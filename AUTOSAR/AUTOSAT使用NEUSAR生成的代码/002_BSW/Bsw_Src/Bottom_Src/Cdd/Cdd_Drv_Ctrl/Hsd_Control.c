/**
 * @file    Hsd_Lsd_Control.c
 * @brief   高低边驱动接口实现
 *
 * @note    本文件很好的实现了高低边驱动的封装，适用于所有项目
 *
 * @author  [dwyane tade]
 * @version 1.0.1
 * @date    2025-10-15
 *
 * @copyright Copyright (c) [2025] [天津易鼎丰]
 */
#include "Hsd_Control.h"
#include "Cdd_Hsd_Wsd7020af.h"
#include "IoHwAbs_PWM.h"
#include "IoHwAbs_DIO_prv.h"
#include "ErrorDiag_Swc.h"
#include "ErrorDiag_Cfg.h"
#include "ErrorHandler_ReactionCfg.h"
#include "ErrorHandler_Swc.h"

extern Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel);

struct dd_ctrl Hsd_valDioCtrl_Mp[DD_HSD_DIO_CHANNEL_MAX] = {
    [0] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_1,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS1_Ch_C,
    },
    [1] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_2,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS2_Ch_C,
    },
    [2] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_3,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS3_Ch_C,
    },
    [3] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_4,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS4_Ch_C,
    },   
    [4] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_5,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS5_Ch_C,
    },
    [5] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_6,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS6_Ch_C,
    },
    [6] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_7,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS7_Ch_C,
    },
    [7] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_8,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS8_Ch_C,
    },   
    [8] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_9,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS9_Ch_C,
    },
    [9] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_HS_10,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_HS10_Ch_C,
    },
};

/**
 * @name Cdd_Hsd_InitFunction
 * @brief 高边驱动初始化函数
 * @param none
 * @return none
 */
void Cdd_Hsd_InitFunction(void)
{
	Cdd_Hsd_WSD7020AF_InitFunction();
}

/**
 * @name Cdd_Hsd_DiagFunction
 * @brief 高边驱动诊断调度函数
 * @param none
 * @return none
 */
void Cdd_Hsd_DiagFunction(void)
{
    Cdd_Hsd_WSD7020AF_DiagFunctoin();
}

/**
 * @name Cdd_Hsd_ErrorDiag
 * @brief 高边驱动统一的诊断处理函数
 * @param Dd_valInfo HS通道/ADC的diag/ADC的cfb/errid等信息
 * @return none
 */
void Cdd_Hsd_ErrorDiag(dd_diaginfo* Dd_valInfo)
{
    uint16 Dc_valIOut_Lo = 0;
    uint16 Dc_valCFb_Lo = 0;
    uint16 Dc_valVDig_Lo = 0;
    struct dd_parameter* Dc_valParameter = (struct dd_parameter*)Dd_valInfo->parameter;

    if(DD_CTRL_IO_ON == Hsd_valDioCtrl_Mp[Dd_valInfo->drv_ch].ch_Level)
    {
        IoHwAbs_ADC_GetChannelRawValue(Dd_valInfo->adc_chcfb, &Dc_valCFb_Lo);
        Dc_valIOut_Lo = (uint16)DD_HSD_STG_GET_IOUT((float)Dc_valCFb_Lo, Dc_valParameter->r, Dc_valParameter->k);
        if((0xFFFF != Dd_valInfo->stg_errid) && (Dc_valIOut_Lo > Dc_valParameter->IoutThres))
            ErrorDiag_Send_ErrorStatus(Dd_valInfo->stg_errid, TRUE);
        else
            ErrorDiag_Send_ErrorStatus(Dd_valInfo->stg_errid, FALSE);
    }
    else if(DD_CTRL_IO_OFF == Hsd_valDioCtrl_Mp[Dd_valInfo->drv_ch].ch_Level)
    {
        IoHwAbs_ADC_GetChannelRawValue(Dd_valInfo->adc_chdiag, &Dc_valVDig_Lo);
		if((0xFFFF != Dd_valInfo->stb_errid) && (Dc_valVDig_Lo >= DD_HSD_STB_THRESH))
            ErrorDiag_Send_ErrorStatus(Dd_valInfo->stb_errid, TRUE);
		else
            ErrorDiag_Send_ErrorStatus(Dd_valInfo->stb_errid, FALSE);

        if((0xFFFF != Dd_valInfo->opl_errid) &&\
            ((Dc_valVDig_Lo >= DD_HSD_OPL_THRESH_Min) && (Dc_valVDig_Lo < DD_HSD_OPL_THRESH_Max)))
            ErrorDiag_Send_ErrorStatus(Dd_valInfo->opl_errid, TRUE);
        else
            ErrorDiag_Send_ErrorStatus(Dd_valInfo->opl_errid, FALSE);
    }
}
volatile boolean AsynHsdCtrlFlag = TRUE;
void Cdd_Hsd_CtrlMainFunction(void)
{
    volatile uint8 Hsd_Chindex = 0;
    volatile uint8 Hsd_ChDiagInhibitFlag = 0;
    for(Hsd_Chindex = 0; Hsd_Chindex < DD_HSD_DIO_CHANNEL_MAX; Hsd_Chindex++)
    {
        Hsd_ChDiagInhibitFlag = EH_GetOutputDisFlag(Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_DiagOutputDisCh);

        if(1 == Hsd_ChDiagInhibitFlag)
        {
            Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level = 0;
            IoHwAbs_DIO_SetChannelValue(Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_id, Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level);
            Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level_Last = 0;
        }
        else
        {
            if(AsynHsdCtrlFlag == TRUE)
            {
                if(Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level != Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level_Last)
                {
                    IoHwAbs_DIO_SetChannelValue(Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_id, Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level);
                    Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level_Last = Hsd_valDioCtrl_Mp[Hsd_Chindex].ch_Level;
                }
            }
        }
        
    }
}



void Cdd_Hsd_10msMainFunction(void)
{
    Cdd_Hsd_DiagFunction();

    Cdd_Hsd_CtrlMainFunction();
}
