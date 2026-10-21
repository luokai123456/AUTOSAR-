#include "Lsd_Control.h"
#include "IoHwAbs_PWM.h"
#include "PwmOut_Release.h"

/**
 * @name Cdd_PwmOut_Function
 * @param uint16 ValChId，通道，参考LS PWM index
 * @param uint32 Frequency，PWM频率，单位：Hz
 * @param uint32 DutyCycle，PWM占空比，单位：%
 * @return 成功(0)/失败(1)
 */
Std_ReturnType Cdd_PwmOut_Function(uint16 ValChId, uint32 Frequency, uint32 DutyCycle)
{
    uint32 Lsd_dutyOut;

    if(ValChId >= DD_LSD_PWM_CHANNEL_MAX)
    {
        return E_NOT_OK;
    }
    if((Frequency < 0) || (Frequency > 20000))
    {
        return E_NOT_OK;
    }

    if((DutyCycle < 0) || (DutyCycle > 100))
    {
        return E_NOT_OK;
    }

    if((Lsd_valPwmCtrl_Mp[ValChId].ch_Frequency != Frequency) || (Lsd_valPwmCtrl_Mp[ValChId].ch_DutyCycle != DutyCycle))
    {
        /* PWMOUT7 通道输出逻辑与其它通道相反，占空比直接使用，无需取反 */
        if(ValChId == IoHwAbs_PWM_MCU_PWMOUT7)
        {
            Lsd_dutyOut = DutyCycle;
        }
        else
        {
            Lsd_dutyOut = 100U - DutyCycle;
        }
        Pwm_SetFreqAndDuty(Lsd_valPwmCtrl_Mp[ValChId].ch_Pwmid, Frequency, Lsd_dutyOut);
        Lsd_valPwmCtrl_Mp[ValChId].ch_Frequency = Frequency;
        Lsd_valPwmCtrl_Mp[ValChId].ch_DutyCycle = DutyCycle;
    }

    return E_OK;
}
