/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Crc
*   Dependencies         : \
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Crc_Sw.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Crc MCAL driver.
*
*   @addtogroup Crc
*   @{
*/
/*PRQA S 0380,0492,2906,2985,2921,0580 EOF*/

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/

#include "Crc_Sw.h"
#include "Crc_Table.h"

/*====================================================================================================
SOURCE FILE VERSION INFORMATION
====================================================================================================*/

#define CRC_SW_VENDOR_ID_C                 176
#define CRC_SW_AR_MAJOR_VER_C              4
#define CRC_SW_AR_MINOR_VER_C              4
#define CRC_SW_AR_PATCH_VER_C              0
#define CRC_SW_SW_MAJOR_VER_C              3
#define CRC_SW_SW_MINOR_VER_C              0
#define CRC_SW_SW_PATCH_VER_C              0

/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/

/* Check if current file and CRC header file are of the same vendor */
#if (CRC_SW_VENDOR_ID_C != CRC_VENDOR_ID)
#error "NON-MATCHED DATA : CRC_VENDOR_ID"
#endif

/* Check if current file and CRC header file are of the same Autosar version */
#if (CRC_SW_AR_MAJOR_VER_C != CRC_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MAJOR_VERSION"
#endif
#if (CRC_SW_AR_MINOR_VER_C != CRC_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MINOR_VERSION"
#endif
#if (CRC_SW_AR_PATCH_VER_C != CRC_AR_PATCH_VER)
#error "NON-MATCHED DATA : CRC_AR_PATCH_VER"
#endif

/* Check if current file and CRC header file are of the same Software version */
#if (CRC_SW_SW_MAJOR_VER_C != CRC_SW_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MAJOR_VER"
#endif
#if (CRC_SW_SW_MINOR_VER_C != CRC_SW_MINOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MINOR_VER"
#endif
#if (CRC_SW_SW_PATCH_VER_C != CRC_SW_PATCH_VER)
#error "NON-MATCHED DATA : CRC_SW_PATCH_VER"
#endif

/*==================================================================================================
GLOBAL VARIABLES
==================================================================================================*/


/*====================================================================================================
GLOBAL FUNCTIONS
====================================================================================================*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_Sw_CalculateCRC8(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                 VAR(uint32, AUTOMATIC) Crc_Length, 
                                 VAR(uint8, AUTOMATIC) Crc_StartValue,
                                 VAR(uint8, AUTOMATIC) Polynomial )
{
    VAR(uint8, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) Idx;
    VAR(uint8, CRC_VAR) MessageBit;
    Result = Crc_StartValue;
    for (Idx = 0U; Idx < Crc_Length; Idx++)
    {
    	Result ^= Crc_DataPtr[Idx];/* polyspace RTE:IDP */
        for(MessageBit = 8U; MessageBit > 0U; MessageBit--)
        {
            if(( Result & 0x80U ) == 0x80U)
            {
            	Result = ((uint8)((uint8)Result << 0x01U)) ^ Polynomial;
            }
            else
            {
            	Result = (uint8)((uint8)Result << 0x01U);
            }
        }
    }
    Result = Result ^ 0xFFU;
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_Sw_CalculateCRC16(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint16, AUTOMATIC) Crc_StartValue )
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) Idx;
    VAR(uint8, CRC_VAR) MessageBit;
    Result = Crc_StartValue;
    for(Idx = 0U; Idx < Crc_Length; Idx++)
    {
        Result ^= (uint16)((uint16)Crc_DataPtr[Idx] << 8U);/* polyspace RTE:IDP */
        for(MessageBit = 8U; MessageBit > 0U; MessageBit--)
        {
            if((Result & 0x8000U) == 0x8000U)
            {
                Result = (uint16)((uint16)Result << 1U) ^ 0x1021U;
            }
            else
            {
                Result = (uint16)((uint16)Result << 1U);
            }
        }
    }
    Result = Result ^ 0x0000U;
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_Sw_CalculateCRC16ARC(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint16, AUTOMATIC) Crc_StartValue )
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint16, CRC_VAR) DataTemp;
    VAR(uint32, CRC_VAR) Idx;
    VAR(uint8, CRC_VAR) MessageBit;
    Result = Crc_StartValue;
    for(Idx = 0U; Idx < Crc_Length; Idx++)
    {
        DataTemp = Crc_ReflectCRC16((uint16)Crc_DataPtr[Idx], 8U);/* polyspace RTE:IDP */
        Result ^= (uint16)(DataTemp << 8U);
        for(MessageBit = 8U; MessageBit > 0U; MessageBit--)
        {
            if((Result & 0x8000U) == 0x8000U)
            {
                Result = (uint16)((uint16)Result << 1U) ^ 0x8005U;
            }
            else
            {
                Result = (uint16)((uint16)Result << 1U);
            }
        }
    }
    Result = Crc_ReflectCRC16(Result, 16U);
    Result = Result ^ 0x0000U;
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_Sw_CalculateCRC32(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint32, AUTOMATIC) Crc_StartValue,
                                VAR(uint32, AUTOMATIC) Polynomial )
{
    VAR(uint32, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) DataTemp;
    VAR(uint32, CRC_VAR) Idx;
    VAR(uint8, CRC_VAR) MessageBit;
    Result = Crc_StartValue;

    for (Idx = 0U; Idx < Crc_Length; Idx++)
    {
        DataTemp = Crc_ReflectCRC32((uint32)Crc_DataPtr[Idx], 8U);/* polyspace RTE:IDP */
        Result ^=  (uint32)(DataTemp << 24U);
        for( MessageBit = 8U;  MessageBit > 0U; MessageBit--)
        {
            if((Result & 0x80000000U) == 0x80000000U)
            {
                Result = (Result << 1U) ^ Polynomial;
            }
            else
            {
                Result = (Result << 1U);
            }
        }
    }
    Result = Crc_ReflectCRC32(Result, 32U);
    Result = Result ^ 0xFFFFFFFFU;
    return Result;
}

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint64, CRC_CODE) Crc_Sw_CalculateCRC64(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                VAR(uint32, AUTOMATIC) Crc_Length, 
                                VAR(uint64, AUTOMATIC) Crc_StartValue,
                                VAR(uint64, AUTOMATIC) Polynomial )
{
    VAR(uint64, CRC_VAR) Result;
    VAR(uint64, CRC_VAR) DataTemp;
    VAR(uint32, CRC_VAR) Idx;
    VAR(uint8, CRC_VAR) MessageBit;
    Result = Crc_StartValue;

    for (Idx = 0U; Idx < Crc_Length; Idx++)
    {
        DataTemp = Crc_ReflectCRC64((uint64)Crc_DataPtr[Idx], 8U);/* polyspace RTE:IDP */
        Result ^=  (uint64)(DataTemp << 56U); /*PRQA S 2790*/
        for( MessageBit = 8U;  MessageBit > 0U; MessageBit--)
        {
            if((Result & 0x8000000000000000U) == 0x8000000000000000U) /*PRQA S 2991,2995*/
            {
                Result = (Result << 1U) ^ Polynomial;
            }
            else
            {
                Result = (Result << 1U);
            }
        }
    }
    Result = Crc_ReflectCRC64(Result, 64U);
    Result = Result ^ 0xFFFFFFFFFFFFFFFFU;
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

