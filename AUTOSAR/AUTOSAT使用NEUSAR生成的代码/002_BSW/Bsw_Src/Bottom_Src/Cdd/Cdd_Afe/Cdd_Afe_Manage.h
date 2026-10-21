#ifndef __CDD_AFE_MANAGE_H_
#define __CDD_AFE_MANAGE_H_

#include "Cdd_Tle9015_Topology.h"

/****************************************************************
 * 模块：Cdd层 - AFE驱动
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 *  1. 修复DMA搬运问题
 *  2. 支持基础采集功能
 * V0.2.0
 *  1. 采集OK
 *  2. 电阻未映射
 *  3. 均衡仍然存在BUG
 * V0.3.0
 *  1. 电阻映射完成
 *  2. 修正激活方式
 *  3. 修复串口使用错误
 * V0.3.1
 *  1. 释放禁用电芯的全局变量
 *  2. 释放禁用温度的全局变量
 *  3. 修改开路阈值
 * V0.3.2
 *  1. 屏蔽ADC Error对均衡的影响
 *  2. 添加代码注释以及头文件注释
 * V0.3.3
 *  1. 勘误
 * V0.3.4
 *  1. 更新AFE个数
 *  2. 修复初始化里面只回调4次的bug
 * V0.3.5
 *  1. 勘误均衡电阻
 *  2. 勘误芯片温度
 *  3. 将电芯/温度采集的配置放回本模块
 * V0.3.6
 *  1. 支持AFE激活
 *  2. 修改初始化位置
 *  3. 修复AFE激活后通信异常问题
 * V0.3.7
 *  1. 增加初始化自检重试机制
 * ==================================================
 ****************************************************************/

#define AFE_VER_MAJOR           0
#define AFE_VER_MINOR           3
#define AFE_VER_PATCH           7
#define AFE_VERSION             ((uint32)AFE_VER_MAJOR << 16 | \
                                (uint32)AFE_VER_MINOR << 8  | \
                                AFE_VER_PATCH)

#define AFE_TOTAL_CELL_NUM      TLE9018_CELL_NUMBER * TLE9018_CHIP_NUMBER
#define AFE_TOTAL_GPIO_NUM      TLE9018_GPIO_NUMBER * TLE9018_CHIP_NUMBER
#define AFE_DEV_NUM             TLE9018_CHIP_NUMBER
#define AFE_DEV_0_ID            1
#define AFE_DEV_1_ID            2
#define AFE_DEV_2_ID            3
#define AFE_DEV_3_ID            4
#define AFE_DEV_4_ID            5
#define AFE_DEV_5_ID            6
#define AFE_DEV_6_ID            7
#define AFE_DEV_7_ID            8
#define AFE_DEV_ALL_ID          0x3F

#define MIN(a, b)  ((a) < (b) ? (a) : (b))

#define AFE_DEV_V_OV_THR        (5)    //单位V   (MIN：0.000V Max：5.0V     )   5V时禁用OV故障
#define AFE_DEV_V_UV_THR        (0)    //单位V   (MIN：0.000V Max：5.0V     )   0V时禁用UV故障
#define AFE_DEV_V_OL_THR_MAX    (799.5)    //单位mV  (MIN：0 mV   Max：1228.5 mV)   0mV时禁用OL故障
#define AFE_DEV_V_OL_THR_MIN    (19.5)    //单位mV  (MIN：0 mV   Max：1228.5 mV)   0mV时禁用OL故障


// ============ 禁用判定 + 钳位保护 ============

// OV：5.0V→禁用(0x3FF)，否则公式计算后钳位防溢出
#define AFE_DEV_OV_THR_CFG      (AFE_DEV_V_OV_THR >= 5.0 ? 0x3FF : \
    MIN((uint16)(AFE_DEV_V_OV_THR * (1024.0 / 5.0) + 0.5), 0x3FF))

// UV：0.0V→禁用(0x000)，否则公式计算
#define AFE_DEV_UV_THR_CFG      (AFE_DEV_V_UV_THR <= 0.0 ? 0x000 : \
    MIN((uint16)(AFE_DEV_V_UV_THR * (1024.0 / 5.0) + 0.5), 0x3FF))

// OL_MAX：0→禁用(0x00)，否则公式计算后钳位到0x3F
#define AFE_DEV_OL_THR_MAX_CFG  (AFE_DEV_V_OL_THR_MAX == 0 ? 0x00 : \
    MIN((uint8)(AFE_DEV_V_OL_THR_MAX / 19.5 + 0.5), 0x3F))

// OL_MIN：0→禁用(0x00)，否则公式计算后钳位到0x3F
#define AFE_DEV_OL_THR_MIN_CFG  (AFE_DEV_V_OL_THR_MIN == 0 ? 0x00 : \
    MIN((uint8)(AFE_DEV_V_OL_THR_MIN / 19.5 + 0.5), 0x3F))

typedef struct {
    uint8 (*get_cell_vol)(uint16*, uint8);
    void (*set_cell_bal)(uint32*, uint8);
    uint8 (*get_bal_status)(uint32*, uint16);
    void (*get_cell_opl)(uint32*, uint8);
    void (*get_temp_opl)(uint32*,uint8);
    void (*get_rist)(uint16*, uint8, uint8);
    void (*get_chiptemp)(float*, uint8);
    void (*get_timeout_status)(uint8*);
    void (*get_is_offline)(uint32*);
    uint32 (*get_balance_error)(uint8);
    void (*get_chip_error)(uint32*);
} Afe_OpsType;

extern Tle9018_DevType* Afe_GetDev(void);
extern Afe_OpsType* Afe_GetOps(void);
extern void Cdd_Afe_MainFunction_10ms(void);
extern void Cdd_Afe_GoToSleep(void);
extern __attribute__((ghs_optimize(Onone))) void Cdd_Afe_InitFunction(void);

#endif /* __CDD_AFE_MANAGE_H_ */
