/*
********************************************************************************
*
* File name: CanIf_Lcfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date : WangCong/2019.10.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: YanCL/2024.7.15
* Change: 1.Add Memmap segment definition.
*         2.Update copyright information.
* Cause: Update
********************************************************************************
*/
#ifndef CANIF_LCFG_H_
#define CANIF_LCFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANIF_NEUSAR_CANDRIVER    FALSE
#include "Can.h"


#define CANIF_RXPDU_NUM                        (88U)

#define CANIF_TXPDU_NUM                        (240U)

#define XCP_CONF_XCP_RXPDU                     (0xFFFFU)

#define CANTP_CONF_CANTP_RX_FCNPDU             (79U)

#define CANTP_CONF_CANTP_RX_NPDU               (85U)

#define CANNM_CONF_CANNM_RXPDU_MODE_CAN1NM     (11U)

#define XCP_CONF_XCP_TXPDU                     (0xFFFFU)

#define CANTP_CONF_CANTP_TX_FCNPDU             (233U)

#define CANNM_CONF_CANNM_TXPDU                 (94U)

#define CANIF_TRCVCFG_NUM                      (0U)


#define CANIF_CHANNEL_ATOM_CAN_MATRIX_DC_V2_0_20250922_ATOM_10NGGJ_INDEX (0U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_CHANNEL_PMS_EV_CAN_20260427_RMXR12_INDEX                  (1U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_CHANNEL_XCP_AND_TEST_CAN_GTPS3U_INDEX                     (2U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_CHANNEL_N72_HCM__MATRIX_V1_1_LGFZID_INDEX                 (3U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_CHANNEL_N72__PMS_C_CAN_20260425_FVS55R_INDEX              (4U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_CHANNEL_N72__PMS_PT_CANFD_20260425__XQC0B_INDEX           (5U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */


#define CANIF_TX_PDU_CFG_BHM_10NGGJ_INDEX                       (0U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BSOC_10NGGJ_INDEX                      (1U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TPDT_10NGGJ_INDEX                      (2U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TPCM_10NGGJ_INDEX                      (3U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BEM_10NGGJ_INDEX                       (4U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BSD_10NGGJ_INDEX                       (5U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BST_10NGGJ_INDEX                       (6U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMT_10NGGJ_INDEX                       (7U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMV_10NGGJ_INDEX                       (8U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BSM_10NGGJ_INDEX                       (9U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BCS_10NGGJ_INDEX                       (10U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BCL_10NGGJ_INDEX                       (11U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BRO_10NGGJ_INDEX                       (12U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BCP_10NGGJ_INDEX                       (13U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BRM_10NGGJ_INDEX                       (14U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_TRQSPD_RMXR12_INDEX                (15U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_STS_RMXR12_INDEX                   (16U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_MOTORALARMINFO_RMXR12_INDEX        (17U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_MOTORELEPARA_RMXR12_INDEX          (18U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_TEMPERATURE_RMXR12_INDEX           (19U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_IPU_IMMOCODE_RMXR12_INDEX          (20U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_HCM_STATUS_RMXR12_INDEX                (21U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_STATUS_RMXR12_INDEX               (22U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_VOLTCURRENT_RMXR12_INDEX          (23U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_SOX_RMXR12_INDEX                  (24U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_SOP_RMXR12_INDEX                  (25U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_CELLVOLTMAXMIN_RMXR12_INDEX       (26U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_CCM_REQ_RMXR12_INDEX              (27U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_CELLVOLT_RMXR12_INDEX        (28U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_CELLTEMP_RMXR12_INDEX        (29U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_PACKCODE_RMXR12_INDEX             (30U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_STSCHGINFO_RMXR12_INDEX           (31U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_FAULT2_RMXR12_INDEX          (32U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TEMP_RMXR12_INDEX                 (33U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_FAULT_RMXR12_INDEX                (34U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_FAULT_RMXR12_INDEX           (35U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_BATCFG_RMXR12_INDEX               (36U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_INFO1_RMXR12_INDEX           (37U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_INFO2_RMXR12_INDEX           (38U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_INFO3_RMXR12_INDEX           (39U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_ODOMETERINFO_RMXR12_INDEX         (40U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_USEINFO_RMXR12_INDEX              (41U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_CHGENERGY_RMXR12_INDEX            (42U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_PWROUT_RMXR12_INDEX               (43U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_RECOVERYENGINFO_RMXR12_INDEX      (44U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_DISCHG_EXCHGENGINFO_RMXR12_INDEX  (45U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_DISCHG_EXCHGCAPACITYINFO_RMXR12_INDEX (46U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_RECOVERYCAPACITYINFO_RMXR12_INDEX (47U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_OVERSEASCHGINFO_RMXR12_INDEX       (48U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_ACCHGCTRLINFO_RMXR12_INDEX         (49U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_INFOR_RMXR12_INDEX                 (50U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_INFOR2_RMXR12_INDEX                (51U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_CELLVOLT1_RMXR12_INDEX       (52U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_CELLTEMP1_RMXR12_INDEX       (53U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_PACKCODE1_RMXR12_INDEX            (54U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOXINFOR_RMXR12_INDEX            (55U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_COMMAND_RMXR12_INDEX               (56U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CTRL1_RMXR12_INDEX                 (57U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_BMSH_CTRL_RMXR12_INDEX             (58U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_SAS_STATUS_RMXR12_INDEX                (59U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_SWAPAUTH_RMXR12_INDEX              (60U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EHB_FRONTWHEELSPEEDSKPH_RMXR12_INDEX   (61U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EHB_REARWHEELSPEEDSKPH_RMXR12_INDEX    (62U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EHB_STATUS_RMXR12_INDEX                (63U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_EPS_SYSTEMSTS_RMXR12_INDEX         (64U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_DCDC_CTRL_RMXR12_INDEX             (65U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CTRL_RMXR12_INDEX                  (66U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_MODECONTROL_RMXR12_INDEX           (67U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_STSEPT_RMXR12_INDEX                (68U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_STSSWAP_RMXR12_INDEX               (69U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_VEHICLEINFO_RMXR12_INDEX           (70U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PEPS_MESSAGE_STS_RMXR12_INDEX          (71U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR1_RMXR12_INDEX            (72U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR2_RMXR12_INDEX            (73U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR5_RMXR12_INDEX            (74U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR6_RMXR12_INDEX            (75U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_IPK_STS_RMXR12_INDEX               (76U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_PEPSAUTH_RMXR12_INDEX              (77U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BCM_STATEUPDATE_RMXR12_INDEX           (78U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BCM_LDOORWINDOWSTATE_RMXR12_INDEX      (79U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BCM_RDOORWINDOWSTATE_RMXR12_INDEX      (80U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_AC_STATUS_INFO_RMXR12_INDEX            (81U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_AC_STATUS_INFO1_RMXR12_INDEX           (82U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_BMSH_INFO_RMXR12_INDEX             (83U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_PEPS_INFORMATION_RMXR12_INDEX      (84U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_BMSH_STS_RMXR12_INDEX              (85U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_EDCPCTR_RMXR12_INDEX               (86U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TEMP_CTRL_RMXR12_INDEX             (87U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_VIN_RMXR12_INDEX                   (88U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TBOX_INSTRUCT_RMXR12_INDEX             (89U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TBOX_DATETIME_INFO_RMXR12_INDEX        (90U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TBOX_REMCON_RMXR12_INDEX               (91U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPK_DATETIME_INFO_RMXR12_INDEX         (92U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPK_TOTALODOMETER_RMXR12_INDEX         (93U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_NWM_PMS_HYBIRD_RMXR12_INDEX            (94U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EGSM_DIAGREQ_RMXR12_INDEX              (95U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_DCDC_DIAGREQ_RMXR12_INDEX              (96U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_OBC_DIAGREQ_RMXR12_INDEX               (97U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_RFR_DIAGREQ_RMXR12_INDEX               (98U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_FUNC_DIAGREQ_RMXR12_INDEX              (99U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_FASTCHGSTOPINFO_RMXR12_INDEX       (100U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ25TX_GTPS3U_INDEX               (101U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ24TX_GTPS3U_INDEX               (102U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ23TX_GTPS3U_INDEX               (103U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ22TX_GTPS3U_INDEX               (104U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ21TX_GTPS3U_INDEX               (105U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ20TX_GTPS3U_INDEX               (106U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ11TX_GTPS3U_INDEX               (107U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ10TX_GTPS3U_INDEX               (108U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ9TX_GTPS3U_INDEX                (109U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ8TX_GTPS3U_INDEX                (110U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ7TX_GTPS3U_INDEX                (111U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ6TX_GTPS3U_INDEX                (112U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ19TX_GTPS3U_INDEX               (113U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ18TX_GTPS3U_INDEX               (114U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ17TX_GTPS3U_INDEX               (115U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ16TX_GTPS3U_INDEX               (116U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ15TX_GTPS3U_INDEX               (117U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ14TX_GTPS3U_INDEX               (118U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ13TX_GTPS3U_INDEX               (119U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ12TX_GTPS3U_INDEX               (120U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ5TX_GTPS3U_INDEX                (121U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ4TX_GTPS3U_INDEX                (122U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TESTOUTPUT6_GTPS3U_INDEX               (123U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TESTOUTPUT5_GTPS3U_INDEX               (124U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TESTOUTPUT4_GTPS3U_INDEX               (125U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TESTOUTPUT1_GTPS3U_INDEX               (126U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TESTOUTPUT2_GTPS3U_INDEX               (127U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_TESTOUTPUT3_GTPS3U_INDEX               (128U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DTO_GTPS3U_INDEX                   (129U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ3TX_GTPS3U_INDEX                (130U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ2TX_GTPS3U_INDEX                (131U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_XCP_DAQ1TX_GTPS3U_INDEX                (132U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_RELAYSAMPSWICH_LGFZID_INDEX        (133U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_RELAYSAMPSWICH_LGFZID_INDEX        (134U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_HCM_DIAGREQ_LGFZID_INDEX               (135U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_FUNC_DIAGREQ_LGFZID_INDEX              (136U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CSCONTROL2_FVS55R_INDEX            (137U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CTRL_FVS55R_INDEX                  (138U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_MODECONTROL_FVS55R_INDEX           (139U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_ENGCONTROL_FVS55R_INDEX            (140U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CSCONTROL1_FVS55R_INDEX            (141U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_STSEPT_FVS55R_INDEX                (142U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EGSM_STATUS_FVS55R_INDEX               (143U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_GENERAL_FVS55R_INDEX              (144U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_BMSH_CTRL_FVS55R_INDEX             (145U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CTRL1_FVS55R_INDEX                 (146U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_TRQSPD_FVS55R_INDEX                (147U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_COMMAND__XQC0B_INDEX               (148U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_VEHICLEINFO__XQC0B_INDEX           (149U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CSCONTROL2__XQC0B_INDEX            (150U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_DCDC_CTRL__XQC0B_INDEX             (151U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CTRL__XQC0B_INDEX                  (152U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_MODECONTROL__XQC0B_INDEX           (153U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_STSSWAP__XQC0B_INDEX               (154U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_ENGCONTROL__XQC0B_INDEX            (155U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CSCONTROL1__XQC0B_INDEX            (156U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_INFORCAN__XQC0B_INDEX              (157U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_IPK_STATUS__XQC0B_INDEX            (158U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_MMI_SWITCHFB__XQC0B_INDEX          (159U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CTRL1__XQC0B_INDEX                 (160U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TEMP_CTRL__XQC0B_INDEX             (161U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TEMP_STATUS__XQC0B_INDEX           (162U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_AUTH__XQC0B_INDEX                  (163U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_LOCKVEHINFOR__XQC0B_INDEX          (164U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TOTALODOMETER1__XQC0B_INDEX        (165U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_STSEPT__XQC0B_INDEX                (166U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_ERRCODE__XQC0B_INDEX               (167U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_CVW__XQC0B_INDEX                   (168U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_INSTRUCT__XQC0B_INDEX              (169U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TBOX_FAULT__XQC0B_INDEX            (170U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TBOX_FAULT1__XQC0B_INDEX           (171U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_VIN__XQC0B_INDEX                   (172U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_VERINFO__XQC0B_INDEX               (173U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HEWP__XQC0B_INDEX                  (174U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_HEWP_1__XQC0B_INDEX                    (175U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_NWM_PMS_PT__XQC0B_INDEX                (176U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_TRQSPD__XQC0B_INDEX                (177U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_TEMPERATURE__XQC0B_INDEX           (178U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_WARNING__XQC0B_INDEX               (179U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_IPU_MOTORALARMINFO__XQC0B_INDEX        (180U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_HCM_STATUS__XQC0B_INDEX                (181U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_OBC_STS__XQC0B_INDEX                   (182U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_OBC_CURR__XQC0B_INDEX                  (183U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_OBC_FAILMODE__XQC0B_INDEX              (184U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_OBC_STATUS2__XQC0B_INDEX               (185U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_DCDC_LV_INFO__XQC0B_INDEX              (186U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_DCDC_FAULTINFO__XQC0B_INDEX            (187U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_DCDC_HV_INFO__XQC0B_INDEX              (188U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_GENERAL__XQC0B_INDEX              (189U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_VOLTCURR__XQC0B_INDEX             (190U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_BATTERY_PERFORMANCE__XQC0B_INDEX  (191U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_BATTERY_CHGSTATE__XQC0B_INDEX     (192U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_CELLTEMPLIMITVALUE__XQC0B_INDEX   (193U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_OBC_CONTROL__XQC0B_INDEX          (194U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_PACKCODE__XQC0B_INDEX             (195U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_CELLVOLTDATA__XQC0B_INDEX          (196U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_FAULTTOGOVERNMENTBACKENDDA__XQC0B_INDEX (197U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_STS__XQC0B_INDEX                  (198U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_CELLTEMPDATA__XQC0B_INDEX          (199U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_ENERGYSTATISTICSONCE__XQC0B_INDEX (200U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_MIN_MAX_CELLVOLT__XQC0B_INDEX      (201U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TEMP__XQC0B_INDEX                 (202U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_FAULT__XQC0B_INDEX                (203U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_FAULT__XQC0B_INDEX           (204U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_STATUS__XQC0B_INDEX               (205U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_INFOR2__XQC0B_INDEX                (206U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_SOP__XQC0B_INDEX                  (207U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_VOLTCURRENT__XQC0B_INDEX          (208U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_STSCHGINFO__XQC0B_INDEX           (209U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMS_ACCHGCTRLINFO__XQC0B_INDEX         (210U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_CCM_REQ__XQC0B_INDEX              (211U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_INFO1__XQC0B_INDEX           (212U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_USEINFO__XQC0B_INDEX              (213U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_DISCHG_EXCHGENGINFO__XQC0B_INDEX  (214U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_RECOVERYENGINFO__XQC0B_INDEX      (215U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_CELLVOLT1__XQC0B_INDEX       (216U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_CELLTEMP1__XQC0B_INDEX       (217U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_PACKCODE1__XQC0B_INDEX            (218U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOXINFOR__XQC0B_INDEX            (219U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_BMSH_TBOX_INFO3__XQC0B_INDEX           (220U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_PEPSAUTH__XQC0B_INDEX              (221U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EGSM_STATUS__XQC0B_INDEX               (222U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_EDCPCTR__XQC0B_INDEX               (223U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EDCP_STATUS__XQC0B_INDEX               (224U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_HBCP_STATUS__XQC0B_INDEX               (225U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR1__XQC0B_INDEX            (226U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR2__XQC0B_INDEX            (227U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR5__XQC0B_INDEX            (228U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_HARDINFOR6__XQC0B_INDEX            (229U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_BMSH_CTRL__XQC0B_INDEX             (230U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_TWVCOMMAND__XQC0B_INDEX            (231U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_MHGV_STATUS__XQC0B_INDEX               (232U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_DIAGRESP__XQC0B_INDEX              (233U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_DCDC_DIAGRESP__XQC0B_INDEX             (234U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_OBC_DIAGRESP__XQC0B_INDEX              (235U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_EGSM_DIAGRESP__XQC0B_INDEX             (236U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_RFR_DIAGRESP__XQC0B_INDEX              (237U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_HCM_DIAGRESP__XQC0B_INDEX              (238U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_TX_PDU_CFG_PMS_OBD_DIAGRESP__XQC0B_INDEX          (239U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */


#define CANIF_RX_PDU_CFG_CHM_10NGGJ_INDEX                       (0U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CEM_10NGGJ_INDEX                       (1U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CSD_10NGGJ_INDEX                       (2U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CST_10NGGJ_INDEX                       (3U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CCS_10NGGJ_INDEX                       (4U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CRO_10NGGJ_INDEX                       (5U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CML_10NGGJ_INDEX                       (6U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CTS_10NGGJ_INDEX                       (7U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CRM_10NGGJ_INDEX                       (8U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TPCM_TP_10NGGJ_INDEX                   (9U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EGSM_STATUS_RMXR12_INDEX               (10U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_NWM_EGSM_RMXR12_INDEX                  (11U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_DCDC_LV_INFO_RMXR12_INDEX              (12U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_DCDC_HV_INFO_RMXR12_INDEX              (13U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_DCDC_FAULTINFO_RMXR12_INDEX            (14U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_OBC_STS_RMXR12_INDEX                   (15U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_OBC_CURR_RMXR12_INDEX                  (16U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_OBC_FAILMODE_RMXR12_INDEX              (17U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_OBC_STATUS2_RMXR12_INDEX               (18U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_NWM_OBC_RMXR12_INDEX                   (19U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_RFR_SWAPBATCODE_RMXR12_INDEX           (20U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_STATION_STATUS_RMXR12_INDEX            (21U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_RFR_SEED_RMXR12_INDEX                  (22U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_RFR_INFO_RMXR12_INDEX                  (23U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EGSM_DIAGRESP_RMXR12_INDEX             (24U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_DCDC_DIAGRESP_RMXR12_INDEX             (25U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_OBC_DIAGRESP_RMXR12_INDEX              (26U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_RFR_DIAGRESP_RMXR12_INDEX              (27U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_XCP_CRO_GTPS3U_INDEX                   (28U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TESTINPUT_GTPS3U_INDEX                 (29U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_STATUS_LGFZID_INDEX                (30U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_INSULATEAVALUE_LGFZID_INDEX        (31U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_MAINRELAYVALUE_LGFZID_INDEX        (32U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_OTHERRELAYVALUE_LGFZID_INDEX       (33U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_OTHER2RELAYVALUE_LGFZID_INDEX      (34U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_VERSION_INFO_LGFZID_INDEX          (35U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_DIAGRESP_LGFZID_INDEX              (36U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_ACU_CHIMETELLTALEREQ_FVS55R_INDEX      (37U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_YRS1_FVS55R_INDEX                      (38U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_YRS2_FVS55R_INDEX                      (39U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_SAS_STATUS_FVS55R_INDEX                (40U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_STATUS_FVS55R_INDEX                (41U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_VLC_TORQUEREQUEST_FVS55R_INDEX     (42U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_DA_MESSAGE_FVS55R_INDEX            (43U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_FRONTWHEELSPEEDSKPH_FVS55R_INDEX   (44U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_REARWHEELSPEEDSKPH_FVS55R_INDEX    (45U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_WHEELSPEEDSRC_FVS55R_INDEX         (46U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_DRIVERREMIND_FVS55R_INDEX          (47U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_REGEN_FVS55R_INDEX                 (48U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_PTTORQUEREQUEST_FVS55R_INDEX       (49U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EHB_ISAREQUEST_FVS55R_INDEX            (50U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_IPK_INFOR_FVS55R_INDEX                 (51U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_PDC_STATUS_INFO_FVS55R_INDEX           (52U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_PEPS_MESSAGE_STS__XQC0B_INDEX          (53U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_IPK_DATETIME_INFO__XQC0B_INDEX         (54U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_IPK_TOTALODOMETER__XQC0B_INDEX         (55U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_MMI_SOCSET__XQC0B_INDEX                (56U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_MMI_HVSM_COMMAND__XQC0B_INDEX          (57U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_BBM_STSFB__XQC0B_INDEX                 (58U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_AC_STATUS_INFO__XQC0B_INDEX            (59U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_AC_STATUS_SE_ACCM__XQC0B_INDEX         (60U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_AC_MMI_STATUS__XQC0B_INDEX             (61U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_AC_STATUS_INFO1__XQC0B_INDEX           (62U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_CSM_SWITCHSTS__XQC0B_INDEX             (63U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_PEPS_IMMOCODE__XQC0B_INDEX             (64U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_PEPS_KEYREMINDER__XQC0B_INDEX          (65U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_BCM_ACCINFOR__XQC0B_INDEX              (66U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_BCM_STATEUPDATE__XQC0B_INDEX           (67U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_BCM_LDOORWINDOWSTATE__XQC0B_INDEX      (68U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_BCM_RDOORWINDOWSTATE__XQC0B_INDEX      (69U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_BCM_SUNROOFSTATE__XQC0B_INDEX          (70U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_INSTRUCT__XQC0B_INDEX             (71U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_INSTRUCT1__XQC0B_INDEX            (72U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_DATETIME_INFO__XQC0B_INDEX        (73U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_CHGLIMIT_COMMAND__XQC0B_INDEX     (74U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_REMCON__XQC0B_INDEX               (75U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_LOCKVEHCTRL__XQC0B_INDEX          (76U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_TBOX_VCULOCKRESP__XQC0B_INDEX          (77U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_NWM_GW_PT__XQC0B_INDEX                 (78U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_PMS_DIAGREQ__XQC0B_INDEX               (79U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_DCDC_DIAGREQ__XQC0B_INDEX              (80U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_OBC_DIAGREQ__XQC0B_INDEX               (81U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_EGSM_DIAGREQ__XQC0B_INDEX              (82U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_RFR_DIAGREQ__XQC0B_INDEX               (83U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_HCM_DIAGREQ__XQC0B_INDEX               (84U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_FUNC_DIAGREQ__XQC0B_INDEX              (85U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_PMS_OBD_DIAGREQ__XQC0B_INDEX           (86U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANIF_RX_PDU_CFG_FUNC_DIAGREQ_PDUR_XQC0B_INDEX          (87U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */

#define CANIF_CONTROLLER_NUM         (6U)

#define CANIF_INITHOHCFG_NUM_CAN     (327U)


#define CANIF_CAN_CONTROLLER_NUM     (6U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
#define CANIF_START_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

#if (CANIF_NEUSAR_CANDRIVER == TRUE) 
extern CONST(Can_MsgCycles_st, CANIF_CONFIG_DATA) CanIf_RxPduInfo[CANIF_RXPDU_NUM];
extern CONST(Can_MsgCycles_st, CANIF_CONFIG_DATA) CanIf_TxPduInfo[CANIF_TXPDU_NUM];
#endif

extern CONST(CanIf_TrcvMapType, CANIF_CONFIG_DATA) CanIf_TrcvMap[CANIF_TRCVCFG_NUM+CANIF_VALUE_ONE];
extern CONST(CanIf_CanObjectMapType, CANIF_CONFIG_DATA) CanIf_Can_ObjectMap[CANIF_INITHOHCFG_NUM_CAN];
extern CONST(uint8, CANIF_CONFIG_DATA) CanIf_ControllerMap[CANIF_CONTROLLER_NUM + CANIF_VALUE_ONE];

#if (CANIF_PUB_MULTIPLE_DRV_SUP == STD_ON)
extern CONST(CanIf_CanMultipeDrvInfoType, CANIF_CONFIG_DATA) CanIf_CanMultipeDrvInfo[CANIF_CONTROLLER_NUM];
#endif 

extern CONST(CanIf_RxPduCfgType, CANIF_CONFIG_DATA) CanIf_RxPduCfg[CANIF_RXPDU_NUM + 1U];
extern CONST(CanIf_TxPduCfgType, CANIF_CONFIG_DATA) CanIf_TxPduCfg[CANIF_TXPDU_NUM + 1U];

#if (CANIF_PRIVATE_SWFILTER_TYPE == CANIF_SWFILTER_INDEX) 
extern CONSTP2CONST(uint16, CANIF_CONFIG_DATA, CANIF_APPL_CONST) CanIf_CanIdMapRxPduPtrList[CANIF_CONTROLLER_NUM + 1U];
extern CONSTP2CONST(uint16, CANIF_CONFIG_DATA, CANIF_APPL_CONST) CanIf_CanIdMapRxPduPtrList_CANFD[CANIF_CONTROLLER_NUM + 1U];
#endif 

extern CONST(uint8, CANIF_CONFIG_DATA) CanIf_CanControllerIdMap[CANIF_CAN_CONTROLLER_NUM + CANIF_VALUE_ONE];

#define CANIF_STOP_SEC_CONFIG_DATA
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"

extern VAR(Can_IdType, CANIF_VAR_INIT) CanIf_TxCanId[CANIF_TXPDU_NUM + 1U];

#define CANIF_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanIf_MemMap.h"


/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* CANIF_LCFG_H_ */


