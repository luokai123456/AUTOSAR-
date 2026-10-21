/*
 * File: swc_VCOP.c
 *
 * Code generated for Simulink model 'swc_VCOP'.
 *
 * Model version                  : 6.918
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Sep  8 10:53:00 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_VCOP.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include <math.h>
#include "const_ImportFromFile.h"
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef DSP_TASK_INTERVAL_S
#error The value of parameter "DSP_TASK_INTERVAL_S" is not defined
#endif

#ifndef TRQ_ZERO
#error The value of parameter "TRQ_ZERO" is not defined
#endif

#ifndef VOL_TASK_INTERVAL_S
#error The value of parameter "VOL_TASK_INTERVAL_S" is not defined
#endif

#ifndef kXX_2_XX
#error The value of parameter "kXX_2_XX" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S26>/timed_debounce' */
#define swc_VCOP_IN_OFF                ((uint8)1U)
#define swc_VCOP_IN_OFF_WAIT           ((uint8)2U)
#define swc_VCOP_IN_ON                 ((uint8)3U)
#define swc_VCOP_IN_ON_WAIT            ((uint8)4U)

/* Named constants for Chart: '<S79>/timed_delay' */
#define swc_VCOP_IN_OFF_WAIT_k         ((uint8)2U)
#define swc_VCOP_IN_OFF_d              ((uint8)1U)
#define swc_VCOP_IN_ON_a               ((uint8)3U)

/* Named constants for Chart: '<S35>/timed_debounce' */
#define swc_VCOP_IN_OFF_WAIT_c         ((uint8)2U)
#define swc_VCOP_IN_OFF_db             ((uint8)1U)
#define swc_VCOP_IN_ON_WAIT_b          ((uint8)4U)
#define swc_VCOP_IN_ON_i               ((uint8)3U)

/* Named constants for Chart: '<S12>/Chart' */
#define swc_VCOP_IN_INIT               ((uint8)1U)
#define swc_VCOP_IN_VIN_SEND           ((uint8)2U)
#define swc_VCOP_IN_VIN_SEND_1         ((uint8)1U)
#define swc_VCOP_IN_VIN_SEND_2         ((uint8)2U)
#define swc_VCOP_IN_VIN_SEND_3         ((uint8)3U)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported data definition */
#define swc_VCOP_START_SEC_CONST_VOLATILE
#include "swc_VCOP_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile uint8 dccc_e_dcdcReqModeDflt = 0U;/* Referenced by: '<S6>/Constant3' */

/* DC/DC Request Mode default value */
const volatile float32 dspc_t_ipcSgnlTrnOffDly_s = 0.0F;/* Referenced by:
                                                         * '<S23>/Constant1'
                                                         * '<S24>/Constant1'
                                                         */

/* Display Turn Off Delay Time */
const volatile float32 dspc_t_ipcSgnlTrnOnDly_s = 0.0F;/* Referenced by:
                                                        * '<S20>/Constant'
                                                        * '<S23>/Constant'
                                                        * '<S24>/Constant'
                                                        * '<S32>/Constant'
                                                        */

/* Display Turn On Delay Time */
const volatile boolean eadc_b_enbSflEad2TqLmt = false;/* Referenced by: '<S39>/Constant5' */

/* SFL torque Limit Enable */
const volatile boolean eadc_b_newWkModEnb = true;/* Referenced by: '<S41>/Constant34' */

/* New Work Mode Enable */
const volatile uint8 eadc_st_inv2ModeReqDft = 0U;/* Referenced by: '<S8>/Constant5' */

/* Secondary EAD Requested Mode default value */
const volatile uint8 epbc_st_parkStatusDflt = 1U;/* Referenced by: '<S9>/Constant2' */

/* EPB Parking Status default value */
const volatile float32 hvbc_pwr_cntnrDisThld_kW = 15.0F;/* Referenced by: '<S53>/Constant37' */

/* HVB Discharge Power Container Control Disable Lower Threshold */
const volatile float32 hvbc_pwr_cntnrEnaThld_kW = 20.0F;/* Referenced by: '<S53>/Constant36' */

/* HVB Discharge Power Container Control Enable Upper Threshold */
const volatile uint16 swcvcop_vilc_tq_vscESCMotTqRef_Nm = 500U;/* Referenced by: '<S236>/Constant32' */

/* Reference Motor Torque */
const volatile float32 thmc_t_ptcTempSettingPTCDis_C = 25.0F;/* Referenced by: '<S86>/EP3_HiSpd1' */

/* VCU BPTC Temperature Setting when PTC disable */
const volatile float32 thmc_t_ptcTempSettingPTCEna_C = 40.0F;/* Referenced by: '<S86>/EP3_HiSpd3' */

/* VCU BPTC Temperature Setting when PTC enable */
const volatile float32 vild_u_RelayClose_V = 2.0F;/* Referenced by:
                                                   * '<S371>/Constant'
                                                   * '<S372>/Constant'
                                                   * '<S373>/Constant'
                                                   */
const volatile boolean volc_12VbatRlyReq_ovrdval = false;
                         /* Referenced by: '<S181>/volc_WatPmpEP3PWM_ovrdval' */

/* Override value for signal 12VbatRlyReq */
const volatile boolean volc_12vDCDCEn_ovrdval = false;
                            /* Referenced by: '<S182>/volc_12vDCDCEn_ovrdval' */

/* Override value for signal 12vDCDCEn */
const volatile boolean volc_24vDCDCEn_ovrdval = false;
                            /* Referenced by: '<S183>/volc_24vDCDCEn_ovrdval' */

/* Override value for signal 24vDCDCEn */
const volatile uint8 volc_AC_EWP_Heat_ovrdval = 0U;
                /* Referenced by: '<S374>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile float32 volc_AC_EWP_HeatrPwrCnsAllwd_ovrdval = 0.0F;
                /* Referenced by: '<S375>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_AC_EWP_Run_ovrdval = 0U;
                /* Referenced by: '<S376>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_AC_EWP_SpeedReq_ovrdval = 0U;
                /* Referenced by: '<S377>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile float32 volc_AC_EWP_Temp_ovrdval = 0.0F;
                /* Referenced by: '<S378>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile float32 volc_BMSH_ACChgTimeRemain_ovrdval = 0.0F;
                 /* Referenced by: '<S718>/volc_BMSH_ACChgTimeRemain_ovrdval' */
const volatile float32 volc_BMSH_BattCurr_ovrdval = -500.0F;
                        /* Referenced by: '<S719>/volc_BMSH_BattCurr_ovrdval' */
const volatile uint8 volc_BMSH_BattFaultLampState_ovrdval = 0U;
              /* Referenced by: '<S720>/volc_BMSH_BattFaultLampState_ovrdval' */
const volatile uint8 volc_BMSH_CCM_ThermalManageReq_ovrdval = 0U;
            /* Referenced by: '<S721>/volc_BMSH_CCM_ThermalManageReq_ovrdval' */
const volatile uint8 volc_BMSH_Cell_TotalNum_ovrdval = 0U;
                   /* Referenced by: '<S722>/volc_BMSH_Cell_TotalNum_ovrdval' */
const volatile uint8 volc_BMSH_ChargeLEDCtrl_ovrdval = 0U;
                   /* Referenced by: '<S723>/volc_BMSH_ChargeLEDCtrl_ovrdval' */
const volatile uint8 volc_BMSH_Charge_Over_Current_ovrdval = 0U;
             /* Referenced by: '<S724>/volc_BMSH_Charge_Over_Current_ovrdval' */
const volatile uint8 volc_BMSH_ChgTimeRemain_ovrdval = 0U;
                   /* Referenced by: '<S725>/volc_BMSH_ChgTimeRemain_ovrdval' */
const volatile uint8 volc_BMSH_DCChgminusSocketTempSensing_Failure_ovrdval = 0U;
/* Referenced by: '<S726>/volc_BMSH_DCChgminusSocketTempSensing_Failure_ovrdval' */
const volatile uint8 volc_BMSH_DCChgplusSocketTempSensing_Failure_ovrdval = 0U;
/* Referenced by: '<S727>/volc_BMSH_DCChgplusSocketTempSensing_Failure_ovrdval' */
const volatile uint8 volc_BMSH_FastChgCC2ConntState_ovrdval = 0U;
            /* Referenced by: '<S728>/volc_BMSH_FastChgCC2ConntState_ovrdval' */
const volatile uint8 volc_BMSH_HvBattThermMod_ovrdval = 0U;
                       /* Referenced by: '<S407>/volc_PMS_ThermalReq_ovrdval' */
const volatile uint8 volc_BMSH_InsulationRes_Fault_ovrdval = 0U;
             /* Referenced by: '<S729>/volc_BMSH_InsulationRes_Fault_ovrdval' */
const volatile boolean volc_BMSH_ThermalOutofControl_ovrdval = false;
             /* Referenced by: '<S730>/volc_BMSH_ThermalOutofControl_ovrdval' */
const volatile boolean volc_BMSH_Vehicle_HVILSts_PHEV_ovrdval = false;
            /* Referenced by: '<S731>/volc_BMSH_Vehicle_HVILSts_PHEV_ovrdval' */
const volatile uint8 volc_EDCP_Flt_ovrdval = 0U;
                             /* Referenced by: '<S401>/volc_EDCP_Flt_ovrdval' */
const volatile uint8 volc_HBCPFlt_ovrdval = 0U;
                       /* Referenced by: '<S402>/volc_PMS_ThermalReq_ovrdval' */
const volatile uint8 volc_PMS_32960FltNum_ovrdval = 0U;
                      /* Referenced by: '<S732>/volc_PMS_32960FltNum_ovrdval' */
const volatile uint8 volc_PMS_AcceRelayVoltSampSwich_ovrdval = 0U;
           /* Referenced by: '<S855>/volc_PMS_AcceRelayVoltSampSwich_ovrdval' */
const volatile uint8 volc_PMS_AcceSuppressionSts_ovrdval = 0U;
                 /* Referenced by: '<S379>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile float32 volc_PMS_Acceleration_ovrdval = 0.0F;
                     /* Referenced by: '<S162>/volc_PMS_Acceleration_ovrdval' */
const volatile uint8 volc_PMS_AccessoryConnStsFb_ovrdval = 0U;
               /* Referenced by: '<S577>/volc_PMS_AccessoryConnStsFb_ovrdval' */
const volatile boolean volc_PMS_AccessoryCtrlCommand_ovrdval = false;
             /* Referenced by: '<S258>/volc_PMS_AccessoryCtrlCommand_ovrdval' */
const volatile uint8 volc_PMS_AccessoryRelayFlt_ovrdval = 0U;
                /* Referenced by: '<S578>/volc_PMS_AccessoryRelayFlt_ovrdval' */
const volatile float32 volc_PMS_ActualPTTorque_ovrdval = 0.0F;
                   /* Referenced by: '<S733>/volc_PMS_ActualPTTorque_ovrdval' */
const volatile boolean volc_PMS_BBM_FaultStatus_ovrdval = false;
                  /* Referenced by: '<S259>/volc_PMS_BBM_FaultStatus_ovrdval' */
const volatile boolean volc_PMS_BBM_WorkSts_ovrdval = false;
                      /* Referenced by: '<S260>/volc_PMS_BBM_WorkSts_ovrdval' */
const volatile uint8 volc_PMS_BMS_Reignstatus1_ovrdval = 0U;
                         /* Referenced by: '<S734>/volc_PMS_ePTFault_ovrdval' */
const volatile uint8 volc_PMS_BMS_Reignstatus2_ovrdval = 0U;
                         /* Referenced by: '<S735>/volc_PMS_ePTFault_ovrdval' */
const volatile boolean volc_PMS_Brake_LightsRequest_ovrdval = false;
              /* Referenced by: '<S736>/volc_PMS_Brake_LightsRequest_ovrdval' */
const volatile uint8 volc_PMS_CPSRU_ovrdval = 0U;
                 /* Referenced by: '<S380>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile uint8 volc_PMS_CampModeFbFailrReason_ovrdval = 0U;
            /* Referenced by: '<S738>/volc_PMS_CampModeFbFailrReason_ovrdval' */
const volatile boolean volc_PMS_CampModeFb_ovrdval = false;
                       /* Referenced by: '<S737>/volc_PMS_CampModeFb_ovrdval' */
const volatile float32 volc_PMS_ChargPwr_ovrdval = 0.0F;
                /* Referenced by: '<S381>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_PMS_ChargeLimitResponse_ovrdval = 0U;
                   /* Referenced by: '<S739>/volc_PMS_VacuumPressure_ovrdval' */
const volatile boolean volc_PMS_CruisingDstSwtFb_ovrdval = false;
                 /* Referenced by: '<S740>/volc_PMS_CruisingDstSwtFb_ovrdval' */
const volatile boolean volc_PMS_CurrentGearPositionValid_ovrdval = false;
         /* Referenced by: '<S639>/volc_PMS_CurrentGearPositionValid_ovrdval' */
const volatile float32 volc_PMS_DriverDemandTorque_ovrdval = 0.0F;
               /* Referenced by: '<S741>/volc_PMS_DriverDemandTorque_ovrdval' */
const volatile uint8 volc_PMS_DrivingTakeEleSts_ovrdval = 0U;
                /* Referenced by: '<S261>/volc_PMS_DrivingTakeEleSts_ovrdval' */
const volatile uint16 volc_PMS_DrvPfmncRedn_ovrdval = 0U;
                     /* Referenced by: '<S742>/volc_PMS_DrvPfmncRedn_ovrdval' */
const volatile boolean volc_PMS_EPBClosedReq_PMS_ovrdval = false;
                 /* Referenced by: '<S743>/volc_PMS_EPBClosedReq_PMS_ovrdval' */
const volatile boolean volc_PMS_Fn1GearRlyDrvStsFb_ovrdval = false;
                 /* Referenced by: '<S382>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile boolean volc_PMS_Fn2GearRlyDrvStsFb_ovrdval = false;
                 /* Referenced by: '<S383>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile boolean volc_PMS_FrntHeatModEnad_ovrdval = false;
                  /* Referenced by: '<S163>/volc_PMS_FrntHeatModEnad_ovrdval' */
const volatile float32 volc_PMS_FrntHeatPwrAllwd_ovrdval = 0.0F;
                 /* Referenced by: '<S164>/volc_PMS_FrntHeatPwrAllwd_ovrdval' */
const volatile boolean volc_PMS_GearIntervene_ovrdval = false;
                 /* Referenced by: '<S744>/volc_BMSH_ACChgTimeRemain_ovrdval' */
const volatile float32 volc_PMS_GrossComVehWeight_ovrdval = 0.0F;
                /* Referenced by: '<S745>/volc_PMS_GrossComVehWeight_ovrdval' */
const volatile boolean volc_PMS_HVIL1Sts_EV_ovrdval = false;
                      /* Referenced by: '<S165>/volc_PMS_HVIL1Sts_EV_ovrdval' */
const volatile boolean volc_PMS_HVIL1Sts_UB_ovrdval = false;
                      /* Referenced by: '<S166>/volc_PMS_HVIL1Sts_UB_ovrdval' */
const volatile boolean volc_PMS_HVIL2Sts_EV_ovrdval = false;
                      /* Referenced by: '<S167>/volc_PMS_HVIL2Sts_EV_ovrdval' */
const volatile boolean volc_PMS_HVIL2Sts_UB_ovrdval = false;
                      /* Referenced by: '<S168>/volc_PMS_HVIL2Sts_UB_ovrdval' */
const volatile boolean volc_PMS_HVILSts_EV_ovrdval = false;
                       /* Referenced by: '<S169>/volc_PMS_HVILSts_EV_ovrdval' */
const volatile float32 volc_PMS_HvCoolgPwrAllwd_ovrdval = 0.0F;
                  /* Referenced by: '<S403>/volc_PMS_HvCoolgPwrAllwd_ovrdval' */
const volatile float32 volc_PMS_HvHeatgPwrAllwd_ovrdval = 0.0F;
                  /* Referenced by: '<S404>/volc_PMS_HvHeatgPwrAllwd_ovrdval' */
const volatile float32 volc_PMS_IPKTotalOdometer_ovrdval = 0.0F;
                 /* Referenced by: '<S746>/volc_PMS_IPKTotalOdometer_ovrdval' */
const volatile uint8 volc_PMS_InventorySpdLmtRxSts_ovrdval = 0U;
             /* Referenced by: '<S747>/volc_PMS_InventorySpdLmtRxSts_ovrdval' */
const volatile uint8 volc_PMS_InventorySpdLmtSts_ovrdval = 0U;
               /* Referenced by: '<S748>/volc_PMS_InventorySpdLmtSts_ovrdval' */
const volatile uint8 volc_PMS_IsgActvDampgModReq_ovrdval = 3U;
               /* Referenced by: '<S487>/volc_PMS_IsgActvDampgModReq_ovrdval' */
const volatile uint8 volc_PMS_Life_ovrdval = 0U;
                             /* Referenced by: '<S749>/volc_PMS_Life_ovrdval' */
const volatile uint8 volc_PMS_LockVehExecutedSts_ovrdval = 0U;
                /* Referenced by: '<S384>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_PMS_LockVehPerFlag_ovrdval = 0U;
                   /* Referenced by: '<S750>/volc_PMS_LockVehPerFlag_ovrdval' */
const volatile uint8 volc_PMS_LockVehPerRxSts_ovrdval = 0U;
                  /* Referenced by: '<S751>/volc_PMS_LockVehPerRxSts_ovrdval' */
const volatile float32 volc_PMS_MCUFlowFeedback_EV_ovrdval = 0.0F;
               /* Referenced by: '<S405>/volc_PMS_MCUFlowFeedback_EV_ovrdval' */
const volatile float32 volc_PMS_MaxPTTorqueAllowed_ovrdval = 0.0F;
               /* Referenced by: '<S752>/volc_PMS_MaxPTTorqueAllowed_ovrdval' */
const volatile float32 volc_PMS_MinPTTorqueAllowed_ovrdval = 0.0F;
               /* Referenced by: '<S753>/volc_PMS_MinPTTorqueAllowed_ovrdval' */
const volatile uint8 volc_PMS_OTAInstrucStsReminder_ovrdval = 0U;
            /* Referenced by: '<S754>/volc_PMS_OTAInstrucStsReminder_ovrdval' */
const volatile uint8 volc_PMS_OTAInstructRxnSts_ovrdval = 0U;
                /* Referenced by: '<S755>/volc_PMS_OTAInstructRxnSts_ovrdval' */
const volatile boolean volc_PMS_OdometerbackupEnable_ovrdval = false;
             /* Referenced by: '<S757>/volc_PMS_OdometerbackupEnable_ovrdval' */
const volatile float32 volc_PMS_Odometerbackup_ovrdval = 0.0F;
                   /* Referenced by: '<S756>/volc_PMS_Odometerbackup_ovrdval' */

/* Override value  */
const volatile uint8 volc_PMS_PTC1ConnStsFb_ovrdval = 0U;
                    /* Referenced by: '<S579>/volc_PMS_PTC1ConnStsFb_ovrdval' */
const volatile uint8 volc_PMS_PTC1RelayFlt_ovrdval = 0U;
                     /* Referenced by: '<S580>/volc_PMS_PTC1RelayFlt_ovrdval' */
const volatile uint8 volc_PMS_PTC3ConnStsFb_ovrdval = 0U;
                    /* Referenced by: '<S581>/volc_PMS_PTC3ConnStsFb_ovrdval' */
const volatile uint8 volc_PMS_PTC3RelayFlt_ovrdval = 0U;
                     /* Referenced by: '<S582>/volc_PMS_PTC3RelayFlt_ovrdval' */
const volatile uint8 volc_PMS_PTCRelayVoltSampSwich_ovrdval = 0U;
            /* Referenced by: '<S856>/volc_PMS_PTCRelayVoltSampSwich_ovrdval' */
const volatile uint8 volc_PMS_PowerOffCmdRxSts_ovrdval = 0U;
                 /* Referenced by: '<S758>/volc_PMS_PowerOffCmdRxSts_ovrdval' */
const volatile uint8 volc_PMS_PowerOffCmdSts_ovrdval = 0U;
                   /* Referenced by: '<S759>/volc_PMS_PowerOffCmdSts_ovrdval' */
const volatile uint8 volc_PMS_PreAccessoryConnStsFb_ovrdval = 0U;
            /* Referenced by: '<S583>/volc_PMS_PreAccessoryConnStsFb_ovrdval' */
const volatile uint8 volc_PMS_PreAccessoryRelayFlt_ovrdval = 0U;
             /* Referenced by: '<S584>/volc_PMS_PreAccessoryRelayFlt_ovrdval' */
const volatile boolean volc_PMS_Real_PedalPositionInvalid_ovrdval = false;
        /* Referenced by: '<S452>/volc_PMS_Real_PedalPositionInvalid_ovrdval' */
const volatile float32 volc_PMS_Real_PedalPosition_ovrdval = 0.0F;
               /* Referenced by: '<S451>/volc_PMS_Real_PedalPosition_ovrdval' */
const volatile float32 volc_PMS_RegenTarTrqPot_ovrdval = 0.0F;
                   /* Referenced by: '<S760>/volc_PMS_RegenTarTrqPot_ovrdval' */
const volatile float32 volc_PMS_RegenTrqAct_ovrdval = 0.0F;
                      /* Referenced by: '<S761>/volc_PMS_RegenTrqAct_ovrdval' */
const volatile float32 volc_PMS_RegenTrqPot_ovrdval = 0.0F;
                      /* Referenced by: '<S762>/volc_PMS_RegenTrqPot_ovrdval' */
const volatile uint8 volc_PMS_RegulationSpeed_ovrdval = 0U;
                 /* Referenced by: '<S385>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile uint8 volc_PMS_RemChrgCmdFailrPrompt_ovrdval = 0U;
                /* Referenced by: '<S386>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_PMS_SpdLmtLevelRxSts_ovrdval = 0U;
                 /* Referenced by: '<S764>/volc_PMS_SpdLmtLevelRxSts_ovrdval' */
const volatile uint8 volc_PMS_SpdLmtLevel_ovrdval = 0U;
                      /* Referenced by: '<S763>/volc_PMS_SpdLmtLevel_ovrdval' */
const volatile uint8 volc_PMS_StsBatLockSensor_ovrdval = 0U;
                 /* Referenced by: '<S170>/volc_PMS_StsBatLockSensor_ovrdval' */
const volatile boolean volc_PMS_TBOX_HVILState_ovrdval = false;
                   /* Referenced by: '<S765>/volc_PMS_TBOX_HVILState_ovrdval' */
const volatile uint8 volc_PMS_TBOX_LifeSts_ovrdval = 0U;
                     /* Referenced by: '<S766>/volc_PMS_TBOX_LifeSts_ovrdval' */
const volatile boolean volc_PMS_TakeEleSwtIndReq_ovrdval = false;
                 /* Referenced by: '<S387>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile uint8 volc_PMS_ThermalReq_ovrdval = 0U;
                       /* Referenced by: '<S406>/volc_PMS_ThermalReq_ovrdval' */
const volatile uint8 volc_PMS_Torque_Ovrd_Active_ovrdval = 0U;
                 /* Referenced by: '<S388>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile uint8 volc_PMS_Torque_Ovrd_Type_ovrdval = 0U;
                 /* Referenced by: '<S389>/volc_VCU_DriveCircuitTemp_ovrdval' */
const volatile uint8 volc_PMS_V2XDchaSwtFb1_ovrdval = 0U;
                 /* Referenced by: '<S767>/volc_BMSH_ACChgTimeRemain_ovrdval' */
const volatile uint8 volc_PMS_VINCode1_8_15_S_ovrdval = 0U;
                  /* Referenced by: '<S768>/volc_PMS_VINCode1_8_15_S_ovrdval' */
const volatile uint8 volc_PMS_VINCode2_9_16_S_ovrdval = 0U;
                  /* Referenced by: '<S769>/volc_PMS_VINCode2_9_16_S_ovrdval' */
const volatile uint8 volc_PMS_VINCode3_10_17_S_ovrdval = 0U;
                 /* Referenced by: '<S770>/volc_PMS_VINCode3_10_17_S_ovrdval' */
const volatile uint8 volc_PMS_VINCode4_11_S_ovrdval = 0U;
                    /* Referenced by: '<S771>/volc_PMS_VINCode4_11_S_ovrdval' */
const volatile uint8 volc_PMS_VINCode5_12_S_ovrdval = 0U;
                    /* Referenced by: '<S772>/volc_PMS_VINCode5_12_S_ovrdval' */
const volatile uint8 volc_PMS_VINCode6_13_S_ovrdval = 0U;
                    /* Referenced by: '<S773>/volc_PMS_VINCode6_13_S_ovrdval' */
const volatile uint8 volc_PMS_VINCode7_14_S_ovrdval = 0U;
                    /* Referenced by: '<S774>/volc_PMS_VINCode7_14_S_ovrdval' */
const volatile uint8 volc_PMS_VINMessageNum_S_ovrdval = 0U;
                  /* Referenced by: '<S775>/volc_PMS_VINMessageNum_S_ovrdval' */
const volatile float32 volc_PMS_VacuumPressure_ovrdval = 0.0F;
                   /* Referenced by: '<S776>/volc_PMS_VacuumPressure_ovrdval' */
const volatile float32 volc_PMS_VacuumPump_FB_ovrdval = 0.0F;
                    /* Referenced by: '<S777>/volc_PMS_VacuumPump_FB_ovrdval' */
const volatile uint8 volc_PMS_VacuumSystemsta_ovrdval = 0U;
                  /* Referenced by: '<S778>/volc_PMS_VacuumSystemsta_ovrdval' */
const volatile uint8 volc_PMS_VehicleSysErrorLevelG_ovrdval = 0U;
                /* Referenced by: '<S398>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_PMS_VersionConversionFlag_ovrdval = 0U;
            /* Referenced by: '<S779>/volc_PMS_VersionConversionFlag_ovrdval' */
const volatile uint8 volc_PMS_VersionConversionRxSts_ovrdval = 0U;
           /* Referenced by: '<S780>/volc_PMS_VersionConversionRxSts_ovrdval' */
const volatile boolean volc_PMS_ePTFault_ovrdval = false;
                         /* Referenced by: '<S781>/volc_PMS_ePTFault_ovrdval' */
const volatile uint8 volc_TBOX_ChrgSoftSwCtrlst_ovrdval = 0U;
                /* Referenced by: '<S390>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_TBOX_ReservationChrgnSts_ovrdval = 0U;
                /* Referenced by: '<S391>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_VCU_12VATS1Enable_ovrdval = 0U;
                    /* Referenced by: '<S431>/volc_VCU_12VATS1Enable_ovrdval' */

/* Override value for signal VCU_12VATS1Enable */
const volatile float32 volc_VCU_12VATS1_PWMRequest_ovrdval = 0.0F;
               /* Referenced by: '<S432>/volc_VCU_12VATS1_PWMRequest_ovrdval' */

/* Override value for signal VCU_12VATS1_PWMRequest */
const volatile uint8 volc_VCU_12VDCDCCutOffLV_ovrdval = 0U;
                  /* Referenced by: '<S535>/volc_VCU_12VDCDCCutOffLV_ovrdval' */

/* Override value for signal VCU_12VDCDCCutOffLV */
const volatile uint8 volc_VCU_12VDCDCEnableOut_ovrdval = 0U;
                 /* Referenced by: '<S536>/volc_VCU_12VDCDCEnableOut_ovrdval' */

/* Override value for signal VCU_12VDCDCEnableOut */
const volatile uint8 volc_VCU_24V_Switch_ovrdval = 0U;/* Referenced by:
                                                       * '<S249>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                       * '<S679>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                       */

/* Override value for signal VCU_24V_Switch */
const volatile uint8 volc_VCU_ACActiveReq_ovrdval = 0U;
                      /* Referenced by: '<S453>/volc_VCU_ACActiveReq_ovrdval' */

/* Override value for signal VCU_ACActiveReq */
const volatile float32 volc_VCU_ACC1PosVol_ovrdval = 0.0F;
                       /* Referenced by: '<S564>/volc_VCU_ACC1PosVol_ovrdval' */

/* Override value for signal VCU_ACC1PosVol */
const volatile float32 volc_VCU_ACC2PosVol_ovrdval = 0.0F;
                       /* Referenced by: '<S565>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_ACC2PosVol */
const volatile uint8 volc_VCU_ACCMEnable_ovrdval = 0U;
                       /* Referenced by: '<S408>/volc_VCU_ACCMEnable_ovrdval' */

/* Override value for signal ACCMEnable */
const volatile uint8 volc_VCU_ACCY1CtrlCmd_ovrdval = 3U;
                     /* Referenced by: '<S262>/volc_VCU_ACCY1CtrlCmd_ovrdval' */

/* Override value for signal VCU_ACCY1CtrlCmd */
const volatile boolean volc_VCU_ACCYEnableIn_ovrdval = false;
                     /* Referenced by: '<S263>/volc_VCU_ACCYEnableIn_ovrdval' */

/* Override value for signal VCU_ACCYEnableIn */
const volatile boolean volc_VCU_ACUCrashfz_Back_dftval = false;
                   /* Referenced by: '<S224>/volc_VCU_ACUCrashfz_Back_dftval' */
const volatile boolean volc_VCU_ACUCrashfz_Back_ovrdval = false;
                  /* Referenced by: '<S264>/volc_VCU_ACUCrashfz_Back_ovrdval' */

/* Override value for signal VCU_ACUCrashfz_Back */
const volatile float32 volc_VCU_AEC_ovrdval = 0.0F;
                              /* Referenced by: '<S527>/volc_VCU_AEC_ovrdval' */

/* Override value for signal VCU_AEC */
const volatile boolean volc_VCU_APUSWILED_Ctrl_dftval = false;
                    /* Referenced by: '<S224>/volc_VCU_APUSWILED_Ctrl_dftval' */
const volatile boolean volc_VCU_APUSWILED_Ctrl_ovrdval = false;
                   /* Referenced by: '<S265>/volc_VCU_APUSWILED_Ctrl_ovrdval' */

/* Override value for signal VCU_APUSWILED_Ctrl */
const volatile uint8 volc_VCU_ATS1Enable_ovrdval = 0U;
                       /* Referenced by: '<S433>/volc_VCU_ATS1Enable_ovrdval' */

/* Override value for signal VCU_ATS1Enable */
const volatile float32 volc_VCU_ATS1_PWMRequest_ovrdval = 0.0F;
                  /* Referenced by: '<S434>/volc_VCU_ATS1_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS1_PWMRequest */
const volatile uint8 volc_VCU_ATS2Enable_ovrdval = 0U;
                       /* Referenced by: '<S435>/volc_VCU_ATS2Enable_ovrdval' */

/* Override value for signal VCU_ATS2Enable */
const volatile float32 volc_VCU_ATS2_PWMRequest_ovrdval = 0.0F;
                  /* Referenced by: '<S436>/volc_VCU_ATS2_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS2_PWMRequest */
const volatile uint8 volc_VCU_ATS3Enable_ovrdval = 0U;
                       /* Referenced by: '<S437>/volc_VCU_ATS3Enable_ovrdval' */

/* Override value for signal VCU_ATS3Enable */
const volatile float32 volc_VCU_ATS3_PWMRequest_ovrdval = 0.0F;
                  /* Referenced by: '<S438>/volc_VCU_ATS3_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS3_PWMRequest */
const volatile uint8 volc_VCU_ATS4Enable_ovrdval = 0U;
                       /* Referenced by: '<S439>/volc_VCU_ATS4Enable_ovrdval' */

/* Override value for signal VCU_ATS4Enable */
const volatile float32 volc_VCU_ATS4_PWMRequest_ovrdval = 0.0F;
                  /* Referenced by: '<S440>/volc_VCU_ATS4_PWMRequest_ovrdval' */

/* Override value for signal VCU_ATS4_PWMRequest */
const volatile boolean volc_VCU_AWB_ovrdval = false;
                    /* Referenced by: '<S614>/volc_VCU_AccePedalPosE_ovrdval' */

/* Override value for signal VCU_AWB */
const volatile float32 volc_VCU_AccePedalPosD_ovrdval = 0.0F;
                    /* Referenced by: '<S626>/volc_VCU_AccePedalPosD_ovrdval' */

/* Override value for signal VCU_AccePedalPosD */
const volatile float32 volc_VCU_AccePedalPosE_ovrdval = 0.0F;
                    /* Referenced by: '<S627>/volc_VCU_AccePedalPosE_ovrdval' */

/* Override value for signal VCU_AccePedalPosE */
const volatile float32 volc_VCU_AcceleratorPedalPosition_ovrdval = 0.0F;
         /* Referenced by: '<S454>/volc_VCU_AcceleratorPedalPosition_ovrdval' */

/* Override value for signal VCU_AcceleratorPedalPosition */
const volatile boolean volc_VCU_AcceleratorPedal_flag_ovrdval = false;
            /* Referenced by: '<S455>/volc_VCU_AcceleratorPedal_flag_ovrdval' */

/* Override value for signal VCU_AcceleratorPedal_flag */
const volatile boolean volc_VCU_AccyAllowEnable_Ctrl_ovrdval = false;
             /* Referenced by: '<S266>/volc_VCU_AccyAllowEnable_Ctrl_ovrdval' */

/* Override value for signal VCU_AccyAllowEnable_Ctrl */
const volatile boolean volc_VCU_AccyPower_back_ovrdval = false;
                   /* Referenced by: '<S267>/volc_VCU_AccyPower_back_ovrdval' */

/* Override value for signal VCU_AccyPower_back */
const volatile uint8 volc_VCU_ActualGear_ovrdval = 0U;
                       /* Referenced by: '<S868>/volc_VCU_ActualGear_ovrdval' */

/* Override value for signal VCU_ActualGear */
const volatile uint8 volc_VCU_Address_ovrdval = 0U;
                    /* Referenced by: '<S615>/volc_VCU_AccePedalPosD_ovrdval' */

/* Override value for signal VCU_Address */
const volatile uint8 volc_VCU_AllowChg_ovrdval = 0U;
                         /* Referenced by: '<S537>/volc_VCU_AllowChg_ovrdval' */

/* Override value for signal VCU_AllowChg */
const volatile uint16 volc_VCU_AppSts_ovrdval = 0U;
                       /* Referenced by: '<S566>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_AppSts */
const volatile float32 volc_VCU_AvgEVConsume_ovrdval = 0.0F;
                     /* Referenced by: '<S268>/volc_VCU_AvgEVConsume_ovrdval' */

/* Override value for signal VCU_AvgEVConsume */
const volatile float32 volc_VCU_AvgFuelVF_dftval = 0.0F;
                         /* Referenced by: '<S224>/volc_VCU_AvgFuelVF_dftval' */
const volatile float32 volc_VCU_AvgFuelVF_ovrdval = 0.0F;
                        /* Referenced by: '<S269>/volc_VCU_AvgFuelVF_ovrdval' */

/* Override value for signal VCU_AvgFuelVF */
const volatile uint8 volc_VCU_BMSHVOnOffReq_ovrdval = 0U;
                    /* Referenced by: '<S538>/volc_VCU_BMSHVOnOffReq_ovrdval' */

/* Override value for signal VCU_BMSHVOnOffReq */
const volatile float32 volc_VCU_BMSH_DCChgRelayVolt_ovrdval = 0.0F;
              /* Referenced by: '<S539>/volc_VCU_BMSH_DCChgRelayVolt_ovrdval' */
const volatile float32 volc_VCU_BMS_SOC_ovrdval = 0.0F;
                          /* Referenced by: '<S335>/volc_VCU_BMS_SOC_ovrdval' */

/* Override value for signal VCU_BMS_SOC */
const volatile float32 volc_VCU_BMS_voltage_ovrdval = 0.0F;
                      /* Referenced by: '<S336>/volc_VCU_BMS_voltage_ovrdval' */

/* Override value for signal VCU_BMS_voltage */
const volatile uint8 volc_VCU_BPTCCtrlCmd_ovrdval = 0U;
                      /* Referenced by: '<S561>/volc_VCU_BPTCCtrlCmd_ovrdval' */

/* Override value for signal VCU_BPTCCtrlCmd */
const volatile boolean volc_VCU_BPTCEnable_ovrdval = false;
                      /* Referenced by: '<S859>/volc_VCU_HVBC_Enable_ovrdval' */

/* Override value for signal VCU_BPTCEnable */
const volatile uint8 volc_VCU_BPTCPowerRatio_dftval = 0U;
                    /* Referenced by: '<S849>/volc_VCU_BPTCPowerRatio_dftval' */

/* Default value for signal VCU_BPTCPowerRatio */
const volatile uint8 volc_VCU_BPTCPowerRatio_ovrdval = 0U;
                  /* Referenced by: '<S860>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_BPTCPowerRatio */
const volatile uint8 volc_VCU_BPTCTempSetting_ovrdval = 0U;
                  /* Referenced by: '<S861>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_BPTCTempSetting */
const volatile uint16 volc_VCU_BattCoolVal3_FBV5_ovrdval = 0U;/* Referenced by:
                                                               * '<S243>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                               * '<S597>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                               */

/* Override value for signal VCU_BattCoolVal3_FBV5 */
const volatile uint16 volc_VCU_BattCoolVal3_FBV6_ovrdval = 0U;/* Referenced by:
                                                               * '<S243>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                               * '<S598>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                               */

/* Override value for signal VCU_BattCoolVal3_FBV6 */
const volatile uint16 volc_VCU_BattHeatVal2_FBV5_ovrdval = 0U;/* Referenced by:
                                                               * '<S243>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                               * '<S599>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                               */

/* Override value for signal VCU_BattHeatVal2_FBV5 */
const volatile uint16 volc_VCU_BattHeatVal2_FBV6_ovrdval = 0U;/* Referenced by:
                                                               * '<S243>/volc_VCU_BattHeatVal2_FBV6_ovrdval'
                                                               * '<S600>/volc_VCU_BattHeatVal2_FBV6_ovrdval'
                                                               */

/* Override value for signal VCU_BattHeatVal2_FBV6 */
const volatile float32 volc_VCU_BattMaxTemp_ovrdval = 0.0F;
                      /* Referenced by: '<S337>/volc_VCU_BattMaxTemp_ovrdval' */

/* Override value for signal VCU_BattMaxTemp */
const volatile float32 volc_VCU_BattMinTemp_ovrdval = 0.0F;
                      /* Referenced by: '<S338>/volc_VCU_BattMinTemp_ovrdval' */

/* Override value for signal VCU_BattMinTemp */
const volatile float32 volc_VCU_BattPackInCoolTemp_ovrdval = 0.0F;
               /* Referenced by: '<S409>/volc_VCU_BattPackInCoolTemp_ovrdval' */

/* Override value for signal VCU_BattPackInCoolTemp */
const volatile float32 volc_VCU_BattPackInCoolTempback_ovrdval = 0.0F;
           /* Referenced by: '<S270>/volc_VCU_BattPackInCoolTempback_ovrdval' */

/* Override value for signal VCU_BattPackInCoolTempback */
const volatile float32 volc_VCU_BattPackOutCoolTemp_ovrdval = 0.0F;
              /* Referenced by: '<S410>/volc_VCU_BattPackoutCoolTemp_ovrdval' */

/* Override value for signal VCU_BattPackOutCoolTemp */
const volatile float32 volc_VCU_BattPackoutCoolTempback_ovrdval = 0.0F;
          /* Referenced by: '<S271>/volc_VCU_BattPackoutCoolTempback_ovrdval' */

/* Override value for signal VCU_BattPackoutCoolTempback */
const volatile float32 volc_VCU_BattVol_ovrdval = 0.0F;
                          /* Referenced by: '<S339>/volc_VCU_BattVol_ovrdval' */

/* Override value for signal VCU_BattVol */
const volatile float32 volc_VCU_BatteryCoolentTemp_ovrdval = 0.0F;
               /* Referenced by: '<S411>/volc_VCU_BatteryCoolentTemp_ovrdval' */

/* Override value for signal VCU_BatteryCoolentTemp */
const volatile float32 volc_VCU_BatteryVol_ovrdval = 0.0F;
                       /* Referenced by: '<S567>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_BatteryVol */
const volatile boolean volc_VCU_Batty_Charge_DisChargeState_ovrdval = false;
      /* Referenced by: '<S340>/volc_VCU_Batty_Charge_DisChargeState_ovrdval' */

/* Override value for signal VCU_Batty_Charge_DisChargeState */
const volatile boolean volc_VCU_Batty_ThermalMangeActive_dftval = false;
          /* Referenced by: '<S226>/volc_VCU_Batty_ThermalMangeActive_dftval' */

/* Default value for signal VCU_Batty_ThermalMangeActive */
const volatile boolean volc_VCU_Batty_ThermalMangeActive_ovrdval = false;
         /* Referenced by: '<S341>/volc_VCU_Batty_ThermalMangeActive_ovrdval' */

/* Override value for signal VCU_Batty_ThermalMangeActive */
const volatile uint8 volc_VCU_Batty_ThermalMangeReq_ovrdval = 0U;
            /* Referenced by: '<S412>/volc_VCU_Batty_ThermalMangeReq_ovrdval' */

/* Override value for signal VCU_Batty_ThermalMangeReq */
const volatile uint8 volc_VCU_Batty_ThermalMangeWorkMode_ovrdval = 0U;
       /* Referenced by: '<S342>/volc_VCU_Batty_ThermalMangeWorkMode_ovrdval' */

/* Override value for signal VCU_Batty_ThermalMangeWorkMode */
const volatile uint8 volc_VCU_BrakSwitchSts_ovrdval = 0U;
                    /* Referenced by: '<S456>/volc_VCU_BrakSwitchSts_ovrdval' */

/* Override value for signal VCU_BrakSwitchSts */
const volatile float32 volc_VCU_Brake1PosVol_ovrdval = 0.0F;
                     /* Referenced by: '<S592>/volc_VCU_Brake1PosVol_ovrdval' */

/* Override value for signal VCU_Brake1PosVol */
const volatile boolean volc_VCU_Brake1Sts_ovrdval = false;
                        /* Referenced by: '<S568>/volc_VCU_Brake1Sts_ovrdval' */

/* Override value for signal VCU_Brake1Sts */
const volatile float32 volc_VCU_Brake2PosVol_ovrdval = 0.0F;
                     /* Referenced by: '<S593>/volc_VCU_Brake2PosVol_ovrdval' */

/* Override value for signal VCU_Brake2PosVol */
const volatile boolean volc_VCU_Brake2Sts_ovrdval = false;
                        /* Referenced by: '<S569>/volc_VCU_Brake2Sts_ovrdval' */

/* Override value for signal VCU_Brake2Sts */
const volatile float32 volc_VCU_BrakePedalPosition_ovrdval = 0.0F;
               /* Referenced by: '<S457>/volc_VCU_BrakePedalPosition_ovrdval' */

/* Override value for signal VCU_BrakePedalPosition */
const volatile uint8 volc_VCU_BrkSysErr_ovrdval = 0U;
                        /* Referenced by: '<S640>/volc_VCU_BrkSysErr_ovrdval' */

/* Override value for signal VCU_BrkSysErr */
const volatile uint8 volc_VCU_CCFb_ovrdval = 0U;
                             /* Referenced by: '<S585>/volc_VCU_CCFb_ovrdval' */

/* Override value for signal VCU_CCFb */
const volatile float32 volc_VCU_CC_Acceleration_ovrdval = 0.0F;
                  /* Referenced by: '<S314>/volc_VCU_CC_Acceleration_ovrdval' */

/* Override value for signal VCU_CC_Acceleration */
const volatile boolean volc_VCU_Cab_ThermalMangeReq_ovrdval = false;/* Referenced by:
                                                                     * '<S226>/volc_VCU_Cab_ThermalMangeReq_ovrdval'
                                                                     * '<S343>/volc_VCU_Cab_ThermalMangeReq_ovrdval'
                                                                     */

/* Override value for signal VCU_Cab_ThermalMangeReq */
const volatile uint16 volc_VCU_CabinLoopVal1_FBV6_ovrdval = 0U;/* Referenced by:
                                                                * '<S243>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                                * '<S601>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
                                                                */

/* Override value for signal VCU_CabinLoopVal1_FBV6 */
const volatile uint16 volc_VCU_CabinLoopVal2_FBV5_ovrdval = 0U;/* Referenced by:
                                                                * '<S243>/volc_VCU_CabinLoopVal2_FBV5_ovrdval'
                                                                * '<S602>/volc_VCU_CabinLoopVal2_FBV5_ovrdval'
                                                                */

/* Override value for signal VCU_CabinLoopVal2_FBV5 */
const volatile uint8 volc_VCU_Cabin_PumpFb_ovrdval = 0U;
                     /* Referenced by: '<S586>/volc_VCU_Cabin_PumpFb_ovrdval' */

/* Override value for signal VCU_Cabin_PumpFb */
const volatile uint8 volc_VCU_CalibrationMajorVer1 = 48U;/* Referenced by: '<S159>/Constant5' */
const volatile uint8 volc_VCU_CalibrationMajorVer1_ovrdval = 0U;
                     /* Referenced by: '<S691>/volc_VCU_SWCompileDay_ovrdval' */
const volatile uint8 volc_VCU_CalibrationMajorVer2 = 48U;/* Referenced by: '<S159>/Constant1' */
const volatile uint8 volc_VCU_CalibrationMajorVer2_ovrdval = 0U;
                     /* Referenced by: '<S692>/volc_VCU_SWCompileDay_ovrdval' */
const volatile uint8 volc_VCU_CalibrationMajorVer3 = 48U;/* Referenced by: '<S159>/Constant2' */
const volatile uint8 volc_VCU_CalibrationMajorVer3_ovrdval = 0U;
                     /* Referenced by: '<S693>/volc_VCU_SWCompileDay_ovrdval' */
const volatile uint8 volc_VCU_CalibrationMinorVer1 = 48U;/* Referenced by: '<S159>/Constant8' */
const volatile uint8 volc_VCU_CalibrationMinorVer1_ovrdval = 0U;
                     /* Referenced by: '<S694>/volc_VCU_SWCompileDay_ovrdval' */
const volatile uint8 volc_VCU_CalibrationMinorVer2 = 48U;/* Referenced by: '<S159>/Constant3' */
const volatile uint8 volc_VCU_CalibrationMinorVer2_ovrdval = 0U;
                     /* Referenced by: '<S695>/volc_VCU_SWCompileDay_ovrdval' */
const volatile uint8 volc_VCU_CalibrationMinorVer3 = 48U;/* Referenced by: '<S159>/Constant7' */
const volatile uint8 volc_VCU_CalibrationMinorVer3_ovrdval = 0U;
                     /* Referenced by: '<S696>/volc_VCU_SWCompileDay_ovrdval' */
const volatile float32 volc_VCU_Cell_Avg_Temp_ovrdval = 0.0F;
                    /* Referenced by: '<S344>/volc_VCU_Cell_Avg_Temp_ovrdval' */

/* Override value for signal VCU_Cell_Avg_Temp */
const volatile uint8 volc_VCU_ChargWakeupSts_ovrdval = 0U;
                   /* Referenced by: '<S587>/volc_VCU_ChargWakeupSts_ovrdval' */

/* Override value for signal VCU_ChargWakeupSts */
const volatile uint8 volc_VCU_ChargeDepthReq_ovrdval = 0U;
                /* Referenced by: '<S400>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_VCU_Charger_Connected_ovrdval = 0U;
                /* Referenced by: '<S345>/volc_VCU_Charger_Connected_ovrdval' */

/* Override value for signal VCU_Charger_Connected */
const volatile uint8 volc_VCU_ControlSetSpeed_Mode_ovrdval = 0U;
             /* Referenced by: '<S476>/volc_VCU_ControlSetSpeed_Mode_ovrdval' */

/* Override value for signal VCU_ControlSetSpeed_Mode */
const volatile float32 volc_VCU_ControlSetSpeed_ovrdval = 0.0F;
                  /* Referenced by: '<S475>/volc_VCU_ControlSetSpeed_ovrdval' */

/* Override value for signal VCU_ControlSetSpeed */
const volatile uint8 volc_VCU_Cooling_Control_Request_dftval = 0U;
           /* Referenced by: '<S226>/volc_VCU_Cooling_Control_Request_dftval' */

/* Default value for signal VCU_Cooling_Control_Request */
const volatile uint8 volc_VCU_Cooling_Control_Request_ovrdval = 0U;
          /* Referenced by: '<S346>/volc_VCU_Cooling_Control_Request_ovrdval' */

/* Override value for signal VCU_Cooling_Control_Request */
const volatile uint8 volc_VCU_CrashOutputSts_ovrdval = 0U;
                   /* Referenced by: '<S782>/volc_VCU_CrashOutputSts_ovrdval' */
const volatile uint8 volc_VCU_CruiseControlSts_ovrdval = 0U;
                 /* Referenced by: '<S477>/volc_VCU_CruiseControlSts_ovrdval' */

/* Override value for signal VCU_CruiseControlSts */
const volatile uint8 volc_VCU_CruiseSwSts_ovrdval = 0U;
                      /* Referenced by: '<S478>/volc_VCU_CruiseSwSts_ovrdval' */

/* Override value for signal VCU_CruiseSwSts */
const volatile uint8 volc_VCU_CruiseSwerrorSts_ovrdval = 0U;
                 /* Referenced by: '<S479>/volc_VCU_CruiseSwerrorSts_ovrdval' */

/* Override value for signal VCU_CruiseSwerrorSts */
const volatile float32 volc_VCU_DCDCPwrLmt_ovrdval = 0.0F;
                       /* Referenced by: '<S540>/volc_VCU_DCDCPwrLmt_ovrdval' */

/* Override value for signal VCU_DCDCPwrLmt */
const volatile uint8 volc_VCU_DCDC_WorkSts_ovrdval = 0U;
                     /* Referenced by: '<S641>/volc_VCU_DCDC_WorkSts_ovrdval' */

/* Override value for signal VCU_DCDC_WorkSts */
const volatile float32 volc_VCU_DTE_ovrdval = 0.0F;
                              /* Referenced by: '<S528>/volc_VCU_DTE_ovrdval' */

/* Override value for signal VCU_DTE */
const volatile uint8 volc_VCU_DischargeEnable_ovrdval = 0U;
                /* Referenced by: '<S397>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile sint16 volc_VCU_DriveCircuitTemp_ovrdval = 0;
                 /* Referenced by: '<S392>/volc_VCU_DriveCircuitTemp_ovrdval' */

/* Override value for signal VCU_DriveCircuitTemp */
const volatile uint16 volc_VCU_DriveCircuitVol_ovrdval = 0U;
                  /* Referenced by: '<S603>/volc_VCU_DriveCircuitVol_ovrdval' */

/* Override value for signal VCU_DriveCircuitVol */
const volatile uint8 volc_VCU_DriveModeInd_ovrdval = 0U;
                     /* Referenced by: '<S642>/volc_VCU_DriveModeInd_ovrdval' */

/* Override value for signal VCU_DriveModeInd */
const volatile uint8 volc_VCU_DrivePwrCircuitInd_ovrdval = 0U;
               /* Referenced by: '<S643>/volc_VCU_DrivePwrCircuitInd_ovrdval' */

/* Override value for signal VCU_DrivePwrCircuitInd */
const volatile float32 volc_VCU_DriveReqTrqPercent_ovrdval = 0.0F;
               /* Referenced by: '<S488>/volc_VCU_DriveReqTrqPercent_ovrdval' */

/* Override value for signal VCU_DriveReqTrqPercent */
const volatile uint8 volc_VCU_DriverOperationReminder_ovrdval = 0U;
          /* Referenced by: '<S458>/volc_VCU_DriverOperationReminder_ovrdval' */

/* Override value for signal VCU_DriverOperationReminder */
const volatile uint8 volc_VCU_DrivingTakeForceSts_dftval = 0U;
               /* Referenced by: '<S853>/volc_VCU_DrivingTakeForceSts_dftval' */

/* Default value for signal VCU_DrivingTakeForceSts */
const volatile uint8 volc_VCU_DrivingTakeForceSts_ovrdval = 0U;
              /* Referenced by: '<S871>/volc_VCU_DrivingTakeForceSts_ovrdval' */

/* Override value for signal VCU_DrivingTakeForceSts */
const volatile boolean volc_VCU_ECOMode_ovrdval = false;
                          /* Referenced by: '<S570>/volc_VCU_ECOMode_ovrdval' */

/* Override value for signal VCU_ECOMode */
const volatile boolean volc_VCU_ECOmodeSWILED_Ctrl_dftval = false;
                /* Referenced by: '<S224>/volc_VCU_ECOmodeSWILED_Ctrl_dftval' */
const volatile boolean volc_VCU_ECOmodeSWILED_Ctrl_ovrdval = false;
               /* Referenced by: '<S272>/volc_VCU_ECOmodeSWILED_Ctrl_ovrdval' */

/* Override value for signal VCU_ECOmodeSWILED_Ctrl */
const volatile float32 volc_VCU_ECPM_FaultFB_ovrdval = 10.0F;
                     /* Referenced by: '<S273>/volc_VCU_ECPM_FaultFB_ovrdval' */

/* Override value for signal VCU_ECPM_FaultFB */
const volatile boolean volc_VCU_EDCP_Enable_ovrdval = false;
                      /* Referenced by: '<S875>/volc_VCU_HVBC_Enable_ovrdval' */

/* Override value for signal VCU_EDCP_Enable */
const volatile float32 volc_VCU_EDCP_FaultFB_ovrdval = 10.0F;
                     /* Referenced by: '<S274>/volc_VCU_EDCP_FaultFB_ovrdval' */

/* Override value for signal VCU_EDCP_FaultFB */
const volatile float32 volc_VCU_EDCP_PWMCtrl_ovrdval = 0.0F;
                  /* Referenced by: '<S876>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_EDCP_PWMCtrl */
const volatile uint8 volc_VCU_EM1CtrlMode_ovrdval = 0U;
                      /* Referenced by: '<S489>/volc_VCU_EM1CtrlMode_ovrdval' */
const volatile uint8 volc_VCU_EM1WorkMode_ovrdval = 0U;
                      /* Referenced by: '<S490>/volc_VCU_EM1WorkMode_ovrdval' */
const volatile uint8 volc_VCU_EMCtrlMode_ovrdval = 0U;
                       /* Referenced by: '<S491>/volc_VCU_EMCtrlMode_ovrdval' */

/* Override value for signal VCU_EMCtrlMode */
const volatile uint8 volc_VCU_EMWorkMode_ovrdval = 0U;
                       /* Referenced by: '<S492>/volc_VCU_EMWorkMode_ovrdval' */

/* Override value for signal VCU_EMWorkMode */
const volatile uint8 volc_VCU_EManualStartSwi_ovrdval = 0U;/* Referenced by:
                                                            * '<S241>/volc_VCU_EManualStartSwi_ovrdval'
                                                            * '<S588>/volc_VCU_EManualStartSwi_ovrdval'
                                                            */

/* Override value for signal VCU_EManualStartSwi */
const volatile float32 volc_VCU_EVDTEodometer_ovrdval = 0.0F;
                    /* Referenced by: '<S275>/volc_VCU_EVDTEodometer_ovrdval' */

/* Override value for signal VCU_EVDTEodometer */
const volatile uint8 volc_VCU_EV_Switch_ovrdval = 0U;
                /* Referenced by: '<S680>/volc_VCU_BattHeatVal2_FBV6_ovrdval' */

/* Override value for signal VCU_EV_Switch */
const volatile uint8 volc_VCU_EVanualStartSwi_dftval = 0U;
                   /* Referenced by: '<S248>/volc_VCU_EVanualStartSwi_dftval' */

/* Default value for signal VCU_EVanualStartSwi */
const volatile uint8 volc_VCU_EVanualStartSwi_ovrdval = 0U;
                  /* Referenced by: '<S644>/volc_VCU_EVanualStartSwi_ovrdval' */

/* Override value for signal VCU_EVanualStartSwi */
const volatile uint8 volc_VCU_EmergencyStop_ovrdval = 0U;
                    /* Referenced by: '<S594>/volc_VCU_EmergencyStop_ovrdval' */

/* Override value for signal VCU_EmergencyStop */
const volatile float32 volc_VCU_EngFuelInstCons_ovrdval = 0.0F;
                  /* Referenced by: '<S347>/volc_VCU_EngFuelInstCons_ovrdval' */

/* Override value for signal VCU_EngFuelInstCons */
const volatile float32 volc_VCU_ErrCode_ovrdval = 0.0F;
                          /* Referenced by: '<S529>/volc_VCU_ErrCode_ovrdval' */

/* Override value for signal VCU_ErrCode */
const volatile float32 volc_VCU_ExternalAccDemand_ovrdval = 0.0F;
                /* Referenced by: '<S315>/volc_VCU_ExternalAccDemand_ovrdval' */

/* Override value for signal VCU_ExternalAccDemand */
const volatile float32 volc_VCU_FanPWM_Ctrl_ovrdval = 0.0F;
                 /* Referenced by: '<S681>/volc_VCU_HTCoolingFanCtrl_ovrdval' */

/* Override value for signal VCU_FanPWM_Ctrl */
const volatile float32 volc_VCU_FuleDTEodometer_dftval = 0.0F;
                   /* Referenced by: '<S224>/volc_VCU_FuleDTEodometer_dftval' */
const volatile float32 volc_VCU_FuleDTEodometer_ovrdval = 0.0F;
                  /* Referenced by: '<S276>/volc_VCU_FuleDTEodometer_ovrdval' */

/* Override value for signal VCU_FuleDTEodometer */
const volatile uint8 volc_VCU_FunAnti_DismantleActive_ovrdval = 0U;
          /* Referenced by: '<S604>/volc_VCU_FunAnti_DismantleActive_ovrdval' */

/* Override value for signal VCU_FunAnti_DismantleActive */
const volatile uint8 volc_VCU_FunLockVehActive_ovrdval = 0U;
                 /* Referenced by: '<S605>/volc_VCU_FunLockVehActive_ovrdval' */

/* Override value for signal VCU_FunLockVehActive */
const volatile boolean volc_VCU_GP_Override_ovrdval = false;
                      /* Referenced by: '<S316>/volc_VCU_GP_Override_ovrdval' */

/* Override value for signal VCU_GP_Override */
const volatile uint8 volc_VCU_GearOperateErr_ovrdval = 0U;
                   /* Referenced by: '<S645>/volc_VCU_GearOperateErr_ovrdval' */

/* Override value for signal VCU_GearOperateErr */
const volatile uint8 volc_VCU_GearPositionInd_ovrdval = 0U;
                  /* Referenced by: '<S646>/volc_VCU_GearPositionInd_ovrdval' */

/* Override value for signal VCU_GearPositionInd */
const volatile float32 volc_VCU_GearPositionInput_ovrdval = 0.0F;
                /* Referenced by: '<S595>/volc_VCU_GearPositionInput_ovrdval' */

/* Override value for signal VCU_GearPositionInput */
const volatile uint8 volc_VCU_Gearshift_Resp_ovrdval = 0U;/* Referenced by:
                                                           * '<S853>/volc_VCU_Gearshift_Resp_ovrdval'
                                                           * '<S872>/volc_VCU_Gearshift_Resp_ovrdval'
                                                           */

/* Override value for signal VCU_Gearshift_Resp */
const volatile boolean volc_VCU_HBCP_Enable_ovrdval = false;
                       /* Referenced by: '<S877>/volc_VCU_ICE_Enable_ovrdval' */

/* Override value for signal VCU_HBCP_Enable */
const volatile float32 volc_VCU_HBCP_FaultFB_ovrdval = 10.0F;
                     /* Referenced by: '<S277>/volc_VCU_HBCP_FaultFB_ovrdval' */

/* Override value for signal VCU_HBCP_FaultFB */
const volatile float32 volc_VCU_HBCP_PWMCtrl_ovrdval = 0.0F;
                  /* Referenced by: '<S878>/volc_VCU_HVBC_BOpenValue_ovrdval' */

/* Override value for signal VCU_HBCP_PWMCtrl */
const volatile float32 volc_VCU_HTCoolingFan1FB_ovrdval = 0.0F;
                  /* Referenced by: '<S278>/volc_VCU_HTCoolingFan1FB_ovrdval' */

/* Override value for signal VCU_HTCoolingFan1FB */
const volatile uint8 volc_VCU_HVB_PumpFb_ovrdval = 0U;
                       /* Referenced by: '<S589>/volc_VCU_HVB_PumpFb_ovrdval' */

/* Override value for signal VCU_HVB_PumpFb */
const volatile float32 volc_VCU_HVILReturn_ovrdval = 0.0F;
                       /* Referenced by: '<S596>/volc_VCU_HVILReturn_ovrdval' */

/* Override value for signal VCU_HVILReturn */
const volatile boolean volc_VCU_HVOnOffReq_ovrdval = false;
                       /* Referenced by: '<S348>/volc_VCU_HVOnOffReq_ovrdval' */

/* Override value for signal VCU_HVOnOffReq */
const volatile uint16 volc_VCU_HVPRASts_ovrdval = 0U;
                       /* Referenced by: '<S571>/volc_VCU_ACC2PosVol_ovrdval' */

/* Override value for signal VCU_HVBVarCtrl */
const volatile uint8 volc_VCU_HV_Status_ovrdval = 3U;
                        /* Referenced by: '<S279>/volc_VCU_HV_Status_ovrdval' */

/* Override value for signal VCU_HV_Status */
const volatile uint8 volc_VCU_HandbrakeSts2_ovrdval = 0U;
                    /* Referenced by: '<S459>/volc_VCU_HandbrakeSts2_ovrdval' */

/* Override value for signal VCU_HandbrakeSts2 */
const volatile uint8 volc_VCU_HandbrakeSts_ovrdval = 0U;
                     /* Referenced by: '<S647>/volc_VCU_HandbrakeSts_ovrdval' */

/* Override value for signal VCU_HandbrakeSts */
const volatile uint8 volc_VCU_HardwareMajorVer_ovrdval = 0U;
                 /* Referenced by: '<S697>/volc_VCU_HardwareMajorVer_ovrdval' */

/* Override value for signal VCU_HardwareMajorVer */
const volatile uint8 volc_VCU_HardwareMinorVer_ovrdval = 0U;
                 /* Referenced by: '<S698>/volc_VCU_HardwareMinorVer_ovrdval' */

/* Override value for signal VCU_HardwareMinorVer */
const volatile uint8 volc_VCU_HybridReady_ovrdval = 0U;
                      /* Referenced by: '<S349>/volc_VCU_HybridReady_ovrdval' */

/* Override value for signal VCU_HybridReady */
const volatile uint8 volc_VCU_Idle_Switch_ovrdval = 0U;/* Referenced by:
                                                        * '<S249>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                        * '<S682>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
                                                        */

/* Override value for signal VCU_Idle_Switch */
const volatile boolean volc_VCU_IgnONSts_ovrdval = false;
                         /* Referenced by: '<S572>/volc_VCU_IgnONSts_ovrdval' */

/* Override value for signal VCU_IgnONSts */
const volatile uint8 volc_VCU_IgniteSts_ovrdval = 0U;
                        /* Referenced by: '<S648>/volc_VCU_IgniteSts_ovrdval' */

/* Override value for signal VCU_IgniteSts */
const volatile uint8 volc_VCU_InhibitHybrid_Switch_ovrdval = 0U;/* Referenced by:
                                                                 * '<S249>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                                 * '<S683>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
                                                                 */

/* Override value for signal VCU_InhibitHybrid_Switch */
const volatile uint8 volc_VCU_IntelLockLoopSts_dftval = 0U;
                  /* Referenced by: '<S238>/volc_VCU_IntelLockLoopSts_dftval' */

/* Default value for signal VCU_IntelLockLoopSts */
const volatile uint8 volc_VCU_IntelLockLoopSts_ovrdval = 0U;
                 /* Referenced by: '<S542>/volc_VCU_IntelLockLoopSts_ovrdval' */

/* Override value for signal VCU_IntelLockLoopSts */
const volatile uint8 volc_VCU_IntelligentChargeExitReq_ovrdval = 3U;
         /* Referenced by: '<S280>/volc_VCU_IntelligentChargeExitReq_ovrdval' */

/* Override value for signal VCU_IntelligentChargeExitReq */
const volatile uint8 volc_VCU_IntelligentChargeQuit_ovrdval = 0U;
            /* Referenced by: '<S281>/volc_VCU_IntelligentChargeQuit_ovrdval' */

/* Override value for signal VCU_IntelligentChargeQuit */
const volatile uint8 volc_VCU_IntelligentChargeState_ovrdval = 0U;
           /* Referenced by: '<S282>/volc_VCU_IntelligentChargeState_ovrdval' */

/* Override value for signal VCU_IntelligentChargeState */
const volatile uint8 volc_VCU_LTCoolingFan2FB_ovrdval = 0U;
                  /* Referenced by: '<S283>/volc_VCU_LTCoolingFan2FB_ovrdval' */

/* Override value for signal VCU_LTCoolingFan2FB */
const volatile uint8 volc_VCU_LockLimResult_ovrdval = 0U;
                    /* Referenced by: '<S606>/volc_VCU_LockLimResult_ovrdval' */

/* Override value for signal VCU_LockLimResult */
const volatile uint8 volc_VCU_LockVehSts_ovrdval = 0U;
                       /* Referenced by: '<S607>/volc_VCU_LockVehSts_ovrdval' */

/* Override value for signal VCU_LockVehSts */
const volatile uint8 volc_VCU_LockVehType_ovrdval = 0U;
                      /* Referenced by: '<S608>/volc_VCU_LockVehType_ovrdval' */

/* Override value for signal VCU_LockVehType */
const volatile uint8 volc_VCU_MCU1EnableReq_ovrdval = 0U;
                    /* Referenced by: '<S493>/volc_VCU_MCU1EnableReq_ovrdval' */
const volatile uint8 volc_VCU_MCUActiveDischg_ovrdval = 0U;
                  /* Referenced by: '<S350>/volc_VCU_MCUActiveDischg_ovrdval' */

/* Override value for signal VCU_MCUActiveDischg */
const volatile uint8 volc_VCU_MCUEnableReq_ovrdval = 0U;
                     /* Referenced by: '<S494>/volc_VCU_MCUEnableReq_ovrdval' */

/* Override value for signal VCU_MCUEnableReq */
const volatile uint16 volc_VCU_MCUMaxTrq_ovrdval = 0U;
                        /* Referenced by: '<S495>/volc_VCU_MCUMaxTrq_ovrdval' */

/* Override value for signal VCU_MCUMaxTrq */
const volatile float32 volc_VCU_MCUSpdRampRate_dftval = 0.0F;
                    /* Referenced by: '<S236>/volc_VCU_MCUSpdRampRate_dftval' */

/* Default value for signal VCU_MCUSpdRampRate */
const volatile float32 volc_VCU_MCUSpdRampRate_ovrdval = 0.0F;
                   /* Referenced by: '<S496>/volc_VCU_MCUSpdRampRate_ovrdval' */

/* Override value for signal VCU_MCUSpdRampRate */
const volatile float32 volc_VCU_MCUTqRampRate_dftval = 0.0F;
                     /* Referenced by: '<S236>/volc_VCU_MCUTqRampRate_dftval' */

/* Default value for signal VCU_MCUTqRampRate */
const volatile float32 volc_VCU_MCUTqRampRate_ovrdval = 0.0F;
                    /* Referenced by: '<S497>/volc_VCU_MCUTqRampRate_ovrdval' */

/* Override value for signal VCU_MCUTqRampRate */
const volatile float32 volc_VCU_MCU_MotorActTrqPercent_ovrdval = 0.0F;
           /* Referenced by: '<S498>/volc_VCU_MCU_MotorActTrqPercent_ovrdval' */

/* Override value for signal VCU_MCU_MotorActTrqPercent */
const volatile float32 volc_VCU_MCU_PumpPWM_Ctrl_ovrdval = 0.0F;
               /* Referenced by: '<S684>/volc_VCU_CabinLoopVal2_FBV5_ovrdval' */

/* Override value for signal VCU_MCU_PumpPWM_Ctrl */
const volatile uint8 volc_VCU_MCU_RelayCtrl_Ctrl_ovrdval = 0U;
                 /* Referenced by: '<S685>/volc_VCU_HTCoolingFanCtrl_ovrdval' */

/* Override value for signal VCU_MCU_RelayCtrl_Ctrl */
const volatile uint8 volc_VCU_MILTelltale_dftval = 0U;
                       /* Referenced by: '<S246>/volc_VCU_MILTelltale_dftval' */

/* Default value for signal VCU_MILTelltale */
const volatile uint8 volc_VCU_MILTelltale_ovrdval = 0U;
                      /* Referenced by: '<S628>/volc_VCU_MILTelltale_ovrdval' */

/* Override value for signal VCU_MILTelltale */
const volatile uint8 volc_VCU_MainPosCtrlCommand_ovrdval = 0U;
               /* Referenced by: '<S543>/volc_VCU_MainPosCtrlCommand_ovrdval' */

/* Override value for signal VCU_MainPosCtrlCommand */
const volatile uint8 volc_VCU_Main_Contactor_Control_ovrdval = 0U;
           /* Referenced by: '<S351>/volc_VCU_Main_Contactor_Control_ovrdval' */

/* Override value for signal VCU_Main_Contactor_Control */
const volatile float32 volc_VCU_MaxEMPwrLmt_ovrdval = 0.0F;
                      /* Referenced by: '<S499>/volc_VCU_MaxEMPwrLmt_ovrdval' */

/* Override value for signal VCU_MaxEMPwrLmt */
const volatile float32 volc_VCU_MinEMPwrLmt_ovrdval = 0.0F;
                      /* Referenced by: '<S500>/volc_VCU_MinEMPwrLmt_ovrdval' */

/* Override value for signal VCU_MinEMPwrLmt */
const volatile float32 volc_VCU_MotorSpeed_ovrdval = 0.0F;
                       /* Referenced by: '<S501>/volc_VCU_MotorSpeed_ovrdval' */

/* Override value for signal VCU_MotorSpeed */
const volatile float32 volc_VCU_MotorTorque_ovrdval = 0.0F;
                      /* Referenced by: '<S502>/volc_VCU_MotorTorque_ovrdval' */

/* Override value for signal VCU_MotorTorque */
const volatile boolean volc_VCU_NMSts_ovrdval = false;
                  /* Referenced by: '<S616>/volc_VCU_DTCClearInhibit_ovrdval' */

/* Override value for signal VCU_NMSts */
const volatile uint8 volc_VCU_Oil_HV_OFF_ovrdval = 0U;
                  /* Referenced by: '<S870>/volc_VCU_HVBC_COpenValue_ovrdval' */

/* Override value for signal VCU_Oil_HV_OFF */
const volatile float32 volc_VCU_PMS_APPowerActual_EV_ovrdval = 0.0F;
             /* Referenced by: '<S413>/volc_VCU_PMS_APPowerActual_EV_ovrdval' */
const volatile boolean volc_VCU_PTC2Enable_ovrdval = false;
                /* Referenced by: '<S394>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile boolean volc_VCU_PTC3Enable_ovrdval = false;
                /* Referenced by: '<S395>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_VCU_PTCEnable_ovrdval = 0U;
                        /* Referenced by: '<S414>/volc_VCU_PTCEnable_ovrdval' */

/* Override value for signal PTCEnable */
const volatile uint8 volc_VCU_PTHVSysErrorLampStsInd_ovrdval = 0U;/* Referenced by:
                                                                   * '<S248>/volc_VCU_PTHVSysErrorLampStsInd_ovrdval'
                                                                   * '<S649>/volc_VCU_PTHVSysErrorLampStsInd_ovrdval'
                                                                   */

/* Override value for signal VCU_PTHVSysErrorLampStsInd */
const volatile uint8 volc_VCU_PTModeInd_ovrdval = 0U;
                        /* Referenced by: '<S650>/volc_VCU_PTModeInd_ovrdval' */

/* Override value for signal VCU_PTModeInd */
const volatile uint8 volc_VCU_PTReadyInd_ovrdval = 0U;
                       /* Referenced by: '<S651>/volc_VCU_PTReadyInd_ovrdval' */

/* Override value for signal VCU_PTReadyInd */
const volatile float32 volc_VCU_PTResiPwr_ovrdval = 0.0F;
                        /* Referenced by: '<S530>/volc_VCU_PTResiPwr_ovrdval' */

/* Override value for signal VCU_PTResiPwr */
const volatile float32 volc_VCU_PTSysElecPwrInd_ovrdval = 0.0F;/* Referenced by:
                                                                * '<S248>/volc_VCU_PTSysElecPwrInd_ovrdval'
                                                                * '<S652>/volc_VCU_PTSysElecPwrInd_ovrdval'
                                                                */

/* Override value for signal VCU_PTSysElecPwrInd */
const volatile uint8 volc_VCU_PreRelay_Ctrl_ovrdval = 0U;/* Referenced by:
                                                          * '<S249>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                          * '<S686>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
                                                          */

/* Override value for signal VCU_PreRelay_Ctrl */
const volatile uint8 volc_VCU_PressureSwi1Sts_ovrdval = 0U;
                  /* Referenced by: '<S590>/volc_VCU_PressureSwi1Sts_ovrdval' */

/* Override value for signal VCU_PressureSwi1Sts */
const volatile uint8 volc_VCU_PressureSwi2Sts_ovrdval = 0U;
                  /* Referenced by: '<S591>/volc_VCU_PressureSwi2Sts_ovrdval' */

/* Override value for signal VCU_PressureSwi2Sts */
const volatile boolean volc_VCU_PropulSysActive_dftval = false;
                   /* Referenced by: '<S224>/volc_VCU_PropulSysActive_dftval' */
const volatile boolean volc_VCU_PropulSysActive_ovrdval = false;
                  /* Referenced by: '<S284>/volc_VCU_PropulSysActive_ovrdval' */

/* Override value for signal VCU_PropulSysActive */
const volatile float32 volc_VCU_QuitControlSpeed_ovrdval = 0.0F;
                 /* Referenced by: '<S480>/volc_VCU_QuitControlSpeed_ovrdval' */

/* Override value for signal VCU_QuitControlSpeed */
const volatile boolean volc_VCU_RMR_ovrdval = false;
                    /* Referenced by: '<S617>/volc_VCU_AccePedalPosD_ovrdval' */

/* Override value for signal VCU_RMR */
const volatile uint8 volc_VCU_RelayCtrl_Ctrl_ovrdval = 0U;
                 /* Referenced by: '<S687>/volc_VCU_HTCoolingFanCtrl_ovrdval' */

/* Override value for signal VCU_RelayCtrl_Ctrl */
const volatile float32 volc_VCU_ReqSpdOrLmt_ovrdval = 0.0F;/* Referenced by:
                                                            * '<S236>/volc_VCU_ReqSpdOrLmt_ovrdval'
                                                            * '<S503>/volc_VCU_ReqSpdOrLmt_ovrdval'
                                                            */

/* Override value for signal VCU_ReqSpdOrLmt */
const volatile float32 volc_VCU_ReqTrqOrLmt_ovrdval = 0.0F;
                      /* Referenced by: '<S504>/volc_VCU_ReqTrqOrLmt_ovrdval' */

/* Override value for signal VCU_ReqTrqOrLmt */
const volatile float32 volc_VCU_SDCACOutFreq_ovrdval = 0.0F;
                     /* Referenced by: '<S544>/volc_VCU_SDCACOutFreq_ovrdval' */

/* Override value for signal VCU_SDCACOutFreq */
const volatile uint8 volc_VCU_SWCompileDay_ovrdval = 0U;
                     /* Referenced by: '<S699>/volc_VCU_SWCompileDay_ovrdval' */

/* Override value for signal VCU_SWCompileDay */
const volatile uint8 volc_VCU_SWCompileMonth_ovrdval = 0U;
                   /* Referenced by: '<S700>/volc_VCU_SWCompileMonth_ovrdval' */

/* Override value for signal VCU_SWCompileMonth */
const volatile float32 volc_VCU_SWCompileYear_ovrdval = 2000.0F;
                    /* Referenced by: '<S701>/volc_VCU_SWCompileYear_ovrdval' */

/* Override value for signal VCU_SWCompileYear */
const volatile uint8 volc_VCU_SelfCheckSts_ovrdval = 0U;
                     /* Referenced by: '<S546>/volc_VCU_SelfCheckSts_ovrdval' */

/* Override value for signal VCU_SelfCheckSts */
const volatile float32 volc_VCU_Set_Temp_ovrdval = 0.0F;
                         /* Referenced by: '<S352>/volc_VCU_Set_Temp_ovrdval' */

/* Override value for signal VCU_Set_Temp */
const volatile boolean volc_VCU_ShiftClimbing = false;
                            /* Referenced by: '<S240>/volc_VCU_ShiftClimbing' */

/* Default value for signal VCU_ShiftClimbing */
const volatile boolean volc_VCU_ShiftClimbing_ovrdval = false;
                          /* Referenced by: '<S573>/volc_VCU_ECOMode_ovrdval' */

/* Override value for signal VCU_ShiftClimbing */
const volatile boolean volc_VCU_ShiftD = false;
                                   /* Referenced by: '<S240>/volc_VCU_ShiftD' */

/* Default value for signal VCU_ShiftD */
const volatile boolean volc_VCU_ShiftD_ovrdval = false;
                         /* Referenced by: '<S574>/volc_VCU_StartSts_ovrdval' */

/* Override value for signal VCU_ShiftD */
const volatile boolean volc_VCU_ShiftR = false;
                                   /* Referenced by: '<S240>/volc_VCU_ShiftR' */

/* Default value for signal VCU_ShiftR */
const volatile boolean volc_VCU_ShiftR_ovrdval = false;
                         /* Referenced by: '<S575>/volc_VCU_StartSts_ovrdval' */

/* Override value for signal VCU_ShiftR */
const volatile uint8 volc_VCU_SoftwareMajorVer_ovrdval = 0U;
                 /* Referenced by: '<S702>/volc_VCU_SoftwareMajorVer_ovrdval' */

/* Override value for signal VCU_SoftwareMajorVer */
const volatile uint8 volc_VCU_SoftwareMinorVer_ovrdval = 0U;
                 /* Referenced by: '<S703>/volc_VCU_SoftwareMinorVer_ovrdval' */

/* Override value for signal VCU_SoftwareMinorVer */
const volatile boolean volc_VCU_StartSts_ovrdval = false;
                         /* Referenced by: '<S576>/volc_VCU_StartSts_ovrdval' */

/* Override value for signal VCU_StartSts */
const volatile uint32 volc_VCU_Stayawake_reasons_ovrdval = 0U;
                    /* Referenced by: '<S618>/volc_VCU_AccePedalPosE_ovrdval' */

/* Override value for signal VCU_Stayawake_reasons */
const volatile boolean volc_VCU_StsBrkSwitch1Invalid_ovrdval = false;
             /* Referenced by: '<S460>/volc_VCU_StsBrkSwitch1Invalid_ovrdval' */
const volatile boolean volc_VCU_TotalOdometerInvalid_ovrdval = false;
             /* Referenced by: '<S630>/volc_VCU_TotalOdometerInvalid_ovrdval' */

/* Override value for signal VCU_TotalOdometerInvalid */
const volatile float32 volc_VCU_TotalOdometer_ovrdval = 0.0F;
                    /* Referenced by: '<S629>/volc_VCU_TotalOdometer_ovrdval' */

/* Override value for signal VCU_TotalOdometer */
const volatile uint8 volc_VCU_TurtleLampReq_ovrdval = 0U;
                    /* Referenced by: '<S653>/volc_VCU_TurtleLampReq_ovrdval' */

/* Override value for signal VCU_TurtleLampReq */
const volatile boolean volc_VCU_VLC_Active_ovrdval = false;
                       /* Referenced by: '<S317>/volc_VCU_VLC_Active_ovrdval' */

/* Override value for signal VCU_VLC_Active */
const volatile boolean volc_VCU_VLC_Available_ovrdval = false;/* Referenced by:
                                                               * '<S225>/volc_VCU_VLC_Available_ovrdval'
                                                               * '<S318>/volc_VCU_VLC_Available_ovrdval'
                                                               */

/* Override value for signal VCU_VLC_Available */
const volatile float32 volc_VCU_VLC_InternalTargetACCeleration_ovrdval = 0.0F;
   /* Referenced by: '<S319>/volc_VCU_VLC_InternalTargetACCeleration_ovrdval' */

/* Override value for signal VCU_VLC_InternalTargetACCeleration */
const volatile float32 volc_VCU_VLC_VCUTargetACCeleration_ovrdval = 0.0F;
        /* Referenced by: '<S320>/volc_VCU_VLC_VCUTargetACCeleration_ovrdval' */

/* Override value for signal VCU_VLC_VCUTargetACCeleration */
const volatile float32 volc_VCU_VehCruisingDistance_ovrdval = 0.0F;
                /* Referenced by: '<S688>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */

/* Override value for signal VCU_VehCruisingDistance */
const volatile uint8 volc_VCU_VehicleAbnormalSts_ovrdval = 0U;/* Referenced by:
                                                               * '<S248>/volc_VCU_VehicleAbnormalSts_ovrdval'
                                                               * '<S654>/volc_VCU_VehicleAbnormalSts_ovrdval'
                                                               */

/* Override value for signal VCU_VehicleAbnormalSts */
const volatile float32 volc_VCU_VehicleIdentification_ovrdval = 0.0F;
            /* Referenced by: '<S689>/volc_VCU_VehicleIdentification_ovrdval' */

/* Override value for signal VCU_VehicleIdentification */
const volatile uint8 volc_VCU_VehicleRunMode_ovrdval = 0U;
                   /* Referenced by: '<S655>/volc_VCU_VehicleRunMode_ovrdval' */

/* Override value for signal VCU_VehicleRunMode */
const volatile uint8 volc_VCU_VehicleSlipWarning_ovrdval = 0U;/* Referenced by:
                                                               * '<S248>/volc_VCU_VehicleSlipWarning'
                                                               * '<S656>/volc_VCU_VehicleSlipWarning'
                                                               */

/* Override value for signal VCU_VehicleSlipWarning */
const volatile boolean volc_VCU_VehicleSpd_flag_ovrdval = false;
                  /* Referenced by: '<S462>/volc_VCU_VehicleSpd_flag_ovrdval' */

/* Override value for signal VCU_VehicleSpd_flag */
const volatile float32 volc_VCU_VehicleSpd_ovrdval = 0.0F;
                       /* Referenced by: '<S461>/volc_VCU_VehicleSpd_ovrdval' */

/* Override value for signal VCU_VehicleSpd */
const volatile uint8 volc_VCU_VehicleSubSysErrorLevel_dftval = 0U;
           /* Referenced by: '<S248>/volc_VCU_VehicleSubSysErrorLevel_dftval' */

/* Default value for signal VCU_VehicleSubSysErrorLevel */
const volatile uint8 volc_VCU_VehicleSubSysErrorLevel_ovrdval = 0U;
          /* Referenced by: '<S657>/volc_VCU_VehicleSubSysErrorLevel_ovrdval' */

/* Override value for signal VCU_VehicleSubSysErrorLevel */
const volatile uint8 volc_VCU_VehicleSysErrorLevel_ovrdval = 0U;
             /* Referenced by: '<S658>/volc_VCU_VehicleSysErrorLevel_ovrdval' */

/* Override value for signal VCU_VehicleSysErrorLevel */
const volatile uint8 volc_VCU_VehicleSysFltLevel_ovrdval = 0U;
               /* Referenced by: '<S636>/volc_VCU_VehicleSysFltLevel_ovrdval' */

/* Override value for signal VCU_VehicleSysFltLevel */
const volatile uint8 volc_VCU_WPCtrl_ovrdval = 0U;
                           /* Referenced by: '<S415>/volc_VCU_WPCtrl_ovrdval' */

/* Override value for signal WPCtrl */
const volatile uint8 volc_VCU_Wakeup_reasons_ovrdval = 0U;
                  /* Referenced by: '<S619>/volc_VCU_DTCClearInhibit_ovrdval' */

/* Override value for signal VCU_Wakeup_reasons */
const volatile uint8 volc_VCU_XBRControlMode_ovrdval = 0U;
                   /* Referenced by: '<S321>/volc_VCU_XBRControlMode_ovrdval' */

/* Override value for signal VCU_XBRControlMode */
const volatile uint8 volc_VCU_XBREBIMode_ovrdval = 0U;
                       /* Referenced by: '<S322>/volc_VCU_XBREBIMode_ovrdval' */

/* Override value for signal VCU_XBREBIMode */
const volatile uint8 volc_VCU_XBRPriority_dftval = 3U;
                       /* Referenced by: '<S225>/volc_VCU_XBRPriority_dftval' */

/* Default value for signal VCU_XBRPriority */
const volatile uint8 volc_VCU_XBRPriority_ovrdval = 0U;
                      /* Referenced by: '<S323>/volc_VCU_XBRPriority_ovrdval' */

/* Override value for signal VCU_XBRPriority */
const volatile boolean volc_VCU_ZeroPwr_Fb_ovrdval = false;
                /* Referenced by: '<S396>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile float32 volc_VCU_bmshAlwChgCurrMax_ovrdval = 300.0F;
                /* Referenced by: '<S399>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_VCU_ePTRegencyLevInd_ovrdval = 0U;
                /* Referenced by: '<S717>/volc_VCU_BattCoolVal3_FBV6_ovrdval' */
const volatile uint8 volc_VCU_ePTReleaseSig_ovrdval = 0U;
                    /* Referenced by: '<S285>/volc_VCU_ePTReleaseSig_ovrdval' */

/* Override value for signal VCU_ePTReleaseSig */
const volatile float32 volc_acc_vehAccXBRDisa_mps2 = 0.0F;/* Referenced by: '<S225>/Relay4' */

/* Deceleration threshold to disable XBR control */
const volatile float32 volc_acc_vehAccXBREna_mps2 = -0.1F;/* Referenced by: '<S225>/Relay4' */

/* Deceleration threshold to enable XBR control */
const volatile boolean volc_b_12VbatRlyReq_invert = false;
                       /* Referenced by: '<S181>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal 12VbatRlyReq */
const volatile boolean volc_b_12VbatRlyReq_ovrdflg = false;
                       /* Referenced by: '<S181>/volc_b_WatPmpEP3PWM_ovrdflg' */

/* Override flag for signal 12VbatRlyReq */
const volatile boolean volc_b_12vDCDCEn_invert = false;
                           /* Referenced by: '<S182>/volc_b_12vDCDCEn_invert' */

/* Invert flag for signal b_12vDCDCEn */
const volatile boolean volc_b_12vDCDCEn_ovrdflg = false;
                          /* Referenced by: '<S182>/volc_b_12vDCDCEn_ovrdflg' */

/* Override flag for signal b_12vDCDCEn */
const volatile boolean volc_b_24vDCDCEn_invert = false;
                           /* Referenced by: '<S183>/volc_b_24vDCDCEn_invert' */

/* Invert flag for signal b_24vDCDCEn */
const volatile boolean volc_b_24vDCDCEn_ovrdflg = false;
                          /* Referenced by: '<S183>/volc_b_24vDCDCEn_ovrdflg' */

/* Override flag for signal b_24vDCDCEn */
const volatile boolean volc_b_AC_EWP_Heat_ovrdflg = false;
              /* Referenced by: '<S374>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_AC_EWP_HeatrPwrCnsAllwd_ovrdflg = false;
              /* Referenced by: '<S375>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_AC_EWP_Run_ovrdflg = false;
              /* Referenced by: '<S376>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_AC_EWP_SpeedReq_ovrdflg = false;
              /* Referenced by: '<S377>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_AC_EWP_Temp_ovrdflg = false;
              /* Referenced by: '<S378>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_AccPedal_1_ovrdflg = false;
                     /* Referenced by: '<S205>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_AccPedal_1 */
const volatile boolean volc_b_AccPedal_2_ovrdflg = false;
                     /* Referenced by: '<S206>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_AccPedal_2 */
const volatile boolean volc_b_BMSH_ACChgTimeRemain_ovrdflg = false;
             /* Referenced by: '<S718>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg' */
const volatile boolean volc_b_BMSH_BattCurr_ovrdflg = false;
                    /* Referenced by: '<S719>/volc_flg_BMSH_BattCurr_ovrdflg' */
const volatile boolean volc_b_BMSH_BattFaultLampState_ovrdflg = false;
          /* Referenced by: '<S720>/volc_flg_BMSH_BattFaultLampState_ovrdflg' */
const volatile boolean volc_b_BMSH_CCM_ThermalManageReq_ovrdflg = false;
        /* Referenced by: '<S721>/volc_flg_BMSH_CCM_ThermalManageReq_ovrdflg' */
const volatile boolean volc_b_BMSH_Cell_TotalNum_ovrdflg = false;
               /* Referenced by: '<S722>/volc_flg_BMSH_Cell_TotalNum_ovrdflg' */
const volatile boolean volc_b_BMSH_ChargeLEDCtrl_ovrdflg = false;
               /* Referenced by: '<S723>/volc_flg_BMSH_ChargeLEDCtrl_ovrdflg' */
const volatile boolean volc_b_BMSH_Charge_Over_Current_ovrdflg = false;
         /* Referenced by: '<S724>/volc_flg_BMSH_Charge_Over_Current_ovrdflg' */
const volatile boolean volc_b_BMSH_ChgTimeRemain_ovrdflg = false;
               /* Referenced by: '<S725>/volc_flg_BMSH_ChgTimeRemain_ovrdflg' */
const volatile boolean volc_b_BMSH_DCChgminusSocketTempSensing_Failure_ovrdflg =
  false;
/* Referenced by: '<S726>/volc_flg_BMSH_DCChgminusSocketTempSensing_Failure_ovrdflg' */
const volatile boolean volc_b_BMSH_DCChgplusSocketTempSensing_Failure_ovrdflg =
  false;
/* Referenced by: '<S727>/volc_flg_BMSH_DCChgplusSocketTempSensing_Failure_ovrdflg' */
const volatile boolean volc_b_BMSH_FastChgCC2ConntState_ovrdflg = false;
        /* Referenced by: '<S728>/volc_flg_BMSH_FastChgCC2ConntState_ovrdflg' */
const volatile boolean volc_b_BMSH_HvBattThermMod_ovrdflg = false;
                     /* Referenced by: '<S407>/volc_b_PMS_ThermalReq_ovrdflg' */
const volatile boolean volc_b_BMSH_InsulationRes_Fault_ovrdflg = false;
         /* Referenced by: '<S729>/volc_flg_BMSH_InsulationRes_Fault_ovrdflg' */
const volatile boolean volc_b_BMSH_ThermalOutofControl_ovrdflg = false;
         /* Referenced by: '<S730>/volc_flg_BMSH_ThermalOutofControl_ovrdflg' */
const volatile boolean volc_b_BMSH_Vehicle_HVILSts_PHEV_ovrdflg = false;
        /* Referenced by: '<S731>/volc_flg_BMSH_Vehicle_HVILSts_PHEV_ovrdflg' */
const volatile boolean volc_b_BrkPedal_1_ovrdflg = false;
                     /* Referenced by: '<S207>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_BrkPedal_1 */
const volatile boolean volc_b_BrkPedal_2_ovrdflg = false;
                     /* Referenced by: '<S208>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal pct_BrkPedal_2 */
const volatile boolean volc_b_EDCP_Flt_ovrdflg = false;
                           /* Referenced by: '<S401>/volc_b_EDCP_Flt_ovrdflg' */
const volatile boolean volc_b_HBCPFlt_ovrdflg = false;
                     /* Referenced by: '<S402>/volc_b_PMS_ThermalReq_ovrdflg' */
const volatile boolean volc_b_PMS_32960FltNum_ovrdflg = false;
                  /* Referenced by: '<S732>/volc_flg_PMS_32960FltNum_ovrdflg' */
const volatile boolean volc_b_PMS_AcceRelayVoltSampSwich_ovrdflg = false;
         /* Referenced by: '<S855>/volc_b_PMS_AcceRelayVoltSampSwich_ovrdflg' */
const volatile boolean volc_b_PMS_AcceSuppressionSts_ovrdflg = false;
               /* Referenced by: '<S379>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
const volatile boolean volc_b_PMS_Acceleration_ovrdflg = false;
                   /* Referenced by: '<S162>/volc_b_PMS_Acceleration_ovrdflg' */
const volatile boolean volc_b_PMS_AccessoryConnStsFb_ovrdflg = false;
             /* Referenced by: '<S577>/volc_b_PMS_AccessoryConnStsFb_ovrdflg' */
const volatile boolean volc_b_PMS_AccessoryCtrlCommand_ovrdflg = false;
           /* Referenced by: '<S258>/volc_b_PMS_AccessoryCtrlCommand_ovrdflg' */
const volatile boolean volc_b_PMS_AccessoryRelayFlt_ovrdflg = false;
              /* Referenced by: '<S578>/volc_b_PMS_AccessoryRelayFlt_ovrdflg' */
const volatile boolean volc_b_PMS_ActualPTTorque_ovrdflg = false;
               /* Referenced by: '<S733>/volc_flg_PMS_ActualPTTorque_ovrdflg' */
const volatile boolean volc_b_PMS_BBM_FaultStatus_ovrdflg = false;
                /* Referenced by: '<S259>/volc_b_PMS_BBM_FaultStatus_ovrdflg' */
const volatile boolean volc_b_PMS_BBM_WorkSts_ovrdflg = false;
                    /* Referenced by: '<S260>/volc_b_PMS_BBM_WorkSts_ovrdflg' */
const volatile boolean volc_b_PMS_BMS_Reignstatus1_ovrdflg = false;
                     /* Referenced by: '<S734>/volc_flg_PMS_ePTFault_ovrdflg' */
const volatile boolean volc_b_PMS_BMS_Reignstatus2_ovrdflg = false;
                     /* Referenced by: '<S735>/volc_flg_PMS_ePTFault_ovrdflg' */
const volatile boolean volc_b_PMS_Brake_LightsRequest_ovrdflg = false;
           /* Referenced by: '<S736>/volc_flg_PMS_Brake_LightsReques_ovrdflg' */
const volatile boolean volc_b_PMS_CPSRU_ovrdflg = false;
               /* Referenced by: '<S380>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
const volatile boolean volc_b_PMS_CampModeFbFailrReason_ovrdflg = false;
          /* Referenced by: '<S738>/volc_b_PMS_CampModeFbFailrReason_ovrdflg' */
const volatile boolean volc_b_PMS_CampModeFb_ovrdflg = false;
                     /* Referenced by: '<S737>/volc_b_PMS_CampModeFb_ovrdflg' */
const volatile boolean volc_b_PMS_ChargPwr_ovrdflg = false;
              /* Referenced by: '<S381>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_PMS_ChargeLimitResponse_ovrdflg = false;
               /* Referenced by: '<S739>/volc_flg_PMS_VacuumPressure_ovrdflg' */
const volatile boolean volc_b_PMS_CruisingDstSwtFb_ovrdflg = false;
             /* Referenced by: '<S740>/volc_flg_PMS_CruisingDstSwtFb_ovrdflg' */
const volatile boolean volc_b_PMS_CurrentGearPositionValid_ovrdflg = false;
     /* Referenced by: '<S639>/volc_flg_PMS_CurrentGearPositionValid_ovrdflg' */
const volatile boolean volc_b_PMS_DriverDemandTorque_ovrdflg = false;
           /* Referenced by: '<S741>/volc_flg_PMS_DriverDemandTorque_ovrdflg' */
const volatile boolean volc_b_PMS_DrivingTakeEleSts_ovrdflg = false;
              /* Referenced by: '<S261>/volc_b_PMS_DrivingTakeEleSts_ovrdflg' */
const volatile boolean volc_b_PMS_DrvPfmncRed_ovrdflg = false;
                 /* Referenced by: '<S742>/volc_flg_PMS_DrvPfmncRedn_ovrdflg' */
const volatile boolean volc_b_PMS_EPBClosedReq_PMS_ovrdflg = false;
             /* Referenced by: '<S743>/volc_flg_PMS_EPBClosedReq_PMS_ovrdflg' */
const volatile boolean volc_b_PMS_Fn1GearRlyDrvStsFb_ovrdflg = false;
               /* Referenced by: '<S382>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
const volatile boolean volc_b_PMS_Fn2GearRlyDrvStsFb_ovrdflg = false;
               /* Referenced by: '<S383>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
const volatile boolean volc_b_PMS_FrntHeatModEnad_ovrdflg = false;
              /* Referenced by: '<S163>/volc_flg_PMS_FrntHeatModEnad_ovrdflg' */
const volatile boolean volc_b_PMS_FrntHeatPwrAllwd_ovrdflg = false;
             /* Referenced by: '<S164>/volc_flg_PMS_FrntHeatPwrAllwd_ovrdflg' */
const volatile boolean volc_b_PMS_GearIntervene_ovrdflg = false;
             /* Referenced by: '<S744>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg' */
const volatile boolean volc_b_PMS_GrossComVehWeight_ovrdflg = false;
            /* Referenced by: '<S745>/volc_flg_PMS_GrossComVehWeight_ovrdflg' */
const volatile boolean volc_b_PMS_HVIL1Sts_EV_ovrdflg = false;
                  /* Referenced by: '<S165>/volc_flg_PMS_HVIL1Sts_EV_ovrdflg' */
const volatile boolean volc_b_PMS_HVIL1Sts_UB_ovrdflg = false;
                    /* Referenced by: '<S166>/volc_b_PMS_HVIL1Sts_UB_ovrdflg' */
const volatile boolean volc_b_PMS_HVIL2Sts_EV_ovrdflg = false;
                  /* Referenced by: '<S167>/volc_flg_PMS_HVIL2Sts_EV_ovrdflg' */
const volatile boolean volc_b_PMS_HVIL2Sts_UB_ovrdflg = false;
                    /* Referenced by: '<S168>/volc_b_PMS_HVIL2Sts_UB_ovrdflg' */
const volatile boolean volc_b_PMS_HVILSts_EV_ovrdflg = false;
                   /* Referenced by: '<S169>/volc_flg_PMS_HVILSts_EV_ovrdflg' */
const volatile boolean volc_b_PMS_HvCoolgPwrAllwd_ovrdflg = false;
              /* Referenced by: '<S403>/volc_flg_PMS_HvCoolgPwrAllwd_ovrdflg' */
const volatile boolean volc_b_PMS_HvHeatgPwrAllwd_ovrdflg = false;
              /* Referenced by: '<S404>/volc_flg_PMS_HvHeatgPwrAllwd_ovrdflg' */
const volatile boolean volc_b_PMS_IPKTotalOdometer_ovrdflg = false;
               /* Referenced by: '<S746>/volc_b_PMS_IPKTotalOdometer_ovrdflg' */
const volatile boolean volc_b_PMS_InventorySpdLmtRxSts_ovrdflg = false;
         /* Referenced by: '<S747>/volc_flg_PMS_InventorySpdLmtRxSts_ovrdflg' */
const volatile boolean volc_b_PMS_InventorySpdLmtSts_ovrdflg = false;
           /* Referenced by: '<S748>/volc_flg_PMS_InventorySpdLmtSts_ovrdflg' */
const volatile boolean volc_b_PMS_IsgActvDampgModReq_ovrdflg = false;
           /* Referenced by: '<S487>/volc_flg_PMS_IsgActvDampgModReq_ovrdflg' */
const volatile boolean volc_b_PMS_Life_ovrdflg = false;
                         /* Referenced by: '<S749>/volc_flg_PMS_Life_ovrdflg' */
const volatile boolean volc_b_PMS_LockVehExecutedSts_ovrdflg = false;
              /* Referenced by: '<S384>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_PMS_LockVehPerFlag_ovrdflg = false;
               /* Referenced by: '<S750>/volc_flg_PMS_LockVehPerFlag_ovrdflg' */
const volatile boolean volc_b_PMS_LockVehPerRxSts_ovrdflg = false;
              /* Referenced by: '<S751>/volc_flg_PMS_LockVehPerRxSts_ovrdflg' */
const volatile boolean volc_b_PMS_MCUFlowFeedback_EV_ovrdflg = false;
           /* Referenced by: '<S405>/volc_flg_PMS_MCUFlowFeedback_EV_ovrdflg' */
const volatile boolean volc_b_PMS_MaxPTTorqueAllowed_ovrdflg = false;
           /* Referenced by: '<S752>/volc_flg_PMS_MaxPTTorqueAllowed_ovrdflg' */
const volatile boolean volc_b_PMS_MinPTTorqueAllowed_ovrdflg = false;
           /* Referenced by: '<S753>/volc_flg_PMS_MinPTTorqueAllowed_ovrdflg' */
const volatile boolean volc_b_PMS_OTAInstrucStsReminder_ovrdflg = false;
        /* Referenced by: '<S754>/volc_flg_PMS_OTAInstrucStsReminder_ovrdflg' */
const volatile boolean volc_b_PMS_OTAInstructRxnSts_ovrdflg = false;
            /* Referenced by: '<S755>/volc_flg_PMS_OTAInstructRxnSts_ovrdflg' */
const volatile boolean volc_b_PMS_OdometerbackupEnable_ovrdflg = false;
           /* Referenced by: '<S757>/volc_b_PMS_OdometerbackupEnable_ovrdflg' */
const volatile boolean volc_b_PMS_Odometerbackup_ovrdflg = false;
               /* Referenced by: '<S756>/volc_flg_PMS_Odometerbackup_ovrdflg' */

/* Override flag  */
const volatile boolean volc_b_PMS_PTC1ConnStsFb_ovrdflg = false;
                  /* Referenced by: '<S579>/volc_b_PMS_PTC1ConnStsFb_ovrdflg' */
const volatile boolean volc_b_PMS_PTC1RelayFlt_ovrdflg = false;
                   /* Referenced by: '<S580>/volc_b_PMS_PTC1RelayFlt_ovrdflg' */
const volatile boolean volc_b_PMS_PTC3ConnStsFb_ovrdflg = false;
                  /* Referenced by: '<S581>/volc_b_PMS_PTC3ConnStsFb_ovrdflg' */
const volatile boolean volc_b_PMS_PTC3RelayFlt_ovrdflg = false;
                   /* Referenced by: '<S582>/volc_b_PMS_PTC3RelayFlt_ovrdflg' */
const volatile boolean volc_b_PMS_PTCRelayVoltSampSwich_ovrdflg = false;
          /* Referenced by: '<S856>/volc_b_PMS_PTCRelayVoltSampSwich_ovrdflg' */
const volatile boolean volc_b_PMS_PowerOffCmdRxSts_ovrdflg = false;
               /* Referenced by: '<S758>/volc_b_PMS_PowerOffCmdRxSts_ovrdflg' */
const volatile boolean volc_b_PMS_PowerOffCmdSts_ovrdflg = false;
                 /* Referenced by: '<S759>/volc_b_PMS_PowerOffCmdSts_ovrdflg' */
const volatile boolean volc_b_PMS_PreAccessoryConnStsFb_ovrdflg = false;
          /* Referenced by: '<S583>/volc_b_PMS_PreAccessoryConnStsFb_ovrdflg' */
const volatile boolean volc_b_PMS_PreAccessoryRelayFlt_ovrdflg = false;
           /* Referenced by: '<S584>/volc_b_PMS_PreAccessoryRelayFlt_ovrdflg' */
const volatile boolean volc_b_PMS_Real_PedalPositionInvalid_ovrdflg = false;
    /* Referenced by: '<S452>/volc_flg_PMS_Real_PedalPositionInvalid_ovrdflg' */
const volatile float32 volc_b_PMS_Real_PedalPosition_ovrdflg = 0.0F;
           /* Referenced by: '<S451>/volc_flg_PMS_Real_PedalPosition_ovrdflg' */
const volatile boolean volc_b_PMS_RegenTarTrqPot_ovrdflg = false;
               /* Referenced by: '<S760>/volc_flg_PMS_RegenTarTrqPot_ovrdflg' */
const volatile boolean volc_b_PMS_RegenTrqAct_ovrdflg = false;
                  /* Referenced by: '<S761>/volc_flg_PMS_RegenTrqAct_ovrdflg' */
const volatile boolean volc_b_PMS_RegenTrqPot_ovrdflg = false;
                  /* Referenced by: '<S762>/volc_flg_PMS_RegenTrqPot_ovrdflg' */
const volatile boolean volc_b_PMS_RegulationSpeed_ovrdflg = false;
               /* Referenced by: '<S385>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
const volatile boolean volc_b_PMS_RemChrgCmdFailrPrompt_ovrdflg = false;
              /* Referenced by: '<S386>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_PMS_SpdLmtLevelRxSts_ovrdflg = false;
             /* Referenced by: '<S764>/volc_flg_PMS_SpdLmtLevelRxSts_ovrdflg' */
const volatile boolean volc_b_PMS_SpdLmtLevel_ovrdflg = false;
                  /* Referenced by: '<S763>/volc_flg_PMS_SpdLmtLevel_ovrdflg' */
const volatile boolean volc_b_PMS_StsBatLockSensor_ovrdflg = false;
             /* Referenced by: '<S170>/volc_flg_PMS_StsBatLockSensor_ovrdflg' */
const volatile boolean volc_b_PMS_TBOX_HVILState_ovrdflg = false;
               /* Referenced by: '<S765>/volc_flg_PMS_TBOX_HVILState_ovrdflg' */
const volatile boolean volc_b_PMS_TBOX_LifeSts_ovrdflg = false;
                 /* Referenced by: '<S766>/volc_flg_PMS_TBOX_LifeSts_ovrdflg' */
const volatile boolean volc_b_PMS_TakeEleSwtIndReq_ovrdflg = false;
               /* Referenced by: '<S387>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg' */
const volatile boolean volc_b_PMS_ThermalReq_ovrdflg = false;
                     /* Referenced by: '<S406>/volc_b_PMS_ThermalReq_ovrdflg' */
const volatile boolean volc_b_PMS_Torque_Ovrd_Active_ovrdflg = false;
               /* Referenced by: '<S388>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
const volatile boolean volc_b_PMS_Torque_Ovrd_Type_ovrdflg = false;
               /* Referenced by: '<S389>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */
const volatile boolean volc_b_PMS_V2XDchaSwtFb1_ovrdflg = false;
             /* Referenced by: '<S767>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode1_8_15_S_ovrdflg = false;
              /* Referenced by: '<S768>/volc_flg_PMS_VINCode1_8_15_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode2_9_16_S_ovrdflg = false;
              /* Referenced by: '<S769>/volc_flg_PMS_VINCode2_9_16_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode3_10_17_S_ovrdflg = false;
             /* Referenced by: '<S770>/volc_flg_PMS_VINCode3_10_17_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode4_11_S_ovrdflg = false;
                /* Referenced by: '<S771>/volc_flg_PMS_VINCode4_11_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode5_12_S_ovrdflg = false;
                /* Referenced by: '<S772>/volc_flg_PMS_VINCode5_12_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode6_13_S_ovrdflg = false;
                /* Referenced by: '<S773>/volc_flg_PMS_VINCode6_13_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINCode7_14_S_ovrdflg = false;
                /* Referenced by: '<S774>/volc_flg_PMS_VINCode7_14_S_ovrdflg' */
const volatile boolean volc_b_PMS_VINMessageNum_S_ovrdflg = false;
              /* Referenced by: '<S775>/volc_flg_PMS_VINMessageNum_S_ovrdflg' */
const volatile boolean volc_b_PMS_VacuumPressure_ovrdflg = false;
               /* Referenced by: '<S776>/volc_flg_PMS_VacuumPressure_ovrdflg' */
const volatile boolean volc_b_PMS_VacuumPump_FB_ovrdflg = false;
                  /* Referenced by: '<S777>/volc_b_PMS_VacuumPump_FB_ovrdflg' */
const volatile boolean volc_b_PMS_VacuumSystemsta_ovrdflg = false;
              /* Referenced by: '<S778>/volc_flg_PMS_VacuumSystemsta_ovrdflg' */
const volatile boolean volc_b_PMS_VehicleSysErrorLevelG_ovrdflg = false;
              /* Referenced by: '<S398>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_PMS_VersionConversionFlag_ovrdflg = false;
        /* Referenced by: '<S779>/volc_flg_PMS_VersionConversionFlag_ovrdflg' */
const volatile boolean volc_b_PMS_VersionConversionRxSts_ovrdflg = false;
       /* Referenced by: '<S780>/volc_flg_PMS_VersionConversionRxSts_ovrdflg' */
const volatile boolean volc_b_PMS_ePTFault_ovrdflg = false;
                     /* Referenced by: '<S781>/volc_flg_PMS_ePTFault_ovrdflg' */
const volatile boolean volc_b_ResetHSDFRA16A17_invert = false;
                         /* Referenced by: '<S186>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA16A17 */
const volatile boolean volc_b_ResetHSDFRA16A17_ovrdflg = false;
                        /* Referenced by: '<S186>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA16A17 */
const volatile boolean volc_b_ResetHSDFRA16A17_ovrdval = false;
                        /* Referenced by: '<S186>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA16A17 */
const volatile boolean volc_b_ResetHSDFRA1A2_invert = false;
                         /* Referenced by: '<S187>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA1A2 */
const volatile boolean volc_b_ResetHSDFRA1A2_ovrdflg = false;
                        /* Referenced by: '<S187>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA1A2 */
const volatile boolean volc_b_ResetHSDFRA1A2_ovrdval = false;
                        /* Referenced by: '<S187>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA1A2 */
const volatile boolean volc_b_ResetHSDFRA31A32_invert = false;
                         /* Referenced by: '<S188>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA31A32 */
const volatile boolean volc_b_ResetHSDFRA31A32_ovrdflg = false;
                        /* Referenced by: '<S188>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA31A32 */
const volatile boolean volc_b_ResetHSDFRA31A32_ovrdval = false;
                        /* Referenced by: '<S188>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA31A32 */
const volatile boolean volc_b_ResetHSDFRA46A47_invert = false;
                         /* Referenced by: '<S189>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal b_ResetHSDFRA46A47 */
const volatile boolean volc_b_ResetHSDFRA46A47_ovrdflg = false;
                        /* Referenced by: '<S189>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_ResetHSDFRA46A47 */
const volatile boolean volc_b_ResetHSDFRA46A47_ovrdval = false;
                        /* Referenced by: '<S189>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_ResetHSDFRA46A47 */
const volatile boolean volc_b_ShtDown_ovrdflg = false;
                      /* Referenced by: '<S216>/vilc_b_ResrAirSwitch_ovrdflg' */
const volatile boolean volc_b_TBOX_ChrgSoftSwCtrlst_ovrdflg = false;
              /* Referenced by: '<S390>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_TBOX_ReservationChrgnSts_ovrdflg = false;
              /* Referenced by: '<S391>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_12VATS1Enable_ovrdflg = false;
                /* Referenced by: '<S431>/volc_flg_VCU_12VATS1Enable_ovrdflg' */

/* Override flag for signal b_VCU_12VATS1Enable */
const volatile boolean volc_b_VCU_12VATS1_PWMRequest_ovrdflg = false;
           /* Referenced by: '<S432>/volc_flg_VCU_12VATS1_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_12VATS1_PWMRequest */
const volatile boolean volc_b_VCU_12VDCDCCutOffLV_ovrdflg = false;
              /* Referenced by: '<S535>/volc_flg_VCU_12VDCDCCutOffLV_ovrdflg' */

/* Override flag for signal b_VCU_12VDCDCCutOffLV */
const volatile boolean volc_b_VCU_12VDCDCEnableOut_ovrdflg = false;
             /* Referenced by: '<S536>/volc_flg_VCU_12VDCDCEnableOut_ovrdflg' */

/* Override flag for signal b_VCU_12VDCDCEnableOut */
const volatile boolean volc_b_VCU_24V_Switch_ovrdflg = false;
             /* Referenced by: '<S679>/volc_b_VCU_CabinLoopVal1_FBV6_ovrdflg' */

/* Override flag for signal VCU_24V_Switch */
const volatile boolean volc_b_VCU_ACActiveReq_ovrdflg = false;
                  /* Referenced by: '<S453>/volc_flg_VCU_ACActiveReq_ovrdflg' */

/* Override flag for signal b_VCU_ACActiveReq */
const volatile boolean volc_b_VCU_ACC1PosVol_ovrdflg = false;
                     /* Referenced by: '<S564>/volc_b_VCU_ACC1PosVol_ovrdflg' */

/* Override flag for signal b_VCU_ACC1PosVol */
const volatile boolean volc_b_VCU_ACC2PosVol_ovrdflg = false;
                     /* Referenced by: '<S565>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal b_VCU_ACC2PosVol */
const volatile boolean volc_b_VCU_ACCMEnable_ovrdflg = false;
                     /* Referenced by: '<S408>/volc_b_VCU_ACCMEnable_ovrdflg' */

/* Override flag for signal ACCMEnable */
const volatile boolean volc_b_VCU_ACCY1CtrlCmd_ovrdflg = false;
                   /* Referenced by: '<S262>/volc_b_VCU_ACCY1CtrlCmd_ovrdflg' */

/* Override flag for signal VCU_ACCY1CtrlCmd */
const volatile boolean volc_b_VCU_ACCYEnableIn_ovrdflg = false;
                   /* Referenced by: '<S263>/volc_b_VCU_ACCYEnableIn_ovrdflg' */

/* Override flag for signal VCU_ACCYEnableIn */
const volatile boolean volc_b_VCU_ACUCrashfz_Back_ovrdflg = false;
                /* Referenced by: '<S264>/volc_b_VCU_ACUCrashfz_Back_ovrdflg' */

/* Override flag for signal VCU_ACUCrashfz_Back */
const volatile boolean volc_b_VCU_AEC_ovrdflg = false;
                          /* Referenced by: '<S527>/volc_flg_VCU_AEC_ovrdflg' */

/* Override flag for signal b_VCU_AEC */
const volatile boolean volc_b_VCU_APUSWILED_Ctrl_ovrdflg = false;
                 /* Referenced by: '<S265>/volc_b_VCU_APUSWILED_Ctrl_ovrdflg' */

/* Override flag for signal VCU_APUSWILED_Ctrl */
const volatile boolean volc_b_VCU_ATS1Enable_ovrdflg = false;
                   /* Referenced by: '<S433>/volc_flg_VCU_ATS1Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS1Enable */
const volatile boolean volc_b_VCU_ATS1_PWMRequest_ovrdflg = false;
              /* Referenced by: '<S434>/volc_flg_VCU_ATS1_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS1_PWMRequest */
const volatile boolean volc_b_VCU_ATS2Enable_ovrdflg = false;
                   /* Referenced by: '<S435>/volc_flg_VCU_ATS2Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS2Enable */
const volatile boolean volc_b_VCU_ATS2_PWMRequest_ovrdflg = false;
              /* Referenced by: '<S436>/volc_flg_VCU_ATS2_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS2_PWMRequest */
const volatile boolean volc_b_VCU_ATS3Enable_ovrdflg = false;
                   /* Referenced by: '<S437>/volc_flg_VCU_ATS3Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS3Enable */
const volatile boolean volc_b_VCU_ATS3_PWMRequest_ovrdflg = false;
              /* Referenced by: '<S438>/volc_flg_VCU_ATS3_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS3_PWMRequest */
const volatile boolean volc_b_VCU_ATS4Enable_ovrdflg = false;
                   /* Referenced by: '<S439>/volc_flg_VCU_ATS4Enable_ovrdflg' */

/* Override flag for signal b_VCU_ATS4Enable */
const volatile boolean volc_b_VCU_ATS4_PWMRequest_ovrdflg = false;
              /* Referenced by: '<S440>/volc_flg_VCU_ATS4_PWMRequest_ovrdflg' */

/* Override flag for signal b_VCU_ATS4_PWMRequest */
const volatile boolean volc_b_VCU_AWB_ovrdflg = false;
                /* Referenced by: '<S614>/volc_flg_VCU_AccePedalPosE_ovrdflg' */

/* Override flag for signal VCU_AWB */
const volatile boolean volc_b_VCU_AccePedalPosD_ovrdflg = false;
                /* Referenced by: '<S626>/volc_flg_VCU_AccePedalPosD_ovrdflg' */

/* Override flag for signal VCU_AccePedalPosD */
const volatile boolean volc_b_VCU_AccePedalPosE_ovrdflg = false;
                /* Referenced by: '<S627>/volc_flg_VCU_AccePedalPosE_ovrdflg' */

/* Override flag for signal VCU_AccePedalPosE */
const volatile boolean volc_b_VCU_AcceleratorPedalPosition_ovrdflg = false;
     /* Referenced by: '<S454>/volc_flg_VCU_AcceleratorPedalPosition_ovrdflg' */

/* Override flag for signal b_VCU_AcceleratorPedalPosition */
const volatile boolean volc_b_VCU_AcceleratorPedal_flag_ovrdflg = false;
        /* Referenced by: '<S455>/volc_flg_VCU_AcceleratorPedal_flag_ovrdflg' */

/* Override flag for signal VCU_AcceleratorPedal_flag */
const volatile boolean volc_b_VCU_AccyAllowEnable_Ctrl_ovrdflg = false;
           /* Referenced by: '<S266>/volc_b_VCU_AccyAllowEnable_Ctrl_ovrdflg' */

/* Override flag for signal VCU_AccyAllowEnable_Ctrl */
const volatile boolean volc_b_VCU_AccyPower_back_ovrdflg = false;
                 /* Referenced by: '<S267>/volc_b_VCU_AccyPower_back_ovrdflg' */

/* Override flag for signal VCU_AccyPower_back */
const volatile boolean volc_b_VCU_ActualGear_ovrdflg = false;
                   /* Referenced by: '<S868>/volc_flg_VCU_ActualGear_ovrdflg' */

/* Override flag for signal b_VCU_ActualGear */
const volatile boolean volc_b_VCU_Address_ovrdflg = false;
                /* Referenced by: '<S615>/volc_flg_VCU_AccePedalPosD_ovrdflg' */

/* Override flag for signal VCU_Address */
const volatile boolean volc_b_VCU_AllowChg_ovrdflg = false;
                     /* Referenced by: '<S537>/volc_flg_VCU_AllowChg_ovrdflg' */

/* Override flag for signal b_VCU_AllowChg */
const volatile boolean volc_b_VCU_AppSts_ovrdflg = false;
                     /* Referenced by: '<S566>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal VCU_AppSts */
const volatile boolean volc_b_VCU_AvgEVConsume_ovrdflg = false;
                   /* Referenced by: '<S268>/volc_b_VCU_AvgEVConsume_ovrdflg' */

/* Override flag for signal VCU_AvgEVConsume */
const volatile boolean volc_b_VCU_AvgFuelVF_ovrdflg = false;
                      /* Referenced by: '<S269>/volc_b_VCU_AvgFuelVF_ovrdflg' */

/* Override flag for signal VCU_AvgFuelVF */
const volatile boolean volc_b_VCU_BMSHVOnOffReq_ovrdflg = false;
                /* Referenced by: '<S538>/volc_flg_VCU_BMSHVOnOffReq_ovrdflg' */

/* Override flag for signal b_VCU_BMSHVOnOffReq */
const volatile boolean volc_b_VCU_BMSH_DCChgRelayVolt_ovrdflg = false;
            /* Referenced by: '<S539>/volc_b_VCU_BMSH_DCChgRelayVolt_ovrdflg' */
const volatile boolean volc_b_VCU_BMS_SOC_ovrdflg = false;
                        /* Referenced by: '<S335>/volc_b_VCU_BMS_SOC_ovrdflg' */

/* Override flag for signal VCU_BMS_SOC */
const volatile boolean volc_b_VCU_BMS_voltage_ovrdflg = false;
                    /* Referenced by: '<S336>/volc_b_VCU_BMS_voltage_ovrdflg' */

/* Override flag for signal VCU_BMS_voltage */
const volatile boolean volc_b_VCU_BPTCCtrlCmd_ovrdflg = false;
                    /* Referenced by: '<S561>/volc_b_VCU_BPTCCtrlCmd_ovrdflg' */

/* Override flag for signal VCU_BPTCCtrlCmd */
const volatile boolean volc_b_VCU_BPTCEnable_invert = false;
                     /* Referenced by: '<S859>/volc_b_VCU_HVBC_Enable_invert' */

/* Invert flag for signal VCU_BPTCEnable */
const volatile boolean volc_b_VCU_BPTCEnable_ovrdflg = false;
                    /* Referenced by: '<S859>/volc_b_VCU_HVBC_Enable_ovrdflg' */

/* Override flag for signal VCU_BPTCEnable */
const volatile boolean volc_b_VCU_BPTCPowerRatio_ovrdflg = false;
                /* Referenced by: '<S860>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_BPTCPowerRatio */
const volatile boolean volc_b_VCU_BPTCTempSetting_ovrdflg = false;
                /* Referenced by: '<S861>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_BPTCTempSetting */
const volatile boolean volc_b_VCU_BattCoolVal3_FBV5_ovrdflg = false;
              /* Referenced by: '<S597>/volc_b_VCU_BattCoolVal3_FBV5_ovrdflg' */

/* Override flag for signal b_VCU_BattCoolVal3_FBV5 */
const volatile boolean volc_b_VCU_BattCoolVal3_FBV6_ovrdflg = false;
              /* Referenced by: '<S598>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */

/* Override flag for signal b_VCU_BattCoolVal3_FBV6 */
const volatile boolean volc_b_VCU_BattHeatVal2_FBV5_ovrdflg = false;
              /* Referenced by: '<S599>/volc_b_VCU_BattHeatVal2_FBV5_ovrdflg' */

/* Override flag for signal b_VCU_BattHeatVal2_FBV5 */
const volatile boolean volc_b_VCU_BattHeatVal2_FBV6_ovrdflg = false;
              /* Referenced by: '<S600>/volc_b_VCU_BattHeatVal2_FBV6_ovrdflg' */

/* Override flag for signal b_VCU_BattHeatVal2_FBV6 */
const volatile boolean volc_b_VCU_BattMaxTemp_ovrdflg = false;
                  /* Referenced by: '<S337>/volc_flg_VCU_BattMaxTemp_ovrdflg' */

/* Override flag for signal VCU_BattMaxTemp */
const volatile boolean volc_b_VCU_BattMinTemp_ovrdflg = false;
                  /* Referenced by: '<S338>/volc_flg_VCU_BattMinTemp_ovrdflg' */

/* Override flag for signal VCU_BattMinTemp */
const volatile boolean volc_b_VCU_BattPackInCoolTemp_ovrdflg = false;
             /* Referenced by: '<S409>/volc_b_VCU_BattPackInCoolTemp_ovrdflg' */

/* Override flag for signal VCU_BattPackInCoolTemp */
const volatile boolean volc_b_VCU_BattPackInCoolTempback_ovrdflg = false;
         /* Referenced by: '<S270>/volc_b_VCU_BattPackInCoolTempback_ovrdflg' */

/* Override flag for signal VCU_BattPackInCoolTempback */
const volatile boolean volc_b_VCU_BattPackOutCoolTemp_ovrdflg = false;
            /* Referenced by: '<S410>/volc_b_VCU_BattPackoutCoolTemp_ovrdflg' */

/* Override flag for signal VCU_BattPackOutCoolTemp */
const volatile boolean volc_b_VCU_BattPackoutCoolTempback_ovrdflg = false;
        /* Referenced by: '<S271>/volc_b_VCU_BattPackoutCoolTempback_ovrdflg' */

/* Override flag for signal VCU_BattPackoutCoolTempback */
const volatile boolean volc_b_VCU_BattVol_ovrdflg = false;
                      /* Referenced by: '<S339>/volc_flg_VCU_BattVol_ovrdflg' */

/* Override flag for signal VCU_BattVol */
const volatile boolean volc_b_VCU_BatteryCoolentTemp_ovrdflg = false;
           /* Referenced by: '<S411>/volc_flg_VCU_BatteryCoolentTemp_ovrdflg' */

/* Override flag for signal b_VCU_BatteryCoolentTemp */
const volatile boolean volc_b_VCU_BatteryVol_ovrdflg = false;
                     /* Referenced by: '<S567>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal b_VCU_BatteryVol */
const volatile boolean volc_b_VCU_Batty_Charge_DisChargeState_ovrdflg = false;
  /* Referenced by: '<S340>/volc_flg_VCU_Batty_Charge_DisChargeState_ovrdflg' */

/* Override flag for signal VCU_Batty_Charge_DisChargeState */
const volatile boolean volc_b_VCU_Batty_ThermalMangeActive_ovrdflg = false;
     /* Referenced by: '<S341>/volc_flg_VCU_Batty_ThermalMangeActive_ovrdflg' */

/* Override flag for signal VCU_Batty_ThermalMangeActive */
const volatile boolean volc_b_VCU_Batty_ThermalMangeReq_ovrdflg = false;
        /* Referenced by: '<S412>/volc_flg_VCU_Batty_ThermalMangeReq_ovrdflg' */

/* Override flag for signal b_VCU_Batty_ThermalMangeReq */
const volatile boolean volc_b_VCU_Batty_ThermalMangeWorkMode_ovrdflg = false;
   /* Referenced by: '<S342>/volc_flg_VCU_Batty_ThermalMangeWorkMode_ovrdflg' */

/* Override flag for signal VCU_Batty_ThermalMangeWorkMode */
const volatile boolean volc_b_VCU_BrakSwitchSts_ovrdflg = false;
                /* Referenced by: '<S456>/volc_flg_VCU_BrakSwitchSts_ovrdflg' */

/* Override flag for signal b_VCU_BrakSwitchSts */
const volatile boolean volc_b_VCU_Brake1PosVol_ovrdflg = false;
                   /* Referenced by: '<S592>/volc_b_VCU_Brake1PosVol_ovrdflg' */

/* Override flag for signal b_VCU_Brake1PosVol */
const volatile boolean volc_b_VCU_Brake1Sts_invert = false;
                       /* Referenced by: '<S568>/volc_b_VCU_Brake1Sts_invert' */

/* Invert flag for signal b_VCU_Brake1Sts */
const volatile boolean volc_b_VCU_Brake1Sts_ovrdflg = false;
                      /* Referenced by: '<S568>/volc_b_VCU_Brake1Sts_ovrdflg' */

/* Override flag for signal b_VCU_Brake1Sts */
const volatile boolean volc_b_VCU_Brake2PosVol_ovrdflg = false;
                   /* Referenced by: '<S593>/volc_b_VCU_Brake2PosVol_ovrdflg' */

/* Override flag for signal b_VCU_Brake2PosVol */
const volatile boolean volc_b_VCU_Brake2Sts_invert = false;
                       /* Referenced by: '<S569>/volc_b_VCU_Brake2Sts_invert' */

/* Invert flag for signal b_VCU_Brake2Sts */
const volatile boolean volc_b_VCU_Brake2Sts_ovrdflg = false;
                      /* Referenced by: '<S569>/volc_b_VCU_Brake2Sts_ovrdflg' */

/* Override flag for signal b_VCU_Brake2Sts */
const volatile boolean volc_b_VCU_BrakePedalPosition_ovrdflg = false;
           /* Referenced by: '<S457>/volc_flg_VCU_BrakePedalPosition_ovrdflg' */

/* Override flag for signal b_VCU_BrakePedalPosition */
const volatile boolean volc_b_VCU_BrkSysErr_ovrdflg = false;
                    /* Referenced by: '<S640>/volc_flg_VCU_BrkSysErr_ovrdflg' */

/* Override flag for signal b_VCU_BrkSysErr */
const volatile boolean volc_b_VCU_CCFb_ovrdflg = false;
                           /* Referenced by: '<S585>/volc_b_VCU_CCFb_ovrdflg' */

/* Override flag for signal b_VCU_CCFb */
const volatile boolean volc_b_VCU_CC_Acceleration_ovrdflg = false;
                /* Referenced by: '<S314>/volc_b_VCU_CC_Acceleration_ovrdflg' */

/* Override flag for signal VCU_CC_Acceleration */
const volatile boolean volc_b_VCU_Cab_ThermalMangeReq_ovrdflg = false;
          /* Referenced by: '<S343>/volc_flg_VCU_Cab_ThermalMangeReq_ovrdflg' */

/* Override flag for signal VCU_Cab_ThermalMangeReq */
const volatile boolean volc_b_VCU_CabinLoopVal1_FBV6_ovrdflg = false;
             /* Referenced by: '<S601>/volc_b_VCU_CabinLoopVal1_FBV6_ovrdflg' */

/* Override flag for signal b_VCU_CabinLoopVal1_FBV6 */
const volatile boolean volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg = false;
             /* Referenced by: '<S602>/volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg' */

/* Override flag for signal b_VCU_CabinLoopVal2_FBV5 */
const volatile boolean volc_b_VCU_Cabin_PumpFb_ovrdflg = false;
                   /* Referenced by: '<S586>/volc_b_VCU_Cabin_PumpFb_ovrdflg' */

/* Override flag for signal b_VCU_Cabin_PumpFb */
const volatile boolean volc_b_VCU_CalNum_ovrdflg = false;
                         /* Referenced by: '<S862>/volc_b_VCU_CalNum_ovrdflg' */

/* Override flag for signal VCU_CalNum */
const volatile boolean volc_b_VCU_CalibrationMajorVer1_ovrdflg = false;
                 /* Referenced by: '<S691>/volc_flg_VCU_SWCompileDay_ovrdflg' */
const volatile boolean volc_b_VCU_CalibrationMajorVer2_ovrdflg = false;
                 /* Referenced by: '<S692>/volc_flg_VCU_SWCompileDay_ovrdflg' */
const volatile boolean volc_b_VCU_CalibrationMajorVer3_ovrdflg = false;
                 /* Referenced by: '<S693>/volc_flg_VCU_SWCompileDay_ovrdflg' */
const volatile boolean volc_b_VCU_CalibrationMinorVer1_ovrdflg = false;
                 /* Referenced by: '<S694>/volc_flg_VCU_SWCompileDay_ovrdflg' */
const volatile boolean volc_b_VCU_CalibrationMinorVer2_ovrdflg = false;
                 /* Referenced by: '<S695>/volc_flg_VCU_SWCompileDay_ovrdflg' */
const volatile boolean volc_b_VCU_CalibrationMinorVer3_ovrdflg = false;
                 /* Referenced by: '<S696>/volc_flg_VCU_SWCompileDay_ovrdflg' */
const volatile boolean volc_b_VCU_Cell_Avg_Temp_ovrdflg = false;
                /* Referenced by: '<S344>/volc_flg_VCU_Cell_Avg_Temp_ovrdflg' */

/* Override flag for signal VCU_Cell_Avg_Temp */
const volatile boolean volc_b_VCU_ChargWakeupSts_ovrdflg = false;
                 /* Referenced by: '<S587>/volc_b_VCU_ChargWakeupSts_ovrdflg' */

/* Override flag for signal b_VCU_ChargWakeupSts */
const volatile boolean volc_b_VCU_ChargeDepthReq_ovrdflg = false;
              /* Referenced by: '<S400>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_Charger_Connected_ovrdflg = false;
            /* Referenced by: '<S345>/volc_flg_VCU_Charger_Connected_ovrdflg' */

/* Override flag for signal VCU_Charger_Connected */
const volatile boolean volc_b_VCU_ControlSetSpeed_Mode_ovrdflg = false;
         /* Referenced by: '<S476>/volc_flg_VCU_ControlSetSpeed_Mode_ovrdflg' */

/* Override flag for signal VCU_ControlSetSpeed_Mode */
const volatile boolean volc_b_VCU_ControlSetSpeed_ovrdflg = false;
              /* Referenced by: '<S475>/volc_flg_VCU_ControlSetSpeed_ovrdflg' */

/* Override flag for signal VCU_ControlSetSpeed */
const volatile boolean volc_b_VCU_Cooling_Control_Request_ovrdflg = false;
      /* Referenced by: '<S346>/volc_flg_VCU_Cooling_Control_Request_ovrdflg' */

/* Override flag for signal VCU_Cooling_Control_Request */
const volatile boolean volc_b_VCU_CrashOutputSts_ovrdflg = false;
               /* Referenced by: '<S782>/volc_flg_VCU_CrashOutputSts_ovrdflg' */
const volatile boolean volc_b_VCU_CruiseControlSts_ovrdflg = false;
               /* Referenced by: '<S477>/volc_b_VCU_CruiseControlSts_ovrdflg' */

/* Override flag for signal VCU_CruiseControlSts */
const volatile boolean volc_b_VCU_CruiseSwSts_ovrdflg = false;
                  /* Referenced by: '<S478>/volc_flg_VCU_CruiseSwSts_ovrdflg' */

/* Override flag for signal VCU_CruiseSwSts */
const volatile boolean volc_b_VCU_CruiseSwerrorSts_ovrdflg = false;
               /* Referenced by: '<S479>/volc_b_VCU_CruiseSwerrorSts_ovrdflg' */

/* Override flag for signal VCU_CruiseSwerrorSts */
const volatile boolean volc_b_VCU_DCDCPwrLmt_ovrdflg = false;
                   /* Referenced by: '<S540>/volc_flg_VCU_DCDCPwrLmt_ovrdflg' */

/* Override flag for signal b_VCU_DCDCPwrLmt */
const volatile boolean volc_b_VCU_DCDC_WorkSts_ovrdflg = false;
                 /* Referenced by: '<S641>/volc_flg_VCU_DCDC_WorkSts_ovrdflg' */

/* Override flag for signal VCU_DCDC_WorkSts */
const volatile boolean volc_b_VCU_DTE_ovrdflg = false;
                          /* Referenced by: '<S528>/volc_flg_VCU_DTE_ovrdflg' */

/* Override flag for signal b_VCU_DTE */
const volatile boolean volc_b_VCU_DischargeEnable_ovrdflg = false;
              /* Referenced by: '<S397>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_DriveCircuitTemp_ovrdflg = false;
               /* Referenced by: '<S392>/volc_b_VCU_DriveCircuitTemp_ovrdflg' */

/* Override flag for signal b_VCU_DriveCircuitTemp */
const volatile boolean volc_b_VCU_DriveCircuitVol_ovrdflg = false;
                /* Referenced by: '<S603>/volc_b_VCU_DriveCircuitVol_ovrdflg' */

/* Override flag for signal b_VCU_DriveCircuitVol */
const volatile boolean volc_b_VCU_DriveModeInd_ovrdflg = false;
                 /* Referenced by: '<S642>/volc_flg_VCU_DriveModeInd_ovrdflg' */

/* Override flag for signal b_VCU_DriveModeInd */
const volatile boolean volc_b_VCU_DrivePwrCircuitInd_ovrdflg = false;
           /* Referenced by: '<S643>/volc_flg_VCU_DrivePwrCircuitInd_ovrdflg' */

/* Override flag for signal b_VCU_DrivePwrCircuitInd */
const volatile boolean volc_b_VCU_DriveReqTrqPercent_ovrdflg = false;
             /* Referenced by: '<S488>/volc_b_VCU_DriveReqTrqPercent_ovrdflg' */

/* Override flag for signal VCU_DriveReqTrqPercent */
const volatile boolean volc_b_VCU_DriverOperationReminder_ovrdflg = false;
      /* Referenced by: '<S458>/volc_flg_VCU_DriverOperationReminder_ovrdflg' */

/* Override flag for signal b_VCU_DriverOperationReminder */
const volatile boolean volc_b_VCU_DrivingTakeForceSts_ovrdflg = false;
            /* Referenced by: '<S871>/volc_b_VCU_DrivingTakeForceSts_ovrdflg' */

/* Override flag for signal VCU_DrivingTakeForceSts */
const volatile boolean volc_b_VCU_ECOMode_invert = false;
                         /* Referenced by: '<S570>/volc_b_VCU_ECOMode_invert' */

/* Invert flag for signal b_VCU_ECOMode */
const volatile boolean volc_b_VCU_ECOMode_ovrdflg = false;
                        /* Referenced by: '<S570>/volc_b_VCU_ECOMode_ovrdflg' */

/* Override flag for signal b_VCU_ECOMode */
const volatile boolean volc_b_VCU_ECOmodeSWILED_Ctrl_ovrdflg = false;
             /* Referenced by: '<S272>/volc_b_VCU_ECOmodeSWILED_Ctrl_ovrdflg' */

/* Override flag for signal VCU_ECOmodeSWILED_Ctrl */
const volatile boolean volc_b_VCU_ECPM_FaultFB_ovrdflg = false;
                   /* Referenced by: '<S273>/volc_b_VCU_ECPM_FaultFB_ovrdflg' */

/* Override flag for signal VCU_ECPM_FaultFB */
const volatile boolean volc_b_VCU_EDCP_Enable_invert = false;
                     /* Referenced by: '<S875>/volc_b_VCU_HVBC_Enable_invert' */

/* Invert flag for signal VCU_EDCP_Enable */
const volatile boolean volc_b_VCU_EDCP_Enable_ovrdflg = false;
                    /* Referenced by: '<S875>/volc_b_VCU_HVBC_Enable_ovrdflg' */

/* Override flag for signal VCU_EDCP_Enable */
const volatile boolean volc_b_VCU_EDCP_FaultFB_ovrdflg = false;
                   /* Referenced by: '<S274>/volc_b_VCU_EDCP_FaultFB_ovrdflg' */

/* Override flag for signal VCU_EDCP_FaultFB */
const volatile boolean volc_b_VCU_EDCP_PWMCtrl_ovrdflg = false;
                /* Referenced by: '<S876>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_EDCP_PWMCtrl */
const volatile boolean volc_b_VCU_EM1CtrlMode_ovrdflg = false;
                    /* Referenced by: '<S489>/volc_b_VCU_EM1CtrlMode_ovrdflg' */
const volatile boolean volc_b_VCU_EM1WorkMode_ovrdflg = false;
                    /* Referenced by: '<S490>/volc_b_VCU_EM1WorkMode_ovrdflg' */
const volatile boolean volc_b_VCU_EMCtrlMode_ovrdflg = false;
                   /* Referenced by: '<S491>/volc_flg_VCU_EMCtrlMode_ovrdflg' */

/* Override flag for signal b_VCU_EMCtrlMode */
const volatile boolean volc_b_VCU_EMWorkMode_ovrdflg = false;
                   /* Referenced by: '<S492>/volc_flg_VCU_EMWorkMode_ovrdflg' */

/* Override flag for signal b_VCU_EMWorkMode */
const volatile boolean volc_b_VCU_EManualStartSwi_ovrdflg = false;
                /* Referenced by: '<S588>/volc_b_VCU_EManualStartSwi_ovrdflg' */

/* Override flag for signal b_VCU_EManualStartSwi */
const volatile boolean volc_b_VCU_EVDTEodometer_ovrdflg = false;
                  /* Referenced by: '<S275>/volc_b_VCU_EVDTEodometer_ovrdflg' */

/* Override flag for signal VCU_EVDTEodometer */
const volatile boolean volc_b_VCU_EV_Switch_ovrdflg = false;
              /* Referenced by: '<S680>/volc_b_VCU_BattHeatVal2_FBV6_ovrdflg' */

/* Override flag for signal VCU_EV_Switch */
const volatile boolean volc_b_VCU_EVanualStartSwi_ovrdflg = false;
                /* Referenced by: '<S644>/volc_b_VCU_EVanualStartSwi_ovrdflg' */

/* Override flag for signal VCU_EVanualStartSwi */
const volatile boolean volc_b_VCU_EmergencyStop_ovrdflg = false;
                  /* Referenced by: '<S594>/volc_b_VCU_EmergencyStop_ovrdflg' */

/* Override flag for signal b_VCU_EmergencyStop */
const volatile boolean volc_b_VCU_EngFuelInstCons_ovrdflg = false;
                /* Referenced by: '<S347>/volc_b_VCU_EngFuelInstCons_ovrdflg' */

/* Override flag for signal VCU_EngFuelInstCons */
const volatile boolean volc_b_VCU_ErrCode_ovrdflg = false;
                      /* Referenced by: '<S529>/volc_flg_VCU_ErrCode_ovrdflg' */

/* Override flag for signal b_VCU_ErrCode */
const volatile boolean volc_b_VCU_ExternalAccDemand_ovrdflg = false;
            /* Referenced by: '<S315>/volc_flg_VCU_ExternalAccDemand_ovrdflg' */

/* Override flag for signal VCU_ExternalAccDemand */
const volatile boolean volc_b_VCU_FanPWM_Ctrl_ovrdflg = false;
               /* Referenced by: '<S681>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg' */

/* Override flag for signal VCU_FanPWM_Ctrl */
const volatile boolean volc_b_VCU_FuleDTEodometer_ovrdflg = false;
                /* Referenced by: '<S276>/volc_b_VCU_FuleDTEodometer_ovrdflg' */

/* Override flag for signal VCU_FuleDTEodometer */
const volatile boolean volc_b_VCU_FunAnti_DismantleActive_ovrdflg = false;
        /* Referenced by: '<S604>/volc_b_VCU_FunAnti_DismantleActive_ovrdflg' */

/* Override flag for signal VCU_FunAnti_DismantleActive */
const volatile boolean volc_b_VCU_FunLockVehActive_ovrdflg = false;
               /* Referenced by: '<S605>/volc_b_VCU_FunLockVehActive_ovrdflg' */

/* Override flag for signal VCU_FunLockVehActive */
const volatile boolean volc_b_VCU_GP_Override_ovrdflg = false;
                    /* Referenced by: '<S316>/volc_b_VCU_GP_Override_ovrdflg' */

/* Override flag for signal VCU_GP_Override */
const volatile boolean volc_b_VCU_GearOperateErr_ovrdflg = false;
               /* Referenced by: '<S645>/volc_flg_VCU_GearOperateErr_ovrdflg' */

/* Override flag for signal b_VCU_GearOperateErr */
const volatile boolean volc_b_VCU_GearPositionInd_ovrdflg = false;
              /* Referenced by: '<S646>/volc_flg_VCU_GearPositionInd_ovrdflg' */

/* Override flag for signal b_VCU_GearPositionInd */
const volatile boolean volc_b_VCU_GearPositionInput_ovrdflg = false;
              /* Referenced by: '<S595>/volc_b_VCU_GearPositionInput_ovrdflg' */

/* Override flag for signal b_VCU_GearPositionInput */
const volatile boolean volc_b_VCU_Gearshift_Resp_ovrdflg = false;
                 /* Referenced by: '<S872>/volc_b_VCU_Gearshift_Resp_ovrdflg' */

/* Override flag for signal VCU_Gearshift_Resp */
const volatile boolean volc_b_VCU_HBCP_Enable_invert = false;
                      /* Referenced by: '<S877>/volc_b_VCU_ICE_Enable_invert' */

/* Invert flag for signal VCU_HBCP_Enable */
const volatile boolean volc_b_VCU_HBCP_Enable_ovrdflg = false;
                     /* Referenced by: '<S877>/volc_b_VCU_ICE_Enable_ovrdflg' */

/* Override flag for signal VCU_HBCP_Enable */
const volatile boolean volc_b_VCU_HBCP_FaultFB_ovrdflg = false;
                   /* Referenced by: '<S277>/volc_b_VCU_HBCP_FaultFB_ovrdflg' */

/* Override flag for signal VCU_HBCP_FaultFB */
const volatile boolean volc_b_VCU_HBCP_PWMCtrl_ovrdflg = false;
                /* Referenced by: '<S878>/volc_b_VCU_HVBC_BOpenValue_ovrdflg' */

/* Override flag for signal VCU_HBCP_PWMCtrl */
const volatile boolean volc_b_VCU_HTCoolingFan1FB_ovrdflg = false;
                /* Referenced by: '<S278>/volc_b_VCU_HTCoolingFan1FB_ovrdflg' */

/* Override flag for signal VCU_HTCoolingFan1FB */
const volatile boolean volc_b_VCU_HVB_PumpFb_ovrdflg = false;
                     /* Referenced by: '<S589>/volc_b_VCU_HVB_PumpFb_ovrdflg' */

/* Override flag for signal b_VCU_HVB_PumpFb */
const volatile boolean volc_b_VCU_HVILReturn_ovrdflg = false;
                     /* Referenced by: '<S596>/volc_b_VCU_HVILReturn_ovrdflg' */

/* Override flag for signal b_VCU_HVILReturn */
const volatile boolean volc_b_VCU_HVOnOffReq_ovrdflg = false;
                   /* Referenced by: '<S348>/volc_flg_VCU_HVOnOffReq_ovrdflg' */

/* Override flag for signal VCU_HVOnOffReq */
const volatile boolean volc_b_VCU_HVPRASts_ovrdflg = false;
                     /* Referenced by: '<S571>/volc_b_VCU_ACC2PosVol_ovrdflg' */

/* Override flag for signal VCU_HVBVarCtrl */
const volatile boolean volc_b_VCU_HV_Status_ovrdflg = false;
                      /* Referenced by: '<S279>/volc_b_VCU_HV_Status_ovrdflg' */

/* Override flag for signal VCU_HV_Status */
const volatile boolean volc_b_VCU_HandbrakeSts2_ovrdflg = false;
                /* Referenced by: '<S459>/volc_flg_VCU_HandbrakeSts2_ovrdflg' */

/* Override flag for signal b_VCU_HandbrakeSts2 */
const volatile boolean volc_b_VCU_HandbrakeSts_ovrdflg = false;
                 /* Referenced by: '<S647>/volc_flg_VCU_HandbrakeSts_ovrdflg' */

/* Override flag for signal b_VCU_HandbrakeSts */
const volatile boolean volc_b_VCU_HardwareMajorVer_ovrdflg = false;
             /* Referenced by: '<S697>/volc_flg_VCU_HardwareMajorVer_ovrdflg' */

/* Override flag for signal b_VCU_HardwareMajorVer */
const volatile boolean volc_b_VCU_HardwareMinorVer_ovrdflg = false;
             /* Referenced by: '<S698>/volc_flg_VCU_HardwareMinorVer_ovrdflg' */

/* Override flag for signal b_VCU_HardwareMinorVer */
const volatile boolean volc_b_VCU_HazardReq_ovrdflg = false;
                      /* Referenced by: '<S541>/volc_b_VCU_HazardReq_ovrdflg' */

/* Override flag for signal VCU_HazardReq */
const volatile boolean volc_b_VCU_HazardReq_ovrdval = false;
                      /* Referenced by: '<S541>/volc_b_VCU_HazardReq_ovrdval' */

/* Override value for signal VCU_HazardReq */
const volatile boolean volc_b_VCU_HybridReady_ovrdflg = false;
                    /* Referenced by: '<S349>/volc_b_VCU_HybridReady_ovrdflg' */

/* Override flag for signal VCU_HybridReady */
const volatile boolean volc_b_VCU_Idle_Switch_ovrdflg = false;
              /* Referenced by: '<S682>/volc_b_VCU_BattCoolVal3_FBV5_ovrdflg' */

/* Override flag for signal VCU_Idle_Switch */
const volatile boolean volc_b_VCU_IgnONSts_invert = false;
                        /* Referenced by: '<S572>/volc_b_VCU_IgnONSts_invert' */

/* Invert flag for signal b_VCU_IgnONSts */
const volatile boolean volc_b_VCU_IgnONSts_ovrdflg = false;
                       /* Referenced by: '<S572>/volc_b_VCU_IgnONSts_ovrdflg' */

/* Override flag for signal b_VCU_IgnONSts */
const volatile boolean volc_b_VCU_IgniteSts_ovrdflg = false;
                    /* Referenced by: '<S648>/volc_flg_VCU_IgniteSts_ovrdflg' */

/* Override flag for signal b_VCU_IgniteSts */
const volatile boolean volc_b_VCU_InhibitHybrid_Switch_ovrdflg = false;
              /* Referenced by: '<S683>/volc_b_VCU_BattHeatVal2_FBV5_ovrdflg' */

/* Override flag for signal VCU_InhibitHybrid_Switch */
const volatile boolean volc_b_VCU_IntelLockLoopSts_ovrdflg = false;
               /* Referenced by: '<S542>/volc_b_VCU_IntelLockLoopSts_ovrdflg' */

/* Override flag for signal VCU_IntelLockLoopSts */
const volatile boolean volc_b_VCU_IntelligentChargeExitReq_ovrdflg = false;
       /* Referenced by: '<S280>/volc_b_VCU_IntelligentChargeExitReq_ovrdflg' */

/* Override flag for signal VCU_IntelligentChargeExitReq */
const volatile boolean volc_b_VCU_IntelligentChargeQuit_ovrdflg = false;
          /* Referenced by: '<S281>/volc_b_VCU_IntelligentChargeQuit_ovrdflg' */

/* Override flag for signal VCU_IntelligentChargeQuit */
const volatile boolean volc_b_VCU_IntelligentChargeState_ovrdflg = false;
         /* Referenced by: '<S282>/volc_b_VCU_IntelligentChargeState_ovrdflg' */

/* Override flag for signal VCU_IntelligentChargeState */
const volatile boolean volc_b_VCU_LTCoolingFan2FB_ovrdflg = false;
                /* Referenced by: '<S283>/volc_b_VCU_LTCoolingFan2FB_ovrdflg' */

/* Override flag for signal VCU_LTCoolingFan2FB */
const volatile boolean volc_b_VCU_LockLimResult_ovrdflg = false;
                  /* Referenced by: '<S606>/volc_b_VCU_LockLimResult_ovrdflg' */

/* Override flag for signal VCU_LockLimResult */
const volatile boolean volc_b_VCU_LockVehSts_ovrdflg = false;
                     /* Referenced by: '<S607>/volc_b_VCU_LockVehSts_ovrdflg' */

/* Override flag for signal VCU_LockVehSts */
const volatile boolean volc_b_VCU_LockVehType_ovrdflg = false;
                    /* Referenced by: '<S608>/volc_b_VCU_LockVehType_ovrdflg' */

/* Override flag for signal VCU_LockVehType */
const volatile boolean volc_b_VCU_MCU1EnableReq_ovrdflg = false;
                /* Referenced by: '<S493>/volc_flg_VCU_MCU1EnableReq_ovrdflg' */
const volatile boolean volc_b_VCU_MCUActiveDischg_ovrdflg = false;
              /* Referenced by: '<S350>/volc_flg_VCU_MCUActiveDischg_ovrdflg' */

/* Override flag for signal VCU_MCUActiveDischg */
const volatile boolean volc_b_VCU_MCUEnableReq_ovrdflg = false;
                 /* Referenced by: '<S494>/volc_flg_VCU_MCUEnableReq_ovrdflg' */

/* Override flag for signal b_VCU_MCUEnableReq */
const volatile boolean volc_b_VCU_MCUMaxTrq_ovrdflg = false;
                      /* Referenced by: '<S495>/volc_b_VCU_MCUMaxTrq_ovrdflg' */

/* Override flag for signal VCU_MCUMaxTrq */
const volatile boolean volc_b_VCU_MCUSpdRampRate_ovrdflg = false;
               /* Referenced by: '<S496>/volc_flg_VCU_MCUSpdRampRate_ovrdflg' */

/* Override flag for signal VCU_MCUSpdRampRate */
const volatile boolean volc_b_VCU_MCUTqRampRate_ovrdflg = false;
                /* Referenced by: '<S497>/volc_flg_VCU_MCUTqRampRate_ovrdflg' */

/* Override flag for signal VCU_MCUTqRampRate */
const volatile boolean volc_b_VCU_MCU_MotorActTrqPercent_ovrdflg = false;
         /* Referenced by: '<S498>/volc_b_VCU_MCU_MotorActTrqPercent_ovrdflg' */

/* Override flag for signal VCU_MCU_MotorActTrqPercent */
const volatile boolean volc_b_VCU_MCU_PumpPWM_Ctrl_ovrdflg = false;
             /* Referenced by: '<S684>/volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg' */

/* Override flag for signal VCU_MCU_PumpPWM_Ctrl */
const volatile boolean volc_b_VCU_MCU_RelayCtrl_Ctrl_ovrdflg = false;
               /* Referenced by: '<S685>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg' */

/* Override flag for signal VCU_MCU_RelayCtrl_Ctrl */
const volatile boolean volc_b_VCU_MILTelltale_ovrdflg = false;
                    /* Referenced by: '<S628>/volc_b_VCU_MILTelltale_ovrdflg' */

/* Override flag for signal VCU_MILTelltale */
const volatile boolean volc_b_VCU_MainPosCtrlCommand_ovrdflg = false;
           /* Referenced by: '<S543>/volc_flg_VCU_MainPosCtrlCommand_ovrdflg' */

/* Override flag for signal b_VCU_MainPosCtrlCommand */
const volatile boolean volc_b_VCU_Main_Contactor_Control_ovrdflg = false;
       /* Referenced by: '<S351>/volc_flg_VCU_Main_Contactor_Control_ovrdflg' */

/* Override flag for signal VCU_Main_Contactor_Control */
const volatile boolean volc_b_VCU_MaxEMPwrLmt_ovrdflg = false;
                  /* Referenced by: '<S499>/volc_flg_VCU_MaxEMPwrLmt_ovrdflg' */

/* Override flag for signal b_VCU_MaxEMPwrLmt */
const volatile boolean volc_b_VCU_MinEMPwrLmt_ovrdflg = false;
                  /* Referenced by: '<S500>/volc_flg_VCU_MinEMPwrLmt_ovrdflg' */

/* Override flag for signal b_VCU_MinEMPwrLmt */
const volatile boolean volc_b_VCU_MotorSpeed_ovrdflg = false;
                   /* Referenced by: '<S501>/volc_flg_VCU_MotorSpeed_ovrdflg' */

/* Override flag for signal VCU_MotorSpeed */
const volatile boolean volc_b_VCU_MotorTorque_ovrdflg = false;
                  /* Referenced by: '<S502>/volc_flg_VCU_MotorTorque_ovrdflg' */

/* Override flag for signal VCU_MotorTorque */
const volatile boolean volc_b_VCU_NMSts_ovrdflg = false;
                /* Referenced by: '<S616>/volc_b_VCU_DTCClearInhibit_ovrdflg' */

/* Override flag for signal VCU_NMSts */
const volatile boolean volc_b_VCU_Oil_HV_OFF_ovrdflg = false;
                /* Referenced by: '<S870>/volc_b_VCU_HVBC_COpenValue_ovrdflg' */

/* Override flag for signal VCU_Oil_HV_OFF */
const volatile boolean volc_b_VCU_OverloadInd_ovrdflg = false;
                    /* Referenced by: '<S863>/volc_b_VCU_OverloadInd_ovrdflg' */

/* Override flag for signal VCU_OverloadInd */
const volatile boolean volc_b_VCU_PMS_APPowerActual_EV_ovrdflg = false;
         /* Referenced by: '<S413>/volc_flg_VCU_PMS_APPowerActual_EV_ovrdflg' */
const volatile boolean volc_b_VCU_PTC2Enable_ovrdflg = false;
              /* Referenced by: '<S394>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_PTC3Enable_ovrdflg = false;
              /* Referenced by: '<S395>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_PTCEnable_ovrdflg = false;
                      /* Referenced by: '<S414>/volc_b_VCU_PTCEnable_ovrdflg' */

/* Override flag for signal PTCEnable */
const volatile boolean volc_b_VCU_PTHVSysErrorLampStsInd_ovrdflg = false;
       /* Referenced by: '<S649>/volc_flg_VCU_PTHVSysErrorLampStsInd_ovrdflg' */

/* Override flag for signal b_VCU_PTHVSysErrorLampStsInd */
const volatile boolean volc_b_VCU_PTModeInd_ovrdflg = false;
                    /* Referenced by: '<S650>/volc_flg_VCU_PTModeInd_ovrdflg' */

/* Override flag for signal b_VCU_PTModeInd */
const volatile boolean volc_b_VCU_PTReadyInd_ovrdflg = false;
                   /* Referenced by: '<S651>/volc_flg_VCU_PTReadyInd_ovrdflg' */

/* Override flag for signal b_VCU_PTReadyInd */
const volatile boolean volc_b_VCU_PTResiPwr_ovrdflg = false;
                      /* Referenced by: '<S530>/volc_b_VCU_PTResiPwr_ovrdflg' */

/* Override flag for signal VCU_PTResiPwr */
const volatile boolean volc_b_VCU_PTSysElecPwrInd_ovrdflg = false;
              /* Referenced by: '<S652>/volc_flg_VCU_PTSysElecPwrInd_ovrdflg' */

/* Override flag for signal b_VCU_PTSysElecPwrInd */
const volatile boolean volc_b_VCU_PreRelay_Ctrl_ovrdflg = false;
              /* Referenced by: '<S686>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */

/* Override flag for signal VCU_PreRelay_Ctrl */
const volatile boolean volc_b_VCU_PressureSwi1Sts_ovrdflg = false;
                /* Referenced by: '<S590>/volc_b_VCU_PressureSwi1Sts_ovrdflg' */

/* Override flag for signal b_VCU_PressureSwi1Sts */
const volatile boolean volc_b_VCU_PressureSwi2Sts_ovrdflg = false;
                /* Referenced by: '<S591>/volc_b_VCU_PressureSwi2Sts_ovrdflg' */

/* Override flag for signal b_VCU_PressureSwi2Sts */
const volatile boolean volc_b_VCU_PropulSysActive_ovrdflg = false;
                /* Referenced by: '<S284>/volc_b_VCU_PropulSysActive_ovrdflg' */

/* Override flag for signal VCU_PropulSysActive */
const volatile boolean volc_b_VCU_QuitControlSpeed_ovrdflg = false;
             /* Referenced by: '<S480>/volc_flg_VCU_QuitControlSpeed_ovrdflg' */

/* Override flag for signal VCU_QuitControlSpeed */
const volatile boolean volc_b_VCU_RMR_ovrdflg = false;
                /* Referenced by: '<S617>/volc_flg_VCU_AccePedalPosD_ovrdflg' */

/* Override flag for signal VCU_RMR */
const volatile boolean volc_b_VCU_RelayCtrl_Ctrl_ovrdflg = false;
               /* Referenced by: '<S687>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg' */

/* Override flag for signal VCU_RelayCtrl_Ctrl */
const volatile boolean volc_b_VCU_ReqSpdOrLmt_ovrdflg = false;
                  /* Referenced by: '<S503>/volc_flg_VCU_ReqSpdOrLmt_ovrdflg' */

/* Override flag for signal b_VCU_ReqSpdOrLmt */
const volatile boolean volc_b_VCU_ReqTrqOrLmt_ovrdflg = false;
                  /* Referenced by: '<S504>/volc_flg_VCU_ReqTrqOrLmt_ovrdflg' */

/* Override flag for signal b_VCU_ReqTrqOrLmt */
const volatile boolean volc_b_VCU_SDCACOutFreq_ovrdflg = false;
                 /* Referenced by: '<S544>/volc_flg_VCU_SDCACOutFreq_ovrdflg' */

/* Override flag for signal b_VCU_SDCACOutFreq */
const volatile boolean volc_b_VCU_SDCACStopFault_ovrdflg = false;
                 /* Referenced by: '<S545>/volc_b_VCU_SDCACStopFault_ovrdflg' */

/* Override flag for signal VCU_SDCACStopFault */
const volatile boolean volc_b_VCU_SDCACStopFault_ovrdval = false;
                 /* Referenced by: '<S545>/volc_b_VCU_SDCACStopFault_ovrdval' */

/* Override value for signal VCU_SDCACStopFault */
const volatile boolean volc_b_VCU_SWCompileDay_ovrdflg = false;
                 /* Referenced by: '<S699>/volc_flg_VCU_SWCompileDay_ovrdflg' */

/* Override flag for signal b_VCU_SWCompileDay */
const volatile boolean volc_b_VCU_SWCompileMonth_ovrdflg = false;
               /* Referenced by: '<S700>/volc_flg_VCU_SWCompileMonth_ovrdflg' */

/* Override flag for signal b_VCU_SWCompileMonth */
const volatile boolean volc_b_VCU_SWCompileYear_ovrdflg = false;
                /* Referenced by: '<S701>/volc_flg_VCU_SWCompileYear_ovrdflg' */

/* Override flag for signal b_VCU_SWCompileYear */
const volatile boolean volc_b_VCU_SelfCheckSts_ovrdflg = false;
                 /* Referenced by: '<S546>/volc_flg_VCU_SelfCheckSts_ovrdflg' */

/* Override flag for signal b_VCU_SelfCheckSts */
const volatile boolean volc_b_VCU_Set_Temp_ovrdflg = false;
                     /* Referenced by: '<S352>/volc_flg_VCU_Set_Temp_ovrdflg' */

/* Override flag for signal VCU_Set_Temp */
const volatile boolean volc_b_VCU_ShiftClimbing_invert = false;
                         /* Referenced by: '<S573>/volc_b_VCU_ECOMode_invert' */

/* Invert flag for signal VCU_ShiftClimbing */
const volatile boolean volc_b_VCU_ShiftClimbing_ovrdflg = false;
                        /* Referenced by: '<S573>/volc_b_VCU_ECOMode_ovrdflg' */

/* Override flag for signal VCU_ShiftClimbing */
const volatile boolean volc_b_VCU_ShiftD_invert = false;
                        /* Referenced by: '<S574>/volc_b_VCU_StartSts_invert' */

/* Invert flag for signal VCU_ShiftD */
const volatile boolean volc_b_VCU_ShiftD_ovrdflg = false;
                       /* Referenced by: '<S574>/volc_b_VCU_StartSts_ovrdflg' */

/* Override flag for signal VCU_ShiftD */
const volatile boolean volc_b_VCU_ShiftR_invert = false;
                        /* Referenced by: '<S575>/volc_b_VCU_StartSts_invert' */

/* Invert flag for signal VCU_ShiftR */
const volatile boolean volc_b_VCU_ShiftR_ovrdflg = false;
                       /* Referenced by: '<S575>/volc_b_VCU_StartSts_ovrdflg' */

/* Override flag for signal VCU_ShiftR */
const volatile boolean volc_b_VCU_SoftwareMajorVer_ovrdflg = false;
             /* Referenced by: '<S702>/volc_flg_VCU_SoftwareMajorVer_ovrdflg' */

/* Override flag for signal b_VCU_SoftwareMajorVer */
const volatile boolean volc_b_VCU_SoftwareMinorVer_ovrdflg = false;
             /* Referenced by: '<S703>/volc_flg_VCU_SoftwareMinorVer_ovrdflg' */

/* Override flag for signal b_VCU_SoftwareMinorVer */
const volatile boolean volc_b_VCU_StartSts_invert = false;
                        /* Referenced by: '<S576>/volc_b_VCU_StartSts_invert' */

/* Invert flag for signal b_VCU_StartSts */
const volatile boolean volc_b_VCU_StartSts_ovrdflg = false;
                       /* Referenced by: '<S576>/volc_b_VCU_StartSts_ovrdflg' */

/* Override flag for signal b_VCU_StartSts */
const volatile boolean volc_b_VCU_Stayawake_reasons_ovrdflg = false;
                /* Referenced by: '<S618>/volc_flg_VCU_AccePedalPosE_ovrdflg' */

/* Override flag for signal VCU_Stayawake_reasons */
const volatile boolean volc_b_VCU_StsBrkSwitch1Invalid_ovrdflg = false;
         /* Referenced by: '<S460>/volc_flg_VCU_StsBrkSwitch1Invalid_ovrdflg' */
const volatile boolean volc_b_VCU_TotalOdometerInvalid_ovrdflg = false;
           /* Referenced by: '<S630>/volc_b_VCU_TotalOdometerInvalid_ovrdflg' */

/* Override flag for signal VCU_TotalOdometerInvalid */
const volatile boolean volc_b_VCU_TotalOdometer_ovrdflg = false;
                  /* Referenced by: '<S629>/volc_b_VCU_TotalOdometer_ovrdflg' */

/* Override flag for signal VCU_TotalOdometer */
const volatile boolean volc_b_VCU_TurtleLampReq_ovrdflg = false;
                /* Referenced by: '<S653>/volc_flg_VCU_TurtleLampReq_ovrdflg' */

/* Override flag for signal b_VCU_TurtleLampReq */
const volatile boolean volc_b_VCU_VLC_Active_ovrdflg = false;
                     /* Referenced by: '<S317>/volc_b_VCU_VLC_Active_ovrdflg' */

/* Override flag for signal VCU_VLC_Active */
const volatile boolean volc_b_VCU_VLC_Available_ovrdflg = false;
                  /* Referenced by: '<S318>/volc_b_VCU_VLC_Available_ovrdflg' */

/* Override flag for signal VCU_VLC_Available */
const volatile boolean volc_b_VCU_VLC_InternalTargetACCeleration_ovrdflg = false;
/* Referenced by: '<S319>/volc_b_VCU_VLC_InternalTargetACCeleration_ovrdflg' */

/* Override flag for signal VCU_VLC_InternalTargetACCeleration */
const volatile boolean volc_b_VCU_VLC_VCUTargetACCeleration_ovrdflg = false;
      /* Referenced by: '<S320>/volc_b_VCU_VLC_VCUTargetACCeleration_ovrdflg' */

/* Override flag for signal VCU_VLC_VCUTargetACCeleration */
const volatile boolean volc_b_VCU_VehCruisingDistance_ovrdflg = false;
              /* Referenced by: '<S688>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */

/* Override flag for signal VCU_VehCruisingDistance */
const volatile boolean volc_b_VCU_VehicleAbnormalSts_ovrdflg = false;
           /* Referenced by: '<S654>/volc_flg_VCU_VehicleAbnormalSts_ovrdflg' */

/* Override flag for signal b_VCU_VehicleAbnormalSts */
const volatile boolean volc_b_VCU_VehicleIdentification_ovrdflg = false;
        /* Referenced by: '<S689>/volc_flg_VCU_VehicleIdentification_ovrdflg' */

/* Override flag for signal b_VCU_VehicleIdentification */
const volatile boolean volc_b_VCU_VehicleRunMode_ovrdflg = false;
               /* Referenced by: '<S655>/volc_flg_VCU_VehicleRunMode_ovrdflg' */

/* Override flag for signal b_VCU_VehicleRunMode */
const volatile boolean volc_b_VCU_VehicleSlipWarning_ovrdflg = false;
                   /* Referenced by: '<S656>/volc_flg_VCU_VehicleSlipWarning' */

/* Override flag for signal b_VCU_VehicleSlipWarning */
const volatile boolean volc_b_VCU_VehicleSpd_flag_ovrdflg = false;
              /* Referenced by: '<S462>/volc_flg_VCU_VehicleSpd_flag_ovrdflg' */

/* Override flag for signal VCU_VehicleSpd_flag */
const volatile boolean volc_b_VCU_VehicleSpd_ovrdflg = false;
                   /* Referenced by: '<S461>/volc_flg_VCU_VehicleSpd_ovrdflg' */

/* Override flag for signal b_VCU_VehicleSpd */
const volatile boolean volc_b_VCU_VehicleSubSysErrorLevel_ovrdflg = false;
        /* Referenced by: '<S657>/volc_b_VCU_VehicleSubSysErrorLevel_ovrdflg' */

/* Override flag for signal VCU_VehicleSubSysErrorLevel */
const volatile boolean volc_b_VCU_VehicleSysErrorLevel_ovrdflg = false;
         /* Referenced by: '<S658>/volc_flg_VCU_VehicleSysErrorLevel_ovrdflg' */

/* Override flag for signal b_VCU_VehicleSysErrorLevel */
const volatile boolean volc_b_VCU_VehicleSysFltLevel_ovrdflg = false;
           /* Referenced by: '<S636>/volc_flg_VCU_VehicleSysFltLevel_ovrdflg' */

/* Override flag for signal b_VCU_VehicleSysFltLevel */
const volatile boolean volc_b_VCU_VehicleWeight_ovrdflg = false;
                  /* Referenced by: '<S864>/volc_b_VCU_VehicleWeight_ovrdflg' */

/* Override flag for signal VCU_VehicleWeight */
const volatile boolean volc_b_VCU_WPCtrl_ovrdflg = false;
                         /* Referenced by: '<S415>/volc_b_VCU_WPCtrl_ovrdflg' */

/* Override flag for signal WPCtrl */
const volatile boolean volc_b_VCU_Wakeup_reasons_ovrdflg = false;
                /* Referenced by: '<S619>/volc_b_VCU_DTCClearInhibit_ovrdflg' */

/* Override flag for signal VCU_Wakeup_reasons */
const volatile boolean volc_b_VCU_XBRControlMode_ovrdflg = false;
               /* Referenced by: '<S321>/volc_flg_VCU_XBRControlMode_ovrdflg' */

/* Override flag for signal VCU_XBRControlMode */
const volatile boolean volc_b_VCU_XBREBIMode_ovrdflg = false;
                     /* Referenced by: '<S322>/volc_b_VCU_XBREBIMode_ovrdflg' */

/* Override flag for signal VCU_XBREBIMode */
const volatile boolean volc_b_VCU_XBRPriority_ovrdflg = false;
                  /* Referenced by: '<S323>/volc_flg_VCU_XBRPriority_ovrdflg' */

/* Override flag for signal VCU_XBRPriority */
const volatile boolean volc_b_VCU_ZeroPwr_Fb_ovrdflg = false;
              /* Referenced by: '<S396>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_bmsModeStsReq_ovrdflg = false;
                  /* Referenced by: '<S547>/volc_b_VCU_bmsModeStsReq_ovrdflg' */
const volatile boolean volc_b_VCU_bmshAlwChgCurrMax_ovrdflg = true;
              /* Referenced by: '<S399>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_ePTRegencyLevInd_ovrdflg = false;
              /* Referenced by: '<S717>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg' */
const volatile boolean volc_b_VCU_ePTReleaseSig_ovrdflg = false;
                  /* Referenced by: '<S285>/volc_b_VCU_ePTReleaseSig_ovrdflg' */

/* Override flag for signal VCU_ePTReleaseSig */
const volatile boolean volc_b_VacPumpRlyEn_invert = false;
                         /* Referenced by: '<S191>/volc_b_cntnrPwrEna_invert' */
const volatile boolean volc_b_VacPumpRlyEn_ovrdflg = false;
                        /* Referenced by: '<S191>/volc_b_cntnrPwrEna_ovrdflg' */
const volatile boolean volc_b_VacPumpRlyEn_ovrdval = false;
                        /* Referenced by: '<S191>/volc_b_cntnrPwrEna_ovrdval' */
const volatile boolean volc_b_acHvilDtyOutpt_ovrdflg = false;
                   /* Referenced by: '<S184>/volc_flg_acHvilDtyOutpt_ovrdflg' */
const volatile boolean volc_b_acHvilPrdOutpt_ovrdflg = false;
                   /* Referenced by: '<S185>/volc_flg_acHvilPrdOutpt_ovrdflg' */
const volatile boolean volc_b_accyPreRlyCmd_invert = false;
                         /* Referenced by: '<S192>/volc_b_cntnrPwrEna_invert' */
const volatile boolean volc_b_accyPreRlyCmd_ovrdflg = false;
                        /* Referenced by: '<S192>/volc_b_cntnrPwrEna_ovrdflg' */
const volatile boolean volc_b_accyPreRlyCmd_ovrdval = false;
                        /* Referenced by: '<S192>/volc_b_cntnrPwrEna_ovrdval' */
const volatile boolean volc_b_brkPmpEn_invert = false;
                            /* Referenced by: '<S201>/volc_b_brkPmpEn_invert' */

/* Invert flag for signal b_brkPmpEn */
const volatile boolean volc_b_brkPmpEn_ovrdflg = false;
                           /* Referenced by: '<S201>/volc_b_brkPmpEn_ovrdflg' */

/* Override flag for signal b_brkPmpEn */
const volatile boolean volc_b_cntnrCtrlEna_invert = false;
                         /* Referenced by: '<S193>/volc_b_cntnrPwrEna_invert' */

/* Invert flag for signal b_cntnrCtrlEna */
const volatile boolean volc_b_cntnrCtrlEna_ovrdflg = false;
                        /* Referenced by: '<S193>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal b_cntnrCtrlEna */
const volatile boolean volc_b_cntnrCtrlEna_ovrdval = false;
                        /* Referenced by: '<S193>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal b_cntnrCtrlEna */
const volatile boolean volc_b_cntnrPwrEna_invert = false;
                         /* Referenced by: '<S194>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal cntnrPwrEna */
const volatile boolean volc_b_cntnrPwrEna_ovrdflg = false;
                        /* Referenced by: '<S194>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal cntnrPwrEna */
const volatile boolean volc_b_cntnrPwrEna_ovrdval = false;
                        /* Referenced by: '<S194>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal cntnrPwrEna */
const volatile boolean volc_b_emergStopEn_invert = false;
                         /* Referenced by: '<S202>/volc_b_emergStopEn_invert' */

/* Invert flag for signal b_emergStopEn */
const volatile boolean volc_b_emergStopEn_ovrdflg = false;
                        /* Referenced by: '<S202>/volc_b_emergStopEn_ovrdflg' */

/* Override flag for signal b_emergStopEn */
const volatile boolean volc_b_fan1TgtSpd_invert = false;
                   /* Referenced by: '<S209>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for Fan1 target speed */
const volatile boolean volc_b_fan1TgtSpd_ovrdflg = false;
                     /* Referenced by: '<S209>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
const volatile boolean volc_b_fan2TgtSpd_invert = false;
                   /* Referenced by: '<S210>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for Fan2 target speed */
const volatile boolean volc_b_fan2TgtSpd_ovrdflg = false;
                     /* Referenced by: '<S210>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
const volatile boolean volc_b_fan3TgtSpd_invert = false;
                   /* Referenced by: '<S211>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for Fan3 target speed */
const volatile boolean volc_b_fan3TgtSpd_ovrdflg = false;
                     /* Referenced by: '<S211>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
const volatile boolean volc_b_flgFnctnConfgBMSWaterTemp = false;/* Referenced by: '<S13>/Constant' */
const volatile boolean volc_b_heater3EnaHW_invert = false;
                         /* Referenced by: '<S195>/volc_b_cntnrPwrEna_invert' */
const volatile boolean volc_b_heater3EnaHW_ovrdflg = false;
                        /* Referenced by: '<S195>/volc_b_cntnrPwrEna_ovrdflg' */
const volatile boolean volc_b_heater3EnaHW_ovrdval = false;
                        /* Referenced by: '<S195>/volc_b_cntnrPwrEna_ovrdval' */
const volatile boolean volc_b_heaterEnaHW_invert = false;
                         /* Referenced by: '<S196>/volc_b_cntnrPwrEna_invert' */
const volatile boolean volc_b_heaterEnaHW_ovrdflg = false;
                        /* Referenced by: '<S196>/volc_b_cntnrPwrEna_ovrdflg' */
const volatile boolean volc_b_heaterEnaHW_ovrdval = false;
                        /* Referenced by: '<S196>/volc_b_cntnrPwrEna_ovrdval' */
const volatile boolean volc_b_highSpdFanRlyReq_invert = false;
                         /* Referenced by: '<S197>/volc_b_cntnrPwrEna_invert' */
const volatile boolean volc_b_highSpdFanRlyReq_ovrdflg = false;
                        /* Referenced by: '<S197>/volc_b_cntnrPwrEna_ovrdflg' */
const volatile boolean volc_b_highSpdFanRlyReq_ovrdval = false;
                        /* Referenced by: '<S197>/volc_b_cntnrPwrEna_ovrdval' */
const volatile boolean volc_b_mainPosRlyReq_invert = false;
                         /* Referenced by: '<S198>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal mainPosRlyReq */
const volatile boolean volc_b_mainPosRlyReq_ovrdflg = false;
                        /* Referenced by: '<S198>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal mainPosRlyReq */
const volatile boolean volc_b_mainPosRlyReq_ovrdval = false;
                        /* Referenced by: '<S198>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal mainPosRlyReq */
const volatile boolean volc_b_motFanRlyReq_invert = false;
                         /* Referenced by: '<S199>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal motFanRlyReq */
const volatile boolean volc_b_motFanRlyReq_ovrdflg = false;
                        /* Referenced by: '<S199>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal motFanRlyReq */
const volatile boolean volc_b_motFanRlyReq_ovrdval = false;
                        /* Referenced by: '<S199>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal motFanRlyReq */
const volatile boolean volc_b_odpHvilDtyOutpt_ovrdflg = false;
                  /* Referenced by: '<S203>/volc_flg_odpHvilDtyOutpt_ovrdflg' */
const volatile boolean volc_b_odpHvilPrdOutpt_ovrdflg = false;
                  /* Referenced by: '<S204>/volc_flg_odpHvilPrdOutpt_ovrdflg' */
const volatile boolean volc_b_pmpEP1TgtSpd_ovrdflg = false;
                     /* Referenced by: '<S212>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */
const volatile boolean volc_b_pmpEP2TgtSpd_pct1_ovrdflg = false;
                  /* Referenced by: '<S213>/volc_b_pmpEP2TgtSpd_pct1_ovrdflg' */

/* Override flag for signal b_pmpEP2TgtSpd_pct1 */
const volatile boolean volc_b_pmpEP3TgtFre_Hz_ovrdflg = false;
                   /* Referenced by: '<S214>/volc_b_pmpEP3TgtSpd_pct_ovrdflg' */

/* Override flag for signal pmpEP3TgtFre_Hz */
const volatile boolean volc_b_pmpEP3TgtSpd_pct_ovrdflg = false;
                   /* Referenced by: '<S215>/volc_b_pmpEP3TgtSpd_pct_ovrdflg' */

/* Override flag for signal b_pmpEP3TgtSpd_pct */
const volatile boolean volc_b_preChrgRlyReq_dftval = false;
                       /* Referenced by: '<S180>/volc_b_preChrgRlyReq_dftval' */

/* Default value for signal preChrgRlyReq */
const volatile boolean volc_b_preChrgRlyReq_invert = false;
                         /* Referenced by: '<S200>/volc_b_cntnrPwrEna_invert' */

/* Inversion flag for signal preChrgRlyReq */
const volatile boolean volc_b_preChrgRlyReq_ovrdflg = false;
                        /* Referenced by: '<S200>/volc_b_cntnrPwrEna_ovrdflg' */

/* Override flag for signal preChrgRlyReq */
const volatile boolean volc_b_preChrgRlyReq_ovrdval = false;
                        /* Referenced by: '<S200>/volc_b_cntnrPwrEna_ovrdval' */

/* Override value for signal preChrgRlyReq */
const volatile boolean volc_b_steerPumpEn_invert = false;
                         /* Referenced by: '<S217>/volc_b_steerPumpEn_invert' */

/* Invert flag for signal b_steerPumpEn */
const volatile boolean volc_b_steerPumpEn_ovrdflg = false;
                        /* Referenced by: '<S217>/volc_b_steerPumpEn_ovrdflg' */

/* Override flag for signal b_steerPumpEn */
const volatile boolean volc_b_vcuWkUpCmd_invert = false;
                       /* Referenced by: '<S190>/vilc_b_ResrAirSwitch_invert' */

/* Inversion flag for signal vcuWkUpCmd */
const volatile boolean volc_b_vcuWkUpCmd_ovrdflg = false;
                      /* Referenced by: '<S190>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal vcuWkUpCmd */
const volatile boolean volc_b_vcuWkUpCmd_ovrdval = false;
                      /* Referenced by: '<S190>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal vcuWkUpCmd */
const volatile boolean volc_b_waterValveTV1V3_V_ovrdflg = false;
                  /* Referenced by: '<S218>/volc_b_waterValveTV1V3_V_ovrdflg' */

/* Override flag for signal b_waterValveTV1V3_V */
const volatile boolean volc_b_waterValveTV2V2_V_ovrdflg = false;
                  /* Referenced by: '<S219>/volc_b_waterValveTV2V2_V_ovrdflg' */

/* Override flag for signal b_waterValveTV2V2_V */
const volatile boolean volc_brkPmpEn_ovrdval = false;
                             /* Referenced by: '<S201>/volc_brkPmpEn_ovrdval' */

/* Override value for signal brkPmpEn */
const volatile boolean volc_emergStopEn_ovrdval = false;
                          /* Referenced by: '<S202>/volc_emergStopEn_ovrdval' */

/* Override value for signal emergStopEn */
const volatile float32 volc_frq_pmpEP3TgtFre_Hz_dftval = 160.0F;
                   /* Referenced by: '<S180>/volc_frq_pmpEP3TgtFre_Hz_dftval' */

/* Default value for signal pmpEP3TgtFre_Hz */
const volatile uint8 volc_n_SWCompileDay = 11U;/* Referenced by: '<S159>/Constant37' */
const volatile uint8 volc_n_SWCompileMonth = 5U;/* Referenced by: '<S159>/Constant36' */
const volatile float32 volc_n_SWCompileYear = 2026.0F;/* Referenced by: '<S159>/Constant35' */
const volatile uint16 volc_n_Spd3_pct = 50U;/* Referenced by: '<S180>/Constant7' */
const volatile uint16 volc_n_Spd4_pct = 50U;/* Referenced by: '<S180>/Constant10' */
const volatile uint16 volc_n_Spd5_pct = 10U;/* Referenced by: '<S1>/Constant13' */
const volatile uint8 volc_pct_AccPedal_1_dftval = 0U;
                        /* Referenced by: '<S180>/volc_pct_AccPedal_1_dftval' */

/* Default value for signal pct_AccPedal_1 */
const volatile uint8 volc_pct_AccPedal_1_ovrdval = 0U;
                   /* Referenced by: '<S205>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_AccPedal_1 */
const volatile uint8 volc_pct_AccPedal_2_dftval = 0U;
                        /* Referenced by: '<S180>/volc_pct_AccPedal_2_dftval' */

/* Default value for signal pct_AccPedal_2 */
const volatile uint8 volc_pct_AccPedal_2_ovrdval = 0U;
                   /* Referenced by: '<S206>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_AccPedal_2 */
const volatile uint8 volc_pct_BrkPedal_1_dftval = 0U;
                        /* Referenced by: '<S180>/volc_pct_BrkPedal_1_dftval' */

/* Default value for signal pct_BrkPedal_1 */
const volatile uint8 volc_pct_BrkPedal_1_ovrdval = 0U;
                   /* Referenced by: '<S207>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_BrkPedal_1 */
const volatile uint8 volc_pct_BrkPedal_2_dftval = 0U;
                        /* Referenced by: '<S180>/volc_pct_BrkPedal_2_dftval' */

/* Default value for signal pct_BrkPedal_2 */
const volatile uint8 volc_pct_BrkPedal_2_ovrdval = 0U;
                   /* Referenced by: '<S208>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_BrkPedal_2 */
const volatile float32 volc_pct_acHvilDtyOutpt_ovrdval = 50.0F;
                   /* Referenced by: '<S184>/volc_pct_acHvilDtyOutpt_ovrdval' */
const volatile float32 volc_pct_fan1TgtSpd_ovrdval = 0.0F;
                   /* Referenced by: '<S209>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
const volatile float32 volc_pct_fan2TgtSpd_ovrdval = 0.0F;
                   /* Referenced by: '<S210>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
const volatile uint8 volc_pct_fan3TgtSpd_dftval = 0U;
                        /* Referenced by: '<S180>/volc_pct_fan3TgtSpd_dftval' */

/* Default value for signal fan3TgtSpd_pct */
const volatile float32 volc_pct_fan3TgtSpd_ovrdval = 0.0F;
                   /* Referenced by: '<S211>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
const volatile float32 volc_pct_odpHvilDtyOutpt_ovrdval = 50.0F;
                  /* Referenced by: '<S203>/volc_pct_odpHvilDtyOutpt_ovrdval' */
const volatile float32 volc_pct_pmpEP1TgtSpd_ovrdval = 0.0F;
                   /* Referenced by: '<S212>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */
const volatile float32 volc_pmpEP2TgtSpd_pct1_ovrdval = 0.0F;
                    /* Referenced by: '<S213>/volc_pmpEP2TgtSpd_pct1_ovrdval' */

/* Override value for signal pmpEP2TgtSpd_pct1 */
const volatile float32 volc_pmpEP3TgtFre_Hz_ovrdval = 0.0F;
                     /* Referenced by: '<S214>/volc_pmpEP3TgtSpd_pct_ovrdval' */

/* Override value for signal pmpEP3TgtFre_Hz */
const volatile float32 volc_pmpEP3TgtSpd_pct_ovrdval = 0.0F;
                     /* Referenced by: '<S215>/volc_pmpEP3TgtSpd_pct_ovrdval' */

/* Override value for signal pmpEP3TgtSpd_pct */
const volatile uint32 volc_pmpTgtPeriod2_us = 10000U;/* Referenced by: '<S1>/Constant2' */

/* PWM period Set */
const volatile uint32 volc_pmpTgtPeriod3_us = 10000U;/* Referenced by: '<S1>/Constant6' */

/* PWM period Set */
const volatile uint32 volc_pmpTgtPeriod4_us = 10000U;/* Referenced by: '<S180>/Constant1' */

/* PWM period Set */
const volatile uint32 volc_pmpTgtPeriod5_us = 10000U;/* Referenced by: '<S180>/Constant11' */

/* PWM period Set */
const volatile uint32 volc_pmpTgtPeriod6_us = 5000U;/* Referenced by: '<S1>/Constant9' */

/* PWM period Set */
const volatile uint32 volc_pmpTgtPeriod7_us = 5000U;/* Referenced by: '<S1>/Constant12' */

/* PWM period Set */
const volatile uint32 volc_pmpTgtPeriod_us = 2000U;/* Referenced by: '<S1>/Constant3' */

/* PWM period Set */
const volatile uint8 volc_st_ShtDown_ovrdval = 0U;
                      /* Referenced by: '<S216>/vilc_b_ResrAirSwitch_ovrdval' */
const volatile uint16 volc_st_VCU_CalNum_ovrdval = 0U;
                        /* Referenced by: '<S862>/volc_st_VCU_CalNum_ovrdval' */

/* Override value for signal VCU_CalNum */
const volatile uint8 volc_st_VCU_OverloadInd_ovrdval = 0U;
                   /* Referenced by: '<S863>/volc_st_VCU_OverloadInd_ovrdval' */

/* Override value for signal VCU_OverloadInd */
const volatile uint8 volc_st_VCU_bmsModeStsReq_ovrdval = 0U;
                 /* Referenced by: '<S547>/volc_st_VCU_bmsModeStsReq_ovrdval' */
const volatile boolean volc_steerPumpEn_ovrdval = false;
                          /* Referenced by: '<S217>/volc_steerPumpEn_ovrdval' */

/* Override value for signal steerPumpEn */
const volatile float32 volc_tm_acHvilPrdOutpt_ovrdval = 2000.0F;
                    /* Referenced by: '<S185>/volc_tm_acHvilPrdOutpt_ovrdval' */
const volatile float32 volc_tm_dlyForRsrChgSt_s = 1.0F;/* Referenced by: '<S77>/Constant28' */
const volatile float32 volc_tm_odpHvilPrdOutpt_ovrdval = 2000.0F;
                   /* Referenced by: '<S204>/volc_tm_odpHvilPrdOutpt_ovrdval' */
const volatile float32 volc_tq_rgnDisTqThd_Nm = 0.0F;/* Referenced by:
                                                      * '<S41>/Relay'
                                                      * '<S41>/Unit Delay'
                                                      */
const volatile float32 volc_tq_rgnEnbTqThd_Nm = -2.0F;/* Referenced by: '<S41>/Relay' */
const volatile float32 volc_w_VCU_VehicleWeight_ovrdval = 0.0F;
                  /* Referenced by: '<S864>/volc_w_VCU_VehicleWeight_ovrdval' */

/* Override value for signal VCU_VehicleWeight */
const volatile boolean volc_waterValveTV1V3_V_ovrdval = false;
                    /* Referenced by: '<S218>/volc_waterValveTV1V3_V_ovrdval' */

/* Override value for signal waterValveTV1V3_V */
const volatile boolean volc_waterValveTV2V2_V_ovrdval = false;
                    /* Referenced by: '<S219>/volc_waterValveTV2V2_V_ovrdval' */

/* Override value for signal waterValveTV2V2_V */
const volatile uint8 vold_VCU_XBREBIMode_dftval = 2U;
                        /* Referenced by: '<S225>/vold_VCU_XBREBIMode_dftval' */

/* Default value for signal VCU_XBREBIMode */
#define swc_VCOP_STOP_SEC_CONST_VOLATILE
#include "swc_VCOP_MemMap.h"
#define swc_VCOP_START_SEC_VAR
#include "swc_VCOP_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean dccd_b_dcdcEna;                /* '<S6>/Relational Operator' */

/* DCDC Enable */
float32 dccd_pwr_outPwrLmt_KW;         /* '<S6>/Data Type Conversion' */

/* DC/DC Out Power Limit */
uint8 dccd_st_modeReq;                 /* '<S18>/Switch' */

/* DC/DC Mode Request */
boolean dspd_b_ECOBttnWrkLgt;          /* '<S20>/Relational Operator' */

/* ECO Mode Work Light */
boolean dspd_b_gearInvert;             /* '<S21>/Logical Operator4' */
boolean dspd_b_hndbrkSt;               /* '<S35>/timed_debounce' */

/* Hand Brake Status */
boolean dspd_b_ignSt;                  /* '<S37>/timed_debounce' */

/* Ignite Status */
uint8 dspd_st_PTModeInd;               /* '<S25>/Switch' */

/* Power Train Mode */
uint8 dspd_st_drvMod;                  /* '<S20>/Switch1' */

/* Drive Mode */
uint8 dspd_st_gearPosnInd;             /* '<S32>/Switch1' */

/* Gear Position */
float32 dspd_t_battCooltTemp_C;        /* '<S19>/Gain' */

/* Battery Coolent Temperature */
boolean eadd_b_ead2Ena;                /* '<S46>/Logical Operator3' */

/* Secondary EAD Control Enable */
uint8 eadd_st_ead2PTImmoRlsSts;        /* '<S8>/Signal Conversion' */

/* Electric Powertrain Release Status */
uint8 eadd_st_inv2EmCtrlMod;           /* '<S42>/Switch' */

/* Secondary EAD Mode Request to CAN out */
uint8 eadd_st_inv2EmWMod;              /* '<S41>/Switch5' */

/* Secondary EAD Work Mode to CAN out */
float32 eadd_tq_mot2TgtTqReqOutpAbs_Nm;/* '<S39>/Signal Conversion2' */

/* Secondary EAD Absolute Torque Request to CAN out */
float32 eadd_tq_mot2TgtTqReqOutp_Nm;   /* '<S39>/Switch1' */

/* Secondary EAD Torque Request to CAN out */
uint8 epbd_st_parkingSts;              /* '<S52>/Switch' */

/* EPB Status */
boolean hvbd_b_HVRdy;                  /* '<S68>/Logical Operator3' */

/* HV Ready */
boolean hvbd_b_cntnrCtrlEna;           /* '<S61>/Logical Operator3' */

/* Container Control Enable Flag */
boolean hvbd_b_hcmRlyEna;              /* '<S74>/Logical Operator3' */

/* HCM Relay Enable */
boolean hvbd_b_sdcacEna;               /* '<S10>/Signal Conversion' */

/* SDCAC Relay Enable */
uint8 hvbd_st_hvbIntelChgSt;           /* '<S55>/Switch1' */

/* HVB Intelligent Charge State */
float32 ptld_pwr_ead21PwrMaxOutp_kW;   /* '<S75>/Switch6' */

/* Secondary EAD Max Power (motor) for CAN output */
float32 ptld_pwr_ead21PwrMinOutp_kW;   /* '<S75>/Signal Conversion1' */

/* Secondary EAD Min Power (generator) for CAN output */
float32 ptld_pwr_ead2PwrMaxOutp_kW;    /* '<S75>/Switch4' */

/* Secondary EAD Max Power (motor) for CAN output */
float32 ptld_pwr_ead2PwrMinOutp_kW;    /* '<S75>/Signal Conversion' */

/* Secondary EAD Min Power (generator) for CAN output */
boolean srud_b_hvbPmsHvilSts;          /* '<S12>/Logical Operator1' */
boolean srud_b_hvbVehHvilSts;          /* '<S12>/Signal Conversion12' */
uint8 srud_st_hvbBattFltLampSt;        /* '<S12>/Switch1' */
boolean thmd_b_FWFVEna;                /* '<S13>/Signal Conversion2' */

/* FWFV enable */
boolean thmd_b_MHGVEna;                /* '<S13>/Logical Operator' */

/* MHGV enable */
boolean thmd_b_highSpdFanRlyReq;       /* '<S138>/Logical Operator3' */
boolean thmd_b_motFanRlyReq;           /* '<S148>/Logical Operator3' */

/* TMM Fan Relaty Request */
float32 thmd_n_12vAts1PwmReq_pct;      /* '<S83>/Multiport Switch1' */

/* 12v ATS1 PWM */
float32 thmd_n_ats1PwmReq_pct;         /* '<S85>/Multiport Switch1' */

/* ATS1 PWM */
float32 thmd_n_fan1TgtSpdOutp_pct;     /* '<S100>/Multiport Switch1' */

/* Fan1 Target Speed PWM */
float32 thmd_n_fan2TgtSpdOutp_pct;     /* '<S101>/Multiport Switch1' */

/* Fan2 Target Speed PWM */
uint8 thmd_st_ats1Ena;                 /* '<S84>/Multiport Switch1' */

/* ATS1 Enable */
uint8 thmd_st_hvbThermMngWorkMod;      /* '<S106>/Switch1' */

/* THM Work Mode Request */
float32 thmd_t_ptcTempSetting;         /* '<S86>/Switch1' */

/* VCU BPTC Temperature Setting */
uint8 trad_st_gearLvrPos;              /* '<S149>/Switch' */

/* Gear Lever Position mapped for CAN */
boolean vold_12VbatRlyReq;             /* '<S181>/Switch2' */
boolean vold_12vDCDCEn;                /* '<S182>/Switch2' */
boolean vold_24vDCDCEn;                /* '<S183>/Switch2' */
uint8 vold_AC_EWP_Heat;                /* '<S374>/Switch2' */
float32 vold_AC_EWP_HeatrPwrCnsAllwd;  /* '<S375>/Switch2' */
uint8 vold_AC_EWP_Run;                 /* '<S376>/Switch2' */
uint8 vold_AC_EWP_SpeedReq;            /* '<S377>/Switch2' */
float32 vold_AC_EWP_Temp;              /* '<S378>/Switch2' */
float32 vold_BMSH_ACChgTimeRemain;     /* '<S783>/Switch2' */
float32 vold_BMSH_BattCurr;            /* '<S784>/Switch2' */
uint8 vold_BMSH_BattFaultLampState;    /* '<S785>/Switch2' */
uint8 vold_BMSH_CCM_ThermalManageReq;  /* '<S786>/Switch2' */
uint8 vold_BMSH_Cell_TotalNum;         /* '<S787>/Switch2' */
uint8 vold_BMSH_ChargeLEDCtrl;         /* '<S788>/Switch2' */
uint8 vold_BMSH_Charge_Over_Current;   /* '<S789>/Switch2' */
float32 vold_BMSH_ChgTimeRemain;       /* '<S790>/Switch2' */
uint8 vold_BMSH_DCChgminusSocketTempSensing_Failure;/* '<S791>/Switch2' */
uint8 vold_BMSH_DCChgplusSocketTempSensing_Failure;/* '<S792>/Switch2' */
uint8 vold_BMSH_FastChgCC2ConntState;  /* '<S793>/Switch2' */
uint8 vold_BMSH_HvBattThermMod;        /* '<S422>/Switch2' */
uint8 vold_BMSH_InsulationRes_Fault;   /* '<S794>/Switch2' */
boolean vold_BMSH_TBOX_BatIsoAlarm2;   /* '<S160>/Signal Conversion12' */
boolean vold_BMSH_TBOX_BatLowSOC2;     /* '<S160>/Signal Conversion6' */
boolean vold_BMSH_TBOX_BatOverCharge2; /* '<S160>/Signal Conversion7' */
boolean vold_BMSH_TBOX_BatOverSOC2;    /* '<S160>/Signal Conversion4' */
boolean vold_BMSH_TBOX_BatOverTemp2;   /* '<S160>/Signal Conversion11' */
boolean vold_BMSH_TBOX_BatOverVoltage2;/* '<S160>/Signal Conversion13' */
boolean vold_BMSH_TBOX_BatTempUniformity2;/* '<S160>/Signal Conversion3' */
boolean vold_BMSH_TBOX_BatUnderVoltage2;/* '<S160>/Signal Conversion10' */
boolean vold_BMSH_TBOX_BatUniformity2; /* '<S160>/Signal Conversion8' */
boolean vold_BMSH_TBOX_CellOverVoltage2;/* '<S160>/Signal Conversion14' */
boolean vold_BMSH_TBOX_CellUnderVoltage2;/* '<S160>/Signal Conversion9' */
boolean vold_BMSH_TBOX_SOCHop2;        /* '<S160>/Signal Conversion5' */
boolean vold_BMSH_ThermalOutofControl; /* '<S795>/Switch2' */
boolean vold_BMSH_Vehicle_HVILSts_PHEV;/* '<S796>/Switch2' */
uint8 vold_BMSH_stMode;                /* '<S160>/Signal Conversion' */
uint8 vold_EDCP_Flt;                   /* '<S416>/Switch2' */
uint8 vold_HBCP_Flt;                   /* '<S417>/Switch2' */
boolean vold_IPU_MCUTempHighAlarm1;    /* '<S160>/Signal Conversion2' */
boolean vold_IPU_MotorTempHighFault1;  /* '<S160>/Signal Conversion1' */
uint8 vold_PMS_32960FltNum;            /* '<S797>/Switch2' */
uint8 vold_PMS_AcceRelayVoltSampSwich; /* '<S857>/Switch2' */
uint8 vold_PMS_AcceSuppressionSts;     /* '<S379>/Switch2' */
float32 vold_PMS_Acceleration;         /* '<S171>/Switch2' */
uint8 vold_PMS_AccessoryConnStsFb;     /* '<S577>/Switch2' */
boolean vold_PMS_AccessoryCtrlCommand; /* '<S286>/Switch2' */
uint8 vold_PMS_AccessoryRelayFlt;      /* '<S578>/Switch2' */
float32 vold_PMS_ActualPTTorque;       /* '<S798>/Switch2' */
boolean vold_PMS_BBM_FaultStatus;      /* '<S287>/Switch2' */
boolean vold_PMS_BBM_WorkSts;          /* '<S288>/Switch2' */
uint8 vold_PMS_BMS_Reignstatus1;       /* '<S799>/Switch2' */
uint8 vold_PMS_BMS_Reignstatus2;       /* '<S800>/Switch2' */
boolean vold_PMS_Brake_LightsRequest;  /* '<S801>/Switch2' */
float32 vold_PMS_CPSRU;                /* '<S380>/Switch2' */
boolean vold_PMS_CampModeFb;           /* '<S802>/Switch2' */
uint8 vold_PMS_CampModeFbFailrReason;  /* '<S803>/Switch2' */
float32 vold_PMS_ChargPwr;             /* '<S381>/Switch2' */
uint8 vold_PMS_ChargeLimitResponse;    /* '<S804>/Switch2' */
boolean vold_PMS_CruisingDstSwtFb;     /* '<S805>/Switch2' */
boolean vold_PMS_CurrentGearPositionValid;/* '<S659>/Switch2' */
float32 vold_PMS_DriverDemandTorque;   /* '<S806>/Switch2' */
uint8 vold_PMS_DrivingTakeEleSts;      /* '<S289>/Switch2' */
uint16 vold_PMS_DrvPfmncRedn;          /* '<S807>/Switch2' */
boolean vold_PMS_EPBClosedReq_PMS;     /* '<S808>/Switch2' */
boolean vold_PMS_Fn1GearRlyDrvStsFb;   /* '<S382>/Switch2' */
boolean vold_PMS_Fn2GearRlyDrvStsFb;   /* '<S383>/Switch2' */
boolean vold_PMS_FrntHeatModEnad;      /* '<S172>/Switch2' */
float32 vold_PMS_FrntHeatPwrAllwd;     /* '<S173>/Switch2' */
boolean vold_PMS_GearIntervene;        /* '<S809>/Switch2' */
float32 vold_PMS_GrossComVehWeight;    /* '<S810>/Switch2' */
boolean vold_PMS_HVIL1Sts_EV;          /* '<S174>/Switch2' */
boolean vold_PMS_HVIL1Sts_UB;          /* '<S175>/Switch2' */
boolean vold_PMS_HVIL2Sts_EV;          /* '<S176>/Switch2' */
boolean vold_PMS_HVIL2Sts_UB;          /* '<S177>/Switch2' */
boolean vold_PMS_HVILSts_EV;           /* '<S178>/Switch2' */
float32 vold_PMS_HvCoolgPwrAllwd;      /* '<S418>/Switch2' */

/* indicated power limiting allowed */
float32 vold_PMS_HvHeatgPwrAllwd;      /* '<S419>/Switch2' */

/* indicated power limiting allowed */
float32 vold_PMS_IPKTotalOdometer;     /* '<S811>/Switch2' */
uint8 vold_PMS_InventorySpdLmtRxSts;   /* '<S812>/Switch2' */
uint8 vold_PMS_InventorySpdLmtSts;     /* '<S813>/Switch2' */
uint8 vold_PMS_IsgActvDampgModReq;     /* '<S509>/Switch2' */
uint8 vold_PMS_Life;                   /* '<S814>/Switch2' */
uint8 vold_PMS_LockVehExecutedSts;     /* '<S384>/Switch2' */
uint8 vold_PMS_LockVehPerFlag;         /* '<S815>/Switch2' */
uint8 vold_PMS_LockVehPerRxSts;        /* '<S816>/Switch2' */
float32 vold_PMS_MCUFlowFeedback_EV;   /* '<S420>/Switch2' */
float32 vold_PMS_MaxPTTorqueAllowed;   /* '<S817>/Switch2' */
float32 vold_PMS_MinPTTorqueAllowed;   /* '<S818>/Switch2' */
uint8 vold_PMS_OTAInstrucStsReminder;  /* '<S819>/Switch2' */
uint8 vold_PMS_OTAInstructRxnSts;      /* '<S820>/Switch2' */
float32 vold_PMS_Odometerbackup;       /* '<S821>/Switch2' */
boolean vold_PMS_OdometerbackupEnable; /* '<S822>/Switch2' */
uint8 vold_PMS_PTC1ConnStsFb;          /* '<S579>/Switch2' */
uint8 vold_PMS_PTC1RelayFlt;           /* '<S580>/Switch2' */
uint8 vold_PMS_PTC3ConnStsFb;          /* '<S581>/Switch2' */
uint8 vold_PMS_PTC3RelayFlt;           /* '<S582>/Switch2' */
uint8 vold_PMS_PTCRelayVoltSampSwich;  /* '<S858>/Switch2' */
uint8 vold_PMS_PowerOffCmdRxSts;       /* '<S823>/Switch2' */
uint8 vold_PMS_PowerOffCmdSts;         /* '<S824>/Switch2' */
uint8 vold_PMS_PreAccessoryConnStsFb;  /* '<S583>/Switch2' */
uint8 vold_PMS_PreAccessoryRelayFlt;   /* '<S584>/Switch2' */
float32 vold_PMS_Real_PedalPosition;   /* '<S463>/Switch2' */
boolean vold_PMS_Real_PedalPositionInvalid;/* '<S464>/Switch2' */
float32 vold_PMS_RegenTarTrqPot;       /* '<S825>/Switch2' */
float32 vold_PMS_RegenTrqAct;          /* '<S826>/Switch2' */
float32 vold_PMS_RegenTrqPot;          /* '<S827>/Switch2' */
uint8 vold_PMS_RegulationSpeed;        /* '<S385>/Switch2' */
uint8 vold_PMS_RemChrgCmdFailrPrompt;  /* '<S386>/Switch2' */
uint8 vold_PMS_SpdLmtLevel;            /* '<S828>/Switch2' */
uint8 vold_PMS_SpdLmtLevelRxSts;       /* '<S829>/Switch2' */
uint8 vold_PMS_StsBatLockSensor;       /* '<S179>/Switch2' */
boolean vold_PMS_TBOX_HVILState;       /* '<S830>/Switch2' */
uint8 vold_PMS_TBOX_LifeSts;           /* '<S831>/Switch2' */
boolean vold_PMS_TakeEleSwtIndReq;     /* '<S387>/Switch2' */
uint8 vold_PMS_ThermalReq;             /* '<S421>/Switch2' */
uint8 vold_PMS_Torque_Ovrd_Active;     /* '<S388>/Switch2' */
uint8 vold_PMS_Torque_Ovrd_Type;       /* '<S389>/Switch2' */
uint8 vold_PMS_V2XDchaSwtFb1;          /* '<S832>/Switch2' */
uint8 vold_PMS_VINCode1_8_15_S;        /* '<S833>/Switch2' */
uint8 vold_PMS_VINCode2_9_16_S;        /* '<S834>/Switch2' */
uint8 vold_PMS_VINCode3_10_17_S;       /* '<S835>/Switch2' */
uint8 vold_PMS_VINCode4_11_S;          /* '<S836>/Switch2' */
uint8 vold_PMS_VINCode5_12_S;          /* '<S837>/Switch2' */
uint8 vold_PMS_VINCode6_13_S;          /* '<S838>/Switch2' */
uint8 vold_PMS_VINCode7_14_S;          /* '<S839>/Switch2' */
uint8 vold_PMS_VINMessageNum_S;        /* '<S840>/Switch2' */
float32 vold_PMS_VacuumPressure;       /* '<S841>/Switch2' */
float32 vold_PMS_VacuumPump_FB;        /* '<S842>/Switch2' */
uint8 vold_PMS_VacuumSystemsta;        /* '<S843>/Switch2' */
uint8 vold_PMS_VehicleSysErrorLevelG;  /* '<S398>/Switch2' */
uint8 vold_PMS_VersionConversionFlag;  /* '<S844>/Switch2' */
uint8 vold_PMS_VersionConversionRxSts; /* '<S845>/Switch2' */
boolean vold_PMS_ePTFault;             /* '<S846>/Switch2' */
uint8 vold_TBOX_ChrgSoftSwCtrlst;      /* '<S390>/Switch2' */
uint8 vold_TBOX_ReservationChrgnSts;   /* '<S391>/Switch2' */
uint8 vold_VCU_12VATS1Enable;          /* '<S441>/Switch2' */
float32 vold_VCU_12VATS1_PWMRequest;   /* '<S442>/Switch2' */
uint8 vold_VCU_12VDCDCCutOffLV;        /* '<S548>/Switch2' */
uint8 vold_VCU_12VDCDCEnableOut;       /* '<S549>/Switch2' */
uint8 vold_VCU_24V_Switch;             /* '<S679>/Switch2' */
uint8 vold_VCU_ACActiveReq;            /* '<S465>/Switch2' */
float32 vold_VCU_ACC1PosVol;           /* '<S564>/Switch2' */
float32 vold_VCU_ACC2PosVol;           /* '<S565>/Switch2' */
uint8 vold_VCU_ACCMEnable;             /* '<S423>/Switch2' */
uint8 vold_VCU_ACCY1CtrlCmd;           /* '<S290>/Switch2' */
uint8 vold_VCU_ACCYEnableIn;           /* '<S291>/Switch2' */
boolean vold_VCU_ACUCrashfz_Back;      /* '<S292>/Switch2' */
float32 vold_VCU_AEC;                  /* '<S531>/Switch2' */
boolean vold_VCU_APUSWILED_Ctrl;       /* '<S293>/Switch2' */
uint8 vold_VCU_ATS1Enable;             /* '<S443>/Switch2' */
float32 vold_VCU_ATS1_PWMRequest;      /* '<S444>/Switch2' */
uint8 vold_VCU_ATS2Enable;             /* '<S445>/Switch2' */
float32 vold_VCU_ATS2_PWMRequest;      /* '<S446>/Switch2' */
uint8 vold_VCU_ATS3Enable;             /* '<S447>/Switch2' */
float32 vold_VCU_ATS3_PWMRequest;      /* '<S448>/Switch2' */
uint8 vold_VCU_ATS4Enable;             /* '<S449>/Switch2' */
float32 vold_VCU_ATS4_PWMRequest;      /* '<S450>/Switch2' */
boolean vold_VCU_AWB;                  /* '<S620>/Switch2' */
float32 vold_VCU_AccePedalPosD;        /* '<S631>/Switch2' */
float32 vold_VCU_AccePedalPosE;        /* '<S632>/Switch2' */
float32 vold_VCU_AcceleratorPedalPosition;/* '<S466>/Switch2' */
boolean vold_VCU_AcceleratorPedal_flag;/* '<S467>/Switch2' */
boolean vold_VCU_AccyAllowEnable_Ctrl; /* '<S294>/Switch2' */
boolean vold_VCU_AccyPower_back;       /* '<S295>/Switch2' */
uint8 vold_VCU_ActualGear;             /* '<S869>/Switch2' */
uint8 vold_VCU_Address;                /* '<S621>/Switch2' */
uint8 vold_VCU_AllowChg;               /* '<S550>/Switch2' */
uint16 vold_VCU_AppSts;                /* '<S566>/Switch2' */
float32 vold_VCU_AvgEVConsume;         /* '<S296>/Switch2' */
float32 vold_VCU_AvgFuelVF;            /* '<S297>/Switch2' */
float32 vold_VCU_BMSHAllowChgCurrentMax;/* '<S399>/Switch2' */
uint8 vold_VCU_BMSHVOnOffReq;          /* '<S551>/Switch2' */
float32 vold_VCU_BMSH_DCChgRelayVolt;  /* '<S552>/Switch2' */
float32 vold_VCU_BMS_SOC;              /* '<S353>/Switch2' */

/* BMS SOC */
float32 vold_VCU_BMS_voltage;          /* '<S354>/Switch2' */

/* BMS Voltage */
uint8 vold_VCU_BPTCCtrlCmd;            /* '<S563>/Switch2' */
boolean vold_VCU_BPTCEnable;           /* '<S859>/Switch2' */
float32 vold_VCU_BPTCPowerRatio;       /* '<S849>/Saturation0' */
float32 vold_VCU_BPTCTempSetting;      /* '<S861>/Switch2' */
uint16 vold_VCU_BattCoolVal3_FBV5;     /* '<S597>/Switch2' */
uint16 vold_VCU_BattCoolVal3_FBV6;     /* '<S598>/Switch2' */
uint16 vold_VCU_BattHeatVal2_FBV5;     /* '<S599>/Switch2' */
uint16 vold_VCU_BattHeatVal2_FBV6;     /* '<S600>/Switch2' */
float32 vold_VCU_BattMaxTemp;          /* '<S355>/Switch2' */

/* Battery Maximum Temperature */
float32 vold_VCU_BattMinTemp;          /* '<S356>/Switch2' */

/* Battery Minimum Temperature */
float32 vold_VCU_BattPackInCoolTemp;   /* '<S424>/Switch2' */
float32 vold_VCU_BattPackInCoolTempback;/* '<S298>/Switch2' */
float32 vold_VCU_BattPackOutCoolTemp;  /* '<S425>/Switch2' */
float32 vold_VCU_BattPackoutCoolTempback;/* '<S299>/Switch2' */
float32 vold_VCU_BattVol;              /* '<S357>/Switch2' */

/* Battery Voltage */
float32 vold_VCU_BatteryCoolentTemp;   /* '<S426>/Switch2' */
float32 vold_VCU_BatteryVol;           /* '<S567>/Switch2' */
boolean vold_VCU_Batty_Charge_DisChargeState;/* '<S358>/Switch2' */

/* Baterry Charge and Discharge State Flag */
boolean vold_VCU_Batty_ThermalMangeActive;/* '<S359>/Switch2' */

/* Battery Thermal Management Active Flag */
uint8 vold_VCU_Batty_ThermalMangeReq;  /* '<S427>/Switch2' */
uint8 vold_VCU_Batty_ThermalMangeWorkMode;/* '<S360>/Switch2' */

/* Battery Thermal Management Work Mode */
uint8 vold_VCU_BrakSwitchSts;          /* '<S468>/Switch2' */
float32 vold_VCU_Brake1PosVol;         /* '<S592>/Switch2' */
boolean vold_VCU_Brake1Sts;            /* '<S568>/Switch2' */
float32 vold_VCU_Brake2PosVol;         /* '<S593>/Switch2' */
boolean vold_VCU_Brake2Sts;            /* '<S569>/Switch2' */
float32 vold_VCU_BrakePedalPosition;   /* '<S469>/Switch2' */
uint8 vold_VCU_BrkSysErr;              /* '<S660>/Switch2' */
uint8 vold_VCU_CCFb;                   /* '<S585>/Switch2' */
float32 vold_VCU_CC_Acceleration;      /* '<S324>/Switch2' */
boolean vold_VCU_Cab_ThermalMangeReq;  /* '<S361>/Switch2' */

/* Cabin Thermal Management Request */
uint16 vold_VCU_CabinLoopVal1_FBV6;    /* '<S601>/Switch2' */
uint16 vold_VCU_CabinLoopVal2_FBV5;    /* '<S602>/Switch2' */
uint8 vold_VCU_Cabin_PumpFb;           /* '<S586>/Switch2' */
uint16 vold_VCU_CalNum;                /* '<S865>/Switch2' */
uint8 vold_VCU_CalibrationMajorVer1;   /* '<S704>/Switch2' */
uint8 vold_VCU_CalibrationMajorVer2;   /* '<S705>/Switch2' */
uint8 vold_VCU_CalibrationMajorVer3;   /* '<S706>/Switch2' */
uint8 vold_VCU_CalibrationMinorVer1;   /* '<S707>/Switch2' */
uint8 vold_VCU_CalibrationMinorVer2;   /* '<S708>/Switch2' */
uint8 vold_VCU_CalibrationMinorVer3;   /* '<S709>/Switch2' */
float32 vold_VCU_Cell_Avg_Temp;        /* '<S362>/Switch2' */

/* Cell Average Temperature */
uint8 vold_VCU_ChargWakeupSts;         /* '<S587>/Switch2' */
uint8 vold_VCU_ChargeDepthReq;         /* '<S400>/Switch2' */
uint8 vold_VCU_Charger_Connected;      /* '<S363>/Switch2' */

/* Charger Connected State */
float32 vold_VCU_ControlSetSpeed;      /* '<S481>/Switch2' */

/* Cruise Control Target Set Speed */
uint8 vold_VCU_ControlSetSpeed_Mode;   /* '<S482>/Switch2' */

/* Cruise Control Speed Mode */
uint8 vold_VCU_Cooling_Control_Request;/* '<S364>/Switch2' */

/* VCU Cooling Control Request */
uint8 vold_VCU_CrashOutputSts;         /* '<S847>/Switch2' */
uint8 vold_VCU_CruiseControlSts;       /* '<S483>/Switch2' */

/* Cruise Control Status */
uint8 vold_VCU_CruiseSwSts;            /* '<S484>/Switch2' */

/* Cruise Control Button Status */
uint8 vold_VCU_CruiseSwerrorSts;       /* '<S485>/Switch2' */

/* Cruise Control Button Status Error */
float32 vold_VCU_DCDCPwrLmt;           /* '<S553>/Switch2' */
uint8 vold_VCU_DCDC_WorkSts;           /* '<S661>/Switch2' */

/* DCDC Working Status */
float32 vold_VCU_DTE;                  /* '<S532>/Switch2' */
uint8 vold_VCU_DischargeEnable;        /* '<S397>/Switch2' */
sint16 vold_VCU_DriveCircuitTemp;      /* '<S392>/Switch2' */
uint16 vold_VCU_DriveCircuitVol;       /* '<S603>/Switch2' */
uint8 vold_VCU_DriveModeInd;           /* '<S662>/Switch2' */
uint8 vold_VCU_DrivePwrCircuitInd;     /* '<S663>/Switch2' */
float32 vold_VCU_DriveReqTrqPercent;   /* '<S510>/Switch2' */

/* Drive Request Torque Percentage */
uint8 vold_VCU_DriverOperationReminder;/* '<S470>/Switch2' */
uint8 vold_VCU_DrivingTakeForceSts;    /* '<S873>/Switch2' */
boolean vold_VCU_ECOMode;              /* '<S570>/Switch2' */
boolean vold_VCU_ECOmodeSWILED_Ctrl;   /* '<S300>/Switch2' */
float32 vold_VCU_ECPM_FaultFB;         /* '<S301>/Switch2' */
boolean vold_VCU_EDCP_Enable;          /* '<S875>/Switch2' */
float32 vold_VCU_EDCP_FaultFB;         /* '<S302>/Switch2' */
float32 vold_VCU_EDCP_PWMCtrl;         /* '<S854>/Saturation0' */
uint8 vold_VCU_EM1CtrlMode;            /* '<S511>/Switch2' */
uint8 vold_VCU_EM1WorkMode;            /* '<S512>/Switch2' */
uint8 vold_VCU_EMCtrlMode;             /* '<S513>/Switch2' */
uint8 vold_VCU_EMWorkMode;             /* '<S514>/Switch2' */
uint8 vold_VCU_EManualStartSwi;        /* '<S588>/Switch2' */
float32 vold_VCU_EVDTEodometer;        /* '<S303>/Switch2' */
uint8 vold_VCU_EV_Switch;              /* '<S680>/Switch2' */
uint8 vold_VCU_EVanualStartSwi;        /* '<S664>/Switch2' */
uint8 vold_VCU_EmergencyStop;          /* '<S594>/Switch2' */
float32 vold_VCU_EngFuelInstCons;      /* '<S365>/Switch2' */

/* Engine Instantaneous Fuel Consumption */
float32 vold_VCU_ErrCode;              /* '<S533>/Switch2' */
float32 vold_VCU_ExternalAccDemand;    /* '<S325>/Switch2' */

/* External Acceleration Demand */
float32 vold_VCU_FanPWM_Ctrl;          /* '<S681>/Switch2' */
float32 vold_VCU_FuleDTEodometer;      /* '<S304>/Switch2' */
uint8 vold_VCU_FunAnti_DismantleActive;/* '<S609>/Switch2' */
uint8 vold_VCU_FunLockVehActive;       /* '<S610>/Switch2' */
boolean vold_VCU_GP_Override;          /* '<S326>/Switch2' */
uint8 vold_VCU_GearOperateErr;         /* '<S665>/Switch2' */
uint8 vold_VCU_GearPositionInd;        /* '<S666>/Switch2' */
float32 vold_VCU_GearPositionInput;    /* '<S595>/Switch2' */
uint8 vold_VCU_Gearshift_Resp;         /* '<S874>/Switch2' */
boolean vold_VCU_HBCP_Enable;          /* '<S877>/Switch2' */
float32 vold_VCU_HBCP_FaultFB;         /* '<S305>/Switch2' */
float32 vold_VCU_HBCP_PWMCtrl;         /* '<S878>/Switch2' */
float32 vold_VCU_HTCoolingFan1FB;      /* '<S306>/Switch2' */
uint8 vold_VCU_HVB_PumpFb;             /* '<S589>/Switch2' */
float32 vold_VCU_HVILReturn;           /* '<S596>/Switch2' */
boolean vold_VCU_HVOnOffReq;           /* '<S366>/Switch2' */

/* VCU HV ON/OFF Request */
uint16 vold_VCU_HVPRASts;              /* '<S571>/Switch2' */
uint8 vold_VCU_HV_Status;              /* '<S307>/Switch2' */
uint8 vold_VCU_HandbrakeSts;           /* '<S667>/Switch2' */
uint8 vold_VCU_HandbrakeSts2;          /* '<S471>/Switch2' */
uint8 vold_VCU_HardwareMajorVer;       /* '<S710>/Switch2' */
uint8 vold_VCU_HardwareMinorVer;       /* '<S711>/Switch2' */
boolean vold_VCU_HazardReq;            /* '<S554>/Switch2' */
uint8 vold_VCU_HybridReady;            /* '<S367>/Switch2' */

/* VCU Hybrid Mode Ready */
uint8 vold_VCU_Idle_Switch;            /* '<S682>/Switch2' */
boolean vold_VCU_IgnONSts;             /* '<S572>/Switch2' */
uint8 vold_VCU_IgniteSts;              /* '<S668>/Switch2' */
uint8 vold_VCU_InhibitHybrid_Switch;   /* '<S683>/Switch2' */
uint8 vold_VCU_IntelLockLoopSts;       /* '<S555>/Switch2' */
uint8 vold_VCU_IntelligentChargeExitReq;/* '<S308>/Switch2' */
uint8 vold_VCU_IntelligentChargeQuit;  /* '<S309>/Switch2' */
uint8 vold_VCU_IntelligentChargeState; /* '<S310>/Switch2' */
uint8 vold_VCU_LTCoolingFan2FB;        /* '<S311>/Switch2' */
uint8 vold_VCU_LockLimResult;          /* '<S611>/Switch2' */
uint8 vold_VCU_LockVehSts;             /* '<S612>/Switch2' */
uint8 vold_VCU_LockVehType;            /* '<S613>/Switch2' */
uint8 vold_VCU_MCU1EnableReq;          /* '<S515>/Switch2' */
uint8 vold_VCU_MCUActiveDischg;        /* '<S368>/Switch2' */

/* MCU Active Discharge State */
uint8 vold_VCU_MCUEnableReq;           /* '<S516>/Switch2' */
uint16 vold_VCU_MCUMaxTrq;             /* '<S517>/Switch2' */

/* Motor Maximum Torque */
float32 vold_VCU_MCUSpdRampRate;       /* '<S518>/Switch2' */

/* MCU Speed Ramp Rate */
float32 vold_VCU_MCUTqRampRate;        /* '<S519>/Switch2' */

/* MCU Torque Ramp Rate */
float32 vold_VCU_MCU_MotorActTrqPercent;/* '<S520>/Switch2' */

/* Motor Actual Torque Percentage */
float32 vold_VCU_MCU_PumpPWM_Ctrl;     /* '<S684>/Switch2' */
uint8 vold_VCU_MCU_RelayCtrl_Ctrl;     /* '<S685>/Switch2' */
uint8 vold_VCU_MILTelltale;            /* '<S633>/Switch2' */
uint8 vold_VCU_MainPosCtrlCommand;     /* '<S556>/Switch2' */
uint8 vold_VCU_Main_Contactor_Control; /* '<S369>/Switch2' */

/* VCU Main Contactor Control Request */
float32 vold_VCU_MaxEMPwrLmt;          /* '<S521>/Switch2' */
float32 vold_VCU_MinEMPwrLmt;          /* '<S522>/Switch2' */
float32 vold_VCU_MotorSpeed;           /* '<S523>/Switch2' */

/* VCU Motor Speed Request */
float32 vold_VCU_MotorTorque;          /* '<S524>/Switch2' */

/* VCU Motor Torque Request */
boolean vold_VCU_NMSts;                /* '<S622>/Switch2' */
uint8 vold_VCU_Oil_HV_OFF;             /* '<S870>/Switch2' */

/* VCU Oil HV Off */
uint8 vold_VCU_OverloadInd;            /* '<S866>/Switch2' */
float32 vold_VCU_PMS_APPowerActual_EV; /* '<S428>/Switch2' */
boolean vold_VCU_PTC2Enable;           /* '<S394>/Switch2' */
boolean vold_VCU_PTC3Enable;           /* '<S395>/Switch2' */
uint8 vold_VCU_PTCEnable;              /* '<S429>/Switch2' */
uint8 vold_VCU_PTHVSysErrorLampStsInd; /* '<S669>/Switch2' */
uint8 vold_VCU_PTModeInd;              /* '<S670>/Switch2' */
uint8 vold_VCU_PTReadyInd;             /* '<S671>/Switch2' */
float32 vold_VCU_PTResiPwr;            /* '<S534>/Switch2' */
float32 vold_VCU_PTSysElecPwrInd;      /* '<S672>/Switch2' */
uint8 vold_VCU_PreRelay_Ctrl;          /* '<S686>/Switch2' */
uint8 vold_VCU_PressureSwi1Sts;        /* '<S590>/Switch2' */
uint8 vold_VCU_PressureSwi2Sts;        /* '<S591>/Switch2' */
boolean vold_VCU_PropulSysActive;      /* '<S312>/Switch2' */
float32 vold_VCU_QuitControlSpeed;     /* '<S486>/Switch2' */

/* Quit Cruise Control Target Speed */
boolean vold_VCU_RMR;                  /* '<S623>/Switch2' */
uint8 vold_VCU_RelayCtrl_Ctrl;         /* '<S687>/Switch2' */
float32 vold_VCU_ReqSpdOrLmt;          /* '<S525>/Switch2' */
float32 vold_VCU_ReqTrqOrLmt;          /* '<S526>/Switch2' */
float32 vold_VCU_SDCACOutFreq;         /* '<S557>/Switch2' */
boolean vold_VCU_SDCACStopFault;       /* '<S558>/Switch2' */
uint8 vold_VCU_SWCompileDay;           /* '<S712>/Switch2' */
uint8 vold_VCU_SWCompileMonth;         /* '<S713>/Switch2' */
float32 vold_VCU_SWCompileYear;        /* '<S714>/Switch2' */
uint8 vold_VCU_SelfCheckSts;           /* '<S559>/Switch2' */
float32 vold_VCU_Set_Temp;             /* '<S370>/Switch2' */

/* VCU Set Temperature */
boolean vold_VCU_ShiftClimbing;        /* '<S573>/Switch2' */
boolean vold_VCU_ShiftD;               /* '<S574>/Switch2' */
boolean vold_VCU_ShiftR;               /* '<S575>/Switch2' */
uint8 vold_VCU_SoftwareMajorVer;       /* '<S715>/Switch2' */
uint8 vold_VCU_SoftwareMinorVer;       /* '<S716>/Switch2' */
boolean vold_VCU_StartSts;             /* '<S576>/Switch2' */
uint32 vold_VCU_Stayawake_reasons;     /* '<S624>/Switch2' */
boolean vold_VCU_StsBrkSwitch1Invalid; /* '<S472>/Switch2' */
float32 vold_VCU_TotalOdometer;        /* '<S634>/Switch2' */
boolean vold_VCU_TotalOdometerInvalid; /* '<S635>/Switch2' */
uint8 vold_VCU_TurtleLampReq;          /* '<S673>/Switch2' */
boolean vold_VCU_VLC_Active;           /* '<S327>/Switch2' */
boolean vold_VCU_VLC_Available;        /* '<S328>/Switch2' */
float32 vold_VCU_VLC_InternalTargetACCeleration;/* '<S329>/Switch2' */
float32 vold_VCU_VLC_VCUTargetACCeleration;/* '<S330>/Switch2' */
float32 vold_VCU_VehCruisingDistance;  /* '<S688>/Switch2' */
uint8 vold_VCU_VehicleAbnormalSts;     /* '<S674>/Switch2' */
float32 vold_VCU_VehicleIdentification;/* '<S690>/Switch2' */
uint8 vold_VCU_VehicleRunMode;         /* '<S675>/Switch2' */
uint8 vold_VCU_VehicleSlipWarning;     /* '<S676>/Switch2' */
float32 vold_VCU_VehicleSpd;           /* '<S473>/Switch2' */
boolean vold_VCU_VehicleSpd_flag;      /* '<S474>/Switch2' */
uint8 vold_VCU_VehicleSubSysErrorLevel;/* '<S677>/Switch2' */
uint8 vold_VCU_VehicleSysErrorLevel;   /* '<S678>/Switch2' */
uint8 vold_VCU_VehicleSysFltLevel;     /* '<S637>/Switch2' */
float32 vold_VCU_VehicleWeight;        /* '<S867>/Switch2' */
uint8 vold_VCU_WPCtrl;                 /* '<S430>/Switch2' */
uint8 vold_VCU_Wakeup_reasons;         /* '<S625>/Switch2' */
uint8 vold_VCU_XBRControlMode;         /* '<S331>/Switch2' */

/* External Brake Control Mode */
uint8 vold_VCU_XBREBIMode;             /* '<S332>/Switch2' */
uint8 vold_VCU_XBRPriority;            /* '<S333>/Switch2' */

/* External Brake Priority */
boolean vold_VCU_ZeroPwr_Fb;           /* '<S396>/Switch2' */
uint8 vold_VCU_bmsModeStsReq;          /* '<S560>/Switch2' */
uint8 vold_VCU_ePTRegencyLevInd;       /* '<S717>/Switch2' */
uint8 vold_VCU_ePTReleaseSig;          /* '<S313>/Switch2' */
boolean vold_b_CpsrCtrl;               /* '<S180>/Signal Conversion1' */
boolean vold_b_ResetHSDFRA16A17;       /* '<S186>/Switch2' */
boolean vold_b_ResetHSDFRA1A2;         /* '<S187>/Switch2' */
boolean vold_b_ResetHSDFRA31A32;       /* '<S188>/Switch2' */
boolean vold_b_ResetHSDFRA46A47;       /* '<S189>/Switch2' */
boolean vold_b_VacPumpRlyEn;           /* '<S191>/Switch2' */
boolean vold_b_accyPreRlyCmd;          /* '<S192>/Switch2' */
boolean vold_b_cntnrCtrlEna;           /* '<S193>/Switch2' */
boolean vold_b_cntnrPwrEna;            /* '<S194>/Switch2' */
boolean vold_b_heater3EnaHW;           /* '<S195>/Switch2' */
boolean vold_b_heaterEnaHW;            /* '<S196>/Switch2' */
boolean vold_b_highSpdFanRlyReq;       /* '<S197>/Switch2' */
boolean vold_b_mainPosRlyReq;          /* '<S198>/Switch2' */

/* Main Positive Relay Request */
boolean vold_b_motFanRlyReq;           /* '<S199>/Switch2' */

/* Motor Fan Relay Request */
boolean vold_b_preChrgRlyReq;          /* '<S200>/Switch2' */

/* Precharge Relay Request */
boolean vold_brkPmpEn;                 /* '<S201>/Switch2' */
boolean vold_emergStopEn;              /* '<S202>/Switch2' */
float32 vold_fan1TgtSpd_pct;           /* '<S209>/Switch2' */
float32 vold_fan2TgtSpd_pct;           /* '<S210>/Switch2' */
float32 vold_fan3TgtSpd_pct;           /* '<S211>/Switch2' */
uint8 vold_pct_AccPedal_1;             /* '<S205>/Switch2' */

/* Accelerator Pedal Position 1 */
uint8 vold_pct_AccPedal_2;             /* '<S206>/Switch2' */

/* Accelerator Pedal Position 2 */
uint8 vold_pct_BrkPedal_1;             /* '<S207>/Switch2' */

/* Brake Pedal Position 1 */
uint8 vold_pct_BrkPedal_2;             /* '<S208>/Switch2' */

/* Brake Pedal Position 2 */
float32 vold_pct_acHvilDtyOutpt;       /* '<S220>/Switch2' */
float32 vold_pct_odpHvilDtyOutpt;      /* '<S222>/Switch2' */
float32 vold_pmpEP1TgtSpd_pct;         /* '<S212>/Switch2' */
float32 vold_pmpEP2TgtSpd_pct;         /* '<S213>/Switch2' */
float32 vold_pmpEP3TgtFre_Hz;          /* '<S214>/Switch2' */

/* EP3 Motor Water Pump Target Frequency */
float32 vold_pmpEP3TgtSpd_pct;         /* '<S215>/Switch2' */
uint8 vold_st_ShtDown;                 /* '<S216>/Switch2' */
boolean vold_steerPumpEn;              /* '<S217>/Switch2' */
float32 vold_tm_acHvilPrdOutpt;        /* '<S221>/Switch2' */
float32 vold_tm_odpHvilPrdOutpt;       /* '<S223>/Switch2' */
boolean vold_waterValveTV1V3_V;        /* '<S218>/Switch2' */
boolean vold_waterValveTV2V2_V;        /* '<S219>/Switch2' */
float32 vscd_tq_axle2ActRgnTq_Nm;      /* '<S154>/Saturation1' */
float32 vscd_tq_axle2ActTq_Nm;         /* '<S154>/Saturation5' */

/* Secondary Axle Actual Torque */
float32 vscd_v_vscVehSpdOutp_kph;      /* '<S155>/Switch' */

/* Vehicle Speed For CAN Output */
#define swc_VCOP_STOP_SEC_VAR
#include "swc_VCOP_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_VCOP_T swc_VCOP_ConstB = {
  (0ULL),                              /* '<S1>/Data Type Conversion237' */
  (0ULL),                              /* '<S1>/Data Type Conversion335' */
  0U,                                  /* '<S1>/Data Type Conversion238' */
  0U,                                  /* '<S1>/Data Type Conversion336' */
  0.0F,                                /* '<Root>/Data Type Conversion9' */
  2.0F,                                /* '<S80>/Saturation1' */
  0U,                                  /* '<S1>/Data Type Conversion11' */
  0U,                                  /* '<S1>/Data Type Conversion12' */
  0U,                                  /* '<S1>/Data Type Conversion13' */
  0U,                                  /* '<S1>/Data Type Conversion14' */
  0U,                                  /* '<S1>/Data Type Conversion23' */
  0U,                                  /* '<S1>/Data Type Conversion24' */
  0U,                                  /* '<S1>/Data Type Conversion25' */
  0U,                                  /* '<S1>/Data Type Conversion26' */
  0U,                                  /* '<S1>/Data Type Conversion33' */
  0U,                                  /* '<S1>/Data Type Conversion34' */
  0U,                                  /* '<S1>/Data Type Conversion35' */
  0U,                                  /* '<S1>/Data Type Conversion36' */
  0U,                                  /* '<S1>/Data Type Conversion44' */
  0U,                                  /* '<S1>/Data Type Conversion45' */
  0U,                                  /* '<S1>/Data Type Conversion46' */
  0U,                                  /* '<S1>/Data Type Conversion47' */
  0U,                                  /* '<S1>/Data Type Conversion66' */
  0U,                                  /* '<S1>/Data Type Conversion67' */
  0U,                                  /* '<S1>/Data Type Conversion68' */
  0U,                                  /* '<S1>/Data Type Conversion69' */
  0U,                                  /* '<S1>/Data Type Conversion77' */
  0U,                                  /* '<S1>/Data Type Conversion79' */
  0U,                                  /* '<S1>/Data Type Conversion81' */
  0U,                                  /* '<S1>/Data Type Conversion83' */
  0U,                                  /* '<S1>/Data Type Conversion92' */
  0U,                                  /* '<S1>/Data Type Conversion93' */
  0U,                                  /* '<S1>/Data Type Conversion94' */
  0U,                                  /* '<S1>/Data Type Conversion96' */
  0U,                                  /* '<S1>/Data Type Conversion466' */
  0U,                                  /* '<S1>/Data Type Conversion467' */
  2U,                                  /* '<S1>/Data Type Conversion470' */
  2U,                                  /* '<S1>/Data Type Conversion100' */
  1U,                                  /* '<S1>/Data Type Conversion101' */
  1U,                                  /* '<S1>/Data Type Conversion102' */
  0U,                                  /* '<S1>/Data Type Conversion103' */
  0U,                                  /* '<S1>/Data Type Conversion105' */
  0U,                                  /* '<S1>/Data Type Conversion119' */
  0U,                                  /* '<S1>/Data Type Conversion120' */
  0U,                                  /* '<S1>/Data Type Conversion121' */
  0U,                                  /* '<S1>/Data Type Conversion122' */
  0U,                                  /* '<S1>/Data Type Conversion131' */
  0U,                                  /* '<S1>/Data Type Conversion132' */
  0U,                                  /* '<S1>/Data Type Conversion141' */
  0U,                                  /* '<S1>/Data Type Conversion3' */
  0U,                                  /* '<S1>/Data Type Conversion4' */
  0U,                                  /* '<S1>/Data Type Conversion147' */
  0U,                                  /* '<S1>/Data Type Conversion148' */
  0U,                                  /* '<S1>/Data Type Conversion155' */
  0U,                                  /* '<S1>/Data Type Conversion157' */
  0U,                                  /* '<S1>/Data Type Conversion163' */
  0U,                                  /* '<S1>/Data Type Conversion164' */
  0U,                                  /* '<S1>/Data Type Conversion165' */
  0U,                                  /* '<S1>/Data Type Conversion167' */
  0U,                                  /* '<S1>/Data Type Conversion168' */
  0U,                                  /* '<S1>/Data Type Conversion169' */
  0U,                                  /* '<S1>/Data Type Conversion170' */
  0U,                                  /* '<S1>/Data Type Conversion175' */
  0U,                                  /* '<S1>/Data Type Conversion177' */
  0U,                                  /* '<S1>/Data Type Conversion178' */
  0U,                                  /* '<S1>/Data Type Conversion179' */
  0U,                                  /* '<S1>/Data Type Conversion181' */
  0U,                                  /* '<S1>/Data Type Conversion182' */
  0U,                                  /* '<S1>/Data Type Conversion183' */
  0U,                                  /* '<S1>/Data Type Conversion184' */
  0U,                                  /* '<S1>/Data Type Conversion185' */
  0U,                                  /* '<S1>/Data Type Conversion186' */
  0U,                                  /* '<S1>/Data Type Conversion187' */
  0U,                                  /* '<S1>/Data Type Conversion188' */
  0U,                                  /* '<S1>/Data Type Conversion193' */
  0U,                                  /* '<S1>/Data Type Conversion194' */
  0U,                                  /* '<S1>/Data Type Conversion195' */
  0U,                                  /* '<S1>/Data Type Conversion196' */
  0U,                                  /* '<S1>/Data Type Conversion201' */
  0U,                                  /* '<S1>/Data Type Conversion233' */
  0U,                                  /* '<S1>/Data Type Conversion234' */
  0U,                                  /* '<S1>/Data Type Conversion235' */
  0U,                                  /* '<S1>/Data Type Conversion236' */
  0U,                                  /* '<S1>/Data Type Conversion239' */
  0U,                                  /* '<S1>/Data Type Conversion240' */
  0U,                                  /* '<S1>/Data Type Conversion267' */
  0U,                                  /* '<S1>/Data Type Conversion271' */
  0U,                                  /* '<S1>/Data Type Conversion272' */
  0U,                                  /* '<S1>/Data Type Conversion273' */
  0U,                                  /* '<S1>/Data Type Conversion274' */
  0U,                                  /* '<S1>/Data Type Conversion281' */
  0U,                                  /* '<S1>/Data Type Conversion282' */
  0U,                                  /* '<S1>/Data Type Conversion283' */
  0U,                                  /* '<S1>/Data Type Conversion284' */
  0U,                                  /* '<S1>/Data Type Conversion313' */
  0U,                                  /* '<S1>/Data Type Conversion483' */
  0U,                                  /* '<S1>/Data Type Conversion489' */
  0U,                                  /* '<S1>/Data Type Conversion490' */
  0U,                                  /* '<S1>/Data Type Conversion491' */
  0U,                                  /* '<S1>/Data Type Conversion495' */
  40U,                                 /* '<S1>/Data Type Conversion498' */
  0U,                                  /* '<S1>/Data Type Conversion499' */
  0U,                                  /* '<S1>/Data Type Conversion500' */
  0U,                                  /* '<S1>/Data Type Conversion502' */
  0U,                                  /* '<S1>/Data Type Conversion507' */
  0U,                                  /* '<S1>/Data Type Conversion508' */
  0U,                                  /* '<S1>/Data Type Conversion540' */
  0U,                                  /* '<S1>/Data Type Conversion542' */
  0U,                                  /* '<S1>/Data Type Conversion548' */
  0U,                                  /* '<S1>/Data Type Conversion769' */
  0U,                                  /* '<S12>/Switch5' */
  0U,                                  /* '<S1>/Data Type Conversion501' */
  0U,                                  /* '<S1>/Data Type Conversion547' */
  0U,                                  /* '<S1>/Data Type Conversion539' */
  0U,                                  /* '<S1>/Data Type Conversion541' */
  40U,                                 /* '<S1>/Data Type Conversion497' */
  0,                                   /* '<Root>/Data Type Conversion8' */
  0,                                   /* '<S1>/Data Type Conversion78' */
  0,                                   /* '<S1>/Data Type Conversion80' */
  0,                                   /* '<S1>/Data Type Conversion82' */
  0,                                   /* '<S1>/Data Type Conversion85' */
  0,                                   /* '<S1>/Data Type Conversion104' */
  0,                                   /* '<S1>/Data Type Conversion106' */
  0,                                   /* '<S1>/Data Type Conversion142' */
  0,                                   /* '<S1>/Data Type Conversion156' */
  0,                                   /* '<S1>/Data Type Conversion6' */
  0,                                   /* '<S1>/Data Type Conversion166' */
  0,                                   /* '<S1>/Data Type Conversion176' */
  0,                                   /* '<S1>/Data Type Conversion180' */
  0,                                   /* '<S1>/Data Type Conversion202' */
  0,                                   /* '<S1>/Data Type Conversion268' */
  0,                                   /* '<S1>/Data Type Conversion314' */
  0,                                   /* '<S1>/Data Type Conversion484' */
  0,                                   /* '<S1>/Data Type Conversion492' */
  0,                                   /* '<S1>/Data Type Conversion496' */
  0,                                   /* '<S1>/Data Type Conversion740' */
  0,                                   /* '<S1>/Data Type Conversion741' */
  0,                                   /* '<S1>/Data Type Conversion770' */
  0,                                   /* '<S1>/Data Type Conversion55' */
  0,                                   /* '<S1>/Data Type Conversion58' */
  0,                                   /* '<S12>/Relational Operator32' */
  0,                                   /* '<S12>/Relational Operator33' */
  0,                                   /* '<S12>/Relational Operator34' */
  0,                                   /* '<S12>/Relational Operator35' */
  0,                                   /* '<S12>/Relational Operator12' */
  0,                                   /* '<S12>/Relational Operator11' */
  0,                                   /* '<S12>/Logical Operator6' */
  0,                                   /* '<S12>/Relational Operator14' */
  0,                                   /* '<S12>/Relational Operator13' */
  0                                    /* '<S12>/Logical Operator7' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_VCOP_T swc_VCOP_ARID_DEF;

/* Real-time model */
static RT_MODEL_swc_VCOP_T swc_VCOP_M_;
RT_MODEL_swc_VCOP_T *const swc_VCOP_M = &swc_VCOP_M_;
static void swc_VCOP_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_SR_latch_o(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_d_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_SR_latch_j(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_m_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_SR_latch_ol(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_p_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_SR_latch_b(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_k_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_SR_latch_oy(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_dk_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_debounce_Init(boolean *rty_flg_out);
static void swc_VCOP_debounce(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_debounce_swc_VCOP_T *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_timed_delay_Init(boolean *rty_flg_out);
static void swc_VCOP_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_VCOP_T
  *swc_VCOP__ARID_DEF_arg);
static void swc_VCOP_HVB_OutputsProcessing(void);
static void swc_VCOP_DCC_OutputsProcessing(void);
static void EAD_OutputsProcessingMot2_Init(void);
static void swc_V_EAD_OutputsProcessingMot2(void);
static void swc_VCOP_VSC_OutputsProcessing(void);
static void swc__TRA_OutputsProcessingTrsm1(void);
static void swc_VCOP_EPB_OutputsProcessing(void);
static void swc_VCOP_THM_OutputsProcessing(void);
static void swc__DSP_OutputsProcessing_Init(void);
static void swc_VCOP_DSP_OutputsProcessing(void);
static void swc_VCOP_PTL_OutputsProcessing(void);
static void swc_VCOP_VOL__VCU_Output_Layer(void);

/* Output and update for atomic system: '<S53>/SR_latch1' */
static void swc_VCOP_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_T *swc_VCOP__ARID_DEF_arg)
{
  /* Logic: '<S61>/Logical Operator3' incorporates:
   *  Logic: '<S61>/Logical Operator'
   *  Logic: '<S61>/Logical Operator1'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  hvbd_b_cntnrCtrlEna = ((swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE = hvbd_b_cntnrCtrlEna;
}

/* Output and update for atomic system: '<S54>/SR_latch' */
static void swc_VCOP_SR_latch_o(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_d_T *swc_VCOP__ARID_DEF_arg)
{
  /* Logic: '<S68>/Logical Operator3' incorporates:
   *  Logic: '<S68>/Logical Operator'
   *  Logic: '<S68>/Logical Operator1'
   *  UnitDelay: '<S68>/Unit Delay'
   */
  hvbd_b_HVRdy = ((swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S68>/Unit Delay' */
  swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE = hvbd_b_HVRdy;
}

/* Output and update for atomic system: '<S56>/SR_latch' */
static void swc_VCOP_SR_latch_j(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_m_T *swc_VCOP__ARID_DEF_arg)
{
  /* Logic: '<S74>/Logical Operator3' incorporates:
   *  Logic: '<S74>/Logical Operator'
   *  Logic: '<S74>/Logical Operator1'
   *  UnitDelay: '<S74>/Unit Delay'
   */
  hvbd_b_hcmRlyEna = ((swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                      (!rtu_flg_reset));

  /* Update for UnitDelay: '<S74>/Unit Delay' */
  swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE = hvbd_b_hcmRlyEna;
}

/* Output and update for function-call system: '<S3>/HVB_OutputsProcessing' */
static void swc_VCOP_HVB_OutputsProcessing(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator1;
  boolean rtb_LogicalOperator12;
  boolean rtb_RelationalOperator_j;
  boolean rtb_RelationalOperator2_h;
  boolean rtb_LogicalOperator8;
  boolean rtb_LogicalOperator9;
  DCDCMode rtb_LogicalOperator8_tmp;
  PmmStatus rtb_LogicalOperator1_tmp;
  uint8 rtb_RelationalOperator1_l_tmp;

  /* RelationalOperator: '<S54>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  RelationalOperator: '<S54>/Relational Operator1'
   *  RelationalOperator: '<S54>/Relational Operator2'
   *  RelationalOperator: '<S54>/Relational Operator3'
   *  RelationalOperator: '<S54>/Relational Operator4'
   *  RelationalOperator: '<S54>/Relational Operator5'
   *  RelationalOperator: '<S55>/Relational Operator2'
   *  RelationalOperator: '<S56>/Relational Operator'
   *  RelationalOperator: '<S56>/Relational Operator2'
   */
  rtb_LogicalOperator1_tmp = swc_VCOP_ARID_DEF.DataTypeConversion7;

  /* Logic: '<S54>/Logical Operator1' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S67>/Constant'
   *  RelationalOperator: '<S54>/Relational Operator'
   *  RelationalOperator: '<S54>/Relational Operator5'
   */
  rtb_LogicalOperator1 = ((rtb_LogicalOperator1_tmp == PmmStatus_BDCACACT) ||
    (rtb_LogicalOperator1_tmp == PmmStatus_LOWTEMPON));

  /* Logic: '<S54>/Logical Operator12' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  RelationalOperator: '<S54>/Relational Operator1'
   *  RelationalOperator: '<S54>/Relational Operator2'
   *  RelationalOperator: '<S54>/Relational Operator3'
   *  RelationalOperator: '<S54>/Relational Operator4'
   */
  rtb_LogicalOperator12 = ((rtb_LogicalOperator1_tmp == PmmStatus_ASSISTOPEN) ||
    (rtb_LogicalOperator1_tmp == PmmStatus_ASSISTOPENEMGY) ||
    (rtb_LogicalOperator1_tmp == PmmStatus_DCDCACT) || (rtb_LogicalOperator1_tmp
    == PmmStatus_MCUDISCHARGE));

  /* Outputs for Atomic SubSystem: '<S54>/SR_latch' */
  swc_VCOP_SR_latch_o(rtb_LogicalOperator1, rtb_LogicalOperator12,
                      &swc_VCOP_ARID_DEF.ARID_DEF_SR_latch_p);

  /* End of Outputs for SubSystem: '<S54>/SR_latch' */

  /* Switch: '<S55>/Switch1' incorporates:
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S71>/Constant'
   *  RelationalOperator: '<S55>/Relational Operator2'
   *  RelationalOperator: '<S69>/Compare'
   *  RelationalOperator: '<S70>/Compare'
   *  Switch: '<S55>/Switch2'
   *  Switch: '<S55>/Switch3'
   */
  if (rtb_LogicalOperator1_tmp == PmmStatus_INTELCHG) {
    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S55>/Constant39'
     */
    hvbd_st_hvbIntelChgSt = ((uint8)1U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion58 == ((uint8)8U)) {
    /* Switch: '<S55>/Switch2' incorporates:
     *  Constant: '<S55>/Constant1'
     *  Switch: '<S55>/Switch1'
     */
    hvbd_st_hvbIntelChgSt = ((uint8)2U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion58 == ((uint8)0U)) {
    /* Switch: '<S55>/Switch3' incorporates:
     *  Constant: '<S55>/Constant2'
     *  Switch: '<S55>/Switch1'
     *  Switch: '<S55>/Switch2'
     */
    hvbd_st_hvbIntelChgSt = ((uint8)0U);
  } else {
    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S55>/Constant3'
     *  Switch: '<S55>/Switch2'
     *  Switch: '<S55>/Switch3'
     */
    hvbd_st_hvbIntelChgSt = ((uint8)3U);
  }

  /* End of Switch: '<S55>/Switch1' */

  /* RelationalOperator: '<S56>/Relational Operator' incorporates:
   *  Constant: '<S72>/Constant'
   */
  rtb_RelationalOperator_j = (rtb_LogicalOperator1_tmp == PmmStatus_HCMWAKEUP);

  /* RelationalOperator: '<S56>/Relational Operator2' incorporates:
   *  Constant: '<S73>/Constant'
   */
  rtb_RelationalOperator2_h = (rtb_LogicalOperator1_tmp == PmmStatus_AFTERRUN);

  /* Outputs for Atomic SubSystem: '<S56>/SR_latch' */
  swc_VCOP_SR_latch_j(rtb_RelationalOperator_j, rtb_RelationalOperator2_h,
                      &swc_VCOP_ARID_DEF.ARID_DEF_SR_latch_b);

  /* End of Outputs for SubSystem: '<S56>/SR_latch' */

  /* SignalConversion: '<S10>/Signal Conversion' */
  hvbd_b_sdcacEna = swc_VCOP_ARID_DEF.DataTypeConversion54;

  /* RelationalOperator: '<S53>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion515'
   *  RelationalOperator: '<S53>/Relational Operator1'
   */
  rtb_LogicalOperator8_tmp = swc_VCOP_ARID_DEF.DataTypeConversion515;

  /* Logic: '<S53>/Logical Operator8' incorporates:
   *  Constant: '<S53>/Constant36'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S60>/Constant'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator6'
   *  RelationalOperator: '<S57>/Compare'
   */
  rtb_LogicalOperator8 = ((swc_VCOP_ARID_DEF.DataTypeConversion57 >
    hvbc_pwr_cntnrEnaThld_kW) && (swc_VCOP_ARID_DEF.DataTypeConversion59 ==
    ((uint8)0U)) && (rtb_LogicalOperator8_tmp == DCDCMode_ACTIVE));

  /* Logic: '<S53>/Logical Operator9' incorporates:
   *  Constant: '<S53>/Constant37'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S60>/Constant'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator1'
   *  RelationalOperator: '<S53>/Relational Operator7'
   *  RelationalOperator: '<S58>/Compare'
   */
  rtb_LogicalOperator9 = ((swc_VCOP_ARID_DEF.DataTypeConversion57 <
    hvbc_pwr_cntnrDisThld_kW) || (swc_VCOP_ARID_DEF.DataTypeConversion59 ==
    ((uint8)1U)) || (rtb_LogicalOperator8_tmp != DCDCMode_ACTIVE));

  /* Outputs for Atomic SubSystem: '<S53>/SR_latch1' */
  swc_VCOP_SR_latch(rtb_LogicalOperator8, rtb_LogicalOperator9,
                    &swc_VCOP_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S53>/SR_latch1' */

  /* SignalConversion generated from: '<S10>/bmsd_e_modeTgt' */
  swc_VCOP_ARID_DEF.bmsd_e_modeTgt = swc_VCOP_ARID_DEF.DataTypeConversion92;

  /* RelationalOperator: '<S10>/Relational Operator1' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in199'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  rtb_RelationalOperator1_l_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_flgFctCfgAccy();

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Inport generated from: '<Root>/vcib_VCIP_in199'
   *  RelationalOperator: '<S10>/Relational Operator'
   *  RelationalOperator: '<S10>/Relational Operator1'
   *  Switch: '<S10>/Switch1'
   *  Switch: '<S10>/Switch2'
   *  Switch: '<S10>/Switch3'
   */
  if (rtb_RelationalOperator1_l_tmp == ((uint8)1U)) {
    /* Switch: '<S10>/Switch' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in31'
     */
    swc_VCOP_ARID_DEF.Switch_p =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw();

    /* Switch: '<S10>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in36'
     */
    swc_VCOP_ARID_DEF.Switch2_g =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyHvOnCmd();
  } else if (rtb_RelationalOperator1_l_tmp == ((uint8)2U)) {
    /* Switch: '<S10>/Switch1' incorporates:
     *  Inport generated from: '<Root>/vcsb_THSM_in50'
     *  Switch: '<S10>/Switch'
     */
    swc_VCOP_ARID_DEF.Switch_p =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch();

    /* Switch: '<S10>/Switch3' incorporates:
     *  Inport generated from: '<Root>/vcsb_THSM_in52'
     *  Switch: '<S10>/Switch2'
     */
    swc_VCOP_ARID_DEF.Switch2_g =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna3HW();
  } else {
    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/Constant3'
     *  Switch: '<S10>/Switch1'
     */
    swc_VCOP_ARID_DEF.Switch_p = ((uint8)0U);

    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/Constant4'
     *  Switch: '<S10>/Switch3'
     */
    swc_VCOP_ARID_DEF.Switch2_g = false;
  }

  /* End of Switch: '<S10>/Switch' */
}

/* Output and update for function-call system: '<S3>/DCC_OutputsProcessing' */
static void swc_VCOP_DCC_OutputsProcessing(void)
{
  DCDCMode dccd_b_dcdcEna_tmp;
  uint8 rtb_Saturation1;

  /* Outputs for Atomic SubSystem: '<S6>/state_mapping' */
  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion515'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   */
  dccd_b_dcdcEna_tmp = swc_VCOP_ARID_DEF.DataTypeConversion515;

  /* End of Outputs for SubSystem: '<S6>/state_mapping' */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S17>/Constant'
   */
  dccd_b_dcdcEna = (dccd_b_dcdcEna_tmp == DCDCMode_ACTIVE);

  /* Outputs for Atomic SubSystem: '<S6>/state_mapping' */
  /* Saturate: '<S18>/Saturation1' */
  if (dccd_b_dcdcEna_tmp <= ((uint8)7U)) {
    /* Saturate: '<S18>/Saturation1' */
    rtb_Saturation1 = dccd_b_dcdcEna_tmp;
  } else {
    /* Saturate: '<S18>/Saturation1' */
    rtb_Saturation1 = ((uint8)7U);
  }

  /* End of Saturate: '<S18>/Saturation1' */

  /* Switch: '<S18>/Switch' incorporates:
   *  RelationalOperator: '<S18>/Relational Operator'
   */
  if (dccd_b_dcdcEna_tmp > rtb_Saturation1) {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S6>/Constant3'
     */
    dccd_st_modeReq = dccc_e_dcdcReqModeDflt;
  } else {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S6>/Constant1'
     *  MultiPortSwitch: '<S18>/Index Vector'
     */
    dccd_st_modeReq = DCC_REQMODE[rtb_Saturation1];
  }

  /* End of Switch: '<S18>/Switch' */
  /* End of Outputs for SubSystem: '<S6>/state_mapping' */

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in28'
   */
  dccd_pwr_outPwrLmt_KW = (float32)
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_dccd_pct_DCDCPwrLmt();
}

/* Output and update for atomic system: '<S40>/SR_latch' */
static void swc_VCOP_SR_latch_ol(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_p_T *swc_VCOP__ARID_DEF_arg)
{
  /* Logic: '<S46>/Logical Operator3' incorporates:
   *  Logic: '<S46>/Logical Operator'
   *  Logic: '<S46>/Logical Operator1'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  eadd_b_ead2Ena = ((swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                    (!rtu_flg_reset));

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE = eadd_b_ead2Ena;
}

/* System initialize for function-call system: '<S3>/EAD_OutputsProcessingMot2' */
static void EAD_OutputsProcessingMot2_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
  swc_VCOP_ARID_DEF.UnitDelay_DSTATE = volc_tq_rgnDisTqThd_Nm;
}

/* Output and update for function-call system: '<S3>/EAD_OutputsProcessingMot2' */
static void swc_V_EAD_OutputsProcessingMot2(void)
{
  /* local block i/o variables */
  boolean rtb_RelationalOperator_d;
  boolean rtb_LogicalOperator12_o;
  float64 rtb_Switch6;
  PmmStatus rtb_RelationalOperator_d_tmp;
  uint8 rtb_DataTypeConversion_ch;
  uint8 rtb_Saturation1;

  /* Outputs for Atomic SubSystem: '<S8>/state_mapping' */
  /* DataTypeConversion: '<S42>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  rtb_DataTypeConversion_ch = swc_VCOP_ARID_DEF.DataTypeConversion6;

  /* Saturate: '<S42>/Saturation1' */
  if (rtb_DataTypeConversion_ch <= ((uint8)10U)) {
    /* Saturate: '<S42>/Saturation1' */
    rtb_Saturation1 = rtb_DataTypeConversion_ch;
  } else {
    /* Saturate: '<S42>/Saturation1' */
    rtb_Saturation1 = ((uint8)10U);
  }

  /* End of Saturate: '<S42>/Saturation1' */

  /* Switch: '<S42>/Switch' incorporates:
   *  RelationalOperator: '<S42>/Relational Operator'
   */
  if (rtb_DataTypeConversion_ch > rtb_Saturation1) {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S8>/Constant5'
     */
    eadd_st_inv2EmCtrlMod = eadc_st_inv2ModeReqDft;
  } else {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S8>/Constant'
     *  MultiPortSwitch: '<S42>/Index Vector'
     */
    eadd_st_inv2EmCtrlMod = EAD2_REQMODE[rtb_Saturation1];
  }

  /* End of Switch: '<S42>/Switch' */
  /* End of Outputs for SubSystem: '<S8>/state_mapping' */

  /* RelationalOperator: '<S40>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  RelationalOperator: '<S40>/Relational Operator1'
   *  RelationalOperator: '<S40>/Relational Operator2'
   *  RelationalOperator: '<S41>/Relational Operator'
   *  Switch: '<S41>/Switch5'
   */
  rtb_RelationalOperator_d_tmp = swc_VCOP_ARID_DEF.DataTypeConversion7;

  /* RelationalOperator: '<S40>/Relational Operator' incorporates:
   *  Constant: '<S43>/Constant'
   */
  rtb_RelationalOperator_d = (rtb_RelationalOperator_d_tmp == PmmStatus_MCUACT);

  /* Logic: '<S40>/Logical Operator12' incorporates:
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  RelationalOperator: '<S40>/Relational Operator1'
   *  RelationalOperator: '<S40>/Relational Operator2'
   */
  rtb_LogicalOperator12_o = ((rtb_RelationalOperator_d_tmp == PmmStatus_MCUDEACT)
    || (rtb_RelationalOperator_d_tmp == PmmStatus_HVDEVICEDEACTEMGY) ||
    swc_VCOP_ConstB.DataTypeConversion8);

  /* Outputs for Atomic SubSystem: '<S40>/SR_latch' */
  swc_VCOP_SR_latch_ol(rtb_RelationalOperator_d, rtb_LogicalOperator12_o,
                       &swc_VCOP_ARID_DEF.ARID_DEF_SR_latch_c);

  /* End of Outputs for SubSystem: '<S40>/SR_latch' */

  /* Switch: '<S39>/Switch1' */
  if (eadd_b_ead2Ena) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S39>/Constant5'
     */
    if (eadc_b_enbSflEad2TqLmt) {
      /* Switch: '<S39>/Switch1' */
      eadd_tq_mot2TgtTqReqOutp_Nm = swc_VCOP_ConstB.DataTypeConversion9;
    } else {
      /* Switch: '<S39>/Switch1' */
      eadd_tq_mot2TgtTqReqOutp_Nm = swc_VCOP_ARID_DEF.DataTypeConversion10;
    }

    /* End of Switch: '<S39>/Switch' */
  } else {
    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S39>/Constant3'
     */
    eadd_tq_mot2TgtTqReqOutp_Nm = ((float32)TRQ_ZERO);
  }

  /* End of Switch: '<S39>/Switch1' */

  /* SignalConversion: '<S39>/Signal Conversion2' */
  eadd_tq_mot2TgtTqReqOutpAbs_Nm = eadd_tq_mot2TgtTqReqOutp_Nm;

  /* Switch: '<S41>/Switch6' incorporates:
   *  Constant: '<S41>/Constant34'
   */
  if (eadc_b_newWkModEnb) {
    /* Switch: '<S41>/Switch6' incorporates:
     *  UnitDelay: '<S41>/Unit Delay'
     */
    rtb_Switch6 = swc_VCOP_ARID_DEF.UnitDelay_DSTATE;
  } else {
    /* Switch: '<S41>/Switch6' */
    rtb_Switch6 = swc_VCOP_ARID_DEF.DataTypeConversion11;
  }

  /* End of Switch: '<S41>/Switch6' */

  /* Relay: '<S41>/Relay' */
  swc_VCOP_ARID_DEF.Relay_Mode = ((rtb_Switch6 >= volc_tq_rgnDisTqThd_Nm) ||
    ((rtb_Switch6 > volc_tq_rgnEnbTqThd_Nm) && swc_VCOP_ARID_DEF.Relay_Mode));

  /* Switch: '<S41>/Switch5' incorporates:
   *  Constant: '<S47>/Constant'
   *  RelationalOperator: '<S41>/Relational Operator'
   *  Switch: '<S41>/Switch3'
   */
  if (swc_VCOP_ARID_DEF.DataTypeConversion4 != 0.0) {
    /* Switch: '<S41>/Switch5' incorporates:
     *  Constant: '<S41>/LvCutOff'
     */
    eadd_st_inv2EmWMod = ((uint8)4U);
  } else if (rtb_RelationalOperator_d_tmp == PmmStatus_MCUDISCHARGE) {
    /* Switch: '<S41>/Switch3' incorporates:
     *  Constant: '<S41>/Discharge'
     *  Switch: '<S41>/Switch5'
     */
    eadd_st_inv2EmWMod = ((uint8)6U);
  } else {
    DriveDir tmp_0;

    /* RelationalOperator: '<S41>/Relational Operator5' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     *  RelationalOperator: '<S41>/Relational Operator1'
     *  RelationalOperator: '<S41>/Relational Operator2'
     *  RelationalOperator: '<S41>/Relational Operator3'
     *  Switch: '<S41>/Switch'
     *  Switch: '<S41>/Switch2'
     *  Switch: '<S41>/Switch3'
     *  Switch: '<S41>/Switch4'
     */
    tmp_0 = swc_VCOP_ARID_DEF.DataTypeConversion5;

    /* Switch: '<S41>/Switch4' incorporates:
     *  Constant: '<S51>/Constant'
     *  RelationalOperator: '<S41>/Relational Operator5'
     *  Relay: '<S41>/Relay'
     *  Switch: '<S41>/Switch3'
     */
    if (tmp_0 == DriveDir_NO_DRIVE) {
      /* Switch: '<S41>/Switch5' incorporates:
       *  Constant: '<S41>/Neutral '
       *  Switch: '<S41>/Switch4'
       */
      eadd_st_inv2EmWMod = ((uint8)0U);
    } else {
      boolean tmp;
      if (swc_VCOP_ARID_DEF.Relay_Mode) {
        /* Relay: '<S41>/Relay' */
        tmp = false;
      } else {
        /* Relay: '<S41>/Relay' */
        tmp = true;
      }

      /* Switch: '<S41>/Switch2' incorporates:
       *  Constant: '<S49>/Constant'
       *  Constant: '<S50>/Constant'
       *  Logic: '<S41>/Logical Operator1'
       *  RelationalOperator: '<S41>/Relational Operator1'
       *  RelationalOperator: '<S41>/Relational Operator2'
       *  RelationalOperator: '<S41>/Relational Operator3'
       *  Relay: '<S41>/Relay'
       *  Switch: '<S41>/Switch'
       *  Switch: '<S41>/Switch1'
       */
      if ((tmp_0 == DriveDir_FORWARD) && tmp) {
        /* Switch: '<S41>/Switch5' incorporates:
         *  Constant: '<S41>/Regen'
         *  Switch: '<S41>/Switch2'
         *  Switch: '<S41>/Switch4'
         */
        eadd_st_inv2EmWMod = ((uint8)3U);
      } else if (tmp_0 == DriveDir_FORWARD) {
        /* Switch: '<S41>/Switch' incorporates:
         *  Constant: '<S41>/Drive'
         *  Switch: '<S41>/Switch5'
         */
        eadd_st_inv2EmWMod = ((uint8)1U);
      } else if (tmp_0 == DriveDir_REVERSE) {
        /* Switch: '<S41>/Switch1' incorporates:
         *  Constant: '<S41>/Reverse'
         *  Switch: '<S41>/Switch'
         *  Switch: '<S41>/Switch5'
         */
        eadd_st_inv2EmWMod = ((uint8)2U);
      } else {
        /* Switch: '<S41>/Switch5' incorporates:
         *  Constant: '<S41>/Default'
         *  Switch: '<S41>/Switch'
         *  Switch: '<S41>/Switch1'
         */
        eadd_st_inv2EmWMod = ((uint8)15U);
      }
    }
  }

  /* SignalConversion: '<S8>/Signal Conversion' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  eadd_st_ead2PTImmoRlsSts =
    Rte_IRead_swc_VCOP_Step_vcsb_ATAU_pmmd_b_ePTRelease_flg();

  /* Update for UnitDelay: '<S41>/Unit Delay' */
  swc_VCOP_ARID_DEF.UnitDelay_DSTATE = swc_VCOP_ARID_DEF.DataTypeConversion11;
}

/* Output and update for function-call system: '<S3>/VSC_OutputsProcessing' */
static void swc_VCOP_VSC_OutputsProcessing(void)
{
  float32 rtb_Divide5;
  float32 u0;
  boolean rtb_RelationalOperator1_k;

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/Constant2'
   *  Constant: '<S154>/Constant3'
   *  Inport generated from: '<Root>/vcib_VCIP_in47'
   *  RelationalOperator: '<S154>/Relational Operator2'
   */
  if (Rte_IRead_swc_VCOP_Step_vcib_VCIP_trad_st_trsm2GearAct() == ((uint8)0U)) {
    u0 = 0.0F;
  } else {
    u0 = swc_VCOP_ARID_DEF.DataTypeConversion62;
  }

  /* Product: '<S154>/Divide5' incorporates:
   *  Switch: '<S154>/Switch1'
   */
  rtb_Divide5 = u0 * swc_VCOP_ARID_DEF.DataTypeConversion103;

  /* RelationalOperator: '<S154>/Relational Operator1' incorporates:
   *  Constant: '<S156>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  rtb_RelationalOperator1_k = (swc_VCOP_ARID_DEF.DataTypeConversion5 ==
    DriveDir_REVERSE);

  /* Switch: '<S154>/Switch4' incorporates:
   *  Gain: '<S154>/Gain3'
   */
  if (rtb_RelationalOperator1_k) {
    u0 = 0.0F * rtb_Divide5;
  } else {
    u0 = rtb_Divide5;
  }

  /* MinMax: '<S154>/Min' incorporates:
   *  Constant: '<S154>/Constant1'
   *  Switch: '<S154>/Switch4'
   */
  u0 = fminf(u0, 0.0F);

  /* Saturate: '<S154>/Saturation1' */
  if (u0 > 0.0F) {
    /* Saturate: '<S154>/Saturation1' */
    vscd_tq_axle2ActRgnTq_Nm = 0.0F;
  } else if (u0 < (-4000.0F)) {
    /* Saturate: '<S154>/Saturation1' */
    vscd_tq_axle2ActRgnTq_Nm = -4000.0F;
  } else {
    /* Saturate: '<S154>/Saturation1' */
    vscd_tq_axle2ActRgnTq_Nm = u0;
  }

  /* End of Saturate: '<S154>/Saturation1' */

  /* Switch: '<S154>/Switch3' */
  if (rtb_RelationalOperator1_k) {
    /* Rounding: '<S155>/Fix' incorporates:
     *  Gain: '<S154>/Gain1'
     */
    rtb_Divide5 *= 1.0F;
  }

  /* End of Switch: '<S154>/Switch3' */

  /* Saturate: '<S154>/Saturation5' */
  if (rtb_Divide5 > 4000.0F) {
    /* Saturate: '<S154>/Saturation5' */
    vscd_tq_axle2ActTq_Nm = 4000.0F;
  } else if (rtb_Divide5 < (-4000.0F)) {
    /* Saturate: '<S154>/Saturation5' */
    vscd_tq_axle2ActTq_Nm = -4000.0F;
  } else {
    /* Saturate: '<S154>/Saturation5' */
    vscd_tq_axle2ActTq_Nm = rtb_Divide5;
  }

  /* End of Saturate: '<S154>/Saturation5' */

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S155>/Constant'
   *  RelationalOperator: '<S155>/Relational Operator'
   *  Rounding: '<S155>/Fix'
   *  Sum: '<S155>/Add'
   */
  if (swc_VCOP_ARID_DEF.DataTypeConversion61 - truncf
      (swc_VCOP_ARID_DEF.DataTypeConversion61) >= 0.5F) {
    /* Switch: '<S155>/Switch' */
    vscd_v_vscVehSpdOutp_kph = swc_VCOP_ARID_DEF.DataTypeConversion61;
  } else {
    /* Switch: '<S155>/Switch' incorporates:
     *  Rounding: '<S155>/Round'
     */
    vscd_v_vscVehSpdOutp_kph = roundf(swc_VCOP_ARID_DEF.DataTypeConversion61);
  }

  /* End of Switch: '<S155>/Switch' */
}

/* Output and update for function-call system: '<S3>/TRA_OutputsProcessingTrsm1' */
static void swc__TRA_OutputsProcessingTrsm1(void)
{
  GearLeverPos tmp;

  /* RelationalOperator: '<S149>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion524'
   *  RelationalOperator: '<S149>/Relational Operator1'
   *  RelationalOperator: '<S149>/Relational Operator2'
   *  RelationalOperator: '<S149>/Relational Operator3'
   *  Switch: '<S149>/Switch'
   *  Switch: '<S149>/Switch1'
   *  Switch: '<S149>/Switch4'
   */
  tmp = swc_VCOP_ARID_DEF.DataTypeConversion524;

  /* Switch: '<S149>/Switch' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S151>/Constant'
   *  Constant: '<S152>/Constant'
   *  Constant: '<S153>/Constant'
   *  RelationalOperator: '<S149>/Relational Operator'
   *  RelationalOperator: '<S149>/Relational Operator1'
   *  RelationalOperator: '<S149>/Relational Operator2'
   *  RelationalOperator: '<S149>/Relational Operator3'
   *  Switch: '<S149>/Switch1'
   *  Switch: '<S149>/Switch2'
   *  Switch: '<S149>/Switch4'
   */
  if (tmp == GearLeverPos_NEUTRAL) {
    /* Switch: '<S149>/Switch' incorporates:
     *  Constant: '<S149>/Constant'
     */
    trad_st_gearLvrPos = ((uint8)0U);
  } else if (tmp == GearLeverPos_FWD_DRIVE) {
    /* Switch: '<S149>/Switch1' incorporates:
     *  Constant: '<S149>/Constant1'
     *  Switch: '<S149>/Switch'
     */
    trad_st_gearLvrPos = ((uint8)12U);
  } else if (tmp == GearLeverPos_REV_DRIVE) {
    /* Switch: '<S149>/Switch4' incorporates:
     *  Constant: '<S149>/Constant2'
     *  Switch: '<S149>/Switch'
     *  Switch: '<S149>/Switch1'
     */
    trad_st_gearLvrPos = ((uint8)11U);
  } else if (tmp == GearLeverPos_PARKING) {
    /* Switch: '<S149>/Switch2' incorporates:
     *  Constant: '<S149>/Constant3'
     *  Switch: '<S149>/Switch'
     *  Switch: '<S149>/Switch1'
     *  Switch: '<S149>/Switch4'
     */
    trad_st_gearLvrPos = ((uint8)10U);
  } else {
    /* Switch: '<S149>/Switch' incorporates:
     *  Constant: '<S149>/Constant4'
     *  Switch: '<S149>/Switch1'
     *  Switch: '<S149>/Switch2'
     *  Switch: '<S149>/Switch4'
     */
    trad_st_gearLvrPos = ((uint8)15U);
  }
}

/* Output and update for function-call system: '<S3>/EPB_OutputsProcessing' */
static void swc_VCOP_EPB_OutputsProcessing(void)
{
  uint8 rtb_DataTypeConversion_h;
  uint8 rtb_Saturation1;

  /* Outputs for Atomic SubSystem: '<S9>/state_mapping' */
  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion52'
   */
  rtb_DataTypeConversion_h = swc_VCOP_ARID_DEF.DataTypeConversion52;

  /* Saturate: '<S52>/Saturation1' */
  if (rtb_DataTypeConversion_h <= ((uint8)5U)) {
    /* Saturate: '<S52>/Saturation1' */
    rtb_Saturation1 = rtb_DataTypeConversion_h;
  } else {
    /* Saturate: '<S52>/Saturation1' */
    rtb_Saturation1 = ((uint8)5U);
  }

  /* End of Saturate: '<S52>/Saturation1' */

  /* Switch: '<S52>/Switch' incorporates:
   *  RelationalOperator: '<S52>/Relational Operator'
   */
  if (rtb_DataTypeConversion_h > rtb_Saturation1) {
    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S9>/Constant2'
     */
    epbd_st_parkingSts = epbc_st_parkStatusDflt;
  } else {
    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S9>/Constant'
     *  MultiPortSwitch: '<S52>/Index Vector'
     */
    epbd_st_parkingSts = EPB_PARKSTS[rtb_Saturation1];
  }

  /* End of Switch: '<S52>/Switch' */
  /* End of Outputs for SubSystem: '<S9>/state_mapping' */
}

/* Output and update for atomic system: '<S103>/SR_latch' */
static void swc_VCOP_SR_latch_b(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_k_T *swc_VCOP__ARID_DEF_arg)
{
  /* Logic: '<S138>/Logical Operator3' incorporates:
   *  Logic: '<S138>/Logical Operator'
   *  Logic: '<S138>/Logical Operator1'
   *  UnitDelay: '<S138>/Unit Delay'
   */
  thmd_b_highSpdFanRlyReq = ((swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE = thmd_b_highSpdFanRlyReq;
}

/* Output and update for atomic system: '<S107>/SR_latch' */
static void swc_VCOP_SR_latch_oy(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_VCOP_dk_T *swc_VCOP__ARID_DEF_arg)
{
  /* Logic: '<S148>/Logical Operator3' incorporates:
   *  Logic: '<S148>/Logical Operator'
   *  Logic: '<S148>/Logical Operator1'
   *  UnitDelay: '<S148>/Unit Delay'
   */
  thmd_b_motFanRlyReq = ((swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S148>/Unit Delay' */
  swc_VCOP__ARID_DEF_arg->UnitDelay_DSTATE = thmd_b_motFanRlyReq;
}

/* Output and update for function-call system: '<S3>/THM_OutputsProcessing' */
static void swc_VCOP_THM_OutputsProcessing(void)
{
  /* local block i/o variables */
  float64 rtb_SignalConversion4;
  float32 rtb_SignalConversion3;
  uint8 rtb_Switch8;
  uint8 rtb_Switch8_e;
  boolean rtb_LogicalOperator12_a;
  boolean rtb_LogicalOperator12_l;
  float32 u0;
  PmmStatus rtb_LogicalOperator12_a_tmp;

  /* MultiPortSwitch: '<S85>/Multiport Switch1' incorporates:
   *  Constant: '<S85>/Constant7'
   */
  switch (((uint8)VEH_SWT_INF)) {
   case 0:
    /* MultiPortSwitch: '<S85>/Multiport Switch1' incorporates:
     *  Constant: '<S85>/Constant9'
     */
    thmd_n_ats1PwmReq_pct = 0.0F;

    /* MultiPortSwitch: '<S100>/Multiport Switch1' */
    thmd_n_fan1TgtSpdOutp_pct = swc_VCOP_ARID_DEF.DataTypeConversion49;

    /* MultiPortSwitch: '<S83>/Multiport Switch1' incorporates:
     *  Constant: '<S83>/Constant1'
     */
    thmd_n_12vAts1PwmReq_pct = 0.0F;

    /* MultiPortSwitch: '<S101>/Multiport Switch1' */
    thmd_n_fan2TgtSpdOutp_pct = swc_VCOP_ARID_DEF.DataTypeConversion50;

    /* MultiPortSwitch: '<S84>/Multiport Switch1' incorporates:
     *  Constant: '<S84>/Constant9'
     */
    thmd_st_ats1Ena = ((uint8)0U);
    break;

   case 1:
    /* MultiPortSwitch: '<S85>/Multiport Switch1' incorporates:
     *  Constant: '<S85>/Constant9'
     */
    thmd_n_ats1PwmReq_pct = 0.0F;

    /* MultiPortSwitch: '<S100>/Multiport Switch1' */
    thmd_n_fan1TgtSpdOutp_pct = swc_VCOP_ARID_DEF.DataTypeConversion49;

    /* MultiPortSwitch: '<S83>/Multiport Switch1' incorporates:
     *  Constant: '<S83>/Constant1'
     */
    thmd_n_12vAts1PwmReq_pct = 0.0F;

    /* MultiPortSwitch: '<S101>/Multiport Switch1' */
    thmd_n_fan2TgtSpdOutp_pct = swc_VCOP_ARID_DEF.DataTypeConversion50;

    /* MultiPortSwitch: '<S84>/Multiport Switch1' incorporates:
     *  Constant: '<S84>/Constant9'
     */
    thmd_st_ats1Ena = ((uint8)0U);
    break;

   case 2:
    /* MultiPortSwitch: '<S85>/Multiport Switch1' incorporates:
     *  Constant: '<S85>/Constant9'
     */
    thmd_n_ats1PwmReq_pct = 0.0F;

    /* MultiPortSwitch: '<S100>/Multiport Switch1' */
    thmd_n_fan1TgtSpdOutp_pct = swc_VCOP_ARID_DEF.DataTypeConversion49;

    /* MultiPortSwitch: '<S83>/Multiport Switch1' incorporates:
     *  Constant: '<S83>/Constant1'
     */
    thmd_n_12vAts1PwmReq_pct = 0.0F;

    /* MultiPortSwitch: '<S101>/Multiport Switch1' */
    thmd_n_fan2TgtSpdOutp_pct = swc_VCOP_ARID_DEF.DataTypeConversion50;

    /* MultiPortSwitch: '<S84>/Multiport Switch1' incorporates:
     *  Constant: '<S84>/Constant9'
     */
    thmd_st_ats1Ena = ((uint8)0U);
    break;

   case 3:
    /* MultiPortSwitch: '<S85>/Multiport Switch1' */
    thmd_n_ats1PwmReq_pct = swc_VCOP_ARID_DEF.DataTypeConversion49;

    /* MultiPortSwitch: '<S100>/Multiport Switch1' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    thmd_n_fan1TgtSpdOutp_pct = 0.0F;

    /* MultiPortSwitch: '<S83>/Multiport Switch1' */
    thmd_n_12vAts1PwmReq_pct = swc_VCOP_ARID_DEF.DataTypeConversion50;

    /* MultiPortSwitch: '<S101>/Multiport Switch1' incorporates:
     *  Constant: '<S101>/Constant2'
     */
    thmd_n_fan2TgtSpdOutp_pct = 0.0F;

    /* MultiPortSwitch: '<S84>/Multiport Switch1' incorporates:
     *  DataTypeConversion: '<S84>/Data Type Conversion'
     */
    thmd_st_ats1Ena = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion44;
    break;

   case 4:
    /* MultiPortSwitch: '<S85>/Multiport Switch1' */
    thmd_n_ats1PwmReq_pct = swc_VCOP_ARID_DEF.DataTypeConversion49;

    /* MultiPortSwitch: '<S100>/Multiport Switch1' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    thmd_n_fan1TgtSpdOutp_pct = 0.0F;

    /* MultiPortSwitch: '<S83>/Multiport Switch1' */
    thmd_n_12vAts1PwmReq_pct = swc_VCOP_ARID_DEF.DataTypeConversion50;

    /* MultiPortSwitch: '<S101>/Multiport Switch1' incorporates:
     *  Constant: '<S101>/Constant2'
     */
    thmd_n_fan2TgtSpdOutp_pct = 0.0F;

    /* MultiPortSwitch: '<S84>/Multiport Switch1' incorporates:
     *  DataTypeConversion: '<S84>/Data Type Conversion'
     */
    thmd_st_ats1Ena = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion44;
    break;

   default:
    /* MultiPortSwitch: '<S85>/Multiport Switch1' */
    thmd_n_ats1PwmReq_pct = swc_VCOP_ARID_DEF.DataTypeConversion49;

    /* MultiPortSwitch: '<S100>/Multiport Switch1' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    thmd_n_fan1TgtSpdOutp_pct = 0.0F;

    /* MultiPortSwitch: '<S83>/Multiport Switch1' */
    thmd_n_12vAts1PwmReq_pct = swc_VCOP_ARID_DEF.DataTypeConversion50;

    /* MultiPortSwitch: '<S101>/Multiport Switch1' incorporates:
     *  Constant: '<S101>/Constant2'
     */
    thmd_n_fan2TgtSpdOutp_pct = 0.0F;

    /* MultiPortSwitch: '<S84>/Multiport Switch1' incorporates:
     *  DataTypeConversion: '<S84>/Data Type Conversion'
     */
    thmd_st_ats1Ena = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion44;
    break;
  }

  /* End of MultiPortSwitch: '<S85>/Multiport Switch1' */

  /* RelationalOperator: '<S103>/Relational Operator1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   *  RelationalOperator: '<S103>/Relational Operator2'
   *  RelationalOperator: '<S107>/Relational Operator1'
   *  RelationalOperator: '<S107>/Relational Operator2'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator10'
   *  RelationalOperator: '<S13>/Relational Operator11'
   *  RelationalOperator: '<S13>/Relational Operator12'
   *  RelationalOperator: '<S13>/Relational Operator2'
   *  RelationalOperator: '<S13>/Relational Operator3'
   *  RelationalOperator: '<S13>/Relational Operator4'
   *  RelationalOperator: '<S13>/Relational Operator5'
   *  RelationalOperator: '<S13>/Relational Operator6'
   *  RelationalOperator: '<S13>/Relational Operator7'
   *  RelationalOperator: '<S13>/Relational Operator8'
   *  RelationalOperator: '<S13>/Relational Operator9'
   */
  rtb_LogicalOperator12_a_tmp = swc_VCOP_ARID_DEF.DataTypeConversion7;

  /* Logic: '<S103>/Logical Operator12' incorporates:
   *  Constant: '<S136>/Constant'
   *  Constant: '<S137>/Constant'
   *  Inport generated from: '<Root>/vcsb_THSM_in45'
   *  Logic: '<S103>/Logical Operator2'
   *  RelationalOperator: '<S103>/Relational Operator1'
   *  RelationalOperator: '<S103>/Relational Operator2'
   */
  rtb_LogicalOperator12_a =
    ((!Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_fanRly2Req()) ||
     (rtb_LogicalOperator12_a_tmp == PmmStatus_INIT) ||
     (rtb_LogicalOperator12_a_tmp == PmmStatus_OFF));

  /* Outputs for Atomic SubSystem: '<S103>/SR_latch' */
  /* Inport generated from: '<Root>/vcsb_THSM_in45' */
  swc_VCOP_SR_latch_b(Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_fanRly2Req(),
                      rtb_LogicalOperator12_a,
                      &swc_VCOP_ARID_DEF.ARID_DEF_SR_latch_k);

  /* End of Outputs for SubSystem: '<S103>/SR_latch' */

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  Constant: '<S96>/Constant'
   *  Constant: '<S97>/Constant'
   *  Constant: '<S98>/Constant'
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator10'
   *  RelationalOperator: '<S13>/Relational Operator11'
   *  RelationalOperator: '<S13>/Relational Operator12'
   *  RelationalOperator: '<S13>/Relational Operator2'
   *  RelationalOperator: '<S13>/Relational Operator3'
   *  RelationalOperator: '<S13>/Relational Operator4'
   *  RelationalOperator: '<S13>/Relational Operator5'
   *  RelationalOperator: '<S13>/Relational Operator6'
   *  RelationalOperator: '<S13>/Relational Operator7'
   *  RelationalOperator: '<S13>/Relational Operator8'
   *  RelationalOperator: '<S13>/Relational Operator9'
   */
  thmd_b_MHGVEna = ((rtb_LogicalOperator12_a_tmp == PmmStatus_DRIVE) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_CHARGE) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_STANDBYDRV) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_STANDBYDRVCONV) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_IMMOCHECK) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_SDCACACT) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_BDCACACT) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_MCUACT) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_VEHSTART) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_SHUTDOWNWAIT) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_HVDEVICEDEACT) ||
                    (rtb_LogicalOperator12_a_tmp == PmmStatus_MCUDEACT));

  /* SignalConversion: '<S13>/Signal Conversion2' */
  thmd_b_FWFVEna = thmd_b_MHGVEna;

  /* Logic: '<S107>/Logical Operator12' incorporates:
   *  Constant: '<S136>/Constant'
   *  Constant: '<S137>/Constant'
   *  Logic: '<S107>/Logical Operator2'
   *  RelationalOperator: '<S103>/Relational Operator1'
   *  RelationalOperator: '<S103>/Relational Operator2'
   *  RelationalOperator: '<S107>/Relational Operator1'
   *  RelationalOperator: '<S107>/Relational Operator2'
   */
  rtb_LogicalOperator12_l = ((!swc_VCOP_ARID_DEF.DataTypeConversion44) ||
    (rtb_LogicalOperator12_a_tmp == PmmStatus_INIT) ||
    (rtb_LogicalOperator12_a_tmp == PmmStatus_OFF));

  /* Outputs for Atomic SubSystem: '<S107>/SR_latch' */
  swc_VCOP_SR_latch_oy(swc_VCOP_ARID_DEF.DataTypeConversion44,
                       rtb_LogicalOperator12_l,
                       &swc_VCOP_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S107>/SR_latch' */

  /* SignalConversion: '<S104>/Signal Conversion1' */
  swc_VCOP_ARID_DEF.SignalConversion1 = swc_VCOP_ARID_DEF.DataTypeConversion214;

  /* Switch: '<S86>/Switch1' */
  if (swc_VCOP_ARID_DEF.SignalConversion1 != 0.0) {
    /* Switch: '<S86>/Switch1' incorporates:
     *  Constant: '<S86>/EP3_HiSpd3'
     */
    thmd_t_ptcTempSetting = thmc_t_ptcTempSettingPTCEna_C;
  } else {
    /* Switch: '<S86>/Switch1' incorporates:
     *  Constant: '<S86>/EP3_HiSpd1'
     */
    thmd_t_ptcTempSetting = thmc_t_ptcTempSettingPTCDis_C;
  }

  /* End of Switch: '<S86>/Switch1' */

  /* SignalConversion: '<S104>/Signal Conversion' */
  swc_VCOP_ARID_DEF.SignalConversion = swc_VCOP_ARID_DEF.DataTypeConversion214;

  /* Switch: '<S106>/Switch1' incorporates:
   *  Constant: '<S106>/Constant3'
   *  Constant: '<S106>/Constant5'
   *  Constant: '<S106>/Constant8'
   *  RelationalOperator: '<S106>/Relational Operator'
   *  RelationalOperator: '<S106>/Relational Operator1'
   *  RelationalOperator: '<S106>/Relational Operator2'
   *  Switch: '<S106>/Switch2'
   *  Switch: '<S106>/Switch3'
   */
  if (swc_VCOP_ARID_DEF.DataTypeConversion112 == ((uint8)1U)) {
    /* Switch: '<S106>/Switch1' incorporates:
     *  Constant: '<S106>/Constant4'
     */
    thmd_st_hvbThermMngWorkMod = ((uint8)3U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion112 == ((uint8)2U)) {
    /* Switch: '<S106>/Switch2' incorporates:
     *  Constant: '<S106>/Constant1'
     *  Switch: '<S106>/Switch1'
     */
    thmd_st_hvbThermMngWorkMod = ((uint8)5U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion112 == ((uint8)3U)) {
    /* Switch: '<S106>/Switch3' incorporates:
     *  Constant: '<S106>/Constant6'
     *  Switch: '<S106>/Switch1'
     *  Switch: '<S106>/Switch2'
     */
    thmd_st_hvbThermMngWorkMod = ((uint8)1U);
  } else {
    /* Switch: '<S106>/Switch1' incorporates:
     *  Constant: '<S106>/Constant7'
     *  Switch: '<S106>/Switch2'
     *  Switch: '<S106>/Switch3'
     */
    thmd_st_hvbThermMngWorkMod = ((uint8)0U);
  }

  /* End of Switch: '<S106>/Switch1' */

  /* SignalConversion: '<S13>/Signal Conversion3' */
  rtb_SignalConversion3 = swc_VCOP_ARID_DEF.DataTypeConversion74;

  /* SignalConversion: '<S13>/Signal Conversion4' */
  rtb_SignalConversion4 = swc_VCOP_ARID_DEF.DataTypeConversion539;

  /* RelationalOperator: '<S13>/Relational Operator' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in138'
   *  RelationalOperator: '<S13>/Relational Operator13'
   */
  u0 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbCooltInSnsr_V();

  /* Switch: '<S13>/Switch9' incorporates:
   *  Constant: '<S13>/Constant10'
   *  Constant: '<S13>/Constant8'
   *  Inport generated from: '<Root>/vcib_VCIP_in138'
   *  Logic: '<S13>/Logical Operator8'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator13'
   *  Saturate: '<S13>/Saturation2'
   */
  if ((u0 > 4.9F) || (u0 < 0.1F)) {
    /* Switch: '<S13>/Switch9' incorporates:
     *  Constant: '<S13>/Constant13'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdInCoolTemp_C = 87.5F;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion191 > 87.0F) {
    /* Saturate: '<S13>/Saturation2' incorporates:
     *  Switch: '<S13>/Switch9'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdInCoolTemp_C = 87.0F;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion191 < (-40.0F)) {
    /* Saturate: '<S13>/Saturation2' incorporates:
     *  Switch: '<S13>/Switch9'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdInCoolTemp_C = (-40.0F);
  } else {
    /* Switch: '<S13>/Switch9' incorporates:
     *  Saturate: '<S13>/Saturation2'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdInCoolTemp_C =
      swc_VCOP_ARID_DEF.DataTypeConversion191;
  }

  /* End of Switch: '<S13>/Switch9' */

  /* RelationalOperator: '<S13>/Relational Operator14' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in141'
   *  RelationalOperator: '<S13>/Relational Operator15'
   */
  u0 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbCooltOutSnsr_V();

  /* Switch: '<S13>/Switch10' incorporates:
   *  Constant: '<S13>/Constant11'
   *  Constant: '<S13>/Constant12'
   *  Inport generated from: '<Root>/vcib_VCIP_in141'
   *  Logic: '<S13>/Logical Operator9'
   *  RelationalOperator: '<S13>/Relational Operator14'
   *  RelationalOperator: '<S13>/Relational Operator15'
   *  Saturate: '<S13>/Saturation1'
   */
  if ((u0 > 4.9F) || (u0 < 0.1F)) {
    /* Switch: '<S13>/Switch10' incorporates:
     *  Constant: '<S13>/Constant14'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdOutCoolTemp_C = 87.5F;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion184 > 87.0F) {
    /* Saturate: '<S13>/Saturation1' incorporates:
     *  Switch: '<S13>/Switch10'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdOutCoolTemp_C = 87.0F;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion184 < (-40.0F)) {
    /* Saturate: '<S13>/Saturation1' incorporates:
     *  Switch: '<S13>/Switch10'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdOutCoolTemp_C = (-40.0F);
  } else {
    /* Switch: '<S13>/Switch10' incorporates:
     *  Saturate: '<S13>/Saturation1'
     */
    swc_VCOP_ARID_DEF.thmd_t_hvbHdOutCoolTemp_C =
      swc_VCOP_ARID_DEF.DataTypeConversion184;
  }

  /* End of Switch: '<S13>/Switch10' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (volc_b_flgFnctnConfgBMSWaterTemp) {
    /* SignalConversion: '<S13>/Signal Conversion6' */
    swc_VCOP_ARID_DEF.SignalConversion6 =
      swc_VCOP_ARID_DEF.DataTypeConversion120;
  } else {
    /* SignalConversion: '<S13>/Signal Conversion6' */
    swc_VCOP_ARID_DEF.SignalConversion6 =
      swc_VCOP_ARID_DEF.thmd_t_hvbHdOutCoolTemp_C;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport generated from: '<Root>/vcib_VCIP_in15'
   *  Switch: '<S13>/Switch1'
   */
  if (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp() != 0) {
    /* Saturate: '<S13>/Saturation3' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in14'
     */
    u0 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_acwpOutptTemp_C();
    if (u0 > 205.0F) {
      /* Switch: '<S13>/Switch2' */
      swc_VCOP_ARID_DEF.Switch2 = 205.0F;
    } else if (u0 < (-50.0F)) {
      /* Switch: '<S13>/Switch2' */
      swc_VCOP_ARID_DEF.Switch2 = (-50.0F);
    } else {
      /* Switch: '<S13>/Switch2' */
      swc_VCOP_ARID_DEF.Switch2 = u0;
    }

    /* End of Saturate: '<S13>/Saturation3' */
  } else if (volc_b_flgFnctnConfgBMSWaterTemp) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Switch: '<S13>/Switch2'
     */
    swc_VCOP_ARID_DEF.Switch2 = swc_VCOP_ARID_DEF.DataTypeConversion118;
  } else {
    /* Switch: '<S13>/Switch2' incorporates:
     *  Switch: '<S13>/Switch1'
     */
    swc_VCOP_ARID_DEF.Switch2 = swc_VCOP_ARID_DEF.thmd_t_hvbHdInCoolTemp_C;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* SignalConversion: '<S13>/Signal Conversion' */
  swc_VCOP_ARID_DEF.SignalConversion_e = swc_VCOP_ARID_DEF.DataTypeConversion97;

  /* SignalConversion: '<S13>/Signal Conversion1' */
  swc_VCOP_ARID_DEF.SignalConversion1_g =
    swc_VCOP_ARID_DEF.DataTypeConversion110;

  /* SignalConversion: '<S13>/Signal Conversion7' */
  swc_VCOP_ARID_DEF.SignalConversion7 = swc_VCOP_ARID_DEF.DataTypeConversion125;

  /* Switch: '<S105>/Switch' incorporates:
   *  Switch: '<S105>/Switch1'
   *  Switch: '<S105>/Switch2'
   *  Switch: '<S105>/Switch3'
   *  Switch: '<S105>/Switch4'
   *  Switch: '<S105>/Switch5'
   *  Switch: '<S105>/Switch6'
   *  Switch: '<S105>/Switch7'
   */
  if (swc_VCOP_ARID_DEF.DataTypeConversion155 > 0.0) {
    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S105>/Constant'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)8U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion242 > 0.0) {
    /* Switch: '<S105>/Switch5' incorporates:
     *  Constant: '<S105>/Constant5'
     *  Switch: '<S105>/Switch'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)1U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion244 > 0.0) {
    /* Switch: '<S105>/Switch7' incorporates:
     *  Constant: '<S105>/Constant8'
     *  Switch: '<S105>/Switch'
     *  Switch: '<S105>/Switch5'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)7U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion241 > 0.0) {
    /* Switch: '<S105>/Switch4' incorporates:
     *  Constant: '<S105>/Constant6'
     *  Switch: '<S105>/Switch'
     *  Switch: '<S105>/Switch5'
     *  Switch: '<S105>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)4U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion157 > 0.0) {
    /* Switch: '<S105>/Switch1' incorporates:
     *  Constant: '<S105>/Constant1'
     *  Switch: '<S105>/Switch'
     *  Switch: '<S105>/Switch4'
     *  Switch: '<S105>/Switch5'
     *  Switch: '<S105>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)10U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion161 > 0.0) {
    /* Switch: '<S105>/Switch2' incorporates:
     *  Constant: '<S105>/Constant2'
     *  Switch: '<S105>/Switch'
     *  Switch: '<S105>/Switch1'
     *  Switch: '<S105>/Switch4'
     *  Switch: '<S105>/Switch5'
     *  Switch: '<S105>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)2U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion243 > 0.0) {
    /* Switch: '<S105>/Switch6' incorporates:
     *  Constant: '<S105>/Constant7'
     *  Switch: '<S105>/Switch'
     *  Switch: '<S105>/Switch1'
     *  Switch: '<S105>/Switch2'
     *  Switch: '<S105>/Switch4'
     *  Switch: '<S105>/Switch5'
     *  Switch: '<S105>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)3U);
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion164 > 0.0) {
    /* Switch: '<S105>/Switch3' incorporates:
     *  Constant: '<S105>/Constant3'
     *  Switch: '<S105>/Switch'
     *  Switch: '<S105>/Switch1'
     *  Switch: '<S105>/Switch2'
     *  Switch: '<S105>/Switch4'
     *  Switch: '<S105>/Switch5'
     *  Switch: '<S105>/Switch6'
     *  Switch: '<S105>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)9U);
  } else {
    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S105>/Constant4'
     *  Switch: '<S105>/Switch1'
     *  Switch: '<S105>/Switch2'
     *  Switch: '<S105>/Switch3'
     *  Switch: '<S105>/Switch4'
     *  Switch: '<S105>/Switch5'
     *  Switch: '<S105>/Switch6'
     *  Switch: '<S105>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch_c = ((uint8)0U);
  }

  /* End of Switch: '<S105>/Switch' */

  /* Switch: '<S105>/Switch8' incorporates:
   *  Constant: '<S139>/Constant'
   *  Constant: '<S140>/Constant'
   *  Constant: '<S141>/Constant'
   *  Constant: '<S142>/Constant'
   *  Constant: '<S143>/Constant'
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Constant'
   *  Logic: '<S105>/Logical Operator'
   *  RelationalOperator: '<S139>/Compare'
   *  RelationalOperator: '<S140>/Compare'
   *  RelationalOperator: '<S141>/Compare'
   *  RelationalOperator: '<S142>/Compare'
   *  RelationalOperator: '<S143>/Compare'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Compare'
   *  Switch: '<S105>/Switch10'
   *  Switch: '<S105>/Switch11'
   *  Switch: '<S105>/Switch13'
   *  Switch: '<S105>/Switch9'
   */
  if (8.0 == 0.0) {
    /* Switch: '<S105>/Switch8' incorporates:
     *  Constant: '<S105>/Constant9'
     */
    swc_VCOP_ARID_DEF.Switch8 = ((uint8)5U);
  } else if ((1.0 == 0.0) || (7.0 == 0.0) || (4.0 == 0.0)) {
    /* Switch: '<S105>/Switch11' incorporates:
     *  Constant: '<S105>/Constant12'
     *  Switch: '<S105>/Switch8'
     */
    swc_VCOP_ARID_DEF.Switch8 = ((uint8)3U);
  } else if (10.0 == 0.0) {
    /* Switch: '<S105>/Switch10' incorporates:
     *  Constant: '<S105>/Constant11'
     *  Switch: '<S105>/Switch11'
     *  Switch: '<S105>/Switch8'
     */
    swc_VCOP_ARID_DEF.Switch8 = ((uint8)1U);
  } else if (2.0 == 0.0) {
    /* Switch: '<S105>/Switch13' incorporates:
     *  Constant: '<S105>/Constant14'
     *  Switch: '<S105>/Switch10'
     *  Switch: '<S105>/Switch11'
     *  Switch: '<S105>/Switch8'
     */
    swc_VCOP_ARID_DEF.Switch8 = ((uint8)2U);
  } else if (9.0 == 0.0) {
    /* Switch: '<S105>/Switch9' incorporates:
     *  Constant: '<S105>/Constant10'
     *  Switch: '<S105>/Switch10'
     *  Switch: '<S105>/Switch11'
     *  Switch: '<S105>/Switch13'
     *  Switch: '<S105>/Switch8'
     */
    swc_VCOP_ARID_DEF.Switch8 = ((uint8)4U);
  } else {
    /* Switch: '<S105>/Switch8' incorporates:
     *  Constant: '<S105>/Constant13'
     *  Switch: '<S105>/Switch10'
     *  Switch: '<S105>/Switch11'
     *  Switch: '<S105>/Switch13'
     *  Switch: '<S105>/Switch9'
     */
    swc_VCOP_ARID_DEF.Switch8 = ((uint8)0U);
  }

  /* End of Switch: '<S105>/Switch8' */

  /* SignalConversion: '<S13>/Signal Conversion8' */
  swc_VCOP_ARID_DEF.thmd_pwr_accmHvClPwrAllwd_kW =
    swc_VCOP_ARID_DEF.DataTypeConversion176;

  /* SignalConversion: '<S13>/Signal Conversion9' */
  swc_VCOP_ARID_DEF.thmd_pwr_ptcHvHtPwrAllwd_kW =
    swc_VCOP_ARID_DEF.DataTypeConversion182;

  /* Switch: '<S102>/Switch8' incorporates:
   *  Constant: '<S122>/Constant'
   *  Constant: '<S123>/Constant'
   *  Constant: '<S124>/Constant'
   *  Constant: '<S125>/Constant'
   *  Constant: '<S126>/Constant'
   *  Constant: '<S127>/Constant'
   *  Constant: '<S128>/Constant'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S130>/Constant'
   *  Constant: '<S131>/Constant'
   *  Constant: '<S132>/Constant'
   *  Constant: '<S133>/Constant'
   *  Constant: '<S134>/Constant'
   *  Constant: '<S135>/Constant'
   *  Logic: '<S102>/Logical Operator1'
   *  Logic: '<S102>/Logical Operator2'
   *  Logic: '<S102>/Logical Operator3'
   *  Logic: '<S102>/Logical Operator4'
   *  Logic: '<S102>/Logical Operator5'
   *  Logic: '<S102>/Logical Operator6'
   *  Logic: '<S102>/Logical Operator7'
   *  RelationalOperator: '<S122>/Compare'
   *  RelationalOperator: '<S123>/Compare'
   *  RelationalOperator: '<S124>/Compare'
   *  RelationalOperator: '<S125>/Compare'
   *  RelationalOperator: '<S126>/Compare'
   *  RelationalOperator: '<S127>/Compare'
   *  RelationalOperator: '<S128>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   *  RelationalOperator: '<S130>/Compare'
   *  RelationalOperator: '<S131>/Compare'
   *  RelationalOperator: '<S132>/Compare'
   *  RelationalOperator: '<S133>/Compare'
   *  RelationalOperator: '<S134>/Compare'
   *  RelationalOperator: '<S135>/Compare'
   *  Switch: '<S102>/Switch2'
   *  Switch: '<S102>/Switch3'
   *  Switch: '<S102>/Switch4'
   *  Switch: '<S102>/Switch5'
   *  Switch: '<S102>/Switch6'
   *  Switch: '<S102>/Switch7'
   */
  if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 6.0F) &&
      (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 14.0F)) {
    /* Switch: '<S102>/Switch8' incorporates:
     *  Constant: '<S102>/Constant9'
     */
    rtb_Switch8 = ((uint8)0U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 26.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 34.0F)) {
    /* Switch: '<S102>/Switch2' incorporates:
     *  Constant: '<S102>/Constant1'
     *  Switch: '<S102>/Switch8'
     */
    rtb_Switch8 = ((uint8)5U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 36.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 44.0F)) {
    /* Switch: '<S102>/Switch3' incorporates:
     *  Constant: '<S102>/Constant2'
     *  Switch: '<S102>/Switch2'
     *  Switch: '<S102>/Switch8'
     */
    rtb_Switch8 = ((uint8)3U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 46.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 54.0F)) {
    /* Switch: '<S102>/Switch4' incorporates:
     *  Constant: '<S102>/Constant3'
     *  Switch: '<S102>/Switch2'
     *  Switch: '<S102>/Switch3'
     *  Switch: '<S102>/Switch8'
     */
    rtb_Switch8 = ((uint8)7U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 56.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 64.0F)) {
    /* Switch: '<S102>/Switch5' incorporates:
     *  Constant: '<S102>/Constant4'
     *  Switch: '<S102>/Switch2'
     *  Switch: '<S102>/Switch3'
     *  Switch: '<S102>/Switch4'
     *  Switch: '<S102>/Switch8'
     */
    rtb_Switch8 = ((uint8)4U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 66.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 74.0F)) {
    /* Switch: '<S102>/Switch6' incorporates:
     *  Constant: '<S102>/Constant5'
     *  Switch: '<S102>/Switch2'
     *  Switch: '<S102>/Switch3'
     *  Switch: '<S102>/Switch4'
     *  Switch: '<S102>/Switch5'
     *  Switch: '<S102>/Switch8'
     */
    rtb_Switch8 = ((uint8)6U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion174 >= 76.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion174 <= 84.0F)) {
    /* Switch: '<S102>/Switch7' incorporates:
     *  Constant: '<S102>/Constant6'
     *  Switch: '<S102>/Switch2'
     *  Switch: '<S102>/Switch3'
     *  Switch: '<S102>/Switch4'
     *  Switch: '<S102>/Switch5'
     *  Switch: '<S102>/Switch6'
     *  Switch: '<S102>/Switch8'
     */
    rtb_Switch8 = ((uint8)2U);
  } else {
    /* Switch: '<S102>/Switch8' incorporates:
     *  Constant: '<S102>/Constant7'
     *  Switch: '<S102>/Switch2'
     *  Switch: '<S102>/Switch3'
     *  Switch: '<S102>/Switch4'
     *  Switch: '<S102>/Switch5'
     *  Switch: '<S102>/Switch6'
     *  Switch: '<S102>/Switch7'
     */
    rtb_Switch8 = ((uint8)15U);
  }

  /* End of Switch: '<S102>/Switch8' */

  /* Switch: '<S87>/Switch8' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  Constant: '<S112>/Constant'
   *  Constant: '<S113>/Constant'
   *  Constant: '<S114>/Constant'
   *  Constant: '<S115>/Constant'
   *  Constant: '<S116>/Constant'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S118>/Constant'
   *  Constant: '<S119>/Constant'
   *  Constant: '<S120>/Constant'
   *  Constant: '<S121>/Constant'
   *  Logic: '<S87>/Logical Operator1'
   *  Logic: '<S87>/Logical Operator2'
   *  Logic: '<S87>/Logical Operator3'
   *  Logic: '<S87>/Logical Operator4'
   *  Logic: '<S87>/Logical Operator5'
   *  Logic: '<S87>/Logical Operator6'
   *  Logic: '<S87>/Logical Operator7'
   *  RelationalOperator: '<S108>/Compare'
   *  RelationalOperator: '<S109>/Compare'
   *  RelationalOperator: '<S110>/Compare'
   *  RelationalOperator: '<S111>/Compare'
   *  RelationalOperator: '<S112>/Compare'
   *  RelationalOperator: '<S113>/Compare'
   *  RelationalOperator: '<S114>/Compare'
   *  RelationalOperator: '<S115>/Compare'
   *  RelationalOperator: '<S116>/Compare'
   *  RelationalOperator: '<S117>/Compare'
   *  RelationalOperator: '<S118>/Compare'
   *  RelationalOperator: '<S119>/Compare'
   *  RelationalOperator: '<S120>/Compare'
   *  RelationalOperator: '<S121>/Compare'
   *  Switch: '<S87>/Switch2'
   *  Switch: '<S87>/Switch3'
   *  Switch: '<S87>/Switch4'
   *  Switch: '<S87>/Switch5'
   *  Switch: '<S87>/Switch6'
   *  Switch: '<S87>/Switch7'
   */
  if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 6.0F) &&
      (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 14.0F)) {
    /* Switch: '<S87>/Switch8' incorporates:
     *  Constant: '<S87>/Constant9'
     */
    rtb_Switch8_e = ((uint8)0U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 26.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 34.0F)) {
    /* Switch: '<S87>/Switch2' incorporates:
     *  Constant: '<S87>/Constant1'
     *  Switch: '<S87>/Switch8'
     */
    rtb_Switch8_e = ((uint8)5U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 36.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 44.0F)) {
    /* Switch: '<S87>/Switch3' incorporates:
     *  Constant: '<S87>/Constant2'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch8'
     */
    rtb_Switch8_e = ((uint8)3U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 46.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 54.0F)) {
    /* Switch: '<S87>/Switch4' incorporates:
     *  Constant: '<S87>/Constant3'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch3'
     *  Switch: '<S87>/Switch8'
     */
    rtb_Switch8_e = ((uint8)7U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 56.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 64.0F)) {
    /* Switch: '<S87>/Switch5' incorporates:
     *  Constant: '<S87>/Constant4'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch3'
     *  Switch: '<S87>/Switch4'
     *  Switch: '<S87>/Switch8'
     */
    rtb_Switch8_e = ((uint8)4U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 66.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 74.0F)) {
    /* Switch: '<S87>/Switch6' incorporates:
     *  Constant: '<S87>/Constant5'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch3'
     *  Switch: '<S87>/Switch4'
     *  Switch: '<S87>/Switch5'
     *  Switch: '<S87>/Switch8'
     */
    rtb_Switch8_e = ((uint8)6U);
  } else if ((swc_VCOP_ARID_DEF.DataTypeConversion173 >= 76.0F) &&
             (swc_VCOP_ARID_DEF.DataTypeConversion173 <= 84.0F)) {
    /* Switch: '<S87>/Switch7' incorporates:
     *  Constant: '<S87>/Constant6'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch3'
     *  Switch: '<S87>/Switch4'
     *  Switch: '<S87>/Switch5'
     *  Switch: '<S87>/Switch6'
     *  Switch: '<S87>/Switch8'
     */
    rtb_Switch8_e = ((uint8)2U);
  } else {
    /* Switch: '<S87>/Switch8' incorporates:
     *  Constant: '<S87>/Constant7'
     *  Switch: '<S87>/Switch2'
     *  Switch: '<S87>/Switch3'
     *  Switch: '<S87>/Switch4'
     *  Switch: '<S87>/Switch5'
     *  Switch: '<S87>/Switch6'
     *  Switch: '<S87>/Switch7'
     */
    rtb_Switch8_e = ((uint8)15U);
  }

  /* End of Switch: '<S87>/Switch8' */
}

/*
 * System initialize for atomic system:
 *    '<S20>/debounce'
 *    '<S32>/debounce'
 */
static void swc_VCOP_debounce_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S26>/timed_debounce' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S20>/debounce'
 *    '<S32>/debounce'
 */
static void swc_VCOP_debounce(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_debounce_swc_VCOP_T *swc_VCOP__ARID_DEF_arg)
{
  float32 rtb_t_delay_off_i;
  float32 rtb_t_delay_on_d;

  /* Saturate: '<S26>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S26>/Saturation' */
    rtb_t_delay_on_d = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S26>/Saturation' */
    rtb_t_delay_on_d = 0.0F;
  } else {
    /* Saturate: '<S26>/Saturation' */
    rtb_t_delay_on_d = rtu_t_delay_on;
  }

  /* End of Saturate: '<S26>/Saturation' */

  /* Saturate: '<S26>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S26>/Saturation1' */
    rtb_t_delay_off_i = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S26>/Saturation1' */
    rtb_t_delay_off_i = 0.0F;
  } else {
    /* Saturate: '<S26>/Saturation1' */
    rtb_t_delay_off_i = rtu_t_delay_off;
  }

  /* End of Saturate: '<S26>/Saturation1' */

  /* Chart: '<S26>/timed_debounce' incorporates:
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   */
  if (swc_VCOP__ARID_DEF_arg->is_active_c6_Ricardo_SW_dev_lib == 0U) {
    swc_VCOP__ARID_DEF_arg->is_active_c6_Ricardo_SW_dev_lib = 1U;
    if (rtu_flg_in) {
      swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib) {
     case swc_VCOP_IN_OFF:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_d == 0.0F) {
          swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON;
          *rty_flg_out = true;
        } else {
          swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_WAIT;
          swc_VCOP__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_VCOP_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON;
        *rty_flg_out = true;
      } else if (swc_VCOP__ARID_DEF_arg->t_wait > rtb_t_delay_off_i - rtu_t_step)
      {
        swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF;
        *rty_flg_out = false;
      } else {
        swc_VCOP__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     case swc_VCOP_IN_ON:
      if (!rtu_flg_in) {
        if (rtb_t_delay_off_i == 0.0F) {
          swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF;
          *rty_flg_out = false;
        } else {
          swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib =
            swc_VCOP_IN_OFF_WAIT;
          swc_VCOP__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF;
        *rty_flg_out = false;
      } else if (swc_VCOP__ARID_DEF_arg->t_wait > rtb_t_delay_on_d - rtu_t_step)
      {
        swc_VCOP__ARID_DEF_arg->is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON;
        *rty_flg_out = true;
      } else {
        swc_VCOP__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S26>/timed_debounce' */
}

/* System initialize for function-call system: '<S3>/DSP_OutputsProcessing' */
static void swc__DSP_OutputsProcessing_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out;
  boolean rtb_flg_out_d;

  /* SystemInitialize for Atomic SubSystem: '<S20>/debounce' */
  swc_VCOP_debounce_Init(&rtb_flg_out_d);

  /* End of SystemInitialize for SubSystem: '<S20>/debounce' */

  /* SystemInitialize for Atomic SubSystem: '<S32>/debounce' */
  swc_VCOP_debounce_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S32>/debounce' */
}

/* Output and update for function-call system: '<S3>/DSP_OutputsProcessing' */
static void swc_VCOP_DSP_OutputsProcessing(void)
{
  /* local block i/o variables */
  boolean rtb_RelationalOperator2_n5;
  boolean rtb_RelationalOperator2_e;
  boolean rtb_flg_out;
  boolean rtb_flg_out_d;
  float32 rtb_t_delay_off_m_tmp;
  float32 rtb_t_delay_on_f_tmp;
  GearLeverPos tmp;
  uint8 rtb_UnitDelay2;

  /* RelationalOperator: '<S20>/Relational Operator2' incorporates:
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  rtb_RelationalOperator2_n5 = (swc_VCOP_ARID_DEF.DataTypeConversion518 !=
    dspd_st_drvMod);

  /* Outputs for Atomic SubSystem: '<S20>/debounce' */
  /* Constant: '<S20>/Constant' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Constant3'
   */
  swc_VCOP_debounce(rtb_RelationalOperator2_n5, dspc_t_ipcSgnlTrnOnDly_s, 0.0F,
                    ((float32)DSP_TASK_INTERVAL_S), &rtb_flg_out_d,
                    &swc_VCOP_ARID_DEF.ARID_DEF_debounce_c);

  /* End of Outputs for SubSystem: '<S20>/debounce' */

  /* Switch: '<S20>/Switch1' */
  if (rtb_flg_out_d) {
    /* Switch: '<S20>/Switch1' */
    dspd_st_drvMod = swc_VCOP_ARID_DEF.DataTypeConversion518;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* RelationalOperator: '<S20>/Relational Operator' incorporates:
   *  Constant: '<S20>/Constant11'
   */
  dspd_b_ECOBttnWrkLgt = (dspd_st_drvMod == DISPLAY_DRIVEMODE_ECO);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/Drive'
   *  Constant: '<S25>/Regen'
   *  Constant: '<S25>/Reverse'
   *  Logic: '<S25>/Logical Operator1'
   *  RelationalOperator: '<S25>/Relational Operator'
   *  RelationalOperator: '<S25>/Relational Operator1'
   *  RelationalOperator: '<S25>/Relational Operator2'
   *  Switch: '<S25>/Switch1'
   */
  if ((eadd_st_inv2EmWMod == ((uint8)1U)) || (eadd_st_inv2EmWMod == ((uint8)2U)))
  {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Drive1'
     */
    dspd_st_PTModeInd = ((uint8)0U);
  } else if (eadd_st_inv2EmWMod == ((uint8)3U)) {
    /* Switch: '<S25>/Switch1' incorporates:
     *  Constant: '<S25>/Drive2'
     *  Switch: '<S25>/Switch'
     */
    dspd_st_PTModeInd = ((uint8)1U);
  } else {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Drive3'
     *  Switch: '<S25>/Switch1'
     */
    dspd_st_PTModeInd = ((uint8)3U);
  }

  /* End of Switch: '<S25>/Switch' */

  /* SignalConversion: '<S7>/Signal Conversion' */
  swc_VCOP_ARID_DEF.dspd_st_gearOptErr = swc_VCOP_ARID_DEF.DataTypeConversion232;

  /* RelationalOperator: '<S22>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion524'
   *  RelationalOperator: '<S22>/Relational Operator1'
   *  RelationalOperator: '<S22>/Relational Operator2'
   *  RelationalOperator: '<S22>/Relational Operator3'
   *  Switch: '<S22>/Switch'
   *  Switch: '<S22>/Switch1'
   *  Switch: '<S22>/Switch4'
   */
  tmp = swc_VCOP_ARID_DEF.DataTypeConversion524;

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Constant'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  RelationalOperator: '<S22>/Relational Operator1'
   *  RelationalOperator: '<S22>/Relational Operator2'
   *  RelationalOperator: '<S22>/Relational Operator3'
   *  Switch: '<S22>/Switch1'
   *  Switch: '<S22>/Switch2'
   *  Switch: '<S22>/Switch4'
   */
  if (tmp == GearLeverPos_NEUTRAL) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant'
     */
    rtb_UnitDelay2 = ((uint8)3U);
  } else if (tmp == GearLeverPos_FWD_DRIVE) {
    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant1'
     *  Switch: '<S22>/Switch'
     */
    rtb_UnitDelay2 = ((uint8)4U);
  } else if (tmp == GearLeverPos_REV_DRIVE) {
    /* Switch: '<S22>/Switch4' incorporates:
     *  Constant: '<S22>/Constant2'
     *  Switch: '<S22>/Switch'
     *  Switch: '<S22>/Switch1'
     */
    rtb_UnitDelay2 = ((uint8)2U);
  } else if (tmp == GearLeverPos_PARKING) {
    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant3'
     *  Switch: '<S22>/Switch'
     *  Switch: '<S22>/Switch1'
     *  Switch: '<S22>/Switch4'
     */
    rtb_UnitDelay2 = ((uint8)1U);
  } else {
    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S22>/Constant4'
     *  Switch: '<S22>/Switch1'
     *  Switch: '<S22>/Switch2'
     *  Switch: '<S22>/Switch4'
     */
    rtb_UnitDelay2 = ((uint8)0U);
  }

  /* RelationalOperator: '<S32>/Relational Operator2' incorporates:
   *  UnitDelay: '<S32>/Unit Delay2'
   */
  rtb_RelationalOperator2_e = (rtb_UnitDelay2 != dspd_st_gearPosnInd);

  /* Outputs for Atomic SubSystem: '<S32>/debounce' */
  /* Constant: '<S32>/Constant' incorporates:
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Constant3'
   */
  swc_VCOP_debounce(rtb_RelationalOperator2_e, dspc_t_ipcSgnlTrnOnDly_s, 0.0F,
                    ((float32)DSP_TASK_INTERVAL_S), &rtb_flg_out,
                    &swc_VCOP_ARID_DEF.ARID_DEF_debounce);

  /* End of Outputs for SubSystem: '<S32>/debounce' */

  /* Switch: '<S32>/Switch1' */
  if (rtb_flg_out) {
    /* Switch: '<S32>/Switch1' */
    dspd_st_gearPosnInd = rtb_UnitDelay2;
  }

  /* End of Switch: '<S32>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S23>/debounce' */
  /* Saturate: '<S35>/Saturation' incorporates:
   *  Constant: '<S23>/Constant'
   */
  if (dspc_t_ipcSgnlTrnOnDly_s > 1.6777216E+7F) {
    /* Outputs for Atomic SubSystem: '<S24>/debounce' */
    /* Saturate: '<S37>/Saturation' */
    rtb_t_delay_on_f_tmp = 1.6777216E+7F;

    /* End of Outputs for SubSystem: '<S24>/debounce' */
  } else if (dspc_t_ipcSgnlTrnOnDly_s < 0.0F) {
    /* Outputs for Atomic SubSystem: '<S24>/debounce' */
    /* Saturate: '<S37>/Saturation' */
    rtb_t_delay_on_f_tmp = 0.0F;

    /* End of Outputs for SubSystem: '<S24>/debounce' */
  } else {
    /* Outputs for Atomic SubSystem: '<S24>/debounce' */
    /* Saturate: '<S37>/Saturation' */
    rtb_t_delay_on_f_tmp = dspc_t_ipcSgnlTrnOnDly_s;

    /* End of Outputs for SubSystem: '<S24>/debounce' */
  }

  /* Saturate: '<S35>/Saturation1' incorporates:
   *  Constant: '<S23>/Constant1'
   */
  if (dspc_t_ipcSgnlTrnOffDly_s > 1.6777216E+7F) {
    /* Outputs for Atomic SubSystem: '<S24>/debounce' */
    /* Saturate: '<S37>/Saturation1' */
    rtb_t_delay_off_m_tmp = 1.6777216E+7F;

    /* End of Outputs for SubSystem: '<S24>/debounce' */
  } else if (dspc_t_ipcSgnlTrnOffDly_s < 0.0F) {
    /* Outputs for Atomic SubSystem: '<S24>/debounce' */
    /* Saturate: '<S37>/Saturation1' */
    rtb_t_delay_off_m_tmp = 0.0F;

    /* End of Outputs for SubSystem: '<S24>/debounce' */
  } else {
    /* Outputs for Atomic SubSystem: '<S24>/debounce' */
    /* Saturate: '<S37>/Saturation1' */
    rtb_t_delay_off_m_tmp = dspc_t_ipcSgnlTrnOffDly_s;

    /* End of Outputs for SubSystem: '<S24>/debounce' */
  }

  /* Chart: '<S35>/timed_debounce' incorporates:
   *  Constant: '<S23>/Constant2'
   *  DataTypeConversion: '<S23>/Data Type Conversion1'
   *  Saturate: '<S35>/Saturation'
   *  Saturate: '<S35>/Saturation1'
   */
  if (swc_VCOP_ARID_DEF.is_active_c6_Ricardo_SW_dev_l_b == 0U) {
    swc_VCOP_ARID_DEF.is_active_c6_Ricardo_SW_dev_l_b = 1U;
    if (epbd_st_parkingSts != 0) {
      swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_ON_i;
      dspd_b_hndbrkSt = true;
    } else {
      swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_OFF_db;
      dspd_b_hndbrkSt = false;
    }
  } else {
    switch (swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e) {
     case swc_VCOP_IN_OFF_db:
      if (epbd_st_parkingSts != 0) {
        if (rtb_t_delay_on_f_tmp == 0.0F) {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_ON_i;
          dspd_b_hndbrkSt = true;
        } else {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_ON_WAIT_b;
          swc_VCOP_ARID_DEF.t_wait_i = ((float32)DSP_TASK_INTERVAL_S);
          dspd_b_hndbrkSt = false;
        }
      } else {
        dspd_b_hndbrkSt = false;
      }
      break;

     case swc_VCOP_IN_OFF_WAIT_c:
      if (epbd_st_parkingSts != 0) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_ON_i;
        dspd_b_hndbrkSt = true;
      } else if (swc_VCOP_ARID_DEF.t_wait_i > rtb_t_delay_off_m_tmp - ((float32)
                  DSP_TASK_INTERVAL_S)) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_OFF_db;
        dspd_b_hndbrkSt = false;
      } else {
        swc_VCOP_ARID_DEF.t_wait_i += ((float32)DSP_TASK_INTERVAL_S);
        dspd_b_hndbrkSt = true;
      }
      break;

     case swc_VCOP_IN_ON_i:
      if (epbd_st_parkingSts == 0) {
        if (rtb_t_delay_off_m_tmp == 0.0F) {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_OFF_db;
          dspd_b_hndbrkSt = false;
        } else {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_OFF_WAIT_c;
          swc_VCOP_ARID_DEF.t_wait_i = ((float32)DSP_TASK_INTERVAL_S);
          dspd_b_hndbrkSt = true;
        }
      } else {
        dspd_b_hndbrkSt = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (epbd_st_parkingSts == 0) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_OFF_db;
        dspd_b_hndbrkSt = false;
      } else if (swc_VCOP_ARID_DEF.t_wait_i > rtb_t_delay_on_f_tmp - ((float32)
                  DSP_TASK_INTERVAL_S)) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib_e = swc_VCOP_IN_ON_i;
        dspd_b_hndbrkSt = true;
      } else {
        swc_VCOP_ARID_DEF.t_wait_i += ((float32)DSP_TASK_INTERVAL_S);
        dspd_b_hndbrkSt = false;
      }
      break;
    }
  }

  /* End of Chart: '<S35>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S23>/debounce' */

  /* Outputs for Atomic SubSystem: '<S24>/debounce' */
  /* Chart: '<S37>/timed_debounce' incorporates:
   *  Constant: '<S24>/Constant2'
   *  DataTypeConversion: '<S37>/Data Type Conversion'
   */
  if (swc_VCOP_ARID_DEF.is_active_c6_Ricardo_SW_dev_lib == 0U) {
    swc_VCOP_ARID_DEF.is_active_c6_Ricardo_SW_dev_lib = 1U;
    if (swc_VCOP_ARID_DEF.DataTypeConversion535) {
      swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_i;
      dspd_b_ignSt = true;
    } else {
      swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_db;
      dspd_b_ignSt = false;
    }
  } else {
    switch (swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib) {
     case swc_VCOP_IN_OFF_db:
      if (swc_VCOP_ARID_DEF.DataTypeConversion535) {
        if (rtb_t_delay_on_f_tmp == 0.0F) {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_i;
          dspd_b_ignSt = true;
        } else {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_WAIT_b;
          swc_VCOP_ARID_DEF.t_wait = ((float32)DSP_TASK_INTERVAL_S);
          dspd_b_ignSt = false;
        }
      } else {
        dspd_b_ignSt = false;
      }
      break;

     case swc_VCOP_IN_OFF_WAIT_c:
      if (swc_VCOP_ARID_DEF.DataTypeConversion535) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_i;
        dspd_b_ignSt = true;
      } else if (swc_VCOP_ARID_DEF.t_wait > rtb_t_delay_off_m_tmp - ((float32)
                  DSP_TASK_INTERVAL_S)) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_db;
        dspd_b_ignSt = false;
      } else {
        swc_VCOP_ARID_DEF.t_wait += ((float32)DSP_TASK_INTERVAL_S);
        dspd_b_ignSt = true;
      }
      break;

     case swc_VCOP_IN_ON_i:
      if (!swc_VCOP_ARID_DEF.DataTypeConversion535) {
        if (rtb_t_delay_off_m_tmp == 0.0F) {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_db;
          dspd_b_ignSt = false;
        } else {
          swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_WAIT_c;
          swc_VCOP_ARID_DEF.t_wait = ((float32)DSP_TASK_INTERVAL_S);
          dspd_b_ignSt = true;
        }
      } else {
        dspd_b_ignSt = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!swc_VCOP_ARID_DEF.DataTypeConversion535) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_db;
        dspd_b_ignSt = false;
      } else if (swc_VCOP_ARID_DEF.t_wait > rtb_t_delay_on_f_tmp - ((float32)
                  DSP_TASK_INTERVAL_S)) {
        swc_VCOP_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_i;
        dspd_b_ignSt = true;
      } else {
        swc_VCOP_ARID_DEF.t_wait += ((float32)DSP_TASK_INTERVAL_S);
        dspd_b_ignSt = false;
      }
      break;
    }
  }

  /* End of Chart: '<S37>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S24>/debounce' */

  /* Gain: '<S19>/Gain' incorporates:
   *  Sum: '<S19>/Sum'
   */
  dspd_t_battCooltTemp_C = (float32)((swc_VCOP_ARID_DEF.DataTypeConversion537 +
    swc_VCOP_ARID_DEF.DataTypeConversion539) * 0.5);

  /* SignalConversion: '<S7>/Signal Conversion1' */
  swc_VCOP_ARID_DEF.dspd_b_gearPosVld = swc_VCOP_ARID_DEF.DataTypeConversion233;

  /* RelationalOperator: '<S21>/Relational Operator' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in144'
   *  RelationalOperator: '<S21>/Relational Operator1'
   *  RelationalOperator: '<S21>/Relational Operator2'
   *  RelationalOperator: '<S21>/Relational Operator6'
   */
  rtb_UnitDelay2 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_drid_st_gearLvrPosSeql();

  /* Logic: '<S21>/Logical Operator4' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   *  Constant: '<S21>/Constant5'
   *  Constant: '<S21>/Constant6'
   *  Inport generated from: '<Root>/vcib_VCIP_in145'
   *  Inport generated from: '<Root>/vcib_VCIP_in144'
   *  Logic: '<S21>/Logical Operator'
   *  Logic: '<S21>/Logical Operator1'
   *  Logic: '<S21>/Logical Operator2'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator1'
   *  RelationalOperator: '<S21>/Relational Operator2'
   *  RelationalOperator: '<S21>/Relational Operator3'
   *  RelationalOperator: '<S21>/Relational Operator4'
   *  RelationalOperator: '<S21>/Relational Operator5'
   *  RelationalOperator: '<S21>/Relational Operator6'
   */
  dspd_b_gearInvert = (((rtb_UnitDelay2 == ((uint8)1U)) || (rtb_UnitDelay2 ==
    ((uint8)2U)) || (rtb_UnitDelay2 == ((uint8)3U)) || (rtb_UnitDelay2 ==
    ((uint8)4U))) && (((swc_VCOP_ARID_DEF.DataTypeConversion234 == ((uint8)0U)) ||
                       (swc_VCOP_ARID_DEF.DataTypeConversion234 == ((uint8)1U)))
                      && (Rte_IRead_swc_VCOP_Step_vcib_VCIP_adcd_b_adcCtrlGearEn
    () == ((uint8)1U))));
}

/* Output and update for function-call system: '<S3>/PTL_OutputsProcessing' */
static void swc_VCOP_PTL_OutputsProcessing(void)
{
  /* Switch: '<S75>/Switch4' incorporates:
   *  Constant: '<S75>/Constant2'
   *  Logic: '<S75>/Logical Operator'
   *  RelationalOperator: '<S75>/Relational Operator4'
   *  Switch: '<S75>/Switch6'
   */
  if (swc_VCOP_ARID_DEF.DataTypeConversion42 ||
      (swc_VCOP_ARID_DEF.DataTypeConversion41 != ((uint8)1U))) {
    /* Switch: '<S75>/Switch4' incorporates:
     *  Constant: '<S75>/Constant9'
     */
    ptld_pwr_ead2PwrMaxOutp_kW = 0.0F;

    /* Switch: '<S75>/Switch6' incorporates:
     *  Constant: '<S75>/Constant12'
     */
    ptld_pwr_ead21PwrMaxOutp_kW = 0.0F;
  } else {
    /* Switch: '<S75>/Switch4' incorporates:
     *  Constant: '<S75>/Constant5'
     */
    ptld_pwr_ead2PwrMaxOutp_kW = 100.0F;

    /* Switch: '<S75>/Switch6' incorporates:
     *  Constant: '<S75>/Constant11'
     */
    ptld_pwr_ead21PwrMaxOutp_kW = 100.0F;
  }

  /* End of Switch: '<S75>/Switch4' */

  /* SignalConversion: '<S75>/Signal Conversion' */
  ptld_pwr_ead2PwrMinOutp_kW = ptld_pwr_ead2PwrMaxOutp_kW;

  /* SignalConversion: '<S75>/Signal Conversion1' */
  ptld_pwr_ead21PwrMinOutp_kW = ptld_pwr_ead21PwrMaxOutp_kW;
}

/*
 * System initialize for atomic system:
 *    '<S79>/timed_delay'
 *    '<S80>/timed_delay'
 */
static void swc_VCOP_timed_delay_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S79>/timed_delay'
 *    '<S80>/timed_delay'
 */
static void swc_VCOP_timed_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_timed_delay_swc_VCOP_T
  *swc_VCOP__ARID_DEF_arg)
{
  /* Chart: '<S79>/timed_delay' */
  if (swc_VCOP__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_VCOP__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_a;
      *rty_flg_out = true;
    } else {
      swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_d;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib) {
     case swc_VCOP_IN_OFF_d:
      if (rtu_flg_in) {
        swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_a;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_VCOP_IN_OFF_WAIT_k:
      if (rtu_flg_in) {
        swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VCOP_IN_ON_a;
        *rty_flg_out = true;
      } else if (swc_VCOP__ARID_DEF_arg->t_wait > rtu_t_delay_off - rtu_t_step)
      {
        swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_d;
        *rty_flg_out = false;
      } else {
        swc_VCOP__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtu_t_delay_off == 0.0F) {
          swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VCOP_IN_OFF_d;
          *rty_flg_out = false;
        } else {
          swc_VCOP__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib =
            swc_VCOP_IN_OFF_WAIT_k;
          swc_VCOP__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S79>/timed_delay' */
}

/* Output and update for function-call system: '<S1>/VOL__VCU_Output_Layer' */
static void swc_VCOP_VOL__VCU_Output_Layer(void)
{
  /* local block i/o variables */
  float32 rtb_DataTypeConversion43;
  float64 tmp;
  float32 rtb_Switch3_op;
  uint8 rtb_DataTypeConversion2;

  /* Switch: '<S174>/Switch2' incorporates:
   *  Constant: '<S165>/volc_flg_PMS_HVIL1Sts_EV_ovrdflg'
   */
  if (volc_b_PMS_HVIL1Sts_EV_ovrdflg) {
    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S165>/volc_PMS_HVIL1Sts_EV_ovrdval'
     */
    vold_PMS_HVIL1Sts_EV = volc_PMS_HVIL1Sts_EV_ovrdval;
  } else {
    /* Switch: '<S174>/Switch2' */
    vold_PMS_HVIL1Sts_EV = swc_VCOP_ARID_DEF.SignalConversion3;
  }

  /* End of Switch: '<S174>/Switch2' */

  /* Switch: '<S176>/Switch2' incorporates:
   *  Constant: '<S167>/volc_flg_PMS_HVIL2Sts_EV_ovrdflg'
   */
  if (volc_b_PMS_HVIL2Sts_EV_ovrdflg) {
    /* Switch: '<S176>/Switch2' incorporates:
     *  Constant: '<S167>/volc_PMS_HVIL2Sts_EV_ovrdval'
     */
    vold_PMS_HVIL2Sts_EV = volc_PMS_HVIL2Sts_EV_ovrdval;
  } else {
    /* Switch: '<S176>/Switch2' */
    vold_PMS_HVIL2Sts_EV = swc_VCOP_ARID_DEF.SignalConversion2;
  }

  /* End of Switch: '<S176>/Switch2' */

  /* Switch: '<S178>/Switch2' incorporates:
   *  Constant: '<S169>/volc_flg_PMS_HVILSts_EV_ovrdflg'
   */
  if (volc_b_PMS_HVILSts_EV_ovrdflg) {
    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S169>/volc_PMS_HVILSts_EV_ovrdval'
     */
    vold_PMS_HVILSts_EV = volc_PMS_HVILSts_EV_ovrdval;
  } else {
    /* Switch: '<S178>/Switch2' */
    vold_PMS_HVILSts_EV = srud_b_hvbPmsHvilSts;
  }

  /* End of Switch: '<S178>/Switch2' */

  /* Switch: '<S179>/Switch2' incorporates:
   *  Constant: '<S170>/volc_flg_PMS_StsBatLockSensor_ovrdflg'
   */
  if (volc_b_PMS_StsBatLockSensor_ovrdflg) {
    /* Switch: '<S179>/Switch2' incorporates:
     *  Constant: '<S170>/volc_PMS_StsBatLockSensor_ovrdval'
     */
    vold_PMS_StsBatLockSensor = volc_PMS_StsBatLockSensor_ovrdval;
  } else {
    /* Switch: '<S179>/Switch2' */
    vold_PMS_StsBatLockSensor = swc_VCOP_ARID_DEF.Switch4;
  }

  /* End of Switch: '<S179>/Switch2' */

  /* Switch: '<S171>/Switch2' incorporates:
   *  Constant: '<S162>/volc_b_PMS_Acceleration_ovrdflg'
   */
  if (volc_b_PMS_Acceleration_ovrdflg) {
    /* Switch: '<S171>/Switch2' incorporates:
     *  Constant: '<S162>/volc_PMS_Acceleration_ovrdval'
     */
    vold_PMS_Acceleration = volc_PMS_Acceleration_ovrdval;
  } else {
    /* Switch: '<S171>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn10'
     */
    vold_PMS_Acceleration =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_a_vscLongitAcce_mps2();
  }

  /* End of Switch: '<S171>/Switch2' */

  /* Switch: '<S172>/Switch2' incorporates:
   *  Constant: '<S163>/volc_flg_PMS_FrntHeatModEnad_ovrdflg'
   */
  if (volc_b_PMS_FrntHeatModEnad_ovrdflg) {
    /* Switch: '<S172>/Switch2' incorporates:
     *  Constant: '<S163>/volc_PMS_FrntHeatModEnad_ovrdval'
     */
    vold_PMS_FrntHeatModEnad = volc_PMS_FrntHeatModEnad_ovrdval;
  } else {
    /* Switch: '<S172>/Switch2' */
    vold_PMS_FrntHeatModEnad = swc_VCOP_ARID_DEF.DataTypeConversion250;
  }

  /* End of Switch: '<S172>/Switch2' */

  /* Switch: '<S173>/Switch2' incorporates:
   *  Constant: '<S164>/volc_flg_PMS_FrntHeatPwrAllwd_ovrdflg'
   */
  if (volc_b_PMS_FrntHeatPwrAllwd_ovrdflg) {
    /* Switch: '<S173>/Switch2' incorporates:
     *  Constant: '<S164>/volc_PMS_FrntHeatPwrAllwd_ovrdval'
     */
    vold_PMS_FrntHeatPwrAllwd = volc_PMS_FrntHeatPwrAllwd_ovrdval;
  } else {
    /* Switch: '<S173>/Switch2' */
    vold_PMS_FrntHeatPwrAllwd = swc_VCOP_ARID_DEF.DataTypeConversion251;
  }

  /* End of Switch: '<S173>/Switch2' */

  /* Switch: '<S175>/Switch2' incorporates:
   *  Constant: '<S166>/volc_b_PMS_HVIL1Sts_UB_ovrdflg'
   */
  if (volc_b_PMS_HVIL1Sts_UB_ovrdflg) {
    /* Switch: '<S175>/Switch2' incorporates:
     *  Constant: '<S166>/volc_PMS_HVIL1Sts_UB_ovrdval'
     */
    vold_PMS_HVIL1Sts_UB = volc_PMS_HVIL1Sts_UB_ovrdval;
  } else {
    /* Switch: '<S175>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in9'
     */
    vold_PMS_HVIL1Sts_UB =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_dccd_b_dcdcHvilFltInvld();
  }

  /* End of Switch: '<S175>/Switch2' */

  /* Switch: '<S177>/Switch2' incorporates:
   *  Constant: '<S168>/volc_b_PMS_HVIL2Sts_UB_ovrdflg'
   */
  if (volc_b_PMS_HVIL2Sts_UB_ovrdflg) {
    /* Switch: '<S177>/Switch2' incorporates:
     *  Constant: '<S168>/volc_PMS_HVIL2Sts_UB_ovrdval'
     */
    vold_PMS_HVIL2Sts_UB = volc_PMS_HVIL2Sts_UB_ovrdval;
  } else {
    /* Switch: '<S177>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in5'
     */
    vold_PMS_HVIL2Sts_UB =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_accd_b_acHvilOpnInvld();
  }

  /* End of Switch: '<S177>/Switch2' */

  /* Switch: '<S215>/Switch2' incorporates:
   *  Constant: '<S215>/volc_b_pmpEP3TgtSpd_pct_ovrdflg'
   */
  if (volc_b_pmpEP3TgtSpd_pct_ovrdflg) {
    /* Switch: '<S215>/Switch2' incorporates:
     *  Constant: '<S215>/volc_pmpEP3TgtSpd_pct_ovrdval'
     */
    vold_pmpEP3TgtSpd_pct = volc_pmpEP3TgtSpd_pct_ovrdval;
  } else {
    /* Switch: '<S215>/Switch2' */
    vold_pmpEP3TgtSpd_pct = swc_VCOP_ARID_DEF.DataTypeConversion122;
  }

  /* End of Switch: '<S215>/Switch2' */

  /* Switch: '<S213>/Switch2' incorporates:
   *  Constant: '<S213>/volc_b_pmpEP2TgtSpd_pct1_ovrdflg'
   */
  if (volc_b_pmpEP2TgtSpd_pct1_ovrdflg) {
    /* Switch: '<S213>/Switch2' incorporates:
     *  Constant: '<S213>/volc_pmpEP2TgtSpd_pct1_ovrdval'
     */
    vold_pmpEP2TgtSpd_pct = volc_pmpEP2TgtSpd_pct1_ovrdval;
  } else {
    /* Switch: '<S213>/Switch2' */
    vold_pmpEP2TgtSpd_pct = swc_VCOP_ARID_DEF.DataTypeConversion124;
  }

  /* End of Switch: '<S213>/Switch2' */

  /* Switch: '<S218>/Switch2' incorporates:
   *  Constant: '<S218>/volc_b_waterValveTV1V3_V_ovrdflg'
   */
  if (volc_b_waterValveTV1V3_V_ovrdflg) {
    /* Switch: '<S218>/Switch2' incorporates:
     *  Constant: '<S218>/volc_waterValveTV1V3_V_ovrdval'
     */
    vold_waterValveTV1V3_V = volc_waterValveTV1V3_V_ovrdval;
  } else {
    /* Switch: '<S218>/Switch2' */
    vold_waterValveTV1V3_V = swc_VCOP_ARID_DEF.DataTypeConversion121;
  }

  /* End of Switch: '<S218>/Switch2' */

  /* Switch: '<S219>/Switch2' incorporates:
   *  Constant: '<S219>/volc_b_waterValveTV2V2_V_ovrdflg'
   */
  if (volc_b_waterValveTV2V2_V_ovrdflg) {
    /* Switch: '<S219>/Switch2' incorporates:
     *  Constant: '<S219>/volc_waterValveTV2V2_V_ovrdval'
     */
    vold_waterValveTV2V2_V = volc_waterValveTV2V2_V_ovrdval;
  } else {
    /* Switch: '<S219>/Switch2' */
    vold_waterValveTV2V2_V = swc_VCOP_ARID_DEF.DataTypeConversion145;
  }

  /* End of Switch: '<S219>/Switch2' */

  /* Switch: '<S217>/Switch2' incorporates:
   *  Constant: '<S217>/volc_b_steerPumpEn_invert'
   *  Constant: '<S217>/volc_b_steerPumpEn_ovrdflg'
   *  Switch: '<S217>/Switch1'
   */
  if (volc_b_steerPumpEn_ovrdflg) {
    /* Switch: '<S217>/Switch2' incorporates:
     *  Constant: '<S217>/volc_steerPumpEn_ovrdval'
     */
    vold_steerPumpEn = volc_steerPumpEn_ovrdval;
  } else if (volc_b_steerPumpEn_invert) {
    /* Switch: '<S217>/Switch1' incorporates:
     *  DataTypeConversion: '<S217>/type_conv'
     *  Logic: '<S217>/Logical Operator'
     *  Switch: '<S217>/Switch2'
     */
    vold_steerPumpEn = !hvbd_b_sdcacEna;
  } else {
    /* Switch: '<S217>/Switch2' incorporates:
     *  DataTypeConversion: '<S217>/type_conv'
     *  Switch: '<S217>/Switch1'
     */
    vold_steerPumpEn = hvbd_b_sdcacEna;
  }

  /* End of Switch: '<S217>/Switch2' */

  /* Switch: '<S556>/Switch2' incorporates:
   *  Constant: '<S543>/volc_flg_VCU_MainPosCtrlCommand_ovrdflg'
   */
  if (volc_b_VCU_MainPosCtrlCommand_ovrdflg) {
    /* Switch: '<S556>/Switch2' incorporates:
     *  Constant: '<S543>/volc_VCU_MainPosCtrlCommand_ovrdval'
     */
    vold_VCU_MainPosCtrlCommand = volc_VCU_MainPosCtrlCommand_ovrdval;
  } else {
    /* Switch: '<S556>/Switch2' */
    vold_VCU_MainPosCtrlCommand = swc_VCOP_ARID_DEF.DataTypeConversion87;
  }

  /* End of Switch: '<S556>/Switch2' */

  /* Switch: '<S202>/Switch2' incorporates:
   *  Constant: '<S202>/volc_b_emergStopEn_invert'
   *  Constant: '<S202>/volc_b_emergStopEn_ovrdflg'
   *  Switch: '<S202>/Switch1'
   */
  if (volc_b_emergStopEn_ovrdflg) {
    /* Switch: '<S202>/Switch2' incorporates:
     *  Constant: '<S202>/volc_emergStopEn_ovrdval'
     */
    vold_emergStopEn = volc_emergStopEn_ovrdval;
  } else if (volc_b_emergStopEn_invert) {
    /* Switch: '<S202>/Switch1' incorporates:
     *  Constant: '<S158>/Constant5'
     *  Logic: '<S158>/Logical Operator'
     *  Logic: '<S202>/Logical Operator'
     *  RelationalOperator: '<S158>/Relational Operator2'
     *  Switch: '<S202>/Switch2'
     */
    vold_emergStopEn = (vold_VCU_MainPosCtrlCommand == ((uint8)1U));
  } else {
    /* Switch: '<S202>/Switch2' incorporates:
     *  Constant: '<S158>/Constant5'
     *  Logic: '<S158>/Logical Operator'
     *  RelationalOperator: '<S158>/Relational Operator2'
     *  Switch: '<S202>/Switch1'
     */
    vold_emergStopEn = (vold_VCU_MainPosCtrlCommand != ((uint8)1U));
  }

  /* End of Switch: '<S202>/Switch2' */

  /* Switch: '<S182>/Switch2' incorporates:
   *  Constant: '<S182>/volc_b_12vDCDCEn_invert'
   *  Constant: '<S182>/volc_b_12vDCDCEn_ovrdflg'
   *  Switch: '<S182>/Switch1'
   */
  if (volc_b_12vDCDCEn_ovrdflg) {
    /* Switch: '<S182>/Switch2' incorporates:
     *  Constant: '<S182>/volc_12vDCDCEn_ovrdval'
     */
    vold_12vDCDCEn = volc_12vDCDCEn_ovrdval;
  } else if (volc_b_12vDCDCEn_invert) {
    /* Switch: '<S182>/Switch1' incorporates:
     *  DataTypeConversion: '<S182>/type_conv'
     *  Logic: '<S182>/Logical Operator'
     *  Switch: '<S182>/Switch2'
     */
    vold_12vDCDCEn = !dccd_b_dcdcEna;
  } else {
    /* Switch: '<S182>/Switch2' incorporates:
     *  DataTypeConversion: '<S182>/type_conv'
     *  Switch: '<S182>/Switch1'
     */
    vold_12vDCDCEn = dccd_b_dcdcEna;
  }

  /* End of Switch: '<S182>/Switch2' */

  /* Switch: '<S183>/Switch2' incorporates:
   *  Constant: '<S183>/volc_b_24vDCDCEn_invert'
   *  Constant: '<S183>/volc_b_24vDCDCEn_ovrdflg'
   *  Switch: '<S183>/Switch1'
   */
  if (volc_b_24vDCDCEn_ovrdflg) {
    /* Switch: '<S183>/Switch2' incorporates:
     *  Constant: '<S183>/volc_24vDCDCEn_ovrdval'
     */
    vold_24vDCDCEn = volc_24vDCDCEn_ovrdval;
  } else if (volc_b_24vDCDCEn_invert) {
    /* Switch: '<S183>/Switch1' incorporates:
     *  DataTypeConversion: '<S183>/type_conv'
     *  Logic: '<S183>/Logical Operator'
     *  Switch: '<S183>/Switch2'
     */
    vold_24vDCDCEn = !dccd_b_dcdcEna;
  } else {
    /* Switch: '<S183>/Switch2' incorporates:
     *  DataTypeConversion: '<S183>/type_conv'
     *  Switch: '<S183>/Switch1'
     */
    vold_24vDCDCEn = dccd_b_dcdcEna;
  }

  /* End of Switch: '<S183>/Switch2' */

  /* Switch: '<S201>/Switch2' incorporates:
   *  Constant: '<S201>/volc_b_brkPmpEn_invert'
   *  Constant: '<S201>/volc_b_brkPmpEn_ovrdflg'
   *  Switch: '<S201>/Switch1'
   */
  if (volc_b_brkPmpEn_ovrdflg) {
    /* Switch: '<S201>/Switch2' incorporates:
     *  Constant: '<S201>/volc_brkPmpEn_ovrdval'
     */
    vold_brkPmpEn = volc_brkPmpEn_ovrdval;
  } else if (volc_b_brkPmpEn_invert) {
    /* Switch: '<S201>/Switch1' incorporates:
     *  DataTypeConversion: '<S201>/type_conv'
     *  Logic: '<S201>/Logical Operator'
     *  Switch: '<S201>/Switch2'
     */
    vold_brkPmpEn = (swc_VCOP_ARID_DEF.DataTypeConversion91 == 0.0);
  } else {
    /* Switch: '<S201>/Switch2' incorporates:
     *  DataTypeConversion: '<S201>/type_conv'
     *  Switch: '<S201>/Switch1'
     */
    vold_brkPmpEn = (swc_VCOP_ARID_DEF.DataTypeConversion91 != 0.0);
  }

  /* End of Switch: '<S201>/Switch2' */

  /* Switch: '<S181>/Switch2' incorporates:
   *  Constant: '<S181>/vilc_b_ResrAirSwitch_invert'
   *  Constant: '<S181>/volc_b_WatPmpEP3PWM_ovrdflg'
   *  Switch: '<S181>/Switch1'
   */
  if (volc_b_12VbatRlyReq_ovrdflg) {
    /* Switch: '<S181>/Switch2' incorporates:
     *  Constant: '<S181>/volc_WatPmpEP3PWM_ovrdval'
     */
    vold_12VbatRlyReq = volc_12VbatRlyReq_ovrdval;
  } else if (volc_b_12VbatRlyReq_invert) {
    /* Switch: '<S181>/Switch1' incorporates:
     *  DataTypeConversion: '<S181>/type_conv'
     *  Logic: '<S181>/Logical Operator'
     *  SignalConversion: '<S158>/Signal Conversion7'
     *  Switch: '<S181>/Switch2'
     */
    vold_12VbatRlyReq = (swc_VCOP_ARID_DEF.DataTypeConversion156 == 0.0);
  } else {
    /* Switch: '<S181>/Switch2' incorporates:
     *  DataTypeConversion: '<S181>/type_conv'
     *  SignalConversion: '<S158>/Signal Conversion7'
     *  Switch: '<S181>/Switch1'
     */
    vold_12VbatRlyReq = (swc_VCOP_ARID_DEF.DataTypeConversion156 != 0.0);
  }

  /* End of Switch: '<S181>/Switch2' */

  /* Switch: '<S209>/Switch2' incorporates:
   *  Constant: '<S209>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   *  Constant: '<S209>/volc_b_waterValveTV4V3_V_invert'
   *  Switch: '<S209>/Switch1'
   */
  if (volc_b_fan1TgtSpd_ovrdflg) {
    /* Switch: '<S209>/Switch2' incorporates:
     *  Constant: '<S209>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_fan1TgtSpd_pct = volc_pct_fan1TgtSpd_ovrdval;
  } else if (volc_b_fan1TgtSpd_invert) {
    /* Switch: '<S209>/Switch1' incorporates:
     *  Constant: '<S209>/volc_b_waterValveTV4V3_V_invert1'
     *  Constant: '<S209>/volc_b_waterValveTV4V3_V_invert2'
     *  MinMax: '<S209>/MinMax'
     *  Sum: '<S209>/Sum'
     *  Switch: '<S209>/Switch2'
     */
    vold_fan1TgtSpd_pct = fmaxf(100.0F - thmd_n_fan1TgtSpdOutp_pct, 0.0F);
  } else {
    /* Switch: '<S209>/Switch2' incorporates:
     *  Switch: '<S209>/Switch1'
     */
    vold_fan1TgtSpd_pct = thmd_n_fan1TgtSpdOutp_pct;
  }

  /* End of Switch: '<S209>/Switch2' */

  /* Switch: '<S210>/Switch2' incorporates:
   *  Constant: '<S210>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   *  Constant: '<S210>/volc_b_waterValveTV4V3_V_invert'
   *  Switch: '<S210>/Switch1'
   */
  if (volc_b_fan2TgtSpd_ovrdflg) {
    /* Switch: '<S210>/Switch2' incorporates:
     *  Constant: '<S210>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_fan2TgtSpd_pct = volc_pct_fan2TgtSpd_ovrdval;
  } else if (volc_b_fan2TgtSpd_invert) {
    /* Switch: '<S210>/Switch1' incorporates:
     *  Constant: '<S210>/volc_b_waterValveTV4V3_V_invert1'
     *  Constant: '<S210>/volc_b_waterValveTV4V3_V_invert2'
     *  MinMax: '<S210>/MinMax'
     *  Sum: '<S210>/Sum'
     *  Switch: '<S210>/Switch2'
     */
    vold_fan2TgtSpd_pct = fmaxf(100.0F - thmd_n_fan2TgtSpdOutp_pct, 0.0F);
  } else {
    /* Switch: '<S210>/Switch2' incorporates:
     *  Switch: '<S210>/Switch1'
     */
    vold_fan2TgtSpd_pct = thmd_n_fan2TgtSpdOutp_pct;
  }

  /* End of Switch: '<S210>/Switch2' */

  /* Switch: '<S212>/Switch2' incorporates:
   *  Constant: '<S212>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   */
  if (volc_b_pmpEP1TgtSpd_ovrdflg) {
    /* Switch: '<S212>/Switch2' incorporates:
     *  Constant: '<S212>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_pmpEP1TgtSpd_pct = volc_pct_pmpEP1TgtSpd_ovrdval;
  } else {
    /* Switch: '<S212>/Switch2' */
    vold_pmpEP1TgtSpd_pct = swc_VCOP_ARID_DEF.TmpBufferAtGround1Outport1;
  }

  /* End of Switch: '<S212>/Switch2' */

  /* Switch: '<S194>/Switch2' incorporates:
   *  Constant: '<S194>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S194>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S194>/Switch1'
   */
  if (volc_b_cntnrPwrEna_ovrdflg) {
    /* Switch: '<S194>/Switch2' incorporates:
     *  Constant: '<S194>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_cntnrPwrEna = volc_b_cntnrPwrEna_ovrdval;
  } else if (volc_b_cntnrPwrEna_invert) {
    /* Switch: '<S194>/Switch2' incorporates:
     *  DataTypeConversion: '<S194>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in37'
     *  Logic: '<S194>/Logical Operator'
     *  Switch: '<S194>/Switch1'
     */
    vold_b_cntnrPwrEna =
      !Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd();
  } else {
    /* Switch: '<S194>/Switch2' incorporates:
     *  DataTypeConversion: '<S194>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in37'
     *  Switch: '<S194>/Switch1'
     */
    vold_b_cntnrPwrEna = Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd
      ();
  }

  /* End of Switch: '<S194>/Switch2' */

  /* Switch: '<S211>/Switch2' incorporates:
   *  Constant: '<S211>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   *  Constant: '<S211>/volc_b_waterValveTV4V3_V_invert'
   *  Switch: '<S211>/Switch1'
   */
  if (volc_b_fan3TgtSpd_ovrdflg) {
    /* Switch: '<S211>/Switch2' incorporates:
     *  Constant: '<S211>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_fan3TgtSpd_pct = volc_pct_fan3TgtSpd_ovrdval;
  } else if (volc_b_fan3TgtSpd_invert) {
    /* Switch: '<S211>/Switch1' incorporates:
     *  Constant: '<S180>/volc_pct_fan3TgtSpd_dftval'
     *  Constant: '<S211>/volc_b_waterValveTV4V3_V_invert1'
     *  Constant: '<S211>/volc_b_waterValveTV4V3_V_invert2'
     *  MinMax: '<S211>/MinMax'
     *  Sum: '<S211>/Sum'
     *  Switch: '<S211>/Switch2'
     */
    vold_fan3TgtSpd_pct = fmaxf(100.0F - (float32)volc_pct_fan3TgtSpd_dftval,
      0.0F);
  } else {
    /* Switch: '<S211>/Switch2' incorporates:
     *  Constant: '<S180>/volc_pct_fan3TgtSpd_dftval'
     *  Switch: '<S211>/Switch1'
     */
    vold_fan3TgtSpd_pct = (float32)volc_pct_fan3TgtSpd_dftval;
  }

  /* End of Switch: '<S211>/Switch2' */

  /* Switch: '<S199>/Switch2' incorporates:
   *  Constant: '<S199>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S199>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S199>/Switch1'
   */
  if (volc_b_motFanRlyReq_ovrdflg) {
    /* Switch: '<S199>/Switch2' incorporates:
     *  Constant: '<S199>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_motFanRlyReq = volc_b_motFanRlyReq_ovrdval;
  } else if (volc_b_motFanRlyReq_invert) {
    /* Switch: '<S199>/Switch1' incorporates:
     *  DataTypeConversion: '<S199>/type_conv'
     *  Logic: '<S199>/Logical Operator'
     *  Switch: '<S199>/Switch2'
     */
    vold_b_motFanRlyReq = !thmd_b_motFanRlyReq;
  } else {
    /* Switch: '<S199>/Switch2' incorporates:
     *  DataTypeConversion: '<S199>/type_conv'
     *  Switch: '<S199>/Switch1'
     */
    vold_b_motFanRlyReq = thmd_b_motFanRlyReq;
  }

  /* End of Switch: '<S199>/Switch2' */

  /* Switch: '<S198>/Switch2' incorporates:
   *  Constant: '<S198>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S198>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S198>/Switch1'
   */
  if (volc_b_mainPosRlyReq_ovrdflg) {
    /* Switch: '<S198>/Switch2' incorporates:
     *  Constant: '<S198>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_mainPosRlyReq = volc_b_mainPosRlyReq_ovrdval;
  } else if (volc_b_mainPosRlyReq_invert) {
    /* Switch: '<S198>/Switch1' incorporates:
     *  DataTypeConversion: '<S198>/type_conv'
     *  Logic: '<S198>/Logical Operator'
     *  Switch: '<S198>/Switch2'
     */
    vold_b_mainPosRlyReq = !hvbd_b_hcmRlyEna;
  } else {
    /* Switch: '<S198>/Switch2' incorporates:
     *  DataTypeConversion: '<S198>/type_conv'
     *  Switch: '<S198>/Switch1'
     */
    vold_b_mainPosRlyReq = hvbd_b_hcmRlyEna;
  }

  /* End of Switch: '<S198>/Switch2' */

  /* Switch: '<S200>/Switch2' incorporates:
   *  Constant: '<S200>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S200>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S200>/Switch1'
   */
  if (volc_b_preChrgRlyReq_ovrdflg) {
    /* Switch: '<S200>/Switch2' incorporates:
     *  Constant: '<S200>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_preChrgRlyReq = volc_b_preChrgRlyReq_ovrdval;
  } else if (volc_b_preChrgRlyReq_invert) {
    /* Switch: '<S200>/Switch1' incorporates:
     *  Constant: '<S180>/volc_b_preChrgRlyReq_dftval'
     *  DataTypeConversion: '<S200>/type_conv'
     *  Logic: '<S200>/Logical Operator'
     *  Switch: '<S200>/Switch2'
     */
    vold_b_preChrgRlyReq = !volc_b_preChrgRlyReq_dftval;
  } else {
    /* Switch: '<S200>/Switch2' incorporates:
     *  Constant: '<S180>/volc_b_preChrgRlyReq_dftval'
     *  DataTypeConversion: '<S200>/type_conv'
     *  Switch: '<S200>/Switch1'
     */
    vold_b_preChrgRlyReq = volc_b_preChrgRlyReq_dftval;
  }

  /* End of Switch: '<S200>/Switch2' */

  /* Switch: '<S214>/Switch2' incorporates:
   *  Constant: '<S214>/volc_b_pmpEP3TgtSpd_pct_ovrdflg'
   */
  if (volc_b_pmpEP3TgtFre_Hz_ovrdflg) {
    /* Switch: '<S214>/Switch2' incorporates:
     *  Constant: '<S214>/volc_pmpEP3TgtSpd_pct_ovrdval'
     */
    vold_pmpEP3TgtFre_Hz = volc_pmpEP3TgtFre_Hz_ovrdval;
  } else {
    /* Switch: '<S214>/Switch2' incorporates:
     *  Constant: '<S180>/volc_frq_pmpEP3TgtFre_Hz_dftval'
     */
    vold_pmpEP3TgtFre_Hz = volc_frq_pmpEP3TgtFre_Hz_dftval;
  }

  /* End of Switch: '<S214>/Switch2' */

  /* Switch: '<S186>/Switch2' incorporates:
   *  Constant: '<S186>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S186>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S186>/Switch1'
   */
  if (volc_b_ResetHSDFRA16A17_ovrdflg) {
    /* Switch: '<S186>/Switch2' incorporates:
     *  Constant: '<S186>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_ResetHSDFRA16A17 = volc_b_ResetHSDFRA16A17_ovrdval;
  } else if (volc_b_ResetHSDFRA16A17_invert) {
    /* Switch: '<S186>/Switch2' incorporates:
     *  DataTypeConversion: '<S186>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Logic: '<S186>/Logical Operator'
     *  Switch: '<S186>/Switch1'
     */
    vold_b_ResetHSDFRA16A17 =
      !Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  } else {
    /* Switch: '<S186>/Switch2' incorporates:
     *  DataTypeConversion: '<S186>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Switch: '<S186>/Switch1'
     */
    vold_b_ResetHSDFRA16A17 =
      Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  }

  /* End of Switch: '<S186>/Switch2' */

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S187>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S187>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S187>/Switch1'
   */
  if (volc_b_ResetHSDFRA1A2_ovrdflg) {
    /* Switch: '<S187>/Switch2' incorporates:
     *  Constant: '<S187>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_ResetHSDFRA1A2 = volc_b_ResetHSDFRA1A2_ovrdval;
  } else if (volc_b_ResetHSDFRA1A2_invert) {
    /* Switch: '<S187>/Switch2' incorporates:
     *  DataTypeConversion: '<S187>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Logic: '<S187>/Logical Operator'
     *  Switch: '<S187>/Switch1'
     */
    vold_b_ResetHSDFRA1A2 =
      !Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  } else {
    /* Switch: '<S187>/Switch2' incorporates:
     *  DataTypeConversion: '<S187>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Switch: '<S187>/Switch1'
     */
    vold_b_ResetHSDFRA1A2 = Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear
      ();
  }

  /* End of Switch: '<S187>/Switch2' */

  /* Switch: '<S188>/Switch2' incorporates:
   *  Constant: '<S188>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S188>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S188>/Switch1'
   */
  if (volc_b_ResetHSDFRA31A32_ovrdflg) {
    /* Switch: '<S188>/Switch2' incorporates:
     *  Constant: '<S188>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_ResetHSDFRA31A32 = volc_b_ResetHSDFRA31A32_ovrdval;
  } else if (volc_b_ResetHSDFRA31A32_invert) {
    /* Switch: '<S188>/Switch2' incorporates:
     *  DataTypeConversion: '<S188>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Logic: '<S188>/Logical Operator'
     *  Switch: '<S188>/Switch1'
     */
    vold_b_ResetHSDFRA31A32 =
      !Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  } else {
    /* Switch: '<S188>/Switch2' incorporates:
     *  DataTypeConversion: '<S188>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Switch: '<S188>/Switch1'
     */
    vold_b_ResetHSDFRA31A32 =
      Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  }

  /* End of Switch: '<S188>/Switch2' */

  /* Switch: '<S189>/Switch2' incorporates:
   *  Constant: '<S189>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S189>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S189>/Switch1'
   */
  if (volc_b_ResetHSDFRA46A47_ovrdflg) {
    /* Switch: '<S189>/Switch2' incorporates:
     *  Constant: '<S189>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_ResetHSDFRA46A47 = volc_b_ResetHSDFRA46A47_ovrdval;
  } else if (volc_b_ResetHSDFRA46A47_invert) {
    /* Switch: '<S189>/Switch2' incorporates:
     *  DataTypeConversion: '<S189>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Logic: '<S189>/Logical Operator'
     *  Switch: '<S189>/Switch1'
     */
    vold_b_ResetHSDFRA46A47 =
      !Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  } else {
    /* Switch: '<S189>/Switch2' incorporates:
     *  DataTypeConversion: '<S189>/type_conv'
     *  Inport generated from: '<Root>/vcsb_VOMM_in16'
     *  Switch: '<S189>/Switch1'
     */
    vold_b_ResetHSDFRA46A47 =
      Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_hsdFltClear();
  }

  /* End of Switch: '<S189>/Switch2' */

  /* Switch: '<S193>/Switch2' incorporates:
   *  Constant: '<S193>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S193>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S193>/Switch1'
   */
  if (volc_b_cntnrCtrlEna_ovrdflg) {
    /* Switch: '<S193>/Switch2' incorporates:
     *  Constant: '<S193>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_cntnrCtrlEna = volc_b_cntnrCtrlEna_ovrdval;
  } else if (volc_b_cntnrCtrlEna_invert) {
    /* Switch: '<S193>/Switch2' incorporates:
     *  DataTypeConversion: '<S193>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in38'
     *  Logic: '<S193>/Logical Operator'
     *  Switch: '<S193>/Switch1'
     */
    vold_b_cntnrCtrlEna = !Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd
      ();
  } else {
    /* Switch: '<S193>/Switch2' incorporates:
     *  DataTypeConversion: '<S193>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in38'
     *  Switch: '<S193>/Switch1'
     */
    vold_b_cntnrCtrlEna = Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd();
  }

  /* End of Switch: '<S193>/Switch2' */

  /* Switch: '<S205>/Switch2' incorporates:
   *  Constant: '<S205>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   */
  if (volc_b_AccPedal_1_ovrdflg) {
    /* Switch: '<S205>/Switch2' incorporates:
     *  Constant: '<S205>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_pct_AccPedal_1 = volc_pct_AccPedal_1_ovrdval;
  } else {
    /* Switch: '<S205>/Switch2' incorporates:
     *  Constant: '<S180>/volc_pct_AccPedal_1_dftval'
     */
    vold_pct_AccPedal_1 = volc_pct_AccPedal_1_dftval;
  }

  /* End of Switch: '<S205>/Switch2' */

  /* Switch: '<S206>/Switch2' incorporates:
   *  Constant: '<S206>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   */
  if (volc_b_AccPedal_2_ovrdflg) {
    /* Switch: '<S206>/Switch2' incorporates:
     *  Constant: '<S206>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_pct_AccPedal_2 = volc_pct_AccPedal_2_ovrdval;
  } else {
    /* Switch: '<S206>/Switch2' incorporates:
     *  Constant: '<S180>/volc_pct_AccPedal_2_dftval'
     */
    vold_pct_AccPedal_2 = volc_pct_AccPedal_2_dftval;
  }

  /* End of Switch: '<S206>/Switch2' */

  /* Switch: '<S207>/Switch2' incorporates:
   *  Constant: '<S207>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   */
  if (volc_b_BrkPedal_1_ovrdflg) {
    /* Switch: '<S207>/Switch2' incorporates:
     *  Constant: '<S207>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_pct_BrkPedal_1 = volc_pct_BrkPedal_1_ovrdval;
  } else {
    /* Switch: '<S207>/Switch2' incorporates:
     *  Constant: '<S180>/volc_pct_BrkPedal_1_dftval'
     */
    vold_pct_BrkPedal_1 = volc_pct_BrkPedal_1_dftval;
  }

  /* End of Switch: '<S207>/Switch2' */

  /* Switch: '<S208>/Switch2' incorporates:
   *  Constant: '<S208>/vilc_b_WatPmpEP2FbPWM_ovrdflg'
   */
  if (volc_b_BrkPedal_2_ovrdflg) {
    /* Switch: '<S208>/Switch2' incorporates:
     *  Constant: '<S208>/vilc_pct_WatPmpEP2FbPWM_ovrdval'
     */
    vold_pct_BrkPedal_2 = volc_pct_BrkPedal_2_ovrdval;
  } else {
    /* Switch: '<S208>/Switch2' incorporates:
     *  Constant: '<S180>/volc_pct_BrkPedal_2_dftval'
     */
    vold_pct_BrkPedal_2 = volc_pct_BrkPedal_2_dftval;
  }

  /* End of Switch: '<S208>/Switch2' */

  /* Switch: '<S216>/Switch2' incorporates:
   *  Constant: '<S216>/vilc_b_ResrAirSwitch_ovrdflg'
   */
  if (volc_b_ShtDown_ovrdflg) {
    /* Switch: '<S216>/Switch2' incorporates:
     *  Constant: '<S216>/vilc_b_ResrAirSwitch_ovrdval'
     */
    vold_st_ShtDown = volc_st_ShtDown_ovrdval;
  } else {
    /* Switch: '<S216>/Switch2' incorporates:
     *  Constant: '<S180>/Constant'
     *  DataTypeConversion: '<S180>/Data Type Conversion'
     *  RelationalOperator: '<S180>/Relational Operator'
     */
    vold_st_ShtDown = (uint8)(swc_VCOP_ARID_DEF.DataTypeConversion151 == ((uint8)
      0U));
  }

  /* End of Switch: '<S216>/Switch2' */

  /* Switch: '<S190>/Switch2' incorporates:
   *  Constant: '<S190>/vilc_b_ResrAirSwitch_invert'
   *  Constant: '<S190>/vilc_b_ResrAirSwitch_ovrdflg'
   *  Switch: '<S190>/Switch1'
   */
  if (volc_b_vcuWkUpCmd_ovrdflg) {
    /* SignalConversion: '<S180>/Signal Conversion1' incorporates:
     *  Constant: '<S190>/vilc_b_ResrAirSwitch_ovrdval'
     *  DataTypeConversion: '<S159>/Data Type Conversion24'
     */
    vold_b_CpsrCtrl = volc_b_vcuWkUpCmd_ovrdval;
  } else if (volc_b_vcuWkUpCmd_invert) {
    /* SignalConversion: '<S180>/Signal Conversion1' incorporates:
     *  DataTypeConversion: '<S190>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in25'
     *  Logic: '<S190>/Logical Operator'
     *  Switch: '<S190>/Switch1'
     */
    vold_b_CpsrCtrl = !Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd();
  } else {
    /* SignalConversion: '<S180>/Signal Conversion1' incorporates:
     *  DataTypeConversion: '<S190>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in25'
     *  Switch: '<S190>/Switch1'
     */
    vold_b_CpsrCtrl = Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd();
  }

  /* End of Switch: '<S190>/Switch2' */

  /* Switch: '<S223>/Switch2' incorporates:
   *  Constant: '<S204>/volc_flg_odpHvilPrdOutpt_ovrdflg'
   */
  if (volc_b_odpHvilPrdOutpt_ovrdflg) {
    /* Switch: '<S223>/Switch2' incorporates:
     *  Constant: '<S204>/volc_tm_odpHvilPrdOutpt_ovrdval'
     */
    vold_tm_odpHvilPrdOutpt = volc_tm_odpHvilPrdOutpt_ovrdval;
  } else {
    /* Switch: '<S223>/Switch2' incorporates:
     *  Constant: '<S180>/Constant11'
     */
    vold_tm_odpHvilPrdOutpt = (float32)volc_pmpTgtPeriod5_us;
  }

  /* End of Switch: '<S223>/Switch2' */

  /* Switch: '<S221>/Switch2' incorporates:
   *  Constant: '<S185>/volc_flg_acHvilPrdOutpt_ovrdflg'
   */
  if (volc_b_acHvilPrdOutpt_ovrdflg) {
    /* Switch: '<S221>/Switch2' incorporates:
     *  Constant: '<S185>/volc_tm_acHvilPrdOutpt_ovrdval'
     */
    vold_tm_acHvilPrdOutpt = volc_tm_acHvilPrdOutpt_ovrdval;
  } else {
    /* Switch: '<S221>/Switch2' incorporates:
     *  Constant: '<S180>/Constant1'
     */
    vold_tm_acHvilPrdOutpt = (float32)volc_pmpTgtPeriod4_us;
  }

  /* End of Switch: '<S221>/Switch2' */

  /* Switch: '<S222>/Switch2' incorporates:
   *  Constant: '<S203>/volc_flg_odpHvilDtyOutpt_ovrdflg'
   */
  if (volc_b_odpHvilDtyOutpt_ovrdflg) {
    /* Switch: '<S222>/Switch2' incorporates:
     *  Constant: '<S203>/volc_pct_odpHvilDtyOutpt_ovrdval'
     */
    vold_pct_odpHvilDtyOutpt = volc_pct_odpHvilDtyOutpt_ovrdval;
  } else {
    /* Switch: '<S222>/Switch2' incorporates:
     *  Constant: '<S180>/Constant10'
     */
    vold_pct_odpHvilDtyOutpt = (float32)volc_n_Spd4_pct;
  }

  /* End of Switch: '<S222>/Switch2' */

  /* Switch: '<S220>/Switch2' incorporates:
   *  Constant: '<S184>/volc_flg_acHvilDtyOutpt_ovrdflg'
   */
  if (volc_b_acHvilDtyOutpt_ovrdflg) {
    /* Switch: '<S220>/Switch2' incorporates:
     *  Constant: '<S184>/volc_pct_acHvilDtyOutpt_ovrdval'
     */
    vold_pct_acHvilDtyOutpt = volc_pct_acHvilDtyOutpt_ovrdval;
  } else {
    /* Switch: '<S220>/Switch2' incorporates:
     *  Constant: '<S180>/Constant7'
     */
    vold_pct_acHvilDtyOutpt = (float32)volc_n_Spd3_pct;
  }

  /* End of Switch: '<S220>/Switch2' */

  /* Switch: '<S197>/Switch2' incorporates:
   *  Constant: '<S197>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S197>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S197>/Switch1'
   */
  if (volc_b_highSpdFanRlyReq_ovrdflg) {
    /* Switch: '<S197>/Switch2' incorporates:
     *  Constant: '<S197>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_highSpdFanRlyReq = volc_b_highSpdFanRlyReq_ovrdval;
  } else if (volc_b_highSpdFanRlyReq_invert) {
    /* Switch: '<S197>/Switch1' incorporates:
     *  DataTypeConversion: '<S197>/type_conv'
     *  Logic: '<S197>/Logical Operator'
     *  Switch: '<S197>/Switch2'
     */
    vold_b_highSpdFanRlyReq = !thmd_b_highSpdFanRlyReq;
  } else {
    /* Switch: '<S197>/Switch2' incorporates:
     *  DataTypeConversion: '<S197>/type_conv'
     *  Switch: '<S197>/Switch1'
     */
    vold_b_highSpdFanRlyReq = thmd_b_highSpdFanRlyReq;
  }

  /* End of Switch: '<S197>/Switch2' */

  /* Switch: '<S196>/Switch2' incorporates:
   *  Constant: '<S196>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S196>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S196>/Switch1'
   */
  if (volc_b_heaterEnaHW_ovrdflg) {
    /* Switch: '<S196>/Switch2' incorporates:
     *  Constant: '<S196>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_heaterEnaHW = volc_b_heaterEnaHW_ovrdval;
  } else if (volc_b_heaterEnaHW_invert) {
    /* Switch: '<S196>/Switch2' incorporates:
     *  DataTypeConversion: '<S196>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in51'
     *  Logic: '<S196>/Logical Operator'
     *  Switch: '<S196>/Switch1'
     */
    vold_b_heaterEnaHW = !Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEnaHW();
  } else {
    /* Switch: '<S196>/Switch2' incorporates:
     *  DataTypeConversion: '<S196>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in51'
     *  Switch: '<S196>/Switch1'
     */
    vold_b_heaterEnaHW = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEnaHW();
  }

  /* End of Switch: '<S196>/Switch2' */

  /* Switch: '<S195>/Switch2' incorporates:
   *  Constant: '<S195>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S195>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S195>/Switch1'
   */
  if (volc_b_heater3EnaHW_ovrdflg) {
    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S195>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_heater3EnaHW = volc_b_heater3EnaHW_ovrdval;
  } else if (volc_b_heater3EnaHW_invert) {
    /* Switch: '<S195>/Switch1' incorporates:
     *  DataTypeConversion: '<S195>/type_conv'
     *  Logic: '<S195>/Logical Operator'
     *  Switch: '<S195>/Switch2'
     */
    vold_b_heater3EnaHW = !swc_VCOP_ARID_DEF.Switch2_g;
  } else {
    /* Switch: '<S195>/Switch2' incorporates:
     *  DataTypeConversion: '<S195>/type_conv'
     *  Switch: '<S195>/Switch1'
     */
    vold_b_heater3EnaHW = swc_VCOP_ARID_DEF.Switch2_g;
  }

  /* End of Switch: '<S195>/Switch2' */

  /* Switch: '<S192>/Switch2' incorporates:
   *  Constant: '<S192>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S192>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S192>/Switch1'
   */
  if (volc_b_accyPreRlyCmd_ovrdflg) {
    /* Switch: '<S192>/Switch2' incorporates:
     *  Constant: '<S192>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_accyPreRlyCmd = volc_b_accyPreRlyCmd_ovrdval;
  } else if (volc_b_accyPreRlyCmd_invert) {
    /* Switch: '<S192>/Switch2' incorporates:
     *  DataTypeConversion: '<S192>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in30'
     *  Logic: '<S192>/Logical Operator'
     *  Switch: '<S192>/Switch1'
     */
    vold_b_accyPreRlyCmd =
      !Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyPreRlyCmd();
  } else {
    /* Switch: '<S192>/Switch2' incorporates:
     *  DataTypeConversion: '<S192>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in30'
     *  Switch: '<S192>/Switch1'
     */
    vold_b_accyPreRlyCmd =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyPreRlyCmd();
  }

  /* End of Switch: '<S192>/Switch2' */

  /* Switch: '<S191>/Switch2' incorporates:
   *  Constant: '<S191>/volc_b_cntnrPwrEna_invert'
   *  Constant: '<S191>/volc_b_cntnrPwrEna_ovrdflg'
   *  Switch: '<S191>/Switch1'
   */
  if (volc_b_VacPumpRlyEn_ovrdflg) {
    /* Switch: '<S191>/Switch2' incorporates:
     *  Constant: '<S191>/volc_b_cntnrPwrEna_ovrdval'
     */
    vold_b_VacPumpRlyEn = volc_b_VacPumpRlyEn_ovrdval;
  } else if (volc_b_VacPumpRlyEn_invert) {
    /* Switch: '<S191>/Switch2' incorporates:
     *  DataTypeConversion: '<S191>/type_conv'
     *  Inport generated from: '<Root>/BusElementIn6'
     *  Logic: '<S191>/Logical Operator'
     *  Switch: '<S191>/Switch1'
     */
    vold_b_VacPumpRlyEn = !Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_b_VacPumpRlyEn
      ();
  } else {
    /* Switch: '<S191>/Switch2' incorporates:
     *  DataTypeConversion: '<S191>/type_conv'
     *  Inport generated from: '<Root>/BusElementIn6'
     *  Switch: '<S191>/Switch1'
     */
    vold_b_VacPumpRlyEn = Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_b_VacPumpRlyEn();
  }

  /* End of Switch: '<S191>/Switch2' */

  /* Switch: '<S290>/Switch2' incorporates:
   *  Constant: '<S262>/volc_b_VCU_ACCY1CtrlCmd_ovrdflg'
   */
  if (volc_b_VCU_ACCY1CtrlCmd_ovrdflg) {
    /* Switch: '<S290>/Switch2' incorporates:
     *  Constant: '<S262>/volc_VCU_ACCY1CtrlCmd_ovrdval'
     */
    vold_VCU_ACCY1CtrlCmd = volc_VCU_ACCY1CtrlCmd_ovrdval;
  } else {
    /* Switch: '<S290>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in39'
     */
    vold_VCU_ACCY1CtrlCmd =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_bbmWrkEnCmd();
  }

  /* End of Switch: '<S290>/Switch2' */

  /* Switch: '<S291>/Switch2' incorporates:
   *  Constant: '<S263>/volc_b_VCU_ACCYEnableIn_ovrdflg'
   */
  if (volc_b_VCU_ACCYEnableIn_ovrdflg) {
    /* Switch: '<S291>/Switch2' incorporates:
     *  Constant: '<S263>/volc_VCU_ACCYEnableIn_ovrdval'
     */
    vold_VCU_ACCYEnableIn = (uint8)volc_VCU_ACCYEnableIn_ovrdval;
  } else {
    /* Switch: '<S291>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in201'
     */
    vold_VCU_ACCYEnableIn = (uint8)
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_AccyEnReq();
  }

  /* End of Switch: '<S291>/Switch2' */

  /* Switch: '<S310>/Switch2' incorporates:
   *  Constant: '<S282>/volc_b_VCU_IntelligentChargeState_ovrdflg'
   */
  if (volc_b_VCU_IntelligentChargeState_ovrdflg) {
    /* Switch: '<S310>/Switch2' incorporates:
     *  Constant: '<S282>/volc_VCU_IntelligentChargeState_ovrdval'
     */
    vold_VCU_IntelligentChargeState = volc_VCU_IntelligentChargeState_ovrdval;
  } else {
    /* Switch: '<S310>/Switch2' */
    vold_VCU_IntelligentChargeState = hvbd_st_hvbIntelChgSt;
  }

  /* End of Switch: '<S310>/Switch2' */

  /* Switch: '<S308>/Switch2' incorporates:
   *  Constant: '<S280>/volc_b_VCU_IntelligentChargeExitReq_ovrdflg'
   */
  if (volc_b_VCU_IntelligentChargeExitReq_ovrdflg) {
    /* Switch: '<S308>/Switch2' incorporates:
     *  Constant: '<S280>/volc_VCU_IntelligentChargeExitReq_ovrdval'
     */
    vold_VCU_IntelligentChargeExitReq =
      volc_VCU_IntelligentChargeExitReq_ovrdval;
  } else {
    /* Switch: '<S308>/Switch2' incorporates:
     *  DataTypeConversion: '<S224>/Data Type Conversion1'
     *  Inport generated from: '<Root>/vcsb_HVSM_in19'
     */
    vold_VCU_IntelligentChargeExitReq = (uint8)
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq();
  }

  /* End of Switch: '<S308>/Switch2' */

  /* Switch: '<S309>/Switch2' incorporates:
   *  Constant: '<S281>/volc_b_VCU_IntelligentChargeQuit_ovrdflg'
   */
  if (volc_b_VCU_IntelligentChargeQuit_ovrdflg) {
    /* Switch: '<S309>/Switch2' incorporates:
     *  Constant: '<S281>/volc_VCU_IntelligentChargeQuit_ovrdval'
     */
    vold_VCU_IntelligentChargeQuit = volc_VCU_IntelligentChargeQuit_ovrdval;
  } else {
    /* Switch: '<S309>/Switch2' */
    vold_VCU_IntelligentChargeQuit = swc_VCOP_ARID_DEF.DataTypeConversion58;
  }

  /* End of Switch: '<S309>/Switch2' */

  /* Switch: '<S312>/Switch2' incorporates:
   *  Constant: '<S284>/volc_b_VCU_PropulSysActive_ovrdflg'
   */
  if (volc_b_VCU_PropulSysActive_ovrdflg) {
    /* Switch: '<S312>/Switch2' incorporates:
     *  Constant: '<S284>/volc_VCU_PropulSysActive_ovrdval'
     */
    vold_VCU_PropulSysActive = volc_VCU_PropulSysActive_ovrdval;
  } else {
    /* Switch: '<S312>/Switch2' incorporates:
     *  Constant: '<S224>/volc_VCU_PropulSysActive_dftval'
     */
    vold_VCU_PropulSysActive = volc_VCU_PropulSysActive_dftval;
  }

  /* End of Switch: '<S312>/Switch2' */

  /* Switch: '<S313>/Switch2' incorporates:
   *  Constant: '<S285>/volc_b_VCU_ePTReleaseSig_ovrdflg'
   */
  if (volc_b_VCU_ePTReleaseSig_ovrdflg) {
    /* Switch: '<S313>/Switch2' incorporates:
     *  Constant: '<S285>/volc_VCU_ePTReleaseSig_ovrdval'
     */
    vold_VCU_ePTReleaseSig = volc_VCU_ePTReleaseSig_ovrdval;
  } else {
    /* Switch: '<S313>/Switch2' */
    vold_VCU_ePTReleaseSig = eadd_st_ead2PTImmoRlsSts;
  }

  /* End of Switch: '<S313>/Switch2' */

  /* Switch: '<S307>/Switch2' incorporates:
   *  Constant: '<S279>/volc_b_VCU_HV_Status_ovrdflg'
   */
  if (volc_b_VCU_HV_Status_ovrdflg) {
    /* Switch: '<S307>/Switch2' incorporates:
     *  Constant: '<S279>/volc_VCU_HV_Status_ovrdval'
     */
    vold_VCU_HV_Status = volc_VCU_HV_Status_ovrdval;
  } else {
    HVBattStatus tmp_0;

    /* RelationalOperator: '<S224>/Relational Operator' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in143'
     *  RelationalOperator: '<S224>/Relational Operator1'
     *  RelationalOperator: '<S224>/Relational Operator2'
     *  RelationalOperator: '<S224>/Relational Operator3'
     */
    tmp_0 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_e_hvbStatus();

    /* Switch: '<S224>/Switch5' incorporates:
     *  Constant: '<S254>/Constant'
     *  Constant: '<S255>/Constant'
     *  Constant: '<S256>/Constant'
     *  Constant: '<S257>/Constant'
     *  Logic: '<S224>/Logical Operator'
     *  Logic: '<S224>/Logical Operator1'
     *  Logic: '<S224>/Logical Operator2'
     *  RelationalOperator: '<S224>/Relational Operator'
     *  RelationalOperator: '<S224>/Relational Operator1'
     *  RelationalOperator: '<S224>/Relational Operator2'
     *  RelationalOperator: '<S224>/Relational Operator3'
     */
    if ((swc_VCOP_ARID_DEF.DataTypeConversion41 == 0) && ((tmp_0 ==
          HVBattStatus_ACTIVE) || (tmp_0 == HVBattStatus_SLOW_CHARGE) || (tmp_0 ==
          HVBattStatus_FAST_CHARGE) || (tmp_0 == HVBattStatus_HEATING))) {
      /* Switch: '<S307>/Switch2' incorporates:
       *  Constant: '<S224>/volc_VCU_AvgFuelVF_dftval1'
       */
      vold_VCU_HV_Status = ((uint8)2U);
    } else {
      /* Switch: '<S307>/Switch2' incorporates:
       *  Constant: '<S224>/volc_VCU_AvgFuelVF_dftval2'
       */
      vold_VCU_HV_Status = ((uint8)0U);
    }

    /* End of Switch: '<S224>/Switch5' */
  }

  /* End of Switch: '<S307>/Switch2' */

  /* Switch: '<S296>/Switch2' incorporates:
   *  Constant: '<S268>/volc_b_VCU_AvgEVConsume_ovrdflg'
   */
  if (volc_b_VCU_AvgEVConsume_ovrdflg) {
    /* Switch: '<S296>/Switch2' incorporates:
     *  Constant: '<S268>/volc_VCU_AvgEVConsume_ovrdval'
     */
    vold_VCU_AvgEVConsume = volc_VCU_AvgEVConsume_ovrdval;
  } else {
    /* Switch: '<S296>/Switch2' */
    vold_VCU_AvgEVConsume = swc_VCOP_ARID_DEF.DataTypeConversion98;
  }

  /* End of Switch: '<S296>/Switch2' */

  /* Switch: '<S297>/Switch2' incorporates:
   *  Constant: '<S269>/volc_b_VCU_AvgFuelVF_ovrdflg'
   */
  if (volc_b_VCU_AvgFuelVF_ovrdflg) {
    /* Switch: '<S297>/Switch2' incorporates:
     *  Constant: '<S269>/volc_VCU_AvgFuelVF_ovrdval'
     */
    vold_VCU_AvgFuelVF = volc_VCU_AvgFuelVF_ovrdval;
  } else {
    /* Switch: '<S297>/Switch2' incorporates:
     *  Constant: '<S224>/volc_VCU_AvgFuelVF_dftval'
     */
    vold_VCU_AvgFuelVF = volc_VCU_AvgFuelVF_dftval;
  }

  /* End of Switch: '<S297>/Switch2' */

  /* Switch: '<S303>/Switch2' incorporates:
   *  Constant: '<S275>/volc_b_VCU_EVDTEodometer_ovrdflg'
   */
  if (volc_b_VCU_EVDTEodometer_ovrdflg) {
    /* Switch: '<S303>/Switch2' incorporates:
     *  Constant: '<S275>/volc_VCU_EVDTEodometer_ovrdval'
     */
    vold_VCU_EVDTEodometer = volc_VCU_EVDTEodometer_ovrdval;
  } else {
    /* Switch: '<S303>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HMIF_in17'
     */
    vold_VCU_EVDTEodometer =
      Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_vehDrvRngStandard_km();
  }

  /* End of Switch: '<S303>/Switch2' */

  /* Switch: '<S304>/Switch2' incorporates:
   *  Constant: '<S276>/volc_b_VCU_FuleDTEodometer_ovrdflg'
   */
  if (volc_b_VCU_FuleDTEodometer_ovrdflg) {
    /* Switch: '<S304>/Switch2' incorporates:
     *  Constant: '<S276>/volc_VCU_FuleDTEodometer_ovrdval'
     */
    vold_VCU_FuleDTEodometer = volc_VCU_FuleDTEodometer_ovrdval;
  } else {
    /* Switch: '<S304>/Switch2' incorporates:
     *  Constant: '<S224>/volc_VCU_FuleDTEodometer_dftval'
     */
    vold_VCU_FuleDTEodometer = volc_VCU_FuleDTEodometer_dftval;
  }

  /* End of Switch: '<S304>/Switch2' */

  /* Switch: '<S295>/Switch2' incorporates:
   *  Constant: '<S267>/volc_b_VCU_AccyPower_back_ovrdflg'
   */
  if (volc_b_VCU_AccyPower_back_ovrdflg) {
    /* Switch: '<S295>/Switch2' incorporates:
     *  Constant: '<S267>/volc_VCU_AccyPower_back_ovrdval'
     */
    vold_VCU_AccyPower_back = volc_VCU_AccyPower_back_ovrdval;
  } else {
    /* Switch: '<S295>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in37'
     */
    vold_VCU_AccyPower_back =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd();
  }

  /* End of Switch: '<S295>/Switch2' */

  /* Switch: '<S292>/Switch2' incorporates:
   *  Constant: '<S264>/volc_b_VCU_ACUCrashfz_Back_ovrdflg'
   */
  if (volc_b_VCU_ACUCrashfz_Back_ovrdflg) {
    /* Switch: '<S292>/Switch2' incorporates:
     *  Constant: '<S264>/volc_VCU_ACUCrashfz_Back_ovrdval'
     */
    vold_VCU_ACUCrashfz_Back = volc_VCU_ACUCrashfz_Back_ovrdval;
  } else {
    /* Switch: '<S292>/Switch2' incorporates:
     *  Constant: '<S224>/volc_VCU_ACUCrashfz_Back_dftval'
     */
    vold_VCU_ACUCrashfz_Back = volc_VCU_ACUCrashfz_Back_dftval;
  }

  /* End of Switch: '<S292>/Switch2' */

  /* Switch: '<S294>/Switch2' incorporates:
   *  Constant: '<S266>/volc_b_VCU_AccyAllowEnable_Ctrl_ovrdflg'
   */
  if (volc_b_VCU_AccyAllowEnable_Ctrl_ovrdflg) {
    /* Switch: '<S294>/Switch2' incorporates:
     *  Constant: '<S266>/volc_VCU_AccyAllowEnable_Ctrl_ovrdval'
     */
    vold_VCU_AccyAllowEnable_Ctrl = volc_VCU_AccyAllowEnable_Ctrl_ovrdval;
  } else {
    /* Switch: '<S294>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in38'
     */
    vold_VCU_AccyAllowEnable_Ctrl =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd();
  }

  /* End of Switch: '<S294>/Switch2' */

  /* Switch: '<S293>/Switch2' incorporates:
   *  Constant: '<S265>/volc_b_VCU_APUSWILED_Ctrl_ovrdflg'
   */
  if (volc_b_VCU_APUSWILED_Ctrl_ovrdflg) {
    /* Switch: '<S293>/Switch2' incorporates:
     *  Constant: '<S265>/volc_VCU_APUSWILED_Ctrl_ovrdval'
     */
    vold_VCU_APUSWILED_Ctrl = volc_VCU_APUSWILED_Ctrl_ovrdval;
  } else {
    /* Switch: '<S293>/Switch2' incorporates:
     *  Constant: '<S224>/volc_VCU_APUSWILED_Ctrl_dftval'
     */
    vold_VCU_APUSWILED_Ctrl = volc_VCU_APUSWILED_Ctrl_dftval;
  }

  /* End of Switch: '<S293>/Switch2' */

  /* Switch: '<S300>/Switch2' incorporates:
   *  Constant: '<S272>/volc_b_VCU_ECOmodeSWILED_Ctrl_ovrdflg'
   */
  if (volc_b_VCU_ECOmodeSWILED_Ctrl_ovrdflg) {
    /* Switch: '<S300>/Switch2' incorporates:
     *  Constant: '<S272>/volc_VCU_ECOmodeSWILED_Ctrl_ovrdval'
     */
    vold_VCU_ECOmodeSWILED_Ctrl = volc_VCU_ECOmodeSWILED_Ctrl_ovrdval;
  } else {
    /* Switch: '<S300>/Switch2' incorporates:
     *  Constant: '<S224>/volc_VCU_ECOmodeSWILED_Ctrl_dftval'
     */
    vold_VCU_ECOmodeSWILED_Ctrl = volc_VCU_ECOmodeSWILED_Ctrl_dftval;
  }

  /* End of Switch: '<S300>/Switch2' */

  /* Switch: '<S311>/Switch2' incorporates:
   *  Constant: '<S283>/volc_b_VCU_LTCoolingFan2FB_ovrdflg'
   */
  if (volc_b_VCU_LTCoolingFan2FB_ovrdflg) {
    /* Switch: '<S311>/Switch2' incorporates:
     *  Constant: '<S283>/volc_VCU_LTCoolingFan2FB_ovrdval'
     */
    vold_VCU_LTCoolingFan2FB = volc_VCU_LTCoolingFan2FB_ovrdval;
  } else {
    /* Switch: '<S311>/Switch2' */
    vold_VCU_LTCoolingFan2FB = 0U;
  }

  /* End of Switch: '<S311>/Switch2' */

  /* Switch: '<S306>/Switch2' incorporates:
   *  Constant: '<S278>/volc_b_VCU_HTCoolingFan1FB_ovrdflg'
   */
  if (volc_b_VCU_HTCoolingFan1FB_ovrdflg) {
    /* Switch: '<S306>/Switch2' incorporates:
     *  Constant: '<S278>/volc_VCU_HTCoolingFan1FB_ovrdval'
     */
    vold_VCU_HTCoolingFan1FB = volc_VCU_HTCoolingFan1FB_ovrdval;
  } else {
    /* Switch: '<S306>/Switch2' */
    vold_VCU_HTCoolingFan1FB = swc_VCOP_ARID_DEF.DataTypeConversion169;
  }

  /* End of Switch: '<S306>/Switch2' */

  /* Switch: '<S305>/Switch2' incorporates:
   *  Constant: '<S277>/volc_b_VCU_HBCP_FaultFB_ovrdflg'
   */
  if (volc_b_VCU_HBCP_FaultFB_ovrdflg) {
    /* Switch: '<S305>/Switch2' incorporates:
     *  Constant: '<S277>/volc_VCU_HBCP_FaultFB_ovrdval'
     */
    vold_VCU_HBCP_FaultFB = volc_VCU_HBCP_FaultFB_ovrdval;
  } else {
    /* Switch: '<S305>/Switch2' */
    vold_VCU_HBCP_FaultFB = swc_VCOP_ARID_DEF.DataTypeConversion171;
  }

  /* End of Switch: '<S305>/Switch2' */

  /* Switch: '<S301>/Switch2' incorporates:
   *  Constant: '<S273>/volc_b_VCU_ECPM_FaultFB_ovrdflg'
   */
  if (volc_b_VCU_ECPM_FaultFB_ovrdflg) {
    /* Switch: '<S301>/Switch2' incorporates:
     *  Constant: '<S273>/volc_VCU_ECPM_FaultFB_ovrdval'
     */
    vold_VCU_ECPM_FaultFB = volc_VCU_ECPM_FaultFB_ovrdval;
  } else {
    /* Switch: '<S301>/Switch2' */
    vold_VCU_ECPM_FaultFB = swc_VCOP_ARID_DEF.DataTypeConversion173;
  }

  /* End of Switch: '<S301>/Switch2' */

  /* Switch: '<S302>/Switch2' incorporates:
   *  Constant: '<S274>/volc_b_VCU_EDCP_FaultFB_ovrdflg'
   */
  if (volc_b_VCU_EDCP_FaultFB_ovrdflg) {
    /* Switch: '<S302>/Switch2' incorporates:
     *  Constant: '<S274>/volc_VCU_EDCP_FaultFB_ovrdval'
     */
    vold_VCU_EDCP_FaultFB = volc_VCU_EDCP_FaultFB_ovrdval;
  } else {
    /* Switch: '<S302>/Switch2' */
    vold_VCU_EDCP_FaultFB = swc_VCOP_ARID_DEF.DataTypeConversion174;
  }

  /* End of Switch: '<S302>/Switch2' */

  /* Switch: '<S298>/Switch2' incorporates:
   *  Constant: '<S270>/volc_b_VCU_BattPackInCoolTempback_ovrdflg'
   */
  if (volc_b_VCU_BattPackInCoolTempback_ovrdflg) {
    /* Switch: '<S298>/Switch2' incorporates:
     *  Constant: '<S270>/volc_VCU_BattPackInCoolTempback_ovrdval'
     */
    vold_VCU_BattPackInCoolTempback = volc_VCU_BattPackInCoolTempback_ovrdval;
  } else {
    /* Switch: '<S298>/Switch2' */
    vold_VCU_BattPackInCoolTempback = swc_VCOP_ARID_DEF.Switch2;
  }

  /* End of Switch: '<S298>/Switch2' */

  /* Switch: '<S299>/Switch2' incorporates:
   *  Constant: '<S271>/volc_b_VCU_BattPackoutCoolTempback_ovrdflg'
   */
  if (volc_b_VCU_BattPackoutCoolTempback_ovrdflg) {
    /* Switch: '<S299>/Switch2' incorporates:
     *  Constant: '<S271>/volc_VCU_BattPackoutCoolTempback_ovrdval'
     */
    vold_VCU_BattPackoutCoolTempback = volc_VCU_BattPackoutCoolTempback_ovrdval;
  } else {
    /* Switch: '<S299>/Switch2' */
    vold_VCU_BattPackoutCoolTempback = swc_VCOP_ARID_DEF.SignalConversion6;
  }

  /* End of Switch: '<S299>/Switch2' */

  /* Switch: '<S287>/Switch2' incorporates:
   *  Constant: '<S259>/volc_b_PMS_BBM_FaultStatus_ovrdflg'
   */
  if (volc_b_PMS_BBM_FaultStatus_ovrdflg) {
    /* Switch: '<S287>/Switch2' incorporates:
     *  Constant: '<S259>/volc_PMS_BBM_FaultStatus_ovrdval'
     */
    vold_PMS_BBM_FaultStatus = volc_PMS_BBM_FaultStatus_ovrdval;
  } else {
    /* Switch: '<S287>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in200'
     */
    vold_PMS_BBM_FaultStatus =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_AccyFltSts();
  }

  /* End of Switch: '<S287>/Switch2' */

  /* Switch: '<S288>/Switch2' incorporates:
   *  Constant: '<S260>/volc_b_PMS_BBM_WorkSts_ovrdflg'
   */
  if (volc_b_PMS_BBM_WorkSts_ovrdflg) {
    /* Switch: '<S288>/Switch2' incorporates:
     *  Constant: '<S260>/volc_PMS_BBM_WorkSts_ovrdval'
     */
    vold_PMS_BBM_WorkSts = volc_PMS_BBM_WorkSts_ovrdval;
  } else {
    /* Switch: '<S288>/Switch2' */
    vold_PMS_BBM_WorkSts = swc_VCOP_ARID_DEF.DataTypeConversion167;
  }

  /* End of Switch: '<S288>/Switch2' */

  /* Switch: '<S289>/Switch2' incorporates:
   *  Constant: '<S261>/volc_b_PMS_DrivingTakeEleSts_ovrdflg'
   */
  if (volc_b_PMS_DrivingTakeEleSts_ovrdflg) {
    /* Switch: '<S289>/Switch2' incorporates:
     *  Constant: '<S261>/volc_PMS_DrivingTakeEleSts_ovrdval'
     */
    vold_PMS_DrivingTakeEleSts = volc_PMS_DrivingTakeEleSts_ovrdval;
  } else {
    /* Switch: '<S289>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in40'
     */
    vold_PMS_DrivingTakeEleSts =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyTakeSts();
  }

  /* End of Switch: '<S289>/Switch2' */

  /* Switch: '<S286>/Switch2' incorporates:
   *  Constant: '<S258>/volc_b_PMS_AccessoryCtrlCommand_ovrdflg'
   */
  if (volc_b_PMS_AccessoryCtrlCommand_ovrdflg) {
    /* Switch: '<S286>/Switch2' incorporates:
     *  Constant: '<S258>/volc_PMS_AccessoryCtrlCommand_ovrdval'
     */
    vold_PMS_AccessoryCtrlCommand = volc_PMS_AccessoryCtrlCommand_ovrdval;
  } else {
    /* Switch: '<S286>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HVSM_in36'
     */
    vold_PMS_AccessoryCtrlCommand =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_accyHvOnCmd();
  }

  /* End of Switch: '<S286>/Switch2' */

  /* Switch: '<S332>/Switch2' incorporates:
   *  Constant: '<S322>/volc_b_VCU_XBREBIMode_ovrdflg'
   */
  if (volc_b_VCU_XBREBIMode_ovrdflg) {
    /* Switch: '<S332>/Switch2' incorporates:
     *  Constant: '<S322>/volc_VCU_XBREBIMode_ovrdval'
     */
    vold_VCU_XBREBIMode = volc_VCU_XBREBIMode_ovrdval;
  } else {
    /* Switch: '<S332>/Switch2' incorporates:
     *  Constant: '<S225>/vold_VCU_XBREBIMode_dftval'
     */
    vold_VCU_XBREBIMode = vold_VCU_XBREBIMode_dftval;
  }

  /* End of Switch: '<S332>/Switch2' */

  /* Switch: '<S326>/Switch2' incorporates:
   *  Constant: '<S316>/volc_b_VCU_GP_Override_ovrdflg'
   */
  if (volc_b_VCU_GP_Override_ovrdflg) {
    /* Switch: '<S326>/Switch2' incorporates:
     *  Constant: '<S316>/volc_VCU_GP_Override_ovrdval'
     */
    vold_VCU_GP_Override = volc_VCU_GP_Override_ovrdval;
  } else {
    /* Switch: '<S326>/Switch2' */
    vold_VCU_GP_Override = swc_VCOP_ARID_DEF.DataTypeConversion223;
  }

  /* End of Switch: '<S326>/Switch2' */

  /* Switch: '<S325>/Switch2' incorporates:
   *  Constant: '<S315>/volc_flg_VCU_ExternalAccDemand_ovrdflg'
   */
  if (volc_b_VCU_ExternalAccDemand_ovrdflg) {
    /* Switch: '<S325>/Switch2' incorporates:
     *  Constant: '<S315>/volc_VCU_ExternalAccDemand_ovrdval'
     */
    vold_VCU_ExternalAccDemand = volc_VCU_ExternalAccDemand_ovrdval;
  } else {
    /* Switch: '<S325>/Switch2' incorporates:
     *  Constant: '<S225>/Constant1'
     *  MinMax: '<S225>/Min'
     */
    vold_VCU_ExternalAccDemand = fminf(0.0F,
      swc_VCOP_ARID_DEF.DataTypeConversion222);
  }

  /* End of Switch: '<S325>/Switch2' */

  /* Switch: '<S329>/Switch2' incorporates:
   *  Constant: '<S319>/volc_b_VCU_VLC_InternalTargetACCeleration_ovrdflg'
   */
  if (volc_b_VCU_VLC_InternalTargetACCeleration_ovrdflg) {
    /* Switch: '<S329>/Switch2' incorporates:
     *  Constant: '<S319>/volc_VCU_VLC_InternalTargetACCeleration_ovrdval'
     */
    vold_VCU_VLC_InternalTargetACCeleration =
      volc_VCU_VLC_InternalTargetACCeleration_ovrdval;
  } else {
    /* Switch: '<S329>/Switch2' */
    vold_VCU_VLC_InternalTargetACCeleration =
      swc_VCOP_ARID_DEF.DataTypeConversion222;
  }

  /* End of Switch: '<S329>/Switch2' */

  /* Relay: '<S225>/Relay4' */
  swc_VCOP_ARID_DEF.Relay4_Mode = ((swc_VCOP_ARID_DEF.DataTypeConversion222 >=
    volc_acc_vehAccXBRDisa_mps2) || ((swc_VCOP_ARID_DEF.DataTypeConversion222 >
    volc_acc_vehAccXBREna_mps2) && swc_VCOP_ARID_DEF.Relay4_Mode));

  /* Switch: '<S331>/Switch2' incorporates:
   *  Constant: '<S321>/volc_flg_VCU_XBRControlMode_ovrdflg'
   *  Relay: '<S225>/Relay4'
   */
  if (volc_b_VCU_XBRControlMode_ovrdflg) {
    /* Switch: '<S331>/Switch2' incorporates:
     *  Constant: '<S321>/volc_VCU_XBRControlMode_ovrdval'
     */
    vold_VCU_XBRControlMode = volc_VCU_XBRControlMode_ovrdval;
  } else if (swc_VCOP_ARID_DEF.Relay4_Mode) {
    /* Relay: '<S225>/Relay4' incorporates:
     *  Switch: '<S331>/Switch2'
     */
    vold_VCU_XBRControlMode = ((uint8)0U);
  } else {
    /* Switch: '<S331>/Switch2' incorporates:
     *  Relay: '<S225>/Relay4'
     */
    vold_VCU_XBRControlMode = ((uint8)1U);
  }

  /* End of Switch: '<S331>/Switch2' */

  /* Switch: '<S330>/Switch2' incorporates:
   *  Constant: '<S320>/volc_b_VCU_VLC_VCUTargetACCeleration_ovrdflg'
   */
  if (volc_b_VCU_VLC_VCUTargetACCeleration_ovrdflg) {
    /* Switch: '<S330>/Switch2' incorporates:
     *  Constant: '<S320>/volc_VCU_VLC_VCUTargetACCeleration_ovrdval'
     */
    vold_VCU_VLC_VCUTargetACCeleration =
      volc_VCU_VLC_VCUTargetACCeleration_ovrdval;
  } else {
    /* Switch: '<S330>/Switch2' incorporates:
     *  Constant: '<S225>/Constant2'
     *  MinMax: '<S225>/Min1'
     */
    vold_VCU_VLC_VCUTargetACCeleration = fmaxf(0.0F,
      swc_VCOP_ARID_DEF.DataTypeConversion225);
  }

  /* End of Switch: '<S330>/Switch2' */

  /* Switch: '<S327>/Switch2' incorporates:
   *  Constant: '<S317>/volc_b_VCU_VLC_Active_ovrdflg'
   */
  if (volc_b_VCU_VLC_Active_ovrdflg) {
    /* Switch: '<S327>/Switch2' incorporates:
     *  Constant: '<S317>/volc_VCU_VLC_Active_ovrdval'
     */
    vold_VCU_VLC_Active = volc_VCU_VLC_Active_ovrdval;
  } else {
    /* Switch: '<S327>/Switch2' */
    vold_VCU_VLC_Active = swc_VCOP_ARID_DEF.DataTypeConversion224;
  }

  /* End of Switch: '<S327>/Switch2' */

  /* Switch: '<S328>/Switch2' incorporates:
   *  Constant: '<S318>/volc_VCU_VLC_Available_ovrdval'
   */
  vold_VCU_VLC_Available = volc_VCU_VLC_Available_ovrdval;

  /* Switch: '<S324>/Switch2' incorporates:
   *  Constant: '<S314>/volc_b_VCU_CC_Acceleration_ovrdflg'
   */
  if (volc_b_VCU_CC_Acceleration_ovrdflg) {
    /* Switch: '<S324>/Switch2' incorporates:
     *  Constant: '<S314>/volc_VCU_CC_Acceleration_ovrdval'
     */
    vold_VCU_CC_Acceleration = volc_VCU_CC_Acceleration_ovrdval;
  } else {
    /* Switch: '<S324>/Switch2' */
    vold_VCU_CC_Acceleration = swc_VCOP_ARID_DEF.DataTypeConversion221;
  }

  /* End of Switch: '<S324>/Switch2' */

  /* Switch: '<S333>/Switch2' incorporates:
   *  Constant: '<S323>/volc_flg_VCU_XBRPriority_ovrdflg'
   */
  if (volc_b_VCU_XBRPriority_ovrdflg) {
    /* Switch: '<S333>/Switch2' incorporates:
     *  Constant: '<S323>/volc_VCU_XBRPriority_ovrdval'
     */
    vold_VCU_XBRPriority = volc_VCU_XBRPriority_ovrdval;
  } else {
    /* Switch: '<S333>/Switch2' incorporates:
     *  Constant: '<S225>/volc_VCU_XBRPriority_dftval'
     */
    vold_VCU_XBRPriority = volc_VCU_XBRPriority_dftval;
  }

  /* End of Switch: '<S333>/Switch2' */

  /* DataTypeConversion: '<S159>/Data Type Conversion2' */
  tmp = fmod(trunc(swc_VCOP_ARID_DEF.SignalConversion1), 256.0);

  /* DataTypeConversion: '<S159>/Data Type Conversion2' */
  rtb_DataTypeConversion2 = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-
    tmp : (sint32)(uint8)tmp);

  /* DataTypeConversion: '<S159>/Data Type Conversion43' */
  rtb_DataTypeConversion43 = swc_VCOP_ARID_DEF.DataTypeConversion190;

  /* Switch: '<S368>/Switch2' incorporates:
   *  Constant: '<S350>/volc_flg_VCU_MCUActiveDischg_ovrdflg'
   */
  if (volc_b_VCU_MCUActiveDischg_ovrdflg) {
    /* Switch: '<S368>/Switch2' incorporates:
     *  Constant: '<S350>/volc_VCU_MCUActiveDischg_ovrdval'
     */
    vold_VCU_MCUActiveDischg = volc_VCU_MCUActiveDischg_ovrdval;
  } else {
    /* Switch: '<S368>/Switch2' incorporates:
     *  Constant: '<S334>/Constant'
     *  DataTypeConversion: '<Root>/Data Type Conversion7'
     *  DataTypeConversion: '<S226>/Data Type Conversion'
     *  RelationalOperator: '<S226>/Relational Operator3'
     */
    vold_VCU_MCUActiveDischg = (uint8)(swc_VCOP_ARID_DEF.DataTypeConversion7 ==
      PmmStatus_MCUDISCHARGE);
  }

  /* End of Switch: '<S368>/Switch2' */

  /* Switch: '<S369>/Switch2' incorporates:
   *  Constant: '<S351>/volc_flg_VCU_Main_Contactor_Control_ovrdflg'
   */
  if (volc_b_VCU_Main_Contactor_Control_ovrdflg) {
    /* Switch: '<S369>/Switch2' incorporates:
     *  Constant: '<S351>/volc_VCU_Main_Contactor_Control_ovrdval'
     */
    vold_VCU_Main_Contactor_Control = volc_VCU_Main_Contactor_Control_ovrdval;
  } else {
    /* Switch: '<S369>/Switch2' incorporates:
     *  Constant: '<S226>/Constant3'
     *  DataTypeConversion: '<S226>/Data Type Conversion2'
     *  RelationalOperator: '<S226>/Relational Operator1'
     */
    vold_VCU_Main_Contactor_Control = (uint8)
      (swc_VCOP_ARID_DEF.DataTypeConversion87 == ((uint8)1U));
  }

  /* End of Switch: '<S369>/Switch2' */

  /* Switch: '<S364>/Switch2' incorporates:
   *  Constant: '<S346>/volc_flg_VCU_Cooling_Control_Request_ovrdflg'
   */
  if (volc_b_VCU_Cooling_Control_Request_ovrdflg) {
    /* Switch: '<S364>/Switch2' incorporates:
     *  Constant: '<S346>/volc_VCU_Cooling_Control_Request_ovrdval'
     */
    vold_VCU_Cooling_Control_Request = volc_VCU_Cooling_Control_Request_ovrdval;
  } else {
    /* Switch: '<S364>/Switch2' incorporates:
     *  Constant: '<S226>/volc_VCU_Cooling_Control_Request_dftval'
     */
    vold_VCU_Cooling_Control_Request = volc_VCU_Cooling_Control_Request_dftval;
  }

  /* End of Switch: '<S364>/Switch2' */

  /* Switch: '<S363>/Switch2' incorporates:
   *  Constant: '<S345>/volc_flg_VCU_Charger_Connected_ovrdflg'
   */
  if (volc_b_VCU_Charger_Connected_ovrdflg) {
    /* Switch: '<S363>/Switch2' incorporates:
     *  Constant: '<S345>/volc_VCU_Charger_Connected_ovrdval'
     */
    vold_VCU_Charger_Connected = volc_VCU_Charger_Connected_ovrdval;
  } else {
    /* Switch: '<S363>/Switch2' incorporates:
     *  DataTypeConversion: '<S226>/Data Type Conversion1'
     *  Inport generated from: '<Root>/vcsb_HVSM_in18'
     */
    vold_VCU_Charger_Connected = (uint8)
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_obcd_b_chargerPlugged();
  }

  /* End of Switch: '<S363>/Switch2' */

  /* Switch: '<S355>/Switch2' incorporates:
   *  Constant: '<S337>/volc_flg_VCU_BattMaxTemp_ovrdflg'
   */
  if (volc_b_VCU_BattMaxTemp_ovrdflg) {
    /* Switch: '<S355>/Switch2' incorporates:
     *  Constant: '<S337>/volc_VCU_BattMaxTemp_ovrdval'
     */
    vold_VCU_BattMaxTemp = volc_VCU_BattMaxTemp_ovrdval;
  } else {
    /* Switch: '<S355>/Switch2' */
    vold_VCU_BattMaxTemp = swc_VCOP_ARID_DEF.DataTypeConversion74;
  }

  /* End of Switch: '<S355>/Switch2' */

  /* Switch: '<S356>/Switch2' incorporates:
   *  Constant: '<S338>/volc_flg_VCU_BattMinTemp_ovrdflg'
   */
  if (volc_b_VCU_BattMinTemp_ovrdflg) {
    /* Switch: '<S356>/Switch2' incorporates:
     *  Constant: '<S338>/volc_VCU_BattMinTemp_ovrdval'
     */
    vold_VCU_BattMinTemp = volc_VCU_BattMinTemp_ovrdval;
  } else {
    /* Switch: '<S356>/Switch2' */
    vold_VCU_BattMinTemp = swc_VCOP_ARID_DEF.DataTypeConversion177;
  }

  /* End of Switch: '<S356>/Switch2' */

  /* Switch: '<S357>/Switch2' incorporates:
   *  Constant: '<S339>/volc_flg_VCU_BattVol_ovrdflg'
   */
  if (volc_b_VCU_BattVol_ovrdflg) {
    /* Switch: '<S357>/Switch2' incorporates:
     *  Constant: '<S339>/volc_VCU_BattVol_ovrdval'
     */
    vold_VCU_BattVol = volc_VCU_BattVol_ovrdval;
  } else {
    /* Switch: '<S357>/Switch2' */
    vold_VCU_BattVol = swc_VCOP_ARID_DEF.SignalConversion11;
  }

  /* End of Switch: '<S357>/Switch2' */

  /* Switch: '<S359>/Switch2' incorporates:
   *  Constant: '<S341>/volc_flg_VCU_Batty_ThermalMangeActive_ovrdflg'
   */
  if (volc_b_VCU_Batty_ThermalMangeActive_ovrdflg) {
    /* Switch: '<S359>/Switch2' incorporates:
     *  Constant: '<S341>/volc_VCU_Batty_ThermalMangeActive_ovrdval'
     */
    vold_VCU_Batty_ThermalMangeActive =
      volc_VCU_Batty_ThermalMangeActive_ovrdval;
  } else {
    /* Switch: '<S359>/Switch2' incorporates:
     *  Constant: '<S226>/volc_VCU_Batty_ThermalMangeActive_dftval'
     */
    vold_VCU_Batty_ThermalMangeActive = volc_VCU_Batty_ThermalMangeActive_dftval;
  }

  /* End of Switch: '<S359>/Switch2' */

  /* Switch: '<S360>/Switch2' incorporates:
   *  Constant: '<S342>/volc_flg_VCU_Batty_ThermalMangeWorkMode_ovrdflg'
   */
  if (volc_b_VCU_Batty_ThermalMangeWorkMode_ovrdflg) {
    /* Switch: '<S360>/Switch2' incorporates:
     *  Constant: '<S342>/volc_VCU_Batty_ThermalMangeWorkMode_ovrdval'
     */
    vold_VCU_Batty_ThermalMangeWorkMode =
      volc_VCU_Batty_ThermalMangeWorkMode_ovrdval;
  } else {
    /* Switch: '<S360>/Switch2' */
    vold_VCU_Batty_ThermalMangeWorkMode = thmd_st_hvbThermMngWorkMod;
  }

  /* End of Switch: '<S360>/Switch2' */

  /* Switch: '<S358>/Switch2' incorporates:
   *  Constant: '<S340>/volc_flg_VCU_Batty_Charge_DisChargeState_ovrdflg'
   */
  if (volc_b_VCU_Batty_Charge_DisChargeState_ovrdflg) {
    /* Switch: '<S358>/Switch2' incorporates:
     *  Constant: '<S340>/volc_VCU_Batty_Charge_DisChargeState_ovrdval'
     */
    vold_VCU_Batty_Charge_DisChargeState =
      volc_VCU_Batty_Charge_DisChargeState_ovrdval;
  } else {
    /* Switch: '<S358>/Switch2' incorporates:
     *  Constant: '<S226>/Constant1'
     *  RelationalOperator: '<S226>/Relational Operator2'
     */
    vold_VCU_Batty_Charge_DisChargeState =
      (swc_VCOP_ARID_DEF.DataTypeConversion179 < 0.0F);
  }

  /* End of Switch: '<S358>/Switch2' */

  /* Switch: '<S361>/Switch2' incorporates:
   *  Constant: '<S343>/volc_VCU_Cab_ThermalMangeReq_ovrdval'
   */
  vold_VCU_Cab_ThermalMangeReq = volc_VCU_Cab_ThermalMangeReq_ovrdval;

  /* Switch: '<S366>/Switch2' incorporates:
   *  Constant: '<S348>/volc_flg_VCU_HVOnOffReq_ovrdflg'
   */
  if (volc_b_VCU_HVOnOffReq_ovrdflg) {
    /* Switch: '<S366>/Switch2' incorporates:
     *  Constant: '<S348>/volc_VCU_HVOnOffReq_ovrdval'
     */
    vold_VCU_HVOnOffReq = volc_VCU_HVOnOffReq_ovrdval;
  } else {
    /* Switch: '<S366>/Switch2' incorporates:
     *  Constant: '<S226>/Constant4'
     *  RelationalOperator: '<S226>/Relational Operator5'
     */
    vold_VCU_HVOnOffReq = (swc_VCOP_ARID_DEF.DataTypeConversion165 == ((uint8)3U));
  }

  /* End of Switch: '<S366>/Switch2' */

  /* Switch: '<S370>/Switch2' incorporates:
   *  Constant: '<S352>/volc_flg_VCU_Set_Temp_ovrdflg'
   */
  if (volc_b_VCU_Set_Temp_ovrdflg) {
    /* Switch: '<S370>/Switch2' incorporates:
     *  Constant: '<S352>/volc_VCU_Set_Temp_ovrdval'
     */
    vold_VCU_Set_Temp = volc_VCU_Set_Temp_ovrdval;
  } else {
    /* Switch: '<S370>/Switch2' */
    vold_VCU_Set_Temp = swc_VCOP_ARID_DEF.SignalConversion7;
  }

  /* End of Switch: '<S370>/Switch2' */

  /* Switch: '<S362>/Switch2' incorporates:
   *  Constant: '<S344>/volc_flg_VCU_Cell_Avg_Temp_ovrdflg'
   */
  if (volc_b_VCU_Cell_Avg_Temp_ovrdflg) {
    /* Switch: '<S362>/Switch2' incorporates:
     *  Constant: '<S344>/volc_VCU_Cell_Avg_Temp_ovrdval'
     */
    vold_VCU_Cell_Avg_Temp = volc_VCU_Cell_Avg_Temp_ovrdval;
  } else {
    /* Switch: '<S362>/Switch2' */
    vold_VCU_Cell_Avg_Temp = swc_VCOP_ARID_DEF.SignalConversion10;
  }

  /* End of Switch: '<S362>/Switch2' */

  /* Switch: '<S367>/Switch2' incorporates:
   *  Constant: '<S349>/volc_b_VCU_HybridReady_ovrdflg'
   */
  if (volc_b_VCU_HybridReady_ovrdflg) {
    /* Switch: '<S367>/Switch2' incorporates:
     *  Constant: '<S349>/volc_VCU_HybridReady_ovrdval'
     */
    vold_VCU_HybridReady = volc_VCU_HybridReady_ovrdval;
  } else {
    /* Switch: '<S367>/Switch2' */
    vold_VCU_HybridReady = swc_VCOP_ARID_DEF.DataTypeConversion41;
  }

  /* End of Switch: '<S367>/Switch2' */

  /* Switch: '<S353>/Switch2' incorporates:
   *  Constant: '<S335>/volc_b_VCU_BMS_SOC_ovrdflg'
   */
  if (volc_b_VCU_BMS_SOC_ovrdflg) {
    /* Switch: '<S353>/Switch2' incorporates:
     *  Constant: '<S335>/volc_VCU_BMS_SOC_ovrdval'
     */
    vold_VCU_BMS_SOC = volc_VCU_BMS_SOC_ovrdval;
  } else {
    /* Switch: '<S353>/Switch2' */
    vold_VCU_BMS_SOC = swc_VCOP_ARID_DEF.DataTypeConversion106;
  }

  /* End of Switch: '<S353>/Switch2' */

  /* Switch: '<S354>/Switch2' incorporates:
   *  Constant: '<S336>/volc_b_VCU_BMS_voltage_ovrdflg'
   */
  if (volc_b_VCU_BMS_voltage_ovrdflg) {
    /* Switch: '<S354>/Switch2' incorporates:
     *  Constant: '<S336>/volc_VCU_BMS_voltage_ovrdval'
     */
    vold_VCU_BMS_voltage = volc_VCU_BMS_voltage_ovrdval;
  } else {
    /* Switch: '<S354>/Switch2' */
    vold_VCU_BMS_voltage = swc_VCOP_ARID_DEF.DataTypeConversion215;
  }

  /* End of Switch: '<S354>/Switch2' */

  /* Switch: '<S365>/Switch2' incorporates:
   *  Constant: '<S347>/volc_b_VCU_EngFuelInstCons_ovrdflg'
   */
  if (volc_b_VCU_EngFuelInstCons_ovrdflg) {
    /* Switch: '<S365>/Switch2' incorporates:
     *  Constant: '<S347>/volc_VCU_EngFuelInstCons_ovrdval'
     */
    vold_VCU_EngFuelInstCons = volc_VCU_EngFuelInstCons_ovrdval;
  } else {
    /* Switch: '<S365>/Switch2' */
    vold_VCU_EngFuelInstCons = swc_VCOP_ARID_DEF.DataTypeConversion108;
  }

  /* End of Switch: '<S365>/Switch2' */

  /* Switch: '<S386>/Switch2' incorporates:
   *  Constant: '<S386>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_PMS_RemChrgCmdFailrPrompt_ovrdflg) {
    /* Switch: '<S386>/Switch2' incorporates:
     *  Constant: '<S386>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_PMS_RemChrgCmdFailrPrompt = volc_PMS_RemChrgCmdFailrPrompt_ovrdval;
  } else {
    /* Switch: '<S386>/Switch2' incorporates:
     *  DataTypeConversion: '<S386>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in4'
     */
    vold_PMS_RemChrgCmdFailrPrompt =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt();
  }

  /* End of Switch: '<S386>/Switch2' */

  /* Switch: '<S390>/Switch2' incorporates:
   *  Constant: '<S390>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_TBOX_ChrgSoftSwCtrlst_ovrdflg) {
    /* Switch: '<S390>/Switch2' incorporates:
     *  Constant: '<S390>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_TBOX_ChrgSoftSwCtrlst = volc_TBOX_ChrgSoftSwCtrlst_ovrdval;
  } else {
    /* Switch: '<S390>/Switch2' incorporates:
     *  DataTypeConversion: '<S390>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in5'
     */
    vold_TBOX_ChrgSoftSwCtrlst =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV();
  }

  /* End of Switch: '<S390>/Switch2' */

  /* Switch: '<S384>/Switch2' incorporates:
   *  Constant: '<S384>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_PMS_LockVehExecutedSts_ovrdflg) {
    /* Switch: '<S384>/Switch2' incorporates:
     *  Constant: '<S384>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_PMS_LockVehExecutedSts = volc_PMS_LockVehExecutedSts_ovrdval;
  } else {
    /* Switch: '<S384>/Switch2' incorporates:
     *  DataTypeConversion: '<S384>/type_conv'
     *  Inport generated from: '<Root>/vcib_VCIP_in11'
     */
    vold_PMS_LockVehExecutedSts =
      Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_st_LockVehExecutedSts();
  }

  /* End of Switch: '<S384>/Switch2' */

  /* Switch: '<S391>/Switch2' incorporates:
   *  Constant: '<S391>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_TBOX_ReservationChrgnSts_ovrdflg) {
    /* Switch: '<S391>/Switch2' incorporates:
     *  Constant: '<S391>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_TBOX_ReservationChrgnSts = volc_TBOX_ReservationChrgnSts_ovrdval;
  } else {
    /* Switch: '<S391>/Switch2' incorporates:
     *  DataTypeConversion: '<S391>/type_conv'
     *  Inport generated from: '<Root>/vcib_VCIP_in186'
     */
    vold_TBOX_ReservationChrgnSts =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_tboxRsrChgSt();
  }

  /* End of Switch: '<S391>/Switch2' */

  /* Switch: '<S381>/Switch2' incorporates:
   *  Constant: '<S381>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_PMS_ChargPwr_ovrdflg) {
    /* Switch: '<S381>/Switch2' incorporates:
     *  Constant: '<S381>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_PMS_ChargPwr = volc_PMS_ChargPwr_ovrdval;
  } else {
    /* Switch: '<S381>/Switch2' incorporates:
     *  DataTypeConversion: '<S381>/type_conv'
     *  Inport generated from: '<Root>/vcib_VCIP_in2'
     */
    vold_PMS_ChargPwr = Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW();
  }

  /* End of Switch: '<S381>/Switch2' */

  /* Switch: '<S377>/Switch2' incorporates:
   *  Constant: '<S377>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_AC_EWP_SpeedReq_ovrdflg) {
    /* Switch: '<S377>/Switch2' incorporates:
     *  Constant: '<S377>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_AC_EWP_SpeedReq = volc_AC_EWP_SpeedReq_ovrdval;
  } else {
    /* Switch: '<S377>/Switch2' incorporates:
     *  DataTypeConversion: '<S377>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in3'
     */
    vold_AC_EWP_SpeedReq = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_acwpSpdReq();
  }

  /* End of Switch: '<S377>/Switch2' */

  /* Switch: '<S374>/Switch2' incorporates:
   *  Constant: '<S374>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_AC_EWP_Heat_ovrdflg) {
    /* Switch: '<S374>/Switch2' incorporates:
     *  Constant: '<S374>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_AC_EWP_Heat = volc_AC_EWP_Heat_ovrdval;
  } else {
    /* Switch: '<S374>/Switch2' incorporates:
     *  DataTypeConversion: '<S374>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in5'
     */
    vold_AC_EWP_Heat = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_acwpHeat();
  }

  /* End of Switch: '<S374>/Switch2' */

  /* Switch: '<S378>/Switch2' incorporates:
   *  Constant: '<S378>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_AC_EWP_Temp_ovrdflg) {
    /* Switch: '<S378>/Switch2' incorporates:
     *  Constant: '<S378>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_AC_EWP_Temp = volc_AC_EWP_Temp_ovrdval;
  } else {
    /* Switch: '<S378>/Switch2' incorporates:
     *  DataTypeConversion: '<S378>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in6'
     */
    vold_AC_EWP_Temp = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_t_acwpTemp_C();
  }

  /* End of Switch: '<S378>/Switch2' */

  /* Switch: '<S376>/Switch2' incorporates:
   *  Constant: '<S376>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_AC_EWP_Run_ovrdflg) {
    /* Switch: '<S376>/Switch2' incorporates:
     *  Constant: '<S376>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_AC_EWP_Run = volc_AC_EWP_Run_ovrdval;
  } else {
    /* Switch: '<S376>/Switch2' incorporates:
     *  DataTypeConversion: '<S376>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in25'
     */
    vold_AC_EWP_Run = (uint8)Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd
      ();
  }

  /* End of Switch: '<S376>/Switch2' */

  /* Switch: '<S375>/Switch2' incorporates:
   *  Constant: '<S375>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_AC_EWP_HeatrPwrCnsAllwd_ovrdflg) {
    /* Switch: '<S375>/Switch2' incorporates:
     *  Constant: '<S375>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_AC_EWP_HeatrPwrCnsAllwd = volc_AC_EWP_HeatrPwrCnsAllwd_ovrdval;
  } else {
    /* Switch: '<S375>/Switch2' incorporates:
     *  Constant: '<S393>/Constant'
     *  Inport generated from: '<Root>/vcsb_EGYM_in1'
     *  Product: '<S393>/Product'
     */
    vold_AC_EWP_HeatrPwrCnsAllwd =
      Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd() *
      ((float32)kXX_2_XX);
  }

  /* End of Switch: '<S375>/Switch2' */

  /* Switch: '<S392>/Switch2' incorporates:
   *  Constant: '<S392>/volc_b_VCU_DriveCircuitTemp_ovrdflg'
   */
  if (volc_b_VCU_DriveCircuitTemp_ovrdflg) {
    /* Switch: '<S392>/Switch2' incorporates:
     *  Constant: '<S392>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_VCU_DriveCircuitTemp = volc_VCU_DriveCircuitTemp_ovrdval;
  } else {
    /* Switch: '<S227>/Switch3' incorporates:
     *  DataTypeConversion: '<S227>/Data Type Conversion'
     *  Gain: '<S227>/Gain5'
     */
    rtb_Switch3_op = 0.001F * (float32)swc_VCOP_ARID_DEF.DataTypeConversion212;

    /* Switch: '<S227>/Switch3' incorporates:
     *  Constant: '<S227>/Constant1'
     *  Constant: '<S227>/Constant2'
     *  Logic: '<S227>/Logical Operator1'
     *  RelationalOperator: '<S227>/Relational Operator16'
     *  RelationalOperator: '<S227>/Relational Operator17'
     *  Saturate: '<S227>/Saturation4'
     */
    if ((rtb_Switch3_op > 4.9F) || (rtb_Switch3_op < 0.1F)) {
      /* Switch: '<S227>/Switch3' incorporates:
       *  Constant: '<S227>/Constant3'
       */
      rtb_Switch3_op = 215.0F;
    } else if (swc_VCOP_ARID_DEF.DataTypeConversion190 > 210.0F) {
      /* Saturate: '<S227>/Saturation4' incorporates:
       *  Switch: '<S227>/Switch3'
       */
      rtb_Switch3_op = 210.0F;
    } else if (swc_VCOP_ARID_DEF.DataTypeConversion190 < (-40.0F)) {
      /* Saturate: '<S227>/Saturation4' incorporates:
       *  Switch: '<S227>/Switch3'
       */
      rtb_Switch3_op = (-40.0F);
    } else {
      /* Switch: '<S227>/Switch3' incorporates:
       *  Saturate: '<S227>/Saturation4'
       */
      rtb_Switch3_op = swc_VCOP_ARID_DEF.DataTypeConversion190;
    }

    /* End of Switch: '<S227>/Switch3' */

    /* DataTypeConversion: '<S392>/type_conv' */
    rtb_Switch3_op = fmodf(floorf(rtb_Switch3_op), 65536.0F);

    /* Switch: '<S392>/Switch2' incorporates:
     *  DataTypeConversion: '<S392>/type_conv'
     */
    vold_VCU_DriveCircuitTemp = (sint16)(rtb_Switch3_op < 0.0F ? (sint32)(sint16)
      -(sint16)(uint16)-rtb_Switch3_op : (sint32)(sint16)(uint16)rtb_Switch3_op);
  }

  /* End of Switch: '<S392>/Switch2' */

  /* Switch: '<S388>/Switch2' incorporates:
   *  Constant: '<S388>/volc_b_VCU_DriveCircuitTemp_ovrdflg'
   */
  if (volc_b_PMS_Torque_Ovrd_Active_ovrdflg) {
    /* Switch: '<S388>/Switch2' incorporates:
     *  Constant: '<S388>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_Torque_Ovrd_Active = volc_PMS_Torque_Ovrd_Active_ovrdval;
  } else {
    /* Switch: '<S388>/Switch2' incorporates:
     *  DataTypeConversion: '<S388>/type_conv'
     *  Inport generated from: '<Root>/vcsb_TCOO_in4'
     */
    vold_PMS_Torque_Ovrd_Active =
      Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_st_ehbOvrdActv();
  }

  /* End of Switch: '<S388>/Switch2' */

  /* Switch: '<S389>/Switch2' incorporates:
   *  Constant: '<S389>/volc_b_VCU_DriveCircuitTemp_ovrdflg'
   */
  if (volc_b_PMS_Torque_Ovrd_Type_ovrdflg) {
    /* Switch: '<S389>/Switch2' incorporates:
     *  Constant: '<S389>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_Torque_Ovrd_Type = volc_PMS_Torque_Ovrd_Type_ovrdval;
  } else {
    /* Switch: '<S389>/Switch2' incorporates:
     *  DataTypeConversion: '<S389>/type_conv'
     *  Inport generated from: '<Root>/vcsb_TCOO_in5'
     */
    vold_PMS_Torque_Ovrd_Type =
      Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_st_ehbOvrdTyp();
  }

  /* End of Switch: '<S389>/Switch2' */

  /* Switch: '<S385>/Switch2' incorporates:
   *  Constant: '<S385>/volc_b_VCU_DriveCircuitTemp_ovrdflg'
   */
  if (volc_b_PMS_RegulationSpeed_ovrdflg) {
    /* Switch: '<S385>/Switch2' incorporates:
     *  Constant: '<S385>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_RegulationSpeed = volc_PMS_RegulationSpeed_ovrdval;
  } else {
    /* DataTypeConversion: '<S385>/type_conv' incorporates:
     *  Inport generated from: '<Root>/BusElementIn1'
     */
    rtb_Switch3_op = fmodf(floorf
      (Rte_IRead_swc_VCOP_Step_vcsb_SCOO_vsld_v_vehMaxSpd_kph()), 256.0F);

    /* Switch: '<S385>/Switch2' incorporates:
     *  DataTypeConversion: '<S385>/type_conv'
     */
    vold_PMS_RegulationSpeed = (uint8)(rtb_Switch3_op < 0.0F ? (sint32)(uint8)-
      (sint8)(uint8)-rtb_Switch3_op : (sint32)(uint8)rtb_Switch3_op);
  }

  /* End of Switch: '<S385>/Switch2' */

  /* Switch: '<S379>/Switch2' incorporates:
   *  Constant: '<S379>/volc_b_VCU_DriveCircuitTemp_ovrdflg'
   */
  if (volc_b_PMS_AcceSuppressionSts_ovrdflg) {
    /* Switch: '<S379>/Switch2' incorporates:
     *  Constant: '<S379>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_AcceSuppressionSts = volc_PMS_AcceSuppressionSts_ovrdval;
  } else {
    /* Switch: '<S379>/Switch2' incorporates:
     *  DataTypeConversion: '<S379>/type_conv'
     *  Inport generated from: '<Root>/BusElementIn2'
     */
    vold_PMS_AcceSuppressionSts =
      Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_st_whlAcceSupprsn();
  }

  /* End of Switch: '<S379>/Switch2' */

  /* Switch: '<S387>/Switch2' incorporates:
   *  Constant: '<S387>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg'
   */
  if (volc_b_PMS_TakeEleSwtIndReq_ovrdflg) {
    /* Switch: '<S387>/Switch2' incorporates:
     *  Constant: '<S387>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_TakeEleSwtIndReq = volc_PMS_TakeEleSwtIndReq_ovrdval;
  } else {
    /* Switch: '<S387>/Switch2' incorporates:
     *  DataTypeConversion: '<S387>/type_conv'
     *  Inport generated from: '<Root>/BusElementIn3'
     */
    vold_PMS_TakeEleSwtIndReq =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq();
  }

  /* End of Switch: '<S387>/Switch2' */

  /* Switch: '<S380>/Switch2' incorporates:
   *  Constant: '<S380>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg'
   */
  if (volc_b_PMS_CPSRU_ovrdflg) {
    /* Switch: '<S380>/Switch2' incorporates:
     *  Constant: '<S380>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_CPSRU = (float32)volc_PMS_CPSRU_ovrdval;
  } else {
    /* Switch: '<S380>/Switch2' incorporates:
     *  Constant: '<S371>/Constant'
     *  DataTypeConversion: '<S380>/type_conv'
     *  Inport generated from: '<Root>/EXT_DO_RELAY_LS_7_Fb'
     *  RelationalOperator: '<S371>/Compare'
     */
    vold_PMS_CPSRU = (float32)
      (Rte_IRead_swc_VCOP_Step_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb() <
       vild_u_RelayClose_V);
  }

  /* End of Switch: '<S380>/Switch2' */

  /* Switch: '<S382>/Switch2' incorporates:
   *  Constant: '<S382>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg'
   */
  if (volc_b_PMS_Fn1GearRlyDrvStsFb_ovrdflg) {
    /* Switch: '<S382>/Switch2' incorporates:
     *  Constant: '<S382>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_Fn1GearRlyDrvStsFb = volc_PMS_Fn1GearRlyDrvStsFb_ovrdval;
  } else {
    /* Switch: '<S382>/Switch2' incorporates:
     *  Constant: '<S372>/Constant'
     *  Inport generated from: '<Root>/EXT_DO_RELAY_LS_9_Fb'
     *  RelationalOperator: '<S372>/Compare'
     */
    vold_PMS_Fn1GearRlyDrvStsFb =
      (Rte_IRead_swc_VCOP_Step_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb() <
       vild_u_RelayClose_V);
  }

  /* End of Switch: '<S382>/Switch2' */

  /* Switch: '<S383>/Switch2' incorporates:
   *  Constant: '<S383>/volc_b_PMS_TakeEleSwtIndReq_ovrdflg'
   */
  if (volc_b_PMS_Fn2GearRlyDrvStsFb_ovrdflg) {
    /* Switch: '<S383>/Switch2' incorporates:
     *  Constant: '<S383>/volc_VCU_DriveCircuitTemp_ovrdval'
     */
    vold_PMS_Fn2GearRlyDrvStsFb = volc_PMS_Fn2GearRlyDrvStsFb_ovrdval;
  } else {
    /* Switch: '<S383>/Switch2' incorporates:
     *  Constant: '<S373>/Constant'
     *  Inport generated from: '<Root>/EXT_DO_RELAY_LS_10_Fb'
     *  RelationalOperator: '<S373>/Compare'
     */
    vold_PMS_Fn2GearRlyDrvStsFb =
      (Rte_IRead_swc_VCOP_Step_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb() <
       vild_u_RelayClose_V);
  }

  /* End of Switch: '<S383>/Switch2' */

  /* Switch: '<S394>/Switch2' incorporates:
   *  Constant: '<S394>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_PTC2Enable_ovrdflg) {
    /* Switch: '<S394>/Switch2' incorporates:
     *  Constant: '<S394>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_PTC2Enable = volc_VCU_PTC2Enable_ovrdval;
  } else {
    /* Switch: '<S394>/Switch2' incorporates:
     *  DataTypeConversion: '<S394>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in35'
     */
    vold_VCU_PTC2Enable = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna2();
  }

  /* End of Switch: '<S394>/Switch2' */

  /* Switch: '<S395>/Switch2' incorporates:
   *  Constant: '<S395>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_PTC3Enable_ovrdflg) {
    /* Switch: '<S395>/Switch2' incorporates:
     *  Constant: '<S395>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_PTC3Enable = volc_VCU_PTC3Enable_ovrdval;
  } else {
    /* Switch: '<S395>/Switch2' incorporates:
     *  DataTypeConversion: '<S395>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in36'
     */
    vold_VCU_PTC3Enable = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna3();
  }

  /* End of Switch: '<S395>/Switch2' */

  /* Switch: '<S396>/Switch2' incorporates:
   *  Constant: '<S396>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_ZeroPwr_Fb_ovrdflg) {
    /* Switch: '<S396>/Switch2' incorporates:
     *  Constant: '<S396>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_ZeroPwr_Fb = volc_VCU_ZeroPwr_Fb_ovrdval;
  } else {
    /* Switch: '<S396>/Switch2' incorporates:
     *  DataTypeConversion: '<S396>/type_conv'
     *  Inport generated from: '<Root>/vcsb_EGYM_in10'
     */
    vold_VCU_ZeroPwr_Fb = Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_b_zeroPwrFb();
  }

  /* End of Switch: '<S396>/Switch2' */

  /* Switch: '<S397>/Switch2' incorporates:
   *  Constant: '<S397>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_DischargeEnable_ovrdflg) {
    /* Switch: '<S397>/Switch2' incorporates:
     *  Constant: '<S397>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_DischargeEnable = volc_VCU_DischargeEnable_ovrdval;
  } else {
    /* Switch: '<S397>/Switch2' incorporates:
     *  Constant: '<S229>/Constant'
     *  DataTypeConversion: '<S397>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in29'
     *  RelationalOperator: '<S229>/Relational Operator'
     */
    vold_VCU_DischargeEnable = (uint8)
      (Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_dchaOn() == true);
  }

  /* End of Switch: '<S397>/Switch2' */

  /* Switch: '<S398>/Switch2' incorporates:
   *  Constant: '<S398>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_PMS_VehicleSysErrorLevelG_ovrdflg) {
    /* Switch: '<S398>/Switch2' incorporates:
     *  Constant: '<S398>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_PMS_VehicleSysErrorLevelG = volc_PMS_VehicleSysErrorLevelG_ovrdval;
  } else {
    /* Switch: '<S398>/Switch2' incorporates:
     *  DataTypeConversion: '<S398>/type_conv'
     */
    vold_PMS_VehicleSysErrorLevelG = swc_VCOP_ARID_DEF.Max;
  }

  /* End of Switch: '<S398>/Switch2' */

  /* Switch: '<S399>/Switch2' incorporates:
   *  Constant: '<S399>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_bmshAlwChgCurrMax_ovrdflg) {
    /* Switch: '<S399>/Switch2' incorporates:
     *  Constant: '<S399>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_BMSHAllowChgCurrentMax = volc_VCU_bmshAlwChgCurrMax_ovrdval;
  } else {
    /* Switch: '<S399>/Switch2' incorporates:
     *  DataTypeConversion: '<S399>/type_conv'
     *  Inport generated from: '<Root>/vcsb_EGYM_in7'
     */
    vold_VCU_BMSHAllowChgCurrentMax =
      Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax();
  }

  /* End of Switch: '<S399>/Switch2' */

  /* Switch: '<S400>/Switch2' incorporates:
   *  Constant: '<S400>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_ChargeDepthReq_ovrdflg) {
    /* Switch: '<S400>/Switch2' incorporates:
     *  Constant: '<S400>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_ChargeDepthReq = volc_VCU_ChargeDepthReq_ovrdval;
  } else {
    /* Switch: '<S400>/Switch2' incorporates:
     *  DataTypeConversion: '<S400>/type_conv'
     *  Inport generated from: '<Root>/vcsb_EGYM_in8'
     */
    vold_VCU_ChargeDepthReq =
      Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pct_vcuChgDepReq();
  }

  /* End of Switch: '<S400>/Switch2' */

  /* Switch: '<S427>/Switch2' incorporates:
   *  Constant: '<S412>/volc_flg_VCU_Batty_ThermalMangeReq_ovrdflg'
   */
  if (volc_b_VCU_Batty_ThermalMangeReq_ovrdflg) {
    /* Switch: '<S427>/Switch2' incorporates:
     *  Constant: '<S412>/volc_VCU_Batty_ThermalMangeReq_ovrdval'
     */
    vold_VCU_Batty_ThermalMangeReq = volc_VCU_Batty_ThermalMangeReq_ovrdval;
  } else {
    /* Switch: '<S427>/Switch2' */
    vold_VCU_Batty_ThermalMangeReq = swc_VCOP_ARID_DEF.DataTypeConversion170;
  }

  /* End of Switch: '<S427>/Switch2' */

  /* Switch: '<S426>/Switch2' incorporates:
   *  Constant: '<S411>/volc_flg_VCU_BatteryCoolentTemp_ovrdflg'
   */
  if (volc_b_VCU_BatteryCoolentTemp_ovrdflg) {
    /* Switch: '<S426>/Switch2' incorporates:
     *  Constant: '<S411>/volc_VCU_BatteryCoolentTemp_ovrdval'
     */
    vold_VCU_BatteryCoolentTemp = volc_VCU_BatteryCoolentTemp_ovrdval;
  } else {
    /* Switch: '<S426>/Switch2' */
    vold_VCU_BatteryCoolentTemp = dspd_t_battCooltTemp_C;
  }

  /* End of Switch: '<S426>/Switch2' */

  /* Switch: '<S423>/Switch2' incorporates:
   *  Constant: '<S408>/volc_b_VCU_ACCMEnable_ovrdflg'
   */
  if (volc_b_VCU_ACCMEnable_ovrdflg) {
    /* Switch: '<S423>/Switch2' incorporates:
     *  Constant: '<S408>/volc_VCU_ACCMEnable_ovrdval'
     */
    vold_VCU_ACCMEnable = volc_VCU_ACCMEnable_ovrdval;
  } else {
    /* Switch: '<S423>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion58'
     *  Inport generated from: '<Root>/vcsb_THSM_in7'
     */
    vold_VCU_ACCMEnable = (uint8)
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_accmEnb();
  }

  /* End of Switch: '<S423>/Switch2' */

  /* Switch: '<S429>/Switch2' incorporates:
   *  Constant: '<S414>/volc_b_VCU_PTCEnable_ovrdflg'
   */
  if (volc_b_VCU_PTCEnable_ovrdflg) {
    /* Switch: '<S429>/Switch2' incorporates:
     *  Constant: '<S414>/volc_VCU_PTCEnable_ovrdval'
     */
    vold_VCU_PTCEnable = volc_VCU_PTCEnable_ovrdval;
  } else {
    /* Switch: '<S429>/Switch2' */
    vold_VCU_PTCEnable = rtb_DataTypeConversion2;
  }

  /* End of Switch: '<S429>/Switch2' */

  /* Switch: '<S430>/Switch2' incorporates:
   *  Constant: '<S415>/volc_b_VCU_WPCtrl_ovrdflg'
   */
  if (volc_b_VCU_WPCtrl_ovrdflg) {
    /* Switch: '<S430>/Switch2' incorporates:
     *  Constant: '<S415>/volc_VCU_WPCtrl_ovrdval'
     */
    vold_VCU_WPCtrl = volc_VCU_WPCtrl_ovrdval;
  } else {
    /* Switch: '<S430>/Switch2' incorporates:
     *  SignalConversion: '<S232>/Signal Conversion'
     */
    vold_VCU_WPCtrl = rtb_DataTypeConversion2;
  }

  /* End of Switch: '<S430>/Switch2' */

  /* Switch: '<S424>/Switch2' incorporates:
   *  Constant: '<S409>/volc_b_VCU_BattPackInCoolTemp_ovrdflg'
   */
  if (volc_b_VCU_BattPackInCoolTemp_ovrdflg) {
    /* Switch: '<S424>/Switch2' incorporates:
     *  Constant: '<S409>/volc_VCU_BattPackInCoolTemp_ovrdval'
     */
    vold_VCU_BattPackInCoolTemp = volc_VCU_BattPackInCoolTemp_ovrdval;
  } else {
    /* Switch: '<S424>/Switch2' */
    vold_VCU_BattPackInCoolTemp = swc_VCOP_ARID_DEF.thmd_t_hvbHdInCoolTemp_C;
  }

  /* End of Switch: '<S424>/Switch2' */

  /* Switch: '<S425>/Switch2' incorporates:
   *  Constant: '<S410>/volc_b_VCU_BattPackoutCoolTemp_ovrdflg'
   */
  if (volc_b_VCU_BattPackOutCoolTemp_ovrdflg) {
    /* Switch: '<S425>/Switch2' incorporates:
     *  Constant: '<S410>/volc_VCU_BattPackoutCoolTemp_ovrdval'
     */
    vold_VCU_BattPackOutCoolTemp = volc_VCU_BattPackOutCoolTemp_ovrdval;
  } else {
    /* Switch: '<S425>/Switch2' */
    vold_VCU_BattPackOutCoolTemp = swc_VCOP_ARID_DEF.thmd_t_hvbHdOutCoolTemp_C;
  }

  /* End of Switch: '<S425>/Switch2' */

  /* Switch: '<S421>/Switch2' incorporates:
   *  Constant: '<S406>/volc_b_PMS_ThermalReq_ovrdflg'
   */
  if (volc_b_PMS_ThermalReq_ovrdflg) {
    /* Switch: '<S421>/Switch2' incorporates:
     *  Constant: '<S406>/volc_PMS_ThermalReq_ovrdval'
     */
    vold_PMS_ThermalReq = volc_PMS_ThermalReq_ovrdval;
  } else {
    /* Switch: '<S421>/Switch2' */
    vold_PMS_ThermalReq = swc_VCOP_ARID_DEF.Switch_c;
  }

  /* End of Switch: '<S421>/Switch2' */

  /* Switch: '<S418>/Switch2' incorporates:
   *  Constant: '<S403>/volc_flg_PMS_HvCoolgPwrAllwd_ovrdflg'
   */
  if (volc_b_PMS_HvCoolgPwrAllwd_ovrdflg) {
    /* Switch: '<S418>/Switch2' incorporates:
     *  Constant: '<S403>/volc_PMS_HvCoolgPwrAllwd_ovrdval'
     */
    vold_PMS_HvCoolgPwrAllwd = volc_PMS_HvCoolgPwrAllwd_ovrdval;
  } else {
    /* Switch: '<S418>/Switch2' */
    vold_PMS_HvCoolgPwrAllwd = swc_VCOP_ARID_DEF.thmd_pwr_accmHvClPwrAllwd_kW;
  }

  /* End of Switch: '<S418>/Switch2' */

  /* Switch: '<S419>/Switch2' incorporates:
   *  Constant: '<S404>/volc_flg_PMS_HvHeatgPwrAllwd_ovrdflg'
   */
  if (volc_b_PMS_HvHeatgPwrAllwd_ovrdflg) {
    /* Switch: '<S419>/Switch2' incorporates:
     *  Constant: '<S404>/volc_PMS_HvHeatgPwrAllwd_ovrdval'
     */
    vold_PMS_HvHeatgPwrAllwd = volc_PMS_HvHeatgPwrAllwd_ovrdval;
  } else {
    /* Switch: '<S419>/Switch2' */
    vold_PMS_HvHeatgPwrAllwd = swc_VCOP_ARID_DEF.thmd_pwr_ptcHvHtPwrAllwd_kW;
  }

  /* End of Switch: '<S419>/Switch2' */

  /* Switch: '<S428>/Switch2' incorporates:
   *  Constant: '<S413>/volc_flg_VCU_PMS_APPowerActual_EV_ovrdflg'
   */
  if (volc_b_VCU_PMS_APPowerActual_EV_ovrdflg) {
    /* Switch: '<S428>/Switch2' incorporates:
     *  Constant: '<S413>/volc_VCU_PMS_APPowerActual_EV_ovrdval'
     */
    vold_VCU_PMS_APPowerActual_EV = volc_VCU_PMS_APPowerActual_EV_ovrdval;
  } else {
    /* Switch: '<S428>/Switch2' */
    vold_VCU_PMS_APPowerActual_EV = swc_VCOP_ARID_DEF.DataTypeConversion237;
  }

  /* End of Switch: '<S428>/Switch2' */

  /* Switch: '<S420>/Switch2' incorporates:
   *  Constant: '<S405>/volc_flg_PMS_MCUFlowFeedback_EV_ovrdflg'
   */
  if (volc_b_PMS_MCUFlowFeedback_EV_ovrdflg) {
    /* Switch: '<S420>/Switch2' incorporates:
     *  Constant: '<S405>/volc_PMS_MCUFlowFeedback_EV_ovrdval'
     */
    vold_PMS_MCUFlowFeedback_EV = volc_PMS_MCUFlowFeedback_EV_ovrdval;
  } else {
    /* Switch: '<S420>/Switch2' */
    vold_PMS_MCUFlowFeedback_EV = swc_VCOP_ARID_DEF.DataTypeConversion238;
  }

  /* End of Switch: '<S420>/Switch2' */

  /* Switch: '<S422>/Switch2' incorporates:
   *  Constant: '<S407>/volc_b_PMS_ThermalReq_ovrdflg'
   */
  if (volc_b_BMSH_HvBattThermMod_ovrdflg) {
    /* Switch: '<S422>/Switch2' incorporates:
     *  Constant: '<S407>/volc_PMS_ThermalReq_ovrdval'
     */
    vold_BMSH_HvBattThermMod = volc_BMSH_HvBattThermMod_ovrdval;
  } else {
    /* Switch: '<S422>/Switch2' */
    vold_BMSH_HvBattThermMod = swc_VCOP_ARID_DEF.Switch8;
  }

  /* End of Switch: '<S422>/Switch2' */

  /* Switch: '<S417>/Switch2' incorporates:
   *  Constant: '<S402>/volc_b_PMS_ThermalReq_ovrdflg'
   */
  if (volc_b_HBCPFlt_ovrdflg) {
    /* Switch: '<S417>/Switch2' incorporates:
     *  Constant: '<S402>/volc_PMS_ThermalReq_ovrdval'
     */
    vold_HBCP_Flt = volc_HBCPFlt_ovrdval;
  } else {
    /* Switch: '<S417>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_DIAG_in14'
     */
    vold_HBCP_Flt = Rte_IRead_swc_VCOP_Step_vcsb_DIAG_digd_st_hbcpFlt();
  }

  /* End of Switch: '<S417>/Switch2' */

  /* Switch: '<S416>/Switch2' incorporates:
   *  Constant: '<S401>/volc_b_EDCP_Flt_ovrdflg'
   */
  if (volc_b_EDCP_Flt_ovrdflg) {
    /* Switch: '<S416>/Switch2' incorporates:
     *  Constant: '<S401>/volc_EDCP_Flt_ovrdval'
     */
    vold_EDCP_Flt = volc_EDCP_Flt_ovrdval;
  } else {
    /* Switch: '<S416>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_DIAG_in13'
     */
    vold_EDCP_Flt = Rte_IRead_swc_VCOP_Step_vcsb_DIAG_digd_st_edcpFlt();
  }

  /* End of Switch: '<S416>/Switch2' */

  /* Switch: '<S443>/Switch2' incorporates:
   *  Constant: '<S433>/volc_flg_VCU_ATS1Enable_ovrdflg'
   */
  if (volc_b_VCU_ATS1Enable_ovrdflg) {
    /* Switch: '<S443>/Switch2' incorporates:
     *  Constant: '<S433>/volc_VCU_ATS1Enable_ovrdval'
     */
    vold_VCU_ATS1Enable = volc_VCU_ATS1Enable_ovrdval;
  } else {
    /* Switch: '<S443>/Switch2' */
    vold_VCU_ATS1Enable = (uint8)thmd_b_MHGVEna;
  }

  /* End of Switch: '<S443>/Switch2' */

  /* Switch: '<S444>/Switch2' incorporates:
   *  Constant: '<S434>/volc_flg_VCU_ATS1_PWMRequest_ovrdflg'
   */
  if (volc_b_VCU_ATS1_PWMRequest_ovrdflg) {
    /* Switch: '<S444>/Switch2' incorporates:
     *  Constant: '<S434>/volc_VCU_ATS1_PWMRequest_ovrdval'
     */
    vold_VCU_ATS1_PWMRequest = volc_VCU_ATS1_PWMRequest_ovrdval;
  } else {
    /* Switch: '<S444>/Switch2' */
    vold_VCU_ATS1_PWMRequest = thmd_n_fan1TgtSpdOutp_pct;
  }

  /* End of Switch: '<S444>/Switch2' */

  /* Switch: '<S445>/Switch2' incorporates:
   *  Constant: '<S435>/volc_flg_VCU_ATS2Enable_ovrdflg'
   */
  if (volc_b_VCU_ATS2Enable_ovrdflg) {
    /* Switch: '<S445>/Switch2' incorporates:
     *  Constant: '<S435>/volc_VCU_ATS2Enable_ovrdval'
     */
    vold_VCU_ATS2Enable = volc_VCU_ATS2Enable_ovrdval;
  } else {
    /* Switch: '<S445>/Switch2' */
    vold_VCU_ATS2Enable = (uint8)thmd_b_MHGVEna;
  }

  /* End of Switch: '<S445>/Switch2' */

  /* Switch: '<S446>/Switch2' incorporates:
   *  Constant: '<S436>/volc_flg_VCU_ATS2_PWMRequest_ovrdflg'
   */
  if (volc_b_VCU_ATS2_PWMRequest_ovrdflg) {
    /* Switch: '<S446>/Switch2' incorporates:
     *  Constant: '<S436>/volc_VCU_ATS2_PWMRequest_ovrdval'
     */
    vold_VCU_ATS2_PWMRequest = volc_VCU_ATS2_PWMRequest_ovrdval;
  } else {
    /* Switch: '<S446>/Switch2' */
    vold_VCU_ATS2_PWMRequest = 0.0F;
  }

  /* End of Switch: '<S446>/Switch2' */

  /* Switch: '<S447>/Switch2' incorporates:
   *  Constant: '<S437>/volc_flg_VCU_ATS3Enable_ovrdflg'
   */
  if (volc_b_VCU_ATS3Enable_ovrdflg) {
    /* Switch: '<S447>/Switch2' incorporates:
     *  Constant: '<S437>/volc_VCU_ATS3Enable_ovrdval'
     */
    vold_VCU_ATS3Enable = volc_VCU_ATS3Enable_ovrdval;
  } else {
    /* Switch: '<S447>/Switch2' */
    vold_VCU_ATS3Enable = (uint8)thmd_b_MHGVEna;
  }

  /* End of Switch: '<S447>/Switch2' */

  /* Switch: '<S448>/Switch2' incorporates:
   *  Constant: '<S438>/volc_flg_VCU_ATS3_PWMRequest_ovrdflg'
   */
  if (volc_b_VCU_ATS3_PWMRequest_ovrdflg) {
    /* Switch: '<S448>/Switch2' incorporates:
     *  Constant: '<S438>/volc_VCU_ATS3_PWMRequest_ovrdval'
     */
    vold_VCU_ATS3_PWMRequest = volc_VCU_ATS3_PWMRequest_ovrdval;
  } else {
    /* Switch: '<S448>/Switch2' */
    vold_VCU_ATS3_PWMRequest = swc_VCOP_ARID_DEF.SignalConversion_e;
  }

  /* End of Switch: '<S448>/Switch2' */

  /* Switch: '<S449>/Switch2' incorporates:
   *  Constant: '<S439>/volc_flg_VCU_ATS4Enable_ovrdflg'
   */
  if (volc_b_VCU_ATS4Enable_ovrdflg) {
    /* Switch: '<S449>/Switch2' incorporates:
     *  Constant: '<S439>/volc_VCU_ATS4Enable_ovrdval'
     */
    vold_VCU_ATS4Enable = volc_VCU_ATS4Enable_ovrdval;
  } else {
    /* Switch: '<S449>/Switch2' */
    vold_VCU_ATS4Enable = (uint8)thmd_b_MHGVEna;
  }

  /* End of Switch: '<S449>/Switch2' */

  /* Switch: '<S450>/Switch2' incorporates:
   *  Constant: '<S440>/volc_flg_VCU_ATS4_PWMRequest_ovrdflg'
   */
  if (volc_b_VCU_ATS4_PWMRequest_ovrdflg) {
    /* Switch: '<S450>/Switch2' incorporates:
     *  Constant: '<S440>/volc_VCU_ATS4_PWMRequest_ovrdval'
     */
    vold_VCU_ATS4_PWMRequest = volc_VCU_ATS4_PWMRequest_ovrdval;
  } else {
    /* Switch: '<S450>/Switch2' */
    vold_VCU_ATS4_PWMRequest = swc_VCOP_ARID_DEF.SignalConversion1_g;
  }

  /* End of Switch: '<S450>/Switch2' */

  /* Switch: '<S441>/Switch2' incorporates:
   *  Constant: '<S431>/volc_flg_VCU_12VATS1Enable_ovrdflg'
   */
  if (volc_b_VCU_12VATS1Enable_ovrdflg) {
    /* Switch: '<S441>/Switch2' incorporates:
     *  Constant: '<S431>/volc_VCU_12VATS1Enable_ovrdval'
     */
    vold_VCU_12VATS1Enable = volc_VCU_12VATS1Enable_ovrdval;
  } else {
    /* Switch: '<S441>/Switch2' */
    vold_VCU_12VATS1Enable = swc_VCOP_ARID_DEF.TmpBufferAtGround2Outport1;
  }

  /* End of Switch: '<S441>/Switch2' */

  /* Switch: '<S442>/Switch2' incorporates:
   *  Constant: '<S432>/volc_flg_VCU_12VATS1_PWMRequest_ovrdflg'
   */
  if (volc_b_VCU_12VATS1_PWMRequest_ovrdflg) {
    /* Switch: '<S442>/Switch2' incorporates:
     *  Constant: '<S432>/volc_VCU_12VATS1_PWMRequest_ovrdval'
     */
    vold_VCU_12VATS1_PWMRequest = volc_VCU_12VATS1_PWMRequest_ovrdval;
  } else {
    /* Switch: '<S442>/Switch2' */
    vold_VCU_12VATS1_PWMRequest = thmd_n_12vAts1PwmReq_pct;
  }

  /* End of Switch: '<S442>/Switch2' */

  /* Switch: '<S470>/Switch2' incorporates:
   *  Constant: '<S458>/volc_flg_VCU_DriverOperationReminder_ovrdflg'
   */
  if (volc_b_VCU_DriverOperationReminder_ovrdflg) {
    /* Switch: '<S470>/Switch2' incorporates:
     *  Constant: '<S458>/volc_VCU_DriverOperationReminder_ovrdval'
     */
    vold_VCU_DriverOperationReminder = volc_VCU_DriverOperationReminder_ovrdval;
  } else {
    /* Switch: '<S470>/Switch2' */
    vold_VCU_DriverOperationReminder = swc_VCOP_ARID_DEF.DataTypeConversion95;
  }

  /* End of Switch: '<S470>/Switch2' */

  /* Switch: '<S465>/Switch2' incorporates:
   *  Constant: '<S453>/volc_flg_VCU_ACActiveReq_ovrdflg'
   */
  if (volc_b_VCU_ACActiveReq_ovrdflg) {
    /* Switch: '<S465>/Switch2' incorporates:
     *  Constant: '<S453>/volc_VCU_ACActiveReq_ovrdval'
     */
    vold_VCU_ACActiveReq = volc_VCU_ACActiveReq_ovrdval;
  } else {
    /* Switch: '<S465>/Switch2' incorporates:
     *  Constant: '<S159>/Constant18'
     */
    vold_VCU_ACActiveReq = ((uint8)0U);
  }

  /* End of Switch: '<S465>/Switch2' */

  /* Switch: '<S468>/Switch2' incorporates:
   *  Constant: '<S456>/volc_flg_VCU_BrakSwitchSts_ovrdflg'
   */
  if (volc_b_VCU_BrakSwitchSts_ovrdflg) {
    /* Switch: '<S468>/Switch2' incorporates:
     *  Constant: '<S456>/volc_VCU_BrakSwitchSts_ovrdval'
     */
    vold_VCU_BrakSwitchSts = volc_VCU_BrakSwitchSts_ovrdval;
  } else {
    /* Switch: '<S468>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion'
     *  Inport generated from: '<Root>/vcib_VCIP_in51'
     */
    vold_VCU_BrakSwitchSts = (uint8)
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_brpd_b_brkPressedFromSwitch();
  }

  /* End of Switch: '<S468>/Switch2' */

  /* Switch: '<S473>/Switch2' incorporates:
   *  Constant: '<S461>/volc_flg_VCU_VehicleSpd_ovrdflg'
   */
  if (volc_b_VCU_VehicleSpd_ovrdflg) {
    /* Switch: '<S473>/Switch2' incorporates:
     *  Constant: '<S461>/volc_VCU_VehicleSpd_ovrdval'
     */
    vold_VCU_VehicleSpd = volc_VCU_VehicleSpd_ovrdval;
  } else {
    /* Switch: '<S473>/Switch2' */
    vold_VCU_VehicleSpd = vscd_v_vscVehSpdOutp_kph;
  }

  /* End of Switch: '<S473>/Switch2' */

  /* Switch: '<S463>/Switch2' incorporates:
   *  Constant: '<S451>/volc_flg_PMS_Real_PedalPosition_ovrdflg'
   */
  if (volc_b_PMS_Real_PedalPosition_ovrdflg != 0.0F) {
    /* Switch: '<S463>/Switch2' incorporates:
     *  Constant: '<S451>/volc_PMS_Real_PedalPosition_ovrdval'
     */
    vold_PMS_Real_PedalPosition = volc_PMS_Real_PedalPosition_ovrdval;
  } else {
    /* Switch: '<S463>/Switch2' */
    vold_PMS_Real_PedalPosition = swc_VCOP_ARID_DEF.DataTypeConversion206;
  }

  /* End of Switch: '<S463>/Switch2' */

  /* Switch: '<S466>/Switch2' incorporates:
   *  Constant: '<S454>/volc_flg_VCU_AcceleratorPedalPosition_ovrdflg'
   */
  if (volc_b_VCU_AcceleratorPedalPosition_ovrdflg) {
    /* Switch: '<S466>/Switch2' incorporates:
     *  Constant: '<S454>/volc_VCU_AcceleratorPedalPosition_ovrdval'
     */
    vold_VCU_AcceleratorPedalPosition =
      volc_VCU_AcceleratorPedalPosition_ovrdval;
  } else {
    /* Switch: '<S466>/Switch2' incorporates:
     *  MinMax: '<S234>/MinMax4'
     */
    vold_VCU_AcceleratorPedalPosition = fmaxf
      (swc_VCOP_ARID_DEF.DataTypeConversion94,
       swc_VCOP_ARID_DEF.DataTypeConversion206);
  }

  /* End of Switch: '<S466>/Switch2' */

  /* Switch: '<S469>/Switch2' incorporates:
   *  Constant: '<S457>/volc_flg_VCU_BrakePedalPosition_ovrdflg'
   */
  if (volc_b_VCU_BrakePedalPosition_ovrdflg) {
    /* Switch: '<S469>/Switch2' incorporates:
     *  Constant: '<S457>/volc_VCU_BrakePedalPosition_ovrdval'
     */
    vold_VCU_BrakePedalPosition = volc_VCU_BrakePedalPosition_ovrdval;
  } else {
    /* Switch: '<S469>/Switch2' */
    vold_VCU_BrakePedalPosition = swc_VCOP_ARID_DEF.DataTypeConversion172;
  }

  /* End of Switch: '<S469>/Switch2' */

  /* Switch: '<S471>/Switch2' incorporates:
   *  Constant: '<S459>/volc_flg_VCU_HandbrakeSts2_ovrdflg'
   */
  if (volc_b_VCU_HandbrakeSts2_ovrdflg) {
    /* Switch: '<S471>/Switch2' incorporates:
     *  Constant: '<S459>/volc_VCU_HandbrakeSts2_ovrdval'
     */
    vold_VCU_HandbrakeSts2 = volc_VCU_HandbrakeSts2_ovrdval;
  } else {
    /* Switch: '<S471>/Switch2' */
    vold_VCU_HandbrakeSts2 = epbd_st_parkingSts;
  }

  /* End of Switch: '<S471>/Switch2' */

  /* Switch: '<S474>/Switch2' incorporates:
   *  Constant: '<S462>/volc_flg_VCU_VehicleSpd_flag_ovrdflg'
   */
  if (volc_b_VCU_VehicleSpd_flag_ovrdflg) {
    /* Switch: '<S474>/Switch2' incorporates:
     *  Constant: '<S462>/volc_VCU_VehicleSpd_flag_ovrdval'
     */
    vold_VCU_VehicleSpd_flag = volc_VCU_VehicleSpd_flag_ovrdval;
  } else {
    /* Switch: '<S474>/Switch2' incorporates:
     *  Logic: '<S159>/Logical Operator'
     */
    vold_VCU_VehicleSpd_flag = (swc_VCOP_ARID_DEF.DataTypeConversion83 == 0.0);
  }

  /* End of Switch: '<S474>/Switch2' */

  /* Switch: '<S467>/Switch2' incorporates:
   *  Constant: '<S455>/volc_flg_VCU_AcceleratorPedal_flag_ovrdflg'
   */
  if (volc_b_VCU_AcceleratorPedal_flag_ovrdflg) {
    /* Switch: '<S467>/Switch2' incorporates:
     *  Constant: '<S455>/volc_VCU_AcceleratorPedal_flag_ovrdval'
     */
    vold_VCU_AcceleratorPedal_flag = volc_VCU_AcceleratorPedal_flag_ovrdval;
  } else {
    /* Switch: '<S467>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_TCOO_in3'
     *  Logic: '<S159>/Logical Operator1'
     */
    vold_VCU_AcceleratorPedal_flag =
      !Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_b_accPedlPosVirtVld();
  }

  /* End of Switch: '<S467>/Switch2' */

  /* Switch: '<S472>/Switch2' incorporates:
   *  Constant: '<S460>/volc_flg_VCU_StsBrkSwitch1Invalid_ovrdflg'
   */
  if (volc_b_VCU_StsBrkSwitch1Invalid_ovrdflg) {
    /* Switch: '<S472>/Switch2' incorporates:
     *  Constant: '<S460>/volc_VCU_StsBrkSwitch1Invalid_ovrdval'
     */
    vold_VCU_StsBrkSwitch1Invalid = volc_VCU_StsBrkSwitch1Invalid_ovrdval;
  } else {
    /* Switch: '<S472>/Switch2' */
    vold_VCU_StsBrkSwitch1Invalid = swc_VCOP_ARID_DEF.DataTypeConversion519;
  }

  /* End of Switch: '<S472>/Switch2' */

  /* Switch: '<S464>/Switch2' incorporates:
   *  Constant: '<S452>/volc_flg_PMS_Real_PedalPositionInvalid_ovrdflg'
   */
  if (volc_b_PMS_Real_PedalPositionInvalid_ovrdflg) {
    /* Switch: '<S464>/Switch2' incorporates:
     *  Constant: '<S452>/volc_PMS_Real_PedalPositionInvalid_ovrdval'
     */
    vold_PMS_Real_PedalPositionInvalid =
      volc_PMS_Real_PedalPositionInvalid_ovrdval;
  } else {
    /* Switch: '<S464>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in54'
     *  Logic: '<S159>/Logical Operator3'
     */
    vold_PMS_Real_PedalPositionInvalid =
      !Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_b_accPedlPosVld();
  }

  /* End of Switch: '<S464>/Switch2' */

  /* Switch: '<S483>/Switch2' incorporates:
   *  Constant: '<S477>/volc_b_VCU_CruiseControlSts_ovrdflg'
   */
  if (volc_b_VCU_CruiseControlSts_ovrdflg) {
    /* Switch: '<S483>/Switch2' incorporates:
     *  Constant: '<S477>/volc_VCU_CruiseControlSts_ovrdval'
     */
    vold_VCU_CruiseControlSts = volc_VCU_CruiseControlSts_ovrdval;
  } else {
    /* DataTypeConversion: '<S159>/Data Type Conversion68' */
    tmp = fmod(trunc(swc_VCOP_ARID_DEF.DataTypeConversion134), 256.0);

    /* Switch: '<S483>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion68'
     */
    vold_VCU_CruiseControlSts = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)
      (uint8)-tmp : (sint32)(uint8)tmp);
  }

  /* End of Switch: '<S483>/Switch2' */

  /* Switch: '<S481>/Switch2' incorporates:
   *  Constant: '<S475>/volc_flg_VCU_ControlSetSpeed_ovrdflg'
   */
  if (volc_b_VCU_ControlSetSpeed_ovrdflg) {
    /* Switch: '<S481>/Switch2' incorporates:
     *  Constant: '<S475>/volc_VCU_ControlSetSpeed_ovrdval'
     */
    vold_VCU_ControlSetSpeed = volc_VCU_ControlSetSpeed_ovrdval;
  } else {
    /* Switch: '<S481>/Switch2' */
    vold_VCU_ControlSetSpeed = swc_VCOP_ARID_DEF.DataTypeConversion135;
  }

  /* End of Switch: '<S481>/Switch2' */

  /* Switch: '<S482>/Switch2' incorporates:
   *  Constant: '<S476>/volc_flg_VCU_ControlSetSpeed_Mode_ovrdflg'
   */
  if (volc_b_VCU_ControlSetSpeed_Mode_ovrdflg) {
    /* Switch: '<S482>/Switch2' incorporates:
     *  Constant: '<S476>/volc_VCU_ControlSetSpeed_Mode_ovrdval'
     */
    vold_VCU_ControlSetSpeed_Mode = volc_VCU_ControlSetSpeed_Mode_ovrdval;
  } else {
    /* DataTypeConversion: '<S159>/Data Type Conversion67' */
    tmp = fmod(trunc(swc_VCOP_ARID_DEF.DataTypeConversion129), 256.0);

    /* Switch: '<S482>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion67'
     */
    vold_VCU_ControlSetSpeed_Mode = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)
      (uint8)-tmp : (sint32)(uint8)tmp);
  }

  /* End of Switch: '<S482>/Switch2' */

  /* Switch: '<S484>/Switch2' incorporates:
   *  Constant: '<S478>/volc_flg_VCU_CruiseSwSts_ovrdflg'
   */
  if (volc_b_VCU_CruiseSwSts_ovrdflg) {
    /* Switch: '<S484>/Switch2' incorporates:
     *  Constant: '<S478>/volc_VCU_CruiseSwSts_ovrdval'
     */
    vold_VCU_CruiseSwSts = volc_VCU_CruiseSwSts_ovrdval;
  } else {
    /* DataTypeConversion: '<S159>/Data Type Conversion70' */
    tmp = fmod(trunc(swc_VCOP_ARID_DEF.DataTypeConversion131), 256.0);

    /* Switch: '<S484>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion70'
     */
    vold_VCU_CruiseSwSts = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-
      tmp : (sint32)(uint8)tmp);
  }

  /* End of Switch: '<S484>/Switch2' */

  /* Switch: '<S486>/Switch2' incorporates:
   *  Constant: '<S480>/volc_flg_VCU_QuitControlSpeed_ovrdflg'
   */
  if (volc_b_VCU_QuitControlSpeed_ovrdflg) {
    /* Switch: '<S486>/Switch2' incorporates:
     *  Constant: '<S480>/volc_VCU_QuitControlSpeed_ovrdval'
     */
    vold_VCU_QuitControlSpeed = volc_VCU_QuitControlSpeed_ovrdval;
  } else {
    /* Switch: '<S486>/Switch2' */
    vold_VCU_QuitControlSpeed = swc_VCOP_ARID_DEF.DataTypeConversion117;
  }

  /* End of Switch: '<S486>/Switch2' */

  /* Switch: '<S485>/Switch2' incorporates:
   *  Constant: '<S479>/volc_b_VCU_CruiseSwerrorSts_ovrdflg'
   */
  if (volc_b_VCU_CruiseSwerrorSts_ovrdflg) {
    /* Switch: '<S485>/Switch2' incorporates:
     *  Constant: '<S479>/volc_VCU_CruiseSwerrorSts_ovrdval'
     */
    vold_VCU_CruiseSwerrorSts = volc_VCU_CruiseSwerrorSts_ovrdval;
  } else {
    /* DataTypeConversion: '<S159>/Data Type Conversion69' */
    tmp = fmod(trunc(swc_VCOP_ARID_DEF.DataTypeConversion116), 256.0);

    /* Switch: '<S485>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion69'
     */
    vold_VCU_CruiseSwerrorSts = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)
      (uint8)-tmp : (sint32)(uint8)tmp);
  }

  /* End of Switch: '<S485>/Switch2' */

  /* Switch: '<S515>/Switch2' incorporates:
   *  Constant: '<S493>/volc_flg_VCU_MCU1EnableReq_ovrdflg'
   *  Constant: '<S505>/Constant32'
   *  Switch: '<S505>/Switch2'
   */
  if (volc_b_VCU_MCU1EnableReq_ovrdflg) {
    /* Switch: '<S515>/Switch2' incorporates:
     *  Constant: '<S493>/volc_VCU_MCU1EnableReq_ovrdval'
     */
    vold_VCU_MCU1EnableReq = volc_VCU_MCU1EnableReq_ovrdval;
  } else if (false) {
    /* Switch: '<S505>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion12'
     *  Switch: '<S515>/Switch2'
     */
    vold_VCU_MCU1EnableReq = (uint8)eadd_b_ead2Ena;
  } else {
    /* Switch: '<S515>/Switch2' incorporates:
     *  Constant: '<S505>/Constant9'
     *  Switch: '<S505>/Switch2'
     */
    vold_VCU_MCU1EnableReq = ((uint8)0U);
  }

  /* End of Switch: '<S515>/Switch2' */

  /* Switch: '<S516>/Switch2' incorporates:
   *  Constant: '<S494>/volc_flg_VCU_MCUEnableReq_ovrdflg'
   */
  if (volc_b_VCU_MCUEnableReq_ovrdflg) {
    /* Switch: '<S516>/Switch2' incorporates:
     *  Constant: '<S494>/volc_VCU_MCUEnableReq_ovrdval'
     */
    vold_VCU_MCUEnableReq = volc_VCU_MCUEnableReq_ovrdval;
  } else {
    /* Switch: '<S516>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion12'
     */
    vold_VCU_MCUEnableReq = (uint8)eadd_b_ead2Ena;
  }

  /* End of Switch: '<S516>/Switch2' */

  /* Switch: '<S511>/Switch2' incorporates:
   *  Constant: '<S489>/volc_b_VCU_EM1CtrlMode_ovrdflg'
   */
  if (volc_b_VCU_EM1CtrlMode_ovrdflg) {
    /* Switch: '<S511>/Switch2' incorporates:
     *  Constant: '<S489>/volc_VCU_EM1CtrlMode_ovrdval'
     */
    vold_VCU_EM1CtrlMode = volc_VCU_EM1CtrlMode_ovrdval;
  } else {
    /* Switch: '<S511>/Switch2' */
    vold_VCU_EM1CtrlMode = eadd_st_inv2EmCtrlMod;
  }

  /* End of Switch: '<S511>/Switch2' */

  /* Switch: '<S513>/Switch2' incorporates:
   *  Constant: '<S491>/volc_flg_VCU_EMCtrlMode_ovrdflg'
   */
  if (volc_b_VCU_EMCtrlMode_ovrdflg) {
    /* Switch: '<S513>/Switch2' incorporates:
     *  Constant: '<S491>/volc_VCU_EMCtrlMode_ovrdval'
     */
    vold_VCU_EMCtrlMode = volc_VCU_EMCtrlMode_ovrdval;
  } else {
    /* Switch: '<S513>/Switch2' */
    vold_VCU_EMCtrlMode = eadd_st_inv2EmCtrlMod;
  }

  /* End of Switch: '<S513>/Switch2' */

  /* Switch: '<S512>/Switch2' incorporates:
   *  Constant: '<S490>/volc_b_VCU_EM1WorkMode_ovrdflg'
   *  Constant: '<S506>/Constant32'
   *  Switch: '<S506>/Switch2'
   */
  if (volc_b_VCU_EM1WorkMode_ovrdflg) {
    /* Switch: '<S512>/Switch2' incorporates:
     *  Constant: '<S490>/volc_VCU_EM1WorkMode_ovrdval'
     */
    vold_VCU_EM1WorkMode = volc_VCU_EM1WorkMode_ovrdval;
  } else if (false) {
    /* Switch: '<S506>/Switch2' incorporates:
     *  Switch: '<S512>/Switch2'
     */
    vold_VCU_EM1WorkMode = eadd_st_inv2EmWMod;
  } else {
    /* Switch: '<S512>/Switch2' incorporates:
     *  Constant: '<S506>/Constant9'
     *  Switch: '<S506>/Switch2'
     */
    vold_VCU_EM1WorkMode = ((uint8)0U);
  }

  /* End of Switch: '<S512>/Switch2' */

  /* Switch: '<S514>/Switch2' incorporates:
   *  Constant: '<S492>/volc_flg_VCU_EMWorkMode_ovrdflg'
   */
  if (volc_b_VCU_EMWorkMode_ovrdflg) {
    /* Switch: '<S514>/Switch2' incorporates:
     *  Constant: '<S492>/volc_VCU_EMWorkMode_ovrdval'
     */
    vold_VCU_EMWorkMode = volc_VCU_EMWorkMode_ovrdval;
  } else {
    /* Switch: '<S514>/Switch2' */
    vold_VCU_EMWorkMode = eadd_st_inv2EmWMod;
  }

  /* End of Switch: '<S514>/Switch2' */

  /* Switch: '<S525>/Switch2' incorporates:
   *  Constant: '<S503>/volc_VCU_ReqSpdOrLmt_ovrdval'
   */
  vold_VCU_ReqSpdOrLmt = volc_VCU_ReqSpdOrLmt_ovrdval;

  /* Switch: '<S526>/Switch2' incorporates:
   *  Constant: '<S504>/volc_flg_VCU_ReqTrqOrLmt_ovrdflg'
   */
  if (volc_b_VCU_ReqTrqOrLmt_ovrdflg) {
    /* Switch: '<S526>/Switch2' incorporates:
     *  Constant: '<S504>/volc_VCU_ReqTrqOrLmt_ovrdval'
     */
    vold_VCU_ReqTrqOrLmt = volc_VCU_ReqTrqOrLmt_ovrdval;
  } else {
    /* Switch: '<S526>/Switch2' */
    vold_VCU_ReqTrqOrLmt = eadd_tq_mot2TgtTqReqOutpAbs_Nm;
  }

  /* End of Switch: '<S526>/Switch2' */

  /* Switch: '<S521>/Switch2' incorporates:
   *  Constant: '<S499>/volc_flg_VCU_MaxEMPwrLmt_ovrdflg'
   */
  if (volc_b_VCU_MaxEMPwrLmt_ovrdflg) {
    /* Switch: '<S521>/Switch2' incorporates:
     *  Constant: '<S499>/volc_VCU_MaxEMPwrLmt_ovrdval'
     */
    vold_VCU_MaxEMPwrLmt = volc_VCU_MaxEMPwrLmt_ovrdval;
  } else {
    /* Switch: '<S521>/Switch2' */
    vold_VCU_MaxEMPwrLmt = ptld_pwr_ead2PwrMaxOutp_kW;
  }

  /* End of Switch: '<S521>/Switch2' */

  /* Switch: '<S522>/Switch2' incorporates:
   *  Constant: '<S500>/volc_flg_VCU_MinEMPwrLmt_ovrdflg'
   */
  if (volc_b_VCU_MinEMPwrLmt_ovrdflg) {
    /* Switch: '<S522>/Switch2' incorporates:
     *  Constant: '<S500>/volc_VCU_MinEMPwrLmt_ovrdval'
     */
    vold_VCU_MinEMPwrLmt = volc_VCU_MinEMPwrLmt_ovrdval;
  } else {
    /* Switch: '<S522>/Switch2' */
    vold_VCU_MinEMPwrLmt = ptld_pwr_ead2PwrMinOutp_kW;
  }

  /* End of Switch: '<S522>/Switch2' */

  /* Switch: '<S510>/Switch2' incorporates:
   *  Constant: '<S488>/volc_b_VCU_DriveReqTrqPercent_ovrdflg'
   */
  if (volc_b_VCU_DriveReqTrqPercent_ovrdflg) {
    /* Switch: '<S510>/Switch2' incorporates:
     *  Constant: '<S488>/volc_VCU_DriveReqTrqPercent_ovrdval'
     */
    vold_VCU_DriveReqTrqPercent = volc_VCU_DriveReqTrqPercent_ovrdval;
  } else {
    /* Switch: '<S510>/Switch2' incorporates:
     *  Constant: '<S236>/Constant11'
     *  Constant: '<S236>/Constant32'
     *  Constant: '<S508>/Constant1'
     *  Constant: '<S508>/Constant15'
     *  MinMax: '<S236>/MinMax'
     *  MinMax: '<S508>/MinMax'
     *  Product: '<S236>/Product2'
     *  Product: '<S508>/Product'
     */
    vold_VCU_DriveReqTrqPercent = swc_VCOP_ARID_DEF.DataTypeConversion71 / fmaxf
      (swc_VCOP_ARID_DEF.DataTypeConversion62, 0.01F) * 100.0F / fmaxf
      (swcvcop_vilc_tq_vscESCMotTqRef_Nm, 1.0F);
  }

  /* End of Switch: '<S510>/Switch2' */

  /* Switch: '<S517>/Switch2' incorporates:
   *  Constant: '<S495>/volc_b_VCU_MCUMaxTrq_ovrdflg'
   */
  if (volc_b_VCU_MCUMaxTrq_ovrdflg) {
    /* Switch: '<S517>/Switch2' incorporates:
     *  Constant: '<S495>/volc_VCU_MCUMaxTrq_ovrdval'
     */
    vold_VCU_MCUMaxTrq = volc_VCU_MCUMaxTrq_ovrdval;
  } else {
    /* Switch: '<S517>/Switch2' incorporates:
     *  Constant: '<S236>/Constant32'
     */
    vold_VCU_MCUMaxTrq = swcvcop_vilc_tq_vscESCMotTqRef_Nm;
  }

  /* End of Switch: '<S517>/Switch2' */

  /* Switch: '<S520>/Switch2' incorporates:
   *  Constant: '<S498>/volc_b_VCU_MCU_MotorActTrqPercent_ovrdflg'
   */
  if (volc_b_VCU_MCU_MotorActTrqPercent_ovrdflg) {
    /* Switch: '<S520>/Switch2' incorporates:
     *  Constant: '<S498>/volc_VCU_MCU_MotorActTrqPercent_ovrdval'
     */
    vold_VCU_MCU_MotorActTrqPercent = volc_VCU_MCU_MotorActTrqPercent_ovrdval;
  } else {
    /* Switch: '<S520>/Switch2' incorporates:
     *  Constant: '<S236>/Constant32'
     *  Constant: '<S507>/Constant1'
     *  Constant: '<S507>/Constant15'
     *  MinMax: '<S507>/MinMax'
     *  Product: '<S507>/Product'
     */
    vold_VCU_MCU_MotorActTrqPercent = swc_VCOP_ARID_DEF.DataTypeConversion103 *
      100.0F / fmaxf(swcvcop_vilc_tq_vscESCMotTqRef_Nm, 1.0F);
  }

  /* End of Switch: '<S520>/Switch2' */

  /* Switch: '<S524>/Switch2' incorporates:
   *  Constant: '<S502>/volc_flg_VCU_MotorTorque_ovrdflg'
   */
  if (volc_b_VCU_MotorTorque_ovrdflg) {
    /* Switch: '<S524>/Switch2' incorporates:
     *  Constant: '<S502>/volc_VCU_MotorTorque_ovrdval'
     */
    vold_VCU_MotorTorque = volc_VCU_MotorTorque_ovrdval;
  } else {
    /* Switch: '<S524>/Switch2' */
    vold_VCU_MotorTorque = swc_VCOP_ARID_DEF.DataTypeConversion163;
  }

  /* End of Switch: '<S524>/Switch2' */

  /* Switch: '<S523>/Switch2' incorporates:
   *  Constant: '<S501>/volc_flg_VCU_MotorSpeed_ovrdflg'
   */
  if (volc_b_VCU_MotorSpeed_ovrdflg) {
    /* Switch: '<S523>/Switch2' incorporates:
     *  Constant: '<S501>/volc_VCU_MotorSpeed_ovrdval'
     */
    vold_VCU_MotorSpeed = volc_VCU_MotorSpeed_ovrdval;
  } else {
    /* Switch: '<S523>/Switch2' */
    vold_VCU_MotorSpeed = swc_VCOP_ARID_DEF.DataTypeConversion162;
  }

  /* End of Switch: '<S523>/Switch2' */

  /* Switch: '<S518>/Switch2' incorporates:
   *  Constant: '<S496>/volc_flg_VCU_MCUSpdRampRate_ovrdflg'
   */
  if (volc_b_VCU_MCUSpdRampRate_ovrdflg) {
    /* Switch: '<S518>/Switch2' incorporates:
     *  Constant: '<S496>/volc_VCU_MCUSpdRampRate_ovrdval'
     */
    vold_VCU_MCUSpdRampRate = volc_VCU_MCUSpdRampRate_ovrdval;
  } else {
    /* Switch: '<S518>/Switch2' incorporates:
     *  Constant: '<S236>/volc_VCU_MCUSpdRampRate_dftval'
     */
    vold_VCU_MCUSpdRampRate = volc_VCU_MCUSpdRampRate_dftval;
  }

  /* End of Switch: '<S518>/Switch2' */

  /* Switch: '<S519>/Switch2' incorporates:
   *  Constant: '<S497>/volc_flg_VCU_MCUTqRampRate_ovrdflg'
   */
  if (volc_b_VCU_MCUTqRampRate_ovrdflg) {
    /* Switch: '<S519>/Switch2' incorporates:
     *  Constant: '<S497>/volc_VCU_MCUTqRampRate_ovrdval'
     */
    vold_VCU_MCUTqRampRate = volc_VCU_MCUTqRampRate_ovrdval;
  } else {
    /* Switch: '<S519>/Switch2' incorporates:
     *  Constant: '<S236>/volc_VCU_MCUTqRampRate_dftval'
     */
    vold_VCU_MCUTqRampRate = volc_VCU_MCUTqRampRate_dftval;
  }

  /* End of Switch: '<S519>/Switch2' */

  /* Switch: '<S509>/Switch2' incorporates:
   *  Constant: '<S487>/volc_flg_PMS_IsgActvDampgModReq_ovrdflg'
   */
  if (volc_b_PMS_IsgActvDampgModReq_ovrdflg) {
    /* Switch: '<S509>/Switch2' incorporates:
     *  Constant: '<S487>/volc_PMS_IsgActvDampgModReq_ovrdval'
     */
    vold_PMS_IsgActvDampgModReq = volc_PMS_IsgActvDampgModReq_ovrdval;
  } else {
    /* Switch: '<S509>/Switch2' */
    vold_PMS_IsgActvDampgModReq = swc_VCOP_ARID_DEF.DataTypeConversion236;
  }

  /* End of Switch: '<S509>/Switch2' */

  /* Switch: '<S532>/Switch2' incorporates:
   *  Constant: '<S528>/volc_flg_VCU_DTE_ovrdflg'
   */
  if (volc_b_VCU_DTE_ovrdflg) {
    /* Switch: '<S532>/Switch2' incorporates:
     *  Constant: '<S528>/volc_VCU_DTE_ovrdval'
     */
    vold_VCU_DTE = volc_VCU_DTE_ovrdval;
  } else {
    /* Switch: '<S532>/Switch2' */
    vold_VCU_DTE = swc_VCOP_ARID_DEF.DataTypeConversion96;
  }

  /* End of Switch: '<S532>/Switch2' */

  /* Switch: '<S531>/Switch2' incorporates:
   *  Constant: '<S527>/volc_flg_VCU_AEC_ovrdflg'
   */
  if (volc_b_VCU_AEC_ovrdflg) {
    /* Switch: '<S531>/Switch2' incorporates:
     *  Constant: '<S527>/volc_VCU_AEC_ovrdval'
     */
    vold_VCU_AEC = volc_VCU_AEC_ovrdval;
  } else {
    /* Switch: '<S531>/Switch2' */
    vold_VCU_AEC = swc_VCOP_ARID_DEF.DataTypeConversion98;
  }

  /* End of Switch: '<S531>/Switch2' */

  /* Switch: '<S533>/Switch2' incorporates:
   *  Constant: '<S529>/volc_flg_VCU_ErrCode_ovrdflg'
   */
  if (volc_b_VCU_ErrCode_ovrdflg) {
    /* Switch: '<S533>/Switch2' incorporates:
     *  Constant: '<S529>/volc_VCU_ErrCode_ovrdval'
     */
    vold_VCU_ErrCode = volc_VCU_ErrCode_ovrdval;
  } else {
    /* Switch: '<S533>/Switch2' */
    vold_VCU_ErrCode = swc_VCOP_ARID_DEF.DataTypeConversion100;
  }

  /* End of Switch: '<S533>/Switch2' */

  /* Switch: '<S534>/Switch2' incorporates:
   *  Constant: '<S530>/volc_b_VCU_PTResiPwr_ovrdflg'
   */
  if (volc_b_VCU_PTResiPwr_ovrdflg) {
    /* Switch: '<S534>/Switch2' incorporates:
     *  Constant: '<S530>/volc_VCU_PTResiPwr_ovrdval'
     */
    vold_VCU_PTResiPwr = volc_VCU_PTResiPwr_ovrdval;
  } else {
    /* Switch: '<S534>/Switch2' */
    vold_VCU_PTResiPwr = swc_VCOP_ARID_DEF.DataTypeConversion102;
  }

  /* End of Switch: '<S534>/Switch2' */

  /* Switch: '<S550>/Switch2' incorporates:
   *  Constant: '<S537>/volc_flg_VCU_AllowChg_ovrdflg'
   */
  if (volc_b_VCU_AllowChg_ovrdflg) {
    /* Switch: '<S550>/Switch2' incorporates:
     *  Constant: '<S537>/volc_VCU_AllowChg_ovrdval'
     */
    vold_VCU_AllowChg = volc_VCU_AllowChg_ovrdval;
  } else {
    /* Switch: '<S550>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion8'
     *  Inport generated from: '<Root>/vcsb_HVSM_in14'
     */
    vold_VCU_AllowChg = (uint8)Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_allowChg
      ();
  }

  /* End of Switch: '<S550>/Switch2' */

  /* Switch: '<S551>/Switch2' incorporates:
   *  Constant: '<S538>/volc_flg_VCU_BMSHVOnOffReq_ovrdflg'
   */
  if (volc_b_VCU_BMSHVOnOffReq_ovrdflg) {
    /* Switch: '<S551>/Switch2' incorporates:
     *  Constant: '<S538>/volc_VCU_BMSHVOnOffReq_ovrdval'
     */
    vold_VCU_BMSHVOnOffReq = volc_VCU_BMSHVOnOffReq_ovrdval;
  } else {
    /* Switch: '<S551>/Switch2' */
    vold_VCU_BMSHVOnOffReq = swc_VCOP_ARID_DEF.DataTypeConversion90;
  }

  /* End of Switch: '<S551>/Switch2' */

  /* Switch: '<S553>/Switch2' incorporates:
   *  Constant: '<S540>/volc_flg_VCU_DCDCPwrLmt_ovrdflg'
   */
  if (volc_b_VCU_DCDCPwrLmt_ovrdflg) {
    /* Switch: '<S553>/Switch2' incorporates:
     *  Constant: '<S540>/volc_VCU_DCDCPwrLmt_ovrdval'
     */
    vold_VCU_DCDCPwrLmt = volc_VCU_DCDCPwrLmt_ovrdval;
  } else {
    /* Switch: '<S553>/Switch2' */
    vold_VCU_DCDCPwrLmt = dccd_pwr_outPwrLmt_KW;
  }

  /* End of Switch: '<S553>/Switch2' */

  /* Switch: '<S557>/Switch2' incorporates:
   *  Constant: '<S544>/volc_flg_VCU_SDCACOutFreq_ovrdflg'
   */
  if (volc_b_VCU_SDCACOutFreq_ovrdflg) {
    /* Switch: '<S557>/Switch2' incorporates:
     *  Constant: '<S544>/volc_VCU_SDCACOutFreq_ovrdval'
     */
    vold_VCU_SDCACOutFreq = volc_VCU_SDCACOutFreq_ovrdval;
  } else {
    /* Switch: '<S557>/Switch2' */
    vold_VCU_SDCACOutFreq = swc_VCOP_ARID_DEF.DataTypeConversion86;
  }

  /* End of Switch: '<S557>/Switch2' */

  /* Switch: '<S549>/Switch2' incorporates:
   *  Constant: '<S536>/volc_flg_VCU_12VDCDCEnableOut_ovrdflg'
   */
  if (volc_b_VCU_12VDCDCEnableOut_ovrdflg) {
    /* Switch: '<S549>/Switch2' incorporates:
     *  Constant: '<S536>/volc_VCU_12VDCDCEnableOut_ovrdval'
     */
    vold_VCU_12VDCDCEnableOut = volc_VCU_12VDCDCEnableOut_ovrdval;
  } else {
    /* Switch: '<S549>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion6'
     */
    vold_VCU_12VDCDCEnableOut = (uint8)dccd_b_dcdcEna;
  }

  /* End of Switch: '<S549>/Switch2' */

  /* Switch: '<S548>/Switch2' incorporates:
   *  Constant: '<S535>/volc_flg_VCU_12VDCDCCutOffLV_ovrdflg'
   */
  if (volc_b_VCU_12VDCDCCutOffLV_ovrdflg) {
    /* Switch: '<S548>/Switch2' incorporates:
     *  Constant: '<S535>/volc_VCU_12VDCDCCutOffLV_ovrdval'
     */
    vold_VCU_12VDCDCCutOffLV = volc_VCU_12VDCDCCutOffLV_ovrdval;
  } else {
    /* DataTypeConversion: '<S159>/Data Type Conversion4' */
    tmp = fmod(trunc(swc_VCOP_ARID_DEF.DataTypeConversion4), 256.0);

    /* Switch: '<S548>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion4'
     */
    vold_VCU_12VDCDCCutOffLV = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)
      -tmp : (sint32)(uint8)tmp);
  }

  /* End of Switch: '<S548>/Switch2' */

  /* Switch: '<S559>/Switch2' incorporates:
   *  Constant: '<S546>/volc_flg_VCU_SelfCheckSts_ovrdflg'
   *  Switch: '<S238>/Switch6'
   */
  if (volc_b_VCU_SelfCheckSts_ovrdflg) {
    /* Switch: '<S559>/Switch2' incorporates:
     *  Constant: '<S546>/volc_VCU_SelfCheckSts_ovrdval'
     */
    vold_VCU_SelfCheckSts = volc_VCU_SelfCheckSts_ovrdval;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion18 != 0.0) {
    /* Switch: '<S238>/Switch6' incorporates:
     *  Constant: '<S238>/Constant5'
     *  Switch: '<S559>/Switch2'
     */
    vold_VCU_SelfCheckSts = ((uint8)2U);
  } else {
    /* Switch: '<S559>/Switch2' incorporates:
     *  Constant: '<S238>/Constant1'
     *  Switch: '<S238>/Switch6'
     */
    vold_VCU_SelfCheckSts = ((uint8)1U);
  }

  /* End of Switch: '<S559>/Switch2' */

  /* Switch: '<S555>/Switch2' incorporates:
   *  Constant: '<S542>/volc_b_VCU_IntelLockLoopSts_ovrdflg'
   */
  if (volc_b_VCU_IntelLockLoopSts_ovrdflg) {
    /* Switch: '<S555>/Switch2' incorporates:
     *  Constant: '<S542>/volc_VCU_IntelLockLoopSts_ovrdval'
     */
    vold_VCU_IntelLockLoopSts = volc_VCU_IntelLockLoopSts_ovrdval;
  } else {
    /* Switch: '<S555>/Switch2' incorporates:
     *  Constant: '<S238>/volc_VCU_IntelLockLoopSts_dftval'
     */
    vold_VCU_IntelLockLoopSts = volc_VCU_IntelLockLoopSts_dftval;
  }

  /* End of Switch: '<S555>/Switch2' */

  /* Switch: '<S558>/Switch2' incorporates:
   *  Constant: '<S545>/volc_b_VCU_SDCACStopFault_ovrdflg'
   */
  if (volc_b_VCU_SDCACStopFault_ovrdflg) {
    /* Switch: '<S558>/Switch2' incorporates:
     *  Constant: '<S545>/volc_b_VCU_SDCACStopFault_ovrdval'
     */
    vold_VCU_SDCACStopFault = volc_b_VCU_SDCACStopFault_ovrdval;
  } else {
    /* Switch: '<S558>/Switch2' */
    vold_VCU_SDCACStopFault = swc_VCOP_ARID_DEF.DataTypeConversion228;
  }

  /* End of Switch: '<S558>/Switch2' */

  /* Switch: '<S554>/Switch2' incorporates:
   *  Constant: '<S541>/volc_b_VCU_HazardReq_ovrdflg'
   */
  if (volc_b_VCU_HazardReq_ovrdflg) {
    /* Switch: '<S554>/Switch2' incorporates:
     *  Constant: '<S541>/volc_b_VCU_HazardReq_ovrdval'
     */
    vold_VCU_HazardReq = volc_b_VCU_HazardReq_ovrdval;
  } else {
    /* Switch: '<S554>/Switch2' */
    vold_VCU_HazardReq = swc_VCOP_ARID_DEF.DataTypeConversion227;
  }

  /* End of Switch: '<S554>/Switch2' */

  /* Switch: '<S560>/Switch2' incorporates:
   *  Constant: '<S547>/volc_b_VCU_bmsModeStsReq_ovrdflg'
   */
  if (volc_b_VCU_bmsModeStsReq_ovrdflg) {
    /* Switch: '<S560>/Switch2' incorporates:
     *  Constant: '<S547>/volc_st_VCU_bmsModeStsReq_ovrdval'
     */
    vold_VCU_bmsModeStsReq = volc_st_VCU_bmsModeStsReq_ovrdval;
  } else {
    /* Switch: '<S560>/Switch2' */
    vold_VCU_bmsModeStsReq = swc_VCOP_ARID_DEF.bmsd_e_modeTgt;
  }

  /* End of Switch: '<S560>/Switch2' */

  /* Switch: '<S552>/Switch2' incorporates:
   *  Constant: '<S539>/volc_b_VCU_BMSH_DCChgRelayVolt_ovrdflg'
   */
  if (volc_b_VCU_BMSH_DCChgRelayVolt_ovrdflg) {
    /* Switch: '<S552>/Switch2' incorporates:
     *  Constant: '<S539>/volc_VCU_BMSH_DCChgRelayVolt_ovrdval'
     */
    vold_VCU_BMSH_DCChgRelayVolt = volc_VCU_BMSH_DCChgRelayVolt_ovrdval;
  } else {
    /* Switch: '<S552>/Switch2' */
    vold_VCU_BMSH_DCChgRelayVolt = swc_VCOP_ARID_DEF.DataTypeConversion93;
  }

  /* End of Switch: '<S552>/Switch2' */

  /* Switch: '<S563>/Switch2' incorporates:
   *  Constant: '<S561>/volc_b_VCU_BPTCCtrlCmd_ovrdflg'
   *  Switch: '<S562>/Switch5'
   */
  if (volc_b_VCU_BPTCCtrlCmd_ovrdflg) {
    /* Switch: '<S563>/Switch2' incorporates:
     *  Constant: '<S561>/volc_VCU_BPTCCtrlCmd_ovrdval'
     */
    vold_VCU_BPTCCtrlCmd = volc_VCU_BPTCCtrlCmd_ovrdval;
  } else if (swc_VCOP_ARID_DEF.SignalConversion != 0.0) {
    /* Switch: '<S562>/Switch5' incorporates:
     *  Constant: '<S562>/Constant6'
     *  Switch: '<S563>/Switch2'
     */
    vold_VCU_BPTCCtrlCmd = ((uint8)1U);
  } else {
    /* Switch: '<S563>/Switch2' incorporates:
     *  Constant: '<S562>/Constant1'
     *  Switch: '<S562>/Switch5'
     */
    vold_VCU_BPTCCtrlCmd = ((uint8)2U);
  }

  /* End of Switch: '<S563>/Switch2' */

  /* Switch: '<S566>/Switch2' incorporates:
   *  Constant: '<S566>/volc_b_VCU_ACC2PosVol_ovrdflg'
   */
  if (volc_b_VCU_AppSts_ovrdflg) {
    /* Switch: '<S566>/Switch2' incorporates:
     *  Constant: '<S566>/volc_VCU_ACC2PosVol_ovrdval'
     */
    vold_VCU_AppSts = volc_VCU_AppSts_ovrdval;
  } else {
    /* Switch: '<S566>/Switch2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion7'
     *  DataTypeConversion: '<S159>/Data Type Conversion3'
     */
    vold_VCU_AppSts = swc_VCOP_ARID_DEF.DataTypeConversion7;
  }

  /* End of Switch: '<S566>/Switch2' */

  /* Switch: '<S571>/Switch2' incorporates:
   *  Constant: '<S571>/volc_b_VCU_ACC2PosVol_ovrdflg'
   */
  if (volc_b_VCU_HVPRASts_ovrdflg) {
    /* Switch: '<S571>/Switch2' incorporates:
     *  Constant: '<S571>/volc_VCU_ACC2PosVol_ovrdval'
     */
    vold_VCU_HVPRASts = volc_VCU_HVPRASts_ovrdval;
  } else {
    /* Switch: '<S571>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion1'
     *  DataTypeConversion: '<S571>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in24'
     */
    vold_VCU_HVPRASts = (uint16)
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_tmOutFlgCfm();
  }

  /* End of Switch: '<S571>/Switch2' */

  /* Switch: '<S567>/Switch2' incorporates:
   *  Constant: '<S567>/volc_b_VCU_ACC2PosVol_ovrdflg'
   */
  if (volc_b_VCU_BatteryVol_ovrdflg) {
    /* Switch: '<S567>/Switch2' incorporates:
     *  Constant: '<S567>/volc_VCU_ACC2PosVol_ovrdval'
     */
    vold_VCU_BatteryVol = volc_VCU_BatteryVol_ovrdval;
  } else {
    /* Switch: '<S567>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion66'
     *  DataTypeConversion: '<S567>/type_conv'
     */
    vold_VCU_BatteryVol = (float32)swc_VCOP_ARID_DEF.DataTypeConversion181;
  }

  /* End of Switch: '<S567>/Switch2' */

  /* Switch: '<S565>/Switch2' incorporates:
   *  Constant: '<S565>/volc_b_VCU_ACC2PosVol_ovrdflg'
   */
  if (volc_b_VCU_ACC2PosVol_ovrdflg) {
    /* Switch: '<S565>/Switch2' incorporates:
     *  Constant: '<S565>/volc_VCU_ACC2PosVol_ovrdval'
     */
    vold_VCU_ACC2PosVol = volc_VCU_ACC2PosVol_ovrdval;
  } else {
    /* Switch: '<S565>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion30'
     */
    vold_VCU_ACC2PosVol = swc_VCOP_ARID_DEF.DataTypeConversion199;
  }

  /* End of Switch: '<S565>/Switch2' */

  /* Switch: '<S564>/Switch2' incorporates:
   *  Constant: '<S564>/volc_b_VCU_ACC1PosVol_ovrdflg'
   */
  if (volc_b_VCU_ACC1PosVol_ovrdflg) {
    /* Switch: '<S564>/Switch2' incorporates:
     *  Constant: '<S564>/volc_VCU_ACC1PosVol_ovrdval'
     */
    vold_VCU_ACC1PosVol = volc_VCU_ACC1PosVol_ovrdval;
  } else {
    /* Switch: '<S564>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion29'
     */
    vold_VCU_ACC1PosVol = swc_VCOP_ARID_DEF.DataTypeConversion200;
  }

  /* End of Switch: '<S564>/Switch2' */

  /* Switch: '<S568>/Switch2' incorporates:
   *  Constant: '<S568>/volc_b_VCU_Brake1Sts_invert'
   *  Constant: '<S568>/volc_b_VCU_Brake1Sts_ovrdflg'
   *  Switch: '<S568>/Switch1'
   */
  if (volc_b_VCU_Brake1Sts_ovrdflg) {
    /* Switch: '<S568>/Switch2' incorporates:
     *  Constant: '<S568>/volc_VCU_Brake1Sts_ovrdval'
     */
    vold_VCU_Brake1Sts = volc_VCU_Brake1Sts_ovrdval;
  } else if (volc_b_VCU_Brake1Sts_invert) {
    /* Switch: '<S568>/Switch1' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion24'
     *  Logic: '<S568>/Logical Operator'
     *  Switch: '<S568>/Switch2'
     */
    vold_VCU_Brake1Sts = !swc_VCOP_ARID_DEF.DataTypeConversion201;
  } else {
    /* Switch: '<S568>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion24'
     *  Switch: '<S568>/Switch1'
     */
    vold_VCU_Brake1Sts = swc_VCOP_ARID_DEF.DataTypeConversion201;
  }

  /* End of Switch: '<S568>/Switch2' */

  /* Switch: '<S574>/Switch2' incorporates:
   *  Constant: '<S574>/volc_b_VCU_StartSts_invert'
   *  Constant: '<S574>/volc_b_VCU_StartSts_ovrdflg'
   *  Switch: '<S574>/Switch1'
   */
  if (volc_b_VCU_ShiftD_ovrdflg) {
    /* Switch: '<S574>/Switch2' incorporates:
     *  Constant: '<S574>/volc_VCU_StartSts_ovrdval'
     */
    vold_VCU_ShiftD = volc_VCU_ShiftD_ovrdval;
  } else if (volc_b_VCU_ShiftD_invert) {
    /* Switch: '<S574>/Switch1' incorporates:
     *  Constant: '<S240>/volc_VCU_ShiftD'
     *  DataTypeConversion: '<S574>/type_conv'
     *  Logic: '<S574>/Logical Operator'
     *  Switch: '<S574>/Switch2'
     */
    vold_VCU_ShiftD = !volc_VCU_ShiftD;
  } else {
    /* Switch: '<S574>/Switch2' incorporates:
     *  Constant: '<S240>/volc_VCU_ShiftD'
     *  DataTypeConversion: '<S574>/type_conv'
     *  Switch: '<S574>/Switch1'
     */
    vold_VCU_ShiftD = volc_VCU_ShiftD;
  }

  /* End of Switch: '<S574>/Switch2' */

  /* Switch: '<S576>/Switch2' incorporates:
   *  Constant: '<S576>/volc_b_VCU_StartSts_invert'
   *  Constant: '<S576>/volc_b_VCU_StartSts_ovrdflg'
   *  Switch: '<S576>/Switch1'
   */
  if (volc_b_VCU_StartSts_ovrdflg) {
    /* Switch: '<S576>/Switch2' incorporates:
     *  Constant: '<S576>/volc_VCU_StartSts_ovrdval'
     */
    vold_VCU_StartSts = volc_VCU_StartSts_ovrdval;
  } else if (volc_b_VCU_StartSts_invert) {
    /* Switch: '<S576>/Switch1' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion25'
     *  Logic: '<S576>/Logical Operator'
     *  Switch: '<S576>/Switch2'
     */
    vold_VCU_StartSts = !swc_VCOP_ARID_DEF.DataTypeConversion202;
  } else {
    /* Switch: '<S576>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion25'
     *  Switch: '<S576>/Switch1'
     */
    vold_VCU_StartSts = swc_VCOP_ARID_DEF.DataTypeConversion202;
  }

  /* End of Switch: '<S576>/Switch2' */

  /* Switch: '<S570>/Switch2' incorporates:
   *  Constant: '<S570>/volc_b_VCU_ECOMode_invert'
   *  Constant: '<S570>/volc_b_VCU_ECOMode_ovrdflg'
   *  Switch: '<S570>/Switch1'
   */
  if (volc_b_VCU_ECOMode_ovrdflg) {
    /* Switch: '<S570>/Switch2' incorporates:
     *  Constant: '<S570>/volc_VCU_ECOMode_ovrdval'
     */
    vold_VCU_ECOMode = volc_VCU_ECOMode_ovrdval;
  } else if (volc_b_VCU_ECOMode_invert) {
    /* Switch: '<S570>/Switch1' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion26'
     *  Logic: '<S570>/Logical Operator'
     *  Switch: '<S570>/Switch2'
     */
    vold_VCU_ECOMode = !swc_VCOP_ARID_DEF.DataTypeConversion196;
  } else {
    /* Switch: '<S570>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion26'
     *  Switch: '<S570>/Switch1'
     */
    vold_VCU_ECOMode = swc_VCOP_ARID_DEF.DataTypeConversion196;
  }

  /* End of Switch: '<S570>/Switch2' */

  /* Switch: '<S573>/Switch2' incorporates:
   *  Constant: '<S573>/volc_b_VCU_ECOMode_invert'
   *  Constant: '<S573>/volc_b_VCU_ECOMode_ovrdflg'
   *  Switch: '<S573>/Switch1'
   */
  if (volc_b_VCU_ShiftClimbing_ovrdflg) {
    /* Switch: '<S573>/Switch2' incorporates:
     *  Constant: '<S573>/volc_VCU_ECOMode_ovrdval'
     */
    vold_VCU_ShiftClimbing = volc_VCU_ShiftClimbing_ovrdval;
  } else if (volc_b_VCU_ShiftClimbing_invert) {
    /* Switch: '<S573>/Switch1' incorporates:
     *  Constant: '<S240>/volc_VCU_ShiftClimbing'
     *  DataTypeConversion: '<S573>/type_conv'
     *  Logic: '<S573>/Logical Operator'
     *  Switch: '<S573>/Switch2'
     */
    vold_VCU_ShiftClimbing = !volc_VCU_ShiftClimbing;
  } else {
    /* Switch: '<S573>/Switch2' incorporates:
     *  Constant: '<S240>/volc_VCU_ShiftClimbing'
     *  DataTypeConversion: '<S573>/type_conv'
     *  Switch: '<S573>/Switch1'
     */
    vold_VCU_ShiftClimbing = volc_VCU_ShiftClimbing;
  }

  /* End of Switch: '<S573>/Switch2' */

  /* Switch: '<S575>/Switch2' incorporates:
   *  Constant: '<S575>/volc_b_VCU_StartSts_invert'
   *  Constant: '<S575>/volc_b_VCU_StartSts_ovrdflg'
   *  Switch: '<S575>/Switch1'
   */
  if (volc_b_VCU_ShiftR_ovrdflg) {
    /* Switch: '<S575>/Switch2' incorporates:
     *  Constant: '<S575>/volc_VCU_StartSts_ovrdval'
     */
    vold_VCU_ShiftR = volc_VCU_ShiftR_ovrdval;
  } else if (volc_b_VCU_ShiftR_invert) {
    /* Switch: '<S575>/Switch1' incorporates:
     *  Constant: '<S240>/volc_VCU_ShiftR'
     *  DataTypeConversion: '<S575>/type_conv'
     *  Logic: '<S575>/Logical Operator'
     *  Switch: '<S575>/Switch2'
     */
    vold_VCU_ShiftR = !volc_VCU_ShiftR;
  } else {
    /* Switch: '<S575>/Switch2' incorporates:
     *  Constant: '<S240>/volc_VCU_ShiftR'
     *  DataTypeConversion: '<S575>/type_conv'
     *  Switch: '<S575>/Switch1'
     */
    vold_VCU_ShiftR = volc_VCU_ShiftR;
  }

  /* End of Switch: '<S575>/Switch2' */

  /* Switch: '<S572>/Switch2' incorporates:
   *  Constant: '<S572>/volc_b_VCU_IgnONSts_invert'
   *  Constant: '<S572>/volc_b_VCU_IgnONSts_ovrdflg'
   *  Switch: '<S572>/Switch1'
   */
  if (volc_b_VCU_IgnONSts_ovrdflg) {
    /* Switch: '<S572>/Switch2' incorporates:
     *  Constant: '<S572>/volc_VCU_IgnONSts_ovrdval'
     */
    vold_VCU_IgnONSts = volc_VCU_IgnONSts_ovrdval;
  } else if (volc_b_VCU_IgnONSts_invert) {
    /* Switch: '<S572>/Switch1' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion27'
     *  Logic: '<S572>/Logical Operator'
     *  Switch: '<S572>/Switch2'
     */
    vold_VCU_IgnONSts = !swc_VCOP_ARID_DEF.DataTypeConversion535;
  } else {
    /* Switch: '<S572>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion27'
     *  Switch: '<S572>/Switch1'
     */
    vold_VCU_IgnONSts = swc_VCOP_ARID_DEF.DataTypeConversion535;
  }

  /* End of Switch: '<S572>/Switch2' */

  /* Switch: '<S569>/Switch2' incorporates:
   *  Constant: '<S569>/volc_b_VCU_Brake2Sts_invert'
   *  Constant: '<S569>/volc_b_VCU_Brake2Sts_ovrdflg'
   *  Switch: '<S569>/Switch1'
   */
  if (volc_b_VCU_Brake2Sts_ovrdflg) {
    /* Switch: '<S569>/Switch2' incorporates:
     *  Constant: '<S569>/volc_VCU_Brake2Sts_ovrdval'
     */
    vold_VCU_Brake2Sts = volc_VCU_Brake2Sts_ovrdval;
  } else if (volc_b_VCU_Brake2Sts_invert) {
    /* Switch: '<S569>/Switch1' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion28'
     *  Logic: '<S569>/Logical Operator'
     *  Switch: '<S569>/Switch2'
     */
    vold_VCU_Brake2Sts = !swc_VCOP_ARID_DEF.DataTypeConversion198;
  } else {
    /* Switch: '<S569>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion28'
     *  Switch: '<S569>/Switch1'
     */
    vold_VCU_Brake2Sts = swc_VCOP_ARID_DEF.DataTypeConversion198;
  }

  /* End of Switch: '<S569>/Switch2' */

  /* Switch: '<S586>/Switch2' incorporates:
   *  Constant: '<S586>/volc_b_VCU_Cabin_PumpFb_ovrdflg'
   */
  if (volc_b_VCU_Cabin_PumpFb_ovrdflg) {
    /* Switch: '<S586>/Switch2' incorporates:
     *  Constant: '<S586>/volc_VCU_Cabin_PumpFb_ovrdval'
     */
    vold_VCU_Cabin_PumpFb = volc_VCU_Cabin_PumpFb_ovrdval;
  } else {
    /* DataTypeConversion: '<S586>/type_conv' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion34'
     */
    rtb_Switch3_op = fmodf(floorf(swc_VCOP_ARID_DEF.DataTypeConversion173),
      256.0F);

    /* Switch: '<S586>/Switch2' incorporates:
     *  DataTypeConversion: '<S586>/type_conv'
     */
    vold_VCU_Cabin_PumpFb = (uint8)(rtb_Switch3_op < 0.0F ? (sint32)(uint8)-
      (sint8)(uint8)-rtb_Switch3_op : (sint32)(uint8)rtb_Switch3_op);
  }

  /* End of Switch: '<S586>/Switch2' */

  /* Switch: '<S589>/Switch2' incorporates:
   *  Constant: '<S589>/volc_b_VCU_HVB_PumpFb_ovrdflg'
   */
  if (volc_b_VCU_HVB_PumpFb_ovrdflg) {
    /* Switch: '<S589>/Switch2' incorporates:
     *  Constant: '<S589>/volc_VCU_HVB_PumpFb_ovrdval'
     */
    vold_VCU_HVB_PumpFb = volc_VCU_HVB_PumpFb_ovrdval;
  } else {
    /* DataTypeConversion: '<S589>/type_conv' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion35'
     */
    rtb_Switch3_op = fmodf(floorf(swc_VCOP_ARID_DEF.DataTypeConversion174),
      256.0F);

    /* Switch: '<S589>/Switch2' incorporates:
     *  DataTypeConversion: '<S589>/type_conv'
     */
    vold_VCU_HVB_PumpFb = (uint8)(rtb_Switch3_op < 0.0F ? (sint32)(uint8)-(sint8)
      (uint8)-rtb_Switch3_op : (sint32)(uint8)rtb_Switch3_op);
  }

  /* End of Switch: '<S589>/Switch2' */

  /* Switch: '<S585>/Switch2' incorporates:
   *  Constant: '<S585>/volc_b_VCU_CCFb_ovrdflg'
   */
  if (volc_b_VCU_CCFb_ovrdflg) {
    /* Switch: '<S585>/Switch2' incorporates:
     *  Constant: '<S585>/volc_VCU_CCFb_ovrdval'
     */
    vold_VCU_CCFb = volc_VCU_CCFb_ovrdval;
  } else {
    /* Switch: '<S585>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion39'
     *  DataTypeConversion: '<S585>/type_conv'
     */
    vold_VCU_CCFb = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion186;
  }

  /* End of Switch: '<S585>/Switch2' */

  /* Switch: '<S587>/Switch2' incorporates:
   *  Constant: '<S587>/volc_b_VCU_ChargWakeupSts_ovrdflg'
   */
  if (volc_b_VCU_ChargWakeupSts_ovrdflg) {
    /* Switch: '<S587>/Switch2' incorporates:
     *  Constant: '<S587>/volc_VCU_ChargWakeupSts_ovrdval'
     */
    vold_VCU_ChargWakeupSts = volc_VCU_ChargWakeupSts_ovrdval;
  } else {
    /* Switch: '<S587>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion40'
     *  DataTypeConversion: '<S587>/type_conv'
     */
    vold_VCU_ChargWakeupSts = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion185;
  }

  /* End of Switch: '<S587>/Switch2' */

  /* Switch: '<S591>/Switch2' incorporates:
   *  Constant: '<S591>/volc_b_VCU_PressureSwi2Sts_ovrdflg'
   */
  if (volc_b_VCU_PressureSwi2Sts_ovrdflg) {
    /* Switch: '<S591>/Switch2' incorporates:
     *  Constant: '<S591>/volc_VCU_PressureSwi2Sts_ovrdval'
     */
    vold_VCU_PressureSwi2Sts = volc_VCU_PressureSwi2Sts_ovrdval;
  } else {
    /* Switch: '<S591>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion41'
     *  DataTypeConversion: '<S591>/type_conv'
     */
    vold_VCU_PressureSwi2Sts = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion187;
  }

  /* End of Switch: '<S591>/Switch2' */

  /* Switch: '<S590>/Switch2' incorporates:
   *  Constant: '<S590>/volc_b_VCU_PressureSwi1Sts_ovrdflg'
   */
  if (volc_b_VCU_PressureSwi1Sts_ovrdflg) {
    /* Switch: '<S590>/Switch2' incorporates:
     *  Constant: '<S590>/volc_VCU_PressureSwi1Sts_ovrdval'
     */
    vold_VCU_PressureSwi1Sts = volc_VCU_PressureSwi1Sts_ovrdval;
  } else {
    /* Switch: '<S590>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion42'
     *  DataTypeConversion: '<S590>/type_conv'
     */
    vold_VCU_PressureSwi1Sts = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion189;
  }

  /* End of Switch: '<S590>/Switch2' */

  /* Switch: '<S588>/Switch2' incorporates:
   *  Constant: '<S588>/volc_VCU_EManualStartSwi_ovrdval'
   */
  vold_VCU_EManualStartSwi = volc_VCU_EManualStartSwi_ovrdval;

  /* Switch: '<S579>/Switch2' incorporates:
   *  Constant: '<S579>/volc_b_PMS_PTC1ConnStsFb_ovrdflg'
   */
  if (volc_b_PMS_PTC1ConnStsFb_ovrdflg) {
    /* Switch: '<S579>/Switch2' incorporates:
     *  Constant: '<S579>/volc_PMS_PTC1ConnStsFb_ovrdval'
     */
    vold_PMS_PTC1ConnStsFb = volc_PMS_PTC1ConnStsFb_ovrdval;
  } else {
    /* Switch: '<S579>/Switch2' incorporates:
     *  DataTypeConversion: '<S579>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in46'
     */
    vold_PMS_PTC1ConnStsFb =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptcConnStsFb();
  }

  /* End of Switch: '<S579>/Switch2' */

  /* Switch: '<S580>/Switch2' incorporates:
   *  Constant: '<S580>/volc_b_PMS_PTC1RelayFlt_ovrdflg'
   */
  if (volc_b_PMS_PTC1RelayFlt_ovrdflg) {
    /* Switch: '<S580>/Switch2' incorporates:
     *  Constant: '<S580>/volc_PMS_PTC1RelayFlt_ovrdval'
     */
    vold_PMS_PTC1RelayFlt = volc_PMS_PTC1RelayFlt_ovrdval;
  } else {
    /* Switch: '<S580>/Switch2' incorporates:
     *  DataTypeConversion: '<S580>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in47'
     */
    vold_PMS_PTC1RelayFlt = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptcRlyFlt();
  }

  /* End of Switch: '<S580>/Switch2' */

  /* Switch: '<S581>/Switch2' incorporates:
   *  Constant: '<S581>/volc_b_PMS_PTC3ConnStsFb_ovrdflg'
   */
  if (volc_b_PMS_PTC3ConnStsFb_ovrdflg) {
    /* Switch: '<S581>/Switch2' incorporates:
     *  Constant: '<S581>/volc_PMS_PTC3ConnStsFb_ovrdval'
     */
    vold_PMS_PTC3ConnStsFb = volc_PMS_PTC3ConnStsFb_ovrdval;
  } else {
    /* Switch: '<S581>/Switch2' incorporates:
     *  DataTypeConversion: '<S581>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in48'
     */
    vold_PMS_PTC3ConnStsFb =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptc3ConnStsFb();
  }

  /* End of Switch: '<S581>/Switch2' */

  /* Switch: '<S582>/Switch2' incorporates:
   *  Constant: '<S582>/volc_b_PMS_PTC3RelayFlt_ovrdflg'
   */
  if (volc_b_PMS_PTC3RelayFlt_ovrdflg) {
    /* Switch: '<S582>/Switch2' incorporates:
     *  Constant: '<S582>/volc_PMS_PTC3RelayFlt_ovrdval'
     */
    vold_PMS_PTC3RelayFlt = volc_PMS_PTC3RelayFlt_ovrdval;
  } else {
    /* Switch: '<S582>/Switch2' incorporates:
     *  DataTypeConversion: '<S582>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in53'
     */
    vold_PMS_PTC3RelayFlt = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptc3RlyFlt
      ();
  }

  /* End of Switch: '<S582>/Switch2' */

  /* Switch: '<S577>/Switch2' incorporates:
   *  Constant: '<S577>/volc_b_PMS_AccessoryConnStsFb_ovrdflg'
   */
  if (volc_b_PMS_AccessoryConnStsFb_ovrdflg) {
    /* Switch: '<S577>/Switch2' incorporates:
     *  Constant: '<S577>/volc_PMS_AccessoryConnStsFb_ovrdval'
     */
    vold_PMS_AccessoryConnStsFb = volc_PMS_AccessoryConnStsFb_ovrdval;
  } else {
    /* Switch: '<S577>/Switch2' incorporates:
     *  DataTypeConversion: '<S577>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in35'
     */
    vold_PMS_AccessoryConnStsFb =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyRlySts();
  }

  /* End of Switch: '<S577>/Switch2' */

  /* Switch: '<S578>/Switch2' incorporates:
   *  Constant: '<S578>/volc_b_PMS_AccessoryRelayFlt_ovrdflg'
   */
  if (volc_b_PMS_AccessoryRelayFlt_ovrdflg) {
    /* Switch: '<S578>/Switch2' incorporates:
     *  Constant: '<S578>/volc_PMS_AccessoryRelayFlt_ovrdval'
     */
    vold_PMS_AccessoryRelayFlt = volc_PMS_AccessoryRelayFlt_ovrdval;
  } else {
    /* Switch: '<S578>/Switch2' incorporates:
     *  DataTypeConversion: '<S578>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in33'
     */
    vold_PMS_AccessoryRelayFlt =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyRlyFlt();
  }

  /* End of Switch: '<S578>/Switch2' */

  /* Switch: '<S583>/Switch2' incorporates:
   *  Constant: '<S583>/volc_b_PMS_PreAccessoryConnStsFb_ovrdflg'
   */
  if (volc_b_PMS_PreAccessoryConnStsFb_ovrdflg) {
    /* Switch: '<S583>/Switch2' incorporates:
     *  Constant: '<S583>/volc_PMS_PreAccessoryConnStsFb_ovrdval'
     */
    vold_PMS_PreAccessoryConnStsFb = volc_PMS_PreAccessoryConnStsFb_ovrdval;
  } else {
    /* Switch: '<S583>/Switch2' incorporates:
     *  DataTypeConversion: '<S583>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in32'
     */
    vold_PMS_PreAccessoryConnStsFb =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyPreRlySts();
  }

  /* End of Switch: '<S583>/Switch2' */

  /* Switch: '<S584>/Switch2' incorporates:
   *  Constant: '<S584>/volc_b_PMS_PreAccessoryRelayFlt_ovrdflg'
   */
  if (volc_b_PMS_PreAccessoryRelayFlt_ovrdflg) {
    /* Switch: '<S584>/Switch2' incorporates:
     *  Constant: '<S584>/volc_PMS_PreAccessoryRelayFlt_ovrdval'
     */
    vold_PMS_PreAccessoryRelayFlt = volc_PMS_PreAccessoryRelayFlt_ovrdval;
  } else {
    /* Switch: '<S584>/Switch2' incorporates:
     *  DataTypeConversion: '<S584>/type_conv'
     *  Inport generated from: '<Root>/vcsb_HVSM_in34'
     */
    vold_PMS_PreAccessoryRelayFlt =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_accyPreRlyFlt();
  }

  /* End of Switch: '<S584>/Switch2' */

  /* Switch: '<S594>/Switch2' incorporates:
   *  Constant: '<S594>/volc_b_VCU_EmergencyStop_ovrdflg'
   */
  if (volc_b_VCU_EmergencyStop_ovrdflg) {
    /* Switch: '<S594>/Switch2' incorporates:
     *  Constant: '<S594>/volc_VCU_EmergencyStop_ovrdval'
     */
    vold_VCU_EmergencyStop = volc_VCU_EmergencyStop_ovrdval;
  } else {
    /* Switch: '<S594>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion46'
     *  DataTypeConversion: '<S594>/type_conv'
     */
    vold_VCU_EmergencyStop = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion192;
  }

  /* End of Switch: '<S594>/Switch2' */

  /* Switch: '<S596>/Switch2' incorporates:
   *  Constant: '<S596>/volc_b_VCU_HVILReturn_ovrdflg'
   */
  if (volc_b_VCU_HVILReturn_ovrdflg) {
    /* Switch: '<S596>/Switch2' incorporates:
     *  Constant: '<S596>/volc_VCU_HVILReturn_ovrdval'
     */
    vold_VCU_HVILReturn = volc_VCU_HVILReturn_ovrdval;
  } else {
    /* Switch: '<S596>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion45'
     */
    vold_VCU_HVILReturn = swc_VCOP_ARID_DEF.DataTypeConversion193;
  }

  /* End of Switch: '<S596>/Switch2' */

  /* Switch: '<S595>/Switch2' incorporates:
   *  Constant: '<S595>/volc_b_VCU_GearPositionInput_ovrdflg'
   */
  if (volc_b_VCU_GearPositionInput_ovrdflg) {
    /* Switch: '<S595>/Switch2' incorporates:
     *  Constant: '<S595>/volc_VCU_GearPositionInput_ovrdval'
     */
    vold_VCU_GearPositionInput = volc_VCU_GearPositionInput_ovrdval;
  } else {
    /* Switch: '<S595>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion47'
     */
    vold_VCU_GearPositionInput = swc_VCOP_ARID_DEF.DataTypeConversion194;
  }

  /* End of Switch: '<S595>/Switch2' */

  /* Switch: '<S593>/Switch2' incorporates:
   *  Constant: '<S593>/volc_b_VCU_Brake2PosVol_ovrdflg'
   */
  if (volc_b_VCU_Brake2PosVol_ovrdflg) {
    /* Switch: '<S593>/Switch2' incorporates:
     *  Constant: '<S593>/volc_VCU_Brake2PosVol_ovrdval'
     */
    vold_VCU_Brake2PosVol = volc_VCU_Brake2PosVol_ovrdval;
  } else {
    /* Switch: '<S593>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion48'
     */
    vold_VCU_Brake2PosVol = swc_VCOP_ARID_DEF.DataTypeConversion188;
  }

  /* End of Switch: '<S593>/Switch2' */

  /* Switch: '<S592>/Switch2' incorporates:
   *  Constant: '<S592>/volc_b_VCU_Brake1PosVol_ovrdflg'
   */
  if (volc_b_VCU_Brake1PosVol_ovrdflg) {
    /* Switch: '<S592>/Switch2' incorporates:
     *  Constant: '<S592>/volc_VCU_Brake1PosVol_ovrdval'
     */
    vold_VCU_Brake1PosVol = volc_VCU_Brake1PosVol_ovrdval;
  } else {
    /* Switch: '<S592>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion49'
     */
    vold_VCU_Brake1PosVol = swc_VCOP_ARID_DEF.DataTypeConversion218;
  }

  /* End of Switch: '<S592>/Switch2' */

  /* Switch: '<S598>/Switch2' incorporates:
   *  Constant: '<S598>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
   */
  vold_VCU_BattCoolVal3_FBV6 = volc_VCU_BattCoolVal3_FBV6_ovrdval;

  /* Switch: '<S597>/Switch2' incorporates:
   *  Constant: '<S597>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
   */
  vold_VCU_BattCoolVal3_FBV5 = volc_VCU_BattCoolVal3_FBV5_ovrdval;

  /* Switch: '<S600>/Switch2' incorporates:
   *  Constant: '<S600>/volc_VCU_BattHeatVal2_FBV6_ovrdval'
   */
  vold_VCU_BattHeatVal2_FBV6 = volc_VCU_BattHeatVal2_FBV6_ovrdval;

  /* Switch: '<S599>/Switch2' incorporates:
   *  Constant: '<S599>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
   */
  vold_VCU_BattHeatVal2_FBV5 = volc_VCU_BattHeatVal2_FBV5_ovrdval;

  /* Switch: '<S601>/Switch2' incorporates:
   *  Constant: '<S601>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
   */
  vold_VCU_CabinLoopVal1_FBV6 = volc_VCU_CabinLoopVal1_FBV6_ovrdval;

  /* Switch: '<S602>/Switch2' incorporates:
   *  Constant: '<S602>/volc_VCU_CabinLoopVal2_FBV5_ovrdval'
   */
  vold_VCU_CabinLoopVal2_FBV5 = volc_VCU_CabinLoopVal2_FBV5_ovrdval;

  /* Switch: '<S603>/Switch2' incorporates:
   *  Constant: '<S603>/volc_b_VCU_DriveCircuitVol_ovrdflg'
   */
  if (volc_b_VCU_DriveCircuitVol_ovrdflg) {
    /* Switch: '<S603>/Switch2' incorporates:
     *  Constant: '<S603>/volc_VCU_DriveCircuitVol_ovrdval'
     */
    vold_VCU_DriveCircuitVol = volc_VCU_DriveCircuitVol_ovrdval;
  } else {
    /* DataTypeConversion: '<S603>/type_conv' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion56'
     */
    tmp = fmod(floor(swc_VCOP_ARID_DEF.DataTypeConversion212), 65536.0);

    /* Switch: '<S603>/Switch2' incorporates:
     *  DataTypeConversion: '<S603>/type_conv'
     */
    vold_VCU_DriveCircuitVol = (uint16)(tmp < 0.0 ? (sint32)(uint16)-(sint16)
      (uint16)-tmp : (sint32)(uint16)tmp);
  }

  /* End of Switch: '<S603>/Switch2' */

  /* Switch: '<S612>/Switch2' incorporates:
   *  Constant: '<S607>/volc_b_VCU_LockVehSts_ovrdflg'
   */
  if (volc_b_VCU_LockVehSts_ovrdflg) {
    /* Switch: '<S612>/Switch2' incorporates:
     *  Constant: '<S607>/volc_VCU_LockVehSts_ovrdval'
     */
    vold_VCU_LockVehSts = volc_VCU_LockVehSts_ovrdval;
  } else {
    /* Switch: '<S612>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in190'
     */
    vold_VCU_LockVehSts = (uint8)
      Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_b_LockVehSts();
  }

  /* End of Switch: '<S612>/Switch2' */

  /* Switch: '<S610>/Switch2' incorporates:
   *  Constant: '<S605>/volc_b_VCU_FunLockVehActive_ovrdflg'
   */
  if (volc_b_VCU_FunLockVehActive_ovrdflg) {
    /* Switch: '<S610>/Switch2' incorporates:
     *  Constant: '<S605>/volc_VCU_FunLockVehActive_ovrdval'
     */
    vold_VCU_FunLockVehActive = volc_VCU_FunLockVehActive_ovrdval;
  } else {
    /* Switch: '<S610>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in188'
     */
    vold_VCU_FunLockVehActive =
      Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_FunLockVehActive();
  }

  /* End of Switch: '<S610>/Switch2' */

  /* Switch: '<S609>/Switch2' incorporates:
   *  Constant: '<S604>/volc_b_VCU_FunAnti_DismantleActive_ovrdflg'
   */
  if (volc_b_VCU_FunAnti_DismantleActive_ovrdflg) {
    /* Switch: '<S609>/Switch2' incorporates:
     *  Constant: '<S604>/volc_VCU_FunAnti_DismantleActive_ovrdval'
     */
    vold_VCU_FunAnti_DismantleActive = volc_VCU_FunAnti_DismantleActive_ovrdval;
  } else {
    /* Switch: '<S609>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in139'
     */
    vold_VCU_FunAnti_DismantleActive =
      Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive();
  }

  /* End of Switch: '<S609>/Switch2' */

  /* Switch: '<S613>/Switch2' incorporates:
   *  Constant: '<S608>/volc_b_VCU_LockVehType_ovrdflg'
   */
  if (volc_b_VCU_LockVehType_ovrdflg) {
    /* Switch: '<S613>/Switch2' incorporates:
     *  Constant: '<S608>/volc_VCU_LockVehType_ovrdval'
     */
    vold_VCU_LockVehType = volc_VCU_LockVehType_ovrdval;
  } else {
    /* Switch: '<S613>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in189'
     */
    vold_VCU_LockVehType =
      Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_LockVehType();
  }

  /* End of Switch: '<S613>/Switch2' */

  /* Switch: '<S611>/Switch2' incorporates:
   *  Constant: '<S606>/volc_b_VCU_LockLimResult_ovrdflg'
   */
  if (volc_b_VCU_LockLimResult_ovrdflg) {
    /* Switch: '<S611>/Switch2' incorporates:
     *  Constant: '<S606>/volc_VCU_LockLimResult_ovrdval'
     */
    vold_VCU_LockLimResult = volc_VCU_LockLimResult_ovrdval;
  } else {
    /* Switch: '<S611>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in140'
     */
    vold_VCU_LockLimResult =
      Rte_IRead_swc_VCOP_Step_vcsb_RMLK_rlcd_num_LockLimResult();
  }

  /* End of Switch: '<S611>/Switch2' */

  /* Switch: '<S622>/Switch2' incorporates:
   *  Constant: '<S616>/volc_b_VCU_DTCClearInhibit_ovrdflg'
   */
  if (volc_b_VCU_NMSts_ovrdflg) {
    /* Switch: '<S622>/Switch2' incorporates:
     *  Constant: '<S616>/volc_VCU_DTCClearInhibit_ovrdval'
     */
    vold_VCU_NMSts = volc_VCU_NMSts_ovrdval;
  } else {
    /* Switch: '<S622>/Switch2' */
    vold_VCU_NMSts = swc_VCOP_ARID_DEF.DataTypeConversion123;
  }

  /* End of Switch: '<S622>/Switch2' */

  /* Switch: '<S623>/Switch2' incorporates:
   *  Constant: '<S617>/volc_flg_VCU_AccePedalPosD_ovrdflg'
   */
  if (volc_b_VCU_RMR_ovrdflg) {
    /* Switch: '<S623>/Switch2' incorporates:
     *  Constant: '<S617>/volc_VCU_AccePedalPosD_ovrdval'
     */
    vold_VCU_RMR = volc_VCU_RMR_ovrdval;
  } else {
    /* Switch: '<S623>/Switch2' */
    vold_VCU_RMR = swc_VCOP_ARID_DEF.DataTypeConversion115;
  }

  /* End of Switch: '<S623>/Switch2' */

  /* Switch: '<S621>/Switch2' incorporates:
   *  Constant: '<S615>/volc_flg_VCU_AccePedalPosD_ovrdflg'
   */
  if (volc_b_VCU_Address_ovrdflg) {
    /* Switch: '<S621>/Switch2' incorporates:
     *  Constant: '<S615>/volc_VCU_AccePedalPosD_ovrdval'
     */
    vold_VCU_Address = volc_VCU_Address_ovrdval;
  } else {
    /* Switch: '<S621>/Switch2' */
    vold_VCU_Address = swc_VCOP_ARID_DEF.DataTypeConversion128;
  }

  /* End of Switch: '<S621>/Switch2' */

  /* Switch: '<S620>/Switch2' incorporates:
   *  Constant: '<S614>/volc_flg_VCU_AccePedalPosE_ovrdflg'
   */
  if (volc_b_VCU_AWB_ovrdflg) {
    /* Switch: '<S620>/Switch2' incorporates:
     *  Constant: '<S614>/volc_VCU_AccePedalPosE_ovrdval'
     */
    vold_VCU_AWB = volc_VCU_AWB_ovrdval;
  } else {
    /* Switch: '<S620>/Switch2' */
    vold_VCU_AWB = swc_VCOP_ARID_DEF.DataTypeConversion130;
  }

  /* End of Switch: '<S620>/Switch2' */

  /* Switch: '<S624>/Switch2' incorporates:
   *  Constant: '<S618>/volc_flg_VCU_AccePedalPosE_ovrdflg'
   */
  if (volc_b_VCU_Stayawake_reasons_ovrdflg) {
    /* Switch: '<S624>/Switch2' incorporates:
     *  Constant: '<S618>/volc_VCU_AccePedalPosE_ovrdval'
     */
    vold_VCU_Stayawake_reasons = volc_VCU_Stayawake_reasons_ovrdval;
  } else {
    /* Switch: '<S624>/Switch2' */
    vold_VCU_Stayawake_reasons = swc_VCOP_ARID_DEF.DataTypeConversion132;
  }

  /* End of Switch: '<S624>/Switch2' */

  /* Switch: '<S625>/Switch2' incorporates:
   *  Constant: '<S619>/volc_b_VCU_DTCClearInhibit_ovrdflg'
   */
  if (volc_b_VCU_Wakeup_reasons_ovrdflg) {
    /* Switch: '<S625>/Switch2' incorporates:
     *  Constant: '<S619>/volc_VCU_DTCClearInhibit_ovrdval'
     */
    vold_VCU_Wakeup_reasons = volc_VCU_Wakeup_reasons_ovrdval;
  } else {
    /* Switch: '<S625>/Switch2' */
    vold_VCU_Wakeup_reasons = swc_VCOP_ARID_DEF.DataTypeConversion133;
  }

  /* End of Switch: '<S625>/Switch2' */

  /* Switch: '<S631>/Switch2' incorporates:
   *  Constant: '<S626>/volc_flg_VCU_AccePedalPosD_ovrdflg'
   */
  if (volc_b_VCU_AccePedalPosD_ovrdflg) {
    /* Switch: '<S631>/Switch2' incorporates:
     *  Constant: '<S626>/volc_VCU_AccePedalPosD_ovrdval'
     */
    vold_VCU_AccePedalPosD = volc_VCU_AccePedalPosD_ovrdval;
  } else {
    /* Switch: '<S631>/Switch2' */
    vold_VCU_AccePedalPosD = swc_VCOP_ARID_DEF.DataTypeConversion178;
  }

  /* End of Switch: '<S631>/Switch2' */

  /* Switch: '<S632>/Switch2' incorporates:
   *  Constant: '<S627>/volc_flg_VCU_AccePedalPosE_ovrdflg'
   */
  if (volc_b_VCU_AccePedalPosE_ovrdflg) {
    /* Switch: '<S632>/Switch2' incorporates:
     *  Constant: '<S627>/volc_VCU_AccePedalPosE_ovrdval'
     */
    vold_VCU_AccePedalPosE = volc_VCU_AccePedalPosE_ovrdval;
  } else {
    /* Switch: '<S632>/Switch2' */
    vold_VCU_AccePedalPosE = swc_VCOP_ARID_DEF.DataTypeConversion180;
  }

  /* End of Switch: '<S632>/Switch2' */

  /* Switch: '<S634>/Switch2' incorporates:
   *  Constant: '<S629>/volc_b_VCU_TotalOdometer_ovrdflg'
   */
  if (volc_b_VCU_TotalOdometer_ovrdflg) {
    /* Switch: '<S634>/Switch2' incorporates:
     *  Constant: '<S629>/volc_VCU_TotalOdometer_ovrdval'
     */
    vold_VCU_TotalOdometer = volc_VCU_TotalOdometer_ovrdval;
  } else {
    /* Switch: '<S634>/Switch2' */
    vold_VCU_TotalOdometer = swc_VCOP_ARID_DEF.DataTypeConversion195;
  }

  /* End of Switch: '<S634>/Switch2' */

  /* Switch: '<S635>/Switch2' incorporates:
   *  Constant: '<S630>/volc_b_VCU_TotalOdometerInvalid_ovrdflg'
   */
  if (volc_b_VCU_TotalOdometerInvalid_ovrdflg) {
    /* Switch: '<S635>/Switch2' incorporates:
     *  Constant: '<S630>/volc_VCU_TotalOdometerInvalid_ovrdval'
     */
    vold_VCU_TotalOdometerInvalid = volc_VCU_TotalOdometerInvalid_ovrdval;
  } else {
    /* Switch: '<S635>/Switch2' */
    vold_VCU_TotalOdometerInvalid = swc_VCOP_ARID_DEF.DataTypeConversion197;
  }

  /* End of Switch: '<S635>/Switch2' */

  /* Switch: '<S633>/Switch2' incorporates:
   *  Constant: '<S628>/volc_b_VCU_MILTelltale_ovrdflg'
   */
  if (volc_b_VCU_MILTelltale_ovrdflg) {
    /* Switch: '<S633>/Switch2' incorporates:
     *  Constant: '<S628>/volc_VCU_MILTelltale_ovrdval'
     */
    vold_VCU_MILTelltale = volc_VCU_MILTelltale_ovrdval;
  } else {
    /* Switch: '<S633>/Switch2' incorporates:
     *  Constant: '<S246>/volc_VCU_MILTelltale_dftval'
     */
    vold_VCU_MILTelltale = volc_VCU_MILTelltale_dftval;
  }

  /* End of Switch: '<S633>/Switch2' */

  /* Switch: '<S637>/Switch2' incorporates:
   *  Constant: '<S636>/volc_flg_VCU_VehicleSysFltLevel_ovrdflg'
   */
  if (volc_b_VCU_VehicleSysFltLevel_ovrdflg) {
    /* Switch: '<S637>/Switch2' incorporates:
     *  Constant: '<S636>/volc_VCU_VehicleSysFltLevel_ovrdval'
     */
    vold_VCU_VehicleSysFltLevel = volc_VCU_VehicleSysFltLevel_ovrdval;
  } else {
    /* Switch: '<S637>/Switch2' */
    vold_VCU_VehicleSysFltLevel = swc_VCOP_ARID_DEF.DataTypeConversion107;
  }

  /* End of Switch: '<S637>/Switch2' */

  /* Switch: '<S662>/Switch2' incorporates:
   *  Constant: '<S642>/volc_flg_VCU_DriveModeInd_ovrdflg'
   */
  if (volc_b_VCU_DriveModeInd_ovrdflg) {
    /* Switch: '<S662>/Switch2' incorporates:
     *  Constant: '<S642>/volc_VCU_DriveModeInd_ovrdval'
     */
    vold_VCU_DriveModeInd = volc_VCU_DriveModeInd_ovrdval;
  } else {
    /* Switch: '<S662>/Switch2' */
    vold_VCU_DriveModeInd = dspd_st_drvMod;
  }

  /* End of Switch: '<S662>/Switch2' */

  /* Switch: '<S670>/Switch2' incorporates:
   *  Constant: '<S650>/volc_flg_VCU_PTModeInd_ovrdflg'
   */
  if (volc_b_VCU_PTModeInd_ovrdflg) {
    /* Switch: '<S670>/Switch2' incorporates:
     *  Constant: '<S650>/volc_VCU_PTModeInd_ovrdval'
     */
    vold_VCU_PTModeInd = volc_VCU_PTModeInd_ovrdval;
  } else {
    /* Switch: '<S670>/Switch2' */
    vold_VCU_PTModeInd = dspd_st_PTModeInd;
  }

  /* End of Switch: '<S670>/Switch2' */

  /* Switch: '<S671>/Switch2' incorporates:
   *  Constant: '<S248>/Constant3'
   *  Constant: '<S638>/Constant'
   *  Constant: '<S651>/volc_flg_VCU_PTReadyInd_ovrdflg'
   *  RelationalOperator: '<S638>/Compare'
   *  Switch: '<S248>/Switch5'
   */
  if (volc_b_VCU_PTReadyInd_ovrdflg) {
    /* Switch: '<S671>/Switch2' incorporates:
     *  Constant: '<S651>/volc_VCU_PTReadyInd_ovrdval'
     */
    vold_VCU_PTReadyInd = volc_VCU_PTReadyInd_ovrdval;
  } else if (((uint8)VEH_SWT_INF) == ((uint8)4U)) {
    /* DataTypeConversion: '<S248>/Data Type Conversion2' incorporates:
     *  Switch: '<S248>/Switch5'
     */
    tmp = fmod(floor(swc_VCOP_ARID_DEF.DataTypeConversion532), 256.0);

    /* Switch: '<S671>/Switch2' incorporates:
     *  DataTypeConversion: '<S248>/Data Type Conversion2'
     *  Switch: '<S248>/Switch5'
     */
    vold_VCU_PTReadyInd = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-tmp
      : (sint32)(uint8)tmp);
  } else {
    /* Switch: '<S671>/Switch2' incorporates:
     *  Switch: '<S248>/Switch5'
     */
    vold_VCU_PTReadyInd = swc_VCOP_ARID_DEF.DataTypeConversion41;
  }

  /* End of Switch: '<S671>/Switch2' */

  /* Switch: '<S663>/Switch2' incorporates:
   *  Constant: '<S643>/volc_flg_VCU_DrivePwrCircuitInd_ovrdflg'
   */
  if (volc_b_VCU_DrivePwrCircuitInd_ovrdflg) {
    /* Switch: '<S663>/Switch2' incorporates:
     *  Constant: '<S643>/volc_VCU_DrivePwrCircuitInd_ovrdval'
     */
    vold_VCU_DrivePwrCircuitInd = volc_VCU_DrivePwrCircuitInd_ovrdval;
  } else {
    /* Switch: '<S663>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion7'
     */
    vold_VCU_DrivePwrCircuitInd = (uint8)hvbd_b_HVRdy;
  }

  /* End of Switch: '<S663>/Switch2' */

  /* Switch: '<S673>/Switch2' incorporates:
   *  Constant: '<S653>/volc_flg_VCU_TurtleLampReq_ovrdflg'
   */
  if (volc_b_VCU_TurtleLampReq_ovrdflg) {
    /* Switch: '<S673>/Switch2' incorporates:
     *  Constant: '<S653>/volc_VCU_TurtleLampReq_ovrdval'
     */
    vold_VCU_TurtleLampReq = volc_VCU_TurtleLampReq_ovrdval;
  } else {
    /* DataTypeConversion: '<S159>/Data Type Conversion59' */
    tmp = fmod(trunc(swc_VCOP_ARID_DEF.srud_st_turtleLmpReq), 256.0);

    /* Switch: '<S673>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion59'
     */
    vold_VCU_TurtleLampReq = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-
      tmp : (sint32)(uint8)tmp);
  }

  /* End of Switch: '<S673>/Switch2' */

  /* Switch: '<S661>/Switch2' incorporates:
   *  Constant: '<S641>/volc_flg_VCU_DCDC_WorkSts_ovrdflg'
   */
  if (volc_b_VCU_DCDC_WorkSts_ovrdflg) {
    /* Switch: '<S661>/Switch2' incorporates:
     *  Constant: '<S641>/volc_VCU_DCDC_WorkSts_ovrdval'
     */
    vold_VCU_DCDC_WorkSts = volc_VCU_DCDC_WorkSts_ovrdval;
  } else {
    /* Switch: '<S661>/Switch2' */
    vold_VCU_DCDC_WorkSts = swc_VCOP_ARID_DEF.DataTypeConversion168;
  }

  /* End of Switch: '<S661>/Switch2' */

  /* Switch: '<S669>/Switch2' incorporates:
   *  Constant: '<S649>/volc_VCU_PTHVSysErrorLampStsInd_ovrdval'
   */
  vold_VCU_PTHVSysErrorLampStsInd = volc_VCU_PTHVSysErrorLampStsInd_ovrdval;

  /* Switch: '<S665>/Switch2' incorporates:
   *  Constant: '<S645>/volc_flg_VCU_GearOperateErr_ovrdflg'
   */
  if (volc_b_VCU_GearOperateErr_ovrdflg) {
    /* Switch: '<S665>/Switch2' incorporates:
     *  Constant: '<S645>/volc_VCU_GearOperateErr_ovrdval'
     */
    vold_VCU_GearOperateErr = volc_VCU_GearOperateErr_ovrdval;
  } else {
    /* Switch: '<S665>/Switch2' */
    vold_VCU_GearOperateErr = swc_VCOP_ARID_DEF.dspd_st_gearOptErr;
  }

  /* End of Switch: '<S665>/Switch2' */

  /* Switch: '<S672>/Switch2' incorporates:
   *  Constant: '<S652>/volc_VCU_PTSysElecPwrInd_ovrdval'
   */
  vold_VCU_PTSysElecPwrInd = volc_VCU_PTSysElecPwrInd_ovrdval;

  /* Switch: '<S666>/Switch2' incorporates:
   *  Constant: '<S646>/volc_flg_VCU_GearPositionInd_ovrdflg'
   */
  if (volc_b_VCU_GearPositionInd_ovrdflg) {
    /* Switch: '<S666>/Switch2' incorporates:
     *  Constant: '<S646>/volc_VCU_GearPositionInd_ovrdval'
     */
    vold_VCU_GearPositionInd = volc_VCU_GearPositionInd_ovrdval;
  } else {
    /* Switch: '<S666>/Switch2' */
    vold_VCU_GearPositionInd = dspd_st_gearPosnInd;
  }

  /* End of Switch: '<S666>/Switch2' */

  /* Switch: '<S667>/Switch2' incorporates:
   *  Constant: '<S647>/volc_flg_VCU_HandbrakeSts_ovrdflg'
   */
  if (volc_b_VCU_HandbrakeSts_ovrdflg) {
    /* Switch: '<S667>/Switch2' incorporates:
     *  Constant: '<S647>/volc_VCU_HandbrakeSts_ovrdval'
     */
    vold_VCU_HandbrakeSts = volc_VCU_HandbrakeSts_ovrdval;
  } else {
    /* Switch: '<S667>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion62'
     */
    vold_VCU_HandbrakeSts = (uint8)dspd_b_hndbrkSt;
  }

  /* End of Switch: '<S667>/Switch2' */

  /* Switch: '<S660>/Switch2' incorporates:
   *  Constant: '<S640>/volc_flg_VCU_BrkSysErr_ovrdflg'
   */
  if (volc_b_VCU_BrkSysErr_ovrdflg) {
    /* Switch: '<S660>/Switch2' incorporates:
     *  Constant: '<S640>/volc_VCU_BrkSysErr_ovrdval'
     */
    vold_VCU_BrkSysErr = volc_VCU_BrkSysErr_ovrdval;
  } else {
    /* Switch: '<S660>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion63'
     *  Inport generated from: '<Root>/vcsb_HMIF_in16'
     */
    vold_VCU_BrkSysErr = (uint8)
      Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_brkSysFlt();
  }

  /* End of Switch: '<S660>/Switch2' */

  /* Switch: '<S674>/Switch2' incorporates:
   *  Constant: '<S654>/volc_VCU_VehicleAbnormalSts_ovrdval'
   */
  vold_VCU_VehicleAbnormalSts = volc_VCU_VehicleAbnormalSts_ovrdval;

  /* Switch: '<S668>/Switch2' incorporates:
   *  Constant: '<S648>/volc_flg_VCU_IgniteSts_ovrdflg'
   */
  if (volc_b_VCU_IgniteSts_ovrdflg) {
    /* Switch: '<S668>/Switch2' incorporates:
     *  Constant: '<S648>/volc_VCU_IgniteSts_ovrdval'
     */
    vold_VCU_IgniteSts = volc_VCU_IgniteSts_ovrdval;
  } else {
    /* Switch: '<S668>/Switch2' incorporates:
     *  DataTypeConversion: '<S159>/Data Type Conversion65'
     */
    vold_VCU_IgniteSts = (uint8)dspd_b_ignSt;
  }

  /* End of Switch: '<S668>/Switch2' */

  /* Switch: '<S678>/Switch2' incorporates:
   *  Constant: '<S658>/volc_flg_VCU_VehicleSysErrorLevel_ovrdflg'
   */
  if (volc_b_VCU_VehicleSysErrorLevel_ovrdflg) {
    /* Switch: '<S678>/Switch2' incorporates:
     *  Constant: '<S658>/volc_VCU_VehicleSysErrorLevel_ovrdval'
     */
    vold_VCU_VehicleSysErrorLevel = volc_VCU_VehicleSysErrorLevel_ovrdval;
  } else {
    /* Switch: '<S678>/Switch2' */
    vold_VCU_VehicleSysErrorLevel = swc_VCOP_ARID_DEF.DataTypeConversion107;
  }

  /* End of Switch: '<S678>/Switch2' */

  /* Switch: '<S675>/Switch2' incorporates:
   *  Constant: '<S655>/volc_flg_VCU_VehicleRunMode_ovrdflg'
   */
  if (volc_b_VCU_VehicleRunMode_ovrdflg) {
    /* Switch: '<S675>/Switch2' incorporates:
     *  Constant: '<S655>/volc_VCU_VehicleRunMode_ovrdval'
     */
    vold_VCU_VehicleRunMode = volc_VCU_VehicleRunMode_ovrdval;
  } else {
    /* Switch: '<S675>/Switch2' */
    vold_VCU_VehicleRunMode = swc_VCOP_ARID_DEF.DataTypeConversion105;
  }

  /* End of Switch: '<S675>/Switch2' */

  /* Switch: '<S676>/Switch2' incorporates:
   *  Constant: '<S656>/volc_VCU_VehicleSlipWarning'
   */
  vold_VCU_VehicleSlipWarning = volc_VCU_VehicleSlipWarning_ovrdval;

  /* Switch: '<S664>/Switch2' incorporates:
   *  Constant: '<S644>/volc_b_VCU_EVanualStartSwi_ovrdflg'
   */
  if (volc_b_VCU_EVanualStartSwi_ovrdflg) {
    /* Switch: '<S664>/Switch2' incorporates:
     *  Constant: '<S644>/volc_VCU_EVanualStartSwi_ovrdval'
     */
    vold_VCU_EVanualStartSwi = volc_VCU_EVanualStartSwi_ovrdval;
  } else {
    /* Switch: '<S664>/Switch2' incorporates:
     *  Constant: '<S248>/volc_VCU_EVanualStartSwi_dftval'
     */
    vold_VCU_EVanualStartSwi = volc_VCU_EVanualStartSwi_dftval;
  }

  /* End of Switch: '<S664>/Switch2' */

  /* Switch: '<S677>/Switch2' incorporates:
   *  Constant: '<S657>/volc_b_VCU_VehicleSubSysErrorLevel_ovrdflg'
   */
  if (volc_b_VCU_VehicleSubSysErrorLevel_ovrdflg) {
    /* Switch: '<S677>/Switch2' incorporates:
     *  Constant: '<S657>/volc_VCU_VehicleSubSysErrorLevel_ovrdval'
     */
    vold_VCU_VehicleSubSysErrorLevel = volc_VCU_VehicleSubSysErrorLevel_ovrdval;
  } else {
    /* Switch: '<S677>/Switch2' incorporates:
     *  Constant: '<S248>/volc_VCU_VehicleSubSysErrorLevel_dftval'
     */
    vold_VCU_VehicleSubSysErrorLevel = volc_VCU_VehicleSubSysErrorLevel_dftval;
  }

  /* End of Switch: '<S677>/Switch2' */

  /* Switch: '<S659>/Switch2' incorporates:
   *  Constant: '<S639>/volc_flg_PMS_CurrentGearPositionValid_ovrdflg'
   */
  if (volc_b_PMS_CurrentGearPositionValid_ovrdflg) {
    /* Switch: '<S659>/Switch2' incorporates:
     *  Constant: '<S639>/volc_PMS_CurrentGearPositionValid_ovrdval'
     */
    vold_PMS_CurrentGearPositionValid =
      volc_PMS_CurrentGearPositionValid_ovrdval;
  } else {
    /* Switch: '<S659>/Switch2' */
    vold_PMS_CurrentGearPositionValid = swc_VCOP_ARID_DEF.dspd_b_gearPosVld;
  }

  /* End of Switch: '<S659>/Switch2' */

  /* Switch: '<S686>/Switch2' incorporates:
   *  Constant: '<S686>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
   */
  vold_VCU_PreRelay_Ctrl = volc_VCU_PreRelay_Ctrl_ovrdval;

  /* Switch: '<S681>/Switch2' incorporates:
   *  Constant: '<S681>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg'
   *  Switch: '<S249>/Switch2'
   */
  if (volc_b_VCU_FanPWM_Ctrl_ovrdflg) {
    /* Switch: '<S681>/Switch2' incorporates:
     *  Constant: '<S681>/volc_VCU_HTCoolingFanCtrl_ovrdval'
     */
    vold_VCU_FanPWM_Ctrl = volc_VCU_FanPWM_Ctrl_ovrdval;
  } else if (thmd_b_motFanRlyReq) {
    /* Switch: '<S249>/Switch2' incorporates:
     *  Constant: '<S249>/Constant'
     *  Switch: '<S681>/Switch2'
     */
    vold_VCU_FanPWM_Ctrl = 100.0F;
  } else {
    /* Switch: '<S681>/Switch2' incorporates:
     *  Constant: '<S249>/Constant1'
     *  Switch: '<S249>/Switch2'
     */
    vold_VCU_FanPWM_Ctrl = 0.0F;
  }

  /* End of Switch: '<S681>/Switch2' */

  /* Switch: '<S682>/Switch2' incorporates:
   *  Constant: '<S682>/volc_VCU_BattCoolVal3_FBV5_ovrdval'
   */
  vold_VCU_Idle_Switch = volc_VCU_Idle_Switch_ovrdval;

  /* Switch: '<S680>/Switch2' incorporates:
   *  Constant: '<S680>/volc_b_VCU_BattHeatVal2_FBV6_ovrdflg'
   */
  if (volc_b_VCU_EV_Switch_ovrdflg) {
    /* Switch: '<S680>/Switch2' incorporates:
     *  Constant: '<S680>/volc_VCU_BattHeatVal2_FBV6_ovrdval'
     */
    vold_VCU_EV_Switch = volc_VCU_EV_Switch_ovrdval;
  } else {
    /* Switch: '<S680>/Switch2' incorporates:
     *  DataTypeConversion: '<S249>/Data Type Conversion1'
     */
    vold_VCU_EV_Switch = (uint8)swc_VCOP_ARID_DEF.DataTypeConversion220;
  }

  /* End of Switch: '<S680>/Switch2' */

  /* Switch: '<S683>/Switch2' incorporates:
   *  Constant: '<S683>/volc_VCU_BattHeatVal2_FBV5_ovrdval'
   */
  vold_VCU_InhibitHybrid_Switch = volc_VCU_InhibitHybrid_Switch_ovrdval;

  /* Switch: '<S679>/Switch2' incorporates:
   *  Constant: '<S679>/volc_VCU_CabinLoopVal1_FBV6_ovrdval'
   */
  vold_VCU_24V_Switch = volc_VCU_24V_Switch_ovrdval;

  /* Switch: '<S684>/Switch2' incorporates:
   *  Constant: '<S684>/volc_b_VCU_CabinLoopVal2_FBV5_ovrdflg'
   */
  if (volc_b_VCU_MCU_PumpPWM_Ctrl_ovrdflg) {
    /* Switch: '<S684>/Switch2' incorporates:
     *  Constant: '<S684>/volc_VCU_CabinLoopVal2_FBV5_ovrdval'
     */
    vold_VCU_MCU_PumpPWM_Ctrl = volc_VCU_MCU_PumpPWM_Ctrl_ovrdval;
  } else {
    /* DataTypeConversion: '<S249>/Data Type Conversion6' */
    rtb_Switch3_op = fmodf(truncf(swc_VCOP_ARID_DEF.DataTypeConversion122),
      256.0F);

    /* Switch: '<S684>/Switch2' incorporates:
     *  DataTypeConversion: '<S249>/Data Type Conversion6'
     *  DataTypeConversion: '<S684>/type_conv'
     */
    vold_VCU_MCU_PumpPWM_Ctrl = (float32)(rtb_Switch3_op < 0.0F ? (sint32)(uint8)
      -(sint8)(uint8)-rtb_Switch3_op : (sint32)(uint8)rtb_Switch3_op);
  }

  /* End of Switch: '<S684>/Switch2' */

  /* Switch: '<S685>/Switch2' incorporates:
   *  Constant: '<S685>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg'
   */
  if (volc_b_VCU_MCU_RelayCtrl_Ctrl_ovrdflg) {
    /* Switch: '<S685>/Switch2' incorporates:
     *  Constant: '<S685>/volc_VCU_HTCoolingFanCtrl_ovrdval'
     */
    vold_VCU_MCU_RelayCtrl_Ctrl = volc_VCU_MCU_RelayCtrl_Ctrl_ovrdval;
  } else {
    /* Switch: '<S685>/Switch2' incorporates:
     *  DataTypeConversion: '<S249>/Data Type Conversion5'
     */
    vold_VCU_MCU_RelayCtrl_Ctrl = (uint8)hvbd_b_hcmRlyEna;
  }

  /* End of Switch: '<S685>/Switch2' */

  /* Switch: '<S687>/Switch2' incorporates:
   *  Constant: '<S687>/volc_b_VCU_HTCoolingFanCtrl_ovrdflg'
   */
  if (volc_b_VCU_RelayCtrl_Ctrl_ovrdflg) {
    /* Switch: '<S687>/Switch2' incorporates:
     *  Constant: '<S687>/volc_VCU_HTCoolingFanCtrl_ovrdval'
     */
    vold_VCU_RelayCtrl_Ctrl = volc_VCU_RelayCtrl_Ctrl_ovrdval;
  } else {
    /* Switch: '<S687>/Switch2' incorporates:
     *  DataTypeConversion: '<S249>/Data Type Conversion5'
     */
    vold_VCU_RelayCtrl_Ctrl = (uint8)hvbd_b_hcmRlyEna;
  }

  /* End of Switch: '<S687>/Switch2' */

  /* Switch: '<S688>/Switch2' incorporates:
   *  Constant: '<S688>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_VehCruisingDistance_ovrdflg) {
    /* Switch: '<S688>/Switch2' incorporates:
     *  Constant: '<S688>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_VehCruisingDistance = volc_VCU_VehCruisingDistance_ovrdval;
  } else {
    /* Switch: '<S688>/Switch2' incorporates:
     *  DataTypeConversion: '<S688>/type_conv'
     */
    vold_VCU_VehCruisingDistance = (float32)
      swc_VCOP_ARID_DEF.DataTypeConversion229;
  }

  /* End of Switch: '<S688>/Switch2' */

  /* Switch: '<S710>/Switch2' incorporates:
   *  Constant: '<S697>/volc_flg_VCU_HardwareMajorVer_ovrdflg'
   */
  if (volc_b_VCU_HardwareMajorVer_ovrdflg) {
    /* Switch: '<S710>/Switch2' incorporates:
     *  Constant: '<S697>/volc_VCU_HardwareMajorVer_ovrdval'
     */
    vold_VCU_HardwareMajorVer = volc_VCU_HardwareMajorVer_ovrdval;
  } else {
    /* Switch: '<S710>/Switch2' */
    vold_VCU_HardwareMajorVer = swc_VCOP_ARID_DEF.Add8;
  }

  /* End of Switch: '<S710>/Switch2' */

  /* Switch: '<S711>/Switch2' incorporates:
   *  Constant: '<S698>/volc_flg_VCU_HardwareMinorVer_ovrdflg'
   */
  if (volc_b_VCU_HardwareMinorVer_ovrdflg) {
    /* Switch: '<S711>/Switch2' incorporates:
     *  Constant: '<S698>/volc_VCU_HardwareMinorVer_ovrdval'
     */
    vold_VCU_HardwareMinorVer = volc_VCU_HardwareMinorVer_ovrdval;
  } else {
    /* Switch: '<S711>/Switch2' */
    vold_VCU_HardwareMinorVer = swc_VCOP_ARID_DEF.Add9;
  }

  /* End of Switch: '<S711>/Switch2' */

  /* Switch: '<S715>/Switch2' incorporates:
   *  Constant: '<S702>/volc_flg_VCU_SoftwareMajorVer_ovrdflg'
   */
  if (volc_b_VCU_SoftwareMajorVer_ovrdflg) {
    /* Switch: '<S715>/Switch2' incorporates:
     *  Constant: '<S702>/volc_VCU_SoftwareMajorVer_ovrdval'
     */
    vold_VCU_SoftwareMajorVer = volc_VCU_SoftwareMajorVer_ovrdval;
  } else {
    /* Switch: '<S715>/Switch2' */
    vold_VCU_SoftwareMajorVer = swc_VCOP_ARID_DEF.Add;
  }

  /* End of Switch: '<S715>/Switch2' */

  /* Switch: '<S716>/Switch2' incorporates:
   *  Constant: '<S703>/volc_flg_VCU_SoftwareMinorVer_ovrdflg'
   */
  if (volc_b_VCU_SoftwareMinorVer_ovrdflg) {
    /* Switch: '<S716>/Switch2' incorporates:
     *  Constant: '<S703>/volc_VCU_SoftwareMinorVer_ovrdval'
     */
    vold_VCU_SoftwareMinorVer = volc_VCU_SoftwareMinorVer_ovrdval;
  } else {
    /* Switch: '<S716>/Switch2' */
    vold_VCU_SoftwareMinorVer = swc_VCOP_ARID_DEF.Add1;
  }

  /* End of Switch: '<S716>/Switch2' */

  /* Switch: '<S714>/Switch2' incorporates:
   *  Constant: '<S701>/volc_flg_VCU_SWCompileYear_ovrdflg'
   */
  if (volc_b_VCU_SWCompileYear_ovrdflg) {
    /* Switch: '<S714>/Switch2' incorporates:
     *  Constant: '<S701>/volc_VCU_SWCompileYear_ovrdval'
     */
    vold_VCU_SWCompileYear = volc_VCU_SWCompileYear_ovrdval;
  } else {
    /* Switch: '<S714>/Switch2' incorporates:
     *  Constant: '<S159>/Constant35'
     */
    vold_VCU_SWCompileYear = volc_n_SWCompileYear;
  }

  /* End of Switch: '<S714>/Switch2' */

  /* Switch: '<S713>/Switch2' incorporates:
   *  Constant: '<S700>/volc_flg_VCU_SWCompileMonth_ovrdflg'
   */
  if (volc_b_VCU_SWCompileMonth_ovrdflg) {
    /* Switch: '<S713>/Switch2' incorporates:
     *  Constant: '<S700>/volc_VCU_SWCompileMonth_ovrdval'
     */
    vold_VCU_SWCompileMonth = volc_VCU_SWCompileMonth_ovrdval;
  } else {
    /* Switch: '<S713>/Switch2' incorporates:
     *  Constant: '<S159>/Constant36'
     */
    vold_VCU_SWCompileMonth = volc_n_SWCompileMonth;
  }

  /* End of Switch: '<S713>/Switch2' */

  /* Switch: '<S712>/Switch2' incorporates:
   *  Constant: '<S699>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_SWCompileDay_ovrdflg) {
    /* Switch: '<S712>/Switch2' incorporates:
     *  Constant: '<S699>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_SWCompileDay = volc_VCU_SWCompileDay_ovrdval;
  } else {
    /* Switch: '<S712>/Switch2' incorporates:
     *  Constant: '<S159>/Constant37'
     */
    vold_VCU_SWCompileDay = volc_n_SWCompileDay;
  }

  /* End of Switch: '<S712>/Switch2' */

  /* Switch: '<S704>/Switch2' incorporates:
   *  Constant: '<S691>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_CalibrationMajorVer1_ovrdflg) {
    /* Switch: '<S704>/Switch2' incorporates:
     *  Constant: '<S691>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_CalibrationMajorVer1 = volc_VCU_CalibrationMajorVer1_ovrdval;
  } else {
    /* Switch: '<S704>/Switch2' incorporates:
     *  Constant: '<S159>/Constant5'
     */
    vold_VCU_CalibrationMajorVer1 = volc_VCU_CalibrationMajorVer1;
  }

  /* End of Switch: '<S704>/Switch2' */

  /* Switch: '<S705>/Switch2' incorporates:
   *  Constant: '<S692>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_CalibrationMajorVer2_ovrdflg) {
    /* Switch: '<S705>/Switch2' incorporates:
     *  Constant: '<S692>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_CalibrationMajorVer2 = volc_VCU_CalibrationMajorVer2_ovrdval;
  } else {
    /* Switch: '<S705>/Switch2' incorporates:
     *  Constant: '<S159>/Constant1'
     */
    vold_VCU_CalibrationMajorVer2 = volc_VCU_CalibrationMajorVer2;
  }

  /* End of Switch: '<S705>/Switch2' */

  /* Switch: '<S706>/Switch2' incorporates:
   *  Constant: '<S693>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_CalibrationMajorVer3_ovrdflg) {
    /* Switch: '<S706>/Switch2' incorporates:
     *  Constant: '<S693>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_CalibrationMajorVer3 = volc_VCU_CalibrationMajorVer3_ovrdval;
  } else {
    /* Switch: '<S706>/Switch2' incorporates:
     *  Constant: '<S159>/Constant2'
     */
    vold_VCU_CalibrationMajorVer3 = volc_VCU_CalibrationMajorVer3;
  }

  /* End of Switch: '<S706>/Switch2' */

  /* Switch: '<S707>/Switch2' incorporates:
   *  Constant: '<S694>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_CalibrationMinorVer1_ovrdflg) {
    /* Switch: '<S707>/Switch2' incorporates:
     *  Constant: '<S694>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_CalibrationMinorVer1 = volc_VCU_CalibrationMinorVer1_ovrdval;
  } else {
    /* Switch: '<S707>/Switch2' incorporates:
     *  Constant: '<S159>/Constant8'
     */
    vold_VCU_CalibrationMinorVer1 = volc_VCU_CalibrationMinorVer1;
  }

  /* End of Switch: '<S707>/Switch2' */

  /* Switch: '<S708>/Switch2' incorporates:
   *  Constant: '<S695>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_CalibrationMinorVer2_ovrdflg) {
    /* Switch: '<S708>/Switch2' incorporates:
     *  Constant: '<S695>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_CalibrationMinorVer2 = volc_VCU_CalibrationMinorVer2_ovrdval;
  } else {
    /* Switch: '<S708>/Switch2' incorporates:
     *  Constant: '<S159>/Constant3'
     */
    vold_VCU_CalibrationMinorVer2 = volc_VCU_CalibrationMinorVer2;
  }

  /* End of Switch: '<S708>/Switch2' */

  /* Switch: '<S709>/Switch2' incorporates:
   *  Constant: '<S696>/volc_flg_VCU_SWCompileDay_ovrdflg'
   */
  if (volc_b_VCU_CalibrationMinorVer3_ovrdflg) {
    /* Switch: '<S709>/Switch2' incorporates:
     *  Constant: '<S696>/volc_VCU_SWCompileDay_ovrdval'
     */
    vold_VCU_CalibrationMinorVer3 = volc_VCU_CalibrationMinorVer3_ovrdval;
  } else {
    /* Switch: '<S709>/Switch2' incorporates:
     *  Constant: '<S159>/Constant7'
     */
    vold_VCU_CalibrationMinorVer3 = volc_VCU_CalibrationMinorVer3;
  }

  /* End of Switch: '<S709>/Switch2' */

  /* Switch: '<S717>/Switch2' incorporates:
   *  Constant: '<S717>/volc_b_VCU_BattCoolVal3_FBV6_ovrdflg'
   */
  if (volc_b_VCU_ePTRegencyLevInd_ovrdflg) {
    /* Switch: '<S717>/Switch2' incorporates:
     *  Constant: '<S717>/volc_VCU_BattCoolVal3_FBV6_ovrdval'
     */
    vold_VCU_ePTRegencyLevInd = volc_VCU_ePTRegencyLevInd_ovrdval;
  } else {
    /* Switch: '<S717>/Switch2' incorporates:
     *  DataTypeConversion: '<S717>/type_conv'
     *  Inport generated from: '<Root>/vcsb_TCOO_in16'
     */
    vold_VCU_ePTRegencyLevInd =
      Rte_IRead_swc_VCOP_Step_vcsb_TCOO_dtdd_st_RegenLvlDisp();
  }

  /* End of Switch: '<S717>/Switch2' */

  /* Switch: '<S690>/Switch2' incorporates:
   *  Constant: '<S689>/volc_flg_VCU_VehicleIdentification_ovrdflg'
   */
  if (volc_b_VCU_VehicleIdentification_ovrdflg) {
    /* Switch: '<S690>/Switch2' incorporates:
     *  Constant: '<S689>/volc_VCU_VehicleIdentification_ovrdval'
     */
    vold_VCU_VehicleIdentification = volc_VCU_VehicleIdentification_ovrdval;
  } else {
    /* Switch: '<S690>/Switch2' incorporates:
     *  Constant: '<S159>/Constant38'
     */
    vold_VCU_VehicleIdentification = 0.0F;
  }

  /* End of Switch: '<S690>/Switch2' */

  /* Switch: '<S783>/Switch2' incorporates:
   *  Constant: '<S718>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg'
   */
  if (volc_b_BMSH_ACChgTimeRemain_ovrdflg) {
    /* Switch: '<S783>/Switch2' incorporates:
     *  Constant: '<S718>/volc_BMSH_ACChgTimeRemain_ovrdval'
     */
    vold_BMSH_ACChgTimeRemain = volc_BMSH_ACChgTimeRemain_ovrdval;
  } else {
    /* Switch: '<S783>/Switch2' */
    vold_BMSH_ACChgTimeRemain = swc_VCOP_ARID_DEF.SignalConversion9;
  }

  /* End of Switch: '<S783>/Switch2' */

  /* Switch: '<S784>/Switch2' incorporates:
   *  Constant: '<S719>/volc_flg_BMSH_BattCurr_ovrdflg'
   */
  if (volc_b_BMSH_BattCurr_ovrdflg) {
    /* Switch: '<S784>/Switch2' incorporates:
     *  Constant: '<S719>/volc_BMSH_BattCurr_ovrdval'
     */
    vold_BMSH_BattCurr = volc_BMSH_BattCurr_ovrdval;
  } else {
    /* Switch: '<S784>/Switch2' */
    vold_BMSH_BattCurr = swc_VCOP_ARID_DEF.SignalConversion4;
  }

  /* End of Switch: '<S784>/Switch2' */

  /* Switch: '<S785>/Switch2' incorporates:
   *  Constant: '<S720>/volc_flg_BMSH_BattFaultLampState_ovrdflg'
   */
  if (volc_b_BMSH_BattFaultLampState_ovrdflg) {
    /* Switch: '<S785>/Switch2' incorporates:
     *  Constant: '<S720>/volc_BMSH_BattFaultLampState_ovrdval'
     */
    vold_BMSH_BattFaultLampState = volc_BMSH_BattFaultLampState_ovrdval;
  } else {
    /* Switch: '<S785>/Switch2' */
    vold_BMSH_BattFaultLampState = srud_st_hvbBattFltLampSt;
  }

  /* End of Switch: '<S785>/Switch2' */

  /* Switch: '<S786>/Switch2' incorporates:
   *  Constant: '<S721>/volc_flg_BMSH_CCM_ThermalManageReq_ovrdflg'
   */
  if (volc_b_BMSH_CCM_ThermalManageReq_ovrdflg) {
    /* Switch: '<S786>/Switch2' incorporates:
     *  Constant: '<S721>/volc_BMSH_CCM_ThermalManageReq_ovrdval'
     */
    vold_BMSH_CCM_ThermalManageReq = volc_BMSH_CCM_ThermalManageReq_ovrdval;
  } else {
    /* Switch: '<S786>/Switch2' */
    vold_BMSH_CCM_ThermalManageReq = thmd_st_hvbThermMngWorkMod;
  }

  /* End of Switch: '<S786>/Switch2' */

  /* Switch: '<S787>/Switch2' incorporates:
   *  Constant: '<S722>/volc_flg_BMSH_Cell_TotalNum_ovrdflg'
   */
  if (volc_b_BMSH_Cell_TotalNum_ovrdflg) {
    /* Switch: '<S787>/Switch2' incorporates:
     *  Constant: '<S722>/volc_BMSH_Cell_TotalNum_ovrdval'
     */
    vold_BMSH_Cell_TotalNum = volc_BMSH_Cell_TotalNum_ovrdval;
  } else {
    /* Switch: '<S787>/Switch2' */
    vold_BMSH_Cell_TotalNum = swc_VCOP_ARID_DEF.SignalConversion_a;
  }

  /* End of Switch: '<S787>/Switch2' */

  /* Switch: '<S788>/Switch2' incorporates:
   *  Constant: '<S723>/volc_flg_BMSH_ChargeLEDCtrl_ovrdflg'
   */
  if (volc_b_BMSH_ChargeLEDCtrl_ovrdflg) {
    /* Switch: '<S788>/Switch2' incorporates:
     *  Constant: '<S723>/volc_BMSH_ChargeLEDCtrl_ovrdval'
     */
    vold_BMSH_ChargeLEDCtrl = volc_BMSH_ChargeLEDCtrl_ovrdval;
  } else {
    /* Switch: '<S788>/Switch2' */
    vold_BMSH_ChargeLEDCtrl = swc_VCOP_ARID_DEF.Switch9;
  }

  /* End of Switch: '<S788>/Switch2' */

  /* Switch: '<S789>/Switch2' incorporates:
   *  Constant: '<S724>/volc_flg_BMSH_Charge_Over_Current_ovrdflg'
   */
  if (volc_b_BMSH_Charge_Over_Current_ovrdflg) {
    /* Switch: '<S789>/Switch2' incorporates:
     *  Constant: '<S724>/volc_BMSH_Charge_Over_Current_ovrdval'
     */
    vold_BMSH_Charge_Over_Current = volc_BMSH_Charge_Over_Current_ovrdval;
  } else {
    /* Switch: '<S789>/Switch2' */
    vold_BMSH_Charge_Over_Current = swc_VCOP_ARID_DEF.SignalConversion5;
  }

  /* End of Switch: '<S789>/Switch2' */

  /* Switch: '<S790>/Switch2' incorporates:
   *  Constant: '<S725>/volc_flg_BMSH_ChgTimeRemain_ovrdflg'
   */
  if (volc_b_BMSH_ChgTimeRemain_ovrdflg) {
    /* Switch: '<S790>/Switch2' incorporates:
     *  Constant: '<S725>/volc_BMSH_ChgTimeRemain_ovrdval'
     */
    vold_BMSH_ChgTimeRemain = (float32)volc_BMSH_ChgTimeRemain_ovrdval;
  } else {
    /* Switch: '<S790>/Switch2' */
    vold_BMSH_ChgTimeRemain = swc_VCOP_ARID_DEF.SignalConversion9;
  }

  /* End of Switch: '<S790>/Switch2' */

  /* Switch: '<S791>/Switch2' incorporates:
   *  Constant: '<S726>/volc_flg_BMSH_DCChgminusSocketTempSensing_Failure_ovrdflg'
   */
  if (volc_b_BMSH_DCChgminusSocketTempSensing_Failure_ovrdflg) {
    /* Switch: '<S791>/Switch2' incorporates:
     *  Constant: '<S726>/volc_BMSH_DCChgminusSocketTempSensing_Failure_ovrdval'
     */
    vold_BMSH_DCChgminusSocketTempSensing_Failure =
      volc_BMSH_DCChgminusSocketTempSensing_Failure_ovrdval;
  } else {
    /* Switch: '<S791>/Switch2' */
    vold_BMSH_DCChgminusSocketTempSensing_Failure =
      swc_VCOP_ARID_DEF.SignalConversion7_m;
  }

  /* End of Switch: '<S791>/Switch2' */

  /* Switch: '<S792>/Switch2' incorporates:
   *  Constant: '<S727>/volc_flg_BMSH_DCChgplusSocketTempSensing_Failure_ovrdflg'
   */
  if (volc_b_BMSH_DCChgplusSocketTempSensing_Failure_ovrdflg) {
    /* Switch: '<S792>/Switch2' incorporates:
     *  Constant: '<S727>/volc_BMSH_DCChgplusSocketTempSensing_Failure_ovrdval'
     */
    vold_BMSH_DCChgplusSocketTempSensing_Failure =
      volc_BMSH_DCChgplusSocketTempSensing_Failure_ovrdval;
  } else {
    /* Switch: '<S792>/Switch2' */
    vold_BMSH_DCChgplusSocketTempSensing_Failure =
      swc_VCOP_ARID_DEF.SignalConversion8;
  }

  /* End of Switch: '<S792>/Switch2' */

  /* Switch: '<S793>/Switch2' incorporates:
   *  Constant: '<S728>/volc_flg_BMSH_FastChgCC2ConntState_ovrdflg'
   */
  if (volc_b_BMSH_FastChgCC2ConntState_ovrdflg) {
    /* Switch: '<S793>/Switch2' incorporates:
     *  Constant: '<S728>/volc_BMSH_FastChgCC2ConntState_ovrdval'
     */
    vold_BMSH_FastChgCC2ConntState = volc_BMSH_FastChgCC2ConntState_ovrdval;
  } else {
    /* Switch: '<S793>/Switch2' */
    vold_BMSH_FastChgCC2ConntState = swc_VCOP_ARID_DEF.Switch2_o;
  }

  /* End of Switch: '<S793>/Switch2' */

  /* Switch: '<S794>/Switch2' incorporates:
   *  Constant: '<S729>/volc_flg_BMSH_InsulationRes_Fault_ovrdflg'
   */
  if (volc_b_BMSH_InsulationRes_Fault_ovrdflg) {
    /* Switch: '<S794>/Switch2' incorporates:
     *  Constant: '<S729>/volc_BMSH_InsulationRes_Fault_ovrdval'
     */
    vold_BMSH_InsulationRes_Fault = volc_BMSH_InsulationRes_Fault_ovrdval;
  } else {
    /* Switch: '<S794>/Switch2' */
    vold_BMSH_InsulationRes_Fault = swc_VCOP_ARID_DEF.SignalConversion6_l;
  }

  /* End of Switch: '<S794>/Switch2' */

  /* Switch: '<S795>/Switch2' incorporates:
   *  Constant: '<S730>/volc_flg_BMSH_ThermalOutofControl_ovrdflg'
   */
  if (volc_b_BMSH_ThermalOutofControl_ovrdflg) {
    /* Switch: '<S795>/Switch2' incorporates:
     *  Constant: '<S730>/volc_BMSH_ThermalOutofControl_ovrdval'
     */
    vold_BMSH_ThermalOutofControl = volc_BMSH_ThermalOutofControl_ovrdval;
  } else {
    /* Switch: '<S795>/Switch2' */
    vold_BMSH_ThermalOutofControl = (swc_VCOP_ARID_DEF.Switch_a != 0);
  }

  /* End of Switch: '<S795>/Switch2' */

  /* Switch: '<S796>/Switch2' incorporates:
   *  Constant: '<S731>/volc_flg_BMSH_Vehicle_HVILSts_PHEV_ovrdflg'
   */
  if (volc_b_BMSH_Vehicle_HVILSts_PHEV_ovrdflg) {
    /* Switch: '<S796>/Switch2' incorporates:
     *  Constant: '<S731>/volc_BMSH_Vehicle_HVILSts_PHEV_ovrdval'
     */
    vold_BMSH_Vehicle_HVILSts_PHEV = volc_BMSH_Vehicle_HVILSts_PHEV_ovrdval;
  } else {
    /* Switch: '<S796>/Switch2' */
    vold_BMSH_Vehicle_HVILSts_PHEV = swc_VCOP_ARID_DEF.SignalConversion1_k;
  }

  /* End of Switch: '<S796>/Switch2' */

  /* Switch: '<S797>/Switch2' incorporates:
   *  Constant: '<S732>/volc_flg_PMS_32960FltNum_ovrdflg'
   */
  if (volc_b_PMS_32960FltNum_ovrdflg) {
    /* Switch: '<S797>/Switch2' incorporates:
     *  Constant: '<S732>/volc_PMS_32960FltNum_ovrdval'
     */
    vold_PMS_32960FltNum = volc_PMS_32960FltNum_ovrdval;
  } else {
    /* Switch: '<S797>/Switch2' */
    vold_PMS_32960FltNum = swc_VCOP_ARID_DEF.Add16;
  }

  /* End of Switch: '<S797>/Switch2' */

  /* Switch: '<S798>/Switch2' incorporates:
   *  Constant: '<S733>/volc_flg_PMS_ActualPTTorque_ovrdflg'
   */
  if (volc_b_PMS_ActualPTTorque_ovrdflg) {
    /* Switch: '<S798>/Switch2' incorporates:
     *  Constant: '<S733>/volc_PMS_ActualPTTorque_ovrdval'
     */
    vold_PMS_ActualPTTorque = volc_PMS_ActualPTTorque_ovrdval;
  } else {
    /* Switch: '<S798>/Switch2' */
    vold_PMS_ActualPTTorque = vscd_tq_axle2ActTq_Nm;
  }

  /* End of Switch: '<S798>/Switch2' */

  /* Switch: '<S809>/Switch2' incorporates:
   *  Constant: '<S744>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg'
   */
  if (volc_b_PMS_GearIntervene_ovrdflg) {
    /* Switch: '<S809>/Switch2' incorporates:
     *  Constant: '<S744>/volc_BMSH_ACChgTimeRemain_ovrdval'
     */
    vold_PMS_GearIntervene = volc_PMS_GearIntervene_ovrdval;
  } else {
    /* Switch: '<S809>/Switch2' */
    vold_PMS_GearIntervene = dspd_b_gearInvert;
  }

  /* End of Switch: '<S809>/Switch2' */

  /* Switch: '<S826>/Switch2' incorporates:
   *  Constant: '<S761>/volc_flg_PMS_RegenTrqAct_ovrdflg'
   */
  if (volc_b_PMS_RegenTrqAct_ovrdflg) {
    /* Switch: '<S826>/Switch2' incorporates:
     *  Constant: '<S761>/volc_PMS_RegenTrqAct_ovrdval'
     */
    vold_PMS_RegenTrqAct = volc_PMS_RegenTrqAct_ovrdval;
  } else {
    /* Switch: '<S826>/Switch2' */
    vold_PMS_RegenTrqAct = vscd_tq_axle2ActRgnTq_Nm;
  }

  /* End of Switch: '<S826>/Switch2' */

  /* Switch: '<S830>/Switch2' incorporates:
   *  Constant: '<S765>/volc_flg_PMS_TBOX_HVILState_ovrdflg'
   */
  if (volc_b_PMS_TBOX_HVILState_ovrdflg) {
    /* Switch: '<S830>/Switch2' incorporates:
     *  Constant: '<S765>/volc_PMS_TBOX_HVILState_ovrdval'
     */
    vold_PMS_TBOX_HVILState = volc_PMS_TBOX_HVILState_ovrdval;
  } else {
    /* Switch: '<S830>/Switch2' */
    vold_PMS_TBOX_HVILState = srud_b_hvbVehHvilSts;
  }

  /* End of Switch: '<S830>/Switch2' */

  /* Switch: '<S832>/Switch2' incorporates:
   *  Constant: '<S767>/volc_flg_BMSH_ACChgTimeRemain_ovrdflg'
   */
  if (volc_b_PMS_V2XDchaSwtFb1_ovrdflg) {
    /* Switch: '<S832>/Switch2' incorporates:
     *  Constant: '<S767>/volc_BMSH_ACChgTimeRemain_ovrdval'
     */
    vold_PMS_V2XDchaSwtFb1 = volc_PMS_V2XDchaSwtFb1_ovrdval;
  } else {
    /* Switch: '<S832>/Switch2' */
    vold_PMS_V2XDchaSwtFb1 = swc_VCOP_ARID_DEF.Switch1;
  }

  /* End of Switch: '<S832>/Switch2' */

  /* Switch: '<S833>/Switch2' incorporates:
   *  Constant: '<S768>/volc_flg_PMS_VINCode1_8_15_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode1_8_15_S_ovrdflg) {
    /* Switch: '<S833>/Switch2' incorporates:
     *  Constant: '<S768>/volc_PMS_VINCode1_8_15_S_ovrdval'
     */
    vold_PMS_VINCode1_8_15_S = volc_PMS_VINCode1_8_15_S_ovrdval;
  } else {
    /* Switch: '<S833>/Switch2' */
    vold_PMS_VINCode1_8_15_S = swc_VCOP_ARID_DEF.VINCode1;
  }

  /* End of Switch: '<S833>/Switch2' */

  /* Switch: '<S834>/Switch2' incorporates:
   *  Constant: '<S769>/volc_flg_PMS_VINCode2_9_16_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode2_9_16_S_ovrdflg) {
    /* Switch: '<S834>/Switch2' incorporates:
     *  Constant: '<S769>/volc_PMS_VINCode2_9_16_S_ovrdval'
     */
    vold_PMS_VINCode2_9_16_S = volc_PMS_VINCode2_9_16_S_ovrdval;
  } else {
    /* Switch: '<S834>/Switch2' */
    vold_PMS_VINCode2_9_16_S = swc_VCOP_ARID_DEF.VINCode2;
  }

  /* End of Switch: '<S834>/Switch2' */

  /* Switch: '<S835>/Switch2' incorporates:
   *  Constant: '<S770>/volc_flg_PMS_VINCode3_10_17_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode3_10_17_S_ovrdflg) {
    /* Switch: '<S835>/Switch2' incorporates:
     *  Constant: '<S770>/volc_PMS_VINCode3_10_17_S_ovrdval'
     */
    vold_PMS_VINCode3_10_17_S = volc_PMS_VINCode3_10_17_S_ovrdval;
  } else {
    /* Switch: '<S835>/Switch2' */
    vold_PMS_VINCode3_10_17_S = swc_VCOP_ARID_DEF.VINCode3;
  }

  /* End of Switch: '<S835>/Switch2' */

  /* Switch: '<S836>/Switch2' incorporates:
   *  Constant: '<S771>/volc_flg_PMS_VINCode4_11_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode4_11_S_ovrdflg) {
    /* Switch: '<S836>/Switch2' incorporates:
     *  Constant: '<S771>/volc_PMS_VINCode4_11_S_ovrdval'
     */
    vold_PMS_VINCode4_11_S = volc_PMS_VINCode4_11_S_ovrdval;
  } else {
    /* Switch: '<S836>/Switch2' */
    vold_PMS_VINCode4_11_S = swc_VCOP_ARID_DEF.VINCode4;
  }

  /* End of Switch: '<S836>/Switch2' */

  /* Switch: '<S837>/Switch2' incorporates:
   *  Constant: '<S772>/volc_flg_PMS_VINCode5_12_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode5_12_S_ovrdflg) {
    /* Switch: '<S837>/Switch2' incorporates:
     *  Constant: '<S772>/volc_PMS_VINCode5_12_S_ovrdval'
     */
    vold_PMS_VINCode5_12_S = volc_PMS_VINCode5_12_S_ovrdval;
  } else {
    /* Switch: '<S837>/Switch2' */
    vold_PMS_VINCode5_12_S = swc_VCOP_ARID_DEF.VINCode5;
  }

  /* End of Switch: '<S837>/Switch2' */

  /* Switch: '<S838>/Switch2' incorporates:
   *  Constant: '<S773>/volc_flg_PMS_VINCode6_13_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode6_13_S_ovrdflg) {
    /* Switch: '<S838>/Switch2' incorporates:
     *  Constant: '<S773>/volc_PMS_VINCode6_13_S_ovrdval'
     */
    vold_PMS_VINCode6_13_S = volc_PMS_VINCode6_13_S_ovrdval;
  } else {
    /* Switch: '<S838>/Switch2' */
    vold_PMS_VINCode6_13_S = swc_VCOP_ARID_DEF.VINCode6;
  }

  /* End of Switch: '<S838>/Switch2' */

  /* Switch: '<S839>/Switch2' incorporates:
   *  Constant: '<S774>/volc_flg_PMS_VINCode7_14_S_ovrdflg'
   */
  if (volc_b_PMS_VINCode7_14_S_ovrdflg) {
    /* Switch: '<S839>/Switch2' incorporates:
     *  Constant: '<S774>/volc_PMS_VINCode7_14_S_ovrdval'
     */
    vold_PMS_VINCode7_14_S = volc_PMS_VINCode7_14_S_ovrdval;
  } else {
    /* Switch: '<S839>/Switch2' */
    vold_PMS_VINCode7_14_S = swc_VCOP_ARID_DEF.VINCode7;
  }

  /* End of Switch: '<S839>/Switch2' */

  /* Switch: '<S840>/Switch2' incorporates:
   *  Constant: '<S775>/volc_flg_PMS_VINMessageNum_S_ovrdflg'
   */
  if (volc_b_PMS_VINMessageNum_S_ovrdflg) {
    /* Switch: '<S840>/Switch2' incorporates:
     *  Constant: '<S775>/volc_PMS_VINMessageNum_S_ovrdval'
     */
    vold_PMS_VINMessageNum_S = volc_PMS_VINMessageNum_S_ovrdval;
  } else {
    /* Switch: '<S840>/Switch2' */
    vold_PMS_VINMessageNum_S = swc_VCOP_ARID_DEF.VINMessageNum;
  }

  /* End of Switch: '<S840>/Switch2' */

  /* Switch: '<S843>/Switch2' incorporates:
   *  Constant: '<S778>/volc_flg_PMS_VacuumSystemsta_ovrdflg'
   */
  if (volc_b_PMS_VacuumSystemsta_ovrdflg) {
    /* Switch: '<S843>/Switch2' incorporates:
     *  Constant: '<S778>/volc_PMS_VacuumSystemsta_ovrdval'
     */
    vold_PMS_VacuumSystemsta = volc_PMS_VacuumSystemsta_ovrdval;
  } else {
    /* Switch: '<S843>/Switch2' */
    vold_PMS_VacuumSystemsta = swc_VCOP_ARID_DEF.Switch;
  }

  /* End of Switch: '<S843>/Switch2' */

  /* Switch: '<S847>/Switch2' incorporates:
   *  Constant: '<S782>/volc_flg_VCU_CrashOutputSts_ovrdflg'
   */
  if (volc_b_VCU_CrashOutputSts_ovrdflg) {
    /* Switch: '<S847>/Switch2' incorporates:
     *  Constant: '<S782>/volc_VCU_CrashOutputSts_ovrdval'
     */
    vold_VCU_CrashOutputSts = volc_VCU_CrashOutputSts_ovrdval;
  } else {
    /* Switch: '<S847>/Switch2' */
    vold_VCU_CrashOutputSts = swc_VCOP_ARID_DEF.acud_st_acuCrashOutput;
  }

  /* End of Switch: '<S847>/Switch2' */

  /* SignalConversion: '<S160>/Signal Conversion' */
  vold_BMSH_stMode = swc_VCOP_ARID_DEF.Switch6;

  /* SignalConversion: '<S160>/Signal Conversion1' */
  vold_IPU_MotorTempHighFault1 = swc_VCOP_ARID_DEF.RelationalOperator16;

  /* SignalConversion: '<S160>/Signal Conversion10' */
  vold_BMSH_TBOX_BatUnderVoltage2 = swc_VCOP_ARID_DEF.RelationalOperator25;

  /* SignalConversion: '<S160>/Signal Conversion11' */
  vold_BMSH_TBOX_BatOverTemp2 = swc_VCOP_ARID_DEF.RelationalOperator26;

  /* SignalConversion: '<S160>/Signal Conversion12' */
  vold_BMSH_TBOX_BatIsoAlarm2 = swc_VCOP_ARID_DEF.RelationalOperator27;

  /* SignalConversion: '<S160>/Signal Conversion13' */
  vold_BMSH_TBOX_BatOverVoltage2 = swc_VCOP_ARID_DEF.RelationalOperator28;

  /* SignalConversion: '<S160>/Signal Conversion14' */
  vold_BMSH_TBOX_CellOverVoltage2 = swc_VCOP_ARID_DEF.RelationalOperator29;

  /* SignalConversion: '<S160>/Signal Conversion2' */
  vold_IPU_MCUTempHighAlarm1 = swc_VCOP_ARID_DEF.RelationalOperator17;

  /* SignalConversion: '<S160>/Signal Conversion3' */
  vold_BMSH_TBOX_BatTempUniformity2 = swc_VCOP_ARID_DEF.RelationalOperator18;

  /* SignalConversion: '<S160>/Signal Conversion4' */
  vold_BMSH_TBOX_BatOverSOC2 = swc_VCOP_ARID_DEF.RelationalOperator19;

  /* SignalConversion: '<S160>/Signal Conversion5' */
  vold_BMSH_TBOX_SOCHop2 = swc_VCOP_ARID_DEF.RelationalOperator20;

  /* SignalConversion: '<S160>/Signal Conversion6' */
  vold_BMSH_TBOX_BatLowSOC2 = swc_VCOP_ARID_DEF.RelationalOperator21;

  /* SignalConversion: '<S160>/Signal Conversion7' */
  vold_BMSH_TBOX_BatOverCharge2 = swc_VCOP_ARID_DEF.RelationalOperator22;

  /* SignalConversion: '<S160>/Signal Conversion8' */
  vold_BMSH_TBOX_BatUniformity2 = swc_VCOP_ARID_DEF.RelationalOperator23;

  /* SignalConversion: '<S160>/Signal Conversion9' */
  vold_BMSH_TBOX_CellUnderVoltage2 = swc_VCOP_ARID_DEF.RelationalOperator24;

  /* Switch: '<S799>/Switch2' incorporates:
   *  Constant: '<S734>/volc_flg_PMS_ePTFault_ovrdflg'
   */
  if (volc_b_PMS_BMS_Reignstatus1_ovrdflg) {
    /* Switch: '<S799>/Switch2' incorporates:
     *  Constant: '<S734>/volc_PMS_ePTFault_ovrdval'
     */
    vold_PMS_BMS_Reignstatus1 = volc_PMS_BMS_Reignstatus1_ovrdval;
  } else {
    /* Switch: '<S799>/Switch2' */
    vold_PMS_BMS_Reignstatus1 = 0U;
  }

  /* End of Switch: '<S799>/Switch2' */

  /* Switch: '<S800>/Switch2' incorporates:
   *  Constant: '<S735>/volc_flg_PMS_ePTFault_ovrdflg'
   */
  if (volc_b_PMS_BMS_Reignstatus2_ovrdflg) {
    /* Switch: '<S800>/Switch2' incorporates:
     *  Constant: '<S735>/volc_PMS_ePTFault_ovrdval'
     */
    vold_PMS_BMS_Reignstatus2 = volc_PMS_BMS_Reignstatus2_ovrdval;
  } else {
    /* Switch: '<S800>/Switch2' */
    vold_PMS_BMS_Reignstatus2 = 0U;
  }

  /* End of Switch: '<S800>/Switch2' */

  /* Switch: '<S801>/Switch2' incorporates:
   *  Constant: '<S736>/volc_flg_PMS_Brake_LightsReques_ovrdflg'
   */
  if (volc_b_PMS_Brake_LightsRequest_ovrdflg) {
    /* Switch: '<S801>/Switch2' incorporates:
     *  Constant: '<S736>/volc_PMS_Brake_LightsRequest_ovrdval'
     */
    vold_PMS_Brake_LightsRequest = volc_PMS_Brake_LightsRequest_ovrdval;
  } else {
    /* Switch: '<S801>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn9'
     */
    vold_PMS_Brake_LightsRequest =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_b_vscBrkLghtActv();
  }

  /* End of Switch: '<S801>/Switch2' */

  /* Switch: '<S802>/Switch2' incorporates:
   *  Constant: '<S737>/volc_b_PMS_CampModeFb_ovrdflg'
   */
  if (volc_b_PMS_CampModeFb_ovrdflg) {
    /* Switch: '<S802>/Switch2' incorporates:
     *  Constant: '<S737>/volc_PMS_CampModeFb_ovrdval'
     */
    vold_PMS_CampModeFb = volc_PMS_CampModeFb_ovrdval;
  } else {
    /* Switch: '<S802>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn4'
     */
    vold_PMS_CampModeFb = Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_CampModeFb();
  }

  /* End of Switch: '<S802>/Switch2' */

  /* Switch: '<S803>/Switch2' incorporates:
   *  Constant: '<S738>/volc_b_PMS_CampModeFbFailrReason_ovrdflg'
   */
  if (volc_b_PMS_CampModeFbFailrReason_ovrdflg) {
    /* Switch: '<S803>/Switch2' incorporates:
     *  Constant: '<S738>/volc_PMS_CampModeFbFailrReason_ovrdval'
     */
    vold_PMS_CampModeFbFailrReason = volc_PMS_CampModeFbFailrReason_ovrdval;
  } else {
    /* Switch: '<S803>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn5'
     */
    vold_PMS_CampModeFbFailrReason =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_CampModeFbFailrReason();
  }

  /* End of Switch: '<S803>/Switch2' */

  /* Switch: '<S805>/Switch2' incorporates:
   *  Constant: '<S740>/volc_flg_PMS_CruisingDstSwtFb_ovrdflg'
   */
  if (volc_b_PMS_CruisingDstSwtFb_ovrdflg) {
    /* Switch: '<S805>/Switch2' incorporates:
     *  Constant: '<S740>/volc_PMS_CruisingDstSwtFb_ovrdval'
     */
    vold_PMS_CruisingDstSwtFb = volc_PMS_CruisingDstSwtFb_ovrdval;
  } else {
    /* Switch: '<S805>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HMIF_in4'
     */
    vold_PMS_CruisingDstSwtFb =
      Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_CruisingDstSwtFb();
  }

  /* End of Switch: '<S805>/Switch2' */

  /* Switch: '<S806>/Switch2' incorporates:
   *  Constant: '<S741>/volc_flg_PMS_DriverDemandTorque_ovrdflg'
   */
  if (volc_b_PMS_DriverDemandTorque_ovrdflg) {
    /* Switch: '<S806>/Switch2' incorporates:
     *  Constant: '<S741>/volc_PMS_DriverDemandTorque_ovrdval'
     */
    vold_PMS_DriverDemandTorque = volc_PMS_DriverDemandTorque_ovrdval;
  } else {
    /* Switch: '<S806>/Switch2' */
    vold_PMS_DriverDemandTorque = swc_VCOP_ARID_DEF.DataTypeConversion231;
  }

  /* End of Switch: '<S806>/Switch2' */

  /* Switch: '<S807>/Switch2' incorporates:
   *  Constant: '<S742>/volc_flg_PMS_DrvPfmncRedn_ovrdflg'
   */
  if (volc_b_PMS_DrvPfmncRed_ovrdflg) {
    /* Switch: '<S807>/Switch2' incorporates:
     *  Constant: '<S742>/volc_PMS_DrvPfmncRedn_ovrdval'
     */
    vold_PMS_DrvPfmncRedn = volc_PMS_DrvPfmncRedn_ovrdval;
  } else {
    /* Switch: '<S807>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HMIF_in15'
     */
    vold_PMS_DrvPfmncRedn =
      Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_drvPfmncRedn();
  }

  /* End of Switch: '<S807>/Switch2' */

  /* Switch: '<S808>/Switch2' incorporates:
   *  Constant: '<S743>/volc_flg_PMS_EPBClosedReq_PMS_ovrdflg'
   */
  if (volc_b_PMS_EPBClosedReq_PMS_ovrdflg) {
    /* Switch: '<S808>/Switch2' incorporates:
     *  Constant: '<S743>/volc_PMS_EPBClosedReq_PMS_ovrdval'
     */
    vold_PMS_EPBClosedReq_PMS = volc_PMS_EPBClosedReq_PMS_ovrdval;
  } else {
    /* Switch: '<S808>/Switch2' */
    vold_PMS_EPBClosedReq_PMS = swc_VCOP_ARID_DEF.DataTypeConversion239;
  }

  /* End of Switch: '<S808>/Switch2' */

  /* Switch: '<S810>/Switch2' incorporates:
   *  Constant: '<S745>/volc_flg_PMS_GrossComVehWeight_ovrdflg'
   */
  if (volc_b_PMS_GrossComVehWeight_ovrdflg) {
    /* Switch: '<S810>/Switch2' incorporates:
     *  Constant: '<S745>/volc_PMS_GrossComVehWeight_ovrdval'
     */
    vold_PMS_GrossComVehWeight = volc_PMS_GrossComVehWeight_ovrdval;
  } else {
    /* Switch: '<S810>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcib_VCIP_in203'
     */
    vold_PMS_GrossComVehWeight =
      Rte_IRead_swc_VCOP_Step_vcsb_MEST_masd_m_vehWeight_kg();
  }

  /* End of Switch: '<S810>/Switch2' */

  /* Switch: '<S811>/Switch2' incorporates:
   *  Constant: '<S746>/volc_b_PMS_IPKTotalOdometer_ovrdflg'
   */
  if (volc_b_PMS_IPKTotalOdometer_ovrdflg) {
    /* Switch: '<S811>/Switch2' incorporates:
     *  Constant: '<S746>/volc_PMS_IPKTotalOdometer_ovrdval'
     */
    vold_PMS_IPKTotalOdometer = volc_PMS_IPKTotalOdometer_ovrdval;
  } else {
    /* Switch: '<S811>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HMIF_in18'
     */
    vold_PMS_IPKTotalOdometer =
      Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_odoTotal_km();
  }

  /* End of Switch: '<S811>/Switch2' */

  /* Switch: '<S812>/Switch2' incorporates:
   *  Constant: '<S747>/volc_flg_PMS_InventorySpdLmtRxSts_ovrdflg'
   */
  if (volc_b_PMS_InventorySpdLmtRxSts_ovrdflg) {
    /* Switch: '<S812>/Switch2' incorporates:
     *  Constant: '<S747>/volc_PMS_InventorySpdLmtRxSts_ovrdval'
     */
    vold_PMS_InventorySpdLmtRxSts = volc_PMS_InventorySpdLmtRxSts_ovrdval;
  } else {
    /* Switch: '<S812>/Switch2' */
    vold_PMS_InventorySpdLmtRxSts = swc_VCOP_ARID_DEF.DataTypeConversion22;
  }

  /* End of Switch: '<S812>/Switch2' */

  /* Switch: '<S813>/Switch2' incorporates:
   *  Constant: '<S748>/volc_flg_PMS_InventorySpdLmtSts_ovrdflg'
   */
  if (volc_b_PMS_InventorySpdLmtSts_ovrdflg) {
    /* Switch: '<S813>/Switch2' incorporates:
     *  Constant: '<S748>/volc_PMS_InventorySpdLmtSts_ovrdval'
     */
    vold_PMS_InventorySpdLmtSts = volc_PMS_InventorySpdLmtSts_ovrdval;
  } else {
    /* Switch: '<S813>/Switch2' */
    vold_PMS_InventorySpdLmtSts = swc_VCOP_ARID_DEF.DataTypeConversion12;
  }

  /* End of Switch: '<S813>/Switch2' */

  /* Switch: '<S814>/Switch2' incorporates:
   *  Constant: '<S749>/volc_flg_PMS_Life_ovrdflg'
   */
  if (volc_b_PMS_Life_ovrdflg) {
    /* Switch: '<S814>/Switch2' incorporates:
     *  Constant: '<S749>/volc_PMS_Life_ovrdval'
     */
    vold_PMS_Life = volc_PMS_Life_ovrdval;
  } else {
    /* Switch: '<S814>/Switch2' */
    vold_PMS_Life = swc_VCOP_ARID_DEF.DataTypeConversion14;
  }

  /* End of Switch: '<S814>/Switch2' */

  /* Switch: '<S815>/Switch2' incorporates:
   *  Constant: '<S750>/volc_flg_PMS_LockVehPerFlag_ovrdflg'
   */
  if (volc_b_PMS_LockVehPerFlag_ovrdflg) {
    /* Switch: '<S815>/Switch2' incorporates:
     *  Constant: '<S750>/volc_PMS_LockVehPerFlag_ovrdval'
     */
    vold_PMS_LockVehPerFlag = volc_PMS_LockVehPerFlag_ovrdval;
  } else {
    /* Switch: '<S815>/Switch2' */
    vold_PMS_LockVehPerFlag = swc_VCOP_ARID_DEF.DataTypeConversion19;
  }

  /* End of Switch: '<S815>/Switch2' */

  /* Switch: '<S816>/Switch2' incorporates:
   *  Constant: '<S751>/volc_flg_PMS_LockVehPerRxSts_ovrdflg'
   */
  if (volc_b_PMS_LockVehPerRxSts_ovrdflg) {
    /* Switch: '<S816>/Switch2' incorporates:
     *  Constant: '<S751>/volc_PMS_LockVehPerRxSts_ovrdval'
     */
    vold_PMS_LockVehPerRxSts = volc_PMS_LockVehPerRxSts_ovrdval;
  } else {
    /* Switch: '<S816>/Switch2' */
    vold_PMS_LockVehPerRxSts = swc_VCOP_ARID_DEF.DataTypeConversion3;
  }

  /* End of Switch: '<S816>/Switch2' */

  /* Switch: '<S817>/Switch2' incorporates:
   *  Constant: '<S752>/volc_flg_PMS_MaxPTTorqueAllowed_ovrdflg'
   */
  if (volc_b_PMS_MaxPTTorqueAllowed_ovrdflg) {
    /* Switch: '<S817>/Switch2' incorporates:
     *  Constant: '<S752>/volc_PMS_MaxPTTorqueAllowed_ovrdval'
     */
    vold_PMS_MaxPTTorqueAllowed = volc_PMS_MaxPTTorqueAllowed_ovrdval;
  } else {
    /* Switch: '<S817>/Switch2' */
    vold_PMS_MaxPTTorqueAllowed = swc_VCOP_ARID_DEF.DataTypeConversion204;
  }

  /* End of Switch: '<S817>/Switch2' */

  /* Switch: '<S818>/Switch2' incorporates:
   *  Constant: '<S753>/volc_flg_PMS_MinPTTorqueAllowed_ovrdflg'
   */
  if (volc_b_PMS_MinPTTorqueAllowed_ovrdflg) {
    /* Switch: '<S818>/Switch2' incorporates:
     *  Constant: '<S753>/volc_PMS_MinPTTorqueAllowed_ovrdval'
     */
    vold_PMS_MinPTTorqueAllowed = volc_PMS_MinPTTorqueAllowed_ovrdval;
  } else {
    /* Switch: '<S818>/Switch2' */
    vold_PMS_MinPTTorqueAllowed = swc_VCOP_ARID_DEF.DataTypeConversion226;
  }

  /* End of Switch: '<S818>/Switch2' */

  /* Switch: '<S819>/Switch2' incorporates:
   *  Constant: '<S754>/volc_flg_PMS_OTAInstrucStsReminder_ovrdflg'
   */
  if (volc_b_PMS_OTAInstrucStsReminder_ovrdflg) {
    /* Switch: '<S819>/Switch2' incorporates:
     *  Constant: '<S754>/volc_PMS_OTAInstrucStsReminder_ovrdval'
     */
    vold_PMS_OTAInstrucStsReminder = volc_PMS_OTAInstrucStsReminder_ovrdval;
  } else {
    /* Switch: '<S819>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn18'
     */
    vold_PMS_OTAInstrucStsReminder =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo();
  }

  /* End of Switch: '<S819>/Switch2' */

  /* Switch: '<S820>/Switch2' incorporates:
   *  Constant: '<S755>/volc_flg_PMS_OTAInstructRxnSts_ovrdflg'
   */
  if (volc_b_PMS_OTAInstructRxnSts_ovrdflg) {
    /* Switch: '<S820>/Switch2' incorporates:
     *  Constant: '<S755>/volc_PMS_OTAInstructRxnSts_ovrdval'
     */
    vold_PMS_OTAInstructRxnSts = volc_PMS_OTAInstructRxnSts_ovrdval;
  } else {
    /* Switch: '<S820>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn17'
     */
    vold_PMS_OTAInstructRxnSts =
      Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts();
  }

  /* End of Switch: '<S820>/Switch2' */

  /* Switch: '<S821>/Switch2' incorporates:
   *  Constant: '<S756>/volc_flg_PMS_Odometerbackup_ovrdflg'
   */
  if (volc_b_PMS_Odometerbackup_ovrdflg) {
    /* Switch: '<S821>/Switch2' incorporates:
     *  Constant: '<S756>/volc_PMS_Odometerbackup_ovrdval'
     */
    vold_PMS_Odometerbackup = volc_PMS_Odometerbackup_ovrdval;
  } else {
    /* Switch: '<S821>/Switch2' */
    vold_PMS_Odometerbackup = swc_VCOP_ARID_DEF.DataTypeConversion266;
  }

  /* End of Switch: '<S821>/Switch2' */

  /* Switch: '<S822>/Switch2' incorporates:
   *  Constant: '<S757>/volc_b_PMS_OdometerbackupEnable_ovrdflg'
   */
  if (volc_b_PMS_OdometerbackupEnable_ovrdflg) {
    /* Switch: '<S822>/Switch2' incorporates:
     *  Constant: '<S757>/volc_PMS_OdometerbackupEnable_ovrdval'
     */
    vold_PMS_OdometerbackupEnable = volc_PMS_OdometerbackupEnable_ovrdval;
  } else {
    /* Switch: '<S822>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HMIF_in19'
     */
    vold_PMS_OdometerbackupEnable =
      Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_odoBckpEn();
  }

  /* End of Switch: '<S822>/Switch2' */

  /* Switch: '<S823>/Switch2' incorporates:
   *  Constant: '<S758>/volc_b_PMS_PowerOffCmdRxSts_ovrdflg'
   */
  if (volc_b_PMS_PowerOffCmdRxSts_ovrdflg) {
    /* Switch: '<S823>/Switch2' incorporates:
     *  Constant: '<S758>/volc_PMS_PowerOffCmdRxSts_ovrdval'
     */
    vold_PMS_PowerOffCmdRxSts = volc_PMS_PowerOffCmdRxSts_ovrdval;
  } else {
    /* Switch: '<S823>/Switch2' */
    vold_PMS_PowerOffCmdRxSts = swc_VCOP_ARID_DEF.DataTypeConversion13;
  }

  /* End of Switch: '<S823>/Switch2' */

  /* Switch: '<S824>/Switch2' incorporates:
   *  Constant: '<S759>/volc_b_PMS_PowerOffCmdSts_ovrdflg'
   */
  if (volc_b_PMS_PowerOffCmdSts_ovrdflg) {
    /* Switch: '<S824>/Switch2' incorporates:
     *  Constant: '<S759>/volc_PMS_PowerOffCmdSts_ovrdval'
     */
    vold_PMS_PowerOffCmdSts = volc_PMS_PowerOffCmdSts_ovrdval;
  } else {
    /* Switch: '<S824>/Switch2' */
    vold_PMS_PowerOffCmdSts = swc_VCOP_ARID_DEF.DataTypeConversion17;
  }

  /* End of Switch: '<S824>/Switch2' */

  /* Switch: '<S825>/Switch2' incorporates:
   *  Constant: '<S760>/volc_flg_PMS_RegenTarTrqPot_ovrdflg'
   */
  if (volc_b_PMS_RegenTarTrqPot_ovrdflg) {
    /* Switch: '<S825>/Switch2' incorporates:
     *  Constant: '<S760>/volc_PMS_RegenTarTrqPot_ovrdval'
     */
    vold_PMS_RegenTarTrqPot = volc_PMS_RegenTarTrqPot_ovrdval;
  } else {
    /* Switch: '<S825>/Switch2' */
    vold_PMS_RegenTarTrqPot = swc_VCOP_ARID_DEF.DataTypeConversion183;
  }

  /* End of Switch: '<S825>/Switch2' */

  /* Switch: '<S827>/Switch2' incorporates:
   *  Constant: '<S762>/volc_flg_PMS_RegenTrqPot_ovrdflg'
   *  Saturate: '<S160>/Saturation'
   */
  if (volc_b_PMS_RegenTrqPot_ovrdflg) {
    /* Switch: '<S827>/Switch2' incorporates:
     *  Constant: '<S762>/volc_PMS_RegenTrqPot_ovrdval'
     */
    vold_PMS_RegenTrqPot = volc_PMS_RegenTrqPot_ovrdval;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion226 > 0.0F) {
    /* Saturate: '<S160>/Saturation' incorporates:
     *  Switch: '<S827>/Switch2'
     */
    vold_PMS_RegenTrqPot = 0.0F;
  } else if (swc_VCOP_ARID_DEF.DataTypeConversion226 < (-4000.0F)) {
    /* Saturate: '<S160>/Saturation' incorporates:
     *  Switch: '<S827>/Switch2'
     */
    vold_PMS_RegenTrqPot = -4000.0F;
  } else {
    /* Switch: '<S827>/Switch2' incorporates:
     *  Saturate: '<S160>/Saturation'
     */
    vold_PMS_RegenTrqPot = swc_VCOP_ARID_DEF.DataTypeConversion226;
  }

  /* End of Switch: '<S827>/Switch2' */

  /* Switch: '<S828>/Switch2' incorporates:
   *  Constant: '<S763>/volc_flg_PMS_SpdLmtLevel_ovrdflg'
   */
  if (volc_b_PMS_SpdLmtLevel_ovrdflg) {
    /* Switch: '<S828>/Switch2' incorporates:
     *  Constant: '<S763>/volc_PMS_SpdLmtLevel_ovrdval'
     */
    vold_PMS_SpdLmtLevel = volc_PMS_SpdLmtLevel_ovrdval;
  } else {
    /* Switch: '<S828>/Switch2' */
    vold_PMS_SpdLmtLevel = swc_VCOP_ARID_DEF.DataTypeConversion2;
  }

  /* End of Switch: '<S828>/Switch2' */

  /* Switch: '<S829>/Switch2' incorporates:
   *  Constant: '<S764>/volc_flg_PMS_SpdLmtLevelRxSts_ovrdflg'
   */
  if (volc_b_PMS_SpdLmtLevelRxSts_ovrdflg) {
    /* Switch: '<S829>/Switch2' incorporates:
     *  Constant: '<S764>/volc_PMS_SpdLmtLevelRxSts_ovrdval'
     */
    vold_PMS_SpdLmtLevelRxSts = volc_PMS_SpdLmtLevelRxSts_ovrdval;
  } else {
    /* Switch: '<S829>/Switch2' */
    vold_PMS_SpdLmtLevelRxSts = swc_VCOP_ARID_DEF.DataTypeConversion21;
  }

  /* End of Switch: '<S829>/Switch2' */

  /* Switch: '<S831>/Switch2' incorporates:
   *  Constant: '<S766>/volc_flg_PMS_TBOX_LifeSts_ovrdflg'
   */
  if (volc_b_PMS_TBOX_LifeSts_ovrdflg) {
    /* Switch: '<S831>/Switch2' incorporates:
     *  Constant: '<S766>/volc_PMS_TBOX_LifeSts_ovrdval'
     */
    vold_PMS_TBOX_LifeSts = volc_PMS_TBOX_LifeSts_ovrdval;
  } else {
    /* Switch: '<S831>/Switch2' */
    vold_PMS_TBOX_LifeSts = swc_VCOP_ARID_DEF.DataTypeConversion16;
  }

  /* End of Switch: '<S831>/Switch2' */

  /* Switch: '<S841>/Switch2' incorporates:
   *  Constant: '<S776>/volc_flg_PMS_VacuumPressure_ovrdflg'
   */
  if (volc_b_PMS_VacuumPressure_ovrdflg) {
    /* Switch: '<S841>/Switch2' incorporates:
     *  Constant: '<S776>/volc_PMS_VacuumPressure_ovrdval'
     */
    vold_PMS_VacuumPressure = volc_PMS_VacuumPressure_ovrdval;
  } else {
    /* Switch: '<S841>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn7'
     */
    vold_PMS_VacuumPressure =
      Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_p_VacPumpPressure_kPa();
  }

  /* End of Switch: '<S841>/Switch2' */

  /* Switch: '<S842>/Switch2' incorporates:
   *  Constant: '<S777>/volc_b_PMS_VacuumPump_FB_ovrdflg'
   */
  if (volc_b_PMS_VacuumPump_FB_ovrdflg) {
    /* Switch: '<S842>/Switch2' incorporates:
     *  Constant: '<S777>/volc_PMS_VacuumPump_FB_ovrdval'
     */
    vold_PMS_VacuumPump_FB = volc_PMS_VacuumPump_FB_ovrdval;
  } else {
    /* Switch: '<S842>/Switch2' incorporates:
     *  Inport generated from: '<Root>/BusElementIn8'
     */
    vold_PMS_VacuumPump_FB =
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_VacTkEnFb_V();
  }

  /* End of Switch: '<S842>/Switch2' */

  /* Switch: '<S844>/Switch2' incorporates:
   *  Constant: '<S779>/volc_flg_PMS_VersionConversionFlag_ovrdflg'
   */
  if (volc_b_PMS_VersionConversionFlag_ovrdflg) {
    /* Switch: '<S844>/Switch2' incorporates:
     *  Constant: '<S779>/volc_PMS_VersionConversionFlag_ovrdval'
     */
    vold_PMS_VersionConversionFlag = volc_PMS_VersionConversionFlag_ovrdval;
  } else {
    /* Switch: '<S844>/Switch2' */
    vold_PMS_VersionConversionFlag = swc_VCOP_ARID_DEF.DataTypeConversion1;
  }

  /* End of Switch: '<S844>/Switch2' */

  /* Switch: '<S845>/Switch2' incorporates:
   *  Constant: '<S780>/volc_flg_PMS_VersionConversionRxSts_ovrdflg'
   */
  if (volc_b_PMS_VersionConversionRxSts_ovrdflg) {
    /* Switch: '<S845>/Switch2' incorporates:
     *  Constant: '<S780>/volc_PMS_VersionConversionRxSts_ovrdval'
     */
    vold_PMS_VersionConversionRxSts = volc_PMS_VersionConversionRxSts_ovrdval;
  } else {
    /* Switch: '<S845>/Switch2' */
    vold_PMS_VersionConversionRxSts = swc_VCOP_ARID_DEF.DataTypeConversion20;
  }

  /* End of Switch: '<S845>/Switch2' */

  /* Switch: '<S846>/Switch2' incorporates:
   *  Constant: '<S781>/volc_flg_PMS_ePTFault_ovrdflg'
   */
  if (volc_b_PMS_ePTFault_ovrdflg) {
    /* Switch: '<S846>/Switch2' incorporates:
     *  Constant: '<S781>/volc_PMS_ePTFault_ovrdval'
     */
    vold_PMS_ePTFault = volc_PMS_ePTFault_ovrdval;
  } else {
    /* Switch: '<S846>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_HMIF_in14'
     */
    vold_PMS_ePTFault = Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_ePTFault();
  }

  /* End of Switch: '<S846>/Switch2' */

  /* Switch: '<S804>/Switch2' incorporates:
   *  Constant: '<S739>/volc_flg_PMS_VacuumPressure_ovrdflg'
   */
  if (volc_b_PMS_ChargeLimitResponse_ovrdflg) {
    /* Switch: '<S804>/Switch2' incorporates:
     *  Constant: '<S739>/volc_PMS_VacuumPressure_ovrdval'
     */
    vold_PMS_ChargeLimitResponse = volc_PMS_ChargeLimitResponse_ovrdval;
  } else {
    /* Switch: '<S804>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_EGYM_in9'
     */
    vold_PMS_ChargeLimitResponse =
      Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_st_vcuChgLimResp();
  }

  /* End of Switch: '<S804>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S4>/PT_CAN' */
  /* Switch: '<S858>/Switch2' incorporates:
   *  Constant: '<S856>/volc_b_PMS_PTCRelayVoltSampSwich_ovrdflg'
   */
  if (volc_b_PMS_PTCRelayVoltSampSwich_ovrdflg) {
    /* Switch: '<S858>/Switch2' incorporates:
     *  Constant: '<S856>/volc_PMS_PTCRelayVoltSampSwich_ovrdval'
     */
    vold_PMS_PTCRelayVoltSampSwich = volc_PMS_PTCRelayVoltSampSwich_ovrdval;
  } else {
    /* Switch: '<S858>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vcsb_THSM_in49'
     */
    vold_PMS_PTCRelayVoltSampSwich =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch();
  }

  /* End of Switch: '<S858>/Switch2' */

  /* Switch: '<S857>/Switch2' incorporates:
   *  Constant: '<S855>/volc_b_PMS_AcceRelayVoltSampSwich_ovrdflg'
   */
  if (volc_b_PMS_AcceRelayVoltSampSwich_ovrdflg) {
    /* Switch: '<S857>/Switch2' incorporates:
     *  Constant: '<S855>/volc_PMS_AcceRelayVoltSampSwich_ovrdval'
     */
    vold_PMS_AcceRelayVoltSampSwich = volc_PMS_AcceRelayVoltSampSwich_ovrdval;
  } else {
    /* Switch: '<S857>/Switch2' */
    vold_PMS_AcceRelayVoltSampSwich = swc_VCOP_ARID_DEF.Switch_p;
  }

  /* End of Switch: '<S857>/Switch2' */

  /* Switch: '<S860>/Switch2' incorporates:
   *  Constant: '<S860>/volc_b_VCU_HVBC_COpenValue_ovrdflg'
   */
  if (volc_b_VCU_BPTCPowerRatio_ovrdflg) {
    /* Switch: '<S876>/Switch2' incorporates:
     *  Constant: '<S860>/volc_VCU_HVBC_COpenValue_ovrdval'
     */
    rtb_Switch3_op = volc_VCU_BPTCPowerRatio_ovrdval;
  } else {
    /* Switch: '<S876>/Switch2' incorporates:
     *  Constant: '<S849>/volc_VCU_BPTCPowerRatio_dftval'
     *  DataTypeConversion: '<S860>/type_conv'
     */
    rtb_Switch3_op = volc_VCU_BPTCPowerRatio_dftval;
  }

  /* End of Switch: '<S860>/Switch2' */

  /* Saturate: '<S849>/Saturation0' */
  if (rtb_Switch3_op > 100.0F) {
    /* Saturate: '<S849>/Saturation0' */
    vold_VCU_BPTCPowerRatio = 100.0F;
  } else if (rtb_Switch3_op < 0.0F) {
    /* Saturate: '<S849>/Saturation0' */
    vold_VCU_BPTCPowerRatio = 0.0F;
  } else {
    /* Saturate: '<S849>/Saturation0' */
    vold_VCU_BPTCPowerRatio = rtb_Switch3_op;
  }

  /* End of Saturate: '<S849>/Saturation0' */

  /* Switch: '<S861>/Switch2' incorporates:
   *  Constant: '<S861>/volc_b_VCU_HVBC_COpenValue_ovrdflg'
   */
  if (volc_b_VCU_BPTCTempSetting_ovrdflg) {
    /* Switch: '<S861>/Switch2' incorporates:
     *  Constant: '<S861>/volc_VCU_HVBC_COpenValue_ovrdval'
     */
    vold_VCU_BPTCTempSetting = (float32)volc_VCU_BPTCTempSetting_ovrdval;
  } else {
    /* Switch: '<S861>/Switch2' incorporates:
     *  DataTypeConversion: '<S861>/type_conv'
     */
    vold_VCU_BPTCTempSetting = thmd_t_ptcTempSetting;
  }

  /* End of Switch: '<S861>/Switch2' */

  /* Switch: '<S859>/Switch2' incorporates:
   *  Constant: '<S859>/volc_b_VCU_HVBC_Enable_invert'
   *  Constant: '<S859>/volc_b_VCU_HVBC_Enable_ovrdflg'
   *  Switch: '<S859>/Switch1'
   */
  if (volc_b_VCU_BPTCEnable_ovrdflg) {
    /* Switch: '<S859>/Switch2' incorporates:
     *  Constant: '<S859>/volc_VCU_HVBC_Enable_ovrdval'
     */
    vold_VCU_BPTCEnable = volc_VCU_BPTCEnable_ovrdval;
  } else if (volc_b_VCU_BPTCEnable_invert) {
    /* Switch: '<S859>/Switch1' incorporates:
     *  DataTypeConversion: '<S859>/type_conv'
     *  Logic: '<S859>/Logical Operator'
     *  Switch: '<S859>/Switch2'
     */
    vold_VCU_BPTCEnable = (swc_VCOP_ARID_DEF.SignalConversion1 == 0.0);
  } else {
    /* Switch: '<S859>/Switch2' incorporates:
     *  DataTypeConversion: '<S859>/type_conv'
     *  Switch: '<S859>/Switch1'
     */
    vold_VCU_BPTCEnable = (swc_VCOP_ARID_DEF.SignalConversion1 != 0.0);
  }

  /* End of Switch: '<S859>/Switch2' */

  /* Switch: '<S869>/Switch2' incorporates:
   *  Constant: '<S868>/volc_flg_VCU_ActualGear_ovrdflg'
   */
  if (volc_b_VCU_ActualGear_ovrdflg) {
    /* Switch: '<S869>/Switch2' incorporates:
     *  Constant: '<S868>/volc_VCU_ActualGear_ovrdval'
     */
    vold_VCU_ActualGear = volc_VCU_ActualGear_ovrdval;
  } else {
    /* Switch: '<S869>/Switch2' */
    vold_VCU_ActualGear = trad_st_gearLvrPos;
  }

  /* End of Switch: '<S869>/Switch2' */

  /* Switch: '<S875>/Switch2' incorporates:
   *  Constant: '<S875>/volc_b_VCU_HVBC_Enable_invert'
   *  Constant: '<S875>/volc_b_VCU_HVBC_Enable_ovrdflg'
   *  Switch: '<S875>/Switch1'
   */
  if (volc_b_VCU_EDCP_Enable_ovrdflg) {
    /* Switch: '<S875>/Switch2' incorporates:
     *  Constant: '<S875>/volc_VCU_HVBC_Enable_ovrdval'
     */
    vold_VCU_EDCP_Enable = volc_VCU_EDCP_Enable_ovrdval;
  } else if (volc_b_VCU_EDCP_Enable_invert) {
    /* Switch: '<S875>/Switch2' incorporates:
     *  DataTypeConversion: '<S875>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in26'
     *  Logic: '<S875>/Logical Operator'
     *  Switch: '<S875>/Switch1'
     */
    vold_VCU_EDCP_Enable =
      !Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled();
  } else {
    /* Switch: '<S875>/Switch2' incorporates:
     *  DataTypeConversion: '<S875>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in26'
     *  Switch: '<S875>/Switch1'
     */
    vold_VCU_EDCP_Enable =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled();
  }

  /* End of Switch: '<S875>/Switch2' */

  /* Switch: '<S876>/Switch2' incorporates:
   *  Constant: '<S876>/volc_b_VCU_HVBC_COpenValue_ovrdflg'
   */
  if (volc_b_VCU_EDCP_PWMCtrl_ovrdflg) {
    /* Switch: '<S876>/Switch2' incorporates:
     *  Constant: '<S876>/volc_VCU_HVBC_COpenValue_ovrdval'
     */
    rtb_Switch3_op = volc_VCU_EDCP_PWMCtrl_ovrdval;
  } else {
    /* Switch: '<S876>/Switch2' incorporates:
     *  DataTypeConversion: '<S876>/type_conv'
     */
    rtb_Switch3_op = swc_VCOP_ARID_DEF.DataTypeConversion122;
  }

  /* End of Switch: '<S876>/Switch2' */

  /* Saturate: '<S854>/Saturation0' */
  if (rtb_Switch3_op > 100.0F) {
    /* Saturate: '<S854>/Saturation0' */
    vold_VCU_EDCP_PWMCtrl = 100.0F;
  } else if (rtb_Switch3_op < 0.0F) {
    /* Saturate: '<S854>/Saturation0' */
    vold_VCU_EDCP_PWMCtrl = 0.0F;
  } else {
    /* Saturate: '<S854>/Saturation0' */
    vold_VCU_EDCP_PWMCtrl = rtb_Switch3_op;
  }

  /* End of Saturate: '<S854>/Saturation0' */

  /* Switch: '<S877>/Switch2' incorporates:
   *  Constant: '<S877>/volc_b_VCU_ICE_Enable_invert'
   *  Constant: '<S877>/volc_b_VCU_ICE_Enable_ovrdflg'
   *  Switch: '<S877>/Switch1'
   */
  if (volc_b_VCU_HBCP_Enable_ovrdflg) {
    /* Switch: '<S877>/Switch2' incorporates:
     *  Constant: '<S877>/volc_VCU_ICE_Enable_ovrdval'
     */
    vold_VCU_HBCP_Enable = volc_VCU_HBCP_Enable_ovrdval;
  } else if (volc_b_VCU_HBCP_Enable_invert) {
    /* Switch: '<S877>/Switch2' incorporates:
     *  DataTypeConversion: '<S877>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in27'
     *  Logic: '<S877>/Logical Operator'
     *  Switch: '<S877>/Switch1'
     */
    vold_VCU_HBCP_Enable =
      !Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled();
  } else {
    /* Switch: '<S877>/Switch2' incorporates:
     *  DataTypeConversion: '<S877>/type_conv'
     *  Inport generated from: '<Root>/vcsb_THSM_in27'
     *  Switch: '<S877>/Switch1'
     */
    vold_VCU_HBCP_Enable =
      Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled();
  }

  /* End of Switch: '<S877>/Switch2' */

  /* Switch: '<S878>/Switch2' incorporates:
   *  Constant: '<S878>/volc_b_VCU_HVBC_BOpenValue_ovrdflg'
   */
  if (volc_b_VCU_HBCP_PWMCtrl_ovrdflg) {
    /* Switch: '<S878>/Switch2' incorporates:
     *  Constant: '<S878>/volc_VCU_HVBC_BOpenValue_ovrdval'
     */
    vold_VCU_HBCP_PWMCtrl = volc_VCU_HBCP_PWMCtrl_ovrdval;
  } else {
    /* Switch: '<S878>/Switch2' incorporates:
     *  DataTypeConversion: '<S878>/type_conv'
     */
    vold_VCU_HBCP_PWMCtrl = swc_VCOP_ARID_DEF.DataTypeConversion124;
  }

  /* End of Switch: '<S878>/Switch2' */

  /* Switch: '<S873>/Switch2' incorporates:
   *  Constant: '<S871>/volc_b_VCU_DrivingTakeForceSts_ovrdflg'
   */
  if (volc_b_VCU_DrivingTakeForceSts_ovrdflg) {
    /* Switch: '<S873>/Switch2' incorporates:
     *  Constant: '<S871>/volc_VCU_DrivingTakeForceSts_ovrdval'
     */
    vold_VCU_DrivingTakeForceSts = volc_VCU_DrivingTakeForceSts_ovrdval;
  } else {
    /* Switch: '<S873>/Switch2' incorporates:
     *  Constant: '<S853>/volc_VCU_DrivingTakeForceSts_dftval'
     */
    vold_VCU_DrivingTakeForceSts = volc_VCU_DrivingTakeForceSts_dftval;
  }

  /* End of Switch: '<S873>/Switch2' */

  /* Switch: '<S874>/Switch2' incorporates:
   *  Constant: '<S872>/volc_VCU_Gearshift_Resp_ovrdval'
   */
  vold_VCU_Gearshift_Resp = volc_VCU_Gearshift_Resp_ovrdval;

  /* Switch: '<S870>/Switch2' incorporates:
   *  Constant: '<S870>/volc_b_VCU_HVBC_COpenValue_ovrdflg'
   */
  if (volc_b_VCU_Oil_HV_OFF_ovrdflg) {
    /* Switch: '<S870>/Switch2' incorporates:
     *  Constant: '<S870>/volc_VCU_HVBC_COpenValue_ovrdval'
     */
    vold_VCU_Oil_HV_OFF = volc_VCU_Oil_HV_OFF_ovrdval;
  } else {
    /* Switch: '<S870>/Switch2' incorporates:
     *  DataTypeConversion: '<S870>/type_conv'
     *  Inport generated from: '<Root>/vcib_VCIP_in102'
     */
    vold_VCU_Oil_HV_OFF = (uint8)
      Rte_IRead_swc_VCOP_Step_vcib_VCIP_cesd_b_acuCrash();
  }

  /* End of Switch: '<S870>/Switch2' */

  /* Switch: '<S867>/Switch2' incorporates:
   *  Constant: '<S864>/volc_b_VCU_VehicleWeight_ovrdflg'
   */
  if (volc_b_VCU_VehicleWeight_ovrdflg) {
    /* Switch: '<S867>/Switch2' incorporates:
     *  Constant: '<S864>/volc_w_VCU_VehicleWeight_ovrdval'
     */
    vold_VCU_VehicleWeight = volc_w_VCU_VehicleWeight_ovrdval;
  } else {
    /* Switch: '<S867>/Switch2' */
    vold_VCU_VehicleWeight = 0.0F;
  }

  /* End of Switch: '<S867>/Switch2' */

  /* Switch: '<S865>/Switch2' incorporates:
   *  Constant: '<S862>/volc_b_VCU_CalNum_ovrdflg'
   */
  if (volc_b_VCU_CalNum_ovrdflg) {
    /* Switch: '<S865>/Switch2' incorporates:
     *  Constant: '<S862>/volc_st_VCU_CalNum_ovrdval'
     */
    vold_VCU_CalNum = volc_st_VCU_CalNum_ovrdval;
  } else {
    /* Switch: '<S865>/Switch2' */
    vold_VCU_CalNum = 0U;
  }

  /* End of Switch: '<S865>/Switch2' */

  /* Switch: '<S866>/Switch2' incorporates:
   *  Constant: '<S863>/volc_b_VCU_OverloadInd_ovrdflg'
   */
  if (volc_b_VCU_OverloadInd_ovrdflg) {
    /* Switch: '<S866>/Switch2' incorporates:
     *  Constant: '<S863>/volc_st_VCU_OverloadInd_ovrdval'
     */
    vold_VCU_OverloadInd = volc_st_VCU_OverloadInd_ovrdval;
  } else {
    /* Switch: '<S866>/Switch2' */
    vold_VCU_OverloadInd = 0U;
  }

  /* End of Switch: '<S866>/Switch2' */
  /* End of Outputs for SubSystem: '<S4>/PT_CAN' */
}

/* Model step function */
void swc_VCOP_Step(void)
{
  /* local block i/o variables */
  float64 rtb_DataTypeConversion101;
  float64 rtb_DataTypeConversion144;
  float64 rtb_DataTypeConversion153;
  float64 rtb_DataTypeConversion63_p;
  float64 rtb_DataTypeConversion84;
  float64 rtb_TmpBufferAtGround3Outport1;
  float64 rtb_TmpBufferAtGroundOutport1;
  float32 rtb_DataTypeConversion175;
  float32 rtb_DataTypeConversion264;
  float32 rtb_t_delay_off_e;
  boolean rtb_DataTypeConversion240;
  boolean rtb_PMS_PreAccessoryCtrl;
  boolean rtb_DataTypeConversion_m;
  boolean rtb_flg_out_p;
  boolean rtb_DataTypeConversion_n;
  boolean rtb_flg_out_l;
  sint32 tmp_3;
  sint32 tmp_4;
  float32 rtb_DataTypeConversion138;
  float32 tmp;
  float32 tmp_0;
  float32 tmp_1;
  float32 tmp_2;
  float32 tmp_5;
  float32 tmp_6;
  float32 tmp_7;
  float32 tmp_8;
  float32 tmp_9;
  float32 tmp_a;
  float32 tmp_b;
  uint32 u0;
  uint8 Add16_tmp;
  uint8 RelationalOperator18_tmp;
  uint8 RelationalOperator19_tmp;
  uint8 RelationalOperator20_tmp;
  uint8 RelationalOperator21_tmp;
  uint8 RelationalOperator22_tmp;
  uint8 RelationalOperator23_tmp;
  uint8 RelationalOperator24_tmp;
  uint8 RelationalOperator25_tmp;
  uint8 RelationalOperator26_tmp;
  uint8 RelationalOperator28_tmp;
  uint8 RelationalOperator29_tmp;
  uint8 rtb_DataTypeConversion154;
  uint8 rtb_DataTypeConversion1_p;
  uint8 rtb_DataTypeConversion254;
  uint8 rtb_DataTypeConversion256;
  uint8 rtb_DataTypeConversion265;
  uint8 rtb_DataTypeConversion_o2;
  uint8 rtb_Switch2_mk;
  uint8 rtb_Switch_kw;
  boolean rtb_DataTypeConversion247;
  boolean rtb_DataTypeConversion248;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in21'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion1 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_versionConversion();

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in1'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion10 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion100' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in7'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion100 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_num_errorCode();

  /* DataTypeConversion: '<Root>/Data Type Conversion101' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in17'
   */
  rtb_DataTypeConversion101 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion102' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in10'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion102 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion103' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in46'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion103 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion105' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in8'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion105 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_vehDrvMode();

  /* DataTypeConversion: '<Root>/Data Type Conversion106' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion106 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_q_hvbSOC_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion107' incorporates:
   *  Inport generated from: '<Root>/vcsb_DIAG_in12'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion107 =
    Rte_IRead_swc_VCOP_Step_vcsb_DIAG_digd_st_vehSysErrLevel();

  /* DataTypeConversion: '<Root>/Data Type Conversion108' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in3'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion108 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km();

  /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion11 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion110' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in30'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion110 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_FWFVTgt_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion112' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in108'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion112 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_st_hvbThermMngReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion115' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in9'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion115 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_vcuRmr();

  /* DataTypeConversion: '<Root>/Data Type Conversion116' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in7'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion116 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsBtnErrSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion117' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in6'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion117 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion118' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in109'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion118 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbInCoolTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in24'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_inventorySpdLmtReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion120' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in110'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion120 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbOutCoolTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion121' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in14'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion121 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_tv1V3();

  /* DataTypeConversion: '<Root>/Data Type Conversion122' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in9'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion122 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_pmp2TgtSpd_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion123' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in8'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion123 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_nmSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion124' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in10'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion124 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_pmp1TgtSpd_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion125' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in111'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion125 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbSetTgtTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion128' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in10'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion128 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_num_vcuAddr();

  /* DataTypeConversion: '<Root>/Data Type Conversion129' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in4'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion129 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsCtrlSpdMode();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in3'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion13 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_pwrOffCmdRxSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion130' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in11'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion130 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_vcuAwb();

  /* DataTypeConversion: '<Root>/Data Type Conversion131' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in5'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion131 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsBtnSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion132' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in18'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion132 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_stayAwkReason();

  /* DataTypeConversion: '<Root>/Data Type Conversion133' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in19'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion133 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_vcuWkUpReason();

  /* DataTypeConversion: '<Root>/Data Type Conversion134' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion134 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_e_crsCtrlSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion135' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in3'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion135 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion138' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in112'
   */
  rtb_DataTypeConversion138 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_fact_hvbSOH_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in25'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion14 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_lifeCnt();

  /* DataTypeConversion: '<Root>/Data Type Conversion144' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in17'
   */
  rtb_DataTypeConversion144 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_essd_b_engStopReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion145' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in15'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion145 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_tv2V2();

  /* DataTypeConversion: '<Root>/Data Type Conversion151' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in14'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion151 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_ptCanModeReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion153' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in15'
   */
  rtb_DataTypeConversion153 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_st_bdCanModeReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion154' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in116'
   */
  rtb_DataTypeConversion154 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_actWorkSts1();

  /* DataTypeConversion: '<Root>/Data Type Conversion155' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in31'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion155 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ActiveCool_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion156' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in13'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion156 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_pmmd_b_pwrHoldReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion157' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in32'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion157 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_BalanceHeat_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in26'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion16 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_tboxLifeSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion161' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in33'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion161 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_PassHeat_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion162' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in49'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion162 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm();

  /* DataTypeConversion: '<Root>/Data Type Conversion163' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in50'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion163 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_tmmd_tq_motActTq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion164' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in34'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion164 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_PassCool_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion165' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in63'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion165 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion167' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in64'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion167 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion168' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in70'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion168 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_24vDcdcModAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion169' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in65'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion169 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_fan1Fb();

  /* DataTypeConversion: '<Root>/Data Type Conversion17' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in12'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion17 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_pwrOffCmd();

  /* DataTypeConversion: '<Root>/Data Type Conversion170' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in71'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion170 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbThermMngReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion171' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in66'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion171 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_WatPmpEP3FbPWM();

  /* DataTypeConversion: '<Root>/Data Type Conversion172' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in53'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion172 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_brpd_x_brkPedlPos_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion173' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in67'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion173 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_WatPmpEP1FbPWM();

  /* DataTypeConversion: '<Root>/Data Type Conversion174' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in68'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion174 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_WatPmpEP2FbPWM();

  /* DataTypeConversion: '<Root>/Data Type Conversion175' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in69'
   */
  rtb_DataTypeConversion175 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_fan2Fb();

  /* DataTypeConversion: '<Root>/Data Type Conversion176' incorporates:
   *  Inport generated from: '<Root>/vcsb_EGYM_in6'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion176 =
    Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion177' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in60'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion177 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbMin_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion178' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in56'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion178 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_x_accPedlPosSens1_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion179' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in61'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion179 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_i_hvbCurr_A();

  /* DataTypeConversion: '<Root>/Data Type Conversion18' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in13'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion18 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_macd_b_vcuSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion180' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in57'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion180 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_x_accPedlPosSens2_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion181' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in58'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion181 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_macd_u_batIntSmpl_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion182' incorporates:
   *  Inport generated from: '<Root>/vcsb_EGYM_in5'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion182 =
    Rte_IRead_swc_VCOP_Step_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion183' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in17'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion183 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion184' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in73'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion184 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbCooltOutTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion185' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in83'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion185 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_obcWakeUpActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion186' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in82'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion186 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_CCSginal();

  /* DataTypeConversion: '<Root>/Data Type Conversion187' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in84'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion187 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_DryAirSwitch();

  /* DataTypeConversion: '<Root>/Data Type Conversion188' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in90'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion188 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_Brk2_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion189' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in85'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion189 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_ResrAirSwitch();

  /* DataTypeConversion: '<Root>/Data Type Conversion19' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in20'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion19 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_lockVehPer();

  /* DataTypeConversion: '<Root>/Data Type Conversion190' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in86'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion190 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_macd_t_ts5SnsrTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion191' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in72'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion191 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbCooltInTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion192' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in87'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion192 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_emgyStopIn();

  /* DataTypeConversion: '<Root>/Data Type Conversion193' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in88'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion193 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_HVILReturnPWM();

  /* DataTypeConversion: '<Root>/Data Type Conversion194' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in89'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion194 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_GearPosn();

  /* DataTypeConversion: '<Root>/Data Type Conversion195' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in74'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion195 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_d_odometer_km();

  /* DataTypeConversion: '<Root>/Data Type Conversion196' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in80'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion196 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_driverEcoModeReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion197' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in75'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion197 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_odometerInvalid();

  /* DataTypeConversion: '<Root>/Data Type Conversion198' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in81'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion198 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_brkSwt2Actv();

  /* DataTypeConversion: '<Root>/Data Type Conversion199' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in76'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion199 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_accPdlSens2InpVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in22'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_spdLmtLevelReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion20' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in32'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion20 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_verCvsRxSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion200' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in77'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion200 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_accPdlSens1InpVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion201' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in78'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion201 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_brkSwt1Actv();

  /* DataTypeConversion: '<Root>/Data Type Conversion202' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in79'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion202 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_ignStsStrt();

  /* DataTypeConversion: '<Root>/Data Type Conversion204' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in6'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion204 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCAP_tqld_tq_whlMax_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion206' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in52'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion206 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_acpd_x_accPedlPosCan_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in34'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion21 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_spdLmtLvRxSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion212' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in98'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion212 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_TS5sensorFb_mV();

  /* DataTypeConversion: '<Root>/Data Type Conversion214' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in28'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion214 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_heaterEna();

  /* DataTypeConversion: '<Root>/Data Type Conversion215' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in103'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion215 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion218' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in91'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion218 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_Brk_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in39'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion22 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_invSpdLmtRxSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion220' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in104'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion220 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_driverEVModeReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion221' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in10'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion221 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_acc_intAccTgt_mps2();

  /* DataTypeConversion: '<Root>/Data Type Conversion222' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in8'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion222 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2();

  /* DataTypeConversion: '<Root>/Data Type Conversion223' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in19'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion223 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_b_gpOvrd();

  /* DataTypeConversion: '<Root>/Data Type Conversion224' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in11'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion224 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_b_accCtrlActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion225' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCOO_in12'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion225 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion226' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in5'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion226 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCAP_tqld_tq_whlMin_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion227' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in11'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion227 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_HazardReqLmpOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion228' incorporates:
   *  Inport generated from: '<Root>/vcsb_AUXC_in5'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion228 =
    Rte_IRead_swc_VCOP_Step_vcsb_AUXC_pscd_b_epsStopFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion229' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in12'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion229 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_vehCrsDst_km();

  /* DataTypeConversion: '<Root>/Data Type Conversion231' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in18'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion231 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tdad_tq_whlDem_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion232' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in21'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion232 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_st_gearLvrLckInd();

  /* DataTypeConversion: '<Root>/Data Type Conversion233' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in22'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion233 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_b_gearPosVld();

  /* DataTypeConversion: '<Root>/Data Type Conversion234' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in117'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion234 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion236' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in118'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion236 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_st_vscIsgActvDampModReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion237' incorporates:
   *  Inport generated from: '<Root>/vcsb_EGYM_in4'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion237 =
    Rte_IRead_swc_VCOP_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion238' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in37'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion238 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_q_pmp2FlowFeedback();

  /* DataTypeConversion: '<Root>/Data Type Conversion239' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in23'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion239 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_b_epbClsdReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion240' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in38'
   */
  rtb_DataTypeConversion240 = Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_hvbDeft();

  /* DataTypeConversion: '<Root>/Data Type Conversion241' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in39'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion241 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_iptcHtIpuResvHt();

  /* DataTypeConversion: '<Root>/Data Type Conversion242' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in40'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion242 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_iptcHtIpuCl();

  /* DataTypeConversion: '<Root>/Data Type Conversion243' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in41'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion243 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ipuResvHt();

  /* DataTypeConversion: '<Root>/Data Type Conversion244' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in42'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion244 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ipuSupHtIptcHt();

  /* DataTypeConversion: '<Root>/Data Type Conversion247' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in121'
   */
  rtb_DataTypeConversion247 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_accd_b_acHvilOpn
    ();

  /* DataTypeConversion: '<Root>/Data Type Conversion248' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in122'
   */
  rtb_DataTypeConversion248 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_dccd_b_dcdcHvilFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion250' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in43'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion250 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_ipuHeatEnableFlg();

  /* DataTypeConversion: '<Root>/Data Type Conversion251' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in44'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion251 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion254' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in126'
   */
  rtb_DataTypeConversion254 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_obcChgSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion256' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in128'
   */
  rtb_DataTypeConversion256 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbInslErr();

  /* DataTypeConversion: '<Root>/Data Type Conversion264' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in136'
   */
  rtb_DataTypeConversion264 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_brpd_p_brkVacuumPres_bar();

  /* DataTypeConversion: '<Root>/Data Type Conversion265' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in137'
   */
  rtb_DataTypeConversion265 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_dcChgCcSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion266' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in13'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion266 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in31'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_VCOP_Step_vcsb_OGVL_dtld_st_lockVehPerRxSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in1'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion4 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_b_lvCutOffReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion41' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in10'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion41 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_ptRdyInd();

  /* DataTypeConversion: '<Root>/Data Type Conversion42' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in30'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion42 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_b_ESPActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion44' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in4'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion44 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_b_fanRly1Req();

  /* DataTypeConversion: '<Root>/Data Type Conversion49' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in1'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion49 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_fan1TgtSpd_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion5 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_e_driveDirSel();

  /* DataTypeConversion: '<Root>/Data Type Conversion50' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion50 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_fan2TgtSpd_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion515' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion515 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_dccd_e_modeTgt();

  /* DataTypeConversion: '<Root>/Data Type Conversion518' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion518 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_drvModInd();

  /* DataTypeConversion: '<Root>/Data Type Conversion519' incorporates:
   *  Inport generated from: '<Root>/vcsb_DIAG_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion519 =
    Rte_IRead_swc_VCOP_Step_vcsb_DIAG_brpd_b_brkSwtMismatch();

  /* DataTypeConversion: '<Root>/Data Type Conversion52' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in27'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion52 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_epbd_e_parkingSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion524' incorporates:
   *  Inport generated from: '<Root>/vcsb_VOMM_in20'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion524 =
    Rte_IRead_swc_VCOP_Step_vcsb_VOMM_drid_e_gearLvrPos();

  /* DataTypeConversion: '<Root>/Data Type Conversion532' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in1'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion532 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion535' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in6'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion535 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_ignStsOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion537' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in7'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion537 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbTemp_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion539' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in8'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion539 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbMin_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion54' incorporates:
   *  Inport generated from: '<Root>/vcsb_AUXC_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion54 =
    Rte_IRead_swc_VCOP_Step_vcsb_AUXC_pscd_b_epsEna();

  /* DataTypeConversion: '<Root>/Data Type Conversion57' incorporates:
   *  Inport generated from: '<Root>/vcsb_SCAP_in'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion57 =
    Rte_IRead_swc_VCOP_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion58' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in28'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion58 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_st_tboxIntelChgQuit();

  /* DataTypeConversion: '<Root>/Data Type Conversion59' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in29'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion59 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbSocFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion6 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_eadd_e_inv2ModeTgt();

  /* DataTypeConversion: '<Root>/Data Type Conversion61' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in36'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion61 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_v_vehSpdRaw_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion62' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in35'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion62 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_trad_fact_trsm2GearRat();

  /* DataTypeConversion: '<Root>/Data Type Conversion63' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in37'
   */
  rtb_DataTypeConversion63_p =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_tmmd_n_motActSpd_rpm();

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in3'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion7 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion71' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in9'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion71 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion74' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in33'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion74 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_t_hvbMax_C();

  /* DataTypeConversion: '<Root>/Data Type Conversion83' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in48'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion83 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vscd_b_vehSpdVld();

  /* DataTypeConversion: '<Root>/Data Type Conversion84' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in16'
   */
  rtb_DataTypeConversion84 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion86' incorporates:
   *  Inport generated from: '<Root>/vcsb_AUXC_in4'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion86 =
    Rte_IRead_swc_VCOP_Step_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz();

  /* DataTypeConversion: '<Root>/Data Type Conversion87' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in13'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion87 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion90' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in15'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion90 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion91' incorporates:
   *  Inport generated from: '<Root>/vcsb_AUXC_in6'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion91 =
    Rte_IRead_swc_VCOP_Step_vcsb_AUXC_brpd_b_brkPmp1Rly();

  /* DataTypeConversion: '<Root>/Data Type Conversion92' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in27'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion92 =
    Rte_IRead_swc_VCOP_Step_vcsb_HVSM_bmsd_e_modeTgt();

  /* DataTypeConversion: '<Root>/Data Type Conversion93' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in107'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion93 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_dcdcRelayVolt_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion94' incorporates:
   *  Inport generated from: '<Root>/vcsb_TCOO_in2'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion94 =
    Rte_IRead_swc_VCOP_Step_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion95' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in9'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion95 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_st_drvrOptRmdr();

  /* DataTypeConversion: '<Root>/Data Type Conversion96' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in5'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion96 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km();

  /* DataTypeConversion: '<Root>/Data Type Conversion97' incorporates:
   *  Inport generated from: '<Root>/vcsb_THSM_in29'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion97 =
    Rte_IRead_swc_VCOP_Step_vcsb_THSM_thmd_n_MHGVTgt_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion98' incorporates:
   *  Inport generated from: '<Root>/vcsb_HMIF_in6'
   */
  swc_VCOP_ARID_DEF.DataTypeConversion98 =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_num_AecEV_kWhp100km();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/VCO__Vehicle_Control_Outputs'
   */
  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/HVB_OutputsProcessing'
   */
  swc_VCOP_HVB_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/DCC_OutputsProcessing'
   */
  swc_VCOP_DCC_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/EAD_OutputsProcessingMot2'
   */
  swc_V_EAD_OutputsProcessingMot2();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/VSC_OutputsProcessing'
   */
  swc_VCOP_VSC_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/TRA_OutputsProcessingTrsm1'
   */
  swc__TRA_OutputsProcessingTrsm1();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/EPB_OutputsProcessing'
   */
  swc_VCOP_EPB_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/THM_OutputsProcessing'
   */
  swc_VCOP_THM_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/DSP_OutputsProcessing'
   */
  swc_VCOP_DSP_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/PTL_OutputsProcessing'
   */
  swc_VCOP_PTL_OutputsProcessing();

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/ACU_OutputsProcessing'
   */
  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Inport generated from: '<Root>/vcib_VCIP_in102'
   */
  if (Rte_IRead_swc_VCOP_Step_vcib_VCIP_cesd_b_acuCrash()) {
    swc_VCOP_ARID_DEF.acud_st_acuCrashOutput = ((uint8)2U);
  } else {
    swc_VCOP_ARID_DEF.acud_st_acuCrashOutput = ((uint8)1U);
  }

  /* End of Switch: '<S5>/Switch' */

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/SRU_OutputsProcessing'
   */
  /* SignalConversion: '<S12>/Signal Conversion' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion245'
   *  Inport generated from: '<Root>/vcib_VCIP_in119'
   */
  swc_VCOP_ARID_DEF.SignalConversion_a = (uint8)
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbCellSum();

  /* SignalConversion: '<S12>/Signal Conversion1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion246'
   *  Inport generated from: '<Root>/vcib_VCIP_in120'
   */
  swc_VCOP_ARID_DEF.SignalConversion1_k =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_hvbHvilFlt();

  /* RelationalOperator: '<S12>/Relational Operator16' incorporates:
   *  Constant: '<S12>/Constant26'
   *  Inport generated from: '<Root>/vcib_VCIP_in194'
   *  MinMax: '<S12>/Max'
   */
  rtb_Switch_kw = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotTempHighFlt();
  swc_VCOP_ARID_DEF.RelationalOperator16 = (rtb_Switch_kw != ((uint8)0U));

  /* RelationalOperator: '<S12>/Relational Operator17' incorporates:
   *  Constant: '<S12>/Constant27'
   *  Inport generated from: '<Root>/vcib_VCIP_in196'
   *  MinMax: '<S12>/Max'
   */
  rtb_Switch2_mk = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuInvTempHighAlm();
  swc_VCOP_ARID_DEF.RelationalOperator17 = (rtb_Switch2_mk != ((uint8)0U));

  /* RelationalOperator: '<S12>/Relational Operator18' incorporates:
   *  Constant: '<S12>/Constant28'
   *  Inport generated from: '<Root>/vcib_VCIP_in176'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator18_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbCellTempDevFlt();
  swc_VCOP_ARID_DEF.RelationalOperator18 = (RelationalOperator18_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator19' incorporates:
   *  Constant: '<S12>/Constant29'
   *  Inport generated from: '<Root>/vcib_VCIP_in175'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator19_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrSoc2();
  swc_VCOP_ARID_DEF.RelationalOperator19 = (RelationalOperator19_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator20' incorporates:
   *  Constant: '<S12>/Constant30'
   *  Inport generated from: '<Root>/vcib_VCIP_in173'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator20_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbSocJumpFlt();
  swc_VCOP_ARID_DEF.RelationalOperator20 = (RelationalOperator20_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator21' incorporates:
   *  Constant: '<S12>/Constant31'
   *  Inport generated from: '<Root>/vcib_VCIP_in174'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator21_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batLowSoc2();
  swc_VCOP_ARID_DEF.RelationalOperator21 = (RelationalOperator21_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator22' incorporates:
   *  Constant: '<S12>/Constant32'
   *  Inport generated from: '<Root>/vcib_VCIP_in195'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator22_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbOvrChgFlt();
  swc_VCOP_ARID_DEF.RelationalOperator22 = (RelationalOperator22_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator23' incorporates:
   *  Constant: '<S12>/Constant33'
   *  Inport generated from: '<Root>/vcib_VCIP_in197'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator23_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbBatUniformity();
  swc_VCOP_ARID_DEF.RelationalOperator23 = (RelationalOperator23_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator24' incorporates:
   *  Constant: '<S12>/Constant34'
   *  Inport generated from: '<Root>/vcib_VCIP_in177'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator24_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellUdrVolt2();
  swc_VCOP_ARID_DEF.RelationalOperator24 = (RelationalOperator24_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator25' incorporates:
   *  Constant: '<S12>/Constant35'
   *  Inport generated from: '<Root>/vcib_VCIP_in179'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator25_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batUdrVolt2();
  swc_VCOP_ARID_DEF.RelationalOperator25 = (RelationalOperator25_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator26' incorporates:
   *  Constant: '<S12>/Constant36'
   *  Inport generated from: '<Root>/vcib_VCIP_in181'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator26_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbTempFlt();
  swc_VCOP_ARID_DEF.RelationalOperator26 = (RelationalOperator26_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator28' incorporates:
   *  Constant: '<S12>/Constant38'
   *  Inport generated from: '<Root>/vcib_VCIP_in180'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator28_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrVolt2();
  swc_VCOP_ARID_DEF.RelationalOperator28 = (RelationalOperator28_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator29' incorporates:
   *  Constant: '<S12>/Constant39'
   *  Inport generated from: '<Root>/vcib_VCIP_in178'
   *  MinMax: '<S12>/Max'
   */
  RelationalOperator29_tmp =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellOverVolt2();
  swc_VCOP_ARID_DEF.RelationalOperator29 = (RelationalOperator29_tmp != ((uint8)
    0U));

  /* RelationalOperator: '<S12>/Relational Operator27' incorporates:
   *  Constant: '<S12>/Constant37'
   */
  swc_VCOP_ARID_DEF.RelationalOperator27 = (rtb_DataTypeConversion256 != ((uint8)
    0U));

  /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in192'
   */
  rtb_DataTypeConversion_o2 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcTempAlm();

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in193'
   */
  rtb_DataTypeConversion1_p =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcStsAlm();

  /* SignalConversion: '<S12>/Signal Conversion12' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in4'
   */
  srud_b_hvbVehHvilSts = Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_b_hvilOpen();

  /* RelationalOperator: '<S12>/Relational Operator30' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in10'
   *  MinMax: '<S12>/Max'
   */
  Add16_tmp = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ehbBrkSysErrFlt();

  /* Sum: '<S12>/Add16' incorporates:
   *  Constant: '<S12>/Constant25'
   *  Constant: '<S12>/Constant3'
   *  Constant: '<S12>/Constant52'
   *  Constant: '<S12>/Constant53'
   *  DataTypeConversion: '<S12>/Data Type Conversion3'
   *  Inport generated from: '<Root>/vcib_VCIP_in10'
   *  RelationalOperator: '<S12>/Relational Operator1'
   *  RelationalOperator: '<S12>/Relational Operator15'
   *  RelationalOperator: '<S12>/Relational Operator30'
   *  RelationalOperator: '<S12>/Relational Operator31'
   */
  swc_VCOP_ARID_DEF.Add16 = (uint8)((((((((((((uint32)(uint8)(((((((((((uint32)
    swc_VCOP_ARID_DEF.RelationalOperator16 +
    swc_VCOP_ARID_DEF.RelationalOperator17) +
    swc_VCOP_ARID_DEF.RelationalOperator18) +
    swc_VCOP_ARID_DEF.RelationalOperator19) +
    swc_VCOP_ARID_DEF.RelationalOperator20) +
    swc_VCOP_ARID_DEF.RelationalOperator21) +
    swc_VCOP_ARID_DEF.RelationalOperator22) +
    swc_VCOP_ARID_DEF.RelationalOperator23) +
    swc_VCOP_ARID_DEF.RelationalOperator24) +
    swc_VCOP_ARID_DEF.RelationalOperator25) +
    swc_VCOP_ARID_DEF.RelationalOperator26) +
    swc_VCOP_ARID_DEF.RelationalOperator28) +
    swc_VCOP_ARID_DEF.RelationalOperator29) +
    swc_VCOP_ARID_DEF.RelationalOperator27) + (uint32)(rtb_DataTypeConversion_o2
    != ((uint8)0U))) + (uint32)(rtb_DataTypeConversion1_p != ((uint8)0U))) +
    (uint32)(Add16_tmp != ((uint8)0U))) + (uint32)(srud_b_hvbVehHvilSts !=
    ((uint8)0U))) + swc_VCOP_ConstB.RelationalOperator32) +
    swc_VCOP_ConstB.RelationalOperator33) + swc_VCOP_ConstB.RelationalOperator34)
    + swc_VCOP_ConstB.RelationalOperator35);

  /* MinMax: '<S12>/Max' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion3'
   */
  if (rtb_Switch_kw >= rtb_Switch2_mk) {
    rtb_Switch2_mk = rtb_Switch_kw;
  }

  if (rtb_Switch2_mk >= RelationalOperator18_tmp) {
    RelationalOperator18_tmp = rtb_Switch2_mk;
  }

  if (RelationalOperator18_tmp >= RelationalOperator19_tmp) {
    RelationalOperator19_tmp = RelationalOperator18_tmp;
  }

  if (RelationalOperator19_tmp >= RelationalOperator20_tmp) {
    RelationalOperator20_tmp = RelationalOperator19_tmp;
  }

  if (RelationalOperator20_tmp >= RelationalOperator21_tmp) {
    RelationalOperator21_tmp = RelationalOperator20_tmp;
  }

  if (RelationalOperator21_tmp >= RelationalOperator22_tmp) {
    RelationalOperator22_tmp = RelationalOperator21_tmp;
  }

  if (RelationalOperator22_tmp >= RelationalOperator23_tmp) {
    RelationalOperator23_tmp = RelationalOperator22_tmp;
  }

  if (RelationalOperator23_tmp >= RelationalOperator24_tmp) {
    RelationalOperator24_tmp = RelationalOperator23_tmp;
  }

  if (RelationalOperator24_tmp >= RelationalOperator25_tmp) {
    RelationalOperator25_tmp = RelationalOperator24_tmp;
  }

  if (RelationalOperator25_tmp >= RelationalOperator26_tmp) {
    RelationalOperator26_tmp = RelationalOperator25_tmp;
  }

  if (RelationalOperator26_tmp >= RelationalOperator28_tmp) {
    RelationalOperator28_tmp = RelationalOperator26_tmp;
  }

  if (RelationalOperator28_tmp >= RelationalOperator29_tmp) {
    RelationalOperator29_tmp = RelationalOperator28_tmp;
  }

  if (RelationalOperator29_tmp < rtb_DataTypeConversion256) {
    RelationalOperator29_tmp = rtb_DataTypeConversion256;
  }

  if (RelationalOperator29_tmp < rtb_DataTypeConversion_o2) {
    RelationalOperator29_tmp = 1U;
  }

  if (RelationalOperator29_tmp < rtb_DataTypeConversion1_p) {
    RelationalOperator29_tmp = 1U;
  }

  if (RelationalOperator29_tmp >= Add16_tmp) {
    Add16_tmp = RelationalOperator29_tmp;
  }

  if (Add16_tmp >= (sint32)srud_b_hvbVehHvilSts) {
    swc_VCOP_ARID_DEF.Max = Add16_tmp;
  } else {
    swc_VCOP_ARID_DEF.Max = 1U;
  }

  /* Logic: '<S12>/Logical Operator1' */
  srud_b_hvbPmsHvilSts = (rtb_DataTypeConversion247 || rtb_DataTypeConversion248);

  /* SignalConversion: '<S12>/Signal Conversion2' */
  swc_VCOP_ARID_DEF.SignalConversion2 = rtb_DataTypeConversion247;

  /* SignalConversion: '<S12>/Signal Conversion3' */
  swc_VCOP_ARID_DEF.SignalConversion3 = rtb_DataTypeConversion248;

  /* SignalConversion: '<S12>/Signal Conversion4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion249'
   *  Inport generated from: '<Root>/vcib_VCIP_in123'
   */
  swc_VCOP_ARID_DEF.SignalConversion4 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_i_hvbCurr_A();

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant2'
   *  DataTypeConversion: '<Root>/Data Type Conversion252'
   *  Inport generated from: '<Root>/vcib_VCIP_in124'
   *  RelationalOperator: '<S12>/Relational Operator'
   */
  if (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt() == ((uint8)
       1U)) {
    swc_VCOP_ARID_DEF.Switch_a = ((uint8)1U);
  } else {
    swc_VCOP_ARID_DEF.Switch_a = ((uint8)0U);
  }

  /* End of Switch: '<S12>/Switch' */

  /* Switch: '<S77>/Switch' incorporates:
   *  Constant: '<S77>/Constant12'
   *  Constant: '<S77>/Constant3'
   *  Logic: '<S77>/Logical Operator3'
   *  RelationalOperator: '<S77>/Relational Operator1'
   *  RelationalOperator: '<S77>/Relational Operator8'
   */
  if ((rtb_DataTypeConversion265 == ((uint8)1U)) || (rtb_DataTypeConversion265 ==
       ((uint8)3U))) {
    /* Switch: '<S77>/Switch' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion253'
     *  Inport generated from: '<Root>/vcib_VCIP_in125'
     */
    rtb_Switch_kw = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbDCChgProcss();
  } else {
    /* Switch: '<S77>/Switch' incorporates:
     *  Constant: '<S77>/Constant4'
     */
    rtb_Switch_kw = ((uint8)0U);
  }

  /* End of Switch: '<S77>/Switch' */

  /* RelationalOperator: '<S77>/Relational Operator2' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in185'
   *  RelationalOperator: '<S77>/Relational Operator18'
   *  RelationalOperator: '<S77>/Relational Operator20'
   *  Switch: '<S77>/Switch8'
   */
  tmp_3 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_obcOnBdCCline();

  /* Switch: '<S77>/Switch2' incorporates:
   *  Constant: '<S77>/Constant31'
   *  Constant: '<S77>/Constant5'
   *  Constant: '<S77>/Constant7'
   *  Logic: '<S77>/Logical Operator1'
   *  Logic: '<S77>/Logical Operator7'
   *  RelationalOperator: '<S77>/Relational Operator18'
   *  RelationalOperator: '<S77>/Relational Operator2'
   *  RelationalOperator: '<S77>/Relational Operator3'
   */
  if (((tmp_3 == ((uint8)1U)) || (tmp_3 == ((uint8)2U))) &&
      (rtb_DataTypeConversion265 != ((uint8)1U))) {
    /* Switch: '<S77>/Switch2' */
    rtb_Switch2_mk = rtb_DataTypeConversion254;
  } else {
    /* Switch: '<S77>/Switch2' incorporates:
     *  Constant: '<S77>/Constant6'
     */
    rtb_Switch2_mk = ((uint8)0U);
  }

  /* End of Switch: '<S77>/Switch2' */

  /* Switch: '<S12>/Switch2' incorporates:
   *  Constant: '<S12>/Constant12'
   *  Constant: '<S12>/Constant13'
   *  Constant: '<S12>/Constant14'
   *  Constant: '<S12>/Constant15'
   *  Constant: '<S12>/Constant17'
   *  Logic: '<S12>/Logical Operator5'
   *  RelationalOperator: '<S12>/Relational Operator10'
   *  RelationalOperator: '<S12>/Relational Operator8'
   *  RelationalOperator: '<S12>/Relational Operator9'
   *  Switch: '<S12>/Switch3'
   */
  if (rtb_DataTypeConversion265 == ((uint8)3U)) {
    swc_VCOP_ARID_DEF.Switch2_o = ((uint8)2U);
  } else if ((rtb_DataTypeConversion265 == ((uint8)1U)) ||
             (rtb_DataTypeConversion265 == ((uint8)2U))) {
    /* Switch: '<S12>/Switch3' incorporates:
     *  Constant: '<S12>/Constant16'
     */
    swc_VCOP_ARID_DEF.Switch2_o = ((uint8)1U);
  } else {
    swc_VCOP_ARID_DEF.Switch2_o = ((uint8)0U);
  }

  /* End of Switch: '<S12>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S77>/turnOFF_delay' */
  /* DataTypeConversion: '<S79>/Data Type Conversion' incorporates:
   *  Constant: '<S77>/Constant26'
   *  Inport generated from: '<Root>/vcib_VCIP_in186'
   *  RelationalOperator: '<S77>/Relational Operator15'
   */
  rtb_DataTypeConversion_n =
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_tboxRsrChgSt() == ((uint8)2U));

  /* Saturate: '<S79>/Saturation1' incorporates:
   *  Constant: '<S77>/Constant28'
   */
  if (volc_tm_dlyForRsrChgSt_s > 1.6777216E+7F) {
    /* Saturate: '<S79>/Saturation1' */
    rtb_t_delay_off_e = 1.6777216E+7F;
  } else if (volc_tm_dlyForRsrChgSt_s < 0.0F) {
    /* Saturate: '<S79>/Saturation1' */
    rtb_t_delay_off_e = 0.0F;
  } else {
    /* Saturate: '<S79>/Saturation1' */
    rtb_t_delay_off_e = volc_tm_dlyForRsrChgSt_s;
  }

  /* End of Saturate: '<S79>/Saturation1' */

  /* Chart: '<S79>/timed_delay' incorporates:
   *  Constant: '<S77>/Constant27'
   */
  swc_VCOP_timed_delay(rtb_DataTypeConversion_n, rtb_t_delay_off_e, ((float32)
    VOL_TASK_INTERVAL_S), &rtb_flg_out_l,
                       &swc_VCOP_ARID_DEF.ARID_DEF_timed_delay_m);

  /* End of Outputs for SubSystem: '<S77>/turnOFF_delay' */

  /* Switch: '<S77>/Switch8' incorporates:
   *  Constant: '<S77>/Constant13'
   *  Constant: '<S77>/Constant14'
   *  Constant: '<S77>/Constant15'
   *  Constant: '<S77>/Constant16'
   *  Constant: '<S77>/Constant17'
   *  Constant: '<S77>/Constant19'
   *  Constant: '<S77>/Constant22'
   *  Constant: '<S77>/Constant23'
   *  Constant: '<S77>/Constant24'
   *  Constant: '<S77>/Constant25'
   *  Constant: '<S77>/Constant36'
   *  Logic: '<S77>/Logical Operator2'
   *  Logic: '<S77>/Logical Operator4'
   *  Logic: '<S77>/Logical Operator5'
   *  Logic: '<S77>/Logical Operator6'
   *  RelationalOperator: '<S77>/Relational Operator10'
   *  RelationalOperator: '<S77>/Relational Operator11'
   *  RelationalOperator: '<S77>/Relational Operator12'
   *  RelationalOperator: '<S77>/Relational Operator13'
   *  RelationalOperator: '<S77>/Relational Operator14'
   *  RelationalOperator: '<S77>/Relational Operator16'
   *  RelationalOperator: '<S77>/Relational Operator20'
   *  RelationalOperator: '<S77>/Relational Operator5'
   *  RelationalOperator: '<S77>/Relational Operator6'
   *  RelationalOperator: '<S77>/Relational Operator7'
   *  RelationalOperator: '<S77>/Relational Operator9'
   *  Switch: '<S77>/Switch3'
   *  Switch: '<S77>/Switch4'
   *  Switch: '<S77>/Switch5'
   *  Switch: '<S77>/Switch7'
   */
  if ((rtb_Switch_kw == ((uint8)2U)) || (rtb_Switch2_mk == ((uint8)4U)) ||
      (rtb_Switch2_mk == ((uint8)9U)) || (rtb_Switch2_mk == ((uint8)14U))) {
    /* Switch: '<S77>/Switch8' incorporates:
     *  Constant: '<S77>/Constant20'
     */
    rtb_DataTypeConversion265 = ((uint8)1U);
  } else if (((tmp_3 == ((uint8)1U)) && (swc_VCOP_ARID_DEF.Switch2_o != ((uint8)
                1U)) && rtb_flg_out_l) || (rtb_Switch2_mk == ((uint8)8U))) {
    /* Switch: '<S77>/Switch4' incorporates:
     *  Constant: '<S77>/Constant10'
     *  Switch: '<S77>/Switch8'
     */
    rtb_DataTypeConversion265 = ((uint8)6U);
  } else if ((rtb_Switch2_mk == ((uint8)11U)) || (rtb_Switch_kw == ((uint8)3U)))
  {
    /* Switch: '<S77>/Switch7' incorporates:
     *  Constant: '<S77>/Constant18'
     *  Switch: '<S77>/Switch4'
     *  Switch: '<S77>/Switch8'
     */
    rtb_DataTypeConversion265 = ((uint8)2U);
  } else if (rtb_Switch2_mk == ((uint8)10U)) {
    /* Switch: '<S77>/Switch3' incorporates:
     *  Constant: '<S77>/Constant9'
     *  Switch: '<S77>/Switch4'
     *  Switch: '<S77>/Switch7'
     *  Switch: '<S77>/Switch8'
     */
    rtb_DataTypeConversion265 = ((uint8)5U);
  } else if (rtb_Switch2_mk == ((uint8)5U)) {
    /* Switch: '<S77>/Switch5' incorporates:
     *  Constant: '<S77>/Constant11'
     *  Switch: '<S77>/Switch3'
     *  Switch: '<S77>/Switch4'
     *  Switch: '<S77>/Switch7'
     *  Switch: '<S77>/Switch8'
     */
    rtb_DataTypeConversion265 = ((uint8)7U);
  } else {
    /* Switch: '<S77>/Switch8' incorporates:
     *  Constant: '<S77>/Constant21'
     *  Switch: '<S77>/Switch3'
     *  Switch: '<S77>/Switch4'
     *  Switch: '<S77>/Switch5'
     *  Switch: '<S77>/Switch7'
     */
    rtb_DataTypeConversion265 = ((uint8)0U);
  }

  /* Switch: '<S77>/Switch1' incorporates:
   *  Constant: '<S77>/Constant1'
   *  Constant: '<S77>/Constant2'
   *  Constant: '<S77>/Constant8'
   *  RelationalOperator: '<S77>/Relational Operator4'
   */
  if (rtb_DataTypeConversion254 == ((uint8)5U)) {
    swc_VCOP_ARID_DEF.Switch1 = ((uint8)2U);
  } else {
    swc_VCOP_ARID_DEF.Switch1 = ((uint8)0U);
  }

  /* End of Switch: '<S77>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S77>/turnOFF_delay1' */
  /* DataTypeConversion: '<S80>/Data Type Conversion' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S77>/Constant32'
   *  Logic: '<S77>/Logical Operator'
   *  RelationalOperator: '<S77>/Relational Operator'
   *  RelationalOperator: '<S77>/Relational Operator19'
   *  UnitDelay: '<S77>/Unit Delay'
   */
  rtb_DataTypeConversion_m = ((rtb_DataTypeConversion265 == ((uint8)6U)) &&
    (swc_VCOP_ARID_DEF.UnitDelay_DSTATE_h == ((uint8)1U)));

  /* Chart: '<S80>/timed_delay' incorporates:
   *  Constant: '<S77>/Constant34'
   */
  swc_VCOP_timed_delay(rtb_DataTypeConversion_m, swc_VCOP_ConstB.t_delay_off,
                       0.01F, &rtb_flg_out_p,
                       &swc_VCOP_ARID_DEF.ARID_DEF_timed_delay);

  /* End of Outputs for SubSystem: '<S77>/turnOFF_delay1' */

  /* Switch: '<S77>/Switch9' incorporates:
   *  Constant: '<S77>/Constant35'
   */
  if (rtb_flg_out_p) {
    swc_VCOP_ARID_DEF.Switch9 = ((uint8)2U);
  } else {
    swc_VCOP_ARID_DEF.Switch9 = rtb_DataTypeConversion265;
  }

  /* End of Switch: '<S77>/Switch9' */

  /* SignalConversion: '<S12>/Signal Conversion5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion255'
   *  Inport generated from: '<Root>/vcib_VCIP_in127'
   */
  swc_VCOP_ARID_DEF.SignalConversion5 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbChgOvrCurr();

  /* SignalConversion: '<S12>/Signal Conversion6' incorporates:
   *  Inport generated from: '<Root>/BusElementIn'
   */
  swc_VCOP_ARID_DEF.SignalConversion6_l =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbBattIsolationSts();

  /* SignalConversion: '<S12>/Signal Conversion7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion257'
   *  Inport generated from: '<Root>/vcib_VCIP_in129'
   */
  swc_VCOP_ARID_DEF.SignalConversion7_m =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp();

  /* SignalConversion: '<S12>/Signal Conversion8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion258'
   *  Inport generated from: '<Root>/vcib_VCIP_in130'
   */
  swc_VCOP_ARID_DEF.SignalConversion8 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp();

  /* SignalConversion: '<S12>/Signal Conversion9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion259'
   *  Inport generated from: '<Root>/vcib_VCIP_in131'
   */
  swc_VCOP_ARID_DEF.SignalConversion9 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_tm_hvbFnshChgTim_m();

  /* SignalConversion: '<S12>/Signal Conversion13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion520'
   *  Inport generated from: '<Root>/vcsb_HMIF_in1'
   */
  swc_VCOP_ARID_DEF.srud_st_turtleLmpReq =
    Rte_IRead_swc_VCOP_Step_vcsb_HMIF_dspd_b_turtleLmpOn();

  /* RelationalOperator: '<S12>/Relational Operator6' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in142'
   *  RelationalOperator: '<S12>/Relational Operator4'
   *  RelationalOperator: '<S12>/Relational Operator7'
   */
  tmp_3 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbStsDischgFlt();

  /* RelationalOperator: '<S12>/Relational Operator5' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in191'
   *  RelationalOperator: '<S12>/Relational Operator2'
   *  RelationalOperator: '<S12>/Relational Operator3'
   */
  tmp_4 = Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbStsChgFlt();

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant10'
   *  Constant: '<S12>/Constant11'
   *  Constant: '<S12>/Constant4'
   *  Constant: '<S12>/Constant5'
   *  Constant: '<S12>/Constant6'
   *  Constant: '<S12>/Constant7'
   *  Constant: '<S12>/Constant8'
   *  Constant: '<S12>/Constant9'
   *  Logic: '<S12>/Logical Operator2'
   *  Logic: '<S12>/Logical Operator3'
   *  Logic: '<S12>/Logical Operator4'
   *  RelationalOperator: '<S12>/Relational Operator2'
   *  RelationalOperator: '<S12>/Relational Operator3'
   *  RelationalOperator: '<S12>/Relational Operator4'
   *  RelationalOperator: '<S12>/Relational Operator5'
   *  RelationalOperator: '<S12>/Relational Operator6'
   *  RelationalOperator: '<S12>/Relational Operator7'
   */
  if ((tmp_3 == ((uint8)3U)) || (tmp_3 == ((uint8)4U)) || (tmp_3 == ((uint8)5U))
      || ((tmp_4 == ((uint8)3U)) || (tmp_4 == ((uint8)4U)) || (tmp_4 == ((uint8)
         5U)))) {
    srud_st_hvbBattFltLampSt = ((uint8)1U);
  } else {
    srud_st_hvbBattFltLampSt = ((uint8)0U);
  }

  /* End of Switch: '<S12>/Switch1' */

  /* SignalConversion: '<S12>/Signal Conversion10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion262'
   *  Inport generated from: '<Root>/vcib_VCIP_in134'
   */
  swc_VCOP_ARID_DEF.SignalConversion10 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_t_hvbAvg_C();

  /* SignalConversion: '<S12>/Signal Conversion11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion263'
   *  Inport generated from: '<Root>/vcib_VCIP_in135'
   */
  swc_VCOP_ARID_DEF.SignalConversion11 =
    Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_hvbPackVolt_V();

  /* Switch: '<S12>/Switch4' incorporates:
   *  Constant: '<S12>/Constant20'
   */
  if (swc_VCOP_ConstB.LogicalOperator6) {
    swc_VCOP_ARID_DEF.Switch4 = ((uint8)3U);
  } else {
    swc_VCOP_ARID_DEF.Switch4 = swc_VCOP_ConstB.Switch5;
  }

  /* End of Switch: '<S12>/Switch4' */

  /* Switch: '<S76>/Switch6' incorporates:
   *  Constant: '<S76>/Constant1'
   *  Constant: '<S76>/Constant11'
   *  Constant: '<S76>/Constant13'
   *  Constant: '<S76>/Constant15'
   *  Constant: '<S76>/Constant17'
   *  Constant: '<S76>/Constant25'
   *  Constant: '<S76>/Constant26'
   *  Constant: '<S76>/Constant3'
   *  Constant: '<S76>/Constant5'
   *  Constant: '<S76>/Constant7'
   *  Constant: '<S76>/Constant9'
   *  RelationalOperator: '<S76>/Relational Operator1'
   *  RelationalOperator: '<S76>/Relational Operator15'
   *  RelationalOperator: '<S76>/Relational Operator2'
   *  RelationalOperator: '<S76>/Relational Operator3'
   *  RelationalOperator: '<S76>/Relational Operator4'
   *  RelationalOperator: '<S76>/Relational Operator5'
   *  RelationalOperator: '<S76>/Relational Operator6'
   *  RelationalOperator: '<S76>/Relational Operator7'
   *  RelationalOperator: '<S76>/Relational Operator8'
   *  RelationalOperator: '<S76>/Relational Operator9'
   *  Switch: '<S76>/Switch1'
   *  Switch: '<S76>/Switch10'
   *  Switch: '<S76>/Switch2'
   *  Switch: '<S76>/Switch3'
   *  Switch: '<S76>/Switch4'
   *  Switch: '<S76>/Switch5'
   *  Switch: '<S76>/Switch7'
   *  Switch: '<S76>/Switch8'
   *  Switch: '<S76>/Switch9'
   */
  if (rtb_DataTypeConversion154 == ((uint8)11U)) {
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)15U);
  } else if (rtb_DataTypeConversion154 == ((uint8)12U)) {
    /* Switch: '<S76>/Switch7' incorporates:
     *  Constant: '<S76>/Constant28'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)13U);
  } else if (rtb_DataTypeConversion154 == ((uint8)13U)) {
    /* Switch: '<S76>/Switch1' incorporates:
     *  Constant: '<S76>/Constant2'
     *  Switch: '<S76>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)12U);
  } else if (rtb_DataTypeConversion154 == ((uint8)9U)) {
    /* Switch: '<S76>/Switch2' incorporates:
     *  Constant: '<S76>/Constant4'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)10U);
  } else if (rtb_DataTypeConversion154 == ((uint8)14U)) {
    /* Switch: '<S76>/Switch3' incorporates:
     *  Constant: '<S76>/Constant6'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)9U);
  } else if (rtb_DataTypeConversion154 == ((uint8)5U)) {
    /* Switch: '<S76>/Switch4' incorporates:
     *  Constant: '<S76>/Constant8'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch3'
     *  Switch: '<S76>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)7U);
  } else if (rtb_DataTypeConversion154 == ((uint8)8U)) {
    /* Switch: '<S76>/Switch5' incorporates:
     *  Constant: '<S76>/Constant10'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch3'
     *  Switch: '<S76>/Switch4'
     *  Switch: '<S76>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)5U);
  } else if (rtb_DataTypeConversion154 == ((uint8)3U)) {
    /* Switch: '<S76>/Switch8' incorporates:
     *  Constant: '<S76>/Constant12'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch3'
     *  Switch: '<S76>/Switch4'
     *  Switch: '<S76>/Switch5'
     *  Switch: '<S76>/Switch7'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)3U);
  } else if (rtb_DataTypeConversion154 == ((uint8)2U)) {
    /* Switch: '<S76>/Switch9' incorporates:
     *  Constant: '<S76>/Constant14'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch3'
     *  Switch: '<S76>/Switch4'
     *  Switch: '<S76>/Switch5'
     *  Switch: '<S76>/Switch7'
     *  Switch: '<S76>/Switch8'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)2U);
  } else if (rtb_DataTypeConversion154 == ((uint8)1U)) {
    /* Switch: '<S76>/Switch10' incorporates:
     *  Constant: '<S76>/Constant16'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch3'
     *  Switch: '<S76>/Switch4'
     *  Switch: '<S76>/Switch5'
     *  Switch: '<S76>/Switch7'
     *  Switch: '<S76>/Switch8'
     *  Switch: '<S76>/Switch9'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)1U);
  } else {
    /* Switch: '<S76>/Switch9' incorporates:
     *  Constant: '<S76>/Constant18'
     *  Switch: '<S76>/Switch1'
     *  Switch: '<S76>/Switch10'
     *  Switch: '<S76>/Switch2'
     *  Switch: '<S76>/Switch3'
     *  Switch: '<S76>/Switch4'
     *  Switch: '<S76>/Switch5'
     *  Switch: '<S76>/Switch7'
     *  Switch: '<S76>/Switch8'
     */
    swc_VCOP_ARID_DEF.Switch6 = ((uint8)0U);
  }

  /* End of Switch: '<S76>/Switch6' */

  /* Saturate: '<S12>/Saturation' incorporates:
   *  Inport generated from: '<Root>/F195_ECUSoftwareVersionNumber_Byte2'
   */
  rtb_DataTypeConversion154 =
    Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2
    ();

  /* Saturate: '<S12>/Saturation1' incorporates:
   *  Inport generated from: '<Root>/F195_ECUSoftwareVersionNumber_Byte3'
   */
  rtb_DataTypeConversion254 =
    Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3
    ();

  /* Saturate: '<S12>/Saturation2' incorporates:
   *  Inport generated from: '<Root>/F195_ECUSoftwareVersionNumber_Byte4'
   */
  rtb_Switch_kw =
    Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4
    ();

  /* Saturate: '<S12>/Saturation' */
  if (rtb_DataTypeConversion154 > ((uint8)57U)) {
    rtb_DataTypeConversion154 = ((uint8)57U);
  } else if (rtb_DataTypeConversion154 < ((uint8)48U)) {
    rtb_DataTypeConversion154 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation1' */
  if (rtb_DataTypeConversion254 > ((uint8)57U)) {
    rtb_DataTypeConversion254 = ((uint8)57U);
  } else if (rtb_DataTypeConversion254 < ((uint8)48U)) {
    rtb_DataTypeConversion254 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation2' */
  if (rtb_Switch_kw > ((uint8)57U)) {
    rtb_Switch_kw = ((uint8)57U);
  } else if (rtb_Switch_kw < ((uint8)48U)) {
    rtb_Switch_kw = ((uint8)48U);
  }

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S12>/Constant40'
   *  Constant: '<S12>/Constant41'
   *  Constant: '<S12>/Constant42'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S12>/Gain1'
   *  Saturate: '<S12>/Saturation'
   *  Saturate: '<S12>/Saturation1'
   *  Saturate: '<S12>/Saturation2'
   *  Sum: '<S12>/Add2'
   *  Sum: '<S12>/Add3'
   *  Sum: '<S12>/Add4'
   */
  swc_VCOP_ARID_DEF.Add = (uint8)((uint32)(uint8)((uint32)(uint8)(((uint32)
    (uint8)(rtb_DataTypeConversion154 - ((uint8)48U)) * ((uint8)200U)) >> 1) +
    (uint8)(((uint32)(uint8)(rtb_DataTypeConversion254 - ((uint8)48U)) * ((uint8)
    160U)) >> 4)) + (uint8)(rtb_Switch_kw - ((uint8)48U)));

  /* Saturate: '<S12>/Saturation3' incorporates:
   *  Inport generated from: '<Root>/F195_ECUSoftwareVersionNumber_Byte6'
   */
  rtb_DataTypeConversion154 =
    Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6
    ();

  /* Saturate: '<S12>/Saturation4' incorporates:
   *  Inport generated from: '<Root>/F195_ECUSoftwareVersionNumber_Byte7'
   */
  rtb_DataTypeConversion254 =
    Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7
    ();

  /* Saturate: '<S12>/Saturation5' incorporates:
   *  Inport generated from: '<Root>/F195_ECUSoftwareVersionNumber_Byte8'
   */
  rtb_Switch_kw =
    Rte_IRead_swc_VCOP_Step_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8
    ();

  /* Saturate: '<S12>/Saturation3' */
  if (rtb_DataTypeConversion154 > ((uint8)57U)) {
    rtb_DataTypeConversion154 = ((uint8)57U);
  } else if (rtb_DataTypeConversion154 < ((uint8)48U)) {
    rtb_DataTypeConversion154 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation4' */
  if (rtb_DataTypeConversion254 > ((uint8)57U)) {
    rtb_DataTypeConversion254 = ((uint8)57U);
  } else if (rtb_DataTypeConversion254 < ((uint8)48U)) {
    rtb_DataTypeConversion254 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation5' */
  if (rtb_Switch_kw > ((uint8)57U)) {
    rtb_Switch_kw = ((uint8)57U);
  } else if (rtb_Switch_kw < ((uint8)48U)) {
    rtb_Switch_kw = ((uint8)48U);
  }

  /* Sum: '<S12>/Add1' incorporates:
   *  Constant: '<S12>/Constant43'
   *  Constant: '<S12>/Constant44'
   *  Constant: '<S12>/Constant45'
   *  Gain: '<S12>/Gain2'
   *  Gain: '<S12>/Gain3'
   *  Saturate: '<S12>/Saturation3'
   *  Saturate: '<S12>/Saturation4'
   *  Saturate: '<S12>/Saturation5'
   *  Sum: '<S12>/Add5'
   *  Sum: '<S12>/Add6'
   *  Sum: '<S12>/Add7'
   */
  swc_VCOP_ARID_DEF.Add1 = (uint8)((uint32)(uint8)((uint32)(uint8)(((uint32)
    (uint8)(rtb_DataTypeConversion154 - ((uint8)48U)) * ((uint8)200U)) >> 1) +
    (uint8)(((uint32)(uint8)(rtb_DataTypeConversion254 - ((uint8)48U)) * ((uint8)
    160U)) >> 4)) + (uint8)(rtb_Switch_kw - ((uint8)48U)));

  /* Chart: '<S12>/Chart' incorporates:
   *  Inport generated from: '<Root>/F190_VIN_Byte0'
   *  Inport generated from: '<Root>/F190_VIN_Byte1'
   *  Inport generated from: '<Root>/F190_VIN_Byte10'
   *  Inport generated from: '<Root>/F190_VIN_Byte11'
   *  Inport generated from: '<Root>/F190_VIN_Byte12'
   *  Inport generated from: '<Root>/F190_VIN_Byte13'
   *  Inport generated from: '<Root>/F190_VIN_Byte14'
   *  Inport generated from: '<Root>/F190_VIN_Byte15'
   *  Inport generated from: '<Root>/F190_VIN_Byte16'
   *  Inport generated from: '<Root>/F190_VIN_Byte2'
   *  Inport generated from: '<Root>/F190_VIN_Byte3'
   *  Inport generated from: '<Root>/F190_VIN_Byte4'
   *  Inport generated from: '<Root>/F190_VIN_Byte5'
   *  Inport generated from: '<Root>/F190_VIN_Byte6'
   *  Inport generated from: '<Root>/F190_VIN_Byte7'
   *  Inport generated from: '<Root>/F190_VIN_Byte8'
   *  Inport generated from: '<Root>/F190_VIN_Byte9'
   */
  swc_VCOP_ARID_DEF.presentTicks = swc_VCOP_M->Timing.clockTick0;
  swc_VCOP_ARID_DEF.elapsedTicks = swc_VCOP_ARID_DEF.presentTicks -
    swc_VCOP_ARID_DEF.previousTicks;
  swc_VCOP_ARID_DEF.previousTicks = swc_VCOP_ARID_DEF.presentTicks;
  if (swc_VCOP_ARID_DEF.temporalCounter_i1 + swc_VCOP_ARID_DEF.elapsedTicks <=
      127U) {
    swc_VCOP_ARID_DEF.temporalCounter_i1 = (uint8)
      (swc_VCOP_ARID_DEF.temporalCounter_i1 + swc_VCOP_ARID_DEF.elapsedTicks);
  } else {
    swc_VCOP_ARID_DEF.temporalCounter_i1 = 127U;
  }

  if (swc_VCOP_ARID_DEF.is_active_c3_swc_VCOP == 0U) {
    swc_VCOP_ARID_DEF.is_active_c3_swc_VCOP = 1U;
    swc_VCOP_ARID_DEF.is_c3_swc_VCOP = swc_VCOP_IN_INIT;
    swc_VCOP_ARID_DEF.temporalCounter_i1 = 0U;
    swc_VCOP_ARID_DEF.VINMessageNum = 0U;
    swc_VCOP_ARID_DEF.VINCode1 = 0U;
    swc_VCOP_ARID_DEF.VINCode2 = 0U;
    swc_VCOP_ARID_DEF.VINCode3 = 0U;
    swc_VCOP_ARID_DEF.VINCode4 = 0U;
    swc_VCOP_ARID_DEF.VINCode5 = 0U;
    swc_VCOP_ARID_DEF.VINCode6 = 0U;
    swc_VCOP_ARID_DEF.VINCode7 = 0U;
  } else if (swc_VCOP_ARID_DEF.is_c3_swc_VCOP == swc_VCOP_IN_INIT) {
    swc_VCOP_ARID_DEF.VINMessageNum = 0U;
    if (swc_VCOP_ARID_DEF.temporalCounter_i1 >= 5U) {
      swc_VCOP_ARID_DEF.is_c3_swc_VCOP = swc_VCOP_IN_VIN_SEND;
      swc_VCOP_ARID_DEF.is_VIN_SEND = swc_VCOP_IN_VIN_SEND_1;
      swc_VCOP_ARID_DEF.temporalCounter_i1 = 0U;
      swc_VCOP_ARID_DEF.VINMessageNum = 1U;
      swc_VCOP_ARID_DEF.VINCode1 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte0_F190_VIN_Byte0();
      swc_VCOP_ARID_DEF.VINCode2 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte1_F190_VIN_Byte1();
      swc_VCOP_ARID_DEF.VINCode3 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte2_F190_VIN_Byte2();
      swc_VCOP_ARID_DEF.VINCode4 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte3_F190_VIN_Byte3();
      swc_VCOP_ARID_DEF.VINCode5 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte4_F190_VIN_Byte4();
      swc_VCOP_ARID_DEF.VINCode6 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte5_F190_VIN_Byte5();
      swc_VCOP_ARID_DEF.VINCode7 =
        Rte_IRead_swc_VCOP_Step_F190_VIN_Byte6_F190_VIN_Byte6();
    }
  } else {
    /* case IN_VIN_SEND: */
    switch (swc_VCOP_ARID_DEF.is_VIN_SEND) {
     case swc_VCOP_IN_VIN_SEND_1:
      swc_VCOP_ARID_DEF.VINMessageNum = 1U;
      if (swc_VCOP_ARID_DEF.temporalCounter_i1 >= 100U) {
        swc_VCOP_ARID_DEF.is_VIN_SEND = swc_VCOP_IN_VIN_SEND_2;
        swc_VCOP_ARID_DEF.temporalCounter_i1 = 0U;
        swc_VCOP_ARID_DEF.VINMessageNum = 2U;
        swc_VCOP_ARID_DEF.VINCode1 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte7_F190_VIN_Byte7();
        swc_VCOP_ARID_DEF.VINCode2 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte8_F190_VIN_Byte8();
        swc_VCOP_ARID_DEF.VINCode3 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte9_F190_VIN_Byte9();
        swc_VCOP_ARID_DEF.VINCode4 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte10_F190_VIN_Byte10();
        swc_VCOP_ARID_DEF.VINCode5 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte11_F190_VIN_Byte11();
        swc_VCOP_ARID_DEF.VINCode6 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte12_F190_VIN_Byte12();
        swc_VCOP_ARID_DEF.VINCode7 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte13_F190_VIN_Byte13();
      }
      break;

     case swc_VCOP_IN_VIN_SEND_2:
      swc_VCOP_ARID_DEF.VINMessageNum = 2U;
      if (swc_VCOP_ARID_DEF.temporalCounter_i1 >= 100U) {
        swc_VCOP_ARID_DEF.is_VIN_SEND = swc_VCOP_IN_VIN_SEND_3;
        swc_VCOP_ARID_DEF.temporalCounter_i1 = 0U;
        swc_VCOP_ARID_DEF.VINMessageNum = 3U;
        swc_VCOP_ARID_DEF.VINCode1 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte14_F190_VIN_Byte14();
        swc_VCOP_ARID_DEF.VINCode2 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte15_F190_VIN_Byte15();
        swc_VCOP_ARID_DEF.VINCode3 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte16_F190_VIN_Byte16();
        swc_VCOP_ARID_DEF.VINCode4 = 0U;
        swc_VCOP_ARID_DEF.VINCode5 = 0U;
        swc_VCOP_ARID_DEF.VINCode6 = 0U;
        swc_VCOP_ARID_DEF.VINCode7 = 0U;
      }
      break;

     default:
      /* case IN_VIN_SEND_3: */
      swc_VCOP_ARID_DEF.VINMessageNum = 3U;
      if (swc_VCOP_ARID_DEF.temporalCounter_i1 >= 100U) {
        swc_VCOP_ARID_DEF.is_VIN_SEND = swc_VCOP_IN_VIN_SEND_1;
        swc_VCOP_ARID_DEF.temporalCounter_i1 = 0U;
        swc_VCOP_ARID_DEF.VINMessageNum = 1U;
        swc_VCOP_ARID_DEF.VINCode1 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte0_F190_VIN_Byte0();
        swc_VCOP_ARID_DEF.VINCode2 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte1_F190_VIN_Byte1();
        swc_VCOP_ARID_DEF.VINCode3 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte2_F190_VIN_Byte2();
        swc_VCOP_ARID_DEF.VINCode4 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte3_F190_VIN_Byte3();
        swc_VCOP_ARID_DEF.VINCode5 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte4_F190_VIN_Byte4();
        swc_VCOP_ARID_DEF.VINCode6 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte5_F190_VIN_Byte5();
        swc_VCOP_ARID_DEF.VINCode7 =
          Rte_IRead_swc_VCOP_Step_F190_VIN_Byte6_F190_VIN_Byte6();
      }
      break;
    }
  }

  /* End of Chart: '<S12>/Chart' */

  /* Saturate: '<S12>/Saturation6' incorporates:
   *  Inport generated from: '<Root>/F193_ECUHardwareVersionNumber_Byte2'
   */
  rtb_DataTypeConversion154 =
    Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2
    ();

  /* Saturate: '<S12>/Saturation7' incorporates:
   *  Inport generated from: '<Root>/F193_ECUHardwareVersionNumber_Byte3'
   */
  rtb_DataTypeConversion254 =
    Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3
    ();

  /* Saturate: '<S12>/Saturation8' incorporates:
   *  Inport generated from: '<Root>/F193_ECUHardwareVersionNumber_Byte4'
   */
  rtb_Switch_kw =
    Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4
    ();

  /* Saturate: '<S12>/Saturation6' */
  if (rtb_DataTypeConversion154 > ((uint8)57U)) {
    rtb_DataTypeConversion154 = ((uint8)57U);
  } else if (rtb_DataTypeConversion154 < ((uint8)48U)) {
    rtb_DataTypeConversion154 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation7' */
  if (rtb_DataTypeConversion254 > ((uint8)57U)) {
    rtb_DataTypeConversion254 = ((uint8)57U);
  } else if (rtb_DataTypeConversion254 < ((uint8)48U)) {
    rtb_DataTypeConversion254 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation8' */
  if (rtb_Switch_kw > ((uint8)57U)) {
    rtb_Switch_kw = ((uint8)57U);
  } else if (rtb_Switch_kw < ((uint8)48U)) {
    rtb_Switch_kw = ((uint8)48U);
  }

  /* Sum: '<S12>/Add8' incorporates:
   *  Constant: '<S12>/Constant46'
   *  Constant: '<S12>/Constant47'
   *  Constant: '<S12>/Constant48'
   *  Gain: '<S12>/Gain4'
   *  Gain: '<S12>/Gain5'
   *  Saturate: '<S12>/Saturation6'
   *  Saturate: '<S12>/Saturation7'
   *  Saturate: '<S12>/Saturation8'
   *  Sum: '<S12>/Add10'
   *  Sum: '<S12>/Add11'
   *  Sum: '<S12>/Add12'
   */
  swc_VCOP_ARID_DEF.Add8 = (uint8)((uint32)(uint8)((uint32)(uint8)(((uint32)
    (uint8)(rtb_DataTypeConversion154 - ((uint8)48U)) * ((uint8)200U)) >> 1) +
    (uint8)(((uint32)(uint8)(rtb_DataTypeConversion254 - ((uint8)48U)) * ((uint8)
    160U)) >> 4)) + (uint8)(rtb_Switch_kw - ((uint8)48U)));

  /* Saturate: '<S12>/Saturation9' incorporates:
   *  Inport generated from: '<Root>/F193_ECUHardwareVersionNumber_Byte6'
   */
  rtb_DataTypeConversion154 =
    Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6
    ();

  /* Saturate: '<S12>/Saturation10' incorporates:
   *  Inport generated from: '<Root>/F193_ECUHardwareVersionNumber_Byte7'
   */
  rtb_DataTypeConversion254 =
    Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7
    ();

  /* Saturate: '<S12>/Saturation11' incorporates:
   *  Inport generated from: '<Root>/F193_ECUHardwareVersionNumber_Byte8'
   */
  rtb_Switch_kw =
    Rte_IRead_swc_VCOP_Step_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8
    ();

  /* Saturate: '<S12>/Saturation9' */
  if (rtb_DataTypeConversion154 > ((uint8)57U)) {
    rtb_DataTypeConversion154 = ((uint8)57U);
  } else if (rtb_DataTypeConversion154 < ((uint8)48U)) {
    rtb_DataTypeConversion154 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation10' */
  if (rtb_DataTypeConversion254 > ((uint8)57U)) {
    rtb_DataTypeConversion254 = ((uint8)57U);
  } else if (rtb_DataTypeConversion254 < ((uint8)48U)) {
    rtb_DataTypeConversion254 = ((uint8)48U);
  }

  /* Saturate: '<S12>/Saturation11' */
  if (rtb_Switch_kw > ((uint8)57U)) {
    rtb_Switch_kw = ((uint8)57U);
  } else if (rtb_Switch_kw < ((uint8)48U)) {
    rtb_Switch_kw = ((uint8)48U);
  }

  /* Sum: '<S12>/Add9' incorporates:
   *  Constant: '<S12>/Constant49'
   *  Constant: '<S12>/Constant50'
   *  Constant: '<S12>/Constant51'
   *  Gain: '<S12>/Gain6'
   *  Gain: '<S12>/Gain7'
   *  Saturate: '<S12>/Saturation10'
   *  Saturate: '<S12>/Saturation11'
   *  Saturate: '<S12>/Saturation9'
   *  Sum: '<S12>/Add13'
   *  Sum: '<S12>/Add14'
   *  Sum: '<S12>/Add15'
   */
  swc_VCOP_ARID_DEF.Add9 = (uint8)((uint32)(uint8)((uint32)(uint8)(((uint32)
    (uint8)(rtb_DataTypeConversion154 - ((uint8)48U)) * ((uint8)200U)) >> 1) +
    (uint8)(((uint32)(uint8)(rtb_DataTypeConversion254 - ((uint8)48U)) * ((uint8)
    160U)) >> 4)) + (uint8)(rtb_Switch_kw - ((uint8)48U)));

  /* Update for UnitDelay: '<S77>/Unit Delay' */
  swc_VCOP_ARID_DEF.UnitDelay_DSTATE_h = rtb_DataTypeConversion265;

  /* S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
   *  SubSystem: '<S3>/VAC_OutputsProcessing'
   */
  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   */
  if (swc_VCOP_ARID_DEF.DataTypeConversion91 != 0.0) {
    swc_VCOP_ARID_DEF.Switch = ((uint8)0U);
  } else {
    swc_VCOP_ARID_DEF.Switch = ((uint8)3U);
  }

  /* End of Switch: '<S15>/Switch' */
  /* End of Outputs for S-Function (fcgen): '<S3>/Function-Call Generator' */

  /* SignalConversion generated from: '<S3>/Ground1' */
  swc_VCOP_ARID_DEF.TmpBufferAtGround1Outport1 = 0.0F;

  /* SignalConversion generated from: '<S3>/Ground2' */
  swc_VCOP_ARID_DEF.TmpBufferAtGround2Outport1 = 0U;

  /* SignalConversion generated from: '<S3>/Ground3' */
  rtb_TmpBufferAtGround3Outport1 = 0.0;

  /* SignalConversion generated from: '<S3>/Ground' */
  rtb_TmpBufferAtGroundOutport1 = 0.0;

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/VOL__VCU_Output_Layer'
   */
  swc_VCOP_VOL__VCU_Output_Layer();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* CCaller: '<S1>/C Caller' */
  mBSW_SetOTAVehSpd(vold_VCU_VehicleSpd);

  /* DataTypeConversion: '<S1>/Data Type Conversion360' */
  tmp_2 = fmodf(floorf(vold_AC_EWP_Temp), 256.0F);

  /* DataTypeConversion: '<S1>/Data Type Conversion365' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion360'
   */
  rtb_DataTypeConversion154 = (uint8)(tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)
    (uint8)-tmp_2 : (sint32)(uint8)tmp_2);

  /* DataTypeConversion: '<S1>/Data Type Conversion368' */
  tmp_2 = fmodf(floorf(vold_AC_EWP_HeatrPwrCnsAllwd / 40.0F), 256.0F);

  /* DataTypeConversion: '<S1>/Data Type Conversion799' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion368'
   */
  rtb_DataTypeConversion265 = (uint8)(tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)
    (uint8)-tmp_2 : (sint32)(uint8)tmp_2);

  /* DataTypeConversion: '<S1>/Data Type Conversion884' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion883'
   */
  rtb_PMS_PreAccessoryCtrl = vold_b_accyPreRlyCmd;

  /* Outport generated from: '<Root>/PMS_IsgModReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IsgModReq_PMS_IsgModReq(vold_VCU_EMCtrlMode);

  /* DataTypeConversion: '<S1>/Data Type Conversion9' */
  tmp_2 = fmodf(floorf(vold_PMS_FrntHeatPwrAllwd / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/PMS_FrntHeatPwrAllwd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion9'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd((uint8)
    (tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* Outport generated from: '<Root>/PMS_FrntHeatModEnad' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion51'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad
    (vold_PMS_FrntHeatModEnad);

  /* Outport generated from: '<Root>/PMS_MCUActvdReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion73'
   *  DataTypeConversion: '<S1>/Data Type Conversion84'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MCUActvdReq_PMS_MCUActvdReq(vold_VCU_MCUEnableReq
    != 0);

  /* DataTypeConversion: '<S1>/Data Type Conversion95' */
  tmp_2 = fmodf(floorf((vold_VCU_ReqTrqOrLmt + 1200.0F) / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_IsgTqReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion95'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IsgTqReq_PMS_IsgTqReq((uint16)(tmp_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/PMS_Command_AliveCounter_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV
    (swc_VCOP_ConstB.PMS_Command_AliveCounter_EV);

  /* Outport generated from: '<Root>/PMS_Command_Checksum_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV
    (swc_VCOP_ConstB.PMS_Command_Checksum_EV);

  /* Outport generated from: '<Root>/VCU_BMSH_StsModeReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion15'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq
    (vold_VCU_bmsModeStsReq);

  /* DataTypeConversion: '<S1>/Data Type Conversion17' */
  tmp_2 = fmodf(floorf(vold_VCU_BMSH_DCChgRelayVolt * 0.25F), 256.0F);

  /* Outport generated from: '<Root>/VCU_BMSH_DCChgRelayVolt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion17'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt
    ((uint8)(tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)
             (uint8)tmp_2));

  /* Outport generated from: '<Root>/VCU_CrashOutputSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion19'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_CrashOutputSts_VCU_CrashOutputSts
    (vold_VCU_CrashOutputSts);

  /* DataTypeConversion: '<S1>/Data Type Conversion21' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion142'
   *  Inport generated from: '<Root>/vcib_VCIP_in114'
   */
  tmp_2 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_ipuHVBusVolt_V()
                       * 2.0F), 65536.0F);

  /* Outport generated from: '<Root>/VCU_ActInputVolt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion21'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_ActInputVolt_VCU_ActInputVolt((uint16)(tmp_2 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/VCU_BMSH_Ctrl_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter
    (swc_VCOP_ConstB.VCU_BMSH_Ctrl_AliveCounter);

  /* Outport generated from: '<Root>/VCU_BMSH_Ctrl_CheckSum' */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum
    (swc_VCOP_ConstB.VCU_BMSH_Ctrl_CheckSum);

  /* Outport generated from: '<Root>/PMS_DCDCCutOffLV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion27'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV
    (vold_VCU_12VDCDCCutOffLV);

  /* Outport generated from: '<Root>/PMS_DcDcActvdReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion29'
   *  DataTypeConversion: '<S1>/Data Type Conversion30'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DcDcActvdReq_PMS_DcDcActvdReq
    (vold_VCU_12VDCDCEnableOut != 0);

  /* DataTypeConversion: '<S1>/Data Type Conversion31' */
  tmp_2 = fmodf(floorf(vold_VCU_DCDCPwrLmt), 256.0F);

  /* Outport generated from: '<Root>/PMS_DCDCPwrLmt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion31'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt((uint8)(tmp_2 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* Outport generated from: '<Root>/PMS_DCDC_Ctrl_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter
    (swc_VCOP_ConstB.PMS_DCDC_Ctrl_AliveCounter);

  /* Outport generated from: '<Root>/PMS_DCDC_Ctrl_Checksum' */
  Rte_IWrite_swc_VCOP_Step_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum
    (swc_VCOP_ConstB.PMS_DCDC_Ctrl_Checksum);

  /* Outport generated from: '<Root>/PMS_ePTReady_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion37'
   *  DataTypeConversion: '<S1>/Data Type Conversion38'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTReady_EV_PMS_ePTReady_EV(vold_VCU_PTReadyInd
    != 0);

  /* DataTypeConversion: '<S1>/Data Type Conversion39' */
  tmp_2 = fmodf(floorf(vold_VCU_BMSHAllowChgCurrentMax * 0.5F), 256.0F);

  /* Outport generated from: '<Root>/VCU_BMSH_AllowChgCurrentMax' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion39'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax
    ((uint8)(tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)
             (uint8)tmp_2));

  /* Outport generated from: '<Root>/VCU_ChargeDepthReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion42'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_ChargeDepthReq_VCU_ChargeDepthReq((uint8)
    (vold_VCU_ChargeDepthReq << 1));

  /* Outport generated from: '<Root>/VCU_VehicleInfo_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter
    (swc_VCOP_ConstB.VCU_VehicleInfo_AliveCounte);

  /* Outport generated from: '<Root>/VCU_VehicleInfo_CheckSum' */
  Rte_IWrite_swc_VCOP_Step_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum
    (swc_VCOP_ConstB.VCU_VehicleInfo_CheckSum);

  /* DataTypeConversion: '<S1>/Data Type Conversion754' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion259'
   */
  tmp_2 = fmodf(floorf(vold_PMS_Odometerbackup / 100.0F), 65536.0F);

  /* Outport generated from: '<Root>/VCU_Odometerbackup' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion754'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_Odometerbackup_VCU_Odometerbackup((uint16)(tmp_2 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/PMS_SlidingmomentrSetReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion64'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq
    (vold_VCU_ePTRegencyLevInd);

  /* Outport generated from: '<Root>/PMS_Command_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_Command_AliveCounter_PMS_Command_AliveCounter
    (swc_VCOP_ConstB.PMS_Command_AliveCounter);

  /* Outport generated from: '<Root>/PMS_Command_Checksum' */
  Rte_IWrite_swc_VCOP_Step_PMS_Command_Checksum_PMS_Command_Checksum
    (swc_VCOP_ConstB.PMS_Command_Checksum);

  /* DataTypeConversion: '<S1>/Data Type Conversion70' */
  tmp_1 = fmodf(floorf(vold_PMS_RegenTrqPot + 4000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_RegenTrqPot' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion70'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqPot_PMS_RegenTrqPot((uint16)(tmp_1 < 0.0F
    ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion72' */
  tmp_1 = fmodf(floorf(vold_PMS_RegenTrqAct + 4000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_RegenTrqAct' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion72'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqAct_PMS_RegenTrqAct((uint16)(tmp_1 < 0.0F
    ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)tmp_1));

  /* Outport generated from: '<Root>/PMS_EPBClosedReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion75'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EPBClosedReq_PMS_EPBClosedReq
    (vold_PMS_EPBClosedReq_PMS);

  /* Outport generated from: '<Root>/PMS_DriverGearAbort' */
  Rte_IWrite_swc_VCOP_Step_PMS_DriverGearAbort_PMS_DriverGearAbort
    (swc_VCOP_ConstB.PMS_DriverGearAbort);

  /* Outport generated from: '<Root>/PMS_RegenTarTrqPotQualifier' */
  Rte_IWrite_swc_VCOP_Step_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier
    (swc_VCOP_ConstB.PMS_RegenTarTrqPotQualifier);

  /* Outport generated from: '<Root>/PMS_RegenTrqActQualifier' */
  Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier
    (swc_VCOP_ConstB.PMS_RegenTrqActQualifier);

  /* Outport generated from: '<Root>/PMS_RegenTrqPotQualifier' */
  Rte_IWrite_swc_VCOP_Step_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier
    (swc_VCOP_ConstB.PMS_RegenTrqPotQualifier);

  /* Outport generated from: '<Root>/PMS_AccelPedalPositionInvalid' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion86'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid
    (vold_VCU_AcceleratorPedal_flag);

  /* DataTypeConversion: '<S1>/Data Type Conversion88' */
  tmp_1 = fmodf(floorf(vold_VCU_AcceleratorPedalPosition / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_AccelPedalPosition' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion88'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AccelPedalPosition_PMS_AccelPedalPosition((uint8)
    (tmp_1 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_1 : (sint32)(uint8)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion90' */
  tmp_1 = fmodf(floorf(vold_PMS_RegenTarTrqPot + 4000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_RegenTarTrqPot' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion90'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot((uint16)(tmp_1 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)tmp_1));

  /* Outport generated from: '<Root>/PMS_CSControl2_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter
    (swc_VCOP_ConstB.PMS_CSControl2_AliveCounter);

  /* Outport generated from: '<Root>/PMS_CSControl2_CheckSum' */
  Rte_IWrite_swc_VCOP_Step_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum
    (swc_VCOP_ConstB.PMS_CSControl2_CheckSum);

  /* Outport generated from: '<Root>/PMS_DriveModeInd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion97'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DriveModeInd_PMS_DriveModeInd
    (vold_VCU_DriveModeInd);

  /* Outport generated from: '<Root>/PMS_VehicleSysErrorLevel' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion99'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel
    (vold_VCU_VehicleSysErrorLevel);

  /* Outport generated from: '<Root>/PMS_GearOperateErr' */
  Rte_IWrite_swc_VCOP_Step_PMS_GearOperateErr_PMS_GearOperateErr
    (swc_VCOP_ConstB.PMS_GearOperateErr);

  /* Outport generated from: '<Root>/PMS_BrkSysErr' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion468'
   *  DataTypeConversion: '<S1>/Data Type Conversion469'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BrkSysErr_PMS_BrkSysErr(vold_VCU_BrkSysErr != 0);

  /* Outport generated from: '<Root>/PMS_ePTModeSelect' */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTModeSelect_PMS_ePTModeSelect
    (swc_VCOP_ConstB.PMS_ePTModeSelect);

  /* Outport generated from: '<Root>/PMS_ePTModeActual' */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTModeActual_PMS_ePTModeActual
    (swc_VCOP_ConstB.PMS_ePTModeActual);

  /* Outport generated from: '<Root>/PMS_DriverRemind' */
  Rte_IWrite_swc_VCOP_Step_PMS_DriverRemind_PMS_DriverRemind
    (swc_VCOP_ConstB.PMS_DriverRemind);

  /* Outport generated from: '<Root>/PMS_ChargerFault' */
  Rte_IWrite_swc_VCOP_Step_PMS_ChargerFault_PMS_ChargerFault
    (swc_VCOP_ConstB.PMS_ChargerFault);

  /* Outport generated from: '<Root>/PMS_ePTReady' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion107'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTReady_PMS_ePTReady(vold_VCU_PTReadyInd != 0);

  /* Outport generated from: '<Root>/PMS_ePTReleaseSig' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion109'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTReleaseSig_PMS_ePTReleaseSig
    (vold_VCU_ePTReleaseSig);

  /* Outport generated from: '<Root>/PMS_ePTRegencyLevInd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion111'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd
    (vold_VCU_ePTRegencyLevInd);

  /* Outport generated from: '<Root>/PMS_DoubleFlashLampOn' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion113'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn
    (vold_VCU_HazardReq);

  /* Outport generated from: '<Root>/PMS_TurtleLampOn' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion115'
   *  DataTypeConversion: '<S1>/Data Type Conversion116'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TurtleLampOn_PMS_TurtleLampOn
    (vold_VCU_TurtleLampReq != 0);

  /* Outport generated from: '<Root>/PMS_ePTFault' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion117'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTFault_PMS_ePTFault(vold_PMS_ePTFault);

  /* Outport generated from: '<Root>/PMS_Ctrl_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter
    (swc_VCOP_ConstB.PMS_Ctrl_AliveCounter);

  /* Outport generated from: '<Root>/PMS_Ctrl_Checksum' */
  Rte_IWrite_swc_VCOP_Step_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum
    (swc_VCOP_ConstB.PMS_Ctrl_Checksum);

  /* DataTypeConversion: '<S1>/Data Type Conversion123' */
  tmp_1 = fmodf(floorf(vold_PMS_Real_PedalPosition / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_Real_PedalPosition' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion123'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Real_PedalPosition_PMS_Real_PedalPosition((uint8)
    (tmp_1 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_1 : (sint32)(uint8)tmp_1));

  /* Outport generated from: '<Root>/PMS_ModeGearDisplaySts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion125'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts
    (vold_VCU_GearPositionInd);

  /* Outport generated from: '<Root>/PMS_ADCCtrlSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion127'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ADCCtrlSts_PMS_ADCCtrlSts
    (swc_VCOP_ARID_DEF.DataTypeConversion234);

  /* Outport generated from: '<Root>/PMS_CANBus_RecSta' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion129'
   *  DataTypeConversion: '<S1>/Data Type Conversion130'
   *  Inport generated from: '<Root>/vcib_VCIP_in187'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CANBus_RecSta_PMS_CANBus_RecSta
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_adcd_st_pmsCanBusRecSta() != 0);

  /* Outport generated from: '<Root>/PMS_ACC_BeControlled_Status' */
  Rte_IWrite_swc_VCOP_Step_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status
    (swc_VCOP_ConstB.PMS_ACC_BeControlled_Status);

  /* Outport generated from: '<Root>/PMS_CurrentGearPosition' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion133'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_PMS_CurrentGearPosition
    (vold_VCU_ActualGear);

  /* Outport generated from: '<Root>/PMS_CurrentGearPosition_Valid' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion135'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid
    (vold_PMS_CurrentGearPositionValid);

  /* Outport generated from: '<Root>/PMS_Gear_intervene' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion137'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Gear_intervene_PMS_Gear_intervene
    (vold_PMS_GearIntervene);

  /* Outport generated from: '<Root>/PMS_ChargeHV_Status' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion139'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ChargeHV_Status_PMS_ChargeHV_Status
    (vold_VCU_HV_Status);

  /* Outport generated from: '<Root>/PMS_APA_BeControlled_Status' */
  Rte_IWrite_swc_VCOP_Step_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status
    (swc_VCOP_ConstB.PMS_APA_BeControlled_Status);

  /* Outport generated from: '<Root>/PMS_Real_PedalPositionInvalid' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion143'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid
    (vold_PMS_Real_PedalPositionInvalid);

  /* Outport generated from: '<Root>/PMS_ModeControl_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter
    (swc_VCOP_ConstB.PMS_ModeControl_AliveCounte);

  /* Outport generated from: '<Root>/PMS_ModeControl_CheckSum' */
  Rte_IWrite_swc_VCOP_Step_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum
    (swc_VCOP_ConstB.PMS_ModeControl_CheckSum);

  /* DataTypeConversion: '<S1>/Data Type Conversion149' */
  tmp_1 = fmodf(floorf(vold_PMS_ActualPTTorque + 6000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_ActualPTTorque' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion149'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ActualPTTorque_PMS_ActualPTTorque((uint16)(tmp_1 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion151' */
  tmp_1 = fmodf(floorf(vold_PMS_DriverDemandTorque + 6000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_DriverDemandTorque' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion151'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DriverDemandTorque_PMS_DriverDemandTorque((uint16)
    (tmp_1 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)
     tmp_1));

  /* Outport generated from: '<Root>/PMS_GP_Ovrd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion153'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_GP_Ovrd_PMS_GP_Ovrd(vold_VCU_GP_Override);

  /* Outport generated from: '<Root>/PMS_ActualPTTorqueInvalid' */
  Rte_IWrite_swc_VCOP_Step_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid
    (swc_VCOP_ConstB.PMS_ActualPTTorqueInvalid);

  /* Outport generated from: '<Root>/PMS_DriverDemandTorqueInvalid' */
  Rte_IWrite_swc_VCOP_Step_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid
    (swc_VCOP_ConstB.PMS_DriverDemandTorqueInval);

  /* Outport generated from: '<Root>/PMS_VacuumSystemsta' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VacuumSystemsta_PMS_VacuumSystemsta
    (vold_PMS_VacuumSystemsta);

  /* DataTypeConversion: '<S1>/Data Type Conversion161' */
  tmp_1 = fmodf(floorf((vold_PMS_VacuumPressure + 108.0F) / 0.2F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_VacuumPressure' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion161'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VacuumPressure_PMS_VacuumPressure((uint16)(tmp_1 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)tmp_1));

  /* Outport generated from: '<Root>/PMS_EngTrqReqSrc' */
  Rte_IWrite_swc_VCOP_Step_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc
    (swc_VCOP_ConstB.PMS_EngTrqReqSrc);

  /* Outport generated from: '<Root>/PMS_LimpHomeSts' */
  Rte_IWrite_swc_VCOP_Step_PMS_LimpHomeSts_PMS_LimpHomeSts
    (swc_VCOP_ConstB.PMS_LimpHomeSts);

  /* Outport generated from: '<Root>/PMS_EngControl_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter
    (swc_VCOP_ConstB.PMS_EngControl_AliveCounter);

  /* Outport generated from: '<Root>/PMS_EngControl_CheckSum' */
  Rte_IWrite_swc_VCOP_Step_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum
    (swc_VCOP_ConstB.PMS_EngControl_CheckSum);

  /* DataTypeConversion: '<S1>/Data Type Conversion171' */
  tmp_1 = fmodf(floorf(vold_PMS_MinPTTorqueAllowed + 6000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_MinPTTorqueAllowed' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion171'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed((uint16)
    (tmp_1 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)
     tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion173' */
  tmp_1 = fmodf(floorf(vold_PMS_MaxPTTorqueAllowed + 6000.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_MaxPTTorqueAllowed' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion173'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed((uint16)
    (tmp_1 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)
     tmp_1));

  /* Outport generated from: '<Root>/PMS_StartActive' */
  Rte_IWrite_swc_VCOP_Step_PMS_StartActive_PMS_StartActive
    (swc_VCOP_ConstB.PMS_StartActive);

  /* Outport generated from: '<Root>/PMS_CruiseControlSts' */
  Rte_IWrite_swc_VCOP_Step_PMS_CruiseControlSts_PMS_CruiseControlSts
    (swc_VCOP_ConstB.PMS_CruiseControlSts);

  /* Outport generated from: '<Root>/PMS_CruiseSwitchSts' */
  Rte_IWrite_swc_VCOP_Step_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts
    (swc_VCOP_ConstB.PMS_CruiseSwitchSts);

  /* Outport generated from: '<Root>/PMS_ControlSetSpeed' */
  Rte_IWrite_swc_VCOP_Step_PMS_ControlSetSpeed_PMS_ControlSetSpeed
    (swc_VCOP_ConstB.PMS_ControlSetSpeed);

  /* Outport generated from: '<Root>/PMS_DM_FailureReasonAndSysFaultFBK' */
  Rte_IWrite_swc_VCOP_Step_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK
    (swc_VCOP_ConstB.PMS_DM_FailureReasonAndSysF);

  /* Outport generated from: '<Root>/PMS_CSControl1_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter
    (swc_VCOP_ConstB.PMS_CSControl1_AliveCounter);

  /* Outport generated from: '<Root>/PMS_CSControl1_CheckSum' */
  Rte_IWrite_swc_VCOP_Step_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum
    (swc_VCOP_ConstB.PMS_CSControl1_CheckSum);

  /* DataTypeConversion: '<S1>/Data Type Conversion189' */
  tmp_1 = fmodf(floorf(vold_VCU_EVDTEodometer), 65536.0F);

  /* Outport generated from: '<Root>/PMS_EVDTEodometer' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion189'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EVDTEodometer_PMS_EVDTEodometer((uint16)(tmp_1 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion191' */
  tmp_1 = fmodf(floorf(vold_VCU_PTResiPwr / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_PTResiduePwrInd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion191'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd((uint16)
    (tmp_1 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_1 : (sint32)(uint16)
     tmp_1));

  /* Outport generated from: '<Root>/PMS_EpedalActive' */
  Rte_IWrite_swc_VCOP_Step_PMS_EpedalActive_PMS_EpedalActive
    (swc_VCOP_ConstB.PMS_EpedalActive);

  /* Outport generated from: '<Root>/PMS_EPedlDrvrIndcnMsg' */
  Rte_IWrite_swc_VCOP_Step_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg
    (swc_VCOP_ConstB.PMS_EPedlDrvrIndcnMsg);

  /* Outport generated from: '<Root>/DrvPfmncRedn' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion197'
   */
  Rte_IWrite_swc_VCOP_Step_DrvPfmncRedn_DrvPfmncRedn(vold_PMS_DrvPfmncRedn);

  /* Outport generated from: '<Root>/PMS_DrvrGearLvrLockIndcn' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion199'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn
    (vold_VCU_GearOperateErr);

  /* Outport generated from: '<Root>/PMS_HvBattCooltLvl' */
  Rte_IWrite_swc_VCOP_Step_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl
    (swc_VCOP_ConstB.PMS_HvBattCooltLvl);

  /* Outport generated from: '<Root>/PMS_V2XDchaSwtFb1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion203'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1
    (vold_PMS_V2XDchaSwtFb1);

  /* Outport generated from: '<Root>/PMS_ACCMEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion211'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ACCMEnable_PMS_ACCMEnable(vold_VCU_ACCMEnable);

  /* Outport generated from: '<Root>/PMS_PTCEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion213'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTCEnable_PMS_PTCEnable(vold_VCU_PTCEnable);

  /* Outport generated from: '<Root>/BMSH_HvBattThermMod' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion215'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_HvBattThermMod_BMSH_HvBattThermMod
    (vold_BMSH_CCM_ThermalManageReq);

  /* DataTypeConversion: '<S1>/Data Type Conversion217' */
  tmp_1 = fmodf(floorf(vold_VCU_ATS1_PWMRequest), 256.0F);

  /* Outport generated from: '<Root>/PMS_CoolingFanPWMSpd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion217'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd((uint8)
    (tmp_1 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_1 : (sint32)(uint8)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion219' */
  tmp_1 = fmodf(floorf(vold_PMS_HvCoolgPwrAllwd / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/PMS_HvCoolgPwrAllwd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion219'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd((uint8)(tmp_1
    < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_1 : (sint32)(uint8)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion221' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion761'
   */
  tmp_1 = fmodf(floorf(vold_VCU_BattPackInCoolTempback * 2.0F + 80.0F), 256.0F);

  /* Outport generated from: '<Root>/BMSH_Inlet_WaterTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion221'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp((uint8)
    (tmp_1 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_1 : (sint32)(uint8)tmp_1));

  /* DataTypeConversion: '<S1>/Data Type Conversion223' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion763'
   */
  tmp_b = fmodf(floorf(vold_VCU_BattPackoutCoolTempback * 2.0F + 80.0F), 256.0F);

  /* Outport generated from: '<Root>/BMSH_Outlet_WaterTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion223'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp((uint8)
    (tmp_b < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_b : (sint32)(uint8)tmp_b));

  /* DataTypeConversion: '<S1>/Data Type Conversion225' */
  tmp_0 = fmodf(floorf(vold_VCU_Set_Temp * 2.0F + 80.0F), 256.0F);

  /* Outport generated from: '<Root>/BMSH_HvBattCooltTReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion225'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq((uint8)
    (tmp_0 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* Outport generated from: '<Root>/PMS_DriveCircuitTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion227'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp((uint8)
    (vold_VCU_DriveCircuitTemp + 40));

  /* DataTypeConversion: '<S1>/Data Type Conversion229' */
  tmp_0 = fmodf(floorf(vold_PMS_HvHeatgPwrAllwd / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/PMS_HvHeatgPwrAllwd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion229'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd((uint8)(tmp_0
    < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* Outport generated from: '<Root>/PMS_LTCoolingFanFB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion231'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB
    (vold_VCU_LTCoolingFan2FB);

  /* Outport generated from: '<Root>/PMS_AuthResult' */
  Rte_IWrite_swc_VCOP_Step_PMS_AuthResult_PMS_AuthResult
    (swc_VCOP_ConstB.PMS_AuthResult);

  /* Outport generated from: '<Root>/PMS_RespResult' */
  Rte_IWrite_swc_VCOP_Step_PMS_RespResult_PMS_RespResult
    (swc_VCOP_ConstB.PMS_RespResult);

  /* Outport generated from: '<Root>/PMS_ReqSeed' */
  Rte_IWrite_swc_VCOP_Step_PMS_ReqSeed_PMS_ReqSeed(swc_VCOP_ConstB.PMS_ReqSeed);

  /* Outport generated from: '<Root>/PMS_ExecuteLockVehResults' */
  Rte_IWrite_swc_VCOP_Step_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults
    (swc_VCOP_ConstB.PMS_ExecuteLockVehResults);

  /* Outport generated from: '<Root>/PMS_LockVehSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion241'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LockVehSts_PMS_LockVehSts(vold_VCU_LockVehSts);

  /* Outport generated from: '<Root>/PMS_FunLockVehActive' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion243'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FunLockVehActive_PMS_FunLockVehActive
    (vold_VCU_FunLockVehActive);

  /* Outport generated from: '<Root>/PMS_FunAnti_DismantleActive' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion245'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive
    (vold_VCU_FunAnti_DismantleActive);

  /* Outport generated from: '<Root>/PMS_LockVehType' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion247'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LockVehType_PMS_LockVehType(vold_VCU_LockVehType);

  /* Outport generated from: '<Root>/PMS_LockLimResult' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion249'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LockLimResult_PMS_LockLimResult
    (vold_VCU_LockLimResult);

  /* Outport generated from: '<Root>/PMS_IntelligentChargeState' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion251'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IntelligentChargeState_PMS_IntelligentChargeState
    (vold_VCU_IntelligentChargeState);

  /* Outport generated from: '<Root>/PMS_IntelligentChargeQuit' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion253'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit
    (vold_VCU_IntelligentChargeQuit);

  /* Outport generated from: '<Root>/PMS_IntelligentChargeExitReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion255'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq
    (vold_VCU_IntelligentChargeExitReq);

  /* Outport generated from: '<Root>/PMS_TBOX_HVILState' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion257'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILState_PMS_TBOX_HVILState
    (vold_PMS_TBOX_HVILState);

  /* Outport generated from: '<Root>/PMS_Odometerbackup' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion259'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Odometerbackup_PMS_Odometerbackup((uint16)(tmp_2 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion261' */
  tmp_2 = fmodf(floorf(rtb_DataTypeConversion138), 256.0F);

  /* Outport generated from: '<Root>/BMSH_BattSOH' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion261'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattSOH_BMSH_BattSOH((uint8)(tmp_2 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion263' */
  tmp_2 = fmodf(floorf((vold_BMSH_BattCurr + 500.0F) / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_BattCurr' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion263'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattCurr_BMSH_BattCurr((uint16)(tmp_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion265' */
  tmp_2 = fmodf(floorf(vold_VCU_BMS_voltage), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_HVBusVolt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion265'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_HVBusVolt_BMSH_HVBusVolt((uint16)(tmp_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/BMSH_HvShutdownReq' */
  Rte_IWrite_swc_VCOP_Step_BMSH_HvShutdownReq_BMSH_HvShutdownReq
    (swc_VCOP_ConstB.BMSH_HvShutdownReq);

  /* DataTypeConversion: '<S1>/Data Type Conversion269' */
  tmp_2 = fmodf(floorf(vold_VCU_BattVol / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_BattVolt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion269'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattVolt_BMSH_BattVolt((uint16)(tmp_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/BMSH_VoltCurr_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter
    (swc_VCOP_ConstB.BMSH_VoltCurr_AliveCounter);

  /* Outport generated from: '<Root>/BMSH_VoltCurr_Checksum' */
  Rte_IWrite_swc_VCOP_Step_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum
    (swc_VCOP_ConstB.BMSH_VoltCurr_Checksum);

  /* DataTypeConversion: '<S1>/Data Type Conversion275' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion139'
   *  DataTypeConversion: '<S1>/Data Type Conversion748'
   *  Inport generated from: '<Root>/vcib_VCIP_in113'
   */
  tmp_2 = fmodf(floorf
                (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh() /
                 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_BattRemainEnergy' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion275'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy((uint16)
    (tmp_2 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)
     tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion277' */
  tmp_0 = fmodf(floorf(vold_VCU_BMS_SOC / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_BattSOC' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion277'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattSOC_BMSH_BattSOC((uint16)(tmp_0 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_0 : (sint32)(uint16)tmp_0));

  /* Outport generated from: '<Root>/BMSH_Cell_TotalNum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion279'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum
    (vold_BMSH_Cell_TotalNum);

  /* Outport generated from: '<Root>/BMSH_Battery_Performance_AliveCounter' */
  Rte_IWrite_swc_VCOP_Step_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter
    (swc_VCOP_ConstB.BMSH_Battery_Performance_Al);

  /* Outport generated from: '<Root>/BMSH_Battery_Performance_Checksum' */
  Rte_IWrite_swc_VCOP_Step_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum
    (swc_VCOP_ConstB.BMSH_Battery_Performance_Ch);

  /* Outport generated from: '<Root>/BMSH_BattFaultLampState' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion301'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattFaultLampState_BMSH_BattFaultLampState
    (vold_BMSH_BattFaultLampState);

  /* Outport generated from: '<Root>/BMSH_Vehicle_HVILSts_PHEV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion303'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV
    (vold_BMSH_Vehicle_HVILSts_PHEV);

  /* Outport generated from: '<Root>/BMSH_stMode' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion305'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_stMode_BMSH_stMode(vold_BMSH_stMode);

  /* Outport generated from: '<Root>/BMSH_FastChgCC2ConntState' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion307'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState
    (vold_BMSH_FastChgCC2ConntState);

  /* DataTypeConversion: '<S1>/Data Type Conversion309' */
  tmp_0 = fmodf(floorf(vold_BMSH_ACChgTimeRemain), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_ACChgTimeRemain' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion309'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain((uint16)
    (tmp_0 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_0 : (sint32)(uint16)
     tmp_0));

  /* Outport generated from: '<Root>/BMSH_ThermalOutofControl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion311'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl
    (vold_BMSH_ThermalOutofControl);

  /* Outport generated from: '<Root>/BMSH_ChargeToBeFinished' */
  Rte_IWrite_swc_VCOP_Step_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished
    (swc_VCOP_ConstB.BMSH_ChargeToBeFinished);

  /* DataTypeConversion: '<S1>/Data Type Conversion315' */
  tmp_0 = fmodf(floorf(vold_VCU_Cell_Avg_Temp + 40.0F), 256.0F);

  /* Outport generated from: '<Root>/BMSH_BattTempAvg_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion315'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT((uint8)(tmp_0
    < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* DataTypeConversion: '<S1>/Data Type Conversion317' */
  tmp_0 = fmodf(floorf(vold_VCU_BattMaxTemp + 40.0F), 256.0F);

  /* Outport generated from: '<Root>/BMSH_TempSensor_MaxTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion317'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp
    ((uint8)(tmp_0 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)
             (uint8)tmp_0));

  /* DataTypeConversion: '<S1>/Data Type Conversion319' */
  tmp_0 = fmodf(floorf(vold_VCU_BattMinTemp + 40.0F), 256.0F);

  /* Outport generated from: '<Root>/BMSH_TempSensor_MinTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion319'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp
    ((uint8)(tmp_0 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)
             (uint8)tmp_0));

  /* Outport generated from: '<Root>/BMSH_ChargeLEDCtrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion321'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl
    (vold_BMSH_ChargeLEDCtrl);

  /* Outport generated from: '<Root>/BMSH_Charge_Over_Current' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion323'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current
    (vold_BMSH_Charge_Over_Current);

  /* Outport generated from: '<Root>/BMSH_InsulationRes_Fault' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion325'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault
    (vold_BMSH_InsulationRes_Fault);

  /* Outport generated from: '<Root>/BMSH_DCChgminusSocketTempSensing_Failure' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion327'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure
    (vold_BMSH_DCChgminusSocketTempSensing_Failure);

  /* Outport generated from: '<Root>/BMSH_DCChgplusSocketTempSensing_Failure' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion329'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure
    (vold_BMSH_DCChgplusSocketTempSensing_Failure);

  /* DataTypeConversion: '<S1>/Data Type Conversion331' */
  tmp_0 = fmodf(floorf(vold_BMSH_ChgTimeRemain), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_ChgTimeRemain' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion331'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain((uint16)(tmp_0 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_0 : (sint32)(uint16)tmp_0));

  /* Outport generated from: '<Root>/PMS_PEPSAuth' */
  Rte_IWrite_swc_VCOP_Step_PMS_PEPSAuth_PMS_PEPSAuth
    (swc_VCOP_ConstB.PMS_PEPSAuth);

  /* Outport generated from: '<Root>/PMS_EDCPEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion347'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EDCPEnable_PMS_EDCPEnable(vold_VCU_EDCP_Enable);

  /* Outport generated from: '<Root>/PMS_HBCPEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion349'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HBCPEnable_PMS_HBCPEnable(vold_VCU_HBCP_Enable);

  /* DataTypeConversion: '<S1>/Data Type Conversion351' */
  tmp_0 = fmodf(floorf(vold_VCU_EDCP_PWMCtrl / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_EDCPPWMCtrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion351'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl((uint8)(tmp_0 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* DataTypeConversion: '<S1>/Data Type Conversion353' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion529'
   */
  tmp_0 = fmodf(floorf(vold_VCU_HBCP_PWMCtrl / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_HBCPPWMCtrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion353'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl((uint8)(tmp_0 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* Outport generated from: '<Root>/EDCP_Flt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion355'
   */
  Rte_IWrite_swc_VCOP_Step_EDCP_Flt_EDCP_Flt(vold_EDCP_Flt);

  /* Outport generated from: '<Root>/EDCP_PWMFB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion361'
   */
  Rte_IWrite_swc_VCOP_Step_EDCP_PWMFB_EDCP_PWMFB((uint8)((vold_VCU_Cabin_PumpFb *
    5U) >> 1));

  /* Outport generated from: '<Root>/HBCP_Flt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion363'
   */
  Rte_IWrite_swc_VCOP_Step_HBCP_Flt_HBCP_Flt(vold_HBCP_Flt);

  /* Outport generated from: '<Root>/HBCP_PWMFB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion369'
   */
  Rte_IWrite_swc_VCOP_Step_HBCP_PWMFB_HBCP_PWMFB((uint8)((vold_VCU_HVB_PumpFb *
    5U) >> 1));

  /* DataTypeConversion: '<S1>/Data Type Conversion371' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion453'
   */
  tmp_5 = fmodf(floorf(vold_VCU_ATS3_PWMRequest / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_MHGV_PosSet' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion371'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_PosSet_PMS_MHGV_PosSet((uint8)(tmp_5 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_5 : (sint32)(uint8)tmp_5));

  /* Outport generated from: '<Root>/PMS_MHGV_EnableReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion373'
   *  DataTypeConversion: '<S1>/Data Type Conversion374'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq
    (vold_VCU_ATS1Enable != 0);

  /* Outport generated from: '<Root>/PMS_MHGV_ReqMotorEmgyStop' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion375'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop
    (vold_waterValveTV1V3_V);

  /* Outport generated from: '<Root>/PMS_MHGV_ReqMotorOptRecovery' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion377'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery
    (vold_waterValveTV2V2_V);

  /* Outport generated from: '<Root>/PMS_FWFV_MoveEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion379'
   *  DataTypeConversion: '<S1>/Data Type Conversion380'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable
    (vold_VCU_ATS2Enable != 0);

  /* DataTypeConversion: '<S1>/Data Type Conversion381' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion159'
   */
  tmp_6 = fmodf(floorf(vold_VCU_ATS4_PWMRequest / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_FWFV_ReqMovePos' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion381'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos((uint8)(tmp_6
    < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_6 : (sint32)(uint8)tmp_6));

  /* Outport generated from: '<Root>/MHGV_RESP_ERROR_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion383'
   *  Inport generated from: '<Root>/vcib_VCIP_in146'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvRespErr());

  /* Outport generated from: '<Root>/MHGV_OverVoltageFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion385'
   *  Inport generated from: '<Root>/vcib_VCIP_in147'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvOvrVoltFlt());

  /* Outport generated from: '<Root>/MHGV_OverCurrentFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion387'
   *  Inport generated from: '<Root>/vcib_VCIP_in148'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvOvrCurrFlt());

  /* Outport generated from: '<Root>/MHGV_OverTempFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion389'
   *  Inport generated from: '<Root>/vcib_VCIP_in149'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvOvrTempFlt());

  /* Outport generated from: '<Root>/MHGV_UnderVoltageFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion391'
   *  Inport generated from: '<Root>/vcib_VCIP_in150'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvUndVoltFlt());

  /* Outport generated from: '<Root>/MHGV_InitState_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion393'
   *  Inport generated from: '<Root>/vcib_VCIP_in151'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_InitState_PMS_MHGV_InitState_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvInitSts());

  /* Outport generated from: '<Root>/MHGV_CCWFlg_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion395'
   *  Inport generated from: '<Root>/vcib_VCIP_in152'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvCcwFlg());

  /* Outport generated from: '<Root>/MHGV_MotorState_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion397'
   *  Inport generated from: '<Root>/vcib_VCIP_in153'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_MotorState_PMS_MHGV_MotorState_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_mhgvMotSts());

  /* DataTypeConversion: '<S1>/Data Type Conversion399' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in154'
   */
  tmp = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_mhgvCrtPos() /
                     0.4F), 256.0F);

  /* Outport generated from: '<Root>/MHGV_CurrentPos_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion399'
   */
  Rte_IWrite_swc_VCOP_Step_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS((uint8)(tmp <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp : (sint32)(uint8)tmp));

  /* Outport generated from: '<Root>/FWFV_RESP_ERROR_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion401'
   *  Inport generated from: '<Root>/vcib_VCIP_in155'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvRespErr());

  /* Outport generated from: '<Root>/FWFV_OverVoltageFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion403'
   *  Inport generated from: '<Root>/vcib_VCIP_in156'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvOvrVoltFlt());

  /* Outport generated from: '<Root>/FWFV_OverCurrentFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion405'
   *  Inport generated from: '<Root>/vcib_VCIP_in157'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvOvrCurrFlt());

  /* Outport generated from: '<Root>/FWFV_OverTempFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion407'
   *  Inport generated from: '<Root>/vcib_VCIP_in158'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvOvrTempFlt());

  /* Outport generated from: '<Root>/FWFV_UnderVoltageFlt_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion409'
   *  Inport generated from: '<Root>/vcib_VCIP_in159'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvUndVoltFlt());

  /* Outport generated from: '<Root>/FWFV_InitState_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion411'
   *  Inport generated from: '<Root>/vcib_VCIP_in160'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_InitState_PMS_FWFV_InitState_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvInitSts());

  /* Outport generated from: '<Root>/FWFV_CCWFlg_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion413'
   *  Inport generated from: '<Root>/vcib_VCIP_in161'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvCcwFlg());

  /* Outport generated from: '<Root>/FWFV_MotorState_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion415'
   *  Inport generated from: '<Root>/vcib_VCIP_in162'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_MotorState_PMS_FWFV_MotorState_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_fwfvMotSts());

  /* DataTypeConversion: '<S1>/Data Type Conversion417' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in163'
   */
  tmp = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_pct_fwfvCrtPos() /
                     0.4F), 256.0F);

  /* Outport generated from: '<Root>/FWFV_CurrentPos_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion417'
   */
  Rte_IWrite_swc_VCOP_Step_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS((uint8)(tmp <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp : (sint32)(uint8)tmp));

  /* Outport generated from: '<Root>/O_S_PIN88' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion419'
   */
  Rte_IWrite_swc_VCOP_Step_O_S_PIN88_O_S_PIN88(vold_brkPmpEn);

  /* Outport generated from: '<Root>/O_S_PIN83' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion421'
   */
  Rte_IWrite_swc_VCOP_Step_O_S_PIN83_O_S_PIN83(vold_b_highSpdFanRlyReq);

  /* Outport generated from: '<Root>/O_S_PIN89' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion423'
   */
  Rte_IWrite_swc_VCOP_Step_O_S_PIN89_O_S_PIN89(vold_b_motFanRlyReq);

  /* Outport generated from: '<Root>/O_S_PIN110' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion425'
   */
  Rte_IWrite_swc_VCOP_Step_O_S_PIN110_O_S_PIN110(vold_b_CpsrCtrl);

  /* DataTypeConversion: '<S1>/Data Type Conversion427' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion431'
   *  DataTypeConversion: '<S1>/Data Type Conversion644'
   */
  tmp = fmodf(floorf(vold_fan1TgtSpd_pct), 65536.0F);

  /* Outport generated from: '<Root>/O_T_PIN82_Duty' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion427'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN82_Duty_O_T_PIN82_Duty((uint16)(tmp < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp : (sint32)(uint16)tmp));

  /* Outport generated from: '<Root>/O_T_PIN82_Period' incorporates:
   *  Constant: '<S1>/Constant3'
   *  DataTypeConversion: '<S1>/Data Type Conversion429'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN82_Period_O_T_PIN82_Period
    (volc_pmpTgtPeriod_us);

  /* Outport generated from: '<Root>/O_T_PIN118_Duty' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion431'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN118_Duty_O_T_PIN118_Duty((uint16)(tmp < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp : (sint32)(uint16)tmp));

  /* Outport generated from: '<Root>/O_T_PIN118_Period' incorporates:
   *  Constant: '<S1>/Constant2'
   *  DataTypeConversion: '<S1>/Data Type Conversion433'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN118_Period_O_T_PIN118_Period
    (volc_pmpTgtPeriod2_us);

  /* Outport generated from: '<Root>/O_T_PIN77_Duty' incorporates:
   *  Constant: '<S1>/Constant13'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN77_Duty_O_T_PIN77_Duty(volc_n_Spd5_pct);

  /* Outport generated from: '<Root>/O_T_PIN77_Period' incorporates:
   *  Constant: '<S1>/Constant6'
   *  DataTypeConversion: '<S1>/Data Type Conversion437'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN77_Period_O_T_PIN77_Period
    (volc_pmpTgtPeriod3_us);

  /* DataTypeConversion: '<S1>/Data Type Conversion439' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion474'
   */
  tmp_9 = fmodf(floorf(vold_pct_acHvilDtyOutpt), 65536.0F);

  /* Outport generated from: '<Root>/O_T_PIN104_Duty' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion439'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN104_Duty_O_T_PIN104_Duty((uint16)(tmp_9 < 0.0F
    ? (sint32)(uint16)-(sint16)(uint16)-tmp_9 : (sint32)(uint16)tmp_9));

  /* DataTypeConversion: '<S1>/Data Type Conversion441' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion656'
   */
  tmp_a = fmodf(floorf(vold_tm_acHvilPrdOutpt), 4.2949673E+9F);

  /* Outport generated from: '<Root>/O_T_PIN104_Period' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion441'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN104_Period_O_T_PIN104_Period(tmp_a < 0.0F ?
    (uint32)-(sint32)(uint32)-tmp_a : (uint32)tmp_a);

  /* Outport generated from: '<Root>/EXT_PO_HVIL_2_DutyCycle' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion443'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle
    (vold_pct_odpHvilDtyOutpt);

  /* Outport generated from: '<Root>/EXT_PO_HVIL_2_Period' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion445'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period
    (vold_tm_odpHvilPrdOutpt);

  /* DataTypeConversion: '<S1>/Data Type Conversion447' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion472'
   */
  tmp_8 = fmodf(floorf(vold_pmpEP2TgtSpd_pct), 65536.0F);

  /* Outport generated from: '<Root>/O_T_PIN14_Duty' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion447'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN14_Duty_O_T_PIN14_Duty((uint16)(tmp_8 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_8 : (sint32)(uint16)tmp_8));

  /* DataTypeConversion: '<S1>/Data Type Conversion461' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion108'
   */
  tmp_7 = fmodf(floorf(vold_pmpEP3TgtSpd_pct), 65536.0F);

  /* Outport generated from: '<Root>/O_T_PIN28_Duty' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion461'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN28_Duty_O_T_PIN28_Duty((uint16)(tmp_7 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_7 : (sint32)(uint16)tmp_7));

  /* Outport generated from: '<Root>/O_T_PIN14_Period' incorporates:
   *  Constant: '<S1>/Constant9'
   *  DataTypeConversion: '<S1>/Data Type Conversion449'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN14_Period_O_T_PIN14_Period
    (volc_pmpTgtPeriod6_us);

  /* Outport generated from: '<Root>/O_T_PIN28_Period' incorporates:
   *  Constant: '<S1>/Constant12'
   *  DataTypeConversion: '<S1>/Data Type Conversion457'
   */
  Rte_IWrite_swc_VCOP_Step_O_T_PIN28_Period_O_T_PIN28_Period
    (volc_pmpTgtPeriod7_us);

  /* Outport generated from: '<Root>/st_ShtDown' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion451'
   */
  Rte_IWrite_swc_VCOP_Step_st_ShtDown_st_ShtDown(vold_st_ShtDown);

  /* Outport generated from: '<Root>/PMS_MHGV_PosSet_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion453'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN((uint8)(tmp_5
    < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_5 : (sint32)(uint8)tmp_5));

  /* Outport generated from: '<Root>/PMS_MHGV_EnableReq_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion455'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN
    (vold_VCU_ATS1Enable != 0);

  /* Outport generated from: '<Root>/PMS_MHGV_ReqMotorEmgyStop_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion145'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN
    (vold_waterValveTV1V3_V);

  /* Outport generated from: '<Root>/PMS_MHGV_ReqMotorOptRecovery_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion146'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN
    (vold_waterValveTV2V2_V);

  /* Outport generated from: '<Root>/PMS_FWFV_MoveEnable_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion158'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN
    (vold_VCU_ATS2Enable != 0);

  /* Outport generated from: '<Root>/PMS_FWFV_ReqMovePos_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion159'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN
    ((uint8)(tmp_6 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_6 : (sint32)
             (uint8)tmp_6));

  /* Outport generated from: '<Root>/PMS_TBOX_HVILState_3A1' */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1
    (swc_VCOP_ConstB.PMS_TBOX_HVILState_3A1);

  /* Outport generated from: '<Root>/PMS_AppSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion485'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AppSts_PMS_AppSts((uint8)vold_VCU_AppSts);

  /* Outport generated from: '<Root>/PMS_HVIL1Sts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion475'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HVIL1Sts_PMS_HVIL1Sts(vold_PMS_HVIL1Sts_EV);

  /* Outport generated from: '<Root>/PMS_HVIL1Sts_UB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion477'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB(vold_PMS_HVIL1Sts_UB);

  /* Outport generated from: '<Root>/PMS_HVIL2Sts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion479'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HVIL2Sts_PMS_HVIL2Sts(vold_PMS_HVIL2Sts_EV);

  /* Outport generated from: '<Root>/PMS_HVIL2Sts_UB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion481'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB(vold_PMS_HVIL2Sts_UB);

  /* Outport generated from: '<Root>/PMS_SelfCheckSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion487'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SelfCheckSts_PMS_SelfCheckSts
    (vold_VCU_SelfCheckSts);

  /* Outport generated from: '<Root>/PMS_CurrentGearPosition_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV
    (swc_VCOP_ConstB.PMS_CurrentGearPosition_EV);

  /* Outport generated from: '<Root>/PMS_CurrentGearPosition_Valid_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV
    (swc_VCOP_ConstB.PMS_CurrentGearPosition_Val);

  /* Outport generated from: '<Root>/PMS_HVILSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion493'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HVILSts_PMS_HVILSts(vold_PMS_HVILSts_EV);

  /* Outport generated from: '<Root>/PMS_HVILSts_UB' */
  Rte_IWrite_swc_VCOP_Step_PMS_HVILSts_UB_PMS_HVILSts_UB
    (swc_VCOP_ConstB.PMS_HVILSts_UB_EV);

  /* Outport generated from: '<Root>/PMS_DriveCircuitTemp_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV
    (swc_VCOP_ConstB.EDCP_FltLevel);

  /* Outport generated from: '<Root>/PMS_EDCPEnable_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV
    (swc_VCOP_ConstB.PMS_EDCPEnable_EV);

  /* Outport generated from: '<Root>/PMS_EDCPPWMCtrl_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV
    (swc_VCOP_ConstB.PMS_EDCPPWMCtrl_EV);

  /* DataTypeConversion: '<S1>/Data Type Conversion503' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion143'
   *  Inport generated from: '<Root>/vcib_VCIP_in115'
   */
  tmp_5 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_i_dcdcInpCurr_A() /
                       0.1F), 256.0F);

  /* Outport generated from: '<Root>/VCU_DCInputCurrent' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion503'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_DCInputCurrent_VCU_DCInputCurrent((uint8)(tmp_5 <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_5 : (sint32)(uint8)tmp_5));

  /* Outport generated from: '<Root>/PMS_ThermalReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion505'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ThermalReq_PMS_ThermalReq(vold_PMS_ThermalReq);

  /* Outport generated from: '<Root>/PMS_IsgActvDampgModReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion511'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq
    (vold_PMS_IsgActvDampgModReq);

  /* Outport generated from: '<Root>/PMS_IgnONSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion517'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IgnONSts_PMS_IgnONSts(vold_VCU_IgnONSts);

  /* DataTypeConversion: '<S1>/Data Type Conversion519' */
  tmp_5 = fmodf(floorf(vold_VCU_ACC1PosVol / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/PMS_ACC1PosVol' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion519'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ACC1PosVol_PMS_ACC1PosVol((uint8)(tmp_5 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_5 : (sint32)(uint8)tmp_5));

  /* DataTypeConversion: '<S1>/Data Type Conversion521' */
  tmp_5 = fmodf(floorf(vold_VCU_ACC2PosVol / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/PMS_ACC2PosVol' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion521'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ACC2PosVol_PMS_ACC2PosVol((uint8)(tmp_5 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_5 : (sint32)(uint8)tmp_5));

  /* DataTypeConversion: '<S1>/Data Type Conversion523' */
  tmp_5 = fmodf(floorf(vold_VCU_BatteryVol * 2.0F), 256.0F);

  /* Outport generated from: '<Root>/PMS_BatteryVol' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion523'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BatteryVol_PMS_BatteryVol((uint8)(tmp_5 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_5 : (sint32)(uint8)tmp_5));

  /* Outport generated from: '<Root>/PMS_HVPRASts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion525'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HVPRASts_PMS_HVPRASts((uint8)vold_VCU_HVPRASts);

  /* Outport generated from: '<Root>/PMS_AppSts_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion485'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AppSts_EV_PMS_AppSts_EV((uint8)vold_VCU_AppSts);

  /* Outport generated from: '<Root>/PMS_HBCP_PWMCtrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion529'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl((uint8)(tmp_0 <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* Outport generated from: '<Root>/PMS_ChargWakeupSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion531'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ChargWakeupSts_PMS_ChargWakeupSts
    (vold_VCU_ChargWakeupSts);

  /* DataTypeConversion: '<S1>/Data Type Conversion533' */
  tmp_0 = fmodf(floorf(vold_VCU_MCU_PumpPWM_Ctrl / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_EDCP_PWMCtrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion533'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl((uint8)(tmp_0 <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* Outport generated from: '<Root>/PMS_HBCP_FaultFB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion535'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB((uint8)
    ((vold_VCU_HVB_PumpFb * 5U) >> 1));

  /* Outport generated from: '<Root>/PMS_EDCP_FaultFB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion537'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB((uint8)
    ((vold_VCU_Cabin_PumpFb * 5U) >> 1));

  /* Outport generated from: '<Root>/PMS_BattPackInCoolTempback_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV
    (swc_VCOP_ConstB.PMS_BattPackInCoolTempback_);

  /* Outport generated from: '<Root>/PMS_BattPackOutCoolTempback_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV
    (swc_VCOP_ConstB.PMS_BattPackOutCoolTempback);

  /* DataTypeConversion: '<S1>/Data Type Conversion545' */
  tmp_0 = fmodf(floorf(vold_VCU_ATS1_PWMRequest / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_FAN_PWMCtrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion545'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl((uint8)(tmp_0 < 0.0F ?
    (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* Outport generated from: '<Root>/PMS_DDwaterPump_PWMCtrl_EV' */
  Rte_IWrite_swc_VCOP_Step_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV
    (swc_VCOP_ConstB.PMS_DDwaterpump_PWMCtrl_EV);

  /* DataTypeConversion: '<S1>/Data Type Conversion551' */
  tmp_0 = fmodf(floorf(vold_VCU_VehicleSpd / 0.05625F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_VehicleSpeed' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion551'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VehicleSpeed_PMS_VehicleSpeed((uint16)(tmp_0 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_0 : (sint32)(uint16)tmp_0));

  /* Outport generated from: '<Root>/PMS_CPSREn' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion553'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CPSREn_PMS_CPSREn(vold_b_CpsrCtrl);

  /* Outport generated from: '<Root>/PMS_VehicleSpeedInvalid_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion557'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV
    (vold_VCU_VehicleSpd_flag);

  /* Outport generated from: '<Root>/PMS_MCUTemp_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion559'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MCUTemp_EV_PMS_MCUTemp_EV((uint8)
    (vold_VCU_DriveCircuitTemp + 40));

  /* Outport generated from: '<Root>/BMSH_TempSensor_TotalNum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion613'
   *  Inport generated from: '<Root>/vcib_VCIP_in184'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbTempSum());

  /* DataTypeConversion: '<S1>/Data Type Conversion515' */
  tmp_0 = fmodf(floorf(vold_PMS_MCUFlowFeedback_EV * 2.0F), 256.0F);

  /* Outport generated from: '<Root>/PMS_MCUFlowFeedback_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion515'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV((uint8)
    (tmp_0 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_0 : (sint32)(uint8)tmp_0));

  /* DataTypeConversion: '<S1>/Data Type Conversion736' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in204'
   */
  tmp_0 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_ang_strWhlAng_rad()
                       / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_EPS_SteeringAngleValue' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion736'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue
    ((sint16)(tmp_0 < 0.0F ? (sint32)(sint16)-(sint16)(uint16)-tmp_0 : (sint32)
              (sint16)(uint16)tmp_0));

  /* Outport generated from: '<Root>/PMS_EPS_SteeringAngleValueInvalid' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion738'
   *  Inport generated from: '<Root>/vcib_VCIP_in202'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_epsEpasFail() != 0);

  /* Outport generated from: '<Root>/PMS_DischargeEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion615'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DischargeEnable_PMS_DischargeEnable
    (vold_VCU_DischargeEnable);

  /* Outport generated from: '<Root>/PMS_0X16A_TimeoutFlag' */
  Rte_IWrite_swc_VCOP_Step_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag
    (swc_VCOP_ConstB.PMS_0X16A_TimeoutFlag_EV);

  /* Outport generated from: '<Root>/PMS_StsBrkSwitch1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion629'
   *  DataTypeConversion: '<S1>/Data Type Conversion630'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1
    (vold_VCU_BrakSwitchSts != 0);

  /* Outport generated from: '<Root>/PMS_SwapAuthRelease_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion509'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV
    (vold_PMS_StsBatLockSensor);

  /* Outport generated from: '<Root>/PMS_StsSwap' */
  Rte_IWrite_swc_VCOP_Step_PMS_StsSwap_PMS_StsSwap(swc_VCOP_ConstB.EDCP_State);

  /* Outport generated from: '<Root>/PMS_IPK_HandBrakeSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion742'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts
    (vold_VCU_HandbrakeSts2 != 0);

  /* DataTypeConversion: '<S1>/Data Type Conversion744' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion39'
   *  Inport generated from: '<Root>/vcib_VCIP_in23'
   */
  tmp_0 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() /
                       0.1F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_BMSH_BattSOCDisp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion744'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp((uint16)
    (tmp_0 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_0 : (sint32)(uint16)
     tmp_0));

  /* Outport generated from: '<Root>/PMS_PEPS_PowerModeValidity' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion752'
   *  Inport generated from: '<Root>/vcib_VCIP_in205'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_pepsPduLvlVld());

  /* Outport generated from: '<Root>/PMS_PEPS_PowerMode' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion15'
   *  Inport generated from: '<Root>/vcib_VCIP_in16'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_pepsPduLvl());

  /* Outport generated from: '<Root>/PMS_PEPS_0x1E2_TimeoutFlag' */
  Rte_IWrite_swc_VCOP_Step_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag
    (swc_VCOP_ConstB.PMS_PEPS_0x1E2_TimeoutFlag_);

  /* DataTypeConversion: '<S1>/Data Type Conversion746' */
  tmp_0 = fmodf(floorf(rtb_DataTypeConversion138 / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_BMSH_BattSOH' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion746'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH((uint16)(tmp_0 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_0 : (sint32)(uint16)tmp_0));

  /* Outport generated from: '<Root>/PMS_BMSH_BattRemainEnergy' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion748'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy
    ((uint16)(tmp_2 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)
              (uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion59' */
  tmp_2 = fmodf(floorf(vold_VCU_DTE), 65536.0F);

  /* Outport generated from: '<Root>/BMSH_ICU_BatteryElectricDTE' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion59'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE
    ((uint16)(tmp_2 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)
              (uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion513' */
  tmp_2 = fmodf(floorf(vold_VCU_PMS_APPowerActual_EV / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/VCU_PMS_APPowerActual' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion513'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual((uint8)
    (tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* Outport generated from: '<Root>/PMS_DcDc1ActvdReq_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion565'
   *  DataTypeConversion: '<S1>/Data Type Conversion566'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV
    (vold_VCU_12VDCDCEnableOut != 0);

  /* Outport generated from: '<Root>/PMS_Wakeup_reasons' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion527'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Wakeup_reasons_PMS_Wakeup_reasons
    (vold_VCU_Wakeup_reasons);

  /* Outport generated from: '<Root>/PMS_NMSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion561'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_NMSts_PMS_NMSts(vold_VCU_NMSts);

  /* Outport generated from: '<Root>/PMS_Stayawake_reasons' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion563'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Stayawake_reasons_PMS_Stayawake_reasons
    (vold_VCU_Stayawake_reasons);

  /* Outport generated from: '<Root>/PMS_BMS_Reignstatus1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion609'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1
    (vold_PMS_BMS_Reignstatus1);

  /* Outport generated from: '<Root>/PMS_BMS_Reignstatus2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion612'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2
    (vold_PMS_BMS_Reignstatus2);

  /* Outport generated from: '<Root>/PMS_ChargeLimitResponse' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion567'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse
    (vold_PMS_ChargeLimitResponse);

  /* DataTypeConversion: '<S1>/Data Type Conversion569' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in164'
   */
  tmp_2 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_R_posInsIRes_Ohm()),
                65536.0F);

  /* Outport generated from: '<Root>/BMSH_InsulationRes' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion569'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_InsulationRes_BMSH_InsulationRes((uint16)(tmp_2 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion571' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in165'
   */
  tmp_2 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_u_busInv2HVAct_V()
                       / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/IPU_HVBusVolt_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion571'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT((uint16)(tmp_2 <
    0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion573' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in166'
   */
  tmp_2 = fmodf(floorf
                ((Rte_IRead_swc_VCOP_Step_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A()
                  + 1000.0F) / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/IPU_HVBusCur_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion573'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_HVBusCur_PT_IPU_HVBusCur_PT((uint16)(tmp_2 < 0.0F
    ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/BMS_MaxVoltCellNum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion575'
   *  Inport generated from: '<Root>/vcib_VCIP_in169'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbCellMaxID());

  /* Outport generated from: '<Root>/BMS_MinVoltCellNum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion577'
   *  Inport generated from: '<Root>/vcib_VCIP_in167'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_MinVoltCellNum_BMS_MinVoltCellNum
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbCellMinID());

  /* DataTypeConversion: '<S1>/Data Type Conversion579' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in168'
   */
  tmp_2 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_BmsMaxCellVolt_V
                       () / 0.001F), 65536.0F);

  /* Outport generated from: '<Root>/BMS_MaxCellVolt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion579'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_MaxCellVolt_BMS_MaxCellVolt((uint16)(tmp_2 < 0.0F
    ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion581' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in172'
   */
  tmp_2 = fmodf(floorf(Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_u_BmsMinCellVolt_V
                       () / 0.001F), 65536.0F);

  /* Outport generated from: '<Root>/BMS_MinCellVolt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion581'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_MinCellVolt_BMS_MinCellVolt((uint16)(tmp_2 < 0.0F
    ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/BMS_MaxTemp1SnsNum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion583'
   *  Inport generated from: '<Root>/vcib_VCIP_in170'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbMaxTempID());

  /* Outport generated from: '<Root>/BMS_MinxTemp1SnsNum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion585'
   *  Inport generated from: '<Root>/vcib_VCIP_in171'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_num_hvbMinTempID());

  /* Outport generated from: '<Root>/BMSH_Over_SOC' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion587'
   *  Inport generated from: '<Root>/vcib_VCIP_in175'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Over_SOC_BMSH_Over_SOC
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrSoc2());

  /* Outport generated from: '<Root>/BMSH_SOC_Hop' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion589'
   *  Inport generated from: '<Root>/vcib_VCIP_in173'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_SOC_Hop_BMSH_SOC_Hop
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbSocJumpFlt() != 0);

  /* Outport generated from: '<Root>/BMSH_Low_SOC' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion591'
   *  Inport generated from: '<Root>/vcib_VCIP_in174'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Low_SOC_BMSH_Low_SOC
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batLowSoc2());

  /* Outport generated from: '<Root>/BMSH_CellTemp_Uniformity' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion593'
   *  Inport generated from: '<Root>/vcib_VCIP_in176'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbCellTempDevFlt() != 0);

  /* Outport generated from: '<Root>/BMSH_Cell_UnderVol' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion595'
   *  Inport generated from: '<Root>/vcib_VCIP_in177'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellUdrVolt2());

  /* Outport generated from: '<Root>/BMSH_Cell_OverVol' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion597'
   *  Inport generated from: '<Root>/vcib_VCIP_in178'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Cell_OverVol_BMSH_Cell_OverVol
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellOverVolt2());

  /* Outport generated from: '<Root>/BMSH_Pack_UnderVoltage' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion599'
   *  Inport generated from: '<Root>/vcib_VCIP_in179'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batUdrVolt2());

  /* Outport generated from: '<Root>/BMSH_Pack_OverVoltage' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion601'
   *  Inport generated from: '<Root>/vcib_VCIP_in180'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrVolt2());

  /* Outport generated from: '<Root>/BMSH_Over_Temperature' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion603'
   *  Inport generated from: '<Root>/vcib_VCIP_in181'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_Over_Temperature_BMSH_Over_Temperature
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbTempFlt());

  /* Outport generated from: '<Root>/BMSH_CellVolt_Uniformity' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion605'
   *  Inport generated from: '<Root>/vcib_VCIP_in182'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbCellVoltDevFlt());

  /* Outport generated from: '<Root>/IPU_IPUTAlm' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion607'
   *  Inport generated from: '<Root>/vcib_VCIP_in183'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_IPUTAlm_IPU_IPUTAlm
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_eadInv2TempHiAlrm() != 0);

  /* Outport generated from: '<Root>/PMS_StsBrkSwitch1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion625'
   *  DataTypeConversion: '<S1>/Data Type Conversion626'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS
    (vold_VCU_BrakSwitchSts != 0);

  /* Outport generated from: '<Root>/PMS_StsBrkSwitch1Invalid_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion631'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS
    (vold_VCU_StsBrkSwitch1Invalid);

  /* Outport generated from: '<Root>/PMS_LockVehPerFlag' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion786'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LockVehPerFlag_PMS_LockVehPerFlag
    (vold_PMS_LockVehPerFlag);

  /* Outport generated from: '<Root>/PMS_VersionConversionFlag' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion788'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VersionConversionFlag_PMS_VersionConversionFlag
    (vold_PMS_VersionConversionFlag);

  /* Outport generated from: '<Root>/PMS_SpdLmtLevel' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion791'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SpdLmtLevel_PMS_SpdLmtLevel(vold_PMS_SpdLmtLevel);

  /* Outport generated from: '<Root>/PMS_InventorySpdLmtSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion776'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts
    (vold_PMS_InventorySpdLmtSts);

  /* Outport generated from: '<Root>/PMS_Life' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion792'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Life_PMS_Life(vold_PMS_Life);

  /* Outport generated from: '<Root>/ODP_TBOX_TDcDcAlm' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion660'
   *  Inport generated from: '<Root>/vcib_VCIP_in192'
   */
  Rte_IWrite_swc_VCOP_Step_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcTempAlm());

  /* Outport generated from: '<Root>/ODP_TBOX_DcDcStsAlm' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion662'
   *  Inport generated from: '<Root>/vcib_VCIP_in193'
   */
  Rte_IWrite_swc_VCOP_Step_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcStsAlm());

  /* Outport generated from: '<Root>/IPU_MotorTempHighFault1_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion664'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT
    (vold_IPU_MotorTempHighFault1);

  /* Outport generated from: '<Root>/IPU_MCUTempHighAlarm1_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion666'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT
    (vold_IPU_MCUTempHighAlarm1);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatTempUniformity2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion668'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT
    (vold_BMSH_TBOX_BatTempUniformity2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverSOC2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion670'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT
    (vold_BMSH_TBOX_BatOverSOC2);

  /* Outport generated from: '<Root>/BMSH_TBOX_SOCHop2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion672'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT
    (vold_BMSH_TBOX_SOCHop2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatLowSOC2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion674'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT
    (vold_BMSH_TBOX_BatLowSOC2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverCharge2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion676'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT
    (vold_BMSH_TBOX_BatOverCharge2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatUniformity2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion678'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT
    (vold_BMSH_TBOX_BatUniformity2);

  /* Outport generated from: '<Root>/BMSH_TBOX_CellUnderVoltage2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion680'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT
    (vold_BMSH_TBOX_CellUnderVoltage2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatUnderVoltage2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion682'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT
    (vold_BMSH_TBOX_BatUnderVoltage2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverTemp2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion684'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT
    (vold_BMSH_TBOX_BatOverTemp2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatIsoAlarm2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion686'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT
    (vold_BMSH_TBOX_BatIsoAlarm2);

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverVoltage2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion688'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT
    (vold_BMSH_TBOX_BatOverVoltage2);

  /* Outport generated from: '<Root>/BMSH_TBOX_CellOverVoltage2_PT' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion690'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT
    (vold_BMSH_TBOX_CellOverVoltage2);

  /* Outport generated from: '<Root>/BMS_BattPackMatchFault' */
  Rte_IWrite_swc_VCOP_Step_BMS_BattPackMatchFault_BMS_BattPackMatchFault
    (swc_VCOP_ConstB.BMS_BattPackMatchFault_PMS);

  /* Outport generated from: '<Root>/PMS_TBOX_BrkSysErr' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport generated from: '<Root>/vcib_VCIP_in10'
   *  RelationalOperator: '<S2>/Compare'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ehbBrkSysErrFlt() != ((uint8)0U));

  /* Outport generated from: '<Root>/PMS_TBOX_HVILSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion767'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts
    (vold_PMS_TBOX_HVILState);

  /* Outport generated from: '<Root>/PMS_StsBrkSwitch1Invalid' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion627'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid
    (vold_VCU_StsBrkSwitch1Invalid);

  /* Outport generated from: '<Root>/PMS_AccessoryCtrlCommand' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion759'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand
    (vold_PMS_AccessoryCtrlCommand);

  /* Outport generated from: '<Root>/PMS_PTC2Enable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion623'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTC2Enable_PMS_PTC2Enable(vold_VCU_PTC2Enable);

  /* Outport generated from: '<Root>/PMS_PTC3Enable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion621'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTC3Enable_PMS_PTC3Enable(vold_VCU_PTC3Enable);

  /* Outport generated from: '<Root>/PMS_BatCoolType' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion773'
   *  Inport generated from: '<Root>/vcib_VCIP_in18'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BatCoolType_PMS_BatCoolType
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_flgFctCfgBatCol());

  /* Outport generated from: '<Root>/PMS_ZeroPwr_Fb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion619'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb(vold_VCU_ZeroPwr_Fb);

  /* Outport generated from: '<Root>/PMS_DisChrgrSwtSt' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion23'
   *  Inport generated from: '<Root>/vcib_VCIP_in40'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_disChgSwtSt());

  /* Outport generated from: '<Root>/PMS_CruisingDstSwtFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion756'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb
    (vold_PMS_CruisingDstSwtFb);

  /* Outport generated from: '<Root>/PMS_EngRecMode_Fb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion617'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb
    (vold_VCU_ePTRegencyLevInd);

  /* Outport generated from: '<Root>/PMS_DCDCAwake_HW' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion633'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW(vold_b_CpsrCtrl);

  /* DataTypeConversion: '<S1>/Data Type Conversion765' */
  tmp_2 = fmodf(floorf(vold_VCU_HTCoolingFan1FB / 0.4F), 256.0F);

  /* Outport generated from: '<Root>/PMS_CoolingFanFaultFB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion765'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB((uint8)
    (tmp_2 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion5' */
  tmp_2 = fmodf(floorf(vold_VCU_ErrCode), 65536.0F);

  /* Outport generated from: '<Root>/PMS_ErrCode' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ErrCode_PMS_ErrCode((uint16)(tmp_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* DataTypeConversion: '<S1>/Data Type Conversion734' */
  tmp_2 = fmodf(floorf(vold_PMS_GrossComVehWeight / 10.0F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_GrossComVehWeight' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion734'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_GrossComVehWeight_PMS_GrossComVehWeight((uint16)
    (tmp_2 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)
     tmp_2));

  /* Outport generated from: '<Root>/EXT_PO_PWM_1_DutyCycle' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion108'
   *  DataTypeConversion: '<S1>/Data Type Conversion471'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle
    ((float32)(tmp_7 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_7 : (sint32)
               (uint16)tmp_7));

  /* Outport generated from: '<Root>/EXT_PO_PWM_2_DutyCycle' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion472'
   *  DataTypeConversion: '<S1>/Data Type Conversion473'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle
    ((float32)(tmp_8 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_8 : (sint32)
               (uint16)tmp_8));

  /* Outport generated from: '<Root>/EXT_PO_HVIL_1_DutyCycle' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion474'
   *  DataTypeConversion: '<S1>/Data Type Conversion637'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle
    ((float32)(tmp_9 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_9 : (sint32)
               (uint16)tmp_9));

  /* Outport generated from: '<Root>/EXT_DO_RELAY_LS_10' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion638'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10
    (vold_b_highSpdFanRlyReq);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_LS_9' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion640'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9
    (vold_b_motFanRlyReq);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_LS_12' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion642'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12
    (vold_b_cntnrPwrEna);

  /* Outport generated from: '<Root>/EXT_PO_PWM_4_DutyCycle' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion644'
   *  DataTypeConversion: '<S1>/Data Type Conversion645'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle
    ((float32)(tmp < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp : (sint32)
               (uint16)tmp));

  /* Outport generated from: '<Root>/EXT_DO_KEY_HS_05' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion646'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05(vold_b_CpsrCtrl);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_LS_7' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion648'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7(vold_b_CpsrCtrl);

  /* Outport generated from: '<Root>/EXT_PO_PWM_1_Period' incorporates:
   *  Constant: '<S1>/Constant12'
   *  DataTypeConversion: '<S1>/Data Type Conversion650'
   *  DataTypeConversion: '<S1>/Data Type Conversion651'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period((float32)
    volc_pmpTgtPeriod7_us);

  /* Outport generated from: '<Root>/EXT_PO_PWM_2_Period' incorporates:
   *  Constant: '<S1>/Constant9'
   *  DataTypeConversion: '<S1>/Data Type Conversion652'
   *  DataTypeConversion: '<S1>/Data Type Conversion653'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period((float32)
    volc_pmpTgtPeriod6_us);

  /* Outport generated from: '<Root>/EXT_PO_PWM_4_Period' incorporates:
   *  Constant: '<S1>/Constant3'
   *  DataTypeConversion: '<S1>/Data Type Conversion654'
   *  DataTypeConversion: '<S1>/Data Type Conversion655'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period((float32)
    volc_pmpTgtPeriod_us);

  /* Outport generated from: '<Root>/EXT_PO_HVIL_1_Period' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion656'
   *  DataTypeConversion: '<S1>/Data Type Conversion657'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period((float32)
    (tmp_a < 0.0F ? (uint32)-(sint32)(uint32)-tmp_a : (uint32)tmp_a));

  /* Outport generated from: '<Root>/EXT_DO_RELAY_HS_11' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion658'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11(vold_b_CpsrCtrl);

  /* Outport generated from: '<Root>/PMS_PTC1ConnStsFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion692'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb
    (vold_PMS_PTC1ConnStsFb);

  /* Outport generated from: '<Root>/PMS_PTC1RelayFlt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion694'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt
    (vold_PMS_PTC1RelayFlt);

  /* Outport generated from: '<Root>/PMS_PTC3ConnStsFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion696'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb
    (vold_PMS_PTC3ConnStsFb);

  /* Outport generated from: '<Root>/PMS_PTC3RelayFlt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion698'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt
    (vold_PMS_PTC3RelayFlt);

  /* Outport generated from: '<Root>/PMS_AccessoryConnStsFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion700'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb
    (vold_PMS_AccessoryConnStsFb);

  /* Outport generated from: '<Root>/PMS_AccessoryRelayFlt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion702'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt
    (vold_PMS_AccessoryRelayFlt);

  /* Outport generated from: '<Root>/PMS_PreAccessoryConnStsFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion704'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb
    (vold_PMS_PreAccessoryConnStsFb);

  /* Outport generated from: '<Root>/PMS_PreAccessoryRelayFlt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion706'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt
    (vold_PMS_PreAccessoryRelayFlt);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_HS_9' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion709'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9
    (vold_b_heaterEnaHW);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_HS_8' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion711'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8
    (vold_b_heater3EnaHW);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_HS_6' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion713'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6
    (vold_b_accyPreRlyCmd);

  /* Outport generated from: '<Root>/PMS_PTCRelayVoltSampSwich' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion708'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich
    (vold_PMS_PTCRelayVoltSampSwich);

  /* Outport generated from: '<Root>/PMS_AcceRelayVoltSampSwich' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion716'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich
    (vold_PMS_AcceRelayVoltSampSwich);

  /* Outport generated from: '<Root>/PMS_BBM_FaultStatus' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion718'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus
    (vold_PMS_BBM_FaultStatus);

  /* Outport generated from: '<Root>/PMS_BBM_WorkSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion720'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BBM_WorkSts_PMS_BBM_WorkSts(vold_PMS_BBM_WorkSts);

  /* Outport generated from: '<Root>/PMS_DrivingTakeEleSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion722'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts
    (vold_PMS_DrivingTakeEleSts);

  /* Outport generated from: '<Root>/PMS_BBMPowerSupplyEn_Ctrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2085'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl
    (vold_b_cntnrPwrEna);

  /* Outport generated from: '<Root>/O_S_PIN123' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1430'
   */
  Rte_IWrite_swc_VCOP_Step_O_S_PIN123_O_S_PIN123(vold_b_cntnrPwrEna);

  /* Outport generated from: '<Root>/O_S_PIN98' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion724'
   */
  Rte_IWrite_swc_VCOP_Step_O_S_PIN98_O_S_PIN98(vold_b_cntnrCtrlEna);

  /* Outport generated from: '<Root>/EXT_DO_KEY_HS_03' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion726'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03(vold_b_cntnrCtrlEna);

  /* Outport generated from: '<Root>/PMS_BBMAllowEnable_Ctrl' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion728'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl
    (vold_b_cntnrCtrlEna);

  /* Outport generated from: '<Root>/PMS_BBM1CtrlCmd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion730'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd(vold_VCU_ACCY1CtrlCmd);

  /* Outport generated from: '<Root>/PMS_BBM_HVReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion732'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_BBM_HVReq_PMS_BBM_HVReq(vold_VCU_ACCYEnableIn !=
    0);

  /* DataTypeConversion: '<S1>/Data Type Conversion48' */
  tmp_2 = fmodf(floorf(vold_VCU_TotalOdometer / 0.1F), 4.2949673E+9F);

  /* Outport generated from: '<Root>/IPK_IPKTotalOdometer_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion48'
   */
  Rte_IWrite_swc_VCOP_Step_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV(tmp_2
    < 0.0F ? (uint32)-(sint32)(uint32)-tmp_2 : (uint32)tmp_2);

  /* Outport generated from: '<Root>/VCU_BMSH_Inlet_WaterTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion761'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp
    ((uint8)(tmp_1 < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_1 : (sint32)
             (uint8)tmp_1));

  /* Outport generated from: '<Root>/VCU_BMSH_Outlet_WaterTemp' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion763'
   */
  Rte_IWrite_swc_VCOP_Step_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp
    ((uint8)(tmp_b < 0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_b : (sint32)
             (uint8)tmp_b));

  /* Outport generated from: '<Root>/PMS_LockVehPerRxSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion794'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts
    (vold_PMS_LockVehPerRxSts);

  /* Outport generated from: '<Root>/PMS_VersionConversionRxSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion778'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts
    (vold_PMS_VersionConversionRxSts);

  /* Outport generated from: '<Root>/PMS_SpdLmtLevelRxSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion782'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts
    (vold_PMS_SpdLmtLevelRxSts);

  /* Outport generated from: '<Root>/PMS_InventorySpdLmtRxSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion780'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts
    (vold_PMS_InventorySpdLmtRxSts);

  /* Outport generated from: '<Root>/PMS_TBOX_LifeSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion784'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts
    (vold_PMS_TBOX_LifeSts);

  /* DataTypeConversion: '<S1>/Data Type Conversion797' */
  tmp_2 = fmodf(floorf(vold_VCU_AEC / 0.01F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_AveragePowerConsumption' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion797'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption
    ((uint16)(tmp_2 < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)
              (uint16)tmp_2));

  /* Outport generated from: '<Root>/PMS_VINMessageNum_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion291'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINMessageNum_S_PMS_VINMessageNum_S
    (vold_PMS_VINMessageNum_S);

  /* Outport generated from: '<Root>/PMS_VINCode1_8_15_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion61'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S
    (vold_PMS_VINCode1_8_15_S);

  /* Outport generated from: '<Root>/PMS_VINCode2_9_16_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion205'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S
    (vold_PMS_VINCode2_9_16_S);

  /* Outport generated from: '<Root>/PMS_VINCode3_10_17_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion207'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S
    (vold_PMS_VINCode3_10_17_S);

  /* Outport generated from: '<Root>/PMS_VINCode4_11_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion209'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode4_11_S_PMS_VINCode4_11_S
    (vold_PMS_VINCode4_11_S);

  /* Outport generated from: '<Root>/PMS_VINCode5_12_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion285'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode5_12_S_PMS_VINCode5_12_S
    (vold_PMS_VINCode5_12_S);

  /* Outport generated from: '<Root>/PMS_VINCode6_13_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion287'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode6_13_S_PMS_VINCode6_13_S
    (vold_PMS_VINCode6_13_S);

  /* Outport generated from: '<Root>/PMS_VINCode7_14_S' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion289'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VINCode7_14_S_PMS_VINCode7_14_S
    (vold_PMS_VINCode7_14_S);

  /* Outport generated from: '<Root>/PMS_HardwareMajorVer' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion338'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HardwareMajorVer_PMS_HardwareMajorVer
    (vold_VCU_HardwareMajorVer);

  /* Outport generated from: '<Root>/PMS_HardwareMinorVer' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion337'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_HardwareMinorVer_PMS_HardwareMinorVer
    (vold_VCU_HardwareMinorVer);

  /* Outport generated from: '<Root>/PMS_SoftwareMajorVer' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion296'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer
    (vold_VCU_SoftwareMajorVer);

  /* Outport generated from: '<Root>/PMS_SoftwareMinorVer' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion295'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer
    (vold_VCU_SoftwareMinorVer);

  /* DataTypeConversion: '<S1>/Data Type Conversion297' */
  tmp_2 = fmodf(floorf(vold_PMS_IPKTotalOdometer / 0.01F), 4.2949673E+9F);
  u0 = tmp_2 < 0.0F ? (uint32)-(sint32)(uint32)-tmp_2 : (uint32)tmp_2;

  /* Saturate: '<S1>/Saturation' */
  if (u0 > 268435456U) {
    u0 = 268435456U;
  }

  /* Outport generated from: '<Root>/PMS_IPKTotalOdometer' incorporates:
   *  Saturate: '<S1>/Saturation'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer(u0);

  /* Outport generated from: '<Root>/PMS_OdometerbackupEnable' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion299'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable
    (vold_PMS_OdometerbackupEnable);

  /* Outport generated from: '<Root>/PMS_PowerOffCmdSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion50'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts
    (vold_PMS_PowerOffCmdSts);

  /* Outport generated from: '<Root>/PMS_PowerOffCmdRxSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion53'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts
    (vold_PMS_PowerOffCmdRxSts);

  /* Outport generated from: '<Root>/PMS_Brake1Switch' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion56'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Brake1Switch_PMS_Brake1Switch(vold_VCU_Brake1Sts);

  /* Outport generated from: '<Root>/PMS_Brake2Switch' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion635'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Brake2Switch_PMS_Brake2Switch(vold_VCU_Brake2Sts);

  /* Outport generated from: '<Root>/TBOX_ChrgSoftSwCtrlst_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion341'
   */
  Rte_IWrite_swc_VCOP_Step_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV
    (vold_TBOX_ChrgSoftSwCtrlst);

  /* Outport generated from: '<Root>/PMS_LockVehExecutedSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion343'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts
    (vold_PMS_LockVehExecutedSts);

  /* Outport generated from: '<Root>/PMS_RemChrgCmdFailrPrompt' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion339'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt
    (vold_PMS_RemChrgCmdFailrPrompt);

  /* Outport generated from: '<Root>/TBOX_ReservationChrgnSts_EV' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion345'
   */
  Rte_IWrite_swc_VCOP_Step_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV
    (vold_TBOX_ReservationChrgnSts);

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion321'
   */
  Rte_IWrite_swc_VCOP_Step_vcob_VCOP_BMSH_ChargeLEDCtrl(vold_BMSH_ChargeLEDCtrl);

  /* DataTypeConversion: '<S1>/Data Type Conversion357' */
  tmp_2 = fmodf(floorf(vold_PMS_ChargPwr / 0.1F), 65536.0F);

  /* Outport generated from: '<Root>/PMS_ChargPwr' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion357'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ChargPwr_PMS_ChargPwr((uint16)(tmp_2 < 0.0F ?
    (sint32)(uint16)-(sint16)(uint16)-tmp_2 : (sint32)(uint16)tmp_2));

  /* Outport generated from: '<Root>/AC_EWP_SpeedReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion800'
   */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_SpeedReq_AC_EWP_SpeedReq(vold_AC_EWP_SpeedReq);

  /* Outport generated from: '<Root>/AC_EWP_SpeedReq_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion800'
   */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN
    (vold_AC_EWP_SpeedReq);

  /* Outport generated from: '<Root>/AC_EWP_Heat' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion802'
   */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_Heat_AC_EWP_Heat(vold_AC_EWP_Heat);

  /* Outport generated from: '<Root>/AC_EWP_Heat_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion802'
   */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN(vold_AC_EWP_Heat);

  /* Outport generated from: '<Root>/AC_EWP_Temp' */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_Temp_AC_EWP_Temp(rtb_DataTypeConversion154);

  /* Outport generated from: '<Root>/AC_EWP_Temp_LIN' */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN
    (rtb_DataTypeConversion154);

  /* Outport generated from: '<Root>/AC_EWP_Run' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion366'
   */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_Run_AC_EWP_Run(vold_AC_EWP_Run);

  /* Outport generated from: '<Root>/AC_EWP_Run_LIN' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion366'
   */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_Run_LIN_AC_EWP_Run_LIN(vold_AC_EWP_Run);

  /* Outport generated from: '<Root>/AC_EWP_HeatrPwrCnsAllwd' */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd
    (rtb_DataTypeConversion265);

  /* Outport generated from: '<Root>/AC_EWP_HeatrPwrCnsAllwd_LIN' */
  Rte_IWrite_swc_VCOP_Step_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN
    (rtb_DataTypeConversion265);

  /* Outport generated from: '<Root>/PMS_VehicleSysErrorLevelG' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion813'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG
    (vold_PMS_VehicleSysErrorLevelG);

  /* Outport generated from: '<Root>/PMS_Torque_Ovrd_Active' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion803'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active
    (vold_PMS_Torque_Ovrd_Active);

  /* Outport generated from: '<Root>/PMS_Torque_Ovrd_Type' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion816'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type
    (vold_PMS_Torque_Ovrd_Type);

  /* Outport generated from: '<Root>/PMS_VehicleSpeedInvalid_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion818'
   *  DataTypeConversion: '<S1>/Data Type Conversion819'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS
    (vold_VCU_VehicleSpd_flag);

  /* Outport generated from: '<Root>/PMS_RegulationSpeed_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion804'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS
    (vold_PMS_RegulationSpeed);

  /* Outport generated from: '<Root>/PMS_AcceSuppressionSts_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion806'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS
    (vold_PMS_AcceSuppressionSts);

  /* Outport generated from: '<Root>/PMS_TakeEleSwtIndReq' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion809'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq
    (vold_PMS_TakeEleSwtIndReq);

  /* DataTypeConversion: '<S1>/Data Type Conversion808' */
  tmp_2 = fmodf(floorf(vold_PMS_CPSRU * 2.0F), 256.0F);

  /* Outport generated from: '<Root>/PMS_CPSRU' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion808'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CPSRU_PMS_CPSRU((uint8)(tmp_2 < 0.0F ? (sint32)
    (uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* Outport generated from: '<Root>/PMS_Fn1GearRlyDrvStsFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion812'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb
    (vold_PMS_Fn1GearRlyDrvStsFb);

  /* Outport generated from: '<Root>/PMS_Fn2GearRlyDrvStsFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion821'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb
    (vold_PMS_Fn2GearRlyDrvStsFb);

  /* Outport generated from: '<Root>/PMS_CampModeFb' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion544'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CampModeFb_PMS_CampModeFb(vold_PMS_CampModeFb);

  /* Outport generated from: '<Root>/PMS_CampModeFbFailrReason' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion543'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason
    (vold_PMS_CampModeFbFailrReason);

  /* Outport generated from: '<Root>/EXT_DO_RELAY_LS_5' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion825'
   */
  Rte_IWrite_swc_VCOP_Step_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5
    (vold_b_VacPumpRlyEn);

  /* DataTypeConversion: '<S1>/Data Type Conversion827' */
  tmp_2 = fmodf(floorf(vold_PMS_VacuumPump_FB * 2.0F), 256.0F);

  /* Outport generated from: '<Root>/PMS_VacuumPump_FB' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion827'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VacuumPump_FB_PMS_VacuumPump_FB((uint8)(tmp_2 <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* Outport generated from: '<Root>/PMS_VacuumPumpCmd' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion825'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd
    (vold_b_VacPumpRlyEn);

  /* Outport generated from: '<Root>/PMS_Brake_LightsRequest' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion549'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest
    (vold_PMS_Brake_LightsRequest);

  /* DataTypeConversion: '<S1>/Data Type Conversion555' */
  tmp_2 = fmodf(floorf((vold_PMS_Acceleration + 12.5F) / 0.1F), 256.0F);

  /* Outport generated from: '<Root>/PMS_Acceleration' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion555'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_Acceleration_PMS_Acceleration((uint8)(tmp_2 <
    0.0F ? (sint32)(uint8)-(sint8)(uint8)-tmp_2 : (sint32)(uint8)tmp_2));

  /* Outport generated from: '<Root>/PMS_TurtleLampOn2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion115'
   *  DataTypeConversion: '<S1>/Data Type Conversion116'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TurtleLampOn2_PMS_TurtleLampOn2
    (vold_VCU_TurtleLampReq != 0);

  /* Outport generated from: '<Root>/PMS_ePTFault2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion117'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_ePTFault2_PMS_ePTFault2(vold_PMS_ePTFault);

  /* Outport generated from: '<Root>/PMS_TBOX_BrkSysErr1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion867'
   *  DataTypeConversion: '<S1>/Data Type Conversion868'
   *  Inport generated from: '<Root>/vcib_VCIP_in10'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ehbBrkSysErrFlt());

  /* Outport generated from: '<Root>/PMS_TBOX_HVILSts1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion869'
   *  DataTypeConversion: '<S1>/Data Type Conversion870'
   *  Inport generated from: '<Root>/vcib_VCIP_in4'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_hvbd_b_hvilOpen());

  /* Outport generated from: '<Root>/ODP_TBOX_DcDcStsAlm1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion865'
   *  DataTypeConversion: '<S1>/Data Type Conversion866'
   *  Inport generated from: '<Root>/vcib_VCIP_in193'
   */
  Rte_IWrite_swc_VCOP_Step_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcStsAlm());

  /* Outport generated from: '<Root>/ODP_TBOX_TDcDcAlm1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion863'
   *  DataTypeConversion: '<S1>/Data Type Conversion864'
   *  Inport generated from: '<Root>/vcib_VCIP_in192'
   */
  Rte_IWrite_swc_VCOP_Step_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_b_dcdcTempAlm());

  /* Outport generated from: '<Root>/BMSH_TBOX_CellOverVoltage3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion861'
   *  DataTypeConversion: '<S1>/Data Type Conversion862'
   *  Inport generated from: '<Root>/vcib_VCIP_in178'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellOverVolt2());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverVoltage3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion859'
   *  DataTypeConversion: '<S1>/Data Type Conversion860'
   *  Inport generated from: '<Root>/vcib_VCIP_in180'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrVolt2());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverTemp3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion857'
   *  DataTypeConversion: '<S1>/Data Type Conversion858'
   *  Inport generated from: '<Root>/vcib_VCIP_in181'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbTempFlt());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatUnderVoltage3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion855'
   *  DataTypeConversion: '<S1>/Data Type Conversion856'
   *  Inport generated from: '<Root>/vcib_VCIP_in179'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batUdrVolt2());

  /* Outport generated from: '<Root>/BMSH_TBOX_CellUnderVoltage3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion853'
   *  DataTypeConversion: '<S1>/Data Type Conversion854'
   *  Inport generated from: '<Root>/vcib_VCIP_in177'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_cellUdrVolt2());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatUniformity3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion851'
   *  DataTypeConversion: '<S1>/Data Type Conversion852'
   *  Inport generated from: '<Root>/vcib_VCIP_in197'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbBatUniformity());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverCharge3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion849'
   *  DataTypeConversion: '<S1>/Data Type Conversion850'
   *  Inport generated from: '<Root>/vcib_VCIP_in195'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbOvrChgFlt());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatLowSOC3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion847'
   *  DataTypeConversion: '<S1>/Data Type Conversion848'
   *  Inport generated from: '<Root>/vcib_VCIP_in174'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batLowSoc2());

  /* Outport generated from: '<Root>/BMSH_TBOX_SOCHop3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion845'
   *  DataTypeConversion: '<S1>/Data Type Conversion846'
   *  Inport generated from: '<Root>/vcib_VCIP_in173'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbSocJumpFlt());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatOverSOC3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion843'
   *  DataTypeConversion: '<S1>/Data Type Conversion844'
   *  Inport generated from: '<Root>/vcib_VCIP_in175'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_batOvrSoc2());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatTempUniformity3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion841'
   *  DataTypeConversion: '<S1>/Data Type Conversion842'
   *  Inport generated from: '<Root>/vcib_VCIP_in176'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_hvbCellTempDevFlt());

  /* Outport generated from: '<Root>/IPU_MCUTempHighAlarm2_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion839'
   *  DataTypeConversion: '<S1>/Data Type Conversion840'
   *  Inport generated from: '<Root>/vcib_VCIP_in196'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuInvTempHighAlm());

  /* Outport generated from: '<Root>/IPU_MotorTempHighFault2_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion837'
   *  DataTypeConversion: '<S1>/Data Type Conversion838'
   *  Inport generated from: '<Root>/vcib_VCIP_in194'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotTempHighFlt());

  /* Outport generated from: '<Root>/IPU_MotorOverCurrFlt1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion835'
   *  DataTypeConversion: '<S1>/Data Type Conversion836'
   *  Inport generated from: '<Root>/BusElementIn14'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotorOverCurrFlt());

  /* Outport generated from: '<Root>/IPU_MotorOverSpdFlt1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion833'
   *  DataTypeConversion: '<S1>/Data Type Conversion834'
   *  Inport generated from: '<Root>/BusElementIn13'
   */
  Rte_IWrite_swc_VCOP_Step_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_ipuMotorOverSpdFlt());

  /* Outport generated from: '<Root>/BMS_BattPackMatchFault1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion831'
   *  DataTypeConversion: '<S1>/Data Type Conversion832'
   *  Inport generated from: '<Root>/BusElementIn12'
   */
  Rte_IWrite_swc_VCOP_Step_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsBattPackMatchFlt());

  /* Outport generated from: '<Root>/BMSH_TBOX_FireAlarm2_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion829'
   *  DataTypeConversion: '<S1>/Data Type Conversion830'
   *  Inport generated from: '<Root>/BusElementIn11'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsTboxFireAlm());

  /* Outport generated from: '<Root>/BMSH_BattSysNum_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion871'
   *  DataTypeConversion: '<S1>/Data Type Conversion872'
   *  Inport generated from: '<Root>/BusElementIn15'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsBattSysNum());

  /* Outport generated from: '<Root>/BMSH_BattPackNum_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion873'
   *  DataTypeConversion: '<S1>/Data Type Conversion874'
   *  Inport generated from: '<Root>/BusElementIn16'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS
    (Rte_IRead_swc_VCOP_Step_vcib_VCIP_vild_st_bmsBattPackNum());

  /* Outport generated from: '<Root>/BMSH_TBOX_BatIsoAlarm3_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion875'
   *  DataTypeConversion: '<S1>/Data Type Conversion876'
   */
  Rte_IWrite_swc_VCOP_Step_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS
    (rtb_DataTypeConversion256);

  /* Outport generated from: '<Root>/PMS_32960FltNum_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion877'
   *  DataTypeConversion: '<S1>/Data Type Conversion878'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS
    (vold_PMS_32960FltNum);

  /* Outport generated from: '<Root>/PMS_VehicleSysErrorLevelG1_PMS' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion813'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS
    (vold_PMS_VehicleSysErrorLevelG);

  /* Outport generated from: '<Root>/PMS_OTAInstructRxnSts' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion879'
   *  DataTypeConversion: '<S1>/Data Type Conversion880'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts
    (vold_PMS_OTAInstructRxnSts);

  /* Outport generated from: '<Root>/PMS_OTAInstrucStsReminder' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion881'
   *  DataTypeConversion: '<S1>/Data Type Conversion882'
   */
  Rte_IWrite_swc_VCOP_Step_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder
    (vold_PMS_OTAInstrucStsReminder);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  swc_VCOP_M->Timing.clockTick0++;
}

/* Model initialize function */
void swc_VCOP_Init(void)
{
  {
    /* local block i/o variables */
    boolean rtb_flg_out_p;
    boolean rtb_flg_out_l;

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/VCO__Vehicle_Control_Outputs'
     */
    /* SystemInitialize for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/EAD_OutputsProcessingMot2'
     */
    EAD_OutputsProcessingMot2_Init();

    /* SystemInitialize for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/DSP_OutputsProcessing'
     */
    swc__DSP_OutputsProcessing_Init();

    /* SystemInitialize for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/SRU_OutputsProcessing'
     */
    /* SystemInitialize for Atomic SubSystem: '<S77>/turnOFF_delay' */
    /* SystemInitialize for Chart: '<S79>/timed_delay' */
    swc_VCOP_timed_delay_Init(&rtb_flg_out_l);

    /* End of SystemInitialize for SubSystem: '<S77>/turnOFF_delay' */

    /* SystemInitialize for Atomic SubSystem: '<S77>/turnOFF_delay1' */
    /* SystemInitialize for Chart: '<S80>/timed_delay' */
    swc_VCOP_timed_delay_Init(&rtb_flg_out_p);

    /* End of SystemInitialize for SubSystem: '<S77>/turnOFF_delay1' */
    /* End of SystemInitialize for S-Function (fcgen): '<S3>/Function-Call Generator' */
    /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

    /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/VCO__Vehicle_Control_Outputs'
     */
    /* Enable for S-Function (fcgen): '<S3>/Function-Call Generator' incorporates:
     *  SubSystem: '<S3>/SRU_OutputsProcessing'
     */
    /* Enable for Chart: '<S12>/Chart' */
    swc_VCOP_ARID_DEF.presentTicks = swc_VCOP_M->Timing.clockTick0;
    swc_VCOP_ARID_DEF.previousTicks = swc_VCOP_ARID_DEF.presentTicks;

    /* End of Enable for S-Function (fcgen): '<S3>/Function-Call Generator' */
    /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
