/*PRQA S 0380, 3432 EOF*/
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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*  
*****************************************************************************/

/**
*   @file    EthSwt.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthSwt
*
*   @addtogroup EthSwt
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
/*EthSwt.h includes Eth.h which includes Eth_GeneralTypes.h*/
#include "EthSwt.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define ETHSWT_C_VENDOR_ID                    176
#define ETHSWT_C_AR_REL_MAJOR_VER             4
#define ETHSWT_C_AR_REL_MINOR_VER             4
#define ETHSWT_C_AR_REL_REV_VER               0
#define ETHSWT_C_SW_MAJOR_VER                 3
#define ETHSWT_C_SW_MINOR_VER                 0
#define ETHSWT_C_SW_PATCH_VER                 0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if (ETH_CFG_H_VENDOR_ID != ETHSWT_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHSWT_C_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHSWT_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_C_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHSWT_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_C_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHSWT_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHSWT_C_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHSWT_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_C_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHSWT_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_C_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHSWT_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHSWT_C_SW_PATCH_VER "
#endif

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/



/*==================================================================================================
                                        LOCAL FUNCTION
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/



/*======================================================================================================*/
/**
* @brief EthSwt_EthRxProcessFrame - Function inspects the Ethernet frame passed by the data pointer for
                                    management information and stores it for later use in
                                    EthSwt_EthRxFinishedIndication().Function which inserts management information
                                    into the Ethernet frame.

* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   DataPtr        IN: Pointer to the position of the EtherType of a common Ethernet frame
*                                OUT: Pointer to the position of the EtherType in the management frame
*                 LengthPtr      IN: Pointer to the length of the frame rececived
*                                OUT: Pointer to the length decreased by the management information length
*
* @param[out]     IsMgmtFrameOnlyPtr    Information about the kind of frame
*                                       FALSE: Frame is not only for management purpose, but
*                                              also for normal communication.
*                                       TRUE: Frame is only for management purpose and must
*                                              not be processed in common receive process
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91004
*/
/*======================================================================================================*/
ETHSWT_START_SEC_CODE
FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthRxProcessFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                            VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, 
                                                            P2P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr, 
                                                            P2VAR(uint16, AUTOMATIC, AUTOMATIC) LengthPtr, 
                                                            P2VAR(boolean, AUTOMATIC, AUTOMATIC) IsMgmtFrameOnlyPtr
                                                          )
{
    VAR(Std_ReturnType, AUTOMATIC)  checkStatus                         = (Std_ReturnType)E_OK;
    (void) CtrlIdx;
    (void) BufIdx;
    (void) DataPtr;
    (void) LengthPtr;
    (void) IsMgmtFrameOnlyPtr;
    return (Std_ReturnType) checkStatus;
}
ETHSWT_STOP_SEC_CODE


/*======================================================================================================*/
/**
* @brief EthSwt_EthRxFinishedIndication - Indication for a finished receive process for a specific Ethernet frame,
*                                  which results in providing the management information retrieved
*                                  during EthSwt_EthRxProcessFrame().
*
* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   NONE
*
* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91005
*/
/*======================================================================================================*/
ETHSWT_START_SEC_CODE
FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthRxFinishedIndication( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                                   VAR(Eth_BufIdxType, AUTOMATIC) BufIdx
                                                                 )
{
    VAR(Std_ReturnType, AUTOMATIC)  checkStatus                         = (Std_ReturnType)E_OK;
    (void) CtrlIdx;
    (void) BufIdx;
    return (Std_ReturnType) checkStatus;
}
ETHSWT_STOP_SEC_CODE


/*======================================================================================================*/
/**
* @brief EthSwt_EthTxPrepareFrame - Prepares the Ethernet frame for common Ethernet communication
*                                    (frame shall be handled by switch according to the common address
*                                    resolution behavior) and stores the information for processing of
*                                    EthSwt_EthTxFinishedIndication()
*
* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   DataPtr        IN: Pointer to the position of the EtherType of a common Ethernet frame
*                                OUT: Pointer to the position of the EtherType in the management frame
*                 LengthPtr      IN: Pointer to the length of the buffer without management information
*                                OUT: Pointer to the modified length needed for buffer and management information
* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91006
*/
/*======================================================================================================*/
ETHSWT_START_SEC_CODE
FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxPrepareFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                             VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
                                                             P2P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr, 
                                                             P2VAR(uint16, AUTOMATIC, AUTOMATIC) LengthPtr
                                                           )
{
    VAR(Std_ReturnType, AUTOMATIC)  checkStatus                         = (Std_ReturnType)E_OK;
    (void) CtrlIdx;
    (void) BufIdx;
    (void) DataPtr;
    (void) LengthPtr;
    return (Std_ReturnType) checkStatus;
}
ETHSWT_STOP_SEC_CODE


/*======================================================================================================*/
/**
* @brief EthSwt_EthTxAdaptBufferLength - Modifies the buffer length to be able to insert management
*                                        information
*
* @details This is a function stub only. 
*     
* @param[in]      NONE
*
* @param[inout]   LengthPtr      IN: Pointer to the length of the buffer without management information
*                                OUT: Pointer to the modified length needed for buffer and management information
* @param[out]     NONE
*
* @return         NONE
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91007
*/
/*======================================================================================================*/
ETHSWT_START_SEC_CODE
FUNC( void, ETHSWT_CODE) EthSwt_EthTxAdaptBufferLength( P2VAR(uint16, AUTOMATIC, AUTOMATIC) LengthPtr)
{
    (void) LengthPtr;
}
ETHSWT_STOP_SEC_CODE


/*======================================================================================================*/
/**
* @brief EthSwt_EthTxProcessFrame - Function which inserts management information into the Ethernet frame.

* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   DataPtr        IN: Pointer to the position of the EtherType of a common Ethernet frame
*                                OUT: Pointer to the position of the EtherType in the management frame
*                 LengthPtr      IN: Pointer to the length of the received frame
*                                OUT: Pointer to the length decreased by the management information length
* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91009
*/
/*======================================================================================================*/
ETHSWT_START_SEC_CODE
FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxProcessFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                             VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, 
                                                             P2P2VAR(uint8, AUTOMATIC, AUTOMATIC) DataPtr, 
                                                             P2VAR(uint16, AUTOMATIC, AUTOMATIC) LengthPtr
                                                           )
{
    VAR(Std_ReturnType, AUTOMATIC)  checkStatus                         = (Std_ReturnType)E_OK;
    (void) CtrlIdx;
    (void) BufIdx;
    (void) DataPtr;
    (void) LengthPtr;
    return (Std_ReturnType) checkStatus;
}
ETHSWT_STOP_SEC_CODE
/*======================================================================================================*/
/**
* @brief EthSwt_EthTxFinishedIndication - Indication for a finished transmit process for a specific Ethernet
*                                         frame
*
* @details This is a function stub only. 
*     
* @param[in]      CtrlIdx        Ethernet Controller index
*                 BufIdx         Ethernet Rx Buffer index 
*
* @param[inout]   NONE

* @param[out]     NONE
*
* @return         E_OK/E_NOT_OK  Result of the operation
*
* @Requirements SWS_Eth_00120, SWS_EthSwt_91010
*/
/*======================================================================================================*/
ETHSWT_START_SEC_CODE
FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxFinishedIndication( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                                   VAR(Eth_BufIdxType, AUTOMATIC) BufIdx
                                                                 )
{
    VAR(Std_ReturnType, AUTOMATIC)  checkStatus                         = (Std_ReturnType)E_OK;
    (void) CtrlIdx;
    (void) BufIdx;
    return (Std_ReturnType) checkStatus;
}
ETHSWT_STOP_SEC_CODE

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif

/** @} */
