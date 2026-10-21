/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DIO
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Dio_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dio MCAL driver.
*
*   @addtogroup Dio
*   @{
*/
/*PRQA S 1752 EOF*/
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Dio_Types.h"
/*=============================SOURCE FILE VERSION INFORMATION==================================*/
#define DIO_CFG_H_VENDOR_ID                     176
#define DIO_CFG_H_MAJOR_VERSION                 4
#define DIO_CFG_H_MINOR_VERSION                 4
#define DIO_CFG_H_patch_VERSION                 0
#define DIO_CFG_H_SW_MAJOR_VERSION              3
#define DIO_CFG_H_SW_MINOR_VERSION              0
#define DIO_CFG_H_SW_PATCH_VERSION              0
/*====================================FILE VERSION CHECKS=======================================*/
#if (DIO_CFG_H_VENDOR_ID != DIO_TYPES_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_CFG_H_VENDOR_ID "
#endif
#if (DIO_CFG_H_MAJOR_VERSION != DIO_TYPES_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_MAJOR_VERSION "
#endif
#if (DIO_CFG_H_MINOR_VERSION != DIO_TYPES_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_MINOR_VERSION "
#endif
#if (DIO_CFG_H_patch_VERSION != DIO_TYPES_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_patch_VERSION "
#endif
#if (DIO_CFG_H_SW_MAJOR_VERSION != DIO_TYPES_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_MAJOR_VERSION "
#endif
#if (DIO_CFG_H_SW_MINOR_VERSION != DIO_TYPES_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_MINOR_VERSION "
#endif
#if (DIO_CFG_H_SW_PATCH_VERSION != DIO_TYPES_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_PATCH_VERSION "
#endif

/*=========================================CONSTANTS============================================*/


#define DIO_DEV_ERROR_DETECT    (STD_OFF)

#define DIO_VERSION_INFO_API    (STD_OFF)

#define DIO_FLIP_CHANNEL_API    (STD_OFF)

#define DIO_MASKEDWRITEPORT_API (STD_OFF)

#define DIO_READZERO_UNDEFINEDPORTS (STD_ON)

#define DIO_MULTICORE_SUPPORT (STD_OFF)
 
#define DIO_NUM_PORTS_U16 (uint16)(24)

#define DIO_NUM_CHANNELS_RIDE_PORT_U16 (uint16)0x10U

#define DIO_ZERO_U16 ((Dio_PortLevelType)0x0U)

#define DIO_NUM_CHANNELS_U16     ((uint16)DIO_NUM_PORTS_U16 * DIO_NUM_CHANNELS_RIDE_PORT_U16)

#define DIO_PRECOMPILE_SUPPORT



#define ncoreid  0

#define DIO_INLINE    LOCAL_INLINE

#define DIO_OFFSET_MAX_VALID_U8 ((uint8)0x1FU)

extern CONST(Dio_PortLevelType, DIO_CONST) Dio_ReadAvailablePins[DIO_NUM_PORTS_U16];
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_WriteAvailablePins[DIO_NUM_PORTS_U16];
extern CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC;


/**
* @brief          Symbolic name for the port DioPort_B.
*
*/
#define DioConf_DioPort_DioPort_B  ((uint8)0x01U)
#define DioConf_DioPort_Group_DioPort_B  ((uint8)0x01U)


/**
* @brief          Symbolic name for the port MCU_OPA_OCP_LS.
*/
#define DioConf_DioChannel_MCU_OPA_OCP_LS ((uint16)27U)


/**
* @brief          Symbolic name for the port MCU_OPA_OCP_HS.
*/
#define DioConf_DioChannel_MCU_OPA_OCP_HS ((uint16)31U)


/**
* @brief          Symbolic name for the port MCU_CAN5_STB.
*/
#define DioConf_DioChannel_MCU_CAN5_STB ((uint16)28U)




/**
* @brief          Symbolic name for the port DioPort_D.
*
*/
#define DioConf_DioPort_DioPort_D  ((uint8)0x03U)
#define DioConf_DioPort_Group_DioPort_D  ((uint8)0x03U)


/**
* @brief          Symbolic name for the port IN_CH11.
*/
#define DioConf_DioChannel_IN_CH11 ((uint16)48U)


/**
* @brief          Symbolic name for the port IN_CH9.
*/
#define DioConf_DioChannel_IN_CH9 ((uint16)49U)


/**
* @brief          Symbolic name for the port IN_CH2.
*/
#define DioConf_DioChannel_IN_CH2 ((uint16)51U)


/**
* @brief          Symbolic name for the port IN_CH14.
*/
#define DioConf_DioChannel_IN_CH14 ((uint16)53U)


/**
* @brief          Symbolic name for the port IN_CH8.
*/
#define DioConf_DioChannel_IN_CH8 ((uint16)57U)


/**
* @brief          Symbolic name for the port IN_CH12.
*/
#define DioConf_DioChannel_IN_CH12 ((uint16)58U)


/**
* @brief          Symbolic name for the port IN_CH7.
*/
#define DioConf_DioChannel_IN_CH7 ((uint16)59U)


/**
* @brief          Symbolic name for the port IN_CH10.
*/
#define DioConf_DioChannel_IN_CH10 ((uint16)60U)


/**
* @brief          Symbolic name for the port IN_CH13.
*/
#define DioConf_DioChannel_IN_CH13 ((uint16)61U)


/**
* @brief          Symbolic name for the port IN_CH1.
*/
#define DioConf_DioChannel_IN_CH1 ((uint16)62U)




/**
* @brief          Symbolic name for the port DioPort_H.
*
*/
#define DioConf_DioPort_DioPort_H  ((uint8)0x07U)
#define DioConf_DioPort_Group_DioPort_H  ((uint8)0x07U)


/**
* @brief          Symbolic name for the port Dio_9015_ERRQ.
*/
#define DioConf_DioChannel_Dio_9015_ERRQ ((uint16)114U)


/**
* @brief          Symbolic name for the port MCU_D_HS_6.
*/
#define DioConf_DioChannel_MCU_D_HS_6 ((uint16)115U)


/**
* @brief          Symbolic name for the port MCU_D_HS_7.
*/
#define DioConf_DioChannel_MCU_D_HS_7 ((uint16)116U)


/**
* @brief          Symbolic name for the port MCU_D_HS_2.
*/
#define DioConf_DioChannel_MCU_D_HS_2 ((uint16)118U)


/**
* @brief          Symbolic name for the port MCU_D_HS_4.
*/
#define DioConf_DioChannel_MCU_D_HS_4 ((uint16)121U)


/**
* @brief          Symbolic name for the port MCU_D_HS_5.
*/
#define DioConf_DioChannel_MCU_D_HS_5 ((uint16)122U)


/**
* @brief          Symbolic name for the port MCU_D_HS_10.
*/
#define DioConf_DioChannel_MCU_D_HS_10 ((uint16)123U)


/**
* @brief          Symbolic name for the port MCU_D_HS_1.
*/
#define DioConf_DioChannel_MCU_D_HS_1 ((uint16)124U)


/**
* @brief          Symbolic name for the port MCU_D_HS_8.
*/
#define DioConf_DioChannel_MCU_D_HS_8 ((uint16)125U)


/**
* @brief          Symbolic name for the port MCU_D_HS_3.
*/
#define DioConf_DioChannel_MCU_D_HS_3 ((uint16)126U)




/**
* @brief          Symbolic name for the port DioPort_I.
*
*/
#define DioConf_DioPort_DioPort_I  ((uint8)0x08U)
#define DioConf_DioPort_Group_DioPort_I  ((uint8)0x08U)


/**
* @brief          Symbolic name for the port MCU_SEPIC_PG.
*/
#define DioConf_DioChannel_MCU_SEPIC_PG ((uint16)132U)


/**
* @brief          Symbolic name for the port MCU_DI_9015_ERR_EXT_OUT.
*/
#define DioConf_DioChannel_MCU_DI_9015_ERR_EXT_OUT ((uint16)137U)


/**
* @brief          Symbolic name for the port MCU_DI_9015_ERR_LOC_OUT.
*/
#define DioConf_DioChannel_MCU_DI_9015_ERR_LOC_OUT ((uint16)139U)


/**
* @brief          Symbolic name for the port MCU_DO_9015_ERRQ_RES.
*/
#define DioConf_DioChannel_MCU_DO_9015_ERRQ_RES ((uint16)135U)


/**
* @brief          Symbolic name for the port MCU_DO_9015_SLEEP.
*/
#define DioConf_DioChannel_MCU_DO_9015_SLEEP ((uint16)136U)


/**
* @brief          Symbolic name for the port MCU_DO_9015_ERRQ_EXT.
*/
#define DioConf_DioChannel_MCU_DO_9015_ERRQ_EXT ((uint16)138U)




/**
* @brief          Symbolic name for the port DioPort_L.
*
*/
#define DioConf_DioPort_DioPort_L  ((uint8)0x0bU)
#define DioConf_DioPort_Group_DioPort_L  ((uint8)0x0bU)


/**
* @brief          Symbolic name for the port MCU_BOT_UV.
*/
#define DioConf_DioChannel_MCU_BOT_UV ((uint16)189U)


/**
* @brief          Symbolic name for the port MCU_TOP_UV.
*/
#define DioConf_DioChannel_MCU_TOP_UV ((uint16)191U)


/**
* @brief          Symbolic name for the port MCU_PWM_OUT_FB8.
*/
#define DioConf_DioChannel_MCU_PWM_OUT_FB8 ((uint16)176U)


/**
* @brief          Symbolic name for the port MCU_PWM_OUT_FB7.
*/
#define DioConf_DioChannel_MCU_PWM_OUT_FB7 ((uint16)177U)


/**
* @brief          Symbolic name for the port MCU_PWM_OUT_CON9.
*/
#define DioConf_DioChannel_MCU_PWM_OUT_CON9 ((uint16)178U)


/**
* @brief          Symbolic name for the port MCU_PWM_OUT_FB9.
*/
#define DioConf_DioChannel_MCU_PWM_OUT_FB9 ((uint16)179U)


/**
* @brief          Symbolic name for the port MCU_SEPIC_EN.
*/
#define DioConf_DioChannel_MCU_SEPIC_EN ((uint16)182U)


/**
* @brief          Symbolic name for the port MCU_UBR_CTL.
*/
#define DioConf_DioChannel_MCU_UBR_CTL ((uint16)183U)


/**
* @brief          Symbolic name for the port MCU_OCPorOV_RST.
*/
#define DioConf_DioChannel_MCU_OCPorOV_RST ((uint16)190U)




/**
* @brief          Symbolic name for the port DioPort_M.
*
*/
#define DioConf_DioPort_DioPort_M  ((uint8)0x0cU)
#define DioConf_DioPort_Group_DioPort_M  ((uint8)0x0cU)


/**
* @brief          Symbolic name for the port MCU_TOP_DESAT_FLT.
*/
#define DioConf_DioChannel_MCU_TOP_DESAT_FLT ((uint16)192U)


/**
* @brief          Symbolic name for the port MCU_BOT_DESAT_FLT.
*/
#define DioConf_DioChannel_MCU_BOT_DESAT_FLT ((uint16)193U)


/**
* @brief          Symbolic name for the port MCU_ASC_FB.
*/
#define DioConf_DioChannel_MCU_ASC_FB ((uint16)195U)


/**
* @brief          Symbolic name for the port MCU_D_HV_5V_PG.
*/
#define DioConf_DioChannel_MCU_D_HV_5V_PG ((uint16)207U)


/**
* @brief          Symbolic name for the port MCU_IGBT_ASC.
*/
#define DioConf_DioChannel_MCU_IGBT_ASC ((uint16)196U)


/**
* @brief          Symbolic name for the port MCU_PWM_BOT_EN.
*/
#define DioConf_DioChannel_MCU_PWM_BOT_EN ((uint16)197U)


/**
* @brief          Symbolic name for the port MCU_PWM_TOP_EN.
*/
#define DioConf_DioChannel_MCU_PWM_TOP_EN ((uint16)198U)


/**
* @brief          Symbolic name for the port MCU_IGBT_H_RST.
*/
#define DioConf_DioChannel_MCU_IGBT_H_RST ((uint16)199U)




/**
* @brief          Symbolic name for the port DioPort_N.
*
*/
#define DioConf_DioPort_DioPort_N  ((uint8)0x0dU)
#define DioConf_DioPort_Group_DioPort_N  ((uint8)0x0dU)


/**
* @brief          Symbolic name for the port MCU_Power_INT.
*/
#define DioConf_DioChannel_MCU_Power_INT ((uint16)209U)


/**
* @brief          Symbolic name for the port Power_SS1.
*/
#define DioConf_DioChannel_Power_SS1 ((uint16)210U)


/**
* @brief          Symbolic name for the port MCU_IMU_INT2.
*/
#define DioConf_DioChannel_MCU_IMU_INT2 ((uint16)213U)


/**
* @brief          Symbolic name for the port MCU_IMU_INT1.
*/
#define DioConf_DioChannel_MCU_IMU_INT1 ((uint16)214U)


/**
* @brief          Symbolic name for the port MCU_HB_FAULT_N.
*/
#define DioConf_DioChannel_MCU_HB_FAULT_N ((uint16)220U)


/**
* @brief          Symbolic name for the port MCU_D_HV_5V_EN.
*/
#define DioConf_DioChannel_MCU_D_HV_5V_EN ((uint16)208U)


/**
* @brief          Symbolic name for the port MCU_IMU_EN.
*/
#define DioConf_DioChannel_MCU_IMU_EN ((uint16)211U)


/**
* @brief          Symbolic name for the port MCU_D_1V8_EN.
*/
#define DioConf_DioChannel_MCU_D_1V8_EN ((uint16)212U)


/**
* @brief          Symbolic name for the port MCU_D_HB_IN0.
*/
#define DioConf_DioChannel_MCU_D_HB_IN0 ((uint16)217U)


/**
* @brief          Symbolic name for the port MCU_D_HB_IN1.
*/
#define DioConf_DioChannel_MCU_D_HB_IN1 ((uint16)218U)


/**
* @brief          Symbolic name for the port MCU_D_HB_EN.
*/
#define DioConf_DioChannel_MCU_D_HB_EN ((uint16)219U)




/**
* @brief          Symbolic name for the port DioPort_K.
*
*/
#define DioConf_DioPort_DioPort_K  ((uint8)0x0aU)
#define DioConf_DioPort_Group_DioPort_K  ((uint8)0x0aU)


/**
* @brief          Symbolic name for the port MCU_PWM_OUT_CON8.
*/
#define DioConf_DioChannel_MCU_PWM_OUT_CON8 ((uint16)175U)




/**
* @brief          Symbolic name for the port DioPort_C.
*
*/
#define DioConf_DioPort_DioPort_C  ((uint8)0x02U)
#define DioConf_DioPort_Group_DioPort_C  ((uint8)0x02U)


/**
* @brief          Symbolic name for the port MCU_CAN6_STB.
*/
#define DioConf_DioChannel_MCU_CAN6_STB ((uint16)33U)


/**
* @brief          Symbolic name for the port MCU_CAN3_STB.
*/
#define DioConf_DioChannel_MCU_CAN3_STB ((uint16)38U)


/**
* @brief          Symbolic name for the port MCU_CAN4_STB.
*/
#define DioConf_DioChannel_MCU_CAN4_STB ((uint16)43U)


/**
* @brief          Symbolic name for the port MCU_OPA_EN.
*/
#define DioConf_DioChannel_MCU_OPA_EN ((uint16)47U)


/**
* @brief          Symbolic name for the port MCU_D_Driver_5V_EN.
*/
#define DioConf_DioChannel_MCU_D_Driver_5V_EN ((uint16)39U)


/**
* @brief          Symbolic name for the port MCU_D_CAN_5V_EN.
*/
#define DioConf_DioChannel_MCU_D_CAN_5V_EN ((uint16)40U)




/**
* @brief          Symbolic name for the port DioPort_E.
*
*/
#define DioConf_DioPort_DioPort_E  ((uint8)0x04U)
#define DioConf_DioPort_Group_DioPort_E  ((uint8)0x04U)


/**
* @brief          Symbolic name for the port MCU_LIN_EN.
*/
#define DioConf_DioChannel_MCU_LIN_EN ((uint16)68U)


/**
* @brief          Symbolic name for the port MCU_D_LS_3.
*/
#define DioConf_DioChannel_MCU_D_LS_3 ((uint16)75U)


/**
* @brief          Symbolic name for the port MCU_D_LS_2.
*/
#define DioConf_DioChannel_MCU_D_LS_2 ((uint16)76U)


/**
* @brief          Symbolic name for the port MCU_D_LS_4.
*/
#define DioConf_DioChannel_MCU_D_LS_4 ((uint16)77U)


/**
* @brief          Symbolic name for the port MCU_D_LS_1.
*/
#define DioConf_DioChannel_MCU_D_LS_1 ((uint16)78U)




/**
* @brief          Symbolic name for the port DioPort_F.
*
*/
#define DioConf_DioPort_DioPort_F  ((uint8)0x05U)
#define DioConf_DioPort_Group_DioPort_F  ((uint8)0x05U)


/**
* @brief          Symbolic name for the port MCU_D_HS3and9_DSEL.
*/
#define DioConf_DioChannel_MCU_D_HS3and9_DSEL ((uint16)90U)


/**
* @brief          Symbolic name for the port MCU_D_HS2and8_DSEL.
*/
#define DioConf_DioChannel_MCU_D_HS2and8_DSEL ((uint16)92U)


/**
* @brief          Symbolic name for the port MCU_D_HS1and7_DSEL.
*/
#define DioConf_DioChannel_MCU_D_HS1and7_DSEL ((uint16)94U)




/**
* @brief          Symbolic name for the port DioPort_G.
*
*/
#define DioConf_DioPort_DioPort_G  ((uint8)0x06U)
#define DioConf_DioPort_Group_DioPort_G  ((uint8)0x06U)


/**
* @brief          Symbolic name for the port MCU_D_HS_9.
*/
#define DioConf_DioChannel_MCU_D_HS_9 ((uint16)97U)


/**
* @brief          Symbolic name for the port MCU_D_HS5and6_DSEL.
*/
#define DioConf_DioChannel_MCU_D_HS5and6_DSEL ((uint16)101U)


/**
* @brief          Symbolic name for the port MCU_D_HS4and10_DSEL.
*/
#define DioConf_DioChannel_MCU_D_HS4and10_DSEL ((uint16)102U)


/**
* @brief          Symbolic name for the port MCU_CAN7_STB.
*/
#define DioConf_DioChannel_MCU_CAN7_STB ((uint16)111U)




/**
* @brief          Symbolic name for the port DioPort_P.
*
*/
#define DioConf_DioPort_DioPort_P  ((uint8)0x0fU)
#define DioConf_DioPort_Group_DioPort_P  ((uint8)0x0fU)


/**
* @brief          Symbolic name for the port MCU_Power_WDI.
*/
#define DioConf_DioChannel_MCU_Power_WDI ((uint16)244U)




/**
* @brief          Symbolic name for the port DioPort_Q.
*
*/
#define DioConf_DioPort_DioPort_Q  ((uint8)0x10U)
#define DioConf_DioPort_Group_DioPort_Q  ((uint8)0x10U)




/**
* @brief          Symbolic name for the port DioPort_U.
*
*/
#define DioConf_DioPort_DioPort_U  ((uint8)0x14U)
#define DioConf_DioPort_Group_DioPort_U  ((uint8)0x14U)


/**
* @brief          Symbolic name for the port F_VPRE_PG.
*/
#define DioConf_DioChannel_F_VPRE_PG ((uint16)323U)




/**
* @brief          Symbolic name for the port DioPort_J.
*
*/
#define DioConf_DioPort_DioPort_J  ((uint8)0x09U)
#define DioConf_DioPort_Group_DioPort_J  ((uint8)0x09U)


/**
* @brief          Symbolic name for the port MCU_PWM_EN.
*/
#define DioConf_DioChannel_MCU_PWM_EN ((uint16)145U)


/**
* @brief          Symbolic name for the port MCU_79600_FAULT_IN.
*/
#define DioConf_DioChannel_MCU_79600_FAULT_IN ((uint16)144U)





extern CONST(Dio_ChannelType, DIO_CONST) channel_index[DIO_NUM_CHANNELS_U16];
extern CONST(Dio_PortType, DIO_CONST) port_index[DIO_NUM_PORTS_U16];





#endif  /* DIO_CFG_H */
