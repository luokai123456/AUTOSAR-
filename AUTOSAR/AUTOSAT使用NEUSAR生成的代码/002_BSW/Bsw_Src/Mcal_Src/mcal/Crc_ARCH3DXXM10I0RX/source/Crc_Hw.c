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
*   @file    Crc_Hw.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Crc MCAL driver.
*
*   @addtogroup Crc
*   @{
*/
/*PRQA S 0380,2844,3432,0751,0492,0491,0313,4304,4404,0314,0431,0311 EOF*/

#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================
INCLUDE FILES
====================================================================================================*/

#include "Crc_Hw.h"

#include "eDma.h"
/*====================================================================================================
SOURCE FILE VERSION INFORMATION
====================================================================================================*/

#define CRC_HW_VENDOR_ID_C                 176
#define CRC_HW_AR_MAJOR_VER_C              4
#define CRC_HW_AR_MINOR_VER_C              4
#define CRC_HW_AR_PATCH_VER_C              0
#define CRC_HW_SW_MAJOR_VER_C              3
#define CRC_HW_SW_MINOR_VER_C              0
#define CRC_HW_SW_PATCH_VER_C              0

/*====================================================================================================
FILE VERSION CHECKS
====================================================================================================*/

/* Check if current file and CRC header file are of the same vendor */
#if (CRC_HW_VENDOR_ID_C != CRC_VENDOR_ID)
#error "NON-MATCHED DATA : CRC_VENDOR_ID"
#endif

/* Check if current file and CRC header file are of the same Autosar version */
#if (CRC_HW_AR_MAJOR_VER_C != CRC_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MAJOR_VERSION"
#endif
#if (CRC_HW_AR_MINOR_VER_C != CRC_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CRC_AR_RELEASE_MINOR_VERSION"
#endif
#if (CRC_HW_AR_PATCH_VER_C != CRC_AR_PATCH_VER)
#error "NON-MATCHED DATA : CRC_AR_PATCH_VER"
#endif

/* Check if current file and CRC header file are of the same Software version */
#if (CRC_HW_SW_MAJOR_VER_C != CRC_SW_MAJOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MAJOR_VER"
#endif
#if (CRC_HW_SW_MINOR_VER_C != CRC_SW_MINOR_VER)
#error "NON-MATCHED DATA : CRC_SW_MINOR_VER"
#endif
#if (CRC_HW_SW_PATCH_VER_C != CRC_SW_PATCH_VER)
#error "NON-MATCHED DATA : CRC_SW_PATCH_VER"
#endif

/*==================================================================================================
GLOBAL VARIABLES
==================================================================================================*/
extern P2CONST(Crc_ConfigType, CRC_VAR, CRC_APPL_CONST) pCrc_ConfigPtr ;
extern VAR(CRC_StatusType, WDG_VAR) eCRC_OperStatus[CRC_INDEX] ;

#define CRC_START_SEC_VAR_INIT
#include "Crc_MemMap.h"
static CONSTP2VAR( CRC_tag_Type, CRC_VAR, CRC_APPL_CONST) g_CrcBase[CRC_INDEX] = CRC_BASE_PTRS;
#define CRC_STOP_SEC_VAR_INIT
#include "Crc_MemMap.h"
/*====================================================================================================
GLOBAL FUNCTIONS
====================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint8, CRC_CODE) Crc_Hw_CalculateCRC8(VAR(uint8, AUTOMATIC) CrcID,
							     P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                 VAR(uint32, AUTOMATIC) Crc_Length, 
                                 VAR(uint8, AUTOMATIC) Crc_StartValue )
{
    VAR(uint8, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) Idx;
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[CrcID];
    CRC_UNIT->CFG.R = CRC_CFG_POLYG_8;
    CRC_UNIT->CSTAT.R = (uint32)Crc_StartValue;
    for(Idx=0U;Idx<Crc_Length;Idx++)
    {
        *(volatile uint8 *)&CRC_UNIT->INP.R = Crc_DataPtr[Idx];/* polyspace RTE:IDP */
    }
    Result = (uint8)CRC_UNIT->OUTP.R;/* polyspace RTE:NIV */
    Result = Result ^ 0xFFU;
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint16, CRC_CODE) Crc_Hw_CalculateCRC16(VAR(uint8, AUTOMATIC) CrcID,
								   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                   VAR(uint32, AUTOMATIC) Crc_Length,
                                   VAR(uint16, AUTOMATIC) Crc_StartValue )
{
    VAR(uint16, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) Idx;
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[CrcID];
    CRC_UNIT->CFG.R = CRC_CFG_POLYG_16;
    CRC_UNIT->CSTAT.R = (uint32)Crc_StartValue;
    for(Idx=0U;Idx<Crc_Length;Idx++)
    {
    	*(volatile uint8 *)&CRC_UNIT->INP.R = Crc_DataPtr[Idx];/* polyspace RTE:IDP */
    }
    Result = (uint16)CRC_UNIT->OUTP.R;/* polyspace RTE:NIV */
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(uint32, CRC_CODE) Crc_Hw_CalculateCRC32(VAR(uint8, AUTOMATIC) CrcID,
								   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                   VAR(uint32, AUTOMATIC) Crc_Length,
                                   VAR(uint32, AUTOMATIC) Crc_StartValue )
{
    VAR(uint32, CRC_VAR) Result;
    VAR(uint32, CRC_VAR) Idx;
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[CrcID];
    CRC_UNIT->CFG.R = CRC_CFG_POLYG_32;
    CRC_UNIT->CSTAT.R = (uint32)Crc_StartValue;
    for(Idx=0U;Idx<Crc_Length;Idx++)
    {
        *(volatile uint8 *)&CRC_UNIT->INP.R = Crc_DataPtr[Idx];/* polyspace RTE:IDP */
    }
    Result = (uint32)CRC_UNIT->OUTP.R;/* polyspace RTE:NIV */
    return Result;
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_AsyncHandle(P2VAR(Crc_ConfigGroupType, AUTOMATIC, CRC_APPL_DATA) CRC_HandlePtr)
{
    Crc_TransmitEndDma(CRC_HandlePtr);
}
FUNC(void, CRC_CODE) Crc_TransmitReceive_dma_8(VAR(uint8, AUTOMATIC) CrcIndex ,
                            P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                            VAR(uint32, AUTOMATIC) Crc_Length)
{
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId];/* polyspace RTE:OBAI,NIV,IDP */
    if((Crc_DataPtr != NULL_PTR))
    {
        (void)EDMA_SetMultiTransferConfig( pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel,/* polyspace RTE:NIV */
                                    EDMA_TRANSFER_TYPE_MEMTOMEM,
                                    (uint32)Crc_DataPtr,
                                    ((uint32 )&CRC_UNIT->INP.R),
                                    EDMA_TRANSFER_SIZE_1B,
                                    1U,
                                    Crc_Length,
                                    TRUE);
    }
    EDMA_SetInterruptConfig(pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    (void)EDMA_SetChannelRequest(pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel);
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_TransmitReceive_dma_16(VAR(uint8, AUTOMATIC) CrcIndex ,
                            P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                            VAR(uint32, AUTOMATIC) Crc_Length)
{
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId];/* polyspace RTE:OBAI,NIV,IDP*/
    if((Crc_DataPtr != NULL_PTR))
    {
        (void)EDMA_SetMultiTransferConfig(pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel,/* polyspace RTE:NIV */
                                    EDMA_TRANSFER_TYPE_MEMTOMEM,
                                    (uint32)Crc_DataPtr,
                                    ((uint32 )&CRC_UNIT->INP.R),
                                    EDMA_TRANSFER_SIZE_1B,
                                    1U,
                                    Crc_Length,
                                    TRUE);
    }
    EDMA_SetInterruptConfig((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel), EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    (void)EDMA_SetChannelRequest((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel));
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_TransmitReceive_dma_32(VAR(uint8, AUTOMATIC) CrcIndex ,
                            P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                            VAR(uint32, AUTOMATIC) Crc_Length)
{
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId];/* polyspace RTE:OBAI,NIV,IDP*/
    if((Crc_DataPtr != NULL_PTR))
    {
        (void)EDMA_SetMultiTransferConfig( (pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel),/* polyspace RTE:NIV */
                                    EDMA_TRANSFER_TYPE_MEMTOMEM,
                                    (uint32)Crc_DataPtr,
                                    ((uint32 )&CRC_UNIT->INP.R),
                                    EDMA_TRANSFER_SIZE_1B,
                                    1U,
                                    Crc_Length,
                                    TRUE);
    }
    EDMA_SetInterruptConfig((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel), EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    (void)EDMA_SetChannelRequest((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel));
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE)Crc_TransmitEndDma(P2VAR(Crc_ConfigGroupType, AUTOMATIC, CRC_APPL_DATA) CRC_HandlePtr)
{
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[CRC_HandlePtr->u8CrcId];/* polyspace RTE:OBAI */
    uint32 Result = 0U;
    if(CRC_HandlePtr->Calculate == CRC_POLYNOMIAL_32)
    {
    	Result = (uint32)CRC_UNIT->OUTP.R ;/* polyspace RTE:NIV */

    }
    else if(CRC_HandlePtr->Calculate == CRC_POLYNOMIAL_16)
    {
    	Result = (uint16)CRC_UNIT->OUTP.R ;/* polyspace RTE:NIV */
    }
    else if(CRC_HandlePtr->Calculate == CRC_POLYNOMIAL_8)
    {
    	Result = (uint8)CRC_UNIT->OUTP.R  ;/* polyspace RTE:NIV */
    	Result = Result ^ 0xFFU;
    }
    else{
	/*nothing*/
    }

    if(CRC_HandlePtr->CRC_Callback !=NULL_PTR)
    {
    	CRC_HandlePtr->CRC_Callback(Result);
    }
    if(eCRC_OperStatus[CRC_HandlePtr->u8CrcId] == CRC_BUSY)
    {
        eCRC_OperStatus[CRC_HandlePtr->u8CrcId] = CRC_NOUSE;
    }
  
    EDMA_SetInterruptConfig((CRC_HandlePtr->u8DMAChannel), EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_Hw_CalculateAsyncCRC8(VAR(uint8, AUTOMATIC) CrcIndex,
							     P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                 VAR(uint32, AUTOMATIC) Crc_Length, 
                                 VAR(uint8, AUTOMATIC) Crc_StartValue )
{

    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId];/* polyspace RTE:OBAI,IDP,NIV*/
    CRC_UNIT->CFG.R = CRC_CFG_POLYG_8;
    CRC_UNIT->CSTAT.R = (uint32)Crc_StartValue;
    (void)EDMA_SetUpCallback((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel), (eDMACallbackType)&Crc_AsyncHandle,( void*)&pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex]);/* polyspace RTE:NIV,IDP*/
    Crc_TransmitReceive_dma_8(CrcIndex,Crc_DataPtr,Crc_Length);

}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_Hw_CalculateAsyncCRC16(VAR(uint8, AUTOMATIC) CrcIndex,
								   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                   VAR(uint32, AUTOMATIC) Crc_Length,
                                   VAR(uint16, AUTOMATIC) Crc_StartValue )
{
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId];/* polyspace RTE:OBAI,IDP,NIV */

    CRC_UNIT->CFG.R = CRC_CFG_POLYG_16;
    CRC_UNIT->CSTAT.R = (uint32)Crc_StartValue;
    (void)EDMA_SetUpCallback((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel), (eDMACallbackType)&Crc_AsyncHandle,( void*)&pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex]);/* polyspace RTE:NIV,IDP*/

    Crc_TransmitReceive_dma_16(CrcIndex,Crc_DataPtr,Crc_Length);

}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
FUNC(void, CRC_CODE) Crc_Hw_CalculateAsyncCRC32(VAR(uint8, AUTOMATIC) CrcIndex,
								   P2CONST(uint8, CRC_APPL_CONST, AUTOMATIC)Crc_DataPtr,
                                   VAR(uint32, AUTOMATIC) Crc_Length,
                                   VAR(uint32, AUTOMATIC) Crc_StartValue )
{
    P2VAR(CRC_tag_Type, CRC_VAR , CRC_APPL_DATA) CRC_UNIT =g_CrcBase[pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8CrcId];/* polyspace RTE:OBAI,IDP,NIV*/


    CRC_UNIT->CFG.R = CRC_CFG_POLYG_32;
    CRC_UNIT->CSTAT.R = (uint32)Crc_StartValue;
    (void)EDMA_SetUpCallback((pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex].u8DMAChannel), (eDMACallbackType)&Crc_AsyncHandle,( void*)&pCrc_ConfigPtr->Crc_ConfigGroup[CrcIndex]);/* polyspace RTE:NIV,IDP */
    Crc_TransmitReceive_dma_32(CrcIndex,Crc_DataPtr,Crc_Length);

}
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

