/**
****************************************************************************************
 * @FilePath: saf_core.h
 * @Author: CCORE
 * @Date: 2024-02-28
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: CORE Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_CORE_H
#define SAF_CORE_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "rgm_lld.h"
#include "saf_cpu.h"
#include "saf_common.h"

/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_CORE_DAC1_SPR_ID                                 (316U)
#define SAF_CORE_DAC2_SPR_ID                                 (317U)
#define SAF_CORE_DBCR0_SPR_ID                                (308U)
#define SAF_CORE_DBCR2_SPR_ID                                (310U)
#define SAF_CORE_DBCR4_SPR_ID                                (563U)
#define SAF_CORE_DBSR_SPR_ID                                 (304U)
#define SAF_CORE_DBSR_DAC_MASK                               (0xF0000U)

#define SAF_MCME_CHEHER_CORE_ENABLE_TIME_OUT_LIMIT           (1U) /*1ms*/
#define SAF_MCME_INSTANCE                                    (0U)
#define MC_ME_INSTANCE_COUNT                                  1U
#if defined(CCFC3012PT)
#define MC_ME_CS_S_COREC_MASK                                 0x02u
#else
#define MC_ME_CS_S_COREC_MASK                                 0x04u
#endif
#define MC_ME_GS_S_MTRANS_MASK                                0x8000000u

#define SAF_RGM_INSTANCE                                     (0U)
#define MC_RGM_INSTANCE_COUNT                                (1U)
#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
#define RGM_DEST_MASK_COUNT                                  (22U)
#else
#define RGM_DEST_MASK_COUNT                                  (24U)
#endif

#define SAF_CORE_RESET_DIS_FLAG                              (0U)
#define SAF_CORE_CHECKER_CORE_DIS_FLAG                       (0U)

#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
#define SAF_RESET_DEST_COUNT                                 (12U)
#define SAF_RESET_FUNC_COUNT                                 (10U)
#else
#define SAF_RESET_DEST_COUNT                                 (13U)
#define SAF_RESET_FUNC_COUNT                                 (11U)
#endif

#define PAE_RAE_ENABLE  0x03
#define PAE_ENABLE      0x02

#define SAF_XBAR0_CRS0_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS0 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#define SAF_XBAR0_CRS1_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS1 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#define SAF_XBAR0_CRS2_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS2 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
#define SAF_XBAR0_CRS3_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS3 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#endif
#define SAF_XBAR0_CRS4_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS4 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
#define SAF_XBAR0_CRS5_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS5 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#endif
#define SAF_XBAR0_CRS7_ARB_MODE_FIXED_PRIORITY   (XBAR_0_CRS7 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))

#define SAF_XBAR1_CRS0_ARB_MODE_FIXED_PRIORITY   (XBAR_1_CRS0 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#if !(defined(CCFC3008PC) | defined(CCFC3008PCSN))
#define SAF_XBAR1_CRS1_ARB_MODE_FIXED_PRIORITY   (XBAR_1_CRS1 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#endif
#define SAF_XBAR1_CRS2_ARB_MODE_FIXED_PRIORITY   (XBAR_1_CRS2 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))
#define SAF_XBAR1_CRS3_ARB_MODE_FIXED_PRIORITY   (XBAR_1_CRS3 &= (uint32_t)(~((uint32_t)0x3U << (uint32_t)8U)))



#if defined(CCFC3008PC) | defined(CCFC3008PCSN)
#define SAF_RESET_REASON_DETECT_OBJ_LIST                     {\
                                                              {SAF_RESET_DEST_VOR,      "VOR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_TSR,      "TSR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_HSM,      "HSM",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SCCM,     "SCCM",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_JTAG,     "JTAG",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_FIF,      "FIF",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_EDR,      "EDR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SWT_AO,   "SWT_AO",        SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SUF,      "SUF",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_FFRR,     "FFRR",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SOFT,     "SOFT",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_PORST,    "POST",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_POR,      "POR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_FUNC_VOR,      "VOR_FUNC",      SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_TSR,      "TSR_FUNC",      SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_HSM,      "HSM_FUNC",      SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_JTAG,     "JTAG_FUNC",     SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_FUNC_SWT_AO,   "SWT_AO",        SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_FCCU_SOFT,"FCCU_SOFT_FUNC",SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_FUNC_FCCU_HARD,"FCCU_HARD_FUNC",SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_SOFT,     "SOFT_FUNC",     SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_ST_DONE,  "ST_DONE_FUNC",  SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_ESR1,     "ESR1_FUNC",     SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_ESR0,     "ESR0_FUNC",     SAF_CORE_GetResetFlag},      \
                                                            }

#define RGM_DEST_MASK                                         {RGM_VOR_DEST_MASK,RGM_TSR_DEST_MASK,RGM_HSM_DEST_MASK,RGM_SSCM_DEST_MASK,RGM_JTAG_DEST_MASK,RGM_FIF_DEST_MASK,RGM_SWT_AO_DEST_MASK,\
                                                               RGM_EDR_DEST_MASK,RGM_SUF_DEST_MASK,RGM_FFRR_DEST_MASK,RGM_SOFT_DEST_MASK,RGM_PORST_DEST_MASK,RGM_POR_DEST_MASK,\
                                                               RGM_VOR_FUNC_MASK,RGM_TSR_FUNC_MASK,RGM_HSM_FUNC_MASK,RGM_JTAG_FUNC_MASK,RGM_SWT_AO_FUNC_MASK,RGM_FCCU_SOFT_FUNC_MASK,RGM_FCCU_HARD_FUNC_MASK,\
                                                               RGM_SOFT_FUNC_MASK,RGM_ST_DONE_FUNC_MASK,RGM_ESR1_FUNC_MASK,RGM_ESR0_FUNC_MASK}
#else
#define SAF_RESET_REASON_DETECT_OBJ_LIST                     {\
                                                              {SAF_RESET_DEST_VOR,      "VOR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_TSR,      "TSR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_HSM,      "HSM",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SCCM,     "SCCM",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_JTAG,     "JTAG",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_FIF,      "FIF",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_EDR,      "EDR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SUF,      "SUF",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_FFRR,     "FFRR",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_SOFT,     "SOFT",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_PORST,    "POST",          SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_DEST_POR,      "POR",           SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_FUNC_VOR,      "VOR_FUNC",      SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_TSR,      "TSR_FUNC",      SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_HSM,      "HSM_FUNC",      SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_JTAG,     "JTAG_FUNC",     SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_FCCU_SOFT,"FCCU_SOFT_FUNC",SAF_CORE_GetResetFlag},      \
                                                              {SAF_RESET_FUNC_FCCU_HARD,"FCCU_HARD_FUNC",SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_SOFT,     "SOFT_FUNC",     SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_ST_DONE,  "ST_DONE_FUNC",  SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_ESR1,     "ESR1_FUNC",     SAF_CORE_GetResetFlag},      \
															  {SAF_RESET_FUNC_ESR0,     "ESR0_FUNC",     SAF_CORE_GetResetFlag},      \
                                                            }

#define RGM_DEST_MASK                                         {RGM_VOR_DEST_MASK,RGM_TSR_DEST_MASK,RGM_HSM_DEST_MASK,RGM_SSCM_DEST_MASK,RGM_JTAG_DEST_MASK,RGM_FIF_DEST_MASK,\
                                                               RGM_EDR_DEST_MASK,RGM_SUF_DEST_MASK,RGM_FFRR_DEST_MASK,RGM_SOFT_DEST_MASK,RGM_PORST_DEST_MASK,RGM_POR_DEST_MASK,\
                                                               RGM_VOR_FUNC_MASK,RGM_TSR_FUNC_MASK,RGM_HSM_FUNC_MASK,RGM_JTAG_FUNC_MASK,RGM_FCCU_SOFT_FUNC_MASK,RGM_FCCU_HARD_FUNC_MASK,\
                                                               RGM_SOFT_FUNC_MASK,RGM_ST_DONE_FUNC_MASK,RGM_ESR1_FUNC_MASK,RGM_ESR0_FUNC_MASK}
#endif

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/

typedef bool (*saf_reset_reason_detect_t)(SAF_RESET_REASON_TYPE type);

/*!
 * @brief reset detect structure.
 *
 * This is used to represent reset detect information. Including reset reason type, reason name,
 * and the detect function.
 */
typedef struct
{
    /* reset reason type */
    SAF_RESET_REASON_TYPE type;
    /* reason name */
    char *name;
    /* detect function */
    saf_reset_reason_detect_t func;
} saf_core_reset_detect_t;

/*!
 * @brief core reset manage structure.
 *
 * This is used to manage core reset. It includes current system reset status.
 */
typedef struct
{
    /* current system reset status */
    bool curSysResetStaus[SAF_RESET_COUNT];
} saf_core_reset_mgr_t;

/*!
 * @brief reset threshold
 *
 * This is used to configure the thresholds for functional reset and destructive reset
 */
typedef struct
{
    /*Destructive Reset Escalation Threshold*/
    uint8_t DesThreshold;
    /*Functional Reset Escalation Threshold*/
    uint8_t FuncThreshold;
} saf_core_reset_config_t;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
void SAF_CORE_SetRgmDretReg(const uint8_t value);
void SAF_CORE_SetRgmFretReg(const uint8_t value);
FS_STATUS SAF_CORE_DesSafeModeRequest(destrutive_reset_name_t name, alternate_request_t mode);
FS_STATUS SAF_CORE_FuncSafeModeRequest(functional_reset_name_t name,alternate_request_t mode); 
FS_STATUS SAF_CORE_CleanRegResetFlag(void);
bool SAF_CORE_GetResetFlag(const SAF_RESET_REASON_TYPE type);
bool SAF_CORE_IsSafetyCore(void); 
bool SAF_CORE_CheckerCoreIsEnabled(void);
bool SAF_CORE_CheckerResetFlag(const SAF_RESET_REASON_TYPE resetType);
bool SAF_CORE_IsDestructiveReset(void);
bool SAF_CORE_IsFunctionReset(void);
void SAF_CORE_SSCM_PAERAESet(void);
FS_STATUS SAF_CORE_ResetDetectInit(void);
bool SAF_CORE_GetRgmDearReg(destrutive_reset_name_t name);
bool SAF_CORE_GetRgmFearReg(functional_reset_name_t name);

#ifdef __cplusplus
}
#endif

#endif
