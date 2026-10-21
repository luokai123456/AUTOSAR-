/*** create info *******************************************
*@ filename : IoHwAbs_DIO_Cfg.c 
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

/********************************************** Include **********************************************/
#include "IoHwAbs_DIO_Cfg.h"
#include "Dio_Cfg.h"
#include "IoHwAbs_Dio_prv.h"

/******************************************* Global Varibles ******************************************/
const Dio_IndexConfigParams_TDSTR Dio_IdxConfig_STR[IoHwAbs_DioChannelNum] =
{
    /* Input Channels */
    /* IN_CHx Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH1,              DioConf_DioChannel_IN_CH1},/* IN_CH1 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH2,              DioConf_DioChannel_IN_CH2},/* IN_CH2 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH7,              DioConf_DioChannel_IN_CH7},/* IN_CH7 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH8,              DioConf_DioChannel_IN_CH8},/* IN_CH8 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH9,              DioConf_DioChannel_IN_CH9},/* IN_CH9 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH10,             DioConf_DioChannel_IN_CH10},/* IN_CH10 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH11,             DioConf_DioChannel_IN_CH11},/* IN_CH11 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH12,             DioConf_DioChannel_IN_CH12},/* IN_CH12 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH13,             DioConf_DioChannel_IN_CH13},/* IN_CH13 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_IN_CH14,             DioConf_DioChannel_IN_CH14},/* IN_CH14 */
    
    /* Power Related Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_Power_INT,       DioConf_DioChannel_MCU_Power_INT},/* MCU_Power_INT */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_Power_SS1,           DioConf_DioChannel_Power_SS1},/* Power_SS1 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_SEPIC_PG,        DioConf_DioChannel_MCU_SEPIC_PG},/* MCU_SEPIC_PG */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_D_HV_5V_PG,      DioConf_DioChannel_MCU_D_HV_5V_PG},/* MCU_D_HV_5V_PG */
    
    /* IMU Related Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_IMU_INT1,        DioConf_DioChannel_MCU_IMU_INT1},/* MCU_IMU_INT1 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_IMU_INT2,        DioConf_DioChannel_MCU_IMU_INT2},/* MCU_IMU_INT2 */
    
    /* OPA Related Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_OPA_OCP_LS,      DioConf_DioChannel_MCU_OPA_OCP_LS},/* MCU_OPA_OCP_LS */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_OPA_OCP_HS,      DioConf_DioChannel_MCU_OPA_OCP_HS},/* MCU_OPA_OCP_HS */
    
    /* 9015 Related Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_Dio_9015_ERRQ,       DioConf_DioChannel_Dio_9015_ERRQ},/* Dio_9015_ERRQ */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_DI_9015_ERR_EXT_OUT, DioConf_DioChannel_MCU_DI_9015_ERR_EXT_OUT},/* MCU_DI_9015_ERR_EXT_OUT */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_DI_9015_ERR_LOC_OUT, DioConf_DioChannel_MCU_DI_9015_ERR_LOC_OUT},/* MCU_DI_9015_ERR_LOC_OUT */
    
    /* Fault Detection Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_BOT_UV,          DioConf_DioChannel_MCU_BOT_UV},/* MCU_BOT_UV */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_TOP_UV,          DioConf_DioChannel_MCU_TOP_UV},/* MCU_TOP_UV */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_TOP_DESAT_FLT,    DioConf_DioChannel_MCU_TOP_DESAT_FLT},/* MCU_TOP_DESAT_FLT */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_BOT_DESAT_FLT,    DioConf_DioChannel_MCU_BOT_DESAT_FLT},/* MCU_BOT_DESAT_FLT */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_HB_FAULT_N,      DioConf_DioChannel_MCU_HB_FAULT_N},/* MCU_HB_FAULT_N */
    
    /* Other Input Type */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_ASC_FB,          DioConf_DioChannel_MCU_ASC_FB},/* MCU_ASC_FB */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB7,      DioConf_DioChannel_MCU_PWM_OUT_FB7},/* MCU_PWM_OUT_FB7 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB8,      DioConf_DioChannel_MCU_PWM_OUT_FB8},/* MCU_PWM_OUT_FB8 */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_PWM_OUT_FB9,      DioConf_DioChannel_MCU_PWM_OUT_FB9},/* MCU_PWM_OUT_FB9 */
    
    /* New Output Channels */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_CAN5_STB,         DioConf_DioChannel_MCU_CAN5_STB},/* MCU_CAN5_STB */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_6,           DioConf_DioChannel_MCU_D_HS_6},/* MCU_D_HS_6 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_7,           DioConf_DioChannel_MCU_D_HS_7},/* MCU_D_HS_7 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_2,           DioConf_DioChannel_MCU_D_HS_2},/* MCU_D_HS_2 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_4,           DioConf_DioChannel_MCU_D_HS_4},/* MCU_D_HS_4 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_5,           DioConf_DioChannel_MCU_D_HS_5},/* MCU_D_HS_5 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_10,          DioConf_DioChannel_MCU_D_HS_10},/* MCU_D_HS_10 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_1,           DioConf_DioChannel_MCU_D_HS_1},/* MCU_D_HS_1 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_8,           DioConf_DioChannel_MCU_D_HS_8},/* MCU_D_HS_8 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_3,           DioConf_DioChannel_MCU_D_HS_3},/* MCU_D_HS_3 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_CAN6_STB,         DioConf_DioChannel_MCU_CAN6_STB},/* MCU_CAN6_STB */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_CAN3_STB,         DioConf_DioChannel_MCU_CAN3_STB},/* MCU_CAN3_STB */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_CAN4_STB,         DioConf_DioChannel_MCU_CAN4_STB},/* MCU_CAN4_STB */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_LIN_EN,           DioConf_DioChannel_MCU_LIN_EN},/* MCU_LIN_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_LS_3,           DioConf_DioChannel_MCU_D_LS_3},/* MCU_D_LS_3 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_LS_2,           DioConf_DioChannel_MCU_D_LS_2},/* MCU_D_LS_2 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_LS_4,           DioConf_DioChannel_MCU_D_LS_4},/* MCU_D_LS_4 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_LS_1,           DioConf_DioChannel_MCU_D_LS_1},/* MCU_D_LS_1 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS3and9_DSEL,   DioConf_DioChannel_MCU_D_HS3and9_DSEL},/* MCU_D_HS3and9_DSEL */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS2and8_DSEL,   DioConf_DioChannel_MCU_D_HS2and8_DSEL},/* MCU_D_HS2and8_DSEL */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS1and7_DSEL,   DioConf_DioChannel_MCU_D_HS1and7_DSEL},/* MCU_D_HS1and7_DSEL */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS_9,           DioConf_DioChannel_MCU_D_HS_9},/* MCU_D_HS_9 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS5and6_DSEL,   DioConf_DioChannel_MCU_D_HS5and6_DSEL},/* MCU_D_HS5and6_DSEL */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HS4and10_DSEL,  DioConf_DioChannel_MCU_D_HS4and10_DSEL},/* MCU_D_HS4and10_DSEL */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_CAN7_STB,         DioConf_DioChannel_MCU_CAN7_STB},/* MCU_CAN7_STB */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_Power_WDI,        DioConf_DioChannel_MCU_Power_WDI},/* MCU_Power_WDI */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_Driver_5V_EN,   DioConf_DioChannel_MCU_D_Driver_5V_EN},/* MCU_D_Driver_5V_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_CAN_5V_EN,      DioConf_DioChannel_MCU_D_CAN_5V_EN},/* MCU_D_CAN_5V_EN */
    {IoHwAbs_Dio_InOut,    IOHWABS_DIOCHANNEL_MCU_OPA_EN,           DioConf_DioChannel_MCU_OPA_EN},/* MCU_OPA_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_PWM_EN,           DioConf_DioChannel_MCU_PWM_EN},/* MCU_PWM_EN */
    
    /* Output Channels */
    /* PWM Output Type */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON8,     DioConf_DioChannel_MCU_PWM_OUT_CON8},/* MCU_PWM_OUT_CON8 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_PWM_OUT_CON9,     DioConf_DioChannel_MCU_PWM_OUT_CON9},/* MCU_PWM_OUT_CON9 */

    
    /* New Output Channels */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_DO_9015_ERRQ_RES, DioConf_DioChannel_MCU_DO_9015_ERRQ_RES},/* MCU_DO_9015_ERRQ_RES */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_DO_9015_SLEEP,   DioConf_DioChannel_MCU_DO_9015_SLEEP},/* MCU_DO_9015_SLEEP */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_DO_9015_ERRQ_EXT, DioConf_DioChannel_MCU_DO_9015_ERRQ_EXT},/* MCU_DO_9015_ERRQ_EXT */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_SEPIC_EN,        DioConf_DioChannel_MCU_SEPIC_EN},/* MCU_SEPIC_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_UBR_CTL,         DioConf_DioChannel_MCU_UBR_CTL},/* MCU_UBR_CTL */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_IGBT_ASC,        DioConf_DioChannel_MCU_IGBT_ASC},/* MCU_IGBT_ASC */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_PWM_BOT_EN,      DioConf_DioChannel_MCU_PWM_BOT_EN},/* MCU_PWM_BOT_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_PWM_TOP_EN,      DioConf_DioChannel_MCU_PWM_TOP_EN},/* MCU_PWM_TOP_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_IGBT_H_RST,      DioConf_DioChannel_MCU_IGBT_H_RST},/* MCU_IGBT_H_RST */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HV_5V_EN,      DioConf_DioChannel_MCU_D_HV_5V_EN},/* MCU_D_HV_5V_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_IMU_EN,          DioConf_DioChannel_MCU_IMU_EN},/* MCU_IMU_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_1V8_EN,        DioConf_DioChannel_MCU_D_1V8_EN},/* MCU_D_1V8_EN */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HB_IN0,        DioConf_DioChannel_MCU_D_HB_IN0},/* MCU_D_HB_IN0 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HB_IN1,        DioConf_DioChannel_MCU_D_HB_IN1},/* MCU_D_HB_IN1 */
    {IoHwAbs_Dio_Output,    IOHWABS_DIOCHANNEL_MCU_D_HB_EN,         DioConf_DioChannel_MCU_D_HB_EN},/* MCU_D_HB_EN */

    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_79600_FAULT_IN,  DioConf_DioChannel_MCU_79600_FAULT_IN},/* MCU_79600_FAULT_IN */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_F_VPRE_PG,            DioConf_DioChannel_F_VPRE_PG},/* F_VPRE_PG */
    {IoHwAbs_Dio_Input,     IOHWABS_DIOCHANNEL_MCU_OCPorOV_RST,     DioConf_DioChannel_MCU_OCPorOV_RST},/* MCU_OCPorOV_RST */

};

const Dio_GtmChannelMapType_TDSTR Dio_GtmChannelMap_STR[] = 
{
    /* Input Channels                               TIM         Chn*/
    {IOHWABS_DIOCHANNEL_PwmIn_CH1            ,   2,           4},
    {IOHWABS_DIOCHANNEL_PwmIn_CH2            ,   2,           6},
    {IOHWABS_DIOCHANNEL_PwmIn_CH3            ,   5,           2},
    {IOHWABS_DIOCHANNEL_PwmIn_CH4            ,   2,           7},
    {IOHWABS_DIOCHANNEL_PwmIn_CH5            ,   5,           1},
    {IOHWABS_DIOCHANNEL_PwmIn_CH6            ,   2,           5},
    {IOHWABS_DIOCHANNEL_PwmIn_CH7            ,   4,           2},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB1_PVF	 ,   4,           4},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB2_PVF	 ,   5,           4},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB3_PVF	 ,   7,           0},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB4_PVF	 ,   4,           5},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB5_PVF	 ,   5,           5},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB6_PVF	 ,   4,           1},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB10_PVF ,   7,           5},
    {IOHWABS_DIOCHANNEL_PwmIn_CH8            ,   5,           0},
    {IOHWABS_DIOCHANNEL_PwmIn_CH9            ,   5,           7},
    {IOHWABS_DIOCHANNEL_ICU_PWM_OUT_FB11_PVF ,   4,           6},
    {IOHWABS_DIOCHANNEL_MCU_DI_OCPorOV_TRIGGER ,   4,           7},
};

