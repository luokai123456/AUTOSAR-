/**
 * @file    WSD7020AF.c
 * @brief   WSD7020AF 双通道高边驱动芯片驱动实现
 *
 * @note    WSD7020AF 是一款双通道高边驱动芯片，适用于汽车应用中的继电器、保险丝和分立器件
 *          本文件实现了该芯片的驱动诊断
 *
 * @author  [dwyane tade]
 * @version 1.0.1
 * @date    2025-10-15
 * 
 * @version 1.0.2
 * @date    2025-11-27
 * @brief   修正诊断通道切换的错误/修改过流阈值/修改魔数
 * 
 * @copyright Copyright (c) [2025] [天津易鼎丰]
 */

#include "Cdd_Hsd_Wsd7020af.h"
#include "Drv_Types.h"
#include "ErrorDiag_Cfg.h"

#define HSD_CHANNEL_MAX         10

static uint8 Hsd_valWstdSel_Mp = 0;
static uint8 Hsd_valWstdCurrentDelay_Mp[HSD_CHANNEL_MAX] = {0};
static uint8 Hsd_valWstdDiagStatus_Mp[HSD_CHANNEL_MAX]  = {WSD7020AF_SWITCH_CH};
static struct dd_parameter Hsd_valWstdParameter_Mp = {
    WSD7020AF_STG_R, 
    WSD7020AF_STG_K,
    WSD7020AF_STG_THRESHOLD
};

static uint8 Hsd_ValWsdDiagChSel_Mp[] = {
    WSD7020AF_CHIP1_SEL_DSEL,
    WSD7020AF_CHIP2_SEL_DSEL,
    WSD7020AF_CHIP3_SEL_DSEL,
    WSD7020AF_CHIP4_SEL_DSEL,
    WSD7020AF_CHIP5_SEL_DSEL,
};

const dd_diaginfo Hsd_ValWstdHsDiagInfo_Mp[] = {
    {6, WSD7020AF_CHIP1_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS1and7_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS7_DIAG,     FALSE   ,   WSD7020AF_ERRORID_WSTD6080_HS7_STG, WSD7020AF_ERRORID_WSTD6080_HS7_STB, WSD7020AF_ERRORID_WSTD6080_HS7_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {0, WSD7020AF_CHIP1_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS1and7_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS1_DIAG,     TRUE    ,   WSD7020AF_ERRORID_WSTD6080_HS1_STG, WSD7020AF_ERRORID_WSTD6080_HS1_STB, WSD7020AF_ERRORID_WSTD6080_HS1_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {7, WSD7020AF_CHIP2_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS2and8_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS8_DIAG,     FALSE   ,   WSD7020AF_ERRORID_WSTD6080_HS8_STG, WSD7020AF_ERRORID_WSTD6080_HS8_STB, WSD7020AF_ERRORID_WSTD6080_HS8_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {1, WSD7020AF_CHIP2_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS2and8_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS2_DIAG,     TRUE    ,   WSD7020AF_ERRORID_WSTD6080_HS2_STG, WSD7020AF_ERRORID_WSTD6080_HS2_STB, WSD7020AF_ERRORID_WSTD6080_HS2_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {8, WSD7020AF_CHIP3_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS3and9_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS9_DIAG,     FALSE   ,   WSD7020AF_ERRORID_WSTD6080_HS9_STG, WSD7020AF_ERRORID_WSTD6080_HS9_STB, WSD7020AF_ERRORID_WSTD6080_HS9_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {2, WSD7020AF_CHIP3_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS3and9_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS3_DIAG,     TRUE    ,   WSD7020AF_ERRORID_WSTD6080_HS3_STG, WSD7020AF_ERRORID_WSTD6080_HS3_STB, WSD7020AF_ERRORID_WSTD6080_HS3_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {9, WSD7020AF_CHIP4_SEL_DSEL,IOHWABS_ADC_CHANNEL_MCU_AN_HS4and10_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS10_DIAG,   FALSE   ,   WSD7020AF_ERRORID_WSTD6080_HS10_STG, WSD7020AF_ERRORID_WSTD6080_HS10_STB, WSD7020AF_ERRORID_WSTD6080_HS10_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {3, WSD7020AF_CHIP4_SEL_DSEL,IOHWABS_ADC_CHANNEL_MCU_AN_HS4and10_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS4_DIAG,    TRUE    ,   WSD7020AF_ERRORID_WSTD6080_HS4_STG, WSD7020AF_ERRORID_WSTD6080_HS4_STB, WSD7020AF_ERRORID_WSTD6080_HS4_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {4, WSD7020AF_CHIP5_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS5and6_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS5_DIAG,     FALSE   ,   WSD7020AF_ERRORID_WSTD6080_HS5_STG, WSD7020AF_ERRORID_WSTD6080_HS5_STB, WSD7020AF_ERRORID_WSTD6080_HS5_OPL, (void*)&Hsd_valWstdParameter_Mp},
    {5, WSD7020AF_CHIP5_SEL_DSEL, IOHWABS_ADC_CHANNEL_MCU_AN_HS5and6_CFB, IOHWABS_ADC_CHANNEL_MCU_D_HS6_DIAG,     TRUE    ,   WSD7020AF_ERRORID_WSTD6080_HS6_STG, WSD7020AF_ERRORID_WSTD6080_HS6_STB, WSD7020AF_ERRORID_WSTD6080_HS6_OPL, (void*)&Hsd_valWstdParameter_Mp},
};
/**
 * name: Cdd_Hsd_WSD7020AF_InitFunction
 * parameter[In]: none
 * parameter[Out]: None
 * 返回值: Std_ReturnType
 * 描述：WSD7020AF初始化函数，打开驱动芯片，并默认选择诊断通道0
 */
void Cdd_Hsd_WSD7020AF_InitFunction(void)
{
    /* Set Pin SeEn High */
    // IoHwAbs_DIO_SetChannelValue(IOHWABS_DIOCHANNEL_MCU_D_HS1and2_SEn, TRUE);
    /* Set Pin DSEL Low */
    volatile uint8 Chip_index = 0;
    for(Chip_index = 0; Chip_index < WSD7020AF_CHIP_NUM; Chip_index++)
    {
        IoHwAbs_DIO_SetChannelValue(Hsd_ValWsdDiagChSel_Mp[Chip_index], FALSE);
    }
}


/**
 * name: Cdd_Hsd_WSD7020AF_DiagFunctoin
 * parameter[In]: none
 * parameter[Out]: None
 * 返回值: Std_ReturnType
 * 描述: 
 *      WSD7020AF诊断函数
 *      Hsd_valDioCtrl_Mp[0]: 0指高边0
 *      Hsd_valDioCtrl_Mp[1]: 1指高边1
*       Hsd_valDioCtrl_Mp[2]: 2指高边2
 *      Hsd_valDioCtrl_Mp[3]: 3指高边3
 *      Hsd_valDioCtrl_Mp[4]: 4指高边4
 *      Hsd_valDioCtrl_Mp[5]: 5指高边5
 *      Hsd_valDioCtrl_Mp[6]: 6指高边6
 *      Hsd_valDioCtrl_Mp[7]: 7指高边7
 *      Hsd_valDioCtrl_Mp[8]: 8指高边8
 *      Hsd_valDioCtrl_Mp[9]: 9指高边9
 * 
 */
void Cdd_Hsd_WSD7020AF_DiagFunctoin(void)
{
    dd_diaginfo Wstd_valInfo_Lo = {0};
    uint8 channel;
    uint8 i;

    for(i = 0;i < 5;i++) {
        channel = 2 * i + Hsd_valWstdSel_Mp;
        Wstd_valInfo_Lo = Hsd_ValWstdHsDiagInfo_Mp[channel];
        switch (Hsd_valWstdDiagStatus_Mp[channel])
        {
        case WSD7020AF_SWITCH_CH:
            IoHwAbs_DIO_SetChannelValue(Wstd_valInfo_Lo.dio_dsel, Wstd_valInfo_Lo.dio_chsel);
            Hsd_valWstdCurrentDelay_Mp[channel]++;
            if(Hsd_valWstdCurrentDelay_Mp[channel] >= WSD7020AF_DELAY)
            {
                Hsd_valWstdDiagStatus_Mp[channel] = WSD7020AF_DIAG_CH;
                Hsd_valWstdCurrentDelay_Mp[channel] = 0;
            }
            break;
        case WSD7020AF_DIAG_CH:
            Cdd_Hsd_ErrorDiag(&Wstd_valInfo_Lo);
            Hsd_valWstdDiagStatus_Mp[channel] = WSD7020AF_SWITCH_CH;
            if(4 == i)
                Hsd_valWstdSel_Mp = 1 - Hsd_valWstdSel_Mp;
            break;
        default:
            break;
        }
    }
}


