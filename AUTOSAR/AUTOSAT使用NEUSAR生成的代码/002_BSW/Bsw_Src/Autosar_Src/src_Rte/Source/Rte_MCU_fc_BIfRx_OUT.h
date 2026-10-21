 
/*
************************************************************************************************************************
*
* File name: Rte_MCU_fc_BIfRx_OUT.h
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
#ifndef RTE_MCU_FC_BIFRX_OUT_H_
#define RTE_MCU_FC_BIFRX_OUT_H_

#include "Rte_MCU_fc_BIfRx_OUT_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En;
extern VAR(Boolean, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_BIfTx_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfTx_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable(P2VAR(UInt8, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En(P2VAR(UInt8, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En(P2VAR(Boolean, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg(P2VAR(Boolean, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable(P2VAR(UInt8, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MCU_fc_BIfRx_OUT_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz(P2VAR(Float, AUTOMATIC, RTE_MCU_fc_BIfRx_OUT_APPL_DATA) data);
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
#define Rte_Read_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ASC_Enable_BSW_u8_ASC_Enable
#define Rte_Read_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ClearFlt_Roty_En_BSW_u8_ClearFlt_Roty_En
#define Rte_Read_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_ClearFlt_Volt_Curr_En_BSW_u8_ClearFlt_Volt_Curr_En
#define Rte_Read_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_CutOffDelayEn_flg_BSW_u8_CutOffDelayEn_flg
#define Rte_Read_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable Rte_Read_MCU_fc_BIfRx_OUT_BSW_u8_PWM_Enable_BSW_u8_PWM_Enable
#define Rte_Read_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Uduty_Null_FOC_f32_Uduty_Null
#define Rte_Read_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Vduty_Null_FOC_f32_Vduty_Null
#define Rte_Read_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null Rte_Read_MCU_fc_BIfRx_OUT_FOC_f32_Wduty_Null_FOC_f32_Wduty_Null
#define Rte_Read_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz Rte_Read_MCU_fc_BIfRx_OUT_kFOC_f32_PWMFreq_Hz_kFOC_f32_PWMFreq_Hz
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
FUNC(void, MCU_fc_BIfRx_OUT_CODE) MCU_fc_BIfRx_OUT_Init(void);
FUNC(void, MCU_fc_BIfRx_OUT_CODE) MCU_fc_BIfRx_OUT_100us(void);
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
#endif /* RTE_MCU_FC_BIFRX_OUT_H_ */
 
 
 
