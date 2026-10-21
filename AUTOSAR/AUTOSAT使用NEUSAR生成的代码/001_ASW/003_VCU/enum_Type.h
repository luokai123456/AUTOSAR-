/********************************************************************************/
/* FILE INFORMATION:                                                            */
/*                                                                              */
/* Filename:           enum_Type.h                                              */
/*                                                                              */
/* MODEL INFORMATION:                                                           */
/* Model Name:         vcu_arch                                                 */
/* Model Description:                                                           */
/* Determine the preconditions for moving around the driving mode state machine */
/*                                                                              */
/* pmmd_flg_set_drive and pmmd_flg_set_charging are each the conditions for     */
/* entering their respective modes.                                             */
/*                                                                              */
/* pmmd_flg_req_drive and pmmd_flg_req_charging are the conditions for          */
/* remaining in those modes, but not strong enough themselves to enter the      */
/* modes                                                                        */
/* Determine whether there is a request for charging mode.                      */
/*                                                                              */
/* A prerequisite is that the OBC detects a charger is plugged in, but there    */
/* may be other conditions.                                                     */
/*                                                                              */
/* We don't consider the HVBatt status == Charge End here, because that is      */
/* about whether charging is performed, rather than whether the charger         */
/* is detected to be present.                                                   */
/*                                                                              */
/* The power-hold is determined separately using the raw OBC signals, as these  */
/* have distinct timings and do not incorporate the OBC feature's other         */
/* plausibility checks.                                                         */
/*                                                                              */
/* The customer request was that the power-hold lasts 180s after the network    */
/* signal goes to OFF, so a slightly shorter power-hold time is applied to the  */
/* hardware input, enabling this behaviour in the situation where the OBC       */
/* behaves as expected                                                          */
/* Determine whether there is a request from the "driver" for drive mode.       */
/*                                                                              */
/* Precondition is that the ignition is on, and other conditions which would    */
/* prevent driving are false                                                    */
/*                                                                              */
/* Code generated on:  Mon Oct 29 17:02:02 2018                                 */
/*                                                                              */
/* MODIFICATION HISTORY:                                                        */
/********************************************************************************/

#ifndef RTW_HEADER_enum_Type_h_
#define RTW_HEADER_enum_Type_h_
#include "rtwtypes.h"

typedef uint8_T ElMac;

/* enum ElMac */
#define ElMac_HV_OFF                   ((ElMac)0U)
#define ElMac_STANDBY                  ((ElMac)1U)
#define ElMac_TORQUE_CTRL              ((ElMac)2U)
#define ElMac_SPEED_CTRL               ((ElMac)3U)
#define ElMac_VOLTAGE_CTRL             ((ElMac)4U)
#define ElMac_PRECHARGE                ((ElMac)5U)  /* %VE21 ADD 20230802*/
#define ElMac_SHUTDOWN                 ((ElMac)6U)
#define ElMac_FAILURE                  ((ElMac)7U)
#define ElMac_HV_ACTIVE_DISCHARGE      ((ElMac)8U)
#define ElMac_HV_PASSIVE_DISCHARGE     ((ElMac)9U)
#define ElMac_INVALID                  ((ElMac)10U)


/* This defines an enumerated type for CAN message count states */
typedef uint8_T CanDataStatus;

/* enum CanDataStatus */
#define CanDataStatus_New              ((CanDataStatus)0U)
#define CanDataStatus_Held             ((CanDataStatus)1U)
#define CanDataStatus_Default          ((CanDataStatus)2U)

typedef uint8_T FanStatus;

/* enum FanStatus */
#define FanStatus_OFF                  ((FanStatus)0U)
#define FanStatus_LOW_SPEED            ((FanStatus)1U)
#define FanStatus_MEDIUM_SPEED         ((FanStatus)2U)
#define FanStatus_HIGH_SPEED           ((FanStatus)3U)
#define FanStatus_FAILURE              ((FanStatus)5U)
#define FanStatus_INVALID              ((FanStatus)10U)

/* This defines an enumerated type for clutch states */
typedef uint8_T KeyAuthStatus;

/* enum KeyAuthStatus */
#define KeyAuthStatus_DEFAULT          ((KeyAuthStatus)0U)
#define KeyAuthStatus_SUCCESS          ((KeyAuthStatus)1U)
#define KeyAuthStatus_FAIL             ((KeyAuthStatus)2U)

typedef uint8_T HVBRelayStatus;

/* enum HVBRelayStatus */

 
#define HVBRelayStatus_RESERVED        ((HVBRelayStatus)0U)
#define HVBRelayStatus_OPEN            ((HVBRelayStatus)1U)
#define HVBRelayStatus_CLOSED          ((HVBRelayStatus)2U)
#define HVBRelayStatus_INVALID         ((HVBRelayStatus)3U) /* %VE21 Changed 20230802*/


/* 
#define HVBRelayStatus_INIT            ((HVBRelayStatus)0U)
#define HVBRelayStatus_OPEN            ((HVBRelayStatus)1U)
#define HVBRelayStatus_ClOSED          ((HVBRelayStatus)2U)
#define HVBRelayStatus_ADHESION        ((HVBRelayStatus)3U)
*/

typedef uint8_T DCDCMode;

/* enum DCDCMode */
#define DCDCMode_HV_OFF                ((DCDCMode)0U)
#define DCDCMode_STANDBY               ((DCDCMode)1U)
#define DCDCMode_ACTIVE                ((DCDCMode)2U)
#define DCDCMode_FAILURE               ((DCDCMode)5U)
#define DCDCMode_SHUTDOWN              ((DCDCMode)7U)
#define DCDCMode_HV_ACTIVE_DISCHARGE   ((DCDCMode)8U)
#define DCDCMode_HV_PASSIVE_DISCHARGE  ((DCDCMode)9U)
#define DCDCMode_INVALID               ((DCDCMode)10U)

typedef uint8_T DriveDir;

/* enum DriveDir */
#define DriveDir_NO_DRIVE              ((DriveDir)0U)
#define DriveDir_FORWARD               ((DriveDir)1U)
#define DriveDir_REVERSE               ((DriveDir)2U)
#define DriveDir_INVALID               ((DriveDir)3U)

/* This defines an enumerated type for BMS state in the hvBatt */
typedef uint8_T HVBattStatus;

/* enum HVBattStatus */
#define HVBattStatus_STANDBY           ((HVBattStatus)0U)
#define HVBattStatus_PREPARATION       ((HVBattStatus)1U)
#define HVBattStatus_PRECHARGE         ((HVBattStatus)2U)
#define HVBattStatus_ACTIVE            ((HVBattStatus)3U)
#define HVBattStatus_CHARGE_OFF        ((HVBattStatus)4U)
#define HVBattStatus_CHARGING          ((HVBattStatus)5U)
#define HVBattStatus_CHARGE_COMPLETE   ((HVBattStatus)6U)
#define HVBattStatus_HEATING           ((HVBattStatus)7U)
#define HVBattStatus_FAILURE           ((HVBattStatus)8U)
#define HVBattStatus_SHUTDOWN          ((HVBattStatus)9U)
#define HVBattStatus_INVALID           ((HVBattStatus)10U)
#define HVBattStatus_SLOW_CHARGE       ((HVBattStatus)11U)   /* %VE21 Changed 20240103*/
#define HVBattStatus_FAST_CHARGE       ((HVBattStatus)12U)   /* %VE21 Changed 20240103*/

/* This defines an enumerated type for hybrid mode manager states */
typedef uint8_T HybModeMngr;

/* enum HybModeMngr */
#define HybModeMngr_PT_OFF             ((HybModeMngr)0U)
#define HybModeMngr_PT_ENA             ((HybModeMngr)1U)
#define HybModeMngr_ICE_MODE           ((HybModeMngr)2U)
#define HybModeMngr_PHEV_MODE          ((HybModeMngr)3U)
#define HybModeMngr_SHEV_MODE          ((HybModeMngr)4U)
#define HybModeMngr_EV_MODE            ((HybModeMngr)5U)
#define HybModeMngr_SHUTDOWN           ((HybModeMngr)9U)
#define HybModeMngr_PTENA2ICE          ((HybModeMngr)12U)
#define HybModeMngr_PTENA2PHEV         ((HybModeMngr)13U)
#define HybModeMngr_PTENA2SHEV         ((HybModeMngr)14U)
#define HybModeMngr_PTENA2EV           ((HybModeMngr)15U)
#define HybModeMngr_ICE2PTENA          ((HybModeMngr)21U)
#define HybModeMngr_ICE2PHEV           ((HybModeMngr)23U)
#define HybModeMngr_PHEV2PTENA         ((HybModeMngr)31U)
#define HybModeMngr_PHEV2ICE           ((HybModeMngr)32U)
#define HybModeMngr_PHEV2SHEV          ((HybModeMngr)34U)
#define HybModeMngr_PHEV2EV            ((HybModeMngr)35U)
#define HybModeMngr_SHEV2PTENA         ((HybModeMngr)41U)
#define HybModeMngr_SHEV2PHEV          ((HybModeMngr)43U)
#define HybModeMngr_SHEV2EV            ((HybModeMngr)45U)
#define HybModeMngr_EV2PTENA           ((HybModeMngr)51U)
#define HybModeMngr_EV2PHEV            ((HybModeMngr)53U)
#define HybModeMngr_EV2SHEV            ((HybModeMngr)54U)

typedef uint8_T FaultStatus;

/* enum FaultStatus */
#define FaultStatus_NO_FAULT           ((FaultStatus)0U)
#define FaultStatus_LEVEL_1            ((FaultStatus)1U)
#define FaultStatus_LEVEL_2            ((FaultStatus)2U)
#define FaultStatus_LEVEL_3            ((FaultStatus)3U)
#define FaultStatus_LEVEL_4            ((FaultStatus)4U)
#define FaultStatus_LEVEL_5            ((FaultStatus)5U)
#define FaultStatus_INVALID            ((FaultStatus)9U)

typedef uint8_T BrakePedalStatus;

/* enum BrakePedalStatus */
#define BrakePedalStatus_NOT_PRESSED   ((BrakePedalStatus)0U)
#define BrakePedalStatus_PRESSED       ((BrakePedalStatus)1U)
#define BrakePedalStatus_INVALID       ((BrakePedalStatus)2U)

/* This defines an enumerated type for transmission states */
typedef uint8_T GearLeverPos;

/* enum GearLeverPos */
#define GearLeverPos_PARKING           ((GearLeverPos)0U)
#define GearLeverPos_NEUTRAL           ((GearLeverPos)1U)
#define GearLeverPos_REV_DRIVE         ((GearLeverPos)2U)
#define GearLeverPos_FWD_DRIVE         ((GearLeverPos)3U)
#define GearLeverPos_SPT_DRIVE         ((GearLeverPos)4U)
#define GearLeverPos_FAILURE           ((GearLeverPos)5U)
#define GearLeverPos_INVALID           ((GearLeverPos)6U)
#define GearLeverPos_UNKNOWN           ((GearLeverPos)9U)

/* This defines an enumerated type for Engine running status */
typedef uint8_T EngineState;

/* enum EngineState */
#define EngineState_OFF                ((EngineState)0U)
#define EngineState_RUNNING            ((EngineState)1U)
#define EngineState_CRANKING           ((EngineState)2U)
#define EngineState_STOPPING           ((EngineState)3U)
#define EngineState_RECOVERY           ((EngineState)4U)
#define EngineState_STALLED            ((EngineState)5U)
#define EngineState_CRANK_FAILED       ((EngineState)6U)
#define EngineState_FAILURE            ((EngineState)7U)
#define EngineState_INVALID            ((EngineState)8U)

typedef uint8_T ParkingStatus;

/* enum ParkingStatus */
#define ParkingStatus_DISENGAGED       ((ParkingStatus)0U)
#define ParkingStatus_ENGAGED          ((ParkingStatus)1U)
#define ParkingStatus_INPROGRESS       ((ParkingStatus)2U)      /* %VE21 ADD 20230808*/
#define ParkingStatus_DEFAULTVALUE     ((ParkingStatus)3U)		/* %VE21 ADD 20230808*/
#define ParkingStatus_ERROR            ((ParkingStatus)4U)   
#define ParkingStatus_INVALID          ((ParkingStatus)5U)

typedef uint8_T ValueTol;

/* enum ValueTol */
#define ValueTol_WITHIN_TOL            ((ValueTol)0U)
#define ValueTol_BELOW_TOL             ((ValueTol)1U)
#define ValueTol_ABOVE_TOL             ((ValueTol)2U)

/* Power flow directions in vehicle */
typedef uint8_T PowerFlowMode;

/* enum PowerFlowMode */
#define PowerFlowMode_OFF              ((PowerFlowMode)0U)
#define PowerFlowMode_EV               ((PowerFlowMode)1U)
#define PowerFlowMode_ICE_MSG          ((PowerFlowMode)2U)
#define PowerFlowMode_PHEV             ((PowerFlowMode)3U)
#define PowerFlowMode_REGEN            ((PowerFlowMode)4U)
#define PowerFlowMode_SERIES           ((PowerFlowMode)5U)
#define PowerFlowMode_PARK_GEN         ((PowerFlowMode)6U)
#define PowerFlowMode_DRIVE_GEN        ((PowerFlowMode)7U)

typedef uint8_T InsulationStatus;

/* enum InsulationStatus */
#define InsulationStatus_OK            ((InsulationStatus)0U)
#define InsulationStatus_LOW           ((InsulationStatus)1U)
#define InsulationStatus_CRITICAL      ((InsulationStatus)2U)
#define InsulationStatus_INVALID       ((InsulationStatus)3U)

/* This defines an enumerated type for clutch states */
typedef uint8_T PDULevel;

/* enum PDULevel */
#define PDULevel_OFF                   ((PDULevel)0U)
#define PDULevel_ACC                   ((PDULevel)1U)
#define PDULevel_ON                    ((PDULevel)2U)
#define PDULevel_START                 ((PDULevel)3U)
#define PDULevel_INVALID               ((PDULevel)9U)

typedef uint8_T ShiftType;

/* enum ShiftType */
#define ShiftType_NO_SHIFT             ((ShiftType)0U)
#define ShiftType_SHIFT_TRQ_INC        ((ShiftType)1U)
#define ShiftType_SHIFT_TRQ_DEC        ((ShiftType)2U)
#define ShiftType_SHIFT_TRQ_CTRL       ((ShiftType)3U)
#define ShiftType_SHIFT_SPD_CTRL       ((ShiftType)4U)
#define ShiftType_SHIFT_SPD_CTRL_HCU   ((ShiftType)5U)

/* This defines an enumerated type for clutch states */
typedef uint8_T ClutchState;

/* enum ClutchState */
#define ClutchState_OPEN               ((ClutchState)0U)
#define ClutchState_SLIPPING           ((ClutchState)1U)
#define ClutchState_CLOSED             ((ClutchState)2U)
#define ClutchState_FAILURE            ((ClutchState)3U)
#define ClutchState_INVALID            ((ClutchState)4U)

/* This defines an enumerated type for Engine start type */
typedef uint8_T EngStartType;

/* enum EngStartType */
#define EngStartType_NO_START_REQ      ((EngStartType)0U)
#define EngStartType_STARTER_START     ((EngStartType)1U)
#define EngStartType_MOTOR_START       ((EngStartType)2U)
#define EngStartType_MOTOR_RECOVERY    ((EngStartType)3U)
#define EngStartType_ENGINE_RECOVERY   ((EngStartType)4U)
#define EngStartType_CLUTCH_SLIP_START ((EngStartType)5U)

/* This defines an enumerated type for Engine start type */
typedef uint8_T EngineMode;

/* enum EngineMode */
#define EngineMode_STANDBY             ((EngineMode)0U)
#define EngineMode_TORQUE_MODE         ((EngineMode)1U)
#define EngineMode_SPEED_MODE          ((EngineMode)2U)

/* This defines an enumerated type for HEV mode transitions */
typedef uint8_T HEVMode;

/* enum HEVMode */
#define HEVMode_OFF                    ((HEVMode)0U)
#define HEVMode_HEV                    ((HEVMode)1U)
#define HEVMode_EV                     ((HEVMode)2U)
#define HEVMode_SERIES                 ((HEVMode)3U)
#define HEVMode_HEV2EV                 ((HEVMode)4U)
#define HEVMode_EV2HEV                 ((HEVMode)5U)
#define HEVMode_HEV2SERIES             ((HEVMode)6U)

typedef uint8_T HVACStatus;

/* enum HVACStatus */
#define HVACStatus_HV_OFF              ((HVACStatus)0U)
#define HVACStatus_STANDBY             ((HVACStatus)1U)
#define HVACStatus_ACTIVE              ((HVACStatus)2U)
#define HVACStatus_CHARGER_COOLING     ((HVACStatus)3U)
#define HVACStatus_CHARGER_HEATING     ((HVACStatus)4U)

/* This defines an enumerated type for HEV modes */
typedef uint8_T HEVModeReq;

/* enum HEVModeReq */
#define HEVModeReq_OFF                 ((HEVModeReq)0U)
#define HEVModeReq_ICE                 ((HEVModeReq)1U)
#define HEVModeReq_PHEV                ((HEVModeReq)2U)
#define HEVModeReq_SHEV                ((HEVModeReq)3U)
#define HEVModeReq_EV                  ((HEVModeReq)4U)
#define HEVModeReq_AUTO                ((HEVModeReq)5U)

/* Choice of strategy for ICU mode lamps */
typedef uint8_T DisplayLampMode;

/* enum DisplayLampMode */
#define DisplayLampMode_ButtonState    ((DisplayLampMode)0U)
#define DisplayLampMode_ActiveMode     ((DisplayLampMode)1U)
#define DisplayLampMode_DriverRequest  ((DisplayLampMode)2U)
#define DisplayLampMode_DriverMode     ((DisplayLampMode)3U)

/* This defines an enumerated type for charger states */
typedef uint8_T ChargerStatus;

/* enum ChargerStatus */
#define ChargerStatus_UNKNOWN          ((ChargerStatus)0U)
#define ChargerStatus_CONFIRMED_PLUGGED ((ChargerStatus)1U)
#define ChargerStatus_CONFIRMED_UNPLUGGED ((ChargerStatus)2U)
#define ChargerStatus_SUSPECT_PLUGGED  ((ChargerStatus)3U)
#define ChargerStatus_SUSPECT_UNPLUGGED ((ChargerStatus)4U)

typedef uint8_T CruiseControl;

/* enum CruiseControl */
#define CruiseControl_NO_REQUEST       ((CruiseControl)0U)
#define CruiseControl_REQ_HONORED      ((CruiseControl)1U)
#define CruiseControl_LOST_ARBITRATION ((CruiseControl)2U)
#define CruiseControl_REQ_DENIED       ((CruiseControl)3U)
#define CruiseControl_REQ_SUSPENDED    ((CruiseControl)4U)
#define CruiseControl_REQ_NOT_LIM      ((CruiseControl)5U)
#define CruiseControl_REQ_LIM_MIN      ((CruiseControl)6U)
#define CruiseControl_REQ_LIM_MAX      ((CruiseControl)7U)

typedef uint8_T PmmMode;

/* enum PmmMode */
#define PmmMode_INACTIVEDRIVE          ((PmmMode)0U)
#define PmmMode_DRIVE                  ((PmmMode)1U)
#define PmmMode_CHARGE                 ((PmmMode)2U)
#define PmmMode_DRIVEINHIBIT           ((PmmMode)3U)
#define PmmMode_AFTERRUN               ((PmmMode)4U)
#define PmmMode_SHUTDOWNWAIT           ((PmmMode)5U)
#define PmmMode_SHUTDOWN               ((PmmMode)6U)

/* This defines an enumerated type for hybrid mode manager states */
typedef uint8_T FiltTrqRange;

/* enum FiltTrqRange */
#define FiltTrqRange_FILTER_OFF        ((FiltTrqRange)0U)
#define FiltTrqRange_BRAKING_POS       ((FiltTrqRange)1U)
#define FiltTrqRange_BRAKING_NEG       ((FiltTrqRange)2U)
#define FiltTrqRange_ZEROCROSS_POS     ((FiltTrqRange)3U)
#define FiltTrqRange_ZEROCROSS_NEG     ((FiltTrqRange)4U)
#define FiltTrqRange_POWER_POS         ((FiltTrqRange)5U)
#define FiltTrqRange_POWER_NEG         ((FiltTrqRange)6U)

typedef uint8_T TV3Status;

/* enum TV3Status */
#define TV3Status_DEFAULT              ((TV3Status)0U)
#define TV3Status_BATT_COOL            ((TV3Status)1U)
#define TV3Status_BATT_HEAT            ((TV3Status)2U)

typedef uint8_T TV4Status;

/* enum TV4Status */
#define TV4Status_DEFAULT              ((TV4Status)0U)
#define TV4Status_CABIN_HEAT           ((TV4Status)1U)
#define TV4Status_BATT_HEAT            ((TV4Status)2U)
#define TV4Status_BATT_CABIN_HEAT      ((TV4Status)3U)
#define TV4Status_BATT_HEAT_DEF        ((TV4Status)4U)

typedef uint8_T PumpStatus;

/* enum PumpStatus */
#define PumpStatus_OFF                 ((PumpStatus)0U)
#define PumpStatus_LOW_SPEED           ((PumpStatus)1U)
#define PumpStatus_MEDIUM_SPEED        ((PumpStatus)2U)
#define PumpStatus_HIGH_SPEED          ((PumpStatus)3U)
#define PumpStatus_FAILURE             ((PumpStatus)5U)
#define PumpStatus_INVALID             ((PumpStatus)10U)

typedef uint8_T PmmStatus;

/* enum PmmStatus */
#define PmmStatus_OFF                  ((PmmStatus)0U)
#define PmmStatus_HCMWAKEUP            ((PmmStatus)1U)
#define PmmStatus_MCUWAKEUP            ((PmmStatus)2U)
#define PmmStatus_DRVBMSNEGCLOSE       ((PmmStatus)3U)
#define PmmStatus_CHGBMSNEGCLOSE       ((PmmStatus)4U)
#define PmmStatus_HCMNEGCLOSE          ((PmmStatus)5U)
#define PmmStatus_ASSISTCLOSE          ((PmmStatus)6U)
#define PmmStatus_DCDCACT              ((PmmStatus)7U)
#define PmmStatus_STANDBYDRV           ((PmmStatus)8U)
#define PmmStatus_CHARGE               ((PmmStatus)9U)
#define PmmStatus_IMMOCHECK            ((PmmStatus)10U)
#define PmmStatus_SDCACACT             ((PmmStatus)11U)
#define PmmStatus_MAINPOSCLOSE         ((PmmStatus)12U)
#define PmmStatus_BDCACACT             ((PmmStatus)13U)
#define PmmStatus_MCUACT               ((PmmStatus)14U)
#define PmmStatus_DRIVE                ((PmmStatus)15U)
#define PmmStatus_SHUTDOWNWAIT         ((PmmStatus)16U)
#define PmmStatus_HVDEVICEDEACT        ((PmmStatus)17U)
#define PmmStatus_MCUDEACT             ((PmmStatus)18U)
#define PmmStatus_MAINPOSOPEN          ((PmmStatus)19U)
#define PmmStatus_HVDEVICEDEACTEMGY    ((PmmStatus)20U)
#define PmmStatus_MAINPOSOPENEMGY      ((PmmStatus)21U)
#define PmmStatus_ASSISTOPEN           ((PmmStatus)22U)
#define PmmStatus_HCMNEGOPEN           ((PmmStatus)23U)
#define PmmStatus_ASSISTOPENEMGY       ((PmmStatus)24U)
#define PmmStatus_HCMNEGOPENEMGY       ((PmmStatus)25U)
#define PmmStatus_MCUDISCHARGE         ((PmmStatus)26U)
#define PmmStatus_BMSNEGOPEN           ((PmmStatus)27U)
#define PmmStatus_LVCUTREQUEST         ((PmmStatus)28U)
#define PmmStatus_LVCUTWAIT            ((PmmStatus)29U)
#define PmmStatus_AFTERRUN             ((PmmStatus)30U)
#define PmmStatus_INIT                 ((PmmStatus)31U)
#define PmmStatus_BMSNEGOPENEMGY       ((PmmStatus)32U)
#define PmmStatus_LOWTEMPON            ((PmmStatus)33U)
#define PmmStatus_LOWTEMPOFF           ((PmmStatus)34U)
#define PmmStatus_CHGWAIT              ((PmmStatus)35U)
#define PmmStatus_STANDBYDRVCONV       ((PmmStatus)36U)
#define PmmStatus_VEHSTART             ((PmmStatus)37U)
#define PmmStatus_INTELCHG             ((PmmStatus)38U)
#define PmmStatus_TIMEOUT              ((PmmStatus)39U)     /* %VE21 ADD 20231108*/
#define PmmStatus_SHUTDOWNWAITEMGY     ((PmmStatus)40U)     /* %VE21 ADD 20231108*/     
#define PmmStatus_HVSHUTDNEMGY         ((PmmStatus)41U)     /* %VE21 ADD 20231108*/    
#define PmmStatus_CHARGEND             ((PmmStatus)42U)     /* %VE21 ADD 20231108*/

/* This defines an enumerated type for Pmm Status */

typedef uint8_T McuSts;

/* enum McuSts */
#define McuSts_NOTREADY               ((McuSts)0U)
#define McuSts_READY                  ((McuSts)1U)
#define McuSts_ERROR                  ((McuSts)2U)
#define McuSts_RESERVED               ((McuSts)3U)

/* This defines an enumerated type for McuSts */

typedef uint8_T CruiseMode_e;

/* enum CruiseMode_e */
#define CruiseMode_e_PidMode          ((CruiseMode_e)0U)
#define CruiseMode_e_MixMode          ((CruiseMode_e)1U)
#define CruiseMode_e_TableMode        ((CruiseMode_e)2U)

/* This defines an enumerated type for CruiseMode_e */

typedef uint8_T CruPidTruTabSts_e;

/* enum CruPidTruTabSts_e */
#define CruPidTruTabSts_e_PidDvrTorqLoad         ((CruPidTruTabSts_e)0U)
#define CruPidTruTabSts_e_PidDvrTorqUnload       ((CruPidTruTabSts_e)1U)
#define CruPidTruTabSts_e_PidRegenTorqUnload     ((CruPidTruTabSts_e)2U)
#define CruPidTruTabSts_e_PidRegenTorqLoad       ((CruPidTruTabSts_e)3U)
#define CruPidTruTabSts_e_PidTorqKeeping         ((CruPidTruTabSts_e)4U)

/* This defines an enumerated type for CruPidTruTabSts_e */

typedef uint8_T CruTabTruTabSts_e;

/* enum CruTabTruTabSts_e */
#define CruTabTruTabSts_e_TabTorqRise      ((CruTabTruTabSts_e)0U)
#define CruTabTruTabSts_e_TabTorqDown      ((CruTabTruTabSts_e)1U)
#define CruTabTruTabSts_e_TabTorqKeep      ((CruTabTruTabSts_e)2U)

/* This defines an enumerated type for CruTabTruTabSts_e */

typedef uint8_T NMStatus;

/* enum NMStatus_e */
#define NMStatus_SLEEPMODE            ((NMStatus)0U)
#define NMStatus_CANDISABLE           ((NMStatus)1U)
#define NMStatus_VCUSLEEPWAIT         ((NMStatus)2U)
#define NMStatus_NORMALWAKED          ((NMStatus)3U)
#define NMStatus_NORMALOPERATION      ((NMStatus)4U)

/* This defines an enumerated type for NMStatus_e */

typedef uint8_T GearShiftResp;

/* enum GearShiftResp */
#define GearShiftResp_DISABLE            ((GearShiftResp)0U)
#define GearShiftResp_ENABLE             ((GearShiftResp)1U)
#define GearShiftResp_RESERVED           ((GearShiftResp)2U)
#define GearShiftResp_INVALID            ((GearShiftResp)3U)

/* This defines an enumerated type for GearShiftResp */

typedef uint8_T TraModeReq;

/* enum TraModeReq */
#define TraModeReq_NO_REQ               ((TraModeReq)0U)
#define TraModeReq_TRQ_CTRL             ((TraModeReq)1U)
#define TraModeReq_SPD_CTRL             ((TraModeReq)2U)
 
/* This defines an enumerated type for TraModeReq */

typedef uint8_T CrModeMngr_e;

/* enum CrModeMngr_e */
#define CrModeMngr_e_ACTIVE_KEEP       ((CrModeMngr_e)0U)
#define CrModeMngr_e_ACCEL             ((CrModeMngr_e)1U)
#define CrModeMngr_e_DECEL             ((CrModeMngr_e)2U)
#define CrModeMngr_e_ACTIVE_RESUME     ((CrModeMngr_e)3U)
#define CrModeMngr_e_TIP_IN            ((CrModeMngr_e)4U)
#define CrModeMngr_e_TIP_OUT           ((CrModeMngr_e)5U)
#define CrModeMngr_e_OFF               ((CrModeMngr_e)6U)
 
/* This defines an enumerated type for CrModeMngr_e */

typedef uint8_T CrsBtnErrSts;

/* enum CrsBtnErrSts */
#define CrsBtnErrSts_NONE                 ((CrsBtnErrSts)0U)
#define CrsBtnErrSts_CRUISE_STUCK         ((CrsBtnErrSts)1U)
#define CrsBtnErrSts_SET_STUCK            ((CrsBtnErrSts)2U)
#define CrsBtnErrSts_RESUME_STUCK         ((CrsBtnErrSts)3U)
#define CrsBtnErrSts_VOLTAGE_ABNORMAL     ((CrsBtnErrSts)7U)
#define CrsBtnErrSts_VOLTAGE_SCB          ((CrsBtnErrSts)8U)
#define CrsBtnErrSts_VOLTAGE_SCG          ((CrsBtnErrSts)9U)
#define CrsBtnErrSts_VOLTAGE_OC           ((CrsBtnErrSts)10U)

/* This defines an enumerated type for CrsBtnErrSts */

typedef uint8_T CrsBtnSts;

/* enum CrsBtnSts */
#define CrsBtnSts_NONE                ((CrsBtnSts)0U)
#define CrsBtnSts_CRUISE_MAIN         ((CrsBtnSts)1U)
#define CrsBtnSts_SET                 ((CrsBtnSts)2U)
#define CrsBtnSts_RESUME              ((CrsBtnSts)3U)

/* This defines an enumerated type for CrsBtnSts */

typedef uint8_T CruiseSts_e;

/* enum CruiseSts_e */
#define CruiseSts_e_OFF              ((CruiseSts_e)0U)
#define CruiseSts_e_STANDBY          ((CruiseSts_e)1U)
#define CruiseSts_e_ACTIVE           ((CruiseSts_e)2U)
#define CruiseSts_e_OVERRIDE         ((CruiseSts_e)3U)
#define CruiseSts_e_INVALID          ((CruiseSts_e)4U)

/* This defines an enumerated type for CruiseSts_e */

typedef uint8_T ApuMode;

/* enum ApuMode */
#define ApuMode_SMART_MODE              ((ApuMode)0U)
#define ApuMode_REC_MODE          		((ApuMode)1U)
#define ApuMode_EV_MODE      			((ApuMode)2U)
#define ApuMode_SAVE_MODE               ((ApuMode)3U)
#define ApuMode_REV_MODE                ((ApuMode)4U)
#define ApuMode_INVALID        			((ApuMode)5U)

/* This defines an enumerated type for ApuMode */

typedef uint8_T PHEVMode;

/* enum PHEVMode */
#define PHEVMode_CLUTCH_ENG            ((PHEVMode)0U)
#define PHEVMode_CLUTCH_DIS      	   ((PHEVMode)1U)
#define PHEVMode_DEFAULT         	   ((PHEVMode)2U)

/* This defines an enumerated type for PEHVMode */


/*-----------------------L2 ADD 20240520----------------------------------*/
typedef uint8_T ACUCrashOutputSts;

/* enum ACUCrashOutputSts */
#define ACUCrashOutputSts_Reserved1                   ((ACUCrashOutputSts)0U)
#define ACUCrashOutputSts_FrontFirstLevel             ((ACUCrashOutputSts)1U)
#define ACUCrashOutputSts_LeftHandSide                ((ACUCrashOutputSts)2U)
#define ACUCrashOutputSts_RightHandSide               ((ACUCrashOutputSts)3U)
#define ACUCrashOutputSts_RearSide                    ((ACUCrashOutputSts)4U)
#define ACUCrashOutputSts_Reserved2                   ((ACUCrashOutputSts)5U)
#define ACUCrashOutputSts_Reserved3                   ((ACUCrashOutputSts)6U)
#define ACUCrashOutputSts_Reserved4                   ((ACUCrashOutputSts)7U)

typedef uint8_T IsgModReq;

/* enum IsgModReq */
#define IsgModReq_Initial                   ((IsgModReq)0U)
#define IsgModReq_StandBy                   ((IsgModReq)1U)
#define IsgModReq_TqCtrl                    ((IsgModReq)2U)
#define IsgModReq_SpdCtrl                   ((IsgModReq)3U)
#define IsgModReq_reserve                   ((IsgModReq)4U)
#define IsgModReq_PreCharge                 ((IsgModReq)5U)
#define IsgModReq_Power_Down                ((IsgModReq)6U)
#define IsgModReq_DisCharge                 ((IsgModReq)7U)



typedef uint8_T LeverReq;

/* enum LeverReq */
#define LeverReq_Home                             ((LeverReq)0U)
#define LeverReq_Left                             ((LeverReq)1U)
#define LeverReq_LeftLeft                         ((LeverReq)2U)
#define LeverReq_Right                            ((LeverReq)3U)
#define LeverReq_RightRight                       ((LeverReq)4U)



typedef uint8_T GearState;

/* enum GearState */
#define GearState_N                             ((GearState)0U)
#define GearState_D                             ((GearState)1U)
#define GearState_R                             ((GearState)2U)
#define GearState_P                             ((GearState)3U)

typedef uint8_T OnBdDisChrgrCCline;

/* enum OnBdDisChrgrCCline */
#define OnBdDisChrgrCCline_Notconnected                             ((OnBdDisChrgrCCline)0U)
#define OnBdDisChrgrCCline_Halfconnected                            ((OnBdDisChrgrCCline)1U)
#define OnBdDisChrgrCCline_V2Lconnected                             ((OnBdDisChrgrCCline)2U)
#define OnBdDisChrgrCCline_V2Vconnected                             ((OnBdDisChrgrCCline)3U)

typedef uint8_T StsCC2;

/* enum StsCC2 */
#define StsCC2_Disconnected                             ((StsCC2)0U)
#define StsCC2_ConnectVeh                               ((StsCC2)1U)
#define StsCC2_ConnectStation                           ((StsCC2)2U)
#define StsCC2_ConnectAbnorm                            ((StsCC2)3U)

typedef uint8_T ElockStmode;

/* enum ElockStmode */
#define ElockStmode_Default                             ((ElockStmode)0U)
#define ElockStmode_Lock                                ((ElockStmode)1U)
#define ElockStmode_Unlock                              ((ElockStmode)2U)
#define ElockStmode_LockErr                             ((ElockStmode)3U)
#define ElockStmode_UnlockErr                           ((ElockStmode)4U)

typedef uint8_T VCUStsMainHVIL;

/* enum VCUStsMainHVIL */
#define VCUStsMainHVIL_Normal                             ((VCUStsMainHVIL)0U)
#define VCUStsMainHVIL_Error                              ((VCUStsMainHVIL)1U)
#define VCUStsMainHVIL_Reserved                           ((VCUStsMainHVIL)2U)
#define VCUStsMainHVIL_Invalid                            ((VCUStsMainHVIL)3U)


typedef uint8_T BMSHStsModeReq;

/* enum BMSHStsModeReq */
#define BMSHStsModeReq_Default                      ((BMSHStsModeReq)0U)
#define BMSHStsModeReq_Standby                      ((BMSHStsModeReq)2U)
#define BMSHStsModeReq_Normal                       ((BMSHStsModeReq)4U)
#define BMSHStsModeReq_ChargeAllowed                ((BMSHStsModeReq)10U)
#define BMSHStsModeReq_ShutDown                     ((BMSHStsModeReq)11U)
#define BMSHStsModeReq_V2LDisCharge                 ((BMSHStsModeReq)14U)


typedef uint8_T DriveMode;

/* enum DriveMode */
#define DriveMode_Normal                             ((DriveMode)0U)
#define DriveMode_Sport                              ((DriveMode)1U)
#define DriveMode_ECO                                ((DriveMode)2U)


/*---------------------------------------------------------------------------------*/


#endif                                 /* RTW_HEADER_enum_Type_h_ */
/*======================== TOOL VERSION INFORMATION ==========================*
 * MATLAB 9.3 (R2017b)24-Jul-2017                                             *
 * Simulink 9.0 (R2017b)24-Jul-2017                                           *
 * Simulink Coder 8.13 (R2017b)24-Jul-2017                                    *
 * Embedded Coder 6.13 (R2017b)24-Jul-2017                                    *
 * Stateflow 9.0 (R2017b)24-Jul-2017                                          *
 * Fixed-Point Designer 6.0 (R2017b)24-Jul-2017                               *
 *============================================================================*/

/*======================= LICENSE IN USE INFORMATION =========================*
 * matlab                                                                     *
 * matlab_coder                                                               *
 * real-time_workshop                                                         *
 * rtw_embedded_coder                                                         *
 * simulink                                                                   *
 * stateflow                                                                  *
 *============================================================================*/
