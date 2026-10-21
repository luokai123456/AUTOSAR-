/*
************************************************************************************************************************
*
* File name: Rte_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_TYPE_H_
#define RTE_TYPE_H_
/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Os_Types.h"
#include "Rte.h"
#include "ComStack_Cfg.h" 
#include "ComStack_Types.h"
#include "Rte_Compiler_Cfg.h"
#include "Rte_Dcm_Type.h"
#include "Rte_BswM_Type.h"
#include "Rte_ComM_Type.h"
#include "Rte_Csm_Type.h"
#include "Rte_Dem_Type.h"
#include "Rte_Det_Type.h"
#include "Rte_EcuM_Type.h"
#include "Rte_FiM_Type.h"
#include "Rte_KeyM_Type.h"
#include "Rte_NvM_Type.h"
#include "Rte_SecOC_Type.h"
#include "Rte_WdgM_Type.h"

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
#define RTE_CALL_STACK_LENGTH_SYNC            (4U)
#define RTE_CALL_STACK_LENGTH_ASYNC           (1U)

#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
#define RTE_CORE_STATE_UNINIT                 (0U)
#define RTE_CORE_STATE_SCHM_INIT              (1U)
#define RTE_CORE_STATE_INIT                   (2U)
#define RTE_CORE_NO_USE                       (0U)
#define RTE_CORE_IN_USE                       (1U)
#define RTE_CORE_NOT_INIT_OK                  (0U)
#define RTE_CORE_ALL_INIT_OK                  (1U)
#define RTE_CORE_COUNT                        (6U)
#define RTE_CORE_MASTER_ID                    (0U)
#endif

/*
************************************************************************************************************************
*    Data type definitions include custom array struct
************************************************************************************************************************
*/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)

#ifndef Rte_TypeDef_dtRef_VOID
#define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;
#endif

#ifndef Rte_TypeDef_dtRef_const_VOID
#define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;
#endif

#ifndef ApuMode_SMART_MODE
#define ApuMode_SMART_MODE (0U)
#endif

#ifndef ApuMode_REC_MODE
#define ApuMode_REC_MODE (1U)
#endif

#ifndef ApuMode_EV_MODE
#define ApuMode_EV_MODE (2U)
#endif

#ifndef ApuMode_SAVE_MODE
#define ApuMode_SAVE_MODE (3U)
#endif

#ifndef ApuMode_REV_MODE
#define ApuMode_REV_MODE (4U)
#endif

#ifndef ApuMode_INVALID
#define ApuMode_INVALID (5U)
#endif

#ifndef CanDataStatus_New
#define CanDataStatus_New (0U)
#endif

#ifndef CanDataStatus_Held
#define CanDataStatus_Held (1U)
#endif

#ifndef CanDataStatus_Default
#define CanDataStatus_Default (2U)
#endif

#ifndef ClutchState_OPEN
#define ClutchState_OPEN (0U)
#endif

#ifndef ClutchState_SLIPPING
#define ClutchState_SLIPPING (1U)
#endif

#ifndef ClutchState_CLOSED
#define ClutchState_CLOSED (2U)
#endif

#ifndef ClutchState_FAILURE
#define ClutchState_FAILURE (3U)
#endif

#ifndef ClutchState_INVALID
#define ClutchState_INVALID (4U)
#endif

#ifndef FanStatus_OFF
#define FanStatus_OFF (0U)
#endif

#ifndef FanStatus_LOW_SPEED
#define FanStatus_LOW_SPEED (1U)
#endif

#ifndef FanStatus_MEDIUM_SPEED
#define FanStatus_MEDIUM_SPEED (2U)
#endif

#ifndef FanStatus_HIGH_SPEED
#define FanStatus_HIGH_SPEED (3U)
#endif

#ifndef FanStatus_FAILURE
#define FanStatus_FAILURE (5U)
#endif

#ifndef FanStatus_INVALID
#define FanStatus_INVALID (10U)
#endif

#ifndef FiltTrqRange_FILTER_OFF
#define FiltTrqRange_FILTER_OFF (0U)
#endif

#ifndef FiltTrqRange_BRAKING_POS
#define FiltTrqRange_BRAKING_POS (1U)
#endif

#ifndef FiltTrqRange_BRAKING_NEG
#define FiltTrqRange_BRAKING_NEG (2U)
#endif

#ifndef FiltTrqRange_ZEROCROSS_POS
#define FiltTrqRange_ZEROCROSS_POS (3U)
#endif

#ifndef FiltTrqRange_ZEROCROSS_NEG
#define FiltTrqRange_ZEROCROSS_NEG (4U)
#endif

#ifndef FiltTrqRange_POWER_POS
#define FiltTrqRange_POWER_POS (5U)
#endif

#ifndef FiltTrqRange_POWER_NEG
#define FiltTrqRange_POWER_NEG (6U)
#endif

#ifndef HVACStatus_HV_OFF
#define HVACStatus_HV_OFF (0U)
#endif

#ifndef HVACStatus_STANDBY
#define HVACStatus_STANDBY (1U)
#endif

#ifndef HVACStatus_ACTIVE
#define HVACStatus_ACTIVE (2U)
#endif

#ifndef HVACStatus_CHARGER_COOLING
#define HVACStatus_CHARGER_COOLING (3U)
#endif

#ifndef HVACStatus_CHARGER_HEATING
#define HVACStatus_CHARGER_HEATING (4U)
#endif

#ifndef InsulationStatus_OK
#define InsulationStatus_OK (0U)
#endif

#ifndef InsulationStatus_LOW
#define InsulationStatus_LOW (1U)
#endif

#ifndef InsulationStatus_CRITICAL
#define InsulationStatus_CRITICAL (2U)
#endif

#ifndef InsulationStatus_INVALID
#define InsulationStatus_INVALID (3U)
#endif

#ifndef PumpStatus_OFF
#define PumpStatus_OFF (0U)
#endif

#ifndef PumpStatus_LOW_SPEED
#define PumpStatus_LOW_SPEED (1U)
#endif

#ifndef PumpStatus_MEDIUM_SPEED
#define PumpStatus_MEDIUM_SPEED (2U)
#endif

#ifndef PumpStatus_HIGH_SPEED
#define PumpStatus_HIGH_SPEED (3U)
#endif

#ifndef PumpStatus_FAILURE
#define PumpStatus_FAILURE (5U)
#endif

#ifndef PumpStatus_INVALID
#define PumpStatus_INVALID (10U)
#endif

#ifndef ShiftType_NO_SHIFT
#define ShiftType_NO_SHIFT (0U)
#endif

#ifndef ShiftType_SHIFT_TRQ_INC
#define ShiftType_SHIFT_TRQ_INC (1U)
#endif

#ifndef ShiftType_SHIFT_TRQ_DEC
#define ShiftType_SHIFT_TRQ_DEC (2U)
#endif

#ifndef ShiftType_SHIFT_TRQ_CTRL
#define ShiftType_SHIFT_TRQ_CTRL (3U)
#endif

#ifndef ShiftType_SHIFT_SPD_CTRL
#define ShiftType_SHIFT_SPD_CTRL (4U)
#endif

#ifndef ShiftType_SHIFT_SPD_CTRL_HCU
#define ShiftType_SHIFT_SPD_CTRL_HCU (5U)
#endif

#ifndef TV4Status_DEFAULT
#define TV4Status_DEFAULT (0U)
#endif

#ifndef TV4Status_CABIN_HEAT
#define TV4Status_CABIN_HEAT (1U)
#endif

#ifndef TV4Status_BATT_HEAT
#define TV4Status_BATT_HEAT (2U)
#endif

#ifndef TV4Status_BATT_CABIN_HEAT
#define TV4Status_BATT_CABIN_HEAT (3U)
#endif

#ifndef TV4Status_BATT_HEAT_DEF
#define TV4Status_BATT_HEAT_DEF (4U)
#endif

#ifndef Rte_TypeDef_ApuMode
#define Rte_TypeDef_ApuMode
typedef uint8 ApuMode;
#endif

#ifndef Rte_TypeDef_Boolean
#define Rte_TypeDef_Boolean
typedef boolean Boolean;
#endif

#ifndef Rte_TypeDef_BrakePedalStatus
#define Rte_TypeDef_BrakePedalStatus
typedef uint8 BrakePedalStatus;
#endif

#ifndef Rte_TypeDef_CanDataStatus
#define Rte_TypeDef_CanDataStatus
typedef uint8 CanDataStatus;
#endif

#ifndef Rte_TypeDef_ChargerStatus
#define Rte_TypeDef_ChargerStatus
typedef uint8 ChargerStatus;
#endif

#ifndef Rte_TypeDef_ClutchState
#define Rte_TypeDef_ClutchState
typedef uint8 ClutchState;
#endif

#ifndef Rte_TypeDef_CrModeMngr_e
#define Rte_TypeDef_CrModeMngr_e
typedef uint8 CrModeMngr_e;
#endif

#ifndef Rte_TypeDef_CrsBtnErrSts
#define Rte_TypeDef_CrsBtnErrSts
typedef uint8 CrsBtnErrSts;
#endif

#ifndef Rte_TypeDef_CrsBtnSts
#define Rte_TypeDef_CrsBtnSts
typedef uint8 CrsBtnSts;
#endif

#ifndef Rte_TypeDef_CruiseSts_e
#define Rte_TypeDef_CruiseSts_e
typedef uint8 CruiseSts_e;
#endif

#ifndef Rte_TypeDef_DCDCMode
#define Rte_TypeDef_DCDCMode
typedef uint8 DCDCMode;
#endif

#ifndef Rte_TypeDef_DriveDir
#define Rte_TypeDef_DriveDir
typedef uint8 DriveDir;
#endif

#ifndef Rte_TypeDef_ElMac
#define Rte_TypeDef_ElMac
typedef uint8 ElMac;
#endif

#ifndef Rte_TypeDef_EngineState
#define Rte_TypeDef_EngineState
typedef uint8 EngineState;
#endif

#ifndef Rte_TypeDef_EngStartType
#define Rte_TypeDef_EngStartType
typedef uint8 EngStartType;
#endif

#ifndef Rte_TypeDef_FanStatus
#define Rte_TypeDef_FanStatus
typedef uint8 FanStatus;
#endif

#ifndef Rte_TypeDef_FaultStatus
#define Rte_TypeDef_FaultStatus
typedef uint8 FaultStatus;
#endif

#ifndef Rte_TypeDef_FiltTrqRange
#define Rte_TypeDef_FiltTrqRange
typedef uint8 FiltTrqRange;
#endif

#ifndef Rte_TypeDef_Float
#define Rte_TypeDef_Float
typedef float32 Float;
#endif

#ifndef Rte_TypeDef_GearLeverPos
#define Rte_TypeDef_GearLeverPos
typedef uint8 GearLeverPos;
#endif

#ifndef Rte_TypeDef_GearShiftResp
#define Rte_TypeDef_GearShiftResp
typedef uint8 GearShiftResp;
#endif

#ifndef Rte_TypeDef_HEVModeReq
#define Rte_TypeDef_HEVModeReq
typedef uint8 HEVModeReq;
#endif

#ifndef Rte_TypeDef_HVACStatus
#define Rte_TypeDef_HVACStatus
typedef uint8 HVACStatus;
#endif

#ifndef Rte_TypeDef_HVBattStatus
#define Rte_TypeDef_HVBattStatus
typedef uint8 HVBattStatus;
#endif

#ifndef Rte_TypeDef_HVBRelayStatus
#define Rte_TypeDef_HVBRelayStatus
typedef uint8 HVBRelayStatus;
#endif

#ifndef Rte_TypeDef_HybModeMngr
#define Rte_TypeDef_HybModeMngr
typedef uint8 HybModeMngr;
#endif

#ifndef Rte_TypeDef_InsulationStatus
#define Rte_TypeDef_InsulationStatus
typedef uint8 InsulationStatus;
#endif

#ifndef Rte_TypeDef_KeyAuthStatus
#define Rte_TypeDef_KeyAuthStatus
typedef uint8 KeyAuthStatus;
#endif

#ifndef Rte_TypeDef_McuSts
#define Rte_TypeDef_McuSts
typedef uint8 McuSts;
#endif

#ifndef Rte_TypeDef_NMStatus
#define Rte_TypeDef_NMStatus
typedef uint8 NMStatus;
#endif

#ifndef Rte_TypeDef_ParkingStatus
#define Rte_TypeDef_ParkingStatus
typedef uint8 ParkingStatus;
#endif

#ifndef Rte_TypeDef_PmmMode
#define Rte_TypeDef_PmmMode
typedef uint8 PmmMode;
#endif

#ifndef Rte_TypeDef_PmmStatus
#define Rte_TypeDef_PmmStatus
typedef uint8 PmmStatus;
#endif

#ifndef Rte_TypeDef_PowerFlowMode
#define Rte_TypeDef_PowerFlowMode
typedef uint8 PowerFlowMode;
#endif

#ifndef Rte_TypeDef_PumpStatus
#define Rte_TypeDef_PumpStatus
typedef uint8 PumpStatus;
#endif

#ifndef Rte_TypeDef_ShiftType
#define Rte_TypeDef_ShiftType
typedef uint8 ShiftType;
#endif

#ifndef Rte_TypeDef_SInt16
#define Rte_TypeDef_SInt16
typedef sint16 SInt16;
#endif

#ifndef Rte_TypeDef_SInt8
#define Rte_TypeDef_SInt8
typedef sint8 SInt8;
#endif

#ifndef Rte_TypeDef_TV4Status
#define Rte_TypeDef_TV4Status
typedef uint8 TV4Status;
#endif

#ifndef Rte_TypeDef_UInt16
#define Rte_TypeDef_UInt16
typedef uint16 UInt16;
#endif

#ifndef Rte_TypeDef_UInt32
#define Rte_TypeDef_UInt32
typedef uint32 UInt32;
#endif

#ifndef Rte_TypeDef_UINT64
#define Rte_TypeDef_UINT64
typedef uint64 UINT64;
#endif

#ifndef Rte_TypeDef_UInt8
#define Rte_TypeDef_UInt8
typedef uint8 UInt8;
#endif

#ifndef Rte_TypeDef_Boolean_T
#define Rte_TypeDef_Boolean_T
typedef boolean Boolean_T;
#endif

#ifndef Rte_TypeDef_rt_Array_Boolean_24
#define Rte_TypeDef_rt_Array_Boolean_24
typedef Boolean rt_Array_Boolean_24[24];
#endif

#ifndef Rte_TypeDef_rt_Array_Float_144
#define Rte_TypeDef_rt_Array_Float_144
typedef Float rt_Array_Float_144[144];
#endif

#ifndef Rte_TypeDef_rt_Array_Float_24
#define Rte_TypeDef_rt_Array_Float_24
typedef Float rt_Array_Float_24[24];
#endif

#ifndef Rte_TypeDef_rt_Array_Float_255
#define Rte_TypeDef_rt_Array_Float_255
typedef Float rt_Array_Float_255[255];
#endif

#ifndef Rte_TypeDef_rt_Array_Float_32
#define Rte_TypeDef_rt_Array_Float_32
typedef Float rt_Array_Float_32[32];
#endif

#ifndef Rte_TypeDef_rt_Array_Float_54
#define Rte_TypeDef_rt_Array_Float_54
typedef Float rt_Array_Float_54[54];
#endif

#ifndef Rte_TypeDef_rt_Array_SInt16_32
#define Rte_TypeDef_rt_Array_SInt16_32
typedef SInt16 rt_Array_SInt16_32[32];
#endif

#ifndef Rte_TypeDef_rt_Array_SInt16_8
#define Rte_TypeDef_rt_Array_SInt16_8
typedef SInt16 rt_Array_SInt16_8[8];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt16_130
#define Rte_TypeDef_rt_Array_UInt16_130
typedef UInt16 rt_Array_UInt16_130[130];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt16_24
#define Rte_TypeDef_rt_Array_UInt16_24
typedef UInt16 rt_Array_UInt16_24[24];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt32_24
#define Rte_TypeDef_rt_Array_UInt32_24
typedef UInt32 rt_Array_UInt32_24[24];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt32_4
#define Rte_TypeDef_rt_Array_UInt32_4
typedef UInt32 rt_Array_UInt32_4[4];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt32_9
#define Rte_TypeDef_rt_Array_UInt32_9
typedef UInt32 rt_Array_UInt32_9[9];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_17
#define Rte_TypeDef_rt_Array_UInt8_17
typedef UInt8 rt_Array_UInt8_17[17];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_24
#define Rte_TypeDef_rt_Array_UInt8_24
typedef UInt8 rt_Array_UInt8_24[24];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_255
#define Rte_TypeDef_rt_Array_UInt8_255
typedef UInt8 rt_Array_UInt8_255[255];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_256
#define Rte_TypeDef_rt_Array_UInt8_256
typedef UInt8 rt_Array_UInt8_256[256];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_3
#define Rte_TypeDef_rt_Array_UInt8_3
typedef UInt8 rt_Array_UInt8_3[3];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_32
#define Rte_TypeDef_rt_Array_UInt8_32
typedef UInt8 rt_Array_UInt8_32[32];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_4
#define Rte_TypeDef_rt_Array_UInt8_4
typedef UInt8 rt_Array_UInt8_4[4];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_54
#define Rte_TypeDef_rt_Array_UInt8_54
typedef UInt8 rt_Array_UInt8_54[54];
#endif

#ifndef Rte_TypeDef_SInt32
#define Rte_TypeDef_SInt32
typedef sint32 SInt32;
#endif

#ifndef Rte_TypeDef_UInt32_T
#define Rte_TypeDef_UInt32_T
typedef uint32 UInt32_T;
#endif

#ifndef Rte_TypeDef_UInt8_T
#define Rte_TypeDef_UInt8_T
typedef uint8 UInt8_T;
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_16
#define Rte_TypeDef_rt_Array_UInt8_16
typedef UInt8 rt_Array_UInt8_16[16];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_2
#define Rte_TypeDef_rt_Array_UInt8_2
typedef UInt8 rt_Array_UInt8_2[2];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_16
#define Rte_TypeDef_rt_Array_UInt8_T_16
typedef UInt8_T rt_Array_UInt8_T_16[16];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_2
#define Rte_TypeDef_rt_Array_UInt8_T_2
typedef UInt8_T rt_Array_UInt8_T_2[2];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_255
#define Rte_TypeDef_rt_Array_UInt8_T_255
typedef UInt8_T rt_Array_UInt8_T_255[255];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_288
#define Rte_TypeDef_rt_Array_UInt8_T_288
typedef UInt8_T rt_Array_UInt8_T_288[288];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_3
#define Rte_TypeDef_rt_Array_UInt8_T_3
typedef UInt8_T rt_Array_UInt8_T_3[3];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_4
#define Rte_TypeDef_rt_Array_UInt8_T_4
typedef UInt8_T rt_Array_UInt8_T_4[4];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_48
#define Rte_TypeDef_rt_Array_UInt8_T_48
typedef UInt8_T rt_Array_UInt8_T_48[48];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_54
#define Rte_TypeDef_rt_Array_UInt8_T_54
typedef UInt8_T rt_Array_UInt8_T_54[54];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_6
#define Rte_TypeDef_rt_Array_UInt8_T_6
typedef UInt8_T rt_Array_UInt8_T_6[6];
#endif

#ifndef Rte_TypeDef_rt_Array_UInt8_T_8
#define Rte_TypeDef_rt_Array_UInt8_T_8
typedef UInt8_T rt_Array_UInt8_T_8[8];
#endif

#ifndef Rte_TypeDef_Double
#define Rte_TypeDef_Double
typedef float64 Double;
#endif


#ifndef Rte_TypeDef_Rte_Cs_TransactionHandleType
#define Rte_TypeDef_Rte_Cs_TransactionHandleType
typedef struct
{
    uint16 clientId;
    uint16 sequenceCounter;
} Rte_Cs_TransactionHandleType;
#endif

#ifndef Rte_TypeDef_Rte_ClientIdType
#define Rte_TypeDef_Rte_ClientIdType
typedef struct
{
    uint8 clientId;
    uint8 subClientId;
}Rte_ClientIdType;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Property_Type
#define Rte_TypeDef_Rte_CS_Server_Property_Type
typedef struct
{
    boolean Rte_ServerCompleted;
    boolean Rte_Call_Busy;
} Rte_CS_Server_Property_Type;
#endif

#if 0 //UDS不使用
#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_3 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type
typedef struct
{
    uint8 Cond;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type
typedef struct
{
    uint8 Cond;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type
typedef struct
{
    uint8 placeholder;
} Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type
typedef struct
{
    rt_Array_UInt8_T_2 DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type
typedef struct
{
    rt_Array_UInt8_T_2 DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type
typedef struct
{
    UInt8_T DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type
typedef struct
{
    UInt8_T DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type
typedef struct
{
    UInt8_T DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type
typedef struct
{
    UInt8_T DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type
typedef struct
{
    UInt8_T DataIn;
    UInt8_T OpStatus;
    UInt8_T DataOut;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    Std_ReturnType ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_255 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_54 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_4 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_48 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_8 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_48 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_48 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_288 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_6 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_2 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_3 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    rt_Array_UInt8_T_3 Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type;
#endif

#ifndef Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type
#define Rte_TypeDef_Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type
typedef struct
{
    UInt8_T OpStatus;
    UInt8_T Data;
    UInt8_T ErrorCode;
} Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type;
#endif

#endif

/*
************************************************************************************************************************
*    Signal Grounp User Types
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE and BSW User Types
************************************************************************************************************************
*/
#ifndef Rte_TypeDef_RteQueueBufferType
#define Rte_TypeDef_RteQueueBufferType
typedef struct
{
    uint32 maxCnt;      /* The max number of elements in the list */
    uint32 currCnt;     /* Current number of elements in the list */
    uint32 dataSize;    /* Size of the elements in the list */
    void *head;         /* Head of the elements in the list */
    void *tail;         /* Tail of the elements in the list */
    void *bufStart;     /* Start of buffer */
    void *bufEnd;       /* End of buffer */
} RteQueueBufferType;
#endif

#ifndef Rte_TypeDef_RteStackBufferType
#define Rte_TypeDef_RteStackBufferType
typedef struct
{
    uint32 maxCnt;      /* The max number of elements in the list */
    uint32 currCnt;     /* Current number of elements in the list */
    uint32 dataSize;    /* Size of the elements in the list */
    void *top;          /* Top of the elements in the list */
    void *bufStart;     /* Start of buffer */
    void *bufEnd;       /* End of buffer */
} RteStackBufferType;
#endif

#ifndef Rte_TypeDef_Rte_BitType
#define Rte_TypeDef_Rte_BitType
typedef unsigned int Rte_BitType;
#endif

#ifndef Rte_TypeDef_NvM_RequestResultType
#define Rte_TypeDef_NvM_RequestResultType 
typedef uint8 NvM_RequestResultType;
#endif

#ifndef Rte_TypeDef_Dem_OperationCycleStateType
#define Rte_TypeDef_Dem_OperationCycleStateType 
typedef uint8 Dem_OperationCycleStateType;
#endif

typedef struct
{
    Rte_BitType Rte_ComCbk_RxNeverReceived;
    Rte_BitType Rte_ComCbk_RxUpdate : 1;
    Rte_BitType Rte_ComCbk_RxUpdate_Sender : 1;
    Rte_BitType Rte_ComCbk_RxInvalid;
    Rte_BitType Rte_ComCbk_RxTimeout;
}Rte_ComCbk_Struct;



#define RTE_TRANSFORMER_UNSPECIFIED   0x00U
#define RTE_TRANSFORMER_SERIALIZER    0x01U
#define RTE_TRANSFORMER_SAFETY        0x02U
#define RTE_TRANSFORMER_SECURITY      0x03U
#define RTE_TRANSFORMER_CUSTOM        0xFFU

#ifndef Rte_TypeDef_Rte_TransformerErrorCode
#define Rte_TypeDef_Rte_TransformerErrorCode
typedef uint8 Rte_TransformerErrorCode;
#endif

#ifndef Rte_TypeDef_Rte_TransformerClass
#define Rte_TypeDef_Rte_TransformerClass
typedef uint8 Rte_TransformerClass;
#endif

#ifndef Rte_TypeDef_Rte_TransformerError
#define Rte_TypeDef_Rte_TransformerError
typedef struct 
{
    Rte_TransformerErrorCode errorCode;
    Rte_TransformerClass transformerClass;
 } Rte_TransformerError;
#endif

#ifndef Rte_TypeDef_Rte_LdComTpFlagType
#define Rte_TypeDef_Rte_LdComTpFlagType
typedef struct 
{
    boolean isLocked;
    uint32 iBufferLength;
    uint32 iUsedLength;
    uint8 iTransformationStatus;
} Rte_LdComTpFlagType;
#endif

/*
************************************************************************************************************************
*    Memory Block User Types
************************************************************************************************************************
*/

/* 
************************************************************************************************************************ 
*    Data type definitions of Tx Confirmation Flag 
************************************************************************************************************************ 
*/

/*
************************************************************************************************************************
*    DataType definitions for implicit access to S/R port elements
************************************************************************************************************************
*/
typedef struct
{
    Float value;
}Rte_DE_Float;

typedef struct
{
    Boolean value;
}Rte_DE_Boolean;

typedef struct
{
    UInt8 value;
}Rte_DE_UInt8;

typedef struct
{
    KeyAuthStatus value;
}Rte_DE_KeyAuthStatus;

typedef struct
{
    DCDCMode value;
}Rte_DE_DCDCMode;

typedef struct
{
    UInt16 value;
}Rte_DE_UInt16;

typedef struct
{
    PmmStatus value;
}Rte_DE_PmmStatus;

typedef struct
{
    EngineState value;
}Rte_DE_EngineState;

typedef struct
{
    EngStartType value;
}Rte_DE_EngStartType;

typedef struct
{
    rt_Array_UInt32_24 value;
}Rte_DE_rt_Array_UInt32_24;

typedef struct
{
    rt_Array_UInt16_24 value;
}Rte_DE_rt_Array_UInt16_24;

typedef struct
{
    rt_Array_Float_255 value;
}Rte_DE_rt_Array_Float_255;

typedef struct
{
    rt_Array_UInt8_24 value;
}Rte_DE_rt_Array_UInt8_24;

typedef struct
{
    rt_Array_UInt8_255 value;
}Rte_DE_rt_Array_UInt8_255;

typedef struct
{
    rt_Array_Boolean_24 value;
}Rte_DE_rt_Array_Boolean_24;

typedef struct
{
    rt_Array_Float_24 value;
}Rte_DE_rt_Array_Float_24;

typedef struct
{
    UInt32 value;
}Rte_DE_UInt32;

typedef struct
{
    rt_Array_Float_144 value;
}Rte_DE_rt_Array_Float_144;

typedef struct
{
    rt_Array_UInt8_4 value;
}Rte_DE_rt_Array_UInt8_4;

typedef struct
{
    rt_Array_Float_54 value;
}Rte_DE_rt_Array_Float_54;

typedef struct
{
    rt_Array_Float_32 value;
}Rte_DE_rt_Array_Float_32;

typedef struct
{
    rt_Array_UInt8_54 value;
}Rte_DE_rt_Array_UInt8_54;

typedef struct
{
    SInt16 value;
}Rte_DE_SInt16;

typedef struct
{
    rt_Array_UInt16_130 value;
}Rte_DE_rt_Array_UInt16_130;

typedef struct
{
    rt_Array_UInt32_4 value;
}Rte_DE_rt_Array_UInt32_4;

typedef struct
{
    rt_Array_SInt16_8 value;
}Rte_DE_rt_Array_SInt16_8;

typedef struct
{
    rt_Array_SInt16_32 value;
}Rte_DE_rt_Array_SInt16_32;

typedef struct
{
    rt_Array_UInt8_32 value;
}Rte_DE_rt_Array_UInt8_32;

typedef struct
{
    SInt32 value;
}Rte_DE_SInt32;

typedef struct
{
    rt_Array_UInt32_9 value;
}Rte_DE_rt_Array_UInt32_9;

typedef struct
{
    FaultStatus value;
}Rte_DE_FaultStatus;

typedef struct
{
    McuSts value;
}Rte_DE_McuSts;

typedef struct
{
    HVBRelayStatus value;
}Rte_DE_HVBRelayStatus;

typedef struct
{
    BrakePedalStatus value;
}Rte_DE_BrakePedalStatus;

typedef struct
{
    GearLeverPos value;
}Rte_DE_GearLeverPos;

typedef struct
{
    ParkingStatus value;
}Rte_DE_ParkingStatus;

typedef struct
{
    SInt8 value;
}Rte_DE_SInt8;

typedef struct
{
    PowerFlowMode value;
}Rte_DE_PowerFlowMode;

typedef struct
{
    DriveDir value;
}Rte_DE_DriveDir;

typedef struct
{
    HEVModeReq value;
}Rte_DE_HEVModeReq;

typedef struct
{
    HybModeMngr value;
}Rte_DE_HybModeMngr;

typedef struct
{
    ElMac value;
}Rte_DE_ElMac;

typedef struct
{
    HVBattStatus value;
}Rte_DE_HVBattStatus;

typedef struct
{
    ChargerStatus value;
}Rte_DE_ChargerStatus;

typedef struct
{
    NMStatus value;
}Rte_DE_NMStatus;

typedef struct
{
    CrsBtnErrSts value;
}Rte_DE_CrsBtnErrSts;

typedef struct
{
    CrsBtnSts value;
}Rte_DE_CrsBtnSts;

typedef struct
{
    CrModeMngr_e value;
}Rte_DE_CrModeMngr_e;

typedef struct
{
    CruiseSts_e value;
}Rte_DE_CruiseSts_e;

typedef struct
{
    GearShiftResp value;
}Rte_DE_GearShiftResp;

typedef struct
{
    Double value;
}Rte_DE_Double;

typedef struct
{
    rt_Array_UInt8_2 value;
}Rte_DE_rt_Array_UInt8_2;

typedef struct
{
    PmmMode value;
}Rte_DE_PmmMode;

typedef struct
{
    Rte_DE_Float Rte_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V;
}Rte_tsRB_BIfRx_fc_BIfRx;

typedef struct
{
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_UInt8 Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg;
    Rte_DE_KeyAuthStatus Rte_vcsb_ATAU_pmmd_e_authenticationStatus;
}Rte_tsRB_swc_ATAU_swc_ATAU_Step;

typedef struct
{
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_DryAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_ResrAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPumpFault;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_vacTankLowPrs;
    Rte_DE_Float Rte_vcib_VCIP_brpd_p_AirPres_kpa;
    Rte_DE_Float Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar;
    Rte_DE_UInt8 Rte_vcib_VCIP_brpd_st_bdcacWrk;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_crash;
    Rte_DE_DCDCMode Rte_vcib_VCIP_dccd_e_modeAct;
    Rte_DE_Float Rte_vcib_VCIP_lvbd_t_lvbEstTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_lvbd_u_dcdcLVBusActFilt_V;
    Rte_DE_Float Rte_vcib_VCIP_macd_p_frontAirTankPres_bar;
    Rte_DE_Float Rte_vcib_VCIP_macd_p_rearAirTankPres_bar;
    Rte_DE_UInt8 Rte_vcib_VCIP_macd_st_epsErrorCode;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgNetConfgABS;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_VacTkAirPres_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_VacTkEnFb_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_brkVacuumPres_V;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_u_vacTkPowSup_V;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_airTankFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_airTankPresLow;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_airTankPresLowEVDis;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_bdcacEna;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_bdcacTmOut;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_brkPmp1Rly;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_brkPmp2Rly;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_pumpRdy;
    Rte_DE_Float Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa;
    Rte_DE_Float Rte_vcsb_AUXC_brpd_u_VacPumpVol_V;
    Rte_DE_Boolean Rte_vcsb_AUXC_lvbd_b_lvbSOCValid;
    Rte_DE_Float Rte_vcsb_AUXC_lvbd_q_lvbSOC_pct;
    Rte_DE_Boolean Rte_vcsb_AUXC_pscd_b_epsEna;
    Rte_DE_Boolean Rte_vcsb_AUXC_pscd_b_epsStopFlt;
    Rte_DE_Float Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_ptRdyInd;
    Rte_DE_EngineState Rte_vcsb_PTSM_engd_e_engState;
    Rte_DE_EngStartType Rte_vcsb_VOMM_essd_e_engStrtTyp;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_EVModeEpsEna;
}Rte_tsRB_swc_AUXC_swc_AUXC_Step;

typedef struct
{
    Rte_DE_rt_Array_UInt32_24 Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp;
    Rte_DE_rt_Array_UInt16_24 Rte_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp;
    Rte_DE_rt_Array_UInt16_24 Rte_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp;
    Rte_DE_rt_Array_Float_255 Rte_BBC_ICellBaln_BBC_ICellBaln;
    Rte_DE_rt_Array_UInt8_24 Rte_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp;
    Rte_DE_rt_Array_UInt8_24 Rte_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp;
    Rte_DE_rt_Array_UInt8_255 Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv;
    Rte_DE_Float Rte_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim;
    Rte_DE_Boolean Rte_BBC_bAcvBaln_BBC_bAcvBaln;
    Rte_DE_rt_Array_Boolean_24 Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln;
    Rte_DE_Float Rte_BCC_IObcLimn_BCC_IObcLimn;
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
    Rte_DE_Float Rte_BCF_IDchaLim_BCF_IDchaLim;
    Rte_DE_Float Rte_BCF_UCellAvg_BCF_UCellAvg;
    Rte_DE_rt_Array_Float_255 Rte_BMC_UCell_BMC_UCell;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_rt_Array_Float_24 Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag;
    Rte_DE_UInt8 Rte_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl;
    Rte_DE_UInt8 Rte_DEH_LvlErr_DEH_LvlErr;
    Rte_DE_UInt8 Rte_DEH_ModBalCtl_DEH_ModBalCtl;
    Rte_DE_UInt8 Rte_DEH_ReqBalCtl_DEH_ReqBalCtl;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCellByMdul_MCC_NrCellByMdul;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_DE_rt_Array_UInt8_255 Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln;
}Rte_tsRB_swc_BatBalnCtl_BBC_100ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BCC_AcvCellURchd_BCC_AcvCellURchd;
    Rte_DE_UInt8 Rte_BCC_AcvSocRchd_BCC_AcvSocRchd;
    Rte_DE_UInt8 Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
    Rte_DE_Float Rte_BCC_EChSng_BCC_EChSng;
    Rte_DE_Float Rte_BCC_IChReq_BCC_IChReq;
    Rte_DE_Float Rte_BCC_IDchaReq_BCC_IDchaReq;
    Rte_DE_UInt8 Rte_BCC_ModeCh_BCC_ModeCh;
    Rte_DE_UInt8 Rte_BCC_StCh_BCC_StCh;
    Rte_DE_Float Rte_BCC_UChReq_BCC_UChReq;
    Rte_DE_Boolean Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull;
    Rte_DE_rt_Array_Float_24 Rte_BCF_CMdulAbsv_BCF_CMdulAbsv;
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_SohPack_BCF_SohPack;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Float Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
    Rte_DE_Float Rte_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour;
    Rte_DE_Float Rte_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu;
    Rte_DE_Float Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Boolean Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    Rte_DE_UInt16 Rte_BTHM_StSys_BTHM_StSys;
    Rte_DE_Float Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    Rte_DE_Float Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_BTHM_TPack_BTHM_TPack;
    Rte_DE_Boolean Rte_CIL_BatCoolType_CIL_BatCoolType;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CIL_StAcChCnct_CIL_StAcChCnct;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_Boolean Rte_DEH_bAcvChInh_DEH_bAcvChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
}Rte_tsRB_swc_BatChCtl_BCC_10ms;

typedef struct
{
    Rte_DE_Boolean Rte_BCC_ChgCCSts_BCC_ChgCCSts;
    Rte_DE_UInt8 Rte_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault;
    Rte_DE_UInt8 Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ;
    Rte_DE_UInt8 Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt;
    Rte_DE_Float Rte_BCC_IObcLimn_BCC_IObcLimn;
    Rte_DE_UInt8 Rte_BCC_StAcChReq_BCC_StAcChReq;
    Rte_DE_UInt8 Rte_BCC_StAcSys_BCC_StAcSys;
    Rte_DE_Boolean Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq;
    Rte_DE_Float Rte_BCC_UObcLimn_BCC_UObcLimn;
    Rte_DE_Boolean Rte_BCC_bAcvDig10_BCC_bAcvDig10;
    Rte_DE_Boolean Rte_BCC_bS2Ctrl_BCC_bS2Ctrl;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Boolean Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt8 Rte_BTHM_ErrChEnd_BTHM_ErrChEnd;
    Rte_DE_UInt16 Rte_BTHM_StSys_BTHM_StSys;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
    Rte_DE_Float Rte_CIL_CP_Vol_CIL_CP_Vol;
    Rte_DE_UInt8 Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt;
    Rte_DE_UInt8 Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv;
    Rte_DE_UInt8 Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass;
    Rte_DE_UInt8 Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
    Rte_DE_UInt8 Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
    Rte_DE_UInt8 Rte_CIL_OnBdCPline_CIL_OnBdCPline;
    Rte_DE_UInt8 Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
    Rte_DE_Float Rte_CIL_PwrEACAct_CIL_PwrEACAct;
    Rte_DE_Float Rte_CIL_PwrPtcAct_CIL_PwrPtcAct;
    Rte_DE_UInt8 Rte_CIL_RAcChCnctn_CIL_RAcChCnctn;
    Rte_DE_UInt8 Rte_CIL_RDisChCnctn_CIL_RDisChCnctn;
    Rte_DE_UInt8 Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts;
    Rte_DE_UInt8 Rte_CIL_StAcChCnct_CIL_StAcChCnct;
    Rte_DE_UInt8 Rte_CIL_StBatHvReq_CIL_StBatHvReq;
    Rte_DE_UInt8 Rte_CIL_StChAllwd_CIL_StChAllwd;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_UInt8 Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc;
    Rte_DE_UInt8 Rte_CIL_StObc_CIL_StObc;
    Rte_DE_UInt8 Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor;
    Rte_DE_Float Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
    Rte_DE_Float Rte_CIL_TAcChPointPos_CIL_TAcChPointPos;
    Rte_DE_Float Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
    Rte_DE_Float Rte_CIL_UObcChInp_CIL_UObcChInp;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_Boolean Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh;
    Rte_DE_Boolean Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh;
    Rte_DE_Boolean Rte_DEH_bAcvChInh_DEH_bAcvChInh;
    Rte_DE_Boolean Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
}Rte_tsRB_swc_BatChCtl_AC_10ms;

typedef struct
{
    Rte_DE_UInt32 Rte_BCC_ErrInfo_BCC_ErrInfo;
    Rte_DE_Boolean Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Float Rte_BPP_IAct_BPP_IAct;
    Rte_DE_UInt8 Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha;
    Rte_DE_UInt8 Rte_BSOF_ErrChImpo_BSOF_ErrChImpo;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
    Rte_DE_UInt8 Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
    Rte_DE_Float Rte_BSOF_IChrgrMax_BSOF_IChrgrMax;
    Rte_DE_Float Rte_BSOF_IChrgrMin_BSOF_IChrgrMin;
    Rte_DE_UInt8 Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn;
    Rte_DE_UInt8 Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy;
    Rte_DE_Float Rte_BSOF_UChrgrMax_BSOF_UChrgrMax;
    Rte_DE_Float Rte_BSOF_UChrgrMin_BSOF_UChrgrMin;
    Rte_DE_Float Rte_BSOF_UDchaMax_BSOF_UDchaMax;
    Rte_DE_Float Rte_BSOF_UDchaMin_BSOF_UDchaMin;
    Rte_DE_Boolean Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn;
    Rte_DE_UInt32 Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt8 Rte_BTHM_ErrChEnd_BTHM_ErrChEnd;
    Rte_DE_UInt16 Rte_BTHM_StSys_BTHM_StSys;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
    Rte_DE_UInt8 Rte_CIL_ChgCCSts_CIL_ChgCCSts;
    Rte_DE_UInt8 Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC;
    Rte_DE_UInt8 Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT;
    Rte_DE_UInt8 Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
    Rte_DE_Float Rte_CIL_PwrEACAct_CIL_PwrEACAct;
    Rte_DE_Float Rte_CIL_PwrPtcAct_CIL_PwrPtcAct;
    Rte_DE_UInt8 Rte_CIL_StAcChCnct_CIL_StAcChCnct;
    Rte_DE_UInt8 Rte_CIL_StBatHvReq_CIL_StBatHvReq;
    Rte_DE_UInt8 Rte_CIL_StChAllwd_CIL_StChAllwd;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_Float Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
    Rte_DE_Float Rte_CIL_TDcChPointPos_CIL_TDcChPointPos;
    Rte_DE_Float Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_CTC_StRlyCh_CTC_StRlyCh;
    Rte_DE_UInt16 Rte_CTC_StSysInt_CTC_StSysInt;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd4_DEH_ErrCfmd4;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_Boolean Rte_DEH_bAcvChInh_DEH_bAcvChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh;
    Rte_DE_Boolean Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
    Rte_DE_UInt8 Rte_ELHPN_StIsln_ELHPN_StIsln;
    Rte_DE_UInt8 Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    Rte_DE_UInt8 Rte_EVCSH_ChMode_EVCSH_ChMode;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync;
    Rte_DE_Float Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
    Rte_DE_UInt8 Rte_EVCSH_StBatRdy_EVCSH_StBatRdy;
    Rte_DE_UInt8 Rte_EVCSH_StDcCh_EVCSH_StDcCh;
    Rte_DE_UInt16 Rte_EVCSH_StInt_EVCSH_StInt;
    Rte_DE_UInt8 Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq;
    Rte_DE_Float Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
    Rte_DE_Boolean Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl;
    Rte_DE_Boolean Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd;
    Rte_DE_Boolean Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu;
    Rte_DE_Boolean Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq;
    Rte_DE_Boolean Rte_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha;
    Rte_DE_UInt8 Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU;
    Rte_DE_Boolean Rte_TimeOut_CRO00_BCC_TimeOutCRO00;
    Rte_DE_Boolean Rte_TimeOut_CROAA_BCC_TimeOutCROAA;
}Rte_tsRB_swc_BatChCtl_DC_10ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BCC_StAcSys_BCC_StAcSys;
    Rte_DE_Boolean Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
    Rte_DE_UInt8 Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    Rte_DE_UInt8 Rte_EVCSH_StBatRdy_EVCSH_StBatRdy;
    Rte_DE_UInt16 Rte_EVCSH_StInt_EVCSH_StInt;
    Rte_DE_Boolean Rte_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl;
    Rte_DE_Boolean Rte_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd;
    Rte_DE_Boolean Rte_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
    Rte_DE_Boolean Rte_TimeOut_CRO00_BCC_TimeOutCRO00;
    Rte_DE_Boolean Rte_TimeOut_CROAA_BCC_TimeOutCROAA;
}Rte_tsRB_swc_BatChCtl_BCC_Init;

typedef struct
{
    Rte_DE_rt_Array_Float_255 Rte_BBC_ICellBaln_BBC_ICellBaln;
    Rte_DE_rt_Array_Boolean_24 Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln;
    Rte_DE_Boolean Rte_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull;
    Rte_DE_rt_Array_Float_24 Rte_BCF_CMdulAbsv_BCF_CMdulAbsv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv;
    Rte_DE_Float Rte_BCF_ChIIntglNv_BCF_ChIIntglNv;
    Rte_DE_Float Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv;
    Rte_DE_Float Rte_BCF_DeltAhNv_BCF_DeltAhNv;
    Rte_DE_Float Rte_BCF_EPackRmng_BCF_EPackRmng;
    Rte_DE_Boolean Rte_BCF_EnaPack_BCF_EnaPack;
    Rte_DE_UInt32 Rte_BCF_ErrInfo_BCF_ErrInfo;
    Rte_DE_UInt32 Rte_BCF_ErrInfo1_BCF_ErrInfo1;
    Rte_DE_UInt32 Rte_BCF_ErrInfo2_BCF_ErrInfo2;
    Rte_DE_UInt32 Rte_BCF_ErrInfo3_BCF_ErrInfo3;
    Rte_DE_UInt32 Rte_BCF_ErrInfo4_BCF_ErrInfo4;
    Rte_DE_UInt32 Rte_BCF_ErrInfo5_BCF_ErrInfo5;
    Rte_DE_UInt32 Rte_BCF_ErrInfo6_BCF_ErrInfo6;
    Rte_DE_Float Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv;
    Rte_DE_Float Rte_BCF_IChLimInt_BCF_IChLimInt;
    Rte_DE_Float Rte_BCF_IChLimMap_BCF_IChLimMap;
    Rte_DE_Float Rte_BCF_IChMax_BCF_IChMax;
    Rte_DE_Float Rte_BCF_IChPredLimInt_BCF_IChPredLimInt;
    Rte_DE_Float Rte_BCF_IDchaLimInt_BCF_IDchaLimInt;
    Rte_DE_Float Rte_BCF_IDchaLimMap_BCF_IDchaLimMap;
    Rte_DE_Float Rte_BCF_IDchaMax_BCF_IDchaMax;
    Rte_DE_Float Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt;
    Rte_DE_Float Rte_BCF_IIntglNv_BCF_IIntglNv;
    Rte_DE_UInt8 Rte_BCF_NrMdulMax_BCF_NrMdulMax;
    Rte_DE_rt_Array_Float_24 Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss;
    Rte_DE_rt_Array_Float_24 Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv;
    Rte_DE_Float Rte_BCF_RPackInt_BCF_RPackInt;
    Rte_DE_Boolean Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv;
    Rte_DE_Boolean Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv;
    Rte_DE_rt_Array_Float_255 Rte_BCF_SocCell_BCF_SocCell;
    Rte_DE_rt_Array_Float_255 Rte_BCF_SocCellDelta_BCF_SocCellDelta;
    Rte_DE_Float Rte_BCF_SocCellMax_BCF_SocCellMax;
    Rte_DE_Float Rte_BCF_SocCellMin_BCF_SocCellMin;
    Rte_DE_Float Rte_BCF_SocCnsActNv_BCF_SocCnsActNv;
    Rte_DE_Float Rte_BCF_SocLimMax_BCF_SocLimMax;
    Rte_DE_Float Rte_BCF_SocLimMin_BCF_SocLimMin;
    Rte_DE_rt_Array_Float_24 Rte_BCF_SocMdul_BCF_SocMdul;
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv;
    Rte_DE_Float Rte_BCF_SohCalNv_BCF_SohCalNv;
    Rte_DE_Float Rte_BCF_SohCycNv_BCF_SohCycNv;
    Rte_DE_Float Rte_BCF_SohPack_BCF_SohPack;
    Rte_DE_Float Rte_BCF_SohPackNv_BCF_SohPackNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv;
    Rte_DE_rt_Array_Float_144 Rte_BCF_StAryFlsNv_BCF_StAryFlsNv;
    Rte_DE_rt_Array_UInt8_4 Rte_BCF_StLimnId_BCF_StLimnId;
    Rte_DE_rt_Array_Float_24 Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut;
    Rte_DE_rt_Array_Float_24 Rte_BCF_TMdulEstimd_BCF_TMdulEstimd;
    Rte_DE_rt_Array_UInt32_24 Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv;
    Rte_DE_rt_Array_UInt32_24 Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv;
    Rte_DE_UInt32 Rte_BCF_TiBatOffNv_BCF_TiBatOffNv;
    Rte_DE_UInt32 Rte_BCF_TiChFullOff_BCF_TiChFullOff;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Float Rte_BCF_UCellAvg_BCF_UCellAvg;
    Rte_DE_Float Rte_BCF_UChLimInt_BCF_UChLimInt;
    Rte_DE_Float Rte_BCF_UChPredLimInt_BCF_UChPredLimInt;
    Rte_DE_Float Rte_BCF_UDchaLimInt_BCF_UDchaLimInt;
    Rte_DE_Float Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt;
    Rte_DE_rt_Array_Float_24 Rte_BCF_UMdul_BCF_UMdul;
    Rte_DE_Float Rte_BCF_UPackCircOpen_BCF_UPackCircOpen;
    Rte_DE_Boolean Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind;
    Rte_DE_Boolean Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
    Rte_DE_rt_Array_UInt8_24 Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls;
    Rte_DE_rt_Array_UInt8_24 Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv;
    Rte_DE_rt_Array_Float_255 Rte_BMC_UCell_BMC_UCell;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
    Rte_DE_Boolean Rte_BPP_bAcvCTest_BPP_bAcvCTest;
    Rte_DE_Boolean Rte_BSTC_RstCmd100_BSTC_RstCmd100;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt32 Rte_BSTC_TiBatOff_BSTC_TiBatOff;
    Rte_DE_rt_Array_Float_24 Rte_BTHM_MfCoolt_BTHM_MfCoolt;
    Rte_DE_Float Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    Rte_DE_rt_Array_Float_54 Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn;
    Rte_DE_Float Rte_BTHM_TPack_BTHM_TPack;
    Rte_DE_rt_Array_Boolean_24 Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno;
    Rte_DE_rt_Array_Boolean_24 Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CIL_SecRtc_CIL_SecRtc;
    Rte_DE_rt_Array_UInt8_24 Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul;
    Rte_DE_UInt8 Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    Rte_DE_UInt8 Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
    Rte_DE_UInt8 Rte_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd6_DEH_ErrCfmd6;
    Rte_DE_UInt16 Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_UInt8 Rte_DEH_StSocCal_DEH_StSocCal;
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_UInt32 Rte_DEH_TiChFullOff_DEH_TiChFullOff;
    Rte_DE_Float Rte_DEH_ValPackSoc_DEH_ValPackSoc;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCellByMdul_MCC_NrCellByMdul;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
    Rte_DE_rt_Array_Float_24 Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls;
    Rte_DE_Float Rte_NVM_ChIIntglFls_NVM_ChIIntglFls;
    Rte_DE_Float Rte_NVM_ChgDeltAh_NVM_ChgDeltAh;
    Rte_DE_Float Rte_NVM_DeltAh_NVM_DeltAh;
    Rte_DE_Float Rte_NVM_EBatChTot_NVM_EBatChTot;
    Rte_DE_Float Rte_NVM_FullChgSOH_NVM_FullChgSOH;
    Rte_DE_Float Rte_NVM_IIntglFls_NVM_IIntglFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls;
    Rte_DE_Boolean Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
    Rte_DE_Boolean Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
    Rte_DE_Float Rte_NVM_SocCnsAct_NVM_SocCnsAct;
    Rte_DE_Float Rte_NVM_SocPackScld_NVM_SocPackScld;
    Rte_DE_Float Rte_NVM_SocUOcIni_NVM_SocUOcIni;
    Rte_DE_Float Rte_NVM_SohCalFls_NVM_SohCalFls;
    Rte_DE_Float Rte_NVM_SohCycFls_NVM_SohCycFls;
    Rte_DE_Float Rte_NVM_SohPackFls_NVM_SohPackFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls;
    Rte_DE_rt_Array_Float_144 Rte_NVM_StAryFls_NVM_StAryFls;
    Rte_DE_Float Rte_NVM_TPackFls_NVM_TPackFls;
    Rte_DE_UInt32 Rte_NVM_TiBatOffFls_NVM_TiBatOffFls;
    Rte_DE_rt_Array_UInt32_24 Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls;
    Rte_DE_rt_Array_UInt32_24 Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls;
    Rte_DE_rt_Array_UInt8_24 Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls;
}Rte_tsRB_swc_BatCoreFct_BCF_100ms;

typedef struct
{
    Rte_DE_rt_Array_Float_24 Rte_BCF_CMdulAbsv_BCF_CMdulAbsv;
    Rte_DE_Float Rte_BCF_ChIIntglNv_BCF_ChIIntglNv;
    Rte_DE_Float Rte_BCF_EPackRmng_BCF_EPackRmng;
    Rte_DE_UInt32 Rte_BCF_ErrInfo_BCF_ErrInfo;
    Rte_DE_UInt32 Rte_BCF_ErrInfo1_BCF_ErrInfo1;
    Rte_DE_UInt32 Rte_BCF_ErrInfo2_BCF_ErrInfo2;
    Rte_DE_UInt32 Rte_BCF_ErrInfo3_BCF_ErrInfo3;
    Rte_DE_UInt32 Rte_BCF_ErrInfo4_BCF_ErrInfo4;
    Rte_DE_UInt32 Rte_BCF_ErrInfo5_BCF_ErrInfo5;
    Rte_DE_UInt32 Rte_BCF_ErrInfo6_BCF_ErrInfo6;
    Rte_DE_Float Rte_BCF_IChLimInt_BCF_IChLimInt;
    Rte_DE_Float Rte_BCF_IChLimMap_BCF_IChLimMap;
    Rte_DE_Float Rte_BCF_IChMax_BCF_IChMax;
    Rte_DE_Float Rte_BCF_IChPredLimInt_BCF_IChPredLimInt;
    Rte_DE_Float Rte_BCF_IDchaLimInt_BCF_IDchaLimInt;
    Rte_DE_Float Rte_BCF_IDchaLimMap_BCF_IDchaLimMap;
    Rte_DE_Float Rte_BCF_IDchaMax_BCF_IDchaMax;
    Rte_DE_Float Rte_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt;
    Rte_DE_Float Rte_BCF_IIntglNv_BCF_IIntglNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_PwrMdulLoss_BCF_PwrMdulLoss;
    Rte_DE_Float Rte_BCF_RPackInt_BCF_RPackInt;
    Rte_DE_rt_Array_Float_255 Rte_BCF_SocCell_BCF_SocCell;
    Rte_DE_rt_Array_Float_255 Rte_BCF_SocCellDelta_BCF_SocCellDelta;
    Rte_DE_Float Rte_BCF_SocCnsActNv_BCF_SocCnsActNv;
    Rte_DE_Float Rte_BCF_SocLimMax_BCF_SocLimMax;
    Rte_DE_Float Rte_BCF_SocLimMin_BCF_SocLimMin;
    Rte_DE_rt_Array_Float_24 Rte_BCF_SocMdul_BCF_SocMdul;
    Rte_DE_Float Rte_BCF_SohCalNv_BCF_SohCalNv;
    Rte_DE_Float Rte_BCF_SohCycNv_BCF_SohCycNv;
    Rte_DE_Float Rte_BCF_SohPack_BCF_SohPack;
    Rte_DE_Float Rte_BCF_SohPackNv_BCF_SohPackNv;
    Rte_DE_rt_Array_UInt8_4 Rte_BCF_StLimnId_BCF_StLimnId;
    Rte_DE_rt_Array_Float_24 Rte_BCF_TCooltMdulOut_BCF_TCooltMdulOut;
    Rte_DE_rt_Array_Float_24 Rte_BCF_TMdulEstimd_BCF_TMdulEstimd;
    Rte_DE_UInt32 Rte_BCF_TiBatOffNv_BCF_TiBatOffNv;
    Rte_DE_Float Rte_BCF_UChLimInt_BCF_UChLimInt;
    Rte_DE_Float Rte_BCF_UChPredLimInt_BCF_UChPredLimInt;
    Rte_DE_Float Rte_BCF_UDchaLimInt_BCF_UDchaLimInt;
    Rte_DE_Float Rte_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt;
    Rte_DE_rt_Array_Float_24 Rte_BCF_UMdul_BCF_UMdul;
    Rte_DE_Float Rte_BCF_UPackCircOpen_BCF_UPackCircOpen;
    Rte_DE_Boolean Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
    Rte_DE_rt_Array_UInt8_24 Rte_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls;
}Rte_tsRB_swc_BatCoreFct_BCF_Init;

typedef struct
{
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
    Rte_DE_Float Rte_BCF_IChPredLim_BCF_IChPredLim;
    Rte_DE_Float Rte_BCF_IDchaLim_BCF_IDchaLim;
    Rte_DE_Float Rte_BCF_IDchaPredLim_BCF_IDchaPredLim;
    Rte_DE_Float Rte_BCF_PwrChLim_BCF_PwrChLim;
    Rte_DE_Float Rte_BCF_PwrChPredLim_BCF_PwrChPredLim;
    Rte_DE_Float Rte_BCF_PwrDchaLim_BCF_PwrDchaLim;
    Rte_DE_Float Rte_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim;
    Rte_DE_Float Rte_BCF_UChLim_BCF_UChLim;
    Rte_DE_Float Rte_BCF_UChPredLim_BCF_UChPredLim;
    Rte_DE_Float Rte_BCF_UDchaLim_BCF_UDchaLim;
    Rte_DE_Float Rte_BCF_UDchaPredLim_BCF_UDchaPredLim;
    Rte_DE_UInt16 Rte_BTHM_StSys_BTHM_StSys;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_Boolean Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh;
    Rte_DE_Boolean Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2;
    Rte_DE_Boolean Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2;
    Rte_DE_Boolean Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh;
}Rte_tsRB_swc_BatCoreFct_BCF_10ms;

typedef struct
{
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
    Rte_DE_Float Rte_BCF_IDchaLim_BCF_IDchaLim;
    Rte_DE_UInt8 Rte_BPIU_ErrIChLim_BPIU_ErrIChLim;
    Rte_DE_UInt8 Rte_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim;
    Rte_DE_UInt8 Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur;
    Rte_DE_UInt32 Rte_BPIU_ErrInfo_BPIU_ErrInfo;
    Rte_DE_UInt8 Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI;
    Rte_DE_UInt8 Rte_BPIU_StChkUMax_BPIU_StChkUMax;
    Rte_DE_UInt8 Rte_BPIU_StChkUMin_BPIU_StChkUMin;
    Rte_DE_Float Rte_BPP_IChAct_BPP_IChAct;
    Rte_DE_Float Rte_BPP_IDchaAct_BPP_IDchaAct;
    Rte_DE_Boolean Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CIL_StAcChCnct_CIL_StAcChCnct;
    Rte_DE_UInt8 Rte_CIL_StPtIndcr_CIL_StPtIndcr;
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
    Rte_DE_Boolean Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv;
    Rte_DE_UInt8 Rte_CIL_bVldBatIHv_CIL_bVldBatIHv;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
}Rte_tsRB_swc_BatProtnIU_BPIU_50ms;

typedef struct
{
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_rt_Array_Float_24 Rte_BCF_UMdul_BCF_UMdul;
    Rte_DE_rt_Array_Float_255 Rte_BMC_UCell_BMC_UCell;
    Rte_DE_UInt8 Rte_BPIU_ErrCellU_BPIU_ErrCellU;
    Rte_DE_UInt8 Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif;
    Rte_DE_UInt8 Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver;
    Rte_DE_UInt8 Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn;
    Rte_DE_UInt16 Rte_BPIU_IdCellUMax_BPIU_IdCellUMax;
    Rte_DE_UInt16 Rte_BPIU_IdCellUMin_BPIU_IdCellUMin;
    Rte_DE_UInt8 Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax;
    Rte_DE_UInt8 Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin;
    Rte_DE_UInt8 Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax;
    Rte_DE_UInt8 Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_Boolean Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv;
    Rte_DE_UInt8 Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    Rte_DE_UInt8 Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    Rte_DE_UInt8 Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
    Rte_DE_UInt8 Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCellByMdul_MCC_NrCellByMdul;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
}Rte_tsRB_swc_BatProtnIU_BPIU_100ms;

typedef struct
{
    Rte_DE_UInt16 Rte_BPIU_IdCellUMax_BPIU_IdCellUMax;
    Rte_DE_UInt16 Rte_BPIU_IdCellUMin_BPIU_IdCellUMin;
    Rte_DE_UInt8 Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax;
    Rte_DE_UInt8 Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
}Rte_tsRB_swc_BatProtnIU_BatProtnIU_Init;

typedef struct
{
    Rte_DE_Boolean Rte_BCF_EnaPack_BCF_EnaPack;
    Rte_DE_rt_Array_Float_255 Rte_BCF_SocCell_BCF_SocCell;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_SohPack_BCF_SohPack;
    Rte_DE_UInt8 Rte_BPP_ErrCellT_BPP_ErrCellT;
    Rte_DE_UInt8 Rte_BPP_ErrSocJmp_BPP_ErrSocJmp;
    Rte_DE_UInt8 Rte_BPP_ErrSocVal_BPP_ErrSocVal;
    Rte_DE_Float Rte_BPP_SocLimMax_BPP_SocLimMax;
    Rte_DE_Float Rte_BPP_SocLimMin_BPP_SocLimMin;
    Rte_DE_Float Rte_BPP_TCellMaxLim_BPP_TCellMaxLim;
    Rte_DE_Float Rte_BPP_TCellMinLim_BPP_TCellMinLim;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw;
    Rte_DE_UInt8 Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
}Rte_tsRB_swc_BatProtnPack_BPP_100ms;

typedef struct
{
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_UInt32 Rte_BPP_ErrInfo_BPP_ErrInfo;
    Rte_DE_UInt8 Rte_BPP_ErrPackU_BPP_ErrPackU;
    Rte_DE_Float Rte_BPP_IAct_BPP_IAct;
    Rte_DE_Float Rte_BPP_IChAct_BPP_IChAct;
    Rte_DE_Float Rte_BPP_IDchaAct_BPP_IDchaAct;
    Rte_DE_Float Rte_BPP_PwrAct_BPP_PwrAct;
    Rte_DE_Boolean Rte_BPP_bAcvCTest_BPP_bAcvCTest;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
}Rte_tsRB_swc_BatProtnPack_BPP_50ms;

typedef struct
{
    Rte_DE_Float Rte_BPP_SocLimMax_BPP_SocLimMax;
    Rte_DE_Float Rte_BPP_SocLimMin_BPP_SocLimMin;
    Rte_DE_Float Rte_BPP_TCellMaxLim_BPP_TCellMaxLim;
    Rte_DE_Float Rte_BPP_TCellMinLim_BPP_TCellMinLim;
}Rte_tsRB_swc_BatProtnPack_BPP_Init;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Float Rte_BSOF_UChrgr_BSOF_UChrgr;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt8 Rte_BTHM_ErrChEnd_BTHM_ErrChEnd;
    Rte_DE_UInt32 Rte_BTHM_ErrInfo_BTHM_ErrInfo;
    Rte_DE_UInt8 Rte_BTHM_IdCellTMax_BTHM_IdCellTMax;
    Rte_DE_UInt8 Rte_BTHM_IdCellTMin_BTHM_IdCellTMin;
    Rte_DE_UInt8 Rte_BTHM_IdMdulTMax_BTHM_IdMdulTMax;
    Rte_DE_UInt8 Rte_BTHM_IdMdulTMin_BTHM_IdMdulTMin;
    Rte_DE_rt_Array_Float_24 Rte_BTHM_MfCoolt_BTHM_MfCoolt;
    Rte_DE_Boolean Rte_BTHM_ReqRePrech_BTHM_ReqRePrech;
    Rte_DE_UInt8 Rte_BTHM_StErrTOver_BTHM_StErrTOver;
    Rte_DE_UInt8 Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq;
    Rte_DE_UInt8 Rte_BTHM_StRlyMain_BTHM_StRlyMain;
    Rte_DE_UInt8 Rte_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg;
    Rte_DE_UInt16 Rte_BTHM_StSys_BTHM_StSys;
    Rte_DE_UInt8 Rte_BTHM_StThermReq_BTHM_StThermReq;
    Rte_DE_Float Rte_BTHM_TBatTgt_BTHM_TBatTgt;
    Rte_DE_Float Rte_BTHM_TBcuSnsr_BTHM_TBcuSnsr;
    Rte_DE_Float Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    Rte_DE_Float Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
    Rte_DE_rt_Array_Float_54 Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn;
    Rte_DE_rt_Array_Float_32 Rte_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr;
    Rte_DE_Float Rte_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin;
    Rte_DE_rt_Array_Float_54 Rte_BTHM_TMdulSnsr_BTHM_TMdulSnsr;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
    Rte_DE_rt_Array_Float_54 Rte_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw;
    Rte_DE_Float Rte_BTHM_TOptmMax_BTHM_TOptmMax;
    Rte_DE_Float Rte_BTHM_TOptmMin_BTHM_TOptmMin;
    Rte_DE_Float Rte_BTHM_TPack_BTHM_TPack;
    Rte_DE_Boolean Rte_BTHM_bAcvDig64_BTHM_bAcvDig64;
    Rte_DE_Boolean Rte_BTHM_bAcvDig93_BTHM_bAcvDig93;
    Rte_DE_rt_Array_Boolean_24 Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno;
    Rte_DE_rt_Array_Boolean_24 Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT;
    Rte_DE_Boolean Rte_CIL_BatCoolType_CIL_BatCoolType;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_Float Rte_CIL_SpdVeh_CIL_SpdVeh;
    Rte_DE_rt_Array_UInt8_54 Rte_CIL_StCellT_CIL_StCellT;
    Rte_DE_UInt8 Rte_CIL_StProj_CIL_StProj;
    Rte_DE_Float Rte_CIL_TBd_CIL_TBd;
    Rte_DE_rt_Array_Float_32 Rte_CIL_TBdSnsr_CIL_TBdSnsr;
    Rte_DE_SInt16 Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
    Rte_DE_SInt16 Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
    Rte_DE_rt_Array_Float_54 Rte_CIL_TMdul_CIL_TMdul;
    Rte_DE_rt_Array_Float_32 Rte_CIL_TMdulCtlr_CIL_TMdulCtlr;
    Rte_DE_SInt16 Rte_CIL_TSnsrI_CIL_TSnsrI;
    Rte_DE_Float Rte_CIL_UObcChOutp_CIL_UObcChOutp;
    Rte_DE_Boolean Rte_CIL_bDCDCW_CIL_bDCDCW;
    Rte_DE_UInt8 Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StRlyHeat_CTC_StRlyHeat;
    Rte_DE_UInt8 Rte_CTC_StRlyPos_CTC_StRlyPos;
    Rte_DE_Boolean Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_Boolean Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh;
    Rte_DE_UInt8 Rte_MCC_NrAFETot_MCC_NrAFETot;
    Rte_DE_UInt8 Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
    Rte_DE_UInt8 Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
    Rte_DE_UInt8 Rte_MCC_StMdulCu_MCC_StMdulCu;
}Rte_tsRB_swc_BatThermHndlgMngt_BTHM_100ms;

typedef struct
{
    Rte_DE_rt_Array_Float_24 Rte_BTHM_MfCoolt_BTHM_MfCoolt;
    Rte_DE_UInt8 Rte_BTHM_StErrTOver_BTHM_StErrTOver;
    Rte_DE_UInt8 Rte_BTHM_StThermReq_BTHM_StThermReq;
    Rte_DE_Float Rte_BTHM_TOptmMax_BTHM_TOptmMax;
    Rte_DE_Float Rte_BTHM_TOptmMin_BTHM_TOptmMin;
    Rte_DE_rt_Array_Boolean_24 Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno;
    Rte_DE_rt_Array_Boolean_24 Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT;
}Rte_tsRB_swc_BatThermHndlgMngt_BTHM_Init;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
    Rte_DE_Float Rte_BPP_IAct_BPP_IAct;
    Rte_DE_Float Rte_BPP_PwrAct_BPP_PwrAct;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_Boolean Rte_BSTC_TrigCh_BSTC_TrigCh;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_BWLD_CBatChTot_BWLD_CBatChTot;
    Rte_DE_Float Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv;
    Rte_DE_Float Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot;
    Rte_DE_Float Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv;
    Rte_DE_Float Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot;
    Rte_DE_Float Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv;
    Rte_DE_UInt16 Rte_BWLD_CtrCh_BWLD_CtrCh;
    Rte_DE_UInt16 Rte_BWLD_CtrChNv_BWLD_CtrChNv;
    Rte_DE_UInt16 Rte_BWLD_CtrDcha_BWLD_CtrDcha;
    Rte_DE_UInt16 Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv;
    Rte_DE_UInt16 Rte_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv;
    Rte_DE_UInt16 Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
    Rte_DE_Float Rte_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc;
    Rte_DE_Float Rte_BWLD_EBatChTot_BWLD_EBatChTot;
    Rte_DE_Float Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv;
    Rte_DE_Float Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc;
    Rte_DE_Float Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
    Rte_DE_Float Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv;
    Rte_DE_Float Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc;
    Rte_DE_Float Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot;
    Rte_DE_Float Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv;
    Rte_DE_Float Rte_BWLD_IBatChMax_BWLD_IBatChMax;
    Rte_DE_Float Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv;
    Rte_DE_Float Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax;
    Rte_DE_Float Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv;
    Rte_DE_Float Rte_BWLD_PBatChMax_BWLD_PBatChMax;
    Rte_DE_Float Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv;
    Rte_DE_Float Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax;
    Rte_DE_Float Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv;
    Rte_DE_Float Rte_BWLD_SocBatMax_BWLD_SocBatMax;
    Rte_DE_Float Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv;
    Rte_DE_Float Rte_BWLD_SocBatMin_BWLD_SocBatMin;
    Rte_DE_Float Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv;
    Rte_DE_Float Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax;
    Rte_DE_Float Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv;
    Rte_DE_Float Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin;
    Rte_DE_Float Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax;
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin;
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax;
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin;
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv;
    Rte_DE_Float Rte_BWLD_UCellMax_BWLD_UCellMax;
    Rte_DE_Float Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv;
    Rte_DE_Float Rte_BWLD_UCellMin_BWLD_UCellMin;
    Rte_DE_Float Rte_BWLD_UCellMinNv_BWLD_UCellMinNv;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_Boolean Rte_CTC_bAcvCh_CTC_bAcvCh;
    Rte_DE_UInt8 Rte_DEH_LvlErr_DEH_LvlErr;
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_UInt8 Rte_MCC_StMdulCu_MCC_StMdulCu;
    Rte_DE_Float Rte_NVM_CBatChTot_NVM_CBatChTot;
    Rte_DE_Float Rte_NVM_CBatDchaTot_NVM_CBatDchaTot;
    Rte_DE_Float Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
    Rte_DE_UInt16 Rte_NVM_CtrCh_NVM_CtrCh;
    Rte_DE_UInt16 Rte_NVM_CtrDcha_NVM_CtrDcha;
    Rte_DE_Float Rte_NVM_EBatChTot_NVM_EBatChTot;
    Rte_DE_Float Rte_NVM_EBatDchaTot_NVM_EBatDchaTot;
    Rte_DE_Float Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
    Rte_DE_Float Rte_NVM_IBatChMax_NVM_IBatChMax;
    Rte_DE_Float Rte_NVM_IBatDchaMax_NVM_IBatDchaMax;
    Rte_DE_Float Rte_NVM_PBatChMax_NVM_PBatChMax;
    Rte_DE_Float Rte_NVM_PBatDchaMax_NVM_PBatDchaMax;
    Rte_DE_Float Rte_NVM_SocBatMax_NVM_SocBatMax;
    Rte_DE_Float Rte_NVM_SocBatMin_NVM_SocBatMin;
    Rte_DE_Float Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
    Rte_DE_Float Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
    Rte_DE_Float Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
    Rte_DE_Float Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
    Rte_DE_Float Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
    Rte_DE_Float Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
    Rte_DE_Float Rte_NVM_UCellMax_NVM_UCellMax;
    Rte_DE_Float Rte_NVM_UCellMin_NVM_UCellMin;
}Rte_tsRB_swc_BatWntyLogtcData_BWLD_100ms;

typedef struct
{
    Rte_DE_UInt32 Rte_BWLD_TiBatAgi_BWLD_TiBatAgi;
    Rte_DE_UInt32 Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_UInt32 Rte_NVM_TiBatAgi_NVM_TiBatAgi;
}Rte_tsRB_swc_BatWntyLogtcData_BWLD_1000ms;

typedef struct
{
    Rte_DE_Boolean Rte_BBC_bAcvBaln_BBC_bAcvBaln;
    Rte_DE_UInt8 Rte_BCC_StAcSys_BCC_StAcSys;
    Rte_DE_UInt8 Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax;
    Rte_DE_UInt8 Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin;
    Rte_DE_UInt8 Rte_BPIU_StChkUMax_BPIU_StChkUMax;
    Rte_DE_UInt8 Rte_BPIU_StChkUMin_BPIU_StChkUMin;
    Rte_DE_UInt8 Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv;
    Rte_DE_Float Rte_BSTC_DelayTime_BSTC_DelayTime;
    Rte_DE_UInt32 Rte_BSTC_ErrInfo_BSTC_ErrInfo;
    Rte_DE_UInt8 Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn;
    Rte_DE_UInt8 Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms;
    Rte_DE_Boolean Rte_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu;
    Rte_DE_UInt8 Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas;
    Rte_DE_Boolean Rte_BSTC_RstCmd_BSTC_RstCmd;
    Rte_DE_Boolean Rte_BSTC_RstCmd100_BSTC_RstCmd100;
    Rte_DE_UInt8 Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt8 Rte_BSTC_StBcuInt_BSTC_StBcuInt;
    Rte_DE_UInt8 Rte_BSTC_StBmsChk_BSTC_StBmsChk;
    Rte_DE_UInt32 Rte_BSTC_TiBatOff_BSTC_TiBatOff;
    Rte_DE_UInt32 Rte_BSTC_TiBatOn_BSTC_TiBatOn;
    Rte_DE_Boolean Rte_BSTC_TrigCh_BSTC_TrigCh;
    Rte_DE_UInt16 Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv;
    Rte_DE_Boolean Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms;
    Rte_DE_Boolean Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm;
    Rte_DE_Boolean Rte_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu;
    Rte_DE_UInt8 Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
    Rte_DE_Boolean Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm;
    Rte_DE_Boolean Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy;
    Rte_DE_Boolean Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun;
    Rte_DE_Boolean Rte_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno;
    Rte_DE_Boolean Rte_BSTC_bErrPwrOff_BSTC_bErrPwrOff;
    Rte_DE_Boolean Rte_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq;
    Rte_DE_Boolean Rte_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq;
    Rte_DE_UInt8 Rte_BTHM_StErrTOver_BTHM_StErrTOver;
    Rte_DE_UInt8 Rte_CIL_DayRtc_CIL_DayRtc;
    Rte_DE_UInt8 Rte_CIL_HourRtc_CIL_HourRtc;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CIL_MinuRtc_CIL_MinuRtc;
    Rte_DE_UInt8 Rte_CIL_ModeSysWup_CIL_ModeSysWup;
    Rte_DE_UInt8 Rte_CIL_MonthRtc_CIL_MonthRtc;
    Rte_DE_UInt8 Rte_CIL_SecRtc_CIL_SecRtc;
    Rte_DE_Float Rte_CIL_SpdVeh_CIL_SpdVeh;
    Rte_DE_UInt8 Rte_CIL_StBatHvReq_CIL_StBatHvReq;
    Rte_DE_UInt8 Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_UInt8 Rte_CIL_StChWup2_CIL_StChWup2;
    Rte_DE_UInt8 Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS;
    Rte_DE_UInt8 Rte_CIL_StRtcFlt_CIL_StRtcFlt;
    Rte_DE_UInt8 Rte_CIL_StTrml15_CIL_StTrml15;
    Rte_DE_UInt16 Rte_CIL_YearRtc_CIL_YearRtc;
    Rte_DE_Boolean Rte_CIL_bCANWakeUp_CIL_bCANWakeUp;
    Rte_DE_UInt8 Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd;
    Rte_DE_UInt8 Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    Rte_DE_UInt8 Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    Rte_DE_UInt8 Rte_CTC_ReqRlyCh_CTC_ReqRlyCh;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_CTC_StRlyChkCh_CTC_StRlyChkCh;
    Rte_DE_UInt8 Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat;
    Rte_DE_UInt8 Rte_CTC_StRlyChkPos_CTC_StRlyChkPos;
    Rte_DE_Boolean Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl;
    Rte_DE_Boolean Rte_CTC_bAcvCh_CTC_bAcvCh;
    Rte_DE_Boolean Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk;
    Rte_DE_UInt8 Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag;
    Rte_DE_UInt8 Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd5_DEH_ErrCfmd5;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_Boolean Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1;
    Rte_DE_Boolean Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2;
    Rte_DE_Boolean Rte_ELHPN_StCrash_ELHPN_StCrash;
    Rte_DE_UInt8 Rte_ELHPN_StCrashIni_ELHPN_StCrashIni;
    Rte_DE_UInt8 Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
    Rte_DE_UInt8 Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2;
    Rte_DE_UInt8 Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
    Rte_DE_UInt8 Rte_NVM_DayRtcLst_NVM_DayRtcLst;
    Rte_DE_UInt8 Rte_NVM_HourRtcLst_NVM_HourRtcLst;
    Rte_DE_UInt8 Rte_NVM_MinuRtcLst_NVM_MinuRtcLst;
    Rte_DE_UInt8 Rte_NVM_MonthRtcLst_NVM_MonthRtcLst;
    Rte_DE_UInt8 Rte_NVM_SecRtcLst_NVM_SecRtcLst;
    Rte_DE_UInt16 Rte_NVM_YearRtcLst_NVM_YearRtcLst;
}Rte_tsRB_swc_BcuStTranCtl_BSTC_10ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BCM_DoorLockStatusDrv_BCM_DoorLockStatusDrv;
    Rte_DE_UInt8 Rte_BCM_DoorLockStatusPass_BCM_DoorLockStatusPass;
    Rte_DE_UInt8 Rte_BSOF_ChAllwd_BSOF_ChAllwd;
    Rte_DE_Float Rte_BSOF_IChrgr_BSOF_IChrgr;
    Rte_DE_UInt16 Rte_BSOF_TiChAccumd_BSOF_TiChAccumd;
    Rte_DE_Float Rte_BSOF_UChrgr_BSOF_UChrgr;
    Rte_DE_Boolean Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr;
    Rte_DE_Boolean Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt;
    Rte_DE_UInt8 Rte_BSWIOSP_ACTemp_ErrFLg_ACTemp_ErrFLg;
    Rte_DE_UInt8 Rte_BSWIOSP_ACUCom_ErrFLg_ACUCom_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_BMUTempOver_ErrFLg_BMUTempOver_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_BalnCtlModl_ErrFLg_BalnCtlModl_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_BattIsoDet_ErrFLg_BattIsoDet_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_CellVoltSampleDiscon_ErrFLg_CellVoltSampleDiscon_ErrFLg;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CCS_UpdataTime_CCS_UpdataTime;
    Rte_DE_UInt8 Rte_BSWIOSP_Com_OBC_Sts_Timeout_OBC_Sts_Timeout;
    Rte_DE_UInt8 Rte_BSWIOSP_Com_PMS_BMSH_Ctrl_Timeout_PMS_BMSH_Ctrl_Timeout;
    Rte_DE_UInt8 Rte_BSWIOSP_DCTemp_ErrFLg_DCTemp_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_EVCANBusOff_ErrFLg_EVCANBusOff_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_HCMCom_ErrFLg_HCMCom_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_HCME2E_ErrFLg_HCME2E_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_HCMbusoff_ErrFLg_HCMbusoff_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_IntCANE2E_ErrFLg_IntCANE2E_ErrFLg;
    Rte_DE_UInt8 Rte_BSWIOSP_NvM_Save_Ok_NvM_Save_Ok;
    Rte_DE_Boolean Rte_BSWIOSP_RlyKCVoltSample_ErrFLg_RlyKCVoltSample_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_RlyKMVoltSample_ErrFLg_RlyKMVoltSample_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_RlyKNVoltSample_ErrFLg_RlyKNVoltSample_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_STHW_ErrFLg_STHW_ErrFLg;
    Rte_DE_Boolean Rte_BSWIOSP_VCUCom_ErrFLg_VCUCom_ErrFLg;
    Rte_DE_UInt8 Rte_BSWIOSP_WeakUpFlg_WeakUpFlg;
    Rte_DE_Boolean Rte_BSWIOSP_bCANWakeUp_bCANWakeUp;
    Rte_DE_rt_Array_UInt32_4 Rte_BmuSample_BMUCellVSt_BMUCellVSt;
    Rte_DE_UInt8 Rte_BmuSample_CellTEffective_CellTEffective;
    Rte_DE_UInt8 Rte_BmuSample_CellTempException_CellTempException;
    Rte_DE_UInt8 Rte_BmuSample_CellVEffective_CellVEffective;
    Rte_DE_UInt8 Rte_BmuSample_CellVoltException_CellVoltException;
    Rte_DE_Float Rte_CIL_ActInputVolt_CIL_ActInputVolt;
    Rte_DE_Float Rte_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
    Rte_DE_Boolean Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
    Rte_DE_Float Rte_CIL_CP_Vol_CIL_CP_Vol;
    Rte_DE_UInt8 Rte_CIL_ChargeDepthReq_CIL_ChargeDepthReq;
    Rte_DE_UInt16 Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg;
    Rte_DE_UInt8 Rte_CIL_DayRtc_CIL_DayRtc;
    Rte_DE_UInt8 Rte_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv;
    Rte_DE_UInt8 Rte_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass;
    Rte_DE_UInt32 Rte_CIL_DucycCrash_CIL_DucycCrash;
    Rte_DE_UInt8 Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
    Rte_DE_UInt32 Rte_CIL_DucycHvil_CIL_DucycHvil;
    Rte_DE_Float Rte_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt;
    Rte_DE_UInt8 Rte_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT;
    Rte_DE_UInt8 Rte_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT;
    Rte_DE_UInt16 Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
    Rte_DE_UInt32 Rte_CIL_FrqCrash_CIL_FrqCrash;
    Rte_DE_UInt32 Rte_CIL_FrqHvil_CIL_FrqHvil;
    Rte_DE_UInt8 Rte_CIL_HourRtc_CIL_HourRtc;
    Rte_DE_UInt8 Rte_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
    Rte_DE_UInt8 Rte_CIL_MinuRtc_CIL_MinuRtc;
    Rte_DE_UInt8 Rte_CIL_ModeSysWup_CIL_ModeSysWup;
    Rte_DE_UInt8 Rte_CIL_MonthRtc_CIL_MonthRtc;
    Rte_DE_UInt32 Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw;
    Rte_DE_SInt32 Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg;
    Rte_DE_SInt32 Rte_CIL_RIslnNeg_CIL_RIslnNeg;
    Rte_DE_SInt32 Rte_CIL_RIslnPos_CIL_RIslnPos;
    Rte_DE_Float Rte_CIL_RngElec_CIL_RngElec;
    Rte_DE_UInt8 Rte_CIL_SecRtc_CIL_SecRtc;
    Rte_DE_Float Rte_CIL_SpdMot_CIL_SpdMot;
    Rte_DE_Float Rte_CIL_SpdVeh_CIL_SpdVeh;
    Rte_DE_UInt8 Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn;
    Rte_DE_rt_Array_UInt8_24 Rte_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul;
    Rte_DE_UInt8 Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_UInt8 Rte_CIL_StMsgToutForObc_CIL_StMsgToutForObc;
    Rte_DE_UInt8 Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS;
    Rte_DE_UInt8 Rte_CIL_StRtcFlt_CIL_StRtcFlt;
    Rte_DE_UInt8 Rte_CIL_StTrml15_CIL_StTrml15;
    Rte_DE_Float Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
    Rte_DE_Float Rte_CIL_TAcChPointPos_CIL_TAcChPointPos;
    Rte_DE_Float Rte_CIL_TBd_CIL_TBd;
    Rte_DE_Float Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
    Rte_DE_Float Rte_CIL_TDcChPointPos_CIL_TDcChPointPos;
    Rte_DE_SInt16 Rte_CIL_TSnsrI_CIL_TSnsrI;
    Rte_DE_UInt32 Rte_CIL_TiSysRun_CIL_TiSysRun;
    Rte_DE_Float Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
    Rte_DE_Float Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
    Rte_DE_UInt16 Rte_CIL_YearRtc_CIL_YearRtc;
    Rte_DE_Boolean Rte_CIL_bCANWakeUp_CIL_bCANWakeUp;
    Rte_DE_Boolean Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv;
    Rte_DE_Boolean Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv;
    Rte_DE_UInt8 Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd;
    Rte_DE_UInt8 Rte_CIL_bVldBatIHv_CIL_bVldBatIHv;
    Rte_DE_UInt8 Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
    Rte_DE_UInt8 Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
    Rte_DE_UInt8 Rte_CIL_bVldIslnR_CIL_bVldIslnR;
    Rte_DE_UInt8 Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly;
    Rte_DE_UInt8 Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly;
    Rte_DE_UInt8 Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
    Rte_DE_UInt8 Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh;
    Rte_DE_UInt8 Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat;
    Rte_DE_UInt8 Rte_CrgChargingPermissible_CrgChargingPermissible;
    Rte_DE_UInt16 Rte_CumulativeChargingTime_CumulativeChargingTime;
    Rte_DE_UInt16 Rte_CurrentOutputValue_CurrentOutputValue;
    Rte_DE_UInt16 Rte_EHB_VehicleSpeed_EHB_VehicleSpeed;
    Rte_DE_SInt16 Rte_HvSysSample_Current_sensorTemp_Current_sensorTemp;
    Rte_DE_SInt32 Rte_HvSysSample_NegInsulationRes_NegInsulationRes;
    Rte_DE_SInt32 Rte_HvSysSample_PosInsulationRes_PosInsulationRes;
    Rte_DE_UInt16 Rte_HvSysSample_SampleCountCurrent_U16_SampleCountCurrent_U16;
    Rte_DE_UInt16 Rte_HvSysSample_SampleCountTotalVol_U16_SampleCountTotalVol_U16;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidBat_U8_SampleValidBat_U8;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidCurrent_U8_SampleValidCurrent_U8;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidIsolation_U8_SampleValidIsolation_U8;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidKC_U8_SampleValidKC_U8;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidKH_U8_SampleValidKH_U8;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidKM_U8_SampleValidKM_U8;
    Rte_DE_UInt8 Rte_HvSysSample_SampleValidKN_U8_SampleValidKN_U8;
    Rte_DE_UInt16 Rte_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
    Rte_DE_UInt8 Rte_MCC_StMdulCu_MCC_StMdulCu;
    Rte_DE_UInt32 Rte_RTC_NowSystemTick_NowSystemTick;
    Rte_DE_SInt32 Rte_RTC_RTCStateFault_RTCStateFault;
    Rte_DE_UInt8 Rte_RTC_ReadDay_ReadDay;
    Rte_DE_UInt8 Rte_RTC_ReadHour_ReadHour;
    Rte_DE_UInt8 Rte_RTC_ReadMinute_ReadMinute;
    Rte_DE_UInt8 Rte_RTC_ReadMonth_ReadMonth;
    Rte_DE_UInt8 Rte_RTC_ReadSecond_ReadSecond;
    Rte_DE_UInt16 Rte_RTC_ReadYear_ReadYear;
    Rte_DE_UInt16 Rte_VCU_ActInputVolt_VCU_ActInputVolt;
    Rte_DE_UInt8 Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
    Rte_DE_Boolean Rte_VCU_BMSH_FaultResetReq_VCU_BMSH_FaultResetReq;
    Rte_DE_UInt8 Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
    Rte_DE_UInt16 Rte_VoltageOutputValue_VoltageOutputValue;
}Rte_tsRB_swc_CIL_CIL_50ms;

typedef struct
{
    Rte_DE_rt_Array_Float_255 Rte_BMC_UCell_BMC_UCell;
    Rte_DE_UInt8 Rte_BSOF_DirChAndDcha_BSOF_DirChAndDcha;
    Rte_DE_Float Rte_BSOF_EChSng_BSOF_EChSng;
    Rte_DE_Float Rte_BSOF_IChrgrMax_BSOF_IChrgrMax;
    Rte_DE_Float Rte_BSOF_IChrgrMin_BSOF_IChrgrMin;
    Rte_DE_Float Rte_BSOF_IDchaMax_BSOF_IDchaMax;
    Rte_DE_Float Rte_BSOF_IDchaMin_BSOF_IDchaMin;
    Rte_DE_UInt8 Rte_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn;
    Rte_DE_UInt8 Rte_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy;
    Rte_DE_UInt8 Rte_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers;
    Rte_DE_UInt8 Rte_BSOF_SocDchaMax_BSOF_SocDchaMax;
    Rte_DE_UInt8 Rte_BSOF_SocDchaMin_BSOF_SocDchaMin;
    Rte_DE_Float Rte_BSOF_UChrgrMax_BSOF_UChrgrMax;
    Rte_DE_Float Rte_BSOF_UChrgrMin_BSOF_UChrgrMin;
    Rte_DE_Float Rte_BSOF_UDchaMax_BSOF_UDchaMax;
    Rte_DE_Float Rte_BSOF_UDchaMin_BSOF_UDchaMin;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn;
    Rte_DE_UInt32 Rte_BSOF_bErrMsgTout_BSOF_bErrMsgTout;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CCD_UpdataTime_CCD_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CDC_UpdataTime_CDC_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CEM_UpdataTime_CEM_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CHM_UpdataTime_CHM_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CMLP_UpdataTime_CMLP_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CML_UpdataTime_CML_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CRM_UpdataTime_CRM_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CRO_UpdataTime_CRO_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CSDP_UpdataTime_CSDP_UpdataTime;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CSD_UpdataTime_CSD_UpdataTime;
    Rte_DE_rt_Array_UInt16_130 Rte_BmuSample_BMUCell_BMUCell;
    Rte_DE_rt_Array_SInt16_8 Rte_BmuSample_BMUChipTemp_BMUChipTemp;
    Rte_DE_rt_Array_SInt16_32 Rte_BmuSample_BMUTemp_BMUTemp;
    Rte_DE_rt_Array_UInt8_32 Rte_BmuSample_BMUTempSt_BMUTempSt;
    Rte_DE_rt_Array_SInt16_8 Rte_BmuSample_BalanceTemp_BalanceTemp;
    Rte_DE_UInt8 Rte_CCD_Chg_Direction_CCD_Chg_Direction;
    Rte_DE_UInt8 Rte_CCD_Max_Allow_Soc_CCD_Max_Allow_Soc;
    Rte_DE_UInt8 Rte_CCD_Min_Allow_Soc_CCD_Min_Allow_Soc;
    Rte_DE_UInt8 Rte_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq;
    Rte_DE_Boolean Rte_CIL_BatCoolType_CIL_BatCoolType;
    Rte_DE_UInt8 Rte_CIL_CfgLvl2_CIL_CfgLvl2;
    Rte_DE_UInt8 Rte_CIL_ChargeModeReq_CIL_ChargeModeReq;
    Rte_DE_UInt8 Rte_CIL_ChgCCSts_CIL_ChgCCSts;
    Rte_DE_UInt8 Rte_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt;
    Rte_DE_Float Rte_CIL_DayTelbox_CIL_DayTelbox;
    Rte_DE_UInt8 Rte_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC;
    Rte_DE_UInt8 Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
    Rte_DE_UInt8 Rte_CIL_HWVerVeh_CIL_HWVerVeh;
    Rte_DE_UInt8 Rte_CIL_HourTelbox_CIL_HourTelbox;
    Rte_DE_Float Rte_CIL_IEACAct_CIL_IEACAct;
    Rte_DE_Float Rte_CIL_IObcChOutp_CIL_IObcChOutp;
    Rte_DE_Float Rte_CIL_MilgTot_CIL_MilgTot;
    Rte_DE_UInt8 Rte_CIL_MinuTelbox_CIL_MinuTelbox;
    Rte_DE_UInt8 Rte_CIL_MonthTelbox_CIL_MonthTelbox;
    Rte_DE_UInt8 Rte_CIL_OnBdCPline_CIL_OnBdCPline;
    Rte_DE_UInt8 Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
    Rte_DE_UInt8 Rte_CIL_PowerMode_CIL_PowerMode;
    Rte_DE_Float Rte_CIL_PwrEACAct_CIL_PwrEACAct;
    Rte_DE_Float Rte_CIL_PwrPtcAct_CIL_PwrPtcAct;
    Rte_DE_UInt8 Rte_CIL_RAcChCnctn_CIL_RAcChCnctn;
    Rte_DE_UInt8 Rte_CIL_RDisChCnctn_CIL_RDisChCnctn;
    Rte_DE_UInt8 Rte_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts;
    Rte_DE_UInt8 Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
    Rte_DE_UInt8 Rte_CIL_SWVerVeh_CIL_SWVerVeh;
    Rte_DE_Float Rte_CIL_SecTelbox_CIL_SecTelbox;
    Rte_DE_UInt8 Rte_CIL_StAcChCnct_CIL_StAcChCnct;
    Rte_DE_UInt8 Rte_CIL_StBatHvReq_CIL_StBatHvReq;
    Rte_DE_UInt8 Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq;
    Rte_DE_rt_Array_UInt8_54 Rte_CIL_StCellT_CIL_StCellT;
    Rte_DE_UInt8 Rte_CIL_StChAllwd_CIL_StChAllwd;
    Rte_DE_UInt8 Rte_CIL_StObc_CIL_StObc;
    Rte_DE_UInt8 Rte_CIL_StProj_CIL_StProj;
    Rte_DE_UInt8 Rte_CIL_StPtIndcr_CIL_StPtIndcr;
    Rte_DE_UInt8 Rte_CIL_StPtcW_CIL_StPtcW;
    Rte_DE_rt_Array_Float_32 Rte_CIL_TBdSnsr_CIL_TBdSnsr;
    Rte_DE_SInt16 Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
    Rte_DE_SInt16 Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
    Rte_DE_rt_Array_Float_54 Rte_CIL_TMdul_CIL_TMdul;
    Rte_DE_rt_Array_Float_32 Rte_CIL_TMdulCtlr_CIL_TMdulCtlr;
    Rte_DE_rt_Array_Float_24 Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE;
    Rte_DE_Float Rte_CIL_UEACAct_CIL_UEACAct;
    Rte_DE_Float Rte_CIL_UObcChInp_CIL_UObcChInp;
    Rte_DE_Float Rte_CIL_UObcChOutp_CIL_UObcChOutp;
    Rte_DE_Boolean Rte_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid;
    Rte_DE_UInt16 Rte_CIL_YearTelbox_CIL_YearTelbox;
    Rte_DE_Boolean Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb;
    Rte_DE_Boolean Rte_CIL_bDCDCW_CIL_bDCDCW;
    Rte_DE_UInt16 Rte_CMLP_Max_DCCur_CMLP_Max_DCCur;
    Rte_DE_UInt16 Rte_CMLP_Max_DCV_CMLP_Max_DCV;
    Rte_DE_UInt16 Rte_CMLP_Min_DCCur_CMLP_Min_DCCur;
    Rte_DE_UInt16 Rte_CMLP_Min_DCV_CMLP_Min_DCV;
    Rte_DE_UInt8 Rte_ChargerReadyForCharging_ChargerReadyForCharging;
    Rte_DE_UInt8 Rte_ChargerRevision_ChargerRevision;
    Rte_DE_Float Rte_ClL_InletWaterTemp_ClL_InletWaterTemp;
    Rte_DE_Float Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp;
    Rte_DE_Boolean Rte_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid;
    Rte_DE_UInt8 Rte_IPK_Day_IPK_Day;
    Rte_DE_UInt8 Rte_IPK_Hour_IPK_Hour;
    Rte_DE_UInt32 Rte_IPK_IPKTotalOdometer_IPK_IPKTotalOdometer;
    Rte_DE_UInt8 Rte_IPK_Minute_IPK_Minute;
    Rte_DE_UInt8 Rte_IPK_Month_IPK_Month;
    Rte_DE_UInt8 Rte_IPK_Second_IPK_Second;
    Rte_DE_UInt8 Rte_IPK_Year_IPK_Year;
    Rte_DE_UInt8 Rte_MCC_NrAFETot_MCC_NrAFETot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCellByMdul_MCC_NrCellByMdul;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul;
    Rte_DE_UInt8 Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
    Rte_DE_UInt8 Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
    Rte_DE_UInt16 Rte_MaxOutputCurrent_MaxOutputCurrent;
    Rte_DE_UInt16 Rte_MaxOutputVoltage_MaxOutputVoltage;
    Rte_DE_UInt16 Rte_MinOutputCurrent_MinOutputCurrent;
    Rte_DE_UInt16 Rte_MinOutputVoltage_MinOutputVoltage;
    Rte_DE_UInt8 Rte_OBC_CCvalue_OBC_CCvalue;
    Rte_DE_UInt8 Rte_OBC_ChgCCSts_OBC_ChgCCSts;
    Rte_DE_UInt8 Rte_OBC_ChrgrSt_OBC_ChrgrSt;
    Rte_DE_UInt8 Rte_OBC_DischargeCCvalue_OBC_DischargeCCvalue;
    Rte_DE_UInt8 Rte_OBC_Elock_Stmode_OBC_Elock_Stmode;
    Rte_DE_UInt8 Rte_OBC_OnBdCCline_OBC_OnBdCCline;
    Rte_DE_UInt8 Rte_OBC_OnBdCPline_OBC_OnBdCPline;
    Rte_DE_UInt8 Rte_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline;
    Rte_DE_UInt16 Rte_OBC_OnBdOuptI_OBC_OnBdOuptI;
    Rte_DE_UInt16 Rte_OBC_OnBdOuptU_OBC_OnBdOuptU;
    Rte_DE_UInt16 Rte_OBC_uInAct_OBC_uInAct;
    Rte_DE_UInt16 Rte_OutputEnergy_OutputEnergy;
    Rte_DE_UInt8 Rte_PEPS_PowerMode_PEPS_PowerMode;
    Rte_DE_Boolean Rte_PMS_BatCoolType_PMS_BatCoolType;
    Rte_DE_UInt8 Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
    Rte_DE_Boolean Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
    Rte_DE_UInt8 Rte_RecognitionResult_RecognitionResult;
    Rte_DE_UInt8 Rte_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt;
    Rte_DE_UInt8 Rte_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts;
    Rte_DE_UInt8 Rte_Timeout_BCL_Timeout_BCL;
    Rte_DE_UInt8 Rte_Timeout_BCP_Timeout_BCP;
    Rte_DE_UInt8 Rte_Timeout_BCS_Timeout_BCS;
    Rte_DE_UInt8 Rte_Timeout_BRM_Timeout_BRM;
    Rte_DE_UInt8 Rte_Timeout_BRO_Timeout_BRO;
    Rte_DE_UInt8 Rte_Timeout_BSD_Timeout_BSD;
    Rte_DE_UInt8 Rte_Timeout_BSM_Timeout_BSM;
    Rte_DE_UInt8 Rte_Timeout_BST_Timeout_BST;
    Rte_DE_UInt8 Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
    Rte_DE_UInt8 Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
    Rte_DE_UInt8 Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
    Rte_DE_UInt8 Rte_VCU_ChargeModeReq_VCU_ChargeModeReq;
    Rte_DE_UInt8 Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
}Rte_tsRB_swc_CIL_CIL_100ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd;
    Rte_DE_UInt8 Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms;
    Rte_DE_UInt8 Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd;
    Rte_DE_UInt8 Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChImpo_BSOF_ErrChImpo;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
    Rte_DE_UInt8 Rte_BSOF_ErrIDe_BSOF_ErrIDe;
    Rte_DE_UInt8 Rte_BSOF_ErrUAbno_BSOF_ErrUAbno;
    Rte_DE_UInt8 Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
    Rte_DE_Boolean Rte_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd;
    Rte_DE_UInt32 Rte_BSWIOSP_Com_CST_UpdataTime_CST_UpdataTime;
    Rte_DE_UInt16 Rte_BSWIOSP_Service0x14_Count_Service0x14_Count;
    Rte_DE_UInt8 Rte_BSWIOSP_StsElectroniclockContor_StsElectroniclockContor;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_Float Rte_CIL_IBatHvRaw_CIL_IBatHvRaw;
    Rte_DE_UInt8 Rte_CIL_ModeMotDrv_CIL_ModeMotDrv;
    Rte_DE_UInt8 Rte_CIL_StCrash_CIL_StCrash;
    Rte_DE_UInt8 Rte_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor;
    Rte_DE_Float Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly;
    Rte_DE_Float Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_Float Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
    Rte_DE_Float Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg;
    Rte_DE_Float Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
    Rte_DE_Boolean Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
    Rte_DE_Boolean Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts;
    Rte_DE_Boolean Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts;
    Rte_DE_Float Rte_CTC_IDriftZero_CTC_IDriftZero;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_CrgSuspCause_Artificial_CrgSuspCause_Artificial;
    Rte_DE_UInt8 Rte_CrgSuspCause_BmsActiveSusp_CrgSuspCause_BmsActiveSusp;
    Rte_DE_UInt8 Rte_CrgSuspCause_ChargerCond_CrgSuspCause_ChargerCond;
    Rte_DE_UInt8 Rte_CrgSuspCause_Fault_CrgSuspCause_Fault;
    Rte_DE_UInt8 Rte_CrgSuspError_AbnormalVoltage_CrgSuspError_AbnormalVoltage;
    Rte_DE_UInt8 Rte_CrgSuspError_CurrentMismatch_CrgSuspError_CurrentMismatch;
    Rte_DE_UInt8 Rte_CrgSuspFault_CannotSupply_CrgSuspFault_CannotSupply;
    Rte_DE_UInt8 Rte_CrgSuspFault_ChargeConn_CrgSuspFault_ChargeConn;
    Rte_DE_UInt8 Rte_CrgSuspFault_CrgTemp_CrgSuspFault_CrgTemp;
    Rte_DE_UInt8 Rte_CrgSuspFault_CrgTempInt_CrgSuspFault_CrgTempInt;
    Rte_DE_UInt8 Rte_CrgSuspFault_OtherFault_CrgSuspFault_OtherFault;
    Rte_DE_UInt8 Rte_CrgSuspFault_SuddenStop_CrgSuspFault_SuddenStop;
    Rte_DE_SInt16 Rte_HvSysSample_Current_Current;
    Rte_DE_UInt8 Rte_HvSysSample_RelayKCNegClsSts_U8_RelayKCNegClsSts_U8;
    Rte_DE_SInt32 Rte_HvSysSample_RelayKCNegVoltage_RelayKCNegVoltage;
    Rte_DE_SInt32 Rte_HvSysSample_RelayKCVoltage_RelayKCVoltage;
    Rte_DE_SInt32 Rte_HvSysSample_RelayKHVoltage_RelayKHVoltage;
    Rte_DE_SInt32 Rte_HvSysSample_RelayKMVoltage_RelayKMVoltage;
    Rte_DE_UInt8 Rte_HvSysSample_RelayKNClsSts_U8_RelayKNClsSts_U8;
    Rte_DE_SInt32 Rte_HvSysSample_RelayKNVoltage_RelayKNVoltage;
    Rte_DE_SInt32 Rte_HvSysSample_TotalVoltage_TotalVoltage;
    Rte_DE_UInt8 Rte_IPU_DischgState_IPU_DischgState;
    Rte_DE_UInt8 Rte_VCU_CrashOutputSts_VCU_CrashOutputSts;
}Rte_tsRB_swc_CIL_CIL_10ms;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_CfgLvl2_CIL_CfgLvl2;
    Rte_DE_UInt8 Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
    Rte_DE_UInt8 Rte_CIL_HWVerVeh_CIL_HWVerVeh;
    Rte_DE_UInt8 Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
    Rte_DE_UInt8 Rte_CIL_SWVerVeh_CIL_SWVerVeh;
    Rte_DE_UInt8 Rte_CIL_StProj_CIL_StProj;
    Rte_DE_rt_Array_Float_24 Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE;
    Rte_DE_UInt8 Rte_MCC_NrAFETot_MCC_NrAFETot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCellByMdul_MCC_NrCellByMdul;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul;
    Rte_DE_UInt8 Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
    Rte_DE_UInt8 Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
}Rte_tsRB_swc_CIL_CIL_Init;

typedef struct
{
    Rte_DE_UInt16 Rte_B2V_SingleChgEnergy_B2V_SingleChgEnergy;
    Rte_DE_Float Rte_BCC_EChSng_BCC_EChSng;
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
    Rte_DE_Float Rte_BCF_IChLimMap_BCF_IChLimMap;
    Rte_DE_Float Rte_BCF_IDchaLim_BCF_IDchaLim;
    Rte_DE_Float Rte_BCF_IDchaLimMap_BCF_IDchaLimMap;
    Rte_DE_Float Rte_BCF_SocLimMin_BCF_SocLimMin;
    Rte_DE_Boolean Rte_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind;
    Rte_DE_Float Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
    Rte_DE_UInt8 Rte_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax;
    Rte_DE_UInt8 Rte_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin;
    Rte_DE_UInt16 Rte_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax;
    Rte_DE_UInt16 Rte_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin;
    Rte_DE_UInt16 Rte_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax;
    Rte_DE_UInt16 Rte_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin;
    Rte_DE_Boolean Rte_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
    Rte_DE_Boolean Rte_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag;
    Rte_DE_UInt8 Rte_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq;
    Rte_DE_Boolean Rte_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag;
    Rte_DE_Boolean Rte_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag;
    Rte_DE_Boolean Rte_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag;
    Rte_DE_UInt8 Rte_BMSH_BatTempMax_BMSH_BatTempMax;
    Rte_DE_UInt8 Rte_BMSH_BatTempMin_BMSH_BatTempMin;
    Rte_DE_Boolean Rte_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag;
    Rte_DE_UInt8 Rte_BMSH_BattPackNum_BMSH_BattPackNum;
    Rte_DE_UInt8 Rte_BMSH_BattSysNum_BMSH_BattSysNum;
    Rte_DE_UInt8 Rte_BMSH_BattTempAvg_BMSH_BattTempAvg;
    Rte_DE_Boolean Rte_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag;
    Rte_DE_Boolean Rte_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag;
    Rte_DE_Boolean Rte_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag;
    Rte_DE_Boolean Rte_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag;
    Rte_DE_Boolean Rte_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag;
    Rte_DE_UInt16 Rte_BMSH_CellVoltMax_BMSH_CellVoltMax;
    Rte_DE_UInt8 Rte_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID;
    Rte_DE_UInt16 Rte_BMSH_CellVoltMin_BMSH_CellVoltMin;
    Rte_DE_UInt8 Rte_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID;
    Rte_DE_UInt8 Rte_BMSH_CoolType_BMSH_CoolType;
    Rte_DE_Boolean Rte_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag;
    Rte_DE_Boolean Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
    Rte_DE_UInt8 Rte_BMSH_DCChgEnder_BMSH_DCChgEnder;
    Rte_DE_UInt8 Rte_BMSH_DCChgStandVer_BMSH_DCChgStandVer;
    Rte_DE_Boolean Rte_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag;
    Rte_DE_UInt8 Rte_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur;
    Rte_DE_UInt16 Rte_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt;
    Rte_DE_Boolean Rte_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP;
    Rte_DE_Boolean Rte_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag;
    Rte_DE_UInt16 Rte_BMSH_EnergyOut_BMSH_EnergyOut;
    Rte_DE_Boolean Rte_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag;
    Rte_DE_UInt16 Rte_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes;
    Rte_DE_Boolean Rte_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag;
    Rte_DE_UInt16 Rte_BMSH_FinishChgTime_BMSH_FinishChgTime;
    Rte_DE_Boolean Rte_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag;
    Rte_DE_UInt8 Rte_BMSH_FlowRateReq_BMSH_FlowRateReq;
    Rte_DE_Boolean Rte_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag;
    Rte_DE_UInt8 Rte_BMSH_PackExtendCd_BMSH_PackExtendCd;
    Rte_DE_UInt8 Rte_BMSH_PackType_BMSH_PackType;
    Rte_DE_Boolean Rte_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
    Rte_DE_UInt32 Rte_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE;
    Rte_DE_UInt16 Rte_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng;
    Rte_DE_UInt8 Rte_BMSH_SupplyVolt_BMSH_SupplyVolt;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear;
    Rte_DE_UInt16 Rte_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy;
    Rte_DE_UInt16 Rte_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatType_BMSH_TBOX_BatType;
    Rte_DE_UInt16 Rte_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer;
    Rte_DE_UInt8 Rte_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test;
    Rte_DE_UInt8 Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer;
    Rte_DE_UInt8 Rte_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test;
    Rte_DE_Boolean Rte_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault;
    Rte_DE_UInt32 Rte_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity;
    Rte_DE_UInt32 Rte_BMSH_TotalDischgEng_BMSH_TotalDischgEng;
    Rte_DE_UInt32 Rte_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity;
    Rte_DE_UInt32 Rte_BMSH_TotalExChgEng_BMSH_TotalExChgEng;
    Rte_DE_UInt32 Rte_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE;
    Rte_DE_UInt32 Rte_BMSH_TotalOdometer_BMSH_TotalOdometer;
    Rte_DE_Boolean Rte_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag;
    Rte_DE_UInt32 Rte_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity;
    Rte_DE_UInt32 Rte_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng;
    Rte_DE_UInt32 Rte_BMSH_TripOdometer_BMSH_TripOdometer;
    Rte_DE_Boolean Rte_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr;
    Rte_DE_Boolean Rte_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP;
    Rte_DE_Boolean Rte_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag;
    Rte_DE_UInt8 Rte_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp;
    Rte_DE_UInt8 Rte_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp;
    Rte_DE_Boolean Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
    Rte_DE_Boolean Rte_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag;
    Rte_DE_Boolean Rte_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind;
    Rte_DE_UInt8 Rte_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct;
    Rte_DE_Boolean Rte_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind;
    Rte_DE_Boolean Rte_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn;
    Rte_DE_UInt16 Rte_BPIU_IdCellUMax_BPIU_IdCellUMax;
    Rte_DE_UInt16 Rte_BPIU_IdCellUMin_BPIU_IdCellUMin;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
    Rte_DE_Float Rte_BSOF_EChSng_BSOF_EChSng;
    Rte_DE_Float Rte_BSOF_IChrgr_BSOF_IChrgr;
    Rte_DE_Float Rte_BSOF_UChrgr_BSOF_UChrgr;
    Rte_DE_UInt8 Rte_BTHM_IdCellTMax_BTHM_IdCellTMax;
    Rte_DE_UInt8 Rte_BTHM_IdCellTMin_BTHM_IdCellTMin;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_BTHM_TOptmMax_BTHM_TOptmMax;
    Rte_DE_Float Rte_BTHM_TOptmMin_BTHM_TOptmMin;
    Rte_DE_Float Rte_BTHM_TPack_BTHM_TPack;
    Rte_DE_Float Rte_BWLD_CBatChTot_BWLD_CBatChTot;
    Rte_DE_Float Rte_BWLD_CBatDchaTot_BWLD_CBatDchaTot;
    Rte_DE_Float Rte_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot;
    Rte_DE_UInt16 Rte_BWLD_CtrCh_BWLD_CtrCh;
    Rte_DE_Float Rte_BWLD_EBatChTot_BWLD_EBatChTot;
    Rte_DE_Float Rte_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc;
    Rte_DE_Float Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
    Rte_DE_Float Rte_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc;
    Rte_DE_Float Rte_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot;
    Rte_DE_Boolean Rte_CIL_BatCoolType_CIL_BatCoolType;
    Rte_DE_UInt8 Rte_CIL_ChargeModeReq_CIL_ChargeModeReq;
    Rte_DE_UInt8 Rte_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
    Rte_DE_UInt8 Rte_CIL_HWVerVeh_CIL_HWVerVeh;
    Rte_DE_Float Rte_CIL_MilgTot_CIL_MilgTot;
    Rte_DE_UInt8 Rte_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
    Rte_DE_UInt8 Rte_CIL_SWVerVeh_CIL_SWVerVeh;
    Rte_DE_Float Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
    Rte_DE_Float Rte_CIL_TDcChPointPos_CIL_TDcChPointPos;
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
    Rte_DE_UInt8 Rte_DEH_BatMfctrType_DEH_BatMfctrType;
    Rte_DE_UInt8 Rte_DEH_BatMfctrr_DEH_BatMfctrr;
    Rte_DE_Float Rte_DEH_CBatNom_DEH_CBatNom;
    Rte_DE_UInt8 Rte_DEH_DayBatMfctr_DEH_DayBatMfctr;
    Rte_DE_UInt8 Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr;
    Rte_DE_UInt16 Rte_DEH_NrPackSerl_DEH_NrPackSerl;
    Rte_DE_Float Rte_DEH_UBatNom_DEH_UBatNom;
    Rte_DE_UInt16 Rte_DEH_YearBatMfctr_DEH_YearBatMfctr;
    Rte_DE_UInt8 Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    Rte_DE_rt_Array_UInt8_24 Rte_MCC_NrCellByMdul_MCC_NrCellByMdul;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
    Rte_DE_UInt8 Rte_MCC_NrMdulTot_MCC_NrMdulTot;
}Rte_tsRB_swc_COL_COL_1000ms;

typedef struct
{
    Rte_DE_rt_Array_UInt32_24 Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp;
    Rte_DE_UInt16 Rte_BMSH_BusVolt_BMSH_BusVolt;
    Rte_DE_UInt8 Rte_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp;
    Rte_DE_UInt8 Rte_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp;
    Rte_DE_UInt8 Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas;
    Rte_DE_UInt8 Rte_BSWIOSP_Mode_Request_shutdown_Request_shutdown;
    Rte_DE_rt_Array_UInt32_9 Rte_BmuControl_BalanceControl_BalanceControl;
    Rte_DE_Float Rte_CIL_ActInputVolt_CIL_ActInputVolt;
    Rte_DE_Float Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
    Rte_DE_Float Rte_CIL_TAcChPointPos_CIL_TAcChPointPos;
    Rte_DE_UInt8 Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
    Rte_DE_UInt8 Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
    Rte_DE_UInt8 Rte_CTC_ReqRlyPos_CTC_ReqRlyPos;
    Rte_DE_Boolean Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas;
    Rte_DE_UInt8 Rte_HvSysSample_DisableIso_DisableIso;
}Rte_tsRB_swc_COL_COL_50ms;

typedef struct
{
    Rte_DE_Boolean Rte_BBC_bAcvBaln_BBC_bAcvBaln;
    Rte_DE_UInt8 Rte_BCC_AcvCellURchd_BCC_AcvCellURchd;
    Rte_DE_UInt8 Rte_BCC_AcvSocRchd_BCC_AcvSocRchd;
    Rte_DE_UInt8 Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
    Rte_DE_UInt8 Rte_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ;
    Rte_DE_UInt8 Rte_BCC_ElectroniclockSt_BCC_ElectroniclockSt;
    Rte_DE_UInt32 Rte_BCC_ErrInfo_BCC_ErrInfo;
    Rte_DE_Float Rte_BCC_IDchaReq_BCC_IDchaReq;
    Rte_DE_Float Rte_BCC_IObcLimn_BCC_IObcLimn;
    Rte_DE_UInt8 Rte_BCC_ModeCh_BCC_ModeCh;
    Rte_DE_UInt8 Rte_BCC_StAcChReq_BCC_StAcChReq;
    Rte_DE_UInt8 Rte_BCC_StCh_BCC_StCh;
    Rte_DE_Boolean Rte_BCC_TimeOutCRO00_BCC_TimeOutCRO00;
    Rte_DE_Boolean Rte_BCC_TimeOutCROAA_BCC_TimeOutCROAA;
    Rte_DE_Float Rte_BCC_UChReq_BCC_UChReq;
    Rte_DE_Float Rte_BCC_UObcLimn_BCC_UObcLimn;
    Rte_DE_Boolean Rte_BCC_bS2Ctrl_BCC_bS2Ctrl;
    Rte_DE_Float Rte_BCF_EPackRmng_BCF_EPackRmng;
    Rte_DE_UInt32 Rte_BCF_ErrInfo_BCF_ErrInfo;
    Rte_DE_Float Rte_BCF_IChPredLim_BCF_IChPredLim;
    Rte_DE_Float Rte_BCF_IDchaPredLim_BCF_IDchaPredLim;
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_SohPack_BCF_SohPack;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Boolean Rte_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
    Rte_DE_UInt16 Rte_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur;
    Rte_DE_UInt16 Rte_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV;
    Rte_DE_UInt16 Rte_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV;
    Rte_DE_UInt8 Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
    Rte_DE_UInt16 Rte_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time;
    Rte_DE_UInt16 Rte_BCSP_Remaining_range_BCSP_Remaining_range;
    Rte_DE_UInt32 Rte_BCSP_reserved_BCSP_reserved;
    Rte_DE_Float Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
    Rte_DE_Float Rte_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot;
    Rte_DE_UInt16 Rte_BDC_Battery_capacity_BDC_Battery_capacity;
    Rte_DE_UInt16 Rte_BDC_Battery_energy_BDC_Battery_energy;
    Rte_DE_UInt16 Rte_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate;
    Rte_DE_UInt16 Rte_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange;
    Rte_DE_UInt16 Rte_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate;
    Rte_DE_UInt8 Rte_BDC_Soc_BDC_Soc;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8;
    Rte_DE_UInt8 Rte_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9;
    Rte_DE_rt_Array_Float_255 Rte_BMC_UCell_BMC_UCell;
    Rte_DE_Boolean Rte_BMSH_12VBatFault_BMSH_12VBatFault;
    Rte_DE_UInt16 Rte_BMSH_BatCurrent_BMSH_BatCurrent;
    Rte_DE_UInt8 Rte_BMSH_BatOverSOC_BMSH_BatOverSOC;
    Rte_DE_UInt8 Rte_BMSH_BatOverVolt_BMSH_BatOverVolt;
    Rte_DE_UInt16 Rte_BMSH_BatRealSOC_BMSH_BatRealSOC;
    Rte_DE_UInt16 Rte_BMSH_BatSOE_BMSH_BatSOE;
    Rte_DE_UInt16 Rte_BMSH_BatSOH_BMSH_BatSOH;
    Rte_DE_UInt8 Rte_BMSH_BatUnderSOC_BMSH_BatUnderSOC;
    Rte_DE_UInt8 Rte_BMSH_BatUnderVolt_BMSH_BatUnderVolt;
    Rte_DE_UInt16 Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
    Rte_DE_UInt8 Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
    Rte_DE_UInt8 Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
    Rte_DE_UInt8 Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
    Rte_DE_UInt8 Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
    Rte_DE_UInt8 Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
    Rte_DE_UInt8 Rte_BMSH_CellOverVolt_BMSH_CellOverVolt;
    Rte_DE_UInt8 Rte_BMSH_CellTempUniformity_BMSH_CellTempUniformity;
    Rte_DE_UInt8 Rte_BMSH_CellUnderVolt_BMSH_CellUnderVolt;
    Rte_DE_UInt8 Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
    Rte_DE_UInt8 Rte_BMSH_ChgOverTemp_BMSH_ChgOverTemp;
    Rte_DE_UInt8 Rte_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp;
    Rte_DE_UInt8 Rte_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp;
    Rte_DE_UInt8 Rte_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp;
    Rte_DE_UInt8 Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
    Rte_DE_UInt8 Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
    Rte_DE_UInt8 Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault;
    Rte_DE_UInt8 Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
    Rte_DE_UInt8 Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
    Rte_DE_UInt8 Rte_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault;
    Rte_DE_UInt8 Rte_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA;
    Rte_DE_Boolean Rte_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD;
    Rte_DE_UInt16 Rte_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow;
    Rte_DE_Boolean Rte_BMSH_DataStorageFault_BMSH_DataStorageFault;
    Rte_DE_UInt8 Rte_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent;
    Rte_DE_UInt8 Rte_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp;
    Rte_DE_UInt8 Rte_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp;
    Rte_DE_Boolean Rte_BMSH_EVCANComFault_BMSH_EVCANComFault;
    Rte_DE_Boolean Rte_BMSH_FastChgComFault_BMSH_FastChgComFault;
    Rte_DE_UInt8 Rte_BMSH_FaultCode_BMSH_FaultCode;
    Rte_DE_UInt8 Rte_BMSH_FireAlarm_BMSH_FireAlarm;
    Rte_DE_Boolean Rte_BMSH_IntComFault_BMSH_IntComFault;
    Rte_DE_UInt8 Rte_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault;
    Rte_DE_UInt8 Rte_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault;
    Rte_DE_UInt8 Rte_BMSH_PackCode1_BMSH_PackCode1;
    Rte_DE_UInt8 Rte_BMSH_PackCode1_1_BMSH_PackCode1_1;
    Rte_DE_UInt8 Rte_BMSH_PackCode2_BMSH_PackCode2;
    Rte_DE_UInt8 Rte_BMSH_PackCode2_1_BMSH_PackCode2_1;
    Rte_DE_UInt8 Rte_BMSH_PackCode3_BMSH_PackCode3;
    Rte_DE_UInt8 Rte_BMSH_PackCode3_1_BMSH_PackCode3_1;
    Rte_DE_UInt8 Rte_BMSH_PackCode4_BMSH_PackCode4;
    Rte_DE_UInt8 Rte_BMSH_PackCode4_1_BMSH_PackCode4_1;
    Rte_DE_UInt8 Rte_BMSH_PackCode5_BMSH_PackCode5;
    Rte_DE_UInt8 Rte_BMSH_PackCode5_1_BMSH_PackCode5_1;
    Rte_DE_UInt8 Rte_BMSH_PackCode6_BMSH_PackCode6;
    Rte_DE_UInt8 Rte_BMSH_PackCode7_BMSH_PackCode7;
    Rte_DE_UInt8 Rte_BMSH_PackCode_ID_BMSH_PackCode_ID;
    Rte_DE_UInt16 Rte_BMSH_PackVolt_BMSH_PackVolt;
    Rte_DE_UInt8 Rte_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent;
    Rte_DE_Boolean Rte_BMSH_SelfCheckFault_BMSH_SelfCheckFault;
    Rte_DE_Boolean Rte_BMSH_StsA_plus_BMSH_StsA_plus;
    Rte_DE_UInt8 Rte_BMSH_StsCC2_BMSH_StsCC2;
    Rte_DE_UInt8 Rte_BMSH_StsCellBalance_BMSH_StsCellBalance;
    Rte_DE_UInt8 Rte_BMSH_StsChgFault_BMSH_StsChgFault;
    Rte_DE_UInt8 Rte_BMSH_StsDischgFault_BMSH_StsDischgFault;
    Rte_DE_UInt8 Rte_BMSH_StsInsulation_BMSH_StsInsulation;
    Rte_DE_UInt8 Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
    Rte_DE_UInt8 Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
    Rte_DE_UInt8 Rte_BMSH_StsMode_BMSH_StsMode;
    Rte_DE_UInt8 Rte_BMSH_StsPrecharge_BMSH_StsPrecharge;
    Rte_DE_UInt8 Rte_BMSH_StsWakeUp_BMSH_StsWakeUp;
    Rte_DE_UInt8 Rte_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp;
    Rte_DE_UInt16 Rte_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID;
    Rte_DE_UInt16 Rte_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt;
    Rte_DE_UInt16 Rte_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID;
    Rte_DE_UInt16 Rte_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt;
    Rte_DE_Boolean Rte_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2;
    Rte_DE_Boolean Rte_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2;
    Rte_DE_UInt16 Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
    Rte_DE_UInt8 Rte_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm;
    Rte_DE_UInt16 Rte_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance;
    Rte_DE_UInt16 Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
    Rte_DE_Boolean Rte_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop;
    Rte_DE_UInt8 Rte_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempA_BMSH_TBOX_TempA;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempB_BMSH_TBOX_TempB;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempC_BMSH_TBOX_TempC;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempD_BMSH_TBOX_TempD;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempE_BMSH_TBOX_TempE;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempF_BMSH_TBOX_TempF;
    Rte_DE_UInt8 Rte_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID;
    Rte_DE_Boolean Rte_BMSH_VCUChksumFault_BMSH_VCUChksumFault;
    Rte_DE_Boolean Rte_BMSH_VCURollCountFault_BMSH_VCURollCountFault;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay;
    Rte_DE_UInt8 Rte_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay;
    Rte_DE_UInt8 Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
    Rte_DE_UInt8 Rte_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay;
    Rte_DE_UInt8 Rte_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode;
    Rte_DE_UInt16 Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
    Rte_DE_UInt8 Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
    Rte_DE_UInt8 Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
    Rte_DE_UInt8 Rte_BMS_BattCellsNumPN_BMS_BattCellsNumPN;
    Rte_DE_UInt8 Rte_BMS_BattPackNumSN_BMS_BattPackNumSN;
    Rte_DE_UInt8 Rte_BMS_BattTemp1_BMS_BattTemp1;
    Rte_DE_UInt8 Rte_BMS_BattTemp2_BMS_BattTemp2;
    Rte_DE_UInt8 Rte_BMS_BattTemp3_BMS_BattTemp3;
    Rte_DE_UInt8 Rte_BMS_BattTemp4_BMS_BattTemp4;
    Rte_DE_UInt8 Rte_BMS_BattTemp5_BMS_BattTemp5;
    Rte_DE_UInt8 Rte_BMS_BattTemp6_BMS_BattTemp6;
    Rte_DE_UInt16 Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
    Rte_DE_UInt8 Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
    Rte_DE_UInt8 Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
    Rte_DE_UInt8 Rte_BMS_CCvalue_BMS_CCvalue;
    Rte_DE_Boolean Rte_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl;
    Rte_DE_UInt8 Rte_BMS_CP_Duty_BMS_CP_Duty;
    Rte_DE_UInt8 Rte_BMS_CP_Vol_BMS_CP_Vol;
    Rte_DE_UInt8 Rte_BMS_CellTempFrameNum_BMS_CellTempFrameNum;
    Rte_DE_UInt8 Rte_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum;
    Rte_DE_UInt16 Rte_BMS_CellVoltN1_BMS_CellVoltN1;
    Rte_DE_UInt16 Rte_BMS_CellVoltN2_BMS_CellVoltN2;
    Rte_DE_UInt16 Rte_BMS_CellVoltN3_BMS_CellVoltN3;
    Rte_DE_UInt8 Rte_BMS_ChgStatus_BMS_ChgStatus;
    Rte_DE_UInt8 Rte_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC;
    Rte_DE_UInt8 Rte_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl;
    Rte_DE_Boolean Rte_BMS_DelayControl_BMS_DelayControl;
    Rte_DE_UInt8 Rte_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
    Rte_DE_UInt8 Rte_BMS_DischargeCCvalue_BMS_DischargeCCvalue;
    Rte_DE_UInt8 Rte_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ;
    Rte_DE_UInt8 Rte_BMS_ElectroniclockSts_BMS_ElectroniclockSts;
    Rte_DE_UInt16 Rte_BMS_MaxChgCurrent_BMS_MaxChgCurrent;
    Rte_DE_UInt16 Rte_BMS_MaxChgVoltage_BMS_MaxChgVoltage;
    Rte_DE_UInt8 Rte_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd;
    Rte_DE_Boolean Rte_BMS_S2STATUS_BMS_S2STATUS;
    Rte_DE_UInt8 Rte_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1;
    Rte_DE_UInt8 Rte_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1;
    Rte_DE_UInt8 Rte_BMS_SysCodeLength_1_BMS_SysCodeLength_1;
    Rte_DE_UInt8 Rte_BMS_TempCSCNum_BMS_TempCSCNum;
    Rte_DE_UInt8 Rte_BMS_TempSnsNumPN_BMS_TempSnsNumPN;
    Rte_DE_UInt8 Rte_BMS_VoltCellNum_BMS_VoltCellNum;
    Rte_DE_Boolean Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
    Rte_DE_UInt8 Rte_BPIU_ErrCellU_BPIU_ErrCellU;
    Rte_DE_UInt8 Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif;
    Rte_DE_UInt8 Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver;
    Rte_DE_UInt8 Rte_BPIU_ErrIChLim_BPIU_ErrIChLim;
    Rte_DE_UInt8 Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur;
    Rte_DE_UInt32 Rte_BPIU_ErrInfo_BPIU_ErrInfo;
    Rte_DE_UInt8 Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI;
    Rte_DE_UInt8 Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn;
    Rte_DE_UInt16 Rte_BPIU_IdCellUMax_BPIU_IdCellUMax;
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
    Rte_DE_UInt8 Rte_BPP_ErrCellT_BPP_ErrCellT;
    Rte_DE_UInt32 Rte_BPP_ErrInfo_BPP_ErrInfo;
    Rte_DE_UInt8 Rte_BPP_ErrPackU_BPP_ErrPackU;
    Rte_DE_UInt8 Rte_BPP_ErrSocVal_BPP_ErrSocVal;
    Rte_DE_UInt8 Rte_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd;
    Rte_DE_UInt8 Rte_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms;
    Rte_DE_UInt8 Rte_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd;
    Rte_DE_UInt8 Rte_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChImpo_BSOF_ErrChImpo;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
    Rte_DE_UInt8 Rte_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
    Rte_DE_UInt8 Rte_BSOF_ErrIDe_BSOF_ErrIDe;
    Rte_DE_UInt8 Rte_BSOF_ErrUAbno_BSOF_ErrUAbno;
    Rte_DE_UInt8 Rte_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
    Rte_DE_Boolean Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    Rte_DE_UInt8 Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn;
    Rte_DE_UInt8 Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt8 Rte_BSTC_StBcuInt_BSTC_StBcuInt;
    Rte_DE_UInt8 Rte_BSTC_StBmsChk_BSTC_StBmsChk;
    Rte_DE_Boolean Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms;
    Rte_DE_UInt8 Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BCP_Request_BCP;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BCPP_Request_BCPP;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BCS_Request_BCS;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BCSP_Request_BCSP;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BDC_Request_BDC;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BEM_Request_BEM;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BHM_Request_BHM;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BRM_Request_BRM;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BRO_Request_BRO;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BSD_Request_BSD;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BSM_Request_BSM;
    Rte_DE_UInt32 Rte_BTHM_ErrInfo_BTHM_ErrInfo;
    Rte_DE_UInt8 Rte_BTHM_IdCellTMax_BTHM_IdCellTMax;
    Rte_DE_UInt8 Rte_BTHM_IdCellTMin_BTHM_IdCellTMin;
    Rte_DE_UInt16 Rte_BTHM_StSys_BTHM_StSys;
    Rte_DE_UInt8 Rte_BTHM_StThermReq_BTHM_StThermReq;
    Rte_DE_Float Rte_BTHM_TBatTgt_BTHM_TBatTgt;
    Rte_DE_Float Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
    Rte_DE_Float Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
    Rte_DE_Float Rte_BTHM_TOptmMax_BTHM_TOptmMax;
    Rte_DE_Boolean Rte_BTHM_bAcvDig93_BTHM_bAcvDig93;
    Rte_DE_UInt16 Rte_BWLD_CtrDcha_BWLD_CtrDcha;
    Rte_DE_UInt16 Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
    Rte_DE_UInt8 Rte_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
    Rte_DE_UInt8 Rte_BatteryExcessTemperature_BatteryExcessTemperature;
    Rte_DE_UInt8 Rte_BatteryHighestTemp_BatteryHighestTemp;
    Rte_DE_UInt8 Rte_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
    Rte_DE_UInt8 Rte_BatteryInsulationState_BatteryInsulationState;
    Rte_DE_UInt8 Rte_BatteryLowestTemp_BatteryLowestTemp;
    Rte_DE_UInt8 Rte_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
    Rte_DE_UInt8 Rte_BatteryOutputConnectorState_BatteryOutputConnectorState;
    Rte_DE_UInt16 Rte_BatterySystemCapacity_BatterySystemCapacity;
    Rte_DE_UInt16 Rte_BatterySystemVoltage_BatterySystemVoltage;
    Rte_DE_UInt8 Rte_BatteryType_BatteryType;
    Rte_DE_UInt8 Rte_BmsReadyForCharging_BmsReadyForCharging;
    Rte_DE_UInt8 Rte_BmsRevision_BmsRevision;
    Rte_DE_UInt16 Rte_BmsVersion_BmsVersion;
    Rte_DE_UInt8 Rte_BsmChargingPermissible_BsmChargingPermissible;
    Rte_DE_Float Rte_CIL_CP_Vol_CIL_CP_Vol;
    Rte_DE_UInt8 Rte_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
    Rte_DE_UInt16 Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
    Rte_DE_UInt32 Rte_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw;
    Rte_DE_Float Rte_CIL_RngElec_CIL_RngElec;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_rt_Array_Float_54 Rte_CIL_TMdul_CIL_TMdul;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_UInt32 Rte_CTC_ErrInfo_CTC_ErrInfo;
    Rte_DE_UInt8 Rte_CTC_ErrRlyCh_CTC_ErrRlyCh;
    Rte_DE_UInt8 Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat;
    Rte_DE_UInt8 Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg;
    Rte_DE_UInt8 Rte_CTC_ErrRlyPos_CTC_ErrRlyPos;
    Rte_DE_UInt8 Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech;
    Rte_DE_UInt8 Rte_CTC_ReqRlyCh_CTC_ReqRlyCh;
    Rte_DE_Boolean Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_CTC_StRlyCh_CTC_StRlyCh;
    Rte_DE_UInt8 Rte_CTC_StRlyHeat_CTC_StRlyHeat;
    Rte_DE_UInt8 Rte_CTC_StRlyNeg_CTC_StRlyNeg;
    Rte_DE_UInt8 Rte_CTC_StRlyPos_CTC_StRlyPos;
    Rte_DE_UInt8 Rte_CTC_StRlyPrech_CTC_StRlyPrech;
    Rte_DE_Float Rte_ClL_InletWaterTemp_ClL_InletWaterTemp;
    Rte_DE_Float Rte_ClL_OutletWaterTemp_ClL_OutletWaterTemp;
    Rte_DE_UInt8 Rte_CurrentChargeState_CurrentChargeState;
    Rte_DE_UInt16 Rte_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
    Rte_DE_Float Rte_DEH_CBatNom_DEH_CBatNom;
    Rte_DE_UInt8 Rte_DEH_ChgLvlErr_DEH_ChgLvlErr;
    Rte_DE_UInt8 Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb;
    Rte_DE_UInt8 Rte_DEH_DischgLvlErr_DEH_DischgLvlErr;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_UInt8 Rte_DEH_LvlErrSb_DEH_LvlErrSb;
    Rte_DE_UInt8 Rte_DEH_NrVin1_DEH_NrVin1;
    Rte_DE_UInt8 Rte_DEH_NrVin10_DEH_NrVin10;
    Rte_DE_UInt8 Rte_DEH_NrVin11_DEH_NrVin11;
    Rte_DE_UInt8 Rte_DEH_NrVin12_DEH_NrVin12;
    Rte_DE_UInt8 Rte_DEH_NrVin13_DEH_NrVin13;
    Rte_DE_UInt8 Rte_DEH_NrVin14_DEH_NrVin14;
    Rte_DE_UInt8 Rte_DEH_NrVin15_DEH_NrVin15;
    Rte_DE_UInt8 Rte_DEH_NrVin16_DEH_NrVin16;
    Rte_DE_UInt8 Rte_DEH_NrVin17_DEH_NrVin17;
    Rte_DE_UInt8 Rte_DEH_NrVin2_DEH_NrVin2;
    Rte_DE_UInt8 Rte_DEH_NrVin3_DEH_NrVin3;
    Rte_DE_UInt8 Rte_DEH_NrVin4_DEH_NrVin4;
    Rte_DE_UInt8 Rte_DEH_NrVin5_DEH_NrVin5;
    Rte_DE_UInt8 Rte_DEH_NrVin6_DEH_NrVin6;
    Rte_DE_UInt8 Rte_DEH_NrVin7_DEH_NrVin7;
    Rte_DE_UInt8 Rte_DEH_NrVin8_DEH_NrVin8;
    Rte_DE_UInt8 Rte_DEH_NrVin9_DEH_NrVin9;
    Rte_DE_rt_Array_UInt8_24 Rte_DEH_PackCode_DEH_PackCode;
    Rte_DE_UInt8 Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
    Rte_DE_Float Rte_DEH_UBatNom_DEH_UBatNom;
    Rte_DE_UInt16 Rte_DEH_ValCodDiag_DEH_ValCodDiag;
    Rte_DE_UInt16 Rte_EHPM_ValCodDiag_EHPM_ValCodDiag;
    Rte_DE_UInt8 Rte_EHPMon_CellOverVolt_EHPMon_CellOverVolt;
    Rte_DE_UInt8 Rte_EHPMon_CellUnderVolt_EHPMon_CellUnderVolt;
    Rte_DE_UInt8 Rte_EHPMon_ChgOverCurrent_EHPMon_ChgOverCurrent;
    Rte_DE_UInt8 Rte_EHPMon_DisChgOverCurrent_EHPMon_DisChgOverCurrent;
    Rte_DE_UInt8 Rte_EHPMon_StErrHvIntlcFlt_EHPMon_StErrHvIntlcFlt;
    Rte_DE_UInt8 Rte_EHPMon_StIsln_EHPMon_StIsln;
    Rte_DE_UInt8 Rte_EHPMon_StIslnErr_EHPMon_StIslnErr;
    Rte_DE_Boolean Rte_EHPMon_StIslnErrFlg_EHPMon_StIslnErrFlg;
    Rte_DE_UInt8 Rte_EHPMon_StRlyNegFlt_EHPMon_StRlyNegFlt;
    Rte_DE_UInt8 Rte_EHPMon_StRlyPosFlt_EHPMon_StRlyPosFlt;
    Rte_DE_UInt8 Rte_EHPMon_StsChgFault_EHPMon_StsChgFault;
    Rte_DE_UInt8 Rte_EHPMon_StsDischgFault_EHPMon_StsDischgFault;
    Rte_DE_Boolean Rte_EHPMon_TBOXStErrHvIntlcFlt_EHPMon_TBOXStErrHvIntlcFlt;
    Rte_DE_Boolean Rte_EHPMon_TBOX_BatOverTemp_EHPMon_TBOX_BatOverTemp;
    Rte_DE_UInt8 Rte_EHPMon_TBOX_BatOverTemp2_EHPMon_TBOX_BatOverTemp2;
    Rte_DE_Boolean Rte_EHPMon_TBOX_CellOverVoltage_EHPMon_TBOX_CellOverVoltage;
    Rte_DE_UInt8 Rte_EHPMon_TBOX_CellOverVoltage2_EHPMon_TBOX_CellOverVoltage2;
    Rte_DE_Boolean Rte_EHPMon_TBOX_CellUnderVoltage_EHPMon_TBOX_CellUnderVoltage;
    Rte_DE_UInt8 Rte_EHPMon_TBOX_CellUnderVoltage2_EHPMon_TBOX_CellUnderVoltage2;
    Rte_DE_UInt16 Rte_EHPMon_TBOX_InsulationResistance_EHPMon_TBOX_InsulationResistance;
    Rte_DE_UInt16 Rte_ELHPN_ErrInfo_ELHPN_ErrInfo;
    Rte_DE_Float Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
    Rte_DE_Float Rte_ELHPN_RIslnPos_ELHPN_RIslnPos;
    Rte_DE_UInt8 Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
    Rte_DE_UInt8 Rte_ELHPN_StIsln_ELHPN_StIsln;
    Rte_DE_UInt8 Rte_ELHPN_StIslnErr_ELHPN_StIslnErr;
    Rte_DE_UInt8 Rte_ELHPN_StVehIsln_ELHPN_StVehIsln;
    Rte_DE_UInt8 Rte_ESIM_CfgLvl2_ESIM_CfgLvl2;
    Rte_DE_UInt8 Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy;
    Rte_DE_UInt8 Rte_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync;
    Rte_DE_UInt8 Rte_EVCSH_StBatRdy_EVCSH_StBatRdy;
    Rte_DE_UInt8 Rte_EVCSH_StDcCh_EVCSH_StDcCh;
    Rte_DE_UInt16 Rte_EVCSH_StInt_EVCSH_StInt;
    Rte_DE_UInt8 Rte_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
    Rte_DE_UInt16 Rte_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
    Rte_DE_UInt16 Rte_MCC_NrCellTot_MCC_NrCellTot;
    Rte_DE_UInt8 Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
    Rte_DE_UInt16 Rte_MaxChargingVoltage_MaxChargingVoltage;
    Rte_DE_UInt16 Rte_MaxPermChargingCurrent_MaxPermChargingCurrent;
    Rte_DE_UInt8 Rte_MaxPermTemperature_MaxPermTemperature;
    Rte_DE_UInt16 Rte_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
    Rte_DE_UInt16 Rte_MeasuredChargingCurrent_MeasuredChargingCurrent;
    Rte_DE_UInt16 Rte_MeasuredChargingVoltage_MeasuredChargingVoltage;
    Rte_DE_UInt16 Rte_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
    Rte_DE_UInt8 Rte_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
    Rte_DE_UInt8 Rte_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
    Rte_DE_UInt8 Rte_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
    Rte_DE_UInt16 Rte_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
    Rte_DE_UInt8 Rte_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
    Rte_DE_UInt16 Rte_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
    Rte_DE_UInt8 Rte_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
    Rte_DE_UInt16 Rte_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
    Rte_DE_UInt8 Rte_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
    Rte_DE_UInt8 Rte_Timeout_CCS_Timeout_CCS;
    Rte_DE_UInt8 Rte_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
    Rte_DE_UInt8 Rte_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
    Rte_DE_UInt8 Rte_Timeout_CRO_Timeout_CRO;
    Rte_DE_UInt8 Rte_Timeout_CSD_Timeout_CSD;
    Rte_DE_UInt8 Rte_Timeout_CST_Timeout_CST;
    Rte_DE_UInt8 Rte_Timeout_CTS_CML_Timeout_CTS_CML;
    Rte_DE_UInt16 Rte_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
    Rte_DE_UInt16 Rte_TotalNominalEnergy_TotalNominalEnergy;
    Rte_DE_UInt8 Rte_VIN_Copy_1_VIN_Copy_1;
    Rte_DE_UInt8 Rte_VIN_Copy_10_VIN_Copy_10;
    Rte_DE_UInt8 Rte_VIN_Copy_11_VIN_Copy_11;
    Rte_DE_UInt8 Rte_VIN_Copy_12_VIN_Copy_12;
    Rte_DE_UInt8 Rte_VIN_Copy_13_VIN_Copy_13;
    Rte_DE_UInt8 Rte_VIN_Copy_14_VIN_Copy_14;
    Rte_DE_UInt8 Rte_VIN_Copy_15_VIN_Copy_15;
    Rte_DE_UInt8 Rte_VIN_Copy_16_VIN_Copy_16;
    Rte_DE_UInt8 Rte_VIN_Copy_17_VIN_Copy_17;
    Rte_DE_UInt8 Rte_VIN_Copy_2_VIN_Copy_2;
    Rte_DE_UInt8 Rte_VIN_Copy_3_VIN_Copy_3;
    Rte_DE_UInt8 Rte_VIN_Copy_4_VIN_Copy_4;
    Rte_DE_UInt8 Rte_VIN_Copy_5_VIN_Copy_5;
    Rte_DE_UInt8 Rte_VIN_Copy_6_VIN_Copy_6;
    Rte_DE_UInt8 Rte_VIN_Copy_7_VIN_Copy_7;
    Rte_DE_UInt8 Rte_VIN_Copy_8_VIN_Copy_8;
    Rte_DE_UInt8 Rte_VIN_Copy_9_VIN_Copy_9;
    Rte_DE_UInt8 Rte_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
}Rte_tsRB_swc_COL_COL_100ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BCC_AcvCellURchd_BCC_AcvCellURchd;
    Rte_DE_UInt8 Rte_BCC_AcvSocRchd_BCC_AcvSocRchd;
    Rte_DE_UInt8 Rte_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
    Rte_DE_Boolean Rte_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq;
    Rte_DE_Boolean Rte_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
    Rte_DE_UInt8 Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
    Rte_DE_Boolean Rte_BMSH_VCU_Crash_BMSH_VCU_Crash;
    Rte_DE_UInt8 Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
    Rte_DE_UInt8 Rte_BMS_ChgCCSts_BMS_ChgCCSts;
    Rte_DE_Boolean Rte_BSWControl_RstDiagGlb_RstDiagGlb;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BCL_Request_BCL;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BMT_Request_BMT;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BMV_Request_BMV;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BSP_Request_BSP;
    Rte_DE_UInt8 Rte_BSWIOSP_Request_BST_Request_BST;
    Rte_DE_UInt8 Rte_BTHM_ErrChEnd_BTHM_ErrChEnd;
    Rte_DE_UInt8 Rte_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend;
    Rte_DE_UInt8 Rte_BmsSuspCause_SOC_BmsSuspCause_SOC;
    Rte_DE_UInt8 Rte_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage;
    Rte_DE_UInt8 Rte_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage;
    Rte_DE_UInt8 Rte_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage;
    Rte_DE_UInt8 Rte_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent;
    Rte_DE_UInt8 Rte_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp;
    Rte_DE_UInt8 Rte_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp;
    Rte_DE_UInt8 Rte_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn;
    Rte_DE_UInt8 Rte_BmsSuspFault_Insulation_BmsSuspFault_Insulation;
    Rte_DE_UInt8 Rte_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults;
    Rte_DE_UInt8 Rte_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp;
    Rte_DE_UInt8 Rte_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection;
    Rte_DE_UInt8 Rte_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay;
    Rte_DE_UInt8 Rte_CIL_StAcChCnct_CIL_StAcChCnct;
    Rte_DE_UInt8 Rte_CIL_StChAllwd_CIL_StChAllwd;
    Rte_DE_UInt8 Rte_ChargingMode_ChargingMode;
    Rte_DE_UInt16 Rte_CurrentDemand_CurrentDemand;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd4_DEH_ErrCfmd4;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_UInt8 Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq;
    Rte_DE_UInt8 Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq;
    Rte_DE_Boolean Rte_DEH_bAcvChInh_DEH_bAcvChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    Rte_DE_UInt8 Rte_EHPMon_ChgFaultReq_EHPMon_ChgFaultReq;
    Rte_DE_Boolean Rte_EHPMon_ReqRlyNeg_EHPMon_ReqRlyNeg;
    Rte_DE_Boolean Rte_EHPMon_ReqRlyPos_EHPMon_ReqRlyPos;
    Rte_DE_Boolean Rte_EHPMon_ReqRlyPre_EHPMon_ReqRlyPre;
    Rte_DE_UInt8 Rte_EHPMon_VCU_DischgFaultReq_EHPMon_VCU_DischgFaultReq;
    Rte_DE_Boolean Rte_EHPMon_bErrCrashMon_EHPMon_bErrCrashMon;
    Rte_DE_UInt8 Rte_ESIM_CfgLvl2_ESIM_CfgLvl2;
    Rte_DE_UInt8 Rte_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
    Rte_DE_UInt8 Rte_EVCSH_ChMode_EVCSH_ChMode;
    Rte_DE_Float Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
    Rte_DE_UInt16 Rte_EVCSH_StInt_EVCSH_StInt;
    Rte_DE_Float Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT;
    Rte_DE_Boolean Rte_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU;
    Rte_DE_Boolean Rte_IOFS_NegRlyCtr_IOFS_NegRlyCtr;
    Rte_DE_Boolean Rte_IOFS_PosRlyCtr_IOFS_PosRlyCtr;
    Rte_DE_Boolean Rte_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr;
    Rte_DE_UInt16 Rte_VoltageDemand_VoltageDemand;
}Rte_tsRB_swc_COL_COL_10ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
    Rte_DE_UInt32 Rte_BCSP_reserved_BCSP_reserved;
    Rte_DE_UInt8 Rte_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault;
    Rte_DE_UInt8 Rte_BatteryOutputConnectorState_BatteryOutputConnectorState;
    Rte_DE_UInt8 Rte_BatteryType_BatteryType;
    Rte_DE_UInt8 Rte_BmsRevision_BmsRevision;
    Rte_DE_UInt16 Rte_BmsVersion_BmsVersion;
}Rte_tsRB_swc_COL_COL_Init;

typedef struct
{
    Rte_DE_UInt8 Rte_BCC_StAcSys_BCC_StAcSys;
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
    Rte_DE_Boolean Rte_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt32 Rte_BSTC_TiBatOff_BSTC_TiBatOff;
    Rte_DE_Boolean Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm;
    Rte_DE_UInt8 Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
    Rte_DE_Boolean Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm;
    Rte_DE_Boolean Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy;
    Rte_DE_Boolean Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun;
    Rte_DE_Boolean Rte_BTHM_ReqRePrech_BTHM_ReqRePrech;
    Rte_DE_UInt8 Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq;
    Rte_DE_UInt8 Rte_BTHM_StRlyMain_BTHM_StRlyMain;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_Float Rte_CIL_IBatHvRaw_CIL_IBatHvRaw;
    Rte_DE_UInt8 Rte_CIL_ModeMotDrv_CIL_ModeMotDrv;
    Rte_DE_UInt8 Rte_CIL_StBatHvReq_CIL_StBatHvReq;
    Rte_DE_UInt8 Rte_CIL_StChWup_CIL_StChWup;
    Rte_DE_UInt8 Rte_CIL_StTrml15_CIL_StTrml15;
    Rte_DE_Float Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_Float Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv;
    Rte_DE_Float Rte_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv;
    Rte_DE_Float Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
    Rte_DE_Float Rte_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg;
    Rte_DE_Float Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
    Rte_DE_Float Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
    Rte_DE_Boolean Rte_CIL_ZeroPwrFb_CIL_ZeroPwrFb;
    Rte_DE_Boolean Rte_CIL_bKCNegClsSts_CIL_bKCNegClsSts;
    Rte_DE_Boolean Rte_CIL_bMainNegClsSts_CIL_bMainNegClsSts;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
    Rte_DE_UInt32 Rte_CTC_ErrInfo_CTC_ErrInfo;
    Rte_DE_UInt8 Rte_CTC_ErrRlyCh_CTC_ErrRlyCh;
    Rte_DE_UInt8 Rte_CTC_ErrRlyHeat_CTC_ErrRlyHeat;
    Rte_DE_UInt8 Rte_CTC_ErrRlyNeg_CTC_ErrRlyNeg;
    Rte_DE_UInt8 Rte_CTC_ErrRlyPos_CTC_ErrRlyPos;
    Rte_DE_UInt8 Rte_CTC_ErrRlyPrech_CTC_ErrRlyPrech;
    Rte_DE_Float Rte_CTC_IDriftZero_CTC_IDriftZero;
    Rte_DE_Float Rte_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh;
    Rte_DE_Float Rte_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat;
    Rte_DE_Float Rte_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg;
    Rte_DE_Float Rte_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos;
    Rte_DE_Float Rte_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech;
    Rte_DE_UInt8 Rte_CTC_ReqRlyCh_CTC_ReqRlyCh;
    Rte_DE_UInt8 Rte_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg;
    Rte_DE_UInt8 Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
    Rte_DE_UInt8 Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
    Rte_DE_UInt8 Rte_CTC_ReqRlyPos_CTC_ReqRlyPos;
    Rte_DE_UInt8 Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech;
    Rte_DE_Boolean Rte_CTC_ReqZeroPwr_CTC_ReqZeroPwr;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_CTC_StRlyCh_CTC_StRlyCh;
    Rte_DE_UInt8 Rte_CTC_StRlyChNeg_CTC_StRlyChNeg;
    Rte_DE_UInt8 Rte_CTC_StRlyChkCh_CTC_StRlyChkCh;
    Rte_DE_UInt8 Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat;
    Rte_DE_UInt8 Rte_CTC_StRlyChkPos_CTC_StRlyChkPos;
    Rte_DE_UInt8 Rte_CTC_StRlyHeat_CTC_StRlyHeat;
    Rte_DE_UInt8 Rte_CTC_StRlyNeg_CTC_StRlyNeg;
    Rte_DE_UInt8 Rte_CTC_StRlyPos_CTC_StRlyPos;
    Rte_DE_UInt8 Rte_CTC_StRlyPrech_CTC_StRlyPrech;
    Rte_DE_UInt16 Rte_CTC_StSysInt_CTC_StSysInt;
    Rte_DE_Float Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv;
    Rte_DE_Boolean Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl;
    Rte_DE_Boolean Rte_CTC_bAcvCh_CTC_bAcvCh;
    Rte_DE_Boolean Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd;
    Rte_DE_Boolean Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk;
    Rte_DE_Boolean Rte_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh;
    Rte_DE_Boolean Rte_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat;
    Rte_DE_Boolean Rte_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg;
    Rte_DE_Boolean Rte_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos;
    Rte_DE_Boolean Rte_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech;
    Rte_DE_Boolean Rte_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha;
    Rte_DE_Boolean Rte_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh;
    Rte_DE_Boolean Rte_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat;
    Rte_DE_Boolean Rte_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg;
    Rte_DE_Boolean Rte_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos;
    Rte_DE_Boolean Rte_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech;
    Rte_DE_UInt8 Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
    Rte_DE_UInt8 Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag;
    Rte_DE_UInt8 Rte_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd4_DEH_ErrCfmd4;
    Rte_DE_Boolean Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag;
    Rte_DE_Boolean Rte_DEH_ReqRlyCh_DEH_ReqRlyCh;
    Rte_DE_Boolean Rte_DEH_ReqRlyHeat_DEH_ReqRlyHeat;
    Rte_DE_Boolean Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg;
    Rte_DE_Boolean Rte_DEH_ReqRlyPos_DEH_ReqRlyPos;
    Rte_DE_Boolean Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_Boolean Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh;
    Rte_DE_UInt16 Rte_EVCSH_StInt_EVCSH_StInt;
    Rte_DE_Boolean Rte_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
    Rte_DE_Float Rte_NVM_UPrechAccumd_NVM_UPrechAccumd;
}Rte_tsRB_swc_CtctrTranCtl_CTC_10ms;

typedef struct
{
    Rte_DE_Float Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
    Rte_DE_Float Rte_CTC_IDriftZero_CTC_IDriftZero;
}Rte_tsRB_swc_CtctrTranCtl_CTC_Init;

typedef struct
{
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_crash;
    Rte_DE_FaultStatus Rte_vcib_VCIP_eadd_e_inv2FltSts;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvilOpen;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    Rte_DE_Float Rte_vcib_VCIP_macd_u_batIntSmpl_V;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcWakeUp;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_brkSwt1Actv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_brkSwt2Actv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgACU;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgNetConfgABS;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDischgFltReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStsDischgFlt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Acc1Raw_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Acc2Raw_mV;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt;
    Rte_DE_Boolean Rte_vcsb_DIAG_acpd_b_accPed1Vld;
    Rte_DE_Boolean Rte_vcsb_DIAG_acpd_b_accPed2Vld;
    Rte_DE_Boolean Rte_vcsb_DIAG_brpd_b_brkSwtMismatch;
    Rte_DE_Boolean Rte_vcsb_DIAG_ddid_b_bmsMsgErr;
    Rte_DE_Boolean Rte_vcsb_DIAG_ddid_b_egsmMsgErr;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_bmsFltLv4A;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_mcuFltLv2A;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_mcuFltLv3A;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_mcuMsgErr;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33;
    Rte_DE_UInt8 Rte_vcsb_DIAG_digd_st_edcpFlt;
    Rte_DE_UInt8 Rte_vcsb_DIAG_digd_st_hbcpFlt;
    Rte_DE_UInt8 Rte_vcsb_DIAG_digd_st_vehSysErrLevel;
    Rte_DE_Boolean Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err;
    Rte_DE_Boolean Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_Boolean Rte_vild_b_adcCanBusOff_vild_b_adcCanBusOff;
    Rte_DE_Boolean Rte_vild_b_evCanBusOff_vild_b_evCanBusOff;
    Rte_DE_Boolean Rte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr;
    Rte_DE_Boolean Rte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr;
    Rte_DE_Boolean Rte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr;
    Rte_DE_Boolean Rte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgClearDTC_vild_b_flgClearDTC;
    Rte_DE_Boolean Rte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr;
    Rte_DE_Boolean Rte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr;
    Rte_DE_Boolean Rte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr;
    Rte_DE_Boolean Rte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
    Rte_DE_Boolean Rte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
    Rte_DE_Boolean Rte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff;
}Rte_tsRB_swc_DIAG_swc_DIAG_Step;

typedef struct
{
    Rte_DE_rt_Array_UInt8_255 Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv;
    Rte_DE_Float Rte_BCF_ChIIntglNv_BCF_ChIIntglNv;
    Rte_DE_Float Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv;
    Rte_DE_Float Rte_BCF_DeltAhNv_BCF_DeltAhNv;
    Rte_DE_Float Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv;
    Rte_DE_Float Rte_BCF_IIntglNv_BCF_IIntglNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv;
    Rte_DE_Boolean Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv;
    Rte_DE_Boolean Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv;
    Rte_DE_Float Rte_BCF_SocCnsActNv_BCF_SocCnsActNv;
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
    Rte_DE_Float Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv;
    Rte_DE_Float Rte_BCF_SohCalNv_BCF_SohCalNv;
    Rte_DE_Float Rte_BCF_SohCycNv_BCF_SohCycNv;
    Rte_DE_Float Rte_BCF_SohPackNv_BCF_SohPackNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv;
    Rte_DE_rt_Array_Float_24 Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv;
    Rte_DE_rt_Array_Float_144 Rte_BCF_StAryFlsNv_BCF_StAryFlsNv;
    Rte_DE_rt_Array_UInt32_24 Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv;
    Rte_DE_rt_Array_UInt32_24 Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv;
    Rte_DE_UInt32 Rte_BCF_TiBatOffNv_BCF_TiBatOffNv;
    Rte_DE_UInt32 Rte_BCF_TiChFullOff_BCF_TiChFullOff;
    Rte_DE_rt_Array_UInt8_24 Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv;
    Rte_DE_UInt8 Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv;
    Rte_DE_UInt8 Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv;
    Rte_DE_UInt16 Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv;
    Rte_DE_Float Rte_BTHM_TPack_BTHM_TPack;
    Rte_DE_Float Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv;
    Rte_DE_Float Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv;
    Rte_DE_Float Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv;
    Rte_DE_UInt16 Rte_BWLD_CtrChNv_BWLD_CtrChNv;
    Rte_DE_UInt16 Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv;
    Rte_DE_Float Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv;
    Rte_DE_Float Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv;
    Rte_DE_Float Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv;
    Rte_DE_Float Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv;
    Rte_DE_Float Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv;
    Rte_DE_Float Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv;
    Rte_DE_Float Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv;
    Rte_DE_Float Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv;
    Rte_DE_Float Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv;
    Rte_DE_Float Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv;
    Rte_DE_Float Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv;
    Rte_DE_UInt32 Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv;
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv;
    Rte_DE_Float Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv;
    Rte_DE_Float Rte_BWLD_UCellMinNv_BWLD_UCellMinNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
    Rte_DE_Float Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv;
    Rte_DE_Float Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv;
    Rte_DE_Float Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv;
}Rte_tsRB_swc_DiagcEveHndlg_NVM_Write_100ms;

typedef struct
{
    Rte_DE_Boolean Rte_BBC_bAcvBaln_BBC_bAcvBaln;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0594_22_RE;

typedef struct
{
    Rte_DE_UInt32 Rte_BCC_ErrInfo_BCC_ErrInfo;
    Rte_DE_UInt32 Rte_BCF_ErrInfo_BCF_ErrInfo;
    Rte_DE_UInt32 Rte_BPIU_ErrInfo_BPIU_ErrInfo;
    Rte_DE_UInt32 Rte_BPP_ErrInfo_BPP_ErrInfo;
    Rte_DE_UInt32 Rte_BSTC_ErrInfo_BSTC_ErrInfo;
    Rte_DE_UInt32 Rte_BTHM_ErrInfo_BTHM_ErrInfo;
    Rte_DE_UInt16 Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
    Rte_DE_UInt32 Rte_CTC_ErrInfo_CTC_ErrInfo;
    Rte_DE_UInt16 Rte_ELHPN_ErrInfo_ELHPN_ErrInfo;
}Rte_tsRB_swc_DiagcEveHndlg_SetEventStatus_10ms;

typedef struct
{
    Rte_DE_Float Rte_BCC_IObcLimn_BCC_IObcLimn;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0545_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BCC_StCh_BCC_StCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0542_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCC_UObcLimn_BCC_UObcLimn;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0544_22_RE;

typedef struct
{
    Rte_DE_rt_Array_Float_24 Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_IChLim_BCF_IChLim;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055C_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_IChLimMap_BCF_IChLimMap;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_IDchaLim_BCF_IDchaLim;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_IDchaLim_BCF_IDchaLim;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055A_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_IDchaLimMap_BCF_IDchaLimMap;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE;

typedef struct
{
    Rte_DE_rt_Array_Float_24 Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocLimMin_BCF_SocLimMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055D_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocPack_BCF_SocPack;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A1_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0524_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052E_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_SocPackScld_BCF_SocPackScld;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF09_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_SohPack_BCF_SohPack;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0525_22_RE;

typedef struct
{
    Rte_DE_rt_Array_Float_144 Rte_BCF_StAryFlsNv_BCF_StAryFlsNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0522_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0592_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_UBatTotInt_BCF_UBatTotInt;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF00_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCF_UCellAvg_BCF_UCellAvg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CC_22_RE;

typedef struct
{
    Rte_DE_rt_Array_Float_24 Rte_BCF_UMdul_BCF_UMdul;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0593_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0547_22_RE;

typedef struct
{
    Rte_DE_rt_Array_Float_255 Rte_BMC_UCell_BMC_UCell;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0507_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059C_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BMSH_StsMode_BMSH_StsMode;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0505_22_RE;

typedef struct
{
    Rte_DE_UInt16 Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
    Rte_DE_UInt8 Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
    Rte_DE_UInt8 Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
    Rte_DE_UInt16 Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
    Rte_DE_UInt8 Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
    Rte_DE_UInt8 Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE;

typedef struct
{
    Rte_DE_UInt16 Rte_BPIU_IdCellUMax_BPIU_IdCellUMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0527_22_RE;

typedef struct
{
    Rte_DE_UInt16 Rte_BPIU_IdCellUMin_BPIU_IdCellUMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0529_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BPIU_UCellMax_BPIU_UCellMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0526_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BPIU_UCellMin_BPIU_UCellMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0528_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
    Rte_DE_UInt8 Rte_CTC_StRlyCh_CTC_StRlyCh;
    Rte_DE_UInt8 Rte_CTC_StRlyHeat_CTC_StRlyHeat;
    Rte_DE_UInt8 Rte_CTC_StRlyNeg_CTC_StRlyNeg;
    Rte_DE_UInt8 Rte_CTC_StRlyPos_CTC_StRlyPos;
    Rte_DE_UInt8 Rte_CTC_StRlyPrech_CTC_StRlyPrech;
    Rte_DE_UInt8 Rte_DEH_BatMfctrType_DEH_BatMfctrType;
    Rte_DE_UInt8 Rte_DEH_BatMfctrr_DEH_BatMfctrr;
    Rte_DE_Float Rte_DEH_CBatNom_DEH_CBatNom;
    Rte_DE_UInt8 Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag;
    Rte_DE_UInt8 Rte_DEH_DayBatMfctr_DEH_DayBatMfctr;
    Rte_DE_Boolean Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag;
    Rte_DE_UInt8 Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr;
    Rte_DE_UInt16 Rte_DEH_NrPackSerl_DEH_NrPackSerl;
    Rte_DE_UInt8 Rte_DEH_NrVin1_DEH_NrVin1;
    Rte_DE_UInt8 Rte_DEH_NrVin10_DEH_NrVin10;
    Rte_DE_UInt8 Rte_DEH_NrVin11_DEH_NrVin11;
    Rte_DE_UInt8 Rte_DEH_NrVin12_DEH_NrVin12;
    Rte_DE_UInt8 Rte_DEH_NrVin13_DEH_NrVin13;
    Rte_DE_UInt8 Rte_DEH_NrVin14_DEH_NrVin14;
    Rte_DE_UInt8 Rte_DEH_NrVin15_DEH_NrVin15;
    Rte_DE_UInt8 Rte_DEH_NrVin16_DEH_NrVin16;
    Rte_DE_UInt8 Rte_DEH_NrVin17_DEH_NrVin17;
    Rte_DE_UInt8 Rte_DEH_NrVin2_DEH_NrVin2;
    Rte_DE_UInt8 Rte_DEH_NrVin3_DEH_NrVin3;
    Rte_DE_UInt8 Rte_DEH_NrVin4_DEH_NrVin4;
    Rte_DE_UInt8 Rte_DEH_NrVin5_DEH_NrVin5;
    Rte_DE_UInt8 Rte_DEH_NrVin6_DEH_NrVin6;
    Rte_DE_UInt8 Rte_DEH_NrVin7_DEH_NrVin7;
    Rte_DE_UInt8 Rte_DEH_NrVin8_DEH_NrVin8;
    Rte_DE_UInt8 Rte_DEH_NrVin9_DEH_NrVin9;
    Rte_DE_rt_Array_UInt8_24 Rte_DEH_PackCode_DEH_PackCode;
    Rte_DE_Float Rte_DEH_UBatNom_DEH_UBatNom;
    Rte_DE_UInt16 Rte_DEH_YearBatMfctr_DEH_YearBatMfctr;
}Rte_tsRB_swc_DiagcEveHndlg_DEH_1000ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt8 Rte_BSTC_StBcuInt_BSTC_StBcuInt;
    Rte_DE_Boolean Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
    Rte_DE_UInt8 Rte_CIL_StPtIndcr_CIL_StPtIndcr;
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
    Rte_DE_Boolean Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_DEH_ChgLvlErr_DEH_ChgLvlErr;
    Rte_DE_UInt8 Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb;
    Rte_DE_UInt8 Rte_DEH_DischgLvlErr_DEH_DischgLvlErr;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt8 Rte_DEH_LvlErr_DEH_LvlErr;
    Rte_DE_UInt8 Rte_DEH_LvlErrSb_DEH_LvlErrSb;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_UInt8 Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
    Rte_DE_UInt8 Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq;
    Rte_DE_UInt8 Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq;
    Rte_DE_UInt16 Rte_DEH_ValCodDiag_DEH_ValCodDiag;
    Rte_DE_Boolean Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh;
    Rte_DE_Boolean Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh;
    Rte_DE_Boolean Rte_DEH_bAcvChInh_DEH_bAcvChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh;
    Rte_DE_Boolean Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh;
    Rte_DE_Boolean Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1;
    Rte_DE_Boolean Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2;
    Rte_DE_Boolean Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh;
    Rte_DE_Boolean Rte_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1;
    Rte_DE_Boolean Rte_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2;
    Rte_DE_Boolean Rte_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3;
    Rte_DE_Boolean Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh;
    Rte_DE_Boolean Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
    Rte_DE_Boolean Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2;
    Rte_DE_Boolean Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1;
    Rte_DE_Boolean Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2;
    Rte_DE_Boolean Rte_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm;
    Rte_DE_Boolean Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh;
    Rte_DE_Boolean Rte_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm;
}Rte_tsRB_swc_DiagcEveHndlg_DEH_10ms;

typedef struct
{
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053A_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF09_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BTHM_IdCellTMax_BTHM_IdCellTMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052B_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_BTHM_IdCellTMin_BTHM_IdCellTMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052D_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052A_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF06_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052C_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF07_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BTHM_TPack_BTHM_TPack;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0530_22_RE;

typedef struct
{
    Rte_DE_UInt16 Rte_BWLD_CtrCh_BWLD_CtrCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0588_22_RE;

typedef struct
{
    Rte_DE_UInt16 Rte_BWLD_CtrDcha_BWLD_CtrDcha;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0589_22_RE;

typedef struct
{
    Rte_DE_UInt16 Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058A_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_EBatChTot_BWLD_EBatChTot;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053E_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053D_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_IBatChMax_BWLD_IBatChMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A4_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A5_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_PBatChMax_BWLD_PBatChMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A2_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A3_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_SocBatMax_BWLD_SocBatMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AB_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_SocBatMin_BWLD_SocBatMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AA_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AF_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AE_22_RE;

typedef struct
{
    Rte_DE_UInt32 Rte_BWLD_TiBatAgi_BWLD_TiBatAgi;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0591_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A9_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A8_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A7_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A6_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_UCellMax_BWLD_UCellMax;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AD_22_RE;

typedef struct
{
    Rte_DE_Float Rte_BWLD_UCellMin_BWLD_UCellMin;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AC_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_DayTelbox_CIL_DayTelbox;
    Rte_DE_UInt8 Rte_CIL_HourTelbox_CIL_HourTelbox;
    Rte_DE_UInt8 Rte_CIL_MinuTelbox_CIL_MinuTelbox;
    Rte_DE_UInt8 Rte_CIL_MonthTelbox_CIL_MonthTelbox;
    Rte_DE_Float Rte_CIL_SecTelbox_CIL_SecTelbox;
    Rte_DE_UInt16 Rte_CIL_YearTelbox_CIL_YearTelbox;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0523_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_IBatHv_CIL_IBatHv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF05_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_MilgTot_CIL_MilgTot;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF03_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_MilgTot_CIL_MilgTot;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF04_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_PowerMode_CIL_PowerMode;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF06_22_RE;

typedef struct
{
    Rte_DE_SInt32 Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CA_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_SWVerVeh_CIL_SWVerVeh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_SpdVeh_CIL_SpdVeh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF01_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_StBatHvReq_CIL_StBatHvReq;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B8_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BA_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BC_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0534_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TAcChPointPos_CIL_TAcChPointPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0533_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TAcChPointPos_CIL_TAcChPointPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CD_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TBd_CIL_TBd;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0596_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TBd_CIL_TBd;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D1_22_RE;

typedef struct
{
    Rte_DE_SInt16 Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0535_22_RE;

typedef struct
{
    Rte_DE_SInt16 Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0536_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0532_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
    Rte_DE_Float Rte_CIL_TDcChPointPos_CIL_TDcChPointPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_TDcChPointPos_CIL_TDcChPointPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0531_22_RE;

typedef struct
{
    Rte_DE_rt_Array_Float_54 Rte_CIL_TMdul_CIL_TMdul;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x050A_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C5_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C8_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0599_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C6_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0598_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CE_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C7_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059B_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059A_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C4_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0500_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CIL_UTrml30_CIL_UTrml30;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF00_22_RE;

typedef struct
{
    Rte_DE_Boolean Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
    Rte_DE_UInt8 Rte_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd2_DEH_ErrCfmd2;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd4_DEH_ErrCfmd4;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd5_DEH_ErrCfmd5;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd6_DEH_ErrCfmd6;
    Rte_DE_UInt16 Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
}Rte_tsRB_swc_DiagcEveHndlg_GetEventStatus_10ms;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldBatIHv_CIL_bVldBatIHv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BE_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B9_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BB_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldIslnR_CIL_bVldIslnR;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BF_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C3_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C2_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BD_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C0_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C1_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058F_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0590_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058D_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058C_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058E_22_RE;

typedef struct
{
    Rte_DE_Float Rte_CTC_IDriftZero_CTC_IDriftZero;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0597_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_ReqRlyCh_CTC_ReqRlyCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B3_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B7_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B4_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_ReqRlyPos_CTC_ReqRlyPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B5_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B6_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CF_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StRlyCh_CTC_StRlyCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0586_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StRlyCh_CTC_StRlyCh;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D0_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StRlyHeat_CTC_StRlyHeat;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0539_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StRlyNeg_CTC_StRlyNeg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0538_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StRlyPos_CTC_StRlyPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0585_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_CTC_StRlyPrech_CTC_StRlyPrech;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0587_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag;
    Rte_DE_UInt8 Rte_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl;
    Rte_DE_UInt8 Rte_DEH_ModBalCtl_DEH_ModBalCtl;
    Rte_DE_UInt8 Rte_DEH_ReqBalCtl_DEH_ReqBalCtl;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag;
    Rte_DE_Boolean Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag;
    Rte_DE_UInt8 Rte_DEH_StSocCal_DEH_StSocCal;
    Rte_DE_Float Rte_DEH_ValPackSoc_DEH_ValPackSoc;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start_Services;

typedef struct
{
    Rte_DE_Boolean Rte_DEH_ReqRlyCh_DEH_ReqRlyCh;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services;

typedef struct
{
    Rte_DE_Boolean Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services;

typedef struct
{
    Rte_DE_Boolean Rte_DEH_ReqRlyPos_DEH_ReqRlyPos;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services;

typedef struct
{
    Rte_DE_Boolean Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech;
}Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_UInt32 Rte_DEH_TiChFullOff_DEH_TiChFullOff;
    Rte_DE_UInt16 Rte_DEH_ValCodDiag_DEH_ValCodDiag;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_Float Rte_NVM_CBatChTot_NVM_CBatChTot;
    Rte_DE_Float Rte_NVM_CBatDchaTot_NVM_CBatDchaTot;
    Rte_DE_Float Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
    Rte_DE_rt_Array_Float_24 Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls;
    Rte_DE_Float Rte_NVM_ChIIntglFls_NVM_ChIIntglFls;
    Rte_DE_Float Rte_NVM_ChgDeltAh_NVM_ChgDeltAh;
    Rte_DE_UInt16 Rte_NVM_CtrCh_NVM_CtrCh;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
    Rte_DE_UInt16 Rte_NVM_CtrDcha_NVM_CtrDcha;
    Rte_DE_UInt8 Rte_NVM_DayRtcLst_NVM_DayRtcLst;
    Rte_DE_Float Rte_NVM_DeltAh_NVM_DeltAh;
    Rte_DE_Float Rte_NVM_EBatChTot_NVM_EBatChTot;
    Rte_DE_Float Rte_NVM_EBatDchaTot_NVM_EBatDchaTot;
    Rte_DE_Float Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
    Rte_DE_Float Rte_NVM_FullChgSOH_NVM_FullChgSOH;
    Rte_DE_UInt8 Rte_NVM_HourRtcLst_NVM_HourRtcLst;
    Rte_DE_Float Rte_NVM_IBatChMax_NVM_IBatChMax;
    Rte_DE_Float Rte_NVM_IBatDchaMax_NVM_IBatDchaMax;
    Rte_DE_Float Rte_NVM_IIntglFls_NVM_IIntglFls;
    Rte_DE_UInt8 Rte_NVM_MinuRtcLst_NVM_MinuRtcLst;
    Rte_DE_UInt8 Rte_NVM_MonthRtcLst_NVM_MonthRtcLst;
    Rte_DE_Float Rte_NVM_PBatChMax_NVM_PBatChMax;
    Rte_DE_Float Rte_NVM_PBatDchaMax_NVM_PBatDchaMax;
    Rte_DE_Float Rte_NVM_RIslnNeg_NVM_RIslnNeg;
    Rte_DE_Float Rte_NVM_RIslnPos_NVM_RIslnPos;
    Rte_DE_rt_Array_Float_24 Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls;
    Rte_DE_rt_Array_UInt8_255 Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln;
    Rte_DE_Boolean Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
    Rte_DE_Boolean Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
    Rte_DE_UInt8 Rte_NVM_SecRtcLst_NVM_SecRtcLst;
    Rte_DE_Float Rte_NVM_SocBatMax_NVM_SocBatMax;
    Rte_DE_Float Rte_NVM_SocBatMin_NVM_SocBatMin;
    Rte_DE_Float Rte_NVM_SocCnsAct_NVM_SocCnsAct;
    Rte_DE_Float Rte_NVM_SocPackScld_NVM_SocPackScld;
    Rte_DE_Float Rte_NVM_SocUOcIni_NVM_SocUOcIni;
    Rte_DE_Float Rte_NVM_SohCalFls_NVM_SohCalFls;
    Rte_DE_Float Rte_NVM_SohCycFls_NVM_SohCycFls;
    Rte_DE_Float Rte_NVM_SohPackFls_NVM_SohPackFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls;
    Rte_DE_rt_Array_Float_144 Rte_NVM_StAryFls_NVM_StAryFls;
    Rte_DE_Float Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
    Rte_DE_Float Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
    Rte_DE_Float Rte_NVM_TPackFls_NVM_TPackFls;
    Rte_DE_UInt32 Rte_NVM_TiBatAgi_NVM_TiBatAgi;
    Rte_DE_UInt32 Rte_NVM_TiBatOffFls_NVM_TiBatOffFls;
    Rte_DE_rt_Array_UInt32_24 Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls;
    Rte_DE_rt_Array_UInt32_24 Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls;
    Rte_DE_Float Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
    Rte_DE_Float Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
    Rte_DE_Float Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
    Rte_DE_Float Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
    Rte_DE_Float Rte_NVM_UCellMax_NVM_UCellMax;
    Rte_DE_Float Rte_NVM_UCellMin_NVM_UCellMin;
    Rte_DE_Float Rte_NVM_UPrechAccumd_NVM_UPrechAccumd;
    Rte_DE_UInt16 Rte_NVM_YearRtcLst_NVM_YearRtcLst;
    Rte_DE_rt_Array_UInt8_24 Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls;
}Rte_tsRB_swc_DiagcEveHndlg_DEH_Init;

typedef struct
{
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_UInt32 Rte_DEH_TiChFullOff_DEH_TiChFullOff;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_Float Rte_NVM_CBatChTot_NVM_CBatChTot;
    Rte_DE_Float Rte_NVM_CBatDchaTot_NVM_CBatDchaTot;
    Rte_DE_Float Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
    Rte_DE_rt_Array_Float_24 Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls;
    Rte_DE_Float Rte_NVM_ChIIntglFls_NVM_ChIIntglFls;
    Rte_DE_Float Rte_NVM_ChgDeltAh_NVM_ChgDeltAh;
    Rte_DE_UInt16 Rte_NVM_CtrCh_NVM_CtrCh;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
    Rte_DE_Float Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
    Rte_DE_UInt16 Rte_NVM_CtrDcha_NVM_CtrDcha;
    Rte_DE_UInt8 Rte_NVM_DayRtcLst_NVM_DayRtcLst;
    Rte_DE_Float Rte_NVM_DeltAh_NVM_DeltAh;
    Rte_DE_Float Rte_NVM_EBatChTot_NVM_EBatChTot;
    Rte_DE_Float Rte_NVM_EBatDchaTot_NVM_EBatDchaTot;
    Rte_DE_Float Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
    Rte_DE_Float Rte_NVM_FullChgSOH_NVM_FullChgSOH;
    Rte_DE_UInt8 Rte_NVM_HourRtcLst_NVM_HourRtcLst;
    Rte_DE_Float Rte_NVM_IBatChMax_NVM_IBatChMax;
    Rte_DE_Float Rte_NVM_IBatDchaMax_NVM_IBatDchaMax;
    Rte_DE_Float Rte_NVM_IIntglFls_NVM_IIntglFls;
    Rte_DE_UInt8 Rte_NVM_MinuRtcLst_NVM_MinuRtcLst;
    Rte_DE_UInt8 Rte_NVM_MonthRtcLst_NVM_MonthRtcLst;
    Rte_DE_Float Rte_NVM_PBatChMax_NVM_PBatChMax;
    Rte_DE_Float Rte_NVM_PBatDchaMax_NVM_PBatDchaMax;
    Rte_DE_Float Rte_NVM_RIslnNeg_NVM_RIslnNeg;
    Rte_DE_Float Rte_NVM_RIslnPos_NVM_RIslnPos;
    Rte_DE_rt_Array_Float_24 Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls;
    Rte_DE_rt_Array_UInt8_255 Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln;
    Rte_DE_Boolean Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
    Rte_DE_Boolean Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
    Rte_DE_UInt8 Rte_NVM_SecRtcLst_NVM_SecRtcLst;
    Rte_DE_Float Rte_NVM_SocBatMax_NVM_SocBatMax;
    Rte_DE_Float Rte_NVM_SocBatMin_NVM_SocBatMin;
    Rte_DE_Float Rte_NVM_SocCnsAct_NVM_SocCnsAct;
    Rte_DE_Float Rte_NVM_SocPackScld_NVM_SocPackScld;
    Rte_DE_Float Rte_NVM_SocUOcIni_NVM_SocUOcIni;
    Rte_DE_Float Rte_NVM_SohCalFls_NVM_SohCalFls;
    Rte_DE_Float Rte_NVM_SohCycFls_NVM_SohCycFls;
    Rte_DE_Float Rte_NVM_SohPackFls_NVM_SohPackFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls;
    Rte_DE_rt_Array_Float_24 Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls;
    Rte_DE_rt_Array_Float_144 Rte_NVM_StAryFls_NVM_StAryFls;
    Rte_DE_Float Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
    Rte_DE_Float Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
    Rte_DE_Float Rte_NVM_TPackFls_NVM_TPackFls;
    Rte_DE_UInt32 Rte_NVM_TiBatAgi_NVM_TiBatAgi;
    Rte_DE_UInt32 Rte_NVM_TiBatOffFls_NVM_TiBatOffFls;
    Rte_DE_rt_Array_UInt32_24 Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls;
    Rte_DE_rt_Array_UInt32_24 Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls;
    Rte_DE_Float Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
    Rte_DE_Float Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
    Rte_DE_Float Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
    Rte_DE_Float Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
    Rte_DE_Float Rte_NVM_UCellMax_NVM_UCellMax;
    Rte_DE_Float Rte_NVM_UCellMin_NVM_UCellMin;
    Rte_DE_Float Rte_NVM_UPrechAccumd_NVM_UPrechAccumd;
    Rte_DE_UInt16 Rte_NVM_YearRtcLst_NVM_YearRtcLst;
    Rte_DE_rt_Array_UInt8_24 Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls;
}Rte_tsRB_swc_DiagcEveHndlg_NVM_Read_10ms;

typedef struct
{
    Rte_DE_Float Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053C_22_RE;

typedef struct
{
    Rte_DE_Float Rte_ELHPN_RIslnPos_ELHPN_RIslnPos;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053B_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058B_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_ELHPN_StIsln_ELHPN_StIsln;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0595_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_EVCSH_ChMode_EVCSH_ChMode;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CB_22_RE;

typedef struct
{
    Rte_DE_Float Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059F_22_RE;

typedef struct
{
    Rte_DE_Float Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
}Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C9_22_RE;

typedef struct
{
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_airCmprSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_iptWorkSt;
    Rte_DE_McuSts Rte_vcib_VCIP_dccd_e_24vDcdcModAct;
    Rte_DE_Float Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg;
    Rte_DE_Float Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW;
    Rte_DE_Float Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hvbZeroPwrReq;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_tboxChgDepth;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_airCmprAct_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_iptActPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_actWorkSts1;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmAccConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgProcss;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcChgSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ptcConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxChgLmtSw;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbVolt_V;
    Rte_DE_Float Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
    Rte_DE_Float Rte_vcsb_EGYM_accd_pwr_maxPwrLim_kW;
    Rte_DE_Float Rte_vcsb_EGYM_accd_pwr_minPwrLim_kW;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_acEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_accyEnbFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_mcuEnbFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_zeroPwrFb;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax;
    Rte_DE_UInt8 Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW;
    Rte_DE_UInt8 Rte_vcsb_EGYM_egmd_st_vcuChgLimResp;
    Rte_DE_UInt8 Rte_vcsb_HVSM_bmsd_e_modeTgt;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_dchaOn;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna3HW;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acwpHeat;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcConnStsFb;
}Rte_tsRB_swc_EGYM_swc_EGYM_Step;

typedef struct
{
    Rte_DE_UInt8 Rte_BSTC_StBcu_BSTC_StBcu;
    Rte_DE_UInt16 Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg;
    Rte_DE_UInt32 Rte_CIL_DucycCrash_CIL_DucycCrash;
    Rte_DE_UInt32 Rte_CIL_DucycHvil_CIL_DucycHvil;
    Rte_DE_UInt32 Rte_CIL_FrqCrash_CIL_FrqCrash;
    Rte_DE_UInt32 Rte_CIL_FrqHvil_CIL_FrqHvil;
    Rte_DE_SInt32 Rte_CIL_RIslnNeg_CIL_RIslnNeg;
    Rte_DE_SInt32 Rte_CIL_RIslnPos_CIL_RIslnPos;
    Rte_DE_UInt8 Rte_CIL_StCrash_CIL_StCrash;
    Rte_DE_Float Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
    Rte_DE_UInt8 Rte_CTC_StHvbat_CTC_StHvbat;
    Rte_DE_UInt8 Rte_CTC_StLoopHv_CTC_StLoopHv;
    Rte_DE_UInt8 Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag;
    Rte_DE_Boolean Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd1_DEH_ErrCfmd1;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd3_DEH_ErrCfmd3;
    Rte_DE_UInt32 Rte_DEH_ErrCfmd5_DEH_ErrCfmd5;
    Rte_DE_UInt16 Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
    Rte_DE_Boolean Rte_DEH_RstDiagGlb_DEH_RstDiagGlb;
    Rte_DE_Boolean Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq;
    Rte_DE_UInt8 Rte_DEH_StsIninNv_DEH_StsIninNv;
    Rte_DE_Boolean Rte_DEH_bAcvBdNew_DEH_bAcvBdNew;
    Rte_DE_UInt16 Rte_ELHPN_ErrInfo_ELHPN_ErrInfo;
    Rte_DE_Float Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
    Rte_DE_Float Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv;
    Rte_DE_Float Rte_ELHPN_RIslnPos_ELHPN_RIslnPos;
    Rte_DE_Float Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv;
    Rte_DE_Boolean Rte_ELHPN_StCrash_ELHPN_StCrash;
    Rte_DE_UInt8 Rte_ELHPN_StCrashIni_ELHPN_StCrashIni;
    Rte_DE_UInt8 Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
    Rte_DE_UInt8 Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
    Rte_DE_UInt8 Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2;
    Rte_DE_UInt8 Rte_ELHPN_StIsln_ELHPN_StIsln;
    Rte_DE_UInt8 Rte_ELHPN_StIslnErr_ELHPN_StIslnErr;
    Rte_DE_UInt8 Rte_ELHPN_StVehIsln_ELHPN_StVehIsln;
    Rte_DE_UInt8 Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
    Rte_DE_Boolean Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas;
    Rte_DE_UInt8 Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq;
    Rte_DE_Float Rte_NVM_RIslnNeg_NVM_RIslnNeg;
    Rte_DE_Float Rte_NVM_RIslnPos_NVM_RIslnPos;
}Rte_tsRB_swc_EltlLnkHzrdProtnNet_ELHPN_50ms;

typedef struct
{
    Rte_DE_UInt8 Rte_ELHPN_StCrashIni_ELHPN_StCrashIni;
    Rte_DE_UInt8 Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
    Rte_DE_UInt8 Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
}Rte_tsRB_swc_EltlLnkHzrdProtnNet_ELHPN_Init;

typedef struct
{
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_AcWrk;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_GearLeverPos Rte_vcib_VCIP_drid_e_gearLvrPosRaw;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_engd_V_engFuelConsInst_ml;
    Rte_DE_Float Rte_vcib_VCIP_engd_dV_engFuelCns_lph;
    Rte_DE_UInt8 Rte_vcib_VCIP_engd_st_apuActWrkSt;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_epbd_e_parkingSts;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvilOpen;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMainRlySts;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_q_hvbSOC_pct;
    Rte_DE_Float Rte_vcib_VCIP_macd_V_tankFuelLvl_l;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcWakeUp;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_driverStartReq;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_SInt8 Rte_vcib_VCIP_trad_st_trsm1GearAct;
    Rte_DE_Float Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_bcmOdometerbackup;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_ipkOdometerbackup;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_odometer_km;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_DIAG_ddid_b_bmsMsgErr;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_bmsFltLv4A;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_mcuFltLv2A;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_mcuFltLv3A;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_mcuMsgErr;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP;
    Rte_DE_Boolean Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err;
    Rte_DE_Boolean Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_brkSysFlt;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_ePTFault;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_evLampOn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_hevLampOn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_odoBckpEn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_turtleLmpOn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_vehOvrLoadEnbl;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_odoTotal_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehCrsDst_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km;
    Rte_DE_PowerFlowMode Rte_vcsb_HMIF_dspd_e_vehPwrFlow;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_m_vehWeight_kg;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_num_errorCode;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_q_hvbSOC_pct;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_drvModInd;
    Rte_DE_UInt16 Rte_vcsb_HMIF_dspd_st_drvPfmncRedn;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_drvrOptRmdr;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehCalNum;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehDrvMode;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehFailLvl;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehOverLoadSts;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehSubFailLvl;
    Rte_DE_Boolean Rte_vcsb_HVSM_apud_b_tmpFrcSttApu1;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_ptRdyInd;
    Rte_DE_Float Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
    Rte_DE_Float Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_veh4WDModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehEcoModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehSportModActv;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_HEVModeReq Rte_vcsb_VOMM_drid_e_drvrHEVModReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_EVModeActive;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_PHEVModeActive;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_SHEVModeActive;
    Rte_DE_HybModeMngr Rte_vcsb_VOMM_hmmd_e_hmmState;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
}Rte_tsRB_swc_HMIF_swc_HMIF_Step;

typedef struct
{
    Rte_DE_McuSts Rte_vcib_VCIP_accd_e_PtcSt;
    Rte_DE_McuSts Rte_vcib_VCIP_accd_e_airCmprSt;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPos_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch;
    Rte_DE_McuSts Rte_vcib_VCIP_brpd_e_bdcacWrk;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_EmergencyStop;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_crash;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk;
    Rte_DE_McuSts Rte_vcib_VCIP_dccd_e_24vDcdcModAct;
    Rte_DE_DCDCMode Rte_vcib_VCIP_dccd_e_modeAct;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk;
    Rte_DE_McuSts Rte_vcib_VCIP_eadd_e_eadInv2Sts;
    Rte_DE_ElMac Rte_vcib_VCIP_eadd_e_inv2ModeAct;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_epbd_e_parkingSts;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvilOpen;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_lowTempProtnReq;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg;
    Rte_DE_McuSts Rte_vcib_VCIP_hvbd_e_hcmWrkSt;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbAssiRly;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
    Rte_DE_HVBattStatus Rte_vcib_VCIP_hvbd_e_hvbStatus;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_i_hvbCurr_A;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_q_hvbSOC_pct;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvilOpenSt;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_epsSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_vcuSelfChkOk;
    Rte_DE_McuSts Rte_vcib_VCIP_macd_e_sdcacWrk;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcWakeUp;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_driverStartReq;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_trad_b_trsm2GearshiftActv;
    Rte_DE_SInt8 Rte_vcib_VCIP_trad_st_trsm2GearAct;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_AccyEnReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_AccyFltSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmCampModeSwt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmTakeEleSwt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmV2XDchaSw;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgBBMMsgErr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bbmFltSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bbmWorkSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_dcChgCcSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_dccAccyConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgAccy;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmAccConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmHvilSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgCcsts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgFltReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDischgFltReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbPreChgSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcChgCCSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdCCline;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_pepsRKECom;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxRsrChgSt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_UInt8 Rte_vcob_VCOP_BMSH_ChargeLEDCtrl;
    Rte_DE_UInt8 Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_accyEnbFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg;
    Rte_DE_UInt8 Rte_vcsb_HVSM_bmsd_e_modeTgt;
    Rte_DE_Boolean Rte_vcsb_HVSM_dccd_b_DCDCEnabled;
    Rte_DE_DCDCMode Rte_vcsb_HVSM_dccd_e_modeTgt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt;
    Rte_DE_Boolean Rte_vcsb_HVSM_eadd_b_ead2Avail;
    Rte_DE_Boolean Rte_vcsb_HVSM_eadd_b_ead2Enad;
    Rte_DE_ElMac Rte_vcsb_HVSM_eadd_e_inv2ModeTgt;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_CampModeFb;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_acPtcEnb;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_allowChg;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_chgCablePlugged;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_dchaOn;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_lvCutOffReq;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_rlyTmOut;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_tmOutFlg;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_HVBattStatus Rte_vcsb_HVSM_hvbd_e_modeTgt;
    Rte_DE_Float Rte_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyPreRlySts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyRlyFlt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyRlySts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyTakeSts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_ptRdyInd;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV;
    Rte_DE_Boolean Rte_vcsb_HVSM_obcd_b_chargerPlugged;
    Rte_DE_ChargerStatus Rte_vcsb_HVSM_obcd_e_chargerSts;
    Rte_DE_Boolean Rte_vcsb_SCAP_eadd_b_mot2TqOff;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_GearLeverPos Rte_vcsb_VOMM_drid_e_gearLvrPos;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_nmRdySlp;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_nmWkUp;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_pwrHoldReq;
    Rte_DE_NMStatus Rte_vcsb_VOMM_pmmd_e_CanNMSts;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_PTDisabled;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_PTEnabled;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_StartDemRaw;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRunRaw;
}Rte_tsRB_swc_HVSM_swc_HVSM_Step;

typedef struct
{
    Rte_DE_Float Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_u_busInv2HVAct_V;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_MEST_masd_b_vehOvrLoadEnbl;
    Rte_DE_Float Rte_vcsb_MEST_masd_m_vehWeight_kg;
    Rte_DE_UInt16 Rte_vcsb_MEST_masd_st_vehCalNum;
    Rte_DE_UInt8 Rte_vcsb_MEST_masd_st_vehOverLoadSts;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
}Rte_tsRB_swc_MEST_swc_MEST_Step;

typedef struct
{
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_obcWakeUpActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_tboxPowOffCmd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_actWorkSts1;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxLife;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_lifeCnt;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_lockVehPer;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_pwrOffCmd;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_tboxLifeSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_verCvsRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_versionConversion;
    Rte_DE_Float Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph;
}Rte_tsRB_swc_OGVL_swc_OGVL_Step;

typedef struct
{
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcWakeUp;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockLimSet;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockVehType;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_actWorkSts1;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_RMLK_rlcd_b_LockVehSts;
    Rte_DE_Boolean Rte_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff;
    Rte_DE_Boolean Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff;
    Rte_DE_Boolean Rte_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_FunLockVehActive;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_LockLimResult;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_LockVehType;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts;
    Rte_DE_Float Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph;
}Rte_tsRB_swc_RMLK_swc_RMLK_Step;

typedef struct
{
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_ElMac Rte_vcib_VCIP_eadd_e_inv2ModeAct;
    Rte_DE_Float Rte_vcib_VCIP_eadd_fact_mot2GearRat;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_q_hvbSOC_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_trad_b_trsm2GearshiftActv;
    Rte_DE_Float Rte_vcib_VCIP_trad_fact_trsm2GearRat;
    Rte_DE_SInt8 Rte_vcib_VCIP_trad_st_trsm2GearAct;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_hvbCurr_A;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbVolt_V;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActvRaw;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    Rte_DE_Float Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_mcuEnbFlg;
    Rte_DE_Boolean Rte_vcsb_HVSM_eadd_b_ead2Enad;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_pwrOffCmd;
    Rte_DE_Boolean Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff;
    Rte_DE_Boolean Rte_vcsb_SCAP_eadd_b_mot2TqOff;
    Rte_DE_Float Rte_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMax_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMin_Nm;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_veh4WDModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehSportModActv;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_EVModeActive;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
}Rte_tsRB_swc_SCAP_swc_SCAP_Step;

typedef struct
{
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPos_pct;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_Float Rte_vcib_VCIP_brpd_x_brkPedlPos_pct;
    Rte_DE_Float Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_epbd_e_parkingSts;
    Rte_DE_Float Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_vscEHBAVHSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSlipWarn;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbHHCActive;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_DIAG_brpd_b_brkSwtMismatch;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehFailLvl;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_Float Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph;
    Rte_DE_Float Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMax_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2;
    Rte_DE_Boolean Rte_vcsb_SCOO_ccdd_b_accCtrlActv;
    Rte_DE_Boolean Rte_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd;
    Rte_DE_CrsBtnErrSts Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts;
    Rte_DE_CrsBtnSts Rte_vcsb_SCOO_ccdd_e_crsBtnSts;
    Rte_DE_CrModeMngr_e Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode;
    Rte_DE_CruiseSts_e Rte_vcsb_SCOO_ccdd_e_crsCtrlSts;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct;
    Rte_DE_Float Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2;
    Rte_DE_Boolean Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld;
    Rte_DE_Boolean Rte_vcsb_SCOO_ctdd_b_eCreepReq;
    Rte_DE_Float Rte_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph;
    Rte_DE_Float Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm;
    Rte_DE_Boolean Rte_vcsb_SCOO_vsld_b_vslTqIntvReq;
    Rte_DE_Float Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph;
    Rte_DE_Float Rte_vcsb_TCOO_apdd_tq_whlDem_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm;
    Rte_DE_Boolean Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehEcoModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehSportModActv;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
}Rte_tsRB_swc_SCOO_swc_SCOO_Step;

typedef struct
{
    Rte_DE_Boolean Rte_vcib_VCIP_acpd_b_accPedlPosVld;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPos_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    Rte_DE_Float Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_Float Rte_vcib_VCIP_brpd_x_brkPedlPos_pct;
    Rte_DE_Float Rte_vcib_VCIP_eadd_fact_mot2GearRat;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_q_hvbSOC_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Float Rte_vcib_VCIP_trad_fact_trsm2GearRat;
    Rte_DE_SInt8 Rte_vcib_VCIP_trad_st_trsm2GearAct;
    Rte_DE_Float Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmEngRecSwtReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ehbVlcCddActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgNetConfgABS;
    Rte_DE_Float Rte_vcib_VCIP_vild_l_whlRad_m;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_csmRgnLvlSet;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ehbIsaSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    Rte_DE_Float Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbAebActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbDtcActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbVlcActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbVlcAvailb;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_pdcBrkFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_Float Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMax_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMin_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2;
    Rte_DE_Boolean Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld;
    Rte_DE_Boolean Rte_vcsb_SCOO_ctdd_b_eCreepReq;
    Rte_DE_Float Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph;
    Rte_DE_Float Rte_vcsb_TCOO_apdd_tq_whlDem_Nm;
    Rte_DE_Boolean Rte_vcsb_TCOO_dtdd_b_drvPfmncDrgDec;
    Rte_DE_UInt8 Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp;
    Rte_DE_Float Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_tdad_tq_whlDem_Nm;
    Rte_DE_Boolean Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld;
    Rte_DE_Boolean Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep;
    Rte_DE_Boolean Rte_vcsb_TCOO_tqdd_b_gpOvrd;
    Rte_DE_UInt8 Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv;
    Rte_DE_UInt8 Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp;
    Rte_DE_UInt8 Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn;
    Rte_DE_Float Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct;
    Rte_DE_Float Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_veh4WDModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehEcoModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehSportModActv;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_GearLeverPos Rte_vcsb_VOMM_drid_e_gearLvrPos;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_EVModeActive;
}Rte_tsRB_swc_TCOO_swc_TCOO_Step;

typedef struct
{
    Rte_DE_McuSts Rte_vcib_VCIP_accd_e_PtcSt;
    Rte_DE_Float Rte_vcib_VCIP_accd_n_acFanReqSpd_pct;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_cbnThermMngReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_iptWorkSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_ptcWorkStRear;
    Rte_DE_Float Rte_vcib_VCIP_accd_t_ambTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_accd_u_acPresVolt_V;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_UInt8 Rte_vcib_VCIP_dccd_st_12vDcdcModAct;
    Rte_DE_Float Rte_vcib_VCIP_dccd_t_dcdcTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_eadd_t_inv2Temp_C;
    Rte_DE_Float Rte_vcib_VCIP_eadd_t_mot2Temp_C;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbHeatEnad;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvbThermMngReq;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbMin_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_obcd_t_obcTemp_C;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgBatCol;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgAccy;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgFan;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_acwpOutptTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_TS5sensorFb_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_Boolean Rte_vcsb_HVSM_obcd_b_chargerPlugged;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ActiveCool_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_BalanceHeat_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_PassCool_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_PassHeat_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_TwoWayVlvReq;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_accmEnb;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_afterRunActive;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_b_fan2Ena;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_fanRly1Req;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_fanRly2Req;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna3;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna3HW;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEnaHW;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_hvbDeft;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_iptcHtIpuCl;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ipuResvHt;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv1V2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv1V3;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv2V2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv4V2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv4V3;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_wtrPmpRly1Req;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_wtrPmpRly2Req;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_FWFVTgt_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_MHGVTgt_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW;
    Rte_DE_Float Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acwpHeat;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acwpSpdReq;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptc3RlyFlt;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcConnStsFb;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcRlyFlt;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_tv4;
    Rte_DE_Float Rte_vcsb_THSM_thmd_t_acwpTemp_C;
    Rte_DE_Boolean Rte_vcsb_VBSW_vbsd_b_vbsShtDwnHVReq;
    Rte_DE_GearLeverPos Rte_vcsb_VOMM_drid_e_gearLvrPos;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_pwrHoldReq;
}Rte_tsRB_swc_THSM_swc_THSM_Step;

typedef struct
{
    Rte_DE_UInt8 Rte_ACCM1_ActPower_ACCM1_ActPower;
    Rte_DE_UInt8 Rte_ACU_CrashOutputSts_ACU_CrashOutputSts;
    Rte_DE_UInt8 Rte_AC_ACCM_ActPower_AC_ACCM_ActPower;
    Rte_DE_Boolean Rte_AC_ACCM_Status_AC_ACCM_Status;
    Rte_DE_UInt8 Rte_AC_AmbientTemperature_AC_AmbientTemperature;
    Rte_DE_Boolean Rte_AC_AmbientTemperatureInvalid_AC_AmbientTemperatureInvalid;
    Rte_DE_UInt8 Rte_AC_CabinThermalReq_AC_CabinThermalReq;
    Rte_DE_UInt8 Rte_AC_CoolingFanPWMSpd_AC_CoolingFanPWMSpd;
    Rte_DE_UInt8 Rte_AC_IPTC_ActPower_AC_IPTC_ActPower;
    Rte_DE_Boolean Rte_AC_IPTC_WorkSts_AC_IPTC_WorkSts;
    Rte_DE_UInt8 Rte_AC_PTC_ActPower_AC_PTC_ActPower;
    Rte_DE_UInt8 Rte_AC_PTC_ActPwr_Rear_AC_PTC_ActPwr_Rear;
    Rte_DE_Boolean Rte_AC_PTC_WorkSts_AC_PTC_WorkSts;
    Rte_DE_Boolean Rte_AC_PTC_WorkSts_Rear_AC_PTC_WorkSts_Rear;
    Rte_DE_Boolean Rte_ADC1Ctr_AlvCtrErrFlg_ADC_ADC1Ctr_AlvCtrErrFlg_ADC;
    Rte_DE_Boolean Rte_ADC1Ctr_AlvCtrErrFlg_PMS_ADC1Ctr_AlvCtrErrFlg_PMS;
    Rte_DE_Boolean Rte_ADC1Ctr_ComRxToutFlg_ADC_ADC1Ctr_ComRxToutFlg_ADC;
    Rte_DE_Boolean Rte_ADC1Ctr_ComRxToutFlg_PMS_ADC1Ctr_ComRxToutFlg_PMS;
    Rte_DE_Boolean Rte_ADC1Ctr_CsmErrFlg_ADC_ADC1Ctr_CsmErrFlg_ADC;
    Rte_DE_Boolean Rte_ADC1Ctr_CsmErrFlg_PMS_ADC1Ctr_CsmErrFlg_PMS;
    Rte_DE_Boolean Rte_ADC1PMSCtr_AlvCtrErrFlg_ADC_ADC1PMSCtr_AlvCtrErrFlg_ADC;
    Rte_DE_Boolean Rte_ADC1PMSCtr_AlvCtrErrFlg_PMS_ADC1PMSCtr_AlvCtrErrFlg_PMS;
    Rte_DE_Boolean Rte_ADC1PMSCtr_ComRxToutFlg_ADC_ADC1PMSCtr_ComRxToutFlg_ADC;
    Rte_DE_Boolean Rte_ADC1PMSCtr_ComRxToutFlg_PMS_ADC1PMSCtr_ComRxToutFlg_PMS;
    Rte_DE_Boolean Rte_ADC1PMSCtr_CsmErrFlg_ADC_ADC1PMSCtr_CsmErrFlg_ADC;
    Rte_DE_Boolean Rte_ADC1PMSCtr_CsmErrFlg_PMS_ADC1PMSCtr_CsmErrFlg_PMS;
    Rte_DE_Boolean Rte_ADC1_CANBUS_flag_ADC1_CANBUS_flag;
    Rte_DE_Boolean Rte_ADC1_ControlGear_Enable_ADC1_ControlGear_Enable;
    Rte_DE_Boolean Rte_ADC1_ControlGear_Enable_ADC_ADC1_ControlGear_Enable_ADC;
    Rte_DE_Boolean Rte_ADC1_ControlTorque_Enable_ADC1_ControlTorque_Enable;
    Rte_DE_Boolean Rte_ADC1_ControlTorque_Enable_ADC_ADC1_ControlTorque_Enable_ADC;
    Rte_DE_Boolean Rte_ADC1_Ctrl_Status_ADC1_Ctrl_Status;
    Rte_DE_Boolean Rte_ADC1_Ctrl_Status_ADC_ADC1_Ctrl_Status_ADC;
    Rte_DE_Boolean Rte_ADC1_SwitchCtrl_Req_ADC1_SwitchCtrl_Req;
    Rte_DE_Boolean Rte_ADC1_SwitchCtrl_Req_ADC_ADC1_SwitchCtrl_Req_ADC;
    Rte_DE_Boolean Rte_ADC1_System_Status_ADC1_System_Status;
    Rte_DE_Boolean Rte_ADC1_System_Status_ADC_ADC1_System_Status_ADC;
    Rte_DE_UInt8 Rte_ADC1_TargetGearPostion_ADC1_TargetGearPostion;
    Rte_DE_UInt8 Rte_ADC1_TargetGearPostion_ADC_ADC1_TargetGearPostion_ADC;
    Rte_DE_UInt16 Rte_ADC1_Target_DrivingTorque_ADC1_Target_DrivingTorque;
    Rte_DE_UInt16 Rte_ADC1_Target_DrivingTorque_ADC_ADC1_Target_DrivingTorque_ADC;
    Rte_DE_UInt8 Rte_ADC1_Temp_ADC1_Temp;
    Rte_DE_UInt8 Rte_ADC1_Temp_ADC_ADC1_Temp_ADC;
    Rte_DE_Boolean Rte_ADCCtr_AlvCtrErrFlg_ADC_ADCCtr_AlvCtrErrFlg_ADC;
    Rte_DE_Boolean Rte_ADCCtr_AlvCtrErrFlg_PMS_ADCCtr_AlvCtrErrFlg_PMS;
    Rte_DE_Boolean Rte_ADCCtr_ComRxToutFlg_ADC_ADCCtr_ComRxToutFlg_ADC;
    Rte_DE_Boolean Rte_ADCCtr_ComRxToutFlg_PMS_ADCCtr_ComRxToutFlg_PMS;
    Rte_DE_Boolean Rte_ADCCtr_CsmErrFlg_ADC_ADCCtr_CsmErrFlg_ADC;
    Rte_DE_Boolean Rte_ADCCtr_CsmErrFlg_PMS_ADCCtr_CsmErrFlg_PMS;
    Rte_DE_Boolean Rte_ADCPMSCtr_AlvCtrErrFlg_ADC_ADCPMSCtr_AlvCtrErrFlg_ADC;
    Rte_DE_Boolean Rte_ADCPMSCtr_AlvCtrErrFlg_PMS_ADCPMSCtr_AlvCtrErrFlg_PMS;
    Rte_DE_Boolean Rte_ADCPMSCtr_ComRxToutFlg_ADC_ADCPMSCtr_ComRxToutFlg_ADC;
    Rte_DE_Boolean Rte_ADCPMSCtr_ComRxToutFlg_PMS_ADCPMSCtr_ComRxToutFlg_PMS;
    Rte_DE_Boolean Rte_ADCPMSCtr_CsmErrFlg_ADC_ADCPMSCtr_CsmErrFlg_ADC;
    Rte_DE_Boolean Rte_ADCPMSCtr_CsmErrFlg_PMS_ADCPMSCtr_CsmErrFlg_PMS;
    Rte_DE_Boolean Rte_ADC_CANBusOff_flg_ADC_CANBusOff_flg;
    Rte_DE_Boolean Rte_ADC_ControlGear_Enable_ADC_ControlGear_Enable;
    Rte_DE_Boolean Rte_ADC_ControlGear_Enable_ADC_ADC_ControlGear_Enable_ADC;
    Rte_DE_Boolean Rte_ADC_ControlTorque_Enable_ADC_ControlTorque_Enable;
    Rte_DE_Boolean Rte_ADC_ControlTorque_Enable_ADC_ADC_ControlTorque_Enable_ADC;
    Rte_DE_Boolean Rte_ADC_Ctrl_Status_ADC_Ctrl_Status;
    Rte_DE_Boolean Rte_ADC_Ctrl_Status_ADC_ADC_Ctrl_Status_ADC;
    Rte_DE_Boolean Rte_ADC_System_Status_ADC_System_Status;
    Rte_DE_Boolean Rte_ADC_System_Status_ADC_ADC_System_Status_ADC;
    Rte_DE_UInt8 Rte_ADC_TargetGearPostion_ADC_TargetGearPostion;
    Rte_DE_UInt8 Rte_ADC_TargetGearPostion_ADC_ADC_TargetGearPostion_ADC;
    Rte_DE_UInt16 Rte_ADC_Target_DrivingTorque_ADC_Target_DrivingTorque;
    Rte_DE_UInt16 Rte_ADC_Target_DrivingTorque_ADC_ADC_Target_DrivingTorque_ADC;
    Rte_DE_UInt8 Rte_ADC_Temp_ADC_Temp;
    Rte_DE_UInt8 Rte_ADC_Temp_ADC_ADC_Temp_ADC;
    Rte_DE_UInt8 Rte_BBM_FaultStatus_BBM_FaultStatus;
    Rte_DE_UInt8 Rte_BBM_WorkSts_BBM_WorkSts;
    Rte_DE_UInt8 Rte_BCM_ATWS_St_BCM_ATWS_St;
    Rte_DE_UInt8 Rte_BCM_BrakePedalSwitchInvalid_BCM_BrakePedalSwitchInvalid;
    Rte_DE_UInt8 Rte_BCM_BrakePedalSwitchStatus_BCM_BrakePedalSwitchStatus;
    Rte_DE_Boolean Rte_BCM_DrvSeatbeltBuckleInvalid_BCM_DrvSeatbeltBuckleInvalid;
    Rte_DE_Boolean Rte_BCM_DrvSeatbeltBucklestatus_BCM_DrvSeatbeltBucklestatus;
    Rte_DE_Boolean Rte_BCM_FrontLeftDoorAjarStatus_BCM_FrontLeftDoorAjarStatus;
    Rte_DE_Boolean Rte_BCM_FrontRightDoorAjarStatus_BCM_FrontRightDoorAjarStatus;
    Rte_DE_Boolean Rte_BCM_IntelligentChargeCommand_BCM_IntelligentChargeCommand;
    Rte_DE_UInt16 Rte_BCM_Odometerbackup_BCM_Odometerbackup;
    Rte_DE_UInt16 Rte_BMSH_BatCurrent_BMSH_BatCurrent;
    Rte_DE_UInt16 Rte_BMSH_BatSOE_BMSH_BatSOE;
    Rte_DE_UInt16 Rte_BMSH_BatSOH_BMSH_BatSOH;
    Rte_DE_UInt8 Rte_BMSH_BatTempMax_BMSH_BatTempMax;
    Rte_DE_UInt8 Rte_BMSH_BatTempMin_BMSH_BatTempMin;
    Rte_DE_UInt16 Rte_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
    Rte_DE_UInt8 Rte_BMSH_BattPackNum_EV_BMSH_BattPackNum_EV;
    Rte_DE_UInt8 Rte_BMSH_BattSysNum_EV_BMSH_BattSysNum_EV;
    Rte_DE_UInt8 Rte_BMSH_BattTempAvg_EV_BMSH_BattTempAvg_EV;
    Rte_DE_UInt16 Rte_BMSH_BusVolt_BMSH_BusVolt;
    Rte_DE_UInt8 Rte_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
    Rte_DE_UInt8 Rte_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
    Rte_DE_UInt8 Rte_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
    Rte_DE_UInt8 Rte_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
    Rte_DE_UInt8 Rte_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
    Rte_DE_UInt16 Rte_BMSH_CellVoltMax_BMSH_CellVoltMax;
    Rte_DE_UInt16 Rte_BMSH_CellVoltMin_BMSH_CellVoltMin;
    Rte_DE_UInt8 Rte_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
    Rte_DE_UInt8 Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
    Rte_DE_UInt8 Rte_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
    Rte_DE_Boolean Rte_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
    Rte_DE_UInt8 Rte_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
    Rte_DE_UInt8 Rte_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
    Rte_DE_UInt16 Rte_BMSH_FinishChgTime_BMSH_FinishChgTime;
    Rte_DE_UInt8 Rte_BMSH_FireAlarm_BMSH_FireAlarm;
    Rte_DE_UInt16 Rte_BMSH_PackVolt_BMSH_PackVolt;
    Rte_DE_UInt8 Rte_BMSH_StsCC2_BMSH_StsCC2;
    Rte_DE_UInt8 Rte_BMSH_StsChgFault_BMSH_StsChgFault;
    Rte_DE_UInt8 Rte_BMSH_StsDischgFault_BMSH_StsDischgFault;
    Rte_DE_UInt8 Rte_BMSH_StsInsulation_BMSH_StsInsulation;
    Rte_DE_UInt8 Rte_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
    Rte_DE_UInt8 Rte_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
    Rte_DE_UInt8 Rte_BMSH_StsMode_BMSH_StsMode;
    Rte_DE_UInt8 Rte_BMSH_StsPrecharge_BMSH_StsPrecharge;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatIsoAlarm2_EV_BMSH_TBOX_BatIsoAlarm2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatLowSOC2_EV_BMSH_TBOX_BatLowSOC2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverCharge2_EV_BMSH_TBOX_BatOverCharge2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverSOC2_EV_BMSH_TBOX_BatOverSOC2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverTemp2_EV_BMSH_TBOX_BatOverTemp2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatOverVoltage2_EV_BMSH_TBOX_BatOverVoltage2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatTempUniformity2_EV_BMSH_TBOX_BatTempUniformity2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatUnderVoltage2_EV_BMSH_TBOX_BatUnderVoltage2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_BatUniformity2_EV_BMSH_TBOX_BatUniformity2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellOverVoltage2_EV_BMSH_TBOX_CellOverVoltage2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellUnderVoltage2_EV_BMSH_TBOX_CellUnderVoltage2_EV;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
    Rte_DE_UInt16 Rte_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
    Rte_DE_UInt8 Rte_BMSH_TBOX_FireAlarm_EV_BMSH_TBOX_FireAlarm_EV;
    Rte_DE_UInt16 Rte_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
    Rte_DE_UInt8 Rte_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
    Rte_DE_UInt8 Rte_BMSH_TBOX_SOCHop2_EV_BMSH_TBOX_SOCHop2_EV;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
    Rte_DE_UInt8 Rte_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
    Rte_DE_Boolean Rte_BMSH_VCU_Crash_BMSH_VCU_Crash;
    Rte_DE_Boolean Rte_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
    Rte_DE_UInt8 Rte_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
    Rte_DE_UInt8 Rte_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
    Rte_DE_UInt8 Rte_BMS_BattPackMatchFault_EV_BMS_BattPackMatchFault_EV;
    Rte_DE_UInt8 Rte_BMS_ChgCCSts_BMS_ChgCCSts;
    Rte_DE_UInt8 Rte_BMS_ChgStatus_BMS_ChgStatus;
    Rte_DE_UInt8 Rte_BMS_DelayDataUpldEnb_EV_BMS_DelayDataUpldEnb_EV;
    Rte_DE_Boolean Rte_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
    Rte_DE_Boolean Rte_CSM_CampModeSwt_CSM_CampModeSwt;
    Rte_DE_Boolean Rte_CSM_CampModeSwtInvalid_CSM_CampModeSwtInvalid;
    Rte_DE_Boolean Rte_CSM_DriveModeReq_CSM_DriveModeReq;
    Rte_DE_Boolean Rte_CSM_DriveModeReqInvalid_CSM_DriveModeReqInvalid;
    Rte_DE_Boolean Rte_CSM_EngRec_Req_CSM_EngRec_Req;
    Rte_DE_UInt8 Rte_CSM_EngRec_ReqInvalid_CSM_EngRec_ReqInvalid;
    Rte_DE_Boolean Rte_CSM_TakeEleSwt_CSM_TakeEleSwt;
    Rte_DE_Boolean Rte_CSM_TakeEleSwt_ReqInvalid_CSM_TakeEleSwt_ReqInvalid;
    Rte_DE_Boolean Rte_CSM_V2XDchaSwt_CSM_V2XDchaSwt;
    Rte_DE_Boolean Rte_CSM_V2XDchaSwtInvalid_CSM_V2XDchaSwtInvalid;
    Rte_DE_UInt8 Rte_DCDC_AccessoryConnStsFb_EV_DCDC_AccessoryConnStsFb_EV;
    Rte_DE_Boolean Rte_DCDC_CANComFault_DCDC_CANComFault;
    Rte_DE_UInt8 Rte_DCDC_CutOffLVFb_DCDC_CutOffLVFb;
    Rte_DE_UInt8 Rte_DCDC_FaultLevel1_DCDC_FaultLevel1;
    Rte_DE_UInt8 Rte_DCDC_IDCDCActHiside1_DCDC_IDCDCActHiside1;
    Rte_DE_UInt8 Rte_DCDC_IDcDcActLoSide_DCDC_IDcDcActLoSide;
    Rte_DE_Boolean Rte_DCDC_OutOverCurr_DCDC_OutOverCurr;
    Rte_DE_Boolean Rte_DCDC_OutOverVolt_DCDC_OutOverVolt;
    Rte_DE_UInt8 Rte_DCDC_PTCConnStsFb_EV_DCDC_PTCConnStsFb_EV;
    Rte_DE_UInt16 Rte_DCDC_Relay_Volt_DCDC_Relay_Volt;
    Rte_DE_UInt8 Rte_DCDC_SelfChkSts_DCDC_SelfChkSts;
    Rte_DE_UInt8 Rte_DCDC_TDcDc_DCDC_TDcDc;
    Rte_DE_UInt16 Rte_DCDC_UDCDCActHiside_DCDC_UDCDCActHiside;
    Rte_DE_UInt8 Rte_DCDC_UDcDcActLoSide_DCDC_UDcDcActLoSide;
    Rte_DE_Boolean Rte_DcDcActvd_DcDcActvd;
    Rte_DE_Boolean Rte_DcDcStsAlm_DcDcStsAlm;
    Rte_DE_UInt32 Rte_ECU_Fun_Config_Data1_ECU_Fun_Config_Data1;
    Rte_DE_UInt32 Rte_ECU_Fun_Config_Data2_ECU_Fun_Config_Data2;
    Rte_DE_UInt32 Rte_ECU_Net_Config_Data1_ECU_Net_Config_Data1;
    Rte_DE_UInt32 Rte_ECU_Net_Config_Data2_ECU_Net_Config_Data2;
    Rte_DE_UInt8 Rte_EGSM_LeverPosition_EGSM_LeverPosition;
    Rte_DE_UInt8 Rte_EGSM_ParkReq_EGSM_ParkReq;
    Rte_DE_UInt8 Rte_EGSM_ShiftleverFailSt_EGSM_ShiftleverFailSt;
    Rte_DE_Boolean Rte_EHB_ABSActive_EHB_ABSActive;
    Rte_DE_Boolean Rte_EHB_ABSFailed_EHB_ABSFailed;
    Rte_DE_Boolean Rte_EHB_AEB_active_EHB_AEB_active;
    Rte_DE_UInt8 Rte_EHB_AVHStatus_EHB_AVHStatus;
    Rte_DE_UInt8 Rte_EHB_BrkSysErrFault_EHB_BrkSysErrFault;
    Rte_DE_Boolean Rte_EHB_DTC_Active_EHB_DTC_Active;
    Rte_DE_Boolean Rte_EHB_EPBErrorStatus_EHB_EPBErrorStatus;
    Rte_DE_UInt8 Rte_EHB_EPBStatus_EHB_EPBStatus;
    Rte_DE_UInt8 Rte_EHB_EPB_DynamicApplystatus_EHB_EPB_DynamicApplystatus;
    Rte_DE_UInt16 Rte_EHB_FLWheelSpeedKPH_EHB_FLWheelSpeedKPH;
    Rte_DE_UInt16 Rte_EHB_FRWheelSpeedKPH_EHB_FRWheelSpeedKPH;
    Rte_DE_Boolean Rte_EHB_HHCActive_EHB_HHCActive;
    Rte_DE_UInt16 Rte_EHB_ISA_PTTrqDecReq_EHB_ISA_PTTrqDecReq;
    Rte_DE_Boolean Rte_EHB_ISA_PTTrqDecReqActive_EHB_ISA_PTTrqDecReqActive;
    Rte_DE_UInt8 Rte_EHB_ISA_Status_EHB_ISA_Status;
    Rte_DE_UInt16 Rte_EHB_MbRegenTargetWheel_EHB_MbRegenTargetWheel;
    Rte_DE_UInt8 Rte_EHB_MbRegenTargetWheelSts_EHB_MbRegenTargetWheelSts;
    Rte_DE_UInt16 Rte_EHB_PTTrqDecReq_EHB_PTTrqDecReq;
    Rte_DE_Boolean Rte_EHB_PTTrqDecReqActive_EHB_PTTrqDecReqActive;
    Rte_DE_UInt16 Rte_EHB_PTTrqIncReq_EHB_PTTrqIncReq;
    Rte_DE_Boolean Rte_EHB_PTTrqIncReqActive_EHB_PTTrqIncReqActive;
    Rte_DE_UInt16 Rte_EHB_RLWheelSpeedKPH_EHB_RLWheelSpeedKPH;
    Rte_DE_UInt16 Rte_EHB_RRWheelSpeedKPH_EHB_RRWheelSpeedKPH;
    Rte_DE_Boolean Rte_EHB_VLC_Active_EHB_VLC_Active;
    Rte_DE_Boolean Rte_EHB_VLC_Available_EHB_VLC_Available;
    Rte_DE_Boolean Rte_EHB_VLC_CDD_active_EHB_VLC_CDD_active;
    Rte_DE_UInt16 Rte_EHB_VLC_PTTrqReq_EHB_VLC_PTTrqReq;
    Rte_DE_Boolean Rte_EHB_VLC_PTTrqReqActive_EHB_VLC_PTTrqReqActive;
    Rte_DE_UInt16 Rte_EHB_VehicleSpeed_EHB_VehicleSpeed;
    Rte_DE_Boolean Rte_EHB_VehicleSpeedInvalid_EHB_VehicleSpeedInvalid;
    Rte_DE_UInt8 Rte_EPS_EpasFailed_EPS_EpasFailed;
    Rte_DE_SInt16 Rte_EPS_SteerWheelAngle_EPS_SteerWheelAngle;
    Rte_DE_Boolean Rte_EWP_HeatPower_EWP_HeatPower;
    Rte_DE_Boolean Rte_EWP_OutputTemp_EWP_OutputTemp;
    Rte_DE_Float Rte_EXT_AI_BATTERY_TEMPH_5_EXT_AI_BATTERY_TEMPH_5;
    Rte_DE_Float Rte_EXT_AI_BATTERY_TEMPH_6_EXT_AI_BATTERY_TEMPH_6;
    Rte_DE_Float Rte_EXT_AI_MID_COOLING_TEMPH_8_EXT_AI_MID_COOLING_TEMPH_8;
    Rte_DE_Float Rte_EXT_AI_SENSOR_1_EXT_AI_SENSOR_1;
    Rte_DE_Float Rte_EXT_AI_SENSOR_2_EXT_AI_SENSOR_2;
    Rte_DE_Float Rte_EXT_AI_SENSOR_6_EXT_AI_SENSOR_6;
    Rte_DE_Float Rte_EXT_AI_SWITCH_1_EXT_AI_SWITCH_1;
    Rte_DE_UInt16 Rte_EXT_AO_LDO_5V_02_EXT_AO_LDO_5V_02;
    Rte_DE_Float Rte_EXT_AO_TRACKING_5V_01_EXT_AO_TRACKING_5V_01;
    Rte_DE_Float Rte_EXT_AO_TRACKING_5V_02_EXT_AO_TRACKING_5V_02;
    Rte_DE_Float Rte_EXT_CHARGE_ON_AI_EXT_CHARGE_ON_AI;
    Rte_DE_Boolean Rte_EXT_DI_HS_04_EXT_DI_HS_04;
    Rte_DE_Boolean Rte_EXT_DI_HS_05_EXT_DI_HS_05;
    Rte_DE_Boolean Rte_EXT_DI_HS_06_EXT_DI_HS_06;
    Rte_DE_Boolean Rte_EXT_DI_HS_07_EXT_DI_HS_07;
    Rte_DE_Boolean Rte_EXT_DI_HS_08_EXT_DI_HS_08;
    Rte_DE_Boolean Rte_EXT_DI_HS_10_EXT_DI_HS_10;
    Rte_DE_UInt16 Rte_EXT_IGN_ON_AI_EXT_IGN_ON_AI;
    Rte_DE_Boolean Rte_EXT_IGN_ON_DI_EXT_IGN_ON_DI;
    Rte_DE_Float Rte_EXT_PI_HVIL_1_DutyCycle_EXT_PI_HVIL_1_DutyCycle;
    Rte_DE_Float Rte_EXT_PI_HVIL_1_Period_EXT_PI_HVIL_1_Period;
    Rte_DE_Float Rte_EXT_PI_HVIL_2_DutyCycle_EXT_PI_HVIL_2_DutyCycle;
    Rte_DE_Float Rte_EXT_PI_HVIL_2_Period_EXT_PI_HVIL_2_Period;
    Rte_DE_Float Rte_EXT_PI_PWM_1_DutyCycle_EXT_PI_PWM_1_DutyCycle;
    Rte_DE_Float Rte_EXT_PI_PWM_2_DutyCycle_EXT_PI_PWM_2_DutyCycle;
    Rte_DE_Float Rte_EXT_PI_PWM_4_DutyCycle_EXT_PI_PWM_4_DutyCycle;
    Rte_DE_Boolean Rte_FWFV_CCWFlg_FWFV_CCWFlg;
    Rte_DE_UInt8 Rte_FWFV_CurrentPos_FWFV_CurrentPos;
    Rte_DE_Boolean Rte_FWFV_InitState_FWFV_InitState;
    Rte_DE_Boolean Rte_FWFV_MotorState_FWFV_MotorState;
    Rte_DE_Boolean Rte_FWFV_OverCurrentFlt_FWFV_OverCurrentFlt;
    Rte_DE_Boolean Rte_FWFV_OverTempFlt_FWFV_OverTempFlt;
    Rte_DE_Boolean Rte_FWFV_OverVoltageFlt_FWFV_OverVoltageFlt;
    Rte_DE_Boolean Rte_FWFV_RESP_ERROR_FWFV_RESP_ERROR;
    Rte_DE_Boolean Rte_FWFV_UnderVoltageFlt_FWFV_UnderVoltageFlt;
    Rte_DE_UInt16 Rte_HCM_AcceRelayVolt_HCM_AcceRelayVolt;
    Rte_DE_Boolean Rte_HCM_AcceRelayVoltValidStat_HCM_AcceRelayVoltValidStat;
    Rte_DE_UInt8 Rte_HCM_AccessoryConnStsFb_HCM_AccessoryConnStsFb;
    Rte_DE_UInt8 Rte_HCM_LockLoopSts_HCM_LockLoopSts;
    Rte_DE_UInt16 Rte_HCM_MainPosBackVolt_HCM_MainPosBackVolt;
    Rte_DE_Boolean Rte_HCM_MainPosBackVoltValidStat_HCM_MainPosBackVoltValidStat;
    Rte_DE_UInt8 Rte_HCM_PTC1ConnStsFb_HCM_PTC1ConnStsFb;
    Rte_DE_UInt8 Rte_HCM_PTCConnStsFb_HCM_PTCConnStsFb;
    Rte_DE_UInt16 Rte_HCM_PTCRelayVolt_HCM_PTCRelayVolt;
    Rte_DE_Boolean Rte_HCM_PTCRelayVoltValidStat_HCM_PTCRelayVoltValidStat;
    Rte_DE_Boolean Rte_IPK_AllowChgSoftSwCtrlSt_IPK_AllowChgSoftSwCtrlSt;
    Rte_DE_Boolean Rte_IPK_ChrgSoftSwCtrlSt_IPK_ChrgSoftSwCtrlSt;
    Rte_DE_UInt8 Rte_IPK_CruisingDstSwt_IPK_CruisingDstSwt;
    Rte_DE_UInt8 Rte_IPK_EngRecMode_Req_IPK_EngRecMode_Req;
    Rte_DE_UInt32 Rte_IPK_IPKTotalOdometer_PT_IPK_IPKTotalOdometer_PT;
    Rte_DE_UInt16 Rte_IPK_Odometerbackup_IPK_Odometerbackup;
    Rte_DE_UInt8 Rte_IPK_OdometerbackupEnable_IPK_OdometerbackupEnable;
    Rte_DE_Boolean Rte_IPU_CANCommFlt_IPU_CANCommFlt;
    Rte_DE_UInt8 Rte_IPU_DisChgFault_IPU_DisChgFault;
    Rte_DE_UInt8 Rte_IPU_DischgState_IPU_DischgState;
    Rte_DE_UInt16 Rte_IPU_HVBusCur_EV_IPU_HVBusCur_EV;
    Rte_DE_UInt16 Rte_IPU_HVBusVolt_EV_IPU_HVBusVolt_EV;
    Rte_DE_UInt16 Rte_IPU_HVBusVolt_IPUSts_IPU_HVBusVolt_IPUSts;
    Rte_DE_Boolean Rte_IPU_IGBTFlt_IPU_IGBTFlt;
    Rte_DE_UInt8 Rte_IPU_IsgInvrT_IPU_IsgInvrT;
    Rte_DE_UInt8 Rte_IPU_IsgModSts_IPU_IsgModSts;
    Rte_DE_UInt8 Rte_IPU_IsgMotT_IPU_IsgMotT;
    Rte_DE_UInt16 Rte_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn;
    Rte_DE_Boolean Rte_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid;
    Rte_DE_UInt16 Rte_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct;
    Rte_DE_UInt8 Rte_IPU_MCUEnableSts_IPU_MCUEnableSts;
    Rte_DE_Boolean Rte_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt;
    Rte_DE_Boolean Rte_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm;
    Rte_DE_UInt8 Rte_IPU_MCUTempHighAlarm1_EV_IPU_MCUTempHighAlarm1_EV;
    Rte_DE_UInt8 Rte_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr;
    Rte_DE_UInt8 Rte_IPU_MotorFltLevell1_IPU_MotorFltLevell1;
    Rte_DE_Boolean Rte_IPU_MotorLockRotErr_IPU_MotorLockRotErr;
    Rte_DE_UInt8 Rte_IPU_MotorOverCurrFlt_EV_IPU_MotorOverCurrFlt_EV;
    Rte_DE_UInt8 Rte_IPU_MotorOverSpdFlt_EV_IPU_MotorOverSpdFlt_EV;
    Rte_DE_Boolean Rte_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm;
    Rte_DE_UInt8 Rte_IPU_MotorSubFltLevell_IPU_MotorSubFltLevell;
    Rte_DE_Boolean Rte_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm;
    Rte_DE_Boolean Rte_IPU_MotorTempHighFault_IPU_MotorTempHighFault;
    Rte_DE_UInt8 Rte_IPU_MotorTempHighFault1_EV_IPU_MotorTempHighFault1_EV;
    Rte_DE_UInt8 Rte_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr;
    Rte_DE_Boolean Rte_IPU_RotateInverterFlt_IPU_RotateInverterFlt;
    Rte_DE_UInt8 Rte_IPU_SelfChkSts_IPU_SelfChkSts;
    Rte_DE_UInt16 Rte_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax;
    Rte_DE_UInt16 Rte_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin;
    Rte_DE_Float Rte_I_A_PIN31_I_A_PIN31;
    Rte_DE_Boolean Rte_I_S_PIN25_I_S_PIN25;
    Rte_DE_Boolean Rte_I_S_PIN38_I_S_PIN38;
    Rte_DE_Boolean Rte_I_S_PIN84_I_S_PIN84;
    Rte_DE_Float Rte_KL30_KL30;
    Rte_DE_Boolean Rte_MHGV_CCWFlg_MHGV_CCWFlg;
    Rte_DE_UInt8 Rte_MHGV_CurrentPos_MHGV_CurrentPos;
    Rte_DE_Boolean Rte_MHGV_InitState_MHGV_InitState;
    Rte_DE_Boolean Rte_MHGV_MotorState_MHGV_MotorState;
    Rte_DE_Boolean Rte_MHGV_OverCurrentFlt_MHGV_OverCurrentFlt;
    Rte_DE_Boolean Rte_MHGV_OverTempFlt_MHGV_OverTempFlt;
    Rte_DE_Boolean Rte_MHGV_OverVoltageFlt_MHGV_OverVoltageFlt;
    Rte_DE_Boolean Rte_MHGV_RESP_ERROR_MHGV_RESP_ERROR;
    Rte_DE_Boolean Rte_MHGV_UnderVoltageFlt_MHGV_UnderVoltageFlt;
    Rte_DE_UInt16 Rte_MMI_LocalBookChrgnTarVal_MMI_LocalBookChrgnTarVal;
    Rte_DE_UInt8 Rte_MMI_RestSwitch_MMI_RestSwitch;
    Rte_DE_UInt8 Rte_OBC_ChgCCSts_OBC_ChgCCSts;
    Rte_DE_UInt8 Rte_OBC_ChrgrSt_OBC_ChrgrSt;
    Rte_DE_UInt8 Rte_OBC_Elock_Stmode_OBC_Elock_Stmode;
    Rte_DE_UInt8 Rte_OBC_LockLoopSts_OBC_LockLoopSts;
    Rte_DE_UInt8 Rte_OBC_OnBdCCline_OBC_OnBdCCline;
    Rte_DE_UInt8 Rte_OBC_OnBdCPline_OBC_OnBdCPline;
    Rte_DE_UInt8 Rte_OBC_OnBdChrgrT_OBC_OnBdChrgrT;
    Rte_DE_UInt8 Rte_OBC_OnBdDisChrgrCCline_OBC_OnBdDisChrgrCCline;
    Rte_DE_UInt16 Rte_OBC_OnBdOuptI_OBC_OnBdOuptI;
    Rte_DE_UInt16 Rte_OBC_OnBdOuptU_OBC_OnBdOuptU;
    Rte_DE_UInt16 Rte_OBC_PwrEgyMgrAvl_OBC_PwrEgyMgrAvl;
    Rte_DE_UInt8 Rte_OBC_SelfCheSts_OBC_SelfCheSts;
    Rte_DE_Boolean Rte_ODP_DCDC_TDcDcAlm_ODP_DCDC_TDcDcAlm;
    Rte_DE_Boolean Rte_PDCStatus_AlvCtrErrFlg_PDCStatus_AlvCtrErrFlg;
    Rte_DE_Boolean Rte_PDC_Brake_Flag_PDC_Brake_Flag;
    Rte_DE_Boolean Rte_PDC_Status_CsmErrFlg_PDC_Status_CsmErrFlg;
    Rte_DE_UInt8 Rte_PEPS_PowerMode_PEPS_PowerMode;
    Rte_DE_UInt8 Rte_PEPS_PowerModeValidity_PEPS_PowerModeValidity;
    Rte_DE_UInt8 Rte_PEPS_RKECommand_PEPS_RKECommand;
    Rte_DE_Boolean Rte_PEPS_RemoteControlSt_PEPS_RemoteControlSt;
    Rte_DE_Boolean Rte_PMS_CANBusOff_flg_PMS_CANBusOff_flg;
    Rte_DE_UInt8 Rte_RFR_ConnectionStatus_RFR_ConnectionStatus;
    Rte_DE_UInt32 Rte_RFR_Seed_RFR_Seed;
    Rte_DE_UInt32 Rte_RFR_SwapBatCode_RFR_SwapBatCode;
    Rte_DE_Boolean Rte_Station_CarLocationConfirm_Station_CarLocationConfirm;
    Rte_DE_Boolean Rte_Station_CarStation_Station_CarStation;
    Rte_DE_Boolean Rte_Station_SwapBatRequest_Station_SwapBatRequest;
    Rte_DE_UInt8 Rte_Station_Swapingproceeding_Station_Swapingproceeding;
    Rte_DE_UInt8 Rte_TBOX_AllowChgCurrentMax_TBOX_AllowChgCurrentMax;
    Rte_DE_UInt8 Rte_TBOX_ChargeDepth_TBOX_ChargeDepth;
    Rte_DE_UInt8 Rte_TBOX_ChargeLimitSwitch_TBOX_ChargeLimitSwitch;
    Rte_DE_UInt8 Rte_TBOX_ChrgSoftSwCtrlSt_TBOX_ChrgSoftSwCtrlSt;
    Rte_DE_UInt8 Rte_TBOX_Day_TBOX_Day;
    Rte_DE_UInt16 Rte_TBOX_Elevation_TBOX_Elevation;
    Rte_DE_UInt8 Rte_TBOX_FunAnti_DismantleActive_TBOX_FunAnti_DismantleActive;
    Rte_DE_UInt8 Rte_TBOX_FunLockVehActive_TBOX_FunLockVehActive;
    Rte_DE_UInt8 Rte_TBOX_Hour_TBOX_Hour;
    Rte_DE_UInt8 Rte_TBOX_InventorySpdLmtReq_TBOX_InventorySpdLmtReq;
    Rte_DE_UInt8 Rte_TBOX_Life_TBOX_Life;
    Rte_DE_UInt8 Rte_TBOX_LockLimSet_TBOX_LockLimSet;
    Rte_DE_UInt8 Rte_TBOX_LockResultResp_TBOX_LockResultResp;
    Rte_DE_UInt8 Rte_TBOX_LockVehCtrl_TBOX_LockVehCtrl;
    Rte_DE_UInt8 Rte_TBOX_LockVehPerFlag_TBOX_LockVehPerFlag;
    Rte_DE_UInt8 Rte_TBOX_LockVehType_TBOX_LockVehType;
    Rte_DE_UInt8 Rte_TBOX_Minute_TBOX_Minute;
    Rte_DE_UInt8 Rte_TBOX_Month_TBOX_Month;
    Rte_DE_Boolean Rte_TBOX_PowerOffCmd_TBOX_PowerOffCmd;
    Rte_DE_UInt8 Rte_TBOX_PriorityFullSwitchSts_TBOX_PriorityFullSwitchSts;
    Rte_DE_Boolean Rte_TBOX_PriorityFullSwitchSts_UB_TBOX_PriorityFullSwitchSts_UB;
    Rte_DE_UInt8 Rte_TBOX_ReservationChrgnSts_TBOX_ReservationChrgnSts;
    Rte_DE_UInt8 Rte_TBOX_Second_TBOX_Second;
    Rte_DE_UInt8 Rte_TBOX_SpdLmtLevelReq_TBOX_SpdLmtLevelReq;
    Rte_DE_UInt8 Rte_TBOX_VersionConversionFlag_TBOX_VersionConversionFlag;
    Rte_DE_UInt8 Rte_TBOX_Year_TBOX_Year;
    Rte_DE_UInt16 Rte_YRS_LongitAcce_YRS_LongitAcce;
    Rte_DE_Boolean Rte_s2vd_BMS_PmtCutoffLVFb_s2vd_BMS_PmtCutoffLVFb;
    Rte_DE_Boolean Rte_vcib_VCIP_accd_b_acHvilOpn;
    Rte_DE_Boolean Rte_vcib_VCIP_accd_b_acHvilOpnInvld;
    Rte_DE_McuSts Rte_vcib_VCIP_accd_e_PtcSt;
    Rte_DE_FaultStatus Rte_vcib_VCIP_accd_e_acFltLvl;
    Rte_DE_McuSts Rte_vcib_VCIP_accd_e_airCmprSt;
    Rte_DE_Float Rte_vcib_VCIP_accd_n_acFanReqSpd_pct;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_AcWrk;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_acSubFltSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_airCmprSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_cbnThermMngReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_iptWorkSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_accd_st_ptcWorkStRear;
    Rte_DE_Float Rte_vcib_VCIP_accd_t_ambTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_accd_u_acPresVolt_V;
    Rte_DE_Boolean Rte_vcib_VCIP_acpd_b_accPedlPosVld;
    Rte_DE_Float Rte_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V;
    Rte_DE_Float Rte_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPos_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adc1CtrlTorqEn;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adc1SwtchCtrlReq;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adcCtrlGearEn;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_adcTgtGearPostn;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta;
    Rte_DE_Float Rte_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_DryAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_ResrAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brakeSwitch1Closed;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brakeSwitch2Closed;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPedlPosVld;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPedlStsVld;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPmpSelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPumpFault;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_vacTankLowPrs;
    Rte_DE_McuSts Rte_vcib_VCIP_brpd_e_bdcacWrk;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_Float Rte_vcib_VCIP_brpd_p_AirPres_kpa;
    Rte_DE_Float Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar;
    Rte_DE_UInt8 Rte_vcib_VCIP_brpd_st_bdcacWrk;
    Rte_DE_Float Rte_vcib_VCIP_brpd_x_brkPedlPos_pct;
    Rte_DE_Float Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_EmergencyStop;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_acuCrash;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_crash;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcHvilFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcSelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk;
    Rte_DE_McuSts Rte_vcib_VCIP_dccd_e_24vDcdcModAct;
    Rte_DE_FaultStatus Rte_vcib_VCIP_dccd_e_dcdcFaultStatus;
    Rte_DE_DCDCMode Rte_vcib_VCIP_dccd_e_modeAct;
    Rte_DE_Float Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW;
    Rte_DE_UInt8 Rte_vcib_VCIP_dccd_st_12vDcdcModAct;
    Rte_DE_UInt8 Rte_vcib_VCIP_dccd_st_24vDcdcFltSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_dccd_st_24vDcdcModAct;
    Rte_DE_UInt8 Rte_vcib_VCIP_dccd_st_24vDcdcSubFltSts;
    Rte_DE_Float Rte_vcib_VCIP_dccd_t_dcdcTemp_C;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReq;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReq4WD;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqECO;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqEV;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqHEV;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqSPORT;
    Rte_DE_UInt8 Rte_vcib_VCIP_drid_b_parkBtnPressed;
    Rte_DE_GearLeverPos Rte_vcib_VCIP_drid_e_gearLvrPosRaw;
    Rte_DE_UInt8 Rte_vcib_VCIP_drid_st_gearLvrPosSeql;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2SelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk;
    Rte_DE_McuSts Rte_vcib_VCIP_eadd_e_eadInv2Sts;
    Rte_DE_FaultStatus Rte_vcib_VCIP_eadd_e_inv21FltSts;
    Rte_DE_FaultStatus Rte_vcib_VCIP_eadd_e_inv2FltSts;
    Rte_DE_ElMac Rte_vcib_VCIP_eadd_e_inv2ModeAct;
    Rte_DE_Float Rte_vcib_VCIP_eadd_fact_mot2GearRat;
    Rte_DE_Float Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_pwr_mot21ActPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW;
    Rte_DE_UInt8 Rte_vcib_VCIP_eadd_st_eadInv2PwrActvMod;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_st_eadInv2Sts;
    Rte_DE_UInt8 Rte_vcib_VCIP_eadd_st_eadInv2WrkMod;
    Rte_DE_UInt8 Rte_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk;
    Rte_DE_UInt8 Rte_vcib_VCIP_eadd_st_inv2SubFltSts;
    Rte_DE_Float Rte_vcib_VCIP_eadd_t_inv2Temp_C;
    Rte_DE_Float Rte_vcib_VCIP_eadd_t_mot2Temp_C;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_u_busInv2HVAct_V;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_epbd_e_parkingSts;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_bmsSelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmSelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbHeatEnad;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvilOpen;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_lowTempProtnReq;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_obcChrgReq;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg;
    Rte_DE_McuSts Rte_vcib_VCIP_hvbd_e_hcmWrkSt;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbAssiRly;
    Rte_DE_FaultStatus Rte_vcib_VCIP_hvbd_e_hvbFaultStatus;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
    Rte_DE_HVBRelayStatus Rte_vcib_VCIP_hvbd_e_hvbMainRlySts;
    Rte_DE_HVBattStatus Rte_vcib_VCIP_hvbd_e_hvbStatus;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_i_hvbCurr_A;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_hvbAct_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_q_hvbSOC_pct;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hcmFltLvl;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hcmPwrActvMod;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvbPwrActvMod;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvbSubFaultSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvbThermMngReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvilOpenSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbAvg_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbMin_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_macd_V_tankFuelLvl_l;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_epsSelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_epsSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_pullUpDiagCmpl;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_vcuSelfChkOk;
    Rte_DE_McuSts Rte_vcib_VCIP_macd_e_sdcacWrk;
    Rte_DE_Float Rte_vcib_VCIP_macd_p_frontAirTankPres_bar;
    Rte_DE_Float Rte_vcib_VCIP_macd_p_rearAirTankPres_bar;
    Rte_DE_UInt8 Rte_vcib_VCIP_macd_st_epsErrorCode;
    Rte_DE_UInt8 Rte_vcib_VCIP_macd_st_epsFltLvl;
    Rte_DE_UInt8 Rte_vcib_VCIP_macd_st_epsSubFltLvl;
    Rte_DE_UInt8 Rte_vcib_VCIP_macd_st_sdcacWrk;
    Rte_DE_Float Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_macd_u_batIntSmpl_V;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcCANMsgValid;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcSelfChkErr;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcSelfChkOk;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcWakeUp;
    Rte_DE_Float Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW;
    Rte_DE_Float Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW;
    Rte_DE_UInt8 Rte_vcib_VCIP_obcd_st_obcfltLvl;
    Rte_DE_Float Rte_vcib_VCIP_obcd_t_obcTemp_C;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_anyIgnOn;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_canIgnOn;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_driverStartReq;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_hwIgnOn;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignStsStrt;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_pepsPduLvlValid;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy;
    Rte_DE_KeyAuthStatus Rte_vcib_VCIP_pmmd_e_authenticationStatus;
    Rte_DE_Boolean Rte_vcib_VCIP_trad_b_trsm2GearActVld;
    Rte_DE_Boolean Rte_vcib_VCIP_trad_b_trsm2GearshiftActv;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_trad_e_trsm1PrkgSts;
    Rte_DE_GearShiftResp Rte_vcib_VCIP_trad_e_trsm2GearShftResp;
    Rte_DE_Float Rte_vcib_VCIP_trad_fact_trsm2FinalDrvRat;
    Rte_DE_Float Rte_vcib_VCIP_trad_fact_trsm2GbxGearRat;
    Rte_DE_Float Rte_vcib_VCIP_trad_fact_trsm2GearRat;
    Rte_DE_SInt8 Rte_vcib_VCIP_trad_st_trsm2GearAct;
    Rte_DE_Float Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
    Rte_DE_Float Rte_vcib_VCIP_vild_R_posInsIRes_Ohm;
    Rte_DE_Float Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
    Rte_DE_Float Rte_vcib_VCIP_vild_ang_strWhlAng_rad;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_AccyEnReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_AccyFltSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_CCSginal;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_DryAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ResrAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_adc1ComErrFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_adcComErrFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_brkSwt1Actv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_brkSwt2Actv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_calCanBusOff;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmCampModeSwt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmEngRecSwtReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmTakeEleSwt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmV2XDchaSw;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_dcdcStsAlm;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_dcdcTempAlm;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_disChgSwtSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_driverEcoModeReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ehbVlcCddActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_emgyStopIn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_epbErrSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgBBMMsgErr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgACU;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgAirBag;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgBatCol;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDualAuthN;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgEpdel;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgMotor;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgTyre;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFnctnConfgEHB;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgNetConfgABS;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvCcwFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvInitSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvMotSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvRespErr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hvbDisChgSopRngUp;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hvbHvilFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_b_hvbInPositionDetct1;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_b_hvbInPositionDetct2;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hvbZeroPwrReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ignStsOn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ignStsStrt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvCcwFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvInitSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvMotSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvRespErr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_obcWakeUpActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_odometerInvalid;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_pepsOnSwtSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_pepsPduLvlVld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ptCanBusOff;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_pullUpDiagCmpl;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_rfrSwapBatReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_rstAvgPwrConsumption;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_tboxPowOffCmd;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_bcmOdometerbackup;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_ipkOdometerbackup;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_odometer_km;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_dcdcInpCurr_A;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_hvbCurr_A;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A;
    Rte_DE_Float Rte_vcib_VCIP_vild_l_whlRad_m;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbCellMaxID;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbCellMinID;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_num_hvbCellSum;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbMaxTempID;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbMinTempID;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbTempSum;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_GearPosn;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_HVILReturnPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_fan1Fb;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_fan2Fb;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_fwfvCrtPos;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_mhgvCrtPos;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_tboxChgDepth;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_airCmprAct_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_iptActPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_24vDcdcModAct;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXFunLockVehActive;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockLimSet;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockResultResp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockVehCtrl;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_TBOXLockVehType;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_actWorkSts1;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batLowSoc2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batOvrSoc2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batOvrVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batUdrVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bbmFltSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bbmWorkSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsBattPackNum;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsBattSysNum;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsTboxFireAlm;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_cellOverVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_cellUdrVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_csmEngRecReqInvalid;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_csmRgnLvlSet;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_dcChgCcSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_dccAccyConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_eadInv2FltSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ehbIsaSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_epsEpasFail;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgAccy;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgBatTyp;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgFan;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgSlowChg;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgV2L;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehUsg;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmAccConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmHvilSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmPTC1ConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbBatUniformity;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbBattIsolationSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgCcsts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgFltReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgOvrCurr;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgProcss;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDischgFltReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbInslErr;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbOvrChgFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbPreChgSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbSocFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbSocJumpFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStatus;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStsChgFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStsDischgFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbTempFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbThermMngReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipkCruisingDstSwt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_mmiRestSwitch;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcChgCCSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcChgSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcElckStMod;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdCCline;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_pepsPduLvl;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_pepsPduLvlVld;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_pepsRKECom;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ptcConnStsFb;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_rfrConnctSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_rfrSwapprocd;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxChgLmtSw;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxInventorySpdLmtReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxLife;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxLockVehPerFlag;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxRsrChgSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxSpdLmtLevelReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxStartBattChgReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxVersionConversionFlag;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_vscEHBAVHSts;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_TS5sensorFb_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_acwpOutptTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbMax_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbMin_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m;
    Rte_DE_Float Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Acc1Raw_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Acc2Raw_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Brk2Raw_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Brk2_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_BrkRaw_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Brk_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_TS5sensorFb_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_VacTkAirPres_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_VacTkEnFb_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_brkVacuumPres_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_eLpWpCtrlCur_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbPackVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_pepsOn_mV;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_u_vacTkPowSup_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_v_ehbVehSpd_kph;
    Rte_DE_Float Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActvRaw;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbAebActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbDtcActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbVlcActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbVlcAvailb;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_pdcBrkFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSlipWarn;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vscBrkLghtActv;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbAVHSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbHHCActive;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_DIAG_acpd_b_accPed1Vld;
    Rte_DE_Boolean Rte_vcsb_DIAG_acpd_b_accPed2Vld;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
    Rte_DE_Boolean Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
    Rte_DE_DCDCMode Rte_vcsb_HVSM_dccd_e_modeTgt;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_GearLeverPos Rte_vcsb_VOMM_drid_e_gearLvrPos;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
    Rte_DE_Boolean Rte_vild_b_flgBBMMsgErr_vild_b_flgBBMMsgErr;
    Rte_DE_Boolean Rte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
    Rte_DE_Boolean Rte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
    Rte_DE_Boolean Rte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
}Rte_tsRB_swc_VCIP_swc_VCIP_Step;

typedef struct
{
    Rte_DE_UInt8 Rte_AC_EWP_Heat_AC_EWP_Heat;
    Rte_DE_UInt8 Rte_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN;
    Rte_DE_UInt8 Rte_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd;
    Rte_DE_UInt8 Rte_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN;
    Rte_DE_UInt8 Rte_AC_EWP_Run_AC_EWP_Run;
    Rte_DE_UInt8 Rte_AC_EWP_Run_LIN_AC_EWP_Run_LIN;
    Rte_DE_UInt8 Rte_AC_EWP_SpeedReq_AC_EWP_SpeedReq;
    Rte_DE_UInt8 Rte_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN;
    Rte_DE_UInt8 Rte_AC_EWP_Temp_AC_EWP_Temp;
    Rte_DE_UInt8 Rte_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN;
    Rte_DE_UInt16 Rte_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain;
    Rte_DE_UInt16 Rte_BMSH_BattCurr_BMSH_BattCurr;
    Rte_DE_UInt8 Rte_BMSH_BattFaultLampState_BMSH_BattFaultLampState;
    Rte_DE_Double Rte_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS;
    Rte_DE_UInt16 Rte_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy;
    Rte_DE_UInt16 Rte_BMSH_BattSOC_BMSH_BattSOC;
    Rte_DE_UInt8 Rte_BMSH_BattSOH_BMSH_BattSOH;
    Rte_DE_Double Rte_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS;
    Rte_DE_UInt8 Rte_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT;
    Rte_DE_UInt16 Rte_BMSH_BattVolt_BMSH_BattVolt;
    Rte_DE_UInt8 Rte_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter;
    Rte_DE_UInt8 Rte_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum;
    Rte_DE_Boolean Rte_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity;
    Rte_DE_UInt8 Rte_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity;
    Rte_DE_UInt8 Rte_BMSH_Cell_OverVol_BMSH_Cell_OverVol;
    Rte_DE_UInt8 Rte_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum;
    Rte_DE_UInt8 Rte_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol;
    Rte_DE_UInt8 Rte_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl;
    Rte_DE_Boolean Rte_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished;
    Rte_DE_UInt8 Rte_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current;
    Rte_DE_UInt16 Rte_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain;
    Rte_DE_UInt8 Rte_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure;
    Rte_DE_UInt8 Rte_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure;
    Rte_DE_UInt8 Rte_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState;
    Rte_DE_UInt16 Rte_BMSH_HVBusVolt_BMSH_HVBusVolt;
    Rte_DE_UInt8 Rte_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq;
    Rte_DE_UInt8 Rte_BMSH_HvBattThermMod_BMSH_HvBattThermMod;
    Rte_DE_Boolean Rte_BMSH_HvShutdownReq_BMSH_HvShutdownReq;
    Rte_DE_UInt16 Rte_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE;
    Rte_DE_UInt8 Rte_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp;
    Rte_DE_UInt16 Rte_BMSH_InsulationRes_BMSH_InsulationRes;
    Rte_DE_UInt8 Rte_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault;
    Rte_DE_UInt8 Rte_BMSH_Low_SOC_BMSH_Low_SOC;
    Rte_DE_UInt8 Rte_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp;
    Rte_DE_UInt8 Rte_BMSH_Over_SOC_BMSH_Over_SOC;
    Rte_DE_UInt8 Rte_BMSH_Over_Temperature_BMSH_Over_Temperature;
    Rte_DE_UInt8 Rte_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage;
    Rte_DE_UInt8 Rte_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage;
    Rte_DE_Boolean Rte_BMSH_SOC_Hop_BMSH_SOC_Hop;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS;
    Rte_DE_Double Rte_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS;
    Rte_DE_Boolean Rte_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT;
    Rte_DE_Double Rte_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS;
    Rte_DE_UInt8 Rte_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp;
    Rte_DE_UInt8 Rte_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp;
    Rte_DE_UInt8 Rte_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum;
    Rte_DE_Boolean Rte_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl;
    Rte_DE_Boolean Rte_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV;
    Rte_DE_UInt8 Rte_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter;
    Rte_DE_UInt8 Rte_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum;
    Rte_DE_UInt8 Rte_BMSH_stMode_BMSH_stMode;
    Rte_DE_Boolean Rte_BMS_BattPackMatchFault_BMS_BattPackMatchFault;
    Rte_DE_Double Rte_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS;
    Rte_DE_UInt16 Rte_BMS_MaxCellVolt_BMS_MaxCellVolt;
    Rte_DE_UInt8 Rte_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum;
    Rte_DE_UInt8 Rte_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum;
    Rte_DE_UInt16 Rte_BMS_MinCellVolt_BMS_MinCellVolt;
    Rte_DE_UInt8 Rte_BMS_MinVoltCellNum_BMS_MinVoltCellNum;
    Rte_DE_UInt8 Rte_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum;
    Rte_DE_UInt16 Rte_DrvPfmncRedn_DrvPfmncRedn;
    Rte_DE_UInt8 Rte_EDCP_Flt_EDCP_Flt;
    Rte_DE_UInt8 Rte_EDCP_PWMFB_EDCP_PWMFB;
    Rte_DE_Boolean Rte_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03;
    Rte_DE_Boolean Rte_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10;
    Rte_DE_Float Rte_EXT_DO_RELAY_LS_10_Fb_EXT_DO_RELAY_LS_10_Fb;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7;
    Rte_DE_Float Rte_EXT_DO_RELAY_LS_7_Fb_EXT_DO_RELAY_LS_7_Fb;
    Rte_DE_Boolean Rte_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9;
    Rte_DE_Float Rte_EXT_DO_RELAY_LS_9_Fb_EXT_DO_RELAY_LS_9_Fb;
    Rte_DE_Float Rte_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle;
    Rte_DE_Float Rte_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period;
    Rte_DE_Float Rte_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle;
    Rte_DE_Float Rte_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period;
    Rte_DE_Float Rte_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle;
    Rte_DE_Float Rte_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period;
    Rte_DE_Float Rte_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle;
    Rte_DE_Float Rte_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period;
    Rte_DE_Float Rte_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle;
    Rte_DE_Float Rte_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period;
    Rte_DE_UInt8 Rte_F190_VIN_Byte0_F190_VIN_Byte0;
    Rte_DE_UInt8 Rte_F190_VIN_Byte1_F190_VIN_Byte1;
    Rte_DE_UInt8 Rte_F190_VIN_Byte10_F190_VIN_Byte10;
    Rte_DE_UInt8 Rte_F190_VIN_Byte11_F190_VIN_Byte11;
    Rte_DE_UInt8 Rte_F190_VIN_Byte12_F190_VIN_Byte12;
    Rte_DE_UInt8 Rte_F190_VIN_Byte13_F190_VIN_Byte13;
    Rte_DE_UInt8 Rte_F190_VIN_Byte14_F190_VIN_Byte14;
    Rte_DE_UInt8 Rte_F190_VIN_Byte15_F190_VIN_Byte15;
    Rte_DE_UInt8 Rte_F190_VIN_Byte16_F190_VIN_Byte16;
    Rte_DE_UInt8 Rte_F190_VIN_Byte2_F190_VIN_Byte2;
    Rte_DE_UInt8 Rte_F190_VIN_Byte3_F190_VIN_Byte3;
    Rte_DE_UInt8 Rte_F190_VIN_Byte4_F190_VIN_Byte4;
    Rte_DE_UInt8 Rte_F190_VIN_Byte5_F190_VIN_Byte5;
    Rte_DE_UInt8 Rte_F190_VIN_Byte6_F190_VIN_Byte6;
    Rte_DE_UInt8 Rte_F190_VIN_Byte7_F190_VIN_Byte7;
    Rte_DE_UInt8 Rte_F190_VIN_Byte8_F190_VIN_Byte8;
    Rte_DE_UInt8 Rte_F190_VIN_Byte9_F190_VIN_Byte9;
    Rte_DE_UInt8 Rte_F193_ECUHardwareVersionNumber_Byte2_F193_ECUHardwareVersionNumber_Byte2;
    Rte_DE_UInt8 Rte_F193_ECUHardwareVersionNumber_Byte3_F193_ECUHardwareVersionNumber_Byte3;
    Rte_DE_UInt8 Rte_F193_ECUHardwareVersionNumber_Byte4_F193_ECUHardwareVersionNumber_Byte4;
    Rte_DE_UInt8 Rte_F193_ECUHardwareVersionNumber_Byte6_F193_ECUHardwareVersionNumber_Byte6;
    Rte_DE_UInt8 Rte_F193_ECUHardwareVersionNumber_Byte7_F193_ECUHardwareVersionNumber_Byte7;
    Rte_DE_UInt8 Rte_F193_ECUHardwareVersionNumber_Byte8_F193_ECUHardwareVersionNumber_Byte8;
    Rte_DE_UInt8 Rte_F195_ECUSoftwareVersionNumber_Byte2_F195_ECUSoftwareVersionNumber_Byte2;
    Rte_DE_UInt8 Rte_F195_ECUSoftwareVersionNumber_Byte3_F195_ECUSoftwareVersionNumber_Byte3;
    Rte_DE_UInt8 Rte_F195_ECUSoftwareVersionNumber_Byte4_F195_ECUSoftwareVersionNumber_Byte4;
    Rte_DE_UInt8 Rte_F195_ECUSoftwareVersionNumber_Byte6_F195_ECUSoftwareVersionNumber_Byte6;
    Rte_DE_UInt8 Rte_F195_ECUSoftwareVersionNumber_Byte7_F195_ECUSoftwareVersionNumber_Byte7;
    Rte_DE_UInt8 Rte_F195_ECUSoftwareVersionNumber_Byte8_F195_ECUSoftwareVersionNumber_Byte8;
    Rte_DE_Boolean Rte_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS;
    Rte_DE_UInt8 Rte_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS;
    Rte_DE_Boolean Rte_FWFV_InitState_PMS_FWFV_InitState_PMS;
    Rte_DE_Boolean Rte_FWFV_MotorState_PMS_FWFV_MotorState_PMS;
    Rte_DE_Boolean Rte_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS;
    Rte_DE_Boolean Rte_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS;
    Rte_DE_Boolean Rte_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS;
    Rte_DE_Boolean Rte_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS;
    Rte_DE_Boolean Rte_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS;
    Rte_DE_UInt8 Rte_HBCP_Flt_HBCP_Flt;
    Rte_DE_UInt8 Rte_HBCP_PWMFB_HBCP_PWMFB;
    Rte_DE_UInt32 Rte_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV;
    Rte_DE_UInt16 Rte_IPU_HVBusCur_PT_IPU_HVBusCur_PT;
    Rte_DE_UInt16 Rte_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT;
    Rte_DE_Boolean Rte_IPU_IPUTAlm_IPU_IPUTAlm;
    Rte_DE_Boolean Rte_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT;
    Rte_DE_Double Rte_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS;
    Rte_DE_Double Rte_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS;
    Rte_DE_Double Rte_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS;
    Rte_DE_Boolean Rte_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT;
    Rte_DE_Double Rte_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS;
    Rte_DE_Boolean Rte_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS;
    Rte_DE_UInt8 Rte_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS;
    Rte_DE_Boolean Rte_MHGV_InitState_PMS_MHGV_InitState_PMS;
    Rte_DE_Boolean Rte_MHGV_MotorState_PMS_MHGV_MotorState_PMS;
    Rte_DE_Boolean Rte_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS;
    Rte_DE_Boolean Rte_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS;
    Rte_DE_Boolean Rte_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS;
    Rte_DE_Boolean Rte_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS;
    Rte_DE_Boolean Rte_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS;
    Rte_DE_Boolean Rte_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm;
    Rte_DE_Double Rte_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS;
    Rte_DE_Boolean Rte_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm;
    Rte_DE_Double Rte_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS;
    Rte_DE_Boolean Rte_O_S_PIN110_O_S_PIN110;
    Rte_DE_Boolean Rte_O_S_PIN123_O_S_PIN123;
    Rte_DE_Boolean Rte_O_S_PIN83_O_S_PIN83;
    Rte_DE_Boolean Rte_O_S_PIN88_O_S_PIN88;
    Rte_DE_Boolean Rte_O_S_PIN89_O_S_PIN89;
    Rte_DE_Boolean Rte_O_S_PIN98_O_S_PIN98;
    Rte_DE_UInt16 Rte_O_T_PIN104_Duty_O_T_PIN104_Duty;
    Rte_DE_UInt32 Rte_O_T_PIN104_Period_O_T_PIN104_Period;
    Rte_DE_UInt16 Rte_O_T_PIN118_Duty_O_T_PIN118_Duty;
    Rte_DE_UInt32 Rte_O_T_PIN118_Period_O_T_PIN118_Period;
    Rte_DE_UInt16 Rte_O_T_PIN14_Duty_O_T_PIN14_Duty;
    Rte_DE_UInt32 Rte_O_T_PIN14_Period_O_T_PIN14_Period;
    Rte_DE_UInt16 Rte_O_T_PIN28_Duty_O_T_PIN28_Duty;
    Rte_DE_UInt32 Rte_O_T_PIN28_Period_O_T_PIN28_Period;
    Rte_DE_UInt16 Rte_O_T_PIN77_Duty_O_T_PIN77_Duty;
    Rte_DE_UInt32 Rte_O_T_PIN77_Period_O_T_PIN77_Period;
    Rte_DE_UInt16 Rte_O_T_PIN82_Duty_O_T_PIN82_Duty;
    Rte_DE_UInt32 Rte_O_T_PIN82_Period_O_T_PIN82_Period;
    Rte_DE_Boolean Rte_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag;
    Rte_DE_Double Rte_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS;
    Rte_DE_UInt8 Rte_PMS_ACC1PosVol_PMS_ACC1PosVol;
    Rte_DE_UInt8 Rte_PMS_ACC2PosVol_PMS_ACC2PosVol;
    Rte_DE_UInt8 Rte_PMS_ACCMEnable_PMS_ACCMEnable;
    Rte_DE_UInt8 Rte_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status;
    Rte_DE_UInt8 Rte_PMS_ADCCtrlSts_PMS_ADCCtrlSts;
    Rte_DE_Boolean Rte_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status;
    Rte_DE_UInt8 Rte_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich;
    Rte_DE_UInt8 Rte_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS;
    Rte_DE_UInt8 Rte_PMS_AccelPedalPosition_PMS_AccelPedalPosition;
    Rte_DE_Boolean Rte_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid;
    Rte_DE_UInt8 Rte_PMS_Acceleration_PMS_Acceleration;
    Rte_DE_UInt8 Rte_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb;
    Rte_DE_Boolean Rte_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand;
    Rte_DE_UInt8 Rte_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt;
    Rte_DE_UInt16 Rte_PMS_ActualPTTorque_PMS_ActualPTTorque;
    Rte_DE_Boolean Rte_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid;
    Rte_DE_UInt8 Rte_PMS_AppSts_PMS_AppSts;
    Rte_DE_UInt8 Rte_PMS_AppSts_EV_PMS_AppSts_EV;
    Rte_DE_UInt8 Rte_PMS_AuthResult_PMS_AuthResult;
    Rte_DE_UInt16 Rte_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption;
    Rte_DE_UInt8 Rte_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd;
    Rte_DE_Boolean Rte_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl;
    Rte_DE_Boolean Rte_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl;
    Rte_DE_Boolean Rte_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus;
    Rte_DE_Boolean Rte_PMS_BBM_HVReq_PMS_BBM_HVReq;
    Rte_DE_Boolean Rte_PMS_BBM_WorkSts_PMS_BBM_WorkSts;
    Rte_DE_UInt16 Rte_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy;
    Rte_DE_UInt16 Rte_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp;
    Rte_DE_UInt16 Rte_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH;
    Rte_DE_UInt8 Rte_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1;
    Rte_DE_UInt8 Rte_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2;
    Rte_DE_Boolean Rte_PMS_BatCoolType_PMS_BatCoolType;
    Rte_DE_UInt8 Rte_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV;
    Rte_DE_UInt8 Rte_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV;
    Rte_DE_UInt8 Rte_PMS_BatteryVol_PMS_BatteryVol;
    Rte_DE_Boolean Rte_PMS_Brake1Switch_PMS_Brake1Switch;
    Rte_DE_Boolean Rte_PMS_Brake2Switch_PMS_Brake2Switch;
    Rte_DE_Boolean Rte_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest;
    Rte_DE_Boolean Rte_PMS_BrkSysErr_PMS_BrkSysErr;
    Rte_DE_Boolean Rte_PMS_CANBus_RecSta_PMS_CANBus_RecSta;
    Rte_DE_Boolean Rte_PMS_CPSREn_PMS_CPSREn;
    Rte_DE_UInt8 Rte_PMS_CPSRU_PMS_CPSRU;
    Rte_DE_UInt8 Rte_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum;
    Rte_DE_UInt8 Rte_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum;
    Rte_DE_Boolean Rte_PMS_CampModeFb_PMS_CampModeFb;
    Rte_DE_UInt8 Rte_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason;
    Rte_DE_UInt16 Rte_PMS_ChargPwr_PMS_ChargPwr;
    Rte_DE_UInt8 Rte_PMS_ChargWakeupSts_PMS_ChargWakeupSts;
    Rte_DE_UInt8 Rte_PMS_ChargeHV_Status_PMS_ChargeHV_Status;
    Rte_DE_UInt8 Rte_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse;
    Rte_DE_Boolean Rte_PMS_ChargerFault_PMS_ChargerFault;
    Rte_DE_UInt8 Rte_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV;
    Rte_DE_UInt8 Rte_PMS_Command_Checksum_PMS_Command_Checksum;
    Rte_DE_UInt8 Rte_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV;
    Rte_DE_UInt8 Rte_PMS_ControlSetSpeed_PMS_ControlSetSpeed;
    Rte_DE_UInt8 Rte_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB;
    Rte_DE_UInt8 Rte_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
    Rte_DE_UInt8 Rte_PMS_CruiseControlSts_PMS_CruiseControlSts;
    Rte_DE_Boolean Rte_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts;
    Rte_DE_Boolean Rte_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb;
    Rte_DE_UInt8 Rte_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum;
    Rte_DE_UInt8 Rte_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
    Rte_DE_UInt8 Rte_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV;
    Rte_DE_Boolean Rte_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
    Rte_DE_Boolean Rte_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV;
    Rte_DE_Boolean Rte_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW;
    Rte_DE_UInt8 Rte_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
    Rte_DE_UInt8 Rte_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt;
    Rte_DE_UInt8 Rte_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum;
    Rte_DE_UInt8 Rte_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV;
    Rte_DE_UInt8 Rte_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK;
    Rte_DE_Boolean Rte_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV;
    Rte_DE_Boolean Rte_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
    Rte_DE_Boolean Rte_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt;
    Rte_DE_UInt8 Rte_PMS_DischargeEnable_PMS_DischargeEnable;
    Rte_DE_Boolean Rte_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn;
    Rte_DE_UInt8 Rte_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
    Rte_DE_UInt8 Rte_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV;
    Rte_DE_UInt8 Rte_PMS_DriveModeInd_PMS_DriveModeInd;
    Rte_DE_UInt16 Rte_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
    Rte_DE_Boolean Rte_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid;
    Rte_DE_Boolean Rte_PMS_DriverGearAbort_PMS_DriverGearAbort;
    Rte_DE_Boolean Rte_PMS_DriverRemind_PMS_DriverRemind;
    Rte_DE_UInt8 Rte_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts;
    Rte_DE_UInt8 Rte_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn;
    Rte_DE_UInt8 Rte_PMS_EDCPEnable_PMS_EDCPEnable;
    Rte_DE_UInt8 Rte_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV;
    Rte_DE_UInt8 Rte_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
    Rte_DE_UInt8 Rte_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV;
    Rte_DE_UInt8 Rte_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB;
    Rte_DE_UInt8 Rte_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl;
    Rte_DE_Boolean Rte_PMS_EPBClosedReq_PMS_EPBClosedReq;
    Rte_DE_SInt16 Rte_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue;
    Rte_DE_Boolean Rte_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid;
    Rte_DE_UInt8 Rte_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg;
    Rte_DE_UInt16 Rte_PMS_EVDTEodometer_PMS_EVDTEodometer;
    Rte_DE_UInt8 Rte_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum;
    Rte_DE_UInt8 Rte_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
    Rte_DE_UInt8 Rte_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc;
    Rte_DE_UInt8 Rte_PMS_EpedalActive_PMS_EpedalActive;
    Rte_DE_UInt16 Rte_PMS_ErrCode_PMS_ErrCode;
    Rte_DE_UInt8 Rte_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults;
    Rte_DE_UInt8 Rte_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl;
    Rte_DE_Boolean Rte_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable;
    Rte_DE_Boolean Rte_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN;
    Rte_DE_UInt8 Rte_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos;
    Rte_DE_UInt8 Rte_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN;
    Rte_DE_Boolean Rte_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb;
    Rte_DE_Boolean Rte_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb;
    Rte_DE_Boolean Rte_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
    Rte_DE_UInt8 Rte_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
    Rte_DE_UInt8 Rte_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive;
    Rte_DE_UInt8 Rte_PMS_FunLockVehActive_PMS_FunLockVehActive;
    Rte_DE_Boolean Rte_PMS_GP_Ovrd_PMS_GP_Ovrd;
    Rte_DE_UInt8 Rte_PMS_GearOperateErr_PMS_GearOperateErr;
    Rte_DE_Boolean Rte_PMS_Gear_intervene_PMS_Gear_intervene;
    Rte_DE_UInt16 Rte_PMS_GrossComVehWeight_PMS_GrossComVehWeight;
    Rte_DE_UInt8 Rte_PMS_HBCPEnable_PMS_HBCPEnable;
    Rte_DE_UInt8 Rte_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
    Rte_DE_UInt8 Rte_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB;
    Rte_DE_UInt8 Rte_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl;
    Rte_DE_Boolean Rte_PMS_HVIL1Sts_PMS_HVIL1Sts;
    Rte_DE_Boolean Rte_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB;
    Rte_DE_Boolean Rte_PMS_HVIL2Sts_PMS_HVIL2Sts;
    Rte_DE_Boolean Rte_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB;
    Rte_DE_Boolean Rte_PMS_HVILSts_PMS_HVILSts;
    Rte_DE_Boolean Rte_PMS_HVILSts_UB_PMS_HVILSts_UB;
    Rte_DE_UInt8 Rte_PMS_HVPRASts_PMS_HVPRASts;
    Rte_DE_UInt8 Rte_PMS_HardwareMajorVer_PMS_HardwareMajorVer;
    Rte_DE_UInt8 Rte_PMS_HardwareMinorVer_PMS_HardwareMinorVer;
    Rte_DE_Boolean Rte_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl;
    Rte_DE_UInt8 Rte_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd;
    Rte_DE_UInt8 Rte_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd;
    Rte_DE_UInt32 Rte_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer;
    Rte_DE_Boolean Rte_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts;
    Rte_DE_Boolean Rte_PMS_IgnONSts_PMS_IgnONSts;
    Rte_DE_UInt8 Rte_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq;
    Rte_DE_UInt8 Rte_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit;
    Rte_DE_UInt8 Rte_PMS_IntelligentChargeState_PMS_IntelligentChargeState;
    Rte_DE_UInt8 Rte_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts;
    Rte_DE_UInt8 Rte_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts;
    Rte_DE_UInt8 Rte_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
    Rte_DE_UInt8 Rte_PMS_IsgModReq_PMS_IsgModReq;
    Rte_DE_UInt16 Rte_PMS_IsgTqReq_PMS_IsgTqReq;
    Rte_DE_UInt8 Rte_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB;
    Rte_DE_UInt8 Rte_PMS_Life_PMS_Life;
    Rte_DE_Boolean Rte_PMS_LimpHomeSts_PMS_LimpHomeSts;
    Rte_DE_UInt8 Rte_PMS_LockLimResult_PMS_LockLimResult;
    Rte_DE_UInt8 Rte_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts;
    Rte_DE_UInt8 Rte_PMS_LockVehPerFlag_PMS_LockVehPerFlag;
    Rte_DE_UInt8 Rte_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts;
    Rte_DE_UInt8 Rte_PMS_LockVehSts_PMS_LockVehSts;
    Rte_DE_UInt8 Rte_PMS_LockVehType_PMS_LockVehType;
    Rte_DE_Boolean Rte_PMS_MCUActvdReq_PMS_MCUActvdReq;
    Rte_DE_UInt8 Rte_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV;
    Rte_DE_UInt8 Rte_PMS_MCUTemp_EV_PMS_MCUTemp_EV;
    Rte_DE_Boolean Rte_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq;
    Rte_DE_Boolean Rte_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN;
    Rte_DE_UInt8 Rte_PMS_MHGV_PosSet_PMS_MHGV_PosSet;
    Rte_DE_UInt8 Rte_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN;
    Rte_DE_Boolean Rte_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop;
    Rte_DE_Boolean Rte_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN;
    Rte_DE_Boolean Rte_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery;
    Rte_DE_Boolean Rte_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN;
    Rte_DE_UInt16 Rte_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed;
    Rte_DE_UInt16 Rte_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed;
    Rte_DE_UInt8 Rte_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
    Rte_DE_UInt8 Rte_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum;
    Rte_DE_UInt8 Rte_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
    Rte_DE_Boolean Rte_PMS_NMSts_PMS_NMSts;
    Rte_DE_Double Rte_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder;
    Rte_DE_Double Rte_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts;
    Rte_DE_UInt16 Rte_PMS_Odometerbackup_PMS_Odometerbackup;
    Rte_DE_Boolean Rte_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable;
    Rte_DE_UInt32 Rte_PMS_PEPSAuth_PMS_PEPSAuth;
    Rte_DE_Boolean Rte_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag;
    Rte_DE_UInt8 Rte_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode;
    Rte_DE_UInt8 Rte_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity;
    Rte_DE_UInt8 Rte_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb;
    Rte_DE_UInt8 Rte_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt;
    Rte_DE_Boolean Rte_PMS_PTC2Enable_PMS_PTC2Enable;
    Rte_DE_UInt8 Rte_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb;
    Rte_DE_Boolean Rte_PMS_PTC3Enable_PMS_PTC3Enable;
    Rte_DE_UInt8 Rte_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt;
    Rte_DE_UInt8 Rte_PMS_PTCEnable_PMS_PTCEnable;
    Rte_DE_UInt8 Rte_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich;
    Rte_DE_UInt16 Rte_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd;
    Rte_DE_UInt8 Rte_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts;
    Rte_DE_UInt8 Rte_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts;
    Rte_DE_UInt8 Rte_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb;
    Rte_DE_UInt8 Rte_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt;
    Rte_DE_UInt8 Rte_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
    Rte_DE_Boolean Rte_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
    Rte_DE_UInt16 Rte_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot;
    Rte_DE_Boolean Rte_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier;
    Rte_DE_UInt16 Rte_PMS_RegenTrqAct_PMS_RegenTrqAct;
    Rte_DE_Boolean Rte_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier;
    Rte_DE_UInt16 Rte_PMS_RegenTrqPot_PMS_RegenTrqPot;
    Rte_DE_Boolean Rte_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier;
    Rte_DE_UInt8 Rte_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS;
    Rte_DE_UInt8 Rte_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt;
    Rte_DE_UInt32 Rte_PMS_ReqSeed_PMS_ReqSeed;
    Rte_DE_UInt8 Rte_PMS_RespResult_PMS_RespResult;
    Rte_DE_UInt8 Rte_PMS_SelfCheckSts_PMS_SelfCheckSts;
    Rte_DE_UInt8 Rte_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq;
    Rte_DE_UInt8 Rte_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer;
    Rte_DE_UInt8 Rte_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer;
    Rte_DE_UInt8 Rte_PMS_SpdLmtLevel_PMS_SpdLmtLevel;
    Rte_DE_UInt8 Rte_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts;
    Rte_DE_Boolean Rte_PMS_StartActive_PMS_StartActive;
    Rte_DE_UInt32 Rte_PMS_Stayawake_reasons_PMS_Stayawake_reasons;
    Rte_DE_Boolean Rte_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1;
    Rte_DE_Boolean Rte_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid;
    Rte_DE_Boolean Rte_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS;
    Rte_DE_Boolean Rte_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS;
    Rte_DE_UInt8 Rte_PMS_StsSwap_PMS_StsSwap;
    Rte_DE_UInt8 Rte_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV;
    Rte_DE_Boolean Rte_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr;
    Rte_DE_Double Rte_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS;
    Rte_DE_Boolean Rte_PMS_TBOX_HVILState_PMS_TBOX_HVILState;
    Rte_DE_Boolean Rte_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1;
    Rte_DE_Boolean Rte_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts;
    Rte_DE_Double Rte_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS;
    Rte_DE_UInt8 Rte_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts;
    Rte_DE_Boolean Rte_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq;
    Rte_DE_UInt8 Rte_PMS_ThermalReq_PMS_ThermalReq;
    Rte_DE_UInt8 Rte_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active;
    Rte_DE_UInt8 Rte_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type;
    Rte_DE_Boolean Rte_PMS_TurtleLampOn_PMS_TurtleLampOn;
    Rte_DE_Boolean Rte_PMS_TurtleLampOn2_PMS_TurtleLampOn2;
    Rte_DE_UInt8 Rte_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1;
    Rte_DE_UInt8 Rte_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S;
    Rte_DE_UInt8 Rte_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S;
    Rte_DE_UInt8 Rte_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S;
    Rte_DE_UInt8 Rte_PMS_VINCode4_11_S_PMS_VINCode4_11_S;
    Rte_DE_UInt8 Rte_PMS_VINCode5_12_S_PMS_VINCode5_12_S;
    Rte_DE_UInt8 Rte_PMS_VINCode6_13_S_PMS_VINCode6_13_S;
    Rte_DE_UInt8 Rte_PMS_VINCode7_14_S_PMS_VINCode7_14_S;
    Rte_DE_UInt8 Rte_PMS_VINMessageNum_S_PMS_VINMessageNum_S;
    Rte_DE_UInt16 Rte_PMS_VacuumPressure_PMS_VacuumPressure;
    Rte_DE_Boolean Rte_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd;
    Rte_DE_UInt8 Rte_PMS_VacuumPump_FB_PMS_VacuumPump_FB;
    Rte_DE_UInt8 Rte_PMS_VacuumSystemsta_PMS_VacuumSystemsta;
    Rte_DE_UInt16 Rte_PMS_VehicleSpeed_PMS_VehicleSpeed;
    Rte_DE_Boolean Rte_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV;
    Rte_DE_UInt8 Rte_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
    Rte_DE_UInt8 Rte_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel;
    Rte_DE_UInt8 Rte_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG;
    Rte_DE_UInt8 Rte_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS;
    Rte_DE_UInt8 Rte_PMS_VersionConversionFlag_PMS_VersionConversionFlag;
    Rte_DE_UInt8 Rte_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts;
    Rte_DE_UInt8 Rte_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
    Rte_DE_Boolean Rte_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
    Rte_DE_Boolean Rte_PMS_ePTFault_PMS_ePTFault;
    Rte_DE_Boolean Rte_PMS_ePTFault2_PMS_ePTFault2;
    Rte_DE_UInt8 Rte_PMS_ePTModeActual_PMS_ePTModeActual;
    Rte_DE_UInt8 Rte_PMS_ePTModeSelect_PMS_ePTModeSelect;
    Rte_DE_Boolean Rte_PMS_ePTReady_PMS_ePTReady;
    Rte_DE_Boolean Rte_PMS_ePTReady_EV_PMS_ePTReady_EV;
    Rte_DE_UInt8 Rte_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd;
    Rte_DE_UInt8 Rte_PMS_ePTReleaseSig_PMS_ePTReleaseSig;
    Rte_DE_UInt8 Rte_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV;
    Rte_DE_UInt8 Rte_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV;
    Rte_DE_UInt16 Rte_VCU_ActInputVolt_VCU_ActInputVolt;
    Rte_DE_UInt8 Rte_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
    Rte_DE_UInt8 Rte_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
    Rte_DE_UInt8 Rte_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum;
    Rte_DE_UInt8 Rte_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt;
    Rte_DE_UInt8 Rte_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
    Rte_DE_UInt8 Rte_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
    Rte_DE_UInt8 Rte_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
    Rte_DE_UInt8 Rte_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
    Rte_DE_UInt8 Rte_VCU_CrashOutputSts_VCU_CrashOutputSts;
    Rte_DE_UInt8 Rte_VCU_DCInputCurrent_VCU_DCInputCurrent;
    Rte_DE_UInt16 Rte_VCU_Odometerbackup_VCU_Odometerbackup;
    Rte_DE_UInt8 Rte_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
    Rte_DE_UInt8 Rte_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter;
    Rte_DE_UInt8 Rte_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum;
    Rte_DE_UInt8 Rte_st_ShtDown_st_ShtDown;
    Rte_DE_Boolean Rte_vcib_VCIP_accd_b_acHvilOpn;
    Rte_DE_Boolean Rte_vcib_VCIP_accd_b_acHvilOpnInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_acpd_b_accPedlPosVld;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosCan_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosSens1_pct;
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPosSens2_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adcCtrlGearEn;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsCanBusRecSta;
    Rte_DE_Boolean Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch;
    Rte_DE_Float Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar;
    Rte_DE_Float Rte_vcib_VCIP_brpd_x_brkPedlPos_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_acuCrash;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcHvilFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_dccd_b_dcdcHvilFltInvld;
    Rte_DE_UInt8 Rte_vcib_VCIP_drid_st_gearLvrPosSeql;
    Rte_DE_Float Rte_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_eadd_u_busInv2HVAct_V;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_epbd_e_parkingSts;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_hvilOpen;
    Rte_DE_HVBattStatus Rte_vcib_VCIP_hvbd_e_hvbStatus;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_fact_hvbSOH_pct;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_i_hvbCurr_A;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_q_hvbSOC_pct;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_hvbThermMngReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_hvbd_st_tboxIntelChgQuit;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbAvg_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbMin_C;
    Rte_DE_Float Rte_vcib_VCIP_hvbd_t_hvbTemp_C;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_vcuSelfChkOk;
    Rte_DE_Float Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_macd_u_batIntSmpl_V;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Float Rte_vcib_VCIP_tmmd_n_motActSpd_rpm;
    Rte_DE_Float Rte_vcib_VCIP_tmmd_tq_motActTq_Nm;
    Rte_DE_Float Rte_vcib_VCIP_trad_fact_trsm2GearRat;
    Rte_DE_SInt8 Rte_vcib_VCIP_trad_st_trsm2GearAct;
    Rte_DE_Float Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
    Rte_DE_Float Rte_vcib_VCIP_vild_R_posInsIRes_Ohm;
    Rte_DE_Float Rte_vcib_VCIP_vild_ang_strWhlAng_rad;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_AccyEnReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_AccyFltSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_CCSginal;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_DryAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ResrAirSwitch;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_brkSwt1Actv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_brkSwt2Actv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_dcdcStsAlm;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_dcdcTempAlm;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_disChgSwtSt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_driverEVModeReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_driverEcoModeReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_emgyStopIn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgBatCol;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvCcwFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvInitSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvMotSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvOvrCurrFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvOvrTempFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvOvrVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvRespErr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_fwfvUndVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_hvbHvilFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ignStsOn;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_ignStsStrt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvCcwFlg;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvInitSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvMotSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvOvrCurrFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvOvrTempFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvOvrVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvRespErr;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_mhgvUndVoltFlt;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_obcWakeUpActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_odometerInvalid;
    Rte_DE_Float Rte_vcib_VCIP_vild_d_odometer_km;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_dcdcInpCurr_A;
    Rte_DE_Float Rte_vcib_VCIP_vild_i_hvbCurr_A;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbCellMaxID;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbCellMinID;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_num_hvbCellSum;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbMaxTempID;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbMinTempID;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_num_hvbTempSum;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_GearPosn;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_HVILReturnPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_WatPmpEP3FbPWM;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_fan1Fb;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_fan2Fb;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_fwfvCrtPos;
    Rte_DE_Float Rte_vcib_VCIP_vild_pct_mhgvCrtPos;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_24vDcdcModAct;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_actWorkSts1;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batLowSoc2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batOvrSoc2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batOvrVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_batUdrVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsBattPackMatchFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsBattPackNum;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsBattSysNum;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_bmsTboxFireAlm;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_cellOverVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_cellUdrVolt2;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_dcChgCcSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_eadInv2TempHiAlrm;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ehbBrkSysErrFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_epsEpasFail;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgAccy;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbBatUniformity;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbBattIsolationSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbCellTempDevFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbCellVoltDevFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgOvrCurr;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbDCChgProcss;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbInslErr;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbOvrChgFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbSocFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbSocJumpFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStatus;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStsChgFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbStsDischgFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbTempFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbThermMngReq;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuInvTempHighAlm;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuMotTempHighFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuMotorOverCurrFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_ipuMotorOverSpdFlt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcChgSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdCCline;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_pepsPduLvl;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_pepsPduLvlVld;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_tboxRsrChgSt;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_acwpOutptTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbCooltInTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbCooltOutTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbMax_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbMin_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbOutCoolTemp_C;
    Rte_DE_Float Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
    Rte_DE_UInt16 Rte_vcib_VCIP_vild_tm_hvbFnshChgTim_m;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_BmsMaxCellVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_BmsMinCellVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Brk2_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_Brk_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_TS5sensorFb_mV;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_VacTkEnFb_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_accPdlSens1InpVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_accPdlSens2InpVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_dcdcRelayVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbPackVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_hvbVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V;
    Rte_DE_Float Rte_vcib_VCIP_vscd_a_vscLongitAcce_mps2;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_ESPActv;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vscBrkLghtActv;
    Rte_DE_UInt8 Rte_vcib_VCIP_vscd_st_vscIsgActvDampModReq;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpdRaw_kph;
    Rte_DE_UInt8 Rte_vcob_VCOP_BMSH_ChargeLEDCtrl;
    Rte_DE_UInt8 Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_brkPmp1Rly;
    Rte_DE_Float Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa;
    Rte_DE_Boolean Rte_vcsb_AUXC_pscd_b_epsEna;
    Rte_DE_Boolean Rte_vcsb_AUXC_pscd_b_epsStopFlt;
    Rte_DE_Float Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz;
    Rte_DE_Boolean Rte_vcsb_DIAG_brpd_b_brkSwtMismatch;
    Rte_DE_UInt8 Rte_vcsb_DIAG_digd_st_edcpFlt;
    Rte_DE_UInt8 Rte_vcsb_DIAG_digd_st_hbcpFlt;
    Rte_DE_UInt8 Rte_vcsb_DIAG_digd_st_vehSysErrLevel;
    Rte_DE_Float Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
    Rte_DE_Boolean Rte_vcsb_EGYM_egmd_b_zeroPwrFb;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax;
    Rte_DE_UInt8 Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd;
    Rte_DE_Float Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW;
    Rte_DE_UInt8 Rte_vcsb_EGYM_egmd_st_vcuChgLimResp;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_brkSysFlt;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_ePTFault;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_odoBckpEn;
    Rte_DE_Boolean Rte_vcsb_HMIF_dspd_b_turtleLmpOn;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_odoTotal_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehCrsDst_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_num_errorCode;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW;
    Rte_DE_Float Rte_vcsb_HMIF_dspd_q_hvbSOC_pct;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_drvModInd;
    Rte_DE_UInt16 Rte_vcsb_HMIF_dspd_st_drvPfmncRedn;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_drvrOptRmdr;
    Rte_DE_UInt8 Rte_vcsb_HMIF_dspd_st_vehDrvMode;
    Rte_DE_UInt8 Rte_vcsb_HVSM_bmsd_e_modeTgt;
    Rte_DE_DCDCMode Rte_vcsb_HVSM_dccd_e_modeTgt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt;
    Rte_DE_ElMac Rte_vcsb_HVSM_eadd_e_inv2ModeTgt;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_CampModeFb;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_allowChg;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_dchaOn;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_lvCutOffReq;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
    Rte_DE_PmmStatus Rte_vcsb_HVSM_hvbd_e_PmmStatus;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyPreRlySts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyRlyFlt;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyRlySts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_accyTakeSts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_ptRdyInd;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV;
    Rte_DE_Boolean Rte_vcsb_HVSM_obcd_b_chargerPlugged;
    Rte_DE_Float Rte_vcsb_MEST_masd_m_vehWeight_kg;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_invSpdLmtRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_inventorySpdLmtReq;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_lifeCnt;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_lockVehPer;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_lockVehPerRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_pwrOffCmd;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_pwrOffCmdRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_spdLmtLevelReq;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_spdLmtLvRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_tboxLifeSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_verCvsRxSts;
    Rte_DE_UInt8 Rte_vcsb_OGVL_dtld_st_versionConversion;
    Rte_DE_Boolean Rte_vcsb_RMLK_rlcd_b_LockVehSts;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_FunLockVehActive;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_LockLimResult;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_num_LockVehType;
    Rte_DE_UInt8 Rte_vcsb_RMLK_rlcd_st_LockVehExecutedSts;
    Rte_DE_Float Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMax_Nm;
    Rte_DE_Float Rte_vcsb_SCAP_tqld_tq_whlMin_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2;
    Rte_DE_Boolean Rte_vcsb_SCOO_ccdd_b_accCtrlActv;
    Rte_DE_CrsBtnErrSts Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts;
    Rte_DE_CrsBtnSts Rte_vcsb_SCOO_ccdd_e_crsBtnSts;
    Rte_DE_CrModeMngr_e Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode;
    Rte_DE_CruiseSts_e Rte_vcsb_SCOO_ccdd_e_crsCtrlSts;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph;
    Rte_DE_Float Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph;
    Rte_DE_Float Rte_vcsb_SCOO_vsld_v_vehMaxSpd_kph;
    Rte_DE_UInt8 Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp;
    Rte_DE_Float Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm;
    Rte_DE_Float Rte_vcsb_TCOO_tdad_tq_whlDem_Nm;
    Rte_DE_Boolean Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld;
    Rte_DE_Boolean Rte_vcsb_TCOO_tqdd_b_gpOvrd;
    Rte_DE_UInt8 Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv;
    Rte_DE_UInt8 Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp;
    Rte_DE_UInt8 Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn;
    Rte_DE_Float Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct;
    Rte_DE_Float Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ActiveCool_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_BalanceHeat_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_PassCool_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_PassHeat_flg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_accmEnb;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_fanRly1Req;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_fanRly2Req;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna3;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEna3HW;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_heaterEnaHW;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_hvbDeft;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_iptcHtIpuCl;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ipuResvHt;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv1V3;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_tv2V2;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_FWFVTgt_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_MHGVTgt_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct;
    Rte_DE_Float Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW;
    Rte_DE_Float Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acwpHeat;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_acwpSpdReq;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptc3RlyFlt;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcConnStsFb;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcRlyFlt;
    Rte_DE_UInt8 Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch;
    Rte_DE_Float Rte_vcsb_THSM_thmd_t_acwpTemp_C;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_epbClsdReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_gearPosVld;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_GearLeverPos Rte_vcsb_VOMM_drid_e_gearLvrPos;
    Rte_DE_UInt8 Rte_vcsb_VOMM_drid_st_gearLvrLckInd;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_engStopReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_hsdFltClear;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_nmSts;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_pwrHoldReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_vcuAwb;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_vcuRmr;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_num_vcuAddr;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_bdCanModeReq;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_ptCanModeReq;
    Rte_DE_UInt32 Rte_vcsb_VOMM_pmmd_st_stayAwkReason;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason;
}Rte_tsRB_swc_VCOP_swc_VCOP_Step;

typedef struct
{
    Rte_DE_Float Rte_vcib_VCIP_acpd_x_accPedlPos_pct;
    Rte_DE_Boolean Rte_vcib_VCIP_adcd_b_adcCtrlGearEn;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_adcTgtGearPostn;
    Rte_DE_UInt8 Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
    Rte_DE_BrakePedalStatus Rte_vcib_VCIP_brpd_e_brkPedalStatus;
    Rte_DE_Boolean Rte_vcib_VCIP_cesd_b_EmergencyStop;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReq;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReq4WD;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqECO;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqEV;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqHEV;
    Rte_DE_Boolean Rte_vcib_VCIP_drid_b_drvrModeReqSPORT;
    Rte_DE_UInt8 Rte_vcib_VCIP_drid_b_parkBtnPressed;
    Rte_DE_GearLeverPos Rte_vcib_VCIP_drid_e_gearLvrPosRaw;
    Rte_DE_UInt8 Rte_vcib_VCIP_drid_st_gearLvrPosSeql;
    Rte_DE_Boolean Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt;
    Rte_DE_Float Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
    Rte_DE_Boolean Rte_vcib_VCIP_engd_b_fuTankLock;
    Rte_DE_Boolean Rte_vcib_VCIP_engd_b_fuTankUnlock;
    Rte_DE_ParkingStatus Rte_vcib_VCIP_epbd_e_parkingSts;
    Rte_DE_Boolean Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
    Rte_DE_Boolean Rte_vcib_VCIP_macd_b_pullUpDiagCmpl;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcCANMsgValid;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged;
    Rte_DE_Boolean Rte_vcib_VCIP_obcd_b_obcWakeUp;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_anyIgnOn;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_driverStartReq;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ignOn;
    Rte_DE_Boolean Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy;
    Rte_DE_KeyAuthStatus Rte_vcib_VCIP_pmmd_e_authenticationStatus;
    Rte_DE_Boolean Rte_vcib_VCIP_tstd_b_engStrtReq;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_epbErrSts;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
    Rte_DE_Boolean Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_dcChgCcSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_hvbChgCcsts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcChgCCSts;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdCCline;
    Rte_DE_UInt8 Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline;
    Rte_DE_Boolean Rte_vcib_VCIP_vscd_b_vehSpdVld;
    Rte_DE_Float Rte_vcib_VCIP_vscd_v_vehSpd_kph;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_airTankFlt;
    Rte_DE_Boolean Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv;
    Rte_DE_Boolean Rte_vcsb_DIAG_ddid_b_egsmMsgErr;
    Rte_DE_Boolean Rte_vcsb_HVSM_eadd_b_ead2Avail;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_chgCablePlugged;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_rlyTmOut;
    Rte_DE_Boolean Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp;
    Rte_DE_UInt8 Rte_vcsb_HVSM_hvbd_st_ptRdyInd;
    Rte_DE_Boolean Rte_vcsb_HVSM_obcd_b_chargerPlugged;
    Rte_DE_ChargerStatus Rte_vcsb_HVSM_obcd_e_chargerSts;
    Rte_DE_Boolean Rte_vcsb_THSM_thmd_b_afterRunActive;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_epbClsdReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_gearPosVld;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_veh4WDModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehEcoModActv;
    Rte_DE_Boolean Rte_vcsb_VOMM_drid_b_vehSportModActv;
    Rte_DE_DriveDir Rte_vcsb_VOMM_drid_e_driveDirSel;
    Rte_DE_HEVModeReq Rte_vcsb_VOMM_drid_e_drvrHEVModReq;
    Rte_DE_GearLeverPos Rte_vcsb_VOMM_drid_e_gearLvrPos;
    Rte_DE_UInt8 Rte_vcsb_VOMM_drid_st_gearLvrLckInd;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_engStartReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_engStopReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_engStrtAbort;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_engStrtComplete;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_motStrtDem;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_motStrtEnad;
    Rte_DE_Boolean Rte_vcsb_VOMM_essd_b_strtrRlyDem;
    Rte_DE_EngStartType Rte_vcsb_VOMM_essd_e_engStrtTyp;
    Rte_DE_EngStartType Rte_vcsb_VOMM_essd_e_engStrtTypSeld;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_EVModeActive;
    Rte_DE_Boolean Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_emsWake;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_hsdFltClear;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_nmRdySlp;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_nmSts;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_nmWkUp;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_peuWake;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_pwrHoldReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_startReq;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_vcuAwb;
    Rte_DE_Boolean Rte_vcsb_VOMM_pmmd_b_vcuRmr;
    Rte_DE_rt_Array_UInt8_2 Rte_vcsb_VOMM_pmmd_bm_netModeReq;
    Rte_DE_NMStatus Rte_vcsb_VOMM_pmmd_e_CanNMSts;
    Rte_DE_PmmMode Rte_vcsb_VOMM_pmmd_e_mode;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_num_vcuAddr;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_bdCanModeReq;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_ptCanModeReq;
    Rte_DE_UInt32 Rte_vcsb_VOMM_pmmd_st_stayAwkReason;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_vcuPwrActvMod;
    Rte_DE_UInt8 Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_PTDisabled;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_PTEnabled;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_StartDemRaw;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRun;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehRunRaw;
    Rte_DE_Boolean Rte_vcsb_VOMM_vsmd_b_VehStrt;
}Rte_tsRB_swc_VOMM_swc_VOMM_Step;

typedef struct
{
    Rte_tsRB_BIfRx_fc_BIfRx Rte_BIfRx_fc_BIfRx;
}Rte_tuRB_Task_100us_Core3_QM;

typedef struct
{
    Rte_tsRB_swc_ATAU_swc_ATAU_Step Rte_swc_ATAU_swc_ATAU_Step;
    Rte_tsRB_swc_DIAG_swc_DIAG_Step Rte_swc_DIAG_swc_DIAG_Step;
    Rte_tsRB_swc_EGYM_swc_EGYM_Step Rte_swc_EGYM_swc_EGYM_Step;
    Rte_tsRB_swc_HMIF_swc_HMIF_Step Rte_swc_HMIF_swc_HMIF_Step;
    Rte_tsRB_swc_HVSM_swc_HVSM_Step Rte_swc_HVSM_swc_HVSM_Step;
    Rte_tsRB_swc_MEST_swc_MEST_Step Rte_swc_MEST_swc_MEST_Step;
    Rte_tsRB_swc_OGVL_swc_OGVL_Step Rte_swc_OGVL_swc_OGVL_Step;
    Rte_tsRB_swc_RMLK_swc_RMLK_Step Rte_swc_RMLK_swc_RMLK_Step;
    Rte_tsRB_swc_SCAP_swc_SCAP_Step Rte_swc_SCAP_swc_SCAP_Step;
    Rte_tsRB_swc_SCOO_swc_SCOO_Step Rte_swc_SCOO_swc_SCOO_Step;
    Rte_tsRB_swc_TCOO_swc_TCOO_Step Rte_swc_TCOO_swc_TCOO_Step;
    Rte_tsRB_swc_AUXC_swc_AUXC_Step Rte_swc_AUXC_swc_AUXC_Step;
    Rte_tsRB_swc_VCIP_swc_VCIP_Step Rte_swc_VCIP_swc_VCIP_Step;
    Rte_tsRB_swc_VCOP_swc_VCOP_Step Rte_swc_VCOP_swc_VCOP_Step;
    Rte_tsRB_swc_VOMM_swc_VOMM_Step Rte_swc_VOMM_swc_VOMM_Step;
}Rte_tuRB_App1_Task_10ms_Core1_QM;

typedef struct
{
    Rte_tsRB_swc_CIL_CIL_100ms Rte_swc_CIL_CIL_100ms;
    Rte_tsRB_swc_BatThermHndlgMngt_BTHM_100ms Rte_swc_BatThermHndlgMngt_BTHM_100ms;
    Rte_tsRB_swc_BatBalnCtl_BBC_100ms Rte_swc_BatBalnCtl_BBC_100ms;
    Rte_tsRB_swc_BatCoreFct_BCF_100ms Rte_swc_BatCoreFct_BCF_100ms;
    Rte_tsRB_swc_BatProtnPack_BPP_100ms Rte_swc_BatProtnPack_BPP_100ms;
    Rte_tsRB_swc_BatProtnIU_BPIU_100ms Rte_swc_BatProtnIU_BPIU_100ms;
    Rte_tsRB_swc_BatWntyLogtcData_BWLD_100ms Rte_swc_BatWntyLogtcData_BWLD_100ms;
    Rte_tsRB_swc_DiagcEveHndlg_NVM_Write_100ms Rte_swc_DiagcEveHndlg_NVM_Write_100ms;
    Rte_tsRB_swc_COL_COL_100ms Rte_swc_COL_COL_100ms;
}Rte_tuRB_App1_Task_100ms_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_DiagcEveHndlg_NVM_Read_10ms Rte_swc_DiagcEveHndlg_NVM_Read_10ms;
    Rte_tsRB_swc_CIL_CIL_10ms Rte_swc_CIL_CIL_10ms;
    Rte_tsRB_swc_DiagcEveHndlg_GetEventStatus_10ms Rte_swc_DiagcEveHndlg_GetEventStatus_10ms;
    Rte_tsRB_swc_DiagcEveHndlg_DEH_10ms Rte_swc_DiagcEveHndlg_DEH_10ms;
    Rte_tsRB_swc_BcuStTranCtl_BSTC_10ms Rte_swc_BcuStTranCtl_BSTC_10ms;
    Rte_tsRB_swc_BatChCtl_BCC_10ms Rte_swc_BatChCtl_BCC_10ms;
    Rte_tsRB_swc_BatChCtl_AC_10ms Rte_swc_BatChCtl_AC_10ms;
    Rte_tsRB_swc_BatChCtl_DC_10ms Rte_swc_BatChCtl_DC_10ms;
    Rte_tsRB_swc_CtctrTranCtl_CTC_10ms Rte_swc_CtctrTranCtl_CTC_10ms;
    Rte_tsRB_swc_BatCoreFct_BCF_10ms Rte_swc_BatCoreFct_BCF_10ms;
    Rte_tsRB_swc_DiagcEveHndlg_SetEventStatus_10ms Rte_swc_DiagcEveHndlg_SetEventStatus_10ms;
    Rte_tsRB_swc_COL_COL_10ms Rte_swc_COL_COL_10ms;
}Rte_tuRB_App1_Task_10ms_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_BatChCtl_BCC_Init Rte_swc_BatChCtl_BCC_Init;
    Rte_tsRB_swc_BatCoreFct_BCF_Init Rte_swc_BatCoreFct_BCF_Init;
    Rte_tsRB_swc_BatProtnIU_BatProtnIU_Init Rte_swc_BatProtnIU_BatProtnIU_Init;
    Rte_tsRB_swc_BatProtnPack_BPP_Init Rte_swc_BatProtnPack_BPP_Init;
    Rte_tsRB_swc_BatThermHndlgMngt_BTHM_Init Rte_swc_BatThermHndlgMngt_BTHM_Init;
    Rte_tsRB_swc_CIL_CIL_Init Rte_swc_CIL_CIL_Init;
    Rte_tsRB_swc_COL_COL_Init Rte_swc_COL_COL_Init;
    Rte_tsRB_swc_CtctrTranCtl_CTC_Init Rte_swc_CtctrTranCtl_CTC_Init;
    Rte_tsRB_swc_DiagcEveHndlg_DEH_Init Rte_swc_DiagcEveHndlg_DEH_Init;
    Rte_tsRB_swc_EltlLnkHzrdProtnNet_ELHPN_Init Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init;
}Rte_tuRB_SWC_Init_Task_Core2;

typedef struct
{
    Rte_tsRB_swc_CIL_CIL_50ms Rte_swc_CIL_CIL_50ms;
    Rte_tsRB_swc_EltlLnkHzrdProtnNet_ELHPN_50ms Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms;
    Rte_tsRB_swc_BatProtnPack_BPP_50ms Rte_swc_BatProtnPack_BPP_50ms;
    Rte_tsRB_swc_BatProtnIU_BPIU_50ms Rte_swc_BatProtnIU_BPIU_50ms;
    Rte_tsRB_swc_COL_COL_50ms Rte_swc_COL_COL_50ms;
}Rte_tuRB_App1_Task_50ms_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_BatWntyLogtcData_BWLD_1000ms Rte_swc_BatWntyLogtcData_BWLD_1000ms;
    Rte_tsRB_swc_DiagcEveHndlg_DEH_1000ms Rte_swc_DiagcEveHndlg_DEH_1000ms;
    Rte_tsRB_swc_COL_COL_1000ms Rte_swc_COL_COL_1000ms;
}Rte_tuRB_App1_Task_1000ms_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058B_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058B_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058C_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058C_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058D_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058D_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058E_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058E_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058F_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058F_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0590_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0590_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0591_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0591_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0592_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0592_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0593_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0593_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0594_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0594_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0595_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0595_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0596_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0596_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0597_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0597_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0598_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0598_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0599_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0599_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059A_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059A_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059B_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059B_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059C_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059C_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059F_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059F_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A1_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A1_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A2_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A2_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A3_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A3_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A4_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A4_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A5_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A5_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A6_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A6_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A7_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A7_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A8_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A8_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A9_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A9_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AA_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AA_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AB_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AB_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AC_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AC_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AD_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AD_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AE_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AE_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AF_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AF_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B3_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B3_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B4_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B4_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B5_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B5_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B6_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B6_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B7_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B7_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B8_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B8_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B9_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B9_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BA_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BA_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BB_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BB_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BC_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BC_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BD_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BD_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BE_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BE_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BF_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BF_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C0_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C0_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C1_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C1_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C2_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C2_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C3_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C3_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C4_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C4_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C5_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C5_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C6_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C6_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C7_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C7_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C8_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C8_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C9_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C9_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CA_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CA_22_RE;
}Rte_tuRB_App1_Task1_UDS_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services Rte_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0500_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0500_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0505_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0505_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0507_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0507_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x050A_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x050A_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0522_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0522_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0523_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0523_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0524_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0524_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0525_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0525_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0526_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0526_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0527_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0527_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0528_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0528_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0529_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0529_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052A_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052A_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052B_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052B_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052C_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052C_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052D_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052D_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052E_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052E_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0530_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0530_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0531_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0531_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0532_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0532_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0533_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0533_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0534_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0534_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0535_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0535_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0536_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0536_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0538_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0538_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0539_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0539_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053A_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053A_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053B_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053B_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053C_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053C_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053D_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053D_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053E_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053E_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0542_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0542_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0544_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0544_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0545_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0545_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0547_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0547_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055A_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055A_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055C_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055C_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055D_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055D_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0585_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0585_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0586_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0586_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0587_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0587_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0588_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0588_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0589_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0589_22_RE;
}Rte_tuRB_App1_Task0_UDS_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CC_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CC_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CD_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CD_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CE_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CE_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CF_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CF_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D0_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D0_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D1_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D1_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF00_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF00_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF05_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF05_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF06_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF06_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF07_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF07_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF09_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF09_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF00_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF00_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF01_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF01_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF03_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF03_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF04_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF04_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF06_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF06_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF09_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF09_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058A_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058A_22_RE;
    Rte_tsRB_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CB_22_RE Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CB_22_RE;
}Rte_tuRB_App1_Task2_UDS_Core2_QM;

typedef struct
{
    Rte_tsRB_swc_THSM_swc_THSM_Step Rte_swc_THSM_swc_THSM_Step;
}Rte_tuRB_App1_Task_100ms_Core1_QM;

typedef struct
{
    Rte_tuRB_Task_100us_Core3_QM Rte_RB;
}Rte_ts_Task_100us_Core3_QM;

typedef struct
{
    Rte_tuRB_App1_Task_10ms_Core1_QM Rte_RB;
}Rte_ts_App1_Task_10ms_Core1_QM;

typedef struct
{
    Rte_tuRB_App1_Task_100ms_Core2_QM Rte_RB;
}Rte_ts_App1_Task_100ms_Core2_QM;

typedef struct
{
    Rte_tuRB_App1_Task_10ms_Core2_QM Rte_RB;
}Rte_ts_App1_Task_10ms_Core2_QM;

typedef struct
{
    Rte_tuRB_SWC_Init_Task_Core2 Rte_RB;
}Rte_ts_SWC_Init_Task_Core2;

typedef struct
{
    Rte_tuRB_App1_Task_50ms_Core2_QM Rte_RB;
}Rte_ts_App1_Task_50ms_Core2_QM;

typedef struct
{
    Rte_tuRB_App1_Task_1000ms_Core2_QM Rte_RB;
}Rte_ts_App1_Task_1000ms_Core2_QM;

typedef struct
{
    Rte_tuRB_App1_Task1_UDS_Core2_QM Rte_RB;
}Rte_ts_App1_Task1_UDS_Core2_QM;

typedef struct
{
    Rte_tuRB_App1_Task0_UDS_Core2_QM Rte_RB;
}Rte_ts_App1_Task0_UDS_Core2_QM;

typedef struct
{
    Rte_tuRB_App1_Task2_UDS_Core2_QM Rte_RB;
}Rte_ts_App1_Task2_UDS_Core2_QM;

typedef struct
{
    Rte_tuRB_App1_Task_100ms_Core1_QM Rte_RB;
}Rte_ts_App1_Task_100ms_Core1_QM;


/*
************************************************************************************************************************
*    extern Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
#if 0 //UDS不使用
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x1002_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x1003_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x11_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x14_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x22_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x27_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x28_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x2E_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x31_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x85_Operation;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4000_Start;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x400F_Start;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_DTC_0x0402_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData;
extern VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData;
extern VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#endif

/*
************************************************************************************************************************
*    extern declaration of Calibration component and SW-C local calibration parameters
************************************************************************************************************************
*/
#define RTE_START_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(sint32, RTE_VAR_INIT) XcpCalOffset;
#define RTE_STOP_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    extern declaration Rte_Pim (Per-Instance Memory)
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(rt_Array_UInt8_4, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D5_Ram;
extern VAR(rt_Array_UInt8_4, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D6_Ram;
extern VAR(rt_Array_UInt8_3, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D7_Ram;
extern VAR(rt_Array_UInt8_2, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D8_Ram;
extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D9_Ram;
extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05DA_Ram;
extern VAR(rt_Array_UInt8_24, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05DB_Ram;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App1;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App2;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App3;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App4;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App5;
extern VAR(rt_Array_UInt8_17, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_F190_Ram;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    extern declarations of RTE internal variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declarations of RTE PRPort variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Data type definitions of Update Flag
************************************************************************************************************************
*/
typedef struct
{
    Rte_BitType Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileDay_PMS_SWCompileDay : 2;
    Rte_BitType Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileMonth_PMS_SWCompileMonth : 2;
    Rte_BitType Rte_TxUpdate_PMS_BswAswRte_PMS_SWCompileYear_PMS_SWCompileYear : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_AC_EWP_Run_AC_EWP_Run : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMSH_stMode_BMSH_stMode : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_EDCP_Flt_EDCP_Flt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_HBCP_Flt_HBCP_Flt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Acceleration_PMS_Acceleration : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AppSts_PMS_AppSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AuthResult_PMS_AuthResult : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1 : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2 : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CPSREn_PMS_CPSREn : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CPSRU_PMS_CPSRU : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ErrCode_PMS_ErrCode : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVILSts_PMS_HVILSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Life_PMS_Life : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_LockVehType_PMS_LockVehType : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_RespResult_PMS_RespResult : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_StartActive_PMS_StartActive : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_StsSwap_PMS_StsSwap : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2 : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1 : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ePTFault_PMS_ePTFault : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2 : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ePTReady_PMS_ePTReady : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual : 2;
    Rte_BitType Rte_TxUpdate_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum : 2;
} Rte_App1_Application_Core1_QM_TxUpdateFlagsType;

typedef struct
{
    Rte_BitType Rte_TxUpdate_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq : 2;
    Rte_BitType Rte_TxUpdate_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatSOE_BMSH_BatSOE : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatSOH_BMSH_BatSOH : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BusVolt_BMSH_BusVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CoolType_BMSH_CoolType : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FaultCode_BMSH_FaultCode : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_IntComFault_BMSH_IntComFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode1_BMSH_PackCode1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode2_BMSH_PackCode2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode3_BMSH_PackCode3 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode4_BMSH_PackCode4 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode5_BMSH_PackCode5 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode6_BMSH_PackCode6 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode7_BMSH_PackCode7 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackType_BMSH_PackType : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackVolt_BMSH_PackVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsCC2_BMSH_StsCC2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsMode_BMSH_StsMode : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattTemp1_BMS_BattTemp1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattTemp2_BMS_BattTemp2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattTemp3_BMS_BattTemp3 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattTemp4_BMS_BattTemp4 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattTemp5_BMS_BattTemp5 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_BattTemp6_BMS_BattTemp6 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CCvalue_BMS_CCvalue : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CP_Duty_BMS_CP_Duty : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CP_Vol_BMS_CP_Vol : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_ChgStatus_BMS_ChgStatus : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_DelayControl_BMS_DelayControl : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_S2STATUS_BMS_S2STATUS : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1 : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req : 2;
    Rte_BitType Rte_TxUpdate_swc_COL_HvSysSample_DisableIso_DisableIso : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_ChargingMode_ChargingMode : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_CurrentDemand_CurrentDemand : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCL_VoltageDemand_VoltageDemand : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermChargingCurrent_MaxPermChargingCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxPermTemperature_MaxPermTemperature : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCP_TotalNominalEnergy_TotalNominalEnergy : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_CurrentChargeState_CurrentChargeState : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingCurrent_MeasuredChargingCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_MeasuredChargingVoltage_MeasuredChargingVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BCS_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CCS_Timeout_CCS : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Recognized_Timeout_CRM_Recognized : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CRO_Timeout_CRO : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CSD_Timeout_CSD : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CST_Timeout_CST : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BEM_Timeout_CTS_CML_Timeout_CTS_CML : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BHM_MaxChargingVoltage_MaxChargingVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_BMSStopChgReason_BMS_BMSStopChgReason : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BMS_CCUStopChgReason_BMS_CCUStopChgReason : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemCapacity_BatterySystemCapacity : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatterySystemVoltage_BatterySystemVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BRM_BatteryType_BatteryType : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BRO_BmsReadyForCharging_BmsReadyForCharging : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinTemperature_SingleBatteryMinTemperature : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SingleBatteryMinVoltage_SingleBatteryMinVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSD_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryChargingOvercurrent_BatteryChargingOvercurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryExcessTemperature_BatteryExcessTemperature : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTemp_BatteryHighestTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryHighestTempSerNo_BatteryHighestTempSerNo : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryInsulationState_BatteryInsulationState : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTemp_BatteryLowestTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryLowestTempSerNo_BatteryLowestTempSerNo : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BatteryOutputConnectorState_BatteryOutputConnectorState : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_BsmChargingPermissible_BsmChargingPermissible : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BSM_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SOC_BmsSuspCause_SOC : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_Insulation_BmsSuspFault_Insulation : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BST_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay : 2;
    Rte_BitType Rte_TxUpdate_swc_SetSendCANMsg_S_BmsProtocolVersion_BmsProtocolVersion : 2;
} Rte_App1_Application_Core2_QM_TxUpdateFlagsType;

typedef struct
{
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter : 2;
    Rte_BitType Rte_TxUpdate_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter : 2;
} Rte_App1_Application_Core4_QM_TxUpdateFlagsType;

typedef struct
{
    Rte_BitType Rte_TxUpdate_ComRx_CAN_BMSH_Status_CheckSum_Rx_BMSH_Status_CheckSum_Rx : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_ActiveDischgFlt_IPU_ActiveDischgFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_BattFaultLampState_IPU_BattFaultLampState : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_BusUndervolt_IPU_BusUndervolt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_CANCommFlt_IPU_CANCommFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_DTC_IPU_DTC : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_DischgState_IPU_DischgState : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_HVBusCur_IPU_HVBusCur : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_20_IPU_HVBusVolt_20 : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_HVBusVolt_500_IPU_HVBusVolt_500 : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_HardwareCapOverVolt_IPU_HardwareCapOverVolt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IGBTFlt_IPU_IGBTFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrT_IPU_IsgInvrT : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgInvrTInvalid_IPU_IsgInvrTInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgModSts_IPU_IsgModSts : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgModStsInvalid_IPU_IsgModStsInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgMotT_IPU_IsgMotT : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgMotTInvalid_IPU_IsgMotTInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgOverTemp_IPU_IsgOverTemp : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgn_IPU_IsgSpdActSgn : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgSpdActSgnInvalid_IPU_IsgSpdActSgnInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqAct_IPU_IsgTqActIsgTqAct : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_IsgTqActIsgTqActInvalid_IPU_IsgTqActIsgTqActInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_LV_VotagtFault_IPU_LV_VotagtFault : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MCUMemoryFlt_IPU_MCUMemoryFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm_IPU_MCUTempHighAlarm : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighAlarm1_IPU_MCUTempHighAlarm1 : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MCUTempHighFault_IPU_MCUTempHighFault : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MCUTempSensorErr_IPU_MCUTempSensorErr : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell1_IPU_MotorFltLevell1 : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorFltLevell_Invalid_IPU_MotorFltLevell_Invalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorLockRotErr_IPU_MotorLockRotErr : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorNum_IPU_MotorNum : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorNumSN_IPU_MotorNumSN : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorOverCurrFlt_IPU_MotorOverCurrFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorOverSpdFlt_IPU_MotorOverSpdFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorSpdHighAlarm_IPU_MotorSpdHighAlarm : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorSts_IPU_MotorSts : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighAlarm_IPU_MotorTempHighAlarm : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault_IPU_MotorTempHighFault : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorTempHighFault1_IPU_MotorTempHighFault1 : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorTempSensorErr_IPU_MotorTempSensorErr : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_MotorUCurrSensorFlt_IPU_MotorUCurrSensorFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_Motor_Phase_Curr_IPU_Motor_Phase_Curr : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_PCOCHW_Fault_IPU_PCOCHW_Fault : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_PCOCSW_Fault_IPU_PCOCSW_Fault : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_PreventSlipFlag_IPU_PreventSlipFlag : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_RotateInverterFlt_IPU_RotateInverterFlt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_SelfChkSts_IPU_SelfChkSts : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_SoftwareCapOverVolt_IPU_SoftwareCapOverVolt : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_Sts_Checksum_IPU_Sts_Checksum : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMax_IPU_TqAvlIsgMax : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMaxInvalid_IPU_TqAvlIsgMaxInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMin_IPU_TqAvlIsgMin : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_TqAvlIsgMinInvalid_IPU_TqAvlIsgMinInvalid : 2;
    Rte_BitType Rte_TxUpdate_ComTx_CAN_IPU_TrqSpd_CheckSum_IPU_TrqSpd_CheckSum : 2;
} Rte_App1_Application_Core5_QM_TxUpdateFlagsType;


/*
************************************************************************************************************************
*    Data type definitions of Timeout Flag
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Data type definitions of Invalid Flag
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Data type definitions of Never Receive Flag
************************************************************************************************************************
*/

/* 
************************************************************************************************************************ 
*    extern declaration of Buffer for Tx Confirmation Flag 
************************************************************************************************************************ 
*/
/*
************************************************************************************************************************
*    extern declaration of Buffer for IOC and TxUpdate variables
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_App1_Application_Core1_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core1_QM_TxUpdateFlags;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_App1_Application_Core2_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core2_QM_TxUpdateFlags;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_App1_Application_Core4_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core4_QM_TxUpdateFlags;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_App1_Application_Core5_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core5_QM_TxUpdateFlags;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    extern declaration of Buffer for Invalid variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of Buffer for Com Call Back variables
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_SelfChkSts_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_ACCM1_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_ACU_CrashOutputSts_ACU_ChimeTelltaleReq_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_ACCM_Status_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_CabinThermalReq_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_CoolingFanPWMSpd_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_IPTC_ActPower_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_IPTC_WorkSts_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_ActPower_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_ActPwr_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_WorkSts_AC_Status_SE_ACCM_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_PTC_WorkSts_Rear_AC_Status_Info1_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BBM_FaultStatus_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BBM_WorkSts_BBM_StsFB_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_ATWS_St_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_DrvSeatbeltBuckleInvalid_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_DrvSeatbeltBucklestatus_BCM_StateUpdate_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_FrontLeftDoorAjarStatus_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_FrontRightDoorAjarStatus_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_BCM_IntelligentChargeCommand_BCM_ACCinfor_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_BCM_Odometerbackup_BCM_SunroofState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_CampModeSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_CampModeSwtInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_DriveModeReq_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_DriveModeReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_EngRec_Req_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_EngRec_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_TakeEleSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_TakeEleSwt_ReqInvalid_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_CSM_V2XDchaSwt_CSM_SwitchSts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_AccessoryConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_CANComFault_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_CutOffLVFb_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_FaultLevel1_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_IDCDCActHiside1_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_IDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_OutOverCurr_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DCDC_OutOverVolt_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_PTCConnStsFb_DCDC_FaultInfo_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_DCDC_Relay_Volt_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_TDcDc_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_DCDC_UDCDCActHiside_DCDC_HV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_DCDC_UDcDcActLoSide_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DcDcActvd_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_DcDcStsAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_LeverPosition_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_ParkReq_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EGSM_ShiftleverFailSt_EGSM_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ABSActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ABSFailed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_AEB_active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_AVHStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_BrkSysErrFault_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_DTC_Active_EHB_DA_MESSAGE_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBErrorStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPB_DynamicApplystatus_EHB_DriverRemind_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_HHCActive_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_PTTrqDecReq_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_PTTrqDecReqActive_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_ISA_Status_EHB_ISARequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_MbRegenTargetWheel_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_MbRegenTargetWheelSts_EHB_Regen_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqDecReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqDecReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqIncReq_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_PTTrqIncReqActive_EHB_PTTorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_Active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_Available_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_CDD_active_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_PTTrqReq_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VLC_PTTrqReqActive_EHB_VLC_TorqueRequest_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EWP_HeatPower_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EWP_OutputTemp_HEWP_1_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_CCWFlg_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_FWFV_CurrentPos_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_InitState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_MotorState_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverCurrentFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverTempFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_OverVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_RESP_ERROR_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_FWFV_UnderVoltageFlt_FWFV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_AcceRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_AcceRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosBackVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_PTCRelayVolt_HCM_Other2RelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_HCM_PTCRelayVoltValidStat_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_IPK_AllowChgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_IPK_ChrgSoftSwCtrlSt_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_EngRecMode_Req_IPK_Infor_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_IPK_IPKTotalOdometer_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_IPK_Odometerbackup_IPK_TotalOdometer_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_CCWFlg_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_MHGV_CurrentPos_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_InitState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_MotorState_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverCurrentFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverTempFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_OverVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_RESP_ERROR_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_MHGV_UnderVoltageFlt_MHGV_Status_VE21_N72_PMS_LIN_ldf_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_MMI_LocalBookChrgnTarVal_MMI_SOCSet_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_MMI_RestSwitch_MMI_HVSM_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_LockLoopSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdChrgrT_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_PwrEgyMgrAvl_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_SelfCheSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_ODP_DCDC_TDcDcAlm_DCDC_LV_Info_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_PDC_Brake_Flag_PDC_Status_Info_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_RKECommand_PEPS_KeyReminder_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_PEPS_RemoteControlSt_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_RFR_ConnectionStatus_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_RFR_Seed_RFR_Seed_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint64, RTE_VAR_INIT) Rte_ComBuffer_RFR_SwapBatCode_RFR_SwapBatCode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_CarLocationConfirm_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_CarStation_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_Station_SwapBatRequest_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_Station_Swapingproceeding_Station_Status_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_AllowChgCurrentMax_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChargeDepth_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChargeLimitSwitch_TBOX_ChgLimit_Command_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Elevation_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_FunAnti_DismantleActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_FunLockVehActive_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_InventorySpdLmtReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Life_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockLimSet_TBOX_VCULockResp_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehCtrl_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehPerFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_LockVehType_TBOX_LockVehCtrl_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PowerOffCmd_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PriorityFullSwitchSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_TBOX_PriorityFullSwitchSts_UB_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_SpdLmtLevelReq_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_VersionConversionFlag_TBOX_instruct_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_YRS_LongitAcce_YRS2_N72__PMS_C_CAN_20260425_dbc_Rx;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_DoorLockStatusDrv_BCM_LDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_BCM_DoorLockStatusPass_BCM_RDoorWindowState_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CRO_ChargerReady_CRO_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_CHM_ProtocolVersion_CHM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CCS_ChargeAllow_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortByUser_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortAchiveCondition_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortByFault_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortErrorVoltage_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortErrorCurrent_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultEnergeTransmit_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultConnetor_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerInnerTemp_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultOther_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CST_AbortFaultChargerStop_CST_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_ChargeTotalTime_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_OutputCurrent_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_TotalCurr_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_HCM_ShuntTemp_HCM_Status_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_NegInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_PosInsulateVal_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_FastChgBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosBackVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainNegBackVolt_HCM_OtherRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint32, RTE_VAR_INIT) Rte_ComBuffer_HCM_InsulateCounter_HCM_InsulateaValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_HCM_MainPosFrtVolt_HCM_MainRelayValue_N72_HCM__Matrix_V1_1_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Day_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Hour_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Minute_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Month_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Second_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_IPK_Year_IPK_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputCurrentMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutpuVoltageMax_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputCurrentMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CML_OutputVoltageMin_CML_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_CCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChgCCSts_OBC_Failmode_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_ChrgrSt_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_DischargeCCvalue_OBC_Status2_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_Elock_Stmode_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCCline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdCPline_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdDisChrgrCCline_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptI_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_OnBdOuptU_OBC_Sts_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_OBC_uInAct_OBC_Curr_PMS_EV_CAN_20260427_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CSD_OutputEnerge_CSD_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CRM_RecognitionResult_CRM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ChrgSoftSwCtrlSt_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_ReservationChrgnSts_TBOX_RemCon_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryChargeRequireTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryParameterTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BatteryStateTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSIdentifyTimout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSFinishChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSChargeStatisticsTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_CEM_BMSAbortChargeTimeout_CEM_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_CCS_OutputVoltage_CCS_ATOM_CAN_Matrix_DC_V2_0_20250922_ATOM_dbc_Rx;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperature_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_AC_AmbientTemperatureInvalid_AC_Status_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_EPBStatus_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FLWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelDirection_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedInvalid_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_FRWheelSpeedKPH_EHB_FrontWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RLWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelDirection_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedInvalid_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_RRWheelSpeedKPH_EHB_RearWheelSpeedsKPH_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint16, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeed_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(boolean, RTE_VAR_INIT) Rte_ComBuffer_EHB_VehicleSpeedInvalid_EHB_Status_N72__PMS_C_CAN_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerMode_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_PEPS_PowerModeValidity_PEPS_Message_Sts_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Day_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Hour_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Minute_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Month_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Second_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
extern VAR(uint8, RTE_VAR_INIT) Rte_ComBuffer_TBOX_Year_TBOX_DateTime_Info_N72__PMS_PT_CANFD_20260425_dbc_Rx;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    extern declaration of Buffer for inter-runnable variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declarations of RTE implicit variables
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Heat_AC_EWP_Heat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_AC_EWP_HeatrPwrCnsAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Run_AC_EWP_Run;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_SpeedReq_AC_EWP_SpeedReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Temp_AC_EWP_Temp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ACChgTimeRemain_BMSH_ACChgTimeRemain;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattCurr_BMSH_BattCurr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattFaultLampState_BMSH_BattFaultLampState;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattPackNum_PMS_BMSH_BattPackNum_PMS;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattRemainEnergy_BMSH_BattRemainEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSOC_BMSH_BattSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSOH_BMSH_BattSOH;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattSysNum_PMS_BMSH_BattSysNum_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattTempAvg_PT_BMSH_BattTempAvg_PT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_BattVolt_BMSH_BattVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_CellTemp_Uniformity_BMSH_CellTemp_Uniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_CellVolt_Uniformity_BMSH_CellVolt_Uniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_OverVol_BMSH_Cell_OverVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_TotalNum_BMSH_Cell_TotalNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Cell_UnderVol_BMSH_Cell_UnderVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChargeLEDCtrl_BMSH_ChargeLEDCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChargeToBeFinished_BMSH_ChargeToBeFinished;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Charge_Over_Current_BMSH_Charge_Over_Current;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ChgTimeRemain_BMSH_ChgTimeRemain;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_DCChgminusSocketTempSensing_Failure_BMSH_DCChgminusSocketTempSensing_Failure;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_DCChgplusSocketTempSensing_Failure_BMSH_DCChgplusSocketTempSensing_Failure;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_FastChgCC2ConntState_BMSH_FastChgCC2ConntState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HVBusVolt_BMSH_HVBusVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvBattCooltTReq_BMSH_HvBattCooltTReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvBattThermMod_BMSH_HvBattThermMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_HvShutdownReq_BMSH_HvShutdownReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ICU_BatteryElectricDTE_BMSH_ICU_BatteryElectricDTE;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Inlet_WaterTemp_BMSH_Inlet_WaterTemp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_InsulationRes_BMSH_InsulationRes;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_InsulationRes_Fault_BMSH_InsulationRes_Fault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Low_SOC_BMSH_Low_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Outlet_WaterTemp_BMSH_Outlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Over_SOC_BMSH_Over_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Over_Temperature_BMSH_Over_Temperature;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Pack_OverVoltage_BMSH_Pack_OverVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Pack_UnderVoltage_BMSH_Pack_UnderVoltage;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_SOC_Hop_BMSH_SOC_Hop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm2_PT_BMSH_TBOX_BatIsoAlarm2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatIsoAlarm3_PMS_BMSH_TBOX_BatIsoAlarm3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatLowSOC2_PT_BMSH_TBOX_BatLowSOC2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatLowSOC3_PMS_BMSH_TBOX_BatLowSOC3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverCharge2_PT_BMSH_TBOX_BatOverCharge2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverCharge3_PMS_BMSH_TBOX_BatOverCharge3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverSOC2_PT_BMSH_TBOX_BatOverSOC2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverSOC3_PMS_BMSH_TBOX_BatOverSOC3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverTemp2_PT_BMSH_TBOX_BatOverTemp2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverTemp3_PMS_BMSH_TBOX_BatOverTemp3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage2_PT_BMSH_TBOX_BatOverVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatOverVoltage3_PMS_BMSH_TBOX_BatOverVoltage3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity2_PT_BMSH_TBOX_BatTempUniformity2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatTempUniformity3_PMS_BMSH_TBOX_BatTempUniformity3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage2_PT_BMSH_TBOX_BatUnderVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUnderVoltage3_PMS_BMSH_TBOX_BatUnderVoltage3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUniformity2_PT_BMSH_TBOX_BatUniformity2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_BatUniformity3_PMS_BMSH_TBOX_BatUniformity3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage2_PT_BMSH_TBOX_CellOverVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellOverVoltage3_PMS_BMSH_TBOX_CellOverVoltage3_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage2_PT_BMSH_TBOX_CellUnderVoltage2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_CellUnderVoltage3_PMS_BMSH_TBOX_CellUnderVoltage3_PMS;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_FireAlarm2_PMS_BMSH_TBOX_FireAlarm2_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_SOCHop2_PT_BMSH_TBOX_SOCHop2_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TBOX_SOCHop3_PMS_BMSH_TBOX_SOCHop3_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_MaxTemp_BMSH_TempSensor_MaxTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_MinTemp_BMSH_TempSensor_MinTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_TempSensor_TotalNum_BMSH_TempSensor_TotalNum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_ThermalOutofControl_BMSH_ThermalOutofControl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Vehicle_HVILSts_PHEV_BMSH_Vehicle_HVILSts_PHEV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_VoltCurr_Checksum_BMSH_VoltCurr_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_stMode_BMSH_stMode;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_BMS_BattPackMatchFault_BMS_BattPackMatchFault;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_BMS_BattPackMatchFault1_PMS_BMS_BattPackMatchFault1_PMS;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxCellVolt_BMS_MaxCellVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxTemp1SnsNum_BMS_MaxTemp1SnsNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MaxVoltCellNum_BMS_MaxVoltCellNum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinCellVolt_BMS_MinCellVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinVoltCellNum_BMS_MinVoltCellNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMS_MinxTemp1SnsNum_BMS_MinxTemp1SnsNum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_DrvPfmncRedn_DrvPfmncRedn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_EDCP_Flt_EDCP_Flt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_EDCP_PWMFB_EDCP_PWMFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_HBCP_Flt_HBCP_Flt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_HBCP_PWMFB_HBCP_PWMFB;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_IPK_IPKTotalOdometer_EV_IPK_IPKTotalOdometer_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_IPU_HVBusCur_PT_IPU_HVBusCur_PT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_IPU_HVBusVolt_PT_IPU_HVBusVolt_PT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_IPUTAlm_IPU_IPUTAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MCUTempHighAlarm1_PT_IPU_MCUTempHighAlarm1_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MCUTempHighAlarm2_PMS_IPU_MCUTempHighAlarm2_PMS;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorOverCurrFlt1_PMS_IPU_MotorOverCurrFlt1_PMS;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorOverSpdFlt1_PMS_IPU_MotorOverSpdFlt1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorTempHighFault1_PT_IPU_MotorTempHighFault1_PT;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_IPU_MotorTempHighFault2_PMS_IPU_MotorTempHighFault2_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_CCWFlg_PMS_MHGV_CCWFlg_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_CurrentPos_PMS_MHGV_CurrentPos_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_InitState_PMS_MHGV_InitState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_MotorState_PMS_MHGV_MotorState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverCurrentFlt_PMS_MHGV_OverCurrentFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverTempFlt_PMS_MHGV_OverTempFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_OverVoltageFlt_PMS_MHGV_OverVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_RESP_ERROR_PMS_MHGV_RESP_ERROR_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_MHGV_UnderVoltageFlt_PMS_MHGV_UnderVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm_ODP_TBOX_DcDcStsAlm;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_DcDcStsAlm1_PMS_ODP_TBOX_DcDcStsAlm1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_TDcDcAlm_ODP_TBOX_TDcDcAlm;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_ODP_TBOX_TDcDcAlm1_PMS_ODP_TBOX_TDcDcAlm1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_0X16A_TimeoutFlag_PMS_0X16A_TimeoutFlag;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_32960FltNum_PMS_PMS_32960FltNum_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC1PosVol_PMS_ACC1PosVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC2PosVol_PMS_ACC2PosVol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACCMEnable_PMS_ACCMEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ACC_BeControlled_Status_PMS_ACC_BeControlled_Status;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AcceRelayVoltSampSwich_PMS_AcceRelayVoltSampSwich;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AcceSuppressionSts_PMS_PMS_AcceSuppressionSts_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccelPedalPosition_PMS_AccelPedalPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccelPedalPositionInvalid_PMS_AccelPedalPositionInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Acceleration_PMS_Acceleration;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryConnStsFb_PMS_AccessoryConnStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryCtrlCommand_PMS_AccessoryCtrlCommand;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AccessoryRelayFlt_PMS_AccessoryRelayFlt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ActualPTTorque_PMS_ActualPTTorque;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ActualPTTorqueInvalid_PMS_ActualPTTorqueInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AppSts_PMS_AppSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AuthResult_PMS_AuthResult;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AveragePowerConsumption_PMS_AveragePowerConsumption;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM1CtrlCmd_PMS_BBM1CtrlCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBMAllowEnable_Ctrl_PMS_BBMAllowEnable_Ctrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBMPowerSupplyEn_Ctrl_PMS_BBMPowerSupplyEn_Ctrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_FaultStatus_PMS_BBM_FaultStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_HVReq_PMS_BBM_HVReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BBM_WorkSts_PMS_BBM_WorkSts;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattRemainEnergy_PMS_BMSH_BattRemainEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattSOCDisp_PMS_BMSH_BattSOCDisp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMSH_BattSOH_PMS_BMSH_BattSOH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMS_Reignstatus1_PMS_BMS_Reignstatus1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BMS_Reignstatus2_PMS_BMS_Reignstatus2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatCoolType_PMS_BatCoolType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BattPackInCoolTempback_EV_PMS_BattPackInCoolTempback_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BattPackOutCoolTempback_EV_PMS_BattPackOutCoolTempback_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BatteryVol_PMS_BatteryVol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake_LightsRequest_PMS_Brake_LightsRequest;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_BrkSysErr_PMS_BrkSysErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CANBus_RecSta_PMS_CANBus_RecSta;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSREn_PMS_CPSREn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CPSRU_PMS_CPSRU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl1_CheckSum_PMS_CSControl1_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl2_CheckSum_PMS_CSControl2_CheckSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CampModeFb_PMS_CampModeFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CampModeFbFailrReason_PMS_CampModeFbFailrReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargPwr_PMS_ChargPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargWakeupSts_PMS_ChargWakeupSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargeHV_Status_PMS_ChargeHV_Status;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargeLimitResponse_PMS_ChargeLimitResponse;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ChargerFault_PMS_ChargerFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_PMS_Command_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanFaultFB_PMS_CoolingFanFaultFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CoolingFanPWMSpd_PMS_CoolingFanPWMSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Ctrl_Checksum_PMS_Ctrl_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_PMS_CurrentGearPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_PMS_CurrentGearPosition_Valid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCAwake_HW_PMS_DCDCAwake_HW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCCutOffLV_PMS_DCDCCutOffLV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDCPwrLmt_PMS_DCDCPwrLmt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DDwaterPump_PWMCtrl_EV_PMS_DDwaterPump_PWMCtrl_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDcActvdReq_PMS_DcDcActvdReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DisChrgrSwtSt_PMS_DisChrgrSwtSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DischargeEnable_PMS_DischargeEnable;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DoubleFlashLampOn_PMS_DoubleFlashLampOn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_PMS_DriveCircuitTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveModeInd_PMS_DriveModeInd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorque_PMS_DriverDemandTorque;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverDemandTorqueInvalid_PMS_DriverDemandTorqueInvalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverGearAbort_PMS_DriverGearAbort;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DrivingTakeEleSts_PMS_DrivingTakeEleSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DrvrGearLvrLockIndcn_PMS_DrvrGearLvrLockIndcn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_PMS_EDCPEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_PMS_EDCPPWMCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCP_FaultFB_PMS_EDCP_FaultFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCP_PWMCtrl_PMS_EDCP_PWMCtrl;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPS_SteeringAngleValue_PMS_EPS_SteeringAngleValue;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EVDTEodometer_PMS_EVDTEodometer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngControl_CheckSum_PMS_EngControl_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngRecMode_Fb_PMS_EngRecMode_Fb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngTrqReqSrc_PMS_EngTrqReqSrc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ErrCode_PMS_ErrCode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FAN_PWMCtrl_PMS_FAN_PWMCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Fn1GearRlyDrvStsFb_PMS_Fn1GearRlyDrvStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Fn2GearRlyDrvStsFb_PMS_Fn2GearRlyDrvStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatModEnad_PMS_FrntHeatModEnad;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FrntHeatPwrAllwd_PMS_FrntHeatPwrAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunAnti_DismantleActive_PMS_FunAnti_DismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FunLockVehActive_PMS_FunLockVehActive;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GP_Ovrd_PMS_GP_Ovrd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GearOperateErr_PMS_GearOperateErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Gear_intervene_PMS_Gear_intervene;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_GrossComVehWeight_PMS_GrossComVehWeight;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPEnable_PMS_HBCPEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCPPWMCtrl_PMS_HBCPPWMCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCP_FaultFB_PMS_HBCP_FaultFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HBCP_PWMCtrl_PMS_HBCP_PWMCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_PMS_HVIL1Sts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL1Sts_UB_PMS_HVIL1Sts_UB;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_PMS_HVIL2Sts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVIL2Sts_UB_PMS_HVIL2Sts_UB;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVILSts_PMS_HVILSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVILSts_UB_PMS_HVILSts_UB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HVPRASts_PMS_HVPRASts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HardwareMajorVer_PMS_HardwareMajorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HardwareMinorVer_PMS_HardwareMinorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvCoolgPwrAllwd_PMS_HvCoolgPwrAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvHeatgPwrAllwd_PMS_HvHeatgPwrAllwd;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPKTotalOdometer_PMS_IPKTotalOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IPK_HandBrakeSts_PMS_IPK_HandBrakeSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IgnONSts_PMS_IgnONSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeExitReq_PMS_IntelligentChargeExitReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeQuit_PMS_IntelligentChargeQuit;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IntelligentChargeState_PMS_IntelligentChargeState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_InventorySpdLmtRxSts_PMS_InventorySpdLmtRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_InventorySpdLmtSts_PMS_InventorySpdLmtSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgActvDampgModReq_PMS_IsgActvDampgModReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgModReq_PMS_IsgModReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_IsgTqReq_PMS_IsgTqReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LTCoolingFanFB_PMS_LTCoolingFanFB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Life_PMS_Life;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LimpHomeSts_PMS_LimpHomeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockLimResult_PMS_LockLimResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehExecutedSts_PMS_LockVehExecutedSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehPerFlag_PMS_LockVehPerFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehPerRxSts_PMS_LockVehPerRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehSts_PMS_LockVehSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_LockVehType_PMS_LockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUFlowFeedback_EV_PMS_MCUFlowFeedback_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_EnableReq_PMS_MHGV_EnableReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_PosSet_PMS_MHGV_PosSet;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_PMS_MHGV_ReqMotorEmgyStop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_PMS_MHGV_ReqMotorOptRecovery;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MaxPTTorqueAllowed_PMS_MaxPTTorqueAllowed;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MinPTTorqueAllowed_PMS_MinPTTorqueAllowed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeControl_CheckSum_PMS_ModeControl_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeGearDisplaySts_PMS_ModeGearDisplaySts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_NMSts_PMS_NMSts;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OTAInstrucStsReminder_PMS_OTAInstrucStsReminder;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OTAInstructRxnSts_PMS_OTAInstructRxnSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_OdometerbackupEnable_PMS_OdometerbackupEnable;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPSAuth_PMS_PEPSAuth;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_0x1E2_TimeoutFlag_PMS_PEPS_0x1E2_TimeoutFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_PowerMode_PMS_PEPS_PowerMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PEPS_PowerModeValidity_PMS_PEPS_PowerModeValidity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC1ConnStsFb_PMS_PTC1ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC1RelayFlt_PMS_PTC1RelayFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC2Enable_PMS_PTC2Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3ConnStsFb_PMS_PTC3ConnStsFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3Enable_PMS_PTC3Enable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTC3RelayFlt_PMS_PTC3RelayFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCEnable_PMS_PTCEnable;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTCRelayVoltSampSwich_PMS_PTCRelayVoltSampSwich;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PTResiduePwrInd_PMS_PTResiduePwrInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PowerOffCmdRxSts_PMS_PowerOffCmdRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PowerOffCmdSts_PMS_PowerOffCmdSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PreAccessoryConnStsFb_PMS_PreAccessoryConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_PreAccessoryRelayFlt_PMS_PreAccessoryRelayFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPosition_PMS_Real_PedalPosition;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Real_PedalPositionInvalid_PMS_Real_PedalPositionInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTarTrqPot_PMS_RegenTarTrqPot;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTarTrqPotQualifier_PMS_RegenTarTrqPotQualifier;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqAct_PMS_RegenTrqAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqActQualifier_PMS_RegenTrqActQualifier;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqPot_PMS_RegenTrqPot;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegenTrqPotQualifier_PMS_RegenTrqPotQualifier;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RegulationSpeed_PMS_PMS_RegulationSpeed_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RemChrgCmdFailrPrompt_PMS_RemChrgCmdFailrPrompt;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ReqSeed_PMS_ReqSeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_RespResult_PMS_RespResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SelfCheckSts_PMS_SelfCheckSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SoftwareMajorVer_PMS_SoftwareMajorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SoftwareMinorVer_PMS_SoftwareMinorVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SpdLmtLevel_PMS_SpdLmtLevel;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SpdLmtLevelRxSts_PMS_SpdLmtLevelRxSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StartActive_PMS_StartActive;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Stayawake_reasons_PMS_Stayawake_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_StsBrkSwitch1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_StsBrkSwitch1Invalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1Invalid_PMS_PMS_StsBrkSwitch1Invalid_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsBrkSwitch1_PMS_PMS_StsBrkSwitch1_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_StsSwap_PMS_StsSwap;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SwapAuthRelease_EV_PMS_SwapAuthRelease_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_BrkSysErr_PMS_TBOX_BrkSysErr;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_BrkSysErr1_PMS_PMS_TBOX_BrkSysErr1_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILSts_PMS_TBOX_HVILSts;
extern VAR(Double, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILSts1_PMS_PMS_TBOX_HVILSts1_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_LifeSts_PMS_TBOX_LifeSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TakeEleSwtIndReq_PMS_TakeEleSwtIndReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Torque_Ovrd_Active_PMS_Torque_Ovrd_Active;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Torque_Ovrd_Type_PMS_Torque_Ovrd_Type;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TurtleLampOn_PMS_TurtleLampOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TurtleLampOn2_PMS_TurtleLampOn2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_V2XDchaSwtFb1_PMS_V2XDchaSwtFb1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode1_8_15_S_PMS_VINCode1_8_15_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode2_9_16_S_PMS_VINCode2_9_16_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode3_10_17_S_PMS_VINCode3_10_17_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode4_11_S_PMS_VINCode4_11_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode5_12_S_PMS_VINCode5_12_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode6_13_S_PMS_VINCode6_13_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINCode7_14_S_PMS_VINCode7_14_S;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VINMessageNum_S_PMS_VINMessageNum_S;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPressure_PMS_VacuumPressure;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPumpCmd_PMS_VacuumPumpCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumPump_FB_PMS_VacuumPump_FB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VacuumSystemsta_PMS_VacuumSystemsta;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeed_PMS_VehicleSpeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_PMS_PMS_VehicleSpeedInvalid_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevel_PMS_VehicleSysErrorLevel;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevelG_PMS_VehicleSysErrorLevelG;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSysErrorLevelG1_PMS_PMS_VehicleSysErrorLevelG1_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VersionConversionFlag_PMS_VersionConversionFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VersionConversionRxSts_PMS_VersionConversionRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Wakeup_reasons_PMS_Wakeup_reasons;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ZeroPwr_Fb_PMS_ZeroPwr_Fb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTFault_PMS_ePTFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTFault2_PMS_ePTFault2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTModeActual_PMS_ePTModeActual;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTModeSelect_PMS_ePTModeSelect;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_PMS_ePTReady;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReleaseSig_PMS_ePTReleaseSig;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_TBOX_ChrgSoftSwCtrlst_EV_TBOX_ChrgSoftSwCtrlst_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_TBOX_ReservationChrgnSts_EV_TBOX_ReservationChrgnSts_EV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ActInputVolt_VCU_ActInputVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_AllowChgCurrentMax_VCU_BMSH_AllowChgCurrentMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Ctrl_CheckSum_VCU_BMSH_Ctrl_CheckSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_DCChgRelayVolt_VCU_BMSH_DCChgRelayVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Inlet_WaterTemp_VCU_BMSH_Inlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Outlet_WaterTemp_VCU_BMSH_Outlet_WaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_StsModeReq_VCU_BMSH_StsModeReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_ChargeDepthReq_VCU_ChargeDepthReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_CrashOutputSts_VCU_CrashOutputSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_DCInputCurrent_VCU_DCInputCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_VCU_Odometerbackup_VCU_Odometerbackup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_PMS_APPowerActual_VCU_PMS_APPowerActual;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_VehicleInfo_CheckSum_VCU_VehicleInfo_CheckSum;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeModeReq_CIL_ChargeModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_12VBatFault_BMSH_12VBatFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowBatTempMax_BMSH_AllowBatTempMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowBatTempMin_BMSH_AllowBatTempMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowCellVoltMax_BMSH_AllowCellVoltMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowCellVoltMin_BMSH_AllowCellVoltMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowPackVoltMax_BMSH_AllowPackVoltMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_AllowPackVoltMin_BMSH_AllowPackVoltMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrent_BMSH_BatCurrent;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatCurrentValidFlag_BMSH_BatCurrentValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatMaintReqValidFlag_BMSH_BatMaintReqValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatMaintenanceReq_BMSH_BatMaintenanceReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatOverSOC_BMSH_BatOverSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatOverVolt_BMSH_BatOverVolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatRealSOC_BMSH_BatRealSOC;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatRealSOCValidFlag_BMSH_BatRealSOCValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOE_BMSH_BatSOE;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOEValidFlag_BMSH_BatSOEValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOH_BMSH_BatSOH;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatSOHValidFlag_BMSH_BatSOHValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMax_BMSH_BatTempMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatTempMin_BMSH_BatTempMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUnderSOC_BMSH_BatUnderSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUnderVolt_BMSH_BatUnderVolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOC_BMSH_BatUseableSOC;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BatUseableSOCValidFlag_BMSH_BatUseableSOCValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattPackNum_BMSH_BattPackNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattSysNum_BMSH_BattSysNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_BattTempAvg_BMSH_BattTempAvg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVolt_BMSH_BusVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_BusVoltValidFlag_BMSH_BusVoltValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargTmpValidFlag_BMSH_CCM_InletTargTmpValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_InletTargetTemp_BMSH_CCM_InletTargetTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTemp_BMSH_CCM_LiquidInTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidInTempValidFlag_BMSH_CCM_LiquidInTempValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTemp_BMSH_CCM_LiquidOutTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_LiquidOutTmpValidFlag_BMSH_CCM_LiquidOutTmpValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThermalManageReq_BMSH_CCM_ThermalManageReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CCM_ThrmlMangReqValidFlag_BMSH_CCM_ThrmlMangReqValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellDiffVoltUniform_BMSH_CellDiffVoltUniform;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellOverVolt_BMSH_CellOverVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellTempUniformity_BMSH_CellTempUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellUnderVolt_BMSH_CellUnderVolt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMax_BMSH_CellVoltMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMaxModuleID_BMSH_CellVoltMaxModuleID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMin_BMSH_CellVoltMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CellVoltMinModuleID_BMSH_CellVoltMinModuleID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverCurrent_BMSH_ChgOverCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgOverTemp_BMSH_ChgOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ChgUnderTemp_BMSH_ChgUnderTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ConnectNegOverTemp_BMSH_ConnectNegOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_ConnectPosOverTemp_BMSH_ConnectPosOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_CoolType_BMSH_CoolType;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_CoolTypeValidFlag_BMSH_CoolTypeValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReq_BMSH_DCChgCurReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgCurReqRangeUP_BMSH_DCChgCurReqRangeUP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgEnder_BMSH_DCChgEnder;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgNegRelayFault_BMSH_DCChgNegRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugNOverTemp_BMSH_DCChgPlugNOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPlugPOverTemp_BMSH_DCChgPlugPOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgPosRelayFault_BMSH_DCChgPosRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRelayFault_BMSH_DCChgRelayFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CCS_BMSH_DCChgRx_OTime_CCS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CML_BMSH_DCChgRx_OTime_CML;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRM00_BMSH_DCChgRx_OTime_CRM00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRMAA_BMSH_DCChgRx_OTime_CRMAA;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CSD_BMSH_DCChgRx_OTime_CSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgStandVer_BMSH_DCChgStandVer;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgVoltAllow_BMSH_DCChgVoltAllow;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgVoltAllowValidFlag_BMSH_DCChgVoltAllowValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCEquipment_DisplayCur_BMSH_DCEquipment_DisplayCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCEquipment_DisplayVolt_BMSH_DCEquipment_DisplayVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DC_DisplayCurRangeUP_BMSH_DC_DisplayCurRangeUP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DC_DisplayVoltValidFlag_BMSH_DC_DisplayVoltValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DataStorageFault_BMSH_DataStorageFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgOverCurrent_BMSH_DisChgOverCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgOverTemp_BMSH_DisChgOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DisChgUnderTemp_BMSH_DisChgUnderTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_EVCANComFault_BMSH_EVCANComFault;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_EnergyOut_BMSH_EnergyOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_EnergyOutValidFlag_BMSH_EnergyOutValidFlag;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_ExChgNumOfTimes_BMSH_ExChgNumOfTimes;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_ExChgNumOfTimesValidFlag_BMSH_ExChgNumOfTimesValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FastChgComFault_BMSH_FastChgComFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FaultCode_BMSH_FaultCode;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTime_BMSH_FinishChgTime;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FinishChgTimeValidFlag_BMSH_FinishChgTimeValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FireAlarm_BMSH_FireAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_FlowRateReq_BMSH_FlowRateReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_FlowRateReqValidFlag_BMSH_FlowRateReqValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_IntComFault_BMSH_IntComFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_MainNegRelayFault_BMSH_MainNegRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_MainPosRelayFault_BMSH_MainPosRelayFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode1_BMSH_PackCode1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode1_1_BMSH_PackCode1_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode2_BMSH_PackCode2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode2_1_BMSH_PackCode2_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode3_BMSH_PackCode3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode3_1_BMSH_PackCode3_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode4_BMSH_PackCode4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode4_1_BMSH_PackCode4_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode5_BMSH_PackCode5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode5_1_BMSH_PackCode5_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode6_BMSH_PackCode6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode7_BMSH_PackCode7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackCode_ID_BMSH_PackCode_ID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackExtendCd_BMSH_PackExtendCd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackType_BMSH_PackType;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVolt_BMSH_PackVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_PackVoltValidFlag_BMSH_PackVoltValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_RecoveryOverCurrent_BMSH_RecoveryOverCurrent;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_SelfCheckFault_BMSH_SelfCheckFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsA_plus_BMSH_StsA_plus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCC2_BMSH_StsCC2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsCellBalance_BMSH_StsCellBalance;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsChgFault_BMSH_StsChgFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsDischgFault_BMSH_StsDischgFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsInsulation_BMSH_StsInsulation;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainNegtiveRelay_BMSH_StsMainNegtiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMainPositiveRelay_BMSH_StsMainPositiveRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsPrecharge_BMSH_StsPrecharge;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsWakeUp_BMSH_StsWakeUp;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_SubtotalExChgSOE_BMSH_SubtotalExChgSOE;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_SubtotalRecoveryEng_BMSH_SubtotalRecoveryEng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_SupplyVolt_BMSH_SupplyVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_SwapCntOverTemp_BMSH_SwapCntOverTemp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatFaultList_BMSH_TBOX_BatFaultList;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatHVILFault_BMSH_TBOX_BatHVILFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm_BMSH_TBOX_BatIsoAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatIsoAlarm2_BMSH_TBOX_BatIsoAlarm2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC_BMSH_TBOX_BatLowSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowSOC2_BMSH_TBOX_BatLowSOC2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatLowTemp_BMSH_TBOX_BatLowTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatModuleSum_BMSH_TBOX_BatModuleSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge_BMSH_TBOX_BatOverCharge;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverCharge2_BMSH_TBOX_BatOverCharge2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC_BMSH_TBOX_BatOverSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverSOC2_BMSH_TBOX_BatOverSOC2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp_BMSH_TBOX_BatOverTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverTemp2_BMSH_TBOX_BatOverTemp2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage_BMSH_TBOX_BatOverVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatOverVoltage2_BMSH_TBOX_BatOverVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductDay_BMSH_TBOX_BatProductDay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductMonth_BMSH_TBOX_BatProductMonth;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatProductYear_BMSH_TBOX_BatProductYear;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatRatedEnergy_BMSH_TBOX_BatRatedEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatRatedVolt_BMSH_TBOX_BatRatedVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatSeriesCellsSum_BMSH_TBOX_BatSeriesCellsSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatStoreSysFault_BMSH_TBOX_BatStoreSysFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempSum_BMSH_TBOX_BatTempSum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity_BMSH_TBOX_BatTempUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatTempUniformity2_BMSH_TBOX_BatTempUniformity2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatType_BMSH_TBOX_BatType;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage_BMSH_TBOX_BatUnderVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUnderVoltage2_BMSH_TBOX_BatUnderVoltage2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity_BMSH_TBOX_BatUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_BatUniformity2_BMSH_TBOX_BatUniformity2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_ID_BMSH_TBOX_CellA_ID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellA_Volt_BMSH_TBOX_CellA_Volt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellB_Volt_BMSH_TBOX_CellB_Volt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_ID_BMSH_TBOX_CellC_ID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellC_Volt_BMSH_TBOX_CellC_Volt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage_BMSH_TBOX_CellOverVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellOverVoltage2_BMSH_TBOX_CellOverVoltage2;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellRatedVolt_BMSH_TBOX_CellRatedVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage_BMSH_TBOX_CellUnderVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellUnderVoltage2_BMSH_TBOX_CellUnderVoltage2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMaxID_BMSH_TBOX_CellVoltMaxID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellVoltMinID_BMSH_TBOX_CellVoltMinID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_CellsSum_BMSH_TBOX_CellsSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_FireAlarm_BMSH_TBOX_FireAlarm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_HWVer_BMSH_TBOX_HWVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_HWVer_Test_BMSH_TBOX_HWVer_Test;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance_BMSH_TBOX_InsulationResistance;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_InsulationResistance2_BMSH_TBOX_InsulationResistance2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MaxTempID_BMSH_TBOX_MaxTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_MinTempID_BMSH_TBOX_MinTempID;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop_BMSH_TBOX_SOCHop;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SOCHop2_BMSH_TBOX_SOCHop2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SWVer_BMSH_TBOX_SWVer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_SWVer_Test_BMSH_TBOX_SWVer_Test;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempA_BMSH_TBOX_TempA;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempA_ID_BMSH_TBOX_TempA_ID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempB_BMSH_TBOX_TempB;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempC_BMSH_TBOX_TempC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempD_BMSH_TBOX_TempD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempE_BMSH_TBOX_TempE;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempF_BMSH_TBOX_TempF;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TempF_ID_BMSH_TBOX_TempF_ID;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TBOX_TheftFault_BMSH_TBOX_TheftFault;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalDischgCapacity_BMSH_TotalDischgCapacity;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalDischgEng_BMSH_TotalDischgEng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgCapacity_BMSH_TotalExChgCapacity;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgEng_BMSH_TotalExChgEng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalExChgSOE_BMSH_TotalExChgSOE;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalOdometer_BMSH_TotalOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalOdometerValidFlag_BMSH_TotalOdometerValidFlag;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalRecoveryCapacity_BMSH_TotalRecoveryCapacity;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TotalRecoveryEng_BMSH_TotalRecoveryEng;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BMSH_TripOdometer_BMSH_TripOdometer;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_TripOdometerValidFlag_BMSH_TripOdometerValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCUChksumFault_BMSH_VCUChksumFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCURollCountFault_BMSH_VCURollCountFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgAllowPwr_BMSH_VCU_BatChgAllowPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgContPwr_BMSH_VCU_BatChgContPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatChgPeakPwr_BMSH_VCU_BatChgPeakPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgAllowPwr_BMSH_VCU_BatDischgAllowPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgContPwr_BMSH_VCU_BatDischgContPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_BatDischgPeakPwr_BMSH_VCU_BatDischgPeakPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgFaultReq_BMSH_VCU_ChgFaultReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgSOPRangeUP_BMSH_VCU_ChgSOPRangeUP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_ChgSOPValidFlag_BMSH_VCU_ChgSOPValidFlag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_Crash_BMSH_VCU_Crash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DCChgNegTemp_BMSH_VCU_DCChgNegTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DCChgPosTemp_BMSH_VCU_DCChgPosTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPRangeUP_BMSH_VCU_DisChgSOPRangeUP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DisChgSOPValidFlag_BMSH_VCU_DisChgSOPValidFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_DischgFaultReq_BMSH_VCU_DischgFaultReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsDCChgPosRelay_BMSH_VCU_StsDCChgPosRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsDCChgRelay_BMSH_VCU_StsDCChgRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsMainHVIL_BMSH_VCU_StsMainHVIL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_VCU_StsPreChgRelay_BMSH_VCU_StsPreChgRelay;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_B2V_ST1_ChgMode_BMS_B2V_ST1_ChgMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattCellsNumPN_BMS_BattCellsNumPN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattPackNumSN_BMS_BattPackNumSN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp1_BMS_BattTemp1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp2_BMS_BattTemp2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp3_BMS_BattTemp3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp4_BMS_BattTemp4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp5_BMS_BattTemp5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BattTemp6_BMS_BattTemp6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCvalue_BMS_CCvalue;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_CPLine_S2_Ctrl_BMS_CPLine_S2_Ctrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CP_Duty_BMS_CP_Duty;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CP_Vol_BMS_CP_Vol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CellTempFrameNum_BMS_CellTempFrameNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltFrameNum_BMS_CellVoltFrameNum;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN1_BMS_CellVoltN1;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN2_BMS_CellVoltN2;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CellVoltN3_BMS_CellVoltN3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgCCSts_BMS_ChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ChgStatus_BMS_ChgStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CutOffLVFbToOBC_BMS_CutOffLVFbToOBC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DCChargRelayCtrl_BMS_DCChargRelayCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayControl_BMS_DelayControl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DelayDataUpldEnb_BMS_DelayDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_DischargeCCvalue_BMS_DischargeCCvalue;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ElectroniclockContorREQ_BMS_ElectroniclockContorREQ;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_ElectroniclockSts_BMS_ElectroniclockSts;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_MaxChgCurrent_BMS_MaxChgCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_MaxChgVoltage_BMS_MaxChgVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_OBCChgContrlCmd_BMS_OBCChgContrlCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_S2STATUS_BMS_S2STATUS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SlowChgNegTemp_BMS_SlowChgNegTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SlowChgPosTemp_BMS_SlowChgPosTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeBattPackSN_1_BMS_SysCodeBattPackSN_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeFrameNum_1_BMS_SysCodeFrameNum_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_SysCodeLength_1_BMS_SysCodeLength_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_TempCSCNum_BMS_TempCSCNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_TempSnsNumPN_BMS_TempSnsNumPN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgFullCalRemind_BMS_VCU_ChrgFullCalRemind;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeAct_BMS_VCU_ChrgModeAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeCalRemind_BMS_VCU_ChrgModeCalRemind;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_VCU_ChrgModeEn_BMS_VCU_ChrgModeEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_VoltCellNum_BMS_VoltCellNum;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMS_ZeroPwr_Req_BMS_ZeroPwr_Req;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_HvSysSample_DisableIso_DisableIso;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg;
extern VAR(KeyAuthStatus, RTE_VAR_INIT) Rte_swc_ATAU_vcsb_ATAU_pmmd_e_authenticationStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpLoPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSnrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSysFailFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLow;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowEVDis;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowInhDrv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacTmOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp1Rly;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp2Rly;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_pumpRdy;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_p_VacPumpPressure_kPa;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_u_VacPumpVol_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_lvbd_b_lvbSOCValid;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_lvbd_q_lvbSOC_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsStopFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed1Vld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed2Vld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_bmsMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_egsmMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl1Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl21Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_bmsFltLv4A;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv2A;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv3A;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vehCrashFltLvl33;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_edcpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_hbcpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_vehSysErrLevel;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoff31Err;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoffDebd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_maxPwrLim_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_minPwrLim_kW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_acEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_accyEnbFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_mcuEnbFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_obcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_zeroPwrFb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pct_vcuChgDepReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_st_vcuChgLimResp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_CruisingDstSwtFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_HazardReqLmpOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_brkSysFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_ePTFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_evLampOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_hevLampOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_odoBckpEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_turtleLmpOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_vehOvrLoadEnbl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_odoTotal_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehCrsDst_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngStandard_km;
extern VAR(PowerFlowMode, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_e_vehPwrFlow;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_m_vehWeight_kg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_AecEV_kWhp100km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_errorCode;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvModInd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvPfmncRedn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvrOptRmdr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehCalNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehDrvMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehFailLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehOverLoadSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehSubFailLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_b_DCDCEnabled;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_pct_DCDCPwrLmt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Avail;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Enad;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_e_inv2ModeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_CampModeFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_acPtcEnb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyHvOnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyPreRlyCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_allowChg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_chgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_fltPwrShutDn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_lvCutOffReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_rlyTmOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlgCfm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuRdyToSlp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_modeTgt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_CampModeFbFailrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlySts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlySts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyTakeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_bbmWrkEnCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
extern VAR(ChargerStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_e_chargerSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_b_vehOvrLoadEnbl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_m_vehWeight_kg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_st_vehCalNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_MEST_vcsb_MEST_masd_st_vehOverLoadSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_invSpdLmtRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_inventorySpdLmtReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lifeCnt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPer;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_lockVehPerRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmdRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLevelReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_spdLmtLvRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_tboxLifeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_verCvsRxSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_versionConversion;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_v_dstSpdLim_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_LockVehSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlAccPedlOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTqOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTurtleLampOn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunAnti_DismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_FunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockLimResult;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_num_LockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_st_LockVehExecutedSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_b_mot2TqOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MinTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_intAccTgt_mps2;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_accCtrlActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd;
extern VAR(CrsBtnErrSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnErrSts;
extern VAR(CrsBtnSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnSts;
extern VAR(CrModeMngr_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSpdMode;
extern VAR(CruiseSts_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_eCreepReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_b_vslTqIntvReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_apdd_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_b_drvPfmncDrgDec;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_st_RegenLvlDisp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlDragDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_msgd_tq_targetTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_accPedlPosVirtVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_ehbDisEnbCreep;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_gpOvrd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_whlAcceSupprsn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ActiveCool_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_BalanceHeat_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassCool_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassHeat_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_TwoWayVlvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_accmEnb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_afterRunActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fan2Ena;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly1Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly2Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEnaHW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_hvbDeft;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuCl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuResvHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuHeatEnableFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuResvHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuSupHtIptcHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv2V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly1Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly2Req;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_FWFVTgt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_MHGVTgt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan1TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan2TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp1TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp2TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_q_pmp2FlowFeedback;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpSpdReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3RlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_tv4;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_t_acwpTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_b_acHvilOpnInvld;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_acFltLvl;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_airCmprSt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_n_acFanReqSpd_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_AcWrk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_acSubFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_airCmprSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_cbnThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_ptcWorkStRear;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_t_ambTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_u_acPresVolt_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens1VoltRaw_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_u_accPedlPosSens2VoltRaw_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosCan_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosLimd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens1_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosSens2_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1CtrlTorqEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adc1SwtchCtrlReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlTorqEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_adcTgtGearPostn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsCanBusRecSta;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adc1TgtDrvTorq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_DryAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_ResrAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch1Closed;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brakeSwitch2Closed;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlPosVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPedlStsVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPumpFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_vacTankLowPrs;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_bdcacWrk;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_AirPres_kpa;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_st_bdcacWrk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_ccdd_u_cruiseADvoltage_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_acuCrash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcHvilFltInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_dcdcFaultStatus;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_12vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_24vDcdcSubFltSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_t_dcdcTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq4WD;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqECO;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqHEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqSPORT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_parkBtnPressed;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_eadInv2Sts;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv21FltSts;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2FltSts;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_i_eadInv2ActCurrDC_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot21ActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot2ActPwr_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2PwrActvMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2Sts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadInv2WrkMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_eadMot2ImmoRlsChk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_st_inv2SubFltSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_inv2Temp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_mot2Temp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_u_busInv2HVAct_V;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmRlyWldFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbHeatEnad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_lowTempProtnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_obcChrgReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_dcdcMainRlySts;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_eadInv2MainRlySts;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmMaiRlyNeg;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmWrkSt;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbAssiRly;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbFaultStatus;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyNeg;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMainRlySts;
extern VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_fact_hvbSOH_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatDischMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbActRaw_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbAct_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbChgPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmMaiRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmPwrActvMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbPwrActvMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbSubFaultSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvilOpenSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_tboxIntelChgQuit;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbAvg_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_V_tankFuelLvl_l;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_pullUpDiagCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_e_sdcacWrk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_frontAirTankPres_bar;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_rearAirTankPres_bar;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsErrorCode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsSubFltLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_sdcacWrk;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcCANMsgValid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCableUnplugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcOutpt_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_st_obcfltLvl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_t_obcTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_anyIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_canIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_hwIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignStsStrt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_pepsPduLvlValid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ptCanNmStRdy;
extern VAR(KeyAuthStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_e_authenticationStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearActVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_e_trsm1PrkgSts;
extern VAR(GearShiftResp, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_e_trsm2GearShftResp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2FinalDrvRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GbxGearRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
extern VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_R_posInsIRes_Ohm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_ang_strWhlAng_rad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_CCSginal;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_DryAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ResrAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_adc1ComErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_adcComErrFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_calCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwtInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmEngRecSwtReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSwInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcStsAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_dcdcTempAlm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_disChgSwtSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_driverEcoModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbVlcCddActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_emgyStopIn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_epbErrSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgBBMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgACU;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAccyButton;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAirBag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgCoastActivBrkLight;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModConn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDualAuthN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgEpdel;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMotor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgTyre;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEGSM;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEHB;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvCcwFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvInitSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvMotSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvOvrVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvRespErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_fwfvUndVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDCChgCurReqRngUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbDisChgSopRngUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbHvilFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbInPositionDetct2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbZeroPwrReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ignStsStrt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ipkOdoBckUpEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvCcwFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvInitSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvMotSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrCurrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrTempFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvOvrVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvRespErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_mhgvUndVoltFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_obcWakeUpActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_odometerInvalid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsOnSwtSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsPduLvlVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsRmtCtrlSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ptCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pullUpDiagCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_rfrSwapBatReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_rstAvgPwrConsumption;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPowOffCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPrtFullSwStUB;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_bcmOdometerbackup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_ipkOdometerbackup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_dcdcInpCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbDCChgCurReq_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_l_whlRad_m;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMaxID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellMinID;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbCellSum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMaxTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbMinTempID;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_num_hvbTempSum;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_GearPosn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_HVILReturnPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP3FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan1Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fan2Fb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_fwfvCrtPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mhgvCrtPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mmiLocBkChgTarVal;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxAlwChgCurrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxChgDepth;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_PTCActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_acwpHeatPower_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_airCmprAct_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_iptActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_ptcActPwrRear_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_24vDcdcModAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_BmsTempOutOfCtrlFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunAntiDismantleActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXFunLockVehActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockLimSet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockResultResp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_TBOXLockVehType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batLowSoc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrSoc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batOvrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_batUdrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmWorkSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackMatchFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattPackNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsBattSysNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsTboxFireAlm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellOverVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_cellUdrVolt2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmEngRecReqInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmRgnLvlSet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dccAccyConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2FltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_eadInv2TempHiAlrm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_egsmShftLvrFailSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbBrkSysErrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbIsaSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_epsEpasFail;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgBatTyp;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgDspRemainRng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgFan;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgSlowChg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgV2L;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehUsg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmHvilSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPTC1ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPtcDefRlyStFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBatUniformity;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbBattIsolationSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellTempDevFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbCellVoltDevFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgOvrCurr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgNOvrTmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgPlgPOvrTmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbInslErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbOvrChgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbPreChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbSocJumpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsChgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbTempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbThermMngReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkChgSftSwCtlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkCruisingDstSwt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuInvTempHighAlm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotTempHighFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverCurrFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipuMotorOverSpdFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_mmiRestSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcElckStMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsPduLvlVld;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsRKECom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ptcConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_rfrConnctSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_rfrSwapprocd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgLmtSw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgSftSwCtlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxInventorySpdLmtReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLife;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxLockVehPerFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxPrtFullSwSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxSpdLmtLevelReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxStartBattChgReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxVersionConversionFlag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_vscEHBAVHSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_TS5sensorFb_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltInTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbCooltOutTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMax_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbOutCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tm_hvbFnshChgTim_m;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT1IntSmpl_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT2IntSmpl_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc1Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc2Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMaxCellVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BmsMinCellVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk2_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_BrkRaw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Brk_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkAirPres_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens1InpVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_accPdlSens2InpVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_batLpPmpCtrlFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_brkVacuumPres_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_cbnLpPmpCtrlFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_dcdcRelayVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_eLpWpCtrlCur_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmMainPosBckVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmPtcRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbPackVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_pepsOn_mV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_vacTkPowSup_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_v_ehbVehSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_a_vscLongitAcce_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActvRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAbsOvrdActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAebActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbDtcActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqIncReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcAvailb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcTrqReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_pdcBrkFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSlipWarn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vscBrkLghtActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbAVHSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbEPBDynAppSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbHHCActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_vscIsgActvDampModReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpdRaw_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Heat_LIN_AC_EWP_Heat_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_HeatrPwrCnsAllwd_LIN_AC_EWP_HeatrPwrCnsAllwd_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Run_LIN_AC_EWP_Run_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_SpeedReq_LIN_AC_EWP_SpeedReq_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_AC_EWP_Temp_LIN_AC_EWP_Temp_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_Battery_Performance_Checksum_BMSH_Battery_Performance_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_03_EXT_DO_KEY_HS_03;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_KEY_HS_05_EXT_DO_KEY_HS_05;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_11_EXT_DO_RELAY_HS_11;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_6_EXT_DO_RELAY_HS_6;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_8_EXT_DO_RELAY_HS_8;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_HS_9_EXT_DO_RELAY_HS_9;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_10_EXT_DO_RELAY_LS_10;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_12_EXT_DO_RELAY_LS_12;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_5_EXT_DO_RELAY_LS_5;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_7_EXT_DO_RELAY_LS_7;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_EXT_DO_RELAY_LS_9_EXT_DO_RELAY_LS_9;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_DutyCycle_EXT_PO_HVIL_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_1_Period_EXT_PO_HVIL_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_DutyCycle_EXT_PO_HVIL_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_HVIL_2_Period_EXT_PO_HVIL_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_DutyCycle_EXT_PO_PWM_1_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_1_Period_EXT_PO_PWM_1_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_DutyCycle_EXT_PO_PWM_2_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_2_Period_EXT_PO_PWM_2_Period;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_DutyCycle_EXT_PO_PWM_4_DutyCycle;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCOP_EXT_PO_PWM_4_Period_EXT_PO_PWM_4_Period;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_CCWFlg_PMS_FWFV_CCWFlg_PMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_CurrentPos_PMS_FWFV_CurrentPos_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_InitState_PMS_FWFV_InitState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_MotorState_PMS_FWFV_MotorState_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverCurrentFlt_PMS_FWFV_OverCurrentFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverTempFlt_PMS_FWFV_OverTempFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_OverVoltageFlt_PMS_FWFV_OverVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_RESP_ERROR_PMS_FWFV_RESP_ERROR_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_FWFV_UnderVoltageFlt_PMS_FWFV_UnderVoltageFlt_PMS;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN110_O_S_PIN110;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN123_O_S_PIN123;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN83_O_S_PIN83;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN88_O_S_PIN88;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN89_O_S_PIN89;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_O_S_PIN98_O_S_PIN98;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN104_Duty_O_T_PIN104_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN104_Period_O_T_PIN104_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN118_Duty_O_T_PIN118_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN118_Period_O_T_PIN118_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN14_Duty_O_T_PIN14_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN14_Period_O_T_PIN14_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN28_Duty_O_T_PIN28_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN28_Period_O_T_PIN28_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN77_Duty_O_T_PIN77_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN77_Period_O_T_PIN77_Period;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN82_Duty_O_T_PIN82_Duty;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VCOP_O_T_PIN82_Period_O_T_PIN82_Period;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ADCCtrlSts_PMS_ADCCtrlSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_APA_BeControlled_Status_PMS_APA_BeControlled_Status;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_AppSts_EV_PMS_AppSts_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake1Switch_PMS_Brake1Switch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Brake2Switch_PMS_Brake2Switch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_AliveCounter_EV_PMS_Command_AliveCounter_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Command_Checksum_EV_PMS_Command_Checksum_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ControlSetSpeed_PMS_ControlSetSpeed;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruiseControlSts_PMS_CruiseControlSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruiseSwitchSts_PMS_CruiseSwitchSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CruisingDstSwtFb_PMS_CruisingDstSwtFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_EV_PMS_CurrentGearPosition_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_CurrentGearPosition_Valid_EV_PMS_CurrentGearPosition_Valid_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDC_Ctrl_AliveCounter_PMS_DCDC_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DCDC_Ctrl_Checksum_PMS_DCDC_Ctrl_Checksum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DM_FailureReasonAndSysFaultFBK_PMS_DM_FailureReasonAndSysFaultFBK;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DcDc1ActvdReq_EV_PMS_DcDc1ActvdReq_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriveCircuitTemp_EV_PMS_DriveCircuitTemp_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_DriverRemind_PMS_DriverRemind;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPEnable_EV_PMS_EDCPEnable_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EDCPPWMCtrl_EV_PMS_EDCPPWMCtrl_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPBClosedReq_PMS_EPBClosedReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPS_SteeringAngleValueInvalid_PMS_EPS_SteeringAngleValueInvalid;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EPedlDrvrIndcnMsg_PMS_EPedlDrvrIndcnMsg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_EpedalActive_PMS_EpedalActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ExecuteLockVehResults_PMS_ExecuteLockVehResults;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_MoveEnable_PMS_FWFV_MoveEnable;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_MoveEnable_LIN_PMS_FWFV_MoveEnable_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_ReqMovePos_PMS_FWFV_ReqMovePos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_FWFV_ReqMovePos_LIN_PMS_FWFV_ReqMovePos_LIN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_HvBattCooltLvl_PMS_HvBattCooltLvl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUActvdReq_PMS_MCUActvdReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MCUTemp_EV_PMS_MCUTemp_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_EnableReq_LIN_PMS_MHGV_EnableReq_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_PosSet_LIN_PMS_MHGV_PosSet_LIN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorEmgyStop_LIN_PMS_MHGV_ReqMotorEmgyStop_LIN;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_MHGV_ReqMotorOptRecovery_LIN_PMS_MHGV_ReqMotorOptRecovery_LIN;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCOP_PMS_Odometerbackup_PMS_Odometerbackup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_SlidingmomentrSetReq_PMS_SlidingmomentrSetReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILState_PMS_TBOX_HVILState;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_TBOX_HVILState_3A1_PMS_TBOX_HVILState_3A1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ThermalReq_PMS_ThermalReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_VehicleSpeedInvalid_EV_PMS_VehicleSpeedInvalid_EV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTReady_EV_PMS_ePTReady_EV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_PMS_ePTRegencyLevInd_PMS_ePTRegencyLevInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_st_ShtDown_st_ShtDown;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_vcob_VCOP_BMSH_ChargeLEDCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_epbClsdReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_gearPosVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(HEVModeReq, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_drvrHEVModReq;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_st_gearLvrLckInd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStopReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtAbort;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtComplete;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtDem;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtEnad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_strtrRlyDem;
extern VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTyp;
extern VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTypSeld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_HVBusDischrgComplete;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_emsWake;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_hsdFltClear;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmRdySlp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmWkUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_peuWake;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_startReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuAwb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuRmr;
extern VAR(rt_Array_UInt8_2, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_bm_netModeReq;
extern VAR(NMStatus, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_CanNMSts;
extern VAR(PmmMode, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_mode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_num_vcuAddr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_bdCanModeReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_ptCanModeReq;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_stayAwkReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuPwrActvMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuWkUpReason;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTDisabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_StartDemRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRunRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehStrt;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp;
extern VAR(rt_Array_UInt16_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp;
extern VAR(rt_Array_UInt16_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_ICellBaln_BBC_ICellBaln;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp;
extern VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvCellURchd_BCC_AcvCellURchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvSocRchd_BCC_AcvSocRchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_AcvUTotRchd_BCC_AcvUTotRchd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ChgCCSts_BCC_ChgCCSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_EChSng_BCC_EChSng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorFault_BCC_ElectroniclockContorFault;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockContorREQ_BCC_ElectroniclockContorREQ;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ElectroniclockSt_BCC_ElectroniclockSt;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IChReq_BCC_IChReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IDchaReq_BCC_IDchaReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ModeCh_BCC_ModeCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcChReq_BCC_StAcChReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StCh_BCC_StCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranAcChEndByBatHvReq_BCC_TranAcChEndByBatHvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_TranDcChEndByBatHvReq_BCC_TranDcChEndByBatHvReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UChReq_BCC_UChReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvDig10_BCC_bAcvDig10;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bAcvHvbatFull_BCC_bAcvHvbatFull;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_bS2Ctrl_BCC_bS2Ctrl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChMaxByHour_BCTE_TiBatChMaxByHour;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChMaxByMinu_BCTE_TiBatChMaxByMinu;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatDchaByMinuTot_BCTE_TiBatDchaByMinuTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_AcvChSuspdByChrgr_EVCSH_AcvChSuspdByChrgr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChRdy_EVCSH_ErrMsgChrgrChRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSts_EVCSH_ErrMsgChrgrChSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChStstc_EVCSH_ErrMsgChrgrChStstc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrChSuspd_EVCSH_ErrMsgChrgrChSuspd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcNotRdy_EVCSH_ErrMsgChrgrIdfcNotRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrIdfcRdy_EVCSH_ErrMsgChrgrIdfcRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ErrMsgChrgrSync_EVCSH_ErrMsgChrgrSync;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StBatRdy_EVCSH_StBatRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StDcCh_EVCSH_StDcCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StInt_EVCSH_StInt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvCfgCmpl_EVCSH_bAcvCfgCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvChSeqEnd_EVCSH_bAcvChSeqEnd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcChReqFromVcu_EVCSH_bAcvDcChReqFromVcu;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvDcCnctReq_EVCSH_bAcvDcCnctReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bAcvVeh2VehDcha_EVCSH_bAcvVeh2VehDcha;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaChrgn_EVCSH_bEnaChrgn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfg_EVCSH_bEnaMsgBatCfg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatCfgPgtn_EVCSH_bEnaMsgBatCfgPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChDmd_EVCSH_bEnaMsgBatChDmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSt_EVCSH_bEnaMsgBatChSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChStPgtn_EVCSH_bEnaMsgBatChStPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatChSuspd_EVCSH_bEnaMsgBatChSuspd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatDetdCfg_EVCSH_bEnaMsgBatDetdCfg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatErr_EVCSH_bEnaMsgBatErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatHdshk_EVCSH_bEnaMsgBatHdshk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatPrvt_EVCSH_bEnaMsgBatPrvt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRcgtn_EVCSH_bEnaMsgBatRcgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatRdy_EVCSH_bEnaMsgBatRdy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatSt_EVCSH_bEnaMsgBatSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatStstc_EVCSH_bEnaMsgBatStstc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgBatT_EVCSH_bEnaMsgBatT;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_bEnaMsgCellU_EVCSH_bEnaMsgCellU;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CRO00_BCC_TimeOutCRO00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatChCtl_TimeOut_CROAA_BCC_TimeOutCROAA;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAbsv_BCF_CMdulAbsv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_DeltAhNv_BCF_DeltAhNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EPackRmng_BCF_EPackRmng;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_EnaPack_BCF_EnaPack;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo1_BCF_ErrInfo1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo2_BCF_ErrInfo2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo3_BCF_ErrInfo3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo4_BCF_ErrInfo4;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo5_BCF_ErrInfo5;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo6_BCF_ErrInfo6;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_FullChgSOHNv_BCF_FullChgSOHNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimInt_BCF_IChLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChMax_BCF_IChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLim_BCF_IChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChPredLimInt_BCF_IChPredLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimInt_BCF_IDchaLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaMax_BCF_IDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLim_BCF_IDchaPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaPredLimInt_BCF_IDchaPredLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_NrMdulMax_BCF_NrMdulMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrChLim_BCF_PwrChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrChPredLim_BCF_PwrChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrDchaLim_BCF_PwrDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrDchaPredLim_BCF_PwrDchaPredLim;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_PwrMdulLoss_BCF_PwrMdulLoss;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RPackInt_BCF_RPackInt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCell_BCF_SocCell;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellDelta_BCF_SocCellDelta;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellMax_BCF_SocCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCellMin_BCF_SocCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMax_BCF_SocLimMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocMdul_BCF_SocMdul;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocUOcIniNv_BCF_SocUOcIniNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv;
extern VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv;
extern VAR(rt_Array_UInt8_4, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StLimnId_BCF_StLimnId;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TCooltMdulOut_BCF_TCooltMdulOut;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TMdulEstimd_BCF_TMdulEstimd;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiChFullOff_BCF_TiChFullOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChLim_BCF_UChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChLimInt_BCF_UChLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChPredLim_BCF_UChPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UChPredLimInt_BCF_UChPredLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaLim_BCF_UDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaLimInt_BCF_UDchaLimInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaPredLim_BCF_UDchaPredLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UDchaPredLimInt_BCF_UDchaPredLimInt;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UPackCircOpen_BCF_UPackCircOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bChrgFullCalRemind_BCF_bChrgFullCalRemind;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bEnaThrwyFlg_BCF_bEnaThrwyFlg;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFls_BCF_bErrMdulSocInvldFls;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellU_BPIU_ErrCellU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUDif_BPIU_ErrCellUDif;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUOver_BPIU_ErrCellUOver;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIChLim_BPIU_ErrIChLim;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrUAcqn_BPIU_ErrUAcqn;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMax_BPIU_StChkUMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMin_BPIU_StChkUMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrCellT_BPP_ErrCellT;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrPackU_BPP_ErrPackU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocJmp_BPP_ErrSocJmp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrSocVal_BPP_ErrSocVal;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IAct_BPP_IAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IChAct_BPP_IChAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IDchaAct_BPP_IDchaAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_PwrAct_BPP_PwrAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_SocLimMax_BPP_SocLimMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_SocLimMin_BPP_SocLimMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_TCellMaxLim_BPP_TCellMaxLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_TCellMinLim_BPP_TCellMinLim;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_bAcvCTest_BPP_bAcvCTest;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMax_BTHM_IdMdulTMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMin_BTHM_IdMdulTMin;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ReqRePrech_BTHM_ReqRePrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMain_BTHM_StRlyMain;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBatTgt_BTHM_TBatTgt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBcuSnsr_BTHM_TBcuSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCorrn_BTHM_TMdulCorrn;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsr_BTHM_TMdulSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig64_BTHM_bAcvDig64;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig93_BTHM_bAcvDig93;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTot_BWLD_CBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTotNv_BWLD_CBatChTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTot_BWLD_CBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTot_BWLD_CBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrChNv_BWLD_CtrChNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDchaNv_BWLD_CtrDchaNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrMdulWrNv_BWLD_CtrMdulWrNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChDrvCyc_BWLD_EBatChDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTotNv_BWLD_EBatChTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaDrvCyc_BWLD_EBatDchaDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryDrvCyc_BWLD_EBatRecoveryDrvCyc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTot_BWLD_EBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMax_BWLD_IBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMax_BWLD_IBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMax_BWLD_PBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMax_BWLD_PBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMax_BWLD_SocBatMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMin_BWLD_SocBatMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMinNv_BWLD_SocBatMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgi_BWLD_TiBatAgi;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMax_BWLD_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMaxNv_BWLD_UCellMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMin_BWLD_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMinNv_BWLD_UCellMinNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DelayTime_BSTC_DelayTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ErrInfo_BSTC_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd_BSTC_RstCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd100_BSTC_RstCmd100;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBmsChk_BSTC_StBmsChk;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOn_BSTC_TiBatOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TrigCh_BSTC_TrigCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrPwrOff_BSTC_bErrPwrOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChManSuspd_BSOF_AcvChManSuspd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdByBms_BSOF_AcvChSuspdByBms;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdCdnRchd_BSOF_AcvChSuspdCdnRchd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_AcvChSuspdFlt_BSOF_AcvChSuspdFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ChAllwd_BSOF_ChAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_DirChAndDcha_BSOF_DirChAndDcha;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_EChSng_BSOF_EChSng;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChImpo_BSOF_ErrChImpo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOutpFlt_BSOF_ErrChrgrOutpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempFlt_BSOF_ErrChrgrOvtempFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrOvtempIntFlt_BSOF_ErrChrgrOvtempIntFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrChrgrShtdnEmcy_BSOF_ErrChrgrShtdnEmcy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrIDe_BSOF_ErrIDe;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUAbno_BSOF_ErrUAbno;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ErrUndfnd_BSOF_ErrUndfnd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgr_BSOF_IChrgr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMax_BSOF_IChrgrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IChrgrMin_BSOF_IChrgrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IDchaMax_BSOF_IDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_IDchaMin_BSOF_IDchaMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRcgtn_BSOF_MsgChrgrRcgtn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_MsgChrgrRdy_BSOF_MsgChrgrRdy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_NrChrgrComVers_BSOF_NrChrgrComVers;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_SocDchaMax_BSOF_SocDchaMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_BSOF_SocDchaMin_BSOF_SocDchaMin;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_BSOF_TiChAccumd_BSOF_TiChAccumd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMax_BSOF_UChrgrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgrMin_BSOF_UChrgrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMax_BSOF_UDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UDchaMin_BSOF_UDchaMin;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bAcvDcChrgrPlg_BSOF_bAcvDcChrgrPlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChDetd_BSOF_bEnaMsgChrgrChDetd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChSt_BSOF_bEnaMsgChrgrChSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrChSuspd_BSOF_bEnaMsgChrgrChSuspd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrDetnCnct_BSOF_bEnaMsgChrgrDetnCnct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrErr_BSOF_bEnaMsgChrgrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrHdshk_BSOF_bEnaMsgChrgrHdshk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOut_BSOF_bEnaMsgChrgrMaxOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrMaxOutPgtn_BSOF_bEnaMsgChrgrMaxOutPgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrRcgtn_BSOF_bEnaMsgChrgrRcgtn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrRdy_BSOF_bEnaMsgChrgrRdy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrStstc_BSOF_bEnaMsgChrgrStstc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bEnaMsgChrgrStstcForPgtn_BSOF_bEnaMsgChrgrStstcForPgtn;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_BSOF_bErrMsgTout_BSOF_bErrMsgTout;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ActInputVolt_CIL_ActInputVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_AllowChgCurrentMax_CIL_BMSH_AllowChgCurrentMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_StsModeReq_CIL_BMSH_StsModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_CP_Vol_CIL_CP_Vol;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_CfgLvl2_CIL_CfgLvl2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChargeDepthReq_CIL_ChargeDepthReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChgCCSts_CIL_ChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ChrgSoftSwCtrlSt_CIL_ChrgSoftSwCtrlSt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayRtc_CIL_DayRtc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayTelbox_CIL_DayTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusDrv_CIL_DoorLockStatusDrv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DoorLockStatusPass_CIL_DoorLockStatusPass;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCrash_CIL_DucycCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCtlPilot_CIL_DucycCtlPilot;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycHvil_CIL_DucycHvil;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElectroniclockVolt_CIL_ElectroniclockVolt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ElockStmodeOBC_CIL_ElockStmodeOBC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrAcScktSnsrT_CIL_ErrAcScktSnsrT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrDcScktSnsrT_CIL_ErrDcScktSnsrT;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqCrash_CIL_FrqCrash;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqHvil_CIL_FrqHvil;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerIntCtrl_CIL_HWVerIntCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HWVerVeh_CIL_HWVerVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourRtc_CIL_HourRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourTelbox_CIL_HourTelbox;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHvRaw_CIL_IBatHvRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_IDcdcLvAct_CIL_IDcdcLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IEACAct_CIL_IEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IObcChOutp_CIL_IObcChOutp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuRtc_CIL_MinuRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuTelbox_CIL_MinuTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeMotDrv_CIL_ModeMotDrv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeSysWup_CIL_ModeSysWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthRtc_CIL_MonthRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthTelbox_CIL_MonthTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdCPline_CIL_OnBdCPline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_OnBdDisChrgrCCline_CIL_OnBdDisChrgrCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_PowerMode_CIL_PowerMode;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrEACAct_CIL_PwrEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_PwrPtcAct_CIL_PwrPtcAct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctn_CIL_RAcChCnctn;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RAcChCnctnResRaw_CIL_RAcChCnctnResRaw;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDisChCnctn_CIL_RDisChCnctn;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnNeg_CIL_RIslnNeg;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnPos_CIL_RIslnPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ReservationChrgnSts_CIL_ReservationChrgnSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_RngElec_CIL_RngElec;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerIntCtrl_CIL_SWVerIntCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecTelbox_CIL_SecTelbox;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdMot_CIL_SpdMot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq;
extern VAR(rt_Array_UInt8_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellT_CIL_StCellT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgErrInMdul_CIL_StCellUSamplgErrInMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChAllwd_CIL_StChAllwd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCrash_CIL_StCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForObc_CIL_StMsgToutForObc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StObc_CIL_StObc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StProj_CIL_StProj;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtcW_CIL_StPtcW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StRtcFlt_CIL_StRtcFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StsElectroniclockContor_CIL_StsElectroniclockContor;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBd_CIL_TBd;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBdSnsr_CIL_TBdSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdul_CIL_TMdul;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlr_CIL_TMdulCtlr;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TSnsrI_CIL_TSnsrI;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TiSysRun_CIL_TiSysRun;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleLowSideDrv_CIL_UChPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UDcdcLvAct_CIL_UDcdcLvAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UEACAct_CIL_UEACAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleLowSideDrv_CIL_UMainNegPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleLowSideDrv_CIL_UMainPosPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleHiSideDrv_CIL_UNegChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UNegChPoleLowSideDrv_CIL_UNegChPoleLowSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChInp_CIL_UObcChInp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChOutp_CIL_UObcChOutp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyChNeg_CIL_UPoleAftRlyChNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_VehicleSpeedInvalid_CIL_VehicleSpeedInvalid;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearRtc_CIL_YearRtc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearTelbox_CIL_YearTelbox;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_ZeroPwrFb_CIL_ZeroPwrFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bCANWakeUp_CIL_bCANWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bDCDCW_CIL_bDCDCW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bKCNegClsSts_CIL_bKCNegClsSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bMainNegClsSts_CIL_bMainNegClsSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldIslnR_CIL_bVldIslnR;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_InletWaterTemp_ClL_InletWaterTemp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_ClL_OutletWaterTemp_ClL_OutletWaterTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCtlrSnsrTByMdul_MCC_NrCtlrSnsrTByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_B2V_SingleChgEnergy_B2V_SingleChgEnergy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCCur_BCPP_Max_Allow_DCCur;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Max_Allow_DCV_BCPP_Max_Allow_DCV;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_CellV_BCPP_Min_Allow_CellV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BCPP_Min_Allow_Soc_BCPP_Min_Allow_Soc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_discharge_time_BCSP_Remaining_discharge_time;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BCSP_Remaining_range_BCSP_Remaining_range;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_COL_BCSP_reserved_BCSP_reserved;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Battery_capacity_BDC_Battery_capacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Battery_energy_BDC_Battery_energy;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Current_V2GCirculate_BDC_Current_V2GCirculate;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Remainder_CruisingRange_BDC_Remainder_CruisingRange;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BDC_Remainder_V2GCirculate_BDC_Remainder_V2GCirculate;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Soc_BDC_Soc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_1_BDC_Vin1_Copy_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_10_BDC_Vin1_Copy_10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_11_BDC_Vin1_Copy_11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_12_BDC_Vin1_Copy_12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_13_BDC_Vin1_Copy_13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_14_BDC_Vin1_Copy_14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_15_BDC_Vin1_Copy_15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_16_BDC_Vin1_Copy_16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_17_BDC_Vin1_Copy_17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_2_BDC_Vin1_Copy_2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_3_BDC_Vin1_Copy_3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_4_BDC_Vin1_Copy_4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_5_BDC_Vin1_Copy_5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_6_BDC_Vin1_Copy_6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_7_BDC_Vin1_Copy_7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_8_BDC_Vin1_Copy_8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BDC_Vin1_Copy_9_BDC_Vin1_Copy_9;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CRO00_BMSH_DCChgRx_OTime_CRO00;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChgRx_OTime_CROAA_BMSH_DCChgRx_OTime_CROAA;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_BSWControl_RstDiagGlb_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Mode_Request_shutdown_Request_shutdown;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCL_Request_BCL;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCP_Request_BCP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCPP_Request_BCPP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCS_Request_BCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BCSP_Request_BCSP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BDC_Request_BDC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BEM_Request_BEM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BHM_Request_BHM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMS_FastChgStopInfo_Request_BMS_FastChgStopInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMT_Request_BMT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BMV_Request_BMV;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRM_Request_BRM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BRO_Request_BRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSD_Request_BSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSM_Request_BSM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BSP_Request_BSP;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BSWIOSP_Request_BST_Request_BST;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryChargingOvercurrent_BatteryChargingOvercurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryExcessTemperature_BatteryExcessTemperature;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTemp_BatteryHighestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryHighestTempSerNo_BatteryHighestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryInsulationState_BatteryInsulationState;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTemp_BatteryLowestTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryLowestTempSerNo_BatteryLowestTempSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryOutputConnectorState_BatteryOutputConnectorState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemCapacity_BatterySystemCapacity;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BatterySystemVoltage_BatterySystemVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BatteryType_BatteryType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsReadyForCharging_BmsReadyForCharging;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsRevision_BmsRevision;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_ActiveSuspend_BmsSuspCause_ActiveSuspend;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_SOC_BmsSuspCause_SOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_SingleVoltage_BmsSuspCause_SingleVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspCause_TotalVoltage_BmsSuspCause_TotalVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspError_AbnormalVoltage_BmsSuspError_AbnormalVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspError_ExcessiveCurrent_BmsSuspError_ExcessiveCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_BatteryTemp_BmsSuspFault_BatteryTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_BmsTemp_BmsSuspFault_BmsTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_ChargeConn_BmsSuspFault_ChargeConn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_Insulation_BmsSuspFault_Insulation;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_OtherFaults_BmsSuspFault_OtherFaults;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_OutputConnTemp_BmsSuspFault_OutputConnTemp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_VoltageDetection_BmsSuspFault_VoltageDetection;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BmsSuspFault_VoltageRelay_BmsSuspFault_VoltageRelay;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BmsVersion_BmsVersion;
extern VAR(rt_Array_UInt32_9, RTE_VAR_INIT) Rte_swc_COL_BmuControl_BalanceControl_BalanceControl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BsmChargingPermissible_BsmChargingPermissible;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_ChargingMode_ChargingMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_CurrentChargeState_CurrentChargeState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentDemand_CurrentDemand;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_CurrentVehicleBatteryVoltage_CurrentVehicleBatteryVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_EstimatedRemainingChargingTime_EstimatedRemainingChargingTime;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_NegRlyCtr_IOFS_NegRlyCtr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_PosRlyCtr_IOFS_PosRlyCtr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_COL_IOFS_PreChgRlyCtr_IOFS_PreChgRlyCtr;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxChargingVoltage_MaxChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxPermChargingCurrent_MaxPermChargingCurrent;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_MaxPermTemperature_MaxPermTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MaxSingleBattChargingVoltage_MaxSingleBattChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingCurrent_MeasuredChargingCurrent;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_MeasuredChargingVoltage_MeasuredChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltage_SingleBatteryHighestVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageGroup_SingleBatteryHighestVoltageGroup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryHighestVoltageSerNo_SingleBatteryHighestVoltageSerNo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxTemperature_SingleBatteryMaxTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMaxVoltage_SingleBatteryMaxVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinTemperature_SingleBatteryMinTemperature;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryMinVoltage_SingleBatteryMinVoltage;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SingleBatteryUnusualVoltage_SingleBatteryUnusualVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_StatusVehiclePowerStorageBattery_StatusVehiclePowerStorageBattery;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_SuspendStateOfChargeSOC_SuspendStateOfChargeSOC;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CCS_Timeout_CCS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Recognized_Timeout_CRM_Recognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRM_Unrecognized_Timeout_CRM_Unrecognized;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CRO_Timeout_CRO;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CSD_Timeout_CSD;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CST_Timeout_CST;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_Timeout_CTS_CML_Timeout_CTS_CML;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalMaxPermChargingVoltage_TotalMaxPermChargingVoltage;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_TotalNominalEnergy_TotalNominalEnergy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_1_VIN_Copy_1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_10_VIN_Copy_10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_11_VIN_Copy_11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_12_VIN_Copy_12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_13_VIN_Copy_13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_14_VIN_Copy_14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_15_VIN_Copy_15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_16_VIN_Copy_16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_17_VIN_Copy_17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_2_VIN_Copy_2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_3_VIN_Copy_3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_4_VIN_Copy_4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_5_VIN_Copy_5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_6_VIN_Copy_6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_7_VIN_Copy_7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_8_VIN_Copy_8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VIN_Copy_9_VIN_Copy_9;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_VehicleBatteryUnusualChargeState_VehicleBatteryUnusualChargeState;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_VoltageDemand_VoltageDemand;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyCh_CTC_ErrRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyHeat_CTC_ErrRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyNeg_CTC_ErrRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPos_CTC_ErrRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrRlyPrech_CTC_ErrRlyPrech;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiCh_CTC_PctgCtctrAgiCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiHeat_CTC_PctgCtctrAgiHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiNeg_CTC_PctgCtctrAgiNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPos_CTC_PctgCtctrAgiPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_PctgCtctrAgiPrech_CTC_PctgCtctrAgiPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyChNeg_CTC_ReqRlyChNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPrech_CTC_ReqRlyPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqZeroPwr_CTC_ReqZeroPwr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChNeg_CTC_StRlyChNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkCh_CTC_StRlyChkCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkHeat_CTC_StRlyChkHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkPos_CTC_StRlyChkPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StSysInt_CTC_StSysInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvBswCtl_CTC_bAcvBswCtl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiCh_CTC_bErrRlyAgiCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiHeat_CTC_bErrRlyAgiHeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiNeg_CTC_bErrRlyAgiNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPos_CTC_bErrRlyAgiPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrRlyAgiPrech_CTC_bErrRlyAgiPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bErrToutForMotDcha_CTC_bErrToutForMotDcha;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiCh_CTC_bWarnRlyAgiCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiHeat_CTC_bWarnRlyAgiHeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiNeg_CTC_bWarnRlyAgiNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPos_CTC_bWarnRlyAgiPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bWarnRlyAgiPrech_CTC_bWarnRlyAgiPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrType_DEH_BatMfctrType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrr_DEH_BatMfctrr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ChgLvlErr_DEH_ChgLvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DayBatMfctr_DEH_DayBatMfctr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DischgLvlErr_DEH_DischgLvlErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd6_DEH_ErrCfmd6;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErrSb_DEH_LvlErrSb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ModBalCtl_DEH_ModBalCtl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_MonthBatMfctr_DEH_MonthBatMfctr;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrPackSerl_DEH_NrPackSerl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin1_DEH_NrVin1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin10_DEH_NrVin10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin11_DEH_NrVin11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin12_DEH_NrVin12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin13_DEH_NrVin13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin14_DEH_NrVin14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin15_DEH_NrVin15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin16_DEH_NrVin16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin17_DEH_NrVin17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin2_DEH_NrVin2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin3_DEH_NrVin3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin4_DEH_NrVin4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin5_DEH_NrVin5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin6_DEH_NrVin6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin7_DEH_NrVin7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin8_DEH_NrVin8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin9_DEH_NrVin9;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_PackCode_DEH_PackCode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqBalCtl_DEH_ReqBalCtl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyCh_DEH_ReqRlyCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyNeg_DEH_ReqRlyNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPos_DEH_ReqRlyPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPrech_DEH_ReqRlyPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StIslnMeasReq_DEH_StIslnMeasReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StSocCal_DEH_StSocCal;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValPackSoc_DEH_ValPackSoc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_YearBatMfctr_DEH_YearBatMfctr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcChInh_DEH_bAcvAcChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDchaInh_DEH_bAcvDchaInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvHeatInh_DEH_bAcvHeatInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPowupInh_DEH_bAcvPowupInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvRecupInh_DEH_bAcvRecupInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls;
extern VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls;
extern VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrash_ELHPN_StCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIslnErr_ELHPN_StIslnErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIsln_ELHPN_StVehIsln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_10ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core1_QM;
extern VAR(Rte_ts_App1_Task_100ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core1_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
extern VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
extern VAR(Rte_ts_App1_Task_50ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_50ms_Core2_QM;
extern VAR(Rte_ts_App1_Task_1000ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_1000ms_Core2_QM;
extern VAR(Rte_ts_App1_Task1_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task1_UDS_Core2_QM;
extern VAR(Rte_ts_App1_Task0_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task0_UDS_Core2_QM;
extern VAR(Rte_ts_App1_Task2_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task2_UDS_Core2_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_Task_100us_Core3_QM, RTE_VAR_NOINIT) Rte_Task_100us_Core3_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_NO_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    extern Rte.c global variables
************************************************************************************************************************
*/
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
#define RTE_START_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern volatile VAR(uint8, RTE_VAR_INIT) Rte_CoreState[RTE_CORE_COUNT];
#define RTE_STOP_SEC_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#define RTE_START_SEC_CONST
#include "Rte_MemMap.h"
extern CONST(uint8, RTE_CONST) Rte_CoreInUseState[RTE_CORE_COUNT];
#define RTE_STOP_SEC_CONST
#include "Rte_MemMap.h"

#endif


#endif /* RTE_TYPE_H_ */
