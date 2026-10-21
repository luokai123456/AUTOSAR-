/**
* @file sema42_lld.h
* @version 3.0.0
**@brief   AUTOSAR ADC Rte - module interface.
* @details This file mainly contains reentrant interfaces and multi - core mutually exclusive interface definitions
*
* @addtogroup
* @{
*/
/****************************************************************************
*
* Copyright (c) 2022  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Base
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    sema42_lld.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Rte MCAL driver.
*
*   @addtogroup Rte
*   @{
*/

#ifndef SEMA42_DRIVER_H
#define SEMA42_DRIVER_H

 /*PRQA S 3432,1535 EOF*/
/*===================================================================================================
 *                                       INCLUDE FILES
 ====================================================================================================*/
#include "derivative.h"
#include "status.h"
#include "compiler_api.h"
#include "compiler.h"
#include "mcal.h"
/*===================================================================================================
 *                                       LOCAL MEMMAP
 ====================================================================================================*/

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define SEMA_START_SEC_CONFIG_DATA           __attribute__ ((section (".mcal_sema_rodata")))
#define SEMA_STOP_SEC_CONFIG_DATA
#define SEMA_START_SEC_CODE                  __attribute__ ((section (".mcal_sema_text")))
#define SEMA_STOP_SEC_CODE
#define SEMA_START_SEC_VAR_NO_INIT           __attribute__ ((section (".mcal_sema_bss")))
#define SEMA_STOP_SEC_VAR_NO_INIT
#define SEMA_START_SEC_VAR_INIT              __attribute__ ((section (".mcal_sema_data")))
#define SEMA_STOP_SEC_VAR_INIT
#define SEMA_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_sema_share")))
#define SEMA_STOP_SEC_VAR_SHARED_INIT
#define SEMA_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_sema_bss_share")))
#define SEMA_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define SEMA_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_sema_rodata")
#define SEMA_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define SEMA_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_sema_text")
#define SEMA_STOP_SEC_CODE                   PRAGMA(ghs section)
#define SEMA_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_sema_bss")
#define SEMA_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define SEMA_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_sema_data")
#define SEMA_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define SEMA_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_sema_share")))
#define SEMA_STOP_SEC_VAR_SHARED_INIT
#define SEMA_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_sema_bss_share")))
#define SEMA_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define SEMA_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_sema_rodata" a)
#define SEMA_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define SEMA_START_SEC_CODE                  PRAGMA(section ".mcal_sema_text" avx)
#define SEMA_STOP_SEC_CODE                   PRAGMA(section)
#define SEMA_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_sema_bss")
#define SEMA_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define SEMA_START_SEC_VAR_INIT              PRAGMA(section ".mcal_sema_data")
#define SEMA_STOP_SEC_VAR_INIT               PRAGMA(section)
#define SEMA_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_sema_share")
#define SEMA_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define SEMA_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_sema_bss_share")
#define SEMA_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define SEMA_START_SEC_CONFIG_DATA
#define SEMA_STOP_SEC_CONFIG_DATA
#define SEMA_START_SEC_CODE
#define SEMA_STOP_SEC_CODE
#define SEMA_START_SEC_VAR_NO_INIT
#define SEMA_STOP_SEC_VAR_NO_INIT
#define SEMA_START_SEC_VAR_INIT
#define SEMA_STOP_SEC_VAR_INIT
#define SEMA_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define SEMA_STOP_SEC_VAR_SHARED_INIT
#define SEMA_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define SEMA_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define SEMA_START_SEC_CONFIG_DATA
#define SEMA_STOP_SEC_CONFIG_DATA
#define SEMA_START_SEC_CODE
#define SEMA_STOP_SEC_CODE
#define SEMA_START_SEC_VAR_NO_INIT
#define SEMA_STOP_SEC_VAR_NO_INIT
#define SEMA_START_SEC_VAR_INIT
#define SEMA_STOP_SEC_VAR_INIT
#define SEMA_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define SEMA_STOP_SEC_VAR_SHARED_INIT
#define SEMA_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define SEMA_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define SEMA_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define SEMA_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define SEMA_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define SEMA_STOP_SEC_CODE                   PRAGMA(section)
#define SEMA_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define SEMA_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define SEMA_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define SEMA_STOP_SEC_VAR_INIT               PRAGMA(section)
#define SEMA_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define SEMA_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define SEMA_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define SEMA_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */
/*===================================================================================================
 *                                       LOCAL MACROS
 ====================================================================================================*/
#define NUMBER_OF_CORES                      5u

 /** Number of instances of the SEMA42 module. */
#define SEMA42_INSTANCE_COUNT                1u

#define SEMA42_GATE_COUNT                   16U
#define SEMA42_UNLOCKED_GATE                0U
#define SEMA42_RSTGT_FIRST_WRITE_DATA       0xE2U
#define SEMA42_RSTGT_SECOND_WRITE_DATA      0x1DU
#define SEMA42_RESET_GATE_ALL               0xFFU
/* ----------------------------------------------------------------------------
   -- SEMA42 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Register_Masks SEMA42 Register Masks
 * @{
 */

/* GATE Bit Fields */
#define SEMA42_GATE_GTFSM_MASK                   0xFu
#define SEMA42_GATE_GTFSM_SHIFT                  0u
#define SEMA42_GATE_GTFSM_WIDTH                  4u
#define SEMA42_GATE_GTFSM(x)                     (((uint8_t)(x)) & SEMA42_GATE_GTFSM_MASK)
/* RSTGT_R Bit Fields */
#define SEMA42_RSTGT_R_RSTGTN_MASK               0xFFu
#define SEMA42_RSTGT_R_RSTGTN_SHIFT              0u
#define SEMA42_RSTGT_R_RSTGTN_WIDTH              8u
#define SEMA42_RSTGT_R_RSTGTN(x)                 (((uint16_t)(((uint16_t)(x))<<SEMA42_RSTGT_R_RSTGTN_SHIFT))&SEMA42_RSTGT_R_RSTGTN_MASK)
#define SEMA42_RSTGT_R_RSTGMS_MASK               0xF00u
#define SEMA42_RSTGT_R_RSTGMS_SHIFT              8u
#define SEMA42_RSTGT_R_RSTGMS_WIDTH              4u
#define SEMA42_RSTGT_R_RSTGMS(x)                 (((uint16_t)(((uint16_t)(x))<<SEMA42_RSTGT_R_RSTGMS_SHIFT))&SEMA42_RSTGT_R_RSTGMS_MASK)
#define SEMA42_RSTGT_R_RSTGSM_MASK               0x3000u
#define SEMA42_RSTGT_R_RSTGSM_SHIFT              12u
#define SEMA42_RSTGT_R_RSTGSM_WIDTH              2u
#define SEMA42_RSTGT_R_RSTGSM(x)                 (((uint16_t)(((uint16_t)(x))<<SEMA42_RSTGT_R_RSTGSM_SHIFT))&SEMA42_RSTGT_R_RSTGSM_MASK)
/* RSTGT_W Bit Fields */
#define SEMA42_RSTGT_W_RSTGTN_MASK               0xFFu
#define SEMA42_RSTGT_W_RSTGTN_SHIFT              0u
#define SEMA42_RSTGT_W_RSTGTN_WIDTH              8u
#define SEMA42_RSTGT_W_RSTGTN(x)                 (((uint16_t)(x)) & SEMA42_RSTGT_W_RSTGTN_MASK)
#define SEMA42_RSTGT_W_RSTGDP_MASK               0xFF00u
#define SEMA42_RSTGT_W_RSTGDP_SHIFT              8u
#define SEMA42_RSTGT_W_RSTGDP_WIDTH              8u
#define SEMA42_RSTGT_W_RSTGDP(x)                 (((uint16_t)(((uint16_t)(x))<<SEMA42_RSTGT_W_RSTGDP_SHIFT))&SEMA42_RSTGT_W_RSTGDP_MASK)
/*===================================================================================================
 *                                       LOCAL CONSTANTS
 ====================================================================================================*/
/*===================================================================================================
 *                                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ====================================================================================================*/

typedef enum
{
    Z7_0,
    Z7_1,
    Z4_2,
    Z7_3_Check,
    Z0_4_HSM,
    CORE_BUTT,
} CORE_ID;

typedef enum 
{
    SEMA42_0,
    SEMA42_BUTT,
} SEMA42_ID;

typedef enum 
{
    SEMA42_GATE_0,
    SEMA42_GATE_1,
    SEMA42_GATE_2,
    SEMA42_GATE_3,
    SEMA42_GATE_4,
    SEMA42_GATE_5,
    SEMA42_GATE_6,
    SEMA42_GATE_7,
    SEMA42_GATE_8,
    SEMA42_GATE_9,
    SEMA42_GATE_10,
    SEMA42_GATE_11,
    SEMA42_GATE_12,
    SEMA42_GATE_13,
    SEMA42_GATE_14,
    SEMA42_GATE_15,
    SEMA42_GATE_BUTT,
} GATE_NUM;

/*===================================================================================================
 *                                       FUNCTION PROTOTYPES
 ====================================================================================================*/

SEMA_START_SEC_CODE
FUNC(uint8, RTE_CODE) SEMA42_ExpectedValue(void);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(void, RTE_CODE) SEMA42_LLD_Init
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(status_t, RTE_CODE) SEMA42_LLD_LockGate
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(status_t, RTE_CODE) SEMA42_LLD_UnlockGate
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(status_t, RTE_CODE) SEMA42_LLD_CheckLock
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    VAR(uint32,         RTE_VAR) timeout \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(uint8, RTE_CODE) SEMA42_LLD_GetGateLocker
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(void, RTE_CODE) SEMA42_LLD_ResetGate
( \
    CONST(SEMA42_ID,    RTE_VAR) instance, \
    CONST(GATE_NUM,     RTE_VAR) gatenum \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(boolean, RTE_CODE) SEMA42_LLD_IsResetGateStateIdle
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(uint8, RTE_CODE) SEMA42_LLD_GetResetGateBusMaster
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(uint8, RTE_CODE) SEMA42_LLD_GetResetGateIndex
( \
    CONST(SEMA42_ID,    RTE_VAR) instance \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(status_t, RTE_CODE) SEMA42_UnlockGate
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    CONST(uint8,        RTE_VAR) processor_num \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(status_t, RTE_CODE) SEMA42_LockGate
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    CONST(uint8,        RTE_VAR) processor_num \
);
SEMA_STOP_SEC_CODE

SEMA_START_SEC_CODE
FUNC(status_t, RTE_CODE) SEMA42_CheckLock
( \
    P2VAR(SEMA42_Type,  RTE_VAR, RTE_APPL_DATA) base, \
    CONST(GATE_NUM,     RTE_VAR) gatenum, \
    CONST(uint8,        RTE_VAR) processor_num, \
    VAR(uint32,         RTE_VAR) timeout \
);
SEMA_STOP_SEC_CODE

#endif
