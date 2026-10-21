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
*   @file    Eth_GMAC_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_GMAC_LLDRIVER_H_
#define ETH_GMAC_LLDRIVER_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#include "Eth_Cfg.h"
#include "Eth_GeneralTypes.h"
/****************************************************************************/

#define ETH_GMAC_LLD_H_VENDOR_ID                     176
#define ETH_GMAC_LLD_H_AR_REL_MAJOR_VER              4
#define ETH_GMAC_LLD_H_AR_REL_MINOR_VER              4
#define ETH_GMAC_LLD_H_AR_REL_REV_VER                0
#define ETH_GMAC_LLD_H_SW_MAJOR_VER                  3
#define ETH_GMAC_LLD_H_SW_MINOR_VER                  0
#define ETH_GMAC_LLD_H_SW_PATCH_VER                  0

#if (ETH_CFG_H_VENDOR_ID != ETH_GMAC_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_GMAC_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_GMAC_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_GMAC_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_GMAC_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_GMAC_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_GMAC_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_GMAC_LLD_H_SW_PATCH_VER "
#endif

/* PRQA S 0635 EOF */

#define GMAC_BUF_DESC_ALIGN 16U
#define GMAC_MAC_ADDR_SIZE 6U

#define GMAC_0_INTC_PRIOR_DMA INTR_PRI_2

#define SSCM_PHY_SEL (*(volatile uint32 *)(0xFFFF8000U + (4 * 14U)))

#define PMU_LDO  (*((volatile uint32 *)0xFFFA05D8))

/***************************************************************************
* TX Buffer Status Bits
***************************************************************************/
/** @brief    Status bit for TX buffer flags, TRUE -> buffer is locked */
#define GMAC_TXB_LOCK_U8 (8U)
/** @brief    Status bit for TX buffer flags, TRUE -> TxConfirmation pending */
#define GMAC_TXB_CONF_U8  (4U)
/** @brief    Status bit for TX buffer flags, TRUE -> buffer linked with BD */
#define GMAC_TXB_LINK_U8  (2U)
/** @brief    Status bit for TX buffer flags, TRUE -> first buffer of frame */
#define GMAC_TXB_FIRST_U8 (1U)

typedef struct GMAC_tag volatile GmacReg;

typedef struct
{
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) BUF1AP;
        } B;
    } TDES0;
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) BUF2AP;
        } B;
    } TDES1;
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) IOC:1;
            VAR(vuint32_t, AUTOMATIC) TTSE_TMWD:1;
            VAR(vuint32_t, AUTOMATIC) B2L:14;
            VAR(vuint32_t, AUTOMATIC) VTIR:2;
            VAR(vuint32_t, AUTOMATIC) HL_B1L:14;
        } B;
    } TDES2;
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) OWN:1;
            VAR(vuint32_t, AUTOMATIC) CTXT:1;
            VAR(vuint32_t, AUTOMATIC) FD:1;
            VAR(vuint32_t, AUTOMATIC) LD:1;
            VAR(vuint32_t, AUTOMATIC) CPC:2;
            VAR(vuint32_t, AUTOMATIC) SAIC:3;
            VAR(vuint32_t, AUTOMATIC) SLOTNUM_THL:4;
            VAR(vuint32_t, AUTOMATIC) TSE:1;
            VAR(vuint32_t, AUTOMATIC) CIC_TPL:2;
            VAR(vuint32_t, AUTOMATIC) TPL:1;
            VAR(vuint32_t, AUTOMATIC) FL_TPL:15;
        } B;
    } TDES3;
} GmacTransmitDesc;

typedef struct
{
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) BUF1AP;
        } B;
    } RDES0;
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
    } RDES1;
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) BUF2AP;
        } B;
    } RDES2;
    union
    {
        VAR(vuint32_t, AUTOMATIC) R;
        struct
        {
            VAR(vuint32_t, AUTOMATIC) OWN:1;
            VAR(vuint32_t, AUTOMATIC) IOC:1;
            VAR(vuint32_t, AUTOMATIC) Resv:4;
            VAR(vuint32_t, AUTOMATIC) BUF2V:1;
            VAR(vuint32_t, AUTOMATIC) BUF1V:1;
            VAR(vuint32_t, AUTOMATIC) Resv2:9;
            VAR(vuint32_t, AUTOMATIC) PL:15;
        } B;
    } RDES3;
} GmacReceiveDesc;

typedef enum
{
    GMAC_ID_0,
    GMAC_ID_BUTT
} GmacId;

typedef enum
{
    GMAC_TRANS_RGMII_MODE,
    GMAC_TRANS_MII_MODE,
    GMAC_TRANS_RMII_MODE,
    GMAC_TRANS_MODE_BUTT,
} GmacTransMode;

typedef enum
{
    GMAC_TRANS_SPEED_1000M,
    GMAC_TRANS_SPEED_100M,
    GMAC_TRANS_SPEED_10M,
    GMAC_TRANS_SPEED_BUTT,
} GmacTransSpeed;

typedef enum
{
    GMAC_TRANS_HALF_DUPLEX,
    GMAC_TRANS_FULL_DUPLEX,
} GmacTransDuplex;

typedef struct
{
    VAR(uint16, AUTOMATIC) max_frame_len;
    VAR(uint16, AUTOMATIC) tx_ring_cnt;
    VAR(uint16, AUTOMATIC) rx_ring_cnt; /* mutil ring counter can improve packet receive efficiency  */
    P2VAR(GmacTransmitDesc, AUTOMATIC, ETH_APPL_DATA) tx_desc; /* only support one tx desc */
    P2VAR(GmacReceiveDesc, AUTOMATIC, ETH_APPL_DATA) rx_desc; /* rx_desc counter equal to rx_ring_cnt */
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) tx_buf_addr;
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) rx_buf_addr;
    VAR(uint16, AUTOMATIC) tx_buf_size; /* tx_buf size equal to 1 * max_frame_len */
    VAR(uint16, AUTOMATIC) rx_buf_size; /* rx_buf size equal to rx_ring_cnt * max_frame_len */
} GmacBufCfg;

typedef struct
{
    VAR(boolean, AUTOMATIC) inner_loop_back_en;
    VAR(boolean, AUTOMATIC) mii_loop_back_en;
    VAR(boolean, AUTOMATIC) mii_echo_mode_en;
} GmacFuncCfg;

typedef struct
{
    VAR(GmacTransMode, AUTOMATIC) transfer_mode;
    VAR(GmacTransSpeed, AUTOMATIC) transfer_speed;
    VAR(GmacTransDuplex, AUTOMATIC) transfer_duplex;
    VAR(uint8, AUTOMATIC) mac_addr[GMAC_MAC_ADDR_SIZE];
} GmacPhycCfg;

typedef struct
{
    P2FUNC(void, AUTOMATIC, tx_transferred)(VAR(GmacId, AUTOMATIC) Gmac_id);
    P2FUNC(void, AUTOMATIC, rx_received) \
    ( \
        VAR(GmacId, AUTOMATIC) Gmac_id, \
        P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pkt_data, \
        VAR(uint32, AUTOMATIC) pkt_len \
    );
} GmacIntrCallback;/* PRQA S 1535 */

typedef struct
{
    VAR(uint8, AUTOMATIC) EthCtrlConfigEgressFifoIdx;
    VAR(uint16, AUTOMATIC) EthCtrlConfigEgressFifoBufLenByte;  /**< Length of one Tx buffer */
    VAR(uint8, AUTOMATIC) EthCtrlConfigEgressFifoBufTotal;         /**< Number of Tx buffers */
} Eth_EgressTxCfgType;

typedef struct
{
    VAR(uint8, AUTOMATIC) EthCtrlConfigIngressFifoIdx;
    VAR(uint16, AUTOMATIC) EthCtrlConfigIngressFifoBufLenByte;  /**< Length of one Rx buffer*/
    VAR(uint8, AUTOMATIC) EthCtrlConfigIngressFifoBufTotal;         /**< Number of Rx buffers */
} Eth_IngressCfgType;

#if STD_ON == ETH_CTRLENABLE_MII
/**
 * @brief    Type for holding function pointers to the EthTrcv
 * @details  It contains the needed function pointers to EthTrcv functions.
 */
typedef struct
{
    P2FUNC(void, AUTOMATIC, readMiiIndicationFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(uint8, AUTOMATIC) TrcvIdx, \
        VAR(uint8, AUTOMATIC) RegIdx, \
        VAR(uint16, AUTOMATIC) RegValPtr \
    );
    P2FUNC(void, AUTOMATIC, writeMiiIndicationFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(uint8, AUTOMATIC) TrcvIdx, \
        VAR(uint8, AUTOMATIC) RegIdx \
    );
} Eth_EthTrcvFunctionsType;
#endif /* ETH_CTRLENABLE_MII */

#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
/**
 * @brief    Type for holding function pointers to the EthSwt
 * @details  It contains the needed function pointers to EthSwt functions.
 */
typedef struct
{
    P2FUNC(void, AUTOMATIC, TxAdaptBufferLengthFunction) \
    ( \
        P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LengthPtr \
    );
    P2FUNC(Std_ReturnType, AUTOMATIC, TxPrepareFrameFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, \
        P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) DataPtr, \
        P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LengthPtr \
    );
    P2FUNC(Std_ReturnType, AUTOMATIC, TxProcessFrameFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, \
        P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) DataPtr, \
        P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LengthPtr \
    );
    P2FUNC(Std_ReturnType, AUTOMATIC, TxFinishedIndicationFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(Eth_BufIdxType, AUTOMATIC) BufIdx \
    );
    P2FUNC(Std_ReturnType, AUTOMATIC, RxProcessFrameFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, \
        P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) DataPtr, \
        P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LengthPtr, \
        P2VAR(boolean, AUTOMATIC, ETH_APPL_DATA) IsMgmtFrameOnlyPtr \
    );
    P2FUNC(Std_ReturnType, AUTOMATIC, RxFinishedIndicationFunction) \
    ( \
        VAR(uint8, AUTOMATIC) CtrlIdx, \
        VAR(Eth_BufIdxType, AUTOMATIC) BufIdx \
    );
} Eth_EthSwtFunctionsType;
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */

typedef struct
{
    VAR(GmacId, AUTOMATIC) gmac_id;
    P2VAR(Eth_EgressTxCfgType, AUTOMATIC, ETH_APPL_DATA) egress_cfg;
    P2VAR(Eth_IngressCfgType, AUTOMATIC, ETH_APPL_DATA) ingress_cfg;
    VAR(GmacBufCfg, AUTOMATIC) buf_cfg;
    VAR(GmacPhycCfg, AUTOMATIC) phy_cfg;
    VAR(GmacFuncCfg, AUTOMATIC) func_cfg;
    VAR(boolean, AUTOMATIC) EnableRxInterrupt;  /**< Enable interrupt requests for frame reception event */
    VAR(boolean, AUTOMATIC) EnableTxInterrupt;  /**< Enable interrupt requests for frame transmission event */
#if STD_ON == ETH_CTRLENABLE_MII
    CONST(Eth_EthTrcvFunctionsType, ETH_CONST) Eth_EthTrcvDriverFunctionList;  /**< @brief The structure with pointer functions to the EthTrcv driver functions */
#endif /* ETH_CTRLENABLE_MII */
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
    CONST(Eth_EthSwtFunctionsType, ETH_CONST) Eth_EthSwtDriverFunctionList; /**< @brief The structure with pointer functions to the EthSwt driver functions */
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
} GmacCfg;

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Enable_Controller(VAR(GmacId, AUTOMATIC) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Disable_Controller(VAR(GmacId, AUTOMATIC) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_ModeType, ETH_CODE) Gmac_LLD_Check_Ctrl_Is_Active(VAR(GmacId, AUTOMATIC) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Gmac_LLD_Reset(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Gmac_LLD_Init \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(status_t, ETH_CODE) Gmac_LLD_DeInit(VAR(GmacId, AUTOMATIC) gmac_id);
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
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
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
);
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
);
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
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Tx_Buf_Cfg(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Rx_Buf_Cfg(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint32, ETH_CODE) Gmac_LLD_Get_Phys_Address_Low(VAR(GmacId, AUTOMATIC) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(uint16, ETH_CODE) Gmac_LLD_Get_Phys_Address_High(VAR(GmacId, AUTOMATIC) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Set_Phys_Addr \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) phy_addr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Counter_Values \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) cnt_type \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Rx_Stats \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) rx_stats \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Tx_Stats \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) tx_stats \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Get_Tx_Err_Cnt_Val \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) tx_error_cnt_val \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Update_Phys_Addr_Filter \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
    VAR(Eth_FilterActionType, AUTOMATIC) eAction \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Clear_Rx_Irq_Flag(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Clear_Tx_Irq_Flag(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Tx_Irq_Flag_Set(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Rx_Irq_Flag_Set(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Tx_Irq_Enabled(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Rx_Irq_Enabled(CONST(GmacId, ETH_CONST) gmac_id);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Report_Transmission \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_RxStatusType, ETH_CODE) Gmac_LLD_Report_Reception \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    VAR(uint8, AUTOMATIC) fifo_idx, \
    VAR(boolean, AUTOMATIC) is_irq \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Gmac_LLD_Is_Tx_Buf_Locked_BT \
( \
    CONST(GmacId, ETH_CONST) gmac_id, \
    CONST(uint8, ETH_CONST) fifo_idx, \
    CONST(Eth_BufIdxType, ETH_CONST) buf_idx \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_CheckAccessToController(VAR(GmacId, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Tx_Intr_Handler_GMAC_ID_0(void);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Gmac_LLD_Rx_Intr_Handler_GMAC_ID_0(void);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif

#endif /* ETH_GMAC_LLDRIVER_H_ */
