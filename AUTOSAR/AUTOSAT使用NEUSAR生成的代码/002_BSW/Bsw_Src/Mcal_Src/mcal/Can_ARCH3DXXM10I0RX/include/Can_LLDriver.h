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
*   @file    Can_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifndef CAN_LLDRIVER_H_
#define CAN_LLDRIVER_H_

#ifdef __cplusplus
extern "C"{
#endif

 /*PRQA S 3472,1534,3630,0779,0654,0722,0723,1954,1756,1594,1599,1758,1536,1535 EOF*/

#include "derivative.h"
#include "status.h"
#include "devassert.h"
#include "common.h"
#include "Compiler.h"
#include "Can_Cfg.h"
#if defined(RESOURCE_SUPPORT_MCAN_DMU)
#include "eDma_LLDriver.h"
#endif

#define CAN_LLD_H_VENDOR_ID                     176
#define CAN_LLD_H_AR_REL_MAJOR_VER              4
#define CAN_LLD_H_AR_REL_MINOR_VER              4
#define CAN_LLD_H_AR_REL_REV_VER                0
#define CAN_LLD_H_SW_MAJOR_VER                  3
#define CAN_LLD_H_SW_MINOR_VER                  0
#define CAN_LLD_H_SW_PATCH_VER                  0

#if (CAN_CFG_H_VENDOR_ID != CAN_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_LLD_H_VENDOR_ID "
#endif
#if (CAN_CFG_H_AR_REL_MAJOR_VER != CAN_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_MINOR_VER != CAN_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_H_AR_REL_MINOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_REV_VER != CAN_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_LLD_H_AR_REL_REV_VER "
#endif
#if (CAN_CFG_H_SW_MAJOR_VER != CAN_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_H_SW_MAJOR_VER "
#endif
#if (CAN_CFG_H_SW_MINOR_VER != CAN_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_H_SW_MINOR_VER "
#endif
#if (CAN_CFG_H_SW_PATCH_VER != CAN_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_LLD_H_SW_PATCH_VER "
#endif

typedef struct M_CAN_tag MCAN_Type;

#define MY_BIT_MASK(_pos) (0x80000000U >> (_pos))
#define MY_BIT_GET(_word, _pos) ((_word) & (0x80000000U >> (_pos)))
#define MY_BIT_SET(_word, _pos) ((_word) |= (0x80000000U >> (_pos)))
#define MY_BIT_CLR(_word, _pos) ((_word) &= (~(0x80000000U >> (_pos))))

/* MCAN - Peripheral instance base addresses */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
#define MCAN_1_BASE                             (0xFFEE4000u)
#define MCAN_1_P                                ((MCAN_Type *)MCAN_1_BASE)

#define MCAN_2_BASE                             (0xFFEE8000u)
#define MCAN_2_P                                ((MCAN_Type *)MCAN_2_BASE)

#define MCAN_3_BASE                             (0xFFEEC000u)
#define MCAN_3_P                                ((MCAN_Type *)MCAN_3_BASE)

#define MCAN_4_BASE                             (0xFFEF0000u)
#define MCAN_4_P                                ((MCAN_Type *)MCAN_4_BASE)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
#define MCAN_5_BASE                             (0xFFEF4000u)
#define MCAN_5_P                                ((MCAN_Type *)MCAN_5_BASE)

#define MCAN_6_BASE                             (0xFFEF8000u)
#define MCAN_6_P                                ((MCAN_Type *)MCAN_6_BASE)

#define MCAN_7_BASE                             (0xFFEFC000u)
#define MCAN_7_P                                ((MCAN_Type *)MCAN_7_BASE)

#define MCAN_8_BASE                             (0xFFF00000u)
#define MCAN_8_P                                ((MCAN_Type *)MCAN_8_BASE)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
#define MCAN_9_BASE                             (0xFFEBC000u)
#define MCAN_9_P                                ((MCAN_Type *)MCAN_9_BASE)

#define MCAN_10_BASE                             (0xFFEC0000u)
#define MCAN_10_P                                ((MCAN_Type *)MCAN_10_BASE)

#define MCAN_11_BASE                            (0xFFEC4000u)
#define MCAN_11_P                               ((MCAN_Type *)MCAN_11_BASE)

#define MCAN_12_BASE                            (0xFFEC8000u)
#define MCAN_12_P                               ((MCAN_Type *)MCAN_12_BASE)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */

#if defined(RESOURCE_SUPPORT_MCAN_CONTROLLER_1) && defined(RESOURCE_SUPPORT_MCAN_CONTROLLER_9)
#define MCAN_BASE_ADDRS                         { MCAN_1_BASE, MCAN_2_BASE, MCAN_3_BASE, MCAN_4_BASE, MCAN_5_BASE, MCAN_6_BASE, MCAN_7_BASE, MCAN_8_BASE, MCAN_9_BASE, MCAN_10_BASE, MCAN_11_BASE, MCAN_12_BASE}
#define MCAN_BASE_PTRS                          { MCAN_1_P, MCAN_2_P, MCAN_3_P, MCAN_4_P, MCAN_5_P, MCAN_6_P, MCAN_7_P, MCAN_8_P, MCAN_9_P, MCAN_10_P, MCAN_11_P, MCAN_12_P}
#elif defined(RESOURCE_SUPPORT_MCAN_CONTROLLER_1) && defined(RESOURCE_SUPPORT_MCAN_CONTROLLER_5)
#define MCAN_BASE_ADDRS                         { MCAN_1_BASE, MCAN_2_BASE, MCAN_3_BASE, MCAN_4_BASE, MCAN_5_BASE, MCAN_6_BASE, MCAN_7_BASE, MCAN_8_BASE}
#define MCAN_BASE_PTRS                          { MCAN_1_P, MCAN_2_P, MCAN_3_P, MCAN_4_P, MCAN_5_P, MCAN_6_P, MCAN_7_P, MCAN_8_P}
#elif defined (RESOURCE_SUPPORT_MCAN_CONTROLLER_5)
#define MCAN_BASE_ADDRS                         { 0, 0, 0, 0, MCAN_5_BASE, MCAN_6_BASE, MCAN_7_BASE, MCAN_8_BASE}
#define MCAN_BASE_PTRS                          { 0, 0, 0, 0, MCAN_5_P, MCAN_6_P, MCAN_7_P, MCAN_8_P}
#endif

/* MCAN module features */
#if defined (RESOURCE_SUPPORT_MCAN_CONTROLLER_9)
#define MCAN_INSTANCE_COUNT                     (12u)
#else
#define MCAN_INSTANCE_COUNT                     (8u)
#endif

#define CAN_FD_MAX_NO_OF_DTB_PER_FRAME 64

#define RX_MESSAGE_LIST_ENTRIES     64U

#define TX_EVENT_FIFO_LIST_ENTRIES  32U

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
#define FEATURE_MCAN_MSG_RAM_START_ADR  0xFFED4000U
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
#define FEATURE_MCAN_MSG_RAM1_START_ADR  0xFFF04000U
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
#define FEATURE_MCAN_MSG_RAM2_START_ADR  0xFFECC000U
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */

#if defined(RESOURCE_SUPPORT_MCAN_DMU)

#define DMU_TX_ELEMENT_OFFSET_ADDRESS              0x200U

#define DMU_RX0_ELEMENT_OFFSET_ADDRESS             0x280U

#define DMU_RX1_ELEMENT_OFFSET_ADDRESS             0x300U

#define DMU_TX_EVENT_ELEMENT_OFFSET_ADDRESS        0x380U

#define DMU_TX_ELEMENT_DEBUG_OFFSET_ADDRESS        0x400U

#define DMU_RX0_ELEMENT_DEBUG_OFFSET_ADDRESS       0x480U

#define DMU_RX1_ELEMENT_DEBUG_OFFSET_ADDRESS       0x500U

#define DMU_TX_EVENT_ELEMENT_DEBUG_OFFSET_ADDRESS  0x580U

#endif

#define FEATURE_MCAN_RX_MB_NUM              (64U)

#define FEATURE_MCAN_TX_MB_NUM              (32U)

#define FEATURE_MCAN_STD_ID_NUM             (128U)

#define FEATURE_MCAN_EXT_ID_NUM             (64U)

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
#if (RESOURCE_SUPPORT_MCAN_RAM_SIZE == (64*1024U))
/* RAM(MCAN1 ~ MCAN4 shared), start address: 0xFFED4000, max size: 64KB */
#define FEATURE_MCAN_RAM_WRD_SIZE           (16384UL)

#elif (RESOURCE_SUPPORT_MCAN_RAM_SIZE == (20*1024U))
/* else RAM(MCAN1 ~ MCAN4 shared), start address: 0xFFED4000, max size: 20KB */
#define FEATURE_MCAN_RAM_WRD_SIZE           (5120UL)

#else 
    #error "no valid resource"
#endif
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
#if (RESOURCE_SUPPORT_MCAN_RAM1_SIZE == (64*1024U))
/* RAM1(MCAN5 ~ MCAN8 shared), start address: 0xFFF04000, max size: 64KB */
#define FEATURE_MCAN_RAM1_WRD_SIZE          (16384UL)

#elif (RESOURCE_SUPPORT_MCAN_RAM1_SIZE == (20*1024U))
/* else RAM1(MCAN5 ~ MCAN8 shared), start address: 0xFFF04000, max size: 20KB */
#define FEATURE_MCAN_RAM1_WRD_SIZE          (5120UL)

#else 
    #error "no valid resource"
#endif
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
#if (RESOURCE_SUPPORT_MCAN_RAM2_SIZE == (64*1024U))
/* RAM2(MCAN9 ~ MCAN12 shared), start address: 0xFFECC000, max size: 64KB */
#define FEATURE_MCAN_RAM2_WRD_SIZE          (16384UL)

#elif (RESOURCE_SUPPORT_MCAN_RAM2_SIZE == (20*1024U))
/* else RAM2(MCAN9 ~ MCAN12 shared), start address: 0xFFECC000, max size: 20KB */
#define FEATURE_MCAN_RAM2_WRD_SIZE          (5120UL)

#else 
    #error "no valid resource"
#endif
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */

#define FEATURE_MCAN_NO_RXFIFO              (2U)

#define INTERRUPT_ALL_SIGNALS       0x3FFFFFFFUL

#define TSCC_TCP_MIN_VALUE  1
#define TSCC_TCP_MAX_VALUE 16

#define LEC_NO_OF_ERROR_CODES  8

#define MCAN_STORE_RX_FIFO0                     ((uint8)0xFCU)
#define MCAN_STORE_RX_FIFO1                     ((uint8)0xFDU)
#define MCAN_FD_ID_DESCRIPTOR                   (0x40000000U)

/* ILE defines */
#define ILE_DISABLE_INTERRUPT_LINES     0x0U
#define ILE_ENABLE_INTERRUPT_LINE_0     0x1U
#define ILE_ENABLE_INTERRUPT_LINE_1     0x2U

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
#define MCAN_RAM     ((RAM_A_MB *)FEATURE_MCAN_MSG_RAM_START_ADR)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
#define MCAN_RAM1    ((RAM_B_MB *)FEATURE_MCAN_MSG_RAM1_START_ADR)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
#define MCAN_RAM2    ((RAM_C_MB *)FEATURE_MCAN_MSG_RAM2_START_ADR)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */

typedef P2FUNC(void, CAN_CODE, errorCallBack_Type)(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
typedef P2FUNC(void, CAN_CODE, mrafCallBack_Type)(VAR(uint8, AUTOMATIC) u8Can_ControllerId);

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
typedef struct
{
    VAR(uint32, AUTOMATIC) RAM[FEATURE_MCAN_RAM_WRD_SIZE];
} RAM_A_MB;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
typedef struct
{
    VAR(uint32, AUTOMATIC) RAM[FEATURE_MCAN_RAM1_WRD_SIZE];
} RAM_B_MB;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */

#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
typedef struct
{
    VAR(uint32, AUTOMATIC) RAM[FEATURE_MCAN_RAM2_WRD_SIZE];
} RAM_C_MB;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */

/* CAN module ID */
typedef enum
{
    MCAN_MOD_ID_1  = 0U,
    MCAN_MOD_ID_2  = 1U,
    MCAN_MOD_ID_3  = 2U,
    MCAN_MOD_ID_4  = 3U,
    MCAN_MOD_ID_5  = 4U,
    MCAN_MOD_ID_6  = 5U,
    MCAN_MOD_ID_7  = 6U,
    MCAN_MOD_ID_8  = 7U,
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
    MCAN_MOD_ID_9  = 8U,
    MCAN_MOD_ID_10 = 9U,
    MCAN_MOD_ID_11 = 10U,
    MCAN_MOD_ID_12 = 11U,
	MCAN_MOD_BUTT = 12U
#else
	MCAN_MOD_BUTT = 8U	
#endif
} MCANModId;

typedef struct
{
    VAR(MCANModId, AUTOMATIC)                    instance;
    VAR(uint8, AUTOMATIC)                        controllerId;
}Controller_mapping;

typedef struct
{
    VAR(MCANModId, AUTOMATIC)                    CanId;
    VAR(boolean, AUTOMATIC)                      IsUsed;
    VAR(uint32, AUTOMATIC)                       BaseWord;
    VAR(uint32, AUTOMATIC)                       mram_size_words;
}McanControlInfor;

typedef struct
{
    P2VAR(McanControlInfor, AUTOMATIC,CAN_APPL_DATA) McanCtrl;
}MCANPartitionConfig;

typedef enum{
    MCAN_LOOPBACK_INTERNAL,
    MCAN_LOOPBACK_EXTERNAL
}loopback_mode;

typedef enum {
    MCAN_SRAM_UNINIT,
    MCAN_SRAM_INITED
}mcan_sram_state_t;

typedef enum {
    MCAN_NORMAL_MODE,
    MCAN_LISTEN_ONLY_MODE,
    MCAN_LOOPBACK_MODE,
    MCAN_TEST_MODE,
    MCAN_DISABLE_MODE
}mcan_operation_modes_t;

typedef enum {
    MCAN_PAYLOAD_SIZE_8  ,
    MCAN_PAYLOAD_SIZE_12 ,
    MCAN_PAYLOAD_SIZE_16 ,
    MCAN_PAYLOAD_SIZE_20 ,
    MCAN_PAYLOAD_SIZE_24 ,
    MCAN_PAYLOAD_SIZE_32 ,
    MCAN_PAYLOAD_SIZE_48 ,
    MCAN_PAYLOAD_SIZE_64
}mcan_fd_payload_size_t;

typedef enum{
    MCAN_TX_BUFF,
    MCAN_RX_BUFF,
    MCAN_RX_FIFO0,
    MCAN_RX_FIFO1,
}mode_type_t;

typedef struct
{
    VAR(uint16, AUTOMATIC)                       brp;
    VAR(uint16, AUTOMATIC)                       prop_seg;
    VAR(uint16, AUTOMATIC)                       phase_seg1;
    VAR(uint16, AUTOMATIC)                       phase_seg2;
    VAR(uint16, AUTOMATIC)                       sjw;
    VAR(boolean, AUTOMATIC)                      tdc;
    VAR(uint16, AUTOMATIC)                       tdc_offset;
    VAR(uint16, AUTOMATIC)                       tdc_filter_window;
}bt_config_struct;

typedef struct
{
    VAR(uint16, AUTOMATIC)                       baudRateConfigId;
    VAR(bt_config_struct, AUTOMATIC)             nominal;
    VAR(bt_config_struct, AUTOMATIC)             data;
    VAR(boolean, AUTOMATIC)                      fd_ena;
    VAR(boolean, AUTOMATIC)                      brs_ena;
    VAR(boolean, AUTOMATIC)                      is_noiso;
}bt_config_canfd_struct;

typedef enum
{
  ACC_NON_MTCH_FRAMES_IN_RX_FIFO0 = 0x0,
  ACC_NON_MTCH_FRAMES_IN_RX_FIFO1 = 0x1,
  REJECT_NON_MATCHING_FRAMES             = 0x3
}GFC_accept_non_matching_frames_enum;

typedef struct
{
    VAR(GFC_accept_non_matching_frames_enum, AUTOMATIC) anfs;
    VAR(GFC_accept_non_matching_frames_enum, AUTOMATIC) anfe;
    VAR(boolean, AUTOMATIC)                             rrfs;
    VAR(boolean, AUTOMATIC)                             rrfe;
}mcan_global_filter_config_t;

typedef enum
{
    FILTER_TYPE_RANGE_ID,
    FILTER_TYPE_DUAL_ID,
    FILTER_TYPE_CLASIC,
    FILTER_TYPE_DISABLE
}filter_type;

typedef enum
{
    FILTER_CONF_DISABLE,
    FILTER_CONF_RX_FIFO0,
    FILTER_CONF_RX_FIFO1,
    FILTER_CONF_REJECT_ID,
    FILTER_CONF_SET_PRIO,
    FILTER_CONF_SET_PRIO_RX_FIFO0,
    FILTER_CONF_SET_PRIO_RX_FIFO1,
    FILTER_CONF_RX_BUFF
} filter_element_config_t;

typedef struct
{
    VAR(filter_type, AUTOMATIC)                  filterType;
    VAR(filter_element_config_t, AUTOMATIC)     filterConfig;
    VAR(boolean, AUTOMATIC)                      isExtendedFrame;
    VAR(uint32, AUTOMATIC)                       ssync;
    VAR(uint32, AUTOMATIC)                       esync;
    VAR(uint32, AUTOMATIC)                       id1;
    VAR(uint32, AUTOMATIC)                       id2;
}mcan_id_table_t;

typedef struct
{
    P2CONST(mcan_id_table_t, AUTOMATIC, CAN_APPL_CONST)    filterconfigs;
    VAR(uint8, AUTOMATIC)                                  std_filters;
    VAR(uint8, AUTOMATIC)                                  ext_filters;
}mcan_filter_config_t;

typedef enum
{
    MCAN_RXFIFO_DISABLED,
    MCAN_RXFIFO_0_ENABLE,
    MCAN_RXFIFO_1_ENABLE,
    MCAN_RXFIFO_0_1_ENABLE
}mcan_rxfifo_mode_t;

typedef enum
{
    FIFO_MODE_BLOCKING,
    FIFO_MODE_OVERWRITE
}fifo_op_mode_t;

typedef struct
{
    VAR(mcan_rxfifo_mode_t, AUTOMATIC)          rx_fifo_needed;
    VAR(fifo_op_mode_t, AUTOMATIC)              modeFIFO;
    VAR(uint8, AUTOMATIC)                       fifo_size_elems;
    VAR(uint8, AUTOMATIC)                       fifo_watermark;
    VAR(mcan_fd_payload_size_t, AUTOMATIC)      payload;
}mcan_fifo_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                        fifo_size_elems;
    VAR(uint8, AUTOMATIC)                        fifo_watermark;
}mcan_tx_event_fifo_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                        FIFO_true_QUEUE_false;
    VAR(uint8, AUTOMATIC)                        fifo_queue_size;
    VAR(uint8, AUTOMATIC)                        ded_buffers_number;
    VAR(mcan_fd_payload_size_t, AUTOMATIC)       payload;
}mcan_tx_buffer_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                        rx_buffer_size_elems;
    VAR(mcan_fd_payload_size_t, AUTOMATIC)       payload;
}mcan_dedicated_buffers_config_t;

typedef struct
{
    VAR(uint32, AUTOMATIC)                       ir_line0_select;
    VAR(uint32, AUTOMATIC)                       ir_line1_select;
    VAR(uint32, AUTOMATIC)                       tx_buffer_tran_ir_enable;
    VAR(uint32, AUTOMATIC)                       tx_buffer_cancel_fin_ir_enable;
}mcan_inter_config_t;

typedef enum {
    TSCC_TSS_TIMESTMP_CNTR_VALUE_ALWAYS_0         = 0x0,
    TSCC_TSS_TIMESTMP_CNTR_VALUE_ACCORDING_TO_TCP = 0x1,
    TSCC_TSS_TIMESTMP_CNTR_VALUE_EXTERNAL_USED    = 0x2
}tscc_tss_timestamp_select_enum;

typedef enum {
    TOCC_TOS_CONTINUOUS_OPERATION       = 0x0,
    TOCC_TOS_TMO_CNTRD_BY_TX_EVENT_FIFO = 0x1,
    TOCC_TOS_TMO_CNTRD_BY_RX_FIFO_0     = 0x2,
    TOCC_TOS_TMO_CNTRD_BY_RX_FIFO_1     = 0x3
}tocc_tos_timeout_select_enum;

typedef struct
{
    VAR(uint32, AUTOMATIC)                         ts_counter_prescaler;
    VAR(tscc_tss_timestamp_select_enum, AUTOMATIC) ts_select;
    VAR(tocc_tos_timeout_select_enum, AUTOMATIC)   to_select;
    VAR(uint16, AUTOMATIC)                         to_period;
    VAR(boolean, AUTOMATIC)                        to_counter_enable;
}mcan_timestamp_config_t;

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
typedef struct
{
    VAR(boolean, AUTOMATIC) mcan_txfifo_dmu_enable;
    VAR(boolean, AUTOMATIC) mcan_rxfifo0_dmu_enable;
    VAR(boolean, AUTOMATIC) mcan_rxfifo1_dmu_enable;
    VAR(boolean, AUTOMATIC) mcan_txeventfifo_dmu_enable;
} mcan_dmu_enable_config_t;

typedef struct
{
    VAR(uint32, AUTOMATIC) mcan_dmu_intr_enable;
} mcan_dmu_intr_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                       ResultDmaMappedChan;
    P2VAR(uint16_t, AUTOMATIC,CAN_APPL_DATA)    DestPtr;
    VAR(uint32, AUTOMATIC)                      DestLen;
    VAR(eDMACallbackType, AUTOMATIC)            Callback;
    P2VAR(void, AUTOMATIC,CAN_APPL_DATA)        CallbackParam;
} mcan_rxfifo0_dma_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                       ResultDmaMappedChan;
    P2VAR(uint16_t, AUTOMATIC,CAN_APPL_DATA)    DestPtr;
    VAR(uint32, AUTOMATIC)                      DestLen;
    VAR(eDMACallbackType, AUTOMATIC)            Callback;
    P2VAR(void, AUTOMATIC,CAN_APPL_DATA)        CallbackParam;
} mcan_rxfifo1_dma_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                       ResultDmaMappedChan;
    P2VAR(uint16_t, AUTOMATIC,CAN_APPL_DATA)    SrcPtr;
    VAR(uint32, AUTOMATIC)                      SrcLen;
    VAR(eDMACallbackType, AUTOMATIC)            Callback;
    P2VAR(void, AUTOMATIC,CAN_APPL_DATA)        CallbackParam;
} mcan_txfifo_dma_config_t;

typedef struct
{
    VAR(uint8, AUTOMATIC)                       ResultDmaMappedChan;
    P2VAR(uint16_t, AUTOMATIC,CAN_APPL_DATA)    DestPtr;
    VAR(uint32, AUTOMATIC)                      DestLen;
    VAR(eDMACallbackType, AUTOMATIC)            Callback;
    P2VAR(void, AUTOMATIC,CAN_APPL_DATA)        CallbackParam;
} mcan_txfifoevent_dma_config_t;

typedef struct
{
    P2CONST(mcan_rxfifo0_dma_config_t, AUTOMATIC,CAN_APPL_DATA)       rxfifo0_dma_config;
    P2CONST(mcan_rxfifo1_dma_config_t, AUTOMATIC,CAN_APPL_DATA)       rxfifo1_dma_config;
    P2CONST(mcan_txfifo_dma_config_t, AUTOMATIC,CAN_APPL_DATA)        txfifo_dma_config;
    P2CONST(mcan_txfifoevent_dma_config_t, AUTOMATIC,CAN_APPL_DATA)   txfifoevent_dma_config;
} mcan_dma_config_t;
#endif /* RESOURCE_SUPPORT_MCAN_DMU */

typedef enum
{
    STANDARD_ID    = 0,
    EXTENDED_ID    = 1,
    STD_AND_EXT_ID = 2
} can_id_type_enum;

typedef enum
{
    TX_DIR = 0,
    RX_DIR = 1
} can_msg_dir_enum;

typedef enum
{
    FIFO_0              = 0,
    FIFO_1              = 1,
    DEDICATED_RX_BUFFER = 2
} rx_buffer_type_enum;

typedef struct
{
    VAR(rx_buffer_type_enum, AUTOMATIC)          rx_via;
    VAR(uint32, AUTOMATIC)                       buffer_index;
    VAR(uint32, AUTOMATIC)                       rx_timestamp;
} rx_info_struct;

typedef struct
{
    VAR(boolean, AUTOMATIC)                      remote;
    VAR(can_id_type_enum, AUTOMATIC)             idtype;
    VAR(uint32, AUTOMATIC)                       id;
    VAR(boolean, AUTOMATIC)                      fdf;
    VAR(boolean, AUTOMATIC)                      brs;
    VAR(boolean, AUTOMATIC)                      esi;
    VAR(uint16, AUTOMATIC)                       dlc;
    VAR(uint8, AUTOMATIC)                        data[CAN_FD_MAX_NO_OF_DTB_PER_FRAME];
    VAR(can_msg_dir_enum, AUTOMATIC)             direction;
    VAR(rx_info_struct, AUTOMATIC)               rx_info;
    VAR(boolean, AUTOMATIC)                      efc;
    VAR(uint8, AUTOMATIC)                        tx_tsce;
    VAR(uint8, AUTOMATIC)                        mm;
} can_msg_struct;

typedef union Tx_Rx_Word0_union_tag {
    uint32_t R;
    struct
    {
        uint32_t ESI:1;
        uint32_t XTD:1;
        uint32_t RTR:1;
        uint32_t ID:29;
    } B;
}Tx_Rx_Word0;

typedef union Tx_Word1_union_tag {
    uint32_t R;
    struct
    {
        uint32_t MM0:8;
        uint32_t EFC:1;
        uint32_t TSCE:1;
        uint32_t FDF:1;
        uint32_t BRS:1;
        uint32_t DLC:4;
        uint32_t MM1:8;
        uint32_t  :8;
    } B;
}Tx_Word1;

typedef union Tx_Rx_Word_DATA_union_tag {
    uint32_t R;
    struct
    {
        uint32_t DATA_BYTE3:8;
        uint32_t DATA_BYTE2:8;
        uint32_t DATA_BYTE1:8;
        uint32_t DATA_BYTE0:8;
    } B;
}Tx_Rx_Word_DATA;

typedef struct
{
    Tx_Rx_Word0     TxWord0;
    Tx_Word1        TxWord1;
    Tx_Rx_Word_DATA TxDataWord0;
    Tx_Rx_Word_DATA TxDataWord1;
    Tx_Rx_Word_DATA TxDataWord2;
    Tx_Rx_Word_DATA TxDataWord3;
    Tx_Rx_Word_DATA TxDataWord4;
    Tx_Rx_Word_DATA TxDataWord5;
    Tx_Rx_Word_DATA TxDataWord6;
    Tx_Rx_Word_DATA TxDataWord7;
    Tx_Rx_Word_DATA TxDataWord8;
    Tx_Rx_Word_DATA TxDataWord9;
    Tx_Rx_Word_DATA TxDataWord10;
    Tx_Rx_Word_DATA TxDataWord11;
    Tx_Rx_Word_DATA TxDataWord12;
    Tx_Rx_Word_DATA TxDataWord13;
    Tx_Rx_Word_DATA TxDataWord14;
    Tx_Rx_Word_DATA TxDataWord15;
} can_txmsg_struct;

typedef union Rx_Word1A_union_tag {
    uint32_t R;
    struct
    {
        uint32_t ANMF:1;
        uint32_t FIDX:7;
        uint32_t  :2;
        uint32_t FDF:1;
        uint32_t BRS:1;
        uint32_t DLC:4;
        uint32_t RXTS:16;
    } B;
}Rx_Word1A;

typedef union Rx_Word1B_union_tag {
    uint32_t R;
    struct
    {
        uint32_t ANMF:1;
        uint32_t FIDX:7;
        uint32_t  :2;
        uint32_t FDF:1;
        uint32_t BRS:1;
        uint32_t DLC:4;
        uint32_t :11;
        uint32_t TSC:1;
        uint32_t RXTSP:4;
    } B;
}Rx_Word1B;

typedef struct
{
    Tx_Rx_Word0     RxWord0;
    Rx_Word1A       RxWord1;
    Tx_Rx_Word_DATA RxDataWord0;
    Tx_Rx_Word_DATA RxDataWord1;
    Tx_Rx_Word_DATA RxDataWord2;
    Tx_Rx_Word_DATA RxDataWord3;
    Tx_Rx_Word_DATA RxDataWord4;
    Tx_Rx_Word_DATA RxDataWord5;
    Tx_Rx_Word_DATA RxDataWord6;
    Tx_Rx_Word_DATA RxDataWord7;
    Tx_Rx_Word_DATA RxDataWord8;
    Tx_Rx_Word_DATA RxDataWord9;
    Tx_Rx_Word_DATA RxDataWord10;
    Tx_Rx_Word_DATA RxDataWord11;
    Tx_Rx_Word_DATA RxDataWord12;
    Tx_Rx_Word_DATA RxDataWord13;
    Tx_Rx_Word_DATA RxDataWord14;
    Tx_Rx_Word_DATA RxDataWord15;
} can_rxmsg_A_struct;

typedef struct
{
    Tx_Rx_Word0     RxWord0;
    Rx_Word1B       RxWord1;
    Tx_Rx_Word_DATA RxDataWord0;
    Tx_Rx_Word_DATA RxDataWord1;
    Tx_Rx_Word_DATA RxDataWord2;
    Tx_Rx_Word_DATA RxDataWord3;
    Tx_Rx_Word_DATA RxDataWord4;
    Tx_Rx_Word_DATA RxDataWord5;
    Tx_Rx_Word_DATA RxDataWord6;
    Tx_Rx_Word_DATA RxDataWord7;
    Tx_Rx_Word_DATA RxDataWord8;
    Tx_Rx_Word_DATA RxDataWord9;
    Tx_Rx_Word_DATA RxDataWord10;
    Tx_Rx_Word_DATA RxDataWord11;
    Tx_Rx_Word_DATA RxDataWord12;
    Tx_Rx_Word_DATA RxDataWord13;
    Tx_Rx_Word_DATA RxDataWord14;
    Tx_Rx_Word_DATA RxDataWord15;
} can_rxmsg_B_struct;

typedef union Tx_Event_Word1A_union_tag {
    uint32_t R;
    struct
    {
        uint32_t MM0:8;
        uint32_t ET:2;
        uint32_t FDF:1;
        uint32_t BRS:1;
        uint32_t DLC:4;
        uint32_t TSTX:16;
    } B;
}Tx_Event_Word1A;

typedef union Tx_Event_Word1B_union_tag {
    uint32_t R;
    struct
    {
        uint32_t MM0:8;
        uint32_t ET:2;
        uint32_t FDF:1;
        uint32_t BRS:1;
        uint32_t DLC:4;
        uint32_t MM1:8;
        uint32_t  :3;
        uint32_t TSC:1;
        uint32_t TXTSP:4;
    } B;
}Tx_Event_Word1B;

typedef struct
{
    Tx_Rx_Word0     Word0;
    Tx_Event_Word1A Word1;
} can_txevent_msg_A_struct;

typedef struct
{
    Tx_Rx_Word0     Word0;
    Tx_Event_Word1B Word1;
} can_txevent_msg_B_struct;

typedef enum
{
    RESERVED                               = 0,
    TX_EVENT                               = 1,
    transmission_in_spite_of_cancellation  = 2
} tx_event_fifo_elem_event_type_enum;

typedef struct
{
    VAR(boolean, AUTOMATIC)                            esi;
    VAR(can_id_type_enum, AUTOMATIC)                   idtype;
    VAR(boolean, AUTOMATIC)                            remote;
    VAR(uint32, AUTOMATIC)                             id;
    VAR(uint16, AUTOMATIC)                             mm;
    VAR(tx_event_fifo_elem_event_type_enum, AUTOMATIC) et;
    VAR(boolean, AUTOMATIC)                            fdf;
    VAR(boolean, AUTOMATIC)                            brs;
    VAR(uint16, AUTOMATIC)                             dlc;
    VAR(uint32, AUTOMATIC)                             tx_timestamp;
} tx_event_element_struct;/* PRQA S 1535 */

typedef enum {
    RECEIVE  = 0U,
    TRANSMIT = 1U
} Can_ObjectType;

typedef struct
{
    CONST(uint32, CAN_CONST)                     CanObjectId;
    CONST(uint32, CAN_CONST)                     CanControllerId;
    CONST(can_id_type_enum, CAN_CONST)           CanIdType;
    CONST(uint32, CAN_CONST)                     mbIdex;
    CONST(uint32, CAN_CONST)                     mbPayloadLength;
    CONST(uint8, CAN_CONST)                      isPolling;
    CONST(Can_ObjectType, CAN_CONST)             CanObjectType;
    CONST(uint8, CAN_CONST)                      CanFdPaddingValue;
    CONST(uint8, CAN_CONST)                      PeriodIndex;
    CONST(filter_type, AUTOMATIC)                filterType;
    CONST(uint32, AUTOMATIC)                     filterCode;
    CONST(uint32, AUTOMATIC)                     filterMask;
} mcan_hwObject;

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
typedef struct {
    P2FUNC(void, CAN_CODE, tx_fifo_dmu_transfered)(VAR(MCANModId, AUTOMATIC) instance);
    P2FUNC(void, CAN_CODE, tx_event_dmu_handler)(VAR(MCANModId, AUTOMATIC) instance);
    P2FUNC(void, CAN_CODE, rx_fifo_0_dmu_received)(VAR(MCANModId, AUTOMATIC) instance);
    P2FUNC(void, CAN_CODE, rx_fifo_1_dmu_received)(VAR(MCANModId, AUTOMATIC) instance);
} mcan_dmu_intr_callback;
#endif /* RESOURCE_SUPPORT_MCAN_DMU */

typedef struct
{
    CONST(uint32, AUTOMATIC)                     CanObjectId;
    CONST(uint32, AUTOMATIC)                     hwFilterIndex;
    CONST(rx_buffer_type_enum, AUTOMATIC)        filterRestorePos;
} mcan_hwFilter;

typedef struct
{
    CONST(MCANModId, CAN_CONST)     controllerId;
    CONST(uint16, CAN_CONST)        defaultBaudRateId;
    CONST(uint16, CAN_CONST)        baudRateConfigCount;
    P2CONST(MCANPartitionConfig, CAN_CONST, CAN_APPL_CONST)              data;
    P2CONST(bt_config_canfd_struct, CAN_CONST, CAN_APPL_CONST)           timingconfig;
    P2CONST(mcan_global_filter_config_t, CAN_CONST, CAN_APPL_CONST)      globalfilterconfig;
    P2CONST(mcan_filter_config_t, CAN_CONST, CAN_APPL_CONST)             filterconfig;
    P2CONST(mcan_fifo_config_t, CAN_CONST, CAN_APPL_CONST)               rxfifoconfig;
    P2CONST(mcan_tx_event_fifo_config_t, CAN_CONST, CAN_APPL_CONST)      txeventconfig;
    P2CONST(mcan_tx_buffer_config_t, CAN_CONST, CAN_APPL_CONST)          txbufferconfig;
    P2CONST(mcan_dedicated_buffers_config_t, CAN_CONST, CAN_APPL_CONST)  rxbufferconfig;
    P2CONST(mcan_inter_config_t, CAN_CONST, CAN_APPL_CONST)              interconfig;
    P2CONST(mcan_timestamp_config_t, CAN_CONST, CAN_APPL_CONST)          stampconfig;
    VAR(mcan_operation_modes_t, CAN_CONST)                             mcanMode;
    CONST(mrafCallBack_Type, CAN_CONST)                                  MRAFNotification;
    CONST(errorCallBack_Type, CAN_CONST)                                 ErrorNotification;
#if defined(RESOURCE_SUPPORT_MCAN_DMU)
    P2CONST(mcan_dmu_enable_config_t, CAN_CONST, CAN_APPL_CONST)         mcandmuenable;
    P2CONST(mcan_dma_config_t, CAN_CONST, CAN_APPL_CONST)                mcandmaconfig;
    CONST(boolean, CAN_CONST)                                            mcanusedmuintr;
    P2CONST(mcan_dmu_intr_config_t, CAN_CONST, CAN_APPL_CONST)           mcandmuintrenable;
    P2CONST(mcan_dmu_intr_callback, CAN_CONST, CAN_APPL_CONST)           mcandmucallback;
#endif
#if defined(RESOURCE_SUPPORT_MCAN_TSU)
    CONST(boolean, CAN_CONST)                                            tsuenable;
    CONST(uint32, CAN_CONST)                                             tcp;
#endif
} CANConfig;

#if (CAN_MULTICORE_ENABLED == STD_ON)
typedef struct
{
    CONST(MCANModId, CAN_CONST)     controllerId;
    CONST(uint32, CAN_CONST)        CoreId;
} mcan_core_map_t;
#endif

typedef struct
{
    P2CONST(mcan_hwObject, CAN_CONST, CAN_APPL_CONST) txObjectConfig;
    P2CONST(mcan_hwObject, CAN_CONST, CAN_APPL_CONST) rxObjectConfig;
    P2CONST(mcan_hwFilter, CAN_CONST, CAN_APPL_CONST) standardFilterConfig;
    P2CONST(mcan_hwFilter, CAN_CONST, CAN_APPL_CONST) extendedFilterConfig;
    CONST(uint32, CAN_CONST)                          txObjCount;
    CONST(uint32, CAN_CONST)                          rxObjCount;
    CONST(uint32, CAN_CONST)                          standardFilterCount;
    CONST(uint32, CAN_CONST)                          extendedFilterCount;
} mcan_hwObject_info;

typedef struct
{
    CONST(uint32, CAN_CONST)                            objectId;
    CONST(uint32, CAN_CONST)                            controllerId;
    CONST(uint32, CAN_CONST)                            mbBitmap;
} mcan_hth_map;

extern CONSTP2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) g_mcanBase[MCAN_INSTANCE_COUNT];

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForTxFIFO \
(
    VAR(MCANModId, AUTOMATIC) instance, \
    CONSTP2CONST(mcan_txfifo_dma_config_t, CAN_CONST, CAN_APPL_CONST) mcan_dma_config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForTxFIFOEvent \
(
    VAR(MCANModId, AUTOMATIC) instance, \
    P2CONST(mcan_txfifoevent_dma_config_t, CAN_CONST, CAN_APPL_CONST) mcan_dma_config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForRxFIFO0 \
(
    VAR(MCANModId, AUTOMATIC) instance, \
    P2CONST(mcan_rxfifo0_dma_config_t, CAN_CONST, CAN_APPL_CONST) mcan_dma_config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForRxFIFO1 \
(
    VAR(MCANModId, AUTOMATIC) instance, \
    P2CONST(mcan_rxfifo1_dma_config_t, CAN_CONST, CAN_APPL_CONST) mcan_dma_config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_GetDmaForRxFIFO \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    VAR(uint32, CAN_VAR) u32Can_Rx_fifo_number \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
#endif /* RESOURCE_SUPPORT_MCAN_DMU */


#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(status_t, CAN_CODE) Can_LLD_Init \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_Deint(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxIsEnableTranPause \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Enable \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxIsEnableDar \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Enable \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_EnterSleepStatus(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_WakeUp(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_SetExtendIDMask \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Mask \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxMsgSingleRequest \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buffer_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxMsgScanSend \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Mask \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_TxSendDedicatedMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buffer_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_TxSendFifoQueueMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_TxFifoGetNumOfFreeElems(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxSendRequestCancel \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buf_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_TxSendReqCancelFinshed \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buf_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_TxTranOccured \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Tx_buf_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32, CAN_CODE) Can_LLD_GetTXBTO \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance
)
{
    return g_mcanBase[eCan_Instance]->TXBTO.R; /* polyspace RTE:OBAI,NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"


#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_RxDedicateBufProcNewMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_RxRecFifoMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Rx_fifo_number \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_IsDataLost \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Rx_fifo_number \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_InterDisableAllSignals(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_InterruptInit \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(mcan_inter_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_IsBusOff(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_IsErrorActive(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_GetRxErrorCounter(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_GetTxErrorCounter(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_IsFDEnabled(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_isInitState(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_isSleep(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_SetTimeOut(VAR(uint32, CAN_VAR) u32Can_TimeOutDuration);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_RsetInit(VAR(MCANModId, AUTOMATIC) eCan_Instance);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_isTxInterruptMb \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Tx_buf_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_TxIsReqPending \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buffer_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
