/******************************************************************************
* 文件名称   : LinDrv_Transmit_Prv.h
* 作    者   : Liufengyuan
* 生成日期   : 2025-05-22
* 描    述   : LIN驱动发送私有头文件，包含宏定义及接口声明。
* 版    本   : V0.0
* 修改记录   :
*   2025-05-22 Liufengyuan 初始版本
******************************************************************************/
#ifndef __LINDRV_TRANSMIT_PRV_H_
#define __LINDRV_TRANSMIT_PRV_H_

#include "LinDrv_Transmit.h"
#include "Lin.h"
#include "Lin_Cfg.h"
/*********************************** Macro *************************************/
#define LINDRV_CH0				(0U)
#define LINDRV_CH_MAX           (1U)

#define LINDRV_ZERO_VAL			(0U)
#define LINDRV_ONE_VAL			(1U)

#define LINDRV_LEN_MAX			(8U)
#define LINDRV_ID_MAX			(0x3fU)

extern VAR(Lin_CoreMapItemType, GPT_CONST) Lin_CoreMap[LIN_HW_MAX_MODULES];
/********************************** Function ************************************/
/**
 * 函数名称: LINDrv_Init
 * 参数In: void
 * 参数Out: None
 * 返回值: void
 * 描述: LIN驱动初始化
 */
extern void LINDrv_Init(void);

#endif /*__LINDRV_TRANSMIT_PRV_H_*/
