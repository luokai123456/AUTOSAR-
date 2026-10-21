/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     mcu_lld.c
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/
/*PRQA S 1258,1259,1505,2052,3108,2834,2844,2985,1503,3469,3218,0404,0654,3408,3119 EOF*/
#include "mcu_lld.h" /* PRQA S 0380 */
#include "../inc/flash_lld.h"
//#include "hsm_lld.h"
#include "compiler_api.h"
//#include "libSwap.h"
#include "Saf_MemMap.h"
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_ircoscClkFreq;    /* IRCOSC_CLK frequency          */
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_xoscClkFreq;      /* XOSC_CLK frequency             */
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_pll0Phi0ClkFreq;  /* PLL0_PHI1_CLK frequency         */
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_pll0Phi1ClkFreq;  /* PLL0_PHI1_CLK frequency         */
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_pll0VcoClkFreq;   /* PLL0_PHI1_CLK frequency         */
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_pll1VcoClkFreq;   /* PLL0_PHI1_CLK frequency         */
SAF_MCU_SEC_VAR_NO_INIT
static uint32_t g_pll1Phi0ClkFreq;  /* PLL1_PHI0_CLK frequency         */
/*******************************************************************************
 * @brief      Get current core id
 * @param[in]  None
 * @param[out] None
 * @retval     CoreId
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
Saf_CoreId SAF_MCU_LLD_Get_Core_Id(void)
{
    return (Saf_CoreId)MFSPR(SPR_PIR); /* PRQA S 0342, 1006, 4342 */
}

/*******************************************************************************
 * @brief      Get current chip mode
 * @param[in]  None
 * @param[out] None
 * @retval     ChipMode
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
ChipMode MCU_LLD_Get_Chip_Mode(void)
{
    ChipMode chip_mode;
    uint32_t me_mode = MC_ME.GS.B.S_CURRENT_MODE;

    switch (me_mode) {
        case MC_ME_MODE_RESET_FUNC: {
            chip_mode = CHIP_MODE_RESET_FUNC;
            break;
        }
        case MC_ME_MODE_TEST: {
            chip_mode = CHIP_MODE_TEST;
            break;
        }
        case MC_ME_MODE_SAFE: {
            chip_mode = CHIP_MODE_SAFE;
            break;
        }
        case MC_ME_MODE_DRUN: {
            chip_mode = CHIP_MODE_DRUN;
            break;
        }
        case MC_ME_MODE_RUN0: {
            chip_mode = CHIP_MODE_RUN0;
            break;
        }
        case MC_ME_MODE_RUN1: {
            chip_mode = CHIP_MODE_RUN1;
            break;
        }
        case MC_ME_MODE_RUN2: {
            chip_mode = CHIP_MODE_RUN2;
            break;
        }
        case MC_ME_MODE_RUN3: {
            chip_mode = CHIP_MODE_RUN3;
            break;
        }
        case MC_ME_MODE_HALT: {
            chip_mode = CHIP_MODE_HALT;
            break;
        }
        case MC_ME_MODE_STOP: {
            chip_mode = CHIP_MODE_STOP;
            break;
        }
        case MC_ME_MODE_RESET_DEST: {
            chip_mode = CHIP_MODE_RESET_DEST;
            break;
        }
        default: {
            chip_mode = CHIP_MODE_INVALID;
            break;
        }
    };

    return chip_mode;
}

/*******************************************************************************
 * @brief      Set current chip mode
 * @param[in]  ChipMode chip_mode
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Set_Chip_Mode(ChipMode chip_mode)
{
    MC_ME_MCTL_tag MCTL;

    MCTL.R = MC_ME.MCTL.R;
    switch (chip_mode) {
        case CHIP_MODE_RESET_FUNC: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_RESET_FUNC;
            break;
        }
        case CHIP_MODE_TEST: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_TEST;
            break;
        }
        case CHIP_MODE_SAFE: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_SAFE;
            break;
        }
        case CHIP_MODE_DRUN: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_DRUN;
            break;
        }
        case CHIP_MODE_RUN0: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_RUN0;
            break;
        }
        case CHIP_MODE_RUN1: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_RUN1;
            break;
        }
        case CHIP_MODE_RUN2: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_RUN2;
            break;
        }
        case CHIP_MODE_RUN3: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_RUN3;
            break;
        }
        case CHIP_MODE_HALT: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_HALT;
            break;
        }
        case CHIP_MODE_STOP: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_STOP;
            break;
        }
        case CHIP_MODE_RESET_DEST: {
            MCTL.B.TARGET_MODE = (uint32_t)MC_ME_MODE_RESET_DEST;
            break;
        }
        default: { /* PRQA S 2024 */
            return STATUS_MCU_INVALID_CHIP_MODE;
        }
    };

    MCTL.B.KEY = (uint16_t)FEATURE_MC_ME_KEY;
    MC_ME.MCTL.R = MCTL.R;
    MCTL.B.KEY = (uint16_t)FEATURE_MC_ME_KEY_INV;
    MC_ME.MCTL.R = MCTL.R;

    while (MC_ME.GS.B.S_MTRANS != 0U) {};

    return STATUS_SUCCESS;
}

#define MCU_LLD_Get_Core_Mode_Para(_CCTL, _Mode) {/* PRQA S 3472 */\
    (_Mode)->B.stop0 = (_CCTL).B.STOP0; \
    (_Mode)->B.halt0 = (_CCTL).B.HALT0; \
    (_Mode)->B.run3 = (_CCTL).B.RUN3; \
    (_Mode)->B.run2 = (_CCTL).B.RUN2; \
    (_Mode)->B.run1 = (_CCTL).B.RUN1; \
    (_Mode)->B.run0 = (_CCTL).B.RUN0; \
    (_Mode)->B.drun = (_CCTL).B.DRUN; \
    (_Mode)->B.safe = (_CCTL).B.SAFE; \
    (_Mode)->B.test = (_CCTL).B.TEST; \
    (_Mode)->B.reset = (_CCTL).B.RESET; \
}
/*******************************************************************************
 * @brief      Get core run mode
 * @param[in]  CoreId core_id, RunMode *run_mode
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Get_Core_Mode(Saf_CoreId core_id, CoreMode *core_mode)
{
    MC_ME_CCTL0_tag CCTL0;
    MC_ME_CCTL1_tag CCTL1;
    MC_ME_CCTL2_tag CCTL2;
    MC_ME_CCTL3_tag CCTL3;
    MC_ME_CCTL4_tag CCTL4;

    switch (core_id) {
        case SAF_CORE_ID_Z7_0: {
            CCTL1.R = MC_ME.CCTL1.R;
            MCU_LLD_Get_Core_Mode_Para(CCTL1, core_mode); /* PRQA S 3469 */
            break;
        }
        case SAF_CORE_ID_Z7_1: {
            CCTL3.R = MC_ME.CCTL3.R;
            MCU_LLD_Get_Core_Mode_Para(CCTL3, core_mode); /* PRQA S 3469 */
            break;
        }
        case SAF_CORE_ID_Z4_2: {
            CCTL0.R = MC_ME.CCTL0.R;
            MCU_LLD_Get_Core_Mode_Para(CCTL0, core_mode); /* PRQA S 3469 */
            break;
        }
        case SAF_CORE_ID_Z7_3_Check: {
            CCTL2.R = MC_ME.CCTL2.R;
            MCU_LLD_Get_Core_Mode_Para(CCTL2, core_mode); /* PRQA S 3469 */
            break;
        }
        case SAF_CORE_ID_Z0_4_HSM: {
            CCTL4.R = MC_ME.CCTL4.R;
            MCU_LLD_Get_Core_Mode_Para(CCTL4, core_mode); /* PRQA S 3469 */
            break;
        }
        default: { /* PRQA S 2024 */
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return STATUS_SUCCESS;
}
#define MCU_LLD_Fill_Core_Mode_Para(_CCTL, _Mode) {/* PRQA S 3472 */\
    (_CCTL).B.STOP0 = (_Mode)->B.stop0; \
    (_CCTL).B.HALT0 = (_Mode)->B.halt0; \
    (_CCTL).B.RUN3 = (_Mode)->B.run3; \
    (_CCTL).B.RUN2 = (_Mode)->B.run2; \
    (_CCTL).B.RUN1 = (_Mode)->B.run1; \
    (_CCTL).B.RUN0 = (_Mode)->B.run0; \
    (_CCTL).B.DRUN = (_Mode)->B.drun; \
    (_CCTL).B.SAFE = (_Mode)->B.safe; \
    (_CCTL).B.TEST = (_Mode)->B.test; \
    (_CCTL).B.RESET = (_Mode)->B.reset; \
}

/*******************************************************************************
 * @brief      Swtich core run mode
 * @param[in]  CoreId core_id, RunMode *run_mode
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Swtich_Core_Mode(Saf_CoreId core_id, const CoreMode *core_mode)
{
    MC_ME_CCTL0_tag CCTL0;
    MC_ME_CCTL1_tag CCTL1;
    MC_ME_CCTL2_tag CCTL2;
    MC_ME_CCTL3_tag CCTL3;
    MC_ME_CCTL4_tag CCTL4;
    MC_ME_MCTL_tag MCTL;

    switch (core_id) {
        case SAF_CORE_ID_Z7_0: {
            CCTL1.R = MC_ME.CCTL1.R;
            MCU_LLD_Fill_Core_Mode_Para(CCTL1, core_mode); /* PRQA S 3469 */
            MC_ME.CCTL1.R = CCTL1.R;
#ifdef CHECKER_CORE_ENABLE
            CCTL2.R = MC_ME.CCTL2.R;
            MCU_LLD_Fill_Core_Mode_Para(CCTL2, core_mode); /* PRQA S 3469 */
            MC_ME.CCTL2.R = CCTL2.R;
#endif
            break;
        }
        case SAF_CORE_ID_Z7_1: {
            CCTL3.R = MC_ME.CCTL3.R;
            MCU_LLD_Fill_Core_Mode_Para(CCTL3, core_mode); /* PRQA S 3469 */
            MC_ME.CCTL3.R = CCTL3.R;
            break;
        }
        case SAF_CORE_ID_Z4_2: {
            CCTL0.R = MC_ME.CCTL0.R;
            MCU_LLD_Fill_Core_Mode_Para(CCTL0, core_mode); /* PRQA S 3469 */
            MC_ME.CCTL0.R = CCTL0.R;
            break;
        }
        case SAF_CORE_ID_Z0_4_HSM: {
            CCTL4.R = MC_ME.CCTL4.R;
            MCU_LLD_Fill_Core_Mode_Para(CCTL4, core_mode); /* PRQA S 3469 */
            MC_ME.CCTL4.R = CCTL4.R;
            break;
        }
        default: { /* PRQA S 2024 */
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    MCTL.R = MC_ME.MCTL.R;
    MCTL.B.KEY = (uint16_t)FEATURE_MC_ME_KEY;
    MC_ME.MCTL.R = MCTL.R;
    MCTL.B.KEY = (uint16_t)FEATURE_MC_ME_KEY_INV;
    MC_ME.MCTL.R = MCTL.R;

    while (MC_ME.GS.B.S_MTRANS != 0U) {};

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * @brief      Launch specified core
 * @param[in]  CoreId core_id
 * @param[out] None
 * @retval     status_code
 * @notapi
 *******************************************************************************/
#if 0
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Launch_Core(Saf_CoreId core_id)
{
#ifdef CPU_Z4_2
    MC_ME_CADDR0_tag CADDR0;
    MC_ME_CADDR1_tag CADDR1;
    MC_ME_CADDR3_tag CADDR3;
    CoreMode core_mode;

    core_mode.R = 0U;
    core_mode.B.run3 = 1U;
    core_mode.B.run2 = 1U;
    core_mode.B.run1 = 1U;
    core_mode.B.run0 = 1U;
    core_mode.B.drun = 1U;
    core_mode.B.safe = 1U;
    core_mode.B.test = 1U;

    switch (core_id) {
        case SAF_CORE_ID_Z7_0: {
            CADDR1.R = MC_ME.CADDR1.R;
            CADDR1.B.RMC = 1U;
#if defined(START_FROM_FLASH)
extern uint32_t __CPU_Z7_0_FLASH_BASE_ADDR;
            CADDR1.B.ADDR = (uint32_t)&__CPU_Z7_0_FLASH_BASE_ADDR >> 2U;
#else
            CADDR1.B.ADDR = (uint32_t)&CPU_Z7_0_SRAM_BASE_ADDR >> 2U;
#endif
            MC_ME.CADDR1.R = CADDR1.R;
#ifdef CHECKER_CORE_ENABLE
            MC_ME.CADDR2.B.RMC = 1U;
#endif
            break;
        }
        case SAF_CORE_ID_Z7_1: {
            CADDR3.R = MC_ME.CADDR3.R;
            CADDR3.B.RMC = 1U;
#if defined(START_FROM_FLASH)
extern uint32_t __CPU_Z7_1_FLASH_BASE_ADDR;
            CADDR3.B.ADDR = (uint32_t)&__CPU_Z7_1_FLASH_BASE_ADDR >> 2U;
#else
            CADDR3.B.ADDR = (uint32_t)&CPU_Z7_1_SRAM_BASE_ADDR >> 2U;
#endif
            MC_ME.CADDR3.R = CADDR3.R;
            break;
        }
        case SAF_CORE_ID_Z4_2: {
            CADDR0.R = MC_ME.CADDR0.R;
            CADDR0.B.RMC = 1U;
#if defined(START_FROM_FLASH)
extern uint32_t __CPU_Z4_2_FLASH_BASE_ADDR;
            CADDR0.B.ADDR = (uint32_t)&__CPU_Z4_2_FLASH_BASE_ADDR >> 2U;
#else
            CADDR0.B.ADDR = (uint32_t)&CPU_Z4_2_SRAM_BASE_ADDR >> 2U;
#endif
            MC_ME.CADDR0.R = CADDR0.R;
        }
        default: { /* PRQA S 2003, 2024 */
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return SAF_MCU_LLD_Swtich_Core_Mode(core_id, &core_mode);
#endif
}
#endif
/*******************************************************************************
 * @brief      Enter wait mode
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
void SAF_MCU_LLD_Enter_Wait_Mode(void) /* PRQA S 1503 */
{
#ifdef __ghs__
    PPCASM ("wait"); /* PRQA S 1006 */
#else
    PPCASM volatile ("wait"); /* PRQA S 1006 */
#endif
}
#ifdef ICACHE_ENABLE
/*******************************************************************************
 * @brief    [local_static] Enable or disable the ICACHE
 * @param[in]  uint32_t switch_val
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
static status_t MCU_LLD_Switch_ICache(uint32_t switch_val)
{
    Z7_SPR_L1CSR1_tag Z7_SPR_L1CSR1;
    Z4_SPR_L1CSR1_tag Z4_SPR_L1CSR1;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    switch (core_id) {
        case SAF_CORE_ID_Z7_0:
        case SAF_CORE_ID_Z7_1: {
            Z7_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);
            Z7_SPR_L1CSR1.B.ICECE = switch_val;
            Z7_SPR_L1CSR1.B.ICE = switch_val;
            MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR1.R);
            break;
        };
        case SAF_CORE_ID_Z4_2: {
            Z4_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);
            Z4_SPR_L1CSR1.B.ICECE = switch_val;
            Z4_SPR_L1CSR1.B.ICE = switch_val;
            MTSPR(SPR_L1CSR1, Z4_SPR_L1CSR1.R);
            break;
        };
        default: {
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * @brief      Enable ICACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Enable_ICache(void)
{
    return MCU_LLD_Switch_ICache(ON);
}

/*******************************************************************************
 * @brief      Disable ICACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Disable_ICache(void)
{
    return MCU_LLD_Switch_ICache(OFF);
}

/*******************************************************************************
 * @brief      Invalid ICACHE by set and way
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Invalid_ICache_Set_Way(uint32_t set, uint32_t way)
{
    Z7_SPR_L1FINV1_tag Z7_SPR_L1FINV1;
    Z7_SPR_L1CSR1_tag Z7_SPR_L1CSR1;
    Z4_SPR_L1FINV1_tag Z4_SPR_L1FINV1;
    Z4_SPR_L1CSR1_tag Z4_SPR_L1CSR1;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    switch (core_id) {
        case SAF_CORE_ID_Z7_0:
        case SAF_CORE_ID_Z7_1: {
            Z7_SPR_L1FINV1.R = MFSPR(SPR_L1FINV1);
            Z7_SPR_L1FINV1.B.CWAY = way;
            Z7_SPR_L1FINV1.B.CSET = set;
            MTSPR(SPR_L1FINV1, Z7_SPR_L1FINV1.R);
            Z7_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);
            Z7_SPR_L1CSR1.B.ICINV = 1U;
            MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR1.R);
            do {
                Z7_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);
            } while (Z7_SPR_L1CSR1.B.ICINV == 1U);
            break;
        };
        case SAF_CORE_ID_Z4_2: {
            Z4_SPR_L1FINV1.R = MFSPR(SPR_L1FINV1);
            Z4_SPR_L1FINV1.B.CWAY = way;
            Z4_SPR_L1FINV1.B.CSET = set;
            MTSPR(SPR_L1FINV1, Z4_SPR_L1FINV1.R);
            Z4_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);
            Z4_SPR_L1CSR1.B.ICINV = 1U;
            do {
                Z4_SPR_L1CSR1.R = MFSPR(SPR_L1CSR1);
            } while (Z4_SPR_L1CSR1.B.ICINV == 1U);
            break;
        };
        default: {
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * @brief      Invalid ICACHE by address and length
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Invalid_ICache(uint32_t base, uint32_t len)
{
	status_t ret = STATUS_SUCCESS;
    uint32_t set_idx, way_idx;
    uint32_t max_addr = base + len;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    switch (core_id) {
        case SAF_CORE_ID_Z7_0:
        case SAF_CORE_ID_Z7_1: {
            for (set_idx = base / Z7_ICACHE_LINE;
                set_idx < (ALIGN_UP(max_addr, Z7_ICACHE_LINE) / Z7_ICACHE_LINE); set_idx++) {
                for (way_idx = 0U; way_idx < Z7_ICACHE_WAY_NUM; way_idx++) {
                    ret |= SAF_MCU_LLD_Invalid_ICache_Set_Way(set_idx % Z7_ICACHE_SET_NUM, way_idx);
                }
            }
            break;
        };
        case SAF_CORE_ID_Z4_2: {
            for (set_idx = base / Z4_ICACHE_LINE;
                set_idx < (ALIGN_UP(max_addr, Z4_ICACHE_LINE) / Z4_ICACHE_LINE); set_idx++) {
                for (way_idx = 0U; way_idx < Z4_ICACHE_WAY_NUM; way_idx++) {
                    ret |= SAF_MCU_LLD_Invalid_ICache_Set_Way(set_idx % Z4_ICACHE_SET_NUM, way_idx);
                }
            }
            break;
        };
        default: {
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return ret;
}
#endif
#ifdef DCACHE_ENABLE
/*******************************************************************************
 * @brief    [local_static] Enable or disable the DCACHE
 * @param[in]  uint32_t switch_val
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Switch_DCache(uint32_t switch_val)
{
    Z7_SPR_L1CSR0_tag Z7_SPR_L1CSR0;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    switch (core_id) {
        case SAF_CORE_ID_Z7_0:
        case SAF_CORE_ID_Z7_1: {
            Z7_SPR_L1CSR0.R = MFSPR(SPR_L1CSR0);
            Z7_SPR_L1CSR0.B.DCECE = switch_val;
            Z7_SPR_L1CSR0.B.DCE = switch_val;
            MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR0.R);
            break;
        };
        case SAF_CORE_ID_Z4_2: {
            return STATUS_MCU_UNSUPPORT_DCACHE;
        };
        default: {
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * @brief      Enable DCACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Enable_DCache(void)
{
    return SAF_MCU_LLD_Switch_DCache(ON);
}

/*******************************************************************************
 * @brief      Disable DCACHE
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Disable_DCache(void)
{
    return SAF_MCU_LLD_Switch_DCache(OFF);
}

/*******************************************************************************
 * @brief      Invalid DCACHE by set and way
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Invalid_DCache_Set_Way(uint32_t set, uint32_t way)
{
    Z7_SPR_L1FINV0_tag Z7_SPR_L1FINV0;
    Z7_SPR_L1CSR0_tag Z7_SPR_L1CSR0;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    switch (core_id) {
        case SAF_CORE_ID_Z7_0:
        case SAF_CORE_ID_Z7_1: {
            Z7_SPR_L1FINV0.R = MFSPR(SPR_L1FINV1);
            Z7_SPR_L1FINV0.B.CWAY = way;
            Z7_SPR_L1FINV0.B.CSET = set;
            MTSPR(SPR_L1FINV1, Z7_SPR_L1FINV0.R);
            Z7_SPR_L1CSR0.R = MFSPR(SPR_L1CSR1);
            Z7_SPR_L1CSR0.B.DCINV = 1U;
            MTSPR(SPR_L1CSR1, Z7_SPR_L1CSR0.R);
            do {
                Z7_SPR_L1CSR0.R = MFSPR(SPR_L1CSR1);
            } while (Z7_SPR_L1CSR0.B.DCINV == 1U);
            break;
        };
        case SAF_CORE_ID_Z4_2: {
            return STATUS_MCU_UNSUPPORT_DCACHE;
        };
        default: {
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * @brief      Invalid ICACHE by address and length
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_MCU_LLD_Invalid_DCache(uint32_t base, uint32_t len)
{
	status_t ret = STATUS_SUCCESS;
    uint32_t set_idx, way_idx;
    uint32_t max_addr = base + len;
    Saf_CoreId core_id = SAF_MCU_LLD_Get_Core_Id();

    switch (core_id) {
        case SAF_CORE_ID_Z7_0:
        case SAF_CORE_ID_Z7_1: {
            for (set_idx = base / Z7_DCACHE_LINE;
                set_idx < (ALIGN_UP(max_addr, Z7_DCACHE_LINE) / Z7_DCACHE_LINE); set_idx++) {
                for (way_idx = 0U; way_idx < Z7_DCACHE_WAY_NUM; way_idx++) {
                    ret |= SAF_MCU_LLD_Invalid_DCache_Set_Way(set_idx % Z7_DCACHE_SET_NUM, way_idx);
                }
            }
            break;
        };
        case SAF_CORE_ID_Z4_2: {
            return STATUS_MCU_UNSUPPORT_DCACHE;
        };
        default: {
            return STATUS_MCU_INVALID_CORE_ID;
        }
    }

    return ret;
}
#endif

SAF_MCU_SEC_CONFIG_DATA
static mc_me_peripheral_clock_config_t const peripherals_defalut[SAF_MC_ME_PERIPH_INSTANCE_COUNT] =
{
        {
            .clockName = SAF_MC_ME_PCTL_EBI0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LFAST_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_SIPI0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_SIUL_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_PIT_RTC_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_PIT_RTC_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DMAMUX_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName =  SAF_MC_ME_PCTL_CRC_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_8_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_6_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_4_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_2_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_MCAN4_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_MCAN3_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_MCAN2_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_MCAN1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_TTCAN_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_CAN_RAM_CTRL_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LINFlexD_16_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LINFlexD_14_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LINFlexD_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LINFlexD_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_12_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_6_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_4_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_IIC_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_SENT_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_FLEXRAY_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_PSI5_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_b_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_4_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_GTMINT_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_PSI5_S_0_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_CRC_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_9_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_7_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_5_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_3_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSD_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LINFlexD_15_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_LINFlexD_2_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_5_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            SAF_MC_ME_PCTL_DSPI_3_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_DSPI_2_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_IIC_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_SENT_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_FLEXRAY_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_PSI5_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_10_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_9_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_8_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_7_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_6_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_5_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_3_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_2_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
        {
            .clockName = SAF_MC_ME_PCTL_ADCSAR_1_INDEX,
            .mc_me_RunPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
            .mc_me_LowPowerPeriphConfig = SAF_MC_ME_PERIPH_CONFIG_0,
        },
};/*PRQA S 0686*/

SAF_MCU_SEC_CODE
static void CGMCS_SetIrcTrimmingValue(IRCOSC_Type * base, uint32_t trimmingValue)
{
    base->CTL.B.USER_TRIM = trimmingValue;
}

/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_SetIrc
 * Description   : Configures IRC clock source
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static void MCU_LLD_SetIrc(cgmcs_irc_config_t const* config)/*PRQA S 3219*/
{
    CGMCS_SetIrcTrimmingValue(SAF_IRCOSC_StPtr, (uint32_t)config->trimmingValue);
}

/*!
 * @brief Sets XOSC clock source
 *
 * This function sets XOSC clock source
 *
 * @param[in] base             Register base address for the XOSC instance.
 * @param[in] bypass           Crystal is used when bypass is zero
 * @param[in] bypassOption     Single ended mode is used when bypass option is different from zero, otherwise differential bypass option is used
 * @param[in] startupDelay     Startup delay
 * @param[in] mode             Xosc mode
 * @param[in] monitor          XOSC is not monitor or not
 */
SAF_MCU_SEC_CODE
static inline void CGMCS_SetXosc(XOSC_Type * base, uint32_t bypass, uint32_t startupDelay)
{
    base->CTL.B.OSCBYP = bypass;
    base->CTL.B.EOCV = startupDelay;
}

/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_SetXosc
 * Description   : Configures XOSC clock source
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static void MCU_LLD_SetXosc(cgmcs_xosc_config_t const* config)
{

    CGMCS_SetXosc(SAF_XOSC_StPtr, (config->bypassOption != SAF_XOSC_USE_CRYSTAL) ? 1UL : 0UL,                /* Bypass or not */
                  (uint32_t)config->startupDelay);
}

/*!
 * @brief Sets CGM AC3 selector
 *
 * This function sets CGM AC3 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static void CGM_SetAC3(MC_CGM_Type * base, uint32_t selector)
{
    base->AC3_SC.B.SELCTL = selector;
}

/*!
 * @brief Sets CGM AC4 selector
 *
 * This function sets CGM AC4 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static void CGM_SetAC4(MC_CGM_Type * base, uint32_t selector)
{
    base->AC4_SC.B.SELCTL = selector;
}

/*!
 * @brief Sets PLL Divider Register
 *
 * This function sets PLL Divider Register
 *
 * @param[in] base             Register base address for the PLLDIG instance.
 * @param[in] instance         Instance number
 * @param[in] phi0Divider      first output divider
 * @param[in] phi1Divider      second output divider
 * @param[in] predivider       Predivider
 * @param[in] mulFactorDiv     Multiplier factor divider
 */
SAF_MCU_SEC_CODE
static inline void CGMCS_PLLDivider(PLLDIG_Type * base, uint32_t instance, uint32_t phi0Divider, uint32_t phi1Divider, uint32_t predivider, uint32_t mulFactorDiv)
{
    /* Configure divider */
    if(instance == 0U)
    {
        base->PLL0DV.B.RFDPHI = phi0Divider;
        base->PLL0DV.B.RFDPHI1 = phi1Divider;
        base->PLL0DV.B.PREDIV = predivider;
        base->PLL0DV.B.MFD = mulFactorDiv;
    }
    else 
    {
        base->PLL1DV.B.RFDPHI = phi0Divider;
        base->PLL1DV.B.MFD = mulFactorDiv;
    }
}

/*!
 * @brief Sets PLL Fractional Divider
 *
 * This function sets PLL Fractional Divider
 *
 * @param[in] base              Register base address for the PLLDIG instance.
 * @param[in] enable            Enable fractional loop divider
 * @param[in] fracDivider       Fractional loop divider value
 */
SAF_MCU_SEC_CODE
static void CGMCS_SetPLLFractionalDivider(PLLDIG_Type * base, boolean enable, uint32_t fracDivider)
{
    base->PLL1FD.B.FDEN = ((enable == TRUE) ? 1UL : 0UL);
    base->PLL1FD.B.FRCDIV = fracDivider;
}

/*!
 * @brief Configures PLL Modulation
 *
 * This function sets PLL Modulation
 *
 * @param[in] base              Register base address for the PLLDIG instance.
 * @param[in] enable            Enable fractional loop divider
 * @param[in] fracDivider       Fractional loop divider value
 */
SAF_MCU_SEC_CODE
static inline void CGMCS_ConfigurePllModulation(PLLDIG_Type * base, boolean enable, uint32_t modulationType, uint32_t modulationPeriod, uint32_t incrementStep)
{
/*  TODO Remove macros from header files and define macros in features.h or different PLLs */
    base->PLL1FM.B.MODEN = ((enable == TRUE) ? 1UL : 0UL);
    base->PLL1FM.B.MODSEL = modulationType;
    base->PLL1FM.B.MODPRD = modulationPeriod;
    base->PLL1FM.B.INCSTP = incrementStep;
}
/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_SetPll
 * Description   : Configures ARM PLL clock source
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static void MCU_LLD_SetPll(cgmcs_plldig_config_t const* config, cgm_config_t const* cgmConfig, uint32_t instance)
{
        uint32_t phi0Divider = 0U, phi1Divider = 0U;

        switch (instance)
        {
            case 0U:
                CGM_SetAC3(SAF_MC_CGM_StPtr, (uint32_t)cgmConfig->ac3_sc);
            break;

            case 1U:
                CGM_SetAC4(SAF_MC_CGM_StPtr, (uint32_t)cgmConfig->ac4_sc);
            break;

            default:
                /* Invalid PLL instance */
                break;
        }

     if((config->phi0Divider) != SAF_PLLDIG_PHI_DIV_DISABLE)
     {
    	 phi0Divider = ((uint32_t)config->phi0Divider) + 1U;
     }
     phi1Divider = ((uint32_t)config->phi1Divider) + 1U;

      /* Configure PLL */
      CGMCS_PLLDivider(SAF_PLLDIG_StPtr,
                         instance,
                         phi0Divider,
                         phi1Divider,
                         (uint32_t)config->predivider,
                         (uint32_t)config->mulFactorDiv);

      if (instance == 1U)
      {
        /* Write FRCDIV - fractional divider. */
        CGMCS_SetPLLFractionalDivider(SAF_PLLDIG_StPtr, config->fracDivider, config->fracDividerValue);

        /* Configure modulation */
        CGMCS_ConfigurePllModulation(SAF_PLLDIG_StPtr, config->modulation, (uint32_t)config->modulationType, config->modulationPeriod, config->incrementStep);
      }
}

/*!
 * @brief Sets CGM system clock first divider
 *
 * This function sets CGM system clock first divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static void CGM_SetSC_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (uint8_t)((enable == TRUE) ? 1UL : 0UL);
    base->SC_DC0.R = SAF_MC_CGM_SC_DC0_DIV(divValue) |
    SAF_MC_CGM_SC_DC0_DE(state);
}

/*!
 * @brief Sets CGM system clock 2nd divider
 *
 * This function sets CGM system clock 2nd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static  void CGM_SetSC_DC1(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->SC_DC1.B.DE = ((enable == TRUE) ? 1UL : 0UL);
    base->SC_DC1.B.DIV = divValue;
}
/*!
 * @brief Sets CGM system clock 3rd divider
 *
 * This function sets CGM system clock 3rd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static  void CGM_SetSC_DC2(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->SC_DC2.B.DE = ((enable == TRUE) ? 1UL : 0UL);
    base->SC_DC2.B.DIV = divValue;
}

/*!
 * @brief Sets CGM system clock 4th divider
 *
 * This function sets CGM system clock 4th divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static  void CGM_SetSC_DC3(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->SC_DC3.B.DE = ((enable == TRUE) ? 1UL : 0UL);
    base->SC_DC3.B.DIV = divValue;
}

/*!
 * @brief Sets CGM system clock 5th divider
 *
 * This function sets CGM system clock 5th divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static  void CGM_SetSC_DC4(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->SC_DC4.B.DE = ((enable == TRUE) ? 1UL : 0UL);
    base->SC_DC4.B.DIV = divValue;
}
/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_ConfigureSystemClockDividers
 * Description   : Configures system clocks
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static void MCU_LLD_ConfigureSystemClockDividers(cgm_config_t const* config)
{
    boolean state;
    /*! System clock divider ratios will change with next update.
     *  Not required for Cut 1.*/
    MC_CGM.SC_DIV_RC.R = 0x00000001UL;
    /*! System clock divider ratios updated on writing MC_CGM.DIV_UPD_TRIG.
     * Not required for Cut 1. */
    MC_CGM.DIV_UPD_TYPE.R = 0x80000000UL;

    /* if hsm is enable, need to set hsm clock divider. make sure hsm clock less than 100MHz */
    if (SSCM.UOPS.B.HSE != 0U)
    {
        //(void)HSM_LLD_SetClkDiv(config->hsm_dc); /* PRQA S 2052,3108 */
    }

    /* First system clock divider */
    state = (config->sc_dc0 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetSC_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->sc_dc0);

    /* Second system clock divider */
    state = (config->sc_dc1 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetSC_DC1(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->sc_dc1);

    /* Third system clock divider */
    state = (config->sc_dc2 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetSC_DC2(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->sc_dc2);

    /* 4th system clock divider */
    state = (config->sc_dc3 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetSC_DC3(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->sc_dc3);

    /* 5th system clock divider */
    state = (config->sc_dc4 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetSC_DC4(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->sc_dc4);

 // ! System clock divider ratio updates triggered.  Not required for Cut 1.
    MC_CGM.DIV_UPD_TRIG.R = 0xfeedfaceUL;
 // ! Wait for System Clock Divider Update Status == 0. Not required for Cut 1.
    while (MC_CGM.DIV_UPD_STAT.B.SYS_UPD_STAT == 1U)
    {

    }
}

/*!
 * @brief Sets CGM AC0 selector
 *
 * This function sets CGM AC0 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC0(MC_CGM_Type * base, uint32_t selector)
{
    base->AC0_SC.B.SELCTL = selector;
}

/*!
 * @brief Sets CGM AC0 1st divider
 *
 * This function sets CGM AC0 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC0_DC0(MC_CGM_Type * base, boolean enable,uint32_t divValue)
{

    uint32_t regValue = 0;
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    regValue = (SAF_MC_CGM_AC0_DC0_DIV(divValue) | SAF_MC_CGM_AC0_DC0_DE(state));
    base->AC0_DC0.R = regValue;
}

/*!
 * @brief Sets CGM AC0 2nd divider
 *
 * This function sets CGM AC0 2nd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC0_DC1(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    uint32_t regValue = 0;
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    regValue = (SAF_MC_CGM_AC0_DC1_DIV(divValue) | SAF_MC_CGM_AC0_DC1_DE(state));
    base->AC0_DC1.R = regValue;
}

/*!
 * @brief Sets CGM AC0 3rd divider
 *
 * This function sets CGM AC0 3rd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC0_DC2(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{


    uint32_t regValue = 0;
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    regValue =  (SAF_MC_CGM_AC0_DC2_DIV(divValue) | SAF_MC_CGM_AC0_DC2_DE(state));
    base->AC0_DC2.R = regValue;
}

/*!
 * @brief Sets CGM AC0 4th divider
 *
 * This function sets CGM AC0 4th divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC0_DC3(MC_CGM_Type * base, boolean enable, uint32_t divValue,cgm_clk_div_fmt_t div_fmt)
{
    uint32_t regValue = 0;
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    regValue = (SAF_MC_CGM_AC0_DC3_DIV(divValue) | SAF_MC_CGM_AC0_DC3_DE(state)|SAF_MC_CGM_ACX_DIV_FMT(div_fmt));
    base->AC0_DC3.R = regValue;
}
/*!
 * @brief Sets CGM AC0 5th divider
 *
 * This function sets CGM AC0 5th divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC0_DC4(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    uint32_t regValue = 0;
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    regValue =  (SAF_MC_CGM_AC0_DC4_DIV(divValue) | SAF_MC_CGM_AC0_DC4_DE(state));
    base->AC0_DC4.R = regValue;
}

/*!
 * @brief Sets CGM AC1 selector
 *
 * This function sets CGM AC1 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC1(MC_CGM_Type * base, uint32_t selector)
{
    base->AC1_SC.B.SELCTL = selector;
}

/*!
 * @brief Sets CGM AC1 1st divider
 *
 * This function sets CGM AC1 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC1_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->AC1_DC0.B.DE  = ((enable == TRUE) ? 1UL : 0UL);
    base->AC1_DC0.B.DIV = divValue;
}
/*!
 * @brief Sets CGM AC2 1st divider
 *
 * This function sets CGM AC2 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC2_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->AC2_DC0.B.DE  = ((enable == TRUE) ? 1UL : 0UL);
    base->AC2_DC0.B.DIV = divValue;
}

/*!
 * @brief Sets CGM AC2 2nd divider
 *
 * This function sets CGM AC2 2nd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC2_DC1(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    base->AC2_DC1.B.DE  = ((enable == TRUE) ? 1UL : 0UL);
    base->AC2_DC1.B.DIV = divValue;
}

/*!
 * @brief Sets CGM AC5 1st divider
 *
 * This function sets CGM AC5 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue,cgm_clk_div_fmt_t div_fmt)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_DC0.R = (SAF_MC_CGM_AC5_DC0_DIV(divValue) | SAF_MC_CGM_AC5_DC0_DE(state)|SAF_MC_CGM_ACX_DIV_FMT(div_fmt));
}

/*!
 * @brief Sets CGM AC5 2nd divider
 *
 * This function sets CGM AC5 2nd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_DC1(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_DC1.R = (SAF_MC_CGM_AC5_DC1_DIV(divValue) | SAF_MC_CGM_AC5_DC1_DE(state));
}
/*!
 * @brief Sets CGM AC5 3rd divider
 *
 * This function sets CGM AC5 3rd divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_DC2(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_DC2.R = (SAF_MC_CGM_AC5_DC2_DIV(divValue) | SAF_MC_CGM_AC5_DC2_DE(state));
}

/*!
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC0.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

/*!
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC1(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC1.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

/*!
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC2(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC2.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

/*!
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC10(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC10.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

/*!
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC11(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC11.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC12(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC12.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC13(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC13.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC20(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC20.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC21(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC21.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC22(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC22.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

SAF_MCU_SEC_CODE
static inline void CGM_SetAC5_CDC23(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC5_CDC23.R = (SAF_MC_CGM_AC5_CDCx_DIV(divValue) | SAF_MC_CGM_AC5_CDCx_DE(state));
}

/*!
 * @brief Sets CGM AC6 selector
 *
 * This function sets CGM AC6 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC6(MC_CGM_Type * base, uint32_t selector)
{
    base->AC6_SC.B.SELCTL  = selector;
}

/*!
 * @brief Sets CGM AC6 1st divider
 *
 * This function sets CGM AC6 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC6_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC6_DC0.R = (SAF_MC_CGM_AC6_DC0_DIV(divValue) | SAF_MC_CGM_AC6_DC0_DE(state));
}

/*!
 * @brief Sets CGM AC7 selector
 *
 * This function sets CGM AC7 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC7(MC_CGM_Type * base, uint32_t selector)
{
    base->AC7_SC.B.SELCTL  = selector;
}

/*!
 * @brief Sets CGM AC7 1st divider
 *
 * This function sets CGM AC7 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC7_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC7_DC0.R = (SAF_MC_CGM_AC7_DC0_DIV(divValue) | SAF_MC_CGM_AC7_DC0_DE(state));
}

/*!
 * @brief Sets CGM AC8 selector
 *
 * This function sets CGM AC8 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC8(MC_CGM_Type * base, uint32_t selector)
{
    base->AC8_SC.B.SELCTL  = selector;
}

/*!
 * @brief Sets CGM AC8 1st divider
 *
 * This function sets CGM AC8 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC8_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC8_DC0.R = (SAF_MC_CGM_AC8_DC0_DIV(divValue) | SAF_MC_CGM_AC8_DC0_DE(state));
}

/*!
 * @brief Sets CGM AC9 selector
 *
 * This function sets CGM AC9 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC9(MC_CGM_Type * base, uint32_t selector)
{
    base->AC9_SC.B.SELCTL  = selector;
}

/*!
 * @brief Sets CGM AC9 1st divider
 *
 * This function sets CGM AC9 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC9_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC9_DC0.R = (SAF_MC_CGM_AC9_DC0_DIV(divValue) | SAF_MC_CGM_AC9_DC0_DE(state));
}

/*!
 * @brief Sets CGM AC10 selector
 *
 * This function sets CGM AC10 selector
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] selector Selector value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC10(MC_CGM_Type * base, uint32_t selector)
{
    base->AC10_SC.B.SELCTL  = selector;
}

/*!
 * @brief Sets CGM AC10 1st divider
 *
 * This function sets CGM AC10 1st divider
 *
 * @param[in] base     Register base address for the CGM instance.
 * @param[in] enable   Enable divider.
 * @param[in] divValue Divider value.
 */
SAF_MCU_SEC_CODE
static inline void CGM_SetAC10_DC0(MC_CGM_Type * base, boolean enable, uint32_t divValue)
{
    boolean state;
    state = (enable == TRUE) ? TRUE : FALSE;
    base->AC10_DC0.R = (SAF_MC_CGM_AC10_DC0_DIV(divValue) | SAF_MC_CGM_AC10_DC0_DE(state));
}
/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_ConfigureAuxiliarySelectorsAndDividers
 * Description   : Configures auxiliary clocks
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static void MCU_LLD_ConfigureAuxiliarySelectorsAndDividers(cgm_config_t const* config)
{
    boolean state;
    /* Configure auxiliary clock selector 0 and dividers 0, 1, 2. */
    CGM_SetAC0(SAF_MC_CGM_StPtr, (uint32_t)config->ac0_sc);
    state = (config->ac0_dc0 != SAF_CGM_CLOCK_DISABLE4) ? TRUE : FALSE;
    CGM_SetAC0_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac0_dc0);
    state = (config->ac0_dc1 != SAF_CGM_CLOCK_DISABLE7) ? TRUE : FALSE;
    CGM_SetAC0_DC1(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac0_dc1);
    state = (config->ac0_dc2 != SAF_CGM_CLOCK_DISABLE7) ? TRUE : FALSE;
    CGM_SetAC0_DC2(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac0_dc2);
    state = (config->ac0_dc3 != SAF_CGM_CLOCK_DISABLE9) ? TRUE : FALSE;
    CGM_SetAC0_DC3(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac0_dc3,
				config->ac3_dc0_fmt);
    state = (config->ac0_dc4 != SAF_CGM_CLOCK_DISABLE4) ? TRUE : FALSE;
    CGM_SetAC0_DC4(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac0_dc4);

    /* Configure auxiliary clock selector 1 and dividers 0, 1. */
    CGM_SetAC1(SAF_MC_CGM_StPtr, (uint32_t)config->ac1_sc);
    state = (config->ac1_dc0 != SAF_CGM_CLOCK_DISABLE7) ? TRUE : FALSE;
    CGM_SetAC1_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac1_dc0);

    /* Configure auxiliary clock dividers 0, 1. */
    state = (config->ac2_dc0 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetAC2_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac2_dc0);
    state = (config->ac2_dc1 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetAC2_DC1(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac2_dc1);

    /* Configure auxiliary clock selector 3 and dividers - . */
    CGM_SetAC3(SAF_MC_CGM_StPtr, (uint32_t)config->ac3_sc);

    /* Configure auxiliary clock selector 4 and dividers - . */
    CGM_SetAC4(SAF_MC_CGM_StPtr, (uint32_t)config->ac4_sc);

    /* Configure auxiliary clock  dividers 0, 1, 2. */
    state = (config->ac5_dc0 != SAF_CGM_CLOCK_DISABLE13) ? TRUE : FALSE;
    CGM_SetAC5_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac5_dc0,
			config->ac5_dc0_fmt);
    state = (config->ac5_dc1 != SAF_CGM_CLOCK_DISABLE13) ? TRUE : FALSE;
    CGM_SetAC5_DC1(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_dc1);
    state = (config->ac5_dc2 != SAF_CGM_CLOCK_DISABLE8) ? TRUE : FALSE;
    CGM_SetAC5_DC2(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_dc2);
    state = (config->ac5_cdc0 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC0(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc0);
    state = (config->ac5_cdc1 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC1(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc1);
    state = (config->ac5_cdc2 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC2(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc2);
    state = (config->ac5_cdc10 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC10(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc10);
    state = (config->ac5_cdc11 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC11(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc11);
    state = (config->ac5_cdc12 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC12(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc12);
    state = (config->ac5_cdc13 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC13(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc13);
    state = (config->ac5_cdc20 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC20(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc20);
    state = (config->ac5_cdc21 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC21(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc21);
    state = (config->ac5_cdc22 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC22(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc22);
    state = (config->ac5_cdc23 != SAF_CGM_CLOCK_DISABLE10) ? TRUE : FALSE;
    CGM_SetAC5_CDC23(SAF_MC_CGM_StPtr,
                state,
                (uint32_t) config->ac5_cdc23);

    /* Configure auxiliary clock selector 6 and dividers 0. */
    CGM_SetAC6(SAF_MC_CGM_StPtr, (uint32_t)config->ac6_sc);
    state = (config->ac6_dc0 != SAF_CGM_CLOCK_DISABLE9) ? TRUE : FALSE;
    CGM_SetAC6_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac6_dc0);

    /* Configure auxiliary clock selector 7 and dividers 0. */
    CGM_SetAC7(SAF_MC_CGM_StPtr, (uint32_t)config->ac7_sc);
    state = (config->ac7_dc0 != SAF_CGM_CLOCK_DISABLE9) ? TRUE : FALSE;
    CGM_SetAC7_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac7_dc0);

    /* Configure auxiliary clock selector 8 and dividers 0. */
    CGM_SetAC8(SAF_MC_CGM_StPtr, (uint32_t)config->ac8_sc);
    state = (config->ac8_dc0 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetAC8_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac8_dc0);

    /* Configure auxiliary clock selector 9 and dividers - . */
    CGM_SetAC9(SAF_MC_CGM_StPtr, (uint32_t)config->ac9_sc);
    state = (config->ac9_dc0 != SAF_CGM_CLOCK_DISABLE6) ? TRUE : FALSE;
    CGM_SetAC9_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac9_dc0);

    /* Configure auxiliary clock selector 10 and dividers 0. */
    CGM_SetAC10(SAF_MC_CGM_StPtr, (uint32_t)config->ac10_sc);
    state = (config->ac10_dc0 != SAF_CGM_CLOCK_DISABLE4) ? TRUE : FALSE;
    CGM_SetAC10_DC0(SAF_MC_CGM_StPtr,
            state,
            (uint32_t) config->ac10_dc0);
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetIrcoscFreq(uint32_t *frequency)
{
    /* This clock source is not enabled in current mode. */
    status_t status;

    if ((MC_ME.GS.R & SAF_MC_ME_GS_S_IRC_MASK) != 0U)
    {
        *frequency = g_ircoscClkFreq;
        status = STATUS_SUCCESS;
    }
    else
    {
        *frequency = 0U;
        status = STATUS_MCU_GATED_OFF;
    }
    return status;
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetXoscFreq(uint32_t *frequency)
{
    /* This clock source is not enabled in current mode. */
    status_t status;

    if ((MC_ME.GS.R & SAF_MC_ME_GS_S_XOSC_MASK) != 0U)
    {
        *frequency = g_xoscClkFreq;
        status = STATUS_SUCCESS;
    }
    else
    {
        *frequency = 0U;
        status = STATUS_MCU_GATED_OFF;
    }
    return status;
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetPll0Phi1Freq(uint32_t *frequency)
{
    /* This clock source is not enabled in current mode. */
    status_t status;

    if ((MC_ME.GS.R & SAF_MC_ME_GS_S_PLL0_MASK)!= 0U)
    {
        *frequency = g_pll0Phi1ClkFreq;
        status = STATUS_SUCCESS;
    }
    else
    {
        *frequency = 0U;
        status = STATUS_MCU_GATED_OFF;
    }
    return status;
}
/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_CalculateFrequenciesOfClockSources
 * Description   : Configures clock sources
 *END**************************************************************************/
SAF_MCU_SEC_CODE
void SAF_MCU_LLD_CalculateFrequenciesOfClockSources(boolean runtime)
{
    uint32_t  multiplyFactor = 0U,fractionalDivider = 0U, outputDivider = 0U, outputDivider1 = 0U, frequency = 0U;

    if (FALSE == runtime)
    {

        g_ircoscClkFreq = FEATURE_IRCOSC0_FREQ;
#if !defined(CCFC3008PCSN)
        g_xoscClkFreq = FEATURE_XOSC0_FREQ;
#else
        g_xoscClkFreq = 12000000;
#endif
        /* Calculate the pll input reference */
        /* Check the pll input reference */
        if (0U == MC_CGM.AC3_SC.B.SELCTL)
        {
            /* Gets input frequency - IRCCOSC */
            (void)CLOCK_GetIrcoscFreq(&frequency);
        }
        else if (1U == MC_CGM.AC3_SC.B.SELCTL)
        {
            /* Gets input frequency - XOSC */
            (void)CLOCK_GetXoscFreq(&frequency);
        }
        else
        {
            /* Invalid input reference */
            DEV_ASSERT(FALSE);
        }

        multiplyFactor      = PLLDIG.PLL0DV.B.MFD;
        fractionalDivider   = PLLDIG.PLL0DV.B.PREDIV;
        outputDivider       = PLLDIG.PLL0DV.B.RFDPHI;  
        outputDivider1       = PLLDIG.PLL0DV.B.RFDPHI1;  

        g_pll0VcoClkFreq = (2U *frequency /fractionalDivider)*multiplyFactor; /* PRQA S 3401,3393 */ /* polyspace RTE:ZDV */
        if(outputDivider != 0U)
        {
        	g_pll0Phi0ClkFreq = g_pll0VcoClkFreq / (2U * outputDivider);
        	g_pll0Phi1ClkFreq = g_pll0VcoClkFreq / (2U * outputDivider1); /* polyspace RTE:ZDV */
        }
        else
        {
        	g_pll0Phi0ClkFreq = g_pll0VcoClkFreq;
        }

        /* Check the pll input reference */
        if (1U == MC_CGM.AC4_SC.B.SELCTL)
        {
            /* Gets input frequency - XOSC */
            (void)CLOCK_GetXoscFreq(&frequency);
        }
        else if (0x03U == MC_CGM.AC4_SC.B.SELCTL)
        {
            (void)CLOCK_GetPll0Phi1Freq(&frequency);
        }
        else
        {
            /* Invalid input reference */
            DEV_ASSERT(FALSE);
        }

        multiplyFactor      = PLLDIG.PLL1DV.B.MFD;  
        outputDivider       = PLLDIG.PLL1DV.B.RFDPHI;  


        g_pll1VcoClkFreq = (frequency)*multiplyFactor;
        if(outputDivider != 0U)
        {
        	g_pll1Phi0ClkFreq = g_pll1VcoClkFreq /(2U * outputDivider);
        }
        else
        {
        	g_pll1Phi0ClkFreq = g_pll1VcoClkFreq;
        }
    }
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetPll0Phi0Freq(uint32_t *frequency)
{
    /* This clock source is not enabled in current mode. */
    status_t status;

    if ((MC_ME.GS.R & SAF_MC_ME_GS_S_PLL0_MASK) != 0U)
    {
        *frequency = g_pll0Phi0ClkFreq;
        status = STATUS_SUCCESS;
    }
    else
    {
        *frequency = 0U;
        status = STATUS_MCU_GATED_OFF;
    }
    return status;
}
SAF_MCU_SEC_CODE
static status_t CLOCK_GetPll1Phi0Freq(uint32_t *frequency)
{
    /* This clock source is not enabled in current mode. */
    status_t status;

    if ((MC_ME.GS.R & SAF_MC_ME_GS_S_PLL1_MASK) != 0U)
    {
        *frequency = g_pll1Phi0ClkFreq;
        status = STATUS_SUCCESS;
    }
    else
    {
        *frequency = 0U;
        status = STATUS_MCU_GATED_OFF;
    }
    return status;
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetSystemClockSelectorOutFreq(uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;

    switch (MC_ME.GS.B.S_SYSCLK)
    {
    case (CGM_SYSTEM_CLOCK_SRC_IRCOSC):
        status = CLOCK_GetIrcoscFreq(frequency);
        break;

    case (CGM_SYSTEM_CLOCK_SRC_XOSC):
        status = CLOCK_GetXoscFreq(frequency);
        break;

    case (CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0):
        status = CLOCK_GetPll0Phi0Freq(frequency);
        break;

    case (CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0):
        status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
    default:
        /* Invalid clock source for system clock */
        DEV_ASSERT(FALSE);
        status = STATUS_ERROR;
        break;
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetClockSourceFreq
 * Description   : This function returns the frequency of a given clock source
 *
 * Implements CLOCK_SYS_GetClockSourceFreq_Activity
 * END**************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_CLOCK_GetClockSourceFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;

    *frequency = 0U;

    switch (clockName)
    {
        case SAF_IRCOSC_CLK:
            status = CLOCK_GetIrcoscFreq(frequency);
            break;
        case SAF_XOSC_CLK:
            status = CLOCK_GetXoscFreq(frequency);
            break;
        case SAF_PLL0_PHI0_CLK:
            status = CLOCK_GetPll0Phi0Freq(frequency);
            break;
        case SAF_PLL0_PHI1_CLK:
            status = CLOCK_GetPll0Phi1Freq(frequency);
            break;

        case SAF_PLL1_PHI0_CLK:
            status = CLOCK_GetPll1Phi0Freq(frequency);
            break;

        default:
            /* This clock source is not supported. */
            status = STATUS_UNSUPPORTED;
            break;
    }
    return status;
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetSystemClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t scsClkFreq = 0U, divider = 0U;
    *frequency = 0U;

    status = CLOCK_GetSystemClockSelectorOutFreq(&scsClkFreq);

    if (status == STATUS_SUCCESS)
    {
        /* System clock and core clock are the same. */
        if (clockName == SAF_HSM_CLK)
        {
            *frequency = scsClkFreq;
        }
        else if ((clockName == SAF_FXBAR_CLK) || (clockName == SAF_BD_CLK) || (clockName == SAF_IOP_CLK))
        {
            divider = (uint32_t)((uint32_t)MC_CGM.SC_DC0.B.DIV + 1U);
            scsClkFreq /= divider;
            *frequency = scsClkFreq;
        }
        else if (clockName == SAF_SXBAR_CLK)
        {
            divider = (uint32_t)((uint32_t)MC_CGM.SC_DC1.B.DIV  + 1U);
            scsClkFreq /= divider;
            *frequency = scsClkFreq;
        }
        else if (clockName == SAF_PBRIDGEx_CLK)
        {
            if (MC_CGM.SC_DC2.B.DE == 1U)
            {
                divider = MC_CGM.SC_DC2.B.DIV;
            }
            *frequency = scsClkFreq / (divider + 1u);
        }

        else if ((clockName == SAF_CORE_CLK) || (clockName == SAF_CHKR_CLK))
        {
            divider = (uint32_t)((uint32_t)MC_CGM.SC_DC3.B.DIV + 1U);
            scsClkFreq /= divider;
            *frequency = scsClkFreq;
        }
        else
        {
            DEV_ASSERT(FALSE);
            status = STATUS_ERROR;
        }
    }
    return status;
}
/* PER ADC*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetPERClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t divider = 0U;
    
    if(clockName != SAF_PER_CLK)
    {
        return STATUS_ERROR;
    }

    switch (MC_CGM.AC0_SC.B.SELCTL)
    {
        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
            break;
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
            break;
        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
            break;
        default:
            /* Invalid value of AC0 selector */
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC0_DC0.B.DE == 1U)
    {
        divider =  (uint32_t)((uint32_t)MC_CGM.AC0_DC0.B.DIV + 1U);
        *frequency /= divider;
    }
    return status;
}
/* SAR ADC*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetAdcSarClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;
    if(clockName != SAF_ADCSAR_CLK)
    {
        return STATUS_ERROR;
    }

    selector = MC_CGM.AC0_SC.B.SELCTL;  

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC0_DC2.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC0_DC2.B.DIV  + 1U);

        *frequency /= divider;
    }

    return status;
}

/* SD ADC*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetAdcsdClockFreq(uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;

    selector = MC_CGM.AC0_SC.B.SELCTL;  

    switch (selector)
    {

        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC0_DC1.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC0_DC1.B.DIV + 1U);
        *frequency /= divider;
    }

    return status;
}

SAF_MCU_SEC_CODE
static status_t CLOCK_GetDspiAClockFreq(uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;

    selector = MC_CGM.AC0_SC.B.SELCTL;  

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC0_DC3.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC0_DC3.B.DIV + 1U);
        *frequency /= divider;
    }

    return status;
}

/*DSPI1, LIN, PSI5 - S*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetDspiBClockFreq(uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;

    selector = MC_CGM.AC0_SC.B.SELCTL;  

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC0_DC4.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC0_DC4.B.DIV + 1U);
        *frequency /= divider;
    }

    return status;
}

/*PSI5*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetPSI5ClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t  divider = 0U, divider1 = 0, divider2 = 0, divider3 = 0;

    status = CLOCK_GetPll0Phi0Freq(frequency);

    switch (clockName)
    {
     case SAF_PSI5_f189_CLK:
            divider =  (uint32_t)((uint32_t)MC_CGM.AC5_DC0.B.DIV + 1U);
            *frequency /= divider;
            break;
     case SAF_PSI5_f125_CLK:
         divider =  (uint32_t)((uint32_t)MC_CGM.AC5_DC1.B.DIV + 1U);
         *frequency /= divider;
         break;
     case SAF_PSI5_1us_CLK:
         divider =  (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         *frequency /= divider;
         break;
     case SAF_PSI5_S_TS_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC0.B.DIV + 1U);
         divider = divider1 * divider2;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_DDSR0_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC1.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC10.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_DDSR1_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC1.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC11.B.DIV + 1U);
         divider = (uint32_t)((uint32_t)divider1 * divider2 * divider3);
         *frequency /= divider;
         break;
     case SAF_PSI5_S_DDSR2_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC1.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC12.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_DDSR3_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC1.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC13.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_WD0_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC2.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC10.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_WD1_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC2.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC11.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_WD2_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC2.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC12.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
     case SAF_PSI5_S_WD3_CLK:
         divider1 = (uint32_t)((uint32_t)MC_CGM.AC5_DC2.B.DIV + 1U);
         divider2 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC2.B.DIV + 1U);
         divider3 = (uint32_t)((uint32_t)MC_CGM.AC5_CDC13.B.DIV + 1U);
         divider = divider1 * divider2 * divider3;
         *frequency /= divider;
         break;
         default:
            DEV_ASSERT(FALSE);
            break;
    }
    return status;
}

/*SYSCLK0*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetSYS0ClockFreq(uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;

    selector = MC_CGM.AC6_SC.B.SELCTL;  

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC6_DC0.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC6_DC0.B.DIV + 1U);
        *frequency /= divider;
    }

    return status;
}

/*SYSCLK1*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetSYS1ClockFreq(uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;

    selector = MC_CGM.AC7_SC.B.SELCTL;  

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_IRCOSC:
            status = CLOCK_GetIrcoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;
        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC7_DC0.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC7_DC0.B.DIV + 1U);
        *frequency /= divider;
    }

    return status;
}

/*LIN*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetLfastClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;
    if(clockName != SAF_LFAST_CLK)
    {
        return STATUS_ERROR;
    }

    selector = MC_CGM.AC1_SC.B.SELCTL;  

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;
        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL1_PHI0:
            status = CLOCK_GetPll1Phi0Freq(frequency);
        break;

        case SAF_CGM_LFASTx_SOURCE_SYS_PIN:
            *frequency = 0U;
        break;

        default:
            DEV_ASSERT(FALSE);
            break;
    }

    if (MC_CGM.AC1_DC0.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC1_DC0.B.DIV + 1U);
        *frequency /= divider;
    }
    return status;
}
/* flexRay*/
SAF_MCU_SEC_CODE
status_t SAF_CLOCK_GetFlexrayClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t divider = 0U;
    if(clockName != SAF_FlexRay_CLK)
    {
        return STATUS_ERROR;
    }

    status = CLOCK_GetXoscFreq(frequency);

    if (MC_CGM.AC2_DC0.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC2_DC0.B.DIV + 1U);
        *frequency /= divider;
    }
    return status;
}
/*SENT CLOCK*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetSentClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t divider = 0U;
    if(clockName != SAF_SENT_CLK)
    {
        return STATUS_ERROR;
    }

    status = CLOCK_GetPll0Phi0Freq(frequency);

    if (MC_CGM.AC2_DC1.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC2_DC1.B.DIV + 1U);
        *frequency /= divider;
    }
    return status;
}

/*MCAN TTCAN*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetFlexcanClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;
    if(clockName != SAF_CAN_CLK)
    {
        return STATUS_ERROR;
    }

    selector = MC_CGM.AC8_SC.B.SELCTL;

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;
        default:
            /* There is no support in CGM for FLECAN clock selection */
            *frequency = 0U;
            break;
    }

    if (MC_CGM.AC8_DC0.B.DE == 1U)
    {
        divider =  (uint32_t)((uint32_t)MC_CGM.AC8_DC0.B.DIV + 1U);
        *frequency /= divider;
    }
    return status;
}

/* RTI */
SAF_MCU_SEC_CODE
static status_t CLOCK_GetRtiClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;
    if(clockName != SAF_RTI_CLK)
    {
        return STATUS_ERROR;
    }

        selector = MC_CGM.AC9_SC.B.SELCTL;

        switch (selector)
        {
            case SAF_CGM_SOURCE_SEL_IRCOSC:
                status = CLOCK_GetIrcoscFreq(frequency);
            break;
            case SAF_CGM_SOURCE_SEL_XOSC:
                status = CLOCK_GetXoscFreq(frequency);
            break;
            default:
                DEV_ASSERT(FALSE);
                break;
        }

        if (MC_CGM.AC9_DC0.B.DE == 1U)
        {
            divider = (uint32_t)((uint32_t)MC_CGM.AC9_DC0.B.DIV + 1U);
            *frequency /= divider;
        }

        return status;
}

/*ETHERNET*/
SAF_MCU_SEC_CODE
static status_t CLOCK_GetEnetClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    uint32_t selector = 0U, divider = 0U;
    if(clockName != SAF_RTI_CLK)
    {
        return STATUS_ERROR;
    }

    selector = MC_CGM.AC9_SC.B.SELCTL;

    switch (selector)
    {
        case SAF_CGM_SOURCE_SEL_XOSC:
            status = CLOCK_GetXoscFreq(frequency);
        break;

        case SAF_CGM_SOURCE_SEL_PLL0_PHI0:
            status = CLOCK_GetPll0Phi0Freq(frequency);
        break;
        default:
            /* There is no support in CGM for FLECAN clock selection */
            *frequency = 0U;
            break;
    }

    if (MC_CGM.AC10_DC0.B.DE == 1U)
    {
        divider = (uint32_t)((uint32_t)MC_CGM.AC10_DC0.B.DIV + 1U);
        *frequency /= divider;
    }
    return status;
}

/*FUNCTION**********************************************************************
 * Function Name : CLOCK_SYS_GetModuleClockFreq
 * Description   : Gets module clock frequency
 *END**************************************************************************/
SAF_MCU_SEC_CODE
status_t SAF_CLOCK_GetModuleClockFreq(saf_clock_names_t clockName, uint32_t *frequency)
{
    status_t status = STATUS_SUCCESS;
    if (clockName < SAF_END_OF_CLK_SOURCES)
    {
        status = SAF_CLOCK_GetClockSourceFreq(clockName, frequency);
    }
    else if (clockName < SAF_END_OF_SYSTEM_CLKS)
    {
        status = CLOCK_GetSystemClockFreq(clockName, frequency);
    }
    else if (clockName < SAF_END_OF_AC0_CLK)
    {
        switch (clockName)
        {
        case SAF_PER_CLK:
            status = CLOCK_GetPERClockFreq(clockName, frequency);
            break;
        case SAF_ADCSD_CLK:
            status = CLOCK_GetAdcSarClockFreq(clockName, frequency);
            break;
        case SAF_ADCSAR_CLK:
            status = CLOCK_GetAdcsdClockFreq(frequency);
            break;
        case SAF_DSPI_A_CLK:
            status = CLOCK_GetDspiAClockFreq(frequency);
            break;
        case SAF_DSPI_B_CLK:
        case SAF_LIN_CLK:
        case SAF_PSI5_S_CLK:
            status = CLOCK_GetDspiBClockFreq(frequency);
            break;
        default:
            status = STATUS_ERROR;
            break;
        }
    }
    else if (clockName < SAF_END_OF_AC6_CLK)
    {
        status = CLOCK_GetSYS0ClockFreq(frequency);
    }
    else if (clockName < SAF_END_OF_AC7_CLK)
    {
        status = CLOCK_GetSYS1ClockFreq(frequency);
    }
    else if (clockName < SAF_END_OF_AC1_CLK)
    {
        status = CLOCK_GetLfastClockFreq(clockName, frequency);
    }
    else if (clockName < SAF_END_OF_AC2_CLK)
    {
        if (clockName == SAF_FlexRay_CLK)
        {
            status = CLOCK_GetFlexcanClockFreq(clockName, frequency);
        }
        else
        {
            status = CLOCK_GetSentClockFreq(clockName, frequency);
        }
    }
    else if (clockName < SAF_END_OF_PSI5_CLK)
    {
        status = CLOCK_GetPSI5ClockFreq(clockName, frequency);
    }
    else
    {
        if (clockName == SAF_TXCLK_REF_CLK)
        {
            status = CLOCK_GetEnetClockFreq(clockName, frequency);
        }
        if (clockName == SAF_CAN_CLK)
        {
            status = CLOCK_GetFlexcanClockFreq(clockName, frequency);
        }
        if (clockName == SAF_RTI_CLK)
        {
            status = CLOCK_GetRtiClockFreq(clockName, frequency);
        }
    }
    return status;
}

/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_ConfigureCgmcs
 * Description   : Configures clock sources
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static status_t MCU_LLD_ConfigureCgmcs(clock_manager_user_config_t const* config)
{
    if(config == NULL_PTR)
    {
        return STATUS_ERROR;
    }
    *(volatile uint32_t *)0xfffb0118U = 0x00010640U;
    *(volatile uint32_t *)0xfffb0138U = 0x003F000AU;
    *(volatile uint32_t *)0xfffb013CU = 0x003F000AU;

    MCU_LLD_SetIrc(&config->cgmcsConfig.irc0Config);

    MCU_LLD_SetXosc(&config->cgmcsConfig.xosc0Config);

    MCU_LLD_SetPll(&config->cgmcsConfig.pll0Config, &config->cgmConfig, 0U);

    MCU_LLD_SetPll(&config->cgmcsConfig.pll1Config, &config->cgmConfig, 1U);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 * Function Name : MCU_LLD_ConfigureCgm
 * Description   : Configures clock generation module
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static status_t MCU_LLD_ConfigureCgm(clock_manager_user_config_t const* config)
{
    if(config == NULL_PTR)
    {
        return STATUS_ERROR;
    }

    /* Configure system dividers */
    MCU_LLD_ConfigureSystemClockDividers(&config->cgmConfig);

    /* Configure auxiliary selector and dividers */
    MCU_LLD_ConfigureAuxiliarySelectorsAndDividers(&config->cgmConfig);

    return STATUS_SUCCESS;
}
/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME
 *
 * @param[in] sysClk Destination mode.
 * @param[in] irc0   First IRCOSC clock source.
 * @param[in] irc1   Second IRCOSC clock source.
 * @param[in] xosc0  First XOSC clock source.
 * @param[in] xosc1  Second XOSC clock source.
 * @param[in] pll0   First PLL clock source.
 * @param[in] pll1   Second PLL clock source.
 * @param[in] modeRegister  register to be read/written
 */
SAF_MCU_SEC_CODE
static void MC_ME_SetModeEnable(MC_ME_Type * base, const mc_me_me_config_t* me)
{

    volatile uint32_t *modeRegister = &base->ME.R;
    uint32_t regValue = *modeRegister;
    boolean state;
    state = (me->test == TRUE) ? TRUE : FALSE;
    regValue |= SAF_MC_ME_ME_TEST(state);
    state = (me->run1 == TRUE) ? TRUE : FALSE;
    regValue |= SAF_MC_ME_ME_RUN1(state);
    state = (me->run2 == TRUE) ? TRUE : FALSE;
    regValue |= SAF_MC_ME_ME_RUN2(state);
    state = (me->run3 == TRUE) ? TRUE : FALSE;
    regValue |= SAF_MC_ME_ME_RUN3(state);
    state = (me->halt0 == TRUE) ? TRUE : FALSE;
    regValue |= SAF_MC_ME_ME_HALT0(state);
    state = (me->stop0 == TRUE) ? TRUE : FALSE;
    regValue |= SAF_MC_ME_ME_STOP0(state);

    *modeRegister = regValue;
}

/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME
 *
 * @param[in] sysClk Destination mode.
 * @param[in] irc0   First IRCOSC clock source.
 * @param[in] irc1   Second IRCOSC clock source.
 * @param[in] xosc0  First XOSC clock source.
 * @param[in] xosc1  Second XOSC clock source.
 * @param[in] pll0   First PLL clock source.
 * @param[in] pll1   Second PLL clock source.
 * @param[in] modeRegister  register to be read/written
 */
SAF_MCU_SEC_CODE
static void MC_ME_SetClockSources(uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1, volatile uint32_t *modeRegister)
{
    uint32_t regValue = *modeRegister;/* polyspace RTE:NIV */
    regValue &= ~(SAF_MC_ME_GS_S_SYSCLK_MASK);/* PRQA S 4397 */
    regValue |= (sysClk&SAF_MC_ME_GS_S_SYSCLK_MASK);

    if(irc0 == TRUE)
    {
    	regValue |= SAF_MC_ME_GS_S_IRC(1);
    }
    else
    {
    	regValue &= ~SAF_MC_ME_GS_S_IRC(1);
    }
    if(xosc0 == TRUE)
    {
    	regValue |= SAF_MC_ME_GS_S_XOSC(1);
    }
    else
    {
    	regValue &= ~SAF_MC_ME_GS_S_XOSC(1);
    }
    if(pll0 == TRUE)
    {
    	regValue |= SAF_MC_ME_GS_S_PLL0(1);
    }
    else
    {
    	 regValue &= ~SAF_MC_ME_GS_S_PLL0(1);
    }
    if(pll1 == TRUE)
    {
    	regValue |= SAF_MC_ME_GS_S_PLL1(1);
    }
    else
    {
    	regValue &= ~SAF_MC_ME_GS_S_PLL1(1);
    }
    *modeRegister = regValue;
}

/*!
 * @brief Enables clock sources from MC_ME
 *
 * This function enables/disables all clock sources from MC_ME in drun mode
 *
 * @param[in] base   Register base address for the MC_ME instance.
 * @param[in] sysClk Destination mode.
 * @param[in] irc0   First IRCOSC clock source.
 * @param[in] irc1   Second IRCOSC clock source.
 * @param[in] xosc0  First XOSC clock source.
 * @param[in] xosc1  Second XOSC clock source.
 * @param[in] pll0   First PLL clock source.
 * @param[in] pll1   Second PLL clock source.
 */
SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInSafeMode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &base->SAFE_MC.R);
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInTestMode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
    MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->TEST_MC.R));
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInStopMode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
    MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->STOP0_MC.R));
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInHaltMode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->HALT0_MC.R));
}

#ifndef SAFETY_ENABLE
SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInResetMode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)/*PRQA S 3219*/
{
    MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->RESET_MC.R));
}
#endif

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInDrunMode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->DRUN_MC.R));
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInRun0Mode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->RUN_MC[0U].R));
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInRun1Mode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->RUN_MC[1U].R));
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInRun2Mode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->RUN_MC[2U].R));
}

SAF_MCU_SEC_CODE
static inline void MC_ME_SetClockSourcesInRun3Mode(MC_ME_Type * base, uint32_t sysClk, boolean irc0, boolean xosc0, boolean pll0, boolean pll1)
{
     MC_ME_SetClockSources(sysClk, irc0, xosc0, pll0, pll1, &(base->RUN_MC[3U].R));
}

/*!
 * @brief Set run periheral configuration
 *
 * This function sets run periheral configuration
 *
 * @param[in] base Register base address for the MC_ME instance.
 */
SAF_MCU_SEC_CODE
static inline void MC_ME_SetRunPeripheralConfig(MC_ME_Type * base, uint32_t configIndex, boolean safe, boolean test, boolean drun, boolean run0, boolean run1, boolean run2, boolean run3)
{
    uint32_t value = 0U;
    boolean state;
    state = (drun == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_DRUN(state);/* PRQA S 2986 */
    state = (run0 == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_RUN0(state);
    state = (run1 == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_RUN1(state);
    state = (run2 == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_RUN2(state);
    state = (run3 == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_RUN3(state);
    state = (safe == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_SAFE(state);
    state = (test == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_TEST(state);

    base->RUN_PC[configIndex].R = value;
}

/*!
 * @brief Set low periheral configuration
 *
 * This function sets low periheral configuration
 *
 * @param[in] base Register base address for the MC_ME instance.
 */
SAF_MCU_SEC_CODE
static inline void MC_ME_SetLowPeripheralConfig(MC_ME_Type * base, uint32_t configIndex, boolean stop0, boolean halt0)
{
    uint32_t value = 0U;
    boolean state;
    state = (stop0 == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_STOP0(state);/* PRQA S 2986 */
    state = (halt0 == TRUE) ? TRUE : FALSE;
    value |= SAF_MC_ME_ME_HALT0(state);

    base->LP_PC[configIndex].R = value;
}

/*!
* @brief Sets Peripheral clock control register
*
* @param[in] base             mc_me base pointer
* @param[in] clockName        clock name
* @param[in] runConfigIndex   running configuration index
* @param[in] lowConfigIndex   low configuration index
*/
SAF_MCU_SEC_CODE
static inline void MC_ME_SetPeripheralClockControl(MC_ME_Type* base, peripheral_names_t peripheralName, uint8_t runConfigIndex, uint8_t lowConfigIndex)
{
   /* Configure the low and run configurations */
   if (peripheralName != SAF_MC_ME_INVALID_INDEX)
   {
       base->PCTL[peripheralName].R = (SAF_MC_ME_PCTLn_RUN_CFG(runConfigIndex) | SAF_MC_ME_PCTLn_LP_CFG(lowConfigIndex)); /* polyspace RTE:OBAI */
   }
}

/*!
 * @brief MC_ME mode change.
 *
 * This function is changing mode in MC_ME module
 *
 * @param[in] base Register base address for the MC_ME instance.
 * @param[in] mode Destination mode.
 */
SAF_MCU_SEC_CODE
static inline void MC_ME_ChangeMode(MC_ME_Type * base, mode_config_t targetmode)
{
    uint32_t currentMode = 0;
    if (targetmode != saf_me_mc_mode_notchange)
    {
         currentMode = (uint32_t)targetmode;
    }
    else{

         currentMode = base->MCTL.B.TARGET_MODE;
    }

    /* Change takes effect after mode transition. */
    base->MCTL.R = SAF_MC_ME_MCTL_TARGET_MODE(currentMode) | SAF_MC_ME_MCTL_KEY(FEATURE_MC_ME_KEY);
    base->MCTL.R = SAF_MC_ME_MCTL_TARGET_MODE(currentMode) | SAF_MC_ME_MCTL_KEY(FEATURE_MC_ME_KEY_INV);
}

/*!
 * @brief MC_ME transition mode status.
 *
 * This function is returning the transition mode status (transition completed or not)
 *
 * @param[in] base Register base address for the MC_ME instance.
 * @return transition status
 */
SAF_MCU_SEC_CODE
static inline boolean MC_ME_GetTransitionStatus(const MC_ME_Type * base)
{
    boolean state = (base->GS.B.S_MTRANS == 0U) ? TRUE : FALSE;
    return state;
}

/*FUNCTION**********************************************************************
 * Function Name : CLOCK_SYS_ConfigureMcMeClocking
 * Description   : Configures peripheral clock gating, system clock source and
 * clock sources in all power modes.
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static status_t MCU_LLD_ConfigureMcMe(clock_manager_user_config_t const* config)
{
    status_t retValue = STATUS_TIMEOUT;
    uint32_t i;

    MC_ME_SetModeEnable(SAF_MC_ME_StPtr, &config->mcmeConfig.me);
    /* Set clock sources in all modes */
    MC_ME_SetClockSourcesInDrunMode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.drun.sysclk,
            config->mcmeConfig.drun.clocksEnabled.irc0,
            config->mcmeConfig.drun.clocksEnabled.xosc0,
            config->mcmeConfig.drun.clocksEnabled.pll0,
            config->mcmeConfig.drun.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInRun0Mode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.run0.sysclk,
            config->mcmeConfig.run0.clocksEnabled.irc0,
            config->mcmeConfig.run0.clocksEnabled.xosc0,
            config->mcmeConfig.run0.clocksEnabled.pll0,
            config->mcmeConfig.run0.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInRun1Mode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.run1.sysclk,
            config->mcmeConfig.run1.clocksEnabled.irc0,
            config->mcmeConfig.run1.clocksEnabled.xosc0,
            config->mcmeConfig.run1.clocksEnabled.pll0,
            config->mcmeConfig.run1.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInRun2Mode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.run2.sysclk,
            config->mcmeConfig.run2.clocksEnabled.irc0,
            config->mcmeConfig.run2.clocksEnabled.xosc0,
            config->mcmeConfig.run2.clocksEnabled.pll0,
            config->mcmeConfig.run2.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInRun3Mode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.run3.sysclk,
            config->mcmeConfig.run3.clocksEnabled.irc0,
            config->mcmeConfig.run3.clocksEnabled.xosc0,
            config->mcmeConfig.run3.clocksEnabled.pll0,
            config->mcmeConfig.run3.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInSafeMode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.safe.sysclk,
            config->mcmeConfig.safe.clocksEnabled.irc0,
            config->mcmeConfig.safe.clocksEnabled.xosc0,
            config->mcmeConfig.safe.clocksEnabled.pll0,
            config->mcmeConfig.safe.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInTestMode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.test.sysclk,
            config->mcmeConfig.test.clocksEnabled.irc0,
            config->mcmeConfig.test.clocksEnabled.xosc0,
            config->mcmeConfig.test.clocksEnabled.pll0,
            config->mcmeConfig.test.clocksEnabled.pll1);

    MC_ME_SetClockSourcesInStopMode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.stop0.sysclk,
            config->mcmeConfig.stop0.clocksEnabled.irc0,
            config->mcmeConfig.stop0.clocksEnabled.xosc0,
            config->mcmeConfig.stop0.clocksEnabled.pll0,
            config->mcmeConfig.stop0.clocksEnabled.pll1);
    MC_ME_SetClockSourcesInHaltMode(SAF_MC_ME_StPtr, (uint32_t)config->mcmeConfig.halt0.sysclk,
            config->mcmeConfig.halt0.clocksEnabled.irc0,
            config->mcmeConfig.halt0.clocksEnabled.xosc0,
            config->mcmeConfig.halt0.clocksEnabled.pll0,
            config->mcmeConfig.halt0.clocksEnabled.pll1);

    /* Clock sources are enabled after mode transition */
    MC_ME_ChangeMode(SAF_MC_ME_StPtr, saf_me_mc_mode_notchange);

    for (i = 0U; i < MC_ME_COMPLETE_TRANSITION_TIMEOUT; i++)
    {
        /* Check whether transition completed */
        if (MC_ME_GetTransitionStatus(SAF_MC_ME_StPtr) == TRUE)
        {
            retValue = STATUS_SUCCESS;
            break;
        }
    }

    if (STATUS_SUCCESS == retValue)
    {
        /* Set run peripheral configurations */
        for (i = 0U; i < ((uint32_t)SAF_MC_ME_PERIPH_CONFIG_COUNT); i++)
        {
            MC_ME_SetRunPeripheralConfig(SAF_MC_ME_StPtr, i,
                    
                    config->mcmeConfig.periphRunConfig[i].safe,
                    config->mcmeConfig.periphRunConfig[i].test,
                    config->mcmeConfig.periphRunConfig[i].drun,
                    config->mcmeConfig.periphRunConfig[i].run0,
                    config->mcmeConfig.periphRunConfig[i].run1,
                    config->mcmeConfig.periphRunConfig[i].run2,
                    config->mcmeConfig.periphRunConfig[i].run3);
        }

        /* Set low peripheral configurations */
        for (i = 0U; i < ((uint32_t)SAF_MC_ME_PERIPH_CONFIG_COUNT); i++)
        {
            MC_ME_SetLowPeripheralConfig(SAF_MC_ME_StPtr, i,
                    config->mcmeConfig.periphLowPowerConfig[i].stop0,
                    config->mcmeConfig.periphLowPowerConfig[i].halt0);
        }

        for (i = 0U; i < config->mcmeConfig.count; i++)
        {
            /* Set peripheral clock control */
            MC_ME_SetPeripheralClockControl(SAF_MC_ME_StPtr,
                    config->mcmeConfig.peripherals[i].clockName, /* polyspace RTE:OBAI */
                    (uint8_t) config->mcmeConfig.peripherals[i].mc_me_RunPeriphConfig,
                    (uint8_t) config->mcmeConfig.peripherals[i].mc_me_LowPowerPeriphConfig);
        }

        retValue = STATUS_TIMEOUT;

        /* Peripherals are clocked after mode transition */
        MC_ME_ChangeMode(SAF_MC_ME_StPtr, saf_me_mc_mode_notchange);

        for (i = 0U; i < MC_ME_COMPLETE_TRANSITION_TIMEOUT; i++)
        {
            /* Check whether transition completed */
            if (MC_ME_GetTransitionStatus(SAF_MC_ME_StPtr) == TRUE)
            {
                retValue = STATUS_SUCCESS;
                break;
            }
        }
    }

    return retValue;
}

/*!
 * @brief Return CMU status
 */
SAF_MCU_SEC_CODE
uint32_t SAF_CMU_LLD_GetStatus(CMU_Type * base)
{
	CMU_Type *pBase = base;
    uint32_t regValue = pBase->ISR.R; /* polyspace RTE:NIV */
    return regValue;
}

/*!
 * @brief Clean ISR register
 */
SAF_MCU_SEC_CODE
void SAF_CMU_LLD_CleanStatusRegister(CMU_Type * base)
{
	CMU_Type *pBase = base;
    uint32_t regValue = pBase->ISR.R;/* polyspace RTE:NIV */
    regValue = (uint32_t)(CMU_ISR_FLLI_MASK | CMU_ISR_FHHI_MASK | CMU_ISR_OLRI_MASK);
    pBase->ISR.R = regValue;
}

/*!
* @brief Return CMU status
*/
SAF_MCU_SEC_CODE
void SAF_CMU_LLD_Reset(CMU_Type * base)
{
	CMU_Type *pBase = base;
    /*  Disable the monitoring unit */
	SAF_CMU_LLD_EnableCMU(pBase, FALSE);
    /*  Clear status register */
    SAF_CMU_LLD_CleanStatusRegister(pBase);

    SAF_CMU_LLD_SetLowFreq(pBase, 0U);
    SAF_CMU_LLD_SetHighFreq(pBase, 0xFFFU);
}

SAF_MCU_SEC_CODE
static void MCU_LLD_SetCMU(clock_manager_user_config_t const* config)
{
    uint8_t i = 0U;
    CMU_Type *base = FIRST_CMU;

    static CMU_Type * const cmu[CMU_INSTANCE_COUNT] = CMU_BASE_PTRS;


    switch (config->cmuConfig.cmu_rcdiv0)
    {
    case SAF_CMU_LO_FREQ_1:
    case SAF_CMU_LO_FREQ_2:
    case SAF_CMU_LO_FREQ_4:
    case SAF_CMU_LO_FREQ_8:
        /* Check that monitoring unit is enabled. Set divider for reference clock in this case. */
        if (config->cmuConfig.cmu[FEATURE_HAS_RCDIV].enable == TRUE)
        {
        	SAF_CMU_LLD_SetDivider(cmu[FEATURE_HAS_RCDIV], (uint32_t) config->cmuConfig.cmu_rcdiv0);
        }
        break;
    default:
        /* Invalid CMU_PLL XOSC divider */
        break;
    }

    /* Set each monitoring unit */
    for (i = 0U; i < CMU_INSTANCE_COUNT; i++)
    {
        if (config->cmuConfig.cmu[i].enable == TRUE)
        {
            base = cmu[i];

            
            
            /* Enable the monitoring unit */
            SAF_CMU_LLD_EnableCMU(base, config->cmuConfig.cmu[i].enable);

            /* Set frequency range for the monitored clock */
            SAF_CMU_LLD_SetLowFreq(base, config->cmuConfig.cmu[i].lo_freq);
            SAF_CMU_LLD_SetHighFreq(base, config->cmuConfig.cmu[i].hi_freq);
            
        }
    }
}

/*!
 * @brief Resets configuration of clock sources in MC_ME.
 *
 * Resets configuration of clock sources in MC_ME. Enables IRC type clock sources and sets an IRC type clock source as system clock in all modes.
 *
 * @param[in] base   Register base address for the MC_ME instance.
 * @param[in] sysClk Destination mode. */
SAF_MCU_SEC_CODE
static void MC_ME_ResetClockSourcesConfiguration(MC_ME_Type * base)
{
   /* Enables IRC sources. Disables XOSC and PLL sources. Sets IRC source as system clock */
    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->DRUN_MC.R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->RUN_MC[0U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->RUN_MC[1U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->RUN_MC[2U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->RUN_MC[3U].R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->SAFE_MC.R));

    MC_ME_SetClockSources(0U, TRUE, FALSE, FALSE, FALSE, &(base->TEST_MC.R));
}
/*!
 * @brief Resets configuration of peripherals in MC_ME.
 *
 * Resets configuration of peripherals in MC_ME. Disables module clocks in all modes.
 *
 * @param[in] base   Register base address for the MC_ME instance. */
SAF_MCU_SEC_CODE
static inline void MC_ME_ResetPeripheralsConfiguration(MC_ME_Type * base)
{
    uint32_t i;

    /* Reset run peripheral configurations */
    for (i = 0U; i < ((uint32_t)SAF_MC_ME_PERIPH_CONFIG_COUNT); i++)
    {
        MC_ME_SetRunPeripheralConfig(base, i, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
    }

    /* Reset low peripheral configurations */
    for (i = 0U; i < ((uint32_t)SAF_MC_ME_PERIPH_CONFIG_COUNT); i++)
    {
        MC_ME_SetLowPeripheralConfig(base, i, FALSE, FALSE);
    }

    for (i = 0U; i < SAF_MC_ME_PERIPH_INSTANCE_COUNT; i++)
    {
        /* Set peripheral clock control */
    	MC_ME_SetPeripheralClockControl(SAF_MC_ME_StPtr,
                peripherals_defalut[i].clockName,
                0,
                0);
    }
}

/*FUNCTION**********************************************************************
 * Function Name : CLOCK_SYS_Reset
 * Description   : Clears peripheral clock gating and all clock sources. Only an IRC
 * type clock source is enabled and set as system clock source.
 *END**************************************************************************/
SAF_MCU_SEC_CODE
static status_t MCU_LLD_Reset(void)
{
    status_t retValue = STATUS_TIMEOUT;
    uint32_t i;
    static CMU_Type * const cmu[CMU_INSTANCE_COUNT] = CMU_BASE_PTRS;

    /* Reset CMU module */
    SAF_CMU_LLD_SetDivider(FIRST_CMU, (uint32_t)CMU_RESET_DIVIDER_VALUE);

    for (i = 0U; i < CMU_INSTANCE_COUNT; i++)
    {
        /*  Disable the monitoring unit */
        SAF_CMU_LLD_EnableCMU(cmu[i], FALSE);
        /*  Clear status register */
           SAF_CMU_LLD_CleanStatusRegister(cmu[i]);

    }

    /* Resets configuration of clock sources in MC_ME. */
    MC_ME_ResetClockSourcesConfiguration(SAF_MC_ME_StPtr);

    /* Resets configuration of peripherals in MC_ME. */
    MC_ME_ResetPeripheralsConfiguration(SAF_MC_ME_StPtr);

    /* Clock sources are enabled after mode transition */
    MC_ME_ChangeMode(SAF_MC_ME_StPtr, saf_me_mc_mode_notchange);

    for (i = 0U; i < MC_ME_COMPLETE_TRANSITION_TIMEOUT; i++)
    {
        /* Check whether transition completed */
        if (MC_ME_GetTransitionStatus(SAF_MC_ME_StPtr) == TRUE)
        {
            retValue = STATUS_SUCCESS;
            break;
        }
    }

    return retValue;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : MCU_LLD_Init
 * Description   : This function sets the system to target configuration, it
 * only sets the clock modules registers for clock mode change, but not send
 * notifications to drivers.
 *
 * Implements CLOCK_DRV_Init_Activity
 * END**************************************************************************/
SAF_MCU_SEC_CODE
status_t MCU_LLD_Init(clock_manager_user_config_t const * config)
{
    status_t result = STATUS_SUCCESS;
    uint32_t fxbarClk;
    DEV_ASSERT(config != NULL);/*PRQA S 4404*/

    /* Clears peripheral clock gating and all clock sources in all power modes.
     * Only an IRC type clock source is enabled and set as system clock source. */
    result = MCU_LLD_Reset();

    if (STATUS_SUCCESS == result)
    {
        /* Configure clock sources. */
        result = MCU_LLD_ConfigureCgmcs(config);

        if (STATUS_SUCCESS == result)
        {
            /* Configure peripheral clock gating, system clock source
             * and clock sources in all power modes. */
            result = MCU_LLD_ConfigureMcMe(config);

            if (STATUS_SUCCESS == result)
            {
                /* Configure peripheral clocks. */
                (void)MCU_LLD_ConfigureCgm(config);

                /* Clock sources are enabled after mode transition */
                MC_ME_ChangeMode(SAF_MC_ME_StPtr, saf_me_mc_run0_mode);
                while (MC_ME.GS.B.S_MTRANS == 1U) {
                    ;
                } //  Wait for mode transition to complete
                while (MC_ME.GS.B.S_CURRENT_MODE != (uint32_t)saf_me_mc_run0_mode) //  Verify RUN0 is the current mode
                {
                    ;
                }
                MCU_LLD_SetCMU(config);
            }
        }
    }

    /* Calculate frequencies of clock sources and cache these values. This function is not called at runtime */
    SAF_MCU_LLD_CalculateFrequenciesOfClockSources(FALSE);

    /* Config RWSC */
    result = SAF_CLOCK_GetModuleClockFreq(SAF_FXBAR_CLK, &fxbarClk);
    if (fxbarClk == 100000000U)
    {
        PFLASH.PFCR1.B.RWSC = 3U;
    }
    else
    {
        PFLASH.PFCR1.B.RWSC = 7U;
    }

    /* Get Flash Swap Status */
    //saf_g_swapStatus = FLASH_Get_Swap_Status();

    return result;
}

