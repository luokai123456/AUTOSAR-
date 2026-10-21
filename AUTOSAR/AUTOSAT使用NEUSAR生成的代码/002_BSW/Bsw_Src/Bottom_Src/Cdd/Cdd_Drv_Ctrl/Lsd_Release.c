#include "Lsd_Control.h"
#include "ErrorHandler_Swc.h"

/**
 * @brief 低边驱动控制函数
 * @param uint8 ValChId，通道，参考LS index
 * @param boolean Lsd_ValChLevel，通道电平，参考LS index
 * @return 成功(0)/失败(1)
 */
extern volatile boolean AsynLsdCtrlFlag;
extern Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel);
Std_ReturnType Cdd_Lsd_AsynSetLevelFunction(uint16 ValChId,uint8 Ctr)
{

    if ((ValChId >= DD_LSD_DIO_CHANNEL_MAX))
        return E_NOT_OK;

    AsynLsdCtrlFlag = TRUE;

    Lsd_valDioCtrl_Mp[ValChId].ch_Level = Ctr;
    
    return E_OK;
}

Std_ReturnType Cdd_Lsd_SetLevelFunction(uint16 ValChId,uint8 Ctr)
{
    uint8 Lsd_SysChDiagOutputDisFlag = 0;

    AsynLsdCtrlFlag = FALSE;

    Lsd_valDioCtrl_Mp[ValChId].ch_Level = Ctr;
    if ((ValChId >= DD_LSD_DIO_CHANNEL_MAX))
        return E_NOT_OK;

    if(Lsd_valDioCtrl_Mp[ValChId].ch_Level_Last != Lsd_valDioCtrl_Mp[ValChId].ch_Level) {
        IoHwAbs_DIO_SetChannelValue(Lsd_valDioCtrl_Mp[ValChId].ch_id, Lsd_valDioCtrl_Mp[ValChId].ch_Level);
        Lsd_valDioCtrl_Mp[ValChId].ch_Level_Last = Lsd_valDioCtrl_Mp[ValChId].ch_Level;
    }

    return E_OK;
}

