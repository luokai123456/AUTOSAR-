/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Adc
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
*   @file    Adc_Cfg.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/
/* PRQA S 1753 EOF */
#ifndef ADC_CFG_H
#define ADC_CFG_H

#include "Mcal.h"
#include "eDma_LLDriver.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define ADC_VENDOR_ID                    176
#define ADC_AR_REL_MAJOR_VER             4
#define ADC_AR_REL_MINOR_VER             4
#define ADC_AR_REL_REV_VER               0
#define ADC_SW_MAJOR_VER                 3
#define ADC_SW_MINOR_VER                 0
#define ADC_SW_PATCH_VER                 0

#define ADC_MODULE_ID                    123

/*============================================FILE VERSION CHECKS===================================*/

#if (ADC_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (ADC_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MAJOR_VER"
#endif
#if (ADC_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MINOR_VER"
#endif
#if (ADC_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (ADC_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MAJOR_VER"
#endif
#if (ADC_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MINOR_VER"
#endif
#if (ADC_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_PATCH_VER"
#endif


/* @brief Define whether to use a precompiled version   */
#define ADC_PRECOMPILE_SUPPORT              (STD_OFF)

/* @brief  Add/remove Service Adc_DeInit() from Code */
#define ADC_DEINIT_API                      (STD_ON)

/* @brief  Enable/disable development error detection function */
#define ADC_DEV_ERROR_DETECT                (STD_ON)

/* @brief Enable/disable the restriction check function in the ADC driver program */
#define ADC_ENABLE_LIMIT_CHECK              (STD_OFF)

/* @brief Enable/disable queue */
#define ADC_ENABLE_QUEUING                  (STD_OFF)

/* @brief  Add/remove Adc_StartGroupConversion and Adc_TopGroupConversion Service Interfaces */
#define ADC_ENABLE_START_STOP_GROUP_API     (STD_ON)

/* @brief Enable/disable notification mechanism for groups */
#define ADC_GRP_NOTIF_CAPABILITY            (STD_OFF)

/* @brief Add/remove Adc_Enabling HardwareTrigger and Adc_DisableHardwareTrigger service interfaces from the code */
#define ADC_HW_TRIGGER_API                  (STD_ON)

/* @brief Add/remove interfaces related to power status management */
#define ADC_POWER_STATE_SUPPORTED           (STD_OFF)

/* @brief Enable/disable ADC driver support for asynchronous power state transition */
#define ADC_POWER_STATE_ASYNCH_TRANSTION    (STD_OFF)

/* @brief  Add/remove Adc_ReadGroup() service interface from code */
#define ADC_READ_GROUP_API                  (STD_ON)

/* @brief  Add/remove Adc_GetVersions Info() service interface from code */
#define ADC_VERSION_INFO_API                (STD_ON)

/* @brief Enable/disable multi-core related configurations */
#define ADC_ENABLE_MULTICORE                (STD_OFF)

/* @brief Enable/disable Dem error detection function */
#define ADC_DEM_REPORT_ERROR_ENABLE         (STD_OFF)

/* @brief Enable/disable RFFO overflow interrupt */
#define ADC_INT_RFOF_ENABLE                 (STD_OFF)

/* @brief Enable/disable CFIFO to trigger overflow interrupt */
#define ADC_INT_TORF_ENABLE                 (STD_OFF)

/*The inline switch is on*/
#define ADC_INLINE     LOCAL_INLINE

/* @brief ADC VREF Power Supply */
#define ADC_VREF_3V3                        (3U)
#define ADC_VREF_5V                         (5U)
#define ADC_VREF_POWER_SUPPLY               (ADC_VREF_5V)




/* @brief  Select the type of priority mechanism */
#define ADC_PRIORITY_IMPLEMENTATION         (PRIORITY_NONE)

/* @brief The maximum number of channels in a group in a configuration item */
#define ADC_MAX_CHANNEL                     (6U)

/* @brief The maximum number of groups under one unit in the configuration item */
#define ADC_MAX_GROUPS                      (3U)

/* @brief Number of configuration groups */
#define ADC_CONFIG_GROUPS                   (28U)

/* @brief Configure the number of ADC units */
#define ADC_CONFIG_UNIT                     (12U)

/* @brief ADC timeout */
#define ADC_TIMEOUT                         (65535UL)

/* @brief Maximum depth of queue */
#define ADC_QUEUE_MAX_DEPTH                 (1U)

/* @brief Alignment method of ADC conversion results */
#define ADC_RESULT_ALIGNMENT                (ADC_ALIGN_RIGHT) 

/* @brief  Maximum number of ADC hardware units */
#define ADC_MAX_HW_UNITS                    (13U)

/* @brief  ADC default core ID */
#define ADC_DEFAULT_COREID                  (0U)

/** Specification of ADC Driver : [SWS_Adc_00099] **/
/* Number of channels per group configuration. */
#define ADC_GROUP_0_CHANNEL_NUM             (4U)

/* The channel index 0 of group 0. */
#define GROUP_0_MCU_AN_TEMP_IGBT_IN1                (0U)

#define ADC_GROUP_0_MCU_AN_TEMP_IGBT_IN1            (0U)


/* The channel index 1 of group 0. */
#define GROUP_0_MCU_AN_TEMP_IGBT_IN2                (1U)

#define ADC_GROUP_0_MCU_AN_TEMP_IGBT_IN2            (1U)


/* The channel index 2 of group 0. */
#define GROUP_0_MCU_D_HS1_DIAG                (2U)

#define ADC_GROUP_0_MCU_D_HS1_DIAG            (2U)


/* The channel index 3 of group 0. */
#define GROUP_0_VDD5REF11                (3U)

#define ADC_GROUP_0_VDD5REF11            (3U)

#define ADC_GROUP_1_CHANNEL_NUM             (2U)

/* The channel index 0 of group 1. */
#define GROUP_1_MCU_CUR_W_AN1                (0U)

#define ADC_GROUP_1_MCU_CUR_W_AN1            (0U)


/* The channel index 1 of group 1. */
#define GROUP_1_VDD5REF4                (1U)

#define ADC_GROUP_1_VDD5REF4            (1U)

#define ADC_GROUP_2_CHANNEL_NUM             (4U)

/* The channel index 0 of group 2. */
#define GROUP_2_MCU_AN_TEMP_IGBT_IN3                (0U)

#define ADC_GROUP_2_MCU_AN_TEMP_IGBT_IN3            (0U)


/* The channel index 1 of group 2. */
#define GROUP_2_MCU_D_HS5_DIAG                (1U)

#define ADC_GROUP_2_MCU_D_HS5_DIAG            (1U)


/* The channel index 2 of group 2. */
#define GROUP_2_MCU_D_HS9_DIAG                (2U)

#define ADC_GROUP_2_MCU_D_HS9_DIAG            (2U)


/* The channel index 3 of group 2. */
#define GROUP_2_MCU_D_HS10_DIAG                (3U)

#define ADC_GROUP_2_MCU_D_HS10_DIAG            (3U)

#define ADC_GROUP_3_CHANNEL_NUM             (2U)

/* The channel index 0 of group 3. */
#define GROUP_3_MCU_CUR_U_AN0                (0U)

#define ADC_GROUP_3_MCU_CUR_U_AN0            (0U)


/* The channel index 1 of group 3. */
#define GROUP_3_VDD5REF3                (1U)

#define ADC_GROUP_3_VDD5REF3            (1U)

#define ADC_GROUP_4_CHANNEL_NUM             (4U)

/* The channel index 0 of group 4. */
#define GROUP_4_MCU_D_HS7_DIAG                (0U)

#define ADC_GROUP_4_MCU_D_HS7_DIAG            (0U)


/* The channel index 1 of group 4. */
#define GROUP_4_MCU_D_HS8_DIAG                (1U)

#define ADC_GROUP_4_MCU_D_HS8_DIAG            (1U)


/* The channel index 2 of group 4. */
#define GROUP_4_AN_9015_ERRQ                (2U)

#define ADC_GROUP_4_AN_9015_ERRQ            (2U)


/* The channel index 3 of group 4. */
#define GROUP_4_AN_OBC_Mic                (3U)

#define ADC_GROUP_4_AN_OBC_Mic            (3U)

#define ADC_GROUP_5_CHANNEL_NUM             (2U)

/* The channel index 0 of group 5. */
#define GROUP_5_MCU_CUR_V_AN0                (0U)

#define ADC_GROUP_5_MCU_CUR_V_AN0            (0U)


/* The channel index 1 of group 5. */
#define GROUP_5_VDD5REF6                (1U)

#define ADC_GROUP_5_VDD5REF6            (1U)

#define ADC_GROUP_6_CHANNEL_NUM             (2U)

/* The channel index 0 of group 6. */
#define GROUP_6_MCU_CUR_U_AN1                (0U)

#define ADC_GROUP_6_MCU_CUR_U_AN1            (0U)


/* The channel index 1 of group 6. */
#define GROUP_6_VDD5REF5                (1U)

#define ADC_GROUP_6_VDD5REF5            (1U)

#define ADC_GROUP_7_CHANNEL_NUM             (2U)

/* The channel index 0 of group 7. */
#define GROUP_7_AN_OBC_ON_Mic                (0U)

#define ADC_GROUP_7_AN_OBC_ON_Mic            (0U)


/* The channel index 1 of group 7. */
#define GROUP_7_AN_CAN_WK_Mic                (1U)

#define ADC_GROUP_7_AN_CAN_WK_Mic            (1U)

#define ADC_GROUP_8_CHANNEL_NUM             (2U)

/* The channel index 0 of group 8. */
#define GROUP_8_MCU_CUR_W_AN0                (0U)

#define ADC_GROUP_8_MCU_CUR_W_AN0            (0U)


/* The channel index 1 of group 8. */
#define GROUP_8_VDD5REF2                (1U)

#define ADC_GROUP_8_VDD5REF2            (1U)

#define ADC_GROUP_9_CHANNEL_NUM             (2U)

/* The channel index 0 of group 9. */
#define GROUP_9_IN_AN1                (0U)

#define ADC_GROUP_9_IN_AN1            (0U)


/* The channel index 1 of group 9. */
#define GROUP_9_VDD5REF10                (1U)

#define ADC_GROUP_9_VDD5REF10            (1U)

#define ADC_GROUP_10_CHANNEL_NUM             (4U)

/* The channel index 0 of group 10. */
#define GROUP_10_AN_5Vsensor2                (0U)

#define ADC_GROUP_10_AN_5Vsensor2            (0U)


/* The channel index 1 of group 10. */
#define GROUP_10_VDD5REF7                (1U)

#define ADC_GROUP_10_VDD5REF7            (1U)


/* The channel index 2 of group 10. */
#define GROUP_10_IN_AN2                (2U)

#define ADC_GROUP_10_IN_AN2            (2U)


/* The channel index 3 of group 10. */
#define GROUP_10_IN_AN4                (3U)

#define ADC_GROUP_10_IN_AN4            (3U)

#define ADC_GROUP_11_CHANNEL_NUM             (4U)

/* The channel index 0 of group 11. */
#define GROUP_11_AN_DC_APlus1_Mic                (0U)

#define ADC_GROUP_11_AN_DC_APlus1_Mic            (0U)


/* The channel index 1 of group 11. */
#define GROUP_11_AN_CAN_5V                (1U)

#define ADC_GROUP_11_AN_CAN_5V            (1U)


/* The channel index 2 of group 11. */
#define GROUP_11_AN_Driver_5V                (2U)

#define ADC_GROUP_11_AN_Driver_5V            (2U)


/* The channel index 3 of group 11. */
#define GROUP_11_IN_AN11                (3U)

#define ADC_GROUP_11_IN_AN11            (3U)

#define ADC_GROUP_12_CHANNEL_NUM             (2U)

/* The channel index 0 of group 12. */
#define GROUP_12_MCU_AN_Motor_TEMP_N                (0U)

#define ADC_GROUP_12_MCU_AN_Motor_TEMP_N            (0U)


/* The channel index 1 of group 12. */
#define GROUP_12_MCU_AN_Motor_TEMP_P                (1U)

#define ADC_GROUP_12_MCU_AN_Motor_TEMP_P            (1U)

#define ADC_GROUP_13_CHANNEL_NUM             (2U)

/* The channel index 0 of group 13. */
#define GROUP_13_MCU_CUR_V_AN1                (0U)

#define ADC_GROUP_13_MCU_CUR_V_AN1            (0U)


/* The channel index 1 of group 13. */
#define GROUP_13_VDD5REF1                (1U)

#define ADC_GROUP_13_VDD5REF1            (1U)

#define ADC_GROUP_14_CHANNEL_NUM             (4U)

/* The channel index 0 of group 14. */
#define GROUP_14_MCU_LS_9_DIAG                (0U)

#define ADC_GROUP_14_MCU_LS_9_DIAG            (0U)


/* The channel index 1 of group 14. */
#define GROUP_14_MCU_LS_11_DIAG                (1U)

#define ADC_GROUP_14_MCU_LS_11_DIAG            (1U)


/* The channel index 2 of group 14. */
#define GROUP_14_MCU_LS_12_DIAG                (2U)

#define ADC_GROUP_14_MCU_LS_12_DIAG            (2U)


/* The channel index 3 of group 14. */
#define GROUP_14_AN_1V8                (3U)

#define ADC_GROUP_14_AN_1V8            (3U)

#define ADC_GROUP_15_CHANNEL_NUM             (2U)

/* The channel index 0 of group 15. */
#define GROUP_15_AN_KEY_Mic                (0U)

#define ADC_GROUP_15_AN_KEY_Mic            (0U)


/* The channel index 1 of group 15. */
#define GROUP_15_AN_DC_APlus2_Mic                (1U)

#define ADC_GROUP_15_AN_DC_APlus2_Mic            (1U)

#define ADC_GROUP_16_CHANNEL_NUM             (4U)

/* The channel index 0 of group 16. */
#define GROUP_16_MCU_D_HS3_DIAG                (0U)

#define ADC_GROUP_16_MCU_D_HS3_DIAG            (0U)


/* The channel index 1 of group 16. */
#define GROUP_16_MCU_D_HS4_DIAG                (1U)

#define ADC_GROUP_16_MCU_D_HS4_DIAG            (1U)


/* The channel index 2 of group 16. */
#define GROUP_16_MCU_D_HS6_DIAG                (2U)

#define ADC_GROUP_16_MCU_D_HS6_DIAG            (2U)


/* The channel index 3 of group 16. */
#define GROUP_16_MCU_LS_10_DIAG                (3U)

#define ADC_GROUP_16_MCU_LS_10_DIAG            (3U)

#define ADC_GROUP_17_CHANNEL_NUM             (2U)

/* The channel index 0 of group 17. */
#define GROUP_17_IN_AN7                (0U)

#define ADC_GROUP_17_IN_AN7            (0U)


/* The channel index 1 of group 17. */
#define GROUP_17_IN_AN12                (1U)

#define ADC_GROUP_17_IN_AN12            (1U)

#define ADC_GROUP_18_CHANNEL_NUM             (4U)

/* The channel index 0 of group 18. */
#define GROUP_18_IN_AN3                (0U)

#define ADC_GROUP_18_IN_AN3            (0U)


/* The channel index 1 of group 18. */
#define GROUP_18_IN_AN5                (1U)

#define ADC_GROUP_18_IN_AN5            (1U)


/* The channel index 2 of group 18. */
#define GROUP_18_IN_AN6                (2U)

#define ADC_GROUP_18_IN_AN6            (2U)


/* The channel index 3 of group 18. */
#define GROUP_18_IN_AN8                (3U)

#define ADC_GROUP_18_IN_AN8            (3U)

#define ADC_GROUP_19_CHANNEL_NUM             (4U)

/* The channel index 0 of group 19. */
#define GROUP_19_IN_AN10                (0U)

#define ADC_GROUP_19_IN_AN10            (0U)


/* The channel index 1 of group 19. */
#define GROUP_19_IN_AN13                (1U)

#define ADC_GROUP_19_IN_AN13            (1U)


/* The channel index 2 of group 19. */
#define GROUP_19_MCU_AN_HS1and7_CFB                (2U)

#define ADC_GROUP_19_MCU_AN_HS1and7_CFB            (2U)


/* The channel index 3 of group 19. */
#define GROUP_19_VDD5REF9                (3U)

#define ADC_GROUP_19_VDD5REF9            (3U)

#define ADC_GROUP_20_CHANNEL_NUM             (4U)

/* The channel index 0 of group 20. */
#define GROUP_20_MCU_AN_HS2and8_CFB                (0U)

#define ADC_GROUP_20_MCU_AN_HS2and8_CFB            (0U)


/* The channel index 1 of group 20. */
#define GROUP_20_MCU_AN_HS3and9_CFB                (1U)

#define ADC_GROUP_20_MCU_AN_HS3and9_CFB            (1U)


/* The channel index 2 of group 20. */
#define GROUP_20_MCU_AN_HS4and10_CFB                (2U)

#define ADC_GROUP_20_MCU_AN_HS4and10_CFB            (2U)


/* The channel index 3 of group 20. */
#define GROUP_20_MCU_AN_HS5and6_CFB                (3U)

#define ADC_GROUP_20_MCU_AN_HS5and6_CFB            (3U)

#define ADC_GROUP_21_CHANNEL_NUM             (6U)

/* The channel index 0 of group 21. */
#define GROUP_21_IN_AN14                (0U)

#define ADC_GROUP_21_IN_AN14            (0U)


/* The channel index 1 of group 21. */
#define GROUP_21_VDD5REF8                (1U)

#define ADC_GROUP_21_VDD5REF8            (1U)


/* The channel index 2 of group 21. */
#define GROUP_21_AN_HV_Driver_5V                (2U)

#define ADC_GROUP_21_AN_HV_Driver_5V            (2U)


/* The channel index 3 of group 21. */
#define GROUP_21_AN_5Vsensor1                (3U)

#define ADC_GROUP_21_AN_5Vsensor1            (3U)


/* The channel index 4 of group 21. */
#define GROUP_21_AN_12_RES_Mic                (4U)

#define ADC_GROUP_21_AN_12_RES_Mic            (4U)


/* The channel index 5 of group 21. */
#define GROUP_21_AN_UBD_Mic                (5U)

#define ADC_GROUP_21_AN_UBD_Mic            (5U)

#define ADC_GROUP_22_CHANNEL_NUM             (2U)

/* The channel index 0 of group 22. */
#define GROUP_22_MCU_AN_HV_DC2                (0U)

#define ADC_GROUP_22_MCU_AN_HV_DC2            (0U)


/* The channel index 1 of group 22. */
#define GROUP_22_MCU_D_HS2_DIAG                (1U)

#define ADC_GROUP_22_MCU_D_HS2_DIAG            (1U)

#define ADC_GROUP_23_CHANNEL_NUM             (2U)

/* The channel index 0 of group 23. */
#define GROUP_23_AN_Temp_MCU                (0U)

#define ADC_GROUP_23_AN_Temp_MCU            (0U)


/* The channel index 1 of group 23. */
#define GROUP_23_AN_UBR_Mic                (1U)

#define ADC_GROUP_23_AN_UBR_Mic            (1U)

#define ADC_GROUP_24_CHANNEL_NUM             (2U)

/* The channel index 0 of group 24. */
#define GROUP_24_IN_AN9                (0U)

#define ADC_GROUP_24_IN_AN9            (0U)


/* The channel index 1 of group 24. */
#define GROUP_24_AN_Temp_SBC                (1U)

#define ADC_GROUP_24_AN_Temp_SBC            (1U)

#define ADC_GROUP_25_CHANNEL_NUM             (2U)

/* The channel index 0 of group 25. */
#define GROUP_25_MCU_AN_HV_DC1                (0U)

#define ADC_GROUP_25_MCU_AN_HV_DC1            (0U)


/* The channel index 1 of group 25. */
#define GROUP_25_AN_F_V_PRE                (1U)

#define ADC_GROUP_25_AN_F_V_PRE            (1U)

#define ADC_GROUP_26_CHANNEL_NUM             (4U)

/* The channel index 0 of group 26. */
#define GROUP_26_MCU_COS_N_FB                (0U)

#define ADC_GROUP_26_MCU_COS_N_FB            (0U)


/* The channel index 1 of group 26. */
#define GROUP_26_MCU_COS_P_FB                (1U)

#define ADC_GROUP_26_MCU_COS_P_FB            (1U)


/* The channel index 2 of group 26. */
#define GROUP_26_MCU_SIN_N_FB                (2U)

#define ADC_GROUP_26_MCU_SIN_N_FB            (2U)


/* The channel index 3 of group 26. */
#define GROUP_26_MCU_SIN_P_FB                (3U)

#define ADC_GROUP_26_MCU_SIN_P_FB            (3U)

#define ADC_GROUP_27_CHANNEL_NUM             (2U)

/* The channel index 0 of group 27. */
#define GROUP_27_MCU_EXC_N_FB                (0U)

#define ADC_GROUP_27_MCU_EXC_N_FB            (0U)


/* The channel index 1 of group 27. */
#define GROUP_27_MCU_EXC_P_FB                (1U)

#define ADC_GROUP_27_MCU_EXC_P_FB            (1U)


/** Specification of ADC Driver : [SWS_Adc_00099] **/
/* The symbolic name of the group. */
#define ADC_GROUP_AdcGroup_0                (0U)
#define ADC_GROUP_AdcGroup_1                (1U)
#define ADC_GROUP_AdcGroup_2                (2U)
#define ADC_GROUP_AdcGroup_3                (3U)
#define ADC_GROUP_AdcGroup_4                (4U)
#define ADC_GROUP_AdcGroup_5                (5U)
#define ADC_GROUP_AdcGroup_6                (6U)
#define ADC_GROUP_AdcGroup_7                (7U)
#define ADC_GROUP_AdcGroup_8                (8U)
#define ADC_GROUP_AdcGroup_9                (9U)
#define ADC_GROUP_AdcGroup_10                (10U)
#define ADC_GROUP_AdcGroup_11                (11U)
#define ADC_GROUP_AdcGroup_12                (12U)
#define ADC_GROUP_AdcGroup_13                (13U)
#define ADC_GROUP_AdcGroup_14                (14U)
#define ADC_GROUP_AdcGroup_15                (15U)
#define ADC_GROUP_AdcGroup_16                (16U)
#define ADC_GROUP_AdcGroup_17                (17U)
#define ADC_GROUP_AdcGroup_18                (18U)
#define ADC_GROUP_AdcGroup_19                (19U)
#define ADC_GROUP_AdcGroup_20                (20U)
#define ADC_GROUP_AdcGroup_21                (21U)
#define ADC_GROUP_AdcGroup_22                (22U)
#define ADC_GROUP_AdcGroup_23                (23U)
#define ADC_GROUP_AdcGroup_24                (24U)
#define ADC_GROUP_AdcGroup_25                (25U)
#define ADC_GROUP_AdcGroup_26                (26U)
#define ADC_GROUP_AdcGroup_27                (27U)



extern VAR(uint16, ADC_VAR) HwUnit0_Group0_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit1_Group1_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit1_Group2_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit2_Group3_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit2_Group4_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit3_Group5_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit4_Group6_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit4_Group7_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit5_Group8_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit6_Group9_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit7_Group10_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit8_Group11_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit9_Group12_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit10_Group13_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit10_Group14_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit11_Group15_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit0_Group16_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit7_Group17_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit8_Group18_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit9_Group19_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit9_Group20_ResultBuf[4];
extern VAR(uint16, ADC_VAR) HwUnit2_Group23_ResultBuf[2];
extern VAR(uint16, ADC_VAR) HwUnit6_Group26_ResultBuf[16];
extern VAR(uint16, ADC_VAR) HwUnit7_Group27_ResultBuf[8];

#endif /* ADC_CFG_H */

/** @} */
