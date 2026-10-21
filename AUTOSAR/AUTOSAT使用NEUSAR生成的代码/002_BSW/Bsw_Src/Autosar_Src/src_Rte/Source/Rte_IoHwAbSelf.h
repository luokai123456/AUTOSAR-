/*
************************************************************************************************************************
*
* File name: Rte_IoHwAbSelf.h
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
#ifndef RTE_IOHWABSELF_H_
#define RTE_IOHWABSELF_H_
/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Rte_Type.h"
#include "Os.h"

/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    RTE Helper-Functions prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_IRead_<r>_<p>_<d>
*    Rte_IStatus_<r>_<p>_<d>
*    Rte_IWrite_<r>_<p>_<d>
*    Rte_IWriteRef_<r>_<p>_<d>
*    Rte_IInvalidate_<r>_<p>_<d>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Periodic Runnable entities 
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) CanNm_UserWakeUp(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_App_5ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Bsw_5ms(void);
FUNC(void, RTE_CODE) Core0_Runnable_Task_10ms_ASILA(void);
FUNC(void, RTE_CODE) Core0_Runnable_Task_10ms_ASILB(void);
FUNC(void, RTE_CODE) Core0_Runnable_Task_10ms_ASILC(void);
FUNC(void, RTE_CODE) Core0_Runnable_Task_10ms_ASILG(void);
FUNC(void, RTE_CODE) Core0_Runnable_Task_Init(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_App_5ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Bsw_5ms(void);
FUNC(void, RTE_CODE) Core1_Runnable_Task_10ms_ASILA(void);
FUNC(void, RTE_CODE) Core1_Runnable_Task_10ms_ASILB(void);
FUNC(void, RTE_CODE) Core1_Runnable_Task_10ms_ASILC(void);
FUNC(void, RTE_CODE) Core1_Runnable_Task_10ms_ASILG(void);
FUNC(void, RTE_CODE) Core1_Runnable_Task_Init(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_App_5ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Bsw_5ms(void);
FUNC(void, RTE_CODE) Core2_Runnable_Task_10ms_ASILA(void);
FUNC(void, RTE_CODE) Core2_Runnable_Task_10ms_ASILB(void);
FUNC(void, RTE_CODE) Core2_Runnable_Task_10ms_ASILC(void);
FUNC(void, RTE_CODE) Core2_Runnable_Task_10ms_ASILG(void);
FUNC(void, RTE_CODE) Core2_Runnable_Task_Init(void);
FUNC(void, RTE_CODE) Core3_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Bsw_5ms(void);
FUNC(void, RTE_CODE) Core3_Runnable_Task_10ms_ASILA(void);
FUNC(void, RTE_CODE) Core3_Runnable_Task_10ms_ASILB(void);
FUNC(void, RTE_CODE) Core3_Runnable_Task_10ms_ASILC(void);
FUNC(void, RTE_CODE) Core3_Runnable_Task_10ms_ASILG(void);
FUNC(void, RTE_CODE) Core3_Runnable_Task_Init(void);
FUNC(void, RTE_CODE) Core4_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_App_5ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Bsw_5ms(void);
FUNC(void, RTE_CODE) Core4_Runnable_Task_10ms_ASILA(void);
FUNC(void, RTE_CODE) Core4_Runnable_Task_10ms_ASILB(void);
FUNC(void, RTE_CODE) Core4_Runnable_Task_10ms_ASILC(void);
FUNC(void, RTE_CODE) Core4_Runnable_Task_10ms_ASILG(void);
FUNC(void, RTE_CODE) Core4_Runnable_Task_Init(void);
FUNC(void, RTE_CODE) Core5_Runnable_App_100ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_App_10ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_App_1ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_App_20ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_App_50ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_App_5ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_100ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_10ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_1ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_20ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_50ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Bsw_5ms(void);
FUNC(void, RTE_CODE) Core5_Runnable_Task_10ms_ASILA(void);
FUNC(void, RTE_CODE) Core5_Runnable_Task_10ms_ASILB(void);
FUNC(void, RTE_CODE) Core5_Runnable_Task_10ms_ASILC(void);
FUNC(void, RTE_CODE) Core5_Runnable_Task_10ms_ASILG(void);
FUNC(void, RTE_CODE) Core5_Runnable_Task_Init(void);
FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic_OsCore0(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* RTE_IOHWABSELF_H_ */

