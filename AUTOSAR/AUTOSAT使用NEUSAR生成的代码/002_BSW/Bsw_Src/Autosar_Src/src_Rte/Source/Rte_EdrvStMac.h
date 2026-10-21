 
/*
************************************************************************************************************************
*
* File name: Rte_EdrvStMac.h
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
#ifndef RTE_EDRVSTMAC_H_
#define RTE_EDRVSTMAC_H_

#include "Rte_EdrvStMac_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_DataStorage_flg_MMC_DataStorage_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_FltSta_MMC_FltSta;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUEn_flg_MMC_MCUEn_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCULvOn_flg_MMC_MCULvOn_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUReady_flg_MMC_MCUReady_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUStaSn_MMC_MCUStaSn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfRx_BIfRx_bT15_BIfRx_bT15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfRx_Config_InternalCtrlMode_Config_InternalCtrlMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Diag_Diag_AscEn_flg_Diag_AscEn_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_FbdDischg_flg_Diag_FbdDischg_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bStopMacFlt_Diag_bStopMacFlt;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta;
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta;
extern VAR(SInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd;
extern VAR(Float, RTE_VAR_INIT) Rte_Diag_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_VehicleSpd_ComRx_VehicleSpd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stBrkSwt_ComRx_stBrkSwt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stEmWrkMod_ComRx_stEmWrkMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHndbrk_ComRx_stHndbrk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_stHvCntctr_ComRx_stHvCntctr;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_mflxExct_IdqDes_mflxExct;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqDes_IdqDes_omRtr_IdqDes_omRtr;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd(P2VAR(SInt16, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_BIfRx_bT15_BIfRx_bT15(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_VehicleSpd_ComRx_VehicleSpd(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stBrkSwt_ComRx_stBrkSwt(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stEmWrkMod_ComRx_stEmWrkMod(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stHndbrk_ComRx_stHndbrk(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_ComRx_stHvCntctr_ComRx_stHvCntctr(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Config_InternalCtrlMode_Config_InternalCtrlMode(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_AscEn_flg_Diag_AscEn_flg(P2VAR(UInt8, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_FbdDischg_flg_Diag_FbdDischg_flg(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_Diag_bStopMacFlt_Diag_bStopMacFlt(P2VAR(Boolean, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_IdqDes_mflxExct_IdqDes_mflxExct(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_IdqDes_omRtr_IdqDes_omRtr(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_DataStorage_flg_MMC_DataStorage_flg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_FltSta_MMC_FltSta(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUEn_flg_MMC_MCUEn_flg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCULvOn_flg_MMC_MCULvOn_flg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUReady_flg_MMC_MCUReady_flg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUStaSn_MMC_MCUStaSn(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_EdrvStMac_PMS_VehicleSpd_Rx_PMS_VehicleSpd_Rx(P2VAR(Float, AUTOMATIC, RTE_EdrvStMac_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd Rte_Read_EdrvStMac_AngSwDecod_nRotateSpd_AngSwDecod_nRotateSpd
#define Rte_Read_BIfRx_bT15_BIfRx_bT15 Rte_Read_EdrvStMac_BIfRx_bT15_BIfRx_bT15
#define Rte_Read_ComRx_VehicleSpd_ComRx_VehicleSpd Rte_Read_EdrvStMac_ComRx_VehicleSpd_ComRx_VehicleSpd
#define Rte_Read_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv Rte_Read_EdrvStMac_ComRx_bMcuCutOffLv_ComRx_bMcuCutOffLv
#define Rte_Read_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq Rte_Read_EdrvStMac_ComRx_bMcuEnaReq_ComRx_bMcuEnaReq
#define Rte_Read_ComRx_stBrkSwt_ComRx_stBrkSwt Rte_Read_EdrvStMac_ComRx_stBrkSwt_ComRx_stBrkSwt
#define Rte_Read_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod Rte_Read_EdrvStMac_ComRx_stEmCtrlMod_ComRx_stEmCtrlMod
#define Rte_Read_ComRx_stEmWrkMod_ComRx_stEmWrkMod Rte_Read_EdrvStMac_ComRx_stEmWrkMod_ComRx_stEmWrkMod
#define Rte_Read_ComRx_stHndbrk_ComRx_stHndbrk Rte_Read_EdrvStMac_ComRx_stHndbrk_ComRx_stHndbrk
#define Rte_Read_ComRx_stHvCntctr_ComRx_stHvCntctr Rte_Read_EdrvStMac_ComRx_stHvCntctr_ComRx_stHvCntctr
#define Rte_Read_Config_InternalCtrlMode_Config_InternalCtrlMode Rte_Read_EdrvStMac_Config_InternalCtrlMode_Config_InternalCtrlMode
#define Rte_Read_Diag_AscEn_flg_Diag_AscEn_flg Rte_Read_EdrvStMac_Diag_AscEn_flg_Diag_AscEn_flg
#define Rte_Read_Diag_FbdDischg_flg_Diag_FbdDischg_flg Rte_Read_EdrvStMac_Diag_FbdDischg_flg_Diag_FbdDischg_flg
#define Rte_Read_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg Rte_Read_EdrvStMac_Diag_FbdHvOn_flg_Diag_FbdHvOn_flg
#define Rte_Read_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt Rte_Read_EdrvStMac_Diag_bRotyTrfrFlt_Diag_bRotyTrfrFlt
#define Rte_Read_Diag_bStopMacFlt_Diag_bStopMacFlt Rte_Read_EdrvStMac_Diag_bStopMacFlt_Diag_bStopMacFlt
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_EdrvStMac_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd Rte_Read_EdrvStMac_HvInvDev_uPhyHVFiltd_HvInvDev_uPhyHVFiltd
#define Rte_Read_IdqDes_mflxExct_IdqDes_mflxExct Rte_Read_EdrvStMac_IdqDes_mflxExct_IdqDes_mflxExct
#define Rte_Read_IdqDes_omRtr_IdqDes_omRtr Rte_Read_EdrvStMac_IdqDes_omRtr_IdqDes_omRtr
#define Rte_Read_PMS_VehicleSpd_Rx_PMS_VehicleSpd_Rx Rte_Read_EdrvStMac_PMS_VehicleSpd_Rx_PMS_VehicleSpd_Rx
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
#define Rte_Write_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr Rte_Write_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr
#define Rte_Write_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Write_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Write_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd Rte_Write_EdrvStMac_MMC_AgSelfStudy_cmd_MMC_AgSelfStudy_cmd
#define Rte_Write_MMC_DataStorage_flg_MMC_DataStorage_flg Rte_Write_EdrvStMac_MMC_DataStorage_flg_MMC_DataStorage_flg
#define Rte_Write_MMC_FltSta_MMC_FltSta Rte_Write_EdrvStMac_MMC_FltSta_MMC_FltSta
#define Rte_Write_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta Rte_Write_EdrvStMac_MMC_MCUCtrlMode_sta_MMC_MCUCtrlMode_sta
#define Rte_Write_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd Rte_Write_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd
#define Rte_Write_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd Rte_Write_EdrvStMac_MMC_MCUDischgEn_cmd_MMC_MCUDischgEn_cmd
#define Rte_Write_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg Rte_Write_EdrvStMac_MMC_MCUDischgFail_flg_MMC_MCUDischgFail_flg
#define Rte_Write_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd Rte_Write_EdrvStMac_MMC_MCUEnReq_cmd_MMC_MCUEnReq_cmd
#define Rte_Write_MMC_MCUEn_flg_MMC_MCUEn_flg Rte_Write_EdrvStMac_MMC_MCUEn_flg_MMC_MCUEn_flg
#define Rte_Write_MMC_MCULvOn_flg_MMC_MCULvOn_flg Rte_Write_EdrvStMac_MMC_MCULvOn_flg_MMC_MCULvOn_flg
#define Rte_Write_MMC_MCUReady_flg_MMC_MCUReady_flg Rte_Write_EdrvStMac_MMC_MCUReady_flg_MMC_MCUReady_flg
#define Rte_Write_MMC_MCUStaSn_MMC_MCUStaSn Rte_Write_EdrvStMac_MMC_MCUStaSn_MMC_MCUStaSn
#define Rte_Write_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd Rte_Write_EdrvStMac_MMC_MCUStopMac_cmd_MMC_MCUStopMac_cmd
#define Rte_Write_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta Rte_Write_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta
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
FUNC(void, EdrvStMac_CODE) EdrvStMac_Init(void);
FUNC(void, EdrvStMac_CODE) fc_EdrvStMac1ms(void);
FUNC(void, EdrvStMac_CODE) fc_EdrvStMac(void);
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
#endif /* RTE_EDRVSTMAC_H_ */
 
 
 
