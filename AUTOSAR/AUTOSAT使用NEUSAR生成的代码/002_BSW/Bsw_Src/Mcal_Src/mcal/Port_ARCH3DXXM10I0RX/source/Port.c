/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : PORT
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
*   @file    Port.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/
/* PRQA S 1006, 3432 EOF */
/* PRQA S 0491,1756 EOF */
#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Port.h" /* PRQA S 0380 */
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

#include "Port_AutoSar_Wrapper.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */

#define PORT_C_VENDOR_ID                    176

#define PORT_C_AR_RELEASE_MAJOR_VERSION     4

#define PORT_C_AR_RELEASE_MINOR_VERSION     4

#define PORT_C_AR_RELEASE_REV               0

#define PORT_C_SW_MAJOR_VERSION             3
#define PORT_C_SW_MINOR_VERSION             0
#define PORT_C_SW_PATCH_VERSION             0

/* ============================================FILE VERSION CHECKS=================================== */

#if (PORT_C_VENDOR_ID != PORT_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_VENDOR_ID"
#endif

#if (PORT_C_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION"
#endif

#if (PORT_C_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)
    #error "NON-MATCHED DATA : "
#endif

#if (PORT_C_AR_RELEASE_REV != PORT_AR_RELEASE_REV_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION"
#endif

#if (PORT_C_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MAJOR_VERSION"
#endif

#if (PORT_C_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MINOR_VERSION"
#endif

#if (PORT_C_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : "
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    // Check if the source file and Det.h file are of the same Autosar version
    #if (STD_ON == PORT_DEV_ERROR_DETECT)
        #if (PORT_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
            #error "NON-MATCHED DATA : DET_AR_RELEASE_MAJOR_VERSION"
        #endif
        #if (PORT_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)
            #error "NON-MATCHED DATA : DET_AR_RELEASE_MINOR_VERSION"
       #endif
    #endif
#endif

/* =========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)=============================== */
    #define Port_GetCoreID()       GetCoreID()
/* ======================================LOCAL MACROS================================================ */


/* ======================================LOCAL CONSTANTS============================================= */


/* ======================================LOCAL VARIABLES============================================= */


/* ======================================GLOBAL CONSTANTS============================================ */


/* ======================================GLOBAL VARIABLES============================================ */
#define PORT_START_SEC_VAR_INIT
#include "Port_MemMap.h"
static P2CONST(Port_ConfigType, PORT_VAR, PORT_APPL_CONST) s_pPort_Config = NULL_PTR;
#define PORT_STOP_SEC_VAR_INIT
#include "Port_MemMap.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)
#define PORT_START_SEC_VAR_INIT
#include "Port_MemMap.h"
static VAR(Port_InitStateType, PORT_VAR) Port_Status = PORT_UNINIT;
#define PORT_STOP_SEC_VAR_INIT
#include "Port_MemMap.h"
#endif
/* ==================================LOCAL FUNCTION PROTOTYPES======================================= */


/* ======================================LOCAL FUNCTIONS============================================= */
#if (PORT_SET_SIUL2_API == STD_ON)
#define PORT_START_SEC_VAR_NO_INIT
#include "Port_MemMap.h"
callBackFunction eirq_cb[EIRQ_MAX_NUM];
#define PORT_STOP_SEC_VAR_NO_INIT
#include "Port_MemMap.h"
#endif

#if (STD_ON == PORT_DEV_ERROR_DETECT)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
static void Port_Det_ReportError(VAR(uint8, AUTOMATIC) ApiId, VAR(uint8, AUTOMATIC) ErrorId)
{
    (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID, ApiId, ErrorId);
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
/*****************************************************************************
**  Service Name     : Port_InitVerify
**
**  Description      : check Parameters
**
**  Parameters (in)  : ConfigPtr: A pointer to the structure which contains
**                                initialization parameters.
**
**  Parameters (out) : None
**
**
******************************************************************************/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(Std_ReturnType, PORT_CODE) Port_InitVerify \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;


#if (STD_OFF == PORT_PRECOMPILE_SUPPORT)
    if (NULL_PTR == ConfigPtr)
    {/* polyspace RTE:UNR */
        Port_Det_ReportError((uint8)PORT_INIT_ID, (uint8)PORT_E_INIT_FAILED);
        ErrStatus = (Std_ReturnType)E_NOT_OK;
    }
#else
    if (NULL_PTR != ConfigPtr)
    {
    	Port_Det_ReportError((uint8)PORT_INIT_ID, (uint8)PORT_E_INIT_FAILED);
        ErrStatus = (Std_ReturnType)E_NOT_OK;
    }
#endif

    return ErrStatus;
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
/*****************************************************************************
**  Service Name     : Port_Init
**
**  Description      : The function @p Port_Init() will initialize ALL ports and port pins
**                     with the configuration set pointed to by the parameter @p pConfigPtr.
**
**  Parameters (in)  : ConfigPtr: A pointer to the structure which contains
**                                initialization parameters.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_Init \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr \
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
    ErrStatus = Port_InitVerify(ConfigPtr);
    if(ErrStatus == (Std_ReturnType)E_OK)/* polyspace RTE:UNR */
#endif
    {

#if (PORT_PRECOMPILE_SUPPORT == STD_ON)
        s_pPort_Config = &Port_Config;
        (void)ConfigPtr;
#else
        s_pPort_Config = ConfigPtr;
#endif

        Port_Wrapper_Init(s_pPort_Config);

#if (PORT_SET_SIUL2_API == STD_ON)
        Port_Siul2_SetExtRequest(s_pPort_Config->reqConfig);
#endif
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        Port_Status = PORT_INIT;
#endif
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)

/*****************************************************************************
**  Service Name     : Port_SetPinDirectionVerify
**
**  Description      : check Parameters
**
**  Parameters (in)  : Pin: Pin ID number.
**
**  Parameters (out) : None
**
**
******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(Std_ReturnType, PORT_CODE) Port_SetPinDirectionVerify \
( \
    VAR(Port_PinType,           AUTOMATIC) Pin
)
{
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;

    VAR(uint32, AUTOMATIC) PortCoreId = 0U;
    PortCoreId = Port_GetCoreID();  /*comment get core id*/

    // Variable used to store current error status
    if(PortCoreId < PORT_CORE_NUM)
    {
        // Check if Port module is initialized
        if (PORT_UNINIT == Port_Status)
        {
            Port_Det_ReportError((uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_UNINIT);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
        // Check port pin validity
        else if (Pin >= (Port_PinType)s_pPort_Config->Port_UsedPin.u16Port_NumPins)/* polyspace RTE:IDP */
        {
            Port_Det_ReportError((uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_PARAM_PIN);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#if !(defined (RESOURCE_SUPPORT_SIUL_IP))
        else if (s_pPort_Config->Port_UsedPin.pPort_UsedPadConfig[Pin].bPort_DC == FALSE)
        {
            Port_Det_ReportError((uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_MODE_UNCHANGEABLE);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#endif
#if (PORT_CORE_NUM != 1U)
        else if ((((s_pPort_Config->coreMap[Pin].u8CoreId)&((uint32)1UL << PortCoreId)) >> PortCoreId) != 1U)/* polyspace RTE:NIV,IDP */
        {
            Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_CONFIG);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#endif
        else
        {
            // do nothing
        }
    }
    return ErrStatus;

}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
/*****************************************************************************
**  Service Name     : Port_SetPinDirection
**
**  Description      : The function @p Port_SetPinDirection() will set the port pin direction
**                     during runtime.
**
**  Parameters (in)  : Pin: Pin ID number.
**                     Direction: Port Pin direction.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_SetPinDirection \
( \
    VAR(Port_PinType,           AUTOMATIC) Pin, \
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction \
)
{
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
        VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
        ErrStatus = Port_SetPinDirectionVerify(Pin);
        if(ErrStatus == (Std_ReturnType)E_OK)
    #endif
        {
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
            ErrStatus \
            = Port_Wrapper_SetPinDirection(Pin, (Port_PinDirectionType)Direction, s_pPort_Config);
    #else
            (void)Port_Wrapper_SetPinDirection \
                            (Pin, (Port_PinDirectionType)Direction, s_pPort_Config);
    #endif

    #if (PORT_DEV_ERROR_DETECT == STD_ON)
            if ((Std_ReturnType)E_NOT_OK == ErrStatus)
            {
                Port_Det_ReportError((uint8)PORT_SETPINDIRECTION_ID, \
                            (uint8)PORT_E_DIRECTION_UNCHANGEABLE);
            }
    #endif
        }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

#if (PORT_SET_PIN_MODE_API == STD_ON)

/*****************************************************************************
**  Service Name     : Port_SetPinModeVerify
**
**  Description      : check Parameters
**
**  Parameters (in)  : Pin: Pin ID number.
**
**  Parameters (out) : None
**
**
******************************************************************************/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(Std_ReturnType, PORT_CODE) Port_SetPinModeVerify \
( \
    VAR(Port_PinType,     AUTOMATIC) Pin
)
{
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) PortCoreId = 0U;
    PortCoreId = Port_GetCoreID();  /*comment get core id*/
    if(PortCoreId < PORT_CORE_NUM)
    {
        // Check if port is initialized
         if (PORT_UNINIT == Port_Status)
        {
            Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_UNINIT);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#if !(defined (RESOURCE_SUPPORT_SIUL_IP))
        // Check port pin mode Unchangeable
        else if((boolean)FALSE == \
                        (boolean) s_pPort_Config->Port_UsedPin.pPort_UsedPadConfig[Pin].bPort_MC)/* polyspace RTE:IDP */
        {
            Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_MODE_UNCHANGEABLE);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#endif
        // Check port pin validity
        else if (Pin >= (Port_PinType)s_pPort_Config->Port_UsedPin.u16Port_NumPins)/* polyspace RTE:IDP */
        {
            Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_PIN);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#if (PORT_CORE_NUM != 1U)
        else if ((((s_pPort_Config->coreMap[Pin].u8CoreId)&((uint32)1UL << PortCoreId)) >> PortCoreId) != 1U)/* polyspace RTE:NIV,IDP */
        {
            Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_CONFIG);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#endif
        else
        {
            // do nothing
        }
    }
    return ErrStatus;
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
/*****************************************************************************
**  Service Name     : Port_SetPinMode
**
**  Description      : The function @p Port_SetPinMode() will set the port pin mode of the
**                     referenced pin during runtime.
**
**  Parameters (in)  : Pin: Pin ID number.
**                     Mode: New Port Pin mode to be set on port pin.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_SetPinMode \
( \
    VAR(Port_PinType,     AUTOMATIC) Pin, \
    VAR(Port_PinModeType, AUTOMATIC) Mode \
)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    VAR(uint8, AUTOMATIC) u8PinModeError = (uint8)0U;
#endif
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
        VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
        ErrStatus = Port_SetPinModeVerify(Pin);
        if(ErrStatus == (Std_ReturnType)E_OK)
    #endif
        {
            // Sets the port pin direction
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
            u8PinModeError = (uint8)Port_AutoSar_Wrapper_SetPinMode(Pin, Mode, s_pPort_Config);
    #else
            (void)Port_AutoSar_Wrapper_SetPinMode(Pin, Mode, s_pPort_Config);
    #endif

    #if (PORT_DEV_ERROR_DETECT == STD_ON)
            if (PORT_E_PARAM_INVALID_MODE == u8PinModeError)
            {
                Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_INVALID_MODE);
            }
    #endif
        }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

/*****************************************************************************
**  Service Name     : Port_RefreshPortDirectionVerify
**
**  Description      : check Parameters
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**
******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(Std_ReturnType, PORT_CODE) Port_RefreshPortDirectionVerify( void )
{
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) PortCoreId = 0U;
    PortCoreId = Port_GetCoreID();  /*comment get core id*/
    if(PortCoreId < PORT_CORE_NUM)
    {
        // Check if Port module is initialized
        if (PORT_UNINIT == Port_Status)
        {
            Port_Det_ReportError((uint8)PORT_REFRESHPINDIRECTION_ID, (uint8)PORT_E_UNINIT);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
        else if ((((s_pPort_Config->coreMap->u8CoreId)&((uint32)1UL << PortCoreId)) >> PortCoreId) != 1U)/* polyspace RTE:NIV,IDP */
        {
            Port_Det_ReportError((uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_CONFIG);
            ErrStatus = (Std_ReturnType)E_NOT_OK;
        }
#endif
        else
        {
            // do nothing
        }
    }
    return ErrStatus;
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
/*****************************************************************************
**  Service Name     : Port_RefreshPortDirection
**
**  Description      : This function will refresh the direction of all configured ports to
**                     the configured direction.
**                     The PORT driver will exclude from refreshing those port pins that
**                     are configured as "pin direction changeable during runtime".
**                     @pre     @p Port_Init() must have been called first.
**
**  Parameters (in)  : None
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_RefreshPortDirection( void )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
    ErrStatus = Port_RefreshPortDirectionVerify();
    if(ErrStatus == (Std_ReturnType)E_OK)
#endif
    {
        Port_Wrapper_UpdataPortDir(s_pPort_Config);
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"


#if (PORT_VERSION_INFO_API == STD_ON)

/*****************************************************************************
**  Service Name     : Port_GetVersionInfoVerify
**
**  Description      : check Parameters
**
**  Parameters (in,out)  : versioninfo: Pointer to where to store the version
**                                      information of this module.
**
**  Return value     : None
**
******************************************************************************/
#if (PORT_DEV_ERROR_DETECT == STD_ON)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(Std_ReturnType, PORT_CODE) Port_GetVersionInfoVerify \
( \
    P2CONST(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) versioninfo \
)
{
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
    if (NULL_PTR == versioninfo)
    {/* polyspace RTE:UNR */
        Port_Det_ReportError((uint8)PORT_GETVERSIONINFO_ID, (uint8)PORT_E_PARAM_POINTER);
        ErrStatus = (Std_ReturnType)E_NOT_OK;
    }

    return ErrStatus;
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

/*****************************************************************************
**  Service Name     : Port_GetVersionInfo
**
**  Description      : The function Port_GetVersionInfo() will return the version
**                     information of this module. The version information includes:
**                     - Module Id,
**                     - Vendor Id,
**                     - Vendor specific version numbers.
**
**  Parameters (in,out)  : versioninfo: Pointer to where to store the version
**                                      information of this module.
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) versioninfo \
)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_OK;
    ErrStatus = Port_GetVersionInfoVerify(versioninfo);
    if(ErrStatus == (Std_ReturnType)E_OK)/* polyspace RTE:UNR */
#endif
    {
        (versioninfo)->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
        (versioninfo)->vendorID         = (uint16)PORT_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PORT_MODULE_ID;
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

/*****************************************************************************
**  Service Name     : Port_Siul2_SetExtRequest
**
**  Description      : Interrupt clear flag bit

**  @brief           : Configures the eirq pin interrupt
**
******************************************************************************/
#if (PORT_SET_SIUL2_API == STD_ON)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE)Port_Siul2_SetExtRequest \
( \
	P2CONST(Port_siul2_request_config, P2CONST, PORT_APPL_DATA) reqConfig \
)
{
	uint8 Count= 0;

    for(Count = 0; Count < PORT_SIUL2_NUM;Count ++)
    {
    	uint32 eirqIndexReg = (uint32)(1UL << reqConfig[Count].eirq_index);/* polyspace RTE:NIV,SHF,IDP */
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
        if (reqConfig[Count].event_edge_sel != SIUL2_EVENT_DISABLED)/* polyspace RTE:NIV */
        {
            SIUL.ISR.R  |= eirqIndexReg; /* clear eirq pin status flag */
            SIUL.IRER.R |= eirqIndexReg;


            /* select request edge trigger */
            if (reqConfig[Count].event_edge_sel == SIUL2_EVENT_RISING_EDGE)
            {
                SIUL.IREER.R |= eirqIndexReg;
                SIUL.IFEER.R &= ~eirqIndexReg;
            }
            else if (reqConfig[Count].event_edge_sel == SIUL2_EVENT_FALLING_EDGE)
            {
                SIUL.IREER.R &= ~eirqIndexReg;
                SIUL.IFEER.R |= eirqIndexReg;
            }
            else
            {
                SIUL.IREER.R |= eirqIndexReg;
                SIUL.IFEER.R |= eirqIndexReg;
            }

            SIUL.IFER.R &= ~eirqIndexReg;
#else
    	if (reqConfig[Count].event_edge_sel != SIUL2_EVENT_DISABLED)
		{
			SIUL2.DISR0.R  = eirqIndexReg; /* clear eirq pin status flag */
			SIUL2.DIRER0.R |= eirqIndexReg;


			/* select request edge trigger */
			if (reqConfig[Count].event_edge_sel == SIUL2_EVENT_RISING_EDGE)
			{
				SIUL2.IREER0.R |= eirqIndexReg;
				SIUL2.IFEER0.R &= ~eirqIndexReg;
			}
			else if (reqConfig[Count].event_edge_sel == SIUL2_EVENT_FALLING_EDGE)
			{
				SIUL2.IREER0.R &= ~eirqIndexReg;
				SIUL2.IFEER0.R |= eirqIndexReg;
			}
			else
			{
				SIUL2.IREER0.R |= eirqIndexReg;
				SIUL2.IFEER0.R |= eirqIndexReg;
			}

            SIUL2.IFER0.R &= ~eirqIndexReg;
#endif
			/* register callback function */
			if (reqConfig[Count].eirq_cb != NULL_PTR)/* polyspace RTE:NIP */
			{
				eirq_cb[reqConfig[Count].eirq_index] = reqConfig[Count].eirq_cb;/* polyspace RTE:IDP,OBAI */
			}
		}
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
