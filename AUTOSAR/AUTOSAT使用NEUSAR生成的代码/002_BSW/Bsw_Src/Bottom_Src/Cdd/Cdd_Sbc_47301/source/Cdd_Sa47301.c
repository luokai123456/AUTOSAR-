#ifdef __cplusplus
extern "C" {
#endif

#include "Cdd_Sa47301.h"
#include "Cdd_Sa47301_Diag.h"
#include "Cdd_Sa47301_Com.h"
#include "Cdd_Sa47301_Hal.h"
#include "Cdd_Sa47301_Ctrl.h"
#include "Cdd_Sa47301_Reg.h"
#include "Cdd_Sa47301_Power.h"
#include "Evpt_System.h"
#include "EvptCdd_TPT1145.h"
#include "Cdd_Afe_Manage.h"
// #include "ErrorDiag_Errorid.h"
// #include "ErrorDiag_Swc.h"
// #include "System_Release.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_C             4
#define SA47301_AR_REL_MINOR_VER_C             4
#define SA47301_AR_REL_REV_VER_C               0
#define SA47301_SW_MAJOR_VER_C                 1
#define SA47301_SW_MINOR_VER_C                 0
#define SA47301_SW_PATCH_VER_C                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_C != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_C"
#endif
#if (SA47301_AR_REL_MINOR_VER_C != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_C"
#endif
#if (SA47301_AR_REL_REV_VER_C != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_C != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_C"
#endif
#if (SA47301_SW_MINOR_VER_C != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_C"
#endif
#if (SA47301_SW_PATCH_VER_C != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_C"
#endif

#define SA47301_INITREG_NUM  (sizeof(Cdd_Sa47301_RegStatus_Mp)/sizeof(Cdd_Sa47301_RegStatus_Mp[0]))
#define SA47301_ERRDIAG_NUM  (sizeof(Cdd_Sa47301_DiagErrSend_Mp)/sizeof(Cdd_Sa47301_DiagErrSend_Mp[0]))

#define SA_INIT_STEP                (0U)

#define SA_RUN_STEP                 (1U)

#define SA_POWEROFF_TIMEOUT_COUNT   (30000U)
#define SA_ABIST_TIMEOUT_COUNT      (100U)
#define SA_FIRST_FEEDWDG_TIMEOUT_COUNT      (100U)

#define SA47301_POWER_ON            (0)
#define SA47301_POWER_OFF           (1)

#define SA47301_WAKE_STATUS_DISABLE            (0)
#define SA47301_WAKE_STATUS_ENABLE             (1)

#define SA47301_WAKE_TIME           ()

static uint8 Sbc_valFirstWakeSrcGetFlag_Mp = 0;

Cdd_SA47301_RegInfoType SA47301_RegDataInfo_Mp[SA_REG_NUM_MAX] = {0};

Cdd_Sa47301SpiInfo_TDSTR SpiDataInfo;

Cdd_Sa47301WeakTimeCyc_TDEN g_WeakTimeCyc = SA47301_WEAKTIME_1MS; // Default weak time cycle is 1ms

extern Cdd_Sa47301ConfigType_TDSTR Cdd_Sa47301_Config;

SA_WakeSrc_STDR SA_valWakeSrc_Mp = {0};
SA_WakeSrc_STDR SA_valWakeSrc_Init_Mp = {0};

Cdd_Sa47301DiagErrSend_TDSTR Cdd_Sa47301_DiagErrSend_Mp[] = {
    {0   , SA47301_DIAG_UCOV  },
    // {ERRORID_SA47301_COM_OV  , SA47301_DIAG_COMOV },
    // {ERRORID_SA47301_VREF_OV , SA47301_DIAG_VREFOV},
    // {ERRORID_SA47301_TRK1_OV , SA47301_DIAG_TRK1OV},
    // {ERRORID_SA47301_TRK2_OV , SA47301_DIAG_TRK2OV},
    // {ERRORID_SA47301_UC_UV   , SA47301_DIAG_UCUV  },
    // {ERRORID_SA47301_COM_UV  , SA47301_DIAG_COMUV },
    // {ERRORID_SA47301_VREF_UV , SA47301_DIAG_VREFUV},
    // {ERRORID_SA47301_TRK1_UV , SA47301_DIAG_TRK1UV},
    // {ERRORID_SA47301_TRK2_UV , SA47301_DIAG_TRK2UV},
    // {ERRORID_SA47301_PREG_OT , SA47301_DIAG_PREG  },
    // {ERRORID_SA47301_UC_OT   , SA47301_DIAG_UC    },
    // {ERRORID_SA47301_COM_OT  , SA47301_DIAG_COM   },
};

static Cdd_Sa47301LdoCtrl_TDSTR Sa_LdoCtrlStr_Mp = {\
    .UpdateFlag = 0,
    .RefVoltEnable = 1,
    .ComVoltEnable = 1,
    .Trk1VoltEnable = 1,
    .Trk2VoltEnable = 1,
};

static boolean SA_fgAbistErr_Mp = FALSE;

static uint8 SA_fgTimerCalled_Mp = 0;

static uint8 SA47031_numStep_Mp = 0;

static uint32 FailChMask = 0; // 0x00: No Fail

static uint8 SA_WWdgEnStatus_Mp = EVPT_CDD_SA_WINWDG_DISABLED;

static uint8 SA_WWdgEnLastStatus_Mp = EVPT_CDD_SA_WINWDG_DISABLED;

static uint8 SA_FWdgEnStatus_Mp = EVPT_CDD_SA_FUNWDG_DISABLED;

static uint8 SA_FWdgEnLastStatus_Mp = EVPT_CDD_SA_FUNWDG_DISABLED;

static Cdd_Sa47301WdgModeType_TDEN SA_WdgFeedMode_Mp = SA47301_FEED_WDG_MODE_AUTO;
/*============================================FUNCTION PROTOTYPES===================================*/

Cdd_Sa47301RegStatus_TDSTR Cdd_Sa47301_RegStatus_Mp[] = {
    {SA_REG_DEVCFG0_CTRL, SA_REG_DEVCFG0_TAG},
    {SA_REG_DEVCFG1_CTRL, SA_REG_DEVCFG1_TAG},
    {SA_REG_DEVCFG2_CTRL, SA_REG_DEVCFG2_TAG},
    {SA_REG_DEVCTRL_CTRL, SA_REG_PROTCFG_TAG},
    {SA_REG_SYSPCFG0_CTRL, SA_REG_SYSPCFG0_TAG},
    {SA_REG_SYSPCFG1_CTRL, SA_REG_SYSPCFG1_TAG},
    {SA_REG_WDCFG0_CTRL, SA_REG_WDCFG0_TAG},
    {SA_REG_WDCFG1_CTRL, SA_REG_WDCFG1_TAG},
    {SA_REG_FWDCFG_CTRL, SA_REG_FWDCFG_TAG},
    {SA_REG_WWDCFG0_CTRL, SA_REG_WWDCFG0_TAG},
    {SA_REG_WWDCFG1_CTRL, SA_REG_WWDCFG1_TAG},
    // {SA_REG_WKTIMCFG0_CTRL, SA_REG_WKTIMCFG0_TAG},
    // {SA_REG_WKTIMCFG1_CTRL, SA_REG_WKTIMCFG1_TAG},
    // {SA_REG_WKTIMCFG2_CTRL, SA_REG_WKTIMCFG2_TAG},
    {SA_REG_BCK_FREQ_CHANGE_CTRL, SA_REG_BCK_FREQ_CHANGE_TAG},
    {SA_REG_BCK_FREQ_SPREAD_CTRL, SA_REG_BCK_FREQ_SPREAD_TAG},
    {SA_REG_BCK_MAIN_CTRL_CTRL, SA_REG_BCK_MAIN_CTRL_TAG},
    {SA_REG_FCR_CTRL, SA_REG_FCR_TAG},
    {SA_REG_MCUSUP_CTRL, SA_REG_MCUSUP_TAG},
};

void Cdd_Sbc_Sa47301_ConfigDataParse(void)
{
    /* -------------------------- DEVCFG0 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG0_TAG].Reg_DEVCFG0_tag.TRDEL = Cdd_Sa47301_Config.DevCfg->Trdel;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG0_TAG].Reg_DEVCFG0_tag.WKTIMKN = Cdd_Sa47301_Config.DevCfg->WakeTimeEn;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG0_TAG].Reg_DEVCFG0_tag.WKTIMCYC = Cdd_Sa47301_Config.DevCfg->WakeTimeCyc;

    /* -------------------------- DEVCFG1 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG1_TAG].Reg_DEVCFG1_tag.RESDEL = Cdd_Sa47301_Config.DevCfg->ResDelayTime;

    /* -------------------------- DEVCFG2 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG2_TAG].Reg_DEVCFG2_tag.CMONEN = Cdd_Sa47301_Config.DevCfg->CmonEn;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG2_TAG].Reg_DEVCFG2_tag.CTHR = Cdd_Sa47301_Config.DevCfg->Cthr;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG2_TAG].Reg_DEVCFG2_tag.SYNCPHA = Cdd_Sa47301_Config.DevCfg->SyncPha;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCFG2_TAG].Reg_DEVCFG2_tag.SYNCEN = Cdd_Sa47301_Config.DevCfg->SyncEn;

    /* -------------------------- DEVCTRL Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Reg_DEVCTRL_tag.TRK2EN = Cdd_Sa47301_Config.DevCfg->ReqTrk2En;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Reg_DEVCTRL_tag.TRK1EN = Cdd_Sa47301_Config.DevCfg->ReqTrk1En;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Reg_DEVCTRL_tag.COMEN = Cdd_Sa47301_Config.DevCfg->ReqComEn;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Reg_DEVCTRL_tag.VREFEN = Cdd_Sa47301_Config.DevCfg->ReqVRefEn;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Reg_DEVCTRL_tag.STATEREQ = Cdd_Sa47301_Config.DevCfg->ReqState;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Reg_DEVCTRL_tag.Reserved = 1;

    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRLN_TAG].Reg_DEVCTRLN_tag.TRK2EN = ~Cdd_Sa47301_Config.DevCfg->ReqTrk2En;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRLN_TAG].Reg_DEVCTRLN_tag.TRK1EN = ~Cdd_Sa47301_Config.DevCfg->ReqTrk1En;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRLN_TAG].Reg_DEVCTRLN_tag.COMEN = ~Cdd_Sa47301_Config.DevCfg->ReqComEn;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRLN_TAG].Reg_DEVCTRLN_tag.VREFEN = ~Cdd_Sa47301_Config.DevCfg->ReqVRefEn;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRLN_TAG].Reg_DEVCTRLN_tag.STATEREQ = ~Cdd_Sa47301_Config.DevCfg->ReqState;
    SA47301_RegDataInfo_Mp[SA_REG_DEVCTRLN_TAG].Reg_DEVCTRLN_tag.Reserved = 0;

    /* ------------------------- SYSPCFG0 Register Configuration ------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_SYSPCFG0_TAG].Reg_SYSPCFG0_tag.STBYEN = Cdd_Sa47301_Config.SysCfg->StbyEn;

    /* ------------------------- SYSPFG1 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_SYSPCFG1_TAG].Reg_SYSPFG1_tag.SS2DEL = Cdd_Sa47301_Config.SysCfg->SS2Del;
    SA47301_RegDataInfo_Mp[SA_REG_SYSPCFG1_TAG].Reg_SYSPFG1_tag.ERRSLPEN = Cdd_Sa47301_Config.SysCfg->ErrMonSleepEn;
    SA47301_RegDataInfo_Mp[SA_REG_SYSPCFG1_TAG].Reg_SYSPFG1_tag.ERREN = Cdd_Sa47301_Config.SysCfg->ErrMonEn;
    SA47301_RegDataInfo_Mp[SA_REG_SYSPCFG1_TAG].Reg_SYSPFG1_tag.ERRRECEN = Cdd_Sa47301_Config.SysCfg->ErrMonRecEn;
    SA47301_RegDataInfo_Mp[SA_REG_SYSPCFG1_TAG].Reg_SYSPFG1_tag.ERRRECTIM = Cdd_Sa47301_Config.SysCfg->ErrMonRecTime;

    /* -------------------------- WDCFG0 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG0_TAG].Reg_WDCFG0_tag.WWDETHR = Cdd_Sa47301_Config.WdgCfg->WinWdgErrCounThr;
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG0_TAG].Reg_WDCFG0_tag.WWDEN = Cdd_Sa47301_Config.WdgCfg->WinWdgEn;
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG0_TAG].Reg_WDCFG0_tag.FWDEN = Cdd_Sa47301_Config.WdgCfg->FunWdgEn;
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG0_TAG].Reg_WDCFG0_tag.WWDTSEL = Cdd_Sa47301_Config.WdgCfg->WinWdgSrcSel;
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG0_TAG].Reg_WDCFG0_tag.WDCYC = Cdd_Sa47301_Config.WdgCfg->WdgCycTime;

    /* -------------------------- WDCFG1 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG1_TAG].Reg_WDCFG1_tag.WDCYCDIV = Cdd_Sa47301_Config.WdgCfg->WdgCycDiv;
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG1_TAG].Reg_WDCFG1_tag.WDSLPEN = Cdd_Sa47301_Config.WdgCfg->WdgInSleepEn;
    SA47301_RegDataInfo_Mp[SA_REG_WDCFG1_TAG].Reg_WDCFG1_tag.FWDETHR = Cdd_Sa47301_Config.WdgCfg->FunWdgErrCounThr;

    /* -------------------------- FWDCFG Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_FWDCFG_TAG].Reg_FWDCFG_tag.WDHBTP = Cdd_Sa47301_Config.WdgCfg->FunWdgHbTimePeriod;

    /* ------------------------- WWDCFG0 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_WWDCFG0_TAG].Reg_WWDCFG0_tag.CW = Cdd_Sa47301_Config.WdgCfg->WinWdgTmin;

    /* ------------------------- WWDCFG1 Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_WWDCFG1_TAG].Reg_WWDCFG1_tag.OW = Cdd_Sa47301_Config.WdgCfg->WinWdgTmargin;

    /* ------------------------ WKTIMCFG0-2 Register Configuration ----------------------- */
    // SA47301_RegDataInfo_Mp[SA_REG_WKTIMCFG0_TAG].Reg_WKTMCFG0_tag.TIMVALL = Cdd_Sa47301_Config.WkTimeCfg->WakeTimeValLowBit;
    // SA47301_RegDataInfo_Mp[SA_REG_WKTIMCFG1_TAG].Reg_WKTMCFG1_tag.TIMVALM = Cdd_Sa47301_Config.WkTimeCfg->WakeTimeValMidBit;
    // SA47301_RegDataInfo_Mp[SA_REG_WKTIMCFG2_TAG].Reg_WKTMCFG2_tag.TIMVALH = Cdd_Sa47301_Config.WkTimeCfg->WakeTimeValHigBit;

    /* ------------------------- ABIST_CTRL0 Register Configuration ---------------------- */
    // Set Safety Path value to ABIST_CTRL0 register INT field
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_CTRL0_TAG].Reg_ABIST_CTRL0_tag.INT = Cdd_Sa47301_Config.AbistCfg->SafetyPath;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_CTRL0_TAG].Reg_ABIST_CTRL0_tag.SINGLE = Cdd_Sa47301_Config.AbistCfg->AbistSequence;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_CTRL0_TAG].Reg_ABIST_CTRL0_tag.PATH = Cdd_Sa47301_Config.AbistCfg->FullPath;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_CTRL0_TAG].Reg_ABIST_CTRL0_tag.START = Cdd_Sa47301_Config.AbistCfg->StartAbist;

    /* ------------------------- ABIST_CTRL1 Register Configuration ---------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_CTRL1_TAG].Reg_ABIST_CTRL1_tag.ABIST_CLK_EN = Cdd_Sa47301_Config.AbistCfg->AbistClkCheckEn;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_CTRL1_TAG].Reg_ABIST_CTRL1_tag.OV_TRIG = Cdd_Sa47301_Config.AbistCfg->OVTrigMonEn;

    /* ------------------------ ABIST_SELECT0 Register Configuration ---------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.TRK2OV = Cdd_Sa47301_Config.AbistCfg->OVTrk2;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.TRK1OV = Cdd_Sa47301_Config.AbistCfg->OVTrk1;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.VREFOV = Cdd_Sa47301_Config.AbistCfg->OVVref;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.COMOV = Cdd_Sa47301_Config.AbistCfg->OVCom;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.VMONOV = Cdd_Sa47301_Config.AbistCfg->OVVmon;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.STBYOV = Cdd_Sa47301_Config.AbistCfg->OVStby;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.UCOV = Cdd_Sa47301_Config.AbistCfg->OVUc;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT0_TAG].Reg_ABIST_SELECT0_tag.PREGOV = Cdd_Sa47301_Config.AbistCfg->OVPreg;

    /* ------------------------ ABIST_SELECT1 Register Configuration ---------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.TRK2UV = Cdd_Sa47301_Config.AbistCfg->UVTrk2;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.TRK1UV = Cdd_Sa47301_Config.AbistCfg->UVTrk1;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.VREFUV = Cdd_Sa47301_Config.AbistCfg->UVVref;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.COMUV = Cdd_Sa47301_Config.AbistCfg->UVCom;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.VMONUV = Cdd_Sa47301_Config.AbistCfg->UVVmon;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.STBYUV = Cdd_Sa47301_Config.AbistCfg->UVStby;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.UCUV = Cdd_Sa47301_Config.AbistCfg->UVUc;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT1_TAG].Reg_ABIST_SELECT1_tag.PREGUV = Cdd_Sa47301_Config.AbistCfg->UVPreg;

    /* ------------------------ ABIST_SELECT2 Register Configuration ---------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT2_TAG].Reg_ABIST_SELECT2_tag.BIASHI = Cdd_Sa47301_Config.AbistCfg->BiasHigh;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT2_TAG].Reg_ABIST_SELECT2_tag.BIASLOW = Cdd_Sa47301_Config.AbistCfg->BiasLow;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT2_TAG].Reg_ABIST_SELECT2_tag.BG12OV = Cdd_Sa47301_Config.AbistCfg->Bg12Ov;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT2_TAG].Reg_ABIST_SELECT2_tag.BG12UV = Cdd_Sa47301_Config.AbistCfg->Bg12Uv;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT2_TAG].Reg_ABIST_SELECT2_tag.INTOV = Cdd_Sa47301_Config.AbistCfg->IntOV;
    SA47301_RegDataInfo_Mp[SA_REG_ABIST_SELECT2_TAG].Reg_ABIST_SELECT2_tag.VBATOV = Cdd_Sa47301_Config.AbistCfg->VBatOV;

    /* ----------------------- BCK_FREQ_CHANGE Register Configuration --------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_BCK_FREQ_CHANGE_TAG].Reg_BCK_FREQ_CHANGE_tag.BCK_FREQ_SEL = Cdd_Sa47301_Config.BuckCfg->BuckFreqSel;

    /* ----------------------- BCK_FREQ_SPREAD Register Configuration --------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_BCK_FREQ_SPREAD_TAG].Reg_BCK_FREQ_SPREAD_tag.FRE_SP_THR = Cdd_Sa47301_Config.BuckCfg->FreSpThr;

    /* ------------------------ BCK_MAIN_CTRL Register Configuration --------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_BCK_MAIN_CTRL_TAG].Reg_BCK_MAIN_CTRL_tag.DATA_VALID = Cdd_Sa47301_Config.BuckCfg->DataValid;

    /* --------------------------- FCR Register Configuration ---------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_FCR_TAG].Reg_FCR_tag.VR_OV_FS = Cdd_Sa47301_Config.FunCtrlCfg->VrOvFailsafeState;
    SA47301_RegDataInfo_Mp[SA_REG_FCR_TAG].Reg_FCR_tag.LDO_UC_CUR = Cdd_Sa47301_Config.FunCtrlCfg->LDOucCurrentLimit;

    /* -------------------------- MCUSUP Register Configuration -------------------------- */
    SA47301_RegDataInfo_Mp[SA_REG_MCUSUP_TAG].Reg_MCUSUP_tag.PROG = Cdd_Sa47301_Config.McuMonCfg->McuProgEn;
}

Std_ReturnType SA47301_ProtectedRegMode_Function(boolean valLock_Lo)
{
    uint8 numCnt_Lo = 0;
    uint16 valSpiRxBuf_Lo = 0;
    uint16 valSpiTxBuf_Lo[4] = {0};
    Std_ReturnType valRet_Lo = E_OK;

    switch(valLock_Lo)
    {
        case SA_REG_UNLOCK: // Unlock operation: load unlock keys
            valSpiTxBuf_Lo[0] = SA_UNLOCK_KEY1_VAL;
            valSpiTxBuf_Lo[1] = SA_UNLOCK_KEY2_VAL;
            valSpiTxBuf_Lo[2] = SA_UNLOCK_KEY3_VAL;
            valSpiTxBuf_Lo[3] = SA_UNLOCK_KEY4_VAL;
            break;
        case SA_REG_LOCKED: // Lock operation: load lock keys
            valSpiTxBuf_Lo[0] = SA_LOCK_KEY1_VAL;
            valSpiTxBuf_Lo[1] = SA_LOCK_KEY2_VAL;
            valSpiTxBuf_Lo[2] = SA_LOCK_KEY3_VAL;
            valSpiTxBuf_Lo[3] = SA_LOCK_KEY4_VAL; // Note: Original code uses KEY3 twice (check if it's KEY4)
            break;
        default: // Invalid input: do nothing, keep valRet_Lo = SA_FAILED
            break;
    }

    for(numCnt_Lo = 0; numCnt_Lo < 4; numCnt_Lo++)
    {
        SpiDataInfo.TxFrame.FrameData = 0;
        SpiDataInfo.TxFrame.BITS.ADDRESS = SA_REG_PROTCFG_TAG;
        SpiDataInfo.TxFrame.BITS.RW = SA47301_SPI_WRITE;
        SpiDataInfo.TxFrame.BITS.DATA = valSpiTxBuf_Lo[numCnt_Lo];
        valRet_Lo |= Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, SA_REG_PROTCFG_TAG, SpiDataInfo.TxFrame.BITS.DATA);
    }
    SpiDataInfo.RxFrame.FrameData = 0;
    SpiDataInfo.TxFrame.FrameData = 0;
    SpiDataInfo.TxFrame.BITS.ADDRESS = SA_REG_PROTSTAT_TAG;
    SpiDataInfo.TxFrame.BITS.RW = SA47301_SPI_READ;
    SpiDataInfo.TxFrame.BITS.DATA = 0;
    valRet_Lo |= Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_PROTSTAT_TAG, 0);

    if(((SpiDataInfo.RxFrame.FrameData >> 1) & SA_LOCK_STATUS_MASK) == valLock_Lo)
    {
        valRet_Lo |= E_OK; // Status matches: operation succeeded
    }

    return valRet_Lo;
}

Std_ReturnType Cdd_Sbc_Sa47301_SetDeviceMode_Function(uint8 valMode_Lo)
{
    uint8 valRegData_Lo = 0;
    uint16 valSpiRxBuf_Lo = 0;
    Std_ReturnType valRet_Lo = E_NOT_OK;

    valRegData_Lo = SA47301_RegDataInfo_Mp[SA_REG_DEVCTRL_TAG].Data | valMode_Lo; // Fixed: SA47301 → SA47301

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_WRITE, SA_DEVCTL_ADDR, valRegData_Lo);    // Fixed: SA_SPI_WRITE → SA_SPI_WRITE
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_WRITE, SA_DEVCTRLN_ADDR, ~valRegData_Lo); // Write complementary value to DEVCTRLN

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_DEVSTAT_ADDR, 0);
    
    // valSpiRxBuf_Lo = SpiDataInfo.RxFrame.BITS.DATA;
    if (((SpiDataInfo.RxFrame.BITS.DATA) & SA_STATE_MASK) == valMode_Lo)
    {
        valRet_Lo = E_OK;
    }
    return valRet_Lo;
}
uint32 usGptTimerStart = 0;
uint32 usGptTimerEnd = 0;
uint32 usGptTimer = 0;
Std_ReturnType Cdd_Sbc_Sa47301_InitFunction(void)
{
    /* Initialize the SA47301 */
    Std_ReturnType RetVal = E_OK;
    volatile uint8 RegIndex = 0;
    uint32 AbistTimeout = 0;
    uint32 FirstFeedWdgTimeoutCount = 0;
    Cdd_Sa47301SpiComErrInfo_TDSTR valSpiComStatus;
    Cdd_Sa47301AbistResult_TDSTR valAbistResult = ABIST_RESULT_IDLE;
    MCU_SPI_InitSa47301();
    Sys_UpdateRemainWakeTime();
    Cdd_Sbc_Sa47301_ConfigDataParse();
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ,SA_REG_INITERROR_TAG,0);
    SA47301_ProtectedRegMode_Function(SA_REG_UNLOCK);

    RetVal |= Cdd_Sbc_Sa47301_SpiComErrCheck(&SpiDataInfo, &valSpiComStatus);

    if(valSpiComStatus.valErrFlag == SPI_COM_ERR_FLAG && RetVal == E_OK)
    {
        RetVal |= Cdd_Sbc_Sa47301_SpiComErrCheck(&SpiDataInfo, &valSpiComStatus);
        if(valSpiComStatus.valErrFlag == SPI_COM_ERR_FLAG && RetVal == E_OK)
        {
            RetVal |= E_NOT_OK;
        }
    }

    for(RegIndex = 0; RegIndex < SA47301_INITREG_NUM; RegIndex++)
    {
        if(Cdd_Sa47301_RegStatus_Mp[RegIndex].WriteEN == STD_ON){
            SpiDataInfo.TxFrame.FrameData = 0;
            SpiDataInfo.RxFrame.FrameData = 0;
            RetVal |= Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_WRITE, Cdd_Sa47301_RegStatus_Mp[RegIndex].RegAddress, SA47301_RegDataInfo_Mp[Cdd_Sa47301_RegStatus_Mp[RegIndex].RegAddress].Data);
        }
    }
    SA47301_ProtectedRegMode_Function(SA_REG_LOCKED);

    Cdd_Sbc_Sa47301_ClearDiag();

    Cdd_Sbc_Sa47301_AbistEnFunction(Cdd_Sa47301_Config.AbistCfg);

    while(((valAbistResult == ABIST_RESULT_IDLE) || (valAbistResult == ABIST_RESULT_BUSY)) && (AbistTimeout <= SA_ABIST_TIMEOUT_COUNT))
    {
        AbistTimeout++;
        Cdd_Sbc_Sa47301_GetAbistResrult(&valAbistResult, &FailChMask); 
    }
    if(AbistTimeout > SA_ABIST_TIMEOUT_COUNT)
    {
        RetVal = E_NOT_OK;
    }
    else if(valAbistResult == ABIST_RESULT_FAIL)
    {
        SA_fgAbistErr_Mp = TRUE;
        RetVal = E_NOT_OK;

    }
    else if(valAbistResult == ABIST_RESULT_PASS)
    {
        RetVal = E_OK;
    }
    else
    {
        RetVal = E_NOT_OK;
    }
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ,SA_REG_INITERROR_TAG,0);
    
    do
    {
        FirstFeedWdgTimeoutCount++;
        if(EVPT_CDD_SA_WINWDG_ENABLED == Cdd_Sa47301_Config.WdgCfg->WinWdgEn )
        { 
            SA_WWdgEnStatus_Mp = Cdd_Sa47301_Config.WdgCfg->WinWdgEn;
            SA_WWdgEnLastStatus_Mp = SA_WWdgEnStatus_Mp;
            Cdd_Sbc_Sa47301_FeedWdgFunction(SA47301_FEED_WWDG);
        }

        if(EVPT_CDD_SA_FUNWDG_ENABLED == Cdd_Sa47301_Config.WdgCfg->FunWdgEn)
        {
            SA_FWdgEnStatus_Mp = Cdd_Sa47301_Config.WdgCfg->FunWdgEn;
            SA_FWdgEnLastStatus_Mp = SA_FWdgEnStatus_Mp;
            Cdd_Sbc_Sa47301_FeedWdgFunction(SA47301_FEED_FWDG);
        }
        RetVal = Cdd_Sbc_Sa47301_SetDeviceMode_Function(SA_DEVICE_NORMAL_MODE);
    }while(RetVal != E_OK && SA_FIRST_FEEDWDG_TIMEOUT_COUNT >= FirstFeedWdgTimeoutCount);
        // SA47301_WWDFeedDog_Function();

    if(FirstFeedWdgTimeoutCount >= SA_FIRST_FEEDWDG_TIMEOUT_COUNT)
    {
        RetVal = E_NOT_OK;
    }

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_DEVSTAT_ADDR, 0);

    Cdd_Sbc_Sa47301_ClearDiag();

    return RetVal;
}

void Cdd_Sbc_Sa47301_FeedWdgFunction(Cdd_Sa47301FeedWdgModeType_TDEM Feed_Mode)
{
    if (Feed_Mode == SA47301_FEED_WWDG)
    {
        Cdd_Sbc_Sa47301_FeedWWdg();
    }
    else if (Feed_Mode == SA47301_FEED_FWDG)
    {
        Cdd_Sbc_Sa47301_FeedFWdg();
    }
}

Std_ReturnType Cdd_Sbc_Sa47301_GetDiagFunction(Cdd_Sa47301Diag_TDEM DiagId, boolean *DiagFlag)
{
    Std_ReturnType ret = E_OK;
    if(DiagId >= SA47301_DIAG_MAX || DiagFlag == NULL_PTR)
    {
        ret = E_NOT_OK;
    }

    *DiagFlag = Cdd_Sbc_Sa47301_GetDiagStatus(DiagId);

    return ret;

}
uint8 Cdd_sbc_Sa47301_GetWakePinLevelStatusFunction(void)
{
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_WKS_TAG, 0);
    return (SpiDataInfo.RxFrame.FrameData >> 8) & 0x01;
}
void Cdd_Sbc_Sa47301_GetWKSFRegValueFunction(void)
{
    Tle9018_DevType* Afe_valDev_Lo = Afe_GetDev();
    uint16 valSpiTxBuf_Lo = 0;
    uint16 valKeyVolt_Lo = 0;
    uint16 valKey1Volt_Lo = 0;
    uint16 valAPlus1Volt_Lo = 0;
    uint16 valAPlus2Volt_Lo = 0;
    uint16 valAFEVolt_Lo = 0;
    uint16 valOBCVolt_Lo = 0;
    Std_ReturnType CanTrcv_WakeFlag1_Lo;
    Std_ReturnType CanTrcv_WakeFlag2_Lo;

    if(1 == Sbc_valFirstWakeSrcGetFlag_Mp) {
        return;
    }

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo, SA47301_SPI_READ, SA_REG_WKS_TAG, 0);
    MCU_ADC_GetKeyVolt(&valKeyVolt_Lo, &valKey1Volt_Lo);
    MCU_ADC_GetAPlusVolt(&valAPlus1Volt_Lo, &valAPlus2Volt_Lo);
    MCU_ADC_GetAfeObcVolt(&valAFEVolt_Lo, &valOBCVolt_Lo);
    CanTrcv_WakeFlag1_Lo = CanTrcv_CheckWakeup(0);
    CanTrcv_WakeFlag2_Lo = CanTrcv_CheckWakeup(1);

	SA_valWakeSrc_Mp.fgCanAWakeUpActive     = ((SpiDataInfo.RxFrame.FrameData >> 2&0x01) && (E_OK == CanTrcv_WakeFlag1_Lo))? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgCanBWakeUpActive     = ((SpiDataInfo.RxFrame.FrameData >> 2&0x01) && (E_OK == CanTrcv_WakeFlag2_Lo))? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgKeyWakeUpActive      = ((SpiDataInfo.RxFrame.FrameData >> 1&0x01) && (valKeyVolt_Lo > 6000)) ? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgAPlus1WakeUpActive   = ((SpiDataInfo.RxFrame.FrameData >> 1&0x01) && (valAPlus1Volt_Lo > 6000)) ? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgAPlus2WakeUpActive   = ((SpiDataInfo.RxFrame.FrameData >> 1&0x01) && (valAPlus2Volt_Lo > 6000)) ? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgAFEWakeUpActive      = ((SpiDataInfo.RxFrame.FrameData >> 1&0x01) && (1 == Afe_valDev_Lo->wake_up_from_sleep)) ? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgOBCWakeUpActive      = ((SpiDataInfo.RxFrame.FrameData >> 1&0x01) && (valOBCVolt_Lo > 6000)) ? TRUE : FALSE;
    SA_valWakeSrc_Mp.fgRTCWakeUpActive      = (SpiDataInfo.RxFrame.FrameData >> 4&0x01);
    
    if((TRUE == SA_valWakeSrc_Mp.fgCanAWakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgCanBWakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgKeyWakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgAPlus1WakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgAPlus2WakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgAFEWakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgOBCWakeUpActive) ||\
        (TRUE == SA_valWakeSrc_Mp.fgRTCWakeUpActive)) {
        Sbc_valFirstWakeSrcGetFlag_Mp = 1;
    }
}

SA_WakeSrc_STDR Cdd_Sbc_Sa47301_GetWakeSourceFunction(void)
{	
	return SA_valWakeSrc_Mp;
}

static uint32 SA_WdgWindowTimerCnt_Mp = 0;
static uint32 SA_WdgFunctionTimerCnt_Mp = 0;
uint8 SA_WdgRestFlag_Mp = 0;
extern void SA47031_CONDITION_Function(void);
static void Cdd_Sbc_Sa47301_Wdg10msFunction(void)
{
    if(SA_WWdgEnStatus_Mp == SA_WWdgEnLastStatus_Mp)
    {
        Cdd_Sbc_Sa47301_SetWdgEnStatus(SA47301_WWDG,SA_WWdgEnStatus_Mp);
        SA_WWdgEnLastStatus_Mp = SA_WWdgEnStatus_Mp;
    }

    if(SA_FWdgEnStatus_Mp == SA_FWdgEnLastStatus_Mp)
    {
        Cdd_Sbc_Sa47301_SetWdgEnStatus(SA47301_FWDG,SA_FWdgEnStatus_Mp);
        SA_FWdgEnLastStatus_Mp = SA_FWdgEnStatus_Mp;
    }
    

    if(SA_WdgFeedMode_Mp == SA47301_FEED_WDG_MODE_AUTO)
    {
        if((SA_WWdgEnStatus_Mp == EVPT_CDD_SA_WINWDG_ENABLED) && (SA_WdgRestFlag_Mp == SA47301_HWWDG_RESET_FLAG_FALSE))
        {
            if(SA_WdgWindowTimerCnt_Mp == 0U)
            {
                // Cdd_Sbc_Sa47301_FeedWWdg();
            }

            SA_WdgWindowTimerCnt_Mp++;

            if(SA_WdgWindowTimerCnt_Mp >= SA_FEED_WWDG_TIME)
            {
                SA_WdgWindowTimerCnt_Mp = 0U;
            }
        }

        if((SA_FWdgEnStatus_Mp == EVPT_CDD_SA_FUNWDG_ENABLED) && (SA_WdgRestFlag_Mp == SA47301_HWWDG_RESET_FLAG_FALSE))
        {
            if(SA_WdgFunctionTimerCnt_Mp == 0U)
            {
                // Cdd_Sbc_Sa47301_FeedFWdg();
            //     SA47031_CONDITION_Function();
            }

            SA_WdgFunctionTimerCnt_Mp++;

            if(SA_WdgFunctionTimerCnt_Mp >= SA_FEED_FWDG_TIME)
            {
                SA_WdgFunctionTimerCnt_Mp = 0U;
            }
        }
    }

    return;
}

static uint8 SA_fgPowerOff_Mp = SA47301_POWER_ON;
static uint8 SA_fgWakeStatus_Mp = SA47301_WAKE_STATUS_DISABLE;
static uint8 SA_fgWakeTime_Mp = 0;
static void Cdd_Sbc_Sa47301_PowerOff10msFunction(void)
{
    if (SA47301_POWER_OFF == SA_fgPowerOff_Mp)
    {
        Cdd_Sbc_Sa47301_SetWakeStatus(SA_fgWakeStatus_Mp);

        if (SA47301_WAKE_STATUS_ENABLE == SA_fgWakeStatus_Mp)
        {
            Cdd_Sbc_Sa47301_SetWakeTime(SA_fgWakeTime_Mp);
        }

        Cdd_Sbc_Sa47301_PowerOff();
        /* code */
    }
    
}

static void Cdd_Sbc_Sa47301_Diag10msFunction(void)
{
    boolean valDiagRes_Lo = FALSE;
    Cdd_Sbc_Sa47301_SaveDiagStatus();

    for (uint8 index = 0; index < SA47301_ERRDIAG_NUM; index++)
    {
        // Cdd_Sbc_Sa47301_GetDiagFunction(Cdd_Sa47301_DiagErrSend_Mp[index].ChipDiagID, &valDiagRes_Lo);
        // ErrorDiag_Send_ErrorStatus(Cdd_Sa47301_DiagErrSend_Mp[index].DiagId, valDiagRes_Lo);
        /* code */
    }

    if(SA_fgAbistErr_Mp == TRUE)
    {
        // ErrorDiag_Send_ErrorStatus(ERRORID_SA47301_ABIST_ERR, TRUE);
        SA_fgAbistErr_Mp = FALSE;
    }
}

static void Cdd_Sbc_Sa47301_LdoCtrl10msFunction(void)
{
    if(Sa_LdoCtrlStr_Mp.UpdateFlag == 1)
    {
        Sa_LdoCtrlStr_Mp.UpdateFlag = 0;
        Cdd_Sbc_Sa47301_SetLdoEn(&Sa_LdoCtrlStr_Mp);
    }
}

static void Cdd_Sbc_Sa47301_RunStep_Function(void)
{
    // Cdd_Sbc_Sa47301_GetWKSFRegValueFunction();
    
    Cdd_Sbc_Sa47301_Diag10msFunction();
    Cdd_Sbc_Sa47301_Wdg10msFunction();
    Cdd_Sbc_Sa47301_PowerOff10msFunction();
    Cdd_Sbc_Sa47301_LdoCtrl10msFunction();
}

Std_ReturnType Cdd_Sbc_Sa47301_SetWakeStatusFunction(boolean valEn_Lo)
{
    SA_fgWakeStatus_Mp = (valEn_Lo == 1)?SA47301_WAKE_STATUS_ENABLE:SA47301_WAKE_STATUS_DISABLE;
    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_SetWakeTimeFunction(uint32 WakeTime)
{
    // SA_fgWakeTime_Mp = WakeTime;
    Cdd_Sbc_Sa47301_SetWakeStatus(SA_fgWakeStatus_Mp);
    Cdd_Sbc_Sa47301_SetWakeTime(WakeTime);
    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_GetPoweroffTimeFunction(uint32 *WakeTime)
{
    volatile uint8 valWakeTime_Hi = 0;
    volatile uint8 valWakeTime_Mi = 0;
    volatile uint8 valWakeTime_Lo = 0;
    volatile uint8 valWakeTimeBase  = 0;

    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_REG_WKS_TAG, 0);

    if((SpiDataInfo.RxFrame.BITS.DATA >> 3 & 0x01) == 0)
    {
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_REG_DEVCFG0_TAG, 0);
        valWakeTimeBase = (SpiDataInfo.RxFrame.BITS.DATA >> 6) & 0x01;
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_REG_WKTIMCFG0_TAG, 0);
        valWakeTime_Lo = SpiDataInfo.RxFrame.BITS.DATA;
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_REG_WKTIMCFG1_TAG, 0);
        valWakeTime_Mi = SpiDataInfo.RxFrame.BITS.DATA;
        Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_REG_WKTIMCFG2_TAG, 0);
        valWakeTime_Hi = SpiDataInfo.RxFrame.BITS.DATA;

        *WakeTime = (((uint32)(valWakeTime_Hi << 16 | valWakeTime_Mi << 8 | valWakeTime_Lo)) / ((valWakeTimeBase)? 1:1000));
    }
    else
    {
        *WakeTime = 0;
    }
    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_SetPowerOffFunction(void)
{
    Cdd_Sbc_Sa47301_PowerOff();
    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_CtrlWdgEnStatusFunction(uint8 WdgType, boolean valEn_Lo)
{
    if(WdgType == SA47301_WWDG)
    {
        SA_WWdgEnStatus_Mp = (valEn_Lo == 1)?EVPT_CDD_SA_WINWDG_ENABLED:EVPT_CDD_SA_WINWDG_DISABLED;
    }
    else if(WdgType == SA47301_FWDG)
    {
        SA_FWdgEnStatus_Mp = (valEn_Lo == 1)?EVPT_CDD_SA_FUNWDG_ENABLED:EVPT_CDD_SA_FUNWDG_DISABLED;
    }

    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_SetWdgFeedModeFunction(Cdd_Sa47301WdgModeType_TDEN FeedWdgMode)
{
    SA_WdgFeedMode_Mp = FeedWdgMode;
    return E_OK;
}

Std_ReturnType Cdd_Sbc_Sa47301_SetLdoEnFunction(uint8 LdoCh, boolean valEn_Lo)
{
    switch(LdoCh)
    {
        case SA47301_LDO_CH_TRK1:
            Sa_LdoCtrlStr_Mp.Trk1VoltEnable = (valEn_Lo == 1)?CDD_SA_LDO_ENABLE:CDD_SA_LDO_DISABLE;
            break;
        case SA47301_LDO_CH_TRK2:
            Sa_LdoCtrlStr_Mp.Trk2VoltEnable = (valEn_Lo == 1)?CDD_SA_LDO_ENABLE:CDD_SA_LDO_DISABLE;
            break;
        case SA47301_LDO_CH_COMV:
            Sa_LdoCtrlStr_Mp.ComVoltEnable = (valEn_Lo == 1)?CDD_SA_LDO_ENABLE:CDD_SA_LDO_DISABLE;
            break;
        case SA47301_LDO_CH_REFV:
            Sa_LdoCtrlStr_Mp.RefVoltEnable = (valEn_Lo == 1)?CDD_SA_LDO_ENABLE:CDD_SA_LDO_DISABLE;
            break;
        default:
            break;
    }
    Sa_LdoCtrlStr_Mp.UpdateFlag = 1;
    return E_OK;
}



void Cdd_Sbc_Sa47301_10msMainFunction(void)
{
    Cdd_Sbc_Sa47301_SpiTransmit(&SpiDataInfo ,SA47301_SPI_READ, SA_DEVSTAT_ADDR, 0);
    switch(SA47031_numStep_Mp)
    {
        case SA_INIT_STEP:			
			SA47031_numStep_Mp = SA_RUN_STEP;
            break;
        case SA_RUN_STEP:
            Cdd_Sbc_Sa47301_RunStep_Function();
            break;
        default:
            SA47031_numStep_Mp = SA_INIT_STEP;
        break;
    }
}

#ifdef __cplusplus
}
#endif
