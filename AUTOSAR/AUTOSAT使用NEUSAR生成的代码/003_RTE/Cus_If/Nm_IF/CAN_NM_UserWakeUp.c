#include "CAN_NM_UserWakeUp.h"
#include "CanIf_Lcfg.h"
#include "CanNM_Cbk.h"

PduInfoType CanNm_PTCAN_PduInfoPtr  = {0, 0};                                       //PT NM CAN 0x40D PDU信息结构体
uint8 CanNm_PTCAN_PduData[8]        = {0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00};    //PT NM CAN 0x40D 接收的数据缓存

uint32* Boot_WakeupAddr = (uint32*)0xFC0C0044;  //Bootloader唤醒标志位地址


//获取Bootloader唤醒标志位 （PT NM CAN 0x40D）
void CanNm_GetBootNMWakeup_Function(void)
{
    const CanIf_RxPduCfgType* rxPduPtr = &CanIf_RxPduCfg[CANIF_RX_PDU_CFG_NWM_GW_PT__XQC0B_INDEX];  //PT NM CAN 0x40D PDU配置结构体指针
    if(*Boot_WakeupAddr == 0x5555AAAA)
    {
        CanNm_PTCAN_PduInfoPtr.SduDataPtr = &CanNm_PTCAN_PduData[0];
        CanNm_PTCAN_PduInfoPtr.SduLength = 8;
        CanNm_RxIndication(rxPduPtr->upperLayerPduId,&CanNm_PTCAN_PduInfoPtr);
        *Boot_WakeupAddr = 0x00000000;  //清除Bootloader唤醒标志位
    }
}


//被OS 调用的函数，5ms周期运行
FUNC(void, RTE_CODE) CanNm_UserWakeUp(void)
{
    CanNm_GetBootNMWakeup_Function();
    return;
}

