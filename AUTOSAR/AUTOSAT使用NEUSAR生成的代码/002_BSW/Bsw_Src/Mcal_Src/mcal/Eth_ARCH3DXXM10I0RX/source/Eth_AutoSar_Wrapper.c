/* PRQA S 0380, 3432, 1258 EOF */
/* PRQA S 0491, 0492, 2844 EOF */   /* CWE */
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
*   @file    Eth_AutoSar_Wrapper.c
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
#include "Eth_AutoSar_Wrapper.h"
#include "Eth_HAL_Wrapper.h"
#if STD_ON == ETH_DEV_ERROR_DETECT
#include "Det.h"
#endif /* ETH_DEV_ERROR_DETECT */
#if STD_ON == ETH_DEM_EVENT_DETECT
#include "Dem.h"
#endif /* ETH_DEM_EVENT_DETECT */

#define ETH_ATS_WRA_C_VENDOR_ID                     176
#define ETH_ATS_WRA_C_AR_REL_MAJOR_VER              4
#define ETH_ATS_WRA_C_AR_REL_MINOR_VER              4
#define ETH_ATS_WRA_C_AR_REL_REV_VER                0
#define ETH_ATS_WRA_C_SW_MAJOR_VER                  3
#define ETH_ATS_WRA_C_SW_MINOR_VER                  0
#define ETH_ATS_WRA_C_SW_PATCH_VER                  0

#if (ETH_CFG_H_VENDOR_ID != ETH_ATS_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_ATS_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_ATS_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_ATS_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_ATS_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_ATS_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_ATS_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_C_SW_PATCH_VER "
#endif

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_InitController \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx \
)
{
    if ((uint32)CtrlIdx < ETH_MAXCTRLS_SUPPORTED)
    {
        Eth_Ctrlmode[CtrlIdx] = ETH_MODE_DOWN;
        Eth_CtrlState[CtrlIdx] = ETH_STATE_UNINIT;
        /*  Check whether the controller is available */
        if ((boolean)TRUE == Eth_Wrapper_CheckAccessToController(CtrlIdx))
        {
            if (STATUS_SUCCESS == Eth_Wrapper_InitController(CtrlIdx))
            {
                Eth_CtrlState[CtrlIdx] = ETH_STATE_INIT;
#if (STD_ON == ETH_DEM_EVENT_DETECT)
                if(STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREPASSED);
                }
#endif /* ETH_DEM_EVENT_DETECT */
            }
            else
            {
                Eth_CtrlState[CtrlIdx] = ETH_STATE_UNINIT;
#if (STD_ON == ETH_DEM_EVENT_DETECT)
                if(STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
                {
                    (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREFAILED);
                }
#endif /* ETH_DEM_EVENT_DETECT */
            }
        }
        else
        {
            Eth_CtrlState[CtrlIdx] = ETH_STATE_UNINIT;
#if (STD_ON == ETH_DEM_EVENT_DETECT)
            if(STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
            {
                (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREFAILED);
            }
#endif /* ETH_DEM_EVENT_DETECT */
        }
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_AutoSar_Wrapper_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Eth_ret = E_NOT_OK;

    if (ETH_MODE_ACTIVE == CtrlMode)
    {
        Eth_Wrapper_Enable_Controller(CtrlIdx);
        Eth_Ctrlmode[CtrlIdx] = ETH_MODE_ACTIVE;
    }
    else
    {
        Eth_Wrapper_Disable_Controller(CtrlIdx);
        Eth_Wrapper_ConfigureBuffer(CtrlIdx);
        Eth_Ctrlmode[CtrlIdx] = ETH_MODE_DOWN;
    }

    if ((boolean)TRUE == Eth_Wrapper_CheckAccessToController(CtrlIdx))
    {
#if (STD_ON == ETH_DEM_EVENT_DETECT)
        if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREPASSED);
        }
#endif /* ETH_DEM_EVENT_DETECT */
        u8Eth_ret = (Std_ReturnType)E_OK;
    }
    else
    {
#if (STD_ON == ETH_DEM_EVENT_DETECT)
        if (STD_ON == Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].state)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Eth_DemErr_Ctrl[CtrlIdx][ETH_E_ACCESS].id, DEM_EVENT_STATUS_PREFAILED);
        }
#endif /* ETH_DEM_EVENT_DETECT */
        u8Eth_ret = (Std_ReturnType)E_NOT_OK;
    }
    return u8Eth_ret;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetControllerMode \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_DATA) CtrlModePtr \
)
{
    if (Eth_Ctrlmode[CtrlIdx] == ETH_MODE_DOWN)
    {
        *CtrlModePtr = ETH_MODE_DOWN;
    }
    else
    {
        *CtrlModePtr = ETH_MODE_ACTIVE;
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetPhysAddr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr \
)
{
    VAR(uint32, AUTOMATIC) u32AddressHolder; /* Used to hold the address value */

    if (CtrlIdx < (uint8)ETH_MAXCTRLS_SUPPORTED)
    { /* Get the first four bytes of the address */
        u32AddressHolder = Eth_Wrapper_Get_Phys_Address_Low(CtrlIdx);

        PhysAddrPtr[0U] = (uint8)(u32AddressHolder & 0xFFU);
        u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */

        PhysAddrPtr[1U] = (uint8)(u32AddressHolder & 0xFFU);
        u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */

        PhysAddrPtr[2U] = (uint8)(u32AddressHolder & 0xFFU);
        u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */
        /* Store the MSB */
        PhysAddrPtr[3U] = (uint8)(u32AddressHolder & 0xFFU); /*PRQA S 2985*/
        /* Get the last two bytes of the address */
        u32AddressHolder = Eth_Wrapper_Get_Phys_Address_High(CtrlIdx);

        PhysAddrPtr[4U] = (uint8)(u32AddressHolder & 0xFFU);
        u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */
        /* Store the MSB */

        PhysAddrPtr[5U] = (uint8)(u32AddressHolder & 0xFFU); /*PRQA S 2985*/
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_SetPhysAddr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr \
)
{
    (void)Eth_Wrapper_Set_Phys_Addr(CtrlIdx, PhysAddrPtr);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_UpdatePhysAddrFilter \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr, \
    VAR(Eth_FilterActionType, AUTOMATIC) Action \
)
{
    Eth_Wrapper_Update_Phys_Addr_Filter(CtrlIdx, PhysAddrPtr, Action);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#if STD_ON == ETH_CTRLENABLE_MII
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_AutoSar_Wrapper_WriteMii \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    VAR(uint16, AUTOMATIC) RegVal \
)
{
    return Eth_Wrapper_Mii_Write_Reg(CtrlIdx, TrcvIdx, RegIdx, RegVal);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(boolean, ETH_CODE) Eth_AutoSar_Wrapper_ReadMii \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) RegValPtr \
)
{
    return Eth_Wrapper_Mii_Read_Reg(CtrlIdx, TrcvIdx, RegIdx, RegValPtr);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_CTRLENABLE_MII */

#if STD_ON == ETH_GET_COUNTVAL_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetCounterValues \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) CounterPtr \
)
{
    Eth_Wrapper_Get_Counter_Values(CtrlIdx, CounterPtr);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_COUNTVAL_API */

#if STD_ON == ETH_GET_RXSTATS_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetRxStats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) RxStats \
)
{
    Eth_Wrapper_Get_Rx_Stats(CtrlIdx, RxStats);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_RXSTATS_API */

#if STD_ON == ETH_GET_TXSTATS_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetTxStats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) TxStats \
)
{
    Eth_Wrapper_Get_Tx_Stats(CtrlIdx, TxStats);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_TXSTATS_API */

#if STD_ON == ETH_GET_TXERRORCOUNT_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetTxErrorCounterValues \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) TxErrorCounterValues \
)
{
    Eth_Wrapper_Get_Tx_Err_Cnt_Val(CtrlIdx, TxErrorCounterValues);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_TXERRORCOUNT_API */

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(BufReq_ReturnType, ETH_CODE) Eth_AutoSar_Wrapper_ProvideTxBuffer \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) Priority, \
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) BufIdxPtr, \
    P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) BufPtr, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LenBytePtr \
)
{
    /* Variable used to track function success status */
    VAR(BufReq_ReturnType, AUTOMATIC) eFunctionSuccess = BUFREQ_E_NOT_OK;
    /* reserve 14 bytes for ethnet fream header */
    VAR(uint16, AUTOMATIC) u16TempLenByte; /* Avoid changes of input
                                              parameters in case of an error */
    VAR(uint32, AUTOMATIC) u32MaxLenByte; /* Maximum available buffer length that
                                              drivers can provide*/
    VAR(uint8, AUTOMATIC) u8QueueIdx;
    VAR(uint16, AUTOMATIC) u16LenByte;
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    P2CONST(DwmacCfg, AUTOMATIC, ETH_APPL_CONST) pCtrl = NULL_PTR;
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) pCtrl = NULL_PTR;
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
    VAR(uint8, AUTOMATIC) u8TotalBuf;
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
    VAR(uint16, AUTOMATIC) u16MangamentLength; /* Management information length which is added to frame */
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
    if (Priority < ETH_MAX_TX_PRIO_NUM)
    {
        u8QueueIdx = 0U;
        pCtrl = &Eth_InternalCfgPtr->pController[CtrlIdx];/* polyspace RTE:IDP */
        /* Check whether the requested length is greater than
        maximal configured one */
        u16LenByte = (uint16)(pCtrl->egress_cfg->EthCtrlConfigEgressFifoBufLenByte); /* polyspace RTE:NIV,NIP,IDP */
#if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
        u8TotalBuf = (uint8)(pCtrl->buf_cfg.tx_ring_cnt);
        u32MaxLenByte = (uint32)((uint32)((uint32)u8TotalBuf * (uint32)u16LenByte) - (uint32)14U);
#else
        u32MaxLenByte = (uint32)((uint32)u16LenByte - (uint32)14U);
#endif /* ETH_USE_MULTIBUFFER_TX_FRAMES */
#if (STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API)
        u16MangamentLength = *LenBytePtr;
        /*Because there're management information which is inserted so size of buffer need be increased.*/
        /* @violates @ref Eth_c_REF_4 */
        pCtrl->Eth_EthSwtDriverFunctionList.TxAdaptBufferLengthFunction(LenBytePtr);
        /*Calculate management information length*/
        u16MangamentLength = *LenBytePtr - u16MangamentLength;
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
        if (*LenBytePtr > u32MaxLenByte)
        {
            /* Requested size is too long, do not lock buffer */
            /* Set length to maximal available payload length */
            *LenBytePtr = (uint16)u32MaxLenByte;
            eFunctionSuccess = BUFREQ_E_OVFL;
        }
        else
        {   /* Good, the requested size fits into buffer size */
            /* Get some space to put data in, check success */
            u16TempLenByte = *LenBytePtr;
#if STD_ON == ETH_SWT_MANAGEMENT_SUPPORT_API
            /* @violates @ref Eth_c_REF_4 */
            if (((boolean)TRUE) == Eth_Wrapper_Borrow_Tx_Buffer(pCtrl, u8QueueIdx, BufIdxPtr, BufPtr, &u16TempLenByte, u16MangamentLength))
#else
            /* @violates @ref Eth_c_REF_4 */
            if (((boolean)TRUE) == Eth_Wrapper_Borrow_Tx_Buffer(pCtrl, u8QueueIdx, BufIdxPtr, BufPtr, &u16TempLenByte))
#endif /* ETH_SWT_MANAGEMENT_SUPPORT_API */
            {
                /* Data space is available */
                /*Return valid value of payload field*/
                *LenBytePtr = u16TempLenByte;
                eFunctionSuccess = BUFREQ_OK;
            }
            else
            { /* Data space is not available */
                eFunctionSuccess = BUFREQ_E_BUSY;
            }
        }
    }

    return eFunctionSuccess;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_AutoSar_Wrapper_Transmit \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, \
    VAR(Eth_FrameType, AUTOMATIC) FrameType, \
    VAR(boolean, AUTOMATIC) TxConfirmation, \
    VAR(uint16, AUTOMATIC) LenByte, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr
#if STD_ON == ETH_BRIDGE_SUPPORT
    , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysSourceAddrPtr
#endif /* ETH_BRIDGE_SUPPORT  */
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8FunctionSuccess = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8Eth_FifoIdx = 0U;

    if ((boolean)TRUE == Eth_Wrapper_Is_Tx_Buf_Locked_BT(CtrlIdx, u8Eth_FifoIdx, BufIdx))
    {
        Eth_Wrapper_Send_Msg(CtrlIdx, u8Eth_FifoIdx, BufIdx, FrameType, LenByte, TxConfirmation, PhysAddrPtr
#if STD_ON == ETH_BRIDGE_SUPPORT
                                , PhysSourceAddrPtr
#endif /* ETH_BRIDGE_SUPPORT  */
                            );
        u8FunctionSuccess = (Std_ReturnType)E_OK;
    }
    else
    {
#if STD_ON == ETH_DEV_ERROR_DETECT
        (void)Det_ReportError ( \
            (uint8) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (uint8) \
            ETH_SID_TRANSMIT, ETH_E_INV_PARAM \
                                );
#endif /* ETH_DEV_ERROR_DETECT  */
        u8FunctionSuccess = (Std_ReturnType)E_NOT_OK;
    }

    return u8FunctionSuccess;
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_Receive \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) FifoIdx, \
    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_DATA) RxStatusPtr \
)
{
    if ((boolean)FALSE == Eth_InternalCfgPtr->pController[CtrlIdx].EnableRxInterrupt) /* polyspace RTE:NIV,IDP */
    {
        *RxStatusPtr = Eth_Wrapper_Report_Reception(CtrlIdx, FifoIdx, (boolean)FALSE);
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Eth_ModeType, ETH_CODE) Eth_AutoSar_Wrapper_Check_Ctrl_Is_Active \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx \
)
{
    return Eth_Wrapper_Check_Ctrl_Is_Active(CtrlIdx);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_TxConfirmation \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) u8Eth_FifoIdx \
)
{
    Eth_Wrapper_Report_Transmission(CtrlIdx, u8Eth_FifoIdx);
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_MainFunction(void)
{
    static VAR(Eth_ModeType, AUTOMATIC) Enet_Mode_status[ETH_MAXCTRLS_SUPPORTED]={ETH_MODE_DOWN};
    VAR(Eth_ModeType, AUTOMATIC) eCurrentMode;
    VAR(uint8, AUTOMATIC) u8EthIfCtrlIdx;
    VAR(uint8, AUTOMATIC) u8CtrlIdx;

    for (u8CtrlIdx = 0U; u8CtrlIdx < ETH_MAXCTRLS_SUPPORTED; u8CtrlIdx++) /*PRQA S 2877*/
    {
        u8EthIfCtrlIdx = u8CtrlIdx;

        eCurrentMode = Eth_Wrapper_Check_Ctrl_Is_Active(u8CtrlIdx);

        if (Enet_Mode_status[u8CtrlIdx] != eCurrentMode)
        {
            Enet_Mode_status[u8CtrlIdx] = eCurrentMode;
            EthIf_CtrlModeIndication(u8EthIfCtrlIdx, eCurrentMode);
        }
#if (ETH_DEM_EVENT_DETECT == STD_ON)
        Eth_Wrapper_EventStatus(u8CtrlIdx);
#endif /* ETH_DEM_EVENT_DETECT */
    }
}
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif
