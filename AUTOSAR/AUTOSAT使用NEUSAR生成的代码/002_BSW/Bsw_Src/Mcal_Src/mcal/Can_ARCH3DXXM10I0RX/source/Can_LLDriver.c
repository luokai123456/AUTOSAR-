/* PRQA S 0380, 1006, 3432, 4558, 4115, 2982, 2934, 5591, 4499, 3305, 1258, 1291, 2986, 2995, 2991, 3675, 0310, 0751, 0488 EOF */
/* PRQA S 0491, 2844, 3604, 4397, 4542, 1841, 1281 EOF */   /* CWE */
/**************************************************************************** 
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
*   @file    Can_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

 /*PRQA S 0380,1503,1505,3469,2016,2023,2024,2004,2984,0404,4404,0499,0654,2985,2842,2843,2812 EOF*/
#include "Can_LLDriver.h"
#include "Can_Cfg.h"
#include "Can.h"
#include "SchM_Can.h"
#ifdef CAN_TIMEOUT_USE_OS
    #include "Os.h"
#endif

#define CAN_LLD_C_VENDOR_ID                     176
#define CAN_LLD_C_AR_REL_MAJOR_VER              4
#define CAN_LLD_C_AR_REL_MINOR_VER              4
#define CAN_LLD_C_AR_REL_REV_VER                0
#define CAN_LLD_C_SW_MAJOR_VER                  3
#define CAN_LLD_C_SW_MINOR_VER                  0
#define CAN_LLD_C_SW_PATCH_VER                  0

#if (CAN_CFG_H_VENDOR_ID != CAN_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_LLD_C_VENDOR_ID "
#endif
#if (CAN_CFG_H_AR_REL_MAJOR_VER != CAN_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_MINOR_VER != CAN_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_C_AR_REL_MINOR_VER "
#endif
#if (CAN_CFG_H_AR_REL_REV_VER != CAN_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_LLD_C_AR_REL_REV_VER "
#endif
#if (CAN_CFG_H_SW_MAJOR_VER != CAN_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_C_SW_MAJOR_VER "
#endif
#if (CAN_CFG_H_SW_MINOR_VER != CAN_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_LLD_C_SW_MINOR_VER "
#endif
#if (CAN_CFG_H_SW_PATCH_VER != CAN_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_LLD_C_SW_PATCH_VER "
#endif

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
CONSTP2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) g_mcanBase[MCAN_INSTANCE_COUNT] = MCAN_BASE_PTRS; /* PRQA S 3004 */
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"
CONST(uint32_t, AUTOMATIC) g_mcanBaseAddr[MCAN_INSTANCE_COUNT];
CONST(uint32_t, AUTOMATIC) g_mcanBaseAddr[MCAN_INSTANCE_COUNT] = MCAN_BASE_ADDRS;
#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(uint32, CAN_VAR) s_u32Can_TimeOut[CAN_CORE_NUM] = {0U};
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(uint8, CAN_VAR) s_u32Can_IsTimeOut[CAN_CORE_NUM] = {0U};
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
static VAR(mcan_sram_state_t, CAN_VAR) s_eCan_SramState[CAN_CONTROLLER_COUNT] = {MCAN_SRAM_UNINIT}; /* PRQA S 3218 */
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
#define CAN_START_SEC_VAR_INIT
#include "Can_MemMap.h"
VAR(mcan_dmu_intr_callback, CAN_VAR) g_dmu_intr_callback[MCAN_INSTANCE_COUNT];
VAR(mcan_dmu_intr_callback, CAN_VAR) g_dmu_intr_callback[MCAN_INSTANCE_COUNT] = {{NULL_PTR}};/* PRQA S 0686,0703 */
#define CAN_STOP_SEC_VAR_INIT
#include "Can_MemMap.h"
#endif

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32, CAN_CODE) Can_LLD_GetRamWord ( P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr );
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) Can_LLD_GetWordsOfRxfifo \
( \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

extern VAR(uint16, CAN_VAR) g_u16Can_CurBaudRateId[CAN_CONTROLLER_COUNT];

extern VAR(Controller_mapping, AUTOMATIC) s_sInsToCtrlMap[MCAN_MOD_BUTT];

extern VAR(uint32, CAN_VAR) s_txHardwareMbIsSelected[CAN_CONTROLLER_COUNT];

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_GetAddressParameter \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(status_t, CAN_CODE) Can_LLD_NecessarySpace \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_TxWriteMsgToBuffer \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buff_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_RxCopyMsgFromRamToList \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Msg_addr_in_msg_ram, \
    VAR(rx_info_struct, AUTOMATIC) sCan_Rx_info \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_RxRecDedicatedMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Ded_buffer_index \
);
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_RxNotifying \
( VAR(can_msg_struct, AUTOMATIC) msg_ptr, \
    VAR(MCANModId, AUTOMATIC) eCan_Instance , \
    VAR(rx_info_struct, AUTOMATIC) sCan_Rx_info ,\
	VAR(uint8, AUTOMATIC)  u8Can_HwFilterIdex );
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_DMU_InterruptInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base, \
    P2CONST(mcan_dmu_intr_config_t, CAN_CONST, CAN_APPL_CONST) config \
)
{
    uint32_t ir_enable;

    ir_enable = config->mcan_dmu_intr_enable;/* polyspace RTE:NIV *//* polyspace RTE:IDP */
    base->DMUIE.R = ir_enable;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) MCAN_DMU_InitIntrHandler \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) config \
)
{
	(void)instance;
	if(config->mcandmucallback != NULL)/* polyspace RTE:NIP */
	{
		g_dmu_intr_callback[instance].tx_fifo_dmu_transfered = config->mcandmucallback->tx_fifo_dmu_transfered;/* polyspace RTE:NIP *//* polyspace RTE:IDP */
		g_dmu_intr_callback[instance].rx_fifo_0_dmu_received = config->mcandmucallback->rx_fifo_0_dmu_received;/* polyspace RTE:NIP */
		g_dmu_intr_callback[instance].rx_fifo_1_dmu_received = config->mcandmucallback->rx_fifo_1_dmu_received;/* polyspace RTE:NIP */
		g_dmu_intr_callback[instance].tx_event_dmu_handler   = config->mcandmucallback->tx_event_dmu_handler;/* polyspace RTE:NIP */
	}
	else
	{
		g_dmu_intr_callback[instance].tx_fifo_dmu_transfered = NULL;
		g_dmu_intr_callback[instance].rx_fifo_0_dmu_received = NULL;
		g_dmu_intr_callback[instance].rx_fifo_1_dmu_received = NULL;
		g_dmu_intr_callback[instance].tx_event_dmu_handler   = NULL;
	}
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
#endif /* RESOURCE_SUPPORT_MCAN_DMU */
#if defined(RESOURCE_SUPPORT_MCAN_TSU)
CAN_INLINE FUNC(void, CAN_CODE) MCAN_TSU_Enable(P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base, P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) config)
{
    base->CCCR.B.UTSU = 1U;
    base->TSCFG.B.TSUE = 1U;
    base->TSCC.B.TCP = config->tcp;/* polyspace RTE:NIV */
    base->TSCC.B.TSS = 0x1U;
}
#endif /* RESOURCE_SUPPORT_MCAN_DMU */

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(status_t,CAN_CODE)MCAN_MsgRamPartitioningCheck \
( \
    P2CONST(MCANPartitionConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Data \
)
{
    VAR(uint32, AUTOMATIC) u32Can_Index;
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
    VAR(uint32, AUTOMATIC) Ram = 0U;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
    VAR(uint32, AUTOMATIC) Ram1 = 0U;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
    VAR(uint32, AUTOMATIC) Ram2 = 0U;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    VAR(status_t, AUTOMATIC) eCan_StatusRet = STATUS_ERROR;

    for(u32Can_Index = 0U; u32Can_Index < MCAN_INSTANCE_COUNT; u32Can_Index++)
    {
        if(pCan_Data->McanCtrl[u32Can_Index].IsUsed == TRUE)/* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */
        {
            if(pCan_Data->McanCtrl[u32Can_Index].CanId <= MCAN_MOD_ID_4)/* polyspace RTE:NIV */
            {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
                Ram += pCan_Data->McanCtrl[u32Can_Index].mram_size_words;/* polyspace RTE:NIV */
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
            }
            else if(pCan_Data->McanCtrl[u32Can_Index].CanId <= MCAN_MOD_ID_8)
            {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
                Ram1 += pCan_Data->McanCtrl[u32Can_Index].mram_size_words;/* polyspace RTE:NIV */
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
            }
            else
            {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
                Ram2 += pCan_Data->McanCtrl[u32Can_Index].mram_size_words;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
            }
        }
    }
    if(
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
    (Ram > FEATURE_MCAN_RAM_WRD_SIZE) ||
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
    (Ram1 > FEATURE_MCAN_RAM1_WRD_SIZE)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
    || (Ram2 > FEATURE_MCAN_RAM2_WRD_SIZE)
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    )
    {
        eCan_StatusRet = STATUS_ERROR;
    }
    else
    {
        eCan_StatusRet = STATUS_SUCCESS;
    }
    return eCan_StatusRet;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE)MCAN_ClearAllReceivedFlags \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    pCan_Base->NDAT1.R = 0xFFFFFFFFU; /* polyspace RTE:IDP */
    pCan_Base->NDAT2.R = 0xFFFFFFFFU;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    VAR(uint32, AUTOMATIC) u32TotalElapsedTime = 0U;
#ifdef CAN_TIMEOUT_USE_OS
    static VAR(TickType, AUTOMATIC) CurrentValue[CAN_CORE_NUM] = {0U};
    static VAR(TickType, AUTOMATIC) ElapsedValue[CAN_CORE_NUM] = {0U};
#endif
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;
    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/

    if(((pCan_Base->CCCR.R & MCAN_CCCR_INIT_MASK) >> MCAN_CCCR_INIT_SHIFT) == 0U)/* polyspace RTE:NIV,IDP */
    {
        pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_INIT_MASK) | MCAN_CCCR_INIT(1U);
        /*
            [SWS_Can_00398] The function Can_SetControllerMode shall use the system 
            service GetCounterValue for timeout monitoring to avoid blocking functions.
        */
        #ifdef CAN_TIMEOUT_USE_OS
            (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &CurrentValue[u32Can_CoreId]);
        #endif
        while ((((pCan_Base->CCCR.R & MCAN_CCCR_INIT_MASK) >> MCAN_CCCR_INIT_SHIFT) == 0U) \
               && ((u32TotalElapsedTime < s_u32Can_TimeOut[u32Can_CoreId])))/* polyspace RTE:OBAI */
        {
            #ifdef CAN_TIMEOUT_USE_OS
                (void)GetElapsedValue
                (
                    (CounterType)CAN_TIMEOUT_COUNTER_NAME,
                    &CurrentValue[u32Can_CoreId],
                    &ElapsedValue[u32Can_CoreId]
                );
                u32TotalElapsedTime += (uint32)ElapsedValue[u32Can_CoreId];
            #else
                u32TotalElapsedTime++;
            #endif
        }
        if (u32TotalElapsedTime >= s_u32Can_TimeOut[u32Can_CoreId])/* polyspace RTE:OBAI */
        {
            s_u32Can_IsTimeOut[u32Can_CoreId] = 1U;
        }
        else
        {
            s_u32Can_IsTimeOut[u32Can_CoreId] = 0U;
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(boolean,CAN_CODE) MCAN_isInitState \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;

    if(((pCan_Base->CCCR.R & MCAN_CCCR_INIT_MASK) >> /* polyspace RTE:NIV,IDP */
         MCAN_CCCR_INIT_SHIFT) == 0U)
    {
        bCan_Ret = FALSE;
    }
    else
    {
        bCan_Ret = TRUE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_RsetInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    DEV_ASSERT(pCan_Base != NULL_PTR);

    VAR(uint32, AUTOMATIC) u32TotalElapsedTime = 0U;
#ifdef CAN_TIMEOUT_USE_OS
    static VAR(TickType, AUTOMATIC) CurrentValue[CAN_CORE_NUM] = {0U};
    static VAR(TickType, AUTOMATIC) ElapsedValue[CAN_CORE_NUM] = {0U};
#endif
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
    if(((pCan_Base->CCCR.R & MCAN_CCCR_INIT_MASK) >> MCAN_CCCR_INIT_SHIFT) == 1U)/* polyspace RTE:NIV,IDP */
    {
        pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_INIT_MASK) | MCAN_CCCR_INIT(0U);
        #ifdef CAN_TIMEOUT_USE_OS
            (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &CurrentValue[u32Can_CoreId]);
        #endif
        SchM_Enter_Can_EXCLUSIVE_AREA_06();
        while ((((pCan_Base->CCCR.R & MCAN_CCCR_INIT_MASK) >> MCAN_CCCR_INIT_SHIFT) == 1U) \
                && ((u32TotalElapsedTime < s_u32Can_TimeOut[u32Can_CoreId])))/* polyspace RTE:OBAI */
        {
            #ifdef CAN_TIMEOUT_USE_OS
                (void)GetElapsedValue
                (
                    (CounterType)CAN_TIMEOUT_COUNTER_NAME,
                    &CurrentValue[u32Can_CoreId],
                    &ElapsedValue[u32Can_CoreId]
                );
                u32TotalElapsedTime += (uint32)ElapsedValue[u32Can_CoreId];
            #else
                u32TotalElapsedTime++;
            #endif
        }
        SchM_Exit_Can_EXCLUSIVE_AREA_06();
        if (u32TotalElapsedTime >= s_u32Can_TimeOut[u32Can_CoreId])/* polyspace RTE:OBAI */
        {
            s_u32Can_IsTimeOut[u32Can_CoreId] = 1U;
        }
        else
        {
            s_u32Can_IsTimeOut[u32Can_CoreId] = 0U;
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetConfigChangeEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    VAR(uint32, AUTOMATIC) u32TotalElapsedTime = 0U;
#ifdef CAN_TIMEOUT_USE_OS
    static VAR(TickType, AUTOMATIC) CurrentValue[CAN_CORE_NUM] = {0U};
    static VAR(TickType, AUTOMATIC) ElapsedValue[CAN_CORE_NUM] = {0U};
#endif
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
    MCAN_SetInit(pCan_Base);
    #ifdef CAN_TIMEOUT_USE_OS
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &CurrentValue[u32Can_CoreId]);
    #endif
    pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_CCE_MASK) | MCAN_CCCR_CCE(1U);/* polyspace RTE:NIV */
    SchM_Enter_Can_EXCLUSIVE_AREA_15();
    while (((pCan_Base->CCCR.R & (MCAN_CCCR_INIT_MASK | MCAN_CCCR_CCE_MASK)) \
           != (MCAN_CCCR_INIT_MASK | MCAN_CCCR_CCE_MASK)) && (u32TotalElapsedTime < s_u32Can_TimeOut[u32Can_CoreId]))/* polyspace RTE:OBAI */
    {
        #ifdef CAN_TIMEOUT_USE_OS
            (void)GetElapsedValue
            (
                (CounterType)CAN_TIMEOUT_COUNTER_NAME,
                &CurrentValue[u32Can_CoreId],
                &ElapsedValue[u32Can_CoreId]
            );
            u32TotalElapsedTime += (uint32)ElapsedValue[u32Can_CoreId];
        #else
            u32TotalElapsedTime++;
        #endif
    }
    SchM_Exit_Can_EXCLUSIVE_AREA_15();
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_IsFDEnabled \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return (((pCan_Base->CCCR.R & MCAN_CCCR_FDOE_MASK) == MCAN_CCCR_FDOE_MASK) ? 1U : 0U);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_GetPayloadSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base, \
    VAR(mode_type_t, AUTOMATIC) eCan_Type \
)
{
    VAR(uint32, AUTOMATIC) payloadSize = 8U;
    VAR(uint32, AUTOMATIC) payloadCode = 0U;

    if (eCan_Type == MCAN_TX_BUFF)
    {
        payloadCode = ((pCan_Base->TXESC.R & MCAN_TXESC_TBDS_MASK) >> MCAN_TXESC_TBDS_SHIFT);/* polyspace RTE:NIV,IDP */
    }

    if (eCan_Type == MCAN_RX_BUFF)
    {
        payloadCode = ((pCan_Base->RXESC.R & MCAN_RXESC_RBDS_MASK) >> MCAN_RXESC_RBDS_SHIFT);/* polyspace RTE:NIV,IDP */
    }

    if (eCan_Type == MCAN_RX_FIFO0)
    {
        payloadCode = ((pCan_Base->RXESC.R & MCAN_RXESC_F0DS_MASK) >> MCAN_RXESC_F0DS_SHIFT);/* polyspace RTE:NIV,IDP */
    }

    if (eCan_Type == MCAN_RX_FIFO1)
    {
        payloadCode = ((pCan_Base->RXESC.R & MCAN_RXESC_F1DS_MASK) >> MCAN_RXESC_F1DS_SHIFT);/* polyspace RTE:NIV,IDP */
    }

    switch (payloadCode)
    {
    case (uint32)MCAN_PAYLOAD_SIZE_64:
    {
        payloadSize = 64U;
        break;
    }
    case (uint32)MCAN_PAYLOAD_SIZE_48:
    {
        payloadSize = 48U;
        break;
    }
    case (uint32)MCAN_PAYLOAD_SIZE_32:
    {
        payloadSize = 32U;
        break;
    }
    default:
    {
        payloadSize = ((payloadCode << 2U) + 8U);
        break;
    }
    }
    return (uint8)payloadSize;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint16, CAN_CODE) MCAN_ConvertDataLengthCode \
( \
    VAR(uint8, AUTOMATIC) u8Can_MbDataLength \
)
{
    VAR(uint16, AUTOMATIC) u16Can_LengthCode = (uint16)0U;
    VAR(uint8, AUTOMATIC) u8Can_Tmp = (uint8)0U;
    u8Can_Tmp = (uint8)((u8Can_MbDataLength + (uint8)3) / (uint8)4);
    switch (u8Can_Tmp)
    {
    case 0U:
    case 1U:
    case 2U:
    {
        u16Can_LengthCode = (uint16)u8Can_MbDataLength;
        break;
    }
    case 3U:
    {
        u16Can_LengthCode = ((uint16)9U);
        break;
    }
    case 4U:
    {
        u16Can_LengthCode = ((uint16)10U);
        break;
    }
    case 5U:
    {
        u16Can_LengthCode = ((uint16)11U);
        break;
    }
    case 6U:
    {
        u16Can_LengthCode = ((uint16)12U);
        break;
    }
    case 7U:
    case 8U:
    {
        u16Can_LengthCode = ((uint16)13U);
        break;
    }
    case 9U:
    case 10U:
    case 11U:
    case 12U:
    {
        u16Can_LengthCode = ((uint16)14U);
        break;
    }
    default:
    {
        u16Can_LengthCode = ((uint16)15U);
        break;
    }
    }
    return u16Can_LengthCode;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_ConvertDLCToDataLength \
( \
    VAR(uint16, AUTOMATIC) u16Can_Dlc \
)
{
    VAR(uint8, AUTOMATIC) u8Can_DlcDatalength = 0U;

    DEV_ASSERT(u16Can_Dlc <= 15U);

    if (u16Can_Dlc <= 8U)
    {
        u8Can_DlcDatalength = (uint8)u16Can_Dlc;
    }
    else
    {
        switch (u16Can_Dlc)
        {
        case 9U:
        {
            u8Can_DlcDatalength = 12U;
            break;
        }
        case 10U:
        {
            u8Can_DlcDatalength = 16U;
            break;
        }
        case 11U:
        {
            u8Can_DlcDatalength = 20U;
            break;
        }
        case 12U:
        {
            u8Can_DlcDatalength = 24U;
            break;
        }
        case 13U:
        {
            u8Can_DlcDatalength = 32U;
            break;
        }
        case 14U:
        {
            u8Can_DlcDatalength = 48U;
            break;
        }
        case 15U:
        {
            u8Can_DlcDatalength = 64U;
            break;
        }
        default:
        {
            u8Can_DlcDatalength = (0U);
            break;
        }
        }
    }

    return u8Can_DlcDatalength;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTestMode \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Enable \
)
{
    pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_TEST_MASK) | MCAN_CCCR_TEST(u8Can_Enable);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetLoopBackMode \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Enable \
)
{
    pCan_Base->TEST.R = (pCan_Base->TEST.R & ~MCAN_TEST_LBCK_MASK) | MCAN_TEST_LBCK(u8Can_Enable);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_EnableBusMonitorMode \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Enable \
)
{
    pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_MON_MASK) | MCAN_CCCR_MON(u8Can_Enable);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_EnableTestMode \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(loopback_mode, AUTOMATIC) eCan_Type \
)
{
    if ((pCan_Base->CCCR.R & MCAN_CCCR_TEST_MASK) != MCAN_CCCR_TEST_MASK)/* polyspace RTE:NIV */
    {
        MCAN_SetTestMode(pCan_Base, TRUE);
    }

    if (eCan_Type == MCAN_LOOPBACK_INTERNAL)
    {
        MCAN_SetLoopBackMode(pCan_Base, TRUE);
        MCAN_EnableBusMonitorMode(pCan_Base, TRUE);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetNominalTimeSegments \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(bt_config_struct, AUTOMATIC, CAN_APPL_CONST) pCan_TimeSeg \
)
{
    (pCan_Base->NBTP.R) = ((pCan_Base->NBTP.R) & ~(MCAN_NBTP_NTSEG2_MASK /* polyspace RTE:NIV */
            | MCAN_NBTP_NTSEG1_MASK | MCAN_NBTP_NBRP_MASK | MCAN_NBTP_NSJW_MASK));

    (pCan_Base->NBTP.R) = ((pCan_Base->NBTP.R) \
                                   | (MCAN_NBTP_NTSEG1(((uint32)pCan_TimeSeg->phase_seg1 /* polyspace RTE:NIV */
                                           + (uint32)pCan_TimeSeg->prop_seg) - 1U) /* polyspace RTE:NIV */
                                   | MCAN_NBTP_NTSEG2((uint32)pCan_TimeSeg->phase_seg2 - 1U) /* polyspace RTE:NIV */
                                   | MCAN_NBTP_NBRP((uint32)pCan_TimeSeg->brp - 1U) /* polyspace RTE:NIV */
                                   | MCAN_NBTP_NSJW((uint32)pCan_TimeSeg->sjw - 1U))); /* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetNonIsoOperation \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(boolean, AUTOMATIC) bCan_Format \
)
{
    pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_NISO_MASK) | MCAN_CCCR_NISO(BOOLTOUINT(bCan_Format));/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetDataTimeSegments \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(bt_config_struct, AUTOMATIC, CAN_APPL_CONST) pCan_TimeSeg \
)
{
    (pCan_Base->DBTP.R) = ((pCan_Base->DBTP.R) & ~(MCAN_DBTP_DTSEG2_MASK | MCAN_DBTP_DTSEG1_MASK /* polyspace RTE:NIV */
                                | MCAN_DBTP_DBRP_MASK | MCAN_DBTP_DSJW_MASK | MCAN_DBTP_TDC_MASK));

    (pCan_Base->DBTP.R) = ((pCan_Base->DBTP.R) \
                                   | (MCAN_DBTP_DTSEG1(((uint32)pCan_TimeSeg->phase_seg1 /* polyspace RTE:NIV */
                                           + (uint32)pCan_TimeSeg->prop_seg) - 1U) /* polyspace RTE:NIV */
                                   | MCAN_DBTP_DTSEG2((uint32)pCan_TimeSeg->phase_seg2 - 1U) /* polyspace RTE:NIV */
                                   | MCAN_DBTP_DBRP((uint32)pCan_TimeSeg->brp - 1U) /* polyspace RTE:NIV */
                                   | MCAN_DBTP_DSJW((uint32)pCan_TimeSeg->sjw - 1U) /* polyspace RTE:NIV */
                                   | MCAN_DBTP_TDC(BOOLTOUINT(pCan_TimeSeg->tdc)))); /* polyspace RTE:NIV */

    (pCan_Base->TDCR.R) = ((pCan_Base->TDCR.R) & ~MCAN_TDCR_TDCO_MASK) /* polyspace RTE:NIV */
                                   | MCAN_TDCR_TDCO(pCan_TimeSeg->tdc_offset); /* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetFDDataEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(boolean, AUTOMATIC) bCan_Enable \
)
{

    pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_FDOE_MASK) | MCAN_CCCR_FDOE(BOOLTOUINT(bCan_Enable));/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetBitRateSwitch \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(boolean, AUTOMATIC) bCan_Enable \
)
{
    pCan_Base->CCCR.R = (pCan_Base->CCCR.R & ~MCAN_CCCR_BRSE_MASK) | MCAN_CCCR_BRSE(BOOLTOUINT(bCan_Enable));/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetBitTiming \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(bt_config_canfd_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    MCAN_SetNominalTimeSegments(pCan_Base, &pCan_Config->nominal);

    if(pCan_Config->fd_ena != 0U)/* polyspace RTE:NIV */
    {
        MCAN_SetDataTimeSegments(pCan_Base, &pCan_Config->data);
        MCAN_SetFDDataEnable(pCan_Base, TRUE);
    }
    else
    {
        MCAN_SetFDDataEnable(pCan_Base, FALSE);
    }

    if(pCan_Config->brs_ena != 0U)/* polyspace RTE:NIV */
    {
        MCAN_SetBitRateSwitch(pCan_Base, TRUE);
    }
    else
    {
        MCAN_SetBitRateSwitch(pCan_Base, FALSE);
    }

    if(pCan_Config->is_noiso != 0U)/* polyspace RTE:NIV */
    {
        MCAN_SetNonIsoOperation(pCan_Base, TRUE);
    }
    else
    {
        MCAN_SetNonIsoOperation(pCan_Base, FALSE);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetRejectRemoteStdFrame \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(boolean, AUTOMATIC) bCan_Enable \
)
{
    pCan_Base->GFC.R = (pCan_Base->GFC.R & ~MCAN_GFC_RRFS_MASK) | MCAN_GFC_RRFS(BOOLTOUINT(bCan_Enable));/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetRejectRemoteExtFrame \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(boolean, AUTOMATIC) bCan_Enable \
)
{
    pCan_Base->GFC.R = (pCan_Base->GFC.R & ~MCAN_GFC_RRFE_MASK) | MCAN_GFC_RRFE(BOOLTOUINT(bCan_Enable));/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetAcceptNonMatchStdFrame \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(GFC_accept_non_matching_frames_enum, AUTOMATIC) eCan_Value \
)
{
    pCan_Base->GFC.R = (pCan_Base->GFC.R & ~MCAN_GFC_ANFS_MASK) | MCAN_GFC_ANFS(eCan_Value);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetAcceptNonMatchExtFrame \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(GFC_accept_non_matching_frames_enum, AUTOMATIC) eCan_Value \
)
{
    pCan_Base->GFC.R = (pCan_Base->GFC.R & ~MCAN_GFC_ANFE_MASK) | MCAN_GFC_ANFE(eCan_Value);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_GlobalFilterConfig \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_global_filter_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    if(pCan_Config != NULL_PTR)
    {
	    MCAN_SetAcceptNonMatchStdFrame(pCan_Base, pCan_Config->anfs);/* polyspace RTE:NIV *//* polyspace RTE:IDP */
	    MCAN_SetAcceptNonMatchExtFrame(pCan_Base, pCan_Config->anfe);/* polyspace RTE:NIV */

	    if(pCan_Config->rrfs == TRUE)/* polyspace RTE:NIV */
	    {
	        MCAN_SetRejectRemoteStdFrame(pCan_Base, TRUE);
	    }
	    else if(pCan_Config->rrfs == FALSE)
	    {
	        MCAN_SetRejectRemoteStdFrame(pCan_Base, FALSE);
	    }
	    else
	    {
	        /* do nothing */
	    }

        if(pCan_Config->rrfe == TRUE)/* polyspace RTE:NIV */
        {
            MCAN_SetRejectRemoteExtFrame(pCan_Base, TRUE);
        }
        else if(pCan_Config->rrfe == FALSE)
        {
            MCAN_SetRejectRemoteExtFrame(pCan_Base, FALSE);
        }
        else
        {
            /* do nothing */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetStdIDFilterAddress \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Address \
)
{
    pCan_Base->SIDFC.R = (pCan_Base->SIDFC.R & ~MCAN_SIDFC_FLSSA_MASK) /* polyspace RTE:NIV,IDP */
                          | (u32Can_Address & MCAN_SIDFC_FLSSA_MASK);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetStdIDFilterSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    pCan_Base->SIDFC.R = (pCan_Base->SIDFC.R & ~MCAN_SIDFC_LSS_MASK) | MCAN_SIDFC_LSS(u8Can_Size);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_GetStdIDFilterSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return (uint8)((pCan_Base->SIDFC.R & MCAN_SIDFC_LSS_MASK) >> MCAN_SIDFC_LSS_SHIFT);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetFilterSTDSpace \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    VAR(uint32, AUTOMATIC) value = 0U;
    VAR(uint32, AUTOMATIC) size;

    size = MCAN_GetStdIDFilterSize(pCan_Base);
    value = (pCan_Base->SIDFC.R & MCAN_SIDFC_FLSSA_MASK) + (size << 2U);/* polyspace RTE:NIV */

    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetSTD_IdFilter \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(mcan_id_table_t, AUTOMATIC, CAN_APPL_CONST) PCan_IdFilter, \
    VAR(uint8, AUTOMATIC) u8Can_Fl_idx \
)
{
    DEV_ASSERT(PCan_IdFilter != NULL_PTR);

    VAR(uint32, AUTOMATIC) filterAddress;
    VAR(uint32, AUTOMATIC) u32Can_Start_Adr = 0U;
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    uint32_t temp_ram_word;
#endif

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base = g_mcanBase[eCan_Instance];

    if(eCan_Instance <= MCAN_MOD_ID_4)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
    }
    else if(eCan_Instance <= MCAN_MOD_ID_8)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM1_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
    }
    else
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM2_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    }

    filterAddress = (pCan_Base->SIDFC.R & MCAN_SIDFC_FLSSA_MASK) + ((uint32)u8Can_Fl_idx << 2U);/* polyspace RTE:NIV,IDP */
    filterAddress = u32Can_Start_Adr + filterAddress;

    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) stdFlElem = (uint32 *)filterAddress;

    *stdFlElem = (uint32)PCan_IdFilter->filterType << MCAN_STD_FILTER_ID_SFT_SHIFT;/* polyspace RTE:IDP *//* polyspace RTE:NIV */
    *stdFlElem |= MCAN_STD_FILTER_ID_SFEC_MASK \
               & ((uint32)PCan_IdFilter->filterConfig << MCAN_STD_FILTER_ID_SFEC_SHIFT);/* polyspace RTE:NIV */
    *stdFlElem |= MCAN_STD_FILTER_ID_SSYNC_MASK \
               & ((uint32)PCan_IdFilter->ssync << MCAN_STD_FILTER_ID_SSYNC_SHIFT);/* polyspace RTE:NIV */
    *stdFlElem |= MCAN_STD_FILTER_ID_SFID1_MASK \
               & (PCan_IdFilter->id1 << MCAN_STD_FILTER_ID_SFID1_SHIFT);/* polyspace RTE:NIV */
    *stdFlElem |= MCAN_STD_FILTER_ID_SFID2_MASK & (PCan_IdFilter->id2);/* polyspace RTE:NIV */
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = *stdFlElem;
    *stdFlElem = (uint32_t)((temp_ram_word & 0x000000FFU) << 24U) | ((temp_ram_word & 0x0000FF00U) << 8U) |\
                            ((temp_ram_word & 0x00FF0000U) >> 8U) | ((temp_ram_word & 0xFF000000U) >> 24U);
#endif
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetExtIDFilterAddress \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Address \
)
{
    pCan_Base->XIDFC.R = (pCan_Base->XIDFC.R & ~MCAN_XIDFC_FLESA_MASK) /* polyspace RTE:NIV */
            | (u32Can_Address & MCAN_XIDFC_FLESA_MASK);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetExtIDFilterSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    pCan_Base->XIDFC.R = (pCan_Base->XIDFC.R & ~MCAN_XIDFC_LSE_MASK) | MCAN_XIDFC_LSE(u8Can_Size);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_GetExtIDFilterSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return (uint8)((pCan_Base->XIDFC.R & MCAN_XIDFC_LSE_MASK) >> MCAN_XIDFC_LSE_SHIFT);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetFilterEXTSpace \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    VAR(uint32, AUTOMATIC) value = 0U;
    VAR(uint32, AUTOMATIC) size;

    size = MCAN_GetExtIDFilterSize(pCan_Base);
    value = (pCan_Base->XIDFC.R & MCAN_XIDFC_FLESA_MASK) + (size << 3U);/* polyspace RTE:NIV */

    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetEXT_IdFilter \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(mcan_id_table_t, AUTOMATIC, CAN_APPL_CONST) PCan_IdFilter, \
    VAR(uint8, AUTOMATIC) u8Can_Fl_idx \
)
{
    DEV_ASSERT(PCan_IdFilter != NULL_PTR);

    VAR(uint32, AUTOMATIC) filterAddress;
    VAR(uint32, AUTOMATIC) u32Can_Start_Adr = 0U;
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    uint32_t temp_ram_word;
#endif

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base = g_mcanBase[eCan_Instance];

    if(eCan_Instance <= MCAN_MOD_ID_4)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
    }
    else if(eCan_Instance <= MCAN_MOD_ID_8)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM1_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
    }
    else
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM2_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    }

    filterAddress = (pCan_Base->XIDFC.R & MCAN_XIDFC_FLESA_MASK) + ((uint32)u8Can_Fl_idx << 3U);/* polyspace RTE:NIV,IDP */
    filterAddress = u32Can_Start_Adr + filterAddress;

    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) extFlElem0 = (uint32 *)filterAddress;

    filterAddress = filterAddress + 4U;

    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) extFlElem1 = (uint32 *)filterAddress;

    *extFlElem0 =  ((uint32)PCan_IdFilter->filterConfig << MCAN_EXT_FILTER_ID_EFEC_SHIFT);/* polyspace RTE:IDP *//* polyspace RTE:NIV */
    *extFlElem0 |= MCAN_EXT_FILTER_ID_EFID1_MASK & PCan_IdFilter->id1;/* polyspace RTE:NIV */
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = *extFlElem0;
    *extFlElem0 = (uint32_t)((temp_ram_word & 0x000000FFU) << 24U) | ((temp_ram_word & 0x0000FF00U) << 8U) |\
                            ((temp_ram_word & 0x00FF0000U) >> 8U) | ((temp_ram_word & 0xFF000000U) >> 24U);
#endif
    *extFlElem1 =  ((uint32)PCan_IdFilter->filterType << MCAN_EXT_FILTER_ID_EFT_SHIFT);/* polyspace RTE:IDP *//* polyspace RTE:NIV */
    *extFlElem1 |= MCAN_EXT_FILTER_ID_ESYNC_MASK \
                & ((uint32)PCan_IdFilter->esync << MCAN_EXT_FILTER_ID_ESYNC_SHIFT);/* polyspace RTE:NIV */
    *extFlElem1 |= MCAN_EXT_FILTER_ID_EFID2_MASK & PCan_IdFilter->id2;/* polyspace RTE:NIV */
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = *extFlElem1;
    *extFlElem1 = (uint32_t)((temp_ram_word & 0x000000FFU) << 24U) | ((temp_ram_word & 0x0000FF00U) << 8U) |\
                            ((temp_ram_word & 0x00FF0000U) >> 8U) | ((temp_ram_word & 0xFF000000U) >> 24U);
#endif
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_RxFilterInit \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(mcan_filter_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) pCan_Address \
)
{
    VAR(uint8, AUTOMATIC) idx;
    VAR(uint8, AUTOMATIC) ext_idx = 0U;
    VAR(uint8, AUTOMATIC) std_idx = 0U;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base = g_mcanBase[eCan_Instance];
    if(pCan_Config != NULL_PTR)
    {
        MCAN_SetStdIDFilterAddress(pCan_Base, *pCan_Address);
        MCAN_SetStdIDFilterSize(pCan_Base, pCan_Config->std_filters);/* polyspace RTE:NIV *//* polyspace RTE:IDP */
        *pCan_Address = MCAN_GetFilterSTDSpace(pCan_Base);
        MCAN_SetExtIDFilterAddress(pCan_Base, *pCan_Address);
        MCAN_SetExtIDFilterSize(pCan_Base, pCan_Config->ext_filters);/* polyspace RTE:NIV */
        *pCan_Address = MCAN_GetFilterEXTSpace(pCan_Base);

        for(idx = 0U; idx < (pCan_Config->std_filters + pCan_Config->ext_filters); idx++)
        {
            if(pCan_Config->filterconfigs[idx].isExtendedFrame == TRUE)/* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */
            {
                MCAN_SetEXT_IdFilter(eCan_Instance,&pCan_Config->filterconfigs[idx], ext_idx);
                ext_idx++;
            }
            else
            {
                MCAN_SetSTD_IdFilter(eCan_Instance, &pCan_Config->filterconfigs[idx], std_idx);
                std_idx++;
            }
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_FIFOSetSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    if (u8Can_FifoIdx == 0U)
    {
        pCan_Base->RXF0C.R = (pCan_Base->RXF0C.R & ~MCAN_RXF0C_F0S_MASK) /* polyspace RTE:NIV */
                | MCAN_RXF0C_F0S(u8Can_Size);
    }
    else
    {
        pCan_Base->RXF1C.R = (pCan_Base->RXF1C.R & ~MCAN_RXF1C_F1S_MASK) /* polyspace RTE:NIV */
                | MCAN_RXF1C_F1S(u8Can_Size);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_FIFOSetStartAddress \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx, \
    VAR(uint32, AUTOMATIC) u32Can_Address \
)
{
    if (u8Can_FifoIdx == 0U)
    {
        pCan_Base->RXF0C.R = (pCan_Base->RXF0C.R & ~MCAN_RXF0C_F0SA_MASK) /* polyspace RTE:NIV */
                | (u32Can_Address&MCAN_RXF0C_F0SA_MASK);
    }
    else
    {
        pCan_Base->RXF1C.R = (pCan_Base->RXF1C.R & ~MCAN_RXF1C_F1SA_MASK) /* polyspace RTE:NIV */
                | (u32Can_Address&MCAN_RXF1C_F1SA_MASK);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_FIFOSetOpMode \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx, \
    VAR(fifo_op_mode_t, AUTOMATIC) eCan_Mode \
)
{
    if (u8Can_FifoIdx == 0U)
    {
        pCan_Base->RXF0C.R = (pCan_Base->RXF0C.R & ~MCAN_RXF0C_F0OM_MASK) /* polyspace RTE:NIV */
                | MCAN_RXF0C_F0OM(eCan_Mode);
    }
    else
    {
        pCan_Base->RXF1C.R = (pCan_Base->RXF1C.R & ~MCAN_RXF1C_F1OM_MASK) /* polyspace RTE:NIV */
                | MCAN_RXF1C_F1OM(eCan_Mode);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_FIFOSetWaterMark \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx, \
    VAR(uint8, AUTOMATIC) u8Can_Level \
)
{
    if (u8Can_FifoIdx == 0U)
    {
        pCan_Base->RXF0C.R = (pCan_Base->RXF0C.R & ~MCAN_RXF0C_F0WM_MASK) /* polyspace RTE:NIV */
                | MCAN_RXF0C_F0WM(u8Can_Level);
    }
    else
    {
        pCan_Base->RXF1C.R = (pCan_Base->RXF1C.R & ~MCAN_RXF1C_F1WM_MASK) /* polyspace RTE:NIV */
                | MCAN_RXF1C_F1WM(u8Can_Level);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_FIFOSetPayloadSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx, \
    VAR(mcan_fd_payload_size_t, AUTOMATIC) eCan_Size \
)
{
    if (u8Can_FifoIdx == 0U)
    {
        pCan_Base->RXESC.R = (pCan_Base->RXESC.R & ~MCAN_RXESC_F0DS_MASK) /* polyspace RTE:NIV */
                | MCAN_RXESC_F0DS(eCan_Size);
    }
    else
    {
        pCan_Base->RXESC.R = (pCan_Base->RXESC.R & ~MCAN_RXESC_F1DS_MASK) /* polyspace RTE:NIV */
                | MCAN_RXESC_F1DS(eCan_Size);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_FIFOGetSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx \
)
{
    VAR(uint8, AUTOMATIC) value = 0U;

    if (u8Can_FifoIdx == 0U)
    {
        value = ((uint8)((pCan_Base->RXF0C.R & MCAN_RXF0C_F0S_MASK) >> MCAN_RXF0C_F0S_SHIFT));/* polyspace RTE:NIV */
    }
    else
    {
        value = ((uint8)((pCan_Base->RXF1C.R & MCAN_RXF1C_F1S_MASK) >> MCAN_RXF1C_F1S_SHIFT));/* polyspace RTE:NIV */
    }

    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetRxFIFOSpace \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_FifoIdx \
)
{
    VAR(uint32, AUTOMATIC) value = 0U;
    VAR(uint32, AUTOMATIC) arbitration_field_size = 8U;
    VAR(uint32, AUTOMATIC) size =  MCAN_FIFOGetSize(pCan_Base, u8Can_FifoIdx);

    if (u8Can_FifoIdx == 0U)
    {
        VAR(uint32, AUTOMATIC) paysize = MCAN_GetPayloadSize(pCan_Base, MCAN_RX_FIFO0);
        value = (pCan_Base->RXF0C.R & MCAN_RXF0C_F0SA_MASK) /* polyspace RTE:NIV */
                 + (size *(paysize+arbitration_field_size));
    }
    else if (u8Can_FifoIdx == 1U)
    {
        VAR(uint32, AUTOMATIC) paysize = MCAN_GetPayloadSize(pCan_Base, MCAN_RX_FIFO1);
        value = (pCan_Base->RXF1C.R & MCAN_RXF1C_F1SA_MASK) /* polyspace RTE:NIV */
                 + (size *(paysize+arbitration_field_size));
    }
    else
    {
        /* do nothing */
    }
    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_RxFifoInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_fifo_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) pCan_Address \
)
{
    if(pCan_Config != NULL_PTR)
    {
        MCAN_FIFOSetSize(pCan_Base, 0U, 0U);
        MCAN_FIFOSetStartAddress(pCan_Base, 0U, 0U);
        MCAN_FIFOSetSize(pCan_Base, 1U, 0U);
        MCAN_FIFOSetStartAddress(pCan_Base, 1U, 0U);

    if ((pCan_Config->rx_fifo_needed == MCAN_RXFIFO_0_ENABLE) /* polyspace RTE:NIV *//* polyspace RTE:IDP */
            || (pCan_Config->rx_fifo_needed == MCAN_RXFIFO_0_1_ENABLE))
        {
        MCAN_FIFOSetOpMode(pCan_Base, 0U, pCan_Config->modeFIFO);/* polyspace RTE:NIV */
        MCAN_FIFOSetWaterMark(pCan_Base, 0U, pCan_Config->fifo_watermark);/* polyspace RTE:NIV */
        MCAN_FIFOSetSize(pCan_Base, 0U, pCan_Config->fifo_size_elems);/* polyspace RTE:NIV */
        MCAN_FIFOSetPayloadSize(pCan_Base, 0U, pCan_Config->payload);/* polyspace RTE:NIV */
            MCAN_FIFOSetStartAddress(pCan_Base, 0U, *pCan_Address);
            *pCan_Address = MCAN_GetRxFIFOSpace(pCan_Base, 0U);
        }
        if ((pCan_Config->rx_fifo_needed == MCAN_RXFIFO_1_ENABLE) \
            || (pCan_Config->rx_fifo_needed == MCAN_RXFIFO_0_1_ENABLE))
        {
        MCAN_FIFOSetOpMode(pCan_Base, 1U, pCan_Config->modeFIFO);/* polyspace RTE:NIV */
        MCAN_FIFOSetWaterMark(pCan_Base, 1U, pCan_Config->fifo_watermark);/* polyspace RTE:NIV */
        MCAN_FIFOSetSize(pCan_Base, 1U, pCan_Config->fifo_size_elems);/* polyspace RTE:NIV */
        MCAN_FIFOSetPayloadSize(pCan_Base, 1U, pCan_Config->payload);/* polyspace RTE:NIV */
            MCAN_FIFOSetStartAddress(pCan_Base, 1U, *pCan_Address);
            *pCan_Address = MCAN_GetRxFIFOSpace(pCan_Base, 1U);
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetRxBuffAddress \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Address \
)
{
    pCan_Base->RXBC.R = (pCan_Base->RXBC.R & ~MCAN_RXBC_RBSA_MASK) /* polyspace RTE:NIV */
            | (u32Can_Address & MCAN_RXBC_RBSA_MASK);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetRxElementdSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(mcan_fd_payload_size_t, AUTOMATIC) eCan_Size \
)
{
    pCan_Base->RXESC.R = (pCan_Base->RXESC.R & ~MCAN_RXESC_RBDS_MASK) /* polyspace RTE:NIV */
            | MCAN_RXESC_RBDS((uint32)eCan_Size);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetRxMBSpace \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Rx_buffer_size_elems \
)
{
    VAR(uint32, AUTOMATIC) value = 0U;
    VAR(uint32, AUTOMATIC) size = u8Can_Rx_buffer_size_elems;
    VAR(uint32, AUTOMATIC) arbitration_field_size = 8U;
    VAR(uint32, AUTOMATIC) paysize = MCAN_GetPayloadSize(pCan_Base, MCAN_RX_BUFF);

    value = (pCan_Base->RXBC.R & MCAN_RXBC_RBSA_MASK) + (size *(paysize+arbitration_field_size));/* polyspace RTE:NIV */

    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_RxDedicatedBuffersInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_dedicated_buffers_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) pCan_Address \
)
{
    if(pCan_Config != NULL_PTR)
    {
        MCAN_SetRxBuffAddress(pCan_Base, *pCan_Address);
        MCAN_SetRxElementdSize(pCan_Base, pCan_Config->payload);/* polyspace RTE:NIV *//* polyspace RTE:IDP */

        *pCan_Address = MCAN_GetRxMBSpace(pCan_Base, pCan_Config->rx_buffer_size_elems);/* polyspace RTE:NIV */
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTxEventFifoSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    pCan_Base->TXEFC.R = (pCan_Base->TXEFC.R & ~MCAN_TXEFC_EFS_MASK) | MCAN_TXEFC_EFS(u8Can_Size);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTxEventWaterMark \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    pCan_Base->TXEFC.R = (pCan_Base->TXEFC.R & ~MCAN_TXEFC_EFWM_MASK) /* polyspace RTE:NIV */
                          | MCAN_TXEFC_EFWM(u8Can_Size);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTxEventFifoAddress \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Address \
)
{
    pCan_Base->TXEFC.R = (pCan_Base->TXEFC.R & ~MCAN_TXEFC_EFSA_MASK) /* polyspace RTE:NIV */
                          | (u32Can_Address & MCAN_TXEFC_EFSA_MASK);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_GetTxEventFifoSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return (uint8)((pCan_Base->TXEFC.R & MCAN_TXEFC_EFS_MASK) >> MCAN_TXEFC_EFS_SHIFT);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetTxEventFifoSpace \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    VAR(uint32, AUTOMATIC) value = 0U;
    VAR(uint32, AUTOMATIC) size = MCAN_GetTxEventFifoSize(pCan_Base);
    VAR(uint32, AUTOMATIC) arbitration_field_size = 8U;

    value = (pCan_Base->TXEFC.R & MCAN_TXEFC_EFSA_MASK) + (size*(arbitration_field_size));/* polyspace RTE:NIV */

    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_TxEventFifoInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_tx_event_fifo_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) pCan_Address \
)
{
    if(pCan_Config != NULL_PTR)
    {
        MCAN_SetTxEventFifoAddress(pCan_Base, *pCan_Address);
        MCAN_SetTxEventWaterMark(pCan_Base, pCan_Config->fifo_watermark);/* polyspace RTE:NIV *//* polyspace RTE:IDP */
		MCAN_SetTxEventFifoSize(pCan_Base, pCan_Config->fifo_size_elems);/* polyspace RTE:NIV */
        *pCan_Address = MCAN_GetTxEventFifoSpace(pCan_Base);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTxBuffAddress \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Address \
)
{
    pCan_Base->TXBC.R = (pCan_Base->TXBC.R & ~MCAN_TXBC_TBSA_MASK) | (u32Can_Address & MCAN_TXBC_TBSA_MASK);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTxBuffSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    pCan_Base->TXBC.R = (pCan_Base->TXBC.R & ~MCAN_TXBC_NDTB_MASK) | MCAN_TXBC_NDTB(u8Can_Size);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetTxFifoQueueSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint8, AUTOMATIC) u8Can_Size \
)
{
    pCan_Base->TXBC.R = (pCan_Base->TXBC.R & ~MCAN_TXBC_TFQS_MASK) | MCAN_TXBC_TFQS(u8Can_Size);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE)  MCAN_SetTxElementdSize \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(mcan_fd_payload_size_t, AUTOMATIC) eCan_Size \
)
{
    pCan_Base->TXESC.R = (pCan_Base->TXESC.R & ~MCAN_TXESC_TBDS_MASK) /* polyspace RTE:NIV */
            | MCAN_TXESC_TBDS((uint32)eCan_Size);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE)  MCAN_SetTxFifoEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(boolean, AUTOMATIC) bCan_Enable \
)
{
    pCan_Base->TXBC.R = (pCan_Base->TXBC.R & ~MCAN_TXBC_TFQM_MASK) | MCAN_TXBC_TFQM(BOOLTOUINT(bCan_Enable));/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_GetTxBuffSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return (uint8)((pCan_Base->TXBC.R & MCAN_TXBC_NDTB_MASK) >> MCAN_TXBC_NDTB_SHIFT);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint8,CAN_CODE) MCAN_GetTxFifoSize \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return (uint8)((pCan_Base->TXBC.R & MCAN_TXBC_TFQS_MASK) >> MCAN_TXBC_TFQS_SHIFT);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetTxMBSpace \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    VAR(uint32, AUTOMATIC) value = 0U;
    VAR(uint32, AUTOMATIC) size = (uint32)MCAN_GetTxBuffSize(pCan_Base) \
            + (uint32)MCAN_GetTxFifoSize(pCan_Base);
    VAR(uint32, AUTOMATIC) arbitration_field_size = 8U;
    VAR(uint32, AUTOMATIC) paysize = MCAN_GetPayloadSize(pCan_Base, MCAN_TX_BUFF);

    value = (pCan_Base->TXBC.R & MCAN_TXBC_TBSA_MASK) + (size *(paysize+arbitration_field_size));/* polyspace RTE:NIV */

    return value;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_TxBufferInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_tx_buffer_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2VAR(uint32, AUTOMATIC,CAN_APPL_DATA) pCan_Address \
)
{
    if(pCan_Config != NULL_PTR)
    {
        MCAN_SetTxBuffAddress(pCan_Base, *pCan_Address);
        MCAN_SetTxBuffSize(pCan_Base, pCan_Config->ded_buffers_number);/* polyspace RTE:NIV *//* polyspace RTE:IDP */
	    MCAN_SetTxFifoQueueSize(pCan_Base, pCan_Config->fifo_queue_size);/* polyspace RTE:NIV */
	    MCAN_SetTxElementdSize(pCan_Base, pCan_Config->payload);/* polyspace RTE:NIV */
	    *pCan_Address = MCAN_GetTxMBSpace(pCan_Base);
	    if(pCan_Config->FIFO_true_QUEUE_false  != 0U)/* polyspace RTE:NIV */
        {
            MCAN_SetTxFifoEnable(pCan_Base, FALSE);
        }
        else
        {
            MCAN_SetTxFifoEnable(pCan_Base, TRUE);
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_ClearNotEnableInterStatus \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    uint32 ire_enabled = (uint32)pCan_Base->IE.R;/* polyspace RTE:NIV,IDP */
    pCan_Base->IR.R = ~ire_enabled;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_InterEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Ir_enable \
)
{
    pCan_Base->IE.R = ((pCan_Base->IE.R & ~INTERRUPT_ALL_SIGNALS) /* polyspace RTE:NIV */
            | (u32Can_Ir_enable & INTERRUPT_ALL_SIGNALS));
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_InterDisableAllSignals \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base \
)
{
    SchM_Enter_Can_EXCLUSIVE_AREA_13();
    pCan_Base->IE.R = (pCan_Base->IE.R & ~INTERRUPT_ALL_SIGNALS);/* polyspace RTE:NIV,IDP */
    SchM_Exit_Can_EXCLUSIVE_AREA_13();
    pCan_Base->TXBTIE.R = 0U;
    pCan_Base->TXBCIE.R = 0U;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_InterLineEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Ile_enable \
)
{
    pCan_Base->ILE.R = ((pCan_Base->ILE.R & ~(MCAN_ILE_EINT0_MASK | MCAN_ILE_EINT1_MASK)) /* polyspace RTE:NIV */
                   | (u32Can_Ile_enable&(MCAN_ILE_EINT0_MASK | MCAN_ILE_EINT1_MASK)));
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_InterLineSelect \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Ir_line_select \
)
{
    pCan_Base->ILS.R = ((pCan_Base->ILS.R & ~INTERRUPT_ALL_SIGNALS) /* polyspace RTE:NIV */
                   | (u32Can_Ir_line_select & INTERRUPT_ALL_SIGNALS));
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_TxBufferTranInterEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Tx_buffer_tran_inter \
)
{
    pCan_Base->TXBTIE.R = ((pCan_Base->TXBTIE.R & ~0xFFFFFFFFU) | u32Can_Tx_buffer_tran_inter);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_TxBufferCancelFinishedInterEnable \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(uint32, AUTOMATIC) u32Can_Tx_buffer_cnacel_inter \
)
{
    pCan_Base->TXBCIE.R = ((pCan_Base->TXBCIE.R & ~0xFFFFFFFFU) | u32Can_Tx_buffer_cnacel_inter);/* polyspace RTE:NIV */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_InterruptInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_inter_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    if(pCan_Config != NULL_PTR)
    {
        DEV_ASSERT((pCan_Config->ir_line0_select & pCan_Config->ir_line1_select) == 0U);
        DEV_ASSERT(((pCan_Config->ir_line0_select + pCan_Config->ir_line1_select) \
                   | INTERRUPT_ALL_SIGNALS) == INTERRUPT_ALL_SIGNALS );

        VAR(uint32, AUTOMATIC) ir_enable;
        VAR(uint32, AUTOMATIC) ir_line_enable;

        ir_enable = pCan_Config->ir_line0_select | pCan_Config->ir_line1_select;/* polyspace RTE:NIV *//* polyspace RTE:IDP */

        MCAN_ClearNotEnableInterStatus(pCan_Base);
        MCAN_InterEnable(pCan_Base, ir_enable);

        ir_line_enable = ILE_DISABLE_INTERRUPT_LINES;

        if(pCan_Config->ir_line0_select != 0U)
        {
            ir_line_enable += ILE_ENABLE_INTERRUPT_LINE_0;
        }
        if(pCan_Config->ir_line1_select != 0U)
        {
            ir_line_enable += ILE_ENABLE_INTERRUPT_LINE_1;
        }

        MCAN_InterLineEnable(pCan_Base, ir_line_enable);

        MCAN_InterLineSelect(pCan_Base, pCan_Config->ir_line1_select);

        MCAN_TxBufferTranInterEnable(pCan_Base, pCan_Config->tx_buffer_tran_ir_enable);/* polyspace RTE:NIV */

        MCAN_TxBufferCancelFinishedInterEnable(pCan_Base, \
                pCan_Config->tx_buffer_cancel_fin_ir_enable);/* polyspace RTE:NIV */
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_SetOperationMode \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    VAR(mcan_operation_modes_t, AUTOMATIC) eCan_Mode \
)
{
    if (eCan_Mode == MCAN_LOOPBACK_MODE)
    {
        MCAN_EnableTestMode(pCan_Base, MCAN_LOOPBACK_INTERNAL);
    }
    else if (eCan_Mode == MCAN_NORMAL_MODE)
    {
        MCAN_SetLoopBackMode(pCan_Base, FALSE);
        MCAN_EnableBusMonitorMode(pCan_Base, FALSE);
    }
    else if (eCan_Mode == MCAN_LISTEN_ONLY_MODE)
    {
        MCAN_SetLoopBackMode(pCan_Base, FALSE);
        MCAN_EnableBusMonitorMode(pCan_Base, TRUE);
    }
    else
    {
        /* do nothing */
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void,CAN_CODE) MCAN_TimestampcounterAndTimeoutcounterInit \
( \
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base, \
    P2CONST(mcan_timestamp_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    if(pCan_Config != NULL)
    {
        pCan_Base->TSCC.R = (pCan_Base->TSCC.R & ~MCAN_TSCC_TSS_MASK) | MCAN_TSCC_TSS(pCan_Config->ts_select);/* polyspace RTE:NIV */
        pCan_Base->TSCC.R = (pCan_Base->TSCC.R & ~MCAN_TSCC_TCP_MASK) \
                        | MCAN_TSCC_TCP(pCan_Config->ts_counter_prescaler - 1U);/* polyspace RTE:NIV */

        pCan_Base->TOCC.R = (pCan_Base->TOCC.R & ~MCAN_TOCC_TOS_MASK) | MCAN_TOCC_TOS(pCan_Config->to_select);/* polyspace RTE:NIV */
        pCan_Base->TOCC.R = (pCan_Base->TOCC.R & ~MCAN_TOCC_TOP_MASK) | MCAN_TOCC_TOP(pCan_Config->to_period);/* polyspace RTE:NIV */


        if(pCan_Config->to_counter_enable == TRUE)/* polyspace RTE:NIV */
        {
            pCan_Base->TOCC.R = (pCan_Base->TOCC.R & ~MCAN_TOCC_ETOC_MASK) | MCAN_TOCC_ETOC(1U);
        }
        else if(pCan_Config->to_counter_enable == FALSE)
        {
            pCan_Base->TOCC.R = (pCan_Base->TOCC.R & ~MCAN_TOCC_ETOC_MASK) | MCAN_TOCC_ETOC(0U);
        }
        else
        {
            /* do nothing */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetBoState \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return pCan_Base->PSR.R & MCAN_PSR_BO_MASK;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) MCAN_GetEpState \
( \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) pCan_Base \
)
{
    return pCan_Base->PSR.R & MCAN_PSR_EP_MASK;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32,CAN_CODE) Can_LLD_GetWordsOfRxfifo \
( \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config, \
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base
)
{
    VAR(uint32, AUTOMATIC) WordsOfRxfifo = 0U;
    if(pCan_Config->rxfifoconfig != NULL)
    {
        if ((pCan_Config->rxfifoconfig->rx_fifo_needed == MCAN_RXFIFO_0_ENABLE) /* polyspace RTE:NIV *//* polyspace RTE:IDP */
            || (pCan_Config->rxfifoconfig->rx_fifo_needed== MCAN_RXFIFO_0_1_ENABLE))
        {
            WordsOfRxfifo = (2U + ((uint32)MCAN_GetPayloadSize(base, MCAN_RX_FIFO0) >> 2U)) \
                             *pCan_Config->rxfifoconfig->fifo_size_elems;/* polyspace RTE:NIV */
        }
        if ((pCan_Config->rxfifoconfig->rx_fifo_needed == MCAN_RXFIFO_1_ENABLE) \
            || (pCan_Config->rxfifoconfig->rx_fifo_needed == MCAN_RXFIFO_0_1_ENABLE))
        {
            WordsOfRxfifo += (2U + ((uint32)MCAN_GetPayloadSize(base, MCAN_RX_FIFO1) >> 2U)) \
                              *(uint32)pCan_Config->rxfifoconfig->fifo_size_elems;/* polyspace RTE:NIV */
        }
    }
    return WordsOfRxfifo;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(status_t, CAN_CODE) Can_LLD_NecessarySpace \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT(pCan_Config != NULL_PTR);
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];

    VAR(uint32, AUTOMATIC) numofwords = 0U;
    VAR(uint32, AUTOMATIC) WordsOfFilter = 0U;
    VAR(uint32, AUTOMATIC) WordsOfRxfifo = 0U;
    VAR(uint32, AUTOMATIC) WordsOfTxevent = 0U;
    VAR(uint32, AUTOMATIC) WordsOfTxbufferAndFifo = 0U;
    VAR(uint32, AUTOMATIC) WordsOfRxbuffer = 0U;
    VAR(status_t, AUTOMATIC) eCan_StatusRet = STATUS_ERROR;

    if(pCan_Config->filterconfig != NULL)
    {
        WordsOfFilter = (uint32)pCan_Config->filterconfig->std_filters /* polyspace RTE:NIV *//* polyspace RTE:IDP */
                         + ((uint32)pCan_Config->filterconfig->ext_filters << 1U);/* polyspace RTE:NIV */
    }
    WordsOfRxfifo = Can_LLD_GetWordsOfRxfifo(pCan_Config, base);
    if(pCan_Config->txeventconfig != NULL)
    {
        WordsOfTxevent = ((uint32)pCan_Config->txeventconfig->fifo_size_elems << 1U);/* polyspace RTE:NIV *//* polyspace RTE:IDP */
    }

    if(pCan_Config->txbufferconfig != NULL)
    {
        WordsOfTxbufferAndFifo = ((uint32)pCan_Config->txbufferconfig->ded_buffers_number /* polyspace RTE:NIV *//* polyspace RTE:IDP */
                                  + (uint32)pCan_Config->txbufferconfig->fifo_queue_size) /* polyspace RTE:NIV */
                                  *(2U + ((uint32)MCAN_GetPayloadSize(base, MCAN_TX_BUFF) >> 2U));
    }

    if(pCan_Config->rxbufferconfig != NULL)
    {
        WordsOfRxbuffer = (2U + ((uint32)MCAN_GetPayloadSize(base, MCAN_RX_BUFF) >> 2U)) \
                           *pCan_Config->rxbufferconfig->rx_buffer_size_elems;/* polyspace RTE:NIV *//* polyspace RTE:IDP */
    }

    numofwords = WordsOfFilter + WordsOfRxfifo + WordsOfTxevent \
                 + WordsOfTxbufferAndFifo + WordsOfRxbuffer;

    if(numofwords > pCan_Config->data->McanCtrl[eCan_Instance].mram_size_words)/* polyspace RTE:NIV *//* polyspace RTE:IDP */
    {
        eCan_StatusRet = STATUS_ERROR;
    }
    else
    {
        eCan_StatusRet = STATUS_SUCCESS;
    }
    return eCan_StatusRet;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_GetAddressParameter \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    VAR(uint32, AUTOMATIC) idx;
    if(eCan_Instance <= MCAN_MOD_ID_4)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
        SchM_Enter_Can_EXCLUSIVE_AREA_07();
        for (idx = (pCan_Config->data->McanCtrl[eCan_Instance].BaseWord); /* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */
             idx < ((pCan_Config->data->McanCtrl[eCan_Instance].BaseWord) \
             + pCan_Config->data->McanCtrl[eCan_Instance].mram_size_words); idx++)/* polyspace RTE:NIV */
        {
            MCAN_RAM->RAM[idx] = 0U;/* polyspace RTE:OBAI */
        }
        SchM_Exit_Can_EXCLUSIVE_AREA_07();
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
    }
    else if (eCan_Instance <= MCAN_MOD_ID_8)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
        SchM_Enter_Can_EXCLUSIVE_AREA_08();
        for (idx = (pCan_Config->data->McanCtrl[eCan_Instance].BaseWord); /* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */
             idx < ((pCan_Config->data->McanCtrl[eCan_Instance].BaseWord) \
             + pCan_Config->data->McanCtrl[eCan_Instance].mram_size_words); idx++)/* polyspace RTE:NIV */
        {
            MCAN_RAM1->RAM[idx] = 0U;/* polyspace RTE:OBAI */
        }
        SchM_Exit_Can_EXCLUSIVE_AREA_08();
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
    }
    else
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
        SchM_Enter_Can_EXCLUSIVE_AREA_18();
        for (idx = (pCan_Config->data->McanCtrl[eCan_Instance].BaseWord); \
             idx < ((pCan_Config->data->McanCtrl[eCan_Instance].BaseWord) \
             + pCan_Config->data->McanCtrl[eCan_Instance].mram_size_words); idx++)
        {
            MCAN_RAM2->RAM[idx] = 0U;/* polyspace RTE:OBAI */
        }
        SchM_Exit_Can_EXCLUSIVE_AREA_18();
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/* PRQA S 2755 EOF */
FUNC(status_t, CAN_CODE) Can_LLD_Init \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerId, \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(CANConfig, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT(pCan_Config != NULL_PTR);

    VAR(status_t, AUTOMATIC) status = STATUS_SUCCESS;
    VAR(uint32, AUTOMATIC) idx;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) pCan_Base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
    VAR(uint32, AUTOMATIC) address = 0U;
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
#if !defined(CCFC3008PT)
    #if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
        *(uint32*)0xFFFF804CU = 0x80000000U; // enable MCAN & enable MCAN change edian
    #elif defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN)
        *(uint32*)0xFFFF804CU = 0x800000FFU; // enable MCAN & enable MCAN5-8 change edian
    #else
        *(uint32*)0xFFFF804CU = 0U; // enable MCAN
    #endif
#endif
#if (defined(CCFC3012PT) || defined(CCFC3010PT) || defined(CCFC3011PT) || defined(CCFC3010PTD))
    *(uint32*)0xFFF28018U |= 3U; // unlock TTCAN0
#ifndef CCFC3010PTD
    *(uint32*)0xFFF2C018U |= 3U; // unlock TTCAN1
#endif
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
    *(uint32*)0xFFEB8018U |= 3U; // unlock TTCAN2
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
#else
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
    *(uint32*)0xFFEDC018U |= 3U; // unlock TTCAN0
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
    *(uint32*)0xFFEE0018U |= 3U; // unlock TTCAN1
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
    *(uint32*)0xFFEB8018U |= 3U; // unlock TTCAN2
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
#endif

    if (s_eCan_SramState[u8Can_ControllerId] == MCAN_SRAM_UNINIT)
    {
        status = MCAN_MsgRamPartitioningCheck(pCan_Config->data);/* polyspace RTE:NIP */
        if (status == STATUS_SUCCESS)
        {
            Can_LLD_GetAddressParameter(eCan_Instance, pCan_Config);
        }
        s_eCan_SramState[u8Can_ControllerId] = MCAN_SRAM_INITED;
    }

    address = ((pCan_Config->data->McanCtrl[eCan_Instance].BaseWord) << 2U);/* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */

    if (status == STATUS_SUCCESS)
    {
        MCAN_ClearAllReceivedFlags(pCan_Base);
        MCAN_SetConfigChangeEnable(pCan_Base);
        if (1U == s_u32Can_IsTimeOut[u32Can_CoreId])/* polyspace RTE:OBAI */
        {
            status = STATUS_TIMEOUT;
        }
    }

    if (STATUS_SUCCESS == status)
    {
        for (idx = 0; idx < pCan_Config->baudRateConfigCount; idx++)/* polyspace RTE:NIV */
        {
            if (g_u16Can_CurBaudRateId[u8Can_ControllerId] == pCan_Config->timingconfig[idx].baudRateConfigId)/* polyspace RTE:NIV *//* polyspace RTE:NIP *//* polyspace RTE:IDP */
            {
                MCAN_SetBitTiming(pCan_Base, &pCan_Config->timingconfig[idx]);
                break;
            }
        }
        MCAN_GlobalFilterConfig(pCan_Base, pCan_Config->globalfilterconfig);/* polyspace RTE:NIP */
        MCAN_RxFilterInit(eCan_Instance, pCan_Config->filterconfig, &address);/* polyspace RTE:NIP */
        MCAN_RxFifoInit(pCan_Base, pCan_Config->rxfifoconfig, &address);/* polyspace RTE:NIP */
        MCAN_TxEventFifoInit(pCan_Base, pCan_Config->txeventconfig, &address);/* polyspace RTE:NIP */
        MCAN_TxBufferInit(pCan_Base, pCan_Config->txbufferconfig, &address);/* polyspace RTE:NIP */
        MCAN_RxDedicatedBuffersInit(pCan_Base, pCan_Config->rxbufferconfig, &address);/* polyspace RTE:NIP */
        status = Can_LLD_NecessarySpace(eCan_Instance, pCan_Config);
    }
#if defined(RESOURCE_SUPPORT_MCAN_TSU)
    if(pCan_Config->tsuenable == TRUE)/* polyspace RTE:NIV */
    {
        MCAN_TSU_Enable(pCan_Base, pCan_Config);
    }
#endif

#if defined(RESOURCE_SUPPORT_MCAN_DMU)
    if(pCan_Config->mcandmuenable != NULL)
    {
        pCan_Base->DMUC.B.TTS = 1U;
        MCAN_DMU_InitIntrHandler(eCan_Instance, pCan_Config);

        if(pCan_Config->mcanusedmuintr == TRUE)/* polyspace RTE:NIV */
        {
            MCAN_DMU_InterruptInit(pCan_Base, pCan_Config->mcandmuintrenable);/* polyspace RTE:NIP */
        }

        if((pCan_Config->mcandmuenable->mcan_txfifo_dmu_enable == TRUE) && (pCan_Config->mcandmaconfig->txfifo_dma_config != NULL))/* polyspace RTE:IDP,NIV,NIP */
        {
            MCAN_SetDmaForTxFIFO(eCan_Instance, pCan_Config->mcandmaconfig->txfifo_dma_config);
        }
        if((pCan_Config->mcandmuenable->mcan_rxfifo0_dmu_enable == TRUE) && (pCan_Config->mcandmaconfig->rxfifo0_dma_config != NULL))/* polyspace RTE:IDP,NIV,NIP */
        {
            MCAN_SetDmaForRxFIFO0(eCan_Instance, pCan_Config->mcandmaconfig->rxfifo0_dma_config);
        }
        if((pCan_Config->mcandmuenable->mcan_rxfifo1_dmu_enable == TRUE) && (pCan_Config->mcandmaconfig->rxfifo1_dma_config != NULL))/* polyspace RTE:IDP,NIV,NIP */
        {
            MCAN_SetDmaForRxFIFO1(eCan_Instance, pCan_Config->mcandmaconfig->rxfifo1_dma_config);
        }
        if((pCan_Config->mcandmuenable->mcan_txeventfifo_dmu_enable == TRUE))/* polyspace RTE:IDP,NIV,NIP */
        {
            MCAN_SetDmaForTxFIFOEvent(eCan_Instance, pCan_Config->mcandmaconfig->txfifoevent_dma_config);/* polyspace RTE:IDP,NIV,NIP */
        }
    }

#endif

    if (STATUS_SUCCESS == status)
    {
        MCAN_SetOperationMode(pCan_Base, pCan_Config->mcanMode);/* polyspace RTE:NIV */

        MCAN_TimestampcounterAndTimeoutcounterInit(pCan_Base, pCan_Config->stampconfig);/* polyspace RTE:NIP */
    }

    return status;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_Deint(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    MCAN_SetConfigChangeEnable(base);

    MCAN_InterDisableAllSignals(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxIsEnableTranPause \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Enable \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    MCAN_SetConfigChangeEnable(base);

    base->CCCR.R = (base->CCCR.R & ~MCAN_CCCR_TXP_MASK) | MCAN_CCCR_TXP(u8Can_Enable);/* polyspace RTE:NIV */

    while ((((base->CCCR.R & MCAN_CCCR_TXP_MASK) >> MCAN_CCCR_TXP_SHIFT) != u8Can_Enable) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }

    MCAN_RsetInit(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxIsEnableDar \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Enable \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    MCAN_SetConfigChangeEnable(base);

    base->CCCR.R = (base->CCCR.R & ~MCAN_CCCR_DAR_MASK) | MCAN_CCCR_DAR(u8Can_Enable);/* polyspace RTE:NIV */

    while ((((base->CCCR.R & MCAN_CCCR_DAR_MASK) >> MCAN_CCCR_DAR_SHIFT) != u8Can_Enable) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }
    MCAN_RsetInit(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_EnterSleepStatus(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    VAR(uint32, AUTOMATIC) u32TotalElapsedTime = 0U;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
#ifdef CAN_TIMEOUT_USE_OS
    static VAR(TickType, AUTOMATIC) CurrentValue[CAN_CORE_NUM] = {0U};
    static VAR(TickType, AUTOMATIC) ElapsedValue[CAN_CORE_NUM] = {0U};
#endif
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/

    base->CCCR.R = (base->CCCR.R & ~MCAN_CCCR_CSR_MASK) | MCAN_CCCR_CSR(1U);/* polyspace RTE:NIV,IDP */
    #ifdef CAN_TIMEOUT_USE_OS
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &CurrentValue[u32Can_CoreId]);
    #endif
    while ((((base->CCCR.R & MCAN_CCCR_INIT_MASK) >> MCAN_CCCR_INIT_SHIFT) == 0U)
            && (u32TotalElapsedTime < s_u32Can_TimeOut[u32Can_CoreId]))/* polyspace RTE:OBAI */
    {
        #ifdef CAN_TIMEOUT_USE_OS
            (void)GetElapsedValue
            (
                (CounterType)CAN_TIMEOUT_COUNTER_NAME,
                &CurrentValue[u32Can_CoreId],
                &ElapsedValue[u32Can_CoreId]
            );
            u32TotalElapsedTime += (uint32)ElapsedValue[u32Can_CoreId];
        #else
            u32TotalElapsedTime++;
        #endif
    }
    u32TotalElapsedTime = 0U;
    #ifdef CAN_TIMEOUT_USE_OS
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &CurrentValue[u32Can_CoreId]);
    #endif
    while ((((base->CCCR.R & MCAN_CCCR_CSA_MASK) >> MCAN_CCCR_CSA_SHIFT) == 0U)
            && (u32TotalElapsedTime < s_u32Can_TimeOut[u32Can_CoreId]))/* polyspace RTE:OBAI */
    {
        #ifdef CAN_TIMEOUT_USE_OS
            (void)GetElapsedValue
            (
                (CounterType)CAN_TIMEOUT_COUNTER_NAME,
                &CurrentValue[u32Can_CoreId],
                &ElapsedValue[u32Can_CoreId]
            );
            u32TotalElapsedTime += (uint32)ElapsedValue[u32Can_CoreId];
        #else
            u32TotalElapsedTime++;
        #endif
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_WakeUp(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    VAR(uint32, AUTOMATIC) u32TotalElapsedTime = 0U;
#ifdef CAN_TIMEOUT_USE_OS
    static VAR(TickType, AUTOMATIC) CurrentValue[CAN_CORE_NUM] = {0U};
    static VAR(TickType, AUTOMATIC) ElapsedValue[CAN_CORE_NUM] = {0U};
#endif
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    base->CCCR.R = (base->CCCR.R & ~MCAN_CCCR_CSR_MASK) | MCAN_CCCR_CSR(0U);/* polyspace RTE:NIV,IDP */
    #ifdef CAN_TIMEOUT_USE_OS
        (void)GetCounterValue((CounterType)CAN_TIMEOUT_COUNTER_NAME, &CurrentValue[u32Can_CoreId]);
    #endif
    while ((((base->CCCR.R & MCAN_CCCR_CSA_MASK) >> MCAN_CCCR_CSA_SHIFT) == 1U)
            && (u32TotalElapsedTime < s_u32Can_TimeOut[u32Can_CoreId]))/* polyspace RTE:OBAI */
    {
        #ifdef CAN_TIMEOUT_USE_OS
            (void)GetElapsedValue
            (
                (CounterType)CAN_TIMEOUT_COUNTER_NAME,
                &CurrentValue[u32Can_CoreId],
                &ElapsedValue[u32Can_CoreId]
            );
            u32TotalElapsedTime += (uint32)ElapsedValue[u32Can_CoreId];
        #else
            u32TotalElapsedTime++;
        #endif
    }

    MCAN_RsetInit(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_SetExtendIDMask \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Mask \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    MCAN_SetConfigChangeEnable(base);

    base->XIDAM.R = (base->XIDAM.R & ~MCAN_XIDAM_EIDM_MASK) | MCAN_XIDAM_EIDM(u32Can_Mask);/* polyspace RTE:NIV */

    while ((((base->XIDAM.R & MCAN_XIDAM_EIDM_MASK) >> MCAN_XIDAM_EIDM_SHIFT) != u32Can_Mask) && (Can_Timeout < DEFAULT_TIMEOUT))
    {
        Can_Timeout++;
    }

    MCAN_RsetInit(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_TxIsReqPending \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buffer_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) mask = 0U;
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(u8Can_Tx_buffer_index < FEATURE_MCAN_TX_MB_NUM)
    {
        mask = (uint32)(1UL << u8Can_Tx_buffer_index);
    }

    if( ((base->TXBRP.R) & mask) == 0U)/* polyspace RTE:NIV,IDP */
    {
        bCan_Ret = FALSE;
    }
    else
    {
        bCan_Ret = TRUE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(uint32, CAN_CODE) Can_LLD_GetRamWord ( P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr )
{
    VAR(uint32, AUTOMATIC) ram_word;
    if (pCan_Tx_msg_ptr->idtype == STANDARD_ID)
    {
        ram_word = pCan_Tx_msg_ptr->id << MCAN_TX_BUFFER_STD_ID_SHIFT;
    }
    else
    {
        ram_word = pCan_Tx_msg_ptr->id + MCAN_TX_BUFFER_XTD_MASK;
    }

    if (pCan_Tx_msg_ptr->remote == TRUE)
    {
        ram_word = ram_word + MCAN_TX_BUFFER_RTR_MASK;
    }

    if (pCan_Tx_msg_ptr->esi == TRUE)
    {
        ram_word = ram_word + MCAN_TX_BUFFER_ESI_MASK;
    }
    return ram_word;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_TxWriteMsgToBuffer \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buff_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT(pCan_Tx_msg_ptr != NULL);
    DEV_ASSERT(u8Can_Tx_buff_index < FEATURE_MCAN_TX_MB_NUM);

    VAR(uint32, AUTOMATIC) ram_write_addr = 0U;
    VAR(uint8, AUTOMATIC)  payload_size = 0U;
    VAR(uint32, AUTOMATIC) ram_word = 0U;
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    VAR(uint32, AUTOMATIC) temp_ram_word = 0U;
#endif
    VAR(uint32, AUTOMATIC) payload_bytes_to_write = 0U;
    VAR(uint32, AUTOMATIC) curr_payload_word = 0U;
    VAR(uint32, AUTOMATIC) u32Can_Start_Adr = 0U;

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(eCan_Instance <= MCAN_MOD_ID_4)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
    }
    else if(eCan_Instance <= MCAN_MOD_ID_8)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM1_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
    }
    else
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM2_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    }

    payload_size = MCAN_GetPayloadSize(base, MCAN_TX_BUFF);
    ram_write_addr =((base->TXBC.R & MCAN_TXBC_TBSA_MASK) + u32Can_Start_Adr) /* polyspace RTE:NIV */
                     + ((uint32)u8Can_Tx_buff_index *((uint32)payload_size + 8U));
                     
    ram_word = Can_LLD_GetRamWord ( pCan_Tx_msg_ptr );
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = (uint32_t)((ram_word & 0x000000FFU) << 24U) | ((ram_word & 0x0000FF00U) << 8U) |\
                            ((ram_word & 0x00FF0000U) >> 8U) | ((ram_word & 0xFF000000U) >> 24U);
    ram_word = temp_ram_word;
#endif
    *(uint32 *)(ram_write_addr) = ram_word;/* polyspace RTE:IDP */

    ram_word = ((uint32)pCan_Tx_msg_ptr->dlc << MCAN_TX_BUFFER_DLC_SHIFT) & MCAN_TX_BUFFER_DLC_MASK;
    if (pCan_Tx_msg_ptr->fdf == TRUE)
    {
        ram_word = ram_word + MCAN_TX_BUFFER_FDF_MASK;
    }

    if (pCan_Tx_msg_ptr->brs == TRUE)
    {
        ram_word = ram_word + MCAN_TX_BUFFER_BRS_MASK;
    }

    if (pCan_Tx_msg_ptr->efc == TRUE)
    {
        ram_word = ram_word + MCAN_TX_BUFFER_EFC_MASK;
        ram_word = ram_word + ((uint32)pCan_Tx_msg_ptr->mm << MCAN_TX_BUFFER_MM_SHIFT);
    }

    if (pCan_Tx_msg_ptr->tx_tsce == TRUE)
    {
        ram_word = ram_word + MCAN_TX_BUFFER_TSCE_MASK;
    }
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = (uint32_t)((ram_word & 0x000000FFU) << 24U) | ((ram_word & 0x0000FF00U) << 8U) |\
                            ((ram_word & 0x00FF0000U) >> 8U) | ((ram_word & 0xFF000000U) >> 24U);
    ram_word = temp_ram_word;
#endif
    *(uint32 *)(ram_write_addr + 4U) = ram_word;/* polyspace RTE:IDP */

    payload_bytes_to_write = (uint32)MCAN_ConvertDLCToDataLength(pCan_Tx_msg_ptr->dlc);
    
    while(payload_bytes_to_write > 0U)
    {
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN) || defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN)
        ram_word = *(uint32_t*)(&(pCan_Tx_msg_ptr->data[curr_payload_word<<2]));/* PRQA S 0310, 0311 */
#else
        ram_word = (((uint32)pCan_Tx_msg_ptr->data[(curr_payload_word<<2U)]) \
                    +((uint32)pCan_Tx_msg_ptr->data[(curr_payload_word<<2U)+1U] <<  8U) \
                    +((uint32)pCan_Tx_msg_ptr->data[(curr_payload_word<<2U)+2U] << 16U) \
                    +((uint32)pCan_Tx_msg_ptr->data[(curr_payload_word<<2U)+3U] << 24U));
#endif
        SchM_Enter_Can_EXCLUSIVE_AREA_09();
        *(uint32 *)(ram_write_addr + 8U + (curr_payload_word *4U)) = ram_word;/* polyspace RTE:IDP */
        SchM_Exit_Can_EXCLUSIVE_AREA_09();
        curr_payload_word++;

        if (payload_bytes_to_write >= 4U)
        {
            payload_bytes_to_write = (payload_bytes_to_write - 4U);
        }
        else
        {
            payload_bytes_to_write = 0U;
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxMsgSingleRequest \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buffer_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) mask = 0U;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];

    if(u8Can_Tx_buffer_index < FEATURE_MCAN_TX_MB_NUM)
    {
        mask = (uint32)(1UL << u8Can_Tx_buffer_index);
    }

    base->TXBAR.R = ((base->TXBAR.R) & ~MCAN_TXBAR_AR_MASK) | mask;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxMsgScanSend \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Mask \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    base->TXBAR.R = ((base->TXBAR.R) & ~MCAN_TXBAR_AR_MASK) | u32Can_Mask;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_TxSendDedicatedMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buffer_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT(pCan_Tx_msg_ptr != NULL);
    DEV_ASSERT(u8Can_Tx_buffer_index < FEATURE_MCAN_TX_MB_NUM);
    DEV_ASSERT(pCan_Tx_msg_ptr->direction == TX_DIR);
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;
    u8Can_ControllerId = s_sInsToCtrlMap[eCan_Instance].controllerId; /* polyspace RTE:OBAI */

    Can_LLD_TxWriteMsgToBuffer(eCan_Instance, pCan_Tx_msg_ptr, u8Can_Tx_buffer_index);
    SchM_Enter_Can_EXCLUSIVE_AREA_26();
    MY_BIT_CLR(s_txHardwareMbIsSelected[u8Can_ControllerId], u8Can_Tx_buffer_index); /* polyspace RTE:OBAI */
    Can_LLD_TxMsgSingleRequest(eCan_Instance, u8Can_Tx_buffer_index);
    SchM_Exit_Can_EXCLUSIVE_AREA_26();
    return 1U;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_TxSendFifoQueueMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(can_msg_struct, AUTOMATIC, CAN_APPL_CONST) pCan_Tx_msg_ptr \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT(pCan_Tx_msg_ptr != NULL);
    DEV_ASSERT(pCan_Tx_msg_ptr->direction == TX_DIR);

    VAR(uint32, AUTOMATIC) msgs_sent = 0U;
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if((((base->TXFQS.R) & MCAN_TXFQS_TFQF_MASK) >> MCAN_TXFQS_TFQF_SHIFT) == 0U)/* polyspace RTE:NIV,IDP */
    {
        Can_LLD_TxWriteMsgToBuffer
        (
            eCan_Instance,
            pCan_Tx_msg_ptr,
            (uint8)(((base->TXFQS.R) & MCAN_TXFQS_TFQPI_MASK) >> MCAN_TXFQS_TFQPI_SHIFT)
        );
        Can_LLD_TxMsgSingleRequest
        (
            eCan_Instance,
            (uint8)(((base->TXFQS.R) & MCAN_TXFQS_TFQPI_MASK) >> MCAN_TXFQS_TFQPI_SHIFT)
        );
        msgs_sent = 1U;
    }
    else
    {
        msgs_sent = 0U;
    }

    return msgs_sent;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_TxFifoGetNumOfFreeElems(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    return ((base->TXFQS.R & MCAN_TXFQS_TFFL_MASK) >> MCAN_TXFQS_TFFL_SHIFT);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_TxSendRequestCancel \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buf_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) mask = 0U;

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(u8Can_Tx_buf_index < FEATURE_MCAN_TX_MB_NUM)
    {
        mask = (uint32)(1UL << u8Can_Tx_buf_index);
    }

    base->TXBCR.R = (( base->TXBCR.R) & ~MCAN_TXBCR_CR_MASK) | mask;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_TxSendReqCancelFinshed \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint8, CAN_VAR) u8Can_Tx_buf_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) mask = 0U;
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(u8Can_Tx_buf_index < FEATURE_MCAN_TX_MB_NUM)
    {
        mask = (uint32)(1UL << u8Can_Tx_buf_index);
    }

    if(((base->TXBCF.R) & mask) != 0U)/* polyspace RTE:NIV,IDP */
    {
        bCan_Ret = TRUE;
    }
    else
    {
        bCan_Ret = FALSE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_TxTranOccured \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Tx_buf_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) mask = 0U;
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(u32Can_Tx_buf_index < FEATURE_MCAN_TX_MB_NUM)
    {
        mask = (uint32)(1UL << u32Can_Tx_buf_index);
    }

    if(((base->TXBTO.R) & mask) != 0U)/* polyspace RTE:NIV,IDP */
    {
        bCan_Ret = TRUE;
    }
    else
    {
        bCan_Ret = FALSE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

extern FUNC(void, CAN_CODE) MCAN_RxNotifiy \
( \
    VAR(uint8, AUTOMATIC) u8Can_ControllerIdx, \
    VAR(uint32, AUTOMATIC) u32Can_CanObjectId, \
    P2CONST(can_msg_struct, CAN_VAR, CAN_APPL_DATA) pCan_MsgInfo \
);

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_RxNotifying \
( VAR(can_msg_struct, AUTOMATIC) msg_ptr, \
    VAR(MCANModId, AUTOMATIC) eCan_Instance , \
    VAR(rx_info_struct, AUTOMATIC) sCan_Rx_info ,\
	VAR(uint8, AUTOMATIC)  u8Can_HwFilterIdex )
{
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;
    P2CONST(mcan_hwFilter, AUTOMATIC, CAN_APPL_DATA) pCan_HwFilterCfg = NULL_PTR;
    VAR(boolean, AUTOMATIC) bCan_IsFifo0 = FALSE;
    VAR(boolean, AUTOMATIC) bCan_IsFifo1 = FALSE;
    VAR(boolean, AUTOMATIC) bCan_IsBuffer = FALSE;
    u8Can_ControllerId = s_sInsToCtrlMap[eCan_Instance].controllerId;
	P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
    
    if(msg_ptr.idtype == STANDARD_ID)
    {
        pCan_HwFilterCfg = &g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerId].standardFilterConfig[u8Can_HwFilterIdex];/* polyspace RTE:IDP *//* polyspace RTE:NIP */
    }
    else if(msg_ptr.idtype == EXTENDED_ID) /* PRQA S 2991, 2995 */
    {
        pCan_HwFilterCfg = &g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerId].extendedFilterConfig[u8Can_HwFilterIdex];/* polyspace RTE:IDP,NIP */
    }
    else
    {
        /* do nothing */
    }
    if(pCan_HwFilterCfg!=NULL_PTR)
    {
        if(pCan_HwFilterCfg->filterRestorePos == FIFO_0)/* polyspace RTE:NIV *//* polyspace RTE:IDP */
        {
            bCan_IsFifo0 = TRUE;
            base->RXF0A.R = (base->RXF0A.R & ~MCAN_RXF0A_F0AI_MASK) /* polyspace RTE:NIV,IDP */
                                                | MCAN_RXF0A_F0AI(sCan_Rx_info.buffer_index);
        }
        else if(pCan_HwFilterCfg->filterRestorePos == FIFO_1)
        {
            base->RXF1A.R = (base->RXF1A.R & ~MCAN_RXF1A_F1AI_MASK) /* polyspace RTE:NIV,IDP */
                                                | MCAN_RXF1A_F1AI(sCan_Rx_info.buffer_index);
            bCan_IsFifo1 = TRUE;
        }
        else if(pCan_HwFilterCfg->filterRestorePos == DEDICATED_RX_BUFFER)
        {
            if(msg_ptr.rx_info.buffer_index < 32U)
            {
                base->NDAT1.R = (1U << msg_ptr.rx_info.buffer_index);/* polyspace RTE:IDP *//* PRQA S 4491 */
            }
            else
            {
                base->NDAT2.R = (1U << (msg_ptr.rx_info.buffer_index - 32U));/* PRQA S 4491 *//* polyspace RTE:SHF,IDP */
            }
            bCan_IsBuffer = TRUE;
        }
        else
        {
            /* do nothing */
        }
    
        if ((bCan_IsFifo0 == TRUE) || (bCan_IsFifo1 == TRUE) || (bCan_IsBuffer == TRUE))
        {
            MCAN_RxNotifiy(u8Can_ControllerId, pCan_HwFilterCfg->CanObjectId, &msg_ptr);/* polyspace RTE:NIV */
        }
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_RxCopyMsgFromRamToList \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Msg_addr_in_msg_ram, \
    VAR(rx_info_struct, AUTOMATIC) sCan_Rx_info \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) u32Can_Index = 0U;
    VAR(uint32, AUTOMATIC) ram_word = 0U;
    VAR(uint32, AUTOMATIC) byte_index = 0U;
    VAR(uint32, AUTOMATIC) bytes_to_read = CAN_FD_MAX_NO_OF_DTB_PER_FRAME;
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    VAR(uint32, AUTOMATIC) temp_ram_word = 0U;
#elif defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN)
    /* do nothing */
#else
    P2VAR(uint32, AUTOMATIC, CAN_APPL_CONST) pCan_DataAddr = NULL_PTR;
#endif
    VAR(can_msg_struct, AUTOMATIC) msg_ptr = {0};
    VAR(uint8, AUTOMATIC)  u8Can_HwFilterIdex = 0U;
    VAR(uint8, AUTOMATIC) paysize = MCAN_GetPayloadSize(g_mcanBase[eCan_Instance], MCAN_RX_BUFF);

    msg_ptr.direction = RX_DIR;
    msg_ptr.rx_info = sCan_Rx_info;

    ram_word = *(uint32 *)(u32Can_Msg_addr_in_msg_ram + (u32Can_Index * 4U));/* polyspace RTE:NIV,IDP */
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = (uint32_t)((ram_word & 0x000000FFU) << 24U) | ((ram_word & 0x0000FF00U) << 8U) |\
                            ((ram_word & 0x00FF0000U) >> 8U) | ((ram_word & 0xFF000000U) >> 24U);
    ram_word = temp_ram_word;
#endif
    /*
        [SWS_Can_00423] In case of an Extended CAN frame, the Can module shall 
        convert the ID to a standardized format since the Upper layer (CANIF) does not know 
        whether the received CAN frame is a Standard CAN frame or Extended CAN frame. 
        In case of an Extended CAN frame, MSB of a received CAN frame ID needs to be 
        made as 1 to mark the received CAN frame as Extended.
    */
    if ((ram_word & MCAN_RX_BUFFER_XTD_MASK) == 0U)
    {
        msg_ptr.idtype = STANDARD_ID;
        msg_ptr.id = (uint32)((ram_word \
                        & MCAN_RX_BUFFER_STD_ID_MASK) >> MCAN_RX_BUFFER_STD_ID_SHIFT);
    }
    else
    {
        msg_ptr.idtype = EXTENDED_ID;
        msg_ptr.id = (ram_word & MCAN_RX_BUFFER_EXT_ID_MASK);
    }

    if ((ram_word & MCAN_RX_BUFFER_RTR_MASK) == 0U)
    {
        msg_ptr.remote = FALSE;
    }
    else
    {
        msg_ptr.remote = TRUE;
    }

    if ((ram_word & MCAN_RX_BUFFER_ESI_MASK) == 0U)
    {
        msg_ptr.esi = FALSE;
    }
    else
    {
        msg_ptr.esi = TRUE;
    }

    u32Can_Index = 1U;
    ram_word = *(uint32 *)(u32Can_Msg_addr_in_msg_ram + (u32Can_Index *4U));/* polyspace RTE:IDP,NIV */
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN)
    temp_ram_word = (uint32_t)((ram_word & 0x000000FFU) << 24U) | ((ram_word & 0x0000FF00U) << 8U) |\
                            ((ram_word & 0x00FF0000U) >> 8U) | ((ram_word & 0xFF000000U) >> 24U);
    ram_word = temp_ram_word;
#endif
    msg_ptr.dlc = (uint16)((ram_word \
                              & MCAN_RX_BUFFER_DLC_MASK)>> MCAN_RX_BUFFER_DLC_SHIFT);

    if (msg_ptr.dlc > MCAN_ConvertDataLengthCode(paysize))
    {
        msg_ptr.dlc = MCAN_ConvertDataLengthCode(paysize);
    }

    bytes_to_read =  (uint32)MCAN_ConvertDLCToDataLength(msg_ptr.dlc);

    if ((ram_word & MCAN_RX_BUFFER_FDF_MASK) == 0U)
    {
        msg_ptr.fdf = FALSE;
    }
    else
    {
        msg_ptr.fdf = TRUE;
    }

    if ((ram_word & MCAN_RX_BUFFER_BRS_MASK) == 0U)
    {
        msg_ptr.brs = FALSE;
    }
    else
    {
        msg_ptr.brs = TRUE;
    }

	u8Can_HwFilterIdex = (uint8)((ram_word & MCAN_RX_BUFFER_FIDX_MASK) >> MCAN_RX_BUFFER_FIDX_SHIFT);
    msg_ptr.rx_info.rx_timestamp = ram_word & MCAN_RX_BUFFER_RXTS_MASK;

    u32Can_Index = 2U;

    while(bytes_to_read > 0U)
    {
        ram_word = *(uint32 *)(u32Can_Msg_addr_in_msg_ram + (u32Can_Index * 4U));/* polyspace RTE:IDP,NIV */

        byte_index = (u32Can_Index - 2U) * 4U;
#if defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN_CCFC3008PCSN) || defined(RESOURCE_SUPPORT_MCAN_CHANGE_EDIAN)
        *(uint32_t*)(&(msg_ptr.data[byte_index])) = ram_word;/* PRQA S 0310 */
#else
        pCan_DataAddr = (uint32 *)&msg_ptr.data[byte_index];
        *pCan_DataAddr = (uint32)((ram_word >> 24U) & 0xFFU) |    /* polyspace RTE:IDP */ /* PRQA S 2934, 0310 */
        		(uint32)((ram_word >> 8u) & 0xFF00u) |
        		(uint32)((ram_word << 8u) & 0xFF0000u) |
        		(uint32)((ram_word << 24u) & 0xFF000000u);
#endif
        if (bytes_to_read >= 4U)
        {
            bytes_to_read = bytes_to_read - 4U;
        }
        else
        {
            bytes_to_read = 0U;
        }

        u32Can_Index++;
    }
    Can_LLD_RxNotifying(msg_ptr, eCan_Instance, sCan_Rx_info, u8Can_HwFilterIdex);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_INLINE FUNC(void, CAN_CODE) Can_LLD_RxRecDedicatedMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Ded_buffer_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT(u32Can_Ded_buffer_index <= FEATURE_MCAN_RX_MB_NUM);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];

    VAR(uint32, AUTOMATIC) u32Can_Start_Adr = 0U;

    VAR(uint32, AUTOMATIC) paysize = MCAN_GetPayloadSize(base, MCAN_RX_BUFF);
    VAR(uint32, AUTOMATIC) ram_read_addr;
    VAR(rx_info_struct, AUTOMATIC) sCan_Rx_info;

    if(eCan_Instance <= MCAN_MOD_ID_4)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
    }
    else if(eCan_Instance <= MCAN_MOD_ID_8)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM1_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
    }
    else
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM2_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    }

    ram_read_addr = ((base->RXBC.R & MCAN_RXBC_RBSA_MASK) /* polyspace RTE:NIV */
                     + u32Can_Start_Adr) + (u32Can_Ded_buffer_index *(paysize + 8U));

    sCan_Rx_info.rx_via = DEDICATED_RX_BUFFER;
    sCan_Rx_info.buffer_index = u32Can_Ded_buffer_index;
    sCan_Rx_info.rx_timestamp = 0U;

    Can_LLD_RxCopyMsgFromRamToList(eCan_Instance, ram_read_addr, sCan_Rx_info);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_RxDedicateBufProcNewMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) ded_buffer_index = 0U;
    VAR(uint32, AUTOMATIC) msgs_read = 0U;
    VAR(uint32, AUTOMATIC) mask = 0U;
    VAR(uint8, AUTOMATIC) u8Can_Index = 0U;
    VAR(uint32, AUTOMATIC) new_data_reg[2U];

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */


    new_data_reg[0] = base->NDAT1.R;/* polyspace RTE:NIV,IDP */
    new_data_reg[1] = base->NDAT2.R;/* polyspace RTE:NIV */

    for (u8Can_Index = 0U; u8Can_Index < 2U; ++u8Can_Index)
    {
        ded_buffer_index = (uint32)u8Can_Index *32U;
        mask = 1U;

        while (new_data_reg[u8Can_Index] > 0U)
        {
            if ((mask & new_data_reg[u8Can_Index]) != 0U)
            {
                new_data_reg[u8Can_Index]=new_data_reg[u8Can_Index] & ~mask;

                Can_LLD_RxRecDedicatedMsg(eCan_Instance, ded_buffer_index);
                msgs_read++;
            }
            ded_buffer_index++;
            mask = mask << 1U;
        }
    }

    return msgs_read;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint32, CAN_CODE) Can_LLD_RxRecFifoMsg \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Rx_fifo_number \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);
    DEV_ASSERT((u32Can_Rx_fifo_number == 0U) || (u32Can_Rx_fifo_number == 1U));

    VAR(uint32, AUTOMATIC) paysize;
    VAR(uint32, AUTOMATIC) msgs_read = 0U;
    VAR(uint32, AUTOMATIC) ram_read_addr;
    VAR(rx_info_struct, AUTOMATIC) sCan_Rx_info;
    VAR(uint32, AUTOMATIC) RXF0S_F0GI_temp = 0U;
    VAR(uint32, AUTOMATIC) RXF1S_F1GI_temp = 0U;
    VAR(uint32, AUTOMATIC) u32Can_Start_Adr = 0U;
    VAR(uint32, AUTOMATIC) Can_Timeout = 0U;

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(eCan_Instance <= MCAN_MOD_ID_4)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_1
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_1 */
    }
    else if(eCan_Instance <= MCAN_MOD_ID_8)
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_5
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM1_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_5 */
    }
    else
    {
#ifdef RESOURCE_SUPPORT_MCAN_CONTROLLER_9
        u32Can_Start_Adr = FEATURE_MCAN_MSG_RAM2_START_ADR;
#endif /* RESOURCE_SUPPORT_MCAN_CONTROLLER_9 */
    }

    switch (u32Can_Rx_fifo_number)
    {
    case 0:
    {
        while(((((base->RXF0S.R) & MCAN_RXF0S_F0FL_MASK) >> MCAN_RXF0S_F0FL_SHIFT) > 0U) && (Can_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV,IDP */
        {
            RXF0S_F0GI_temp = ((base->RXF0S.R & MCAN_RXF0S_F0GI_MASK) >> MCAN_RXF0S_F0GI_SHIFT);
            msgs_read++;
            paysize = MCAN_GetPayloadSize(base, MCAN_RX_FIFO0);
            ram_read_addr = ((base->RXF0C.R & MCAN_RXF0C_F0SA_MASK) /* polyspace RTE:NIV */
                                + u32Can_Start_Adr) \
                                + (RXF0S_F0GI_temp * (paysize + 8U));
            sCan_Rx_info.rx_via = FIFO_0;
            sCan_Rx_info.buffer_index = RXF0S_F0GI_temp;
            sCan_Rx_info.rx_timestamp = 0U;
            Can_LLD_RxCopyMsgFromRamToList(eCan_Instance, ram_read_addr, sCan_Rx_info);
            Can_Timeout++;
        }
        break;
    }
    case 1:
    {
        while(((((base->RXF1S.R) & MCAN_RXF1S_F1FL_MASK) >> MCAN_RXF1S_F1FL_SHIFT) > 0U) && (Can_Timeout < DEFAULT_TIMEOUT))/* polyspace RTE:NIV,IDP */
        {
            RXF1S_F1GI_temp = ((base->RXF1S.R & MCAN_RXF1S_F1GI_MASK) >> MCAN_RXF1S_F1GI_SHIFT);
            msgs_read++;
            paysize = MCAN_GetPayloadSize(base, MCAN_RX_FIFO1);
            ram_read_addr = ((base->RXF1C.R & MCAN_RXF1C_F1SA_MASK) /* polyspace RTE:NIV */
                                + u32Can_Start_Adr) \
                                + (RXF1S_F1GI_temp * (paysize + 8U));
            sCan_Rx_info.rx_via = FIFO_1;
            sCan_Rx_info.rx_timestamp = 0U;
            sCan_Rx_info.buffer_index = RXF1S_F1GI_temp;
            Can_LLD_RxCopyMsgFromRamToList(eCan_Instance, ram_read_addr, sCan_Rx_info);
            Can_Timeout++;
        }
        break;
    }
    default:
    {
        /* nothing */
        break;
    }
    }

    return msgs_read;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_IsDataLost \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Rx_fifo_number \
)
{
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
    VAR(uint8, AUTOMATIC) IsDataLost = 0U;

    VAR(uint32, AUTOMATIC) IR_REG_VAULE = base->IR.R;/* polyspace RTE:NIV,IDP */
    if (u32Can_Rx_fifo_number == 0U)
    {
        if((IR_REG_VAULE & MCAN_IR_RF0L_MASK) != 0U)
        {
            base->IR.R = MCAN_IR_RF0L_MASK;
            IsDataLost = 1U;
        }

        if((IR_REG_VAULE & MCAN_IR_RF0F_MASK) != 0U)
        {
            base->IR.R = MCAN_IR_RF0F_MASK;
            IsDataLost = 1U;
        }
    }
    else
    {
        if((IR_REG_VAULE & MCAN_IR_RF1F_MASK) != 0U)
        {
            base->IR.R = MCAN_IR_RF1F_MASK;
            IsDataLost = 1U;
        }

        if((IR_REG_VAULE & MCAN_IR_RF1L_MASK) != 0U)
        {
            base->IR.R = MCAN_IR_RF1L_MASK;
            IsDataLost = 1U;
        }
    }
    return IsDataLost;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_InterDisableAllSignals(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
    MCAN_InterDisableAllSignals(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_InterruptInit \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    P2CONST(mcan_inter_config_t, AUTOMATIC, CAN_APPL_CONST) pCan_Config \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
    MCAN_InterruptInit(base, pCan_Config);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_IsBusOff(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;

    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if (MCAN_PSR_BO_MASK == MCAN_GetBoState(base))
    {
        bCan_Ret = TRUE;
    }
    else
    {
        bCan_Ret = FALSE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_IsErrorActive(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;

    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if (MCAN_PSR_EP_MASK != MCAN_GetEpState(base))
    {
        bCan_Ret = TRUE;
    }
    else
    {
        bCan_Ret = FALSE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_GetRxErrorCounter(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    return (uint8)base->ECR.B.REC;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_GetTxErrorCounter(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    return (uint8)base->ECR.B.TEC;/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(uint8, CAN_CODE) Can_LLD_IsFDEnabled(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    return MCAN_IsFDEnabled(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_isInitState(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    return MCAN_isInitState(base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_isSleep(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;

    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if ((((base->CCCR.R & MCAN_CCCR_CSR_MASK) >> MCAN_CCCR_CSR_SHIFT) == 1U))/* polyspace RTE:NIV,IDP */
    {
        bCan_Ret = TRUE;
    }
    else
    {
        bCan_Ret = FALSE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_SetTimeOut(VAR(uint32, CAN_VAR) u32Can_TimeOutDuration)
{
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();    /*get coreid*/
    s_u32Can_TimeOut[u32Can_CoreId] = u32Can_TimeOutDuration;/* polyspace RTE:OBAI */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) Can_LLD_RsetInit(VAR(MCANModId, AUTOMATIC) eCan_Instance)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_DATA) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */
    MCAN_RsetInit((MCAN_Type*)(uint32)base);
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(boolean, CAN_CODE) Can_LLD_isTxInterruptMb \
( \
    VAR(MCANModId, AUTOMATIC) eCan_Instance, \
    VAR(uint32, CAN_VAR) u32Can_Tx_buf_index \
)
{
    DEV_ASSERT(eCan_Instance < MCAN_MOD_BUTT);

    VAR(uint32, AUTOMATIC) mask = 0U;
    VAR(boolean, AUTOMATIC) bCan_Ret = FALSE;
    P2CONST(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[eCan_Instance];/* polyspace RTE:OBAI */

    if(u32Can_Tx_buf_index < FEATURE_MCAN_TX_MB_NUM)
    {
        mask = (uint32)(1UL << u32Can_Tx_buf_index);
    }

    if(((base->TXBTIE.R) & mask) != 0U)/* polyspace RTE:NIV,IDP */
    {
        bCan_Ret = TRUE;
    }
    else
    {
        bCan_Ret = FALSE;
    }

    return bCan_Ret;
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#if defined(RESOURCE_SUPPORT_MCAN_DMU)

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForTxFIFO \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    CONSTP2CONST(mcan_txfifo_dma_config_t, AUTOMATIC, CAN_APPL_CONST) mcan_dma_config \
)
{
    status_t ret;
    eDMATransferConfigType TcdCfg = {0u};
    eDMALoopTransferConfigType LoopTcdCfg = {0U};
    TcdCfg.srcAddr                  = (uint32_t)mcan_dma_config->SrcPtr;/* polyspace RTE:IDP,NIP */
    TcdCfg.destAddr                 = (uint32_t)(g_mcanBaseAddr[instance] + DMU_TX_ELEMENT_OFFSET_ADDRESS);
    TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.srcAddrOffset            = 4;
    TcdCfg.destAddrOffset           = 4;
    TcdCfg.srcAddrAdjustLast        = 0;
    TcdCfg.destAddrAdjustLast       = -(((sint32)mcan_dma_config->SrcLen) * 4);/* polyspace RTE:OVFL,NIV */
    TcdCfg.srcAddrModulo            = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.destAddrModulo           = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.minorTransByte           = ((mcan_dma_config->SrcLen) * 4U);
    TcdCfg.featureScatterGatherEn   = FALSE;
    TcdCfg.featureScatterGatherNextDescriptor   = 0U;
    TcdCfg.completeIntEn            = FALSE;
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = 1U;
    LoopTcdCfg.srcAddrOffsetEn      = FALSE;
    LoopTcdCfg.dstAddrOffsetEn      = FALSE;
    LoopTcdCfg.minorLpOffset        = 0;
    LoopTcdCfg.minorLpLinkEn        = FALSE;
    LoopTcdCfg.minorLpLinkChn       = 0U;
    LoopTcdCfg.majorLpLinkEn        = FALSE;
    LoopTcdCfg.majorLpLinkChn       = 0U;

    ret = EDMA_LLD_SetLoopTransferConfig(mcan_dma_config->ResultDmaMappedChan, &TcdCfg);/* polyspace RTE:NIV */
    DEV_ASSERT(ret == STATUS_SUCCESS); /* PRQA S 4404 */
    (void)ret;

    (void)EDMA_LLD_SetChannelRequest(mcan_dma_config->ResultDmaMappedChan);/* polyspace RTE:NIV */

    if (mcan_dma_config->Callback != NULL)/* polyspace RTE:NIP */
    {
        (void) EDMA_LLD_SetUpCallback(mcan_dma_config->ResultDmaMappedChan, mcan_dma_config->Callback, mcan_dma_config->CallbackParam);/* polyspace RTE:NIP */

        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    }
    else
    {
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForRxFIFO0 \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    CONSTP2CONST(mcan_rxfifo0_dma_config_t, AUTOMATIC, CAN_APPL_CONST) mcan_dma_config \
)
{
    status_t ret;

    eDMATransferConfigType TcdCfg = {0U};
    eDMALoopTransferConfigType LoopTcdCfg = {0U};

    TcdCfg.srcAddr                  = (uint32_t)(g_mcanBaseAddr[instance]) + DMU_RX0_ELEMENT_OFFSET_ADDRESS;
    TcdCfg.destAddr                 = (uint32_t)mcan_dma_config->DestPtr;/* polyspace RTE:IDP,NIP */
    TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.srcAddrOffset            = 4;
    TcdCfg.destAddrOffset           = 4;
    TcdCfg.srcAddrAdjustLast        = -(((sint32)mcan_dma_config->DestLen) * 4);/* polyspace RTE:NIV,OVFL */
    TcdCfg.destAddrAdjustLast       = 0;
    TcdCfg.srcAddrModulo            = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.destAddrModulo           = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.minorTransByte           = ((mcan_dma_config->DestLen) * 4U);
    TcdCfg.featureScatterGatherEn   = FALSE;
    TcdCfg.featureScatterGatherNextDescriptor   = 0U;
    TcdCfg.completeIntEn            = TRUE;
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = (uint32)1U;
    LoopTcdCfg.srcAddrOffsetEn      = FALSE;
    LoopTcdCfg.dstAddrOffsetEn      = FALSE;
    LoopTcdCfg.minorLpOffset        = 0;
    LoopTcdCfg.minorLpLinkEn        = FALSE;
    LoopTcdCfg.minorLpLinkChn       = 0U;
    LoopTcdCfg.majorLpLinkEn        = FALSE;
    LoopTcdCfg.majorLpLinkChn       = 0U;

    ret = EDMA_LLD_SetLoopTransferConfig(mcan_dma_config->ResultDmaMappedChan, &TcdCfg);/* polyspace RTE:NIV */
    DEV_ASSERT(ret == STATUS_SUCCESS); /* PRQA S 4404 */
    (void)ret;

    (void)EDMA_LLD_SetChannelRequest(mcan_dma_config->ResultDmaMappedChan);/* polyspace RTE:NIV */

    if (mcan_dma_config->Callback != NULL)/* polyspace RTE:NIP */
    {
        (void) EDMA_LLD_SetUpCallback(mcan_dma_config->ResultDmaMappedChan, mcan_dma_config->Callback, mcan_dma_config->CallbackParam);/* polyspace RTE:NIP */

        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    }
    else
    {
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForRxFIFO1 \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    CONSTP2CONST(mcan_rxfifo1_dma_config_t, AUTOMATIC, CAN_APPL_CONST) mcan_dma_config \
)
{
    status_t ret;

    eDMATransferConfigType TcdCfg = {0U};
    eDMALoopTransferConfigType LoopTcdCfg = {0U};

    TcdCfg.srcAddr                  = (uint32_t)(g_mcanBaseAddr[instance]) + DMU_RX1_ELEMENT_OFFSET_ADDRESS;
    TcdCfg.destAddr                 = (uint32_t)mcan_dma_config->DestPtr;/* polyspace RTE:IDP,NIP */
    TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.srcAddrOffset            = 4;
    TcdCfg.destAddrOffset           = 4;
    TcdCfg.srcAddrAdjustLast        = -(((sint32)mcan_dma_config->DestLen) * 4);/* polyspace RTE:NIV,OVFL */
    TcdCfg.destAddrAdjustLast       = 0;
    TcdCfg.srcAddrModulo            = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.destAddrModulo           = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.minorTransByte           = ((mcan_dma_config->DestLen) * 4U);
    TcdCfg.featureScatterGatherEn   = FALSE;
    TcdCfg.featureScatterGatherNextDescriptor   = 0U;
    TcdCfg.completeIntEn            = TRUE;
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = 1U;
    LoopTcdCfg.srcAddrOffsetEn      = FALSE;
    LoopTcdCfg.dstAddrOffsetEn      = FALSE;
    LoopTcdCfg.minorLpOffset        = 0;
    LoopTcdCfg.minorLpLinkEn        = FALSE;
    LoopTcdCfg.minorLpLinkChn       = 0U;
    LoopTcdCfg.majorLpLinkEn        = FALSE;
    LoopTcdCfg.majorLpLinkChn       = 0U;

    ret = EDMA_LLD_SetLoopTransferConfig(mcan_dma_config->ResultDmaMappedChan, &TcdCfg);/* polyspace RTE:NIV */
    DEV_ASSERT(ret == STATUS_SUCCESS); /* PRQA S 4404 */
    (void)ret;

    (void)EDMA_LLD_SetChannelRequest(mcan_dma_config->ResultDmaMappedChan);/* polyspace RTE:NIV */

    if (mcan_dma_config->Callback != NULL)/* polyspace RTE:NIP */
    {
        (void) EDMA_LLD_SetUpCallback(mcan_dma_config->ResultDmaMappedChan, mcan_dma_config->Callback, mcan_dma_config->CallbackParam);/* polyspace RTE:NIP */

        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    }
    else
    {
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_SetDmaForTxFIFOEvent \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    CONSTP2CONST(mcan_txfifoevent_dma_config_t, AUTOMATIC, CAN_APPL_CONST) mcan_dma_config \
)
{
    status_t ret;

    eDMATransferConfigType TcdCfg = {0U};
    eDMALoopTransferConfigType LoopTcdCfg = {0U};

    TcdCfg.srcAddr                  = (uint32_t)(g_mcanBaseAddr[instance]) + DMU_RX1_ELEMENT_OFFSET_ADDRESS;
    TcdCfg.destAddr                 = (uint32_t)mcan_dma_config->DestPtr;/* polyspace RTE:IDP,NIP */
    TcdCfg.srcTransDataSize         = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.destTransDataSize        = EDMA_TRANSFER_SIZE_4B;
    TcdCfg.srcAddrOffset            = 4;
    TcdCfg.destAddrOffset           = 4;
    TcdCfg.srcAddrAdjustLast        = -(((sint32)mcan_dma_config->DestLen) * 4);/* polyspace RTE:NIV,OVFL */
    TcdCfg.destAddrAdjustLast       = 0;
    TcdCfg.srcAddrModulo            = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.destAddrModulo           = EDMA_ADDRESS_MODULO_OFF;
    TcdCfg.minorTransByte           = ((mcan_dma_config->DestLen) * 4U);
    TcdCfg.featureScatterGatherEn   = FALSE;
    TcdCfg.featureScatterGatherNextDescriptor   = 0U;
    TcdCfg.completeIntEn            = TRUE;
    TcdCfg.lpTransConfigPtr         = &LoopTcdCfg;

    LoopTcdCfg.majorLpIterCnt       = 1U;
    LoopTcdCfg.srcAddrOffsetEn      = FALSE;
    LoopTcdCfg.dstAddrOffsetEn      = FALSE;
    LoopTcdCfg.minorLpOffset        = 0;
    LoopTcdCfg.minorLpLinkEn        = FALSE;
    LoopTcdCfg.minorLpLinkChn       = 0U;
    LoopTcdCfg.majorLpLinkEn        = FALSE;
    LoopTcdCfg.majorLpLinkChn       = 0U;

    ret = EDMA_LLD_SetLoopTransferConfig(mcan_dma_config->ResultDmaMappedChan, &TcdCfg);/* polyspace RTE:NIV */
    DEV_ASSERT(ret == STATUS_SUCCESS); /* PRQA S 4404 */
    (void)ret;

    (void)EDMA_LLD_SetChannelRequest(mcan_dma_config->ResultDmaMappedChan);/* polyspace RTE:NIV */

    if (mcan_dma_config->Callback != NULL)/* polyspace RTE:NIP */
    {
        (void) EDMA_LLD_SetUpCallback(mcan_dma_config->ResultDmaMappedChan, mcan_dma_config->Callback, mcan_dma_config->CallbackParam);/* polyspace RTE:NIP */

        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, TRUE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, TRUE);
    }
    else
    {
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_ERROR_INT, FALSE);
        EDMA_LLD_SetInterruptConfig(mcan_dma_config->ResultDmaMappedChan, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    }
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
FUNC(void, CAN_CODE) MCAN_GetDmaForRxFIFO \
( \
    VAR(MCANModId, AUTOMATIC) instance, \
    VAR(uint32, CAN_VAR) u32Can_Rx_fifo_number \
)
{
    VAR(uint8, AUTOMATIC) u8Can_ControllerId = 0U;
    P2VAR(can_rxmsg_B_struct, AUTOMATIC, CAN_APPL_DATA) pCan_rxmsg = NULL_PTR;
    VAR(can_msg_struct, AUTOMATIC) msg_ptr = {0};
    VAR(uint32, AUTOMATIC) ram_word = 0U;
    VAR(uint32, AUTOMATIC) u32Can_Index = 0U;
    VAR(uint32, AUTOMATIC) RXFS_FGI_temp = 0U;
    VAR(uint32, AUTOMATIC) bytes_to_read = 0U;
    VAR(uint8, AUTOMATIC)  u8Can_HwFilterIdex = 0U;
    VAR(uint32, AUTOMATIC) byte_index = 0U;
    P2VAR(uint32, AUTOMATIC, CAN_APPL_CONST) pCan_DataAddr = NULL_PTR;
    P2CONST(mcan_hwFilter, AUTOMATIC, CAN_APPL_DATA) pCan_HwFilterCfg = NULL_PTR;
    P2VAR(MCAN_Type, AUTOMATIC, CAN_APPL_CONST) base = g_mcanBase[instance];/* polyspace RTE:OBAI */
    VAR(uint8, AUTOMATIC) paysize = MCAN_GetPayloadSize(g_mcanBase[instance], MCAN_RX_BUFF);

    u8Can_ControllerId = s_sInsToCtrlMap[instance].controllerId;
    switch (u32Can_Rx_fifo_number)
    {
    case 0U:
        {
            pCan_rxmsg = (can_rxmsg_B_struct*)g_pCan_CurConfig->controllerConfig[u8Can_ControllerId].mcandmaconfig->rxfifo0_dma_config->DestPtr;/* polyspace RTE:IDP,NIP */
            RXFS_FGI_temp = (uint32)((base->RXF0S.R & MCAN_RXF0S_F0GI_MASK) >> MCAN_RXF0S_F0GI_SHIFT);/* polyspace RTE:NIV */
            break;
        }
    case 1U:
        {
            pCan_rxmsg = (can_rxmsg_B_struct*)g_pCan_CurConfig->controllerConfig[u8Can_ControllerId].mcandmaconfig->rxfifo1_dma_config->DestPtr;/* polyspace RTE:IDP,NIP */
            RXFS_FGI_temp = (uint32)((base->RXF1S.R & MCAN_RXF1S_F1GI_MASK) >> MCAN_RXF1S_F1GI_SHIFT);/* polyspace RTE:NIV */
            break;
        }
    default:
        {
            pCan_rxmsg = (can_rxmsg_B_struct*)g_pCan_CurConfig->controllerConfig[u8Can_ControllerId].mcandmaconfig->rxfifo0_dma_config->DestPtr;/* polyspace RTE:IDP */
            RXFS_FGI_temp = (uint32)((base->RXF0S.R & MCAN_RXF0S_F0GI_MASK) >> MCAN_RXF0S_F0GI_SHIFT);
            break;
        }
    }
    if (RXFS_FGI_temp > 0U)
    {
        RXFS_FGI_temp = RXFS_FGI_temp - 1U;
    }
    else
    {
        RXFS_FGI_temp = 0U;
    }

    msg_ptr.direction = RX_DIR;
    ram_word = pCan_rxmsg[RXFS_FGI_temp].RxWord0.R;/* polyspace RTE:IDP,NIV */
    if ((ram_word & MCAN_RX_BUFFER_XTD_MASK) == 0U)
    {
        msg_ptr.idtype = STANDARD_ID;
        msg_ptr.id = (uint32)((ram_word \
                        & MCAN_RX_BUFFER_STD_ID_MASK) >> MCAN_RX_BUFFER_STD_ID_SHIFT);
    }
    else
    {
        msg_ptr.idtype = EXTENDED_ID;
        msg_ptr.id = (ram_word & MCAN_RX_BUFFER_EXT_ID_MASK);
    }
    if ((ram_word & MCAN_RX_BUFFER_RTR_MASK) == 0U)
    {
        msg_ptr.remote = FALSE;
    }
    else
    {
        msg_ptr.remote = TRUE;
    }

    if ((ram_word & MCAN_RX_BUFFER_ESI_MASK) == 0U)
    {
        msg_ptr.esi = FALSE;
    }
    else
    {
        msg_ptr.esi = TRUE;
    }

    ram_word = pCan_rxmsg[RXFS_FGI_temp].RxWord1.R;/* polyspace RTE:NIV */
    msg_ptr.dlc = (uint16)((ram_word \
                              & MCAN_RX_BUFFER_DLC_MASK)>> MCAN_RX_BUFFER_DLC_SHIFT);
    
    if (msg_ptr.dlc > MCAN_ConvertDataLengthCode(paysize))
    {
        msg_ptr.dlc = MCAN_ConvertDataLengthCode(paysize);
    }

    bytes_to_read =  (uint32)MCAN_ConvertDLCToDataLength(msg_ptr.dlc);

    if ((ram_word & MCAN_RX_BUFFER_FDF_MASK) == 0U)
    {
        msg_ptr.fdf = FALSE;
    }
    else
    {
        msg_ptr.fdf = TRUE;
    }

    if ((ram_word & MCAN_RX_BUFFER_BRS_MASK) == 0U)
    {
        msg_ptr.brs = FALSE;
    }
    else
    {
        msg_ptr.brs = TRUE;
    }
    u8Can_HwFilterIdex = (uint8)((ram_word & MCAN_RX_BUFFER_FIDX_MASK) >> MCAN_RX_BUFFER_FIDX_SHIFT);
    msg_ptr.rx_info.rx_timestamp = ram_word & MCAN_RX_BUFFER_RXTS_MASK;

    while(bytes_to_read > 0U)
    {
        ram_word = *(uint32 *)(((uint8*)&pCan_rxmsg[RXFS_FGI_temp].RxDataWord0.R) + (u32Can_Index * 4U));/* polyspace RTE:IDP,NIV */

        byte_index = (u32Can_Index * 4U);
        pCan_DataAddr = (uint32 *)&msg_ptr.data[byte_index];/* PRQA S 2934, 0310 */
        *pCan_DataAddr = ((ram_word >> 24U) & 0xFFU) |    /* PRQA S 2934, 0310 */
                            ((ram_word >> 8U) & 0xFF00U) |
                            ((ram_word << 8U) & 0xFF0000U) |
                            ((ram_word << 24U) & 0xFF000000U);
        if (bytes_to_read >= 4U)
        {
            bytes_to_read = bytes_to_read - 4U;
        }
        else
        {
            bytes_to_read = 0U;
        }

        u32Can_Index++;
    }
    if(msg_ptr.idtype == STANDARD_ID)
    {
        pCan_HwFilterCfg = &g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerId].standardFilterConfig[u8Can_HwFilterIdex];/* polyspace RTE:IDP *//* polyspace RTE:NIP */
    }
    else if(msg_ptr.idtype == EXTENDED_ID) /* PRQA S 2991, 2995 */
    {
        pCan_HwFilterCfg = &g_pCan_CurConfig->hwObjectConfig[u8Can_ControllerId].extendedFilterConfig[u8Can_HwFilterIdex];/* polyspace RTE:IDP,NIP */
    }
    else
    {
        /* do nothing */
    }

    MCAN_RxNotifiy(u8Can_ControllerId, pCan_HwFilterCfg->CanObjectId, &msg_ptr);/* polyspace RTE:NIV,IDP */
}
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
#endif /* RESOURCE_SUPPORT_MCAN_DMU */

#ifdef __cplusplus
}
#endif
