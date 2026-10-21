/*
********************************************************************************
*
* File name: FiM_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yaoxingjia/2019.08.28
* Change: New create.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Liuziyang/2019.11.13
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 3.0
* Author/Date :liuziyang/2020.03.27
* Change: Nothing
* Cause: Update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date: Liuziyang/2020.05.19
* Change: Modify file format.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: Liuziyang/2020.09.15
* Change: Remove the 1-byte alignment rule.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: Liuziyang/2020.09.28
* Change: Add the Rte_FiM_Type.h.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: LiuZY/2020.11.14
* Change: Modify the code review record.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: XieYN/2021.08.12
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: ChenQJ/2023.12.26
* Change: Delete no use type.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: TianG/2024.05.10
* Change: Modify format of comment.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: TianG/2024.06.28
* Change: Modify copyright.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: TianG/2024.08.27
* Change: Modify copyright.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: TianG/2024.09.24
* Change: Delete type definitions of FiM_FunctionIdType.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: TianSL/2025.06.12
* Change: Add the polyspace deviation suppression comment.
* Cause: Bugfix
********************************************************************************
*/
#ifndef FIM_TYPES_H_
#define FIM_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Rte_FiM_Type.h"
#include "Dem_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Inhibition mask type. */
/* polyspace-bigen MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define FIM_LAST_FAILED                     (0U)
#define FIM_NOT_TESTED                      (1U)
#define FIM_TESTED                          (2U)
#define FIM_TESTED_AND_FAILED               (3U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Config type. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_FiM_RuleD4.8" */
{
    uint8 noConfigType;
} FiM_ConfigType;

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

#endif  /* FIM_TYPES_H_ */

