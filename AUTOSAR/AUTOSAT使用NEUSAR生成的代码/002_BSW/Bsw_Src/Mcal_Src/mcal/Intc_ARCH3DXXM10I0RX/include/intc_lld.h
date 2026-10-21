/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     intc_lld.h
* @version  3.0.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*
*****************************************************************************/
#ifndef INTC_LLD_H_
#define INTC_LLD_H_

#include "stdbool.h"
#include "derivative.h"
#include "status.h"
#include "Mcu_LLDriver.h"
/****************************************************************************/

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define INTC_START_SEC_CONFIG_DATA           __attribute__ ((section (".mcal_intc_rodata")))
#define INTC_STOP_SEC_CONFIG_DATA
#define INTC_START_SEC_CODE                  __attribute__ ((section (".mcal_intc_text")))
#define INTC_STOP_SEC_CODE
#define INTC_START_SEC_VAR_NO_INIT           __attribute__ ((section (".mcal_intc_bss")))
#define INTC_STOP_SEC_VAR_NO_INIT
#define INTC_START_SEC_VAR_INIT              __attribute__ ((section (".mcal_intc_data")))
#define INTC_STOP_SEC_VAR_INIT
#define INTC_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_intc_share")))
#define INTC_STOP_SEC_VAR_SHARED_INIT
#define INTC_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_intc_bss_share")))
#define INTC_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define INTC_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_intc_rodata")
#define INTC_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define INTC_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_intc_text")
#define INTC_STOP_SEC_CODE                   PRAGMA(ghs section)
#define INTC_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_intc_bss")
#define INTC_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define INTC_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_intc_data")
#define INTC_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define INTC_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_intc_share")))
#define INTC_STOP_SEC_VAR_SHARED_INIT
#define INTC_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_intc_bss_share")))
#define INTC_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define INTC_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_intc_rodata" a)
#define INTC_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define INTC_START_SEC_CODE                  PRAGMA(section ".mcal_intc_text" avx)
#define INTC_STOP_SEC_CODE                   PRAGMA(section)
#define INTC_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_intc_bss")
#define INTC_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define INTC_START_SEC_VAR_INIT              PRAGMA(section ".mcal_intc_data")
#define INTC_STOP_SEC_VAR_INIT               PRAGMA(section)
#define INTC_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_intc_share")
#define INTC_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define INTC_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_intc_bss_share")
#define INTC_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define INTC_START_SEC_CONFIG_DATA
#define INTC_STOP_SEC_CONFIG_DATA
#define INTC_START_SEC_CODE
#define INTC_STOP_SEC_CODE
#define INTC_START_SEC_VAR_NO_INIT
#define INTC_STOP_SEC_VAR_NO_INIT
#define INTC_START_SEC_VAR_INIT
#define INTC_STOP_SEC_VAR_INIT
#define INTC_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define INTC_STOP_SEC_VAR_SHARED_INIT
#define INTC_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define INTC_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define INTC_START_SEC_CONFIG_DATA
#define INTC_STOP_SEC_CONFIG_DATA
#define INTC_START_SEC_CODE
#define INTC_STOP_SEC_CODE
#define INTC_START_SEC_VAR_NO_INIT
#define INTC_STOP_SEC_VAR_NO_INIT
#define INTC_START_SEC_VAR_INIT
#define INTC_STOP_SEC_VAR_INIT
#define INTC_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define INTC_STOP_SEC_VAR_SHARED_INIT
#define INTC_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define INTC_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                            _Pragma(#x)
#define INTC_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define INTC_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define INTC_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define INTC_STOP_SEC_CODE                   PRAGMA(section)
#define INTC_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define INTC_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define INTC_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define INTC_STOP_SEC_VAR_INIT               PRAGMA(section)
#define INTC_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define INTC_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define INTC_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define INTC_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */

#define INTC_SUPPORT_CORE_NUM 4U

typedef enum {
    INTC_MODE_SOFTWARE_VECTOR,
    INTC_MODE_HARDWARE_VECTOR,
    INTC_MODE_BNUTT,
} IntcMode;

typedef void(* IntrHandle)(void);

INTC_START_SEC_CODE
void INTC_LLD_Reset_IRQ_Status(void);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
void INTC_LLD_Set_Vector_Prefix(register uint32_t prefix);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
void INTC_LLD_Set_Vector_Table(uint32_t vector_table);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Disable(IntrId intr_id);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Enable(IntrId intr_id);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
void INTC_LLD_Set_Global_Disable(void);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
void INTC_LLD_Set_Global_Enable(void);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Priority(IntrId intr_id, IntrPrior intr_prior);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_Global_Priority(IntrPrior intr_prior);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_IRQ_Handle(IntrId intr_id, IntrHandle intr_handle);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
IntrId INTC_LLD_Get_Cur_IRQ_Id(void);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Swtich_Mode(IntcMode intc_mode);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Set_Soft_IRQ(uint8_t instance, IntrId intr_id);
INTC_STOP_SEC_CODE

INTC_START_SEC_CODE
status_t INTC_LLD_Clr_Soft_IRQ(uint8_t instance, IntrId intr_id);
INTC_STOP_SEC_CODE

#endif
