/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC 
*   Peripheral           : ICU
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*  
*****************************************************************************/

/**
*   @file    Icu_Irq.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 0380, 2053 EOF */
/* PRQA S 0316 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_Irq.h"
#include "Icu.h"
#include "Icu_AutoSar_Wrapper.h"
#include "Icu_eMIOS_Wrapper.h"
#include "Icu_eMIOS_HAL_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "Icu_eTPU_Wrapper.h"
#include "Icu_eTPU_HAL_Wrapper.h"
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Icu_Ccu7_Wrapper.h"
#endif /* (defined(RESOURCE_SUPPORT_CCU7_IP)) */

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_IRQ_VENDOR_ID_C                   176

#define ICU_IRQ_MAJOR_VER_C                   4
#define ICU_IRQ_MINOR_VER_C                   4
#define ICU_IRQ_REVISION_VER_C                0

#define ICU_IRQ_SW_MAJOR_VER_C                3
#define ICU_IRQ_SW_MINOR_VER_C                0
#define ICU_IRQ_SW_PATCH_VER_C                0

#if (ICU_IRQ_VENDOR_ID_C != ICU_IRQ_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_IRQ_MAJOR_VER_C != ICU_IRQ_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_IRQ_MINOR_VER_C != ICU_IRQ_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_IRQ_REVISION_VER_C != ICU_IRQ_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_IRQ_SW_MAJOR_VER_C != ICU_IRQ_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_IRQ_SW_MINOR_VER_C != ICU_IRQ_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_IRQ_SW_PATCH_VER_C != ICU_IRQ_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))	
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) ICU_GTM_Callback_From_IRQ
( \
    VAR(uint8, AUTOMATIC) u8Icu_ModuleId, \
    VAR(uint8, AUTOMATIC) u8Icu_ChannelId \
)
{
	(void)u8Icu_ModuleId;
	(void)u8Icu_ChannelId;
    /* to do in Icu_Gtm_HAL_Wrapper.c file */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) ICU_eMIOS_Callback_From_IRQ
( \
    VAR(uint8, AUTOMATIC) u8Icu_ModuleId, \
    VAR(uint8, AUTOMATIC) u8Icu_ChannelId \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) nIcu_Instance = \
        Icu_eMios_Wrapper_GetInstance(u8Icu_ModuleId, u8Icu_ChannelId);

    if (nIcu_Instance != (Icu_ChannelType)ICU_INVALID_INSTANCE)
    {
        eMios_Channel_ProcessCommonIrq(u8Icu_ModuleId, u8Icu_ChannelId);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void,ICU_CODE) ICU_eTPU_Callback_From_IRQ
( \
    VAR(uint8, AUTOMATIC) u8Icu_ModuleId, \
    VAR(uint8, AUTOMATIC) u8Icu_ChannelId \
)
{
    VAR(Icu_ChannelType, AUTOMATIC) nIcu_Instance = \
        Icu_eTpu_Wrapper_GetInstance(u8Icu_ModuleId, u8Icu_ChannelId);

    if (nIcu_Instance != (Icu_ChannelType)ICU_INVALID_INSTANCE)
    {
        eTpu_Channel_ProcessCommonIrq(u8Icu_ModuleId, u8Icu_ChannelId);
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /*  (defined(RESOURCE_SUPPORT_ETPU)) */

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ICU_TimeStamp_Callback_From_DMA
( \
    P2CONST(void,             AUTOMATIC, ICU_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
)
{
	(void)mappedChannel;
    if (status == EDMA_CHN_STATUS_NORMAL)
    {
        Icu_Autosar_Wrapper_TimestampDmaProcess(*(const Icu_ChannelType*)parameter);/* polyspace RTE:NIV,IDP */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ICU_SingalMeasurement_Callback_From_DMA
( \
	P2CONST(void,             AUTOMATIC, ICU_CODE) parameter, \
    VAR(eDMAChnStatusType,  AUTOMATIC) status, \
    VAR(uint8,              AUTOMATIC) mappedChannel \
)
{
	(void)mappedChannel;
    if (status == EDMA_CHN_STATUS_NORMAL)
    {
        Icu_Autosar_Wrapper_SignalMeasurementDmaProcess(*(const Icu_ChannelType*)parameter);/* polyspace RTE:NIV,IDP */
    }
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"



