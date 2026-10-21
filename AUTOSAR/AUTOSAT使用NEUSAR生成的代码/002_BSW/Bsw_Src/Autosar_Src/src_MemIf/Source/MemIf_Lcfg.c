/*
********************************************************************************
*
* File name: MemIf_Lcfg.c
*
* Copyright 2018-2025 Neusoft Reach Corporation.All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.11.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2019.01.05
* Change: Add configuration items.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: TongQian/2019.05.06
* Change: Replace numbers with macros.
* Cause: Optimization
********************************************************************************
* Version: 2.0
* Author/Date: WangHe/2019.11.25
* Change:Format modification.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "MemIf.h"

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
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
#define MEMIF_START_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* Interface of the underlying memory Abstract module. */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_MemIf_UsedNonSharedVariable" */
CONST(MemIf_API_Type_st, MEMIF_CONFIG_DATA) MemIf_API_Table[MEMIF_NUMBER_OF_DEVICES] =  /* PRQA S 3447 */ /* NSCA_QAC_MemIf_Rule8.5 */
{
    {
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },
    {
        Fee_SetMode,
        Fee_Read,
        Fee_Write,
        Fee_Cancel,
        Fee_GetStatus,
        Fee_GetJobResult,
        Fee_InvalidateBlock,
        Fee_EraseImmediateBlock
    }
};


#define MEMIF_STOP_SEC_CONFIG_DATA
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

