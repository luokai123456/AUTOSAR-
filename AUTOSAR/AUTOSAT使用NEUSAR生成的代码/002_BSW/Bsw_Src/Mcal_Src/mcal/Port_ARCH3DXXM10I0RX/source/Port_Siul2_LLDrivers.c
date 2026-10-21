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
*   @file    Port_LLDrivers.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/
/* PRQA S 2985,2991,2995,3344,1258,2983 EOF */
/* PRQA S 0491,2844,1841,4542,1259,2053,4461 EOF */
#ifdef __cplusplus
extern "C" {
#endif
/* ==============================================INCLUDE FILES======================================= */

#include "Port.h" /* PRQA S 0380 */
#include "Port_Register.h"
#include "Port_LLDriver.h"
#include "derivative.h"
#include "SchM_Port.h"

#if (defined (RESOURCE_SUPPORT_SIUL2_IP))
#define USER_MODE_REG_PROT_ENABLED (PORT_USER_MODE_SOFT_LOCKING)

#define PORT_MULTI_CORE_SUPPORT                      (0)

#define PORT_CORE_Z70_ID_MASK                        (0x01U)
#define PORT_CORE_Z71_ID_MASK                        (0x02U)
#define PORT_CORE_Z42_ID_MASK                        (0x04U)
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define PORT_C_SIUL2_VENDOR_ID                     176

#define PORT_C_SIUL2_AR_REL_MAJOR_VER              4

#define PORT_C_SIUL2_AR_REL_MINOR_VER              4

#define PORT_C_SIUL2_AR_REL_REV_VER                0
#define PORT_C_SIUL2_SW_MAJOR_VERSION              3
#define PORT_C_SIUL2_SW_MINOR_VERSION              0
#define PORT_C_SIUL2_SW_PATCH_VERSION              0

/* ============================================FILE VERSION CHECKS=================================== */


#if (PORT_C_SIUL2_VENDOR_ID != PORT_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != PORT_AR_RELEASE_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != PORT_AR_RELEASE_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION"
#endif

#if (PORT_C_SIUL2_AR_REL_REV_VER != PORT_AR_RELEASE_REV_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_REV_VERSION"
#endif

#if (PORT_C_SIUL2_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MAJOR_VERSION"
#endif

#if (PORT_C_SIUL2_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MINOR_VERSION"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_PATCH_VERSION"
#endif

#if (PORT_C_SIUL2_VENDOR_ID != PORT_H_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_SIUL2_VENDOR_ID_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != PORT_H_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != PORT_H_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_AR_REL_REV_VER != PORT_H_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_REVISION_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MAJOR_VERSION != PORT_H_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MINOR_VERSION != PORT_H_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != PORT_H_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_PATCH_VERSION_H"
#endif

#if (PORT_C_SIUL2_VENDOR_ID != REGESYS_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_VENDOR_ID"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != REGESYS_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != REGESYS_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MINOR_VER"
#endif

#if (PORT_C_SIUL2_AR_REL_REV_VER != REGESYS_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_REV_VER"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != REGESYS_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif

#if (PORT_C_SIUL2_VENDOR_ID != PORT_H_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_SIUL2_VENDOR_ID_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != PORT_H_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != PORT_H_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MAJOR_VERSION != PORT_H_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MINOR_VERSION != PORT_H_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != PORT_H_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_PATCH_VERSION_H"
#endif

/* =========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)=============================== */


/* ======================================LOCAL MACROS================================================ */


/* ======================================LOCAL CONSTANTS============================================= */


/* ======================================LOCAL VARIABLES============================================= */


/* ======================================GLOBAL CONSTANTS============================================ */


/* ======================================GLOBAL VARIABLES============================================ */



#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
#define PORT_START_SEC_VAR_NO_INIT
#include "Port_MemMap.h"
static VAR(uint16, PORT_VAR) s_u16Port_Siul2_au16GPIODirChangeability[PAD_16BLOCK_NO_U8];
#define PORT_STOP_SEC_VAR_NO_INIT
#include "Port_MemMap.h"
#endif


/* ==================================LOCAL FUNCTION PROTOTYPES======================================= */


/* ======================================LOCAL FUNCTIONS============================================= */

/* ======================================GLOBAL FUNCTIONS============================================ */

/*    CHECK SIUL2.MSCR_IO    */
#define WRITE_MSCRIO(idx,val) \
    (val) &= 0x77ff80ffu;                \
    SIUL2.MSCR_IO[(idx)].R = (val);      \
	(val) = SIUL2.MSCR_IO[(idx)].R;

/*    CHECK EIOMUX.PAD    */
#define WRITE_EIOMUX2_PAD(idx,val) \
    (val) &= 0x00000fffu;                \
    EIOMUX2.PAD[(idx)].R = (val);      \
	(val) = EIOMUX2.PAD[(idx)].R;
/*****************************************************************************
**  Service Name     : Port_LLD_Init
**
**  Description      : The function Port_LLD_Init will initialize ALL ports and port pins with the
**                     configuration set pointed to by the parameter pConfigPtr.
**
**  Parameters (in)  : pConfigPtr: A pointer to the structure which contains initialization parameters
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC(void, PORT_CODE) Port_LLD_Init \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    // Initialize all variables
    VAR(uint16, AUTOMATIC) u16Port_PinIndex = 0;
    VAR(uint16, AUTOMATIC) u16Port_PcrPin   = 0;
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinPad = 0;

    VAR(uint16, AUTOMATIC) u16Port_NumUnusedPins \
                                = (uint16)(pPort_ConfigPtr->Port_UnusedPin.u16Port_NumUnusedPins);
    VAR(uint16, AUTOMATIC) u16Port_NumPins \
                                = (uint16)(pPort_ConfigPtr->Port_UsedPin.u16Port_NumPins);
    VAR(uint32, PORT_VAR) PortRegVal1;
    #if defined RESOURCE_SUPPORT_EIOMUX2
    VAR(uint32, PORT_VAR) PortRegVal2;
    VAR(uint8, PORT_VAR)  u8Port_PreIoModeEiomux2;
    #endif
#ifndef RESOURCE_SUPPORT_EIOMUX
    VAR(uint32, AUTOMATIC) u32Port_LocalVar = 0;
    VAR(uint16, AUTOMATIC) u16Port_MuxIndex = 0;
    VAR(uint16, AUTOMATIC) u16Port_NumMuxRegs    = PORT_NMBR_INMUX_REGS_U16;
#else
    VAR(uint8, AUTOMATIC)  u8Port_PreIoMode = 0;
#endif
    VAR(uint32, AUTOMATIC) u32Port_LocalMSCR \
                            = pPort_ConfigPtr->Port_UnusedPin.pPort_UnusedPadConfig->u32Port_MSCR;
    VAR(uint8,  AUTOMATIC) u8Port_LocalPDO \
                            = pPort_ConfigPtr->Port_UnusedPin.pPort_UnusedPadConfig->u8Port_PDO;

#if (PORT_CORE_NUM != 1U)
    SIUL2.ISEL8.B.ETPU29 = pPort_ConfigPtr->Etpu_IS[0];
    SIUL2.ISEL8.B.ETPU28 = pPort_ConfigPtr->Etpu_IS[1];
    SIUL2.ISEL8.B.ETPU27 = pPort_ConfigPtr->Etpu_IS[2];
    SIUL2.ISEL8.B.ETPU26 = pPort_ConfigPtr->Etpu_IS[3];
    SIUL2.ISEL8.B.ETPU25 = pPort_ConfigPtr->Etpu_IS[4];
    SIUL2.ISEL8.B.ETPU24 = pPort_ConfigPtr->Etpu_IS[5];
#endif

    // Initialize All UnUsed Port Pins
    u16Port_PinIndex = (uint16)0U;
    SchM_Enter_Port_EXCLUSIVE_AREA_00();
    while( u16Port_PinIndex < u16Port_NumUnusedPins)
    {
        u16Port_PcrPin = pPort_ConfigPtr->Port_UnusedPin.au16Port_UnusedPads[u16Port_PinIndex];
        SIUL2.GPDO[u16Port_PcrPin].R = u8Port_LocalPDO;/* polyspace RTE:IDP,OBAI */
        // Write MSCR configuration from Configuration tool
        WRITE_MSCRIO(u16Port_PcrPin, u32Port_LocalMSCR);/* polyspace RTE:NIV,IDP */
        u16Port_PinIndex++;
    }

#if(defined(PORT_MULTI_CORE_SUPPORT) && (PORT_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)(1<<GetCoreID());
#endif
    // Initialize All Configured Port Pins
    u16Port_PinIndex = (uint16)0U;
    while(u16Port_PinIndex < u16Port_NumPins)
    {
#if(defined(PORT_MULTI_CORE_SUPPORT) && (PORT_MULTI_CORE_SUPPORT == 1))
        if((u32CoreID & (pPort_ConfigPtr->coreMap[u16Port_PinIndex].u8CoreId)) != 0U)
#endif
        {
            u8Port_LocalPDO \
                = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u8Port_PDO;
            u16Port_PinPad = (uint16) \
                (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u16Port_SIUPin);
            if (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].bPort_GPIO)
            {
                if (PORT_PIN_LEVEL_LOW_U8 == u8Port_LocalPDO)
                {
                    SIUL2.GPDO[u16Port_PinPad].R = (uint8)STD_LOW;/* polyspace RTE:IDP,OBAI */
                }
                else if (PORT_PIN_LEVEL_HIGH_U8 == u8Port_LocalPDO)
                {
                    SIUL2.GPDO[u16Port_PinPad].R = (uint8)STD_HIGH;/* polyspace RTE:IDP,OBAI */
                }
                else
                {
                    // do nothing
                }
            }
        }

    #if defined RESOURCE_SUPPORT_EIOMUX
        /* use ioMode to set module and func of pin */
        u8Port_PreIoMode = (uint8)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u8Port_IoMode);
        Port_LLD_SetEioMux(u16Port_PinPad, u8Port_PreIoMode);
    #endif
        PortRegVal1 = (uint32)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_MSCR);/* polyspace RTE:IDP,OBAI */
        SIUL2.MSCR_IO[u16Port_PinPad].R = (uint32)PortRegVal1;/* polyspace RTE:OBAI */
        SIUL2.MSCR_IO[u16Port_PinPad].R &= 0x77FF80FFU;
    #if defined RESOURCE_SUPPORT_EIOMUX2
        u8Port_PreIoModeEiomux2 = (uint8)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u8Port_IoMode);
        PortRegVal2 = Port_LLD_GetEioMux2(u8Port_PreIoModeEiomux2);
        PortRegVal2 |= PortRegVal1 & 0x0000001FU; /* Source Signal Select */
        PortRegVal2 |= ((PortRegVal1 & 0x07000000U) >> 19U); /* Output Drive Control */
        PortRegVal2 |= ((PortRegVal1 & 0x00800000U) >> 14U); /* Safe Mode Control */
        PortRegVal2 |= ((PortRegVal1 & 0x00080000U) >> 8U);  /* Input Buffer Enable */
        EIOMUX2.PAD[u16Port_PinPad].R = PortRegVal2;/* polyspace RTE:OBAI */
    #endif
        u16Port_PinIndex++;
    }

#if defined RESOURCE_SUPPORT_EIOMUX
    /* EIOMUX, no need to set inputmux */

#else
    // Write Multiplexed Pad configuration registers from Configuration tool
    u16Port_MuxIndex = (uint16)0U;
    while(u16Port_MuxIndex < u16Port_NumMuxRegs)
    {
    #if(defined(PORT_MULTI_CORE_SUPPORT) && (PORT_MULTI_CORE_SUPPORT == 1))
            if((u32CoreID & (pPort_ConfigPtr->coreMap[u16Port_PinIndex].u8CoreId)) != 0U)
    #endif
        {
            // Write MSCR configuration from Configuration tool
                u32Port_LocalVar \
                    = ((uint32)(pPort_ConfigPtr->Port_UsedPin.pPort_PadSelConfig[u16Port_MuxIndex]));

            if (PORT_LLD_INMUX_UNUSE_PATTEN_U32 != u32Port_LocalVar)
            {
				#if defined RESOURCE_SUPPORT_EIOMUX2
            	EIOMUX2.ICR[u16Port_MuxIndex].R = u32Port_LocalVar;/* polyspace RTE:OBAI */
				#else
                // Set all reserved bits of the IMCR register to their reset value
                u32Port_LocalVar|= SIUL2_IMCR_RESET_MASK_U32;
                SIUL2.MSCR_MUX[u16Port_MuxIndex].R = u32Port_LocalVar;
				#endif
            }
        }
        u16Port_MuxIndex++;
    }
#endif
    SchM_Exit_Port_EXCLUSIVE_AREA_00();

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
    // u16Port_Siul2_au16GPIODirChangeability is only used by PORT_Siul_SetPinDirection and PORT_Siul_SetPinMode functions
    // Initialize the Array with Change Direction Flags for GPIO
    u16Port_PinIndex = (uint16)0U;
    while(u16Port_PinIndex < PAD_16BLOCK_NO_U8)
    {
        s_u16Port_Siul2_au16GPIODirChangeability[u16Port_PinIndex] = (uint16)0UL;
        u16Port_PinIndex++;
    }
#endif

#ifdef EB_IO_DRIVER_ENHANCE_ENABLE 
    SSCM.CHIP_CR.B.EN_VD33 = 1U;
#endif
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"


#if (STD_ON == PORT_SET_PIN_MODE_API)

/*****************************************************************************
**  Service Name     : Port_LLD_SetPinDirection
**
**  Description      : Sets the pin direction at runtime, changing it only if the pin is configurated as
**                     changeable.
**
**  Parameters (in)  : PinIndex: Pin ID number
**                     eDirection: Port Pin direction
**                     pConfigPtr: A pointer to the structure which contains initialization parameters
**
**  Parameters (out) : None
**
**  Return value     : Error code after execution
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
FUNC (Std_ReturnType, PORT_CODE) Port_LLD_EIOMUX2_SetPinDirection \
( \
    VAR    (Port_PinType,          AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) ePort_Direction, \
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    // Point to the Port Pin MSCR register address
    VAR(uint16, AUTOMATIC) u16Port_PinPad \
    = (uint16)pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin;/* polyspace RTE:IDP */
    VAR(uint8, AUTOMATIC) u8Pad_Func_Select \
    = (uint8)pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u8Port_IoMode;/* polyspace RTE:IDP */
    // Return value
    VAR(Std_ReturnType, AUTOMATIC) u8Port_PinDirError = (Std_ReturnType)E_OK;
    VAR(uint8, AUTOMATIC) u8Port_ODC = 0U;
    // Bit Offset and Table value for change direction flag word
    VAR(uint8,  AUTOMATIC) u8Port_PinDescBitOffset \
                            = (uint8)((uint8)u8Pad_Func_Select & SIUL2_BIT_OFFSET_MASK_U8);
    VAR(uint16, AUTOMATIC) u16Port_PinChangeDirFlagWord \
                        = s_u16Port_Siul2_au16GPIODirChangeability[(uint8)(u16Port_PinPad>>4)];/* polyspace RTE:OBAI */
    if(u8Port_PinDescBitOffset <= 15U)
    {
        // Check the Direction changeability option
        if (((boolean)TRUE == \
            pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].bPort_DC) \
            || ((uint16)0 != (u16Port_PinChangeDirFlagWord & (uint16)(1UL<<u8Port_PinDescBitOffset))))
        {
            SchM_Enter_Port_EXCLUSIVE_AREA_01();
            // Configures Port Pin as Output
            if (PORT_PIN_OUT == ePort_Direction)
            {
            	/* Disable IBE */
                EIOMUX2.PAD[u16Port_PinPad].R &= (~EIOMUX2_PADX_IBE_ON_U32);/* polyspace RTE:NIV,IDP,OBAI */
                /* Get ODC value taken from configuration */
                u8Port_ODC = (uint8)((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC & SIUL2_MSCR_ODC_U32) \
                		     >> SIUL2_MSCR_ODC_OFFSET_U32);
                /* Set ODC */
                EIOMUX2.PAD[u16Port_PinPad].R |= (uint32)u8Port_ODC << EIOMUX2_PADX_ODC_OFFSET_U32;
            }
            // Configures Port Pin as Input
            else if (PORT_PIN_IN == ePort_Direction)
            {
            	EIOMUX2.PAD[u16Port_PinPad].R &= ~EIOMUX2_PADX_ODC_MASK_U32;/* polyspace RTE:NIV,IDP,OBAI */
            	EIOMUX2.PAD[u16Port_PinPad].R |= EIOMUX2_PADX_IBE_ON_U32;/* polyspace RTE:NIV,IDP,OBAI */
            }
            else
            {
            	EIOMUX2.PAD[u16Port_PinPad].R |= EIOMUX2_PADX_IBE_ON_U32;/* polyspace RTE:NIV,IDP,OBAI */
                /* Get ODC value taken from configuration */
                u8Port_ODC = (uint8)((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC & SIUL2_MSCR_ODC_U32) \
                		     >> SIUL2_MSCR_ODC_OFFSET_U32);
                /* Set ODC */
                EIOMUX2.PAD[u16Port_PinPad].R |= (uint32)u8Port_ODC << EIOMUX2_PADX_ODC_OFFSET_U32;
            }
            SchM_Exit_Port_EXCLUSIVE_AREA_01();
            WRITE_EIOMUX2_PAD(u16Port_PinPad, EIOMUX2.PAD[u16Port_PinPad].R);/* polyspace RTE:NIV,IDP */
        }
    }
    // Direction changeability is NOT supported
    else
    {
        u8Port_PinDirError = (Std_ReturnType)E_NOT_OK;
    }

    return u8Port_PinDirError;
}
#else
FUNC (Std_ReturnType, PORT_CODE) Port_LLD_SetPinDirection \
( \
    VAR    (Port_PinType,          AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) ePort_Direction, \
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    // Point to the Port Pin MSCR register address
    VAR(uint16, AUTOMATIC) u16Port_PinPad \
    = (uint16)pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin;/* polyspace RTE:IDP */

    // Return value
    VAR(Std_ReturnType, AUTOMATIC) u8Port_PinDirError = (Std_ReturnType)E_OK;

    // Bit Offset and Table value for change direction flag word
    VAR(uint8,  AUTOMATIC) u8Port_PinDescBitOffset \
                            = (uint8)((uint8)u16Port_PinPad & SIUL2_BIT_OFFSET_MASK_U8);
    VAR(uint16, AUTOMATIC) u16Port_PinChangeDirFlagWord \
                        = s_u16Port_Siul2_au16GPIODirChangeability[(uint8)(u16Port_PinPad>>4)];/* polyspace RTE:OBAI */
    if(u8Port_PinDescBitOffset <= 15U)
    {
        // Check the Direction changeability option
        if (((boolean)TRUE == \
            pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].bPort_DC) \
            || ((uint16)0 != (u16Port_PinChangeDirFlagWord & (uint16)(1UL<<u8Port_PinDescBitOffset))))
        {
            SchM_Enter_Port_EXCLUSIVE_AREA_01();
            // Configures Port Pin as Output
            if (PORT_PIN_OUT == ePort_Direction)
            {
                SIUL2.MSCR_IO[u16Port_PinPad].R &= (~SIUL2_MSCR_IBE_ON_U32);/* polyspace RTE:NIV,IDP,OBAI */
                // Set MSCR.ODC bitfield to the value taken from configuration
                SIUL2.MSCR_IO[u16Port_PinPad].R |= (SIUL2.MSCR_IO[u16Port_PinPad].R /* polyspace RTE:NIV,IDP */
                & (~SIUL2_MSCR_IBE_ON_U32)) \
                | (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC /* polyspace RTE:NIV */
                & SIUL2_MSCR_ODC_U32);
            }
            // Configures Port Pin as Input
            else if (PORT_PIN_IN == ePort_Direction)
            {
                SIUL2.MSCR_IO[u16Port_PinPad].R &= ~SIUL2_MSCR_ODC_U32;/* polyspace RTE:NIV,IDP,OBAI */
                SIUL2.MSCR_IO[u16Port_PinPad].R |= SIUL2_MSCR_IBE_ON_U32;/* polyspace RTE:NIV,IDP */
            }
            else
            {
                SIUL2.MSCR_IO[u16Port_PinPad].R |= SIUL2_MSCR_IBE_ON_U32;/* polyspace RTE:NIV,IDP,OBAI */
                // Set MSCR.ODC bitfield to the value taken from configuration
                SIUL2.MSCR_IO[u16Port_PinPad].R = (SIUL2.MSCR_IO[u16Port_PinPad].R /* polyspace RTE:NIV,IDP */
                & (~SIUL2_MSCR_ODC_U32)) \
                | (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_ODC /* polyspace RTE:NIV */
                & SIUL2_MSCR_ODC_U32);
            }
            SchM_Exit_Port_EXCLUSIVE_AREA_01();
            WRITE_MSCRIO(u16Port_PinPad, SIUL2.MSCR_IO[u16Port_PinPad].R);/* polyspace RTE:NIV,IDP */
        }
    }
    // Direction changeability is NOT supported
    else
    {
        u8Port_PinDirError = (Std_ReturnType)E_NOT_OK;
    }

    return u8Port_PinDirError;
}
#endif

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif


#if (STD_ON == PORT_SET_PIN_MODE_API)

#if (defined  (RESOURCE_SUPPORT_EIOMUX))
/*****************************************************************************
**  Service Name     : Port_LLD_SetEioMux
**
**  Description      : The function will set the port pin mode of the referenced pin during runtime
**
**  Parameters (in)  : PinCfgRegIndex: Index of Register MSCR
**                     u8Port_PinMode: Value of IO_MODE + INPUT/OUTPUT for EIOMUX
**                     u32Port_MSCR_Mask: related to MSCR.ODC
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetEioMux \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_PinModeType,       AUTOMATIC) u8Port_IoModePre \
)
{
    /* Variable used to set EIOMUX PAD_MODE register */
    VAR(uint8, AUTOMATIC) u8Port_IoMode = 0U;

    SchM_Enter_Port_EXCLUSIVE_AREA_05();

    if((u8Port_IoModePre >= PORT_IN_IOMODE_1) && (u8Port_IoModePre < PORT_ONLY_INPUT_IOMODE))
    {
        u8Port_IoMode = u8Port_IoModePre;
    }
    else if((u8Port_IoModePre >= PORT_ONLY_INPUT_IOMODE) && (u8Port_IoModePre < PORT_ONLY_OUTPUT_IOMODE))
    {
        /* the minimum IO_MODE is 1 except GPIO mode */
        u8Port_IoMode = u8Port_IoModePre - PORT_ONLY_INPUT_IOMODE;
    }
    else if((u8Port_IoModePre >= PORT_ONLY_OUTPUT_IOMODE) && (u8Port_IoModePre < PORT_IN_OUT_IOMODE_END))
    {
        u8Port_IoMode = u8Port_IoModePre - PORT_ONLY_OUTPUT_IOMODE;
    }
    else /* GPIO or ADC_INPUT or MCD_LVDS*/
    {
    	/* check if need to set MCD LVDS register */
        switch(u16Port_PinCfgRegIndex)
        {
        	case (uint16)PAD_48:
        	case (uint16)PAD_49:
        	case (uint16)PAD_50:
        	case (uint16)PAD_51:
        		if(u8Port_IoModePre == PORT_MCD_LVDS_OUTPUT_IOMODE)
        		{
        			EIOMUX.PAD_MCD_LVDS_EN.R = 1;
        		}
        		else
        		{
        			EIOMUX.PAD_MCD_LVDS_EN.R = 0;
        		}
        		break;
        	default:
                /*do nothing*/
        		break;
        }

        u8Port_IoMode = 0;
    }

    EIOMUX.PAD_MODE[u16Port_PinCfgRegIndex].R = (uint32_t)u8Port_IoMode;/* polyspace RTE:OBAI */

    SchM_Exit_Port_EXCLUSIVE_AREA_05();
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
/*****************************************************************************
**  Service Name     : Port_LLD_SetPinMode_EIOMUX
**
**  Description      : The function will set the port pin mode of the referenced pin during runtime
**
**  Parameters (in)  : PinCfgRegIndex: Index of Register MSCR
**                     u8Port_PinMode: Value of IO_MODE + INPUT/OUTPUT for EIOMUX
**                     u32Port_MSCR_Mask: related to MSCR.ODC
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetPinMode_EIOMUX \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_PinModeType,       AUTOMATIC) u8Port_PinMode, \
	VAR(Port_RegValueType,      AUTOMATIC) u32Port_MSCR_Mask \
)
{
    // Variable used to clear and updated MSCR register
    VAR(uint32, AUTOMATIC) u32Port_LocalVar = (uint32)0UL;
    // Read the entire value of the MSCR register
    u32Port_LocalVar = SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R;/* polyspace RTE:OBAI */

	SchM_Enter_Port_EXCLUSIVE_AREA_06();

	if(PORT_ANALOG_INPUT_IOMODE == u8Port_PinMode)
	{
        // Set the Analog Pad Control (APC) bit in MSCR
        u32Port_LocalVar = SIUL2_MSCR_APC_U32;
	}
	else
	{
		if((u8Port_PinMode >= PORT_IN_IOMODE_1) && (u8Port_PinMode < PORT_ONLY_INPUT_IOMODE))
		{
	        // Clear MSCR.SSS bit field
	        u32Port_LocalVar &= ~SIUL2_MSCR_SSS_U32;
	        // Clear MSCR.OBE or MSCR.ODC bit field
	        u32Port_LocalVar &= ~SIUL2_MSCR_ODC_U32;
	        // Clear MSCR.APC bit field
	#ifndef PORT_NO_ANALOG_MODE
	        u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
	#endif
	        // Set the INPUT mode in MSCR
	        u32Port_LocalVar |=  SIUL2_MSCR_IBE_U32;
		}
		else if((u8Port_PinMode >= PORT_ONLY_INPUT_IOMODE) && (u8Port_PinMode < PORT_ONLY_OUTPUT_IOMODE))
		{
	        // Clear MSCR.IBE and MSCR.SSS bit fields
	        u32Port_LocalVar &= ~(SIUL2_MSCR_IBE_U32 | SIUL2_MSCR_SSS_U32);
	#ifndef PORT_NO_ANALOG_MODE
	        // Clear MSCR.APC bit field, if platform supports it
	        u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
	#endif
	        // Set the OUTPUT mode in MSCR
	        // For platforms having ODC SIUL2 support, the Port_AutoSar_Wrapper_SetPinMode() function will send through
	        // u32Port_MSCR_Mask parameter the value of the MSCR.ODC in configuration structure.
	        u32Port_LocalVar |= ((uint32)u32Port_MSCR_Mask);
		}
		else if((u8Port_PinMode >= PORT_ONLY_OUTPUT_IOMODE) && (u8Port_PinMode < PORT_IN_OUT_IOMODE_END))
		{
            // Clear the previous mode (MSCR.SSS)
            u32Port_LocalVar &= ~SIUL2_MSCR_SSS_U32;
#ifndef PORT_NO_ANALOG_MODE
            // Clear MSCR.APC bit, if platform supports it
            u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif
            // For platforms having ODC support, the MSCR.ODC bits should be set.
            // u32Port_MSCR_Mask parameter the value of the MSCR.ODC in configuration structure.
            u32Port_LocalVar |= ((uint32)u32Port_MSCR_Mask);
            u32Port_LocalVar |= ((uint32)SIUL2_MSCR_IBE_U32);
		}
        else
        {
            /*do nothing*/
        }
	}

	Port_LLD_SetEioMux(u16Port_PinCfgRegIndex, u8Port_PinMode);

	SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R = u32Port_LocalVar;

	SchM_Exit_Port_EXCLUSIVE_AREA_06();
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#elif (defined  (RESOURCE_SUPPORT_EIOMUX2))
/*****************************************************************************
**  Service Name     : Port_LLD_SetPinMode_EIOMUX
**
**  Description      : The function will set the port pin mode of the referenced pin during runtime
**
**  Parameters (in)  : PinCfgRegIndex: Index of Register MSCR
**                     u8Port_PinMode: Value of IO_MODE + INPUT/OUTPUT for EIOMUX
**                     u32Port_MSCR_Mask: related to MSCR.ODC
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetPinMode_EIOMUX2 \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PadNum, \
    VAR(Port_PinModeType,       AUTOMATIC) u32Port_PinMode \
)
{
    // Variable used to clear and updated MSCR register
    VAR(uint32, AUTOMATIC) u32MSCR_IO_Val = (uint32)0UL;
    VAR(uint32, AUTOMATIC) u32Padx_Val = (uint32)0UL;
    VAR(uint32, AUTOMATIC) u32ICR_Val = (uint32)0UL;
    VAR(uint32, AUTOMATIC) u32TempVal = (uint32)0UL;

    VAR(uint8,   AUTOMATIC) u8isAnMode = 0U;
    VAR(uint8,   AUTOMATIC) u8PortDir = 0U;
    VAR(uint8,   AUTOMATIC) u8FuncSel = 0U;
    VAR(uint16,   AUTOMATIC) u16MscrId = 0U;

    u8isAnMode = (uint8)((u32Port_PinMode & PORT_MODE_AN_MASK) >> 24U);
    u8PortDir =  (uint8)((u32Port_PinMode & PORT_MODE_DIR_INOUT_MASK) >> 26U);
    u8FuncSel =  (uint8)((u32Port_PinMode & PORT_MODE_SSS_MASK));
    u16MscrId = (uint16)((u32Port_PinMode & PORT_MODE_MSCR_MASK) >> 8U);

    if(((uint16)EIOMUX2_PAD_REG_NUM_MAX <= u16Port_PadNum) ||
      ((512U+(uint16)EIOMUX2_ISR_REG_NUM_MAX) <= u16MscrId))
    {
    	return;
    }

    // Read the entire value of the MSCR register
    u32MSCR_IO_Val = SIUL2.MSCR_IO[u16Port_PadNum].R;/* polyspace RTE:OBAI */
    u32Padx_Val = EIOMUX2.PAD[u16Port_PadNum].R;

	SchM_Enter_Port_EXCLUSIVE_AREA_06();

	if(1U == u8isAnMode)
	{
		/* disable ODC, enable IBE */
		u16MscrId = u16Port_PadNum;
		u32Padx_Val &= ~EIOMUX2_PADX_ODC_MASK_U32;
		u32Padx_Val |= (EIOMUX2_PADX_ODC_DISABLE_U32 | EIOMUX2_PADX_IBE_ON_U32);
	}
	else
	{
        if(3U == u8PortDir)
        {
        	/* Input_Output direction, like GPIO/I2C function */
        	/* Set Output ODC */
            if((uint16)EIOMUX2_PAD_REG_NUM_MAX > u16MscrId)
            {
            	u32TempVal = u32Padx_Val & EIOMUX2_PADX_ODC_MASK_U32;
            	/*if ODC is disable, set default ODC */
            	if((EIOMUX2_PADX_ODC_DISABLE_U32 == u32TempVal) || (EIOMUX2_PADX_ODC_OUT_BUF_DISABLE_U32 ==u32TempVal))
                {
            		if(0U == u8FuncSel)
            		{
            			/* GPIO */
                	    u32TempVal = EIOMUX2_PADX_ODC_PUSH_PULL_U32;
            		}
            		else
            		{
            			/* I2C, SENT */
            			u32TempVal = EIOMUX2_PADX_ODC_OPEN_DRAIN_U32;
            		}
                    /* set ODC to EIOMUX2.PAD register field */
                    u32Padx_Val &= ~EIOMUX2_PADX_ODC_MASK_U32;
                    u32Padx_Val |= u32TempVal;
                }
            	/* set output ISSS */
                u32Padx_Val &= ~EIOMUX2_PADX_ISSS_MASK_U32;
                u32Padx_Val |= (uint32)u8FuncSel;
            }

            /* enable IBE */
            u32Padx_Val |= EIOMUX2_PADX_IBE_ON_U32;
            /* Set Input SSS if necessary */
            if(((uint16)(512U+(uint16)EIOMUX2_ISR_REG_NUM_MAX) > u16MscrId) && (512U <= u16MscrId))
            {
            	/* set input ISS */
            	u16MscrId -= 512U;
            	u32ICR_Val = EIOMUX2.ICR[u16MscrId].R;
            	u32ICR_Val &= ~EIOMUX2_ISR_ISS_MASK_U32;
            	u32ICR_Val |= (uint32)u8FuncSel;
            	EIOMUX2.ICR[u16MscrId].R = u32ICR_Val;
            }
        }
        else if(1U == u8PortDir)
        {
        	/* Output direction */
        	/* We want to set u16Port_PadNum as output function */
        	/* disable IBE */
        	u32Padx_Val &= ~EIOMUX2_PADX_IBE_MASK_U32;
        	/* Set Output ODC */
        	u32TempVal = u32Padx_Val & EIOMUX2_PADX_ODC_MASK_U32;
        	/*if ODC is disable, set default ODC */
        	if((EIOMUX2_PADX_ODC_DISABLE_U32 == u32TempVal) || (EIOMUX2_PADX_ODC_OUT_BUF_DISABLE_U32 ==u32TempVal))
            {
        		if(0U == u8FuncSel)
        		{
        			/* GPIO */
            	    u32TempVal = EIOMUX2_PADX_ODC_PUSH_PULL_U32;
        		}
        		else
        		{
        			/* I2C */
        			u32TempVal = EIOMUX2_PADX_ODC_OPEN_DRAIN_U32;
        		}
                /* set ODC to EIOMUX2.PAD register field */
                u32Padx_Val &= ~EIOMUX2_PADX_ODC_MASK_U32;
                u32Padx_Val |= u32TempVal;
            }
        	/* set output ISSS */
            u32Padx_Val &= ~EIOMUX2_PADX_ISSS_MASK_U32;
            u32Padx_Val |= (uint32)u8FuncSel;
        }
        else
        {
            /* default Input direction */
        	/* enable IBE, close OBE */
        	u32Padx_Val |= (EIOMUX2_PADX_ODC_OUT_BUF_DISABLE_U32 | EIOMUX2_PADX_IBE_ON_U32);
        	/* set input select: ISS */
        	if(((uint16)(512U+(uint16)EIOMUX2_ISR_REG_NUM_MAX) > u16MscrId) && (512U <= u16MscrId))
            {
            	u16MscrId -= 512U;
            	u32ICR_Val = EIOMUX2.ICR[u16MscrId].R;
            	u32ICR_Val &= ~EIOMUX2_ISR_ISS_MASK_U32;
            	u32ICR_Val |= (uint32)u8FuncSel;
            	EIOMUX2.ICR[u16MscrId].R = u32ICR_Val;
            }
        }
	}

    EIOMUX2.PAD[u16Port_PadNum].R = u32Padx_Val;
	SIUL2.MSCR_IO[u16Port_PadNum].R = u32MSCR_IO_Val;

	SchM_Exit_Port_EXCLUSIVE_AREA_06();
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#else

/*****************************************************************************
**  Service Name     : Port_LLD_SetPinMode
**
**  Description      : The function will set the port pin mode of the referenced pin during runtime
**
**  Parameters (in)  : PinCfgRegIndex: Index of Register MSCR
**                     PinCfgRegValue: Value of Register MSCR
**                     u16InMuxRegIndex: Index of Register IMCR
**                     InMuxRegValue: Value of Register IMCR
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetPinMode \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_PinCfgRegValue, \
    VAR(uint16,                 AUTOMATIC) u16Port_InMuxRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_InMuxRegValue \
)
{
    // Variable used to clear and updated MSCR register
    VAR(uint32, AUTOMATIC) u32Port_LocalVar = (uint32)0UL;
    SchM_Enter_Port_EXCLUSIVE_AREA_02();

    // Read the entire value of the MSCR register
    u32Port_LocalVar = SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R; /* polyspace RTE:NIV */

    if (PORT_LLD_INPUT_ACTIVE_U32 == u32Port_PinCfgRegValue)
    {
        // Clear MSCR.SSS bit field
        u32Port_LocalVar &= ~SIUL2_MSCR_SSS_U32;
        // Clear MSCR.OBE or MSCR.ODC bit field
        u32Port_LocalVar &= ~SIUL2_MSCR_ODC_U32;
        // Clear MSCR.APC bit field
#ifndef PORT_NO_ANALOG_MODE
        u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif
        // Set the INPUT mode in MSCR
        u32Port_LocalVar |=  SIUL2_MSCR_IBE_U32;
    }
    else if (PORT_LLD_OUTPUT_ACTIVE_U32 == u32Port_PinCfgRegValue)
    {
        // Clear MSCR.IBE and MSCR.SSS bit fields
        u32Port_LocalVar &= ~(SIUL2_MSCR_IBE_U32 | SIUL2_MSCR_SSS_U32);
#ifndef PORT_NO_ANALOG_MODE
        // Clear MSCR.APC bit field, if platform supports it
        u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif
        // Set the OUTPUT mode in MSCR
        // For platforms having ODC SIUL2 support, the Port_AutoSar_Wrapper_SetPinMode() function will send through
        // InMuxRegValue parameter the value of the MSCR.ODC in configuration structure.
        u32Port_LocalVar |= ((uint32)u32Port_InMuxRegValue);
    }
    else
    {
#ifndef PORT_NO_ANALOG_MODE
        if (PORT_ANALOG_INPUT_MODE == u32Port_PinCfgRegValue)
        {
            // Set the Analog Pad Control (APC) bit in MSCR
            u32Port_LocalVar = SIUL2_MSCR_APC_U32;
        }
        else
#endif
        {
            // Clear the previous mode (MSCR.SSS)
            u32Port_LocalVar &= ~SIUL2_MSCR_SSS_U32;
#ifndef PORT_NO_ANALOG_MODE
            // Clear MSCR.APC bit, if platform supports it
            u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif

            // For platforms having ODC support, for modes PORT_ALTx and PORT_INOUTx the MSCR.ODC bits should also be set.
            // InMuxRegValue is a logic OR between MSCR.ODC and IMCR.SSS so apply a mask in order to get only the information
            // related to MSCR.ODC
            u32Port_LocalVar |= (((uint32)u32Port_InMuxRegValue) & SIUL2_MSCR_ODC_U32);
            // Set the proper mode in MSCR.SSS
            u32Port_LocalVar |= ((uint32)u32Port_PinCfgRegValue<<SIUL2_MSCR_SSS_OFFSET_U32);
        }
    }
    SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R = u32Port_LocalVar;

    if (NO_INPUTMUX_U16 != u16Port_InMuxRegIndex)
    {
        // Set the proper values in IMCR. For platforms having ODC support, InMuxRegValue is a logic OR between MSCR.ODC and IMCR.SSS
        // so apply a mask in order to get only the information related to IMCR.SSS */
        SIUL2.MSCR_MUX[(u16Port_InMuxRegIndex % 512U)].R = \
                                                    ((u32Port_InMuxRegValue & SIUL2_IMCR_SSS_U32) \
                                                    | SIUL2_IMCR_RESET_MASK_U32);
        // Set the MSCR/IBE bit
        u32Port_LocalVar = SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R;/* polyspace RTE:NIV */
        u32Port_LocalVar |= ((uint32)SIUL2_MSCR_IBE_U32);
        SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R = u32Port_LocalVar;
    }
    SchM_Exit_Port_EXCLUSIVE_AREA_02();
    WRITE_MSCRIO(u16Port_PinCfgRegIndex, SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R);/* polyspace RTE:NIV */
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#endif /* #if (defined  (RESOURCE_SUPPORT_EIOMUX)) */
#endif /* #if (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)

/*****************************************************************************
**  Service Name     : Port_LLD_SetGpioDirChangeability
**
**  Description      : The function will update the direction changeabilty for the pads whose mode is changed
**
**  Parameters (in)  : PadID: Pin ID number
**                     bStatus: The new value true or falsr for directuion changeability
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetGpioDirChangeability \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PadID, \
    VAR(boolean,                AUTOMATIC) bPort_Status \
)
{
    // Pin description variables
    VAR(uint16, AUTOMATIC) u16Port_PinDirFlagWord = 0;
    VAR(uint8, AUTOMATIC) u8Port_PinBitOffset     = 0;

    SchM_Enter_Port_EXCLUSIVE_AREA_03();

    // Bit offset of Pin index inside the pin description matrix
    u8Port_PinBitOffset    = (uint8)((uint8)u16Port_PadID & SIUL2_BIT_OFFSET_MASK_U8);
    u16Port_PinDirFlagWord = \
                    s_u16Port_Siul2_au16GPIODirChangeability[(uint8)((uint8)u16Port_PadID>>4)];
    if(u8Port_PinBitOffset <= 32U)/* polyspace RTE:UNR */
    {
        if ((boolean)TRUE == bPort_Status)
        {
            // Set the change direction flag
            u16Port_PinDirFlagWord |= (uint16)(1UL<<u8Port_PinBitOffset);
        }
        else
        {   // Reset the change direction flag
            u16Port_PinDirFlagWord &= (uint16)(~((uint16)(1UL<<u8Port_PinBitOffset)));
        }
    }

    s_u16Port_Siul2_au16GPIODirChangeability[(uint8)((uint8)u16Port_PadID>>4U)] = \
                                                                    u16Port_PinDirFlagWord;

    SchM_Exit_Port_EXCLUSIVE_AREA_03();
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)

/*****************************************************************************
**  Service Name     : Port_LLD_SetGpioPadOutput
**
**  Description      : The function will update the output for the pads whose mode is changed
**
**  Parameters (in)  : PinIndex: Pin ID number
**                     pConfigPtr: A pointer to the structure which contains initialization parameters
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetGpioPadOutput \
( \
    VAR    (Port_PinType,    AUTOMATIC                 ) u32Port_PinIndex, \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{

    VAR(uint16, AUTOMATIC) u16Port_PinPad \
    = (uint16)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin);/* polyspace RTE:IDP */
    VAR(uint8, AUTOMATIC) u8Port_LocalPDO \
            = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u8Port_PDO;

    // Set pin to High value
    if (PORT_PIN_LEVEL_HIGH_U8 == u8Port_LocalPDO)
    {
        SchM_Enter_Port_EXCLUSIVE_AREA_01();
        SIUL2.GPDO[u16Port_PinPad].R = (uint8)STD_HIGH;/* polyspace RTE:IDP,OBAI */
        SchM_Exit_Port_EXCLUSIVE_AREA_01();
    }
    // Set pin to Low value
    else if (PORT_PIN_LEVEL_LOW_U8 == u8Port_LocalPDO)
    {
        SchM_Enter_Port_EXCLUSIVE_AREA_02();
        SIUL2.GPDO[u16Port_PinPad].R = (uint8)STD_LOW;/* polyspace RTE:IDP,OBAI */
        SchM_Exit_Port_EXCLUSIVE_AREA_02();
    }
    else
    {
        // No action to be done
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
#endif

/*****************************************************************************
**  Service Name     : Port_LLD_RefreshPortDirection
**
**  Description      : This service shall refresh the direction of all configured ports to the configured
**                     direction. The PORT driver shall exclude from refreshing those port pins that are
**                     configured as pin direction changeable during runtime.
**
**  Parameters (in)  : numPins: Number of pins to be refreshed
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
FUNC (void, PORT_CODE) Port_LLD_EIOMUX2_RefreshPortDirection \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    VAR(uint16, AUTOMATIC) u16Port_NumPins = pPort_ConfigPtr->Port_UsedPin.u16Port_NumPins;/* polyspace RTE:IDP */
    /* Index of the port table */
    VAR(uint16, AUTOMATIC) u16Port_PinIndex = 0;
    VAR(uint16, AUTOMATIC) u16Port_PinPad = 0;
    VAR(uint8, AUTOMATIC) u8Port_ODC = 0U;

    /* Initialize All Configured Port Pins that aren't direction changable */
    u16Port_PinIndex = (uint16)0U;
    while( u16Port_PinIndex < u16Port_NumPins)
    {
        if ((boolean)FALSE \
                == pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].bPort_DC)
        {
            // Point to the Port Pin MSCR register address
            u16Port_PinPad = (uint16) \
                pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u16Port_SIUPin;

            SchM_Enter_Port_EXCLUSIVE_AREA_04();

            // Configures Port Pin as Output
            if ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_MSCR \
                                                                    & SIUL2_MSCR_ODC_U32) != 0U)
            {
                // Set MSCR.ODC bitfield to the value taken from configuration
                SchM_Enter_Port_EXCLUSIVE_AREA_03();
            	/* Disable IBE */
                EIOMUX2.PAD[u16Port_PinPad].R &= (~EIOMUX2_PADX_IBE_ON_U32);/* polyspace RTE:NIV,IDP,OBAI */
                /* Get ODC value taken from configuration */
                u8Port_ODC = (uint8)((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_ODC & SIUL2_MSCR_ODC_U32) \
                		     >> SIUL2_MSCR_ODC_OFFSET_U32);
                /* Set ODC */
                EIOMUX2.PAD[u16Port_PinPad].R |= (uint32)u8Port_ODC << EIOMUX2_PADX_ODC_OFFSET_U32;

                SchM_Exit_Port_EXCLUSIVE_AREA_03();
            }
            else
            {
                SchM_Enter_Port_EXCLUSIVE_AREA_04();
                EIOMUX2.PAD[u16Port_PinPad].R &= (~EIOMUX2_PADX_ODC_MASK_U32);/* polyspace RTE:NIV,IDP,OBAI */
                SchM_Exit_Port_EXCLUSIVE_AREA_04();
            }
            // Configures Port Pin as Input
            if ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_MSCR \
                                                                & SIUL2_MSCR_IBE_U32) != 0U)
            {
                SchM_Enter_Port_EXCLUSIVE_AREA_05();
                /* Disable ODC and enable IBE */
            	EIOMUX2.PAD[u16Port_PinPad].R &= ~EIOMUX2_PADX_ODC_MASK_U32;/* polyspace RTE:NIV,IDP,OBAI */
            	EIOMUX2.PAD[u16Port_PinPad].R |= EIOMUX2_PADX_IBE_ON_U32;/* polyspace RTE:NIV,IDP,OBAI */
                SchM_Exit_Port_EXCLUSIVE_AREA_05();
            }
            else
            {
                SchM_Enter_Port_EXCLUSIVE_AREA_06();
                EIOMUX2.PAD[u16Port_PinPad].R &= (~EIOMUX2_PADX_IBE_MASK_U32);/* polyspace RTE:NIV,IDP */
                SchM_Exit_Port_EXCLUSIVE_AREA_06();
            }
            SchM_Exit_Port_EXCLUSIVE_AREA_04();
            WRITE_EIOMUX2_PAD(u16Port_PinPad, EIOMUX2.PAD[u16Port_PinPad].R);/* polyspace RTE:NIV,IDP */
        }
        u16Port_PinIndex++;
    }
}
#else
FUNC (void, PORT_CODE) Port_LLD_RefreshPortDirection \
( \
    P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    VAR(uint16, AUTOMATIC) u16Port_NumPins = pPort_ConfigPtr->Port_UsedPin.u16Port_NumPins;/* polyspace RTE:IDP */
    // Index of the port table
    VAR(uint16, AUTOMATIC) u16Port_PinIndex = 0;
    VAR(uint16, AUTOMATIC) u16Port_PinPad = 0;

    // Initialize All Configured Port Pins that aren't direction changable
    u16Port_PinIndex = (uint16)0U;
    while( u16Port_PinIndex < u16Port_NumPins)
    {
        if ((boolean)FALSE \
                == pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].bPort_DC)
        {
            // Point to the Port Pin MSCR register address
            u16Port_PinPad = (uint16) \
                pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u16Port_SIUPin;

            SchM_Enter_Port_EXCLUSIVE_AREA_04();

            // Configures Port Pin as Output
            if ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_MSCR \
                                                                    & SIUL2_MSCR_ODC_U32) != 0U)
            {
                // Set MSCR.ODC bitfield to the value taken from configuration
                SchM_Enter_Port_EXCLUSIVE_AREA_03();
                SIUL2.MSCR_IO[u16Port_PinPad].R = (SIUL2.MSCR_IO[u16Port_PinPad].R /* polyspace RTE:NIV,IDP,OBAI */
                & (~SIUL2_MSCR_ODC_U32)) \
                | (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_ODC /* polyspace RTE:NIV */
                & SIUL2_MSCR_ODC_U32);
                SchM_Exit_Port_EXCLUSIVE_AREA_03();
            }
            else
            {
                SchM_Enter_Port_EXCLUSIVE_AREA_04();
                SIUL2.MSCR_IO[u16Port_PinPad].R &= (~SIUL2_MSCR_ODC_U32);/* polyspace RTE:NIV,IDP,OBAI */
                SchM_Exit_Port_EXCLUSIVE_AREA_04();
            }
            // Configures Port Pin as Input
            if ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_MSCR \
                                                                & SIUL2_MSCR_IBE_U32) != 0U)
            {
                SchM_Enter_Port_EXCLUSIVE_AREA_05();
                SIUL2.MSCR_IO[u16Port_PinPad].R |= SIUL2_MSCR_IBE_U32;/* polyspace RTE:NIV,IDP */
                SchM_Exit_Port_EXCLUSIVE_AREA_05();
            }
            else
            {
                SchM_Enter_Port_EXCLUSIVE_AREA_06();
                SIUL2.MSCR_IO[u16Port_PinPad].R &= (~SIUL2_MSCR_IBE_U32);/* polyspace RTE:NIV,IDP */
                SchM_Exit_Port_EXCLUSIVE_AREA_06();
            }
            SchM_Exit_Port_EXCLUSIVE_AREA_04();
            WRITE_MSCRIO(u16Port_PinPad, SIUL2.MSCR_IO[u16Port_PinPad].R);/* polyspace RTE:NIV,IDP */
        }
        u16Port_PinIndex++;
    }
}
#endif
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (PORT_SET_SIUL2_API == STD_ON)
extern callBackFunction eirq_cb[EIRQ_MAX_NUM];
/*
 * @brief Global Interrupt SIUL2 external interrupt 0 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ0 | EIRQ1 | EIRQ2 | EIRQ3 |
 * EIRQ4 | EIRQ5 | EIRQ6 | EIRQ7
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
void SIUL2_EIRQ_0_IRQHandler(void)
{
    uint32 eirq_n, tmp_disr0;

    tmp_disr0 = SIUL2.DISR0.R;

    for (eirq_n = EIRQ0; eirq_n <= EIRQ7; eirq_n++)
    {
        if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
        {
            SIUL2.DISR0.R = (1UL << eirq_n);
            if (eirq_cb[eirq_n] != NULL_PTR)
            {
                eirq_cb[eirq_n]();
            }
        }
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/*
 * @brief Global Interrupt SIUL2 external interrupt 1 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ8  | EIRQ9  | EIRQ10 | EIRQ11 |
 * EIRQ12 | EIRQ13 | EIRQ14 | EIRQ15
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
void SIUL2_EIRQ_1_IRQHandler(void)
{
    uint32 eirq_n, tmp_disr0;

    tmp_disr0 = SIUL2.DISR0.R;

    for (eirq_n = EIRQ8; eirq_n <= EIRQ15; eirq_n++)
    {
        if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
        {
            SIUL2.DISR0.R = (1UL << eirq_n);
            if (eirq_cb[eirq_n] != NULL_PTR)
            {
                eirq_cb[eirq_n]();
            }
        }
    }
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

/**
* file MemMap.h
*/
#endif

#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (uint8, PORT_CODE) Port_LLD_GetEioMux2 \
( \
    VAR(Port_PinModeType,       AUTOMATIC) u8Port_IoModePre \
)
{
    /* Variable used to set EIOMUX PAD_MODE register */
    VAR(uint8, AUTOMATIC) u8Port_IoMode = 0U;

    SchM_Enter_Port_EXCLUSIVE_AREA_05();

    if((u8Port_IoModePre >= PORT_IN_IOMODE_1) && (u8Port_IoModePre < PORT_ONLY_INPUT_IOMODE))
    {
        u8Port_IoMode = u8Port_IoModePre;
    }
    else if((u8Port_IoModePre >= PORT_ONLY_INPUT_IOMODE) && (u8Port_IoModePre < PORT_ONLY_OUTPUT_IOMODE))
    {
        /* the minimum IO_MODE is 1 except GPIO mode */
        u8Port_IoMode = u8Port_IoModePre - PORT_ONLY_INPUT_IOMODE;
    }
    else if((u8Port_IoModePre >= PORT_ONLY_OUTPUT_IOMODE) && (u8Port_IoModePre < PORT_IN_OUT_IOMODE_END))
    {
        u8Port_IoMode = u8Port_IoModePre - PORT_ONLY_OUTPUT_IOMODE;
    }
    else /* GPIO or ADC_INPUT or MCD_LVDS*/
    {
        u8Port_IoMode = 0;
    }

    SchM_Exit_Port_EXCLUSIVE_AREA_05();
    return u8Port_IoMode;
}
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* RESOURCE_SUPPORT_EIOMUX2 */

#ifdef __cplusplus
}
#endif
/** @} */
