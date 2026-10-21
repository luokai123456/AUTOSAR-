/*
************************************************************************************************************************
*
* File name: Rte_App1_Application_Core3_QM.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#define RTE_CORE


/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Os.h"
#include "Rte_Type.h"
#include "Rte_Main.h"
#include "Rte_IoHwAbSelf.h"
#include "Rte_AngEmDev.h"
#include "Rte_AngOfstCal.h"
#include "Rte_AngSwDecod.h"
#include "Rte_BIfRx.h"
#include "Rte_BIfTx.h"
#include "Rte_Diag.h"
#include "Rte_DynFrq.h"
#include "Rte_EdrvStMac.h"
#include "Rte_HrmcInj.h"
#include "Rte_HvInvDev.h"
#include "Rte_IdqAct.h"
#include "Rte_IdqCtrl.h"
#include "Rte_MCU_DID.h"
#include "Rte_MCU_UDS_Interface.h"
#include "Rte_MCU_fc_BIfRx_IN.h"
#include "Rte_MCU_fc_BIfRx_OUT.h"
#include "Rte_PhaCurrDev.h"
#include "Rte_VoltModlnGen.h"
#include "Rte_VoltModlnlnp.h"
#include "ASW_Task_Instead.h"
#include "EcuM.h"
#include "Rte_Cbk.h"
#include "Rte_Hook.h"
#include "Com.h"

/*
************************************************************************************************************************
    Timer handling
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Local Types
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    API for enable / disable interrupts up to the systemLevel . 
************************************************************************************************************************
*/
#define Rte_DisableOSInterrupts() SuspendOSInterrupts()
#define Rte_EnableOSInterrupts() ResumeOSInterrupts()

/*
************************************************************************************************************************
*    Definition of Buffers for unqueued S/R 
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd = 0.0F;
VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd = 0;
VAR(UInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs = 0U;
VAR(SInt8, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir = 0;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_BIfRx_BIfRx_stPWM_BIfRx_stPWM = 0U;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_noDTCNr_Diag_noDTCNr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta = 0U;
VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uRpl_HvInvDev_uRpl = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDa_IdqAct_iDa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQa_IdqAct_iQa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW = 0.0F;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngOfstCal_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltUH_BIfRx_bFltUH = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltUL_BIfRx_bFltUL = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltVH_BIfRx_bFltVH = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltVL_BIfRx_bFltVL = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltWH_BIfRx_bFltWH = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltWL_BIfRx_bFltWL = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bT15_BIfRx_bT15 = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iDCAct_BIfRx_iDCAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW = 0.0F;
VAR(SInt16, RTE_VAR_INIT) Rte_BIfRx_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm = 0;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uLv5_BIfRx_uLv5 = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERHDFlt_BlfRx_bERHDFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERP2Flt_BlfRx_bERP2Flt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERRFlt_BlfRx_bERRFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERSQFlt_BlfRx_bERSQFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable = 0U;
VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_AscEn_flg_Diag_AscEn_flg = 0U;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt = FALSE;
VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt = 0U;
VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSwngSigFlt_Diag_bSwngSigFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bTqImpsFlt_Diag_bTqImpsFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt = FALSE;
VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuModErr_Diag_bVcuModErr = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_frqPWM_DynFrq_frqPWM = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_DataStorage_flg_MMC_DataStorage_flg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_FltSta_MMC_FltSta = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUEn_flg_MMC_MCUEn_flg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCULvOn_flg_MMC_MCULvOn_flg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUReady_flg_MMC_MCUReady_flg = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUStaSn_MMC_MCUStaSn = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd = 0U;
VAR(Float, RTE_VAR_INIT) Rte_HrmcInj_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iAa_IdqAct_iAa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iBa_IdqAct_iBa = 0.0F;
VAR(Boolean, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv = FALSE;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDa_IdqCtrl_uDa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQa_IdqCtrl_uQa = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_IdqCtrl_IdqCtrl_uStr_IdqCtrl_uStr = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error = 0U;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V = 0.0F;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM = 0U;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta = 0.0F;
VAR(Float, RTE_VAR_INIT) Rte_VoltModlnlnp_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp = 0.0F;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
VAR(Rte_ts_Task_100us_Core3_QM, RTE_VAR_NOINIT) Rte_Task_100us_Core3_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_NO_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    TxAck/ModeSwitchAck Flags
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Update Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Timeout Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Invalid Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Never Received Flags for each external Rx Signal with handleNeverReceived != 0
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Per-Instance Memory variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Buffers for inter-runnable variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Data structures for mode management
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Definition of Rte functions
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num); 
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) RteBuff_PushRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC(void, RTE_CODE) RteBuff_PopRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PopLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PushLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Push(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Pop(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) Rte_MemSet(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, uint8 c, uint32 num);
FUNC(void, RTE_CODE) Rte_MoveFront(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
FUNC(void, RTE_CODE) Rte_MoveBehind(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Client Server API (Rte_Call)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_CALL Func
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    COM-Callbacks for COM Invalid Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM-Callbacks for DataSendCompletedEvent triggered runnables for transmission acknowledgement and error handling
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function definition for Rx Update Notification
************************************************************************************************************************
*/



/*
************************************************************************************************************************
*    LdCom Callbacks Function definition for TX Trigger Transmit
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Internal/External Tx connections
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngEmDev_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngOfstCal_AngOfstCal_iDaDes_AngOfstCal_iDaDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngOfstCal_AngOfstCal_iQaDes_AngOfstCal_iQaDes = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngOfstCal_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngOfstCal_AngOfstCal_stOfstCalFns_AngOfstCal_stOfstCalFns = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_bSigDegratn_AngSwDecod_bSigDegratn = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_bSigLoss_AngSwDecod_bSigLoss = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_bTrckgLoss_AngSwDecod_bTrckgLoss = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_nRotateMeclAgSpd_AngSwDecod_nRotateMeclAgSpd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(sint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(uint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir(sint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_AngSwDecod_AngSwDecod_stRotateDir_AngSwDecod_stRotateDir = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltUH_BIfRx_bFltUH(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bFltUH_BIfRx_bFltUH = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltUL_BIfRx_bFltUL(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bFltUL_BIfRx_bFltUL = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltVH_BIfRx_bFltVH(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bFltVH_BIfRx_bFltVH = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltVL_BIfRx_bFltVL(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bFltVL_BIfRx_bFltVL = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltWH_BIfRx_bFltWH(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bFltWH_BIfRx_bFltWH = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltWL_BIfRx_bFltWL(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bFltWL_BIfRx_bFltWL = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bT15_BIfRx_bT15(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_bT15_BIfRx_bT15 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iDCAct_BIfRx_iDCAct(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_iDCAct_BIfRx_iDCAct = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm(sint16 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_stPWM_BIfRx_stPWM(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_stPWM_BIfRx_stPWM = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uLv5_BIfRx_uLv5(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uLv5_BIfRx_uLv5 = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERHDFlt_BlfRx_bERHDFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERHDFlt_BlfRx_bERHDFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERP2Flt_BlfRx_bERP2Flt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERP2Flt_BlfRx_bERP2Flt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERRFlt_BlfRx_bERRFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERRFlt_BlfRx_bERRFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERSQFlt_BlfRx_bERSQFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bERSQFlt_BlfRx_bERSQFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_AscEn_flg_Diag_AscEn_flg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_AscEn_flg_Diag_AscEn_flg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bSwngSigFlt_Diag_bSwngSigFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bSwngSigFlt_Diag_bSwngSigFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bTqImpsFlt_Diag_bTqImpsFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bTqImpsFlt_Diag_bTqImpsFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bVcuModErr_Diag_bVcuModErr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bVcuModErr_Diag_bVcuModErr = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_noDTCNr_Diag_noDTCNr(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_noDTCNr_Diag_noDTCNr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DynFrq_DynFrq_frqPWM_DynFrq_frqPWM(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DynFrq_DynFrq_frqPWM_DynFrq_frqPWM = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_DataStorage_flg_MMC_DataStorage_flg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_DataStorage_flg_MMC_DataStorage_flg = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_FltSta_MMC_FltSta(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_FltSta_MMC_FltSta = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUEn_flg_MMC_MCUEn_flg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUEn_flg_MMC_MCUEn_flg = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCULvOn_flg_MMC_MCULvOn_flg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCULvOn_flg_MMC_MCULvOn_flg = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUReady_flg_MMC_MCUReady_flg(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUReady_flg_MMC_MCUReady_flg = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUStaSn_MMC_MCUStaSn(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUStaSn_MMC_MCUStaSn = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HrmcInj_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HrmcInj_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HvInvDev_HvInvDev_uRpl_HvInvDev_uRpl(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_HvInvDev_HvInvDev_uRpl_HvInvDev_uRpl = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iAa_IdqAct_iAa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iAa_IdqAct_iAa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iBa_IdqAct_iBa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iBa_IdqAct_iBa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iDa_IdqAct_iDa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iDa_IdqAct_iDa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iQa_IdqAct_iQa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iQa_IdqAct_iQa = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv(boolean data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_bUSqrtLimActv_IdqCtrl_bUSqrtLimActv = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_facOverModlnMaxSqd_IdqCtrl_facOverModlnMaxSqd = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uDa_IdqCtrl_uDa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uDa_IdqCtrl_uDa = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uPwmMax_IdqCtrl_uPwmMax = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uQa_IdqCtrl_uQa(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uQa_IdqCtrl_uQa = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uRsv_IdqCtrl_uRsv = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uSqrtMax_IdqCtrl_uSqrtMax = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uSqrtRsvSclg_IdqCtrl_uSqrtRsvSclg = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqCtrl_IdqCtrl_uStr_IdqCtrl_uStr(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_IdqCtrl_IdqCtrl_uStr_IdqCtrl_uStr = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM(uint8 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnlnp_VoltModlnlnp_uAlphaCmp_VoltModlnlnp_uAlphaCmp = *(&data);
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta = *(&data);

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_VoltModlnlnp_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp(float32 data)
{
    Std_ReturnType ret = RTE_E_OK;
    Rte_VoltModlnlnp_VoltModlnlnp_uBetaCmp_VoltModlnlnp_uBetaCmp = *(&data);
    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Definition of Internal/External Rx connections
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgCosN_BIfRx_uAgCosN(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgCosP_BIfRx_uAgCosP(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgExctN_BIfRx_uAgExctN(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgExctP_BIfRx_uAgExctP(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgSinN_BIfRx_uAgSinN(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgSinP_BIfRx_uAgSinP(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_IdqCtrl_uDaPI_IdqCtrl_uDaPI(P2VAR(Float, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uDaPI_IdqCtrl_uDaPI;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_IdqCtrl_uQaPI_IdqCtrl_uQaPI(P2VAR(Float, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uQaPI_IdqCtrl_uQaPI;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngOfstCal_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_AngOfstCal_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_AngOfstCal_agOfst_AngOfstCal_agOfst(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngOfstCal_AngOfstCal_agOfst_AngOfstCal_agOfst;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_agRotateBsw_BIfRx_agRotateBsw(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt(P2VAR(Boolean, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_tiGroupDly_BIfRx_tiGroupDly(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_BIfRx_tiStamp_BIfRx_tiStamp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_IdqDes_iDaDes_IdqDes_iDaDes(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_IdqDes_iQaDes_IdqDes_iQaDes(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngSwDecod_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_AngSwDecod_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_Drive_Error_BSW_f32_Drive_Error(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_KL15_State_BSW_f32_KL15_State(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_CosN_BSW_f32_RDC_CosN(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_CosP_BSW_f32_RDC_CosP(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_ExctN_BSW_f32_RDC_ExctN(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_ExctP_BSW_f32_RDC_ExctP(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_GroupDelay_BSW_f32_RDC_GroupDelay(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_SinN_BSW_f32_RDC_SinN(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_SinP_BSW_f32_RDC_SinP(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_TimeStamp_BSW_f32_RDC_TimeStamp(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_u12V_V_BSW_f32_u12V_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_u5V_V_BSW_f32_u5V_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uSmpRpl_V_BSW_f32_uSmpRpl_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERRFlt_BSW_u8_bERRFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_stPWM_BSW_u8_stPWM(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_DynFrq_frqPWM_DynFrq_frqPWM(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_frqPWM_DynFrq_frqPWM;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd(P2VAR(UInt8, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bT15_BIfRx_bT15(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bT15_BIfRx_bT15;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uLv5_BIfRx_uLv5(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uLv5_BIfRx_uLv5;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uLvAct_BIfRx_uLvAct(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_nDes_ComRx_nDes(P2VAR(SInt16, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_stEmWrkMod_ComRx_stEmWrkMod(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_tqDes_ComRx_tqDes(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_EmTq_tqEm_EmTq_tqEm(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EmTq_EmTq_tqEm_EmTq_tqEm;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvIntlck_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_TempDev_tPhyMot_TempDev_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_TempDev_tPhySic_TempDev_tPhySic(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DynFrq_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_DynFrq_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_BIfRx_bT15_BIfRx_bT15(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_bT15_BIfRx_bT15;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_VehicleSpd_ComRx_VehicleSpd(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stBrkSwt_ComRx_stBrkSwt(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stEmWrkMod_ComRx_stEmWrkMod(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stHndbrk_ComRx_stHndbrk(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stHvCntctr_ComRx_stHvCntctr(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Config_InternalCtrlMode_Config_InternalCtrlMode(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_AscEn_flg_Diag_AscEn_flg(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_AscEn_flg_Diag_AscEn_flg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_FbdDischg_flg_Diag_FbdDischg_flg(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_bStopMacFlt_Diag_bStopMacFlt(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_IdqDes_mflxExct_IdqDes_mflxExct(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_IdqDes_omRtr_IdqDes_omRtr(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_omRtr_IdqDes_omRtr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_PMS_VehicleSpd_Rx_PMS_VehicleSpd_Rx(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data)
{
    *(data) = 0.0F;

    return RTE_E_UNCONNECTED;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HrmcInj_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_HrmcInj_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HrmcInj_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_HrmcInj_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HrmcInj_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg(P2VAR(Float, AUTOMATIC, RTE_HrmcInj_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_tqEmDesWoDampg_ExtTqDes_tqEmDesWoDampg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HvInvDev_BIfRx_uSmpHV_BIfRx_uSmpHV(P2VAR(Float, AUTOMATIC, RTE_HvInvDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HvInvDev_BIfRx_uSmpRpl_BIfRx_uSmpRpl(P2VAR(Float, AUTOMATIC, RTE_HvInvDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HvInvDev_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_HvInvDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_HvInvDev_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy(P2VAR(Boolean, AUTOMATIC, RTE_HvInvDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HrmcInj_HrmcInj_iQaDesWithHrmcInj_HrmcInj_iQaDesWithHrmcInj;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iAa_IdqAct_iAa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iAa_IdqAct_iAa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iBa_IdqAct_iBa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iBa_IdqAct_iBa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iDa_IdqAct_iDa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqAct_iQa_IdqAct_iQa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_iDaDes_IdqDes_iDaDes(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_iDaDes_IdqDes_iDaDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_iQaDes_IdqDes_iQaDes(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_iQaDes_IdqDes_iQaDes;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_indtDa_IdqDes_indtDa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_indtDa_IdqDes_indtDa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_indtQa_IdqDes_indtQa(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_indtQa_IdqDes_indtQa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_mflxExct_IdqDes_mflxExct(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_omRtr_IdqDes_omRtr(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_omRtr_IdqDes_omRtr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqCtrl_IdqDes_resStr_IdqDes_resStr(P2VAR(Float, AUTOMATIC, RTE_IdqCtrl_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqDes_IdqDes_resStr_IdqDes_resStr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_DTC_IPU_DTC(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_DTC_IPU_DTC;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_DischgState_IPU_DischgState(P2VAR(UInt8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_DischgState_IPU_DischgState;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_HVBusCur_IPU_HVBusCur(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_HVBusVolt_500_IPU_HVBusVolt_500(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgInvrT_IPU_IsgInvrT(P2VAR(UInt8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgMotT_IPU_IsgMotT(P2VAR(UInt8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_DID_PMS_DriverDemandTorque_PMS_DriverDemandTorque(P2VAR(UInt16, AUTOMATIC, RTE_MCU_DID_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable(P2VAR(UInt8, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En(P2VAR(UInt8, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En(P2VAR(Boolean, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg(P2VAR(Boolean, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable(P2VAR(UInt8, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy(P2VAR(Boolean, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt(P2VAR(UInt8, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnlnp_VoltModlnlnp_uAlpha_VoltModlnlnp_uAlpha;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnGen_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta(P2VAR(Float, AUTOMATIC, RTE_VoltModlnGen_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_VoltModlnlnp_VoltModlnlnp_uBeta_VoltModlnlnp_uBeta;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_AngSwDecod_AngSwDecod_frqRtrElec_AngSwDecod_frqRtrElec;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqAct_iDa_IdqAct_iDa(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqAct_iQa_IdqAct_iQa(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uDaSclg_IdqCtrl_uDaSclg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_IdqCtrl_IdqCtrl_uQaSclg_IdqCtrl_uQaSclg;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_VoltModlnlnp_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_VoltModlnlnp_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
  
/*
************************************************************************************************************************
*    Inter-runnable variable access
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Runnable Entities for Nv Block Components
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Task bodies for RTE controlled tasks
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(SWC_Init_Task_Core3)
{
    Core3_Runnable_Task_Init();

    MCU_fc_BIfRx_IN_Init();

    MCU_fc_BIfRx_OUT_Init();

    AngEmDev_Init();

    AngOfstCal_Init();

    AngSwDecod_Init();

    BIfRx_Init();

    BIfTx_Init();

    Diag_Init();

    DynFrq_Init();

    EdrvStMac_Init();

    HvInvDev_Init();

    IdqAct_Init();

    IdqCtrl_Init();

    PhaCurrDev_Init();

    VoltModlnGen_Init();

    VoltModlnlnp_Init();

    HrmcInj_Init();

    (void)TerminateTask();
}

TASK(Task_100us_Core3_QM)
{
    // MCU_fc_BIfRx_IN_100us();

    // *(&Rte_Task_100us_Core3_QM.Rte_RB.Rte_BIfRx_fc_BIfRx.Rte_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V.value) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V;
    // fc_BIfRx();

    // fc_HvInvDev();

    // fc_PhaCurrDev();

    // fc_AngEmDev();

    // fc_AngSwDecod();

    // fc_AngOfstCal();

    // fc_IdqAct();

    // fc_HrmcInj();

    // fc_IdqCtrl();

    // fc_VoltModlnInp();

    // fc_Diag();

    // fc_EdrvStMac();

    // fc_VoltModlnGen();

    // fc_DynFrq();

    // fc_BIfTx();

    // MCU_fc_BIfRx_OUT_100us();

    (void)TerminateTask();
}

TASK(Task_1ms_Core3_QM)
{
    Core3_Runnable_App_1ms();

    Core3_Runnable_Bsw_1ms();

    fc_Diag1ms();

    fc_EdrvStMac1ms();

    fc_HrmcInj1ms();

    fc_Config();

    (void)TerminateTask();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task_UDS_Core3_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT_UDS_CORE3_QM
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0400_22_RE
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DTC_0X0402_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DISCHGSTATE_0X04CF_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSCUR_0X0409_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSVOLT_500_0X0408_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGMOTT_0X040B_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGSPDACTSGN_0X0403_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_MOTORTEMP_0X040D_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMAX_0X0406_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMIN_0X0407_CS_READDATA
                        | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA);
        (void)GetEvent(APP1_TASK_UDS_CORE3_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT_UDS_CORE3_QM
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0400_22_RE
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DTC_0X0402_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DISCHGSTATE_0X04CF_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSCUR_0X0409_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSVOLT_500_0X0408_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGMOTT_0X040B_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGSPDACTSGN_0X0403_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_MOTORTEMP_0X040D_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMAX_0X0406_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMIN_0X0407_CS_READDATA
                         | RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA));

        #if 0 //UDS不使用
        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0400_22_RE) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type));
            }

            SWC_TestDCM_DataServices_DspData_0x0400_22_RE( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DTC_0X0402_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_DTC_0x0402_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type));
            }

            IPU_DTC_0x0402_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_DTC_0x0402_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DISCHGSTATE_0X04CF_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type));
            }

            IPU_DischgState_0X04CF_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSCUR_0X0409_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type));
            }

            IPU_HVBusCur_0x0409_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSVOLT_500_0X0408_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type));
            }

            IPU_HVBusVolt_500_0x0408_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGMOTT_0X040B_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type));
            }

            IPU_IsgMotT_0x040B_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGSPDACTSGN_0X0403_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type));
            }

            IPU_IsgSpdActSgn_0x0403_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type));
            }

            IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_MOTORTEMP_0X040D_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type));
            }

            IPU_MotorTemp_0x040D_CS_ReadData( cs_Server.OpStatus, &cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMAX_0X0406_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type));
            }

            IPU_TqAvlIsgMax_0x0406_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMIN_0X0407_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type));
            }

            IPU_TqAvlIsgMin_0x0407_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData.Rte_ServerCompleted = TRUE;
        }

        if ((ev & RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA) != (EventMaskType)0)
        {
            Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type cs_Server = {0};

            Rte_DisableOSInterrupts();
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type));
            }

            PMS_DriverDemandTorque_0x0405_CS_ReadData( cs_Server.OpStatus, cs_Server.Data, &cs_Server.ErrorCode);


            Rte_DisableOSInterrupts();
            void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData);
            Rte_EnableOSInterrupts();
            if(NULL_PTR != pPush)
            {
                Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type));
            }

            Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData.Rte_ServerCompleted = TRUE;
        }
        #endif

    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Mode Switch API (Rte_Switch)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Mode Mode API (Rte_Mode)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    IsUpdate Func
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_ISUPDATE Func
************************************************************************************************************************
*/

