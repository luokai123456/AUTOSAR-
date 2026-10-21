/*** create info ***************************************************************
*@ File name: LinDrv_Transmit.h
*@ Author : liufengyuan 
*@ date :2025-04-27
*@ Description : 描述本文件实现功能
**** modify info ***************************************************************
*@ version :0.0
*@ Modifier : liufengyuan 
*@ date :2025-04-27
*@ Modification Description : 初始版本
********************************************************************************/
#ifndef __LINDRV_TRANSMIT_H_
#define __LINDRV_TRANSMIT_H_

#include "StandardTypes.h"

typedef enum{
	Lin_Csmode_Enhanced,
	Lin_Csmode_Classic
}Lin_CsMode_Str;

typedef struct{
	uint8 LIN_RxValid	:	1;
	uint8 LIN_RxLen  	: 	6;
	uint8 LIN_Reserved	:	1;
	uint8 LIN_RxData[8];
}LIN_RxInfo_Str;

/* LIN运行在那个核 0:0核 1:1核 2:2核 3:3核 */
extern const uint8 LT_valLinCoreId_Mp;

extern Std_ReturnType LINA_MasterSend(uint8 *LIN_Data, uint8 LIN_ID, uint8 LIN_Len, Lin_CsMode_Str LIN_CsMode);
extern Std_ReturnType LINA_MasterReceive(uint8 LIN_ID, uint8 LIN_Len, Lin_CsMode_Str LIN_CsMode);
extern void LIN_GetResult(uint8 LIN_Channel, LIN_RxInfo_Str *LIN_RxInfo);

#endif /*__LINDRV_TRANSMIT_PRV_H_*/
