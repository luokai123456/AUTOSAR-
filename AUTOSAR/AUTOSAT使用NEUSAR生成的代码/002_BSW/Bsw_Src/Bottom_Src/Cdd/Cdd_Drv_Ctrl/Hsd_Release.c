#include "Hsd_Control.h"
#include "ErrorHandler_Swc.h"
/**
 * @brief 高边驱动控制函数
 * @param uint8 ValChId，通道，参考LS index
 * @param uint32 Frequency, 频率，推荐5~20000
 * @param uint32 DutyCycle，占空比，0~100
 * @return 成功(0)/失败(1)
 */

 extern volatile boolean AsynHsdCtrlFlag;
 extern Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel);
Std_ReturnType Cdd_Hsd_AsynSetLevelFunction(uint16 ValChId,uint8 Ctr)
{
    AsynHsdCtrlFlag = TRUE;

    if ((ValChId >= DD_HSD_DIO_CHANNEL_MAX))
        return E_NOT_OK;
        Hsd_valDioCtrl_Mp[ValChId].ch_Level = Ctr;

    return E_OK;
}

Std_ReturnType Cdd_Hsd_SetLevelFunction(uint16 ValChId,uint8 Ctr)
{
    uint8 Hsd_SysChDiagOutputDisFlag = 0;

    AsynHsdCtrlFlag = FALSE;

    Hsd_valDioCtrl_Mp[ValChId].ch_Level = Ctr;
    if ((ValChId >= DD_HSD_DIO_CHANNEL_MAX))
        return E_NOT_OK;


    if(Hsd_valDioCtrl_Mp[ValChId].ch_Level_Last != Hsd_valDioCtrl_Mp[ValChId].ch_Level) {
        IoHwAbs_DIO_SetChannelValue(Hsd_valDioCtrl_Mp[ValChId].ch_id, Hsd_valDioCtrl_Mp[ValChId].ch_Level);
        Hsd_valDioCtrl_Mp[ValChId].ch_Level_Last = Hsd_valDioCtrl_Mp[ValChId].ch_Level;
    }

    return E_OK;
}
