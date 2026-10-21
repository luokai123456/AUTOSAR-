 
/*
************************************************************************************************************************
*
* File name: Rte_swc_HMIF_Type.h
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
#ifndef RTE_SWC_HMIF_TYPE_H_
#define RTE_SWC_HMIF_TYPE_H_

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

#ifndef HVBRelayStatus_RESERVED
#define HVBRelayStatus_RESERVED (0U)
#endif

#ifndef HVBRelayStatus_OPEN
#define HVBRelayStatus_OPEN (1U)
#endif

#ifndef HVBRelayStatus_CLOSED
#define HVBRelayStatus_CLOSED (2U)
#endif

#ifndef HVBRelayStatus_INVALID
#define HVBRelayStatus_INVALID (3U)
#endif

#ifndef PowerFlowMode_OFF
#define PowerFlowMode_OFF (0U)
#endif

#ifndef PowerFlowMode_EV
#define PowerFlowMode_EV (1U)
#endif

#ifndef PowerFlowMode_ICE_MSG
#define PowerFlowMode_ICE_MSG (2U)
#endif

#ifndef PowerFlowMode_PHEV
#define PowerFlowMode_PHEV (3U)
#endif

#ifndef PowerFlowMode_REGEN
#define PowerFlowMode_REGEN (4U)
#endif

#ifndef PowerFlowMode_SERIES
#define PowerFlowMode_SERIES (5U)
#endif

#ifndef PowerFlowMode_PARK_GEN
#define PowerFlowMode_PARK_GEN (6U)
#endif

#ifndef PowerFlowMode_DRIVE_GEN
#define PowerFlowMode_DRIVE_GEN (7U)
#endif

#ifndef PmmStatus_OFF
#define PmmStatus_OFF (0U)
#endif

#ifndef PmmStatus_HCMWAKEUP
#define PmmStatus_HCMWAKEUP (1U)
#endif

#ifndef PmmStatus_MCUWAKEUP
#define PmmStatus_MCUWAKEUP (2U)
#endif

#ifndef PmmStatus_DRVBMSNEGCLOSE
#define PmmStatus_DRVBMSNEGCLOSE (3U)
#endif

#ifndef PmmStatus_CHGBMSNEGCLOSE
#define PmmStatus_CHGBMSNEGCLOSE (4U)
#endif

#ifndef PmmStatus_HCMNEGCLOSE
#define PmmStatus_HCMNEGCLOSE (5U)
#endif

#ifndef PmmStatus_ASSISTCLOSE
#define PmmStatus_ASSISTCLOSE (6U)
#endif

#ifndef PmmStatus_DCDCACT
#define PmmStatus_DCDCACT (7U)
#endif

#ifndef PmmStatus_STANDBYDRV
#define PmmStatus_STANDBYDRV (8U)
#endif

#ifndef PmmStatus_CHARGE
#define PmmStatus_CHARGE (9U)
#endif

#ifndef PmmStatus_IMMOCHECK
#define PmmStatus_IMMOCHECK (10U)
#endif

#ifndef PmmStatus_SDCACACT
#define PmmStatus_SDCACACT (11U)
#endif

#ifndef PmmStatus_MAINPOSCLOSE
#define PmmStatus_MAINPOSCLOSE (12U)
#endif

#ifndef PmmStatus_BDCACACT
#define PmmStatus_BDCACACT (13U)
#endif

#ifndef PmmStatus_MCUACT
#define PmmStatus_MCUACT (14U)
#endif

#ifndef PmmStatus_DRIVE
#define PmmStatus_DRIVE (15U)
#endif

#ifndef PmmStatus_SHUTDOWNWAIT
#define PmmStatus_SHUTDOWNWAIT (16U)
#endif

#ifndef PmmStatus_HVDEVICEDEACT
#define PmmStatus_HVDEVICEDEACT (17U)
#endif

#ifndef PmmStatus_MCUDEACT
#define PmmStatus_MCUDEACT (18U)
#endif

#ifndef PmmStatus_MAINPOSOPEN
#define PmmStatus_MAINPOSOPEN (19U)
#endif

#ifndef PmmStatus_HVDEVICEDEACTEMGY
#define PmmStatus_HVDEVICEDEACTEMGY (20U)
#endif

#ifndef PmmStatus_MAINPOSOPENEMGY
#define PmmStatus_MAINPOSOPENEMGY (21U)
#endif

#ifndef PmmStatus_ASSISTOPEN
#define PmmStatus_ASSISTOPEN (22U)
#endif

#ifndef PmmStatus_HCMNEGOPEN
#define PmmStatus_HCMNEGOPEN (23U)
#endif

#ifndef PmmStatus_ASSISTOPENEMGY
#define PmmStatus_ASSISTOPENEMGY (24U)
#endif

#ifndef PmmStatus_HCMNEGOPENEMGY
#define PmmStatus_HCMNEGOPENEMGY (25U)
#endif

#ifndef PmmStatus_MCUDISCHARGE
#define PmmStatus_MCUDISCHARGE (26U)
#endif

#ifndef PmmStatus_BMSNEGOPEN
#define PmmStatus_BMSNEGOPEN (27U)
#endif

#ifndef PmmStatus_LVCUTREQUEST
#define PmmStatus_LVCUTREQUEST (28U)
#endif

#ifndef PmmStatus_LVCUTWAIT
#define PmmStatus_LVCUTWAIT (29U)
#endif

#ifndef PmmStatus_AFTERRUN
#define PmmStatus_AFTERRUN (30U)
#endif

#ifndef PmmStatus_INIT
#define PmmStatus_INIT (31U)
#endif

#ifndef PmmStatus_BMSNEGOPENEMGY
#define PmmStatus_BMSNEGOPENEMGY (32U)
#endif

#ifndef PmmStatus_LOWTEMPON
#define PmmStatus_LOWTEMPON (33U)
#endif

#ifndef PmmStatus_LOWTEMPOFF
#define PmmStatus_LOWTEMPOFF (34U)
#endif

#ifndef PmmStatus_CHGWAIT
#define PmmStatus_CHGWAIT (35U)
#endif

#ifndef PmmStatus_STANDBYDRVCONV
#define PmmStatus_STANDBYDRVCONV (36U)
#endif

#ifndef PmmStatus_VEHSTART
#define PmmStatus_VEHSTART (37U)
#endif

#ifndef PmmStatus_INTELCHG
#define PmmStatus_INTELCHG (38U)
#endif

#ifndef PmmStatus_TIMEOUT
#define PmmStatus_TIMEOUT (39U)
#endif

#ifndef PmmStatus_SHUTDOWNWAITEMGY
#define PmmStatus_SHUTDOWNWAITEMGY (40U)
#endif

#ifndef PmmStatus_HVSHUTDNEMGY
#define PmmStatus_HVSHUTDNEMGY (41U)
#endif

#ifndef PmmStatus_DISCHARGE
#define PmmStatus_DISCHARGE (42U)
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

#ifndef HybModeMngr_PT_OFF
#define HybModeMngr_PT_OFF (0U)
#endif

#ifndef HybModeMngr_PT_ENA
#define HybModeMngr_PT_ENA (1U)
#endif

#ifndef HybModeMngr_ICE_MODE
#define HybModeMngr_ICE_MODE (2U)
#endif

#ifndef HybModeMngr_PHEV_MODE
#define HybModeMngr_PHEV_MODE (3U)
#endif

#ifndef HybModeMngr_SHEV_MODE
#define HybModeMngr_SHEV_MODE (4U)
#endif

#ifndef HybModeMngr_EV_MODE
#define HybModeMngr_EV_MODE (5U)
#endif

#ifndef HybModeMngr_SHUTDOWN
#define HybModeMngr_SHUTDOWN (9U)
#endif

#ifndef HybModeMngr_PTENA2ICE
#define HybModeMngr_PTENA2ICE (12U)
#endif

#ifndef HybModeMngr_PTENA2PHEV
#define HybModeMngr_PTENA2PHEV (13U)
#endif

#ifndef HybModeMngr_PTENA2SHEV
#define HybModeMngr_PTENA2SHEV (14U)
#endif

#ifndef HybModeMngr_PTENA2EV
#define HybModeMngr_PTENA2EV (15U)
#endif

#ifndef HybModeMngr_ICE2PTENA
#define HybModeMngr_ICE2PTENA (21U)
#endif

#ifndef HybModeMngr_ICE2PHEV
#define HybModeMngr_ICE2PHEV (23U)
#endif

#ifndef HybModeMngr_PHEV2PTENA
#define HybModeMngr_PHEV2PTENA (31U)
#endif

#ifndef HybModeMngr_PHEV2ICE
#define HybModeMngr_PHEV2ICE (32U)
#endif

#ifndef HybModeMngr_PHEV2SHEV
#define HybModeMngr_PHEV2SHEV (34U)
#endif

#ifndef HybModeMngr_PHEV2EV
#define HybModeMngr_PHEV2EV (35U)
#endif

#ifndef HybModeMngr_SHEV2PTENA
#define HybModeMngr_SHEV2PTENA (41U)
#endif

#ifndef HybModeMngr_SHEV2PHEV
#define HybModeMngr_SHEV2PHEV (43U)
#endif

#ifndef HybModeMngr_SHEV2EV
#define HybModeMngr_SHEV2EV (45U)
#endif

#ifndef HybModeMngr_EV2PTENA
#define HybModeMngr_EV2PTENA (51U)
#endif

#ifndef HybModeMngr_EV2PHEV
#define HybModeMngr_EV2PHEV (53U)
#endif

#ifndef HybModeMngr_EV2SHEV
#define HybModeMngr_EV2SHEV (54U)
#endif

/*
************************************************************************************************************************
*    Definitions for Mode Management.
************************************************************************************************************************
*/

#ifdef __cplusplus
}
#endif
#endif /* RTE_SWC_HMIF_TYPE_H_ */
 
 
 
