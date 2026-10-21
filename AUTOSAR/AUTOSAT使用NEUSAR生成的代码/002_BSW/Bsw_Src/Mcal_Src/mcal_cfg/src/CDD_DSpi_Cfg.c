/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : DSPI
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*  
*****************************************************************************/
/*PRQA S 0380,1533 EOF*/
/**
*   @file    CDD_DSpi_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Dspi MCAL driver.
*
*   @addtogroup Dspi
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_DSpi.h"

#define CDD_DSPI_CFG_CCFG_C_VENDOR_ID_OUTPUT                       176
#define CDD_DSPI_CFG_CAR_RELEASE_MAJOR_VERSION_OUTPUT        4
#define CDD_DSPI_CFG_CAR_RELEASE_MINOR_VERSION_OUTPUT        4
#define CDD_DSPI_CFG_CAR_RELEASE_REVISION_VERSION_OUTPUT     0
#define CDD_DSPI_CFG_CSW_MAJOR_VERSION_OUTPUT                3
#define CDD_DSPI_CFG_CSW_MINOR_VERSION_OUTPUT                0
#define CDD_DSPI_CFG_CSW_PATCH_VERSION_OUTPUT                0

#if (CDD_DSPI_CFG_CCFG_C_VENDOR_ID_OUTPUT != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : CDD_DSPI_CFG_CCFG_C_VENDOR_ID_OUTPUT"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (CDD_DSPI_CFG_CAR_RELEASE_MAJOR_VERSION_OUTPUT != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_CFG_CAR_RELEASE_MAJOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_CFG_CAR_RELEASE_MINOR_VERSION_OUTPUT != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_CFG_CAR_RELEASE_MINOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_CFG_CAR_RELEASE_REVISION_VERSION_OUTPUT != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_CFG_CAR_RELEASE_REVISION_VERSION_OUTPUT"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (CDD_DSPI_CFG_CSW_MAJOR_VERSION_OUTPUT != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCACDD_DSPI_CFG_CSW_MAJOR_VERSION_OUTPUTL_SW_MAJOR_VER"
#endif
#if (CDD_DSPI_CFG_CSW_MINOR_VERSION_OUTPUT != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_CFG_CSW_MINOR_VERSION_OUTPUT"
#endif
#if (CDD_DSPI_CFG_CSW_PATCH_VERSION_OUTPUT != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : CDD_DSPI_CFG_CSW_PATCH_VERSION_OUTPUT"
#endif




#define CDD_DSPI_START_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"
static CONST(spi_config_t, DSPI_CONST) dspi_configs[CDD_DSPI_CONTROLLER_COUNT] =
{
    {
        .WhichSpiController = CDD_DSPI0,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI1,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 625000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_CSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI2,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_CSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_ENABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_ENABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI3,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI4,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI5,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 9900000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI6,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI7,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI8,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI9,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI10,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI11,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI12,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI13,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI14,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI15,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI16,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI17,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI18,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 4U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 4U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 4U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI19,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI20,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 0U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 0U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 0U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
    {
        .WhichSpiController = CDD_DSPI21,
        .DSpi_Clock = 100000000,
        .bitsPerSec = 5000000,
        .pcsPolarity = SPI_INACTIVE_HIGH,
        .bitcount = 8,
        .clkPhase = SPI_CLOCK_PHASE_2ND_EDGE,
        .clkPolarity = SPI_ACTIVE_HIGH,
        .isClkContinuous = FALSE,
        .lsbFirst = FALSE,
        .transferType = SPI_USING_INTERRUPTS,
        .dmaType = DSPI_DMA_NONE,
        .callback = NULL_PTR,
        .continuousPCS = TRUE,
        .whichPCS = 4U,
        /*********************DSI CSI CONFIG****************************/
        .Dconf = (uint8_t)DSPI_DSI_MODE,
        .TSBC = (uint8_t)DSPI_TSBC_DISABLE,
        .ITSBC = (uint8_t)DSPI_ITSBC_DISABLE,
        .DsiDataSource = 1U,
        .isCID = 1U,
        .istrre = 0U,
        .tpol = 0U,
        .Dcont = 0U,
        
        .DSICTAx = 0U,
        .whichDSIPCS = 4U,
        .TSBCNT = 8,
        .SDR1En = 1U,
        .DataSelect0En = 0U,
        .DataSelect1En = 0U,
        .whichTSBPCS = 4U,
        .spi_mode = SPI_MASTER,
        /*********************GTM MSC CONFIG****************************/
        #if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
        .MSCConfig = NULL_PTR
        #endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */
    },
};
#define CDD_DSPI_STOP_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"



#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
#define CDD_DSPI_START_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"
static CONST(gtm_msc_set_sel_t, DSPI_CONST) gtmMSCSetSelMap[0] =
{
};
#define CDD_DSPI_STOP_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"
#endif /* STD_ON == CDD_DSPI_GTM_MSC_ENABLE */

#define CDD_DSPI_START_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"
static CONST(mdspi_core_map_t, DSPI_CONST) Mdspi_CoreMap[CDD_DSPI_CONTROLLER_COUNT] =
{
    {
        .WhichSpiController = CDD_DSPI0,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI1,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI2,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI3,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI4,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI5,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI6,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI7,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI8,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI9,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI10,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI11,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI12,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI13,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI14,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI15,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI16,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI17,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI18,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI19,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI20,
        .Dspi_CoreId = 0U
    },
    {
        .WhichSpiController = CDD_DSPI21,
        .Dspi_CoreId = 0U
    },
};
#define CDD_DSPI_STOP_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"

#define CDD_DSPI_START_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"
CONST(CDD_DSpi_ConfigType, DSPI_CONST) CDD_DSpi_Config =
{
    .dspiConfig = dspi_configs,
#if STD_ON == CDD_DSPI_GTM_MSC_ENABLE
    .gtmMSCSetConfig = gtmMSCSetSelMap,
#endif
    .coreMap = Mdspi_CoreMap
};
#define CDD_DSPI_STOP_SEC_CONFIG_DATA
#include "CDD_DSpi_MemMap.h"

#ifdef __cplusplus
}
#endif
