 
/*
************************************************************************************************************************
*
* File name: Rte_swc_VOMM_Type.h
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
#ifndef RTE_SWC_VOMM_TYPE_H_
#define RTE_SWC_VOMM_TYPE_H_

#include "Rte_Type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
************************************************************************************************************************
*    Range, Invalidation, Enumeration and Bit Field Definitions.
************************************************************************************************************************
*/
#ifndef BrakePedalStatus_NOT_PRESSED
#define BrakePedalStatus_NOT_PRESSED (0U)
#endif

#ifndef BrakePedalStatus_PRESSED
#define BrakePedalStatus_PRESSED (1U)
#endif

#ifndef BrakePedalStatus_INVALID
#define BrakePedalStatus_INVALID (2U)
#endif

#ifndef GearLeverPos_PARKING
#define GearLeverPos_PARKING (0U)
#endif

#ifndef GearLeverPos_NEUTRAL
#define GearLeverPos_NEUTRAL (1U)
#endif

#ifndef GearLeverPos_REV_DRIVE
#define GearLeverPos_REV_DRIVE (2U)
#endif

#ifndef GearLeverPos_FWD_DRIVE
#define GearLeverPos_FWD_DRIVE (3U)
#endif

#ifndef GearLeverPos_SPT_DRIVE
#define GearLeverPos_SPT_DRIVE (4U)
#endif

#ifndef GearLeverPos_FAILURE
#define GearLeverPos_FAILURE (5U)
#endif

#ifndef GearLeverPos_INVALID
#define GearLeverPos_INVALID (6U)
#endif

#ifndef GearLeverPos_UNKNOWN
#define GearLeverPos_UNKNOWN (9U)
#endif

#ifndef ParkingStatus_DISENGAGED
#define ParkingStatus_DISENGAGED (0U)
#endif

#ifndef ParkingStatus_ENGAGED
#define ParkingStatus_ENGAGED (1U)
#endif

#ifndef ParkingStatus_INPROGRESS
#define ParkingStatus_INPROGRESS (2U)
#endif

#ifndef ParkingStatus_DEFAULTVALUE
#define ParkingStatus_DEFAULTVALUE (3U)
#endif

#ifndef ParkingStatus_ERROR
#define ParkingStatus_ERROR (4U)
#endif

#ifndef ParkingStatus_INVALID
#define ParkingStatus_INVALID (5U)
#endif

#ifndef KeyAuthStatus_DEFAULT
#define KeyAuthStatus_DEFAULT (0U)
#endif

#ifndef KeyAuthStatus_SUCCESS
#define KeyAuthStatus_SUCCESS (1U)
#endif

#ifndef KeyAuthStatus_FAIL
#define KeyAuthStatus_FAIL (2U)
#endif

#ifndef ChargerStatus_UNKNOWN
#define ChargerStatus_UNKNOWN (0U)
#endif

#ifndef ChargerStatus_CONFIRMED_PLUGGED
#define ChargerStatus_CONFIRMED_PLUGGED (1U)
#endif

#ifndef ChargerStatus_CONFIRMED_UNPLUGGED
#define ChargerStatus_CONFIRMED_UNPLUGGED (2U)
#endif

#ifndef ChargerStatus_SUSPECT_PLUGGED
#define ChargerStatus_SUSPECT_PLUGGED (3U)
#endif

#ifndef ChargerStatus_SUSPECT_UNPLUGGED
#define ChargerStatus_SUSPECT_UNPLUGGED (4U)
#endif

#ifndef DriveDir_NO_DRIVE
#define DriveDir_NO_DRIVE (0U)
#endif

#ifndef DriveDir_FORWARD
#define DriveDir_FORWARD (1U)
#endif

#ifndef DriveDir_REVERSE
#define DriveDir_REVERSE (2U)
#endif

#ifndef DriveDir_INVALID
#define DriveDir_INVALID (3U)
#endif

#ifndef HEVModeReq_OFF
#define HEVModeReq_OFF (0U)
#endif

#ifndef HEVModeReq_ICE
#define HEVModeReq_ICE (1U)
#endif

#ifndef HEVModeReq_PHEV
#define HEVModeReq_PHEV (2U)
#endif

#ifndef HEVModeReq_SHEV
#define HEVModeReq_SHEV (3U)
#endif

#ifndef HEVModeReq_EV
#define HEVModeReq_EV (4U)
#endif

#ifndef HEVModeReq_AUTO
#define HEVModeReq_AUTO (5U)
#endif

#ifndef EngStartType_NO_START_REQ
#define EngStartType_NO_START_REQ (0U)
#endif

#ifndef EngStartType_STARTER_START
#define EngStartType_STARTER_START (1U)
#endif

#ifndef EngStartType_MOTOR_START
#define EngStartType_MOTOR_START (2U)
#endif

#ifndef EngStartType_MOTOR_RECOVERY
#define EngStartType_MOTOR_RECOVERY (3U)
#endif

#ifndef EngStartType_ENGINE_RECOVERY
#define EngStartType_ENGINE_RECOVERY (4U)
#endif

#ifndef EngStartType_CLUTCH_SLIP_START
#define EngStartType_CLUTCH_SLIP_START (5U)
#endif

#ifndef NMStatus_SLEEPMODE
#define NMStatus_SLEEPMODE (0U)
#endif

#ifndef NMStatus_CANDISABLE
#define NMStatus_CANDISABLE (1U)
#endif

#ifndef NMStatus_VCUSLEEPWAIT
#define NMStatus_VCUSLEEPWAIT (2U)
#endif

#ifndef NMStatus_NORMALWAKED
#define NMStatus_NORMALWAKED (3U)
#endif

#ifndef NMStatus_NORMALOPERATION
#define NMStatus_NORMALOPERATION (4U)
#endif

#ifndef PmmMode_INACTIVEDRIVE
#define PmmMode_INACTIVEDRIVE (0U)
#endif

#ifndef PmmMode_DRIVE
#define PmmMode_DRIVE (1U)
#endif

#ifndef PmmMode_CHARGE
#define PmmMode_CHARGE (2U)
#endif

#ifndef PmmMode_DRIVEINHIBIT
#define PmmMode_DRIVEINHIBIT (3U)
#endif

#ifndef PmmMode_AFTERRUN
#define PmmMode_AFTERRUN (4U)
#endif

#ifndef PmmMode_SHUTDOWNWAIT
#define PmmMode_SHUTDOWNWAIT (5U)
#endif

#ifndef PmmMode_SHUTDOWN
#define PmmMode_SHUTDOWN (6U)
#endif

/*
************************************************************************************************************************
*    Definitions for Mode Management.
************************************************************************************************************************
*/

#ifdef __cplusplus
}
#endif
#endif /* RTE_SWC_VOMM_TYPE_H_ */
 
 
 
