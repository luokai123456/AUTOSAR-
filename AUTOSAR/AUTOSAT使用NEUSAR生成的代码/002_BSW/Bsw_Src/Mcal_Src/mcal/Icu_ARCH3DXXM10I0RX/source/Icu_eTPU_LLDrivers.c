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
*   @file    Icu_eTPU_LLDriver.c
*   @version 3.0.0 
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Icu MCAL driver.
*
*   @addtogroup Icu
*   @{
*/
/* PRQA S 3432, 0380, 2985 EOF */
/* PRQA S 2844, 4342, 0488, 0751 EOF */
/*====================================================================================================
                                        INCLUDE FILES
====================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Icu_eTPU_LLDrivers.h"
#if (defined(RESOURCE_SUPPORT_ETPU))

/*====================================================================================================
                                SOURCE FILE VERSION INFORMATION
====================================================================================================*/

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_ETPU_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_ETPU_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_ETPU_LLDRIVERS_MINOR_VER_C                   4
#define ICU_ETPU_LLDRIVERS_REVISION_VER_C                0

#define ICU_ETPU_LLDRIVERS_SW_MAJOR_VER_C                3
#define ICU_ETPU_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_ETPU_LLDRIVERS_SW_PATCH_VER_C                0

#if (ICU_ETPU_LLDRIVERS_VENDOR_ID_C != ICU_ETPU_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_ETPU_LLDRIVERS_MAJOR_VER_C != ICU_ETPU_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MAJOR_VERSION"
#endif
#if (ICU_ETPU_LLDRIVERS_MINOR_VER_C != ICU_ETPU_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_AR_RELEASE_MINOR_VERSION"
#endif
#if (ICU_ETPU_LLDRIVERS_REVISION_VER_C != ICU_ETPU_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_ETPU_LLDRIVERS_SW_MAJOR_VER_C != ICU_ETPU_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_ETPU_LLDRIVERS_SW_MINOR_VER_C != ICU_ETPU_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_ETPU_LLDRIVERS_SW_PATCH_VER_C != ICU_ETPU_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
static uint8 seTpu_ic_hsr[ETPU_INSTANCE_MAX][ETPU_PASSAGE_MAX];
#define ICU_STOP_SEC_VAR_NO_INIT
#include "Icu_MemMap.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Init
PURPOSE      : To initialize an eTPU channel to look for inputs.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
               parameter - ic config para
RETURNS NOTES: Error code if channel could not be initialized. Error code that
                 can be returned is: FS_ETPU_ERROR_MALLOC
WARNING      : *This function does not configure the pin only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
)
{
    P2VAR(uint32, ICU_VAR, ICU_APPL_CONST) pba;    /* parameter base address for 32&24 bit parameters */
    P2VAR(uint8,  ICU_VAR, ICU_APPL_CONST) pba8;    /* parameter base address for 8 bit parameters */

    /* Disable channel to assign function safely */
    ETPU_LLD_ChannelDisable(etpuGroup, channel);

    pba = ETPU_LLD_Malloc2(etpuGroup, channel, ETPU_IC_NUM_PARMS);
    if (pba == NULL_PTR )
    {
        return (ETPU_ERROR_MALLOC);
    }
    pba8 = (uint8 *)pba;

    /* write parameters to data memory */
    *(pba + ((ETPU_IC_MAXCOUNT_OFFSET - 1U)>>2U))  = parameter->max_count;/* polyspace RTE:IDP */
    *(pba8 + (ETPU_IC_FLAGS_OFFSET )) = parameter->edge;

    /* write FM (function mode) bits */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = parameter->mode;/* polyspace RTE:IDP,OBAI */

    /* write hsr to start channel running */
    if (parameter->timebase == ETPU_TCR1 )
    {
        eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_IC_INIT_TCR1;/* polyspace RTE:IDP */
        seTpu_ic_hsr[etpuGroup][channel] = (uint8)ETPU_IC_INIT_TCR1;/* polyspace RTE:OBAI */
    }
    else
    {
        eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_IC_INIT_TCR2;/* polyspace RTE:IDP */
        seTpu_ic_hsr[etpuGroup][channel] = (uint8)ETPU_IC_INIT_TCR2;/* polyspace RTE:OBAI */
    }
    /* write channel configuration register and enable channel */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = ((uint32)parameter->priority << 28U) + /* polyspace RTE:IDP */
                    (ETPU_IC_TABLE_SELECT << 24U) + \
                    (ETPU_IC_FUNCTION_NUMBER << 16U) + \
                    (((uint32)pba - eTPUInstance[etpuGroup].data_ram_start) >> 3U);

    return(0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Init_Ram
PURPOSE      : To initialize an eTPU channel to look for inputs and use
                parameter RAM as the reference.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
               parameter - ic config para
RETURNS NOTES: Error code if channel could not be initialized. Error code that
                 can be returned is: FS_ETPU_ERROR_MALLOC
WARNING      : *This function does not configure the pin only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init_Ram
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
)
{
    P2VAR(uint32, ICU_VAR, ICU_APPL_CONST) pba;    /* parameter base address for 32&24 bit parameters */
    P2VAR(uint8,  ICU_VAR, ICU_APPL_CONST) pba8;    /* parameter base address for 8 bit parameters */

    /* Disable channel to assign function safely */
    ETPU_LLD_ChannelDisable(etpuGroup, channel);

    pba = ETPU_LLD_Malloc2(etpuGroup, channel, ETPU_IC_NUM_PARMS);
    if (pba == NULL_PTR) 
    {
        return (ETPU_ERROR_MALLOC);
    }
    pba8 = (uint8 *)pba;

    /* write parameters to data memory */
    *(pba + ((ETPU_IC_MAXCOUNT_OFFSET - 1U)>>2U))  = parameter->max_count;/* polyspace RTE:IDP */
    *(pba8 + (ETPU_IC_FLAGS_OFFSET )) = parameter->edge;/* polyspace RTE:IDP */
    *(pba + ((ETPU_IC_ADDRESS_OFFSET - 1U)>>2U))  = (uint32)parameter->address;/* polyspace RTE:IDP */

    /* write FM (function mode) bits */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = parameter->mode;/* polyspace RTE:IDP,OBAI */

    /* write hsr to start channel running */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_IC_INIT_PRAM;/* polyspace RTE:IDP */
    seTpu_ic_hsr[etpuGroup][channel] = (uint8)ETPU_IC_INIT_PRAM;/* polyspace RTE:OBAI,IDP */

    /* write channel configuration register and enable channel */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = ((uint32)parameter->priority << 28U) + /* polyspace RTE:IDP */
                    (ETPU_IC_TABLE_SELECT << 24U) + \
                    (ETPU_IC_FUNCTION_NUMBER << 16U) + \
                    (((uint32)pba - eTPUInstance[etpuGroup].data_ram_start) >> 3U);

    return(0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Init_Link
PURPOSE      : To initialize an eTPU channel to look for inputs and generate
                links when done.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
               parameter - ic config para
RETURNS NOTES: Error code if channel could not be initialized. Error code that
                 can be returned is: FS_ETPU_ERROR_MALLOC
WARNING      : *This function does not configure the pin only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init_Link
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
)
{
    P2VAR(uint32, ICU_VAR, ICU_APPL_CONST) pba;    /* parameter base address for 32&24 bit parameters */
    P2VAR(uint8,  ICU_VAR, ICU_APPL_CONST) pba8;    /* parameter base address for 8 bit parameters */

    /* Disable channel to assign function safely */
    ETPU_LLD_ChannelDisable(etpuGroup, channel);

    pba = ETPU_LLD_Malloc2(etpuGroup, channel, ETPU_IC_NUM_PARMS);
    if (pba == NULL_PTR) 
    {
        return (ETPU_ERROR_MALLOC);
    }
    pba8 = (uint8 *)pba;

    /* write parameters to data memory */
    *(pba + ((ETPU_IC_MAXCOUNT_OFFSET - 1U)>>2U))  = parameter->max_count;/* polyspace RTE:IDP */
    *(pba8 + (ETPU_IC_FLAGS_OFFSET )) = parameter->edge;/* polyspace RTE:IDP */
    *(pba + ((ETPU_IC_LINK1_OFFSET)>>2U))  = parameter->link1;/* polyspace RTE:IDP */
    *(pba + ((ETPU_IC_LINK2_OFFSET)>>2U))  = parameter->link2;/* polyspace RTE:IDP */

    /* write FM (function mode) bits */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = (uint32)parameter->mode;/* polyspace RTE:IDP,OBAI */

    /* write hsr to start channel running */
    if (parameter->timebase == ETPU_TCR1 )
    {
        eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_IC_INIT_TCR1;/* polyspace RTE:IDP */
        seTpu_ic_hsr[etpuGroup][channel] = (uint8)ETPU_IC_INIT_TCR1;/* polyspace RTE:OBAI */
    }
    else
    {    
        eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_IC_INIT_TCR2;/* polyspace RTE:IDP */
        seTpu_ic_hsr[etpuGroup][channel] = (uint8)ETPU_IC_INIT_TCR2;/* polyspace RTE:OBAI */
    }
    /* write channel configuration register and enable channel */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = ((uint32)parameter->priority << 28U) + /* polyspace RTE:IDP */
                    (ETPU_IC_TABLE_SELECT << 24U) + \
                    (ETPU_IC_FUNCTION_NUMBER << 16U) + \
                    (((uint32)pba - eTPUInstance[etpuGroup].data_ram_start) >> 3U);

    return(0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Init_Link_Ram
PURPOSE      : To initialize an eTPU channel to look for inputs using a
                parameter RAM refernce and generating links when done.
INPUTS NOTES : This function has 8 parameters:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
               parameter - ic config para
RETURNS NOTES: Error code if channel could not be initialized. Error code that
                 can be returned is: FS_ETPU_ERROR_MALLOC
WARNING      : *This function does not configure the pin only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Init_Link_Ram
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    P2CONST(etpu_ic_param_t, ICU_VAR, ICU_APPL_CONST) parameter \
)
{
	P2VAR(uint32, ICU_VAR, ICU_APPL_CONST) pba;    /* parameter base address for 32&24 bit parameters */
	P2VAR(uint8,  ICU_VAR, ICU_APPL_CONST) pba8;    /* parameter base address for 8 bit parameters */

    /* Disable channel to assign function safely */
    ETPU_LLD_ChannelDisable(etpuGroup, channel);

    pba = ETPU_LLD_Malloc2(etpuGroup, channel, ETPU_IC_NUM_PARMS);
    if (pba == NULL_PTR) 
    {
        return (ETPU_ERROR_MALLOC);
    }
    pba8 = (uint8 *)pba;

    /* write parameters to data memory */
    *(pba + ((ETPU_IC_MAXCOUNT_OFFSET - 1U)>>2U))  = parameter->max_count;/* polyspace RTE:IDP */
    *(pba8 + (ETPU_IC_FLAGS_OFFSET )) = (uint8)parameter->edge;/* polyspace RTE:IDP */
    *(pba + ((ETPU_IC_ADDRESS_OFFSET - 1U)>>2U))  = (uint32)parameter->address;/* polyspace RTE:IDP */
    *(pba + ((ETPU_IC_LINK1_OFFSET - 1U)>>2U))  = parameter->link1;/* polyspace RTE:IDP */
    *(pba + ((ETPU_IC_LINK2_OFFSET - 1U)>>2U))  = parameter->link2;/* polyspace RTE:IDP */

    /* write FM (function mode) bits */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = (uint32)parameter->mode;/* polyspace RTE:IDP,OBAI */

    /* write hsr to start channel running */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_IC_INIT_PRAM;/* polyspace RTE:IDP */
    seTpu_ic_hsr[etpuGroup][channel] = (uint8)ETPU_IC_INIT_PRAM;/* polyspace RTE:OBAI */

    /* write channel configuration register and enable channel */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = ((uint32)parameter->priority << 28U) + /* polyspace RTE:IDP */
                   (ETPU_IC_TABLE_SELECT << 24U) + \
                   (ETPU_IC_FUNCTION_NUMBER << 16U) + \
                   (((uint32)pba - eTPUInstance[etpuGroup].data_ram_start) >> 3U);

    return(0);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ETPU_LLD_IC_DeInit
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel \
)
{
    ETPU_LLD_ChannelDisable(etpuGroup, channel);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ETPU_LLD_IC_SetTriggerMode
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    VAR(eTPU_EdgeTrigModeType, ICU_VAR) eEdge \
)
{
    uint32 *pba = ETPU_LLD_GetDataRam(etpuGroup, channel);
    uint8 *pba8 = (uint8*)pba;

    /* write parameters to data memory */
    *(pba8 + (ETPU_IC_FLAGS_OFFSET )) = (uint8)eEdge;/* polyspace RTE:IDP */
    /* write hsr to start channel running */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = seTpu_ic_hsr[etpuGroup][channel];/* polyspace RTE:OBAI,IDP */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(eTPU_EdgeTrigModeType, ICU_CODE) ETPU_LLD_IC_GetTriggerMode
( \
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel \
)
{
    uint32 *pba = ETPU_LLD_GetDataRam(etpuGroup, channel);
    uint8 *pba8 = (uint8*)pba;
    /* write parameters to data memory */
    return (eTPU_EdgeTrigModeType)*(pba8 + (ETPU_IC_FLAGS_OFFSET )) ;/* polyspace RTE:NIV,IDP */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ETPU_LLD_IC_SetIterCount
(
    VAR(uint8, ICU_VAR) etpuGroup, \
    VAR(uint8, ICU_VAR) channel, \
    VAR(uint32, ICU_VAR) count \
)
{
    uint32 *pba = ETPU_LLD_GetDataRam(etpuGroup, channel);

    *(pba + ((ETPU_IC_MAXCOUNT_OFFSET - 1U)>>2U))  = count;/* polyspace RTE:IDP */
    /* write hsr to start channel running */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = seTpu_ic_hsr[etpuGroup][channel];/* polyspace RTE:OBAI,IDP */
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Read_Trans_Count
PURPOSE      : To read the current number of transition counted.
INPUTS NOTES : This function has 1 parameter:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
RETURNS NOTES: The current number of transitions counted.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(sint32, ICU_CODE) ETPU_LLD_IC_Read_Trans_Count
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
)
{
    return ((int32_t)ETPU_LLD_GetChannelParameter24S(etpuGroup, channel, ETPU_IC_TRANSCOUNT_OFFSET));
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ETPU_LLD_IC_SetTransCount
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel,
    VAR(uint32,ICU_VAR) u32Value
)
{
    ETPU_LLD_SetChannelParameter24S(etpuGroup, channel, ETPU_IC_TRANSCOUNT_OFFSET, u32Value);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Read_Final_Time
PURPOSE      : To read the final tranistion refernce value.
INPUTS NOTES : This function has 1 parameter:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
RETURNS NOTES: The reference value of the final detected transition.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) ETPU_LLD_IC_Read_Final_Time
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
)
{
    return ((uint32)ETPU_LLD_GetChannelParameter24S(etpuGroup, channel, ETPU_IC_FINAL_OFFSET) & 0xFFFFFFUL);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ETPU_LLD_IC_SetFinalTime
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel,
    VAR(uint32,ICU_VAR) u32Value
)
{
    ETPU_LLD_SetChannelParameter24S(etpuGroup, channel, ETPU_IC_FINAL_OFFSET, u32Value);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_IC_Read_Last_Time
PURPOSE      : To read the last tranistion refernce value.
INPUTS NOTES : This function has 1 parameter:
               channel - This is the channel number.
                           0-31 for FS_ETPU_A and 64-95 for FS_ETPU_B.
RETURNS NOTES: The reference value of the last detected transition.
******************************************************************************/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) ETPU_LLD_IC_Read_Last_Time
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
)
{
    return ((uint32)ETPU_LLD_GetChannelParameter24S(etpuGroup, channel, ETPU_IC_LAST_OFFSET) & 0xFFFFFFUL);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) ETPU_LLD_IC_SetLastTime
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel,
    VAR(uint32,ICU_VAR) u32Value
)
{
    ETPU_LLD_SetChannelParameter24S(etpuGroup, channel, ETPU_IC_LAST_OFFSET, u32Value);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"


#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
FUNC(uint32, ICU_CODE) ETPU_LLD_IC_GetCountAddress
(
    VAR(uint8, ICU_VAR) etpuGroup,
    VAR(uint8, ICU_VAR) channel
)
{
    return ETPU_LLD_GetChannelParameter24SAddress(etpuGroup, channel, ETPU_IC_FINAL_OFFSET);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_ETPU)) */
#ifdef __cplusplus
}
#endif
