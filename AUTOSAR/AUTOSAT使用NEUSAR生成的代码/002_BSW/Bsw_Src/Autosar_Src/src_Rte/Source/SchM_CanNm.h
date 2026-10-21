 
/*
************************************************************************************************************************
*
* File name: SchM_CanNm.h
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
/*
************************************************************************************************************************
*    double include preventio and include files
************************************************************************************************************************
*/
#ifndef SCHM_CANNM_H
#define SCHM_CANNM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SchM_CanNm_Type.h"

/*
************************************************************************************************************************
*    MainFuntion prototypes
************************************************************************************************************************
*/
FUNC(void, CANNM_CODE) CanNm_MainFunction(void);

/*
************************************************************************************************************************
*    Exclusive_area prototypes
************************************************************************************************************************
*/
FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_0(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_0(void);

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_1(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_1(void);

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_2(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_2(void);

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_3(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_3(void);

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_4(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_4(void);

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_5(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_5(void);

FUNC(void, RTE_CODE) SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_6(void);

FUNC(void, RTE_CODE) SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_6(void);


#ifdef __cplusplus
}
#endif

#endif /* SCHM_CANNM_H */

 
 
 
