/**
 * @file    Cdd_Afe_Release.c
 * @brief   实现标准化Afe接口
 *
 * @author  [dwyane tade]
 * @version 1.0.0
 * @date    2026-04-30
 *
 * @copyright Copyright (c) [2026] [天津易鼎丰]
 */

#include "Cdd_Afe_Manage.h"

uint8 Cdd_AFE_GetCellVoltages(uint16* CellVoltages, uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();
    uint8 Afe_valRetLo;

    if((!CellVoltages) || (ChLength > AFE_TOTAL_CELL_NUM)) {
        return 0;
    }

    if(Afe_valOps_Lo->get_cell_vol)
        Afe_valRetLo = Afe_valOps_Lo->get_cell_vol(CellVoltages, ChLength);

    return Afe_valRetLo;
}

uint8 Cdd_AFE_GetCellTempResistance(uint16* CalTempResistors, uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if((NULL == CalTempResistors) || (0 == ChLength) || (ChLength > AFE_DEV_NUM * 6)) {
        return 0;
    }
    
    if(Afe_valOps_Lo->get_rist)
        Afe_valOps_Lo->get_rist(CalTempResistors, 2, ChLength);

    return 1;
}

void Cdd_AFE_GetBalTempResistance(uint16* BalTempResistors, uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if((NULL == BalTempResistors) || (0 == ChLength) || (ChLength > AFE_DEV_NUM)) {
        return;
    }
    
    if(Afe_valOps_Lo->get_rist)
        Afe_valOps_Lo->get_rist(BalTempResistors, 1, ChLength);
}

void Cdd_AFE_GetChipTemp(float *AFEInterTemp,uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if((NULL == AFEInterTemp) || (0 == ChLength) || (ChLength > AFE_DEV_NUM)) {
        return;
    }
    
    if(Afe_valOps_Lo->get_chiptemp)
        Afe_valOps_Lo->get_chiptemp(AFEInterTemp, ChLength);
}

void Cdd_AFE_GetCellOpenWireStatus(uint32* OpenWireMask, uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if((NULL == OpenWireMask) || (ChLength > AFE_DEV_NUM) || (0 == ChLength))
        return;

    if(Afe_valOps_Lo->get_cell_opl)
        Afe_valOps_Lo->get_cell_opl(OpenWireMask, ChLength);
}

void Cdd_AFE_GetTempOpenWireStatus(uint32* OpenWireMask, uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if((NULL == OpenWireMask) || (ChLength > AFE_DEV_NUM) || (0 == ChLength))
        return;

    if(Afe_valOps_Lo->get_temp_opl)
        Afe_valOps_Lo->get_temp_opl(OpenWireMask, ChLength);
}

void Cdd_AFE_SetBalancingChannels(uint32* BalancingMask, uint8 ChLength)
{
    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if((NULL == BalancingMask) || (ChLength > AFE_DEV_NUM) || (0 == ChLength))
        return;

    if(Afe_valOps_Lo->set_cell_bal)
        Afe_valOps_Lo->set_cell_bal(BalancingMask, ChLength);
}

/**
 * @brief Cdd_AFE_GetBalancingStatus：获取各芯片均衡开启状态
 * @param FeedbackMask 输出均衡状态掩码数组首地址
 * @param Length 需要读取的芯片数量
 * @return E_OK全部读取成功，E_NOT_OK参数、接口或通信异常
 * @note 低层需求说明：按逻辑芯片顺序返回18位均衡通道掩码。
 */
uint8 Cdd_AFE_GetBalancingStatus(uint32* FeedbackMask, uint16 Length)
{
    Afe_OpsType* Afe_valOps_Lo;

    if((NULL == FeedbackMask) || (0U == Length) || (Length > AFE_DEV_NUM))
    {
        return E_NOT_OK;
    }

    Afe_valOps_Lo = Afe_GetOps();
    if((NULL == Afe_valOps_Lo) || (NULL == Afe_valOps_Lo->get_bal_status))
    {
        return E_NOT_OK;
    }

    return Afe_valOps_Lo->get_bal_status(FeedbackMask, Length);
}

uint8 Cdd_AFE_GetUARTCommTimeout(void)
{
    uint8 ret = 0;

    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if(Afe_valOps_Lo->get_timeout_status)
        Afe_valOps_Lo->get_timeout_status(&ret);

    return ret;
}

uint32 Cdd_AFE_GetSubMissingStatus(void)
{
    uint32 ret = 0;

    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if(Afe_valOps_Lo->get_is_offline)
        Afe_valOps_Lo->get_is_offline(&ret);

    return ret;
}

uint32 Cdd_AFE_GetBalanceErrorStatus(uint8 AFEChannel)
{
    uint32 ret = 0;

    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if(Afe_valOps_Lo->get_balance_error)
        ret = Afe_valOps_Lo->get_balance_error(AFEChannel);

    return ret;
}

uint32 Cdd_AFE_GetAFEChipErrorStatus(void)
{
    uint32 ret = 0;

    Afe_OpsType* Afe_valOps_Lo = Afe_GetOps();

    if(Afe_valOps_Lo->get_chip_error)
        Afe_valOps_Lo->get_chip_error(&ret);

    return ret;
}
