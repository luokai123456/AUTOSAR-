 
/*
************************************************************************************************************************
*
* File name: Rte_BIfRx.h
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
#ifndef RTE_BIFRX_H_
#define RTE_BIFRX_H_

#include "Rte_BIfRx_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltUH_BIfRx_bFltUH;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltUL_BIfRx_bFltUL;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltVH_BIfRx_bFltVH;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltVL_BIfRx_bFltVL;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltWH_BIfRx_bFltWH;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bFltWL_BIfRx_bFltWL;
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
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iDCAct_BIfRx_iDCAct;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW;
extern VAR(SInt16, RTE_VAR_INIT) Rte_BIfRx_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uLv5_BIfRx_uLv5;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERHDFlt_BlfRx_bERHDFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERP2Flt_BlfRx_bERP2Flt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERRFlt_BlfRx_bERRFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bERSQFlt_BlfRx_bERSQFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V;
extern VAR(Float, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfRx_BIfRx_stPWM_BIfRx_stPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_Task_100us_Core3_QM, RTE_VAR_NOINIT) Rte_Task_100us_Core3_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltUH_BIfRx_bFltUH(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltUL_BIfRx_bFltUL(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltVH_BIfRx_bFltVH(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltVL_BIfRx_bFltVL(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltWH_BIfRx_bFltWH(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bFltWL_BIfRx_bFltWL(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_bT15_BIfRx_bT15(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iDCAct_BIfRx_iDCAct(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm(SInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_stPWM_BIfRx_stPWM(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uLv5_BIfRx_uLv5(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_Drive_Error_BSW_f32_Drive_Error(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_KL15_State_BSW_f32_KL15_State(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_CosN_BSW_f32_RDC_CosN(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_CosP_BSW_f32_RDC_CosP(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_ExctN_BSW_f32_RDC_ExctN(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_ExctP_BSW_f32_RDC_ExctP(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_GroupDelay_BSW_f32_RDC_GroupDelay(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_SinN_BSW_f32_RDC_SinN(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_SinP_BSW_f32_RDC_SinP(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_RDC_TimeStamp_BSW_f32_RDC_TimeStamp(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_u12V_V_BSW_f32_u12V_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_u5V_V_BSW_f32_u5V_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_f32_uSmpRpl_V_BSW_f32_uSmpRpl_V(P2VAR(Float, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERRFlt_BSW_u8_bERRFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfRx_BSW_u8_stPWM_BSW_u8_stPWM(P2VAR(UInt8, AUTOMATIC, RTE_BIfRx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERHDFlt_BlfRx_bERHDFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERP2Flt_BlfRx_bERP2Flt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERRFlt_BlfRx_bERRFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bERSQFlt_BlfRx_bERSQFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode(UInt8 data);
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
#define Rte_IRead_fc_BIfRx_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V() \
  (Rte_Task_100us_Core3_QM.Rte_RB.Rte_BIfRx_fc_BIfRx.Rte_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V.value)

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
#define Rte_Read_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State Rte_Read_BIfRx_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State
#define Rte_Read_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error Rte_Read_BIfRx_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error
#define Rte_Read_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error Rte_Read_BIfRx_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error
#define Rte_Read_BSW_f32_Drive_Error_BSW_f32_Drive_Error Rte_Read_BIfRx_BSW_f32_Drive_Error_BSW_f32_Drive_Error
#define Rte_Read_BSW_f32_KL15_State_BSW_f32_KL15_State Rte_Read_BIfRx_BSW_f32_KL15_State_BSW_f32_KL15_State
#define Rte_Read_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp Rte_Read_BIfRx_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp
#define Rte_Read_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp Rte_Read_BIfRx_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp
#define Rte_Read_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad Rte_Read_BIfRx_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad
#define Rte_Read_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A Rte_Read_BIfRx_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A
#define Rte_Read_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A Rte_Read_BIfRx_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A
#define Rte_Read_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A Rte_Read_BIfRx_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A
#define Rte_Read_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm Rte_Read_BIfRx_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm
#define Rte_Read_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C Rte_Read_BIfRx_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C
#define Rte_Read_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C Rte_Read_BIfRx_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C
#define Rte_Read_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C Rte_Read_BIfRx_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C
#define Rte_Read_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C Rte_Read_BIfRx_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C
#define Rte_Read_BSW_f32_u12V_V_BSW_f32_u12V_V Rte_Read_BIfRx_BSW_f32_u12V_V_BSW_f32_u12V_V
#define Rte_Read_BSW_f32_u5V_V_BSW_f32_u5V_V Rte_Read_BIfRx_BSW_f32_u5V_V_BSW_f32_u5V_V
#define Rte_Read_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V Rte_Read_BIfRx_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V
#define Rte_Read_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V Rte_Read_BIfRx_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V
#define Rte_Read_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V Rte_Read_BIfRx_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V
#define Rte_Read_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V Rte_Read_BIfRx_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V
#define Rte_Read_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V Rte_Read_BIfRx_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V
#define Rte_Read_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V Rte_Read_BIfRx_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V
#define Rte_Read_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V Rte_Read_BIfRx_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V
#define Rte_Read_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V Rte_Read_BIfRx_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V
#define Rte_Read_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V Rte_Read_BIfRx_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V
#define Rte_Read_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V Rte_Read_BIfRx_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V
#define Rte_Read_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH Rte_Read_BIfRx_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH
#define Rte_Read_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL Rte_Read_BIfRx_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL
#define Rte_Read_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH Rte_Read_BIfRx_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH
#define Rte_Read_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL Rte_Read_BIfRx_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL
#define Rte_Read_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH Rte_Read_BIfRx_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH
#define Rte_Read_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL Rte_Read_BIfRx_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL
#define Rte_Read_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt Rte_Read_BIfRx_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt
#define Rte_Read_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt Rte_Read_BIfRx_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt
#define Rte_Read_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt Rte_Read_BIfRx_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt
#define Rte_Read_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt Rte_Read_BIfRx_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt
#define Rte_Read_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt Rte_Read_BIfRx_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt
#define Rte_Read_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt Rte_Read_BIfRx_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt
#define Rte_Read_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt Rte_Read_BIfRx_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt
#define Rte_Read_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt Rte_Read_BIfRx_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt
#define Rte_Read_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt Rte_Read_BIfRx_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt
#define Rte_Read_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt Rte_Read_BIfRx_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt
#define Rte_Read_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt Rte_Read_BIfRx_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt
#define Rte_Read_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt Rte_Read_BIfRx_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt
#define Rte_Read_BSW_u8_bERRFlt_BSW_u8_bERRFlt Rte_Read_BIfRx_BSW_u8_bERRFlt_BSW_u8_bERRFlt
#define Rte_Read_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt Rte_Read_BIfRx_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt
#define Rte_Read_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt Rte_Read_BIfRx_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt
#define Rte_Read_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt Rte_Read_BIfRx_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt
#define Rte_Read_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt Rte_Read_BIfRx_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt
#define Rte_Read_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt Rte_Read_BIfRx_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt
#define Rte_Read_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt Rte_Read_BIfRx_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt
#define Rte_Read_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt Rte_Read_BIfRx_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt
#define Rte_Read_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt Rte_Read_BIfRx_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt
#define Rte_Read_BSW_u8_stPWM_BSW_u8_stPWM Rte_Read_BIfRx_BSW_u8_stPWM_BSW_u8_stPWM
#define Rte_Read_BSW_f32_RDC_CosN_BSW_f32_RDC_CosN Rte_Read_BIfRx_BSW_f32_RDC_CosN_BSW_f32_RDC_CosN
#define Rte_Read_BSW_f32_RDC_CosP_BSW_f32_RDC_CosP Rte_Read_BIfRx_BSW_f32_RDC_CosP_BSW_f32_RDC_CosP
#define Rte_Read_BSW_f32_RDC_ExctN_BSW_f32_RDC_ExctN Rte_Read_BIfRx_BSW_f32_RDC_ExctN_BSW_f32_RDC_ExctN
#define Rte_Read_BSW_f32_RDC_ExctP_BSW_f32_RDC_ExctP Rte_Read_BIfRx_BSW_f32_RDC_ExctP_BSW_f32_RDC_ExctP
#define Rte_Read_BSW_f32_RDC_GroupDelay_BSW_f32_RDC_GroupDelay Rte_Read_BIfRx_BSW_f32_RDC_GroupDelay_BSW_f32_RDC_GroupDelay
#define Rte_Read_BSW_f32_RDC_SinN_BSW_f32_RDC_SinN Rte_Read_BIfRx_BSW_f32_RDC_SinN_BSW_f32_RDC_SinN
#define Rte_Read_BSW_f32_RDC_SinP_BSW_f32_RDC_SinP Rte_Read_BIfRx_BSW_f32_RDC_SinP_BSW_f32_RDC_SinP
#define Rte_Read_BSW_f32_RDC_TimeStamp_BSW_f32_RDC_TimeStamp Rte_Read_BIfRx_BSW_f32_RDC_TimeStamp_BSW_f32_RDC_TimeStamp
#define Rte_Read_BSW_f32_uSmpRpl_V_BSW_f32_uSmpRpl_V Rte_Read_BIfRx_BSW_f32_uSmpRpl_V_BSW_f32_uSmpRpl_V
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
#define Rte_Write_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup Rte_Write_BIfRx_BIfRx_ChrgWakeup_BIfRx_ChrgWakeup
#define Rte_Write_BIfRx_agRotateBsw_BIfRx_agRotateBsw Rte_Write_BIfRx_BIfRx_agRotateBsw_BIfRx_agRotateBsw
#define Rte_Write_BIfRx_bFltUH_BIfRx_bFltUH Rte_Write_BIfRx_BIfRx_bFltUH_BIfRx_bFltUH
#define Rte_Write_BIfRx_bFltUL_BIfRx_bFltUL Rte_Write_BIfRx_BIfRx_bFltUL_BIfRx_bFltUL
#define Rte_Write_BIfRx_bFltVH_BIfRx_bFltVH Rte_Write_BIfRx_BIfRx_bFltVH_BIfRx_bFltVH
#define Rte_Write_BIfRx_bFltVL_BIfRx_bFltVL Rte_Write_BIfRx_BIfRx_bFltVL_BIfRx_bFltVL
#define Rte_Write_BIfRx_bFltWH_BIfRx_bFltWH Rte_Write_BIfRx_BIfRx_bFltWH_BIfRx_bFltWH
#define Rte_Write_BIfRx_bFltWL_BIfRx_bFltWL Rte_Write_BIfRx_BIfRx_bFltWL_BIfRx_bFltWL
#define Rte_Write_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr Rte_Write_BIfRx_BIfRx_bHwOverCurr_BIfRx_bHwOverCurr
#define Rte_Write_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt Rte_Write_BIfRx_BIfRx_bHwOverVolt_BIfRx_bHwOverVolt
#define Rte_Write_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt Rte_Write_BIfRx_BIfRx_bRotyTrfrDosFlt_BIfRx_bRotyTrfrDosFlt
#define Rte_Write_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt Rte_Write_BIfRx_BIfRx_bRotyTrfrFlt_BIfRx_bRotyTrfrFlt
#define Rte_Write_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt Rte_Write_BIfRx_BIfRx_bRotyTrfrLosFlt_BIfRx_bRotyTrfrLosFlt
#define Rte_Write_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt Rte_Write_BIfRx_BIfRx_bRotyTrfrLotFlt_BIfRx_bRotyTrfrLotFlt
#define Rte_Write_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt Rte_Write_BIfRx_BIfRx_bRslvrFlt_BIfRx_bRslvrFlt
#define Rte_Write_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt Rte_Write_BIfRx_BIfRx_bRslvrHBridgFlt_BIfRx_bRslvrHBridgFlt
#define Rte_Write_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt Rte_Write_BIfRx_BIfRx_bRslvrLBridgFlt_BIfRx_bRslvrLBridgFlt
#define Rte_Write_BIfRx_bT15_BIfRx_bT15 Rte_Write_BIfRx_BIfRx_bT15_BIfRx_bT15
#define Rte_Write_BIfRx_frqPwmRx_BIfRx_frqPwmRx Rte_Write_BIfRx_BIfRx_frqPwmRx_BIfRx_frqPwmRx
#define Rte_Write_BIfRx_iDCAct_BIfRx_iDCAct Rte_Write_BIfRx_BIfRx_iDCAct_BIfRx_iDCAct
#define Rte_Write_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef Rte_Write_BIfRx_BIfRx_iSmpPhaRef_BIfRx_iSmpPhaRef
#define Rte_Write_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU Rte_Write_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU
#define Rte_Write_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV Rte_Write_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV
#define Rte_Write_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW Rte_Write_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW
#define Rte_Write_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm Rte_Write_BIfRx_BIfRx_nRotateSpd_rpm_BIfRx_nRotateSpd_rpm
#define Rte_Write_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx Rte_Write_BIfRx_BIfRx_rDutyPwmRx_BIfRx_rDutyPwmRx
#define Rte_Write_BIfRx_stPWM_BIfRx_stPWM Rte_Write_BIfRx_BIfRx_stPWM_BIfRx_stPWM
#define Rte_Write_BIfRx_tPhyMot_BIfRx_tPhyMot Rte_Write_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot
#define Rte_Write_BIfRx_tPhySicU_BIfRx_tPhySicU Rte_Write_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU
#define Rte_Write_BIfRx_tPhySicV_BIfRx_tPhySicV Rte_Write_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV
#define Rte_Write_BIfRx_tPhySicW_BIfRx_tPhySicW Rte_Write_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW
#define Rte_Write_BIfRx_tiGroupDly_BIfRx_tiGroupDly Rte_Write_BIfRx_BIfRx_tiGroupDly_BIfRx_tiGroupDly
#define Rte_Write_BIfRx_tiStamp_BIfRx_tiStamp Rte_Write_BIfRx_BIfRx_tiStamp_BIfRx_tiStamp
#define Rte_Write_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp Rte_Write_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp
#define Rte_Write_BIfRx_uAgCosN_BIfRx_uAgCosN Rte_Write_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN
#define Rte_Write_BIfRx_uAgCosP_BIfRx_uAgCosP Rte_Write_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP
#define Rte_Write_BIfRx_uAgExctN_BIfRx_uAgExctN Rte_Write_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN
#define Rte_Write_BIfRx_uAgExctP_BIfRx_uAgExctP Rte_Write_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP
#define Rte_Write_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp Rte_Write_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp
#define Rte_Write_BIfRx_uAgSinN_BIfRx_uAgSinN Rte_Write_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN
#define Rte_Write_BIfRx_uAgSinP_BIfRx_uAgSinP Rte_Write_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP
#define Rte_Write_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp Rte_Write_BIfRx_BIfRx_uCurrSnsrRefSmp_BIfRx_uCurrSnsrRefSmp
#define Rte_Write_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp Rte_Write_BIfRx_BIfRx_uCurrSnsrUSmp_BIfRx_uCurrSnsrUSmp
#define Rte_Write_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp Rte_Write_BIfRx_BIfRx_uCurrSnsrVSmp_BIfRx_uCurrSnsrVSmp
#define Rte_Write_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp Rte_Write_BIfRx_BIfRx_uCurrSnsrWSmp_BIfRx_uCurrSnsrWSmp
#define Rte_Write_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp Rte_Write_BIfRx_BIfRx_uDcHvRplSmp_BIfRx_uDcHvRplSmp
#define Rte_Write_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp Rte_Write_BIfRx_BIfRx_uDcHvSmp_BIfRx_uDcHvSmp
#define Rte_Write_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp Rte_Write_BIfRx_BIfRx_uIGBTTempUSmp_BIfRx_uIGBTTempUSmp
#define Rte_Write_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp Rte_Write_BIfRx_BIfRx_uIGBTTempVSmp_BIfRx_uIGBTTempVSmp
#define Rte_Write_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp Rte_Write_BIfRx_BIfRx_uIGBTTempWSmp_BIfRx_uIGBTTempWSmp
#define Rte_Write_BIfRx_uLv5_BIfRx_uLv5 Rte_Write_BIfRx_BIfRx_uLv5_BIfRx_uLv5
#define Rte_Write_BIfRx_uLvAct_BIfRx_uLvAct Rte_Write_BIfRx_BIfRx_uLvAct_BIfRx_uLvAct
#define Rte_Write_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp Rte_Write_BIfRx_BIfRx_uMotTempSmp_BIfRx_uMotTempSmp
#define Rte_Write_BIfRx_uSmpHV_BIfRx_uSmpHV Rte_Write_BIfRx_BIfRx_uSmpHV_BIfRx_uSmpHV
#define Rte_Write_BIfRx_uSmpRpl_BIfRx_uSmpRpl Rte_Write_BIfRx_BIfRx_uSmpRpl_BIfRx_uSmpRpl
#define Rte_Write_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss Rte_Write_BIfRx_BlfRx_bBmsRlyInfoNodMiss_BlfRx_bBmsRlyInfoNodMiss
#define Rte_Write_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt Rte_Write_BIfRx_BlfRx_bBusOffFlt_BlfRx_bBusOffFlt
#define Rte_Write_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt Rte_Write_BIfRx_BlfRx_bERCNVFlt_BlfRx_bERCNVFlt
#define Rte_Write_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt Rte_Write_BIfRx_BlfRx_bERDCNVFlt_BlfRx_bERDCNVFlt
#define Rte_Write_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt Rte_Write_BIfRx_BlfRx_bERDEXCFlt_BlfRx_bERDEXCFlt
#define Rte_Write_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt Rte_Write_BIfRx_BlfRx_bERDP2Flt_BlfRx_bERDP2Flt
#define Rte_Write_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt Rte_Write_BIfRx_BlfRx_bERDSBCFlt_BlfRx_bERDSBCFlt
#define Rte_Write_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt Rte_Write_BIfRx_BlfRx_bERDSBSFlt_BlfRx_bERDSBSFlt
#define Rte_Write_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt Rte_Write_BIfRx_BlfRx_bERDSQFlt_BlfRx_bERDSQFlt
#define Rte_Write_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt Rte_Write_BIfRx_BlfRx_bEREXCFlt_BlfRx_bEREXCFlt
#define Rte_Write_BlfRx_bERHDFlt_BlfRx_bERHDFlt Rte_Write_BIfRx_BlfRx_bERHDFlt_BlfRx_bERHDFlt
#define Rte_Write_BlfRx_bERP2Flt_BlfRx_bERP2Flt Rte_Write_BIfRx_BlfRx_bERP2Flt_BlfRx_bERP2Flt
#define Rte_Write_BlfRx_bERRFlt_BlfRx_bERRFlt Rte_Write_BIfRx_BlfRx_bERRFlt_BlfRx_bERRFlt
#define Rte_Write_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt Rte_Write_BIfRx_BlfRx_bERSBCFlt_BlfRx_bERSBCFlt
#define Rte_Write_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt Rte_Write_BIfRx_BlfRx_bERSBSFlt_BlfRx_bERSBSFlt
#define Rte_Write_BlfRx_bERSQFlt_BlfRx_bERSQFlt Rte_Write_BIfRx_BlfRx_bERSQFlt_BlfRx_bERSQFlt
#define Rte_Write_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt Rte_Write_BIfRx_BlfRx_bMcuStorgUnitFlt_BlfRx_bMcuStorgUnitFlt
#define Rte_Write_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss Rte_Write_BIfRx_BlfRx_bPmsEmCtrlNodMiss_BlfRx_bPmsEmCtrlNodMiss
#define Rte_Write_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss Rte_Write_BIfRx_BlfRx_bPmsHvCtrlNodMiss_BlfRx_bPmsHvCtrlNodMiss
#define Rte_Write_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp Rte_Write_BIfRx_BlfRx_uCurrSnsDcSmp_BlfRx_uCurrSnsDcSmp
#define Rte_Write_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt Rte_Write_BIfRx_BlfRx_uDrvSplyVolt_BlfRx_uDrvSplyVolt
#define Rte_Write_Config_InternalCtrlMode_Config_InternalCtrlMode Rte_Write_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
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
FUNC(void, BIfRx_CODE) BIfRx_Init(void);
FUNC(void, BIfRx_CODE) fc_BIfRx(void);
FUNC(void, BIfRx_CODE) fc_Config(void);
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
#endif /* RTE_BIFRX_H_ */
 
 
 
