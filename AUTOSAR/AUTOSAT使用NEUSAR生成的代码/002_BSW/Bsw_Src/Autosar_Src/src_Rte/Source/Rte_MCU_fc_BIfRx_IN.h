 
/*
************************************************************************************************************************
*
* File name: Rte_MCU_fc_BIfRx_IN.h
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
#ifndef RTE_MCU_FC_BIFRX_IN_H_
#define RTE_MCU_FC_BIFRX_IN_H_

#include "Rte_MCU_fc_BIfRx_IN_Type.h"
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM(UInt8 data);
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
#define Rte_Write_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_ChrgWakeup_State_BSW_f32_ChrgWakeup_State
#define Rte_Write_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_DriveHBridg_Error_BSW_f32_DriveHBridg_Error
#define Rte_Write_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_DriveLBridg_Error_BSW_f32_DriveLBridg_Error
#define Rte_Write_BSW_f32_Drive_Error_BSW_f32_Drive_Error Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_Drive_Error_BSW_f32_Drive_Error
#define Rte_Write_BSW_f32_KL15_State_BSW_f32_KL15_State Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_KL15_State_BSW_f32_KL15_State
#define Rte_Write_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_RDC_CosEvlp_BSW_f32_RDC_CosEvlp
#define Rte_Write_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_RDC_SinEvlp_BSW_f32_RDC_SinEvlp
#define Rte_Write_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_eAngle_rad_BSW_f32_eAngle_rad
#define Rte_Write_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaU_A_BSW_f32_iSmpPhaU_A
#define Rte_Write_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaV_A_BSW_f32_iSmpPhaV_A
#define Rte_Write_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_iSmpPhaW_A_BSW_f32_iSmpPhaW_A
#define Rte_Write_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_nRotateSpd_rpm_BSW_f32_nRotateSpd_rpm
#define Rte_Write_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempU_C_BSW_f32_tIGBTTempU_C
#define Rte_Write_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempV_C_BSW_f32_tIGBTTempV_C
#define Rte_Write_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tIGBTTempW_C_BSW_f32_tIGBTTempW_C
#define Rte_Write_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_tMotTemp_C_BSW_f32_tMotTemp_C
#define Rte_Write_BSW_f32_u12V_V_BSW_f32_u12V_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_u12V_V_BSW_f32_u12V_V
#define Rte_Write_BSW_f32_u5V_V_BSW_f32_u5V_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_u5V_V_BSW_f32_u5V_V
#define Rte_Write_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrRefSmp_V_BSW_f32_uCurrSnsrRefSmp_V
#define Rte_Write_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrUSmp_V_BSW_f32_uCurrSnsrUSmp_V
#define Rte_Write_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrVSmp_V_BSW_f32_uCurrSnsrVSmp_V
#define Rte_Write_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uCurrSnsrWSmp_V_BSW_f32_uCurrSnsrWSmp_V
#define Rte_Write_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V
#define Rte_Write_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDcHVSmp_V_BSW_f32_uDcHVSmp_V
#define Rte_Write_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uDcHV_V_BSW_f32_uDcHV_V
#define Rte_Write_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempUSmp_V_BSW_f32_uIGBTTempUSmp_V
#define Rte_Write_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempVSmp_V_BSW_f32_uIGBTTempVSmp_V
#define Rte_Write_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uIGBTTempWSmp_V_BSW_f32_uIGBTTempWSmp_V
#define Rte_Write_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V Rte_Write_MCU_fc_BIfRx_IN_BSW_f32_uMotTempSmp_V_BSW_f32_uMotTempSmp_V
#define Rte_Write_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UH_BSW_u8_DriFault_UH
#define Rte_Write_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_UL_BSW_u8_DriFault_UL
#define Rte_Write_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VH_BSW_u8_DriFault_VH
#define Rte_Write_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_VL_BSW_u8_DriFault_VL
#define Rte_Write_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WH_BSW_u8_DriFault_WH
#define Rte_Write_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_DriFault_WL_BSW_u8_DriFault_WL
#define Rte_Write_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_HWOCFlt_BSW_u8_HWOCFlt
#define Rte_Write_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_HWOVFlt_BSW_u8_HWOVFlt
#define Rte_Write_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERCNVFlt_BSW_u8_bERCNVFlt
#define Rte_Write_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDCNVFlt_BSW_u8_bERDCNVFlt
#define Rte_Write_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDEXCFlt_BSW_u8_bERDEXCFlt
#define Rte_Write_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDP2Flt_BSW_u8_bERDP2Flt
#define Rte_Write_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSBCFlt_BSW_u8_bERDSBCFlt
#define Rte_Write_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSBSFlt_BSW_u8_bERDSBSFlt
#define Rte_Write_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERDSQFlt_BSW_u8_bERDSQFlt
#define Rte_Write_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bEREXCFlt_BSW_u8_bEREXCFlt
#define Rte_Write_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERHDFlt_BSW_u8_bERHDFlt
#define Rte_Write_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERP2Flt_BSW_u8_bERP2Flt
#define Rte_Write_BSW_u8_bERRFlt_BSW_u8_bERRFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERRFlt_BSW_u8_bERRFlt
#define Rte_Write_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSBCFlt_BSW_u8_bERSBCFlt
#define Rte_Write_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSBSFlt_BSW_u8_bERSBSFlt
#define Rte_Write_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bERSQFlt_BSW_u8_bERSQFlt
#define Rte_Write_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bMcuStorgUnitFlt_BSW_u8_bMcuStorgUnitFlt
#define Rte_Write_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrDosFlt_BSW_u8_bRotyTrfrDosFlt
#define Rte_Write_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrFlt_BSW_u8_bRotyTrfrFlt
#define Rte_Write_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLosFlt_BSW_u8_bRotyTrfrLosFlt
#define Rte_Write_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_bRotyTrfrLotFlt_BSW_u8_bRotyTrfrLotFlt
#define Rte_Write_BSW_u8_stPWM_BSW_u8_stPWM Rte_Write_MCU_fc_BIfRx_IN_BSW_u8_stPWM_BSW_u8_stPWM
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
FUNC(void, MCU_fc_BIfRx_IN_CODE) MCU_fc_BIfRx_IN_Init(void);
FUNC(void, MCU_fc_BIfRx_IN_CODE) MCU_fc_BIfRx_IN_100us(void);
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
#endif /* RTE_MCU_FC_BIFRX_IN_H_ */
 
 
 
