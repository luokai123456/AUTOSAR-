/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETH
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/
/* PRQA S 0380, 3432, 4115, 4558, 1258, 2877, 0751, 2985, 4542, 4543, 1281, 2004, 4532 EOF */
/* PRQA S 0488, 0491, 0492, 2844, 3604, 3344, 2982, 2755, 1841, 1843, 1840, 2052, 2890 EOF */   /* CWE */
/**
*   @file    Eth_GMAC_LLDrivers.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#include "Eth_GMAC_LLDriver.h"
#include "EthIf_Cbk.h"
#include "SchM_Eth.h"

#define ETH_GMAC_LLD_C_VENDOR_ID                     176
#define ETH_GMAC_LLD_C_AR_REL_MAJOR_VER              4
#define ETH_GMAC_LLD_C_AR_REL_MINOR_VER              4
#define ETH_GMAC_LLD_C_AR_REL_REV_VER                0
#define ETH_GMAC_LLD_C_SW_MAJOR_VER                  3
#define ETH_GMAC_LLD_C_SW_MINOR_VER                  0
#define ETH_GMAC_LLD_C_SW_PATCH_VER                  0

#if (ETH_CFG_H_VENDOR_ID != ETH_GMAC_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_GMAC_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_GMAC_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_GMAC_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_GMAC_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_GMAC_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_GMAC_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_C_SW_PATCH_VER "
#endif

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define GMAC_LLD_CRC32_POLYVAL 0xEDB88320U
/**
* @brief   Initial value of CRC32 calculation register
*/
#define GMAC_LLD_CRC32_INITVAL 0xFFFFFFFFU
#endif

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
typedef struct
{
    VAR(boolean, AUTOMATIC) is_active;
    VAR(uint8, AUTOMATIC) phys_addr[6];
} Gmac_LLD_McastPoolItemType;
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

/**
* @brief    Address of Rx buffers ring start
* @details  Used for optimization of buffer address computation.
*           It is initialized during TX buffers initialization.
*/
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static VAR(uint32, AUTOMATIC) s_Gmac_LLD_u32RxBufStartAddr[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_RXFIFO_CONFIG];/* PRQA S 0940 */
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
/**
* @brief    Address of Tx buffers ring start
* @details  Used for optimization of buffer address computation.
*           It is initialized during TX buffers initialization.
*/
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static VAR(uint32, AUTOMATIC) s_Gmac_LLD_u32TxBufStartAddr[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_TXFIFO_CONFIG];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static VAR(uint8, AUTOMATIC) s_Eth_u8LockedTxBufCount[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_TXFIFO_CONFIG];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"

/**
* @brief          Active transmit buffer descriptor index
* @details        This variable contains index of the buffer descriptor which
*                 will be used for transmission after the TDAR register is
*                 written.
* @implements     Eth_u8ActiveTxBD_Object */
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static volatile VAR(uint8, AUTOMATIC) s_Eth_u8ActiveTxBD[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_TXFIFO_CONFIG];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
/**
* @brief          Active receive buffer descriptor index
* @details        This variable contains number of the buffer descriptor which
*                 will be used  for the first reception from the time of the
*                 last call of the receive function.
* 
* @implements     Eth_u8ActiveRxBuf_Object */
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static volatile VAR(uint8, AUTOMATIC) s_Eth_u8ActiveRxBuf[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_RXFIFO_CONFIG];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
/**
* @brief        Index of buffer where to continue search for free buffers
* @details      This variable is used to reduce buffer memory fragmentation.
*               Algorithm tries to allocate new buffers right after previously
*               allocated buffers.
*/
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static VAR(uint8, AUTOMATIC) s_Gmac_LLD_u8SearchTxBufFrom[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_TXFIFO_CONFIG];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"

/**
* @brief        An array containing buffer flags.
* @details      Use buffer index for indexing this array.
*               It contains 4 flags for each buffer:
*               TXB_LOCK 8, TXB_CONF 4, TXB_LINK 2, TXB_FIRST 1 
*/
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static volatile VAR(uint8, AUTOMATIC) s_Eth_au8TxBufFlags[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_TXFIFO_CONFIG][TX_BUFFER_COUNT];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"

#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
/**
* @brief        Number of buffers allocated together for one frame
* @details      Use buffer index for indexing this array.
*
*/

#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static VAR(uint8, AUTOMATIC) s_Gmac_LLD_au8TxBufGroup[ETH_MAXCTRLS_SUPPORTED][ETH_MAX_TXFIFO_CONFIG][TX_BUFFER_COUNT];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"

#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */

#define ETH_START_SEC_VAR_INIT
#include "Eth_MemMap.h"
static P2CONST(GmacCfg, ETH_VAR, ETH_APPL_CONST) s_pGmac_cfg[ETH_MAXCTRLS_SUPPORTED] = {NULL_PTR};
#define ETH_STOP_SEC_VAR_INIT
#include "Eth_MemMap.h"

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"
static VAR(Gmac_LLD_McastPoolItemType, AUTOMATIC) s_Gmac_LLD_MulticastPool[ETH_MAXCTRLS_SUPPORTED][ETH_MULTICAST_POOL_SIZE];
#define ETH_STOP_SEC_VAR_NO_INIT
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT
#include "Eth_MemMap.h"
static VAR(uint16, AUTOMATIC) s_Gmac_LLD_McastItemsCnt[ETH_MAXCTRLS_SUPPORTED] = {0U};
#define ETH_STOP_SEC_VAR_INIT
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT
#include "Eth_MemMap.h"
static VAR(boolean, AUTOMATIC) s_Gmac_LLD_McastPoolOvf[ETH_MAXCTRLS_SUPPORTED] = {(boolean)FALSE};
#define ETH_STOP_SEC_VAR_INIT
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_INIT
#include "Eth_MemMap.h"
static VAR(boolean, AUTOMATIC) s_Gmac_LLD_McastFullOpen[ETH_MAXCTRLS_SUPPORTED] = {(boolean)FALSE};
#define ETH_STOP_SEC_VAR_INIT
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(boolean, ETH_CODE) Gmac_LLD_Compare_Phys_Addr \
( \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phy_addrA, \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phy_addrB \
)
{
    /* Return variable */
    VAR(boolean, AUTOMATIC) ret = (boolean)TRUE;
    VAR(uint8, AUTOMATIC) i;

    for (i = 0U; i < 6U; i++)
    {
        if (phy_addrA[i] != phy_addrB[i])
        {
            ret = (boolean)FALSE;
            break;
        }
    }
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(boolean, ETH_CODE) GMAC_LLD_Is_Addr_In_Mcast_Pool \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phys_addr_ptr, \
    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_CONST) pool_item_idx \
)
{
    /* Temporary return variable / Matching entry found */
    VAR(boolean, AUTOMATIC) is_address_found = (boolean)FALSE;
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) pool_idx = 0U;
    /* Used for counting of found active items in loop */
    VAR(uint16, AUTOMATIC) found_cnt = 0U;

    /* Loop over multicast pool */
    while ((found_cnt !=  s_Gmac_LLD_McastItemsCnt[gmac_id]) && (ETH_MULTICAST_POOL_SIZE > pool_idx))
    {
        /* Filter only active entries */
        if ((boolean)TRUE == s_Gmac_LLD_MulticastPool[gmac_id][pool_idx].is_active)
        { /* Item is active */
            if ((boolean)TRUE == Gmac_LLD_Compare_Phys_Addr(phys_addr_ptr, s_Gmac_LLD_MulticastPool[gmac_id][pool_idx].phys_addr))
            { /* Item matches with requested */
                is_address_found = (boolean)TRUE;
                *pool_item_idx = pool_idx;
                break;
            }
            found_cnt++;
        }
        pool_idx++;
    }

    return is_address_found;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Mcast_Pool_Clean(CONST(GmacId, ETH_CONST) gmac_id)
{
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) found_cnt = 0U;

    while (ETH_MULTICAST_POOL_SIZE > found_cnt)
    {
        s_Gmac_LLD_MulticastPool[gmac_id][found_cnt].is_active = (boolean)FALSE;
        found_cnt++;
    }
    s_Gmac_LLD_McastItemsCnt[gmac_id] = 0U;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Phys_Addr_Allowed \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phys_addr_ptr \
)
{
    /* Return variable */
    VAR(boolean, AUTOMATIC) reception_allowed;
    /* Multicast Pool table item index */
    VAR(uint16, AUTOMATIC) mulCast_found_cnt;

    if ((boolean)TRUE == s_Gmac_LLD_McastPoolOvf[gmac_id])
    { /* Multicast filter overflow detected */
        reception_allowed = (boolean)TRUE;
    }
    else if ((boolean)TRUE == s_Gmac_LLD_McastFullOpen[gmac_id])
    { /* Filter is fully open */
        reception_allowed = (boolean)TRUE;
    }
    else
    {
        reception_allowed = GMAC_LLD_Is_Addr_In_Mcast_Pool(gmac_id, phys_addr_ptr, &mulCast_found_cnt);
    }

    return reception_allowed;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
static volatile FUNC(GmacReg *, ETH_CODE) Gmac_LLD_Get_Reg(VAR(GmacId, AUTOMATIC) gmac_id)
{
    static volatile CONSTP2VAR(GmacReg, AUTOMATIC, ETH_APPL_CONST) reg[GMAC_ID_BUTT] =
    {
        (volatile GmacReg*)&GMAC_0,
    };
    return reg[gmac_id]; /* polyspace RTE:OBAI */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Enable \
( \
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg \
)
{
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.B.SR = 1U; /* polyspace RTE:NIV */ /* start receive */
    gmac_reg->DMA_CH[0].DMA_CH_TX_CONTROL.B.ST = 1U; /* start transmit */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Enable_Controller(VAR(GmacId, AUTOMATIC) gmac_id)
{
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg;
    VAR(uint8, AUTOMATIC) fifo_idx = 0U;

    s_Eth_u8ActiveRxBuf[gmac_id][fifo_idx] = 0U;
    s_Eth_u8ActiveTxBD[gmac_id][fifo_idx] = 0U;
    s_Eth_u8LockedTxBufCount[gmac_id][fifo_idx] = 0U;

    gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    gmac_reg->MAC_CONFIGURATION.B.TE = 1U;
    gmac_reg->MAC_CONFIGURATION.B.RE = 1U;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Disable_Controller(VAR(GmacId, AUTOMATIC) gmac_id)
{
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg;

    gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    gmac_reg->MAC_CONFIGURATION.B.TE = 0U;
    gmac_reg->MAC_CONFIGURATION.B.RE = 0U;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_ModeType, ETH_CODE) Gmac_LLD_Check_Ctrl_Is_Active(VAR(GmacId, AUTOMATIC) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg;
    VAR(Eth_ModeType, AUTOMATIC) ret = ETH_MODE_DOWN;
    gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    if(gmac_reg->MAC_CONFIGURATION.B.TE == 1U)/* polyspace RTE:NIV */
    {
        if(gmac_reg->MAC_CONFIGURATION.B.RE == 1U)/* polyspace RTE:NIV */
        {
            ret = ETH_MODE_ACTIVE;
        }
    }

    return ret;
}   
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Gmac_LLD_Reset(CONST(GmacId, ETH_CONST) gmac_id)  /* PRQA S 1505 */
{
    VAR(uint32, AUTOMATIC) u32Timer = 0U;
    P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    /* Clear multicast pool buffer */
    Gmac_LLD_Mcast_Pool_Clean(gmac_id);
    /* Clear MulticastPool flags */
    s_Gmac_LLD_McastPoolOvf[gmac_id] = (boolean)FALSE;
    s_Gmac_LLD_McastFullOpen[gmac_id] = (boolean)FALSE;
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
    volatile VAR(uint32, AUTOMATIC) delay_cnt = 4U; /* at least delay 4 cycle */
    gmac_reg->DMA_MODE.B.SWR = 1U;
    while (delay_cnt != 0U)
    {
        delay_cnt--; /* PRQA S 3387 */
    }
    do
    {
        u32Timer++;
    }
    while ((gmac_reg->DMA_MODE.B.SWR == 1U) && (u32Timer < DEFAULT_TIMEOUT));

    if(gmac_reg->DMA_MODE.B.SWR == 1U)
    {
        return STATUS_TIMEOUT;
    }
    else
    {
        return STATUS_SUCCESS;
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Record_Cfg \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
)
{
    s_pGmac_cfg[gmac_id] = gmac_cfg;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(const GmacCfg *, ETH_CODE)Gmac_LLD_Require_Cfg(VAR(GmacId, AUTOMATIC) gmac_id)
{
    return s_pGmac_cfg[gmac_id];
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Dma_Cfg \
( \
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
)
{
    gmac_reg->MTL_OPERATION_MODE.B.SCHALG = 2U; /* DWRR */ /*Tx Scheduling Algorithm*/
    gmac_reg->MTL_TXQ0_OPERATION_MODE.B.TXQEN = 2U; /* Enabled */
    gmac_reg->MTL_TXQ0_OPERATION_MODE.B.TTC = 0U; /* Transmit Threshold Control is 32 */
    gmac_reg->MTL_TXQ0_OPERATION_MODE.B.TSF = 1U; /* Transmit Store and Forward is enabled */
    gmac_reg->MTL_TXQ0_OPERATION_MODE.B.TQS = 15U; /* Transmit Queue Size is 15 */
    gmac_reg->MTL_RXQ0_OPERATION_MODE.B.RQS = 0x3FU; /* Receive Queue Size is 255 */
    gmac_reg->MTL_RXQ0_OPERATION_MODE.B.RTC = 1U;   /* Receive Threshold Control: 32 bytes */
    gmac_reg->MTL_RXQ0_OPERATION_MODE.B.RSF = 0U;   /* Receive Store and Forward */
    gmac_reg->MTL_RXQ0_CONTROL.R = 0U; /* Receive Queue Packet Arbitration is disabled */
    gmac_reg->MAC_RXQ_CTRL0.B.RXQ0EN = 2U; /* : Queue enabled for DCB/Generic */
    gmac_reg->MAC_RXQ_CTRL1.R = 0U;
    gmac_reg->MAC_RXQ_CTRL2.R = 0U;
    gmac_reg->MTL_RXQ_DMA_MAP0.B.Q0DDMACH = 0U;
    gmac_reg->MTL_RXQ_DMA_MAP0.B.Q0MDMACH = 0U;  // Queue 0 Mapped to DMA Channel 0
    gmac_reg->DMA_SYSBUS_MODE.B.MB = 1U; /* Mixed Burst is enabled */
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.R |= ((uint32)1U << 16U); /* polyspace RTE:OBAI,NIV */ /* 8xPBL mode is enabled */
    gmac_reg->DMA_CH[0].DMA_CH_TX_CONTROL.B.TXPBL = 0x8U; /* Transmit Programmable Burst Length */
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.R |= ((uint32)(((uint32)(0x3FFFUL<<1))|((uint32)(0x8UL<<16)))); // Receive Programmable Burst Length && Receive Buffer size

    if ((gmac_cfg->EnableRxInterrupt) || (gmac_cfg->EnableTxInterrupt)) /* polyspace RTE:NIV */
    {
        gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.TIE = 1U; /* polyspace RTE:NIV */ /* Transmit Interrupt is enabled */
        gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.RIE = 1U; /*  Receive Interrupt is enabled */
        gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.NIE = 1U; /* Normal Interrupt Summary is enabled */
    }
    else
    {
        gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.TIE = 0U; /* polyspace RTE:NIV */ /* Transmit Interrupt is enabled */
        gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.RIE = 0U; /*  Receive Interrupt is enabled */
        gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.NIE = 0U; /* Normal Interrupt Summary is enabled */
    }
    gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.RBUE = 1U; /* : Receive Buffer Unavailable is enabled */
    gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.TBUE = 1U; /* : Transmit Buffer Unavailable is enabled */
    gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.FBEE = 1U; /* : Fatal Bus Error is enabled */
    gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.AIE = 1U; /* Abnormal Interrupt Summary is enabled */
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.R |= ((uint32)1U << 13U); /* polyspace RTE:NIV */ /* Receive Buffer size High */
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.B.RXPBL = 8U; /* Receive Programmable Burst Length */
    gmac_reg->DMA_CH[0].DMA_CH_TXDESC_LIST_ADDRESS.R = (uint32)(gmac_cfg->buf_cfg.tx_desc); /* polyspace RTE:NIP */
    gmac_reg->DMA_CH[0].DMA_CH_RXDESC_LIST_ADDRESS.R = (uint32)(gmac_cfg->buf_cfg.rx_desc); /* polyspace RTE:NIP */
    gmac_reg->DMA_CH[0].DMA_CH_TXDESC_RING_LENGTH.R = (uint32)(gmac_cfg->buf_cfg.tx_ring_cnt - 1U); /* PRQA S 4391 */ /* polyspace RTE:NIV */
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL2.R = (uint32)(gmac_cfg->buf_cfg.rx_ring_cnt - 1U); /* PRQA S 4391 */ /* polyspace RTE:NIV */
    gmac_reg->DMA_CH[0].DMA_CH_TXDESC_TAIL_POINTER.R =
        (uint32)(gmac_cfg->buf_cfg.tx_desc + gmac_cfg->buf_cfg.tx_ring_cnt); /* only one tx buffer*/
    gmac_reg->DMA_CH[0].DMA_CH_RXDESC_TAIL_POINTER.R =
        (uint32)(gmac_cfg->buf_cfg.rx_desc + gmac_cfg->buf_cfg.rx_ring_cnt); /* point offset */
    gmac_reg->DMA_MODE.B.TAA = 2U; /* Weighted Round - Robin (WRR) */
    gmac_reg->DMA_MODE.B.INTM = 2U; /* Enable FEC_SBD_PERCH_TX_0_IRQn & FEC_SBD_PERCH_RX_0_IRQn */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Phy_Cfg \
( \
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
)
{
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) mac = &gmac_cfg->phy_cfg.mac_addr[0];

    if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_RGMII_MODE)/* polyspace RTE:NIV */
    {
        gmac_reg->MAC_EXT_CONFIGURATION.R = ((0UL<<31) | (1UL<<15) | (0UL<<14));//1000M: select gref_txclk
        gmac_reg->MAC_PHYIF_CONTROL_STATUS.R = 0x3U;//TC=1,LUD=1
    }
    else if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_MII_MODE)
    {
        gmac_reg->MAC_EXT_CONFIGURATION.R = ((0UL<<31) | (0UL<<15) | (1UL<<14));//100M:  select txclk
    }
    else if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_RMII_MODE)
    {
        /* do nothing */
    }
    else
    {
        /* do nothing */
    }
    gmac_reg->MAC_CONFIGURATION.B.ACS = 1U; /* CRC stripping for Type packets is disabled */
    gmac_reg->MAC_CONFIGURATION.B.WD = 1U; /* Watchdog is disabled */
    gmac_reg->MAC_CONFIGURATION.B.JD = 1U; /*  Jabber is disabled */
    gmac_reg->MAC_CONFIGURATION.B.JE = 1U; /* Jumbo packet is enabled */
    if (gmac_cfg->phy_cfg.transfer_speed == GMAC_TRANS_SPEED_1000M)/* polyspace RTE:NIV */
    {
        gmac_reg->MAC_CONFIGURATION.B.PS = 0U; /* For 1000 or 2500 Mbps operations */
        gmac_reg->MAC_CONFIGURATION.B.FES = 0U; /* For 10 or 1000 Mbps operations */
    }
    else if (gmac_cfg->phy_cfg.transfer_speed == GMAC_TRANS_SPEED_100M)
    {
        gmac_reg->MAC_CONFIGURATION.B.PS = 1U; /* For 10 or 100 Mbps operations */
        gmac_reg->MAC_CONFIGURATION.B.FES = 1U; /* For 100 or 2500 Mbps operations */
    }
    else if (gmac_cfg->phy_cfg.transfer_speed == GMAC_TRANS_SPEED_10M)
    {
        gmac_reg->MAC_CONFIGURATION.B.PS = 1U; /* For 10 or 100 Mbps operations */
        gmac_reg->MAC_CONFIGURATION.B.FES = 0U; /* For 10 or 1000 Mbps operations */
    }
    else
    {
        /* do nothing */
    }
    if (gmac_cfg->phy_cfg.transfer_duplex == GMAC_TRANS_FULL_DUPLEX) /* polyspace RTE:NIV */
    {
        gmac_reg->MAC_CONFIGURATION.B.DM = 1U; /* Full - duplex mode , default 0 means half mode */
    }
    gmac_reg->MAC_CONFIGURATION.B.TE = 0U; /* Transmitter Enable */
    gmac_reg->MAC_CONFIGURATION.B.RE = 0U; /* Receiver Enable */
    if (gmac_cfg->func_cfg.inner_loop_back_en == TRUE)/* PRQA S 1881 */ /* polyspace RTE:NIV */
    {
        gmac_reg->MAC_CONFIGURATION.B.LM = 1U; /* Loopback is enabled */
    }
    gmac_reg->MAC_ADDRESS0_HIGH.B.ADDRHI = ((uint32)mac[5U] << 8U) | (uint32)mac[4U]; /* polyspace RTE:NIV */
    gmac_reg->MAC_ADDRESS0_LOW.B.ADDRLO = ((uint32)mac[3U] << 24U) | ((uint32)mac[2U] << 16U) | ((uint32)mac[1U] << 8U) | (uint32)mac[0U];/* polyspace RTE:NIV */
    gmac_reg->MAC_PACKET_FILTER.R = 0x80000000U; // receive all
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(GmacReceiveDesc *, ETH_CODE) Gmac_LLD_Search_All_Rx_Desc \
( \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg, \
    P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) rdes_idx \
)
{
    VAR(uint32, AUTOMATIC) idx;

    for (idx = 0U; idx < gmac_cfg->buf_cfg.rx_ring_cnt; idx++) /* polyspace RTE:NIV,IDP */
    {
        if (gmac_cfg->buf_cfg.rx_desc[idx].RDES3.B.OWN == 1U) /* polyspace RTE:NIV,NIP,IDP */
        {
            continue; /* DMA is in use */
        }
        *rdes_idx = idx;
        return &gmac_cfg->buf_cfg.rx_desc[idx];
    }
    return NULL_PTR;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Tx_Intr_Handler_GMAC_ID_0(void)
{
    VAR(GmacId, AUTOMATIC) gmac_id = GMAC_ID_0;
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);

    if ((gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.TI == 1U) && (gmac_cfg->EnableTxInterrupt == TRUE)) /* polyspace RTE:NIV,IDP */
    {
        gmac_reg->DMA_CH[0].DMA_CH_STATUS.R = 0x00000001U; /* write clear */
        Gmac_LLD_Report_Transmission(gmac_id, 0U);

    }
    gmac_reg->DMA_CH[0].DMA_CH_STATUS.R = 0xFFFFFFFEU; /* polyspace RTE:NIV */ /* write clear */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Rx_Intr_Handler_GMAC_ID_0(void)
{
    VAR(GmacId, AUTOMATIC) gmac_id = GMAC_ID_0;
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);

    if((gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.RI == 1U) && (gmac_cfg->EnableRxInterrupt == TRUE))/* polyspace RTE:NIV,IDP */
    {
        gmac_reg->DMA_CH[0].DMA_CH_STATUS.R = 0x00000040U; /* write clear */
        (void)Gmac_LLD_Report_Reception(gmac_id, 0U, (boolean)TRUE);
    }
    gmac_reg->DMA_CH[0].DMA_CH_STATUS.R = 0xFFFFFFBFU; /* polyspace RTE:NIV */ /* write clear */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(status_t, ETH_CODE) Gmac_LLD_Config_Check \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
)
{
    if (gmac_id >= GMAC_ID_BUTT)
    {
        return STATUS_GMAC_INVALID_GMAC_ID;
    }
    if (gmac_cfg->phy_cfg.transfer_mode >= GMAC_TRANS_MODE_BUTT) /* polyspace RTE:NIV,IDP */
    {
        return STATUS_GMAC_INVALID_MILL_MODE;
    }
    if (gmac_cfg->buf_cfg.max_frame_len == 0U) /* polyspace RTE:NIV */
    {
        return STATUS_GMAC_INVALID_BUF_SIZE;
    }
    if ((gmac_cfg->buf_cfg.tx_desc == NULL_PTR) /* polyspace RTE:NIP */
            || (((uint32)gmac_cfg->buf_cfg.tx_desc % GMAC_BUF_DESC_ALIGN) != 0U))
    {
        return STATUS_GMAC_INVALID_TX_DESC;
    }
    if ((gmac_cfg->buf_cfg.rx_desc == NULL_PTR) /* polyspace RTE:NIP */
            || (((uint32)gmac_cfg->buf_cfg.rx_desc % GMAC_BUF_DESC_ALIGN) != 0U))
    {
        return STATUS_GMAC_INVALID_RX_DESC;
    }
    if (gmac_cfg->buf_cfg.rx_ring_cnt == 0U) /* polyspace RTE:NIV */
    {
        return STATUS_GMAC_INVALID_DESC_CNT;
    }
    if (gmac_cfg->buf_cfg.tx_buf_size > gmac_cfg->buf_cfg.max_frame_len) /* polyspace RTE:NIV */
    {
        return STATUS_GMAC_INVALID_TX_BUFFER;
    }
    if (gmac_cfg->buf_cfg.rx_buf_size > (gmac_cfg->buf_cfg.max_frame_len * gmac_cfg->buf_cfg.rx_ring_cnt)) /* polyspace RTE:NIV,OVFL */
    {
        return STATUS_GMAC_INVALID_RX_BUFFER;
    }
    return STATUS_SUCCESS;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Gmac_LLD_Init \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
)
{
    VAR(status_t, AUTOMATIC) ret;
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg;
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    VAR(uint16, AUTOMATIC) mcast_item_loop = 0U;
    VAR(uint8, AUTOMATIC) ctrl_loop = 0U;
    VAR(Gmac_LLD_McastPoolItemType, AUTOMATIC) MulticastPoolInitValue = {FALSE, {0U, 0U, 0U, 0U, 0U, 0U}};
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
    ret  = Gmac_LLD_Config_Check(gmac_id, gmac_cfg);
    if (ret != STATUS_SUCCESS)
    {
        return ret;
    }

    if ((PMU_LDO & 0xC0) != 0xC0)
    {
        PMU_LDO |= 0xC0;   // FlexIO 3.3V Mode
    }
    if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_RGMII_MODE)/* polyspace RTE:NIV */
    {
        /* phy_sel: RGMII */
        SSCM.CHIP_CR.R &= (uint32)(~ SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK);
        SSCM.CHIP_CR.R |= SSCM_CHIP_CR_GMAC0_PHY_SEL(1u);
    }
    else if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_MII_MODE)
    {
        /* phy_sel: MII */
        SSCM.CHIP_CR.R &= (uint32)(~ SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK);
    }
    if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_RMII_MODE)
    {
        /* phy_sel: RMII */
        SSCM.CHIP_CR.R &= (uint32)(~ SSCM_CHIP_CR_GMAC0_PHY_SEL_MASK);
        SSCM.CHIP_CR.R |= SSCM_CHIP_CR_GMAC0_PHY_SEL(4u);
    }
    gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    Gmac_LLD_Record_Cfg(gmac_id, gmac_cfg);

    ret = Gmac_LLD_Reset(gmac_id);
    if (ret != STATUS_SUCCESS)
    {
        return ret;
    }

    Gmac_LLD_Tx_Buf_Cfg(gmac_id);

    Gmac_LLD_Rx_Buf_Cfg(gmac_id);

    Gmac_LLD_Phy_Cfg(gmac_reg, gmac_cfg);

    Gmac_LLD_Dma_Cfg(gmac_reg, gmac_cfg);

    Gmac_LLD_Enable(gmac_reg);
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    for (ctrl_loop = 0U; ctrl_loop < (uint8)ETH_MAXCTRLS_SUPPORTED; ctrl_loop++)
    {
        for (mcast_item_loop = 0U; mcast_item_loop < (uint16)ETH_MULTICAST_POOL_SIZE; mcast_item_loop++)
        {
            s_Gmac_LLD_MulticastPool[ctrl_loop][mcast_item_loop] = MulticastPoolInitValue;
        }
    }
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
    return STATUS_SUCCESS;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Gmac_LLD_DeInit(VAR(GmacId, AUTOMATIC) gmac_id) /* PRQA S 1503 */
{
    return Gmac_LLD_Reset(gmac_id);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Write_16_Tx_Buf_Mem \
( \
    CONST(uint32, ETH_CONST) base_addr, \
    CONST(uint32, ETH_CONST) offset, \
    CONST(uint16, ETH_CONST) data \
)
{
    *((volatile uint16 *)(base_addr + (offset))) = data; /* polyspace RTE:IDP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Give_Back_Tx_Buffer \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    VAR(uint8, AUTOMATIC) buf_idx \
)
{

#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    VAR(uint8, AUTOMATIC) buf_num; /* Number of buffers in current frame */
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */

    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    P2VAR(GmacTransmitDesc, AUTOMATIC, ETH_APPL_DATA) transmit_desc = &gmac_cfg->buf_cfg.tx_desc[buf_idx]; /* polyspace RTE:NIP,IDP */

    /* Is there a BD linked to this buffer? */
    if ((GMAC_TXB_FIRST_U8 | GMAC_TXB_LINK_U8 | GMAC_TXB_LOCK_U8) == s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx])
    {   /* Yes, unlink the BD */
        transmit_desc->TDES3.B.OWN = 0U; /* polyspace RTE:IDP */
        /* NOTE: on buffer side the link is removed below */
    }
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    /* Unlock all buffers of frame */
    buf_num = s_Gmac_LLD_au8TxBufGroup[gmac_id][fifo_idx][buf_idx];
    while (0U != buf_num)
    {
        s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx] = 0U;
        buf_num--;
        buf_idx++; /* The memory must be continuous, wrap may not occur */
    }
#else /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    /* Unlock the buffer, there is only one */
    s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx] = 0U;
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(uint32, ETH_CODE) Gmac_LLD_Compute_Tx_Buf_Addr \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONST(Eth_BufIdxType, ETH_CONST) buf_idx \
)
{
    VAR(uint16, AUTOMATIC) buf_len = 0U;
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    buf_len = (uint16)gmac_cfg->egress_cfg[fifo_idx].EthCtrlConfigEgressFifoBufLenByte; /* polyspace RTE:NIV,NIP,IDP */

    /*Calculate start address of data buffer when length of buffer in configuration isn't multiple of 64*/
    if (0U != (uint16)(buf_len % 16U))
    {
        buf_len = (uint16)(buf_len + ((uint16)16U - (buf_len % 16U)));
    }
    
    return (s_Gmac_LLD_u32TxBufStartAddr[gmac_id][fifo_idx] + ((uint32)buf_len * (uint32)buf_idx));
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(uint32, ETH_CODE) Gmac_LLD_Compute_Rx_Buf_Addr \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONST(uint8, ETH_CONST) buf_idx \
)
{
    VAR(uint16, AUTOMATIC) buf_len = 0U;
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    buf_len = (uint16)gmac_cfg->ingress_cfg[fifo_idx].EthCtrlConfigIngressFifoBufLenByte; /* polyspace RTE:NIV,NIP,IDP */
    /*Calculate start address of data buffer when length of buffer in configuration isn't multiple of 16*/
    if (0U != (uint16)(buf_len % 16U))
    {
        buf_len += (uint16)((uint16)16U - (buf_len % 16U));
    }

    return (uint32)(s_Gmac_LLD_u32RxBufStartAddr[gmac_id][fifo_idx] + ((uint32)buf_len * (uint32)buf_idx));
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Borrow_Tx_Buffer \
( \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONSTP2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_CONST) buf_idx, \
    P2P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) buf_ptr, \
    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_CONST) buf_len
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
    , VAR(uint16, AUTOMATIC) management_len
#endif
)
{
    VAR(uint8, AUTOMATIC) buf_num_need = 0U; /* Needed number of buffers */
    VAR(uint8, AUTOMATIC) buf_num_found = 0U; /* Number of free buffers found */
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    VAR(uint8, AUTOMATIC) idx_loop; /* General purpose index to be used in loops */
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    VAR(uint32, AUTOMATIC) TDES_status = 0U;
    VAR(uint8, AUTOMATIC) idx = 0U;  /* General purpose index to be used in loops */
    VAR(uint16, AUTOMATIC) search_cnt = 0U; /* Countdown to limit search */

    VAR(boolean, AUTOMATIC) data_area_found = ((boolean)FALSE);
    /* Used to track if some free buffer was found */
    /* Local copies of configuration (optimization): */
    VAR(uint16, AUTOMATIC) total_buf_num = 0U;
    VAR(GmacId, AUTOMATIC) gmac_id = gmac_cfg->gmac_id; /* polyspace RTE:NIV */
    VAR(uint16, AUTOMATIC) buf_size = 0U;

    P2CONST(GmacTransmitDesc, AUTOMATIC, ETH_APPL_CONST) transmit_desc = &gmac_cfg->buf_cfg.tx_desc[*buf_idx]; /* polyspace RTE:NIP */
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pType = NULL_PTR;
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
    total_buf_num = gmac_cfg->buf_cfg.tx_ring_cnt; /* polyspace RTE:NIV */
    if (total_buf_num > TX_BUFFER_COUNT)
    {
        return (boolean)FALSE;
    }
    buf_size = (uint16)gmac_cfg->egress_cfg[fifo_idx].EthCtrlConfigEgressFifoBufLenByte; /* polyspace RTE:IDP */
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    /* Compute needed number of buffers. Add 14B for eth header, round up */
    buf_num_need = (uint8)((*buf_len + (buf_size + (14U - 1U))) / buf_size);

    search_cnt = ((uint16)total_buf_num + (uint16)buf_num_need) - 1U;
#else /* ETH_USE_MULTIBUFFER_TX_FRAMES */
    /* One buffer is always needed */
    buf_num_need = (uint8)1U;
    search_cnt = total_buf_num;
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */

    /* Start at s_Gmac_LLD_u8SearchTxBufFrom (to minimize fragmentation) */
    idx = s_Gmac_LLD_u8SearchTxBufFrom[gmac_id][fifo_idx]; /* polyspace RTE:OBAI */
    buf_num_found = 0U;
    while (((boolean)FALSE == data_area_found) && (search_cnt != 0U)) /* PRQA S 2877 */
    {
        /* Check buffer status, whether the buffer may be unlocked now */
        if ((GMAC_TXB_LOCK_U8 | GMAC_TXB_LINK_U8 | GMAC_TXB_FIRST_U8) == s_Eth_au8TxBufFlags[gmac_id][fifo_idx][idx])
        {   /* According to buffer flags, it may be unlocked now */
            /* Now check BD status, whether Ready bit is cleared */
            TDES_status = 0x80000000U & transmit_desc->TDES3.R; /* polyspace RTE:NIV,IDP */
            if (0U == TDES_status)
            {   /* Yes, the frame is in UNLOCKEDAT state and both BD and
                   buffers shall be unlocked and unlinked now */
                Gmac_LLD_Give_Back_Tx_Buffer(gmac_id, fifo_idx, idx);
            }
        }
        /* Check buffer status. Is the buffer free ? */
        if (0U == s_Eth_au8TxBufFlags[gmac_id][fifo_idx][idx])
        {   /* Yes, it is free */
            buf_num_found++;
            /* enough buf? */
            if (buf_num_found == buf_num_need)
            {   /* All needed buffers found */
                data_area_found = (boolean)TRUE;
                idx++;
                /* Next time continue search from here */
                if (idx >= total_buf_num)
                {
                    s_Gmac_LLD_u8SearchTxBufFrom[gmac_id][fifo_idx] = 0U;
                }
                else
                {
                    s_Gmac_LLD_u8SearchTxBufFrom[gmac_id][fifo_idx] = idx;
                }
                /* Compute index of the first buffer, idx is behind allocated
                   buffers now. Continuous block => no wrap => no under-loop */
                *buf_idx = ((uint32)idx - buf_num_found); /* PRQA S 2897, 2912, 4391 */
                /* Return real length of buffers minus eth header length */
#if (STD_ON == ETH_BUFFER_LENGTH_FROM_CONFIG) /*PRQA S 3332*/
                *buf_len = (uint16)((buf_size * buf_num_need) - (uint8)14U); /* PRQA S 2985 */
#else
                (void)buf_len;
                (void)buf_size;
#endif /* ETH_BUFFER_LENGTH_FROM_CONFIG */
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)

                pType = (uint8 *)(12U + (Gmac_LLD_Compute_Tx_Buf_Addr(gmac_id, fifo_idx, (uint8)(*buf_idx))));
                *buf_len = *buf_len - management_len;
                gmac_cfg->Eth_EthSwtDriverFunctionList.TxPrepareFrameFunction(gmac_id, (Eth_BufIdxType)(*buf_idx), &pType, buf_len);
                *buf_ptr =  pType + 2U;
#else
                /* Compute buffer pointer, skip 14 bytes for ethernet header */
                *buf_ptr = (Eth_DataType *)(14U + (Gmac_LLD_Compute_Tx_Buf_Addr(gmac_id, fifo_idx, (uint8)(*buf_idx))));
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
                /* Lock all allocated buffers, do in critical section to prevent interference */
                s_Eth_au8TxBufFlags[gmac_id][fifo_idx][*buf_idx] = (uint8)(GMAC_TXB_LOCK_U8 | GMAC_TXB_FIRST_U8); /* The 1st */

#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
                /* Write number of buffers belonging to this frame */
                s_Gmac_LLD_au8TxBufGroup[gmac_id][fifo_idx][*buf_idx] = buf_num_need;

                for (idx_loop = (uint8)((uint8)(*buf_idx) + (uint8)1U); idx_loop < (uint8)((uint8)(*buf_idx) + buf_num_need); idx_loop++) /* Skip the first */
                {
                    s_Eth_au8TxBufFlags[gmac_id][fifo_idx][idx_loop] = GMAC_TXB_LOCK_U8;
                }
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
            }
        }
        else
        {
            /* No, buffer is locked => continuity broken */
            buf_num_found = 0U;  /* PRQA S 2982 */
        }
        search_cnt--; /* PRQA S 2984 */
        idx++;
        if (idx >= total_buf_num)
        {   /* Wrapped */
            idx = 0U; /* PRQA S 2983 */
            buf_num_found = 0U; /* Wrap => continuity broken *//* PRQA S 2983 */
        }
    }

    return data_area_found;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Tx_Buf_Locked_BT \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONST(Eth_BufIdxType, ETH_CONST) buf_idx \
) /* PRQA S 1503 */
{
    VAR(boolean, AUTOMATIC) ret; /* Result holder */

    if ((GMAC_TXB_LOCK_U8|GMAC_TXB_FIRST_U8)== s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx])
    {   /* OK, it is locked and first buffer of frame */
        ret = (boolean)TRUE;
    }
    else
    {
        ret = (boolean)FALSE;
    }
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

/**
* @brief         Triggers the transmission of the given frame
* @param[in]     gmac_id Index of controller which will be triggered the transmission
* @param[in]     buf_idx Buffer index provided by Gmac_LLD_Borrow_Tx_Buffer.
* @param[in]     frame_type Type or length field value in the 802.3 frame header
* @param[in]     pkt_len Payload length
* @param[in]     confirm Selects whether the frame transmission shall
*                be confirmed or not
* @param[in]     dest_mac Frame destination address
* @details       At first Ethernet header is assembled.
*                Then the buffers are linked with active buffer descriptor
*                (s_Eth_u8ActiveTxBD) and the buffer descriptor is written
*                including the Ready bit. The controller is notified about the
*                new buffer by a write into the TDAR register.
* @note          Note that as buffer was successfully borrowed, at least one BD
*                will also be available, because number of BDs >= number of
*                frames in buffers, so even if all buffers (but this one) are
*                linked to BDs, at least one BD is free and may be used for
*                current frame. 
*                Buffer descriptors are used as ring buffer, where
*                s_Eth_u8ActiveTxBD is index of first available BD. It is also
*                the only one BD that may be used, because it is the BD where
*                GMAC controller will look for next frame.
* @implements    Gmac_LLD_Send_Msg_Activity
*/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Send_Msg \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    VAR(uint8, AUTOMATIC) fifo_idx, \
    VAR(Eth_BufIdxType, AUTOMATIC) buf_idx, \
    VAR(Eth_FrameType, AUTOMATIC) frame_type, \
    VAR(uint32, AUTOMATIC) pkt_len, \
    VAR(boolean, AUTOMATIC) confirm, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) dest_mac
#if STD_ON == ETH_BRIDGE_SUPPORT
    , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) src_addr
#endif /* ETH_BRIDGE_SUPPORT  */
) /* PRQA S 1503 */
{
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    P2VAR(GmacTransmitDesc, AUTOMATIC, ETH_APPL_DATA) transmit_desc = &gmac_cfg->buf_cfg.tx_desc[buf_idx];/* polyspace RTE:NIP,IDP */

    VAR(uint32, AUTOMATIC) buf_addr = 0U; /* Address of (first) buffer */
    VAR(uint32, AUTOMATIC) manipulation_var; /* Used for bit manipulations */
    VAR(uint16, AUTOMATIC) PhysAddrPtr; /* Used for bit manipulations */
    /* Local copies of configuration (optimization): */
    VAR(uint8, AUTOMATIC) total_buf_num;
    VAR(uint32, AUTOMATIC) eth_cycle_flg = 0U;

#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) data_ptr = NULL_PTR;
    VAR(uint16, AUTOMATIC) buf_len;

    buf_len = (uint16)gmac_cfg->buf_cfg.tx_buf_size;
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
    total_buf_num = 1U;
    buf_addr = transmit_desc->TDES0.B.BUF1AP; /* polyspace RTE:NIV,IDP */

    manipulation_var = ((uint32)dest_mac[4U] << 8U) | (uint32)dest_mac[5U];
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 4U, (uint16) manipulation_var); /* Put first 2 bytes */
    manipulation_var = ((uint32)dest_mac[2U] << 8U) | (uint32)dest_mac[3U];
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 2U, (uint16) manipulation_var); /* Put second 2 bytes */
    manipulation_var = ((uint32)dest_mac[0U] << 8U) | (uint32)dest_mac[1U];
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 0U, (uint16) manipulation_var); /* Put third 2 bytes */

#if STD_ON == ETH_BRIDGE_SUPPORT
    if (NULL_PTR == src_addr)
    {
        /* Read source MAC address from registers and put it to header */
        /* Read first 4 bytes */
        manipulation_var = Gmac_LLD_Get_Phys_Address_Low(gmac_id);
        PhysAddrPtr = (uint16)(manipulation_var << 8 | manipulation_var >> 8);
        Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 6U, (uint16) PhysAddrPtr); /* Put first 2 bytes */

        PhysAddrPtr = (uint16)(manipulation_var >> 16 << 8 | manipulation_var >> 24);
        Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 8U, (uint16) PhysAddrPtr); /* Put second 2 bytes */

        manipulation_var = Gmac_LLD_Get_Phys_Address_High(gmac_id);
        PhysAddrPtr = (uint16)(manipulation_var << 8 | manipulation_var >> 8);
        Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 10U, (uint16) PhysAddrPtr); /* Put third 2 bytes */
    }
    else
    {
        manipulation_var = ((uint32)src_addr[4U] << 8U) | (uint32)src_addr[5U];
        Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 10U, (uint16) manipulation_var); /* Put first 2 bytes */
        manipulation_var = ((uint32)src_addr[2U] << 8U) | (uint32)src_addr[3U];
        Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 8U, (uint16) manipulation_var); /* Put second 2 bytes */
        manipulation_var = ((uint32)src_addr[0U] << 8U) | (uint32)src_addr[1U];
        Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 6U, (uint16) manipulation_var); /* Put third 2 bytes */
    }
#else
    /* Read source MAC address from registers and put it to header */
    /* Read first 4 bytes */
    manipulation_var = Gmac_LLD_Get_Phys_Address_Low(gmac_id);
    PhysAddrPtr = (uint16)((manipulation_var << 8) | (manipulation_var >> 8));
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 6U, (uint16) PhysAddrPtr); /* Put first 2 bytes */

    PhysAddrPtr = (uint16)(((manipulation_var >> 16) << 8) | (manipulation_var >> 24));
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 8U, (uint16) PhysAddrPtr); /* Put second 2 bytes */

    manipulation_var = Gmac_LLD_Get_Phys_Address_High(gmac_id);
    PhysAddrPtr = (uint16)((manipulation_var << 8) | (manipulation_var >> 8));
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 10U, (uint16) PhysAddrPtr); /* Put third 2 bytes */

#endif /* ETH_BRIDGE_SUPPORT */

    /* Append the type field */
    Gmac_LLD_Write_16_Tx_Buf_Mem(buf_addr, 12U, (uint16)frame_type);
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
    data_ptr = (uint8 *)(12U + s_Gmac_LLD_u32TxBufStartAddr[gmac_id][fifo_idx] + (uint32)((uint32)buf_len * (uint32)buf_idx));
    if (E_OK == gmac_cfg->Eth_EthSwtDriverFunctionList.TxProcessFrameFunction(gmac_id, buf_idx, (uint8**)&data_ptr, (uint16*)&pkt_len))
    {
        if (E_OK == gmac_cfg->Eth_EthSwtDriverFunctionList.TxFinishedIndicationFunction(gmac_id, buf_idx))
        {
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
            /* Now write the buffer descriptor */
            /* Write pointer */
            /* Write status bits and frame length. Note that GMAC_TXBD_R_U32 bit must be written
               last. It will be written last, together with other bits and length.
               14 bytes of ethernet header is added to the length.  */
            transmit_desc->TDES2.B.HL_B1L = pkt_len + 14U;

            s_Eth_u8ActiveTxBD[gmac_id][fifo_idx] = (uint8)((uint32)s_Eth_u8ActiveTxBD[gmac_id][fifo_idx] + 1U);
            if ( s_Eth_u8ActiveTxBD[gmac_id][fifo_idx] >= total_buf_num )
            {
                s_Eth_u8ActiveTxBD[gmac_id][fifo_idx] = 0U;
            }
            /* Write frame/buffer status bits */
            if ((boolean)TRUE == confirm)
            {   /* TxConfirmation is requested, also set TxConfirmation bit */
                s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx] = (uint8)(GMAC_TXB_LOCK_U8 | GMAC_TXB_FIRST_U8 | GMAC_TXB_LINK_U8 | GMAC_TXB_CONF_U8);
                /* Update number of pending confirmations */
                SchM_Enter_Eth_EXCLUSIVE_AREA_00();
                s_Eth_u8LockedTxBufCount[gmac_id][fifo_idx]++;
                SchM_Exit_Eth_EXCLUSIVE_AREA_00();
            }
            else
            {
                s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx] = (uint8)(GMAC_TXB_LOCK_U8 | GMAC_TXB_FIRST_U8 | GMAC_TXB_LINK_U8);
            }
            gmac_reg->DMA_CH[0].DMA_CH_TX_CONTROL.B.ST = 0U; /* polyspace RTE:OBAi,NIV */ /* start transmit */
            gmac_reg->DMA_CH[0].DMA_CH_TXDESC_LIST_ADDRESS.R = (uint32)(transmit_desc);
            gmac_reg->DMA_CH[0].DMA_CH_TX_CONTROL.B.ST = 1U; /* start transmit */
            /* Write the TDAR register to notify the controller about a new buffer,
               written value is ignored, the write access is what matters. */
            transmit_desc->TDES1.R = 0U;
            transmit_desc->TDES2.B.IOC = 1;
            transmit_desc->TDES3.R = 0xB0030000;

            gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.TBU = 1U; /* polyspace RTE:OBAI,NIV */ /* clear transmit completed flag */

            gmac_reg->DMA_CH[0].DMA_CH_TXDESC_TAIL_POINTER.R \
                = (uint32)((&(gmac_cfg->buf_cfg.tx_desc[gmac_cfg->buf_cfg.tx_ring_cnt]))); /* polyspace RTE:NIV,NIP */ /* start transmit */
            
            while(((0x80000000U & transmit_desc->TDES3.R) != 0U) && (eth_cycle_flg < 1000000U))/* polyspace RTE:NIV */
            {
                eth_cycle_flg++;
            }
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
        }
    }
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

/**
* @brief         Reports received frames to the upper layer
* @param[in]     gmac_id Index of the controller to report receptions
* @param[in]     is_irq Selects between the poll driven and interrupt driven
*                mode (algorithm). The value TRUE means interrupt driven mode.
* @details       Function examines type of receive buffers. It begins
*                from the empty buffer found by previous call or from the
*                first one if no call has been done since the controller has
*                been enabled or from the latest known full buffer containing
*                the single-buffer-error-free frame.
* @return        In the poll driven mode signalizes whether a frame has been
*                reported to the EthIf module and whether another frame is
*                available. It shall be ignored in the interrupt driven mode.
* @retval        ETH_RECEIVED Only one frame received
* @retval        ETH_NOT_RECEIVED No frame received
* @retval        ETH_RECEIVED_MORE_DATA_AVAILABLE More frames received
*                frame was discarded.
*/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_RxStatusType, ETH_CODE) Gmac_LLD_Report_Reception \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    VAR(uint8, AUTOMATIC) fifo_idx, \
    VAR(boolean, AUTOMATIC) is_irq \
)
{
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    VAR(uint8, AUTOMATIC) buf_ctr = 0U; /* Buffer referencing variable */
    VAR(uint16, AUTOMATIC) pkt_len = 0U;
    VAR(Eth_FrameType, AUTOMATIC) frame_type = 0U;
    VAR(boolean, AUTOMATIC) isBroadcast;
    VAR(uint8, AUTOMATIC) recv_des_cnt = 0U; /* recv descriptor count */
    VAR(Eth_RxStatusType, AUTOMATIC) ret; /* Single return implementation needs to store the return value */
    /* The ret could be used as a steering variable instead of the
       FirstFramFound but the readability would be decreased and the compiler
       will optimize it anyway */

    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    P2VAR(GmacReceiveDesc, AUTOMATIC, ETH_APPL_DATA) receive_desc;
    VAR(uint32, AUTOMATIC) rdes_idx = 0U;

    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) data_ptr = NULL_PTR;
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    VAR(uint8, AUTOMATIC) dest_addr[6U] = {0U};
    VAR(uint8, AUTOMATIC) cnt = 0U;
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
    VAR(boolean, AUTOMATIC) is_mgtm_frame_only;
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) data_mgt_ptr = NULL_PTR;
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
    buf_ctr = s_Eth_u8ActiveRxBuf[gmac_id][fifo_idx]; /* polyspace RTE:OBAI */
    (void)is_irq;
    /* No valid frames have been found yet */
    ret = ETH_NOT_RECEIVED;
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.B.SR = 0U; /* polyspace RTE:OBAI,NIV,IDP */ /* start receive */
    while ((boolean)TRUE) /* PRQA S 0771 */
    {
        receive_desc = Gmac_LLD_Search_All_Rx_Desc(gmac_cfg, &rdes_idx);
        if (receive_desc == NULL_PTR)
        {
            break;
        }
        else
        {
            recv_des_cnt++;
        }
        if (receive_desc->RDES3.B.PL >= (uint32)gmac_cfg->buf_cfg.max_frame_len) /* polyspace RTE:NIV */
        {
            receive_desc->RDES3.R = (1UL<<31)|(1UL<<30)|(1UL<<24);
            continue;
        }

        data_ptr = (uint8 *)receive_desc->RDES0.B.BUF1AP;/* polyspace RTE:NIV */
        if (data_ptr == NULL_PTR)
        {
            receive_desc->RDES3.B.OWN = 1U; /* give back to DMA */
            break;
        }
        pkt_len = receive_desc->RDES3.B.PL;
#if STD_ON == ETH_USE_MULTIBUFFER_RX_FRAMES
        if (pkt_len > (uint16)1514U)
        {   /* The length must be incorrect, it is greater than maximal allowed length */
            /* Return maximal length instead */
            pkt_len = (uint16)1514U;
        }
#else
        if (pkt_len > gmac_cfg->ingress_cfg[fifo_idx].EthCtrlConfigIngressFifoBufLenByte) /* polyspace RTE:NIV,NIP,IDP */
        {   /* The length must be incorrect, it is greater than maximal allowed length */
            /* Return maximal length instead */
            pkt_len = (uint16)gmac_cfg->ingress_cfg[fifo_idx].EthCtrlConfigIngressFifoBufLenByte;
        }
#endif /* ETH_USE_MULTIBUFFER_RX_FRAMES */
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER

        for(cnt = 0U; cnt < 6U; cnt++)
        {
            dest_addr[cnt] = data_ptr[cnt]; /* polyspace RTE:NIV,IDP */
        }
        cnt = 0U;
        if((boolean)TRUE == Gmac_LLD_Is_Phys_Addr_Allowed(gmac_id, (uint8 *)&dest_addr))
        {
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

            frame_type = ((uint16)data_ptr[12U] << 8U); /* polyspace RTE:NIV,IDP */
            frame_type |= (uint16)data_ptr[13U]; /* polyspace RTE:NIV,IDP */

            if (gmac_reg->MAC_PACKET_FILTER.B.DBF == 0U)/* polyspace RTE:NIV */
            {   /* isBroadcast */
                isBroadcast = (boolean)TRUE;
            }
            else
            {   /* Unicast or multicast */
                isBroadcast = (boolean)FALSE;
            }
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
            data_mgt_ptr = &data_ptr[12U];
            (void)gmac_cfg->Eth_EthSwtDriverFunctionList.RxProcessFrameFunction(gmac_id, (uint32_t)buf_ctr, &data_mgt_ptr, &pkt_len, &is_mgtm_frame_only);
            if (((bool)FALSE) == is_mgtm_frame_only)
            {
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
            EthIf_RxIndication((uint8)gmac_id, frame_type, isBroadcast, (data_ptr + 6), (data_ptr + 14), (uint16)(pkt_len - 14U - 4U)); /* PRQA S 2934 */
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
            }
            else
            {
                (void)gmac_cfg->Eth_EthSwtDriverFunctionList.RxFinishedIndicationFunction(gmac_id, (uint32)buf_ctr);
            }
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
        }
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
        buf_ctr = buf_ctr + 1U;
        if (buf_ctr >= gmac_cfg->buf_cfg.rx_ring_cnt) /* polyspace RTE:NIV */
        {
            buf_ctr = 0U;
        }
        s_Eth_u8ActiveRxBuf[gmac_id][fifo_idx] = buf_ctr;
        /* Descriptors need to be reinitialized */
        receive_desc->RDES0.R =
            (uint32)(gmac_cfg->buf_cfg.rx_buf_addr + (rdes_idx * gmac_cfg->buf_cfg.max_frame_len));/* polyspace RTE:NIV,NIP */
        receive_desc->RDES1.R = 0U;
        receive_desc->RDES2.R = 0U;
        receive_desc->RDES3.R = ((1UL<<31) | (1UL<<30) | (1UL<<24));
    }
    gmac_reg->DMA_CH[0].DMA_CH_RXDESC_TAIL_POINTER.R = /* polyspace RTE:OBAI,NIV */
                        (uint32)&(gmac_cfg->buf_cfg.rx_desc[gmac_cfg->buf_cfg.rx_ring_cnt]); /* polyspace RTE:NIV,NIP */
    if(recv_des_cnt == 1U)
    {
        ret = ETH_RECEIVED;
    }
    else if(recv_des_cnt > 1U)
    {
        ret = ETH_RECEIVED_MORE_DATA_AVAILABLE;
    }
    else
    {
        /* do nothing */
    }
    /* Return information about availability of more buffers */
    gmac_reg->DMA_CH[0].DMA_CH_RX_CONTROL.B.SR = 1U; /* start receive */
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint32, ETH_CODE) Gmac_LLD_Get_Phys_Address_Low(VAR(GmacId, AUTOMATIC) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    /* Return lower 32 bits of MAC address */
    return (uint32)gmac_reg->MAC_ADDRESS0_LOW.R;/* polyspace RTE:NIV */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint16, ETH_CODE) Gmac_LLD_Get_Phys_Address_High(VAR(GmacId, AUTOMATIC) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(uint32, AUTOMATIC) addr_high;
    
    /* Get upper 16 bits of MAC address and move them to appropriate position*/ 
    addr_high = gmac_reg->MAC_ADDRESS0_HIGH.B.ADDRHI;/* polyspace RTE:NIV */
    addr_high &= 0x0000ffffu;
    /* Return the obtained value */
    return (uint16)addr_high;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Set_Phys_Addr \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) phy_addr \
)
{
    VAR(boolean, AUTOMATIC) ret = FALSE;
    VAR(uint32, AUTOMATIC) addr_value = 0U;
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    /* Change mac address only when the conroller is down */
    if(ETH_MODE_DOWN == Gmac_LLD_Check_Ctrl_Is_Active(gmac_id))
    {
        /* Prepare lower bytes of MAC */
        addr_value = (uint32)phy_addr[3U];
        addr_value = ((addr_value << 8U) | (uint32)phy_addr[2U]);
        addr_value = ((addr_value << 8U) | (uint32)phy_addr[1U]);
        addr_value = ((addr_value << 8U) | (uint32)phy_addr[0U]);
        gmac_reg->MAC_ADDRESS0_LOW.R = addr_value;

        /* Prepare higher bytes of MAC */
        
        addr_value = (uint32)phy_addr[5U];
        addr_value = ((uint32)(addr_value << 8U) | (uint32)phy_addr[4U]);
        gmac_reg->MAC_ADDRESS0_HIGH.B.ADDRHI = addr_value;

        /* Set return status */
        ret = TRUE;
    }
    
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Counter_Values \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) cnt_type \
)
{
    VAR(uint32, AUTOMATIC) reg_temp;
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    /* error send and recv */
    reg_temp = (uint32)(gmac_reg->TX_PACKET_COUNT_GOOD_BAD.R);/* polyspace RTE:NIV */
    reg_temp = (uint32)(reg_temp - gmac_reg->TX_PACKET_COUNT_GOOD.R);/* polyspace RTE:NIV */
    cnt_type->DropPktBufOverrun = (uint32)(reg_temp + gmac_reg->RX_RECEIVE_ERROR_PACKETS.R);/* polyspace RTE:NIV */

    /* just Rx, Hardware doesn't support register to read this Tx value */
    cnt_type->DropPktCrc = (uint32)gmac_reg->RX_CRC_ERROR_PACKETS.R;/* polyspace RTE:NIV */
 
    /* just Rx, Hardware doesn't support register to read this Tx value */
    cnt_type->UndersizePkt = (uint32)gmac_reg->RX_UNDERSIZE_PACKETS_GOOD.R;/* polyspace RTE:NIV */

    reg_temp = (uint32)gmac_reg->RX_UNDERSIZE_PACKETS_GOOD.R;/* polyspace RTE:NIV */

    cnt_type->OversizePkt = (uint32)(reg_temp + gmac_reg->RX_OVERSIZE_PACKETS_GOOD.R);/* polyspace RTE:NIV */

    /* just Rx, Hardware doesn't support register to read this Tx value */
    cnt_type->AlgnmtErr = (uint32)gmac_reg->RX_CRC_ERROR_PACKETS.R;/* polyspace RTE:NIV */

    cnt_type->SnglCollPkt = (uint32)gmac_reg->TX_SINGLE_COLLISION_GOOD_PACKETS.R;/* polyspace RTE:NIV */

    cnt_type->MultCollPkt = (uint32)gmac_reg->TX_MULTIPLE_COLLISION_GOOD_PACKETS.R;/* polyspace RTE:NIV */

    cnt_type->DfrdPkt = (uint32)gmac_reg->TX_DEFERRED_PACKETS.R;/* polyspace RTE:NIV */

    cnt_type->LatCollPkt = (uint32)gmac_reg->TX_LATE_COLLISION_PACKETS.R;/* polyspace RTE:NIV */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Rx_Stats \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) rx_stats \
)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(uint32, AUTOMATIC) reg_temp;

    rx_stats->RxStatsDropEvents = (uint32)gmac_reg->RX_RECEIVE_ERROR_PACKETS.R;/* polyspace RTE:NIV */ /* error frames */

    rx_stats->RxStatsOctets = (uint32)gmac_reg->RX_OCTET_COUNT_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsPkts = (uint32)gmac_reg->RX_PACKETS_COUNT_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsBroadcastPkts = (uint32)gmac_reg->RX_BROADCAST_PACKETS_GOOD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsMulticastPkts = (uint32)gmac_reg->RX_MULTICAST_PACKETS_GOOD.R;/* polyspace RTE:NIV */

    reg_temp = (uint32)(gmac_reg->RX_CRC_ERROR_PACKETS.R);/* polyspace RTE:NIV */

    rx_stats->RxStatsCrcAlignErrors = (uint32)(reg_temp + gmac_reg->RX_ALIGNMENT_ERROR_PACKETS.R);/* polyspace RTE:NIV */

    rx_stats->RxStatsUndersizePkts = (uint32)gmac_reg->RX_UNDERSIZE_PACKETS_GOOD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsOversizePkts = (uint32)gmac_reg->RX_OVERSIZE_PACKETS_GOOD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsFragments = (uint32)gmac_reg->RX_RUNT_ERROR_PACKETS.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsJabbers = (uint32)gmac_reg->RX_JABBER_ERROR_PACKETS.R;/* polyspace RTE:NIV */

    /*Hardware doesn't support register to read this value*/
    rx_stats->RxStatsCollisions = 0xFFFFU;

    rx_stats->RxStatsPkts64Octets = (uint32)gmac_reg->RX_64OCTETS_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsPkts65to127Octets = (uint32)gmac_reg->RX_65TO127OCTETS_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsPkts128to255Octets = (uint32)gmac_reg->RX_128TO255OCTETS_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsPkts256to511Octets = (uint32)gmac_reg->RX_256TO511OCTETS_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsPkts512to1023Octets = (uint32)gmac_reg->RX_512TO1023OCTETS_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */

    rx_stats->RxStatsPkts1024to1518Octets = (uint32)gmac_reg->RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Tx_Stats \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) tx_stats \
)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(uint32, AUTOMATIC) reg_temp;

    tx_stats->TxNumberOfOctets = (uint32)gmac_reg->TX_OCTET_COUNT_GOOD.R;/* polyspace RTE:NIV */

    reg_temp = (uint32)gmac_reg->TX_BROADCAST_PACKETS_GOOD_BAD.R;/* polyspace RTE:NIV */
    tx_stats->TxNUcastPkts = (uint32)(reg_temp + gmac_reg->TX_MULTICAST_PACKETS_GOOD_BAD.R);/* polyspace RTE:NIV */

    reg_temp = (uint32)gmac_reg->TX_PACKET_COUNT_GOOD_BAD.R;/* polyspace RTE:NIV */
    tx_stats->TxUniCastPkts = (uint32)(reg_temp - tx_stats->TxNUcastPkts);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Tx_Err_Cnt_Val \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) tx_error_cnt_val \
)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(uint32, AUTOMATIC) reg_temp;

    /*Hardware doesn't support register to read this value*/
    tx_error_cnt_val->TxDroppedNoErrorPkts = 0xFFFFU;

    reg_temp = (uint32)gmac_reg->TX_PACKET_COUNT_GOOD_BAD.R;/* polyspace RTE:NIV */
    tx_error_cnt_val->TxDroppedErrorPkts = (uint32)(reg_temp - gmac_reg->TX_OCTET_COUNT_GOOD.R);/* polyspace RTE:NIV */

    tx_error_cnt_val->TxDeferredTrans = (uint32)gmac_reg->TX_DEFERRED_PACKETS.R;/* polyspace RTE:NIV */

    tx_error_cnt_val->TxSingleCollision = (uint32)gmac_reg->TX_SINGLE_COLLISION_GOOD_PACKETS.R;/* polyspace RTE:NIV */

    tx_error_cnt_val->TxMultipleCollision = (uint32)gmac_reg->TX_MULTIPLE_COLLISION_GOOD_PACKETS.R;/* polyspace RTE:NIV */

    tx_error_cnt_val->TxLateCollision = (uint32)gmac_reg->TX_LATE_COLLISION_PACKETS.R;/* polyspace RTE:NIV */

    tx_error_cnt_val->TxExcessiveCollison = (uint32)gmac_reg->TX_EXCESSIVE_COLLISION_PACKETS.R;/* polyspace RTE:NIV */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(uint32, ETH_CODE) Gmac_LLD_Get_CRC32_Hash \
( \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) data, \
    VAR(uint32, AUTOMATIC) length \
)
{
    VAR(uint32, AUTOMATIC) CRC32_hash;    /* CRC hash output register */
    VAR(uint32, AUTOMATIC) CRC32_byte_idx; /* Index of data byte */
    VAR(uint8, AUTOMATIC) CRC32_bit_idx;    /* Index of bit inside
                                               CRC32 calculated byte */
    CRC32_hash = GMAC_LLD_CRC32_INITVAL;
    /* Loop over all bytes */
    for (CRC32_byte_idx = 0U; CRC32_byte_idx < length; CRC32_byte_idx++)
    {
        CRC32_hash ^= (uint32)data[CRC32_byte_idx];
        /* Loop over bits */
        for (CRC32_bit_idx = 0U; 8U > CRC32_bit_idx; CRC32_bit_idx++)
        {
            CRC32_hash = (CRC32_hash >> 1) ^ ((~(CRC32_hash & 0x1U) + 0x1U) & GMAC_LLD_CRC32_POLYVAL);
        }
    }
    
    return CRC32_hash;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(boolean, ETH_CODE) Gmac_LLD_Mcast_Pool_Add_Item \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phys_addr_ptr \
)
{
    /* Temporary return variable / Matching entry found */
    VAR(boolean, AUTOMATIC) ret = (boolean)FALSE;
    /* Index of pool entry */
    uint16 found_cnt = 0U;
    VAR(uint8, AUTOMATIC) cnt = 0U;

    if ((boolean)TRUE == GMAC_LLD_Is_Addr_In_Mcast_Pool(gmac_id, phys_addr_ptr, &found_cnt))
    { /* Item already in the table */
        ret = (boolean)TRUE;
    }
    else if (ETH_MULTICAST_POOL_SIZE == s_Gmac_LLD_McastItemsCnt[gmac_id])
    { /* Table is full */
        ret = (boolean)FALSE;
    }
    else
    { /* Item is not in the table - Look for empty position*/
        while (ETH_MULTICAST_POOL_SIZE > found_cnt)
        { /* Loop over table items */
            if ((boolean)FALSE == s_Gmac_LLD_MulticastPool[gmac_id][found_cnt].is_active)
            { /* First empty item in table */
                /* Mark found item as used - active */
                s_Gmac_LLD_MulticastPool[gmac_id][found_cnt].is_active = (boolean)TRUE;
                /* Write address to the pools */
                for (cnt = 0U; cnt < 6U; cnt++)
                {
                    s_Gmac_LLD_MulticastPool[gmac_id][found_cnt].phys_addr[cnt] = phys_addr_ptr[cnt];
                }
                /* Increment the count of used items */
                s_Gmac_LLD_McastItemsCnt[gmac_id]++;
                /* Set return variable */
                ret = (boolean)TRUE;
                break;
            } /* Active item check */
            found_cnt++;
        } /* Items loop */
    } /* Table check */
    
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(boolean, ETH_CODE) Gmac_LLD_Mcast_Pool_Rmv_Item \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phys_addr_ptr \
)
{
    /* Index of pool entry */
    VAR(uint16, AUTOMATIC) found_cnt = 0U;
    /* Return variable */
    VAR(boolean, AUTOMATIC) ret;

    /* Look for item in the table */
    if ((boolean)TRUE ==  GMAC_LLD_Is_Addr_In_Mcast_Pool(gmac_id, phys_addr_ptr, &found_cnt))
    { /* Item was found in the table at position found_cnt */
        /* Deactivate it */
        s_Gmac_LLD_MulticastPool[gmac_id][found_cnt].is_active = (boolean)FALSE;
        /* Decrement count of used pool items */
        s_Gmac_LLD_McastItemsCnt[gmac_id]--;
        /* Set return variable */
        ret = (boolean)TRUE;
    }
    else
    { /* Item is not in the table */
        ret = (boolean)FALSE;
    }
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Mcast_GA_Add \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONSTP2CONST(uint8, ETH_CONST, ETH_APPL_CONST) phys_addr_ptr \
)
{
    /* Storage of CRC32 hash of Physical Address */
    VAR(uint32, AUTOMATIC) tmp_CRC32_hash;
    /* Manipulation variable */
    VAR(uint32, AUTOMATIC) manipulation_var;
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    /* Once pool overflow was detected the recalculation of
    * the MAC_HASH_TABLE_REG1/MAC_HASH_TABLE_REG0 registers can not be used anymore.
    * Only new group reception bit can be enabled. */
    /* Calculate CRC32 hash */
    tmp_CRC32_hash = Gmac_LLD_Get_CRC32_Hash(phys_addr_ptr, 6U);
    /* Estimate address group number */
    if (1U == (tmp_CRC32_hash >> 31U))
    { /* Address is in group located in MAC_HASH_TABLE_REG1 register */
        manipulation_var = gmac_reg->MAC_HASH_TABLE_REG1.R;/* polyspace RTE:NIV */
        manipulation_var |= ((1UL << ((tmp_CRC32_hash >> 26UL) & 0x1FUL)));

        gmac_reg->MAC_HASH_TABLE_REG1.R = manipulation_var;
    }
    else
    { /* Address is in group located in MAC_HASH_TABLE_REG0 register */
        manipulation_var = gmac_reg->MAC_HASH_TABLE_REG0.R;/* polyspace RTE:NIV */
        manipulation_var |= ((1UL << ((tmp_CRC32_hash >> 26UL) & 0x1FUL)));

        gmac_reg->MAC_HASH_TABLE_REG0.R = manipulation_var;
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
ETH_INLINE FUNC(void, ETH_CODE) Gmac_LLD_Mcast_GA_Recalculate(CONST(GmacId, ETH_CONST) gmac_id)
{
    /* Used for counting of found active items in loop */
    VAR(uint16, AUTOMATIC) found_cnt = 0U;
    /* Temporary storage of CRC32 hash  */
    VAR(uint32, AUTOMATIC) tmp_CRC32_hash;
    /* Used for calculation of value for MAC_HASH_TABLE_REG0 register */
    VAR(uint32, AUTOMATIC) tmp_reg0 = 0U;
    /* Used for calculation of value for MAC_HASH_TABLE_REG1 register */
    VAR(uint32, AUTOMATIC) tmp_reg1 = 0U;
    /* Current item index */
    VAR(uint16, AUTOMATIC) current_idx = 0U;

    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    while ((found_cnt != s_Gmac_LLD_McastItemsCnt[gmac_id]) && (ETH_MULTICAST_POOL_SIZE > current_idx))
    { /* Go over pool till ends or all active items were processed  */
        if ((boolean)TRUE == s_Gmac_LLD_MulticastPool[gmac_id][current_idx].is_active)
        { /* Filter only active items */
            /* Calculate CRC32 hash */
            tmp_CRC32_hash = Gmac_LLD_Get_CRC32_Hash(s_Gmac_LLD_MulticastPool[gmac_id][current_idx].phys_addr, 6U);
            /* Estimate address group numbers */
            if (1U == (tmp_CRC32_hash >> 31U))
            { /* Address is in group located in MAC_HASH_TABLE_REG1 register */
                tmp_reg1 |= (tmp_CRC32_hash & 0x7C000000UL) >> 25U;
            }
            else
            { /* Address is in group located in MAC_HASH_TABLE_REG0 register */
                tmp_reg0 |= (tmp_CRC32_hash & 0x7C000000UL) >> 25U;
            }
            found_cnt++;
        }
        current_idx++;
    }
    /* Write MAC_HASH_TABLE_REG1 register, change selected bit */
    gmac_reg->MAC_HASH_TABLE_REG1.R = tmp_reg1;
    /* Write MAC_HASH_TABLE_REG0 register */
    gmac_reg->MAC_HASH_TABLE_REG0.R = tmp_reg0;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Update_Phys_Addr_Filter \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
    VAR(Eth_FilterActionType, AUTOMATIC) eAction \
)
{
    /* Indicator of full open filter action */
    VAR(boolean, AUTOMATIC) full_open;
    /* Indicator of full close filter action */
    VAR(boolean, AUTOMATIC) full_close;
    /* Pattern for full open filter request */
    VAR(uint8, AUTOMATIC) full_open_pattern[] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};
    /* Pattern for full close filter request */
    VAR(uint8, AUTOMATIC) full_close_pattern[] = {0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U};

    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    static VAR(boolean, AUTOMATIC) Gmac_LLD_McastFullClose[ETH_MAXCTRLS_SUPPORTED] = {(boolean)FALSE};
    /* Fill full open filter indicator */
    full_open = Gmac_LLD_Compare_Phys_Addr(pPhysAddrPtr, full_open_pattern);
    /* Fill full close filter indicator */
    full_close = Gmac_LLD_Compare_Phys_Addr(pPhysAddrPtr, full_close_pattern);
    switch (eAction)
    {
    case ETH_ADD_TO_FILTER:
    {
        if ((boolean)TRUE == full_open)
        { /* Full open filter action (ETH_ADD_TO_FILTER) */
            gmac_reg->MAC_PACKET_FILTER.B.RA = 1U; /* Receive All */
            gmac_reg->MAC_PACKET_FILTER.B.DBF = 0U; /* Enable Broadcast Packets */

            /* Multicast filter will be bypassed at reception */
            s_Gmac_LLD_McastFullOpen[gmac_id] = (boolean)TRUE;

            Gmac_LLD_McastFullClose[gmac_id] = (boolean)FALSE;

            /* pass all multicast */
            gmac_reg->MAC_PACKET_FILTER.B.PM = 1U;
            /* Open all groups in MAC_HASH_TABLE_REG0 register */
            gmac_reg->MAC_HASH_TABLE_REG0.R = 0xFFFFFFFFU;
            /* Open all groups in MAC_HASH_TABLE_REG1 register */
            gmac_reg->MAC_HASH_TABLE_REG1.R = 0xFFFFFFFFU;
        }
        /** @requirements   SWS_Eth_00147 */
        else if ((boolean)TRUE == full_close)
        { /* Full close filter action (ETH_ADD_TO_FILTER) */
            gmac_reg->MAC_PACKET_FILTER.B.RA = 0U; /* Not Receive All */
            gmac_reg->MAC_PACKET_FILTER.B.DBF = 1U; /* Disable Broadcast Packets */
            /* Source Address Filter Enable */
            gmac_reg->MAC_PACKET_FILTER.B.SAF = 1U;
            /* Full close request excludes previous full open request */
            s_Gmac_LLD_McastFullOpen[gmac_id] = (boolean)FALSE;
            Gmac_LLD_McastFullClose[gmac_id] = (boolean)TRUE;
            /* Clean overflow flag */
            s_Gmac_LLD_McastPoolOvf[gmac_id] = (boolean)FALSE;
            /* not pass all multicast */
            gmac_reg->MAC_PACKET_FILTER.B.PM = 0U;
            /* hash multicast */
            gmac_reg->MAC_PACKET_FILTER.B.HMC = 1U;
            /* Open all groups in MAC_HASH_TABLE_REG0 register */
            gmac_reg->MAC_HASH_TABLE_REG0.R = 0x00000000U;
            /* Open all groups in MAC_HASH_TABLE_REG1 register */
            gmac_reg->MAC_HASH_TABLE_REG1.R = 0x00000000U;
        }
        else
        {   
            if(Gmac_LLD_McastFullClose[gmac_id] == (boolean)FALSE)
            {
                gmac_reg->MAC_PACKET_FILTER.B.RA = 1U; /* Receive All */
            }
            if((gmac_reg->MAC_PACKET_FILTER.B.DBF == 0U) && (s_Gmac_LLD_McastFullOpen[gmac_id] == (boolean)FALSE))/* polyspace RTE:NIV */
            {
                gmac_reg->MAC_PACKET_FILTER.B.DBF = 1U; /* Disable Broadcast Packets */
            }
            /* Regular adding of PhysAddr into the pool (ETH_ADD_TO_FILTER) */
            gmac_reg->MAC_PACKET_FILTER.B.PM = 0U;
            /* Source Address Filter Enable */
            gmac_reg->MAC_PACKET_FILTER.B.SAF = 1U;
            /* hash multicast */
            gmac_reg->MAC_PACKET_FILTER.B.HMC = 1U;
            if ((boolean)FALSE == Gmac_LLD_Mcast_Pool_Add_Item(gmac_id, pPhysAddrPtr))
            { /* Table is full */
                /* Once table is full Overflow tag is set  */
                s_Gmac_LLD_McastPoolOvf[gmac_id] = (boolean)TRUE;
            }
            /* Open Group Address for requested Physical Address */
            Gmac_LLD_Mcast_GA_Add(gmac_id, pPhysAddrPtr);
        }
        break;
    }
    case ETH_REMOVE_FROM_FILTER:
    {
        if ((boolean)TRUE == full_open)
        { /* Full open filter action (ETH_REMOVE_FROM_FILTER)  */
            gmac_reg->MAC_PACKET_FILTER.R = 0U;
            gmac_reg->MAC_PACKET_FILTER.B.DBF = 1U; /* Disable Broadcast Packets */
            /* not pass all multicast */
            gmac_reg->MAC_PACKET_FILTER.B.PM = 0U;
            /* hash multicast */
            gmac_reg->MAC_PACKET_FILTER.B.HMC = 1U;
            s_Gmac_LLD_McastFullOpen[gmac_id] = (boolean)FALSE;
            if(gmac_reg->MAC_HASH_TABLE_REG0.R == 0xFFFFFFFFUL)/* polyspace RTE:NIV */
            {
                gmac_reg->MAC_HASH_TABLE_REG0.R = 0x0000000U;
            }
            if(gmac_reg->MAC_HASH_TABLE_REG1.R == 0xFFFFFFFFUL)/* polyspace RTE:NIV */
            {
                gmac_reg->MAC_HASH_TABLE_REG1.R = 0x0000000U;
            }
        }
        /** @requirements   SWS_Eth_00147 */
        else if ((boolean)TRUE == full_close)
        { /* Full close filter action (ETH_REMOVE_FROM_FILTER) */
            /* Full close request excludes previous full open request */
            gmac_reg->MAC_PACKET_FILTER.B.PM = 0U;
            if(gmac_reg->MAC_PACKET_FILTER.B.DBF == 0U)/* polyspace RTE:NIV */
            {
                gmac_reg->MAC_PACKET_FILTER.B.DBF = 0U; /* ENable Broadcast Packets */

            }
            s_Gmac_LLD_McastFullOpen[gmac_id] = (boolean)FALSE;
            Gmac_LLD_McastFullClose[gmac_id] = (boolean)FALSE;
            /* Clean overflow flag */
            s_Gmac_LLD_McastPoolOvf[gmac_id] = (boolean)FALSE;
            Gmac_LLD_Mcast_Pool_Clean(gmac_id);
        }
        else
        { /* Regular removal of Physical Address from Pool */
            gmac_reg->MAC_PACKET_FILTER.B.PM = 0U;
            (void)Gmac_LLD_Mcast_Pool_Rmv_Item(gmac_id, pPhysAddrPtr);
        }
        if (((boolean)FALSE == s_Gmac_LLD_McastPoolOvf[gmac_id]) && ((boolean)FALSE == s_Gmac_LLD_McastFullOpen[gmac_id]))
        { /* No Pool overflow or full open request */
            /* Recalculate the pool addresses */
            Gmac_LLD_Mcast_GA_Recalculate(gmac_id);
        }
        break;
    }
    default:
    {
        /* do nothing */
        break;
    }
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Clear_Rx_Irq_Flag(CONST(GmacId, ETH_CONST) gmac_id)
{
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    if(gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.RI == 1U) /* polyspace RTE:OBAI,NIV,IDP */
    {
        gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.RI = 1U; /* write clear */
    }
    
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Clear_Tx_Irq_Flag(CONST(GmacId, ETH_CONST) gmac_id)
{
    volatile P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    if(gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.TI == 1U)  /* polyspace RTE:OBAI,NIV,IDP */
    {
        gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.TI = 1U; /* write clear */
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Tx_Irq_Flag_Set(CONST(GmacId, ETH_CONST) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(boolean, AUTOMATIC) retValue; /* Stores the result */
    
    /* Check whether the bit is set */
    if (gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.TI == 1U) /* polyspace RTE:OBAI,NIV,IDP */
    {
        retValue = (boolean)TRUE;
    }
    else
    {
        retValue = (boolean)FALSE;
    }
    
    return retValue;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Rx_Irq_Flag_Set(CONST(GmacId, ETH_CONST) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(boolean, AUTOMATIC) retValue; /* Stores the result */
    
    /* Check whether the bit is set */
    if (gmac_reg->DMA_CH[0].DMA_CH_STATUS.B.RI == 1U) /* polyspace RTE:OBAI,NIV,IDP */
    {
        retValue = (boolean)TRUE;
    }
    else
    {
        retValue = (boolean)FALSE;
    }
    
    return retValue;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Tx_Irq_Enabled(CONST(GmacId, ETH_CONST) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(boolean, AUTOMATIC) retValue; /* Stores the result */

    /* Check whether the bit is set */
    if (gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.TIE == 1U) /* polyspace RTE:OBAI,NIV,IDP */
    {
        retValue = (boolean)TRUE;
    }
    else
    {
        retValue = (boolean)FALSE;
    }

    return retValue;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Rx_Irq_Enabled(CONST(GmacId, ETH_CONST) gmac_id)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);
    VAR(boolean, AUTOMATIC) retValue; /* Stores the result */

    /* Check whether the bit is set */
    if (gmac_reg->DMA_CH[0].DMA_CH_INTERRUPT_ENABLE.B.RIE == 1U) /* polyspace RTE:OBAI,NIV,IDP */
    {
        retValue = (boolean)TRUE;
    }
    else
    {
        retValue = (boolean)FALSE;
    }
    return retValue;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Report_Transmission \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx \
)
{
    VAR(uint8, AUTOMATIC) buf_idx; /* Counter used for buffer referencing */
    VAR(uint16, AUTOMATIC) total_buf_num; /* Variable used to hold the buffs number
     - this should be faster than reading the configuration */
    /*     - to avoid its re-initializations during function calls in the loop
           it is placed here. Reading value from (ROM) memory through pointer is
           slower than local variable access (register or stack). */
    VAR(uint32, AUTOMATIC) TDES_status; /* Status bits of linked BD */
    VAR(uint8, AUTOMATIC) u8TxBufFlag; /* Temporary Tx buffer flag */
    VAR(Std_ReturnType, AUTOMATIC) Result = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) ethIf_ctrl_idx; /* Copy of the configured parameter
    EthCtrlIdxInEthIf  - this should improve execution time (multiple
    access to memory is slower than access to register) */
    ethIf_ctrl_idx = 0U; /* Get the value needed
                                  for EthIf_TxConfirmation callback call */
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);

    total_buf_num = gmac_cfg->buf_cfg.tx_ring_cnt; /* polyspace RTE:NIV,IDP */ /* Get number of buffers */

    if (total_buf_num > TX_BUFFER_COUNT)
    {
        return;
    }
    /* Compiler_Warning: (diab) this should not be a warning because they are same type. 
    No potential problem here. */
    /* memory address value to pass it to lower drivers layers*/

    /* Search through all buffers */
    for (buf_idx = 0U; buf_idx < total_buf_num; buf_idx++) /* PRQA S 2877 */
    {
        if (s_Eth_u8LockedTxBufCount[gmac_id][fifo_idx] > 0U)
        {
            /* At first check status bits of buffer */
            u8TxBufFlag = s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx];
            if ((GMAC_TXB_LOCK_U8 | GMAC_TXB_CONF_U8 | GMAC_TXB_FIRST_U8) ==  \
            ((GMAC_TXB_LOCK_U8 | GMAC_TXB_CONF_U8 | GMAC_TXB_FIRST_U8) & u8TxBufFlag) \
                )
            {   /* The frame is in LOCKEDAT or LOCKEDIT state */
                /* If there is link to BD, try to remove it */
                if (GMAC_TXB_LINK_U8 == (GMAC_TXB_LINK_U8 & u8TxBufFlag))
                {
                    P2VAR(GmacTransmitDesc, AUTOMATIC, ETH_APPL_DATA) transmit_desc = &gmac_cfg->buf_cfg.tx_desc[buf_idx];/* polyspace RTE:NIP */
                    /* There is link, may be removed only if GMAC_TXBD_R_U32=0 and GMAC_TXBD_TO1_U32=1
                        (if GMAC_TXBD_TO1_U32 would be 0 it might be frame being turned into
                        LockedIT state with BD not written yet) */
                    TDES_status = transmit_desc->TDES3.R; /* polyspace RTE:NIV,IDP */
                    if( 0U == (0x80000000U & TDES_status) )
                    { 
                        Result = (Std_ReturnType)E_OK;
                        /* Ready bit is zero -> frame was sent -> remove the link */
                        u8TxBufFlag &= (uint8)(~GMAC_TXB_LINK_U8);
                        /* Enter exclusive area before update software flag to prevent interfere */
                        s_Eth_au8TxBufFlags[gmac_id][fifo_idx][buf_idx] = u8TxBufFlag;
                    }
                }
                /* The link was removed -> LOCKEDAT state, call confirmation */
                EthIf_TxConfirmation(ethIf_ctrl_idx, buf_idx, Result);

                /* Call TxConfirmation and free buffers only if the link is gone */
                if (0U == (GMAC_TXB_LINK_U8 & u8TxBufFlag))
                {
                    Gmac_LLD_Give_Back_Tx_Buffer(gmac_id, fifo_idx, buf_idx); /* At last free the buffers */
                    /* Update number of pending confirmations, need critical section because this is RMW access */
                    SchM_Enter_Eth_EXCLUSIVE_AREA_01();
                    s_Eth_u8LockedTxBufCount[gmac_id][fifo_idx]--;
                    SchM_Exit_Eth_EXCLUSIVE_AREA_01();
                }
            }
        }
        else
        {
            break;
        }
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Mii_Read_Reg \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    VAR(uint8, AUTOMATIC) phy_addr, \
    VAR(uint8, AUTOMATIC) reg_addr, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) reg_data \
)
{
    VAR(boolean, AUTOMATIC) ret = TRUE;
    volatile VAR(uint32, AUTOMATIC) timeout_cnt = 0U;
    P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    while ((gmac_reg->MAC_MDIO_ADDRESS.B.GB != 0U) && (timeout_cnt < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        timeout_cnt++;
    }

    gmac_reg->MAC_MDIO_DATA.B.RA = reg_addr;
    gmac_reg->MAC_MDIO_DATA.B.GD = 0U;
    gmac_reg->MAC_MDIO_ADDRESS.B.PA = phy_addr;
    gmac_reg->MAC_MDIO_ADDRESS.B.RDA = reg_addr;
    gmac_reg->MAC_MDIO_ADDRESS.B.GOC = 3U; /* read  */
    gmac_reg->MAC_MDIO_ADDRESS.B.CR = 0xBU;

    gmac_reg->MAC_MDIO_ADDRESS.B.GB = 1U;

    while ((gmac_reg->MAC_MDIO_ADDRESS.B.GB != 0U) && (timeout_cnt < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        timeout_cnt++;
    }

    *reg_data = (uint16) (gmac_reg->MAC_MDIO_DATA.R & 0x0000FFFFU);/* polyspace RTE:NIV */
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Mii_Write_Reg \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    VAR(uint8, AUTOMATIC) phy_addr, \
    VAR(uint8, AUTOMATIC) reg_addr, \
    VAR(uint16, AUTOMATIC) reg_data \
)
{
    VAR(boolean, AUTOMATIC) ret = TRUE;
    volatile VAR(uint32, AUTOMATIC) timeout_cnt = 0U;
    P2VAR(GmacReg, AUTOMATIC, ETH_APPL_DATA) gmac_reg = Gmac_LLD_Get_Reg(gmac_id);

    while ((gmac_reg->MAC_MDIO_ADDRESS.B.GB != 0U) && (timeout_cnt < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        timeout_cnt++;
    }

    gmac_reg->MAC_MDIO_DATA.B.RA = reg_addr;
    gmac_reg->MAC_MDIO_DATA.B.GD = reg_data;
    gmac_reg->MAC_MDIO_ADDRESS.B.PA = phy_addr;
    gmac_reg->MAC_MDIO_ADDRESS.B.RDA = reg_addr;
    gmac_reg->MAC_MDIO_ADDRESS.B.GOC = 1U; /* write */
    gmac_reg->MAC_MDIO_ADDRESS.B.CR = 0x0BU;

    gmac_reg->MAC_MDIO_ADDRESS.B.GB = 1U;

    while ((gmac_reg->MAC_MDIO_ADDRESS.B.GB != 0U) && (timeout_cnt < DEFAULT_TIMEOUT))/* polyspace RTE:NIV */
    {
        timeout_cnt++;
    }
    return ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Tx_Buf_Cfg(CONST(GmacId, ETH_CONST) gmac_id)
{
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    /* Number of TX buffers from configuration */
    VAR(uint16, AUTOMATIC) buf_num = 0U;

    /*Index of queue*/    
    VAR(uint8, AUTOMATIC) queue_idx = 0U;
    VAR(uint32, AUTOMATIC) buf_address = 0U;

    VAR(uint32, AUTOMATIC) tx_buf_addr = 0U;
    VAR(uint32, AUTOMATIC) idx = 0U;
    VAR(uint32, AUTOMATIC) idx_j = 0U;
    for (idx_j = 0U; idx_j < TX_BUFFER_COUNT; idx_j++)
    {
        for (idx = 0U; idx < MAX_TX_BUFFER_SIZE; idx++)
        {
            gmac_cfg->buf_cfg.tx_buf_addr[idx + (MAX_TX_BUFFER_SIZE * idx_j)] = 0U; /* polyspace RTE:NIP,IDP */
        }
    }

    tx_buf_addr = (uint32)gmac_cfg->buf_cfg.tx_buf_addr; /* polyspace RTE:NIP */

    buf_num = gmac_cfg->buf_cfg.tx_ring_cnt; /* polyspace RTE:NIV */

    buf_address = (uint32)tx_buf_addr;

    if (buf_num > TX_BUFFER_COUNT)
    {
        return;
    }
    /* Store the TX buffer start address for future use */
    s_Gmac_LLD_u32TxBufStartAddr[gmac_id][queue_idx] = buf_address;
    s_Gmac_LLD_u8SearchTxBufFrom[gmac_id][queue_idx] = 0U;
    for (idx = 0U; idx < buf_num; idx++) /* PRQA S 2877 */
    {
        /* Unlock all TX buffers */
        s_Eth_au8TxBufFlags[gmac_id][queue_idx][idx] = 0U;
        gmac_cfg->buf_cfg.tx_desc[idx].TDES0.R = Gmac_LLD_Compute_Tx_Buf_Addr(gmac_id, 0U, idx); /* polyspace RTE:NIP,IDP */
        gmac_cfg->buf_cfg.tx_desc[idx].TDES1.R = 0U; /* polyspace RTE:NIP,IDP */
        gmac_cfg->buf_cfg.tx_desc[idx].TDES2.B.IOC = 1U; /* polyspace RTE:NIP,IDP */ /* interrupt notify */
        gmac_cfg->buf_cfg.tx_desc[idx].TDES3.B.CIC_TPL = 1U; /* polyspace RTE:NIP,IDP */ /* checksum */
        gmac_cfg->buf_cfg.tx_desc[idx].TDES3.B.FD = 1U; /* polyspace RTE:NIP,IDP */ /* no fragment */
        gmac_cfg->buf_cfg.tx_desc[idx].TDES3.B.LD = 1U; /* polyspace RTE:NIP,IDP */ /* no fragment */
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Rx_Buf_Cfg(CONST(GmacId, ETH_CONST) gmac_id)
{
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = Gmac_LLD_Require_Cfg(gmac_id);
    /* Number of TX buffers from configuration */
    VAR(uint16, AUTOMATIC) buf_num = 0U;
    /*Index of queue*/    
    VAR(uint8, AUTOMATIC) queue_idx = 0U;
    VAR(uint32, AUTOMATIC) rx_buf_addr = 0U;
    VAR(uint8, AUTOMATIC) idx = 0U;
    VAR(uint8, AUTOMATIC) fifo_num_max = 0U;
    VAR(uint8, AUTOMATIC) idx_fifo = 0U;
    /**
    * @brief    Address of Rx buffers ring start
    * @details  Used for optimization of buffer address computation.
    *           It is initialized during TX buffers initialization.
    */
    fifo_num_max = (uint8)gmac_cfg->ingress_cfg->EthCtrlConfigIngressFifoIdx; /* polyspace RTE:NIV,NIP,IDP */

    buf_num = (uint8)gmac_cfg->buf_cfg.rx_ring_cnt; /* polyspace RTE:NIV */
    rx_buf_addr = (uint32)gmac_cfg->buf_cfg.rx_buf_addr; /* polyspace RTE:NIP */

    /* Store the RX buffer start address for future use */
    s_Gmac_LLD_u32RxBufStartAddr[gmac_id][queue_idx] = rx_buf_addr;
    for (idx_fifo = 0U; idx_fifo <= fifo_num_max; idx_fifo++)
    {
        for (idx = 0U; idx < buf_num; idx++)
        {
            gmac_cfg->buf_cfg.rx_desc[idx].RDES0.R = Gmac_LLD_Compute_Rx_Buf_Addr(gmac_id, 0U, idx); /* polyspace RTE:NIP,IDP */
            gmac_cfg->buf_cfg.rx_desc[idx].RDES1.R = 0U; /* polyspace RTE:NIP,IDP */
            gmac_cfg->buf_cfg.rx_desc[idx].RDES2.R = 0U; /* polyspace RTE:NIP,IDP */
            gmac_cfg->buf_cfg.rx_desc[idx].RDES3.R = ((1UL<<31) | (1UL<<30) | (1UL<<24)); /* polyspace RTE:NIP,IDP */
        }
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_CheckAccessToController(VAR(GmacId, AUTOMATIC) CtrlIdx)
{
    P2CONST(GmacReg, AUTOMATIC, ETH_APPL_CONST) gmac_reg = Gmac_LLD_Get_Reg(CtrlIdx);
    VAR(uint32, AUTOMATIC) t_mac_version = 0U;/* polyspace RTE:NIV */
    t_mac_version = (uint32)gmac_reg->MAC_VERSION.R;/* polyspace RTE:NIV */
    return (((t_mac_version & 0xFFU) == 0x52U) ? TRUE : FALSE);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif
