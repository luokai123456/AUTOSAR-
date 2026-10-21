/****************************************************************
 * 模块：Cdd层 - 电机诊断模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持电机诊断模块初始化功能
 * 2. 支持电机诊断功能阈值设置
 * 3. 支持电机诊断功能故障状态获取功能
*  V0.2.0 
 * 1. 新增四个故障标志状态获取函数
 * ==================================================
 ****************************************************************/
#ifndef _MOTOR_DIAG_H_
#define _MOTOR_DIAG_H_

#include "Platform_Types.h"
#include "status.h"
#include "typedefs.h"



// 诊断初始化函数
extern void Motor_Diag_Init(void);
extern void Diag_TIM_Isr_Init(void);
extern uint8_t Motor_InitDiagThresholds(void);

// 清除所有故障标志
extern void Motor_Diag_ClearAllFaults(void);


// 故障状态获取函数
extern uint8_t Motor_Get_U_HsFault(void);
extern uint8_t Motor_Get_U_LsFault(void);
extern uint8_t Motor_Get_V_HsFault(void);
extern uint8_t Motor_Get_V_LsFault(void);
extern uint8_t Motor_Get_W_HsFault(void);
extern uint8_t Motor_Get_W_LsFault(void);
extern uint8_t Motor_Get_U_OverCurrent(void);
extern uint8_t Motor_Get_V_OverCurrent(void);
extern uint8_t Motor_Get_W_OverCurrent(void);
extern uint8_t Motor_Get_OverVoltage1(void);
extern uint8_t Motor_Get_OverVoltage2(void);
extern uint8_t Motor_Get_TOPDesatFlt(void);
extern uint8_t Motor_Get_BOTDesatFlt(void);
extern uint8_t Motor_Get_TOP_UV(void);
extern uint8_t Motor_Get_BOT_UV(void);
extern void Motor_Diag_DIOMainFunction(void);
extern void Motor_DiagOverCorV_Reset(uint8 enable);


#endif /* __MOTOR_DIAG_H_ */




