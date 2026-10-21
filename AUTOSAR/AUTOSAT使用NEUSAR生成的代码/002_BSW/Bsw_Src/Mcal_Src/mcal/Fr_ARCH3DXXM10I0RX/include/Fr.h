/* PRQA S 0722,1752 EOF */
/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   Project              : AUTOSAR 4.4.0 MCAL
 *   Platform             : PowerPC e200
 *   Peripheral           :
 *   Dependencies         :
 *
 *   Autosar Version      : 4.4.0
 *   Autosar Revision     : ASR_REL_4_3_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           :
 *   Build Version        :
 *
 *****************************************************************************/

/**
 *   @file    Fr.h
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Fr MCAL driver.
 *
 *   @addtogroup Fr
 *   @{
 */
#ifndef FR_H
#define FR_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Standard AUTOSAR types */

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#define FR_MODULE_ID   188

/*Write verification macros*/
#include "Fr_GeneralTypes.h"
#include "Fr_Cfg.h"
#include "Fr_LLDriver.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_H_VENDOR_ID                        176
#define FR_AR_RELEASE_MAJOR_VERSION           4
#define FR_AR_RELEASE_MINOR_VERSION           4
/* @violates @ref FR_FR_H_REF_2 */
#define FR_H_AR_RELEASE_REVISION_VERSION      0
#define FR_H_SW_MAJOR_VERSION                 3
#define FR_H_SW_MINOR_VERSION                 0
#define FR_H_SW_PATCH_VERSION                 0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_Cfg.h header file are of the same vendor */
#if(FR_CFG_H_VENDOR_ID != FR_H_VENDOR_ID)
    #error "Fr_Cfg.h and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION    != FR_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION    != FR_CFG_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_H_AR_RELEASE_REVISION_VERSION != FR_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Cfg.h and Fr.h are different"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same software version */
#if((FR_H_SW_MAJOR_VERSION != FR_CFG_H_SW_MAJOR_VERSION) || \
    (FR_H_SW_MINOR_VERSION != FR_CFG_H_SW_MINOR_VERSION) || \
    (FR_H_SW_PATCH_VERSION != FR_CFG_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Cfg.h and Fr.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Error reported when parameter timer index exceeds number of available timers
* */
#define FR_E_INV_TIMER_IDX                              ((uint8)0x01U)
/**
* @brief Error reported when invalid pointer in parameter list
* */
#define FR_E_PARAM_POINTER                              ((uint8)0x02U)
/**
* @brief Error reported when parameter offset exceeds bounds  
* */
#define FR_E_INV_OFFSET                                 ((uint8)0x03U)
/**
* @brief Error reported when invalid controller index
* */
#define FR_E_INV_CTRL_IDX                               ((uint8)0x04U)
/**
* @brief Error reported when invalid channel index
* */
#define FR_E_INV_CHNL_IDX                               ((uint8)0x05U)
/**
* @brief Error reported when parameter cycle exceeds 63
* */
#define FR_E_INV_CYCLE                                  ((uint8)0x06U)
/**
* @brief Error reported when Fr module was not initialized
* */
#define FR_E_INIT_FAILED                                ((uint8)0x08U)
/**
* @brief Error reported when Fr CC is not in the expected POC state
* */
#define FR_E_INV_POCSTATE                               ((uint8)0x09U)
/**
* @brief Error reported when Payload length parameter has an invalid value
* */
#define FR_E_INV_LENGTH                                 ((uint8)0x0AU)
/**
* @brief Error reported when invalid LPdu index
* */
#define FR_E_INV_LPDU_IDX                               ((uint8)0x0BU)
/**
* @brief Error reported when invalid FlexRay header CRC
* */
#define FR_E_INV_HEADERCRC                              ((uint8)0x0CU)
/**
* @brief Error reported when invalid value passed as parameter Fr_ConfigParamIdx.
* */
#define FR_E_INV_CONFIG_IDX                             ((uint8)0x0DU)
/**
* @brief Error reported when invalid framelist size value.
* */
#define FR_E_INV_FRAMELIST_SIZE                         ((uint8)0x0EU)
/**
* @brief Error reported when requested resource is not configured to be available
* on the current core
* */
#define FR_E_PARAM_CONFIG                               ((uint8)0x0FU)

/* Service ID for DET reporting */
#define FR_SID_INIT_U8                                  ((uint8)0x1CU)
#define FR_SID_CONTROLLERINIT_U8                        ((uint8)0x00U)
#define FR_SID_STARTCOMMUNICATION_U8                    ((uint8)0x03U)
#define FR_SID_HALTCOMMUNICATION_U8                     ((uint8)0x04U)
#define FR_SID_ABORTCOMMUNICATION_U8                    ((uint8)0x05U)
#define FR_SID_SENDWUP_U8                               ((uint8)0x06U)
#define FR_SID_SETWAKEUPCHANNEL_U8                      ((uint8)0x07U)
#define FR_SID_GETPOCSTATUS_U8                          ((uint8)0x0AU)
#define FR_SID_TRANSMITTXLPDU_U8                        ((uint8)0x0BU)
#define FR_SID_RECEIVERXLPDU_U8                         ((uint8)0x0CU)
#define FR_SID_CHECKTXLPDUSTATUS_U8                     ((uint8)0x0DU)
#define FR_SID_GETGLOBALTIME_U8                         ((uint8)0x10U)
#define FR_SID_SETABSTIMER_U8                           ((uint8)0x11U)
#define FR_SID_CANCELABSTIMER_U8                        ((uint8)0x13U)
#define FR_SID_ENABLEABSTIMERIRQ_U8                     ((uint8)0x15U)
#define FR_SID_ACKABSTIMERIRQ_U8                        ((uint8)0x17U)
#define FR_SID_DISABLEABSTIMERIRQ_U8                    ((uint8)0x19U)
#define FR_SID_GETVERSIONINFO_U8                        ((uint8)0x1BU)
#define FR_SID_PREPARELPDU_U8                           ((uint8)0x1FU)
#define FR_SID_GETABSTIMERIRQSTATUS_U8                  ((uint8)0x20U)
#define FR_SID_GETNMVECTOR_U8                           ((uint8)0x22U)
#define FR_SID_ALLOWCOLDSTART_U8                        ((uint8)0x23U)
#define FR_SID_ALLSLOTS_U8                              ((uint8)0x24U)
#define FR_SID_RECONFIGLPDU_U8                          ((uint8)0x25U)
#define FR_SID_DISABLELPDU_U8                           ((uint8)0x26U)
#define FR_SID_GETNUMOFSTARTUPFRAMES_U8                 ((uint8)0x27U)
#define FR_SID_GETCHANNELSTATUS_U8                      ((uint8)0x28U)
#define FR_SID_GETCLOCKCORRECTION_U8                    ((uint8)0x29U)
#define FR_SID_GETSYNCFRAMELIST_U8                      ((uint8)0x2AU)
#define FR_SID_GETWAKEUPRXSTATUS_U8                     ((uint8)0x2BU)
#define FR_SID_CANCELTXLPDU_U8                          ((uint8)0x2DU)
#define FR_SID_READCCCONFIG_U8                          ((uint8)0x2EU)

#define FR_CORE_NUM                                     MCAL_CORE_NUM

#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
    /* Only if FR_BUFFER_RECONFIG is enabled: */
    /* Array is used for storage of information which virtual message buffer is currently configured
    for the physical message buffer each array element represents one physical MB and stored value
    corresponds with configured virtual MB index.
    Example: VirtualResourceAllocation[15] means that MB with index 15 (MBCCSR15,MBIDX15...) is
    configured for virtual MB with index 26 */
extern VAR(uint16, FR_VAR) Fr_InternalResource[FR_NUM_CTRL_SUPPORTED][FR_NUMBER_MB];
#endif  /* FR_BUFFER_RECONFIG */

typedef enum
{ /* Flexray un-init */
    FR_UNINIT = 0U,
    /* Flexray init */
    FR_INIT         
} Fr_SoftwareStatesType;


#if (FR_PRECOMPILE_SUPPORT == STD_OFF)
FR_PB_CONFIG_DECLARATION
#else
extern const VAR(Fr_ConfigType, AUTOMATIC) Fr_cfg;
#endif

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_Init(
    P2CONST(Fr_ConfigType, AUTOMATIC, FR_APPL_CONST) Fr_ConfigPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_AllSlots(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP(
    VAR(uint8, FR_VAR) Fr_CtrlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_LSduPtr,
    VAR(uint8, FR_VAR) Fr_LSduLength,
    P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelTxLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduLengthPtr,
    P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr,
    P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
    
#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_PrepareLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx,
    VAR(uint16, FR_VAR) Fr_FrameId,
    VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx,
    VAR(uint8, FR_VAR) Fr_CycleRepetition,
    VAR(uint8, FR_VAR) Fr_CycleOffset,
    VAR(uint8, FR_VAR) Fr_PayloadLength,
    VAR(uint16, FR_VAR) Fr_HeaderCRC);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#if (FR_DISABLE_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableLPdu(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_LPduIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#endif
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNumOfStartupFrames(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NumOfStartupFramesPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr,
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncFrameList(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_ListSize,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAOddListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBOddListPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetWakeupRxStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_WakeupRxStatusPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx,
    VAR(uint8, FR_VAR) Fr_Cycle,
    VAR(uint16, FR_VAR) Fr_Offset);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_AbsTimerIdx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#if (FR_VERSION_INFO_API == STD_ON)
    #define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_GetVersionInfo(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FR_APPL_DATA) VersioninfoPtr
    );
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReadCCConfig(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint8, FR_VAR) Fr_ConfigParamIdx,
    P2VAR(uint32, AUTOMATIC, FR_APPL_DATA) Fr_ConfigParamValuePtr);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_InterruptEnable(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_InterruptSource);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(Std_ReturnType, FR_CODE) Fr_InterruptDisable(
    VAR(uint8, FR_VAR) Fr_CtrlIdx,
    VAR(uint16, FR_VAR) Fr_InterruptSource);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
extern FUNC(void, FR_CODE) Fr_Disable_AllInterrupts(void);
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif

#endif /* FR_H */
