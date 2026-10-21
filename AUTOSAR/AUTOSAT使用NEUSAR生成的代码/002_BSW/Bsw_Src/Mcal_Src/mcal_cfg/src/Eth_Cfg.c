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
/* PRQA S 0380, 1258, 0311, 0686, 0704, 0673, 1259 EOF */
/**
*   @file    Eth_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

#include "Eth.h"
#if STD_ON == ETH_CTRLENABLE_MII
#include "EthTrcv.h"
#endif
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
#include "EthSwt.h"
#endif

#define ETH_CFG_C_VENDOR_ID                     176
#define ETH_CFG_C_AR_REL_MAJOR_VER              4
#define ETH_CFG_C_AR_REL_MINOR_VER              4
#define ETH_CFG_C_AR_REL_REV_VER                0
#define ETH_CFG_C_SW_MAJOR_VER                  3
#define ETH_CFG_C_SW_MINOR_VER                  0
#define ETH_CFG_C_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != ETH_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != ETH_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != ETH_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != ETH_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != ETH_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != ETH_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != ETH_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_CFG_C_SW_PATCH_VER "
#endif

#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(GmacTransmitDesc, AUTOMATIC) g_tx_desc[TX_BUFFER_COUNT] = {{{0U}, {0U}, {0U}, {0U}}};         /* PRQA S 3218 # need in .bss, not stack */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(GmacReceiveDesc, AUTOMATIC) g_rx_desc[RX_BUFFER_COUNT] = {{{0U}, {0U}, {0U}, {0U}}};          /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(uint8, AUTOMATIC) g_tx_buf[MAX_TX_BUFFER_SIZE] = {0U};                                         /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"
static MEM_ALIGN(128) VAR(uint8, AUTOMATIC) g_rx_buf[RX_BUFFER_COUNT * MAX_RX_BUFFER_SIZE] = {0U};                       /* PRQA S 3218 */
#define ETH_STOP_SEC_VAR_SHARED_INIT
#include "Eth_MemMap.h"

#define ETH_START_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
static CONST(Eth_EgressTxCfgType, ETH_CONST) Eth_EgressTxCfgType_0[1] =
{
    {
        .EthCtrlConfigEgressFifoIdx = 0,
        .EthCtrlConfigEgressFifoBufLenByte = 1514,
        .EthCtrlConfigEgressFifoBufTotal = 1,
    }
};
#define ETH_STOP_SEC_CONFIG_DATA
#include "Eth_MemMap.h"

#define ETH_START_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
static CONST(Eth_IngressCfgType, ETH_CONST) Eth_IngressCfgType_0[1] =
{
    {
        .EthCtrlConfigIngressFifoIdx = 0,
        .EthCtrlConfigIngressFifoBufLenByte = 128,
        .EthCtrlConfigIngressFifoBufTotal = 10,
    }
};
#define ETH_STOP_SEC_CONFIG_DATA
#include "Eth_MemMap.h"

#define ETH_START_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
static CONST(GmacCfg, ETH_CONST) Eth_ControllerConfigs[ETH_MAXCTRLS_SUPPORTED] =
{
    {
        .gmac_id = GMAC_ID_0,
        .egress_cfg = (Eth_EgressTxCfgType*)Eth_EgressTxCfgType_0,
        .ingress_cfg = (Eth_IngressCfgType*)Eth_IngressCfgType_0,
        .buf_cfg =
        {
            .max_frame_len = MAX_BUFFER_SIZE,
            .tx_ring_cnt = TX_BUFFER_COUNT,
            .rx_ring_cnt = RX_BUFFER_COUNT,
            .tx_desc = g_tx_desc,
            .rx_desc = g_rx_desc,
            .tx_buf_addr = g_tx_buf,
            .rx_buf_addr = g_rx_buf,
            .tx_buf_size = (uint16)sizeof(g_tx_buf),
            .rx_buf_size = (uint16)sizeof(g_rx_buf)
        },
        .phy_cfg =
        {
            .transfer_mode = GMAC_TRANS_RGMII_MODE,
            .transfer_speed = GMAC_TRANS_SPEED_1000M,
            .transfer_duplex = GMAC_TRANS_FULL_DUPLEX,
            .mac_addr = {0x66U, 0x55U, 0x44U, 0x33U, 0x22U, 0x11U}
        },
        .func_cfg =
        {
            .inner_loop_back_en = (FALSE),
            .mii_loop_back_en = (FALSE),
            .mii_echo_mode_en = (FALSE)
        },
        .EnableRxInterrupt = (TRUE),
        .EnableTxInterrupt = (TRUE),
#if STD_ON == ETH_CTRLENABLE_MII
        .Eth_EthTrcvDriverFunctionList =
        {
            &EthTrcv_ReadMiiIndication,
            &EthTrcv_WriteMiiIndication
        },
#endif
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
        .Eth_EthSwtDriverFunctionList =
        {
            &EthSwt_EthTxAdaptBufferLength,
            &EthSwt_EthTxPrepareFrame,
            &EthSwt_EthTxProcessFrame,
            &EthSwt_EthTxFinishedIndication,
            &EthSwt_EthRxProcessFrame,
            &EthSwt_EthRxFinishedIndication
        }
#endif
    }
};
#define ETH_STOP_SEC_CONFIG_DATA
#include "Eth_MemMap.h"

#if STD_ON == ETH_MULTICORE_ENABLED
#define ETH_START_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
static CONST(Eth_core_map_t, ETH_CONST) Eth_CoreMap[ETH_MAXCTRLS_SUPPORTED] =
{
    {
        .gmac_id = GMAC_ID_0,
        .CoreId = 0U
    },
};
#define ETH_STOP_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
#endif

#define ETH_START_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
CONST(Eth_ConfigType, ETH_CONST) Eth_Config =
{
    .pController = Eth_ControllerConfigs,
#if STD_ON == ETH_MULTICORE_ENABLED
    .pEth_CoreMap = Eth_CoreMap
#endif
};
#define ETH_STOP_SEC_CONFIG_DATA
#include "Eth_MemMap.h"

#if (ETH_DEM_EVENT_DETECT == STD_ON)
#define ETH_START_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
CONST(Eth_DemErrorType,AUTOMATIC) Eth_DemErr_Ctrl[ETH_MAXCTRLS_SUPPORTED][ETH_DEM_ERROR_MAX] =
{
    {
        {(uint32)STD_ON,ETH_E_ACCESS},
        {(uint32)STD_ON,ETH_E_ALIGNMENT},
        {(uint32)STD_ON,ETH_E_CRC},
        {(uint32)STD_ON,ETH_E_LATECOLLISION},
        {(uint32)STD_ON,ETH_E_MULTIPLECOLLISION},
        {(uint32)STD_ON,ETH_E_OVERSIZEFRAME},
        {(uint32)STD_ON,ETH_E_RX_FRAMES_LOST},
        {(uint32)STD_ON,ETH_E_SINGLECOLLISION},
        {(uint32)STD_ON,ETH_E_UNDERSIZEFRAME}
    }
};
#define ETH_STOP_SEC_CONFIG_DATA
#include "Eth_MemMap.h"
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */ 
