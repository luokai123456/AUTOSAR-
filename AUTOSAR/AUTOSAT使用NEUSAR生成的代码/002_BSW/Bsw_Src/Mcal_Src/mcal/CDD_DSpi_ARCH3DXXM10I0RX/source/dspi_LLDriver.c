/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30XX
* DESCRIPTION : CCFC30XX dspi low level drivers code
* HISTORY     : Initial version
* @file     dspi_lld.c
* @version  3.0.0
* @date     2023 - 05 - 30
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 0311,0380,2755,2995,3432 EOF*/
/*PRQA S 0310,0488,0498,1259,2834,2844,3604,4397,1257 EOF*//*QAC_CWE*/
#include "dspi_LLDriver.h"
#include "eDma.h"
#include "status.h"
#include "SchM_CDD_DSpi.h"
#include "common.h"

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Driver exported variables.                                                */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DSPI_LLD_C_VENDOR_ID                   176
#define DSPI_LLD_C_AR_MAJOR_VER                4
#define DSPI_LLD_C_AR_MINOR_VER                4
#define DSPI_LLD_C_AR_PATCH_VER                0
#define DSPI_LLD_C_SW_MAJOR_VER                3
#define DSPI_LLD_C_SW_MINOR_VER                0
#define DSPI_LLD_C_SW_PATCH_VER                0

/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (DSPI_LLD_C_VENDOR_ID != CDD_DSPI_VENDOR_ID_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (DSPI_LLD_C_AR_MAJOR_VER != CDD_DSPI_AR_RELEASE_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_AR_MAJOR_VER"
#endif
#if (DSPI_LLD_C_AR_MINOR_VER != CDD_DSPI_AR_RELEASE_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_AR_MINOR_VER"
#endif
#if (DSPI_LLD_C_AR_PATCH_VER != CDD_DSPI_AR_RELEASE_REVISION_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (DSPI_LLD_C_SW_MAJOR_VER != CDD_DSPI_SW_MAJOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_AR_PATCH_VER"
#endif
#if (DSPI_LLD_C_SW_MINOR_VER != CDD_DSPI_SW_MINOR_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_SW_MINOR_VER"
#endif
#if (DSPI_LLD_C_SW_PATCH_VER != CDD_DSPI_SW_PATCH_VERSION_OUTPUT)
#error "NON-MATCHED DATA : DSPI_LLD_C_SW_PATCH_VER"
#endif

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(status_t, DSPI_CODE) SPI_LLD_Gpio_Init
(
    VAR(uint8, DSPI_VAR) dspix,
    VAR(uint8, DSPI_VAR) spi_mode
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) SPI_LLD_Install_INT
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CONST) spip
);
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

/**
 * @brief   SPID1 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_0
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID1;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID2 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_1
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID2;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID3 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_2
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID3;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID4 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_3
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID4;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID5 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_4
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID5;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID6 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_5
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID6;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID7 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_6
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID7;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID8 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_7
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID8;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID9 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_8
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID9;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID10 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_9
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID10;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID11 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_10
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID11;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID12 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_11
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID12;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID13 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_12
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID13;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID14 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_13
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID14;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID15 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_14
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID15;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID16 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_15
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID16;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID17 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_16
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID17;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID18 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_17
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID18;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID19 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_18
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID19;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID20 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_19
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID20;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID21 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_20
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID21;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif
/**
 * @brief   SPID22 driver identifier.
 */
#ifdef RESOURCE_SUPPORT_DSPI_21
#define CDD_DSPI_START_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
VAR(SPIDriver_t, DSPI_VAR) SPID22;
#define CDD_DSPI_STOP_SEC_VAR_NO_INIT
#include "CDD_DSpi_MemMap.h"
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  =*/
/* Driver exported functions.                                                */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

/*******************************************************************************
 * @brief      abs_dif
 * @param[in]  uint32 a, uint32 b
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(uint32, DSPI_CODE) abs_dif
(
    VAR(uint32, DSPI_VAR) a,
    VAR(uint32, DSPI_VAR) b
)
{
    if (a > b)
    {
        return(a - b);
    }
    else
    {
        return(b - a);
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/*******************************************************************************
 * @brief   Install INT functions for  the SPI peripheral.
 *
 * @param[in] Dspix      Index of specific SPIDriver_t object
 *
 * @param[in] spi_mode   configure the SPIDriver_t object master or slave
 * @api
 *******************************************************************************/

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(status_t, DSPI_CODE) SPI_LLD_Gpio_Init
(
    VAR(uint8, DSPI_VAR) dspix,
    VAR(uint8, DSPI_VAR) spi_mode
)
{
    (void)spi_mode;
    VAR(status_t, DSPI_VAR)ret = STATUS_ERROR;
#ifdef RESOURCE_SUPPORT_DSPI_0
    if (dspix == (uint8)CDD_DSPI0)/*DSPI_0*/
    {
        SPID1.dspi = &DSPI_0;
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_0 */
#ifdef RESOURCE_SUPPORT_DSPI_1
    if (dspix == (uint8)CDD_DSPI1)/*DSPI_1*/
    {
        SPID2.dspi = &DSPI_1;
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_1 */
#ifdef RESOURCE_SUPPORT_DSPI_2
    if (dspix == (uint8)CDD_DSPI2)/*DSPI_2*/
    {
        SPID3.dspi = &DSPI_2;
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_2 */
#ifdef RESOURCE_SUPPORT_DSPI_3
    if (dspix == (uint8)CDD_DSPI3)/*DSPI_3*/
    {
        SPID4.dspi = &DSPI_3; //DSPI3 can't be in use for CCFC3008PT
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_3 */
#ifdef RESOURCE_SUPPORT_DSPI_4
    if (dspix == (uint8)CDD_DSPI4)/*DSPI_4*/
    {
        SPID5.dspi = &DSPI_4;
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_4 */
#ifdef RESOURCE_SUPPORT_DSPI_5
    if (dspix == (uint8)CDD_DSPI5)/*DSPI_5*/
    {
        SPID6.dspi = &DSPI_5;
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_5 */
#ifdef RESOURCE_SUPPORT_DSPI_6
    if (dspix == (uint8)CDD_DSPI6)/*DSPI_6*/
    {
        SPID7.dspi = &DSPI_6;
        ret = STATUS_SUCCESS;
    }
#endif /* RESOURCE_SUPPORT_DSPI_6 */
#ifdef RESOURCE_SUPPORT_DSPI_7
    if (dspix == (uint8)CDD_DSPI7)/*DSPI_7*/
    {
        SPID8.dspi = &DSPI_7;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_8
    if (dspix == (uint8)CDD_DSPI8)/*DSPI_8*/
    {
        SPID9.dspi = &DSPI_8;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_9
    if (dspix == (uint8)CDD_DSPI9)/*DSPI_9*/
    {
        SPID10.dspi = &DSPI_9;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_10
    if (dspix == (uint8)CDD_DSPI10)/*DSPI_10*/
    {
        SPID11.dspi = &DSPI_10;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_11
    if (dspix == (uint8)CDD_DSPI11)/*DSPI_11*/
    {
        SPID12.dspi = &DSPI_11;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_12
    if (dspix == (uint8)CDD_DSPI12)/*DSPI_12*/
    {
        SPID13.dspi = &DSPI_12;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_13
    if (dspix == (uint8)CDD_DSPI13)/*DSPI_13*/
    {
        SPID14.dspi = &DSPI_13;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_14
    if (dspix == (uint8)CDD_DSPI14)/*DSPI_14*/
    {
        SPID15.dspi = &DSPI_14;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_15
    if (dspix == (uint8)CDD_DSPI15)/*DSPI_15*/
    {
        SPID16.dspi = &DSPI_15;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_16
    if (dspix == (uint8)CDD_DSPI16)/*DSPI_16*/
    {
        SPID17.dspi = &DSPI_16;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_17
    if (dspix == (uint8)CDD_DSPI17)/*DSPI_17*/
    {
        SPID18.dspi = &DSPI_17;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_18
    if (dspix == (uint8)CDD_DSPI18)/*DSPI_18*/
    {
        SPID19.dspi = &DSPI_18;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_19
    if (dspix == (uint8)CDD_DSPI19)/*DSPI_19*/
    {
        SPID20.dspi = &DSPI_19;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_20
    if (dspix == (uint8)CDD_DSPI20)/*DSPI_20*/
    {
        SPID21.dspi = &DSPI_20;
        ret = STATUS_SUCCESS;
    }
#endif
#ifdef RESOURCE_SUPPORT_DSPI_21
    if (dspix == (uint8)CDD_DSPI21)/*DSPI_21*/
    {
        SPID22.dspi = &DSPI_21;
        ret = STATUS_SUCCESS;
     }
#endif
	 return ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/*
 * @brief Disable initial DSPI.
 *
 * This function resets the DSPI peripheral and disables the interrupt to the core.
 *
 * @param[in] instance The selected dspi module.
 * @return Operation status
 */

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(status_t, DSPI_CODE) SPI_LLD_Deinit
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
)
{
    VAR(status_t, DSPI_VAR)  status;

    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_01();
    spip->dspi->MODE.CTAR[0].R  = 0u;
    spip->dspi->RSER.R     = 0u;
    spip->dspi->SR.R       = 0xFFFFFFFFU;
    spip->dspi->MCR.R     |= MCR_HALT |
                       MCR_CLR_TXF | MCR_CLR_RXF;
    spip->dspi->MCR.B.MDIS = 1u;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_01();

    status = STATUS_SUCCESS;

    return status;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

/*******************************************************************************
 * @brief   Install INT functions for  the SPI peripheral.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 *
 * @api
 *******************************************************************************/

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) SPI_LLD_Install_INT
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CONST) spip
)
{
    if ((uint8)spip->Cdsiconfig->dmaType == (uint8)SPI_DMA_RX_AND_TX)
    {
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_02();
        spip->dspi->RSER.R = RSER_TFFF_RE | RSER_TFFF_DIRS | RSER_RFDF_RE | RSER_RFDF_DIRS;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_02();
    }
    else
    {
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_03();
        spip->dspi->RSER.R = RSER_RFDF_RE | RSER_RFDF_DIRS;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_03();
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Driver local functions.                                                   */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/*******************************************************************************
 * @brief      DSPI unit transfer start.
 * @param[in]  const SPIDriver_t *spip
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) Spi_Dspi_Start
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
)
{
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_04();
    spip->dspi->SR.R = 0xFFFFFFFFU;/* polyspace RTE:IDP */
    spip->dspi->MCR.B.HALT = 0u;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_04();
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/*******************************************************************************
 * @brief      DSPI unit transfer stop.
 * @param[in]  const SPIDriver_t *spip
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Dspi_Stop
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
)
{
    VAR(uint32, DSPI_VAR) Dspi_Timeout;
    /* Stops the DSPI */
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_05();
    spip->dspi->MCR.R |= MCR_HALT;/* polyspace RTE:NIV,IDP */ 
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_05();
    /* Waits till the DSPI is in stopped state and the transfer is completed.*/
    Dspi_Timeout = 0U;
    while ((spip->dspi->SR.B.TXRXS != 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV,IDP */
    {
        Dspi_Timeout++;
    }

    /* Clears DSPI queues.*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_06();
    spip->dspi->MCR.R |= MCR_CLR_TXF | MCR_CLR_RXF;/* polyspace RTE:NIV */
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_06();
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) DSPI_LLD_GetBestDelay
(
    VAR(uint32, DSPI_VAR) reqDelay,
	VAR(uint32, DSPI_VAR) srcClockInHz,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) bestPrescaler,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) bestScaler
)
{
    VAR(uint32, DSPI_VAR) bestDelay = 0U;
    VAR(uint32, DSPI_VAR) curDelay = 0U;
    VAR(uint8, DSPI_VAR) scaler, prescaler;
    VAR(uint8, DSPI_VAR) low, high;
    VAR(uint32, DSPI_VAR) const s_PBR_Prescaler[] = {2U, 3U, 5U, 7U};
    VAR(uint32, DSPI_VAR) pretemp;

    *bestPrescaler = 0U;
    *bestScaler = 0U;

    for (prescaler = 0; prescaler < 4U; prescaler++)
    {
        low = 0U;
        high = 0xFU;
        while ((uint8)(high - low) > 1U)
        {
            scaler = (uint8)((low + high) / 2U);
            pretemp = (uint32)((((uint32)scaler + 1U) * 1000000U) / srcClockInHz); /* polyspace RTE:ZDV */

            if(pretemp <= 32U)
			{
				VAR(uint8, DSPI_VAR) prs = scaler + 1U;
				 if (prs < 13U)
				 {
					 curDelay = (uint32)((((uint32)(s_PBR_Prescaler[prescaler] << prs)) * 1000000U) / srcClockInHz);
				 }
				 else if (prs < 32U)
				 {
					 curDelay = (uint32)(((uint32)(s_PBR_Prescaler[prescaler]) << prs) / srcClockInHz) * 1000000U;
				 }
				 else
				 {
					 /* overflow */
				 }
			}

            if (abs_dif(reqDelay, bestDelay) > abs_dif(reqDelay, curDelay))
            {
                bestDelay = curDelay;
                *bestPrescaler = prescaler;
                *bestScaler = scaler;
            }

            if (curDelay < reqDelay)
            {
                low = scaler;
            }
            else
            {
                high = scaler;
            }
        }
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

/*******************************************************************************
 * @brief      SPI_LLD_SetbaudRate
 * @param[in]  const SPIDriver_t *spip, uint32 bitsPerSec, uint32 sourceClockInHz
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) DCSI_LLD_SetbaudRate
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint8, DSPI_VAR) catr_index,
    VAR(uint32, DSPI_VAR) bitsPerSec,
    VAR(uint32, DSPI_VAR) sourceClockInHz
)
{
    VAR(uint32, DSPI_VAR) bestFreq = 0xFFFFFFFFU;
    VAR(uint32, DSPI_VAR) bestScaler = 0U;
    VAR(uint32, DSPI_VAR) bestPrescaler = 0U;
    VAR(uint32, DSPI_VAR) freq1 = 0U;
    VAR(uint32, DSPI_VAR) freq2 = 0U;
    VAR(uint8, DSPI_VAR) scaler = 0U;
    VAR(uint8, DSPI_VAR) prescaler = 0U;
    VAR(uint8, DSPI_VAR) low, high;
    VAR(uint32, DSPI_VAR) tempBestFreq = 0U;
    VAR(uint8, DSPI_VAR)  tempScaler   = 0U;
    static const VAR(uint32, DSPI_VAR) s_PBR_baudratePrescaler[] = {2U, 3U, 5U, 7U};
    static const VAR(uint32, DSPI_VAR) s_BR_baudrateScaler[] = {2U, 4U, 6U, 8U, 16U, 32U, 64U, 128U, 256U, 512U, 1024U, 2048U, 4096U, 8192U, 16384U, 32768U};

    for (prescaler = 0; prescaler < 4U; prescaler++)
    {
        low = 0U;
        high = 15U;

        /* Implement golden section search algorithm */
        do
        {
            scaler = (uint8)((low + high) / 2U);
            freq1 = (sourceClockInHz / s_PBR_baudratePrescaler[prescaler]) / s_BR_baudrateScaler[scaler];
            if (abs_dif(bitsPerSec, bestFreq) > abs_dif(bitsPerSec, freq1))
            {
                bestFreq = freq1;
            }

            if (freq1 < bitsPerSec)
            {
                high = scaler;
            }
            else
            {
                low = scaler;
            }
        }
        while ((high - low) > (uint8)1U);

        /* Evaluate last 2 scaler values */
        freq1 = (sourceClockInHz / s_PBR_baudratePrescaler[prescaler]) / s_BR_baudrateScaler[low]; /* polyspace RTE:IDP */
        freq2 = (sourceClockInHz / s_PBR_baudratePrescaler[prescaler]) / s_BR_baudrateScaler[high];
        if (abs_dif(bitsPerSec, freq1) > abs_dif(bitsPerSec, freq2))
        {
            tempBestFreq   = freq2;
            tempScaler     = high;
        }
        else
        {
            tempBestFreq   = freq1;
            tempScaler     = low;
        }

        if (abs_dif(bitsPerSec, bestFreq) >= abs_dif(bitsPerSec, tempBestFreq))
        {
            bestFreq       = tempBestFreq;
            bestPrescaler = prescaler;
            bestScaler    = tempScaler;
        }

        /* If current frequency is equal to target frequency  stop the search */
        if (bestFreq == bitsPerSec)
        {
            break;
        }
    }

    /* Write the best baud rate scalar and prescaler to the CATR0.*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_08();
    spip->dspi->MODE.CTAR[catr_index].B.PBR = bestPrescaler;
    spip->dspi->MODE.CTAR[catr_index].B.BR = bestScaler;

    /* set delays for SPI signals */
    DSPI_LLD_GetBestDelay(3U, sourceClockInHz, &prescaler,&scaler);
    spip->dspi->MODE.CTAR[catr_index].B.PDT = prescaler;
    spip->dspi->MODE.CTAR[catr_index].B.DT = scaler;
    DSPI_LLD_GetBestDelay(3U, sourceClockInHz, &prescaler,&scaler);
    spip->dspi->MODE.CTAR[catr_index].B.PASC = prescaler;
    spip->dspi->MODE.CTAR[catr_index].B.ASC = scaler;
    DSPI_LLD_GetBestDelay(3U, sourceClockInHz, &prescaler,&scaler);
    spip->dspi->MODE.CTAR[catr_index].B.PCSSCK = prescaler;
    spip->dspi->MODE.CTAR[catr_index].B.CSSCK = scaler;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_08();
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

/*******************************************************************************
 * @brief   Starts reception without DMA for frames up to 16 bits.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] n         number of words to be exchanged
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 *******************************************************************************/
#if  FEATURE_DSPI_HAS_EXTENDED_MODE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"

static FUNC(void, DSPI_CODE) Spi_Start_Rx32
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA)spip,
    VAR(uint32, DSPI_VAR) n,
    P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA)rxbuf
)
{
    /* Setting up the fields required for operation continuation.*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_17();
    spip->rx.rx_ptr32 = rxbuf;
    spip->rx_cnt = n;

    spip->dspi->RSER.B.RFDF_RE = 1u;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_17();
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

/*******************************************************************************
 * @brief   Prefills the TX FIFO using 16 bits frames.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in, out] np    pointer to the number of frames to send, must be
 *                      greater than zero, contains the number of remaining
 *                      frames on return
 * @param[in, out] txpp  pointer to the pointer to the transmit buffer
 *
 * @notapi
 *******************************************************************************/
#if  FEATURE_DSPI_HAS_EXTENDED_MODE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Dspi_Prefill_Txfifo32
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip, 
    P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA) np,
    P2P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA) txpp
)
{
    VAR(uint32, DSPI_VAR) frame; 
    while (spip->dspi->SR.B.TXCTR < DSPI_FIFO_DEPTH)
    {
      frame = **txpp;
      (*txpp)++;
      SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_20();
      spip->dspi->PUSHR.PUSHR_XSPI.B.TXDATA  = ((uint16)(frame & 0x0000ffffU));
      spip->dspi->PUSHR.PUSHR_XSPI.B.TXDATA  = (uint16)(frame >> 16);
      SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_20();
      (*np)--;
      if((*np) == 0U)/*PRQA S 3440*/
      {
    	  break;
      }
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Dspi_Prefill_XspiTxfifo16
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA) np,
    P2P2VAR(uint16, AUTOMATIC, DSPI_APPL_DATA) txpp
)
{
    VAR(uint16, DSPI_VAR) frame;
    while (spip->dspi->SR.B.TXCTR < DSPI_FIFO_DEPTH)
    {
      frame = **txpp;
      (*txpp)++;
      SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_21();
      spip->dspi->PUSHR.PUSHR_XSPI.B.TXDATA  = frame;
      SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_21();
      (*np)--;
      if((*np) == 0U)/*PRQA S 3440*/
      {
    	  break;
      }
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Dspi_Prefill_XspiTxfifo8
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA) np,
    P2P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) txpp
)/*PRQA S 3219*/
{
    VAR(uint8, DSPI_VAR) frame;
    while (spip->dspi->SR.B.TXCTR < DSPI_FIFO_DEPTH)
    {
      frame = **txpp;
      (*txpp)++;
      SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_22();
      spip->dspi->PUSHR.PUSHR_XSPI.B.TXDATA  = frame;
      SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_22();
      (*np)--;
      if((*np) == 0U)/*PRQA S 3440*/
      {
    	  break;
      }
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

/*******************************************************************************
 * @brief   Starts transmission without DMA for frames up to 16 bits.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] n         number of words to be exchanged
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @notapi
 *******************************************************************************/
#if  FEATURE_DSPI_HAS_EXTENDED_MODE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Start_Tx32
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip,
    VAR(uint32, DSPI_VAR) n,
    P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA) txbuf
)
{

    /* Enabling the EOQF interrupt source for transfer complete.
    * This interrupt is not valid in slave mode.
    */
    if (spip->dspi->MCR.B.MSTR == 1UL)
    {
       spip->dspi->RSER.B.EOQF_RE = 1;
    }

    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_27();
    spip->dspi->PUSHR.PUSHR_XSPI.B.CMD = (uint16)((((((uint32)(spip->Cdsiconfig->continuousPCS)) << 31) &
                 (~(((uint32)(spip->Cdsiconfig->continuousPCS)) << 27))) |
                (((uint32)(((uint32)1U) << ((uint32)(spip->Cdsiconfig->whichPCS)))) << 16))>>16);
    spip->dspi->CTARE[0U].B.DTCP = n-1U;

    spip->dspi->PUSHR.PUSHR_XSPI.B.CMD = (uint16)(((((((uint32)(~(spip->Cdsiconfig->continuousPCS)) << 31U)) &/*PRQA S 4391,2921*/
             (((uint32)(spip->Cdsiconfig->continuousPCS)) << 27U))) |PUSHR_EOQ|PUSHR_CTAS(1U)|/*PRQA S 3469 */
            (((uint32)(((uint32)1U) << ((uint32)(spip->Cdsiconfig->whichPCS)))) << 16U ))>>16U);
    spip->dspi->CTARE[1U].B.DTCP = 1U;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_27();
    /* Preloading the TX FIFO with as much frames as possible.*/
    Spi_Dspi_Prefill_Txfifo32(spip, &n, &txbuf); /*PRQA S 1339*/

    /* This is the case where the whole operation can be satisfied using the
      preloading alone.*/
    if (n == 0U)
    {
      return;
    }

    /* Setting up the fields required for operation continuation.*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_28();
    spip->tx.tx_ptr32 = txbuf;
    spip->tx_cnt = n;

    /* Enabling the TFFF interrupt source for transfer continuation.*/
    spip->dspi->RSER.B.TFFF_RE = 1;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_28();
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

/*******************************************************************************
 * @brief   Starts transmission using DMA for frames up to 16 bits.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] n         number of words to be exchanged
 * @param[in] txbuf     the pointer to the transmit buffer
 *
 * @notapi
 *******************************************************************************/
#if  FEATURE_DSPI_HAS_EXTENDED_MODE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Start_XspiTx16_dma
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip,
    VAR(uint32, DSPI_VAR) n,
    P2VAR(uint32, AUTOMATIC, DSPI_APPL_DATA) txbuf
)
{
  VAR(uint16, DSPI_VAR) last_frame;
  P2CONST(uint32, AUTOMATIC, DSPI_APPL_CODE)src;
  P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE)dst;

  /* Special case when the data to be transmitted can entirely fit into the
     TX FIFO, in this case the TX DMAs are not activated.*/
  if (n <= DSPI_FIFO_DEPTH)
  {
    Spi_Dspi_Prefill_Txfifo16(spip, &n, (uint16 **)&txbuf); /*PRQA S 1339,0310*/
    return;
  }

  /* Preparing the TX intermediate buffer with the fixed part.*/
  /* The first frame is pushed immediately, then the DMA is activated to
     send the following frames. This should reduce latency on the operation
     start.*/
  spip->tx_cmd = (((((uint32)(spip->Cdsiconfig->continuousPCS)) << 31) &
                  (~(((uint32)(spip->Cdsiconfig->continuousPCS)) << 27))) |
                  (((uint32)(((uint32)1) << ((uint32)(spip->Cdsiconfig->whichPCS)))) << 16));

  SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_29();
  spip->dspi->PUSHR.PUSHR_XSPI.B.CMD = (uint16)(spip->tx_cmd>>16);
  spip->dspi->CTARE[0].B.DTCP = n-1U;
  SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_29();

  /* The last frame is a special case, will be pushed by the TX FIFO drain
     interrupt handler or the DMA final callback.*/
  last_frame = (uint16)txbuf[n - 1U];
  spip->tx_last = (uint32)last_frame;
  /* At least two frames left, the DMA is enabled in order to handle the
     long transfer, note that the final frame is not pushed by the DMA.*/
  /* Setting up TX1 DMA TCD parameters for 8 bits transfers.*/
  src = (uint32 *)txbuf;
  dst = ((uint8 *)&spip->dspi->PUSHR.PUSHR.R) + 2U;/*PRQA S 0312*/

    eDMATransferConfigType dmaConfig_32bit =
    {
        .srcAddr = (uint32)src, /* Modified by function */
        .destAddr = (uint32)dst, /* Modified by function */
        .minorTransByte = 2u,
        .srcTransDataSize = EDMA_TRANSFER_SIZE_2B,
        .destTransDataSize = EDMA_TRANSFER_SIZE_2B,
        .srcAddrOffset = 2,
        .destAddrOffset = 0,
        .srcAddrAdjustLast = 0,
        .destAddrAdjustLast = 0, /* Modified by function */
        .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .featureScatterGatherEn = FALSE,
        .featureScatterGatherNextDescriptor = 0u,
        .completeIntEn = TRUE,
        .lpTransConfigPtr = &(eDMALoopTransferConfigType)
        {
            .majorLpIterCnt = n - 1U,
            .srcAddrOffsetEn = FALSE,
            .dstAddrOffsetEn = FALSE,
            .minorLpOffset = 0,
            .minorLpLinkEn = FALSE,
            .minorLpLinkChn = 0u,
            .majorLpLinkEn = FALSE,
            .majorLpLinkChn = 0u
        }
    };

    (void)EDMA_LLD_SetLoopTransferConfig(spip->tx1_channel, &dmaConfig_32bit);
    EDMA_SetChnDisRequestsOnTransferComplete(spip->tx1_channel, TRUE);

    (void)EDMA_LLD_SetChannelRequest(spip->tx1_channel);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static FUNC(void, DSPI_CODE) Spi_Start_XspiTx8_dma
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip,
    VAR(uint32, DSPI_VAR) n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA)txbuf
)
{
  VAR(uint8, DSPI_VAR) last_frame;
  P2CONST(uint32, AUTOMATIC, DSPI_APPL_CODE)src;
  P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE)dst;

  /* Special case when the data to be transmitted can entirely fit into the
     TX FIFO, in this case the TX DMAs are not activated.*/
  if (n <= DSPI_FIFO_DEPTH)
  {
	  Spi_Dspi_Prefill_Txfifo8(spip, &n, &txbuf); /*PRQA S 1339*/
    return;
  }

  /* Preparing the TX intermediate buffer with the fixed part.*/
  /* The first frame is pushed immediately, then the DMA is activated to
     send the following frames. This should reduce latency on the operation
     start.*/
  spip->tx_cmd = (((((uint32)(spip->Cdsiconfig->continuousPCS)) << 31) &
                  (~(((uint32)(spip->Cdsiconfig->continuousPCS)) << 27))) |
                  (((uint32)(((uint32)1) << ((uint32)(spip->Cdsiconfig->whichPCS)))) << 16));

  spip->dspi->PUSHR.PUSHR_XSPI.B.CMD = (uint16)(spip->tx_cmd>>16);
  spip->dspi->CTARE[0].B.DTCP = n-1U;

  /* The last frame is a special case, will be pushed by the TX FIFO drain
     interrupt handler or the DMA final callback.*/
  last_frame = txbuf[n - 1U];
  spip->tx_last = last_frame;
  /* At least two frames left, the DMA is enabled in order to handle the
     long transfer, note that the final frame is not pushed by the DMA.*/
  /* Setting up TX1 DMA TCD parameters for 8 bits transfers.*/
  src = (uint32 *)txbuf;/*PRQA S 3305,0310*/
  dst = ((uint8 *)&spip->dspi->PUSHR.PUSHR.R) + 3;/*PRQA S 0312*/

    eDMATransferConfigType dmaConfig_8bit =
    {
        .srcAddr = (uint32)src, /* Modified by function */
        .destAddr = (uint32)dst, /* Modified by function */
        .minorTransByte = 1u,
        .srcTransDataSize = EDMA_TRANSFER_SIZE_1B,
        .destTransDataSize = EDMA_TRANSFER_SIZE_1B,
        .srcAddrOffset = 1,
        .destAddrOffset = 0,
        .srcAddrAdjustLast = 0,
        .destAddrAdjustLast = 0, /* Modified by function */
        .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .featureScatterGatherEn = FALSE,
        .featureScatterGatherNextDescriptor = 0,
        .completeIntEn = TRUE,
        .lpTransConfigPtr = &(eDMALoopTransferConfigType)
        {
            .majorLpIterCnt = n - 1U,
            .srcAddrOffsetEn = FALSE,
            .dstAddrOffsetEn = FALSE,
            .minorLpOffset = 0,
            .minorLpLinkEn = FALSE,
            .minorLpLinkChn = 0u,
            .majorLpLinkEn = FALSE,
            .majorLpLinkChn = 0u
        }
    };

    (void)EDMA_LLD_SetLoopTransferConfig(spip->tx1_channel, &dmaConfig_8bit);
    EDMA_SetChnDisRequestsOnTransferComplete(spip->tx1_channel, TRUE);

    (void)EDMA_LLD_SetChannelRequest(spip->tx1_channel);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

/*******************************************************************************
 * @brief   Starts reception using DMA for frames up to 32 bits with dma.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] n         number of words to be exchanged
 * @param[out] rxbuf    the pointer to the receive buffer
 *
 * @notapi
 *******************************************************************************/
#if  FEATURE_DSPI_HAS_EXTENDED_MODE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
static void Spi_Start_Rx32_dma(const SPIDriver_t *spip, uint32 n, const uint32 *rxbuf)
{


    const uint8 *src = ((const uint8 *)&(spip)->dspi->POPR.R);/*PRQA S 0312*/

    eDMATransferConfigType dmaConfig_rx32bit =
    {
        .srcAddr = (uint32)src, /* Modified by function */
        .destAddr = (uint32)rxbuf, /* Modified by function */
        .minorTransByte = 4u,
        .srcTransDataSize = EDMA_TRANSFER_SIZE_4B,
        .destTransDataSize = EDMA_TRANSFER_SIZE_4B,
        .srcAddrOffset = 0,
        .destAddrOffset = 4,
        .srcAddrAdjustLast = 0,
        .destAddrAdjustLast = 0, /* Modified by function */
        .srcAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .destAddrModulo = EDMA_ADDRESS_MODULO_OFF,
        .featureScatterGatherEn = FALSE,
        .featureScatterGatherNextDescriptor = 0u,
        .completeIntEn = TRUE,
        .lpTransConfigPtr = &(eDMALoopTransferConfigType)
        {
            .majorLpIterCnt = n,
            .srcAddrOffsetEn = FALSE,
            .dstAddrOffsetEn = FALSE,
            .minorLpOffset = 0,
            .minorLpLinkEn = FALSE,
            .minorLpLinkChn = 0u,
            .majorLpLinkEn = FALSE,
            .majorLpLinkChn = 0u
        }
    };
    (void)EDMA_LLD_SetLoopTransferConfig(spip->rx_channel, &dmaConfig_rx32bit);
    (void)EDMA_SetChnDisRequestsOnTransferComplete(spip->rx_channel, TRUE);
    (void)EDMA_LLD_SetChannelRequest(spip->rx_channel);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) MSC_SETi_SEL_Set(VAR(uint32, DSPI_VAR) set_index, P2CONST(uint8, DSPI_CONST, DSPI_APPL_CONST) sel_value)
{
    //SETi[0:15]
    GTM4.GLS[0].MSC.SET[set_index].CON0.R = (sel_value[0] << 0 | sel_value[1] << (8 * 1) | (sel_value[2] << (8*2)) |(sel_value[3] << (8*3))) & GTM_MSC_SETi_MSK ;
    GTM4.GLS[0].MSC.SET[set_index].CON1.R = (sel_value[4] << 0 | sel_value[5] << (8 * 1) | (sel_value[6] << (8*2)) |(sel_value[7] << (8*3))) & GTM_MSC_SETi_MSK ;
    GTM4.GLS[0].MSC.SET[set_index].CON2.R = (sel_value[8] << 0 | sel_value[9] << (8 * 1) | (sel_value[10] << (8*2)) |(sel_value[11] << (8*3))) & GTM_MSC_SETi_MSK ;
    GTM4.GLS[0].MSC.SET[set_index].CON3.R = (sel_value[12] << 0 | sel_value[13] << (8 * 1) | (sel_value[14] << (8*2)) |(sel_value[15] << (8*3))) & GTM_MSC_SETi_MSK ;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(void, DSPI_CODE) MSCi_Selection_INLCON(VAR(uint32, DSPI_VAR) msc_index, CONST(uint32, DSPI_CONST) set_value)
{
    GTM4.GLS[0].MSC.MSCQ[msc_index].INLCON.R = set_value;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(void, DSPI_CODE) MSCi_Selection_INHCON(VAR(uint32, DSPI_VAR) msc_index, CONST(uint32, DSPI_CONST) set_value)
{
    GTM4.GLS[0].MSC.MSCQ[msc_index].INHCON.R = set_value;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
DSPI_INLINE FUNC(void, DSPI_CODE) MSCi_Selection_INEXTCON(VAR(uint32, DSPI_VAR) msc_index, CONST(uint32, DSPI_CONST) set_value)
{
    GTM4.GLS[0].MSC.MSCQ[msc_index].INLEXTCON.R = set_value;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif

/****************************************************************
 * @brief   Low level SPI driver initialization.
 * 
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] config    pointer to the @p SPIConfig object
 *
 * @init
 ***************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(status_t, DSPI_CODE) SPI_LLD_Init                   /*PRQA S 2755*/
(   
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip, 
    P2CONST(spi_config_t, AUTOMATIC, DSPI_APPL_CODE) config,
    VAR(spi_functional_mode_t, DSPI_VAR) spi_mode
)
{
	VAR(status_t, DSPI_VAR) ret = STATUS_SUCCESS;
	spip->Cdsiconfig = config;/* polyspace RTE:IDP */
	/*configure DSPIx pins as sck,cs_0,mosi,miso */
	ret = SPI_LLD_Gpio_Init((uint8)config->WhichSpiController,(uint8)spi_mode);

    /*Module Enable */
    spip->dspi->MCR.B.MDIS = 0;/* polyspace RTE:IDP */
	/* Set SPI mode (Master/Slave).*/
	if (spi_mode == SPI_MASTER) 
	{
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_31();
		spip->dspi->MCR.B.MSTR = 1U;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_31();
	} 
	else 
	{
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_32();
		spip->dspi->MCR.B.MSTR = 0U;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_32();
	}

	spip->dspi->MCR.B.CONT_SCKE = spip->Cdsiconfig->isClkContinuous;
	/* On this platform DSPI in extended mode is supported */
#if  FEATURE_DSPI_HAS_EXTENDED_MODE
	spip->dspi->MCR.B.XSPI = 1U;
	spip->dspi->CTARE[0].B.FMSZE = 1U;
	spip->dspi->CTARE[0].B.DTCP = 1U;
	spip->dspi->CTARE[1].B.FMSZE = 1U;
	spip->dspi->CTARE[1].B.DTCP = 1U;
#endif
	if((((spip->Cdsiconfig->whichPCS))) <= 16U)
	{
		spip->dspi->MCR.R |= ((((uint32)spip->Cdsiconfig->pcsPolarity << (spip->Cdsiconfig->whichPCS)))<<16U);/* polyspace RTE:NIV */
	}
	/*clear TX and RX FIFO*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_33();
	spip->dspi->MCR.B.CLR_RXF = 1U;
	spip->dspi->MCR.B.CLR_TXF = 1U;

	spip->dspi->MCR.B.ROOE = 1U;

	/*when DSPI configured as an SPI bus Slave,the DSPIX_CATR0 is used.so default to use CATR0 for Master and slave*/

	spip->dspi->MODE.CTAR[0].B.LSBFE  = (uint8)spip->Cdsiconfig->lsbFirst;
	spip->dspi->MODE.CTAR[0].B.CPHA	 = (uint8)spip->Cdsiconfig->clkPhase;
	spip->dspi->MODE.CTAR[0].B.CPOL	 = (uint8)spip->Cdsiconfig->clkPolarity;

	spip->dspi->MODE.CTAR[1].B.LSBFE  = (uint8)spip->Cdsiconfig->lsbFirst;
	spip->dspi->MODE.CTAR[1].B.CPHA	 = (uint8)spip->Cdsiconfig->clkPhase;
	spip->dspi->MODE.CTAR[1].B.CPOL	 = (uint8)spip->Cdsiconfig->clkPolarity;

    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_33();
	/* set clock frequency */
	DCSI_LLD_SetbaudRate(spip,0,spip->Cdsiconfig->bitsPerSec,config->DSpi_Clock);
	DCSI_LLD_SetbaudRate(spip,1,spip->Cdsiconfig->bitsPerSec,config->DSpi_Clock);

	spip->dspi->MODE.CTAR[0].B.FMSZ = (uint8)(spip->Cdsiconfig->bitcount - 1U);

    spip->dspi->MODE.CTAR[1].B.FMSZ = (uint8)(spip->Cdsiconfig->bitcount - 1U);
    spip->dspi->SR.R = 0xFFFFFFFFUL;

	if ((config->transferType) == SPI_USING_INTERRUPTS)
	{
		SPI_LLD_Install_INT(spip);
	}
/********************* DSI CSI CONFIG************************/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_34();
    spip->dspi->MCR.B.DCONF = config->Dconf;

    if (config->Dconf != 0U)
    {
        spip->dspi->DSICR0.B.DSICTAS = config->DSICTAx;
        spip->dspi->DSICR0.B.TSBC = config->TSBC;
        spip->dspi->DSICR0.B.ITSB = config->ITSBC;
        spip->dspi->DSICR0.B.CID = config->isCID;
        spip->dspi->DSICR0.B.TPOL = config->tpol;
        spip->dspi->DSICR0.B.TXSS = config->DsiDataSource;
        if(config->whichDSIPCS <= 8U)
        {
        	spip->dspi->DSICR0.R |= (uint8)(1U << config->whichDSIPCS);/* polyspace RTE:NIV */
        }

        if (config->TSBC == 1U)
        {
            spip->dspi->DSICR1.B.TSBCNT = (uint8)(config->TSBCNT - 1U);
            spip->dspi->DSICR1.B.DSE0 = config->DataSelect0En;
            spip->dspi->DSICR1.B.DSE1 = config->DataSelect1En;
            if(config->whichTSBPCS <= 8U)
            {
            	spip->dspi->DSICR1.R |= (uint8)(1U << config->whichTSBPCS);/* polyspace RTE:NIV */
            }

            if(((config->whichTSBPCS)) <= 16U)
            {
            	spip->dspi->MCR.R |= ((((uint32)spip->Cdsiconfig->pcsPolarity << config->whichTSBPCS)) << 16U);/* polyspace RTE:NIV */
            }
        }
    }
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_34();

#ifdef RESOURCE_SUPPORT_GTM_TO_MSC
/********************* GTM MSC CONFIG************************/
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_35();
    if (spip->Cdsiconfig->MSCConfig != NULL_PTR)
    {
        MSCi_Selection_INLCON(spip->Cdsiconfig->MSCConfig->mscIndex, spip->Cdsiconfig->MSCConfig->InputLowControl);
        MSCi_Selection_INHCON(spip->Cdsiconfig->MSCConfig->mscIndex, spip->Cdsiconfig->MSCConfig->InputHighControl);
        MSCi_Selection_INEXTCON(spip->Cdsiconfig->MSCConfig->mscIndex, spip->Cdsiconfig->MSCConfig->InputLowExtendedControl);
    }
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_35();
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
#endif
    return ret;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/*******************************************************************************
 * @brief   Starts reception without DMA ignoring the received data.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] n         number of words to be exchanged
 *
 * @notapi
 *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_DSI_Send
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
)
{
    VAR(uint8, DSPI_VAR) val = 0;
    VAR(uint32, DSPI_VAR) Dspi_Timeout;

    /* Starting transfer.*/
    Spi_Dspi_Start(spip);

    while (n != 0U)
    {
        val = *txbuf; /* polyspace RTE:IDP */
	    txbuf++;
        spip->dspi->ASDR0.R = (val);
        Dspi_Timeout = 0U;
        while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */ 
        {
            Dspi_Timeout++;
        }
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_37();
        spip->dspi->SR.B.TCF = 1U;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_37();
        *rxbuf = (uint8)spip->dspi->DDR0.R;/* polyspace RTE:NIV */ 
	rxbuf++;
        n--;
    }
    /* Stop transfer.*/
    Spi_Dspi_Stop(spip);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
 /*******************************************************************************
  * @brief     Starts reception without DMA ignoring the received data.
  *
  * @param[in] spip      pointer to the @p SPIDriver_t object
  * @param[in] n         number of words to be exchanged
  *
  * @notapi
  *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_DSI_TSB_Send
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
)
 {
     /* Starting transfer.*/
     VAR(uint32, DSPI_VAR) Dspi_Timeout;
     Spi_Dspi_Start(spip);

     while (n != 0U)
     {
        spip->dspi->ASDR0.R = *txbuf; /* polyspace RTE:IDP */
	    txbuf++;
        Dspi_Timeout = 0U;
        while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
        {
            Dspi_Timeout++;
        }          
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_38();
        spip->dspi->SR.B.TCF = 1U;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_38();

        *rxbuf = (uint8)spip->dspi->DDR0.R;/* polyspace RTE:NIV */ 
        rxbuf++;
        n--;
     }
     /* Stop transfer.*/
     Spi_Dspi_Stop(spip);
 }
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
 /*******************************************************************************
  * @brief     Starts reception without DMA ignoring the received data.
  *
  * @param[in] spip      pointer to the @p SPIDriver_t object
  * @param[in] n         number of words to be exchanged
  *
  * @notapi
  *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_DSI_Receive
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf
)
 {
     /* Starting transfer.*/
     VAR(uint32, DSPI_VAR) Dspi_Timeout;
     Spi_Dspi_Start(spip);
     while (n != 0U)
     {
        Dspi_Timeout = 0U;
        while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */ 
        {
            Dspi_Timeout++;
        }
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_39();
        spip->dspi->SR.B.TCF = 1U;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_39();

        *rxbuf = (uint8)spip->dspi->DDR0.R;/* polyspace RTE:NIV,IDP*/
        rxbuf++;
        n--;
     }
     /* Stop transfer.*/
     Spi_Dspi_Stop(spip);
 }
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
 /*******************************************************************************
  * @brief     Starts reception without DMA ignoring the received data.
  *
  * @param[in] spip      pointer to the @p SPIDriver_t object
  * @param[in] n         number of words to be exchanged
  *
  * @notapi
  *******************************************************************************/

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
 static FUNC(void, DSPI_CODE) Cdsi_Prefill_Tx8
 (
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) spi_n,
    VAR(uint32, DSPI_VAR) dsi_n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
)/*PRQA S 3673*/
{
    VAR(uint32, DSPI_VAR) cmd = 0;
    VAR(uint32, DSPI_VAR) frame = 0;
    VAR(uint32, DSPI_VAR) spi_num = spi_n;
    VAR(uint32, DSPI_VAR) dsi_num = dsi_n;
    VAR(uint32, DSPI_VAR) move_check_variable_1 = 31U;
    VAR(uint32, DSPI_VAR) move_check_variable_2 = 27U;
    VAR(uint32, DSPI_VAR) move_check_variable_3 = 16U;
    VAR(uint32, DSPI_VAR) Dspi_Timeout;

    if((move_check_variable_1 <= 32U) && (move_check_variable_2 <= 32U) && (move_check_variable_3 <= 32U) && ((uint32)(spip->Cdsiconfig->whichPCS) <= 32U)) /* polyspace RTE:NIV,IDP */ 
    {
        cmd = (((((uint32)(spip->Cdsiconfig->continuousPCS)) << move_check_variable_1) &  /* polyspace RTE:NIV */
                (~(((uint32)(spip->Cdsiconfig->continuousPCS)) << move_check_variable_2))) |
                ((uint32)(((uint32)1) << ((uint32)(spip->Cdsiconfig->whichPCS))) << move_check_variable_3));/* polyspace RTE:SHF */
    }

    while ((spip->dspi->SR.B.TXCTR < DSPI_FIFO_DEPTH) && (spi_num > 0U))/* polyspace RTE:NIV */
    {
      frame = *txbuf;/* polyspace RTE:IDP */
      (txbuf)++;
      spi_num--;
      if (spi_num == 0U)
      {
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_40();
        spip->dspi->PUSHR.PUSHR.R = (PUSHR_EOQ | cmd | frame) & (~PUSHR_CONT);
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_40();
        break;
      }
      SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_41();
      spip->dspi->PUSHR.PUSHR.R = cmd | frame;
      SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_41();

    }
    Dspi_Timeout = 0U;
    while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        Dspi_Timeout++;
    }
    Dspi_Timeout = 0U;
    while ((spip->dspi->SR.B.TXCTR != 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */

    {
        Dspi_Timeout++;
    }
    delay(0x1000);
    spip->dspi->SR.B.TCF = 1U;

              /* Emptying the RX FIFO.*/

    while (dsi_num != 0U)
    {
        spip->dspi->ASDR0.R = *txbuf1;/* polyspace RTE:IDP */
	    txbuf1++;
        Dspi_Timeout = 0U;
        while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
        {
            Dspi_Timeout++;
        }
        SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_42();
        spip->dspi->SR.B.TCF = 1U;
        SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_42();

        *rxbuf = (uint8)spip->dspi->DDR0.R;/* polyspace RTE:NIV */
        rxbuf++;
        dsi_num--;
       }
    Dspi_Timeout = 0U;
    while ((spip->dspi->SR.B.RXCTR > 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
      SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_43();
      frame = spip->dspi->POPR.R;/* polyspace RTE:NIV */
      SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_43();
      *rxbuf1 = (uint8)frame;/* polyspace RTE:IDP */
      rxbuf1++;
      Dspi_Timeout ++;
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
 /*******************************************************************************
  * @brief     Starts reception without DMA ignoring the received data.
  *
  * @param[in] spip      pointer to the @p SPIDriver_t object
  * @param[in] n         number of words to be exchanged
  *
  * @notapi
  *******************************************************************************/

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) Cdsi_Prefill_ITBC_Tx
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) spi_n,
    VAR(uint32, DSPI_VAR) dsi_n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
)
{
    VAR(uint32, DSPI_VAR) cmd = 0;
    VAR(uint32, DSPI_VAR) frame = 0;
    VAR(uint32, DSPI_VAR) spi_num = spi_n;
    VAR(uint32, DSPI_VAR) dsi_num = dsi_n;
    VAR(uint32, DSPI_VAR) dsi_rx_num = spi_n + 1U;
    VAR(uint32, DSPI_VAR) move_check_variable_1 = 31U;
	VAR(uint32, DSPI_VAR) move_check_variable_2 = 27U;
	VAR(uint32, DSPI_VAR) move_check_variable_3 = 16U;
	if((move_check_variable_1 <= 32U) && (move_check_variable_2 <= 32U) && (move_check_variable_3 <= 32U) && ((uint32)(spip->Cdsiconfig->whichPCS) <= 32U))/* polyspace RTE:NIV,IDP*/
	{
		cmd = (((((uint32)(spip->Cdsiconfig->continuousPCS)) << move_check_variable_1) &/* polyspace RTE:NIV */
		        (~(((uint32)(spip->Cdsiconfig->continuousPCS)) << move_check_variable_2))) |
		        ((uint32)(((uint32)1) << ((uint32)(spip->Cdsiconfig->whichPCS))) << move_check_variable_3));/* polyspace RTE:SHF */
	}

    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_47();
    spip->dspi->ASDR0.R = *txbuf1;/* polyspace RTE:IDP */
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_47();
    txbuf1++;
    frame = *txbuf;
    (txbuf)++;
    spip->dspi->PUSHR.PUSHR.R = cmd |frame;

    /* Starting transfer.*/
    Spi_Dspi_Start(spip);
    VAR(uint32, DSPI_VAR) Dspi_Timeout;

    while ((dsi_num != 0U) || (dsi_rx_num != 0U))
    {
        while ((spip->dspi->SR.B.TXCTR < DSPI_FIFO_DEPTH) && (spi_num > 0U))/* polyspace RTE:NIV */
        {
          frame = *txbuf;/* polyspace RTE:IDP */
          (txbuf)++;

	      spi_num--;
          if (spi_num == 0U)
          {
            spip->dspi->PUSHR.PUSHR.R = (cmd) & (~PUSHR_CONT);
            break;
          }
          spip->dspi->PUSHR.PUSHR.R = cmd | frame;

        }

        if (dsi_num != 0U)/*PRQA S 2991,2995*/
        {
            Dspi_Timeout = 0U;
			while ((spip->dspi->SR.B.DSITCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
            {
                Dspi_Timeout++;
            };

			spip->dspi->SR.R = 0x04000000;
			if(dsi_num != 0U)/*PRQA S 2991,2995*/
			{
				spip->dspi->ASDR0.R= *txbuf1;	/* polyspace RTE:IDP */
				txbuf1++;
    		         }
			else
			{
				spip->dspi->ASDR0.R= 0xffff; /* PRQA S 2880 */
			}
			*rxbuf = (uint8)spip->dspi->DDR0.R;/* polyspace RTE:NIV */
			rxbuf++;
			dsi_num--;

        }
        Dspi_Timeout = 0U;
        while ((spip->dspi->SR.B.RXCTR > 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
        {
          frame = spip->dspi->POPR.R;/* polyspace RTE:NIV */
          *rxbuf1 = (uint8)frame;/* polyspace RTE:IDP */
          rxbuf1++;
          Dspi_Timeout++;
          if(dsi_rx_num != 0U)
          {
              dsi_rx_num--;
          }
        }
    }
    Dspi_Timeout = 0U;
    while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        Dspi_Timeout++;
    }
   /* Stop transfer.*/
   Spi_Dspi_Stop(spip);
   spip->dspi->SR.R = 0xffffffffU;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/*******************************************************************************
 * @brief   Starts reception without DMA ignoring the received data.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 * @param[in] n         number of words to be exchanged
 *
 * @notapi
 *******************************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_CSI_Send
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) spi_n,
    VAR(uint32, DSPI_VAR) dsi_n,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) txbuf1,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) rxbuf1
)
{
    VAR(uint32, DSPI_VAR) spi_num = spi_n;
    VAR(uint32, DSPI_VAR) dsi_num = dsi_n;
    VAR(uint8, DSPI_VAR) spi_sendnum = 0;
    VAR(uint8, DSPI_VAR) dsi_sendnum = 0;

    /* Starting transfer.*/
    Spi_Dspi_Start(spip);

    while ((dsi_num > 0U) || (spi_num > 0U))
    {
        if (spi_num > DSPI_FIFO_DEPTH)
        {
            spi_sendnum = DSPI_FIFO_DEPTH;
        }
        else
        {
            spi_sendnum = (uint8)spi_num;
        }

        if (dsi_num > DSPI_FIFO_DEPTH)
        {
            dsi_sendnum = DSPI_FIFO_DEPTH;
        }
        else
        {
            dsi_sendnum = (uint8)dsi_num;
        }

        Cdsi_Prefill_Tx8(spip, spi_sendnum, dsi_sendnum, txbuf, txbuf1, rxbuf, rxbuf1);
        dsi_num -= dsi_sendnum;
        spi_num -= spi_sendnum;
        txbuf += DSPI_FIFO_DEPTH;
        txbuf1 += DSPI_FIFO_DEPTH;
        rxbuf += DSPI_FIFO_DEPTH;
        rxbuf1 += DSPI_FIFO_DEPTH;

    }
    /* Stop transfer.*/
    Spi_Dspi_Stop(spip);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) DSPI_LLD_CSI_TSB_Tx
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) tsbcmd_n,
    VAR(uint32, DSPI_VAR) tsbdata_n,
    P2VAR(uint8, AUTOMATIC, DSPI_APPL_DATA) tsbcmd,
    P2CONST(uint8, AUTOMATIC, DSPI_APPL_CODE) tsbdata
)
{
    VAR(uint32, DSPI_VAR) cmd = 0;
    VAR(uint32, DSPI_VAR) frame = 0;
    VAR(uint32, DSPI_VAR) move_check_variable_1 = 31U;
    VAR(uint32, DSPI_VAR) move_check_variable_2 = 27U;
    VAR(uint32, DSPI_VAR) move_check_variable_3 = 16U;
    VAR(uint32, DSPI_VAR) Dspi_Timeout;

    /* Starting transfer.*/
    Spi_Dspi_Start(spip);
    if((move_check_variable_1 <= 32U) && (move_check_variable_2 <= 32U) && (move_check_variable_3 <= 32U) && ((uint32)(spip->Cdsiconfig->whichPCS) <= 32U)) /* polyspace RTE:NIV,IDP */
    {
        cmd = (((((uint32)(spip->Cdsiconfig->continuousPCS)) << 31) & /* polyspace RTE:NIV */ 
                    (~(((uint32)(spip->Cdsiconfig->continuousPCS)) << 27))) | /* polyspace RTE:NIV */ 
                    ((uint32)(((uint32)1) << ((uint32)(spip->Cdsiconfig->whichPCS))) << 16)); /* polyspace RTE:NIV,SHF */
    }

    *tsbcmd |=  1U << (7U);  //  Selection bit for SPI frame is inserted by software;

    while ((spip->dspi->SR.B.TXCTR < DSPI_FIFO_DEPTH) && (tsbcmd_n > 0U)) /* polyspace RTE:NIV */
    {
      frame = *tsbcmd; /* polyspace RTE:IDP */
      (tsbcmd)++;
	
      tsbcmd_n--;
      if (tsbcmd_n == 0U)
      {
        spip->dspi->PUSHR.PUSHR.R = (PUSHR_EOQ | cmd | frame) & (~PUSHR_CONT);
        break;
      }
      spip->dspi->PUSHR.PUSHR.R = cmd | frame;
    }
    Dspi_Timeout = 0U;
    while ((spip->dspi->SR.B.EOQF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        Dspi_Timeout++;
    }
    spip->dspi->SR.B.EOQF = 1U;

    while (tsbdata_n != 0U)
    {
        spip->dspi->ASDR0.R = *tsbdata; /* polyspace RTE:IDP */
	    tsbdata++;
        Dspi_Timeout = 0U;
        while ((spip->dspi->SR.B.TCF == 0U) && (Dspi_Timeout < DEFAULT_TIMEOUT)) /* polyspace RTE:NIV */
        {
            Dspi_Timeout++;
        }
        spip->dspi->SR.B.TCF = 1U;
        tsbdata_n--;
    }

    /* Stop transfer.*/
    Spi_Dspi_Stop(spip); 
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) spi_serve_dma_error_irq
(
    P2CONST(uint32, AUTOMATIC, DSPI_APPL_CODE) p
)/*PRQA S 3673*/
{
    /*Casting of void pointer needful for using the same DMA driver
      in different drivers. */
    CONSTP2VAR(SPIDriver_t, ADC_CONST, ADC_APPL_CONST) spip = (SPIDriver_t *)p; 

    /* Stops the transfer.*/
    Spi_Dspi_Stop(spip);
    EDMA_LLD_ErrorIRQHandler((uint8)spip->tx1_channel);
    EDMA_LLD_ErrorIRQHandler((uint8)spip->tx2_channel);
    EDMA_LLD_ErrorIRQHandler((uint8)spip->rx_channel);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
/****************************************************************
 * @brief   Shared ISR for EOQF DSPI events.
 *
 * @param[in] spip      pointer to the @p SPIDriver_t object
 *
 * @notapi
 ***************************************************************/
#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
FUNC(void, DSPI_CODE) spi_serve_dspi_tcf
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip
)
{
    /* Interrupt served.*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_44();
    spip->dspi->SR.R = RSER_TCF_RE;/* polyspace RTE:IDP */
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_44();
    /* Stops the transfer.*/
    Spi_Dspi_Stop(spip);

    /* Call the related callback.*/
    if (spip->Cdsiconfig->callback != NULL) { /* polyspace RTE:NIP,IDP */ 
    spip->Cdsiconfig->callback(spip);/* polyspace RTE:COR */
    }

    SPI_TXRX_DONE(spip);
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) spi_serve_dspi_eoqf
(
    P2VAR(SPIDriver_t, AUTOMATIC, DSPI_APPL_DATA) spip
)
{
    /* Emptying the RX FIFO.*/
      while ((spip->dspi->SR.B.RXCTR > 0U) && (spip->rx_cnt > 0U)) /* polyspace RTE:NIV,IDP */ 
      {
      VAR(uint32, DSPI_VAR) frame = spip->dspi->POPR.R;/* polyspace RTE:NIV */

      if (spip->rx.rx_ptr != NULL)
      {
      #if  FEATURE_DSPI_HAS_EXTENDED_MODE

        *spip->rx.rx_ptr32 = (uint32)frame;
        spip->rx.rx_ptr32++;
      #else

        if (spip->dspi->MODE.CTAR[0].B.FMSZ < 8U)/* polyspace RTE:NIV */
        {
          *spip->rx.rx_ptr8 = (uint8)frame;/* polyspace RTE:IDP */
           spip->rx.rx_ptr8++;
        }
        else
        {
          *spip->rx.rx_ptr16 = (uint16)frame;/* polyspace RTE:IDP */
          spip->rx.rx_ptr16++;
        }
    #endif
      }
      spip->rx_cnt--;
    }

    /* Interrupt served.*/
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_45();
    spip->dspi->SR.R = RSER_EOQF_RE;

    /* Done with transfer, disable interrupt */
    spip->dspi->RSER.B.EOQF_RE = 0;
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_45();

    if (spip->rx_cnt == 0U)
    {
      /* Stops the transfer.*/
      Spi_Dspi_Stop(spip);

      /* Call the related callback.*/
      if (spip->Cdsiconfig->callback != NULL)/* polyspace RTE:NIP,IDP */
      {
        spip->Cdsiconfig->callback(spip);/* polyspace RTE:COR */
      }

      SPI_TXRX_DONE(spip);
    }
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(status_t, DSPI_CODE) DSPI_TrannsferFail
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip
)
{
    /* Halt DSPI */
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_46();
    spip->dspi->MCR.B.HALT = 1U; /* polyspace RTE:IDP */

    /* Disable and clear all interrupts. */
    spip->dspi->RSER.B.TFFF_RE = 0U;
    spip->dspi->RSER.B.RFDF_RE = 0U;
    spip->dspi->RSER.B.RFOF_RE = 0U;
    spip->dspi->RSER.B.TFUF_RE = 0U;

    spip->dspi->SR.R = SR_RFDF|SR_TFFF|SR_TFUF|SR_RFOF ;

    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_46();
    return STATUS_SUCCESS;
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CODE
#include "CDD_DSpi_MemMap.h"
extern FUNC(void, DSPI_CODE) SPI_LLD_SetDsiTRGPRD
(
    P2CONST(SPIDriver_t, AUTOMATIC, DSPI_APPL_CODE) spip,
    VAR(uint32, DSPI_VAR) trig_period
)
{
    SchM_Enter_CDD_DSpi_EXCLUSIVE_AREA_36();    
    spip->dspi->DSICR1.B.TRGPRD = trig_period;/* polyspace RTE:IDP */
    SchM_Exit_CDD_DSpi_EXCLUSIVE_AREA_36();
}
#define CDD_DSPI_STOP_SEC_CODE
#include "CDD_DSpi_MemMap.h"
#ifdef __cplusplus
}
#endif
