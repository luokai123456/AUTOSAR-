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
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Spi_Irq.h
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Spi
*   @{
*/

#ifndef SPI_IRQ_H
#define SPI_IRQ_H
#ifdef __cplusplus
extern "C"{
#endif

#include "Spi_LLDriver.h"


/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IRQ_H_VENDOR_ID                   176
#define SPI_IRQ_H_AR_MAJOR_VER                4
#define SPI_IRQ_H_AR_MINOR_VER                4
#define SPI_IRQ_H_AR_PATCH_VER                0
#define SPI_IRQ_H_SW_MAJOR_VER                3
#define SPI_IRQ_H_SW_MINOR_VER                0
#define SPI_IRQ_H_SW_PATCH_VER                0
#define SPI_IRQ_H_MODULE_ID                   83
/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_IRQ_H_VENDOR_ID != SPI_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_IRQ_H_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_IRQ_H_AR_MAJOR_VER != SPI_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_H_AR_MAJOR_VER"
#endif
#if (SPI_IRQ_H_AR_MINOR_VER != SPI_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_H_AR_MINOR_VER"
#endif
#if (SPI_IRQ_H_AR_PATCH_VER != SPI_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SPI_IRQ_H_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_IRQ_H_SW_MAJOR_VER != SPI_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_H_SW_MAJOR_VER"
#endif
#if (SPI_IRQ_H_SW_MINOR_VER != SPI_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SPI_IRQ_H_SW_MINOR_VER"
#endif
#if (SPI_IRQ_H_SW_PATCH_VER != SPI_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SPI_IRQ_H_SW_PATCH_VER"
#endif


#if ((SPI_LEVEL_DELIVERED == SPI_LEVEL_1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL_2))
#ifdef RESOURCE_SUPPORT_DSPI_0
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_0_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_1
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_1_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_2
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_2_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_3
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_3_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_4
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_4_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_5
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_5_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_6
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_6_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_7
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_7_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_8
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_8_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_9
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_9_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_10
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_10_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_11
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_11_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_12
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_12_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_13
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_13_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_14
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_14_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_15
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_15_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_16
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_16_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_17
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_17_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_18
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_18_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_19
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_19_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_20
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_20_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_DSPI_21
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
extern ISR(dspi_21_Tcf_Irq);
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#endif

#endif /* SPI_LEVEL_DELIVERED == SPI_LEVEL_1 || SPI_LEVEL_DELIVERED == SPI_LEVEL_2 */


#ifdef __cplusplus
}
#endif
#endif /* DSPI_H */
