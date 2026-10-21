/*
 * File: swc_GetInputInterface.h
 *
 * Code generated for Simulink model 'swc_GetInputInterface'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 16:56:27 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_GetInputInterface_h_
#define RTW_HEADER_swc_GetInputInterface_h_
#include <string.h>
#ifndef swc_GetInputInterface_COMMON_INCLUDES_
#define swc_GetInputInterface_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_GetInputInterface.h"
#endif                              /* swc_GetInputInterface_COMMON_INCLUDES_ */

#include "swc_GetInputInterface_types.h"

/* Child system includes */
#include "BSWIOSP_Get_ACTemp_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_ACUCom_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_BMUTempOver_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_BattIsoDet_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_Com_CCD_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CCS_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CDC_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CEM_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CHM_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CMLP_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CML_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CRM_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CRO_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CSDP_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CSD_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_CST_UpdataTime_Operation_private.h"
#include "BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation_private.h"
#include "BSWIOSP_Get_DCTemp_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_HCMCom_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_HCME2E_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_HCMbusoff_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_IntCANE2E_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_NvM_Save_Ok_Operation_private.h"
#include "BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation_private.h"
#include "BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_STHW_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_Service0x14_Count_Operation_private.h"
#include "BSWIOSP_Get_StsElectroniclockContor_Operation_private.h"
#include "BSWIOSP_Get_VCUCom_ErrFLg_Operation_private.h"
#include "BSWIOSP_Get_WeakUpFlg_Operation_private.h"
#include "BSWIOSP_Get_bCANWakeUp_Operation_private.h"
#include "BmuSample_Get_BMUCell_Operation_private.h"
#include "BmuSample_Get_BMUCellVSt_Operation_private.h"
#include "BmuSample_Get_BMUChipTemp_Operation_private.h"
#include "BmuSample_Get_BMUTemp_Operation_private.h"
#include "BmuSample_Get_BMUTempSt_Operation_private.h"
#include "BmuSample_Get_BalanceTemp_Operation_private.h"
#include "BmuSample_Get_CellTEffective_Operation_private.h"
#include "BmuSample_Get_CellTempException_Operation_private.h"
#include "BmuSample_Get_CellVEffective_Operation_private.h"
#include "BmuSample_Get_CellVoltException_Operation_private.h"
#include "DiagcEvent_GetEvent_private.h"
#include "DiagcEvent_SetEvent_private.h"
#include "Func_FiMFID1_GetFunctionPermission_private.h"
#include "Func_FiMFID10_GetFunctionPermission_private.h"
#include "Func_FiMFID11_GetFunctionPermission_private.h"
#include "Func_FiMFID12_GetFunctionPermission_private.h"
#include "Func_FiMFID13_GetFunctionPermission_private.h"
#include "Func_FiMFID14_GetFunctionPermission_private.h"
#include "Func_FiMFID15_GetFunctionPermission_private.h"
#include "Func_FiMFID16_GetFunctionPermission_private.h"
#include "Func_FiMFID17_GetFunctionPermission_private.h"
#include "Func_FiMFID18_GetFunctionPermission_private.h"
#include "Func_FiMFID19_GetFunctionPermission_private.h"
#include "Func_FiMFID2_GetFunctionPermission_private.h"
#include "Func_FiMFID20_GetFunctionPermission_private.h"
#include "Func_FiMFID21_GetFunctionPermission_private.h"
#include "Func_FiMFID22_GetFunctionPermission_private.h"
#include "Func_FiMFID23_GetFunctionPermission_private.h"
#include "Func_FiMFID24_GetFunctionPermission_private.h"
#include "Func_FiMFID25_GetFunctionPermission_private.h"
#include "Func_FiMFID26_GetFunctionPermission_private.h"
#include "Func_FiMFID27_GetFunctionPermission_private.h"
#include "Func_FiMFID28_GetFunctionPermission_private.h"
#include "Func_FiMFID29_GetFunctionPermission_private.h"
#include "Func_FiMFID3_GetFunctionPermission_private.h"
#include "Func_FiMFID30_GetFunctionPermission_private.h"
#include "Func_FiMFID4_GetFunctionPermission_private.h"
#include "Func_FiMFID5_GetFunctionPermission_private.h"
#include "Func_FiMFID6_GetFunctionPermission_private.h"
#include "Func_FiMFID7_GetFunctionPermission_private.h"
#include "Func_FiMFID8_GetFunctionPermission_private.h"
#include "Func_FiMFID9_GetFunctionPermission_private.h"
#include "HvSysSample_Get_Current_Operation_private.h"
#include "HvSysSample_Get_NegInsulationRes_Operation_private.h"
#include "HvSysSample_Get_PosInsulationRes_Operation_private.h"
#include "HvSysSample_Get_RelayKCVoltage_Operation_private.h"
#include "HvSysSample_Get_RelayKHVoltage_Operation_private.h"
#include "HvSysSample_Get_RelayKMVoltage_Operation_private.h"
#include "HvSysSample_Get_RelayKNClsSts_U8_Operation_private.h"
#include "HvSysSample_Get_RelayKNVoltage_Operation_private.h"
#include "HvSysSample_Get_SampleCountCurrent_U16_Operation_private.h"
#include "HvSysSample_Get_SampleCountInsRes_U16_Operation_private.h"
#include "HvSysSample_Get_SampleCountTotalVol_U16_Operation_private.h"
#include "HvSysSample_Get_SampleValidBat_U8_Operation_private.h"
#include "HvSysSample_Get_SampleValidCurrent_U8_Operation_private.h"
#include "HvSysSample_Get_SampleValidIsolation_U8_Operation_private.h"
#include "HvSysSample_Get_SampleValidKC_U8_Operation_private.h"
#include "HvSysSample_Get_SampleValidKH_U8_Operation_private.h"
#include "HvSysSample_Get_SampleValidKM_U8_Operation_private.h"
#include "HvSysSample_Get_SampleValidKN_U8_Operation_private.h"
#include "HvSysSample_Get_TotalVoltage_Operation_private.h"
#include "If_AdcConvertValueInput_GetAdcConvertValue_private.h"
#include "If_IcuDutyValueInput_GetIcuDutyValue_private.h"
#include "If_IcuPeriodValueInput_GetIcuPeriodValue_private.h"
#include "RTC_Get_NowSystemTick_Operation_private.h"
#include "RTC_Get_RTCStateFault_Operation_private.h"
#include "RTC_Get_ReadDay_Operation_private.h"
#include "RTC_Get_ReadHour_Operation_private.h"
#include "RTC_Get_ReadMinute_Operation_private.h"
#include "RTC_Get_ReadMonth_Operation_private.h"
#include "RTC_Get_ReadSecond_Operation_private.h"
#include "RTC_Get_ReadYear_Operation_private.h"
#include "rt_defines.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_ICU.h"
#include "Dcm_Lcfg.h"
#include "IoHwAbs_DIO.h"



#define Dcm_SID0x14CountBufferAddress Dcm_Did_Block00B9_Data.Dcm_Service0x14CountBuffer


/* Macros for accessing real-time model data structure */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'swc_GetInputInterface'
 * '<S1>'   : 'swc_GetInputInterface/BSWIOSP_Get_ACTemp_ErrFLg'
 * '<S2>'   : 'swc_GetInputInterface/BSWIOSP_Get_ACUCom_ErrFLg'
 * '<S3>'   : 'swc_GetInputInterface/BSWIOSP_Get_BMUTempOver_ErrFLg'
 * '<S4>'   : 'swc_GetInputInterface/BSWIOSP_Get_BalnCtlModl_ErrFLg'
 * '<S5>'   : 'swc_GetInputInterface/BSWIOSP_Get_BattIsoDet_ErrFLg'
 * '<S6>'   : 'swc_GetInputInterface/BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg'
 * '<S7>'   : 'swc_GetInputInterface/BSWIOSP_Get_Com_OBC_Sts_Timeout'
 * '<S8>'   : 'swc_GetInputInterface/BSWIOSP_Get_DCTemp_ErrFLg'
 * '<S9>'   : 'swc_GetInputInterface/BSWIOSP_Get_EVCANBusOff_ErrFLg'
 * '<S10>'  : 'swc_GetInputInterface/BSWIOSP_Get_HCMCom_ErrFLg'
 * '<S11>'  : 'swc_GetInputInterface/BSWIOSP_Get_HCME2E_ErrFLg'
 * '<S12>'  : 'swc_GetInputInterface/BSWIOSP_Get_HCMbusoff_ErrFLg'
 * '<S13>'  : 'swc_GetInputInterface/BSWIOSP_Get_IntCANE2E_ErrFLg'
 * '<S14>'  : 'swc_GetInputInterface/BSWIOSP_Get_NvM_Save_Ok'
 * '<S15>'  : 'swc_GetInputInterface/BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout'
 * '<S16>'  : 'swc_GetInputInterface/BSWIOSP_Get_RlyKCVoltSample_ErrFLg'
 * '<S17>'  : 'swc_GetInputInterface/BSWIOSP_Get_RlyKMVoltSample_ErrFLg'
 * '<S18>'  : 'swc_GetInputInterface/BSWIOSP_Get_RlyKNVoltSample_ErrFLg'
 * '<S19>'  : 'swc_GetInputInterface/BSWIOSP_Get_STHW_ErrFLg'
 * '<S20>'  : 'swc_GetInputInterface/BSWIOSP_Get_StsElectroniclockContor'
 * '<S21>'  : 'swc_GetInputInterface/BSWIOSP_Get_VCUCom_ErrFLg'
 * '<S22>'  : 'swc_GetInputInterface/BSWIOSP_Get_WeakUpFlg'
 * '<S23>'  : 'swc_GetInputInterface/BSWIOSP_Get_bCANWakeUp'
 * '<S24>'  : 'swc_GetInputInterface/BmuSample_Get_BMUCell'
 * '<S25>'  : 'swc_GetInputInterface/BmuSample_Get_BMUCellVSt'
 * '<S26>'  : 'swc_GetInputInterface/BmuSample_Get_BMUChipTemp'
 * '<S27>'  : 'swc_GetInputInterface/BmuSample_Get_BMUTemp'
 * '<S28>'  : 'swc_GetInputInterface/BmuSample_Get_BMUTempSt'
 * '<S29>'  : 'swc_GetInputInterface/BmuSample_Get_BalanceTemp'
 * '<S30>'  : 'swc_GetInputInterface/BmuSample_Get_CellTEffective'
 * '<S31>'  : 'swc_GetInputInterface/BmuSample_Get_CellTempException'
 * '<S32>'  : 'swc_GetInputInterface/BmuSample_Get_CellVEffective'
 * '<S33>'  : 'swc_GetInputInterface/BmuSample_Get_CellVoltException'
 * '<S34>'  : 'swc_GetInputInterface/HvSysSample_Get_Current'
 * '<S35>'  : 'swc_GetInputInterface/HvSysSample_Get_NegInsulationRes'
 * '<S36>'  : 'swc_GetInputInterface/HvSysSample_Get_PosInsulationRes'
 * '<S37>'  : 'swc_GetInputInterface/HvSysSample_Get_RelayKCVoltage'
 * '<S38>'  : 'swc_GetInputInterface/HvSysSample_Get_RelayKHVoltage'
 * '<S39>'  : 'swc_GetInputInterface/HvSysSample_Get_RelayKMVoltage'
 * '<S40>'  : 'swc_GetInputInterface/HvSysSample_Get_RelayKNClsSts_U8'
 * '<S41>'  : 'swc_GetInputInterface/HvSysSample_Get_RelayKNVoltage'
 * '<S42>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleCountCurrent_U16'
 * '<S43>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleCountInsRes_U16'
 * '<S44>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleCountTotalVol_U16'
 * '<S45>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidBat_U8'
 * '<S46>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidCurrent_U8'
 * '<S47>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidIsolation_U8'
 * '<S48>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKC_U8'
 * '<S49>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKH_U8'
 * '<S50>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKM_U8'
 * '<S51>'  : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKN_U8'
 * '<S52>'  : 'swc_GetInputInterface/HvSysSample_Get_TotalVoltage'
 * '<S53>'  : 'swc_GetInputInterface/If_AdcConvertValueInput'
 * '<S54>'  : 'swc_GetInputInterface/If_IcuDutyValueInput'
 * '<S55>'  : 'swc_GetInputInterface/If_IcuPeriodValueInput'
 * '<S56>'  : 'swc_GetInputInterface/RTC_Get_NowSystemTick'
 * '<S57>'  : 'swc_GetInputInterface/RTC_Get_RTCStateFault'
 * '<S58>'  : 'swc_GetInputInterface/RTC_Get_ReadDay'
 * '<S59>'  : 'swc_GetInputInterface/RTC_Get_ReadHour'
 * '<S60>'  : 'swc_GetInputInterface/RTC_Get_ReadMinute'
 * '<S61>'  : 'swc_GetInputInterface/RTC_Get_ReadMonth'
 * '<S62>'  : 'swc_GetInputInterface/RTC_Get_ReadSecond'
 * '<S63>'  : 'swc_GetInputInterface/RTC_Get_ReadYear'
 * '<S64>'  : 'swc_GetInputInterface/swc_GetInputInterface_Init'
 * '<S65>'  : 'swc_GetInputInterface/BSWIOSP_Get_ACTemp_ErrFLg/BSWIOSP_Get_ACTemp_ErrFLg_Operation_sys'
 * '<S66>'  : 'swc_GetInputInterface/BSWIOSP_Get_ACUCom_ErrFLg/BSWIOSP_Get_ACUCom_ErrFLg_Operation_sys'
 * '<S67>'  : 'swc_GetInputInterface/BSWIOSP_Get_BMUTempOver_ErrFLg/BSWIOSP_Get_BMUTempOver_ErrFLg_Operation_sys'
 * '<S68>'  : 'swc_GetInputInterface/BSWIOSP_Get_BalnCtlModl_ErrFLg/BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation_sys'
 * '<S69>'  : 'swc_GetInputInterface/BSWIOSP_Get_BattIsoDet_ErrFLg/BSWIOSP_Get_BattIsoDet_ErrFLg_Operation_sys'
 * '<S70>'  : 'swc_GetInputInterface/BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg/BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation_sys'
 * '<S71>'  : 'swc_GetInputInterface/BSWIOSP_Get_Com_OBC_Sts_Timeout/BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation_sys'
 * '<S72>'  : 'swc_GetInputInterface/BSWIOSP_Get_DCTemp_ErrFLg/BSWIOSP_Get_DCTemp_ErrFLg_Operation_sys'
 * '<S73>'  : 'swc_GetInputInterface/BSWIOSP_Get_EVCANBusOff_ErrFLg/BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation_sys'
 * '<S74>'  : 'swc_GetInputInterface/BSWIOSP_Get_HCMCom_ErrFLg/BSWIOSP_Get_HCMCom_ErrFLg_Operation_sys'
 * '<S75>'  : 'swc_GetInputInterface/BSWIOSP_Get_HCME2E_ErrFLg/BSWIOSP_Get_HCME2E_ErrFLg_Operation_sys'
 * '<S76>'  : 'swc_GetInputInterface/BSWIOSP_Get_HCMbusoff_ErrFLg/BSWIOSP_Get_HCMbusoff_ErrFLg_Operation_sys'
 * '<S77>'  : 'swc_GetInputInterface/BSWIOSP_Get_IntCANE2E_ErrFLg/BSWIOSP_Get_IntCANE2E_ErrFLg_Operation_sys'
 * '<S78>'  : 'swc_GetInputInterface/BSWIOSP_Get_NvM_Save_Ok/BSWIOSP_Get_NvM_Save_Ok_Operation_sys'
 * '<S79>'  : 'swc_GetInputInterface/BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout/BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation_sys'
 * '<S80>'  : 'swc_GetInputInterface/BSWIOSP_Get_RlyKCVoltSample_ErrFLg/BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation_sys'
 * '<S81>'  : 'swc_GetInputInterface/BSWIOSP_Get_RlyKMVoltSample_ErrFLg/BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation_sys'
 * '<S82>'  : 'swc_GetInputInterface/BSWIOSP_Get_RlyKNVoltSample_ErrFLg/BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation_sys'
 * '<S83>'  : 'swc_GetInputInterface/BSWIOSP_Get_STHW_ErrFLg/BSWIOSP_Get_STHW_ErrFLg_Operation_sys'
 * '<S84>'  : 'swc_GetInputInterface/BSWIOSP_Get_StsElectroniclockContor/BSWIOSP_Get_StsElectroniclockContor_Operation_sys'
 * '<S85>'  : 'swc_GetInputInterface/BSWIOSP_Get_VCUCom_ErrFLg/BSWIOSP_Get_VCUCom_ErrFLg_Operation_sys'
 * '<S86>'  : 'swc_GetInputInterface/BSWIOSP_Get_WeakUpFlg/BSWIOSP_Get_WeakUpFlg_Operation_sys'
 * '<S87>'  : 'swc_GetInputInterface/BSWIOSP_Get_bCANWakeUp/BSWIOSP_Get_bCANWakeUp_Operation_sys'
 * '<S88>'  : 'swc_GetInputInterface/BmuSample_Get_BMUCell/BmuSample_Get_BMUCell_Operation_sys'
 * '<S89>'  : 'swc_GetInputInterface/BmuSample_Get_BMUCellVSt/BmuSample_Get_BMUCellVSt_Operation_sys'
 * '<S90>'  : 'swc_GetInputInterface/BmuSample_Get_BMUChipTemp/BmuSample_Get_BMUChipTemp_Operation_sys'
 * '<S91>'  : 'swc_GetInputInterface/BmuSample_Get_BMUTemp/BmuSample_Get_BMUTemp_Operation_sys'
 * '<S92>'  : 'swc_GetInputInterface/BmuSample_Get_BMUTempSt/BmuSample_Get_BMUTempSt_Operation_sys'
 * '<S93>'  : 'swc_GetInputInterface/BmuSample_Get_BalanceTemp/BmuSample_Get_BalanceTemp_Operation_sys'
 * '<S94>'  : 'swc_GetInputInterface/BmuSample_Get_CellTEffective/BmuSample_Get_CellTEffective_Operation_sys'
 * '<S95>'  : 'swc_GetInputInterface/BmuSample_Get_CellTempException/BmuSample_Get_CellTempException_Operation_sys'
 * '<S96>'  : 'swc_GetInputInterface/BmuSample_Get_CellVEffective/BmuSample_Get_CellVEffective_Operation_sys'
 * '<S97>'  : 'swc_GetInputInterface/BmuSample_Get_CellVoltException/BmuSample_Get_CellVoltException_Operation_sys'
 * '<S98>'  : 'swc_GetInputInterface/HvSysSample_Get_Current/HvSysSample_Get_Current_Operation_sys'
 * '<S99>'  : 'swc_GetInputInterface/HvSysSample_Get_NegInsulationRes/HvSysSample_Get_NegInsulationRes_Operation_sys'
 * '<S100>' : 'swc_GetInputInterface/HvSysSample_Get_PosInsulationRes/HvSysSample_Get_PosInsulationRes_Operation_sys'
 * '<S101>' : 'swc_GetInputInterface/HvSysSample_Get_RelayKCVoltage/HvSysSample_Get_RelayKCVoltage_Operation_sys'
 * '<S102>' : 'swc_GetInputInterface/HvSysSample_Get_RelayKHVoltage/HvSysSample_Get_RelayKHVoltage_Operation_sys'
 * '<S103>' : 'swc_GetInputInterface/HvSysSample_Get_RelayKMVoltage/HvSysSample_Get_RelayKMVoltage_Operation_sys'
 * '<S104>' : 'swc_GetInputInterface/HvSysSample_Get_RelayKNClsSts_U8/HvSysSample_Get_RelayKNClsSts_U8_Operation_sys'
 * '<S105>' : 'swc_GetInputInterface/HvSysSample_Get_RelayKNVoltage/HvSysSample_Get_RelayKNVoltage_Operation_sys'
 * '<S106>' : 'swc_GetInputInterface/HvSysSample_Get_SampleCountCurrent_U16/HvSysSample_Get_SampleCountCurrent_U16_Operation_sys'
 * '<S107>' : 'swc_GetInputInterface/HvSysSample_Get_SampleCountInsRes_U16/HvSysSample_Get_SampleCountInsRes_U16_Operation_sys'
 * '<S108>' : 'swc_GetInputInterface/HvSysSample_Get_SampleCountTotalVol_U16/HvSysSample_Get_SampleCountTotalVol_U16_Operation_sys'
 * '<S109>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidBat_U8/HvSysSample_Get_SampleValidBat_U8_Operation_sys'
 * '<S110>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidCurrent_U8/HvSysSample_Get_SampleValidCurrent_U8_Operation_sys'
 * '<S111>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidIsolation_U8/HvSysSample_Get_SampleValidIsolation_U8_Operation_sys'
 * '<S112>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKC_U8/HvSysSample_Get_SampleValidKC_U8_Operation_sys'
 * '<S113>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKH_U8/HvSysSample_Get_SampleValidKH_U8_Operation_sys'
 * '<S114>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKM_U8/HvSysSample_Get_SampleValidKM_U8_Operation_sys'
 * '<S115>' : 'swc_GetInputInterface/HvSysSample_Get_SampleValidKN_U8/HvSysSample_Get_SampleValidKN_U8_Operation_sys'
 * '<S116>' : 'swc_GetInputInterface/HvSysSample_Get_TotalVoltage/HvSysSample_Get_TotalVoltage_Operation_sys'
 * '<S117>' : 'swc_GetInputInterface/If_AdcConvertValueInput/If_AdcConvertValueInput_GetAdcConvertValue_sys'
 * '<S118>' : 'swc_GetInputInterface/If_IcuDutyValueInput/If_IcuDutyValueInput_GetIcuDutyValue_sys'
 * '<S119>' : 'swc_GetInputInterface/If_IcuPeriodValueInput/If_IcuPeriodValueInput_GetIcuPeriodValue_sys'
 * '<S120>' : 'swc_GetInputInterface/RTC_Get_NowSystemTick/RTC_Get_NowSystemTick_Operation_sys'
 * '<S121>' : 'swc_GetInputInterface/RTC_Get_RTCStateFault/RTC_Get_RTCStateFault_Operation_sys'
 * '<S122>' : 'swc_GetInputInterface/RTC_Get_ReadDay/RTC_Get_ReadDay_Operation_sys'
 * '<S123>' : 'swc_GetInputInterface/RTC_Get_ReadHour/RTC_Get_ReadHour_Operation_sys'
 * '<S124>' : 'swc_GetInputInterface/RTC_Get_ReadMinute/RTC_Get_ReadMinute_Operation_sys'
 * '<S125>' : 'swc_GetInputInterface/RTC_Get_ReadMonth/RTC_Get_ReadMonth_Operation_sys'
 * '<S126>' : 'swc_GetInputInterface/RTC_Get_ReadSecond/RTC_Get_ReadSecond_Operation_sys'
 * '<S127>' : 'swc_GetInputInterface/RTC_Get_ReadYear/RTC_Get_ReadYear_Operation_sys'
 */
#endif                                 /* RTW_HEADER_swc_GetInputInterface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
