/* PRQA S 1006, 2985, 3418, 3432, 4342, 2982, 0380 EOF */
/* PRQA S 0491, 0751, 2844, 3604, 4404, 1880,2842 EOF */   /* CWE */
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CAN
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
*   @file    Can_176_CanFD_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFd MCAL driver.
*
*   @addtogroup CanFd
*   @{
*/
#include "Can_176_CanFD_LLDriver.h"
#include "Det.h"
#include "common.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP

#define CAN_176_CANFD_LLD_C_VENDOR_ID                     176
#define CAN_176_CANFD_LLD_C_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_LLD_C_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_LLD_C_AR_REL_REV_VER                0
#define CAN_176_CANFD_LLD_C_SW_MAJOR_VER                  3
#define CAN_176_CANFD_LLD_C_SW_MINOR_VER                  0
#define CAN_176_CANFD_LLD_C_SW_PATCH_VER                  0

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_LLD_C_SW_PATCH_VER "
#endif

#define CAN_176_CANFD_START_SEC_VAR_NO_INIT
#include "Can_176_CanFD_MemMap.h"
static VAR(CanfdTransBufState, AUTOMATIC) g_trans_buf_state[CANFD_MOD_BUTT][CANFD_TRANS_BUF_TYPE_BUTT];
#define CAN_176_CANFD_STOP_SEC_VAR_NO_INIT
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"
static CONST(uint8, CAN_CONST) g_dlc_2_size_list[] =
{
    12, 16, 20, 24, 32, 48, 64,
};
#define CAN_176_CANFD_STOP_SEC_CONFIG_DATA
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_VAR_NO_INIT
#include "Can_176_CanFD_MemMap.h"
static VAR(CANFDIntrCallback, AUTOMATIC) g_intr_callback[CANFD_MOD_BUTT];
#define CAN_176_CANFD_STOP_SEC_VAR_NO_INIT
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Config_Filter \
( \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg, \
    P2CONST(CANFDConfig, AUTOMATIC, CAN_APPL_CONST) config \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Get_IntrCallback \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) canfd_ret, \
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg, \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Get_IntrCallbackRec \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) canfd_ret, \
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg, \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
/* common API */

/*******************************************************************************
 * @brief      Get CANFD register base address though ID
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE volatile FUNC(CANFDReg*, CAN_CODE) Canfd_LLD_Get_Reg(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    DEV_ASSERT(canfd_id < CANFD_MOD_BUTT);

	static volatile CONSTP2VAR(CANFDReg, AUTOMATIC, CAN_APPL_CONST) reg[CANFD_MOD_BUTT] =
	{
		[CANFD_MOD_ID_1] = (volatile CANFDReg*)&CANFD_1,
		[CANFD_MOD_ID_9] = (volatile CANFDReg*)&CANFD_9,
	};
	return reg[canfd_id];/* polyspace RTE:OBAI */
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Set CANFD transmission speed
 * @param[in]  volatile CANFDReg *canfd_reg
 *             const CANFDConfig *config
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Set_Rate \
( \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg, \
    P2CONST(CANFDConfig, AUTOMATIC, CAN_APPL_CONST) config, \
    VAR(uint16, CAN_VAR) u8Can_BaudRateId \
)
{
    /* second sample point offset */
    canfd_reg->FD_SSPOFF = config->phy_para[u8Can_BaudRateId].data_bit_rate.ssp;
    /* T Seg_1 = (S_Seg_1 + 2) * TQ */
    canfd_reg->AC_SEG_1_L = (uint8)(config->phy_para[u8Can_BaudRateId].preamble_bit_rate.seg1 - 2U);
    canfd_reg->AC_SEG_1_H = 0U;
    /* T Seg_2 = (S_Seg_2 + 1) * TQ */
    canfd_reg->AC_SEG_2 = (uint8)(config->phy_para[u8Can_BaudRateId].preamble_bit_rate.seg2 - 1U);
    /* T SJW = (S_SJW + 1) * TQ */
    canfd_reg->AC_SJW = (uint8)(config->phy_para[u8Can_BaudRateId].preamble_bit_rate.sjw - 1U);
    /* prescaler = S_PRESC + 1 */
    canfd_reg->PRESC = (uint8)(config->phy_para[u8Can_BaudRateId].preamble_bit_rate.prescaler - 1U);

    canfd_reg->FD_TIME.B.FD_SEG_1 = (uint8)(config->phy_para[u8Can_BaudRateId].data_bit_rate.seg1 - 2U);
    canfd_reg->FD_TIME.B.FD_SEG_2 = (uint32)((uint32)config->phy_para[u8Can_BaudRateId].data_bit_rate.seg2 - 1U);
    canfd_reg->FD_TIME.B.FD_SJW = (uint32)((uint32)config->phy_para[u8Can_BaudRateId].data_bit_rate.sjw - 1U);
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Config CANFD frame filter
 * @param[in]  volatile CANFDReg *canfd_reg
 *             const CANFDConfig *config
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Config_Filter \
( \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg, \
    P2CONST(CANFDConfig, AUTOMATIC, CAN_APPL_CONST) config \
)/*PRQA S 3219*/
{
    VAR(uint8, AUTOMATIC) idx = 0;
    VAR(CAN_FD_LLC_FRAME_FMT_tag, AUTOMATIC) filter_value = {.R = 0U};
    VAR(CAN_FD_LLC_FRAME_FMT_tag, AUTOMATIC) filter_mask = {.R = 0U};
    VAR(CAN_FD_ACF_ID_tag, AUTOMATIC) acfc_id_value = {.R = 0U};
    VAR(CAN_FD_ACF_ID_tag, AUTOMATIC) acfc_id_mask = {.R = 0U};

    for (idx = 0; idx < CANFD_MAX_FILTER_NUM; idx++)
    {
        if (config->filter[idx].is_valid == 0U)
        {
            continue;
        }
        canfd_reg->ACFCTRL.B.ACFADR = idx;
        if (idx < 8U) {
            canfd_reg->ACFEN_0 |= (uint8)(1U << idx);/* polyspace RTE:NIV */
        } else {
            canfd_reg->ACFEN_1 |= (uint8)(1U << (idx - (uint8)8U));/* polyspace RTE:NIV */
        }
        //
        filter_value.B.IDE = config->filter[idx].value.is_extern;
        filter_value.B.FDF = config->filter[idx].value.is_fd_format_flag;
        filter_value.B.BRS = config->filter[idx].value.is_bit_rate_switch;
        //
        filter_mask.R = 0xFFFFFFFFU;
        filter_mask.B.IDE = config->filter[idx].mask.is_extern;
        filter_mask.B.FDF = config->filter[idx].mask.is_fd_format_flag;
        filter_mask.B.BRS = config->filter[idx].mask.is_bit_rate_switch;
        //
        if(config->filter[idx].value.is_extern == 1U) /* extended ID */
        {
            acfc_id_value.R = ((config->filter[idx].value.id >> 24U) & 0xffU) |
                ((config->filter[idx].value.id >> 8U) & 0xff00U) |
                ((config->filter[idx].value.id << 8U) & 0xff0000U) |
                ((config->filter[idx].value.id << 24U) & 0xff000000U);
            acfc_id_mask.R = ((config->filter[idx].mask.id >> 24U) & 0xffU) |
                ((config->filter[idx].mask.id >> 8U) & 0xff00U) |
                ((config->filter[idx].mask.id << 8U) & 0xff0000U) |
                ((config->filter[idx].mask.id << 24U) & 0xff000000U);
        }
        else
        {
            acfc_id_value.B.ID_Byte_0 = 0U;
            acfc_id_value.B.ID_Byte_1 = 0U;
            acfc_id_value.B.ID_Byte_2 = (config->filter[idx].value.id & 0x3fU) << 2U;
            acfc_id_value.B.ID_Byte_3 = (uint8)((config->filter[idx].value.id & 0x07c0U) >> 6U);
            acfc_id_mask.B.ID_Byte_0 = 0U;
            acfc_id_mask.B.ID_Byte_1 = 0U;
            acfc_id_mask.B.ID_Byte_2 = (config->filter[idx].mask.id & 0x3fU) << 2U;
            acfc_id_mask.B.ID_Byte_3 = (uint8)((config->filter[idx].mask.id & 0x07c0U) >> 6U);
        }
        //
        canfd_reg->ACFC_ID = acfc_id_value.R;
        canfd_reg->ACFM_ID = acfc_id_mask.R;
        canfd_reg->ACFC_FMT.R = filter_value.R;
        canfd_reg->ACFM_FMT.R = filter_mask.R;
        canfd_reg->ACFC_TYPE.R = config->filter[idx].ac_frame;
        canfd_reg->ACFM_TYPE.R = config->filter[idx].am_frame;
        canfd_reg->ACFM_AF = 0xffffffffU;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Select CANFD run mode
 * @param[in]  CANFDModId canfd_id
 *             volatile CANFDReg *canfd_reg
 *             const CANFDConfig *config
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Select_Run_Mode \
( \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg, \
    P2CONST(CANFDConfig, AUTOMATIC, CAN_APPL_CONST) config \
)
{
    /* close mem err it */
    canfd_reg->MEM_STA.B.MPEN = DISABLE;

    /* retry counter */
    canfd_reg->RELIM.B.RETLIM = 1U;
    canfd_reg->RELIM.B.REALIM = 1U;

    /* water line */
    canfd_reg->LIMIT.B.AFWL = 8U;

    /* iso mode */
    canfd_reg->TCRL.B.FD_ISO = 1U; /* ISO mode */

    /* sending mode */
    canfd_reg->TCRL.B.TSMODE = 0U; /* 0->FIFO mode 1->priority decision mode */

    /* receiving mode */
    canfd_reg->RCRL.B.ROM = 0U; /* 0->overwrite the oldest message 1->discard new message */

    if (config->func_switch->inner_loop_back_en == (uint8)ENABLE)
    {
        /* inner loop back mode */
        canfd_reg->CFG_STAT.B.LBMI = ENABLE;
    }
    else if (config->func_switch->outer_loop_back_en == (uint8)ENABLE)
    {
        /* outer loop back mode */
        canfd_reg->CFG_STAT.B.LBME = ENABLE;
    }
    else if (config->func_switch->listen_only_en == (uint8)ENABLE)
    {
        /* listen_only */
        canfd_reg->TCMD.B.LOM = ENABLE;
    }
    else
    {
        /* do nothing */
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Bind CANFD Message to transmission buffer
 * @param[in]  CANFDModId canfd_id
 *             uint32 buf_idx
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(uint32, CAN_CODE) Canfd_LLD_Bind_Msg_Id_To_Trans_Buf \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) buf_idx \
)
{
    DEV_ASSERT(canfd_id < CANFD_MOD_BUTT);
    DEV_ASSERT(buf_idx < CANFD_TRANS_BUF_TYPE_BUTT);

    static VAR(CanfdTransBufMsgId, AUTOMATIC) msg_id[CAN_176_CANFD_CORE_NUM];
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/

    msg_id[u32CanFd_CoreId].attr.msg_cnt++;/* polyspace RTE:OBAI,OVFL */
    msg_id[u32CanFd_CoreId].attr.is_valid = TRUE;
    g_trans_buf_state[canfd_id][buf_idx].cur_msg = msg_id[u32CanFd_CoreId].id;/* polyspace RTE:OBAI */

    return g_trans_buf_state[canfd_id][buf_idx].cur_msg;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Get CANFD Message in transmission buffer
 * @param[in]  CANFDModId canfd_id
 *             uint32 buf_idx
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(uint32, CAN_CODE) Canfd_LLD_Get_Msg_Id_From_Trans_Buf \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) buf_idx \
)
{
    DEV_ASSERT(canfd_id < CANFD_MOD_BUTT);
    DEV_ASSERT(buf_idx < CANFD_TRANS_BUF_TYPE_BUTT);

    return g_trans_buf_state[canfd_id][buf_idx].cur_msg;/* polyspace RTE:OBAI */
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Clear CANFD Message in transmission buffer
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Clear_Msg_Id_In_Trans_Buf \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) buf_idx \
)
{
	if((canfd_id < CANFD_MOD_BUTT)&&(buf_idx < (uint32)CANFD_TRANS_BUF_TYPE_BUTT))
	{
		g_trans_buf_state[canfd_id][buf_idx].cur_msg = 0;
	}
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Convert CANFD Message length to DLC field
 * @param[in]  uint32 data_size
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(uint32, CAN_CODE) Canfd_LLD_Convert_Size2DLC(VAR(uint32, AUTOMATIC) data_size)
{
    VAR(uint32, AUTOMATIC) idx;
    VAR(uint32, AUTOMATIC) size = 0U;
    /* within 8 bytes, the DLC value is the same as the data length */
    if (data_size < (uint32)CANFD_DLC_12_BYTES)
    {
        size = data_size;
    }
    else
    {
    	for (idx = 0;
    	        idx < (sizeof(g_dlc_2_size_list) / sizeof(g_dlc_2_size_list[0])); idx++)
    	    {
    	        if (g_dlc_2_size_list[idx] == data_size)
    	        {
    	            size = idx + (uint32)CANFD_DLC_12_BYTES;
    	            break;
    	        }
    	    }
    }
    return size;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Convert DLC field to CANFD Message length
 * @param[in]  uint8 dlc_type
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(uint8, CAN_CODE) Canfd_LLD_Convert_DLC2Size(VAR(uint8, AUTOMATIC) dlc_type)
{
    VAR(uint8, AUTOMATIC) size = 0U;
    if (dlc_type < (uint32)CANFD_DLC_12_BYTES)
    {
        size = dlc_type;
    }
    else if (dlc_type >= (uint32)CANFD_DLC_TYPE_BUTT)
    {
        size = 0;
    }
    else
    {
        size = g_dlc_2_size_list[dlc_type - (uint32)CANFD_DLC_12_BYTES];
    }
    return size;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Fill in CANFD Message
 * @param[in]  volatile CANFDReg *canfd_reg
 *             const CANFDTxMsg *tx_msg
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Fill_Msg \
( \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg, \
    P2CONST(CANFDTxMsg, AUTOMATIC, CAN_APPL_CONST) tx_msg \
)
{
    VAR(uint32, AUTOMATIC) byte_idx, word_idx;

    VAR(FrameFlagl, AUTOMATIC) flag_l = {.R = 0U};

    flag_l.B.fdf = tx_msg->is_fd_format_flag;
    flag_l.B.ide = tx_msg->is_extern;
    flag_l.B.brs = tx_msg->is_bit_rate_switch;
    flag_l.B.rmf = tx_msg->is_remote;

    if (tx_msg->is_extern == TRUE) {
        canfd_reg->TBUF[0].B.TxByte_0 = (uint8)(tx_msg->id & 0xffU);
        canfd_reg->TBUF[0].B.TxByte_1 = (uint8)((tx_msg->id >> 8U) & 0xffU);
        canfd_reg->TBUF[0].B.TxByte_2 = (uint8)((tx_msg->id >> 16U) & 0xffU);
        canfd_reg->TBUF[0].B.TxByte_3 = (uint8)((tx_msg->id >> 24U) & 0xffU);
    } else {
        canfd_reg->TBUF[0].B.TxByte_0 = 0U;
        canfd_reg->TBUF[0].B.TxByte_1 = 0U;
        canfd_reg->TBUF[0].B.TxByte_2 = (uint8)((tx_msg->id & 0x3fU) << 2U);
        canfd_reg->TBUF[0].B.TxByte_3 = (uint8)((tx_msg->id & 0x07c0U) >> 6U);
    }

    canfd_reg->TBUF[1].B.TxByte_0 = (uint8)Canfd_LLD_Convert_Size2DLC(tx_msg->data_len);
    canfd_reg->TBUF[1].B.TxByte_1 = 0U;
    canfd_reg->TBUF[1].B.TxByte_2 = flag_l.R;
    canfd_reg->TBUF[1].B.TxByte_3 = 0U;
    canfd_reg->TBUF[2].R = 0U;
    canfd_reg->TBUF[3].R = 0U;

    for (byte_idx = 0, word_idx = 0; /* PRQA S 2462, 2463 */
        (word_idx * sizeof(uint32)) < tx_msg->data_len;
        byte_idx += sizeof(uint32), word_idx++)
    {
            canfd_reg->TBUF[4U + word_idx].R = (uint32)(tx_msg->data.word[word_idx]);/* polyspace RTE:OBAI */
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Launch CANFD Message transmission
 * @param[in]  CANFDModId canfd_id
 *             const CANFDTxMsg *tx_msg
 *             uint32 *msg_idx
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_LLD_Send_Msg \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2CONST(CANFDTxMsg, AUTOMATIC, CAN_APPL_CONST) tx_msg, \
    P2VAR(uint32, AUTOMATIC, CAN_APPL_DATA)msg_idx \
)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    VAR(uint32, AUTOMATIC) flag = CANFD_OK;

    switch (tx_msg->trans_buf)
    {
        case CANFD_TRANS_BUF_TYPE_PRIMARY :
        {
            if (canfd_reg->TCMD.B.TPE != 0U)/* polyspace RTE:NIV */
            {
                flag = CANFD_ERROR_TRANS_BUF_BUSY;
            }
            else
            {
                canfd_reg->TCMD.B.TBSEL = (uint8)CANFD_TRANS_BUF_TYPE_PRIMARY;
                Canfd_LLD_Fill_Msg(canfd_reg, tx_msg);
                canfd_reg->TCMD.B.TPE = ENABLE;
            }

            break;
        }
        case CANFD_TRANS_BUF_TYPE_SECONDARY :
        {
            if( canfd_reg->TCRL.B.TSSTAT == (uint8)3) /* 3 means BUFF FULL *//* polyspace RTE:NIV */
            {
                flag = CANFD_ERROR_TRANS_BUF_BUSY;
            }
            else
            {
                canfd_reg->TCMD.B.TBSEL = (uint8)CANFD_TRANS_BUF_TYPE_SECONDARY;
                Canfd_LLD_Fill_Msg(canfd_reg, tx_msg);
                canfd_reg->TCRL.B.TSNEXT = ENABLE;
                canfd_reg->TCMD.B.TSALL = ENABLE;
            }
            break;
        }
        default :
        {
            flag = CANFD_ERROR_INVALID_PARA;
            break;
        }
    }

    if(flag ==  CANFD_OK)
    {
        *msg_idx = Canfd_LLD_Bind_Msg_Id_To_Trans_Buf(canfd_id, (uint32)tx_msg->trans_buf);
    }

    return flag;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Check if a transmission is finished.
 * @param[in]  CANFDModId canfd_id
 *             uint32 msg_idx
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Canfd_LLD_Is_Msg_Transferred \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) msg_idx \
)
{
    VAR(uint32, AUTOMATIC) idx;
    VAR(Std_ReturnType, AUTOMATIC) u8Can_ret = TRUE;
    for (idx = 0; idx < (uint32)CANFD_TRANS_BUF_TYPE_BUTT; idx++)
    {
        if (Canfd_LLD_Get_Msg_Id_From_Trans_Buf(canfd_id, idx) == msg_idx)
        {
        	u8Can_ret = FALSE;
        	break;
        }
    }

    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Abort an CANFD frame transmission requests.
 * @param[in]  CANFDModId canfd_id
 *             uint32 msg_idx
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint8, CAN_CODE) Canfd_LLD_Abort_Msg_Transfer \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) msg_idx \
)
{
    VAR(uint32, AUTOMATIC) buf_idx;
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(uint8, AUTOMATIC) flag = CANFD_OK;
    for (buf_idx = 0; buf_idx < (uint32)CANFD_TRANS_BUF_TYPE_BUTT; buf_idx++)
    {
        if (Canfd_LLD_Get_Msg_Id_From_Trans_Buf(canfd_id, buf_idx) == msg_idx)
        {
            break;
        }
    }
    if (buf_idx == (uint32)CANFD_TRANS_BUF_TYPE_BUTT)
    {
        flag = CANFD_ERROR_ABORT_MSG_TRANS;
    }
    else
	{
		canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

		switch (buf_idx)
		{
			case (uint32)CANFD_TRANS_BUF_TYPE_PRIMARY :
			{
				canfd_reg->TCMD.B.TPA = ENABLE;
				if (canfd_reg->TCMD.B.TPA != (uint8)ENABLE)
				{
					flag = CANFD_ERROR_ABORT_MSG_TRANS;
				}
				break;
			}
			case (uint32)CANFD_TRANS_BUF_TYPE_SECONDARY :
			{
				canfd_reg->TCMD.B.TSA = ENABLE;
				if (canfd_reg->TCMD.B.TSA != (uint8)ENABLE)
				{
					flag = CANFD_ERROR_ABORT_MSG_TRANS;
				}
				break;
			}
			default :
			{
				/*nothing to do*/
				break;
			}
		}
		if(flag == CANFD_OK)
		{
			Canfd_LLD_Clear_Msg_Id_In_Trans_Buf(canfd_id, buf_idx);
		}
	}
    return flag;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/* receive messages */
/*******************************************************************************
 * @brief      Get an CANFD frame from Rx FIFO.
 * @param[in]  CANFDModId canfd_id
 * @param[out] CANFDRxMsg *rx_msg
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_LLD_Recv_Msg \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg \
)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(uint32, AUTOMATIC) byte_idx = 0;
    VAR(uint32, AUTOMATIC) word_idx = 0;
    VAR(uint32, AUTOMATIC) indicate = CANFD_OK;
    VAR(FrameFlagl, AUTOMATIC) flag_l;
    VAR(FrameFlagh, AUTOMATIC) flag_h;

    flag_l.R = 0;
    flag_h.B.esi = 0;

    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    if (canfd_reg->RCRL.B.RSTAT == 0U)/* polyspace RTE:NIV */
    {
    	indicate = CANFD_ERROR_NO_MSG_RECEIVED;
    }
    else
    {
		/* Read message */
		flag_l.R = (uint8)canfd_reg->RBUF[1].B.RxByte_2;/* polyspace RTE:NIV */
		flag_h.R = (uint8)canfd_reg->RBUF[1].B.RxByte_3; /* PRQA S 2983 */ /* polyspace RTE:NIV */

		rx_msg->is_extern = flag_l.B.ide;
		rx_msg->is_fd_format_flag = flag_l.B.fdf;
		rx_msg->is_bit_rate_switch = flag_l.B.brs;
		rx_msg->is_remote = flag_l.B.rmf;
		rx_msg->is_error_happened = flag_h.B.esi;
		rx_msg->data_len = Canfd_LLD_Convert_DLC2Size((uint8)canfd_reg->RBUF[1].B.RxByte_0);/* polyspace RTE:NIV */

		if (rx_msg->is_extern == TRUE) {
			rx_msg->id = ((canfd_reg->RBUF[0].R & 0xffU) << 24U) | ((canfd_reg->RBUF[0].R & 0xff00U) << 8U) |/* polyspace RTE:NIV */
				((canfd_reg->RBUF[0].R & 0xff0000U) >> 8U) | ((canfd_reg->RBUF[0].R & 0xff000000U) >> 24U);/* polyspace RTE:NIV */
		} else {
			rx_msg->id = ((canfd_reg->RBUF[0].R & 0x1fU)<<6U) | ((canfd_reg->RBUF[0].R & 0xfc00U)>>10U);/* polyspace RTE:NIV */
		}

		for (byte_idx = 0, word_idx = 0;  /* PRQA S 2462, 2463 */
			(word_idx * sizeof(uint32)) < rx_msg->data_len;
			byte_idx += sizeof(uint32), word_idx++)
		{
			rx_msg->data.word[word_idx] = canfd_reg->RBUF[4U + word_idx].R;/* polyspace RTE:NIV */
		}

		canfd_reg->RCRL.B.RREL = 1U; /* write-release */
    }
    return indicate;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/* low power */
/*******************************************************************************
 * @brief      enter to sleep mode.
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Sleep(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;

    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    /* enter the standby mode */
    canfd_reg->TCMD.B.STBY = ENABLE;
    /* wait feedback */
    while ((canfd_reg->TCMD.B.STBY != (uint8)ENABLE) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Wake up from sleep mode.
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Wakeup(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;

    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    /* exit the standby mode */
    canfd_reg->TCMD.B.STBY = DISABLE;
    /* wait feedback */
    while ((canfd_reg->TCMD.B.STBY != (uint8)DISABLE) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_InterDisableAllSignals(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;

    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    canfd_reg->INTE.R = 0U;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_InterruptInit \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    CONST(uint32, CAN_CONST) interconfig \
)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;

    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    canfd_reg->INTE.R = interconfig;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_IsBusOff(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(boolean, AUTOMATIC) u8Can_ret;
    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    if (canfd_reg->CFG_STAT.B.BUSOFF == 1U)/* polyspace RTE:NIV */
    {
    	u8Can_ret = TRUE;
    }
    else
    {
    	u8Can_ret = FALSE;
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_IsErrorActive(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(boolean, AUTOMATIC) u8Can_ret;
    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    if (canfd_reg->INTF.B.EPASS == 1U)/* polyspace RTE:NIV */
    {
    	u8Can_ret = TRUE;
    }
    else
    {
    	u8Can_ret = FALSE;
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_IsDataLost(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(boolean, AUTOMATIC) u8Can_ret;
    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    if (canfd_reg->RCRL.B.ROV == 1U)/* polyspace RTE:NIV */
    {
    	u8Can_ret = TRUE;
    }
    else
    {
    	u8Can_ret = FALSE;
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_isInitState(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(boolean, AUTOMATIC) u8Can_ret;
    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    if (canfd_reg->CFG_STAT.B.RESET == (uint8)ENABLE)/* polyspace RTE:NIV */
    {
    	u8Can_ret = TRUE;
    }
    else
    {
    	u8Can_ret = FALSE;
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(boolean, CAN_CODE) Canfd_LLD_isSleep(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(boolean, AUTOMATIC) u8Can_ret;
    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);

    if (canfd_reg->TCMD.B.STBY == (uint8)ENABLE)/* polyspace RTE:NIV */
    {
    	u8Can_ret = TRUE;
    }
    else
    {
    	u8Can_ret = FALSE;
    }
    return u8Can_ret;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"


/*******************************************************************************
 * @brief      hook CANFD interrupt callback function
 * @param[in]  volatile CANFDReg *reg
 *             const CANFDConfig *config
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Init_Intr \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2CONST(CANFDIntrCallback, AUTOMATIC, CAN_APPL_CONST) callback \
)
{
    cc_memcpy((uint8 *)&g_intr_callback[(uint32)canfd_id],  /* PRQA S 2934 */
        (const uint8 *)callback, sizeof(CANFDIntrCallback));
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_Can_IsTransmitBusy
(
    VAR(uint32,AUTOMATIC)eCanfd_176CANx,
    VAR(CANFDTransBufType,AUTOMATIC) type
)
{
    VAR(uint32, AUTOMATIC) u8IsTransmitBusy = 0U;
    P2CONST(CANFDReg, AUTOMATIC, CAN_APPL_CODE) pCanfd_176Reg;
    pCanfd_176Reg = Canfd_LLD_Get_Reg((CANFDModId)eCanfd_176CANx);

    if (CANFD_TRANS_BUF_TYPE_PRIMARY == type)
    {
        u8IsTransmitBusy =pCanfd_176Reg->TCMD.B.TPE;/* polyspace RTE:NIV */
    }
    else
    {
        if (3U == pCanfd_176Reg->TCRL.B.TSSTAT)/* polyspace RTE:NIV */
        {
            u8IsTransmitBusy = 1;
        }
        else
        {
            u8IsTransmitBusy = 0;
        }
    }
    return u8IsTransmitBusy;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      CANFD interrupt callback function
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Get_IntrCallbackRec \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) canfd_ret, \
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg, \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg
)
{
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;
    if ((canfd_id < CANFD_MOD_BUTT)&&(canfd_reg->INTF.B.RIF != 0U))/* polyspace RTE:NIV */
    {
        canfd_reg->INTF.R = 0x80000000U;
        if (g_intr_callback[canfd_id].rx_received != NULL_PTR)
        {
            while ((CANFD_ERROR_NO_MSG_RECEIVED != canfd_ret) && (Can_Timeout < DEFAULT_TIMEOUT))
            {
                cc_memset((uint8 *)&rx_msg, 0, sizeof(rx_msg));
                canfd_ret = Canfd_LLD_Recv_Msg(canfd_id, &rx_msg);
                if (canfd_ret == CANFD_OK)
                {
                    g_intr_callback[canfd_id].rx_received(canfd_id, &rx_msg);/* polyspace RTE:COR */
                }
                Can_Timeout++;
            }
        }
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
CAN_176_CANFD_INLINE FUNC(void, CAN_CODE) Canfd_LLD_Get_IntrCallback \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    VAR(uint32, AUTOMATIC) canfd_ret, \
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg, \
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg
)
{
    if(canfd_id < CANFD_MOD_BUTT)
    {
		if (canfd_reg->INTF.B.TPIF != 0U)/* polyspace RTE:NIV */
		{
			canfd_reg->INTF.R = 0x08000000U;
			Canfd_LLD_Clear_Msg_Id_In_Trans_Buf(canfd_id, (uint32)CANFD_TRANS_BUF_TYPE_PRIMARY);
			if (g_intr_callback[canfd_id].tx_transferred != NULL_PTR)
			{
				g_intr_callback[canfd_id].tx_transferred(canfd_id, CANFD_TRANS_BUF_TYPE_PRIMARY);/* polyspace RTE:COR */
			}
		}
		if (canfd_reg->INTF.B.TSIF != 0U)/* polyspace RTE:NIV */
		{
			canfd_reg->INTF.R = 0x04000000U;
			Canfd_LLD_Clear_Msg_Id_In_Trans_Buf(canfd_id, (uint32)CANFD_TRANS_BUF_TYPE_SECONDARY);
			if (g_intr_callback[canfd_id].tx_transferred != NULL_PTR)
			{
				g_intr_callback[canfd_id].tx_transferred(canfd_id, CANFD_TRANS_BUF_TYPE_SECONDARY);/* polyspace RTE:COR */
			}
		}
        Canfd_LLD_Get_IntrCallbackRec(canfd_id, canfd_ret, rx_msg, canfd_reg);
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Canfd_LLD_Intr_Callback(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    VAR(uint32, AUTOMATIC) canfd_ret = CANFD_OK;
    VAR(CANFDRxMsg, AUTOMATIC) rx_msg = {0};
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    Canfd_LLD_Get_IntrCallback (canfd_id, canfd_ret, rx_msg, canfd_reg);
    if (canfd_reg->INTF.B.ROIF != 0U)/* polyspace RTE:NIV */
    {
        canfd_reg->INTF.R = 0x40000000U;
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)CAN_176_CANFD_MODULE_ID, \
            (uint8)CAN_176_CANFD_INSTANCE, \
            (uint8)CAN_176_CANFD_SID_MAIN_FUNCTION_READ, \
            (uint8)CAN_176_CANFD_E_DATALOST \
        );
    }
    if (canfd_reg->INTF.B.RFIF != 0U)/* polyspace RTE:NIV */
    {
        canfd_reg->INTF.R = 0x20000000U;
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)CAN_176_CANFD_MODULE_ID, \
            (uint8)CAN_176_CANFD_INSTANCE, \
            (uint8)CAN_176_CANFD_SID_MAIN_FUNCTION_READ, \
            (uint8)CAN_176_CANFD_E_DATALOST \
        );
    }
    if(canfd_id < CANFD_MOD_BUTT)
    {
		if (canfd_reg->INTF.B.BEIF != 0U)/* polyspace RTE:NIV */
		{
			canfd_reg->INTF.R = 0x00010000U;
			if (canfd_reg->CFG_STAT.B.BUSOFF == 1U)/* polyspace RTE:NIV */
			{
				if (g_intr_callback[canfd_id].busoff != NULL_PTR)
				{
					g_intr_callback[canfd_id].busoff((uint8)canfd_id);/* polyspace RTE:COR */
				}
			}
		}
		if (canfd_reg->INTF.B.EIF != 0U)/* polyspace RTE:NIV */
		{
			canfd_reg->INTF.R = 0x02000000U;
			if (g_intr_callback[canfd_id].error != NULL_PTR)
			{
				g_intr_callback[canfd_id].error((uint8)canfd_id);/* polyspace RTE:COR */
			}
		}
    }
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/* CANFD Diag */
/*******************************************************************************
 * @brief      Update CANFD TX and RX error counter.
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(const CANFDErrorCnt *, CAN_CODE) Canfd_LLD_Get_Error_Counter(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile CONSTP2CONST(CANFDReg, CAN_CONST, CAN_APPL_CONST) canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    static VAR(CANFDErrorCnt, AUTOMATIC) error_cnt[CAN_176_CANFD_CORE_NUM];
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();    /*get coreid*/

    error_cnt[u32CanFd_CoreId].rx_cnt = canfd_reg->RECNT;/* polyspace RTE:NIV,OBAI */
    error_cnt[u32CanFd_CoreId].tx_cnt = canfd_reg->TECNT;/* polyspace RTE:NIV */

    return &error_cnt[u32CanFd_CoreId]; /* PRQA S 2934 */
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/* CANFD init */
/*******************************************************************************
 * @brief      Initializes the CANFD peripheral bnase on the specified parameters.
 * @param[in]  const CANFDConfig *config
 * @param[out] CANDriver *canfd
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(status_t, CAN_CODE) Canfd_LLD_Init \
( \
    VAR(CANFDModId, AUTOMATIC) canfd_id, \
    P2CONST(CANFDConfig, AUTOMATIC, CAN_APPL_CONST) config, \
    VAR(uint16, AUTOMATIC) u8Can_BaudRateId \
)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;

    /* canfd mode*/
#ifdef CCFC3012PT
    *(uint32 *)0xffff804cU = 0x80ffffffU;
#elif CCFC3007PT
    *(uint32 *)0xffff804cU = 0x80000fffU;
#endif

    /* SCR0 1U << 22U */
    #ifdef RESOURCE_SUPPORT_SIUL2_IP
    if ((SIUL2.SCR0.R & 0x400000U) != 0x400000U)
    {
        SIUL2.SCR0.R |= 0x400000U;
    }
    #endif
    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    /* hardware reset */
    canfd_reg->CFG_STAT.B.RESET = ENABLE;
    while ((canfd_reg->CFG_STAT.B.RESET != (uint8)ENABLE) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }
    /* close memory error IRQ */
    canfd_reg->MEM_STA.B.MPEN = DISABLE;
    /* config bit rate */
    Canfd_LLD_Set_Rate(canfd_reg, config, u8Can_BaudRateId);
    /* select mode */
    Canfd_LLD_Select_Run_Mode(canfd_reg, config);
    /* config filter */
    Canfd_LLD_Config_Filter(canfd_reg,config);
    /* start running */
    canfd_reg->CFG_STAT.B.RESET = DISABLE;
    Can_Timeout = 0U;
    while ((canfd_reg->CFG_STAT.B.RESET != (uint8)DISABLE) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }
    return STATUS_SUCCESS;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*******************************************************************************
 * @brief      Deinitializes the CAN peripheral.
 * @param[in]  CANDriver *canfd
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(uint32, CAN_CODE) Canfd_LLD_DeInit(VAR(CANFDModId, AUTOMATIC) canfd_id)
{
    volatile P2VAR(CANFDReg, AUTOMATIC, CAN_APPL_DATA) canfd_reg = NULL_PTR;

    /* fetch register */
    canfd_reg = Canfd_LLD_Get_Reg(canfd_id);
    /* hardware reset */
    canfd_reg->CFG_STAT.B.RESET = ENABLE;

    return CANFD_OK;
}
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#endif /* RESOURCE_SUPPORT_CANFD_IP */
