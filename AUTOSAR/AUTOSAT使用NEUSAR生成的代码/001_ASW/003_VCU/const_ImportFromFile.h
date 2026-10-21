#ifndef RTW_HEADER_const_ImportFromFile_h_
#define RTW_HEADER_const_ImportFromFile_h_

#include "rtwtypes.h"
#include "Rte_Type.h"
#include "enum_Type.h"  

/* ConstVolatile memory section */
/* Declaration for custom storage class: ConstVolatile */

extern const volatile uint8 CC64[8];
extern const volatile uint8 InitRand[3];
extern const volatile uint8 DISPLAY_DRIVEMODE_4WD;
extern const volatile uint8 DISPLAY_DRIVEMODE_Dft;
extern const volatile uint8 DISPLAY_DRIVEMODE_ECO;
extern const volatile uint8 DISPLAY_DRIVEMODE_EV;
extern const volatile uint8 DISPLAY_DRIVEMODE_HEV;
extern const volatile uint8 DISPLAY_DRIVEMODE_Normal;
extern const volatile uint8 DISPLAY_DRIVEMODE_OFF;
extern const volatile uint8 DISPLAY_DRIVEMODE_SPORT;
extern const volatile uint8 DISPLAY_DRIVEMODE_DRIVE;
extern const volatile uint8 THM_FANREQSTATUS[11];
extern const volatile boolean THM_FANRLY1[4];
extern const volatile boolean THM_FANRLY2[4];
extern const volatile uint8 THM_WTRPMP1REQSTATUS[11];
extern const volatile uint8 THM_WTRPMP2REQSTATUS[11];
extern const volatile boolean THM_WTRPMPRLY1[4];
extern const volatile boolean THM_WTRPMPRLY2[4];
extern const volatile FanStatus ACC_FANSTATUS[4];
extern const volatile FaultStatus ACC_FAULTSTATUS[4];
extern const volatile sint8 BMS_ACTWRKSTS[6];
extern const volatile sint8 BMS_CHGSTS[3];
extern const volatile BrakePedalStatus BRP_BRKSTATUS[4];
extern const volatile DCDCMode DCC_ACTMODE[4];
extern const volatile FaultStatus DCC_FAULTSTATUS[4];
extern const volatile sint8 DCDC_WRKSTS[4];
extern const volatile GearLeverPos DRI_GEARLEVERPOS[5];
extern const volatile GearLeverPos DRI_GEARLEVERPOSLDT[6];
extern const volatile GearLeverPos DRI_GEARLEVERPOSLDTCAN[6];
extern const volatile ElMac EAD1_ACTMODE[8];
extern const volatile FaultStatus EAD1_FAULTSTATUS[5];
extern const volatile FaultStatus EMS_ENGFLTSTS[6];
extern const volatile EngineState ENG_ENGSTATE[8];
extern const volatile FanStatus ENG_FANREQ[4];
extern const volatile ParkingStatus EPB_PARKSTATUS[6];
extern const volatile HVBattStatus HVB_BMSSTATUS[16] ;/* Referenced by: '<S16>/Constant' */
extern const volatile InsulationStatus HVB_INSLSTATUS[6];/* Referenced by: '<S16>/Constant4' */
extern const volatile HVBRelayStatus HVB_RLYSTATUS[4];
extern const volatile boolean MAC_THREEWAYVLVOPSTATUS[5];              
extern const volatile boolean MAC_TWOWAYVLVOPSTATUS[4];/* Referenced by: '<S18>/Constant7' */
extern const volatile McuSts MCU_STATUS[4];    
extern const volatile FaultStatus OBC_FAULTSTATUS[4];
extern const volatile PDULevel PDU_LEVEL[5];  /* Referenced by: '<S315>/Constant3' */
extern const volatile ElMac TMM_ACTMODE[7];                      /* Referenced by: '<S22>/Constant' */
extern const volatile FaultStatus TMM_FAULTSTATUS[7];/* Referenced by: '<S22>/Constant3' */
extern const volatile ClutchState TRA_ENGCLTHSTS[4];/* Referenced by: '<S350>/Constant9' */
extern const volatile ClutchState TRA_TRSM1CLTHSTS[3];/* Referenced by: '<S350>/Constant22' */
extern const volatile FanStatus TRA_TRSM1FANREQ[4];/* Referenced by: '<S346>/Constant13' */
extern const volatile FaultStatus TRA_TRSM1FLTSTS[4];/* Referenced by: '<S23>/Constant' */
extern const volatile sint8 TRA_TRSM1GEARSTS[15];                                                   
extern const volatile ParkingStatus TRA_TRSM1PRKGSTS[6];/* Referenced by: '<S350>/Constant3' */
extern const volatile ShiftType TRA_TRSM1SHIFTMODE[4];/* Referenced by: '<S348>/Constant16' */
extern const volatile FaultStatus TRA_TRSM2FLTSTS[4];/* Referenced by: '<S24>/Constant' */
extern const volatile sint8 TRA_TRSM2GEARSTS[16];                      /* Referenced by: '<S369>/Constant1' */
extern const volatile uint8 DCC_REQMODE[8];/* Referenced by: '<S6>/Constant1' */
extern const volatile uint8 DISPLAY_DRIVEMODE_ECO;/* Referenced by: '<S28>/Constant11' */
extern const volatile uint8 EAD2_REQMODE[11];                               /* Referenced by: '<S9>/Constant' */
extern const volatile uint8 ENG_ENGSTATE_CANOUT[9];                               /* Referenced by: '<S10>/Constant1' */
extern const volatile uint8 ENG_MODEREQ[3];/* Referenced by: '<S107>/Constant1' */
extern const volatile uint8 ENG_STARTTYPE[5];/* Referenced by: '<S10>/Constant3' */
extern const volatile uint8 EPB_PARKSTS[6];/* Referenced by: '<S11>/Constant' */
extern const volatile uint8 TRA_ENGCLTHSTSTGT[5];/* Referenced by: '<S221>/Constant' */
extern const volatile uint8 TRA_TRSM1HEVMODE[7];/* Referenced by: '<S220>/Constant' */
extern const volatile uint8 TRA_TRSM2SHFTRESPSTS[3];/* Referenced by: '<S19>/Constant' */


#endif