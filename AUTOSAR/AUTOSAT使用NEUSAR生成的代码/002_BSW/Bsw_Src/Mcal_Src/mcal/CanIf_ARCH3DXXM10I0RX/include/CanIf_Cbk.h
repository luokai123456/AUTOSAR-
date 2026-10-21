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
*   @file    CanIf_Cbk.h
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanIf
*
*   @addtogroup CanIf
*   @{
*/

#ifndef CANIF_CBK_H
#define CANIF_CBK_H

#ifdef  __cplusplus
extern "C"
{
#endif
#include "CanIf_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CBK_VENDOR_ID                         176
#define CANIF_CBK_MODULE_ID                         60
#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION          4
#define CANIF_CBK_AR_RELEASE_REVISION_VERSION       0
#define CANIF_CBK_SW_MAJOR_VERSION                  3
#define CANIF_CBK_SW_MINOR_VERSION                  0
#define CANIF_CBK_SW_PATCH_VERSION                  0

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define CANIF_START_SEC_CONFIG_DATA           __attribute__((section(".mcal_canif_rodata")))
#define CANIF_STOP_SEC_CONFIG_DATA
#define CANIF_START_SEC_CODE                  __attribute__((section(".mcal_canif_text")))
#define CANIF_STOP_SEC_CODE
#define CANIF_START_SEC_VAR_NO_INIT           __attribute__((section(".mcal_canif_bss")))
#define CANIF_STOP_SEC_VAR_NO_INIT
#define CANIF_START_SEC_VAR_INIT              __attribute__((section(".mcal_canif_data")))
#define CANIF_STOP_SEC_VAR_INIT
#define CANIF_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_canif_share")))
#define CANIF_STOP_SEC_VAR_SHARED_INIT
#define CANIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_canif_bss_share")))
#define CANIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CANIF_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_canif_rodata")
#define CANIF_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define CANIF_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_canif_text")
#define CANIF_STOP_SEC_CODE                   PRAGMA(ghs section)
#define CANIF_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_canif_bss")
#define CANIF_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define CANIF_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_canif_data")
#define CANIF_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define CANIF_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_canif_share")))
#define CANIF_STOP_SEC_VAR_SHARED_INIT
#define CANIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_canif_bss_share")))
#define CANIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CANIF_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_canif_rodata" a)
#define CANIF_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define CANIF_START_SEC_CODE                  PRAGMA(section ".mcal_canif_text" avx)
#define CANIF_STOP_SEC_CODE                   PRAGMA(section)
#define CANIF_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_canif_bss")
#define CANIF_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define CANIF_START_SEC_VAR_INIT              PRAGMA(section ".mcal_canif_data")
#define CANIF_STOP_SEC_VAR_INIT               PRAGMA(section)
#define CANIF_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_canif_share")
#define CANIF_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define CANIF_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_canif_bss_share")
#define CANIF_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define CANIF_START_SEC_CONFIG_DATA
#define CANIF_STOP_SEC_CONFIG_DATA
#define CANIF_START_SEC_CODE
#define CANIF_STOP_SEC_CODE
#define CANIF_START_SEC_VAR_NO_INIT
#define CANIF_STOP_SEC_VAR_NO_INIT
#define CANIF_START_SEC_VAR_INIT
#define CANIF_STOP_SEC_VAR_INIT
#define CANIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define CANIF_STOP_SEC_VAR_SHARED_INIT
#define CANIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define CANIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CANIF_START_SEC_CONFIG_DATA
#define CANIF_STOP_SEC_CONFIG_DATA
#define CANIF_START_SEC_CODE
#define CANIF_STOP_SEC_CODE
#define CANIF_START_SEC_VAR_NO_INIT
#define CANIF_STOP_SEC_VAR_NO_INIT
#define CANIF_START_SEC_VAR_INIT
#define CANIF_STOP_SEC_VAR_INIT
#define CANIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define CANIF_STOP_SEC_VAR_SHARED_INIT
#define CANIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define CANIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CANIF_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define CANIF_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define CANIF_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define CANIF_STOP_SEC_CODE                   PRAGMA(section)
#define CANIF_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define CANIF_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define CANIF_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define CANIF_STOP_SEC_VAR_INIT               PRAGMA(section)
#define CANIF_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define CANIF_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define CANIF_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define CANIF_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */


CANIF_START_SEC_CODE
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(VAR(PduIdType, CANIF_VAR) CanTxPduId);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(void, CANIF_CODE) CanIf_RxIndication \
( \
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_CONST) Mailbox, \
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr \
);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(VAR(uint8, CANIF_VAR) ControllerId);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication \
( \
    VAR(uint8, CANIF_VAR) ControllerId, \
    VAR(Can_ControllerStateType, CANIF_VAR) ControllerMode \
);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit \
( \
    VAR(PduIdType, CANIF_VAR) TxPduId, \
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr \
);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(boolean, COM_APPL_CODE) Can_LPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) Hrh, \
    VAR(Can_IdType, AUTOMATIC) CanId, \
    VAR(uint8, AUTOMATIC) CanDlc, \
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_CONST) CanSduPtr \
);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(void,CAN_CODE) CallBack_ErrorController(void);
CANIF_STOP_SEC_CODE

CANIF_START_SEC_CODE
FUNC(void,CAN_CODE) CallBack_MRAFN(void);
CANIF_STOP_SEC_CODE


#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_CBK_H */

/** @} */

