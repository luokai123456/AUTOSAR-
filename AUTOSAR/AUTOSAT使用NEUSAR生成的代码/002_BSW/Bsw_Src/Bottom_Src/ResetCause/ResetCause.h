#ifndef CDD_SRC_RESETCAUSE_RESETCAUSE_H
#define CDD_SRC_RESETCAUSE_RESETCAUSE_H


#include "Std_Types.h"


typedef enum
{
    /* 'Destructive' Event Status Register (RGM_DES) */
    RC_MCU_POWER_ON_RESET=0x00U,   /**<  Power-On reset RGM_DES[F_POR]. */
    RC_MCU_EXT_POWER_ON_RESET,     /**<  External power-on reset RGM_DES[F_PORST]. */
    RC_MCU_SOFT_DEST_RESET,        /**<  Software 'destructive' reset RGM_DES[F_SOFT_DEST]. */
    RC_MCU_FFRR_RESET,             /**<  FCCU failure to react reset RGM_DES[F_FFRR]. */
    RC_MCU_SUF_RESET,              /**<  STCU unrecoverable fault RGM_DES[F_SUF]. */
    RC_MCU_EDR_RESET,              /**<  Functional reset escalation RGM_DES[F_EDR]. */
    RC_MCU_FIF_RESET,              /**<  Flash initialization failure reset RGM_DES[F_FIF]. */
    RC_MCU_JTAG_DEST_RESET,        /**<  JTAG 'destructive' reset RGM_DES[F_JTAG_DEST]. */
    RC_MCU_SSCM_DEST_RESET,        /**<  HSM 'destructive' reset RGM_DES[F_SSCM_DEST]. */
    RC_MCU_HSM_DEST_RESET,         /**<  HSM 'destructive' reset RGM_DES[F_HSM_DEST]. */
    RC_MCU_TSR_DEST_RESET,         /**<  Temperature sensor 'destructive' reset RGM_DES[F_TSR_DEST]. */
    RC_MCU_VOR_DEST_RESET,         /**<  Voltage out of range 'destructive' reset RGM_DES[F_VOR_DEST]. */
    /* 'Functional' Event Status Register (RGM_FES) */
    /* RC_MCU_ESR0_RESET, */             /**<  ESR0 External Reset. RGM_FES[F_ESR0]. */
    /* RC_MCU_ESR1_RESET, */             /**<  ESR1 External Reset. RGM_FES[F_ESR1]. */
    /* RC_MCU_ST_DONE_RESET, */          /**<  Self test completed. RGM_FES[F_ST_DONE]. */
    RC_MCU_SOFT_FUNC_RESET,        /**<  Software 'functional' reset. RGM_FES[F_SOFT_FUNC]. */
    RC_MCU_FCCU_HARD_RESET,        /**<  FCCU hard reaction reset. RGM_FES[F_FCCU_HARD]. */
    RC_MCU_FCCU_SOFT_RESET,        /**<  FCCU soft reaction. RGM_FES[F_FCCU_SOFT]. */
    RC_MCU_JTAG_FUNC_RESET,        /**<  JTAG 'functional' reset. RGM_FES[F_JTAG_FUNC]. */
    RC_MCU_HSM_FUNC_RESET,         /**<  HSM 'functional' reset. RGM_FES[F_HSM_FUNC]. */
    RC_MCU_TSR_FUNC_RESET,         /**<  Temperature sensor 'functional' reset. RGM_FES[F_TSR_FUNC]. */
    RC_MCU_VOR_FUNC_RESET,         /**<  Voltage out of range 'functional' reset. RGM_FES[F_VOR_FUNC]. */
    RC_MCU_NO_RESET_REASON,                 /**<  No reset reason found */
    RC_MCU_MULTIPLE_RESET_REASON,           /**<  More than one reset events are logged except "Power on event" */
    RC_MCU_RESET_UNDEFINED         /**<  Undefined reset source. */
} ResetCause_ResetType;


#define RESET_CAUSE_TYP_WDG_CAUSED_POR RC_MCU_EXT_POWER_ON_RESET
#define RESET_CAUSE_TYP_NORMAL_POR RC_MCU_POWER_ON_RESET

#define RESET_CAUSE_TYP_EXT_WDG (0xA0u)
#define RESET_CAUSE_TYP_UNINIT (0xFFu)

#define RESET_HISTORY_DEPTH (20u)


extern volatile uint8 reset_cause_history[RESET_HISTORY_DEPTH];
extern const uint8 reset_cause_history_default[RESET_HISTORY_DEPTH];


void ResetCause_PreInit(void);
void ResetCause_UpdateHistory(void);
void ResetCause_ResetLoopCheck(void);
uint8 ResetCause_GetCause(void);
Std_ReturnType ResetCause_LoadFromNvm(uint8 *romData);
boolean ResetCause_IsPorHappened(void);

uint32 ResetCause_GetFunctionalEventStatus(void);
uint32 ResetCause_GetDestructiveEventStatus(void);



#endif  /* CDD_SRC_RESETCAUSE_RESETCAUSE_H */
