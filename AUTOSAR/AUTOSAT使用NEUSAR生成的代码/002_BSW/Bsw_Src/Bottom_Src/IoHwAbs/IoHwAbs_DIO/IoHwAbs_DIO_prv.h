/*** create info *******************************************
*@ filename : IoHwAbs_DIO_prv.h 
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :DIO的接口声明
/*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/

#ifndef IOHWABS_DIO_PRV_H
#define IOHWABS_DIO_PRV_H

/********************************************** Include **********************************************/
#include "IoHwAbs_DIO_Cfg.h"
#include "StandardTypes.h"
#include "IoHwAbs_DIO.h"

/***************************************** Macro Definitions *****************************************/
#define DIO_LEVEL_LOW                           STD_LOW
#define DIO_LEVEL_HIGH                          STD_HIGH
#define IoHwAbs_DIO_Invalid_Value               0xFFFF
#define DIO_INVALID_LEVEL                       0xFF
#define DIO_H_SW_FILTER_NUM                     2u
#define DIO_READ_FILTER                         (STD_OFF)

/* ========================== new add Macro ========================== */
#define Dout_Channel_MaxNum							4u
/* ========================== Output Channels ========================== */
/* PWM Output Type */
#define IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON7                   44U
#define IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON8                   45U
#define IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON9                   46U

/* New Output Channels */
#define IOHWABS_DIOCHANNEL_MCU_CAN5_STB                       47U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_6                         48U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_7                         49U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_2                         50U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_4                         51U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_5                         52U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_10                        53U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_1                         54U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_8                         55U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_3                         56U
#define IOHWABS_DIOCHANNEL_MCU_CAN6_STB                       57U
#define IOHWABS_DIOCHANNEL_MCU_CAN3_STB                       58U
#define IOHWABS_DIOCHANNEL_MCU_CAN4_STB                       59U
#define IOHWABS_DIOCHANNEL_MCU_LIN_EN                         60U
#define IOHWABS_DIOCHANNEL_MCU_D_LS_3                         61U
#define IOHWABS_DIOCHANNEL_MCU_D_LS_2                         62U
#define IOHWABS_DIOCHANNEL_MCU_D_LS_4                         63U
#define IOHWABS_DIOCHANNEL_MCU_D_LS_1                         64U
#define IOHWABS_DIOCHANNEL_MCU_D_HS3and9_DSEL                 65U
#define IOHWABS_DIOCHANNEL_MCU_D_HS2and8_DSEL                 66U
#define IOHWABS_DIOCHANNEL_MCU_D_HS1and7_DSEL                 67U
#define IOHWABS_DIOCHANNEL_MCU_D_HS_9                         68U
#define IOHWABS_DIOCHANNEL_MCU_D_HS5and6_DSEL                 69U
#define IOHWABS_DIOCHANNEL_MCU_D_HS4and10_DSEL                70U
#define IOHWABS_DIOCHANNEL_MCU_CAN7_STB                       71U
#define IOHWABS_DIOCHANNEL_MCU_Power_WDI                      72U
#define IOHWABS_DIOCHANNEL_MCU_D_Driver_5V_EN                 73U
#define IOHWABS_DIOCHANNEL_MCU_D_CAN_5V_EN                    74U
#define IOHWABS_DIOCHANNEL_MCU_OPA_EN                         75U
#define IOHWABS_DIOCHANNEL_MCU_PWM_EN                         76U
#define IOHWABS_DIOCHANNEL_MCU_DO_9015_ERRQ_RES               77U
#define IOHWABS_DIOCHANNEL_MCU_DO_9015_SLEEP                 78U
#define IOHWABS_DIOCHANNEL_MCU_DO_9015_ERRQ_EXT              79U
#define IOHWABS_DIOCHANNEL_MCU_SEPIC_EN                      80U
#define IOHWABS_DIOCHANNEL_MCU_UBR_CTL                       81U
#define IOHWABS_DIOCHANNEL_MCU_IGBT_ASC                      82U
#define IOHWABS_DIOCHANNEL_MCU_PWM_BOT_EN                    83U
#define IOHWABS_DIOCHANNEL_MCU_PWM_TOP_EN                    84U
#define IOHWABS_DIOCHANNEL_MCU_IGBT_H_RST                    85U    
#define IOHWABS_DIOCHANNEL_MCU_D_HV_5V_EN                    86U
#define IOHWABS_DIOCHANNEL_MCU_IMU_EN                        87U
#define IOHWABS_DIOCHANNEL_MCU_D_1V8_EN                      88U
#define IOHWABS_DIOCHANNEL_MCU_D_HB_IN0                      89U
#define IOHWABS_DIOCHANNEL_MCU_D_HB_IN1                      90U
#define IOHWABS_DIOCHANNEL_MCU_D_HB_EN                       91U



#define IoHwAbs_DioChannelNum   99

#define IOHWABS_DIO_GTM_CHANNEL_MAP_SIZE        18
/****************************************** External Varibles *****************************************/
typedef struct
{
    uint8                   DIO_ActFlag;
    uint8                  DIO_ChnLevel;
} Dio_StInfo_TDSTR;

/********************************************* Function *********************************************/
/**
 * 函数名称: IoHwAbs_DIO_SetChannelValue
 * 参数in: 通道 IOHWABS_DIOCHANNEL_MCU_HS_IN0~IOHWABS_DIOCHANNEL_MCU_HS_IN1
 * 参数out: 0：不输出 1：输出
 * 返回值: retVal：执行成功与否
 * 描述: 设置DIO通道输出与否
 */
extern Std_ReturnType IoHwAbs_DIO_SetChannelValue(uint16 channel, boolean writeLevel);
extern const Dio_IndexConfigParams_TDSTR Dio_IdxConfig_STR[IoHwAbs_DioChannelNum];
 
extern const Dio_GtmChannelMapType_TDSTR Dio_GtmChannelMap_STR[];
extern Std_ReturnType IoHwAbs_DIO_GetPwmChannelValue(uint16 channel, boolean *readLevel);
extern void IoHwAbs_DIO_MainFunction(void);
extern uint8 Dio_fgLs1DisOutput_Mp;
extern uint8 Dio_fgLs2DisOutput_Mp;
extern uint8 Dio_fgLs3DisOutput_Mp;
extern uint8 Dio_fgLs4DisOutput_Mp;

#endif/*IOHWABS_DIO_PRV_H*/




