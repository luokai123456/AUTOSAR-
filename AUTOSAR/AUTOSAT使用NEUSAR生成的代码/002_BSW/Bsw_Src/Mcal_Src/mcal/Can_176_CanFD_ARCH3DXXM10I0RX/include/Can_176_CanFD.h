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
*   @file    Can_176_CanFD.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CanFd MCAL driver.
*
*   @addtogroup CanFd
*   @{
*/
/* PRQA S 0779 EOF */
#ifndef CAN_176_CANFD_H
#define CAN_176_CANFD_H

#ifdef __cplusplus
extern "C"{
#endif

#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "Mcal.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP
#include "Can_176_CanFD_Cfg.h"

#define CAN_176_CANFD_H_VENDOR_ID                     176
#define CAN_176_CANFD_H_AR_REL_MAJOR_VER              4
#define CAN_176_CANFD_H_AR_REL_MINOR_VER              4
#define CAN_176_CANFD_H_AR_REL_REV_VER                0
#define CAN_176_CANFD_H_SW_MAJOR_VER                  3
#define CAN_176_CANFD_H_SW_MINOR_VER                  0
#define CAN_176_CANFD_H_SW_PATCH_VER                  0
#define CAN_176_CANFD_MODULE_ID                       80

#if (CAN_176_CANFD_CFG_H_VENDOR_ID != CAN_176_CANFD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_VENDOR_ID "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MAJOR_VER != CAN_176_CANFD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_AR_REL_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_MINOR_VER != CAN_176_CANFD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_AR_REL_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_AR_REL_REV_VER != CAN_176_CANFD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_AR_REL_REV_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MAJOR_VER != CAN_176_CANFD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_SW_MAJOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_MINOR_VER != CAN_176_CANFD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_SW_MINOR_VER "
#endif
#if (CAN_176_CANFD_CFG_H_SW_PATCH_VER != CAN_176_CANFD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_176_CANFD_H_SW_PATCH_VER "
#endif

#define CAN_176_CANFD_E_PARAM_POINTER         ((uint8)0x01U)
#define CAN_176_CANFD_E_PARAM_HANDLE          ((uint8)0x02U)
#define CAN_176_CANFD_E_PARAM_DATA_LENGTH     ((uint8)0x03U)
#define CAN_176_CANFD_E_PARAM_CONTROLLER      ((uint8)0x04U)
#define CAN_176_CANFD_E_UNINIT                ((uint8)0x05U)
#define CAN_176_CANFD_E_TRANSITION            ((uint8)0x06U)
#define CAN_176_CANFD_E_PARAM_BAUDRATE        ((uint8)0x07U)
#define CAN_176_CANFD_E_ICOM_CONFIG_INVALID   ((uint8)0x08U)
#define CAN_176_CANFD_E_INIT_FAILED           ((uint8)0x09U)
#define CAN_176_CANFD_E_DATALOST              ((uint8)0x01U)
#define CAN_176_CANFD_E_INVALID_CONTROLLER    ((uint8)0x0AU)
#define CAN_176_CANFD_E_PARAM_CONFIG          ((uint8)0x0BU)

#define CAN_176_CANFD_SID_INIT                          ((uint8)0x00U)
#define CAN_176_CANFD_SID_MAIN_FUNCTION_WRITE           ((uint8)0x01U)
#define CAN_176_CANFD_SID_SET_CONTROLLER_MODE           ((uint8)0x03U)
#define CAN_176_CANFD_SID_DISABLE_CONT_INTERRUPTS       ((uint8)0x04U)
#define CAN_176_CANFD_SID_ENABLE_CONT_INTERRUPTS        ((uint8)0x05U)
#define CAN_176_CANFD_SID_WRITE                         ((uint8)0x06U)
#define CAN_176_CANFD_SID_GET_VERSION_INFO              ((uint8)0x07U)
#define CAN_176_CANFD_SID_MAIN_FUNCTION_READ            ((uint8)0x08U)
#define CAN_176_CANFD_SID_MAIN_FUNCTION_BUS_OFF         ((uint8)0x09U)
#define CAN_176_CANFD_SID_MAIN_FUNCTION_WAKEUP          ((uint8)0x0AU)
#define CAN_176_CANFD_SID_CBK_CHECK_WAKEUP              ((uint8)0x0BU)
#define CAN_176_CANFD_SID_MAIN_FUNCTION_MODE            ((uint8)0x0CU)
#define CAN_176_CANFD_SID_CHANGE_BAUDRATE               ((uint8)0x0DU)
#define CAN_176_CANFD_SID_CHECK_BAUDRATE                ((uint8)0x0EU)
#define CAN_176_CANFD_SID_SET_BAUDRATE                  ((uint8)0x0FU)
#define CAN_176_CANFD_SID_DEINIT                        ((uint8)0x10U)
#define CAN_176_CANFD_SID_GETCONTROLLERERRORSTATE       ((uint8)0x11U)
#define CAN_176_CANFD_SID_GETCONTROLLERMODE             ((uint8)0x12U)
#define CAN_176_CANFD_SID_GET_RX_ERROR_COUNTER          ((uint8)0x30U)
#define CAN_176_CANFD_SID_GET_TX_ERROR_COUNTER          ((uint8)0x31U)

#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    #define CanFD_GetCoreID()       (GetCoreID())
#else
    #define CanFD_GetCoreID()       ((uint32)CAN_176_CANFD_DEFAULT_COREID)
#endif

#define CAN_176_CANFD_CORE_NUM                    MCAL_CORE_NUM

#define CANFD_MAX_FILTER_NUM        16U

typedef P2FUNC(void, CAN_CODE, CANFDerrorCallBack_Type)(VAR(uint8, AUTOMATIC) u8Can_ControllerId);

typedef enum {
    CAN_176_CANFD_UNINIT = 0U,
    CAN_176_CANFD_READY  = 1U
} Can_176_CANFD_DriverStateType;

/* CANFD module ID */
typedef enum {
    CANFD_MOD_ID_1,
    CANFD_MOD_ID_9,
    CANFD_MOD_BUTT
} CANFDModId;

/* CANFD data length */
typedef enum
{
    /* within 8 bytes, the DLC value is the same as the data length */
    CANFD_DLC_12_BYTES  = 9UL,
    CANFD_DLC_16_BYTES  = 10UL,
    CANFD_DLC_20_BYTES  = 11UL,
    CANFD_DLC_24_BYTES  = 12UL,
    CANFD_DLC_32_BYTES  = 13UL,
    CANFD_DLC_48_BYTES  = 14UL,
    CANFD_DLC_64_BYTES  = 15UL,
    CANFD_DLC_TYPE_BUTT = 16UL
} CANFD_DlcType; /* PRQA S 1535 # useful */

/* CANFD TX BUF */
typedef enum {
    CANFD_TRANS_BUF_TYPE_PRIMARY,
    CANFD_TRANS_BUF_TYPE_SECONDARY,
    CANFD_TRANS_BUF_TYPE_BUTT
} CANFDTransBufType;

typedef enum {
    CANFD_RECEIVE  = 0U,
    CANFD_TRANSMIT = 1U
} CanFd_ObjectType;

typedef enum
{
    CANFD_STANDARD_ID    = 0,
    CANFD_EXTENDED_ID    = 1,
    CANFD_STD_AND_EXT_ID = 2
} CanFd_id_type;

/* CANFD RX message */
typedef struct {
    VAR(uint32, AUTOMATIC) id;
    union {
        VAR(uint8, AUTOMATIC)  byte[64];
        VAR(uint32, AUTOMATIC) word[16];
    } data;
    VAR(uint8, AUTOMATIC) data_len;
    VAR(uint8, AUTOMATIC) is_extern;
    VAR(uint8, AUTOMATIC) is_remote;
    VAR(uint8, AUTOMATIC) is_fd_format_flag;
    VAR(uint8, AUTOMATIC) is_bit_rate_switch;
    VAR(uint8, AUTOMATIC) is_error_happened;
} CANFDRxMsg;

typedef struct {
    VAR(uint8, AUTOMATIC) seg1; /* include SYNC_SEG, PROP_SEG and PHASE_SEG1 */
    VAR(uint8, AUTOMATIC) seg2;
    VAR(uint8, AUTOMATIC) sjw;
    VAR(uint8, AUTOMATIC) ssp;
    VAR(uint8, AUTOMATIC) prescaler;
} CANFDTimeSeg;

/* CANFD Protocol physical layer parameters */
typedef struct {
    VAR(uint8, AUTOMATIC) use_bus_clk_src;
    VAR(uint16, AUTOMATIC) baudRateConfigId;
    VAR(CANFDTimeSeg, AUTOMATIC) preamble_bit_rate;
    VAR(CANFDTimeSeg, AUTOMATIC) data_bit_rate;
    VAR(boolean, AUTOMATIC) brs_ena;
} CANFDPhyPara;

/* CANFD function switch */
typedef struct {
    VAR(uint8, AUTOMATIC) tdc_en;
    VAR(uint8, AUTOMATIC) inner_loop_back_en;
    VAR(uint8, AUTOMATIC) outer_loop_back_en;
    VAR(uint8, AUTOMATIC) listen_only_en;
} CANFDFuncSwitch;

/* CAN filter parameter */
typedef struct {
    struct {
        VAR(uint8, AUTOMATIC) is_extern;
        VAR(uint8, AUTOMATIC) is_fd_format_flag;
        VAR(uint8, AUTOMATIC) is_bit_rate_switch;
        VAR(uint32, AUTOMATIC)  id;
    } value, mask;
    VAR(uint32, AUTOMATIC)  ac_frame;
    VAR(uint32, AUTOMATIC)  am_frame;
    VAR(uint8, AUTOMATIC) is_valid;
} CANFDFilter;

/* CANFD Interrupt callback */
typedef struct {
    void (* tx_transferred)(VAR(CANFDModId, AUTOMATIC) cafd_id, VAR(CANFDTransBufType, AUTOMATIC) buf_idx);
    void (* rx_received)(VAR(CANFDModId, AUTOMATIC) cafd_id, P2VAR(CANFDRxMsg, AUTOMATIC, CAN_APPL_DATA) rx_msg);
    void (* error)(VAR(uint8, AUTOMATIC) cafd_id);
    void (* busoff)(VAR(uint8, AUTOMATIC) cafd_id);
} CANFDIntrCallback;

/* CANFD configuration parameter */
typedef struct {
    CONST(CANFDModId, CAN_CONST)                        controllerId;
    CONST(uint8, CAN_CONST)                             supportPolling;
    CONST(uint16, CAN_CONST)                            defaultBaudRateId;
    CONST(uint16, CAN_CONST)                            baudRateConfigCount;
    P2CONST(CANFDPhyPara, CAN_CONST, CAN_APPL_CONST)    phy_para;
    P2CONST(CANFDFuncSwitch, CAN_CONST, CAN_APPL_CONST) func_switch;
    P2CONST(CANFDFilter, CAN_CONST, CAN_APPL_CONST)     filter;
    CONST(CANFDerrorCallBack_Type, CAN_CONST)           ErrorNotification;
    CONST(uint32, CAN_CONST)                            interconfig;
} CANFDConfig;

typedef struct
{
    CONST(uint32, CAN_CONST)                     CanObjectId;
    CONST(uint32, CAN_CONST)                     CanControllerId;
    CONST(CanFd_id_type, CAN_CONST)              CanIdType;
    CONST(uint32, CAN_CONST)                     mbIdex;
    CONST(uint32, CAN_CONST)                     mbPayloadLength;
    CONST(CANFDTransBufType, CAN_CONST)          mbType;
    CONST(uint8, CAN_CONST)                      isPolling;
    CONST(CanFd_ObjectType, CAN_CONST)           CanObjectType;
    CONST(uint8, CAN_CONST)                      CanFdPaddingValue;
    CONST(uint8, CAN_CONST)                      PeriodIndex;
    CONST(uint32, AUTOMATIC)                     filterCode;
    CONST(uint32, AUTOMATIC)                     filterMask;
    CONST(uint8, CAN_CONST)                      isBitRateSwitce;
} CanFd_hwObject;

#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
typedef struct
{
    CONST(CANFDModId, CAN_CONST)            controllerId;
    CONST(uint32, CAN_CONST)                CoreId;
} CanFd_core_map_t;
#endif

typedef struct {
    P2CONST(CanFd_hwObject, CAN_CONST, CAN_APPL_CONST)      CanFdHwObjectConfig;
    P2CONST(CANFDConfig, CAN_CONST, CAN_APPL_CONST)         CanFdControllerConfig;
    CONST(uint8, CAN_CONST)                                 CanFdHwObjCount;
#if (CAN_176_CANFD_MULTICORE_ENABLED == STD_ON)
    P2CONST(CanFd_core_map_t, CAN_CONST, CAN_APPL_CONST)    CanFdCoreMap;
#endif
} Can_176_CanFD_ConfigType;


#if (CAN_176_CANFD_VERSION_INFO_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_Init \
( \
    P2CONST(Can_176_CanFD_ConfigType, AUTOMATIC, CAN_APPL_CONST) Config \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_DeInit(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_SetBaudrate \
( \
    VAR(uint8, AUTOMATIC) Controller, VAR(uint16, AUTOMATIC) BaudRateConfigID \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) Controller, \
    VAR(Can_ControllerStateType, AUTOMATIC) Transition \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_DisableControllerInterrupts(VAR(uint8, AUTOMATIC) Controller);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_EnableControllerInterrupts(VAR(uint8, AUTOMATIC) Controller);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*
    [SWS_Can_00485] The function Can_CheckWakeup shall be pre compile time 
    configurable On/Off by the configuration parameter: CanWakeupFunctionalityAPI
*/
#if (CAN_176_CANFD_CHECK_WAKEUP_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_CheckWakeup(VAR(uint8, AUTOMATIC) Controller);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerErrorState \
( \
    VAR(uint8, AUTOMATIC) ControllerId, \
    P2VAR(Can_ErrorStateType, AUTOMATIC, CAN_APPL_DATA) ErrorStatePtr \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerMode \
( \
    VAR(uint8, AUTOMATIC) Controller, \
    P2VAR(Can_ControllerStateType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerRxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) ControllerId, \
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) pRxErrorCounterPtr \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_GetControllerTxErrorCounter \
( \
    VAR(uint8, AUTOMATIC) ControllerId, \
    P2VAR(uint8, AUTOMATIC, CAN_APPL_DATA) pTxErrorCounterPtr \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(Std_ReturnType, CAN_CODE) Can_176_CanFD_Write \
( \
    VAR(Can_HwHandleType, AUTOMATIC) Hth, \
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo \
);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

/*
    [SWS_Can_00031] The function Can_MainFunction_Write shall perform the polling 
    of TX confirmation when CanTxProcessing
*/
#if (CAN_176_CANFD_MAINFUNCTION_WRITE_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif
/*
    [SWS_Can_00108] The function Can_MainFunction_Read shall perform the polling 
    of RX indications when CanRxProcessing is set to POLLING or MIXED. In case of 
    MIXED processing only the hardware objects for which 
    CanHardwareObjectUsesPolling is set to TRUE shall be polled.
*/
#if (CAN_176_CANFD_MAINFUNCTION_READ_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif
/*
    [SWS_Can_00109] The function Can_MainFunction_BusOff shall perform the 
    polling of bus-off events that are configured statically as 'to be polled'.
*/
#if (CAN_176_CANFD_MAINFUNCTION_BUSOFF_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_BusOff(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif
/*
    [SWS_Can_00112] The function Can_MainFunction_Wakeup shall perform the 
    polling of wake-up events that are configured statically as 'to be polled'.
*/
#if (CAN_176_CANFD_MAINFUNCTION_WAKEUP_API == STD_ON)
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Wakeup(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Mode(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"

#if (CAN_176_CANFD_MULTIPLE_READ_PERIOD == STD_ON)

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_0
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_0(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_1
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_1(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_2
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_2(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_3
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_3(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_READ_4
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Read_4(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#endif // CAN_MULTIPLE_READ_PERIOD

#if (CAN_176_CANFD_MULTIPLE_WRITE_PERIOD == STD_ON)

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_0
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_0(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_1
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_1(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_2
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_2(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_3
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_3(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#ifdef CAN_176_CANFD_MAINFUNCTION_PERIOD_WRITE_4
#define CAN_176_CANFD_START_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
FUNC(void, CAN_CODE) Can_176_CanFD_MainFunction_Write_4(void);
#define CAN_176_CANFD_STOP_SEC_CODE
#include "Can_176_CanFD_MemMap.h"
#endif

#endif

#if (CAN_176_CANFD_PRECOMPILE_SUPPORT == STD_OFF)
CAN_176_CANFD_PB_CONFIG_DECLARATION
#else
extern CONST(Can_176_CanFD_ConfigType, CAN_CONST) Can_176_CanFD_Config;
#endif

extern P2CONST(Can_176_CanFD_ConfigType, CAN_VAR, CAN_APPL_CONST) g_pCanFd_CurConfig;

#endif /* RESOURCE_SUPPORT_CANFD_IP */

#ifdef __cplusplus
}
#endif

#endif /* CAN_176_CANFD_H */
