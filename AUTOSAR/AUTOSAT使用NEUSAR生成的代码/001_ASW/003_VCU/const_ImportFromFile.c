
#include "const_ImportFromFile.h"



/* ConstVolatile memory section */
/* Definition for custom storage class: ConstVolatile */
const volatile uint8 CC64[8] = { 148U, 37U, 69U, 71U, 70U, 74U, 91U, 125U } ;/* Referenced by:
                                                                      * '<S4>/CC64'
                                                                      * '<S4>/CC64_1'
                                                                      */

const volatile uint8 InitRand[3] = { 148U, 37U, 69U } ;/* Referenced by: '<S3>/Fix_Rdn' */

const volatile uint8 DISPLAY_DRIVEMODE_4WD = 4U;/* Referenced by: '<S12>/Constant6' */
const volatile uint8 DISPLAY_DRIVEMODE_Dft = 3U;/* Referenced by: '<S12>/Constant13' */
const volatile uint8 DISPLAY_DRIVEMODE_ECO = 1U;/* Referenced by: '<S12>/Constant11' */
const volatile uint8 DISPLAY_DRIVEMODE_EV = 1U;/* Referenced by:
                                                * '<S2>/dspd_st_vehDrvMode'
                                                * '<S92>/Constant10'
                                                */
const volatile uint8 DISPLAY_DRIVEMODE_HEV = 2U;/* Referenced by:
                                                 * '<S85>/Constant'
                                                 * '<S92>/Constant16'
                                                 */
const volatile uint8 DISPLAY_DRIVEMODE_Normal = 0U;/* Referenced by: '<S12>/Constant12' */
const volatile uint8 DISPLAY_DRIVEMODE_OFF = 0U;/* Referenced by: '<S12>/Constant8' */
const volatile uint8 DISPLAY_DRIVEMODE_SPORT = 2U;/* Referenced by: '<S12>/Constant2' */
const volatile uint8 DISPLAY_DRIVEMODE_DRIVE = 0U;

const volatile uint8 THM_FANREQSTATUS[11] = { 0U, 1U, 2U, 3U, 0U, 0U, 0U, 0U, 0U,
  0U, 3U } ;                           /* Referenced by: '<S109>/Constant' */

const volatile boolean THM_FANRLY1[4] = { false, true, false, false } ;/* Referenced by: '<S106>/Constant' */

const volatile boolean THM_FANRLY2[4] = { false, false, true, true } ;/* Referenced by: '<S106>/Constant2' */

const volatile uint8 THM_WTRPMP1REQSTATUS[11] = { 0U, 1U, 2U, 3U, 0U, 0U, 0U, 0U,
  0U, 0U, 3U } ;                       /* Referenced by: '<S178>/Constant' */

const volatile uint8 THM_WTRPMP2REQSTATUS[11] = { 0U, 1U, 2U, 3U, 0U, 0U, 0U, 0U,
  0U, 0U, 3U } ;                       /* Referenced by: '<S178>/Constant1' */

const volatile boolean THM_WTRPMPRLY1[4] = { false, true, true, true } ;/* Referenced by: '<S177>/Constant' */

const volatile boolean THM_WTRPMPRLY2[4] = { false, true, true, true } ;/* Referenced by: '<S177>/Constant2' */



const volatile FanStatus ACC_FANSTATUS[4] = { FanStatus_OFF, FanStatus_LOW_SPEED,
  FanStatus_HIGH_SPEED, FanStatus_OFF };/* Referenced by: '<S4>/Constant' */

const volatile FaultStatus ACC_FAULTSTATUS[4] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3 };/* Referenced by:
                                                                   * '<S4>/Constant12'
                                                                   * '<S4>/Constant2'
                                                                   * '<S4>/Constant6'
                                                                   * '<S4>/Constant8'
                                                                   */

const volatile sint8 BMS_ACTWRKSTS[6] = { 4, 2, 2, 3, 5, 0 } ;/* Referenced by: '<S1042>/Constant4' */

const volatile sint8 BMS_CHGSTS[3] = { 0, 1, 2 } ;/* Referenced by: '<S1042>/Constant8' */

const volatile BrakePedalStatus BRP_BRKSTATUS[4] = {
  BrakePedalStatus_NOT_PRESSED, BrakePedalStatus_PRESSED,
  BrakePedalStatus_INVALID, BrakePedalStatus_INVALID };/* Referenced by: '<S99>/Constant2' */

const volatile DCDCMode DCC_ACTMODE[4] = { DCDCMode_SHUTDOWN, DCDCMode_ACTIVE,
  DCDCMode_FAILURE, DCDCMode_INVALID };/* Referenced by: '<S121>/Constant' */

const volatile FaultStatus DCC_FAULTSTATUS[4] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3 };/* Referenced by: '<S10>/Constant2' */

const volatile sint8 DCDC_WRKSTS[4] = { 0, 1, 1, 1 } ;/* Referenced by: '<S788>/Constant8' */

const volatile GearLeverPos DRI_GEARLEVERPOS[5] = { GearLeverPos_NEUTRAL,
  GearLeverPos_FWD_DRIVE, GearLeverPos_SPT_DRIVE, GearLeverPos_REV_DRIVE,
  GearLeverPos_UNKNOWN };              /* Referenced by: '<S11>/Constant3' */

const volatile GearLeverPos DRI_GEARLEVERPOSLDT[6] = { GearLeverPos_NEUTRAL,
  GearLeverPos_FWD_DRIVE, GearLeverPos_SPT_DRIVE, GearLeverPos_REV_DRIVE,
  GearLeverPos_NEUTRAL, GearLeverPos_UNKNOWN };/* Referenced by: '<S11>/Constant4' */

const volatile GearLeverPos DRI_GEARLEVERPOSLDTCAN[6] = { GearLeverPos_NEUTRAL,
  GearLeverPos_FWD_DRIVE, GearLeverPos_SPT_DRIVE, GearLeverPos_REV_DRIVE,
  GearLeverPos_NEUTRAL, GearLeverPos_UNKNOWN };/* Referenced by: '<S11>/Constant6' */

const volatile ElMac EAD1_ACTMODE[8] = { ElMac_HV_OFF, ElMac_STANDBY,
  ElMac_TORQUE_CTRL, ElMac_SPEED_CTRL, ElMac_VOLTAGE_CTRL, ElMac_PRECHARGE,
  ElMac_SHUTDOWN, ElMac_FAILURE };     /* Referenced by: '<S13>/Constant' */

const volatile FaultStatus EAD1_FAULTSTATUS[5] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3,
  FaultStatus_INVALID };               /* Referenced by:
                                        * '<S13>/Constant3'
                                        * '<S13>/Constant7'
                                        */

const volatile FaultStatus EMS_ENGFLTSTS[6] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3,
  FaultStatus_LEVEL_4, FaultStatus_INVALID };/* Referenced by: '<S202>/Constant3' */

const volatile EngineState ENG_ENGSTATE[8] = { EngineState_OFF, EngineState_OFF,
  EngineState_CRANKING, EngineState_RUNNING, EngineState_STOPPING,
  EngineState_OFF, EngineState_OFF, EngineState_INVALID };/* Referenced by: '<S202>/Constant' */

const volatile FanStatus ENG_FANREQ[4] = { FanStatus_OFF, FanStatus_LOW_SPEED,
  FanStatus_HIGH_SPEED, FanStatus_INVALID };/* Referenced by: '<S203>/Constant3' */

const volatile ParkingStatus EPB_PARKSTATUS[6] = { ParkingStatus_DISENGAGED,
  ParkingStatus_ENGAGED, ParkingStatus_INPROGRESS, ParkingStatus_DEFAULTVALUE,
  ParkingStatus_ERROR, ParkingStatus_INVALID };/* Referenced by: '<S15>/Constant' */

const volatile HVBattStatus HVB_BMSSTATUS[16] = { HVBattStatus_STANDBY,
  HVBattStatus_PREPARATION, HVBattStatus_STANDBY, HVBattStatus_PRECHARGE,
  HVBattStatus_ACTIVE, HVBattStatus_SLOW_CHARGE, HVBattStatus_STANDBY,
  HVBattStatus_STANDBY, HVBattStatus_FAST_CHARGE, HVBattStatus_HEATING,
  HVBattStatus_STANDBY, HVBattStatus_SHUTDOWN, HVBattStatus_STANDBY,
  HVBattStatus_CHARGE_COMPLETE, HVBattStatus_STANDBY, HVBattStatus_INVALID };/* Referenced by: '<S16>/Constant' */

const volatile InsulationStatus HVB_INSLSTATUS[6] = { InsulationStatus_OK,
  InsulationStatus_LOW, InsulationStatus_LOW, InsulationStatus_CRITICAL,
  InsulationStatus_CRITICAL, InsulationStatus_INVALID };/* Referenced by: '<S16>/Constant4' */

const volatile HVBRelayStatus HVB_RLYSTATUS[4] = { HVBRelayStatus_RESERVED,
  HVBRelayStatus_OPEN, HVBRelayStatus_CLOSED, HVBRelayStatus_INVALID };/* Referenced by:
                                                                      * '<S16>/Constant12'
                                                                      * '<S16>/Constant14'
                                                                      * '<S16>/Constant16'
                                                                      * '<S16>/Constant9'
                                                                      */

const volatile boolean MAC_THREEWAYVLVOPSTATUS[5] = { false, true, true, false,
  false } ;                            /* Referenced by: '<S18>/Constant9' */

const volatile boolean MAC_TWOWAYVLVOPSTATUS[4] = { false, true, false, false } ;/* Referenced by: '<S18>/Constant7' */

const volatile McuSts MCU_STATUS[4] = { McuSts_NOTREADY, McuSts_READY,
  McuSts_ERROR, McuSts_RESERVED };     /* Referenced by:
                                        * '<S4>/Constant16'
                                        * '<S4>/Constant5'
                                        * '<S7>/Constant16'
                                        * '<S10>/Constant16'
                                        * '<S13>/Constant16'
                                        * '<S16>/Constant20'
                                        * '<S18>/Constant16'
                                        */

const volatile FaultStatus OBC_FAULTSTATUS[4] = { FaultStatus_NO_FAULT,
   FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3 };/* Referenced by: '<S20>/Constant' */

const volatile PDULevel PDU_LEVEL[5] = { PDULevel_OFF, PDULevel_ACC, PDULevel_ON,
  PDULevel_INVALID, PDULevel_START };  /* Referenced by: '<S315>/Constant3' */

const volatile ElMac TMM_ACTMODE[7] = { ElMac_HV_OFF, ElMac_STANDBY,
  ElMac_TORQUE_CTRL, ElMac_SPEED_CTRL, ElMac_STANDBY, ElMac_INVALID,
  ElMac_HV_OFF };                      /* Referenced by: '<S22>/Constant' */

const volatile FaultStatus TMM_FAULTSTATUS[7] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_NO_FAULT, FaultStatus_NO_FAULT,
  FaultStatus_NO_FAULT, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3 };/* Referenced by: '<S22>/Constant3' */

const volatile ClutchState TRA_ENGCLTHSTS[4] = { ClutchState_OPEN,
  ClutchState_CLOSED, ClutchState_SLIPPING, ClutchState_CLOSED };/* Referenced by: '<S350>/Constant9' */

const volatile ClutchState TRA_TRSM1CLTHSTS[3] = { ClutchState_OPEN,
  ClutchState_CLOSED, ClutchState_SLIPPING };/* Referenced by: '<S350>/Constant22' */

const volatile FanStatus TRA_TRSM1FANREQ[4] = { FanStatus_OFF,
  FanStatus_LOW_SPEED, FanStatus_HIGH_SPEED, FanStatus_INVALID };/* Referenced by: '<S346>/Constant13' */

const volatile FaultStatus TRA_TRSM1FLTSTS[4] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_INVALID };/* Referenced by: '<S23>/Constant' */

const volatile sint8 TRA_TRSM1GEARSTS[15] = { -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8,
  9, 10, 11, 12 } ;                    /* Referenced by:
                                        * '<S350>/Constant1'
                                        * '<S350>/Constant4'
                                        */

const volatile ParkingStatus TRA_TRSM1PRKGSTS[6] = { ParkingStatus_DISENGAGED,
  ParkingStatus_DISENGAGED, ParkingStatus_ENGAGED, ParkingStatus_DISENGAGED,
  ParkingStatus_DISENGAGED, ParkingStatus_ERROR };/* Referenced by: '<S350>/Constant3' */

const volatile ShiftType TRA_TRSM1SHIFTMODE[4] = { ShiftType_NO_SHIFT,
  ShiftType_SHIFT_SPD_CTRL, ShiftType_SHIFT_TRQ_CTRL, ShiftType_NO_SHIFT };/* Referenced by: '<S348>/Constant16' */

const volatile FaultStatus TRA_TRSM2FLTSTS[4] = { FaultStatus_NO_FAULT,
  FaultStatus_LEVEL_1, FaultStatus_LEVEL_2, FaultStatus_LEVEL_3 };/* Referenced by: '<S24>/Constant' */

const volatile sint8 TRA_TRSM2GEARSTS[16] = { 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, -1, 0, 0 } ;                      /* Referenced by: '<S369>/Constant1' */

const volatile float32 TRA_TRSM2_TASK_INTERVAL_S = 0.01F;/* Referenced by: '<S367>/Constant3' */


const volatile uint8 DCC_REQMODE[8] = { 0U, 0U, 1U, 2U, 0U, 0U, 0U, 3U } ;/* Referenced by: '<S6>/Constant1' */

//onst volatile uint8 DISPLAY_DRIVEMODE_ECO = 1U;/* Referenced by: '<S28>/Constant11' */
const volatile uint8 EAD2_REQMODE[11] = { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 0U, 7U, 0U,
  0U } ;                               /* Referenced by: '<S9>/Constant' */

const volatile uint8 ENG_ENGSTATE_CANOUT[9] = { 0U, 2U, 1U, 0U, 0U, 0U, 0U, 0U,
  3U } ;                               /* Referenced by: '<S10>/Constant1' */

const volatile uint8 ENG_MODEREQ[3] = { 0U, 1U, 2U } ;/* Referenced by: '<S107>/Constant1' */

const volatile uint8 ENG_STARTTYPE[5] = { 0U, 1U, 2U, 0U, 0U } ;/* Referenced by: '<S10>/Constant3' */

const volatile uint8 EPB_PARKSTS[6] = { 0U, 1U, 2U, 3U, 0U, 0U } ;/* Referenced by: '<S11>/Constant' */

const volatile uint8 TRA_ENGCLTHSTSTGT[5] = { 1U, 3U, 2U, 0U, 0U } ;/* Referenced by: '<S221>/Constant' */

const volatile uint8 TRA_TRSM1HEVMODE[7] = { 0U, 3U, 1U, 2U, 6U, 5U, 7U } ;/* Referenced by: '<S220>/Constant' */

const volatile uint8 TRA_TRSM2SHFTRESPSTS[3] = { 0U, 1U, 3U } ;/* Referenced by: '<S19>/Constant' */


    