#include "CCFC3012PT.h"
#include "Mcu.h"
#include "Mcu_LLDriver.h"
#include "ResetCause.h"


#define EXT_WDG_CNT_CHECK (0u)
#define SOFTWARE_LOOP_RESET_CHECK (0u)
#define SAME_CAUSE_RESET_LOOP_LIM (3u)


#define RC_RGM_DES_RWBITS_MASK32             ((uint32)0x0180C73BU)
#define RC_RGM_FES_RWBITS_MASK32             ((uint32)0x01808468U)


#define EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_C
#include "Evpt_MemMap.h"
static volatile MC_RGM_DES_tag snapshot_des;
static volatile MC_RGM_FES_tag snapshot_fes;
#define EVPT_BSW_STOP_SEC_VAR_CLEAR_ASIL_C
#include "Evpt_MemMap.h"


volatile uint8 reset_cause_history[RESET_HISTORY_DEPTH] __attribute__((section (".reset_keep")));
#define EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_C
#include "Evpt_MemMap.h"
static volatile uint8 current_reset_cause = RESET_CAUSE_TYP_UNINIT;
#define EVPT_BSW_START_SEC_VAR_CLEAR_ASIL_C
#include "Evpt_MemMap.h"


#define EVPT_BSW_START_SEC_CODE_ASIL_C
#include "Evpt_MemMap.h"


static void ResetCause_RegisterSnapshot(void) {
    snapshot_des.R = MC_RGM.DES.R;
    snapshot_fes.R = MC_RGM.FES.R;
}


uint32 ResetCause_GetDestructiveEventStatus(void) {
    return snapshot_des.R;
}


uint32 ResetCause_GetFunctionalEventStatus(void) {
    return snapshot_fes.R;
}


/**
 * 从 MCAL 修改而来
 * 1. DES改用boot传的值
 * 2. MASK掉ESR-STDONE，否则POR会误识别成MULTIPLE
 * 3. 修改返回枚举的定义，否则MASK掉的ESR0-STDONE会导致FES错位
 */
static FUNC(ResetCause_ResetType, MCU_CODE) ResetCause_LLD_GetResetReason(void)
{
    VAR(ResetCause_ResetType, MCU_VAR) ResetReason = RC_MCU_NO_RESET_REASON;
    VAR(uint32, MCU_VAR) RegValue = 0U;
    VAR(uint32, MCU_VAR) Index = 0U;
    VAR(uint32, MCU_VAR) ResetOffset = 0U;
    VAR(uint32, MCU_VAR) Count = 0U;
    volatile VAR(uint32, MCU_VAR) Mcu_ReasonReg[2U] = {0U};

    RegValue = (snapshot_des.R & RC_RGM_DES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[0U] = RegValue;
    }
    RegValue = (snapshot_fes.R & RC_RGM_FES_RWBITS_MASK32);
    if(RegValue != 0U)
    {
        Mcu_ReasonReg[1U] = RegValue;
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if(((uint32)(0x01UL << Index) & RC_RGM_DES_RWBITS_MASK32) != 0U)
        {
            if((Mcu_ReasonReg[0U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(Count == 0U)
                {
                    ResetReason = (ResetCause_ResetType) ResetOffset;
                    Count++;
                }
                else
                {
                    ResetReason = (ResetCause_ResetType) RC_MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            ResetOffset++;
        }
    }

    for(Index = 0x00U; Index < 0x20U; Index++)
    {
        if((((uint32)0x01UL << Index) & RC_RGM_FES_RWBITS_MASK32) != 0U)
        {
            if((Mcu_ReasonReg[1U] & (uint32)(0x01UL << Index)) != 0U)
            {
                if(Count == 0U)
                {
                    ResetReason = (ResetCause_ResetType) ResetOffset;
                    Count++;
                }
                else
                {
                    ResetReason = (ResetCause_ResetType) RC_MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            ResetOffset++;
        }
    }

    MC_RGM.DES.R = (MC_RGM.DES.R & RC_RGM_DES_RWBITS_MASK32);
    MC_RGM.FES.R = (MC_RGM.FES.R & RC_RGM_FES_RWBITS_MASK32);

    return (ResetCause_ResetType)ResetReason;
}


// Callback for NvMReadRamBlockFromNvCallback, copy from NvM on demand
Std_ReturnType ResetCause_LoadFromNvm(uint8 *romData)
{
    // Copy only after POR happened
    if (ResetCause_IsPorHappened() == TRUE)
    {
        for (uint8 i = 0; i < RESET_HISTORY_DEPTH; i++) {
            reset_cause_history[i] = romData[i];
        }
	} else {
        /* Do nothing */
    }

    return E_OK;
}


boolean ResetCause_IsPorHappened(void) {
#if(1)  /* Check if soft reset or FCCU reset */
    return (
        (current_reset_cause == RC_MCU_SOFT_FUNC_RESET) ||
        (current_reset_cause == RC_MCU_FCCU_HARD_RESET) ||
        (current_reset_cause == RC_MCU_FCCU_SOFT_RESET)
    ) ? 0 : 1;
#else
    return (
        (current_reset_cause == RESET_CAUSE_TYP_NORMAL_POR) || 
        (current_reset_cause == RESET_CAUSE_TYP_WDG_CAUSED_POR)
    );
#endif
}


uint8 ResetCause_GetCause(void) {
    return current_reset_cause;
}


static void ResetCause_InitPostProcess(void) {
    // do nothing
}


/**
 * Call before safetylib prestartup test, or flag will be cleared.
 */
void ResetCause_PreInit(void) {
    ResetCause_RegisterSnapshot();

    current_reset_cause = (uint8) ResetCause_LLD_GetResetReason();

    ResetCause_InitPostProcess();
}


static void ResetCause_HistoryAppend(uint8 val, uint8 n) {
    uint8 i;

    for (i = RESET_HISTORY_DEPTH - 1u; i >= n; --i) {
        reset_cause_history[i] = reset_cause_history[i - n];
    }

    for (i = 0u; i < n; ++i) {
        reset_cause_history[i] = val;
    }
}


/**
 * Determine whether watchdog caused POR.
 */
void ResetCause_ExtWdgCheck(void) {
    uint8 wdgResetCnt = 0;

    if (current_reset_cause == RESET_CAUSE_TYP_WDG_CAUSED_POR) {
        // Get watchdog reset counter
        // wdgResetCnt = ExtWdg_GetResetCounter();
        if (wdgResetCnt > 0) {
        	ResetCause_HistoryAppend(RESET_CAUSE_TYP_EXT_WDG, wdgResetCnt);
        }
    }
}


/**
 * Update reset history array.
 * Call AFTER NvM initialized.
 */
void ResetCause_UpdateHistory(void) {
#if EXT_WDG_CNT_CHECK
	ResetCause_ExtWdgCheck();
#endif

    ResetCause_HistoryAppend(ResetCause_GetCause(), 1);
}


void ResetCause_ResetLoopCheck(void) {
#if SOFTWARE_LOOP_RESET_CHECK
	uint8 idx;
	uint8 same_cnt = 0u;

	for(idx = 1u; idx < SAME_CAUSE_RESET_LOOP_LIM; idx++) {
		if (current_reset_cause == reset_cause_history[idx]) {
			same_cnt += 1u;
		}
	}

	if ((current_reset_cause != RESET_CAUSE_TYP_NORMAL_POR) && (same_cnt == (SAME_CAUSE_RESET_LOOP_LIM - 1u))) {
		while(TRUE) {

		}
	}
#endif
}

#define EVPT_BSW_STOP_SEC_CODE_ASIL_C
#include "Evpt_MemMap.h"
