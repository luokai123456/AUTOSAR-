/*** create info *******************************************
*@ filename : IoHwAbs_Dio.h 
*@ Author : pianyongxin 
*@ date :2025-02-12
*@ Description :DIO的接口声明
**** modify info *******************************************
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-12
*@ Modification Description :
初始版本
************************************************************/
#ifndef IOHWABS_DIO_H
#define IOHWABS_DIO_H

/********************************************** Include **********************************************/

#include "Std_Types.h"
/***************************************** Macro Definitions *****************************************/

/* IN_CHx Type */
#define IOHWABS_DIOCHANNEL_IN_CH1                              0U
#define IOHWABS_DIOCHANNEL_IN_CH2                              1U
#define IOHWABS_DIOCHANNEL_IN_CH7                              2U
#define IOHWABS_DIOCHANNEL_IN_CH8                              3U
#define IOHWABS_DIOCHANNEL_IN_CH9                              4U
#define IOHWABS_DIOCHANNEL_IN_CH10                             5U
#define IOHWABS_DIOCHANNEL_IN_CH11                             6U
#define IOHWABS_DIOCHANNEL_IN_CH12                             7U
#define IOHWABS_DIOCHANNEL_IN_CH13                             8U
#define IOHWABS_DIOCHANNEL_IN_CH14                             9U

/* Power Related Type */
#define IOHWABS_DIOCHANNEL_MCU_Power_INT                       10U
#define IOHWABS_DIOCHANNEL_Power_SS1                           11U
#define IOHWABS_DIOCHANNEL_MCU_SEPIC_PG                       12U
#define IOHWABS_DIOCHANNEL_MCU_D_HV_5V_PG                     13U

/* IMU Related Type */
#define IOHWABS_DIOCHANNEL_MCU_IMU_INT1                        14U
#define IOHWABS_DIOCHANNEL_MCU_IMU_INT2                        15U

/* OPA Related Type */
#define IOHWABS_DIOCHANNEL_MCU_OPA_OCP_LS                     16U
#define IOHWABS_DIOCHANNEL_MCU_OPA_OCP_HS                     17U

/* 9015 Related Type */
#define IOHWABS_DIOCHANNEL_Dio_9015_ERRQ                      18U
#define IOHWABS_DIOCHANNEL_MCU_DI_9015_ERR_EXT_OUT            19U
#define IOHWABS_DIOCHANNEL_MCU_DI_9015_ERR_LOC_OUT            20U

/* Fault Detection Type */
#define IOHWABS_DIOCHANNEL_MCU_BOT_UV                         21U
#define IOHWABS_DIOCHANNEL_MCU_TOP_UV                         22U
#define IOHWABS_DIOCHANNEL_MCU_TOP_DESAT_FLT                  23U
#define IOHWABS_DIOCHANNEL_MCU_BOT_DESAT_FLT                  24U
#define IOHWABS_DIOCHANNEL_MCU_HB_FAULT_N                     25U

/* Other Input Type */
#define IOHWABS_DIOCHANNEL_MCU_ASC_FB                         26U
#define IOHWABS_DIOCHANNEL_F_VPRE_PG                           96U
#define IOHWABS_DIOCHANNEL_MCU_79600_FAULT_IN                 97U
#define IOHWABS_DIOCHANNEL_MCU_OCPorOV_RST                    98U

/* New Input Channels */
#define IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB7                    27U
#define IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB8                    28U
#define IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB9                    29U


#define IOHWABS_DIOCHANNEL_PwmIn_CH1                         30U
#define IOHWABS_DIOCHANNEL_PwmIn_CH2                         31U
#define IOHWABS_DIOCHANNEL_PwmIn_CH3                         32U
#define IOHWABS_DIOCHANNEL_PwmIn_CH4                         33U
#define IOHWABS_DIOCHANNEL_PwmIn_CH5                         34U
#define IOHWABS_DIOCHANNEL_PwmIn_CH6                         35U
#define IOHWABS_DIOCHANNEL_PwmIn_CH7                         36U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB1_PVF               37U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB2_PVF               38U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB3_PVF               39U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB4_PVF               40U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB5_PVF               41U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB6_PVF               42U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB10_PVF              43U
#define IOHWABS_DIOCHANNEL_PwmIn_CH8                         92U
#define IOHWABS_DIOCHANNEL_PwmIn_CH9                         93U
#define IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB11_PVF              94U
#define IOHWABS_DIOCHANNEL_MCU_DI_OCPorOV_TRIGGER            95U
/**
 * 函数名称: IoHwAbs_DIO_GetChannelValue
 * 参数in: 通道 IOHWABS_DIOCHANNEL_IN_CH1~IOHWABS_DIOCHANNEL_MCU_HS_IN1
 * 参数out: 0：不输出 1：输出
 * 返回值: retVal：执行成功与否
 * 描述: 获取通道输出状态
 */
extern Std_ReturnType IoHwAbs_DIO_GetChannelValue(uint16 channel, boolean *readLevel);
#endif /* IOHWABS_DIO_H */
