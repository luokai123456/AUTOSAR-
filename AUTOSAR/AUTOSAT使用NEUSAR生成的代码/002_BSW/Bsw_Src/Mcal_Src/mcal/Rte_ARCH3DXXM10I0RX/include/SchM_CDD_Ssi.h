/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : RTE
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    SchM_CDD_Ssi.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/

/* PRQA S 0779, 2053, 1527 EOF */
#ifndef SCHM_CDD_SSI_H
#define SCHM_CDD_SSI_H
/*===================================================================================================
 *                                           INCLUDE FILES
 ====================================================================================================*/
#ifdef __cplusplus 
extern "C" {
#endif
#include "Compiler.h"
#include "Mcal.h"
#include "Rte_MConfig.h"

/*===================================================================================================
 *                                            LOCAL MACROS
 ====================================================================================================*/
#ifndef CDD_SSI_CORE_NUM
#define CDD_SSI_CORE_NUM                    MCAL_CORE_NUM
#endif
#define MULTICORE_CDD_SSI_TYPE              MULTICORE_TYPE_EXCLUSIVE
/*===================================================================================================
 *                                          LOCAL CONSTANTS
 ====================================================================================================*/
/*===================================================================================================
 *                               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/
/*===================================================================================================
 *                                          LOCAL VARIABLES
 ====================================================================================================*/
/*===================================================================================================
 *                                        FUNCTION PROTOTYPES
 ====================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_00(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_01(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_02(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_03(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_04(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_05(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_06(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_07(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_08(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_09(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_10(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_11(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_12(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_13(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_14(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_15(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_16(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_17(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_18(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_19(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_20(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_21(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_22(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_23(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_24(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_25(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_26(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_27(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_28(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_29(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_30(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_31(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_32(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_33(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_34(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_35(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_36(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_37(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_38(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_39(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_40(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_41(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_42(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_43(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_44(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_45(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_46(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_47(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_48(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_49(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_50(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_51(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_52(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_53(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_54(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_55(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_56(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_57(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_58(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_59(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_60(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_61(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_62(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_63(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_64(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_65(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_66(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_67(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_68(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_EXCLUSIVE_AREA_69(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_x(VAR(uint8, RTE_VAR) n);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_00(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_01(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_02(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_03(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_04(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_05(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_06(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_07(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_08(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_09(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_10(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_11(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_12(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_13(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_14(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_15(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_16(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_17(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_18(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_19(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_20(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_21(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_22(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_23(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_24(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_25(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_26(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_27(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_28(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_29(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_30(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_31(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_32(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_33(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_34(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_35(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_36(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_37(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_38(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_39(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_40(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_41(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_42(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_43(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_44(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_45(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_46(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_47(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_48(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_49(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_50(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_51(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_52(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_53(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_54(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_55(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_56(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_57(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_58(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_59(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_60(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_61(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_62(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_63(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_64(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_65(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_66(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_67(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_68(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_EXCLUSIVE_AREA_69(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/* Definition of Enter Critical Area */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_00(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_01(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_02(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_03(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_04(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_05(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_06(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_07(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_08(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Enter_CDD_Ssi_CRITICAL_AREA_09(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/* Definition of Exit Critical Area */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_00(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_01(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_02(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_03(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_04(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_05(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_06(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_07(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_08(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) SchM_Exit_CDD_Ssi_CRITICAL_AREA_09(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /* SCHM_CDD_SSI_H */

