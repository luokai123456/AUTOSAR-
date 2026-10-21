/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
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
*   @file    sPwm_LLDrivers.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of sPwm MCAL driver.
*
*   @addtogroup sPwm
*   @{
*/
/* PRQA S 3432 EOF */
/* PRQA S 2844, 0488, 0751 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "eTPU_LLDrivers.h"         /* PRQA S 0380 */
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "EBPPA_LLDrivers.h"        /* eTPU PPA API */
#include "SchM_eTPU.h"
/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define EBPPA_LLDRIVERS_VENDOR_ID_C                   176

#define EBPPA_LLDRIVERS_MAJOR_VER_C                   4
#define EBPPA_LLDRIVERS_MINOR_VER_C                   4
#define EBPPA_LLDRIVERS_REVISION_VER_C                0

#define EBPPA_LLDRIVERS_SW_MAJOR_VER_C                3
#define EBPPA_LLDRIVERS_SW_MINOR_VER_C                0
#define EBPPA_LLDRIVERS_SW_PATCH_VER_C                0

#if (EBPPA_LLDRIVERS_VENDOR_ID_C != EBPPA_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_VENDOR_ID_C"
#endif

/* Check if current file and EBPPA header file are of the same Autosar version */
#if (EBPPA_LLDRIVERS_MAJOR_VER_C != EBPPA_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_MAJOR_VER_C"
#endif
#if (EBPPA_LLDRIVERS_MINOR_VER_C != EBPPA_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_MINOR_VER_C"
#endif
#if (EBPPA_LLDRIVERS_REVISION_VER_C != EBPPA_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_REVISION_VER_C"
#endif

/* Check if current file and EBPPA header file are of the same Software version */
#if (EBPPA_LLDRIVERS_SW_MAJOR_VER_C != EBPPA_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_SW_MAJOR_VER_C"
#endif
#if (EBPPA_LLDRIVERS_SW_MINOR_VER_C != EBPPA_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_SW_MINOR_VER_C"
#endif
#if (EBPPA_LLDRIVERS_SW_PATCH_VER_C != EBPPA_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : EBPPA_LLDRIVERS_SW_PATCH_VER_C"
#endif

#if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
/***************************************************************************
FUNCTION     : ETPU_LLD_EBPPA_Init
PURPOSE      : To initialize an eTPU channel to measure period and pulse timing data.
INPUTS NOTES : This function has 6 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
              priority - This is the priority to assign to the channel.
                         This parameter should be assigned a value of:
                         FS_ETPU_PRIORITY_HIGH, FS_ETPU_PRIORITY_MIDDLE or
                         FS_ETPU_PRIORITY_LOW.
              timebase - This is the timer to use as a reference for the EBPPA
                         function. This parameter should be assigned to a 
                         value of: ETPU_EBPPA_INIT_TCR1 or
                                   ETPU_EBPPA_INIT_TCR2.
                  mode - This is the mode to use for EBPPA measurements. This 
                         parameter should be assigned a value of:
                         ETPU_EBPPA_LOW_PULSE,
                         ETPU_EBPPA_HIGH_PULSE,
             max_count - This is the number of periods and pulses that are 
                         accumulated before the measurement restarts. This
                         parameter should be assigned a value in the range
                         0 to 2^23. A value of zero or one results in the 
                         accumulation of one period and pulse width.
           sample_time - Defines the rate at which the measurement is updated 
                         in the absence of an edge.
RETURNS NOTES: Error code is channel could not be initialized. Error code that
                 can be returned are:
                    ETPU_ERROR_MALLOC
WARNING      : *This function does not configure the pin, only the eTPU. In a
                  system a pin may need to be configured to select the eTPU.
******************************************************************************/

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, EBPPA_CODE) ETPU_LLD_EBPPA_Init \
(
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_priority, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_timebase, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_mode, \
	VAR(uint32, EBPPA_VAR) u8Ebppa_MaxCount, \
	VAR(uint32, EBPPA_VAR) u8Ebppa_SampleTime
)
{
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA) p32Ebppa_BsaeAdd;
	P2VAR(uint8, ATUPMATIC, EBPPA_APPL_DATA) p8Ebppa_BsaeAdd;
	VAR(uint8, EBPPA_VAR) u8Ebppa_eRet = 0U;
    eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPR = 0U;/* polyspace RTE:OBAI,IDP */
    SchM_Enter_eTPU_EXCLUSIVE_AREA_03();
    /*only get parameter RAM if the channel has not been used before */
    if (eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPBA == (uint32)0UL )/* polyspace RTE:NIV,IDP */
    {
        /* allocate parameter RAM */
    	p32Ebppa_BsaeAdd = ETPU_LLD_Malloc_32(u8Ebppa_EtpuGroup, ETPU_EBPPA_NUM_PARMS);
        if (p32Ebppa_BsaeAdd == NULL_PTR)
        {
        	u8Ebppa_eRet = ETPU_ERROR_MALLOC;
        }
    }
    else /*set pba to what is in the CR register*/
    {
    	p32Ebppa_BsaeAdd = (uint32*)(eTPUInstance[u8Ebppa_EtpuGroup].data_ram_start \
    			           + ((uint32)eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPBA << 3U));
    }
    p8Ebppa_BsaeAdd = (uint8 *) p32Ebppa_BsaeAdd;

    if(p32Ebppa_BsaeAdd != NULL_PTR)
    {
        /* write relevant function parameters */
        *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_ACCUM_PULSE_OFFSET >> 2U)) = 0U;/* polyspace RTE:IDP */
        *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_ACCUM_PERIOD_OFFSET>> 2U)) = 0U;/* polyspace RTE:IDP */
        *(p32Ebppa_BsaeAdd + ((ETPU_EBPPA_PERIOD_COUNT_OFFSET - 1U)>>2U))  =  0U;/* polyspace RTE:IDP */
        *(p32Ebppa_BsaeAdd + ((ETPU_EBPPA_SAMPLE_TIME_OFFSET - 1U)>>2U))  =  u8Ebppa_SampleTime;/* polyspace RTE:IDP */
        *(p32Ebppa_BsaeAdd + ((ETPU_EBPPA_MAX_COUNT_OFFSET - 1U)>>2U))  =  u8Ebppa_MaxCount;/* polyspace RTE:IDP */
        *(p8Ebppa_BsaeAdd + ETPU_EBPPA_STAT_ACC_OFFSET )  =  0U;
    }
    SchM_Exit_eTPU_EXCLUSIVE_AREA_03();
    /* function mode, controls pulse measurement type and edge-to-edge period measurement */
    eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].SCR.R = (u8Ebppa_mode);/* polyspace RTE:IDP */

    /* write hsr */
    eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].HSRR.R = u8Ebppa_timebase;/* polyspace RTE:IDP */

    /*write chan config register */
    eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.R =/* polyspace RTE:IDP */
				((uint32)u8Ebppa_priority << 28U) + ((uint32)ETPU_EBPPA_TABLE_SELECT << 24U) \
				+ (((uint32)ETPU_EBPPA_FUNCTION_NUMBER << 16U)) + (((uint32)p32Ebppa_BsaeAdd \
				- eTPUInstance[u8Ebppa_EtpuGroup].data_ram_start) >> 3U);

	return u8Ebppa_eRet;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_EBPPA_Get_Accumulation
PURPOSE      : This function call returns the status of the last measurement,
               and passes back the last accumulated pulse width and period data, 
               in counts of the selected timebase used to initialize 
               the function: either TCR1 or TCR2
INPUTS NOTES : This function has 3 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               period_result - A pointer to where the EBPPA period result will be stored.
                        Can be NULL if user doesn't want this parameter.
               pulse_result - A pointer to where the EBPPA pulse result will be stored.
                        Can be NULL if user doesn't want this parameter.

RETURNS NOTES: returns status; if status is non zero the result has overflowed
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_Get_Accumulation \
(
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodResult, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PulseResult
)
{
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA) p32Ebppa_BsaeAdd;
	P2VAR(uint8, ATUPMATIC, EBPPA_APPL_DATA) p8Ebppa_BsaeAdd;
	VAR(uint8, EBPPA_VAR) u8Ebppa_StatusAcc = 0U;


    p32Ebppa_BsaeAdd = (uint32*)(eTPUInstance[u8Ebppa_EtpuGroup].data_ram_start /* polyspace RTE:OBAI */
    		           + ((uint32)eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPBA << 3U));/* polyspace RTE:OBAI,NIV,IDP */
    p8Ebppa_BsaeAdd = (uint8 *) p32Ebppa_BsaeAdd;

    if (pEbppa_PeriodResult != NULL_PTR)
    {
        *pEbppa_PeriodResult = *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_RESULT_PERIOD_OFFSET >> 2U));/* polyspace RTE:NIV,IDP */
        *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_RESULT_PERIOD_OFFSET >> 2U)) = 0x0U;
    }
    if (pEbppa_PulseResult != NULL_PTR)
    {
        *pEbppa_PulseResult = *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_RESULT_PULSE_OFFSET >> 2U));/* polyspace RTE:NIV,IDP */
        *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_RESULT_PULSE_OFFSET >> 2U)) = 0x0U;
        u8Ebppa_StatusAcc = *(p8Ebppa_BsaeAdd + ETPU_EBPPA_STATUS_OFFSET);/* polyspace RTE:NIV,IDP */
    }

    return u8Ebppa_StatusAcc;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/******************************************************************************
FUNCTION     : ETPU_LLD_EBPPA_Get_Immediate
PURPOSE      : This function call returns the status of the current measurement,
               and passes back the current accumulated pulse widths and 
               periods, in counts of the selected timebase used to initialize 
               the function: either TCR1 or TCR2
INPUTS NOTES : This function has 4 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               period_result - A pointer to where the EBPPA accumulated period will be stored.
                        Can be NULL if user doesn't want this parameter.
               pulse_result - A pointer to where the EBPPA pulse result will be stored.
                        Can be NULL if user doesn't want this parameter.
               current_count - a pointer to where the current elapsed number
                        of periods and pulse widths will be stored.
                        Can be NULL if user doesn't want this parameter.
RETURNS NOTES: returns stat_acc; if stat_acc is non zero the result has overflowed
******************************************************************************/

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_Get_Immediate \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PeriodResult, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_PulseResult
)
{
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA) p32Ebppa_BsaeAdd;
	P2VAR(uint8, ATUPMATIC, EBPPA_APPL_DATA) p8Ebppa_BsaeAdd;
	VAR(uint8, EBPPA_VAR) u8Ebppa_StatusAcc = 0U;

    p32Ebppa_BsaeAdd = (uint32*)(eTPUInstance[u8Ebppa_EtpuGroup].data_ram_start /* polyspace RTE:OBAI */
    					+ ((uint32)eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPBA << 3U));/* polyspace RTE:OBAI,NIV,IDP */
                        
    p8Ebppa_BsaeAdd = (uint8 *) p32Ebppa_BsaeAdd;

    if (pEbppa_PeriodResult != NULL_PTR)
    {
        *pEbppa_PeriodResult = *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_ACCUM_PERIOD_OFFSET >> 2U));/* polyspace RTE:NIV,IDP */
    }
    if (pEbppa_PulseResult != NULL_PTR)
    {
        *pEbppa_PulseResult = *(p32Ebppa_BsaeAdd + (ETPU_EBPPA_ACCUM_PULSE_OFFSET >> 2U));/* polyspace RTE:NIV,IDP */
        u8Ebppa_StatusAcc = *(p8Ebppa_BsaeAdd + ETPU_EBPPA_STAT_ACC_OFFSET);/* polyspace RTE:NIV,IDP */
    }

    

    return u8Ebppa_StatusAcc;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_GetCount \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
)
{
    P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA) p32Ebppa_BsaeAdd;
	P2VAR(uint8, ATUPMATIC, EBPPA_APPL_DATA) p8Ebppa_BsaeAdd;
	VAR(uint8, EBPPA_VAR) u8Ebppa_StatusAcc = 0U;

    p32Ebppa_BsaeAdd = (uint32*)(eTPUInstance[u8Ebppa_EtpuGroup].data_ram_start /* polyspace RTE:OBAI */
    					+ ((uint32)eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPBA << 3U));/* polyspace RTE:OBAI,NIV,IDP */
    p8Ebppa_BsaeAdd = (uint8 *) p32Ebppa_BsaeAdd;

    if (pEbppa_CurrentCount != NULL_PTR)
    {
        *pEbppa_CurrentCount= (*(p32Ebppa_BsaeAdd + ((ETPU_EBPPA_PERIOD_COUNT_OFFSET - 1U)>>2U))&0xffffffu);/* polyspace RTE:NIV,IDP */
        u8Ebppa_StatusAcc = *(p8Ebppa_BsaeAdd + ETPU_EBPPA_STAT_ACC_OFFSET);/* polyspace RTE:NIV */
    }
    return u8Ebppa_StatusAcc;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, EBPPA_CODE) ETPU_LLD_EBPPA_ResetCount \
( \
	VAR(uint8, EBPPA_VAR) u8Ebppa_EtpuGroup, \
	VAR(uint8, EBPPA_VAR) u8Ebppa_Channel, \
	P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA)pEbppa_CurrentCount
)
{
    P2VAR(uint32, ATUPMATIC, EBPPA_APPL_DATA) p32Ebppa_BsaeAdd;
	P2VAR(uint8, ATUPMATIC, EBPPA_APPL_DATA) p8Ebppa_BsaeAdd;
	VAR(uint8, EBPPA_VAR) u8Ebppa_StatusAcc = 0U;

    p32Ebppa_BsaeAdd = (uint32*)(eTPUInstance[u8Ebppa_EtpuGroup].data_ram_start /* polyspace RTE:OBAI */
    					+ ((uint32)eTPUInstance[u8Ebppa_EtpuGroup].eTPU->CHAN[u8Ebppa_Channel].CR.B.CPBA << 3U));/* polyspace RTE:OBAI,NIV,IDP */
    p8Ebppa_BsaeAdd = (uint8 *) p32Ebppa_BsaeAdd;

    if (pEbppa_CurrentCount != NULL_PTR)
    {
        *(p32Ebppa_BsaeAdd + ((ETPU_EBPPA_PERIOD_COUNT_OFFSET - 1U)>>2U))= 0U;/* polyspace RTE:IDP */
        *pEbppa_CurrentCount=*(p32Ebppa_BsaeAdd + ((ETPU_EBPPA_PERIOD_COUNT_OFFSET - 1U)>>2U));
        u8Ebppa_StatusAcc = *(p8Ebppa_BsaeAdd + ETPU_EBPPA_STAT_ACC_OFFSET);/* polyspace RTE:NIV */
    }
    return u8Ebppa_StatusAcc;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#endif/*EBPPA_INSTANCE_NUM != 0U*/

#ifdef __cplusplus
}
#endif
#endif
