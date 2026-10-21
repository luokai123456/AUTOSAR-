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
*   @file    Port_LLDrivers.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/
/* PRQA S 1535 EOF */
#ifndef PORT_LLDRIVER_H
#define PORT_LLDRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Port_Cfg.h"

#include "Port_Types.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define PORT_H_SIUL2_VENDOR_ID                     176
#define PORT_H_SIUL2_AR_REL_MAJOR_VER              4
#define PORT_H_SIUL2_AR_REL_MINOR_VER              4
#define PORT_H_SIUL2_AR_REL_REV_VER                0
#define PORT_H_SIUL2_SW_MAJOR_VERSION              3
#define PORT_H_SIUL2_SW_MINOR_VERSION              0
#define PORT_H_SIUL2_SW_PATCH_VERSION              0


/* ============================================FILE VERSION CHECKS=================================== */

#if (PORT_H_SIUL2_VENDOR_ID != PORT_H_VENDOR_ID_CFG)
    #error "NON-MATCHED DATA : PORT_H_VENDOR_ID_CFG"
#endif

#if (PORT_H_SIUL2_AR_REL_MAJOR_VER != PORT_H_AR_RELEASE_MAJOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_MAJOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_AR_REL_MINOR_VER != PORT_H_AR_RELEASE_MINOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_MINOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_SW_MAJOR_VERSION != PORT_H_SW_MAJOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_MAJOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_SW_MINOR_VERSION != PORT_H_SW_MINOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_MINOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_SW_PATCH_VERSION != PORT_H_SW_PATCH_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_PATCH_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_VENDOR_ID != PORT_H_SIUL2_VENDOR_ID_TYPES)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_VENDOR_ID_TYPES"
#endif

#if (PORT_H_SIUL2_AR_REL_MAJOR_VER != PORT_H_SIUL2_AR_REL_MAJ_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_MAJ_VER_TY"
#endif

#if (PORT_H_SIUL2_AR_REL_MINOR_VER != PORT_H_SIUL2_AR_REL_MIN_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_MIN_VER_TY"
#endif

#if (PORT_H_SIUL2_AR_REL_REV_VER != PORT_H_SIUL2_AR_REL_REV_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_REV_VER_TY"
#endif

#if (PORT_H_SIUL2_SW_MAJOR_VERSION != PORT_H_SIUL2_SW_MAJOR_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_MAJOR_VER_TY"
#endif

#if (PORT_H_SIUL2_SW_MINOR_VERSION != PORT_H_SIUL2_SW_MINOR_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_MINOR_VER_TY"
#endif

#if (PORT_H_SIUL2_SW_PATCH_VERSION != PORT_H_SIUL2_SW_PATCH_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_PATCH_VER_TY"
#endif

/* =============================================CONSTANTS============================================ */

#define PORT_LLD_INPUT_ACTIVE_U32             ((uint32)0xFFFFFFFFUL)
#define PORT_LLD_OUTPUT_ACTIVE_U32            ((uint32)0xFFFFFFFEUL)

#define PORT_LLD_INMUX_UNUSE_PATTEN_U32     ((uint32)0xFFFFFFFFUL)

#if (defined  (RESOURCE_SUPPORT_EIOMUX))
/* =========================================DEFINES AND MACROS======================================= */
/* PAD enable analog function */
#define EIOMUX_PAD_32_ANA_EN_MASK       0x00000001UL
#define EIOMUX_PAD_38_ANA_EN_MASK       0x00000002UL
#define EIOMUX_PAD_60_ANA_EN_MASK       0x00000004UL
#define EIOMUX_PAD_64_ANA_EN_MASK       0x00000008UL
#define EIOMUX_PAD_66_ANA_EN_MASK       0x00000010UL
#define EIOMUX_PAD_68_ANA_EN_MASK       0x00000020UL
#define EIOMUX_PAD_77_ANA_EN_MASK       0x00000040UL
#define EIOMUX_PAD_85_ANA_EN_MASK       0x00000080UL
#define EIOMUX_PAD_96_ANA_EN_MASK       0x00000100UL
#define EIOMUX_PAD_103_ANA_EN_MASK      0x00000200UL
#define EIOMUX_PAD_104_ANA_EN_MASK      0x00000400UL
#define EIOMUX_PAD_113_ANA_EN_MASK      0x00000800UL
#define EIOMUX_PAD_125_ANA_EN_MASK      0x00001000UL
#define EIOMUX_PAD_130_ANA_EN_MASK      0x00002000UL
#define EIOMUX_PAD_133_ANA_EN_MASK      0x00004000UL
#define EIOMUX_PAD_136_ANA_EN_MASK      0x00008000UL
#define EIOMUX_PAD_166_ANA_EN_MASK      0x00010000UL
#define EIOMUX_PAD_167_ANA_EN_MASK      0x00020000UL
#define EIOMUX_PAD_168_ANA_EN_MASK      0x00040000UL
#define EIOMUX_PAD_176_ANA_EN_MASK      0x00080000UL
#define EIOMUX_PAD_185_ANA_EN_MASK      0x00100000UL
#define EIOMUX_PAD_202_ANA_EN_MASK      0x00200000UL
#define EIOMUX_PAD_237_ANA_EN_MASK      0x00400000UL
#define EIOMUX_PAD_254_ANA_EN_MASK      0x00800000UL
/* ==============================================ENUMS=============================================== */
typedef enum
{
	PAD_48 = 48U,
	PAD_49 = 49U,
	PAD_50 = 50U,
	PAD_51 = 51U
}ePadNumber;
#endif

/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */


/* ====================================GLOBAL VARIABLE DECLARATIONS================================== */


/* ========================================FUNCTION PROTOTYPES======================================= */




#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_Init \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (defined  (RESOURCE_SUPPORT_EIOMUX))
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetEioMux \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_PinModeType,       AUTOMATIC) u8Port_IoModePre \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (uint8, PORT_CODE) Port_LLD_GetEioMux2 \
( \
    VAR(Port_PinModeType,       AUTOMATIC) u8Port_IoModePre \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
FUNC (Std_ReturnType, PORT_CODE) Port_LLD_EIOMUX2_SetPinDirection \
( \
    VAR    (Port_PinType,          AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) ePort_Direction, \
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#else
FUNC (Std_ReturnType, PORT_CODE) Port_LLD_SetPinDirection \
( \
    VAR    (Port_PinType,          AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) ePort_Direction, \
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#endif /* #if (defined  (RESOURCE_SUPPORT_EIOMUX2)) */
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* #if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

#if (defined  (RESOURCE_SUPPORT_EIOMUX))
FUNC (void, PORT_CODE) Port_LLD_SetPinMode_EIOMUX \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_PinModeType,       AUTOMATIC) u8Port_PinMode, \
	VAR(Port_RegValueType,      AUTOMATIC) u32Port_MSCR_Mask \
);

#elif (defined  (RESOURCE_SUPPORT_EIOMUX2))
FUNC (void, PORT_CODE) Port_LLD_SetPinMode_EIOMUX2 \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PadNum, \
    VAR(Port_PinModeType,       AUTOMATIC) u32Port_PinMode \
);
#else
FUNC (void, PORT_CODE) Port_LLD_SetPinMode \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_PinCfgRegValue, \
    VAR(uint16,                 AUTOMATIC) u16Port_InMuxRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_InMuxRegValue \
);
#endif /* #if (defined  (RESOURCE_SUPPORT_EIOMUX)) */

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetGpioDirChangeability \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PadID, \
    VAR(boolean,                AUTOMATIC) bPort_Status \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
FUNC (void, PORT_CODE) Port_LLD_SetGpioPadOutput \
( \
    VAR    (Port_PinType,    AUTOMATIC                 ) u32Port_PinIndex, \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
#endif


#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
#if (defined  (RESOURCE_SUPPORT_EIOMUX2))
FUNC (void, PORT_CODE) Port_LLD_EIOMUX2_RefreshPortDirection \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#else
FUNC (void, PORT_CODE) Port_LLD_RefreshPortDirection \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#endif/* #if (defined  (RESOURCE_SUPPORT_EIOMUX)) */
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if (PORT_SET_SIUL2_API == STD_ON)
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
void SIUL2_EIRQ_0_IRQHandler(void);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
void SIUL2_EIRQ_1_IRQHandler(void);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#if (defined (RESOURCE_SUPPORT_SIUL_IP))
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
void SIUL2_EIRQ_2_IRQHandler(void);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"
#endif
#endif




#ifdef __cplusplus
}
#endif
/* PORT_LLDRIVER_H */
#endif
/** @} */
