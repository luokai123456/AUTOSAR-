#ifdef __cplusplus
extern "C" {
#endif
#include "Cdd_Sa47301_Cfg.h"
#include "Cdd_Sa47301_Reg.h"
#include "Cdd_Sa47301_Type.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_CFG_C             4
#define SA47301_AR_REL_MINOR_VER_CFG_C             4
#define SA47301_AR_REL_REV_VER_CFG_C               0
#define SA47301_SW_MAJOR_VER_CFG_C                 1
#define SA47301_SW_MINOR_VER_CFG_C                 0
#define SA47301_SW_PATCH_VER_CFG_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_CFG_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_CFG_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_CFG_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_CFG_C"
#endif
#if (SA47301_AR_REL_REV_VER_CFG_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_CFG_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_CFG_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_CFG_C"
#endif
#if (SA47301_SW_MINOR_VER_CFG_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_CFG_C"
#endif
#if (SA47301_SW_PATCH_VER_CFG_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_CFG_C"
#endif


Cdd_Sa47301DevCfgType_TDSTR SA47301_DevCfg ={
    .WakeTimeEn =              EVPT_CDD_SA_WAKETIME_DISABLED,
    .WakeTimeCyc =             EVPT_CDD_SA_WAKETIME_CYC_PERIOD_1MS,
    .Trdel       =             EVPT_CDD_SA_TRDEL_900US,
    .ResDelayTime=             EVPT_CDD_SA_RESDELAYTIME_200US,
    .CmonEn      =             EVPT_CDD_SA_CMON_DISABLED,
    .Cthr        =             EVPT_CDD_SA_CTHR_10MA,
    .SyncPha     =             EVPT_CDD_SA_SYNCEN_DISABLED,
    .SyncEn      =             EVPT_CDD_SA_SYNCEN_DISABLED,
    .ReqTrk1En   =             EVPT_CDD_SA_REQTRK1_VT1_ENABLED,
    .ReqTrk2En   =             EVPT_CDD_SA_REQTRK2_VT2_ENABLED,
    .ReqComEn    =             EVPT_CDD_SA_REQCOM_VCO_ENABLED,
    .ReqVRefEn   =             EVPT_CDD_SA_REQVREF_VR_ENABLED,
    .ReqState    =             EVPT_CDD_SA_REQSTATE_NONE,
};

Cdd_Sa47301SysCfgType_TDSTR SA47301_SysCfg = {
    .StbyEn =                 EVPT_CDD_SA_STBY_ENABLED,
    .SS2Del =                 EVPT_CDD_SA_SS2DEL_NO_DELAY,
    .ErrMonSleepEn =         EVPT_CDD_SA_ERRMONSLEEP_DISABLED,
    .ErrMonEn =             EVPT_CDD_SA_ERRMON_DISABLED,
    .ErrMonRecEn =             EVPT_CDD_SA_ERRMONREC_DISABLED,
    .ErrMonRecTime =         EVPT_CDD_SA_ERRMONREC_1MS,
};

Cdd_Sa47301WdgCfgType_TDSTR SA47301_WdgCfg = {
    .WinWdgErrCounThr =     9,
    .FunWdgErrCounThr =     9,
    .WinWdgEn =             EVPT_CDD_SA_WINWDG_DISABLED,
    .FunWdgEn =             EVPT_CDD_SA_FUNWDG_ENABLED,
    .WinWdgSrcSel =         EVPT_CDD_SA_WINWDGSRCSEL_SPI_WRITE,
    .WdgCycTime =             EVPT_CDD_SA_WDGCYC_1MS,
    .WdgCycDiv =             EVPT_CDD_SA_WDGCYCDIV_DISABLE,
    .WdgInSleepEn =         EVPT_CDD_SA_WDGINSLP_DISABLED_IN_SLEEP,
    .FunWdgHbTimePeriod =     EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_100WD,
    .WinWdgTmin =             EVPT_CDD_SA_WINWDGTMIN_CW_50WD,
    .WinWdgTmargin =         EVPT_CDD_SA_WINWDGTMARGIN_OW_50WD,
};

Cdd_Sa47301WkTimeCfgType_TDSTR SA47301_WkTimeCfg = {
    .WakeTimeValLowBit =     0,
    .WakeTimeValMidBit =     0,
    .WakeTimeValHigBit =     0,
};

Cdd_Sa47301AbistCfgType_TDSTR SA47301_AbistCfg = {
    .SafetyPath =             EVPT_CDD_SA_ABIST_SAFETYPATH_INTERRUPT,
    .AbistSequence =         EVPT_CDD_SA_ABIST_SINGLE_PREDEFINED,
    .FullPath =             EVPT_CDD_SA_ABIST_FULLPATH_FULL_PATH,
    .StartAbist =             EVPT_CDD_SA_ABIST_STARTABIST_DONE,
    .AbistClkCheckEn =         EVPT_CDD_SA_ABIST_ABISTCLKCHECKEN_ENABLE,
    .OVTrigMonEn =             EVPT_CDD_SA_ABIST_OVTRIGMONEN_ENABLE,
    .OVTrk2 =                 EVPT_CDD_SA_ABIST_OVTRK2_SELECT,
    .OVTrk1 =                 EVPT_CDD_SA_ABIST_OVTRK1_SELECT,
    .OVVref =                 EVPT_CDD_SA_ABIST_OVVREF_SELECT,
    .OVCom =                  EVPT_CDD_SA_ABIST_OVCOM_SELECT,
    .OVVmon =                 EVPT_CDD_SA_ABIST_OVVMON_SELECT,
    .OVStby =                 EVPT_CDD_SA_ABIST_OVSTBY_SELECT,
    .OVUc =                   EVPT_CDD_SA_ABIST_OVUC_SELECT,
    .OVPreg =                 EVPT_CDD_SA_ABIST_OVPREG_SELECT,
    .UVTrk2 =                 EVPT_CDD_SA_ABIST_UVTRK2_NOT_SELECT,
    .UVTrk1 =                 EVPT_CDD_SA_ABIST_UVTRK1_NOT_SELECT,
    .UVVref =                 EVPT_CDD_SA_ABIST_UVVREF_NOT_SELECT,
    .UVCom =                  EVPT_CDD_SA_ABIST_UVCOM_NOT_SELECT,
    .UVVmon =                 EVPT_CDD_SA_ABIST_UVVMON_NOT_SELECT,
    .UVStby =                 EVPT_CDD_SA_ABIST_UVSTBY_NOT_SELECT,
    .UVUc =                   EVPT_CDD_SA_ABIST_UVUC_NOT_SELECT,
    .UVPreg =                 EVPT_CDD_SA_ABIST_UVPREG_NOT_SELECT,
    .BiasHigh =             EVPT_CDD_SA_ABIST_BIASHIGH_NOT_SELECT,
    .BiasLow =                 EVPT_CDD_SA_ABIST_BIASLOW_NOT_SELECT,
    .Bg12Ov =                 EVPT_CDD_SA_ABIST_BG12OV_NOT_SELECT,
    .Bg12Uv =                 EVPT_CDD_SA_ABIST_BG12UV_NOT_SELECT,
    .IntOV =                 EVPT_CDD_SA_ABIST_INTOV_NOT_SELECT,
    .VBatOV =                 EVPT_CDD_SA_ABIST_VBATOV_NOT_SELECT,
};

Cdd_Sa47301BuckCfgType_TDSTR SA47301_BuckCfg = {
    .BuckFreqSel =             EVPT_CDD_SA_BUCK_FREQ_SEL_NO_CHANGE,
    .DataValid =             EVPT_CDD_SA_BUCK_DATA_VALID_NO_ACTION,
    .FreSpThr =             EVPT_CDD_SA_BUCK_FREQ_SP_THR_NO_SPREAD,
};

Cdd_Sa47301FunCtrlCfgType_TDSTR SA47301_FunCtrlCfg = {
    .LDOucCurrentLimit =     EVPT_CDD_SA_FUNCTRL_LDOUC_CURRENT_LIMIT_850MA,
    .VrOvFailsafeState =     EVPT_CDD_SA_FUNCTRL_VROVF_ENTER_FAILSAFE,
};

Cdd_Sa47301McuMonCfgType_TDSTR SA47301_McuMonCfg = {
    .McuProgEn =             EVPT_CDD_SA_MCU_MON_MCU_PROG_DISABLE,
};

Cdd_Sa47301ConfigType_TDSTR Cdd_Sa47301_Config ={
    .DevCfg =       &SA47301_DevCfg,
    .SysCfg =       &SA47301_SysCfg,
    .WdgCfg =       &SA47301_WdgCfg,
    .WkTimeCfg =  &SA47301_WkTimeCfg,
    .AbistCfg =   &SA47301_AbistCfg,
    .BuckCfg =    &SA47301_BuckCfg,
    .FunCtrlCfg = &SA47301_FunCtrlCfg,
    .McuMonCfg =  &SA47301_McuMonCfg,
};

#ifdef __cplusplus
}
#endif
