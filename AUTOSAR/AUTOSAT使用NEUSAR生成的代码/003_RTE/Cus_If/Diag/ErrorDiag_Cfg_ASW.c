/*
* Generated at 2026-08-27 15:04:41.
* Source file last modified at 2026-08-27 14:58:19.
* Config generator version: 4.1.1
*/
#include "ErrorDiag_Types.h"


#define ERRORDIAG_START_SEC_CONST_ASIL_C_32
#include "ErrorDiag_MemMap.h"
const uint16* const ED_ASW_ErrSuppress_Cfg[];
#define ERRORDIAG_STOP_SEC_CONST_ASIL_C_32
#include "ErrorDiag_MemMap.h"
  



#define ERRORDIAG_START_SEC_CONST_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"
const ErrorDiag_ConfigStatus_params_t ED_ASW_ConfigParams_Cfg[ERRORDIAG_ID_NUM_ASW] = 
{
	/* Suppression Index               Suppression Len     CountUp         CountDown       MaxRecovery*/
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_ACCELERATOR_PEDAL_VOLTAGE1_LOW (0) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_ACCELERATOR_PEDAL_VOLTAGE1_HIGH (1) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_ACCELERATOR_PEDAL_VOLTAGE2_LOW (2) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_ACCELERATOR_PEDAL_VOLTAGE2_HIGH (3) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_INT_HVIL_IN_PLS (4) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_EXT_HVIL_IN_PLS (5) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BRAKE_SW_PLS (6) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VACUUM_PUMP_LOW (7) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VACUUM_PUMP_HIGH (8) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_PRECHARGE_RELAY_PLS (9) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MAIN_POSITIVE_RELAY_PLS (10) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MAIN_NEGATIVE_RELAY_PLS (11) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_FAST_CHARGE_POSITIVE_RELAY_PLS (12) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_FAST_CHARGE_NEGATIVE_RELAY_PLS (13) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_UPPER_PRECHARGE_RELAY_PLS (14) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_UPPER_MAIN_RELAY_PLS (15) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_PTC_RELAY_PLS (16) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BATTERY_HEATING_RELAY_PLS (17) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BATTERY_INLET_TEMP_LOW (18) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BATTERY_INLET_TEMP_HIGH (19) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BATTERY_OUTLET_TEMP_LOW (20) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BATTERY_OUTLET_TEMP_HIGH (21) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE2_CC2_LOW (22) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE2_CC2_HIGH (23) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE1_CC2_LOW (24) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE1_CC2_HIGH (25) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_ELECTRIC_DRIVE_CIRCUIT_TEMP_LOW (26) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_ELECTRIC_DRIVE_CIRCUIT_TEMP_HIGH (27) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE_TEMP1_LOW (28) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE_TEMP1_HIGH (29) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE_TEMP2_LOW (30) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_FAST_CHARGE_TEMP2_HIGH (31) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AC_SLOW_CHARGE_TEMP1_LOW (32) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AC_SLOW_CHARGE_TEMP1_HIGH (33) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AC_SLOW_CHARGE_TEMP2_LOW (34) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AC_SLOW_CHARGE_TEMP2_HIGH (35) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_UPPER_FAULT_FB (36) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_UPPER_STATUS_FB (37) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_BUS_VOLTAGE1_LOW (38) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_BUS_VOLTAGE1_HIGH (39) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_BUS_VOLTAGE2_LOW (40) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_BUS_VOLTAGE2_HIGH (41) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_BUS_VOLTAGE_PLS (42) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_INSULATION (43) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_12_RES_MIC_UV (44) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_12_RES_MIC_OV (45) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_HV_DRIVER_5V_UV (46) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_HV_DRIVER_5V_OV (47) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_UBD_MIC_UV (48) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_UBD_MIC_18V_OV (49) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_AN_UBD_MIC_28V_OV (50) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_POWER_1V2_UV (51) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_POWER_1V2_OV (52) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF1_UV (53) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF1_OV (54) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF2_UV (55) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF2_OV (56) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF3_UV (57) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF3_OV (58) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF4_UV (59) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF4_OV (60) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF5_UV (61) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF5_OV (62) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF6_UV (63) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_VDD5REF6_OV (64) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_5VSENSOR1_UV (65) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_5VSENSOR1_OV (66) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_5VSENSOR2_UV (67) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_5VSENSOR2_OV (68) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_HV_PRECHARGE_RELAY_WELD (69) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MAIN_POSITIVE_RELAY_WELD (70) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_MAIN_NEGATIVE_RELAY_WELD (71) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_FAST_CHARGE_RELAY_WELD (72) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_FAST_CHARGE_NEGATIVE_RELAY_WELD (73) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_UPPER_PRECHARGE_RELAY_WELD (74) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_UPPER_MAIN_RELAY_WELD (75) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_PTC_RELAY_WELD (76) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_BATTERY_HEAT_RELAY_WELD (77) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   },   /* ERRORID_DC_BUS_VOLTAGE_PLS (78) */
	{ ED_SUPPRESSION_NONE,             0u,                 3u,             3u,             0u   }    /* ERRORID_DC_BUS_CURRENT_PLS (79) */
};
#define ERRORDIAG_STOP_SEC_CONST_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"

#define ERRORDIAG_START_SEC_CONST_ASIL_C_16
#include "ErrorDiag_MemMap.h"
const uint16 ErrorDiag_Id_Num_Asw = ERRORDIAG_ID_NUM_ASW;
const uint16 ErrorDiag_Asw_AswSupNum = 0;
#define ERRORDIAG_STOP_SEC_CONST_ASIL_C_16
#include "ErrorDiag_MemMap.h"

/* ErrorDiag status */
#define ERRORDIAG_START_SEC_VAR_CLEAR_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"
ErrorDiag_Status_params_t ErrorDiag_ErrorStatus_ASW[ERRORDIAG_ID_NUM_ASW];
#define ERRORDIAG_STOP_SEC_VAR_CLEAR_ASIL_C_UNSPECIFIED
#include "ErrorDiag_MemMap.h"