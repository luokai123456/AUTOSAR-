/*
 * File: swc_OGVL.c
 *
 * Code generated for Simulink model 'swc_OGVL'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Aug 20 10:58:11 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_OGVL.h"
#include "rtwtypes.h"
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef VEH_SPD_MAX
#error The value of parameter "VEH_SPD_MAX" is not defined
#endif

#ifndef VSL_TASK_INTERVAL_S
#error The value of parameter "VSL_TASK_INTERVAL_S" is not defined
#endif

/* Named constants for Chart: '<S16>/timed_delay' */
#define swc_OGVL_IN_OFF                ((uint8)1U)
#define swc_OGVL_IN_ON                 ((uint8)2U)
#define swc_OGVL_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S4>/En_Immediately_Dis_NextKeyOn' */
#define swc_OGVL_IN_DisEnable          ((uint8)1U)
#define swc_OGVL_IN_DisEnableLatch     ((uint8)2U)
#define swc_OGVL_IN_EnableExecute      ((uint8)3U)
#define swc_OGVL_IN_EnableExecute1     ((uint8)4U)
#define swc_OGVL_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_OGVL_IN_TboxLost           ((uint8)5U)
#define swc_OGVL_IN_WakeUp             ((uint8)6U)

/* Named constants for Chart: '<S14>/timed_delay' */
#define swc_OGVL_IN_OFF_g              ((uint8)1U)
#define swc_OGVL_IN_ON_WAIT_g          ((uint8)3U)
#define swc_OGVL_IN_ON_l               ((uint8)2U)

/* Named constants for Chart: '<S6>/En_Immediately_Dis_Immediately' */
#define swc_OGVL_IN_EnableExecute_e    ((uint8)2U)
#define swc_OGVL_IN_TboxLost_d         ((uint8)3U)
#define swc_OGVL_IN_WakeUp_h           ((uint8)4U)

/* Named constants for Chart: '<S7>/ControlTorqueOff' */
#define swc_OGVL_IN_Active             ((uint8)1U)
#define swc_OGVL_IN_Init               ((uint8)2U)
#define swc_OGVL_IN_LimitTorque        ((uint8)1U)
#define swc_OGVL_IN_ZeroTorque         ((uint8)2U)

/* Named constants for Chart: '<S7>/En_Immediately_Dis_NextKeyOn' */
#define swc_OGVL_IN_DisEnableExecute   ((uint8)2U)
#define swc_OGVL_IN_DisEnableLatch_i   ((uint8)3U)
#define swc_OGVL_IN_EnableExecute_eu   ((uint8)4U)

/* Named constants for Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
#define swc_OGVL_IN_DisEnableExecute_f ((uint8)1U)
#define swc_OGVL_IN_Key_On             ((uint8)3U)
#define swc_OGVL_IN_TboxLost_k         ((uint8)4U)
#define swc_OGVL_IN_WakeUp_i           ((uint8)5U)

/* Exported data definition */
#define swc_OGVL_START_SEC_CONST_VOLATILE
#include "swc_OGVL_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean ogvl_dtlc_b_nvmWriteAntiDismtLckReq_ovrdflg = false;
            /* Referenced by: '<S100>/dtlc_b_nvmWriteAntiDismtLckReq_ovrdflg' */
const volatile boolean ogvl_dtlc_b_nvmWriteDSTNOSC_ovrdflg = false;
                    /* Referenced by: '<S101>/dtlc_b_nvmWriteDSTNOSC_ovrdflg' */
const volatile boolean ogvl_dtlc_b_nvmWriteInvtryLck_ovrdflg = false;
             /* Referenced by: '<S102>/ogvl_dtlc_b_nvmWriteInvtryLck_ovrdflg' */
const volatile boolean ogvl_dtlc_b_nvmWritePwrOffCmdReq_ovrdflg = false;
               /* Referenced by: '<S103>/dtlc_b_nvmWritePwrOffCmdReq_ovrdflg' */
const volatile boolean ogvl_dtlc_b_nvmWriteSpdLmtLvlReq_ovrdflg = false;
               /* Referenced by: '<S104>/dtlc_b_nvmWriteSpdLmtLvlReq_ovrdflg' */
const volatile uint8 ogvl_dtlc_st_nvmWriteAntiDismtLckReq_ovrdval = 0U;
           /* Referenced by: '<S100>/dtlc_st_nvmWriteAntiDismtLckReq_ovrdval' */
const volatile uint8 ogvl_dtlc_st_nvmWriteDSTNOSC_ovrdval = 0U;
                   /* Referenced by: '<S101>/dtlc_st_nvmWriteDSTNOSC_ovrdval' */
const volatile uint8 ogvl_dtlc_st_nvmWriteInvtryLck_ovrdval = 0U;
            /* Referenced by: '<S102>/ogvl_dtlc_st_nvmWriteInvtryLck_ovrdval' */
const volatile uint8 ogvl_dtlc_st_nvmWritePwrOffCmdReq_ovrdval = 0U;
              /* Referenced by: '<S103>/dtlc_st_nvmWritePwrOffCmdReq_ovrdval' */
const volatile uint8 ogvl_dtlc_st_nvmWriteSpdLmtLvlReq_ovrdval = 0U;
              /* Referenced by: '<S104>/dtlc_st_nvmWriteSpdLmtLvlReq_ovrdval' */
const volatile boolean ovgl_b_nvmWriteTboxDsmtSet_ovrdflg = false;
                /* Referenced by: '<S105>/ovgl_b_nvmWriteTboxDsmtSet_ovrdflg' */
const volatile uint8 ovgl_b_nvmWriteTboxDsmtSet_ovrdval = 0U;
                /* Referenced by: '<S105>/ovgl_b_nvmWriteTboxDsmtSet_ovrdval' */
const volatile float32 vslc_tm_IgnOnGetNvmDly_s = 0.0F;/* Referenced by: '<S3>/Constant11' */
const volatile float32 vslc_tm_tboxDsmtDlyOff_s = 2.0F;/* Referenced by: '<S4>/Constant57' */
const volatile float32 vslc_tm_tboxDsmtDlyOn_s = 120.0F;/* Referenced by: '<S4>/Constant56' */
const volatile float32 vslc_tm_tboxVerConvDlyOff_s = 10.0F;/* Referenced by: '<S57>/Constant5' */
const volatile float32 vslc_tm_tboxVerConvDlyOn_s = 10.0F;/* Referenced by: '<S58>/Constant4' */
const volatile float32 vslc_v_vehSpdLimLevel1_kph = 5.0F;/* Referenced by:
                                                          * '<S5>/Constant1'
                                                          * '<S9>/Constant1'
                                                          */

/* Speed limit Level1 */
const volatile float32 vslc_v_vehSpdLimLevel2_kph = 60.0F;/* Referenced by:
                                                           * '<S5>/Constant3'
                                                           * '<S9>/Constant3'
                                                           */

/* Speed limit Level2 */
const volatile float32 vslc_v_vehSpdLimLevel3_kph = 80.0F;/* Referenced by:
                                                           * '<S5>/Constant13'
                                                           * '<S9>/Constant13'
                                                           */

/* Speed limit Level3 */
const volatile float32 vslc_v_vehSpdUpdLimCfg_kph = 2.0F;/* Referenced by: '<S9>/Constant2' */

/* Remote Lock Speed Limit Update Enable Speed Threshold */
#define swc_OGVL_STOP_SEC_CONST_VOLATILE
#include "swc_OGVL_MemMap.h"
#define swc_OGVL_START_SEC_VAR
#include "swc_OGVL_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
uint8 Ovrd_b_nvmWriteTboxDsmtWrite;    /* '<S123>/Switch2' */
boolean ovgl_b_dstTboxDsmtExc;        /* '<S4>/En_Immediately_Dis_NextKeyOn1' */
boolean ovgl_dtld_b_dstAntiDismtLckDis;/* '<S4>/Logical Operator2' */
boolean ovgl_dtld_b_dstAntiDismtLckEn; /* '<S4>/Logical Operator12' */
boolean ovgl_dtld_b_dstAntiDismtLckExc;/* '<S4>/En_Immediately_Dis_NextKeyOn' */
boolean ovgl_dtld_b_dstCtrlTqLmt;      /* '<S7>/Signal Conversion' */
boolean ovgl_dtld_b_dstCtrlTqOff;      /* '<S7>/Signal Conversion1' */
boolean ovgl_dtld_b_dstInvtryLckDis;   /* '<S96>/timed_delay' */
boolean ovgl_dtld_b_dstInvtryLckEn;    /* '<S94>/timed_delay' */
boolean ovgl_dtld_b_dstInvtryLckExc;  /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
boolean ovgl_dtld_b_dstInvtryLckRead;  /* '<S8>/Data Type Conversion4' */
boolean ovgl_dtld_b_dstInvtryLckWrite;/* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
boolean ovgl_dtld_b_dstLckVehVerDis;   /* '<S59>/timed_delay' */
boolean ovgl_dtld_b_dstLckVehVerEn;    /* '<S61>/timed_delay' */
boolean ovgl_dtld_b_dstLckVehVerExc; /* '<S6>/En_Immediately_Dis_Immediately' */
boolean ovgl_dtld_b_dstLckVehVerWrite;
                                     /* '<S6>/En_Immediately_Dis_Immediately' */
boolean ovgl_dtld_b_dstPwrOffDis;      /* '<S65>/timed_delay' */
boolean ovgl_dtld_b_dstPwrOffExc;      /* '<S7>/En_Immediately_Dis_NextKeyOn' */
boolean ovgl_dtld_b_dstPwrOffOn;       /* '<S66>/timed_delay' */
boolean ovgl_dtld_b_dstPwrOffWrite;    /* '<S7>/En_Immediately_Dis_NextKeyOn' */
boolean ovgl_dtld_b_dstSpdLmtLvl1Dis;  /* '<S86>/timed_delay' */
boolean ovgl_dtld_b_dstSpdLmtLvl1En;   /* '<S88>/timed_delay' */
boolean ovgl_dtld_b_dstSpdLmtLvl1Exc;
                                 /* '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */
boolean ovgl_dtld_b_dstSpdLmtLvl1Write;
                                 /* '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */
boolean ovgl_dtld_b_dstSpdLmtLvl2Dis;  /* '<S90>/timed_delay' */
boolean ovgl_dtld_b_dstSpdLmtLvl2En;   /* '<S98>/timed_delay' */
boolean ovgl_dtld_b_dstSpdLmtLvl2Exc; /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
boolean ovgl_dtld_b_dstSpdLmtLvl2Write;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
boolean ovgl_dtld_b_dstSpdLmtLvl3Dis;  /* '<S92>/timed_delay' */
boolean ovgl_dtld_b_dstSpdLmtLvl3En;   /* '<S84>/timed_delay' */
boolean ovgl_dtld_b_dstSpdLmtLvl3Exc; /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
boolean ovgl_dtld_b_dstSpdLmtLvl3Write;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
uint8 ovgl_dtld_st_dstAntiDismtLckRead;/* '<S8>/Data Type Conversion3' */
uint8 ovgl_dtld_st_dstLckVehVerRead;   /* '<S8>/Data Type Conversion2' */
uint8 ovgl_dtld_st_dstPwrOffCmdRead;   /* '<S8>/Data Type Conversion1' */
uint8 ovgl_dtld_st_dstSpdLmtLvlRead;   /* '<S8>/Data Type Conversion5' */
uint8 ovgl_dtld_st_dstSpdLmtLvlWrite;  /* '<S10>/Switch4' */
uint8 ovgl_dtld_st_dstTboxDsmtRead;    /* '<S8>/Data Type Conversion13' */
uint8 ovgl_dtld_st_nvmWriteAntiDismtLckReq;/* '<S118>/Switch2' */
uint8 ovgl_dtld_st_nvmWriteDSTNOSC;    /* '<S119>/Switch2' */
uint8 ovgl_dtld_st_nvmWriteDismantleCmdCnt;/* '<S107>/Counter' */
boolean ovgl_dtld_st_nvmWriteDismantleCmdEnbl;/* '<S107>/SR_latch' */
uint8 ovgl_dtld_st_nvmWriteDismantleCmdReturnVal;
                                     /* '<S107>/mBSW_NvmRead_DSTNOSC_retval1' */
boolean ovgl_dtld_st_nvmWriteDismantleCmdRset;/* '<S129>/FixPt Relational Operator' */
uint8 ovgl_dtld_st_nvmWriteDismantleCmd_1s;/* '<S107>/Signal Conversion' */
uint8 ovgl_dtld_st_nvmWriteDstLckVehTypeCmdCnt;/* '<S108>/Counter' */
boolean ovgl_dtld_st_nvmWriteDstLckVehTypeCmdEnbl;/* '<S108>/SR_latch' */
uint8 ovgl_dtld_st_nvmWriteDstLckVehTypeCmdReturnVal;
                                     /* '<S108>/mBSW_NvmRead_DSTNOSC_retval1' */
boolean ovgl_dtld_st_nvmWriteDstLckVehTypeCmdRset;/* '<S133>/FixPt Relational Operator' */
uint8 ovgl_dtld_st_nvmWriteDstLckVehTypeCmd_1s;/* '<S108>/Signal Conversion' */
uint8 ovgl_dtld_st_nvmWriteDstNoscCnt; /* '<S106>/Counter' */
boolean ovgl_dtld_st_nvmWriteDstNoscEnbl;/* '<S106>/SR_latch' */
boolean ovgl_dtld_st_nvmWriteDstNoscRset;/* '<S125>/FixPt Relational Operator' */
uint8 ovgl_dtld_st_nvmWriteDstNosc_1s; /* '<S106>/Signal Conversion' */
uint8 ovgl_dtld_st_nvmWriteDstPwrOffCmdReqCnt;/* '<S110>/Counter' */
boolean ovgl_dtld_st_nvmWriteDstPwrOffCmdReqEnbl;/* '<S110>/SR_latch' */
uint8 ovgl_dtld_st_nvmWriteDstPwrOffCmdReqReturnVal;
                                     /* '<S110>/mBSW_NvmRead_DSTNOSC_retval1' */
boolean ovgl_dtld_st_nvmWriteDstPwrOffCmdReqRset;/* '<S141>/FixPt Relational Operator' */
uint8 ovgl_dtld_st_nvmWriteDstPwrOffCmdReq_1s;/* '<S110>/Signal Conversion' */
uint8 ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqCnt;/* '<S109>/Counter' */
boolean ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqEnbl;/* '<S109>/SR_latch' */
uint8 ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqReturnVal;
                                     /* '<S109>/mBSW_NvmRead_DSTNOSC_retval1' */
boolean ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqRset;/* '<S137>/FixPt Relational Operator' */
uint8 ovgl_dtld_st_nvmWriteDstSpdLmtLvlReq_1s;/* '<S109>/Signal Conversion' */
boolean ovgl_dtld_st_nvmWriteDstTboxDsmtEnbl;/* '<S111>/SR_latch' */
uint8 ovgl_dtld_st_nvmWriteDstTboxDsmtReturnVal;
                                     /* '<S111>/mBSW_NvmRead_TboxDsmt_retval' */
boolean ovgl_dtld_st_nvmWriteDstTboxDsmtRset;/* '<S145>/FixPt Relational Operator' */
uint8 ovgl_dtld_st_nvmWriteDstnoscReturnVal;
                                     /* '<S106>/mBSW_NvmRead_DSTNOSC_retval1' */
uint8 ovgl_dtld_st_nvmWriteInvtryLck;  /* '<S120>/Switch2' */
uint8 ovgl_dtld_st_nvmWritePwrOffCmdReq;/* '<S121>/Switch2' */
uint8 ovgl_dtld_st_nvmWriteSpdLmtLvlReq;/* '<S122>/Switch2' */
boolean vsld_b_dstTboxDsmtReset;       /* '<S15>/timed_delay' */
boolean vsld_b_dstTboxDsmtSet;         /* '<S14>/timed_delay' */
float32 vsld_v_dstSpdLimRaw_kph;       /* '<S9>/Switch' */
float32 vsld_v_dstSpdLim_kph;          /* '<S9>/Switch3' */

#define swc_OGVL_STOP_SEC_VAR
#include "swc_OGVL_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_OGVL_T swc_OGVL_ConstB = {
  100.0,                               /* '<S112>/Divide' */
  100.0,                               /* '<S113>/Divide' */
  100.0,                               /* '<S114>/Divide' */
  100.0,                               /* '<S115>/Divide' */
  100.0,                               /* '<S116>/Divide' */
  100.0                                /* '<S117>/Divide' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_OGVL_T swc_OGVL_ARID_DEF;
static void swc_OGVL_turnON_delay3_Init(boolean *rty_flg_out);
static boolean swc_OGVL_turnON_delay3(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, ARID_DEF_turnON_delay3_swc_OG_T *swc_OGVL__ARID_DEF_arg);
static void swc_OGVL_Counter(uint8 rtu_Inc_step, uint8 rtu_Reset, boolean
  rtu_Enable, uint8 *rty_Count_out, ARID_DEF_Counter_swc_OGVL_T
  *swc_OGVL__ARID_DEF_arg);
static void swc_OGVL_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_OGVL_T *swc_OGVL__ARID_DEF_arg);

/*
 * System initialize for atomic system:
 *    '<S4>/turnON_delay3'
 *    '<S4>/turnON_delay4'
 *    '<S23>/turnON_delay1'
 *    '<S24>/turnON_delay1'
 *    '<S25>/turnON_delay1'
 *    '<S26>/turnON_delay1'
 *    '<S27>/turnON_delay1'
 *    '<S28>/turnON_delay1'
 *    '<S29>/turnON_delay1'
 *    '<S30>/turnON_delay1'
 *    ...
 */
static void swc_OGVL_turnON_delay3_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S16>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S4>/turnON_delay3'
 *    '<S4>/turnON_delay4'
 *    '<S23>/turnON_delay1'
 *    '<S24>/turnON_delay1'
 *    '<S25>/turnON_delay1'
 *    '<S26>/turnON_delay1'
 *    '<S27>/turnON_delay1'
 *    '<S28>/turnON_delay1'
 *    '<S29>/turnON_delay1'
 *    '<S30>/turnON_delay1'
 *    ...
 */
static boolean swc_OGVL_turnON_delay3(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, ARID_DEF_turnON_delay3_swc_OG_T *swc_OGVL__ARID_DEF_arg)
{
  boolean rty_flg_out_0;
  float32 rtb_t_delay_on_f;

  /* Saturate: '<S16>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S16>/Saturation' */
    rtb_t_delay_on_f = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S16>/Saturation' */
    rtb_t_delay_on_f = 0.0F;
  } else {
    /* Saturate: '<S16>/Saturation' */
    rtb_t_delay_on_f = rtu_t_delay_on;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Chart: '<S16>/timed_delay' incorporates:
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  if (swc_OGVL__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_OGVL__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON;
      rty_flg_out_0 = true;
    } else {
      swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_OFF;
      rty_flg_out_0 = false;
    }
  } else {
    switch (swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_OGVL_IN_OFF:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_f == 0.0F) {
          swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON;
          rty_flg_out_0 = true;
        } else {
          swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_OGVL_IN_ON_WAIT;
          swc_OGVL__ARID_DEF_arg->t_wait = rtu_t_step;
          rty_flg_out_0 = false;
        }
      } else {
        rty_flg_out_0 = false;
      }
      break;

     case swc_OGVL_IN_ON:
      if (!rtu_flg_in) {
        swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_OFF;
        rty_flg_out_0 = false;
      } else {
        rty_flg_out_0 = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_OFF;
        rty_flg_out_0 = false;
      } else if (swc_OGVL__ARID_DEF_arg->t_wait > rtb_t_delay_on_f - rtu_t_step)
      {
        swc_OGVL__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON;
        rty_flg_out_0 = true;
      } else {
        swc_OGVL__ARID_DEF_arg->t_wait += rtu_t_step;
        rty_flg_out_0 = false;
      }
      break;
    }
  }

  /* End of Chart: '<S16>/timed_delay' */
  return rty_flg_out_0;
}

/*
 * Output and update for atomic system:
 *    '<S106>/Counter'
 *    '<S107>/Counter'
 *    '<S108>/Counter'
 *    '<S109>/Counter'
 *    '<S110>/Counter'
 *    '<S111>/Counter'
 */
static void swc_OGVL_Counter(uint8 rtu_Inc_step, uint8 rtu_Reset, boolean
  rtu_Enable, uint8 *rty_Count_out, ARID_DEF_Counter_swc_OGVL_T
  *swc_OGVL__ARID_DEF_arg)
{
  uint8 tmp;

  /* Switch: '<S124>/Switch2' incorporates:
   *  UnitDelay: '<S124>/UnitDelay3'
   */
  if (rtu_Enable) {
    tmp = swc_OGVL__ARID_DEF_arg->UnitDelay3_DSTATE;
  } else {
    tmp = rtu_Reset;
  }

  /* Sum: '<S124>/Sum6' incorporates:
   *  Switch: '<S124>/Switch2'
   */
  *rty_Count_out = (uint8)((uint32)rtu_Inc_step + tmp);

  /* Update for UnitDelay: '<S124>/UnitDelay3' */
  swc_OGVL__ARID_DEF_arg->UnitDelay3_DSTATE = *rty_Count_out;
}

/*
 * Output and update for atomic system:
 *    '<S106>/SR_latch'
 *    '<S107>/SR_latch'
 *    '<S108>/SR_latch'
 *    '<S109>/SR_latch'
 *    '<S110>/SR_latch'
 *    '<S111>/SR_latch'
 */
static void swc_OGVL_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_OGVL_T *swc_OGVL__ARID_DEF_arg)
{
  /* Logic: '<S126>/Logical Operator3' incorporates:
   *  Logic: '<S126>/Logical Operator'
   *  Logic: '<S126>/Logical Operator1'
   *  UnitDelay: '<S126>/Unit Delay'
   */
  *rty_flg_out = ((swc_OGVL__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S126>/Unit Delay' */
  swc_OGVL__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* Model step function */
void swc_OGVL_Step(void)
{
  /* local block i/o variables */
  uint8 rtb_Sum6;
  uint8 rtb_Sum6_j;
  uint8 rtb_Sum6_n;
  uint8 rtb_Sum6_l;
  uint8 rtb_Sum6_e;
  uint8 rtb_Sum6_k;
  boolean rtb_DataTypeConversion22;
  boolean rtb_flg_out;
  boolean rtb_LogicalOperator4;
  boolean rtb_RelationalOperator15_n;
  boolean rtb_RelationalOperator28_b;
  boolean rtb_RelationalOperator3_d;
  boolean rtb_RelationalOperator4;
  boolean rtb_RelationalOperator5_p;
  boolean rtb_RelationalOperator6_mc;
  boolean rtb_RelationalOperator7_c;
  boolean rtb_RelationalOperator8_j;
  boolean rtb_RelationalOperator10_d;
  boolean rtb_RelationalOperator9_c;
  boolean rtb_RelationalOperator14_i;
  boolean rtb_RelationalOperator16_i;
  boolean rtb_RelationalOperator1_k2;
  boolean rtb_RelationalOperator4_h;
  boolean rtb_RelationalOperator34;
  boolean rtb_RelationalOperator1_d;
  boolean rtb_LogicalOperator3_e;
  boolean rtb_RelationalOperator1_i;
  boolean rtb_LogicalOperator3_n;
  boolean rtb_RelationalOperator1_m;
  boolean rtb_LogicalOperator3_l;
  boolean rtb_RelationalOperator1_g;
  boolean rtb_LogicalOperator3_i;
  boolean rtb_RelationalOperator1_b;
  boolean rtb_LogicalOperator3_dl;
  boolean rtb_RelationalOperator1_h;
  boolean rtb_LogicalOperator3_f;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_n;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_m5;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_h;
  boolean rtb_flg_out_l;
  boolean rtb_flg_out_c;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_hy;
  boolean rtb_flg_out_cd;
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_gp;
  sint32 rtb_DataTypeConversion16;
  sint32 idxDelay;
  float32 rtb_DataTypeConversion21;
  uint8 rtb_DataTypeConversion12;
  uint8 rtb_DataTypeConversion13;
  uint8 rtb_DataTypeConversion14;
  uint8 rtb_DataTypeConversion15;
  uint8 rtb_DataTypeConversion19;
  uint8 rtb_DataTypeConversion20;
  boolean rtb_DataTypeConversion23;

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/BusElementIn6'
   */
  rtb_DataTypeConversion22 = Rte_IRead_swc_OGVL_Step_vcib_VCIP_pmmd_b_ignOn();

  /* Outputs for Atomic SubSystem: '<S3>/turnON_delay' */
  /* Constant: '<S3>/Constant11' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_flg_out = swc_OGVL_turnON_delay3(rtb_DataTypeConversion22,
    vslc_tm_IgnOnGetNvmDly_s, ((float32)VSL_TASK_INTERVAL_S),
    &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S3>/turnON_delay' */

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/BusElementIn1'
   */
  rtb_DataTypeConversion21 = Rte_IRead_swc_OGVL_Step_vcib_VCIP_vscd_v_vehSpd_kph
    ();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/BusElementIn3'
   */
  rtb_DataTypeConversion12 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxLockVehPerFlag();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/BusElementIn4'
   */
  rtb_DataTypeConversion13 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxVersionConversionFlag();

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/BusElementIn5'
   */
  rtb_DataTypeConversion15 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxSpdLmtLevelReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   */
  rtb_DataTypeConversion14 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxInventorySpdLmtReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/BusElementIn8'
   */
  rtb_DataTypeConversion16 = Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_tboxLife();

  /* DataTypeConversion: '<Root>/Data Type Conversion23' incorporates:
   *  Inport generated from: '<Root>/BusElementIn10'
   */
  rtb_DataTypeConversion23 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_b_obcWakeUpActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion20' incorporates:
   *  Inport generated from: '<Root>/BusElementIn9'
   */
  rtb_DataTypeConversion20 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_b_tboxPowOffCmd();

  /* DataTypeConversion: '<Root>/Data Type Conversion19' incorporates:
   *  Inport generated from: '<Root>/BusElementIn7'
   */
  rtb_DataTypeConversion19 =
    Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_actWorkSts1();

  /* Outputs for Enabled SubSystem: '<S1>/DstSpeedLimit' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* RelationalOperator: '<S1>/Relational Operator6' incorporates:
   *  Constant: '<S106>/Constant1'
   *  Constant: '<S106>/Constant2'
   *  Constant: '<S107>/Constant1'
   *  Constant: '<S107>/Constant2'
   *  Constant: '<S108>/Constant1'
   *  Constant: '<S108>/Constant2'
   *  Constant: '<S109>/Constant1'
   *  Constant: '<S109>/Constant2'
   *  Constant: '<S110>/Constant1'
   *  Constant: '<S110>/Constant2'
   *  Constant: '<S111>/Constant1'
   *  Constant: '<S111>/Constant2'
   *  Constant: '<S1>/Constant15'
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S24>/Constant1'
   *  Constant: '<S24>/Constant3'
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S25>/Constant3'
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S26>/Constant3'
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant3'
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant3'
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant3'
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant3'
   *  Constant: '<S31>/Constant1'
   *  Constant: '<S31>/Constant3'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant7'
   *  DataTypeConversion: '<Root>/Data Type Conversion24'
   *  Inport generated from: '<Root>/BusElementIn'
   *  RelationalOperator: '<S112>/Relational Operator1'
   *  RelationalOperator: '<S113>/Relational Operator1'
   *  RelationalOperator: '<S114>/Relational Operator1'
   *  RelationalOperator: '<S115>/Relational Operator1'
   *  RelationalOperator: '<S116>/Relational Operator1'
   *  RelationalOperator: '<S117>/Relational Operator1'
   */
  if (Rte_IRead_swc_OGVL_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() == ((uint8)1U))
  {
    float64 rtb_Add;
    float64 rtb_Switch;
    float64 rtb_Switch_b;
    float64 rtb_Switch_gb;
    float64 rtb_Switch_j;
    float64 rtb_Switch_p;
    float32 rtb_t_delay_on_e_tmp;
    float32 rtb_t_delay_on_kf;
    uint8 rtb_Add1;
    boolean rtb_DataTypeConversion12_a;
    boolean rtb_DataTypeConversion7_g;
    boolean rtb_DataTypeConversion8_o;
    boolean rtb_DataTypeConversion9_kq;
    boolean rtb_RelationalOperator;
    swc_OGVL_ARID_DEF.DstSpeedLimit_MODE = true;

    /* Outputs for Atomic SubSystem: '<S2>/ReadFromNVM' */
    /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
     *  CCaller: '<S8>/C Caller5'
     *  Sum: '<S22>/Add1'
     */
    ovgl_dtld_st_dstLckVehVerRead = mBSW_NvmRead_DSTNOSC_eep();

    /* DataTypeConversion: '<S8>/Data Type Conversion7' */
    rtb_DataTypeConversion7_g = (ovgl_dtld_st_dstLckVehVerRead != 0);

    /* DataTypeConversion: '<S8>/Data Type Conversion3' incorporates:
     *  CCaller: '<S8>/C Caller6'
     *  Sum: '<S22>/Add1'
     */
    ovgl_dtld_st_dstAntiDismtLckRead = mBSW_NvmRead_DismantleCmd_eep();

    /* DataTypeConversion: '<S8>/Data Type Conversion8' */
    rtb_DataTypeConversion8_o = (ovgl_dtld_st_dstAntiDismtLckRead != 0);

    /* Sum: '<S22>/Add1' incorporates:
     *  CCaller: '<S8>/C Caller1'
     */
    rtb_Add1 = mBSW_NvmRead_InventoryCmd_eep();

    /* DataTypeConversion: '<S8>/Data Type Conversion4' */
    ovgl_dtld_b_dstInvtryLckRead = (rtb_Add1 != 0);

    /* DataTypeConversion: '<S8>/Data Type Conversion9' */
    rtb_DataTypeConversion9_kq = ovgl_dtld_b_dstInvtryLckRead;

    /* DataTypeConversion: '<S8>/Data Type Conversion5' incorporates:
     *  CCaller: '<S8>/C Caller7'
     *  Sum: '<S22>/Add1'
     */
    ovgl_dtld_st_dstSpdLmtLvlRead = mBSW_NvmRead_SpdLmtCmd_eep();

    /* DataTypeConversion: '<S8>/Data Type Conversion10' */
    rtb_Add1 = ovgl_dtld_st_dstSpdLmtLvlRead;

    /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
     *  CCaller: '<S8>/C Caller9'
     *  Sum: '<S22>/Add1'
     */
    ovgl_dtld_st_dstPwrOffCmdRead = mBSW_NvmRead_PwrOffCmd_eep();

    /* DataTypeConversion: '<S8>/Data Type Conversion12' */
    rtb_DataTypeConversion12_a = (ovgl_dtld_st_dstPwrOffCmdRead != 0);

    /* DataTypeConversion: '<S8>/Data Type Conversion13' incorporates:
     *  CCaller: '<S8>/C Caller2'
     *  Sum: '<S22>/Add1'
     */
    ovgl_dtld_st_dstTboxDsmtRead = mBSW_NvmRead_TboxDsmt_eep();

    /* End of Outputs for SubSystem: '<S2>/ReadFromNVM' */

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_RelationalOperator = (rtb_DataTypeConversion13 == ((uint8)1U));

    /* Outputs for Atomic SubSystem: '<S58>/turnON_delay1' */
    /* Saturate: '<S61>/Saturation' incorporates:
     *  Constant: '<S58>/Constant4'
     */
    if (vslc_tm_tboxVerConvDlyOn_s > 1.6777216E+7F) {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on_kf = 1.6777216E+7F;
    } else if (vslc_tm_tboxVerConvDlyOn_s < 0.0F) {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on_kf = 0.0F;
    } else {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on_kf = vslc_tm_tboxVerConvDlyOn_s;
    }

    /* End of Saturate: '<S61>/Saturation' */

    /* Chart: '<S61>/timed_delay' incorporates:
     *  Constant: '<S58>/Constant3'
     *  DataTypeConversion: '<S61>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__a == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__a = 1U;
      if (rtb_RelationalOperator) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstLckVehVerEn = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstLckVehVerEn = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_RelationalOperator) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstLckVehVerEn = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_d = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_d += 0.01F;
            ovgl_dtld_b_dstLckVehVerEn = false;
          }
        } else {
          ovgl_dtld_b_dstLckVehVerEn = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_RelationalOperator) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstLckVehVerEn = false;
        } else {
          ovgl_dtld_b_dstLckVehVerEn = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_RelationalOperator) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstLckVehVerEn = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_d > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_d = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstLckVehVerEn = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_d += 0.01F;
          ovgl_dtld_b_dstLckVehVerEn = false;
        }
        break;
      }
    }

    /* End of Chart: '<S61>/timed_delay' */
    /* End of Outputs for SubSystem: '<S58>/turnON_delay1' */

    /* RelationalOperator: '<S6>/Relational Operator3' incorporates:
     *  Constant: '<S6>/Constant3'
     */
    rtb_RelationalOperator = (rtb_DataTypeConversion13 == ((uint8)0U));

    /* Outputs for Atomic SubSystem: '<S57>/turnON_delay1' */
    /* Saturate: '<S59>/Saturation' incorporates:
     *  Constant: '<S57>/Constant5'
     */
    if (vslc_tm_tboxVerConvDlyOff_s > 1.6777216E+7F) {
      /* Saturate: '<S59>/Saturation' */
      rtb_t_delay_on_kf = 1.6777216E+7F;
    } else if (vslc_tm_tboxVerConvDlyOff_s < 0.0F) {
      /* Saturate: '<S59>/Saturation' */
      rtb_t_delay_on_kf = 0.0F;
    } else {
      /* Saturate: '<S59>/Saturation' */
      rtb_t_delay_on_kf = vslc_tm_tboxVerConvDlyOff_s;
    }

    /* End of Saturate: '<S59>/Saturation' */

    /* Chart: '<S59>/timed_delay' incorporates:
     *  Constant: '<S57>/Constant3'
     *  DataTypeConversion: '<S59>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__m == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__m = 1U;
      if (rtb_RelationalOperator) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstLckVehVerDis = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstLckVehVerDis = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_RelationalOperator) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstLckVehVerDis = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_f = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_f += 0.01F;
            ovgl_dtld_b_dstLckVehVerDis = false;
          }
        } else {
          ovgl_dtld_b_dstLckVehVerDis = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_RelationalOperator) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstLckVehVerDis = false;
        } else {
          ovgl_dtld_b_dstLckVehVerDis = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_RelationalOperator) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstLckVehVerDis = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_f > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_bk = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstLckVehVerDis = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_f += 0.01F;
          ovgl_dtld_b_dstLckVehVerDis = false;
        }
        break;
      }
    }

    /* End of Chart: '<S59>/timed_delay' */
    /* End of Outputs for SubSystem: '<S57>/turnON_delay1' */

    /* Chart: '<S6>/En_Immediately_Dis_Immediately' */
    if (swc_OGVL_ARID_DEF.is_active_c12_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c12_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_WakeUp_h;
      ovgl_dtld_b_dstLckVehVerWrite = rtb_DataTypeConversion7_g;
      ovgl_dtld_b_dstLckVehVerExc = rtb_DataTypeConversion7_g;
    } else {
      switch (swc_OGVL_ARID_DEF.is_c12_swc_OGVL) {
       case swc_OGVL_IN_DisEnable:
        if (ovgl_dtld_b_dstLckVehVerEn) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstLckVehVerWrite = true;
          ovgl_dtld_b_dstLckVehVerExc = true;
        }
        break;

       case swc_OGVL_IN_EnableExecute_e:
        if (ovgl_dtld_b_dstLckVehVerDis) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstLckVehVerWrite = false;
          ovgl_dtld_b_dstLckVehVerExc = false;
        }
        break;

       case swc_OGVL_IN_TboxLost_d:
        if (ovgl_dtld_b_dstLckVehVerEn) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstLckVehVerWrite = true;
          ovgl_dtld_b_dstLckVehVerExc = true;
        } else if (ovgl_dtld_b_dstLckVehVerDis) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstLckVehVerWrite = false;
          ovgl_dtld_b_dstLckVehVerExc = false;
        } else {
          ovgl_dtld_b_dstLckVehVerWrite = rtb_DataTypeConversion7_g;
          ovgl_dtld_b_dstLckVehVerExc = rtb_DataTypeConversion7_g;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstLckVehVerEn) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstLckVehVerWrite = true;
          ovgl_dtld_b_dstLckVehVerExc = true;
        } else if (ovgl_dtld_b_dstLckVehVerDis) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstLckVehVerWrite = false;
          ovgl_dtld_b_dstLckVehVerExc = false;
        } else if ((!ovgl_dtld_b_dstLckVehVerEn) &&
                   (!ovgl_dtld_b_dstLckVehVerDis)) {
          swc_OGVL_ARID_DEF.is_c12_swc_OGVL = swc_OGVL_IN_TboxLost_d;
          ovgl_dtld_b_dstLckVehVerWrite = rtb_DataTypeConversion7_g;
          ovgl_dtld_b_dstLckVehVerExc = rtb_DataTypeConversion7_g;
        }
        break;
      }
    }

    /* End of Chart: '<S6>/En_Immediately_Dis_Immediately' */

    /* RelationalOperator: '<S22>/Relational Operator' incorporates:
     *  Logic: '<S4>/Logical Operator1'
     */
    rtb_DataTypeConversion7_g = (rtb_flg_out || rtb_DataTypeConversion23);

    /* Logic: '<S4>/Logical Operator5' incorporates:
     *  UnitDelay: '<S4>/Unit Delay'
     */
    swc_OGVL_ARID_DEF.vsld_b_dstTboxOfflineRaw =
      (swc_OGVL_ARID_DEF.UnitDelay_DSTATE_hv && rtb_DataTypeConversion7_g);

    /* Outputs for Atomic SubSystem: '<S4>/turnON_delay1' */
    /* Saturate: '<S14>/Saturation' incorporates:
     *  Constant: '<S4>/Constant56'
     */
    if (vslc_tm_tboxDsmtDlyOn_s > 1.6777216E+7F) {
      /* Saturate: '<S14>/Saturation' */
      rtb_t_delay_on_kf = 1.6777216E+7F;
    } else if (vslc_tm_tboxDsmtDlyOn_s < 0.0F) {
      /* Saturate: '<S14>/Saturation' */
      rtb_t_delay_on_kf = 0.0F;
    } else {
      /* Saturate: '<S14>/Saturation' */
      rtb_t_delay_on_kf = vslc_tm_tboxDsmtDlyOn_s;
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* Chart: '<S14>/timed_delay' incorporates:
     *  Constant: '<S4>/Constant58'
     *  DataTypeConversion: '<S14>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_g3 == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_g3 = 1U;
      if (swc_OGVL_ARID_DEF.vsld_b_dstTboxOfflineRaw) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o = swc_OGVL_IN_ON_l;
        vsld_b_dstTboxDsmtSet = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o = swc_OGVL_IN_OFF_g;
        vsld_b_dstTboxDsmtSet = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o) {
       case swc_OGVL_IN_OFF_g:
        if (swc_OGVL_ARID_DEF.vsld_b_dstTboxOfflineRaw) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o = swc_OGVL_IN_ON_l;
            vsld_b_dstTboxDsmtSet = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_p = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_p += 0.01F;
            vsld_b_dstTboxDsmtSet = false;
          }
        } else {
          vsld_b_dstTboxDsmtSet = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!swc_OGVL_ARID_DEF.vsld_b_dstTboxOfflineRaw) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o = swc_OGVL_IN_OFF_g;
          vsld_b_dstTboxDsmtSet = false;
        } else {
          vsld_b_dstTboxDsmtSet = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!swc_OGVL_ARID_DEF.vsld_b_dstTboxOfflineRaw) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o = swc_OGVL_IN_OFF_g;
          vsld_b_dstTboxDsmtSet = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_p > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_o = swc_OGVL_IN_ON_l;
          vsld_b_dstTboxDsmtSet = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_p += 0.01F;
          vsld_b_dstTboxDsmtSet = false;
        }
        break;
      }
    }

    /* End of Chart: '<S14>/timed_delay' */
    /* End of Outputs for SubSystem: '<S4>/turnON_delay1' */

    /* Logic: '<S4>/Logical Operator6' incorporates:
     *  Logic: '<S4>/Logical Operator3'
     */
    swc_OGVL_ARID_DEF.LogicalOperator6 =
      ((!swc_OGVL_ARID_DEF.vsld_b_dstTboxOfflineRaw) &&
       rtb_DataTypeConversion7_g);

    /* Outputs for Atomic SubSystem: '<S4>/turnON_delay2' */
    /* Saturate: '<S15>/Saturation' incorporates:
     *  Constant: '<S4>/Constant57'
     */
    if (vslc_tm_tboxDsmtDlyOff_s > 1.6777216E+7F) {
      /* Saturate: '<S15>/Saturation' */
      rtb_t_delay_on_kf = 1.6777216E+7F;
    } else if (vslc_tm_tboxDsmtDlyOff_s < 0.0F) {
      /* Saturate: '<S15>/Saturation' */
      rtb_t_delay_on_kf = 0.0F;
    } else {
      /* Saturate: '<S15>/Saturation' */
      rtb_t_delay_on_kf = vslc_tm_tboxDsmtDlyOff_s;
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* Chart: '<S15>/timed_delay' incorporates:
     *  Constant: '<S4>/Constant59'
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c10_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c10_swc_OGVL = 1U;
      if (swc_OGVL_ARID_DEF.LogicalOperator6) {
        swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_ON_l;
        vsld_b_dstTboxDsmtReset = true;
      } else {
        swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_OFF_g;
        vsld_b_dstTboxDsmtReset = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c10_swc_OGVL) {
       case swc_OGVL_IN_OFF_g:
        if (swc_OGVL_ARID_DEF.LogicalOperator6) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_ON_l;
            vsld_b_dstTboxDsmtReset = true;
          } else {
            swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_m = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_m += 0.01F;
            vsld_b_dstTboxDsmtReset = false;
          }
        } else {
          vsld_b_dstTboxDsmtReset = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!swc_OGVL_ARID_DEF.LogicalOperator6) {
          swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_OFF_g;
          vsld_b_dstTboxDsmtReset = false;
        } else {
          vsld_b_dstTboxDsmtReset = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!swc_OGVL_ARID_DEF.LogicalOperator6) {
          swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_OFF_g;
          vsld_b_dstTboxDsmtReset = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_m > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c10_swc_OGVL = swc_OGVL_IN_ON_l;
          vsld_b_dstTboxDsmtReset = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_m += 0.01F;
          vsld_b_dstTboxDsmtReset = false;
        }
        break;
      }
    }

    /* End of Chart: '<S15>/timed_delay' */
    /* End of Outputs for SubSystem: '<S4>/turnON_delay2' */

    /* Chart: '<S4>/En_Immediately_Dis_NextKeyOn1' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion14'
     */
    if (swc_OGVL_ARID_DEF.is_active_c1_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c1_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_WakeUp;

      /* Outputs for Atomic SubSystem: '<S2>/ReadFromNVM' */
      swc_OGVL_ARID_DEF.cmdWrite = (ovgl_dtld_st_dstTboxDsmtRead != 0);
      ovgl_b_dstTboxDsmtExc = (ovgl_dtld_st_dstTboxDsmtRead != 0);

      /* End of Outputs for SubSystem: '<S2>/ReadFromNVM' */
    } else {
      switch (swc_OGVL_ARID_DEF.is_c1_swc_OGVL) {
       case swc_OGVL_IN_DisEnable:
        if (vsld_b_dstTboxDsmtSet) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite = true;
          ovgl_b_dstTboxDsmtExc = true;
        } else if (!rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_DisEnableLatch;
          swc_OGVL_ARID_DEF.cmdWrite = false;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch:
        if ((rtb_flg_out && (!rtb_DataTypeConversion23)) || ((!rtb_flg_out) &&
             rtb_DataTypeConversion23) || (rtb_flg_out &&
             rtb_DataTypeConversion23)) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite = false;
          ovgl_b_dstTboxDsmtExc = false;
        }
        break;

       case swc_OGVL_IN_EnableExecute:
        if (vsld_b_dstTboxDsmtReset) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite = false;
          ovgl_b_dstTboxDsmtExc = false;
        } else if ((!rtb_flg_out) && vsld_b_dstTboxDsmtSet) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_EnableExecute1;
          swc_OGVL_ARID_DEF.cmdWrite = true;
          ovgl_b_dstTboxDsmtExc = true;
        }
        break;

       case swc_OGVL_IN_EnableExecute1:
        if (rtb_flg_out || rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite = true;
          ovgl_b_dstTboxDsmtExc = true;
        }
        break;

       case swc_OGVL_IN_TboxLost:
        if (vsld_b_dstTboxDsmtSet) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite = true;
          ovgl_b_dstTboxDsmtExc = true;
        } else if (vsld_b_dstTboxDsmtReset) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite = false;
          ovgl_b_dstTboxDsmtExc = false;
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/ReadFromNVM' */
          swc_OGVL_ARID_DEF.cmdWrite = (ovgl_dtld_st_dstTboxDsmtRead != 0);
          ovgl_b_dstTboxDsmtExc = (ovgl_dtld_st_dstTboxDsmtRead != 0);

          /* End of Outputs for SubSystem: '<S2>/ReadFromNVM' */
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (vsld_b_dstTboxDsmtSet) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite = true;
          ovgl_b_dstTboxDsmtExc = true;
        } else if (vsld_b_dstTboxDsmtReset) {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite = false;
          ovgl_b_dstTboxDsmtExc = false;
        } else {
          swc_OGVL_ARID_DEF.is_c1_swc_OGVL = swc_OGVL_IN_TboxLost;

          /* Outputs for Atomic SubSystem: '<S2>/ReadFromNVM' */
          swc_OGVL_ARID_DEF.cmdWrite = (ovgl_dtld_st_dstTboxDsmtRead != 0);
          ovgl_b_dstTboxDsmtExc = (ovgl_dtld_st_dstTboxDsmtRead != 0);

          /* End of Outputs for SubSystem: '<S2>/ReadFromNVM' */
        }
        break;
      }
    }

    /* End of Chart: '<S4>/En_Immediately_Dis_NextKeyOn1' */

    /* Logic: '<S4>/Logical Operator4' incorporates:
     *  Constant: '<S4>/Charging2'
     *  Constant: '<S4>/Cooling1'
     *  Constant: '<S4>/Heating2'
     *  RelationalOperator: '<S4>/Relational Operator36'
     *  RelationalOperator: '<S4>/Relational Operator37'
     *  RelationalOperator: '<S4>/Relational Operator38'
     */
    rtb_LogicalOperator4 = ((rtb_DataTypeConversion19 == ((uint8)5U)) ||
      (rtb_DataTypeConversion19 == ((uint8)8U)) || (rtb_DataTypeConversion19 ==
      ((uint8)9U)));

    /* Outputs for Atomic SubSystem: '<S4>/turnON_delay3' */
    rtb_flg_out_gp = swc_OGVL_turnON_delay3(rtb_LogicalOperator4, 5.0F, 0.01F,
      &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay3);

    /* End of Outputs for SubSystem: '<S4>/turnON_delay3' */

    /* Logic: '<S4>/Logical Operator12' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    ovgl_dtld_b_dstAntiDismtLckEn = (ovgl_dtld_b_dstLckVehVerExc &&
      ovgl_b_dstTboxDsmtExc && rtb_flg_out_gp);

    /* Logic: '<S4>/Logical Operator2' incorporates:
     *  Constant: '<S4>/Constant4'
     *  Logic: '<S4>/Logical Operator7'
     *  RelationalOperator: '<S4>/Relational Operator6'
     */
    ovgl_dtld_b_dstAntiDismtLckDis = ((!ovgl_b_dstTboxDsmtExc) &&
      (rtb_DataTypeConversion21 <= 3.0F));

    /* Chart: '<S4>/En_Immediately_Dis_NextKeyOn' */
    if (swc_OGVL_ARID_DEF.is_active_c8_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c8_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_WakeUp;
      swc_OGVL_ARID_DEF.cmdWrite_i = rtb_DataTypeConversion8_o;
      ovgl_dtld_b_dstAntiDismtLckExc = rtb_DataTypeConversion8_o;
    } else {
      boolean guard1 = false;
      guard1 = false;
      switch (swc_OGVL_ARID_DEF.is_c8_swc_OGVL) {
       case swc_OGVL_IN_DisEnable:
        if (ovgl_dtld_b_dstAntiDismtLckEn) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite_i = true;
          ovgl_dtld_b_dstAntiDismtLckExc = true;
        } else if (!rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_DisEnableLatch;
          swc_OGVL_ARID_DEF.cmdWrite_i = false;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch:
        if (rtb_flg_out && (!rtb_DataTypeConversion23)) {
          ovgl_dtld_b_dstAntiDismtLckExc = false;
          guard1 = true;
        } else if ((!rtb_flg_out) && rtb_DataTypeConversion23) {
          guard1 = true;
        } else if (rtb_flg_out && rtb_DataTypeConversion23) {
          ovgl_dtld_b_dstAntiDismtLckExc = false;
          guard1 = true;
        }
        break;

       case swc_OGVL_IN_EnableExecute:
        if (ovgl_dtld_b_dstAntiDismtLckDis) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite_i = false;
        } else if ((!rtb_flg_out) && ovgl_dtld_b_dstAntiDismtLckEn) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_EnableExecute1;
          swc_OGVL_ARID_DEF.cmdWrite_i = true;
          ovgl_dtld_b_dstAntiDismtLckExc = true;
        }
        break;

       case swc_OGVL_IN_EnableExecute1:
        if (rtb_flg_out || rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite_i = true;
          ovgl_dtld_b_dstAntiDismtLckExc = true;
        }
        break;

       case swc_OGVL_IN_TboxLost:
        if (ovgl_dtld_b_dstAntiDismtLckEn) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite_i = true;
          ovgl_dtld_b_dstAntiDismtLckExc = true;
        } else if (ovgl_dtld_b_dstAntiDismtLckDis) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite_i = false;
        } else {
          swc_OGVL_ARID_DEF.cmdWrite_i = rtb_DataTypeConversion8_o;
          ovgl_dtld_b_dstAntiDismtLckExc = rtb_DataTypeConversion8_o;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstAntiDismtLckEn) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_EnableExecute;
          swc_OGVL_ARID_DEF.cmdWrite_i = true;
          ovgl_dtld_b_dstAntiDismtLckExc = true;
        } else if (ovgl_dtld_b_dstAntiDismtLckDis) {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_DisEnable;
          swc_OGVL_ARID_DEF.cmdWrite_i = false;
        } else {
          swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_TboxLost;
          swc_OGVL_ARID_DEF.cmdWrite_i = rtb_DataTypeConversion8_o;
          ovgl_dtld_b_dstAntiDismtLckExc = rtb_DataTypeConversion8_o;
        }
        break;
      }

      if (guard1) {
        swc_OGVL_ARID_DEF.is_c8_swc_OGVL = swc_OGVL_IN_DisEnable;
        swc_OGVL_ARID_DEF.cmdWrite_i = false;
      }
    }

    /* End of Chart: '<S4>/En_Immediately_Dis_NextKeyOn' */

    /* Logic: '<S10>/Logical Operator20' incorporates:
     *  Constant: '<S10>/Constant22'
     *  Constant: '<S10>/Constant35'
     *  Constant: '<S10>/Constant46'
     *  Constant: '<S10>/Level11'
     *  RelationalOperator: '<S10>/Relational Operator35'
     *  RelationalOperator: '<S10>/Relational Operator39'
     *  RelationalOperator: '<S10>/Relational Operator40'
     *  RelationalOperator: '<S10>/Relational Operator44'
     */
    rtb_DataTypeConversion8_o = (ovgl_dtld_b_dstLckVehVerExc &&
      (rtb_DataTypeConversion12 == ((uint8)1U)) && (rtb_DataTypeConversion15 ==
      ((uint8)0U)) && (rtb_DataTypeConversion14 == ((uint8)1U)) &&
      (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S81>/turnON_delay1' */
    /* Saturate: '<S94>/Saturation' incorporates:
     *  Constant: '<S81>/Constant1'
     */
    if (5.0F > 1.6777216E+7F) {
      /* Outputs for Atomic SubSystem: '<S7>/turnON_delay2' */
      /* Outputs for Atomic SubSystem: '<S76>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S83>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S78>/turnON_delay1' */
      /* Saturate: '<S88>/Saturation' incorporates:
       *  Saturate: '<S66>/Saturation'
       *  Saturate: '<S84>/Saturation'
       *  Saturate: '<S98>/Saturation'
       */
      rtb_t_delay_on_kf = 1.6777216E+7F;

      /* End of Outputs for SubSystem: '<S78>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S83>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S76>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S7>/turnON_delay2' */
    } else if (5.0F < 0.0F) {
      /* Outputs for Atomic SubSystem: '<S7>/turnON_delay2' */
      /* Outputs for Atomic SubSystem: '<S76>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S83>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S78>/turnON_delay1' */
      /* Saturate: '<S88>/Saturation' incorporates:
       *  Saturate: '<S66>/Saturation'
       *  Saturate: '<S84>/Saturation'
       *  Saturate: '<S98>/Saturation'
       */
      rtb_t_delay_on_kf = 0.0F;

      /* End of Outputs for SubSystem: '<S78>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S83>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S76>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S7>/turnON_delay2' */
    } else {
      /* Outputs for Atomic SubSystem: '<S7>/turnON_delay2' */
      /* Outputs for Atomic SubSystem: '<S76>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S83>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S78>/turnON_delay1' */
      /* Saturate: '<S88>/Saturation' incorporates:
       *  Saturate: '<S66>/Saturation'
       *  Saturate: '<S84>/Saturation'
       *  Saturate: '<S98>/Saturation'
       */
      rtb_t_delay_on_kf = 5.0F;

      /* End of Outputs for SubSystem: '<S78>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S83>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S76>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S7>/turnON_delay2' */
    }

    /* Chart: '<S94>/timed_delay' incorporates:
     *  Constant: '<S81>/Constant3'
     *  DataTypeConversion: '<S94>/Data Type Conversion'
     *  Saturate: '<S94>/Saturation'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__c == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__c = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstInvtryLckEn = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstInvtryLckEn = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstInvtryLckEn = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_k = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_k += 0.01F;
            ovgl_dtld_b_dstInvtryLckEn = false;
          }
        } else {
          ovgl_dtld_b_dstInvtryLckEn = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstInvtryLckEn = false;
        } else {
          ovgl_dtld_b_dstInvtryLckEn = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstInvtryLckEn = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_k > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_f = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstInvtryLckEn = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_k += 0.01F;
          ovgl_dtld_b_dstInvtryLckEn = false;
        }
        break;
      }
    }

    /* End of Chart: '<S94>/timed_delay' */
    /* End of Outputs for SubSystem: '<S81>/turnON_delay1' */

    /* RelationalOperator: '<S22>/Relational Operator' incorporates:
     *  Constant: '<S10>/Constant21'
     *  RelationalOperator: '<S10>/Relational Operator41'
     */
    rtb_DataTypeConversion7_g = (rtb_DataTypeConversion12 == ((uint8)0U));

    /* Logic: '<S10>/Logical Operator21' incorporates:
     *  Constant: '<S10>/Constant23'
     *  Constant: '<S10>/Constant7'
     *  Constant: '<S10>/Level10'
     *  Constant: '<S10>/invalid'
     *  Logic: '<S10>/Logical Operator19'
     *  Logic: '<S10>/Logical Operator22'
     *  Logic: '<S10>/Logical Operator23'
     *  RelationalOperator: '<S10>/Relational Operator33'
     *  RelationalOperator: '<S10>/Relational Operator42'
     *  RelationalOperator: '<S10>/Relational Operator43'
     *  RelationalOperator: '<S10>/Relational Operator45'
     *  UnitDelay: '<S10>/UnitDelay1'
     *  UnitDelay: '<S10>/UnitDelay2'
     *  UnitDelay: '<S10>/UnitDelay4'
     */
    rtb_DataTypeConversion8_o = (((ovgl_dtld_b_dstLckVehVerExc == false) ||
      rtb_DataTypeConversion7_g || rtb_DataTypeConversion7_g ||
      ((rtb_DataTypeConversion15 != ((uint8)0U)) && (rtb_DataTypeConversion15 !=
      ((uint8)3U)) && (swc_OGVL_ARID_DEF.UnitDelay4_DSTATE ||
                       swc_OGVL_ARID_DEF.UnitDelay1_DSTATE_a ||
                       swc_OGVL_ARID_DEF.UnitDelay2_DSTATE_h))) &&
      (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S82>/turnON_delay1' */
    /* Saturate: '<S96>/Saturation' incorporates:
     *  Constant: '<S82>/Constant1'
     */
    if (2.0F > 1.6777216E+7F) {
      /* Outputs for Atomic SubSystem: '<S7>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S80>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S79>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S77>/turnON_delay1' */
      /* Saturate: '<S86>/Saturation' incorporates:
       *  Saturate: '<S65>/Saturation'
       *  Saturate: '<S90>/Saturation'
       *  Saturate: '<S92>/Saturation'
       */
      rtb_t_delay_on_e_tmp = 1.6777216E+7F;

      /* End of Outputs for SubSystem: '<S77>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S79>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S80>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S7>/turnON_delay1' */
    } else if (2.0F < 0.0F) {
      /* Outputs for Atomic SubSystem: '<S7>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S80>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S79>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S77>/turnON_delay1' */
      /* Saturate: '<S86>/Saturation' incorporates:
       *  Saturate: '<S65>/Saturation'
       *  Saturate: '<S90>/Saturation'
       *  Saturate: '<S92>/Saturation'
       */
      rtb_t_delay_on_e_tmp = 0.0F;

      /* End of Outputs for SubSystem: '<S77>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S79>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S80>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S7>/turnON_delay1' */
    } else {
      /* Outputs for Atomic SubSystem: '<S7>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S80>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S79>/turnON_delay1' */
      /* Outputs for Atomic SubSystem: '<S77>/turnON_delay1' */
      /* Saturate: '<S86>/Saturation' incorporates:
       *  Saturate: '<S65>/Saturation'
       *  Saturate: '<S90>/Saturation'
       *  Saturate: '<S92>/Saturation'
       */
      rtb_t_delay_on_e_tmp = 2.0F;

      /* End of Outputs for SubSystem: '<S77>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S79>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S80>/turnON_delay1' */
      /* End of Outputs for SubSystem: '<S7>/turnON_delay1' */
    }

    /* Chart: '<S96>/timed_delay' incorporates:
     *  Constant: '<S82>/Constant3'
     *  DataTypeConversion: '<S96>/Data Type Conversion'
     *  Saturate: '<S96>/Saturation'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__d == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__d = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstInvtryLckDis = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstInvtryLckDis = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_e_tmp == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstInvtryLckDis = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_l = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_l += 0.01F;
            ovgl_dtld_b_dstInvtryLckDis = false;
          }
        } else {
          ovgl_dtld_b_dstInvtryLckDis = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstInvtryLckDis = false;
        } else {
          ovgl_dtld_b_dstInvtryLckDis = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstInvtryLckDis = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_l > rtb_t_delay_on_e_tmp - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_b = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstInvtryLckDis = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_l += 0.01F;
          ovgl_dtld_b_dstInvtryLckDis = false;
        }
        break;
      }
    }

    /* End of Chart: '<S96>/timed_delay' */
    /* End of Outputs for SubSystem: '<S82>/turnON_delay1' */

    /* Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
    if (swc_OGVL_ARID_DEF.is_active_c18_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c18_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_WakeUp_i;
      ovgl_dtld_b_dstInvtryLckWrite = rtb_DataTypeConversion9_kq;
      ovgl_dtld_b_dstInvtryLckExc = rtb_DataTypeConversion9_kq;
    } else {
      switch (swc_OGVL_ARID_DEF.is_c18_swc_OGVL) {
       case swc_OGVL_IN_DisEnableExecute_f:
        if (ovgl_dtld_b_dstInvtryLckEn) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstInvtryLckWrite = true;
        } else if (ovgl_dtld_b_dstInvtryLckDis) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstInvtryLckWrite = false;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch:
        if (rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_DisEnableExecute_f;
          ovgl_dtld_b_dstInvtryLckExc = ovgl_dtld_b_dstInvtryLckWrite;
        } else if (ovgl_dtld_b_dstInvtryLckDis && rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstInvtryLckWrite = false;
        } else if (ovgl_dtld_b_dstInvtryLckEn && rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstInvtryLckWrite = true;
        }
        break;

       case swc_OGVL_IN_Key_On:
        if ((!rtb_flg_out) && (!rtb_DataTypeConversion23)) {
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_NO_ACTIVE_CHILD;
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_DisEnableLatch;
        } else if (swc_OGVL_ARID_DEF.is_Key_On_c == swc_OGVL_IN_DisEnable) {
          if (ovgl_dtld_b_dstInvtryLckEn) {
            swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_EnableExecute_e;
            ovgl_dtld_b_dstInvtryLckWrite = true;
          }

          /* case IN_EnableExecute: */
        } else if (ovgl_dtld_b_dstInvtryLckDis) {
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstInvtryLckWrite = false;
        }
        break;

       case swc_OGVL_IN_TboxLost_k:
        if (ovgl_dtld_b_dstInvtryLckEn) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstInvtryLckWrite = true;
        } else if (ovgl_dtld_b_dstInvtryLckDis) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstInvtryLckWrite = false;
        } else {
          ovgl_dtld_b_dstInvtryLckWrite = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstInvtryLckExc = rtb_DataTypeConversion9_kq;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstInvtryLckEn) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstInvtryLckWrite = true;
        } else if (ovgl_dtld_b_dstInvtryLckDis) {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_c = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstInvtryLckWrite = false;
        } else {
          swc_OGVL_ARID_DEF.is_c18_swc_OGVL = swc_OGVL_IN_TboxLost_k;
          ovgl_dtld_b_dstInvtryLckWrite = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstInvtryLckExc = rtb_DataTypeConversion9_kq;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */

    /* RelationalOperator: '<S10>/Relational Operator19' incorporates:
     *  Constant: '<S10>/Constant5'
     */
    rtb_DataTypeConversion9_kq = (rtb_Add1 == ((uint8)1U));

    /* Logic: '<S10>/Logical Operator1' incorporates:
     *  Constant: '<S10>/Charging2'
     *  Constant: '<S10>/Constant15'
     *  Constant: '<S10>/Constant17'
     *  Constant: '<S10>/Cooling1'
     *  Constant: '<S10>/Heating2'
     *  Constant: '<S10>/Level1'
     *  Logic: '<S10>/Logical Operator4'
     *  RelationalOperator: '<S10>/Relational Operator36'
     *  RelationalOperator: '<S10>/Relational Operator37'
     *  RelationalOperator: '<S10>/Relational Operator38'
     *  RelationalOperator: '<S10>/Relational Operator6'
     *  RelationalOperator: '<S10>/Relational Operator7'
     *  RelationalOperator: '<S10>/Relational Operator8'
     */
    rtb_DataTypeConversion8_o = ((ovgl_dtld_b_dstLckVehVerExc == true) &&
      (rtb_DataTypeConversion12 == ((uint8)1U)) && (rtb_DataTypeConversion15 ==
      ((uint8)0U)) && ((rtb_DataTypeConversion19 == ((uint8)5U)) ||
                       (rtb_DataTypeConversion19 == ((uint8)8U)) ||
                       (rtb_DataTypeConversion19 == ((uint8)9U))));

    /* Outputs for Atomic SubSystem: '<S78>/turnON_delay1' */
    /* Chart: '<S88>/timed_delay' incorporates:
     *  Constant: '<S78>/Constant49'
     *  DataTypeConversion: '<S88>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__p == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__p = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstSpdLmtLvl1En = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstSpdLmtLvl1En = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstSpdLmtLvl1En = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_g = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_g += 0.01F;
            ovgl_dtld_b_dstSpdLmtLvl1En = false;
          }
        } else {
          ovgl_dtld_b_dstSpdLmtLvl1En = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl1En = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl1En = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl1En = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_g > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstSpdLmtLvl1En = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_g += 0.01F;
          ovgl_dtld_b_dstSpdLmtLvl1En = false;
        }
        break;
      }
    }

    /* End of Chart: '<S88>/timed_delay' */
    /* End of Outputs for SubSystem: '<S78>/turnON_delay1' */

    /* Logic: '<S10>/Logical Operator2' incorporates:
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S10>/Constant25'
     *  Constant: '<S10>/Constant27'
     *  Constant: '<S10>/Level2'
     *  RelationalOperator: '<S10>/Relational Operator1'
     *  RelationalOperator: '<S10>/Relational Operator10'
     *  RelationalOperator: '<S10>/Relational Operator11'
     *  RelationalOperator: '<S10>/Relational Operator9'
     */
    rtb_DataTypeConversion8_o = ((ovgl_dtld_b_dstLckVehVerExc == true) &&
      (rtb_DataTypeConversion12 == ((uint8)1U)) && (rtb_DataTypeConversion15 ==
      ((uint8)1U)) && (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S83>/turnON_delay1' */
    /* Chart: '<S98>/timed_delay' incorporates:
     *  Constant: '<S83>/Constant49'
     *  DataTypeConversion: '<S98>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_li == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstSpdLmtLvl2En = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstSpdLmtLvl2En = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstSpdLmtLvl2En = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait = 0.0F;
            swc_OGVL_ARID_DEF.t_wait += 0.01F;
            ovgl_dtld_b_dstSpdLmtLvl2En = false;
          }
        } else {
          ovgl_dtld_b_dstSpdLmtLvl2En = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl2En = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl2En = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl2En = false;
        } else if (swc_OGVL_ARID_DEF.t_wait > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstSpdLmtLvl2En = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait += 0.01F;
          ovgl_dtld_b_dstSpdLmtLvl2En = false;
        }
        break;
      }
    }

    /* End of Chart: '<S98>/timed_delay' */
    /* End of Outputs for SubSystem: '<S83>/turnON_delay1' */

    /* Logic: '<S10>/Logical Operator11' incorporates:
     *  Constant: '<S10>/Constant11'
     *  Constant: '<S10>/Constant12'
     *  Constant: '<S10>/Constant13'
     *  Constant: '<S10>/Level8'
     *  RelationalOperator: '<S10>/Relational Operator25'
     *  RelationalOperator: '<S10>/Relational Operator26'
     *  RelationalOperator: '<S10>/Relational Operator27'
     *  RelationalOperator: '<S10>/Relational Operator28'
     */
    rtb_DataTypeConversion8_o = ((ovgl_dtld_b_dstLckVehVerExc == true) &&
      (rtb_DataTypeConversion12 == ((uint8)1U)) && (rtb_DataTypeConversion15 ==
      ((uint8)2U)) && (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S76>/turnON_delay1' */
    /* Chart: '<S84>/timed_delay' incorporates:
     *  Constant: '<S76>/Constant49'
     *  DataTypeConversion: '<S84>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__e == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__e = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstSpdLmtLvl3En = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstSpdLmtLvl3En = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstSpdLmtLvl3En = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_n = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_n += 0.01F;
            ovgl_dtld_b_dstSpdLmtLvl3En = false;
          }
        } else {
          ovgl_dtld_b_dstSpdLmtLvl3En = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl3En = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl3En = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl3En = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_n > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_hw = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstSpdLmtLvl3En = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_n += 0.01F;
          ovgl_dtld_b_dstSpdLmtLvl3En = false;
        }
        break;
      }
    }

    /* End of Chart: '<S84>/timed_delay' */
    /* End of Outputs for SubSystem: '<S76>/turnON_delay1' */

    /* Logic: '<S10>/Logical Operator5' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S10>/Constant3'
     *  Constant: '<S10>/Constant4'
     *  Constant: '<S10>/Level4'
     *  Constant: '<S10>/Level5'
     *  Logic: '<S10>/Logical Operator3'
     *  Logic: '<S10>/Logical Operator6'
     *  Logic: '<S10>/Logical Operator7'
     *  RelationalOperator: '<S10>/Relational Operator15'
     *  RelationalOperator: '<S10>/Relational Operator16'
     *  RelationalOperator: '<S10>/Relational Operator17'
     *  RelationalOperator: '<S10>/Relational Operator18'
     *  RelationalOperator: '<S10>/Relational Operator3'
     */
    rtb_DataTypeConversion8_o = (((ovgl_dtld_b_dstLckVehVerExc == false) ||
      (rtb_DataTypeConversion12 == ((uint8)0U)) || ((rtb_DataTypeConversion15 !=
      ((uint8)0U)) && (rtb_DataTypeConversion15 != ((uint8)3U)) &&
      (ovgl_dtld_b_dstSpdLmtLvl2En || ovgl_dtld_b_dstSpdLmtLvl3En ||
       ovgl_dtld_b_dstInvtryLckEn))) && (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S77>/turnON_delay1' */
    /* Chart: '<S86>/timed_delay' incorporates:
     *  Constant: '<S77>/Constant49'
     *  DataTypeConversion: '<S86>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__g == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__g = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstSpdLmtLvl1Dis = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstSpdLmtLvl1Dis = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_e_tmp == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstSpdLmtLvl1Dis = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_h = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_h += 0.01F;
            ovgl_dtld_b_dstSpdLmtLvl1Dis = false;
          }
        } else {
          ovgl_dtld_b_dstSpdLmtLvl1Dis = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl1Dis = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl1Dis = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl1Dis = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_h > rtb_t_delay_on_e_tmp - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_ps = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstSpdLmtLvl1Dis = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_h += 0.01F;
          ovgl_dtld_b_dstSpdLmtLvl1Dis = false;
        }
        break;
      }
    }

    /* End of Chart: '<S86>/timed_delay' */
    /* End of Outputs for SubSystem: '<S77>/turnON_delay1' */

    /* Chart: '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' incorporates:
     *  RelationalOperator: '<S71>/FixPt Relational Operator'
     *  UnitDelay: '<S71>/Delay Input1'
     *
     * Block description for '<S71>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (swc_OGVL_ARID_DEF.is_active_c16_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c16_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_WakeUp;
      ovgl_dtld_b_dstSpdLmtLvl1Write = rtb_DataTypeConversion9_kq;
      ovgl_dtld_b_dstSpdLmtLvl1Exc = rtb_DataTypeConversion9_kq;
    } else {
      switch (swc_OGVL_ARID_DEF.is_c16_swc_OGVL) {
       case swc_OGVL_IN_DisEnable:
        if (ovgl_dtld_b_dstSpdLmtLvl1En) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstSpdLmtLvl1Write = true;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = true;
        } else if (!rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_DisEnableLatch_i;
        }
        break;

       case swc_OGVL_IN_DisEnableExecute:
        if (ovgl_dtld_b_dstSpdLmtLvl1En) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstSpdLmtLvl1Write = true;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = true;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch_i:
        if (rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_DisEnableExecute;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = false;
        } else if ((sint32)rtb_DataTypeConversion23 > (sint32)
                   swc_OGVL_ARID_DEF.DelayInput1_DSTATE) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl1Write = false;
        }
        break;

       case swc_OGVL_IN_EnableExecute_eu:
        if (ovgl_dtld_b_dstSpdLmtLvl1Dis) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl1Write = false;
        }
        break;

       case swc_OGVL_IN_TboxLost:
        if (ovgl_dtld_b_dstSpdLmtLvl1En) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstSpdLmtLvl1Write = true;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl1Dis) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl1Write = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl1Write = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = rtb_DataTypeConversion9_kq;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstSpdLmtLvl1En) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstSpdLmtLvl1Write = true;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl1Dis) {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl1Write = false;
        } else {
          swc_OGVL_ARID_DEF.is_c16_swc_OGVL = swc_OGVL_IN_TboxLost;
          ovgl_dtld_b_dstSpdLmtLvl1Write = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstSpdLmtLvl1Exc = rtb_DataTypeConversion9_kq;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */

    /* RelationalOperator: '<S10>/Relational Operator31' incorporates:
     *  Constant: '<S10>/Constant19'
     */
    rtb_DataTypeConversion9_kq = (rtb_Add1 == ((uint8)2U));

    /* Logic: '<S10>/Logical Operator8' incorporates:
     *  Constant: '<S10>/Constant10'
     *  Constant: '<S10>/Constant6'
     *  Constant: '<S10>/Constant9'
     *  Constant: '<S10>/Level6'
     *  Constant: '<S10>/Level7'
     *  Logic: '<S10>/Logical Operator14'
     *  Logic: '<S10>/Logical Operator15'
     *  Logic: '<S10>/Logical Operator9'
     *  RelationalOperator: '<S10>/Relational Operator20'
     *  RelationalOperator: '<S10>/Relational Operator21'
     *  RelationalOperator: '<S10>/Relational Operator22'
     *  RelationalOperator: '<S10>/Relational Operator23'
     *  RelationalOperator: '<S10>/Relational Operator24'
     */
    rtb_DataTypeConversion8_o = (((ovgl_dtld_b_dstLckVehVerExc == false) ||
      (rtb_DataTypeConversion12 == ((uint8)0U)) || ((rtb_DataTypeConversion15 !=
      ((uint8)1U)) && (rtb_DataTypeConversion15 != ((uint8)3U)) &&
      (ovgl_dtld_b_dstSpdLmtLvl1En || ovgl_dtld_b_dstSpdLmtLvl3En ||
       ovgl_dtld_b_dstInvtryLckEn))) && (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S79>/turnON_delay1' */
    /* Chart: '<S90>/timed_delay' incorporates:
     *  Constant: '<S79>/Constant49'
     *  DataTypeConversion: '<S90>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_og == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_og = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstSpdLmtLvl2Dis = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstSpdLmtLvl2Dis = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_e_tmp == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstSpdLmtLvl2Dis = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_ly = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_ly += 0.01F;
            ovgl_dtld_b_dstSpdLmtLvl2Dis = false;
          }
        } else {
          ovgl_dtld_b_dstSpdLmtLvl2Dis = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl2Dis = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl2Dis = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl2Dis = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_ly > rtb_t_delay_on_e_tmp - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_p = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstSpdLmtLvl2Dis = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_ly += 0.01F;
          ovgl_dtld_b_dstSpdLmtLvl2Dis = false;
        }
        break;
      }
    }

    /* End of Chart: '<S90>/timed_delay' */
    /* End of Outputs for SubSystem: '<S79>/turnON_delay1' */

    /* Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
    if (swc_OGVL_ARID_DEF.is_active_c17_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c17_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_WakeUp_i;
      ovgl_dtld_b_dstSpdLmtLvl2Write = rtb_DataTypeConversion9_kq;
      ovgl_dtld_b_dstSpdLmtLvl2Exc = rtb_DataTypeConversion9_kq;
    } else {
      switch (swc_OGVL_ARID_DEF.is_c17_swc_OGVL) {
       case swc_OGVL_IN_DisEnableExecute_f:
        if (ovgl_dtld_b_dstSpdLmtLvl2En) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl2Write = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl2Dis) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl2Write = false;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch:
        if (rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_DisEnableExecute_f;
          ovgl_dtld_b_dstSpdLmtLvl2Exc = ovgl_dtld_b_dstSpdLmtLvl2Write;
        } else if (ovgl_dtld_b_dstSpdLmtLvl2Dis && rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl2Write = false;
        } else if (ovgl_dtld_b_dstSpdLmtLvl2En && rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl2Write = true;
        }
        break;

       case swc_OGVL_IN_Key_On:
        if ((!rtb_flg_out) && (!rtb_DataTypeConversion23)) {
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_NO_ACTIVE_CHILD;
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_DisEnableLatch;
        } else if (swc_OGVL_ARID_DEF.is_Key_On_o == swc_OGVL_IN_DisEnable) {
          if (ovgl_dtld_b_dstSpdLmtLvl2En) {
            swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_EnableExecute_e;
            ovgl_dtld_b_dstSpdLmtLvl2Write = true;
          }

          /* case IN_EnableExecute: */
        } else if (ovgl_dtld_b_dstSpdLmtLvl2Dis) {
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl2Write = false;
        }
        break;

       case swc_OGVL_IN_TboxLost_k:
        if (ovgl_dtld_b_dstSpdLmtLvl2En) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl2Write = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl2Dis) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl2Write = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl2Write = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstSpdLmtLvl2Exc = rtb_DataTypeConversion9_kq;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstSpdLmtLvl2En) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl2Write = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl2Dis) {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On_o = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl2Write = false;
        } else {
          swc_OGVL_ARID_DEF.is_c17_swc_OGVL = swc_OGVL_IN_TboxLost_k;
          ovgl_dtld_b_dstSpdLmtLvl2Write = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstSpdLmtLvl2Exc = rtb_DataTypeConversion9_kq;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */

    /* RelationalOperator: '<S10>/Relational Operator32' incorporates:
     *  Constant: '<S10>/Constant20'
     */
    rtb_DataTypeConversion9_kq = (rtb_Add1 == ((uint8)3U));

    /* Logic: '<S10>/Logical Operator12' incorporates:
     *  Constant: '<S10>/Constant14'
     *  Constant: '<S10>/Constant16'
     *  Constant: '<S10>/Constant18'
     *  Constant: '<S10>/Level3'
     *  Constant: '<S10>/Level9'
     *  Logic: '<S10>/Logical Operator10'
     *  Logic: '<S10>/Logical Operator13'
     *  Logic: '<S10>/Logical Operator16'
     *  RelationalOperator: '<S10>/Relational Operator12'
     *  RelationalOperator: '<S10>/Relational Operator13'
     *  RelationalOperator: '<S10>/Relational Operator14'
     *  RelationalOperator: '<S10>/Relational Operator29'
     *  RelationalOperator: '<S10>/Relational Operator30'
     */
    rtb_DataTypeConversion8_o = (((ovgl_dtld_b_dstLckVehVerExc == false) ||
      (rtb_DataTypeConversion12 == ((uint8)0U)) || ((rtb_DataTypeConversion15 !=
      ((uint8)2U)) && (rtb_DataTypeConversion15 != ((uint8)3U)) &&
      (ovgl_dtld_b_dstSpdLmtLvl1En || ovgl_dtld_b_dstSpdLmtLvl2En ||
       ovgl_dtld_b_dstInvtryLckEn))) && (rtb_DataTypeConversion21 <= 3.0F));

    /* Outputs for Atomic SubSystem: '<S80>/turnON_delay1' */
    /* Chart: '<S92>/timed_delay' incorporates:
     *  Constant: '<S80>/Constant49'
     *  DataTypeConversion: '<S92>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__o == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__o = 1U;
      if (rtb_DataTypeConversion8_o) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstSpdLmtLvl3Dis = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstSpdLmtLvl3Dis = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion8_o) {
          if (rtb_t_delay_on_e_tmp == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstSpdLmtLvl3Dis = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_ku = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_ku += 0.01F;
            ovgl_dtld_b_dstSpdLmtLvl3Dis = false;
          }
        } else {
          ovgl_dtld_b_dstSpdLmtLvl3Dis = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl3Dis = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl3Dis = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion8_o) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstSpdLmtLvl3Dis = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_ku > rtb_t_delay_on_e_tmp - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_l = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstSpdLmtLvl3Dis = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_ku += 0.01F;
          ovgl_dtld_b_dstSpdLmtLvl3Dis = false;
        }
        break;
      }
    }

    /* End of Chart: '<S92>/timed_delay' */
    /* End of Outputs for SubSystem: '<S80>/turnON_delay1' */

    /* Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
    if (swc_OGVL_ARID_DEF.is_active_c19_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c19_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_WakeUp_i;
      ovgl_dtld_b_dstSpdLmtLvl3Write = rtb_DataTypeConversion9_kq;
      ovgl_dtld_b_dstSpdLmtLvl3Exc = rtb_DataTypeConversion9_kq;
    } else {
      switch (swc_OGVL_ARID_DEF.is_c19_swc_OGVL) {
       case swc_OGVL_IN_DisEnableExecute_f:
        if (ovgl_dtld_b_dstSpdLmtLvl3En) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl3Write = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl3Dis) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl3Write = false;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch:
        if (rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_DisEnableExecute_f;
          ovgl_dtld_b_dstSpdLmtLvl3Exc = ovgl_dtld_b_dstSpdLmtLvl3Write;
        } else if (ovgl_dtld_b_dstSpdLmtLvl3Dis && rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl3Write = false;
        } else if (ovgl_dtld_b_dstSpdLmtLvl3En && rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl3Write = true;
        }
        break;

       case swc_OGVL_IN_Key_On:
        if ((!rtb_flg_out) && (!rtb_DataTypeConversion23)) {
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_NO_ACTIVE_CHILD;
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_DisEnableLatch;
        } else if (swc_OGVL_ARID_DEF.is_Key_On == swc_OGVL_IN_DisEnable) {
          if (ovgl_dtld_b_dstSpdLmtLvl3En) {
            swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_EnableExecute_e;
            ovgl_dtld_b_dstSpdLmtLvl3Write = true;
          }

          /* case IN_EnableExecute: */
        } else if (ovgl_dtld_b_dstSpdLmtLvl3Dis) {
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl3Write = false;
        }
        break;

       case swc_OGVL_IN_TboxLost_k:
        if (ovgl_dtld_b_dstSpdLmtLvl3En) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl3Write = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl3Dis) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl3Write = false;
        } else {
          ovgl_dtld_b_dstSpdLmtLvl3Write = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstSpdLmtLvl3Exc = rtb_DataTypeConversion9_kq;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstSpdLmtLvl3En) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_EnableExecute_e;
          ovgl_dtld_b_dstSpdLmtLvl3Write = true;
        } else if (ovgl_dtld_b_dstSpdLmtLvl3Dis) {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_Key_On;
          swc_OGVL_ARID_DEF.is_Key_On = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstSpdLmtLvl3Write = false;
        } else {
          swc_OGVL_ARID_DEF.is_c19_swc_OGVL = swc_OGVL_IN_TboxLost_k;
          ovgl_dtld_b_dstSpdLmtLvl3Write = rtb_DataTypeConversion9_kq;
          ovgl_dtld_b_dstSpdLmtLvl3Exc = rtb_DataTypeConversion9_kq;
        }
        break;
      }
    }

    /* End of Chart: '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */

    /* Switch: '<S10>/Switch4' incorporates:
     *  Switch: '<S10>/Switch5'
     *  Switch: '<S10>/Switch6'
     */
    if (ovgl_dtld_b_dstSpdLmtLvl1Write) {
      /* Switch: '<S10>/Switch4' incorporates:
       *  Constant: '<S10>/LmtLevel1'
       */
      ovgl_dtld_st_dstSpdLmtLvlWrite = ((uint8)1U);
    } else if (ovgl_dtld_b_dstSpdLmtLvl2Write) {
      /* Switch: '<S10>/Switch5' incorporates:
       *  Constant: '<S10>/LmtLevel2'
       *  Switch: '<S10>/Switch4'
       */
      ovgl_dtld_st_dstSpdLmtLvlWrite = ((uint8)2U);
    } else if (ovgl_dtld_b_dstSpdLmtLvl3Write) {
      /* Switch: '<S10>/Switch6' incorporates:
       *  Constant: '<S10>/LmtLevel3'
       *  Switch: '<S10>/Switch4'
       *  Switch: '<S10>/Switch5'
       */
      ovgl_dtld_st_dstSpdLmtLvlWrite = ((uint8)3U);
    } else {
      /* Switch: '<S10>/Switch4' incorporates:
       *  Constant: '<S10>/NoLmtLevel'
       *  Switch: '<S10>/Switch5'
       *  Switch: '<S10>/Switch6'
       */
      ovgl_dtld_st_dstSpdLmtLvlWrite = ((uint8)0U);
    }

    /* End of Switch: '<S10>/Switch4' */

    /* RelationalOperator: '<S7>/Relational Operator15' incorporates:
     *  Delay: '<S7>/Delay'
     */
    rtb_RelationalOperator15_n = (rtb_DataTypeConversion16 ==
      swc_OGVL_ARID_DEF.Delay_DSTATE[0]);

    /* Outputs for Atomic SubSystem: '<S7>/turnON_delay4' */
    rtb_flg_out_g = swc_OGVL_turnON_delay3(rtb_RelationalOperator15_n, 0.9F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay4);

    /* End of Outputs for SubSystem: '<S7>/turnON_delay4' */

    /* RelationalOperator: '<S22>/Relational Operator' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Constant: '<S7>/Constant7'
     *  Logic: '<S7>/Logical Operator'
     */
    rtb_DataTypeConversion7_g = !rtb_flg_out_g;

    /* Logic: '<S7>/Logical Operator1' incorporates:
     *  Constant: '<S7>/Constant15'
     *  Constant: '<S7>/Constant17'
     *  Constant: '<S7>/Constant8'
     *  RelationalOperator: '<S7>/Relational Operator6'
     *  RelationalOperator: '<S7>/Relational Operator7'
     *  RelationalOperator: '<S7>/Relational Operator8'
     */
    rtb_DataTypeConversion9_kq = ((ovgl_dtld_b_dstLckVehVerExc == true) &&
      (rtb_DataTypeConversion20 == ((uint8)1U)) && (rtb_DataTypeConversion7_g ==
      true));

    /* Outputs for Atomic SubSystem: '<S7>/turnON_delay2' */
    /* Chart: '<S66>/timed_delay' incorporates:
     *  Constant: '<S7>/Constant11'
     *  DataTypeConversion: '<S66>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__b == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev__b = 1U;
      if (rtb_DataTypeConversion9_kq) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstPwrOffOn = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstPwrOffOn = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion9_kq) {
          if (rtb_t_delay_on_kf == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstPwrOffOn = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_b = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_b += 0.01F;
            ovgl_dtld_b_dstPwrOffOn = false;
          }
        } else {
          ovgl_dtld_b_dstPwrOffOn = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion9_kq) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstPwrOffOn = false;
        } else {
          ovgl_dtld_b_dstPwrOffOn = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion9_kq) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstPwrOffOn = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_b > rtb_t_delay_on_kf - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_n = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstPwrOffOn = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_b += 0.01F;
          ovgl_dtld_b_dstPwrOffOn = false;
        }
        break;
      }
    }

    /* End of Chart: '<S66>/timed_delay' */
    /* End of Outputs for SubSystem: '<S7>/turnON_delay2' */

    /* Logic: '<S7>/Logical Operator2' incorporates:
     *  Constant: '<S7>/Constant12'
     *  Constant: '<S7>/Constant3'
     *  Constant: '<S7>/Constant4'
     *  Constant: '<S7>/Constant6'
     *  Logic: '<S7>/Logical Operator4'
     *  RelationalOperator: '<S7>/Relational Operator2'
     *  RelationalOperator: '<S7>/Relational Operator3'
     *  RelationalOperator: '<S7>/Relational Operator5'
     *  RelationalOperator: '<S7>/Relational Operator9'
     */
    rtb_DataTypeConversion9_kq = (((ovgl_dtld_b_dstLckVehVerExc == false) ||
      (rtb_DataTypeConversion20 == ((uint8)0U))) && (rtb_DataTypeConversion21 <=
      3.0F) && (rtb_DataTypeConversion7_g == true));

    /* Outputs for Atomic SubSystem: '<S7>/turnON_delay1' */
    /* Chart: '<S65>/timed_delay' incorporates:
     *  Constant: '<S7>/Constant9'
     *  DataTypeConversion: '<S65>/Data Type Conversion'
     */
    if (swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_ci == 0U) {
      swc_OGVL_ARID_DEF.is_active_c14_Ricardo_SW_dev_ci = 1U;
      if (rtb_DataTypeConversion9_kq) {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 = swc_OGVL_IN_ON_l;
        ovgl_dtld_b_dstPwrOffDis = true;
      } else {
        swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 = swc_OGVL_IN_OFF_g;
        ovgl_dtld_b_dstPwrOffDis = false;
      }
    } else {
      switch (swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1) {
       case swc_OGVL_IN_OFF_g:
        if (rtb_DataTypeConversion9_kq) {
          if (rtb_t_delay_on_e_tmp == 0.0F) {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 = swc_OGVL_IN_ON_l;
            ovgl_dtld_b_dstPwrOffDis = true;
          } else {
            swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 =
              swc_OGVL_IN_ON_WAIT_g;
            swc_OGVL_ARID_DEF.t_wait_o = 0.0F;
            swc_OGVL_ARID_DEF.t_wait_o += 0.01F;
            ovgl_dtld_b_dstPwrOffDis = false;
          }
        } else {
          ovgl_dtld_b_dstPwrOffDis = false;
        }
        break;

       case swc_OGVL_IN_ON_l:
        if (!rtb_DataTypeConversion9_kq) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstPwrOffDis = false;
        } else {
          ovgl_dtld_b_dstPwrOffDis = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_DataTypeConversion9_kq) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 = swc_OGVL_IN_OFF_g;
          ovgl_dtld_b_dstPwrOffDis = false;
        } else if (swc_OGVL_ARID_DEF.t_wait_o > rtb_t_delay_on_e_tmp - 0.01F) {
          swc_OGVL_ARID_DEF.is_c14_Ricardo_SW_dev_lib_h1 = swc_OGVL_IN_ON_l;
          ovgl_dtld_b_dstPwrOffDis = true;
        } else {
          swc_OGVL_ARID_DEF.t_wait_o += 0.01F;
          ovgl_dtld_b_dstPwrOffDis = false;
        }
        break;
      }
    }

    /* End of Chart: '<S65>/timed_delay' */
    /* End of Outputs for SubSystem: '<S7>/turnON_delay1' */

    /* Chart: '<S7>/En_Immediately_Dis_NextKeyOn' */
    if (swc_OGVL_ARID_DEF.is_active_c15_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c15_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_WakeUp;
      ovgl_dtld_b_dstPwrOffWrite = rtb_DataTypeConversion12_a;
      ovgl_dtld_b_dstPwrOffExc = rtb_DataTypeConversion12_a;
    } else {
      switch (swc_OGVL_ARID_DEF.is_c15_swc_OGVL) {
       case swc_OGVL_IN_DisEnable:
        if (ovgl_dtld_b_dstPwrOffOn) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstPwrOffWrite = true;
          ovgl_dtld_b_dstPwrOffExc = true;
        } else if (!rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_DisEnableLatch_i;
        }
        break;

       case swc_OGVL_IN_DisEnableExecute:
        if (ovgl_dtld_b_dstPwrOffOn) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstPwrOffWrite = true;
          ovgl_dtld_b_dstPwrOffExc = true;
        }
        break;

       case swc_OGVL_IN_DisEnableLatch_i:
        if (rtb_flg_out) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_DisEnableExecute;
          ovgl_dtld_b_dstPwrOffExc = false;
        } else if (rtb_DataTypeConversion23) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstPwrOffWrite = false;
        }
        break;

       case swc_OGVL_IN_EnableExecute_eu:
        if (ovgl_dtld_b_dstPwrOffDis) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstPwrOffWrite = false;
        }
        break;

       case swc_OGVL_IN_TboxLost:
        if (ovgl_dtld_b_dstPwrOffOn) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstPwrOffWrite = true;
          ovgl_dtld_b_dstPwrOffExc = true;
        } else if (ovgl_dtld_b_dstPwrOffDis) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstPwrOffWrite = false;
        } else {
          ovgl_dtld_b_dstPwrOffWrite = rtb_DataTypeConversion12_a;
          ovgl_dtld_b_dstPwrOffExc = rtb_DataTypeConversion12_a;
        }
        break;

       default:
        /* case IN_WakeUp: */
        if (ovgl_dtld_b_dstPwrOffOn) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_EnableExecute_eu;
          ovgl_dtld_b_dstPwrOffWrite = true;
          ovgl_dtld_b_dstPwrOffExc = true;
        } else if (ovgl_dtld_b_dstPwrOffDis) {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_DisEnable;
          ovgl_dtld_b_dstPwrOffWrite = false;
        } else {
          swc_OGVL_ARID_DEF.is_c15_swc_OGVL = swc_OGVL_IN_TboxLost;
          ovgl_dtld_b_dstPwrOffWrite = rtb_DataTypeConversion12_a;
          ovgl_dtld_b_dstPwrOffExc = rtb_DataTypeConversion12_a;
        }
        break;
      }
    }

    /* End of Chart: '<S7>/En_Immediately_Dis_NextKeyOn' */

    /* Outputs for Atomic SubSystem: '<S2>/WriteToNVM' */
    /* Sum: '<S117>/Add' incorporates:
     *  Constant: '<S112>/Constant'
     *  Sum: '<S112>/Add'
     *  UnitDelay: '<S112>/Unit Delay'
     */
    rtb_Add = 1.0 + swc_OGVL_ARID_DEF.UnitDelay_DSTATE;

    /* Switch: '<S112>/Switch' incorporates:
     *  RelationalOperator: '<S112>/Relational Operator'
     */
    if (rtb_Add > swc_OGVL_ConstB.Divide) {
      /* Switch: '<S112>/Switch' incorporates:
       *  Constant: '<S112>/Constant4'
       */
      rtb_Switch = 1.0;
    } else {
      /* Switch: '<S112>/Switch' */
      rtb_Switch = rtb_Add;
    }

    /* End of Switch: '<S112>/Switch' */

    /* Switch: '<S119>/Switch2' incorporates:
     *  Constant: '<S101>/dtlc_b_nvmWriteDSTNOSC_ovrdflg'
     */
    if (ogvl_dtlc_b_nvmWriteDSTNOSC_ovrdflg) {
      /* Switch: '<S119>/Switch2' incorporates:
       *  Constant: '<S101>/dtlc_st_nvmWriteDSTNOSC_ovrdval'
       */
      ovgl_dtld_st_nvmWriteDSTNOSC = ogvl_dtlc_st_nvmWriteDSTNOSC_ovrdval;
    } else {
      /* Switch: '<S119>/Switch2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion5'
       */
      ovgl_dtld_st_nvmWriteDSTNOSC = (uint8)ovgl_dtld_b_dstLckVehVerWrite;
    }

    /* End of Switch: '<S119>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S112>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S148>/Enable'
     */
    if (rtb_Switch == swc_OGVL_ConstB.Divide) {
      /* S-Function (fcgen): '<S148>/Function-Call Generator' incorporates:
       *  SubSystem: '<S11>/Subsystem10'
       */
      /* SignalConversion: '<S106>/Signal Conversion' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       */
      ovgl_dtld_st_nvmWriteDstNosc_1s = ovgl_dtld_st_nvmWriteDSTNOSC;

      /* RelationalOperator: '<S106>/Relational Operator1' incorporates:
       *  UnitDelay: '<S106>/Unit Delay7'
       */
      rtb_RelationalOperator1_h = (ovgl_dtld_st_nvmWriteDstNosc_1s !=
        swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_k2);

      /* CCaller: '<S106>/mBSW_NvmRead_DSTNOSC_retval1' */
      ovgl_dtld_st_nvmWriteDstnoscReturnVal = mBSW_NvmRead_DSTNOSC_retval();

      /* RelationalOperator: '<S106>/Relational Operator6' incorporates:
       *  Constant: '<S106>/Constant'
       */
      rtb_DataTypeConversion12_a = (ovgl_dtld_st_nvmWriteDstnoscReturnVal !=
        ((uint8)0U));

      /* RelationalOperator: '<S125>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S106>/Data Type Conversion5'
       *  UnitDelay: '<S125>/Delay Input1'
       *
       * Block description for '<S125>/Delay Input1':
       *
       *  Store in Global RAM
       */
      ovgl_dtld_st_nvmWriteDstNoscRset = ((sint32)rtb_DataTypeConversion12_a <
        (sint32)swc_OGVL_ARID_DEF.DelayInput1_DSTATE_b);

      /* Outputs for Atomic SubSystem: '<S106>/SR_latch' */
      swc_OGVL_SR_latch(rtb_RelationalOperator1_h,
                        ovgl_dtld_st_nvmWriteDstNoscRset,
                        &rtb_LogicalOperator3_f,
                        &swc_OGVL_ARID_DEF.ARID_DEF_SR_latch_g);

      /* End of Outputs for SubSystem: '<S106>/SR_latch' */

      /* SignalConversion generated from: '<S106>/SR_latch' */
      ovgl_dtld_st_nvmWriteDstNoscEnbl = rtb_LogicalOperator3_f;

      /* Outputs for Enabled SubSystem: '<S106>/mBSW_NvmWrite_DSTNOSC_eep' incorporates:
       *  EnablePort: '<S127>/Enable'
       */
      if (ovgl_dtld_st_nvmWriteDstNoscEnbl) {
        /* CCaller: '<S127>/C Caller1' */
        mBSW_NvmWrite_DSTNOSC_eep(ovgl_dtld_st_nvmWriteDstNosc_1s);
      }

      /* End of Outputs for SubSystem: '<S106>/mBSW_NvmWrite_DSTNOSC_eep' */

      /* Outputs for Atomic SubSystem: '<S106>/Counter' */
      swc_OGVL_Counter(((uint8)1U), ((uint8)0U),
                       ovgl_dtld_st_nvmWriteDstNoscEnbl, &rtb_Sum6_k,
                       &swc_OGVL_ARID_DEF.ARID_DEF_Counter_g);

      /* End of Outputs for SubSystem: '<S106>/Counter' */

      /* SignalConversion generated from: '<S106>/Counter' incorporates:
       *  Constant: '<S106>/Constant1'
       *  Constant: '<S106>/Constant2'
       */
      ovgl_dtld_st_nvmWriteDstNoscCnt = rtb_Sum6_k;

      /* Update for UnitDelay: '<S106>/Unit Delay7' */
      swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_k2 = ovgl_dtld_st_nvmWriteDstNosc_1s;

      /* Update for UnitDelay: '<S125>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S106>/Data Type Conversion5'
       *
       * Block description for '<S125>/Delay Input1':
       *
       *  Store in Global RAM
       */
      swc_OGVL_ARID_DEF.DelayInput1_DSTATE_b = rtb_DataTypeConversion12_a;

      /* End of Outputs for S-Function (fcgen): '<S148>/Function-Call Generator' */
    }

    /* End of Outputs for SubSystem: '<S112>/Enabled Subsystem' */

    /* Sum: '<S117>/Add' incorporates:
     *  Constant: '<S106>/Constant1'
     *  Constant: '<S106>/Constant2'
     *  Constant: '<S113>/Constant'
     *  RelationalOperator: '<S112>/Relational Operator1'
     *  Sum: '<S113>/Add'
     *  UnitDelay: '<S113>/Unit Delay'
     */
    rtb_Add = 1.0 + swc_OGVL_ARID_DEF.UnitDelay_DSTATE_g;

    /* Switch: '<S113>/Switch' incorporates:
     *  RelationalOperator: '<S113>/Relational Operator'
     */
    if (rtb_Add > swc_OGVL_ConstB.Divide_k) {
      /* Switch: '<S113>/Switch' incorporates:
       *  Constant: '<S113>/Constant4'
       */
      rtb_Switch_b = 1.0;
    } else {
      /* Switch: '<S113>/Switch' */
      rtb_Switch_b = rtb_Add;
    }

    /* End of Switch: '<S113>/Switch' */

    /* Switch: '<S118>/Switch2' incorporates:
     *  Constant: '<S100>/dtlc_b_nvmWriteAntiDismtLckReq_ovrdflg'
     */
    if (ogvl_dtlc_b_nvmWriteAntiDismtLckReq_ovrdflg) {
      /* Switch: '<S118>/Switch2' incorporates:
       *  Constant: '<S100>/dtlc_st_nvmWriteAntiDismtLckReq_ovrdval'
       */
      ovgl_dtld_st_nvmWriteAntiDismtLckReq =
        ogvl_dtlc_st_nvmWriteAntiDismtLckReq_ovrdval;
    } else {
      /* Switch: '<S118>/Switch2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion4'
       */
      ovgl_dtld_st_nvmWriteAntiDismtLckReq = (uint8)swc_OGVL_ARID_DEF.cmdWrite_i;
    }

    /* End of Switch: '<S118>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S113>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S149>/Enable'
     */
    if (rtb_Switch_b == swc_OGVL_ConstB.Divide_k) {
      /* S-Function (fcgen): '<S149>/Function-Call Generator' incorporates:
       *  SubSystem: '<S11>/Subsystem11'
       */
      /* SignalConversion: '<S107>/Signal Conversion' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion7'
       */
      ovgl_dtld_st_nvmWriteDismantleCmd_1s =
        ovgl_dtld_st_nvmWriteAntiDismtLckReq;

      /* RelationalOperator: '<S107>/Relational Operator1' incorporates:
       *  UnitDelay: '<S107>/Unit Delay7'
       */
      rtb_RelationalOperator1_b = (ovgl_dtld_st_nvmWriteDismantleCmd_1s !=
        swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_ox);

      /* CCaller: '<S107>/mBSW_NvmRead_DSTNOSC_retval1' */
      ovgl_dtld_st_nvmWriteDismantleCmdReturnVal =
        mBSW_NvmRead_DismantleCmd_eep_retval();

      /* RelationalOperator: '<S107>/Relational Operator6' incorporates:
       *  Constant: '<S107>/Constant'
       */
      rtb_DataTypeConversion12_a = (ovgl_dtld_st_nvmWriteDismantleCmdReturnVal
        != ((uint8)0U));

      /* RelationalOperator: '<S129>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S107>/Data Type Conversion5'
       *  UnitDelay: '<S129>/Delay Input1'
       *
       * Block description for '<S129>/Delay Input1':
       *
       *  Store in Global RAM
       */
      ovgl_dtld_st_nvmWriteDismantleCmdRset = ((sint32)
        rtb_DataTypeConversion12_a < (sint32)
        swc_OGVL_ARID_DEF.DelayInput1_DSTATE_lx);

      /* Outputs for Atomic SubSystem: '<S107>/SR_latch' */
      swc_OGVL_SR_latch(rtb_RelationalOperator1_b,
                        ovgl_dtld_st_nvmWriteDismantleCmdRset,
                        &rtb_LogicalOperator3_dl,
                        &swc_OGVL_ARID_DEF.ARID_DEF_SR_latch_c);

      /* End of Outputs for SubSystem: '<S107>/SR_latch' */

      /* SignalConversion generated from: '<S107>/SR_latch' */
      ovgl_dtld_st_nvmWriteDismantleCmdEnbl = rtb_LogicalOperator3_dl;

      /* Outputs for Enabled SubSystem: '<S107>/mBSW_NvmWrite_dstAntiDismtLckReq' incorporates:
       *  EnablePort: '<S131>/Enable'
       */
      if (ovgl_dtld_st_nvmWriteDismantleCmdEnbl) {
        /* CCaller: '<S131>/C Caller2' */
        mBSW_NvmWrite_DismantleCmd_eep(ovgl_dtld_st_nvmWriteDismantleCmd_1s);
      }

      /* End of Outputs for SubSystem: '<S107>/mBSW_NvmWrite_dstAntiDismtLckReq' */

      /* Outputs for Atomic SubSystem: '<S107>/Counter' */
      swc_OGVL_Counter(((uint8)1U), ((uint8)0U),
                       ovgl_dtld_st_nvmWriteDismantleCmdEnbl, &rtb_Sum6_e,
                       &swc_OGVL_ARID_DEF.ARID_DEF_Counter_f);

      /* End of Outputs for SubSystem: '<S107>/Counter' */

      /* SignalConversion generated from: '<S107>/Counter' incorporates:
       *  Constant: '<S107>/Constant1'
       *  Constant: '<S107>/Constant2'
       */
      ovgl_dtld_st_nvmWriteDismantleCmdCnt = rtb_Sum6_e;

      /* Update for UnitDelay: '<S107>/Unit Delay7' */
      swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_ox =
        ovgl_dtld_st_nvmWriteDismantleCmd_1s;

      /* Update for UnitDelay: '<S129>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S107>/Data Type Conversion5'
       *
       * Block description for '<S129>/Delay Input1':
       *
       *  Store in Global RAM
       */
      swc_OGVL_ARID_DEF.DelayInput1_DSTATE_lx = rtb_DataTypeConversion12_a;

      /* End of Outputs for S-Function (fcgen): '<S149>/Function-Call Generator' */
    }

    /* End of Outputs for SubSystem: '<S113>/Enabled Subsystem' */

    /* Sum: '<S117>/Add' incorporates:
     *  Constant: '<S107>/Constant1'
     *  Constant: '<S107>/Constant2'
     *  Constant: '<S114>/Constant'
     *  RelationalOperator: '<S113>/Relational Operator1'
     *  Sum: '<S114>/Add'
     *  UnitDelay: '<S114>/Unit Delay'
     */
    rtb_Add = 1.0 + swc_OGVL_ARID_DEF.UnitDelay_DSTATE_l;

    /* Switch: '<S114>/Switch' incorporates:
     *  RelationalOperator: '<S114>/Relational Operator'
     */
    if (rtb_Add > swc_OGVL_ConstB.Divide_n) {
      /* Switch: '<S114>/Switch' incorporates:
       *  Constant: '<S114>/Constant4'
       */
      rtb_Switch_p = 1.0;
    } else {
      /* Switch: '<S114>/Switch' */
      rtb_Switch_p = rtb_Add;
    }

    /* End of Switch: '<S114>/Switch' */

    /* Switch: '<S120>/Switch2' incorporates:
     *  Constant: '<S102>/ogvl_dtlc_b_nvmWriteInvtryLck_ovrdflg'
     */
    if (ogvl_dtlc_b_nvmWriteInvtryLck_ovrdflg) {
      /* Switch: '<S120>/Switch2' incorporates:
       *  Constant: '<S102>/ogvl_dtlc_st_nvmWriteInvtryLck_ovrdval'
       */
      ovgl_dtld_st_nvmWriteInvtryLck = ogvl_dtlc_st_nvmWriteInvtryLck_ovrdval;
    } else {
      /* Switch: '<S120>/Switch2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion3'
       */
      ovgl_dtld_st_nvmWriteInvtryLck = (uint8)ovgl_dtld_b_dstInvtryLckWrite;
    }

    /* End of Switch: '<S120>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S114>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S150>/Enable'
     */
    if (rtb_Switch_p == swc_OGVL_ConstB.Divide_n) {
      /* S-Function (fcgen): '<S150>/Function-Call Generator' incorporates:
       *  SubSystem: '<S11>/Subsystem12'
       */
      /* SignalConversion: '<S108>/Signal Conversion' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion8'
       */
      ovgl_dtld_st_nvmWriteDstLckVehTypeCmd_1s = ovgl_dtld_st_nvmWriteInvtryLck;

      /* RelationalOperator: '<S108>/Relational Operator1' incorporates:
       *  UnitDelay: '<S108>/Unit Delay7'
       */
      rtb_RelationalOperator1_g = (ovgl_dtld_st_nvmWriteDstLckVehTypeCmd_1s !=
        swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_k);

      /* CCaller: '<S108>/mBSW_NvmRead_DSTNOSC_retval1' */
      ovgl_dtld_st_nvmWriteDstLckVehTypeCmdReturnVal =
        mBSW_NvmRead_InventoryCmd_eep_retval();

      /* RelationalOperator: '<S108>/Relational Operator6' incorporates:
       *  Constant: '<S108>/Constant'
       */
      rtb_DataTypeConversion12_a =
        (ovgl_dtld_st_nvmWriteDstLckVehTypeCmdReturnVal != ((uint8)0U));

      /* RelationalOperator: '<S133>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S108>/Data Type Conversion5'
       *  UnitDelay: '<S133>/Delay Input1'
       *
       * Block description for '<S133>/Delay Input1':
       *
       *  Store in Global RAM
       */
      ovgl_dtld_st_nvmWriteDstLckVehTypeCmdRset = ((sint32)
        rtb_DataTypeConversion12_a < (sint32)
        swc_OGVL_ARID_DEF.DelayInput1_DSTATE_e);

      /* Outputs for Atomic SubSystem: '<S108>/SR_latch' */
      swc_OGVL_SR_latch(rtb_RelationalOperator1_g,
                        ovgl_dtld_st_nvmWriteDstLckVehTypeCmdRset,
                        &rtb_LogicalOperator3_i,
                        &swc_OGVL_ARID_DEF.ARID_DEF_SR_latch_b);

      /* End of Outputs for SubSystem: '<S108>/SR_latch' */

      /* SignalConversion generated from: '<S108>/SR_latch' */
      ovgl_dtld_st_nvmWriteDstLckVehTypeCmdEnbl = rtb_LogicalOperator3_i;

      /* Outputs for Enabled SubSystem: '<S108>/vsld_st_dstLckVehTypeCmd' incorporates:
       *  EnablePort: '<S135>/Enable'
       */
      if (ovgl_dtld_st_nvmWriteDstLckVehTypeCmdEnbl) {
        /* CCaller: '<S135>/C Caller4' */
        mBSW_NvmWrite_InventoryCmd_eep(ovgl_dtld_st_nvmWriteDstLckVehTypeCmd_1s);
      }

      /* End of Outputs for SubSystem: '<S108>/vsld_st_dstLckVehTypeCmd' */

      /* Outputs for Atomic SubSystem: '<S108>/Counter' */
      swc_OGVL_Counter(((uint8)1U), ((uint8)0U),
                       ovgl_dtld_st_nvmWriteDstLckVehTypeCmdEnbl, &rtb_Sum6_l,
                       &swc_OGVL_ARID_DEF.ARID_DEF_Counter_p);

      /* End of Outputs for SubSystem: '<S108>/Counter' */

      /* SignalConversion generated from: '<S108>/Counter' incorporates:
       *  Constant: '<S108>/Constant1'
       *  Constant: '<S108>/Constant2'
       */
      ovgl_dtld_st_nvmWriteDstLckVehTypeCmdCnt = rtb_Sum6_l;

      /* Update for UnitDelay: '<S108>/Unit Delay7' */
      swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_k =
        ovgl_dtld_st_nvmWriteDstLckVehTypeCmd_1s;

      /* Update for UnitDelay: '<S133>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S108>/Data Type Conversion5'
       *
       * Block description for '<S133>/Delay Input1':
       *
       *  Store in Global RAM
       */
      swc_OGVL_ARID_DEF.DelayInput1_DSTATE_e = rtb_DataTypeConversion12_a;

      /* End of Outputs for S-Function (fcgen): '<S150>/Function-Call Generator' */
    }

    /* End of Outputs for SubSystem: '<S114>/Enabled Subsystem' */

    /* Sum: '<S117>/Add' incorporates:
     *  Constant: '<S108>/Constant1'
     *  Constant: '<S108>/Constant2'
     *  Constant: '<S115>/Constant'
     *  RelationalOperator: '<S114>/Relational Operator1'
     *  Sum: '<S115>/Add'
     *  UnitDelay: '<S115>/Unit Delay'
     */
    rtb_Add = 1.0 + swc_OGVL_ARID_DEF.UnitDelay_DSTATE_c;

    /* Switch: '<S115>/Switch' incorporates:
     *  RelationalOperator: '<S115>/Relational Operator'
     */
    if (rtb_Add > swc_OGVL_ConstB.Divide_e) {
      /* Switch: '<S115>/Switch' incorporates:
       *  Constant: '<S115>/Constant4'
       */
      rtb_Switch_j = 1.0;
    } else {
      /* Switch: '<S115>/Switch' */
      rtb_Switch_j = rtb_Add;
    }

    /* End of Switch: '<S115>/Switch' */

    /* Switch: '<S122>/Switch2' incorporates:
     *  Constant: '<S104>/dtlc_b_nvmWriteSpdLmtLvlReq_ovrdflg'
     */
    if (ogvl_dtlc_b_nvmWriteSpdLmtLvlReq_ovrdflg) {
      /* Switch: '<S122>/Switch2' incorporates:
       *  Constant: '<S104>/dtlc_st_nvmWriteSpdLmtLvlReq_ovrdval'
       */
      ovgl_dtld_st_nvmWriteSpdLmtLvlReq =
        ogvl_dtlc_st_nvmWriteSpdLmtLvlReq_ovrdval;
    } else {
      /* Switch: '<S122>/Switch2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion2'
       */
      ovgl_dtld_st_nvmWriteSpdLmtLvlReq = ovgl_dtld_st_dstSpdLmtLvlWrite;
    }

    /* End of Switch: '<S122>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S115>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S151>/Enable'
     */
    if (rtb_Switch_j == swc_OGVL_ConstB.Divide_e) {
      /* S-Function (fcgen): '<S151>/Function-Call Generator' incorporates:
       *  SubSystem: '<S11>/Subsystem13'
       */
      /* SignalConversion: '<S109>/Signal Conversion' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion9'
       */
      ovgl_dtld_st_nvmWriteDstSpdLmtLvlReq_1s =
        ovgl_dtld_st_nvmWriteSpdLmtLvlReq;

      /* RelationalOperator: '<S109>/Relational Operator1' incorporates:
       *  UnitDelay: '<S109>/Unit Delay7'
       */
      rtb_RelationalOperator1_m = (ovgl_dtld_st_nvmWriteDstSpdLmtLvlReq_1s !=
        swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_o);

      /* CCaller: '<S109>/mBSW_NvmRead_DSTNOSC_retval1' */
      ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqReturnVal =
        mBSW_NvmRead_SpdLmtCmd_eep_retval();

      /* RelationalOperator: '<S109>/Relational Operator6' incorporates:
       *  Constant: '<S109>/Constant'
       */
      rtb_DataTypeConversion12_a =
        (ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqReturnVal != ((uint8)0U));

      /* RelationalOperator: '<S137>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S109>/Data Type Conversion5'
       *  UnitDelay: '<S137>/Delay Input1'
       *
       * Block description for '<S137>/Delay Input1':
       *
       *  Store in Global RAM
       */
      ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqRset = ((sint32)
        rtb_DataTypeConversion12_a < (sint32)
        swc_OGVL_ARID_DEF.DelayInput1_DSTATE_d);

      /* Outputs for Atomic SubSystem: '<S109>/SR_latch' */
      swc_OGVL_SR_latch(rtb_RelationalOperator1_m,
                        ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqRset,
                        &rtb_LogicalOperator3_l,
                        &swc_OGVL_ARID_DEF.ARID_DEF_SR_latch_k);

      /* End of Outputs for SubSystem: '<S109>/SR_latch' */

      /* SignalConversion generated from: '<S109>/SR_latch' */
      ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqEnbl = rtb_LogicalOperator3_l;

      /* Outputs for Enabled SubSystem: '<S109>/ogvl_vsld_st_dstSpdLmtLvlReq' incorporates:
       *  EnablePort: '<S139>/Enable'
       */
      if (ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqEnbl) {
        /* CCaller: '<S139>/C Caller10' */
        mBSW_NvmWrite_SpdLmtCmd_eep(ovgl_dtld_st_nvmWriteDstSpdLmtLvlReq_1s);
      }

      /* End of Outputs for SubSystem: '<S109>/ogvl_vsld_st_dstSpdLmtLvlReq' */

      /* Outputs for Atomic SubSystem: '<S109>/Counter' */
      swc_OGVL_Counter(((uint8)1U), ((uint8)0U),
                       ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqEnbl, &rtb_Sum6_n,
                       &swc_OGVL_ARID_DEF.ARID_DEF_Counter_cx);

      /* End of Outputs for SubSystem: '<S109>/Counter' */

      /* SignalConversion generated from: '<S109>/Counter' incorporates:
       *  Constant: '<S109>/Constant1'
       *  Constant: '<S109>/Constant2'
       */
      ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqCnt = rtb_Sum6_n;

      /* Update for UnitDelay: '<S109>/Unit Delay7' */
      swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_o =
        ovgl_dtld_st_nvmWriteDstSpdLmtLvlReq_1s;

      /* Update for UnitDelay: '<S137>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S109>/Data Type Conversion5'
       *
       * Block description for '<S137>/Delay Input1':
       *
       *  Store in Global RAM
       */
      swc_OGVL_ARID_DEF.DelayInput1_DSTATE_d = rtb_DataTypeConversion12_a;

      /* End of Outputs for S-Function (fcgen): '<S151>/Function-Call Generator' */
    }

    /* End of Outputs for SubSystem: '<S115>/Enabled Subsystem' */

    /* Sum: '<S117>/Add' incorporates:
     *  Constant: '<S109>/Constant1'
     *  Constant: '<S109>/Constant2'
     *  Constant: '<S116>/Constant'
     *  RelationalOperator: '<S115>/Relational Operator1'
     *  Sum: '<S116>/Add'
     *  UnitDelay: '<S116>/Unit Delay'
     */
    rtb_Add = 1.0 + swc_OGVL_ARID_DEF.UnitDelay_DSTATE_j;

    /* Switch: '<S116>/Switch' incorporates:
     *  RelationalOperator: '<S116>/Relational Operator'
     */
    if (rtb_Add > swc_OGVL_ConstB.Divide_f) {
      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S116>/Constant4'
       */
      rtb_Switch_gb = 1.0;
    } else {
      /* Switch: '<S116>/Switch' */
      rtb_Switch_gb = rtb_Add;
    }

    /* End of Switch: '<S116>/Switch' */

    /* Switch: '<S121>/Switch2' incorporates:
     *  Constant: '<S103>/dtlc_b_nvmWritePwrOffCmdReq_ovrdflg'
     */
    if (ogvl_dtlc_b_nvmWritePwrOffCmdReq_ovrdflg) {
      /* Switch: '<S121>/Switch2' incorporates:
       *  Constant: '<S103>/dtlc_st_nvmWritePwrOffCmdReq_ovrdval'
       */
      ovgl_dtld_st_nvmWritePwrOffCmdReq =
        ogvl_dtlc_st_nvmWritePwrOffCmdReq_ovrdval;
    } else {
      /* Switch: '<S121>/Switch2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion6'
       */
      ovgl_dtld_st_nvmWritePwrOffCmdReq = (uint8)ovgl_dtld_b_dstPwrOffWrite;
    }

    /* End of Switch: '<S121>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S116>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S152>/Enable'
     */
    if (rtb_Switch_gb == swc_OGVL_ConstB.Divide_f) {
      /* S-Function (fcgen): '<S152>/Function-Call Generator' incorporates:
       *  SubSystem: '<S11>/Subsystem14'
       */
      /* SignalConversion: '<S110>/Signal Conversion' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion10'
       */
      ovgl_dtld_st_nvmWriteDstPwrOffCmdReq_1s =
        ovgl_dtld_st_nvmWritePwrOffCmdReq;

      /* RelationalOperator: '<S110>/Relational Operator1' incorporates:
       *  UnitDelay: '<S110>/Unit Delay7'
       */
      rtb_RelationalOperator1_i = (ovgl_dtld_st_nvmWriteDstPwrOffCmdReq_1s !=
        swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_e);

      /* CCaller: '<S110>/mBSW_NvmRead_DSTNOSC_retval1' */
      ovgl_dtld_st_nvmWriteDstPwrOffCmdReqReturnVal =
        mBSW_NvmRead_PwrOffCmd_eep_retval();

      /* RelationalOperator: '<S110>/Relational Operator6' incorporates:
       *  Constant: '<S110>/Constant'
       */
      rtb_DataTypeConversion12_a =
        (ovgl_dtld_st_nvmWriteDstPwrOffCmdReqReturnVal != ((uint8)0U));

      /* RelationalOperator: '<S141>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S110>/Data Type Conversion5'
       *  UnitDelay: '<S141>/Delay Input1'
       *
       * Block description for '<S141>/Delay Input1':
       *
       *  Store in Global RAM
       */
      ovgl_dtld_st_nvmWriteDstPwrOffCmdReqRset = ((sint32)
        rtb_DataTypeConversion12_a < (sint32)
        swc_OGVL_ARID_DEF.DelayInput1_DSTATE_l);

      /* Outputs for Atomic SubSystem: '<S110>/SR_latch' */
      swc_OGVL_SR_latch(rtb_RelationalOperator1_i,
                        ovgl_dtld_st_nvmWriteDstPwrOffCmdReqRset,
                        &rtb_LogicalOperator3_n,
                        &swc_OGVL_ARID_DEF.ARID_DEF_SR_latch_m);

      /* End of Outputs for SubSystem: '<S110>/SR_latch' */

      /* SignalConversion generated from: '<S110>/SR_latch' */
      ovgl_dtld_st_nvmWriteDstPwrOffCmdReqEnbl = rtb_LogicalOperator3_n;

      /* Outputs for Enabled SubSystem: '<S110>/ogvl_dtld_st_dstPwrOffCmdReq' incorporates:
       *  EnablePort: '<S143>/Enable'
       */
      if (ovgl_dtld_st_nvmWriteDstPwrOffCmdReqEnbl) {
        /* CCaller: '<S143>/C Caller10' */
        mBSW_NvmWrite_PwrOffCmd_eep(ovgl_dtld_st_nvmWriteDstPwrOffCmdReq_1s);
      }

      /* End of Outputs for SubSystem: '<S110>/ogvl_dtld_st_dstPwrOffCmdReq' */

      /* Outputs for Atomic SubSystem: '<S110>/Counter' */
      swc_OGVL_Counter(((uint8)1U), ((uint8)0U),
                       ovgl_dtld_st_nvmWriteDstPwrOffCmdReqEnbl, &rtb_Sum6_j,
                       &swc_OGVL_ARID_DEF.ARID_DEF_Counter_c);

      /* End of Outputs for SubSystem: '<S110>/Counter' */

      /* SignalConversion generated from: '<S110>/Counter' incorporates:
       *  Constant: '<S110>/Constant1'
       *  Constant: '<S110>/Constant2'
       */
      ovgl_dtld_st_nvmWriteDstPwrOffCmdReqCnt = rtb_Sum6_j;

      /* Update for UnitDelay: '<S110>/Unit Delay7' */
      swc_OGVL_ARID_DEF.UnitDelay7_DSTATE_e =
        ovgl_dtld_st_nvmWriteDstPwrOffCmdReq_1s;

      /* Update for UnitDelay: '<S141>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S110>/Data Type Conversion5'
       *
       * Block description for '<S141>/Delay Input1':
       *
       *  Store in Global RAM
       */
      swc_OGVL_ARID_DEF.DelayInput1_DSTATE_l = rtb_DataTypeConversion12_a;

      /* End of Outputs for S-Function (fcgen): '<S152>/Function-Call Generator' */
    }

    /* End of Outputs for SubSystem: '<S116>/Enabled Subsystem' */

    /* Sum: '<S117>/Add' incorporates:
     *  Constant: '<S110>/Constant1'
     *  Constant: '<S110>/Constant2'
     *  Constant: '<S117>/Constant'
     *  RelationalOperator: '<S116>/Relational Operator1'
     *  UnitDelay: '<S117>/Unit Delay'
     */
    rtb_Add = 1.0 + swc_OGVL_ARID_DEF.UnitDelay_DSTATE_a;

    /* Switch: '<S117>/Switch' incorporates:
     *  RelationalOperator: '<S117>/Relational Operator'
     */
    if (rtb_Add > swc_OGVL_ConstB.Divide_g) {
      /* Switch: '<S117>/Switch' incorporates:
       *  Constant: '<S117>/Constant4'
       */
      rtb_Add = 1.0;
    }

    /* End of Switch: '<S117>/Switch' */

    /* Switch: '<S123>/Switch2' incorporates:
     *  Constant: '<S105>/ovgl_b_nvmWriteTboxDsmtSet_ovrdflg'
     */
    if (ovgl_b_nvmWriteTboxDsmtSet_ovrdflg) {
      /* Switch: '<S123>/Switch2' incorporates:
       *  Constant: '<S105>/ovgl_b_nvmWriteTboxDsmtSet_ovrdval'
       */
      Ovrd_b_nvmWriteTboxDsmtWrite = ovgl_b_nvmWriteTboxDsmtSet_ovrdval;
    } else {
      /* Switch: '<S123>/Switch2' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion12'
       */
      Ovrd_b_nvmWriteTboxDsmtWrite = (uint8)swc_OGVL_ARID_DEF.cmdWrite;
    }

    /* End of Switch: '<S123>/Switch2' */

    /* Outputs for Enabled SubSystem: '<S117>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S153>/Enable'
     */
    if (rtb_Add == swc_OGVL_ConstB.Divide_g) {
      /* S-Function (fcgen): '<S153>/Function-Call Generator' incorporates:
       *  SubSystem: '<S11>/Subsystem2'
       */
      /* SignalConversion: '<S111>/Signal Conversion' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion11'
       */
      rtb_DataTypeConversion19 = Ovrd_b_nvmWriteTboxDsmtWrite;

      /* RelationalOperator: '<S111>/Relational Operator1' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion11'
       *  UnitDelay: '<S111>/Unit Delay7'
       */
      rtb_RelationalOperator1_d = (Ovrd_b_nvmWriteTboxDsmtWrite !=
        swc_OGVL_ARID_DEF.UnitDelay7_DSTATE);

      /* CCaller: '<S111>/mBSW_NvmRead_TboxDsmt_retval' */
      ovgl_dtld_st_nvmWriteDstTboxDsmtReturnVal =
        mBSW_NvmRead_TboxDsmt_eep_retval();

      /* RelationalOperator: '<S111>/Relational Operator6' incorporates:
       *  Constant: '<S111>/Constant'
       */
      rtb_DataTypeConversion12_a = (ovgl_dtld_st_nvmWriteDstTboxDsmtReturnVal !=
        ((uint8)0U));

      /* RelationalOperator: '<S145>/FixPt Relational Operator' incorporates:
       *  DataTypeConversion: '<S111>/Data Type Conversion5'
       *  UnitDelay: '<S145>/Delay Input1'
       *
       * Block description for '<S145>/Delay Input1':
       *
       *  Store in Global RAM
       */
      ovgl_dtld_st_nvmWriteDstTboxDsmtRset = ((sint32)rtb_DataTypeConversion12_a
        < (sint32)swc_OGVL_ARID_DEF.DelayInput1_DSTATE_n);

      /* Outputs for Atomic SubSystem: '<S111>/SR_latch' */
      swc_OGVL_SR_latch(rtb_RelationalOperator1_d,
                        ovgl_dtld_st_nvmWriteDstTboxDsmtRset,
                        &rtb_LogicalOperator3_e,
                        &swc_OGVL_ARID_DEF.ARID_DEF_SR_latch);

      /* End of Outputs for SubSystem: '<S111>/SR_latch' */

      /* SignalConversion generated from: '<S111>/SR_latch' */
      ovgl_dtld_st_nvmWriteDstTboxDsmtEnbl = rtb_LogicalOperator3_e;

      /* Outputs for Enabled SubSystem: '<S111>/ogvl_dtld_st_dstPwrOffCmdReq' incorporates:
       *  EnablePort: '<S147>/Enable'
       */
      if (ovgl_dtld_st_nvmWriteDstTboxDsmtEnbl) {
        /* CCaller: '<S147>/C Caller10' */
        mBSW_NvmWrite_TboxDsmt_eep(rtb_DataTypeConversion19);
      }

      /* End of Outputs for SubSystem: '<S111>/ogvl_dtld_st_dstPwrOffCmdReq' */

      /* Outputs for Atomic SubSystem: '<S111>/Counter' */
      swc_OGVL_Counter(((uint8)1U), ((uint8)0U),
                       ovgl_dtld_st_nvmWriteDstTboxDsmtEnbl, &rtb_Sum6,
                       &swc_OGVL_ARID_DEF.ARID_DEF_Counter);

      /* End of Outputs for SubSystem: '<S111>/Counter' */

      /* Update for UnitDelay: '<S111>/Unit Delay7' incorporates:
       *  Constant: '<S111>/Constant1'
       *  Constant: '<S111>/Constant2'
       */
      swc_OGVL_ARID_DEF.UnitDelay7_DSTATE = rtb_DataTypeConversion19;

      /* Update for UnitDelay: '<S145>/Delay Input1' incorporates:
       *  DataTypeConversion: '<S111>/Data Type Conversion5'
       *
       * Block description for '<S145>/Delay Input1':
       *
       *  Store in Global RAM
       */
      swc_OGVL_ARID_DEF.DelayInput1_DSTATE_n = rtb_DataTypeConversion12_a;

      /* End of Outputs for S-Function (fcgen): '<S153>/Function-Call Generator' */
    }

    /* End of Outputs for SubSystem: '<S117>/Enabled Subsystem' */

    /* Update for UnitDelay: '<S112>/Unit Delay' incorporates:
     *  Constant: '<S111>/Constant1'
     *  Constant: '<S111>/Constant2'
     *  RelationalOperator: '<S117>/Relational Operator1'
     */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE = rtb_Switch;

    /* Update for UnitDelay: '<S113>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_g = rtb_Switch_b;

    /* Update for UnitDelay: '<S114>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_l = rtb_Switch_p;

    /* Update for UnitDelay: '<S115>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_c = rtb_Switch_j;

    /* Update for UnitDelay: '<S116>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_j = rtb_Switch_gb;

    /* Update for UnitDelay: '<S117>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_a = rtb_Add;

    /* End of Outputs for SubSystem: '<S2>/WriteToNVM' */

    /* Logic: '<S4>/Logical Operator' incorporates:
     *  Delay: '<S4>/Delay'
     *  Delay: '<S4>/Delay1'
     *  Delay: '<S4>/Delay2'
     *  RelationalOperator: '<S4>/Relational Operator1'
     *  RelationalOperator: '<S4>/Relational Operator15'
     *  RelationalOperator: '<S4>/Relational Operator2'
     */
    swc_OGVL_ARID_DEF.LogicalOperator = ((rtb_DataTypeConversion16 ==
      swc_OGVL_ARID_DEF.Delay_DSTATE_k[0]) && (rtb_DataTypeConversion16 ==
      swc_OGVL_ARID_DEF.Delay1_DSTATE[0]) && (rtb_DataTypeConversion16 ==
      swc_OGVL_ARID_DEF.Delay2_DSTATE[0]));

    /* Outputs for Atomic SubSystem: '<S4>/turnON_delay4' */
    rtb_flg_out_e = swc_OGVL_turnON_delay3(swc_OGVL_ARID_DEF.LogicalOperator,
      0.1F, 0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay4_l);

    /* End of Outputs for SubSystem: '<S4>/turnON_delay4' */

    /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant5'
     */
    swc_OGVL_ARID_DEF.vsld_st_InventorySpdLmtReq = ovgl_dtld_b_dstInvtryLckExc;

    /* Switch: '<S5>/Switch12' incorporates:
     *  Logic: '<S5>/Logical Operator2'
     */
    if (ovgl_dtld_b_dstInvtryLckExc || ovgl_dtld_b_dstSpdLmtLvl1Exc ||
        ovgl_dtld_b_dstSpdLmtLvl2Exc || ovgl_dtld_b_dstSpdLmtLvl3Exc ||
        ovgl_dtld_b_dstAntiDismtLckExc) {
      /* Switch: '<S5>/Switch12' incorporates:
       *  Constant: '<S5>/Constant24'
       */
      swc_OGVL_ARID_DEF.vsld_st_LockVehPer = ((uint8)1U);
    } else {
      /* Switch: '<S5>/Switch12' incorporates:
       *  Constant: '<S5>/Constant26'
       */
      swc_OGVL_ARID_DEF.vsld_st_LockVehPer = ((uint8)0U);
    }

    /* End of Switch: '<S5>/Switch12' */

    /* SignalConversion: '<S5>/Signal Conversion' */
    swc_OGVL_ARID_DEF.vsld_st_VersionConversion = ovgl_dtld_b_dstLckVehVerExc;

    /* Switch: '<S9>/Switch' incorporates:
     *  Logic: '<S9>/Logical Operator'
     *  Switch: '<S9>/Switch1'
     *  Switch: '<S9>/Switch2'
     */
    if (ovgl_dtld_b_dstAntiDismtLckExc || ovgl_dtld_b_dstInvtryLckExc ||
        ovgl_dtld_b_dstSpdLmtLvl1Exc) {
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant1'
       */
      vsld_v_dstSpdLimRaw_kph = vslc_v_vehSpdLimLevel1_kph;
    } else if (ovgl_dtld_b_dstSpdLmtLvl2Exc) {
      /* Switch: '<S9>/Switch1' incorporates:
       *  Constant: '<S9>/Constant3'
       *  Switch: '<S9>/Switch'
       */
      vsld_v_dstSpdLimRaw_kph = vslc_v_vehSpdLimLevel2_kph;
    } else if (ovgl_dtld_b_dstSpdLmtLvl3Exc) {
      /* Switch: '<S9>/Switch2' incorporates:
       *  Constant: '<S9>/Constant13'
       *  Switch: '<S9>/Switch'
       *  Switch: '<S9>/Switch1'
       */
      vsld_v_dstSpdLimRaw_kph = vslc_v_vehSpdLimLevel3_kph;
    } else {
      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant12'
       *  Switch: '<S9>/Switch1'
       *  Switch: '<S9>/Switch2'
       */
      vsld_v_dstSpdLimRaw_kph = ((float32)VEH_SPD_MAX);
    }

    /* End of Switch: '<S9>/Switch' */

    /* Switch: '<S9>/Switch3' incorporates:
     *  Constant: '<S9>/Constant2'
     *  RelationalOperator: '<S9>/Relational Operator6'
     */
    if (rtb_DataTypeConversion21 < vslc_v_vehSpdUpdLimCfg_kph) {
      /* Switch: '<S9>/Switch3' */
      vsld_v_dstSpdLim_kph = vsld_v_dstSpdLimRaw_kph;
    } else {
      /* Switch: '<S9>/Switch3' incorporates:
       *  UnitDelay: '<S9>/Unit Delay'
       */
      vsld_v_dstSpdLim_kph = swc_OGVL_ARID_DEF.UnitDelay_DSTATE_h;
    }

    /* End of Switch: '<S9>/Switch3' */

    /* Switch: '<S5>/Switch14' incorporates:
     *  Constant: '<S5>/Constant1'
     *  Constant: '<S5>/Constant13'
     *  Constant: '<S5>/Constant3'
     *  RelationalOperator: '<S5>/Relational Operator2'
     *  RelationalOperator: '<S5>/Relational Operator39'
     *  RelationalOperator: '<S5>/Relational Operator40'
     *  Switch: '<S5>/Switch15'
     *  Switch: '<S5>/Switch16'
     */
    if (vsld_v_dstSpdLim_kph == vslc_v_vehSpdLimLevel1_kph) {
      /* Switch: '<S5>/Switch14' incorporates:
       *  Constant: '<S5>/Constant66'
       */
      swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq = ((uint8)0U);
    } else if (vsld_v_dstSpdLim_kph == vslc_v_vehSpdLimLevel2_kph) {
      /* Switch: '<S5>/Switch15' incorporates:
       *  Constant: '<S5>/Constant62'
       *  Switch: '<S5>/Switch14'
       */
      swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq = ((uint8)1U);
    } else if (vsld_v_dstSpdLim_kph == vslc_v_vehSpdLimLevel3_kph) {
      /* Switch: '<S5>/Switch16' incorporates:
       *  Constant: '<S5>/Constant65'
       *  Switch: '<S5>/Switch14'
       *  Switch: '<S5>/Switch15'
       */
      swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq = ((uint8)2U);
    } else {
      /* Switch: '<S5>/Switch14' incorporates:
       *  Constant: '<S5>/Constant67'
       *  Switch: '<S5>/Switch15'
       *  Switch: '<S5>/Switch16'
       */
      swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq = ((uint8)3U);
    }

    /* End of Switch: '<S5>/Switch14' */

    /* Sum: '<S22>/Add' incorporates:
     *  Constant: '<S22>/Constant2'
     *  UnitDelay: '<S22>/Unit Delay'
     */
    rtb_DataTypeConversion19 = (uint8)((uint32)((uint8)1U) +
      swc_OGVL_ARID_DEF.UnitDelay_DSTATE_lx);

    /* RelationalOperator: '<S22>/Relational Operator' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    rtb_DataTypeConversion7_g = (rtb_DataTypeConversion19 > ((uint8)10U));

    /* Switch: '<S22>/Switch1' incorporates:
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant3'
     */
    if (rtb_DataTypeConversion7_g) {
      rtb_Add1 = ((uint8)1U);
    } else {
      rtb_Add1 = ((uint8)0U);
    }

    /* Sum: '<S22>/Add1' incorporates:
     *  Switch: '<S22>/Switch1'
     *  UnitDelay: '<S22>/Unit Delay1'
     */
    rtb_Add1 = (uint8)((uint32)rtb_Add1 + swc_OGVL_ARID_DEF.UnitDelay1_DSTATE);

    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant6'
     *  RelationalOperator: '<S22>/Relational Operator1'
     */
    if (rtb_Add1 > ((uint8)255U)) {
      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S22>/Constant7'
       */
      swc_OGVL_ARID_DEF.Switch2 = ((uint8)0U);
    } else {
      /* Switch: '<S22>/Switch2' */
      swc_OGVL_ARID_DEF.Switch2 = rtb_Add1;
    }

    /* End of Switch: '<S22>/Switch2' */

    /* RelationalOperator: '<S5>/Relational Operator28' incorporates:
     *  Constant: '<S5>/Constant46'
     */
    rtb_RelationalOperator28_b = (rtb_DataTypeConversion12 == ((uint8)1U));

    /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
     *  Constant: '<S5>/Constant2'
     */
    rtb_RelationalOperator3_d = (rtb_DataTypeConversion12 == ((uint8)0U));

    /* Outputs for Atomic SubSystem: '<S23>/turnON_delay1' */
    rtb_flg_out_cd = swc_OGVL_turnON_delay3(rtb_RelationalOperator28_b, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_dy);

    /* End of Outputs for SubSystem: '<S23>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S26>/turnON_delay1' */
    rtb_flg_out_c = swc_OGVL_turnON_delay3(rtb_RelationalOperator3_d, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_g);

    /* End of Outputs for SubSystem: '<S26>/turnON_delay1' */

    /* Switch: '<S5>/Switch1' incorporates:
     *  Constant: '<S23>/Constant1'
     *  Constant: '<S23>/Constant3'
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant3'
     *  Switch: '<S5>/Switch2'
     */
    if (rtb_flg_out_cd) {
      /* Switch: '<S5>/Switch1' incorporates:
       *  Constant: '<S5>/Constant4'
       */
      swc_OGVL_ARID_DEF.Switch1 = ((uint8)1U);
    } else if (rtb_flg_out_c) {
      /* Switch: '<S5>/Switch2' incorporates:
       *  Constant: '<S5>/Constant6'
       *  Switch: '<S5>/Switch1'
       */
      swc_OGVL_ARID_DEF.Switch1 = ((uint8)0U);
    } else {
      /* Switch: '<S5>/Switch1' incorporates:
       *  UnitDelay: '<S5>/Unit Delay'
       */
      swc_OGVL_ARID_DEF.Switch1 = swc_OGVL_ARID_DEF.UnitDelay_DSTATE_p;
    }

    /* End of Switch: '<S5>/Switch1' */

    /* RelationalOperator: '<S5>/Relational Operator4' incorporates:
     *  Constant: '<S5>/Constant8'
     */
    rtb_RelationalOperator4 = (rtb_DataTypeConversion13 == ((uint8)1U));

    /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
     *  Constant: '<S5>/Constant5'
     */
    rtb_RelationalOperator5_p = (rtb_DataTypeConversion13 == ((uint8)0U));

    /* Outputs for Atomic SubSystem: '<S27>/turnON_delay1' */
    rtb_flg_out_l = swc_OGVL_turnON_delay3(rtb_RelationalOperator4, 5.0F, 0.01F,
      &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_d);

    /* End of Outputs for SubSystem: '<S27>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S28>/turnON_delay1' */
    rtb_flg_out_h = swc_OGVL_turnON_delay3(rtb_RelationalOperator5_p, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_j);

    /* End of Outputs for SubSystem: '<S28>/turnON_delay1' */

    /* Switch: '<S5>/Switch3' incorporates:
     *  Constant: '<S27>/Constant1'
     *  Constant: '<S27>/Constant3'
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S28>/Constant3'
     *  Switch: '<S5>/Switch4'
     */
    if (rtb_flg_out_l) {
      /* Switch: '<S5>/Switch3' incorporates:
       *  Constant: '<S5>/Constant7'
       */
      swc_OGVL_ARID_DEF.Switch3 = ((uint8)1U);
    } else if (rtb_flg_out_h) {
      /* Switch: '<S5>/Switch4' incorporates:
       *  Constant: '<S5>/Constant9'
       *  Switch: '<S5>/Switch3'
       */
      swc_OGVL_ARID_DEF.Switch3 = ((uint8)0U);
    } else {
      /* Switch: '<S5>/Switch3' incorporates:
       *  UnitDelay: '<S5>/Unit Delay1'
       */
      swc_OGVL_ARID_DEF.Switch3 = swc_OGVL_ARID_DEF.UnitDelay1_DSTATE_n;
    }

    /* End of Switch: '<S5>/Switch3' */

    /* RelationalOperator: '<S5>/Relational Operator6' incorporates:
     *  Constant: '<S5>/Constant14'
     */
    rtb_RelationalOperator6_mc = (rtb_DataTypeConversion15 == ((uint8)2U));

    /* RelationalOperator: '<S5>/Relational Operator7' incorporates:
     *  Constant: '<S5>/Constant10'
     */
    rtb_RelationalOperator7_c = (rtb_DataTypeConversion15 == ((uint8)1U));

    /* RelationalOperator: '<S5>/Relational Operator8' incorporates:
     *  Constant: '<S5>/Constant16'
     */
    rtb_RelationalOperator8_j = (rtb_DataTypeConversion15 == ((uint8)0U));

    /* Outputs for Atomic SubSystem: '<S29>/turnON_delay1' */
    rtb_flg_out_b = swc_OGVL_turnON_delay3(rtb_RelationalOperator6_mc, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_l);

    /* End of Outputs for SubSystem: '<S29>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S30>/turnON_delay1' */
    rtb_flg_out_m5 = swc_OGVL_turnON_delay3(rtb_RelationalOperator7_c, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_p);

    /* End of Outputs for SubSystem: '<S30>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S31>/turnON_delay1' */
    rtb_flg_out_o = swc_OGVL_turnON_delay3(rtb_RelationalOperator8_j, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_n);

    /* End of Outputs for SubSystem: '<S31>/turnON_delay1' */

    /* Switch: '<S5>/Switch5' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant3'
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S30>/Constant3'
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant3'
     *  Switch: '<S5>/Switch6'
     *  Switch: '<S5>/Switch7'
     */
    if (rtb_flg_out_b) {
      /* Switch: '<S5>/Switch5' incorporates:
       *  Constant: '<S5>/Constant11'
       */
      swc_OGVL_ARID_DEF.Switch5 = ((uint8)2U);
    } else if (rtb_flg_out_m5) {
      /* Switch: '<S5>/Switch6' incorporates:
       *  Constant: '<S5>/Constant15'
       *  Switch: '<S5>/Switch5'
       */
      swc_OGVL_ARID_DEF.Switch5 = ((uint8)1U);
    } else if (rtb_flg_out_o) {
      /* Switch: '<S5>/Switch7' incorporates:
       *  Constant: '<S5>/Constant17'
       *  Switch: '<S5>/Switch5'
       *  Switch: '<S5>/Switch6'
       */
      swc_OGVL_ARID_DEF.Switch5 = ((uint8)0U);
    } else {
      /* Switch: '<S5>/Switch5' incorporates:
       *  Switch: '<S5>/Switch6'
       *  UnitDelay: '<S5>/Unit Delay2'
       */
      swc_OGVL_ARID_DEF.Switch5 = swc_OGVL_ARID_DEF.UnitDelay2_DSTATE;
    }

    /* End of Switch: '<S5>/Switch5' */

    /* RelationalOperator: '<S5>/Relational Operator10' incorporates:
     *  Constant: '<S5>/Constant18'
     */
    rtb_RelationalOperator10_d = (rtb_DataTypeConversion14 == ((uint8)0U));

    /* RelationalOperator: '<S5>/Relational Operator9' incorporates:
     *  Constant: '<S5>/Constant20'
     */
    rtb_RelationalOperator9_c = (rtb_DataTypeConversion14 == ((uint8)1U));

    /* Outputs for Atomic SubSystem: '<S32>/turnON_delay1' */
    rtb_flg_out_m = swc_OGVL_turnON_delay3(rtb_RelationalOperator9_c, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_m);

    /* End of Outputs for SubSystem: '<S32>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S33>/turnON_delay1' */
    rtb_flg_out_n = swc_OGVL_turnON_delay3(rtb_RelationalOperator10_d, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1);

    /* End of Outputs for SubSystem: '<S33>/turnON_delay1' */

    /* Switch: '<S5>/Switch8' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S32>/Constant3'
     *  Constant: '<S33>/Constant1'
     *  Constant: '<S33>/Constant3'
     *  Switch: '<S5>/Switch9'
     */
    if (rtb_flg_out_m) {
      /* Switch: '<S5>/Switch8' incorporates:
       *  Constant: '<S5>/Constant19'
       */
      swc_OGVL_ARID_DEF.Switch8 = ((uint8)1U);
    } else if (rtb_flg_out_n) {
      /* Switch: '<S5>/Switch9' incorporates:
       *  Constant: '<S5>/Constant21'
       *  Switch: '<S5>/Switch8'
       */
      swc_OGVL_ARID_DEF.Switch8 = ((uint8)0U);
    } else {
      /* Switch: '<S5>/Switch8' incorporates:
       *  UnitDelay: '<S5>/Unit Delay3'
       */
      swc_OGVL_ARID_DEF.Switch8 = swc_OGVL_ARID_DEF.UnitDelay3_DSTATE;
    }

    /* End of Switch: '<S5>/Switch8' */

    /* Switch: '<S5>/Switch10' */
    if (ovgl_b_dstTboxDsmtExc) {
      /* Switch: '<S5>/Switch10' incorporates:
       *  Constant: '<S5>/Constant22'
       */
      swc_OGVL_ARID_DEF.Switch10 = ((uint8)1U);
    } else {
      /* Switch: '<S5>/Switch10' incorporates:
       *  Constant: '<S5>/Constant23'
       */
      swc_OGVL_ARID_DEF.Switch10 = ((uint8)0U);
    }

    /* End of Switch: '<S5>/Switch10' */

    /* RelationalOperator: '<S5>/Relational Operator14' incorporates:
     *  Constant: '<S5>/Constant27'
     */
    rtb_RelationalOperator14_i = (rtb_DataTypeConversion20 == ((uint8)0U));

    /* RelationalOperator: '<S5>/Relational Operator16' incorporates:
     *  Constant: '<S5>/Constant29'
     */
    rtb_RelationalOperator16_i = (rtb_DataTypeConversion20 == ((uint8)1U));

    /* Outputs for Atomic SubSystem: '<S24>/turnON_delay1' */
    rtb_flg_out_hy = swc_OGVL_turnON_delay3(rtb_RelationalOperator16_i, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_dh);

    /* End of Outputs for SubSystem: '<S24>/turnON_delay1' */

    /* Outputs for Atomic SubSystem: '<S25>/turnON_delay1' */
    rtb_flg_out_a = swc_OGVL_turnON_delay3(rtb_RelationalOperator14_i, 5.0F,
      0.01F, &swc_OGVL_ARID_DEF.ARID_DEF_turnON_delay1_ld);

    /* End of Outputs for SubSystem: '<S25>/turnON_delay1' */

    /* Switch: '<S5>/Switch17' incorporates:
     *  Constant: '<S24>/Constant1'
     *  Constant: '<S24>/Constant3'
     *  Constant: '<S25>/Constant1'
     *  Constant: '<S25>/Constant3'
     *  Switch: '<S5>/Switch18'
     */
    if (rtb_flg_out_hy) {
      /* Switch: '<S5>/Switch17' incorporates:
       *  Constant: '<S5>/Constant28'
       */
      swc_OGVL_ARID_DEF.Switch17 = ((uint8)1U);
    } else if (rtb_flg_out_a) {
      /* Switch: '<S5>/Switch18' incorporates:
       *  Constant: '<S5>/Constant30'
       *  Switch: '<S5>/Switch17'
       */
      swc_OGVL_ARID_DEF.Switch17 = ((uint8)0U);
    } else {
      /* Switch: '<S5>/Switch17' incorporates:
       *  UnitDelay: '<S5>/Unit Delay6'
       */
      swc_OGVL_ARID_DEF.Switch17 = swc_OGVL_ARID_DEF.UnitDelay6_DSTATE;
    }

    /* End of Switch: '<S5>/Switch17' */

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    swc_OGVL_ARID_DEF.vsld_PowerOffCmdSts = ovgl_dtld_b_dstPwrOffExc;

    /* Chart: '<S7>/ControlTorqueOff' */
    if (swc_OGVL_ARID_DEF.is_active_c13_swc_OGVL == 0U) {
      swc_OGVL_ARID_DEF.is_active_c13_swc_OGVL = 1U;
      swc_OGVL_ARID_DEF.is_c13_swc_OGVL = swc_OGVL_IN_Init;

      /* SignalConversion: '<S7>/Signal Conversion1' */
      ovgl_dtld_b_dstCtrlTqOff = false;

      /* SignalConversion: '<S7>/Signal Conversion' */
      ovgl_dtld_b_dstCtrlTqLmt = false;
    } else if (swc_OGVL_ARID_DEF.is_c13_swc_OGVL == swc_OGVL_IN_Active) {
      if (!ovgl_dtld_b_dstPwrOffExc) {
        swc_OGVL_ARID_DEF.is_Active = swc_OGVL_IN_NO_ACTIVE_CHILD;
        swc_OGVL_ARID_DEF.is_c13_swc_OGVL = swc_OGVL_IN_Init;

        /* SignalConversion: '<S7>/Signal Conversion1' */
        ovgl_dtld_b_dstCtrlTqOff = false;

        /* SignalConversion: '<S7>/Signal Conversion' */
        ovgl_dtld_b_dstCtrlTqLmt = false;
      } else if (swc_OGVL_ARID_DEF.is_Active == swc_OGVL_IN_LimitTorque) {
        /* SignalConversion: '<S7>/Signal Conversion1' */
        ovgl_dtld_b_dstCtrlTqOff = false;

        /* SignalConversion: '<S7>/Signal Conversion' */
        ovgl_dtld_b_dstCtrlTqLmt = true;
        if (swc_OGVL_ARID_DEF.dt > 10.0F) {
          swc_OGVL_ARID_DEF.is_Active = swc_OGVL_IN_ZeroTorque;

          /* SignalConversion: '<S7>/Signal Conversion1' */
          ovgl_dtld_b_dstCtrlTqOff = true;

          /* SignalConversion: '<S7>/Signal Conversion' */
          ovgl_dtld_b_dstCtrlTqLmt = false;
        } else {
          swc_OGVL_ARID_DEF.dt += 0.01F;
        }
      } else {
        /* SignalConversion: '<S7>/Signal Conversion1' */
        /* case IN_ZeroTorque: */
        ovgl_dtld_b_dstCtrlTqOff = true;

        /* SignalConversion: '<S7>/Signal Conversion' */
        ovgl_dtld_b_dstCtrlTqLmt = false;
      }
    } else {
      /* SignalConversion: '<S7>/Signal Conversion1' */
      /* case IN_Init: */
      ovgl_dtld_b_dstCtrlTqOff = false;

      /* SignalConversion: '<S7>/Signal Conversion' */
      ovgl_dtld_b_dstCtrlTqLmt = false;
      if (ovgl_dtld_b_dstPwrOffExc) {
        swc_OGVL_ARID_DEF.is_c13_swc_OGVL = swc_OGVL_IN_Active;
        if (rtb_DataTypeConversion21 <= 3.0F) {
          swc_OGVL_ARID_DEF.is_Active = swc_OGVL_IN_ZeroTorque;

          /* SignalConversion: '<S7>/Signal Conversion1' */
          ovgl_dtld_b_dstCtrlTqOff = true;

          /* SignalConversion: '<S7>/Signal Conversion' */
          ovgl_dtld_b_dstCtrlTqLmt = false;
        } else {
          swc_OGVL_ARID_DEF.is_Active = swc_OGVL_IN_LimitTorque;
          swc_OGVL_ARID_DEF.dt = 0.0F;

          /* SignalConversion: '<S7>/Signal Conversion1' */
          ovgl_dtld_b_dstCtrlTqOff = false;

          /* SignalConversion: '<S7>/Signal Conversion' */
          ovgl_dtld_b_dstCtrlTqLmt = true;
        }
      }
    }

    /* End of Chart: '<S7>/ControlTorqueOff' */

    /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    rtb_RelationalOperator1_k2 = (rtb_DataTypeConversion12 == ((uint8)1U));

    /* RelationalOperator: '<S7>/Relational Operator4' incorporates:
     *  Constant: '<S7>/Constant5'
     */
    rtb_RelationalOperator4_h = (rtb_DataTypeConversion12 == ((uint8)0U));

    /* RelationalOperator: '<S10>/Relational Operator34' incorporates:
     *  Constant: '<S10>/Constant8'
     */
    rtb_RelationalOperator34 = (rtb_DataTypeConversion14 == ((uint8)0U));

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_hv = rtb_flg_out_e;

    /* Update for UnitDelay: '<S10>/UnitDelay4' */
    swc_OGVL_ARID_DEF.UnitDelay4_DSTATE = ovgl_dtld_b_dstSpdLmtLvl1En;

    /* Update for UnitDelay: '<S10>/UnitDelay1' */
    swc_OGVL_ARID_DEF.UnitDelay1_DSTATE_a = ovgl_dtld_b_dstSpdLmtLvl2En;

    /* Update for UnitDelay: '<S10>/UnitDelay2' */
    swc_OGVL_ARID_DEF.UnitDelay2_DSTATE_h = ovgl_dtld_b_dstSpdLmtLvl3En;

    /* Update for UnitDelay: '<S71>/Delay Input1'
     *
     * Block description for '<S71>/Delay Input1':
     *
     *  Store in Global RAM
     */
    swc_OGVL_ARID_DEF.DelayInput1_DSTATE = rtb_DataTypeConversion23;
    for (idxDelay = 0; idxDelay < 9; idxDelay++) {
      /* Update for Delay: '<S7>/Delay' */
      swc_OGVL_ARID_DEF.Delay_DSTATE[idxDelay] =
        swc_OGVL_ARID_DEF.Delay_DSTATE[idxDelay + 1];

      /* Update for Delay: '<S4>/Delay' */
      swc_OGVL_ARID_DEF.Delay_DSTATE_k[idxDelay] =
        swc_OGVL_ARID_DEF.Delay_DSTATE_k[idxDelay + 1];
    }

    /* Update for Delay: '<S7>/Delay' */
    swc_OGVL_ARID_DEF.Delay_DSTATE[9] = rtb_DataTypeConversion16;

    /* Update for Delay: '<S4>/Delay' */
    swc_OGVL_ARID_DEF.Delay_DSTATE_k[9] = rtb_DataTypeConversion16;

    /* Update for Delay: '<S4>/Delay1' */
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
      swc_OGVL_ARID_DEF.Delay1_DSTATE[idxDelay] =
        swc_OGVL_ARID_DEF.Delay1_DSTATE[idxDelay + 1];
    }

    swc_OGVL_ARID_DEF.Delay1_DSTATE[19] = rtb_DataTypeConversion16;

    /* End of Update for Delay: '<S4>/Delay1' */

    /* Update for Delay: '<S4>/Delay2' */
    for (idxDelay = 0; idxDelay < 29; idxDelay++) {
      swc_OGVL_ARID_DEF.Delay2_DSTATE[idxDelay] =
        swc_OGVL_ARID_DEF.Delay2_DSTATE[idxDelay + 1];
    }

    swc_OGVL_ARID_DEF.Delay2_DSTATE[29] = rtb_DataTypeConversion16;

    /* End of Update for Delay: '<S4>/Delay2' */

    /* Update for UnitDelay: '<S9>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_h = vsld_v_dstSpdLim_kph;

    /* Switch: '<S22>/Switch' */
    if (rtb_DataTypeConversion7_g) {
      /* Update for UnitDelay: '<S22>/Unit Delay' incorporates:
       *  Constant: '<S22>/Constant5'
       */
      swc_OGVL_ARID_DEF.UnitDelay_DSTATE_lx = ((uint8)1U);
    } else {
      /* Update for UnitDelay: '<S22>/Unit Delay' */
      swc_OGVL_ARID_DEF.UnitDelay_DSTATE_lx = rtb_DataTypeConversion19;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Update for UnitDelay: '<S22>/Unit Delay1' */
    swc_OGVL_ARID_DEF.UnitDelay1_DSTATE = swc_OGVL_ARID_DEF.Switch2;

    /* Update for UnitDelay: '<S5>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_p = swc_OGVL_ARID_DEF.Switch1;

    /* Update for UnitDelay: '<S5>/Unit Delay1' */
    swc_OGVL_ARID_DEF.UnitDelay1_DSTATE_n = swc_OGVL_ARID_DEF.Switch3;

    /* Update for UnitDelay: '<S5>/Unit Delay2' */
    swc_OGVL_ARID_DEF.UnitDelay2_DSTATE = swc_OGVL_ARID_DEF.Switch5;

    /* Update for UnitDelay: '<S5>/Unit Delay3' */
    swc_OGVL_ARID_DEF.UnitDelay3_DSTATE = swc_OGVL_ARID_DEF.Switch8;

    /* Update for UnitDelay: '<S5>/Unit Delay6' */
    swc_OGVL_ARID_DEF.UnitDelay6_DSTATE = swc_OGVL_ARID_DEF.Switch17;
  } else if (swc_OGVL_ARID_DEF.DstSpeedLimit_MODE) {
    /* Disable for Switch: '<S5>/Switch12' incorporates:
     *  Outport: '<S2>/vsld_st_LockVehPer'
     */
    swc_OGVL_ARID_DEF.vsld_st_LockVehPer = ((uint8)3U);

    /* Disable for SignalConversion: '<S5>/Signal Conversion' incorporates:
     *  Outport: '<S2>/vsld_st_VersionConversion'
     */
    swc_OGVL_ARID_DEF.vsld_st_VersionConversion = true;

    /* Disable for Switch: '<S5>/Switch14' incorporates:
     *  Outport: '<S2>/vsld_st_SpdLmtLevelReq'
     */
    swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq = ((uint8)3U);

    /* Disable for DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
     *  Outport: '<S2>/vsld_st_InventorySpdLmtReq'
     */
    swc_OGVL_ARID_DEF.vsld_st_InventorySpdLmtReq = ((uint8)3U);

    /* Disable for Switch: '<S22>/Switch2' incorporates:
     *  Outport: '<S2>/vsld_st_LifeCnt'
     */
    swc_OGVL_ARID_DEF.Switch2 = ((uint8)0U);

    /* Disable for Switch: '<S9>/Switch3' incorporates:
     *  Outport: '<S2>/vsld_v_dstSpdLim_kph'
     */
    vsld_v_dstSpdLim_kph = ((float32)VEH_SPD_MAX);

    /* Disable for SignalConversion: '<S7>/Signal Conversion' incorporates:
     *  Outport: '<S2>/vsld_b_dstCtrlTqLmt'
     */
    ovgl_dtld_b_dstCtrlTqLmt = false;

    /* Disable for SignalConversion: '<S7>/Signal Conversion1' incorporates:
     *  Outport: '<S2>/vsld_b_dstCtrlTqOff'
     */
    ovgl_dtld_b_dstCtrlTqOff = false;

    /* Disable for Switch: '<S5>/Switch1' incorporates:
     *  Outport: '<S2>/vsld_LockVehPerRxSts'
     */
    swc_OGVL_ARID_DEF.Switch1 = ((uint8)0U);

    /* Disable for Switch: '<S5>/Switch3' incorporates:
     *  Outport: '<S2>/vsld_VersionConversionRxSts'
     */
    swc_OGVL_ARID_DEF.Switch3 = ((uint8)0U);

    /* Disable for Switch: '<S5>/Switch5' incorporates:
     *  Outport: '<S2>/vsld_SpdLmtLevelRxSts'
     */
    swc_OGVL_ARID_DEF.Switch5 = ((uint8)3U);

    /* Disable for Switch: '<S5>/Switch8' incorporates:
     *  Outport: '<S2>/vsld_InventorySpdLmtRxSts'
     */
    swc_OGVL_ARID_DEF.Switch8 = ((uint8)0U);

    /* Disable for Switch: '<S5>/Switch10' incorporates:
     *  Outport: '<S2>/vsld_TBOX_LifeSts'
     */
    swc_OGVL_ARID_DEF.Switch10 = ((uint8)0U);

    /* Disable for Switch: '<S5>/Switch17' incorporates:
     *  Outport: '<S2>/vsld_PowerOffCmdRxSts'
     */
    swc_OGVL_ARID_DEF.Switch17 = ((uint8)0U);

    /* Disable for DataTypeConversion: '<S5>/Data Type Conversion2' incorporates:
     *  Outport: '<S2>/vsld_PowerOffCmdSts'
     */
    swc_OGVL_ARID_DEF.vsld_PowerOffCmdSts = ((uint8)0U);
    swc_OGVL_ARID_DEF.DstSpeedLimit_MODE = false;
  }

  /* End of RelationalOperator: '<S1>/Relational Operator6' */
  /* End of Outputs for SubSystem: '<S1>/DstSpeedLimit' */

  /* Outport generated from: '<Root>/Bus Element Out' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_lockVehPer
    (swc_OGVL_ARID_DEF.vsld_st_LockVehPer);

  /* Outport generated from: '<Root>/Bus Element Out1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_versionConversion
    (swc_OGVL_ARID_DEF.vsld_st_VersionConversion);

  /* Outport generated from: '<Root>/Bus Element Out2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_spdLmtLevelReq
    (swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq);

  /* Outport generated from: '<Root>/Bus Element Out3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_inventorySpdLmtReq
    (swc_OGVL_ARID_DEF.vsld_st_InventorySpdLmtReq);

  /* Outport generated from: '<Root>/Bus Element Out4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_lifeCnt(swc_OGVL_ARID_DEF.Switch2);

  /* Outport generated from: '<Root>/Bus Element Out5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_v_dstSpdLim_kph(vsld_v_dstSpdLim_kph);

  /* Outport generated from: '<Root>/Bus Element Out6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_tboxLifeSts
    (swc_OGVL_ARID_DEF.Switch10);

  /* Outport generated from: '<Root>/Bus Element Out7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_lockVehPerRxSts
    (swc_OGVL_ARID_DEF.Switch1);

  /* Outport generated from: '<Root>/Bus Element Out8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_verCvsRxSts
    (swc_OGVL_ARID_DEF.Switch3);

  /* Outport generated from: '<Root>/Bus Element Out9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_spdLmtLvRxSts
    (swc_OGVL_ARID_DEF.Switch5);

  /* Outport generated from: '<Root>/Bus Element Out10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_invSpdLmtRxSts
    (swc_OGVL_ARID_DEF.Switch8);

  /* Outport generated from: '<Root>/Bus Element Out11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion17'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_pwrOffCmdRxSts
    (swc_OGVL_ARID_DEF.Switch17);

  /* Outport generated from: '<Root>/Bus Element Out12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion18'
   */
  Rte_IWrite_swc_OGVL_Step_vcsb_OGVL_dtld_st_pwrOffCmd
    (swc_OGVL_ARID_DEF.vsld_PowerOffCmdSts);
}

/* Model initialize function */
void swc_OGVL_Init(void)
{
  {
    /* local block i/o variables */
    boolean rtb_flg_out;
    boolean rtb_flg_out_g;
    boolean rtb_flg_out_n;
    boolean rtb_flg_out_m;
    boolean rtb_flg_out_o;
    boolean rtb_flg_out_m5;
    boolean rtb_flg_out_b;
    boolean rtb_flg_out_h;
    boolean rtb_flg_out_l;
    boolean rtb_flg_out_c;
    boolean rtb_flg_out_a;
    boolean rtb_flg_out_hy;
    boolean rtb_flg_out_cd;
    boolean rtb_flg_out_e;
    boolean rtb_flg_out_gp;

    /* SystemInitialize for Atomic SubSystem: '<S3>/turnON_delay' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out);

    /* End of SystemInitialize for SubSystem: '<S3>/turnON_delay' */

    /* SystemInitialize for Enabled SubSystem: '<S1>/DstSpeedLimit' */
    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
    swc_OGVL_ARID_DEF.UnitDelay_DSTATE_h = ((float32)VEH_SPD_MAX);

    /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
    swc_OGVL_ARID_DEF.UnitDelay2_DSTATE = ((uint8)3U);

    /* SystemInitialize for Atomic SubSystem: '<S4>/turnON_delay3' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_gp);

    /* End of SystemInitialize for SubSystem: '<S4>/turnON_delay3' */

    /* SystemInitialize for Atomic SubSystem: '<S7>/turnON_delay4' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_g);

    /* End of SystemInitialize for SubSystem: '<S7>/turnON_delay4' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/turnON_delay4' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_e);

    /* End of SystemInitialize for SubSystem: '<S4>/turnON_delay4' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_cd);

    /* End of SystemInitialize for SubSystem: '<S23>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S26>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_c);

    /* End of SystemInitialize for SubSystem: '<S26>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S27>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_l);

    /* End of SystemInitialize for SubSystem: '<S27>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S28>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_h);

    /* End of SystemInitialize for SubSystem: '<S28>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S29>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_b);

    /* End of SystemInitialize for SubSystem: '<S29>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S30>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_m5);

    /* End of SystemInitialize for SubSystem: '<S30>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S31>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_o);

    /* End of SystemInitialize for SubSystem: '<S31>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S32>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_m);

    /* End of SystemInitialize for SubSystem: '<S32>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S33>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_n);

    /* End of SystemInitialize for SubSystem: '<S33>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S24>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_hy);

    /* End of SystemInitialize for SubSystem: '<S24>/turnON_delay1' */

    /* SystemInitialize for Atomic SubSystem: '<S25>/turnON_delay1' */
    swc_OGVL_turnON_delay3_Init(&rtb_flg_out_a);

    /* End of SystemInitialize for SubSystem: '<S25>/turnON_delay1' */

    /* SystemInitialize for Switch: '<S5>/Switch12' incorporates:
     *  Outport: '<S2>/vsld_st_LockVehPer'
     */
    swc_OGVL_ARID_DEF.vsld_st_LockVehPer = ((uint8)3U);

    /* SystemInitialize for SignalConversion: '<S5>/Signal Conversion' incorporates:
     *  Outport: '<S2>/vsld_st_VersionConversion'
     */
    swc_OGVL_ARID_DEF.vsld_st_VersionConversion = true;

    /* SystemInitialize for Switch: '<S5>/Switch14' incorporates:
     *  Outport: '<S2>/vsld_st_SpdLmtLevelReq'
     */
    swc_OGVL_ARID_DEF.vsld_st_SpdLmtLevelReq = ((uint8)3U);

    /* SystemInitialize for DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
     *  Outport: '<S2>/vsld_st_InventorySpdLmtReq'
     */
    swc_OGVL_ARID_DEF.vsld_st_InventorySpdLmtReq = ((uint8)3U);

    /* SystemInitialize for Switch: '<S9>/Switch3' incorporates:
     *  Outport: '<S2>/vsld_v_dstSpdLim_kph'
     */
    vsld_v_dstSpdLim_kph = ((float32)VEH_SPD_MAX);

    /* SystemInitialize for Switch: '<S5>/Switch5' incorporates:
     *  Outport: '<S2>/vsld_SpdLmtLevelRxSts'
     */
    swc_OGVL_ARID_DEF.Switch5 = ((uint8)3U);

    /* End of SystemInitialize for SubSystem: '<S1>/DstSpeedLimit' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
