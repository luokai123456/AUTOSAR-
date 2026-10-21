/*
 * File: PMS_RollingCounter.c
 *
 * Code generated for Simulink model 'PMS_RollingCounter'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Aug 12 17:16:19 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMS_RollingCounter.h"
#include "PMS_RollingCounter_private.h"

/* Block states (default storage) */
DW_PMS_RollingCounter_T PMS_RollingCounter_DW;

/* Model step function for TID1 */
void PMS_RollingCounter_Runnable(void)
                                /* Explicit Task: PMS_RollingCounter_Runnable */
{
  boolean rtb_Compare_dg;

  /* RootInportFunctionCallGenerator generated from: '<Root>/PMS_RollingCounter_Runnable' incorporates:
   *  SubSystem: '<Root>/PMS_RollingCounter_Runnable_sys'
   */
  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant8'
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   *  Sum: '<S2>/Add1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  if (PMS_RollingCounter_DW.UnitDelay_DSTATE == 101) {
    PMS_RollingCounter_DW.UnitDelay_DSTATE = 1U;
  }

  PMS_RollingCounter_DW.UnitDelay_DSTATE++;

  /* End of Switch: '<S2>/Switch' */

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Math: '<S2>/Mod4'
   *  RelationalOperator: '<S4>/Compare'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  if ((uint8)(PMS_RollingCounter_DW.UnitDelay_DSTATE % 4) == 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S21>/Constant3'
     *  Sum: '<S21>/Add2'
     *  UnitDelay: '<S21>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE + 1);
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S42>/Constant'
   *  RelationalOperator: '<S42>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE = 0U;
  } else {
    /* Switch: '<S21>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Math: '<S2>/Mod1'
   *  RelationalOperator: '<S5>/Compare'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Compare_dg = ((uint8)(PMS_RollingCounter_DW.UnitDelay_DSTATE % 10) == 0);

  /* Switch: '<S8>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S8>/Constant3'
     *  Sum: '<S8>/Add2'
     *  UnitDelay: '<S8>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_i + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S8>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_f;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S29>/Constant'
   *  RelationalOperator: '<S29>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S8>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_i = 0U;
  } else {
    /* Switch: '<S8>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_i =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Switch: '<S19>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S19>/Constant3'
     *  Sum: '<S19>/Add2'
     *  UnitDelay: '<S19>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_o + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_b;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Switch: '<S19>/Switch2' incorporates:
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S40>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S19>/Switch2' incorporates:
     *  Constant: '<S19>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_o = 0U;
  } else {
    /* Switch: '<S19>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_o =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S19>/Switch2' */

  /* Switch: '<S23>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S23>/Constant3'
     *  Sum: '<S23>/Add2'
     *  UnitDelay: '<S23>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_a + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S23>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_b0;
  }

  /* End of Switch: '<S23>/Switch1' */

  /* Switch: '<S23>/Switch2' incorporates:
   *  Constant: '<S44>/Constant'
   *  RelationalOperator: '<S44>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S23>/Switch2' incorporates:
     *  Constant: '<S23>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_a = 0U;
  } else {
    /* Switch: '<S23>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_a =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S23>/Switch2' */

  /* Switch: '<S24>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S24>/Constant3'
     *  Sum: '<S24>/Add2'
     *  UnitDelay: '<S24>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_j + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S24>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_n;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* Switch: '<S24>/Switch2' incorporates:
   *  Constant: '<S45>/Constant'
   *  RelationalOperator: '<S45>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S24>/Switch2' incorporates:
     *  Constant: '<S24>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_j = 0U;
  } else {
    /* Switch: '<S24>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_j =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S24>/Switch2' */

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   *  Math: '<S2>/Mod2'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  rtb_Compare_dg = ((uint8)(PMS_RollingCounter_DW.UnitDelay_DSTATE % 2) == 0);

  /* Switch: '<S11>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S11>/Constant3'
     *  Sum: '<S11>/Add2'
     *  UnitDelay: '<S11>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_c + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S11>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Switch: '<S11>/Switch2' incorporates:
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S32>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S11>/Switch2' incorporates:
     *  Constant: '<S11>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_c = 0U;
  } else {
    /* Switch: '<S11>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_c =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Switch: '<S13>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S13>/Constant3'
     *  Sum: '<S13>/Add2'
     *  UnitDelay: '<S13>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_h + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Switch: '<S13>/Switch2' incorporates:
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S34>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S13>/Switch2' incorporates:
     *  Constant: '<S13>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_h = 0U;
  } else {
    /* Switch: '<S13>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_h =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Switch: '<S14>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S14>/Constant3'
     *  Sum: '<S14>/Add2'
     *  UnitDelay: '<S14>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_n + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S14>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_o;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S35>/Constant'
   *  RelationalOperator: '<S35>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S14>/Switch2' incorporates:
     *  Constant: '<S14>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_n = 0U;
  } else {
    /* Switch: '<S14>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_n =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Switch: '<S15>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S15>/Constant3'
     *  Sum: '<S15>/Add2'
     *  UnitDelay: '<S15>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_f + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S15>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_j;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Switch: '<S15>/Switch2' incorporates:
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S36>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S15>/Switch2' incorporates:
     *  Constant: '<S15>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_f = 0U;
  } else {
    /* Switch: '<S15>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_f =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S15>/Switch2' */

  /* Switch: '<S20>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S20>/Constant3'
     *  Sum: '<S20>/Add2'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_k + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_k;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S41>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S20>/Switch2' incorporates:
     *  Constant: '<S20>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_k = 0U;
  } else {
    /* Switch: '<S20>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_k =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S20>/Switch2' */

  /* Switch: '<S28>/Switch1' */
  if (rtb_Compare_dg) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S28>/Constant3'
     *  Sum: '<S28>/Add2'
     *  UnitDelay: '<S28>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_c2 + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S28>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_i;
  }

  /* End of Switch: '<S28>/Switch1' */

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S49>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S28>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_c2 = 0U;
  } else {
    /* Switch: '<S28>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_c2 =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* Switch: '<S17>/Switch1' incorporates:
   *  Constant: '<S7>/Constant'
   *  Math: '<S2>/Mod3'
   *  RelationalOperator: '<S7>/Compare'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  if ((uint8)(PMS_RollingCounter_DW.UnitDelay_DSTATE % 5) == 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S17>/Constant3'
     *  Sum: '<S17>/Add2'
     *  UnitDelay: '<S17>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_fw + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S17>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_b1;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* Switch: '<S17>/Switch2' incorporates:
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S38>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S17>/Switch2' incorporates:
     *  Constant: '<S17>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_fw = 0U;
  } else {
    /* Switch: '<S17>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_fw =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S17>/Switch2' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S9>/Constant3'
     *  Sum: '<S9>/Add2'
     *  UnitDelay: '<S9>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_nm + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S9>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_ou;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S30>/Constant'
   *  RelationalOperator: '<S30>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S9>/Switch2' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_nm = 0U;
  } else {
    /* Switch: '<S9>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_nm =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S10>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S10>/Constant3'
     *  Sum: '<S10>/Add2'
     *  UnitDelay: '<S10>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_ht + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S10>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_ji;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* Switch: '<S10>/Switch2' incorporates:
   *  Constant: '<S31>/Constant'
   *  RelationalOperator: '<S31>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ht = 0U;
  } else {
    /* Switch: '<S10>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ht =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Switch: '<S12>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S12>/Constant3'
     *  Sum: '<S12>/Add2'
     *  UnitDelay: '<S12>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_hl + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_c;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Switch: '<S12>/Switch2' incorporates:
   *  Constant: '<S33>/Constant'
   *  RelationalOperator: '<S33>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S12>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_hl = 0U;
  } else {
    /* Switch: '<S12>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_hl =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S12>/Switch2' */

  /* Switch: '<S16>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S16>/Constant3'
     *  Sum: '<S16>/Add2'
     *  UnitDelay: '<S16>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_ix + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S16>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_l;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S37>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S16>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ix = 0U;
  } else {
    /* Switch: '<S16>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ix =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Switch: '<S18>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S18>/Constant3'
     *  Sum: '<S18>/Add2'
     *  UnitDelay: '<S18>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_ho + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S18>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_g;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* Switch: '<S18>/Switch2' incorporates:
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S39>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ho = 0U;
  } else {
    /* Switch: '<S18>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ho =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S18>/Switch2' */

  /* Switch: '<S22>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S22>/Constant3'
     *  Sum: '<S22>/Add2'
     *  UnitDelay: '<S22>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_m + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S22>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_gp;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* Switch: '<S22>/Switch2' incorporates:
   *  Constant: '<S43>/Constant'
   *  RelationalOperator: '<S43>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_m = 0U;
  } else {
    /* Switch: '<S22>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_m =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S22>/Switch2' */

  /* Switch: '<S25>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S25>/Constant3'
     *  Sum: '<S25>/Add2'
     *  UnitDelay: '<S25>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_o3 + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S25>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_py;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S46>/Constant'
   *  RelationalOperator: '<S46>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S25>/Switch2' incorporates:
     *  Constant: '<S25>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_o3 = 0U;
  } else {
    /* Switch: '<S25>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_o3 =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S25>/Switch2' */

  /* Switch: '<S26>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S26>/Constant3'
     *  Sum: '<S26>/Add2'
     *  UnitDelay: '<S26>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_l + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S26>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_kf;
  }

  /* End of Switch: '<S26>/Switch1' */

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S47>/Constant'
   *  RelationalOperator: '<S47>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S26>/Switch2' incorporates:
     *  Constant: '<S26>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_l = 0U;
  } else {
    /* Switch: '<S26>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_l =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S26>/Switch2' */

  /* Switch: '<S27>/Switch1' incorporates:
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE_a != 0) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/Constant3'
     *  Sum: '<S27>/Add2'
     *  UnitDelay: '<S27>/Unit Delay2'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE = (uint8)
      (PMS_RollingCounter_DW.UnitDelay2_DSTATE_e + 1);
  } else {
    /* Switch: '<S27>/Switch1' incorporates:
     *  UnitDelay: '<S27>/Unit Delay1'
     */
    PMS_RollingCounter_DW.UnitDelay1_DSTATE =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE_e2;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Switch: '<S27>/Switch2' incorporates:
   *  Constant: '<S48>/Constant'
   *  RelationalOperator: '<S48>/Compare'
   */
  if (PMS_RollingCounter_DW.UnitDelay1_DSTATE == 16) {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/Constant4'
     */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_e = 0U;
  } else {
    /* Switch: '<S27>/Switch2' */
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_e =
      PMS_RollingCounter_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S27>/Switch2' */

  /* Update for UnitDelay: '<S21>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_f =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_i;

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_b =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_o;

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_b0 =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_a;

  /* Update for UnitDelay: '<S24>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_n =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_j;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_e =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_c;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_p =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_h;

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_o =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_n;

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_j =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_f;

  /* Update for UnitDelay: '<S20>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_k =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_k;

  /* Update for UnitDelay: '<S28>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_i =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_c2;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_b1 =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_fw;

  /* Update for UnitDelay: '<S2>/Unit Delay1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_a = 1U;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_ou =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_nm;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_ji =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ht;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_c =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_hl;

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_l =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ix;

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_g =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_ho;

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_gp =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_m;

  /* Update for UnitDelay: '<S25>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_py =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_o3;

  /* Update for UnitDelay: '<S26>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_kf =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_l;

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  PMS_RollingCounter_DW.UnitDelay1_DSTATE_e2 =
    PMS_RollingCounter_DW.UnitDelay2_DSTATE_e;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/PMS_RollingCounter_Runnable' */

  /* Outport: '<Root>/BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter' */
  (void)Rte_Write_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_i);

  /* Outport: '<Root>/BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter' */
  (void)
    Rte_Write_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_m);

  /* Outport: '<Root>/BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter' */
  (void)
    Rte_Write_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_o);

  /* Outport: '<Root>/BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter' */
  (void)Rte_Write_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_a);

  /* Outport: '<Root>/BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter' */
  (void)Rte_Write_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_j);

  /* Outport: '<Root>/BMSH_Status_AliveCounter_BMSH_Status_AliveCounter' */
  (void)Rte_Write_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_o3);

  /* Outport: '<Root>/BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter' */
  (void)Rte_Write_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_l);

  /* Outport: '<Root>/BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter' */
  (void)Rte_Write_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_e);

  /* Outport: '<Root>/IPU_Sts_AliveCounter_IPU_Sts_AliveCounter' */
  (void)Rte_Write_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_c2);

  /* Outport: '<Root>/IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter' */
  (void)Rte_Write_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_nm);

  /* Outport: '<Root>/PMS_Command_AliveCounter_PMS_Command_AliveCounter' */
  (void)Rte_Write_PMS_Command_AliveCounter_PMS_Command_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_ht);

  /* Outport: '<Root>/PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter' */
  (void)Rte_Write_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_c);

  /* Outport: '<Root>/PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter' */
  (void)Rte_Write_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_hl);

  /* Outport: '<Root>/PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter' */
  (void)Rte_Write_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_h);

  /* Outport: '<Root>/PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter' */
  (void)Rte_Write_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_n);

  /* Outport: '<Root>/PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter' */
  (void)Rte_Write_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE);

  /* Outport: '<Root>/PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter' */
  (void)Rte_Write_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_f);

  /* Outport: '<Root>/PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter' */
  (void)
    Rte_Write_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_ix);

  /* Outport: '<Root>/PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter' */
  (void)Rte_Write_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_fw);

  /* Outport: '<Root>/VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter' */
  (void)Rte_Write_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_ho);

  /* Outport: '<Root>/VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter' */
  (void)Rte_Write_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter
    (PMS_RollingCounter_DW.UnitDelay2_DSTATE_k);
}

/* Model initialize function */
void PMS_RollingCounter_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
