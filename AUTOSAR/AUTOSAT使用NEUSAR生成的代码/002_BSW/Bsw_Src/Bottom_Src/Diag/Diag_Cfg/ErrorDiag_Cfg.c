/*
* Generated at 2026-08-27 15:04:12.
* Source file last modified at 2026-08-27 14:58:19.
* Config generator version: 4.1.1
*/
#include "ErrorDiag_Cfg.h"


 

#define ERRORDIAG_START_SEC_CONST_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"
const ErrorDiag_ConfigStatus_params_t ED_ConfigParams_Cfg[ERRORDIAG_ID_NUM_BSW] = 
{
	/* Suppression Index               Suppression Len     CountUp         CountDown       MaxRecovery*/
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Prestartup_ResetDetectInit_Test (0) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Prestartup_CACHE_Enable_Test (1) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Prestartup_STACK_MonitorEnable_Test (2) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_DcfCmp_Record_Test (3) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_BIST_Offline_Record_Test (4) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_OSC_XoscSysClkSrcCheckTest (5) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_OSC_IrcoscFreqIsStable (6) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_OSC_XoscFreqIsStable (7) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_OSC_IrcoscFreqAccuracyTest (8) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_PLL_IsStable (9) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_PLL_SysClkSrcCheckTest (10) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_PLL_PeriphClkSrcCheckTest (11) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_PMC_SelfTest (12) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_TSENS_HtdPathInjTest (13) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_TSENS_LtdPathInjTest (14) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_FCCU_RfErrReportPathTest (15) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_FCCU_RfIsConfigured (16) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_FLASH_EccReportPathTest (17) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_RAM_EccReportPathTest (18) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_CACHE_EdcReportPathTest (19) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_CMU_Init (20) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_CMU_ConfigCheckTest (21) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_CMU_MonitorTest (22) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_CRC_SelfTest (23) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_STM_ConfigDataInit (24) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_PIT_ConfigDataInit (25) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_Startup_ADC_ModeSafetyTest (26) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_STARTUP_INJ_CMPU (27) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MCU_Runtime_STM_TimerMonitorTest (28) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MCU_Runtime_PIT_TimerMonitorTest (29) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MCU_Runtime_INTC_IrqMonitorTest (30) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MCU_Runtime_CRC_RegisterReadbackTest (31) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MCU_Runtime_DMA_MonitorTest (32) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_RESET_CAUSE_EXTWDG (33) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_RESET_CAUSE_MCU_ERROR (34) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_APP_Request_Reset (35) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_MCU_APP_Request_FCCU (36) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_OV (37) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_UV (38) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB1_OC (39) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB1_OPL (40) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB2_OC (41) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB2_OPL (42) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB3_OC (43) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB3_OPL (44) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB4_OC (45) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB4_OPL (46) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB5_OC (47) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB5_OPL (48) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB6_OC (49) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB6_OPL (50) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB7_OC (51) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB7_OPL (52) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HE99MD_EXT_HB8_OC (53) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             3u   },   /* ERRORID_HE99MD_EXT_HB8_OPL (54) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS1_OPL (55) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HELS121D_EXT_D_LS1_STB (56) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS1_STG (57) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS2_OPL (58) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HELS121D_EXT_D_LS2_STB (59) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS2_STG (60) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS3_OPL (61) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HELS121D_EXT_D_LS3_STB (62) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS3_STG (63) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS4_OPL (64) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HELS121D_EXT_D_LS4_STB (65) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_HELS121D_EXT_D_LS4_STG (66) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS1_OPL (67) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS1_STB (68) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS1_STG (69) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS2_OPL (70) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS2_STB (71) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS2_STG (72) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS3_OPL (73) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS3_STB (74) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS3_STG (75) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS4_OPL (76) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS4_STB (77) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS4_STG (78) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS5_OPL (79) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS5_STB (80) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS5_STG (81) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS6_OPL (82) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS6_STB (83) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS6_STG (84) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS7_OPL (85) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS7_STB (86) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS7_STG (87) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS8_OPL (88) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS8_STB (89) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS8_STG (90) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS9_OPL (91) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS9_STB (92) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS9_STG (93) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS10_OPL (94) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_WSD7020AF_HS10_STB (95) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_WSD7020AF_HS10_STG (96) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_PHASE_CURRENT_SHORT_GND (97) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_PHASE_CURRENT_SHORT_PWR (98) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_PHASE_CURRENT_OFFSET_ERR (99) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_PHASE_CURRENT_CHK_SUM_ERR (100) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_BKUP_PHASE_CURRENT_CHK_SUM_ERR (101) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_PHASE_CURRENT_OVER (102) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_HIGH_VOLTAGE_OV (103) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_HIGH_VOLTAGE_UV (104) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_BKUP_HIGH_VOLTAGE_CHK_ERR (105) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_EXCITATION_SHORT_GND (106) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_EXCITATION_SHORT_PWR (107) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_EXCITATION_AMP_OVER_LIMIT (108) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_EXCITATION_AMP_OPEN (109) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_RESOLVER_SIN_COS_SHORT_GND (110) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_RESOLVER_SIN_COS_SHORT_PWR (111) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_RESOLVER_SIN_COS_AMP_OVER_LIMIT (112) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_RESOLVER_SIN_COS_OPEN (113) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_RESOLVER_SIN_COS_CHK_ERR (114) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_TQREQ_E2E_OVER_LIMIT (115) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_TQREQ_OVER_LIMIT (116) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_TQREQ_MOD_OVER_LIMIT (117) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_ACTIVE_DISCHARGE_FAILURE (118) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_DRV_LOW_UV (119) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_DRV_HIGH_UV (120) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_DRV_HIGH_DESAT_FAULT (121) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_DRV_LOW_DESAT_FAULT (122) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_DRV_ASC_INVALID_FAULT (123) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_U_HIGH_BRIDGE_FAULT (124) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_U_LOW_BRIDGE_FAULT (125) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_V_HIGH_BRIDGE_FAULT (126) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_V_LOW_BRIDGE_FAULT (127) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_W_HIGH_BRIDGE_FAULT (128) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_W_LOW_BRIDGE_FAULT (129) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_U_OVER_TEMP (130) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_V_OVER_TEMP (131) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_IGBT_W_OVER_TEMP (132) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_STATOR_SEN_P_N_SHORT_GND (133) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_STATOR_SEN_P_N_SHORT_PWR (134) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_12V_SUPPLY_PWR_OV (135) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_12V_SUPPLY_PWR_UV (136) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_5V_SUPPLY_PWR_OV (137) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_MCU_5V_SUPPLY_PWR_UV (138) */
	{ ED_SUPPRESSION_NONE,             0u,                 10u,            10u,            1u   },   /* ERRORID_SBC_Init_failure (139) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SBC_Communication_Failure (140) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_UC_OV (141) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_COM_OV (142) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_VREF_OV (143) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_TRK1_OV (144) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_TRK2_OV (145) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_UC_UV (146) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_COM_UV (147) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_VREF_UV (148) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_TRK1_UV (149) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_TRK2_UV (150) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_PREG_OT (151) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_UC_OT (152) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             2u   },   /* ERRORID_SA47301_COM_OT (153) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_SA47301_ABIST_ERR (154) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             0u   },   /* ERRORID_SA47301_SHUTDOWN_PATH_TEST (155) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9015_ERRQ (156) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9015_ERR_LOC_OUT (157) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9015_ERR_EXT_OUT (158) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_0 (159) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_1 (160) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_2 (161) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_3 (162) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_4 (163) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_5 (164) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_6 (165) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_CRC_ERR_7 (166) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_0 (167) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_1 (168) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_2 (169) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_3 (170) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_4 (171) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_5 (172) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_6 (173) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OC_DIAG_7 (174) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_0 (175) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_1 (176) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_2 (177) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_3 (178) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_4 (179) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_5 (180) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_6 (181) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_INIT_OPL_DIAG_7 (182) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_0 (183) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_1 (184) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_2 (185) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_3 (186) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_4 (187) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_5 (188) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_6 (189) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_CRC_ERR_7 (190) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_0 (191) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_1 (192) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_2 (193) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_3 (194) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_4 (195) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_5 (196) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_6 (197) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_MO_FREQ_ERR_7 (198) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_0 (199) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_1 (200) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_2 (201) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_3 (202) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_4 (203) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_5 (204) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_6 (205) */
	{ ED_SUPPRESSION_NONE,             0u,                 1u,             1u,             255u },   /* ERRORID_TLE9018_COMM_TIMEOUT_7 (206) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_0 (207) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_1 (208) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_2 (209) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_3 (210) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_4 (211) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_5 (212) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_6 (213) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_GEN_DIAG_ERR_7 (214) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_0 (215) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_1 (216) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_2 (217) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_3 (218) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_4 (219) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_5 (220) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_6 (221) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_X_X_ERR_7 (222) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_0 (223) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_1 (224) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_2 (225) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_3 (226) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_4 (227) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_5 (228) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_6 (229) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_EXT_TEMP_DIAG_X_ERR_7 (230) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_0 (231) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_1 (232) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_2 (233) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_3 (234) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_4 (235) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_5 (236) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_6 (237) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_REF_DIAG_ERR_7 (238) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_0 (239) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_1 (240) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_2 (241) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_3 (242) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_4 (243) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_5 (244) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_6 (245) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_PCVM_SCVM_CMP_ERR_7 (246) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_0 (247) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_1 (248) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_2 (249) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_3 (250) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_4 (251) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_5 (252) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_6 (253) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_DIAG_RES_CHECK_7 (254) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_0 (255) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_1 (256) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_2 (257) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_3 (258) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_4 (259) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_5 (260) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u },   /* ERRORID_TLE9018_TMP_SHORT_ERR_6 (261) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             255u }    /* ERRORID_TLE9018_TMP_SHORT_ERR_7 (262) */
};
#define ERRORDIAG_STOP_SEC_CONST_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"


#define ERRORDIAG_START_SEC_CONST_ASIL_C_16
#include "ErrorDiag_MemMap.h"
const uint16 ED_ClearableCfg[ED_CLEARABLE_NUM] =
{
    ERRORID_HE99MD_OV,
    ERRORID_HE99MD_UV,
    ERRORID_HE99MD_EXT_HB1_OC,
    ERRORID_HE99MD_EXT_HB1_OPL,
    ERRORID_HE99MD_EXT_HB2_OC,
    ERRORID_HE99MD_EXT_HB2_OPL,
    ERRORID_HE99MD_EXT_HB3_OC,
    ERRORID_HE99MD_EXT_HB3_OPL,
    ERRORID_HE99MD_EXT_HB4_OC,
    ERRORID_HE99MD_EXT_HB4_OPL,
    ERRORID_HE99MD_EXT_HB5_OC,
    ERRORID_HE99MD_EXT_HB5_OPL,
    ERRORID_HE99MD_EXT_HB6_OC,
    ERRORID_HE99MD_EXT_HB6_OPL,
    ERRORID_HE99MD_EXT_HB7_OC,
    ERRORID_HE99MD_EXT_HB7_OPL,
    ERRORID_HE99MD_EXT_HB8_OC,
    ERRORID_HE99MD_EXT_HB8_OPL,
    ERRORID_HELS121D_EXT_D_LS1_OPL,
    ERRORID_HELS121D_EXT_D_LS1_STB,
    ERRORID_HELS121D_EXT_D_LS1_STG,
    ERRORID_HELS121D_EXT_D_LS2_OPL,
    ERRORID_HELS121D_EXT_D_LS2_STB,
    ERRORID_HELS121D_EXT_D_LS2_STG,
    ERRORID_HELS121D_EXT_D_LS3_OPL,
    ERRORID_HELS121D_EXT_D_LS3_STB,
    ERRORID_HELS121D_EXT_D_LS3_STG,
    ERRORID_HELS121D_EXT_D_LS4_OPL,
    ERRORID_HELS121D_EXT_D_LS4_STB,
    ERRORID_HELS121D_EXT_D_LS4_STG,
    ERRORID_WSD7020AF_HS1_OPL,
    ERRORID_WSD7020AF_HS1_STB,
    ERRORID_WSD7020AF_HS1_STG,
    ERRORID_WSD7020AF_HS2_OPL,
    ERRORID_WSD7020AF_HS2_STB,
    ERRORID_WSD7020AF_HS2_STG,
    ERRORID_WSD7020AF_HS3_OPL,
    ERRORID_WSD7020AF_HS3_STB,
    ERRORID_WSD7020AF_HS3_STG,
    ERRORID_WSD7020AF_HS4_OPL,
    ERRORID_WSD7020AF_HS4_STB,
    ERRORID_WSD7020AF_HS4_STG,
    ERRORID_WSD7020AF_HS5_OPL,
    ERRORID_WSD7020AF_HS5_STB,
    ERRORID_WSD7020AF_HS5_STG,
    ERRORID_WSD7020AF_HS6_OPL,
    ERRORID_WSD7020AF_HS6_STB,
    ERRORID_WSD7020AF_HS6_STG,
    ERRORID_WSD7020AF_HS7_OPL,
    ERRORID_WSD7020AF_HS7_STB,
    ERRORID_WSD7020AF_HS7_STG,
    ERRORID_WSD7020AF_HS8_OPL,
    ERRORID_WSD7020AF_HS8_STB,
    ERRORID_WSD7020AF_HS8_STG,
    ERRORID_WSD7020AF_HS9_OPL,
    ERRORID_WSD7020AF_HS9_STB,
    ERRORID_WSD7020AF_HS9_STG,
    ERRORID_WSD7020AF_HS10_OPL,
    ERRORID_WSD7020AF_HS10_STB,
    ERRORID_WSD7020AF_HS10_STG 
};
#define ERRORDIAG_STOP_SEC_CONST_ASIL_C_16
#include "ErrorDiag_MemMap.h"
