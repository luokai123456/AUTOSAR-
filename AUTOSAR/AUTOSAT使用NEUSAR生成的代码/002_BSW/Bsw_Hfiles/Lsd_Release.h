#ifndef __LSD_RELEASE_H_
#define __LSD_RELEASE_H_

#include "typedefs.h"
#include "Std_Types.h"

/* LS index */
#define EXT_D_LS9_CH1           (0U)
#define EXT_D_LS10_CH2          (1U)
#define EXT_D_LS11_CH3          (2U)
#define EXT_D_LS12_CH4          (3U)

/**
 * @name Cdd_Lsd_AsynSetLevelFunction
 * @brief 低边驱动异步控制函数
 * @param uint16 ValChId，通道，参考LS index
 * @param uint8 Ctr 开关控制，0:Close, 1:Open
 * @return 成功(0)/失败(1)
 */
extern Std_ReturnType Cdd_Lsd_AsynSetLevelFunction(uint16 ValChId, uint8 Ctr);

/**
 * @name Cdd_Lsd_SetLevelFunction
 * @brief 低边驱动同步步控制函数
 * @param uint16 ValChId，通道，参考LS index
 * @param uint8 Ctr 开关控制，0:Close, 1:Open
 * @return 成功(0)/失败(1)
 */
extern Std_ReturnType Cdd_Lsd_SetLevelFunction(uint16 ValChId, uint8 Ctr);

#endif /* __LSD_RELEASE_H_ */
