/*
 * File: McuFunSafeMonitor.c
 *
 * Code generated for Simulink model 'McuFunSafeMonitor'.
 *
 * Model version                  : 1.993
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Sep  5 08:33:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "McuFunSafeMonitor.h"
#include "Hal_ReadPwrChipVolt.h"
#include "Hal_ReadMotorTempAdc.h"
#include "Hal_ReadMotorTempAdcBkUp.h"
#include "Hal_ReadDcLinkVoltMeasAD.h"
#include <math.h>
#include "rtwtypes.h"
#include "Hal_ReadCosPosiLow.h"
#include "Hal_ReadCosPosiHigh.h"
#include "Hal_ReadCosNegHigh.h"
#include "Hal_ReadCosNegLow.h"
#include "Hal_ReadExcPosiLow.h"
#include "Hal_ReadExcNegHigh.h"
#include "Hal_ReadExcPosiHigh.h"
#include "Hal_ReadExcNegLow.h"
#include "Hal_ReadSinPosiHigh.h"
#include "Hal_ReadSinPosiLow.h"
#include "Hal_ReadSinNegHigh.h"
#include "Hal_ReadSinNegLow.h"
#include "Hal_ReadPhaseACurrentAD.h"
#include "Hal_ReadPhaseCCurrentAD.h"
#include "McuFunSafeMonitor_private.h"
#include "plook_u32ff_binx.h"
#include "intrp1d_fu32fl.h"

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile real32_T MFSM_BusCurrentCompCoeff_M[3] = { 0.0F, 0.0F, 0.0F } ;
                          /* Referenced by: '<S115>/Bus Current Coeff Lookup' */

volatile real32_T MFSM_BusCurrentComp_M[3] = { 0.0F, 0.0F, 0.0F } ;
             /* Referenced by: '<S116>/Bus Current Compensation Lookup Table' */

volatile real32_T MFSM_ElecSpd_A[3] = { 0.0F, 10000.0F, 20000.0F } ;/* Referenced by: '<S111>/Prelookup' */

volatile real32_T MFSM_LpfBusCurrent_A[3] = { 0.0F, 10000.0F, 20000.0F } ;/* Referenced by: '<S116>/Prelookup1' */

volatile real32_T MFSM_MechSpd_A[3] = { 0.0F, 10000.0F, 20000.0F } ;/* Referenced by: '<S115>/Prelookup' */

volatile real32_T MFSM_MtrEfficiency_M[3] = { 0.0F, 0.0F, 0.0F } ;
                       /* Referenced by: '<S111>/Mtr Efficiency Lookup Table' */

#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile real32_T MFSM_AmpHigh_C = 0.0F;/* Referenced by: '<S266>/Constant' */
volatile real32_T MFSM_AmpLow_C = 0.0F;/* Referenced by: '<S265>/Constant' */
volatile real32_T MFSM_BusCurDiff_C = 0.0F;/* Referenced by: '<S17>/Constant' */
volatile uint8_T MFSM_BusCurrentCalCoeffSel_C = 0U;/* Referenced by: '<S119>/Constant' */
volatile real32_T MFSM_BusCurrentCalCoeff_C = 0.0F;/* Referenced by: '<S118>/Constant' */
volatile uint8_T MFSM_BusCurrentCompEna_C = 0U;/* Referenced by: '<S120>/Constant' */
volatile real32_T MFSM_BusCurrentFilterFreq_C = 0.0F;/* Referenced by: '<S113>/Constant' */
volatile real32_T MFSM_CosShortGndValue_C = 0.0F;/* Referenced by: '<S134>/Constant' */
volatile real32_T MFSM_CosShortPwrValue_C = 0.0F;/* Referenced by: '<S143>/Constant' */
volatile uint8_T MFSM_DebounceDecrBusCurDiff_C = 0U;/* Referenced by: '<S20>/Constant' */
volatile uint8_T MFSM_DebounceDecrCosOpen_C = 0U;/* Referenced by: '<S127>/Constant' */
volatile uint8_T MFSM_DebounceDecrCosShortGnd_C = 0U;/* Referenced by: '<S137>/Constant' */
volatile uint8_T MFSM_DebounceDecrCosShortPwr_C = 0U;/* Referenced by: '<S146>/Constant' */
volatile uint8_T MFSM_DebounceDecrExcAmp_C = 0U;/* Referenced by: '<S154>/Constant' */
volatile uint8_T MFSM_DebounceDecrExcOpen_C = 0U;/* Referenced by: '<S170>/Constant' */
volatile uint8_T MFSM_DebounceDecrExcShortGnd_C = 0U;/* Referenced by:
                                                      * '<S180>/Constant'
                                                      * '<S189>/Constant'
                                                      */
volatile uint8_T MFSM_DebounceDecrHighVolt_C = 0U;/* Referenced by: '<S34>/Constant' */
volatile uint8_T MFSM_DebounceDecrMtrTempShortGnd_C = 0U;/* Referenced by: '<S53>/Constant' */
volatile uint8_T MFSM_DebounceDecrMtrTempShortPwr_C = 0U;/* Referenced by: '<S63>/Constant' */
volatile uint8_T MFSM_DebounceDecrMtrTemp_C = 0U;/* Referenced by: '<S43>/Constant' */
volatile uint8_T MFSM_DebounceDecrOpen_C = 0U;/* Referenced by: '<S228>/Constant' */
volatile uint8_T MFSM_DebounceDecrPhaCurrDiff_C = 0U;/* Referenced by: '<S216>/Constant' */
volatile uint8_T MFSM_DebounceDecrPhaCurrOpen_C = 0U;/* Referenced by: '<S241>/Constant' */
volatile uint8_T MFSM_DebounceDecrPhaCurrShortPwr_C = 0U;/* Referenced by: '<S251>/Constant' */
volatile uint8_T MFSM_DebounceDecrRslvrAmp_C = 0U;/* Referenced by: '<S262>/Constant' */
volatile uint8_T MFSM_DebounceDecrSensorVolt_C = 0U;/* Referenced by: '<S74>/Constant' */
volatile uint8_T MFSM_DebounceDecrSinOpen_C = 0U;/* Referenced by: '<S276>/Constant' */
volatile uint8_T MFSM_DebounceDecrSinShortGnd_C = 0U;/* Referenced by: '<S286>/Constant' */
volatile uint8_T MFSM_DebounceDecrSinShortPwr_C = 0U;/* Referenced by: '<S295>/Constant' */
volatile uint8_T MFSM_DebounceDecrTqDiff_C = 0U;/* Referenced by: '<S84>/Constant' */
volatile uint8_T MFSM_DebounceIncrBusCurDiff_C = 0U;/* Referenced by: '<S19>/Constant' */
volatile uint8_T MFSM_DebounceIncrCosOpen_C = 0U;/* Referenced by: '<S126>/Constant' */
volatile uint8_T MFSM_DebounceIncrCosShortGnd_C = 0U;/* Referenced by: '<S136>/Constant' */
volatile uint8_T MFSM_DebounceIncrCosShortPwr_C = 0U;/* Referenced by: '<S145>/Constant' */
volatile uint8_T MFSM_DebounceIncrExcAmp_C = 0U;/* Referenced by: '<S153>/Constant' */
volatile uint8_T MFSM_DebounceIncrExcOpen_C = 0U;/* Referenced by: '<S169>/Constant' */
volatile uint8_T MFSM_DebounceIncrExcShortGnd_C = 0U;/* Referenced by:
                                                      * '<S179>/Constant'
                                                      * '<S188>/Constant'
                                                      */
volatile uint8_T MFSM_DebounceIncrHighVolt_C = 0U;/* Referenced by: '<S33>/Constant' */
volatile uint8_T MFSM_DebounceIncrMtrTempShortGnd_C = 0U;/* Referenced by: '<S52>/Constant' */
volatile uint8_T MFSM_DebounceIncrMtrTempShortPwr_C = 0U;/* Referenced by: '<S62>/Constant' */
volatile uint8_T MFSM_DebounceIncrMtrTemp_C = 0U;/* Referenced by: '<S42>/Constant' */
volatile uint8_T MFSM_DebounceIncrOpen_C = 0U;/* Referenced by: '<S227>/Constant' */
volatile uint8_T MFSM_DebounceIncrPhaCurrDiff_C = 0U;/* Referenced by: '<S215>/Constant' */
volatile uint8_T MFSM_DebounceIncrPhaCurrOpen_C = 0U;/* Referenced by: '<S240>/Constant' */
volatile uint8_T MFSM_DebounceIncrPhaCurrShortPwr_C = 0U;/* Referenced by: '<S250>/Constant' */
volatile uint8_T MFSM_DebounceIncrRslvrAmp_C = 0U;/* Referenced by: '<S261>/Constant' */
volatile uint8_T MFSM_DebounceIncrSensorVolt_C = 0U;/* Referenced by: '<S73>/Constant' */
volatile uint8_T MFSM_DebounceIncrSinOpen_C = 0U;/* Referenced by: '<S275>/Constant' */
volatile uint8_T MFSM_DebounceIncrSinShortGnd_C = 0U;/* Referenced by: '<S285>/Constant' */
volatile uint8_T MFSM_DebounceIncrSinShortPwr_C = 0U;/* Referenced by: '<S294>/Constant' */
volatile uint8_T MFSM_DebounceIncrTqDiff_C = 0U;/* Referenced by: '<S83>/Constant' */
volatile uint8_T MFSM_DebounceMaxBusCurDiff_C = 0U;/* Referenced by: '<S18>/Constant' */
volatile uint8_T MFSM_DebounceMaxCosOpen_C = 0U;/* Referenced by: '<S125>/Constant' */
volatile uint8_T MFSM_DebounceMaxCosShortGnd_C = 0U;/* Referenced by: '<S135>/Constant' */
volatile uint8_T MFSM_DebounceMaxCosShortPwr_C = 0U;/* Referenced by: '<S144>/Constant' */
volatile uint8_T MFSM_DebounceMaxExcAmp_C = 0U;/* Referenced by: '<S152>/Constant' */
volatile uint8_T MFSM_DebounceMaxExcOpen_C = 0U;/* Referenced by: '<S168>/Constant' */
volatile uint8_T MFSM_DebounceMaxExcShortGnd_C = 0U;/* Referenced by:
                                                     * '<S178>/Constant'
                                                     * '<S187>/Constant'
                                                     */
volatile uint8_T MFSM_DebounceMaxHighVolt_C = 0U;/* Referenced by: '<S32>/Constant' */
volatile uint8_T MFSM_DebounceMaxMtrTempShortGnd_C = 0U;/* Referenced by: '<S51>/Constant' */
volatile uint8_T MFSM_DebounceMaxMtrTempShortPwr_C = 0U;/* Referenced by: '<S61>/Constant' */
volatile uint8_T MFSM_DebounceMaxMtrTemp_C = 0U;/* Referenced by: '<S41>/Constant' */
volatile uint8_T MFSM_DebounceMaxOpen_C = 0U;/* Referenced by: '<S226>/Constant' */
volatile uint8_T MFSM_DebounceMaxPhaCurrDiff_C = 0U;/* Referenced by: '<S214>/Constant' */
volatile uint8_T MFSM_DebounceMaxPhaCurrOpen_C = 0U;/* Referenced by: '<S239>/Constant' */
volatile uint8_T MFSM_DebounceMaxPhaCurrShortPwr_C = 0U;/* Referenced by: '<S249>/Constant' */
volatile uint8_T MFSM_DebounceMaxRslvrAmp_C = 0U;/* Referenced by: '<S260>/Constant' */
volatile uint8_T MFSM_DebounceMaxSensorVolt_C = 0U;/* Referenced by: '<S72>/Constant' */
volatile uint8_T MFSM_DebounceMaxSinOpen_C = 0U;/* Referenced by: '<S274>/Constant' */
volatile uint8_T MFSM_DebounceMaxSinShortGnd_C = 0U;/* Referenced by: '<S284>/Constant' */
volatile uint8_T MFSM_DebounceMaxSinShortPwr_C = 0U;/* Referenced by: '<S293>/Constant' */
volatile uint8_T MFSM_DebounceMaxTqDiff_C = 0U;/* Referenced by: '<S82>/Constant' */
volatile uint8_T MFSM_DebounceMinBusCurDiff_C = 0U;/* Referenced by: '<S21>/Constant' */
volatile uint8_T MFSM_DebounceMinCosOpen_C = 0U;/* Referenced by: '<S128>/Constant' */
volatile uint8_T MFSM_DebounceMinCosShortGnd_C = 0U;/* Referenced by: '<S138>/Constant' */
volatile uint8_T MFSM_DebounceMinCosShortPwr_C = 0U;/* Referenced by: '<S147>/Constant' */
volatile uint8_T MFSM_DebounceMinExcAmp_C = 0U;/* Referenced by: '<S155>/Constant' */
volatile uint8_T MFSM_DebounceMinExcOpen_C = 0U;/* Referenced by: '<S171>/Constant' */
volatile uint8_T MFSM_DebounceMinExcShortGnd_C = 0U;/* Referenced by:
                                                     * '<S181>/Constant'
                                                     * '<S190>/Constant'
                                                     */
volatile uint8_T MFSM_DebounceMinHighVolt_C = 0U;/* Referenced by: '<S35>/Constant' */
volatile uint8_T MFSM_DebounceMinMtrTempShortGnd_C = 0U;/* Referenced by: '<S54>/Constant' */
volatile uint8_T MFSM_DebounceMinMtrTempShortPwr_C = 0U;/* Referenced by: '<S64>/Constant' */
volatile uint8_T MFSM_DebounceMinMtrTemp_C = 0U;/* Referenced by: '<S44>/Constant' */
volatile uint8_T MFSM_DebounceMinOpen_C = 0U;/* Referenced by: '<S229>/Constant' */
volatile uint8_T MFSM_DebounceMinPhaCurrDiff_C = 0U;/* Referenced by: '<S217>/Constant' */
volatile uint8_T MFSM_DebounceMinPhaCurrOpen_C = 0U;/* Referenced by: '<S242>/Constant' */
volatile uint8_T MFSM_DebounceMinPhaCurrShortPwr_C = 0U;/* Referenced by: '<S252>/Constant' */
volatile uint8_T MFSM_DebounceMinRslvrAmp_C = 0U;/* Referenced by: '<S263>/Constant' */
volatile uint8_T MFSM_DebounceMinSensorVolt_C = 0U;/* Referenced by: '<S75>/Constant' */
volatile uint8_T MFSM_DebounceMinSinOpen_C = 0U;/* Referenced by: '<S277>/Constant' */
volatile uint8_T MFSM_DebounceMinSinShortGnd_C = 0U;/* Referenced by: '<S287>/Constant' */
volatile uint8_T MFSM_DebounceMinSinShortPwr_C = 0U;/* Referenced by: '<S296>/Constant' */
volatile uint8_T MFSM_DebounceMinTqDiff_C = 0U;/* Referenced by: '<S85>/Constant' */
volatile real32_T MFSM_ExcMaxHighValue_C = 0.0F;/* Referenced by: '<S163>/Constant' */
volatile real32_T MFSM_ExcMaxLowValue_C = 0.0F;/* Referenced by: '<S162>/Constant' */
volatile real32_T MFSM_ExcMinHighValue_C = 0.0F;/* Referenced by: '<S165>/Constant' */
volatile real32_T MFSM_ExcMinLowValue_C = 0.0F;/* Referenced by: '<S164>/Constant' */
volatile real32_T MFSM_ExcOpenValue_C = 0.0F;/* Referenced by: '<S172>/Constant' */
volatile real32_T MFSM_ExcShortGndValue_C = 0.0F;/* Referenced by:
                                                  * '<S182>/Constant'
                                                  * '<S198>/Constant'
                                                  */
volatile real32_T MFSM_ExcShortPwrValue_C = 0.0F;/* Referenced by: '<S197>/Constant' */
volatile uint16_T MFSM_FastDiagInitTimeCount_C = 0U;/* Referenced by: '<S92>/Constant' */
volatile real32_T MFSM_HighVoltDiff_C = 0.0F;/* Referenced by: '<S31>/Constant' */
volatile real32_T MFSM_MaxCosOpenValue_C = 0.0F;/* Referenced by: '<S129>/Constant' */
volatile real32_T MFSM_MaxSinOpenValue_C = 0.0F;/* Referenced by: '<S278>/Constant' */
volatile real32_T MFSM_MinCosOpenValue_C = 0.0F;/* Referenced by: '<S124>/Constant' */
volatile real32_T MFSM_MinSinOpenValue_C = 0.0F;/* Referenced by: '<S273>/Constant' */
volatile real32_T MFSM_MtrTempSensorNShortGnd_C = 0.0F;/* Referenced by: '<S55>/Constant' */
volatile real32_T MFSM_MtrTempSensorNShortPwr_C = 0.0F;/* Referenced by: '<S65>/Constant' */
volatile real32_T MFSM_MtrTempSensorPShortGnd_C = 0.0F;/* Referenced by: '<S50>/Constant' */
volatile real32_T MFSM_MtrTempSensorPShortPwr_C = 0.0F;/* Referenced by: '<S60>/Constant' */
volatile real32_T MFSM_MtrTempSensorShortGnd_C = 0.0F;/* Referenced by: '<S45>/Constant' */
volatile real32_T MFSM_MtrTempSensorShortPwr_C = 0.0F;/* Referenced by: '<S40>/Constant' */
volatile real32_T MFSM_PhaCurrDiffValue_C = 0.0F;/* Referenced by: '<S224>/Constant' */
volatile real32_T MFSM_PhaCurrOpenDiffValue_C = 0.0F;/* Referenced by: '<S237>/Constant' */
volatile real32_T MFSM_PhaCurrOpenValue_C = 0.0F;/* Referenced by: '<S236>/Constant' */
volatile real32_T MFSM_PhaCurrShortGndValue_C = 0.0F;/* Referenced by: '<S247>/Constant' */
volatile real32_T MFSM_PhaCurrShortPwrValue_C = 0.0F;/* Referenced by: '<S257>/Constant' */
volatile real32_T MFSM_SensorVoltDiff_C = 0.0F;/* Referenced by: '<S71>/Constant' */
volatile real32_T MFSM_SinShortGndValue_C = 0.0F;/* Referenced by: '<S283>/Constant' */
volatile real32_T MFSM_SinShortPwrValue_C = 0.0F;/* Referenced by: '<S292>/Constant' */
volatile uint16_T MFSM_SlowDiagInitTimeCount_C = 0U;/* Referenced by: '<S5>/Constant' */
volatile real32_T MFSM_TorqueDiff_C = 0.0F;/* Referenced by: '<S81>/Constant' */
volatile real32_T MFSM_TorqueFilterFreq_C = 0.0F;/* Referenced by: '<S301>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
real32_T MFSM_BusCurDiff;
uint8_T MFSM_BusCurrentDiffFualt;      /* '<S1>/Subsystem' */
real32_T MFSM_BusCurrentLpfVal;        /* '<S2>/Subsystem' */
real32_T MFSM_CosDiff;
uint8_T MFSM_CosDiffFault;             /* '<S2>/Subsystem' */
real32_T MFSM_CosNegHigh;
real32_T MFSM_CosNegLow;
uint8_T MFSM_CosOpenFault;             /* '<S2>/Subsystem' */
real32_T MFSM_CosPosHigh;
real32_T MFSM_CosPosLow;
uint8_T MFSM_CosShortGndFault;         /* '<S2>/Subsystem' */
uint8_T MFSM_CosShortPwrFault;         /* '<S2>/Subsystem' */
real32_T MFSM_CosSum;
real32_T MFSM_DcVolt;
real32_T MFSM_DcVoltDiff;
real32_T MFSM_ExcAmpAve;
uint8_T MFSM_ExcAmpFault;              /* '<S2>/Subsystem' */
real32_T MFSM_ExcAveVal;
real32_T MFSM_ExcDiffHigh;
real32_T MFSM_ExcDiffLow;
real32_T MFSM_ExcNegHigh;
real32_T MFSM_ExcNegLow;
uint8_T MFSM_ExcOpenFault;             /* '<S2>/Subsystem' */
real32_T MFSM_ExcPosHigh;
real32_T MFSM_ExcPosLow;
uint8_T MFSM_ExcShortGndFault;         /* '<S2>/Subsystem' */
uint8_T MFSM_ExcShortPwrFault;         /* '<S2>/Subsystem' */
real32_T MFSM_ExcShortPwr_Max;
real32_T MFSM_ExcShortPwr_Min;
real32_T MFSM_FunSafetyTorque;         /* '<S2>/Subsystem' */
uint8_T MFSM_HighVoltFault;            /* '<S1>/Subsystem' */
uint8_T MFSM_MtrTempFault;             /* '<S1>/Subsystem' */
real32_T MFSM_MtrTempNVolt;
real32_T MFSM_MtrTempPVolt;
uint8_T MFSM_MtrTempShortGndFault;     /* '<S1>/Subsystem' */
uint8_T MFSM_MtrTempShortPwrFault;     /* '<S1>/Subsystem' */
uint8_T MFSM_PhaCurrDiffFault;         /* '<S2>/Subsystem' */
uint8_T MFSM_PhaCurrOpenFault;         /* '<S2>/Subsystem' */
uint8_T MFSM_PhaCurrShortGndFault;     /* '<S2>/Subsystem' */
uint8_T MFSM_PhaCurrShortPwrFault;     /* '<S2>/Subsystem' */
real32_T MFSM_PhaseA;
real32_T MFSM_PhaseACurrentDiff;
real32_T MFSM_PhaseADiff;
real32_T MFSM_PhaseBCurrent;
real32_T MFSM_PhaseC;
real32_T MFSM_PhaseCCurrentDiff;
real32_T MFSM_PhaseCDiff;
real32_T MFSM_PwrChipVoltDiff;
real32_T MFSM_PwrChipVoltValue;
uint8_T MFSM_RslvrAmpFault;            /* '<S2>/Subsystem' */
real32_T MFSM_RslvrAmpSum;
uint8_T MFSM_SensorVoltFault;          /* '<S1>/Subsystem' */
real32_T MFSM_SinDiff;
real32_T MFSM_SinNegHigh;
real32_T MFSM_SinNegLow;
uint8_T MFSM_SinOpenFault;             /* '<S2>/Subsystem' */
real32_T MFSM_SinPosHigh;
real32_T MFSM_SinPosLow;
uint8_T MFSM_SinShortGndFault;         /* '<S2>/Subsystem' */
uint8_T MFSM_SinShortPwrFault;         /* '<S2>/Subsystem' */
real32_T MFSM_SinSum;
uint8_T MFSM_SineDiffFault;            /* '<S2>/Subsystem' */
real32_T MFSM_TqDiff;
uint8_T MFSM_TqDiffFualt;              /* '<S1>/Subsystem' */

#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Block signals (default storage) */
B_McuFunSafeMonitor_T McuFunSafeMonitor_B;

/* Block states (default storage) */
DW_McuFunSafeMonitor_T McuFunSafeMonitor_DW;

/* Real-time model */
static RT_MODEL_McuFunSafeMonitor_T McuFunSafeMonitor_M_;
RT_MODEL_McuFunSafeMonitor_T *const McuFunSafeMonitor_M = &McuFunSafeMonitor_M_;

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void MFSM_FuncSafetyRedundancy_1ms(void)
{
  int32_T rtb_DataTypeConversion16;
  int32_T rtb_DataTypeConversion18;
  int32_T rtb_DataTypeConversion19;
  int32_T tmp;
  int32_T tmp_0;
  uint32_T tmp_1;
  uint16_T rtb_Subtract1_k;
  uint8_T rtb_MultiportSwitch;

  /* RootInportFunctionCallGenerator generated from: '<Root>/MFSM_FuncSafetyRedundancy_1ms' incorporates:
   *  SubSystem: '<Root>/MFSM_FuncSafetyRedundancy_1ms_sys'
   */
  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  tmp_1 = (uint32_T)((uint16_T)1U) + McuFunSafeMonitor_DW.UnitDelay_DSTATE_o;
  if (tmp_1 > 65535U) {
    tmp_1 = 65535U;
  }

  /* Switch: '<S6>/Switch2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S6>/LowerRelop1'
   *  RelationalOperator: '<S6>/UpperRelop'
   *  Sum: '<S3>/Add'
   *  Switch: '<S6>/Switch'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if ((uint16_T)tmp_1 > MFSM_SlowDiagInitTimeCount_C) {
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_o = MFSM_SlowDiagInitTimeCount_C;
  } else if ((uint16_T)tmp_1 < ((uint16_T)0U)) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S3>/Constant1'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_o = ((uint16_T)0U);
  } else {
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_o = (uint16_T)tmp_1;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* RelationalOperator: '<S3>/Relational Operator' incorporates:
   *  Constant: '<S5>/Constant'
   *  FunctionCaller: '<S8>/Hal_ReadDcLinkVoltMeasAD'
   *  FunctionCaller: '<S8>/Hal_ReadMotorTempAdc'
   *  FunctionCaller: '<S8>/Hal_ReadPwrChipVolt'
   *  FunctionCaller: '<S8>/Hal_ReadStatorTempAdcBkUp'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if (McuFunSafeMonitor_DW.UnitDelay_DSTATE_o >= MFSM_SlowDiagInitTimeCount_C) {
    rtb_Subtract1_k = Hal_ReadPwrChipVolt();

    /* DataTypeConversion: '<S8>/Data Type Conversion16' incorporates:
     *  FunctionCaller: '<S8>/Hal_ReadPwrChipVolt'
     */
    rtb_DataTypeConversion16 = rtb_Subtract1_k;

    /* DataStoreWrite: '<S25>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion16'
     */
    MFSM_PwrChipVoltValue = (real32_T)rtb_Subtract1_k;
    rtb_Subtract1_k = Hal_ReadMotorTempAdc();

    /* DataTypeConversion: '<S8>/Data Type Conversion18' incorporates:
     *  FunctionCaller: '<S8>/Hal_ReadMotorTempAdc'
     */
    rtb_DataTypeConversion18 = rtb_Subtract1_k;

    /* DataStoreWrite: '<S27>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion18'
     */
    MFSM_MtrTempPVolt = (real32_T)rtb_Subtract1_k;
    rtb_Subtract1_k = Hal_ReadMotorTempAdcBkUp();

    /* DataTypeConversion: '<S8>/Data Type Conversion19' incorporates:
     *  FunctionCaller: '<S8>/Hal_ReadStatorTempAdcBkUp'
     */
    rtb_DataTypeConversion19 = rtb_Subtract1_k;

    /* DataStoreWrite: '<S28>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion19'
     */
    MFSM_MtrTempNVolt = (real32_T)rtb_Subtract1_k;
    rtb_Subtract1_k = Hal_ReadDcLinkVoltMeasAD();

    /* DataTypeConversion: '<S8>/Data Type Conversion17' incorporates:
     *  DataStoreWrite: '<S26>/Data Store Write'
     *  FunctionCaller: '<S8>/Hal_ReadDcLinkVoltMeasAD'
     */
    MFSM_DcVolt = (real32_T)rtb_Subtract1_k;

    /* Abs: '<S9>/Abs' incorporates:
     *  DataStoreWrite: '<S26>/Data Store Write'
     *  DataStoreWrite: '<S30>/Data Store Write'
     *  Inport: '<Root>/SGSA_DcLinkVoltMeasAD'
     *  Sum: '<S9>/Subtract'
     */
    MFSM_DcVoltDiff = (real32_T)fabs(SGSA_DcLinkVoltMeasAD - MFSM_DcVolt);

    /* Sum: '<S29>/Add2' incorporates:
     *  Constant: '<S29>/0 Constant4'
     *  Constant: '<S32>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxHighVolt_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S29>/Multiport Switch' incorporates:
     *  Constant: '<S29>/0 Constant'
     *  Constant: '<S31>/Constant'
     *  DataStoreWrite: '<S30>/Data Store Write'
     *  MinMax: '<S29>/Max'
     *  RelationalOperator: '<S9>/Relational Operator4'
     *  Sum: '<S29>/Add'
     *  Sum: '<S29>/Add1'
     *  UnitDelay: '<S38>/Bare Unit Delay'
     */
    if (!(MFSM_DcVoltDiff > MFSM_HighVoltDiff_C)) {
      /* Sum: '<S29>/Add' incorporates:
       *  Constant: '<S34>/Constant'
       *  UnitDelay: '<S38>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j -
        MFSM_DebounceDecrHighVolt_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j) {
        /* MinMax: '<S29>/Max' incorporates:
         *  Constant: '<S29>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S29>/Max' incorporates:
         *  UnitDelay: '<S38>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j;
      }

      /* Sum: '<S29>/Add1' incorporates:
       *  Constant: '<S33>/Constant'
       *  MinMax: '<S29>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrHighVolt_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S29>/Multiport Switch' */

    /* Switch: '<S38>/Enable' incorporates:
     *  Constant: '<S29>/Constant2'
     *  Logic: '<S38>/Logical Operator2'
     *  Switch: '<S38>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_n4 && true) {
      /* Switch: '<S36>/Switch2' incorporates:
       *  Constant: '<S29>/0 Constant1'
       *  RelationalOperator: '<S36>/LowerRelop1'
       *  RelationalOperator: '<S36>/UpperRelop'
       *  Sum: '<S29>/Add2'
       *  Switch: '<S36>/Switch'
       *  UnitDelay: '<S38>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S36>/Switch' incorporates:
         *  Constant: '<S29>/0 Constant1'
         *  UnitDelay: '<S38>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S36>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_c) {
      /* Switch: '<S38>/Reset' incorporates:
       *  Constant: '<S38>/iv'
       *  UnitDelay: '<S38>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j = ((uint8_T)0U);
    }

    /* End of Switch: '<S38>/Enable' */

    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S35>/Constant'
     *  RelationalOperator: '<S29>/Relational Operator'
     *  RelationalOperator: '<S29>/Relational Operator1'
     *  Sum: '<S29>/Add2'
     *  Switch: '<S37>/Switch1'
     *  UnitDelay: '<S38>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j >= (uint8_T)tmp_0) {
      /* Switch: '<S37>/Switch' incorporates:
       *  Constant: '<S37>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_e = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_j <=
               MFSM_DebounceMinHighVolt_C) {
      /* Switch: '<S37>/Switch' incorporates:
       *  Constant: '<S37>/Constant4'
       *  Switch: '<S37>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_e = false;
    }

    /* End of Switch: '<S37>/Switch' */

    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S37>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_c =
      McuFunSafeMonitor_DW.Memory_PreviousInput_e;

    /* Abs: '<S13>/Abs' incorporates:
     *  DataStoreWrite: '<S70>/Data Store Write'
     *  Gain: '<S13>/Gain'
     *  Inport: '<Root>/SGSA_PwrChipVolt'
     *  Sum: '<S13>/Subtract'
     */
    MFSM_PwrChipVoltDiff = (real32_T)fabs(SGSA_PwrChipVolt - 0.002442F *
      (real32_T)rtb_DataTypeConversion16);

    /* Sum: '<S69>/Add2' incorporates:
     *  Constant: '<S69>/0 Constant4'
     *  Constant: '<S72>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxSensorVolt_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S69>/Multiport Switch' incorporates:
     *  Constant: '<S69>/0 Constant'
     *  Constant: '<S71>/Constant'
     *  DataStoreWrite: '<S70>/Data Store Write'
     *  MinMax: '<S69>/Max'
     *  RelationalOperator: '<S13>/Relational Operator4'
     *  Sum: '<S69>/Add'
     *  Sum: '<S69>/Add1'
     *  UnitDelay: '<S78>/Bare Unit Delay'
     */
    if (!(MFSM_PwrChipVoltDiff > MFSM_SensorVoltDiff_C)) {
      /* Sum: '<S69>/Add' incorporates:
       *  Constant: '<S74>/Constant'
       *  UnitDelay: '<S78>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 -
        MFSM_DebounceDecrSensorVolt_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3) {
        /* MinMax: '<S69>/Max' incorporates:
         *  Constant: '<S69>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S69>/Max' incorporates:
         *  UnitDelay: '<S78>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3;
      }

      /* Sum: '<S69>/Add1' incorporates:
       *  Constant: '<S73>/Constant'
       *  MinMax: '<S69>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrSensorVolt_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S69>/Multiport Switch' */

    /* Switch: '<S78>/Enable' incorporates:
     *  Constant: '<S69>/Constant2'
     *  Logic: '<S78>/Logical Operator2'
     *  Switch: '<S78>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_fw && true) {
      /* Switch: '<S76>/Switch2' incorporates:
       *  Constant: '<S69>/0 Constant1'
       *  RelationalOperator: '<S76>/LowerRelop1'
       *  RelationalOperator: '<S76>/UpperRelop'
       *  Sum: '<S69>/Add2'
       *  Switch: '<S76>/Switch'
       *  UnitDelay: '<S78>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S76>/Switch' incorporates:
         *  Constant: '<S69>/0 Constant1'
         *  UnitDelay: '<S78>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S76>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_n2) {
      /* Switch: '<S78>/Reset' incorporates:
       *  Constant: '<S78>/iv'
       *  UnitDelay: '<S78>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 = ((uint8_T)0U);
    }

    /* End of Switch: '<S78>/Enable' */

    /* Switch: '<S77>/Switch' incorporates:
     *  Constant: '<S75>/Constant'
     *  RelationalOperator: '<S69>/Relational Operator'
     *  RelationalOperator: '<S69>/Relational Operator1'
     *  Sum: '<S69>/Add2'
     *  Switch: '<S77>/Switch1'
     *  UnitDelay: '<S78>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 >= (uint8_T)tmp_0) {
      /* Switch: '<S77>/Switch' incorporates:
       *  Constant: '<S77>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_eb = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k3 <=
               MFSM_DebounceMinSensorVolt_C) {
      /* Switch: '<S77>/Switch' incorporates:
       *  Constant: '<S77>/Constant4'
       *  Switch: '<S77>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_eb = false;
    }

    /* End of Switch: '<S77>/Switch' */

    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S77>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_lp =
      McuFunSafeMonitor_DW.Memory_PreviousInput_eb;

    /* Abs: '<S14>/Abs' incorporates:
     *  Constant: '<S86>/Constant1'
     *  DataStoreWrite: '<S80>/Data Store Write'
     *  Gain: '<S86>/Gain'
     *  Inport: '<Root>/IPU_IsgTqActIsgTqAct'
     *  Sum: '<S14>/Subtract'
     *  Sum: '<S86>/Subtract1'
     */
    MFSM_TqDiff = (real32_T)fabs((real32_T)((uint16_T)52429U) * 1.90734863E-6F *
      (real32_T)(uint16_T)(0 - ((uint16_T)1200U)) -
      MFSM_FunSafetyTorque);

    /* Sum: '<S79>/Add2' incorporates:
     *  Constant: '<S79>/0 Constant4'
     *  Constant: '<S82>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxTqDiff_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S79>/Multiport Switch' incorporates:
     *  Constant: '<S79>/0 Constant'
     *  Constant: '<S81>/Constant'
     *  DataStoreWrite: '<S80>/Data Store Write'
     *  MinMax: '<S79>/Max'
     *  RelationalOperator: '<S14>/Relational Operator4'
     *  Sum: '<S79>/Add'
     *  Sum: '<S79>/Add1'
     *  UnitDelay: '<S89>/Bare Unit Delay'
     */
    if (!(MFSM_TqDiff > MFSM_TorqueDiff_C)) {
      /* Sum: '<S79>/Add' incorporates:
       *  Constant: '<S84>/Constant'
       *  UnitDelay: '<S89>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov -
        MFSM_DebounceDecrTqDiff_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov) {
        /* MinMax: '<S79>/Max' incorporates:
         *  Constant: '<S79>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S79>/Max' incorporates:
         *  UnitDelay: '<S89>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov;
      }

      /* Sum: '<S79>/Add1' incorporates:
       *  Constant: '<S83>/Constant'
       *  MinMax: '<S79>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrTqDiff_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S79>/Multiport Switch' */

    /* Switch: '<S89>/Enable' incorporates:
     *  Constant: '<S79>/Constant2'
     *  Logic: '<S89>/Logical Operator2'
     *  Switch: '<S89>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_lm && true) {
      /* Switch: '<S87>/Switch2' incorporates:
       *  Constant: '<S79>/0 Constant1'
       *  RelationalOperator: '<S87>/LowerRelop1'
       *  RelationalOperator: '<S87>/UpperRelop'
       *  Sum: '<S79>/Add2'
       *  Switch: '<S87>/Switch'
       *  UnitDelay: '<S89>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S87>/Switch' incorporates:
         *  Constant: '<S79>/0 Constant1'
         *  UnitDelay: '<S89>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S87>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_pu) {
      /* Switch: '<S89>/Reset' incorporates:
       *  Constant: '<S89>/iv'
       *  UnitDelay: '<S89>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov = ((uint8_T)0U);
    }

    /* End of Switch: '<S89>/Enable' */

    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S85>/Constant'
     *  RelationalOperator: '<S79>/Relational Operator'
     *  RelationalOperator: '<S79>/Relational Operator1'
     *  Sum: '<S79>/Add2'
     *  Switch: '<S88>/Switch1'
     *  UnitDelay: '<S89>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov >= (uint8_T)tmp_0) {
      /* Switch: '<S88>/Switch' incorporates:
       *  Constant: '<S88>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_o3 = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_ov <=
               MFSM_DebounceMinTqDiff_C) {
      /* Switch: '<S88>/Switch' incorporates:
       *  Constant: '<S88>/Constant4'
       *  Switch: '<S88>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_o3 = false;
    }

    /* End of Switch: '<S88>/Switch' */

    /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S88>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_cs =
      McuFunSafeMonitor_DW.Memory_PreviousInput_o3;

    /* Abs: '<S7>/Abs' incorporates:
     *  DataStoreWrite: '<S16>/Data Store Write'
     *  Sum: '<S7>/Subtract'
     */
    MFSM_BusCurDiff = (real32_T)fabs(0.0F - MFSM_BusCurrentLpfVal);

    /* Sum: '<S15>/Add2' incorporates:
     *  Constant: '<S15>/0 Constant4'
     *  Constant: '<S18>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxBusCurDiff_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S15>/Multiport Switch' incorporates:
     *  Constant: '<S15>/0 Constant'
     *  Constant: '<S17>/Constant'
     *  DataStoreWrite: '<S16>/Data Store Write'
     *  MinMax: '<S15>/Max'
     *  RelationalOperator: '<S7>/Relational Operator4'
     *  Sum: '<S15>/Add'
     *  Sum: '<S15>/Add1'
     *  UnitDelay: '<S24>/Bare Unit Delay'
     */
    if (!(MFSM_BusCurDiff > MFSM_BusCurDiff_C)) {
      /* Sum: '<S15>/Add' incorporates:
       *  Constant: '<S20>/Constant'
       *  UnitDelay: '<S24>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy -
        MFSM_DebounceDecrBusCurDiff_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy) {
        /* MinMax: '<S15>/Max' incorporates:
         *  Constant: '<S15>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S15>/Max' incorporates:
         *  UnitDelay: '<S24>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy;
      }

      /* Sum: '<S15>/Add1' incorporates:
       *  Constant: '<S19>/Constant'
       *  MinMax: '<S15>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrBusCurDiff_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S15>/Multiport Switch' */

    /* Switch: '<S24>/Enable' incorporates:
     *  Constant: '<S15>/Constant2'
     *  Logic: '<S24>/Logical Operator2'
     *  Switch: '<S24>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_b && true) {
      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S15>/0 Constant1'
       *  RelationalOperator: '<S22>/LowerRelop1'
       *  RelationalOperator: '<S22>/UpperRelop'
       *  Sum: '<S15>/Add2'
       *  Switch: '<S22>/Switch'
       *  UnitDelay: '<S24>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S22>/Switch' incorporates:
         *  Constant: '<S15>/0 Constant1'
         *  UnitDelay: '<S24>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S22>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_ne) {
      /* Switch: '<S24>/Reset' incorporates:
       *  Constant: '<S24>/iv'
       *  UnitDelay: '<S24>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy = ((uint8_T)0U);
    }

    /* End of Switch: '<S24>/Enable' */

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S21>/Constant'
     *  RelationalOperator: '<S15>/Relational Operator'
     *  RelationalOperator: '<S15>/Relational Operator1'
     *  Sum: '<S15>/Add2'
     *  Switch: '<S23>/Switch1'
     *  UnitDelay: '<S24>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy >= (uint8_T)tmp_0) {
      /* Switch: '<S23>/Switch' incorporates:
       *  Constant: '<S23>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_fx = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_jy <=
               MFSM_DebounceMinBusCurDiff_C) {
      /* Switch: '<S23>/Switch' incorporates:
       *  Constant: '<S23>/Constant4'
       *  Switch: '<S23>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_fx = false;
    }

    /* End of Switch: '<S23>/Switch' */

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_dm =
      McuFunSafeMonitor_DW.Memory_PreviousInput_fx;

    /* Sum: '<S49>/Add2' incorporates:
     *  Constant: '<S49>/0 Constant4'
     *  Constant: '<S51>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxMtrTempShortGnd_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S49>/Multiport Switch' incorporates:
     *  Constant: '<S49>/0 Constant'
     *  Constant: '<S50>/Constant'
     *  Constant: '<S55>/Constant'
     *  Logic: '<S11>/OR'
     *  MinMax: '<S49>/Max'
     *  RelationalOperator: '<S11>/Relational Operator1'
     *  RelationalOperator: '<S11>/Relational Operator4'
     *  Sum: '<S49>/Add'
     *  Sum: '<S49>/Add1'
     *  UnitDelay: '<S58>/Bare Unit Delay'
     */
    if ((!(rtb_DataTypeConversion18 < MFSM_MtrTempSensorPShortGnd_C)) &&
        (!(rtb_DataTypeConversion19 < MFSM_MtrTempSensorNShortGnd_C))) {
      /* Sum: '<S49>/Add' incorporates:
       *  Constant: '<S53>/Constant'
       *  UnitDelay: '<S58>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md -
        MFSM_DebounceDecrMtrTempShortGnd_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md) {
        /* MinMax: '<S49>/Max' incorporates:
         *  Constant: '<S49>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S49>/Max' incorporates:
         *  UnitDelay: '<S58>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md;
      }

      /* Sum: '<S49>/Add1' incorporates:
       *  Constant: '<S52>/Constant'
       *  MinMax: '<S49>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrMtrTempShortGnd_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S49>/Multiport Switch' */

    /* Switch: '<S58>/Enable' incorporates:
     *  Constant: '<S49>/Constant2'
     *  Logic: '<S58>/Logical Operator2'
     *  Switch: '<S58>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_fl && true) {
      /* Switch: '<S56>/Switch2' incorporates:
       *  Constant: '<S49>/0 Constant1'
       *  RelationalOperator: '<S56>/LowerRelop1'
       *  RelationalOperator: '<S56>/UpperRelop'
       *  Sum: '<S49>/Add2'
       *  Switch: '<S56>/Switch'
       *  UnitDelay: '<S58>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S56>/Switch' incorporates:
         *  Constant: '<S49>/0 Constant1'
         *  UnitDelay: '<S58>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S56>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_nb) {
      /* Switch: '<S58>/Reset' incorporates:
       *  Constant: '<S58>/iv'
       *  UnitDelay: '<S58>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md = ((uint8_T)0U);
    }

    /* End of Switch: '<S58>/Enable' */

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  RelationalOperator: '<S49>/Relational Operator'
     *  RelationalOperator: '<S49>/Relational Operator1'
     *  Sum: '<S49>/Add2'
     *  Switch: '<S57>/Switch1'
     *  UnitDelay: '<S58>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md >= (uint8_T)tmp_0) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S57>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_b = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_md <=
               MFSM_DebounceMinMtrTempShortGnd_C) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S57>/Constant4'
       *  Switch: '<S57>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_b = false;
    }

    /* End of Switch: '<S57>/Switch' */

    /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S57>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_c3 =
      McuFunSafeMonitor_DW.Memory_PreviousInput_b;

    /* Sum: '<S59>/Add2' incorporates:
     *  Constant: '<S59>/0 Constant4'
     *  Constant: '<S61>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxMtrTempShortPwr_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S59>/Multiport Switch' incorporates:
     *  Constant: '<S59>/0 Constant'
     *  Constant: '<S60>/Constant'
     *  Constant: '<S65>/Constant'
     *  Logic: '<S12>/OR'
     *  MinMax: '<S59>/Max'
     *  RelationalOperator: '<S12>/Relational Operator1'
     *  RelationalOperator: '<S12>/Relational Operator4'
     *  Sum: '<S59>/Add'
     *  Sum: '<S59>/Add1'
     *  UnitDelay: '<S68>/Bare Unit Delay'
     */
    if ((!(rtb_DataTypeConversion18 > MFSM_MtrTempSensorPShortPwr_C)) &&
        (!(rtb_DataTypeConversion19 > MFSM_MtrTempSensorNShortPwr_C))) {
      /* Sum: '<S59>/Add' incorporates:
       *  Constant: '<S63>/Constant'
       *  UnitDelay: '<S68>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b -
        MFSM_DebounceDecrMtrTempShortPwr_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b) {
        /* MinMax: '<S59>/Max' incorporates:
         *  Constant: '<S59>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S59>/Max' incorporates:
         *  UnitDelay: '<S68>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b;
      }

      /* Sum: '<S59>/Add1' incorporates:
       *  Constant: '<S62>/Constant'
       *  MinMax: '<S59>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrMtrTempShortPwr_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S59>/Multiport Switch' */

    /* Switch: '<S68>/Enable' incorporates:
     *  Constant: '<S59>/Constant2'
     *  Logic: '<S68>/Logical Operator2'
     *  Switch: '<S68>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_pw && true) {
      /* Switch: '<S66>/Switch2' incorporates:
       *  Constant: '<S59>/0 Constant1'
       *  RelationalOperator: '<S66>/LowerRelop1'
       *  RelationalOperator: '<S66>/UpperRelop'
       *  Sum: '<S59>/Add2'
       *  Switch: '<S66>/Switch'
       *  UnitDelay: '<S68>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S66>/Switch' incorporates:
         *  Constant: '<S59>/0 Constant1'
         *  UnitDelay: '<S68>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S66>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_d) {
      /* Switch: '<S68>/Reset' incorporates:
       *  Constant: '<S68>/iv'
       *  UnitDelay: '<S68>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b = ((uint8_T)0U);
    }

    /* End of Switch: '<S68>/Enable' */

    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S59>/Relational Operator'
     *  RelationalOperator: '<S59>/Relational Operator1'
     *  Sum: '<S59>/Add2'
     *  Switch: '<S67>/Switch1'
     *  UnitDelay: '<S68>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b >= (uint8_T)tmp_0) {
      /* Switch: '<S67>/Switch' incorporates:
       *  Constant: '<S67>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_c3 = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_b <=
               MFSM_DebounceMinMtrTempShortPwr_C) {
      /* Switch: '<S67>/Switch' incorporates:
       *  Constant: '<S67>/Constant4'
       *  Switch: '<S67>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_c3 = false;
    }

    /* End of Switch: '<S67>/Switch' */

    /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S67>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_p0 =
      McuFunSafeMonitor_DW.Memory_PreviousInput_c3;

    /* Sum: '<S39>/Add2' incorporates:
     *  Constant: '<S39>/0 Constant4'
     *  Constant: '<S41>/Constant'
     */
    tmp_0 = (int32_T)((uint32_T)MFSM_DebounceMaxMtrTemp_C + ((uint8_T)1U));
    if ((uint32_T)tmp_0 > 255U) {
      tmp_0 = 255;
    }

    /* MultiPortSwitch: '<S39>/Multiport Switch' incorporates:
     *  Constant: '<S39>/0 Constant'
     *  Constant: '<S40>/Constant'
     *  Constant: '<S45>/Constant'
     *  Inport: '<Root>/SGSA_MotorTemp1AD'
     *  Logic: '<S10>/OR'
     *  MinMax: '<S39>/Max'
     *  RelationalOperator: '<S10>/Relational Operator1'
     *  RelationalOperator: '<S10>/Relational Operator4'
     *  Sum: '<S39>/Add'
     *  Sum: '<S39>/Add1'
     *  UnitDelay: '<S48>/Bare Unit Delay'
     */
    if ((!(SGSA_MotorTemp1AD > MFSM_MtrTempSensorShortPwr_C)) &&
        (!(SGSA_MotorTemp1AD < MFSM_MtrTempSensorShortGnd_C))) {
      /* Sum: '<S39>/Add' incorporates:
       *  Constant: '<S43>/Constant'
       *  UnitDelay: '<S48>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d -
        MFSM_DebounceDecrMtrTemp_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d) {
        /* MinMax: '<S39>/Max' incorporates:
         *  Constant: '<S39>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S39>/Max' incorporates:
         *  UnitDelay: '<S48>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d;
      }

      /* Sum: '<S39>/Add1' incorporates:
       *  Constant: '<S42>/Constant'
       *  MinMax: '<S39>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrMtrTemp_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S39>/Multiport Switch' */

    /* Switch: '<S48>/Enable' incorporates:
     *  Constant: '<S39>/Constant2'
     *  Logic: '<S48>/Logical Operator2'
     *  Switch: '<S48>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_h && true) {
      /* Switch: '<S46>/Switch2' incorporates:
       *  Constant: '<S39>/0 Constant1'
       *  RelationalOperator: '<S46>/LowerRelop1'
       *  RelationalOperator: '<S46>/UpperRelop'
       *  Sum: '<S39>/Add2'
       *  Switch: '<S46>/Switch'
       *  UnitDelay: '<S48>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)tmp_0) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d = (uint8_T)tmp_0;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S46>/Switch' incorporates:
         *  Constant: '<S39>/0 Constant1'
         *  UnitDelay: '<S48>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S46>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_ls) {
      /* Switch: '<S48>/Reset' incorporates:
       *  Constant: '<S48>/iv'
       *  UnitDelay: '<S48>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d = ((uint8_T)0U);
    }

    /* End of Switch: '<S48>/Enable' */

    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S44>/Constant'
     *  RelationalOperator: '<S39>/Relational Operator'
     *  RelationalOperator: '<S39>/Relational Operator1'
     *  Sum: '<S39>/Add2'
     *  Switch: '<S47>/Switch1'
     *  UnitDelay: '<S48>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d >= (uint8_T)tmp_0) {
      /* Switch: '<S47>/Switch' incorporates:
       *  Constant: '<S47>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_g = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_d <=
               MFSM_DebounceMinMtrTemp_C) {
      /* Switch: '<S47>/Switch' incorporates:
       *  Constant: '<S47>/Constant4'
       *  Switch: '<S47>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_g = false;
    }

    /* End of Switch: '<S47>/Switch' */

    /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S47>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_ld =
      McuFunSafeMonitor_DW.Memory_PreviousInput_g;
  }

  /* End of RelationalOperator: '<S3>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* SignalConversion generated from: '<S1>/MFSM_BusCurrentDiffFualt' */
  MFSM_BusCurrentDiffFualt = McuFunSafeMonitor_B.DataTypeConversion_dm;

  /* SignalConversion generated from: '<S1>/MFSM_HighVoltFault' */
  MFSM_HighVoltFault = McuFunSafeMonitor_B.DataTypeConversion_c;

  /* SignalConversion generated from: '<S1>/MFSM_MtrTempFault' */
  MFSM_MtrTempFault = McuFunSafeMonitor_B.DataTypeConversion_ld;

  /* SignalConversion generated from: '<S1>/MFSM_MtrTempShortGndFault' */
  MFSM_MtrTempShortGndFault = McuFunSafeMonitor_B.DataTypeConversion_c3;

  /* SignalConversion generated from: '<S1>/MFSM_MtrTempShortPwrFault' */
  MFSM_MtrTempShortPwrFault = McuFunSafeMonitor_B.DataTypeConversion_p0;

  /* SignalConversion generated from: '<S1>/MFSM_SensorVoltFault' */
  MFSM_SensorVoltFault = McuFunSafeMonitor_B.DataTypeConversion_lp;

  /* SignalConversion generated from: '<S1>/MFSM_TqDiffFualt' */
  MFSM_TqDiffFualt = McuFunSafeMonitor_B.DataTypeConversion_cs;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/MFSM_FuncSafetyRedundancy_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void MFSM_FuncSafetyRedundancy_96us(void)
{
  int32_T rtb_DataTypeConversion10;
  int32_T rtb_DataTypeConversion11;
  int32_T rtb_DataTypeConversion12;
  int32_T rtb_DataTypeConversion12_tmp;
  int32_T rtb_Max;
  int32_T rtb_Max2;
  int32_T rtb_Max3;
  int32_T rtb_Min2;
  int32_T rtb_Min3;
  int32_T tmp;
  real32_T rtb_Min1;
  real32_T rtb_Min1_tmp_tmp;
  real32_T rtb_Saturation;
  real32_T rtb_Switch3;
  real32_T u0;
  uint32_T rtb_Prelookup_o1_k;
  int16_T rtb_Hal_ReadSinNegLowFall;
  uint16_T rtb_Hal_ReadPhaseCCurrentAD;
  uint8_T rtb_MultiportSwitch;
  boolean_T rtb_Switch_a;
  boolean_T rtb_Switch_ae;
  boolean_T rtb_Switch_cg;
  boolean_T rtb_Switch_go;
  boolean_T rtb_Switch_kl;
  boolean_T rtb_Switch_os;

  /* RootInportFunctionCallGenerator generated from: '<Root>/MFSM_FuncSafetyRedundancy_96us' incorporates:
   *  SubSystem: '<Root>/MFSM_FuncSafetyRedundancy_96us_sys'
   */
  /* Sum: '<S90>/Add' incorporates:
   *  Constant: '<S90>/Constant'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  rtb_Prelookup_o1_k = (uint32_T)((uint16_T)1U) +
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_p;
  if (rtb_Prelookup_o1_k > 65535U) {
    rtb_Prelookup_o1_k = 65535U;
  }

  /* Switch: '<S93>/Switch2' incorporates:
   *  Constant: '<S90>/Constant1'
   *  Constant: '<S92>/Constant'
   *  RelationalOperator: '<S93>/LowerRelop1'
   *  RelationalOperator: '<S93>/UpperRelop'
   *  Sum: '<S90>/Add'
   *  Switch: '<S93>/Switch'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  if ((uint16_T)rtb_Prelookup_o1_k > MFSM_FastDiagInitTimeCount_C) {
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_p = MFSM_FastDiagInitTimeCount_C;
  } else if ((uint16_T)rtb_Prelookup_o1_k < ((uint16_T)0U)) {
    /* Switch: '<S93>/Switch' incorporates:
     *  Constant: '<S90>/Constant1'
     *  UnitDelay: '<S90>/Unit Delay'
     */
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_p = ((uint16_T)0U);
  } else {
    McuFunSafeMonitor_DW.UnitDelay_DSTATE_p = (uint16_T)rtb_Prelookup_o1_k;
  }

  /* End of Switch: '<S93>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S91>/Enable'
   */
  /* RelationalOperator: '<S90>/Relational Operator' incorporates:
   *  Constant: '<S92>/Constant'
   *  FunctionCaller: '<S102>/Hal_ReadCosNegHighFall'
   *  FunctionCaller: '<S102>/Hal_ReadCosNegLowFall'
   *  FunctionCaller: '<S102>/Hal_ReadCosPosiHighRise'
   *  FunctionCaller: '<S102>/Hal_ReadCosPosiLowRise'
   *  FunctionCaller: '<S102>/Hal_ReadExcHighVal'
   *  FunctionCaller: '<S102>/Hal_ReadExcHighVal1'
   *  FunctionCaller: '<S102>/Hal_ReadExcLowVal'
   *  FunctionCaller: '<S102>/Hal_ReadExcLowVal1'
   *  FunctionCaller: '<S102>/Hal_ReadPhaseACurrentAD'
   *  FunctionCaller: '<S102>/Hal_ReadPhaseCCurrentAD'
   *  FunctionCaller: '<S102>/Hal_ReadSinNegHighFall'
   *  FunctionCaller: '<S102>/Hal_ReadSinNegLowFall'
   *  FunctionCaller: '<S102>/Hal_ReadSinPosiLowRise'
   *  FunctionCaller: '<S102>/ReadSinPosiHighRise'
   *  UnitDelay: '<S90>/Unit Delay'
   */
  if (McuFunSafeMonitor_DW.UnitDelay_DSTATE_p >= MFSM_FastDiagInitTimeCount_C) {
    /* Sum: '<S258>/Add' incorporates:
     *  DataStoreWrite: '<S264>/Data Store Write'
     *  Inport: '<Root>/SGRD_CosEnvelope'
     *  Inport: '<Root>/SGRD_SinEnvelope'
     *  Product: '<S258>/Product'
     *  Product: '<S258>/Product1'
     */
    MFSM_RslvrAmpSum = SGRD_SinEnvelope * SGRD_SinEnvelope + SGRD_CosEnvelope *
      SGRD_CosEnvelope;

    /* Sum: '<S259>/Add2' incorporates:
     *  Constant: '<S259>/0 Constant4'
     *  Constant: '<S260>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxRslvrAmp_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S259>/Multiport Switch' incorporates:
     *  Constant: '<S259>/0 Constant'
     *  Constant: '<S265>/Constant'
     *  Constant: '<S266>/Constant'
     *  DataStoreWrite: '<S264>/Data Store Write'
     *  Logic: '<S258>/Logical Operator1'
     *  Logic: '<S258>/NOT'
     *  MinMax: '<S259>/Max'
     *  RelationalOperator: '<S258>/Relational Operator1'
     *  RelationalOperator: '<S258>/Relational Operator3'
     *  Sum: '<S259>/Add'
     *  Sum: '<S259>/Add1'
     *  UnitDelay: '<S269>/Bare Unit Delay'
     */
    if ((MFSM_RslvrAmpSum < MFSM_AmpHigh_C) && (MFSM_RslvrAmpSum > MFSM_AmpLow_C))
    {
      /* Sum: '<S259>/Add' incorporates:
       *  Constant: '<S262>/Constant'
       *  UnitDelay: '<S269>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE -
        MFSM_DebounceDecrRslvrAmp_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE) {
        /* MinMax: '<S259>/Max' incorporates:
         *  Constant: '<S259>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S259>/Max' incorporates:
         *  UnitDelay: '<S269>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE;
      }

      /* Sum: '<S259>/Add1' incorporates:
       *  Constant: '<S261>/Constant'
       *  MinMax: '<S259>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrRslvrAmp_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S259>/Multiport Switch' */

    /* Switch: '<S269>/Enable' incorporates:
     *  Constant: '<S259>/Constant2'
     *  Logic: '<S269>/Logical Operator2'
     *  Switch: '<S269>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1 && true) {
      /* Switch: '<S267>/Switch2' incorporates:
       *  Constant: '<S259>/0 Constant1'
       *  RelationalOperator: '<S267>/LowerRelop1'
       *  RelationalOperator: '<S267>/UpperRelop'
       *  Sum: '<S259>/Add2'
       *  Switch: '<S267>/Switch'
       *  UnitDelay: '<S269>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S267>/Switch' incorporates:
         *  Constant: '<S259>/0 Constant1'
         *  UnitDelay: '<S269>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S267>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1) {
      /* Switch: '<S269>/Reset' incorporates:
       *  Constant: '<S269>/iv'
       *  UnitDelay: '<S269>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE = ((uint8_T)0U);
    }

    /* End of Switch: '<S269>/Enable' */

    /* Switch: '<S268>/Switch' incorporates:
     *  Constant: '<S263>/Constant'
     *  Constant: '<S268>/Constant1'
     *  Memory: '<S268>/Memory'
     *  RelationalOperator: '<S259>/Relational Operator'
     *  RelationalOperator: '<S259>/Relational Operator1'
     *  Sum: '<S259>/Add2'
     *  Switch: '<S268>/Switch1'
     *  UnitDelay: '<S269>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      rtb_Switch_ae = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE <=
               MFSM_DebounceMinRslvrAmp_C) {
      /* Switch: '<S268>/Switch1' incorporates:
       *  Constant: '<S268>/Constant4'
       */
      rtb_Switch_ae = false;
    } else {
      rtb_Switch_ae = McuFunSafeMonitor_DW.Memory_PreviousInput;
    }

    /* End of Switch: '<S268>/Switch' */

    /* DataTypeConversion: '<S107>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S268>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion = rtb_Switch_ae;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadCosPosiLow();

    /* DataTypeConversion: '<S102>/Data Type Conversion7' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadCosPosiLowRise'
     */
    rtb_Max2 = rtb_Hal_ReadSinNegLowFall;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadCosPosiHigh();

    /* DataTypeConversion: '<S102>/Data Type Conversion6' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadCosPosiHighRise'
     */
    rtb_DataTypeConversion12_tmp = rtb_Hal_ReadSinNegLowFall;

    /* MinMax: '<S102>/Min2' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion6'
     */
    if ((real32_T)rtb_Max2 <= rtb_Hal_ReadSinNegLowFall) {
      rtb_Min2 = (int32_T)(real32_T)rtb_Max2;
    } else {
      rtb_Min2 = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Min2' */
    rtb_Hal_ReadSinNegLowFall = Hal_ReadCosNegHigh();

    /* DataTypeConversion: '<S102>/Data Type Conversion8' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadCosNegHighFall'
     */
    rtb_Min3 = rtb_Hal_ReadSinNegLowFall;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadCosNegLow();

    /* MinMax: '<S102>/Max3' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion9'
     *  FunctionCaller: '<S102>/Hal_ReadCosNegLowFall'
     */
    if ((real32_T)rtb_Min3 >= rtb_Hal_ReadSinNegLowFall) {
      rtb_Max3 = (int32_T)(real32_T)rtb_Min3;
    } else {
      rtb_Max3 = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Max3' */

    /* Sum: '<S95>/Subtract1' incorporates:
     *  DataStoreWrite: '<S122>/Data Store Write'
     */
    MFSM_CosSum = (real32_T)(rtb_Min2 + rtb_Max3);

    /* MinMax: '<S102>/Max2' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion6'
     */
    if ((real32_T)rtb_Max2 >= rtb_DataTypeConversion12_tmp) {
      rtb_Max2 = (int32_T)(real32_T)rtb_Max2;
    } else {
      rtb_Max2 = (int32_T)(real32_T)rtb_DataTypeConversion12_tmp;
    }

    /* End of MinMax: '<S102>/Max2' */

    /* MinMax: '<S102>/Min3' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion9'
     */
    if ((real32_T)rtb_Min3 <= rtb_Hal_ReadSinNegLowFall) {
      rtb_Min3 = (int32_T)(real32_T)rtb_Min3;
    } else {
      rtb_Min3 = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Min3' */

    /* Sum: '<S95>/Subtract' incorporates:
     *  DataStoreWrite: '<S123>/Data Store Write'
     */
    MFSM_CosDiff = (real32_T)(rtb_Max2 - rtb_Min3);

    /* Sum: '<S121>/Add2' incorporates:
     *  Constant: '<S121>/0 Constant4'
     *  Constant: '<S125>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)MFSM_DebounceMaxCosOpen_C
      + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S121>/Multiport Switch' incorporates:
     *  Constant: '<S121>/0 Constant'
     *  Constant: '<S124>/Constant'
     *  Constant: '<S129>/Constant'
     *  DataStoreWrite: '<S122>/Data Store Write'
     *  DataStoreWrite: '<S123>/Data Store Write'
     *  Logic: '<S95>/AND'
     *  MinMax: '<S121>/Max'
     *  RelationalOperator: '<S95>/Relational Operator1'
     *  RelationalOperator: '<S95>/Relational Operator2'
     *  Sum: '<S121>/Add'
     *  Sum: '<S121>/Add1'
     *  UnitDelay: '<S132>/Bare Unit Delay'
     */
    if ((!(MFSM_CosDiff > MFSM_MinCosOpenValue_C)) || (!(MFSM_CosSum <
          MFSM_MaxCosOpenValue_C))) {
      /* Sum: '<S121>/Add' incorporates:
       *  Constant: '<S127>/Constant'
       *  UnitDelay: '<S132>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p -
        MFSM_DebounceDecrCosOpen_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p) {
        /* MinMax: '<S121>/Max' incorporates:
         *  Constant: '<S121>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S121>/Max' incorporates:
         *  UnitDelay: '<S132>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p;
      }

      /* Sum: '<S121>/Add1' incorporates:
       *  Constant: '<S126>/Constant'
       *  MinMax: '<S121>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrCosOpen_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S121>/Multiport Switch' */

    /* Switch: '<S132>/Enable' incorporates:
     *  Constant: '<S121>/Constant2'
     *  Logic: '<S132>/Logical Operator2'
     *  Switch: '<S132>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_f && true) {
      /* Switch: '<S130>/Switch2' incorporates:
       *  Constant: '<S121>/0 Constant1'
       *  RelationalOperator: '<S130>/LowerRelop1'
       *  RelationalOperator: '<S130>/UpperRelop'
       *  Sum: '<S121>/Add2'
       *  Switch: '<S130>/Switch'
       *  UnitDelay: '<S132>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S130>/Switch' incorporates:
         *  Constant: '<S121>/0 Constant1'
         *  UnitDelay: '<S132>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S130>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_m) {
      /* Switch: '<S132>/Reset' incorporates:
       *  Constant: '<S132>/iv'
       *  UnitDelay: '<S132>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p = ((uint8_T)0U);
    }

    /* End of Switch: '<S132>/Enable' */

    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S128>/Constant'
     *  Constant: '<S131>/Constant1'
     *  Memory: '<S131>/Memory'
     *  RelationalOperator: '<S121>/Relational Operator'
     *  RelationalOperator: '<S121>/Relational Operator1'
     *  Sum: '<S121>/Add2'
     *  Switch: '<S131>/Switch1'
     *  UnitDelay: '<S132>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      rtb_Switch_go = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_p <=
               MFSM_DebounceMinCosOpen_C) {
      /* Switch: '<S131>/Switch1' incorporates:
       *  Constant: '<S131>/Constant4'
       */
      rtb_Switch_go = false;
    } else {
      rtb_Switch_go = McuFunSafeMonitor_DW.Memory_PreviousInput_p;
    }

    /* End of Switch: '<S131>/Switch' */

    /* DataTypeConversion: '<S95>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S131>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_m = rtb_Switch_go;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadExcPosiLow();

    /* DataTypeConversion: '<S102>/Data Type Conversion11' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadExcLowVal'
     */
    rtb_DataTypeConversion11 = rtb_Hal_ReadSinNegLowFall;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadExcNegHigh();

    /* DataTypeConversion: '<S102>/Data Type Conversion12' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadExcHighVal1'
     */
    rtb_DataTypeConversion12 = rtb_Hal_ReadSinNegLowFall;

    /* Sum: '<S156>/Add1' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion12'
     */
    rtb_Min1_tmp_tmp = (real32_T)(rtb_DataTypeConversion11 -
      rtb_Hal_ReadSinNegLowFall);

    /* DataStoreWrite: '<S160>/Data Store Write' incorporates:
     *  Sum: '<S156>/Add1'
     */
    MFSM_ExcDiffLow = rtb_Min1_tmp_tmp;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadExcPosiHigh();

    /* DataTypeConversion: '<S102>/Data Type Conversion10' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadExcHighVal'
     */
    rtb_DataTypeConversion10 = rtb_Hal_ReadSinNegLowFall;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadExcNegLow();

    /* DataTypeConversion: '<S102>/Data Type Conversion13' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadExcLowVal1'
     */
    rtb_Switch3 = rtb_Hal_ReadSinNegLowFall;

    /* Sum: '<S156>/Add' incorporates:
     *  DataStoreWrite: '<S161>/Data Store Write'
     *  DataTypeConversion: '<S102>/Data Type Conversion13'
     *  Sum: '<S100>/Add'
     *  Sum: '<S99>/Add'
     */
    rtb_Max = rtb_DataTypeConversion10 - rtb_Hal_ReadSinNegLowFall;
    MFSM_ExcDiffHigh = (real32_T)rtb_Max;

    /* Sum: '<S151>/Add2' incorporates:
     *  Constant: '<S151>/0 Constant4'
     *  Constant: '<S152>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)MFSM_DebounceMaxExcAmp_C
      + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S151>/Multiport Switch' incorporates:
     *  Constant: '<S151>/0 Constant'
     *  Constant: '<S162>/Constant'
     *  Constant: '<S163>/Constant'
     *  Constant: '<S164>/Constant'
     *  Constant: '<S165>/Constant'
     *  DataStoreWrite: '<S161>/Data Store Write'
     *  Logic: '<S156>/AND'
     *  Logic: '<S156>/AND1'
     *  Logic: '<S156>/AND2'
     *  Logic: '<S156>/NOT'
     *  Logic: '<S156>/NOT1'
     *  MinMax: '<S151>/Max'
     *  RelationalOperator: '<S156>/Relational Operator1'
     *  RelationalOperator: '<S156>/Relational Operator2'
     *  RelationalOperator: '<S156>/Relational Operator3'
     *  RelationalOperator: '<S156>/Relational Operator4'
     *  Sum: '<S151>/Add'
     *  Sum: '<S151>/Add1'
     *  Sum: '<S156>/Add1'
     *  UnitDelay: '<S159>/Bare Unit Delay'
     */
    if ((MFSM_ExcDiffHigh < MFSM_ExcMaxHighValue_C) && (MFSM_ExcDiffHigh >
         MFSM_ExcMaxLowValue_C) && ((rtb_Min1_tmp_tmp < MFSM_ExcMinHighValue_C) &&
         (rtb_Min1_tmp_tmp > MFSM_ExcMinLowValue_C))) {
      /* Sum: '<S151>/Add' incorporates:
       *  Constant: '<S154>/Constant'
       *  UnitDelay: '<S159>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n -
        MFSM_DebounceDecrExcAmp_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n) {
        /* MinMax: '<S151>/Max' incorporates:
         *  Constant: '<S151>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S151>/Max' incorporates:
         *  UnitDelay: '<S159>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n;
      }

      /* Sum: '<S151>/Add1' incorporates:
       *  Constant: '<S153>/Constant'
       *  MinMax: '<S151>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrExcAmp_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S151>/Multiport Switch' */

    /* Switch: '<S159>/Enable' incorporates:
     *  Constant: '<S151>/Constant2'
     *  Logic: '<S159>/Logical Operator2'
     *  Switch: '<S159>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_o && true) {
      /* Switch: '<S157>/Switch2' incorporates:
       *  Constant: '<S151>/0 Constant1'
       *  RelationalOperator: '<S157>/LowerRelop1'
       *  RelationalOperator: '<S157>/UpperRelop'
       *  Sum: '<S151>/Add2'
       *  Switch: '<S157>/Switch'
       *  UnitDelay: '<S159>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S157>/Switch' incorporates:
         *  Constant: '<S151>/0 Constant1'
         *  UnitDelay: '<S159>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S157>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_j) {
      /* Switch: '<S159>/Reset' incorporates:
       *  Constant: '<S159>/iv'
       *  UnitDelay: '<S159>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n = ((uint8_T)0U);
    }

    /* End of Switch: '<S159>/Enable' */

    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S155>/Constant'
     *  Constant: '<S158>/Constant1'
     *  Memory: '<S158>/Memory'
     *  RelationalOperator: '<S151>/Relational Operator'
     *  RelationalOperator: '<S151>/Relational Operator1'
     *  Sum: '<S151>/Add2'
     *  Switch: '<S158>/Switch1'
     *  UnitDelay: '<S159>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      rtb_Switch_kl = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n <=
               MFSM_DebounceMinExcAmp_C) {
      /* Switch: '<S158>/Switch1' incorporates:
       *  Constant: '<S158>/Constant4'
       */
      rtb_Switch_kl = false;
    } else {
      rtb_Switch_kl = McuFunSafeMonitor_DW.Memory_PreviousInput_h;
    }

    /* End of Switch: '<S158>/Switch' */

    /* DataTypeConversion: '<S98>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S158>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_n = rtb_Switch_kl;

    /* Gain: '<S99>/Gain' incorporates:
     *  DataStoreWrite: '<S167>/Data Store Write'
     *  Sum: '<S99>/Add1'
     */
    MFSM_ExcAmpAve = (real32_T)((rtb_Max + rtb_DataTypeConversion12) -
      rtb_DataTypeConversion11) * 0.5F;

    /* Sum: '<S166>/Add2' incorporates:
     *  Constant: '<S166>/0 Constant4'
     *  Constant: '<S168>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)MFSM_DebounceMaxExcOpen_C
      + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S166>/Multiport Switch' incorporates:
     *  Constant: '<S166>/0 Constant'
     *  Constant: '<S172>/Constant'
     *  DataStoreWrite: '<S167>/Data Store Write'
     *  MinMax: '<S166>/Max'
     *  RelationalOperator: '<S99>/Relational Operator1'
     *  Sum: '<S166>/Add'
     *  Sum: '<S166>/Add1'
     *  UnitDelay: '<S175>/Bare Unit Delay'
     */
    if (!(MFSM_ExcAmpAve < MFSM_ExcOpenValue_C)) {
      /* Sum: '<S166>/Add' incorporates:
       *  Constant: '<S170>/Constant'
       *  UnitDelay: '<S175>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l -
        MFSM_DebounceDecrExcOpen_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l) {
        /* MinMax: '<S166>/Max' incorporates:
         *  Constant: '<S166>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S166>/Max' incorporates:
         *  UnitDelay: '<S175>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l;
      }

      /* Sum: '<S166>/Add1' incorporates:
       *  Constant: '<S169>/Constant'
       *  MinMax: '<S166>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrExcOpen_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S166>/Multiport Switch' */

    /* Switch: '<S175>/Enable' incorporates:
     *  Constant: '<S166>/Constant2'
     *  Logic: '<S175>/Logical Operator2'
     *  Switch: '<S175>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_l && true) {
      /* Switch: '<S173>/Switch2' incorporates:
       *  Constant: '<S166>/0 Constant1'
       *  RelationalOperator: '<S173>/LowerRelop1'
       *  RelationalOperator: '<S173>/UpperRelop'
       *  Sum: '<S166>/Add2'
       *  Switch: '<S173>/Switch'
       *  UnitDelay: '<S175>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S173>/Switch' incorporates:
         *  Constant: '<S166>/0 Constant1'
         *  UnitDelay: '<S175>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S173>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_p) {
      /* Switch: '<S175>/Reset' incorporates:
       *  Constant: '<S175>/iv'
       *  UnitDelay: '<S175>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l = ((uint8_T)0U);
    }

    /* End of Switch: '<S175>/Enable' */

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S171>/Constant'
     *  Constant: '<S174>/Constant1'
     *  Memory: '<S174>/Memory'
     *  RelationalOperator: '<S166>/Relational Operator'
     *  RelationalOperator: '<S166>/Relational Operator1'
     *  Sum: '<S166>/Add2'
     *  Switch: '<S174>/Switch1'
     *  UnitDelay: '<S175>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      rtb_Switch_a = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_l <=
               MFSM_DebounceMinExcOpen_C) {
      /* Switch: '<S174>/Switch1' incorporates:
       *  Constant: '<S174>/Constant4'
       */
      rtb_Switch_a = false;
    } else {
      rtb_Switch_a = McuFunSafeMonitor_DW.Memory_PreviousInput_i;
    }

    /* End of Switch: '<S174>/Switch' */

    /* DataTypeConversion: '<S99>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S174>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_p = rtb_Switch_a;

    /* Gain: '<S100>/Gain' incorporates:
     *  DataStoreWrite: '<S177>/Data Store Write'
     *  Sum: '<S100>/Add1'
     */
    MFSM_ExcAveVal = (real32_T)((rtb_Max + rtb_DataTypeConversion11) -
      rtb_DataTypeConversion12) * 0.5F;

    /* Sum: '<S176>/Add2' incorporates:
     *  Constant: '<S176>/0 Constant4'
     *  Constant: '<S178>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxExcShortGnd_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S176>/Multiport Switch' incorporates:
     *  Constant: '<S176>/0 Constant'
     *  Constant: '<S182>/Constant'
     *  DataStoreWrite: '<S177>/Data Store Write'
     *  MinMax: '<S176>/Max'
     *  RelationalOperator: '<S100>/Relational Operator1'
     *  Sum: '<S176>/Add'
     *  Sum: '<S176>/Add1'
     *  UnitDelay: '<S185>/Bare Unit Delay'
     */
    if (!(MFSM_ExcAveVal < MFSM_ExcShortGndValue_C)) {
      /* Sum: '<S176>/Add' incorporates:
       *  Constant: '<S180>/Constant'
       *  UnitDelay: '<S185>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 -
        MFSM_DebounceDecrExcShortGnd_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5) {
        /* MinMax: '<S176>/Max' incorporates:
         *  Constant: '<S176>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S176>/Max' incorporates:
         *  UnitDelay: '<S185>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5;
      }

      /* Sum: '<S176>/Add1' incorporates:
       *  Constant: '<S179>/Constant'
       *  MinMax: '<S176>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrExcShortGnd_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S176>/Multiport Switch' */

    /* Switch: '<S185>/Enable' incorporates:
     *  Constant: '<S176>/Constant2'
     *  Logic: '<S185>/Logical Operator2'
     *  Switch: '<S185>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_m && true) {
      /* Switch: '<S183>/Switch2' incorporates:
       *  Constant: '<S176>/0 Constant1'
       *  RelationalOperator: '<S183>/LowerRelop1'
       *  RelationalOperator: '<S183>/UpperRelop'
       *  Sum: '<S176>/Add2'
       *  Switch: '<S183>/Switch'
       *  UnitDelay: '<S185>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S183>/Switch' incorporates:
         *  Constant: '<S176>/0 Constant1'
         *  UnitDelay: '<S185>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S183>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_jr) {
      /* Switch: '<S185>/Reset' incorporates:
       *  Constant: '<S185>/iv'
       *  UnitDelay: '<S185>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 = ((uint8_T)0U);
    }

    /* End of Switch: '<S185>/Enable' */

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S181>/Constant'
     *  Constant: '<S184>/Constant1'
     *  Memory: '<S184>/Memory'
     *  RelationalOperator: '<S176>/Relational Operator'
     *  RelationalOperator: '<S176>/Relational Operator1'
     *  Sum: '<S176>/Add2'
     *  Switch: '<S184>/Switch1'
     *  UnitDelay: '<S185>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      rtb_Switch_cg = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_n5 <=
               MFSM_DebounceMinExcShortGnd_C) {
      /* Switch: '<S184>/Switch1' incorporates:
       *  Constant: '<S184>/Constant4'
       */
      rtb_Switch_cg = false;
    } else {
      rtb_Switch_cg = McuFunSafeMonitor_DW.Memory_PreviousInput_m;
    }

    /* End of Switch: '<S184>/Switch' */

    /* DataTypeConversion: '<S100>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S184>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_f = rtb_Switch_cg;

    /* Sum: '<S191>/Add1' */
    rtb_Min1_tmp_tmp = (real32_T)(rtb_DataTypeConversion11 -
      rtb_DataTypeConversion12);

    /* Gain: '<S191>/Gain' incorporates:
     *  DataStoreWrite: '<S195>/Data Store Write'
     *  Sum: '<S156>/Add'
     *  Sum: '<S191>/Add1'
     *  Sum: '<S191>/Add3'
     */
    MFSM_ExcShortPwr_Max = ((real32_T)rtb_Max + rtb_Min1_tmp_tmp) * 0.5F;

    /* Sum: '<S191>/Add2' incorporates:
     *  DataStoreWrite: '<S196>/Data Store Write'
     *  Sum: '<S156>/Add'
     *  Sum: '<S191>/Add1'
     */
    MFSM_ExcShortPwr_Min = (real32_T)rtb_Max - rtb_Min1_tmp_tmp;

    /* Sum: '<S186>/Add2' incorporates:
     *  Constant: '<S186>/0 Constant4'
     *  Constant: '<S187>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxExcShortGnd_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S186>/Multiport Switch' incorporates:
     *  Constant: '<S186>/0 Constant'
     *  Constant: '<S197>/Constant'
     *  Constant: '<S198>/Constant'
     *  DataStoreWrite: '<S195>/Data Store Write'
     *  DataStoreWrite: '<S196>/Data Store Write'
     *  Logic: '<S191>/AND'
     *  MinMax: '<S186>/Max'
     *  RelationalOperator: '<S191>/Relational Operator1'
     *  RelationalOperator: '<S191>/Relational Operator2'
     *  Sum: '<S186>/Add'
     *  Sum: '<S186>/Add1'
     *  UnitDelay: '<S194>/Bare Unit Delay'
     */
    if ((!(MFSM_ExcShortPwr_Min < MFSM_ExcShortGndValue_C)) ||
        (!(MFSM_ExcShortPwr_Max > MFSM_ExcShortPwrValue_C))) {
      /* Sum: '<S186>/Add' incorporates:
       *  Constant: '<S189>/Constant'
       *  UnitDelay: '<S194>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf -
        MFSM_DebounceDecrExcShortGnd_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf) {
        /* MinMax: '<S186>/Max' incorporates:
         *  Constant: '<S186>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S186>/Max' incorporates:
         *  UnitDelay: '<S194>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf;
      }

      /* Sum: '<S186>/Add1' incorporates:
       *  Constant: '<S188>/Constant'
       *  MinMax: '<S186>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrExcShortGnd_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S186>/Multiport Switch' */

    /* Switch: '<S194>/Enable' incorporates:
     *  Constant: '<S186>/Constant2'
     *  Logic: '<S194>/Logical Operator2'
     *  Switch: '<S194>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_g && true) {
      /* Switch: '<S192>/Switch2' incorporates:
       *  Constant: '<S186>/0 Constant1'
       *  RelationalOperator: '<S192>/LowerRelop1'
       *  RelationalOperator: '<S192>/UpperRelop'
       *  Sum: '<S186>/Add2'
       *  Switch: '<S192>/Switch'
       *  UnitDelay: '<S194>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S192>/Switch' incorporates:
         *  Constant: '<S186>/0 Constant1'
         *  UnitDelay: '<S194>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S192>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_g) {
      /* Switch: '<S194>/Reset' incorporates:
       *  Constant: '<S194>/iv'
       *  UnitDelay: '<S194>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf = ((uint8_T)0U);
    }

    /* End of Switch: '<S194>/Enable' */

    /* Switch: '<S193>/Switch' incorporates:
     *  Constant: '<S190>/Constant'
     *  Constant: '<S193>/Constant1'
     *  Memory: '<S193>/Memory'
     *  RelationalOperator: '<S186>/Relational Operator'
     *  RelationalOperator: '<S186>/Relational Operator1'
     *  Sum: '<S186>/Add2'
     *  Switch: '<S193>/Switch1'
     *  UnitDelay: '<S194>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      rtb_Switch_os = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_lf <=
               MFSM_DebounceMinExcShortGnd_C) {
      /* Switch: '<S193>/Switch1' incorporates:
       *  Constant: '<S193>/Constant4'
       */
      rtb_Switch_os = false;
    } else {
      rtb_Switch_os = McuFunSafeMonitor_DW.Memory_PreviousInput_mz;
    }

    /* End of Switch: '<S193>/Switch' */

    /* DataTypeConversion: '<S101>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S193>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_o = rtb_Switch_os;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadSinPosiHigh();

    /* DataTypeConversion: '<S102>/Data Type Conversion2' incorporates:
     *  FunctionCaller: '<S102>/ReadSinPosiHighRise'
     */
    rtb_Min1_tmp_tmp = rtb_Hal_ReadSinNegLowFall;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadSinPosiLow();

    /* MinMax: '<S102>/Max' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion4'
     *  FunctionCaller: '<S102>/Hal_ReadSinPosiLowRise'
     */
    if (rtb_Min1_tmp_tmp >= rtb_Hal_ReadSinNegLowFall) {
      rtb_Max = (int32_T)rtb_Min1_tmp_tmp;
    } else {
      rtb_Max = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Max' */

    /* DataStoreWrite: '<S206>/Data Store Write' */
    MFSM_SinPosHigh = (real32_T)rtb_Max;

    /* MinMax: '<S102>/Min' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion4'
     */
    if (!(rtb_Min1_tmp_tmp <= rtb_Hal_ReadSinNegLowFall)) {
      rtb_Min1_tmp_tmp = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Min' */

    /* DataStoreWrite: '<S208>/Data Store Write' */
    MFSM_SinPosLow = rtb_Min1_tmp_tmp;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadSinNegHigh();

    /* DataTypeConversion: '<S102>/Data Type Conversion3' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadSinNegHighFall'
     */
    rtb_Min1 = rtb_Hal_ReadSinNegLowFall;
    rtb_Hal_ReadSinNegLowFall = Hal_ReadSinNegLow();

    /* MinMax: '<S102>/Max1' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion5'
     *  FunctionCaller: '<S102>/Hal_ReadSinNegLowFall'
     */
    if (rtb_Min1 >= rtb_Hal_ReadSinNegLowFall) {
      rtb_Saturation = rtb_Min1;
    } else {
      rtb_Saturation = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Max1' */

    /* DataStoreWrite: '<S207>/Data Store Write' */
    MFSM_SinNegHigh = rtb_Saturation;

    /* MinMax: '<S102>/Min1' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion5'
     */
    if (!(rtb_Min1 <= rtb_Hal_ReadSinNegLowFall)) {
      rtb_Min1 = rtb_Hal_ReadSinNegLowFall;
    }

    /* End of MinMax: '<S102>/Min1' */

    /* DataStoreWrite: '<S209>/Data Store Write' */
    MFSM_SinNegLow = rtb_Min1;

    /* DataStoreWrite: '<S210>/Data Store Write' */
    MFSM_CosPosHigh = (real32_T)rtb_Max2;

    /* DataStoreWrite: '<S212>/Data Store Write' */
    MFSM_CosPosLow = (real32_T)rtb_Min2;

    /* DataStoreWrite: '<S199>/Data Store Write' */
    MFSM_CosNegLow = (real32_T)rtb_Min3;

    /* DataStoreWrite: '<S211>/Data Store Write' */
    MFSM_CosNegHigh = (real32_T)rtb_Max3;

    /* DataStoreWrite: '<S200>/Data Store Write' */
    MFSM_ExcPosHigh = (real32_T)rtb_DataTypeConversion10;

    /* DataStoreWrite: '<S201>/Data Store Write' */
    MFSM_ExcPosLow = (real32_T)rtb_DataTypeConversion11;

    /* DataStoreWrite: '<S202>/Data Store Write' */
    MFSM_ExcNegHigh = (real32_T)rtb_DataTypeConversion12;

    /* DataStoreWrite: '<S203>/Data Store Write' */
    MFSM_ExcNegLow = rtb_Switch3;
    rtb_Hal_ReadPhaseCCurrentAD = Hal_ReadPhaseACurrentAD();

    /* DataTypeConversion: '<S102>/Data Type Conversion14' incorporates:
     *  FunctionCaller: '<S102>/Hal_ReadPhaseACurrentAD'
     */
    rtb_Switch3 = rtb_Hal_ReadPhaseCCurrentAD;

    /* DataStoreWrite: '<S204>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S102>/Data Type Conversion14'
     */
    MFSM_PhaseA = (real32_T)rtb_Hal_ReadPhaseCCurrentAD;
    rtb_Hal_ReadPhaseCCurrentAD = Hal_ReadPhaseCCurrentAD();

    /* DataTypeConversion: '<S102>/Data Type Conversion15' incorporates:
     *  DataStoreWrite: '<S205>/Data Store Write'
     *  FunctionCaller: '<S102>/Hal_ReadPhaseCCurrentAD'
     */
    MFSM_PhaseC = (real32_T)rtb_Hal_ReadPhaseCCurrentAD;

    /* Abs: '<S218>/Abs1' incorporates:
     *  DataStoreWrite: '<S205>/Data Store Write'
     *  DataStoreWrite: '<S222>/Data Store Write'
     *  Gain: '<S218>/Gain2'
     *  Inport: '<Root>/SGSA_PhaseCCurrentAD'
     *  Sum: '<S218>/Subtract1'
     */
    MFSM_PhaseCDiff = (real32_T)fabs(SGSA_PhaseCCurrentAD - 0.00122070312F *
      MFSM_PhaseC);

    /* Abs: '<S218>/Abs' incorporates:
     *  DataStoreWrite: '<S223>/Data Store Write'
     *  DataTypeConversion: '<S102>/Data Type Conversion14'
     *  Gain: '<S218>/Gain1'
     *  Inport: '<Root>/SGSA_PhaseACurrentAD'
     *  Sum: '<S218>/Subtract'
     */
    MFSM_PhaseADiff = (real32_T)fabs(SGSA_PhaseACurrentAD - 0.00122070312F *
      rtb_Switch3);

    /* Sum: '<S213>/Add2' incorporates:
     *  Constant: '<S213>/0 Constant4'
     *  Constant: '<S214>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxPhaCurrDiff_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S213>/Multiport Switch' incorporates:
     *  Constant: '<S213>/0 Constant'
     *  Constant: '<S224>/Constant'
     *  DataStoreWrite: '<S222>/Data Store Write'
     *  DataStoreWrite: '<S223>/Data Store Write'
     *  Logic: '<S218>/AND2'
     *  MinMax: '<S213>/Max'
     *  RelationalOperator: '<S218>/Relational Operator4'
     *  Sum: '<S213>/Add'
     *  Sum: '<S213>/Add1'
     *  UnitDelay: '<S221>/Bare Unit Delay'
     */
    if ((!(MFSM_PhaseADiff > MFSM_PhaCurrDiffValue_C)) && (!(MFSM_PhaseCDiff >
          MFSM_PhaCurrDiffValue_C))) {
      /* Sum: '<S213>/Add' incorporates:
       *  Constant: '<S216>/Constant'
       *  UnitDelay: '<S221>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k -
        MFSM_DebounceDecrPhaCurrDiff_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k) {
        /* MinMax: '<S213>/Max' incorporates:
         *  Constant: '<S213>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S213>/Max' incorporates:
         *  UnitDelay: '<S221>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k;
      }

      /* Sum: '<S213>/Add1' incorporates:
       *  Constant: '<S215>/Constant'
       *  MinMax: '<S213>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrPhaCurrDiff_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S213>/Multiport Switch' */

    /* Switch: '<S221>/Enable' incorporates:
     *  Constant: '<S213>/Constant2'
     *  Logic: '<S221>/Logical Operator2'
     *  Switch: '<S221>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_e && true) {
      /* Switch: '<S219>/Switch2' incorporates:
       *  Constant: '<S213>/0 Constant1'
       *  RelationalOperator: '<S219>/LowerRelop1'
       *  RelationalOperator: '<S219>/UpperRelop'
       *  Sum: '<S213>/Add2'
       *  Switch: '<S219>/Switch'
       *  UnitDelay: '<S221>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S219>/Switch' incorporates:
         *  Constant: '<S213>/0 Constant1'
         *  UnitDelay: '<S221>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S219>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_md) {
      /* Switch: '<S221>/Reset' incorporates:
       *  Constant: '<S221>/iv'
       *  UnitDelay: '<S221>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k = ((uint8_T)0U);
    }

    /* End of Switch: '<S221>/Enable' */

    /* Switch: '<S220>/Switch' incorporates:
     *  Constant: '<S217>/Constant'
     *  RelationalOperator: '<S213>/Relational Operator'
     *  RelationalOperator: '<S213>/Relational Operator1'
     *  Sum: '<S213>/Add2'
     *  Switch: '<S220>/Switch1'
     *  UnitDelay: '<S221>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S220>/Switch' incorporates:
       *  Constant: '<S220>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_f = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_k <=
               MFSM_DebounceMinPhaCurrDiff_C) {
      /* Switch: '<S220>/Switch' incorporates:
       *  Constant: '<S220>/Constant4'
       *  Switch: '<S220>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_f = false;
    }

    /* End of Switch: '<S220>/Switch' */

    /* DataTypeConversion: '<S103>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S220>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_fo =
      McuFunSafeMonitor_DW.Memory_PreviousInput_f;

    /* Sum: '<S230>/Subtract1' incorporates:
     *  DataStoreWrite: '<S205>/Data Store Write'
     *  DataStoreWrite: '<S234>/Data Store Write'
     *  Gain: '<S230>/Gain1'
     *  Inport: '<Root>/SGSA_PhaseCCurrentAD'
     */
    MFSM_PhaseCCurrentDiff = SGSA_PhaseCCurrentAD - 0.00122070312F * MFSM_PhaseC;

    /* Sum: '<S230>/Subtract' incorporates:
     *  DataStoreWrite: '<S235>/Data Store Write'
     *  DataTypeConversion: '<S102>/Data Type Conversion14'
     *  Gain: '<S230>/Gain2'
     *  Inport: '<Root>/SGSA_PhaseACurrentAD'
     */
    MFSM_PhaseACurrentDiff = SGSA_PhaseACurrentAD - 0.00122070312F * rtb_Switch3;

    /* Sum: '<S225>/Add2' incorporates:
     *  Constant: '<S225>/0 Constant4'
     *  Constant: '<S226>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)MFSM_DebounceMaxOpen_C +
      ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S225>/Multiport Switch' incorporates:
     *  Abs: '<S230>/Abs'
     *  Constant: '<S225>/0 Constant'
     *  Constant: '<S236>/Constant'
     *  Constant: '<S237>/Constant'
     *  DataStoreWrite: '<S234>/Data Store Write'
     *  DataStoreWrite: '<S235>/Data Store Write'
     *  Inport: '<Root>/SGSA_PhaseACurrentAD'
     *  Inport: '<Root>/SGSA_PhaseCCurrentAD'
     *  Logic: '<S230>/AND'
     *  Logic: '<S230>/AND1'
     *  Logic: '<S230>/AND2'
     *  MinMax: '<S225>/Max'
     *  RelationalOperator: '<S230>/Relational Operator1'
     *  RelationalOperator: '<S230>/Relational Operator4'
     *  Sum: '<S225>/Add'
     *  Sum: '<S225>/Add1'
     *  UnitDelay: '<S233>/Bare Unit Delay'
     */
    if (((!((real32_T)fabs(MFSM_PhaseACurrentDiff) > MFSM_PhaCurrOpenDiffValue_C))
         || (!(SGSA_PhaseACurrentAD < MFSM_PhaCurrOpenValue_C))) &&
        ((!((real32_T)fabs(MFSM_PhaseCCurrentDiff) > MFSM_PhaCurrOpenDiffValue_C))
         || (!(SGSA_PhaseCCurrentAD < MFSM_PhaCurrOpenValue_C)))) {
      /* Sum: '<S225>/Add' incorporates:
       *  Constant: '<S228>/Constant'
       *  UnitDelay: '<S233>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h -
        MFSM_DebounceDecrOpen_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h) {
        /* MinMax: '<S225>/Max' incorporates:
         *  Constant: '<S225>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S225>/Max' incorporates:
         *  UnitDelay: '<S233>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h;
      }

      /* Sum: '<S225>/Add1' incorporates:
       *  Constant: '<S227>/Constant'
       *  MinMax: '<S225>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrOpen_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S225>/Multiport Switch' */

    /* Switch: '<S233>/Enable' incorporates:
     *  Constant: '<S225>/Constant2'
     *  Logic: '<S233>/Logical Operator2'
     *  Switch: '<S233>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_mt && true) {
      /* Switch: '<S231>/Switch2' incorporates:
       *  Constant: '<S225>/0 Constant1'
       *  RelationalOperator: '<S231>/LowerRelop1'
       *  RelationalOperator: '<S231>/UpperRelop'
       *  Sum: '<S225>/Add2'
       *  Switch: '<S231>/Switch'
       *  UnitDelay: '<S233>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S231>/Switch' incorporates:
         *  Constant: '<S225>/0 Constant1'
         *  UnitDelay: '<S233>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S231>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_gu) {
      /* Switch: '<S233>/Reset' incorporates:
       *  Constant: '<S233>/iv'
       *  UnitDelay: '<S233>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h = ((uint8_T)0U);
    }

    /* End of Switch: '<S233>/Enable' */

    /* Switch: '<S232>/Switch' incorporates:
     *  Constant: '<S229>/Constant'
     *  RelationalOperator: '<S225>/Relational Operator'
     *  RelationalOperator: '<S225>/Relational Operator1'
     *  Sum: '<S225>/Add2'
     *  Switch: '<S232>/Switch1'
     *  UnitDelay: '<S233>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S232>/Switch' incorporates:
       *  Constant: '<S232>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_k = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_h <=
               MFSM_DebounceMinOpen_C) {
      /* Switch: '<S232>/Switch' incorporates:
       *  Constant: '<S232>/Constant4'
       *  Switch: '<S232>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_k = false;
    }

    /* End of Switch: '<S232>/Switch' */

    /* DataTypeConversion: '<S104>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S232>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_e =
      McuFunSafeMonitor_DW.Memory_PreviousInput_k;

    /* Sum: '<S108>/Subtract1' incorporates:
     *  DataStoreWrite: '<S271>/Data Store Write'
     */
    MFSM_SinSum = rtb_Min1_tmp_tmp + rtb_Saturation;

    /* Sum: '<S108>/Subtract' incorporates:
     *  DataStoreWrite: '<S206>/Data Store Write'
     *  DataStoreWrite: '<S272>/Data Store Write'
     */
    MFSM_SinDiff = (real32_T)rtb_Max - rtb_Min1;

    /* Sum: '<S270>/Add2' incorporates:
     *  Constant: '<S270>/0 Constant4'
     *  Constant: '<S274>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)MFSM_DebounceMaxSinOpen_C
      + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S270>/Multiport Switch' incorporates:
     *  Constant: '<S270>/0 Constant'
     *  Constant: '<S273>/Constant'
     *  Constant: '<S278>/Constant'
     *  DataStoreWrite: '<S271>/Data Store Write'
     *  DataStoreWrite: '<S272>/Data Store Write'
     *  Logic: '<S108>/AND'
     *  MinMax: '<S270>/Max'
     *  RelationalOperator: '<S108>/Relational Operator1'
     *  RelationalOperator: '<S108>/Relational Operator2'
     *  Sum: '<S270>/Add'
     *  Sum: '<S270>/Add1'
     *  UnitDelay: '<S281>/Bare Unit Delay'
     */
    if ((!(MFSM_SinDiff > MFSM_MinSinOpenValue_C)) || (!(MFSM_SinSum <
          MFSM_MaxSinOpenValue_C))) {
      /* Sum: '<S270>/Add' incorporates:
       *  Constant: '<S276>/Constant'
       *  UnitDelay: '<S281>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m -
        MFSM_DebounceDecrSinOpen_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m) {
        /* MinMax: '<S270>/Max' incorporates:
         *  Constant: '<S270>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S270>/Max' incorporates:
         *  UnitDelay: '<S281>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m;
      }

      /* Sum: '<S270>/Add1' incorporates:
       *  Constant: '<S275>/Constant'
       *  MinMax: '<S270>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch + MFSM_DebounceIncrSinOpen_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S270>/Multiport Switch' */

    /* Switch: '<S281>/Enable' incorporates:
     *  Constant: '<S270>/Constant2'
     *  Logic: '<S281>/Logical Operator2'
     *  Switch: '<S281>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_f2 && true) {
      /* Switch: '<S279>/Switch2' incorporates:
       *  Constant: '<S270>/0 Constant1'
       *  RelationalOperator: '<S279>/LowerRelop1'
       *  RelationalOperator: '<S279>/UpperRelop'
       *  Sum: '<S270>/Add2'
       *  Switch: '<S279>/Switch'
       *  UnitDelay: '<S281>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S279>/Switch' incorporates:
         *  Constant: '<S270>/0 Constant1'
         *  UnitDelay: '<S281>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S279>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_f) {
      /* Switch: '<S281>/Reset' incorporates:
       *  Constant: '<S281>/iv'
       *  UnitDelay: '<S281>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m = ((uint8_T)0U);
    }

    /* End of Switch: '<S281>/Enable' */

    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S277>/Constant'
     *  RelationalOperator: '<S270>/Relational Operator'
     *  RelationalOperator: '<S270>/Relational Operator1'
     *  Sum: '<S270>/Add2'
     *  Switch: '<S280>/Switch1'
     *  UnitDelay: '<S281>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S280>/Switch' incorporates:
       *  Constant: '<S280>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_hq = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_m <=
               MFSM_DebounceMinSinOpen_C) {
      /* Switch: '<S280>/Switch' incorporates:
       *  Constant: '<S280>/Constant4'
       *  Switch: '<S280>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_hq = false;
    }

    /* End of Switch: '<S280>/Switch' */

    /* DataTypeConversion: '<S108>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S280>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_ee =
      McuFunSafeMonitor_DW.Memory_PreviousInput_hq;

    /* Sum: '<S114>/Add5' incorporates:
     *  Inport: '<Root>/SGPP_BSW_f32_iSmpPhaU_A'
     *  Inport: '<Root>/SGPP_BSW_f32_iSmpPhaW_A'
     *  Sum: '<S111>/Add4'
     */
    MFSM_PhaseBCurrent = (0.0F - SGPP_BSW_f32_iSmpPhaU_A) -
      SGPP_BSW_f32_iSmpPhaW_A;

    /* Switch: '<S115>/Switch3' incorporates:
     *  Constant: '<S118>/Constant'
     *  Constant: '<S119>/Constant'
     *  Interpolation_n-D: '<S115>/Bus Current Coeff Lookup'
     */
    if (MFSM_BusCurrentCalCoeffSel_C != 0) {
      rtb_Switch3 = MFSM_BusCurrentCalCoeff_C;
    } else {
      /* Abs: '<S115>/Abs' incorporates:
       *  Inport: '<Root>/SGPP_BSW_f32_nRotateSpd_rpm'
       */
      rtb_Switch3 = (real32_T)fabs(SGPP_BSW_f32_nRotateSpd_rpm);

      /* PreLookup: '<S115>/Prelookup' */
      rtb_Prelookup_o1_k = plook_u32ff_binx(rtb_Switch3, (real32_T *)
        &MFSM_MechSpd_A[0], 2U, &rtb_Switch3);
      rtb_Switch3 = intrp1d_fu32fl(rtb_Prelookup_o1_k, rtb_Switch3, (real32_T *)
        &MFSM_BusCurrentCompCoeff_M[0]);
    }

    /* End of Switch: '<S115>/Switch3' */

    /* Product: '<S112>/Product' incorporates:
     *  Constant: '<S113>/Constant'
     *  Constant: '<S91>/Constant'
     */
    u0 = MFSM_BusCurrentFilterFreq_C * 9.6E-5F;

    /* Saturate: '<S112>/Saturation' */
    if (u0 > 1.0F) {
      u0 = 1.0F;
    } else if (u0 < 0.0F) {
      u0 = 0.0F;
    }

    /* Sum: '<S112>/Subtract1' incorporates:
     *  DataStoreWrite: '<S117>/Data Store Write'
     *  Delay: '<S112>/Delay'
     *  Delay: '<S114>/Delay'
     *  Delay: '<S114>/Delay1'
     *  Delay: '<S114>/Delay2'
     *  Inport: '<Root>/SGPP_BSW_f32_iSmpPhaU_A'
     *  Inport: '<Root>/SGPP_BSW_f32_iSmpPhaW_A'
     *  Product: '<S112>/Product1'
     *  Product: '<S114>/Product'
     *  Product: '<S114>/Product1'
     *  Product: '<S114>/Product2'
     *  Product: '<S94>/Product3'
     *  Saturate: '<S112>/Saturation'
     *  Sum: '<S112>/Subtract'
     *  Sum: '<S114>/Add4'
     */
    McuFunSafeMonitor_DW.Delay_DSTATE_h += (((SGPP_BSW_f32_iSmpPhaU_A *
      McuFunSafeMonitor_DW.Delay_DSTATE + MFSM_PhaseBCurrent *
      McuFunSafeMonitor_DW.Delay1_DSTATE) + SGPP_BSW_f32_iSmpPhaW_A *
      McuFunSafeMonitor_DW.Delay2_DSTATE) * rtb_Switch3 -
      McuFunSafeMonitor_DW.Delay_DSTATE_h) * u0;

    /* Switch: '<S116>/Switch1' incorporates:
     *  Constant: '<S116>/Constant1_single'
     *  Constant: '<S120>/Constant'
     *  Interpolation_n-D: '<S116>/Bus Current Compensation Lookup Table'
     */
    if (MFSM_BusCurrentCompEna_C != 0) {
      /* PreLookup: '<S116>/Prelookup1' incorporates:
       *  Delay: '<S112>/Delay'
       */
      rtb_Prelookup_o1_k = plook_u32ff_binx(McuFunSafeMonitor_DW.Delay_DSTATE_h,
        (real32_T *)&MFSM_LpfBusCurrent_A[0], 2U, &rtb_Switch3);
      rtb_Switch3 = intrp1d_fu32fl(rtb_Prelookup_o1_k, rtb_Switch3, (real32_T *)
        &MFSM_BusCurrentComp_M[0]);
    } else {
      rtb_Switch3 = 0.0F;
    }

    /* End of Switch: '<S116>/Switch1' */

    /* Sum: '<S94>/Add1' incorporates:
     *  Delay: '<S112>/Delay'
     */
    McuFunSafeMonitor_B.Add1 = McuFunSafeMonitor_DW.Delay_DSTATE_h + rtb_Switch3;

    /* SignalConversion generated from: '<S91>/MFSM_SineDiffFault' */
    McuFunSafeMonitor_B.OutportBufferForMFSM_SineDiffFault = 0U;

    /* SignalConversion generated from: '<S91>/MFSM_CosDiffFault' */
    McuFunSafeMonitor_B.OutportBufferForMFSM_CosDiffFault = 0U;

    /* Sum: '<S133>/Add2' incorporates:
     *  Constant: '<S133>/0 Constant4'
     *  Constant: '<S135>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxCosShortGnd_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S133>/Multiport Switch' incorporates:
     *  Constant: '<S133>/0 Constant'
     *  Constant: '<S134>/Constant'
     *  DataStoreWrite: '<S199>/Data Store Write'
     *  DataStoreWrite: '<S210>/Data Store Write'
     *  DataStoreWrite: '<S211>/Data Store Write'
     *  DataStoreWrite: '<S212>/Data Store Write'
     *  Logic: '<S96>/AND'
     *  MinMax: '<S133>/Max'
     *  RelationalOperator: '<S96>/Relational Operator2'
     *  Sum: '<S133>/Add'
     *  Sum: '<S133>/Add1'
     *  UnitDelay: '<S141>/Bare Unit Delay'
     */
    if ((!(rtb_Max2 < MFSM_CosShortGndValue_C)) || (!(rtb_Max3 <
          MFSM_CosShortGndValue_C)) || (!(rtb_Min2 < MFSM_CosShortGndValue_C)) ||
        (!(rtb_Min3 < MFSM_CosShortGndValue_C))) {
      /* Sum: '<S133>/Add' incorporates:
       *  Constant: '<S137>/Constant'
       *  UnitDelay: '<S141>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a -
        MFSM_DebounceDecrCosShortGnd_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a) {
        /* MinMax: '<S133>/Max' incorporates:
         *  Constant: '<S133>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S133>/Max' incorporates:
         *  UnitDelay: '<S141>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a;
      }

      /* Sum: '<S133>/Add1' incorporates:
       *  Constant: '<S136>/Constant'
       *  MinMax: '<S133>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrCosShortGnd_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S133>/Multiport Switch' */

    /* Switch: '<S141>/Enable' incorporates:
     *  Constant: '<S133>/Constant2'
     *  Logic: '<S141>/Logical Operator2'
     *  Switch: '<S141>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_g0 && true) {
      /* Switch: '<S139>/Switch2' incorporates:
       *  Constant: '<S133>/0 Constant1'
       *  RelationalOperator: '<S139>/LowerRelop1'
       *  RelationalOperator: '<S139>/UpperRelop'
       *  Sum: '<S133>/Add2'
       *  Switch: '<S139>/Switch'
       *  UnitDelay: '<S141>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S139>/Switch' incorporates:
         *  Constant: '<S133>/0 Constant1'
         *  UnitDelay: '<S141>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S139>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_h) {
      /* Switch: '<S141>/Reset' incorporates:
       *  Constant: '<S141>/iv'
       *  UnitDelay: '<S141>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a = ((uint8_T)0U);
    }

    /* End of Switch: '<S141>/Enable' */

    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S138>/Constant'
     *  RelationalOperator: '<S133>/Relational Operator'
     *  RelationalOperator: '<S133>/Relational Operator1'
     *  Sum: '<S133>/Add2'
     *  Switch: '<S140>/Switch1'
     *  UnitDelay: '<S141>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S140>/Switch' incorporates:
       *  Constant: '<S140>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_l = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_a <=
               MFSM_DebounceMinCosShortGnd_C) {
      /* Switch: '<S140>/Switch' incorporates:
       *  Constant: '<S140>/Constant4'
       *  Switch: '<S140>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_l = false;
    }

    /* End of Switch: '<S140>/Switch' */

    /* DataTypeConversion: '<S96>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S140>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_oi =
      McuFunSafeMonitor_DW.Memory_PreviousInput_l;

    /* Sum: '<S142>/Add2' incorporates:
     *  Constant: '<S142>/0 Constant4'
     *  Constant: '<S144>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxCosShortPwr_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S142>/Multiport Switch' incorporates:
     *  Constant: '<S142>/0 Constant'
     *  Constant: '<S143>/Constant'
     *  DataStoreWrite: '<S199>/Data Store Write'
     *  DataStoreWrite: '<S210>/Data Store Write'
     *  DataStoreWrite: '<S211>/Data Store Write'
     *  DataStoreWrite: '<S212>/Data Store Write'
     *  Logic: '<S97>/AND'
     *  MinMax: '<S142>/Max'
     *  RelationalOperator: '<S97>/Relational Operator2'
     *  Sum: '<S142>/Add'
     *  Sum: '<S142>/Add1'
     *  UnitDelay: '<S150>/Bare Unit Delay'
     */
    if ((!(rtb_Max2 > MFSM_CosShortPwrValue_C)) || (!(rtb_Max3 >
          MFSM_CosShortPwrValue_C)) || (!(rtb_Min2 > MFSM_CosShortPwrValue_C)) ||
        (!(rtb_Min3 > MFSM_CosShortPwrValue_C))) {
      /* Sum: '<S142>/Add' incorporates:
       *  Constant: '<S146>/Constant'
       *  UnitDelay: '<S150>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o -
        MFSM_DebounceDecrCosShortPwr_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o) {
        /* MinMax: '<S142>/Max' incorporates:
         *  Constant: '<S142>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S142>/Max' incorporates:
         *  UnitDelay: '<S150>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o;
      }

      /* Sum: '<S142>/Add1' incorporates:
       *  Constant: '<S145>/Constant'
       *  MinMax: '<S142>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrCosShortPwr_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S142>/Multiport Switch' */

    /* Switch: '<S150>/Enable' incorporates:
     *  Constant: '<S142>/Constant2'
     *  Logic: '<S150>/Logical Operator2'
     *  Switch: '<S150>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_k && true) {
      /* Switch: '<S148>/Switch2' incorporates:
       *  Constant: '<S142>/0 Constant1'
       *  RelationalOperator: '<S148>/LowerRelop1'
       *  RelationalOperator: '<S148>/UpperRelop'
       *  Sum: '<S142>/Add2'
       *  Switch: '<S148>/Switch'
       *  UnitDelay: '<S150>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S148>/Switch' incorporates:
         *  Constant: '<S142>/0 Constant1'
         *  UnitDelay: '<S150>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S148>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_o) {
      /* Switch: '<S150>/Reset' incorporates:
       *  Constant: '<S150>/iv'
       *  UnitDelay: '<S150>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o = ((uint8_T)0U);
    }

    /* End of Switch: '<S150>/Enable' */

    /* Switch: '<S149>/Switch' incorporates:
     *  Constant: '<S147>/Constant'
     *  RelationalOperator: '<S142>/Relational Operator'
     *  RelationalOperator: '<S142>/Relational Operator1'
     *  Sum: '<S142>/Add2'
     *  Switch: '<S149>/Switch1'
     *  UnitDelay: '<S150>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S149>/Switch' incorporates:
       *  Constant: '<S149>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_d = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_o <=
               MFSM_DebounceMinCosShortPwr_C) {
      /* Switch: '<S149>/Switch' incorporates:
       *  Constant: '<S149>/Constant4'
       *  Switch: '<S149>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_d = false;
    }

    /* End of Switch: '<S149>/Switch' */

    /* DataTypeConversion: '<S97>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S149>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_l =
      McuFunSafeMonitor_DW.Memory_PreviousInput_d;

    /* Sum: '<S238>/Add2' incorporates:
     *  Constant: '<S238>/0 Constant4'
     *  Constant: '<S239>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxPhaCurrOpen_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S238>/Multiport Switch' incorporates:
     *  Constant: '<S238>/0 Constant'
     *  Constant: '<S247>/Constant'
     *  Inport: '<Root>/SGSA_PhaseACurrentAD'
     *  Inport: '<Root>/SGSA_PhaseCCurrentAD'
     *  Logic: '<S243>/OR'
     *  MinMax: '<S238>/Max'
     *  RelationalOperator: '<S243>/Relational Operator4'
     *  Sum: '<S238>/Add'
     *  Sum: '<S238>/Add1'
     *  UnitDelay: '<S246>/Bare Unit Delay'
     */
    if ((!(SGSA_PhaseACurrentAD < MFSM_PhaCurrShortGndValue_C)) &&
        (!(SGSA_PhaseCCurrentAD < MFSM_PhaCurrShortGndValue_C))) {
      /* Sum: '<S238>/Add' incorporates:
       *  Constant: '<S241>/Constant'
       *  UnitDelay: '<S246>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb -
        MFSM_DebounceDecrPhaCurrOpen_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb) {
        /* MinMax: '<S238>/Max' incorporates:
         *  Constant: '<S238>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S238>/Max' incorporates:
         *  UnitDelay: '<S246>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb;
      }

      /* Sum: '<S238>/Add1' incorporates:
       *  Constant: '<S240>/Constant'
       *  MinMax: '<S238>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrPhaCurrOpen_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S238>/Multiport Switch' */

    /* Switch: '<S246>/Enable' incorporates:
     *  Constant: '<S238>/Constant2'
     *  Logic: '<S246>/Logical Operator2'
     *  Switch: '<S246>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_p && true) {
      /* Switch: '<S244>/Switch2' incorporates:
       *  Constant: '<S238>/0 Constant1'
       *  RelationalOperator: '<S244>/LowerRelop1'
       *  RelationalOperator: '<S244>/UpperRelop'
       *  Sum: '<S238>/Add2'
       *  Switch: '<S244>/Switch'
       *  UnitDelay: '<S246>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S244>/Switch' incorporates:
         *  Constant: '<S238>/0 Constant1'
         *  UnitDelay: '<S246>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S244>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_n) {
      /* Switch: '<S246>/Reset' incorporates:
       *  Constant: '<S246>/iv'
       *  UnitDelay: '<S246>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb = ((uint8_T)0U);
    }

    /* End of Switch: '<S246>/Enable' */

    /* Switch: '<S245>/Switch' incorporates:
     *  Constant: '<S242>/Constant'
     *  RelationalOperator: '<S238>/Relational Operator'
     *  RelationalOperator: '<S238>/Relational Operator1'
     *  Sum: '<S238>/Add2'
     *  Switch: '<S245>/Switch1'
     *  UnitDelay: '<S246>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S245>/Switch' incorporates:
       *  Constant: '<S245>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_o = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_kb <=
               MFSM_DebounceMinPhaCurrOpen_C) {
      /* Switch: '<S245>/Switch' incorporates:
       *  Constant: '<S245>/Constant4'
       *  Switch: '<S245>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_o = false;
    }

    /* End of Switch: '<S245>/Switch' */

    /* DataTypeConversion: '<S105>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S245>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_d =
      McuFunSafeMonitor_DW.Memory_PreviousInput_o;

    /* Sum: '<S248>/Add2' incorporates:
     *  Constant: '<S248>/0 Constant4'
     *  Constant: '<S249>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxPhaCurrShortPwr_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S248>/Multiport Switch' incorporates:
     *  Constant: '<S248>/0 Constant'
     *  Constant: '<S257>/Constant'
     *  Inport: '<Root>/SGSA_PhaseACurrentAD'
     *  Inport: '<Root>/SGSA_PhaseCCurrentAD'
     *  Logic: '<S253>/OR'
     *  MinMax: '<S248>/Max'
     *  RelationalOperator: '<S253>/Relational Operator4'
     *  Sum: '<S248>/Add'
     *  Sum: '<S248>/Add1'
     *  UnitDelay: '<S256>/Bare Unit Delay'
     */
    if ((!(SGSA_PhaseACurrentAD > MFSM_PhaCurrShortPwrValue_C)) &&
        (!(SGSA_PhaseCCurrentAD > MFSM_PhaCurrShortPwrValue_C))) {
      /* Sum: '<S248>/Add' incorporates:
       *  Constant: '<S251>/Constant'
       *  UnitDelay: '<S256>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e -
        MFSM_DebounceDecrPhaCurrShortPwr_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e) {
        /* MinMax: '<S248>/Max' incorporates:
         *  Constant: '<S248>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S248>/Max' incorporates:
         *  UnitDelay: '<S256>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e;
      }

      /* Sum: '<S248>/Add1' incorporates:
       *  Constant: '<S250>/Constant'
       *  MinMax: '<S248>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrPhaCurrShortPwr_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S248>/Multiport Switch' */

    /* Switch: '<S256>/Enable' incorporates:
     *  Constant: '<S248>/Constant2'
     *  Logic: '<S256>/Logical Operator2'
     *  Switch: '<S256>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_n && true) {
      /* Switch: '<S254>/Switch2' incorporates:
       *  Constant: '<S248>/0 Constant1'
       *  RelationalOperator: '<S254>/LowerRelop1'
       *  RelationalOperator: '<S254>/UpperRelop'
       *  Sum: '<S248>/Add2'
       *  Switch: '<S254>/Switch'
       *  UnitDelay: '<S256>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S254>/Switch' incorporates:
         *  Constant: '<S248>/0 Constant1'
         *  UnitDelay: '<S256>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S254>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_h5) {
      /* Switch: '<S256>/Reset' incorporates:
       *  Constant: '<S256>/iv'
       *  UnitDelay: '<S256>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e = ((uint8_T)0U);
    }

    /* End of Switch: '<S256>/Enable' */

    /* Switch: '<S255>/Switch' incorporates:
     *  Constant: '<S252>/Constant'
     *  RelationalOperator: '<S248>/Relational Operator'
     *  RelationalOperator: '<S248>/Relational Operator1'
     *  Sum: '<S248>/Add2'
     *  Switch: '<S255>/Switch1'
     *  UnitDelay: '<S256>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S255>/Switch' incorporates:
       *  Constant: '<S255>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_c = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_e <=
               MFSM_DebounceMinPhaCurrShortPwr_C) {
      /* Switch: '<S255>/Switch' incorporates:
       *  Constant: '<S255>/Constant4'
       *  Switch: '<S255>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_c = false;
    }

    /* End of Switch: '<S255>/Switch' */

    /* DataTypeConversion: '<S106>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S255>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_j =
      McuFunSafeMonitor_DW.Memory_PreviousInput_c;

    /* Sum: '<S282>/Add2' incorporates:
     *  Constant: '<S282>/0 Constant4'
     *  Constant: '<S284>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxSinShortGnd_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S282>/Multiport Switch' incorporates:
     *  Constant: '<S282>/0 Constant'
     *  Constant: '<S283>/Constant'
     *  DataStoreWrite: '<S206>/Data Store Write'
     *  Logic: '<S109>/AND'
     *  MinMax: '<S282>/Max'
     *  RelationalOperator: '<S109>/Relational Operator2'
     *  Sum: '<S282>/Add'
     *  Sum: '<S282>/Add1'
     *  UnitDelay: '<S290>/Bare Unit Delay'
     */
    if ((!(rtb_Max < MFSM_SinShortGndValue_C)) || (!(rtb_Saturation <
          MFSM_SinShortGndValue_C)) || (!(rtb_Min1_tmp_tmp <
          MFSM_SinShortGndValue_C)) || (!(rtb_Min1 < MFSM_SinShortGndValue_C)))
    {
      /* Sum: '<S282>/Add' incorporates:
       *  Constant: '<S286>/Constant'
       *  UnitDelay: '<S290>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu -
        MFSM_DebounceDecrSinShortGnd_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu) {
        /* MinMax: '<S282>/Max' incorporates:
         *  Constant: '<S282>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S282>/Max' incorporates:
         *  UnitDelay: '<S290>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu;
      }

      /* Sum: '<S282>/Add1' incorporates:
       *  Constant: '<S285>/Constant'
       *  MinMax: '<S282>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrSinShortGnd_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S282>/Multiport Switch' */

    /* Switch: '<S290>/Enable' incorporates:
     *  Constant: '<S282>/Constant2'
     *  Logic: '<S290>/Logical Operator2'
     *  Switch: '<S290>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_mx && true) {
      /* Switch: '<S288>/Switch2' incorporates:
       *  Constant: '<S282>/0 Constant1'
       *  RelationalOperator: '<S288>/LowerRelop1'
       *  RelationalOperator: '<S288>/UpperRelop'
       *  Sum: '<S282>/Add2'
       *  Switch: '<S288>/Switch'
       *  UnitDelay: '<S290>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S288>/Switch' incorporates:
         *  Constant: '<S282>/0 Constant1'
         *  UnitDelay: '<S290>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S288>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_l) {
      /* Switch: '<S290>/Reset' incorporates:
       *  Constant: '<S290>/iv'
       *  UnitDelay: '<S290>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu = ((uint8_T)0U);
    }

    /* End of Switch: '<S290>/Enable' */

    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S287>/Constant'
     *  RelationalOperator: '<S282>/Relational Operator'
     *  RelationalOperator: '<S282>/Relational Operator1'
     *  Sum: '<S282>/Add2'
     *  Switch: '<S289>/Switch1'
     *  UnitDelay: '<S290>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S289>/Switch' incorporates:
       *  Constant: '<S289>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_ig = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_hu <=
               MFSM_DebounceMinSinShortGnd_C) {
      /* Switch: '<S289>/Switch' incorporates:
       *  Constant: '<S289>/Constant4'
       *  Switch: '<S289>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_ig = false;
    }

    /* End of Switch: '<S289>/Switch' */

    /* DataTypeConversion: '<S109>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S289>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_dg =
      McuFunSafeMonitor_DW.Memory_PreviousInput_ig;

    /* Sum: '<S291>/Add2' incorporates:
     *  Constant: '<S291>/0 Constant4'
     *  Constant: '<S293>/Constant'
     */
    rtb_DataTypeConversion12_tmp = (int32_T)((uint32_T)
      MFSM_DebounceMaxSinShortPwr_C + ((uint8_T)1U));
    if ((uint32_T)rtb_DataTypeConversion12_tmp > 255U) {
      rtb_DataTypeConversion12_tmp = 255;
    }

    /* MultiPortSwitch: '<S291>/Multiport Switch' incorporates:
     *  Constant: '<S291>/0 Constant'
     *  Constant: '<S292>/Constant'
     *  DataStoreWrite: '<S206>/Data Store Write'
     *  Logic: '<S110>/AND'
     *  MinMax: '<S291>/Max'
     *  RelationalOperator: '<S110>/Relational Operator2'
     *  Sum: '<S291>/Add'
     *  Sum: '<S291>/Add1'
     *  UnitDelay: '<S299>/Bare Unit Delay'
     */
    if ((!(rtb_Max > MFSM_SinShortPwrValue_C)) || (!(rtb_Saturation >
          MFSM_SinShortPwrValue_C)) || (!(rtb_Min1_tmp_tmp >
          MFSM_SinShortPwrValue_C)) || (!(rtb_Min1 > MFSM_SinShortPwrValue_C)))
    {
      /* Sum: '<S291>/Add' incorporates:
       *  Constant: '<S295>/Constant'
       *  UnitDelay: '<S299>/Bare Unit Delay'
       */
      tmp = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa -
        MFSM_DebounceDecrSinShortPwr_C;
      if (tmp < 0) {
        tmp = 0;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    } else {
      if (((uint8_T)0U) >= McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa) {
        /* MinMax: '<S291>/Max' incorporates:
         *  Constant: '<S291>/0 Constant'
         */
        rtb_MultiportSwitch = ((uint8_T)0U);
      } else {
        /* MinMax: '<S291>/Max' incorporates:
         *  UnitDelay: '<S299>/Bare Unit Delay'
         */
        rtb_MultiportSwitch = McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa;
      }

      /* Sum: '<S291>/Add1' incorporates:
       *  Constant: '<S294>/Constant'
       *  MinMax: '<S291>/Max'
       */
      tmp = (int32_T)((uint32_T)rtb_MultiportSwitch +
                      MFSM_DebounceIncrSinShortPwr_C);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rtb_MultiportSwitch = (uint8_T)tmp;
    }

    /* End of MultiPortSwitch: '<S291>/Multiport Switch' */

    /* Switch: '<S299>/Enable' incorporates:
     *  Constant: '<S291>/Constant2'
     *  Logic: '<S299>/Logical Operator2'
     *  Switch: '<S299>/Reset'
     */
    if (McuFunSafeMonitor_ConstB.LogicalOperator1_ov && true) {
      /* Switch: '<S297>/Switch2' incorporates:
       *  Constant: '<S291>/0 Constant1'
       *  RelationalOperator: '<S297>/LowerRelop1'
       *  RelationalOperator: '<S297>/UpperRelop'
       *  Sum: '<S291>/Add2'
       *  Switch: '<S297>/Switch'
       *  UnitDelay: '<S299>/Bare Unit Delay'
       */
      if (rtb_MultiportSwitch > (uint8_T)rtb_DataTypeConversion12_tmp) {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa = (uint8_T)
          rtb_DataTypeConversion12_tmp;
      } else if (rtb_MultiportSwitch < ((uint8_T)0U)) {
        /* Switch: '<S297>/Switch' incorporates:
         *  Constant: '<S291>/0 Constant1'
         *  UnitDelay: '<S299>/Bare Unit Delay'
         */
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa = ((uint8_T)0U);
      } else {
        McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa = rtb_MultiportSwitch;
      }

      /* End of Switch: '<S297>/Switch2' */
    } else if (McuFunSafeMonitor_ConstB.DataTypeConversion1_b) {
      /* Switch: '<S299>/Reset' incorporates:
       *  Constant: '<S299>/iv'
       *  UnitDelay: '<S299>/Bare Unit Delay'
       */
      McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa = ((uint8_T)0U);
    }

    /* End of Switch: '<S299>/Enable' */

    /* DataTypeConversion: '<S291>/Data Type Conversion EveSt' incorporates:
     *  RelationalOperator: '<S291>/Relational Operator'
     *  Sum: '<S291>/Add2'
     *  UnitDelay: '<S299>/Bare Unit Delay'
     */
    rtb_Saturation = (real32_T)(McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa >=
      (uint8_T)rtb_DataTypeConversion12_tmp);

    /* Switch: '<S298>/Switch' incorporates:
     *  Constant: '<S296>/Constant'
     *  RelationalOperator: '<S291>/Relational Operator'
     *  RelationalOperator: '<S291>/Relational Operator1'
     *  Sum: '<S291>/Add2'
     *  Switch: '<S298>/Switch1'
     *  UnitDelay: '<S299>/Bare Unit Delay'
     */
    if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa >= (uint8_T)
        rtb_DataTypeConversion12_tmp) {
      /* Switch: '<S298>/Switch' incorporates:
       *  Constant: '<S298>/Constant1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_fa = true;
    } else if (McuFunSafeMonitor_DW.BareUnitDelay_DSTATE_pa <=
               MFSM_DebounceMinSinShortPwr_C) {
      /* Switch: '<S298>/Switch' incorporates:
       *  Constant: '<S298>/Constant4'
       *  Switch: '<S298>/Switch1'
       */
      McuFunSafeMonitor_DW.Memory_PreviousInput_fa = false;
    }

    /* End of Switch: '<S298>/Switch' */

    /* DataTypeConversion: '<S110>/Data Type Conversion' incorporates:
     *  DataTypeConversion: '<S298>/Data Type Conversion EveSt2'
     */
    McuFunSafeMonitor_B.DataTypeConversion_eb =
      McuFunSafeMonitor_DW.Memory_PreviousInput_fa;

    /* PreLookup: '<S111>/Prelookup' incorporates:
     *  Inport: '<Root>/SGPP_BSW_f32_nRotateSpd_rpm'
     */
    rtb_Prelookup_o1_k = plook_u32ff_binx(SGPP_BSW_f32_nRotateSpd_rpm, (real32_T
      *)&MFSM_ElecSpd_A[0], 2U, &rtb_Saturation);

    /* Product: '<S300>/Product' incorporates:
     *  Constant: '<S301>/Constant'
     *  Constant: '<S91>/Constant'
     */
    u0 = MFSM_TorqueFilterFreq_C * 9.6E-5F;

    /* Saturate: '<S300>/Saturation' */
    if (u0 > 1.0F) {
      u0 = 1.0F;
    } else if (u0 < 0.0F) {
      u0 = 0.0F;
    }

    /* Sum: '<S300>/Subtract1' incorporates:
     *  Delay: '<S300>/Delay'
     *  Gain: '<S111>/Gain'
     *  Gain: '<S111>/Gain1'
     *  Gain: '<S111>/Gain2'
     *  Gain: '<S111>/Gain3'
     *  Gain: '<S111>/Gain4'
     *  Gain: '<S111>/Gain5'
     *  Inport: '<Root>/SGPP_BSW_f32_iSmpPhaU_A'
     *  Inport: '<Root>/SGPP_BSW_f32_iSmpPhaW_A'
     *  Inport: '<Root>/SGPP_BSW_f32_nRotateSpd_rpm'
     *  Inport: '<Root>/SGPP_BSW_f32_uDcHV_V'
     *  Interpolation_n-D: '<S111>/Mtr Efficiency Lookup Table'
     *  Product: '<S111>/Divide'
     *  Product: '<S111>/Product1'
     *  Product: '<S111>/Product2'
     *  Product: '<S111>/Product3'
     *  Product: '<S111>/Product4'
     *  Product: '<S300>/Product1'
     *  Saturate: '<S300>/Saturation'
     *  Sum: '<S111>/Add1'
     *  Sum: '<S111>/Add2'
     *  Sum: '<S111>/Add3'
     *  Sum: '<S111>/Add5'
     *  Sum: '<S300>/Subtract'
     *  UnitDelay: '<S111>/Unit Delay'
     *  UnitDelay: '<S111>/Unit Delay1'
     *  UnitDelay: '<S111>/Unit Delay2'
     */
    McuFunSafeMonitor_DW.Delay_DSTATE_b += (((((2.0F *
      McuFunSafeMonitor_DW.UnitDelay_DSTATE -
      McuFunSafeMonitor_DW.UnitDelay2_DSTATE) -
      McuFunSafeMonitor_DW.UnitDelay1_DSTATE) * 0.003333F * SGPP_BSW_f32_uDcHV_V
      * SGPP_BSW_f32_iSmpPhaU_A + ((2.0F *
      McuFunSafeMonitor_DW.UnitDelay2_DSTATE -
      McuFunSafeMonitor_DW.UnitDelay_DSTATE) -
      McuFunSafeMonitor_DW.UnitDelay1_DSTATE) * 0.003333F * SGPP_BSW_f32_uDcHV_V
      * MFSM_PhaseBCurrent) + ((2.0F * McuFunSafeMonitor_DW.UnitDelay1_DSTATE -
      McuFunSafeMonitor_DW.UnitDelay_DSTATE) -
      McuFunSafeMonitor_DW.UnitDelay2_DSTATE) * 0.003333F * SGPP_BSW_f32_uDcHV_V
      * SGPP_BSW_f32_iSmpPhaW_A) / (intrp1d_fu32fl(rtb_Prelookup_o1_k,
      rtb_Saturation, (real32_T *)&MFSM_MtrEfficiency_M[0]) *
      SGPP_BSW_f32_nRotateSpd_rpm) - McuFunSafeMonitor_DW.Delay_DSTATE_b) * u0;

    /* Update for Memory: '<S268>/Memory' */
    McuFunSafeMonitor_DW.Memory_PreviousInput = rtb_Switch_ae;

    /* Update for Memory: '<S131>/Memory' */
    McuFunSafeMonitor_DW.Memory_PreviousInput_p = rtb_Switch_go;

    /* Update for Memory: '<S158>/Memory' */
    McuFunSafeMonitor_DW.Memory_PreviousInput_h = rtb_Switch_kl;

    /* Update for Memory: '<S174>/Memory' */
    McuFunSafeMonitor_DW.Memory_PreviousInput_i = rtb_Switch_a;

    /* Update for Memory: '<S184>/Memory' */
    McuFunSafeMonitor_DW.Memory_PreviousInput_m = rtb_Switch_cg;

    /* Update for Memory: '<S193>/Memory' */
    McuFunSafeMonitor_DW.Memory_PreviousInput_mz = rtb_Switch_os;

    /* Update for Delay: '<S114>/Delay' incorporates:
     *  Inport: '<Root>/SGPP_PhaseADuty'
     */
    McuFunSafeMonitor_DW.Delay_DSTATE = SGPP_PhaseADuty;

    /* Update for Delay: '<S114>/Delay1' incorporates:
     *  Inport: '<Root>/SGPP_PhaseBDuty'
     */
    McuFunSafeMonitor_DW.Delay1_DSTATE = SGPP_PhaseBDuty;

    /* Update for Delay: '<S114>/Delay2' incorporates:
     *  Inport: '<Root>/SGPP_PhaseCDuty'
     */
    McuFunSafeMonitor_DW.Delay2_DSTATE = SGPP_PhaseCDuty;

    /* Update for UnitDelay: '<S111>/Unit Delay' incorporates:
     *  Inport: '<Root>/SGPP_FOC_f32_Uduty_Null'
     */
    McuFunSafeMonitor_DW.UnitDelay_DSTATE = SGPP_FOC_f32_Uduty_Null;

    /* Update for UnitDelay: '<S111>/Unit Delay2' incorporates:
     *  Inport: '<Root>/SGPP_FOC_f32_Vduty_Null'
     */
    McuFunSafeMonitor_DW.UnitDelay2_DSTATE = SGPP_FOC_f32_Vduty_Null;

    /* Update for UnitDelay: '<S111>/Unit Delay1' incorporates:
     *  Inport: '<Root>/SGPP_FOC_f32_Wduty_Null'
     */
    McuFunSafeMonitor_DW.UnitDelay1_DSTATE = SGPP_FOC_f32_Wduty_Null;
  }

  /* End of RelationalOperator: '<S90>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S2>/Subsystem' */

  /* SignalConversion generated from: '<S2>/MFSM_BusCurrentLpfVal' */
  MFSM_BusCurrentLpfVal = McuFunSafeMonitor_B.Add1;

  /* SignalConversion generated from: '<S2>/MFSM_CosDiffFault' */
  MFSM_CosDiffFault = McuFunSafeMonitor_B.OutportBufferForMFSM_CosDiffFault;

  /* SignalConversion generated from: '<S2>/MFSM_CosOpenFault' */
  MFSM_CosOpenFault = McuFunSafeMonitor_B.DataTypeConversion_m;

  /* SignalConversion generated from: '<S2>/MFSM_CosShortGndFault' */
  MFSM_CosShortGndFault = McuFunSafeMonitor_B.DataTypeConversion_oi;

  /* SignalConversion generated from: '<S2>/MFSM_CosShortPwrFault' */
  MFSM_CosShortPwrFault = McuFunSafeMonitor_B.DataTypeConversion_l;

  /* SignalConversion generated from: '<S2>/MFSM_ExcAmpFault' */
  MFSM_ExcAmpFault = McuFunSafeMonitor_B.DataTypeConversion_n;

  /* SignalConversion generated from: '<S2>/MFSM_ExcOpenFault' */
  MFSM_ExcOpenFault = McuFunSafeMonitor_B.DataTypeConversion_p;

  /* SignalConversion generated from: '<S2>/MFSM_ExcShortGndFault' */
  MFSM_ExcShortGndFault = McuFunSafeMonitor_B.DataTypeConversion_f;

  /* SignalConversion generated from: '<S2>/MFSM_ExcShortPwrFault' */
  MFSM_ExcShortPwrFault = McuFunSafeMonitor_B.DataTypeConversion_o;

  /* SignalConversion generated from: '<S2>/MFSM_FunSafetyTorque' incorporates:
   *  Delay: '<S300>/Delay'
   */
  MFSM_FunSafetyTorque = McuFunSafeMonitor_DW.Delay_DSTATE_b;

  /* SignalConversion generated from: '<S2>/MFSM_PhaCurrDiffFault' */
  MFSM_PhaCurrDiffFault = McuFunSafeMonitor_B.DataTypeConversion_fo;

  /* SignalConversion generated from: '<S2>/MFSM_PhaCurrOpenFault' */
  MFSM_PhaCurrOpenFault = McuFunSafeMonitor_B.DataTypeConversion_e;

  /* SignalConversion generated from: '<S2>/MFSM_PhaCurrShortGndFault' */
  MFSM_PhaCurrShortGndFault = McuFunSafeMonitor_B.DataTypeConversion_d;

  /* SignalConversion generated from: '<S2>/MFSM_PhaCurrShortPwr_Fault' */
  MFSM_PhaCurrShortPwrFault = McuFunSafeMonitor_B.DataTypeConversion_j;

  /* SignalConversion generated from: '<S2>/MFSM_RslvrAmpFault' */
  MFSM_RslvrAmpFault = McuFunSafeMonitor_B.DataTypeConversion;

  /* SignalConversion generated from: '<S2>/MFSM_SinOpenFault' */
  MFSM_SinOpenFault = McuFunSafeMonitor_B.DataTypeConversion_ee;

  /* SignalConversion generated from: '<S2>/MFSM_SinShortGndFault' */
  MFSM_SinShortGndFault = McuFunSafeMonitor_B.DataTypeConversion_dg;

  /* SignalConversion generated from: '<S2>/MFSM_SinShortPwrFault' */
  MFSM_SinShortPwrFault = McuFunSafeMonitor_B.DataTypeConversion_eb;

  /* SignalConversion generated from: '<S2>/MFSM_SineDiffFault' */
  MFSM_SineDiffFault = McuFunSafeMonitor_B.OutportBufferForMFSM_SineDiffFault;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/MFSM_FuncSafetyRedundancy_96us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void McuFunSafeMonitor_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void McuFunSafeMonitor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
