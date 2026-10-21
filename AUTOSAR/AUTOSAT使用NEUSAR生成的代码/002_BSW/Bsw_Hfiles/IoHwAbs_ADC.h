/*** create info *******************************************
*@ filename : IoHwAbs_ADC.h 
*@ Author : pianyongxin 
*@ date :2025-02-24
*@ Description :描述本文件实现功能
/*** modify info ******************************************* 
*@ version :0.0
*@ Modifier : pianyongxin 
*@ date :2025-02-24
*@ Modification Description :
初始版本
************************************************************/
#ifndef IOHWABS_ADC_H_
#define IOHWABS_ADC_H_

/********************************************** Include **********************************************/
/* 头文件 */
#include "StandardTypes.h"
#include "typedefs.h"
/***************************************** Macro Definitions *****************************************/
/* =============================== 输入通道 (IN_) =============================== */
/***************************************** Macro Definitions *****************************************/
/* =============================== 通用模拟输入通道 (IN_ANx / MCU_AN_) =============================== */
/* ADC Channel IDs */
/* ========================== IN_AN Type (Input Analog) ========================== */
#define IOHWABS_ADC_CHANNEL_IN_AN1                  0U
#define IOHWABS_ADC_CHANNEL_IN_AN2                  1U
#define IOHWABS_ADC_CHANNEL_IN_AN3                  2U
#define IOHWABS_ADC_CHANNEL_IN_AN4                  3U
#define IOHWABS_ADC_CHANNEL_IN_AN5                  4U
#define IOHWABS_ADC_CHANNEL_IN_AN6                  5U
#define IOHWABS_ADC_CHANNEL_IN_AN7                  6U
#define IOHWABS_ADC_CHANNEL_IN_AN8                  7U
#define IOHWABS_ADC_CHANNEL_IN_AN9                  8U
#define IOHWABS_ADC_CHANNEL_IN_AN10                 9U
#define IOHWABS_ADC_CHANNEL_IN_AN11                 10U
#define IOHWABS_ADC_CHANNEL_IN_AN12                 11U
#define IOHWABS_ADC_CHANNEL_IN_AN13                 12U
#define IOHWABS_ADC_CHANNEL_IN_AN14                 13U

/* ========================== VDD5REF Type ========================== */
#define IOHWABS_ADC_CHANNEL_VDD5REF1                14U
#define IOHWABS_ADC_CHANNEL_VDD5REF2                15U
#define IOHWABS_ADC_CHANNEL_VDD5REF3                16U
#define IOHWABS_ADC_CHANNEL_VDD5REF4                17U
#define IOHWABS_ADC_CHANNEL_VDD5REF5                18U
#define IOHWABS_ADC_CHANNEL_VDD5REF6                19U
#define IOHWABS_ADC_CHANNEL_VDD5REF7                20U
#define IOHWABS_ADC_CHANNEL_VDD5REF8                21U
#define IOHWABS_ADC_CHANNEL_VDD5REF9                22U
#define IOHWABS_ADC_CHANNEL_VDD5REF10               23U
#define IOHWABS_ADC_CHANNEL_VDD5REF11               24U


/* ========================== Temp Type (Temperature) ========================== */
#define IOHWABS_ADC_CHANNEL_AN_Temp_MCU             25U
#define IOHWABS_ADC_CHANNEL_AN_Temp_SBC             26U
#define IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN1    27U
#define IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN2    28U
#define IOHWABS_ADC_CHANNEL_MCU_AN_TEMP_IGBT_IN3    29U
#define IOHWABS_ADC_CHANNEL_MCU_AN_Motor_TEMP_N     30U
#define IOHWABS_ADC_CHANNEL_MCU_AN_Motor_TEMP_P     31U

/* ========================== HS_DIAG Type (High Side Diagnostics) ========================== */
#define IOHWABS_ADC_CHANNEL_MCU_D_HS1_DIAG          32U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS2_DIAG          33U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS3_DIAG          34U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS4_DIAG          35U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS5_DIAG          36U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS6_DIAG          37U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS7_DIAG          38U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS8_DIAG          39U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS9_DIAG          40U
#define IOHWABS_ADC_CHANNEL_MCU_D_HS10_DIAG         41U

/* ========================== LS_DIAG Type (Low Side Diagnostics) ========================== */
#define IOHWABS_ADC_CHANNEL_MCU_LS_9_DIAG           42U
#define IOHWABS_ADC_CHANNEL_MCU_LS_10_DIAG          43U
#define IOHWABS_ADC_CHANNEL_MCU_LS_11_DIAG          44U
#define IOHWABS_ADC_CHANNEL_MCU_LS_12_DIAG          45U

/* ========================== 5V Sensor Type ========================== */
#define IOHWABS_ADC_CHANNEL_AN_5Vsensor1            46U
#define IOHWABS_ADC_CHANNEL_AN_5Vsensor2            47U

/* ========================== HV/DC Type ========================== */
#define IOHWABS_ADC_CHANNEL_MCU_AN_HV_DC1           48U
#define IOHWABS_ADC_CHANNEL_MCU_AN_HV_DC2           49U
#define IOHWABS_ADC_CHANNEL_AN_DC_APlus1_Mic        50U
#define IOHWABS_ADC_CHANNEL_AN_DC_APlus2_Mic        51U

/* ========================== Driver 5V Type ========================== */
#define IOHWABS_ADC_CHANNEL_AN_HV_Driver_5V         52U
#define IOHWABS_ADC_CHANNEL_AN_Driver_5V            53U
#define IOHWABS_ADC_CHANNEL_AN_CAN_5V               54U

/* ========================== Mic/Key Type ========================== */
#define IOHWABS_ADC_CHANNEL_AN_12_RES_Mic           55U
#define IOHWABS_ADC_CHANNEL_AN_UBR_Mic              56U
#define IOHWABS_ADC_CHANNEL_AN_OBC_ON_Mic           57U
#define IOHWABS_ADC_CHANNEL_AN_CAN_WK_Mic           58U
#define IOHWABS_ADC_CHANNEL_AN_KEY_Mic              59U
#define IOHWABS_ADC_CHANNEL_AN_UBD_Mic              60U
#define IOHWABS_ADC_CHANNEL_AN_OBC_Mic              61U
/* ========================== CFB Type (Current Feedback) ========================== */
#define IOHWABS_ADC_CHANNEL_MCU_AN_HS1and7_CFB      62U
#define IOHWABS_ADC_CHANNEL_MCU_AN_HS2and8_CFB      63U
#define IOHWABS_ADC_CHANNEL_MCU_AN_HS3and9_CFB      64U
#define IOHWABS_ADC_CHANNEL_MCU_AN_HS4and10_CFB     65U
#define IOHWABS_ADC_CHANNEL_MCU_AN_HS5and6_CFB      66U

/* ========================== Other Type ========================== */
#define IOHWABS_ADC_CHANNEL_AN_9015_ERRQ            67U
/* ========================== Other New Type ========================== */
#define IOHWABS_ADC_CHANNEL_AN_1V8                  68U
#define IOHWABS_ADC_CHANNEL_AN_F_V_PRE              69U

/********************************************* Function *********************************************/
/**
 * 函数名称: IoHwAbs_ADC_GetChannelRawValue
 * 参数in: 通道 IOHWABS_ADC_CHANNEL_AN_5VSENSOR1~IOHWABS_ADC_CHANNEL_IN_AN9
 * 参数out: AD值
 * 返回值: RetVal，是否执行成功
 * 描述: 按照通道读AD值
 */
extern Std_ReturnType IoHwAbs_ADC_GetChannelRawValue(uint16 ChIdx, uint16* RawResult);
/**
 * 函数名称: IoHwAbs_ADC_GetChannelValue
 * 参数in: 通道 IOHWABS_ADC_CHANNEL_AN_5VSENSOR1~IOHWABS_ADC_CHANNEL_IN_AN9
 * 参数out: 滤波AD值
 * 返回值: RetVal，是否执行成功
 * 描述: 按照通道读AD滤波值
 */
extern Std_ReturnType IoHwAbs_ADC_GetChannelValue(uint16 ChIdx, uint16* RawResult);


#endif/*IOHWABS_ADC_H*/

