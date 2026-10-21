 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SCAP_Type.h
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
#ifndef RTE_SWC_SCAP_TYPE_H_
#define RTE_SWC_SCAP_TYPE_H_

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

#ifndef ElMac_HV_OFF
#define ElMac_HV_OFF (0U)
#endif

#ifndef ElMac_STANDBY
#define ElMac_STANDBY (1U)
#endif

#ifndef ElMac_TORQUE_CTRL
#define ElMac_TORQUE_CTRL (2U)
#endif

#ifndef ElMac_SPEED_CTRL
#define ElMac_SPEED_CTRL (3U)
#endif

#ifndef ElMac_VOLTAGE_CTRL
#define ElMac_VOLTAGE_CTRL (4U)
#endif

#ifndef ElMac_PRECHARGE
#define ElMac_PRECHARGE (5U)
#endif

#ifndef ElMac_SHUTDOWN
#define ElMac_SHUTDOWN (6U)
#endif

#ifndef ElMac_FAILURE
#define ElMac_FAILURE (7U)
#endif

#ifndef ElMac_HV_ACTIVE_DISCHARGE
#define ElMac_HV_ACTIVE_DISCHARGE (8U)
#endif

#ifndef ElMac_HV_PASSIVE_DISCHARGE
#define ElMac_HV_PASSIVE_DISCHARGE (9U)
#endif

#ifndef ElMac_INVALID
#define ElMac_INVALID (10U)
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
#endif /* RTE_SWC_SCAP_TYPE_H_ */
 
 
 
