
#include "COL_50ms.h"

extern void Sws_EcuCtrl_SetShutDownType(uint8 Data);

void COL_50ms(void)
{

    Rte_IWrite_COL_50ms_BSWIOSP_Mode_Request_shutdown_Request_shutdown(2); 

    //测试NOS下SWC控制不发送网络管理报文
    // Rte_IWrite_COL_100ms_BMS_DelayControl_BMS_DelayControl(1);

    //SWC给的主动唤醒标志位
    // Sws_EcuCtrl_SetShutDownType(0);
    
}


