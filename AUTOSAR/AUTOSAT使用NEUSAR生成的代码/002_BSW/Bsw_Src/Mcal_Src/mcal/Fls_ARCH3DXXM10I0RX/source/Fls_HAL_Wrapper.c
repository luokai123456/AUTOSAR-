/* PRQA S 2053, 2844 EOF */
/**************************************************************************** 
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        :
*
*****************************************************************************/
/* PRQA S 0380,2995,2985,0310 ,3305 ,0488 ,2982,1880 EOF */ 
/**
*   @file    Fls_HAL_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#include "Fls_HAL_Wrapper.h"
#include "Fls_Autosar_Wrapper.h"
#include "Fls_LLDriver.h"
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif


#define FLS_HAL_WRA_C_VENDOR_ID                     176
#define FLS_HAL_WRA_C_AR_REL_MAJOR_VER              4
#define FLS_HAL_WRA_C_AR_REL_MINOR_VER              4
#define FLS_HAL_WRA_C_AR_REL_REV_VER                0
#define FLS_HAL_WRA_C_SW_MAJOR_VER                  3
#define FLS_HAL_WRA_C_SW_MINOR_VER                  0
#define FLS_HAL_WRA_C_SW_PATCH_VER                  0

#if (FLS_VENDOR_ID_OUTPUT != FLS_HAL_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_HAL_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_HAL_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_HAL_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_HAL_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_HAL_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_HAL_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_C_SW_PATCH_VER "
#endif

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Fls_AddressType, FLS_CODE ) Fls_MaxTransferEndAddr \
( \
    CONST( Fls_LengthType, AUTOMATIC) u32Fls_MaxTransfer \
)
{
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_MaxEndAddr = gFls_JobAddrEnd;
    
    if( u32Fls_MaxEndAddr < (gFls_JobAddrIt + u32Fls_MaxTransfer) )
    {
        
    }
    else
    {
        u32Fls_MaxEndAddr = (gFls_JobAddrIt + u32Fls_MaxTransfer) - 1U;
    }
    return( u32Fls_MaxEndAddr );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32SectorAddrStart = 0UL;

    u32SectorAddrStart = Fls_GetSectorStartAddr(gFls_JobSectorIt);

    return(gFls_JobAddrIt - u32SectorAddrStart );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength
( CONST( Fls_AddressType, AUTOMATIC) u32MaxTransferEndAddr )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32SectorEndAddr = 0UL;
        
    /* Get last address of Fls_u32JobSectorIt sector */
   
    u32SectorEndAddr = (*(gFls_ConfigPtr->paSectorEndAddr))[gFls_JobSectorIt];  /*polyspace RTE:IDP,OBAI,NIV*/
    
    if( u32SectorEndAddr > u32MaxTransferEndAddr )
    {
        u32SectorEndAddr = u32MaxTransferEndAddr;
    }
    
    return(( u32SectorEndAddr - gFls_JobAddrIt ) + 1U );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(uint16, FLS_CODE)get_flash_block(void)
{
    VAR( uint16, AUTOMATIC) u16Fls_Block = 0U;

    CONST(Fls_PhysicalSector_Type, FLS_CONST) eFls_SectorId \
        = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt];  /*polyspace RTE:IDP,OBAI,NIV*/

    if((uint32)eFls_SectorId < FLS_MID_OFFSET)
    {
        u16Fls_Block = FLS_BLK_LOW;
    }
#if FLS_MID_BLOCK > 0U
    else if(((uint32)eFls_SectorId >= FLS_MID_OFFSET) && ((uint32)eFls_SectorId < FLS_HIGH_OFFSET))
    {
        u16Fls_Block = FLS_BLK_MID;
    }
#endif
#ifndef RESOURCE_SUPPORT_PFI
#if !defined(CCFC3008PC) && !defined(CCFC3008PCSN) && !defined(CCFC3008PCSA)
    else if(((uint32)eFls_SectorId >= FLS_HIGH_OFFSET) && ((uint32)eFls_SectorId < FLS_256K_FIRST_OFFSET))
    {
        u16Fls_Block = FLS_BLK_HIGH;
    }
#endif
    else if(((uint32)eFls_SectorId >= FLS_256K_FIRST_OFFSET) && ((uint32)eFls_SectorId < FLS_256K_SECOND_OFFSET))
    {
        u16Fls_Block = FLS_BLK_FIRST_256K;
    }
#ifdef CCFC3007PT
    else if(((uint32)eFls_SectorId >= FLS_256K_SECOND_OFFSET) && ((uint32)eFls_SectorId < FLS_BLOCK_ALL))
    {
        u16Fls_Block = FLS_BLK_SECOND_256K;
    }
#endif
#else
    else if(((uint32)eFls_SectorId >= FLS_HIGH_OFFSET) && ((uint32)eFls_SectorId < (FLS_HIGH_OFFSET + FLS_HIGH_BLOCK)))
    {
        u16Fls_Block = FLS_BLK_HIGH;
    }
#ifdef RESOURCE_SUPPORT_PFI0
    else if(((uint32)eFls_SectorId >= FLS_256K_LARGE0_OFFSET) && ((uint32)eFls_SectorId < (FLS_256K_LARGE0_OFFSET + FLS_256K_BLOCK_LARGE0)))
    {
        u16Fls_Block = FLS_BLK_LARGE0_256K;
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI1
    else if(((uint32)eFls_SectorId >= FLS_256K_LARGE1_OFFSET) && ((uint32)eFls_SectorId < (FLS_256K_LARGE1_OFFSET + FLS_256K_BLOCK_LARGE1)))
    {
        u16Fls_Block = FLS_BLK_LARGE1_256K;
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI2
    else if(((uint32)eFls_SectorId >= FLS_256K_LARGE2_OFFSET) && ((uint32)eFls_SectorId < (FLS_256K_LARGE2_OFFSET + FLS_256K_BLOCK_LARGE2)))
    {
        u16Fls_Block = FLS_BLK_LARGE2_256K;
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI3
    else if(((uint32)eFls_SectorId >= FLS_256K_LARGE3_OFFSET) && ((uint32)eFls_SectorId < (FLS_256K_LARGE3_OFFSET + FLS_256K_BLOCK_LARGE3)))
    {
        u16Fls_Block = FLS_BLK_LARGE3_256K;
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI4
    else if(((uint32)eFls_SectorId >= FLS_256K_LARGE4_OFFSET) && ((uint32)eFls_SectorId < (FLS_256K_LARGE4_OFFSET + FLS_256K_BLOCK_LARGE4)))
    {
        u16Fls_Block = FLS_BLK_LARGE4_256K;
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI5
    else if(((uint32)eFls_SectorId >= FLS_256K_LARGE5_OFFSET) && ((uint32)eFls_SectorId < FLS_BLOCK_ALL))
    {
        u16Fls_Block = FLS_BLK_LARGE5_256K;
    }
#endif
#endif
    else
    {
    	//do nothing
    }

    return u16Fls_Block;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(uint16, FLS_CODE)get_flash_block_index(VAR( uint16, AUTOMATIC) u16Fls_Block)
{
    VAR( uint16, AUTOMATIC) u16Fls_Index = 0U;

    CONST(Fls_PhysicalSector_Type, FLS_CONST) eFls_SectorId \
        = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt];  /*polyspace RTE:IDP,OBAI,NIV*/

    if(u16Fls_Block == FLS_BLK_LOW)
    {
        u16Fls_Index = (uint16)eFls_SectorId - FLS_LOW_OFFSET;
    }
    else if(u16Fls_Block == FLS_BLK_MID)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_MID_OFFSET);
    }
    else
    {
    	//do nothing
    }
    if(u16Fls_Block == FLS_BLK_HIGH)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_HIGH_OFFSET);
    }
#ifndef RESOURCE_SUPPORT_PFI
    else if(u16Fls_Block == FLS_BLK_FIRST_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_FIRST_OFFSET);
    }
    else if(u16Fls_Block == FLS_BLK_SECOND_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_SECOND_OFFSET);
    }
#else
#ifdef RESOURCE_SUPPORT_PFI0
    else if(u16Fls_Block == FLS_BLK_LARGE0_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_LARGE0_OFFSET);
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI1
    else if(u16Fls_Block == FLS_BLK_LARGE1_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_LARGE1_OFFSET);
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI2
    else if(u16Fls_Block == FLS_BLK_LARGE2_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_LARGE2_OFFSET);
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI3
    else if(u16Fls_Block == FLS_BLK_LARGE3_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_LARGE3_OFFSET);
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI4
    else if(u16Fls_Block == FLS_BLK_LARGE4_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_LARGE4_OFFSET);
    }
#endif
#ifdef RESOURCE_SUPPORT_PFI5
    else if(u16Fls_Block == FLS_BLK_LARGE5_256K)
    {
        u16Fls_Index = (uint16)((uint16)eFls_SectorId - FLS_256K_LARGE5_OFFSET);
    }
#endif
#endif
    else
    {
    	//do nothing
    }

    return u16Fls_Index;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(uint32, FLS_CODE)get_flash_offset(VAR( uint16, AUTOMATIC ) u16Fls_Block)
{
    VAR( uint32, AUTOMATIC) u32Fls_Offset = 0U;

    switch (u16Fls_Block)
    {
        case FLS_BLK_LOW:
        {
            u32Fls_Offset = FLS_LOW_OFFSET;
            break;
        }
        case FLS_BLK_MID:
        {
            u32Fls_Offset = FLS_MID_OFFSET;
            break;
        }
        case FLS_BLK_HIGH:
        {
            u32Fls_Offset = FLS_HIGH_OFFSET;
            break;
        }
#ifndef RESOURCE_SUPPORT_PFI 
        case FLS_BLK_FIRST_256K:
        {
            u32Fls_Offset = FLS_256K_FIRST_OFFSET;
            break;
        }
        case FLS_BLK_SECOND_256K:
        {
            u32Fls_Offset = FLS_256K_SECOND_OFFSET;
            break;
        }
#else
#ifdef RESOURCE_SUPPORT_PFI0
        case FLS_BLK_LARGE0_256K:
        {
            u32Fls_Offset = FLS_256K_LARGE0_OFFSET;
            break;
        }
#endif
#ifdef RESOURCE_SUPPORT_PFI1
        case FLS_BLK_LARGE1_256K:
        {
            u32Fls_Offset = FLS_256K_LARGE1_OFFSET;
            break;
        }
#endif
#ifdef RESOURCE_SUPPORT_PFI2
        case FLS_BLK_LARGE2_256K:
        {
            u32Fls_Offset = FLS_256K_LARGE2_OFFSET;
            break;
        }
#endif
#ifdef RESOURCE_SUPPORT_PFI3
        case FLS_BLK_LARGE3_256K:
        {
            u32Fls_Offset = FLS_256K_LARGE3_OFFSET;
            break;
        }
#endif
#ifdef RESOURCE_SUPPORT_PFI4
        case FLS_BLK_LARGE4_256K:
        {
            u32Fls_Offset = FLS_256K_LARGE4_OFFSET;
            break;
        }
#endif
#ifdef RESOURCE_SUPPORT_PFI5
        case FLS_BLK_LARGE5_256K:
        {
            u32Fls_Offset = FLS_256K_LARGE5_OFFSET;
            break;
        }
#endif
#endif
        default:
        {
            //do nothing
            break;
        }
    }

    return u32Fls_Offset;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(status_t, FLS_CODE) Fls_Wrapper_InitController(void) 
{
    VAR(status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;

    sFls_Ret = FLASH_SDK_LLD_Init();

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_EraseController(void)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( MemIf_JobResultType, AUTOMATIC) eFls_RetVal = MEMIF_JOB_PENDING;
    VAR( uint16, AUTOMATIC) u16Fls_FlashBlock = FLS_BLK_LOW;
    VAR( uint16, AUTOMATIC) u16Fls_FashSector = 0U;
    VAR( uint32, AUTOMATIC) u8Fls_offset = 0U;
    VAR( uint16, AUTOMATIC ) bFls_Mode = 0U;
#if( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
    VAR( uint32, AUTOMATIC) u32Fls_Dest = 0U;                 /* destination address */
#endif
    VAR( uint32, AUTOMATIC) u32Fls_Size = 0U;                 /* u32Fls_Size applicable */

    if( gFls_JobSectorIt > gFls_JobSectorEnd )
    {
        eFls_RetVal = MEMIF_JOB_OK;
        gFls_SubJobStatus = FLS_JOB_COMPLETED;
    }
    else
    {
        u16Fls_FlashBlock = get_flash_block();
        u16Fls_FashSector = get_flash_block_index(u16Fls_FlashBlock);
        u8Fls_offset = get_flash_offset(u16Fls_FlashBlock);
        u32Fls_Size = flashInfo[u8Fls_offset + u16Fls_FashSector].blockSize;  /* polyspace RTE:OBAI*/
        if( ((*(gFls_ConfigPtr->paSectorFlags))[gFls_JobSectorIt] & (FLS_SECTOR_ERASE_ASYNCH)) != 0U )  /*polyspace RTE:IDP,OBAI,NIV*/
        {
            bFls_Mode = FLS_OP_ASYNC;
        }
        else
        {
            bFls_Mode = FLS_OP_SYNC;
        }
        sFls_Ret = FLS_SDK_Erase(u16Fls_FlashBlock,u16Fls_FashSector,bFls_Mode);
        if( STATUS_SUCCESS != sFls_Ret )
        {
        	if(sFls_Ret == STATUS_FLASH_INPROGRESS)
        	{
        		eFls_RetVal = MEMIF_JOB_PENDING;
                gFls_SubJobStatus = FLS_JOB_PENDING;
        		return eFls_RetVal;
        	}
        	else
        	{
        		eFls_RetVal = MEMIF_JOB_FAILED;
                gFls_SubJobStatus = FLS_JOB_FAILED;
        		 return eFls_RetVal;
        	}
        }
        
    #if( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
        u32Fls_Dest = flashInfo[u8Fls_offset + u16Fls_FashSector].addrStart;  /* polyspace RTE:OBAI*/
        sFls_Ret = Fls_LLD_VerifyErase((uint32 *)u32Fls_Dest,u32Fls_Size);

        if( STATUS_SUCCESS != sFls_Ret )
        {
            eFls_RetVal = MEMIF_JOB_FAILED;
            gFls_SubJobStatus = FLS_JOB_FAILED;
            return eFls_RetVal;
        }
    #endif
        

        gFls_JobAddrIt += u32Fls_Size;
    }

    if( sFls_Ret != STATUS_SUCCESS ) /* PRQA S 2996, 2992 */
    {
        eFls_RetVal = MEMIF_JOB_FAILED;
        gFls_SubJobStatus = FLS_JOB_FAILED;
    }   
    else if(( gFls_JobSectorIt == gFls_JobSectorEnd ) && 
            ( sFls_Ret == STATUS_SUCCESS ) /* PRQA S 2995 */
            )
    {
        eFls_RetVal = MEMIF_JOB_OK;
        gFls_SubJobStatus = FLS_JOB_COMPLETED;
        #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
        u32Fls_TimerCounterAC = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
        #endif
    }
    else
    {
        gFls_JobSectorIt++;
        gFls_SubJobStatus = FLS_JOB_COMPLETED;
    }

    return eFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_WriteController(void)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( MemIf_JobResultType, AUTOMATIC) eFls_RetVal = MEMIF_JOB_PENDING;
    static VAR( fls_ctxdata_t, AUTOMATIC) pFls_CtxData ={0};
    VAR( uint8, AUTOMATIC) u8Fls_OpRet;
    static VAR( uint32, AUTOMATIC) u32Fls_Dest = 0U;                 /* destination address */
    static VAR( uint32, AUTOMATIC) u32Fls_Size = 0U;                 /* u32Fls_Size applicable */
    VAR( uint32, AUTOMATIC) u32Fls_Src = 0U;               /* source address for program and verify */
    VAR( uint16, AUTOMATIC ) bFls_Mode = 0U;
    VAR( Fls_PhysicalSector_Type, AUTOMATIC) u32Fls_PhyIndex = FLS_DATA_L0;
    VAR( uint32, AUTOMATIC) u32Fls_PhyStartAddr = 0U; 
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_MaxEndAddr = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_SectorTransferOffset = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_SectorTransferLength = 0UL;
    
    sFls_Ret = FLASH_SDK_LLD_CheckProgramStatus(&pFls_CtxData, &u8Fls_OpRet);
    if((sFls_Ret == STATUS_SUCCESS) && (FLS_OK == u8Fls_OpRet))
    {
        #if( FLS_WRITE_VERIFICATION_ENABLED == STD_ON )
			sFls_Ret = Fls_LLD_VerifyWrite((uint32 *)u32Fls_Dest,(const uint32 *)(gFls_JobDataSrcPtr),u32Fls_Size);
			if( STATUS_SUCCESS != sFls_Ret )
			{
				eFls_RetVal = MEMIF_JOB_FAILED;
                gFls_SubJobStatus = FLS_JOB_FAILED;
				return eFls_RetVal;
			}
        #endif
     
            gFls_JobDataSrcPtr += u32Fls_Size;
            gFls_JobAddrIt += u32Fls_Size;
            gFls_SubJobStatus = FLS_JOB_COMPLETED;

            if( (gFls_JobAddrIt > ((*(gFls_ConfigPtr->paSectorEndAddr))[gFls_JobSectorIt]) ))   /* polyspace RTE:OBAI,IDP,NIV*/  
            {
                /* Move on to the next sector */
                gFls_JobSectorIt++;
            }
    }
    else if(sFls_Ret == STATUS_FLASH_INPROGRESS)
    {
		eFls_RetVal = MEMIF_JOB_PENDING;
        gFls_SubJobStatus = FLS_JOB_PENDING;
		return eFls_RetVal;

    }
    else if(sFls_Ret ==  STATUS_INITIALIZED)
    {
		if( gFls_JobSectorIt > gFls_JobSectorEnd )
		{
			eFls_RetVal = MEMIF_JOB_OK;
            gFls_SubJobStatus = FLS_JOB_COMPLETED;
		}
		else
		{
			u32Fls_MaxEndAddr = Fls_MaxTransferEndAddr(gFls_MaxWrite);
      
        /* Move on to the next sector */
           
            if(gFls_JobAddrIt <= u32Fls_MaxEndAddr)
            {

                u32Fls_SectorTransferOffset = Fls_CalcSectorTransferOffset();
                u32Fls_SectorTransferLength = Fls_CalcSectorTransferLength( u32Fls_MaxEndAddr );

                u32Fls_PhyIndex = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt]; /*polyspace RTE:IDP,OBAI,NIV*/
                if(u32Fls_PhyIndex >= FLS_BLOCK_ALL) // is array index may be outside bounds
                {
                    eFls_RetVal = MEMIF_JOB_FAILED;
                    gFls_SubJobStatus = FLS_JOB_FAILED;
                    return eFls_RetVal;
                }
                else
                {
                    
                }
                u32Fls_PhyStartAddr = flashInfo[u32Fls_PhyIndex].addrStart;
                u32Fls_Dest = u32Fls_PhyStartAddr + u32Fls_SectorTransferOffset;
                u32Fls_Size = u32Fls_SectorTransferLength;
                u32Fls_Src = (uint32)gFls_JobDataSrcPtr;

                if( ((*(gFls_ConfigPtr->paSectorFlags))[gFls_JobSectorIt] & (FLS_PAGE_WRITE_ASYNCH)) != 0U ) /*polyspace RTE:IDP,OBAI,NIV*/
                {
                    bFls_Mode = FLS_OP_ASYNC;
                }
                else
                {
                    bFls_Mode = FLS_OP_SYNC;
                }
                /* Call FLASH_LLD_Program to start program */
                pFls_CtxData.u32Fls_Dest = u32Fls_Dest;
                pFls_CtxData.u32Fls_Src = u32Fls_Src;
                pFls_CtxData.u32Fls_Size = u32Fls_Size;
                pFls_CtxData.u32Fls_Mode = bFls_Mode;

            #if( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
                sFls_Ret = Fls_LLD_VerifyErase((const uint32 *)u32Fls_Dest,u32Fls_Size);

                if( STATUS_SUCCESS != sFls_Ret )
                {
                    eFls_RetVal = MEMIF_JOB_FAILED;
                    gFls_SubJobStatus = FLS_JOB_FAILED;
                    return eFls_RetVal;
                }
            #endif

                sFls_Ret = FLASH_SDK_LLD_Program(&pFls_CtxData);
                if (STATUS_SUCCESS != sFls_Ret)
                {
                    eFls_RetVal = MEMIF_JOB_FAILED;
                    gFls_SubJobStatus = FLS_JOB_FAILED;
                    return eFls_RetVal;
                }
            }
        }
            
        
    }
    else
    {
    	eFls_RetVal = MEMIF_JOB_FAILED;
        gFls_SubJobStatus = FLS_JOB_FAILED;
    	return eFls_RetVal;
    }

                
    if( sFls_Ret != STATUS_SUCCESS ) /* PRQA S 2996, 2992 */
    {
            eFls_RetVal = MEMIF_JOB_FAILED;
            gFls_SubJobStatus = FLS_JOB_FAILED;
    }   
    else if(( gFls_JobAddrIt > gFls_JobAddrEnd ) && 
            ( sFls_Ret == STATUS_SUCCESS ) /* PRQA S 2995 */
            )
    {
        #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
        #endif
        eFls_RetVal = MEMIF_JOB_OK;
        gFls_SubJobStatus = FLS_JOB_COMPLETED;
    }
    else
    {
        /* The write operation is either pending (FLASH_E_PENDING) */
    }

    return eFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_ReadController(void)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( MemIf_JobResultType, AUTOMATIC) eFls_RetVal = MEMIF_JOB_PENDING;
    VAR( uint32, AUTOMATIC) u32Fls_Dest = 0U;                 /* destination address */
    VAR( uint32, AUTOMATIC) u32Fls_Size = 0U;                 /* u32Fls_Size applicable */
    VAR( uint32, AUTOMATIC) u32Fls_MaxEndAddr = 0U;
    VAR( Fls_PhysicalSector_Type, AUTOMATIC) u32Fls_PhyIndex = FLS_DATA_L0;
    VAR( uint32, AUTOMATIC) u32Fls_PhyStartAddr = 0U; 
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_SectorTransferOffset = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_SectorTransferLength = 0UL;

    u32Fls_MaxEndAddr = Fls_MaxTransferEndAddr(gFls_MaxRead);
    
    if( gFls_JobSectorIt > gFls_JobSectorEnd )
    {
        eFls_RetVal = MEMIF_JOB_OK;
    }
    else
    {
        do
        {
            u32Fls_SectorTransferOffset = Fls_CalcSectorTransferOffset();
            u32Fls_SectorTransferLength = Fls_CalcSectorTransferLength( u32Fls_MaxEndAddr ); 
            u32Fls_PhyIndex = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt];  /*polyspace RTE:IDP,OBAI,NIV*/
            if(u32Fls_PhyIndex >= FLS_BLOCK_ALL)    // is array index may be outside bounds 
            {
                eFls_RetVal = MEMIF_JOB_FAILED;
                return eFls_RetVal;
            }
            else
            {
                
            }
            u32Fls_PhyStartAddr = flashInfo[u32Fls_PhyIndex].addrStart;
            u32Fls_Dest = u32Fls_PhyStartAddr + u32Fls_SectorTransferOffset;
            u32Fls_Size = u32Fls_SectorTransferLength;
            sFls_Ret = FLS_SDK_Read(u32Fls_Dest,u32Fls_Size,gFls_JobDataDestPtr);

            if (STATUS_SUCCESS != sFls_Ret)
            {
                eFls_RetVal = MEMIF_JOB_FAILED;
                return eFls_RetVal;
            }

            gFls_JobDataDestPtr += u32Fls_Size;
            gFls_JobAddrIt += u32Fls_Size;
            if ( (0U == ((*(gFls_ConfigPtr->paSectorFlags))[gFls_JobSectorIt] & FLS_PAGE_WRITE_ASYNCH))  ||    /*polyspace RTE:IDP,OBAI,NIV*/
                   (FLS_JOB_READ == gFls_Job ) )
            {
                if( (gFls_JobAddrIt > (*(gFls_ConfigPtr->paSectorEndAddr))[gFls_JobSectorIt]))  /*polyspace RTE:IDP,OBAI,NIV*/
                {
                    /* Move on to the next sector */
                    gFls_JobSectorIt++;        
                }
            }
        } while(gFls_JobAddrIt <= u32Fls_MaxEndAddr);
    }

    if( sFls_Ret != STATUS_SUCCESS ) /* PRQA S 2992, 2996 */
    {
        eFls_RetVal = MEMIF_JOB_FAILED;
    }   
    else if(( gFls_JobAddrIt > gFls_JobAddrEnd ) && 
            ( sFls_Ret == STATUS_SUCCESS ) /* PRQA S 2995 */
            )
    {
        eFls_RetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* The write operation is either pending (FLASH_E_PENDING) */
    }
    
    return eFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_CompareController(void)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( MemIf_JobResultType, AUTOMATIC) eFls_RetVal = MEMIF_JOB_PENDING;
    VAR( uint32, AUTOMATIC) u32Fls_Dest = 0U;                 /* destination address */
    VAR( uint32, AUTOMATIC) u32Fls_Size = 0U;                 /* u32Fls_Size applicable */
    VAR( uint32, AUTOMATIC) u32Fls_Src = 0U;               /* source address for program and verify */
    VAR( Fls_PhysicalSector_Type, AUTOMATIC) u32Fls_PhyIndex = FLS_DATA_L0;
    VAR( uint32, AUTOMATIC) u32Fls_PhyStartAddr = 0U; 
    VAR( uint32, AUTOMATIC) u32Fls_FailedAddress = 0U;
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_MaxEndAddr = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_SectorTransferOffset = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_SectorTransferLength = 0UL;

    u32Fls_MaxEndAddr = Fls_MaxTransferEndAddr(gFls_MaxRead);
    
    if( gFls_JobSectorIt > gFls_JobSectorEnd )
    {
        eFls_RetVal = MEMIF_JOB_OK;
    }
    else
    {
        do
        {
            u32Fls_SectorTransferOffset = Fls_CalcSectorTransferOffset();
            u32Fls_SectorTransferLength = Fls_CalcSectorTransferLength( u32Fls_MaxEndAddr );
            u32Fls_PhyIndex = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt];  /*polyspace RTE:IDP,OBAI,NIV*/
            if(u32Fls_PhyIndex >= FLS_BLOCK_ALL)   // is array index may be outside bounds 
            {
                eFls_RetVal = MEMIF_JOB_FAILED;
                return eFls_RetVal;
            }
            u32Fls_PhyStartAddr = flashInfo[u32Fls_PhyIndex].addrStart;
            u32Fls_Dest = u32Fls_PhyStartAddr + u32Fls_SectorTransferOffset;
            u32Fls_Size = u32Fls_SectorTransferLength;
            u32Fls_Src = (uint32)gFls_JobDataSrcPtr;

            /* Call FLASH_LLD_ProgramVerify to check program data is right or not*/
            sFls_Ret = FLASH_LLD_ProgramVerify(u32Fls_Dest, \
                                            u32Fls_Size, \
                                            u32Fls_Src, \
                                            NUM_WORD_FOR_PGM_VERIFY, \
                                            &u32Fls_FailedAddress);

            if (STATUS_SUCCESS != sFls_Ret)
            {
                eFls_RetVal = MEMIF_JOB_FAILED;
                return eFls_RetVal;
            }

            gFls_JobDataSrcPtr += u32Fls_Size;
            gFls_JobAddrIt += u32Fls_Size;
            if ( (0U == ((*(gFls_ConfigPtr->paSectorFlags))[gFls_JobSectorIt] & FLS_PAGE_WRITE_ASYNCH))  ||    /*polyspace RTE:IDP,OBAI,NIV*/
                    (FLS_JOB_COMPARE == gFls_Job ) )
            {
                if( (gFls_JobAddrIt > (*(gFls_ConfigPtr->paSectorEndAddr))[gFls_JobSectorIt]))  /*polyspace RTE:IDP,OBAI,NIV*/
                {
                    /* Move on to the next sector */
                    gFls_JobSectorIt++;        
                }
            }

        } while(gFls_JobAddrIt <= u32Fls_MaxEndAddr);
    }
    
    if( sFls_Ret != STATUS_SUCCESS ) /* PRQA S 2996, 2992 */
    {
        eFls_RetVal = MEMIF_JOB_FAILED;
    }   
    else if(( gFls_JobAddrIt > gFls_JobAddrEnd ) && 
            ( sFls_Ret == STATUS_SUCCESS ) /* PRQA S 2995 */
            )
    {
        eFls_RetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* The write operation is either pending (FLASH_E_PENDING) */
    }

    return eFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_BlankCheckController(void)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( MemIf_JobResultType, AUTOMATIC) eFls_RetVal = MEMIF_JOB_PENDING;
    VAR( uint32, AUTOMATIC) u32Fls_Dest = 0U;                 /* destination address */
    VAR( uint32, AUTOMATIC) u32Fls_Size = 0U;                 /* u32Fls_Size applicable */
    VAR( Fls_PhysicalSector_Type, AUTOMATIC) u32Fls_PhyIndex = FLS_DATA_L0;
    VAR( uint32, AUTOMATIC) u32Fls_FailedAddress = 0U;

    if( gFls_JobAddrIt >= gFls_JobAddrEnd )
    {
        eFls_RetVal = MEMIF_JOB_OK;
    }
    else
    {
        u32Fls_PhyIndex = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt];  /*polyspace RTE:IDP,OBAI,NIV*/
        if(u32Fls_PhyIndex >= FLS_BLOCK_ALL)   // is array index may be outside bounds 
        {
            eFls_RetVal = MEMIF_JOB_FAILED;
            return eFls_RetVal;
        }
		u32Fls_Dest = flashInfo[u32Fls_PhyIndex].addrStart + Fls_CalcSectorTransferOffset();
		u32Fls_Size = ((gFls_JobAddrEnd - gFls_JobAddrIt) + 1U) ;

        /* Call FLASH_LLD_BlankCheck to check erase data is right or not */
        sFls_Ret = FLASH_LLD_BlankCheck(u32Fls_Dest, \
                                    u32Fls_Size, \
                                    NUM_WORD_FOR_BLANK_CHECK, \
                                    &u32Fls_FailedAddress);
    }

    if( sFls_Ret != STATUS_SUCCESS )
    {
        eFls_RetVal = MEMIF_JOB_FAILED;
    }   
    else if(( gFls_JobAddrIt >= gFls_JobAddrEnd ) &&
            ( sFls_Ret == STATUS_SUCCESS ) /* PRQA S 2995 */
            )
    {
        eFls_RetVal = MEMIF_JOB_OK;
    }
    else
    {
        /*Nothing to do*/
    }

    return eFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Wrapper_CancelController(void)
{
    (void)FLASH_SDK_LLD_Abort();
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Wrapper_Lock(void)
{
    (void)Fls_LLD_Lock();
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Wrapper_Unlock(VAR( uint32, AUTOMATIC) u32Fls_Dest,VAR(uint32,AUTOMATIC)  u32Fls_EndAddr)
{
    Fls_LLD_Unlock(u32Fls_Dest,u32Fls_EndAddr);
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
