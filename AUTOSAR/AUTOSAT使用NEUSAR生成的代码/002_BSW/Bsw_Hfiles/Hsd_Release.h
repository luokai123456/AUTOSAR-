#ifndef __HSD_RELEASE_H_
#define __HSD_RELEASE_H_

#include "typedefs.h"
#include "Std_Types.h"

/* HS index */
#define EXT_D_HS_CH_1           (0U)
#define EXT_D_HS_CH_2           (1U)
#define EXT_D_HS_CH_3           (2U)
#define EXT_D_HS_CH_4           (3U)
#define EXT_D_HS_CH_5           (4U)
#define EXT_D_HS_CH_6           (5U)
#define EXT_D_HS_CH_7           (6U)   
#define EXT_D_HS_CH_8           (7U)
#define EXT_D_HS_CH_9           (8U)
#define EXT_D_HS_CH_10          (9U)
/**
 * @name Cdd_Hsd_AsynSetLevelFunction
 * @brief 高边驱动异步控制函数
 * @param uint8 ValChId，通道，参考HS index
 * @param uint32 Ctr 开关控制，0:Close, 1:Open
 * @return 成功(0)/失败(1)
 */
extern Std_ReturnType Cdd_Hsd_AsynSetLevelFunction(uint16 ValChId,uint8 Ctr);

/**
 * @name Cdd_Hsd_SetLevelFunction
 * @brief 高边驱动同步控制函数
 * @param uint8 ValChId，通道，参考HS index
 * @param uint32 Ctr 开关控制，0:Close, 1:Open
 * @return 成功(0)/失败(1)
 */
extern Std_ReturnType Cdd_Hsd_SetLevelFunction(uint16 ValChId,uint8 Ctr);


#endif /* __HSD_RELEASE_H_ */
