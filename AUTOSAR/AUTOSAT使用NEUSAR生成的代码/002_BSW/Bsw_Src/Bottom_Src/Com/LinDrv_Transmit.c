/******************************************************************************
* 文件名称   : LinDrv_Transmit.c
* 作    者   : Liufengyuan
* 生成日期   : 2025-05-22
* 描    述   : LIN驱动发送相关实现文件。
* 版    本   : V0.0
* 修改记录   :
*   2025-05-22 Liufengyuan 初始版本
* 版    本   : V0.1
* 修改记录   :
*   2026-04-28 Liufengyuan 
	1、优化LIN驱动初始化函数，需要配合修改Lin_Cfg.c,将对应的核配置到Lin_CoreMap中
	2、需要配合修改 Lin_LLDriver.c的修改 确保状态切换回来，能够正常发送数据
******************************************************************************/
/****************************** include ***********************************/
#include "LinDrv_Transmit.h"
#include "LinDrv_Transmit_Prv.h"
#include "Lin.h"
#include "Lin_Cfg.h"
#include "string.h"

/******************************* local ***********************************/
static uint8 LT_valRxDataLen_Mp[LINDRV_CH_MAX] 					= {LINDRV_ZERO_VAL};
static uint8 LT_valRxData_Mp[LINDRV_CH_MAX][LINDRV_LEN_MAX]		= {LINDRV_ZERO_VAL};

//******************************* external ***********************************/
extern CONST(Lin_ConfigType,LIN_CONST)LinGlobalConfig;

/******************************* function ***********************************/
/**
 * 函数名称: LINDrv_Init
 * 参数In: void
 * 参数Out: None
 * 返回值: void
 * 描述: LIN驱动初始化函数 该函数用于初始化LIN驱动，配置LIN通道，并唤醒所有通道。
 * 注意: 该函数只需要在配置的核上调用一次，其他核不需要调用。
 */
void LINDrv_Init(void)
{
	Lin_Init(&LinGlobalConfig);
	for(uint8 LT_valInitCnter_Lo = LINDRV_ZERO_VAL;LT_valInitCnter_Lo < LINDRV_CH_MAX;LT_valInitCnter_Lo++)
	{
		Lin_Wakeup(LT_valInitCnter_Lo);
	}
}

/**
 * 函数名称: LINA_MasterSend
 * 参数In: LIN_Data, LIN_ID, LIN_Len, LIN_CsMode
 * 参数Out: None
 * 返回值: Std_ReturnType
 * 描述: 发送LIN主节点消息。
 */
Std_ReturnType LINA_MasterSend(uint8 *LIN_Data, uint8 LIN_ID, uint8 LIN_Len, Lin_CsMode_Str LIN_CsMode)
{
	uint8			LT_valChSel_Lo		= LINDRV_CH0;
	Std_ReturnType	LT_valLinStat_Lo   	= E_OK;
	Lin_PduType 	LT_valLinSndPdu_Lo 	= {LINDRV_ZERO_VAL};

	if((LIN_ID > LINDRV_ID_MAX) || (LIN_Len > LINDRV_LEN_MAX))
	{
		LT_valLinStat_Lo = E_NOT_OK;
	}
	else
	{
		LT_valLinSndPdu_Lo.Pid 		= 	LIN_ID;
		LT_valLinSndPdu_Lo.Cs 		= 	((Lin_FrameCsModelType)LIN_CsMode);
		LT_valLinSndPdu_Lo.Drc 		= 	LIN_FRAMERESPONSE_TX;
		LT_valLinSndPdu_Lo.Dl 		= 	LIN_Len;
		LT_valLinSndPdu_Lo.SduPtr 	= 	&LIN_Data[LINDRV_ZERO_VAL];
		LT_valLinStat_Lo 			= 	Lin_SendFrame(LT_valChSel_Lo,&LT_valLinSndPdu_Lo);
	}

	return LT_valLinStat_Lo;
}
/**
 * 函数名称: LINA_MasterReceive
 * 参数In: LIN_ID, LIN_Len, LIN_CsMode
 * 参数Out: None
 * 返回值: Std_ReturnType
 * 描述: 接收LIN主节点消息。
 */
Std_ReturnType LINA_MasterReceive(uint8 LIN_ID, uint8 LIN_Len, Lin_CsMode_Str LIN_CsMode)
{
	uint8			LT_valChSel_Lo		= LINDRV_CH0;
	Std_ReturnType	LT_valLinStat_Lo	= E_OK;
	Lin_PduType 	LT_valLinSndPdu_Lo	= {LINDRV_ZERO_VAL};

	if((LIN_ID > LINDRV_ID_MAX) || (LIN_Len > LINDRV_LEN_MAX))
	{
		LT_valLinStat_Lo   = E_NOT_OK;
	}
	else
	{
		LT_valRxDataLen_Mp[LT_valChSel_Lo] 			= 	LIN_Len;

		LT_valLinSndPdu_Lo.Pid 		= 	LIN_ID;
		LT_valLinSndPdu_Lo.Cs 		= 	((Lin_FrameCsModelType)LIN_CsMode);
		LT_valLinSndPdu_Lo.Drc 		= 	LIN_FRAMERESPONSE_RX;
		LT_valLinSndPdu_Lo.Dl 		= 	LIN_Len;
		LT_valLinSndPdu_Lo.SduPtr	= 	NULL_PTR;
		LT_valLinStat_Lo 			=	Lin_SendFrame(LT_valChSel_Lo,&LT_valLinSndPdu_Lo);
	}

	return LT_valLinStat_Lo;
}
/**
 * 函数名称: LIN_GetResult
 * 参数In: LIN_Channel
 * 参数Out: LIN_RxInfo
 * 返回值: void
 * 描述: 获取LIN通道的接收结果。
 */
void LIN_GetResult(uint8 LIN_Channel, LIN_RxInfo_Str *LIN_RxInfo)
{
	uint8			LT_valdata_Lo[LINDRV_LEN_MAX]		= {LINDRV_ZERO_VAL};
	uint8			*LT_valP_Lo							= &LT_valdata_Lo[LINDRV_ZERO_VAL];
	uint8			**LT_valDataPtr						= &LT_valP_Lo;
	uint8			LT_valDataAddCnter_Lo				= LINDRV_ZERO_VAL;
	Lin_StatusType	LT_valRetVal_Lo 					= LIN_RX_OK;

	if((LIN_Channel >= LINDRV_CH_MAX) || (LIN_RxInfo == NULL_PTR))
	{
		return;
	}
	else
	{
		LT_valRetVal_Lo = Lin_GetStatus(LIN_Channel, LT_valDataPtr);
		memcpy(&LT_valRxData_Mp[LIN_Channel][LINDRV_ZERO_VAL],*LT_valDataPtr,LT_valRxDataLen_Mp[LIN_Channel]);

		if(LIN_RX_OK == LT_valRetVal_Lo)
		{
			LIN_RxInfo->LIN_RxValid = LINDRV_ONE_VAL;
			LIN_RxInfo->LIN_RxLen 	= LT_valRxDataLen_Mp[LIN_Channel];
			for(LT_valDataAddCnter_Lo = 0;LT_valDataAddCnter_Lo < LINDRV_LEN_MAX;LT_valDataAddCnter_Lo++)
			{
				LIN_RxInfo->LIN_RxData[LT_valDataAddCnter_Lo]  = LT_valRxData_Mp[LIN_Channel][LT_valDataAddCnter_Lo];
			}
		}
		else
		{
			LIN_RxInfo->LIN_RxValid = LINDRV_ZERO_VAL;
		}
	}
}


