 
/*
************************************************************************************************************************
*
* File name: Rte_swc_GetInputInterface.h
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
#ifndef RTE_SWC_GETINPUTINTERFACE_H_
#define RTE_SWC_GETINPUTINTERFACE_H_

#include "Rte_swc_GetInputInterface_Type.h"
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
*    declaration of application error code
************************************************************************************************************************
*/

#ifndef RTE_E_FunctionInhibition_NOT_OK
#define RTE_E_FunctionInhibition_NOT_OK (1U)
#endif


/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/
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
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_ACTemp_ErrFLg_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ACTemp_ErrFLg);
#define Rte_Call_BSWIOSP_Get_ACUCom_ErrFLg_Operation Rte_Call_swc_GetInputInterface_BSWIOSP_Get_ACUCom_ErrFLg_Operation
#define Rte_Call_swc_GetInputInterface_BSWIOSP_Get_ACUCom_ErrFLg_Operation(arg1) (BSWIOSP_Get_ACUCom_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_ACUCom_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ACUCom_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_BMUTempOver_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUTempOver_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BalnCtlModl_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_BattIsoDet_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BattIsoDet_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellVoltSampleDiscon_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CCD_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CCD_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CCS_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CCS_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CDC_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CDC_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CEM_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CEM_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CHM_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CHM_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CMLP_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CMLP_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CML_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CML_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CRM_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CRM_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CRO_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CRO_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CSDP_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CSDP_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CSD_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CSD_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_CST_UpdataTime_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CST_UpdataTime);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) OBC_Sts_Timeout);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_DCTemp_ErrFLg_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) DCTemp_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) EVCANBusOff_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_HCMCom_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) HCMCom_ErrFLg);
#define Rte_Call_BSWIOSP_Get_HCME2E_ErrFLg_Operation Rte_Call_swc_GetInputInterface_BSWIOSP_Get_HCME2E_ErrFLg_Operation
#define Rte_Call_swc_GetInputInterface_BSWIOSP_Get_HCME2E_ErrFLg_Operation(arg1) (BSWIOSP_Get_HCME2E_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_HCME2E_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) HCME2E_ErrFLg);
#define Rte_Call_BSWIOSP_Get_HCMbusoff_ErrFLg_Operation Rte_Call_swc_GetInputInterface_BSWIOSP_Get_HCMbusoff_ErrFLg_Operation
#define Rte_Call_swc_GetInputInterface_BSWIOSP_Get_HCMbusoff_ErrFLg_Operation(arg1) (BSWIOSP_Get_HCMbusoff_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_HCMbusoff_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) HCMbusoff_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_IntCANE2E_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) IntCANE2E_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_NvM_Save_Ok_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) NvM_Save_Ok);
#define Rte_Call_BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation Rte_Call_swc_GetInputInterface_BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation
#define Rte_Call_swc_GetInputInterface_BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation(arg1) (BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) PMS_BMSH_Ctrl_Timeout);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RlyKCVoltSample_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RlyKMVoltSample_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RlyKNVoltSample_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_STHW_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) STHW_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Service0x14_Count_Operation(P2VAR(UInt16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Service0x14_Count);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_StsElectroniclockContor_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) StsElectroniclockContor);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_VCUCom_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) VCUCom_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_WeakUpFlg_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) WeakUpFlg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_bCANWakeUp_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) bCANWakeUp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUCellVSt_Operation(P2VAR(uint32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUCellVSt);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUCell_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUCell);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUChipTemp_Operation(P2VAR(sint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUChipTemp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUTempSt_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUTempSt);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUTemp_Operation(P2VAR(sint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUTemp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BalanceTemp_Operation(P2VAR(sint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BalanceTemp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellTEffective_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellTEffective);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellTempException_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellTempException);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellVEffective_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellVEffective);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellVoltException_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellVoltException);
FUNC(void, swc_GetInputInterface_CODE) DiagcEvent_GetEvent(VAR(UInt16, RTE_swc_GetInputInterface_APPL_DATA) DTC_ID, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) EventStatusByte);
FUNC(void, swc_GetInputInterface_CODE) DiagcEvent_SetEvent(VAR(UInt16, RTE_swc_GetInputInterface_APPL_DATA) ID, VAR(UInt8_T, RTE_swc_GetInputInterface_APPL_DATA) EventStatus);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID10_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID11_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID12_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID13_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID14_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID15_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID16_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID17_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID18_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID19_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID1_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID20_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID21_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID22_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID23_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID24_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID25_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID26_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID27_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID28_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID29_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID2_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID30_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID3_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID4_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID5_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID6_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID7_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID8_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID9_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
#define Rte_Call_HvSysSample_Get_Current_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_Current_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_Current_Operation(arg1) (HvSysSample_Get_Current_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_Current_Operation(P2VAR(SInt16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Current);
#define Rte_Call_HvSysSample_Get_NegInsulationRes_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_NegInsulationRes_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_NegInsulationRes_Operation(arg1) (HvSysSample_Get_NegInsulationRes_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_NegInsulationRes_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) NegInsulationRes);
#define Rte_Call_HvSysSample_Get_PosInsulationRes_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_PosInsulationRes_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_PosInsulationRes_Operation(arg1) (HvSysSample_Get_PosInsulationRes_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_PosInsulationRes_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) PosInsulationRes);
#define Rte_Call_HvSysSample_Get_RelayKCVoltage_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_RelayKCVoltage_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_RelayKCVoltage_Operation(arg1) (HvSysSample_Get_RelayKCVoltage_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKCVoltage_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKCVoltage);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKHVoltage_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKHVoltage);
#define Rte_Call_HvSysSample_Get_RelayKMVoltage_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_RelayKMVoltage_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_RelayKMVoltage_Operation(arg1) (HvSysSample_Get_RelayKMVoltage_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKMVoltage_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKMVoltage);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKNClsSts_U8_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKNClsSts_U8);
#define Rte_Call_HvSysSample_Get_RelayKNVoltage_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_RelayKNVoltage_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_RelayKNVoltage_Operation(arg1) (HvSysSample_Get_RelayKNVoltage_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKNVoltage_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKNVoltage);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleCountCurrent_U16_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleCountCurrent_U16);
#define Rte_Call_HvSysSample_Get_SampleCountInsRes_U16_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_SampleCountInsRes_U16_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_SampleCountInsRes_U16_Operation(arg1) (HvSysSample_Get_SampleCountInsRes_U16_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleCountInsRes_U16_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleCountInsRes_U16);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleCountTotalVol_U16_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleCountTotalVol_U16);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidBat_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidBat_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidCurrent_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidCurrent_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidIsolation_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidIsolation_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKC_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKC_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKH_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKH_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKM_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKM_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKN_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKN_U8);
#define Rte_Call_HvSysSample_Get_TotalVoltage_Operation Rte_Call_swc_GetInputInterface_HvSysSample_Get_TotalVoltage_Operation
#define Rte_Call_swc_GetInputInterface_HvSysSample_Get_TotalVoltage_Operation(arg1) (HvSysSample_Get_TotalVoltage_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_TotalVoltage_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) TotalVoltage);
FUNC(void, swc_GetInputInterface_CODE) If_AdcConvertValueInput_GetAdcConvertValue(VAR(UInt32, RTE_swc_GetInputInterface_APPL_DATA) NumId, P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) value);
FUNC(void, swc_GetInputInterface_CODE) If_IcuDutyValueInput_GetIcuDutyValue(VAR(UInt32, RTE_swc_GetInputInterface_APPL_DATA) NumId, P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) value);
FUNC(void, swc_GetInputInterface_CODE) If_IcuPeriodValueInput_GetIcuPeriodValue(VAR(UInt32, RTE_swc_GetInputInterface_APPL_DATA) NumId, P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) value);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_NowSystemTick_Operation(P2VAR(UInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) NowSystemTick);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_RTCStateFault_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RTCStateFault);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_ReadDay_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ReadDay);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_ReadHour_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ReadHour);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_ReadMinute_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ReadMinute);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_ReadMonth_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ReadMonth);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_ReadSecond_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ReadSecond);
FUNC(void, swc_GetInputInterface_CODE) RTC_Get_ReadYear_Operation(P2VAR(UInt16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ReadYear);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_SWC_GETINPUTINTERFACE_H_ */
 
 
 
