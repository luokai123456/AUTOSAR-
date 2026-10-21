/**
 * @file    Lsd_Control.c
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
#include "Lsd_Control.h"
#include "IoHwAbs_PWM.h"
#include "Cdd_Lsd_HELS121D_prv.h"
#include "ErrorHandler_ReactionCfg.h"
#include "ErrorHandler_Swc.h"

extern Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel);

struct dd_ctrl Lamp_valDioCtrl_Mp[DD_LSD_LAMP_CHANNEL_MAX] = {
    [0] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON7,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = 0,
    },
    [1] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON8,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = 0,
    },
    [2] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON9,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = 0,
    }, 
};

struct dd_ctrl Lsd_valDioCtrl_Mp[DD_LSD_DIO_CHANNEL_MAX] = {
    [0] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_LS_4,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_LS1_Ch_C,
    },
    [1] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_LS_2,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_LS2_Ch_C,
    },
    [2] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_LS_3,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_LS3_Ch_C,
    },
    [3] = {
        .ch_id = IOHWABS_DIOCHANNEL_MCU_D_LS_1,
        .ch_Level = 0,
        .ch_Level_Last = 0,
        .ch_DiagOutputDisCh = EH_LS4_Ch_C,
    },
};

struct dd_PwmCtrl Lsd_valPwmCtrl_Mp[DD_LSD_PWM_CHANNEL_MAX] = {
    [0] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON1,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [1] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON2,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [2] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON3,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [3] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON4,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },   
    [4] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON5,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [5] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON6,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [6] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON10,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [7] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_VrefPhase_OCP_N,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },   
    [8] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_VrefPhase_OCP_P,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    },
    [9] = {
        .ch_Pwmstat = 0,
        .ch_Pwmid = IoHwAbs_PWM_MCU_Vref_VDC,
        .ch_Frequency = 0,
        .ch_DutyCycle = 0,
    }, 
    [10] = {
    .ch_Pwmstat = 0,
    .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON7,
    .ch_Frequency = 0,
    .ch_DutyCycle = 0,
    }, 
    [11] = {
    .ch_Pwmstat = 0,
    .ch_Pwmid = IoHwAbs_PWM_MCU_PWMOUT_CON11,
    .ch_Frequency = 0,
    .ch_DutyCycle = 0,
    }, 
};


/**
 * @name Cdd_Lsd_DiagFunction
 * @brief 低边驱动诊断调度函数
 * @param none
 * @return none
 */
void Cdd_Lsd_DiagFunction(void)
{
    static uint8_t diag_cnt = 0;
    diag_cnt++;
    if(diag_cnt %3 == 0)
    {
        EH_HELS121D_Diag();
    }
}

/**
 * @name Cdd_Lsd_ErrorDiag
 * @brief 低边驱动统一的诊断处理函数
 * @param Dd_valInfo HS通道/ADC的diag/ADC的cfb/errid等信息
 * @return none
 */
void Cdd_Lsd_ErrorDiag(dd_diaginfo* Dd_valInfo)
{

}

volatile boolean AsynLsdCtrlFlag = TRUE;
volatile boolean AsynLsdLampCtrlFlag = TRUE;

void Cdd_Lsd_CtrlMainFunction(void)
{
    volatile uint8 Lsd_Chindex = 0;
    volatile uint8 Lsd_ChDiagInhibitFlag = 0;
    for(Lsd_Chindex = 0; Lsd_Chindex < DD_LSD_DIO_CHANNEL_MAX; Lsd_Chindex++)
    {
        Lsd_ChDiagInhibitFlag = EH_GetOutputDisFlag(Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_DiagOutputDisCh);
        if(Lsd_ChDiagInhibitFlag == 1)
        {
            Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level = 0;
            IoHwAbs_DIO_SetChannelValue(Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_id, Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level);
            Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level_Last = 0;
        }
        else
        {
            if(AsynLsdCtrlFlag == TRUE)
            {
                if(Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level != Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level_Last)
                {
                    IoHwAbs_DIO_SetChannelValue(Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_id, Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level);
                    Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level_Last = Lsd_valDioCtrl_Mp[Lsd_Chindex].ch_Level;
                }
            }
        }
        
    }
}


void Cdd_Lsd_LampOutCtrlMainFunction(void)
{
    volatile uint8 Lsd_LampChindex = 0;
    for(Lsd_LampChindex = 0; Lsd_LampChindex < DD_LSD_LAMP_CHANNEL_MAX; Lsd_LampChindex++)
    {
        if(Lamp_valDioCtrl_Mp[Lsd_LampChindex].ch_Level != Lamp_valDioCtrl_Mp[Lsd_LampChindex].ch_Level_Last)
        {
            IoHwAbs_DIO_SetChannelValue(Lamp_valDioCtrl_Mp[Lsd_LampChindex].ch_id, Lamp_valDioCtrl_Mp[Lsd_LampChindex].ch_Level);
            Lamp_valDioCtrl_Mp[Lsd_LampChindex].ch_Level_Last = Lamp_valDioCtrl_Mp[Lsd_LampChindex].ch_Level;
        }
    }
}


void Cdd_Lsd_10msMainFunction(void)
{
    Cdd_Lsd_DiagFunction();

    Cdd_Lsd_CtrlMainFunction();
    if(AsynLsdLampCtrlFlag == TRUE)
    {
        Cdd_Lsd_LampOutCtrlMainFunction();
    }
}
