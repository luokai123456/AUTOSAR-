 
/*
************************************************************************************************************************
*
* File name: Rte_Diag.h
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
#ifndef RTE_DIAG_H_
#define RTE_DIAG_H_

#include "Rte_Diag_Type.h"
#include "Rte_DataHandleType.h"

#ifndef RTE_CORE                                     
#ifdef RTE_APPLICATION_HEADER_FILE                   
# error Multiple application header files included.  
#endif                                               
#define RTE_APPLICATION_HEADER_FILE                  
#ifndef RTE_PTR2ARRAYBASETYPE_PASSING                
#define RTE_PTR2ARRAYBASETYPE_PASSING                
#endif                                               
#endif                                               
                   
#ifdef __cplusplus
extern "C"         
{                  
#endif            

/*
************************************************************************************************************************
*    Buffers for Mode Management
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Mode_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_AscEn_flg_Diag_AscEn_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSwngSigFlt_Diag_bSwngSigFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bTqImpsFlt_Diag_bTqImpsFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuModErr_Diag_bVcuModErr;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bT15_BIfRx_bT15;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uLv5_BIfRx_uLv5;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_noDTCNr_Diag_noDTCNr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt;
extern VAR(SInt16, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_nDes_ComRx_nDes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tqDes_ComRx_tqDes;
extern VAR(Float, RTE_VAR_INIT) Rte_EmTq_EmTq_tqEm_EmTq_tqEm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_HvIntlck_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic;
extern VAR(Float, RTE_VAR_INIT) Rte_TqDemCoorn_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Buffers for inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE Helper-Functions prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_bT15_BIfRx_bT15(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uLv5_BIfRx_uLv5(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uLvAct_BIfRx_uLvAct(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_nDes_ComRx_nDes(P2VAR(SInt16, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_stEmWrkMod_ComRx_stEmWrkMod(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_ComRx_tqDes_ComRx_tqDes(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_AscEn_flg_Diag_AscEn_flg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bSwngSigFlt_Diag_bSwngSigFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bTqImpsFlt_Diag_bTqImpsFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bVcuModErr_Diag_bVcuModErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_noDTCNr_Diag_noDTCNr(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_EmTq_tqEm_EmTq_tqEm(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd(P2VAR(Boolean, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg(P2VAR(UInt8, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_TempDev_tPhyMot_TempDev_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_TempDev_tPhySic_TempDev_tPhySic(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Diag_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd(P2VAR(Float, AUTOMATIC, RTE_Diag_APPL_DATA) data);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Rte_Switch_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IRead_<r>_<p>_<d>
*    Rte_IStatus_<r>_<p>_<d>
*    Rte_IWrite_<r>_<p>_<d>
*    Rte_IWriteRef_<r>_<p>_<d>
*    Rte_IInvalidate_<r>_<p>_<d>
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Trigger_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#define Rte_Read_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp Rte_Read_Diag_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp
#define Rte_Read_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp Rte_Read_Diag_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_Diag_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr Rte_Read_Diag_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr
#define Rte_Read_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt Rte_Read_Diag_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt
#define Rte_Read_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt Rte_Read_Diag_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt
#define Rte_Read_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt Rte_Read_Diag_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt
#define Rte_Read_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt Rte_Read_Diag_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt
#define Rte_Read_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt Rte_Read_Diag_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt
#define Rte_Read_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt Rte_Read_Diag_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt
#define Rte_Read_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt Rte_Read_Diag_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt
#define Rte_Read_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt Rte_Read_Diag_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt
#define Rte_Read_BIfRx_bT15_BIfRx_bT15 Rte_Read_Diag_BIfRx_bT15_BIfRx_bT15
#define Rte_Read_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp Rte_Read_Diag_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp
#define Rte_Read_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp Rte_Read_Diag_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp
#define Rte_Read_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp Rte_Read_Diag_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp
#define Rte_Read_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp Rte_Read_Diag_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp
#define Rte_Read_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp Rte_Read_Diag_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp
#define Rte_Read_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp Rte_Read_Diag_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp
#define Rte_Read_BIfRx_uLv5_BIfRx_uLv5 Rte_Read_Diag_BIfRx_uLv5_BIfRx_uLv5
#define Rte_Read_BIfRx_uLvAct_BIfRx_uLvAct Rte_Read_Diag_BIfRx_uLvAct_BIfRx_uLvAct
#define Rte_Read_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp Rte_Read_Diag_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp
#define Rte_Read_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss Rte_Read_Diag_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss
#define Rte_Read_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt Rte_Read_Diag_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt
#define Rte_Read_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt Rte_Read_Diag_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt
#define Rte_Read_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss Rte_Read_Diag_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss
#define Rte_Read_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss Rte_Read_Diag_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss
#define Rte_Read_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt Rte_Read_Diag_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt
#define Rte_Read_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt Rte_Read_Diag_ComRx_bCrcChksFlt_ComRx_bCrcChksFlt
#define Rte_Read_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq Rte_Read_Diag_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq
#define Rte_Read_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt Rte_Read_Diag_ComRx_bRollgCntrFlt_ComRx_bRollgCntrFlt
#define Rte_Read_ComRx_nDes_ComRx_nDes Rte_Read_Diag_ComRx_nDes_ComRx_nDes
#define Rte_Read_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod Rte_Read_Diag_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod
#define Rte_Read_ComRx_stEmWrkMod_ComRx_stEmWrkMod Rte_Read_Diag_ComRx_stEmWrkMod_ComRx_stEmWrkMod
#define Rte_Read_ComRx_tqDes_ComRx_tqDes Rte_Read_Diag_ComRx_tqDes_ComRx_tqDes
#define Rte_Read_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr Rte_Read_Diag_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr
#define Rte_Read_EmTq_tqEm_EmTq_tqEm Rte_Read_Diag_EmTq_tqEm_EmTq_tqEm
#define Rte_Read_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd Rte_Read_Diag_HvIntlck_bMCUHvIntlckClsd_HvIntlck_bMCUHvIntlckClsd
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_Diag_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd Rte_Read_Diag_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd
#define Rte_Read_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Read_Diag_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
#define Rte_Read_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg Rte_Read_Diag_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg
#define Rte_Read_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU Rte_Read_Diag_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU
#define Rte_Read_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV Rte_Read_Diag_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV
#define Rte_Read_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW Rte_Read_Diag_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW
#define Rte_Read_TempDev_tPhyMot_TempDev_tPhyMot Rte_Read_Diag_TempDev_tPhyMot_TempDev_tPhyMot
#define Rte_Read_TempDev_tPhySic_TempDev_tPhySic Rte_Read_Diag_TempDev_tPhySic_TempDev_tPhySic
#define Rte_Read_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd Rte_Read_Diag_TqDemCoorn_tqDesFiltd_TqDemCoorn_tqDesFiltd
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#define Rte_Write_Diag_AscEn_flg_Diag_AscEn_flg Rte_Write_Diag_Diag_AscEn_flg_Diag_AscEn_flg
#define Rte_Write_Diag_FbdDischg_flg_Diag_FbdDischg_flg Rte_Write_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg
#define Rte_Write_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg Rte_Write_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg
#define Rte_Write_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt Rte_Write_Diag_Diag_bActvDchrgTioutFlt_Diag_bActvDchrgTioutFlt
#define Rte_Write_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt Rte_Write_Diag_Diag_bBmsNodMissFlt_Diag_bBmsNodMissFlt
#define Rte_Write_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm Rte_Write_Diag_Diag_bBusOverVoltAlrm_Diag_bBusOverVoltAlrm
#define Rte_Write_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt Rte_Write_Diag_Diag_bBusOverVoltFlt_Diag_bBusOverVoltFlt
#define Rte_Write_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm Rte_Write_Diag_Diag_bBusUnderVoltAlrm_Diag_bBusUnderVoltAlrm
#define Rte_Write_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt Rte_Write_Diag_Diag_bBusVoltSmpLoopFlt_Diag_bBusVoltSmpLoopFlt
#define Rte_Write_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt Rte_Write_Diag_Diag_bCurrSnsrUZrDriftFlt_Diag_bCurrSnsrUZrDriftFlt
#define Rte_Write_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt Rte_Write_Diag_Diag_bCurrSnsrVZrDriftFlt_Diag_bCurrSnsrVZrDriftFlt
#define Rte_Write_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt Rte_Write_Diag_Diag_bCurrSnsrWZrDriftFlt_Diag_bCurrSnsrWZrDriftFlt
#define Rte_Write_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt Rte_Write_Diag_Diag_bDCHvCurrSnsrFlt_Diag_bDCHvCurrSnsrFlt
#define Rte_Write_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt Rte_Write_Diag_Diag_bDrvSplyVoltFlt_Diag_bDrvSplyVoltFlt
#define Rte_Write_Diag_bE2EChksFlt_Diag_bE2EChksFlt Rte_Write_Diag_Diag_bE2EChksFlt_Diag_bE2EChksFlt
#define Rte_Write_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt Rte_Write_Diag_Diag_bHwBusOffFlt_Diag_bHwBusOffFlt
#define Rte_Write_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt Rte_Write_Diag_Diag_bHwOverCurrFlt_Diag_bHwOverCurrFlt
#define Rte_Write_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt Rte_Write_Diag_Diag_bHwOverVoltFlt_Diag_bHwOverVoltFlt
#define Rte_Write_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt Rte_Write_Diag_Diag_bIGBTDrvFlt_Diag_bIGBTDrvFlt
#define Rte_Write_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt Rte_Write_Diag_Diag_bIGBTDrvHBridgFlt_Diag_bIGBTDrvHBridgFlt
#define Rte_Write_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt Rte_Write_Diag_Diag_bIGBTDrvLBridgFlt_Diag_bIGBTDrvLBridgFlt
#define Rte_Write_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt Rte_Write_Diag_Diag_bIntPwrModlFlt_Diag_bIntPwrModlFlt
#define Rte_Write_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt Rte_Write_Diag_Diag_bLvVoltHiLimFlt_Diag_bLvVoltHiLimFlt
#define Rte_Write_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm Rte_Write_Diag_Diag_bLvVoltOverAlrm_Diag_bLvVoltOverAlrm
#define Rte_Write_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt Rte_Write_Diag_Diag_bLvVoltUnderFlt_Diag_bLvVoltUnderFlt
#define Rte_Write_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd Rte_Write_Diag_Diag_bMcuHvIntlckClsd_Diag_bMcuHvIntlckClsd
#define Rte_Write_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt Rte_Write_Diag_Diag_bMcuStorgUnitFlt_Diag_bMcuStorgUnitFlt
#define Rte_Write_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt Rte_Write_Diag_Diag_bMcuTempSnsrShoCircGndFlt_Diag_bMcuTempSnsrShoCircGndFlt
#define Rte_Write_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt Rte_Write_Diag_Diag_bMcuTempSnsrShoCircPwrFlt_Diag_bMcuTempSnsrShoCircPwrFlt
#define Rte_Write_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt Rte_Write_Diag_Diag_bMotOverSpdFlt_Diag_bMotOverSpdFlt
#define Rte_Write_Diag_bMotStalFlt_Diag_bMotStalFlt Rte_Write_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt
#define Rte_Write_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm Rte_Write_Diag_Diag_bMotStrOverTempAlrm_Diag_bMotStrOverTempAlrm
#define Rte_Write_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt Rte_Write_Diag_Diag_bMotStrOverTempFlt_Diag_bMotStrOverTempFlt
#define Rte_Write_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt Rte_Write_Diag_Diag_bMotTempSnsrShoCircGndFlt_Diag_bMotTempSnsrShoCircGndFlt
#define Rte_Write_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt Rte_Write_Diag_Diag_bMotTempSnsrShoCircPwrFlt_Diag_bMotTempSnsrShoCircPwrFlt
#define Rte_Write_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt Rte_Write_Diag_Diag_bPhaCurrImpsFlt_Diag_bPhaCurrImpsFlt
#define Rte_Write_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt Rte_Write_Diag_Diag_bPhaCurrOverFlt_Diag_bPhaCurrOverFlt
#define Rte_Write_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt Rte_Write_Diag_Diag_bPhaCurrSmpLoopFlt_Diag_bPhaCurrSmpLoopFlt
#define Rte_Write_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt Rte_Write_Diag_Diag_bPhaCurrUShoCircGndFlt_Diag_bPhaCurrUShoCircGndFlt
#define Rte_Write_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt Rte_Write_Diag_Diag_bPhaCurrUShoCircPwrFlt_Diag_bPhaCurrUShoCircPwrFlt
#define Rte_Write_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt Rte_Write_Diag_Diag_bPhaCurrVShoCircGndFlt_Diag_bPhaCurrVShoCircGndFlt
#define Rte_Write_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt Rte_Write_Diag_Diag_bPhaCurrVShoCircPwrFlt_Diag_bPhaCurrVShoCircPwrFlt
#define Rte_Write_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt Rte_Write_Diag_Diag_bPhaCurrWShoCircGndFlt_Diag_bPhaCurrWShoCircGndFlt
#define Rte_Write_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt Rte_Write_Diag_Diag_bPhaCurrWShoCircPwrFlt_Diag_bPhaCurrWShoCircPwrFlt
#define Rte_Write_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt Rte_Write_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt
#define Rte_Write_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm Rte_Write_Diag_Diag_bSicOverTempAlrm_Diag_bSicOverTempAlrm
#define Rte_Write_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt Rte_Write_Diag_Diag_bSicOverTempFlt_Diag_bSicOverTempFlt
#define Rte_Write_Diag_bStopMacFlt_Diag_bStopMacFlt Rte_Write_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt
#define Rte_Write_Diag_bSwngSigFlt_Diag_bSwngSigFlt Rte_Write_Diag_Diag_bSwngSigFlt_Diag_bSwngSigFlt
#define Rte_Write_Diag_bTqImpsFlt_Diag_bTqImpsFlt Rte_Write_Diag_Diag_bTqImpsFlt_Diag_bTqImpsFlt
#define Rte_Write_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt Rte_Write_Diag_Diag_bVcuInstrcnExcddFlt_Diag_bVcuInstrcnExcddFlt
#define Rte_Write_Diag_bVcuModErr_Diag_bVcuModErr Rte_Write_Diag_Diag_bVcuModErr_Diag_bVcuModErr
#define Rte_Write_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt Rte_Write_Diag_Diag_bVcuNodMissFlt_Diag_bVcuNodMissFlt
#define Rte_Write_Diag_facDiagTqDern_Diag_facDiagTqDern Rte_Write_Diag_Diag_facDiagTqDern_Diag_facDiagTqDern
#define Rte_Write_Diag_noDTCNr_Diag_noDTCNr Rte_Write_Diag_Diag_noDTCNr_Diag_noDTCNr
#define Rte_Write_Diag_stMcuFltLvl_Diag_stMcuFltLvl Rte_Write_Diag_Diag_stMcuFltLvl_Diag_stMcuFltLvl
#define Rte_Write_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl Rte_Write_Diag_Diag_stMcuSubFltLvl_Diag_stMcuSubFltLvl
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
#ifndef RTE_CORE
#define Rte_Call_CP_SetEvent_CP_SetEvent Rte_Call_Diag_CP_SetEvent_CP_SetEvent
#define Rte_Call_Diag_CP_SetEvent_CP_SetEvent(arg1, arg2) (RTE_E_UNCONNECTED)
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IrvRead_<p>_<d> and Rte_IrvWrite_<p>_<d> Inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    extern declaration of calibration parameters buffers
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_CData (SW-C local calibration parameters) and Rte_Prm (Calibration component calibration parameters)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of Buffers for Memory Block
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Pim (Per-Instance Memory)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, Diag_CODE) Diag_Init(void);
FUNC(void, Diag_CODE) fc_Diag1ms(void);
FUNC(void, Diag_CODE) fc_Diag(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_DIAG_H_ */
 
 
 
