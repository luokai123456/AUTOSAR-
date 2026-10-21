/*
 * File: swc_SetOutputInterface.c
 *
 * Code generated for Simulink model 'swc_SetOutputInterface'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sat Apr 25 18:23:10 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_SetOutputInterface.h"
#include "swc_SetOutputInterface_private.h"
#include "PwmOut_Release.h"
#include "Cdd_Afe_Release.h"
#include "BMS_AFE_CFG.h"

#ifdef VCU_Test_Code_LK
uint8 test_Ram_Service_ReadStatus = 0U;
uint32 test_Cdd_AFE_GetBalancingStatus[AFE_NUM] = {0U};
extern void If_DiscreteValueOutput_SetDiscreteValue(UInt32 NumId, UInt32 value);
extern void If_PwmValueOutput_SetPwmValue(UInt32 NumId, UInt32 Period, UInt32 Ducy);
#pragma ghs section data =".XCP_CAL"

UInt32 tastout_NumId=0U;
UInt32 tastout_value=0U;

UInt32 tastout_If_PwmValueOutput_Period=0U;
UInt32 tastout_If_PwmValueOutput_Ducy=0U;

UInt32 tastout_If_SetRtcWakeUp_minute=0U;

#pragma ghs section
#endif



uint32 Ea_cellPassiveBlnCtr[AFE_NUM] = {0};/* 从控被动均衡控制 */
uint8 Ea_ShutdownReq = 0;           /* app请求低压下电 */
//uint8 Ea_CloseDisableso = 0;        /* 关闭绝缘检测 */
uint8 Ea_fgSendFastChgStopInfo = 0;     /* 请求发送BMS_FastChgStopInfo报文 */

uint8 Ea_fgSendBCLMsg = 0;              /* 请求发送BCL报文报文 */
uint8 Ea_fgSendBCPMsg = 0;              /* 请求发送BCP报文报文 */
uint8 Ea_fgSendBCPPMsg = 0;             /* 请求发送BCPP报文报文 */
uint8 Ea_fgSendBCSMsg = 0;              /* 请求发送BCS报文报文 */
uint8 Ea_fgSendBCSPMsg = 0;             /* 请求发送BCSP报文报文 */
uint8 Ea_fgSendBDCMsg = 0;              /* 请求发送BDC报文报文 */
uint8 Ea_fgSendBEMMsg = 0;              /* 请求发送BEM报文报文 */
uint8 Ea_fgSendBHMMsg = 0;              /* 请求发送BHM报文报文 */
uint8 Ea_fgSendBMTMsg = 0;              /* 请求发送BMT报文报文 */
uint8 Ea_fgSendBMVMsg = 0;              /* 请求发送BMV报文报文 */
uint8 Ea_fgSendBRMMsg = 0;              /* 请求发送BRM报文报文 */
uint8 Ea_fgSendBROMsg = 0;              /* 请求发送BRO报文报文 */
uint8 Ea_fgSendBRDMsg = 0;              /* 请求发送BRD报文报文 */
uint8 Ea_fgSendBSDMsg = 0;              /* 请求发送BSD报文报文 */
uint8 Ea_fgSendBSMMsg = 0;              /* 请求发送BSM报文报文 */
uint8 Ea_fgSendBSPMsg = 0;              /* 请求发送BSP报文报文 */
uint8 Ea_fgSendBSTMsg = 0;              /* 请求发送BST报文报文 */

uint8 NVMBlock119Array[256] __attribute__((section(".ee_Block119_data")));
uint8 NVMBlock128Array[256] __attribute__((section(".ee_Block128_data")));
uint8 NVMBlock129Array[256] __attribute__((section(".ee_Block129_data")));
uint8 NVMBlock130Array[256] __attribute__((section(".ee_Block130_data")));
uint8 NVMBlock131Array[256] __attribute__((section(".ee_Block131_data")));
boolean NVM_XCU_EEWriteFlgBlock119 = 0;
boolean NVM_XCU_EEWriteFlgBlock128 = 0;
boolean NVM_XCU_EEWriteFlgBlock129 = 0;
boolean NVM_XCU_EEWriteFlgBlock130 = 0;
boolean NVM_XCU_EEWriteFlgBlock131 = 0;
/* Model step function for TID1 */
void swc_SetOutputInterface_10ms(void)
                                /* Explicit Task: swc_SetOutputInterface_10ms */
{
  uint8 tmpRead;
  uint8 tmpRead_0;
  uint8 tmpRead_1;
  uint8 tmpRead_2;
  uint8 tmpRead_3;
  uint8 tmpRead_4;
  uint8 tmpRead_5;
  uint8 tmpRead_6;
  uint8 tmpRead_7;
  uint8 tmpRead_8;
  uint8 tmpRead_9;
  uint8 tmpRead_a;
  uint8 tmpRead_b;
  uint8 tmpRead_c;
  uint8 tmpRead_d;
  uint8 tmpRead_e;

  /* Inport: '<Root>/BSWIOSP_Request_BST_Request_BST' */
  (void)Rte_Read_BSWIOSP_Request_BST_Request_BST(&tmpRead_e);
  Ea_fgSendBSTMsg = tmpRead_e;
  /* Inport: '<Root>/BSWIOSP_Request_BSP_Request_BSP' */
  (void)Rte_Read_BSWIOSP_Request_BSP_Request_BSP(&tmpRead_d);
  Ea_fgSendBSPMsg = tmpRead_d;
  /* Inport: '<Root>/BSWIOSP_Request_BSM_Request_BSM' */
  (void)Rte_Read_BSWIOSP_Request_BSM_Request_BSM(&tmpRead_c);
  Ea_fgSendBSMMsg = tmpRead_c;
  /* Inport: '<Root>/BSWIOSP_Request_BSD_Request_BSD' */
  (void)Rte_Read_BSWIOSP_Request_BSD_Request_BSD(&tmpRead_b);
  Ea_fgSendBSDMsg = tmpRead_b;
  /* Inport: '<Root>/BSWIOSP_Request_BRO_Request_BRO' */
  (void)Rte_Read_BSWIOSP_Request_BRO_Request_BRO(&tmpRead_a);
  Ea_fgSendBROMsg = tmpRead_a;
  /* Inport: '<Root>/BSWIOSP_Request_BRM_Request_BRM' */
  (void)Rte_Read_BSWIOSP_Request_BRM_Request_BRM(&tmpRead_9);
  Ea_fgSendBRMMsg = tmpRead_9;
  /* Inport: '<Root>/BSWIOSP_Request_BMV_Request_BMV' */
  (void)Rte_Read_BSWIOSP_Request_BMV_Request_BMV(&tmpRead_8);
  Ea_fgSendBMVMsg = tmpRead_8;
  /* Inport: '<Root>/BSWIOSP_Request_BMT_Request_BMT' */
  (void)Rte_Read_BSWIOSP_Request_BMT_Request_BMT(&tmpRead_7);
  Ea_fgSendBMTMsg = tmpRead_7;
  /* Inport: '<Root>/BSWIOSP_Request_BHM_Request_BHM' */
  (void)Rte_Read_BSWIOSP_Request_BHM_Request_BHM(&tmpRead_6);
  Ea_fgSendBHMMsg = tmpRead_6;
  /* Inport: '<Root>/BSWIOSP_Request_BEM_Request_BEM' */
  (void)Rte_Read_BSWIOSP_Request_BEM_Request_BEM(&tmpRead_5);
  Ea_fgSendBEMMsg = tmpRead_5;
  /* Inport: '<Root>/BSWIOSP_Request_BDC_Request_BDC' */
  (void)Rte_Read_BSWIOSP_Request_BDC_Request_BDC(&tmpRead_4);
  Ea_fgSendBDCMsg = tmpRead_4;
  /* Inport: '<Root>/BSWIOSP_Request_BCSP_Request_BCSP' */
  (void)Rte_Read_BSWIOSP_Request_BCSP_Request_BCSP(&tmpRead_3);
  Ea_fgSendBCSPMsg = tmpRead_3;
  /* Inport: '<Root>/BSWIOSP_Request_BCS_Request_BCS' */
  (void)Rte_Read_BSWIOSP_Request_BCS_Request_BCS(&tmpRead_2);
  Ea_fgSendBCSMsg = tmpRead_2;
  /* Inport: '<Root>/BSWIOSP_Request_BCPP_Request_BCPP' */
  (void)Rte_Read_BSWIOSP_Request_BCPP_Request_BCPP(&tmpRead_1);
  Ea_fgSendBCPPMsg = tmpRead_1;
  /* Inport: '<Root>/BSWIOSP_Request_BCP_Request_BCP' */
  (void)Rte_Read_BSWIOSP_Request_BCP_Request_BCP(&tmpRead_0);
  Ea_fgSendBCPMsg = tmpRead_0;
  /* Inport: '<Root>/BSWIOSP_Request_BCL_Request_BCL' */
  (void)Rte_Read_BSWIOSP_Request_BCL_Request_BCL(&tmpRead);
  Ea_fgSendBCLMsg = tmpRead;
#ifdef VCU_Test_Code_LK
  If_DiscreteValueOutput_SetDiscreteValue(0, 0);
  If_PwmValueOutput_SetPwmValue(2, 0, 0);

  Cdd_AFE_GetBalancingStatus(&test_Cdd_AFE_GetBalancingStatus,AFE_NUM);  


#endif
  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetOutputInterface_10ms' incorporates:
   *  SubSystem: '<Root>/swc_SetOutputInterface_10ms_sys'
   */
  /* Outport: '<Root>/Request_BCL_read' incorporates:
   *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BCL_Request_BCL_read'
   */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BCL_read_Request_BCL_read
  //   (tmpRead);

  // /* Outport: '<Root>/Request_BCP_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BCP_Request_BCP_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BCP_read_Request_BCP_read
  //   (tmpRead_0);

  // /* Outport: '<Root>/Request_BCPP_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BCPP_Request_BCPP_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BCPP_read_Request_BCPP_read
  //   (tmpRead_1);

  // /* Outport: '<Root>/Request_BCS_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BCS_Request_BCS_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BCS_read_Request_BCS_read
  //   (tmpRead_2);

  // /* Outport: '<Root>/Request_BCSP_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BCSP_Request_BCSP_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BCSP_read_Request_BCSP_read
  //   (tmpRead_3);

  // /* Outport: '<Root>/Request_BDC_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BDC_Request_BDC_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BDC_read_Request_BDC_read
  //   (tmpRead_4);

  // /* Outport: '<Root>/Request_BEM_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BEM_Request_BEM_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BEM_read_Request_BEM_read
  //   (tmpRead_5);

  // /* Outport: '<Root>/Request_BHM_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BHM_Request_BHM_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BHM_read_Request_BHM_read
  //   (tmpRead_6);

  // /* Outport: '<Root>/Request_BMT_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BMT_Request_BMT_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BMT_read_Request_BMT_read
  //   (tmpRead_7);

  // /* Outport: '<Root>/Request_BMV_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BMV_Request_BMV_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BMV_read_Request_BMV_read
  //   (tmpRead_8);

  // /* Outport: '<Root>/Request_BRM_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BRM_Request_BRM_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BRM_read_Request_BRM_read
  //   (tmpRead_9);

  // /* Outport: '<Root>/Request_BRO_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BRO_Request_BRO_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BRO_read_Request_BRO_read
  //   (tmpRead_a);

  // /* Outport: '<Root>/Request_BSD_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BSD_Request_BSD_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BSD_read_Request_BSD_read
  //   (tmpRead_b);

  // /* Outport: '<Root>/Request_BSM_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BSM_Request_BSM_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BSM_read_Request_BSM_read
  //   (tmpRead_c);

  // /* Outport: '<Root>/Request_BSP_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BSP_Request_BSP_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BSP_read_Request_BSP_read
  //   (tmpRead_d);

  // /* Outport: '<Root>/Request_BST_read' incorporates:
  //  *  SignalConversion generated from: '<S7>/BSWIOSP_Request_BST_Request_BST_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_10ms_Request_BST_read_Request_BST_read
  //   (tmpRead_e);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetOutputInterface_10ms' */
}

/* Model step function for TID2 */
void swc_SetOutputInterface_50ms(void)
                                /* Explicit Task: swc_SetOutputInterface_50ms */
{
  uint32 tmpRead[9];
  uint8 tmpRead_0;
  //uint8 tmpRead_1;
  (void)Rte_Read_BSWIOSP_Mode_Request_shutdown_Request_shutdown(&tmpRead_0);
  Ea_ShutdownReq = tmpRead_0;
  if(Ea_ShutdownReq == 1)
  {
    for(uint16 i =0;i<256;i++)
    {
      NVMBlock119Array[i] = ASW_NvRam_App1_MP[i];
      NVMBlock128Array[i] = ASW_NvRam_App2_MP[i];
      NVMBlock129Array[i] = ASW_NvRam_App3_MP[i];
      NVMBlock130Array[i] = ASW_NvRam_App4_MP[i];
      NVMBlock131Array[i] = ASW_NvRam_App5_MP[i];
    }

  }
  (void)Rte_Read_BmuControl_BalanceControl_BalanceControl(tmpRead);
  for(uint8 i = 0; i < AFE_NUM; i++)
  {
    Ea_cellPassiveBlnCtr[i] =  tmpRead[i];
  }
  Cdd_AFE_SetBalancingChannels(&Ea_cellPassiveBlnCtr,AFE_NUM); 
  // Ea_CloseDisableso = tmpRead_1;
  /* Inport: '<Root>/HvSysSample_DisableIso_DisableIso' */
  //(void)Rte_Read_HvSysSample_DisableIso_DisableIso(&tmpRead_1);

  /* Inport: '<Root>/BSWIOSP_Mode_Request_shutdown_Request_shutdown' */

  /* Inport: '<Root>/BmuControl_BalanceControl_BalanceControl' */

  /* Outport: '<Root>/BalanceControl_read' */
  // Rte_IWrite_swc_SetOutputInterface_50ms_BalanceControl_read_BalanceControl_read
  //   (tmpRead);

  // /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetOutputInterface_50ms' incorporates:
  //  *  SubSystem: '<Root>/swc_SetOutputInterface_50ms_sys'
  //  */
  // /* Outport: '<Root>/Request_shutdown_read' incorporates:
  //  *  SignalConversion generated from: '<S8>/BSWIOSP_Mode_Request_shutdown_Request_shutdown_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_50ms_Request_shutdown_read_Request_shutdown_read
  //   (tmpRead_0);

  // /* Outport: '<Root>/DisableIso_read' incorporates:
  //  *  SignalConversion generated from: '<S8>/HvSysSample_DisableIso_DisableIso_read'
  //  */
  // Rte_IWrite_swc_SetOutputInterface_50ms_DisableIso_read_DisableIso_read
  //   (tmpRead_1);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetOutputInterface_50ms' */
}

/* Model step function for TID3 */
void swc_SetOutputInterface_100ms(void)
                               /* Explicit Task: swc_SetOutputInterface_100ms */
{
  uint8 tmpRead;
  /* Inport: '<Root>/BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo' */
  (void)Rte_Read_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo
    (&tmpRead);
  Ea_fgSendFastChgStopInfo = tmpRead;
  /* RootInportFunctionCallGenerator generated from: '<Root>/swc_SetOutputInterface_100ms' incorporates:
   *  SubSystem: '<Root>/swc_SetOutputInterface_100ms_sys'
   */

  /* Outport: '<Root>/Request_BMS_FastChgStopInfo_read' incorporates:
   *  SignalConversion generated from: '<S6>/BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo_read'
   */
  // Rte_IWrite_swc_SetOutputInterface_100ms_Request_BMS_FastChgStopInfo_read_Request_BMS_FastChgStopInfo_read
  //   (tmpRead);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/swc_SetOutputInterface_100ms' */
}

/* Output function */
void If_DiscreteValueOutput_SetDiscreteValue(UInt32 NumId, UInt32 value)
{
  // UNUSED_PARAMETER(NumId);
  // UNUSED_PARAMETER(value);
#ifdef VCU_Test_Code_LK

  NumId = tastout_NumId;
  value = tastout_value;

#endif
  switch (NumId)
  {
  case 6:
    Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_7,value);
    // Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL7, 1, 1, 2, 0);
    Cdd_Lsd_SetLevelFunction(EXT_D_LS11_CH3,value);
    break;
  case 4:
    Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_1,value);
    // Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL5, 1, 1, 2, 0);
    Cdd_Lsd_SetLevelFunction(EXT_D_LS9_CH1,value);
    break;
  case 25:
    Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_3,value);
    break;
  case 20:
    Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_4,value);
    break;
  case 27:
    Cdd_Hsd_SetLevelFunction(EXT_D_HS_CH_8,value);
    // Cdd_HalfBridegeOut_Function(EXT_D_HB_CHANNEL8, 1, 1, 2, 0);
    Cdd_Lsd_SetLevelFunction(EXT_D_LS12_CH4,value);
    break;
  default:
    break;
  }
}

/* Output function */
void If_PwmValueOutput_SetPwmValue(UInt32 NumId, UInt32 Period, UInt32 Ducy)
{
  // UNUSED_PARAMETER(NumId);
  // UNUSED_PARAMETER(Period);
  // UNUSED_PARAMETER(Ducy);

#ifdef VCU_Test_Code_LK

  Period = tastout_If_PwmValueOutput_Period;
  Ducy = tastout_If_PwmValueOutput_Ducy;

#endif
  switch (NumId)
  {
  case 2:
//    Cdd_Lsd_SetPwmFunction(IoHwAbs_PWM_MCU_PWMOUT5, Period, Ducy);
//    Cdd_Lsd_SetPwmFunction(IoHwAbs_PWM_MCU_PWMOUT10, Period, Ducy);
    // Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT5, Period, Ducy);
    // Cdd_PwmOut_Function(IoHwAbs_PWM_MCU_PWMOUT10, Period, Ducy);
    break;
  default:
    break;
  }
}

/* Output function */
void If_RequestElectcContorCls_RequestElectcContorCls(float64 Num)
{
  // UNUSED_PARAMETER(Num);
}

/* Output function */
void If_SetRtcWakeUp_SetWakeUpTime(uint16 minute)
{
#ifdef VCU_Test_Code_LK

  minute = tastout_If_SetRtcWakeUp_minute;

#endif
  // UNUSED_PARAMETER(minute);
  Sys_SetWakeTime(minute*60);
}

/* Output function */
Std_ReturnType Ram_Service_ReadStatus(UInt32_T BlockId, UInt8_T *blockstatus)
{
  // UNUSED_PARAMETER(BlockId);

  /* Outputs for Function Call SubSystem: '<S5>/Ram_Service_ReadStatus_sys' */
  /* SignalConversion generated from: '<S14>/blockstatus' */
  switch (BlockId)
  {
    case 1:
      NvM_GetErrorStatus(119,blockstatus);
    break;
    case 2:
      NvM_GetErrorStatus(128,blockstatus);
    break;
    case 3:
      NvM_GetErrorStatus(129,blockstatus);
    break;
    case 4:
      NvM_GetErrorStatus(130,blockstatus);
    break;
    case 5:
      NvM_GetErrorStatus(131,blockstatus);
    break;
    default:
    break;
  }
#ifdef VCU_Test_Code_LK
    test_Ram_Service_ReadStatus = *blockstatus;
#endif
  /* SignalConversion generated from: '<S14>/ERR' */
  return 0U;

  /* End of Outputs for SubSystem: '<S5>/Ram_Service_ReadStatus_sys' */
}

/* Output function */
Std_ReturnType Ram_Service_Write(UInt32_T block_Id, UInt8_T write)
{
  // UNUSED_PARAMETER(block_Id);
  // UNUSED_PARAMETER(write);

  /* Outputs for Function Call SubSystem: '<S5>/Ram_Service_Write_sys' */
  /* SignalConversion generated from: '<S15>/ERR' */
  if(write == 1)
  {
    switch (block_Id)
    {
      case 1:
        NVM_XCU_EEWriteFlgBlock119 = 1;
        for(uint16 i =0;i<256;i++)
        {
          NVMBlock119Array[i] = ASW_NvRam_App1_MP[i];
        }
      break;
      case 2:
        NVM_XCU_EEWriteFlgBlock128 = 1;
        for(uint16 i =0;i<256;i++)
        {
          NVMBlock128Array[i] = ASW_NvRam_App2_MP[i];
        }
      break;
      case 3:
        NVM_XCU_EEWriteFlgBlock129 = 1;
        for(uint16 i =0;i<256;i++)
        {
          NVMBlock129Array[i] = ASW_NvRam_App3_MP[i];
        }
      break;
      case 4:
        NVM_XCU_EEWriteFlgBlock130 = 1;
        for(uint16 i =0;i<256;i++)
        {
          NVMBlock130Array[i] = ASW_NvRam_App4_MP[i];
        }
      break;
      case 5:
        NVM_XCU_EEWriteFlgBlock131 = 1;
        for(uint16 i =0;i<256;i++)
        {
          NVMBlock131Array[i] = ASW_NvRam_App5_MP[i];
        }
      break;
      default:
      break;
    }
  }
  return 0U;

  /* End of Outputs for SubSystem: '<S5>/Ram_Service_Write_sys' */
}

/* Model initialize function */
void swc_SetOutputInterface_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
