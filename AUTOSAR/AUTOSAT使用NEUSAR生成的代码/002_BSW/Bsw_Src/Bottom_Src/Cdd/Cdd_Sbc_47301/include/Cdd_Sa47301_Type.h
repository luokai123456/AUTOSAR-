#ifndef _CDD_SA47301_TYPE_H_
#define _CDD_SA47301_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Cdd_Sa47301_Cfg.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SA47301_AR_REL_MAJOR_VER_TYPE             4
#define SA47301_AR_REL_MINOR_VER_TYPE             4
#define SA47301_AR_REL_REV_VER_TYPE               0
#define SA47301_SW_MAJOR_VER_TYPE                 1
#define SA47301_SW_MINOR_VER_TYPE                 0
#define SA47301_SW_PATCH_VER_TYPE                 0

/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same Autosar version */
#if (SA47301_AR_REL_MAJOR_VER_TYPE != EB_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MAJOR_VER_TYPE"
#endif
#if (SA47301_AR_REL_MINOR_VER_TYPE != EB_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_MINOR_VER_TYPE"
#endif
#if (SA47301_AR_REL_REV_VER_TYPE != EB_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SA47301_AR_REL_REV_VER_TYPE"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (SA47301_SW_MAJOR_VER_TYPE != EB_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MAJOR_VER_TYPE"
#endif
#if (SA47301_SW_MINOR_VER_TYPE != EB_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_MINOR_VER_TYPE"
#endif
#if (SA47301_SW_PATCH_VER_TYPE != EB_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SA47301_SW_PATCH_VER_TYPE"
#endif

#define CDD_SA_LDO_ENABLE                                (1)
#define CDD_SA_LDO_DISABLE                               (0)

#define CDD_SA_ABIST_ENABLE                                (1)
#define CDD_SA_ABIST_DISABLE                               (0)

/*************************WakeTimeEn*******************************/
#define EVPT_CDD_SA_WAKETIME_DISABLED         (0x00)
#define EVPT_CDD_SA_WAKETIME_ENABLED          (0x01)
/******************WakeTimeCycPeriod*******************************/
#define EVPT_CDD_SA_WAKETIME_CYC_PERIOD_1MS   (0x00)
#define EVPT_CDD_SA_WAKETIME_CYC_PERIOD_1S    (0x01)
/*********************************Trdel**************************************/
#define EVPT_CDD_SA_TRDEL_100US               (0x00)
#define EVPT_CDD_SA_TRDEL_200US               (0x01)
#define EVPT_CDD_SA_TRDEL_300US               (0x02)
#define EVPT_CDD_SA_TRDEL_400US               (0x03)
#define EVPT_CDD_SA_TRDEL_500US               (0x04)
#define EVPT_CDD_SA_TRDEL_600US               (0x05)
#define EVPT_CDD_SA_TRDEL_700US               (0x06)
#define EVPT_CDD_SA_TRDEL_800US               (0x07)
#define EVPT_CDD_SA_TRDEL_900US               (0x08)
#define EVPT_CDD_SA_TRDEL_1000US              (0x09)
#define EVPT_CDD_SA_TRDEL_1100US              (0x0A)
#define EVPT_CDD_SA_TRDEL_1200US              (0x0B)
#define EVPT_CDD_SA_TRDEL_1300US              (0x0C)
#define EVPT_CDD_SA_TRDEL_1400US              (0x0D)
#define EVPT_CDD_SA_TRDEL_1500US              (0x0E)
#define EVPT_CDD_SA_TRDEL_1600US              (0x0F)
/*****************************ResDelayTime**********************************/
#define EVPT_CDD_SA_RESDELAYTIME_200US        (0x00)
#define EVPT_CDD_SA_RESDELAYTIME_400US        (0x01)
#define EVPT_CDD_SA_RESDELAYTIME_800US        (0x02)
#define EVPT_CDD_SA_RESDELAYTIME_1MS          (0x03)
#define EVPT_CDD_SA_RESDELAYTIME_2MS          (0x04)
#define EVPT_CDD_SA_RESDELAYTIME_4MS          (0x05)
#define EVPT_CDD_SA_RESDELAYTIME_10MS         (0x06)
#define EVPT_CDD_SA_RESDELAYTIME_15MS         (0x07)
#define EVPT_CDD_SA_RESDELAYTIME_30MS         (0x08)
#define EVPT_CDD_SA_RESDELAYTIME_60MS         (0x09)
/***********************************CmonEn**********************************/
#define EVPT_CDD_SA_CMON_DISABLED             (0x00)
#define EVPT_CDD_SA_CMON_ENABLED              (0x01)
/*********************************Cthr**************************************/
#define EVPT_CDD_SA_CTHR_10MA                 (0x00)
#define EVPT_CDD_SA_CTHR_30MA                 (0x01)
#define EVPT_CDD_SA_CTHR_60MA                 (0x02)
#define EVPT_CDD_SA_CTHR_100MA                (0x03)
/***********************************SyncPha**********************************/
#define EVPT_CDD_SA_SYNCPHA_NO_PHASE          (0x00)
#define EVPT_CDD_SA_SYNCPHA_180_PHASE         (0x01)
/***********************************SyncEn**********************************/
#define EVPT_CDD_SA_SYNCEN_DISABLED           (0x00)
#define EVPT_CDD_SA_SYNCEN_ENABLED            (0x01)
/********************************ReqTrk1En**********************************/
#define EVPT_CDD_SA_REQTRK1_VT1_DISABLED      (0x00)
#define EVPT_CDD_SA_REQTRK1_VT1_ENABLED       (0x01)
/********************************ReqTrk2En**********************************/
#define EVPT_CDD_SA_REQTRK2_VT2_DISABLED      (0x00)
#define EVPT_CDD_SA_REQTRK2_VT2_ENABLED       (0x01)
/********************************ReqComEn**********************************/
#define EVPT_CDD_SA_REQCOM_VCO_DISABLED       (0x00)
#define EVPT_CDD_SA_REQCOM_VCO_ENABLED        (0x01)
/********************************ReqVRefEn**********************************/
#define EVPT_CDD_SA_REQVREF_VR_DISABLED       (0x00)
#define EVPT_CDD_SA_REQVREF_VR_ENABLED        (0x01)
/********************************ReqState**********************************/
#define EVPT_CDD_SA_REQSTATE_NONE              (0x00)
#define EVPT_CDD_SA_REQSTATE_INIT              (0x01)
#define EVPT_CDD_SA_REQSTATE_NORMAL            (0x02)
#define EVPT_CDD_SA_REQSTATE_SLEEP             (0x03)
#define EVPT_CDD_SA_REQSTATE_STANDBY           (0x04)
#define EVPT_CDD_SA_REQSTATE_WAKE              (0x05)
#define EVPT_CDD_SA_REQSTATE_RESERVED          (0x06)
/********************************InvertedReqTrk1En**********************************/
#define EVPT_CDD_SA_INVERTED_REQTRK1_VT1_DISABLED      (0x00)
#define EVPT_CDD_SA_INVERTED_REQTRK1_VT1_ENABLED       (0x01)
/********************************InvertedReqTrk2En**********************************/
#define EVPT_CDD_SA_INVERTED_REQTRK2_VT2_DISABLED      (0x00)
#define EVPT_CDD_SA_INVERTED_REQTRK2_VT2_ENABLED       (0x01)
/********************************InvertedReqComEn**********************************/
#define EVPT_CDD_SA_INVERTED_REQCOM_VCO_DISABLED       (0x00)
#define EVPT_CDD_SA_INVERTED_REQCOM_VCO_ENABLED        (0x01)
/********************************InvertedReqVRefEn**********************************/
#define EVPT_CDD_SA_INVERTED_REQVREF_VR_DISABLED       (0x00)
#define EVPT_CDD_SA_INVERTED_REQVREF_VR_ENABLED        (0x01)
/********************************InvertedReqState**********************************/
#define EVPT_CDD_SA_INVERTED_REQSTATE_RESERVED         (0x00)
#define EVPT_CDD_SA_INVERTED_REQSTATE_WAKE             (0x02)
#define EVPT_CDD_SA_INVERTED_REQSTATE_SLEEP            (0x04)
#define EVPT_CDD_SA_INVERTED_REQSTATE_NORMAL           (0x05)
#define EVPT_CDD_SA_INVERTED_REQSTATE_INIT             (0x06)
#define EVPT_CDD_SA_INVERTED_REQSTATE_NONE             (0x07)

/*****************************StbyEn**********************************/
#define EVPT_CDD_SA_STBY_DISABLED             (0x00)
#define EVPT_CDD_SA_STBY_ENABLED              (0x01)
/*****************************SS2Del**********************************/
#define EVPT_CDD_SA_SS2DEL_NO_DELAY           (0x00)
#define EVPT_CDD_SA_SS2DEL_10MS_DELAY         (0x01)
#define EVPT_CDD_SA_SS2DEL_50MS_DELAY         (0x02)
#define EVPT_CDD_SA_SS2DEL_100MS_DELAY        (0x03)
#define EVPT_CDD_SA_SS2DEL_250MS_DELAY        (0x04)
#define EVPT_CDD_SA_SS2DEL_1250MS_DELAY       (0x05)
#define EVPT_CDD_SA_SS2DEL_2500MS_DELAY       (0x06)
/*****************************ErrMonSleepEn**********************************/
#define EVPT_CDD_SA_ERRMONSLEEP_DISABLED      (0x00)
#define EVPT_CDD_SA_ERRMONSLEEP_ENABLED       (0x01)
/*****************************ErrMonEn**********************************/
#define EVPT_CDD_SA_ERRMON_DISABLED           (0x00)
#define EVPT_CDD_SA_ERRMON_ENABLED            (0x01)
/*****************************ErrMonRecEn**********************************/
#define EVPT_CDD_SA_ERRMONREC_DISABLED        (0x00)
#define EVPT_CDD_SA_ERRMONREC_ENABLED         (0x01)
/*****************************ErrMonRecTime**********************************/
#define EVPT_CDD_SA_ERRMONREC_1MS             (0x00)
#define EVPT_CDD_SA_ERRMONREC_2500US          (0x01)
#define EVPT_CDD_SA_ERRMONREC_5MS             (0x02)
#define EVPT_CDD_SA_ERRMONREC_10MS            (0x03)
/*****************************WinWdgErrCounThr**********************************/

/*****************************FunWdgErrCounThr**********************************/

/*****************************WinWdgEn**********************************/
#define EVPT_CDD_SA_WINWDG_DISABLED           (0x00)
#define EVPT_CDD_SA_WINWDG_ENABLED            (0x01)
/*****************************FunWdgEn**********************************/
#define EVPT_CDD_SA_FUNWDG_DISABLED           (0x00)
#define EVPT_CDD_SA_FUNWDG_ENABLED            (0x01)
/*****************************WinWdgSrcSel**********************************/
#define EVPT_CDD_SA_WINWDGSRCSEL_EXTERNAL_WDI (0x00)
#define EVPT_CDD_SA_WINWDGSRCSEL_SPI_WRITE    (0x01)
/*****************************WdgCycTime**********************************/
#define EVPT_CDD_SA_WDGCYC_100US              (0x00)
#define EVPT_CDD_SA_WDGCYC_1MS                (0x01)
/*****************************WdgCycDiv**********************************/
#define EVPT_CDD_SA_WDGCYCDIV_DISABLE         (0x00)
#define EVPT_CDD_SA_WDGCYCDIV_ENABLE          (0x01)
/*****************************WdgInSleepEn**********************************/
#define EVPT_CDD_SA_WDGINSLP_DISABLED_IN_SLEEP   (0x00)
#define EVPT_CDD_SA_WDGINSLP_ENABLED_IN_SLEEP    (0x01)
/*****************************FunWdgHbTimePeriod**********************************/
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_50WD   (0x00)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_100WD  (0x01)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_150WD  (0x02)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_200WD  (0x03)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_250WD  (0x04)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_300WD  (0x05)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_350WD  (0x06)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_400WD  (0x07)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_450WD  (0x08)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_500WD  (0x09)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_550WD  (0x0A)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_600WD  (0x0B)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_650WD  (0x0C)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_700WD  (0x0D)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_750WD  (0x0E)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_800WD  (0x0F)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_850WD  (0x10)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_900WD  (0x11)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_950WD  (0x12)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1000WD (0x13)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1050WD (0x14)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1100WD (0x15)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1150WD (0x16)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1200WD (0x17)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1250WD (0x18)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1300WD (0x19)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1350WD (0x1A)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1400WD (0x1B)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1450WD (0x1C)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1500WD (0x1D)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1550WD (0x1E)
#define EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_1600WD (0x1F)
/*****************************WinWdgTmin**********************************/
#define EVPT_CDD_SA_WINWDGTMIN_CW_50WD        (0x00)
#define EVPT_CDD_SA_WINWDGTMIN_CW_100WD       (0x01)
#define EVPT_CDD_SA_WINWDGTMIN_CW_150WD       (0x02)
#define EVPT_CDD_SA_WINWDGTMIN_CW_200WD       (0x03)
#define EVPT_CDD_SA_WINWDGTMIN_CW_250WD       (0x04)
#define EVPT_CDD_SA_WINWDGTMIN_CW_300WD       (0x05)
#define EVPT_CDD_SA_WINWDGTMIN_CW_350WD       (0x06)
#define EVPT_CDD_SA_WINWDGTMIN_CW_400WD       (0x07)
#define EVPT_CDD_SA_WINWDGTMIN_CW_450WD       (0x08)
#define EVPT_CDD_SA_WINWDGTMIN_CW_500WD       (0x09)
#define EVPT_CDD_SA_WINWDGTMIN_CW_550WD       (0x0A)
#define EVPT_CDD_SA_WINWDGTMIN_CW_600WD       (0x0B)
#define EVPT_CDD_SA_WINWDGTMIN_CW_650WD       (0x0C)
#define EVPT_CDD_SA_WINWDGTMIN_CW_700WD       (0x0D)
#define EVPT_CDD_SA_WINWDGTMIN_CW_750WD       (0x0E)
#define EVPT_CDD_SA_WINWDGTMIN_CW_800WD       (0x0F)
#define EVPT_CDD_SA_WINWDGTMIN_CW_850WD       (0x10)
#define EVPT_CDD_SA_WINWDGTMIN_CW_900WD       (0x11)
#define EVPT_CDD_SA_WINWDGTMIN_CW_950WD       (0x12)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1000WD      (0x13)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1050WD      (0x14)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1100WD      (0x15)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1150WD      (0x16)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1200WD      (0x17)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1250WD      (0x18)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1300WD      (0x19)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1350WD      (0x1A)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1400WD      (0x1B)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1450WD      (0x1C)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1500WD      (0x1D)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1550WD      (0x1E)
#define EVPT_CDD_SA_WINWDGTMIN_CW_1600WD      (0x1F)
/*****************************WinWdgTmargin**********************************/
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_50WD     (0x00)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_100WD    (0x01)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_150WD    (0x02)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_200WD    (0x03)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_250WD    (0x04)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_300WD    (0x05)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_350WD    (0x06)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_400WD    (0x07)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_450WD    (0x08)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_500WD    (0x09)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_550WD    (0x0A)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_600WD    (0x0B)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_650WD    (0x0C)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_700WD    (0x0D)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_750WD    (0x0E)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_800WD    (0x0F)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_850WD    (0x10)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_900WD    (0x11)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_950WD    (0x12)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1000WD   (0x13)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1050WD   (0x14)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1100WD   (0x15)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1150WD   (0x16)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1200WD   (0x17)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1250WD   (0x18)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1300WD   (0x19)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1350WD   (0x1A)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1400WD   (0x1B)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1450WD   (0x1C)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1500WD   (0x1D)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1550WD   (0x1E)
#define EVPT_CDD_SA_WINWDGTMARGIN_OW_1600WD   (0x1F)
/*****************************WakeTimeValLow**********************************/

/*****************************WakeTimeValMid**********************************/

/*****************************WakeTimeValHig**********************************/

/*****************************SafetyPath**********************************/
#define EVPT_CDD_SA_ABIST_SAFETYPATH_SAFE          (0x00)
#define EVPT_CDD_SA_ABIST_SAFETYPATH_INTERRUPT     (0x01)
/*****************************AbistSequence**********************************/
#define EVPT_CDD_SA_ABIST_SINGLE_PREDEFINED        (0x00)
#define EVPT_CDD_SA_ABIST_SINGLE_SINCOMTEST        (0x01)
/*****************************FullPath**********************************/
#define EVPT_CDD_SA_ABIST_FULLPATH_COMPARATOR_ONLY (0x00)
#define EVPT_CDD_SA_ABIST_FULLPATH_FULL_PATH       (0x01)
/*****************************StartAbist**********************************/
#define EVPT_CDD_SA_ABIST_STARTABIST_DONE          (0x00)
#define EVPT_CDD_SA_ABIST_STARTABIST_START         (0x01)
/*****************************AbistClkCheckEn**********************************/
#define EVPT_CDD_SA_ABIST_ABISTCLKCHECKEN_DISABLE  (0x00)
#define EVPT_CDD_SA_ABIST_ABISTCLKCHECKEN_ENABLE   (0x01)
/*****************************OVTrigMonEn**********************************/
#define EVPT_CDD_SA_ABIST_OVTRIGMONEN_DISABLE      (0x00)
#define EVPT_CDD_SA_ABIST_OVTRIGMONEN_ENABLE       (0x01)
/*****************************OVTrk2**********************************/
#define EVPT_CDD_SA_ABIST_OVTRK2_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_OVTRK2_SELECT            (0x01)
/*****************************OVTrk1**********************************/
#define EVPT_CDD_SA_ABIST_OVTRK1_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_OVTRK1_SELECT            (0x01)
/*****************************OVVref**********************************/
#define EVPT_CDD_SA_ABIST_OVVREF_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_OVVREF_SELECT            (0x01)
/*****************************OVCom**********************************/
#define EVPT_CDD_SA_ABIST_OVCOM_NOT_SELECT         (0x00)
#define EVPT_CDD_SA_ABIST_OVCOM_SELECT             (0x01)
/*****************************OVVmon**********************************/
#define EVPT_CDD_SA_ABIST_OVVMON_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_OVVMON_SELECT            (0x01)
/*****************************OVStby**********************************/
#define EVPT_CDD_SA_ABIST_OVSTBY_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_OVSTBY_SELECT            (0x01)
/*****************************OVUc**********************************/
#define EVPT_CDD_SA_ABIST_OVUC_NOT_SELECT          (0x00)
#define EVPT_CDD_SA_ABIST_OVUC_SELECT              (0x01)
/*****************************OVPreg**********************************/
#define EVPT_CDD_SA_ABIST_OVPREG_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_OVPREG_SELECT            (0x01)
/*****************************UVTrk2**********************************/
#define EVPT_CDD_SA_ABIST_UVTRK2_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_UVTRK2_SELECT            (0x01)
/*****************************UVTrk1**********************************/
#define EVPT_CDD_SA_ABIST_UVTRK1_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_UVTRK1_SELECT            (0x01)
/*****************************UVVref**********************************/
#define EVPT_CDD_SA_ABIST_UVVREF_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_UVVREF_SELECT            (0x01)
/*****************************UVCom**********************************/
#define EVPT_CDD_SA_ABIST_UVCOM_NOT_SELECT         (0x00)
#define EVPT_CDD_SA_ABIST_UVCOM_SELECT             (0x01)
/*****************************UVVmon**********************************/
#define EVPT_CDD_SA_ABIST_UVVMON_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_UVVMON_SELECT            (0x01)
/*****************************UVStby**********************************/
#define EVPT_CDD_SA_ABIST_UVSTBY_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_UVSTBY_SELECT            (0x01)
/*****************************UVUc**********************************/
#define EVPT_CDD_SA_ABIST_UVUC_NOT_SELECT          (0x00)
#define EVPT_CDD_SA_ABIST_UVUC_SELECT              (0x01)
/*****************************UVPreg**********************************/
#define EVPT_CDD_SA_ABIST_UVPREG_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_UVPREG_SELECT            (0x01)
/*****************************BiasHigh**********************************/
#define EVPT_CDD_SA_ABIST_BIASHIGH_NOT_SELECT      (0x00)
#define EVPT_CDD_SA_ABIST_BIASHIGH_SELECT          (0x01)
/*****************************BiasLow**********************************/
#define EVPT_CDD_SA_ABIST_BIASLOW_NOT_SELECT       (0x00)
#define EVPT_CDD_SA_ABIST_BIASLOW_SELECT           (0x01)
/*****************************Bg12Ov**********************************/
#define EVPT_CDD_SA_ABIST_BG12OV_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_BG12OV_SELECT            (0x01)
/*****************************Bg12Uv**********************************/
#define EVPT_CDD_SA_ABIST_BG12UV_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_BG12UV_SELECT            (0x01)
/*****************************IntOV**********************************/
#define EVPT_CDD_SA_ABIST_INTOV_NOT_SELECT         (0x00)
#define EVPT_CDD_SA_ABIST_INTOV_SELECT             (0x01)
/*****************************VBatOV**********************************/
#define EVPT_CDD_SA_ABIST_VBATOV_NOT_SELECT        (0x00)
#define EVPT_CDD_SA_ABIST_VBATOV_SELECT            (0x01)
/*****************************BuckFreqSel**********************************/
#define EVPT_CDD_SA_BUCK_FREQ_SEL_NO_CHANGE                   (0x00)
#define EVPT_CDD_SA_BUCK_FREQ_SEL_CHANGE_ADD_15_PERCENT       (0x01)
#define EVPT_CDD_SA_BUCK_FREQ_SEL_CHANGE_ADD_30_PERCENT       (0x02)
#define EVPT_CDD_SA_BUCK_FREQ_SEL_CHANGE_ADD_45_PERCENT       (0x03)
#define EVPT_CDD_SA_BUCK_FREQ_SEL_CHANGE_REDUCE_15_PERCENT    (0x05)
#define EVPT_CDD_SA_BUCK_FREQ_SEL_CHANGE_REDUCE_30_PERCENT    (0x06)
#define EVPT_CDD_SA_BUCK_FREQ_SEL_CHANGE_REDUCE_45_PERCENT    (0x07)
/*****************************FreSpThr**********************************/
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_NO_SPREAD           (0x00)
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_SPREAD_1_PERCENT    (0x2B)
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_SPREAD_2_PERCENT    (0x55)
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_SPREAD_3_PERCENT    (0x80)
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_SPREAD_4_PERCENT    (0xAA)
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_SPREAD_5_PERCENT    (0xD5)
#define EVPT_CDD_SA_BUCK_FREQ_SP_THR_SPREAD_6_PERCENT    (0xFF)

/*****************************DataValiD**********************************/
#define EVPT_CDD_SA_BUCK_DATA_VALID_NO_ACTION           (0x00)
#define EVPT_CDD_SA_BUCK_DATA_VALID_LOAD_NEWPARAMETERS  (0x01)
/*****************************VrOvFailsafeState**********************************/
#define EVPT_CDD_SA_FUNCTRL_VROVF_ENTER_FAILSAFE        (0x00)
#define EVPT_CDD_SA_FUNCTRL_VROVF_KEEP_STATUS           (0x01)
/*****************************LDOucCurrentLimit**********************************/
#define EVPT_CDD_SA_FUNCTRL_LDOUC_CURRENT_LIMIT_600MA   (0x00)
#define EVPT_CDD_SA_FUNCTRL_LDOUC_CURRENT_LIMIT_850MA   (0x01)
/*****************************McuProgEn**********************************/
#define EVPT_CDD_SA_MCU_MON_MCU_PROG_DISABLE            (0x00)
#define EVPT_CDD_SA_MCU_MON_MCU_PROG_ENABLE             (0x01)

#define SA47301_SPI_READ    (0)
#define SA47301_SPI_WRITE   (1)

#define SA_REG_UNLOCK       (0)
#define SA_REG_LOCKED       (1)

#define SA_DEVICE_NONE_MODE                       (0x00U)
#define SA_DEVICE_INIT_MODE                       (0x01U)
#define SA_DEVICE_NORMAL_MODE                     (0x02U)
#define SA_DEVICE_SLEEP_MODE                      (0x03U)
#define SA_DEVICE_STANDBY_MODE                    (0x04U)
#define SA_DEVICE_WAKE_MODE                       (0x05U)



#define CHECK_PTR_NULL_RET(PTR, ERR_CODE) \
    do { \
        if ((PTR) == NULL_PTR) { \
            return (ERR_CODE); \
        } \
    } while(0)

typedef uint16 (*Cdd_Sbc_Sa47301SendCallBackPtr)(uint16 TxData);
typedef uint16 (*Cdd_Sbc_Sa47301ReceiveCallBackPtr)(void);

typedef union 
{
    uint16 FrameData;
    struct{
        uint16 RW :             1;
        uint16 ADDRESS :        6;
        uint16 DATA :           8;
        uint16 PARITY :         1;
    }BITS;
}Cdd_Sa47301DateFrame_TDUN;

typedef struct 
{
    Cdd_Sa47301DateFrame_TDUN TxFrame;
    Cdd_Sa47301DateFrame_TDUN RxFrame;
    
    Cdd_Sbc_Sa47301ReceiveCallBackPtr SpiReceiveCallBack;
    Cdd_Sbc_Sa47301SendCallBackPtr SpiSendCallBack;
} Cdd_Sa47301SpiInfo_TDSTR;

typedef struct 
{
    uint16 WriteEN;
    uint16 RegAddress;
    /* data */
}Cdd_Sa47301RegStatus_TDSTR;

typedef enum 
{
    SA47301_DIAG_TRK2SC     = 0x00,
    SA47301_DIAG_TRK1SC     = 0x01,
    SA47301_DIAG_VREFSG     = 0x02,
    SA47301_DIAG_COMSG      = 0x03,
    SA47301_DIAG_VMONSG     = 0x04,
    SA47301_DIAG_STBYSG     = 0x05,
    SA47301_DIAG_UCSG       = 0x06,
    SA47301_DIAG_PREGSG     = 0x07,
    SA47301_DIAG_TRK2OV     = 0x08,
    SA47301_DIAG_TRK1OV     = 0x09,
    SA47301_DIAG_VREFOV     = 0x0A,
    SA47301_DIAG_COMOV      = 0x0B,
    SA47301_DIAG_VMONOV     = 0x0C,
    SA47301_DIAG_STBYOV     = 0x0D,
    SA47301_DIAG_UCOV       = 0x0E,
    SA47301_DIAG_TRK2UV     = 0x10,
    SA47301_DIAG_TRK1UV     = 0x11,
    SA47301_DIAG_VREFUV     = 0x12,
    SA47301_DIAG_COMUV      = 0x13,
    SA47301_DIAG_VMONUV     = 0x14,
    SA47301_DIAG_STBYUV     = 0x15,
    SA47301_DIAG_UCUV       = 0x16,
    SA47301_DIAG_PREGUV     = 0x17,
    SA47301_DIAG_BIASHI     = 0x18,
    SA47301_DIAG_BIASLOW    = 0x19,
    SA47301_DIAG_RG12OV     = 0x1A,
    SA47301_DIAG_BG12UV     = 0x1B,
    SA47301_DIAG_VBATOV     = 0x1C,
    SA47301_DIAG_MON        = 0x1D,
    SA47301_DIAG_COM        = 0x1E,
    SA47301_DIAG_UC         = 0x1F,
    SA47301_DIAG_PREG       = 0x20,
    SA47301_DIAG_MAX        = 0x21,
} Cdd_Sa47301Diag_TDEM;

typedef struct 
{
    Cdd_Sa47301Diag_TDEM DiagID;
    uint8 Addr;
    uint8 Bit;
    boolean DiagFlag;
} Cdd_Sa47301DiagInfo_TDSTR;

typedef struct
{
    uint8 WakeTimeEn;
    uint8 WakeTimeCyc;
    uint8 Trdel;
    uint8 ResDelayTime;
    uint8 CmonEn;
    uint8 Cthr;
    uint8 SyncPha;
    uint8 SyncEn;
    uint8 ReqTrk1En;
    uint8 ReqTrk2En;
    uint8 ReqComEn;
    uint8 ReqVRefEn;
    uint8 ReqState;
} Cdd_Sa47301DevCfgType_TDSTR;

typedef struct
{
    uint8 StbyEn;
    uint8 SS2Del;
    uint8 ErrMonSleepEn;
    uint8 ErrMonEn;
    uint8 ErrMonRecEn;
    uint8 ErrMonRecTime;
} Cdd_Sa47301SysCfgType_TDSTR;

typedef struct
{
    uint8 WinWdgErrCounThr;
    uint8 FunWdgErrCounThr;
    uint8 WinWdgEn;
    uint8 FunWdgEn;
    uint8 WinWdgSrcSel;
    uint8 WdgCycTime;
    uint8 WdgCycDiv;
    uint8 WdgInSleepEn;
    uint8 FunWdgHbTimePeriod;
    uint8 WinWdgTmin;
    uint8 WinWdgTmargin;
} Cdd_Sa47301WdgCfgType_TDSTR;

typedef struct
{
    uint8 WakeTimeValLowBit;
    uint8 WakeTimeValMidBit;
    uint8 WakeTimeValHigBit;
} Cdd_Sa47301WkTimeCfgType_TDSTR;

typedef struct
{
    uint8 SafetyPath;
    uint8 AbistSequence;
    uint8 FullPath;
    uint8 StartAbist;
    uint8 AbistClkCheckEn;
    uint8 OVTrigMonEn;
    uint8 OVTrk2;
    uint8 OVTrk1;
    uint8 OVVref;
    uint8 OVCom;
    uint8 OVVmon;
    uint8 OVStby;
    uint8 OVUc;
    uint8 OVPreg;
    uint8 UVTrk2;
    uint8 UVTrk1;
    uint8 UVVref;
    uint8 UVCom;
    uint8 UVVmon;
    uint8 UVStby;
    uint8 UVUc;
    uint8 UVPreg;
    uint8 BiasHigh;
    uint8 BiasLow;
    uint8 Bg12Ov;
    uint8 Bg12Uv;
    uint8 IntOV;
    uint8 VBatOV;
} Cdd_Sa47301AbistCfgType_TDSTR;

typedef struct
{
    uint8 BuckFreqSel;
    uint8 FreSpThr;
    uint8 DataValid;
} Cdd_Sa47301BuckCfgType_TDSTR;

typedef struct
{
    uint8 VrOvFailsafeState;
    uint8 LDOucCurrentLimit;
} Cdd_Sa47301FunCtrlCfgType_TDSTR;

typedef struct
{
    uint8 McuProgEn;
} Cdd_Sa47301McuMonCfgType_TDSTR;


typedef struct 
{
    Cdd_Sa47301DevCfgType_TDSTR *DevCfg;
    Cdd_Sa47301SysCfgType_TDSTR *SysCfg;
    Cdd_Sa47301WdgCfgType_TDSTR *WdgCfg;
    Cdd_Sa47301WkTimeCfgType_TDSTR *WkTimeCfg;
    Cdd_Sa47301AbistCfgType_TDSTR *AbistCfg;
    Cdd_Sa47301BuckCfgType_TDSTR *BuckCfg;
    Cdd_Sa47301FunCtrlCfgType_TDSTR *FunCtrlCfg;
    Cdd_Sa47301McuMonCfgType_TDSTR *McuMonCfg;
    /* data */
} Cdd_Sa47301ConfigType_TDSTR;

typedef struct
{
    uint8 UpdateFlag;
    uint8 RefVoltEnable;
    uint8 ComVoltEnable;
    uint8 Trk1VoltEnable;
    uint8 Trk2VoltEnable;
}Cdd_Sa47301LdoCtrl_TDSTR;

typedef enum
{
    CDD_SA47301_CHECKWDG_OK,
    CDD_SA47301_CHECKWDG_NOT_OK,
}Cdd_Sa47301AbistStatus_TDEN;

typedef enum
{
    CDD_SA47301_ABIST_TRK2OV  = 0x00,
    CDD_SA47301_ABIST_TRK1OV  = 0x01,
    CDD_SA47301_ABIST_VREFOV  = 0x02,
    CDD_SA47301_ABIST_COMOV   = 0x03,
    CDD_SA47301_ABIST_VMONOV  = 0x04,
    CDD_SA47301_ABIST_STBYOV  = 0x05,
    CDD_SA47301_ABIST_UCOV    = 0x06,
    CDD_SA47301_ABIST_PREGOV  = 0x07,
    CDD_SA47301_ABIST_TRK2UV  = 0x08,
    CDD_SA47301_ABIST_TRK1UV  = 0x09,
    CDD_SA47301_ABIST_VREFUV  = 0x0A,
    CDD_SA47301_ABIST_COMUV   = 0x0B,
    CDD_SA47301_ABIST_VMONUV  = 0x0C,
    CDD_SA47301_ABIST_STBYUV  = 0x0D,
    CDD_SA47301_ABIST_UCUV    = 0x0E,
    CDD_SA47301_ABIST_PREGUV  = 0x0F,
    CDD_SA47301_ABIST_BIASHI  = 0x10,
    CDD_SA47301_ABIST_BIASLOW = 0x11,
    CDD_SA47301_ABIST_RG12OV  = 0x12,
    CDD_SA47301_ABIST_BG12UV  = 0x13,
    CDD_SA47301_ABIST_INTOV   = 0x14,
    CDD_SA47301_ABIST_VBATOV  = 0x15,
    CDD_SA47301_ABIST_NUM_MAX = 0x16,
}Cdd_Sa47301AbistSelect_TDEN;

typedef struct
{
    uint16 DiagId;
    Cdd_Sa47301Diag_TDEM ChipDiagID; 
}Cdd_Sa47301DiagErrSend_TDSTR;

typedef struct 
{
    Cdd_Sa47301AbistSelect_TDEN AbistName;
    uint8 AbistEnStatus;
    boolean AbistResult;
}Cdd_Sa47301AbistResInfo_TDSTR;

// ABIST测试结果状态
typedef enum
{
    ABIST_RESULT_IDLE = 0x00U,        // 空闲未启动
    ABIST_RESULT_BUSY = 0x01U,        // 测试执行中
    ABIST_RESULT_PASS = 0x02U,         // 测试全部通过
    ABIST_RESULT_FAIL = 0x03U,         // 测试通道失败
    ABIST_RESULT_COMM_ERR = 0x04U,     // SPI通讯失败
    ABIST_RESULT_ABORT_ERR = 0x05U     // ABIST执行被异常中断
} Cdd_Sa47301AbistResult_TDSTR;

typedef enum
{
    SA47301_WWDG,
    SA47301_FWDG,
}Cdd_Sa47301WdgType_TDEN;

typedef struct
{
    uint8  MonSF1Val;        /* 0x21 MONSF1 — 监控状态1(过压)          */
    uint8  MonSF2Val;        /* 0x22 MONSF2 — 监控状态2(欠压)          */
} Cdd_Sa47301ResetSnapshot_TDSTR;
typedef enum
{
    SA47301_ERRMONREC_1MS, 
    SA47301_ERRMONREC_2500US,
    SA47301_ERRMONREC_5MS,  
    SA47301_ERRMONREC_10MS, 
}Cdd_Sa47301ErrMonRecTimetype_TDEM;
typedef struct
{
    boolean ErrMonEn;
    boolean ErrMonSleepEn;
    boolean ErrMonRecEn;
    Cdd_Sa47301ErrMonRecTimetype_TDEM ErrMonRecTime;
}Cdd_Sa47301ErrMonType_STDR;

#ifdef __cplusplus
}
#endif



#endif /* _CDD_SA47301_TYPE_H_ */