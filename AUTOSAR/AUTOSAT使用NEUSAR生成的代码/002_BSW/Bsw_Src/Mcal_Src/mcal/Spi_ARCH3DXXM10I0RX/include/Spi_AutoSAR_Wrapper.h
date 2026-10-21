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
*   @file    Spi_AutoSAR_Wrapper.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of SPI MCAL driver.
*
*   @addtogroup Spi
*   @{
*/

#ifndef SPI_AUTOSAR_WRAPPER_H
#define SPI_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Spi.h"
#include "Spi_LLDriver.h"

#define SPI_ATS_WRA_H_VENDOR_ID                     176
#define SPI_ATS_WRA_H_AR_REL_MAJOR_VER              4
#define SPI_ATS_WRA_H_AR_REL_MINOR_VER              4
#define SPI_ATS_WRA_H_AR_REL_REV_VER                0
#define SPI_ATS_WRA_H_SW_MAJOR_VER                  3
#define SPI_ATS_WRA_H_SW_MINOR_VER                  0
#define SPI_ATS_WRA_H_SW_PATCH_VER                  0

#if (SPI_CFG_VENDOR_ID != SPI_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_VENDOR_ID "
#endif
#if (SPI_CFG_AR_MAJOR_VER != SPI_ATS_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (SPI_CFG_AR_MINOR_VER != SPI_ATS_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_AR_REL_MINOR_VER "
#endif
#if (SPI_CFG_AR_PATCH_VER != SPI_ATS_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_AR_REL_REV_VER "
#endif
#if (SPI_CFG_SW_MAJOR_VER != SPI_ATS_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_SW_MAJOR_VER "
#endif
#if (SPI_CFG_SW_MINOR_VER != SPI_ATS_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_SW_MINOR_VER "
#endif
#if (SPI_CFG_SW_PATCH_VER != SPI_ATS_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SPI_ATS_WRA_H_SW_PATCH_VER "
#endif

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE)Spi_Wrap_Init ( VAR(uint8, AUTOMATIC)HwUnitIdx );
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE)Spi_Wrap_DeInit( VAR(uint8, AUTOMATIC)HwUnitIdx );
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_0) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_Wrap_SyncTransmit \
( \
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CODE) Spi_JobConfigPtr \
);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(Std_ReturnType, SPI_CODE) Spi_Wrap_AsyncTransmit \
( \
    P2CONST(Spi_JobCfgType, AUTOMATIC, SPI_APPL_CODE) Spi_JobConfigPtr \
);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
FUNC(void, SPI_CODE) Spi_AsyncHandle(
    P2VAR(Spi_HandleType, AUTOMATIC, SPI_APPL_DATA) Spi_HandlePtr);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#define Spi_Wrap_MainFunc dspi_MainFunc
#endif

#ifdef __cplusplus
}
#endif
#endif
