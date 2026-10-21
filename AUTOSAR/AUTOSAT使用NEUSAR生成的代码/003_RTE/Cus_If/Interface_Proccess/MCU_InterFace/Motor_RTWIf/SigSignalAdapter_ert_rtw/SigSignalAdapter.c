/*
 * File: SigSignalAdapter.c
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

#include "SigSignalAdapter.h"
#include "Hal_ReadMotorTempAdc.h"
#include "Hal_ReadMotorTempAdcBkUp.h"
#include "Hal_ReadSwitchTempAdc1.h"
#include "Hal_ReadSwitchTempAdc2.h"
#include "Hal_ReadSwitchTempAdc3.h"
#include "Hal_ReadPowerChipVoltageAdc.h"
#include "Hal_ReadBatteryVoltageAdc.h"
#include "Hal_ReadIgnitionVoltageAdc.h"
#include "Hal_GetHwOvervoltSt.h"
#include "Hal_GetHwOvervoltSt1.h"
#include "Hal_GetHwOvercurSt.h"
#include "Hal_GetHwOvercurSt1.h"
#include "Hal_GetHwOvercurSt2.h"
#include "Hal_ReadUHDriFault.h"
#include "Hal_ReadVHDriFault.h"
#include "Hal_ReadWHDriFault.h"
#include "Hal_ReadHDriDeSatFault.h"
#include "Hal_ReadHDirUVFault.h"
#include "Hal_ReadULDriFault.h"
#include "Hal_ReadVLDriFault.h"
#include "Hal_ReadWLDriFault.h"
#include "Hal_ReadLDriDeSatFault.h"
#include "Hal_ReadLDriUVFault.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "Hal_ReadPhaseCurrentAdc1.h"
#include "Hal_ReadUPhaZeroPointAD.h"
#include "Hal_ReadPhaseCurrentAdc3.h"
#include "Hal_ReadWPhaZeroPointAD.h"
#include "Hal_ReadDcBusVoltageAdc.h"
#include "Hal_ConfigActiveShortCircuit.h"
#include "Hal_SetDriverCircuit.h"
#include "Hal_UpdatePwmDutyCycle.h"
#include "Hal_UpdatePwmFreqCycle.h"
#include "Hal_ClrHWFaultCycle.h"
#include "Hal_SetPwrOffDlyFlg.h"
#include "plook_u32ff_binx.h"
#include "intrp1d_fu32fl.h"
#include "SigSignalAdapter_private.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile real32_T SGSA_TMotSnsr1TableHigh_M[301] = { 250.0F, 249.0F, 248.0F,
  247.0F, 246.0F, 245.0F, 244.0F, 243.0F, 242.0F, 241.0F, 240.0F, 239.0F, 238.0F,
  237.0F, 236.0F, 235.0F, 234.0F, 233.0F, 232.0F, 231.0F, 230.0F, 229.0F, 228.0F,
  227.0F, 226.0F, 225.0F, 224.0F, 223.0F, 222.0F, 221.0F, 220.0F, 219.0F, 218.0F,
  217.0F, 216.0F, 215.0F, 214.0F, 213.0F, 212.0F, 211.0F, 210.0F, 209.0F, 208.0F,
  207.0F, 206.0F, 205.0F, 204.0F, 203.0F, 202.0F, 201.0F, 200.0F, 199.0F, 198.0F,
  197.0F, 196.0F, 195.0F, 194.0F, 193.0F, 192.0F, 191.0F, 190.0F, 189.0F, 188.0F,
  187.0F, 186.0F, 185.0F, 184.0F, 183.0F, 182.0F, 181.0F, 180.0F, 179.0F, 178.0F,
  177.0F, 176.0F, 175.0F, 174.0F, 173.0F, 172.0F, 171.0F, 170.0F, 169.0F, 168.0F,
  167.0F, 166.0F, 165.0F, 164.0F, 163.0F, 162.0F, 161.0F, 160.0F, 159.0F, 158.0F,
  157.0F, 156.0F, 155.0F, 154.0F, 153.0F, 152.0F, 151.0F, 150.0F, 149.0F, 148.0F,
  147.0F, 146.0F, 145.0F, 144.0F, 143.0F, 142.0F, 141.0F, 140.0F, 139.0F, 138.0F,
  137.0F, 136.0F, 135.0F, 134.0F, 133.0F, 132.0F, 131.0F, 130.0F, 129.0F, 128.0F,
  127.0F, 126.0F, 125.0F, 124.0F, 123.0F, 122.0F, 121.0F, 120.0F, 119.0F, 118.0F,
  117.0F, 116.0F, 115.0F, 114.0F, 113.0F, 112.0F, 111.0F, 110.0F, 109.0F, 108.0F,
  107.0F, 106.0F, 105.0F, 104.0F, 103.0F, 102.0F, 101.0F, 100.0F, 99.0F, 98.0F,
  97.0F, 96.0F, 95.0F, 94.0F, 93.0F, 92.0F, 91.0F, 90.0F, 89.0F, 88.0F, 87.0F,
  86.0F, 85.0F, 84.0F, 83.0F, 82.0F, 81.0F, 80.0F, 79.0F, 78.0F, 77.0F, 76.0F,
  75.0F, 74.0F, 73.0F, 72.0F, 71.0F, 70.0F, 69.0F, 68.0F, 67.0F, 66.0F, 65.0F,
  64.0F, 63.0F, 62.0F, 61.0F, 60.0F, 59.0F, 58.0F, 57.0F, 56.0F, 55.0F, 54.0F,
  53.0F, 52.0F, 51.0F, 50.0F, 49.0F, 48.0F, 47.0F, 46.0F, 45.0F, 44.0F, 43.0F,
  42.0F, 41.0F, 40.0F, 39.0F, 38.0F, 37.0F, 36.0F, 35.0F, 34.0F, 33.0F, 32.0F,
  31.0F, 30.0F, 29.0F, 28.0F, 27.0F, 26.0F, 25.0F, 24.0F, 23.0F, 22.0F, 21.0F,
  20.0F, 19.0F, 18.0F, 17.0F, 16.0F, 15.0F, 14.0F, 13.0F, 12.0F, 11.0F, 10.0F,
  9.0F, 8.0F, 7.0F, 6.0F, 5.0F, 4.0F, 3.0F, 2.0F, 1.0F, 0.0F, -1.0F, -2.0F,
  -3.0F, -4.0F, -5.0F, -6.0F, -7.0F, -8.0F, -9.0F, -10.0F, -11.0F, -12.0F,
  -13.0F, -14.0F, -15.0F, -16.0F, -17.0F, -18.0F, -19.0F, -20.0F, -21.0F, -22.0F,
  -23.0F, -24.0F, -25.0F, -26.0F, -27.0F, -28.0F, -29.0F, -30.0F, -31.0F, -32.0F,
  -33.0F, -34.0F, -35.0F, -36.0F, -37.0F, -38.0F, -39.0F, -40.0F, -41.0F, -42.0F,
  -43.0F, -44.0F, -45.0F, -46.0F, -47.0F, -48.0F, -49.0F, -50.0F } ;
                      /* Referenced by: '<S42>/Interpolation Using Prelookup' */

volatile real32_T SGSA_UTIgbtPha123SampleTemp_A[44] = { 80.8F, 105.8F, 137.0F,
  175.5F, 222.4F, 278.8F, 345.6F, 423.7F, 513.8F, 615.9F, 729.9F, 855.2F, 990.6F,
  1134.3F, 1284.6F, 1439.0F, 1595.2F, 1750.7F, 1903.4F, 2051.3F, 2192.9F,
  2326.8F, 2452.2F, 2568.8F, 2676.1F, 2774.5F, 2864.0F, 2945.2F, 3018.5F,
  3084.5F, 3143.8F, 3197.0F, 3244.6F, 3287.3F, 3321.0F, 3359.6F, 3385.0F,
  3410.0F, 3435.0F, 3457.0F, 3480.0F, 3495.0F, 3510.0F, 3525.0F } ;/* Referenced by:
                                                                    * '<S18>/Prelookup'
                                                                    * '<S19>/Prelookup'
                                                                    * '<S20>/Prelookup'
                                                                    */

volatile real32_T SGSA_UTIgbtPha123Table_M[44] = { -40.0F, -35.0F, -30.0F,
  -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F,
  30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 65.0F, 70.0F, 75.0F, 80.0F,
  85.0F, 90.0F, 95.0F, 100.0F, 105.0F, 110.0F, 115.0F, 120.0F, 125.0F, 130.0F,
  135.0F, 140.0F, 145.0F, 150.0F, 155.0F, 160.0F, 165.0F, 170.0F, 175.0F } ;/* Referenced by:
                                                                      * '<S18>/Interpolation Using Prelookup'
                                                                      * '<S19>/Interpolation Using Prelookup'
                                                                      * '<S20>/Interpolation Using Prelookup'
                                                                      */

volatile real32_T SGSA_UTMotSnsr1SampleHighTemp_A[301] = { 17.0F, 17.3F, 17.5F,
  17.8F, 18.1F, 18.3F, 18.6F, 18.9F, 19.2F, 19.5F, 19.8F, 20.1F, 20.4F, 20.7F,
  21.0F, 21.4F, 21.7F, 22.0F, 22.4F, 22.7F, 23.1F, 23.5F, 23.9F, 24.2F, 24.6F,
  25.0F, 25.4F, 25.9F, 26.3F, 26.7F, 27.1F, 27.6F, 28.0F, 28.5F, 29.0F, 29.5F,
  30.0F, 30.5F, 31.0F, 31.5F, 32.0F, 32.6F, 33.2F, 33.7F, 34.3F, 34.9F, 35.5F,
  36.1F, 36.7F, 37.4F, 38.0F, 38.7F, 39.4F, 40.1F, 40.8F, 41.6F, 42.3F, 43.1F,
  43.8F, 44.6F, 45.5F, 46.3F, 47.1F, 48.0F, 48.9F, 49.8F, 50.8F, 51.7F, 52.7F,
  53.7F, 54.7F, 55.7F, 56.8F, 57.9F, 59.0F, 60.2F, 61.3F, 62.5F, 63.8F, 65.0F,
  66.3F, 67.6F, 68.9F, 70.3F, 71.7F, 73.2F, 74.7F, 76.1F, 77.7F, 79.3F, 80.9F,
  82.6F, 84.3F, 86.0F, 87.8F, 89.7F, 91.6F, 93.5F, 95.4F, 97.5F, 99.5F, 101.7F,
  103.9F, 106.1F, 108.4F, 110.7F, 113.1F, 115.6F, 118.1F, 120.7F, 123.4F, 126.1F,
  128.9F, 131.8F, 134.7F, 137.7F, 140.8F, 144.0F, 147.3F, 150.6F, 154.0F, 157.6F,
  161.2F, 164.9F, 168.7F, 172.6F, 176.6F, 180.7F, 184.9F, 189.2F, 193.6F, 198.2F,
  202.9F, 207.6F, 212.6F, 217.6F, 222.8F, 228.1F, 233.6F, 239.2F, 244.9F, 250.8F,
  256.9F, 263.1F, 269.5F, 276.0F, 282.8F, 289.6F, 296.8F, 303.9F, 311.4F, 319.2F,
  327.0F, 334.9F, 343.4F, 351.9F, 360.5F, 369.7F, 378.8F, 388.1F, 397.9F, 407.9F,
  418.0F, 428.4F, 439.3F, 450.3F, 461.5F, 473.1F, 485.1F, 497.3F, 509.9F, 522.7F,
  535.8F, 549.3F, 563.2F, 577.4F, 592.2F, 607.2F, 622.4F, 638.2F, 654.3F, 670.9F,
  687.7F, 705.1F, 722.9F, 741.2F, 759.9F, 779.0F, 798.5F, 818.6F, 839.0F, 860.0F,
  881.7F, 903.6F, 926.1F, 949.1F, 972.5F, 996.5F, 1021.0F, 1046.2F, 1071.8F,
  1097.9F, 1124.6F, 1151.9F, 1179.6F, 1207.9F, 1236.7F, 1266.2F, 1296.1F,
  1326.7F, 1357.7F, 1389.3F, 1421.4F, 1454.0F, 1487.1F, 1520.8F, 1554.9F,
  1589.6F, 1624.7F, 1660.3F, 1696.4F, 1732.9F, 1769.8F, 1807.1F, 1844.8F,
  1882.9F, 1921.3F, 1960.0F, 1999.0F, 2038.2F, 2077.8F, 2117.5F, 2157.5F,
  2197.6F, 2237.8F, 2278.2F, 2318.5F, 2359.0F, 2399.4F, 2439.8F, 2480.1F,
  2520.3F, 2560.4F, 2600.3F, 2640.1F, 2679.5F, 2718.7F, 2757.7F, 2796.2F,
  2834.4F, 2872.2F, 2909.7F, 2946.6F, 2983.0F, 3019.0F, 3054.4F, 3089.2F,
  3123.5F, 3157.1F, 3190.2F, 3222.6F, 3254.3F, 3285.4F, 3315.8F, 3345.5F,
  3374.5F, 3402.8F, 3430.4F, 3457.2F, 3483.3F, 3508.7F, 3533.4F, 3557.3F,
  3580.6F, 3603.1F, 3624.9F, 3645.9F, 3666.3F, 3686.0F, 3704.9F, 3723.3F,
  3740.9F, 3757.9F, 3774.3F, 3790.1F, 3805.2F, 3819.7F, 3833.6F, 3847.0F,
  3859.8F, 3872.1F, 3883.9F, 3895.1F, 3905.9F, 3916.1F, 3925.9F, 3935.3F,
  3944.2F, 3952.7F, 3960.8F, 3990.0F } ;/* Referenced by: '<S42>/Prelookup' */

#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T SGSA_BatteryVoltGain_C = 0.0067765F;/* Referenced by: '<S34>/Constant' */

/* Battery voltage sensor gain calibration */
volatile real32_T SGSA_BatteryVoltOffset_C = 0.0F;/* Referenced by: '<S35>/Constant' */

/* Battery voltage sensor offset calibration */
volatile uint8_T SGSA_ClrHWFaultEnable_C = 0U;/* Referenced by: '<S75>/Constant' */
volatile boolean_T SGSA_ClrHWFault_C = false;/* Referenced by: '<S74>/Constant' */
volatile real32_T SGSA_DcLinkVoltGain_C = 0.159399599F;/* Referenced by: '<S55>/Constant' */

/* DC-link voltage sensor gain calibration */
volatile real32_T SGSA_DcLinkVoltOffset_C = 0.0F;/* Referenced by: '<S56>/Constant' */

/* DC-link voltage sensor offset calibration */
volatile real32_T SGSA_IgnitionAVoltGain_C = 1.0F;/* Referenced by: '<S30>/Constant' */
volatile real32_T SGSA_IgnitionAVoltOffset_C = 0.0F;/* Referenced by: '<S27>/Constant' */
volatile real32_T SGSA_IgnitionBVoltGain_C = 1.0F;/* Referenced by: '<S31>/Constant' */
volatile real32_T SGSA_IgnitionBVoltOffset_C = 0.0F;/* Referenced by: '<S32>/Constant' */
volatile real32_T SGSA_IgnitionCVoltGain_C = 1.0F;/* Referenced by: '<S28>/Constant' */

/* Ignition voltage sensor gain calibration */
volatile real32_T SGSA_IgnitionCVoltOffset_C = 0.0F;/* Referenced by: '<S29>/Constant' */

/* Ignition voltage sensor offset calibration */
volatile real32_T SGSA_KL15VoltGain_C = 0.0067765F;/* Referenced by: '<S37>/Constant' */
volatile real32_T SGSA_Kl15VoltOffset_C = 0.0F;/* Referenced by: '<S38>/Constant' */
volatile real32_T SGSA_MotorInitAngleOffset_C = 0.0F;/* Referenced by: '<S67>/Constant' */

/* Initial angle offset for motor alignment */
volatile real32_T SGSA_MotorTempGain_C = 1.0F;/* Referenced by: '<S46>/Constant' */

/* Motor temperature sensor gain calibration */
volatile real32_T SGSA_MotorTempOffset_C = 0.0F;/* Referenced by: '<S45>/Constant' */

/* Motor temperature sensor offset calibration */
volatile real32_T SGSA_PhaseACurrentGain_C = 0.610351562F;/* Referenced by: '<S63>/Constant' */

/* Phase A current sensor gain calibration value */
volatile real32_T SGSA_PhaseAPwmDuty_C = 50.0F;/* Referenced by: '<S87>/Constant' */

/* Phase A PWM duty cycle parameter setpoint */
volatile real32_T SGSA_PhaseBPwmDuty_C = 50.0F;/* Referenced by: '<S84>/Constant' */

/* Phase B PWM duty cycle parameter setpoint */
volatile real32_T SGSA_PhaseCCurrentGain_C = 0.610351562F;/* Referenced by: '<S64>/Constant' */
volatile real32_T SGSA_PhaseCPwmDuty_C = 50.0F;/* Referenced by: '<S85>/Constant' */

/* Phase C PWM duty cycle parameter setpoint */
volatile real32_T SGSA_PowerChipVoltGain_C = 0.002442F;/* Referenced by: '<S40>/Constant' */

/* Battery voltage sensor gain calibration */
volatile real32_T SGSA_PowerChipVoltOffset_C = 0.0F;/* Referenced by: '<S41>/Constant' */
volatile uint8_T SGSA_PwmParamEnable_C = 0U;/* Referenced by: '<S86>/Constant' */

/* Enable flag for PWM parameter setpoint mode */
volatile uint8_T SGSA_SetDriverStsEnable_C = 0U;/* Referenced by: '<S77>/Constant' */
volatile uint8_T SGSA_SetDriverSts_C = 0U;/* Referenced by: '<S76>/Constant' */
volatile uint8_T SGSA_SetFreqEnable_C = 0U;/* Referenced by: '<S83>/Constant' */
volatile real32_T SGSA_SetFreq_C = 0.0F;/* Referenced by: '<S82>/Constant' */
volatile uint8_T SGSA_SetHighASCFlgEnable_C = 0U;/* Referenced by: '<S79>/Constant' */
volatile uint8_T SGSA_SetHighASCFlg_C = 0U;/* Referenced by: '<S78>/Constant' */
volatile uint8_T SGSA_SetPwrOffDlyFlgEnable_C = 0U;/* Referenced by: '<S89>/Constant' */
volatile boolean_T SGSA_SetPwrOffDlyFlg_C = true;/* Referenced by: '<S88>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T HWAL_AdcIAZero;               /* Phase A current ADC raw value */
real32_T HWAL_AdcICZero;               /* Phase A current ADC raw value */
real32_T HWAL_BatteryVoltAdc;         /* Battery supply voltage ADC raw value */
real32_T HWAL_DcLinkVoltAdc;           /* DC-link voltage ADC raw value */
real32_T HWAL_DcLinkVoltAdcBkUp;       /* DC-link voltage ADC raw value */
real32_T HWAL_IgnitionVoltAdc;       /* Ignition supply voltage ADC raw value */
real32_T HWAL_MotorTempAdc;            /* Motor temperature ADC raw value */
real32_T HWAL_MotorTempAdcBkUp;        /* Motor temperature ADC raw value */
real32_T HWAL_PhaseACurrentAdc;        /* Phase A current ADC raw value */
real32_T HWAL_PhaseACurrentAdcBkUp;    /* Phase A current ADC raw value */
real32_T HWAL_PhaseASwitchTempAdc;
                            /* Phase A power switch temperature ADC raw value */
real32_T HWAL_PhaseASwitchTempAdcBkUp;
                            /* Phase A power switch temperature ADC raw value */
real32_T HWAL_PhaseBSwitchTempAdc;
                            /* Phase B power switch temperature ADC raw value */
real32_T HWAL_PhaseBSwitchTempAdcBkUp;
                            /* Phase A power switch temperature ADC raw value */
real32_T HWAL_PhaseCCurrentAdc;        /* Phase C current ADC raw value */
real32_T HWAL_PhaseCCurrentAdcBkUp;    /* Phase A current ADC raw value */
real32_T HWAL_PhaseCSwitchTempAdc;
                            /* Phase C power switch temperature ADC raw value */
real32_T HWAL_PhaseCSwitchTempAdcBkUp;
                            /* Phase A power switch temperature ADC raw value */
real32_T HWAL_PowerChipVoltAdc;       /* Battery supply voltage ADC raw value */
real32_T SGSA_BatteryVolt;             /* '<S5>/Product1' */

/* Battery supply voltage measurement */
real32_T SGSA_DcLinkVoltMeas;          /* '<S47>/Product' */

/* DC-link voltage measurement */
real32_T SGSA_DcLinkVoltMeasAD;        /* '<S47>/Gain2' */

/* DC-link voltage measurement AD */
uint8_T SGSA_DriveErr;                 /* '<S8>/Data Type Conversion1' */
real32_T SGSA_ElecAngle;               /* '<S66>/Switch' */

/* Electrical rotor angle */
uint8_T SGSA_HDriFault;                /* '<S8>/Data Type Conversion' */
uint8_T SGSA_HwOvercurSt;              /* '<S14>/Data Type Conversion1' */
uint8_T SGSA_HwOvervoltSt;             /* '<S14>/Data Type Conversion' */
real32_T SGSA_IgnitionVolt;            /* '<S6>/Product2' */

/* Ignition supply voltage measurement */
uint8_T SGSA_LDriFault;                /* '<S8>/Data Type Conversion2' */
real32_T SGSA_MotorTemp1;            /* '<S42>/Interpolation Using Prelookup' */

/* Motor temperature sensor 1 reading */
real32_T SGSA_MotorTemp1AD;            /* '<S17>/Gain1' */

/* Motor temperature sensor 1 reading */
uint8_T SGSA_PWMSts;                   /* '<S51>/Chart' */

/* PWM State */
real32_T SGSA_PhaseACurrent;           /* '<S50>/Product' */

/* Phase A current measurement */
real32_T SGSA_PhaseACurrentAD;         /* '<S50>/Gain1' */

/* Phase C current measurement */
real32_T SGSA_PhaseASwitchTemp;      /* '<S18>/Interpolation Using Prelookup' */

/* Phase A power switch temperature measurement */
real32_T SGSA_PhaseASwitchTempAD;      /* '<S4>/Gain1' */

/* Phase A power switch temperature measurement */
real32_T SGSA_PhaseBSwitchTemp;      /* '<S19>/Interpolation Using Prelookup' */

/* Phase B power switch temperature measurement */
real32_T SGSA_PhaseBSwitchTempAD;      /* '<S4>/Gain2' */

/* Phase A power switch temperature measurement */
real32_T SGSA_PhaseCCurrent;           /* '<S50>/Product2' */

/* Phase C current measurement */
real32_T SGSA_PhaseCCurrentAD;         /* '<S50>/Gain2' */

/* Phase C current measurement */
real32_T SGSA_PhaseCSwitchTemp;      /* '<S20>/Interpolation Using Prelookup' */

/* Phase C power switch temperature measurement */
real32_T SGSA_PhaseCSwitchTempAD;      /* '<S4>/Gain3' */

/* Phase A power switch temperature measurement */
real32_T SGSA_PwrChipVolt;             /* '<S7>/Product1' */
uint8_T SGSA_ResolverError;            /* '<S2>/SGRD_ResolverErr' */

/* Resolver fault detection status */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Block signals (default storage) */
B_SigSignalAdapter_T SigSignalAdapter_B;

/* Real-time model */
static RT_MODEL_SigSignalAdapter_T SigSignalAdapter_M_;
RT_MODEL_SigSignalAdapter_T *const SigSignalAdapter_M = &SigSignalAdapter_M_;

/* Model step function */
#define MTRCTRL_START_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
void SGSA_ReadTempVolt_1ms(void)
{
  int32_T rtb_DataTypeConversion6;
  real32_T rtb_Prelookup_o2_g;
  real32_T rtb_Prelookup_o2_j;
  uint32_T rtb_Prelookup_o1;
  uint16_T rtb_Hal_ReadHDirUVFault;
  uint16_T rtb_Hal_ReadHDriDeSatFault;
  uint16_T rtb_Hal_ReadLDriDeSatFault;
  uint16_T rtb_Hal_ReadLDriUVFault;
  uint16_T rtb_Hal_ReadUHDriFault;
  uint16_T rtb_Hal_ReadULDriFault;
  uint16_T rtb_Hal_ReadVHDriFault;
  uint16_T rtb_Hal_ReadVLDriFault;
  uint16_T rtb_Hal_ReadWDriFault;
  uint16_T rtb_Hal_ReadWHDriFault;
  uint8_T rtb_Hal_GetHwOvercurSt;
  uint8_T rtb_Hal_GetHwOvercurSt1;
  uint8_T rtb_Hal_GetHwOvercurSt2;
  uint8_T rtb_Hal_GetHwOvervoltSt;
  uint8_T rtb_Hal_GetHwOvervoltSt1;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGSA_ReadTempVolt_1ms' incorporates:
   *  SubSystem: '<Root>/SGSA_ReadTempVolt_1ms_sys'
   */
  /* FunctionCaller: '<S9>/Hal_ReadMotorTempAdc' */
  rtb_Hal_ReadWHDriFault = Hal_ReadMotorTempAdc();

  /* FunctionCaller: '<S9>/Hal_ReadStatorTempAdcBkUp' */
  rtb_Hal_ReadVHDriFault = Hal_ReadMotorTempAdcBkUp();

  /* Sum: '<S9>/Add' */
  rtb_DataTypeConversion6 = rtb_Hal_ReadWHDriFault - rtb_Hal_ReadVHDriFault;
  if (rtb_DataTypeConversion6 < 0) {
    rtb_DataTypeConversion6 = 0;
  }

  /* DataTypeConversion: '<S17>/Data Type Conversion3' incorporates:
   *  DataStoreWrite: '<S44>/Data Store Write'
   *  Sum: '<S9>/Add'
   */
  HWAL_MotorTempAdc = (real32_T)rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S17>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S43>/Data Store Write'
   */
  HWAL_MotorTempAdcBkUp = (real32_T)rtb_Hal_ReadWHDriFault;

  /* Product: '<S17>/Product3' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  DataStoreWrite: '<S44>/Data Store Write'
   *  Sum: '<S17>/Add3'
   */
  rtb_Prelookup_o2_j = (HWAL_MotorTempAdc - SGSA_MotorTempOffset_C) *
    SGSA_MotorTempGain_C;

  /* PreLookup: '<S42>/Prelookup' */
  rtb_Prelookup_o1 = plook_u32ff_binx(rtb_Prelookup_o2_j, (real32_T *)
    &SGSA_UTMotSnsr1SampleHighTemp_A[0], 300U, &rtb_Prelookup_o2_j);

  /* Interpolation_n-D: '<S42>/Interpolation Using Prelookup' */
  SGSA_MotorTemp1 = intrp1d_fu32fl(rtb_Prelookup_o1, rtb_Prelookup_o2_j,
    (real32_T *)&SGSA_TMotSnsr1TableHigh_M[0]);

  /* Gain: '<S17>/Gain1' incorporates:
   *  DataStoreWrite: '<S43>/Data Store Write'
   */
  SGSA_MotorTemp1AD = 0.00122070312F * HWAL_MotorTempAdcBkUp;

  /* FunctionCaller: '<S10>/Hal_ReadSwitchTempAdc1' */
  rtb_Hal_ReadUHDriFault = Hal_ReadSwitchTempAdc1();

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  rtb_Prelookup_o2_j = rtb_Hal_ReadUHDriFault;

  /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  HWAL_PhaseASwitchTempAdc = (real32_T)rtb_Hal_ReadUHDriFault;

  /* DataTypeConversion: '<S4>/Data Type Conversion6' */
  rtb_DataTypeConversion6 = rtb_Hal_ReadUHDriFault;

  /* DataStoreWrite: '<S24>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  HWAL_PhaseASwitchTempAdcBkUp = (real32_T)rtb_Hal_ReadUHDriFault;

  /* FunctionCaller: '<S10>/Hal_ReadSwitchTempAdc2' */
  rtb_Hal_ReadUHDriFault = Hal_ReadSwitchTempAdc2();

  /* DataTypeConversion: '<S4>/Data Type Conversion4' */
  rtb_Prelookup_o2_g = rtb_Hal_ReadUHDriFault;

  /* DataStoreWrite: '<S22>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   */
  HWAL_PhaseBSwitchTempAdc = (real32_T)rtb_Hal_ReadUHDriFault;

  /* DataStoreWrite: '<S25>/Data Store Write' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   */
  HWAL_PhaseBSwitchTempAdcBkUp = (real32_T)rtb_Hal_ReadUHDriFault;

  /* FunctionCaller: '<S10>/Hal_ReadSwitchTempAdc3' */
  rtb_Hal_ReadUHDriFault = Hal_ReadSwitchTempAdc3();

  /* DataTypeConversion: '<S4>/Data Type Conversion5' incorporates:
   *  DataStoreWrite: '<S23>/Data Store Write'
   */
  HWAL_PhaseCSwitchTempAdc = (real32_T)rtb_Hal_ReadUHDriFault;

  /* DataTypeConversion: '<S4>/Data Type Conversion8' incorporates:
   *  DataStoreWrite: '<S26>/Data Store Write'
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   */
  HWAL_PhaseCSwitchTempAdcBkUp = (real32_T)rtb_Hal_ReadUHDriFault;

  /* Product: '<S4>/Product3' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S30>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   *  Sum: '<S4>/Add3'
   */
  rtb_Prelookup_o2_j = (rtb_Prelookup_o2_j - SGSA_IgnitionAVoltOffset_C) *
    SGSA_IgnitionAVoltGain_C;

  /* PreLookup: '<S18>/Prelookup' */
  rtb_Prelookup_o1 = plook_u32ff_binx(rtb_Prelookup_o2_j, (real32_T *)
    &SGSA_UTIgbtPha123SampleTemp_A[0], 43U, &rtb_Prelookup_o2_j);

  /* Interpolation_n-D: '<S18>/Interpolation Using Prelookup' */
  SGSA_PhaseASwitchTemp = intrp1d_fu32fl(rtb_Prelookup_o1, rtb_Prelookup_o2_j,
    (real32_T *)&SGSA_UTIgbtPha123Table_M[0]);

  /* Gain: '<S4>/Gain1' */
  SGSA_PhaseASwitchTempAD = 0.00122070312F * (real32_T)rtb_DataTypeConversion6;

  /* Product: '<S4>/Product4' incorporates:
   *  Constant: '<S31>/Constant'
   *  Constant: '<S32>/Constant'
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   *  Sum: '<S4>/Add4'
   */
  rtb_Prelookup_o2_j = (rtb_Prelookup_o2_g - SGSA_IgnitionBVoltOffset_C) *
    SGSA_IgnitionBVoltGain_C;

  /* PreLookup: '<S19>/Prelookup' */
  rtb_Prelookup_o1 = plook_u32ff_binx(rtb_Prelookup_o2_j, (real32_T *)
    &SGSA_UTIgbtPha123SampleTemp_A[0], 43U, &rtb_Prelookup_o2_j);

  /* Interpolation_n-D: '<S19>/Interpolation Using Prelookup' */
  SGSA_PhaseBSwitchTemp = intrp1d_fu32fl(rtb_Prelookup_o1, rtb_Prelookup_o2_j,
    (real32_T *)&SGSA_UTIgbtPha123Table_M[0]);

  /* Gain: '<S4>/Gain2' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   */
  SGSA_PhaseBSwitchTempAD = 0.00122070312F * rtb_Prelookup_o2_g;

  /* Product: '<S4>/Product5' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  DataStoreWrite: '<S23>/Data Store Write'
   *  Sum: '<S4>/Add5'
   */
  rtb_Prelookup_o2_g = (HWAL_PhaseCSwitchTempAdc - SGSA_IgnitionCVoltOffset_C) *
    SGSA_IgnitionCVoltGain_C;

  /* PreLookup: '<S20>/Prelookup' */
  rtb_Prelookup_o1 = plook_u32ff_binx(rtb_Prelookup_o2_g, (real32_T *)
    &SGSA_UTIgbtPha123SampleTemp_A[0], 43U, &rtb_Prelookup_o2_g);

  /* Interpolation_n-D: '<S20>/Interpolation Using Prelookup' */
  SGSA_PhaseCSwitchTemp = intrp1d_fu32fl(rtb_Prelookup_o1, rtb_Prelookup_o2_g,
    (real32_T *)&SGSA_UTIgbtPha123Table_M[0]);

  /* Gain: '<S4>/Gain3' incorporates:
   *  DataStoreWrite: '<S26>/Data Store Write'
   */
  SGSA_PhaseCSwitchTempAD = 0.00122070312F * HWAL_PhaseCSwitchTempAdcBkUp;

  /* FunctionCaller: '<S16>/Hal_ReadStatorTempAdc' */
  rtb_Hal_ReadUHDriFault = Hal_ReadPowerChipVoltageAdc();

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S39>/Data Store Write'
   */
  HWAL_PowerChipVoltAdc = (real32_T)rtb_Hal_ReadUHDriFault;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S40>/Constant'
   *  Constant: '<S41>/Constant'
   *  DataStoreWrite: '<S39>/Data Store Write'
   *  Sum: '<S7>/Add1'
   */
  SGSA_PwrChipVolt = (HWAL_PowerChipVoltAdc - SGSA_PowerChipVoltOffset_C) *
    SGSA_PowerChipVoltGain_C;

  /* FunctionCaller: '<S11>/Hal_ReadBatteryVoltageAdc' */
  rtb_Hal_ReadUHDriFault = Hal_ReadBatteryVoltageAdc();

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S33>/Data Store Write'
   */
  HWAL_BatteryVoltAdc = (real32_T)rtb_Hal_ReadUHDriFault;

  /* Product: '<S5>/Product1' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S35>/Constant'
   *  DataStoreWrite: '<S33>/Data Store Write'
   *  Sum: '<S5>/Add1'
   */
  SGSA_BatteryVolt = (HWAL_BatteryVoltAdc - SGSA_BatteryVoltOffset_C) *
    SGSA_BatteryVoltGain_C;

  /* FunctionCaller: '<S13>/Hal_ReadIgnitionVoltageAdc' */
  rtb_Hal_ReadUHDriFault = Hal_ReadIgnitionVoltageAdc();

  /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
   *  DataStoreWrite: '<S36>/Data Store Write'
   */
  HWAL_IgnitionVoltAdc = (real32_T)rtb_Hal_ReadUHDriFault;

  /* Product: '<S6>/Product2' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  DataStoreWrite: '<S36>/Data Store Write'
   *  Sum: '<S6>/Add2'
   */
  SGSA_IgnitionVolt = (HWAL_IgnitionVoltAdc - SGSA_Kl15VoltOffset_C) *
    SGSA_KL15VoltGain_C;

  /* FunctionCaller: '<S12>/Hal_GetHwOvervoltSt' */
  rtb_Hal_GetHwOvervoltSt = Hal_GetHwOvervoltSt();

  /* FunctionCaller: '<S12>/Hal_GetHwOvervoltSt1' */
  rtb_Hal_GetHwOvervoltSt1 = Hal_GetHwOvervoltSt1();

  /* FunctionCaller: '<S12>/Hal_GetHwOvercurSt' */
  rtb_Hal_GetHwOvercurSt = Hal_GetHwOvercurSt();

  /* FunctionCaller: '<S12>/Hal_GetHwOvercurSt1' */
  rtb_Hal_GetHwOvercurSt1 = Hal_GetHwOvercurSt1();

  /* FunctionCaller: '<S12>/Hal_GetHwOvercurSt2' */
  rtb_Hal_GetHwOvercurSt2 = Hal_GetHwOvercurSt2();

  /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
   *  Logic: '<S14>/OR'
   */
  SGSA_HwOvervoltSt = (uint8_T)((rtb_Hal_GetHwOvervoltSt != 0) ||
    (rtb_Hal_GetHwOvervoltSt1 != 0));

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Logic: '<S14>/OR1'
   */
  SGSA_HwOvercurSt = (uint8_T)((rtb_Hal_GetHwOvercurSt != 0) ||
    (rtb_Hal_GetHwOvercurSt1 != 0) || (rtb_Hal_GetHwOvercurSt2 != 0));

  /* FunctionCaller: '<S15>/Hal_ReadUHDriFault' */
  rtb_Hal_ReadUHDriFault = Hal_ReadUHDriFault();

  /* FunctionCaller: '<S15>/Hal_ReadVHDriFault' */
  rtb_Hal_ReadVHDriFault = Hal_ReadVHDriFault();

  /* FunctionCaller: '<S15>/Hal_ReadWHDriFault' */
  rtb_Hal_ReadWHDriFault = Hal_ReadWHDriFault();

  /* FunctionCaller: '<S15>/Hal_ReadHDriDeSatFault' */
  rtb_Hal_ReadHDriDeSatFault = Hal_ReadHDriDeSatFault();

  /* FunctionCaller: '<S15>/Hal_ReadHDirUVFault' */
  rtb_Hal_ReadHDirUVFault = Hal_ReadHDirUVFault();

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Logic: '<S8>/OR'
   */
  SGSA_HDriFault = (uint8_T)((rtb_Hal_ReadUHDriFault != 0) ||
    (rtb_Hal_ReadVHDriFault != 0) || (rtb_Hal_ReadWHDriFault != 0) ||
    (rtb_Hal_ReadHDriDeSatFault != 0) || (rtb_Hal_ReadHDirUVFault != 0));

  /* FunctionCaller: '<S15>/Hal_ReadULDriFault' */
  rtb_Hal_ReadULDriFault = Hal_ReadULDriFault();

  /* FunctionCaller: '<S15>/Hal_ReadVLDriFault' */
  rtb_Hal_ReadVLDriFault = Hal_ReadVLDriFault();

  /* FunctionCaller: '<S15>/Hal_ReadWDriFault' */
  rtb_Hal_ReadWDriFault = Hal_ReadWLDriFault();

  /* FunctionCaller: '<S15>/Hal_ReadLDriDeSatFault' */
  rtb_Hal_ReadLDriDeSatFault = Hal_ReadLDriDeSatFault();

  /* FunctionCaller: '<S15>/Hal_ReadLDriUVFault' */
  rtb_Hal_ReadLDriUVFault = Hal_ReadLDriUVFault();

  /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
   *  Logic: '<S8>/Logical Operator'
   */
  SGSA_DriveErr = (uint8_T)((rtb_Hal_ReadUHDriFault != 0) ||
    (rtb_Hal_ReadULDriFault != 0) || (rtb_Hal_ReadVHDriFault != 0) ||
    (rtb_Hal_ReadVLDriFault != 0) || (rtb_Hal_ReadWHDriFault != 0) ||
    (rtb_Hal_ReadWDriFault != 0) || (rtb_Hal_ReadHDriDeSatFault != 0) ||
    (rtb_Hal_ReadLDriDeSatFault != 0) || (rtb_Hal_ReadHDirUVFault != 0) ||
    (rtb_Hal_ReadLDriUVFault != 0));

  /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
   *  Logic: '<S8>/OR1'
   */
  SGSA_LDriFault = (uint8_T)((rtb_Hal_ReadULDriFault != 0) ||
    (rtb_Hal_ReadVLDriFault != 0) || (rtb_Hal_ReadWDriFault != 0) ||
    (rtb_Hal_ReadLDriDeSatFault != 0) || (rtb_Hal_ReadLDriUVFault != 0));

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGSA_ReadTempVolt_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT
#include "MtrCtrl_MemMap.h"
/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void SGSA_Read_100us(void)
{
  int32_T rtb_DataTypeConversion_d;
  real32_T rtb_Add_p;
  real32_T rtb_Divide;
  real32_T rtb_Product1;
  uint16_T rtb_Hal_ReadDcBusVoltageAdc;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGSA_Read_100us' incorporates:
   *  SubSystem: '<Root>/SGSA_Read_100us_sys'
   */
  /* MinMax: '<S50>/Max' incorporates:
   *  Constant: '<S50>/Constant'
   */
  if ((SGSA_PwrChipVolt >= 2.0F) || rtIsNaNF(2.0F)) {
    rtb_Divide = SGSA_PwrChipVolt;
  } else {
    rtb_Divide = 2.0F;
  }

  /* Product: '<S50>/Divide' incorporates:
   *  Constant: '<S50>/Constant1'
   *  MinMax: '<S50>/Max'
   */
  rtb_Divide = 5.0F / rtb_Divide;

  /* FunctionCaller: '<S48>/Hal_ReadPhaseCurrentAdc1' */
  rtb_Hal_ReadDcBusVoltageAdc = Hal_ReadPhaseCurrentAdc1();

  /* DataTypeConversion: '<S50>/Data Type Conversion' */
  rtb_DataTypeConversion_d = rtb_Hal_ReadDcBusVoltageAdc;

  /* FunctionCaller: '<S48>/Hal_ReadUPhaZeroPointAD' */
  rtb_Hal_ReadDcBusVoltageAdc = Hal_ReadUPhaZeroPointAD();

  /* DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
   *  DataStoreWrite: '<S58>/Data Store Write'
   */
  HWAL_AdcIAZero = (real32_T)rtb_Hal_ReadDcBusVoltageAdc;

  /* Product: '<S50>/Product1' incorporates:
   *  DataStoreWrite: '<S58>/Data Store Write'
   *  Sum: '<S50>/Add'
   */
  rtb_Product1 = ((real32_T)rtb_DataTypeConversion_d - HWAL_AdcIAZero) *
    rtb_Divide;

  /* DataStoreWrite: '<S57>/Data Store Write' */
  HWAL_PhaseACurrentAdc = rtb_Product1;

  /* FunctionCaller: '<S48>/Hal_ReadPhaseCurrentAdc3' */
  rtb_Hal_ReadDcBusVoltageAdc = Hal_ReadPhaseCurrentAdc3();

  /* DataTypeConversion: '<S50>/Data Type Conversion2' */
  rtb_Add_p = rtb_Hal_ReadDcBusVoltageAdc;

  /* FunctionCaller: '<S48>/Hal_ReadWPhaZeroPointAD' */
  rtb_Hal_ReadDcBusVoltageAdc = Hal_ReadWPhaZeroPointAD();

  /* DataTypeConversion: '<S50>/Data Type Conversion4' incorporates:
   *  DataStoreWrite: '<S61>/Data Store Write'
   */
  HWAL_AdcICZero = (real32_T)rtb_Hal_ReadDcBusVoltageAdc;

  /* Product: '<S50>/Product3' incorporates:
   *  DataStoreWrite: '<S59>/Data Store Write'
   *  DataStoreWrite: '<S61>/Data Store Write'
   *  Sum: '<S50>/Add2'
   */
  HWAL_PhaseCCurrentAdc = (rtb_Add_p - HWAL_AdcICZero) * rtb_Divide;

  /* DataStoreWrite: '<S60>/Data Store Write' */
  HWAL_PhaseACurrentAdcBkUp = (real32_T)rtb_DataTypeConversion_d;

  /* DataStoreWrite: '<S62>/Data Store Write' */
  HWAL_PhaseCCurrentAdcBkUp = rtb_Add_p;

  /* Gain: '<S50>/Gain1' */
  SGSA_PhaseACurrentAD = 0.00122070312F * (real32_T)rtb_DataTypeConversion_d;

  /* Gain: '<S50>/Gain2' */
  SGSA_PhaseCCurrentAD = 0.00122070312F * rtb_Add_p;

  /* Product: '<S50>/Product' incorporates:
   *  Constant: '<S63>/Constant'
   */
  SGSA_PhaseACurrent = rtb_Product1 * SGSA_PhaseACurrentGain_C;

  /* Product: '<S50>/Product2' incorporates:
   *  Constant: '<S64>/Constant'
   *  DataStoreWrite: '<S59>/Data Store Write'
   */
  SGSA_PhaseCCurrent = HWAL_PhaseCCurrentAdc * SGSA_PhaseCCurrentGain_C;

  /* FunctionCaller: '<S49>/Hal_ReadDcBusVoltageAdc' */
  rtb_Hal_ReadDcBusVoltageAdc = Hal_ReadDcBusVoltageAdc();

  /* DataTypeConversion: '<S47>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S53>/Data Store Write'
   */
  HWAL_DcLinkVoltAdc = (real32_T)rtb_Hal_ReadDcBusVoltageAdc;

  /* DataTypeConversion: '<S47>/Data Type Conversion9' incorporates:
   *  DataStoreWrite: '<S54>/Data Store Write'
   *  DataTypeConversion: '<S47>/Data Type Conversion'
   */
  HWAL_DcLinkVoltAdcBkUp = (real32_T)rtb_Hal_ReadDcBusVoltageAdc;

  /* Product: '<S47>/Product' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  DataStoreWrite: '<S53>/Data Store Write'
   *  Sum: '<S47>/Add'
   */
  SGSA_DcLinkVoltMeas = (HWAL_DcLinkVoltAdc - SGSA_DcLinkVoltOffset_C) *
    SGSA_DcLinkVoltGain_C;

  /* Gain: '<S47>/Gain2' incorporates:
   *  DataStoreWrite: '<S54>/Data Store Write'
   */
  SGSA_DcLinkVoltMeasAD = 0.00122070312F * HWAL_DcLinkVoltAdcBkUp;

  /* Sum: '<S52>/Add' incorporates:
   *  Constant: '<S67>/Constant'
   *  Inport: '<Root>/SGRD_ElecAngle'
   */
  rtb_Add_p = SGRD_ElecAngle + SGSA_MotorInitAngleOffset_C;

  /* DataTypeConversion: '<S66>/Data Type Conversion' incorporates:
   *  Constant: '<S66>/Constant'
   *  Product: '<S66>/Product'
   */
  rtb_Divide = 0.159154937F * rtb_Add_p;
  if (rtb_Divide < 2.14748365E+9F) {
    if (rtb_Divide >= -2.14748365E+9F) {
      rtb_DataTypeConversion_d = (int32_T)rtb_Divide;
    } else {
      rtb_DataTypeConversion_d = INT32_MIN;
    }
  } else {
    rtb_DataTypeConversion_d = INT32_MAX;
  }

  /* Sum: '<S66>/Add' incorporates:
   *  Constant: '<S66>/Constant1'
   *  DataTypeConversion: '<S66>/Data Type Conversion'
   *  Product: '<S66>/Product1'
   */
  SGSA_ElecAngle = rtb_Add_p - (real32_T)rtb_DataTypeConversion_d * 6.28318548F;

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant2'
   *  RelationalOperator: '<S66>/Relational Operator'
   */
  if (SGSA_ElecAngle < 0.0F) {
    /* Sum: '<S66>/Add' incorporates:
     *  Constant: '<S66>/Constant4'
     *  Sum: '<S66>/Add1'
     *  Switch: '<S66>/Switch'
     */
    SGSA_ElecAngle = 6.28318548F + SGSA_ElecAngle;
  }

  /* End of Switch: '<S66>/Switch' */

  /* SignalConversion generated from: '<S2>/SGRD_ResolverErr' incorporates:
   *  Inport: '<Root>/SGRD_ResolverErr'
   */
  SGSA_ResolverError = SGRD_ResolverErr;

  /* Chart: '<S51>/Chart' */
  if (SigSignalAdapter_B.Switch2 == 0) {
    SGSA_PWMSts = 0U;
  } else {
    switch (SigSignalAdapter_B.output) {
     case 2:
      SGSA_PWMSts = 1U;
      break;

     case 0:
      SGSA_PWMSts = 2U;
      break;

     default:
      SGSA_PWMSts = 3U;
      break;
    }
  }

  /* End of Chart: '<S51>/Chart' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGSA_Read_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void SGSA_WriteCommand_100us(void)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T tmp_1;
  uint8_T u0;
  boolean_T tmp_2;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SGSA_WriteCommand_100us' incorporates:
   *  SubSystem: '<Root>/SGSA_WriteCommand_100us_sys'
   */
  /* Outputs for Atomic SubSystem: '<S3>/Set High ASC Flag' */
  /* Chart: '<S80>/Chart' incorporates:
   *  Saturate: '<S70>/Saturation1'
   */
  switch (SGSA_HDriFault) {
   case 0:
    /* Switch: '<S70>/Switch2' incorporates:
     *  Constant: '<S78>/Constant'
     *  Constant: '<S79>/Constant'
     *  Inport: '<Root>/SGPP_SetHighASCFlg'
     */
    if (SGSA_SetHighASCFlgEnable_C != 0) {
      u0 = SGSA_SetHighASCFlg_C;
    } else {
      u0 = SGPP_SetHighASCFlg;
    }

    /* Saturate: '<S70>/Saturation1' incorporates:
     *  Switch: '<S70>/Switch2'
     */
    if (u0 > ((uint8_T)1U)) {
      u0 = ((uint8_T)1U);
    }

    if (u0 == 0) {
      SigSignalAdapter_B.output = 2U;
    } else {
      SigSignalAdapter_B.output = 0U;
    }
    break;

   case 1:
    /* Switch: '<S70>/Switch2' incorporates:
     *  Constant: '<S78>/Constant'
     *  Constant: '<S79>/Constant'
     *  Inport: '<Root>/SGPP_SetHighASCFlg'
     */
    if (SGSA_SetHighASCFlgEnable_C != 0) {
      u0 = SGSA_SetHighASCFlg_C;
    } else {
      u0 = SGPP_SetHighASCFlg;
    }

    /* Saturate: '<S70>/Saturation1' incorporates:
     *  Switch: '<S70>/Switch2'
     */
    if (u0 > ((uint8_T)1U)) {
      u0 = ((uint8_T)1U);
    }

    if (u0 == 0) {
      SigSignalAdapter_B.output = 2U;
    } else {
      SigSignalAdapter_B.output = 1U;
    }
    break;

   default:
    SigSignalAdapter_B.output = 2U;
    break;
  }

  /* End of Chart: '<S80>/Chart' */

  /* FunctionCaller: '<S70>/Hal_ConfigActiveShortCircuit' */
  Hal_ConfigActiveShortCircuit(SigSignalAdapter_B.output);

  /* End of Outputs for SubSystem: '<S3>/Set High ASC Flag' */

  /* Outputs for Atomic SubSystem: '<S3>/Set Driver State' */
  /* Switch: '<S69>/Switch2' incorporates:
   *  Constant: '<S77>/Constant'
   */
  if (SGSA_SetDriverStsEnable_C != 0) {
    /* Switch: '<S69>/Switch2' incorporates:
     *  Constant: '<S76>/Constant'
     */
    SigSignalAdapter_B.Switch2 = SGSA_SetDriverSts_C;
  } else {
    /* Switch: '<S69>/Switch2' incorporates:
     *  Inport: '<Root>/SGPP_SetDriverSts'
     */
    SigSignalAdapter_B.Switch2 = SGPP_SetDriverSts;
  }

  /* End of Switch: '<S69>/Switch2' */

  /* FunctionCaller: '<S69>/Hal_SetDriverCircuit' */
  Hal_SetDriverCircuit(SigSignalAdapter_B.Switch2);

  /* End of Outputs for SubSystem: '<S3>/Set Driver State' */

  /* Outputs for Atomic SubSystem: '<S3>/Set PWM Run' */
  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Inport: '<Root>/SGPP_PhaseADuty'
   *  Inport: '<Root>/SGPP_PhaseBDuty'
   *  Inport: '<Root>/SGPP_PhaseCDuty'
   *  Switch: '<S72>/Switch1'
   *  Switch: '<S72>/Switch2'
   */
  if (SGSA_PwmParamEnable_C != 0) {
    tmp = SGSA_PhaseAPwmDuty_C;
    tmp_0 = SGSA_PhaseBPwmDuty_C;
    tmp_1 = SGSA_PhaseCPwmDuty_C;
  } else {
    tmp = SGPP_PhaseADuty;
    tmp_0 = SGPP_PhaseBDuty;
    tmp_1 = SGPP_PhaseCDuty;
  }

  /* FunctionCaller: '<S72>/Hal_UpdatePwmDutyCycle' incorporates:
   *  Switch: '<S72>/Switch'
   *  Switch: '<S72>/Switch1'
   *  Switch: '<S72>/Switch2'
   */
  Hal_UpdatePwmDutyCycle(tmp, tmp_0, tmp_1);

  /* End of Outputs for SubSystem: '<S3>/Set PWM Run' */

  /* Outputs for Atomic SubSystem: '<S3>/Set PWM Frequency' */
  /* Switch: '<S71>/Switch2' incorporates:
   *  Constant: '<S82>/Constant'
   *  Constant: '<S83>/Constant'
   *  Inport: '<Root>/SGPP_SetFreq'
   */
  if (SGSA_SetFreqEnable_C != 0) {
    tmp = SGSA_SetFreq_C;
  } else {
    tmp = SGPP_SetFreq;
  }

  /* FunctionCaller: '<S71>/Hal_UpdatePwmFreqCycle' incorporates:
   *  Switch: '<S71>/Switch2'
   */
  Hal_UpdatePwmFreqCycle(tmp);

  /* End of Outputs for SubSystem: '<S3>/Set PWM Frequency' */

  /* Outputs for Atomic SubSystem: '<S3>/Clear HW Fault' */
  /* Switch: '<S68>/Switch2' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  Inport: '<Root>/SGPP_ClrHWFault'
   */
  if (SGSA_ClrHWFaultEnable_C != 0) {
    tmp_2 = SGSA_ClrHWFault_C;
  } else {
    tmp_2 = SGPP_ClrHWFault;
  }

  /* FunctionCaller: '<S68>/Hal_ClrHWFaultCycle' incorporates:
   *  Switch: '<S68>/Switch2'
   */
  Hal_ClrHWFaultCycle(tmp_2);

  /* End of Outputs for SubSystem: '<S3>/Clear HW Fault' */

  /* Outputs for Atomic SubSystem: '<S3>/Set Power Off Delay Flag' */
  /* Switch: '<S73>/Switch2' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Inport: '<Root>/SGPP_SetPwrOffDlyFlg'
   */
  if (SGSA_SetPwrOffDlyFlgEnable_C != 0) {
    tmp_2 = SGSA_SetPwrOffDlyFlg_C;
  } else {
    tmp_2 = SGPP_SetPwrOffDlyFlg;
  }

  /* FunctionCaller: '<S73>/SetPwrOffDlyFlg' incorporates:
   *  Switch: '<S73>/Switch2'
   */
  Hal_SetPwrOffDlyFlg(tmp_2);

  /* End of Outputs for SubSystem: '<S3>/Set Power Off Delay Flag' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SGSA_WriteCommand_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void SigSignalAdapter_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void SigSignalAdapter_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
