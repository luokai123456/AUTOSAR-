/**
 * @file    Cdd_Afe_Manage.c
 * @brief   向上适配标准化接口, 向下管理初始化以及调度
 *
 * @author  [dwyane tade]
 * @version 1.0.0
 * @date    2026-04-30
 *
 * @copyright Copyright (c) [2026] [天津易鼎丰]
 */

#include "Cdd_Afe_Manage.h"
#include "Cdd_Tle9015_Topology.h"
#include "Cdd_Tle9018_Driver.h"
#include "CCFC3012PT.h"

#define AFE_STATE_INITING           0
#define AFE_STATE_TRIG              1
#define AFE_STATE_READ              2
#define AFE_STATE_DIAG              3

#define AFE_DUAL_CHAIN_WAIT_SLEEP        0
#define AFE_DUAL_CHAIN_TOPOLOPY          1
#define AFE_DUAL_CHAIN_ACTIVE_CHIP       2
#define AFE_DUAL_CHAIN_CFG_FUNC_1        3
#define AFE_DUAL_CHAIN_CFG_FUNC_2        4
#define AFE_DUAL_CHAIN_CFG_FUNC_3        5

uint8 AFE_valAbistState_Mp = 0;
uint8 AFE_valDualInitState_Mp = AFE_DUAL_CHAIN_WAIT_SLEEP;

extern uint32 AFE_valCellMask_Mp[TLE9018_CHIP_NUMBER];
extern uint8 AFE_valTempNumber_Mp[TLE9018_CHIP_NUMBER];

Tle9018_DevType Afe_valDev_Mp = {0};

uint8 Tle9015_DualChain_Init(void);

Tle9018_DevType* Afe_GetDev(void)
{
    return &Afe_valDev_Mp;
}

/**
 * @brief 非标准化接口, 配置电芯 / 温度具体使用情况
 * @param dev Tle9018 设备实例指针
 */
static void Cdd_Afe_UserConfig(void* dev)
{
    Tle9018_DevType* p_dev = (Tle9018_DevType*)dev;
    Tle9015_LinkStateType* link = &p_dev->link_state;
    uint8 logic_chip;
    uint8 phy_chip_idx;
    uint8 seg_cnt = link->segment_count;
    uint8 seg0_cnt = link->segments[0].dev_count;
    uint8 seg1_cnt = link->segments[1].dev_count;

    if(NULL == p_dev) return;

    for(phy_chip_idx = 0; phy_chip_idx < seg0_cnt; phy_chip_idx++) {
        logic_chip = phy_chip_idx;
        p_dev->driver.cell_mask[logic_chip] = AFE_valCellMask_Mp[logic_chip] & 0x3FFFF;
        if(AFE_valTempNumber_Mp[logic_chip] <= 8)
            p_dev->driver.temp_number[logic_chip] = AFE_valTempNumber_Mp[logic_chip];
    }

    for(phy_chip_idx = 0; phy_chip_idx < seg1_cnt; phy_chip_idx++) {
        logic_chip = (seg1_cnt - 1) - phy_chip_idx;
        if(2 == seg_cnt) {
            logic_chip += seg0_cnt;
        }

        p_dev->driver.cell_mask[logic_chip] = AFE_valCellMask_Mp[logic_chip] & 0x3FFFF;
        if(AFE_valTempNumber_Mp[logic_chip] <= 8)
            p_dev->driver.temp_number[logic_chip] = AFE_valTempNumber_Mp[logic_chip];
    }
}

/**
 * @brief AFE的初始化函数
 */
__attribute__((ghs_optimize(Onone))) void Cdd_Afe_InitFunction(void)
{
    uint32 mask_val;
    uint8 temp_num;
    uint8 total_dev;
    uint8 phy_id;
    uint8 port;
    uint8 seg_cnt;
    uint8 ret;
    uint8 i;

    AFE_valAbistState_Mp = Cdd_Afe_Tle9015_AbistChack(&Afe_valDev_Mp);

    ret = Tle9015_Topology_AutoInit(&Afe_valDev_Mp);
    if(ret) {
        for(i = 0;i < AFE_DEV_NUM;i++)
            Afe_valDev_Mp.driver.is_offline[i] = 1;
        return;
    }

    Cdd_Afe_UserConfig((void*)&Afe_valDev_Mp);
    total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);
    Afe_valDev_Mp.inited = 1;

    for(i = 1;i <= total_dev;i++) {
        phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, i);
        port = Tle9015_GetPort(&Afe_valDev_Mp, i);
        Tle9018_ReadSleepStat(&Afe_valDev_Mp, port, phy_id);
    }

    seg_cnt = Afe_valDev_Mp.link_state.segment_count;
    for(i = 0;i < seg_cnt;i++) {
        if(1 == seg_cnt)
            port = (Afe_valDev_Mp.link_state.segments[0].dev_count > 0) ? 0 : 1;
        else if(2 == seg_cnt)
            port = i;
        
        Tle9018_ClearAllFaults(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
    }
    
    for(i = 1; i <= total_dev; i++) {
        phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, i);
        port   = Tle9015_GetPort(&Afe_valDev_Mp, i);
        mask_val = Afe_valDev_Mp.driver.cell_mask[i - 1];
        temp_num  = Afe_valDev_Mp.driver.temp_number[i - 1];

        Tle9018_EnablePCVM(&Afe_valDev_Mp, port, phy_id, mask_val);
        Tle9018_EnableExternalTemp(&Afe_valDev_Mp, port, phy_id, temp_num);
    }

    for(i = 0;i < seg_cnt;i++) {
        if(1 == seg_cnt)
            port = (Afe_valDev_Mp.link_state.segments[0].dev_count > 0) ? 0 : 1;
        else if(2 == seg_cnt)
            port = i;
        
        // Tle9018_SetEmmMask(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
        Tle9018_GeneralConfig(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
#if 0
        Tle9018_CfgMultiRead(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
#endif
        Tle9018_SetOvUvThreshold(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
        Tle9018_SetBalCurtThreshold(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
        Tle9018_ClearTmpRefFaults(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
        Tle9018_StartRoundRobin(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
    }
}

/**
 * @brief 启动所有在线芯片的均衡
 */
static void Cdd_Afe_StartAllCellBalance(void)
{
    uint32 cur_mask;
    uint8 total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);
    uint8 phy_id;
    uint8 port;
    uint8 i;

    for(i = 1U; i <= total_dev; i++) {
        cur_mask = Afe_valDev_Mp.driver.bal_mask[i - 1];

        if(cur_mask == Afe_valDev_Mp.driver.bal_mask_last[i - 1]) {
            continue;
        }

        Afe_valDev_Mp.driver.bal_mask_last[i - 1] = cur_mask;

        phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, i);
        port   = Tle9015_GetPort(&Afe_valDev_Mp, i);

        Tle9018_StartCellBalance(&Afe_valDev_Mp, port, phy_id, cur_mask);
    }
}



/**
 * @brief 初始化等待状态处理
 * @details 等待NVM就绪，延迟5个10ms周期后进入测量触发状态
 */
static void Cdd_Afe_StateIniting(void)
{
    Afe_valDev_Mp.delay++;
    if (5U == Afe_valDev_Mp.delay) {
        Afe_valDev_Mp.delay = 0U;
        Afe_valDev_Mp.step = AFE_STATE_TRIG;
    }
}

/**
 * @brief 测量触发状态处理
 * @details 批量启动均衡，遍历所有逻辑芯片触发ADC测量
 */
static void Cdd_Afe_StateTrigMeas(void)
{
    float chip_int_temp;
    uint8 total_dev;
    uint8 logic_addr;
    uint8 phy_id;
    uint8 port;

    total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);

    Cdd_Afe_StartAllCellBalance();

    for (logic_addr = 1U; logic_addr <= total_dev; logic_addr++) {
        phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, logic_addr);
        port   = Tle9015_GetPort(&Afe_valDev_Mp, logic_addr);
        Tle9018_TrigMeas(&Afe_valDev_Mp, port, phy_id);

        Tle9018_ReadIntelTemp(&Afe_valDev_Mp, port, phy_id, &chip_int_temp);
        Afe_valDev_Mp.driver.int_temp[logic_addr - 1] = chip_int_temp;
    }

    Afe_valDev_Mp.step = AFE_STATE_READ;
    Afe_valDev_Mp.read_counter = 0U;
}

/**
 * @brief 电压温度读取状态处理
 * @details 轮询读取电芯电压和温度，6组寄存器读完后进入诊断状态
 */
static void Cdd_Afe_StateReadVoltage(void)
{
    uint8 seg_cnt;
    uint8 read_idx;

    seg_cnt = Afe_valDev_Mp.link_state.segment_count;
    read_idx = Afe_valDev_Mp.read_counter;

    /* 单段场景：仅读取对应端口 */
    if (1U == seg_cnt) {
        if (Afe_valDev_Mp.link_state.segments[0].dev_count > 0U) {
            Tle9018_ReadCellVoltage(&Afe_valDev_Mp, 0U, read_idx);
            if (read_idx < 4U) {
                Tle9018_ReadTempVoltage(&Afe_valDev_Mp, 0U, read_idx);
            }
        } else if (Afe_valDev_Mp.link_state.segments[1].dev_count > 0U) {
            Tle9018_ReadCellVoltage(&Afe_valDev_Mp, 1U, read_idx);
            if (read_idx < 4U) {
                Tle9018_ReadTempVoltage(&Afe_valDev_Mp, 1U, read_idx);
            }
        }
    }
    /* 双段场景：两个端口同时读取 */
    else if (2U == seg_cnt) {
        Tle9018_ReadCellVoltage(&Afe_valDev_Mp, 0U, read_idx);
        Tle9018_ReadCellVoltage(&Afe_valDev_Mp, 1U, read_idx);
        if (read_idx < 4U) {
            Tle9018_ReadTempVoltage(&Afe_valDev_Mp, 0U, read_idx);
            Tle9018_ReadTempVoltage(&Afe_valDev_Mp, 1U, read_idx);
        }
    }

    Afe_valDev_Mp.read_counter++;
    if (6U == Afe_valDev_Mp.read_counter) {
        Afe_valDev_Mp.step = AFE_STATE_DIAG;
        Afe_valDev_Mp.read_counter = 0U;
    }
}

/**
 * @brief 诊断信息读取状态处理
 * @details 轮询读取单芯片通用信息、诊断状态，喂狗，全部读完回到触发状态
 */
static void Cdd_Afe_StateReadDiag(void)
{
    uint32 temp_opl_state = 0;
    uint32 cell_opl_state = 0;
    uint32 balance_error_state = 0;
    uint32 balance_state = 0;
    uint8 chip_error_state = 0;
    uint8 balance_status_ret;
    uint8 total_dev;
    uint8 logic_addr;
    uint8 phy_id;
    uint8 port;

    total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);
    logic_addr = Afe_valDev_Mp.read_counter + 1U;

    phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, logic_addr);
    port   = Tle9015_GetPort(&Afe_valDev_Mp, logic_addr);

    Tle9018_ReadGenernalInfo(&Afe_valDev_Mp, port, phy_id, &chip_error_state);

    Tle9018_ReadDiagInfo(&Afe_valDev_Mp, port, phy_id,
                                 &temp_opl_state, &cell_opl_state, &balance_error_state);

    Afe_valDev_Mp.driver.temp_opl_state[logic_addr - 1]    = temp_opl_state;
    Afe_valDev_Mp.driver.cell_opl_state[logic_addr - 1]    = cell_opl_state;
    Afe_valDev_Mp.driver.balance_error_state[logic_addr - 1] = balance_error_state;
    Afe_valDev_Mp.driver.is_chip_error[logic_addr - 1] = chip_error_state;

    balance_status_ret = Tle9018_ReadBalancingStatus(&Afe_valDev_Mp,
                                                      port,
                                                      phy_id,
                                                      &balance_state);
    if(E_OK == balance_status_ret)
    {
        Afe_valDev_Mp.driver.balance_state[logic_addr - 1U] = balance_state;
    }

    Tle9018_FeedWatchDog(&Afe_valDev_Mp, port, phy_id);

    Afe_valDev_Mp.read_counter++;
    if (AFE_DEV_NUM == Afe_valDev_Mp.read_counter) {
        Afe_valDev_Mp.step = AFE_STATE_TRIG;
        Afe_valDev_Mp.read_counter = 0U;
    }
}

/**
 * @brief Afe的10ms调度函数
 */
uint8 Afe_ValOffLineFg_Mp;
uint8 Afe_ValOffLineCheakFg_Mp;
uint8 Afe_valDev_Mp_step_cnt[2];
uint8 Afe_valDev_nSleepFg_Mp = 0U;
extern uint8 Tle9018_IsDevOffline(Tle9018_DevType* dev, uint8 port, uint8 dev_id);
void Cdd_Afe_MainFunction_10ms(void)
{
    if(!Afe_valDev_Mp.inited)
        return;

    if(Afe_ValOffLineCheakFg_Mp == 0U) {
        for (uint8 i = 0;i < AFE_DEV_NUM;i++) {
            if (Tle9018_IsDevOffline(&Afe_valDev_Mp, 0, i + 1U)) {
                Afe_ValOffLineFg_Mp = 1U;
                Afe_ValOffLineCheakFg_Mp = 1U;
                break;
            }
        }     
    }

    if(Afe_ValOffLineFg_Mp == 1U) {
        if(Afe_valDev_nSleepFg_Mp == 0U) {
            SIUL.GPDO[136].R = 0;
            Afe_valDev_nSleepFg_Mp = 1U;
        }
        
        Tle9015_DualChain_Init();
    }
    else {
        switch (Afe_valDev_Mp.step)
        {   
        case AFE_STATE_INITING:
            Cdd_Afe_StateIniting();
            break;
        case AFE_STATE_TRIG:
            Cdd_Afe_StateTrigMeas();
            break;
        case AFE_STATE_READ:
            Cdd_Afe_StateReadVoltage();
            break;
        case AFE_STATE_DIAG:
            Cdd_Afe_StateReadDiag();
            break;
        default:
            break;
        }
    }
}

void Cdd_Afe_GoToSleep(void)
{
    uint8 i;
    uint8 seg0_cnt;
    uint8 seg1_cnt;
    seg0_cnt = Afe_valDev_Mp.link_state.segments[0].dev_count;
    seg1_cnt = Afe_valDev_Mp.link_state.segments[1].dev_count;
    for(i = seg0_cnt;i >= 1;i--)
    {
        Tle9018_SetEmmMask(&Afe_valDev_Mp, 0, i);
        Tle9018_GoToSleep(&Afe_valDev_Mp, 0, i);
    }
    for(i = seg1_cnt;i >= 1;i--)
    {
        Tle9018_SetEmmMask(&Afe_valDev_Mp, 1, i);
        Tle9018_GoToSleep(&Afe_valDev_Mp, 1, i);
    }
}
/**
 * @brief 适配标准化接口, 拷贝电芯电压
 * @param vol 起始地址
 * @param len 长度
 */
static uint8 Afe_GetCellVoltages(uint16* vol, uint8 len)
{
    uint8 i;

    if((NULL == vol) || (len > AFE_TOTAL_CELL_NUM))
        return E_NOT_OK;

    memcpy(vol, Afe_valDev_Mp.driver.cell_vol, 2 * len);

    return E_OK;
}

/**
 * @brief 适配标准化接口, 拷贝电阻值
 * @param vol 起始地址
 * @param type 0(bal) / 1(intel) / 2(external)
 * @param len 长度
 */
static void Afe_GetRist(uint16* rist, uint8 type, uint8 len)
{
    uint8 i;

    if(NULL == rist)    return;

    switch (type)
    {
    case 0:
        if((0 == len) || (len > AFE_DEV_NUM)) return;

        for(i = 0;i < len;i++) {
            *rist = Afe_valDev_Mp.driver.rist_val[8 * i];
            rist++; 
        }
        break;
    case 1:
        if((0 == len) || (len > AFE_DEV_NUM)) return;

        for(i = 0;i < len;i++) {
            *rist = Afe_valDev_Mp.driver.rist_val[8 * i + 1];
            rist++; 
        }
        break;
    case 2:
        if((0 == len) || (len > AFE_DEV_NUM * 6) || (0 != (len % 6))) return;

        for(i = 0;i < len / 6;i++) {
            memcpy(rist, &Afe_valDev_Mp.driver.rist_val[8 * i + 2], 6 * sizeof(uint16));
            rist += 6;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 适配标准化接口, 开启均衡
 * @param bal_cfg bal位图
 * @param len 长度
 */
static void Afe_SetCellBalance(uint32* bal_cfg, uint8 len)
{
    uint8 i;

    if((NULL == bal_cfg) || (len > AFE_DEV_NUM))
        return;

    for(i = 0;i < len;i++)
        Afe_valDev_Mp.driver.bal_mask[i] = bal_cfg[i];
}

/**
 * @brief Afe_GetBalancingStatus：复制周期采集的均衡状态
 * @param feedback_mask 输出均衡状态掩码数组首地址
 * @param length 需要获取的芯片数量
 * @return E_OK复制成功，E_NOT_OK参数或初始化状态异常
 * @note 低层需求说明：从balance_state缓存按逻辑芯片顺序反馈状态。
 */
static uint8 Afe_GetBalancingStatus(uint32* feedback_mask, uint16 length)
{
    uint8 total_dev;
    uint8 index;

    if((NULL == feedback_mask) || (0U == length) ||
       (length > AFE_DEV_NUM) || (0U == Afe_valDev_Mp.inited))
    {
        return E_NOT_OK;
    }

    total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);
    if(length > total_dev)
    {
        return E_NOT_OK;
    }

    memcpy(feedback_mask, Afe_valDev_Mp.driver.balance_state,
           length * sizeof(uint32));

    return E_OK;
}

/**
 * @brief 适配标准化接口, 获取电芯开路信息
 * @param mask cell_opl位图
 * @param len 长度
 */
static void Afe_GetCellOpl(uint32* mask, uint8 len)
{
    if((NULL == mask) || (len > AFE_DEV_NUM))
        return;

    memcpy(mask, Afe_valDev_Mp.driver.cell_opl_state, 4 * len);
}

/**
 * @brief 适配标准化接口, 获取温度开路信息
 * @param mask temp_opl位图
 * @param len 长度
 */
static void Afe_GetTempOpl(uint32* mask, uint8 len)
{
    if((NULL == mask) || (len > AFE_DEV_NUM))
        return;

    memcpy(mask, Afe_valDev_Mp.driver.temp_opl_state, 4 * len);
}

static void Afe_GetChipTemp(float* temp, uint8 len)
{
    if((NULL == temp) || (len > AFE_DEV_NUM))
        return;

    memcpy(temp, Afe_valDev_Mp.driver.int_temp, 4 * len);
}

static void Afe_GetTimeoutStatus(uint8* timeout)
{
    uint8 i;
    for(i = 0;i < AFE_DEV_NUM;i++) {
        if(1 == Afe_valDev_Mp.driver.is_offline[i])
        {
            *timeout = 1;
        }
        else if(1 == Afe_valDev_Mp.driver.is_offlinehistory[i])
        {
            *timeout = 1;
        }
        else
        {
            //Nothing todo
        }
    }
}

static void Afe_GetIsOffline(uint32* val)
{
    uint8 i;

    for(i = 0;i < AFE_DEV_NUM;i++) {
        if(Afe_valDev_Mp.driver.is_offline[i] == 1)
        {
            *val |= (Afe_valDev_Mp.driver.is_offline[i] << i); 
        }
        else if(Afe_valDev_Mp.driver.is_offlinehistory[i] == 1)
        {
            *val |= (Afe_valDev_Mp.driver.is_offlinehistory[i] << i);
        }
        else
        {
            *val |= (Afe_valDev_Mp.driver.is_offline[i] << i);
        }
    }
}

static uint32 Afe_GetBalanceError(uint8 channel)
{
    uint8 i;

    return Afe_valDev_Mp.driver.balance_error_state[channel];
}

static void Afe_GetChipError(uint32* val)
{
    uint8 i;

    for(i = 0;i < AFE_DEV_NUM;i++) {
        *val |= (Afe_valDev_Mp.driver.is_chip_error[i] << i);
    }
}

static Afe_OpsType Afe_valOps_Mp = {
    .get_cell_vol = Afe_GetCellVoltages,
    .set_cell_bal = Afe_SetCellBalance,
    .get_bal_status = Afe_GetBalancingStatus,
    .get_cell_opl = Afe_GetCellOpl,
    .get_temp_opl = Afe_GetTempOpl,
    .get_rist = Afe_GetRist,
    .get_chiptemp = Afe_GetChipTemp,
    .get_timeout_status = Afe_GetTimeoutStatus,
    .get_is_offline = Afe_GetIsOffline,
    .get_balance_error = Afe_GetBalanceError,
    .get_chip_error = Afe_GetChipError,
};

/**
 * @brief 返回操作集
 * @return 操作集地址
 */
Afe_OpsType* Afe_GetOps(void)
{
    return &Afe_valOps_Mp;
}
uint32 sleep_Count = 0;
uint8  valFlag_LoseChip_Mp = 0;
extern uint8 valFlag_EnTopoligyInitEnd_Mp; 
/**
 * @brief Tle9015双链路初始化函数
 * @return uint8 返回0表示函数执行成功
 */
uint8 Tle9015_DualChain_Init(void)
{
    uint32 mask_val;      // 用于存储PCVM掩码值
    uint8 temp_num;       // 用于存储温度传感器数量
    uint8 total_dev;      // 用于存储设备总数
    uint8 phy_id;         // 用于存储物理ID
    uint8 port;           // 用于存储端口号
    uint8 seg_cnt;        // 用于存储段计数
    uint8 ret;            // 用于存储返回值
    uint16 Sleep_Timeout;  // 用于存储睡眠超时时间
    uint8 i;              // 用于循环计数
   

    switch(AFE_valDualInitState_Mp)
    {
        
        case AFE_DUAL_CHAIN_WAIT_SLEEP:
            if(1 == valFlag_LoseChip_Mp) {
                Sleep_Timeout = 0x100; 
            }
            else {
                Sleep_Timeout = 0x10;
            }
            sleep_Count++;
            if(sleep_Count >= Sleep_Timeout) {
                AFE_valDualInitState_Mp = AFE_DUAL_CHAIN_TOPOLOPY;
            }
            break;
        case AFE_DUAL_CHAIN_TOPOLOPY:
            
            for(uint8 index_chip = 0; index_chip < TLE9018_CHIP_NUMBER; index_chip++) {
                if(1 == Afe_valDev_Mp.driver.is_offline[index_chip]){
                    Afe_valDev_Mp.driver.is_offline[index_chip] = 0;
                    Afe_valDev_Mp.driver.is_offlinehistory[index_chip] = 1;
                }
            }
            Tle9015_RestErrAndnSleep();
            Tle9015_LineOffTopologyInit(&Afe_valDev_Mp);
            if(valFlag_EnTopoligyInitEnd_Mp == 1)
            {
                AFE_valDualInitState_Mp = AFE_DUAL_CHAIN_ACTIVE_CHIP;
            }
            break;
        case AFE_DUAL_CHAIN_ACTIVE_CHIP:
            Cdd_Afe_UserConfig((void*)&Afe_valDev_Mp);
            total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);
            // Afe_valDev_Mp.inited = 1;

            for(i = 1;i <= total_dev;i++) {
                phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, i);
                port = Tle9015_GetPort(&Afe_valDev_Mp, i);
                Tle9018_ReadSleepStat(&Afe_valDev_Mp, port, phy_id);
            }

            seg_cnt = Afe_valDev_Mp.link_state.segment_count;
            for(i = 0;i < seg_cnt;i++) {
                if(1 == seg_cnt)
                    port = (Afe_valDev_Mp.link_state.segments[0].dev_count > 0) ? 0 : 1;
                else if(2 == seg_cnt)
                    port = i;
                
                Tle9018_ClearAllFaults(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
            }
            AFE_valDualInitState_Mp = AFE_DUAL_CHAIN_CFG_FUNC_1;
            break;
        case AFE_DUAL_CHAIN_CFG_FUNC_1:
            total_dev = Tle9015_GetTotalDevNum(&Afe_valDev_Mp);
            for(i = 1; i <= total_dev; i++) {
                phy_id = Tle9015_GetPhyId(&Afe_valDev_Mp, i);
                port   = Tle9015_GetPort(&Afe_valDev_Mp, i);
                mask_val = Afe_valDev_Mp.driver.cell_mask[i - 1];
                temp_num  = Afe_valDev_Mp.driver.temp_number[i - 1];

                Tle9018_EnablePCVM(&Afe_valDev_Mp, port, phy_id, mask_val);
                Tle9018_EnableExternalTemp(&Afe_valDev_Mp, port, phy_id, temp_num);
            }
            AFE_valDualInitState_Mp = AFE_DUAL_CHAIN_CFG_FUNC_2;
            break;
        case AFE_DUAL_CHAIN_CFG_FUNC_2:
            seg_cnt = Afe_valDev_Mp.link_state.segment_count;
            for(i = 0;i < seg_cnt;i++) {
                if(1 == seg_cnt)
                    port = (Afe_valDev_Mp.link_state.segments[0].dev_count > 0) ? 0 : 1;
                else if(2 == seg_cnt)
                    port = i;
                
                // Tle9018_SetEmmMask(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
                Tle9018_GeneralConfig(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
    #if 0 
                Tle9018_CfgMultiRead(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
    #endif
                Tle9018_SetOvUvThreshold(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
                Tle9018_SetBalCurtThreshold(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
                Tle9018_ClearTmpRefFaults(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
                Tle9018_StartRoundRobin(&Afe_valDev_Mp, port, AFE_DEV_ALL_ID);
            }
            
            Afe_ValOffLineFg_Mp = 0U;
            // AFE_valDualInitState_Mp = AFE_DUAL_CHAIN_CFG_FUNC_3;
            break;
        // case AFE_DUAL_CHAIN_CFG_FUNC_3:

        //     break;
        default:
            break;
    }
    return 0;
}

