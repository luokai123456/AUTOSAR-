 
/*
************************************************************************************************************************
*
* File name: Rte_swc_AUXC_Type.h
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
#ifndef RTE_SWC_AUXC_TYPE_H_
#define RTE_SWC_AUXC_TYPE_H_

#include "Rte_Type.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
************************************************************************************************************************
*    Range, Invalidation, Enumeration and Bit Field Definitions.
************************************************************************************************************************
*/
#ifndef DCDCMode_HV_OFF
#define DCDCMode_HV_OFF (0U)
#endif

#ifndef DCDCMode_STANDBY
#define DCDCMode_STANDBY (1U)
#endif

#ifndef DCDCMode_ACTIVE
#define DCDCMode_ACTIVE (2U)
#endif

#ifndef DCDCMode_FAILURE
#define DCDCMode_FAILURE (5U)
#endif

#ifndef DCDCMode_SHUTDOWN
#define DCDCMode_SHUTDOWN (7U)
#endif

#ifndef DCDCMode_HV_ACTIVE_DISCHARGE
#define DCDCMode_HV_ACTIVE_DISCHARGE (8U)
#endif

#ifndef DCDCMode_HV_PASSIVE_DISCHARGE
#define DCDCMode_HV_PASSIVE_DISCHARGE (9U)
#endif

#ifndef DCDCMode_INVALID
#define DCDCMode_INVALID (10U)
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

#ifndef EngineState_OFF
#define EngineState_OFF (0U)
#endif

#ifndef EngineState_RUNNING
#define EngineState_RUNNING (1U)
#endif

#ifndef EngineState_CRANKING
#define EngineState_CRANKING (2U)
#endif

#ifndef EngineState_STOPPING
#define EngineState_STOPPING (3U)
#endif

#ifndef EngineState_RECOVERY
#define EngineState_RECOVERY (4U)
#endif

#ifndef EngineState_STALLED
#define EngineState_STALLED (5U)
#endif

#ifndef EngineState_CRANK_FAILED
#define EngineState_CRANK_FAILED (6U)
#endif

#ifndef EngineState_FAILURE
#define EngineState_FAILURE (7U)
#endif

#ifndef EngineState_INVALID
#define EngineState_INVALID (8U)
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

/*
************************************************************************************************************************
*    Definitions for Mode Management.
************************************************************************************************************************
*/

#ifdef __cplusplus
}
#endif
#endif /* RTE_SWC_AUXC_TYPE_H_ */
 
 
 
