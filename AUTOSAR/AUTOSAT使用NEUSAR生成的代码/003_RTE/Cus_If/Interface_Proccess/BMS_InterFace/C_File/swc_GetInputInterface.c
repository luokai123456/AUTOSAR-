/*
 * File: swc_GetInputInterface.c
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

#include "swc_GetInputInterface.h"
#include "swc_GetInputInterface_private.h"
#include "IoHwAbs_NTC_Lookup.h"
#include "System_Release.h"
#include "User_Func.h"
#include "Cdd_Afe_Release.h"
#include "FiM.h"
#include "Com_Lcfg.h"
#include "Com.h"
#include "BMS_AFE_CFG.h"

#define AFE_Chip_0          0
#define AFE_Chip_1          1
#define AFE_Chip_2          2
#define AFE_Chip_3          3
#define AFE_Chip_4          4
#define AFE_Chip_5          5
#define AFE_Chip_6          6
#define AFE_Chip_7          7


extern boolean CANG_0x122_TimeOut;
extern boolean CANA_0x220_TimeOut;
extern boolean CANG_0x122_Active;
extern boolean CANE_0x1812F456_Active;
extern boolean CANE_0x1808F456_Active;
extern boolean CANE_0x1801F456_Active;
extern boolean CANE_0x100AF456_Active;
extern boolean CANE_0x181DF456_Active;
extern boolean CANE_0x101AF456_Active;
extern boolean CANE_0x81FF456_Active; 
extern boolean CANE_0x1826F456_Active; 
extern boolean CANA_stBusoffFlg; 
extern boolean Can_DiagCondKeyOn;
extern boolean Can_DiagCondChargeOn;
extern boolean Can_DiagVltgCondFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb;

#ifdef BMS_TestMea_Code_LK
  uint16 Test_DiagcEvent_SetEvent_ID          = 0;
  uint8  Test_DiagcEvent_SetEvent_EventStatus = 0;
#endif
#ifdef VCU_Test_Code_LK

SInt32 tast_Ea_KL30Volatage = 0U;
SInt32 tast_Ea_KL15Volatage = 0U;
SInt32 tast_Ea_APlusVolatage = 0U;·
SInt32 tast_Ea_CC2Volatage = 0U;
SInt32 tast_Ea_PreChargeRelayVolatage = 0U;
SInt32 tast_Ea_MainPosRelayVolatage = 0U;
SInt32 tast_Ea_MainNegRelayVolatage = 0U;
SInt32 tast_Ea_HeatRelayVolatage = 0U;
SInt32 tast_Ea_FastChargeRelayVolatage = 0U;
SInt32 tast_Ea_FastChargePosVolatage = 0U;
SInt32 tast_Ea_FastChargeNegVolatage = 0U;
SInt32 tast_Ea_SlowChargePosVolatage = 0U;
SInt32 tast_Ea_MCUtempsource = 0U;
uint32 tast_GetIcuDutyValue_2 = 0U;
uint32 tast_GetIcuPeriodValue_2 = 0U;

uint8 test_Ea_SampleValidBat_U8 = 0U;
uint8 test_Ea_CellTempException = 0U;
uint8 test_Ea_SampleValidCurrent_U8 = 0U;
uint16 tast_WorkTime_GetYear = 0U;

#endif


extern uint32 Cdd_AFE_GetBalanceErrorStatus(uint8 AFEChannel);
extern uint8 Cdd_AFE_GetUARTCommTimeout(void);
extern uint32 Cdd_AFE_GetAFEChipErrorStatus(void);

uint32 Ea_AFEBlnErrSts[AFE_NUM]           = {0};    /* 采集芯片均衡故障 */
uint32 Ea_AFEChipErrSts                   = 0;      /* 采集芯片故障 */

uint8  Ea_WakeSource                      = 0;      /* 唤醒源 */

uint16 Ea_CellTemp[AFE_TOTAL_TEMP_NUM]    = {0};    /* 单体温度 */
uint8  Ea_CellTempVolid                   = 0;      /* 单体温度有效性 */
uint32 Ea_CellTempOpenSts[AFE_NUM]        = {0};    /* 单体温度断线状态 */

uint16 Ea_CellVoltage[AFE_TOTAL_VOL_NUM]  = {0};    /* 单体电压 */
uint8  Ea_CellVoltageVolid                = 0;      /* 单体电压有效性 */
uint32 Ea_CellVoltageOpenSts[AFE_NUM]     = {0};    /* 单体电压断线状态 */
uint8  Ea_CellVoltException               = 0;      /* 电压断线状态 0：无 1：单处断线 2：多处断线 */
SInt32 Ea_MCUtemp                         = 0;

float32 Ea_AFETemp[AFE_NUM]               = {0};    /* AFE娓╁害 */
uint16  Ea_BalTempResistors[AFE_NUM]      = {0};    /* 均衡温度电阻值 */
uint8   AFEuseCellNub[AFE_NUM]            = {0};    /* 每个AFE采集的通道个数；这个后期可以改成固定的，和底层AFE_valCellMask_Mp匹配即可*/
// float32 ChargeGunTempLookTable_x[25]      = {0.0705, 0.0842, 0.1015, 0.1237, 0.1523, 0.1896, 0.2387, 0.3041, 0.3924,
//                                             0.5132, 0.6806, 0.9167, 1.255, 1.749, 2.483, 3.598, 5.326,
//                                             8.059, 12.48, 19.783, 32.097, 53.269, 90.309, 156.05, 273.95};/* KΩ*/
// float32 ChargeGunTempLookTable_y[25]      = {200, 190, 180, 170, 160, 150, 140, 130, 120, 110, 100, 90, 80, 70, 
//                                             60, 50, 40, 30, 20, 10, 0, -10, -20, -30, -40};/* 摄氏度*/

float32 ChargeGunTempLookTable_x[25]      = {0.19876 ,0.24935 ,0.31621 ,0.40567 ,0.52738 ,0.69583 ,0.93277 ,1.2713 ,1.7633 ,2.4925 ,
                                            2.9866 ,3.5987 ,4.3617 ,5.3183 ,6.5244 ,8.0529 ,10.000 ,12.494 ,19.895 ,32.696 ,55.791 ,
                                            98.607 ,180.29 ,345.19 ,693.73};/* KΩ*/
float32 ChargeGunTempLookTable_y[25]      = {150 ,140 ,130 ,120 ,110 ,100 ,90 ,80 ,70 ,60 ,55 ,50 ,45 ,40 ,35 ,30 ,25 ,20 ,10 ,0 ,
                                            -10 ,-20 ,-30 ,-40 ,-50 };/* 摄氏度*/



#if((BAT_VERSION == BAT_65KWH)&&(RUN_AFE_TEMP_NUM == 4)&&(AFE_NUM == 6))
const uint8 indices_MP[AFE_NUM * 4] = {
      0,1,2,3, 6,7,8,9, 12,13,14,15, 18,19,20,21,
      24,25,26,27, 30,31,32,33};                          //65KWH 电池
#elif((BAT_VERSION == BAT_65KWH)&&(RUN_AFE_TEMP_NUM == 4)&&(AFE_NUM == 8))
const uint8 indices_MP[AFE_NUM * 4] = {
      0,1,2,3, 6,7,8,9, 12,13,14,15, 18,19,20,21,
      24,25,26,27, 30,31,32,33, 36,37,38,39, 42,43,44,45}; //65KWH 电池
#elif((BAT_VERSION == BAT_51KWH)&&(RUN_AFE_TEMP_NUM == 3)&&(AFE_NUM == 6))
const uint8 indices_MP[AFE_NUM * 3] = {
      0,1,2,    6,7,8,    12,13,14,   18,19,20,
      24,25,26, 30,31,32};           //51KWH 电池
#else/* ((BAT_VERSION == BAT_51KWH)&&(RUN_AFE_TEMP_NUM == 3)&&(AFE_NUM == 8)) */
const uint8 indices_MP[AFE_NUM * 3] = {
      0,1,2,    6,7,8,    12,13,14,   18,19,20,
      24,25,26, 30,31,32, 36,37,38,   42,43,44};           //51KWH 电池
#endif

extern uint32 AFE_valCellMask_Mp[AFE_NUM];
extern uint8 AFE_valTempNumber_Mp[AFE_NUM];
extern uint8 Ea_ShutdownReq;
extern boolean NVM_XCU_EEWriteFinish;
const uint16 FID1 = 1;const uint16 FID2 = 2;const uint16 FID3 = 3;const uint16 FID4 = 4;const uint16 FID5 = 5;
const uint16 FID6 = 6;const uint16 FID7 = 7;const uint16 FID8 = 8;const uint16 FID9 = 9;const uint16 FID10 = 10;
const uint16 FID11 = 11;const uint16 FID12 = 12;const uint16 FID13 = 13;const uint16 FID14 = 14;const uint16 FID15 = 15;
const uint16 FID16 = 16;const uint16 FID17 = 17;const uint16 FID18 = 18;const uint16 FID19 = 19;const uint16 FID20 = 20;
const uint16 FID21 = 21;const uint16 FID22 = 22;const uint16 FID23 = 23;const uint16 FID24 = 24;const uint16 FID25 = 25;
const uint16 FID26 = 26;const uint16 FID27 = 27;const uint16 FID28 = 28;const uint16 FID29 = 29;const uint16 FID30 = 30;

uint8 Nvm_WriteBlock119Sts = 0;
uint8 Nvm_WriteBlock128Sts = 0;
uint8 Nvm_WriteBlock129Sts = 0;
uint8 Nvm_WriteBlock130Sts = 0;
uint8 Nvm_WriteBlock131Sts = 0;
/**
 * @brief 从源32位数组中按指定位数提取数据，打包到目标32位数组中
 * 
 * 功能说明：
 * - 从每个源数组元素中提取低N位数据（N由bits_per_src指定）
 * - 将提取出的所有位数据按顺序拼接，然后以32位为单位存入目标数组
 * - 例如：源数组有8个元素，分别提取15、13、10...位，总共不超过128位
 * 
 * @param dst        目标数组指针（输出）
 *                   - 类型：uint32*
 *                   - 大小：至少 ceil(总提取位数/32) 个元素
 *                   - 注意：函数会清空目标数组，然后填充提取的数据
 * 
 * @param src        源数组指针（输入）
 *                   - 类型：const uint32*
 *                   - 大小：至少 src_count 个元素
 *                   - 注意：只提取每个元素的低bits_per_src[i]位
 * 
 * @param bits_per_src   每个源元素要提取的位数数组
 *                   - 类型：const uint8*
 *                   - 大小：至少 src_count 个元素
 *                   - 范围：0-32位（建议不超过18位，根据你的应用）
 *                   - 示例：{15, 13, 10, 8, 12, 14, 9, 11}
 * 
 * @param src_count      源数组元素个数
 *                   - 类型：uint8
 *                   - 范围：0-8（根据你的应用，最多8个AFE）
 *                   - 注意：必须 ≤ bits_per_src 数组大小
 * 
 * @param dst_count      目标数组元素个数（用于防止越界）
 *                   - 类型：uint8
 *                   - 范围：建议至少 4（因为最多100位，需要4个uint32）
 *                   - 注意：函数最多写入 dst_count 个元素
 * 
 * @note  函数会先清空目标数组的前 dst_count 个元素
 * @note  如果总提取位数超过 dst_count * 32，超出部分会被丢弃
 * @warning 确保 dst 数组至少有 dst_count 个元素的空间
 */
void ExtractBitsOptimized(uint32* dst, const uint32* src, const uint8* bits_per_src, 
                          uint8 src_count, uint8 dst_count)
{
    uint64 accumulator = 0;     // 位累加器（64位，防止溢出）
    uint8 acc_bits = 0;         // 累加器中当前有效的位数
    uint8 dst_idx = 0;          // 当前要写入的目标数组索引
    
    // 清空目标数组的前 dst_count 个元素
    for(uint8 i = 0; i < dst_count; i++) 
    {
        dst[i] = 0;
    }
    
    // 遍历每个源数组元素
    for(uint8 i = 0; i < src_count && dst_idx < dst_count; i++)
    {
        // 提取当前源元素的低 bits_per_src[i] 位
        // 例如：bits=15，则提取低15位；bits=13，提取低13位
        uint32 value = src[i] & ((1 << bits_per_src[i]) - 1);
        
        // 将提取的值添加到累加器中（注意移位拼接）
        // 例如：累加器中已有15位，现在加入13位，则新数据放在高位
        accumulator |= ((uint64)value << acc_bits);
        acc_bits += bits_per_src[i];
        
        // 当累加器中的位数足够32位时，取出完整的32位写入目标数组
        while(acc_bits >= 32 && dst_idx < dst_count)
        {
            // 取出低32位作为目标数组的一个元素
            dst[dst_idx++] = (uint32)(accumulator & 0xFFFFFFFF);
            // 累加器右移32位，保留剩余的高位数据
            accumulator >>= 32;
            acc_bits -= 32;
        }
    }
    // 处理最后不足32位的剩余数据
    // 例如：总共95位，前两个32位已取出，还剩31位
    if(acc_bits > 0 && dst_idx < dst_count)
    {
        dst[dst_idx] = (uint32)(accumulator & 0xFFFFFFFF);
    }
}

/**
 * @brief 从8个uint32成员中提取指定位，存入uint8数组中
 * 
 * @param src        源数组（8个uint32）
 * @param bits       每个成员要提取的位数，最大为4
 * @param dst        目标uint8数组（至少32个元素）
 * @param dst_size   目标数组大小（用于防止越界）
 * @return uint8     实际提取的总位数
 */
uint8 ExtractBitsToUint8Array(const uint32* src, uint8 bits, 
                               uint8* dst, uint8 dst_size)
{
    uint8 total_bits = 0;
    
    // 清空目标数组
    for(uint8 i = 0; i < dst_size; i++)
    {
        dst[i] = 0;
    }
    
    // 遍历 AFE_NUM 个源成员
    for(uint8 member = 0; member < AFE_NUM; member++)
    {
        // 从第2位开始，提取bits位
        uint32 shifted = src[member] >> 2;
        
        // 逐位提取
        for(uint8 b = 0; b < bits; b++)
        {
            uint8 dst_index = total_bits + b;
            if(dst_index >= dst_size) break;
            
            // 提取第b位的值（0或1）
            dst[dst_index] = (shifted >> b) & 1;
        }
        
        total_bits += bits;
        if(total_bits >= dst_size) break;
    }
    
    return total_bits;
}

//一维查表函数
float32 LookUp1D_Table(float32 x0,float32 xx[],float32 MAP[],uint16 n)
{
    uint16 j = 0;
    float32 x = 0;
    float32 z = 0;
    if(x0 > xx[n-1])
    {
        x0=xx[n-1];
    }
    if(x0 < xx[0]) 
    {
        x0=xx[0];
    }
    while( (x0>=xx[j]) && (j<n) )
    {
        j++;
    }
    j--;
    if(j<0)
    {
        j = 0;
    }
    if(j==(n-1))
    {
        z = MAP[n-1];
    }
    else
    {
        x = (x0-xx[j])*1.0 / (xx[j+1] - xx[j]);
        z = MAP[j] + x * (MAP[j+1] - MAP[j]); 
    }
    return z;
}
/* 缁熻涓�涓� uint32 涓疆1鐨勬瘮鐗逛釜鏁� */
static uint8 CountBits(uint32 val)
{
  uint8 count = 0;
  while (val != 0)
  {
      count++;
      val &= (val - 1);
  }
  return count;
}
void CalAFEuseCellNub(void)
{
  for(uint8 i = 0;i < AFE_NUM;i++)
  {
    AFEuseCellNub[i] = CountBits(AFE_valCellMask_Mp[i]);
  }
}

void CP_SetEvent(uint16 ID,uint8 EventStatus)
{
  if(ID != 0)
  {
      Dem_SetEventStatus(ID,EventStatus);
  }
}
void CP_GetEventStatus(uint16 ID,uint8 *EventStatus)
{
  uint8 Get_EventStsBack = 0;
  if((ID != 0)&&(EventStatus != NULL))
  {
    Get_EventStsBack = Dem_GetEventStatus(ID,EventStatus);
    if(Get_EventStsBack == E_NOT_OK)
    {
      *EventStatus = 0;
    }
  }
  else if((ID == 0)&&(EventStatus != NULL))
  {
    *EventStatus = 0;
  }
  else
  {}
}

/* Model step function */
void BSWIOSP_Get_ACTemp_ErrFLg_Operation(uint8 *ACTemp_ErrFLg)
{
  *ACTemp_ErrFLg = 0U;
}

/* Model step function */
void BSWIOSP_Get_ACUCom_ErrFLg_Operation(boolean *ACUCom_ErrFLg)
{
  /* Outputs for Function Call SubSystem: '<S2>/BSWIOSP_Get_ACUCom_ErrFLg_Operation_sys' */
  /* SignalConversion generated from: '<S66>/ACUCom_ErrFLg' */
  *ACUCom_ErrFLg = false;

  /* End of Outputs for SubSystem: '<S2>/BSWIOSP_Get_ACUCom_ErrFLg_Operation_sys' */
}

/* Model step function */
uint8 Ea_BMUTempOverErr_Count = 0;
void BSWIOSP_Get_BMUTempOver_ErrFLg_Operation(boolean *BMUTempOver_ErrFLg)
{
  if(Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb == 1)
  {
    Ea_BMUTempOverErr_Count = 0;
  }
  if((Ea_MCUtemp >= 105)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagVltgCondFlg ==1))
  {
    if(Ea_BMUTempOverErr_Count < 100)
    {Ea_BMUTempOverErr_Count++;}
  }
  else if((Ea_MCUtemp >= 85)&&(Ea_MCUtemp < 105)&&(Ea_BMUTempOverErr_Count >= 100))
  {}
  else
  {
    Ea_BMUTempOverErr_Count = 0;
  }
  if(Ea_BMUTempOverErr_Count >= 100)
  {
    *BMUTempOver_ErrFLg = true;
  }
  else
  {
    *BMUTempOver_ErrFLg = false;
  }
}

/* Model step function */
void BSWIOSP_Get_BalnCtlModl_ErrFLg_Operation(boolean *BalnCtlModl_ErrFLg)
{
  Ea_AFEBlnErrSts[AFE_Chip_0] = Cdd_AFE_GetBalanceErrorStatus(AFE_Chip_0);
  Ea_AFEBlnErrSts[AFE_Chip_1] = Cdd_AFE_GetBalanceErrorStatus(AFE_Chip_1);
  Ea_AFEBlnErrSts[AFE_Chip_2] = Cdd_AFE_GetBalanceErrorStatus(AFE_Chip_2);
  Ea_AFEBlnErrSts[AFE_Chip_3] = Cdd_AFE_GetBalanceErrorStatus(AFE_Chip_3);
  Ea_AFEBlnErrSts[AFE_Chip_4] = Cdd_AFE_GetBalanceErrorStatus(AFE_Chip_4);
  Ea_AFEBlnErrSts[AFE_Chip_5] = Cdd_AFE_GetBalanceErrorStatus(AFE_Chip_5);
  if((Ea_AFEBlnErrSts[AFE_Chip_0] == 0)&&(Ea_AFEBlnErrSts[AFE_Chip_1] == 0)&&
    (Ea_AFEBlnErrSts[AFE_Chip_2] == 0)&&(Ea_AFEBlnErrSts[AFE_Chip_3] == 0)&&
    (Ea_AFEBlnErrSts[AFE_Chip_4] == 0)&&(Ea_AFEBlnErrSts[AFE_Chip_5] == 0))
  {
    *BalnCtlModl_ErrFLg = false;
  }
  else
  {
    *BalnCtlModl_ErrFLg = true;
  }
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
boolean Test_BattIsoDet_ErrFLg = 0;
#endif
void BSWIOSP_Get_BattIsoDet_ErrFLg_Operation(boolean *BattIsoDet_ErrFLg)
{
  boolean Ea_BattIsoDet_ErrFLg = 0;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_INSULATEVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_BattIsoDet_ErrFLg);
  if((Ea_BattIsoDet_ErrFLg ==1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagVltgCondFlg ==1))
  {
    *BattIsoDet_ErrFLg = true;
  }
  else
  {
    *BattIsoDet_ErrFLg = false;
  }
  #ifdef BMS_Test_Code_KYH
  Test_BattIsoDet_ErrFLg = *BattIsoDet_ErrFLg;
  #endif
}
/* Model step function */
uint8 Ea_CellVoltSampleErr_Count = 0;
void BSWIOSP_Get_CellVoltSampleDiscon_ErrFLg_Operation(boolean *CellVoltSampleDiscon_ErrFLg)
{
  if(Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb == 1)
  {
    Ea_CellVoltSampleErr_Count = 0;
  }
  if((Ea_CellVoltException > 0)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagVltgCondFlg ==1))
  {
    if(Ea_CellVoltSampleErr_Count<80)
    {Ea_CellVoltSampleErr_Count++;}
  }
  else
  {
    Ea_CellVoltSampleErr_Count = 0;
  }
  if(Ea_CellVoltSampleErr_Count >= 80)
  {
    *CellVoltSampleDiscon_ErrFLg = true;
  }
  else
  {
    *CellVoltSampleDiscon_ErrFLg = false;
  }
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_OBC_Sts_Timeout = 0;
#endif
void BSWIOSP_Get_Com_OBC_Sts_Timeout_Operation(uint8 *OBC_Sts_Timeout)
{
  if(CANA_0x220_TimeOut == 1)
  {
    *OBC_Sts_Timeout = 1U;
  }
  else
  {
    *OBC_Sts_Timeout = 0U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_OBC_Sts_Timeout = *OBC_Sts_Timeout;
  #endif
}

/* Model step function */
void BSWIOSP_Get_DCTemp_ErrFLg_Operation(uint8 *DCTemp_ErrFLg)
{
  *DCTemp_ErrFLg = 0U;
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
boolean Test_EVCANBusOff_ErrFLg = 0;
#endif
uint8 Ea_ACANBusOff_Count = 0;
void BSWIOSP_Get_EVCANBusOff_ErrFLg_Operation(boolean *EVCANBusOff_ErrFLg)
{
  if(CANA_stBusoffFlg == 1)
  {
    if(Ea_ACANBusOff_Count < 20)
    {Ea_ACANBusOff_Count++;}
  }
  else
  {
    Ea_ACANBusOff_Count = 0;
  }
  if(Ea_ACANBusOff_Count >= 20)
  {
    *EVCANBusOff_ErrFLg = true;
  }
  else
  {
    *EVCANBusOff_ErrFLg = false;
  }
  #ifdef BMS_Test_Code_KYH
  Test_EVCANBusOff_ErrFLg = *EVCANBusOff_ErrFLg;
  #endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
boolean Test_HCMCom_ErrFLg = 0;
#endif
uint8 Ea_HCM122_TimeOutCount = 0;
void BSWIOSP_Get_HCMCom_ErrFLg_Operation(boolean *HCMCom_ErrFLg)
{
  if(Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb == 1)
  {
    Ea_HCM122_TimeOutCount = 0;
  }
  if((CANG_0x122_TimeOut == 1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagVltgCondFlg ==1))
  {
    if(Ea_HCM122_TimeOutCount < 200)
    {Ea_HCM122_TimeOutCount++;}
  }
  else
  {
    Ea_HCM122_TimeOutCount = 0;
  }
  if(Ea_HCM122_TimeOutCount >= 200)
  {
    *HCMCom_ErrFLg = true;
  }
  else
  {
    *HCMCom_ErrFLg = false;
  }
  #ifdef BMS_Test_Code_KYH
  Test_HCMCom_ErrFLg = *HCMCom_ErrFLg;
  #endif
}

/* Model step function */
void BSWIOSP_Get_HCME2E_ErrFLg_Operation(boolean *HCME2E_ErrFLg)
{
  *HCME2E_ErrFLg = false;
}

/* Model step function */
void BSWIOSP_Get_HCMbusoff_ErrFLg_Operation(boolean *HCMbusoff_ErrFLg)
{
  /* Outputs for Function Call SubSystem: '<S12>/BSWIOSP_Get_HCMbusoff_ErrFLg_Operation_sys' */
  /* SignalConversion generated from: '<S76>/HCMbusoff_ErrFLg' */
  *HCMbusoff_ErrFLg = false;

  /* End of Outputs for SubSystem: '<S12>/BSWIOSP_Get_HCMbusoff_ErrFLg_Operation_sys' */
}

/* Model step function */
uint8 Ea_IntCANE2EErr_Count = 0;
void BSWIOSP_Get_IntCANE2E_ErrFLg_Operation(boolean *IntCANE2E_ErrFLg)
{
  uint8 Ea_UARTSPITimeoutSts = 0;
  Ea_UARTSPITimeoutSts = Cdd_AFE_GetUARTCommTimeout();

  if(Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb == 1)
  {
    Ea_IntCANE2EErr_Count = 0;
  }
  if((Ea_UARTSPITimeoutSts > 0)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagCondKeyOn ==1)&&(Can_DiagVltgCondFlg ==1))
  {
    if(Ea_IntCANE2EErr_Count < 80)
    {Ea_IntCANE2EErr_Count++;}
  }
  else
  {
    Ea_IntCANE2EErr_Count = 0;
  }
  if(Ea_IntCANE2EErr_Count >= 80)
  {*IntCANE2E_ErrFLg = 1U;}
  else
  {*IntCANE2E_ErrFLg = 0U;}
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_NvM_Save_Ok = 0;
#endif
void BSWIOSP_Get_NvM_Save_Ok_Operation(uint8 *NvM_Save_Ok)
{
  if(NVM_XCU_EEWriteFinish == 1)
  {
    if((Nvm_WriteBlock119Sts == 0)&&(Nvm_WriteBlock128Sts == 0)&&(Nvm_WriteBlock129Sts == 0)&&(Nvm_WriteBlock130Sts == 0)&&(Nvm_WriteBlock131Sts == 0))
    {
      *NvM_Save_Ok = 1U;

    }
    else
    {
      *NvM_Save_Ok = 0U;

    }
  }
  else
  {
    *NvM_Save_Ok = 0U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_NvM_Save_Ok = *NvM_Save_Ok;
  #endif
}

/* Model step function */
void BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation(boolean *PMS_BMSH_Ctrl_Timeout)
{
  /* Outputs for Function Call SubSystem: '<S15>/BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation_sys' */
  /* SignalConversion generated from: '<S79>/PMS_BMSH_Ctrl_Timeout' */
  *PMS_BMSH_Ctrl_Timeout = false;

  /* End of Outputs for SubSystem: '<S15>/BSWIOSP_Get_PMS_BMSH_Ctrl_Timeout_Operation_sys' */
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
boolean Test_RlyKCVoltSample_ErrFLg = 0;
#endif
void BSWIOSP_Get_RlyKCVoltSample_ErrFLg_Operation(boolean *RlyKCVoltSample_ErrFLg)
{
  uint8 Ea_SampleValidKC_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_FASTCHGBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidKC_U8);
  if(Ea_SampleValidKC_U8 == 1)
  {
    *RlyKCVoltSample_ErrFLg = true;
  }
  else
  {
    *RlyKCVoltSample_ErrFLg = false;
  }
  #ifdef BMS_Test_Code_KYH
  Test_RlyKCVoltSample_ErrFLg = *RlyKCVoltSample_ErrFLg;
  #endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
boolean Test_RlyKMVoltSample_ErrFLg = 0;
#endif
void BSWIOSP_Get_RlyKMVoltSample_ErrFLg_Operation(boolean *RlyKMVoltSample_ErrFLg)
{
  uint8 Ea_SampleValidKM_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_MAINPOSBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidKM_U8);
  if(Ea_SampleValidKM_U8 == 1)
  {
    *RlyKMVoltSample_ErrFLg = true;
  }
  else
  {
    *RlyKMVoltSample_ErrFLg = false;
  }
  #ifdef BMS_Test_Code_KYH
  Test_RlyKMVoltSample_ErrFLg = *RlyKMVoltSample_ErrFLg;
  #endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
boolean Test_RlyKNVoltSample_ErrFLg = 0;
#endif
void BSWIOSP_Get_RlyKNVoltSample_ErrFLg_Operation(boolean *RlyKNVoltSample_ErrFLg)
{  
  uint8 Ea_SampleValidKN_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_MAINNEGBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidKN_U8);
  if(Ea_SampleValidKN_U8 == 1)
  {
    *RlyKNVoltSample_ErrFLg = true;
  }
  else
  {
    *RlyKNVoltSample_ErrFLg = false;
  }
  #ifdef BMS_Test_Code_KYH
  Test_RlyKNVoltSample_ErrFLg = *RlyKNVoltSample_ErrFLg;
  #endif
}

/* Model step function */
void BSWIOSP_Get_STHW_ErrFLg_Operation(boolean *STHW_ErrFLg)
{
  Ea_AFEChipErrSts = Cdd_AFE_GetAFEChipErrorStatus();
  if(Ea_AFEChipErrSts > 0)
  {
    *STHW_ErrFLg = true;
  }
  else
  {
    *STHW_ErrFLg = false;
  }
}

/* Model step function */
void BSWIOSP_Get_StsElectroniclockContor_Operation(uint8  *StsElectroniclockContor)
{
  *StsElectroniclockContor = 0U;
}

/* Model step function */
void BSWIOSP_Get_VCUCom_ErrFLg_Operation(boolean *VCUCom_ErrFLg)
{
  /* Outputs for Function Call SubSystem: '<S21>/BSWIOSP_Get_VCUCom_ErrFLg_Operation_sys' */
  /* SignalConversion generated from: '<S85>/VCUCom_ErrFLg' */
  *VCUCom_ErrFLg = false;

  /* End of Outputs for SubSystem: '<S21>/BSWIOSP_Get_VCUCom_ErrFLg_Operation_sys' */
}

/* Model step function */
void BSWIOSP_Get_WeakUpFlg_Operation(uint8 *WeakUpFlg)
{
  Ea_WakeSource = BswM_GetWakeSource();
  if(Ea_WakeSource == 3)
  {
    *WeakUpFlg = 1;//唤醒源为钥匙唤醒
  }
  else if((Ea_WakeSource == 4)||(Ea_WakeSource == 5))
  {
    *WeakUpFlg = 2;//唤醒源为充电枪唤醒
  }
  else if(Ea_WakeSource == 7)
  {
    *WeakUpFlg = 3;//唤醒源为RTC唤醒
  }
  else if((Ea_WakeSource == 1)||(Ea_WakeSource == 2))
  {
    *WeakUpFlg = 4;//唤醒源为CAN唤醒
  }
  else
  {
    *WeakUpFlg = 0;
  }
}

/* Model step function */
void BSWIOSP_Get_bCANWakeUp_Operation(boolean *bCANWakeUp)
{
  Ea_WakeSource = BswM_GetWakeSource();
  if((Ea_WakeSource == 1)||(Ea_WakeSource == 2))
  {*bCANWakeUp = true;}
  else
  {*bCANWakeUp = false;}
}

/* Model step function */
void BmuSample_Get_BMUCell_Operation(uint16 BMUCell[130])
{
  Ea_CellVoltageVolid = Cdd_AFE_GetCellVoltages(Ea_CellVoltage,AFE_TOTAL_VOL_NUM);
  /* Outputs for Function Call SubSystem: '<S24>/BmuSample_Get_BMUCell_Operation_sys' */
  /* SignalConversion generated from: '<S88>/BMUCell' */
  CalAFEuseCellNub();
  for(uint8 ii = 0;ii<130; ii++)
  {
    BMUCell[ii] = 0;
  }
  uint16 offset = 0;
  for(uint8 afe = 0; afe < AFE_NUM; afe++)
  {
      for(uint8 i = 0; i < AFEuseCellNub[afe]; i++)
      {
          BMUCell[offset + i] = Ea_CellVoltage[i + ONE_AFE_VOL_NUM * afe];
      }
      offset += AFEuseCellNub[afe];
  }
  /* End of Outputs for SubSystem: '<S24>/BmuSample_Get_BMUCell_Operation_sys' */
}

/* Model step function */
void BmuSample_Get_BMUCellVSt_Operation(uint32 BMUCellVSt[4])
{
  Cdd_AFE_GetCellOpenWireStatus(Ea_CellVoltageOpenSts,AFE_NUM);
  ExtractBitsOptimized(BMUCellVSt, Ea_CellVoltageOpenSts, AFEuseCellNub, AFE_NUM, 4);
  /* Outputs for Function Call SubSystem: '<S25>/BmuSample_Get_BMUCellVSt_Operation_sys' */
  /* SignalConversion generated from: '<S89>/BMUCellVSt' */


  /* End of Outputs for SubSystem: '<S25>/BmuSample_Get_BMUCellVSt_Operation_sys' */
}

/* Model step function */
void BmuSample_Get_BMUChipTemp_Operation(sint16 BMUChipTemp[8])
{
  Cdd_AFE_GetChipTemp(Ea_AFETemp,AFE_NUM);
  /* Outputs for Function Call SubSystem: '<S26>/BmuSample_Get_BMUChipTemp_Operation_sys' */
  /* SignalConversion generated from: '<S90>/BMUChipTemp' */
  uint32 i;
  for (i = 0; i < AFE_NUM; i++) {
    BMUChipTemp[i] = (sint16)(Ea_AFETemp[i]);
  }

  /* End of SignalConversion generated from: '<S90>/BMUChipTemp' */
  /* End of Outputs for SubSystem: '<S26>/BmuSample_Get_BMUChipTemp_Operation_sys' */
}

/* Model step function */
void BmuSample_Get_BMUTemp_Operation(sint16 BMUTemp[32])
{
  Ea_CellTempVolid = Cdd_AFE_GetCellTempResistance(Ea_CellTemp,AFE_TOTAL_TEMP_NUM);
  /* Outputs for Function Call SubSystem: '<S27>/BmuSample_Get_BMUTemp_Operation_sys' */
  /* SignalConversion generated from: '<S91>/BMUTemp' */

  for(uint8 j = 0; j < (AFE_NUM * RUN_AFE_TEMP_NUM); j++)
  {
    BMUTemp[j] = 0;
  }
  for (uint8 i = 0; i < (AFE_NUM * RUN_AFE_TEMP_NUM); i++) {
    BMUTemp[i] = (sint16)(Ea_CellTemp[indices_MP[i]]*0.5);
  }


  /* End of Outputs for SubSystem: '<S27>/BmuSample_Get_BMUTemp_Operation_sys' */
}

/* Model step function */
void BmuSample_Get_BMUTempSt_Operation(uint8 BMUTempSt[32])
{
  uint8 getbitsnub = 0;
  if(AFE_valTempNumber_Mp[0] > 2)
  {
    getbitsnub = AFE_valTempNumber_Mp[0] - 2;
  }
  else
  {
    getbitsnub = 2;
  }
  if((getbitsnub > 4)||(getbitsnub < 0))
  {
    getbitsnub = 4;
  }
  ExtractBitsToUint8Array(Ea_CellTempOpenSts, getbitsnub, BMUTempSt, AFE_NUM*4);
}

/* Model step function */
void BmuSample_Get_BalanceTemp_Operation(sint16 BalanceTemp[8])
{
  Cdd_AFE_GetBalTempResistance(Ea_BalTempResistors, AFE_NUM);


  /* Outputs for Function Call SubSystem: '<S29>/BmuSample_Get_BalanceTemp_Operation_sys' */
  /* SignalConversion generated from: '<S93>/BalanceTemp' */
  sint32 i;
  for (i = 0; i < AFE_NUM; i++) {
    BalanceTemp[i] = (sint16)(Ea_BalTempResistors[i]*0.5);
  }

  /* End of SignalConversion generated from: '<S93>/BalanceTemp' */
  /* End of Outputs for SubSystem: '<S29>/BmuSample_Get_BalanceTemp_Operation_sys' */
}

/* Model step function */
void BmuSample_Get_CellTEffective_Operation(uint8 *CellTEffective)
{
  /* Outputs for Function Call SubSystem: '<S30>/BmuSample_Get_CellTEffective_Operation_sys' */
  /* SignalConversion generated from: '<S94>/CellTEffective' */
  *CellTEffective = Ea_CellTempVolid;

  /* End of Outputs for SubSystem: '<S30>/BmuSample_Get_CellTEffective_Operation_sys' */
}

/* Model step function */
void BmuSample_Get_CellTempException_Operation(uint8 *CellTempException)
{
  Cdd_AFE_GetTempOpenWireStatus(Ea_CellTempOpenSts,AFE_NUM);
  uint8 total = 0;
  for (uint8 i = 0; i < AFE_NUM; i++)
  {
    total += CountBits(Ea_CellTempOpenSts[i]);
  }
  if (total == 0)
  {
    *CellTempException = 0U;
  }
  else if (total == 1)
  {
    *CellTempException = 1U;
  }
  else
  {
    *CellTempException = 2U;
  }
#ifdef VCU_Test_Code_LK
  test_Ea_CellTempException = *CellTempException;
#endif

}

/* Model step function */
void BmuSample_Get_CellVEffective_Operation(uint8 *CellVEffective)
{
  if(Ea_CellVoltageVolid == 1)
  {
    *CellVEffective = 0;
  }
  else
  {
    *CellVEffective = 1;
  }
}

/* Model step function */
void BmuSample_Get_CellVoltException_Operation(uint8 *CellVoltException)
{
  Cdd_AFE_GetCellOpenWireStatus(Ea_CellVoltageOpenSts,AFE_NUM);
  uint8 total = 0;
  for (uint8 i = 0; i < AFE_NUM; i++)
  {
    total += CountBits(Ea_CellVoltageOpenSts[i]);
  }
  if (total == 0)
  {
    *CellVoltException = 0U;
  }
  else if (total == 1)
  {
    *CellVoltException = 1U;
  }
  else
  {
    *CellVoltException = 2U;
  }
  Ea_CellVoltException = total;
}

/* Model step function */
void HvSysSample_Get_Current_Operation(sint16 *Current)
{
  /* Outputs for Function Call SubSystem: '<S34>/HvSysSample_Get_Current_Operation_sys' */
  /* SignalConversion generated from: '<S98>/Current' */
  *Current = 0;

  /* End of Outputs for SubSystem: '<S34>/HvSysSample_Get_Current_Operation_sys' */
}

/* Model step function */
void HvSysSample_Get_NegInsulationRes_Operation(SInt32 *NegInsulationRes)
{
  /* Outputs for Function Call SubSystem: '<S35>/HvSysSample_Get_NegInsulationRes_Operation_sys' */
  /* SignalConversion generated from: '<S99>/NegInsulationRes' */
  *NegInsulationRes = 0;

  /* End of Outputs for SubSystem: '<S35>/HvSysSample_Get_NegInsulationRes_Operation_sys' */
}

/* Model step function */
void HvSysSample_Get_PosInsulationRes_Operation(SInt32 *PosInsulationRes)
{
  /* Outputs for Function Call SubSystem: '<S36>/HvSysSample_Get_PosInsulationRes_Operation_sys' */
  /* SignalConversion generated from: '<S100>/PosInsulationRes' */
  *PosInsulationRes = 0;

  /* End of Outputs for SubSystem: '<S36>/HvSysSample_Get_PosInsulationRes_Operation_sys' */
}

/* Model step function */
void HvSysSample_Get_RelayKCVoltage_Operation(SInt32 *RelayKCVoltage)
{
  /* Outputs for Function Call SubSystem: '<S37>/HvSysSample_Get_RelayKCVoltage_Operation_sys' */
  /* SignalConversion generated from: '<S101>/RelayKCVoltage' */
  *RelayKCVoltage = 0;

  /* End of Outputs for SubSystem: '<S37>/HvSysSample_Get_RelayKCVoltage_Operation_sys' */
}

/* Model step function */
void HvSysSample_Get_RelayKHVoltage_Operation(SInt32 *RelayKHVoltage)
{
  /* Outputs for Function Call SubSystem: '<S38>/HvSysSample_Get_RelayKHVoltage_Operation_sys' */
  /* SignalConversion generated from: '<S102>/RelayKHVoltage' */
  *RelayKHVoltage = 0;

  /* End of Outputs for SubSystem: '<S38>/HvSysSample_Get_RelayKHVoltage_Operation_sys' */
}

/* Model step function */
void HvSysSample_Get_RelayKMVoltage_Operation(SInt32 *RelayKMVoltage)
{
  /* Outputs for Function Call SubSystem: '<S39>/HvSysSample_Get_RelayKMVoltage_Operation_sys' */
  /* SignalConversion generated from: '<S103>/RelayKMVoltage' */
  *RelayKMVoltage = 0;

  /* End of Outputs for SubSystem: '<S39>/HvSysSample_Get_RelayKMVoltage_Operation_sys' */
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_RelayKNClsSts_U8 = 0;
#endif
void HvSysSample_Get_RelayKNClsSts_U8_Operation(uint8 *RelayKNClsSts_U8)
{
  if(Rte_ComBuffer_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx > 14)
  {
    *RelayKNClsSts_U8 = 0U;
  }
  else
  {
    *RelayKNClsSts_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_RelayKNClsSts_U8 = *RelayKNClsSts_U8;
  #endif
}

/* Model step function */
void HvSysSample_Get_RelayKNVoltage_Operation(SInt32 *RelayKNVoltage)
{
  /* Outputs for Function Call SubSystem: '<S41>/HvSysSample_Get_RelayKNVoltage_Operation_sys' */
  /* SignalConversion generated from: '<S105>/RelayKNVoltage' */
  *RelayKNVoltage = 0;

  /* End of Outputs for SubSystem: '<S41>/HvSysSample_Get_RelayKNVoltage_Operation_sys' */
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint16 Test_SampleCountCurrent_U16 = 0;
#endif
uint16 Ea_SampleCountCurrent_U16 = 0;
void HvSysSample_Get_SampleCountCurrent_U16_Operation(uint16 *SampleCountCurrent_U16)
{
  if(Ea_SampleCountCurrent_U16 >= 65535)
  {
    Ea_SampleCountCurrent_U16 = 0U;
  }
  else
  {
    if(CANG_0x122_Active == 1)
    {
      (Ea_SampleCountCurrent_U16)++;
    }
  }
  *SampleCountCurrent_U16 = Ea_SampleCountCurrent_U16;
  #ifdef BMS_Test_Code_KYH
  Test_SampleCountCurrent_U16 = *SampleCountCurrent_U16;
  #endif
}

/* Model step function */
void HvSysSample_Get_SampleCountInsRes_U16_Operation(uint16 *SampleCountInsRes_U16)
{
  *SampleCountInsRes_U16 = 0U;
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint16 Test_SampleCountTotalVol_U16 = 0;
#endif
uint16 Ea_SampleCountTotalVol_U16 = 0;
void HvSysSample_Get_SampleCountTotalVol_U16_Operation(uint16 *SampleCountTotalVol_U16)
{
  if(Ea_SampleCountTotalVol_U16 >= 65535)
  {
    Ea_SampleCountTotalVol_U16 = 0U;
  }
  else
  {
    if(CANG_0x122_Active == 1)
    {
      Ea_SampleCountTotalVol_U16++;
    }
  }
  *SampleCountTotalVol_U16 = Ea_SampleCountTotalVol_U16;
  #ifdef BMS_Test_Code_KYH
  Test_SampleCountTotalVol_U16 = *SampleCountTotalVol_U16;
  #endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_SampleValidBat_U8 = 0U;
#endif
void HvSysSample_Get_SampleValidBat_U8_Operation(uint8 *SampleValidBat_U8)
{
  uint8 Ea_SampleValidBat_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_VOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidBat_U8);
  if(Ea_SampleValidBat_U8 == 1)
  {
    *SampleValidBat_U8 = 0U;
  }
  else
  {
    *SampleValidBat_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_SampleValidBat_U8 = *SampleValidBat_U8;
  #endif
#ifdef VCU_Test_Code_LK
  test_Ea_SampleValidBat_U8 = *SampleValidBat_U8;
#endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_SampleValidCurrent_U8 = 0U;
#endif
void HvSysSample_Get_SampleValidCurrent_U8_Operation(uint8 *SampleValidCurrent_U8)
{
  uint8 Ea_SampleValidCurrent_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_CURRVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidCurrent_U8);
  if(Ea_SampleValidCurrent_U8 == 1)
  {
    *SampleValidCurrent_U8 = 0U;
  }
  else
  {
    *SampleValidCurrent_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_SampleValidCurrent_U8 = *SampleValidCurrent_U8;
  #endif
#ifdef VCU_Test_Code_LK
  test_Ea_SampleValidCurrent_U8 = *SampleValidCurrent_U8;
#endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_SampleValidIsolation_U8 = 0;
#endif
void HvSysSample_Get_SampleValidIsolation_U8_Operation(uint8 *SampleValidIsolation_U8)
{
  uint8 Ea_SampleValidIsolation_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_INSULATEVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidIsolation_U8);
  if(Ea_SampleValidIsolation_U8 == 1)
  {
    *SampleValidIsolation_U8 = 0U;
  }
  else
  {
    *SampleValidIsolation_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_SampleValidIsolation_U8 = *SampleValidIsolation_U8;
  #endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_SampleValidKC_U8 = 0U;
#endif
void HvSysSample_Get_SampleValidKC_U8_Operation(uint8 *SampleValidKC_U8)
{
  uint8 Ea_SampleValidKC_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_FASTCHGBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidKC_U8);
  if(Ea_SampleValidKC_U8 == 1)
  {
    *SampleValidKC_U8 = 0U;
  }
  else
  {
    *SampleValidKC_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_SampleValidKC_U8 = *SampleValidKC_U8;
  #endif
}

/* Model step function */
void HvSysSample_Get_SampleValidKH_U8_Operation(uint8 *SampleValidKH_U8)
{
  *SampleValidKH_U8 = 0U;
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_SampleValidKM_U8 = 0;
#endif
void HvSysSample_Get_SampleValidKM_U8_Operation(uint8 *SampleValidKM_U8)
{
  uint8 Ea_SampleValidKM_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_MAINPOSBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidKM_U8);
  if(Ea_SampleValidKM_U8 == 1)
  {
    *SampleValidKM_U8 = 0U;
  }
  else
  {
    *SampleValidKM_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_SampleValidKM_U8 = *SampleValidKM_U8;
  #endif
}

/* Model step function */
#ifdef BMS_Test_Code_KYH
uint8 Test_SampleValidKN_U8 = 0U;
#endif
void HvSysSample_Get_SampleValidKN_U8_Operation(uint8 *SampleValidKN_U8)
{
  uint8 Ea_SampleValidKN_U8 = 0U;
  Com_ReceiveSignal(COMCONF_COMSIGNAL_HCM_STATUS_LGFZID_HCM_MAINNEGBACKVOLTVALIDSTAT_HCM_STATUS_N72_HCM__MATRIX_V1_1_DBC_RX,&Ea_SampleValidKN_U8);
  if(Ea_SampleValidKN_U8 == 1)
  {
    *SampleValidKN_U8 = 0U;
  }
  else
  {
    *SampleValidKN_U8 = 1U;
  }
  #ifdef BMS_Test_Code_KYH
  Test_SampleValidKN_U8 = *SampleValidKN_U8;
  #endif
}

/* Model step function */
void HvSysSample_Get_TotalVoltage_Operation(SInt32 *TotalVoltage)
{
  /* Outputs for Function Call SubSystem: '<S52>/HvSysSample_Get_TotalVoltage_Operation_sys' */
  /* SignalConversion generated from: '<S116>/TotalVoltage' */
  *TotalVoltage = 0;

  /* End of Outputs for SubSystem: '<S52>/HvSysSample_Get_TotalVoltage_Operation_sys' */
}

/* Model step function */
void If_AdcConvertValueInput_GetAdcConvertValue(UInt32 NumId, SInt32 *value)
{
  // UNUSED_PARAMETER(NumId);
  uint16 Ea_KL30Volatage = 0;
  uint16 Ea_KL15Volatage = 0; Boolean Ea_DCDCWakeBackSts = 0;
  uint16 Ea_APlusVolatage = 0;
  uint16 Ea_CC2Volatage = 0;
  uint16 Ea_PreChargeRelayVolatage = 0;
  uint16 Ea_MainPosRelayVolatage = 0;
  uint16 Ea_MainNegRelayVolatage = 0;
  uint16 Ea_HeatRelayVolatage = 0;
  uint16 Ea_FastChargeRelayVolatage = 0;
  uint16 Ea_FastChargePosVolatage = 0;  float32 Ea_FastChargePosRes = 0;
  uint16 Ea_FastChargeNegVolatage = 0;  float32 Ea_FastChargeNegRes = 0;
  uint16 Ea_SlowChargePosVolatage = 0;  float32 Ea_SlowChargePosRes = 0;
  uint16 Ea_SlowChargeNegVolatage = 0;  float32 Ea_SlowChargeNegRes = 0;
  float32 Ea_MCUtempsource = 0;
  switch (NumId)
  {
  case 4:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_UBD_Mic,&Ea_KL30Volatage);
    *value = (SInt32)(Ea_KL30Volatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_KL30Volatage = (uint16)*value;
#endif
    break;
  case 10:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_KEY_Mic,&Ea_KL15Volatage);
    *value = (SInt32)(Ea_KL15Volatage*0.01);
    // IoHwAbs_DIO_GetChannelValue(IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB9,&Ea_DCDCWakeBackSts);
    // if(Ea_DCDCWakeBackSts > 0)
    // {
    //   *value = (SInt32)(120);
    // }
    // else
    // {
    //   *value = (SInt32)(0);
    // }
    

#ifdef VCU_Test_Code_LK
    tast_Ea_KL15Volatage = (uint16)*value;
#endif
    break;
  case 8:
    // IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_DC_APlus2_Mic,&Ea_APlusVolatage);
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic,&Ea_APlusVolatage);
    *value = (SInt32)(Ea_APlusVolatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_APlusVolatage = (uint16)*value;
#endif
    break;
  case 2:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_IN_AN14,&Ea_CC2Volatage);
    if(Ea_CC2Volatage >= 5000)
    {
      Ea_CC2Volatage = 4999;
    }
    if(Ea_CC2Volatage <= 0)
    {
      Ea_CC2Volatage = 1;
    }
    *value = (SInt32)((Ea_CC2Volatage*1000)/(5000 - Ea_CC2Volatage));

#ifdef VCU_Test_Code_LK
    tast_Ea_CC2Volatage = (uint16)*value;
#endif
    break;
  case 13:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_D_HS3_DIAG,&Ea_PreChargeRelayVolatage);
    *value = (SInt32)(Ea_PreChargeRelayVolatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_PreChargeRelayVolatage = (uint16)*value;
#endif
    break;
  case 12:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_D_HS7_DIAG,&Ea_MainPosRelayVolatage);
    *value = (SInt32)(Ea_MainPosRelayVolatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_MainPosRelayVolatage = (uint16)*value;
#endif
    break;
  case 15:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_D_HS1_DIAG,&Ea_MainNegRelayVolatage);
    *value = (SInt32)(Ea_MainNegRelayVolatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_MainNegRelayVolatage = (uint16)*value;
#endif
    break;
  case 20:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_D_HS4_DIAG,&Ea_HeatRelayVolatage);
    *value = (SInt32)(Ea_HeatRelayVolatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_HeatRelayVolatage = (uint16)*value;
#endif
    break;
  case 16:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_MCU_D_HS8_DIAG,&Ea_FastChargeRelayVolatage);
    *value = (SInt32)(Ea_FastChargeRelayVolatage*0.01);
#ifdef VCU_Test_Code_LK
    tast_Ea_FastChargeRelayVolatage = (uint16)*value;
#endif
    break;
  case 25:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_IN_AN8,&Ea_FastChargePosVolatage);
    if(Ea_FastChargePosVolatage >= 5000)
    {
      Ea_FastChargePosVolatage = 4999;
    }
    if(Ea_FastChargePosVolatage <= 0)
    {
      Ea_FastChargePosVolatage = 1;
    }
    Ea_FastChargePosRes = (float32)((Ea_FastChargePosVolatage*10000)/(5000 - Ea_FastChargePosVolatage));
    *value = (SInt32)(10*LookUp1D_Table((Ea_FastChargePosRes*0.001),ChargeGunTempLookTable_x,ChargeGunTempLookTable_y,25));
#ifdef VCU_Test_Code_LK
    tast_Ea_FastChargePosVolatage = *value;
#endif
    break;
  case 24:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_IN_AN9,&Ea_FastChargeNegVolatage);
    if(Ea_FastChargeNegVolatage >= 5000)
    {
      Ea_FastChargeNegVolatage = 4999;
    }
    if(Ea_FastChargeNegVolatage <= 0)
    {
      Ea_FastChargeNegVolatage = 1;
    }
    Ea_FastChargeNegRes = (SInt32)((Ea_FastChargeNegVolatage*10000)/(5000 - Ea_FastChargeNegVolatage));
    *value = (SInt32)(10*LookUp1D_Table((Ea_FastChargeNegRes*0.001),ChargeGunTempLookTable_x,ChargeGunTempLookTable_y,25));
#ifdef VCU_Test_Code_LK
    tast_Ea_FastChargeNegVolatage = *value;
#endif
    break;
  case 23:
    IoHwAbs_ADC_GetChannelValue(IOHWABS_ADC_CHANNEL_IN_AN4,&Ea_SlowChargePosVolatage);
    if(Ea_SlowChargePosVolatage >= 5000)
    {
      Ea_SlowChargePosVolatage = 4999;
    }
    if(Ea_SlowChargePosVolatage <= 0)
    {
      Ea_SlowChargePosVolatage = 1;
    }
    Ea_SlowChargePosRes = (SInt32)((Ea_SlowChargePosVolatage*10000)/(5000 - Ea_SlowChargePosVolatage));
    *value = (SInt32)(10*LookUp1D_Table((Ea_SlowChargePosRes*0.001),ChargeGunTempLookTable_x,ChargeGunTempLookTable_y,25));
#ifdef VCU_Test_Code_LK
    tast_Ea_SlowChargePosVolatage = *value;
#endif
    break;
  case 1:
      *value = 0;
    break;
  case 27:
      *value = 0;
    break;
  case 7:
      *value = 0;
    break;
  case 26:
    Sys_GetNTCTempureValue(SYS_NTCThermisor_MCU,&Ea_MCUtempsource);
    *value = (SInt32)Ea_MCUtempsource;
    Ea_MCUtemp = (SInt32)Ea_MCUtempsource;
#ifdef VCU_Test_Code_LK
    tast_Ea_MCUtempsource = (uint16)*value;
#endif
    break;

  default:
    *value = 0;
    break;
  }
}

/* Model step function */
void If_IcuDutyValueInput_GetIcuDutyValue(UInt32 NumId, UInt32 *value)
{
  // UNUSED_PARAMETER(NumId);

  /* Outputs for Function Call SubSystem: '<S54>/If_IcuDutyValueInput_GetIcuDutyValue_sys' */
  /* SignalConversion generated from: '<S118>/value' */
  Pwm_ResultIn_TDSTR Ea_CrashSignalpwm = {0};
  switch (NumId)
  {
  case 2:
    IoHwAbs_ICU_GetChanneValue(IOHWABS_ICU_PwmIn_CH5, &Ea_CrashSignalpwm);
    if(Ea_CrashSignalpwm.flgActive == 1)
    {
      *value = Ea_CrashSignalpwm.numDuty;
    }
#ifdef VCU_Test_Code_LK
    tast_GetIcuDutyValue_2 = (uint16)*value;
#endif
    break;
  case 1:
  *value = 0U;
    break;
  case 4:
    *value = 0U;
    break;  
  default:
    break;
  }
  /* End of Outputs for SubSystem: '<S54>/If_IcuDutyValueInput_GetIcuDutyValue_sys' */
}

/* Model step function */
void If_IcuPeriodValueInput_GetIcuPeriodValue(UInt32 NumId, UInt32 *value)
{
  // UNUSED_PARAMETER(NumId);

  /* Outputs for Function Call SubSystem: '<S55>/If_IcuPeriodValueInput_GetIcuPeriodValue_sys' */
  /* SignalConversion generated from: '<S119>/value' */
  Pwm_ResultIn_TDSTR Ea_CrashSignalpwm = {0};
  switch (NumId)
  {
  case 2:
    IoHwAbs_ICU_GetChanneValue(IOHWABS_ICU_PwmIn_CH5, &Ea_CrashSignalpwm);
    if(Ea_CrashSignalpwm.flgActive == 1)
    {
      *value = Ea_CrashSignalpwm.numFreq;
    }
#ifdef VCU_Test_Code_LK
    tast_GetIcuPeriodValue_2 = *value;
#endif
    break;
  case 4:
  *value = 0U;
    break;
  default:
    break;
  }
  /* End of Outputs for SubSystem: '<S55>/If_IcuPeriodValueInput_GetIcuPeriodValue_sys' */
}

/* Model step function */
void RTC_Get_NowSystemTick_Operation(UInt32 *NowSystemTick)
{
  *NowSystemTick = 0U;
}

/* Model step function */
void RTC_Get_RTCStateFault_Operation(SInt32 *RTCStateFault)
{
  /* Outputs for Function Call SubSystem: '<S57>/RTC_Get_RTCStateFault_Operation_sys' */
  /* SignalConversion generated from: '<S121>/RTCStateFault' */
  *RTCStateFault = 0;

  /* End of Outputs for SubSystem: '<S57>/RTC_Get_RTCStateFault_Operation_sys' */
}

/* Model step function */
void RTC_Get_ReadDay_Operation(uint8 *ReadDay)
{
  /* Outputs for Function Call SubSystem: '<S58>/RTC_Get_ReadDay_Operation_sys' */
  /* SignalConversion generated from: '<S122>/ReadDay' */
  *ReadDay = WorkTime_GetDay();

  /* End of Outputs for SubSystem: '<S58>/RTC_Get_ReadDay_Operation_sys' */
}

/* Model step function */
void RTC_Get_ReadHour_Operation(uint8 *ReadHour)
{
  /* Outputs for Function Call SubSystem: '<S59>/RTC_Get_ReadHour_Operation_sys' */
  /* SignalConversion generated from: '<S123>/ReadHour' */
  *ReadHour = WorkTime_GetHours();

  /* End of Outputs for SubSystem: '<S59>/RTC_Get_ReadHour_Operation_sys' */
}

/* Model step function */
void RTC_Get_ReadMinute_Operation(uint8 *ReadMinute)
{
  /* Outputs for Function Call SubSystem: '<S60>/RTC_Get_ReadMinute_Operation_sys' */
  /* SignalConversion generated from: '<S124>/ReadMinute' */
  *ReadMinute = WorkTime_GetMinutes();

  /* End of Outputs for SubSystem: '<S60>/RTC_Get_ReadMinute_Operation_sys' */
}

/* Model step function */
void RTC_Get_ReadMonth_Operation(uint8 *ReadMonth)
{
  /* Outputs for Function Call SubSystem: '<S61>/RTC_Get_ReadMonth_Operation_sys' */
  /* SignalConversion generated from: '<S125>/ReadMonth' */
  *ReadMonth = WorkTime_GetMonth();

  /* End of Outputs for SubSystem: '<S61>/RTC_Get_ReadMonth_Operation_sys' */
}

/* Model step function */
void RTC_Get_ReadSecond_Operation(uint8 *ReadSecond)
{
  /* Outputs for Function Call SubSystem: '<S62>/RTC_Get_ReadSecond_Operation_sys' */
  /* SignalConversion generated from: '<S126>/ReadSecond' */
  *ReadSecond = WorkTime_GetSeconds();

  /* End of Outputs for SubSystem: '<S62>/RTC_Get_ReadSecond_Operation_sys' */
}

/* Model step function */
void RTC_Get_ReadYear_Operation(uint16 *ReadYear)
{
  /* Outputs for Function Call SubSystem: '<S63>/RTC_Get_ReadYear_Operation_sys' */
  /* SignalConversion generated from: '<S127>/ReadYear' */
  *ReadYear = (uint16)(WorkTime_GetYear());

#ifdef VCU_Test_Code_LK
    tast_WorkTime_GetYear = *ReadYear;
#endif
  /* End of Outputs for SubSystem: '<S63>/RTC_Get_ReadYear_Operation_sys' */
}

/* Model initialize function */
void swc_GetInputInterface_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
/* Model step function */
void DiagcEvent_SetEvent(uint16 ID, UInt8_T EventStatus)
{
#ifdef BMS_TestMea_Code_LK  
  Test_DiagcEvent_SetEvent_ID          =          ID;
  Test_DiagcEvent_SetEvent_EventStatus = EventStatus;
#endif
  CP_SetEvent(ID,EventStatus);
}
/* Model step function */
void DiagcEvent_GetEvent(uint16 DTC_ID, UInt8_T *EventStatusByte)
{
  CP_GetEventStatus(DTC_ID,EventStatusByte);
}
/* Model step function */
Std_ReturnType Func_FiMFID1_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID1,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID2_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID2,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID3_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID3,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID4_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID4,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID5_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID5,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID6_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID6,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID7_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID7,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID8_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID8,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID9_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID9,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID10_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID10,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID11_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID11,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID12_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID12,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID13_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID13,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID14_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID14,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID15_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID15,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID16_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID16,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID17_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID17,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID18_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID18,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID19_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID19,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID20_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID20,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID21_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID21,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID22_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID22,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID23_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID23,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID24_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID24,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID25_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID25,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID26_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID26,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID27_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID27,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID28_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID28,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID29_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID29,Permission);
  *Permission = !(*Permission);
  return ret;
}
/* Model step function */
Std_ReturnType Func_FiMFID30_GetFunctionPermission(Boolean_T *Permission)
{
  Std_ReturnType ret = 0;
  ret = FiM_GetFunctionPermission(FID30,Permission);
  *Permission = !(*Permission);
  return ret;
}







/* Model step function */
void BSWIOSP_Get_Com_CCD_UpdataTime_Operation(uint32 *CCD_UpdataTime)
{
  /* Outputs for Function Call SubSystem: '<S7>/BSWIOSP_Get_Com_CCD_UpdataTime_Operation_sys' */
  /* SignalConversion generated from: '<S115>/CCD_UpdataTime' */
  *CCD_UpdataTime = 0U;

  /* End of Outputs for SubSystem: '<S7>/BSWIOSP_Get_Com_CCD_UpdataTime_Operation_sys' */
}

/* Model step function */
uint32 Ea_CCS_UpdataTime = 0;
void BSWIOSP_Get_Com_CCS_UpdataTime_Operation(uint32 *CCS_UpdataTime)
{
  if(Ea_CCS_UpdataTime >= 65535)
  {
    Ea_CCS_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x1812F456_Active == 1)
    {
      (Ea_CCS_UpdataTime)++;
    }
  }
  *CCS_UpdataTime = Ea_CCS_UpdataTime;
}

/* Model step function */
void BSWIOSP_Get_Com_CDC_UpdataTime_Operation(uint32 *CDC_UpdataTime)
{
  /* Outputs for Function Call SubSystem: '<S9>/BSWIOSP_Get_Com_CDC_UpdataTime_Operation_sys' */
  /* SignalConversion generated from: '<S117>/CDC_UpdataTime' */
  *CDC_UpdataTime = 0U;

  /* End of Outputs for SubSystem: '<S9>/BSWIOSP_Get_Com_CDC_UpdataTime_Operation_sys' */
}

/* Model step function */
uint32 Ea_CEM_UpdataTime = 0;
void BSWIOSP_Get_Com_CEM_UpdataTime_Operation(uint32 *CEM_UpdataTime)
{
  if(Ea_CEM_UpdataTime >= 65535)
  {
    Ea_CEM_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x81FF456_Active == 1)
    {
      (Ea_CEM_UpdataTime)++;
    }
  }
  *CEM_UpdataTime = Ea_CEM_UpdataTime;
}

/* Model step function */
uint32 Ea_CHM_UpdataTime = 0;
void BSWIOSP_Get_Com_CHM_UpdataTime_Operation(uint32 *CHM_UpdataTime)
{
  if(Ea_CHM_UpdataTime >= 65535)
  {
    Ea_CHM_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x1826F456_Active == 1)
    {
      (Ea_CHM_UpdataTime)++;
    }
  }
  *CHM_UpdataTime = Ea_CHM_UpdataTime;
}

/* Model step function */
void BSWIOSP_Get_Com_CMLP_UpdataTime_Operation(uint32 *CMLP_UpdataTime)
{
  /* Outputs for Function Call SubSystem: '<S12>/BSWIOSP_Get_Com_CMLP_UpdataTime_Operation_sys' */
  /* SignalConversion generated from: '<S120>/CMLP_UpdataTime' */
  *CMLP_UpdataTime = 0U;

  /* End of Outputs for SubSystem: '<S12>/BSWIOSP_Get_Com_CMLP_UpdataTime_Operation_sys' */
}
/* Model step function */
uint32 Ea_CML_UpdataTime = 0;
void BSWIOSP_Get_Com_CML_UpdataTime_Operation(uint32 *CML_UpdataTime)
{
  if(Ea_CML_UpdataTime >= 65535)
  {
    Ea_CML_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x1808F456_Active == 1)
    {
      (Ea_CML_UpdataTime)++;
    }
  }
  *CML_UpdataTime = Ea_CML_UpdataTime;
}

/* Model step function */
uint32 Ea_CRM_UpdataTime = 0;
void BSWIOSP_Get_Com_CRM_UpdataTime_Operation(uint32 *CRM_UpdataTime)
{
  if(Ea_CRM_UpdataTime >= 65535)
  {
    Ea_CRM_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x1801F456_Active == 1)
    {
      (Ea_CRM_UpdataTime)++;
    }
  }
  *CRM_UpdataTime = Ea_CRM_UpdataTime;
}

/* Model step function */
uint32 Ea_CRO_UpdataTime = 0;
void BSWIOSP_Get_Com_CRO_UpdataTime_Operation(uint32 *CRO_UpdataTime)
{
  if(Ea_CRO_UpdataTime >= 65535)
  {
    Ea_CRO_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x100AF456_Active == 1)
    {
      (Ea_CRO_UpdataTime)++;
    }
  }
  *CRO_UpdataTime = Ea_CRO_UpdataTime;
}

/* Model step function */
void BSWIOSP_Get_Com_CSDP_UpdataTime_Operation(uint32 *CSDP_UpdataTime)
{
  /* Outputs for Function Call SubSystem: '<S16>/BSWIOSP_Get_Com_CSDP_UpdataTime_Operation_sys' */
  /* SignalConversion generated from: '<S124>/CSDP_UpdataTime' */
  *CSDP_UpdataTime = 0U;

  /* End of Outputs for SubSystem: '<S16>/BSWIOSP_Get_Com_CSDP_UpdataTime_Operation_sys' */
}

/* Model step function */
uint32 Ea_CSD_UpdataTime = 0;
void BSWIOSP_Get_Com_CSD_UpdataTime_Operation(uint32 *CSD_UpdataTime)
{
  if(Ea_CSD_UpdataTime >= 65535)
  {
    Ea_CSD_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x181DF456_Active == 1)
    {
      (Ea_CSD_UpdataTime)++;
    }
  }
  *CSD_UpdataTime = Ea_CSD_UpdataTime;
}

/* Model step function */
uint32 Ea_CST_UpdataTime = 0;
void BSWIOSP_Get_Com_CST_UpdataTime_Operation(uint32 *CST_UpdataTime)
{
  if(Ea_CST_UpdataTime >= 65535)
  {
    Ea_CST_UpdataTime = 0U;
  }
  else
  {
    if(CANE_0x101AF456_Active == 1)
    {
      (Ea_CST_UpdataTime)++;
    }
  }
  *CST_UpdataTime = Ea_CST_UpdataTime;
}
/* Model step function */
void BSWIOSP_Get_Service0x14_Count_Operation(uint16 *Service0x14_Count)
{
  if(Dcm_SID0x14CountBufferAddress[0] < 0)
  {
    *Service0x14_Count = 0U;
  }
  else if(Dcm_SID0x14CountBufferAddress[0] > 65535)
  {
    *Service0x14_Count = 65535U;
  }
  else
  {
    *Service0x14_Count = Dcm_SID0x14CountBufferAddress[0];
  }
}
