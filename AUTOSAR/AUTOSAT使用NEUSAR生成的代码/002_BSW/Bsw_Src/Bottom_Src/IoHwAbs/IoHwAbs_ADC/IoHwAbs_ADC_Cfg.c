/*** create info *******************************************
*@ filename : IoHwAbs_ADC_Cfg.c
*@ Author : wk
*@ date :2025-02-12
*@ Description :ADC相关配置
/*** modify info *******************************************
*@ version :2.0
*@ Modifier : wk
*@ date :2026-06-03
*@ Modification Description :
根据最新Adc_Cfg.c和Adc_Cfg.h同步更新全部Group通道配置
************************************************************/

/********************************************** Include **********************************************/
#include "IoHwAbs_ADC_Cfg.h"
#include "IoHwAbs_ADC.h"
#include "IoHwAbs_ADC_Prv.h"
#include "Adc.h"
#include "Adc_Cfg.h"
/******************************************* Global Varibles ******************************************/

const Adc_CfgParams_TDSTR Adc_CfgParams_STR[] =
{
    /* ========================== Group 0 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN1, ADC_GROUP_AdcGroup_0,  GROUP_0_MCU_AN_TEMP_IGBT_IN1,  IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN2, ADC_GROUP_AdcGroup_0,  GROUP_0_MCU_AN_TEMP_IGBT_IN2,  IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS1_DIAG,       ADC_GROUP_AdcGroup_0,  GROUP_0_MCU_D_HS1_DIAG,        IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_VDD5REF11,            ADC_GROUP_AdcGroup_0,  GROUP_0_VDD5REF11,             IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 1 (2 channels) ========================== */



    /* ========================== Group 2 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN3, ADC_GROUP_AdcGroup_2,  GROUP_2_MCU_AN_TEMP_IGBT_IN3,  IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS5_DIAG,       ADC_GROUP_AdcGroup_2,  GROUP_2_MCU_D_HS5_DIAG,        IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS9_DIAG,       ADC_GROUP_AdcGroup_2,  GROUP_2_MCU_D_HS9_DIAG,        IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS10_DIAG,      ADC_GROUP_AdcGroup_2,  GROUP_2_MCU_D_HS10_DIAG,       IoHwAbs_ADC_ChannelFormula_Hs},

    /* ========================== Group 3 (2 channels) ========================== */

    /* ========================== Group 4 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_D_HS7_DIAG,       ADC_GROUP_AdcGroup_4,  GROUP_4_MCU_D_HS7_DIAG,        IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS8_DIAG,       ADC_GROUP_AdcGroup_4,  GROUP_4_MCU_D_HS8_DIAG,        IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_AN_9015_ERRQ,         ADC_GROUP_AdcGroup_4,  GROUP_4_AN_9015_ERRQ,          IoHwAbs_ADC_ChannelFormula_Ls},
    {IOHWABS_ADC_CHANNEL_AN_OBC_Mic,           ADC_GROUP_AdcGroup_4,  GROUP_4_AN_OBC_Mic,            IoHwAbs_ADC_ChannelFormula_BAT},

    /* ========================== Group 5 (2 channels) ========================== */

    /* ========================== Group 6 (2 channels) ========================== */



    /* ========================== Group 7 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_AN_OBC_ON_Mic,        ADC_GROUP_AdcGroup_7,  GROUP_7_AN_OBC_ON_Mic,         IoHwAbs_ADC_ChannelFormula_BAT},
    {IOHWABS_ADC_CHANNEL_AN_CAN_WK_Mic,        ADC_GROUP_AdcGroup_7,  GROUP_7_AN_CAN_WK_Mic,         IoHwAbs_ADC_ChannelFormula_CAN},

    /* ========================== Group 8 (2 channels) ========================== */


    /* ========================== Group 9 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_IN_AN1,               ADC_GROUP_AdcGroup_9,  GROUP_9_IN_AN1,                IoHwAbs_ADC_ChannelFormula_BAT},
    {IOHWABS_ADC_CHANNEL_VDD5REF10,            ADC_GROUP_AdcGroup_9,  GROUP_9_VDD5REF10,             IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 10 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_AN_5Vsensor2,         ADC_GROUP_AdcGroup_10, GROUP_10_AN_5Vsensor2,        IoHwAbs_ADC_ChannelFormula_5VSensor},
    {IOHWABS_ADC_CHANNEL_VDD5REF7,             ADC_GROUP_AdcGroup_10, GROUP_10_VDD5REF7,            IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN2,               ADC_GROUP_AdcGroup_10, GROUP_10_IN_AN2,              IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN4,               ADC_GROUP_AdcGroup_10, GROUP_10_IN_AN4,              IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 11 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic,     ADC_GROUP_AdcGroup_11, GROUP_11_AN_DC_APlus1_Mic,    IoHwAbs_ADC_ChannelFormula_BAT},
    {IOHWABS_ADC_CHANNEL_AN_CAN_5V,            ADC_GROUP_AdcGroup_11, GROUP_11_AN_CAN_5V,           IoHwAbs_ADC_ChannelFormula_5VSensor},
    {IOHWABS_ADC_CHANNEL_AN_Driver_5V,         ADC_GROUP_AdcGroup_11, GROUP_11_AN_Driver_5V,        IoHwAbs_ADC_ChannelFormula_5VSensor},
    {IOHWABS_ADC_CHANNEL_IN_AN11,              ADC_GROUP_AdcGroup_11, GROUP_11_IN_AN11,             IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 12 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_AN_Motor_TEMP_N,  ADC_GROUP_AdcGroup_12, GROUP_12_MCU_AN_Motor_TEMP_N, IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_AN_Motor_TEMP_P,  ADC_GROUP_AdcGroup_12, GROUP_12_MCU_AN_Motor_TEMP_P, IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 13 (2 channels) ========================== */

    /* ========================== Group 14 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_LS_9_DIAG,        ADC_GROUP_AdcGroup_14, GROUP_14_MCU_LS_9_DIAG,       IoHwAbs_ADC_ChannelFormula_Ls},
    {IOHWABS_ADC_CHANNEL_MCU_LS_11_DIAG,       ADC_GROUP_AdcGroup_14, GROUP_14_MCU_LS_11_DIAG,      IoHwAbs_ADC_ChannelFormula_Ls},
    {IOHWABS_ADC_CHANNEL_MCU_LS_12_DIAG,       ADC_GROUP_AdcGroup_14, GROUP_14_MCU_LS_12_DIAG,      IoHwAbs_ADC_ChannelFormula_Ls},
    {IOHWABS_ADC_CHANNEL_AN_1V8,               ADC_GROUP_AdcGroup_14, GROUP_14_AN_1V8,              IoHwAbs_ADC_ChannelFormula_Imu},

    /* ========================== Group 15 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_AN_KEY_Mic,           ADC_GROUP_AdcGroup_15, GROUP_15_AN_KEY_Mic,          IoHwAbs_ADC_ChannelFormula_BAT},
    {IOHWABS_ADC_CHANNEL_AN_DC_APlus2_Mic,     ADC_GROUP_AdcGroup_15, GROUP_15_AN_DC_APlus2_Mic,    IoHwAbs_ADC_ChannelFormula_BAT},

    /* ========================== Group 16 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_D_HS3_DIAG,       ADC_GROUP_AdcGroup_16, GROUP_16_MCU_D_HS3_DIAG,      IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS4_DIAG,       ADC_GROUP_AdcGroup_16, GROUP_16_MCU_D_HS4_DIAG,      IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS6_DIAG,       ADC_GROUP_AdcGroup_16, GROUP_16_MCU_D_HS6_DIAG,      IoHwAbs_ADC_ChannelFormula_Hs},
    {IOHWABS_ADC_CHANNEL_MCU_LS_10_DIAG,       ADC_GROUP_AdcGroup_16, GROUP_16_MCU_LS_10_DIAG,      IoHwAbs_ADC_ChannelFormula_Ls},

    /* ========================== Group 17 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_IN_AN7,               ADC_GROUP_AdcGroup_17, GROUP_17_IN_AN7,              IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN12,              ADC_GROUP_AdcGroup_17, GROUP_17_IN_AN12,             IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 18 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_IN_AN3,               ADC_GROUP_AdcGroup_18, GROUP_18_IN_AN3,              IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN5,               ADC_GROUP_AdcGroup_18, GROUP_18_IN_AN5,              IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN6,               ADC_GROUP_AdcGroup_18, GROUP_18_IN_AN6,              IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN8,               ADC_GROUP_AdcGroup_18, GROUP_18_IN_AN8,              IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 19 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_IN_AN10,              ADC_GROUP_AdcGroup_19, GROUP_19_IN_AN10,             IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_IN_AN13,              ADC_GROUP_AdcGroup_19, GROUP_19_IN_AN13,             IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_AN_HS1and7_CFB,   ADC_GROUP_AdcGroup_19, GROUP_19_MCU_AN_HS1and7_CFB,  IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_VDD5REF9,             ADC_GROUP_AdcGroup_19, GROUP_19_VDD5REF9,            IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 20 (4 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_AN_HS2and8_CFB,   ADC_GROUP_AdcGroup_20, GROUP_20_MCU_AN_HS2and8_CFB,  IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_AN_HS3and9_CFB,   ADC_GROUP_AdcGroup_20, GROUP_20_MCU_AN_HS3and9_CFB,  IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_AN_HS4and10_CFB,  ADC_GROUP_AdcGroup_20, GROUP_20_MCU_AN_HS4and10_CFB, IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_AN_HS5and6_CFB,   ADC_GROUP_AdcGroup_20, GROUP_20_MCU_AN_HS5and6_CFB,  IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 21 (6 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_IN_AN14,              ADC_GROUP_AdcGroup_21, GROUP_21_IN_AN14,             IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_VDD5REF8,             ADC_GROUP_AdcGroup_21, GROUP_21_VDD5REF8,            IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_AN_HV_Driver_5V,      ADC_GROUP_AdcGroup_21, GROUP_21_AN_HV_Driver_5V,     IoHwAbs_ADC_ChannelFormula_5VSensor},
    {IOHWABS_ADC_CHANNEL_AN_5Vsensor1,         ADC_GROUP_AdcGroup_21, GROUP_21_AN_5Vsensor1,        IoHwAbs_ADC_ChannelFormula_5VSensor},
    {IOHWABS_ADC_CHANNEL_AN_12_RES_Mic,        ADC_GROUP_AdcGroup_21, GROUP_21_AN_12_RES_Mic,       IoHwAbs_ADC_ChannelFormula_BAT},
    {IOHWABS_ADC_CHANNEL_AN_UBD_Mic,           ADC_GROUP_AdcGroup_21, GROUP_21_AN_UBD_Mic,          IoHwAbs_ADC_ChannelFormula_BAT},

    /* ========================== Group 22 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_AN_HV_DC2,        ADC_GROUP_AdcGroup_22, GROUP_22_MCU_AN_HV_DC2,       IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_MCU_D_HS2_DIAG,       ADC_GROUP_AdcGroup_22, GROUP_22_MCU_D_HS2_DIAG,      IoHwAbs_ADC_ChannelFormula_Hs},

    /* ========================== Group 23 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_AN_Temp_MCU,          ADC_GROUP_AdcGroup_23, GROUP_23_AN_Temp_MCU,         IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_AN_UBR_Mic,           ADC_GROUP_AdcGroup_23, GROUP_23_AN_UBR_Mic,          IoHwAbs_ADC_ChannelFormula_BAT},

    /* ========================== Group 24 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_IN_AN9,               ADC_GROUP_AdcGroup_24, GROUP_24_IN_AN9,              IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_AN_Temp_SBC,          ADC_GROUP_AdcGroup_24, GROUP_24_AN_Temp_SBC,         IoHwAbs_ADC_ChannelFormula_IN_ANx},

    /* ========================== Group 25 (2 channels) ========================== */
    {IOHWABS_ADC_CHANNEL_MCU_AN_HV_DC1,        ADC_GROUP_AdcGroup_25, GROUP_25_MCU_AN_HV_DC1,       IoHwAbs_ADC_ChannelFormula_IN_ANx},
    {IOHWABS_ADC_CHANNEL_AN_F_V_PRE,           ADC_GROUP_AdcGroup_25, GROUP_25_AN_F_V_PRE,          IoHwAbs_ADC_ChannelFormula_5VSensor},


};





Adc_ValueGroupType Adc_valResultBufferGroup0_ARRY[ADC_GROUP_0_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup1_ARRY[ADC_GROUP_1_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup2_ARRY[ADC_GROUP_2_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup3_ARRY[ADC_GROUP_3_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup4_ARRY[ADC_GROUP_4_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup5_ARRY[ADC_GROUP_5_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup6_ARRY[ADC_GROUP_6_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup7_ARRY[ADC_GROUP_7_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup8_ARRY[ADC_GROUP_8_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup9_ARRY[ADC_GROUP_9_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup10_ARRY[ADC_GROUP_10_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup11_ARRY[ADC_GROUP_11_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup12_ARRY[ADC_GROUP_12_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup13_ARRY[ADC_GROUP_13_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup14_ARRY[ADC_GROUP_14_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup15_ARRY[ADC_GROUP_15_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup16_ARRY[ADC_GROUP_16_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup17_ARRY[ADC_GROUP_17_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup18_ARRY[ADC_GROUP_18_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup19_ARRY[ADC_GROUP_19_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup20_ARRY[ADC_GROUP_20_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup21_ARRY[ADC_GROUP_21_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup22_ARRY[ADC_GROUP_22_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup23_ARRY[ADC_GROUP_23_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup24_ARRY[ADC_GROUP_24_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup25_ARRY[ADC_GROUP_25_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup26_ARRY[Group26_BufferSize] = {0};
Adc_ValueGroupType Adc_valResultBufferGroup27_ARRY[Group27_BufferSize] = {0};



Adc_ValueGroupType Adc_valDMAReadBufferGroup0_ARRY[ADC_GROUP_0_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup1_ARRY[ADC_GROUP_1_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup2_ARRY[ADC_GROUP_2_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup3_ARRY[ADC_GROUP_3_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup4_ARRY[ADC_GROUP_4_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup5_ARRY[ADC_GROUP_5_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup6_ARRY[ADC_GROUP_6_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup7_ARRY[ADC_GROUP_7_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup8_ARRY[ADC_GROUP_8_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup9_ARRY[ADC_GROUP_9_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup10_ARRY[ADC_GROUP_10_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup11_ARRY[ADC_GROUP_11_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup12_ARRY[ADC_GROUP_12_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup13_ARRY[ADC_GROUP_13_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup14_ARRY[ADC_GROUP_14_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup15_ARRY[ADC_GROUP_15_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup16_ARRY[ADC_GROUP_16_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup17_ARRY[ADC_GROUP_17_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup18_ARRY[ADC_GROUP_18_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup19_ARRY[ADC_GROUP_19_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup20_ARRY[ADC_GROUP_20_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup21_ARRY[ADC_GROUP_21_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup22_ARRY[ADC_GROUP_22_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup23_ARRY[ADC_GROUP_23_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup24_ARRY[ADC_GROUP_24_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup25_ARRY[ADC_GROUP_25_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup26_ARRY[ADC_GROUP_26_CHANNEL_NUM] = {0};
Adc_ValueGroupType Adc_valDMAReadBufferGroup27_ARRY[ADC_GROUP_27_CHANNEL_NUM] = {0};



Adc_ValueGroupType *Adc_ResultBufferptr_ARRY[ADC_CONFIG_GROUPS] =
    {
        Adc_valResultBufferGroup0_ARRY,
        Adc_valResultBufferGroup1_ARRY,
        Adc_valResultBufferGroup2_ARRY,
        Adc_valResultBufferGroup3_ARRY,
        Adc_valResultBufferGroup4_ARRY,
        Adc_valResultBufferGroup5_ARRY,
        Adc_valResultBufferGroup6_ARRY,
        Adc_valResultBufferGroup7_ARRY,
        Adc_valResultBufferGroup8_ARRY,
        Adc_valResultBufferGroup9_ARRY,
        Adc_valResultBufferGroup10_ARRY,
        Adc_valResultBufferGroup11_ARRY,
        Adc_valResultBufferGroup12_ARRY,
        Adc_valResultBufferGroup13_ARRY,
        Adc_valResultBufferGroup14_ARRY,
        Adc_valResultBufferGroup15_ARRY,
        Adc_valResultBufferGroup16_ARRY,
        Adc_valResultBufferGroup17_ARRY,
        Adc_valResultBufferGroup18_ARRY,
        Adc_valResultBufferGroup19_ARRY,
        Adc_valResultBufferGroup20_ARRY,
        Adc_valResultBufferGroup21_ARRY,
        Adc_valResultBufferGroup22_ARRY,
        Adc_valResultBufferGroup23_ARRY,
        Adc_valResultBufferGroup24_ARRY,
        Adc_valResultBufferGroup25_ARRY,
        Adc_valResultBufferGroup26_ARRY,
        Adc_valResultBufferGroup27_ARRY
};

Adc_ValueGroupType *Adc_DMAReadBufferptr_ARRY[ADC_CONFIG_GROUPS] =
    {
        Adc_valDMAReadBufferGroup0_ARRY,
        Adc_valDMAReadBufferGroup1_ARRY,
        Adc_valDMAReadBufferGroup2_ARRY,
        Adc_valDMAReadBufferGroup3_ARRY,
        Adc_valDMAReadBufferGroup4_ARRY,
        Adc_valDMAReadBufferGroup5_ARRY,
        Adc_valDMAReadBufferGroup6_ARRY,
        Adc_valDMAReadBufferGroup7_ARRY,
        Adc_valDMAReadBufferGroup8_ARRY,
        Adc_valDMAReadBufferGroup9_ARRY,
        Adc_valDMAReadBufferGroup10_ARRY,
        Adc_valDMAReadBufferGroup11_ARRY,
        Adc_valDMAReadBufferGroup12_ARRY,
        Adc_valDMAReadBufferGroup13_ARRY,
        Adc_valDMAReadBufferGroup14_ARRY,
        Adc_valDMAReadBufferGroup15_ARRY,
        Adc_valDMAReadBufferGroup16_ARRY,
        Adc_valDMAReadBufferGroup17_ARRY,
        Adc_valDMAReadBufferGroup18_ARRY,
        Adc_valDMAReadBufferGroup19_ARRY,
        Adc_valDMAReadBufferGroup20_ARRY,
        Adc_valDMAReadBufferGroup21_ARRY,
        Adc_valDMAReadBufferGroup22_ARRY,
        Adc_valDMAReadBufferGroup23_ARRY,
        Adc_valDMAReadBufferGroup24_ARRY,
        Adc_valDMAReadBufferGroup25_ARRY,
        Adc_valDMAReadBufferGroup26_ARRY,
        Adc_valDMAReadBufferGroup27_ARRY
};

const eMIOS_GlobalParamType eMIOS_GlobalConfig_STR =
    {
        .LowPowerModeEn = FALSE,                                 /*!< Low power mode or normal mode */
        .FreezeInDebugMode = FALSE,                               /*!< If true, all channel in eMIOS group can enter debug mode */
        .GlobalPreClkDiv = 10U,                                  /*!< Select the clock divider value for the global prescaler in range(1-256) */
        .ExternalTimeBaseSel = EMIOS_ETB_DIS_COUNTER_BUSA_TO_UC, /*!< Enable or disable external timebase */
        .ServerTimeSlotSel = 0U                                  /*!< Select the address of a specific STAC server to which the STAC is assigned */
};

const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_ChanConfig_STR =
   {
      .mode = EMIOS_UC_MODE_PWM_OPWMCB_LEAD,        /*!< Sub-mode selected */
      .divid = 1U,                             /*!< Internal prescaler value */
      .active = (uint8_t)EMIOS_POSITIVE_PULSE, /*!< Output active value, active low or high level */
      .period = 0UL,                      /*!< Period count */
      .dutyCycle = 0UL,                    /*!< Duty cycle count */
      .timebase = EMIOS_COUNTER_BUS_A,  /*!< Counter bus selected */
      .idealDutyCycle = 52000UL,                   /*!< Ideal duty cycle value using to compare with the selected time base */
      .deadTime = 0UL                          /*!< The dead time value and is compared against the internal counter */
};

const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH17_ChanConfig =
{
   .mode = EMIOS_UC_MODE_PWM_OPWMCB_LEAD,        /*!< Sub-mode selected */
   .divid = 1U,                             /*!< Internal prescaler value */
   .active = (uint8_t)EMIOS_POSITIVE_PULSE, /*!< Output active value, active low or high level */
   .period = 0UL,                      /*!< Period count */
   .dutyCycle = 0UL,                    /*!< Duty cycle count */
   .timebase = EMIOS_COUNTER_BUS_A,  /*!< Counter bus selected */
   .idealDutyCycle = 35000UL,                   /*!< Ideal duty cycle value using to compare with the selected time base */
   .deadTime = 10UL                          /*!< The dead time value and is compared against the internal counter */
};

const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH18_ChanConfig =
{
   .mode = EMIOS_UC_MODE_PWM_OPWMCB_LEAD,        /*!< Sub-mode selected */
   .divid = 1U,                             /*!< Internal prescaler value */
   .active = (uint8_t)EMIOS_POSITIVE_PULSE, /*!< Output active value, active low or high level */
   .period = 0UL,                      /*!< Period count */
   .dutyCycle = 0UL,                    /*!< Duty cycle count */
   .timebase = EMIOS_COUNTER_BUS_A,  /*!< Counter bus selected */
   .idealDutyCycle = 45000UL,                   /*!< Ideal duty cycle value using to compare with the selected time base */
   .deadTime = 10UL                          /*!< The dead time value and is compared against the internal counter */
};

const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH19_ChanConfig =
{
   .mode = EMIOS_UC_MODE_PWM_OPWMCB_LEAD,        /*!< Sub-mode selected */
   .divid = 1U,                             /*!< Internal prescaler value */
   .active = (uint8_t)EMIOS_POSITIVE_PULSE, /*!< Output active value, active low or high level */
   .period = 0UL,                      /*!< Period count */
   .dutyCycle = 0UL,                    /*!< Duty cycle count */
   .timebase = EMIOS_COUNTER_BUS_A,  /*!< Counter bus selected */
   .idealDutyCycle = 62000UL,                   /*!< Ideal duty cycle value using to compare with the selected time base */
   .deadTime = 10UL                          /*!< The dead time value and is compared against the internal counter */
};

const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH20_ChanConfig =
{
   .mode = EMIOS_UC_MODE_PWM_OPWMCB_LEAD,        /*!< Sub-mode selected */
   .divid = 1U,                             /*!< Internal prescaler value */
   .active = (uint8_t)EMIOS_POSITIVE_PULSE, /*!< Output active value, active low or high level */
   .period = 0UL,                      /*!< Period count */
   .dutyCycle = 0UL,                    /*!< Duty cycle count */
   .timebase = EMIOS_COUNTER_BUS_A,  /*!< Counter bus selected */
   .idealDutyCycle = 28000UL,                   /*!< Ideal duty cycle value using to compare with the selected time base */
   .deadTime = 10UL                          /*!< The dead time value and is compared against the internal counter */
};

const eMIOS_PWM_ParamType eMIOS_PWM_OPWFMB_CH21_ChanConfig =
{
   .mode = EMIOS_UC_MODE_PWM_OPWMCB_LEAD,        /*!< Sub-mode selected */
   .divid = 1U,                             /*!< Internal prescaler value */
   .active = (uint8_t)EMIOS_POSITIVE_PULSE, /*!< Output active value, active low or high level */
   .period = 0UL,                      /*!< Period count */
   .dutyCycle = 0UL,                    /*!< Duty cycle count */
   .timebase = EMIOS_COUNTER_BUS_A,  /*!< Counter bus selected */
   .idealDutyCycle = 75000UL,                   /*!< Ideal duty cycle value using to compare with the selected time base */
   .deadTime = 10UL                          /*!< The dead time value and is compared against the internal counter */
};
