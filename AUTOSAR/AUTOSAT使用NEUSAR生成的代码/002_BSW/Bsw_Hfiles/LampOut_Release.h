#ifndef __LAMPOUT_RELEASE_H_
#define __LAMPOUT_RELEASE_H_

/* Lamp index */
#define EXT_D_LAMP_CH7          (0U)
#define EXT_D_LAMP_CH8          (1U)
#define EXT_D_LAMP_CH9          (2U)

/**
 * @brief 低边PWM驱动异步控制函数
 * @param uint8 ValChId，通道，参考LS index
 * @param boolean Lsd_ValChLevel，通道电平，参考LS index
 * @return 成功(0)/失败(1)
 */

extern Std_ReturnType Cdd_LampOut_AsynSetLevelFunction(uint16 ValChId, uint8 Ctr);

/**
 * @brief 低边PWM驱动同步控制函数
 * @param uint8 ValChId，通道，参考LS index
 * @param boolean Lsd_ValChLevel，通道电平，参考LS index
 * @return 成功(0)/失败(1)
 */

extern Std_ReturnType Cdd_LampOut_SetLevelFunction(uint16 ValChId, uint8 Ctr);

#endif
