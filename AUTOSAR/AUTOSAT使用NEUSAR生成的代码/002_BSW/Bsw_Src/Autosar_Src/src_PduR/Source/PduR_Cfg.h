/*
********************************************************************************
*
*  File name: PduR_cfg.h
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: LuQ/2024.05.20
* Change: New create.
* Cause: New
********************************************************************************
*/
#ifndef PDUR_CFG_H_
#define PDUR_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* PolySpace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */

/* PduRGeneral Start */
/**
 * Name: PduRDevErrorDetect
 * Brief: Switches the Default Error Tracer (Det) detection and notification
 *        ON or OFF.
 */
#define PDUR_DEV_ERROR_DETECT (STD_OFF)

/**
 * Name: PduRVersionInfoApi
 * Brief: If true the PduR_GetVersionInfo API is available.
 */
#define PDUR_VERSION_INFO_API (STD_OFF)
/**
 * Name: PduRZeroCostOperation
 * Brief: If set the PduR configuration generator will report an error if
 *        zero-costoperation cannot be fulfilled.
 */
#define PDUR_ZERO_COST_OPERATION (STD_OFF)
#define PDUR_SUPPORT_MULTICORE (STD_OFF)
/* PduRGeneral End   */

#define PDUR_SUPPORT_IF_GETWAY (STD_ON)
/**
 * Note:
 * The gateway requirements are deliberately separated to allow an efficient
 * implementation of the PDU Router module in case
 * gatewaying is not needed.
 * In case the PDU Router module allows gatewaying of I-PDUs, these requirements
 * are seen as additional and not replacing previous requirements.
 */
#if ((defined PDUR_SUPPORT_IF_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY))
#define PDUR_SUPPORT_GETWAY             (STD_ON)
#else   /* #if ((defined PDUR_SUPPORT_IF_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY)) */
#define PDUR_SUPPORT_GETWAY             (STD_OFF)
#endif   /* #if ((defined PDUR_SUPPORT_IF_GETWAY) || (defined PDUR_SUPPORT_TP_GETWAY)) */

#define PDUR_SUPPORT_IF_MULICAST (STD_ON)

/* Note:
   The multicast feature is separated to an own section since there are issues using
   this feature as described in section 4.1.1.
*/
#if ((defined PDUR_SUPPORT_IF_MULICAST) || (defined PDUR_SUPPORT_TP_MULICAST))
#define PDUR_SUPPORT_MULICAST               (STD_ON)
#else   /* #if ((defined PDUR_SUPPORT_IF_MULICAST) || (defined PDUR_SUPPORT_TP_MULICAST)) */
#define PDUR_SUPPORT_MULICAST               (STD_OFF)
#endif   /* #if ((defined PDUR_SUPPORT_IF_MULICAST) || (defined PDUR_SUPPORT_TP_MULICAST)) */

#if ((defined PDUR_SUPPORT_IF_MULICAST) && (defined PDUR_SUPPORT_TP_MULICAST))
#define PDUR_SUPPORT_MULICAST_IF_AND_TP     (STD_ON)
#else   /* #if ((defined PDUR_SUPPORT_IF_MULICAST) || (defined PDUR_SUPPORT_TP_MULICAST)) */
#define PDUR_SUPPORT_MULICAST_IF_AND_TP     (STD_OFF)
#endif   /* #if ((defined PDUR_SUPPORT_IF_MULICAST) || (defined PDUR_SUPPORT_TP_MULICAST)) */

/* The NeuSAR communication module does not currently support MeteData processing. */

#if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH))
#error This version does not support meteData, please do not enable this item.
#endif  /* #if (defined NEUSAR_SUPPORT_METE_DATA_LENGTH && (STD_ON == NEUSAR_SUPPORT_METE_DATA_LENGTH)) */

#define PDUR_SrcPduID_PMS_TWVCommand_T34TDk (0)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_MHGV_Status_T34TDk (1)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_FWFV_Status_T34TDk (2)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HEWP_T34TDk (3)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HEWP_1_T34TDk (4)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BHM_10nggJ (5)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BSOC_10nggJ (6)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BEM_10nggJ (7)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BSD_10nggJ (8)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BST_10nggJ (9)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMT_10nggJ (10)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMV_10nggJ (11)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BSM_10nggJ (12)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCS_10nggJ (13)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCL_10nggJ (14)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BRO_10nggJ (15)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCP_10nggJ (16)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BRM_10nggJ (17)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CHM_10nggJ (18)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CEM_10nggJ (19)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CSD_10nggJ (20)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CST_10nggJ (21)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CCS_10nggJ (22)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CRO_10nggJ (23)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CML_10nggJ (24)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CTS_10nggJ (25)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CRM_10nggJ (26)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_TrqSpd_RMXr12 (27)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_Sts_RMXr12 (28)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_MotorAlarmInfo_RMXr12 (29)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_MotorElePara_RMXr12 (30)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_Temperature_RMXr12 (31)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_IPU_IMMOCode_RMXr12 (32)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_Status_RMXr12 (33)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Status_RMXr12 (34)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_VoltCurrent_RMXr12 (35)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_SOX_RMXr12 (36)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_SOP_RMXr12 (37)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_CellVoltMaxMin_RMXr12 (38)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_CCM_Req_RMXr12 (39)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_CellVolt_RMXr12 (40)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_CellTemp_RMXr12 (41)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_PackCode_RMXr12 (42)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_StsChgInfo_RMXr12 (43)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Fault2_RMXr12 (44)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Temp_RMXr12 (45)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Fault_RMXr12 (46)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Fault_RMXr12 (47)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_BatCfg_RMXr12 (48)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Info1_RMXr12 (49)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Info2_RMXr12 (50)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Info3_RMXr12 (51)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_OdometerInfo_RMXr12 (52)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_UseInfo_RMXr12 (53)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_ChgEnergy_RMXr12 (54)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_PwrOut_RMXr12 (55)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_RecoveryEngInfo_RMXr12 (56)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Dischg_ExChgEngInfo_RMXr12 (57)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Dischg_ExChgCapacityInfo_RMXr12 (58)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_RecoveryCapacityInfo_RMXr12 (59)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_OverseasChgInfo_RMXr12 (60)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_ACChgCtrlInfo_RMXr12 (61)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_Infor_RMXr12 (62)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_Infor2_RMXr12 (63)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_CellVolt1_RMXr12 (64)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_CellTemp1_RMXr12 (65)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_PackCode1_RMXr12 (66)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOXInfor_RMXr12 (67)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Command_RMXr12 (68)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Ctrl1_RMXr12 (69)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_BMSH_Ctrl_RMXr12 (70)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_SwapAuth_RMXr12 (71)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_EPS_SystemSts_RMXr12 (72)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_DCDC_Ctrl_RMXr12 (73)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Ctrl_RMXr12 (74)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_ModeControl_RMXr12 (75)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_StsEpt_RMXr12 (76)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_StsSwap_RMXr12 (77)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_VehicleInfo_RMXr12 (78)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor1_RMXr12 (79)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor2_RMXr12 (80)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor5_RMXr12 (81)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor6_RMXr12 (82)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_IPK_STS_RMXr12 (83)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_PEPSAuth_RMXr12 (84)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_BMSH_Info_RMXr12 (85)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_PEPS_Information_RMXr12 (86)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_BMSH_sts_RMXr12 (87)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_EDCPCtr_RMXr12 (88)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Temp_Ctrl_RMXr12 (89)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_VIN_RMXr12 (90)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_RemCon_RMXr12 (91)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EGSM_Status_RMXr12 (92)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_DCDC_LV_Info_RMXr12 (93)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_DCDC_HV_Info_RMXr12 (94)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_DCDC_FaultInfo_RMXr12 (95)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_OBC_Sts_RMXr12 (96)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_OBC_Curr_RMXr12 (97)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_OBC_Failmode_RMXr12 (98)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_OBC_Status2_RMXr12 (99)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_RFR_SwapBatCode_RMXr12 (100)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Station_Status_RMXr12 (101)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_RFR_Seed_RMXr12 (102)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_RFR_Info_RMXr12 (103)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EGSM_DiagResp_RMXr12 (104)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_DCDC_DiagResp_RMXr12 (105)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_OBC_DiagResp_RMXr12 (106)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_RFR_DiagResp_RMXr12 (107)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq25Tx_GtPS3U (108)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq24Tx_GtPS3U (109)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq23Tx_GtPS3U (110)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq22Tx_GtPS3U (111)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq21Tx_GtPS3U (112)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq20Tx_GtPS3U (113)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq11Tx_GtPS3U (114)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq10Tx_GtPS3U (115)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq9Tx_GtPS3U (116)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq8Tx_GtPS3U (117)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq7Tx_GtPS3U (118)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq6Tx_GtPS3U (119)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq19Tx_GtPS3U (120)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq18Tx_GtPS3U (121)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq17Tx_GtPS3U (122)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq16Tx_GtPS3U (123)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq15Tx_GtPS3U (124)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq14Tx_GtPS3U (125)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq13Tx_GtPS3U (126)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq12Tx_GtPS3U (127)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq5Tx_GtPS3U (128)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq4Tx_GtPS3U (129)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestOutput6_GtPS3U (130)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestOutput5_GtPS3U (131)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestOutput4_GtPS3U (132)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestOutput1_GtPS3U (133)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestOutput2_GtPS3U (134)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestOutput3_GtPS3U (135)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Dto_GtPS3U (136)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq3Tx_GtPS3U (137)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq2Tx_GtPS3U (138)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Daq1Tx_GtPS3U (139)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Xcp_Cro_GtPS3U (140)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TestInput_GtPS3U (141)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_RelaySampSwich_lGfZId (142)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_RelaySampSwich_lGfZId (143)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Func_DiagReq_lGfZId (144)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_Status_lGfZId (145)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_InsulateaValue_lGfZId (146)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_MainRelayValue_lGfZId (147)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_OtherRelayValue_lGfZId (148)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_Other2RelayValue_lGfZId (149)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_Version_Info_lGfZId (150)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_DiagResp_lGfZId (151)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_CSControl2_fVs55R (152)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Ctrl_fVs55R (153)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_ModeControl_fVs55R (154)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_EngControl_fVs55R (155)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_CSControl1_fVs55R (156)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_StsEpt_fVs55R (157)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_General_fVs55R (158)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_BMSH_Ctrl_fVs55R (159)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Ctrl1_fVs55R (160)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_TrqSpd_fVs55R (161)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_ACU_ChimeTelltaleReq_fVs55R (162)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_YRS1_fVs55R (163)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_YRS2_fVs55R (164)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_SAS_Status_fVs55R (165)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_Status_fVs55R (166)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_VLC_TorqueRequest_fVs55R (167)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_DA_MESSAGE_fVs55R (168)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_FrontWheelSpeedsKPH_fVs55R (169)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_RearWheelSpeedsKPH_fVs55R (170)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_WheelSpeedsRC_fVs55R (171)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_DriverRemind_fVs55R (172)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_Regen_fVs55R (173)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_PTTorqueRequest_fVs55R (174)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EHB_ISARequest_fVs55R (175)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPK_Infor_fVs55R (176)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PDC_Status_Info_fVs55R (177)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Command__XQc0B (178)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_VehicleInfo__XQc0B (179)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_CSControl2__XQc0B (180)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_DCDC_Ctrl__XQc0B (181)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Ctrl__XQc0B (182)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_ModeControl__XQc0B (183)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_StsSwap__XQc0B (184)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_EngControl__XQc0B (185)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_CSControl1__XQc0B (186)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_InforCAN__XQc0B (187)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_IPK_Status__XQc0B (188)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_MMI_SwitchFb__XQc0B (189)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Ctrl1__XQc0B (190)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Temp_Ctrl__XQc0B (191)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Temp_Status__XQc0B (192)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_Auth__XQc0B (193)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_LockVehInfor__XQc0B (194)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_TotalOdometer1__XQc0B (195)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_StsEpt__XQc0B (196)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_ErrCode__XQc0B (197)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_CVW__XQc0B (198)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_instruct__XQc0B (199)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_TBOX_Fault__XQc0B (200)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_TBOX_Fault1__XQc0B (201)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_VIN__XQc0B (202)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_VerInfo__XQc0B (203)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HEWP__XQc0B (204)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HEWP_1__XQc0B (205)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_TrqSpd__XQc0B (206)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_Temperature__XQc0B (207)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_Warning__XQc0B (208)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPU_MotorAlarmInfo__XQc0B (209)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_Status__XQc0B (210)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_General__XQc0B (211)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_VoltCurr__XQc0B (212)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Battery_Performance__XQc0B (213)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Battery_chgstate__XQc0B (214)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_CellTempLimitValue__XQc0B (215)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_OBC_Control__XQc0B (216)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_PackCode__XQc0B (217)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_CellVoltData__XQc0B (218)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_FaultToGovernmentBackendDa__XQc0B (219)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_sts__XQc0B (220)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_CellTempData__XQc0B (221)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_EnergyStatisticsOnce__XQc0B (222)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_Min_MAX_CellVolt__XQc0B (223)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Temp__XQc0B (224)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Fault__XQc0B (225)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Fault__XQc0B (226)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Status__XQc0B (227)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_Infor2__XQc0B (228)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_SOP__XQc0B (229)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_VoltCurrent__XQc0B (230)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_StsChgInfo__XQc0B (231)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_ACChgCtrlInfo__XQc0B (232)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_CCM_Req__XQc0B (233)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Info1__XQc0B (234)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_UseInfo__XQc0B (235)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_Dischg_ExChgEngInfo__XQc0B (236)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_RecoveryEngInfo__XQc0B (237)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_CellVolt1__XQc0B (238)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_CellTemp1__XQc0B (239)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_PackCode1__XQc0B (240)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOXInfor__XQc0B (241)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMSH_TBOX_Info3__XQc0B (242)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_PEPSAuth__XQc0B (243)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_EDCPCtr__XQc0B (244)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EDCP_Status__XQc0B (245)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HBCP_Status__XQc0B (246)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor1__XQc0B (247)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor2__XQc0B (248)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor5__XQc0B (249)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_HardInfor6__XQc0B (250)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_BMSH_Ctrl__XQc0B (251)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_TWVCommand__XQc0B (252)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_MHGV_Status__XQc0B (253)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_DiagResp__XQc0B (254)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_OBD_DiagResp__XQc0B (255)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PEPS_Message_Sts__XQc0B (256)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPK_DateTime_Info__XQc0B (257)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_IPK_TotalOdometer__XQc0B (258)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_MMI_SOCSet__XQc0B (259)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_MMI_HVSM_Command__XQc0B (260)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BBM_StsFB__XQc0B (261)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_AC_Status_Info__XQc0B (262)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_AC_Status_SE_ACCM__XQc0B (263)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_AC_MMI_Status__XQc0B (264)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_AC_Status_Info1__XQc0B (265)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_CSM_SwitchSts__XQc0B (266)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PEPS_IMMOCode__XQc0B (267)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PEPS_KeyReminder__XQc0B (268)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCM_ACCinfor__XQc0B (269)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCM_StateUpdate__XQc0B (270)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCM_LDoorWindowState__XQc0B (271)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCM_RDoorWindowState__XQc0B (272)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BCM_SunroofState__XQc0B (273)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_instruct__XQc0B (274)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_instruct1__XQc0B (275)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_DateTime_Info__XQc0B (276)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_ChgLimit_Command__XQc0B (277)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_RemCon__XQc0B (278)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_LockVehCtrl__XQc0B (279)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_TBOX_VCULockResp__XQc0B (280)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_DiagReq__XQc0B (281)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_DCDC_DiagReq__XQc0B (282)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_OBC_DiagReq__XQc0B (283)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_EGSM_DiagReq__XQc0B (284)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_RFR_DiagReq__XQc0B (285)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_HCM_DiagReq__XQc0B (286)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Func_DiagReq__XQc0B (287)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_PMS_OBD_DiagReq__XQc0B (288)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_NWM_PMS_PT_UserData__XQc0B (289)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_NWM_PMS_Hybird_UserData_RMXr12 (290)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_BMS_FastChgStopInfo_RMXr12 (291)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_SrcPduID_Func_DiagReq_Pdur_XQc0B (292)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_TWVCommand_T34TDk_PMS_TWVCommand_T34TDk (0)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_MHGV_Status_T34TDk_MHGV_Status_T34TDk (1)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_FWFV_Status_T34TDk_FWFV_Status_T34TDk (2)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HEWP_T34TDk_PMS_HEWP_T34TDk (3)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HEWP_1_T34TDk_HEWP_1_T34TDk (4)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BHM_10nggJ_BHM_10nggJ (5)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BSOC_10nggJ_BSOC_10nggJ (6)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BEM_10nggJ_BEM_10nggJ (7)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BSD_10nggJ_BSD_10nggJ (8)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BST_10nggJ_BST_10nggJ (9)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMT_10nggJ_BMT_10nggJ (10)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMV_10nggJ_BMV_10nggJ (11)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BSM_10nggJ_BSM_10nggJ (12)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCS_10nggJ_BCS_10nggJ (13)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCL_10nggJ_BCL_10nggJ (14)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BRO_10nggJ_BRO_10nggJ (15)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCP_10nggJ_BCP_10nggJ (16)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BRM_10nggJ_BRM_10nggJ (17)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CHM_10nggJ_CHM_10nggJ (18)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CEM_10nggJ_CEM_10nggJ (19)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CSD_10nggJ_CSD_10nggJ (20)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CST_10nggJ_CST_10nggJ (21)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CCS_10nggJ_CCS_10nggJ (22)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CRO_10nggJ_CRO_10nggJ (23)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CML_10nggJ_CML_10nggJ (24)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CTS_10nggJ_CTS_10nggJ (25)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CRM_10nggJ_CRM_10nggJ (26)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_TrqSpd_RMXr12_IPU_TrqSpd_RMXr12 (27)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_Sts_RMXr12_IPU_Sts_RMXr12 (28)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_MotorAlarmInfo_RMXr12_IPU_MotorAlarmInfo_RMXr12 (29)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_MotorElePara_RMXr12_IPU_MotorElePara_RMXr12 (30)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_Temperature_RMXr12_IPU_Temperature_RMXr12 (31)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_IPU_IMMOCode_RMXr12_BMS_IPU_IMMOCode_RMXr12 (32)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_Status_RMXr12_HCM_Status_RMXr12 (33)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Status_RMXr12_BMSH_Status_RMXr12 (34)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_VoltCurrent_RMXr12_BMSH_VoltCurrent_RMXr12 (35)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_SOX_RMXr12_BMSH_SOX_RMXr12 (36)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_SOP_RMXr12_BMSH_SOP_RMXr12 (37)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_CellVoltMaxMin_RMXr12_BMSH_CellVoltMaxMin_RMXr12 (38)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_CCM_Req_RMXr12_BMSH_CCM_Req_RMXr12 (39)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_CellVolt_RMXr12_BMSH_TBOX_CellVolt_RMXr12 (40)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_CellTemp_RMXr12_BMSH_TBOX_CellTemp_RMXr12 (41)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_PackCode_RMXr12_BMSH_PackCode_RMXr12 (42)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_StsChgInfo_RMXr12_BMSH_StsChgInfo_RMXr12 (43)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Fault2_RMXr12_BMSH_TBOX_Fault2_RMXr12 (44)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Temp_RMXr12_BMSH_Temp_RMXr12 (45)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Fault_RMXr12_BMSH_Fault_RMXr12 (46)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Fault_RMXr12_BMSH_TBOX_Fault_RMXr12 (47)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_BatCfg_RMXr12_BMSH_BatCfg_RMXr12 (48)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Info1_RMXr12_BMSH_TBOX_Info1_RMXr12 (49)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Info2_RMXr12_BMSH_TBOX_Info2_RMXr12 (50)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Info3_RMXr12_BMSH_TBOX_Info3_RMXr12 (51)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_OdometerInfo_RMXr12_BMSH_OdometerInfo_RMXr12 (52)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_UseInfo_RMXr12_BMSH_UseInfo_RMXr12 (53)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_ChgEnergy_RMXr12_BMSH_ChgEnergy_RMXr12 (54)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_PwrOut_RMXr12_BMSH_PwrOut_RMXr12 (55)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_RecoveryEngInfo_RMXr12_BMSH_RecoveryEngInfo_RMXr12 (56)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Dischg_ExChgEngInfo_RMXr12_BMSH_Dischg_ExChgEngInfo_RMXr12 (57)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Dischg_ExChgCapacityInfo_RMXr12_BMSH_Dischg_ExChgCapacityInfo_RMXr12 (58)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_RecoveryCapacityInfo_RMXr12_BMSH_RecoveryCapacityInfo_RMXr12 (59)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_OverseasChgInfo_RMXr12_BMS_OverseasChgInfo_RMXr12 (60)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_ACChgCtrlInfo_RMXr12_BMS_ACChgCtrlInfo_RMXr12 (61)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_Infor_RMXr12_BMS_Infor_RMXr12 (62)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_Infor2_RMXr12_BMS_Infor2_RMXr12 (63)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_CellVolt1_RMXr12_BMSH_TBOX_CellVolt1_RMXr12 (64)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_CellTemp1_RMXr12_BMSH_TBOX_CellTemp1_RMXr12 (65)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_PackCode1_RMXr12_BMSH_PackCode1_RMXr12 (66)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOXInfor_RMXr12_BMSH_TBOXInfor_RMXr12 (67)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Command_RMXr12_PMS_Command_RMXr12 (68)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Ctrl1_RMXr12_PMS_Ctrl1_RMXr12 (69)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_BMSH_Ctrl_RMXr12_PMS_BMSH_Ctrl_RMXr12 (70)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_SwapAuth_RMXr12_PMS_SwapAuth_RMXr12 (71)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_EPS_SystemSts_RMXr12_PMS_EPS_SystemSts_RMXr12 (72)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_DCDC_Ctrl_RMXr12_PMS_DCDC_Ctrl_RMXr12 (73)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Ctrl_RMXr12_PMS_Ctrl_RMXr12 (74)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_ModeControl_RMXr12_PMS_ModeControl_RMXr12 (75)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_StsEpt_RMXr12_PMS_StsEpt_RMXr12 (76)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_StsSwap_RMXr12_PMS_StsSwap_RMXr12 (77)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_VehicleInfo_RMXr12_PMS_VehicleInfo_RMXr12 (78)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor1_RMXr12_PMS_HardInfor1_RMXr12 (79)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor2_RMXr12_PMS_HardInfor2_RMXr12 (80)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor5_RMXr12_PMS_HardInfor5_RMXr12 (81)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor6_RMXr12_PMS_HardInfor6_RMXr12 (82)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_IPK_STS_RMXr12_PMS_IPK_STS_RMXr12 (83)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_PEPSAuth_RMXr12_PMS_PEPSAuth_RMXr12 (84)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_BMSH_Info_RMXr12_PMS_BMSH_Info_RMXr12 (85)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_PEPS_Information_RMXr12_PMS_PEPS_Information_RMXr12 (86)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_BMSH_sts_RMXr12_PMS_BMSH_sts_RMXr12 (87)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_EDCPCtr_RMXr12_PMS_EDCPCtr_RMXr12 (88)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Temp_Ctrl_RMXr12_PMS_Temp_Ctrl_RMXr12 (89)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_VIN_RMXr12_PMS_VIN_RMXr12 (90)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_RemCon_RMXr12_TBOX_RemCon_RMXr12 (91)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EGSM_Status_RMXr12_EGSM_Status__XQc0B (92)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EGSM_Status_RMXr12_EGSM_Status_fVs55R (93)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EGSM_Status_RMXr12_EGSM_Status_RMXr12 (94)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_LV_Info_RMXr12_DCDC_LV_Info_XQc0B (95)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_LV_Info_RMXr12_DCDC_LV_Info_RMXr12 (96)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_HV_Info_RMXr12_DCDC_HV_Info_RMXr12 (97)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_HV_Info_RMXr12_DCDC_HV_Info_XQc0B (98)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_FaultInfo_RMXr12_DCDC_FaultInfo_RMXr12 (99)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_FaultInfo_RMXr12_DCDC_FaultInfo_XQc0B (100)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Sts_RMXr12_OBC_Sts_RMXr12 (101)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Sts_RMXr12_OBC_Sts_XQc0B (102)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Curr_RMXr12_OBC_Curr_RMXr12 (103)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Curr_RMXr12_OBC_Curr__XQc0B (104)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Failmode_RMXr12_OBC_Failmode_RMXr12 (105)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Failmode_RMXr12_OBC_Failmode__XQc0B (106)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Status2_RMXr12_OBC_Status2_RMXr12 (107)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_Status2_RMXr12_OBC_Status2__XQc0B (108)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_RFR_SwapBatCode_RMXr12_RFR_SwapBatCode_RMXr12 (109)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Station_Status_RMXr12_Station_Status_RMXr12 (110)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_RFR_Seed_RMXr12_RFR_Seed_RMXr12 (111)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_RFR_Info_RMXr12_RFR_Info_RMXr12 (112)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EGSM_DiagResp_RMXr12_EGSM_DiagResp__XQc0B (113)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_DiagResp_RMXr12_DCDC_DiagResp__XQc0B (114)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_DiagResp_RMXr12_OBC_DiagResp_RMXr12 (115)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_RFR_DiagResp_RMXr12_RFR_DiagResp__XQc0B (116)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq25Tx_GtPS3U_Xcp_Daq25Tx_GtPS3U (117)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq24Tx_GtPS3U_Xcp_Daq24Tx_GtPS3U (118)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq23Tx_GtPS3U_Xcp_Daq23Tx_GtPS3U (119)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq22Tx_GtPS3U_Xcp_Daq22Tx_GtPS3U (120)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq21Tx_GtPS3U_Xcp_Daq21Tx_GtPS3U (121)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq20Tx_GtPS3U_Xcp_Daq20Tx_GtPS3U (122)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq11Tx_GtPS3U_Xcp_Daq11Tx_GtPS3U (123)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq10Tx_GtPS3U_Xcp_Daq10Tx_GtPS3U (124)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq9Tx_GtPS3U_Xcp_Daq9Tx_GtPS3U (125)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq8Tx_GtPS3U_Xcp_Daq8Tx_GtPS3U (126)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq7Tx_GtPS3U_Xcp_Daq7Tx_GtPS3U (127)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq6Tx_GtPS3U_Xcp_Daq6Tx_GtPS3U (128)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq19Tx_GtPS3U_Xcp_Daq19Tx_GtPS3U (129)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq18Tx_GtPS3U_Xcp_Daq18Tx_GtPS3U (130)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq17Tx_GtPS3U_Xcp_Daq17Tx_GtPS3U (131)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq16Tx_GtPS3U_Xcp_Daq16Tx_GtPS3U (132)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq15Tx_GtPS3U_Xcp_Daq15Tx_GtPS3U (133)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq14Tx_GtPS3U_Xcp_Daq14Tx_GtPS3U (134)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq13Tx_GtPS3U_Xcp_Daq13Tx_GtPS3U (135)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq12Tx_GtPS3U_Xcp_Daq12Tx_GtPS3U (136)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq5Tx_GtPS3U_Xcp_Daq5Tx_GtPS3U (137)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq4Tx_GtPS3U_Xcp_Daq4Tx_GtPS3U (138)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestOutput6_GtPS3U_TestOutput6_GtPS3U (139)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestOutput5_GtPS3U_TestOutput5_GtPS3U (140)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestOutput4_GtPS3U_TestOutput4_GtPS3U (141)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestOutput1_GtPS3U_TestOutput1_GtPS3U (142)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestOutput2_GtPS3U_TestOutput2_GtPS3U (143)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestOutput3_GtPS3U_TestOutput3_GtPS3U (144)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Dto_GtPS3U_Xcp_Dto_GtPS3U (145)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq3Tx_GtPS3U_Xcp_Daq3Tx_GtPS3U (146)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq2Tx_GtPS3U_Xcp_Daq2Tx_GtPS3U (147)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Daq1Tx_GtPS3U_Xcp_Daq1Tx_GtPS3U (148)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Xcp_Cro_GtPS3U_Xcp_Cro_GtPS3U (149)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TestInput_GtPS3U_TestInput_GtPS3U (150)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_RelaySampSwich_lGfZId_BMS_RelaySampSwich_lGfZId (151)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_RelaySampSwich_lGfZId_PMS_RelaySampSwich_lGfZId (152)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Func_DiagReq_lGfZId_Func_DiagReq_lGfZId (153)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_Status_lGfZId_HCM_Status_lGfZId (154)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_InsulateaValue_lGfZId_HCM_InsulateaValue_lGfZId (155)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_MainRelayValue_lGfZId_HCM_MainRelayValue_lGfZId (156)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_OtherRelayValue_lGfZId_HCM_OtherRelayValue_lGfZId (157)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_Other2RelayValue_lGfZId_HCM_Other2RelayValue_lGfZId (158)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_Version_Info_lGfZId_HCM_Version_Info_lGfZId (159)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_DiagResp_lGfZId_HCM_DiagResp__XQc0B (160)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_CSControl2_fVs55R_PMS_CSControl2_fVs55R (161)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Ctrl_fVs55R_PMS_Ctrl_fVs55R (162)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_ModeControl_fVs55R_PMS_ModeControl_fVs55R (163)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_EngControl_fVs55R_PMS_EngControl_fVs55R (164)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_CSControl1_fVs55R_PMS_CSControl1_fVs55R (165)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_StsEpt_fVs55R_PMS_StsEpt_fVs55R (166)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_General_fVs55R_BMSH_General_fVs55R (167)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_BMSH_Ctrl_fVs55R_PMS_BMSH_Ctrl_fVs55R (168)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Ctrl1_fVs55R_PMS_Ctrl1_fVs55R (169)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_TrqSpd_fVs55R_IPU_TrqSpd_fVs55R (170)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_ACU_ChimeTelltaleReq_fVs55R_ACU_ChimeTelltaleReq_fVs55R (171)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_YRS1_fVs55R_YRS1_fVs55R (172)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_YRS2_fVs55R_YRS2_fVs55R (173)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_SAS_Status_fVs55R_SAS_Status_RMXr12 (174)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_Status_fVs55R_EHB_Status_RMXr12 (175)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_Status_fVs55R_EHB_Status_fVs55R (176)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_VLC_TorqueRequest_fVs55R_EHB_VLC_TorqueRequest_fVs55R (177)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_DA_MESSAGE_fVs55R_EHB_DA_MESSAGE_fVs55R (178)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_FrontWheelSpeedsKPH_fVs55R_EHB_FrontWheelSpeedsKPH_fVs55R (179)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_FrontWheelSpeedsKPH_fVs55R_EHB_FrontWheelSpeedsKPH_RMXr12 (180)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_RearWheelSpeedsKPH_fVs55R_EHB_RearWheelSpeedsKPH_fVs55R (181)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_RearWheelSpeedsKPH_fVs55R_EHB_RearWheelSpeedsKPH_RMXr12 (182)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_WheelSpeedsRC_fVs55R_EHB_WheelSpeedsRC_fVs55R (183)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_DriverRemind_fVs55R_EHB_DriverRemind_fVs55R (184)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_Regen_fVs55R_EHB_Regen_fVs55R (185)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_PTTorqueRequest_fVs55R_EHB_PTTorqueRequest_fVs55R (186)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EHB_ISARequest_fVs55R_EHB_ISARequest_fVs55R (187)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPK_Infor_fVs55R_IPK_Infor_fVs55R (188)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PDC_Status_Info_fVs55R_PDC_Status_Info_fVs55R (189)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Command__XQc0B_PMS_Command__XQc0B (190)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_VehicleInfo__XQc0B_PMS_VehicleInfo__XQc0B (191)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_CSControl2__XQc0B_PMS_CSControl2__XQc0B (192)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_DCDC_Ctrl__XQc0B_PMS_DCDC_Ctrl__XQc0B (193)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Ctrl__XQc0B_PMS_Ctrl__XQc0B (194)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_ModeControl__XQc0B_PMS_ModeControl__XQc0B (195)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_StsSwap__XQc0B_PMS_StsSwap__XQc0B (196)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_EngControl__XQc0B_PMS_EngControl__XQc0B (197)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_CSControl1__XQc0B_PMS_CSControl1__XQc0B (198)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_InforCAN__XQc0B_PMS_InforCAN__XQc0B (199)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_IPK_Status__XQc0B_PMS_IPK_Status__XQc0B (200)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_MMI_SwitchFb__XQc0B_PMS_MMI_SwitchFb__XQc0B (201)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Ctrl1__XQc0B_PMS_Ctrl1__XQc0B (202)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Temp_Ctrl__XQc0B_PMS_Temp_Ctrl__XQc0B (203)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Temp_Status__XQc0B_PMS_Temp_Status__XQc0B (204)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_Auth__XQc0B_PMS_Auth__XQc0B (205)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_LockVehInfor__XQc0B_PMS_LockVehInfor__XQc0B (206)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_TotalOdometer1__XQc0B_PMS_TotalOdometer1__XQc0B (207)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_StsEpt__XQc0B_PMS_StsEpt__XQc0B (208)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_ErrCode__XQc0B_PMS_ErrCode__XQc0B (209)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_CVW__XQc0B_PMS_CVW__XQc0B (210)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_instruct__XQc0B_PMS_instruct__XQc0B (211)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_TBOX_Fault__XQc0B_PMS_TBOX_Fault__XQc0B (212)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_TBOX_Fault1__XQc0B_PMS_TBOX_Fault1__XQc0B (213)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_VIN__XQc0B_PMS_VIN__XQc0B (214)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_VerInfo__XQc0B_PMS_VerInfo__XQc0B (215)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HEWP__XQc0B_PMS_HEWP__XQc0B (216)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HEWP_1__XQc0B_HEWP_1__XQc0B (217)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_TrqSpd__XQc0B_IPU_TrqSpd__XQc0B (218)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_Temperature__XQc0B_IPU_Temperature__XQc0B (219)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_Warning__XQc0B_IPU_Warning__XQc0B (220)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPU_MotorAlarmInfo__XQc0B_IPU_MotorAlarmInfo__XQc0B (221)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_Status__XQc0B_HCM_Status__XQc0B (222)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_General__XQc0B_BMSH_General__XQc0B (223)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_VoltCurr__XQc0B_BMSH_VoltCurr__XQc0B (224)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Battery_Performance__XQc0B_BMSH_Battery_Performance__XQc0B (225)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Battery_chgstate__XQc0B_BMSH_Battery_chgstate__XQc0B (226)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_CellTempLimitValue__XQc0B_BMSH_CellTempLimitValue__XQc0B (227)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_OBC_Control__XQc0B_BMSH_OBC_Control__XQc0B (228)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_PackCode__XQc0B_BMSH_PackCode__XQc0B (229)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_CellVoltData__XQc0B_BMS_CellVoltData__XQc0B (230)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_FaultToGovernmentBackendDa__XQc0B_BMSH_FaultToGovernmentBackendDa__XQc0B (231)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_sts__XQc0B_BMSH_sts__XQc0B (232)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_CellTempData__XQc0B_BMS_CellTempData__XQc0B (233)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_EnergyStatisticsOnce__XQc0B_BMSH_EnergyStatisticsOnce__XQc0B (234)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_Min_MAX_CellVolt__XQc0B_BMS_Min_MAX_CellVolt__XQc0B (235)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Temp__XQc0B_BMSH_Temp__XQc0B (236)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Fault__XQc0B_BMSH_Fault__XQc0B (237)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Fault__XQc0B_BMSH_TBOX_Fault__XQc0B (238)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Status__XQc0B_BMSH_Status__XQc0B (239)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_Infor2__XQc0B_BMS_Infor2__XQc0B (240)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_SOP__XQc0B_BMSH_SOP__XQc0B (241)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_VoltCurrent__XQc0B_BMSH_VoltCurrent__XQc0B (242)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_StsChgInfo__XQc0B_BMSH_StsChgInfo__XQc0B (243)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_ACChgCtrlInfo__XQc0B_BMS_ACChgCtrlInfo__XQc0B (244)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_CCM_Req__XQc0B_BMSH_CCM_Req__XQc0B (245)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Info1__XQc0B_BMSH_TBOX_Info1__XQc0B (246)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_UseInfo__XQc0B_BMSH_UseInfo__XQc0B (247)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_Dischg_ExChgEngInfo__XQc0B_BMSH_Dischg_ExChgEngInfo__XQc0B (248)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_RecoveryEngInfo__XQc0B_BMSH_RecoveryEngInfo__XQc0B (249)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_CellVolt1__XQc0B_BMSH_TBOX_CellVolt1__XQc0B (250)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_CellTemp1__XQc0B_BMSH_TBOX_CellTemp1__XQc0B (251)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_PackCode1__XQc0B_BMSH_PackCode1__XQc0B (252)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOXInfor__XQc0B_BMSH_TBOXInfor__XQc0B (253)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMSH_TBOX_Info3__XQc0B_BMSH_TBOX_Info3__XQc0B (254)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_PEPSAuth__XQc0B_PMS_PEPSAuth__XQc0B (255)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_EDCPCtr__XQc0B_PMS_EDCPCtr__XQc0B (256)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EDCP_Status__XQc0B_EDCP_Status__XQc0B (257)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HBCP_Status__XQc0B_HBCP_Status__XQc0B (258)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor1__XQc0B_PMS_HardInfor1__XQc0B (259)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor2__XQc0B_PMS_HardInfor2__XQc0B (260)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor5__XQc0B_PMS_HardInfor5__XQc0B (261)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_HardInfor6__XQc0B_PMS_HardInfor6__XQc0B (262)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_BMSH_Ctrl__XQc0B_PMS_BMSH_Ctrl__XQc0B (263)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_TWVCommand__XQc0B_PMS_TWVCommand__XQc0B (264)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_MHGV_Status__XQc0B_MHGV_Status__XQc0B (265)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_DiagResp__XQc0B_PMS_DiagResp__XQc0B (266)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_OBD_DiagResp__XQc0B_PMS_OBD_DiagResp__XQc0B (267)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PEPS_Message_Sts__XQc0B_PEPS_Message_Sts__XQc0B (268)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PEPS_Message_Sts__XQc0B_PEPS_Message_Sts_RMXr12 (269)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPK_DateTime_Info__XQc0B_IPK_DateTime_Info__XQc0B (270)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPK_DateTime_Info__XQc0B_IPK_DateTime_Info_RMXr12 (271)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPK_TotalOdometer__XQc0B_IPK_TotalOdometer__XQc0B (272)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_IPK_TotalOdometer__XQc0B_IPK_TotalOdometer_RMXr12 (273)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_MMI_SOCSet__XQc0B_MMI_SOCSet__XQc0B (274)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_MMI_HVSM_Command__XQc0B_MMI_HVSM_Command__XQc0B (275)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BBM_StsFB__XQc0B_BBM_StsFB__XQc0B (276)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_AC_Status_Info__XQc0B_AC_Status_Info__XQc0B (277)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_AC_Status_Info__XQc0B_AC_Status_Info_RMXr12 (278)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_AC_Status_SE_ACCM__XQc0B_AC_Status_SE_ACCM__XQc0B (279)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_AC_MMI_Status__XQc0B_AC_MMI_Status__XQc0B (280)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_AC_Status_Info1__XQc0B_AC_Status_Info1__XQc0B (281)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_AC_Status_Info1__XQc0B_AC_Status_Info1_RMXr12 (282)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_CSM_SwitchSts__XQc0B_CSM_SwitchSts__XQc0B (283)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PEPS_IMMOCode__XQc0B_PEPS_IMMOCode__XQc0B (284)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PEPS_KeyReminder__XQc0B_PEPS_KeyReminder__XQc0B (285)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_ACCinfor__XQc0B_BCM_ACCinfor__XQc0B (286)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_StateUpdate__XQc0B_BCM_StateUpdate__XQc0B (287)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_StateUpdate__XQc0B_BCM_StateUpdate_RMXr12 (288)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_LDoorWindowState__XQc0B_BCM_LDoorWindowState_RMXr12 (289)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_LDoorWindowState__XQc0B_BCM_LDoorWindowState_XQc0B (290)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_RDoorWindowState__XQc0B_BCM_RDoorWindowState_RMXr12 (291)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_RDoorWindowState__XQc0B_BCM_RDoorWindowState_XQc0B (292)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BCM_SunroofState__XQc0B_BCM_SunroofState__XQc0B (293)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_instruct__XQc0B_TBOX_instruct__XQc0B (294)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_instruct__XQc0B_TBOX_instruct_RMXr12 (295)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_instruct1__XQc0B_TBOX_instruct1__XQc0B (296)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_DateTime_Info__XQc0B_TBOX_DateTime_Info__XQc0B (297)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_DateTime_Info__XQc0B_TBOX_DateTime_Info_RMXr12 (298)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_ChgLimit_Command__XQc0B_TBOX_ChgLimit_Command__XQc0B (299)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_RemCon__XQc0B_TBOX_RemCon__XQc0B (300)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_LockVehCtrl__XQc0B_TBOX_LockVehCtrl__XQc0B (301)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_TBOX_VCULockResp__XQc0B_TBOX_VCULockResp__XQc0B (302)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_DiagReq__XQc0B_PMS_DiagReq__XQc0B (303)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_DCDC_DiagReq__XQc0B_DCDC_DiagReq__RMXr12 (304)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_OBC_DiagReq__XQc0B_OBC_DiagReq_RMXr12 (305)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_EGSM_DiagReq__XQc0B_EGSM_DiagReq_RMXr12 (306)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_RFR_DiagReq__XQc0B_RFR_DiagReq__XQc0B (307)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_HCM_DiagReq__XQc0B_HCM_DiagReq__IGfZId (308)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Func_DiagReq__XQc0B_Func_DiagReq__XQc0B (309)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_PMS_OBD_DiagReq__XQc0B_PMS_OBD_DiagReq__XQc0B (310)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_NWM_PMS_PT_UserData__XQc0B_NWM_PMS_PT_UserData__XQc0B (311)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_NWM_PMS_Hybird_UserData_RMXr12_NWM_PMS_Hybird_UserData_RMXr12 (312)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_NWM_PMS_Hybird_UserData_RMXr12_PduRDestPdu0 (313)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_BMS_FastChgStopInfo_RMXr12_BMS_FastChgStopInfo_RMXr12 (314)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Func_DiagReq_Pdur_XQc0B_Func_DiagReq_RMXr12 (315)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */
#define PDUR_DstPduID_Func_DiagReq_Pdur_XQc0B_Func_DiagReq_lGfZId (316)  /* PRQA S 0779, 0779 */ /* NSCA_QAC_PduR_Rule1.3, NSCA_QAC_Common_Rule5.2 */

#if (STD_ON == PDUR_SUPPORT_MULTICORE)
#define PDUR_PARTITION_SIZE (0U)
#define PDUR_APPLICATION_SIZE (18U)
#endif /* #if (STD_ON == PDUR_SUPPORT_MULTICORE) */

#define PDUR_SUPPORT_DIAG                               (STD_OFF)

/* PolySpace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_PduR_2.5" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint16 PduRMultiCastType;
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* #ifndef PDUR_CFG_H_ */

