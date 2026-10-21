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
*   @file    EthIf_Cbk.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthIf.
*
*   @addtogroup EthIf
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif
/* PRQA S 0380 EOF */
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "EthIf_Cbk.h"
#include "status.h"
#include "cc_printf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETHIF_CBK_C_VENDOR_ID                    176
#define ETHIF_CBK_C_AR_REL_MAJOR_VER             4
#define ETHIF_CBK_C_AR_REL_MINOR_VER             4
#define ETHIF_CBK_C_AR_REL_REV_VER               0
#define ETHIF_CBK_C_SW_MAJOR_VER                 3
#define ETHIF_CBK_C_SW_MINOR_VER                 0
#define ETHIF_CBK_C_SW_PATCH_VER                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHIF_CBK_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHIF_CBK_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHIF_CBK_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHIF_CBK_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHIF_CBK_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHIF_CBK_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHIF_CBK_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_C_SW_PATCH_VER "
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
ETHIF_START_SEC_VAR_NO_INIT
volatile VAR(uint32, AUTOMATIC) Eth_TestFlag;
ETHIF_STOP_SEC_VAR_NO_INIT
ETHIF_START_SEC_VAR_NO_INIT
volatile VAR(uint32, AUTOMATIC) Eth_TestStopFlag; /*PRQA S 1514*/
ETHIF_STOP_SEC_VAR_NO_INIT

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @note           The passed data buffer is no longer valid after the function
*                 is exited.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which received the frame.
* @param[in]      FrameType The received frame Ethertype (from the frame header)
* @param[in]      IsBroadcast The value TRUE indicates that the received frame
*                 was sent to broadcast address (ff-ff-ff-ff-ff-ff)
* @param[in]      PhysAddrPtr Pointer to received frame source MAC address
*                 (6 bytes).
* @param[in]      DataPtr Data buffer containing the received Ethernet frame 
*                 payload.
* @param[in]      LenByte Length of the data in the buffer DataPtr.
*
*/
/*PRQA S 1503,3206 EOF*/
ETHIF_START_SEC_CODE
FUNC(void, ETH_CODE) EthIf_RxIndication \
(\
    VAR(uint8, AUTOMATIC) CtrlIdx,\
    VAR(Eth_FrameType, AUTOMATIC) FrameType, \
    VAR(boolean, AUTOMATIC) IsBroadcast, \
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_CONST) PhysAddrPtr, \
    P2CONST(Eth_DataType, AUTOMATIC, ETHIF_APPL_CONST) DataPtr,\
    VAR(uint16, AUTOMATIC) LenByte \
)
{
    (void)CtrlIdx;
    (void)FrameType;
    (void)IsBroadcast;
    (void)PhysAddrPtr;
    (void)DataPtr;
    Eth_TestStopFlag++;
    if (Eth_TestFlag == 0U)
    {
        VAR(uint32, AUTOMATIC) index;
        ETHIF_PRINTF("CtrlIdx = %d, Eth_FrameType = %04x, IsBroadcast = %x, PhysAddrPtr = 0x%x, pkt_data = 0x%x, pkt_len = %u\r\n", CtrlIdx, FrameType, IsBroadcast, PhysAddrPtr, DataPtr, LenByte);
        for(index = 0U; index < LenByte; index++)
        {
            if(((index % 10U) == 0U) && (index != 0U))
            {
                ETHIF_PRINTF("\r\n");
            }
            ETHIF_PRINTF("0x%02x  ", (DataPtr[index]));
        }
        ETHIF_PRINTF("\r\n\r\n"); /* This is an empty stub function */
    }
    else
    {
        static VAR(uint32, AUTOMATIC) Eth_RxCount = 0U;
        static VAR(uint32, AUTOMATIC) index_j = 1U;
        Eth_RxCount++;
        if (Eth_RxCount == 10000U)
        {
            ETHIF_PRINTF("No.%d 10000 is over\r\n", index_j);
            index_j++;
            Eth_RxCount = 0U;
        }
    }
}
ETHIF_STOP_SEC_CODE

/*================================================================================================*/
/**
* @brief          This function confirms that transmission of an Ethernet frame
*                 was finished.
* @details        Function should notify the appropriate upper layer module that
*                 the data transmission was successfully finished.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which transmitted the frame.
* @param[in]      BufIdx Index of the transmitted data buffer.

*/
ETHIF_START_SEC_CODE
FUNC(void, ETH_CODE) EthIf_TxConfirmation \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) BufIdx, \
    VAR(Std_ReturnType, AUTOMATIC) Result \
)
{
    (void)CtrlIdx;
    (void)BufIdx;
    (void)Result;
    if (Eth_TestFlag == 0U)
    {
        ETHIF_PRINTF("CtrlIdx = %d, BufIdx = %d Result = %d\r\n", CtrlIdx, BufIdx, Result);; /* This is an empty stub function */
    }
    else
    {
        static VAR(uint32, AUTOMATIC) Eth_TxCount = 0U;
        static VAR(uint32, AUTOMATIC) index_tx = 1U;
        Eth_TxCount++;
        if (Eth_TxCount == 10000U)
        {
            ETHIF_PRINTF("No.%d 10000 is over\r\n", index_tx);
            index_tx++;
            Eth_TxCount = 0U;
        }
    }
}
ETHIF_STOP_SEC_CODE
/*================================================================================================*/
/**
* @brief          This function indicate that driver mode has been changed
* @details        Called asynchronously when mode has been read out. Triggered by previous 
*                 Eth_SetControllerMode call. Can directly be called within the trigger functions.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which mode has been changed.
* @param[in]      CtrlMode New mode of correspond Eth driver.

*/
ETHIF_START_SEC_CODE
FUNC(void, ETH_CODE) EthIf_CtrlModeIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
)
{
    (void)CtrlIdx;
    if (CtrlMode == ETH_MODE_DOWN)
    {
        ETHIF_PRINTF("EthIf_CtrlModeIndication mode is ETH_MODE_DOWN\r\n");
    }
    else
    {
        ETHIF_PRINTF("EthIf_CtrlModeIndication mode is ETH_MODE_ACTIVE\r\n");
    }
    /* This is an empty stub function */ 
}
ETHIF_STOP_SEC_CODE

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif
/** @} */
