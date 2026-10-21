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
*   @file    Eth.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/
/* PRQA S 1752 EOF */

#ifndef ETH_H
#define ETH_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Eth.h Version
****************************************************************************************
*/
#define ETH_H_VENDOR_ID                    176
#define ETH_AR_RELEASE_MAJOR_VERSION       4
#define ETH_AR_RELEASE_MINOR_VERSION       4
#define ETH_H_AR_REL_REV_VER               0
#define ETH_H_SW_MAJOR_VER                 3
#define ETH_H_SW_MINOR_VER                 0
#define ETH_H_SW_PATCH_VER                 0
#define ETH_MODULE_ID                      88

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "derivative.h"
#if (defined(RESOURCE_SUPPORT_ETH_EMAC_IP) || defined(RESOURCE_SUPPORT_ETH_GMAC_IP))
#include "ComStack_Types.h"
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
#include "Eth_EMAC_LLDriver.h"
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
#include "Eth_GMAC_LLDriver.h"
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
#include "Eth_Cfg.h"
#include "EthIf_Cbk.h"
#include "Eth_GeneralTypes.h"

/**
****************************************************************************************
 * @brief: Version Verify
****************************************************************************************
*/
#if (ETH_CFG_H_VENDOR_ID != ETH_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : ETH_AR_RELEASE_MAJOR_VERSION "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : ETH_AR_RELEASE_MINOR_VERSION "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_H_SW_PATCH_VER "
#endif
/**
****************************************************************************************
 * @brief: Defines
****************************************************************************************
*/
#define ETH_MAX_FIFONUM 16
#define ETH_DMA_FrameLenShift           16

/* Service IDs definition */
#define ETH_SID_INIT                    0x01
#define ETH_SID_SETCONTROLLERMODE       0x03
#define ETH_SID_GETCONTROLLERMODE       0x04
#define ETH_SID_GETPHYSADDR             0x08
#define ETH_SID_WRITEMII                0x05
#define ETH_SID_READMII                 0x06
#define ETH_SID_PROVIDETXBUFFER         0x09
#define ETH_SID_TRANSMIT                0x0A
#define ETH_SID_RECEIVE                 0x0B
#define ETH_SID_TXCONFIRMATION          0x0C
#define ETH_SID_GETVERSIONINFO          0x0D
#define ETH_SID_SETPHYSADDR             0x13
#define ETH_SID_UPDATEADDRFILTER        0x12
#define ETH_SID_GETCURRENTTIME          0x16
#define ETH_SID_ENABLEEGRESSTIMESTAMP   0x17
#define ETH_SID_GETEGRESSTIMESTAMP      0x18
#define ETH_SID_GETINGRESSTIMESTAMP     0x19
#define ETH_SID_GETCOUNTERVALUES        0x14
#define ETH_SID_GETRXSTATS              0x15
#define ETH_SID_GETTXSTATS              0x1C
#define ETH_SID_GETTXERRORCOUNTERVALUES 0x1D

/* DET error codes */
#if STD_ON == ETH_DEV_ERROR_DETECT
#define ETH_E_INV_CTRL_IDX      ((uint8)0x01)
#define ETH_E_UNINIT            ((uint8)0x02)
#define ETH_E_PARAM_POINTER     ((uint8)0x03)
#define ETH_E_INV_PARAM         ((uint8)0x04)
#define ETH_E_INV_MODE          ((uint8)0x05)
#define ETH_E_PARAM_CONFIG      ((uint8)0x06)
#endif /* ETH_DEV_ERROR_DETECT */

/* DEM error codes */
#define ETH_E_ACCESS                 ((uint8)0x00)
#define ETH_E_ALIGNMENT              ((uint8)0x01)
#define ETH_E_CRC                    ((uint8)0x02)
#define ETH_E_LATECOLLISION          ((uint8)0x03)
#define ETH_E_MULTIPLECOLLISION      ((uint8)0x04)
#define ETH_E_OVERSIZEFRAME          ((uint8)0x05)
#define ETH_E_RX_FRAMES_LOST         ((uint8)0x06)
#define ETH_E_SINGLECOLLISION        ((uint8)0x07)
#define ETH_E_UNDERSIZEFRAME         ((uint8)0x08)

#define ETH_DEM_ERROR_MAX (0x09U)

#if STD_ON == ETH_MULTICORE_ENABLED
    #define Eth_GetCoreID()       GetCoreID()
#else
    #define Eth_GetCoreID()       ((uint32)ETH_DEFAULT_COREID)
#endif /* ETH_MULTICORE_ENABLED */

#define ETH_CORE_NUM                    MCAL_CORE_NUM
/**
****************************************************************************************
 * @brief: struct and other typedefs
****************************************************************************************
*/

typedef struct
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    VAR(DwmacId, AUTOMATIC) dwmac_id;
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    VAR(GmacId, AUTOMATIC) gmac_id;
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
    CONST(uint32, ETH_CONST) CoreId;
} Eth_core_map_t;

typedef struct
{
#ifdef RESOURCE_SUPPORT_ETH_EMAC_IP
    P2CONST(DwmacCfg, AUTOMATIC, ETH_APPL_CONST) pController;
#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP */
#ifdef RESOURCE_SUPPORT_ETH_GMAC_IP
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) pController;
#endif /* RESOURCE_SUPPORT_ETH_GMAC_IP */
#if STD_ON == ETH_MULTICORE_ENABLED
    P2CONST(Eth_core_map_t, ETH_CONST, ETH_APPL_CONST) pEth_CoreMap;
#endif /* ETH_MULTICORE_ENABLED */
} Eth_ConfigType;

//arain add start
/* @brief: This parameter shall represent the Eth dem error type */
typedef struct
{
    /* @brief: This parameter shall represent the enabling/disabling the DEM error */
    VAR(uint32, AUTOMATIC) state;
    /* @brief: This parameter shall represent the ID of DEM error (0 if STD_OFF) */
    VAR(uint32, AUTOMATIC) id ;
} Eth_DemErrorType;

/**
****************************************************************************************
 * @brief: Global Variable Declarations
****************************************************************************************
*/
extern VAR(volatile Eth_ModeType, ETH_VAR) Eth_Ctrlmode[ETH_MAXCTRLS_SUPPORTED];
extern VAR(volatile Eth_StateType, ETH_VAR) Eth_CtrlState[ETH_MAXCTRLS_SUPPORTED];
extern P2CONST(Eth_ConfigType, ETH_VAR, ETH_APPL_CONST) Eth_InternalCfgPtr;

#if (ETH_DEM_EVENT_DETECT == STD_ON)
extern CONST(Eth_DemErrorType, ETH_CONST) Eth_DemErr_Ctrl[ETH_MAXCTRLS_SUPPORTED][ETH_DEM_ERROR_MAX];
#endif /* ETH_DEM_EVENT_DETECT */

#if (ETH_PRECOMPILE_SUPPORT == STD_OFF)
ETH_PB_CONFIG_DECLARATION
#else
extern CONST(Eth_ConfigType, ETH_CONST) Eth_Config;
#endif /* ETH_PRECOMPILE_SUPPORT */
/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Init(P2CONST(Eth_ConfigType, AUTOMATIC, ETH_APPL_CONST) CfgPtr);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_GetControllerMode \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_DATA) CtrlModePtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_GetPhysAddr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_SetPhysAddr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_UpdatePhysAddrFilter \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr, \
    VAR(Eth_FilterActionType, AUTOMATIC) Action \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
#if STD_ON == ETH_CTRLENABLE_MII
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_WriteMii \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    VAR(uint16, AUTOMATIC) RegVal \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_ReadMii \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) RegValPtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_CTRLENABLE_MII */
#if STD_ON == ETH_GET_COUNTVAL_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_GetCounterValues \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) CounterPtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_COUNTVAL_API */
#if STD_ON == ETH_GET_RXSTATS_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_GetRxStats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) RxStats \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_RXSTATS_API */
#if STD_ON == ETH_GET_TXSTATS_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_GetTxStats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) TxStats \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_TXSTATS_API */
#if STD_ON == ETH_GET_TXERRORCOUNT_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_GetTxErrorCounterValues \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) TxErrorCounterValues \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_TXERRORCOUNT_API */
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(BufReq_ReturnType, ETH_CODE) Eth_ProvideTxBuffer \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) Priority, \
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) BufIdxPtr, \
    P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) BufPtr, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LenBytePtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(Std_ReturnType, ETH_CODE) Eth_Transmit \
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
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_Receive \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) FifoIdx, \
    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_DATA) RxStatusPtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_TxConfirmation(VAR(uint8, AUTOMATIC) CtrlIdx);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#if STD_ON == ETH_GET_VERSION_INFO_API
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, ETH_APPL_DATA) VersionInfoPtr \
);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"
#endif /* ETH_GET_VERSION_INFO_API */
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"
FUNC(void, ETH_CODE) Eth_MainFunction(void);
#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#endif /* RESOURCE_SUPPORT_ETH_EMAC_IP || RESOURCE_SUPPORT_ETH_GMAC_IP */

#ifdef __cplusplus
}
#endif

#endif /* ETH_H */
