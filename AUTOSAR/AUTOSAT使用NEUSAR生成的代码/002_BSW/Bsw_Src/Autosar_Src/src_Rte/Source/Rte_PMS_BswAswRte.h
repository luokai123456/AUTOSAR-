 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_BswAswRte.h
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
#ifndef RTE_PMS_BSWASWRTE_H_
#define RTE_PMS_BSWASWRTE_H_

#include "Rte_PMS_BswAswRte_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear(UInt8 data);
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
#define Rte_Write_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1 Rte_Write_PMS_BswAswRte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1
#define Rte_Write_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2 Rte_Write_PMS_BswAswRte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2
#define Rte_Write_ECU_Net_Config_Data1_ECU_Net_Config_Data1 Rte_Write_PMS_BswAswRte_ECU_Net_Config_Data1_ECU_Net_Config_Data1
#define Rte_Write_ECU_Net_Config_Data2_ECU_Net_Config_Data2 Rte_Write_PMS_BswAswRte_ECU_Net_Config_Data2_ECU_Net_Config_Data2
#define Rte_Write_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb
#define Rte_Write_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb
#define Rte_Write_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb Rte_Write_PMS_BswAswRte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb
#define Rte_Write_F190_VIN_Byte0_F190_VIN_Byte0 Rte_Write_PMS_BswAswRte_F190_VIN_Byte0_F190_VIN_Byte0
#define Rte_Write_F190_VIN_Byte1_F190_VIN_Byte1 Rte_Write_PMS_BswAswRte_F190_VIN_Byte1_F190_VIN_Byte1
#define Rte_Write_F190_VIN_Byte10_F190_VIN_Byte10 Rte_Write_PMS_BswAswRte_F190_VIN_Byte10_F190_VIN_Byte10
#define Rte_Write_F190_VIN_Byte11_F190_VIN_Byte11 Rte_Write_PMS_BswAswRte_F190_VIN_Byte11_F190_VIN_Byte11
#define Rte_Write_F190_VIN_Byte12_F190_VIN_Byte12 Rte_Write_PMS_BswAswRte_F190_VIN_Byte12_F190_VIN_Byte12
#define Rte_Write_F190_VIN_Byte13_F190_VIN_Byte13 Rte_Write_PMS_BswAswRte_F190_VIN_Byte13_F190_VIN_Byte13
#define Rte_Write_F190_VIN_Byte14_F190_VIN_Byte14 Rte_Write_PMS_BswAswRte_F190_VIN_Byte14_F190_VIN_Byte14
#define Rte_Write_F190_VIN_Byte15_F190_VIN_Byte15 Rte_Write_PMS_BswAswRte_F190_VIN_Byte15_F190_VIN_Byte15
#define Rte_Write_F190_VIN_Byte16_F190_VIN_Byte16 Rte_Write_PMS_BswAswRte_F190_VIN_Byte16_F190_VIN_Byte16
#define Rte_Write_F190_VIN_Byte2_F190_VIN_Byte2 Rte_Write_PMS_BswAswRte_F190_VIN_Byte2_F190_VIN_Byte2
#define Rte_Write_F190_VIN_Byte3_F190_VIN_Byte3 Rte_Write_PMS_BswAswRte_F190_VIN_Byte3_F190_VIN_Byte3
#define Rte_Write_F190_VIN_Byte4_F190_VIN_Byte4 Rte_Write_PMS_BswAswRte_F190_VIN_Byte4_F190_VIN_Byte4
#define Rte_Write_F190_VIN_Byte5_F190_VIN_Byte5 Rte_Write_PMS_BswAswRte_F190_VIN_Byte5_F190_VIN_Byte5
#define Rte_Write_F190_VIN_Byte6_F190_VIN_Byte6 Rte_Write_PMS_BswAswRte_F190_VIN_Byte6_F190_VIN_Byte6
#define Rte_Write_F190_VIN_Byte7_F190_VIN_Byte7 Rte_Write_PMS_BswAswRte_F190_VIN_Byte7_F190_VIN_Byte7
#define Rte_Write_F190_VIN_Byte8_F190_VIN_Byte8 Rte_Write_PMS_BswAswRte_F190_VIN_Byte8_F190_VIN_Byte8
#define Rte_Write_F190_VIN_Byte9_F190_VIN_Byte9 Rte_Write_PMS_BswAswRte_F190_VIN_Byte9_F190_VIN_Byte9
#define Rte_Write_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2 Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2
#define Rte_Write_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3 Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3
#define Rte_Write_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4 Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4
#define Rte_Write_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6 Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6
#define Rte_Write_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7 Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7
#define Rte_Write_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8 Rte_Write_PMS_BswAswRte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8
#define Rte_Write_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2 Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2
#define Rte_Write_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3 Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3
#define Rte_Write_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4 Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4
#define Rte_Write_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6 Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6
#define Rte_Write_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7 Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7
#define Rte_Write_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8 Rte_Write_PMS_BswAswRte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8
#define Rte_Write_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg Rte_Write_PMS_BswAswRte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg
#define Rte_Write_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg Rte_Write_PMS_BswAswRte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg
#define Rte_Write_PMS_SWCompileDay_PMS_SWCompileDay Rte_Write_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay
#define Rte_Write_PMS_SWCompileMonth_PMS_SWCompileMonth Rte_Write_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth
#define Rte_Write_PMS_SWCompileYear_PMS_SWCompileYear Rte_Write_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear
#define Rte_Write_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb Rte_Write_PMS_BswAswRte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb
#define Rte_Write_vild_b_adcCanBusOff_vild_b_adcCanBusOff Rte_Write_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff
#define Rte_Write_vild_b_evCanBusOff_vild_b_evCanBusOff Rte_Write_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff
#define Rte_Write_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr
#define Rte_Write_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr
#define Rte_Write_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr Rte_Write_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr
#define Rte_Write_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr
#define Rte_Write_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr
#define Rte_Write_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr
#define Rte_Write_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr Rte_Write_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr
#define Rte_Write_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr
#define Rte_Write_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr
#define Rte_Write_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr Rte_Write_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr
#define Rte_Write_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr
#define Rte_Write_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr
#define Rte_Write_vild_b_flgClearDTC_vild_b_flgClearDTC Rte_Write_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC
#define Rte_Write_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr
#define Rte_Write_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr Rte_Write_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr
#define Rte_Write_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr
#define Rte_Write_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr
#define Rte_Write_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr Rte_Write_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr
#define Rte_Write_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr
#define Rte_Write_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr Rte_Write_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr
#define Rte_Write_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr
#define Rte_Write_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr
#define Rte_Write_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr Rte_Write_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr
#define Rte_Write_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr Rte_Write_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr
#define Rte_Write_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr Rte_Write_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr
#define Rte_Write_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff Rte_Write_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff
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
FUNC(void, PMS_BswAswRte_CODE) PMS_BswAswRte_Step(void);
FUNC(void, PMS_BswAswRte_CODE) PMS_BswAswRte_Init(void);
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
#endif /* RTE_PMS_BSWASWRTE_H_ */
 
 
 
