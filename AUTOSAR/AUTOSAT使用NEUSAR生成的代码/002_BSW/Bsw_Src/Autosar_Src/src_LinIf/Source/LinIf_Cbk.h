/*
********************************************************************************
*
* File name: LinIf_Cbk.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.03.26
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: lizhiheng/2020.07.01
* Change: Tab to spaces.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.08.25
* Change: Modify function declaration.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.09.26
* Change: 1.Modify the code to AutoSar coding style.
*         2.Add memap inclusion processing.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiZH/2020.09.30
* Change: Modify the code comment.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: LiZH/2020.10.15
* Change: Modify AutoSar style non-pointer type modification.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2020.11.04
* Change:  Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2021.07.29
* Change: Add "LinIf_Cfg.h" file references because of compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: SunHQ/2022.12.9
* Change: Modify the included header file.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: LiXB/2023.10.25
* Change: Update version to R21-11.
* Cause: Update
********************************************************************************
* Version: 3.9
* Author/Date: TianG/2024.06.27
* Change: 1. Modify copyright.
*         2. Modify the comments format.
*         3. Add a memory-map label to function.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: YanCL/2025.06.23
* Change: #include "LinIf_MemMap.h" add suppression comments.
* Cause: Update
********************************************************************************
*/
#ifndef LINIF_CBK_H_
#define LINIF_CBK_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "LinIf_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define LINIF_START_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"
#if( LINIF_ADAPTED_AR_VERSION == LINIF_AR_VERSION_BEFORE_440 )
#if ( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
extern FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
);
#endif
#endif
#define LINIF_STOP_SEC_CODE
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "LinIf_MemMap.h"

#endif /* LINIF_CBK_H_ */

