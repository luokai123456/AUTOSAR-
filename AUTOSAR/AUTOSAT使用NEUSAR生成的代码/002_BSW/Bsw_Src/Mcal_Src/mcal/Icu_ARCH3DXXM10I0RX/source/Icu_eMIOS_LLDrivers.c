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
*   @file    Icu_eMIOS_LLDrivers.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 0380 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#include "Icu_eMIOS_LLDrivers.h"
#include "eMIOS_HAL_Irq.h"

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_EMIOS_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_EMIOS_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_EMIOS_LLDRIVERS_MINOR_VER_C                   4
#define ICU_EMIOS_LLDRIVERS_REVISION_VER_C                0

#define ICU_EMIOS_LLDRIVERS_SW_MAJOR_VER_C                3
#define ICU_EMIOS_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_EMIOS_LLDRIVERS_SW_PATCH_VER_C                0

#if (ICU_EMIOS_LLDRIVERS_VENDOR_ID_C != ICU_EMIOS_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_EMIOS_LLDRIVERS_MAJOR_VER_C != ICU_EMIOS_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_EMIOS_LLDRIVERS_MINOR_VER_C != ICU_EMIOS_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_EMIOS_LLDRIVERS_REVISION_VER_C != ICU_EMIOS_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_EMIOS_LLDRIVERS_SW_MAJOR_VER_C != ICU_EMIOS_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_EMIOS_LLDRIVERS_SW_MINOR_VER_C != ICU_EMIOS_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_EMIOS_LLDRIVERS_SW_PATCH_VER_C != ICU_EMIOS_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_Init
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    CONST(eMIOS_IC_ParamType, ICU_VAR) *ParamPtr \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(ParamPtr != NULL);

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;

    /* GPIO mode used reset eMIOS module */
    eMIOS_UC_Cn_SetMode(emiosIndex, ChanNum, (uint8_t)EMIOS_UC_MODE_GPIO_INPUT);
    /* eMIOS IC mode Initialization */
    eMIOS_LLD_UC_DeInitChannel(emiosIndex, ChanNum);

    eMIOS_UC_Cn_SetBSL(emiosIndex, ChanNum, (uint8)ParamPtr->timebase);
    eMIOS_UC_Cn_SetIF(emiosIndex, ChanNum, (uint8)ParamPtr->filter);
    eMIOS_UC_Cn_SetFCK(emiosIndex, ChanNum, (uint8)EMIOS_C_FCK_PRESCALED_CLK);
    eMIOS_UC_Cn_SetUCPREN(emiosIndex, ChanNum, TRUE);
    /* Set Freeze off */
    eMIOS_UC_Cn_SetFREN(emiosIndex, ChanNum, FALSE);
    /* Clear flag */
    eMIOS_LLD_UC_ClearFlag(emiosIndex, ChanNum);
    /* Disable interrupt */
    eMIOS_UC_Cn_SetFEN(emiosIndex, ChanNum, (boolean)FALSE);
    /* Set UC Prescaler */
    eMIOS_UC_Cn_SetUCPRE(emiosIndex, ChanNum, (uint8)ParamPtr->ucPrescaler);

    return ret;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_GetLastMeasurement
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    VAR(uint32,  ICU_VAR) *value \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(value != NULL);

    VAR(uint8, AUTOMATIC) counterBus;
    VAR(uint8, AUTOMATIC) temp;
    VAR(uint8, AUTOMATIC) busSelect;

    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;

    /* Get mode of operation of the Unified Channel */
    temp = eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum);

    switch(temp)
    {
    case (uint8)EMIOS_UC_MODE_SAIC:
    {
        *value = (uint32)eMIOS_UC_An_GetValue(emiosIndex, ChanNum);
        break;
    }
    case (uint8)EMIOS_UC_MODE_IPM:
    case (uint8)EMIOS_UC_MODE_IPWM:
    case (uint8)EMIOS_UC_MODE_PEA_CONTIN:
    case (uint8)EMIOS_UC_MODE_PEA_SINGLE:
    {
        VAR(uint32, AUTOMATIC) A = (uint32)eMIOS_UC_An_GetValue(emiosIndex, ChanNum);
        VAR(uint32, AUTOMATIC) B = (uint32)eMIOS_UC_Bn_GetValue(emiosIndex, ChanNum);

        /* Normal Case */
        if (B <= A)
        {
            *value = A - B;
        }
        else
        {
            /* Get bus select */
            busSelect = eMIOS_UC_Cn_GetBSL(emiosIndex, ChanNum);

            switch (busSelect)
            {
                case (uint8)EMIOS_COUNTER_BUS_A:
                    counterBus = (uint8)EMIOS_CNT_BUSA_DRIVEN_CHANNEL;
                    break;
                case (uint8)EMIOS_COUNTER_BUS_BCDE:
                    counterBus = (uint8)(ChanNum & 0xF8U);
                    break;
                default:
                    counterBus = ChanNum;
                    break;
            }

            if (counterBus != ChanNum)
            {
                *value = (eMIOS_UC_An_GetValue(emiosIndex, counterBus) - B) + A;
            }
            else
            {
                *value = (EMIOS_MC_CNT_MAX - B) + A;
            }
        }
        break;
    }
    case (uint8)EMIOS_UC_MODE_PEC_CONTIN:
    case (uint8)EMIOS_UC_MODE_PEC_SINGLE:
    {
        *value = eMIOS_UC_CNTn_GetValue(emiosIndex, ChanNum);
        break;
    }
    case (uint8)EMIOS_UC_MODE_WPTA:
    {
        *value = eMIOS_UC_ALTAn_GetValue(emiosIndex, ChanNum);
        break;
    }
    default:
    {
        ret = STATUS_ERROR;
	break;
    }
    }
    return ret;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_PEA_SingleTrigger
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    VAR(uint32,  ICU_VAR) count \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum) == (uint8)EMIOS_UC_MODE_PEA_SINGLE);

    eMIOS_UC_An_SetValue(emiosIndex, ChanNum, count);

    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(status_t, ICU_CODE) eMIOS_LLD_IC_PEC_SingleTrigger
( \
    CONST(uint8, ICU_VAR) emiosIndex, \
    CONST(uint8, ICU_VAR) ChanNum, \
    VAR(uint32,  ICU_VAR) endtime, \
    VAR(uint32,  ICU_VAR) starttime \
)
{
    EMIOS_DEV_ERR(eMIOS_DevError_Instance(emiosIndex));
    EMIOS_DEV_ERR(eMIOS_DevError_ChanNum(ChanNum));
    EMIOS_DEV_ERR(eMIOS_UC_Cn_GetMode(emiosIndex, ChanNum) == (uint8)EMIOS_UC_MODE_PEC_SINGLE);

    eMIOS_UC_Bn_SetValue(emiosIndex, ChanNum, endtime);

    eMIOS_UC_An_SetValue(emiosIndex, ChanNum, starttime);

    return STATUS_SUCCESS;
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
