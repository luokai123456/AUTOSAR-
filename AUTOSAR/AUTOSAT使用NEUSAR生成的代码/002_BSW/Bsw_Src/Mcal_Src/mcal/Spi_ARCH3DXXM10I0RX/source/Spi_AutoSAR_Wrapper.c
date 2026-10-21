/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : SPI
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
*   @file    Spi_AutoSAR_Wrapper.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of SPI MCAL driver.
*
*   @addtogroup Spi
*   @{
*/
/*PRQA S 0380,3432 EOF*/
/*PRQA S 0488,0491,1258,2844,2934,1821,4532,4523,1821,1580,1520 EOF*/ /*QAC_CWE*/
#ifdef __cplusplus
extern "C"{
#endif

#include "Spi_AutoSAR_Wrapper.h"
#include "Spi_LLDriver.h"
#if(SPI_DMA_USED == STD_ON)
#include "eDma.h"
#endif

#define SPI_ATS_WRA_C_VENDOR_ID                     176
#define SPI_ATS_WRA_C_AR_REL_MAJOR_VER              4
#define SPI_ATS_WRA_C_AR_REL_MINOR_VER              4
#define SPI_ATS_WRA_C_AR_REL_REV_VER                0
#define SPI_ATS_WRA_C_SW_MAJOR_VER                  3
#define SPI_ATS_WRA_C_SW_MINOR_VER                  0
#define SPI_ATS_WRA_C_SW_PATCH_VER                  0

#if (SPI_CFG_VENDOR_ID != SPI_ATS_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_VENDOR_ID "
#endif
#if (SPI_CFG_AR_MAJOR_VER != SPI_ATS_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (SPI_CFG_AR_MINOR_VER != SPI_ATS_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_AR_REL_MINOR_VER "
#endif
#if (SPI_CFG_AR_PATCH_VER != SPI_ATS_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_AR_REL_REV_VER "
#endif
#if (SPI_CFG_SW_MAJOR_VER != SPI_ATS_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_SW_MAJOR_VER "
#endif
#if (SPI_CFG_SW_MINOR_VER != SPI_ATS_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_SW_MINOR_VER "
#endif
#if (SPI_CFG_SW_PATCH_VER != SPI_ATS_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_C_SW_PATCH_VER "
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE)Spi_Wrap_Init ( VAR(uint8, AUTOMATIC)HwUnitIdx )
{
    // Interrupts are disabled
    dspi_Disable((uint8)HwUnitIdx);
    dspi_Enable((uint8)HwUnitIdx);
    // Interrupts are disabled
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE)Spi_Wrap_DeInit ( VAR(uint8, AUTOMATIC)HwUnitIdx )
{
    // Interrupts are disabled
    dspi_Disable((uint8)HwUnitIdx);
    // Interrupts are disabled
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE)Spi_Job_DataInit (
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CONST) Spi_JobConfigPtr, 
    P2VAR(Spi_HandleType, AUTOMATIC, SPI_APPL_DATA) Spi_HandlePtr)
{
    Spi_HandlePtr->HwDevice = Spi_JobConfigPtr->HwDevice;/* polyspace RTE:NIV,IDP */
    Spi_HandlePtr->Ctar = (uint32)( Spi_JobConfigPtr->Ctar |/* polyspace RTE:NIV */
                                    (Spi_JobConfigPtr->ClockPolarity << 26U) |/* polyspace RTE:NIV */
                                    (Spi_JobConfigPtr->ClockShift << 25U) );/* polyspace RTE:NIV */

    Spi_HandlePtr->Pcs_Idle = (uint8)Spi_JobConfigPtr->CSPolarity;/* polyspace RTE:NIV */
    if(Spi_JobConfigPtr->CSFunc == TRUE)/* polyspace RTE:NIV */
    {
        Spi_HandlePtr->PushCmd = ((uint16)Spi_JobConfigPtr->CSPin | Spi_JobConfigPtr->CSCountinue );/* polyspace RTE:NIV */
    }
    else
    {
        Spi_HandlePtr->PushCmd = 0U;
    }
    Spi_HandlePtr->LastChannel = 0U;
    #if (SPI_DMA_USED == STD_ON)
    Spi_HandlePtr->Spi_DmaEnable = Spi_JobConfigPtr->JobDmaEn;
    #endif
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_INLINE FUNC(void, SPI_CODE)Spi_Channel_DataInit ( 
    P2CONST(Spi_ChannelCfgType, AUTOMATIC, SPI_APPL_CONST) Spi_ChannelConfigPtr,
    P2VAR(Spi_HandleType, AUTOMATIC, SPI_APPL_DATA) Spi_HandlePtr )
{
	Spi_HandlePtr->FrameSize = Spi_ChannelConfigPtr->DataWidth;/* polyspace RTE:NIV,IDP */
	if(Spi_HandlePtr->FrameSize > (uint8)16U)
	{
		Spi_HandlePtr->Ctar &= ~((uint32)0x0FU << 27U);
		Spi_HandlePtr->Ctar |= (((uint32)Spi_HandlePtr->FrameSize - 17U) << 27U);
	}
	else
	{
		Spi_HandlePtr->Ctar &= ~((uint32)0x0FU << 27U);
		Spi_HandlePtr->Ctar |= (((uint32)Spi_HandlePtr->FrameSize - 1U ) << 27U);
	}

    if((uint8)Spi_ChannelConfigPtr->TransferType == 1U)/* polyspace RTE:NIV */
    {
        /* SET CTARx.LSBFE */
    	Spi_HandlePtr->Ctar |= 0x01000000U;
    }
    else
    {
    	Spi_HandlePtr->Ctar &= ~0x01000000U;
    }

    if(Spi_ChannelConfigPtr->ChannelBufferType == IB)/* polyspace RTE:NIV */
    {
		#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
    	Spi_HandlePtr->Spi_DataLength = Spi_ChannelConfigPtr->BufferSize;/* polyspace RTE:NIV */
        Spi_HandlePtr->Spi_TranBufPtr = (uint8 *)Spi_ChannelConfigPtr->WriteBuffer;/* polyspace RTE:NIP */
        Spi_HandlePtr->Spi_RecBufPtr = (uint8 *)Spi_ChannelConfigPtr->ReadBuffer;/* polyspace RTE:NIP */
		#endif
    }
    else
    {
        #if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0x1) || (SPI_CHANNEL_BUFFERS_ALLOWED == 0x2))
        Spi_HandlePtr->Spi_DataLength = Spi_ChannelConfigPtr->EB_Buffer->Length;/* polyspace RTE:NIV,NIP,IDP */
        if(Spi_ChannelConfigPtr->DataWidth > 16U)
        {
        	if(Spi_ChannelConfigPtr->EB_Buffer->WriteBuffer == NULL_PTR)/* polyspace RTE:NIP */
        	{
        		Spi_HandlePtr->Spi_TranBufPtr = (uint8 *)NULL_PTR;
        		Spi_HandlePtr->Spi_RecBufPtr = (uint8 *)Spi_ChannelConfigPtr->EB_Buffer->ReadBuffer;/* polyspace RTE:NIP */
        	}
        	else
        	{
        		Spi_HandlePtr->Spi_TranBufPtr = (uint8 *)Spi_ChannelConfigPtr->EB_Buffer->WriteBufferReverse;/* polyspace RTE:NIP */
        		Spi_HandlePtr->Spi_RecBufPtr = (uint8 *)Spi_ChannelConfigPtr->EB_Buffer->ReadBuffer;/* polyspace RTE:NIP */
        	}
        }
        else
        {
        	Spi_HandlePtr->Spi_TranBufPtr = (uint8 *)Spi_ChannelConfigPtr->EB_Buffer->WriteBuffer;/* polyspace RTE:NIP */
        	Spi_HandlePtr->Spi_RecBufPtr = (uint8 *)Spi_ChannelConfigPtr->EB_Buffer->ReadBuffer;/* polyspace RTE:NIP */
        }
        #endif
    }
    /* Setting Default Transmit Data */
    Spi_HandlePtr->TranDefaultData = Spi_ChannelConfigPtr->DefaultValue;/* polyspace RTE:NIV */
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
FUNC(Std_ReturnType, SPI_CODE) Spi_Wrap_SyncTransmit(
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CODE) Spi_JobConfigPtr )
{
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    P2VAR(Spi_HandleType, SPI_VAR, SPI_APPL_DATA) Spi_HandlePtr;
    /* Channel Config */
    P2CONST(Spi_ChannelCfgType, SPI_VAR, SPI_APPL_CONST) Spi_ChannelConfigPtr;
    /* Channel Index */
    VAR(Spi_ChannelType, SPI_VAR)u8Spi_ChannelIdx;

    Spi_HandlePtr = &Spi_gHandle[Spi_JobConfigPtr->HwDeviceIdx];

    Spi_Job_DataInit(Spi_JobConfigPtr, Spi_HandlePtr);
    Spi_Job_HwInit(Spi_HandlePtr);

    for(u8Spi_ChannelIdx = 0U; u8Spi_ChannelIdx < Spi_JobConfigPtr->NoOfChannels; u8Spi_ChannelIdx++)
    {
        if((u8Spi_ChannelIdx + 1U )== Spi_JobConfigPtr->NoOfChannels)
        {
            Spi_HandlePtr->LastChannel = 1U;
        }
        Spi_ChannelConfigPtr = (const Spi_ChannelCfgType *)&Spi_ConfigPtr-> \
            ChannelConfiguration[Spi_JobConfigPtr->ChannelList[u8Spi_ChannelIdx]];/* polyspace RTE:NIV,NIP,IDP */
        Spi_Channel_DataInit(Spi_ChannelConfigPtr, Spi_HandlePtr);
        Spi_Channel_HwInit(Spi_HandlePtr);

        dspi_TransmitReceive_polling(Spi_HandlePtr,
        		                     Spi_HandlePtr->Spi_TranBufPtr,
									 Spi_HandlePtr->Spi_RecBufPtr,
									 Spi_HandlePtr->Spi_DataLength);
    }
    dspi_TransmitEnd(Spi_HandlePtr);
    return (Std_ReturnType)E_OK;
}
#endif
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_Wrap_AsyncTransmit (
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CODE) Spi_JobConfigPtr )
{
    P2VAR(Spi_HandleType, SPI_VAR, SPI_APPL_DATA) Spi_HandlePtr;

    Spi_HandlePtr = &Spi_gHandle[Spi_JobConfigPtr->HwDeviceIdx];

    Spi_Job_DataInit(Spi_JobConfigPtr, Spi_HandlePtr);
    Spi_Job_HwInit(Spi_HandlePtr);

    #if(SPI_DMA_USED == STD_ON)
    if(Spi_JobConfigPtr->JobDmaEn == TRUE)
    {
        dspi_DmaInit(Spi_HandlePtr);
    }
    #endif

    Spi_HandlePtr->CurrentChannel = 0U;
    Spi_AsyncHandle( Spi_HandlePtr );
    return (Std_ReturnType)E_OK;
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_AsyncHandle(
    P2VAR(Spi_HandleType, AUTOMATIC, SPI_APPL_DATA) Spi_HandlePtr)
{
    P2CONST(Spi_ChannelCfgType, SPI_VAR, SPI_APPL_CONST) Spi_ChannelConfigPtr;
    /* Spi Global Configuration */
    P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_ConfigPtr = Spi_gConfigPtr;
    /* Job Configuration */
    P2CONST(Spi_JobCfgType, SPI_VAR, SPI_APPL_CODE) Spi_JobConfigPtr
        = &Spi_ConfigPtr->JobConfiguration[/* polyspace RTE:IDP */
            Spi_ConfigPtr->SequenceConfiguration[/* polyspace RTE:IDP */
                Spi_HandlePtr->Spi_AsyncSchePtr->SequenceId/* polyspace RTE:NIV,IDP */
            ].JobList[Spi_HandlePtr->Spi_AsyncSchePtr->Current_Job] ];/* polyspace RTE:NIV,NIP,IDP */

    if(Spi_HandlePtr->CurrentChannel < Spi_JobConfigPtr->NoOfChannels)/* polyspace RTE:NIV,IDP */
    {
        if((Spi_HandlePtr->CurrentChannel + 1U) == Spi_JobConfigPtr->NoOfChannels)
        {
            Spi_HandlePtr->LastChannel = 1U;
        }
        /* Channel Configuration */
        Spi_ChannelConfigPtr = &Spi_ConfigPtr->ChannelConfiguration[
            Spi_JobConfigPtr->ChannelList[Spi_HandlePtr->CurrentChannel] ];/* polyspace RTE:NIV,NIP,IDP */

        Spi_Channel_DataInit(Spi_ChannelConfigPtr, Spi_HandlePtr);
        Spi_Channel_HwInit(Spi_HandlePtr);

        Spi_HandlePtr->CurrentChannel++;
        #if(SPI_DMA_USED == STD_ON)
        if(Spi_JobConfigPtr->JobDmaEn == TRUE)
        {
            dspi_TransmitReceive_dma ( Spi_HandlePtr,
            		                   Spi_HandlePtr->Spi_TranBufPtr,
									   Spi_HandlePtr->Spi_RecBufPtr,
									   Spi_HandlePtr->Spi_DataLength );
        }
        else
        #endif
        {
        	dspi_TransmitReceive_interrupt(Spi_HandlePtr);
        }
    }
    else
    {
        #if(SPI_DMA_USED == STD_ON)
        if(Spi_JobConfigPtr->JobDmaEn == TRUE)
        {
            dspi_TransmitEndDma( Spi_HandlePtr );
        }
        else
        #endif
        {
            dspi_TransmitEndInt( Spi_HandlePtr );
        }
        Spi_AsyncSchedulerMain( Spi_HandlePtr );
    }
}
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif
