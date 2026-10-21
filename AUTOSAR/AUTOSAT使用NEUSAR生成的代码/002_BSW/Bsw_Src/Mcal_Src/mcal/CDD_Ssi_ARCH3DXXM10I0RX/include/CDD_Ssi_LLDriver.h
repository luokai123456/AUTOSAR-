/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CDD_Ssi
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/
/* PRQA S 1535 EOF */
/**
*   @file    CDD_Ssi_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CDD SSI MCAL driver.
*
*   @addtogroup CDD SSI
*   @{
*/
/*PRQA S 1753 EOF*/
#ifndef CDD_SSI_LLDRIVER_H
#define CDD_SSI_LLDRIVER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#include "eDma_LLDriver.h"
#include "Mcal.h"
#include "CDD_Ssi_Cfg.h"

#define CDD_LLD_WRA_H_VENDOR_ID                     176
#define CDD_LLD_WRA_H_AR_REL_MAJOR_VER              4
#define CDD_LLD_WRA_H_AR_REL_MINOR_VER              4
#define CDD_LLD_WRA_H_AR_REL_REV_VER                0
#define CDD_LLD_WRA_H_SW_MAJOR_VER                  3
#define CDD_LLD_WRA_H_SW_MINOR_VER                  0
#define CDD_LLD_WRA_H_SW_PATCH_VER                  0

#if (CDD_VENDOR_ID_OUTPUT != CDD_LLD_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_VENDOR_ID "
#endif
#if (CDD_AR_REL_MAJOR_VER_OUTPUT != CDD_LLD_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (CDD_AR_REL_MINOR_VER_OUTPUT != CDD_LLD_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_AR_REL_MINOR_VER "
#endif
#if (CDD_AR_REL_REVISION_VER_OUTPUT != CDD_LLD_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_AR_REL_REV_VER "
#endif
#if (CDD_SW_MAJOR_VERSION_OUTPUT != CDD_LLD_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_SW_MAJOR_VER "
#endif
#if (CDD_SW_MINOR_VERSION_OUTPUT != CDD_LLD_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_SW_MINOR_VER "
#endif
#if (CDD_SW_PATCH_VERSION_OUTPUT != CDD_LLD_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_LLD_WRA_H_SW_PATCH_VER "
#endif

#ifdef RESOURCE_SUPPORT_SSI_IP
typedef  struct SSI_tag                   SSI_Type;
/* SSI - Peripheral instance base addresses */
/** Peripheral SSI0 base address */
#define SSI0_BASE                               ((uint32_t)&SSI0)
/** Peripheral SSI0 base pointer */
#define SSI0_StPtr                              ((SSI_Type *)SSI0_BASE)
#ifdef  RESOURCE_SUPPORT_SSI1
/** Peripheral SSI0 base address */
#define SSI1_BASE                               ((uint32_t)&SSI1)
/** Peripheral SSI0 base pointer */
#define SSI1_StPtr                              ((SSI_Type *)SSI1_BASE)
#endif


/*---macro definition-----------------------------------------------------------*/

/**
  *@brief SSI_FlagIndexTypeDef
  */
typedef enum
{
    SSI_FLAG_INDEX_BUSY = 0x01U,
    SSI_FLAG_INDEX_TFNF = 0x02U,
    SSI_FLAG_INDEX_TFE  = 0x04U,
    SSI_FLAG_INDEX_RFNE = 0x08U,
    SSI_FLAG_INDEX_RFF  = 0x10U,
}SSI_FlagIndexTypeDef;

#define SSI_EN                                        ((uint32)(1<<24U))
/*****************************************************************************/
/*bit operation*/

/**
  * @brief SPI status
  */
typedef enum
{
    DRV_SSI_OK       = 0x00U,
    DRV_SSI_ERROR    = 0x01U,
    DRV_SSI_BUSY     = 0x02U,
    DRV_SSI_TIMEOUT  = 0x03U,
}DRV_SSI_StatusTypeDef;
/**
  * @brief SPI flash read or write status
  */
typedef enum
{
    DRV_SSI_READ   = 0x00U,
    DRV_SSI_WRITE  = 0x01U,
}DRV_SSI_ReadTypeDef;
/**
  * @brief DFS definition
  */
typedef enum
{
    DFS_01_BIT  = 0x00U,
    DFS_02_BIT  = 0x01U,
    DFS_03_BIT  = 0x02U,
    DFS_04_BIT  = 0x03U,
    DFS_05_BIT  = 0x04U,
    DFS_06_BIT  = 0x05U,
    DFS_07_BIT  = 0x06U,
    DFS_08_BIT  = 0x07U,
    DFS_09_BIT  = 0x08U,
    DFS_10_BIT  = 0x09U,
    DFS_11_BIT  = 0x0aU,
    DFS_12_BIT  = 0x0bU,
    DFS_13_BIT  = 0x0cU,
    DFS_14_BIT  = 0x0dU,
    DFS_15_BIT  = 0x0eU,
    DFS_16_BIT  = 0x0fU,
    DFS_17_BIT  = 0x10U,
    DFS_18_BIT  = 0x11U,
    DFS_19_BIT  = 0x12U,
    DFS_20_BIT  = 0x13U,
    DFS_21_BIT  = 0x14U,
    DFS_22_BIT  = 0x15U,
    DFS_23_BIT  = 0x16U,
    DFS_24_BIT  = 0x17U,
    DFS_25_BIT  = 0x18U,
    DFS_26_BIT  = 0x19U,
    DFS_27_BIT  = 0x1aU,
    DFS_28_BIT  = 0x1bU,
    DFS_29_BIT  = 0x1cU,
    DFS_30_BIT  = 0x1dU,
    DFS_31_BIT  = 0x1eU,
    DFS_32_BIT  = 0x1fU,
}SSI_DFSTypeDef;
/**
  * @brief FRF format definition
  */
typedef enum
{
    FRF_SPI       = 0x00U,
    FRF_SSP       = 0x01U,
    FRF_MICROWIRE = 0x02U,
}SSI_FRFTypeDef;
/**
  * @brief SCPH format definition
  */
typedef enum
{
    SCPH_START_BIT  = 0x01U,
    SCPH_MIDDLE_BIT = 0x00U,
}SSI_SCPHTypeDef;
/**
  * @brief SCPOL format definition
  */
typedef enum
{
    INACTIVE_LOW  = 0x01U,
    INACTIVE_HIGH = 0x00U,
}SSI_SCPOLTypeDef;
/**
  * @brief TMOD format definition
  */
typedef enum
{
    TX_AND_RX   = 0x00U,
    TX_ONLY     = 0x01U,
    RX_ONLY     = 0x02U,
    EEPROM_READ = 0x03U,
}SSI_TMODTypeDef;
/**
  * @brief SRL format definition
  */
typedef enum
{
    NORMAL_MODE   = 0x00U,
    TESTING_MODE  = 0x01U,
}SSI_SRLTypeDef;
/**
  * @brief SSTE format definition
  */
typedef enum
{
    TOGGLE_DISABLE = 0x00U,
    TOGGLE_EN      = 0x01U,
}SSI_SSTETypeDef;
/**
  * @brief CFS format definition
  */
typedef enum
{
    CFS_01_BIT  = 0x00U,
    CFS_02_BIT  = 0x01U,
    CFS_03_BIT  = 0x02U,
    CFS_04_BIT  = 0x03U,
    CFS_05_BIT  = 0x04U,
    CFS_06_BIT  = 0x05U,
    CFS_07_BIT  = 0x06U,
    CFS_08_BIT  = 0x07U,
    CFS_09_BIT  = 0x08U,
    CFS_10_BIT  = 0x09U,
    CFS_11_BIT  = 0x0aU,
    CFS_12_BIT  = 0x0bU,
    CFS_13_BIT  = 0x0cU,
    CFS_14_BIT  = 0x0dU,
    CFS_15_BIT  = 0x0eU,
    CFS_16_BIT  = 0x0fU,
}SSI_CFSTypeDef;
/**
  * @brief SSI format definition
  */
typedef enum
{
    STD_mode   = 0x00U,
    DUAL_mode  = 0x01U,
    QUAD_mode  = 0x02U,
}SSI_FormatTypeDef;

typedef enum
{
    STD_MODE,
    DUAL_MODE,
    QUAD_MODE_FIFO,
    QUAD_MODE_DMA,
    QPI_MODE,
}SSI_OptModTypeDef;
/**
  * @brief SSI transmission definition
  */
typedef enum
{
    TT0 = 0x00U,
    TT1 = 0x01U,
    TT2 = 0x02U,
    TT3 = 0x03U,
}SSI_TransTypeTypeDef;
/**
  * @brief SSI address length
  */
typedef enum
{
    ADDR_L0   = 0x00U,
    ADDR_L4   = 0x01U,
    ADDR_L8   = 0x02U,
    ADDR_L12    = 0x03U,
    ADDR_L16  = 0x04U,
    ADDR_L20  = 0x05U,
    ADDR_L24  = 0x06U,
    ADDR_L28  = 0x07U,
    ADDR_L32  = 0x08U,
    ADDR_L36  = 0x09U,
    ADDR_L40  = 0x0aU,
    ADDR_L44  = 0x0bU,
    ADDR_L48  = 0x0cU,
    ADDR_L52  = 0x0dU,
    ADDR_L56  = 0x0eU,
    ADDR_L60  = 0x0fU,
}SSI_AdressTypeDef;
/**
  * @brief SSI instruction length
  */
typedef enum
{
    INST_L0  = 0x00U,
    INST_L4  = 0x01U,
    INST_L8  = 0x02U,
    INST_L16 = 0x03U,
}SSI_InstructionTypeDef;
/**
  * @brief CLK_STRETCH_EN
  */
typedef enum
{
    CLK_STRETCH_DISABLE = 0x00U,
    CLK_STRETCH_ENABLE  = 0x01U,
}SSI_CLK_STRETCH_ENTypeDef;


/**
  * @brief IMR interrupt index
  */
typedef enum
{
    IMR_XRXOIM  = 0x40000000U,
    IMR_RXFIM   = 0x10000000U,
    IMR_RXOIM   = 0x08000000U,
    IMR_RXUIM   = 0x04000000U,
    IMR_TXOIM   = 0x02000000U,
    IMR_TXEIM   = 0x01000000U
}SSI_IMR_IndexTypedef;

/**
  * @brief DMA TX/RX Index
  */
typedef enum
{
    DMA_TX  = 0x02000000U,
    DMA_RX  = 0x01000000U
}SSI_DMA_IndexTypedef;

typedef enum
{
    RESET = 0U,
    SET   = 1U
}FlagStatusTypeDef;

/**
  *@brief spi init struct definition
  *
  */
typedef struct
{
    uint8 DFS;
    uint8 FRF;
    uint8 SCPH;
    uint8 SCPOL;
    uint8 TMOD;
    uint8 SRL;
    uint8 SSTE;
    uint8 CFS;
    uint8 Format;                      /**
                                         *- STD_mode    Standard SPI Format
                                         *- DUAL_mode   Dual SPI Format
                                         *- QUAD_mode   Quad SPI Format
                                         */
    uint16 NDF;

    uint16 SSI_BaudRatePrescaler;
    uint8 Transfer_start_FIFO_level;   //TXFTLR<<16
    uint8 Transmit_FIFO_Threshold;     //TXFTLR
    uint8 Receive_FIFO_Threshold;        //RXFTLR
    uint8 Trans_Type;
    uint8 Address_Length;
    uint8 Instruction_length;          /**
                                         *- INST_L0   No Instruction
                                         *- INST_L4   4 bit Instruction length
                                         *- INST_L8   8 bit Instruction length
                                         *- INST_L16  6 bit Instruction length
                                         */
    uint8 WAIT_CYCLES;
    uint8 CLK_STRETCH_EN;

} SSI_InitTypeDef;

/*----API-----------------------------------------------------------------------------*/

/**
  *@brief.
  *
  */
typedef enum
{
    SSI_CALLBACK_ID_TXISR,
    SSI_CALLBACK_ID_RXISR,
}SSICallbackIDTypeDef;
/**
  *@brief.
  *
  */
typedef enum
{
    HAL_SSI_STATE_RESET      = 0x00U,        /**< SSI not yet initialized or disabled                */
    HAL_SSI_STATE_READY      = 0x01U,        /**< SSI initialized and ready for use                  */
    HAL_SSI_STATE_BUSY       = 0x02U,        /**< SSI process is ongoing                             */
    HAL_SSI_STATE_BUSY_TX    = 0x12U,        /**< Data Transmission process is ongoing               */
    HAL_SSI_STATE_BUSY_RX    = 0x22U,        /**< Data Reception process is ongoing                  */
    HAL_SSI_STATE_BUSY_TX_RX = 0x32U,        /**< Data Transmission and Reception process is ongoing */
    HAL_SSI_STATE_ERROR      = 0x03U         /**< SSI error state                                    */
} HAL_SSI_StateTypeDef;

typedef void (*HAL_SSI_CALLBACK)(void *parameter);

typedef struct
{
    SSI_Type *Instance;
    SSI_InitTypeDef Init;
    uint8_t *pRxBuf;
    uint32_t RxSize;
    uint16_t RxCnt;
    uint8_t *pTxBuf;
    uint32_t TxSize;
    uint16_t TxCnt;
    HAL_SSI_StateTypeDef State;
    uint32_t ErrorCode;
    HAL_SSI_CALLBACK XferCpltCallback;
    HAL_SSI_CALLBACK ErrCallback;
    HAL_SSI_CALLBACK TxIsrCallback;
    HAL_SSI_CALLBACK RxIsrCallback;
} SSI_HandleTypeDef;

typedef struct
{
	SSI_HandleTypeDef SSIHandle; /* PRQA S 1759,1758,1756 */
	uint32 timeout;
} SSI_ConfigType_t;
/* Exported types ------------------------------------------------------------*/
/**
  * @brief  HAL Status structures definition
  */
typedef enum
{
    SSI_HAL_OK       = 0x00U,
    SSI_HAL_ERROR    = 0x01U,
    SSI_HAL_BUSY     = 0x02U,
    SSI_HAL_TIMEOUT  = 0x03U,
    SSI_HAL_UNKNOW   = 0x04U,

    /*CPM error code*/
    SSI_HAL_CPM_ERROR_SYSCLKDIV_OUTRANGE   = 0x100U,

    /*DMA error code*/
    SSI_HAL_DMA_ERROR_TE                   = 0x110U,
    SSI_HAL_DMA_ERROR_CHANNEL_OUTRANG      = 0x111U,
} SSI_HAL_StatusTypeDef;

/**
  * @}
  */
typedef enum {
    SSI_MOD_ID_0,
    SSI_MOD_ID_1,
    SSI_MOD_ID_BUF
}eSsiModuleId;

typedef struct {
    uint8_t  edma_ch;
    eDMARequestSourceType edma_mux;
    boolean triggerEn;
}SsiEdmaConfigCh;
typedef struct {
    /* LIN_HW_CH_MAX was defined in CCFC30XX_features.h */
    SsiEdmaConfigCh ssi_edma_tx;
    SsiEdmaConfigCh ssi_edma_rx;
}SsiEdmaConfig;

#if defined RESOURCE_SUPPORT_SIUL2_IP
typedef struct {
    uint32_t pad_num;
    uint32_t mscr_io;
    uint32_t mscr_siul2;
    uint8_t mscr_sss;
} SsiGpioSiul2Cell;

typedef struct {
    SsiGpioSiul2Cell sck;
    SsiGpioSiul2Cell cs;
    SsiGpioSiul2Cell da_0;
    SsiGpioSiul2Cell da_1;
    SsiGpioSiul2Cell da_2;
    SsiGpioSiul2Cell da_3;
}SsiGpioSiul2;
#endif

#if defined RESOURCE_SUPPORT_SIUL_IP
typedef struct {
    uint16_t pad_num;
    uint16_t pcr_val;
}SsiGpioSiulCell;

typedef struct {
    SsiGpioSiulCell sck;
    SsiGpioSiulCell cs;
    SsiGpioSiulCell da_0;
    SsiGpioSiulCell da_1;
    SsiGpioSiulCell da_2;
    SsiGpioSiulCell da_3;
}SsiGpioSiul;
#endif
/*** 锟斤拷锟斤拷锟斤拷锟斤拷 ******************************************************************/
DRV_SSI_StatusTypeDef DRV_SSI_GetFlag(SSI_Type const *pssi,SSI_FlagIndexTypeDef FlagIndex,FlagStatusTypeDef *pflag);
DRV_SSI_StatusTypeDef DRV_SSI_Check_STD_Mode(const SSI_Type *pssi);
DRV_SSI_StatusTypeDef DRV_SSI_WaitonFlagTimeout(const SSI_Type *pssi,
                                            SSI_FlagIndexTypeDef index,
                                            FlagStatusTypeDef status,
                                            uint32_t timeout);
SSI_HAL_StatusTypeDef DrvSSIStatusToHalStatus(DRV_SSI_StatusTypeDef DrvStatus);
DRV_SSI_StatusTypeDef DRV_SSI_Clear_Fifo(const SSI_Type *pssi,uint32_t timeout);
void DRV_SSI_En(SSI_Type *pssi);
void DRV_SSI_Dis(SSI_Type *pssi);
void DRV_SSI_Init(SSI_Type *pssi, const SSI_InitTypeDef *pinit);


#ifdef SSI_MODULE_0_SUPPORT
#define SSI_CS_OUT_LOW      SSI_0_CS_OUT_LOW
#define SSI_CS_OUT_HIGH     SSI_0_CS_OUT_HIGH
#define SSI_MOD_ID 0
#else /* DEFAULT */
#define SSI_CS_OUT_LOW      SSI_1_CS_OUT_LOW
#define SSI_CS_OUT_HIGH     SSI_1_CS_OUT_HIGH
#define SSI_MOD_ID 1
#endif

#endif  /* RESOURCE_SUPPORT_SSI_IP */

#ifdef __cplusplus
}
#endif

#endif /* CDD_SSI_LLDRIVER_H */
