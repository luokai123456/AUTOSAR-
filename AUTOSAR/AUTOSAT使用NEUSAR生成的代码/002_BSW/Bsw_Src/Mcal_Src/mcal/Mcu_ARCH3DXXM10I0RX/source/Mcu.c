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
*   @file    Mcu.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/
/*PRQA S 1758,1594,1599 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/

#include "Mcu.h"                    /*PRQA S 0380*/
#include "Mcu_AutoSAR_Wrapper.h"
#include "Mcu_LLDriver.h"           /*PRQA S 0380*/
#include "SchM_Mcu.h"
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* MCU_DEV_ERROR_DETECT  STD_ON */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*====================================================================================================
SOURCE FILE VERSION INFORMATION
====================================================================================================*/

#define MCU_VENDOR_ID_C                 176
#define MCU_AR_MAJOR_VER_C              4
#define MCU_AR_MINOR_VER_C              4
#define MCU_AR_PATCH_VER_C              0
#define MCU_SW_MAJOR_VER_C              3
#define MCU_SW_MINOR_VER_C              0
#define MCU_SW_PATCH_VER_C              0

/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/

/* Check if current file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID_C != MCU_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_AR_MAJOR_VER_C != MCU_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (MCU_AR_MINOR_VER_C != MCU_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCU_AR_RELEASE_MINOR_VERSION"
#endif
#if (MCU_AR_PATCH_VER_C != MCU_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_SW_MAJOR_VER_C != MCU_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_SW_MAJOR_VER"
#endif
#if (MCU_SW_MINOR_VER_C != MCU_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_SW_MINOR_VER"
#endif
#if (MCU_SW_PATCH_VER_C != MCU_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_SW_PATCH_VER"
#endif

#define MCU_START_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"
P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_gConfigPtr;
P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_gConfigPtr = NULL_PTR;
#define MCU_STOP_SEC_VAR_SHARED_INIT
#include "Mcu_MemMap.h"

/*==================================================================================================
GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT
#include "Mcu_MemMap.h"
P2CONST(Mcu_ClockConfigType, MCU_VAR, MCU_APPL_DATA) Mcu_gClockConfigPtr;
P2CONST(Mcu_ClockConfigType, MCU_VAR, MCU_APPL_DATA) Mcu_gClockConfigPtr = NULL_PTR;
#define MCU_STOP_SEC_VAR_INIT
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT
#include "Mcu_MemMap.h"
VAR(Mcu_Rgm_ResetType, MCU_VAR) Mcu_gRgmConfiguration;
VAR(Mcu_Rgm_ResetType, MCU_VAR) Mcu_gRgmConfiguration = MCU_FUNC_RESET;
#define MCU_STOP_SEC_VAR_INIT
#include "Mcu_MemMap.h"

/*====================================================================================================
GLOBAL FUNCTIONS
====================================================================================================*/
/*******************************************************************************
**  Service Name     : Mcu_Init
**
**  Description      : This service initializes the MCU driver.
**
**  Parameters (in)  : ConfigPtr   Pointer to MCU driver configuration set.
**
**  Parameters (out) : None
**
**  Return value     : void
**
*******************************************************************************/
/* [SWS_Mcu_00153] */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_Init( P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr )
{
    P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_tConfigPtr;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR != Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INIT_ID, (uint8)MCU_E_INIT_FAILED);
    }
    else
    {
        #if (MCU_CONFIG_TYPE_PB == STD_ON)
        if(NULL_PTR == ConfigPtr)
        #else
        if(ConfigPtr != NULL_PTR)
        #endif
        {
            (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INIT_ID, (uint8)MCU_E_PARAM_POINTER);
        }
        else
        {
    #endif
            SchM_Enter_Mcu_EXCLUSIVE_AREA_00();
            #if (MCU_CONFIG_TYPE_PB == STD_ON)
            Mcu_tConfigPtr = (P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST))ConfigPtr;
            #else
            Mcu_tConfigPtr = (P2CONST(Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST))&Mcu_Config;
            #endif
            if(Mcu_tConfigPtr->Mcu_CtrlConfigPtr->Mcu_InitCore == Mcu_LLD_Get_Core_Id())
            {
                Mcu_gConfigPtr = Mcu_tConfigPtr;
            }
            Mcu_Wrap_Init(Mcu_tConfigPtr);
            SchM_Exit_Mcu_EXCLUSIVE_AREA_00();
        #if (MCU_CONFIG_TYPE_PB == STD_OFF)
            (void)ConfigPtr;
        #endif
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
// [SWS_Mcu_00026]: The function Mcu_Init shall initialize the MCU module, i.e. make the configuration settings for power down, clock and RAM sections visible within the MCU module.
// [SWS_Mcu_00116]: If the hardware allows for only one usage of the register, the driver module implementing that functionality is responsible for initializing the register.()
// [SWS_Mcu_00244]: If the register can affect several hardware modules and if it is an I/O register, it shall be initialised by the PORT driver.()
// [SWS_Mcu_00245]: If the register can affect several hardware modules and if it is not an I/O register, it shall be initialised by this MCU driver.()
// [SWS_Mcu_00246]: One-time writable registers that require initialisation directly after reset shall be initialised by the startup code.()
// [SWS_Mcu_00247]: All other registers not mentioned before shall be initialised by the start-up code.()

// [SWS_Mcu_00125]: If development error detection is enabled and if any other function (except Mcu_GetVersionInfo) of the MCU module is called before Mcu_Init function, the error code MCU_E_UNINIT shall be reported to the DET.()


/*******************************************************************************
**  Service Name     : Mcu_InitRamSection
**
**  Description      : This service initializes the RAM section wise.
**
**  Parameters (in)  : RamSection   Selects RAM memory section provided in configuration set.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
/* [SWS_Mcu_00154] */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection( VAR(Mcu_RamSectionType, AUTOMATIC) RamSection )
{
    VAR(Std_ReturnType, MCU_VAR) RetResult = (Std_ReturnType)E_NOT_OK;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INITRAMSECTION_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
        if(RamSection >= (Mcu_RamSectionType)Mcu_gConfigPtr->NoRamSectionConfig)
        {
            (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INITRAMSECTION_ID, (uint8)MCU_E_PARAM_RAMSECTION);
        }
        else
        {
    #endif
            SchM_Enter_Mcu_EXCLUSIVE_AREA_01();
            RetResult = (Std_ReturnType)Mcu_Wrap_InitRamSection(&Mcu_gConfigPtr->Mcu_RamConfigPtr[RamSection]); /*PRQA S 0491*/
            SchM_Exit_Mcu_EXCLUSIVE_AREA_01();
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
    return (Std_ReturnType)RetResult;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* [SWS_Mcu_00011]: The function Mcu_InitRamSection shall fill the memory from address McuRamSectionBaseAddress up to address McuRamSectionBaseAddress + McuRamSectionSize-1 with 
the byte-value contained in McuRamDefaultValue and by writing at once a number of bytes defined by McuRamSectionWriteSize, where McuRamSectionBaseAddress, McuRamSectionSize, 
McuRamDefaultValue and McuRamSectionWriteSize are the values of the configuration parameters for each RamSection (see SWS_Mcu_00030). */
// [SWS_Mcu_00136]: The MCU module's environment shall call the function Mcu_InitRamSection only after the MCU module has been initialized using the function Mcu_Init.()

// [SWS_Mcu_00021]: RamSection shall be within the sections defined in the configuration data structure. Related error value: MCU_E_PARAM_RAMSECTION()

/*******************************************************************************
**  Service Name     : Mcu_InitClock
**
**  Description      : This service initializes the PLL and other MCU specific clock options.
**
**  Parameters (in)  : ClockSetting   Set different MCU Clock configured in the configuration set.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
/* [SWS_Mcu_00155] */
#if (MCU_INIT_CLOCK == STD_ON)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock( VAR(Mcu_ClockType, AUTOMATIC) ClockSetting )
{
    VAR(Std_ReturnType, AUTOMATIC) RetResult = (Std_ReturnType)E_OK;
    P2CONST(Mcu_ClockConfigType, MCU_VAR, MCU_APPL_DATA)Mcu_ClockConfigPtr;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INITCLOCK_ID, (uint8)MCU_E_UNINIT);
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if( ClockSetting >= Mcu_gConfigPtr->NoClockConfig)
        {
            (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_INITCLOCK_ID, (uint8)MCU_E_PARAM_CLOCK);
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
    #endif
            SchM_Enter_Mcu_EXCLUSIVE_AREA_02();
            Mcu_ClockConfigPtr = &Mcu_gConfigPtr->Mcu_ClockConfigPtr[ClockSetting]; /*PRQA S 0491*/

			RetResult = Mcu_Wrap_InitClock( Mcu_ClockConfigPtr );
			if(RetResult == (Std_ReturnType)E_OK)
			{
				Mcu_gClockConfigPtr = Mcu_ClockConfigPtr;
			}

            SchM_Exit_Mcu_EXCLUSIVE_AREA_02();

    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
    return (Std_ReturnType)RetResult;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_INIT_CLOCK  STD_ON */
// [SWS_Mcu_00137]: The function Mcu_InitClock shall initialize the PLL and other MCU specific clock options. The clock configuration parameters are provided via the configuration structure.()
// [SWS_Mcu_00138]: The function Mcu_InitClock shall start the PLL lock procedure (if PLL shall be initialized) and shall return without waiting until the PLL is locked.()
// [SWS_Mcu_00139]: The MCU module's environment shall only call the function Mcu_InitClock after the MCU module has been initialized using the function Mcu_Init.()
// [SWS_Mcu_00210]: The function Mcu_InitClock shall be disabled if the parameter McuInitClock is set to FALSE. Instead this function is available if the former parameter is set to TRUE (see also ECUC_Mcu_00118 : ).()

// [SWS_Mcu_00019]: ClockSetting shall be within the settings defined in the configuration data structure. Related error value: MCU_E_PARAM_CLOCK()


/*******************************************************************************
**  Service Name     : Mcu_DistributePllClock
**
**  Description      : This service activates the PLL clock to the MCU clock distribution.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
/* [SWS_Mcu_00156] */
#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock( VAR(void, AUTOMATIC) )
{
    VAR(Std_ReturnType, MCU_VAR) RetResult = (Std_ReturnType)E_OK;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_DISTRIBUTEPLLCLOCK_ID, (uint8)MCU_E_UNINIT);
        RetResult = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
    #endif
        if(MCU_PLL_LOCKED != (Mcu_PllStatusType)Mcu_Wrap_GetPllStatus())
        {
            #if (MCU_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_DISTRIBUTEPLLCLOCK_ID, (uint8)MCU_E_PLL_NOT_LOCKED);
            #endif
            RetResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            SchM_Enter_Mcu_EXCLUSIVE_AREA_03();
            (void)Mcu_Wrap_DistributePllClock();
            SchM_Exit_Mcu_EXCLUSIVE_AREA_03();
            RetResult = (Std_ReturnType)E_OK;
        }
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return (Std_ReturnType)RetResult;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_NO_PLL  STD_OFF */
#endif /* MCU_INIT_CLOCK  STD_ON */
// [SWS_Mcu_00140]: The function Mcu_DistributePllClock shall activate the PLL clock to the MCU clock distribution.()
// [SWS_Mcu_00141]: The function Mcu_DistributePllClock shall remove the current clock source (for example internal oscillator clock) from MCU clock distribution.()
// [SWS_Mcu_00056]: The function Mcu_DistributePllClock shall return without affecting the MCU hardware if the PLL clock has been automatically activated by the MCU hardware.()
// [SWS_Mcu_00142]: If the function Mcu_DistributePllClock is called before PLL has locked, this function shall return E_NOT_OK immediately, without any further action.()
// [SWS_Mcu_00205]: The function Mcu_DistributePllClock shall be available if the pre-compile parameter McuNoPll is set to FALSE. Otherwise, this Api has to be disabled (see also ECUC_Mcu_00180 : ).()



/*******************************************************************************
**  Service Name     : Mcu_GetPllStatus
**
**  Description      : This service provides the lock status of the PLL.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : Mcu_PllStatusType
**
*******************************************************************************/
/* [SWS_Mcu_00157] */
#if (MCU_INIT_CLOCK == STD_ON)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus( VAR(void, AUTOMATIC) )
{
    VAR(Mcu_PllStatusType, MCU_VAR) Pll_Status;
    #if (MCU_NO_PLL == STD_OFF)
        #if (MCU_DEV_ERROR_DETECT == STD_ON)
        if(NULL_PTR == Mcu_gConfigPtr)
        {
            (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_GETPLLSTATUS_ID, (uint8)MCU_E_UNINIT);
            Pll_Status = (Mcu_PllStatusType)MCU_PLL_STATUS_UNDEFINED;
        }
        else
        {
        #endif
            Pll_Status = (Mcu_PllStatusType)Mcu_Wrap_GetPllStatus();
        #if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
        #endif
    #else
        Pll_Status = (Mcu_PllStatusType)MCU_PLL_STATUS_UNDEFINED;
    #endif /* MCU_NO_PLL  STD_OFF */
        return (Mcu_PllStatusType)Pll_Status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_INIT_CLOCK  STD_ON */
// [SWS_Mcu_00008]: The function Mcu_GetPllStatus shall return the lock status of the PLL.()
// [SWS_Mcu_00132]: The function Mcu_GetPllStatus shall return MCU_PLL_STATUS_UNDEFINED if this function is called prior to calling of the function Mcu_Init.()
// [SWS_Mcu_00206]: The function Mcu_GetPllStatus shall also return MCU_PLL_STATUS_UNDEFINED if the pre-compile parameter McuNoPll is set to TRUE (see also ECUC_Mcu_00180 : ).()



/*******************************************************************************
**  Service Name     : Mcu_GetResetReason
**
**  Description      : The service reads the reset type from the hardware, if supported.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : Mcu_ResetType
**
*******************************************************************************/
/* [SWS_Mcu_00158] */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason( VAR(void, AUTOMATIC) )
{
    VAR(Mcu_ResetType, MCU_VAR) ResetReason = (Mcu_ResetType)MCU_RESET_UNDEFINED;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_GETRESETREASON_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
    #endif
        ResetReason = (Mcu_ResetType)Mcu_Wrap_GetResetReason();
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return (Mcu_ResetType)ResetReason;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* [SWS_Mcu_00005]: The function Mcu_GetResetReason shall read the reset reason from the hardware and return this reason if supported by the hardware. 
If the hardware does not support the hardware detection of the reset reason, the return value from the function Mcu_GetResetReason shall always be MCU_POWER_ON_RESET.() */
// [SWS_Mcu_00133]: The function Mcu_GetResetReason shall return MCU_RESET_UNDEFINED if this function is called prior to calling of the function Mcu_Init, and if supported by the hardware.()



/*******************************************************************************
**  Service Name     : Mcu_GetResetRawValue
**
**  Description      : The service reads the reset type from the hardware register, if supported.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : Mcu_RawResetType
**
*******************************************************************************/
/* [SWS_Mcu_00159] */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue( VAR( void, AUTOMATIC) )
{
    VAR(Mcu_RawResetType, MCU_VAR) ResetReason = (Mcu_RawResetType)0xffffffffUL;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_GETRESETRAWVALUE_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
    #endif
        ResetReason = (Mcu_RawResetType)Mcu_Wrap_GetResetRaw();
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return (Mcu_RawResetType)ResetReason;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/* [SWS_Mcu_00135]: The function Mcu_GetResetRawValue shall return an implementation specific value which does not correspond to a valid value of the reset status register and is not equal to 0 
if this function is called prior to calling of the function Mcu_Init, and if supported by the hardware.() */
// [SWS_Mcu_00006]: The function Mcu_GetResetRawValue shall read the reset raw value from the hardware register if the hardware supports this. If the hardware does not have a reset status register, the return value shall be 0x0.()



/*******************************************************************************
**  Service Name     : Mcu_PerformReset
**
**  Description      : The service performs a microcontroller reset.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None                                                   
**
**  Return value     : void
**
*******************************************************************************/
/* [SWS_Mcu_00160] */
#if (MCU_PERFORM_RESET_API == STD_ON)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_PerformReset( VAR(void, AUTOMATIC) )
{
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PERFORMRESET_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
    #endif
        SchM_Enter_Mcu_EXCLUSIVE_AREA_04();
        (void)Mcu_Wrap_PerformReset(Mcu_gRgmConfiguration);
        SchM_Exit_Mcu_EXCLUSIVE_AREA_04();
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_PERFORM_RESET_API  STD_ON */
// [SWS_Mcu_00143]: The function Mcu_PerformReset shall perform a microcontroller reset by using the hardware feature of the microcontroller.()
// [SWS_Mcu_00144]: The function Mcu_PerformReset shall perform the reset type which is configured in the configuration set.()
// [SWS_Mcu_00145]: The MCU module's environment shall only call the function Mcu_PerformReset after the MCU module has been initialized by the function Mcu_Init.()
// [SWS_Mcu_00146]: The function Mcu_PerformReset is only available if the pre-compile parameter McuPerformResetApi is set to TRUE. If set to FALSE, the function Mcu_PerformReset is not applicable. (see Section 10.2.2).()


/*******************************************************************************
**  Service Name     : Mcu_SetMode
**
**  Description      : This service activates the MCU power modes.
**
**  Parameters (in)  : McuMode   Set different MCU power modes configured in the configuration set
**
**  Parameters (out) : None
**
**  Return value     : void                                         
**
*******************************************************************************/
/* [SWS_Mcu_00161] */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_SetMode( VAR(Mcu_ModeType, AUTOMATIC) McuMode )
{
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_SETMODE_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
        if(McuMode >= Mcu_gConfigPtr->NoModeConfig)
        {
            (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_SETMODE_ID, (uint8)MCU_E_PARAM_MODE);
        }
        else
        {
    #endif
            (void)Mcu_Wrap_SetMode(&Mcu_gConfigPtr->Mcu_ModeConfigPtr[McuMode]); /*PRQA S 0491*/
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
        }
    }
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
// [SWS_Mcu_00147]: The function Mcu_SetMode shall set the MCU power mode. In case of CPU power down mode, the function Mcu_SetMode returns after it has performed a wake-up.()
// [SWS_Mcu_00148]: The MCU module's environment shall only call the function Mcu_SetMode after the MCU module has been initialized by the function Mcu_Init.()

// [SWS_Mcu_00020]: McuMode shall be within the modes defined in the configuration data structure. Related error value: MCU_E_PARAM_MODE()

/*******************************************************************************
**  Service Name     : Mcu_GetVersionInfo
**
**  Description      : This service returns the version information of this module.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : void
**
*******************************************************************************/
/* [SWS_Mcu_00162] */
#if (MCU_VERSION_INFO_API == STD_ON)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_GetVersionInfo( P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) versioninfo ) /*PRQA S 3432*/
{
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_GETVERSIONINFO_ID, (uint8)MCU_E_PARAM_POINTER);
    }
    else
    {
    #endif
        versioninfo->vendorID = (uint16)MCU_VENDOR_ID;
        versioninfo->moduleID = (uint16)MCU_MODULE_ID;
        versioninfo->sw_major_version = (uint8)MCU_AR_RELEASE_MINOR_VERSION;
        versioninfo->sw_minor_version = (uint8)MCU_AR_RELEASE_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)MCU_AR_PATCH_VER;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif

/*******************************************************************************
**  Service Name     : Mcu_GetRamState
**
**  Description      : This service provides the actual status of the microcontroller Ram. (if supported)
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : Mcu_RamStateType
**
*******************************************************************************/
/* [SWS_Mcu_00207] */
#if (MCU_GET_RAM_STATE_API == STD_ON)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState( VAR(void, AUTOMATIC) )
{
    VAR(Mcu_RamStateType, MCU_VAR)Mcu_Ram_Status = (Mcu_RamStateType)MCU_RAMSTATE_INVALID;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_GETRAMSTATE_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
    #endif
        Mcu_Ram_Status = (Mcu_RamStateType) Mcu_Wrap_GetRamState();
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return (Mcu_RamStateType)Mcu_Ram_Status;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_GET_RAM_STATE_API  STD_ON */
// [SWS_Mcu_00208]: The MCU module's environment shall call this function only if the MCU module has been already initialized using the function MCU_Init.()
/* [SWS_Mcu_00209]: The function Mcu_GetRamState shall be available to the user if the pre-compile parameter McuGetRamStateApi is set to TRUE. Instead, if the former parameter is set to FALSE, this function shall be disabled
(e.g. the hardware does not support this functionality).() */

#if (MCU_FCCU_ENABLE == STD_ON)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE)Mcu_FccuInit( VAR(void, AUTOMATIC) )
{
    VAR(Std_ReturnType, MCU_CODE)Mcu_RetVal = (Std_ReturnType)E_OK;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_FCCUINIT_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
    #endif
        Mcu_RetVal = (Std_ReturnType) Mcu_Wrap_FccuInit(Mcu_gConfigPtr->Mcu_FccuConfigPtr);
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return (Std_ReturnType)Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE)Mcu_FccuClearFault( VAR(uint8, AUTOMATIC)faultIndex )
{
    VAR(Std_ReturnType, MCU_CODE)Mcu_RetVal = (Std_ReturnType)E_OK;
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_FCCUINIT_CLEARFAULT_ID, (uint8)MCU_E_UNINIT);
    }
    else
    {
    #endif
        Mcu_RetVal = (Std_ReturnType) Mcu_Wrap_FccuClearFaults(faultIndex);
    #if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return (Std_ReturnType)Mcu_RetVal;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_PeriModeSet( VAR(Mcu_PeriType, AUTOMATIC)PeriConfig )
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PERIMODESET_ID, (uint8)MCU_E_UNINIT);
    }
    else if (PeriConfig >= MC_ME_PERIPH_CONFIG_COUNT)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PERIMODESET_ID, (uint8)MCU_E_PARAM_ERR);
    }
    else
#endif
    {
        Mcu_Wrap_PeriModeSet(Mcu_gConfigPtr->Mcu_McMeConfigPtr->McMePeripheralConfig[PeriConfig]);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#if (MCU_PERIRESET_COUNT != 0)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_PeriResetPend( VAR(Mcu_PeriType, AUTOMATIC)PeriConfig )
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PERIRESETPEND_ID, (uint8)MCU_E_UNINIT);
    }
    else if (PeriConfig >= MCU_PERIRESET_COUNT)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PERIRESETPEND_ID, (uint8)MCU_E_PARAM_ERR);
    }
    else
#endif
    {
        Mcu_Wrap_PeriResetPend(Mcu_gConfigPtr->Mcu_RgmConfigPtr->PeriResetConfig[PeriConfig]);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_PeriResetClose( VAR(void, AUTOMATIC) )
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PERIRESETCLOSE_ID, (uint8)MCU_E_UNINIT);
    }
    else
#endif
    {
        Mcu_Wrap_PeriResetClose();
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_CoreSynchronise( void )
{
    Mcu_Wrap_CoreSynchronise();
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_PctlPeriRunSet
( \
    VAR(Mcu_McMePeriNameType, AUTOMATIC) Mcu_McMePeriName, \
    VAR(Mcu_McMeLPModeType, AUTOMATIC) Mcu_McMeLPMode, \
    VAR(Mcu_McMeRunModeType, AUTOMATIC) Mcu_McMeRunMode \
)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_PCTLPERIRUNSET_ID, (uint8)MCU_E_UNINIT);
    }
    else
#endif
    {
        Mcu_Wrap_PctlPeriRunSet(Mcu_McMePeriName,Mcu_McMeLPMode,Mcu_McMeRunMode);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE)Mcu_RgmlPeriRstSet( VAR(Mcu_RgmPeriRstType, AUTOMATIC) Mcu_McRgmPeriName)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == Mcu_gConfigPtr)
    {
        (void)Det_ReportError((uint16)MCU_MODULE_ID, (uint8)MCU_INSTANCE_ID, (uint8)MCU_RGMPERIRSTSET_ID, (uint8)MCU_E_UNINIT);
    }
    else
#endif
    {
        Mcu_Wrap_RgmlPeriRstSet(Mcu_McRgmPeriName);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(void, MCU_CODE) Mcu_PerformReset_Custom( VAR(Mcu_Rgm_ResetType, AUTOMATIC) Mcu_ResetMode )
{
    if(NULL_PTR == Mcu_gConfigPtr)
    {

    }
    else
    {
        (void)Mcu_Wrap_PerformReset(Mcu_ResetMode);
    }
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

