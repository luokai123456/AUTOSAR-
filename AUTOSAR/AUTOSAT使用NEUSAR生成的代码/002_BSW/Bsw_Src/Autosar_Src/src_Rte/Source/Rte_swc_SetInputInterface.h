 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SetInputInterface.h
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
#ifndef RTE_SWC_SETINPUTINTERFACE_H_
#define RTE_SWC_SETINPUTINTERFACE_H_

#include "Rte_swc_SetInputInterface_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp;
extern VAR(rt_Array_UInt16_130, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUCell_BMUCell;
extern VAR(rt_Array_UInt32_4, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt;
extern VAR(rt_Array_SInt16_8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp;
extern VAR(rt_Array_SInt16_32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp;
extern VAR(rt_Array_UInt8_32, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt;
extern VAR(rt_Array_SInt16_8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellTempException_CellTempException;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadDay_ReadDay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadHour_ReadHour;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadMinute_ReadMinute;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadMonth_ReadMonth;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadSecond_ReadSecond;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_SetInputInterface_RTC_ReadYear_ReadYear;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUCell_BMUCell(P2CONST(uint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt(P2CONST(uint32, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp(P2CONST(sint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp(P2CONST(sint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt(P2CONST(uint8, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp(P2CONST(sint16, AUTOMATIC, RTE_swc_SetInputInterface_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellTempException_CellTempException(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage(SInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16(UInt16 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick(UInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault(SInt32 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadDay_ReadDay(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadHour_ReadHour(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadMinute_ReadMinute(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadMonth_ReadMonth(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadSecond_ReadSecond(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SetInputInterface_RTC_ReadYear_ReadYear(UInt16 data);
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
#define Rte_Write_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg
#define Rte_Write_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg
#define Rte_Write_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg
#define Rte_Write_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg
#define Rte_Write_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg
#define Rte_Write_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime
#define Rte_Write_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime
#define Rte_Write_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime
#define Rte_Write_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime
#define Rte_Write_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime
#define Rte_Write_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime
#define Rte_Write_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime
#define Rte_Write_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime
#define Rte_Write_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime
#define Rte_Write_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime
#define Rte_Write_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime
#define Rte_Write_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime Rte_Write_swc_SetInputInterface_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime
#define Rte_Write_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout Rte_Write_swc_SetInputInterface_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout
#define Rte_Write_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg
#define Rte_Write_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg
#define Rte_Write_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg
#define Rte_Write_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg
#define Rte_Write_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok Rte_Write_swc_SetInputInterface_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok
#define Rte_Write_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg
#define Rte_Write_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg
#define Rte_Write_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg
#define Rte_Write_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg
#define Rte_Write_BSWIOSP_Service0x14_Count_Service0x14_Count Rte_Write_swc_SetInputInterface_BSWIOSP_Service0x14_Count_Service0x14_Count
#define Rte_Write_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor Rte_Write_swc_SetInputInterface_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor
#define Rte_Write_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg Rte_Write_swc_SetInputInterface_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg
#define Rte_Write_BSWIOSP_WeakUpFlg_WeakUpFlg Rte_Write_swc_SetInputInterface_BSWIOSP_WeakUpFlg_WeakUpFlg
#define Rte_Write_BSWIOSP_bCANWakeUp_bCANWakeUp Rte_Write_swc_SetInputInterface_BSWIOSP_bCANWakeUp_bCANWakeUp
#define Rte_Write_BmuSample_BMUCell_BMUCell Rte_Write_swc_SetInputInterface_BmuSample_BMUCell_BMUCell
#define Rte_Write_BmuSample_BMUCellVSt_BMUCellVSt Rte_Write_swc_SetInputInterface_BmuSample_BMUCellVSt_BMUCellVSt
#define Rte_Write_BmuSample_BMUChipTemp_BMUChipTemp Rte_Write_swc_SetInputInterface_BmuSample_BMUChipTemp_BMUChipTemp
#define Rte_Write_BmuSample_BMUTemp_BMUTemp Rte_Write_swc_SetInputInterface_BmuSample_BMUTemp_BMUTemp
#define Rte_Write_BmuSample_BMUTempSt_BMUTempSt Rte_Write_swc_SetInputInterface_BmuSample_BMUTempSt_BMUTempSt
#define Rte_Write_BmuSample_BalanceTemp_BalanceTemp Rte_Write_swc_SetInputInterface_BmuSample_BalanceTemp_BalanceTemp
#define Rte_Write_BmuSample_CellTEffective_CellTEffective Rte_Write_swc_SetInputInterface_BmuSample_CellTEffective_CellTEffective
#define Rte_Write_BmuSample_CellTempException_CellTempException Rte_Write_swc_SetInputInterface_BmuSample_CellTempException_CellTempException
#define Rte_Write_BmuSample_CellVEffective_CellVEffective Rte_Write_swc_SetInputInterface_BmuSample_CellVEffective_CellVEffective
#define Rte_Write_BmuSample_CellVoltException_CellVoltException Rte_Write_swc_SetInputInterface_BmuSample_CellVoltException_CellVoltException
#define Rte_Write_HvSysSample_RelayKHVoltage_RelayKHVoltage Rte_Write_swc_SetInputInterface_HvSysSample_RelayKHVoltage_RelayKHVoltage
#define Rte_Write_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8 Rte_Write_swc_SetInputInterface_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8
#define Rte_Write_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16 Rte_Write_swc_SetInputInterface_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16
#define Rte_Write_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16 Rte_Write_swc_SetInputInterface_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16
#define Rte_Write_HvSysSample_SampleValidBat_U8_SampleValidBat_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidBat_U8_SampleValidBat_U8
#define Rte_Write_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8
#define Rte_Write_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8
#define Rte_Write_HvSysSample_SampleValidKC_U8_SampleValidKC_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKC_U8_SampleValidKC_U8
#define Rte_Write_HvSysSample_SampleValidKH_U8_SampleValidKH_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKH_U8_SampleValidKH_U8
#define Rte_Write_HvSysSample_SampleValidKM_U8_SampleValidKM_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKM_U8_SampleValidKM_U8
#define Rte_Write_HvSysSample_SampleValidKN_U8_SampleValidKN_U8 Rte_Write_swc_SetInputInterface_HvSysSample_SampleValidKN_U8_SampleValidKN_U8
#define Rte_Write_RTC_NowSystemTick_NowSystemTick Rte_Write_swc_SetInputInterface_RTC_NowSystemTick_NowSystemTick
#define Rte_Write_RTC_RTCStateFault_RTCStateFault Rte_Write_swc_SetInputInterface_RTC_RTCStateFault_RTCStateFault
#define Rte_Write_RTC_ReadDay_ReadDay Rte_Write_swc_SetInputInterface_RTC_ReadDay_ReadDay
#define Rte_Write_RTC_ReadHour_ReadHour Rte_Write_swc_SetInputInterface_RTC_ReadHour_ReadHour
#define Rte_Write_RTC_ReadMinute_ReadMinute Rte_Write_swc_SetInputInterface_RTC_ReadMinute_ReadMinute
#define Rte_Write_RTC_ReadMonth_ReadMonth Rte_Write_swc_SetInputInterface_RTC_ReadMonth_ReadMonth
#define Rte_Write_RTC_ReadSecond_ReadSecond Rte_Write_swc_SetInputInterface_RTC_ReadSecond_ReadSecond
#define Rte_Write_RTC_ReadYear_ReadYear Rte_Write_swc_SetInputInterface_RTC_ReadYear_ReadYear
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_ACTemp_ErrFLg_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) ACTemp_ErrFLg);
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
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_IntCANE2E_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) IntCANE2E_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_NvM_Save_Ok_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) NvM_Save_Ok);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RlyKCVoltSample_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RlyKMVoltSample_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RlyKNVoltSample_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_STHW_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) STHW_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_Service0x14_Count_Operation(P2VAR(UInt16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Service0x14_Count);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_StsElectroniclockContor_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) StsElectroniclockContor);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_VCUCom_ErrFLg_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) VCUCom_ErrFLg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_WeakUpFlg_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) WeakUpFlg);
FUNC(void, swc_GetInputInterface_CODE) BSWIOSP_Get_bCANWakeUp_Operation(P2VAR(Boolean, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) bCANWakeUp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUCell_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUCell);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUCellVSt_Operation(P2VAR(uint32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUCellVSt);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUChipTemp_Operation(P2VAR(sint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUChipTemp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUTemp_Operation(P2VAR(sint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUTemp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BMUTempSt_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BMUTempSt);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_BalanceTemp_Operation(P2VAR(sint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) BalanceTemp);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellTEffective_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellTEffective);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellTempException_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellTempException);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellVEffective_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellVEffective);
FUNC(void, swc_GetInputInterface_CODE) BmuSample_Get_CellVoltException_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) CellVoltException);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKHVoltage_Operation(P2VAR(SInt32, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKHVoltage);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_RelayKNClsSts_U8_Operation(P2VAR(UInt8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) RelayKNClsSts_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleCountCurrent_U16_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleCountCurrent_U16);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleCountTotalVol_U16_Operation(P2VAR(uint16, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleCountTotalVol_U16);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidBat_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidBat_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidCurrent_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidCurrent_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidIsolation_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidIsolation_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKC_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKC_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKH_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKH_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKM_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKM_U8);
FUNC(void, swc_GetInputInterface_CODE) HvSysSample_Get_SampleValidKN_U8_Operation(P2VAR(uint8, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) SampleValidKN_U8);
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

#ifndef RTE_CORE
#define Rte_Call_BSWIOSP_Get_ACTemp_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_ACTemp_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_ACTemp_ErrFLg_Operation(arg1) (BSWIOSP_Get_ACTemp_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_BMUTempOver_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_BMUTempOver_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_BMUTempOver_ErrFLg_Operation(arg1) (BSWIOSP_Get_BMUTempOver_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation(arg1) (BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_BattIsoDet_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_BattIsoDet_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_BattIsoDet_ErrFLg_Operation(arg1) (BSWIOSP_Get_BattIsoDet_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation(arg1) (BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CCD_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CCD_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CCD_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CCD_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CCS_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CCS_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CCS_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CCS_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CDC_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CDC_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CDC_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CDC_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CEM_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CEM_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CEM_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CEM_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CHM_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CHM_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CHM_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CHM_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CMLP_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CMLP_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CMLP_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CMLP_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CML_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CML_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CML_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CML_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CRM_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CRM_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CRM_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CRM_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CRO_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CRO_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CRO_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CRO_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CSDP_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CSDP_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CSDP_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CSDP_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CSD_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CSD_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CSD_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CSD_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_CST_UpdataTime_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CST_UpdataTime_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_CST_UpdataTime_Operation(arg1) (BSWIOSP_Get_Com_CST_UpdataTime_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation(arg1) (BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_DCTemp_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_DCTemp_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_DCTemp_ErrFLg_Operation(arg1) (BSWIOSP_Get_DCTemp_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation(arg1) (BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_HCMCom_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_HCMCom_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_HCMCom_ErrFLg_Operation(arg1) (BSWIOSP_Get_HCMCom_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_IntCANE2E_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_IntCANE2E_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_IntCANE2E_ErrFLg_Operation(arg1) (BSWIOSP_Get_IntCANE2E_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_NvM_Save_Ok_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_NvM_Save_Ok_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_NvM_Save_Ok_Operation(arg1) (BSWIOSP_Get_NvM_Save_Ok_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation(arg1) (BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation(arg1) (BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation(arg1) (BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_STHW_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_STHW_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_STHW_ErrFLg_Operation(arg1) (BSWIOSP_Get_STHW_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_Service0x14_Count_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Service0x14_Count_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_Service0x14_Count_Operation(arg1) (BSWIOSP_Get_Service0x14_Count_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_StsElectroniclockContor_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_StsElectroniclockContor_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_StsElectroniclockContor_Operation(arg1) (BSWIOSP_Get_StsElectroniclockContor_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_VCUCom_ErrFLg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_VCUCom_ErrFLg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_VCUCom_ErrFLg_Operation(arg1) (BSWIOSP_Get_VCUCom_ErrFLg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_WeakUpFlg_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_WeakUpFlg_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_WeakUpFlg_Operation(arg1) (BSWIOSP_Get_WeakUpFlg_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BSWIOSP_Get_bCANWakeUp_Operation Rte_Call_swc_SetInputInterface_BSWIOSP_Get_bCANWakeUp_Operation
#define Rte_Call_swc_SetInputInterface_BSWIOSP_Get_bCANWakeUp_Operation(arg1) (BSWIOSP_Get_bCANWakeUp_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_BMUCell_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUCell_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUCell_Operation(arg1) (BmuSample_Get_BMUCell_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_BMUCellVSt_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUCellVSt_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUCellVSt_Operation(arg1) (BmuSample_Get_BMUCellVSt_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_BMUChipTemp_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUChipTemp_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUChipTemp_Operation(arg1) (BmuSample_Get_BMUChipTemp_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_BMUTemp_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUTemp_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUTemp_Operation(arg1) (BmuSample_Get_BMUTemp_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_BMUTempSt_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUTempSt_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_BMUTempSt_Operation(arg1) (BmuSample_Get_BMUTempSt_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_BalanceTemp_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_BalanceTemp_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_BalanceTemp_Operation(arg1) (BmuSample_Get_BalanceTemp_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_CellTEffective_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_CellTEffective_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_CellTEffective_Operation(arg1) (BmuSample_Get_CellTEffective_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_CellTempException_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_CellTempException_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_CellTempException_Operation(arg1) (BmuSample_Get_CellTempException_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_CellVEffective_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_CellVEffective_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_CellVEffective_Operation(arg1) (BmuSample_Get_CellVEffective_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_BmuSample_Get_CellVoltException_Operation Rte_Call_swc_SetInputInterface_BmuSample_Get_CellVoltException_Operation
#define Rte_Call_swc_SetInputInterface_BmuSample_Get_CellVoltException_Operation(arg1) (BmuSample_Get_CellVoltException_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_RelayKHVoltage_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_RelayKHVoltage_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_RelayKHVoltage_Operation(arg1) (HvSysSample_Get_RelayKHVoltage_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_RelayKNClsSts_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_RelayKNClsSts_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_RelayKNClsSts_U8_Operation(arg1) (HvSysSample_Get_RelayKNClsSts_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleCountCurrent_U16_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleCountCurrent_U16_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleCountCurrent_U16_Operation(arg1) (HvSysSample_Get_SampleCountCurrent_U16_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleCountTotalVol_U16_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleCountTotalVol_U16_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleCountTotalVol_U16_Operation(arg1) (HvSysSample_Get_SampleCountTotalVol_U16_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidBat_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidBat_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidBat_U8_Operation(arg1) (HvSysSample_Get_SampleValidBat_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidCurrent_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidCurrent_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidCurrent_U8_Operation(arg1) (HvSysSample_Get_SampleValidCurrent_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidIsolation_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidIsolation_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidIsolation_U8_Operation(arg1) (HvSysSample_Get_SampleValidIsolation_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidKC_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKC_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKC_U8_Operation(arg1) (HvSysSample_Get_SampleValidKC_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidKH_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKH_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKH_U8_Operation(arg1) (HvSysSample_Get_SampleValidKH_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidKM_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKM_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKM_U8_Operation(arg1) (HvSysSample_Get_SampleValidKM_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_HvSysSample_Get_SampleValidKN_U8_Operation Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKN_U8_Operation
#define Rte_Call_swc_SetInputInterface_HvSysSample_Get_SampleValidKN_U8_Operation(arg1) (HvSysSample_Get_SampleValidKN_U8_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_NowSystemTick_Operation Rte_Call_swc_SetInputInterface_RTC_Get_NowSystemTick_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_NowSystemTick_Operation(arg1) (RTC_Get_NowSystemTick_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_RTCStateFault_Operation Rte_Call_swc_SetInputInterface_RTC_Get_RTCStateFault_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_RTCStateFault_Operation(arg1) (RTC_Get_RTCStateFault_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_ReadDay_Operation Rte_Call_swc_SetInputInterface_RTC_Get_ReadDay_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_ReadDay_Operation(arg1) (RTC_Get_ReadDay_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_ReadHour_Operation Rte_Call_swc_SetInputInterface_RTC_Get_ReadHour_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_ReadHour_Operation(arg1) (RTC_Get_ReadHour_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_ReadMinute_Operation Rte_Call_swc_SetInputInterface_RTC_Get_ReadMinute_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_ReadMinute_Operation(arg1) (RTC_Get_ReadMinute_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_ReadMonth_Operation Rte_Call_swc_SetInputInterface_RTC_Get_ReadMonth_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_ReadMonth_Operation(arg1) (RTC_Get_ReadMonth_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_ReadSecond_Operation Rte_Call_swc_SetInputInterface_RTC_Get_ReadSecond_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_ReadSecond_Operation(arg1) (RTC_Get_ReadSecond_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_RTC_Get_ReadYear_Operation Rte_Call_swc_SetInputInterface_RTC_Get_ReadYear_Operation
#define Rte_Call_swc_SetInputInterface_RTC_Get_ReadYear_Operation(arg1) (RTC_Get_ReadYear_Operation(arg1), ((Std_ReturnType)RTE_E_OK))
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
FUNC(void, swc_SetInputInterface_CODE) swc_SetInput_50ms(void);
FUNC(void, swc_SetInputInterface_CODE) swc_SetInput_100ms(void);
FUNC(void, swc_SetInputInterface_CODE) swc_SetInput_10ms(void);
FUNC(void, swc_SetInputInterface_CODE) swc_SetInput_Init(void);
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
#endif /* RTE_SWC_SETINPUTINTERFACE_H_ */
 
 
 
