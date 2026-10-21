#include "Lsd_Control.h"

/**
 * @brief 低边PWM驱动异步控制函数
 * @param uint8 ValChId，通道，参考LS index
 * @param boolean Lsd_ValChLevel，通道电平，参考LS index
 * @return 成功(0)/失败(1)
 */

extern volatile boolean AsynLsdLampCtrlFlag;
extern Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel);
Std_ReturnType Cdd_LampOut_AsynSetLevelFunction(uint16 ValChId, uint8 Ctr)
{
    if ((ValChId >= DD_LSD_LAMP_CHANNEL_MAX))
        return E_NOT_OK;

    AsynLsdLampCtrlFlag = TRUE;

    Lamp_valDioCtrl_Mp[ValChId].ch_Level = Ctr;
    return E_OK;
}

/**
 * @brief 低边PWM驱动同步控制函数
 * @param uint8 ValChId，通道，参考LS index
 * @param boolean Lsd_ValChLevel，通道电平，参考LS index
 * @return 成功(0)/失败(1)
 */
Std_ReturnType Cdd_LampOut_SetLevelFunction(uint16 ValChId, uint8 Ctr)
{
    if ((ValChId >= DD_LSD_LAMP_CHANNEL_MAX))
        return E_NOT_OK;
        
    AsynLsdLampCtrlFlag = FALSE;

    Lamp_valDioCtrl_Mp[ValChId].ch_Level = Ctr;
    if ((ValChId >= DD_LSD_LAMP_CHANNEL_MAX))
        return E_NOT_OK;
    
    if(Lamp_valDioCtrl_Mp[ValChId].ch_Level_Last != Lamp_valDioCtrl_Mp[ValChId].ch_Level) {
        IoHwAbs_DIO_SetChannelValue(Lamp_valDioCtrl_Mp[ValChId].ch_id, Lamp_valDioCtrl_Mp[ValChId].ch_Level);
        Lamp_valDioCtrl_Mp[ValChId].ch_Level_Last = Lamp_valDioCtrl_Mp[ValChId].ch_Level;
    }
    return E_OK;
}
