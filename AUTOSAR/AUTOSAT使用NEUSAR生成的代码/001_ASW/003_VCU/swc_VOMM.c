/*
 * File: swc_VOMM.c
 *
 * Code generated for Simulink model 'swc_VOMM'.
 *
 * Model version                  : 6.171
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 21 15:54:36 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_VOMM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef DRI_TASK_INTERVAL_S
#error The value of parameter "DRI_TASK_INTERVAL_S" is not defined
#endif

#ifndef PMM_TASK_INTERVAL_S
#error The value of parameter "PMM_TASK_INTERVAL_S" is not defined
#endif

#ifndef VSM_TASK_INTERVAL_S
#error The value of parameter "VSM_TASK_INTERVAL_S" is not defined
#endif

#ifndef PMM_NET_AFTERCHG
#error The value of parameter "PMM_NET_AFTERCHG" is not defined
#endif

#ifndef PMM_NET_AFTERRUN
#error The value of parameter "PMM_NET_AFTERRUN" is not defined
#endif

#ifndef PMM_NET_CHG
#error The value of parameter "PMM_NET_CHG" is not defined
#endif

#ifndef PMM_NET_OBC
#error The value of parameter "PMM_NET_OBC" is not defined
#endif

#ifndef PMM_NET_RUN
#error The value of parameter "PMM_NET_RUN" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S200>/timed_delay' */
#define swc_VOMM_IN_OFF                ((uint8)1U)
#define swc_VOMM_IN_OFF_WAIT           ((uint8)2U)
#define swc_VOMM_IN_ON                 ((uint8)3U)

/* Named constants for Chart: '<S14>/timed_delay' */
#define swc_VOMM_IN_OFF_l              ((uint8)1U)
#define swc_VOMM_IN_ON_WAIT            ((uint8)3U)
#define swc_VOMM_IN_ON_j               ((uint8)2U)

/* Named constants for Chart: '<S199>/timed_delay' */
#define swc_VOMM_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_VOMM_IN_OFF_WAIT_o         ((uint8)2U)
#define swc_VOMM_IN_OFF_c              ((uint8)1U)
#define swc_VOMM_IN_ON_f               ((uint8)3U)

/* Named constants for Chart: '<S209>/Chart' */
#define swc_VOMM_IN_FristWkUp          ((uint8)1U)
#define swc_VOMM_IN_init               ((uint8)2U)

/* Named constants for Chart: '<S209>/network_modes' */
#define swc_VOMM_IN_CANDisable         ((uint8)1U)
#define swc_VOMM_IN_NormalOperation    ((uint8)3U)
#define swc_VOMM_IN_SleepMode          ((uint8)4U)
#define swc_VOMM_IN_VCUSleepWait       ((uint8)5U)
#define swc_V_IN_NormalNMWakedOperation ((uint8)2U)

/* Named constants for Chart: '<S197>/pmm_power_modes' */
#define swc_VOMM_IN_AfterRun           ((uint8)1U)
#define swc_VOMM_IN_Charging           ((uint8)1U)
#define swc_VOMM_IN_Drive              ((uint8)2U)
#define swc_VOMM_IN_InactiveDrive      ((uint8)3U)
#define swc_VOMM_IN_InhibitDrive       ((uint8)4U)
#define swc_VOMM_IN_NoActiveReq        ((uint8)5U)
#define swc_VOMM_IN_Shutdown           ((uint8)2U)
#define swc_VOMM_IN_ShutdownWait       ((uint8)3U)

/* Named constants for Chart: '<S5>/VehicleStartManager' */
#define swc_VOMM_IN_START_COMPLETE     ((uint8)1U)
#define swc_VOMM_IN_START_DEMAND_LATCH ((uint8)2U)
#define swc_VOMM_IN_START_REQ          ((uint8)3U)
#define swc_VOMM_IN_VEHICLE_OFF        ((uint8)4U)

/* Named constants for Chart: '<S24>/BrakePedalPushFirst' */
#define swc_VOMM_IN_BrakePushed        ((uint8)1U)
#define swc_VOMM_IN_GearShifted        ((uint8)2U)
#define swc_VOMM_IN_InitialState       ((uint8)3U)

/* Named constants for Chart: '<S24>/GearLeverPosition' */
#define swc_VOMM_IN_DRIVE              ((uint8)1U)
#define swc_VOMM_IN_NEUTRAL            ((uint8)2U)
#define swc_VOMM_IN_PARKING            ((uint8)3U)
#define swc_VOMM_IN_REVERSE            ((uint8)4U)
#define swc_VOMM_IN_SPORT              ((uint8)5U)
#define swc_VOMM_IN_UNKNOWN            ((uint8)6U)

/* Named constants for Chart: '<S25>/EPBClsdReq' */
#define swc_VOMM_IN_EPBCLOSE           ((uint8)1U)
#define swc_VOMM_IN_EPBOPENTOCLOSE     ((uint8)2U)
#define swc_VOMM_IN_INIT               ((uint8)3U)
#define swc_VOMM_IN_OPEN               ((uint8)4U)

/* Named constants for Chart: '<S25>/GearLeverPosition' */
#define swc_VOMM_IN_DEFAULT            ((uint8)1U)
#define swc_VOMM_IN_DRIVE_h            ((uint8)2U)
#define swc_VOMM_IN_NEUTRAL_b          ((uint8)3U)
#define swc_VOMM_IN_PARKING_p          ((uint8)4U)
#define swc_VOMM_IN_REVERSE_l          ((uint8)5U)

/* Named constants for Chart: '<S134>/timed_delay' */
#define swc_VOMM_IN_OFF_h              ((uint8)1U)
#define swc_VOMM_IN_ON_WAIT_o          ((uint8)3U)
#define swc_VOMM_IN_ON_g               ((uint8)2U)

/* Named constants for Chart: '<S161>/DriverMode' */
#define swc_VOMM_IN_ECO                ((uint8)1U)
#define swc_VOMM_IN_INIT_j             ((uint8)2U)
#define swc_VOMM_IN_NORMAL             ((uint8)3U)
#define swc_VOMM_IN_SPORT_b            ((uint8)4U)

/* Named constants for Chart: '<S3>/Hybrid_Mode_Manager' */
#define swc_VOMM_IN_EV_MODE            ((uint8)1U)
#define swc_VOMM_IN_EV_TO_PHEV_TRANS   ((uint8)2U)
#define swc_VOMM_IN_EV_TO_PTENA_TRANS  ((uint8)3U)
#define swc_VOMM_IN_EV_TO_SHEV_TRANS   ((uint8)4U)
#define swc_VOMM_IN_ICE_MODE           ((uint8)5U)
#define swc_VOMM_IN_ICE_TO_PHEV_TRANS  ((uint8)6U)
#define swc_VOMM_IN_ICE_TO_PTENA_TRANS ((uint8)7U)
#define swc_VOMM_IN_PHEV_MODE          ((uint8)8U)
#define swc_VOMM_IN_PHEV_TO_EV_TRANS   ((uint8)9U)
#define swc_VOMM_IN_PHEV_TO_ICE_TRANS  ((uint8)10U)
#define swc_VOMM_IN_PHEV_TO_PTENA_TRANS ((uint8)11U)
#define swc_VOMM_IN_PHEV_TO_SHEV_TRANS ((uint8)12U)
#define swc_VOMM_IN_PTENA_TO_EV_TRANS  ((uint8)13U)
#define swc_VOMM_IN_PTENA_TO_ICE_TRANS ((uint8)14U)
#define swc_VOMM_IN_PTENA_TO_PHEV_TRANS ((uint8)15U)
#define swc_VOMM_IN_PTENA_TO_SHEV_TRANS ((uint8)16U)
#define swc_VOMM_IN_PT_ENA             ((uint8)17U)
#define swc_VOMM_IN_PT_OFF             ((uint8)18U)
#define swc_VOMM_IN_SHEV_MODE          ((uint8)19U)
#define swc_VOMM_IN_SHEV_TO_EV_TRANS   ((uint8)20U)
#define swc_VOMM_IN_SHEV_TO_PHEV_TRANS ((uint8)21U)
#define swc_VOMM_IN_SHEV_TO_PTENA_TRANS ((uint8)22U)
#define swc_VOMM_IN_SHUTDOWN           ((uint8)23U)
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
#define swc_VOMM_START_SEC_CONST_VOLATILE
#include "swc_VOMM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean dric_b_enaSportModeIn4WDMode = false;/* Referenced by: '<S8>/Constant7' */

/* Enable Sport Mode when 4WD mode is selected by the driver */
const volatile boolean dric_b_gearLvrPos_ovrdflg = false;
                          /* Referenced by: '<S32>/dric_b_gearLvrPos_ovrdflg' */
const volatile boolean dric_b_resetModeReqAtIgnON = false;/* Referenced by: '<S6>/Constant16' */

/* Reset Mode request at Ignition ON */
const volatile boolean dric_b_useGearLvrPosFromCan = false;/* Referenced by: '<S7>/Constant1' */

/* Use Gear Lever position from CAN */
const volatile HEVModeReq dric_e_driverModeReqInit = HEVModeReq_EV;/* Referenced by: '<S6>/Constant17' */

/* Initial Mode request */
const volatile HEVModeReq dric_e_driverModeReqSel[32] = { HEVModeReq_EV,
  HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV,
  HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV,
  HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV,
  HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV,
  HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV,
  HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV, HEVModeReq_EV,
  HEVModeReq_EV };                     /* Referenced by: '<S6>/Constant18' */

/* Mode Request Table */
const volatile GearLeverPos dric_e_gearLvrPos_ovrdval = GearLeverPos_FWD_DRIVE;
                          /* Referenced by: '<S32>/dric_e_gearLvrPos_ovrdval' */
const volatile float32 dric_t_P2NDebTm_s = 3.0F;/* Referenced by: '<S25>/Constant14' */

/* Gear lever Position Detection timeout */
const volatile float32 dric_t_driGearLvrPosTout_s = 0.1F;/* Referenced by:
                                                          * '<S24>/Constant12'
                                                          * '<S25>/Constant12'
                                                          */

/* Gear lever Position Detection timeout */
const volatile uint16 dric_t_epbClsReqTout_s = 9U;/* Referenced by: '<S25>/Constant4' */

/* Driver gear lever operation debounce time */
const volatile float32 dric_tm_driverModeReq4WDDeb_s = 0.05F;/* Referenced by: '<S6>/Constant11' */

/* Mode request debounce when 4WD mode is selected by the driver */
const volatile float32 dric_tm_driverModeReqECODeb_s = 0.05F;/* Referenced by: '<S6>/Constant7' */

/* Mode request debounce when ECO mode is selected by the driver */
const volatile float32 dric_tm_driverModeReqEVDeb_s = 0.05F;/* Referenced by: '<S6>/Constant5' */

/* Mode request debounce when EV mode is selected  by the driver */
const volatile float32 dric_tm_driverModeReqHEVDeb_s = 0.05F;/* Referenced by: '<S6>/Constant14' */

/* Mode request debounce when HEV mode is selected  by the driver */
const volatile float32 dric_tm_driverModeReqSPORTDeb_s = 0.05F;/* Referenced by: '<S6>/Constant9' */

/* Mode request debounce when SPORT mode is selected by the driver */
const volatile float32 dric_tm_gearLvrLckInd_s = 4.0F;/* Referenced by:
                                                       * '<S66>/Constant11'
                                                       * '<S66>/Constant14'
                                                       * '<S66>/Constant9'
                                                       */

/* Driver gear lever operation debounce time */
const volatile float32 dric_v_spdRstAutoP_kph = 3.0F;/* Referenced by: '<S76>/Constant3' */

/* AUTO P Vehicle Reset speed */
const volatile float32 dric_v_vehMoveThd_kph = 3.0F;/* Referenced by:
                                                     * '<S24>/Constant1'
                                                     * '<S25>/Constant1'
                                                     */

/* Vehicle Stopped threshold */
const volatile float32 dric_v_vehStoppedThd_kph = 3.0F;/* Referenced by:
                                                        * '<S24>/Constant2'
                                                        * '<S25>/Constant2'
                                                        */

/* Vehicle Stopped threshold */
const volatile boolean hmmc_b_dcBusDischargeType = false;/* Referenced by: '<S166>/Constant1' */

/* Different auto discharge strategies type calibration */
const volatile boolean hmmc_b_hmmModeReq_ovrdflg = true;
                         /* Referenced by: '<S168>/hmmc_b_hmmModeReq_ovrdflg' */
const volatile boolean hmmc_b_hmmState_ovrdflg = true;
                           /* Referenced by: '<S169>/hmmc_b_hmmState_ovrdflg' */
const volatile HEVModeReq hmmc_e_hmmModeReq_ovrdval = HEVModeReq_EV;
                         /* Referenced by: '<S168>/hmmc_e_hmmModeReq_ovrdval' */
const volatile HybModeMngr hmmc_e_hmmState_ovrdval = HybModeMngr_EV_MODE;
                           /* Referenced by: '<S169>/hmmc_e_hmmState_ovrdval' */
const volatile float32 hmmc_u_dcBusDischargeThr_V = 60.0F;/* Referenced by: '<S166>/Constant2' */

/* DC bus discharge threshold */
const volatile boolean obcc_b_enbChgCblChk = false;/* Referenced by: '<S195>/Constant1' */

/* Enable Charge Cable Check for Power Hold */
const volatile boolean pmmc_b_chgCANPwrHold = false;/* Referenced by: '<S194>/Constant' */

/* Retain powerhold if charger CAN is detected */
const volatile uint8 pmmc_num_vcuAddr = 0U;/* Referenced by: '<S209>/Constant9' */
const volatile uint8 pmmc_st_CanModeDisableReq = 0U;/* Referenced by: '<S209>/Constant19' */

/* CanMode disable request */
const volatile uint32 pmmc_st_dftStayAwk = 4U;/* Referenced by: '<S209>/Constant2' */

/* Stay awake reason Default */
const volatile uint32 pmmc_st_keyOnStayAwk = 1U;/* Referenced by: '<S209>/Constant18' */

/* Stay awake reason Key On */
const volatile uint32 pmmc_st_obcWkUpStayAwk = 2U;/* Referenced by: '<S209>/Constant4' */

/* Stay awake reason OBC Wake Up */
const volatile uint32 pmmc_st_resdStayAwk = 4U;/* Referenced by: '<S209>/Constant3' */

/* Stay awake reason Reserved */
const volatile float32 pmmc_tm_afterRunTmOut_s = 20.0F;/* Referenced by: '<S197>/Constant2' */

/* After run time out in PMM */
const volatile float32 pmmc_tm_chgCanAfterRun_s = 180.0F;/* Referenced by: '<S195>/Constant5' */

/* Time to hold power up after loss of CCS on CAN signal */
const volatile float32 pmmc_tm_chgHwAfterRun_s = 175.0F;/* Referenced by: '<S195>/Constant2' */

/* Time to hold power up after loss of charge wakeup input */
const volatile float32 pmmc_tm_driveAfterRun_s = 180.0F;/* Referenced by: '<S196>/Constant2' */

/* Time to hold power up after ignition off */
const volatile float32 pmmc_tm_fuTankLockThd_s = 2.0F;/* Referenced by: '<S209>/Constant16' */

/* Time threshold for for APU fuel tank lock */
const volatile float32 pmmc_tm_fuTankUnlockThd_s = 10.0F;/* Referenced by: '<S209>/Constant17' */

/* Time threshold for for APU fuel tank unlock */
const volatile float32 pmmc_tm_ptCanNmStRdyThd_s = 0.5F;/* Referenced by: '<S209>/Constant14' */

/* Time threshold for Pp_PtCan_CanNm_NmState is ready */
const volatile float32 pmmc_tm_ptCanNmStSlpThd_s = 0.01F;/* Referenced by: '<S209>/Constant15' */

/* Time threshold for Pp_PtCan_CanNm_NmState is not ready */
const volatile float32 pmmc_tm_pwrHoldReqDelayTime_s = 3.0F;/* Referenced by: '<S191>/Constant5' */

/* Power hold request delay time */
const volatile float32 pmmc_v_maxShutdown_kph = 3.0F;/* Referenced by: '<S194>/Constant5' */

/* Maximum speed at which shutdown mode is permitted */
const volatile float32 swcvomm_dric_tm_drvGearLvrLck_s = 0.02F;/* Referenced by:
                                                                * '<S99>/Constant'
                                                                * '<S105>/Constant'
                                                                * '<S111>/Constant'
                                                                * '<S117>/Constant'
                                                                */

/* Driver gear lever operation error debounce time */
const volatile float32 swcvomm_dric_tm_drvGearReqDly_s = 1.0F;/* Referenced by:
                                                               * '<S77>/Constant1'
                                                               * '<S77>/Constant6'
                                                               */

/* Driver gear lever operation debounce time */
const volatile float32 swcvomm_dric_tm_drvVehSpdChk_s = 0.2F;/* Referenced by: '<S76>/Constant14' */

/* Vehicle Speed check time */
const volatile float32 swcvomm_dric_tm_pedRel_s = 0.1F;/* Referenced by: '<S76>/Constant20' */

/* Vehicle Speed check time */
const volatile boolean swcvomm_vsmc_b_enaPTReadyVehRun = false;/* Referenced by: '<S5>/Constant4' */

/* Enable PT Ready determination of Vehicle Run */
const volatile boolean vsmc_b_PTDisabled_ovrdflg = false;
                         /* Referenced by: '<S239>/vsmc_b_PTDisabled_ovrdflg' */
const volatile boolean vsmc_b_PTDisabled_ovrdval = true;
                         /* Referenced by: '<S239>/vsmc_b_PTDisabled_ovrdval' */
const volatile boolean vsmc_b_PTEnabled_ovrdflg = false;
                          /* Referenced by: '<S240>/vsmc_b_PTEnabled_ovrdflg' */
const volatile boolean vsmc_b_PTEnabled_ovrdval = true;
                          /* Referenced by: '<S240>/vsmc_b_PTEnabled_ovrdval' */
const volatile boolean vsmc_b_VehRunRaw_ovrdflg = false;
                          /* Referenced by: '<S223>/vsmc_b_VehRunRaw_ovrdflg' */
const volatile boolean vsmc_b_VehRunRaw_ovrdval = true;
                          /* Referenced by: '<S223>/vsmc_b_VehRunRaw_ovrdval' */
const volatile boolean vsmc_b_VehRun_ovrdflg = false;
                             /* Referenced by: '<S222>/vsmc_b_VehRun_ovrdflg' */
const volatile boolean vsmc_b_VehRun_ovrdval = true;
                             /* Referenced by: '<S222>/vsmc_b_VehRun_ovrdval' */
const volatile boolean vsmc_b_VehStrt_ovrdflg = false;
                            /* Referenced by: '<S224>/vsmc_b_VehStrt_ovrdflg' */
const volatile boolean vsmc_b_VehStrt_ovrdval = true;
                            /* Referenced by: '<S224>/vsmc_b_VehStrt_ovrdval' */
const volatile boolean vsmc_b_enaAbort = true;/* Referenced by: '<S221>/Constant2' */
const volatile boolean vsmc_b_enaStrtWithGearPN = true;/* Referenced by: '<S221>/Constant1' */

/* Enable Start with P/N gear */
const volatile boolean vsmc_b_enaStrtWithPlugUnknown = true;/* Referenced by: '<S221>/Constant3' */

/* Enable Start with external charger status unknown */
const volatile boolean vsmc_b_enaVehStopIfEngStalls = true;/* Referenced by: '<S5>/Constant3' */

/* Enable Vehicle Stop if engine stalls */
const volatile boolean vsmc_b_enableQuickStrt = false;/* Referenced by: '<S5>/Constant1' */

/* Enable Quick Start */
const volatile float32 vsmc_tm_StartDemLatchTimeout_s = 10.0F;/* Referenced by: '<S5>/Constant2' */

/* Vehicle start demand latch timeout */
const volatile float32 vsmc_tm_StartReqTimeout_s = 10.0F;/* Referenced by: '<S5>/Constant7' */

/* Vehicle start request timeout */
const volatile float32 vsmc_v_PTOffThr_kph = 3.0F;/* Referenced by: '<S225>/Constant5' */

/* Vehicle speed threshold for system shutdown */
const volatile float32 vsmc_v_enaVehStrtThd_kph = 1.0F;/* Referenced by: '<S221>/Constant5' */

/* Vehicle speed threshold to enable start */
#define swc_VOMM_STOP_SEC_CONST_VOLATILE
#include "swc_VOMM_MemMap.h"
#define swc_VOMM_START_SEC_VAR
#include "swc_VOMM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean drid_b_DriModAct;              /* '<S8>/AND' */

/* VehicleStopped  */
boolean drid_b_DriModWriteflg;         /* '<S8>/Logical Operator6' */

/* egsmParkReq  */
boolean drid_b_VehicleMove;            /* '<S25>/Logical Operator2' */

/* VehicleMove  */
boolean drid_b_VehicleStopped;         /* '<S25>/Logical Operator1' */

/* VehicleStopped  */
boolean drid_b_egsmParkReq;            /* '<S76>/Switch10' */

/* egsmParkReq  */
boolean drid_b_veh4WDModActv;          /* '<S8>/Signal Conversion1' */

/* 4WD Mode selected by the driver */
boolean drid_b_vehSportModActv;        /* '<S157>/Switch' */

/* Sport Mode selected by the driver */
HEVModeReq drid_e_drvrHEVModReq;       /* '<S6>/Switch8' */

/* HEV Mode requested by the driver */
GearLeverPos drid_e_gearLvrPos;        /* '<S144>/Switch2' */

/* Gear Lever Position */
uint8 drid_st_DriModRead;              /* '<S155>/C Caller1' */

/* Gear Req  */
uint8 drid_st_DriModWrite;             /* '<S8>/Switch1' */

/* Gear Req  */
boolean hmmd_b_EVModeActive;           /* '<S165>/Logical Operator' */

/* EV mode active */
boolean hmmd_b_HVBusDischrgComplete;   /* '<S166>/Switch' */

/* HV Bus discharge complete */
boolean hmmd_b_bHVReady;               /* '<S166>/Relational Operator4' */

/* HV system ready */
HybModeMngr hmmd_e_hmmState;           /* '<S188>/Switch2' */

/* Hybrid Mode Manager State */
boolean pmmd_b_ActivityReq;            /* '<S194>/Logical Operator1' */

/* Strategy still active - powerhold requested */
boolean pmmd_b_chgCanPwrHold;          /* '<S195>/Logical Operator' */

/* Power hold request due to charger CAN */
boolean pmmd_b_chgHwPwrHold;           /* '<S199>/timed_delay' */

/* Power hold request due to charger hardware line */
boolean pmmd_b_chgPwrHold;             /* '<S195>/Logical Operator3' */

/* Power hold request due to charger */
boolean pmmd_b_drivePwrHold;           /* '<S205>/timed_delay' */

/* Internal power hold request */
boolean pmmd_b_emsWake;                /* '<S191>/Signal Conversion' */

/* EMS wakeup control output */
boolean pmmd_b_hsdFltClear;            /* '<S209>/network_modes' */

/* Fault Clear HSD Flag */
boolean pmmd_b_nmRdySlp;               /* '<S209>/network_modes' */

/* NM ready to sleep */
boolean pmmd_b_nmSts;                  /* '<S209>/Constant5' */

/* NM status */
boolean pmmd_b_nmWkUp;                 /* '<S209>/network_modes' */

/* NM wake up command */
boolean pmmd_b_peuWake;                /* '<S191>/Signal Conversion1' */

/* PEU wakeup control output */
boolean pmmd_b_pwrHoldAny;             /* '<S197>/Logical Operator4' */

/* Internal power hold request */
boolean pmmd_b_pwrHoldReq;             /* '<S191>/Signal Conversion2' */

/* External power hold request */
boolean pmmd_b_req_charging;           /* '<S195>/Logical Operator1' */

/* Assert power hold request */
boolean pmmd_b_req_drive;              /* '<S196>/Logical Operator7' */

/* Assert power hold request */
boolean pmmd_b_startReq;               /* '<S189>/Logical Operator4' */

/* Authorized driver Start Request */
boolean pmmd_b_vcuAwb;                 /* '<S209>/Switch4' */

/* VCU AWB */
boolean pmmd_b_vcuRmr;                 /* '<S209>/Constant6' */

/* VCU RMR */
uint8 pmmd_bm_netModeReq[2];           /* '<S210>/Signal Conversion' */

/* Network mode request */
NMStatus pmmd_e_CanNMSts;              /* '<S209>/network_modes' */

/* Network mode control status */
PmmMode pmmd_e_mode;                   /* '<S197>/pmm_power_modes' */

/* Overall power mode) */
uint8 pmmd_st_bdCanModeReq;            /* '<S209>/network_modes' */

/* CCan Com Mode Request */
uint8 pmmd_st_ptCanModeReq;            /* '<S209>/network_modes' */

/* PtCan Com Mode Request */
uint32 pmmd_st_stayAwkReason;          /* '<S209>/Switch14' */

/* VCU stay awake reason */
uint8 pmmd_st_vcuPwrActvMod;           /* '<S209>/Switch2' */

/* VCU power active mode */
uint8 pmmd_st_vcuWkUpReason;           /* '<S209>/Chart' */

/* VCU wake up reason */
float32 pmmd_tm_fuTankLockDeb_s;       /* '<S209>/network_modes' */

/* Turn on delay timer for APU fuel tank lock */
float32 pmmd_tm_fuTankUnlockDeb_s;     /* '<S209>/network_modes' */

/* Turn on delay timer for APU fuel tank unlock */
float32 pmmd_tm_ptCanNmStRdyDeb_s;     /* '<S209>/network_modes' */

/* Turn on delay timer for Pp_PtCan_CanNm_NmState is ready */
float32 pmmd_tm_ptCanNmStSlpDeb_s;     /* '<S209>/network_modes' */

/* Turn on delay timer for Pp_PtCan_CanNm_NmState is not ready */
boolean swcvomm_drid_b_adcGearCtrlEn;  /* '<S42>/Logical Operator1' */

/* ADC Gear Control  */
boolean swcvomm_drid_b_autoParkFlg;    /* '<S134>/timed_delay' */

/* Auto P Flg  */
boolean swcvomm_drid_b_drvOffSeatFlg;  /* '<S76>/Logical Operator10' */

/* driver off seat flg */
boolean swcvomm_drid_b_epbClsdReq;     /* '<S25>/EPBClsdReq' */

/* EPB Closed Req  */
boolean swcvomm_drid_b_gearPosVld;     /* '<S25>/Logical Operator5' */

/* current Gear Lever position valid flg  */
boolean swcvomm_drid_b_vehEcoModActv;  /* '<S157>/Switch1' */

/* ECO Mode  */
uint8 swcvomm_drid_st_adcGearLvrReq;   /* '<S42>/Switch1' */

/* ADC Gear Req  */
uint8 swcvomm_drid_st_egsmGearReq;     /* '<S25>/Switch10' */

/* Gear Req  */
uint8 swcvomm_drid_st_egsmGearReqRaw;  /* '<S7>/Signal Conversion1' */

/* Gear Req Raw */
uint8 swcvomm_drid_st_gearLvrLckInd;   /* '<S66>/Switch2' */

/* driver Gear Lever LOCK  */
boolean vsmd_b_PTDisabled;             /* '<S241>/Switch2' */

/* PowerTrain disabled */
boolean vsmd_b_PTEnabled;              /* '<S242>/Switch2' */

/* PowerTrain enabled */
boolean vsmd_b_StartDemRaw;            /* '<S221>/Logical Operator5' */
boolean vsmd_b_VehRun;                 /* '<S235>/Switch2' */

/* Vehicle running */
boolean vsmd_b_VehRunRaw;              /* '<S236>/Switch2' */

/* Vehicle running raw */
boolean vsmd_b_VehStrt;                /* '<S237>/Switch2' */

/* Vehicle start / started */
uint8 vsmd_st_vsmStatus;               /* '<S5>/VehicleStartManager' */

/* Vehicle Start Manager Status */
#define swc_VOMM_STOP_SEC_VAR
#include "swc_VOMM_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_VOMM_T swc_VOMM_ConstB = {
  0.0F,                                /* '<S166>/MinMax' */
  1U,                                  /* '<S7>/Constant' */
  0,                                   /* '<Root>/Data Type Conversion140' */
  0,                                   /* '<Root>/Data Type Conversion142' */
  0,                                   /* '<Root>/Data Type Conversion143' */
  0,                                   /* '<Root>/Data Type Conversion146' */
  0,                                   /* '<Root>/Data Type Conversion147' */
  0,                                   /* '<Root>/Data Type Conversion149' */
  0,                                   /* '<Root>/Data Type Conversion150' */
  0,                                   /* '<S166>/Relational Operator13' */
  1,                                   /* '<S225>/Logical Operator6' */
  EngStartType_NO_START_REQ,           /* '<Root>/Data Type Conversion137' */
  EngStartType_NO_START_REQ            /* '<Root>/Data Type Conversion138' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_VOMM_T swc_VOMM_ARID_DEF;
static void swc_VOMM_turnOFF_delay1_Init(boolean *rty_flg_out);
static void swc_VOMM_turnOFF_delay1(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay1_swc_V_T
  *swc_VOMM__ARID_DEF_arg);
static void swc_VOMM_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_VOMM_T *swc_VOMM__ARID_DEF_arg);
static void swc_VOMM_turnON_delay_4WD_Init(boolean *rty_flg_out);
static void swc_VOMM_turnON_delay_4WD(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_4WD_swc_T
  *swc_VOMM__ARID_DEF_arg);
static void swc_V_PMM_PowerModeManager_Init(void);
static void swc_VOMM_PMM_PowerModeManager(void);
static void swc_VOM_VSM_VehicleStartManager(void);
static void sw_DRI_DriveModesManagment_Init(void);
static void swc_VOM_DRI_DriveModesManagment(void);
static void swc_VOMM_HMM_ModeManager_Const(void);
static void swc_VOMM_HMM_ModeManager(void);

/* Forward declaration for local functions */
static void swc_VOMM_PHEV_MODE(HybModeMngr *hmm_status, const HEVModeReq *signal);
static void swc_VOMM_PT_ENA(HybModeMngr *hmm_status, const HEVModeReq *signal);
static void swc_VOMM_SHEV_MODE(HybModeMngr *hmm_status, const HEVModeReq *signal);

/*
 * System initialize for atomic system:
 *    '<S195>/turnOFF_delay1'
 *    '<S191>/turnOFF_delay'
 */
static void swc_VOMM_turnOFF_delay1_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S200>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S195>/turnOFF_delay1'
 *    '<S191>/turnOFF_delay'
 */
static void swc_VOMM_turnOFF_delay1(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay1_swc_V_T
  *swc_VOMM__ARID_DEF_arg)
{
  float32 rtb_t_delay_off_l;

  /* Saturate: '<S200>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S200>/Saturation1' */
    rtb_t_delay_off_l = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S200>/Saturation1' */
    rtb_t_delay_off_l = 0.0F;
  } else {
    /* Saturate: '<S200>/Saturation1' */
    rtb_t_delay_off_l = rtu_t_delay_off;
  }

  /* End of Saturate: '<S200>/Saturation1' */

  /* Chart: '<S200>/timed_delay' incorporates:
   *  DataTypeConversion: '<S200>/Data Type Conversion'
   */
  if (swc_VOMM__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_VOMM__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib) {
     case swc_VOMM_IN_OFF:
      if (rtu_flg_in) {
        swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_ON;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_VOMM_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_ON;
        *rty_flg_out = true;
      } else if (swc_VOMM__ARID_DEF_arg->t_wait > rtb_t_delay_off_l - rtu_t_step)
      {
        swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF;
        *rty_flg_out = false;
      } else {
        swc_VOMM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtb_t_delay_off_l == 0.0F) {
          swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF;
          *rty_flg_out = false;
        } else {
          swc_VOMM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib =
            swc_VOMM_IN_OFF_WAIT;
          swc_VOMM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S200>/timed_delay' */
}

/*
 * Output and update for atomic system:
 *    '<S191>/SR_latch'
 *    '<S5>/SR_latch'
 *    '<S86>/SR_latch'
 *    '<S87>/SR_latch'
 *    '<S88>/SR_latch'
 *    '<S89>/SR_latch'
 *    '<S66>/SR_latch'
 *    '<S66>/SR_latch1'
 *    '<S66>/SR_latch2'
 *    '<S76>/SR_latch'
 *    '<S25>/SR_latch'
 */
static void swc_VOMM_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_VOMM_T *swc_VOMM__ARID_DEF_arg)
{
  /* Logic: '<S216>/Logical Operator3' incorporates:
   *  Logic: '<S216>/Logical Operator'
   *  Logic: '<S216>/Logical Operator1'
   *  UnitDelay: '<S216>/Unit Delay'
   */
  *rty_flg_out = ((swc_VOMM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S216>/Unit Delay' */
  swc_VOMM__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* System initialize for function-call system: '<S1>/PMM_PowerModeManager' */
static void swc_V_PMM_PowerModeManager_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out;
  boolean rtb_flg_out_e;

  /* Start for Constant: '<S209>/Constant5' */
  pmmd_b_nmSts = true;

  /* Start for Constant: '<S209>/Constant6' */
  pmmd_b_vcuRmr = false;

  /* SystemInitialize for SignalConversion generated from: '<S4>/pmmd_num_vcuAddr' incorporates:
   *  Constant: '<S209>/Constant9'
   */
  swc_VOMM_ARID_DEF.OutportBufferForpmmd_num_vcuAdd = pmmc_num_vcuAddr;

  /* SystemInitialize for Atomic SubSystem: '<S195>/turnOFF_delay1' */
  swc_VOMM_turnOFF_delay1_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S195>/turnOFF_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S191>/turnOFF_delay' */
  swc_VOMM_turnOFF_delay1_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S191>/turnOFF_delay' */

  /* SystemInitialize for SignalConversion: '<S191>/Signal Conversion2' incorporates:
   *  Outport: '<S4>/pmmd_b_pwrHoldReq'
   */
  pmmd_b_pwrHoldReq = true;
}

/* Output and update for function-call system: '<S1>/PMM_PowerModeManager' */
static void swc_VOMM_PMM_PowerModeManager(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator1;
  boolean rtb_RelationalOperator2;
  boolean rtb_flg_out;
  boolean rtb_flg_out_e;
  boolean rtb_LogicalOperator3;
  float32 rtb_t_delay_off;
  uint8 rtb_Switch3_p;
  uint8 rtb_Switch6;
  uint8 rtb_pmm_afterrun_mask;
  uint8 tmp;
  boolean pmmd_b_req_charging_tmp;
  boolean pmmd_b_req_drive_tmp;
  boolean pmmd_b_req_drive_tmp_0;
  boolean rtb_DataTypeConversion_a_tmp;
  boolean rtb_DataTypeConversion_tmp;

  /* SignalConversion generated from: '<S4>/pmmd_num_vcuAddr' incorporates:
   *  Constant: '<S209>/Constant9'
   */
  swc_VOMM_ARID_DEF.OutportBufferForpmmd_num_vcuAdd = pmmc_num_vcuAddr;

  /* Logic: '<S196>/Logical Operator2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element10'
   *  Logic: '<S191>/Logical Operator1'
   *  Logic: '<S195>/Logical Operator1'
   */
  pmmd_b_req_drive_tmp = Rte_IRead_swc_VOMM_Step_vcsb_HVSM_obcd_b_chargerPlugged
    ();

  /* Logic: '<S196>/Logical Operator7' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Logic: '<S191>/Logical Operator1'
   */
  pmmd_b_req_drive_tmp_0 = Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ignOn();

  /* Logic: '<S196>/Logical Operator7' incorporates:
   *  Constant: '<S204>/Constant'
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Inport generated from: '<Root>/In Bus Element3'
   *  Inport generated from: '<Root>/In Bus Element10'
   *  Logic: '<S196>/Logical Operator2'
   *  RelationalOperator: '<S196>/Relational Operator4'
   */
  pmmd_b_req_drive =
    ((Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_e_authenticationStatus() ==
      KeyAuthStatus_SUCCESS) && pmmd_b_req_drive_tmp_0 && (!pmmd_b_req_drive_tmp));

  /* Logic: '<S195>/Logical Operator1' incorporates:
   *  Chart: '<S209>/network_modes'
   *  Inport generated from: '<Root>/In Bus Element17'
   *  Logic: '<S191>/Logical Operator1'
   */
  pmmd_b_req_charging_tmp =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd();

  /* Logic: '<S195>/Logical Operator1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  pmmd_b_req_charging = (pmmd_b_req_drive_tmp || pmmd_b_req_charging_tmp);

  /* Outputs for Atomic SubSystem: '<S196>/turnOFF_delay' */
  /* DataTypeConversion: '<S205>/Data Type Conversion' incorporates:
   *  Chart: '<S197>/pmm_power_modes'
   *  Chart: '<S209>/network_modes'
   *  Inport generated from: '<Root>/In Bus Element4'
   *  Logic: '<S209>/Logical Operator4'
   */
  rtb_DataTypeConversion_tmp = Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn
    ();

  /* Saturate: '<S205>/Saturation1' incorporates:
   *  Constant: '<S196>/Constant2'
   */
  if (pmmc_tm_driveAfterRun_s > 1.6777216E+7F) {
    /* Saturate: '<S205>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (pmmc_tm_driveAfterRun_s < 0.0F) {
    /* Saturate: '<S205>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S205>/Saturation1' */
    rtb_t_delay_off = pmmc_tm_driveAfterRun_s;
  }

  /* End of Saturate: '<S205>/Saturation1' */

  /* Chart: '<S205>/timed_delay' incorporates:
   *  Constant: '<S196>/Constant8'
   *  DataTypeConversion: '<S205>/Data Type Conversion'
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  if (swc_VOMM_ARID_DEF.is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_VOMM_ARID_DEF.is_active_c12_Ricardo_SW_dev_li = 1U;
    if (rtb_DataTypeConversion_tmp) {
      swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_f;
      pmmd_b_drivePwrHold = true;
    } else {
      swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_c;
      pmmd_b_drivePwrHold = false;
    }
  } else {
    switch (swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib) {
     case swc_VOMM_IN_OFF_c:
      if (rtb_DataTypeConversion_tmp) {
        swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_f;
        pmmd_b_drivePwrHold = true;
      } else {
        pmmd_b_drivePwrHold = false;
      }
      break;

     case swc_VOMM_IN_OFF_WAIT_o:
      if (rtb_DataTypeConversion_tmp) {
        swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_f;
        pmmd_b_drivePwrHold = true;
      } else if (swc_VOMM_ARID_DEF.t_wait_m > rtb_t_delay_off - ((float32)
                  PMM_TASK_INTERVAL_S)) {
        swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_c;
        pmmd_b_drivePwrHold = false;
      } else {
        swc_VOMM_ARID_DEF.t_wait_m += ((float32)PMM_TASK_INTERVAL_S);
        pmmd_b_drivePwrHold = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtb_DataTypeConversion_tmp) {
        if (rtb_t_delay_off == 0.0F) {
          swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_c;
          pmmd_b_drivePwrHold = false;
        } else {
          swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_WAIT_o;
          swc_VOMM_ARID_DEF.t_wait_m = ((float32)PMM_TASK_INTERVAL_S);
          pmmd_b_drivePwrHold = true;
        }
      } else {
        pmmd_b_drivePwrHold = true;
      }
      break;
    }
  }

  /* End of Chart: '<S205>/timed_delay' */
  /* End of Outputs for SubSystem: '<S196>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S195>/turnOFF_delay' */
  /* DataTypeConversion: '<S199>/Data Type Conversion' incorporates:
   *  Chart: '<S209>/network_modes'
   *  Inport generated from: '<Root>/In Bus Element2'
   *  Logic: '<S209>/Logical Operator4'
   */
  rtb_DataTypeConversion_a_tmp =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp();

  /* Saturate: '<S199>/Saturation1' incorporates:
   *  Constant: '<S195>/Constant2'
   */
  if (pmmc_tm_chgHwAfterRun_s > 1.6777216E+7F) {
    /* Saturate: '<S199>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (pmmc_tm_chgHwAfterRun_s < 0.0F) {
    /* Saturate: '<S199>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S199>/Saturation1' */
    rtb_t_delay_off = pmmc_tm_chgHwAfterRun_s;
  }

  /* End of Saturate: '<S199>/Saturation1' */

  /* Chart: '<S199>/timed_delay' incorporates:
   *  Constant: '<S195>/Constant8'
   *  DataTypeConversion: '<S199>/Data Type Conversion'
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  if (swc_VOMM_ARID_DEF.is_active_c12_Ricardo_SW_dev__o == 0U) {
    swc_VOMM_ARID_DEF.is_active_c12_Ricardo_SW_dev__o = 1U;
    if (rtb_DataTypeConversion_a_tmp) {
      swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_ON_f;
      pmmd_b_chgHwPwrHold = true;
    } else {
      swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_OFF_c;
      pmmd_b_chgHwPwrHold = false;
    }
  } else {
    switch (swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p) {
     case swc_VOMM_IN_OFF_c:
      if (rtb_DataTypeConversion_a_tmp) {
        swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_ON_f;
        pmmd_b_chgHwPwrHold = true;
      } else {
        pmmd_b_chgHwPwrHold = false;
      }
      break;

     case swc_VOMM_IN_OFF_WAIT_o:
      if (rtb_DataTypeConversion_a_tmp) {
        swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_ON_f;
        pmmd_b_chgHwPwrHold = true;
      } else if (swc_VOMM_ARID_DEF.t_wait_a > rtb_t_delay_off - ((float32)
                  PMM_TASK_INTERVAL_S)) {
        swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_OFF_c;
        pmmd_b_chgHwPwrHold = false;
      } else {
        swc_VOMM_ARID_DEF.t_wait_a += ((float32)PMM_TASK_INTERVAL_S);
        pmmd_b_chgHwPwrHold = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtb_DataTypeConversion_a_tmp) {
        if (rtb_t_delay_off == 0.0F) {
          swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_OFF_c;
          pmmd_b_chgHwPwrHold = false;
        } else {
          swc_VOMM_ARID_DEF.is_c12_Ricardo_SW_dev_lib_p = swc_VOMM_IN_OFF_WAIT_o;
          swc_VOMM_ARID_DEF.t_wait_a = ((float32)PMM_TASK_INTERVAL_S);
          pmmd_b_chgHwPwrHold = true;
        }
      } else {
        pmmd_b_chgHwPwrHold = true;
      }
      break;
    }
  }

  /* End of Chart: '<S199>/timed_delay' */
  /* End of Outputs for SubSystem: '<S195>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S195>/turnOFF_delay1' */
  /* Inport generated from: '<Root>/In Bus Element1' incorporates:
   *  Constant: '<S195>/Constant5'
   *  Constant: '<S195>/Constant8'
   */
  swc_VOMM_turnOFF_delay1
    (Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged(),
     pmmc_tm_chgCanAfterRun_s, ((float32)PMM_TASK_INTERVAL_S), &rtb_flg_out_e,
     &swc_VOMM_ARID_DEF.ARID_DEF_turnOFF_delay1);

  /* End of Outputs for SubSystem: '<S195>/turnOFF_delay1' */

  /* Logic: '<S195>/Logical Operator' incorporates:
   *  Constant: '<S195>/Constant1'
   */
  pmmd_b_chgCanPwrHold = (rtb_flg_out_e && obcc_b_enbChgCblChk);

  /* Logic: '<S195>/Logical Operator3' */
  pmmd_b_chgPwrHold = (pmmd_b_chgHwPwrHold || pmmd_b_chgCanPwrHold);

  /* Logic: '<S197>/Logical Operator4' */
  pmmd_b_pwrHoldAny = (pmmd_b_drivePwrHold || pmmd_b_chgPwrHold);

  /* Logic: '<S216>/Logical Operator3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element8'
   *  Logic: '<S194>/Logical Operator2'
   */
  rtb_LogicalOperator3 =
    !Rte_IRead_swc_VOMM_Step_vcib_VCIP_macd_b_pullUpDiagCmpl();

  /* Logic: '<S194>/Logical Operator1' incorporates:
   *  Constant: '<S194>/Constant'
   *  Constant: '<S194>/Constant5'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Inport generated from: '<Root>/In Bus Element7'
   *  Inport generated from: '<Root>/In Bus Element12'
   *  Logic: '<S194>/Logical Operator4'
   *  RelationalOperator: '<S194>/Relational Operator'
   */
  pmmd_b_ActivityReq = ((Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_v_vehSpd_kph() >=
    pmmc_v_maxShutdown_kph) ||
                        Rte_IRead_swc_VOMM_Step_vcsb_THSM_thmd_b_afterRunActive()
                        ||
                        (Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcCANMsgValid
    () && pmmc_b_chgCANPwrHold) || rtb_LogicalOperator3);

  /* Chart: '<S197>/pmm_power_modes' incorporates:
   *  Constant: '<S197>/Constant2'
   *  Constant: '<S197>/Constant8'
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  if (swc_VOMM_ARID_DEF.is_active_c1_pmm == 0U) {
    swc_VOMM_ARID_DEF.is_active_c1_pmm = 1U;
    swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_InactiveDrive;
    pmmd_e_mode = PmmMode_INACTIVEDRIVE;
  } else {
    switch (swc_VOMM_ARID_DEF.is_c1_pmm) {
     case swc_VOMM_IN_Charging:
      pmmd_e_mode = PmmMode_CHARGE;
      if (!pmmd_b_req_charging) {
        if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_driverStartReq()) {
          swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_InhibitDrive;
          pmmd_e_mode = PmmMode_DRIVEINHIBIT;
        } else {
          swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_NoActiveReq;
          swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_AfterRun;
          swc_VOMM_ARID_DEF.TimeInState = 0.0F;
          pmmd_e_mode = PmmMode_AFTERRUN;
        }
      }
      break;

     case swc_VOMM_IN_Drive:
      pmmd_e_mode = PmmMode_DRIVE;
      if (!pmmd_b_req_drive) {
        swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_NoActiveReq;
        swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_AfterRun;
        swc_VOMM_ARID_DEF.TimeInState = 0.0F;
        pmmd_e_mode = PmmMode_AFTERRUN;
      }
      break;

     case swc_VOMM_IN_InactiveDrive:
      pmmd_e_mode = PmmMode_INACTIVEDRIVE;
      if ((!rtb_DataTypeConversion_tmp) && (!pmmd_b_req_charging)) {
        swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_NoActiveReq;
        swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_AfterRun;
        swc_VOMM_ARID_DEF.TimeInState = 0.0F;
        pmmd_e_mode = PmmMode_AFTERRUN;
      } else if (pmmd_b_req_charging) {
        swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_Charging;
        pmmd_e_mode = PmmMode_CHARGE;
      } else if (pmmd_b_req_drive) {
        swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_Drive;
        pmmd_e_mode = PmmMode_DRIVE;
      }
      break;

     case swc_VOMM_IN_InhibitDrive:
      pmmd_e_mode = PmmMode_DRIVEINHIBIT;
      if (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_driverStartReq()) {
        swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_NoActiveReq;
        swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_AfterRun;
        swc_VOMM_ARID_DEF.TimeInState = 0.0F;
        pmmd_e_mode = PmmMode_AFTERRUN;
      }
      break;

     default:
      /* case IN_NoActiveReq: */
      if (rtb_DataTypeConversion_tmp || pmmd_b_req_charging) {
        if (pmmd_b_req_charging) {
          swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_NO_ACTIVE_CHILD;
          swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_Charging;
          pmmd_e_mode = PmmMode_CHARGE;
        } else if (pmmd_b_req_drive) {
          swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_NO_ACTIVE_CHILD;
          swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_Drive;
          pmmd_e_mode = PmmMode_DRIVE;
        } else {
          swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_NO_ACTIVE_CHILD;
          swc_VOMM_ARID_DEF.is_c1_pmm = swc_VOMM_IN_InactiveDrive;
          pmmd_e_mode = PmmMode_INACTIVEDRIVE;
        }
      } else {
        switch (swc_VOMM_ARID_DEF.is_NoActiveReq) {
         case swc_VOMM_IN_AfterRun:
          pmmd_e_mode = PmmMode_AFTERRUN;
          if ((!pmmd_b_ActivityReq) || (swc_VOMM_ARID_DEF.TimeInState >
               pmmc_tm_afterRunTmOut_s)) {
            swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_ShutdownWait;
            swc_VOMM_ARID_DEF.TimeInState = 0.0F;
            pmmd_e_mode = PmmMode_SHUTDOWNWAIT;
          } else {
            swc_VOMM_ARID_DEF.TimeInState += ((float32)PMM_TASK_INTERVAL_S);
          }
          break;

         case swc_VOMM_IN_Shutdown:
          pmmd_e_mode = PmmMode_SHUTDOWN;
          break;

         default:
          /* case IN_ShutdownWait: */
          pmmd_e_mode = PmmMode_SHUTDOWNWAIT;
          if (!pmmd_b_pwrHoldAny) {
            swc_VOMM_ARID_DEF.is_NoActiveReq = swc_VOMM_IN_Shutdown;
            pmmd_e_mode = PmmMode_SHUTDOWN;
          }
          break;
        }
      }
      break;
    }
  }

  /* Logic: '<S189>/Logical Operator4' incorporates:
   *  Constant: '<S192>/Constant'
   *  Inport generated from: '<Root>/In Bus Element5'
   *  RelationalOperator: '<S189>/Relational Operator3'
   */
  pmmd_b_startReq = ((pmmd_e_mode == PmmMode_DRIVE) &&
                     Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_driverStartReq());

  /* Chart: '<S209>/network_modes' incorporates:
   *  Constant: '<S209>/Constant1'
   *  Constant: '<S209>/Constant14'
   *  Constant: '<S209>/Constant15'
   *  Constant: '<S209>/Constant17'
   *  Constant: '<S209>/Constant19'
   *  Inport generated from: '<Root>/In Bus Element13'
   *  Inport generated from: '<Root>/In Bus Element14'
   *  Inport generated from: '<Root>/In Bus Element17'
   *  Inport generated from: '<Root>/In Bus Element2'
   *  Inport generated from: '<Root>/In Bus Element4'
   *  Inport generated from: '<Root>/In Bus Element9'
   *  Inport generated from: '<Root>/In Bus Element11'
   */
  if (swc_VOMM_ARID_DEF.is_active_c3_pmm == 0U) {
    swc_VOMM_ARID_DEF.is_active_c3_pmm = 1U;
    swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_SleepMode;
    pmmd_e_CanNMSts = NMStatus_SLEEPMODE;
    pmmd_b_nmWkUp = false;
    pmmd_b_nmRdySlp = true;
    pmmd_tm_ptCanNmStRdyDeb_s = 0.0F;
    pmmd_b_hsdFltClear = false;
    if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy()) {
      pmmd_tm_ptCanNmStRdyDeb_s = pmmd_tm_ptCanNmStRdyDeb_s + ((float32)
        PMM_TASK_INTERVAL_S);
    } else {
      pmmd_tm_ptCanNmStRdyDeb_s = 0.0F;
    }
  } else {
    switch (swc_VOMM_ARID_DEF.is_c3_pmm) {
     case swc_VOMM_IN_CANDisable:
      pmmd_e_CanNMSts = NMStatus_CANDISABLE;
      pmmd_b_nmWkUp = false;
      pmmd_b_nmRdySlp = true;
      pmmd_b_hsdFltClear = true;
      if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn() ||
          Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp() ||
          pmmd_b_req_charging_tmp) {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_NormalOperation;
        pmmd_e_CanNMSts = NMStatus_NORMALOPERATION;
        pmmd_b_nmWkUp = true;
        pmmd_b_nmRdySlp = false;
        pmmd_st_ptCanModeReq = 2U;
        pmmd_st_bdCanModeReq = 2U;
        pmmd_b_hsdFltClear = false;
      } else if (pmmd_tm_ptCanNmStSlpDeb_s >= pmmc_tm_ptCanNmStSlpThd_s) {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_SleepMode;
        pmmd_e_CanNMSts = NMStatus_SLEEPMODE;
        pmmd_b_nmWkUp = false;
        pmmd_b_nmRdySlp = true;
        pmmd_tm_ptCanNmStRdyDeb_s = 0.0F;
        pmmd_b_hsdFltClear = false;
        if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy()) {
          pmmd_tm_ptCanNmStRdyDeb_s = pmmd_tm_ptCanNmStRdyDeb_s + ((float32)
            PMM_TASK_INTERVAL_S);
        } else {
          pmmd_tm_ptCanNmStRdyDeb_s = 0.0F;
        }
      } else if (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy()) {
        pmmd_tm_ptCanNmStSlpDeb_s = pmmd_tm_ptCanNmStSlpDeb_s + ((float32)
          PMM_TASK_INTERVAL_S);
      } else {
        pmmd_tm_ptCanNmStSlpDeb_s = 0.0F;
      }
      break;

     case swc_V_IN_NormalNMWakedOperation:
      pmmd_e_CanNMSts = NMStatus_NORMALWAKED;
      pmmd_b_nmWkUp = true;
      pmmd_b_nmRdySlp = false;
      pmmd_b_hsdFltClear = false;
      if ((!Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn()) &&
          (!rtb_DataTypeConversion_a_tmp) && (!pmmd_b_req_charging_tmp)) {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_VCUSleepWait;
        pmmd_e_CanNMSts = NMStatus_VCUSLEEPWAIT;
        pmmd_b_nmWkUp = false;
        pmmd_b_nmRdySlp = true;
        pmmd_tm_fuTankUnlockDeb_s = 0.0F;
        if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankUnlock()) {
          pmmd_tm_fuTankUnlockDeb_s = pmmd_tm_fuTankUnlockDeb_s + ((float32)
            PMM_TASK_INTERVAL_S);
        } else {
          pmmd_tm_fuTankUnlockDeb_s = 0.0F;
        }
      } else if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn() ||
                 Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp() ||
                 pmmd_b_req_charging_tmp) {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_NormalOperation;
        pmmd_e_CanNMSts = NMStatus_NORMALOPERATION;
        pmmd_b_nmWkUp = true;
        pmmd_b_nmRdySlp = false;
        pmmd_st_ptCanModeReq = 2U;
        pmmd_st_bdCanModeReq = 2U;
        pmmd_b_hsdFltClear = false;
      } else if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankLock()) {
        pmmd_tm_fuTankLockDeb_s = pmmd_tm_fuTankLockDeb_s + ((float32)
          PMM_TASK_INTERVAL_S);
      } else {
        pmmd_tm_fuTankLockDeb_s = 0.0F;
      }
      break;

     case swc_VOMM_IN_NormalOperation:
      pmmd_e_CanNMSts = NMStatus_NORMALOPERATION;
      pmmd_b_nmWkUp = true;
      pmmd_b_nmRdySlp = false;
      pmmd_b_hsdFltClear = false;
      if ((!Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn()) &&
          (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp()) &&
          (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd())) {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_V_IN_NormalNMWakedOperation;
        pmmd_e_CanNMSts = NMStatus_NORMALWAKED;
        pmmd_b_nmWkUp = true;
        pmmd_b_nmRdySlp = false;
        pmmd_tm_fuTankLockDeb_s = 0.0F;
        pmmd_st_ptCanModeReq = 2U;
        pmmd_st_bdCanModeReq = 2U;
        pmmd_b_hsdFltClear = false;
        if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankLock()) {
          pmmd_tm_fuTankLockDeb_s = pmmd_tm_fuTankLockDeb_s + ((float32)
            PMM_TASK_INTERVAL_S);
        } else {
          pmmd_tm_fuTankLockDeb_s = 0.0F;
        }
      }
      break;

     case swc_VOMM_IN_SleepMode:
      pmmd_e_CanNMSts = NMStatus_SLEEPMODE;
      pmmd_b_nmWkUp = false;
      pmmd_b_nmRdySlp = true;
      pmmd_b_hsdFltClear = false;
      if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn() ||
          Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp() ||
          pmmd_b_req_charging_tmp) {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_NormalOperation;
        pmmd_e_CanNMSts = NMStatus_NORMALOPERATION;
        pmmd_b_nmWkUp = true;
        pmmd_b_nmRdySlp = false;
        pmmd_st_ptCanModeReq = 2U;
        pmmd_st_bdCanModeReq = 2U;
        pmmd_b_hsdFltClear = false;
      } else if ((pmmd_tm_ptCanNmStRdyDeb_s >= pmmc_tm_ptCanNmStRdyThd_s) &&
                 (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn()) &&
                 (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp()) &&
                 (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd()))
      {
        swc_VOMM_ARID_DEF.is_c3_pmm = swc_V_IN_NormalNMWakedOperation;
        pmmd_e_CanNMSts = NMStatus_NORMALWAKED;
        pmmd_b_nmWkUp = true;
        pmmd_b_nmRdySlp = false;
        pmmd_tm_fuTankLockDeb_s = 0.0F;
        pmmd_st_ptCanModeReq = 2U;
        pmmd_st_bdCanModeReq = 2U;
        pmmd_b_hsdFltClear = false;
        if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankLock()) {
          pmmd_tm_fuTankLockDeb_s = pmmd_tm_fuTankLockDeb_s + ((float32)
            PMM_TASK_INTERVAL_S);
        } else {
          pmmd_tm_fuTankLockDeb_s = 0.0F;
        }
      } else if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy()) {
        pmmd_tm_ptCanNmStRdyDeb_s = pmmd_tm_ptCanNmStRdyDeb_s + ((float32)
          PMM_TASK_INTERVAL_S);
      } else {
        pmmd_tm_ptCanNmStRdyDeb_s = 0.0F;
      }
      break;

     default:
      {
        /* case IN_VCUSleepWait: */
        pmmd_e_CanNMSts = NMStatus_VCUSLEEPWAIT;
        pmmd_b_nmWkUp = false;
        pmmd_b_nmRdySlp = true;
        if (rtb_DataTypeConversion_tmp || rtb_DataTypeConversion_a_tmp ||
            pmmd_b_req_charging_tmp) {
          swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_NormalOperation;
          pmmd_e_CanNMSts = NMStatus_NORMALOPERATION;
          pmmd_b_nmWkUp = true;
          pmmd_b_nmRdySlp = false;
          pmmd_st_ptCanModeReq = 2U;
          pmmd_st_bdCanModeReq = 2U;
          pmmd_b_hsdFltClear = false;
        } else {
          boolean tmp_0;
          boolean tmp_1;
          boolean tmp_2;
          tmp_0 = !Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn();
          tmp_1 = !Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp();
          tmp_2 = !Rte_IRead_swc_VOMM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd();
          if ((pmmd_tm_fuTankUnlockDeb_s >= pmmc_tm_fuTankUnlockThd_s) && tmp_0 &&
              tmp_1 && tmp_2) {
            swc_VOMM_ARID_DEF.is_c3_pmm = swc_V_IN_NormalNMWakedOperation;
            pmmd_e_CanNMSts = NMStatus_NORMALWAKED;
            pmmd_b_nmWkUp = true;
            pmmd_b_nmRdySlp = false;
            pmmd_tm_fuTankLockDeb_s = 0.0F;
            pmmd_st_ptCanModeReq = 2U;
            pmmd_st_bdCanModeReq = 2U;
            pmmd_b_hsdFltClear = false;
            if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankLock()) {
              pmmd_tm_fuTankLockDeb_s = pmmd_tm_fuTankLockDeb_s + ((float32)
                PMM_TASK_INTERVAL_S);
            } else {
              pmmd_tm_fuTankLockDeb_s = 0.0F;
            }
          } else if (Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_vcuRdyToSlp() &&
                     tmp_0 && tmp_1 && tmp_2) {
            swc_VOMM_ARID_DEF.is_c3_pmm = swc_VOMM_IN_CANDisable;
            pmmd_e_CanNMSts = NMStatus_CANDISABLE;
            pmmd_b_nmWkUp = false;
            pmmd_b_nmRdySlp = true;
            pmmd_tm_fuTankUnlockDeb_s = 0.0F;
            pmmd_tm_ptCanNmStSlpDeb_s = 0.0F;
            pmmd_st_ptCanModeReq = pmmc_st_CanModeDisableReq;
            pmmd_st_bdCanModeReq = pmmc_st_CanModeDisableReq;
            pmmd_b_hsdFltClear = true;
            if (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy()) {
              pmmd_tm_ptCanNmStSlpDeb_s = pmmd_tm_ptCanNmStSlpDeb_s + ((float32)
                PMM_TASK_INTERVAL_S);
            } else {
              pmmd_tm_ptCanNmStSlpDeb_s = 0.0F;
            }
          } else if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankUnlock()) {
            pmmd_tm_fuTankUnlockDeb_s = pmmd_tm_fuTankUnlockDeb_s + ((float32)
              PMM_TASK_INTERVAL_S);
          } else {
            pmmd_tm_fuTankUnlockDeb_s = 0.0F;
          }
        }
      }
      break;
    }
  }

  /* Switch: '<S209>/Switch6' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   *  Inport generated from: '<Root>/In Bus Element4'
   *  Switch: '<S209>/Switch14'
   *  Switch: '<S209>/Switch7'
   *  Switch: '<S209>/Switch8'
   */
  if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn()) {
    /* Switch: '<S209>/Switch6' incorporates:
     *  Constant: '<S209>/Constant10'
     */
    rtb_Switch6 = ((uint8)1U);

    /* Switch: '<S209>/Switch14' incorporates:
     *  Constant: '<S209>/Constant18'
     */
    pmmd_st_stayAwkReason = pmmc_st_keyOnStayAwk;
  } else {
    if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp()) {
      /* Switch: '<S209>/Switch7' incorporates:
       *  Constant: '<S209>/Constant11'
       *  Switch: '<S209>/Switch6'
       */
      rtb_Switch6 = ((uint8)3U);
    } else if (pmmd_b_nmWkUp) {
      /* Switch: '<S209>/Switch8' incorporates:
       *  Constant: '<S209>/Constant12'
       *  Switch: '<S209>/Switch6'
       *  Switch: '<S209>/Switch7'
       */
      rtb_Switch6 = ((uint8)2U);
    } else {
      /* Switch: '<S209>/Switch6' incorporates:
       *  Constant: '<S209>/Constant13'
       *  Switch: '<S209>/Switch7'
       *  Switch: '<S209>/Switch8'
       */
      rtb_Switch6 = ((uint8)0U);
    }

    /* Switch: '<S209>/Switch12' incorporates:
     *  Inport generated from: '<Root>/In Bus Element2'
     *  Switch: '<S209>/Switch1'
     *  Switch: '<S209>/Switch7'
     *  Switch: '<S209>/Switch8'
     */
    if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp()) {
      /* Switch: '<S209>/Switch14' incorporates:
       *  Constant: '<S209>/Constant4'
       *  Switch: '<S209>/Switch12'
       */
      pmmd_st_stayAwkReason = pmmc_st_obcWkUpStayAwk;
    } else if (pmmd_b_nmWkUp) {
      /* Switch: '<S209>/Switch1' incorporates:
       *  Constant: '<S209>/Constant3'
       *  Switch: '<S209>/Switch12'
       *  Switch: '<S209>/Switch14'
       */
      pmmd_st_stayAwkReason = pmmc_st_resdStayAwk;
    } else {
      /* Switch: '<S209>/Switch14' incorporates:
       *  Constant: '<S209>/Constant2'
       *  Switch: '<S209>/Switch1'
       *  Switch: '<S209>/Switch12'
       */
      pmmd_st_stayAwkReason = pmmc_st_dftStayAwk;
    }

    /* End of Switch: '<S209>/Switch12' */
  }

  /* End of Switch: '<S209>/Switch6' */

  /* Chart: '<S209>/Chart' */
  if (swc_VOMM_ARID_DEF.is_active_c4_pmm == 0U) {
    swc_VOMM_ARID_DEF.is_active_c4_pmm = 1U;
    swc_VOMM_ARID_DEF.is_c4_pmm = swc_VOMM_IN_init;
    pmmd_st_vcuWkUpReason = 0U;
  } else {
    switch (swc_VOMM_ARID_DEF.is_c4_pmm) {
     case swc_VOMM_IN_FristWkUp:
      break;

     default:
      /* case IN_init: */
      if (rtb_Switch6 != 0) {
        swc_VOMM_ARID_DEF.is_c4_pmm = swc_VOMM_IN_FristWkUp;
        pmmd_st_vcuWkUpReason = rtb_Switch6;
      }
      break;
    }
  }

  /* End of Chart: '<S209>/Chart' */

  /* Switch: '<S209>/Switch2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   *  Inport generated from: '<Root>/In Bus Element4'
   *  Logic: '<S209>/Logical Operator4'
   *  Switch: '<S209>/Switch3'
   *  Switch: '<S209>/Switch5'
   */
  if (rtb_DataTypeConversion_tmp && rtb_DataTypeConversion_a_tmp) {
    /* Switch: '<S209>/Switch2' incorporates:
     *  Constant: '<S209>/Constant22'
     */
    pmmd_st_vcuPwrActvMod = ((uint8)3U);
  } else if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn()) {
    /* Switch: '<S209>/Switch2' incorporates:
     *  Constant: '<S209>/Constant20'
     *  Switch: '<S209>/Switch3'
     */
    pmmd_st_vcuPwrActvMod = ((uint8)1U);
  } else if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp()) {
    /* Switch: '<S209>/Switch5' incorporates:
     *  Constant: '<S209>/Constant21'
     *  Switch: '<S209>/Switch2'
     *  Switch: '<S209>/Switch3'
     */
    pmmd_st_vcuPwrActvMod = ((uint8)2U);
  } else {
    /* Switch: '<S209>/Switch2' incorporates:
     *  Constant: '<S209>/Constant23'
     *  Switch: '<S209>/Switch3'
     *  Switch: '<S209>/Switch5'
     */
    pmmd_st_vcuPwrActvMod = ((uint8)0U);
  }

  /* End of Switch: '<S209>/Switch2' */

  /* Switch: '<S209>/Switch4' incorporates:
   *  Constant: '<S209>/Constant7'
   */
  pmmd_b_vcuAwb = false;

  /* Constant: '<S209>/Constant5' */
  pmmd_b_nmSts = true;

  /* Constant: '<S209>/Constant6' */
  pmmd_b_vcuRmr = false;

  /* Switch: '<S212>/Switch' incorporates:
   *  Constant: '<S212>/Constant'
   *  Constant: '<S212>/Constant9'
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn()) {
    tmp = ((uint8)PMM_NET_RUN);
  } else {
    tmp = ((uint8)0U);
  }

  /* Switch: '<S212>/Switch1' incorporates:
   *  Constant: '<S212>/Constant1'
   *  Constant: '<S212>/Constant2'
   */
  if (pmmd_b_req_charging) {
    rtb_pmm_afterrun_mask = ((uint8)PMM_NET_CHG);
  } else {
    rtb_pmm_afterrun_mask = ((uint8)0U);
  }

  /* Sum: '<S210>/Sum3' incorporates:
   *  Sum: '<S212>/Sum'
   *  Switch: '<S212>/Switch'
   *  Switch: '<S212>/Switch1'
   */
  rtb_Switch6 = (uint8)((uint32)tmp + rtb_pmm_afterrun_mask);

  /* Switch: '<S211>/Switch2' incorporates:
   *  Constant: '<S211>/Constant5'
   *  Constant: '<S211>/Constant9'
   */
  if (pmmd_b_drivePwrHold) {
    tmp = ((uint8)PMM_NET_AFTERRUN);
  } else {
    tmp = ((uint8)0U);
  }

  /* Switch: '<S211>/Switch3' incorporates:
   *  Constant: '<S211>/Constant1'
   *  Constant: '<S211>/Constant6'
   */
  if (pmmd_b_chgPwrHold) {
    rtb_pmm_afterrun_mask = ((uint8)PMM_NET_AFTERCHG);
  } else {
    rtb_pmm_afterrun_mask = ((uint8)0U);
  }

  /* Sum: '<S211>/Sum1' incorporates:
   *  Switch: '<S211>/Switch2'
   *  Switch: '<S211>/Switch3'
   */
  rtb_pmm_afterrun_mask = (uint8)((uint32)tmp + rtb_pmm_afterrun_mask);

  /* Switch: '<S210>/Switch3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp()) {
    /* Switch: '<S210>/Switch3' incorporates:
     *  Constant: '<S210>/Constant6'
     */
    rtb_Switch3_p = ((uint8)PMM_NET_OBC);
  } else {
    /* Switch: '<S210>/Switch3' incorporates:
     *  Constant: '<S210>/Constant1'
     */
    rtb_Switch3_p = ((uint8)0U);
  }

  /* End of Switch: '<S210>/Switch3' */

  /* Switch: '<S210>/Switch4' incorporates:
   *  Constant: '<S210>/Constant9'
   */
  if (pmmd_b_ActivityReq) {
    tmp = rtb_pmm_afterrun_mask;
  } else {
    tmp = ((uint8)0U);
  }

  /* SignalConversion: '<S210>/Signal Conversion' incorporates:
   *  Sum: '<S210>/Sum2'
   *  Sum: '<S210>/Sum3'
   *  Switch: '<S210>/Switch4'
   */
  pmmd_bm_netModeReq[0] = (uint8)((uint32)(uint8)((uint32)rtb_Switch6 + tmp) +
    rtb_Switch3_p);
  pmmd_bm_netModeReq[1] = (uint8)((uint32)(uint8)((uint32)rtb_Switch6 +
    rtb_pmm_afterrun_mask) + rtb_Switch3_p);

  /* Logic: '<S191>/Logical Operator1' */
  rtb_LogicalOperator1 = (pmmd_b_req_drive_tmp_0 || pmmd_b_req_drive_tmp ||
    pmmd_b_req_charging_tmp);

  /* RelationalOperator: '<S191>/Relational Operator2' incorporates:
   *  Constant: '<S215>/Constant'
   */
  rtb_RelationalOperator2 = (pmmd_e_mode == PmmMode_SHUTDOWN);

  /* Outputs for Atomic SubSystem: '<S191>/SR_latch' */
  swc_VOMM_SR_latch(rtb_LogicalOperator1, rtb_RelationalOperator2,
                    &rtb_LogicalOperator3,
                    &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_l);

  /* End of Outputs for SubSystem: '<S191>/SR_latch' */

  /* SignalConversion: '<S191>/Signal Conversion' */
  pmmd_b_emsWake = rtb_LogicalOperator3;

  /* SignalConversion: '<S191>/Signal Conversion1' */
  pmmd_b_peuWake = rtb_LogicalOperator3;

  /* Outputs for Atomic SubSystem: '<S191>/turnOFF_delay' */
  /* Constant: '<S191>/Constant5' incorporates:
   *  Constant: '<S191>/Constant8'
   */
  swc_VOMM_turnOFF_delay1(rtb_LogicalOperator3, pmmc_tm_pwrHoldReqDelayTime_s,
    ((float32)PMM_TASK_INTERVAL_S), &rtb_flg_out,
    &swc_VOMM_ARID_DEF.ARID_DEF_turnOFF_delay);

  /* End of Outputs for SubSystem: '<S191>/turnOFF_delay' */

  /* SignalConversion: '<S191>/Signal Conversion2' */
  pmmd_b_pwrHoldReq = rtb_flg_out;
}

/* Output and update for function-call system: '<S1>/VSM_VehicleStartManager' */
static void swc_VOM_VSM_VehicleStartManager(void)
{
  /* local block i/o variables */
  boolean rtb_RelationalOperator2_f;
  boolean rtb_LogicalOperator4_hg;
  boolean rtb_LogicalOperator10;
  boolean rtb_LogicalOperator1_c;
  boolean rtb_LogicalOperator6_j;
  boolean rtb_LogicalOperator3_l;
  float32 rtb_RelationalOperator2_f_tmp;
  ChargerStatus vsmd_b_StartDemRaw_tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator8;

  /* RelationalOperator: '<S221>/Relational Operator3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element27'
   *  RelationalOperator: '<S221>/Relational Operator4'
   *  RelationalOperator: '<S225>/Relational Operator1'
   */
  vsmd_b_StartDemRaw_tmp = Rte_IRead_swc_VOMM_Step_vcsb_HVSM_obcd_e_chargerSts();

  /* Logic: '<S221>/Logical Operator5' incorporates:
   *  Constant: '<S221>/Constant3'
   *  Constant: '<S221>/Constant4'
   *  Constant: '<S221>/Constant9'
   *  Constant: '<S230>/Constant'
   *  Constant: '<S231>/Constant'
   *  Inport generated from: '<Root>/In Bus Element41'
   *  Inport generated from: '<Root>/In Bus Element18'
   *  Logic: '<S221>/Logical Operator1'
   *  Logic: '<S221>/Logical Operator2'
   *  Logic: '<S221>/Logical Operator6'
   *  RelationalOperator: '<S221>/Relational Operator3'
   *  RelationalOperator: '<S221>/Relational Operator4'
   *  RelationalOperator: '<S221>/Relational Operator8'
   */
  vsmd_b_StartDemRaw = (((vsmd_b_StartDemRaw_tmp ==
    ChargerStatus_CONFIRMED_UNPLUGGED) || ((vsmd_b_StartDemRaw_tmp ==
    ChargerStatus_SUSPECT_UNPLUGGED) && vsmc_b_enaStrtWithPlugUnknown)) &&
                        (pmmd_b_startReq ||
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_tstd_b_engStrtReq()) && true &&
                        (Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_st_gearLvrPosSeql
    () == ((uint8)0U)));

  /* Logic: '<S221>/Logical Operator8' incorporates:
   *  Constant: '<S221>/Constant2'
   *  Constant: '<S221>/Constant6'
   *  Constant: '<S232>/Constant'
   *  Inport generated from: '<Root>/In Bus Element15'
   *  Inport generated from: '<Root>/In Bus Element32'
   *  Logic: '<S221>/Logical Operator11'
   *  Logic: '<S221>/Logical Operator3'
   *  Logic: '<S221>/Logical Operator9'
   *  RelationalOperator: '<S221>/Relational Operator6'
   */
  rtb_LogicalOperator8 =
    (((Rte_IRead_swc_VOMM_Step_vcib_VCIP_brpd_e_brkPedalStatus() !=
       BrakePedalStatus_PRESSED) || (!true) ||
      Rte_IRead_swc_VOMM_Step_vcsb_AUXC_brpd_b_airTankFlt()) && vsmc_b_enaAbort);

  /* RelationalOperator: '<S221>/Relational Operator2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element7'
   *  RelationalOperator: '<S225>/Relational Operator2'
   *  Switch: '<S241>/Switch2'
   */
  rtb_RelationalOperator2_f_tmp =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* RelationalOperator: '<S221>/Relational Operator2' incorporates:
   *  Constant: '<S221>/Constant5'
   *  Inport generated from: '<Root>/In Bus Element7'
   */
  rtb_RelationalOperator2_f = (rtb_RelationalOperator2_f_tmp <=
    vsmc_v_enaVehStrtThd_kph);

  /* Logic: '<S221>/Logical Operator4' incorporates:
   *  Constant: '<S221>/Constant1'
   *  Constant: '<S233>/Constant'
   *  Logic: '<S221>/Logical Operator7'
   *  RelationalOperator: '<S221>/Relational Operator1'
   *  Switch: '<S7>/Switch1'
   */
  rtb_LogicalOperator4_hg = ((swc_VOMM_ARID_DEF.drid_e_driveDirSel ==
    DriveDir_NO_DRIVE) || (!vsmc_b_enaStrtWithGearPN));

  /* Logic: '<S221>/Logical Operator10' incorporates:
   *  Constant: '<S221>/Constant'
   *  Constant: '<S229>/Constant'
   *  Constant: '<S234>/Constant'
   *  RelationalOperator: '<S221>/Relational Operator5'
   *  RelationalOperator: '<S221>/Relational Operator7'
   *  Switch: '<S144>/Switch2'
   */
  rtb_LogicalOperator10 = ((drid_e_gearLvrPos == GearLeverPos_PARKING) ||
    (drid_e_gearLvrPos == GearLeverPos_NEUTRAL) || false);

  /* Logic: '<S226>/Logical Operator3' incorporates:
   *  Constant: '<S5>/Constant5'
   *  Inport generated from: '<Root>/In Bus Element30'
   *  RelationalOperator: '<S5>/Relational Operator2'
   */
  rtb_LogicalOperator3_l = (Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_st_ptRdyInd()
    == ((uint8)1U));

  /* Logic: '<S5>/Logical Operator1' */
  rtb_LogicalOperator1_c = !rtb_LogicalOperator3_l;

  /* Logic: '<S225>/Logical Operator' incorporates:
   *  Constant: '<S238>/Constant'
   *  Inport generated from: '<Root>/In Bus Element21'
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Inport generated from: '<Root>/In Bus Element122'
   *  Inport generated from: '<Root>/In Bus Element28'
   *  Logic: '<S225>/Logical Operator3'
   *  Logic: '<S225>/Logical Operator5'
   *  Logic: '<S225>/Logical Operator7'
   *  RelationalOperator: '<S225>/Relational Operator1'
   */
  rtb_LogicalOperator = (Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ignOn() &&
    (vsmd_b_StartDemRaw_tmp != ChargerStatus_CONFIRMED_PLUGGED) &&
    (!Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_rlyTmOut()) &&
    (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_cesd_b_EmergencyStop()) &&
    swc_VOMM_ConstB.LogicalOperator6 &&
    (!Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_fltPwrShutDn()));

  /* Switch: '<S242>/Switch2' incorporates:
   *  Constant: '<S240>/vsmc_b_PTEnabled_ovrdflg'
   */
  if (vsmc_b_PTEnabled_ovrdflg) {
    /* Switch: '<S242>/Switch2' incorporates:
     *  Constant: '<S240>/vsmc_b_PTEnabled_ovrdval'
     */
    vsmd_b_PTEnabled = vsmc_b_PTEnabled_ovrdval;
  } else {
    /* Switch: '<S242>/Switch2' */
    vsmd_b_PTEnabled = rtb_LogicalOperator;
  }

  /* End of Switch: '<S242>/Switch2' */

  /* Chart: '<S5>/VehicleStartManager' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant13'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant7'
   *  Inport generated from: '<Root>/In Bus Element26'
   *  Logic: '<S5>/Logical Operator2'
   *  UnitDelay: '<S5>/Unit Delay4'
   */
  if (swc_VOMM_ARID_DEF.is_active_c6_vsm == 0U) {
    swc_VOMM_ARID_DEF.is_active_c6_vsm = 1U;
    swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_VEHICLE_OFF;
    vsmd_st_vsmStatus = 0U;
    swc_VOMM_ARID_DEF.StartReq = false;
  } else {
    switch (swc_VOMM_ARID_DEF.is_c6_vsm) {
     case swc_VOMM_IN_START_COMPLETE:
      vsmd_st_vsmStatus = 3U;
      if (!vsmd_b_PTEnabled) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_VEHICLE_OFF;
        vsmd_st_vsmStatus = 0U;
        swc_VOMM_ARID_DEF.StartReq = false;
      }
      break;

     case swc_VOMM_IN_START_DEMAND_LATCH:
      vsmd_st_vsmStatus = 1U;
      if ((!vsmd_b_PTEnabled) || rtb_LogicalOperator8) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_VEHICLE_OFF;
        vsmd_st_vsmStatus = 0U;
        swc_VOMM_ARID_DEF.StartReq = false;
      } else if (Rte_IRead_swc_VOMM_Step_vcsb_HVSM_eadd_b_ead2Avail() ||
                 (swc_VOMM_ARID_DEF.StartDemLatchTimer >=
                  vsmc_tm_StartDemLatchTimeout_s)) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_START_REQ;
        vsmd_st_vsmStatus = 2U;
        swc_VOMM_ARID_DEF.StartReq = true;
        swc_VOMM_ARID_DEF.StartReqTimer = 0.0F;
      } else {
        swc_VOMM_ARID_DEF.StartDemLatchTimer += ((float32)VSM_TASK_INTERVAL_S);
      }
      break;

     case swc_VOMM_IN_START_REQ:
      vsmd_st_vsmStatus = 2U;
      if (swc_VOMM_ARID_DEF.UnitDelay4_DSTATE) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_START_COMPLETE;
        vsmd_st_vsmStatus = 3U;
        swc_VOMM_ARID_DEF.StartReq = true;
      } else if ((!vsmd_b_PTEnabled) || rtb_LogicalOperator8 ||
                 (swc_VOMM_ARID_DEF.StartReqTimer >= vsmc_tm_StartReqTimeout_s))
      {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_VEHICLE_OFF;
        vsmd_st_vsmStatus = 0U;
        swc_VOMM_ARID_DEF.StartReq = false;
      } else {
        swc_VOMM_ARID_DEF.StartReqTimer += ((float32)VSM_TASK_INTERVAL_S);
      }
      break;

     default:
      /* case IN_VEHICLE_OFF: */
      vsmd_st_vsmStatus = 0U;
      if (vsmd_b_PTEnabled && vsmd_b_StartDemRaw && (!vsmc_b_enableQuickStrt)) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_START_DEMAND_LATCH;
        vsmd_st_vsmStatus = 1U;
        swc_VOMM_ARID_DEF.StartReq = false;
        swc_VOMM_ARID_DEF.StartDemLatchTimer = 0.0F;
      } else if (vsmd_b_PTEnabled && vsmd_b_StartDemRaw &&
                 vsmc_b_enableQuickStrt) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_START_REQ;
        vsmd_st_vsmStatus = 2U;
        swc_VOMM_ARID_DEF.StartReq = true;
        swc_VOMM_ARID_DEF.StartReqTimer = 0.0F;
      } else if (vsmd_b_PTEnabled && swc_VOMM_ARID_DEF.UnitDelay4_DSTATE) {
        swc_VOMM_ARID_DEF.is_c6_vsm = swc_VOMM_IN_START_COMPLETE;
        vsmd_st_vsmStatus = 3U;
        swc_VOMM_ARID_DEF.StartReq = true;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/VehicleStartManager' */

  /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
   *  Constant: '<S5>/Constant6'
   */
  rtb_LogicalOperator8 = (vsmd_st_vsmStatus == ((uint8)3U));

  /* Logic: '<S5>/Logical Operator6' */
  rtb_LogicalOperator6_j = (rtb_LogicalOperator3_l && rtb_LogicalOperator8);

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch' */
  swc_VOMM_SR_latch(rtb_LogicalOperator6_j, rtb_LogicalOperator1_c,
                    &rtb_LogicalOperator3_l,
                    &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_pp);

  /* End of Outputs for SubSystem: '<S5>/SR_latch' */

  /* Switch: '<S235>/Switch2' incorporates:
   *  Constant: '<S219>/Constant'
   *  Constant: '<S222>/vsmc_b_VehRun_ovrdflg'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S5>/Constant8'
   *  Logic: '<S5>/Logical Operator3'
   *  RelationalOperator: '<S219>/Compare'
   *  Switch: '<S5>/Switch2'
   */
  if (vsmc_b_VehRun_ovrdflg) {
    /* Switch: '<S235>/Switch2' incorporates:
     *  Constant: '<S222>/vsmc_b_VehRun_ovrdval'
     */
    vsmd_b_VehRun = vsmc_b_VehRun_ovrdval;
  } else if ((((uint8)VEH_SWT_INF) != ((uint8)4U)) ||
             swcvomm_vsmc_b_enaPTReadyVehRun) {
    /* Switch: '<S5>/Switch2' incorporates:
     *  Switch: '<S235>/Switch2'
     */
    vsmd_b_VehRun = rtb_LogicalOperator3_l;
  } else {
    /* Switch: '<S235>/Switch2' incorporates:
     *  Switch: '<S5>/Switch2'
     */
    vsmd_b_VehRun = rtb_LogicalOperator8;
  }

  /* End of Switch: '<S235>/Switch2' */

  /* Switch: '<S236>/Switch2' incorporates:
   *  Constant: '<S223>/vsmc_b_VehRunRaw_ovrdflg'
   */
  if (vsmc_b_VehRunRaw_ovrdflg) {
    /* Switch: '<S236>/Switch2' incorporates:
     *  Constant: '<S223>/vsmc_b_VehRunRaw_ovrdval'
     */
    vsmd_b_VehRunRaw = vsmc_b_VehRunRaw_ovrdval;
  } else {
    /* Switch: '<S236>/Switch2' incorporates:
     *  Constant: '<S220>/Constant'
     *  Constant: '<S5>/Constant9'
     *  Inport generated from: '<Root>/In Bus Element19'
     *  Logic: '<S5>/Logical Operator4'
     *  Logic: '<S5>/Logical Operator5'
     *  Logic: '<S5>/Logical Operator7'
     *  RelationalOperator: '<S220>/Compare'
     */
    vsmd_b_VehRunRaw = (rtb_LogicalOperator8 &&
                        ((!Rte_IRead_swc_VOMM_Step_vcsb_AUXC_brpd_b_airTankPresLowInhDrv
                          ()) || (((uint8)VEH_SWT_INF) != ((uint8)4U))));
  }

  /* End of Switch: '<S236>/Switch2' */

  /* Switch: '<S237>/Switch2' incorporates:
   *  Constant: '<S224>/vsmc_b_VehStrt_ovrdflg'
   */
  if (vsmc_b_VehStrt_ovrdflg) {
    /* Switch: '<S237>/Switch2' incorporates:
     *  Constant: '<S224>/vsmc_b_VehStrt_ovrdval'
     */
    vsmd_b_VehStrt = vsmc_b_VehStrt_ovrdval;
  } else {
    /* Switch: '<S237>/Switch2' */
    vsmd_b_VehStrt = swc_VOMM_ARID_DEF.StartReq;
  }

  /* End of Switch: '<S237>/Switch2' */

  /* Switch: '<S241>/Switch2' incorporates:
   *  Constant: '<S239>/vsmc_b_PTDisabled_ovrdflg'
   */
  if (vsmc_b_PTDisabled_ovrdflg) {
    /* Switch: '<S241>/Switch2' incorporates:
     *  Constant: '<S239>/vsmc_b_PTDisabled_ovrdval'
     */
    vsmd_b_PTDisabled = vsmc_b_PTDisabled_ovrdval;
  } else {
    /* Switch: '<S241>/Switch2' incorporates:
     *  Constant: '<S225>/Constant5'
     *  Logic: '<S225>/Logical Operator2'
     *  Logic: '<S225>/Logical Operator4'
     *  RelationalOperator: '<S225>/Relational Operator2'
     */
    vsmd_b_PTDisabled = ((rtb_RelationalOperator2_f_tmp <= vsmc_v_PTOffThr_kph) &&
                         (!rtb_LogicalOperator));
  }

  /* Update for UnitDelay: '<S5>/Unit Delay4' */
  swc_VOMM_ARID_DEF.UnitDelay4_DSTATE = hmmd_b_EVModeActive;
}

/*
 * System initialize for atomic system:
 *    '<S6>/turnON_delay_4WD'
 *    '<S6>/turnON_delay_ECO'
 *    '<S6>/turnON_delay_EV'
 *    '<S6>/turnON_delay_HEV'
 *    '<S6>/turnON_delay_SPORT'
 *    '<S99>/turnON_delay'
 *    '<S105>/turnON_delay'
 *    '<S111>/turnON_delay'
 *    '<S117>/turnON_delay'
 *    '<S66>/turnON_delay'
 *    ...
 */
static void swc_VOMM_turnON_delay_4WD_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S14>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S6>/turnON_delay_4WD'
 *    '<S6>/turnON_delay_ECO'
 *    '<S6>/turnON_delay_EV'
 *    '<S6>/turnON_delay_HEV'
 *    '<S6>/turnON_delay_SPORT'
 *    '<S99>/turnON_delay'
 *    '<S105>/turnON_delay'
 *    '<S111>/turnON_delay'
 *    '<S117>/turnON_delay'
 *    '<S66>/turnON_delay'
 *    ...
 */
static void swc_VOMM_turnON_delay_4WD(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_4WD_swc_T
  *swc_VOMM__ARID_DEF_arg)
{
  float32 rtb_t_delay_on_m;

  /* Saturate: '<S14>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S14>/Saturation' */
    rtb_t_delay_on_m = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S14>/Saturation' */
    rtb_t_delay_on_m = 0.0F;
  } else {
    /* Saturate: '<S14>/Saturation' */
    rtb_t_delay_on_m = rtu_t_delay_on;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Chart: '<S14>/timed_delay' incorporates:
   *  DataTypeConversion: '<S14>/Data Type Conversion'
   */
  if (swc_VOMM__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_VOMM__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_j;
      *rty_flg_out = true;
    } else {
      swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_l;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_VOMM_IN_OFF_l:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_m == 0.0F) {
          swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_j;
          *rty_flg_out = true;
        } else {
          swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_VOMM_IN_ON_WAIT;
          swc_VOMM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_VOMM_IN_ON_j:
      if (!rtu_flg_in) {
        swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_l;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_l;
        *rty_flg_out = false;
      } else if (swc_VOMM__ARID_DEF_arg->t_wait > rtb_t_delay_on_m - rtu_t_step)
      {
        swc_VOMM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_j;
        *rty_flg_out = true;
      } else {
        swc_VOMM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S14>/timed_delay' */
}

/* System initialize for function-call system: '<S1>/DRI_DriveModesManagment' */
static void sw_DRI_DriveModesManagment_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_k;
  boolean rtb_flg_out_kj;
  boolean rtb_flg_out_eq;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_i;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_p;
  boolean rtb_flg_out_lh;
  boolean rtb_flg_out_k2;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_ez;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_ey;
  boolean rtb_flg_out_d;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
  swc_VOMM_ARID_DEF.UnitDelay1_DSTATE = true;

  /* SystemInitialize for Atomic SubSystem: '<S6>/turnON_delay_EV' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_f);

  /* End of SystemInitialize for SubSystem: '<S6>/turnON_delay_EV' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/turnON_delay_HEV' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_ez);

  /* End of SystemInitialize for SubSystem: '<S6>/turnON_delay_HEV' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/turnON_delay_ECO' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_ey);

  /* End of SystemInitialize for SubSystem: '<S6>/turnON_delay_ECO' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/turnON_delay_SPORT' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_j);

  /* End of SystemInitialize for SubSystem: '<S6>/turnON_delay_SPORT' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/turnON_delay_4WD' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_d);

  /* End of SystemInitialize for SubSystem: '<S6>/turnON_delay_4WD' */

  /* SystemInitialize for Enabled SubSystem: '<S7>/Calc_GearLeverPos1' */
  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
  swc_VOMM_ARID_DEF.UnitDelay_DSTATE_c = GearLeverPos_NEUTRAL;

  /* End of SystemInitialize for SubSystem: '<S7>/Calc_GearLeverPos1' */

  /* SystemInitialize for Enabled SubSystem: '<S7>/Calc_GearLeverPos2' */
  /* SystemInitialize for Atomic SubSystem: '<S76>/turnON_delay5' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_eq);

  /* End of SystemInitialize for SubSystem: '<S76>/turnON_delay5' */

  /* SystemInitialize for Atomic SubSystem: '<S77>/turnON_delay' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_kj);

  /* End of SystemInitialize for SubSystem: '<S77>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S77>/turnON_delay1' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_k);

  /* End of SystemInitialize for SubSystem: '<S77>/turnON_delay1' */

  /* SystemInitialize for Enabled SubSystem: '<S66>/GearP' */
  /* SystemInitialize for Atomic SubSystem: '<S111>/turnON_delay' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_p);

  /* End of SystemInitialize for SubSystem: '<S111>/turnON_delay' */
  /* End of SystemInitialize for SubSystem: '<S66>/GearP' */

  /* SystemInitialize for Enabled SubSystem: '<S66>/GearN' */
  /* InitializeConditions for UnitDelay: '<S87>/Unit Delay3' */
  swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_p = GearLeverPos_NEUTRAL;

  /* SystemInitialize for Atomic SubSystem: '<S105>/turnON_delay' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_lh);

  /* End of SystemInitialize for SubSystem: '<S105>/turnON_delay' */
  /* End of SystemInitialize for SubSystem: '<S66>/GearN' */

  /* SystemInitialize for Enabled SubSystem: '<S66>/GearD' */
  /* InitializeConditions for UnitDelay: '<S86>/Unit Delay3' */
  swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_m = GearLeverPos_FWD_DRIVE;

  /* SystemInitialize for Atomic SubSystem: '<S99>/turnON_delay' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_k2);

  /* End of SystemInitialize for SubSystem: '<S99>/turnON_delay' */
  /* End of SystemInitialize for SubSystem: '<S66>/GearD' */

  /* SystemInitialize for Enabled SubSystem: '<S66>/GearR' */
  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay3' */
  swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_c = GearLeverPos_REV_DRIVE;

  /* SystemInitialize for Atomic SubSystem: '<S117>/turnON_delay' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_l);

  /* End of SystemInitialize for SubSystem: '<S117>/turnON_delay' */
  /* End of SystemInitialize for SubSystem: '<S66>/GearR' */

  /* SystemInitialize for Merge: '<S66>/Merge' */
  swc_VOMM_ARID_DEF.Merge = false;

  /* SystemInitialize for Atomic SubSystem: '<S66>/turnON_delay' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_i);

  /* End of SystemInitialize for SubSystem: '<S66>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S66>/turnON_delay1' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_o);

  /* End of SystemInitialize for SubSystem: '<S66>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S66>/turnON_delay2' */
  swc_VOMM_turnON_delay_4WD_Init(&rtb_flg_out_g);

  /* End of SystemInitialize for SubSystem: '<S66>/turnON_delay2' */
  /* End of SystemInitialize for SubSystem: '<S7>/Calc_GearLeverPos2' */
}

/* Output and update for function-call system: '<S1>/DRI_DriveModesManagment' */
static void swc_VOM_DRI_DriveModesManagment(void)
{
  /* local block i/o variables */
  boolean rtb_drid_b_vehSportModActv;
  boolean rtb_AND;
  boolean rtb_FixPtRelationalOperator_a;
  boolean rtb_LogicalOperator6_b;
  boolean rtb_FixPtRelationalOperator_d;
  boolean rtb_RelationalOperator12_h;
  boolean rtb_LogicalOperator4_g;
  boolean rtb_FixPtRelationalOperator_dn;
  boolean rtb_RelationalOperator2_e;
  boolean rtb_RelationalOperator10_j;
  boolean rtb_FixPtRelationalOperator_g;
  boolean rtb_UnitDelay9_h;
  boolean rtb_UnitDelay1_d;
  boolean rtb_UnitDelay2_m;
  boolean rtb_Switch5_k;
  boolean rtb_flg_out_k;
  boolean rtb_flg_out_kj;
  boolean rtb_flg_out_eq;
  boolean rtb_LogicalOperator3_mf;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_i;
  boolean rtb_LogicalOperator3_p;
  boolean rtb_RelationalOperator6_c;
  boolean rtb_RelationalOperator2_j;
  boolean rtb_LogicalOperator1_f;
  boolean rtb_flg_out_l;
  boolean rtb_LogicalOperator3_f;
  boolean rtb_LogicalOperator_n;
  boolean rtb_RelationalOperator2_og;
  boolean rtb_LogicalOperator1_i;
  boolean rtb_flg_out_p;
  boolean rtb_LogicalOperator3_am;
  boolean rtb_LogicalOperator_l;
  boolean rtb_RelationalOperator2_jm;
  boolean rtb_LogicalOperator1_pu;
  boolean rtb_flg_out_lh;
  boolean rtb_LogicalOperator3_lb;
  boolean rtb_RelationalOperator1_l;
  boolean rtb_RelationalOperator2_d;
  boolean rtb_LogicalOperator1_iu;
  boolean rtb_flg_out_k2;
  boolean rtb_LogicalOperator3_b;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_ez;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_ey;
  boolean rtb_flg_out_d;
  boolean rtb_LogicalOperator3_fi;
  boolean rtb_LogicalOperator3_d;
  sint32 tmp_0;
  float32 rtb_LogicalOperator1_o_tmp;
  uint16 rtb_Gain1;
  uint16 rtb_Gain2;
  uint16 rtb_Gain3;
  GearLeverPos rtb_RelationalOperator1_m3_tmp;
  HEVModeReq rtb_Switch_e;
  uint8 rtb_DataTypeConversion_n;
  uint8 rtb_Saturation1;
  boolean drid_b_DriModAct_tmp;
  boolean rtb_BrkPdlPushFstFlg;
  boolean rtb_FixPtRelationalOperator;
  boolean rtb_FixPtRelationalOperator_tmp;
  boolean rtb_LogicalOperator1_j3;
  boolean rtb_LogicalOperator2_f;
  boolean rtb_LogicalOperator6_jj_tmp;
  boolean rtb_RelationalOperator10_ht;
  boolean rtb_RelationalOperator1_o;
  boolean rtb_RelationalOperator2_cb;
  boolean rtb_RelationalOperator4_m;
  boolean rtb_RelationalOperator7_l;
  boolean tmp_1;

  /* Outputs for Atomic SubSystem: '<S6>/turnON_delay_EV' */
  /* Inport generated from: '<Root>/In Bus Element34' incorporates:
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   */
  swc_VOMM_turnON_delay_4WD
    (Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqEV(),
     dric_tm_driverModeReqEVDeb_s, ((float32)DRI_TASK_INTERVAL_S),
     &rtb_flg_out_f, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_EV);

  /* End of Outputs for SubSystem: '<S6>/turnON_delay_EV' */

  /* Gain: '<S6>/Gain2' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   */
  rtb_Gain2 = (uint16)((uint32)((uint8)128U) * rtb_flg_out_f);

  /* Outputs for Atomic SubSystem: '<S6>/turnON_delay_HEV' */
  /* Inport generated from: '<Root>/In Bus Element35' incorporates:
   *  Constant: '<S6>/Constant13'
   *  Constant: '<S6>/Constant14'
   */
  swc_VOMM_turnON_delay_4WD
    (Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqHEV(),
     dric_tm_driverModeReqHEVDeb_s, ((float32)DRI_TASK_INTERVAL_S),
     &rtb_flg_out_ez, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_HEV);

  /* End of Outputs for SubSystem: '<S6>/turnON_delay_HEV' */

  /* Gain: '<S6>/Gain1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   */
  rtb_Gain1 = (uint16)((uint32)((uint8)128U) * rtb_flg_out_ez);

  /* Outputs for Atomic SubSystem: '<S6>/turnON_delay_ECO' */
  /* Inport generated from: '<Root>/In Bus Element36' incorporates:
   *  Constant: '<S6>/Constant6'
   *  Constant: '<S6>/Constant7'
   */
  swc_VOMM_turnON_delay_4WD
    (Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqECO(),
     dric_tm_driverModeReqECODeb_s, ((float32)DRI_TASK_INTERVAL_S),
     &rtb_flg_out_ey, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_ECO);

  /* End of Outputs for SubSystem: '<S6>/turnON_delay_ECO' */

  /* Gain: '<S6>/Gain3' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion3'
   */
  rtb_Gain3 = (uint16)((uint32)((uint8)128U) * rtb_flg_out_ey);

  /* RelationalOperator: '<S153>/FixPt Relational Operator' incorporates:
   *  Inport generated from: '<Root>/In Bus Element113'
   *  UnitDelay: '<S153>/Delay Input1'
   * *
   * Block description for '<S153>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_tmp =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReq();

  /* RelationalOperator: '<S153>/FixPt Relational Operator' incorporates:
   *  Inport generated from: '<Root>/In Bus Element113'
   *  UnitDelay: '<S153>/Delay Input1'
   *
   * Block description for '<S153>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((sint32)rtb_FixPtRelationalOperator_tmp >
    (sint32)swc_VOMM_ARID_DEF.DelayInput1_DSTATE);

  /* Logic: '<S8>/AND' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   *  UnitDelay: '<S11>/Delay Input1'
   * *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator6_jj_tmp = Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ignOn();

  /* RelationalOperator: '<S152>/Compare' incorporates:
   *  Inport generated from: '<Root>/BusElementIn1'
   *  RelationalOperator: '<S151>/Compare'
   */
  drid_b_DriModAct_tmp =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgDrvModStor();

  /* Logic: '<S8>/AND' incorporates:
   *  Constant: '<S152>/Constant'
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Inport generated from: '<Root>/BusElementIn1'
   *  RelationalOperator: '<S152>/Compare'
   */
  drid_b_DriModAct = (rtb_LogicalOperator6_jj_tmp && (drid_b_DriModAct_tmp ==
    false));

  /* Outputs for Enabled SubSystem: '<S8>/Subsystem' incorporates:
   *  EnablePort: '<S155>/Enable'
   */
  if (drid_b_DriModAct) {
    /* CCaller: '<S155>/C Caller1' */
    drid_st_DriModRead = mBSW_NvmRead_DriMod();
  }

  /* End of Outputs for SubSystem: '<S8>/Subsystem' */

  /* Chart: '<S161>/DriverMode' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Logic: '<S8>/AND'
   */
  if (swc_VOMM_ARID_DEF.is_active_c6_swc_VOMM == 0U) {
    swc_VOMM_ARID_DEF.is_active_c6_swc_VOMM = 1U;
    swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_INIT_j;
    swc_VOMM_ARID_DEF.EcoMod_j = false;
    swc_VOMM_ARID_DEF.SportMod_o = false;
    swc_VOMM_ARID_DEF.T_b = 0U;
    swc_VOMM_ARID_DEF.InitMod_n = false;
  } else {
    switch (swc_VOMM_ARID_DEF.is_c6_swc_VOMM) {
     case swc_VOMM_IN_ECO:
      if (rtb_FixPtRelationalOperator) {
        swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_NORMAL;
        swc_VOMM_ARID_DEF.EcoMod_j = false;
        swc_VOMM_ARID_DEF.SportMod_o = false;
      }
      break;

     case swc_VOMM_IN_INIT_j:
      if ((rtb_LogicalOperator6_jj_tmp && (swc_VOMM_ARID_DEF.T_b > 10) &&
           ((drid_st_DriModRead != 1) && (drid_st_DriModRead != 2) &&
            (drid_st_DriModRead != 3))) || (drid_st_DriModRead == 1)) {
        swc_VOMM_ARID_DEF.InitMod_n = true;
        swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_NORMAL;
        swc_VOMM_ARID_DEF.EcoMod_j = false;
        swc_VOMM_ARID_DEF.SportMod_o = false;
      } else {
        switch (drid_st_DriModRead) {
         case 2:
          swc_VOMM_ARID_DEF.InitMod_n = true;
          swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_SPORT_b;
          swc_VOMM_ARID_DEF.EcoMod_j = false;
          swc_VOMM_ARID_DEF.SportMod_o = true;
          break;

         case 3:
          swc_VOMM_ARID_DEF.InitMod_n = true;
          swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_ECO;
          swc_VOMM_ARID_DEF.EcoMod_j = true;
          swc_VOMM_ARID_DEF.SportMod_o = false;
          break;

         default:
          tmp_0 = swc_VOMM_ARID_DEF.T_b + 1;
          if (swc_VOMM_ARID_DEF.T_b + 1 > 65535) {
            tmp_0 = 65535;
          }

          swc_VOMM_ARID_DEF.T_b = (uint16)tmp_0;
          break;
        }
      }
      break;

     case swc_VOMM_IN_NORMAL:
      if (rtb_FixPtRelationalOperator) {
        swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_SPORT_b;
        swc_VOMM_ARID_DEF.EcoMod_j = false;
        swc_VOMM_ARID_DEF.SportMod_o = true;
      }
      break;

     default:
      /* case IN_SPORT: */
      if (rtb_FixPtRelationalOperator) {
        swc_VOMM_ARID_DEF.is_c6_swc_VOMM = swc_VOMM_IN_ECO;
        swc_VOMM_ARID_DEF.EcoMod_j = true;
        swc_VOMM_ARID_DEF.SportMod_o = false;
      }
      break;
    }
  }

  /* End of Chart: '<S161>/DriverMode' */

  /* Chart: '<S162>/DriverMode' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Inport generated from: '<Root>/BusElementIn4'
   *  Logic: '<S8>/AND'
   */
  if (swc_VOMM_ARID_DEF.is_active_c7_swc_VOMM == 0U) {
    swc_VOMM_ARID_DEF.is_active_c7_swc_VOMM = 1U;
    swc_VOMM_ARID_DEF.is_c7_swc_VOMM = swc_VOMM_IN_INIT_j;
    swc_VOMM_ARID_DEF.EcoMod = false;
    swc_VOMM_ARID_DEF.SportMod = false;
    swc_VOMM_ARID_DEF.T = 0U;
    swc_VOMM_ARID_DEF.InitMod = false;
  } else {
    switch (swc_VOMM_ARID_DEF.is_c7_swc_VOMM) {
     case swc_VOMM_IN_ECO:
      if (rtb_FixPtRelationalOperator) {
        swc_VOMM_ARID_DEF.is_c7_swc_VOMM = swc_VOMM_IN_NORMAL;
        swc_VOMM_ARID_DEF.EcoMod = false;
        swc_VOMM_ARID_DEF.SportMod = false;
      }
      break;

     case swc_VOMM_IN_INIT_j:
      tmp_0 = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg();
      if ((rtb_LogicalOperator6_jj_tmp && (swc_VOMM_ARID_DEF.T > 10) &&
           ((drid_st_DriModRead != 1) && (drid_st_DriModRead != 3)) && (tmp_0 !=
            1)) || (drid_st_DriModRead == 1)) {
        swc_VOMM_ARID_DEF.InitMod = true;
        swc_VOMM_ARID_DEF.is_c7_swc_VOMM = swc_VOMM_IN_NORMAL;
        swc_VOMM_ARID_DEF.EcoMod = false;
        swc_VOMM_ARID_DEF.SportMod = false;
      } else if ((rtb_LogicalOperator6_jj_tmp && (swc_VOMM_ARID_DEF.T > 10) &&
                  ((drid_st_DriModRead != 1) && (drid_st_DriModRead != 3)) &&
                  (tmp_0 == 1)) || (drid_st_DriModRead == 3)) {
        swc_VOMM_ARID_DEF.InitMod = true;
        swc_VOMM_ARID_DEF.is_c7_swc_VOMM = swc_VOMM_IN_ECO;
        swc_VOMM_ARID_DEF.EcoMod = true;
        swc_VOMM_ARID_DEF.SportMod = false;
      } else {
        tmp_0 = swc_VOMM_ARID_DEF.T + 1;
        if (swc_VOMM_ARID_DEF.T + 1 > 65535) {
          tmp_0 = 65535;
        }

        swc_VOMM_ARID_DEF.T = (uint16)tmp_0;
      }
      break;

     default:
      /* case IN_NORMAL: */
      if (rtb_FixPtRelationalOperator) {
        swc_VOMM_ARID_DEF.is_c7_swc_VOMM = swc_VOMM_IN_ECO;
        swc_VOMM_ARID_DEF.EcoMod = true;
        swc_VOMM_ARID_DEF.SportMod = false;
      }
      break;
    }
  }

  /* End of Chart: '<S162>/DriverMode' */

  /* RelationalOperator: '<S158>/Compare' incorporates:
   *  Inport generated from: '<Root>/BusElementIn12'
   *  RelationalOperator: '<S159>/Compare'
   *  RelationalOperator: '<S160>/Compare'
   */
  tmp_0 = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgDrvMod();

  /* Switch: '<S157>/Switch' incorporates:
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S158>/Compare'
   */
  if (tmp_0 == true) {
    /* Switch: '<S157>/Switch' */
    drid_b_vehSportModActv = swc_VOMM_ARID_DEF.SportMod_o;
  } else {
    /* Switch: '<S157>/Switch' */
    drid_b_vehSportModActv = swc_VOMM_ARID_DEF.SportMod;
  }

  /* End of Switch: '<S157>/Switch' */

  /* Outputs for Atomic SubSystem: '<S6>/turnON_delay_SPORT' */
  /* Constant: '<S6>/Constant9' incorporates:
   *  Constant: '<S6>/Constant8'
   */
  swc_VOMM_turnON_delay_4WD(drid_b_vehSportModActv,
    dric_tm_driverModeReqSPORTDeb_s, ((float32)DRI_TASK_INTERVAL_S),
    &rtb_flg_out_j, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_SPORT);

  /* End of Outputs for SubSystem: '<S6>/turnON_delay_SPORT' */

  /* Outputs for Atomic SubSystem: '<S6>/turnON_delay_4WD' */
  /* Inport generated from: '<Root>/In Bus Element38' incorporates:
   *  Constant: '<S6>/Constant10'
   *  Constant: '<S6>/Constant11'
   */
  swc_VOMM_turnON_delay_4WD
    (Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReq4WD(),
     dric_tm_driverModeReq4WDDeb_s, ((float32)DRI_TASK_INTERVAL_S),
     &rtb_flg_out_d, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_4WD);

  /* End of Outputs for SubSystem: '<S6>/turnON_delay_4WD' */

  /* Sum: '<S6>/Sum4' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion4'
   *  DataTypeConversion: '<S6>/Data Type Conversion5'
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  Gain: '<S6>/Gain3'
   *  Gain: '<S6>/Gain4'
   *  Gain: '<S6>/Gain5'
   */
  rtb_Gain2 = (uint16)(((((((uint32)rtb_Gain1 << 1) + rtb_Gain2) + ((uint32)
    rtb_Gain3 << 2)) + (((uint32)((uint8)128U) * rtb_flg_out_j) << 3)) +
                        (((uint32)((uint8)128U) * rtb_flg_out_d) << 4)) >> 4);

  /* Outputs for Atomic SubSystem: '<S6>/state_mapping' */
  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Sum: '<S6>/Sum4'
   */
  rtb_DataTypeConversion_n = (uint8)((uint32)rtb_Gain2 >> 3);

  /* Saturate: '<S13>/Saturation1' */
  if (rtb_DataTypeConversion_n <= ((uint8)31U)) {
    /* Saturate: '<S13>/Saturation1' */
    rtb_Saturation1 = rtb_DataTypeConversion_n;
  } else {
    /* Saturate: '<S13>/Saturation1' */
    rtb_Saturation1 = ((uint8)31U);
  }

  /* End of Saturate: '<S13>/Saturation1' */

  /* Switch: '<S13>/Switch' incorporates:
   *  RelationalOperator: '<S13>/Relational Operator'
   */
  if (rtb_DataTypeConversion_n > rtb_Saturation1) {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     */
    rtb_Switch_e = HEVModeReq_EV;
  } else {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S6>/Constant18'
     *  MultiPortSwitch: '<S13>/Index Vector'
     */
    rtb_Switch_e = dric_e_driverModeReqSel[rtb_Saturation1];
  }

  /* End of Switch: '<S13>/Switch' */
  /* End of Outputs for SubSystem: '<S6>/state_mapping' */

  /* Switch: '<S6>/Switch8' incorporates:
   *  Constant: '<S6>/Constant16'
   *  Constant: '<S9>/Constant'
   *  Inport generated from: '<Root>/In Bus Element6'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator2'
   *  Logic: '<S8>/AND'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  RelationalOperator: '<S9>/Compare'
   *  Sum: '<S6>/Sum4'
   *  Switch: '<S6>/Switch3'
   *  UnitDelay: '<S11>/Delay Input1'
   *  UnitDelay: '<S6>/Unit Delay1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((((sint32)rtb_LogicalOperator6_jj_tmp > (sint32)
        swc_VOMM_ARID_DEF.DelayInput1_DSTATE_l) && dric_b_resetModeReqAtIgnON) ||
      swc_VOMM_ARID_DEF.UnitDelay1_DSTATE) {
    /* Switch: '<S6>/Switch8' incorporates:
     *  Constant: '<S6>/Constant17'
     */
    drid_e_drvrHEVModReq = dric_e_driverModeReqInit;
  } else if (rtb_Gain2 == ((uint16)0U)) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S6>/Constant1'
     *  RelationalOperator: '<S10>/Compare'
     *  Switch: '<S6>/Switch3'
     */
    if (((uint8)VEH_SWT_INF) != ((uint8)4U)) {
      /* Switch: '<S6>/Switch8' incorporates:
       *  Switch: '<S6>/Switch3'
       *  UnitDelay: '<S6>/Unit Delay'
       */
      drid_e_drvrHEVModReq = swc_VOMM_ARID_DEF.UnitDelay_DSTATE_m;
    } else {
      /* Switch: '<S6>/Switch8' incorporates:
       *  Switch: '<S13>/Switch'
       *  Switch: '<S6>/Switch3'
       */
      drid_e_drvrHEVModReq = rtb_Switch_e;
    }

    /* End of Switch: '<S6>/Switch1' */
  } else {
    /* Switch: '<S6>/Switch8' incorporates:
     *  Switch: '<S13>/Switch'
     *  Switch: '<S6>/Switch3'
     */
    drid_e_drvrHEVModReq = rtb_Switch_e;
  }

  /* End of Switch: '<S6>/Switch8' */

  /* Outputs for Enabled SubSystem: '<S7>/Calc_GearLeverPos1' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  /* Constant: '<S7>/Constant1' */
  if (dric_b_useGearLvrPosFromCan) {
    /* RelationalOperator: '<S24>/Relational Operator8' incorporates:
     *  Constant: '<S35>/Constant'
     *  Inport generated from: '<Root>/In Bus Element15'
     */
    rtb_FixPtRelationalOperator =
      (Rte_IRead_swc_VOMM_Step_vcib_VCIP_brpd_e_brkPedalStatus() ==
       BrakePedalStatus_PRESSED);

    /* Chart: '<S24>/BrakePedalPushFirst' incorporates:
     *  Inport generated from: '<Root>/In Bus Element20'
     *  UnitDelay: '<S24>/Unit Delay'
     */
    if (swc_VOMM_ARID_DEF.is_active_c3_swc_VOMM == 0U) {
      swc_VOMM_ARID_DEF.is_active_c3_swc_VOMM = 1U;
      swc_VOMM_ARID_DEF.is_c3_swc_VOMM = swc_VOMM_IN_InitialState;
      rtb_BrkPdlPushFstFlg = false;
    } else {
      switch (swc_VOMM_ARID_DEF.is_c3_swc_VOMM) {
       case swc_VOMM_IN_BrakePushed:
        rtb_BrkPdlPushFstFlg = true;
        if (!rtb_FixPtRelationalOperator) {
          swc_VOMM_ARID_DEF.is_c3_swc_VOMM = swc_VOMM_IN_InitialState;
          rtb_BrkPdlPushFstFlg = false;
        }
        break;

       case swc_VOMM_IN_GearShifted:
        rtb_BrkPdlPushFstFlg = false;
        rtb_RelationalOperator1_m3_tmp =
          Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_e_gearLvrPosRaw();
        if ((rtb_RelationalOperator1_m3_tmp ==
             swc_VOMM_ARID_DEF.UnitDelay_DSTATE_c) ||
            (rtb_RelationalOperator1_m3_tmp == GearLeverPos_NEUTRAL)) {
          swc_VOMM_ARID_DEF.is_c3_swc_VOMM = swc_VOMM_IN_InitialState;
        }
        break;

       default:
        /* case IN_InitialState: */
        rtb_BrkPdlPushFstFlg = false;
        if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_e_gearLvrPosRaw() !=
            swc_VOMM_ARID_DEF.UnitDelay_DSTATE_c) {
          swc_VOMM_ARID_DEF.is_c3_swc_VOMM = swc_VOMM_IN_GearShifted;
        } else if (rtb_FixPtRelationalOperator) {
          swc_VOMM_ARID_DEF.is_c3_swc_VOMM = swc_VOMM_IN_BrakePushed;
          rtb_BrkPdlPushFstFlg = true;
        }
        break;
      }
    }

    /* End of Chart: '<S24>/BrakePedalPushFirst' */

    /* RelationalOperator: '<S24>/Relational Operator7' incorporates:
     *  Constant: '<S40>/Constant'
     *  Inport generated from: '<Root>/In Bus Element42'
     */
    rtb_RelationalOperator7_l =
      (Rte_IRead_swc_VOMM_Step_vcib_VCIP_epbd_e_parkingSts() ==
       ParkingStatus_ENGAGED);

    /* RelationalOperator: '<S24>/Relational Operator3' incorporates:
     *  Inport generated from: '<Root>/In Bus Element7'
     *  RelationalOperator: '<S24>/Relational Operator5'
     */
    rtb_LogicalOperator1_o_tmp =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_v_vehSpd_kph();

    /* Logic: '<S24>/Logical Operator1' incorporates:
     *  Inport generated from: '<Root>/In Bus Element45'
     *  Logic: '<S24>/Logical Operator2'
     */
    rtb_LogicalOperator2_f = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_b_vehSpdVld();

    /* Logic: '<S24>/Logical Operator1' incorporates:
     *  Constant: '<S24>/Constant2'
     *  Inport generated from: '<Root>/In Bus Element45'
     *  Inport generated from: '<Root>/In Bus Element7'
     *  RelationalOperator: '<S24>/Relational Operator3'
     */
    rtb_LogicalOperator1_j3 = (rtb_LogicalOperator2_f &&
      (rtb_LogicalOperator1_o_tmp < dric_v_vehStoppedThd_kph));

    /* Logic: '<S24>/Logical Operator2' incorporates:
     *  Constant: '<S24>/Constant1'
     *  RelationalOperator: '<S24>/Relational Operator5'
     */
    rtb_LogicalOperator2_f = (rtb_LogicalOperator2_f &&
      (rtb_LogicalOperator1_o_tmp > dric_v_vehMoveThd_kph));

    /* RelationalOperator: '<S24>/Relational Operator1' incorporates:
     *  Inport generated from: '<Root>/In Bus Element20'
     *  RelationalOperator: '<S24>/Relational Operator10'
     *  RelationalOperator: '<S24>/Relational Operator2'
     *  RelationalOperator: '<S24>/Relational Operator4'
     *  RelationalOperator: '<S24>/Relational Operator6'
     */
    rtb_RelationalOperator1_m3_tmp =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_e_gearLvrPosRaw();

    /* RelationalOperator: '<S24>/Relational Operator1' incorporates:
     *  Constant: '<S34>/Constant'
     */
    rtb_RelationalOperator1_o = (rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_PARKING);

    /* RelationalOperator: '<S24>/Relational Operator2' incorporates:
     *  Constant: '<S36>/Constant'
     */
    rtb_RelationalOperator2_cb = (rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_REV_DRIVE);

    /* RelationalOperator: '<S24>/Relational Operator4' incorporates:
     *  Constant: '<S37>/Constant'
     */
    rtb_RelationalOperator4_m = (rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_NEUTRAL);

    /* RelationalOperator: '<S24>/Relational Operator10' incorporates:
     *  Constant: '<S38>/Constant'
     */
    rtb_RelationalOperator10_ht = (rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_FWD_DRIVE);

    /* Switch: '<S24>/Switch' incorporates:
     *  Inport generated from: '<Root>/BusElementIn2'
     */
    if (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFnctnConfgEGSM()) {
      /* Switch: '<S24>/Switch' incorporates:
       *  Constant: '<S24>/Constant4'
       */
      rtb_BrkPdlPushFstFlg = true;
    }

    /* End of Switch: '<S24>/Switch' */

    /* Chart: '<S24>/GearLeverPosition' incorporates:
     *  Constant: '<S24>/Constant10'
     *  Constant: '<S24>/Constant12'
     *  Constant: '<S39>/Constant'
     *  RelationalOperator: '<S24>/Relational Operator6'
     */
    if (swc_VOMM_ARID_DEF.is_active_c2_swc_VOMM == 0U) {
      swc_VOMM_ARID_DEF.is_active_c2_swc_VOMM = 1U;
      swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_UNKNOWN;
      swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_UNKNOWN;
      swc_VOMM_ARID_DEF.PowerUpTimer_b = 0.0F;
      swc_VOMM_ARID_DEF.GearLeverFrmD_c = false;
      swc_VOMM_ARID_DEF.GearLeverFrmR_m = false;
    } else {
      switch (swc_VOMM_ARID_DEF.is_c2_swc_VOMM) {
       case swc_VOMM_IN_DRIVE:
        swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_FWD_DRIVE;
        tmp_1 = !vsmd_b_VehRun;
        if (rtb_RelationalOperator1_o && rtb_LogicalOperator1_j3 &&
            (rtb_FixPtRelationalOperator || rtb_RelationalOperator7_l || tmp_1))
        {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_PARKING;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_PARKING;
        } else if (rtb_RelationalOperator4_m || tmp_1 || (vsmd_b_VehRun &&
                    rtb_RelationalOperator2_cb && rtb_FixPtRelationalOperator &&
                    rtb_BrkPdlPushFstFlg && rtb_LogicalOperator1_j3)) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_NEUTRAL;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_NEUTRAL;
        } else if (vsmd_b_VehRun && (rtb_RelationalOperator1_m3_tmp ==
                    GearLeverPos_SPT_DRIVE)) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_SPORT;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_SPT_DRIVE;
        }
        break;

       case swc_VOMM_IN_NEUTRAL:
        swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_NEUTRAL;
        if (rtb_RelationalOperator1_o && rtb_LogicalOperator1_j3 &&
            (rtb_FixPtRelationalOperator || rtb_RelationalOperator7_l ||
             (!vsmd_b_VehRun))) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_PARKING;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_PARKING;
        } else {
          tmp_1 = (vsmd_b_VehRun && rtb_RelationalOperator2_cb);
          if ((tmp_1 && rtb_FixPtRelationalOperator && rtb_BrkPdlPushFstFlg &&
               rtb_LogicalOperator1_j3) || (tmp_1 && rtb_LogicalOperator2_f && (
                !swc_VOMM_ARID_DEF.GearLeverFrmD_c))) {
            swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_REVERSE;
            swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_REV_DRIVE;
            swc_VOMM_ARID_DEF.GearLeverFrmD_c = false;
            swc_VOMM_ARID_DEF.GearLeverFrmR_m = true;
          } else if ((vsmd_b_VehRun && rtb_RelationalOperator10_ht &&
                      rtb_FixPtRelationalOperator && rtb_BrkPdlPushFstFlg &&
                      rtb_LogicalOperator1_j3) || (vsmd_b_VehRun &&
                      rtb_RelationalOperator10_ht && rtb_LogicalOperator2_f && (
                       !swc_VOMM_ARID_DEF.GearLeverFrmR_m))) {
            swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_DRIVE;
            swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_FWD_DRIVE;
            swc_VOMM_ARID_DEF.GearLeverFrmD_c = true;
            swc_VOMM_ARID_DEF.GearLeverFrmR_m = false;
          }
        }
        break;

       case swc_VOMM_IN_PARKING:
        swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_PARKING;
        if (rtb_RelationalOperator4_m) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_NEUTRAL;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_NEUTRAL;
        } else if (vsmd_b_VehRun && rtb_RelationalOperator10_ht &&
                   rtb_FixPtRelationalOperator && rtb_BrkPdlPushFstFlg &&
                   rtb_LogicalOperator1_j3) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_DRIVE;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_FWD_DRIVE;
          swc_VOMM_ARID_DEF.GearLeverFrmD_c = true;
          swc_VOMM_ARID_DEF.GearLeverFrmR_m = false;
        } else if (vsmd_b_VehRun && rtb_RelationalOperator2_cb &&
                   rtb_FixPtRelationalOperator && rtb_BrkPdlPushFstFlg &&
                   rtb_LogicalOperator1_j3) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_REVERSE;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_REV_DRIVE;
          swc_VOMM_ARID_DEF.GearLeverFrmD_c = false;
          swc_VOMM_ARID_DEF.GearLeverFrmR_m = true;
        }
        break;

       case swc_VOMM_IN_REVERSE:
        swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_REV_DRIVE;
        if (rtb_RelationalOperator1_o && rtb_LogicalOperator1_j3 &&
            (rtb_FixPtRelationalOperator || rtb_RelationalOperator7_l ||
             (!vsmd_b_VehRun))) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_PARKING;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_PARKING;
        } else if (rtb_RelationalOperator4_m || (!vsmd_b_VehRun) ||
                   (vsmd_b_VehRun && rtb_RelationalOperator10_ht &&
                    rtb_FixPtRelationalOperator && rtb_BrkPdlPushFstFlg &&
                    rtb_LogicalOperator1_j3)) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_NEUTRAL;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_NEUTRAL;
        }
        break;

       case swc_VOMM_IN_SPORT:
        swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_SPT_DRIVE;
        if (rtb_RelationalOperator1_o && rtb_LogicalOperator1_j3 &&
            (rtb_FixPtRelationalOperator || rtb_RelationalOperator7_l ||
             (!vsmd_b_VehRun))) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_PARKING;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_PARKING;
        } else if (rtb_RelationalOperator4_m || (!vsmd_b_VehRun) ||
                   (vsmd_b_VehRun && rtb_RelationalOperator2_cb &&
                    rtb_FixPtRelationalOperator && rtb_BrkPdlPushFstFlg &&
                    rtb_LogicalOperator1_j3)) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_NEUTRAL;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_NEUTRAL;
        } else if (rtb_RelationalOperator10_ht) {
          swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_DRIVE;
          swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_FWD_DRIVE;
          swc_VOMM_ARID_DEF.GearLeverFrmD_c = true;
          swc_VOMM_ARID_DEF.GearLeverFrmR_m = false;
        }
        break;

       default:
        /* case IN_UNKNOWN: */
        swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_UNKNOWN;
        if (swc_VOMM_ARID_DEF.PowerUpTimer_b > dric_t_driGearLvrPosTout_s) {
          if ((rtb_LogicalOperator1_j3 & rtb_RelationalOperator1_o) != 0) {
            swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_PARKING;
            swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_PARKING;
          } else {
            swc_VOMM_ARID_DEF.is_c2_swc_VOMM = swc_VOMM_IN_NEUTRAL;
            swc_VOMM_ARID_DEF.GearLeverPosSts_m = GearLeverPos_NEUTRAL;
          }
        } else {
          swc_VOMM_ARID_DEF.PowerUpTimer_b += ((float32)DRI_TASK_INTERVAL_S);
        }
        break;
      }
    }

    /* End of Chart: '<S24>/GearLeverPosition' */

    /* Update for UnitDelay: '<S24>/Unit Delay' */
    swc_VOMM_ARID_DEF.UnitDelay_DSTATE_c = swc_VOMM_ARID_DEF.GearLeverPosSts_m;
  }

  /* End of Outputs for SubSystem: '<S7>/Calc_GearLeverPos1' */

  /* SignalConversion: '<S7>/Signal Conversion1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element41'
   */
  swcvomm_drid_st_egsmGearReqRaw =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_st_gearLvrPosSeql();

  /* Outputs for Enabled SubSystem: '<S7>/Calc_GearLeverPos2' incorporates:
   *  EnablePort: '<S25>/Enable'
   */
  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S105>/Constant1'
   *  Constant: '<S111>/Constant'
   *  Constant: '<S111>/Constant1'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S117>/Constant1'
   *  Constant: '<S130>/Constant'
   *  Constant: '<S131>/Constant'
   *  Constant: '<S132>/Constant'
   *  Constant: '<S66>/Constant10'
   *  Constant: '<S66>/Constant11'
   *  Constant: '<S66>/Constant13'
   *  Constant: '<S66>/Constant14'
   *  Constant: '<S66>/Constant4'
   *  Constant: '<S66>/Constant9'
   *  Constant: '<S76>/Constant20'
   *  Constant: '<S76>/Constant21'
   *  Constant: '<S77>/Constant1'
   *  Constant: '<S77>/Constant2'
   *  Constant: '<S77>/Constant6'
   *  Constant: '<S77>/Constant7'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S82>/Constant'
   *  Constant: '<S99>/Constant'
   *  Constant: '<S99>/Constant1'
   *  RelationalOperator: '<S66>/Relational Operator1'
   *  RelationalOperator: '<S66>/Relational Operator2'
   *  RelationalOperator: '<S66>/Relational Operator3'
   *  RelationalOperator: '<S66>/Relational Operator4'
   *  RelationalOperator: '<S76>/Relational Operator1'
   *  RelationalOperator: '<S76>/Relational Operator3'
   *  RelationalOperator: '<S76>/Relational Operator4'
   */
  if (!dric_b_useGearLvrPosFromCan) {
    float32 rtb_LogicalOperator5_d_tmp;
    float32 rtb_t_delay_on;
    BrakePedalStatus rtb_AND_tmp;
    GearLeverPos rtb_UnitDelay6;
    ParkingStatus rtb_RelationalOperator4_ca_tmp;
    uint8 rtb_LogicalOperator14_tmp;
    uint8 rtb_Switch2_o;
    boolean rtb_LogicalOperator6_k;
    boolean rtb_OR;
    boolean rtb_OR1;
    boolean rtb_RelationalOperator11_k;
    boolean rtb_RelationalOperator1_m3_tm_0;
    boolean rtb_RelationalOperator4_o;
    boolean rtb_RelationalOperator6_p;

    /* RelationalOperator: '<S42>/Relational Operator1' incorporates:
     *  Inport generated from: '<Root>/In Bus Element109'
     *  RelationalOperator: '<S42>/Relational Operator2'
     */
    rtb_DataTypeConversion_n =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts();

    /* Logic: '<S42>/Logical Operator1' incorporates:
     *  Constant: '<S42>/Constant1'
     *  Constant: '<S42>/Constant2'
     *  Inport generated from: '<Root>/In Bus Element110'
     *  Inport generated from: '<Root>/In Bus Element109'
     *  Logic: '<S42>/Logical Operator'
     *  RelationalOperator: '<S42>/Relational Operator1'
     *  RelationalOperator: '<S42>/Relational Operator2'
     */
    swcvomm_drid_b_adcGearCtrlEn = (((rtb_DataTypeConversion_n == ((uint8)0U)) ||
      (rtb_DataTypeConversion_n == ((uint8)1U))) &&
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_adcd_b_adcCtrlGearEn());

    /* Switch: '<S42>/Switch1' */
    if (swcvomm_drid_b_adcGearCtrlEn) {
      /* Switch: '<S42>/Switch1' incorporates:
       *  Inport generated from: '<Root>/In Bus Element112'
       */
      swcvomm_drid_st_adcGearLvrReq =
        Rte_IRead_swc_VOMM_Step_vcib_VCIP_adcd_st_adcTgtGearPostn();
    } else {
      /* Switch: '<S42>/Switch1' incorporates:
       *  Constant: '<S42>/Constant3'
       */
      swcvomm_drid_st_adcGearLvrReq = ((uint8)0U);
    }

    /* End of Switch: '<S42>/Switch1' */

    /* Switch: '<S25>/Switch3' incorporates:
     *  Constant: '<S54>/Constant'
     *  Logic: '<S25>/Logical Operator10'
     *  RelationalOperator: '<S25>/Relational Operator4'
     *  RelationalOperator: '<S54>/Compare'
     *  UnitDelay: '<S25>/Unit Delay7'
     */
    if ((swcvomm_drid_st_egsmGearReqRaw != ((uint8)0U)) &&
        (swcvomm_drid_st_egsmGearReqRaw == swc_VOMM_ARID_DEF.UnitDelay7_DSTATE))
    {
      /* Switch: '<S25>/Switch3' incorporates:
       *  Constant: '<S25>/Constant5'
       */
      rtb_DataTypeConversion_n = ((uint8)1U);
    } else {
      /* Switch: '<S25>/Switch3' incorporates:
       *  Constant: '<S25>/Constant8'
       */
      rtb_DataTypeConversion_n = ((uint8)0U);
    }

    /* End of Switch: '<S25>/Switch3' */

    /* Switch: '<S25>/Switch1' incorporates:
     *  Logic: '<S25>/Logical Operator9'
     */
    if (rtb_DataTypeConversion_n == 0) {
      /* Switch: '<S25>/Switch1' incorporates:
       *  Constant: '<S25>/Constant'
       */
      rtb_DataTypeConversion_n = ((uint8)0U);
    } else {
      /* Switch: '<S25>/Switch1' incorporates:
       *  Sum: '<S25>/Add'
       *  UnitDelay: '<S25>/Unit Delay9'
       */
      rtb_DataTypeConversion_n = (uint8)((uint32)rtb_DataTypeConversion_n +
        swc_VOMM_ARID_DEF.UnitDelay9_DSTATE);
    }

    /* End of Switch: '<S25>/Switch1' */

    /* RelationalOperator: '<S76>/Relational Operator7' incorporates:
     *  Inport generated from: '<Root>/In Bus Element95'
     *  RelationalOperator: '<S76>/Relational Operator13'
     */
    rtb_FixPtRelationalOperator =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts();

    /* Logic: '<S91>/Logical Operator3' incorporates:
     *  Constant: '<S76>/Constant'
     *  Inport generated from: '<Root>/In Bus Element95'
     *  RelationalOperator: '<S76>/Relational Operator7'
     */
    rtb_LogicalOperator3_fi = (rtb_FixPtRelationalOperator == ((uint8)1U));

    /* Logic: '<S92>/Logical Operator3' incorporates:
     *  Constant: '<S76>/Constant2'
     *  Inport generated from: '<Root>/In Bus Element97'
     *  RelationalOperator: '<S76>/Relational Operator2'
     */
    rtb_LogicalOperator3_d =
      (Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld() ==
       ((uint8)0U));

    /* Logic: '<S76>/Logical Operator2' */
    rtb_RelationalOperator7_l = (rtb_LogicalOperator3_fi &&
      rtb_LogicalOperator3_d);

    /* Switch: '<S76>/Switch' incorporates:
     *  Constant: '<S123>/Constant'
     *  Inport generated from: '<Root>/BusElementIn3'
     *  RelationalOperator: '<S123>/Compare'
     */
    if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgDrvSeat() == true) {
      /* Logic: '<S92>/Logical Operator3' incorporates:
       *  Inport generated from: '<Root>/BusElementIn9'
       */
      rtb_LogicalOperator3_d =
        Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_bcmFrntRDrAjSts();
    } else {
      /* Logic: '<S92>/Logical Operator3' incorporates:
       *  Inport generated from: '<Root>/In Bus Element99'
       */
      rtb_LogicalOperator3_d =
        Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_bcmFrntLftDrAjSts();
    }

    /* End of Switch: '<S76>/Switch' */

    /* Logic: '<S91>/Logical Operator3' incorporates:
     *  Constant: '<S76>/Constant4'
     *  RelationalOperator: '<S76>/Relational Operator8'
     */
    rtb_LogicalOperator3_fi = (rtb_LogicalOperator3_d == ((uint8)1U));

    /* Logic: '<S76>/Logical Operator10' */
    swcvomm_drid_b_drvOffSeatFlg = (rtb_RelationalOperator7_l ||
      rtb_LogicalOperator3_fi);

    /* RelationalOperator: '<S76>/Relational Operator11' incorporates:
     *  Inport generated from: '<Root>/In Bus Element84'
     *  RelationalOperator: '<S25>/Relational Operator11'
     */
    rtb_LogicalOperator1_o_tmp =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_acpd_x_accPedlPos_pct();

    /* Outputs for Enabled SubSystem: '<S66>/GearR' incorporates:
     *  EnablePort: '<S89>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S66>/GearD' incorporates:
     *  EnablePort: '<S86>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S66>/GearN' incorporates:
     *  EnablePort: '<S87>/Enable'
     */
    /* Outputs for Enabled SubSystem: '<S66>/GearP' incorporates:
     *  EnablePort: '<S88>/Enable'
     */
    /* RelationalOperator: '<S76>/Relational Operator10' incorporates:
     *  Inport generated from: '<Root>/In Bus Element15'
     *  RelationalOperator: '<S25>/Relational Operator8'
     *  RelationalOperator: '<S86>/Relational Operator8'
     *  RelationalOperator: '<S87>/Relational Operator8'
     *  RelationalOperator: '<S88>/Relational Operator8'
     *  RelationalOperator: '<S89>/Relational Operator8'
     */
    rtb_AND_tmp = Rte_IRead_swc_VOMM_Step_vcib_VCIP_brpd_e_brkPedalStatus();

    /* End of Outputs for SubSystem: '<S66>/GearP' */
    /* End of Outputs for SubSystem: '<S66>/GearN' */
    /* End of Outputs for SubSystem: '<S66>/GearD' */
    /* End of Outputs for SubSystem: '<S66>/GearR' */

    /* Logic: '<S76>/AND' incorporates:
     *  Constant: '<S129>/Constant'
     *  Constant: '<S76>/Constant8'
     *  Inport generated from: '<Root>/In Bus Element84'
     *  RelationalOperator: '<S76>/Relational Operator10'
     *  RelationalOperator: '<S76>/Relational Operator11'
     */
    rtb_AND = ((rtb_AND_tmp == BrakePedalStatus_NOT_PRESSED) &&
               (rtb_LogicalOperator1_o_tmp < 1.0F));

    /* Outputs for Atomic SubSystem: '<S76>/turnON_delay5' */
    swc_VOMM_turnON_delay_4WD(rtb_AND, swcvomm_dric_tm_pedRel_s, ((float32)
      DRI_TASK_INTERVAL_S), &rtb_flg_out_eq,
      &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay5);

    /* End of Outputs for SubSystem: '<S76>/turnON_delay5' */

    /* RelationalOperator: '<S76>/Relational Operator6' incorporates:
     *  Constant: '<S76>/Constant20'
     *  Constant: '<S76>/Constant21'
     *  Inport generated from: '<Root>/In Bus Element7'
     *  RelationalOperator: '<S25>/Relational Operator3'
     *  RelationalOperator: '<S25>/Relational Operator5'
     *  RelationalOperator: '<S76>/Relational Operator12'
     */
    rtb_LogicalOperator5_d_tmp =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_v_vehSpd_kph();

    /* RelationalOperator: '<S76>/Relational Operator1' incorporates:
     *  RelationalOperator: '<S76>/Relational Operator3'
     *  RelationalOperator: '<S76>/Relational Operator4'
     *  UnitDelay: '<S25>/Unit Delay4'
     */
    rtb_RelationalOperator1_m3_tmp = swc_VOMM_ARID_DEF.UnitDelay4_DSTATE_g;

    /* Logic: '<S76>/Logical Operator5' incorporates:
     *  Constant: '<S130>/Constant'
     *  Constant: '<S131>/Constant'
     *  Constant: '<S132>/Constant'
     *  Constant: '<S76>/Constant1'
     *  Inport generated from: '<Root>/In Bus Element6'
     *  Inport generated from: '<Root>/In Bus Element7'
     *  Logic: '<S76>/Logical Operator3'
     *  Logic: '<S76>/Logical Operator4'
     *  Logic: '<S8>/AND'
     *  RelationalOperator: '<S76>/Relational Operator1'
     *  RelationalOperator: '<S76>/Relational Operator3'
     *  RelationalOperator: '<S76>/Relational Operator4'
     *  RelationalOperator: '<S76>/Relational Operator6'
     */
    rtb_RelationalOperator7_l = (((rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_NEUTRAL) || (rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_FWD_DRIVE) || (rtb_RelationalOperator1_m3_tmp ==
      GearLeverPos_REV_DRIVE)) && ((rtb_LogicalOperator5_d_tmp <= 3.0F) &&
      swcvomm_drid_b_drvOffSeatFlg) && rtb_LogicalOperator6_jj_tmp &&
      rtb_flg_out_eq);

    /* Outputs for Atomic SubSystem: '<S76>/turnON_delay3' */
    /* Saturate: '<S134>/Saturation' incorporates:
     *  Constant: '<S76>/Constant14'
     */
    if (swcvomm_dric_tm_drvVehSpdChk_s > 1.6777216E+7F) {
      /* Saturate: '<S134>/Saturation' */
      rtb_t_delay_on = 1.6777216E+7F;
    } else if (swcvomm_dric_tm_drvVehSpdChk_s < 0.0F) {
      /* Saturate: '<S134>/Saturation' */
      rtb_t_delay_on = 0.0F;
    } else {
      /* Saturate: '<S134>/Saturation' */
      rtb_t_delay_on = swcvomm_dric_tm_drvVehSpdChk_s;
    }

    /* End of Saturate: '<S134>/Saturation' */

    /* Chart: '<S134>/timed_delay' incorporates:
     *  Constant: '<S76>/Constant13'
     *  DataTypeConversion: '<S134>/Data Type Conversion'
     */
    if (swc_VOMM_ARID_DEF.is_active_c14_Ricardo_SW_dev_li == 0U) {
      swc_VOMM_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 1U;
      if (rtb_RelationalOperator7_l) {
        swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_g;
        swcvomm_drid_b_autoParkFlg = true;
      } else {
        swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_h;
        swcvomm_drid_b_autoParkFlg = false;
      }
    } else {
      switch (swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib) {
       case swc_VOMM_IN_OFF_h:
        if (rtb_RelationalOperator7_l) {
          if (rtb_t_delay_on == 0.0F) {
            swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_g;
            swcvomm_drid_b_autoParkFlg = true;
          } else {
            swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_WAIT_o;
            swc_VOMM_ARID_DEF.t_wait = 0.0F;
            swc_VOMM_ARID_DEF.t_wait += ((float32)DRI_TASK_INTERVAL_S);
            swcvomm_drid_b_autoParkFlg = false;
          }
        } else {
          swcvomm_drid_b_autoParkFlg = false;
        }
        break;

       case swc_VOMM_IN_ON_g:
        if (!rtb_RelationalOperator7_l) {
          swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_h;
          swcvomm_drid_b_autoParkFlg = false;
        } else {
          swcvomm_drid_b_autoParkFlg = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_RelationalOperator7_l) {
          swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_OFF_h;
          swcvomm_drid_b_autoParkFlg = false;
        } else if (swc_VOMM_ARID_DEF.t_wait > rtb_t_delay_on - ((float32)
                    DRI_TASK_INTERVAL_S)) {
          swc_VOMM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_VOMM_IN_ON_g;
          swcvomm_drid_b_autoParkFlg = true;
        } else {
          swc_VOMM_ARID_DEF.t_wait += ((float32)DRI_TASK_INTERVAL_S);
          swcvomm_drid_b_autoParkFlg = false;
        }
        break;
      }
    }

    /* End of Chart: '<S134>/timed_delay' */
    /* End of Outputs for SubSystem: '<S76>/turnON_delay3' */

    /* RelationalOperator: '<S124>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S124>/Delay Input1'
     *
     * Block description for '<S124>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_a = ((sint32)swcvomm_drid_b_autoParkFlg <
      (sint32)swc_VOMM_ARID_DEF.DelayInput1_DSTATE_p);

    /* RelationalOperator: '<S76>/Relational Operator13' incorporates:
     *  Constant: '<S76>/Constant15'
     */
    rtb_FixPtRelationalOperator = (rtb_FixPtRelationalOperator == ((uint8)0U));

    /* RelationalOperator: '<S76>/Relational Operator14' incorporates:
     *  Constant: '<S76>/Constant16'
     */
    rtb_RelationalOperator7_l = (rtb_LogicalOperator3_d == ((uint8)0U));

    /* Logic: '<S76>/Logical Operator6' incorporates:
     *  Constant: '<S76>/Constant3'
     *  RelationalOperator: '<S125>/FixPt Relational Operator'
     *  RelationalOperator: '<S126>/FixPt Relational Operator'
     *  RelationalOperator: '<S127>/FixPt Relational Operator'
     *  RelationalOperator: '<S76>/Relational Operator12'
     *  UnitDelay: '<S125>/Delay Input1'
     *  UnitDelay: '<S126>/Delay Input1'
     *  UnitDelay: '<S127>/Delay Input1'
     *
     * Block description for '<S125>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S126>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S127>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_LogicalOperator6_b = ((rtb_LogicalOperator5_d_tmp >
      dric_v_spdRstAutoP_kph) || ((sint32)vsmd_b_VehRun > (sint32)
      swc_VOMM_ARID_DEF.DelayInput1_DSTATE_n) || ((sint32)
      rtb_FixPtRelationalOperator > (sint32)
      swc_VOMM_ARID_DEF.DelayInput1_DSTATE_ns) || ((sint32)
      rtb_RelationalOperator7_l > (sint32)
      swc_VOMM_ARID_DEF.DelayInput1_DSTATE_n2));

    /* Outputs for Atomic SubSystem: '<S76>/SR_latch' */
    swc_VOMM_SR_latch(rtb_FixPtRelationalOperator_a, rtb_LogicalOperator6_b,
                      &rtb_LogicalOperator3_mf,
                      &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_m);

    /* End of Outputs for SubSystem: '<S76>/SR_latch' */

    /* RelationalOperator: '<S76>/Relational Operator9' incorporates:
     *  Inport generated from: '<Root>/In Bus Element39'
     *  RelationalOperator: '<S66>/Relational Operator5'
     */
    rtb_Saturation1 = Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_parkBtnPressed();

    /* RelationalOperator: '<S76>/Relational Operator9' incorporates:
     *  Constant: '<S76>/Constant6'
     *  Inport generated from: '<Root>/In Bus Element39'
     */
    rtb_LogicalOperator1_j3 = (rtb_Saturation1 == ((uint8)1U));

    /* Switch: '<S76>/Switch10' */
    if (swcvomm_drid_b_adcGearCtrlEn) {
      /* Switch: '<S76>/Switch10' incorporates:
       *  Constant: '<S76>/Constant17'
       */
      drid_b_egsmParkReq = false;
    } else {
      /* Switch: '<S76>/Switch10' incorporates:
       *  Logic: '<S76>/Logical Operator11'
       *  Logic: '<S76>/Logical Operator12'
       *  Logic: '<S76>/Logical Operator7'
       *  RelationalOperator: '<S128>/FixPt Relational Operator'
       *  UnitDelay: '<S128>/Delay Input1'
       *
       * Block description for '<S128>/Delay Input1':
       *
       *  Store in Global RAM
       */
      drid_b_egsmParkReq = ((swcvomm_drid_b_autoParkFlg &&
        (!rtb_LogicalOperator3_mf)) || ((sint32)rtb_LogicalOperator1_j3 >
        (sint32)swc_VOMM_ARID_DEF.DelayInput1_DSTATE_ld));
    }

    /* End of Switch: '<S76>/Switch10' */

    /* RelationalOperator: '<S63>/FixPt Relational Operator' incorporates:
     *  Inport generated from: '<Root>/BusElementIn10'
     *  UnitDelay: '<S63>/Delay Input1'
     *  UnitDelay: '<S65>/Delay Input1'
     * *
     * Block description for '<S63>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S65>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_RelationalOperator1_m3_tm_0 =
      Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_chgCablePlugged();

    /* RelationalOperator: '<S63>/FixPt Relational Operator' incorporates:
     *  Inport generated from: '<Root>/BusElementIn10'
     *  UnitDelay: '<S63>/Delay Input1'
     *
     * Block description for '<S63>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_RelationalOperator2_cb = ((sint32)rtb_RelationalOperator1_m3_tm_0 >
      (sint32)swc_VOMM_ARID_DEF.DelayInput1_DSTATE_g);

    /* Logic: '<S25>/Logical Operator6' incorporates:
     *  Inport generated from: '<Root>/In Bus Element6'
     *  Logic: '<S8>/AND'
     */
    rtb_LogicalOperator6_k = !rtb_LogicalOperator6_jj_tmp;

    /* Logic: '<S92>/Logical Operator3' incorporates:
     *  Constant: '<S25>/Constant6'
     *  Inport generated from: '<Root>/In Bus Element116'
     *  RelationalOperator: '<S25>/Relational Operator1'
     */
    rtb_LogicalOperator3_d =
      (Rte_IRead_swc_VOMM_Step_vcsb_DIAG_ddid_b_egsmMsgErr() == ((uint8)1U));

    /* RelationalOperator: '<S66>/Relational Operator6' incorporates:
     *  Inport generated from: '<Root>/In Bus Element85'
     *  RelationalOperator: '<S25>/Relational Operator10'
     *  RelationalOperator: '<S25>/Relational Operator2'
     */
    rtb_Switch2_o = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_egsmShftLvrFailSt();

    /* Logic: '<S66>/Logical Operator1' incorporates:
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S66>/Constant3'
     *  Inport generated from: '<Root>/In Bus Element85'
     *  Logic: '<S66>/Logical Operator'
     *  RelationalOperator: '<S66>/Relational Operator5'
     *  RelationalOperator: '<S66>/Relational Operator6'
     */
    rtb_BrkPdlPushFstFlg = (((rtb_Saturation1 == ((uint8)3U)) && (rtb_Switch2_o ==
      ((uint8)2U))) || rtb_LogicalOperator3_d);

    /* RelationalOperator: '<S79>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S79>/Delay Input1'
     *
     * Block description for '<S79>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_d = ((sint32)rtb_BrkPdlPushFstFlg > (sint32)
      swc_VOMM_ARID_DEF.DelayInput1_DSTATE_h);

    /* UnitDelay: '<S25>/Unit Delay2' */
    rtb_Saturation1 = swc_VOMM_ARID_DEF.UnitDelay2_DSTATE;

    /* RelationalOperator: '<S25>/Relational Operator12' incorporates:
     *  UnitDelay: '<S25>/Unit Delay'
     *  UnitDelay: '<S25>/Unit Delay2'
     */
    rtb_RelationalOperator12_h = (swc_VOMM_ARID_DEF.UnitDelay2_DSTATE !=
      swc_VOMM_ARID_DEF.UnitDelay_DSTATE_g);

    /* UnitDelay: '<S25>/Unit Delay6' */
    rtb_UnitDelay6 = swc_VOMM_ARID_DEF.UnitDelay6_DSTATE;

    /* Logic: '<S25>/Logical Operator4' incorporates:
     *  RelationalOperator: '<S25>/Relational Operator13'
     *  UnitDelay: '<S25>/Unit Delay1'
     *  UnitDelay: '<S25>/Unit Delay6'
     */
    rtb_LogicalOperator4_g = ((swc_VOMM_ARID_DEF.UnitDelay6_DSTATE !=
      swc_VOMM_ARID_DEF.UnitDelay1_DSTATE_h) || swcvomm_drid_b_adcGearCtrlEn);

    /* Outputs for Atomic SubSystem: '<S25>/SR_latch' */
    swc_VOMM_SR_latch(rtb_RelationalOperator12_h, rtb_LogicalOperator4_g,
                      &rtb_LogicalOperator3_fi,
                      &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch);

    /* End of Outputs for SubSystem: '<S25>/SR_latch' */

    /* Switch: '<S25>/Switch10' */
    if (rtb_LogicalOperator3_fi) {
      /* Switch: '<S25>/Switch10' incorporates:
       *  UnitDelay: '<S25>/Unit Delay2'
       */
      swcvomm_drid_st_egsmGearReq = swc_VOMM_ARID_DEF.UnitDelay2_DSTATE;
    } else {
      /* Switch: '<S25>/Switch10' incorporates:
       *  Constant: '<S25>/Constant9'
       */
      swcvomm_drid_st_egsmGearReq = ((uint8)0U);
    }

    /* End of Switch: '<S25>/Switch10' */

    /* RelationalOperator: '<S66>/Relational Operator8' incorporates:
     *  Constant: '<S66>/Constant8'
     */
    rtb_LogicalOperator2_f = (swcvomm_drid_st_egsmGearReq == ((uint8)7U));

    /* RelationalOperator: '<S80>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S80>/Delay Input1'
     *
     * Block description for '<S80>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_dn = ((sint32)rtb_LogicalOperator2_f > (sint32)
      swc_VOMM_ARID_DEF.DelayInput1_DSTATE_i);

    /* RelationalOperator: '<S25>/Relational Operator8' incorporates:
     *  Constant: '<S69>/Constant'
     */
    rtb_RelationalOperator10_ht = (rtb_AND_tmp == BrakePedalStatus_PRESSED);

    /* RelationalOperator: '<S25>/Relational Operator7' incorporates:
     *  Inport generated from: '<Root>/In Bus Element42'
     *  RelationalOperator: '<S25>/Relational Operator14'
     *  RelationalOperator: '<S25>/Relational Operator15'
     *  RelationalOperator: '<S25>/Relational Operator16'
     *  RelationalOperator: '<S25>/Relational Operator6'
     *  RelationalOperator: '<S25>/Relational Operator9'
     */
    rtb_RelationalOperator4_ca_tmp =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_epbd_e_parkingSts();

    /* RelationalOperator: '<S25>/Relational Operator7' incorporates:
     *  Constant: '<S74>/Constant'
     */
    rtb_RelationalOperator4_m = (rtb_RelationalOperator4_ca_tmp ==
      ParkingStatus_ENGAGED);

    /* Logic: '<S25>/OR' incorporates:
     *  Constant: '<S68>/Constant'
     *  Constant: '<S70>/Constant'
     *  RelationalOperator: '<S25>/Relational Operator6'
     *  RelationalOperator: '<S25>/Relational Operator9'
     */
    rtb_OR = (rtb_RelationalOperator4_m || (rtb_RelationalOperator4_ca_tmp ==
               ParkingStatus_INPROGRESS) || (rtb_RelationalOperator4_ca_tmp ==
               ParkingStatus_DEFAULTVALUE));

    /* Logic: '<S25>/OR1' incorporates:
     *  Constant: '<S68>/Constant'
     *  Constant: '<S70>/Constant'
     *  Constant: '<S71>/Constant'
     *  RelationalOperator: '<S25>/Relational Operator14'
     *  RelationalOperator: '<S25>/Relational Operator15'
     *  RelationalOperator: '<S25>/Relational Operator16'
     *  RelationalOperator: '<S25>/Relational Operator6'
     *  RelationalOperator: '<S25>/Relational Operator9'
     */
    rtb_OR1 = ((rtb_RelationalOperator4_ca_tmp == ParkingStatus_DISENGAGED) ||
               (rtb_RelationalOperator4_ca_tmp == ParkingStatus_INPROGRESS) ||
               (rtb_RelationalOperator4_ca_tmp == ParkingStatus_DEFAULTVALUE));

    /* Logic: '<S25>/Logical Operator1' incorporates:
     *  Inport generated from: '<Root>/In Bus Element45'
     *  Logic: '<S25>/Logical Operator2'
     */
    rtb_RelationalOperator4_o =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_b_vehSpdVld();

    /* Logic: '<S25>/Logical Operator1' incorporates:
     *  Constant: '<S25>/Constant2'
     *  Inport generated from: '<Root>/In Bus Element45'
     *  RelationalOperator: '<S25>/Relational Operator3'
     */
    drid_b_VehicleStopped = (rtb_RelationalOperator4_o &&
      (rtb_LogicalOperator5_d_tmp <= dric_v_vehStoppedThd_kph));

    /* Logic: '<S25>/Logical Operator2' incorporates:
     *  Constant: '<S25>/Constant1'
     *  RelationalOperator: '<S25>/Relational Operator5'
     */
    drid_b_VehicleMove = (rtb_RelationalOperator4_o &&
                          (rtb_LogicalOperator5_d_tmp > dric_v_vehMoveThd_kph));

    /* RelationalOperator: '<S77>/Relational Operator2' incorporates:
     *  Constant: '<S77>/Constant'
     */
    rtb_RelationalOperator2_e = (swcvomm_drid_st_egsmGearReq == ((uint8)1U));

    /* Outputs for Atomic SubSystem: '<S77>/turnON_delay' */
    swc_VOMM_turnON_delay_4WD(rtb_RelationalOperator2_e,
      swcvomm_dric_tm_drvGearReqDly_s, ((float32)DRI_TASK_INTERVAL_S),
      &rtb_flg_out_kj, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay);

    /* End of Outputs for SubSystem: '<S77>/turnON_delay' */

    /* RelationalOperator: '<S77>/Relational Operator4' incorporates:
     *  Constant: '<S77>/Constant1'
     *  Constant: '<S77>/Constant2'
     *  Constant: '<S77>/Constant3'
     */
    rtb_RelationalOperator4_o = (swcvomm_drid_st_egsmGearReq == ((uint8)3U));

    /* RelationalOperator: '<S77>/Relational Operator10' incorporates:
     *  Constant: '<S77>/Constant4'
     */
    rtb_RelationalOperator10_j = (swcvomm_drid_st_egsmGearReq == ((uint8)2U));

    /* Outputs for Atomic SubSystem: '<S77>/turnON_delay1' */
    swc_VOMM_turnON_delay_4WD(rtb_RelationalOperator10_j,
      swcvomm_dric_tm_drvGearReqDly_s, ((float32)DRI_TASK_INTERVAL_S),
      &rtb_flg_out_k, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay1);

    /* End of Outputs for SubSystem: '<S77>/turnON_delay1' */

    /* RelationalOperator: '<S77>/Relational Operator6' incorporates:
     *  Constant: '<S77>/Constant5'
     *  Constant: '<S77>/Constant6'
     *  Constant: '<S77>/Constant7'
     */
    rtb_RelationalOperator6_p = (swcvomm_drid_st_egsmGearReq == ((uint8)4U));

    /* Logic: '<S25>/Logical Operator5' incorporates:
     *  Constant: '<S25>/Constant13'
     *  Constant: '<S25>/Constant3'
     *  Logic: '<S25>/AND1'
     *  RelationalOperator: '<S25>/Relational Operator10'
     *  RelationalOperator: '<S25>/Relational Operator2'
     */
    swcvomm_drid_b_gearPosVld = ((rtb_Switch2_o == ((uint8)3U)) ||
      (rtb_Switch2_o == ((uint8)2U)) || rtb_LogicalOperator3_d);

    /* Logic: '<S25>/Logical Operator3' */
    rtb_RelationalOperator1_o = !swcvomm_drid_b_gearPosVld;

    /* RelationalOperator: '<S25>/Relational Operator11' incorporates:
     *  Constant: '<S25>/Constant11'
     */
    rtb_RelationalOperator11_k = (rtb_LogicalOperator1_o_tmp == 0.0F);

    /* Chart: '<S25>/GearLeverPosition' incorporates:
     *  Constant: '<S132>/Constant'
     *  Constant: '<S25>/Constant10'
     *  Constant: '<S25>/Constant12'
     *  Constant: '<S25>/Constant14'
     *  Inport generated from: '<Root>/BusElementIn5'
     *  Inport generated from: '<Root>/BusElementIn14'
     *  RelationalOperator: '<S76>/Relational Operator4'
     *  RelationalOperator: '<S77>/Relational Operator3'
     *  Switch: '<S77>/Switch1'
     *  Switch: '<S77>/Switch10'
     *  UnitDelay: '<S25>/Unit Delay5'
     */
    swc_VOMM_ARID_DEF.EPBRelease_prev = swc_VOMM_ARID_DEF.EPBRelease_start;
    swc_VOMM_ARID_DEF.EPBRelease_start = rtb_OR1;
    swc_VOMM_ARID_DEF.EPBActive_prev = swc_VOMM_ARID_DEF.EPBActive_start;
    swc_VOMM_ARID_DEF.EPBActive_start = rtb_OR;
    if (swc_VOMM_ARID_DEF.is_active_c5_swc_VOMM == 0U) {
      swc_VOMM_ARID_DEF.EPBRelease_prev = rtb_OR1;
      swc_VOMM_ARID_DEF.EPBActive_prev = rtb_OR;
      swc_VOMM_ARID_DEF.is_active_c5_swc_VOMM = 1U;
      swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_DEFAULT;
      swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
      swc_VOMM_ARID_DEF.PowerUpTimer = 0.0F;
    } else {
      switch (swc_VOMM_ARID_DEF.is_c5_swc_VOMM) {
       case swc_VOMM_IN_DEFAULT:
        swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
        if (swc_VOMM_ARID_DEF.PowerUpTimer > dric_t_driGearLvrPosTout_s) {
          swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_PARKING_p;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
          swc_VOMM_ARID_DEF.WaitTm = 0.0F;
        } else {
          swc_VOMM_ARID_DEF.PowerUpTimer += ((float32)DRI_TASK_INTERVAL_S);
        }
        break;

       case swc_VOMM_IN_DRIVE_h:
        {
          boolean tmp_2;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_FWD_DRIVE;
          rtb_OR = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts();
          tmp_1 = !Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts();
          rtb_OR1 = !vsmd_b_VehRun;
          rtb_RelationalOperator6_p = (drid_b_egsmParkReq &&
            drid_b_VehicleStopped && rtb_RelationalOperator1_o);
          rtb_RelationalOperator11_k = (rtb_OR1 && drid_b_VehicleStopped);
          tmp_2 = (rtb_LogicalOperator6_k && drid_b_VehicleStopped);
          rtb_RelationalOperator2_cb = (drid_b_VehicleStopped &&
            rtb_RelationalOperator2_cb);
          if ((rtb_RelationalOperator6_p && (!rtb_OR)) ||
              (rtb_RelationalOperator11_k && tmp_1) || (tmp_2 && tmp_1) ||
              (rtb_RelationalOperator2_cb && tmp_1) ||
              ((swcvomm_drid_st_adcGearLvrReq == 1) && drid_b_VehicleStopped &&
               rtb_RelationalOperator1_o && tmp_1)) {
            swc_VOMM_ARID_DEF.epbClsdFlg = true;
            swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_PARKING_p;
            swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
            swc_VOMM_ARID_DEF.WaitTm = 0.0F;
          } else if ((vsmd_b_VehRun && rtb_RelationalOperator10_ht &&
                      rtb_RelationalOperator4_o && drid_b_VehicleStopped &&
                      rtb_RelationalOperator1_o) || (vsmd_b_VehRun &&
                      (swcvomm_drid_st_adcGearLvrReq == 2) &&
                      drid_b_VehicleStopped && rtb_RelationalOperator1_o)) {
            swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_REVERSE_l;
            swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_REV_DRIVE;
            swc_VOMM_ARID_DEF.epbClsdFlg = false;
          } else {
            if (swc_VOMM_ARID_DEF.UnitDelay5_DSTATE == GearLeverPos_FWD_DRIVE) {
              /* Switch: '<S77>/Switch10' */
              tmp_1 = rtb_flg_out_kj;
            } else {
              /* Switch: '<S77>/Switch10' */
              tmp_1 = rtb_RelationalOperator2_e;
            }

            if ((vsmd_b_VehRun && (tmp_1 || (swcvomm_drid_st_adcGearLvrReq == 3))
                 && rtb_RelationalOperator1_o) || (rtb_OR1 &&
                 (!drid_b_VehicleStopped)) || (rtb_RelationalOperator6_p &&
                 rtb_OR) || (rtb_RelationalOperator11_k && rtb_OR) || (tmp_2 &&
                 rtb_OR) || (rtb_RelationalOperator2_cb && rtb_OR) ||
                ((swcvomm_drid_st_adcGearLvrReq == 1) && drid_b_VehicleStopped &&
                 rtb_RelationalOperator1_o && rtb_OR)) {
              swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_NEUTRAL_b;
              swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_NEUTRAL;
              swc_VOMM_ARID_DEF.epbClsdFlg = false;
            }
          }
        }
        break;

       case swc_VOMM_IN_NEUTRAL_b:
        swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_NEUTRAL;
        tmp_1 = !Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts();
        if (((drid_b_egsmParkReq || (swcvomm_drid_st_adcGearLvrReq == 1)) &&
             drid_b_VehicleStopped && rtb_RelationalOperator1_o && tmp_1) ||
            (rtb_LogicalOperator6_k && drid_b_VehicleStopped && tmp_1) ||
            (drid_b_VehicleStopped && rtb_RelationalOperator2_cb && tmp_1) || ((
              !rtb_LogicalOperator6_k) && ((swc_VOMM_ARID_DEF.EPBRelease_prev !=
               swc_VOMM_ARID_DEF.EPBRelease_start) &&
              (!swc_VOMM_ARID_DEF.EPBRelease_start)))) {
          swc_VOMM_ARID_DEF.epbClsdFlg = true;
          swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_PARKING_p;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
          swc_VOMM_ARID_DEF.WaitTm = 0.0F;
        } else {
          rtb_LogicalOperator1_o_tmp =
            Rte_IRead_swc_VOMM_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm();
          if ((vsmd_b_VehRun && ((rtb_RelationalOperator4_o &&
                                  rtb_RelationalOperator10_ht) ||
                                 (swcvomm_drid_st_adcGearLvrReq == 2)) &&
               drid_b_VehicleStopped && rtb_RelationalOperator1_o) ||
              (vsmd_b_VehRun && (rtb_RelationalOperator4_o ||
                                 (swcvomm_drid_st_adcGearLvrReq == 2)) &&
               drid_b_VehicleMove && (rtb_LogicalOperator1_o_tmp < 0.0F) &&
               rtb_RelationalOperator11_k && rtb_RelationalOperator1_o)) {
            swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_REVERSE_l;
            swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_REV_DRIVE;
            swc_VOMM_ARID_DEF.epbClsdFlg = false;
          } else if ((vsmd_b_VehRun && ((rtb_RelationalOperator6_p &&
                        rtb_RelationalOperator10_ht) ||
                       (swcvomm_drid_st_adcGearLvrReq == 4)) &&
                      drid_b_VehicleStopped && rtb_RelationalOperator1_o) ||
                     (vsmd_b_VehRun && (rtb_RelationalOperator6_p ||
                       (swcvomm_drid_st_adcGearLvrReq == 4)) &&
                      drid_b_VehicleMove && (rtb_LogicalOperator1_o_tmp > 0.0F) &&
                      rtb_RelationalOperator11_k && rtb_RelationalOperator1_o))
          {
            swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_DRIVE_h;
            swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_FWD_DRIVE;
            swc_VOMM_ARID_DEF.epbClsdFlg = false;
          }
        }
        break;

       case swc_VOMM_IN_PARKING_p:
        swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
        tmp_1 = !rtb_LogicalOperator6_k;
        if (((swc_VOMM_ARID_DEF.EPBActive_prev !=
              swc_VOMM_ARID_DEF.EPBActive_start) &&
             (!swc_VOMM_ARID_DEF.EPBActive_start) && tmp_1 &&
             (!swc_VOMM_ARID_DEF.epbClsdFlg)) || (vsmd_b_VehRun &&
             (swcvomm_drid_st_adcGearLvrReq == 3) && rtb_RelationalOperator1_o) ||
            (rtb_OR1 && tmp_1 && swc_VOMM_ARID_DEF.epbClsdFlg &&
             (swc_VOMM_ARID_DEF.WaitTm > dric_t_P2NDebTm_s))) {
          swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_NEUTRAL_b;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_NEUTRAL;
          swc_VOMM_ARID_DEF.epbClsdFlg = false;
        } else if ((vsmd_b_VehRun && rtb_RelationalOperator6_p &&
                    rtb_RelationalOperator10_ht && rtb_RelationalOperator1_o) ||
                   (vsmd_b_VehRun && (swcvomm_drid_st_adcGearLvrReq == 4) &&
                    rtb_RelationalOperator1_o)) {
          swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_DRIVE_h;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_FWD_DRIVE;
          swc_VOMM_ARID_DEF.epbClsdFlg = false;
        } else if ((vsmd_b_VehRun && rtb_RelationalOperator4_o &&
                    rtb_RelationalOperator10_ht && rtb_RelationalOperator1_o) ||
                   (vsmd_b_VehRun && (swcvomm_drid_st_adcGearLvrReq == 2) &&
                    rtb_RelationalOperator1_o)) {
          swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_REVERSE_l;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_REV_DRIVE;
          swc_VOMM_ARID_DEF.epbClsdFlg = false;
        } else {
          swc_VOMM_ARID_DEF.WaitTm += ((float32)DRI_TASK_INTERVAL_S);
        }
        break;

       default:
        /* case IN_REVERSE: */
        swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_REV_DRIVE;
        tmp_1 = !Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts();
        rtb_RelationalOperator4_o = !vsmd_b_VehRun;
        rtb_OR1 = (drid_b_egsmParkReq && drid_b_VehicleStopped &&
                   rtb_RelationalOperator1_o);
        rtb_RelationalOperator11_k = (rtb_RelationalOperator4_o &&
          drid_b_VehicleStopped);
        if ((rtb_OR1 && tmp_1) || (rtb_RelationalOperator11_k && tmp_1) ||
            (rtb_LogicalOperator6_k && drid_b_VehicleStopped &&
             (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts())) ||
            (drid_b_VehicleStopped && rtb_RelationalOperator2_cb &&
             (!Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts())) ||
            ((swcvomm_drid_st_adcGearLvrReq == 1) && drid_b_VehicleStopped &&
             rtb_RelationalOperator1_o && tmp_1)) {
          swc_VOMM_ARID_DEF.epbClsdFlg = true;
          swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_PARKING_p;
          swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_PARKING;
          swc_VOMM_ARID_DEF.WaitTm = 0.0F;
        } else {
          rtb_OR = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts();

          /* Switch: '<S77>/Switch1' incorporates:
           *  Constant: '<S131>/Constant'
           *  RelationalOperator: '<S76>/Relational Operator3'
           *  RelationalOperator: '<S77>/Relational Operator1'
           *  UnitDelay: '<S25>/Unit Delay5'
           */
          if (swc_VOMM_ARID_DEF.UnitDelay5_DSTATE == GearLeverPos_REV_DRIVE) {
            tmp_1 = rtb_flg_out_k;
          } else {
            tmp_1 = rtb_RelationalOperator10_j;
          }

          if ((vsmd_b_VehRun && (tmp_1 || (swcvomm_drid_st_adcGearLvrReq == 3)) &&
               rtb_RelationalOperator1_o) || (rtb_RelationalOperator4_o &&
               (!drid_b_VehicleStopped)) || (rtb_OR1 && rtb_OR) ||
              (rtb_RelationalOperator11_k && rtb_OR) || (rtb_LogicalOperator6_k &&
               drid_b_VehicleStopped && rtb_OR) || (drid_b_VehicleStopped &&
               rtb_RelationalOperator2_cb && rtb_OR) ||
              ((swcvomm_drid_st_adcGearLvrReq == 1) && drid_b_VehicleStopped &&
               rtb_RelationalOperator1_o && rtb_OR)) {
            swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_NEUTRAL_b;
            swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_NEUTRAL;
            swc_VOMM_ARID_DEF.epbClsdFlg = false;
          } else if ((vsmd_b_VehRun && rtb_RelationalOperator10_ht &&
                      rtb_RelationalOperator6_p && drid_b_VehicleStopped &&
                      rtb_RelationalOperator1_o) || (vsmd_b_VehRun &&
                      (swcvomm_drid_st_adcGearLvrReq == 4) &&
                      drid_b_VehicleStopped && rtb_RelationalOperator1_o)) {
            swc_VOMM_ARID_DEF.is_c5_swc_VOMM = swc_VOMM_IN_DRIVE_h;
            swc_VOMM_ARID_DEF.GearLeverPosSts = GearLeverPos_FWD_DRIVE;
            swc_VOMM_ARID_DEF.epbClsdFlg = false;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S25>/GearLeverPosition' */

    /* Outputs for Enabled SubSystem: '<S66>/GearP' incorporates:
     *  EnablePort: '<S88>/Enable'
     */
    if (swc_VOMM_ARID_DEF.GearLeverPosSts == GearLeverPos_PARKING) {
      /* Logic: '<S88>/Logical Operator' incorporates:
       *  Constant: '<S88>/Constant1'
       *  Constant: '<S88>/Constant3'
       *  Constant: '<S88>/Constant4'
       *  Constant: '<S88>/Constant5'
       *  RelationalOperator: '<S88>/Relational Operator1'
       *  RelationalOperator: '<S88>/Relational Operator4'
       *  RelationalOperator: '<S88>/Relational Operator5'
       *  RelationalOperator: '<S88>/Relational Operator6'
       */
      rtb_LogicalOperator_n = ((swcvomm_drid_st_egsmGearReq == ((uint8)3U)) ||
        (swcvomm_drid_st_egsmGearReq == ((uint8)4U)) ||
        (swcvomm_drid_st_egsmGearReq == ((uint8)1U)) ||
        (swcvomm_drid_st_egsmGearReq == ((uint8)2U)));

      /* RelationalOperator: '<S88>/Relational Operator2' incorporates:
       *  Constant: '<S88>/Constant2'
       */
      rtb_RelationalOperator2_og = (swcvomm_drid_st_egsmGearReq == ((uint8)0U));

      /* Outputs for Atomic SubSystem: '<S88>/SR_latch' */
      swc_VOMM_SR_latch(rtb_LogicalOperator_n, rtb_RelationalOperator2_og,
                        &rtb_LogicalOperator3_am,
                        &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_f);

      /* End of Outputs for SubSystem: '<S88>/SR_latch' */

      /* Logic: '<S88>/Logical Operator1' incorporates:
       *  Constant: '<S69>/Constant'
       *  Constant: '<S88>/Constant17'
       *  RelationalOperator: '<S25>/Relational Operator8'
       *  RelationalOperator: '<S88>/Relational Operator3'
       *  RelationalOperator: '<S88>/Relational Operator7'
       *  RelationalOperator: '<S88>/Relational Operator8'
       *  UnitDelay: '<S88>/Unit Delay3'
       */
      rtb_LogicalOperator1_i = (rtb_LogicalOperator3_am &&
        (swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_l == GearLeverPos_PARKING) &&
        (rtb_AND_tmp != BrakePedalStatus_PRESSED) && (vsmd_b_VehRun == true));

      /* Outputs for Atomic SubSystem: '<S111>/turnON_delay' */
      swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator1_i,
        swcvomm_dric_tm_drvGearLvrLck_s, ((float32)DRI_TASK_INTERVAL_S),
        &rtb_flg_out_p, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_c);

      /* End of Outputs for SubSystem: '<S111>/turnON_delay' */

      /* Merge: '<S66>/Merge' incorporates:
       *  Constant: '<S111>/Constant'
       *  Constant: '<S111>/Constant1'
       *  SignalConversion generated from: '<S88>/flg_out'
       */
      swc_VOMM_ARID_DEF.Merge = rtb_flg_out_p;

      /* Update for UnitDelay: '<S88>/Unit Delay3' */
      swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_l = swc_VOMM_ARID_DEF.GearLeverPosSts;
    }

    /* End of Outputs for SubSystem: '<S66>/GearP' */

    /* Outputs for Enabled SubSystem: '<S66>/GearN' incorporates:
     *  EnablePort: '<S87>/Enable'
     */
    if (swc_VOMM_ARID_DEF.GearLeverPosSts == GearLeverPos_NEUTRAL) {
      /* Logic: '<S87>/Logical Operator' incorporates:
       *  Constant: '<S87>/Constant1'
       *  Constant: '<S87>/Constant5'
       *  RelationalOperator: '<S87>/Relational Operator1'
       *  RelationalOperator: '<S87>/Relational Operator6'
       */
      rtb_LogicalOperator_l = ((swcvomm_drid_st_egsmGearReq == ((uint8)3U)) ||
        (swcvomm_drid_st_egsmGearReq == ((uint8)4U)));

      /* RelationalOperator: '<S87>/Relational Operator2' incorporates:
       *  Constant: '<S87>/Constant2'
       */
      rtb_RelationalOperator2_jm = (swcvomm_drid_st_egsmGearReq == ((uint8)0U));

      /* Outputs for Atomic SubSystem: '<S87>/SR_latch' */
      swc_VOMM_SR_latch(rtb_LogicalOperator_l, rtb_RelationalOperator2_jm,
                        &rtb_LogicalOperator3_lb,
                        &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_g);

      /* End of Outputs for SubSystem: '<S87>/SR_latch' */

      /* Logic: '<S87>/Logical Operator1' incorporates:
       *  Constant: '<S69>/Constant'
       *  Constant: '<S87>/Constant17'
       *  RelationalOperator: '<S25>/Relational Operator8'
       *  RelationalOperator: '<S87>/Relational Operator3'
       *  RelationalOperator: '<S87>/Relational Operator7'
       *  RelationalOperator: '<S87>/Relational Operator8'
       *  UnitDelay: '<S87>/Unit Delay3'
       */
      rtb_LogicalOperator1_pu = (rtb_LogicalOperator3_lb &&
        (swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_p == GearLeverPos_NEUTRAL) &&
        (rtb_AND_tmp != BrakePedalStatus_PRESSED) && drid_b_VehicleStopped &&
        (vsmd_b_VehRun == true));

      /* Outputs for Atomic SubSystem: '<S105>/turnON_delay' */
      swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator1_pu,
        swcvomm_dric_tm_drvGearLvrLck_s, ((float32)DRI_TASK_INTERVAL_S),
        &rtb_flg_out_lh, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_g);

      /* End of Outputs for SubSystem: '<S105>/turnON_delay' */

      /* Merge: '<S66>/Merge' incorporates:
       *  Constant: '<S105>/Constant'
       *  Constant: '<S105>/Constant1'
       *  SignalConversion generated from: '<S87>/flg_out'
       */
      swc_VOMM_ARID_DEF.Merge = rtb_flg_out_lh;

      /* Update for UnitDelay: '<S87>/Unit Delay3' */
      swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_p = swc_VOMM_ARID_DEF.GearLeverPosSts;
    }

    /* End of Outputs for SubSystem: '<S66>/GearN' */

    /* RelationalOperator: '<S66>/Relational Operator3' incorporates:
     *  Constant: '<S105>/Constant'
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S111>/Constant'
     *  Constant: '<S111>/Constant1'
     *  Constant: '<S130>/Constant'
     *  Constant: '<S82>/Constant'
     *  RelationalOperator: '<S66>/Relational Operator1'
     *  RelationalOperator: '<S66>/Relational Operator2'
     *  RelationalOperator: '<S66>/Relational Operator4'
     *  RelationalOperator: '<S76>/Relational Operator1'
     */
    rtb_RelationalOperator1_m3_tmp = swc_VOMM_ARID_DEF.GearLeverPosSts;

    /* Outputs for Enabled SubSystem: '<S66>/GearD' incorporates:
     *  EnablePort: '<S86>/Enable'
     */
    if (rtb_RelationalOperator1_m3_tmp == GearLeverPos_FWD_DRIVE) {
      /* RelationalOperator: '<S86>/Relational Operator1' incorporates:
       *  Constant: '<S86>/Constant1'
       */
      rtb_RelationalOperator1_l = (swcvomm_drid_st_egsmGearReq == ((uint8)3U));

      /* RelationalOperator: '<S86>/Relational Operator2' incorporates:
       *  Constant: '<S86>/Constant2'
       */
      rtb_RelationalOperator2_d = (swcvomm_drid_st_egsmGearReq == ((uint8)0U));

      /* Outputs for Atomic SubSystem: '<S86>/SR_latch' */
      swc_VOMM_SR_latch(rtb_RelationalOperator1_l, rtb_RelationalOperator2_d,
                        &rtb_LogicalOperator3_b,
                        &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_n);

      /* End of Outputs for SubSystem: '<S86>/SR_latch' */

      /* Logic: '<S86>/Logical Operator1' incorporates:
       *  Constant: '<S69>/Constant'
       *  RelationalOperator: '<S25>/Relational Operator8'
       *  RelationalOperator: '<S86>/Relational Operator3'
       *  RelationalOperator: '<S86>/Relational Operator8'
       *  UnitDelay: '<S86>/Unit Delay3'
       */
      rtb_LogicalOperator1_iu = (rtb_LogicalOperator3_b &&
        (swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_m == GearLeverPos_FWD_DRIVE) &&
        (rtb_AND_tmp != BrakePedalStatus_PRESSED) && drid_b_VehicleStopped);

      /* Outputs for Atomic SubSystem: '<S99>/turnON_delay' */
      swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator1_iu,
        swcvomm_dric_tm_drvGearLvrLck_s, ((float32)DRI_TASK_INTERVAL_S),
        &rtb_flg_out_k2, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_m);

      /* End of Outputs for SubSystem: '<S99>/turnON_delay' */

      /* Merge: '<S66>/Merge' incorporates:
       *  Constant: '<S99>/Constant'
       *  Constant: '<S99>/Constant1'
       *  SignalConversion generated from: '<S86>/flg_out'
       */
      swc_VOMM_ARID_DEF.Merge = rtb_flg_out_k2;

      /* Update for UnitDelay: '<S86>/Unit Delay3' */
      swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_m = swc_VOMM_ARID_DEF.GearLeverPosSts;
    }

    /* End of Outputs for SubSystem: '<S66>/GearD' */

    /* Outputs for Enabled SubSystem: '<S66>/GearR' incorporates:
     *  EnablePort: '<S89>/Enable'
     */
    if (rtb_RelationalOperator1_m3_tmp == GearLeverPos_REV_DRIVE) {
      /* RelationalOperator: '<S89>/Relational Operator6' incorporates:
       *  Constant: '<S89>/Constant5'
       */
      rtb_RelationalOperator6_c = (swcvomm_drid_st_egsmGearReq == ((uint8)4U));

      /* RelationalOperator: '<S89>/Relational Operator2' incorporates:
       *  Constant: '<S89>/Constant2'
       */
      rtb_RelationalOperator2_j = (swcvomm_drid_st_egsmGearReq == ((uint8)0U));

      /* Outputs for Atomic SubSystem: '<S89>/SR_latch' */
      swc_VOMM_SR_latch(rtb_RelationalOperator6_c, rtb_RelationalOperator2_j,
                        &rtb_LogicalOperator3_f,
                        &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_p);

      /* End of Outputs for SubSystem: '<S89>/SR_latch' */

      /* Logic: '<S89>/Logical Operator1' incorporates:
       *  Constant: '<S69>/Constant'
       *  RelationalOperator: '<S25>/Relational Operator8'
       *  RelationalOperator: '<S89>/Relational Operator4'
       *  RelationalOperator: '<S89>/Relational Operator8'
       *  UnitDelay: '<S89>/Unit Delay3'
       */
      rtb_LogicalOperator1_f = (rtb_LogicalOperator3_f &&
        (swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_c == GearLeverPos_REV_DRIVE) &&
        (rtb_AND_tmp != BrakePedalStatus_PRESSED) && drid_b_VehicleStopped);

      /* Outputs for Atomic SubSystem: '<S117>/turnON_delay' */
      swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator1_f,
        swcvomm_dric_tm_drvGearLvrLck_s, ((float32)DRI_TASK_INTERVAL_S),
        &rtb_flg_out_l, &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_b);

      /* End of Outputs for SubSystem: '<S117>/turnON_delay' */

      /* Merge: '<S66>/Merge' incorporates:
       *  Constant: '<S117>/Constant'
       *  Constant: '<S117>/Constant1'
       *  SignalConversion generated from: '<S89>/flg_out'
       */
      swc_VOMM_ARID_DEF.Merge = rtb_flg_out_l;

      /* Update for UnitDelay: '<S89>/Unit Delay3' */
      swc_VOMM_ARID_DEF.UnitDelay3_DSTATE_c = swc_VOMM_ARID_DEF.GearLeverPosSts;
    }

    /* End of Outputs for SubSystem: '<S66>/GearR' */

    /* RelationalOperator: '<S81>/FixPt Relational Operator' incorporates:
     *  Constant: '<S117>/Constant'
     *  Constant: '<S117>/Constant1'
     *  Constant: '<S131>/Constant'
     *  Constant: '<S132>/Constant'
     *  Constant: '<S99>/Constant'
     *  Constant: '<S99>/Constant1'
     *  RelationalOperator: '<S66>/Relational Operator3'
     *  RelationalOperator: '<S66>/Relational Operator4'
     *  RelationalOperator: '<S76>/Relational Operator3'
     *  RelationalOperator: '<S76>/Relational Operator4'
     *  UnitDelay: '<S81>/Delay Input1'
     *
     * Block description for '<S81>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_FixPtRelationalOperator_g = ((sint32)swc_VOMM_ARID_DEF.Merge > (sint32)
      swc_VOMM_ARID_DEF.DelayInput1_DSTATE_e);

    /* UnitDelay: '<S66>/Unit Delay9' */
    rtb_UnitDelay9_h = swc_VOMM_ARID_DEF.UnitDelay9_DSTATE_f;

    /* Outputs for Atomic SubSystem: '<S66>/SR_latch' */
    swc_VOMM_SR_latch(rtb_FixPtRelationalOperator_g, rtb_UnitDelay9_h,
                      &rtb_LogicalOperator3_p,
                      &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch_c);

    /* End of Outputs for SubSystem: '<S66>/SR_latch' */

    /* UnitDelay: '<S66>/Unit Delay1' */
    rtb_UnitDelay1_d = swc_VOMM_ARID_DEF.UnitDelay1_DSTATE_f;

    /* Outputs for Atomic SubSystem: '<S66>/SR_latch1' */
    swc_VOMM_SR_latch(rtb_FixPtRelationalOperator_d, rtb_UnitDelay1_d,
                      &rtb_LogicalOperator3_fi,
                      &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch1);

    /* End of Outputs for SubSystem: '<S66>/SR_latch1' */

    /* UnitDelay: '<S66>/Unit Delay2' */
    rtb_UnitDelay2_m = swc_VOMM_ARID_DEF.UnitDelay2_DSTATE_a;

    /* Outputs for Atomic SubSystem: '<S66>/SR_latch2' */
    swc_VOMM_SR_latch(rtb_FixPtRelationalOperator_dn, rtb_UnitDelay2_m,
                      &rtb_LogicalOperator3_d,
                      &swc_VOMM_ARID_DEF.ARID_DEF_SR_latch2);

    /* End of Outputs for SubSystem: '<S66>/SR_latch2' */

    /* Switch: '<S66>/Switch2' incorporates:
     *  Switch: '<S66>/Switch1'
     *  Switch: '<S66>/Switch10'
     */
    if (rtb_LogicalOperator3_d) {
      /* Switch: '<S66>/Switch2' incorporates:
       *  Constant: '<S66>/Constant7'
       */
      swcvomm_drid_st_gearLvrLckInd = ((uint8)9U);
    } else if (rtb_LogicalOperator3_fi) {
      /* Switch: '<S66>/Switch1' incorporates:
       *  Constant: '<S66>/Constant5'
       *  Switch: '<S66>/Switch2'
       */
      swcvomm_drid_st_gearLvrLckInd = ((uint8)5U);
    } else if (rtb_LogicalOperator3_p) {
      /* Switch: '<S66>/Switch10' incorporates:
       *  Constant: '<S66>/Constant6'
       *  Switch: '<S66>/Switch1'
       *  Switch: '<S66>/Switch2'
       */
      swcvomm_drid_st_gearLvrLckInd = ((uint8)1U);
    } else {
      /* Switch: '<S66>/Switch2' incorporates:
       *  Constant: '<S66>/Constant1'
       *  Switch: '<S66>/Switch1'
       *  Switch: '<S66>/Switch10'
       */
      swcvomm_drid_st_gearLvrLckInd = ((uint8)0U);
    }

    /* End of Switch: '<S66>/Switch2' */

    /* Outputs for Atomic SubSystem: '<S66>/turnON_delay' */
    swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator3_p, dric_tm_gearLvrLckInd_s,
      ((float32)DRI_TASK_INTERVAL_S), &rtb_flg_out_i,
      &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay_k);

    /* End of Outputs for SubSystem: '<S66>/turnON_delay' */

    /* Outputs for Atomic SubSystem: '<S66>/turnON_delay1' */
    swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator3_fi, dric_tm_gearLvrLckInd_s,
      ((float32)DRI_TASK_INTERVAL_S), &rtb_flg_out_o,
      &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay1_c);

    /* End of Outputs for SubSystem: '<S66>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S66>/turnON_delay2' */
    swc_VOMM_turnON_delay_4WD(rtb_LogicalOperator3_d, dric_tm_gearLvrLckInd_s,
      ((float32)DRI_TASK_INTERVAL_S), &rtb_flg_out_g,
      &swc_VOMM_ARID_DEF.ARID_DEF_turnON_delay2);

    /* End of Outputs for SubSystem: '<S66>/turnON_delay2' */

    /* Logic: '<S25>/Logical Operator8' incorporates:
     *  Constant: '<S66>/Constant10'
     *  Constant: '<S66>/Constant11'
     *  Constant: '<S66>/Constant13'
     *  Constant: '<S66>/Constant14'
     *  Constant: '<S66>/Constant4'
     *  Constant: '<S66>/Constant9'
     *  Inport generated from: '<Root>/BusElementIn10'
     *  RelationalOperator: '<S62>/FixPt Relational Operator'
     *  RelationalOperator: '<S63>/FixPt Relational Operator'
     *  RelationalOperator: '<S64>/FixPt Relational Operator'
     *  RelationalOperator: '<S65>/FixPt Relational Operator'
     *  UnitDelay: '<S62>/Delay Input1'
     *  UnitDelay: '<S64>/Delay Input1'
     *  UnitDelay: '<S65>/Delay Input1'
     *
     * Block description for '<S62>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S64>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S65>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_RelationalOperator1_o = (((sint32)rtb_RelationalOperator1_m3_tm_0 >
      (sint32)swc_VOMM_ARID_DEF.DelayInput1_DSTATE_j) || ((sint32)
      rtb_LogicalOperator6_k > (sint32)swc_VOMM_ARID_DEF.DelayInput1_DSTATE_d) ||
      ((sint32)drid_b_egsmParkReq > (sint32)
       swc_VOMM_ARID_DEF.DelayInput1_DSTATE_k));

    /* Chart: '<S25>/EPBClsdReq' incorporates:
     *  Constant: '<S25>/Constant4'
     */
    if (swc_VOMM_ARID_DEF.is_active_c4_swc_VOMM == 0U) {
      swc_VOMM_ARID_DEF.is_active_c4_swc_VOMM = 1U;
      swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_INIT;
      swcvomm_drid_b_epbClsdReq = false;
      swc_VOMM_ARID_DEF.T_m = 0U;
    } else {
      switch (swc_VOMM_ARID_DEF.is_c4_swc_VOMM) {
       case swc_VOMM_IN_EPBCLOSE:
        {
          if (swc_VOMM_ARID_DEF.T_m >= 1) {
            swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_OPEN;
            swcvomm_drid_b_epbClsdReq = false;
            swc_VOMM_ARID_DEF.T_m = 0U;
          } else {
            sint32 tmp;
            tmp = swc_VOMM_ARID_DEF.T_m + 1;
            if (swc_VOMM_ARID_DEF.T_m + 1 > 65535) {
              tmp = 65535;
            }

            swc_VOMM_ARID_DEF.T_m = (uint16)tmp;
          }
        }
        break;

       case swc_VOMM_IN_EPBOPENTOCLOSE:
        {
          if (swc_VOMM_ARID_DEF.T_m >= dric_t_epbClsReqTout_s) {
            swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_OPEN;
            swcvomm_drid_b_epbClsdReq = false;
            swc_VOMM_ARID_DEF.T_m = 0U;
          } else {
            sint32 tmp;
            tmp = swc_VOMM_ARID_DEF.T_m + 1;
            if (swc_VOMM_ARID_DEF.T_m + 1 > 65535) {
              tmp = 65535;
            }

            swc_VOMM_ARID_DEF.T_m = (uint16)tmp;
          }
        }
        break;

       case swc_VOMM_IN_INIT:
        if (rtb_RelationalOperator1_o && rtb_RelationalOperator4_m) {
          swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_EPBCLOSE;
          swcvomm_drid_b_epbClsdReq = true;
          swc_VOMM_ARID_DEF.T_m = 0U;
        } else if (rtb_RelationalOperator1_o && (!rtb_RelationalOperator4_m)) {
          swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_EPBOPENTOCLOSE;
          swcvomm_drid_b_epbClsdReq = true;
          swc_VOMM_ARID_DEF.T_m = 0U;
        }
        break;

       default:
        /* case IN_OPEN: */
        if (rtb_RelationalOperator1_o && rtb_RelationalOperator4_m) {
          swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_EPBCLOSE;
          swcvomm_drid_b_epbClsdReq = true;
          swc_VOMM_ARID_DEF.T_m = 0U;
        } else if (rtb_RelationalOperator1_o && (!rtb_RelationalOperator4_m)) {
          swc_VOMM_ARID_DEF.is_c4_swc_VOMM = swc_VOMM_IN_EPBOPENTOCLOSE;
          swcvomm_drid_b_epbClsdReq = true;
          swc_VOMM_ARID_DEF.T_m = 0U;
        }
        break;
      }
    }

    /* End of Chart: '<S25>/EPBClsdReq' */

    /* Switch: '<S25>/Switch2' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S55>/Constant'
     *  RelationalOperator: '<S44>/Compare'
     *  RelationalOperator: '<S55>/Compare'
     *  Switch: '<S25>/Switch'
     */
    if (swcvomm_drid_st_egsmGearReqRaw == ((uint8)0U)) {
      /* Switch: '<S25>/Switch2' incorporates:
       *  Constant: '<S25>/Constant7'
       */
      rtb_Switch2_o = ((uint8)0U);
    } else if (rtb_DataTypeConversion_n >= ((uint8)6U)) {
      /* Switch: '<S25>/Switch' incorporates:
       *  Switch: '<S25>/Switch2'
       */
      rtb_Switch2_o = swcvomm_drid_st_egsmGearReqRaw;
    } else {
      /* Switch: '<S25>/Switch2' incorporates:
       *  UnitDelay: '<S25>/Unit Delay8'
       */
      rtb_Switch2_o = swc_VOMM_ARID_DEF.UnitDelay8_DSTATE;
    }

    /* End of Switch: '<S25>/Switch2' */

    /* RelationalOperator: '<S46>/Compare' incorporates:
     *  Inport generated from: '<Root>/BusElementIn7'
     *  RelationalOperator: '<S47>/Compare'
     *  RelationalOperator: '<S48>/Compare'
     */
    rtb_LogicalOperator14_tmp =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_obcOnBdDchaCCline();

    /* Logic: '<S25>/Logical Operator14' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S47>/Constant'
     *  Constant: '<S48>/Constant'
     *  Inport generated from: '<Root>/BusElementIn7'
     *  RelationalOperator: '<S46>/Compare'
     *  RelationalOperator: '<S47>/Compare'
     *  RelationalOperator: '<S48>/Compare'
     */
    rtb_RelationalOperator1_o = ((rtb_LogicalOperator14_tmp == ((uint8)1U)) ||
      (rtb_LogicalOperator14_tmp == ((uint8)2U)) || (rtb_LogicalOperator14_tmp ==
      ((uint8)3U)));

    /* Switch: '<S25>/Switch5' incorporates:
     *  Constant: '<S49>/Constant'
     *  Inport generated from: '<Root>/BusElementIn13'
     *  RelationalOperator: '<S49>/Compare'
     */
    if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp() != ((uint8)
         2U)) {
      /* Switch: '<S25>/Switch4' incorporates:
       *  Constant: '<S60>/Constant'
       *  Inport generated from: '<Root>/BusElementIn8'
       *  RelationalOperator: '<S60>/Compare'
       */
      if (Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgChgTyp() == false) {
        /* RelationalOperator: '<S43>/Compare' incorporates:
         *  Inport generated from: '<Root>/In Bus Element120'
         *  RelationalOperator: '<S58>/Compare'
         *  RelationalOperator: '<S59>/Compare'
         */
        rtb_LogicalOperator14_tmp =
          Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_obcOnBdCCline();

        /* Switch: '<S25>/Switch4' incorporates:
         *  Constant: '<S43>/Constant'
         *  Constant: '<S58>/Constant'
         *  Constant: '<S59>/Constant'
         *  Inport generated from: '<Root>/In Bus Element120'
         *  Logic: '<S25>/Logical Operator12'
         *  RelationalOperator: '<S43>/Compare'
         *  RelationalOperator: '<S58>/Compare'
         *  RelationalOperator: '<S59>/Compare'
         */
        rtb_RelationalOperator2_cb = ((rtb_LogicalOperator14_tmp == ((uint8)1U))
          || (rtb_LogicalOperator14_tmp == ((uint8)2U)) ||
          (rtb_LogicalOperator14_tmp == ((uint8)3U)));
      } else {
        /* RelationalOperator: '<S61>/Compare' incorporates:
         *  Inport generated from: '<Root>/BusElementIn6'
         *  RelationalOperator: '<S45>/Compare'
         */
        rtb_LogicalOperator14_tmp =
          Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_obcChgCCSts();

        /* Switch: '<S25>/Switch4' incorporates:
         *  Constant: '<S45>/Constant'
         *  Constant: '<S61>/Constant'
         *  Inport generated from: '<Root>/BusElementIn6'
         *  Logic: '<S25>/Logical Operator13'
         *  RelationalOperator: '<S45>/Compare'
         *  RelationalOperator: '<S61>/Compare'
         */
        rtb_RelationalOperator2_cb = ((rtb_LogicalOperator14_tmp == ((uint8)1U))
          || (rtb_LogicalOperator14_tmp == ((uint8)2U)));
      }

      /* End of Switch: '<S25>/Switch4' */

      /* RelationalOperator: '<S56>/Compare' incorporates:
       *  Inport generated from: '<Root>/In Bus Element121'
       *  RelationalOperator: '<S57>/Compare'
       */
      rtb_LogicalOperator14_tmp =
        Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_dcChgCcSt();

      /* Switch: '<S25>/Switch5' incorporates:
       *  Constant: '<S56>/Constant'
       *  Constant: '<S57>/Constant'
       *  Inport generated from: '<Root>/In Bus Element121'
       *  Logic: '<S25>/Logical Operator11'
       *  Logic: '<S25>/Logical Operator7'
       *  RelationalOperator: '<S56>/Compare'
       *  RelationalOperator: '<S57>/Compare'
       */
      rtb_Switch5_k = ((rtb_LogicalOperator14_tmp == ((uint8)1U)) ||
                       (rtb_LogicalOperator14_tmp == ((uint8)3U)) ||
                       rtb_RelationalOperator2_cb || rtb_RelationalOperator1_o);
    } else {
      uint8 rtb_Switch5_k_tmp;

      /* RelationalOperator: '<S51>/Compare' incorporates:
       *  Inport generated from: '<Root>/In Bus Element121'
       *  RelationalOperator: '<S50>/Compare'
       */
      rtb_LogicalOperator14_tmp =
        Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_dcChgCcSt();

      /* RelationalOperator: '<S53>/Compare' incorporates:
       *  Inport generated from: '<Root>/BusElementIn11'
       *  RelationalOperator: '<S52>/Compare'
       */
      rtb_Switch5_k_tmp = Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_hvbChgCcsts();

      /* Switch: '<S25>/Switch5' incorporates:
       *  Constant: '<S50>/Constant'
       *  Constant: '<S51>/Constant'
       *  Constant: '<S52>/Constant'
       *  Constant: '<S53>/Constant'
       *  Inport generated from: '<Root>/In Bus Element121'
       *  Inport generated from: '<Root>/BusElementIn11'
       *  Logic: '<S25>/Logical Operator15'
       *  Logic: '<S25>/Logical Operator16'
       *  Logic: '<S25>/Logical Operator17'
       *  RelationalOperator: '<S50>/Compare'
       *  RelationalOperator: '<S51>/Compare'
       *  RelationalOperator: '<S52>/Compare'
       *  RelationalOperator: '<S53>/Compare'
       */
      rtb_Switch5_k = ((rtb_LogicalOperator14_tmp == ((uint8)1U)) ||
                       (rtb_LogicalOperator14_tmp == ((uint8)3U)) ||
                       ((rtb_Switch5_k_tmp == ((uint8)1U)) || (rtb_Switch5_k_tmp
        == ((uint8)2U))) || rtb_RelationalOperator1_o);
    }

    /* End of Switch: '<S25>/Switch5' */

    /* Update for UnitDelay: '<S25>/Unit Delay7' */
    swc_VOMM_ARID_DEF.UnitDelay7_DSTATE = swcvomm_drid_st_egsmGearReqRaw;

    /* Update for UnitDelay: '<S25>/Unit Delay9' */
    swc_VOMM_ARID_DEF.UnitDelay9_DSTATE = rtb_DataTypeConversion_n;

    /* Update for UnitDelay: '<S62>/Delay Input1'
     *
     * Block description for '<S62>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_k = drid_b_egsmParkReq;

    /* Update for UnitDelay: '<S25>/Unit Delay4' */
    swc_VOMM_ARID_DEF.UnitDelay4_DSTATE_g = swc_VOMM_ARID_DEF.GearLeverPosSts;

    /* Update for UnitDelay: '<S124>/Delay Input1'
     *
     * Block description for '<S124>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_p = swcvomm_drid_b_autoParkFlg;

    /* Update for UnitDelay: '<S125>/Delay Input1'
     *
     * Block description for '<S125>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_n = vsmd_b_VehRun;

    /* Update for UnitDelay: '<S126>/Delay Input1'
     *
     * Block description for '<S126>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_ns = rtb_FixPtRelationalOperator;

    /* Update for UnitDelay: '<S127>/Delay Input1'
     *
     * Block description for '<S127>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_n2 = rtb_RelationalOperator7_l;

    /* Update for UnitDelay: '<S128>/Delay Input1'
     *
     * Block description for '<S128>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_ld = rtb_LogicalOperator1_j3;

    /* Update for UnitDelay: '<S63>/Delay Input1'
     *
     * Block description for '<S63>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_g = rtb_RelationalOperator1_m3_tm_0;

    /* Update for UnitDelay: '<S64>/Delay Input1'
     *
     * Block description for '<S64>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_d = rtb_LogicalOperator6_k;

    /* Update for UnitDelay: '<S65>/Delay Input1'
     *
     * Block description for '<S65>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_j = rtb_RelationalOperator1_m3_tm_0;

    /* Update for UnitDelay: '<S79>/Delay Input1'
     *
     * Block description for '<S79>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_h = rtb_BrkPdlPushFstFlg;

    /* Update for UnitDelay: '<S80>/Delay Input1'
     *
     * Block description for '<S80>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_i = rtb_LogicalOperator2_f;

    /* Update for UnitDelay: '<S25>/Unit Delay2' */
    swc_VOMM_ARID_DEF.UnitDelay2_DSTATE = rtb_Switch2_o;

    /* Update for UnitDelay: '<S25>/Unit Delay' */
    swc_VOMM_ARID_DEF.UnitDelay_DSTATE_g = rtb_Saturation1;

    /* Update for UnitDelay: '<S25>/Unit Delay6' incorporates:
     *  UnitDelay: '<S25>/Unit Delay3'
     */
    swc_VOMM_ARID_DEF.UnitDelay6_DSTATE = swc_VOMM_ARID_DEF.UnitDelay3_DSTATE;

    /* Update for UnitDelay: '<S25>/Unit Delay1' incorporates:
     *  UnitDelay: '<S25>/Unit Delay6'
     */
    swc_VOMM_ARID_DEF.UnitDelay1_DSTATE_h = rtb_UnitDelay6;

    /* Update for UnitDelay: '<S81>/Delay Input1'
     *
     * Block description for '<S81>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_VOMM_ARID_DEF.DelayInput1_DSTATE_e = swc_VOMM_ARID_DEF.Merge;

    /* Update for UnitDelay: '<S25>/Unit Delay5' */
    swc_VOMM_ARID_DEF.UnitDelay5_DSTATE = swc_VOMM_ARID_DEF.GearLeverPosSts;

    /* Update for UnitDelay: '<S66>/Unit Delay9' */
    swc_VOMM_ARID_DEF.UnitDelay9_DSTATE_f = rtb_flg_out_i;

    /* Update for UnitDelay: '<S66>/Unit Delay1' */
    swc_VOMM_ARID_DEF.UnitDelay1_DSTATE_f = rtb_flg_out_o;

    /* Update for UnitDelay: '<S66>/Unit Delay2' */
    swc_VOMM_ARID_DEF.UnitDelay2_DSTATE_a = rtb_flg_out_g;

    /* Update for UnitDelay: '<S25>/Unit Delay8' */
    swc_VOMM_ARID_DEF.UnitDelay8_DSTATE = rtb_Switch2_o;

    /* Update for UnitDelay: '<S25>/Unit Delay3' */
    swc_VOMM_ARID_DEF.UnitDelay3_DSTATE = swc_VOMM_ARID_DEF.GearLeverPosSts;
  }

  /* End of Logic: '<S7>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S7>/Calc_GearLeverPos2' */

  /* Switch: '<S144>/Switch2' incorporates:
   *  Constant: '<S32>/dric_b_gearLvrPos_ovrdflg'
   *  Constant: '<S32>/dric_e_gearLvrPos_ovrdval'
   *  Constant: '<S7>/Constant1'
   *  Switch: '<S7>/Switch10'
   */
  if (dric_b_gearLvrPos_ovrdflg) {
    drid_e_gearLvrPos = dric_e_gearLvrPos_ovrdval;
  } else if (dric_b_useGearLvrPosFromCan) {
    /* Switch: '<S7>/Switch10' incorporates:
     *  Switch: '<S144>/Switch2'
     */
    drid_e_gearLvrPos = swc_VOMM_ARID_DEF.GearLeverPosSts_m;
  } else {
    drid_e_gearLvrPos = swc_VOMM_ARID_DEF.GearLeverPosSts;
  }

  /* End of Switch: '<S144>/Switch2' */

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Constant'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  RelationalOperator: '<S7>/Relational Operator2'
   *  RelationalOperator: '<S7>/Relational Operator4'
   *  Switch: '<S144>/Switch2'
   *  Switch: '<S7>/Switch2'
   */
  if ((drid_e_gearLvrPos == GearLeverPos_SPT_DRIVE) || (drid_e_gearLvrPos ==
       GearLeverPos_FWD_DRIVE)) {
    swc_VOMM_ARID_DEF.drid_e_driveDirSel = DriveDir_FORWARD;
  } else if (drid_e_gearLvrPos == GearLeverPos_REV_DRIVE) {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S27>/Constant'
     *  Switch: '<S7>/Switch1'
     */
    swc_VOMM_ARID_DEF.drid_e_driveDirSel = DriveDir_REVERSE;
  } else {
    swc_VOMM_ARID_DEF.drid_e_driveDirSel = DriveDir_NO_DRIVE;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element38'
   *  SignalConversion: '<S8>/Signal Conversion1'
   */
  rtb_FixPtRelationalOperator =
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReq4WD();

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S8>/Constant7'
   *  Inport generated from: '<Root>/In Bus Element38'
   *  Inport generated from: '<Root>/In Bus Element37'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S7>/Relational Operator4'
   *  RelationalOperator: '<S8>/Relational Operator4'
   *  Switch: '<S144>/Switch2'
   */
  rtb_drid_b_vehSportModActv = ((drid_e_gearLvrPos == GearLeverPos_SPT_DRIVE) ||
    Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqSPORT() ||
    (dric_b_enaSportModeIn4WDMode && rtb_FixPtRelationalOperator));

  /* SignalConversion: '<S8>/Signal Conversion1' */
  drid_b_veh4WDModActv = rtb_FixPtRelationalOperator;

  /* Switch: '<S157>/Switch1' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  if (tmp_0 == true) {
    /* Switch: '<S157>/Switch1' */
    swcvomm_drid_b_vehEcoModActv = swc_VOMM_ARID_DEF.EcoMod_j;
  } else {
    /* Switch: '<S157>/Switch1' */
    swcvomm_drid_b_vehEcoModActv = swc_VOMM_ARID_DEF.EcoMod;
  }

  /* End of Switch: '<S157>/Switch1' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S146>/Constant'
   *  Constant: '<S147>/Constant'
   *  Constant: '<S148>/Constant'
   *  Constant: '<S149>/Constant'
   *  Constant: '<S150>/Constant'
   *  Logic: '<S8>/Logical Operator2'
   *  Logic: '<S8>/Logical Operator3'
   *  Logic: '<S8>/Logical Operator4'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S146>/Compare'
   *  RelationalOperator: '<S147>/Compare'
   *  RelationalOperator: '<S148>/Compare'
   *  RelationalOperator: '<S149>/Compare'
   *  RelationalOperator: '<S150>/Compare'
   *  Switch: '<S8>/Switch'
   *  Switch: '<S8>/Switch2'
   */
  if ((drid_b_vehSportModActv == false) && (swcvomm_drid_b_vehEcoModActv ==
       false)) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    drid_st_DriModWrite = ((uint8)1U);
  } else if ((drid_b_vehSportModActv == true) && (swcvomm_drid_b_vehEcoModActv ==
              false)) {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S8>/Constant'
     *  Switch: '<S8>/Switch1'
     */
    drid_st_DriModWrite = ((uint8)2U);
  } else if ((drid_b_vehSportModActv == false) && (swcvomm_drid_b_vehEcoModActv ==
              true)) {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Switch: '<S8>/Switch'
     *  Switch: '<S8>/Switch1'
     */
    drid_st_DriModWrite = ((uint8)3U);
  } else {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant3'
     *  Switch: '<S8>/Switch'
     *  Switch: '<S8>/Switch2'
     */
    drid_st_DriModWrite = ((uint8)0U);
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Switch: '<S157>/Switch2' incorporates:
   *  Constant: '<S160>/Constant'
   *  RelationalOperator: '<S160>/Compare'
   */
  if (tmp_0 == true) {
    tmp_1 = swc_VOMM_ARID_DEF.InitMod_n;
  } else {
    tmp_1 = swc_VOMM_ARID_DEF.InitMod;
  }

  /* Logic: '<S8>/Logical Operator6' incorporates:
   *  Constant: '<S151>/Constant'
   *  Logic: '<S8>/Logical Operator5'
   *  RelationalOperator: '<S151>/Compare'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Switch: '<S157>/Switch2'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  drid_b_DriModWriteflg = ((drid_b_DriModAct_tmp == false) && (tmp_1 &&
    (drid_st_DriModWrite != swc_VOMM_ARID_DEF.UnitDelay_DSTATE)));

  /* Outputs for Enabled SubSystem: '<S8>/Subsystem1' incorporates:
   *  EnablePort: '<S156>/Enable'
   */
  if (drid_b_DriModWriteflg) {
    /* CCaller: '<S156>/C Caller8' */
    mBSW_NvmWrite_DriMod(drid_st_DriModWrite);
  }

  /* End of Outputs for SubSystem: '<S8>/Subsystem1' */

  /* Update for UnitDelay: '<S153>/Delay Input1'
   *
   * Block description for '<S153>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_VOMM_ARID_DEF.DelayInput1_DSTATE = rtb_FixPtRelationalOperator_tmp;

  /* Update for UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_VOMM_ARID_DEF.DelayInput1_DSTATE_l = rtb_LogicalOperator6_jj_tmp;

  /* Update for UnitDelay: '<S6>/Unit Delay1' incorporates:
   *  Constant: '<S6>/Constant12'
   */
  swc_VOMM_ARID_DEF.UnitDelay1_DSTATE = false;

  /* Update for UnitDelay: '<S6>/Unit Delay' incorporates:
   *  Switch: '<S6>/Switch8'
   */
  swc_VOMM_ARID_DEF.UnitDelay_DSTATE_m = drid_e_drvrHEVModReq;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  swc_VOMM_ARID_DEF.UnitDelay_DSTATE = drid_st_DriModWrite;
}

/* Function for Chart: '<S3>/Hybrid_Mode_Manager' */
static void swc_VOMM_PHEV_MODE(HybModeMngr *hmm_status, const HEVModeReq *signal)
{
  *hmm_status = HybModeMngr_PHEV_MODE;

  /* Switch: '<S187>/Switch2' */
  switch (*signal) {
   case HEVModeReq_OFF:
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_TO_PTENA_TRANS;
    *hmm_status = HybModeMngr_PHEV2PTENA;
    break;

   case HEVModeReq_ICE:
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_TO_ICE_TRANS;
    *hmm_status = HybModeMngr_PHEV2ICE;
    break;

   case HEVModeReq_SHEV:
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_TO_SHEV_TRANS;
    *hmm_status = HybModeMngr_PHEV2SHEV;
    break;

   default:
    /*   */
    if (*signal == HEVModeReq_EV) {
      swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_TO_EV_TRANS;
      *hmm_status = HybModeMngr_PHEV2EV;
    }
    break;
  }

  /* End of Switch: '<S187>/Switch2' */
}

/* Function for Chart: '<S3>/Hybrid_Mode_Manager' */
static void swc_VOMM_PT_ENA(HybModeMngr *hmm_status, const HEVModeReq *signal)
{
  *hmm_status = HybModeMngr_PT_ENA;
  if (vsmd_b_PTDisabled) {
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHUTDOWN;
    *hmm_status = HybModeMngr_SHUTDOWN;
  } else {
    /* Switch: '<S187>/Switch2' */
    switch (*signal) {
     case HEVModeReq_ICE:
      swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PTENA_TO_ICE_TRANS;
      *hmm_status = HybModeMngr_PTENA2ICE;
      break;

     case HEVModeReq_PHEV:
      swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PTENA_TO_PHEV_TRANS;
      *hmm_status = HybModeMngr_PTENA2PHEV;
      break;

     case HEVModeReq_SHEV:
      swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PTENA_TO_SHEV_TRANS;
      *hmm_status = HybModeMngr_PTENA2SHEV;
      break;

     case HEVModeReq_EV:
      swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PTENA_TO_EV_TRANS;
      *hmm_status = HybModeMngr_PTENA2EV;
      break;
    }

    /* End of Switch: '<S187>/Switch2' */
  }
}

/* Function for Chart: '<S3>/Hybrid_Mode_Manager' */
static void swc_VOMM_SHEV_MODE(HybModeMngr *hmm_status, const HEVModeReq *signal)
{
  *hmm_status = HybModeMngr_SHEV_MODE;

  /* Switch: '<S187>/Switch2' */
  if (*signal == HEVModeReq_OFF) {
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHEV_TO_PTENA_TRANS;
    *hmm_status = HybModeMngr_SHEV2PTENA;
  } else if ((*signal == HEVModeReq_PHEV) || (*signal == HEVModeReq_ICE)) {
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHEV_TO_PHEV_TRANS;
    *hmm_status = HybModeMngr_SHEV2PHEV;
  } else if (*signal == HEVModeReq_EV) {
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHEV_TO_EV_TRANS;
    *hmm_status = HybModeMngr_SHEV2EV;
  }

  /* End of Switch: '<S187>/Switch2' */
}

/* Output and update for function-call system: '<S1>/HMM_ModeManager' */
static void swc_VOMM_HMM_ModeManager(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator1_g;
  boolean rtb_LogicalOperator2_l;
  HEVModeReq signal;
  HybModeMngr hmm_status;

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S168>/hmmc_b_hmmModeReq_ovrdflg'
   */
  if (hmmc_b_hmmModeReq_ovrdflg) {
    /* Switch: '<S187>/Switch2' incorporates:
     *  Constant: '<S168>/hmmc_e_hmmModeReq_ovrdval'
     */
    signal = hmmc_e_hmmModeReq_ovrdval;
  } else {
    /* Switch: '<S187>/Switch2' */
    signal = HEVModeReq_OFF;
  }

  /* End of Switch: '<S187>/Switch2' */

  /* Chart: '<S3>/Hybrid_Mode_Manager' incorporates:
   *  Switch: '<S187>/Switch2'
   */
  if (swc_VOMM_ARID_DEF.is_active_c5_hmm == 0U) {
    swc_VOMM_ARID_DEF.is_active_c5_hmm = 1U;
    swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PT_OFF;
    hmm_status = HybModeMngr_PT_OFF;
  } else {
    switch (swc_VOMM_ARID_DEF.is_c5_hmm) {
     case swc_VOMM_IN_EV_MODE:
      hmm_status = HybModeMngr_EV_MODE;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_EV_TO_PTENA_TRANS;
        hmm_status = HybModeMngr_EV2PTENA;
      } else if ((signal == HEVModeReq_PHEV) || (signal == HEVModeReq_ICE)) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_EV_TO_PHEV_TRANS;
        hmm_status = HybModeMngr_EV2PHEV;
      } else if (signal == HEVModeReq_SHEV) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_EV_TO_SHEV_TRANS;
        hmm_status = HybModeMngr_EV2SHEV;
      }
      break;

     case swc_VOMM_IN_EV_TO_PHEV_TRANS:
      hmm_status = HybModeMngr_EV2PHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_EV_MODE;
        hmm_status = HybModeMngr_EV_MODE;
      }
      break;

     case swc_VOMM_IN_EV_TO_PTENA_TRANS:
      hmm_status = HybModeMngr_EV2PTENA;
      break;

     case swc_VOMM_IN_EV_TO_SHEV_TRANS:
      hmm_status = HybModeMngr_EV2SHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_EV_MODE;
        hmm_status = HybModeMngr_EV_MODE;
      }
      break;

     case swc_VOMM_IN_ICE_MODE:
      hmm_status = HybModeMngr_ICE_MODE;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_ICE_TO_PTENA_TRANS;
        hmm_status = HybModeMngr_ICE2PTENA;
      } else if (signal != HEVModeReq_ICE) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_ICE_TO_PHEV_TRANS;
        hmm_status = HybModeMngr_ICE2PHEV;
      }
      break;

     case swc_VOMM_IN_ICE_TO_PHEV_TRANS:
      hmm_status = HybModeMngr_ICE2PHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_ICE_MODE;
        hmm_status = HybModeMngr_ICE_MODE;
      }
      break;

     case swc_VOMM_IN_ICE_TO_PTENA_TRANS:
      hmm_status = HybModeMngr_ICE2PTENA;
      break;

     case swc_VOMM_IN_PHEV_MODE:
      swc_VOMM_PHEV_MODE(&hmm_status, &signal);
      break;

     case swc_VOMM_IN_PHEV_TO_EV_TRANS:
      hmm_status = HybModeMngr_PHEV2EV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_MODE;
        hmm_status = HybModeMngr_PHEV_MODE;
      }
      break;

     case swc_VOMM_IN_PHEV_TO_ICE_TRANS:
      hmm_status = HybModeMngr_PHEV2ICE;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_MODE;
        hmm_status = HybModeMngr_PHEV_MODE;
      }
      break;

     case swc_VOMM_IN_PHEV_TO_PTENA_TRANS:
      hmm_status = HybModeMngr_PHEV2PTENA;
      break;

     case swc_VOMM_IN_PHEV_TO_SHEV_TRANS:
      hmm_status = HybModeMngr_PHEV2SHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_MODE;
        hmm_status = HybModeMngr_PHEV_MODE;
      }
      break;

     case swc_VOMM_IN_PTENA_TO_EV_TRANS:
      hmm_status = HybModeMngr_PTENA2EV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_EV_TO_PTENA_TRANS;
        hmm_status = HybModeMngr_EV2PTENA;
      }
      break;

     case swc_VOMM_IN_PTENA_TO_ICE_TRANS:
      hmm_status = HybModeMngr_PTENA2ICE;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_ICE_TO_PTENA_TRANS;
        hmm_status = HybModeMngr_ICE2PTENA;
      }
      break;

     case swc_VOMM_IN_PTENA_TO_PHEV_TRANS:
      hmm_status = HybModeMngr_PTENA2PHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PHEV_TO_PTENA_TRANS;
        hmm_status = HybModeMngr_PHEV2PTENA;
      }
      break;

     case swc_VOMM_IN_PTENA_TO_SHEV_TRANS:
      hmm_status = HybModeMngr_PTENA2SHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHEV_TO_PTENA_TRANS;
        hmm_status = HybModeMngr_SHEV2PTENA;
      }
      break;

     case swc_VOMM_IN_PT_ENA:
      swc_VOMM_PT_ENA(&hmm_status, &signal);
      break;

     case swc_VOMM_IN_PT_OFF:
      hmm_status = HybModeMngr_PT_OFF;
      if (vsmd_b_PTEnabled) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PT_ENA;
        hmm_status = HybModeMngr_PT_ENA;
      }
      break;

     case swc_VOMM_IN_SHEV_MODE:
      swc_VOMM_SHEV_MODE(&hmm_status, &signal);
      break;

     case swc_VOMM_IN_SHEV_TO_EV_TRANS:
      hmm_status = HybModeMngr_SHEV2EV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHEV_MODE;
        hmm_status = HybModeMngr_SHEV_MODE;
      }
      break;

     case swc_VOMM_IN_SHEV_TO_PHEV_TRANS:
      hmm_status = HybModeMngr_SHEV2PHEV;
      if (signal == HEVModeReq_OFF) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_SHEV_MODE;
        hmm_status = HybModeMngr_SHEV_MODE;
      }
      break;

     case swc_VOMM_IN_SHEV_TO_PTENA_TRANS:
      hmm_status = HybModeMngr_SHEV2PTENA;
      break;

     default:
      /* case IN_SHUTDOWN: */
      hmm_status = HybModeMngr_SHUTDOWN;
      if (vsmd_b_PTEnabled) {
        swc_VOMM_ARID_DEF.is_c5_hmm = swc_VOMM_IN_PT_ENA;
        hmm_status = HybModeMngr_PT_ENA;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Hybrid_Mode_Manager' */

  /* Switch: '<S188>/Switch2' incorporates:
   *  Constant: '<S169>/hmmc_b_hmmState_ovrdflg'
   */
  if (hmmc_b_hmmState_ovrdflg) {
    /* Switch: '<S188>/Switch2' incorporates:
     *  Constant: '<S169>/hmmc_e_hmmState_ovrdval'
     */
    hmmd_e_hmmState = hmmc_e_hmmState_ovrdval;
  } else {
    /* Switch: '<S188>/Switch2' */
    hmmd_e_hmmState = hmm_status;
  }

  /* End of Switch: '<S188>/Switch2' */

  /* Logic: '<S165>/Logical Operator' incorporates:
   *  Constant: '<S171>/Constant'
   *  Constant: '<S172>/Constant'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S180>/Constant'
   *  Constant: '<S181>/Constant'
   *  Constant: '<S182>/Constant'
   *  RelationalOperator: '<S165>/Relational Operator1'
   *  RelationalOperator: '<S165>/Relational Operator14'
   *  RelationalOperator: '<S165>/Relational Operator15'
   *  RelationalOperator: '<S165>/Relational Operator2'
   *  RelationalOperator: '<S165>/Relational Operator3'
   *  RelationalOperator: '<S165>/Relational Operator4'
   *  Switch: '<S188>/Switch2'
   */
  hmmd_b_EVModeActive = ((hmmd_e_hmmState == HybModeMngr_SHEV_MODE) ||
    (hmmd_e_hmmState == HybModeMngr_EV_MODE) || (hmmd_e_hmmState ==
    HybModeMngr_PHEV2SHEV) || (hmmd_e_hmmState == HybModeMngr_PHEV2EV) ||
    (hmmd_e_hmmState == HybModeMngr_SHEV2EV) || (hmmd_e_hmmState ==
    HybModeMngr_EV2SHEV));

  /* Logic: '<S165>/Logical Operator1' incorporates:
   *  Constant: '<S171>/Constant'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S181>/Constant'
   *  Constant: '<S182>/Constant'
   *  RelationalOperator: '<S165>/Relational Operator1'
   *  RelationalOperator: '<S165>/Relational Operator10'
   *  RelationalOperator: '<S165>/Relational Operator14'
   *  RelationalOperator: '<S165>/Relational Operator3'
   *  RelationalOperator: '<S165>/Relational Operator4'
   *  RelationalOperator: '<S165>/Relational Operator5'
   *  RelationalOperator: '<S165>/Relational Operator6'
   *  RelationalOperator: '<S165>/Relational Operator9'
   *  Switch: '<S188>/Switch2'
   */
  rtb_LogicalOperator1_g = ((hmmd_e_hmmState == HybModeMngr_SHEV_MODE) ||
    (hmmd_e_hmmState == HybModeMngr_PHEV2SHEV) || (hmmd_e_hmmState ==
    HybModeMngr_SHEV2EV) || (hmmd_e_hmmState == HybModeMngr_EV2SHEV));

  /* Logic: '<S165>/Logical Operator2' incorporates:
   *  Constant: '<S173>/Constant'
   *  Constant: '<S175>/Constant'
   *  Constant: '<S178>/Constant'
   *  Constant: '<S184>/Constant'
   *  RelationalOperator: '<S165>/Relational Operator12'
   *  RelationalOperator: '<S165>/Relational Operator13'
   *  RelationalOperator: '<S165>/Relational Operator14'
   *  RelationalOperator: '<S165>/Relational Operator7'
   *  RelationalOperator: '<S165>/Relational Operator8'
   *  Switch: '<S188>/Switch2'
   */
  rtb_LogicalOperator2_l = ((hmmd_e_hmmState == HybModeMngr_ICE_MODE) ||
    (hmmd_e_hmmState == HybModeMngr_PHEV_MODE) || (hmmd_e_hmmState ==
    HybModeMngr_ICE2PHEV) || (hmmd_e_hmmState == HybModeMngr_PHEV2ICE));

  /* Switch: '<S166>/Switch' incorporates:
   *  Constant: '<S166>/Constant'
   *  Constant: '<S166>/Constant1'
   *  Constant: '<S166>/Constant14'
   *  Logic: '<S166>/Logical Operator2'
   *  RelationalOperator: '<S166>/Relational Operator7'
   */
  if ((((uint8)VEH_SWT_INF) == ((uint8)4U)) || hmmc_b_dcBusDischargeType) {
    /* Switch: '<S166>/Switch' incorporates:
     *  Constant: '<S166>/Constant2'
     *  Logic: '<S166>/Logical Operator5'
     *  RelationalOperator: '<S166>/Relational Operator'
     */
    hmmd_b_HVBusDischrgComplete = (swc_VOMM_ConstB.RelationalOperator13 &&
      (swc_VOMM_ConstB.MinMax < hmmc_u_dcBusDischargeThr_V));
  } else {
    /* Switch: '<S166>/Switch' incorporates:
     *  Inport generated from: '<Root>/In Bus Element114'
     */
    hmmd_b_HVBusDischrgComplete =
      Rte_IRead_swc_VOMM_Step_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt();
  }

  /* End of Switch: '<S166>/Switch' */
}

/* ConstCode for function-call system: '<S1>/HMM_ModeManager' */
static void swc_VOMM_HMM_ModeManager_Const(void)
{
  /* ConstCode for RelationalOperator: '<S166>/Relational Operator4' incorporates:
   *  Constant: '<S186>/Constant'
   */
  hmmd_b_bHVReady = (HVBRelayStatus_CLOSED == HVBRelayStatus_RESERVED);
}

/* Model step function */
void swc_VOMM_Step(void)
{
  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/PMM_PowerModeManager'
   */
  swc_VOMM_PMM_PowerModeManager();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/VSM_VehicleStartManager'
   */
  swc_VOM_VSM_VehicleStartManager();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DRI_DriveModesManagment'
   */
  swc_VOM_DRI_DriveModesManagment();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/HMM_ModeManager'
   */
  swc_VOMM_HMM_ModeManager();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Outport generated from: '<Root>/Out Bus Element' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq(&pmmd_bm_netModeReq[0]);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion110'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_e_mode(pmmd_e_mode);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion111'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_emsWake(pmmd_b_emsWake);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion112'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_peuWake(pmmd_b_peuWake);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion113'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq(pmmd_b_pwrHoldReq);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion114'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_startReq(pmmd_b_startReq);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion115'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_vcuAwb(pmmd_b_vcuAwb);

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion116'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_stayAwkReason(pmmd_st_stayAwkReason);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion118'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_vcuWkUpReason(pmmd_st_vcuWkUpReason);

  /* Outport generated from: '<Root>/Out Bus Element9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion119'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmSts(pmmd_b_nmSts);

  /* Outport generated from: '<Root>/Out Bus Element10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion121'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_vcuRmr(pmmd_b_vcuRmr);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion122'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_num_vcuAddr
    (swc_VOMM_ARID_DEF.OutportBufferForpmmd_num_vcuAdd);

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion123'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmWkUp(pmmd_b_nmWkUp);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion125'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmRdySlp(pmmd_b_nmRdySlp);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion126'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_ptCanModeReq(pmmd_st_ptCanModeReq);

  /* Outport generated from: '<Root>/Out Bus Element15' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion127'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_bdCanModeReq(pmmd_st_bdCanModeReq);

  /* Outport generated from: '<Root>/Out Bus Element16' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion128'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_e_CanNMSts(pmmd_e_CanNMSts);

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion131'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_vcuPwrActvMod(pmmd_st_vcuPwrActvMod);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion117'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_PTDisabled(vsmd_b_PTDisabled);

  /* Outport generated from: '<Root>/Out Bus Element19' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion124'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_PTEnabled(vsmd_b_PTEnabled);

  /* Outport generated from: '<Root>/Out Bus Element20' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion129'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehRun(vsmd_b_VehRun);

  /* Outport generated from: '<Root>/Out Bus Element21' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion132'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehStrt(vsmd_b_VehStrt);

  /* Outport generated from: '<Root>/Out Bus Element22' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion134'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_StartDemRaw(vsmd_b_StartDemRaw);

  /* Outport generated from: '<Root>/Out Bus Element23' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion135'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehRunRaw(vsmd_b_VehRunRaw);

  /* Outport generated from: '<Root>/Out Bus Element24' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion141'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_vehSportModActv
    (drid_b_vehSportModActv);

  /* Outport generated from: '<Root>/Out Bus Element25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion144'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_veh4WDModActv(drid_b_veh4WDModActv);

  /* Outport generated from: '<Root>/Out Bus Element26' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion148'
   *  Switch: '<S7>/Switch1'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_e_driveDirSel
    (swc_VOMM_ARID_DEF.drid_e_driveDirSel);

  /* Outport generated from: '<Root>/Out Bus Element27' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion151'
   *  Switch: '<S6>/Switch8'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_e_drvrHEVModReq(drid_e_drvrHEVModReq);

  /* Outport generated from: '<Root>/Out Bus Element28' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion153'
   *  Switch: '<S144>/Switch2'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_e_gearLvrPos(drid_e_gearLvrPos);

  /* Outport generated from: '<Root>/Out Bus Element33' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion139'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_hmmd_b_EVModeActive(hmmd_b_EVModeActive);

  /* Outport generated from: '<Root>/Out Bus Element34' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion145'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_hmmd_b_HVBusDischrgComplete
    (hmmd_b_HVBusDischrgComplete);

  /* Outport generated from: '<Root>/Out Bus Element40' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion137'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_e_engStrtTyp
    (swc_VOMM_ConstB.DataTypeConversion137);

  /* Outport generated from: '<Root>/Out Bus Element41' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion138'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_e_engStrtTypSeld
    (swc_VOMM_ConstB.DataTypeConversion138);

  /* Outport generated from: '<Root>/Out Bus Element42' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_strtrRlyDem
    (swc_VOMM_ConstB.DataTypeConversion140);

  /* Outport generated from: '<Root>/Out Bus Element43' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_motStrtDem
    (swc_VOMM_ConstB.DataTypeConversion142);

  /* Outport generated from: '<Root>/Out Bus Element44' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_motStrtEnad
    (swc_VOMM_ConstB.DataTypeConversion143);

  /* Outport generated from: '<Root>/Out Bus Element45' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStartReq
    (swc_VOMM_ConstB.DataTypeConversion146);

  /* Outport generated from: '<Root>/Out Bus Element46' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStopReq
    (swc_VOMM_ConstB.DataTypeConversion147);

  /* Outport generated from: '<Root>/Out Bus Element47' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStrtAbort
    (swc_VOMM_ConstB.DataTypeConversion149);

  /* Outport generated from: '<Root>/Out Bus Element48' */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStrtComplete
    (swc_VOMM_ConstB.DataTypeConversion150);

  /* Outport generated from: '<Root>/Out Bus Element49' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion158'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_hsdFltClear(pmmd_b_hsdFltClear);

  /* Outport generated from: '<Root>/Out Bus Element54' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_st_gearLvrLckInd
    (swcvomm_drid_st_gearLvrLckInd);

  /* Outport generated from: '<Root>/Out Bus Element55' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_gearPosVld(swcvomm_drid_b_gearPosVld);

  /* Outport generated from: '<Root>/Out Bus Element56' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_epbClsdReq(swcvomm_drid_b_epbClsdReq);

  /* Outport generated from: '<Root>/Out Bus Element57' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_vehEcoModActv
    (swcvomm_drid_b_vehEcoModActv);
}

/* Model initialize function */
void swc_VOMM_Init(void)
{
  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/PMM_PowerModeManager'
   */
  swc_V_PMM_PowerModeManager_Init();

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DRI_DriveModesManagment'
   */
  sw_DRI_DriveModesManagment_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* ConstCode for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/HMM_ModeManager'
   */
  swc_VOMM_HMM_ModeManager_Const();

  /* End of ConstCode for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
