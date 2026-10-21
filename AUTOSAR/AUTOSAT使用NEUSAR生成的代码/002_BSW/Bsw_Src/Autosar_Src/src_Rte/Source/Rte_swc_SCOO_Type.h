 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SCOO_Type.h
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
#ifndef RTE_SWC_SCOO_TYPE_H_
#define RTE_SWC_SCOO_TYPE_H_

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

#ifndef CrsBtnErrSts_NONE
#define CrsBtnErrSts_NONE (0U)
#endif

#ifndef CrsBtnErrSts_CRUISE_STUCK
#define CrsBtnErrSts_CRUISE_STUCK (1U)
#endif

#ifndef CrsBtnErrSts_SET_STUCK
#define CrsBtnErrSts_SET_STUCK (2U)
#endif

#ifndef CrsBtnErrSts_RESUME_STUCK
#define CrsBtnErrSts_RESUME_STUCK (3U)
#endif

#ifndef CrsBtnErrSts_VOLTAGE_ABNORMAL
#define CrsBtnErrSts_VOLTAGE_ABNORMAL (7U)
#endif

#ifndef CrsBtnErrSts_VOLTAGE_SCB
#define CrsBtnErrSts_VOLTAGE_SCB (8U)
#endif

#ifndef CrsBtnErrSts_VOLTAGE_SCG
#define CrsBtnErrSts_VOLTAGE_SCG (9U)
#endif

#ifndef CrsBtnErrSts_VOLTAGE_OC
#define CrsBtnErrSts_VOLTAGE_OC (10U)
#endif

#ifndef CrsBtnSts_NONE
#define CrsBtnSts_NONE (0U)
#endif

#ifndef CrsBtnSts_CRUISE_MAIN
#define CrsBtnSts_CRUISE_MAIN (1U)
#endif

#ifndef CrsBtnSts_SET
#define CrsBtnSts_SET (2U)
#endif

#ifndef CrsBtnSts_RESUME
#define CrsBtnSts_RESUME (3U)
#endif

#ifndef CrModeMngr_e_ACTIVE_KEEP
#define CrModeMngr_e_ACTIVE_KEEP (0U)
#endif

#ifndef CrModeMngr_e_ACCEL
#define CrModeMngr_e_ACCEL (1U)
#endif

#ifndef CrModeMngr_e_DECEL
#define CrModeMngr_e_DECEL (2U)
#endif

#ifndef CrModeMngr_e_ACTIVE_RESUME
#define CrModeMngr_e_ACTIVE_RESUME (3U)
#endif

#ifndef CrModeMngr_e_TIP_IN
#define CrModeMngr_e_TIP_IN (4U)
#endif

#ifndef CrModeMngr_e_TIP_OUT
#define CrModeMngr_e_TIP_OUT (5U)
#endif

#ifndef CrModeMngr_e_OFF
#define CrModeMngr_e_OFF (6U)
#endif

#ifndef CruiseSts_e_OFF
#define CruiseSts_e_OFF (0U)
#endif

#ifndef CruiseSts_e_STANDBY
#define CruiseSts_e_STANDBY (1U)
#endif

#ifndef CruiseSts_e_ACTIVE
#define CruiseSts_e_ACTIVE (2U)
#endif

#ifndef CruiseSts_e_OVERRIDE
#define CruiseSts_e_OVERRIDE (3U)
#endif

#ifndef CruiseSts_e_INVALID
#define CruiseSts_e_INVALID (4U)
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

/*
************************************************************************************************************************
*    Definitions for Mode Management.
************************************************************************************************************************
*/

#ifdef __cplusplus
}
#endif
#endif /* RTE_SWC_SCOO_TYPE_H_ */
 
 
 
