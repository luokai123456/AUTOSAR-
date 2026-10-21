/* PRQA S 0380, 3432 EOF */
/* PRQA S 0491, 2844, 4342 EOF */   /* CWE */
/**************************************************************************** 
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

/**
*   @file    Eth_HAL_Wrapper.c
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
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "Eth_HAL_Wrapper.h"
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
#include "Eth_EMAC_LLDriver.h"
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#include "Eth_GMAC_LLDriver.h"
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
#if STD_ON == ETH_DEM_EVENT_DETECT
#include "Dem.h"
#endif /* ETH_DEM_EVENT_DETECT */

#define ETH_HAL_WRA_C_VENDOR_ID                     176
#define ETH_HAL_WRA_C_AR_REL_MAJOR_VER              4
#define ETH_HAL_WRA_C_AR_REL_MINOR_VER              4
#define ETH_HAL_WRA_C_AR_REL_REV_VER                0
#define ETH_HAL_WRA_C_SW_MAJOR_VER                  3
#define ETH_HAL_WRA_C_SW_MINOR_VER                  0
#define ETH_HAL_WRA_C_SW_PATCH_VER                  0

#if (ETH_CFG_H_VENDOR_ID != ETH_HAL_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_HAL_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_HAL_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_HAL_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_HAL_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_HAL_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_HAL_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_C_SW_PATCH_VER "
#endif

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Enable_Controller(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Enable_Controller((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Enable_Controller((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Disable_Controller(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Disable_Controller((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Disable_Controller((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_ModeType, ETH_CODE) Eth_Wrapper_Check_Ctrl_Is_Active(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Check_Ctrl_Is_Active((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Check_Ctrl_Is_Active((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Eth_Wrapper_Reset(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Reset((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Reset((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Eth_Wrapper_InitController \
( \
    CONST(uint8, ETH_CONST) CtrlIdx \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    P2CONST(DwmacCfg, AUTOMATIC, ETH_APPL_CONST) dwmac_cfg = &Eth_InternalCfgPtr->pController[CtrlIdx];
    return Dwmac_LLD_Init((DwmacId)CtrlIdx, dwmac_cfg);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg = &Eth_InternalCfgPtr->pController[CtrlIdx];
    return Gmac_LLD_Init((GmacId)CtrlIdx, gmac_cfg);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Eth_Wrapper_DeInit(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_DeInit((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_DeInit((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Borrow_Tx_Buffer \
(
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    P2CONST(DwmacCfg, AUTOMATIC, ETH_APPL_CONST) dwmac_cfg,
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg,
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONSTP2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_CONST) buf_idx, \
    P2P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) buf_ptr, \
    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_CONST) buf_len
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
    , VAR(uint16, AUTOMATIC) management_len
#endif
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
    return Dwmac_LLD_Borrow_Tx_Buffer(dwmac_cfg, fifo_idx, buf_idx, buf_ptr, buf_len, management_len);
#else
    return Dwmac_LLD_Borrow_Tx_Buffer(dwmac_cfg, fifo_idx, buf_idx, buf_ptr, buf_len);
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
    return Gmac_LLD_Borrow_Tx_Buffer(gmac_cfg, fifo_idx, buf_idx, buf_ptr, buf_len, management_len);
#else
    return Gmac_LLD_Borrow_Tx_Buffer(gmac_cfg, fifo_idx, buf_idx, buf_ptr, buf_len);
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Send_Msg \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) fifo_idx, \
    VAR(Eth_BufIdxType, AUTOMATIC) buf_idx, \
    VAR(Eth_FrameType, AUTOMATIC) frame_type, \
    VAR(uint32, AUTOMATIC) pkt_len, \
    VAR(boolean, AUTOMATIC) confirm, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) dest_mac
#if STD_ON == ETH_BRIDGE_SUPPORT
    , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) src_addr
#endif /* ETH_BRIDGE_SUPPORT  */
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
#if STD_ON == ETH_BRIDGE_SUPPORT
    Dwmac_LLD_Send_Msg((DwmacId)CtrlIdx, fifo_idx, buf_idx, frame_type, pkt_len, confirm, dest_mac, src_addr);
#else
    Dwmac_LLD_Send_Msg((DwmacId)CtrlIdx, fifo_idx, buf_idx, frame_type, pkt_len, confirm, dest_mac);
#endif /* ETH_BRIDGE_SUPPORT  */
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#if STD_ON == ETH_BRIDGE_SUPPORT
    Gmac_LLD_Send_Msg((GmacId)CtrlIdx, fifo_idx, buf_idx, frame_type, pkt_len, confirm, dest_mac, src_addr);
#else
    Gmac_LLD_Send_Msg((GmacId)CtrlIdx, fifo_idx, buf_idx, frame_type, pkt_len, confirm, dest_mac);
#endif /* ETH_BRIDGE_SUPPORT  */
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Mii_Read_Reg \
( \
    CONST(uint8, ETH_CONST) CtrlIdx, \
    VAR(uint8, AUTOMATIC) phy_addr, \
    VAR(uint8, AUTOMATIC) reg_addr, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) reg_data \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Mii_Read_Reg((DwmacId)CtrlIdx, phy_addr, reg_addr, reg_data);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Mii_Read_Reg((GmacId)CtrlIdx, phy_addr, reg_addr, reg_data);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Mii_Write_Reg \
( \
    CONST(uint8, ETH_CONST) CtrlIdx, \
    VAR(uint8, AUTOMATIC) phy_addr, \
    VAR(uint8, AUTOMATIC) reg_addr, \
    VAR(uint16, AUTOMATIC) reg_data \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Mii_Write_Reg((DwmacId)CtrlIdx, phy_addr, reg_addr, reg_data);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Mii_Write_Reg((GmacId)CtrlIdx, phy_addr, reg_addr, reg_data);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint32, ETH_CODE) Eth_Wrapper_Get_Phys_Address_Low(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Get_Phys_Address_Low((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Get_Phys_Address_Low((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint16, ETH_CODE) Eth_Wrapper_Get_Phys_Address_High(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Get_Phys_Address_High((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Get_Phys_Address_High((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Set_Phys_Addr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) phy_addr \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Set_Phys_Addr((DwmacId)CtrlIdx, phy_addr);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Set_Phys_Addr((GmacId)CtrlIdx, phy_addr);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Counter_Values \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) cnt_type \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Get_Counter_Values((DwmacId)CtrlIdx, cnt_type);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Get_Counter_Values((GmacId)CtrlIdx, cnt_type);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Rx_Stats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) rx_stats \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Get_Rx_Stats((DwmacId)CtrlIdx, rx_stats);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Get_Rx_Stats((GmacId)CtrlIdx, rx_stats);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Tx_Stats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) tx_stats \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Get_Tx_Stats((DwmacId)CtrlIdx, tx_stats);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Get_Tx_Stats((GmacId)CtrlIdx, tx_stats);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Tx_Err_Cnt_Val \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) tx_error_cnt_val \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Get_Tx_Err_Cnt_Val((DwmacId)CtrlIdx, tx_error_cnt_val);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Get_Tx_Err_Cnt_Val((GmacId)CtrlIdx, tx_error_cnt_val);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Update_Phys_Addr_Filter \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
    VAR(Eth_FilterActionType, AUTOMATIC) eAction \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Update_Phys_Addr_Filter((DwmacId)CtrlIdx, pPhysAddrPtr, eAction);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Update_Phys_Addr_Filter((GmacId)CtrlIdx, pPhysAddrPtr, eAction);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Clear_Rx_Irq_Flag(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Clear_Rx_Irq_Flag((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Clear_Rx_Irq_Flag((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Clear_Tx_Irq_Flag(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Clear_Tx_Irq_Flag((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Clear_Tx_Irq_Flag((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Tx_Irq_Flag_Set(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Is_Tx_Irq_Flag_Set((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Is_Tx_Irq_Flag_Set((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Rx_Irq_Flag_Set(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Is_Rx_Irq_Flag_Set((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Is_Rx_Irq_Flag_Set((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Tx_Irq_Enabled(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Is_Tx_Irq_Enabled((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Is_Tx_Irq_Enabled((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Rx_Irq_Enabled(CONST(uint8, ETH_CONST) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Is_Rx_Irq_Enabled((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Is_Rx_Irq_Enabled((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Report_Transmission \
( \
    CONST(uint8, ETH_CONST) CtrlIdx, \
    CONST(uint8, ETH_CONST) fifo_idx \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Report_Transmission((DwmacId)CtrlIdx, fifo_idx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Report_Transmission((GmacId)CtrlIdx, fifo_idx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_RxStatusType, ETH_CODE) Eth_Wrapper_Report_Reception \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) fifo_idx, \
    VAR(boolean, AUTOMATIC) is_irq \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Report_Reception((DwmacId)CtrlIdx, fifo_idx, is_irq);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Report_Reception((GmacId)CtrlIdx, fifo_idx, is_irq);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Tx_Buf_Locked_BT \
( \
    CONST(uint8, ETH_CONST) CtrlIdx, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONST(Eth_BufIdxType, ETH_CONST) buf_idx \
)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Dwmac_LLD_Is_Tx_Buf_Locked_BT((DwmacId)CtrlIdx, fifo_idx, buf_idx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Gmac_LLD_Is_Tx_Buf_Locked_BT((GmacId)CtrlIdx, fifo_idx, buf_idx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_CheckAccessToController(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    return Eth_CheckAccessToController((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    return Eth_CheckAccessToController((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_ConfigureBuffer(VAR(uint8, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    Dwmac_LLD_Tx_Buf_Cfg((DwmacId)CtrlIdx);
    Dwmac_LLD_Rx_Buf_Cfg((DwmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    Gmac_LLD_Tx_Buf_Cfg((GmacId)CtrlIdx);
    Gmac_LLD_Rx_Buf_Cfg((GmacId)CtrlIdx);
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

/**
****************************************************************************************
 * @brief  Get errors and lost frames.
 * @return void
****************************************************************************************
*/
#if (ETH_DEM_EVENT_DETECT == STD_ON)
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_EventStatus(VAR(uint32, AUTOMATIC) CtrlIdx)
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    static volatile CONSTP2VAR(DwmacReg, AUTOMATIC, ETH_APPL_CONST) reg[DWMAC_ID_BUTT] = {(volatile DwmacReg*)&ETHERNET_0};
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    static volatile CONSTP2VAR(GmacReg, AUTOMATIC, ETH_APPL_CONST) reg[GMAC_ID_BUTT] = {(volatile GmacReg*)&GMAC_0};
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    if (((boolean)FALSE) == Eth_CheckAccessToController((DwmacId)CtrlIdx))
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    if (((boolean)FALSE) == Eth_CheckAccessToController((GmacId)CtrlIdx))
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
    {
        if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREFAILED);
        }
    }
    else
    {
        if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREPASSED);
        }

        if (reg[CtrlIdx]->RX_ALIGNMENT_ERROR_PACKETS.R > 0U)
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ALIGNMENT].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ALIGNMENT].id, DEM_EVENT_STATUS_PREFAILED);
            }
        }
        else
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ALIGNMENT].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ALIGNMENT].id, DEM_EVENT_STATUS_PREPASSED);
            }
        }

        if (reg[CtrlIdx]->RX_CRC_ERROR_PACKETS.R > 0U)
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_CRC].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_CRC].id, DEM_EVENT_STATUS_PREFAILED);
            }
        }
        else
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_CRC].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_CRC].id, DEM_EVENT_STATUS_PREPASSED);
            }
        }

        if (reg[CtrlIdx]->TX_LATE_COLLISION_PACKETS.R > 0U)
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_LATECOLLISION].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_LATECOLLISION].id, DEM_EVENT_STATUS_PREFAILED);
            }
        }
        else
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_LATECOLLISION].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_LATECOLLISION].id, DEM_EVENT_STATUS_PREPASSED);
            }
        }

        if (reg[CtrlIdx]->RX_OVERSIZE_PACKETS_GOOD.R > 0U)
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_OVERSIZEFRAME].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_OVERSIZEFRAME].id, DEM_EVENT_STATUS_PREFAILED);
            }
        }
        else
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_OVERSIZEFRAME].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_OVERSIZEFRAME].id, DEM_EVENT_STATUS_PREPASSED);
            }
        }

        if (reg[CtrlIdx]->RX_UNDERSIZE_PACKETS_GOOD.R > 0U)
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_UNDERSIZEFRAME].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_UNDERSIZEFRAME].id, DEM_EVENT_STATUS_PREFAILED);
            }
        }
        else
        {
            if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_UNDERSIZEFRAME].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_UNDERSIZEFRAME].id, DEM_EVENT_STATUS_PREPASSED);
            }
        }
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_DEM_EVENT_DETECT */

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif
