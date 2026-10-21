/*** create info *******************************************
*@ filename : IoHwAbs_DIO_Cfg.h 
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :DIO的相关配置
**** modify info *******************************************
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/
#ifndef IOHWABS_DIO_CFG_H
#define IOHWABS_DIO_CFG_H

/********************************************** Include **********************************************/
#include "Dio.h"
#include "Std_Types.h"
/***************************************** Macro Definitions *****************************************/


/* DIO Channel IDs */





/****************************************** Types Definition ******************************************/
/**
 * 结构体名称: Dio_Type_TDEM
 * 描述: DIO类型
 */

typedef enum
{
    IoHwAbs_Dio_Input = 0,
    IoHwAbs_Dio_Output,
    IoHwAbs_Dio_InOut,
} Dio_Type_TDEM;


/**
 * 结构体名称: Dio_IndexConfigParams_TDSTR
 * 描述: DIO索引参数配置
 */
typedef struct
{
    Dio_Type_TDEM            IoHwAbs_IO_Type_EM;
    uint16                   IoHwAbs_DIO_Index;
    uint16                   Initial_DIO_Index;
} Dio_IndexConfigParams_TDSTR;


typedef struct
{
    uint16 channel;      /* 通道号 */
    uint8 timIndex;      /* GTM TIM索引 */
    uint8 channelIndex;  /* TIM通道索引 */
} Dio_GtmChannelMapType_TDSTR;

#endif /* IOHWABS_DIO_CFG_H */
