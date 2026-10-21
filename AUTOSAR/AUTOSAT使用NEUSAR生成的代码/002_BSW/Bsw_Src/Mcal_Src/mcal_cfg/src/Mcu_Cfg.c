/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Mcu_PBcfg.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

/*PRQA S 0499,4499,4397,4399,1258,1759,1594,1599,1756,1758,0704 EOF*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================INCLUDE FILES=======================================*/

#include "Mcu_Cfg.h"       /*PRQA S 0380*/
#include "Mcu.h"           /*PRQA S 0380*/
#include "Mcu_LLDriver.h"  /*PRQA S 0380*/

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define MCU_PB_VENDOR_ID_C                 176
#define MCU_PB_AR_MAJOR_VER_C              4
#define MCU_PB_AR_MINOR_VER_C              4
#define MCU_PB_AR_PATCH_VER_C              0
#define MCU_PB_SW_MAJOR_VER_C              3
#define MCU_PB_SW_MINOR_VER_C              0
#define MCU_PB_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

#if (MCU_PB_VENDOR_ID_C != MCU_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_CFG_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_PB_AR_MAJOR_VER_C != MCU_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MAJOR_VER"
#endif
#if (MCU_PB_AR_MINOR_VER_C != MCU_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MINOR_VER"
#endif
#if (MCU_PB_AR_PATCH_VER_C != MCU_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_PB_SW_MAJOR_VER_C != MCU_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MAJOR_VER"
#endif
#if (MCU_PB_SW_MINOR_VER_C != MCU_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MINOR_VER"
#endif
#if (MCU_PB_SW_PATCH_VER_C != MCU_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_PATCH_VER"
#endif














/*
CCFC3007PT    : MCU_HARDVAR = 2
CCFC3008PT    : MCU_HARDVAR = 3
CCFC3007BC    : MCU_HARDVAR = 4
CCFC3012PT    : MCU_HARDVAR = 5
CCFC3008PC    : MCU_HARDVAR = 6
CCFC3010PT    : MCU_HARDVAR = 7
CCFC3011PT    : MCU_HARDVAR = 8
CCFC3008PCSN  : MCU_HARDVAR = 9
CCFC3008PCSA  : MCU_HARDVAR = 11
CCFC3010PTD   : MCU_HARDVAR = 12
CCRC4086S     : MCU_HARDVAR = 20
CCRC4045S     : MCU_HARDVAR = 21
*/

/* MCU_HARDVAR 5 */







    #if (MCU_FCCU_ENABLE == STD_ON)
    #endif
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_CoreConfigType, MCU_CONST) Mcu_CoreConfiguration = 
{
    /* Core 0 */  .Mcme_Caddr0_Config = (uint32)(MC_ME_CADDR_RESET_DISABLE | (0x01100000U & MC_ME_CADDR_ADDR_MASK32) ),
    /* Core 0C */ .Mcme_Caddr1_Config = (uint32)(MC_ME_CADDR_RESET_DISABLE),
    /* Core 1 */  .Mcme_Caddr2_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE | (0x01100000U & MC_ME_CADDR_ADDR_MASK32) ),
    /* Core 1C */ .Mcme_Caddr3_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE),
    /* Core HSM */.Mcme_Caddr4_Config = (uint32)(MC_ME_CADDR_RESET_DISABLE | (0x00000000U & MC_ME_CADDR_ADDR_MASK32) ),
    /* Core 2 */  .Mcme_Caddr6_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE | (0x01100000U & MC_ME_CADDR_ADDR_MASK32) ),
    /* Core 2C */ .Mcme_Caddr7_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE),
    /* Core 3 */  .Mcme_Caddr8_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE | (0x01100000U & MC_ME_CADDR_ADDR_MASK32) ),
    /* Core 3C */ .Mcme_Caddr9_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE),
    /* Core 4 */  .Mcme_Caddr10_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE | (0x01100000U & MC_ME_CADDR_ADDR_MASK32) ),
    /* Core 5 */  .Mcme_Caddr11_Config = (uint32)(MC_ME_CADDR_RESET_ENABLE | (0x01100000U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Cctrl0_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)     ),
    .Mcme_Cctrl1_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)
     ),
    .Mcme_Cctrl2_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)     ),
    .Mcme_Cctrl3_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)
     ),
    .Mcme_Cctrl4_Config = (uint16)(
        (MC_ME_CCTL_RUN3_OFF) |
        (MC_ME_CCTL_RUN2_OFF) |
        (MC_ME_CCTL_RUN1_OFF) |
        (MC_ME_CCTL_RUN0_OFF) |
        (MC_ME_CCTL_DRUN_OFF) |
        (MC_ME_CCTL_SAFE_OFF)     ),
    .Mcme_Cctrl6_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)     ),
    .Mcme_Cctrl7_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)
     ),
    .Mcme_Cctrl8_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)     ),
    .Mcme_Cctrl9_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)
     ),
    .Mcme_Cctrl10_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)     ),
    .Mcme_Cctrl11_Config = (uint16)(
        (MC_ME_CCTL_RUN3_ON) |
        (MC_ME_CCTL_RUN2_ON) |
        (MC_ME_CCTL_RUN1_ON) |
        (MC_ME_CCTL_RUN0_ON) |
        (MC_ME_CCTL_DRUN_ON) |
        (MC_ME_CCTL_SAFE_ON)     )
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_PeriConfigType, MCU_CONST) McuPeripheralConfig_0[]= 
{
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SIPI0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SIUL_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PIT_RTC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PIT_RTC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DMAMUX0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CRC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_GMAC_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAM_RAM_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAM_RAM_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_TTCAN_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_TTCAN_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAN_RAM_1_CTRL_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAN_RAM_0_CTRL_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_TTCAN_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAN_SAMPLER_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_RTC_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_16_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_14_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_IIC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_15_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_14_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SENT_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_FLEXRAY_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_21_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_20_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_19_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PSI5_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DAC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_GTMINT_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_EMIOS_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SPORT_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SDEMMC_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_13_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_18_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_17_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_16_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CMU_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CANFD_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CANFD_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PSI5_S_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CRC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_13_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DAC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_15_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_IIC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SENT_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_FLEXRAY_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_PeriConfigType, MCU_CONST) McuPeripheralConfig_1[]= 
{
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SIPI0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SIUL_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PIT_RTC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PIT_RTC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DMAMUX0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CRC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_GMAC_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAM_RAM_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAM_RAM_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_TTCAN_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_TTCAN_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAN_RAM_1_CTRL_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAN_RAM_0_CTRL_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_MCAN9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_TTCAN_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CAN_SAMPLER_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_RTC_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_16_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_14_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_IIC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_15_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_14_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SENT_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_FLEXRAY_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_21_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_20_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_19_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PSI5_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DAC_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_GTMINT_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_EMIOS_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SPORT_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SDEMMC_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_13_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_18_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_17_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DPSI_16_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CMU_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CANFD_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CANFD_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_PSI5_S_0_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_CRC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_13_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSD_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DAC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ACMP_4_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_15_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_12_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_11_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_10_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_LINFlexD_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_DSPI_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_IIC_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_SENT_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_FLEXRAY_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_9_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_8_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_7_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_6_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_5_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_3_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_2_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)MC_ME_PCTL_ADCSAR_1_INDEX,
        .McMeRunConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0,
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)MC_ME_PERIPH_CONFIG_0 },
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_McMeConfigType, MCU_CONST) Mcu_McMeConfiguration = 
{
    .McMeMe = (uint32)(
        /* McuModeRun1 */  (uint32) (MCU_MCME_RUN1)
        /* McuModeRun2 */ |(uint32) (MCU_MCME_RUN2)
        /* McuModeRun3 */ |(uint32) (0U)
        /* McuModeHalt */ |(uint32) (MCU_MCME_HALT)
        /* McuModeStop */ |(uint32) (MCU_MCME_STOP)
        /* McuModeStandby */ |(uint32) (MCU_MCME_STANDBY)
    ),

    .McMeRunConfig = {
        (uint32) ( /* McuRunConfig 0 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (MCU_MCME_DRUN)
                /* McuModeRun0 */ |(uint32) (MCU_MCME_RUN0)
                /* McuModeRun1 */ |(uint32) (MCU_MCME_RUN1)
                /* McuModeRun2 */ |(uint32) (MCU_MCME_RUN2)
                /* McuModeRun3 */ |(uint32) (MCU_MCME_RUN3) ),
        (uint32) ( /* McuRunConfig 1 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
        (uint32) ( /* McuRunConfig 2 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
        (uint32) ( /* McuRunConfig 3 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
        (uint32) ( /* McuRunConfig 4 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
        (uint32) ( /* McuRunConfig 5 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
        (uint32) ( /* McuRunConfig 6 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
        (uint32) ( /* McuRunConfig 7 */
                /* McuModeSafe */  (uint32) (0U)
                /* McuModeDrun */ |(uint32) (0U)
                /* McuModeRun0 */ |(uint32) (0U)
                /* McuModeRun1 */ |(uint32) (0U)
                /* McuModeRun2 */ |(uint32) (0U)
                /* McuModeRun3 */ |(uint32) (0U) ),
    },

    .McMeLowPowerConfig = {
        (uint32)( /* McuLowPowerConfig 0 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 1 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 2 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 3 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 4 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 5 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 6 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
        (uint32)( /* McuLowPowerConfig 7 */
            /* McuModeHalt */     (uint32) (0U)
            /* McuModeStop */    |(uint32) (0U)
            /* McuModeStandby */ |(uint32) (0U) ),
    },

    .McMePeripheralConfig = {
        /* McuPeripheralConfig 0 */&McuPeripheralConfig_0[0U],
        /* McuPeripheralConfig 1 */&McuPeripheralConfig_1[0U],
    },

    .Mcu_McMeIrqCfg = (uint32_t)(
        (uint32_t)(0U)
        |(uint32_t)(0U)
        |(uint32_t)(0U)
        |(uint32_t)(0U)
        |(uint32_t)(0U)
        |(uint32_t)(0U)
    ),
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"




#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_RgmConfigType, MCU_CONST)  Mcu_RgmConfiguration = 
{
    #if (MCU_PERFORM_RESET_API == STD_ON)
    .Mcu_RgmResetType =MCU_FUNC_RESET,
    #endif /* MCU_PERFORM_RESET_API == STD_ON */
    /* RGM_FRET Register Configuration. */
    .Mcrgm_FuncThresholdReset = (uint8)(0U),
    /* RGM_DRET Register Configuration. */
    .Mcrgm_DesThresholdReset = (uint8)(0U),
    .Mcrgm_DestResetOpt = (uint32)(RGM_PORST_RESET),
    .Mcrgm_DestSafeIsrOpt = (uint32)(RGM_PORST_ALT_EVENT_SAFE),
    .Mcrgm_DestExtPinReset = (uint32)(0x00000000U),
    .Mcrgm_FuncResetOpt = (uint32)(
        (RGM_VOR_FUNC_EVENT_RESET) |
        (RGM_TSR_FUNC_EVENT_SAFE_INT) |
        (RGM_ESR1_EVENT_RESET)
    ),
    .Mcrgm_FuncSafeIsrOpt = (uint32)(
        (RGM_VOR_FUNC_EVENT_SAFE) |
        (RGM_TSR_FUNC_EVENT_SAFE) |
        (RGM_ESR1_EVENT_SAFE)
    ),
    .Mcrgm_FuncExtPinReset = (uint32)(
        (RGM_VOR_FUNC_EXT_RESET_B_DIS) |
        (RGM_TSR_FUNC_EXT_RESET_B_DIS) |
        (RGM_HSM_FUNC_ASSERT_ESR0_DIS) |
        (RGM_FCCU_SOFT_EXT_RESET_B_DIS) |
        (RGM_FCCU_HARD_EXT_RESET_B_DIS) |
        (RGM_SOFT_FUNC_EXT_RESET_B_DIS) |
        (RGM_ESR1_ASSERT_ESR0_DIS)
    ),
    .Mcrgm_FuncPhase1or3Opt = (uint32)(
        (RGM_VOR_FUNC_RESET_PHASE1) |
        (RGM_TSR_FUNC_RESET_PHASE1) |
        (RGM_JTAG_FUNC_RESET_PHASE1) |
        (RGM_SOFT_FUNC_RESET_PHASE1) |
        (RGM_ESR1_RESET_PHASE1) |
        (RGM_ESR0_RESET_PHASE1)
    ),
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"




#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_PmcConfigType, MCU_CONST)  Mcu_PmcConfiguration = 
{
    .Pmc_IerConfig = (uint32)(
        PMC_IER_VD15IE_A_ENA|
        PMC_IER_VD15IE_C_ENA|
        PMC_IER_VD14IE_A_ENA|
        PMC_IER_VD14IE_IM_ENA|
        PMC_IER_VD13IE_IM_ENA|
        PMC_IER_VD12IE_F_ENA|
        PMC_IER_VD10IE_A_ENA|
        PMC_IER_VD10IE_F_ENA|
        PMC_IER_VD9IE_O_ENA|
        PMC_IER_VD9IE_O_H_ENA|
        PMC_IER_VD9IE_IO_5V_H_ENA|
        PMC_IER_VD9IE_IO_5V_ENA|
        PMC_IER_VD9IE_PMC_H_ENA|
        PMC_IER_VD9IE_PMC_ENA|
        PMC_IER_VD8IE_C_ENA|
        PMC_IER_VD8IE_F_ENA|
        PMC_IER_VD7IE_C_ENA|
        PMC_IER_VD4IE_C_ENA|
        PMC_IER_VD3IE_P_ENA|
        PMC_IER_VD3IE_F_ENA),
    .Pmc_VD3ResetEventEn = (uint32)(
        PMC_REE_VD3_HVD3_P_ENA|
        PMC_REE_VD3_LVD3_F_ENA|
        PMC_REE_VD3_LVD3_C_ENA),
    .Pmc_VD4ResetEventEn = (uint32)(
        PMC_REE_VD4_LVD4_C_ENA),
    .Pmc_VD7ResetEventEn = (uint32)(
        PMC_REE_VD7_HVD7_C_ENA),
    .Pmc_VD8ResetEventEn = (uint32)(
        PMC_REE_VD8_LVD8_F_ENA|
        PMC_REE_VD8_HVD8_C_ENA),
    .Pmc_VD9ResetEventEn = (uint32)(
        PMC_REE_VD9_HVD9_O_DIS|
        PMC_REE_VD9_HVD9_IO_5V_DIS|
        PMC_REE_VD9_HVD9_PMC_DIS|
        PMC_REE_VD9_LVD9_O_ENA|
        PMC_REE_VD9_LVD9_IO_5V_ENA|
        PMC_REE_VD9_LVD9_PMC_ENA),
    .Pmc_VD10ResetEventEn = (uint32)(
        PMC_REE_VD10_LVD10_A_ENA|
        PMC_REE_VD10_LVD10_F_ENA),
    .Pmc_VD12ResetEventEn = (uint32)(
        PMC_REE_VD12_HVD12_F_ENA),
    .Pmc_VD13ResetEventEn = (uint32)(
        PMC_REE_VD13_LVD13_IM_ENA),
    .Pmc_VD14ResetEventEn = (uint32)(
        PMC_REE_VD14_LVD14_A_ENA|
        PMC_REE_VD14_HVD14_IM_ENA),
    .Pmc_VD15ResetEventEn = (uint32)(
        PMC_REE_VD15_HVD15_A_ENA|
        PMC_REE_VD15_HVD15_C_ENA),
    .Pmc_VD3ResetEventSel = (uint32)(
        PMC_RES_VD3_HVD3_P_DIS|
        PMC_RES_VD3_LVD3_F_DIS|
        PMC_RES_VD3_LVD3_C_DIS),
    .Pmc_VD4ResetEventSel = (uint32)(
        PMC_RES_VD4_LVD4_C_DIS),
    .Pmc_VD7ResetEventSel = (uint32)(
        PMC_RES_VD7_HVD7_C_DIS),
    .Pmc_VD8ResetEventSel = (uint32)(
        PMC_RES_VD8_LVD8_F_DIS|
        PMC_RES_VD8_HVD8_C_DIS),
    .Pmc_VD9ResetEventSel = (uint32)(
        PMC_RES_VD9_HVD9_O_DIS|
        PMC_RES_VD9_HVD9_IO_5V_DIS|
        PMC_RES_VD9_HVD9_PMC_DIS),
    .Pmc_VD12ResetEventSel = (uint32)(
        PMC_RES_VD12_HVD12_F_DIS),
    .Pmc_VD13ResetEventSel = (uint32)(
        PMC_RES_VD13_LVD13_IM_DIS),
    .Pmc_VD14ResetEventSel = (uint32)(
        PMC_RES_VD14_LVD14_A_DIS|
        PMC_RES_VD14_HVD14_IM_DIS),
    .Pmc_VD15ResetEventSel = (uint32)(
        PMC_RES_VD15_HVD15_A_DIS|
        PMC_RES_VD15_HVD15_C_DIS),
    .Pmc_VD3FccuEventEn = (uint32)(
        PMC_FEE_VD3_FEE3_P_ENA|
        PMC_FEE_VD3_FEE3_F_ENA|
        PMC_FEE_VD3_FEE3_C_ENA),
    .Pmc_VD4FccuEventEn = (uint32)(
        PMC_FEE_VD4_FEE4_C_ENA),
    .Pmc_VD7FccuEventEn = (uint32)(
        PMC_FEE_VD7_FEE7_C_ENA),
    .Pmc_VD8FccuEventEn = (uint32)(
        PMC_FEE_VD8_FEE8_F_ENA|
        PMC_FEE_VD8_FEE8_C_ENA),
    .Pmc_VD9FccuEventEn = (uint32)(
        PMC_FEE_VD9_FEE9_O_ENA|
        PMC_FEE_VD9_FEE9_IO_5V_DIS|
        PMC_FEE_VD9_FEE9_PMC_ENA|
        PMC_FEE_VD9_FEE9_O_H_DIS|
        PMC_FEE_VD9_FEE9_IO_5V_H_ENA|
        PMC_FEE_VD9_FEE9_PMC_ENA),
    .Pmc_VD10FccuEventEn = (uint32)(
        PMC_FEE_VD10_FEE10_A_ENA|
        PMC_FEE_VD10_FEE10_F_ENA),
    .Pmc_VD12FccuEventEn = (uint32)(
        PMC_FEE_VD12_FEE12_F_ENA),
    .Pmc_VD13FccuEventEn = (uint32)(
        PMC_FEE_VD13_FEE13_IM_ENA),
    .Pmc_VD14FccuEventEn = (uint32)(
        PMC_FEE_VD14_FEE14_A_ENA|
        PMC_FEE_VD14_FEE14_IM_ENA),
    .Pmc_VD15FccuEventEn = (uint32)(
        PMC_FEE_VD15_FEE15_A_ENA|
        PMC_FEE_VD15_FEE15_C_ENA),
    .Pmc_VoltageSupply = (uint32)(
        PMC_VSIO_VSIO_IF2_ENA|
        PMC_VSIO_VSIO_IF_ENA|
        PMC_VSIO_VSIO_IJ_ENA|
        PMC_VSIO_VSIO_IM_ENA),
    .Pmc_TempResEventEn = (uint32)(
        PMC_REE_TD_TEMP_3_DIS|
        PMC_REE_TD_TEMP_2_DIS|
        PMC_REE_TD_TEMP_0_DIS),
    .Pmc_TempResEventSel = (uint32)(
        PMC_RES_TD_TEMP_3_DIS|
        PMC_RES_TD_TEMP_2_DIS|
        PMC_RES_TD_TEMP_0_DIS),
    .Pmc_TempDetConfig = (uint32)(
        PMC_CTL_TD_TS3IE_DIS|
        PMC_CTL_TD_TS2IE_DIS|
        PMC_CTL_TD_TS0IE_DIS|
        ((uint32)( (uint32)((0U) << (uint32)8U) & PMC_CTL_TD_TRIM_ADJ_OVER )) |
        ((uint32)( (uint32)((0U) << (uint32)2U) & PMC_CTL_TD_TRIM_ADJ_UNDER )) |
        PMC_CTL_TD_DOUT_ENA|
        PMC_CTL_TD_AOUT_ENA),
    .Pmc_TempFccuEventEn = (uint32)(
        PMC_FEE_TD_FEE_TS3_DIS|
        PMC_FEE_TD_FEE_TS2_DIS|
        PMC_FEE_TD_FEE_TS0_DIS)
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_ClockConfigType, MCU_CONST) Mcu_ClockConfiguration[] = 
{
    {
    .cgmConfig = {
        .sc_dc0 = (Mcu_CgmClkDivType)(1U << 16U),
        .sc_dc1 = (Mcu_CgmClkDivType)(3U << 16U),
        .sc_dc2 = (Mcu_CgmClkDivType)(7U << 16U),
        .sc_dc3 = (Mcu_CgmClkDivType)(0U << 16U),
        .sc_dc4 = (Mcu_CgmClkDivType)(7U << 16U),
        .ac0_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0<< 24U),
        .ac0_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (1U << 16U) ),
        .ac0_dc1 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (25U << 16U)
                                        | (0U)
                                        ),
        .ac0_dc2 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (12U << 16U)
                                        | (0U)
                                        ),
        .ac0_dc3 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (3U << 16U) |
                                        (0U) ),
        .ac0_dc4 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (3U << 16U) ),
        .ac1_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0<< 24U),
        .ac1_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (15U << 16U) ),
        .ac2_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (9U << 16U) ),
        .ac2_dc1 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (3U << 16U) ),
        .ac2_dc2 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (3U << 16U) ),
        .ac3_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac4_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac5_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (6618U << 16U) |
                                        (2U)),
        .ac5_dc1 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (99U << 16U) ),
        .ac5_dc2 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (399U << 16U) ),
        .ac5_cdc0 = (Mcu_CgmClkDivType) ( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc1 = (Mcu_CgmClkDivType) ( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc2 = (Mcu_CgmClkDivType) ( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc10 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc11 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc12 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc13 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc20 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc21 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc22 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac5_cdc23 = (Mcu_CgmClkDivType)( (0U<< 31U) |
                                          (0U << 16U) ),
        .ac6_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0<< 24U),
        .ac6_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (3U << 16U) ),
        .ac7_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0<< 24U),
        .ac7_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (3U << 16U) ),
        .ac8_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac8_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (0U << 16U) ),
        .ac9_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac9_dc0 = (Mcu_CgmClkDivType)( (1U<< 31U) |
                                        (0U << 16U) ),
        .ac10_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac10_dc0 = (Mcu_CgmClkDivType)((1U<< 31U) |
                                        (0U << 16U) ),
        .ac11_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac11_dc0 = (Mcu_CgmClkDivType)((1U<< 31U) |
                                        (0U << 16U) ),
        .ac12_sc = (Mcu_CgmClkSelType)(CGM_SYSTEM_CLOCK_SRC_XOSC<< 24U),
        .ac12_dc1 = (Mcu_CgmClkDivType)((1U<< 31U) |
                                        (0U << 16U) |
                                        (0U) ),
        },
    .cgmcsConfig = {
        .ircConfig = {
            .Mcu_FircCfg = (uint32)(
                (uint32)(0U << 16U)  /* FIRC Trim */
               |(uint32)(0U<< 23U) /* FIRCOFF_STDBY */
               |(uint32)(0U << 8U) /* FIRC DIV */
            ),
            .Mcu_SircCfg = (uint32)(
                (uint32)(1U) /* SIRC Enable */
               |(uint32)(3U << 8U) /* SIRC DIV */
            )
            },
        .xoscConfig = {
            .freq = (uint32) 40000000U,
            .startupDelay = (uint16) 100U,
            .bypassOption = (Mcu_XoscBypassType)XOSC_USE_CRYSTAL,
            .Mcu_xoscInterruptEn =TRUE,
            },
        .pllConfig = {
            .pll0cr = (uint32) ( (0U << 7U)/* EXPDIE */
                                |(0U << 3U)/* LOLIE */),
            .pll0dv = (uint32) ( (2U << 12U)/* PREDIV */
                                |(20U)/* MFD */ 
                                |(1U << 16U)/* RFDPHI */
                                |(8U << 27U)/* RFDPHI1 */),
            .pll1cr = (uint32) ( (0U << 7U)/* EXPDIE */
                                |(0U << 3U)/* LOLIE */),
            .pll1dv = (uint32) ( (18U)/* MFD */ 
                                |(1U << 16U)/* RFDPHI */),
            .pll1fm = (uint32) (0U),
            .pll1fd = (uint32) (0U),
            }
        },
    .Mcu_SRamWSConfig = (uint32)(
        ((uint32)(((uint32)2U<< (uint32)8U) & PRAMC_PRCR1_PRI_MASK32)) |
        (PRAMC_PRCR1_P1_BO_ENA) |
        (PRAMC_PRCR1_P0_BO_ENA) |
        (PRAMC_PRCR1_P1_RB_ENA) |
        (PRAMC_PRCR1_P0_RB_ENA) |
        (PRAMC_PRCR1_FT_ENA)),
    .mode_configuration = {
        .clocksEnabled = {
            .irc0 = (uint8)TRUE,
            .xosc0 = (uint8)TRUE,
            .pll0 = (uint8)TRUE,
            .pll1 = (uint8)TRUE            },
        .sysclk = (Mcu_CgmSysClkSrcType)CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0,
        },
    .PeriConfigPtr = &McuPeripheralConfig_0[0U],
    },
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_ModeConfigType, MCU_CONST) Mcu_ModeConfiguration[] = 
{
    {
        .Mcu_ModeConfigId = 0,
        .Mcu_ChipMode =me_mc_run0_mode,
        .Mcu_TargetClock =CGM_SYSTEM_CLOCK_SRC_IRCOSC,
        .Mcu_IRC_En =TRUE,
        .Mcu_XOSC_En =TRUE,
        .Mcu_PLL0_En =TRUE,
        .Mcu_PLL1_En =TRUE,
        .PeriConfigPtr = &McuPeripheralConfig_0[0U]
    },
    {
        .Mcu_ModeConfigId = 1,
        .Mcu_ChipMode =me_mc_run0_mode,
        .Mcu_TargetClock =CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0,
        .Mcu_IRC_En =TRUE,
        .Mcu_XOSC_En =TRUE,
        .Mcu_PLL0_En =TRUE,
        .Mcu_PLL1_En =TRUE,
        .PeriConfigPtr = &McuPeripheralConfig_0[0U]
    },
    {
        .Mcu_ModeConfigId = 2,
        .Mcu_ChipMode =me_mc_stop0_mode,
        .Mcu_TargetClock =CGM_SYSTEM_CLOCK_SRC_IRCOSC,
        .Mcu_IRC_En =TRUE,
        .Mcu_XOSC_En =FALSE,
        .Mcu_PLL0_En =FALSE,
        .Mcu_PLL1_En =FALSE,
        .PeriConfigPtr = &McuPeripheralConfig_1[0U]
    },
    {
        .Mcu_ModeConfigId = 3,
        .Mcu_ChipMode =me_mc_standby_mode,
        .Mcu_TargetClock =CGM_SYSTEM_CLOCK_SRC_IRCOSC,
        .Mcu_IRC_En =TRUE,
        .Mcu_XOSC_En =FALSE,
        .Mcu_PLL0_En =FALSE,
        .Mcu_PLL1_En =FALSE,
        .PeriConfigPtr = &McuPeripheralConfig_1[0U]
    },
    {
        .Mcu_ModeConfigId = 4,
        .Mcu_ChipMode =me_mc_halt0_mode,
        .Mcu_TargetClock =CGM_SYSTEM_CLOCK_SRC_IRCOSC,
        .Mcu_IRC_En =TRUE,
        .Mcu_XOSC_En =FALSE,
        .Mcu_PLL0_En =FALSE,
        .Mcu_PLL1_En =FALSE,
        .PeriConfigPtr = &McuPeripheralConfig_1[0U]
    },
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_RamConfiguration[] = 
{
    {
        /* The ID for Ram Sector configuration. */
        (Mcu_RamSectionType)0U,
        /* RAM section base address: Start of Mcu_RamConfig[0]. */
        (uint8 *)0x40000000U,
        /* RAM section size: Section base address (must be aligned to 4 bytes). */
        (Mcu_RamSizeType)0x00000400U,
        (uint64) ( 
            ((uint64)0x00U << 0U)
            | ((uint64)0x00U << 8U)
            | ((uint64)0x00U << 16U)
            | ((uint64)0x00U << 24U)
        ),
        /* RAM section write size (maximum allowed: 8). */
        (Mcu_RamWriteSizeType)4U
    },
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#if (MCU_FCCU_ENABLE == STD_ON)
#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_FccuRfConfigType, MCU_CONST)  Mcu_FccuRfConfiguration[] = {
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_TEMP_ERROR_CH_0,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_LVD_ERROR_CH_1,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_HVD_ERROR_CH_2,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT0_RESET_REQ_CH_15,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT1_RESET_REQ_CH_13,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT2_RESET_REQ_CH_66,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT3_RESET_REQ_CH_55,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_CMU_0_OSC_CH_31,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_CMU_0_PLL_CH_32,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_FM_PLL_0_CH_29,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_FM_PLL_1_CH_30,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SAFE_MODE_CH_52,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_NO_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)TRUE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)TRUE,
            .nmi_en       = (uint8)TRUE,
            .eout_sig_en  = (uint8)TRUE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT4_RESET_REQ_CH_68,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT5_RESET_REQ_CH_69,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
    {
        .Mcu_FccuChannel           = (uint8)FCCU_FAILURE_SWT6_RESET_REQ_CH_70,
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)FCCU_RF_SW_RECOVERABLE_FAULT,
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)FCCU_RFS_SHORT_RESET,
        .Mcu_FccuToAlarmEn         = (uint8)FALSE,
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)FALSE,
            .nmi_en       = (uint8)FALSE,
            .eout_sig_en  = (uint8)FALSE        },
    },
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_FccuConfigType, MCU_CONST) Mcu_FccuConfiguration = /* PRQA S 3218 */
{
    .Mcu_FccuFilterBypassEn = (uint8)TRUE,
    .Mcu_FccuFilterWidth =0U,
    .Mcu_FccuEoutConfig = {
        .set_after_reset  = (uint8)FALSE,
        .control = FCCU_EP_INDEPENDENT_ABOVE_SW,
        .output = FCCU_EP_OUTPUT_OPEN_DRAIN,
        .fop = FCCU_EOUT_FOP_VARIABLE,
        .switch_mode =FCCU_EOUT_PROTOCOL_SLOW_SM,
        .polarity_sel =FCCU_EOUT_0_LOW_1_HIGH,
        .mode =FCCU_FOM_DUAL_RAIL,
        .eof = FCCU_EOUT_EOF_61HZ,
        .delta_t_value = 0,
    },
    .Mcu_FccuLockTypeConfig = FCCU_TRANSIENTLY_UNLOCK,
    .Mcu_FccuCfgTimeout = 6U,
    .Mcu_FccuIrqTypeConfig = (Mcu_FccuIrqType)FCCU_IRQ_CFG_TO_IEN,
    .Mcu_FccuRfCfgNumber = (uint8)15,
    .Mcu_FccuRfConfigPtr = &Mcu_FccuRfConfiguration[0U],
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
#endif


#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST(Mcu_CtrlConfigType, MCU_CONST) Mcu_CtrlConfiguration = 
{
    .Mcu_BootCore = CORE_ID_0,
    .Mcu_InitCore = CORE_ID_0
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
static CONST( Mcu_NotifyConfigType, MCU_CONST) Mcu_NotifyConfiguration = {
    .Mcu_ClockFailureNotification = NULL_PTR,
    .Mcu_XoscStartupNotification =NULL_PTR,
    .McuFailOfChangeModeNotification = NULL_PTR,
    .Mcu_InvalidConfigNotification_Core =NULL_PTR,
    .Mcu_InvalidConfigNotification_Clock =NULL_PTR,
    .Mcu_InvalidConfigNotification =NULL_PTR,
    .Mcu_InvalidModeNotification =NULL_PTR,
    .Mcu_SafeModeNotification =NULL_PTR,
    .Mcu_ModeCompleteNotification =NULL_PTR,
    .McuVoltageErrorNotification =NULL_PTR,
    .McuTemperatureErrorNotification =NULL_PTR,

    #if (MCU_FCCU_ENABLE == STD_ON)
    .Mcu_FccuAlarmNotification = NULL_PTR,
    .Mcu_FccuCfgToNotification = NULL_PTR,
    #endif
};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
CONST(Mcu_ConfigType, MCU_CONST) Mcu_Config = 
{
    .Mcu_NotifyConfigPtr = &Mcu_NotifyConfiguration,
    .Mcu_CtrlConfigPtr = &Mcu_CtrlConfiguration,
    .Mcu_CoreConfigPtr = &Mcu_CoreConfiguration,
    .Mcu_McMeConfigPtr = &Mcu_McMeConfiguration,
    .Mcu_RgmConfigPtr = &Mcu_RgmConfiguration,
    .Mcu_PmcConfigPtr = &Mcu_PmcConfiguration,
    #if (MCU_FCCU_ENABLE == STD_ON)
    .Mcu_FccuConfigPtr = &Mcu_FccuConfiguration,
    #endif
    .NoClockConfig = 1U,
    .Mcu_ClockConfigPtr = &Mcu_ClockConfiguration[0U],
    .NoModeConfig = 5U,
    .Mcu_ModeConfigPtr = &Mcu_ModeConfiguration[0U],
    .NoRamSectionConfig = 1U,
    .Mcu_RamConfigPtr = &Mcu_RamConfiguration[0U]};
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif


