 
/*
************************************************************************************************************************
*
* File name: Rte_BIfTx.h
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
#ifndef RTE_BIFTX_H_
#define RTE_BIFTX_H_

#include "Rte_BIfTx_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz;
extern VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_frqPWM_DynFrq_frqPWM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_EdrvStMac_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV;
extern VAR(Float, RTE_VAR_INIT) Rte_VoltModlnGen_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_DynFrq_frqPWM_DynFrq_frqPWM(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr(P2VAR(Boolean, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr(P2VAR(UInt8, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd(P2VAR(UInt8, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta(P2VAR(UInt8, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BIfTx_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW(P2VAR(Float, AUTOMATIC, RTE_BIfTx_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz(Float data);
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
#define Rte_Read_DynFrq_frqPWM_DynFrq_frqPWM Rte_Read_BIfTx_DynFrq_frqPWM_DynFrq_frqPWM
#define Rte_Read_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr Rte_Read_BIfTx_EdrvStMac_bEnaDrvr_EdrvStMac_bEnaDrvr
#define Rte_Read_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr Rte_Read_BIfTx_EdrvStMac_stGateDrvr_EdrvStMac_stGateDrvr
#define Rte_Read_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd Rte_Read_BIfTx_MMC_MCUCutOffDly_cmd_MMC_MCUCutOffDly_cmd
#define Rte_Read_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta Rte_Read_BIfTx_MMC_MCUWorkMode_sta_MMC_MCUWorkMode_sta
#define Rte_Read_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU Rte_Read_BIfTx_VoltModlnGen_rDutyU_VoltModlnGen_rDutyU
#define Rte_Read_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV Rte_Read_BIfTx_VoltModlnGen_rDutyV_VoltModlnGen_rDutyV
#define Rte_Read_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW Rte_Read_BIfTx_VoltModlnGen_rDutyW_VoltModlnGen_rDutyW
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
#define Rte_Write_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag Rte_Write_BIfTx_BIfTx_bShdBswDiag_BIfTx_bShdBswDiag
#define Rte_Write_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable Rte_Write_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable
#define Rte_Write_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En Rte_Write_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En
#define Rte_Write_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En Rte_Write_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En
#define Rte_Write_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg Rte_Write_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg
#define Rte_Write_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable Rte_Write_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable
#define Rte_Write_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null Rte_Write_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null
#define Rte_Write_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null Rte_Write_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null
#define Rte_Write_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null Rte_Write_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null
#define Rte_Write_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz Rte_Write_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz
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
FUNC(void, BIfTx_CODE) BIfTx_Init(void);
FUNC(void, BIfTx_CODE) fc_BIfTx(void);
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
#endif /* RTE_BIFTX_H_ */
 
 
 
