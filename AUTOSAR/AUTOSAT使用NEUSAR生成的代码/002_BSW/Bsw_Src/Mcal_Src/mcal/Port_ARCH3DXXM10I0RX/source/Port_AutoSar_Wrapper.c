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
*   @file    Port_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/
/* PRQA S 2983,2985,2991,2995,2992,2996 EOF */
/* PRQA S 0491, 4342, 2844, 1841, 4542 EOF */
#ifdef __cplusplus
extern "C"{
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Port_AutoSar_Wrapper.h" /* PRQA S 0380 */
#include "Port.h"
#include "Port_Register.h"
#include "SchM_Port.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */

#define PORT_C_VENDOR_ID_IPW                    176

#define PORT_C_AR_REL_MAJOR_VER_IPW             4

#define PORT_C_AR_REL_MINOR_VER_IPW             4

#define PORT_C_AR_REL_REV_VER_IPW               0

#define PORT_C_SW_MAJOR_VERSION_IPW             3
#define PORT_C_SW_MINOR_VERSION_IPW             0
#define PORT_C_SW_PATCH_VERSION_IPW             0


/* ============================================FILE VERSION CHECKS=================================== */

#if (PORT_C_VENDOR_ID_IPW != PORT_H_VENDOR_ID_IPW)
    #error "NON-MATCHED DATA : PORT_VENDOR_ID_IPW_H"
#endif

#if (PORT_C_AR_REL_MAJOR_VER_IPW != PORT_H_AR_REL_MAJOR_VER_IPW)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION_IPW_H"
#endif

#if (PORT_C_AR_REL_MINOR_VER_IPW != PORT_H_AR_REL_MINOR_VER_IPW)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION_IPW_H"
#endif

#if (PORT_C_AR_REL_REV_VER_IPW != PORT_H_AR_REL_REV_VER_IPW)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_REVISION_VERSION_IPW_H"
#endif

#if (PORT_C_SW_MAJOR_VERSION_IPW != PORT_H_SW_MAJOR_VERSION_IPW)
    #error "NON-MATCHED DATA : PORT_SW_MAJOR_VERSION_IPW_H"
#endif

#if (PORT_C_SW_MINOR_VERSION_IPW != PORT_H_SW_MINOR_VERSION_IPW)
    #error "NON-MATCHED DATA : PORT_SW_MINOR_VERSION_IPW_H"
#endif

#if (PORT_C_SW_PATCH_VERSION_IPW != PORT_H_SW_PATCH_VERSION_IPW)
    #error "NON-MATCHED DATA : PORT_SW_PATCH_VERSION_IPW_H"
#endif

#if (PORT_C_VENDOR_ID_IPW != PORT_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_VENDOR_ID"
#endif

#if (PORT_C_AR_REL_MAJOR_VER_IPW != PORT_AR_RELEASE_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION"
#endif

#if (PORT_C_AR_REL_MINOR_VER_IPW != PORT_AR_RELEASE_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION"
#endif

#if (PORT_C_AR_REL_REV_VER_IPW != PORT_AR_RELEASE_REV_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_REV_VERSION"
#endif

#if (PORT_C_SW_PATCH_VERSION_IPW != PORT_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_PATCH_VERSION"
#endif

#if (PORT_C_VENDOR_ID_IPW != REGESYS_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_VENDOR_ID"
#endif

#if (PORT_C_AR_REL_MAJOR_VER_IPW != REGESYS_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (PORT_C_AR_REL_MINOR_VER_IPW != REGESYS_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MINOR_VER"
#endif

#if (PORT_C_AR_REL_REV_VER_IPW != REGESYS_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_REV_VER"
#endif

#if (PORT_C_SW_MAJOR_VERSION_IPW != REGESYS_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MAJOR_VERSION"
#endif

#if (PORT_C_SW_MINOR_VERSION_IPW != REGESYS_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MINOR_VERSION"
#endif

#if (PORT_C_SW_PATCH_VERSION_IPW != REGESYS_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif

/* =========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)=============================== */


/* ======================================LOCAL MACROS================================================ */


/* ======================================LOCAL CONSTANTS============================================= */


/* ======================================LOCAL VARIABLES============================================= */


/* ======================================GLOBAL CONSTANTS============================================ */


/* ======================================GLOBAL VARIABLES============================================ */


/* ==================================LOCAL FUNCTION PROTOTYPES======================================= */


#if (STD_ON == PORT_SET_PIN_MODE_API)
#if defined RESOURCE_SUPPORT_EIOMUX
#elif defined RESOURCE_SUPPORT_EIOMUX2
#else
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(uint16, PORT_CODE) Port_AutoSar_Wrapper_GetIndexForInoutEntry
(
    VAR    (Port_InternalPinIdType, AUTOMATIC) u16Port_PinPad,
    VAR    (Port_PinModeType,       AUTOMATIC) u8Port_PinMode
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
#endif

/* ======================================LOCAL FUNCTIONS============================================= */
#if (STD_ON == PORT_SET_PIN_MODE_API)

#if defined RESOURCE_SUPPORT_EIOMUX
#elif defined RESOURCE_SUPPORT_EIOMUX2
#else
/*****************************************************************************
**  Service Name     : Port_Wrapper_GetIndexForInoutEntry
**
**  Description      : Searches index of an entry having a given Pad number and a given PadMode in
**                     Port_aPadFunctInoutMuxSettings[] table
**
**  Parameters (in)  : PinPad: Number of the pad for which index in Port_aPadFunctInoutMuxSettings is requested.
**                     PinMode: Mode of the pad for which index in Port_aPadFunctInoutMuxSettings is requested
**
**  Parameters (out) : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
Port_INLINE FUNC(uint16, PORT_CODE) Port_AutoSar_Wrapper_GetIndexForInoutEntry \
( \
    VAR    (Port_InternalPinIdType, AUTOMATIC) u16Port_PinPad, \
    VAR    (Port_PinModeType,       AUTOMATIC) u8Port_PinMode \
)
{
    VAR(uint16,         AUTOMATIC) u16Port_ReturnIndex = (uint16)0;
    VAR(uint16,         AUTOMATIC) u16Port_Counter     = 0;

    u16Port_Counter = (uint16)0U;
    while(u16Port_Counter < PORT_INOUT_TABLE_NUM_ENTRIES_U16)
    {
        if((Port_aPadFunctInoutMuxSettings[u16Port_Counter].u16Port_MSCR \
                                                                == (uint16)u16Port_PinPad) \
            && (Port_aPadFunctInoutMuxSettings[u16Port_Counter].u8Port_Mode \
                                                                == (uint8)u8Port_PinMode))
        {
            SchM_Enter_Port_EXCLUSIVE_AREA_00();
            u16Port_ReturnIndex = u16Port_Counter;
            SchM_Exit_Port_EXCLUSIVE_AREA_00();
            break;
        }
        u16Port_Counter++;
    }
    return u16Port_ReturnIndex;
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

#endif
/* ======================================GLOBAL FUNCTIONS============================================ */

#if (STD_ON == PORT_SET_PIN_MODE_API)

/*****************************************************************************
**  Service Name     : Port_AutoSar_Wrapper_SetPinMode
**
**  Description      : The function @p Port_AutoSar_Wrapper_SetPinMode will set the port pin mode of the
**                     referenced pin during runtime.
**
**  Parameters (in)  : PinIndex: Pin ID number.
**                     PinMode: New Port Pin mode to be set on port pin.
**                     pConfigPtr: Pointer to the initialization data structure
**
**  Parameters (out) : None
**
******************************************************************************/
#if defined  RESOURCE_SUPPORT_EIOMUX
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(Std_ReturnType, PORT_CODE) Port_AutoSar_Wrapper_SetPinMode_EIOMUX \
( \
    VAR    (Port_PinType,     AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinModeType, AUTOMATIC                 ) u16Port_PinMode, \
    P2CONST(Port_ConfigType,  AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    VAR(uint8,                AUTOMATIC) u8Port_PinMode = (uint8)(u16Port_PinMode & (uint8)0xFF);/*PRQA S 2919*/

    VAR(Std_ReturnType,     AUTOMATIC) u8Port_PinModeError = (Std_ReturnType)0UL;
    VAR(Port_InternalPinIdType, AUTOMATIC) sPort_PinPad \
            = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin;/* polyspace RTE:IDP */

    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex \
                                                        = (Port_InternalPinIdType)sPort_PinPad;

    VAR(Port_PinDirectionType, AUTOMATIC) ePort_PadDirection = (Port_PinDirectionType)0UL;

    VAR(Port_RegValueType,     AUTOMATIC) u32Port_MSCR_Mask = PORT_LLD_INMUX_UNUSE_PATTEN_U32;

    if(PORT_IOMODE_VALID_MAX > u8Port_PinMode)
    {
    	if(PORT_GPIO_MODE == u8Port_PinMode)
    	{
    		Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)TRUE);
    		ePort_PadDirection = (Port_PinDirectionType)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u8Port_PDDir);
            #if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
    		if(PORT_PIN_IN != ePort_PadDirection)
    		{
    			Port_LLD_SetGpioPadOutput(u32Port_PinIndex, pPort_ConfigPtr);
    		}
            #endif
    		(void)Port_LLD_SetPinDirection(u32Port_PinIndex, ePort_PadDirection, pPort_ConfigPtr);
    	}
    	else if((PORT_OUT_IOMODE_1 < u8Port_PinMode) && (PORT_IN_OUT_IOMODE_END > u8Port_PinMode ))
    	{
    		/* Output and I/O mode, need to configure ODC of MSCR*/
    		u32Port_MSCR_Mask = (Port_RegValueType)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC & SIUL2_MSCR_ODC_U32);
    		Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
    	}
    	else
    	{
    		Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
    	}

    	Port_LLD_SetPinMode_EIOMUX(u16Port_PinCfgRegIndex, u8Port_PinMode, u32Port_MSCR_Mask);
    }
    else
    {
    	u8Port_PinModeError = PORT_E_PARAM_INVALID_MODE;
    }

    return (u8Port_PinModeError);
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

/* ======================================GLOBAL FUNCTIONS============================================ */


/*****************************************************************************
**  Service Name     : Port_AutoSar_Wrapper_SetPinMode
**
**  Description      : The function @p Port_AutoSar_Wrapper_SetPinMode will set the port pin mode of the
**                     referenced pin during runtime.
**
**  Parameters (in)  : PinIndex: Pin ID number.
**                     PinMode: New Port Pin mode to be set on port pin.
**                     pConfigPtr: Pointer to the initialization data structure
**
**  Parameters (out) : None
**
******************************************************************************/
#if defined  RESOURCE_SUPPORT_EIOMUX2
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(Std_ReturnType, PORT_CODE) Port_AutoSar_Wrapper_SetPinMode_EIOMUX2 \
( \
    VAR    (Port_PinType,     AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinModeType, AUTOMATIC                 ) u32Port_PinMode, \
    P2CONST(Port_ConfigType,  AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    VAR(Std_ReturnType,     AUTOMATIC) u8Port_PinModeError = (Std_ReturnType)0UL;
    VAR(Port_InternalPinIdType, AUTOMATIC) sPort_PinPad \
            = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin;/* polyspace RTE:IDP */

    VAR(Port_PinDirectionType, AUTOMATIC) ePort_PadDirection = (Port_PinDirectionType)0UL;

    VAR(uint8,   AUTOMATIC) u8isAnMode = 0U;
    VAR(uint8,   AUTOMATIC) u8PortDir = 0U;
    VAR(uint8,   AUTOMATIC) u8FuncSel = 0U;
    VAR(uint16,   AUTOMATIC) u16MscrId = 0U;

    u8isAnMode = (uint8)((u32Port_PinMode & PORT_MODE_AN_MASK) >> 24U);
    u8PortDir =  (uint8)((u32Port_PinMode & PORT_MODE_DIR_INOUT_MASK) >> 26U);
    u8FuncSel =  (uint8)((u32Port_PinMode & PORT_MODE_SSS_MASK));
    u16MscrId = (uint16)((u32Port_PinMode & PORT_MODE_MSCR_MASK) >> 8U);

    /* check Port_Mode valid */
    if(((512u > u16MscrId) && (sPort_PinPad != u16MscrId)) ||
       ((uint16)(512U+(uint16)EIOMUX2_ISR_REG_NUM_MAX) <= u16MscrId))
    {
    	return PORT_E_PARAM_INVALID_MODE;
    }

    if(0xfU < u8FuncSel)
    {
    	return PORT_E_PARAM_INVALID_MODE;
    }

    /* not Analog */
    if(1U == u8isAnMode)
    {
    	Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
    }
    else
    {
        if(3U == u8PortDir)
        {
            /* Handle Output_Input set */
        	/* GPIO */
        	if(0U == u8FuncSel)
        	{
                Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)TRUE);
                /* the original direction set from Port_Config */
                ePort_PadDirection = (Port_PinDirectionType)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u8Port_PDDir);
                #if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
                    if(PORT_PIN_IN != ePort_PadDirection)
                    {
                        Port_LLD_SetGpioPadOutput(u32Port_PinIndex, pPort_ConfigPtr);
                    }
                #endif
        	}
        }
        else if(1U == u8PortDir)
        {
            /* Handle Output set*/
            Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
        }
        else
        {
            /* Handle Input set*/
            Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
        }
    }

    Port_LLD_SetPinMode_EIOMUX2(sPort_PinPad, u32Port_PinMode);

    return (u8Port_PinModeError);
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(Std_ReturnType, PORT_CODE) Port_AutoSar_Wrapper_SetPinMode \
( \
    VAR    (Port_PinType,     AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinModeType, AUTOMATIC                 ) Port_PinMode, \
    P2CONST(Port_ConfigType,  AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
#if defined RESOURCE_SUPPORT_EIOMUX
    /* for configure EIOMUX PAD */
    return Port_AutoSar_Wrapper_SetPinMode_EIOMUX(u32Port_PinIndex, Port_PinMode, pPort_ConfigPtr);
#elif defined RESOURCE_SUPPORT_EIOMUX2
    /* for configure EIOMUX2 PAD */
    return Port_AutoSar_Wrapper_SetPinMode_EIOMUX2(u32Port_PinIndex, Port_PinMode, pPort_ConfigPtr);
#else
    VAR(uint8,                AUTOMATIC) u8Port_PinMode = (uint8)(Port_PinMode & (uint8)0xFF);

    VAR(Std_ReturnType,     AUTOMATIC) u8Port_PinModeError = (Std_ReturnType)0UL;
    VAR(Port_InternalPinIdType, AUTOMATIC) sPort_PinPad \
            = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin;/* polyspace RTE:IDP */

    VAR(uint8,                AUTOMATIC) u8Port_PinDescBitOffset = 0;
    VAR(uint16,               AUTOMATIC) u16Port_PinDescWord     = 0;
    VAR(Port_InMuxSettingType,AUTOMATIC) sPort_PadInMuxData;

    VAR(uint16,                 AUTOMATIC) u16Port_Index            = 0;
    VAR(uint16,                 AUTOMATIC) u16Port_InMuxRegIndex    = NO_INPUTMUX_U16;
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_PinCfgRegValue   = \
                                                        (Port_RegValueType)u8Port_PinMode;
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_InMuxRegValue    = (Port_RegValueType)0UL;
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex \
                                                        = (Port_InternalPinIdType)sPort_PinPad;

    VAR(Port_PinDirectionType, AUTOMATIC) ePort_PadDirection = (Port_PinDirectionType)0UL;
    VAR(Port_InoutSettingType,  AUTOMATIC) sPort_PadInoutData;

#if defined RESOURCE_SUPPORT_SIUL2_IP && !(defined (RESOURCE_SUPPORT_EIOMUX) ||defined (RESOURCE_SUPPORT_EIOMUX2))
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU_INPUT_SELECT_MASK = ETPU_INPUT_SELECT_MASK;
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU1CH29_INPUT_SELECT_MASK = ETPU1CH29_INPUT_SELECT_MASK;
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU1CH28_INPUT_SELECT_MASK = ETPU1CH28_INPUT_SELECT_MASK;
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU1CH27_INPUT_SELECT_MASK = ETPU1CH27_INPUT_SELECT_MASK;
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU1CH26_INPUT_SELECT_MASK = ETPU1CH26_INPUT_SELECT_MASK;
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU1CH25_INPUT_SELECT_MASK = ETPU1CH25_INPUT_SELECT_MASK;
    VAR(uint16,                 AUTOMATIC) u16Port_ETPU1CH24_INPUT_SELECT_MASK = ETPU1CH24_INPUT_SELECT_MASK;

    if((Port_PinMode & u16Port_ETPU_INPUT_SELECT_MASK) > 0U)
    {/* polyspace RTE:UNR */
        if((Port_PinMode & u16Port_ETPU1CH29_INPUT_SELECT_MASK) > 0U)
        {
            SIUL2.ISEL8.B.ETPU29 = 1U;
        }
        else if((Port_PinMode & u16Port_ETPU1CH28_INPUT_SELECT_MASK) > 0U)
        {
            SIUL2.ISEL8.B.ETPU28 = 1U;
        }
        else if((Port_PinMode & u16Port_ETPU1CH27_INPUT_SELECT_MASK) > 0U)
        {
            SIUL2.ISEL8.B.ETPU27 = 1U;
        }
        else if((Port_PinMode & u16Port_ETPU1CH26_INPUT_SELECT_MASK) > 0U)
        {
            SIUL2.ISEL8.B.ETPU26 = 1U;
        }
        else if((Port_PinMode & u16Port_ETPU1CH25_INPUT_SELECT_MASK) > 0U)
        {
            SIUL2.ISEL8.B.ETPU25 = 1U;
        }
        else if((Port_PinMode & u16Port_ETPU1CH24_INPUT_SELECT_MASK) > 0U)
        {
            SIUL2.ISEL8.B.ETPU24 = 1U;
        }
        else
        {
            //do nothing
        }
    }
#endif

    if(PAD_MODE_OPTIONS_U8 > u8Port_PinMode)
    {
        // Bit offset of Pin index inside the pin description matrix
        u8Port_PinDescBitOffset = (uint8)(sPort_PinPad & SIUL2_MODE_BIT_OFFSET_MASK_U8);
        // Selected word inside the pin description matrix
        u16Port_PinDescWord = \
                        (uint16)Port_au16PinDescription[(uint8)u8Port_PinMode][sPort_PinPad>>4];/* polyspace RTE:OBAI */

        if(u8Port_PinDescBitOffset <= 15U)/* polyspace RTE:UNR */
        {
            // Check if desired mode is valid for selected pin
            if ((u16Port_PinDescWord & (uint16)(1UL<<u8Port_PinDescBitOffset)) != (uint16)0)
            {
                if(((PORT_ALT1_FUNC_MODE <= u8Port_PinMode) \
                                            && (PORT_ALT15_FUNC_MODE >= u8Port_PinMode)) \
                                            || (PORT_ANALOG_INPUT_MODE == u8Port_PinMode))
                {
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
                    u32Port_InMuxRegValue \
                    = (Port_RegValueType) \
                    (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_PCR \
                        & SIUL_PCR_ODE_U16);
#else
                    u32Port_InMuxRegValue \
                    = (Port_RegValueType) \
                    (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC \
                        & SIUL2_MSCR_ODC_U32);
#endif
                    Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
                }
                else if((PORT_INOUT1_MODE <= u8Port_PinMode) && (PORT_INOUT5_MODE >= u8Port_PinMode))
                {
                    u16Port_Index = Port_AutoSar_Wrapper_GetIndexForInoutEntry(sPort_PinPad, u8Port_PinMode);
                    sPort_PadInoutData    = Port_aPadFunctInoutMuxSettings[u16Port_Index];
                    u16Port_InMuxRegIndex = (uint16)sPort_PadInoutData.u16Port_InMuxId;
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
                    u32Port_InMuxRegValue \
                    = (Port_RegValueType)
                    ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_PCR \
                        & SIUL_PCR_ODE_U16) | (uint16)(sPort_PadInoutData.u8Port_InMuxCode \
                        & SIUL_PCR_SSS_U16));
#else
                    u32Port_InMuxRegValue \
                    = (Port_RegValueType)
                    ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC \
                        & SIUL2_MSCR_ODC_U32) | (sPort_PadInoutData.u8Port_InMuxCode \
                        & SIUL2_IMCR_SSS_U32));
#endif
                    u32Port_PinCfgRegValue   = ((Port_RegValueType)u8Port_PinMode \
                                                + (Port_RegValueType)1UL) \
                                                - (Port_RegValueType)PORT_INOUT1_MODE;
                    Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
                }
                else if(PORT_ONLY_OUTPUT_MODE == u8Port_PinMode)
                {
                    u32Port_PinCfgRegValue = PORT_LLD_OUTPUT_ACTIVE_U32;
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
                    u32Port_InMuxRegValue \
                    = (Port_RegValueType) \
                    (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_PCR \
                        & SIUL_PCR_ODE_U16);
#else
                    u32Port_InMuxRegValue \
                    = (Port_RegValueType) \
                    (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC \
                        & SIUL2_MSCR_ODC_U32);
#endif
                    Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
                }
                else if(PORT_ONLY_INPUT_MODE == u8Port_PinMode)
                {
                    u32Port_PinCfgRegValue = PORT_LLD_INPUT_ACTIVE_U32;
                    Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
                }
                else if(PORT_GPIO_MODE == u8Port_PinMode)
                {
                    Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)TRUE);
                    ePort_PadDirection \
                    = (Port_PinDirectionType) \
                    (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u8Port_PDDir);
                    #if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
                    if(PORT_PIN_IN != ePort_PadDirection)
                    {
                        Port_LLD_SetGpioPadOutput(u32Port_PinIndex, pPort_ConfigPtr);
                    }
                    #endif
                    (void)Port_LLD_SetPinDirection(u32Port_PinIndex, ePort_PadDirection, \
                                                                            pPort_ConfigPtr);
                }
                else
                {
                    u32Port_PinCfgRegValue   = PORT_LLD_INPUT_ACTIVE_U32;
                    u16Port_Index            = Port_au16PadFunctInMuxIndex[sPort_PinPad];/* polyspace RTE:OBAI */
                    sPort_PadInMuxData       = Port_aPadFunctInMuxSettings \
                                                [(u16Port_Index + u8Port_PinMode) - PORT_INPUT1_MODE];/* polyspace RTE:OBAI */
                    u32Port_InMuxRegValue    = sPort_PadInMuxData.u8Port_InMuxCode;
                    u16Port_InMuxRegIndex    = (uint16)sPort_PadInMuxData.u16Port_InMuxId;
                    Port_LLD_SetGpioDirChangeability(sPort_PinPad,(boolean)FALSE);
                }

                // Sets the port pin mode
                Port_LLD_SetPinMode(u16Port_PinCfgRegIndex, u32Port_PinCfgRegValue, \
                                                u16Port_InMuxRegIndex, u32Port_InMuxRegValue);
            }
            else
            {
                u8Port_PinModeError = PORT_E_PARAM_INVALID_MODE;
            }
        }
    }
    else
    {
        u8Port_PinModeError = PORT_E_PARAM_INVALID_MODE;
    }

    return (u8Port_PinModeError);
#endif
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif




#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
