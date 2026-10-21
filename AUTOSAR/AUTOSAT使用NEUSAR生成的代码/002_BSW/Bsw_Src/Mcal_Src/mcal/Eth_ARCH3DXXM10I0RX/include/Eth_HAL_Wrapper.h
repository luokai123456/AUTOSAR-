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

/**
*   @file    Eth_HAL_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_HAL_WRAPPER_H
#define ETH_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "Std_Types.h"
#include "Eth.h"

#define ETH_HAL_WRA_H_VENDOR_ID                     176
#define ETH_HAL_WRA_H_AR_REL_MAJOR_VER              4
#define ETH_HAL_WRA_H_AR_REL_MINOR_VER              4
#define ETH_HAL_WRA_H_AR_REL_REV_VER                0
#define ETH_HAL_WRA_H_SW_MAJOR_VER                  3
#define ETH_HAL_WRA_H_SW_MINOR_VER                  0
#define ETH_HAL_WRA_H_SW_PATCH_VER                  0

#if (ETH_CFG_H_VENDOR_ID != ETH_HAL_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_HAL_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_HAL_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_HAL_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_HAL_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_HAL_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_HAL_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_HAL_WRA_H_SW_PATCH_VER "
#endif

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Enable_Controller(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Disable_Controller(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_ModeType, ETH_CODE) Eth_Wrapper_Check_Ctrl_Is_Active(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Eth_Wrapper_Reset(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Eth_Wrapper_InitController \
( \
    CONST(uint8, ETH_CONST) CtrlIdx \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Eth_Wrapper_DeInit(VAR(uint8, AUTOMATIC) CtrlIdx);
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
);
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
);
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
);
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
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint32, ETH_CODE) Eth_Wrapper_Get_Phys_Address_Low(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint16, ETH_CODE) Eth_Wrapper_Get_Phys_Address_High(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Set_Phys_Addr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) phy_addr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Counter_Values \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) cnt_type \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Rx_Stats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) rx_stats \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Tx_Stats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) tx_stats \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Get_Tx_Err_Cnt_Val \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) tx_error_cnt_val \
);
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
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Clear_Rx_Irq_Flag(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Clear_Tx_Irq_Flag(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Tx_Irq_Flag_Set(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Rx_Irq_Flag_Set(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Tx_Irq_Enabled(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Rx_Irq_Enabled(CONST(uint8, ETH_CONST) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_Report_Transmission \
( \
    CONST(uint8, ETH_CONST) CtrlIdx, \
    CONST(uint8, ETH_CONST) fifo_idx \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_RxStatusType, ETH_CODE) Eth_Wrapper_Report_Reception \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) fifo_idx, \
    VAR(boolean, AUTOMATIC) is_irq \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_Is_Tx_Buf_Locked_BT \
( \
    CONST(uint8, ETH_CONST) CtrlIdx, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONST(Eth_BufIdxType, ETH_CONST) buf_idx \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_Wrapper_CheckAccessToController(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_ConfigureBuffer(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#if (ETH_DEM_EVENT_DETECT == STD_ON)
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Wrapper_EventStatus(VAR(uint32, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_DEM_EVENT_DETECT */

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif

#endif /* ETH_HAL_WRAPPER_H */
