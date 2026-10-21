/*
 * File: swc_MEST.c
 *
 * Code generated for Simulink model 'swc_MEST'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Mar 11 14:07:43 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_MEST.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<S4>/VhlMassEst' */
#define swc_MEST_IN_Active             ((uint8)1U)
#define swc_MEST_IN_Init               ((uint8)2U)
#define swc_MEST_IN_ReInit             ((uint8)3U)

/* Named constants for Chart: '<S12>/timed_debounce' */
#define swc_MEST_IN_OFF                ((uint8)1U)
#define swc_MEST_IN_OFF_WAIT           ((uint8)2U)
#define swc_MEST_IN_ON                 ((uint8)3U)
#define swc_MEST_IN_ON_WAIT            ((uint8)4U)

/* Exported data definition */
#define swc_MEST_START_SEC_CONST_VOLATILE
#include "swc_MEST_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile sint16 C_IFC_MCA_Crt_Max = 500;/* Referenced by: '<S8>/Constant32' */
const volatile sint16 C_IFC_MCA_Crt_Min = 0;/* Referenced by: '<S8>/Constant33' */
const volatile sint16 C_IFC_MCA_Rot_Max = 7000;/* Referenced by: '<S8>/Constant24' */
const volatile sint16 C_IFC_MCA_Rot_Min = 0;/* Referenced by: '<S8>/Constant25' */
const volatile sint16 C_IFC_MCA_Torq_Max = 1000;/* Referenced by: '<S8>/Constant28' */
const volatile sint16 C_IFC_MCA_Torq_Min = 0;/* Referenced by: '<S8>/Constant29' */
const volatile uint16 C_IFC_MCA_Vlt_Max = 1000U;/* Referenced by: '<S8>/Constant30' */
const volatile uint16 C_IFC_MCA_Vlt_Min = 0U;/* Referenced by: '<S8>/Constant31' */
const volatile uint8 C_MCA_CdA = 10U;  /* Referenced by: '<S8>/Constant' */
const volatile uint16 C_MCA_Cls_Num = 6000U;/* Referenced by: '<S8>/Constant26' */
const volatile uint16 C_MCA_MassOverload1 = 3900U;/* Referenced by: '<S8>/Constant6' */
const volatile uint16 C_MCA_MassOverload2 = 4400U;/* Referenced by: '<S8>/Constant7' */
const volatile uint16 C_MCA_Mmax = 6000U;/* Referenced by: '<S8>/Constant5' */
const volatile uint16 C_MCA_Mmin = 1650U;/* Referenced by: '<S8>/Constant4' */
const volatile uint16 C_MCA_RLS_Acc_Lot = 80U;/* Referenced by: '<S8>/Constant20' */
const volatile uint8 C_MCA_RLS_Alpha = 10U;/* Referenced by: '<S8>/Constant23' */
const volatile uint8 C_MCA_RLS_Dt = 10U;/* Referenced by: '<S8>/Constant14' */
const volatile uint16 C_MCA_RLS_EfMk = 100U;/* Referenced by: '<S8>/Constant18' */
const volatile uint16 C_MCA_RLS_EfTm = 2000U;/* Referenced by: '<S8>/Constant19' */
const volatile uint8 C_MCA_RLS_Eta = 93U;/* Referenced by: '<S8>/Constant22' */
const volatile uint16 C_MCA_RLS_Mass_ST = 3200U;/* Referenced by: '<S8>/Constant34' */
const volatile uint16 C_MCA_RLS_Mr = 61U;/* Referenced by: '<S8>/Constant21' */
const volatile uint16 C_MCA_RLS_P0 = 1U;/* Referenced by: '<S8>/Constant17' */
const volatile uint8 C_MCA_RSL_MassScale_Factor = 110U;/* Referenced by: '<S8>/Constant15' */
const volatile uint16 C_MCA_ResutlCom_Num = 1500U;/* Referenced by: '<S8>/Constant27' */
const volatile uint16 C_MCA_Sta_Acc_Lot = 80U;/* Referenced by: '<S8>/Constant11' */
const volatile uint16 C_MCA_Sta_Acc_Upt = 600U;/* Referenced by: '<S8>/Constant12' */
const volatile uint8 C_MCA_Sta_Dt = 250U;/* Referenced by: '<S8>/Constant37' */
const volatile uint16 C_MCA_Sta_K_Ratio = 15U;/* Referenced by: '<S8>/Constant9' */
const volatile uint8 C_MCA_Sta_MassScale_Factor = 110U;/* Referenced by: '<S8>/Constant16' */
const volatile uint16 C_MCA_Sta_Mass_Factor = 1000U;/* Referenced by: '<S8>/Constant8' */
const volatile uint16 C_MCA_Sta_Mass_ST = 2600U;/* Referenced by: '<S8>/Constant35' */
const volatile uint16 C_MCA_Sta_Power_Lot = 5000U;/* Referenced by: '<S8>/Constant10' */
const volatile uint16 C_MCA_Sta_Vel_Lot = 60U;/* Referenced by: '<S8>/Constant13' */
const volatile uint8 C_MCA_Total_Factor = 10U;/* Referenced by: '<S8>/Constant36' */
const volatile uint16 C_MCA_g = 985U;  /* Referenced by: '<S8>/Constant3' */
const volatile uint16 C_MCA_ig = 12100U;/* Referenced by: '<S8>/Constant1' */
const volatile uint16 C_MCA_r = 316U;  /* Referenced by:
                                        * '<S8>/Constant2'
                                        * '<S10>/Constant1'
                                        */
const volatile uint16 masc_m_vehWeightBase_kg = 1800U;/* Referenced by: '<S10>/Constant' */
const volatile uint16 masc_m_vehWeightMax_kg = 6000U;/* Referenced by: '<S10>/Constant4' */
const volatile uint16 masc_m_vehWeightMin_kg = 1650U;/* Referenced by: '<S10>/Constant2' */
const volatile uint16 masc_m_vehWeightOvrLd1_kg = 3900U;/* Referenced by: '<S10>/Constant6' */
const volatile uint16 masc_m_vehWeightOvrLd2_kg = 4400U;/* Referenced by: '<S10>/Constant8' */
const volatile uint16 masc_t_MassCallTime = 50U;/* Referenced by:
                                                 * '<S5>/Constant'
                                                 * '<S6>/Constant'
                                                 */
const volatile float32 masc_t_vehSpdEstVhlMasOffDeb_s = 300.0F;/* Referenced by: '<S4>/Constant2' */
const volatile float32 masc_t_vehSpdEstVhlMasOnDeb_s = 0.01F;/* Referenced by: '<S4>/Constant1' */
const volatile float32 masc_v_vehSpdEstVhlMasThr_kph = 2.0F;/* Referenced by: '<S4>/Constant' */

#define swc_MEST_STOP_SEC_CONST_VOLATILE
#include "swc_MEST_MemMap.h"
#define swc_MEST_START_SEC_VAR
#include "swc_MEST_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
uint16 masc_m_vehWeightRaw_kg;         /* '<S4>/Data Type Conversion4' */

/* Vehicle weight */
sint16 masd_IFC_MCA_Crt_Max;           /* '<S8>/Constant32' */
sint16 masd_IFC_MCA_Crt_Min;           /* '<S8>/Constant33' */
sint16 masd_IFC_MCA_Rot_Max;           /* '<S8>/Constant24' */
sint16 masd_IFC_MCA_Rot_Min;           /* '<S8>/Constant25' */
sint16 masd_IFC_MCA_Torq_Max;          /* '<S8>/Constant28' */
sint16 masd_IFC_MCA_Torq_Min;          /* '<S8>/Constant29' */
uint16 masd_IFC_MCA_Vlt_Max;           /* '<S8>/Constant30' */
uint16 masd_IFC_MCA_Vlt_Min;           /* '<S8>/Constant31' */
uint8 masd_MCA_CdA;                    /* '<S8>/Constant' */

/* MCA_CdA */
uint16 masd_MCA_Cls_Num;               /* '<S8>/Constant26' */
uint16 masd_MCA_MassOverload1;         /* '<S8>/Constant6' */
uint16 masd_MCA_MassOverload2;         /* '<S8>/Constant7' */
uint16 masd_MCA_Mmax;                  /* '<S8>/Constant5' */
uint16 masd_MCA_Mmin;                  /* '<S8>/Constant4' */
uint16 masd_MCA_RLS_Acc_Lot;           /* '<S8>/Constant20' */
uint8 masd_MCA_RLS_Alpha;              /* '<S8>/Constant23' */
uint8 masd_MCA_RLS_Dt;                 /* '<S8>/Constant14' */
uint16 masd_MCA_RLS_EfMk;              /* '<S8>/Constant18' */
uint16 masd_MCA_RLS_EfTm;              /* '<S8>/Constant19' */
uint8 masd_MCA_RLS_Eta;                /* '<S8>/Constant22' */
uint16 masd_MCA_RLS_Mass_ST;           /* '<S8>/Constant34' */
uint16 masd_MCA_RLS_Mr;                /* '<S8>/Constant21' */
uint16 masd_MCA_RLS_P0;                /* '<S8>/Constant17' */
uint8 masd_MCA_RSL_MassScale_Factor;   /* '<S8>/Constant15' */
uint16 masd_MCA_ResutlCom_Num;         /* '<S8>/Constant27' */
uint16 masd_MCA_Sta_Acc_Lot;           /* '<S8>/Constant11' */
uint16 masd_MCA_Sta_Acc_Upt;           /* '<S8>/Constant12' */
uint8 masd_MCA_Sta_Dt;                 /* '<S8>/Constant37' */
uint16 masd_MCA_Sta_K_Ratio;           /* '<S8>/Constant9' */
uint8 masd_MCA_Sta_MassScale_Factor;   /* '<S8>/Constant16' */
uint16 masd_MCA_Sta_Mass_Factor;       /* '<S8>/Constant8' */
uint16 masd_MCA_Sta_Mass_ST;           /* '<S8>/Constant35' */
uint16 masd_MCA_Sta_Power_Lot;         /* '<S8>/Constant10' */
uint16 masd_MCA_Sta_Vel_Lot;           /* '<S8>/Constant13' */
uint8 masd_MCA_Total_Factor;           /* '<S8>/Constant36' */
uint16 masd_MCA_g;                     /* '<S8>/Constant3' */
uint16 masd_MCA_ig;                    /* '<S8>/Constant1' */

/* MCA_ig */
uint16 masd_MCA_r;                     /* '<S8>/Constant2' */
boolean masd_b_vehOvrLoadEnbl;         /* '<S3>/Compare' */

/* Vehicle overload very high flag */
float32 masd_m_vehWeight_kg;           /* '<S2>/Data Type Conversion' */

/* Vehicle weight */
uint16 masd_st_vehCalNum;              /* '<S2>/Data Type Conversion8' */

/* Vehicle Cal number */
uint8 masd_st_vehOverLoadSts;          /* '<S2>/Data Type Conversion7' */

/* Vehicle overload state */
#define swc_MEST_STOP_SEC_VAR
#include "swc_MEST_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_MEST_T swc_MEST_ConstB = {
  0.0,                                 /* '<S2>/Data Type Conversion6' */
  0.0,                                 /* '<S10>/Data Type Conversion' */
  316U,                                /* '<S10>/Switch' */
  0                                    /* '<S13>/Compare' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_MEST_T swc_MEST_ARID_DEF;
static void swc_MEST_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_MEST_T *swc_MEST__ARID_DEF_arg);

/* Output and update for atomic system: '<S4>/SR_latch' */
static void swc_MEST_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_MEST_T *swc_MEST__ARID_DEF_arg)
{
  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Logic: '<S9>/Logical Operator'
   *  Logic: '<S9>/Logical Operator1'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  *rty_flg_out = ((swc_MEST__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  swc_MEST__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* Model step function */
void swc_MEST_Step(void)
{
  /* local block i/o variables */
  uint8 rtb_DataTypeConversion7;
  boolean rtb_Compare;
  boolean rtb_LogicalOperator3;
  boolean rtb_DataTypeConversion1_f;
  boolean rtb_LogicalOperator3_e;
  sint32 rtb_DataTypeConversion11;
  float32 rtb_t_delay_off;
  float32 rtb_t_delay_on;
  uint16 rtb_DataTypeConversion6;
  uint16 rtb_Switch;
  uint16 rtb_Switch3;
  uint8 rtb_DataTypeConversion5_m;
  boolean rtb_RelationalOperator;

  /* S-Function (fcgen): '<S1>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/MASE_Mass_Estimation'
   */
  /* DataTypeConversion: '<S2>/Data Type Conversion11' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   */
  rtb_DataTypeConversion11 =
    Rte_IRead_swc_MEST_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp();

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<S4>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion9'
   *  Inport generated from: '<Root>/BusElementIn'
   */
  rtb_RelationalOperator = (Rte_IRead_swc_MEST_Step_vcib_VCIP_vscd_v_vehSpd_kph()
    >= masc_v_vehSpdEstVhlMasThr_kph);

  /* Outputs for Atomic SubSystem: '<S4>/debounce' */
  /* Saturate: '<S12>/Saturation' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  if (masc_t_vehSpdEstVhlMasOnDeb_s > 1.6777216E+7F) {
    /* Saturate: '<S12>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (masc_t_vehSpdEstVhlMasOnDeb_s < 0.0F) {
    /* Saturate: '<S12>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S12>/Saturation' */
    rtb_t_delay_on = masc_t_vehSpdEstVhlMasOnDeb_s;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Saturate: '<S12>/Saturation1' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  if (masc_t_vehSpdEstVhlMasOffDeb_s > 1.6777216E+7F) {
    /* Saturate: '<S12>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (masc_t_vehSpdEstVhlMasOffDeb_s < 0.0F) {
    /* Saturate: '<S12>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S12>/Saturation1' */
    rtb_t_delay_off = masc_t_vehSpdEstVhlMasOffDeb_s;
  }

  /* End of Saturate: '<S12>/Saturation1' */

  /* Chart: '<S12>/timed_debounce' incorporates:
   *  Constant: '<S4>/Constant3'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   */
  if (swc_MEST_ARID_DEF.is_active_c6_Ricardo_SW_dev_lib == 0U) {
    swc_MEST_ARID_DEF.is_active_c6_Ricardo_SW_dev_lib = 1U;
    if (rtb_RelationalOperator) {
      swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_ON;
    } else {
      swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_OFF;
    }
  } else {
    switch (swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib) {
     case swc_MEST_IN_OFF:
      if (rtb_RelationalOperator) {
        if (rtb_t_delay_on == 0.0F) {
          swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_ON;
        } else {
          swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_ON_WAIT;
          swc_MEST_ARID_DEF.t_wait = 0.0F;
          swc_MEST_ARID_DEF.t_wait += 0.01F;
          rtb_RelationalOperator = false;
        }
      }
      break;

     case swc_MEST_IN_OFF_WAIT:
      if (rtb_RelationalOperator) {
        swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_ON;
      } else if (swc_MEST_ARID_DEF.t_wait > rtb_t_delay_off - 0.01F) {
        swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_OFF;
      } else {
        swc_MEST_ARID_DEF.t_wait += 0.01F;
        rtb_RelationalOperator = true;
      }
      break;

     case swc_MEST_IN_ON:
      if (!rtb_RelationalOperator) {
        if (rtb_t_delay_off == 0.0F) {
          swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_OFF;
        } else {
          swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_OFF_WAIT;
          swc_MEST_ARID_DEF.t_wait = 0.0F;
          swc_MEST_ARID_DEF.t_wait += 0.01F;
          rtb_RelationalOperator = true;
        }
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_RelationalOperator) {
        swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_OFF;
      } else if (swc_MEST_ARID_DEF.t_wait > rtb_t_delay_on - 0.01F) {
        swc_MEST_ARID_DEF.is_c6_Ricardo_SW_dev_lib = swc_MEST_IN_ON;
      } else {
        swc_MEST_ARID_DEF.t_wait += 0.01F;
        rtb_RelationalOperator = false;
      }
      break;
    }
  }

  /* End of Chart: '<S12>/timed_debounce' */
  /* End of Outputs for SubSystem: '<S4>/debounce' */

  /* Switch: '<S4>/Switch1' */
  if (rtb_DataTypeConversion11 > 0.0) {
    /* Switch: '<S4>/Switch1' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion10'
     *  Inport generated from: '<Root>/BusElementIn1'
     */
    rtb_RelationalOperator = Rte_IRead_swc_MEST_Step_vcib_VCIP_pmmd_b_ignOn();
  } else {
    /* Switch: '<S4>/Switch1' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion10'
     *  Inport generated from: '<Root>/BusElementIn1'
     *  Logic: '<S4>/Logical Operator'
     */
    rtb_RelationalOperator = (Rte_IRead_swc_MEST_Step_vcib_VCIP_pmmd_b_ignOn() &&
      rtb_RelationalOperator);
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Chart: '<S4>/VhlMassEst' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant4'
   *  Constant: '<S10>/Constant6'
   *  Constant: '<S10>/Constant8'
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  DataTypeConversion: '<S2>/Data Type Conversion4'
   *  DataTypeConversion: '<S2>/Data Type Conversion5'
   */
  if (swc_MEST_ARID_DEF.temporalCounter_i1 < 3U) {
    swc_MEST_ARID_DEF.temporalCounter_i1++;
  }

  if (swc_MEST_ARID_DEF.is_active_c27_swc_MEST == 0U) {
    swc_MEST_ARID_DEF.is_active_c27_swc_MEST = 1U;
    swc_MEST_ARID_DEF.is_c27_swc_MEST = swc_MEST_IN_Init;
    swc_MEST_ARID_DEF.temporalCounter_i1 = 0U;
    MCA_Init(masc_m_vehWeightBase_kg, C_MCA_r, masc_m_vehWeightMin_kg,
             masc_m_vehWeightMax_kg, masc_m_vehWeightOvrLd1_kg,
             masc_m_vehWeightOvrLd2_kg);
  } else {
    switch (swc_MEST_ARID_DEF.is_c27_swc_MEST) {
     case swc_MEST_IN_Active:
      {
        if (!rtb_RelationalOperator) {
          swc_MEST_ARID_DEF.is_c27_swc_MEST = swc_MEST_IN_ReInit;
          MCA_ReInit();
          swc_MEST_ARID_DEF.dataValidFlg = MCA_Output
            (&swc_MEST_ARID_DEF.MCA_TotalMass,
             &swc_MEST_ARID_DEF.MCA_OverLoadFlag, &swc_MEST_ARID_DEF.MCA_DataID);
        } else {
          float32 tmp;
          float32 tmp_0;

          /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
           *  Inport generated from: '<Root>/vcib_VCIP_in50'
           */
          rtb_t_delay_on = fmodf(floorf
            (Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm()),
            65536.0F);

          /* DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
           *  Inport generated from: '<Root>/vcib_VCIP_in49'
           */
          rtb_t_delay_off = fmodf(floorf
            (Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm()), 65536.0F);

          /* DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
           *  Inport generated from: '<Root>/vcib_VCIP_in1'
           */
          tmp = fmodf(floorf
                      (Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_u_busInv2HVAct_V()),
                      65536.0F);

          /* DataTypeConversion: '<S2>/Data Type Conversion5' incorporates:
           *  Inport generated from: '<Root>/vcib_VCIP_in2'
           */
          tmp_0 = fmodf(floorf
                        (Rte_IRead_swc_MEST_Step_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A
                         ()), 65536.0F);
          MCA_Input((sint16)(rtb_t_delay_on < 0.0F ? (sint32)(sint16)-(sint16)
                             (uint16)-rtb_t_delay_on : (sint32)(sint16)(uint16)
                             rtb_t_delay_on), (sint16)(rtb_t_delay_off < 0.0F ?
                     (sint32)(sint16)-(sint16)(uint16)-rtb_t_delay_off : (sint32)
                     (sint16)(uint16)rtb_t_delay_off), (uint16)(tmp < 0.0F ?
                     (sint32)(uint16)-(sint16)(uint16)-tmp : (sint32)(uint16)tmp),
                    (sint16)(tmp_0 < 0.0F ? (sint32)(sint16)-(sint16)(uint16)-
                             tmp_0 : (sint32)(sint16)(uint16)tmp_0));
          MCA_MainFunction();
          swc_MEST_ARID_DEF.dataValidFlg = MCA_Output
            (&swc_MEST_ARID_DEF.MCA_TotalMass,
             &swc_MEST_ARID_DEF.MCA_OverLoadFlag, &swc_MEST_ARID_DEF.MCA_DataID);
        }
      }
      break;

     case swc_MEST_IN_Init:
      if (swc_MEST_ARID_DEF.temporalCounter_i1 >= 2) {
        swc_MEST_ARID_DEF.is_c27_swc_MEST = swc_MEST_IN_ReInit;
        MCA_ReInit();
        swc_MEST_ARID_DEF.dataValidFlg = MCA_Output
          (&swc_MEST_ARID_DEF.MCA_TotalMass, &swc_MEST_ARID_DEF.MCA_OverLoadFlag,
           &swc_MEST_ARID_DEF.MCA_DataID);
      }
      break;

     default:
      /* case IN_ReInit: */
      if (rtb_RelationalOperator) {
        swc_MEST_ARID_DEF.is_c27_swc_MEST = swc_MEST_IN_Active;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/VhlMassEst' */

  /* DataTypeConversion: '<S4>/Data Type Conversion5' */
  rtb_DataTypeConversion5_m = swc_MEST_ARID_DEF.MCA_OverLoadFlag;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  masd_b_vehOvrLoadEnbl = (rtb_DataTypeConversion5_m == ((uint8)2U));

  /* DataTypeConversion: '<S4>/Data Type Conversion4' */
  masc_m_vehWeightRaw_kg = swc_MEST_ARID_DEF.MCA_TotalMass;

  /* DataTypeConversion: '<S4>/Data Type Conversion6' */
  rtb_DataTypeConversion6 = swc_MEST_ARID_DEF.MCA_DataID;

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_Compare = (rtb_DataTypeConversion6 >= masc_t_MassCallTime);

  /* Logic: '<S4>/Logical Operator3' */
  rtb_LogicalOperator3 = !rtb_RelationalOperator;

  /* Outputs for Atomic SubSystem: '<S4>/SR_latch' */
  swc_MEST_SR_latch(rtb_Compare, rtb_LogicalOperator3, &rtb_LogicalOperator3_e,
                    &swc_MEST_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S4>/SR_latch' */

  /* Switch: '<S4>/Switch3' incorporates:
   *  Logic: '<S4>/Logical Operator2'
   */
  if (rtb_LogicalOperator3_e && rtb_RelationalOperator) {
    /* Switch: '<S4>/Switch3' */
    rtb_Switch3 = masc_m_vehWeightRaw_kg;
  } else {
    /* Switch: '<S4>/Switch3' incorporates:
     *  UnitDelay: '<S4>/Unit Delay1'
     */
    rtb_Switch3 = swc_MEST_ARID_DEF.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S4>/Switch3' */

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  rtb_RelationalOperator = ((rtb_DataTypeConversion6 >= masc_t_MassCallTime) &&
    rtb_RelationalOperator);

  /* Switch: '<S4>/Switch' incorporates:
   *  RelationalOperator: '<S7>/FixPt Relational Operator'
   *  UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)rtb_RelationalOperator > (sint32)
      swc_MEST_ARID_DEF.DelayInput1_DSTATE) {
    /* Switch: '<S4>/Switch' */
    rtb_Switch = masc_m_vehWeightRaw_kg;
  } else {
    /* Switch: '<S4>/Switch' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    rtb_Switch = swc_MEST_ARID_DEF.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S4>/Switch2' */
  if (rtb_DataTypeConversion11 > 0.0) {
    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    masd_m_vehWeight_kg = (float32)rtb_Switch3;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    masd_m_vehWeight_kg = (float32)rtb_Switch;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element174'
   */
  rtb_DataTypeConversion1_f = Rte_IRead_swc_MEST_Step_vcsb_VOMM_vsmd_b_VehRun();

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  masd_st_vehOverLoadSts = rtb_DataTypeConversion5_m;

  /* DataTypeConversion: '<S2>/Data Type Conversion8' */
  masd_st_vehCalNum = rtb_DataTypeConversion6;

  /* DataTypeConversion: '<S4>/Data Type Conversion7' */
  rtb_DataTypeConversion7 = swc_MEST_ARID_DEF.dataValidFlg;

  /* Constant: '<S8>/Constant' */
  masd_MCA_CdA = C_MCA_CdA;

  /* Constant: '<S8>/Constant1' */
  masd_MCA_ig = C_MCA_ig;

  /* Constant: '<S8>/Constant2' */
  masd_MCA_r = C_MCA_r;

  /* Constant: '<S8>/Constant3' */
  masd_MCA_g = C_MCA_g;

  /* Constant: '<S8>/Constant4' */
  masd_MCA_Mmin = C_MCA_Mmin;

  /* Constant: '<S8>/Constant5' */
  masd_MCA_Mmax = C_MCA_Mmax;

  /* Constant: '<S8>/Constant6' */
  masd_MCA_MassOverload1 = C_MCA_MassOverload1;

  /* Constant: '<S8>/Constant7' */
  masd_MCA_MassOverload2 = C_MCA_MassOverload2;

  /* Constant: '<S8>/Constant8' */
  masd_MCA_Sta_Mass_Factor = C_MCA_Sta_Mass_Factor;

  /* Constant: '<S8>/Constant9' */
  masd_MCA_Sta_K_Ratio = C_MCA_Sta_K_Ratio;

  /* Constant: '<S8>/Constant10' */
  masd_MCA_Sta_Power_Lot = C_MCA_Sta_Power_Lot;

  /* Constant: '<S8>/Constant11' */
  masd_MCA_Sta_Acc_Lot = C_MCA_Sta_Acc_Lot;

  /* Constant: '<S8>/Constant12' */
  masd_MCA_Sta_Acc_Upt = C_MCA_Sta_Acc_Upt;

  /* Constant: '<S8>/Constant13' */
  masd_MCA_Sta_Vel_Lot = C_MCA_Sta_Vel_Lot;

  /* Constant: '<S8>/Constant16' */
  masd_MCA_Sta_MassScale_Factor = C_MCA_Sta_MassScale_Factor;

  /* Constant: '<S8>/Constant17' */
  masd_MCA_RLS_P0 = C_MCA_RLS_P0;

  /* Constant: '<S8>/Constant18' */
  masd_MCA_RLS_EfMk = C_MCA_RLS_EfMk;

  /* Constant: '<S8>/Constant19' */
  masd_MCA_RLS_EfTm = C_MCA_RLS_EfTm;

  /* Constant: '<S8>/Constant20' */
  masd_MCA_RLS_Acc_Lot = C_MCA_RLS_Acc_Lot;

  /* Constant: '<S8>/Constant21' */
  masd_MCA_RLS_Mr = C_MCA_RLS_Mr;

  /* Constant: '<S8>/Constant22' */
  masd_MCA_RLS_Eta = C_MCA_RLS_Eta;

  /* Constant: '<S8>/Constant23' */
  masd_MCA_RLS_Alpha = C_MCA_RLS_Alpha;

  /* Constant: '<S8>/Constant14' */
  masd_MCA_RLS_Dt = C_MCA_RLS_Dt;

  /* Constant: '<S8>/Constant15' */
  masd_MCA_RSL_MassScale_Factor = C_MCA_RSL_MassScale_Factor;

  /* Constant: '<S8>/Constant24' */
  masd_IFC_MCA_Rot_Max = C_IFC_MCA_Rot_Max;

  /* Constant: '<S8>/Constant25' */
  masd_IFC_MCA_Rot_Min = C_IFC_MCA_Rot_Min;

  /* Constant: '<S8>/Constant28' */
  masd_IFC_MCA_Torq_Max = C_IFC_MCA_Torq_Max;

  /* Constant: '<S8>/Constant29' */
  masd_IFC_MCA_Torq_Min = C_IFC_MCA_Torq_Min;

  /* Constant: '<S8>/Constant30' */
  masd_IFC_MCA_Vlt_Max = C_IFC_MCA_Vlt_Max;

  /* Constant: '<S8>/Constant31' */
  masd_IFC_MCA_Vlt_Min = C_IFC_MCA_Vlt_Min;

  /* Constant: '<S8>/Constant32' */
  masd_IFC_MCA_Crt_Max = C_IFC_MCA_Crt_Max;

  /* Constant: '<S8>/Constant33' */
  masd_IFC_MCA_Crt_Min = C_IFC_MCA_Crt_Min;

  /* Constant: '<S8>/Constant34' */
  masd_MCA_RLS_Mass_ST = C_MCA_RLS_Mass_ST;

  /* Constant: '<S8>/Constant35' */
  masd_MCA_Sta_Mass_ST = C_MCA_Sta_Mass_ST;

  /* Constant: '<S8>/Constant26' */
  masd_MCA_Cls_Num = C_MCA_Cls_Num;

  /* Constant: '<S8>/Constant27' */
  masd_MCA_ResutlCom_Num = C_MCA_ResutlCom_Num;

  /* Constant: '<S8>/Constant36' */
  masd_MCA_Total_Factor = C_MCA_Total_Factor;

  /* Constant: '<S8>/Constant37' */
  masd_MCA_Sta_Dt = C_MCA_Sta_Dt;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  swc_MEST_ARID_DEF.UnitDelay1_DSTATE = rtb_Switch3;

  /* Update for UnitDelay: '<S7>/Delay Input1'
   *
   * Block description for '<S7>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_MEST_ARID_DEF.DelayInput1_DSTATE = rtb_RelationalOperator;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  swc_MEST_ARID_DEF.UnitDelay_DSTATE = rtb_Switch;

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator1' */

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_st_vehOverLoadSts
    (masd_st_vehOverLoadSts);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_m_vehWeight_kg(masd_m_vehWeight_kg);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_st_vehCalNum(masd_st_vehCalNum);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  Rte_IWrite_swc_MEST_Step_vcsb_MEST_masd_b_vehOvrLoadEnbl(masd_b_vehOvrLoadEnbl);
}

/* Model initialize function */
void swc_MEST_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
