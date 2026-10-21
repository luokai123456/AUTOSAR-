/**
 * @file    Cdd_Tle9018_Driver.c
 * @brief   硬件操作
 *
 * @note    本文件主要用Tle9018_ReadRegister/Tle9018_WriteRegister完成寄存器操作
 *
 * @author  [dwyane tade]
 * @version 1.0.0
 * @date    2026-04-30
 *
 * @copyright Copyright (c) [2026] [天津易鼎丰]
 */

#include "Cdd_Tle9018_Driver.h"
#include "IoHwAbs_Uart.h"
#include "Cdd_Afe_Manage.h"

#define TLE9018_COM_INST_0          TLE9018_UART_INST_0
#define TLE9018_COM_INST_1          TLE9018_UART_INST_1

/**
 * @brief 用于计算x的次幂, 例Tle9018_CalcuPow(2,3)
 */
static uint16 Tle9018_CalcuPow(uint8 val,uint8 pow)
{
    uint16 res = 1;
	uint8 n;

	if(pow < 2)
	{
		res = val;
	}
	else
	{
		for(n = 0;n < pow;n++)
		{
			res = res * val;
		}
	}

	return res;
}

/**
 * @brief 用于电阻值的计算
 * @param raw_value 原始寄存器值
 */
static float Tle9018_CalcuRist(uint16 raw_value)
{
	float moleytemp = 0;
	float denotemp = 0;
	uint8 intc = 0;

	intc = ((raw_value & TLE9018_REG_EXT_TEMP_INTC_MASK) >> TLE9018_REG_EXT_TEMP_INTC_POS);
	moleytemp = TLE9018_CALCU_FSR_TEMP * (raw_value & TLE9018_REG_EXT_TEMP_RESULT_MASK) * Tle9018_CalcuPow(2,(7 - intc));
	denotemp = TLE9018_CALCU_PARA_U * TLE9018_CALCU_PARA_A - TLE9018_CALCU_PARA_O;

	return TLE9018_CALCU_PARA_M * (moleytemp / denotemp);
}

/**
 * @brief 用于获取temp开路状态, 并返回
 * @param data_ptr, 起始地址
 * @param fault_regs, 代表这个芯片对应的寄存器
 */
static uint32 Tle9018_GetTempOpenState(const uint16 fault_regs[2])
{
    uint32 ret_val = 0U;
    uint16 reg_val;

    reg_val = fault_regs[0];
    if (reg_val & 0x0001U) { ret_val |= (1UL << 0); }
    if (reg_val & 0x0010U) { ret_val |= (1UL << 1); }
    if (reg_val & 0x0100U) { ret_val |= (1UL << 2); }
    if (reg_val & 0x1000U) { ret_val |= (1UL << 3); }

    reg_val = fault_regs[1];
    if (reg_val & 0x0001U) { ret_val |= (1UL << 4); }
    if (reg_val & 0x0010U) { ret_val |= (1UL << 5); }
    if (reg_val & 0x0100U) { ret_val |= (1UL << 6); }
    if (reg_val & 0x1000U) { ret_val |= (1UL << 7); }

    return ret_val;
}

/**
 * @brief 用于更新cell开路状态, 并存于data_ptr
 * @param data_ptr, 起始地址
 * @param index, 代表第几个芯片
 * @param fault_regs, 代表这个芯片对应的寄存器
 */
static uint32 Tle9018_GetCellOpenState(const uint16 fault_regs[9])
{
    uint32 ret_val = 0U;
    uint8 i;

    for(i = 0;i < 9;i++) {
        if(fault_regs[i] & 0x10)    { ret_val |= (1UL << (2 * i)); }
        if(fault_regs[i] & 0x1000)  { ret_val |= (1UL << (1 + 2 * i)); }
    }

    return ret_val;
}

/**
 * @brief 处理电压值，自动根据拓扑做正向/反向映射
 * @param dev 设备实例
 * @param start_addr 目标存储起始地址
 * @param type 处理类型 0(cell)/1(temp)
 * @param port 当前端口 0/1
 */ 
static void Tle9018_ProcessChannelVoltage(
    Tle9018_DevType* dev, 
    uint16* start_addr, 
    uint8 type, 
    uint8 port
)
{
    uint16* target_addr;
    uint16 raw_value;
    uint8* rxdata_ptr = NULL;
    uint8 phy_idx;
    uint8 logic_idx;
    uint8 chip_count;
    uint8 port0_chip_count;
    Tle9015_LinkStateType* link = NULL;

    if((NULL == dev) || (NULL == start_addr))
        return;
    
    if((port > 1) || (type > 1))
        return;

    link = &dev->link_state;
    rxdata_ptr = Tle9018_GetSpiRxData(port);
    chip_count = link->segments[port].dev_count;
    port0_chip_count = link->segments[0].dev_count;

    if(port == 0) {
        for(phy_idx = 0;phy_idx < chip_count;phy_idx++) {
            logic_idx = phy_idx;
            
            if(type == 0) {
                target_addr = start_addr + TLE9018_CELL_NUMBER * logic_idx;
                raw_value = (uint16)(((uint16)rxdata_ptr[0] << 8) | (uint16)rxdata_ptr[1]);
                *target_addr = (uint16)((uint32)raw_value * TLE9018_VOLTAGE_REFERENCE_MV / TLE9018_ADC_RESOLUTION);
            }else {
                target_addr = start_addr + TLE9018_GPIO_NUMBER * logic_idx;
                raw_value = (uint16)(((uint16)rxdata_ptr[0] << 8) | (uint16)rxdata_ptr[1]);
                if((raw_value & 0x3FF) <= 0x3F7) {
                    *target_addr = (uint16)(100 * Tle9018_CalcuRist(raw_value));
                }
            }
            rxdata_ptr += TLE9018_SPI_DATA_STEP;
        }
    }
    else {
        for(phy_idx = 0;phy_idx < chip_count;phy_idx++) {
            logic_idx = (chip_count - 1) - phy_idx;
            
            if(2 == link->segment_count) {
                logic_idx += port0_chip_count;
            }
            
            if(type == 0) {
                target_addr = start_addr + TLE9018_CELL_NUMBER * logic_idx;
                raw_value = (uint16)(((uint16)rxdata_ptr[0] << 8) | (uint16)rxdata_ptr[1]);
                *target_addr = (uint16)((uint32)raw_value * TLE9018_VOLTAGE_REFERENCE_MV / TLE9018_ADC_RESOLUTION);
            }else {
                target_addr = start_addr + TLE9018_GPIO_NUMBER * logic_idx;
                raw_value = (uint16)(((uint16)rxdata_ptr[0] << 8) | (uint16)rxdata_ptr[1]);
                if((raw_value & 0x3FF) <= 0x3F7) {
                    *target_addr = (uint16)(100 * Tle9018_CalcuRist(raw_value));
                }
            }
            rxdata_ptr += TLE9018_SPI_DATA_STEP;
        }
    }
}

static uint32 Tle9018_GetBalanceError(uint16 reg_val, uint8 reg_idx)
{
    uint32 state = 0U;
    uint8 cell_base = reg_idx * 2U;

    if((reg_val & 0x0060U) != 0U) {
        state |= (1UL << cell_base);
    }
    if((reg_val & 0x6000U) != 0U) {
        state |= (1UL << (cell_base + 1U));
    }

    return state;
}

static uint8 Tle9018_ProcessChipError(uint16 reg_value)
{
    if(0 != (reg_value & 0x3FFFU)) {
        return 1;
    }

    return 0;
}

void Tle9018_HandlerComError(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8 err_code)
{
    uint8 seg0_cnt;
    uint8 seg1_cnt;
    uint8 logic_addr;
    uint8 logic_idx;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER)) {
        return;
    }

    seg0_cnt = dev->link_state.segments[0].dev_count;
    seg1_cnt = dev->link_state.segments[1].dev_count;

    if(((0 == port) && (dev_id > seg0_cnt)) || ((1 == port) && (dev_id > seg1_cnt))) {
        return;
    }

    if(0 == port) {
        logic_addr = dev_id;
    }else {
        logic_addr = seg0_cnt + seg1_cnt - dev_id + 1U;
    }

    if((0 == logic_addr) || (logic_addr > TLE9018_CHIP_NUMBER)) {
        return;
    }

    logic_idx = logic_addr - 1U;

    if (err_code != 0U) {
        dev->driver.is_offline[logic_idx] = 1U;
    } else {
        dev->driver.is_offline[logic_idx] = 0U;
    }
}

static uint8 Tle9018_IsBoardOffline(Tle9018_DevType* dev)
{
    uint8 i;
    uint8 result = 0;

    for(i = 0;i < TLE9018_CHIP_NUMBER;i++) {
        if(dev->driver.is_offline[i])
            result = 1;
    }

    return result;
}

/**
 * @brief 查询指定端口的物理芯片是否离线
 * @param dev 设备指针实例
 * @param port 通信端口(0/1)
 * @param dev_id 端口内物理设备地址(1-based)
 * @return uint8 1-离线，0-在线
 */
uint8 Tle9018_IsDevOffline(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint8 seg0_cnt;
    uint8 seg1_cnt;
    uint8 logic_addr;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER)) {
        return 1U;
    }

    seg0_cnt = dev->link_state.segments[0].dev_count;
    seg1_cnt = dev->link_state.segments[1].dev_count;

    if (port == 0U) {
        logic_addr = dev_id;
    } else {
        logic_addr = seg0_cnt + seg1_cnt - dev_id + 1U;
    }
    if (logic_addr == 0U || logic_addr > TLE9018_CHIP_NUMBER) {
        return 1U;
    }

    return dev->driver.is_offline[logic_addr - 1U];
}

/**
 * @brief 进行首次唤醒
 * @param dev 设备指针实例
 * @param port 串口索引
 * 
 */
void Tle9018_WakeUpDevices(Tle9018_DevType* dev, uint8 port)
{
    uint32 index;

    if((NULL == dev) || (port > 1))  return;

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    (void)Tle9018_ReadRegister(index, 1, 0xC0, 4);
}

/**
 * @brief 设置设备地址
 * @param dev 设备指针实例
 * @param port 串口索引
 * @param dev_id 设备地址
 * @param is_final, 0 / 1, 1代表最后一个设备
 */
uint8 Tle9018_SetDeviceId(Tle9018_DevType* dev,
    uint8 port,
    uint8 dev_id,
    uint8 is_final
)
{
    uint32 index;
    uint16 Tle9018_valData_Lo = 0;
    uint8 ret;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER)) {
        return 1U;
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    if(is_final) {
        Tle9018_valData_Lo = 0x8000 | (uint16)dev_id;
    }else {
        Tle9018_valData_Lo = (uint16)dev_id;
    }

    ret = Tle9018_WriteRegister(index, 0, TLE9018_REG_IF_CFG, Tle9018_valData_Lo);
    Tle9018_HandlerComError(dev, port, dev_id, ret);

    return ret;
}

/**
 * @brief 读取设备地址
 * @param port 串口索引
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 * @
 */
uint8 Tle9018_ReadDualDevId(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8* id_out)
{
    uint32 index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;
    uint8* rxdata_ptr1 = Tle9018_GetSpiRxData(0);
    uint8* rxdata_ptr2 = Tle9018_GetSpiRxData(1);
    uint8 ret;

    if((NULL == dev) || (NULL == id_out)) {
        return 1;
    }
    
    if((port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER)) {
        return 1U;
    }

    if(Tle9018_ReadRegister_Dual(index, dev_id, TLE9018_REG_IF_CFG, 9))
        return 1;
    
    id_out[0] = rxdata_ptr1[1];
    id_out[1] = rxdata_ptr2[1];

    return 0;
}

/**
 * @brief 读取设备地址
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
uint8 Tle9018_ReadDevId(Tle9018_DevType* dev, uint8 port, uint8* dev_id)
{
    uint32 index;
    uint8* data_ptr = Tle9018_GetSpiRxData(port);;
    uint8 ret;

    if((NULL == dev) || (NULL == dev_id) || (port > 1)) {
        return 1;
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    if(Tle9018_ReadRegister(index, *dev_id, TLE9018_REG_IF_CFG, 9))
        return 1;

    *dev_id = data_ptr[1];

    return 0;
}

void Tle9018_ReadSleepStat(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8* data_ptr = NULL;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;
    data_ptr = Tle9018_GetSpiRxData(port);

    (void)Tle9018_ReadRegister(index, dev_id, TLE9018_REG_RR_SLEEP_STAT, 9);
    Tle9018_valData_Lo = (uint16)(((uint16)data_ptr[0] << 8) | (uint16)data_ptr[1]);
    if(Tle9018_valData_Lo > 0) {
        Tle9018_valData_Lo = 0x07FF;
        (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_RR_SLEEP_STAT, Tle9018_valData_Lo);
        dev->wake_up_from_sleep = 1;
    }
}

/**
 * @brief 清除所有的故障
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_ClearAllFaults(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 reg_addr;
    uint8 DevOffline_status[8] = {0};

    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;

    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    /* 先清除通道明细故障，避免汇总故障清除后被明细故障再次置位。 */
    Tle9018_valData_Lo = 0xFFFFU;
    for(reg_addr = TLE9018_REG_DIAG_1_0;
        reg_addr <= TLE9018_REG_EXT_TEMP_DIAG_1;
        reg_addr++)
    {
        (void)Tle9018_WriteRegister(index, dev_id, reg_addr,
                                    Tle9018_valData_Lo);
    }

    /* TMP_REF_DIAG仅低10位有效。 */
    Tle9018_valData_Lo = 0x03FFU;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_TMP_REF_DIAG,
                                Tle9018_valData_Lo);

    /* 最后清除通道汇总故障和通用汇总故障。 */
    Tle9018_valData_Lo = 0xFFFFU;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_CH_DIAG,
                                Tle9018_valData_Lo);
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_GEN_DIAG,
                                Tle9018_valData_Lo);
}

/**
 * @brief 配置PART0/1, 用于round_robin / PCVM
 * @param dev 设备指针实例
 * @param port 通信端口(0/1)
 * @param dev_id 端口内物理设备地址(1-based)
 * @param cell_mask 电芯掩码(18bit有效)
 */
void Tle9018_EnablePCVM(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint32 cell_mask)
{
    uint32 com_inst;
    uint16 Tle9018_valData_Lo;

    if(NULL == dev)
        return;

    if((port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;
    
    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    com_inst = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = (uint16)(cell_mask >> 2);
    (void)Tle9018_WriteRegister(com_inst, dev_id, TLE9018_REG_PART_CFG_0, Tle9018_valData_Lo);

    Tle9018_valData_Lo = (uint16)((cell_mask & 0x03U) << 14);
    (void)Tle9018_WriteRegister(com_inst, dev_id, TLE9018_REG_PART_CFG_1, Tle9018_valData_Lo);
}

/**
 * @brief 使能外部温度采集通道
 * @param dev 设备指针实例
 * @param port 通信端口(0/1)
 * @param dev_id 端口内物理设备地址(1-based)
 * @param temp_num 温度通道数量
 */
void Tle9018_EnableExternalTemp(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8 temp_num)
{
    uint32 com_inst;
    uint16 Tle9018_valData_Lo;

    if(NULL == dev)
        return;

    if((port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER) || (temp_num > 8))
        return;
    
    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    com_inst = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;
    
    Tle9018_valData_Lo = (temp_num << 12);
    (void)Tle9018_WriteRegister(com_inst, dev_id, TLE9018_REG_EXT_TEMP_CFG_2, Tle9018_valData_Lo);

    Tle9018_valData_Lo = 0x1fff;
    (void)Tle9018_WriteRegister(com_inst, dev_id, TLE9018_REG_EXT_TEMP_CFG_0, Tle9018_valData_Lo);
}

void Tle9018_SetEmmMask(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 DevOffline_status[8] = {0};
    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;

    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x0000;       //lth: AFE 唤醒启用时配置为0x3B00/ 唤醒禁用时配置为0x0000
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_FAULT_MASK_CONFIG, Tle9018_valData_Lo);
}

/**
 * @brief 设置通用配置寄存器
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_GeneralConfig(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 DevOffline_status[8] = {0};

    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;

    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x0650;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_GEN_CFG, Tle9018_valData_Lo);
}

/**
 * @brief 设置Multi_Read的配置信息
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_CfgMultiRead(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;
    uint16 Tle9018_valData_Lo;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    Tle9018_valData_Lo = 0x0012;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_MULTI_READ_CFG_0, Tle9018_valData_Lo);

    Tle9018_valData_Lo = 0x0080;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_MULTI_READ_CFG_2, Tle9018_valData_Lo);

    Tle9018_valData_Lo = 0x0FDC;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_MULTI_READ_CFG, Tle9018_valData_Lo);
}

/**
 * @brief 设置开路过欠压阈值
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_SetOvUvThreshold(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 DevOffline_status[8] = {0};

    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;

    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = (AFE_DEV_OL_THR_MAX_CFG << 10) | AFE_DEV_OV_THR_CFG;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_OL_OV_CFG, Tle9018_valData_Lo);

    Tle9018_valData_Lo = (AFE_DEV_OL_THR_MIN_CFG << 10) | AFE_DEV_UV_THR_CFG;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_OL_UV_CFG, Tle9018_valData_Lo);
}

/**
 * @brief 设置均衡电流阈值
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_SetBalCurtThreshold(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 DevOffline_status[8] = {0};

    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;

    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x0C47;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_UC_OC_CFG, Tle9018_valData_Lo);
}

/**
 * @brief 清除temp_ref错误
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_ClearTmpRefFaults(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 DevOffline_status[8] = {0};

    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;

    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x03FF;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_TMP_REF_DIAG, Tle9018_valData_Lo);
}

/**
 * @brief 开启round_robin校验
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_StartRoundRobin(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 DevOffline_status[8] = {0};

    if((NULL == dev) || (port > 1) || (0 == dev_id) || ((dev_id > TLE9018_CHIP_NUMBER) && (0x3F != dev_id)))
        return;
        
    if(dev_id != 0x3F)
    {
        if(Tle9018_IsDevOffline(dev, port, dev_id))
            return;
    }
    else
    {
        for(uint8 index_dev = 0U; index_dev < TLE9018_CHIP_NUMBER; index_dev++)
        {
            DevOffline_status[index_dev] = Tle9018_IsDevOffline(dev, port, index_dev + 1);
            if(DevOffline_status[index_dev])
                return;
        }
    }
    
    
    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x0010;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_RR_CFG_0, Tle9018_valData_Lo);
    Tle9018_valData_Lo = 0xFF01;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_RR_CFG_1, Tle9018_valData_Lo);

    return;
}

void Tle9018_StartCellBalance(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint32 bal_mask)
{
    uint32 com_inst;
    uint32 Tle9018_valMask_Lo;
    uint16 Tle9018_valData_Lo = 0;
    uint8 i, j;
    uint8 pos;
    uint8 ret;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    com_inst = (0 == port) ? TLE9018_COM_INST_0: TLE9018_COM_INST_1;

    bal_mask &= 0x3FFFF;
    for(i = 0U; i < (TLE9018_CELL_NUMBER / TLE9018_BAL_CELL_PER_REG); i++) {
        Tle9018_valData_Lo = 0U;

        for(j = 0U; j < TLE9018_BAL_CELL_PER_REG; j++) {
            pos = i * TLE9018_BAL_CELL_PER_REG + j;
            if((bal_mask & (1UL << pos)) != 0U) {
                Tle9018_valData_Lo |=  0x1F << (j * TLE9018_BAL_CNT_BIT_WIDTH);
            }
        }
        ret = Tle9018_WriteRegister(com_inst, dev_id, (TLE9018_REG_BAL_CNT_CFG_0 + i), Tle9018_valData_Lo);
        Tle9018_HandlerComError(dev, port, dev_id, ret);
    }

    Tle9018_ClearAllFaults(dev, com_inst, dev_id);

    Tle9018_valData_Lo = (uint16)(bal_mask >> 2);
    ret = Tle9018_WriteRegister(com_inst, dev_id, TLE9018_REG_BAL_CTRL_0, Tle9018_valData_Lo);
    Tle9018_HandlerComError(dev, port, dev_id, ret);

    Tle9018_valData_Lo = (uint16)((bal_mask & 0x03) << 14) | 0x01;
    ret = Tle9018_WriteRegister(com_inst, dev_id, TLE9018_REG_BAL_CTRL_1, Tle9018_valData_Lo);
    Tle9018_HandlerComError(dev, port, dev_id, ret);
}

/**
 * @brief 开启ADC转换
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_TrigMeas(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 ret;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0xe021;
    ret = Tle9018_WriteRegister(index, dev_id, TLE9018_REG_MEAS_CTRL, Tle9018_valData_Lo);
    Tle9018_HandlerComError(dev, port, dev_id, ret);
}

/**
 * @brief 读取内部温度信息
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_ReadIntelTemp(Tle9018_DevType* dev, uint8 port, uint8 dev_id, float* int_temp)
{
    uint32 com_inst;
    uint16 Tle9018_valData_Lo = 0;
    uint8* data_ptr = NULL;
    uint8 ret;

    if((NULL == dev) || (NULL == int_temp))
        return;
    
    if((port > 1) || (dev_id > TLE9018_CHIP_NUMBER) || (0 == dev_id))
        return;
    
    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    data_ptr = Tle9018_GetSpiRxData(port);
    com_inst = (0 == port) ? TLE9018_COM_INST_0: TLE9018_COM_INST_1;

    ret = Tle9018_ReadRegister(com_inst, dev_id, TLE9018_REG_INT_TEMP_0, 9);
    Tle9018_HandlerComError(dev, port, dev_id, ret);
    Tle9018_valData_Lo = (uint16)((((uint16)data_ptr[0] << 8) | (uint16)data_ptr[1]) & 0xFFF);
    *int_temp = 541 - 0.1597f * (float)Tle9018_valData_Lo;
}

/**
 * @brief 读取电芯电压
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_ReadCellVoltage(Tle9018_DevType* dev, uint8 port, uint8 pos)
{
    uint32 com_inst;
    uint8 ret;
    uint8 offset;
    uint8 chip_count;
    uint8 read_len;

    if(NULL == dev) return;

    if(Tle9018_IsBoardOffline(dev) ||\
        (port > 1) ||\
        (pos >= 6)
    ) {
        return;
    }

    chip_count = dev->link_state.segments[port].dev_count;
    if (chip_count == 0U) {
        return;
    }

    read_len = 4 + chip_count * 5;
    com_inst = (0 == port) ? TLE9018_COM_INST_0: TLE9018_COM_INST_1;
    
    offset = 3 * pos;
    ret = Tle9018_ReadRegister(com_inst, 0x3F, (TLE9018_REG_PCVM_1 + offset), read_len);
    Tle9018_ProcessChannelVoltage(dev, &dev->driver.cell_vol[offset], 0, port);

    offset = 1 + 3 * pos;
    ret = Tle9018_ReadRegister(com_inst, 0x3F, (TLE9018_REG_PCVM_1 + offset), read_len);
    Tle9018_ProcessChannelVoltage(dev, &dev->driver.cell_vol[offset], 0, port);

    offset = 2 + 3 * pos;
    ret = Tle9018_ReadRegister(com_inst, 0x3F, (TLE9018_REG_PCVM_1 + offset), read_len);
    Tle9018_ProcessChannelVoltage(dev, &dev->driver.cell_vol[offset], 0, port);
}

/**
 * @brief 读取外部温度
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */

void Tle9018_ReadTempVoltage(Tle9018_DevType* dev, uint8 port, uint8 pos)
{
    uint32 com_inst;
    uint8 ret;
    uint8 offset;
    uint8 chip_count;
    uint8 read_len;

    if(NULL == dev) return;
    if(Tle9018_IsBoardOffline(dev) ||\
        (port > 1) ||\
        (pos >= 4)
    ) {
        return;
    }

    chip_count = dev->link_state.segments[port].dev_count;
    if (chip_count == 0U) {
        return;
    }

    read_len = 4 + chip_count * 5;
    com_inst = (0 == port) ? TLE9018_COM_INST_0: TLE9018_COM_INST_1;
    offset = 2 * pos;
    ret = Tle9018_ReadRegister(com_inst, 0x3F, (EXT_TEMP_1 + offset), read_len);
    Tle9018_ProcessChannelVoltage(dev, &dev->driver.rist_val[offset], 1, port);

    offset = 1 + 2 * pos;
    ret = Tle9018_ReadRegister(com_inst, 0x3F, (EXT_TEMP_1 + offset), read_len);
    Tle9018_ProcessChannelVoltage(dev, &dev->driver.rist_val[offset], 1, port);
}

/**
 * @brief 读取通用诊断/状态信息
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_ReadGenernalInfo(Tle9018_DevType* dev, uint8 port, uint8 dev_id, uint8* chip_error)
{
    uint32 index;
    uint8* data_ptr = NULL;
    uint16 raw_reg_val;
    uint8 ret;

    if((NULL == dev) || (NULL == chip_error))
        return;

    if((port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    index = (0 == port) ? TLE9018_COM_INST_0: TLE9018_COM_INST_1;
    data_ptr = Tle9018_GetSpiRxData(port);
    if(!data_ptr)
        return;

    ret = Tle9018_ReadRegister(index, dev_id, TLE9018_REG_GEN_STAT, 9);
    Tle9018_HandlerComError(dev, port, dev_id, ret);
    ret = Tle9018_ReadRegister(index, dev_id, TLE9018_REG_GEN_DIAG, 9);
    raw_reg_val = (uint16)(((uint16)data_ptr[0] << 8) | (uint16)data_ptr[1]);
    *chip_error = Tle9018_ProcessChipError(raw_reg_val);
    Tle9018_HandlerComError(dev, port, dev_id, ret);
}

/**
 * @brief 读取诊断信息
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_ReadDiagInfo(Tle9018_DevType* dev,
    uint8 port,
    uint8 dev_id,
    uint32* temp_opl,
    uint32* cell_opl,
    uint32* bal_err
)
{
    uint32 com_inst;
    uint16 Tle9018_valData_Lo[9] = {0};
    uint8* data_ptr = NULL;
    uint8 i;
    uint8 ret;

    if((NULL == dev) || (NULL == temp_opl) || (NULL == cell_opl) || (NULL == bal_err))
        return;

    if((port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    com_inst = (0 == port) ? TLE9018_COM_INST_0: TLE9018_COM_INST_1;
    data_ptr = Tle9018_GetSpiRxData(port);

    for(i = 0;i < 2;i++) {
        ret = Tle9018_ReadRegister(com_inst, dev_id, (TLE9018_REG_EXT_TEMP_DIAG_0 + i), 9);
        Tle9018_HandlerComError(dev, port, dev_id, ret);
        Tle9018_valData_Lo[i] = (uint16)(((uint16)data_ptr[0] << 8) | (uint16)data_ptr[1]);
    }

    *temp_opl = Tle9018_GetTempOpenState(Tle9018_valData_Lo);

    for(i = 0;i < 9;i++) {
        ret = Tle9018_ReadRegister(com_inst, dev_id, (TLE9018_REG_DIAG_1_0 + i), 9);
        Tle9018_HandlerComError(dev, port, dev_id, ret);
        Tle9018_valData_Lo[i] = (uint16)(((uint16)data_ptr[0] << 8) | (uint16)data_ptr[1]);
        *bal_err |= Tle9018_GetBalanceError(Tle9018_valData_Lo[i], i);
    }
    *cell_opl = Tle9018_GetCellOpenState(Tle9018_valData_Lo);
}

/**
 * @brief 喂狗函数, 狗无法关闭, 需要周期喂狗
 * @param dev 设备指针实例
 * @param dev_id 设备地址
 */
void Tle9018_FeedWatchDog(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;
    uint8 ret;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x000A;
    ret = Tle9018_WriteRegister(index, dev_id, TLE9018_REG_WDOG_CNT, Tle9018_valData_Lo);
    Tle9018_HandlerComError(dev, port, dev_id, ret);
}

/**
 * @brief Tle9018_GetBalancingStatusValue：转换均衡控制寄存器状态
 * @param bal_ctrl_0 BAL_CTRL_0寄存器值
 * @param bal_ctrl_1 BAL_CTRL_1寄存器值
 * @return 18个通道的均衡状态掩码
 * @note 低层需求说明：组合BAL_CTRL_0和BAL_CTRL_1中的通道使能位。
 */
static uint32 Tle9018_GetBalancingStatusValue(uint16 bal_ctrl_0,
    uint16 bal_ctrl_1)
{
    uint32 balancing_mask;

    balancing_mask = (((uint32)bal_ctrl_0 << 2U) & 0x3FFFCUL) |
                     (((uint32)bal_ctrl_1 >> 14U) & 0x00003UL);

    return balancing_mask;
}

/**
 * @brief Tle9018_ReadBalancingStatus：读取指定芯片的均衡控制状态
 * @param dev TLE9018设备实例指针
 * @param port 通信端口，取值0或1
 * @param dev_id 芯片物理地址
 * @param balancing_mask 输出的18通道均衡状态掩码
 * @return E_OK读取成功，E_NOT_OK读取失败
 * @note 低层需求说明：读取BAL_CTRL_0和BAL_CTRL_1并还原通道状态。
 */
uint8 Tle9018_ReadBalancingStatus(Tle9018_DevType* dev,
    uint8 port,
    uint8 dev_id,
    uint32* balancing_mask)
{
    uint32 com_inst;
    uint16 bal_ctrl_0;
    uint16 bal_ctrl_1;
    uint8* data_ptr;
    uint8 ret;

    if((NULL == dev) || (NULL == balancing_mask) || (port > 1U) ||
       (0U == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
    {
        return E_NOT_OK;
    }

    if(0U != Tle9018_IsDevOffline(dev, port, dev_id))
    {
        return E_NOT_OK;
    }

    com_inst = (0U == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;
    data_ptr = Tle9018_GetSpiRxData(port);
    if(NULL == data_ptr)
    {
        return E_NOT_OK;
    }

    ret = Tle9018_ReadRegister(com_inst, dev_id, TLE9018_REG_BAL_CTRL_0, 9U);
    if(0U != ret)
    {
        Tle9018_HandlerComError(dev, port, dev_id, ret);
        return E_NOT_OK;
    }
    bal_ctrl_0 = (uint16)(((uint16)data_ptr[0] << 8U) |
                          (uint16)data_ptr[1]);

    ret = Tle9018_ReadRegister(com_inst, dev_id, TLE9018_REG_BAL_CTRL_1, 9U);
    if(0U != ret)
    {
        Tle9018_HandlerComError(dev, port, dev_id, ret);
        return E_NOT_OK;
    }
    bal_ctrl_1 = (uint16)(((uint16)data_ptr[0] << 8U) |
                          (uint16)data_ptr[1]);

    *balancing_mask = Tle9018_GetBalancingStatusValue(bal_ctrl_0,
                                                       bal_ctrl_1);
    return E_OK;
}

void Tle9018_GoToSleep(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
        return;

    if(Tle9018_IsDevOffline(dev, port, dev_id))
        return;

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x0001;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_OP_MODE, Tle9018_valData_Lo);
}


void Tle9018_ResetFromSleep(Tle9018_DevType* dev, uint8 port, uint8 dev_id)
{
    uint32 index;
    uint16 Tle9018_valData_Lo;

    if((NULL == dev) || (port > 1) || (0 == dev_id) || (dev_id > TLE9018_CHIP_NUMBER))
    {
        return;
    }

    // if(Tle9018_IsDevOffline(dev, port, dev_id))
    // {
    //     return; 
    // }

    index = (0 == port) ? TLE9018_COM_INST_0 : TLE9018_COM_INST_1;

    Tle9018_valData_Lo = 0x0100;
    (void)Tle9018_WriteRegister(index, dev_id, TLE9018_REG_OP_MODE, Tle9018_valData_Lo);
}
