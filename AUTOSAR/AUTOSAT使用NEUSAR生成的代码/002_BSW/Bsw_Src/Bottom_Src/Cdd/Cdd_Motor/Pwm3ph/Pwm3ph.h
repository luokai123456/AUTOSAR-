/****************************************************************
 * 模块：Cdd层 - PWM3相驱动模块模块
 * 版本：主版本.次版本.修订号
 * ==================== 修改记录 ====================
 * V0.1.0 (初始版本)
 * 1. 支持PWM3相驱动模块控制功能
 * 2. 支持PWM3相驱动模块状态获取功能
 * ==================================================
 ****************************************************************/
#ifndef _PWM3PH_H_
#define _PWM3PH_H_


#include "common.h"
#include "Mcal.h"
#include "Mcu.h"
#include "intc_lld.h"
#include "Gpt_Irq.h"
#include "CCFC3012PT.h"


/*==================== PWM 基础参数配置 ====================*/
#define PWM3PH_Init_FREQ                (10000UL)      /* 初始载波频率（Hz） */
#define PWM3PH_GTM_PWM_CLK              (200UL * 1000UL * 1000UL) /* GTM时钟 200MHz */
#define PWM3PH_PERIOD_CNT               (PWM3PH_GTM_PWM_CLK / PWM3PH_Init_FREQ)
#define PWM3PH_HALF_PERIOD_CNT          (PWM3PH_PERIOD_CNT / 2)

/*==================== 死区时间配置 ====================*/
#define PWM3PH_DEADTIME_US              (3UL)           /* 死区时间 3us */
#define PWM3PH_DEADTIME_CNT             ((PWM3PH_DEADTIME_US * PWM3PH_GTM_PWM_CLK) / 1000000UL) /* 计算值 = 600 */

/*==================== 返回状态 ====================*/
#define PWM_NOT_OK                      0x01U
#define PWM_OK                          0x00U

/*==================== PWM 工作状态 ====================*/
#define Pwm3ph_State_Disable            0x00U   /* 输出禁用 */
#define Pwm3ph_State_Enable             0x01U   /* 正常输出 */
#define Pwm3ph_State_Hasc               0x02U   /* 高边短路 */
#define Pwm3ph_State_Lasc               0x03U   /* 低边短路 */



typedef float float32_t;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct GTM_TOUT_MUX_tag {
    uint16_t TOUT_NUM;
    uint8_t Alt_FUN;
    uint16_t PAD_NUM;
}GTM_TOUT_MUX_t;

typedef struct GTM_SEL_Value_tag {
    uint8_t module;
    uint8_t index;
    uint8_t ch;
    uint8_t inver;
}GTM_SEL_Value_t;

typedef struct GTM_TOUT_SEL_tag {
    uint16_t         TOUT_NUM;
    GTM_SEL_Value_t  SEL_Value[0xC];
}GTM_TOUT_SEL_t;


typedef struct {
    uint8_t           state;
    uint16_t          TOUT_NUM;

}Pwm3ph_Dev_t;

typedef struct 
{
    vuint32_t period_cnt;         // 完整周期计数值
    vuint32_t half_period_cnt;    // 半周期计数值
    uint32_t current_freq;        // 当前频率
    bool initialized;             // 初始化标志
} Pwm3ph_ConfigType;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

extern Pwm3ph_Dev_t Dev1;
extern Pwm3ph_ConfigType g_PwmConfig;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
extern void Pwm3ph_SetPwmAtomCfg(void);
extern uint8_t Pwm3ph_SetPwmDuty(float32_t duty1, float32_t duty2, float32_t duty3);
extern uint8_t Pwm3ph_SetPwmFreq(uint32_t freq);
extern uint32_t Pwm3ph_GetPwmFreq(void);
extern void Pwm3ph_SetPwmState(Pwm3ph_Dev_t * pwmDev, uint8_t stateCmd);
extern void Pwm3ph_SetHasc(Pwm3ph_Dev_t * pwmDev);
extern void Pwm3ph_SetLasc(Pwm3ph_Dev_t * pwmDev);
extern void Pwm3ph_SetSpo(Pwm3ph_Dev_t * pwmDev);
extern void Pwm3ph_Disable(Pwm3ph_Dev_t * pwmDev);
extern void Pwm3ph_Enable(Pwm3ph_Dev_t * pwmDev);
extern void Pwm3ph_SetPwmTimCfg(void);
extern uint32 Pwm3ph_GetTs(void);
extern status_t GTM_LLD_SetToutSel_lld(uint32_t TOUT_NUM,  uint32_t TOUT_SEL);
extern void Foc_Isr_init(void);
extern void PwmOutEnable(uint8 enable);
#endif /* __PWM3PH_H */






