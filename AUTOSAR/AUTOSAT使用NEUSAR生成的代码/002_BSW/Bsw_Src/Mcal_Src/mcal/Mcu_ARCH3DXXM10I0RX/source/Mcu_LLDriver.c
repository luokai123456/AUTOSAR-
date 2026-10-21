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
#pragma ghs ZO
/**
*   @file    Mcu_LLDriver.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/
/*PRQA S 1514,3432,4461,2985,2844,1258,4342,4491,4397 EOF*/
/*PRQA S 2052,2976,1259,0492,2991,2995,3397,1881 EOF*/
/*PRQA S 3400,3401,1863,0491,4542,0499,3006,1006,2016,1257,0310,1891 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

#include "devassert.h"
#include "common.h"
#include "Mcu_LLDriver.h" /*PRQA S 0380*/
#if (MCU_HARDVER == 3)
#include "libSwap.h"
#endif
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/*====================================================================================================
HEAD FILE VERSION INFORMATION
====================================================================================================*/
#define MCU_LLD_VENDOR_ID_C                     176
#define MCU_LLD_AR_MAJOR_VER_C                  4
#define MCU_LLD_AR_MINOR_VER_C                  4
#define MCU_LLD_AR_PATCH_VER_C                  0
#define MCU_LLD_SW_MAJOR_VER_C                  3
#define MCU_LLD_SW_MINOR_VER_C                  0
#define MCU_LLD_SW_PATCH_VER_C                  0
/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_LLD_VENDOR_ID != MCU_LLD_VENDOR_ID_C)
#error "NON-MATCHED DATA : MCU_LLD_VENDOR_ID_C"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_LLD_AR_MAJOR_VER != MCU_LLD_AR_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_AR_MAJOR_VER_C"
#endif
#if (MCU_LLD_AR_MINOR_VER != MCU_LLD_AR_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_AR_MINOR_VER_C"
#endif
#if (MCU_LLD_AR_PATCH_VER != MCU_LLD_AR_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_AR_PATCH_VER_C"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_LLD_SW_MAJOR_VER != MCU_LLD_SW_MAJOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_SW_MAJOR_VER_C"
#endif
#if (MCU_LLD_SW_MINOR_VER != MCU_LLD_SW_MINOR_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_SW_MINOR_VER_C"
#endif
#if (MCU_LLD_SW_PATCH_VER != MCU_LLD_SW_PATCH_VER_C)
#error "NON-MATCHED DATA : MCU_LLD_SW_PATCH_VER_C"
#endif

#define MCU_START_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"
volatile VAR(Mcu_CoreStatusType, MCU_VAR) Mcu_gCoreStatus[MCU_CORE_COUNT];
volatile VAR(Mcu_CoreStatusType, MCU_VAR) Mcu_gCoreStatus[MCU_CORE_COUNT] = {0U};
#define MCU_STOP_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"
volatile VAR(uint32, MCU_VAR) Mcu_ReasonReg[2U];
volatile VAR(uint32, MCU_VAR) Mcu_ReasonReg[2U] = {0U};
#define MCU_STOP_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"

#if MCU_FCCU_ENABLE == STD_ON
#define MCU_START_SEC_VAR_INIT
#include "Mcu_MemMap.h"
static P2CONST(Mcu_FccuConfigType, MCU_CONST, MCU_APPL_CONST) Mcu_gFccuConfigPtr = NULL_PTR;
#define MCU_STOP_SEC_VAR_INIT
#include "Mcu_MemMap.h"
#endif

extern P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_gConfigPtr;
extern P2CONST(Mcu_ClockConfigType, MCU_VAR, MCU_APPL_DATA) Mcu_gClockConfigPtr;
extern VAR(Mcu_Rgm_ResetType, MCU_VAR) Mcu_gRgmConfiguration;

#if (MCU_HARDVER == 3)
extern VAR( uint8_t, AUTOMATIC) g_swapStatus;
#endif


/*******************************************************************************
 * @brief      Get current core id
 * @param[in]  None
 * @param[out] None
 * @retval     Mcu_CoreType
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_CoreType, MCU_CODE) Mcu_LLD_Get_Core_Id(void)
{
    return (Mcu_CoreType)MFSPR(SPR_PIR); /* PRQA S 0342, 1006, 4342 */
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Launch specified core
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_Launch_Core \
( \
    P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    P2CONST(Mcu_CoreConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_CoreMode_ptr \
)
{
#ifdef RESOURCE_SUPPORT_MCU_CCTL0
    pMcu_Base->CCTL0.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl0_Config;
    pMcu_Base->CADDR0.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr0_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL1
    pMcu_Base->CCTL1.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl1_Config;
    pMcu_Base->CADDR1.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr1_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL2
    pMcu_Base->CCTL2.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl2_Config;
    pMcu_Base->CADDR2.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr2_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL3
    pMcu_Base->CCTL3.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl3_Config;
    pMcu_Base->CADDR3.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr3_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL4
    pMcu_Base->CCTL4.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl4_Config;
    pMcu_Base->CADDR4.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr4_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL6
    pMcu_Base->CCTL6.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl6_Config;
    pMcu_Base->CADDR6.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr6_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL7
    pMcu_Base->CCTL7.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl7_Config;
    pMcu_Base->CADDR7.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr7_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL8
    pMcu_Base->CCTL8.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl8_Config;
    pMcu_Base->CADDR8.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr8_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL9
    pMcu_Base->CCTL9.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl9_Config;
    pMcu_Base->CADDR9.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr9_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL10
    pMcu_Base->CCTL10.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl10_Config;
    pMcu_Base->CADDR10.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr10_Config;
#endif

#ifdef RESOURCE_SUPPORT_MCU_CCTL11
    pMcu_Base->CCTL11.R = (uint16)Mcu_CoreMode_ptr->Mcme_Cctrl11_Config;
    pMcu_Base->CADDR11.R = (uint32)Mcu_CoreMode_ptr->Mcme_Caddr11_Config;
#endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME
 *
 * @param[in] Mcu_SysClk Destination mode.
 * @param[in] Mcu_IrcEn   First IRCOSC clock source.
 * @param[in] Mcu_XoscEn  First XOSC clock source.
 * @param[in] Mcu_Pll0En   First PLL clock source.
 * @param[in] Mcu_Pll1En   Second PLL clock source.
 * @param[in] Mcu_ModeReg  register to be read/written
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_SetClockSources
(
    VAR(uint8, AUTOMATIC) Mcu_SysClk, \
    VAR(uint8, AUTOMATIC) Mcu_IrcEn, \
    VAR(uint8, AUTOMATIC) Mcu_XoscEn, \
    VAR(uint8, AUTOMATIC) Mcu_Pll0En, \
    VAR(uint8, AUTOMATIC) Mcu_Pll1En, \
    volatile P2VAR(uint32, AUTOMATIC, MCU_APPL_DATA) Mcu_ModeReg \
)
{
    VAR(uint32, MCU_VAR) regAddr = (uint32)Mcu_ModeReg;
    VAR(uint32, MCU_VAR) regValue = 0U;
    regValue = *(uint32 *)regAddr;/* polyspace RTE:IDP,NIV */
    
    /*change power lever*/
#if 1
    VAR(uint32, MCU_VAR) u32PowerLevel;
    VAR(uint32, MCU_VAR) u32CurrentMode;
    VAR(boolean, MCU_VAR) bPowerLevelNeedChange = FALSE;

    u32PowerLevel = 0U;
    u32CurrentMode = MC_ME_StPtr->GS.B.S_CURRENT_MODE;

    if(me_mc_safe_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->SAFE_MC.B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_drun_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->DRUN_MC.B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run0_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[0].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run1_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[1].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run2_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[2].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run3_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[3].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else
    {
    	bPowerLevelNeedChange = FALSE;
    }

    u32PowerLevel = (u32PowerLevel + 1U) % 8U;

    if(bPowerLevelNeedChange == TRUE)
    {
    	regValue &= ~(0x70000000U);
    	regValue |= (u32PowerLevel << 28) & 0x70000000U;
    }
#endif

    regValue &= ~(MC_ME_GS_S_SYSCLK_MASK);/*PRQA S 4397*/
    regValue |= (uint8)(Mcu_SysClk & MC_ME_GS_S_SYSCLK_MASK);

    if(Mcu_IrcEn == TRUE)
    {
        regValue |= MC_ME_GS_S_IRC(1UL);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_IRC(1UL);
    }

    if(Mcu_XoscEn == TRUE)
    {
        regValue |= MC_ME_GS_S_XOSC(1UL);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_XOSC(1UL);
    }

    if(Mcu_Pll0En == TRUE)
    {
        regValue |= MC_ME_GS_S_PLL0(1UL);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_PLL0(1UL);
    }

    if(Mcu_Pll1En == TRUE)
    {
        regValue |= MC_ME_GS_S_PLL1(1UL);
    }
    else
    {
        regValue &= ~MC_ME_GS_S_PLL1(1UL);
    }

    *(uint32 *)regAddr = regValue;/* polyspace RTE:IDP */
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_SetIrc
 * Description   : Configures IRC clock source
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) Mcu_LLD_SetIrc \
( \
    P2CONST(Mcu_IrcConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_IrcConfigPtr \
)
{
    VAR(uint32, AUTOMATIC) tempReg;
    tempReg = IRCOSC_StPtr->CTL.R;
    tempReg &= ~(0x009F1F00U);
    tempReg |= (Mcu_IrcConfigPtr->Mcu_FircCfg & 0x009F1F00U);
    IRCOSC_StPtr->CTL.R = tempReg;
    #if (MCU_HARDVER != 3)
    IRCOSC_StPtr->SCTL.R = 0x0301UL;
    delay(10U);
    IRCOSC_StPtr->SCTL.R = Mcu_IrcConfigPtr->Mcu_SircCfg;
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_SetXosc
 * Description   : Configures XOSC clock source
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_SetXosc \
( \
    P2CONST(Mcu_XoscConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_XoscConfig \
)
{
    if(pMcu_XoscConfig->bypassOption != XOSC_USE_CRYSTAL)
    {
        XOSC_StPtr->CTL.B.OSCBYP = 1U;
    }
    else
    {
        XOSC_StPtr->CTL.B.OSCBYP = 0U;
    }

    if(pMcu_XoscConfig->Mcu_xoscInterruptEn == TRUE)
    {
        XOSC_StPtr->CTL.B.I_OSC = 1U;
        XOSC_StPtr->CTL.B.M_OSC = 1U;
    }
    else
    {
        XOSC_StPtr->CTL.B.M_OSC = 0U;
    }

    XOSC_StPtr->CTL.B.EOCV = (uint32)pMcu_XoscConfig->startupDelay;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"



/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_SetPll
 * Description   : Configures ARM PLL clock source
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_SetPll \
( \
    P2CONST(Mcu_PlldigConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config, \
    P2CONST(Mcu_CgmConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_CgmConfig  \
)
{
    MC_CGM_StPtr->AC3_SC.R = pMcu_CgmConfig->ac3_sc;
    MC_CGM_StPtr->AC4_SC.R = pMcu_CgmConfig->ac4_sc;

    PLLDIG_StPtr->PLL0CR.R = pMcu_Config->pll0cr;
    PLLDIG_StPtr->PLL0DV.R = pMcu_Config->pll0dv;
    PLLDIG_StPtr->PLL1CR.R = pMcu_Config->pll1cr;
    PLLDIG_StPtr->PLL1DV.R = pMcu_Config->pll1dv;
    PLLDIG_StPtr->PLL1FD.R = pMcu_Config->pll1fd;
    if(pMcu_Config->pll1fm != 0U)
    {
        PLLDIG_StPtr->PLL_CFG1 = 0xFFFFFFF2UL;
        PLLDIG_StPtr->PLL1FM.R = pMcu_Config->pll1fm & (PLLDIG_PLL1FM_INCSTP_MASK | PLLDIG_PLL1FM_MODPRD_MASK | PLLDIG_PLL1FM_MODSEL_MSAK);
        PLLDIG_StPtr->PLL1FM.R |= PLLDIG_PLL1FM_MODEN_MASK;
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureSystemClockDividers
 * Description   : Configures system clocks
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_ConfigureSystemClockDividers \
( \
    P2CONST(Mcu_CgmConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
    /*! System clock u32Mcu_Divider ratios will change with next update.
     *  Not required for Cut 1.*/
    MC_CGM_StPtr->SC_DIV_RC.R = 0x00000001UL;
    /*! System clock u32Mcu_Divider ratios updated on writing MC_CGM_StPtr->DIV_UPD_TRIG.
     * Not required for Cut 1. */
    MC_CGM_StPtr->DIV_UPD_TYPE.R = 0x80000000UL;

    VAR(uint32, MCU_VAR)Mcu_Timeout = 0U;
    /* Check hsm enable */
    if (0u != SSCM.UOPS.B.HSE)
    {
#if ((MCU_HARDVER == 4 || MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
        (void)MCU_HSM_SetClkDiv(pMcu_Config->sc_dc1 >> 16);
#else
        HSM.ALG_PARAM[1] = pMcu_Config->sc_dc1;
        HSM.HOST_FLAG = 0x000100AAUL;

        /* Wait for the service to complete */
        while ((HSM.HOST_FLAG == 0x000100AAUL) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
        {
            Mcu_Timeout++;
        }
#endif
    }

    /* First system clock u32Mcu_Divider */
    MC_CGM_StPtr->SC_DC0.R = pMcu_Config->sc_dc0;
    MC_CGM_StPtr->SC_DC1.R = pMcu_Config->sc_dc1;
    MC_CGM_StPtr->SC_DC2.R = pMcu_Config->sc_dc2;
    MC_CGM_StPtr->SC_DC3.R = pMcu_Config->sc_dc3;
    MC_CGM_StPtr->SC_DC4.R = pMcu_Config->sc_dc4;
 // ! System clock u32Mcu_Divider ratio updates triggered.  Not required for Cut 1.
    MC_CGM_StPtr->DIV_UPD_TRIG.R = 0xfeedfaceUL;
 // ! Wait for System Clock Divider Update Status == 0. Not required for Cut 1.
    Mcu_Timeout = 0U;
    while ((MC_CGM_StPtr->DIV_UPD_STAT.B.SYS_UPD_STAT == 1U) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
    {
        Mcu_Timeout++;
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers
 * Description   : Configures auxiliary clocks
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers \
( \
    P2CONST(Mcu_CgmConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
    MC_CGM_StPtr->AC0_SC.R  = pMcu_Config->ac0_sc;
    MC_CGM_StPtr->AC0_DC0.R = pMcu_Config->ac0_dc0;
    MC_CGM_StPtr->AC0_DC1.R = pMcu_Config->ac0_dc1;
    MC_CGM_StPtr->AC0_DC2.R = pMcu_Config->ac0_dc2;
    MC_CGM_StPtr->AC0_DC3.R = pMcu_Config->ac0_dc3;
    MC_CGM_StPtr->AC0_DC4.R = pMcu_Config->ac0_dc4;

    MC_CGM_StPtr->AC1_SC.R  = pMcu_Config->ac1_sc;
    MC_CGM_StPtr->AC1_DC0.R = pMcu_Config->ac1_dc0;

    MC_CGM_StPtr->AC2_DC0.R = pMcu_Config->ac2_dc0;
    MC_CGM_StPtr->AC2_DC1.R = pMcu_Config->ac2_dc1;
#ifdef RESOURCE_SUPPORT_MCU_AC2_DC2
    MC_CGM_StPtr->AC2_DC2.R = pMcu_Config->ac2_dc2;
#endif

    MC_CGM_StPtr->AC5_DC0.R = pMcu_Config->ac5_dc0;
    MC_CGM_StPtr->AC5_DC1.R = pMcu_Config->ac5_dc1;
    MC_CGM_StPtr->AC5_DC2.R = pMcu_Config->ac5_dc2;

    MC_CGM_StPtr->AC5_CDC0.R = pMcu_Config->ac5_cdc0;
    MC_CGM_StPtr->AC5_CDC1.R = pMcu_Config->ac5_cdc1;
    MC_CGM_StPtr->AC5_CDC2.R = pMcu_Config->ac5_cdc2;

    MC_CGM_StPtr->AC5_CDC10.R = pMcu_Config->ac5_cdc10;
    MC_CGM_StPtr->AC5_CDC11.R = pMcu_Config->ac5_cdc11;
    MC_CGM_StPtr->AC5_CDC12.R = pMcu_Config->ac5_cdc12;
    MC_CGM_StPtr->AC5_CDC13.R = pMcu_Config->ac5_cdc13;

    MC_CGM_StPtr->AC5_CDC20.R = pMcu_Config->ac5_cdc20;
    MC_CGM_StPtr->AC5_CDC21.R = pMcu_Config->ac5_cdc21;
    MC_CGM_StPtr->AC5_CDC22.R = pMcu_Config->ac5_cdc22;
    MC_CGM_StPtr->AC5_CDC23.R = pMcu_Config->ac5_cdc23;

    MC_CGM_StPtr->AC6_SC.R  = pMcu_Config->ac6_sc;
    MC_CGM_StPtr->AC6_DC0.R = pMcu_Config->ac6_dc0;

    MC_CGM_StPtr->AC7_SC.R  = pMcu_Config->ac7_sc;
    MC_CGM_StPtr->AC7_DC0.R = pMcu_Config->ac7_dc0;

    MC_CGM_StPtr->AC8_SC.R  = pMcu_Config->ac8_sc;
    MC_CGM_StPtr->AC8_DC0.R = pMcu_Config->ac8_dc0;

    MC_CGM_StPtr->AC9_SC.R  = pMcu_Config->ac9_sc;
    MC_CGM_StPtr->AC9_DC0.R = pMcu_Config->ac9_dc0;

    MC_CGM_StPtr->AC10_SC.R  = pMcu_Config->ac10_sc;
    MC_CGM_StPtr->AC10_DC0.R = pMcu_Config->ac10_dc0;

    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
    MC_CGM_StPtr->AC11_SC.R  = pMcu_Config->ac11_sc;
    MC_CGM_StPtr->AC11_DC0.R = pMcu_Config->ac11_dc0;
    #endif
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8)|| (MCU_HARDVER == 12))
    MC_CGM_StPtr->AC12_SC.R  = pMcu_Config->ac12_sc;
    #endif
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
    MC_CGM_StPtr->AC12_DC0.R  = pMcu_Config->ac12_dc0;
    #endif
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8)|| (MCU_HARDVER == 12))
    MC_CGM_StPtr->AC12_DC1.R  = pMcu_Config->ac12_dc1;
    #endif
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
    MC_CGM_StPtr->AC12_DC2.R  = pMcu_Config->ac12_dc2;
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 * Function Name : Mcu_LLD_ConfigureCgmcs
 * Description   : Configures clock sources
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_ConfigureCgmcs \
( \
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_Config \
)
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    if(pMcu_Config == NULL_PTR)
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Mcu_LLD_SetIrc(&pMcu_Config->cgmcsConfig.ircConfig);

        Mcu_LLD_SetXosc(&pMcu_Config->cgmcsConfig.xoscConfig);

        Mcu_LLD_SetPll(&pMcu_Config->cgmcsConfig.pllConfig, &pMcu_Config->cgmConfig);
    }
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME
 * @param[in] ModeEnable  register to be MC_ME.ME
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_SetModeEnable ( VAR(uint32, AUTOMATIC) ModeEnable )
{
    MC_ME_StPtr->ME.R = ModeEnable;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
 * @brief Set run periheral configuration
 *
 * This function sets run periheral configuration
 *
 * @param[in]   RunModeConfig 
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_SetRunPeripheralConfig ( VAR(uint32, AUTOMATIC) RunIdx,
                                                                 VAR(uint32, AUTOMATIC) RunModeConfig )
{
    MC_ME_StPtr->RUN_PC[RunIdx].R = RunModeConfig;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
 * @brief Set low periheral configuration
 *
 * This function sets low periheral configuration
 *
 * @param[in]   LpModeConfig
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_SetLowPeripheralConfig ( VAR(uint32, AUTOMATIC) RunIdx,
                                                                 VAR(uint32, AUTOMATIC) LpModeConfig )
{
    MC_ME_StPtr->LP_PC[RunIdx].R = LpModeConfig;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
* @brief Sets Peripheral clock control register
*
* @param[in] pMcu_Base             mc_me pMcu_Base pointer
* @param[in] eMcu_McMePeriNameConfig        clock name
* @param[in] u8Mcu_RunConfigIndex   running configuration index
* @param[in] u8Mcu_LowConfigIndex   low configuration index
*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_SetPeripheralClockControl \
( \
    P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) pMcu_Base, \
    VAR(Mcu_McMePeriNameType, AUTOMATIC) eMcu_PeripheralName, \
    VAR(uint8, AUTOMATIC) u8Mcu_RunConfigIndex, \
    VAR(uint8, AUTOMATIC) u8Mcu_LowConfigIndex \
)
{
   /* Configure the low and run configurations */
   if (eMcu_PeripheralName != MC_ME_INVALID_INDEX)
   {
       pMcu_Base->PCTL[eMcu_PeripheralName].R \
           = (uint8)((MC_ME_PCTLn_RUN_CFG(u8Mcu_RunConfigIndex) | MC_ME_PCTLn_LP_CFG(u8Mcu_LowConfigIndex)));
   }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_ChangeSysClk( P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) Mcu_McmePtr, \
                                                                VAR(Mcu_CgmClkSelType, AUTOMATIC) Mcu_ClkSel )
{
    VAR(uint32, MCU_VAR) regValue = 0U;
#if 1
    VAR(uint32, MCU_VAR) u32PowerLevel;
    VAR(uint32, MCU_VAR) u32CurrentMode;
    VAR(boolean, MCU_VAR) bPowerLevelNeedChange = FALSE;

    u32PowerLevel = 0U;
    u32CurrentMode = Mcu_McmePtr->GS.B.S_CURRENT_MODE;

    if(me_mc_safe_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->SAFE_MC.B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_drun_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->DRUN_MC.B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run0_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[0].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run1_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[1].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run2_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[2].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else if(me_mc_run3_mode == u32CurrentMode)
    {
    	u32PowerLevel = MC_ME_StPtr->RUN_MC[3].B.PWRLVL;
    	bPowerLevelNeedChange = TRUE;
    }
    else
    {
    	bPowerLevelNeedChange = FALSE;
    }

    u32PowerLevel = (u32PowerLevel + 1U) % 8U;

    if(bPowerLevelNeedChange == TRUE)
    {
    	regValue |= (u32PowerLevel << 28) & 0x70000000U;/*PRQA S 2986,2983*/
    }
#endif

    switch ((Mcu_McModeType)(Mcu_McmePtr->GS.B.S_CURRENT_MODE))
    {
        case me_mc_drun_mode:
        {
            Mcu_McmePtr->DRUN_MC.B.SYSCLK = (uint32) Mcu_ClkSel;
            Mcu_McmePtr->DRUN_MC.R &= ~(0x70000000U);
            Mcu_McmePtr->DRUN_MC.R |= (u32PowerLevel << 28) & 0x70000000U;
            break;
        }
        case me_mc_run0_mode:
        {
            Mcu_McmePtr->RUN_MC[0].B.SYSCLK = (uint32) Mcu_ClkSel;
            Mcu_McmePtr->RUN_MC[0].R &= ~(0x70000000U);
            Mcu_McmePtr->RUN_MC[0].R |= (u32PowerLevel << 28) & 0x70000000U;
            break;
        }
        case me_mc_run1_mode:
        {
            Mcu_McmePtr->RUN_MC[1].B.SYSCLK = (uint32) Mcu_ClkSel;
            Mcu_McmePtr->RUN_MC[1].R &= ~(0x70000000U);
            Mcu_McmePtr->RUN_MC[1].R |= (u32PowerLevel << 28) & 0x70000000U;
            break;
        }
        case me_mc_run2_mode:
        {
            Mcu_McmePtr->RUN_MC[2].B.SYSCLK = (uint32) Mcu_ClkSel;
            Mcu_McmePtr->RUN_MC[2].R &= ~(0x70000000U);
            Mcu_McmePtr->RUN_MC[2].R |= (u32PowerLevel << 28) & 0x70000000U;
            break;
        }
        case me_mc_run3_mode:
        {
            Mcu_McmePtr->RUN_MC[3].B.SYSCLK = (uint32) Mcu_ClkSel;
            Mcu_McmePtr->RUN_MC[3].R &= ~(0x70000000U);
            Mcu_McmePtr->RUN_MC[3].R |= (u32PowerLevel << 28) & 0x70000000U;
            break;
        }
        case me_mc_halt0_mode:
        {
            Mcu_McmePtr->HALT0_MC.B.SYSCLK = (uint32) Mcu_ClkSel;
            Mcu_McmePtr->HALT0_MC.R &= ~(0x70000000U);
            Mcu_McmePtr->HALT0_MC.R |= (u32PowerLevel << 28) & 0x70000000U;
            break;
        }
        default:
        {
            /* Do nothing */
            break;
        }
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
 * @brief MC_ME mode change.
 *
 * This function is changing mode in MC_ME module
 *
 * @param[in] Mcu_McmePtr Register Mcu_McmePtr address for the MC_ME u32Mcu_Instance.
 * @param[in] Mcu_TargetMode Destination mode.
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(Std_ReturnType, MCU_CODE) MC_ME_ChangeMode( P2VAR(MC_ME_Type, AUTOMATIC, MCU_APPL_DATA) Mcu_McmePtr, \
                                                              VAR(Mcu_McModeType, AUTOMATIC) Mcu_TargetMode )
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) Mcu_CurrentMode = 0;
    VAR(uint32, MCU_VAR) Mcu_Timeout = 0;

    if (Mcu_TargetMode != me_mc_mode_notchange)
    {
         Mcu_CurrentMode = (uint32)Mcu_TargetMode;
    }
    else
    {
        Mcu_CurrentMode = Mcu_McmePtr->GS.B.S_CURRENT_MODE;
    }

    /* Change takes effect after mode transition. */
    Mcu_McmePtr->MCTL.R = MC_ME_MCTL_TARGET_MODE(Mcu_CurrentMode) \
                        | MC_ME_MCTL_KEY(FEATURE_MC_ME_KEY);
    Mcu_McmePtr->MCTL.R = MC_ME_MCTL_TARGET_MODE(Mcu_CurrentMode) \
                        | MC_ME_MCTL_KEY(FEATURE_MC_ME_KEY_INV);

    while ((Mcu_McmePtr->GS.B.S_MTRANS == 1U) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
    {
        Mcu_Timeout++;
    } //  Wait for mode transition to complete
    if(Mcu_Timeout >= MCU_TIMEOUT_LOOPS)
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_ChangeMode(VAR(Mcu_McModeType, AUTOMATIC) Mcu_TargetMode)
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    VAR(uint8, MCU_VAR) Mcu_Loop = 0U;
    for(Mcu_Loop = 0U; Mcu_Loop < 3U; Mcu_Loop++)
    {
        Mcu_RetVal = MC_ME_ChangeMode(MC_ME_StPtr, Mcu_TargetMode);
        if(Mcu_RetVal != (Std_ReturnType)E_OK)
        {
            Mcu_RetVal = MC_ME_ChangeMode(MC_ME_StPtr, me_mc_safe_mode);
            if(Mcu_RetVal != (Std_ReturnType)E_OK)
            {
                break;
            }
            else
            {
                /* Do Nothing */
            }
            Mcu_RetVal = MC_ME_ChangeMode(MC_ME_StPtr, me_mc_drun_mode);
            if(Mcu_RetVal != (Std_ReturnType)E_OK)
            {
                break;
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            break;
        }
    }

    if(Mcu_RetVal != (Std_ReturnType)E_OK)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuFailOfChangeModeNotification != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuFailOfChangeModeNotification();
        }
    }
    else
    {
        /* Do Nothing */
    }

    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) Mcu_LLD_ClockPCS_Init(void)
{
    VAR(uint32, MCU_VAR) Mcu_PWRLVL;
    if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_drun_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->DRUN_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->DRUN_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_safe_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->SAFE_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->SAFE_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run0_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[0U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[0U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run1_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[1U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[1U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run2_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[2U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[2U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_run3_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->RUN_MC[3U].B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->RUN_MC[3U].B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE == (uint32)me_mc_halt0_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->HALT0_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->HALT0_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else if(MC_ME_StPtr->GS.B.S_CURRENT_MODE ==(uint32) me_mc_stop0_mode)
    {
        Mcu_PWRLVL = (MC_ME_StPtr->STOP0_MC.B.PWRLVL + 1U) % 8U;
        MC_ME_StPtr->STOP0_MC.B.PWRLVL = Mcu_PWRLVL;
    }
    else
    {
        /* Do nothing */
    }

    MC_CGM_StPtr->PCS_SDUR.R = 16U;

    MC_CGM_StPtr->PCS_DIVC1.R = 0x03E70008U;
    MC_CGM_StPtr->PCS_DIVE1.R = 0x000004E1U;

    MC_CGM_StPtr->PCS_DIVC2.R = 0x03E70008U;
    MC_CGM_StPtr->PCS_DIVE2.R = 0x00001869U;

    MC_CGM_StPtr->PCS_DIVC4.R = 0x0294000CU;
    MC_CGM_StPtr->PCS_DIVE4.R = 0x0000493DU;
    MC_CGM_StPtr->PCS_DIVS4.R = 0x00004C17U;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


/*!
 * @brief Resets configuration of clock sources in MC_ME_StPtr->
 *
 * Resets configuration of clock sources in MC_ME_StPtr-> Enables IRC type clock sources and sets an IRC type clock source as system clock in all modes.
 *
 * @param[in] pMcu_Base   Register pMcu_Base address for the MC_ME u32Mcu_Instance.
 * @param[in] Mcu_SysClk Destination mode. */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_ResetClockSourcesConfiguration( void )
{
#if 1
    VAR(uint32, AUTOMATIC) u32DRUN_MC  = (uint32)&(MC_ME_StPtr->DRUN_MC.R);
    VAR(uint32, AUTOMATIC) u32RUN0_MC  = (uint32)&(MC_ME_StPtr->RUN_MC[0U].R);
    VAR(uint32, AUTOMATIC) u32RUN1_MC  = (uint32)&(MC_ME_StPtr->RUN_MC[1U].R);
    VAR(uint32, AUTOMATIC) u32RUN2_MC  = (uint32)&(MC_ME_StPtr->RUN_MC[2U].R);
    VAR(uint32, AUTOMATIC) u32RUN3_MC  = (uint32)&(MC_ME_StPtr->RUN_MC[3U].R);
    VAR(uint32, AUTOMATIC) u32SAFE_MC  = (uint32)&(MC_ME_StPtr->SAFE_MC.R);
    VAR(uint32, AUTOMATIC) u32TEST_MC  = (uint32)&(MC_ME_StPtr->TEST_MC.R);
 

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32DRUN_MC);
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32RUN0_MC);
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32RUN1_MC);
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32RUN2_MC);
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32RUN3_MC);
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32SAFE_MC);
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, (volatile uint32*)u32TEST_MC);
#endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*!
 * @brief Resets configuration of McMePeripheral in MC_ME_StPtr->
 *
 * Resets configuration of McMePeripheral in MC_ME_StPtr-> Disables module clocks in all modes.
 *
 * @param[in] pMcu_Base   Register pMcu_Base address for the MC_ME u32Mcu_Instance. */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) MC_ME_ResetPeripheralsConfiguration( void )
{
#if 1
    VAR(uint32, MCU_VAR) index = 0U;
    /* Reset run peripheral configurations */
    for (index = (uint32)0UL; index < ((uint32)MC_ME_RUN_CONFIG_COUNT); index++)
    {
        MC_ME_SetRunPeripheralConfig ( index, 0U );
    }
    /* Reset low peripheral configurations */
    for (index = (uint32)0UL; index < ((uint32)MC_ME_LOWPOWER_CONFIG_COUNT); index++)
    {
        MC_ME_SetLowPeripheralConfig( index, 0U );
    }

    for (index = (uint32)0UL; index < (uint32)255UL; index++)
    {
        /* Set peripheral clock control */
        MC_ME_SetPeripheralClockControl(MC_ME_StPtr, (Mcu_McMePeriNameType)index, 0U, 0U);
    }
#endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 * Function Name : CLOCK_SYS_Reset
 * Description   : Clears peripheral clock gating and all clock sources. Only an IRC
 * type clock source is enabled and u32Mcu_Set as system clock source.
 *END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Reset(void)
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) Mcu_Timeout = 0;

    MC_RGM.PRST0.R = 0xFFFFFFFFU;
    MC_RGM.PRST1.R = 0xFFFFFFFFU;
    MC_RGM.PRST2.R = 0xFFFFFFFFU;
    MC_RGM.PRST3.R = 0xFFFFFFFFU;
    MC_RGM.PRST4.R = 0xFFFFFFFFU;
    MC_RGM.PRST5.R = 0xFFFFFFFFU;
    MC_RGM.PRST6.R = 0xFFFFFFFFU;
    MC_RGM.PRST7.R = 0xFFFFFFFFU;

    MC_RGM.PRST0.R = 0;
    MC_RGM.PRST1.R = 0;
    MC_RGM.PRST2.R = 0;
    MC_RGM.PRST3.R = 0;
    MC_RGM.PRST4.R = 0;
    MC_RGM.PRST5.R = 0;
    MC_RGM.PRST6.R = 0;
    MC_RGM.PRST7.R = 0;

    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
    LINFlexD_4.LINCR1.B.INIT = 1;
    LINFlexD_4.LINCR1.B.SLEEP = 1;
    LINFlexD_4.UARTCR.B.RxEn = 0;
    LINFlexD_4.UARTCR.B.TxEn = 0;
    LINFlexD_4.DMARXE.R = 0x0;
    LINFlexD_4.DMATXE.R = 0x0;

    LINFlexD_5.LINCR1.B.INIT = 1;
    LINFlexD_5.LINCR1.B.SLEEP = 1;
    LINFlexD_5.UARTCR.B.RxEn = 0;
    LINFlexD_5.UARTCR.B.TxEn = 0;
    LINFlexD_5.DMARXE.R = 0x0;
    LINFlexD_5.DMATXE.R = 0x0;

    LINFlexD_6.LINCR1.B.INIT = 1;
    LINFlexD_6.LINCR1.B.SLEEP = 1;
    LINFlexD_6.UARTCR.B.RxEn = 0;
    LINFlexD_6.UARTCR.B.TxEn = 0;
    LINFlexD_6.DMARXE.R = 0x0;
    LINFlexD_6.DMATXE.R = 0x0;
    #endif

    /* Resets configuration of McMePeripheral in MC_ME_StPtr-> */
    MC_ME_ResetPeripheralsConfiguration();

    /* Resets configuration of clock sources in MC_ME_StPtr-> */
    MC_ME_ResetClockSourcesConfiguration();

    /* Change takes effect after mode transition. */ /* DRUN */
    MC_ME_StPtr->MCTL.R = (MC_ME_MCTL_TARGET_MODE(0x03UL) | MC_ME_MCTL_KEY(0x5AF0UL));
    MC_ME_StPtr->MCTL.R = (MC_ME_MCTL_TARGET_MODE(0x03UL) | MC_ME_MCTL_KEY(0xA50FUL));

    Mcu_Timeout = 0U;
    while ((MC_ME_StPtr->GS.B.S_MTRANS == 1UL) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
    {
        Mcu_Timeout++;
    } //  Wait for mode transition to complete
    if(Mcu_Timeout >= MCU_TIMEOUT_LOOPS)
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }

    if(Mcu_RetVal == (Std_ReturnType)E_OK)
    {
        /*! System clock divider ratios will change with next update.
        *  Not required for Cut 1.*/
        MC_CGM_StPtr->SC_DIV_RC.R = 0x00000001U;
        /*! System clock divider ratios updated on writing MC_CGM_StPtr->DIV_UPD_TRIG.
        * Not required for Cut 1. */
        MC_CGM_StPtr->DIV_UPD_TYPE.R = 0x80000000UL;

        // PBRIDGEA/PBRIDGEB_CLK at syst clk div by 12 ... (50 MHz)
        MC_CGM_StPtr->SC_DC2.R = 0x80000000UL;

        Mcu_Timeout = 0U;
        if (0u != SSCM.UOPS.B.HSE)
        {
            #if ((MCU_HARDVER == 4 || MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
            (void)MCU_HSM_SetClkDiv(0);
            #else
            HSM.ALG_PARAM[1] = 0U;
            HSM.HOST_FLAG = 0x000100AAUL;
    
            /* Wait for the service to complete */
            while ((HSM.HOST_FLAG == 0x000100AAUL) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
            {
                Mcu_Timeout++;
            }
            #endif
        }

        // SXBAR_CLK at syst clk div by 6 ... (100 MHz)
        MC_CGM_StPtr->SC_DC1.R = 0x80000000UL;

        // FXBAR_CLK, BD_CLK, IOP_CLK at syst clk div by 3 ... (200 MHz)
        MC_CGM_StPtr->SC_DC0.R = 0x80000000UL;

        // COMP/CHKR_CLK at syst clk div by 2 ... (300 MHz)
        MC_CGM_StPtr->SC_DC3.R = 0x80000000UL;

        // CLKOUT at syst clk div by 11 ... (54.55 MHz)
        MC_CGM_StPtr->SC_DC4.R = 0x80000000UL;
        //MC_CGM_StPtr->SC_DC4.R = 0x80080000;
        //! System clock divider ratio updates triggered.  Not required for Cut 1.
        MC_CGM_StPtr->DIV_UPD_TRIG.R = 0xfeedfaceUL;
        //! Wait for System Clock Divider Update Status == 0. Not required for Cut 1.
        
        while ((MC_CGM_StPtr->DIV_UPD_STAT.B.SYS_UPD_STAT == 1UL) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
        {
            Mcu_Timeout++;
        }
        if(Mcu_Timeout >= MCU_TIMEOUT_LOOPS)
        {
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    if(Mcu_RetVal == (Std_ReturnType)E_OK)
    {
        MC_CGM_StPtr->AC3_SC.B.SELCTL = 0x00;   //connect XOSC to the PLL0 input
        MC_CGM_StPtr->AC4_SC.B.SELCTL = 0x01;         //connect XOSC to the PLL1 input

        // Set PLL0 to 300 MHz with 40MHz XOSC reference
        // PREDIV =  1, MFD = 15, RFDPHI = 2, RFDPHI1 = 8
        PLLDIG.PLL0DV.R = 0;
        // Set PLL1 to 600 MHz with 40MHz XOSC reference
        PLLDIG.PLL1DV.R = 0;                // MFD = 30, RFDPHI = 1

        MC_CGM_StPtr->AC0_SC.R  = 0x01000000;     //Selects the source for auxiliary clock 0 = PLL0_PHI

        MC_CGM_StPtr->AC0_DC0.R =  0x0;      //Auxiliary Clock0 Divisor0 = 8
        MC_CGM_StPtr->AC0_DC1.R =  0x0;      //Auxiliary Clock0 Divisor1 = 20
        MC_CGM_StPtr->AC0_DC2.R =  0x0;      //Auxiliary Clock0 Divisor2 = 10
        MC_CGM_StPtr->AC0_DC3.R =  0x0;      //Auxiliary Clock0 Divisor3 = 4
        MC_CGM_StPtr->AC0_DC4.R =  0x0;      //Auxiliary Clock0 Divisor4 = 4

        MC_CGM_StPtr->AC1_DC0.R =  0x0;      //Auxiliary Clock1 Divisor0 = 16

        MC_CGM_StPtr->AC2_DC0.R =  0x0;       //Auxiliary Clock2 Divisor0 = 10
        MC_CGM_StPtr->AC2_DC1.R =  0x0;       //Auxiliary Clock2 Divisor1= 4
        #ifdef RESOURCE_SUPPORT_MCU_AC2_DC2
        MC_CGM_StPtr->AC2_DC2.R =  0x0;
        #endif
        MC_CGM_StPtr->AC5_DC0.R = 0x00000000;      //Auxiliary Clock5 Divisor0 =6613,Divider Value Format =2

        MC_CGM_StPtr->AC5_DC1.R = 0x00000000;      //Auxiliary Clock5 Divisor1 = 200

        MC_CGM_StPtr->AC5_DC2.R = 0x00000000;     //Auxiliary Clock5 Divisor2  = 400

        MC_CGM_StPtr->AC5_CDC0.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor0 = 12

        MC_CGM_StPtr->AC5_CDC1.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor1 = 12

        MC_CGM_StPtr->AC5_CDC10.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor10 =2

        MC_CGM_StPtr->AC5_CDC11.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor11 = 2

        MC_CGM_StPtr->AC5_CDC12.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor12 =2

        MC_CGM_StPtr->AC5_CDC13.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor13 = 2

        MC_CGM_StPtr->AC5_CDC2.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor2 = 12

        MC_CGM_StPtr->AC5_CDC20.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor20 = 2

        MC_CGM_StPtr->AC5_CDC21.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor21 = 2

        MC_CGM_StPtr->AC5_CDC22.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor22 =2

        MC_CGM_StPtr->AC5_CDC23.R =0x00000000;     //Auxiliary Clock5 Cascaded Divisor23 = 2

        MC_CGM_StPtr->AC6_SC.R  = 0x01000000;      //Auxiliary Clock6 Source_Select =Select PLL0_PHI

        MC_CGM_StPtr->AC7_SC.R  = 0x01000000;      //Auxiliary Clock7 Source_Select =Select PLL0_PHI

        MC_CGM_StPtr->AC8_SC.R  = 0x01000000;      //Auxiliary Clock8 Source_Select =Select PLL0_PHI

        MC_CGM_StPtr->AC9_SC.R  = 0x01000000;      //Auxiliary Clock9 Source_Select =Select XOSC/IRCOSC

        MC_CGM_StPtr->AC10_SC.R  = 0x01000000;      //Auxiliary Clock10 Source_Select =Select XOSC/IRCOSC

#if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
        MC_CGM_StPtr->AC11_SC.R  = 0x01000000;      //Auxiliary Clock10 Source_Select =Select PLL0_PHI

        MC_CGM_StPtr->AC12_SC.R  = 0x01000000;      //Auxiliary Clock10 Source_Select =Select XOSC/IRCOSC
#endif

        /* Change takes effect after mode transition. */ /* DRUN */
        MC_ME_StPtr->MCTL.R = (MC_ME_MCTL_TARGET_MODE(0x03UL) | MC_ME_MCTL_KEY(0x5AF0UL));
        MC_ME_StPtr->MCTL.R = (MC_ME_MCTL_TARGET_MODE(0x03UL) | MC_ME_MCTL_KEY(0xA50FUL));
        Mcu_Timeout = 0U;
        while ((MC_ME_StPtr->GS.B.S_MTRANS == 1UL) && (Mcu_Timeout < MCU_TIMEOUT_LOOPS))
        {
            Mcu_Timeout++;
        } //  Wait for mode transition to complete
        if(Mcu_Timeout >= MCU_TIMEOUT_LOOPS)
        {
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    FIRST_CMU->CSR.B.RCDIV = (uint32)3UL;
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_RgmInit(P2CONST(Mcu_RgmConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_RgmConfigPtr)
{
    #if(MCU_PERFORM_RESET_API == STD_ON)
    Mcu_gRgmConfiguration = Mcu_RgmConfigPtr->Mcu_RgmResetType;
    #endif
    /* Event Reset Disable Register (RGM_DERD) */
    MC_RGM.DERD.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_DestResetOpt;
    /* Event Alternate Request Register (RGM_DEAR) */
    MC_RGM.DEAR.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_DestSafeIsrOpt;
    /* Bidirectional Reset Enable Register (RGM_DBRE) */
    MC_RGM.DBRE.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_DestExtPinReset;
    /* Functional */
    MC_RGM.FERD.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncResetOpt;
    MC_RGM.FEAR.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncSafeIsrOpt;
    MC_RGM.FBRE.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncExtPinReset;
    /* Event Short Sequence Register (RGM_FESS) */
    MC_RGM.FESS.R = (uint32)Mcu_RgmConfigPtr->Mcrgm_FuncPhase1or3Opt;

    if(0U != MC_RGM.DES.R)
    {
        /* Reset Escalation Threshold Register (RGM_FRET) */
        MC_RGM.FRET.R = (uint8)Mcu_RgmConfigPtr->Mcrgm_FuncThresholdReset;
    }

    if(0U != (MC_RGM.DES.R & 0x1U))
    {
        /* Reset Escalation Threshold Register (RGM_DRET) */
        MC_RGM.DRET.R = (uint8)Mcu_RgmConfigPtr->Mcrgm_DesThresholdReset;
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) Mcu_LLD_PmcInit(P2CONST(Mcu_PmcConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_PmcConfigPtr)
{
    PMCDIG.IE_P.R = (uint32)(PMC_IER_IE_EN_MASK32);
    PMCDIG.IE_P.R = (uint32)(Mcu_PmcConfigPtr->Pmc_IerConfig | PMC_IER_IE_EN_MASK32);
    PMCDIG.REE_VD3.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD3ResetEventEn);
    PMCDIG.REE_VD4.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD4ResetEventEn);
    PMCDIG.REE_VD7.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD7ResetEventEn);
    PMCDIG.REE_VD8.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD8ResetEventEn);
    PMCDIG.REE_VD9.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD9ResetEventEn);
    PMCDIG.REE_VD10.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD10ResetEventEn);
    PMCDIG.REE_VD12.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD12ResetEventEn);
    PMCDIG.REE_VD13.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD13ResetEventEn);
    PMCDIG.REE_VD14.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD14ResetEventEn);
    PMCDIG.REE_VD15.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD15ResetEventEn);
    PMCDIG.REE_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempResEventEn);
    PMCDIG.RES_VD3.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD3ResetEventSel);
    PMCDIG.RES_VD4.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD4ResetEventSel);
    PMCDIG.RES_VD7.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD7ResetEventSel);
    PMCDIG.RES_VD8.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD8ResetEventSel);
    PMCDIG.RES_VD9.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD9ResetEventSel);
    PMCDIG.RES_VD12.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD12ResetEventSel);
    PMCDIG.RES_VD13.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD13ResetEventSel);
    PMCDIG.RES_VD14.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD14ResetEventSel);
    PMCDIG.RES_VD15.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD15ResetEventSel);
    PMCDIG.RES_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempResEventSel);
    PMCDIG.FEE_VD3.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD3FccuEventEn);
    PMCDIG.FEE_VD4.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD4FccuEventEn);
    PMCDIG.FEE_VD7.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD7FccuEventEn);
    PMCDIG.FEE_VD8.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD8FccuEventEn);
    PMCDIG.FEE_VD9.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD9FccuEventEn);
    PMCDIG.FEE_VD10.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD10FccuEventEn);
    PMCDIG.FEE_VD12.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD12FccuEventEn);
    PMCDIG.FEE_VD13.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD13FccuEventEn);
    PMCDIG.FEE_VD14.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD14FccuEventEn);
    PMCDIG.FEE_VD15.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VD15FccuEventEn);
    PMCDIG.FEE_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempFccuEventEn);
    PMCDIG.CTL_TD.R = (uint32)(Mcu_PmcConfigPtr->Pmc_TempDetConfig) | 0x00000040UL;
    PMCDIG.VSIO.R = (uint32)(Mcu_PmcConfigPtr->Pmc_VoltageSupply);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) Mcu_LLD_McMeIrqConfig(VAR(uint32, AUTOMATIC) Mcu_McMeIrqConfig)
{
    MC_ME_StPtr->IM.R = Mcu_McMeIrqConfig;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(void, MCU_CODE) Mcu_LLD_McMeRunConfig(P2CONST(Mcu_McMeConfigType, AUTOMATIC, MCU_APPL_DATA) Mcu_McMeCfgPtr)
{
    VAR(uint32, MCU_VAR)  index = 0;
    /* Set run peripheral configurations */
    for (index = (uint32)0UL; index < ((uint32)MC_ME_RUN_CONFIG_COUNT); index++)
    {
        MC_ME_SetRunPeripheralConfig (index, Mcu_McMeCfgPtr->McMeRunConfig[index]);
    }

    /* Set low peripheral configurations */
    for (index = (uint32)0UL; index < ((uint32)MC_ME_LOWPOWER_CONFIG_COUNT); index++)
    {
        MC_ME_SetLowPeripheralConfig (index, Mcu_McMeCfgPtr->McMeLowPowerConfig[index]);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ConfigPtr)
{
    #if ((MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8) || (MCU_HARDVER == 12))
    VAR(uint32, MCU_VAR)index;
    #endif
    if(pMcu_ConfigPtr->Mcu_CtrlConfigPtr->Mcu_BootCore == Mcu_LLD_Get_Core_Id())
    {
        #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
        *((volatile uint32*)0xfffa059CU) |= (0x1000u | 0x800u);    /* Open PMU_CFG */
        #endif

        #if (MCU_HARDVER == 4)
        *((volatile uint32*)0xfffa0138U) |= (0x80000000u);    /* Open PMU_CFG */
        #endif

        #if (MCU_HARDVER == 4)
            for(index = 0U; index < 6U; index++)
            {
                XBAR_0.PORT[index].CRS.R = 0x100U;
            }
            for(index = 0U; index < 4U;index ++)
            {
                XBAR_1.PORT[index].CRS.R = 0x100U;
            }
        #endif
        #if ((MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8) || (MCU_HARDVER == 12))
            for(index = 0U; index < 8U; index++)
            {
                XBAR_0.PORT[index].CRS.R = 0x100U;
                XBAR_1.PORT[index].CRS.R = 0x100U;
                XBAR_2.PORT[index].CRS.R = 0x100U;
                XBAR_3.PORT[index].CRS.R = 0x100U;
            }
        #endif
        // Mcu_LLD_Launch_Core(MC_ME_StPtr, pMcu_ConfigPtr->Mcu_CoreConfigPtr);
        // (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
    }

    if(pMcu_ConfigPtr->Mcu_CtrlConfigPtr->Mcu_InitCore == Mcu_LLD_Get_Core_Id())
    {
        Mcu_LLD_McMeIrqConfig(pMcu_ConfigPtr->Mcu_McMeConfigPtr->Mcu_McMeIrqCfg);
        MC_ME_SetModeEnable(pMcu_ConfigPtr->Mcu_McMeConfigPtr->McMeMe);
        (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
        /* Infinite reset Contorl */
        Mcu_LLD_RgmInit(pMcu_ConfigPtr->Mcu_RgmConfigPtr);
        Mcu_LLD_PmcInit(pMcu_ConfigPtr->Mcu_PmcConfigPtr);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Mcu_LLD_Clock_Init
 * Description   : This function sets the system to target configuration, it
 * only sets the clock modules registers for clock mode change, but not send
 * notifications to drivers.
 *
 * Implements CLOCK_DRV_Init_Activity
 * END**************************************************************************/

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_SysCLockCheck(
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr )
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_NOT_OK;

    /* Check whether the current clock source is enabled */
    if(MC_ME_StPtr->GS.B.S_IRC == pMcu_ClockConfigPtr->mode_configuration.clocksEnabled.irc0  /* polyspace RTE:IDP */
        && MC_ME_StPtr->GS.B.S_XOSC == pMcu_ClockConfigPtr->mode_configuration.clocksEnabled.xosc0
        && MC_ME_StPtr->GS.B.S_PLL0 == pMcu_ClockConfigPtr->mode_configuration.clocksEnabled.pll0
        && MC_ME_StPtr->GS.B.S_PLL1 == pMcu_ClockConfigPtr->mode_configuration.clocksEnabled.pll1
        && MC_ME_StPtr->GS.B.S_SYSCLK == pMcu_ClockConfigPtr->mode_configuration.sysclk)
    {
        Mcu_RetVal = (Std_ReturnType)E_OK;
    }
    else
    {
        Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
    }


    /* Check the clock source configuration */
    if(Mcu_RetVal == (Std_ReturnType)E_OK)
    {
        /* AC3 */
        if(pMcu_ClockConfigPtr->mode_configuration.clocksEnabled.pll0 == 1U)
        {
            if(MC_CGM_StPtr->AC3_SC.R == pMcu_ClockConfigPtr->cgmConfig.ac3_sc)
            {
                Mcu_RetVal = (Std_ReturnType)E_OK;
            }
            else
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
        /* AC4 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->mode_configuration.clocksEnabled.pll1 == 1U)
            {
                if(MC_CGM_StPtr->AC4_SC.R == pMcu_ClockConfigPtr->cgmConfig.ac4_sc)
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmcsConfig.ircConfig.Mcu_FircCfg == (IRCOSC_StPtr->CTL.R & 0x009F1F00UL)
                && pMcu_ClockConfigPtr->cgmcsConfig.xoscConfig.startupDelay == XOSC_StPtr->CTL.B.EOCV 
                && pMcu_ClockConfigPtr->cgmcsConfig.xoscConfig.Mcu_xoscInterruptEn == XOSC_StPtr->CTL.B.M_OSC
                && pMcu_ClockConfigPtr->cgmcsConfig.xoscConfig.bypassOption == XOSC_StPtr->CTL.B.OSCBYP
                && (pMcu_ClockConfigPtr->cgmcsConfig.pllConfig.pll0cr | (3U/* CLKCFG=Normal */ << 8U)) == PLLDIG_StPtr->PLL0CR.R
                && pMcu_ClockConfigPtr->cgmcsConfig.pllConfig.pll0dv == PLLDIG_StPtr->PLL0DV.R
                && (pMcu_ClockConfigPtr->cgmcsConfig.pllConfig.pll1cr | (3U/* CLKCFG=Normal */ << 8U)) == PLLDIG_StPtr->PLL1CR.R
                && pMcu_ClockConfigPtr->cgmcsConfig.pllConfig.pll1dv == PLLDIG_StPtr->PLL1DV.R
                && pMcu_ClockConfigPtr->cgmcsConfig.pllConfig.pll1fd == PLLDIG_StPtr->PLL1FD.R
                && pMcu_ClockConfigPtr->cgmcsConfig.pllConfig.pll1fm == PLLDIG_StPtr->PLL1FM.R )
            {
                Mcu_RetVal = (Std_ReturnType)E_OK;
            }
            else
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    /* System clock check */
    if(Mcu_RetVal == (Std_ReturnType)E_OK)
    {
        if(  (pMcu_ClockConfigPtr->cgmConfig.sc_dc0 | 0x80000000U /* DEN */) == MC_CGM_StPtr->SC_DC0.R
          && (pMcu_ClockConfigPtr->cgmConfig.sc_dc1 | 0x80000000U /* DEN */) == MC_CGM_StPtr->SC_DC1.R
          && (pMcu_ClockConfigPtr->cgmConfig.sc_dc2 | 0x80000000U /* DEN */) == MC_CGM_StPtr->SC_DC2.R
          && (pMcu_ClockConfigPtr->cgmConfig.sc_dc3 | 0x80000000U /* DEN */) == MC_CGM_StPtr->SC_DC3.R
          && (pMcu_ClockConfigPtr->cgmConfig.sc_dc4 | 0x80000000U /* DEN */) == MC_CGM_StPtr->SC_DC4.R)
        {
            Mcu_RetVal = (Std_ReturnType)E_OK;
        }
        else
        {
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_PeriCLockCheck(
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr )
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
    /* Peripheral clock check */
    #if 0
    if(Mcu_RetVal == (Std_ReturnType)E_OK)
    #endif
    {
        /* AC0 */
        if( pMcu_ClockConfigPtr->cgmConfig.ac0_sc != MC_CGM_StPtr->AC0_SS.R )
        {
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if((pMcu_ClockConfigPtr->cgmConfig.ac0_dc0 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC0_DC0.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac0_dc0 != MC_CGM_StPtr->AC0_DC0.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac0_dc1 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC0_DC1.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if (pMcu_ClockConfigPtr->cgmConfig.ac0_dc1 != MC_CGM_StPtr->AC0_DC1.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if ((pMcu_ClockConfigPtr->cgmConfig.ac0_dc2 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC0_DC2.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if (pMcu_ClockConfigPtr->cgmConfig.ac0_dc2 != MC_CGM_StPtr->AC0_DC2.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if ((pMcu_ClockConfigPtr->cgmConfig.ac0_dc3 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC0_DC3.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if (pMcu_ClockConfigPtr->cgmConfig.ac0_dc3 != MC_CGM_StPtr->AC0_DC3.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if ((pMcu_ClockConfigPtr->cgmConfig.ac0_dc4 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC0_DC4.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if (pMcu_ClockConfigPtr->cgmConfig.ac0_dc4 != MC_CGM_StPtr->AC0_DC4.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                Mcu_RetVal = (Std_ReturnType)E_OK;
            }
        }

        /* AC1 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac1_sc != MC_CGM_StPtr->AC1_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac1_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC1_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac1_dc0 != MC_CGM_StPtr->AC1_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }

        /* AC2 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if((pMcu_ClockConfigPtr->cgmConfig.ac2_dc0 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC2_DC0.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac2_dc0 != MC_CGM_StPtr->AC2_DC0.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac2_dc1 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC2_DC1.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac2_dc1 != MC_CGM_StPtr->AC2_DC1.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            #if ((MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
            else if((pMcu_ClockConfigPtr->cgmConfig.ac2_dc2 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC2_DC2.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac2_dc2 != MC_CGM_StPtr->AC2_DC2.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            #endif
            else
            {
                Mcu_RetVal = (Std_ReturnType)E_OK;
            }
        }

        /* AC5 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if((pMcu_ClockConfigPtr->cgmConfig.ac5_dc0 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_DC0.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_dc0 != MC_CGM_StPtr->AC5_DC0.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_dc1 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_DC1.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_dc1 != MC_CGM_StPtr->AC5_DC1.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_dc2 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_DC2.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_dc2 != MC_CGM_StPtr->AC5_DC2.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc0 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC0.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc0 != MC_CGM_StPtr->AC5_CDC0.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc1 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC1.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc1 != MC_CGM_StPtr->AC5_CDC1.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc2 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC2.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc2 != MC_CGM_StPtr->AC5_CDC2.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc10 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC10.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc10 != MC_CGM_StPtr->AC5_CDC10.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc11 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC11.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc11 != MC_CGM_StPtr->AC5_CDC11.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc12 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC12.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc12 != MC_CGM_StPtr->AC5_CDC12.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc13 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC13.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc13 != MC_CGM_StPtr->AC5_CDC13.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc20 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC20.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc20 != MC_CGM_StPtr->AC5_CDC20.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc21 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC21.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc21 != MC_CGM_StPtr->AC5_CDC21.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc22 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC22.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc22 != MC_CGM_StPtr->AC5_CDC22.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if((pMcu_ClockConfigPtr->cgmConfig.ac5_cdc23 & (1U << 31U)) 
                != (MC_CGM_StPtr->AC5_CDC23.R & (1U << 31U)))
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else if(pMcu_ClockConfigPtr->cgmConfig.ac5_cdc23 != MC_CGM_StPtr->AC5_CDC23.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                Mcu_RetVal = (Std_ReturnType)E_OK;
            }
        }

        /* AC6 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac6_sc != MC_CGM_StPtr->AC6_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac6_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC6_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac6_dc0 != MC_CGM_StPtr->AC6_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }

        /* AC7 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac7_sc != MC_CGM_StPtr->AC7_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac7_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC7_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac7_dc0 != MC_CGM_StPtr->AC7_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }

        /* AC8 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac8_sc != MC_CGM_StPtr->AC8_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac8_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC8_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac8_dc0 != MC_CGM_StPtr->AC8_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }

        /* AC9 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac9_sc != MC_CGM_StPtr->AC9_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac9_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC9_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac9_dc0 != MC_CGM_StPtr->AC9_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }

        /* AC10 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac10_sc != MC_CGM_StPtr->AC10_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac10_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC10_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac10_dc0 != MC_CGM_StPtr->AC10_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }

        #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
        /* AC11 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac11_sc != MC_CGM_StPtr->AC11_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if((pMcu_ClockConfigPtr->cgmConfig.ac11_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC11_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac11_dc0 != MC_CGM_StPtr->AC11_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }
        #endif
        #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
        /* AC12 */
        if(Mcu_RetVal == (Std_ReturnType)E_OK)
        {
            if(pMcu_ClockConfigPtr->cgmConfig.ac12_sc != MC_CGM_StPtr->AC12_SS.R)
            {
                Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
                if((pMcu_ClockConfigPtr->cgmConfig.ac12_dc0 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC12_DC0.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac12_dc0 != MC_CGM_StPtr->AC12_DC0.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if((pMcu_ClockConfigPtr->cgmConfig.ac12_dc1 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC12_DC1.R & (1U << 31U)))
                #else
                if((pMcu_ClockConfigPtr->cgmConfig.ac12_dc1 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC12_DC1.R & (1U << 31U)))
                #endif
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac12_dc1 != MC_CGM_StPtr->AC12_DC1.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4))
                else if((pMcu_ClockConfigPtr->cgmConfig.ac12_dc2 & (1U << 31U)) 
                    != (MC_CGM_StPtr->AC12_DC2.R & (1U << 31U)))
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                else if(pMcu_ClockConfigPtr->cgmConfig.ac12_dc2 != MC_CGM_StPtr->AC12_DC2.R)
                {
                    Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
                }
                #endif
                else
                {
                    Mcu_RetVal = (Std_ReturnType)E_OK;
                }
            }
        }
        #endif
    }
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


/*FUNCTION**********************************************************************
 *
 * Function Name : Mcu_LLD_Clock_Init
 * Description   : This function sets the system to target configuration, it
 * only sets the clock modules registers for clock mode change, but not send
 * notifications to drivers.
 *
 * Implements CLOCK_DRV_Init_Activity
 * END**************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Clock_Init (
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) pMcu_ClockConfigPtr )
{
    VAR(Std_ReturnType, MCU_VAR) Mcu_RetVal = (Std_ReturnType)E_OK;
#ifdef MCU_FLASH_WAIT_STATUS_CONFIG
    VAR(uint32, MCU_VAR) RegValue;
#endif

    VAR(uint32, MCU_VAR) index = 0U;

    P2VAR(volatile struct PFLASH_tag, RTE_VAR, RTE_REGSPACE) PFlash_Array[] = /*PRQA S 3604*/
    {
        &PFLASH,
    #if defined(CCFC3010PT) || defined(CCFC3011PT) || defined(CCFC3012PT)
        &PFI0_PFLASH,
        &PFI1_PFLASH,
        &PFI2_PFLASH,
        &PFI3_PFLASH,
    #endif
    #if defined(CCFC3012PT)
        &PFI4_PFLASH,
        &PFI5_PFLASH,
    #endif
    };

    Mcu_RetVal = Mcu_LLD_SysCLockCheck(pMcu_ClockConfigPtr);
    if(Mcu_RetVal == (Std_ReturnType)E_OK)
    {
        Mcu_RetVal = Mcu_LLD_PeriCLockCheck(pMcu_ClockConfigPtr);
        if(Mcu_RetVal != (Std_ReturnType)E_OK)
        {
            /* Configure auxiliary u32Mcu_Selector and dividers */
            (void)Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers(&pMcu_ClockConfigPtr->cgmConfig);
            Mcu_RetVal = (Std_ReturnType)E_OK;
        }
        /* Configure peripheral clock gating, system clock source and clock sources in all power modes. */
        Mcu_LLD_McMeRunConfig(Mcu_gConfigPtr->Mcu_McMeConfigPtr);
        Mcu_LLD_PeriModeSet(pMcu_ClockConfigPtr->PeriConfigPtr);
        Mcu_LLD_SetIrc(&pMcu_ClockConfigPtr->cgmcsConfig.ircConfig);
    }
    else
    {
        /* Clears peripheral clock gating and all clock sources in all power modes.
         * Only an IRC type clock source is enabled and IRC as system clock source. */
        if (0u != SSCM.UOPS.B.HSE)
        {
            while(0U != HSM.HSM_STATUS)
            {
                /* Do nothing */
            }
        }
        Mcu_RetVal = Mcu_LLD_Reset();
        if(Mcu_RetVal != (Std_ReturnType)E_OK)
        {
            /* Do nothing */
        }
        else
        {
            (void)Mcu_LLD_ClockPCS_Init();
            /* Configure clock sources. */
            (void)Mcu_LLD_ConfigureCgmcs(pMcu_ClockConfigPtr);
            /* Configure system dividers */
            (void)Mcu_LLD_ConfigureSystemClockDividers(&pMcu_ClockConfigPtr->cgmConfig);
            /* Configure auxiliary u32Mcu_Selector and dividers */
            (void)Mcu_LLD_ConfigureAuxiliarySelectorsAndDividers(&pMcu_ClockConfigPtr->cgmConfig);

            #ifdef MCU_FLASH_WAIT_STATUS_CONFIG
            RegValue = PFLASH.PFCR1.R;
            RegValue &= ( uint32)(~( uint32)(FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32));
            RegValue |= ( uint32)((FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32) & pMcu_ClockConfigPtr->Mcu_FlashWSConfig);
            /* Set the AddressPipelining/Write/Read Wait State Control. */
            PFLASH.PFCR1.R = (volatile uint32)RegValue;
            #endif
            PRAMC.PRCR1.R = (uint32)pMcu_ClockConfigPtr->Mcu_SRamWSConfig;
            /* Configure peripheral clock gating, system clock source and clock sources in all power modes. */
            Mcu_LLD_McMeRunConfig(Mcu_gConfigPtr->Mcu_McMeConfigPtr);
            Mcu_LLD_PeriModeSet(pMcu_ClockConfigPtr->PeriConfigPtr);

            Mcu_RetVal = (Std_ReturnType)E_OK;
        }
    }
    #if (MCU_HARDVER == 3)
    /* Get Flash Swap Status */
    g_swapStatus = FLASH_Get_Swap_Status();
    #endif

    /* Enable Instruction Prefetch */
    for (index = 0U; index < ARRAY_SIZE(PFlash_Array); index++) /*PRQA S 2877*/
    {
        PFlash_Array[index]->PFCR1.R |= 0xFFFF0000U;
        PFlash_Array[index]->PFCR1.B.P0_PFLIM = 2U;
        PFlash_Array[index]->PFCR1.B.P0_IPFEN = 1U;

        PFlash_Array[index]->PFCR2.R |= 0xFFFF0000U;
        PFlash_Array[index]->PFCR2.B.P1_PFLIM = 2U;
        PFlash_Array[index]->PFCR2.B.P1_IPFEN = 1U;
    }

    Mcu_LLD_InternalVrefEn();

    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_GetPllStatus(void)
{
    VAR(Std_ReturnType, MCU_VAR) RetResult = (Std_ReturnType)E_OK;
    VAR(uint32, MCU_VAR) unlock_Count = 0U;
    VAR(uint32, MCU_VAR) Pll_Flag = 0U;

    if (PLLDIG_StPtr->PLL0CR.B.CLKCFG == (uint32)MCU_PLLCR_CFG_MASK)
    {
        Pll_Flag++;
        if(PLLDIG_StPtr->PLL0SR.B.LOCK != TRUE)
        {
            unlock_Count++;
        }
    }
    if (PLLDIG_StPtr->PLL1CR.B.CLKCFG == MCU_PLLCR_CFG_MASK)
    {
        Pll_Flag++;
        if(PLLDIG_StPtr->PLL1SR.B.LOCK != TRUE)
        {
            unlock_Count++;
        }
    }
    if(Pll_Flag == 0U)
    {
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if (unlock_Count > 0U)
        {
            /* at leas 1 pll that was ON is unlocked return that there are unlocked PLL's */
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* at leas 1 pll that was ON is unlocked return that there are unlocked PLL's */
            RetResult = (Std_ReturnType)E_OK;
        }
    }
    return RetResult;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_DistributePllClock(void)
{
    if(Mcu_gClockConfigPtr == NULL_PTR)
    {
        /* do nothing */
    }
    else
    {
        MC_ME_ChangeSysClk(MC_ME_StPtr, Mcu_gClockConfigPtr->mode_configuration.sysclk);
        (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static FUNC(void, MCU_CODE) Mcu_LLD_Wkpu_Reset(void)
{
    MC_ME_StPtr->IS.R = (MC_ME_StPtr->IS.R & 0x3FU);
    XOSC_StPtr->CTL.B.I_OSC = (XOSC_StPtr->CTL.B.I_OSC & 0x1U);
    /* Clear WKPU.WISR */
    #if (MCU_HARDVER != 3)
    WKPU.WISR0.R  = 0xFFFFFFFFUL;
    WKPU.WISR1.R  = 0xFFFFFFFFUL;
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*******************************************************************************
 * @brief      Set current chip mode
 * @param[in]  ChipMode chip_mode
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_LLD_Set_Chip_Mode \
( \
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_ModeConfigPtr
)
{
    VAR(Std_ReturnType, MCU_CODE)Mcu_RetVal = (Std_ReturnType)E_OK;

    switch (pMcu_ModeConfigPtr->Mcu_ChipMode) 
    {
        case me_mc_reset_mode:
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_reset_mode);
            break;
        }
        case me_mc_test_mode: 
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_test_mode);
            break;
        }
        case me_mc_safe_mode:
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_safe_mode);
            break;
        }
        case me_mc_drun_mode:
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->DRUN_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_drun_mode);
            break;
        }
        case me_mc_run0_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[0].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run0_mode);
            break;
        }
        case me_mc_run1_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[1].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run1_mode);
            break;
        }
        case me_mc_run2_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[2].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run2_mode);
            break;
        }
        case me_mc_run3_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->RUN_MC[3].R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_run3_mode);
            break;
        }
        case me_mc_halt0_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->HALT0_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_halt0_mode);
            break;
        }
        case me_mc_stop0_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                  (volatile uint32 *)&MC_ME_StPtr->STOP0_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_stop0_mode);
            break;
        }
        #if (MCU_HARDVER != 3)
        case me_mc_standby_mode: 
        {
            MC_ME_SetClockSources(pMcu_ModeConfigPtr->Mcu_TargetClock,
                                  pMcu_ModeConfigPtr->Mcu_IRC_En,
                                  pMcu_ModeConfigPtr->Mcu_XOSC_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL0_En,
                                  pMcu_ModeConfigPtr->Mcu_PLL1_En,
                                 (volatile uint32 *) &MC_ME_StPtr->STANDBY_MC.R);
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_standby_mode);
            break;
        }
        #endif
        case me_mc_reset_des_mode: 
        {
            Mcu_RetVal = Mcu_LLD_ChangeMode(me_mc_reset_des_mode);
            break;
        }
        default: 
        { 
            /* PRQA S 2024 */
            Mcu_RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    };
    return Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_SetMode \
( \
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_ModeConfigPtr
)
{
    P2CONST(Mcu_ModeConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_TargetModeConfigPtr;
    VAR(Mcu_ModeConfigType, MCU_VAR) Mcu_CurrentModeConfig;
    VAR(Mcu_ModeConfigType, MCU_VAR) Mcu_LowPowerModeConfig;

    Mcu_TargetModeConfigPtr = pMcu_ModeConfigPtr;

    if  ( (Mcu_TargetModeConfigPtr->Mcu_ChipMode == me_mc_halt0_mode) /* polyspace RTE:IDP */
        || (Mcu_TargetModeConfigPtr->Mcu_ChipMode == me_mc_stop0_mode) ) /* polyspace RTE:IDP */
    {
        /* The current clock mode, which needs to be restored after waking up */
        Mcu_CurrentModeConfig.Mcu_ChipMode = (Mcu_McModeType)MC_ME_StPtr->GS.B.S_CURRENT_MODE;
        Mcu_CurrentModeConfig.Mcu_IRC_En = MC_ME_StPtr->GS.B.S_IRC;
        Mcu_CurrentModeConfig.Mcu_XOSC_En = MC_ME_StPtr->GS.B.S_XOSC;
        Mcu_CurrentModeConfig.Mcu_PLL0_En = MC_ME_StPtr->GS.B.S_PLL0;
        Mcu_CurrentModeConfig.Mcu_PLL1_En = MC_ME_StPtr->GS.B.S_PLL1;
        Mcu_CurrentModeConfig.Mcu_TargetClock = MC_ME_StPtr->GS.B.S_SYSCLK;
        /* LowPwer Clock */
        /* Set current mode to the same clock configuration as low power mode */
        Mcu_LowPowerModeConfig.Mcu_ChipMode = (Mcu_McModeType)MC_ME_StPtr->GS.B.S_CURRENT_MODE;
        Mcu_LowPowerModeConfig.Mcu_IRC_En = Mcu_TargetModeConfigPtr->Mcu_IRC_En;
        Mcu_LowPowerModeConfig.Mcu_XOSC_En = Mcu_TargetModeConfigPtr->Mcu_XOSC_En;
        Mcu_LowPowerModeConfig.Mcu_PLL0_En = Mcu_TargetModeConfigPtr->Mcu_PLL0_En;
        Mcu_LowPowerModeConfig.Mcu_PLL1_En = Mcu_TargetModeConfigPtr->Mcu_PLL1_En;
        Mcu_LowPowerModeConfig.Mcu_TargetClock = Mcu_TargetModeConfigPtr->Mcu_TargetClock;
        Mcu_LowPowerModeConfig.PeriConfigPtr = Mcu_TargetModeConfigPtr->PeriConfigPtr;

        /* All peripherals need to be turned off before setting the clock configuration */
        /* Synchronous low power clock mode */
        Mcu_LLD_PeriModeSet(Mcu_LowPowerModeConfig.PeriConfigPtr);
        (void)Mcu_LLD_Set_Chip_Mode(&Mcu_LowPowerModeConfig);
        /* Turn off the interrupt flag that may affect wakeup */
        Mcu_LLD_Wkpu_Reset();
        /* Enter low power */
        (void)Mcu_LLD_Set_Chip_Mode(Mcu_TargetModeConfigPtr);
        if(Mcu_gClockConfigPtr != NULL_PTR)
        {
            Mcu_LLD_PeriModeSet(Mcu_gClockConfigPtr->PeriConfigPtr);
        }
        (void)Mcu_LLD_Set_Chip_Mode(&Mcu_CurrentModeConfig);
    }
    #if ((MCU_HARDVER == 2) || (MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
    else if (Mcu_TargetModeConfigPtr->Mcu_ChipMode == me_mc_standby_mode)
    {
        /* LowPower Clock */
        /* Set current mode to the same clock configuration as low power mode */
        Mcu_LowPowerModeConfig.Mcu_ChipMode = me_mc_drun_mode; // (Mcu_McModeType)MC_ME_StPtr->GS.B.S_CURRENT_MODE;
        Mcu_LowPowerModeConfig.Mcu_IRC_En = Mcu_TargetModeConfigPtr->Mcu_IRC_En;
        Mcu_LowPowerModeConfig.Mcu_XOSC_En = Mcu_TargetModeConfigPtr->Mcu_XOSC_En;
        Mcu_LowPowerModeConfig.Mcu_PLL0_En = Mcu_TargetModeConfigPtr->Mcu_PLL0_En;
        Mcu_LowPowerModeConfig.Mcu_PLL1_En = Mcu_TargetModeConfigPtr->Mcu_PLL1_En;
        Mcu_LowPowerModeConfig.Mcu_TargetClock = Mcu_TargetModeConfigPtr->Mcu_TargetClock;
        Mcu_LowPowerModeConfig.PeriConfigPtr = Mcu_TargetModeConfigPtr->PeriConfigPtr;
        /* All peripherals need to be turned off before setting the clock configuration */
        Mcu_LLD_PeriModeSet(Mcu_LowPowerModeConfig.PeriConfigPtr);
        /* Synchronous low power clock mode */
        (void)Mcu_LLD_Set_Chip_Mode(&Mcu_LowPowerModeConfig);
        /* PMU_CFG */
        *((volatile uint32*)0xfffa059CU) &= (uint32)(~(0x1000UL | 0x800UL));   /* Close PMU_CFG */
        /* Turn off the interrupt flag that may affect wakeup */
        Mcu_LLD_Wkpu_Reset();
        /* Enter low power */
        (void)Mcu_LLD_Set_Chip_Mode(Mcu_TargetModeConfigPtr);
    }
    #endif
    else
    {
        #if 0
        if( ((Mcu_TargetModeConfigPtr->Mcu_PLL0_En == 1U) || (Mcu_TargetModeConfigPtr->Mcu_PLL1_En == 1U))
            && (MC_ME_StPtr->GS.B.S_XOSC == 0U))
        {
            Mcu_CurrentModeConfig.Mcu_ChipMode = me_mc_drun_mode;
            Mcu_CurrentModeConfig.Mcu_IRC_En = Mcu_TargetModeConfigPtr->Mcu_IRC_En;
            Mcu_CurrentModeConfig.Mcu_XOSC_En = Mcu_TargetModeConfigPtr->Mcu_XOSC_En;
            Mcu_CurrentModeConfig.Mcu_PLL0_En = 0U;
            Mcu_CurrentModeConfig.Mcu_PLL1_En = 0U;
            Mcu_CurrentModeConfig.Mcu_TargetClock = CGM_SYSTEM_CLOCK_SRC_IRCOSC;
            (void)Mcu_LLD_Set_Chip_Mode(&Mcu_CurrentModeConfig);
        }
        #endif
        Mcu_LLD_PeriModeSet(Mcu_TargetModeConfigPtr->PeriConfigPtr);
        (void)Mcu_LLD_Set_Chip_Mode(Mcu_TargetModeConfigPtr);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_PerformReset(Mcu_Rgm_ResetType ResetType)
{
    VAR(Mcu_ModeConfigType, MCU_VAR) ResetModeConfig;
    if(ResetType == MCU_FUNC_RESET)
    {
        ResetModeConfig.Mcu_ChipMode = me_mc_reset_mode;
    }
    else
    {
        ResetModeConfig.Mcu_ChipMode = me_mc_reset_des_mode;
    }
    (void)Mcu_LLD_Set_Chip_Mode(&ResetModeConfig);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_ResetType, MCU_CODE) Mcu_LLD_GetResetReason(void)
{
    VAR(Mcu_ResetType, MCU_VAR) ResetReason = MCU_NO_RESET_REASON;
    VAR(uint32, MCU_VAR) RegValue = 0U;
    VAR(uint32, MCU_VAR) Index = 0U;
    VAR(uint32, MCU_VAR) ResetOffset = 0U;
    VAR(uint32, MCU_VAR) Count = 0U;

    RegValue = (MC_RGM.DES.R & RGM_DES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[0U] = RegValue;
    }
    RegValue = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[1U] = RegValue;
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & RGM_DES_RWBITS_MASK32) != 0U)
        {
            if((Mcu_ReasonReg[0U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(Count == 0U)
                {
                    ResetReason = (Mcu_ResetType) ResetOffset;
                    Count++;
                }
                else
                {
                    ResetReason = (Mcu_ResetType) MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            ResetOffset++;
        }
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if((((uint32)0x01UL << Index) & RGM_FES_RWBITS_MASK32) != 0U)
        {
            if((Mcu_ReasonReg[1U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(Count == 0U)
                {
                    ResetReason = (Mcu_ResetType) ResetOffset;
                    Count++;
                }
                else
                {
                    ResetReason = (Mcu_ResetType) MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            ResetOffset++;
        }
    }

    MC_RGM.DES.R = (MC_RGM.DES.R & RGM_DES_RWBITS_MASK32);
    MC_RGM.FES.R = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    return (Mcu_ResetType)ResetReason;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_LLD_GetResetRaw(void)
{
    VAR(Mcu_RawResetType, MCU_VAR) ResetRaw = (Mcu_RawResetType)0U;
    VAR(uint32, MCU_VAR) RegValue = 0U;
    VAR(uint32, MCU_VAR) ResetOffset = 0U;
    VAR(uint32, MCU_VAR) Index = 0U;

    RegValue = (uint32)(MC_RGM.DES.R & RGM_DES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[0U] = RegValue;
    }
    RegValue = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[1U] = RegValue;
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & RGM_DES_RWBITS_MASK32) != 0U)/*PRQA S 2896*/
        {
            if((Mcu_ReasonReg[0U] & (uint32)(0x01UL << Index)) != 0U)
            {
                ResetRaw |= (uint32)(0x01UL << ResetOffset);
            }
            ResetOffset++;
        }
    }
    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & (uint32)RGM_FES_RWBITS_MASK32) != 0U)/*PRQA S 2896*/
        {
            if((Mcu_ReasonReg[1U] & (Mcu_RawResetType)(0x01UL << Index)) != 0U)
            {
                ResetRaw |= (uint32)(0x01UL << ResetOffset);
            }
            ResetOffset++;
        }
    }

    MC_RGM.DES.R = (MC_RGM.DES.R & RGM_DES_RWBITS_MASK32);
    MC_RGM.FES.R = (MC_RGM.FES.R & RGM_FES_RWBITS_MASK32);
    return (Mcu_RawResetType)ResetRaw;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_LLD_GetRamState(void)
{
    VAR(Mcu_RamStateType, MCU_VAR) RamState = MCU_RAMSTATE_INVALID;

    if(MEMU.ERR_FLAG.B.SR_CE == TRUE)
    {
    /* Do nothing */
    }
    else if(MEMU.ERR_FLAG.B.SR_UCE == TRUE)
    {
    /* Do nothing */
    }
    else if(MEMU.ERR_FLAG.B.PR_CE == TRUE)
    {
    /* Do nothing */
    }
    else if(MEMU.ERR_FLAG.B.PR_UCE == TRUE)
    {
    /* Do nothing */
    }
    else
    {
        RamState = MCU_RAMSTATE_VALID;
    }

    return (Mcu_RamStateType)RamState;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PeriModeSet (P2CONST(Mcu_PeriConfigType, AUTOMATIC, MCU_APPL_CONST) PeriConfigPtr)
{
    VAR(uint32, MCU_VAR) index;
    for(index = 0U; index < (uint32)MC_ME_PERIPH_INSTANCE_COUNT; index++)
    {
        MC_ME_StPtr->PCTL[(uint8)PeriConfigPtr[index].McMePeriNameConfig].R = (/* polyspace RTE:OBAI*/
                                  (uint8)MC_ME_PCTLn_RUN_CFG(PeriConfigPtr[index].McMeRunConfig)
                                | (uint8)MC_ME_PCTLn_LP_CFG(PeriConfigPtr[index].McMeLowPowerConfig) );
    }
    (void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PeriResetPend 
    (P2CONST(Mcu_PeripheralResetType, AUTOMATIC, MCU_APPL_CONST) ResetConfigPtr)
{
    MC_RGM.PRST0.R = ResetConfigPtr->RgmGroup0;
    MC_RGM.PRST1.R = ResetConfigPtr->RgmGroup1;
    MC_RGM.PRST2.R = ResetConfigPtr->RgmGroup2;
    MC_RGM.PRST3.R = ResetConfigPtr->RgmGroup3;
    MC_RGM.PRST4.R = ResetConfigPtr->RgmGroup4;
    MC_RGM.PRST5.R = ResetConfigPtr->RgmGroup5;
    MC_RGM.PRST6.R = ResetConfigPtr->RgmGroup6;
    MC_RGM.PRST7.R = ResetConfigPtr->RgmGroup7;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PeriResetClose (VAR(void, AUTOMATIC))
{
    MC_RGM.PRST0.R = 0x0U;
    MC_RGM.PRST1.R = 0x0U;
    MC_RGM.PRST2.R = 0x0U;
    MC_RGM.PRST3.R = 0x0U;
    MC_RGM.PRST4.R = 0x0U;
    MC_RGM.PRST5.R = 0x0U;
    MC_RGM.PRST6.R = 0x0U;
    MC_RGM.PRST7.R = 0x0U;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_CoreSynchronise (VAR(void, AUTOMATIC))
{
    VAR(uint8, MCU_VAR) CoreId;
    VAR(uint8, MCU_VAR) CoreIdx;
    volatile VAR(uint8, MCU_VAR) CoreStatus = CORE_NOT_READY;
    CoreId = Mcu_LLD_Get_Core_Id();
    Mcu_gCoreStatus[CoreId] = CORE_READY;/* polyspace RTE:OBAI*/

    while(CoreStatus == CORE_NOT_READY)
    {
        for(CoreIdx = 0U; CoreIdx < MCU_CORE_COUNT; CoreIdx++)  /*PRQA S 2877*/
        {
            if(Mcu_gCoreStatus[CoreIdx] == CORE_NOT_READY)
            {
                break;
            }
        }
        if(CoreIdx == MCU_CORE_COUNT)
        {
            CoreStatus = CORE_READY;
        }
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_InternalVrefEn (VAR(void, AUTOMATIC))
{
    /* EQADC VREF/Temperature channels enable.
     *  SSCM module offsets the 0x38 register bit2: VREF enable,
     *  SSCM module offsets the 0x38 register bit3: Temperature enable */
#ifdef RESOURCE_SUPPORT_EQADC_VREF_SW
    #if (RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_1)
    /* The enable bit of SDADC needs to be turned on (The VREF switch is internally connected to the SDADC_EN),
     * and SSCM module offsets the 0x38 register, bit2/3    */

    /** 1.The enable bit of SDADC needs to be turned on **/
    volatile uint8 val_AC0_DC1_DE = 0u;
    volatile uint8 val_CurrentRunPC7 = 0u;
    volatile uint8 val_CurrentMode = 0u;
    volatile uint8 val_CurrentPCTL = 0u;

    if ((MC_CGM.AC0_DC1.R & MC_CGM_AC0_DC1_DE_MASK) != MC_CGM_AC0_DC1_DE_MASK)
    {
        MC_CGM.AC0_DC1.R |= (uint32)MC_CGM_AC0_DC1_DE_MASK;
        val_AC0_DC1_DE = FALSE;
    }
    else
    {
        val_AC0_DC1_DE = TRUE;
    }

    val_CurrentRunPC7 = MC_ME.RUN_PC[7].R;
	val_CurrentMode = MC_ME.GS.B.S_CURRENT_MODE;
	val_CurrentPCTL = MC_ME.PCTL[60].B.RUN_CFG;

	MC_ME.RUN_PC[7].R |= 1U << val_CurrentMode;
	MC_ME.PCTL[60].R &= 0xF8U;
	MC_ME.PCTL[60].R |= 7U;

	(void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);

    (*(volatile uint32 *) 0xFFF0C000UL) |= 0x1UL;   /* SDADC_0 enable */

    if(((*(volatile uint32 *) 0xFFF0C000UL) & 0x1U) != 1U)
    {
    	/*error*/
    }

    if (FALSE == val_AC0_DC1_DE)
    {
        MC_CGM.AC0_DC1.R &= (uint32)(~(uint32)MC_CGM_AC0_DC1_DE_MASK);
    }

	MC_ME.RUN_PC[7].R |= val_CurrentRunPC7;
	MC_ME.PCTL[60].R &= 0xF8U;
	MC_ME.PCTL[60].R |= val_CurrentPCTL;

	(void)Mcu_LLD_ChangeMode(me_mc_mode_notchange);

	/** 2.SSCM module offsets the 0x38 register, bit2/3 **/
    SSCM.CHIP_CR.R |= (uint32)(SSCM_CHIP_CR_EN_VREF_MASK | SSCM_CHIP_CR_EN_TS_MASK);

    #elif (RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_2)
    /* SSCM module offsets the 0x38 register, bit2/3/4
     * (The switch of SDADC_EN has been modified to bit 4 to achieve the function)  */
    SSCM.CHIP_CR.R |= (uint32)(SSCM_CHIP_CR_EN_VREF_MASK | SSCM_CHIP_CR_EN_TS_MASK | SSCM_CHIP_CR_EN_SDADC_BIAS_MASK);

    #elif (RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_3)
    /* SSCM module offsets the 0x38 register, bit2/3
     * (The functions of bit2 and bit4 have been combined into bit2) */
    SSCM.CHIP_CR.R |= (uint32)(SSCM_CHIP_CR_EN_VREF_MASK | SSCM_CHIP_CR_EN_TS_MASK);

    #else
        #error "RESOURCE_SUPPORT_EQADC_VREF_SW error!"
    #endif /* RESOURCE_SUPPORT_EQADC_VREF_SW == RESOURCE_SUPPORT_EQADC_VREF_SW_CTRL_X */

#else
    #error "RESOURCE_SUPPORT_EQADC_VREF_SW no defined!"
#endif /* RESOURCE_SUPPORT_EQADC_VREF_SW */
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#if MCU_FCCU_ENABLE == STD_ON
/*
 * @brief Clear Fault Status Register
 *
 * This function use to clear the rf fault status register
 *
 * @param[in] faultIndex: FCCU failure input signal index
 * @retval    E_OK: success clearing faults
 *            Std_ReturnTypeIMEOUT: timeout operation
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
Std_ReturnType FCCU_LLD_ClearFaults(uint8 faultIndex) /* PRQA S 1505 */
{
    uint8 index, regIdx, bitPos;
    uint32 timeout;
    Std_ReturnType status = (Std_ReturnType)E_OK;

    if (faultIndex >= FCCU_MAX_FAULTS_NO)
    {
        for (index = 0U; index < FCCU_RF_MAX_GROUP; index++)
        {
            /* set recoverable fault key */
            FCCU.RFK.R = FCCU_RECOVERABLE_FAULT_KEY;
            /* clear all faults */
            FCCU.RF_S[index].R = 0xFFFFFFFFU;
            /* wait operation 12 done */
            timeout = FCCU_OP_TIMEOUT_CONFIG;

            while ((FCCU.CTRL.B.OPS == (uint8)FCCU_OPS_IN_PROGRESS) && (timeout > 0U))
            {
                timeout--;
            }

            /* timeout happen */
            if (timeout == 0U)
            {
                status = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }
    else
    {
        regIdx = faultIndex >> 5U;   /* divide by 32 */
        bitPos = faultIndex & 0x1FU; /* modulo by 32 */

        /* set recoverable fault key */
        FCCU.RFK.R = FCCU_RECOVERABLE_FAULT_KEY;
        if(bitPos < 32U)
        {
            /* clear all faults */
            FCCU.RF_S[regIdx].R = (uint32)(1UL << (uint32)bitPos);
        }
        /* wait operation 12 done */
        timeout = FCCU_OP_TIMEOUT_CONFIG;

        while ((FCCU.CTRL.B.OPS == (uint8)FCCU_OPS_IN_PROGRESS) && (timeout > 0U))
        {
            timeout--;
        }

        /* timeout happen */
        if (timeout == 0U)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }


    }
    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Run operation
 *
 * This function use to run fcc operation
 *
 * @param[in] opRun: operation run
 * @retval    E_OK: success run operation
 *            Std_ReturnTypeIMEOUT: timeout run operation
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static Std_ReturnType FCCU_LLD_RunOperation(const fccu_op_run_t opRun) /* PRQA S 1505 */
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    uint32 timeout = FCCU_OP_TIMEOUT_CONFIG;

    /* wait for the last operation complete */
    while (((uint8)FCCU_OPS_IN_PROGRESS == FCCU.CTRL.B.OPS) && (timeout != 0U))
    {
        timeout--;
    }

    if (0U == timeout)
    {
        status = (Std_ReturnType)E_NOT_OK;
    }

    if (status == (Std_ReturnType)E_OK)
    {
        /* get operation status */
        switch (opRun)
        {
            case FCCU_RUN_OP1:
                FCCU.CTRLK.R = FCCU_UNLOCK_OP1_KEY;
                FCCU.CTRL.R = (uint32)FCCU_RUN_OP1;
                break;
            case FCCU_RUN_OP2:
                FCCU.CTRLK.R = FCCU_UNLOCK_OP2_KEY;
                FCCU.CTRL.R = (uint32)FCCU_RUN_OP2;
                break;
            default:
                FCCU.CTRL.R = (uint32)opRun;
                break;
        }

        timeout = FCCU_OP_TIMEOUT_CONFIG;
        /* wait for the last operation complete */
        while (((uint8)FCCU_OPS_IN_PROGRESS == FCCU.CTRL.B.OPS) && (timeout != 0U))
        {
            timeout--;
        }

        if (0U == timeout)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
    }
    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Read Recoverable Faults
 *
 * This function update and read recoverable faults
 *
 * @param[in] flags: faults flags
 * @retval    E_OK: success run operation
 *            Std_ReturnTypeIMEOUT: timeout operation
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static Std_ReturnType FCCU_LLD_ReadFaults(fccu_faults_flags_t *flags) /* PRQA S 1505 */
{
    uint8 index;
    Std_ReturnType status = (Std_ReturnType)E_OK;

    for (index = 0; index < FCCU_RF_MAX_GROUP; index++)
    {
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP10);
        if ((Std_ReturnType)E_OK == status)
        {
            flags->faultsFlags[index] = FCCU.RF_S[index].R;
        }
        else
        {
            return status;
        }
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Read FCCU state
 *
 * This function use to read fccu state
 *
 * @retval the state of fccu module
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static fccu_status_t FCCU_LLD_GetState(void) /* PRQA S 1505 */
{
    Std_ReturnType status;
    fccu_status_t fccuStatus = FCCU_UNKNOWN_STATE;

    status = FCCU_LLD_RunOperation(FCCU_RUN_OP3);
    if ((Std_ReturnType)E_OK == status)
    {
        switch (FCCU.STAT.B.STATUS)
        {
            case 0U:
                fccuStatus = FCCU_NORMAL_STATE;
                break;
            case 1U:
                fccuStatus = FCCU_CONFIG_STATE;
                break;
            case 2U:
                fccuStatus = FCCU_ALARM_STATE;
                break;
            default:
                fccuStatus = FCCU_FAULT_STATE;
                break;
        }
    }

    return fccuStatus;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static uint8 FCCU_LLD_CheckFaultFlags(const fccu_faults_flags_t *faultFlags)
{
    uint32_t index;
    uint32_t bits;
    uint8 ret = FALSE;

    for (index = 0U; index < FCCU_RF_MAX_GROUP; index++)
    {
        for (bits = 0; bits < 32U; bits++)
        {
            if (index == 0U)
            {
                if (bits != 3U) /* do not check FCCU channel 3 faults input */
                {
                    if ((faultFlags->faultsFlags[index] & (0x1UL << bits)) != 0U)/* polyspace RTE:NIV*/
                    {
                        ret = TRUE;
                        break;
                    }
                }
            }
            else if (index == 1U)
            {
                #if ((MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
                 if ((bits != 7U) && (bits != 11U) && (bits != 19U)) /* do not check FCCU channel 43,51,54 faults input */
                #else
                if ((bits != 11U) && (bits != 19U) && (bits != 22U)) /* do not check FCCU channel 43,51,54 faults input */
                #endif
                {
                    if ((faultFlags->faultsFlags[index] & (0x1UL << bits)) != 0U) /* polyspace RTE:NIV */
                    {
                        ret = TRUE;
                        break;
                    }
                }
            }
            else
            {
                if ((faultFlags->faultsFlags[index] & (0x1UL << bits)) != 0U) /* polyspace RTE:NIV */
                {
                    ret = TRUE;
                    break;
                }
            }
        }

        if (TRUE == ret)
        {
            break;
        }
    }

    return ret;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* @brief Set FCCU into config state
 *
 * This function set fccu into config state
 *
 * @retval E_OK: success to set fccu in config state
 *         Std_ReturnTypeIMEOUT: timeout operation
 *         FCCU_ERROR_SET_CONFIG: fail to set fccu in config state
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static Std_ReturnType FCCU_LLD_SetConfigState(void) /* PRQA S 1505 */
{
    Std_ReturnType status = FCCU_ERROR_OTHER;
    fccu_status_t fccuStatus;
    fccu_faults_flags_t faultsFlags;
    uint8 isFaultExist = TRUE;
    uint32 timeout = FCCU_OP_TIMEOUT_CONFIG;
    uint8 fccuOpStatus;

    /* Unlock configuration */
    FCCU.TRANS_LOCK.R = FCCU_TRANSKEY_UNLOCK_VAL;

    fccuStatus = FCCU_LLD_GetState();
    if (fccuStatus == FCCU_NORMAL_STATE)
    {
        /* clear all faults */
        status = FCCU_LLD_ClearFaults(FCCU_MAX_FAULTS_NO);
        if ((Std_ReturnType)E_OK == status)
        {
            fccuOpStatus = (uint8)FCCU.CTRL.B.OPS;
            if ((uint8)FCCU_OPS_SUCCESSFUL != fccuOpStatus)
            {
                /* read FCCU state */
                (void)FCCU_LLD_RunOperation(FCCU_RUN_OP3);
            }

            /* set fccu to enter config state */
            (void)FCCU_LLD_RunOperation(FCCU_RUN_OP1);
        }
        fccuStatus = FCCU_LLD_GetState();
        if (FCCU_CONFIG_STATE == fccuStatus)
        {
            status = (Std_ReturnType)E_OK;
        }
        else
        {
            status = FCCU_ERROR_SET_CONFIG;
        }
    }
    else if (fccuStatus == FCCU_CONFIG_STATE)
    {
        status = (Std_ReturnType)E_OK;
    }
    else if (fccuStatus == FCCU_UNKNOWN_STATE)
    {
        status = FCCU_ERROR_SET_CONFIG;
    }
    else /* Alarm or Fault State */
    {
        do
        {
            status = FCCU_LLD_ClearFaults(FCCU_MAX_FAULTS_NO);
            if ((Std_ReturnType)E_OK == status)
            {
                status = FCCU_LLD_ReadFaults(&faultsFlags);
                if ((Std_ReturnType)E_OK == status)
                {
                    isFaultExist = FCCU_LLD_CheckFaultFlags(&faultsFlags);
                }
            }
            timeout--;
        } while ((isFaultExist == (uint8)TRUE) && (timeout != 0U));

        if (timeout == 0U)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* set fccu in noraml state */
            (void)FCCU_LLD_RunOperation(FCCU_RUN_OP2);
            if (FCCU_NORMAL_STATE != FCCU_LLD_GetState())
            {
                status = FCCU_ERROR_SET_CONFIG;
            }
            else
            {
                /* set fccu in config state */
                (void)FCCU_LLD_RunOperation(FCCU_RUN_OP1);
                if (FCCU_CONFIG_STATE != FCCU_LLD_GetState())
                {
                    status = FCCU_ERROR_SET_CONFIG;
                }
                else
                {
                    status = (Std_ReturnType)E_OK;
                }
            }
        }
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Set FCCU into normal state
 *
 * @retval E_OK: set fccu successfully
 *         FCCU_ERROR_SET_NORMAL: fails to set fccu state
 *         Std_ReturnTypeIMEOUT: run operation timeout
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static Std_ReturnType FCCU_LLD_SetNormalState(void) /* PRQA S 1505 */
{
    uint8 isFaultExist = TRUE;
    uint32 timeout = FCCU_OP_TIMEOUT_CONFIG;
    Std_ReturnType status = FCCU_ERROR_OTHER;
    fccu_status_t fccuStatus;
    fccu_faults_flags_t faultsFlags;

    fccuStatus = FCCU_LLD_GetState();
    if (FCCU_NORMAL_STATE == fccuStatus)
    {
        /* fccu already in normal state */
        status = (Std_ReturnType)E_OK;
    }
    else if (FCCU_CONFIG_STATE == fccuStatus)
    {
        /* set fccu into noraml state */
        (void)FCCU_LLD_RunOperation(FCCU_RUN_OP2);
        if (FCCU_NORMAL_STATE == FCCU_LLD_GetState())
        {
            status = (Std_ReturnType)E_OK;
        }
        else
        {
            status = FCCU_ERROR_SET_NORMAL;
        }
    }
    else if ((FCCU_ALARM_STATE == fccuStatus) || (FCCU_FAULT_STATE == fccuStatus))
    {
        do
        {
            status = FCCU_LLD_ClearFaults(FCCU_MAX_FAULTS_NO);
            if ((Std_ReturnType)E_OK == status)
            {
                status = FCCU_LLD_ReadFaults(&faultsFlags);
                if ((Std_ReturnType)E_OK == status)
                {
                    isFaultExist = FCCU_LLD_CheckFaultFlags(&faultsFlags);
                }
            }
            timeout--;
        } while ((isFaultExist == TRUE) && (timeout != 0U));

        if (timeout == 0U)
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            (void)FCCU_LLD_RunOperation(FCCU_RUN_OP2);
            if (FCCU_NORMAL_STATE == FCCU_LLD_GetState())
            {
                status = (Std_ReturnType)E_OK;
            }
            else
            {
                status = FCCU_ERROR_SET_NORMAL;
            }
        }
    }
    else
    {
        status = FCCU_ERROR_SET_NORMAL;
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Defines the preset value of the watchdog timer for the
 *        recovery from the CONFIG state
 *
 *
 * @param[in] to: configuration time-out value
 * @retval E_OK: set configuration timeout successfully
 *         FCCU_ERROR_CONFIG_TIMEOUT: fail to set configuration timeout
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
Std_ReturnType FCCU_LLD_SetCfgTimeout(uint8 to) /* PRQA S 1503 */
{
    fccu_status_t fccuState;
    Std_ReturnType status;

    fccuState = FCCU_LLD_GetState();
    if (FCCU_CONFIG_STATE == fccuState)
    {
        status = FCCU_LLD_SetNormalState();
        if ((Std_ReturnType)E_OK != status)
        {
            status = FCCU_ERROR_CONFIG_TIMEOUT;
        }
        else
        {
            FCCU.CFG_TO.R = to;
        }
    }
    else
    {
        FCCU.CFG_TO.R = to;
        status = (Std_ReturnType)E_OK;
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Lock the fccu configuration
 *
 *
 * @param[in] lock: type of lock
 * @retval None
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static void FCCU_LLD_LockConfig(const Mcu_FccuLockType lock) /* PRQA S 1505 */
{
    switch (lock)
    {
        case FCCU_TRANSIENTLY_UNLOCK:
            FCCU.TRANS_LOCK.B.TRANSKEY = FCCU_TRANSKEY_UNLOCK_VAL;
            break;
        case FCCU_TRANSIENTLY_LOCK:
            FCCU.TRANS_LOCK.B.TRANSKEY = FCCU_TRANSKEY_LOCK_VAL;
            break;
        case FCCU_PERANENTLY_LOCK:
            FCCU.PERMNT_LOCK.B.PERMNTKEY = FCCU_PERMENTKEY_LOCK_VAL;
            break;
        default:
            /* Do nothing */
            break;
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Check fccu IRQ_STAT register
 *
 *
 * @param[in] intStatus: status of interrupt
 * @retval 1: int bit occurs in IRQ_STAT register
 *         0: int bit nor occurs
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
uint8 FCCU_LLD_CheckIntStatus(fccu_int_status_t intStatus) /* PRQA S 1505 */
{
    uint32 regIrqStat = (uint32)FCCU.IRQ_STAT.R;
    if((uint32)intStatus < 32U)
    {
        regIrqStat &= (1UL << (uint32)intStatus);
    }
    return (regIrqStat != 0UL) ? 1U : 0U;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Clear fccu interrupt flag
 *
 *
 * @param[in] intStatus: status of interrupt
 * @retval None
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static void FCCU_LLD_ClearIntFlag(fccu_int_status_t intStatus) /* PRQA S 1505 */
{
    uint32 regIrqStat = 0U;
    if((uint32)intStatus < 32U)
    {
        FCCU.IRQ_STAT.R = FCCU.IRQ_STAT.R & ~(1UL << (uint32)intStatus);
        regIrqStat = (uint32)(1UL << (uint32)intStatus);
    }
    FCCU.IRQ_STAT.R = regIrqStat;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief FCCU Alarm Interrupt Callback function
 *
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static void FCCU_LLD_AlarmIrqCallback(void)
{
    uint8 index;
    uint8 reg_index, bit_pos;
    VAR(uint32, MCU_VAR)Mcu_FccuRf;
    /* Update faults status */
    (void)FCCU_LLD_RunOperation(FCCU_RUN_OP10);

    for (index = 0U; index < Mcu_gFccuConfigPtr->Mcu_FccuRfCfgNumber; index++)/* polyspace RTE:IDP */
    {
        reg_index = Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel >> 5U; /* divide by 32 */
        bit_pos = Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel & 0x1FU; /* modulo by 32 */
        if(bit_pos < 32U)
        {
            Mcu_FccuRf = (uint32)FCCU.RF_S[reg_index].R;/* polyspace RTE:OBAI*/
            Mcu_FccuRf = (Mcu_FccuRf & (1UL << (uint32)bit_pos));
            if ((reg_index < FCCU_RF_MAX_GROUP) && ( Mcu_FccuRf != 0UL))
            {
                if((Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_FM_PLL_0_CH_29) 
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_FM_PLL_1_CH_30)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_0_OSC_CH_31)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_0_PLL_CH_32)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_COMP_SUBSYS_CH_33)
                || (Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel == (uint8)FCCU_FAILURE_CMU_OTHER_CH_34))
                {
                    Mcu_ClockFailureCmu_ISR();
                }
                /* Clear Fault */
                (void)FCCU_LLD_ClearFaults(Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[index].Mcu_FccuChannel);
            }
        }
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Set the recoverable fault configuration
 *
 *
 * @param[in] cfg: recoverable fault configuration
 * @retval E_OK: set recoverable configuration successfully
 *         FCCU_ERROR_SET_NORMAL: fail to set fccu in noraml state
 *         FCCU_ERROR_SET_CONFIG: fail to set fccu in config state
 *         Std_ReturnTypeIMEOUT: run operation timeout
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static Std_ReturnType FCCU_LLD_SetRfConfig(const Mcu_FccuRfConfigType *cfg) /* PRQA S 1505 */
{
    uint8 regIdx;
    uint8 bitPos;
    Std_ReturnType status = (Std_ReturnType)E_OK;

    status = FCCU_LLD_SetConfigState();
    if ((Std_ReturnType)E_OK == status)
    {
        /* set rf configurations */
        regIdx = cfg->Mcu_FccuChannel >> 5U;   /* divide by 32 */
        bitPos = cfg->Mcu_FccuChannel & 0x1FU; /* modulo by 32 */
        if(bitPos < 32U)
        {
            /* recoverable fault configuration */
            FCCU.RF_CFG[regIdx].R = ((uint32)(FCCU.RF_CFG[regIdx].R & ~((uint32)1UL << bitPos))) | ((uint32)(((uint32)cfg->Mcu_FccuRecoveryConfig) << bitPos));/* polyspace RTE:OBAI*/

            /* allow fccu moves ALARM or FAULT state */
            FCCU.RF_E[regIdx].R = (FCCU.RF_E[regIdx].R & ~(1UL << bitPos)) | (1UL << bitPos);

            /* set timeout enable
            * 0 FCCU moves into the FAULT state if the respective fault is enabled
            * 1 FCCU moves into the ALARM state if the respective fault is enabled
            */
            FCCU.RF_TOE[regIdx].R = (FCCU.RF_TOE[regIdx].R & ~(1UL << bitPos)) \
                                    | (((cfg->Mcu_FccuToAlarmEn == TRUE) ? 1UL : 0UL) << bitPos);

            /* set irq alarm en */
            FCCU.IRQ_ALARM_EN[regIdx].R = (FCCU.IRQ_ALARM_EN[regIdx].R & ~(1UL << bitPos)) \
                                        | (((cfg->Mcu_FccuRfReactionEnCfg.irq_alarm_en == TRUE) ? 1UL : 0UL) << bitPos);
            /* set nmi en */
            FCCU.NMI_EN[regIdx].R = (FCCU.NMI_EN[regIdx].R & ~(1UL << bitPos)) \
                                | (((cfg->Mcu_FccuRfReactionEnCfg.nmi_en == TRUE) ? 1UL : 0UL) << bitPos);

            /* set eout signaling enable */
            FCCU.EOUT_SIG_EN[regIdx].R = (FCCU.EOUT_SIG_EN[regIdx].R & ~(1UL << bitPos))
                                    | (((cfg->Mcu_FccuRfReactionEnCfg.eout_sig_en == TRUE) ? 1UL : 0UL) << bitPos);

            /* set reset Mcu_FccuRfReactionEnCfg */
            regIdx = cfg->Mcu_FccuChannel >> 4U;   /* divide by 16 */
            bitPos = (uint8)((cfg->Mcu_FccuChannel & 0xFU) << 1U); /* modulo by 16 */

            FCCU.RFS_CFG[regIdx].R = (FCCU.RFS_CFG[regIdx].R & ~(3UL << bitPos)) | (((uint32)cfg->Mcu_FccuReactionConfig ) << bitPos);
        }

        status = (Std_ReturnType)FCCU_LLD_SetNormalState();
    }
    else
    {
        status = (Std_ReturnType)E_NOT_OK;
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Set fccu eout configuration
 *
 *
 * @param[in] eoutCfg: configuration of errpin out
 * @retval E_OK: set fccu eout configuration successfully
 *         FCCU_ERROR_SET_EOUT: fail to set fccu eout configuration
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
static Std_ReturnType FCCU_LLD_SetEout(const Mcu_FccuEoutConfigType *eoutCfg) /* PRQA S 1505,3673 */
{
    Std_ReturnType status;

    status = FCCU_LLD_SetConfigState();
    if ((Std_ReturnType)E_OK == status)
    {
        FCCU.CFG.B.FCCU_SET_AFTER_RESET = (eoutCfg->set_after_reset == TRUE) ? 1U : 0U;
        FCCU.CFG.B.FCCU_SET_CLEAR = (uint8_t)eoutCfg->control;
        FCCU.CFG.B.OD = (uint8_t)eoutCfg->output;
        #if ((MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))
        FCCU.CFG.B.FOP = (uint8_t)eoutCfg->fop;
        FCCU.CFG.B.EOFS = (uint8_t)eoutCfg->eof;
        #endif
        FCCU.CFG.B.SM = (uint8)eoutCfg->switch_mode;
        FCCU.CFG.B.PS = (uint8)eoutCfg->polarity_sel;
        FCCU.CFG.B.FOM = (uint8)eoutCfg->mode;
        FCCU.DELTA_T.B.DELTA_T = eoutCfg->delta_t_value;
    }
    else
    {
         status = FCCU_ERROR_SET_EOUT;
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Read the FCCU frozen status flags
 *
 *
 * @param[in] frozenType: type of frozen status
 * @param[in] frozenStatus: pointer to frozen status address
 * @retval E_OK: read status successfully
 *         FCCU_ERROR_UPDATE_FREEZE: fail to read frozen status
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
Std_ReturnType FCCU_LLD_GetFrozenStatus(fccu_frozen_type_t frozenType, uint16 *frozenStatus) /* PRQA S 1503 */
{
    Std_ReturnType status = FCCU_ERROR_UPDATE_FREEZE;

    switch (frozenType)
    {
    case FCCU_FROZEN_N2AF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP4);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.N2AF_STATUS.B.NAFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    case FCCU_FROZEN_A2FF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP5);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.A2FF_STATUS.B.AFFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    case FCCU_FROZEN_N2FF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP6);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.N2FF_STATUS.B.NFFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    case FCCU_FROZEN_F2AF_STATUS:
        status = FCCU_LLD_RunOperation(FCCU_RUN_OP7);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            *frozenStatus = (uint16)FCCU.F2A_STATUS.B.FAFS;
            status = (Std_ReturnType)E_OK;
        }
        break;
    default:
        status = FCCU_ERROR_UPDATE_FREEZE;
        break;
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Clear the freeze status register
 *
 *
 * @retval E_OK: clear status register successfully
 *         E_OK: fail to clear status register
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
Std_ReturnType FCCU_LLD_ClearFreezeStatus(void) /* PRQA S 1503 */
{
    Std_ReturnType status;

    (void)FCCU_LLD_RunOperation(FCCU_RUN_OP13);
    if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
    {
        status = (Std_ReturnType)E_OK;
    }
    else
    {
        status = FCCU_ERROR_CLEAR_FREEZE;
    }

    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Return the XTMR register value
 *
 *
 * @param[in] xtmrType: type of xtmr value
 * @retval the value of XTMR register
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
uint32 FCCU_LLD_GetXtmrValue(fccu_xtmr_type_t xtmrType) /* PRQA S 1503 */
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    uint32 value = 0U;

    switch (xtmrType)
    {
        case FCCU_XTMR_ALARM:
            status = FCCU_LLD_RunOperation(FCCU_RUN_OP17);
            break;
        case FCCU_XTMR_CFG:
            status = FCCU_LLD_RunOperation(FCCU_RUN_OP19);
            break;
        case FCCU_XTMR_ETMR:
            status = FCCU_LLD_RunOperation(FCCU_RUN_OP20);
            break;
        default:
            value = 0U;
            break;
    }

    if ((Std_ReturnType)E_OK == status)
    {
        if ((uint8)FCCU_OPS_SUCCESSFUL == FCCU.CTRL.B.OPS)
        {
            value = FCCU.XTMR.R;
        }
    }

    return value;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Trigger a recoverable fault fake to test
 *
 *
 * @param[in] fakeCode: trogger fake fault Mcu_FccuChannel
 * @retval None
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
void FCCU_LLD_SetRfFake(fccu_failure_inputs_t fakeCode)
{
    FCCU.RFF.B.FRFC = (uint8)fakeCode;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*
 * @brief Initializes the fccu module
 *
 *
 * @param[in] config: fccu module configuration
 * @param[in] rfConfig: fccu recoverable faults configuration
 * @retval    E_OK: init successfully
 *            FCCU_ERROR_SET_NORMAL: fail to set fccu goto normal state
 *            FCCU_ERROR_SET_CONFIG: fail to set fccu goto config state
 *            Std_ReturnTypeIMEOUT: in case of a timeout operation
 */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
VAR(Std_ReturnType, MCU_CODE)Mcu_LLD_FccuInit
(
    P2CONST( Mcu_FccuConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_FccuConfigPtr
)
{
    Std_ReturnType status = FCCU_ERROR_OTHER;\
    VAR(uint8, MCU_VAR)Mcu_Idx;
    Mcu_gFccuConfigPtr = Mcu_FccuConfigPtr;
    /* set debug mode */
    FCCU.CTRL.B.DEBUG = (uint32)FALSE;
    /* set filter bypass and width */
    FCCU.CTRL.B.FILTER_BYPASS = (uint32)Mcu_gFccuConfigPtr->Mcu_FccuFilterBypassEn;
    if (TRUE == Mcu_gFccuConfigPtr->Mcu_FccuFilterBypassEn)
    {
        FCCU.CTRL.B.FILTER_WIDTH = Mcu_gFccuConfigPtr->Mcu_FccuFilterWidth;
    }
    /* enable timeout interrupt */
    if (Mcu_gFccuConfigPtr->Mcu_FccuIrqTypeConfig == FCCU_IRQ_CFG_TO_IEN)
    {
        FCCU.IRQ_EN.B.CFG_TO_IEN = 0x1U;
    }

    /* set fccu goto config state */
    status = FCCU_LLD_SetConfigState();
    if ((Std_ReturnType)E_OK == status)
    {
        FCCU.CFG_TO.B.TO = Mcu_gFccuConfigPtr->Mcu_FccuCfgTimeout;

        status = FCCU_LLD_SetEout(&Mcu_gFccuConfigPtr->Mcu_FccuEoutConfig);
        if ((Std_ReturnType)E_OK != status)
        {
            return status;
        }

        for (Mcu_Idx = 0U; Mcu_Idx < Mcu_gFccuConfigPtr->Mcu_FccuRfCfgNumber; Mcu_Idx++)
        {
            status = FCCU_LLD_SetRfConfig(&Mcu_gFccuConfigPtr->Mcu_FccuRfConfigPtr[Mcu_Idx]);
            if ((Std_ReturnType)E_OK != status)
            {
                break;
            }
        }
    }

    if ((Std_ReturnType)E_OK == status)
    {
        status = FCCU_LLD_SetNormalState();
        if ((Std_ReturnType)E_OK == status)
        {
            FCCU_LLD_LockConfig(Mcu_gFccuConfigPtr->Mcu_FccuLockTypeConfig);
        }
    }
    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_ClockFailureCmu_ISR(void)
{
    VAR(uint32, MCU_VAR) IndexCmu = 0U;
    CONSTP2VAR(CMU_Type, MCU_CONST, MCU_APPL_CONST) Mcu_CmuPtr[] = CMU_BASE_PTRS;/* PRQA S 3604 */
    #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    (void)Dem_SetEventStatus(Mcu_gConfigPtr->Mcu_DemConfigPtr->Mcu_E_ClockFailureCfg.id, Mcu_gConfigPtr->Mcu_DemConfigPtr->Mcu_E_ClockFailureCfg.id);
    #endif

    #if (MCU_CLOCKS_FAILURE_EN == STD_ON)
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ClockFailureNotification != NULL_PTR)/* polyspace RTE:IDP */
        {
        (void)Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ClockFailureNotification();
    }
    #endif

    for(IndexCmu = (uint32)0U; IndexCmu < (uint32)CMU_INSTANCE_COUNT; IndexCmu++)
    {
        if(Mcu_CmuPtr[IndexCmu]->ISR.R != (uint32)0U)
        {
            Mcu_CmuPtr[IndexCmu]->ISR.R = (Mcu_CmuPtr[IndexCmu]->ISR.R & 0x7U);
        }
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_XoscISR(void)
{
    if(Mcu_gConfigPtr != NULL_PTR)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_XoscStartupNotification != NULL_PTR)
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_XoscStartupNotification();
        }
    }
    if(XOSC_StPtr->CTL.B.I_OSC == (uint32)TRUE)
    {
        XOSC_StPtr->CTL.B.I_OSC = (uint32)TRUE;
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_InvalidConfig_ISR(void)
{
    if(MC_ME_StPtr->IS.B.I_ICONF_CC == TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Core != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Core();
        }
        MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_ICONF_CC;
    }else if(MC_ME_StPtr->IS.B.I_ICONF_CU == TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Clock != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification_Clock();
        }
        MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_ICONF_CU;
    }
    else if(MC_ME_StPtr->IS.B.I_ICONF == TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidConfigNotification();
        }
        MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_ICONF;
    }
    else
    {
        /* Do nothing */
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_InvalidMode_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidModeNotification != NULL_PTR)/* polyspace RTE:IDP */
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_InvalidModeNotification();
    }
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_IMODE;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_SafeMode_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_SafeModeNotification != NULL_PTR)/* polyspace RTE:IDP */
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_SafeModeNotification();
    }
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_SAFE;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_ModeComplete_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ModeCompleteNotification != NULL_PTR)/* polyspace RTE:IDP */
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_ModeCompleteNotification();
    }
    MC_ME_StPtr->IS.R = MC_ME_StPtr->IS.B.I_MTC;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_VoltageError_ISR(void)
{
    VAR(uint16, MCU_VAR) VoltageIsrFlag = 0U;
    if(PMCDIG.EPR_VD3.R != (uint32)0U)
    {
        PMCDIG.EPR_VD3.R = (PMCDIG.EPR_VD3.R & 0xc1U);
        VoltageIsrFlag |= ((uint16)1<<3U);
    }
    if(PMCDIG.EPR_VD4.R != (uint32)0U)
    {
        PMCDIG.EPR_VD4.R = (PMCDIG.EPR_VD4.R & 0x1U);
        VoltageIsrFlag |= ((uint16)1U<<4U);
    }
    if(PMCDIG.EPR_VD7.R != (uint32)0U)
    {
        PMCDIG.EPR_VD7.R = (PMCDIG.EPR_VD7.R & 0x1U);
        VoltageIsrFlag |= ((uint16)1U<<7U);
    }
    if(PMCDIG.EPR_VD8.R != (uint32)0U)
    {
        PMCDIG.EPR_VD8.R = (PMCDIG.EPR_VD8.R & 0x41U);
        VoltageIsrFlag |= ((uint16)1U<<8U);
    }
    if(PMCDIG.EPR_VD9.R != (uint32)0U)
    {
        PMCDIG.EPR_VD9.R = (PMCDIG.EPR_VD9.R & 0x4e09U);
        VoltageIsrFlag |= ((uint16)1U<<9U);
    }
    if(PMCDIG.EPR_VD10.R != (uint32)0U)
    {
        PMCDIG.EPR_VD10.R = (PMCDIG.EPR_VD10.R & 0x8040U);
        VoltageIsrFlag |= ((uint16)1U<<10U);
    }
    if(PMCDIG.EPR_VD12.R != (uint32)0U)
    {
        PMCDIG.EPR_VD12.R = (PMCDIG.EPR_VD12.R & 0x40U);
        VoltageIsrFlag |= ((uint16)1U<<12U);
    }
    if(PMCDIG.EPR_VD13.R != (uint32)0U)
    {
        PMCDIG.EPR_VD13.R = (PMCDIG.EPR_VD13.R & 0x100U);
        VoltageIsrFlag |= ((uint16)1U<<13U);
    }
    if(PMCDIG.EPR_VD14.R != (uint32)0U)
    {
        PMCDIG.EPR_VD14.R = (PMCDIG.EPR_VD14.R & 0x8100U);
        VoltageIsrFlag |= ((uint16)1U<<14U);
    }
    if(PMCDIG.EPR_VD15.R != (uint32)0U)
    {
        PMCDIG.EPR_VD15.R = (PMCDIG.EPR_VD15.R &0x8001U);
        VoltageIsrFlag |= ((uint16)1U<<15U);
    }
    if(VoltageIsrFlag != (uint32)0U)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuVoltageErrorNotification != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuVoltageErrorNotification();
        }
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_LLD_TemperatureErrorError_ISR(void)
{
    if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuTemperatureErrorNotification != NULL_PTR)/* polyspace RTE:IDP */
    {
        Mcu_gConfigPtr->Mcu_NotifyConfigPtr->McuTemperatureErrorNotification();
    }
    PMCDIG.EPR_TD.R = (PMCDIG.EPR_TD.R & 0xbU);
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#if MCU_FCCU_ENABLE == STD_ON
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_Fccu_ISR(void)
{
    if(FCCU.IRQ_STAT.B.ALRM_STAT == (uint32)TRUE)
    {
        FCCU_LLD_AlarmIrqCallback();
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuAlarmNotification != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuAlarmNotification();
        }
        FCCU_LLD_ClearIntFlag(FCCU_INT_ALARM);
    }
    if(FCCU.IRQ_STAT.B.CFG_TO_STAT == (uint32)TRUE)
    {
        if(Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuCfgToNotification != NULL_PTR)/* polyspace RTE:IDP */
        {
            Mcu_gConfigPtr->Mcu_NotifyConfigPtr->Mcu_FccuCfgToNotification();
        }
        FCCU_LLD_ClearIntFlag(FCCU_INT_TIMEOUT);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif


#if ((MCU_HARDVER == 4) || (MCU_HARDVER == 5) || (MCU_HARDVER == 7) || (MCU_HARDVER == 8))

#define MCU_START_SEC_VAR_NO_INIT
#include "Mcu_MemMap.h"
static mcuHsmSrvDescriptor_t mcu_hsmSrvDesc;/* PRQA S 3218 */
#define MCU_STOP_SEC_VAR_NO_INIT
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(boolean, MCU_CODE) MCU_HSM_IsResponseReady
(
    VAR(Mcu_CoreType, AUTOMATIC) coreId
)
{
    boolean isBusy;

    if ((1UL << coreId) == (HSM.HOST_FLAG & (1UL << coreId)))/* polyspace RTE:SHF */
    {
        isBusy = FALSE;
    }
    else
    {
        if (MCU_HSM_STATUS_MASK == (HSM.HSM_STATUS & MCU_HSM_STATUS_MASK))
        {
            isBusy = FALSE;
        }
        else
        {
            isBusy = TRUE;
        }
    }

    return isBusy;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
MCU_INLINE FUNC(status_t, MCU_CODE) MCU_HSM_RequestService
(
    VAR(Mcu_CoreType, AUTOMATIC) coreId,
    P2VAR(mcuHsmSrvDescriptor_t, AUTOMATIC, MCU_APPL_DATA) pHsmSrvDescriptor
)
{
    uint32_t timeout = MCU_HSE_OPERATION_TIMEOUT;
    status_t status = STATUS_SUCCESS;

#ifdef DCACHE_ENABLE
    (void)Mcu_LLD_Disable_DCache();
#endif
    if (TRUE != MCU_HSM_IsResponseReady(coreId))
    {
        status = STATUS_BUSY;
    }
    if (STATUS_SUCCESS == status)
    {
        HSM.ALG_PARAM[0] = coreId;
        HSM.ALG_PARAM[1] = (uint32_t)pHsmSrvDescriptor;

        HSM.HOST_FLAG = 1UL << coreId; /* Call hsm to raise interrupt */


        while ((FALSE == MCU_HSM_IsResponseReady(coreId)) && (timeout > 0U))
        {
            timeout -- ;
        }

        if (0UL == timeout)
        {
            status = STATUS_TIMEOUT;
        }

    }
    if (STATUS_SUCCESS == status)
    {
        if (0U != HSM.HSM_STATUS)
        {
            status = (status_t)(((HSM.HSM_STATUS & 0xFFFF0000U) >> 16) | MCU_HSM_ERC_OFFSET);/* PRQA S 4394 */
        }
    }

#ifdef DCACHE_ENABLE
    (void)Mcu_LLD_Enable_DCache();
#endif
    return status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(status_t, MCU_CODE) MCU_HSM_SetClkDiv
(
            VAR(uint32, AUTOMATIC) divider
)
{
    status_t status = STATUS_SUCCESS;
    Mcu_CoreType coreId = Mcu_LLD_Get_Core_Id();
    mcuHsmSrvDescriptor_t *pHsmSrvDesc = &mcu_hsmSrvDesc;

    /* Prepare the service */
    cc_memset((uint8_t *)pHsmSrvDesc, 0, sizeof(mcuHsmSrvDescriptor_t));/* PRQA S 0751 */

    /* Prepare the service */
    pHsmSrvDesc->srvCmd = MCU_HSM_SRV_CMD_SET_ATTR;
    //pHsmSrvDesc->srvReq.setAttr.attrId = HSM_ATTR_ID_CORE_CLK_DIVIDER;
    pHsmSrvDesc->srvReq.setAttr.attrId = 5;
    pHsmSrvDesc->srvReq.setAttr.pAttr = (uint32_t)&divider;
    pHsmSrvDesc->srvReq.setAttr.attrLen = 4U;

    /* Request the service to HSM */
    status = MCU_HSM_RequestService(coreId, pHsmSrvDesc);

    return status;

}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#endif

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_PctlPeriRunSet
( \
    VAR(Mcu_McMePeriNameType, AUTOMATIC) Mcu_McMePeriName, \
    VAR(Mcu_McMeLPModeType, AUTOMATIC) Mcu_McMeLPMode, \
    VAR(Mcu_McMeRunModeType, AUTOMATIC) Mcu_McMeRunMode \
)
{
    if(Mcu_McMePeriName == MC_ME_PCTL_ALL)
    {
        for(uint8 PeriIndex = 0U; PeriIndex < 255U; PeriIndex++)
        {
            MC_ME_StPtr->PCTL[(uint8)PeriIndex].R = (uint8)((MC_ME_PCTLn_RUN_CFG(Mcu_McMeRunMode) | MC_ME_PCTLn_LP_CFG(Mcu_McMeLPMode)));
        }
    }
    else
    {
        MC_ME_StPtr->PCTL[(uint8)Mcu_McMePeriName].R = (uint8)((MC_ME_PCTLn_RUN_CFG(Mcu_McMeRunMode) | MC_ME_PCTLn_LP_CFG(Mcu_McMeLPMode)));/* polyspace RTE:OBAI */
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_LLD_RgmlPeriRstSet
( \
    VAR(Mcu_RgmPeriRstType, AUTOMATIC) Mcu_McRgmPeriName
)
{
    VAR(uint32, MCU_VAR)TimeCount = 100U;
    if(Mcu_McRgmPeriName == MC_RGM_ALL)
    {
        MC_RGM.PRST0.R = 0xFFFFFFFFU;
        MC_RGM.PRST1.R = 0xFFFFFFFFU;
        MC_RGM.PRST2.R = 0xFFFFFFFFU;
        MC_RGM.PRST3.R = 0xFFFFFFFFU;
        MC_RGM.PRST4.R = 0xFFFFFFFFU;
        MC_RGM.PRST5.R = 0xFFFFFFFFU;
        MC_RGM.PRST6.R = 0xFFFFFFFFU;
        MC_RGM.PRST7.R = 0xFFFFFFFFU;
        while(TimeCount != 0U)
        {
        TimeCount--;
        }
        MC_RGM.PRST0.R = 0x0U;
        MC_RGM.PRST1.R = 0x0U;
        MC_RGM.PRST2.R = 0x0U;
        MC_RGM.PRST3.R = 0x0U;
        MC_RGM.PRST4.R = 0x0U;
        MC_RGM.PRST5.R = 0x0U;
        MC_RGM.PRST6.R = 0x0U;
        MC_RGM.PRST7.R = 0x0U;
    }
    else
    {
        if((uint32)Mcu_McRgmPeriName < 32U)
        {
            MC_RGM.PRST0.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST0.R = 0x0U;
        }
        else if((uint32)Mcu_McRgmPeriName < 64U)
        {
            MC_RGM.PRST1.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST1.R = 0x0U;
        }
        else if((uint32)Mcu_McRgmPeriName < 96U)
        {
            MC_RGM.PRST2.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST2.R = 0x0U;
        }
        else if((uint32)Mcu_McRgmPeriName < 128U)
        {
            MC_RGM.PRST3.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST3.R = 0x0U;
        }
        else if((uint32)Mcu_McRgmPeriName < 160U)
        {
            MC_RGM.PRST4.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST4.R = 0x0U;
        }
        else if((uint32)Mcu_McRgmPeriName < 192U)
        {
            MC_RGM.PRST5.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST5.R = 0x0U;
        }
        else if((uint32)Mcu_McRgmPeriName < 224U)
        {
            MC_RGM.PRST6.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST6.R = 0x0U;
        }
        else
        {
            MC_RGM.PRST7.R = 1UL << ((uint32)Mcu_McRgmPeriName % 32UL);/* polyspace RTE:OBAI*/
            while(TimeCount != 0U)
            {
                TimeCount--;
            }
            MC_RGM.PRST7.R = 0x0U;
        }
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#include "Cache_C.h"




#ifdef __cplusplus
}
#endif
