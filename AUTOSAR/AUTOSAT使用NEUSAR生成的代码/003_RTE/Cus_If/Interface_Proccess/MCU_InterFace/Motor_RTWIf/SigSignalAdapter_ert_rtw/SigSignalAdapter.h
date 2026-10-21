/*
 * File: SigSignalAdapter.h
 *
 * Code generated for Simulink model 'SigSignalAdapter'.
 *
 * Model version                  : 1.342
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Oct 13 17:09:44 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SigSignalAdapter_h_
#define RTW_HEADER_SigSignalAdapter_h_
#ifndef SigSignalAdapter_COMMON_INCLUDES_
#define SigSignalAdapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SigSignalAdapter_COMMON_INCLUDES_ */

#include "SigSignalAdapter_types.h"
#include "Hal_ReadVLDriFault.h"
#include "Hal_ReadMotorTempAdc.h"
#include "Hal_ReadLDriUVFault.h"
#include "Hal_ReadMotorTempAdcBkUp.h"
#include "Hal_ReadSwitchTempAdc1.h"
#include "Hal_GetHwOvervoltSt1.h"
#include "Hal_ReadSwitchTempAdc2.h"
#include "Hal_GetHwOvercurSt.h"
#include "Hal_ReadPhaseCurrentAdc1.h"
#include "Hal_ReadDcBusVoltageAdc.h"
#include "Hal_ReadSwitchTempAdc3.h"
#include "Hal_GetHwOvercurSt1.h"
#include "Hal_GetHwOvercurSt2.h"
#include "Hal_ReadBatteryVoltageAdc.h"
#include "Hal_ReadVHDriFault.h"
#include "Hal_ReadHDriDeSatFault.h"
#include "Hal_ReadHDirUVFault.h"
#include "Hal_ReadPowerChipVoltageAdc.h"
#include "Hal_ReadIgnitionVoltageAdc.h"
#include "Hal_ReadLDriDeSatFault.h"
#include "Hal_ReadUHDriFault.h"
#include "Hal_ReadULDriFault.h"
#include "Hal_ReadPhaseCurrentAdc3.h"
#include "Hal_ReadWLDriFault.h"
#include "Hal_ReadUPhaZeroPointAD.h"
#include "Hal_ReadWPhaZeroPointAD.h"
#include "Hal_ClrHWFaultCycle.h"
#include "Hal_GetHwOvervoltSt.h"
#include "Hal_SetDriverCircuit.h"
#include "Hal_ConfigActiveShortCircuit.h"
#include "Hal_UpdatePwmFreqCycle.h"
#include "Hal_UpdatePwmDutyCycle.h"
#include "Hal_ReadWHDriFault.h"
#include "Hal_SetPwrOffDlyFlg.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T output;                      /* '<S80>/Chart' */
  uint8_T Switch2;                     /* '<S69>/Switch2' */
} B_SigSignalAdapter_T;

/* Real-time Model Data Structure */
struct tag_RTM_SigSignalAdapter_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_SigSignalAdapter_T SigSignalAdapter_B;

/* Model entry point functions */
extern void SigSignalAdapter_initialize(void);
extern void SigSignalAdapter_terminate(void);

/* Exported entry point function */
extern void SGSA_ReadTempVolt_1ms(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGSA_Read_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void SGSA_WriteCommand_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real32_T SGSA_TMotSnsr1TableHigh_M[301];
                      /* Referenced by: '<S42>/Interpolation Using Prelookup' */
extern volatile real32_T SGSA_UTIgbtPha123SampleTemp_A[44];/* Referenced by:
                                                            * '<S18>/Prelookup'
                                                            * '<S19>/Prelookup'
                                                            * '<S20>/Prelookup'
                                                            */
extern volatile real32_T SGSA_UTIgbtPha123Table_M[44];/* Referenced by:
                                                       * '<S18>/Interpolation Using Prelookup'
                                                       * '<S19>/Interpolation Using Prelookup'
                                                       * '<S20>/Interpolation Using Prelookup'
                                                       */
extern volatile real32_T SGSA_UTMotSnsr1SampleHighTemp_A[301];/* Referenced by: '<S42>/Prelookup' */

#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T SGSA_BatteryVoltGain_C;/* Referenced by: '<S34>/Constant' */

/* Battery voltage sensor gain calibration */
extern volatile real32_T SGSA_BatteryVoltOffset_C;/* Referenced by: '<S35>/Constant' */

/* Battery voltage sensor offset calibration */
extern volatile uint8_T SGSA_ClrHWFaultEnable_C;/* Referenced by: '<S75>/Constant' */
extern volatile boolean_T SGSA_ClrHWFault_C;/* Referenced by: '<S74>/Constant' */
extern volatile real32_T SGSA_DcLinkVoltGain_C;/* Referenced by: '<S55>/Constant' */

/* DC-link voltage sensor gain calibration */
extern volatile real32_T SGSA_DcLinkVoltOffset_C;/* Referenced by: '<S56>/Constant' */

/* DC-link voltage sensor offset calibration */
extern volatile real32_T SGSA_IgnitionAVoltGain_C;/* Referenced by: '<S30>/Constant' */
extern volatile real32_T SGSA_IgnitionAVoltOffset_C;/* Referenced by: '<S27>/Constant' */
extern volatile real32_T SGSA_IgnitionBVoltGain_C;/* Referenced by: '<S31>/Constant' */
extern volatile real32_T SGSA_IgnitionBVoltOffset_C;/* Referenced by: '<S32>/Constant' */
extern volatile real32_T SGSA_IgnitionCVoltGain_C;/* Referenced by: '<S28>/Constant' */

/* Ignition voltage sensor gain calibration */
extern volatile real32_T SGSA_IgnitionCVoltOffset_C;/* Referenced by: '<S29>/Constant' */

/* Ignition voltage sensor offset calibration */
extern volatile real32_T SGSA_KL15VoltGain_C;/* Referenced by: '<S37>/Constant' */
extern volatile real32_T SGSA_Kl15VoltOffset_C;/* Referenced by: '<S38>/Constant' */
extern volatile real32_T SGSA_MotorInitAngleOffset_C;/* Referenced by: '<S67>/Constant' */

/* Initial angle offset for motor alignment */
extern volatile real32_T SGSA_MotorTempGain_C;/* Referenced by: '<S46>/Constant' */

/* Motor temperature sensor gain calibration */
extern volatile real32_T SGSA_MotorTempOffset_C;/* Referenced by: '<S45>/Constant' */

/* Motor temperature sensor offset calibration */
extern volatile real32_T SGSA_PhaseACurrentGain_C;/* Referenced by: '<S63>/Constant' */

/* Phase A current sensor gain calibration value */
extern volatile real32_T SGSA_PhaseAPwmDuty_C;/* Referenced by: '<S87>/Constant' */

/* Phase A PWM duty cycle parameter setpoint */
extern volatile real32_T SGSA_PhaseBPwmDuty_C;/* Referenced by: '<S84>/Constant' */

/* Phase B PWM duty cycle parameter setpoint */
extern volatile real32_T SGSA_PhaseCCurrentGain_C;/* Referenced by: '<S64>/Constant' */
extern volatile real32_T SGSA_PhaseCPwmDuty_C;/* Referenced by: '<S85>/Constant' */

/* Phase C PWM duty cycle parameter setpoint */
extern volatile real32_T SGSA_PowerChipVoltGain_C;/* Referenced by: '<S40>/Constant' */

/* Battery voltage sensor gain calibration */
extern volatile real32_T SGSA_PowerChipVoltOffset_C;/* Referenced by: '<S41>/Constant' */
extern volatile uint8_T SGSA_PwmParamEnable_C;/* Referenced by: '<S86>/Constant' */

/* Enable flag for PWM parameter setpoint mode */
extern volatile uint8_T SGSA_SetDriverStsEnable_C;/* Referenced by: '<S77>/Constant' */
extern volatile uint8_T SGSA_SetDriverSts_C;/* Referenced by: '<S76>/Constant' */
extern volatile uint8_T SGSA_SetFreqEnable_C;/* Referenced by: '<S83>/Constant' */
extern volatile real32_T SGSA_SetFreq_C;/* Referenced by: '<S82>/Constant' */
extern volatile uint8_T SGSA_SetHighASCFlgEnable_C;/* Referenced by: '<S79>/Constant' */
extern volatile uint8_T SGSA_SetHighASCFlg_C;/* Referenced by: '<S78>/Constant' */
extern volatile uint8_T SGSA_SetPwrOffDlyFlgEnable_C;/* Referenced by: '<S89>/Constant' */
extern volatile boolean_T SGSA_SetPwrOffDlyFlg_C;/* Referenced by: '<S88>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T HWAL_AdcIAZero;

/* Phase A current ADC raw value */
extern real32_T HWAL_AdcICZero;

/* Phase A current ADC raw value */
extern real32_T HWAL_BatteryVoltAdc;

/* Battery supply voltage ADC raw value */
extern real32_T HWAL_DcLinkVoltAdc;

/* DC-link voltage ADC raw value */
extern real32_T HWAL_DcLinkVoltAdcBkUp;

/* DC-link voltage ADC raw value */
extern real32_T HWAL_IgnitionVoltAdc;

/* Ignition supply voltage ADC raw value */
extern real32_T HWAL_MotorTempAdc;

/* Motor temperature ADC raw value */
extern real32_T HWAL_MotorTempAdcBkUp;

/* Motor temperature ADC raw value */
extern real32_T HWAL_PhaseACurrentAdc;

/* Phase A current ADC raw value */
extern real32_T HWAL_PhaseACurrentAdcBkUp;

/* Phase A current ADC raw value */
extern real32_T HWAL_PhaseASwitchTempAdc;

/* Phase A power switch temperature ADC raw value */
extern real32_T HWAL_PhaseASwitchTempAdcBkUp;

/* Phase A power switch temperature ADC raw value */
extern real32_T HWAL_PhaseBSwitchTempAdc;

/* Phase B power switch temperature ADC raw value */
extern real32_T HWAL_PhaseBSwitchTempAdcBkUp;

/* Phase A power switch temperature ADC raw value */
extern real32_T HWAL_PhaseCCurrentAdc;

/* Phase C current ADC raw value */
extern real32_T HWAL_PhaseCCurrentAdcBkUp;

/* Phase A current ADC raw value */
extern real32_T HWAL_PhaseCSwitchTempAdc;

/* Phase C power switch temperature ADC raw value */
extern real32_T HWAL_PhaseCSwitchTempAdcBkUp;

/* Phase A power switch temperature ADC raw value */
extern real32_T HWAL_PowerChipVoltAdc;

/* Battery supply voltage ADC raw value */
extern real32_T SGSA_BatteryVolt;      /* '<S5>/Product1' */

/* Battery supply voltage measurement */
extern real32_T SGSA_DcLinkVoltMeas;   /* '<S47>/Product' */

/* DC-link voltage measurement */
extern real32_T SGSA_DcLinkVoltMeasAD; /* '<S47>/Gain2' */

/* DC-link voltage measurement AD */
extern uint8_T SGSA_DriveErr;          /* '<S8>/Data Type Conversion1' */
extern real32_T SGSA_ElecAngle;        /* '<S66>/Switch' */

/* Electrical rotor angle */
extern uint8_T SGSA_HDriFault;         /* '<S8>/Data Type Conversion' */
extern uint8_T SGSA_HwOvercurSt;       /* '<S14>/Data Type Conversion1' */
extern uint8_T SGSA_HwOvervoltSt;      /* '<S14>/Data Type Conversion' */
extern real32_T SGSA_IgnitionVolt;     /* '<S6>/Product2' */

/* Ignition supply voltage measurement */
extern uint8_T SGSA_LDriFault;         /* '<S8>/Data Type Conversion2' */
extern real32_T SGSA_MotorTemp1;     /* '<S42>/Interpolation Using Prelookup' */

/* Motor temperature sensor 1 reading */
extern real32_T SGSA_MotorTemp1AD;     /* '<S17>/Gain1' */

/* Motor temperature sensor 1 reading */
extern uint8_T SGSA_PWMSts;            /* '<S51>/Chart' */

/* PWM State */
extern real32_T SGSA_PhaseACurrent;    /* '<S50>/Product' */

/* Phase A current measurement */
extern real32_T SGSA_PhaseACurrentAD;  /* '<S50>/Gain1' */

/* Phase C current measurement */
extern real32_T SGSA_PhaseASwitchTemp;
                                     /* '<S18>/Interpolation Using Prelookup' */

/* Phase A power switch temperature measurement */
extern real32_T SGSA_PhaseASwitchTempAD;/* '<S4>/Gain1' */

/* Phase A power switch temperature measurement */
extern real32_T SGSA_PhaseBSwitchTemp;
                                     /* '<S19>/Interpolation Using Prelookup' */

/* Phase B power switch temperature measurement */
extern real32_T SGSA_PhaseBSwitchTempAD;/* '<S4>/Gain2' */

/* Phase A power switch temperature measurement */
extern real32_T SGSA_PhaseCCurrent;    /* '<S50>/Product2' */

/* Phase C current measurement */
extern real32_T SGSA_PhaseCCurrentAD;  /* '<S50>/Gain2' */

/* Phase C current measurement */
extern real32_T SGSA_PhaseCSwitchTemp;
                                     /* '<S20>/Interpolation Using Prelookup' */

/* Phase C power switch temperature measurement */
extern real32_T SGSA_PhaseCSwitchTempAD;/* '<S4>/Gain3' */

/* Phase A power switch temperature measurement */
extern real32_T SGSA_PwrChipVolt;      /* '<S7>/Product1' */
extern uint8_T SGSA_ResolverError;     /* '<S2>/SGRD_ResolverErr' */

/* Resolver fault detection status */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_SigSignalAdapter_T *const SigSignalAdapter_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SigSignalAdapter'
 * '<S1>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys'
 * '<S2>'   : 'SigSignalAdapter/SGSA_Read_100us_sys'
 * '<S3>'   : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys'
 * '<S4>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD'
 * '<S5>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD1'
 * '<S6>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD2'
 * '<S7>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/ConvPowerChipVolt'
 * '<S8>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Driver_Err'
 * '<S9>'   : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Function Caller Interface'
 * '<S10>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Function Caller Interface1'
 * '<S11>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Function Caller Interface2'
 * '<S12>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Function Caller Interface3'
 * '<S13>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Function Caller Interface4'
 * '<S14>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/GetHWErrorStatus'
 * '<S15>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Get_Driver_Fault'
 * '<S16>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/PowerChipVolADGet'
 * '<S17>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Subsystem'
 * '<S18>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/1D LUT'
 * '<S19>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/1D LUT1'
 * '<S20>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/1D LUT2'
 * '<S21>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Local Variable Storage3'
 * '<S22>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Local Variable Storage4'
 * '<S23>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Local Variable Storage5'
 * '<S24>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Local Variable Storage6'
 * '<S25>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Local Variable Storage7'
 * '<S26>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Local Variable Storage8'
 * '<S27>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Parameter10'
 * '<S28>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Parameter11'
 * '<S29>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Parameter12'
 * '<S30>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Parameter7'
 * '<S31>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Parameter8'
 * '<S32>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD/Parameter9'
 * '<S33>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD1/Local Variable Storage1'
 * '<S34>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD1/Parameter2'
 * '<S35>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD1/Parameter3'
 * '<S36>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD2/Local Variable Storage2'
 * '<S37>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD2/Parameter5'
 * '<S38>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/AdcToPhysicalAndGetAD2/Parameter6'
 * '<S39>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/ConvPowerChipVolt/Local Variable Storage1'
 * '<S40>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/ConvPowerChipVolt/Parameter2'
 * '<S41>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/ConvPowerChipVolt/Parameter3'
 * '<S42>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Subsystem/1D LUT'
 * '<S43>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Subsystem/Local Variable Storage1'
 * '<S44>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Subsystem/Local Variable Storage3'
 * '<S45>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Subsystem/Parameter10'
 * '<S46>'  : 'SigSignalAdapter/SGSA_ReadTempVolt_1ms_sys/Subsystem/Parameter7'
 * '<S47>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/AdcToPhysicalAndGetAD'
 * '<S48>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/Function Caller Interface'
 * '<S49>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/Function Caller Interface1'
 * '<S50>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD'
 * '<S51>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PwmStateGet'
 * '<S52>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/ResolverAngleZeroAdjust'
 * '<S53>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/AdcToPhysicalAndGetAD/Local Variable Storage'
 * '<S54>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/AdcToPhysicalAndGetAD/Local Variable Storage9'
 * '<S55>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/AdcToPhysicalAndGetAD/Parameter1'
 * '<S56>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/AdcToPhysicalAndGetAD/Parameter4'
 * '<S57>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Local Variable Storage'
 * '<S58>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Local Variable Storage1'
 * '<S59>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Local Variable Storage2'
 * '<S60>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Local Variable Storage3'
 * '<S61>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Local Variable Storage4'
 * '<S62>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Local Variable Storage5'
 * '<S63>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Parameter1'
 * '<S64>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PhaseCurrentAdcToPhysicalAndGetAD/Parameter5'
 * '<S65>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/PwmStateGet/Chart'
 * '<S66>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/ResolverAngleZeroAdjust/AngleWrapZeroToTwoPi'
 * '<S67>'  : 'SigSignalAdapter/SGSA_Read_100us_sys/ResolverAngleZeroAdjust/Parameter4'
 * '<S68>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Clear HW Fault'
 * '<S69>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set Driver State'
 * '<S70>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set High ASC Flag'
 * '<S71>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Frequency'
 * '<S72>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Run'
 * '<S73>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set Power Off Delay Flag'
 * '<S74>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Clear HW Fault/Parameter2'
 * '<S75>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Clear HW Fault/Parameter3'
 * '<S76>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set Driver State/Parameter2'
 * '<S77>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set Driver State/Parameter3'
 * '<S78>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set High ASC Flag/Parameter2'
 * '<S79>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set High ASC Flag/Parameter3'
 * '<S80>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set High ASC Flag/Subsystem'
 * '<S81>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set High ASC Flag/Subsystem/Chart'
 * '<S82>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Frequency/Parameter2'
 * '<S83>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Frequency/Parameter3'
 * '<S84>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Run/Parameter1'
 * '<S85>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Run/Parameter2'
 * '<S86>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Run/Parameter3'
 * '<S87>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set PWM Run/Parameter4'
 * '<S88>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set Power Off Delay Flag/Parameter2'
 * '<S89>'  : 'SigSignalAdapter/SGSA_WriteCommand_100us_sys/Set Power Off Delay Flag/Parameter3'
 */
#endif                                 /* RTW_HEADER_SigSignalAdapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
