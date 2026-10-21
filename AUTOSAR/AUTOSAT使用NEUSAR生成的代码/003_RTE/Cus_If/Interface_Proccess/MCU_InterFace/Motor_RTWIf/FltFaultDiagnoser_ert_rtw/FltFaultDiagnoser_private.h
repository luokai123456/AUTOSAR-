/*
 * File: FltFaultDiagnoser_private.h
 *
 * Code generated for Simulink model 'FltFaultDiagnoser'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:38:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FltFaultDiagnoser_private_h_
#define RTW_HEADER_FltFaultDiagnoser_private_h_
#include "rtwtypes.h"
#include "FltFaultDiagnoser_types.h"

/* Exported data declaration */

/* Data with Imported storage */
extern uint8_T CTSO_DischargeFaultFlag;/* '<Root>/CTSO_DischargeFaultFlag' */
extern real32_T SGPP_DcLinkVoltMeas;   /* '<Root>/SGPP_DcLinkVoltMeas' */
extern real32_T SGPP_MechSpeedAbsolute;/* '<Root>/SGPP_MechSpeedAbsolute' */
extern real32_T SGPP_MotorTemp1;       /* '<Root>/SGPP_MotorTemp1' */
extern real32_T SGPP_PhaseACurrent;    /* '<Root>/SGPP_PhaseACurrent' */
extern real32_T SGPP_PhaseBCurrent;    /* '<Root>/SGPP_PhaseBCurrent' */
extern real32_T SGPP_PhaseCCurrent;    /* '<Root>/SGPP_PhaseCCurrent' */
extern real32_T SGSA_BatteryVolt;      /* '<Root>/SGSA_BatteryVolt' */
extern uint8_T SGSA_HwHsIntBSt;        /* '<Root>/SGSA_HwHsIntBSt' */
extern uint8_T SGSA_HwLsIntBSt;        /* '<Root>/SGSA_HwLsIntBSt' */
extern uint8_T SGSA_HwOvercurSt;       /* '<Root>/SGSA_HwOvercurSt' */
extern uint8_T SGSA_HwOvervoltSt;      /* '<Root>/SGSA_HwOvervoltSt' */
extern real32_T SGSA_PhaseASwitchTemp; /* '<Root>/SGSA_PhaseASwitchTemp' */
extern real32_T SGSA_PhaseBSwitchTemp; /* '<Root>/SGSA_PhaseBSwitchTemp' */
extern real32_T SGSA_PhaseCSwitchTemp; /* '<Root>/SGSA_PhaseCSwitchTemp' */
extern uint8_T SGSA_ResolverError;     /* '<Root>/SGSA_ResolverError' */

#endif                             /* RTW_HEADER_FltFaultDiagnoser_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
