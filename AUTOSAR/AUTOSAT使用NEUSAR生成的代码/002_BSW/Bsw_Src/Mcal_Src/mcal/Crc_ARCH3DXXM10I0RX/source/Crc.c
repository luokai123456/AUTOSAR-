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
*   @file    Crc.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Crc MCAL driver.
*
*   @addtogroup Crc
*   @{
*/
/*PRQA S 0380,3408,0686,3432,2985,2844,0491,4461,1533,0580 EOF*/
#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/

#include "Crc.h"
#include "Crc_Hw.h"
#include "Crc_Sw.h"
#include "Crc_Table.h"
#include "SchM_Crc.h"
/*====================================================================================================
SOURCE FILE VERSION INFORMATION
====================================================================================================*/

#define CRC_VENDOR_ID_C                 176
#define CRC_AR_RELEASE_MAJOR_VERSION_C              4
#define CRC_AR_RELEASE_MINOR_VERSION_C              4
#define CRC_AR_PATCH_VER_C              0
#define CRC_SW_MAJOR_VER_C              3
#define CRC_SW_MINOR_VER_C              0
#define CRC_SW_PATCH_VER_C              0

/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/

/* Check if current file and CRC header file are of the same vendor */
#if (CRC_VENDOR_ID_C != CRC_VENDOR_ID)
#error "NON-MATCHED DATA : CRC_VENDOR_ID"
#endif

/* Check if current file and CRC header file are of the same Autosar version */
#if (CRC_AR_RELEASE_MAJOR_VERSION_C != CRC_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MAJOR_VERSION"
#endif
#if (CRC_AR_RELEASE_MINOR_VERSION_C != CRC_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MINOR_VERSION"
#endif
#if (CRC_AR_PATCH_VER_C != CRC_AR_PATCH_VER)
#error "NON-MATCHED DATA : CRC_AR_PATCH_VER"
#endif

/* Check if current file and CRC header file are of the same Software version */
#if (CRC_SW_MAJOR_VER_C != CRC_SW_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MAJOR_VER"
#endif
#if (CRC_SW_MINOR_VER_C != CRC_SW_MINOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MINOR_VER"
#endif
#if (CRC_SW_PATCH_VER_C != CRC_SW_PATCH_VER)
#error "NON-MATCHED DATA : CRC_SW_PATCH_VER"
#endif

/*==================================================================================================
GLOBAL VARIABLES
==================================================================================================*/
#define CRC_START_SEC_VAR_NO_INIT
#include "Crc_MemMap.h"
P2CONST(Crc_ConfigType, CRC_VAR, CRC_APPL_CONST) pCrc_ConfigPtr = NULL_PTR ;
#define CRC_STOP_SEC_VAR_NO_INIT
#include "Crc_MemMap.h"

#define CRC_START_SEC_VAR_INIT
#include "Crc_MemMap.h"
VAR(CRC_StatusType, WDG_VAR) eCRC_OperStatus[CRC_INDEX] = {CRC_NOUSE};
#define CRC_STOP_SEC_VAR_INIT
#include "Crc_MemMap.h"

/*====================================================================================================
GLOBAL FUNCTIONS
====================================================================================================*/

/*******************************************************************************
**  Service Name     : CRC_GetVersionInfo                                                                                                               
**  Description      : Returns the version information of the module.                                                                          
**  Service ID       : 0x04                                                                                                                        
**  Sync/Async       : Synchronous                                                                                                                    
**  Parameters (in)  : versioninfo: Pointer to where to store the version     
**                     information of this module.                                                                                                    
**  Parameters (out) : None                                                                                                                           
**  Return value     : None                                                                                                                          
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) CRC_GetVersionInfo \
( \
		P2VAR(Std_VersionInfoType, AUTOMATIC, CRC_APPL_DATA) Versioninfo
)
{

        (Versioninfo)->vendorID         = (uint16)CRC_HW_VENDOR_ID;
        (Versioninfo)->moduleID         = (uint8)CRC_MODULE_ID;
        (Versioninfo)->sw_major_version = (uint8)CRC_HW_SW_MAJOR_VER;
        (Versioninfo)->sw_minor_version = (uint8)CRC_HW_SW_MINOR_VER;
        (Versioninfo)->sw_patch_version = (uint8)CRC_HW_SW_PATCH_VER;

}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"
/*******************************************************************************
**  Service Name     : Crc_CalculateCRC8
**
**  Description      : The function Crc_CalculateCRC8 shall perform a CRC8 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint8
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                        VAR(uint32, AUTOMATIC) Crc_Length, 
                        VAR(uint8, AUTOMATIC) Crc_StartValue8, 
                        VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint8, CRC_VAR) Result;
    VAR(uint8, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFU;
        (void)Crc_StartValue8;
    }
    else
    {
        StartValue = Crc_StartValue8;
        StartValue = StartValue ^ 0xFFU;
    }
    #if CRC_8_MODE == CRC_8_HARDWARE
    	SchM_Enter_Crc_EXCLUSIVE_AREA_00();
        Result = Crc_Hw_CalculateCRC8(CRC_CONTROLLER,Crc_DataPtr,Crc_Length,StartValue);
        SchM_Exit_Crc_EXCLUSIVE_AREA_00();
    #elif CRC_8_MODE == CRC_8_RUNTIME
        Result = Crc_Sw_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x1DU);
    #elif CRC_8_MODE == CRC_8_TABLE
        Result = Crc_Table_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x1DU);
    #else
        #error "There is no valid configuration option"
    #endif

    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC8H2F
**
**  Description      : The function Crc_CalculateCRC8H2F shall perform a CRC8H2F calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated.
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts.
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8.
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call.
**
**  Parameters (out) : None
**
**  Return value     : uint8
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                           VAR(uint32, AUTOMATIC) Crc_Length, 
                           VAR(uint8, AUTOMATIC) Crc_StartValue8, 
                           VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint8, CRC_VAR) Result;
    VAR(uint8, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFU;
        (void)Crc_StartValue8;
    }
    else
    {
        StartValue = Crc_StartValue8;
        StartValue = StartValue ^ 0xFFU;
    }
    #if CRC_8H2F_MODE == CRC_8H2F_RUNTIME
        Result = Crc_Sw_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x2FU);
    #elif CRC_8H2F_MODE == CRC_8H2F_TABLE
        Result = Crc_Table_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x2FU);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC16
**
**  Description      : The function Crc_CalculateCRC16 shall perform a CRC16 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue16   Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint16
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                          VAR(uint32, AUTOMATIC) Crc_Length, 
                          VAR(uint16, AUTOMATIC) Crc_StartValue16, 
                          VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint16, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFFFU;
        (void)Crc_StartValue16;
    }
    else
    {
        StartValue = Crc_StartValue16;
    }
    #if CRC_16_MODE == CRC_16_HARDWARE
    	SchM_Enter_Crc_EXCLUSIVE_AREA_01();
        Result = Crc_Hw_CalculateCRC16(CRC_CONTROLLER,Crc_DataPtr,Crc_Length,StartValue);
        SchM_Exit_Crc_EXCLUSIVE_AREA_01();
    #elif CRC_16_MODE == CRC_16_RUNTIME
        Result = Crc_Sw_CalculateCRC16(Crc_DataPtr,Crc_Length,StartValue);
    #elif CRC_16_MODE == CRC_16_TABLE
        Result = Crc_Table_CalculateCRC16(Crc_DataPtr,Crc_Length,StartValue);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC16ARC
**
**  Description      : The function Crc_CalculateCRC16ARC shall perform a CRC16ARC calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint16
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16ARC(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                             VAR(uint32, AUTOMATIC) Crc_Length, 
                             VAR(uint16, AUTOMATIC) Crc_StartValue16, 
                             VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint16, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0x0000U;
        (void)Crc_StartValue16;
    }
    else
    {
        StartValue = Crc_StartValue16;
        StartValue = StartValue ^ 0x0000U;
        StartValue = Crc_ReflectCRC16(StartValue, 16U);
    }
    #if CRC_16ARC_MODE == CRC_16_ARC_RUNTIME
        Result = Crc_Sw_CalculateCRC16ARC(Crc_DataPtr,Crc_Length,StartValue);
    #elif CRC_16ARC_MODE == CRC_16_ARC_TABLE
        Result = Crc_Table_CalculateCRC16ARC(Crc_DataPtr,Crc_Length,StartValue);
    #else
        #error "There is no valid configuration option"
    #endif

    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC32
**
**  Description      : The function Crc_CalculateCRC32 shall perform a CRC32 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint32
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                          VAR(uint32, AUTOMATIC) Crc_Length, 
                          VAR(uint32, AUTOMATIC) Crc_StartValue32, 
                          VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint32, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) StartValue;

	if(Crc_IsFirstCall == (boolean)TRUE)
	{
		StartValue = 0xFFFFFFFFU;
		(void)Crc_StartValue32;
	}
	else
	{
		StartValue = Crc_StartValue32;
		StartValue = StartValue ^ 0xFFFFFFFFU;
		StartValue = Crc_ReflectCRC32(StartValue, 32U);
	}
    #if CRC_32_MODE == CRC_32_HARDWARE
    	SchM_Enter_Crc_EXCLUSIVE_AREA_02();
        Result = Crc_Hw_CalculateCRC32(CRC_CONTROLLER,Crc_DataPtr,Crc_Length,StartValue);
        SchM_Exit_Crc_EXCLUSIVE_AREA_02();
    #elif CRC_32_MODE == CRC_32_RUNTIME
        Result =  Crc_Sw_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0x04C11DB7U);
    #elif CRC_32_MODE == CRC_32_TABLE
        Result = Crc_Table_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0x04C11DB7U);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC32P4
**
**  Description      : The function Crc_CalculateCRC32P4 shall perform a CRC32P4 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue32   Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint32
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                            VAR(uint32, AUTOMATIC) Crc_Length, 
                            VAR(uint32, AUTOMATIC) Crc_StartValue32, 
                            VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint32, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFFFFFFFU;
        (void)Crc_StartValue32;
    }
    else
    {
        StartValue = Crc_StartValue32;
        StartValue = StartValue ^ 0xFFFFFFFFU;
        StartValue = Crc_ReflectCRC32(StartValue, 32);
    }
    #if CRC_32P4_MODE == CRC_32P4_RUNTIME
        Result =  Crc_Sw_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0xF4ACFB13U);
    #elif CRC_32P4_MODE == CRC_32P4_TABLE
        Result = Crc_Table_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0xF4ACFB13U);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


/*******************************************************************************
**  Service Name     : Crc_CalculateCRC64
**
**  Description      : The function Crc_CalculateCRC64 shall perform a CRC64 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint64
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint64, CRC_CODE) Crc_CalculateCRC64(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                          VAR(uint32, AUTOMATIC) Crc_Length,
                          VAR(uint64, AUTOMATIC) Crc_StartValue64,
                          VAR(boolean, AUTOMATIC) Crc_IsFirstCall)                   
{
    VAR(uint64, CRC_VAR) Result;
    VAR(uint64, CRC_VAR) StartValue;

    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFFFFFFFFFFFFFFFU;
        (void)Crc_StartValue64;
    }
    else
    {
        StartValue = Crc_StartValue64;
        StartValue = StartValue ^ 0xFFFFFFFFFFFFFFFFU;
        StartValue = Crc_ReflectCRC64(StartValue, 64);
    }
    
    #if CRC_64_MODE == CRC_64_RUNTIME
        Result = Crc_Sw_CalculateCRC64(Crc_DataPtr, Crc_Length,StartValue,0x42F0E1EBA9EA3693);
    #elif CRC_64_MODE == CRC_64_TABLE
        Result = Crc_Table_CalculateCRC64(Crc_DataPtr, Crc_Length,StartValue);
    #else
        #error "There is no valid configuration option"
    #endif

    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                        VAR(uint32, AUTOMATIC) Crc_Length, 
                        VAR(uint8, AUTOMATIC) Crc_StartValue8, 
                        VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint8, CRC_VAR) Result;
    VAR(uint8, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFU;
        (void)Crc_StartValue8;
    }
    else
    {
        StartValue = Crc_StartValue8;
        StartValue = StartValue ^ 0xFFU;
    }
    #if CRC_8_MODE_EXT == CRC_8_HARDWARE
    	SchM_Enter_Crc_EXCLUSIVE_AREA_03();
        Result = Crc_Hw_CalculateCRC8(CRC_CONTROLLER_EXT,Crc_DataPtr,Crc_Length,StartValue);
        SchM_Exit_Crc_EXCLUSIVE_AREA_03();
    #elif CRC_8_MODE_EXT == CRC_8_RUNTIME
        Result = Crc_Sw_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x1DU);
    #elif CRC_8_MODE_EXT == CRC_8_TABLE
        Result = Crc_Table_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x1DU);
    #else
        #error "There is no valid configuration option"
    #endif

    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC8H2F
**
**  Description      : The function Crc_CalculateCRC8H2F shall perform a CRC8H2F calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated.
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts.
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8.
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call.
**
**  Parameters (out) : None
**
**  Return value     : uint8
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8H2F_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                           VAR(uint32, AUTOMATIC) Crc_Length, 
                           VAR(uint8, AUTOMATIC) Crc_StartValue8, 
                           VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint8, CRC_VAR) Result;
    VAR(uint8, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFU;
        (void)Crc_StartValue8;
    }
    else
    {
        StartValue = Crc_StartValue8;
        StartValue = StartValue ^ 0xFFU;
    }
    #if CRC_8H2F_MODE_EXT == CRC_8H2F_RUNTIME
        Result = Crc_Sw_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x2FU);
    #elif CRC_8H2F_MODE_EXT == CRC_8H2F_TABLE
        Result = Crc_Table_CalculateCRC8(Crc_DataPtr,Crc_Length,StartValue,0x2FU);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC16
**
**  Description      : The function Crc_CalculateCRC16 shall perform a CRC16 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue16   Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint16
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                          VAR(uint32, AUTOMATIC) Crc_Length, 
                          VAR(uint16, AUTOMATIC) Crc_StartValue16, 
                          VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint16, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFFFU;
        (void)Crc_StartValue16;
    }
    else
    {
        StartValue = Crc_StartValue16;
    }
    #if CRC_16_MODE_EXT == CRC_16_HARDWARE
    	SchM_Enter_Crc_EXCLUSIVE_AREA_04();
        Result = Crc_Hw_CalculateCRC16(CRC_CONTROLLER_EXT,Crc_DataPtr,Crc_Length,StartValue);
        SchM_Exit_Crc_EXCLUSIVE_AREA_04();
    #elif CRC_16_MODE_EXT == CRC_16_RUNTIME
        Result = Crc_Sw_CalculateCRC16(Crc_DataPtr,Crc_Length,StartValue);
    #elif CRC_16_MODE_EXT == CRC_16_TABLE
        Result = Crc_Table_CalculateCRC16(Crc_DataPtr,Crc_Length,StartValue);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC16ARC
**
**  Description      : The function Crc_CalculateCRC16ARC shall perform a CRC16ARC calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint16
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16ARC_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                             VAR(uint32, AUTOMATIC) Crc_Length, 
                             VAR(uint16, AUTOMATIC) Crc_StartValue16, 
                             VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint16, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0x0000U;
        (void)Crc_StartValue16;
    }
    else
    {
        StartValue = Crc_StartValue16;
        StartValue = StartValue ^ 0x0000U;
        StartValue = Crc_ReflectCRC16(StartValue, 16U);
    }
    #if CRC_16ARC_MODE_EXT == CRC_16_ARC_RUNTIME
        Result = Crc_Sw_CalculateCRC16ARC(Crc_DataPtr,Crc_Length,StartValue);
    #elif CRC_16ARC_MODE_EXT == CRC_16_ARC_TABLE
        Result = Crc_Table_CalculateCRC16ARC(Crc_DataPtr,Crc_Length,StartValue);
    #else
        #error "There is no valid configuration option"
    #endif

    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC32
**
**  Description      : The function Crc_CalculateCRC32 shall perform a CRC32 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint32
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                          VAR(uint32, AUTOMATIC) Crc_Length, 
                          VAR(uint32, AUTOMATIC) Crc_StartValue32, 
                          VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint32, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) StartValue;

	if(Crc_IsFirstCall == (boolean)TRUE)
	{
		StartValue = 0xFFFFFFFFU;
		(void)Crc_StartValue32;
	}
	else
	{
		StartValue = Crc_StartValue32;
		StartValue = StartValue ^ 0xFFFFFFFFU;
		StartValue = Crc_ReflectCRC32(StartValue, 32U);
	}
    #if CRC_32_MODE_EXT == CRC_32_HARDWARE
    	SchM_Enter_Crc_EXCLUSIVE_AREA_05();
        Result = Crc_Hw_CalculateCRC32(CRC_CONTROLLER_EXT,Crc_DataPtr,Crc_Length,StartValue);
        SchM_Exit_Crc_EXCLUSIVE_AREA_05();
    #elif CRC_32_MODE_EXT == CRC_32_RUNTIME
        Result =  Crc_Sw_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0x04C11DB7U);
    #elif CRC_32_MODE_EXT == CRC_32_TABLE
        Result = Crc_Table_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0x04C11DB7U);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

/*******************************************************************************
**  Service Name     : Crc_CalculateCRC32P4
**
**  Description      : The function Crc_CalculateCRC32P4 shall perform a CRC32P4 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue32   Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint32
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_CalculateCRC32P4_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr, 
                            VAR(uint32, AUTOMATIC) Crc_Length, 
                            VAR(uint32, AUTOMATIC) Crc_StartValue32, 
                            VAR(boolean, AUTOMATIC) Crc_IsFirstCall)
{
    VAR(uint32, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) StartValue;
    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFFFFFFFU;
        (void)Crc_StartValue32;
    }
    else
    {
        StartValue = Crc_StartValue32;
        StartValue = StartValue ^ 0xFFFFFFFFU;
        StartValue = Crc_ReflectCRC32(StartValue, 32);
    }
    #if CRC_32P4_MODE_EXT == CRC_32P4_RUNTIME
        Result =  Crc_Sw_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0xF4ACFB13U);
    #elif CRC_32P4_MODE_EXT == CRC_32P4_TABLE
        Result = Crc_Table_CalculateCRC32(Crc_DataPtr,Crc_Length,StartValue, 0xF4ACFB13U);
    #else
        #error "There is no valid configuration option"
    #endif
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


/*******************************************************************************
**  Service Name     : Crc_CalculateCRC64
**
**  Description      : The function Crc_CalculateCRC64 shall perform a CRC64 calculation on Crc_Length data bytes.
**
**  Parameters (in)  : Crc_DataPtr        Pointer to start address of data block to be calculated. 
**  Parameters (in)  : Crc_Length         Length of data block to be calculated in bytes.
**  Parameters (in)  : Crc_StartValue8    Start value when the algorithm starts. 
**  Parameters (in)  : Crc_IsFirstCall   TRUE: First call in a sequence or individual CRC calculation; start from initial value, ignore Crc_StartValue8. 
                                         FALSE: Subsequent call in a call sequence; Crc_StartValue8 is interpreted to be the return value of the previous function call. 
**
**  Parameters (out) : None
**
**  Return value     : uint64
**
*******************************************************************************/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint64, CRC_CODE) Crc_CalculateCRC64_Ext(P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                          VAR(uint32, AUTOMATIC) Crc_Length,
                          VAR(uint64, AUTOMATIC) Crc_StartValue64,
                          VAR(boolean, AUTOMATIC) Crc_IsFirstCall)                   
{
    VAR(uint64, CRC_VAR) Result;
    VAR(uint64, CRC_VAR) StartValue;

    if(Crc_IsFirstCall == (boolean)TRUE)
    {
        StartValue = 0xFFFFFFFFFFFFFFFFU;
        (void)Crc_StartValue64;
    }
    else
    {
        StartValue = Crc_StartValue64;
        StartValue = StartValue ^ 0xFFFFFFFFFFFFFFFFU;
        StartValue = Crc_ReflectCRC64(StartValue, 64);
    }
    
    #if CRC_64_MODE_EXT == CRC_64_RUNTIME
        Result = Crc_Sw_CalculateCRC64(Crc_DataPtr, Crc_Length,StartValue,0x42F0E1EBA9EA3693);
    #elif CRC_64_MODE_EXT == CRC_64_TABLE
        Result = Crc_Table_CalculateCRC64(Crc_DataPtr, Crc_Length,StartValue);
    #else
        #error "There is no valid configuration option"
    #endif

    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(Std_ReturnType, CRC_CODE) Crc_AsyncCalculate(
    VAR(uint8, AUTOMATIC) CrcIndex,
    P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
    VAR(uint32, AUTOMATIC) Crc_Length,
    VAR(uint32, AUTOMATIC) Crc_StartValue32,
    VAR(boolean, AUTOMATIC)  Crc_IsFirstCall)
{
	VAR(Std_ReturnType, AUTOMATIC) u8Crc_Ret = (Std_ReturnType)E_NOT_OK;
#if (CRC_CHANNEL_MAX!=0)
	if(CrcIndex >= (uint8)CRC_CHANNEL_MAX)
	{
		u8Crc_Ret = (Std_ReturnType)E_NOT_OK;
	}
	else{

		pCrc_ConfigPtr = &Crc_Config;

		if(pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].Calculate == CRC_POLYNOMIAL_8)
		{

			VAR(uint8, CRC_VAR) StartValue;
			if(Crc_IsFirstCall == (boolean)TRUE)
			{
				StartValue = 0xFFU;
			}
			else
			{
				StartValue = Crc_StartValue32;
				StartValue = StartValue ^ 0xFFU;
			}

            if(eCRC_OperStatus[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId] == CRC_NOUSE)/* polyspace RTE:OBAI */
            {
                Crc_Hw_CalculateAsyncCRC8(CrcIndex,Crc_DataPtr,Crc_Length,StartValue);
                eCRC_OperStatus[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId] = CRC_BUSY;/* polyspace RTE:OBAI */
            }
            u8Crc_Ret = (Std_ReturnType)E_OK;
		}
		else if(pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].Calculate == CRC_POLYNOMIAL_16)
		{

			VAR(uint16, CRC_VAR) StartValue;
			if(Crc_IsFirstCall == (boolean)TRUE)
			{
				StartValue = 0xFFFFU;
			}
			else
			{
				StartValue = Crc_StartValue32;
			}

			if(eCRC_OperStatus[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId] == CRC_NOUSE)/* polyspace RTE:OBAI */
			{
				Crc_Hw_CalculateAsyncCRC16(CrcIndex,Crc_DataPtr,Crc_Length,StartValue);
				eCRC_OperStatus[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId] = CRC_BUSY;/* polyspace RTE:OBAI */
			}
			u8Crc_Ret = (Std_ReturnType)E_OK;
		}
		else if(pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].Calculate == CRC_POLYNOMIAL_32)
		{

			VAR(uint32, CRC_VAR) StartValue;
			if(Crc_IsFirstCall == (boolean)TRUE)
			{
				StartValue = 0xFFFFFFFFU;
			}
			else
			{
				StartValue = Crc_StartValue32;
				StartValue = StartValue ^ 0xFFFFFFFFU;
				StartValue = Crc_ReflectCRC32(StartValue, 32U);
			}

            if(eCRC_OperStatus[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId] == CRC_NOUSE)/* polyspace RTE:OBAI */
           	{
                Crc_Hw_CalculateAsyncCRC32(CrcIndex,Crc_DataPtr,Crc_Length,StartValue);
               
                eCRC_OperStatus[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId] = CRC_BUSY;/* polyspace RTE:OBAI */
            }
            u8Crc_Ret = (Std_ReturnType)E_OK;
		}
		else{
			u8Crc_Ret = (Std_ReturnType)E_NOT_OK;
		}
	}
#else
	(void)CrcIndex;
	(void)Crc_DataPtr;
	(void)Crc_IsFirstCall;
	(void)Crc_StartValue32;
	(void)Crc_Length;
#endif
    return u8Crc_Ret;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

