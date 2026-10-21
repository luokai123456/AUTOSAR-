/*
 * File: McuFunSafeMonitor.h
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

#ifndef RTW_HEADER_McuFunSafeMonitor_h_
#define RTW_HEADER_McuFunSafeMonitor_h_
#ifndef McuFunSafeMonitor_COMMON_INCLUDES_
#define McuFunSafeMonitor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* McuFunSafeMonitor_COMMON_INCLUDES_ */

#include "McuFunSafeMonitor_types.h"
#include "Hal_ReadDcLinkVoltMeasAD.h"
#include "Hal_ReadMotorTempAdc.h"
#include "Hal_ReadPwrChipVolt.h"
#include "Hal_ReadSinNegHigh.h"
#include "Hal_ReadCosNegHigh.h"
#include "Hal_ReadMotorTempAdcBkUp.h"
#include "Hal_ReadCosNegLow.h"
#include "Hal_ReadCosPosiHigh.h"
#include "Hal_ReadCosPosiLow.h"
#include "Hal_ReadExcNegHigh.h"
#include "Hal_ReadExcNegLow.h"
#include "Hal_ReadExcPosiHigh.h"
#include "Hal_ReadExcPosiLow.h"
#include "Hal_ReadPhaseACurrentAD.h"
#include "Hal_ReadPhaseCCurrentAD.h"
#include "Hal_ReadSinNegLow.h"
#include "Hal_ReadSinPosiLow.h"
#include "Hal_ReadSinPosiHigh.h"
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
  real32_T Add1;                       /* '<S94>/Add1' */
  uint8_T DataTypeConversion;          /* '<S107>/Data Type Conversion' */
  uint8_T DataTypeConversion_m;        /* '<S95>/Data Type Conversion' */
  uint8_T DataTypeConversion_n;        /* '<S98>/Data Type Conversion' */
  uint8_T DataTypeConversion_p;        /* '<S99>/Data Type Conversion' */
  uint8_T DataTypeConversion_f;        /* '<S100>/Data Type Conversion' */
  uint8_T DataTypeConversion_o;        /* '<S101>/Data Type Conversion' */
  uint8_T DataTypeConversion_fo;       /* '<S103>/Data Type Conversion' */
  uint8_T DataTypeConversion_e;        /* '<S104>/Data Type Conversion' */
  uint8_T DataTypeConversion_ee;       /* '<S108>/Data Type Conversion' */
  uint8_T OutportBufferForMFSM_SineDiffFault;
  uint8_T OutportBufferForMFSM_CosDiffFault;
  uint8_T DataTypeConversion_oi;       /* '<S96>/Data Type Conversion' */
  uint8_T DataTypeConversion_l;        /* '<S97>/Data Type Conversion' */
  uint8_T DataTypeConversion_d;        /* '<S105>/Data Type Conversion' */
  uint8_T DataTypeConversion_j;        /* '<S106>/Data Type Conversion' */
  uint8_T DataTypeConversion_dg;       /* '<S109>/Data Type Conversion' */
  uint8_T DataTypeConversion_eb;       /* '<S110>/Data Type Conversion' */
  uint8_T DataTypeConversion_c;        /* '<S9>/Data Type Conversion' */
  uint8_T DataTypeConversion_lp;       /* '<S13>/Data Type Conversion' */
  uint8_T DataTypeConversion_cs;       /* '<S14>/Data Type Conversion' */
  uint8_T DataTypeConversion_dm;       /* '<S7>/Data Type Conversion' */
  uint8_T DataTypeConversion_c3;       /* '<S11>/Data Type Conversion' */
  uint8_T DataTypeConversion_p0;       /* '<S12>/Data Type Conversion' */
  uint8_T DataTypeConversion_ld;       /* '<S10>/Data Type Conversion' */
} B_McuFunSafeMonitor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S114>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S114>/Delay1' */
  real32_T Delay2_DSTATE;              /* '<S114>/Delay2' */
  real32_T Delay_DSTATE_h;             /* '<S112>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S111>/Unit Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<S111>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S111>/Unit Delay1' */
  real32_T Delay_DSTATE_b;             /* '<S300>/Delay' */
  uint16_T UnitDelay_DSTATE_p;         /* '<S90>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_o;         /* '<S3>/Unit Delay' */
  uint8_T BareUnitDelay_DSTATE;        /* '<S269>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_p;      /* '<S132>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_n;      /* '<S159>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_l;      /* '<S175>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_n5;     /* '<S185>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_lf;     /* '<S194>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_k;      /* '<S221>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_h;      /* '<S233>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_m;      /* '<S281>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_a;      /* '<S141>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_o;      /* '<S150>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_kb;     /* '<S246>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_e;      /* '<S256>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_hu;     /* '<S290>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_pa;     /* '<S299>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_j;      /* '<S38>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_k3;     /* '<S78>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_ov;     /* '<S89>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_jy;     /* '<S24>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_md;     /* '<S58>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_b;      /* '<S68>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_d;      /* '<S48>/Bare Unit Delay' */
  boolean_T Memory_PreviousInput;      /* '<S268>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S131>/Memory' */
  boolean_T Memory_PreviousInput_h;    /* '<S158>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S174>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S184>/Memory' */
  boolean_T Memory_PreviousInput_mz;   /* '<S193>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S220>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S232>/Memory' */
  boolean_T Memory_PreviousInput_hq;   /* '<S280>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S140>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S149>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S245>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S255>/Memory' */
  boolean_T Memory_PreviousInput_ig;   /* '<S289>/Memory' */
  boolean_T Memory_PreviousInput_fa;   /* '<S298>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S37>/Memory' */
  boolean_T Memory_PreviousInput_eb;   /* '<S77>/Memory' */
  boolean_T Memory_PreviousInput_o3;   /* '<S88>/Memory' */
  boolean_T Memory_PreviousInput_fx;   /* '<S23>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S57>/Memory' */
  boolean_T Memory_PreviousInput_c3;   /* '<S67>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S47>/Memory' */
} DW_McuFunSafeMonitor_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean_T DataTypeConversion1; /* '<S107>/Data Type Conversion1' */
  const boolean_T LogicalOperator1;    /* '<S269>/Logical Operator1' */
  const boolean_T DataTypeConversion1_m;/* '<S95>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_f;  /* '<S132>/Logical Operator1' */
  const boolean_T DataTypeConversion1_j;/* '<S98>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_o;  /* '<S159>/Logical Operator1' */
  const boolean_T DataTypeConversion1_p;/* '<S99>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_l;  /* '<S175>/Logical Operator1' */
  const boolean_T DataTypeConversion1_jr;/* '<S100>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_m;  /* '<S185>/Logical Operator1' */
  const boolean_T DataTypeConversion1_g;/* '<S101>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_g;  /* '<S194>/Logical Operator1' */
  const boolean_T DataTypeConversion1_md;/* '<S103>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_e;  /* '<S221>/Logical Operator1' */
  const boolean_T DataTypeConversion1_gu;/* '<S104>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_mt; /* '<S233>/Logical Operator1' */
  const boolean_T DataTypeConversion1_f;/* '<S108>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_f2; /* '<S281>/Logical Operator1' */
  const boolean_T DataTypeConversion1_h;/* '<S96>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_g0; /* '<S141>/Logical Operator1' */
  const boolean_T DataTypeConversion1_o;/* '<S97>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_k;  /* '<S150>/Logical Operator1' */
  const boolean_T DataTypeConversion1_n;/* '<S105>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_p;  /* '<S246>/Logical Operator1' */
  const boolean_T DataTypeConversion1_h5;/* '<S106>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_n;  /* '<S256>/Logical Operator1' */
  const boolean_T DataTypeConversion1_l;/* '<S109>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_mx; /* '<S290>/Logical Operator1' */
  const boolean_T DataTypeConversion1_b;/* '<S110>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_ov; /* '<S299>/Logical Operator1' */
  const boolean_T DataTypeConversion1_c;/* '<S9>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_n4; /* '<S38>/Logical Operator1' */
  const boolean_T DataTypeConversion1_n2;/* '<S13>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_fw; /* '<S78>/Logical Operator1' */
  const boolean_T DataTypeConversion1_pu;/* '<S14>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_lm; /* '<S89>/Logical Operator1' */
  const boolean_T DataTypeConversion1_ne;/* '<S7>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_b;  /* '<S24>/Logical Operator1' */
  const boolean_T DataTypeConversion1_nb;/* '<S11>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_fl; /* '<S58>/Logical Operator1' */
  const boolean_T DataTypeConversion1_d;/* '<S12>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_pw; /* '<S68>/Logical Operator1' */
  const boolean_T DataTypeConversion1_ls;/* '<S10>/Data Type Conversion1' */
  const boolean_T LogicalOperator1_h;  /* '<S48>/Logical Operator1' */
} ConstB_McuFunSafeMonitor_T;

/* Real-time Model Data Structure */
struct tag_RTM_McuFunSafeMonitor_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_McuFunSafeMonitor_T McuFunSafeMonitor_B;

/* Block states (default storage) */
extern DW_McuFunSafeMonitor_T McuFunSafeMonitor_DW;
extern const ConstB_McuFunSafeMonitor_T McuFunSafeMonitor_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void McuFunSafeMonitor_initialize(void);
extern void McuFunSafeMonitor_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void MFSM_FuncSafetyRedundancy_1ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void MFSM_FuncSafetyRedundancy_96us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile real32_T MFSM_BusCurrentCompCoeff_M[3];
                          /* Referenced by: '<S115>/Bus Current Coeff Lookup' */
extern volatile real32_T MFSM_BusCurrentComp_M[3];
             /* Referenced by: '<S116>/Bus Current Compensation Lookup Table' */
extern volatile real32_T MFSM_ElecSpd_A[3];/* Referenced by: '<S111>/Prelookup' */
extern volatile real32_T MFSM_LpfBusCurrent_A[3];/* Referenced by: '<S116>/Prelookup1' */
extern volatile real32_T MFSM_MechSpd_A[3];/* Referenced by: '<S115>/Prelookup' */
extern volatile real32_T MFSM_MtrEfficiency_M[3];
                       /* Referenced by: '<S111>/Mtr Efficiency Lookup Table' */

#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T MFSM_AmpHigh_C;/* Referenced by: '<S266>/Constant' */
extern volatile real32_T MFSM_AmpLow_C;/* Referenced by: '<S265>/Constant' */
extern volatile real32_T MFSM_BusCurDiff_C;/* Referenced by: '<S17>/Constant' */
extern volatile uint8_T MFSM_BusCurrentCalCoeffSel_C;/* Referenced by: '<S119>/Constant' */
extern volatile real32_T MFSM_BusCurrentCalCoeff_C;/* Referenced by: '<S118>/Constant' */
extern volatile uint8_T MFSM_BusCurrentCompEna_C;/* Referenced by: '<S120>/Constant' */
extern volatile real32_T MFSM_BusCurrentFilterFreq_C;/* Referenced by: '<S113>/Constant' */
extern volatile real32_T MFSM_CosShortGndValue_C;/* Referenced by: '<S134>/Constant' */
extern volatile real32_T MFSM_CosShortPwrValue_C;/* Referenced by: '<S143>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrBusCurDiff_C;/* Referenced by: '<S20>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrCosOpen_C;/* Referenced by: '<S127>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrCosShortGnd_C;/* Referenced by: '<S137>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrCosShortPwr_C;/* Referenced by: '<S146>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrExcAmp_C;/* Referenced by: '<S154>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrExcOpen_C;/* Referenced by: '<S170>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrExcShortGnd_C;/* Referenced by:
                                                        * '<S180>/Constant'
                                                        * '<S189>/Constant'
                                                        */
extern volatile uint8_T MFSM_DebounceDecrHighVolt_C;/* Referenced by: '<S34>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrMtrTempShortGnd_C;/* Referenced by: '<S53>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrMtrTempShortPwr_C;/* Referenced by: '<S63>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrMtrTemp_C;/* Referenced by: '<S43>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrOpen_C;/* Referenced by: '<S228>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrPhaCurrDiff_C;/* Referenced by: '<S216>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrPhaCurrOpen_C;/* Referenced by: '<S241>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrPhaCurrShortPwr_C;/* Referenced by: '<S251>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrRslvrAmp_C;/* Referenced by: '<S262>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrSensorVolt_C;/* Referenced by: '<S74>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrSinOpen_C;/* Referenced by: '<S276>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrSinShortGnd_C;/* Referenced by: '<S286>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrSinShortPwr_C;/* Referenced by: '<S295>/Constant' */
extern volatile uint8_T MFSM_DebounceDecrTqDiff_C;/* Referenced by: '<S84>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrBusCurDiff_C;/* Referenced by: '<S19>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrCosOpen_C;/* Referenced by: '<S126>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrCosShortGnd_C;/* Referenced by: '<S136>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrCosShortPwr_C;/* Referenced by: '<S145>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrExcAmp_C;/* Referenced by: '<S153>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrExcOpen_C;/* Referenced by: '<S169>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrExcShortGnd_C;/* Referenced by:
                                                        * '<S179>/Constant'
                                                        * '<S188>/Constant'
                                                        */
extern volatile uint8_T MFSM_DebounceIncrHighVolt_C;/* Referenced by: '<S33>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrMtrTempShortGnd_C;/* Referenced by: '<S52>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrMtrTempShortPwr_C;/* Referenced by: '<S62>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrMtrTemp_C;/* Referenced by: '<S42>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrOpen_C;/* Referenced by: '<S227>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrPhaCurrDiff_C;/* Referenced by: '<S215>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrPhaCurrOpen_C;/* Referenced by: '<S240>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrPhaCurrShortPwr_C;/* Referenced by: '<S250>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrRslvrAmp_C;/* Referenced by: '<S261>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrSensorVolt_C;/* Referenced by: '<S73>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrSinOpen_C;/* Referenced by: '<S275>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrSinShortGnd_C;/* Referenced by: '<S285>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrSinShortPwr_C;/* Referenced by: '<S294>/Constant' */
extern volatile uint8_T MFSM_DebounceIncrTqDiff_C;/* Referenced by: '<S83>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxBusCurDiff_C;/* Referenced by: '<S18>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxCosOpen_C;/* Referenced by: '<S125>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxCosShortGnd_C;/* Referenced by: '<S135>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxCosShortPwr_C;/* Referenced by: '<S144>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxExcAmp_C;/* Referenced by: '<S152>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxExcOpen_C;/* Referenced by: '<S168>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxExcShortGnd_C;/* Referenced by:
                                                       * '<S178>/Constant'
                                                       * '<S187>/Constant'
                                                       */
extern volatile uint8_T MFSM_DebounceMaxHighVolt_C;/* Referenced by: '<S32>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxMtrTempShortGnd_C;/* Referenced by: '<S51>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxMtrTempShortPwr_C;/* Referenced by: '<S61>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxMtrTemp_C;/* Referenced by: '<S41>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxOpen_C;/* Referenced by: '<S226>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxPhaCurrDiff_C;/* Referenced by: '<S214>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxPhaCurrOpen_C;/* Referenced by: '<S239>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxPhaCurrShortPwr_C;/* Referenced by: '<S249>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxRslvrAmp_C;/* Referenced by: '<S260>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxSensorVolt_C;/* Referenced by: '<S72>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxSinOpen_C;/* Referenced by: '<S274>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxSinShortGnd_C;/* Referenced by: '<S284>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxSinShortPwr_C;/* Referenced by: '<S293>/Constant' */
extern volatile uint8_T MFSM_DebounceMaxTqDiff_C;/* Referenced by: '<S82>/Constant' */
extern volatile uint8_T MFSM_DebounceMinBusCurDiff_C;/* Referenced by: '<S21>/Constant' */
extern volatile uint8_T MFSM_DebounceMinCosOpen_C;/* Referenced by: '<S128>/Constant' */
extern volatile uint8_T MFSM_DebounceMinCosShortGnd_C;/* Referenced by: '<S138>/Constant' */
extern volatile uint8_T MFSM_DebounceMinCosShortPwr_C;/* Referenced by: '<S147>/Constant' */
extern volatile uint8_T MFSM_DebounceMinExcAmp_C;/* Referenced by: '<S155>/Constant' */
extern volatile uint8_T MFSM_DebounceMinExcOpen_C;/* Referenced by: '<S171>/Constant' */
extern volatile uint8_T MFSM_DebounceMinExcShortGnd_C;/* Referenced by:
                                                       * '<S181>/Constant'
                                                       * '<S190>/Constant'
                                                       */
extern volatile uint8_T MFSM_DebounceMinHighVolt_C;/* Referenced by: '<S35>/Constant' */
extern volatile uint8_T MFSM_DebounceMinMtrTempShortGnd_C;/* Referenced by: '<S54>/Constant' */
extern volatile uint8_T MFSM_DebounceMinMtrTempShortPwr_C;/* Referenced by: '<S64>/Constant' */
extern volatile uint8_T MFSM_DebounceMinMtrTemp_C;/* Referenced by: '<S44>/Constant' */
extern volatile uint8_T MFSM_DebounceMinOpen_C;/* Referenced by: '<S229>/Constant' */
extern volatile uint8_T MFSM_DebounceMinPhaCurrDiff_C;/* Referenced by: '<S217>/Constant' */
extern volatile uint8_T MFSM_DebounceMinPhaCurrOpen_C;/* Referenced by: '<S242>/Constant' */
extern volatile uint8_T MFSM_DebounceMinPhaCurrShortPwr_C;/* Referenced by: '<S252>/Constant' */
extern volatile uint8_T MFSM_DebounceMinRslvrAmp_C;/* Referenced by: '<S263>/Constant' */
extern volatile uint8_T MFSM_DebounceMinSensorVolt_C;/* Referenced by: '<S75>/Constant' */
extern volatile uint8_T MFSM_DebounceMinSinOpen_C;/* Referenced by: '<S277>/Constant' */
extern volatile uint8_T MFSM_DebounceMinSinShortGnd_C;/* Referenced by: '<S287>/Constant' */
extern volatile uint8_T MFSM_DebounceMinSinShortPwr_C;/* Referenced by: '<S296>/Constant' */
extern volatile uint8_T MFSM_DebounceMinTqDiff_C;/* Referenced by: '<S85>/Constant' */
extern volatile real32_T MFSM_ExcMaxHighValue_C;/* Referenced by: '<S163>/Constant' */
extern volatile real32_T MFSM_ExcMaxLowValue_C;/* Referenced by: '<S162>/Constant' */
extern volatile real32_T MFSM_ExcMinHighValue_C;/* Referenced by: '<S165>/Constant' */
extern volatile real32_T MFSM_ExcMinLowValue_C;/* Referenced by: '<S164>/Constant' */
extern volatile real32_T MFSM_ExcOpenValue_C;/* Referenced by: '<S172>/Constant' */
extern volatile real32_T MFSM_ExcShortGndValue_C;/* Referenced by:
                                                  * '<S182>/Constant'
                                                  * '<S198>/Constant'
                                                  */
extern volatile real32_T MFSM_ExcShortPwrValue_C;/* Referenced by: '<S197>/Constant' */
extern volatile uint16_T MFSM_FastDiagInitTimeCount_C;/* Referenced by: '<S92>/Constant' */
extern volatile real32_T MFSM_HighVoltDiff_C;/* Referenced by: '<S31>/Constant' */
extern volatile real32_T MFSM_MaxCosOpenValue_C;/* Referenced by: '<S129>/Constant' */
extern volatile real32_T MFSM_MaxSinOpenValue_C;/* Referenced by: '<S278>/Constant' */
extern volatile real32_T MFSM_MinCosOpenValue_C;/* Referenced by: '<S124>/Constant' */
extern volatile real32_T MFSM_MinSinOpenValue_C;/* Referenced by: '<S273>/Constant' */
extern volatile real32_T MFSM_MtrTempSensorNShortGnd_C;/* Referenced by: '<S55>/Constant' */
extern volatile real32_T MFSM_MtrTempSensorNShortPwr_C;/* Referenced by: '<S65>/Constant' */
extern volatile real32_T MFSM_MtrTempSensorPShortGnd_C;/* Referenced by: '<S50>/Constant' */
extern volatile real32_T MFSM_MtrTempSensorPShortPwr_C;/* Referenced by: '<S60>/Constant' */
extern volatile real32_T MFSM_MtrTempSensorShortGnd_C;/* Referenced by: '<S45>/Constant' */
extern volatile real32_T MFSM_MtrTempSensorShortPwr_C;/* Referenced by: '<S40>/Constant' */
extern volatile real32_T MFSM_PhaCurrDiffValue_C;/* Referenced by: '<S224>/Constant' */
extern volatile real32_T MFSM_PhaCurrOpenDiffValue_C;/* Referenced by: '<S237>/Constant' */
extern volatile real32_T MFSM_PhaCurrOpenValue_C;/* Referenced by: '<S236>/Constant' */
extern volatile real32_T MFSM_PhaCurrShortGndValue_C;/* Referenced by: '<S247>/Constant' */
extern volatile real32_T MFSM_PhaCurrShortPwrValue_C;/* Referenced by: '<S257>/Constant' */
extern volatile real32_T MFSM_SensorVoltDiff_C;/* Referenced by: '<S71>/Constant' */
extern volatile real32_T MFSM_SinShortGndValue_C;/* Referenced by: '<S283>/Constant' */
extern volatile real32_T MFSM_SinShortPwrValue_C;/* Referenced by: '<S292>/Constant' */
extern volatile uint16_T MFSM_SlowDiagInitTimeCount_C;/* Referenced by: '<S5>/Constant' */
extern volatile real32_T MFSM_TorqueDiff_C;/* Referenced by: '<S81>/Constant' */
extern volatile real32_T MFSM_TorqueFilterFreq_C;/* Referenced by: '<S301>/Constant' */

#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T MFSM_BusCurDiff;
extern uint8_T MFSM_BusCurrentDiffFualt;/* '<S1>/Subsystem' */
extern real32_T MFSM_BusCurrentLpfVal; /* '<S2>/Subsystem' */
extern real32_T MFSM_CosDiff;
extern uint8_T MFSM_CosDiffFault;      /* '<S2>/Subsystem' */
extern real32_T MFSM_CosNegHigh;
extern real32_T MFSM_CosNegLow;
extern uint8_T MFSM_CosOpenFault;      /* '<S2>/Subsystem' */
extern real32_T MFSM_CosPosHigh;
extern real32_T MFSM_CosPosLow;
extern uint8_T MFSM_CosShortGndFault;  /* '<S2>/Subsystem' */
extern uint8_T MFSM_CosShortPwrFault;  /* '<S2>/Subsystem' */
extern real32_T MFSM_CosSum;
extern real32_T MFSM_DcVolt;
extern real32_T MFSM_DcVoltDiff;
extern real32_T MFSM_ExcAmpAve;
extern uint8_T MFSM_ExcAmpFault;       /* '<S2>/Subsystem' */
extern real32_T MFSM_ExcAveVal;
extern real32_T MFSM_ExcDiffHigh;
extern real32_T MFSM_ExcDiffLow;
extern real32_T MFSM_ExcNegHigh;
extern real32_T MFSM_ExcNegLow;
extern uint8_T MFSM_ExcOpenFault;      /* '<S2>/Subsystem' */
extern real32_T MFSM_ExcPosHigh;
extern real32_T MFSM_ExcPosLow;
extern uint8_T MFSM_ExcShortGndFault;  /* '<S2>/Subsystem' */
extern uint8_T MFSM_ExcShortPwrFault;  /* '<S2>/Subsystem' */
extern real32_T MFSM_ExcShortPwr_Max;
extern real32_T MFSM_ExcShortPwr_Min;
extern real32_T MFSM_FunSafetyTorque;  /* '<S2>/Subsystem' */
extern uint8_T MFSM_HighVoltFault;     /* '<S1>/Subsystem' */
extern uint8_T MFSM_MtrTempFault;      /* '<S1>/Subsystem' */
extern real32_T MFSM_MtrTempNVolt;
extern real32_T MFSM_MtrTempPVolt;
extern uint8_T MFSM_MtrTempShortGndFault;/* '<S1>/Subsystem' */
extern uint8_T MFSM_MtrTempShortPwrFault;/* '<S1>/Subsystem' */
extern uint8_T MFSM_PhaCurrDiffFault;  /* '<S2>/Subsystem' */
extern uint8_T MFSM_PhaCurrOpenFault;  /* '<S2>/Subsystem' */
extern uint8_T MFSM_PhaCurrShortGndFault;/* '<S2>/Subsystem' */
extern uint8_T MFSM_PhaCurrShortPwrFault;/* '<S2>/Subsystem' */
extern real32_T MFSM_PhaseA;
extern real32_T MFSM_PhaseACurrentDiff;
extern real32_T MFSM_PhaseADiff;
extern real32_T MFSM_PhaseBCurrent;
extern real32_T MFSM_PhaseC;
extern real32_T MFSM_PhaseCCurrentDiff;
extern real32_T MFSM_PhaseCDiff;
extern real32_T MFSM_PwrChipVoltDiff;
extern real32_T MFSM_PwrChipVoltValue;
extern uint8_T MFSM_RslvrAmpFault;     /* '<S2>/Subsystem' */
extern real32_T MFSM_RslvrAmpSum;
extern uint8_T MFSM_SensorVoltFault;   /* '<S1>/Subsystem' */
extern real32_T MFSM_SinDiff;
extern real32_T MFSM_SinNegHigh;
extern real32_T MFSM_SinNegLow;
extern uint8_T MFSM_SinOpenFault;      /* '<S2>/Subsystem' */
extern real32_T MFSM_SinPosHigh;
extern real32_T MFSM_SinPosLow;
extern uint8_T MFSM_SinShortGndFault;  /* '<S2>/Subsystem' */
extern uint8_T MFSM_SinShortPwrFault;  /* '<S2>/Subsystem' */
extern real32_T MFSM_SinSum;
extern uint8_T MFSM_SineDiffFault;     /* '<S2>/Subsystem' */
extern real32_T MFSM_TqDiff;
extern uint8_T MFSM_TqDiffFualt;       /* '<S1>/Subsystem' */

#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_McuFunSafeMonitor_T *const McuFunSafeMonitor_M;

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
 * '<Root>' : 'McuFunSafeMonitor'
 * '<S1>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys'
 * '<S2>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys'
 * '<S3>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/EnSlowDiag'
 * '<S4>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem'
 * '<S5>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/EnSlowDiag/Parameter'
 * '<S6>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/EnSlowDiag/Saturation Dynamic'
 * '<S7>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault'
 * '<S8>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/Function Caller'
 * '<S9>'   : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk'
 * '<S10>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk'
 * '<S11>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd'
 * '<S12>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr'
 * '<S13>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk'
 * '<S14>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault'
 * '<S15>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/FaultDebounce'
 * '<S16>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/Local Variable Storage1'
 * '<S17>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/Parameter1'
 * '<S18>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/Parameter2'
 * '<S19>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/Parameter3'
 * '<S20>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/Parameter4'
 * '<S21>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/Parameter5'
 * '<S22>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/FaultDebounce/Saturation Dynamic'
 * '<S23>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/FaultDebounce/Subsystem'
 * '<S24>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/BusCurrentDeviationFault/FaultDebounce/UnitDelay'
 * '<S25>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/Function Caller/Local Variable Storage1'
 * '<S26>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/Function Caller/Local Variable Storage17'
 * '<S27>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/Function Caller/Local Variable Storage2'
 * '<S28>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/Function Caller/Local Variable Storage3'
 * '<S29>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/FaultDebounce'
 * '<S30>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/Local Variable Storage3'
 * '<S31>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/Parameter1'
 * '<S32>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/Parameter2'
 * '<S33>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/Parameter3'
 * '<S34>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/Parameter4'
 * '<S35>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/Parameter5'
 * '<S36>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/FaultDebounce/Saturation Dynamic'
 * '<S37>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/FaultDebounce/Subsystem'
 * '<S38>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/HighVoltConsistencyChk/FaultDebounce/UnitDelay'
 * '<S39>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/FaultDebounce'
 * '<S40>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/Parameter1'
 * '<S41>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/Parameter2'
 * '<S42>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/Parameter3'
 * '<S43>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/Parameter4'
 * '<S44>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/Parameter5'
 * '<S45>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/Parameter6'
 * '<S46>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/FaultDebounce/Saturation Dynamic'
 * '<S47>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/FaultDebounce/Subsystem'
 * '<S48>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempConsistencyChk/FaultDebounce/UnitDelay'
 * '<S49>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/FaultDebounce'
 * '<S50>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/Parameter1'
 * '<S51>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/Parameter2'
 * '<S52>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/Parameter3'
 * '<S53>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/Parameter4'
 * '<S54>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/Parameter5'
 * '<S55>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/Parameter6'
 * '<S56>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/FaultDebounce/Saturation Dynamic'
 * '<S57>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/FaultDebounce/Subsystem'
 * '<S58>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortGnd/FaultDebounce/UnitDelay'
 * '<S59>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/FaultDebounce'
 * '<S60>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/Parameter1'
 * '<S61>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/Parameter2'
 * '<S62>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/Parameter3'
 * '<S63>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/Parameter4'
 * '<S64>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/Parameter5'
 * '<S65>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/Parameter6'
 * '<S66>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/FaultDebounce/Saturation Dynamic'
 * '<S67>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/FaultDebounce/Subsystem'
 * '<S68>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/MtrTempSensorShortPwr/FaultDebounce/UnitDelay'
 * '<S69>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/FaultDebounce'
 * '<S70>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/Local Variable Storage1'
 * '<S71>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/Parameter1'
 * '<S72>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/Parameter2'
 * '<S73>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/Parameter3'
 * '<S74>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/Parameter4'
 * '<S75>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/Parameter5'
 * '<S76>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/FaultDebounce/Saturation Dynamic'
 * '<S77>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/FaultDebounce/Subsystem'
 * '<S78>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/SensorVoltConsistencyChk/FaultDebounce/UnitDelay'
 * '<S79>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/FaultDebounce'
 * '<S80>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Local Variable Storage1'
 * '<S81>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Parameter1'
 * '<S82>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Parameter2'
 * '<S83>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Parameter3'
 * '<S84>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Parameter4'
 * '<S85>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Parameter5'
 * '<S86>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/Subsystem'
 * '<S87>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/FaultDebounce/Saturation Dynamic'
 * '<S88>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/FaultDebounce/Subsystem'
 * '<S89>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_1ms_sys/Subsystem/TorqueDeviationFault/FaultDebounce/UnitDelay'
 * '<S90>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/EnFastDiag'
 * '<S91>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem'
 * '<S92>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/EnFastDiag/Parameter'
 * '<S93>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/EnFastDiag/Saturation Dynamic'
 * '<S94>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate'
 * '<S95>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt'
 * '<S96>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt'
 * '<S97>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt'
 * '<S98>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt'
 * '<S99>'  : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt'
 * '<S100>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt'
 * '<S101>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt'
 * '<S102>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller'
 * '<S103>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault'
 * '<S104>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen'
 * '<S105>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd'
 * '<S106>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr'
 * '<S107>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt'
 * '<S108>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt'
 * '<S109>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt'
 * '<S110>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt'
 * '<S111>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/TorqueEstimate'
 * '<S112>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/LowPassFilter'
 * '<S113>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/Parameter1'
 * '<S114>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/bus current calculate'
 * '<S115>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/bus current select'
 * '<S116>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/current compensate'
 * '<S117>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/bus current calculate/Local Variable Storage1'
 * '<S118>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/bus current select/Parameter2'
 * '<S119>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/bus current select/Parameter5'
 * '<S120>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/BusCurrentEstimate/current compensate/Parameter3'
 * '<S121>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/FaultDebounce'
 * '<S122>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Local Variable Storage1'
 * '<S123>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Local Variable Storage3'
 * '<S124>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Parameter1'
 * '<S125>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Parameter2'
 * '<S126>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Parameter3'
 * '<S127>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Parameter4'
 * '<S128>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Parameter5'
 * '<S129>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/Parameter6'
 * '<S130>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/FaultDebounce/Saturation Dynamic'
 * '<S131>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/FaultDebounce/Subsystem'
 * '<S132>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosOpenFualt/FaultDebounce/UnitDelay'
 * '<S133>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/FaultDebounce'
 * '<S134>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/Parameter1'
 * '<S135>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/Parameter2'
 * '<S136>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/Parameter3'
 * '<S137>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/Parameter4'
 * '<S138>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/Parameter5'
 * '<S139>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/FaultDebounce/Saturation Dynamic'
 * '<S140>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/FaultDebounce/Subsystem'
 * '<S141>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortGndFualt/FaultDebounce/UnitDelay'
 * '<S142>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/FaultDebounce'
 * '<S143>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/Parameter1'
 * '<S144>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/Parameter2'
 * '<S145>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/Parameter3'
 * '<S146>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/Parameter4'
 * '<S147>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/Parameter5'
 * '<S148>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/FaultDebounce/Saturation Dynamic'
 * '<S149>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/FaultDebounce/Subsystem'
 * '<S150>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/CosSigShortPwrFualt/FaultDebounce/UnitDelay'
 * '<S151>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/FaultDebounce'
 * '<S152>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Parameter2'
 * '<S153>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Parameter3'
 * '<S154>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Parameter4'
 * '<S155>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Parameter5'
 * '<S156>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem'
 * '<S157>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/FaultDebounce/Saturation Dynamic'
 * '<S158>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/FaultDebounce/Subsystem'
 * '<S159>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/FaultDebounce/UnitDelay'
 * '<S160>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem/Local Variable Storage1'
 * '<S161>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem/Local Variable Storage3'
 * '<S162>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem/Parameter1'
 * '<S163>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem/Parameter6'
 * '<S164>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem/Parameter7'
 * '<S165>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcAmpFualt/Subsystem/Parameter8'
 * '<S166>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/FaultDebounce'
 * '<S167>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/Local Variable Storage3'
 * '<S168>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/Parameter2'
 * '<S169>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/Parameter3'
 * '<S170>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/Parameter4'
 * '<S171>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/Parameter5'
 * '<S172>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/Parameter6'
 * '<S173>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/FaultDebounce/Saturation Dynamic'
 * '<S174>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/FaultDebounce/Subsystem'
 * '<S175>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcOpenFualt/FaultDebounce/UnitDelay'
 * '<S176>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/FaultDebounce'
 * '<S177>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/Local Variable Storage3'
 * '<S178>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/Parameter2'
 * '<S179>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/Parameter3'
 * '<S180>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/Parameter4'
 * '<S181>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/Parameter5'
 * '<S182>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/Parameter6'
 * '<S183>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/FaultDebounce/Saturation Dynamic'
 * '<S184>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/FaultDebounce/Subsystem'
 * '<S185>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortGndFualt/FaultDebounce/UnitDelay'
 * '<S186>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/FaultDebounce'
 * '<S187>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Parameter2'
 * '<S188>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Parameter3'
 * '<S189>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Parameter4'
 * '<S190>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Parameter5'
 * '<S191>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Subsystem'
 * '<S192>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/FaultDebounce/Saturation Dynamic'
 * '<S193>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/FaultDebounce/Subsystem'
 * '<S194>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/FaultDebounce/UnitDelay'
 * '<S195>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Subsystem/Local Variable Storage1'
 * '<S196>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Subsystem/Local Variable Storage3'
 * '<S197>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Subsystem/Parameter1'
 * '<S198>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/ExcShortPwrFualt/Subsystem/Parameter6'
 * '<S199>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage10'
 * '<S200>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage11'
 * '<S201>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage12'
 * '<S202>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage13'
 * '<S203>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage14'
 * '<S204>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage15'
 * '<S205>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage16'
 * '<S206>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage3'
 * '<S207>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage4'
 * '<S208>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage5'
 * '<S209>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage6'
 * '<S210>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage7'
 * '<S211>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage8'
 * '<S212>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/Function Caller/Local Variable Storage9'
 * '<S213>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/FaultDebounce'
 * '<S214>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Parameter2'
 * '<S215>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Parameter3'
 * '<S216>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Parameter4'
 * '<S217>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Parameter5'
 * '<S218>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Subsystem'
 * '<S219>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/FaultDebounce/Saturation Dynamic'
 * '<S220>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/FaultDebounce/Subsystem'
 * '<S221>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/FaultDebounce/UnitDelay'
 * '<S222>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Subsystem/Local Variable Storage1'
 * '<S223>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Subsystem/Local Variable Storage3'
 * '<S224>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentAmpFault/Subsystem/Parameter7'
 * '<S225>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/FaultDebounce'
 * '<S226>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Parameter2'
 * '<S227>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Parameter3'
 * '<S228>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Parameter4'
 * '<S229>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Parameter5'
 * '<S230>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Subsystem'
 * '<S231>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/FaultDebounce/Saturation Dynamic'
 * '<S232>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/FaultDebounce/Subsystem'
 * '<S233>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/FaultDebounce/UnitDelay'
 * '<S234>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Subsystem/Local Variable Storage1'
 * '<S235>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Subsystem/Local Variable Storage3'
 * '<S236>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Subsystem/Parameter1'
 * '<S237>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentOpen/Subsystem/Parameter7'
 * '<S238>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/FaultDebounce'
 * '<S239>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/Parameter2'
 * '<S240>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/Parameter3'
 * '<S241>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/Parameter4'
 * '<S242>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/Parameter5'
 * '<S243>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/Subsystem'
 * '<S244>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/FaultDebounce/Saturation Dynamic'
 * '<S245>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/FaultDebounce/Subsystem'
 * '<S246>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/FaultDebounce/UnitDelay'
 * '<S247>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortGnd/Subsystem/Parameter7'
 * '<S248>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/FaultDebounce'
 * '<S249>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/Parameter2'
 * '<S250>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/Parameter3'
 * '<S251>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/Parameter4'
 * '<S252>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/Parameter5'
 * '<S253>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/Subsystem'
 * '<S254>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/FaultDebounce/Saturation Dynamic'
 * '<S255>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/FaultDebounce/Subsystem'
 * '<S256>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/FaultDebounce/UnitDelay'
 * '<S257>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/PhaseCurrrentShortPwr/Subsystem/Parameter7'
 * '<S258>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Fault Determination'
 * '<S259>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/FaultDebounce'
 * '<S260>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Parameter2'
 * '<S261>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Parameter3'
 * '<S262>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Parameter4'
 * '<S263>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Parameter5'
 * '<S264>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Fault Determination/Local Variable Storage1'
 * '<S265>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Fault Determination/Parameter1'
 * '<S266>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/Fault Determination/Parameter6'
 * '<S267>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/FaultDebounce/Saturation Dynamic'
 * '<S268>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/FaultDebounce/Subsystem'
 * '<S269>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/RslvrAmpFualt/FaultDebounce/UnitDelay'
 * '<S270>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/FaultDebounce'
 * '<S271>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Local Variable Storage1'
 * '<S272>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Local Variable Storage3'
 * '<S273>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Parameter1'
 * '<S274>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Parameter2'
 * '<S275>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Parameter3'
 * '<S276>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Parameter4'
 * '<S277>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Parameter5'
 * '<S278>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/Parameter6'
 * '<S279>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/FaultDebounce/Saturation Dynamic'
 * '<S280>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/FaultDebounce/Subsystem'
 * '<S281>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinOpenFualt/FaultDebounce/UnitDelay'
 * '<S282>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/FaultDebounce'
 * '<S283>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/Parameter1'
 * '<S284>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/Parameter2'
 * '<S285>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/Parameter3'
 * '<S286>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/Parameter4'
 * '<S287>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/Parameter5'
 * '<S288>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/FaultDebounce/Saturation Dynamic'
 * '<S289>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/FaultDebounce/Subsystem'
 * '<S290>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortGndFualt/FaultDebounce/UnitDelay'
 * '<S291>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/FaultDebounce'
 * '<S292>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/Parameter1'
 * '<S293>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/Parameter2'
 * '<S294>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/Parameter3'
 * '<S295>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/Parameter4'
 * '<S296>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/Parameter5'
 * '<S297>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/FaultDebounce/Saturation Dynamic'
 * '<S298>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/FaultDebounce/Subsystem'
 * '<S299>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/SinSigShortPwrFualt/FaultDebounce/UnitDelay'
 * '<S300>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/TorqueEstimate/LowPassFilter'
 * '<S301>' : 'McuFunSafeMonitor/MFSM_FuncSafetyRedundancy_96us_sys/Subsystem/TorqueEstimate/Parameter1'
 */
#endif                                 /* RTW_HEADER_McuFunSafeMonitor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
