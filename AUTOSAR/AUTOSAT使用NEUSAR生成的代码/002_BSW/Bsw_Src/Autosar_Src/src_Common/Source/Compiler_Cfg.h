/*
********************************************************************************
*
*  File name: Compiler_Cfg.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : WangJP/2019.03.22
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date : WangJP/2020.06.17
* Change: Define each module memory and pointer class.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date : WangJP/2021.12.24
* Change: 1. Add FlexRayStack memory and pointer class.
*         2. Add SomeIp memory and pointer class.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date : ZhangXL/2024.03.12
* Change: 1. Add MemAcc memory and pointer class.
*         2. Remove duplicate macro definition in OSEKNM and NeuLib.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date : ZhangXL/2024.04.03
* Change: Remove duplicate memory and pointer class of the KeyM and SecOC.
* Cause: Bugfix
********************************************************************************
*/
#ifndef COMPILTER_CFG_H_
#define COMPILTER_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* BswM MemClass and ptrClass. */
#define BSWM_CODE
#define BSWM_CALL_OUT_CODE
#define BSWM_CODE_FAST
#define BSWM_CODE_SLOW
#define BSWM_CONST
#define BSWM_CALIB
#define BSWM_CONFIG_DATA
#define BSWM_APPL_DATA
#define BSWM_APPL_CONST
#define BSWM_VAR_NO_INIT
#define BSWM_VAR_CLEARED
#define BSWM_VAR_POWER_ON_CLEARED
#define BSWM_VAR_INIT
#define BSWM_VAR_POWER_ON_INIT

/* CanIf MemClass and ptrClass. */
#define CANIF_CODE
#define CANIF_CALL_OUT_CODE
#define CANIF_CODE_FAST
#define CANIF_CODE_SLOW
#define CANIF_CONST
#define CANIF_CALIB
#define CANIF_CONFIG_DATA
#define CANIF_APPL_DATA
#define CANIF_APPL_CONST
#define CANIF_VAR_NO_INIT
#define CANIF_VAR_CLEARED
#define CANIF_VAR_POWER_ON_CLEARED
#define CANIF_VAR_INIT
#define CANIF_VAR_POWER_ON_INIT

/* CanNm MemClass and ptrClass. */
#define CANNM_CODE
#define CANNM_CALL_OUT_CODE
#define CANNM_CODE_FAST
#define CANNM_CODE_SLOW
#define CANNM_CONST
#define CANNM_CALIB
#define CANNM_CONFIG_DATA
#define CANNM_APPL_DATA
#define CANNM_APPL_CONST
#define CANNM_VAR_NO_INIT
#define CANNM_VAR_CLEARED
#define CANNM_VAR_POWER_ON_CLEARED
#define CANNM_VAR_INIT
#define CANNM_VAR_POWER_ON_INIT

/* CanSM MemClass and ptrClass. */
#define CANSM_CODE
#define CANSM_CALL_OUT_CODE
#define CANSM_CODE_FAST
#define CANSM_CODE_SLOW
#define CANSM_CONST
#define CANSM_CALIB
#define CANSM_CONFIG_DATA
#define CANSM_APPL_DATA
#define CANSM_APPL_CONST
#define CANSM_VAR_NO_INIT
#define CANSM_VAR_CLEARED
#define CANSM_VAR_POWER_ON_CLEARED
#define CANSM_VAR_INIT
#define CANSM_VAR_POWER_ON_INIT

/* CanTp MemClass and ptrClass. */
#define CANTP_CODE
#define CANTP_CALL_OUT_CODE
#define CANTP_CODE_FAST
#define CANTP_CODE_SLOW
#define CANTP_CONST
#define CANTP_CALIB
#define CANTP_CONFIG_DATA
#define CANTP_APPL_DATA
#define CANTP_APPL_CONST
#define CANTP_VAR_NO_INIT
#define CANTP_VAR_CLEARED
#define CANTP_VAR_POWER_ON_CLEARED
#define CANTP_VAR_INIT
#define CANTP_VAR_POWER_ON_INIT

/* CanTrcv MemClass and ptrClass. */
#define CANTRCV_CODE
#define CANTRCV_CALL_OUT_CODE
#define CANTRCV_CODE_FAST
#define CANTRCV_CODE_SLOW
#define CANTRCV_CONST
#define CANTRCV_CALIB
#define CANTRCV_CONFIG_DATA
#define CANTRCV_APPL_DATA
#define CANTRCV_APPL_CONST
#define CANTRCV_VAR_NO_INIT
#define CANTRCV_VAR_CLEARED
#define CANTRCV_VAR_POWER_ON_CLEARED
#define CANTRCV_VAR_INIT
#define CANTRCV_VAR_POWER_ON_INIT

/* CanTSyn MemClass and ptrClass. */
#define CANTSYN_CODE
#define CANTSYN_CALL_OUT_CODE
#define CANTSYN_CODE_FAST
#define CANTSYN_CODE_SLOW
#define CANTSYN_CONST
#define CANTSYN_CALIB
#define CANTSYN_CONFIG_DATA
#define CANTSYN_APPL_DATA
#define CANTSYN_APPL_CONST
#define CANTSYN_VAR_NO_INIT
#define CANTSYN_VAR_CLEARED
#define CANTSYN_VAR_POWER_ON_CLEARED
#define CANTSYN_VAR_INIT
#define CANTSYN_VAR_POWER_ON_INIT

/* Com MemClass and ptrClass. */
#define COM_CODE
#define COM_CALL_OUT_CODE
#define COM_CODE_FAST
#define COM_CODE_SLOW
#define COM_CONST
#define COM_CALIB
#define COM_CONFIG_DATA
#define COM_APPL_DATA
#define COM_APPL_CONST
#define COM_VAR_NO_INIT
#define COM_VAR_CLEARED
#define COM_VAR_POWER_ON_CLEARED
#define COM_VAR_INIT
#define COM_VAR_POWER_ON_INIT
/* ComM MemClass and ptrClass. */
#define COMM_CODE
#define COMM_CALL_OUT_CODE
#define COMM_CODE_FAST
#define COMM_CODE_SLOW
#define COMM_CONST
#define COMM_CALIB
#define COMM_CONFIG_DATA
#define COMM_APPL_DATA
#define COMM_APPL_CONST
#define COMM_VAR_NO_INIT
#define COMM_VAR_CLEARED
#define COMM_VAR_POWER_ON_CLEARED
#define COMM_VAR_INIT
#define COMM_VAR_POWER_ON_INIT

/* ComXf MemClass and ptrClass. */
#define COMXF_CODE
#define COMXF_CALL_OUT_CODE
#define COMXF_CODE_FAST
#define COMXF_CODE_SLOW
#define COMXF_CONST
#define COMXF_CALIB
#define COMXF_CONFIG_DATA
#define COMXF_APPL_DATA
#define COMXF_APPL_CONST
#define COMXF_VAR_NO_INIT
#define COMXF_VAR_CLEARED
#define COMXF_VAR_POWER_ON_CLEARED
#define COMXF_VAR_INIT
#define COMXF_VAR_POWER_ON_INIT

/* Crc MemClass and ptrClass. */
#define CRC_CODE
#define CRC_CALL_OUT_CODE
#define CRC_CODE_FAST
#define CRC_CODE_SLOW
#define CRC_CONST
#define CRC_CALIB
#define CRC_CONFIG_DATA
#define CRC_APPL_DATA
#define CRC_APPL_CONST
#define CRC_VAR_NO_INIT
#define CRC_VAR_CLEARED
#define CRC_VAR_POWER_ON_CLEARED
#define CRC_VAR_INIT
#define CRC_VAR_POWER_ON_INIT

/* CryIf MemClass and ptrClass. */
#define CRYIF_CODE
#define CRYIF_CALL_OUT_CODE
#define CRYIF_CODE_FAST
#define CRYIF_CODE_SLOW
#define CRYIF_CONST
#define CRYIF_CALIB
#define CRYIF_CONFIG_DATA
#define CRYIF_APPL_DATA
#define CRYIF_APPL_CONST
#define CRYIF_VAR_NO_INIT
#define CRYIF_VAR_CLEARED
#define CRYIF_VAR_POWER_ON_CLEARED
#define CRYIF_VAR_INIT
#define CRYIF_VAR_POWER_ON_INIT

/* Csm MemClass and ptrClass. */
#define CSM_CODE
#define CSM_CALL_OUT_CODE
#define CSM_CODE_FAST
#define CSM_CODE_SLOW
#define CSM_CONST
#define CSM_CALIB
#define CSM_CONFIG_DATA
#define CSM_APPL_DATA
#define CSM_APPL_CONST
#define CSM_VAR_NO_INIT
#define CSM_VAR_CLEARED
#define CSM_VAR_POWER_ON_CLEARED
#define CSM_VAR_INIT
#define CSM_VAR_POWER_ON_INIT


/* Dcm MemClass and ptrClass. */
#define DCM_CODE
#define DCM_CALL_OUT_CODE
#define DCM_CODE_FAST
#define DCM_CODE_SLOW
#define DCM_CONST
#define DCM_CALIB
#define DCM_CONFIG_DATA
#define DCM_APPL_DATA
#define DCM_APPL_CONST
#define DCM_VAR_NO_INIT
#define DCM_VAR_CLEARED
#define DCM_VAR_POWER_ON_CLEARED
#define DCM_VAR_INIT
#define DCM_VAR_POWER_ON_INIT

/* Dem MemClass and ptrClass. */
#define DEM_CODE
#define DEM_CALL_OUT_CODE
#define DEM_CODE_FAST
#define DEM_CODE_SLOW
#define DEM_CONST
#define DEM_CALIB
#define DEM_CONFIG_DATA
#define DEM_APPL_DATA
#define DEM_APPL_CONST
#define DEM_VAR_NO_INIT
#define DEM_VAR_CLEARED
#define DEM_VAR_POWER_ON_CLEARED
#define DEM_VAR_INIT
#define DEM_VAR_POWER_ON_INIT

/* Det MemClass and ptrClass. */
#define DET_CODE
#define DET_CALL_OUT_CODE
#define DET_CODE_FAST
#define DET_CODE_SLOW
#define DET_CONST
#define DET_CALIB
#define DET_CONFIG_DATA
#define DET_APPL_DATA
#define DET_APPL_CONST
#define DET_VAR_NO_INIT
#define DET_VAR_CLEARED
#define DET_VAR_POWER_ON_CLEARED
#define DET_VAR_INIT
#define DET_VAR_POWER_ON_INIT

/* Dlt MemClass and ptrClass. */
#define DLT_CODE
#define DLT_CALL_OUT_CODE
#define DLT_CODE_FAST
#define DLT_CODE_SLOW
#define DLT_CONST
#define DLT_CALIB
#define DLT_CONFIG_DATA
#define DLT_APPL_DATA
#define DLT_APPL_CONST
#define DLT_VAR_NO_INIT
#define DLT_VAR_CLEARED
#define DLT_VAR_POWER_ON_CLEARED
#define DLT_VAR_INIT
#define DLT_VAR_POWER_ON_INIT

/* DoIp MemClass and ptrClass. */
#define DOIP_CODE
#define DOIP_CALL_OUT_CODE
#define DOIP_CODE_FAST
#define DOIP_CODE_SLOW
#define DOIP_CONST
#define DOIP_CALIB
#define DOIP_CONFIG_DATA
#define DOIP_APPL_DATA
#define DOIP_APPL_CONST
#define DOIP_VAR_NO_INIT
#define DOIP_VAR_CLEARED
#define DOIP_VAR_POWER_ON_CLEARED
#define DOIP_VAR_INIT
#define DOIP_VAR_POWER_ON_INIT

/* E2E MemClass and ptrClass. */
#define E2E_CODE
#define E2E_CALL_OUT_CODE
#define E2E_CODE_FAST
#define E2E_CODE_SLOW
#define E2E_CONST
#define E2E_CALIB
#define E2E_CONFIG_DATA
#define E2E_APPL_DATA
#define E2E_APPL_CONST
#define E2E_VAR_NO_INIT
#define E2E_VAR_CLEARED
#define E2E_VAR_POWER_ON_CLEARED
#define E2E_VAR_INIT
#define E2E_VAR_POWER_ON_INIT

/* E2EPW MemClass and ptrClass. */
#define E2EPW_CODE
#define E2EPW_CALL_OUT_CODE
#define E2EPW_CODE_FAST
#define E2EPW_CODE_SLOW
#define E2EPW_CONST
#define E2EPW_CALIB
#define E2EPW_CONFIG_DATA
#define E2EPW_APPL_DATA
#define E2EPW_APPL_CONST
#define E2EPW_VAR_NO_INIT
#define E2EPW_VAR_CLEARED
#define E2EPW_VAR_POWER_ON_CLEARED
#define E2EPW_VAR_INIT
#define E2EPW_VAR_POWER_ON_INIT

/* E2EXf MemClass and ptrClass. */
#define E2EXF_CODE
#define E2EXF_CALL_OUT_CODE
#define E2EXF_CODE_FAST
#define E2EXF_CODE_SLOW
#define E2EXF_CONST
#define E2EXF_CALIB
#define E2EXF_CONFIG_DATA
#define E2EXF_APPL_DATA
#define E2EXF_APPL_CONST
#define E2EXF_VAR_NO_INIT
#define E2EXF_VAR_CLEARED
#define E2EXF_VAR_POWER_ON_CLEARED
#define E2EXF_VAR_INIT
#define E2EXF_VAR_POWER_ON_INIT

/* Ea MemClass and ptrClass. */
#define EA_CODE
#define EA_CALL_OUT_CODE
#define EA_CODE_FAST
#define EA_CODE_SLOW
#define EA_CONST
#define EA_CALIB
#define EA_CONFIG_DATA
#define EA_APPL_DATA
#define EA_APPL_CONST
#define EA_VAR_NO_INIT
#define EA_VAR_CLEARED
#define EA_VAR_POWER_ON_CLEARED
#define EA_VAR_INIT
#define EA_VAR_POWER_ON_INIT

/* EcuM MemClass and ptrClass. */
#define ECUM_CODE
#define ECUM_CALL_OUT_CODE
#define ECUM_CODE_FAST
#define ECUM_CODE_SLOW
#define ECUM_CONST
#define ECUM_CALIB
#define ECUM_CONFIG_DATA
#define ECUM_APPL_DATA
#define ECUM_APPL_CONST
#define ECUM_VAR_NO_INIT
#define ECUM_VAR_CLEARED
#define ECUM_VAR_POWER_ON_CLEARED
#define ECUM_VAR_INIT
#define ECUM_VAR_POWER_ON_INIT

/* Eep MemClass and ptrClass. */
#define EEP_CODE
#define EEP_CALL_OUT_CODE
#define EEP_CODE_FAST
#define EEP_CODE_SLOW
#define EEP_CONST
#define EEP_CALIB
#define EEP_CONFIG_DATA
#define EEP_APPL_DATA
#define EEP_APPL_CONST
#define EEP_VAR_NO_INIT
#define EEP_VAR_CLEARED
#define EEP_VAR_POWER_ON_CLEARED
#define EEP_VAR_INIT
#define EEP_VAR_POWER_ON_INIT

/* EthIf MemClass and ptrClass. */
#define ETHIF_CODE
#define ETHIF_CALL_OUT_CODE
#define ETHIF_CODE_FAST
#define ETHIF_CODE_SLOW
#define ETHIF_CONST
#define ETHIF_CALIB
#define ETHIF_CONFIG_DATA
#define ETHIF_APPL_DATA
#define ETHIF_APPL_CONST
#define ETHIF_VAR_NO_INIT
#define ETHIF_VAR_CLEARED
#define ETHIF_VAR_POWER_ON_CLEARED
#define ETHIF_VAR_INIT
#define ETHIF_VAR_POWER_ON_INIT

/* EthSM MemClass and ptrClass. */
#define ETHSM_CODE
#define ETHSM_CALL_OUT_CODE
#define ETHSM_CODE_FAST
#define ETHSM_CODE_SLOW
#define ETHSM_CONST
#define ETHSM_CALIB
#define ETHSM_CONFIG_DATA
#define ETHSM_APPL_DATA
#define ETHSM_APPL_CONST
#define ETHSM_VAR_NO_INIT
#define ETHSM_VAR_CLEARED
#define ETHSM_VAR_POWER_ON_CLEARED
#define ETHSM_VAR_INIT
#define ETHSM_VAR_POWER_ON_INIT

/* EthSwt MemClass and ptrClass. */
#define ETHSWT_CODE
#define ETHSWT_CALL_OUT_CODE
#define ETHSWT_CODE_FAST
#define ETHSWT_CODE_SLOW
#define ETHSWT_CONST
#define ETHSWT_CALIB
#define ETHSWT_CONFIG_DATA
#define ETHSWT_APPL_DATA
#define ETHSWT_APPL_CONST
#define ETHSWT_VAR_NO_INIT
#define ETHSWT_VAR_CLEARED
#define ETHSWT_VAR_POWER_ON_CLEARED
#define ETHSWT_VAR_INIT
#define ETHSWT_VAR_POWER_ON_INIT

/* EthTrcv MemClass and ptrClass. */
#define ETHTRCV_CODE
#define ETHTRCV_CALL_OUT_CODE
#define ETHTRCV_CODE_FAST
#define ETHTRCV_CODE_SLOW
#define ETHTRCV_CONST
#define ETHTRCV_CALIB
#define ETHTRCV_CONFIG_DATA
#define ETHTRCV_APPL_DATA
#define ETHTRCV_APPL_CONST
#define ETHTRCV_VAR_NO_INIT
#define ETHTRCV_VAR_CLEARED
#define ETHTRCV_VAR_POWER_ON_CLEARED
#define ETHTRCV_VAR_INIT
#define ETHTRCV_VAR_POWER_ON_INIT

/* EthTSyn MemClass and ptrClass. */
#define ETHTSYN_CODE
#define ETHTSYN_CALL_OUT_CODE
#define ETHTSYN_CODE_FAST
#define ETHTSYN_CODE_SLOW
#define ETHTSYN_CONST
#define ETHTSYN_CALIB
#define ETHTSYN_CONFIG_DATA
#define ETHTSYN_APPL_DATA
#define ETHTSYN_APPL_CONST
#define ETHTSYN_VAR_NO_INIT
#define ETHTSYN_VAR_CLEARED
#define ETHTSYN_VAR_POWER_ON_CLEARED
#define ETHTSYN_VAR_INIT
#define ETHTSYN_VAR_POWER_ON_INIT

/* Fee MemClass and ptrClass. */
#define FEE_CODE
#define FEE_CALL_OUT_CODE
#define FEE_CODE_FAST
#define FEE_CODE_SLOW
#define FEE_CONST
#define FEE_CALIB
#define FEE_CONFIG_DATA
#define FEE_APPL_DATA
#define FEE_APPL_CONST
#define FEE_VAR_NO_INIT
#define FEE_VAR_CLEARED
#define FEE_VAR_POWER_ON_CLEARED
#define FEE_VAR_INIT
#define FEE_VAR_POWER_ON_INIT

/* FiM MemClass and ptrClass. */
#define FIM_CODE
#define FIM_CALL_OUT_CODE
#define FIM_CODE_FAST
#define FIM_CODE_SLOW
#define FIM_CONST
#define FIM_CALIB
#define FIM_CONFIG_DATA
#define FIM_APPL_DATA
#define FIM_APPL_CONST
#define FIM_VAR_NO_INIT
#define FIM_VAR_CLEARED
#define FIM_VAR_POWER_ON_CLEARED
#define FIM_VAR_INIT
#define FIM_VAR_POWER_ON_INIT

/* FrArTp MemClass and ptrClass. */
#define FRARTP_CODE
#define FRARTP_CALL_OUT_CODE
#define FRARTP_CODE_FAST
#define FRARTP_CODE_SLOW
#define FRARTP_CONST
#define FRARTP_CALIB
#define FRARTP_CONFIG_DATA
#define FRARTP_APPL_DATA
#define FRARTP_APPL_CONST
#define FRARTP_VAR_NO_INIT
#define FRARTP_VAR_CLEARED
#define FRARTP_VAR_POWER_ON_CLEARED
#define FRARTP_VAR_INIT
#define FRARTP_VAR_POWER_ON_INIT

/* FrIf MemClass and ptrClass. */
#define FRIF_CODE
#define FRIF_CALL_OUT_CODE
#define FRIF_CODE_FAST
#define FRIF_CODE_SLOW
#define FRIF_CONST
#define FRIF_CALIB
#define FRIF_CONFIG_DATA
#define FRIF_APPL_DATA
#define FRIF_APPL_CONST
#define FRIF_VAR_NO_INIT
#define FRIF_VAR_CLEARED
#define FRIF_VAR_POWER_ON_CLEARED
#define FRIF_VAR_INIT
#define FRIF_VAR_POWER_ON_INIT

/* FrNm MemClass and ptrClass. */
#define FRNM_CODE
#define FRNM_CALL_OUT_CODE
#define FRNM_CODE_FAST
#define FRNM_CODE_SLOW
#define FRNM_CONST
#define FRNM_CALIB
#define FRNM_CONFIG_DATA
#define FRNM_APPL_DATA
#define FRNM_APPL_CONST
#define FRNM_VAR_NO_INIT
#define FRNM_VAR_CLEARED
#define FRNM_VAR_POWER_ON_CLEARED
#define FRNM_VAR_INIT
#define FRNM_VAR_POWER_ON_INIT

/* FrSM MemClass and ptrClass. */
#define FRSM_CODE
#define FRSM_CALL_OUT_CODE
#define FRSM_CODE_FAST
#define FRSM_CODE_SLOW
#define FRSM_CONST
#define FRSM_CALIB
#define FRSM_CONFIG_DATA
#define FRSM_APPL_DATA
#define FRSM_APPL_CONST
#define FRSM_VAR_NO_INIT
#define FRSM_VAR_CLEARED
#define FRSM_VAR_POWER_ON_CLEARED
#define FRSM_VAR_INIT
#define FRSM_VAR_POWER_ON_INIT

/* FrTp MemClass and ptrClass. */
#define FRTP_CODE
#define FRTP_CALL_OUT_CODE
#define FRTP_CODE_FAST
#define FRTP_CODE_SLOW
#define FRTP_CONST
#define FRTP_CALIB
#define FRTP_CONFIG_DATA
#define FRTP_APPL_DATA
#define FRTP_APPL_CONST
#define FRTP_VAR_NO_INIT
#define FRTP_VAR_CLEARED
#define FRTP_VAR_POWER_ON_CLEARED
#define FRTP_VAR_INIT
#define FRTP_VAR_POWER_ON_INIT

/* FrTrcv MemClass and ptrClass. */
#define FRTRCV_CODE
#define FRTRCV_CALL_OUT_CODE
#define FRTRCV_CODE_FAST
#define FRTRCV_CODE_SLOW
#define FRTRCV_CONST
#define FRTRCV_CALIB
#define FRTRCV_CONFIG_DATA
#define FRTRCV_APPL_DATA
#define FRTRCV_APPL_CONST
#define FRTRCV_VAR_NO_INIT
#define FRTRCV_VAR_CLEARED
#define FRTRCV_VAR_POWER_ON_CLEARED
#define FRTRCV_VAR_INIT
#define FRTRCV_VAR_POWER_ON_INIT

/* FrTSyn MemClass and ptrClass. */
#define FRTSYN_CODE
#define FRTSYN_CALL_OUT_CODE
#define FRTSYN_CODE_FAST
#define FRTSYN_CODE_SLOW
#define FRTSYN_CONST
#define FRTSYN_CALIB
#define FRTSYN_CONFIG_DATA
#define FRTSYN_APPL_DATA
#define FRTSYN_APPL_CONST
#define FRTSYN_VAR_NO_INIT
#define FRTSYN_VAR_CLEARED
#define FRTSYN_VAR_POWER_ON_CLEARED
#define FRTSYN_VAR_INIT
#define FRTSYN_VAR_POWER_ON_INIT

/* IpduM MemClass and ptrClass. */
#define IPDUM_CODE
#define IPDUM_CALL_OUT_CODE
#define IPDUM_CODE_FAST
#define IPDUM_CODE_SLOW
#define IPDUM_CONST
#define IPDUM_CALIB
#define IPDUM_CONFIG_DATA
#define IPDUM_APPL_DATA
#define IPDUM_APPL_CONST
#define IPDUM_VAR_NO_INIT
#define IPDUM_VAR_CLEARED
#define IPDUM_VAR_POWER_ON_CLEARED
#define IPDUM_VAR_INIT
#define IPDUM_VAR_POWER_ON_INIT

/* J1939Dcm MemClass and ptrClass. */
#define J1939DCM_CODE
#define J1939DCM_CALL_OUT_CODE
#define J1939DCM_CODE_FAST
#define J1939DCM_CODE_SLOW
#define J1939DCM_CONST
#define J1939DCM_CALIB
#define J1939DCM_CONFIG_DATA
#define J1939DCM_APPL_DATA
#define J1939DCM_APPL_CONST
#define J1939DCM_VAR_NO_INIT
#define J1939DCM_VAR_CLEARED
#define J1939DCM_VAR_POWER_ON_CLEARED
#define J1939DCM_VAR_INIT
#define J1939DCM_VAR_POWER_ON_INIT

/* J1939Rm MemClass and ptrClass. */
#define J1939RM_CODE
#define J1939RM_CALL_OUT_CODE
#define J1939RM_CODE_FAST
#define J1939RM_CODE_SLOW
#define J1939RM_CONST
#define J1939RM_CALIB
#define J1939RM_CONFIG_DATA
#define J1939RM_APPL_DATA
#define J1939RM_APPL_CONST
#define J1939RM_VAR_NO_INIT
#define J1939RM_VAR_CLEARED
#define J1939RM_VAR_POWER_ON_CLEARED
#define J1939RM_VAR_INIT
#define J1939RM_VAR_POWER_ON_INIT

/* J1939Tp MemClass and ptrClass. */
#define J1939TP_CODE
#define J1939TP_CALL_OUT_CODE
#define J1939TP_CODE_FAST
#define J1939TP_CODE_SLOW
#define J1939TP_CONST
#define J1939TP_CALIB
#define J1939TP_CONFIG_DATA
#define J1939TP_APPL_DATA
#define J1939TP_APPL_CONST
#define J1939TP_VAR_NO_INIT
#define J1939TP_VAR_CLEARED
#define J1939TP_VAR_POWER_ON_CLEARED
#define J1939TP_VAR_INIT
#define J1939TP_VAR_POWER_ON_INIT

/* KeyM MemClass and ptrClass. */
#define KEYM_CODE
#define KEYM_CALL_OUT_CODE
#define KEYM_CODE_FAST
#define KEYM_CODE_SLOW
#define KEYM_CONST
#define KEYM_CALIB
#define KEYM_CONFIG_DATA
#define KEYM_APPL_DATA
#define KEYM_APPL_CONST
#define KEYM_VAR_NO_INIT
#define KEYM_VAR_CLEARED
#define KEYM_VAR_POWER_ON_CLEARED
#define KEYM_VAR_INIT
#define KEYM_VAR_POWER_ON_INIT

/* LdCom MemClass and ptrClass. */
#define LDCOM_CODE
#define LDCOM_CALL_OUT_CODE
#define LDCOM_CODE_FAST
#define LDCOM_CODE_SLOW
#define LDCOM_CONST
#define LDCOM_CALIB
#define LDCOM_CONFIG_DATA
#define LDCOM_APPL_DATA
#define LDCOM_APPL_CONST
#define LDCOM_VAR_NO_INIT
#define LDCOM_VAR_CLEARED
#define LDCOM_VAR_POWER_ON_CLEARED
#define LDCOM_VAR_INIT
#define LDCOM_VAR_POWER_ON_INIT

/* LinIf MemClass and ptrClass. */
#define LINIF_CODE
#define LINIF_CALL_OUT_CODE
#define LINIF_CODE_FAST
#define LINIF_CODE_SLOW
#define LINIF_CONST
#define LINIF_CALIB
#define LINIF_CONFIG_DATA
#define LINIF_APPL_DATA
#define LINIF_APPL_CONST
#define LINIF_VAR_NO_INIT
#define LINIF_VAR_CLEARED
#define LINIF_VAR_POWER_ON_CLEARED
#define LINIF_VAR_INIT
#define LINIF_VAR_POWER_ON_INIT

/* LinNm MemClass and ptrClass. */
#define LINNM_CODE
#define LINNM_CALL_OUT_CODE
#define LINNM_CODE_FAST
#define LINNM_CODE_SLOW
#define LINNM_CONST
#define LINNM_CALIB
#define LINNM_CONFIG_DATA
#define LINNM_APPL_DATA
#define LINNM_APPL_CONST
#define LINNM_VAR_NO_INIT
#define LINNM_VAR_CLEARED
#define LINNM_VAR_POWER_ON_CLEARED
#define LINNM_VAR_INIT
#define LINNM_VAR_POWER_ON_INIT

/* LinSM MemClass and ptrClass. */
#define LINSM_CODE
#define LINSM_CALL_OUT_CODE
#define LINSM_CODE_FAST
#define LINSM_CODE_SLOW
#define LINSM_CONST
#define LINSM_CALIB
#define LINSM_CONFIG_DATA
#define LINSM_APPL_DATA
#define LINSM_APPL_CONST
#define LINSM_VAR_NO_INIT
#define LINSM_VAR_CLEARED
#define LINSM_VAR_POWER_ON_CLEARED
#define LINSM_VAR_INIT
#define LINSM_VAR_POWER_ON_INIT

/* LinTrcv MemClass and ptrClass. */
#define LINTRCV_CODE
#define LINTRCV_CALL_OUT_CODE
#define LINTRCV_CODE_FAST
#define LINTRCV_CODE_SLOW
#define LINTRCV_CONST
#define LINTRCV_CALIB
#define LINTRCV_CONFIG_DATA
#define LINTRCV_APPL_DATA
#define LINTRCV_APPL_CONST
#define LINTRCV_VAR_NO_INIT
#define LINTRCV_VAR_CLEARED
#define LINTRCV_VAR_POWER_ON_CLEARED
#define LINTRCV_VAR_INIT
#define LINTRCV_VAR_POWER_ON_INIT

/* MemIf MemClass and ptrClass. */
#define MEMIF_CODE
#define MEMIF_CALL_OUT_CODE
#define MEMIF_CODE_FAST
#define MEMIF_CODE_SLOW
#define MEMIF_CONST
#define MEMIF_CALIB
#define MEMIF_CONFIG_DATA
#define MEMIF_APPL_DATA
#define MEMIF_APPL_CONST
#define MEMIF_VAR_NO_INIT
#define MEMIF_VAR_CLEARED
#define MEMIF_VAR_POWER_ON_CLEARED
#define MEMIF_VAR_INIT
#define MEMIF_VAR_POWER_ON_INIT

/* Nm MemClass and ptrClass. */
#define NM_CODE
#define NM_CALL_OUT_CODE
#define NM_CODE_FAST
#define NM_CODE_SLOW
#define NM_CONST
#define NM_CALIB
#define NM_CONFIG_DATA
#define NM_APPL_DATA
#define NM_APPL_CONST
#define NM_VAR_NO_INIT
#define NM_VAR_CLEARED
#define NM_VAR_POWER_ON_CLEARED
#define NM_VAR_INIT
#define NM_VAR_POWER_ON_INIT

/* NvM MemClass and ptrClass. */
#define NVM_CODE
#define NVM_CALL_OUT_CODE
#define NVM_CODE_FAST
#define NVM_CODE_SLOW
#define NVM_CONST
#define NVM_CALIB
#define NVM_CONFIG_DATA
#define NVM_APPL_DATA
#define NVM_APPL_CONST
#define NVM_VAR_NO_INIT
#define NVM_VAR_CLEARED
#define NVM_VAR_POWER_ON_CLEARED
#define NVM_VAR_INIT
#define NVM_VAR_POWER_ON_INIT

/* Os MemClass and ptrClass. */
#define OS_CODE
#define OS_CALL_OUT_CODE
#define OS_CODE_FAST
#define OS_CODE_SLOW
#define OS_CONST
#define OS_CALIB
#define OS_CONFIG_DATA
#define OS_APPL_DATA
#define OS_APPL_CONST
#define OS_VAR_NO_INIT
#define OS_VAR_CLEARED
#define OS_VAR_POWER_ON_CLEARED
#define OS_VAR_INIT
#define OS_VAR_POWER_ON_INIT

/* PduR MemClass and ptrClass. */
#define PDUR_CODE
#define PDUR_CALL_OUT_CODE
#define PDUR_CODE_FAST
#define PDUR_CODE_SLOW
#define PDUR_CONST
#define PDUR_CALIB
#define PDUR_CONFIG_DATA
#define PDUR_APPL_DATA
#define PDUR_APPL_CONST
#define PDUR_VAR_NO_INIT
#define PDUR_VAR_CLEARED
#define PDUR_VAR_POWER_ON_CLEARED
#define PDUR_VAR_INIT
#define PDUR_VAR_POWER_ON_INIT

/* Sd MemClass and ptrClass. */
#define SD_CODE
#define SD_CALL_OUT_CODE
#define SD_CODE_FAST
#define SD_CODE_SLOW
#define SD_CONST
#define SD_CALIB
#define SD_CONFIG_DATA
#define SD_APPL_DATA
#define SD_APPL_CONST
#define SD_VAR_NO_INIT
#define SD_VAR_CLEARED
#define SD_VAR_POWER_ON_CLEARED
#define SD_VAR_INIT
#define SD_VAR_POWER_ON_INIT

/* SecOC MemClass and ptrClass. */
#define SECOC_CODE
#define SECOC_CALL_OUT_CODE
#define SECOC_CODE_FAST
#define SECOC_CODE_SLOW
#define SECOC_CONST
#define SECOC_CALIB
#define SECOC_CONFIG_DATA
#define SECOC_APPL_DATA
#define SECOC_APPL_CONST
#define SECOC_VAR_NO_INIT
#define SECOC_VAR_CLEARED
#define SECOC_VAR_POWER_ON_CLEARED
#define SECOC_VAR_INIT
#define SECOC_VAR_POWER_ON_INIT

/* SoAd MemClass and ptrClass. */
#define SOAD_CODE
#define SOAD_CALL_OUT_CODE
#define SOAD_CODE_FAST
#define SOAD_CODE_SLOW
#define SOAD_CONST
#define SOAD_CALIB
#define SOAD_CONFIG_DATA
#define SOAD_APPL_DATA
#define SOAD_APPL_CONST
#define SOAD_VAR_NO_INIT
#define SOAD_VAR_CLEARED
#define SOAD_VAR_POWER_ON_CLEARED
#define SOAD_VAR_INIT
#define SOAD_VAR_POWER_ON_INIT

/* SomeIpTp MemClass and ptrClass. */
#define SOMEIPTP_CODE
#define SOMEIPTP_CALL_OUT_CODE
#define SOMEIPTP_CODE_FAST
#define SOMEIPTP_CODE_SLOW
#define SOMEIPTP_CONST
#define SOMEIPTP_CALIB
#define SOMEIPTP_CONFIG_DATA
#define SOMEIPTP_APPL_DATA
#define SOMEIPTP_APPL_CONST
#define SOMEIPTP_VAR_NO_INIT
#define SOMEIPTP_VAR_CLEARED
#define SOMEIPTP_VAR_POWER_ON_CLEARED
#define SOMEIPTP_VAR_INIT
#define SOMEIPTP_VAR_POWER_ON_INIT

/* SomeIpXf MemClass and ptrClass. */
#define SOMEIPXF_CODE
#define SOMEIPXF_CALL_OUT_CODE
#define SOMEIPXF_CODE_FAST
#define SOMEIPXF_CODE_SLOW
#define SOMEIPXF_CONST
#define SOMEIPXF_CALIB
#define SOMEIPXF_CONFIG_DATA
#define SOMEIPXF_APPL_DATA
#define SOMEIPXF_APPL_CONST
#define SOMEIPXF_VAR_NO_INIT
#define SOMEIPXF_VAR_CLEARED
#define SOMEIPXF_VAR_POWER_ON_CLEARED
#define SOMEIPXF_VAR_INIT
#define SOMEIPXF_VAR_POWER_ON_INIT

/* StbM MemClass and ptrClass. */
#define STBM_CODE
#define STBM_CALL_OUT_CODE
#define STBM_CODE_FAST
#define STBM_CODE_SLOW
#define STBM_CONST
#define STBM_CALIB
#define STBM_CONFIG_DATA
#define STBM_APPL_DATA
#define STBM_APPL_CONST
#define STBM_VAR_NO_INIT
#define STBM_VAR_CLEARED
#define STBM_VAR_POWER_ON_CLEARED
#define STBM_VAR_INIT
#define STBM_VAR_POWER_ON_INIT

/* TcpIp MemClass and ptrClass. */
#define TCPIP_CODE
#define TCPIP_CALL_OUT_CODE
#define TCPIP_CODE_FAST
#define TCPIP_CODE_SLOW
#define TCPIP_CONST
#define TCPIP_CALIB
#define TCPIP_CONFIG_DATA
#define TCPIP_APPL_DATA
#define TCPIP_APPL_CONST
#define TCPIP_VAR_NO_INIT
#define TCPIP_VAR_CLEARED
#define TCPIP_VAR_POWER_ON_CLEARED
#define TCPIP_VAR_INIT
#define TCPIP_VAR_POWER_ON_INIT

/* Tm MemClass and ptrClass. */
#define TM_CODE
#define TM_CALL_OUT_CODE
#define TM_CODE_FAST
#define TM_CODE_SLOW
#define TM_CONST
#define TM_CALIB
#define TM_CONFIG_DATA
#define TM_APPL_DATA
#define TM_APPL_CONST
#define TM_VAR_NO_INIT
#define TM_VAR_CLEARED
#define TM_VAR_POWER_ON_CLEARED
#define TM_VAR_INIT
#define TM_VAR_POWER_ON_INIT

/* UdpNm MemClass and ptrClass. */
#define UDPNM_CODE
#define UDPNM_CALL_OUT_CODE
#define UDPNM_CODE_FAST
#define UDPNM_CODE_SLOW
#define UDPNM_CONST
#define UDPNM_CALIB
#define UDPNM_CONFIG_DATA
#define UDPNM_APPL_DATA
#define UDPNM_APPL_CONST
#define UDPNM_VAR_NO_INIT
#define UDPNM_VAR_CLEARED
#define UDPNM_VAR_POWER_ON_CLEARED
#define UDPNM_VAR_INIT
#define UDPNM_VAR_POWER_ON_INIT

/* WdgIf MemClass and ptrClass. */
#define WDGIF_CODE
#define WDGIF_CALL_OUT_CODE
#define WDGIF_CODE_FAST
#define WDGIF_CODE_SLOW
#define WDGIF_CONST
#define WDGIF_CALIB
#define WDGIF_CONFIG_DATA
#define WDGIF_APPL_DATA
#define WDGIF_APPL_CONST
#define WDGIF_VAR_NO_INIT
#define WDGIF_VAR_CLEARED
#define WDGIF_VAR_POWER_ON_CLEARED
#define WDGIF_VAR_INIT
#define WDGIF_VAR_POWER_ON_INIT

/* WdgM MemClass and ptrClass. */
#define WDGM_CODE
#define WDGM_CALL_OUT_CODE
#define WDGM_CODE_FAST
#define WDGM_CODE_SLOW
#define WDGM_CONST
#define WDGM_CALIB
#define WDGM_CONFIG_DATA
#define WDGM_APPL_DATA
#define WDGM_APPL_CONST
#define WDGM_VAR_NO_INIT
#define WDGM_VAR_CLEARED
#define WDGM_VAR_POWER_ON_CLEARED
#define WDGM_VAR_INIT
#define WDGM_VAR_POWER_ON_INIT

/* Xcp MemClass and ptrClass. */
#define XCP_CODE
#define XCP_CALL_OUT_CODE
#define XCP_CODE_FAST
#define XCP_CODE_SLOW
#define XCP_CONST
#define XCP_CALIB
#define XCP_CONFIG_DATA
#define XCP_APPL_DATA
#define XCP_APPL_CONST
#define XCP_VAR_NO_INIT
#define XCP_VAR_CLEARED
#define XCP_VAR_POWER_ON_CLEARED
#define XCP_VAR_INIT
#define XCP_VAR_POWER_ON_INIT

/* OSEKNM MemClass and ptrClass. */
#define OSEKNM_CODE
#define OSEKNM_CALL_OUT_CODE
#define OSEKNM_CODE_FAST
#define OSEKNM_CODE_SLOW
#define OSEKNM_CONST
#define OSEKNM_CALIB
#define OSEKNM_CONFIG_DATA
#define OSEKNM_APPL_DATA
#define OSEKNM_APPL_CONST
#define OSEKNM_VAR_NO_INIT
#define OSEKNM_VAR_CLEARED
#define OSEKNM_VAR_POWER_ON_CLEARED
#define OSEKNM_VAR_INIT
#define OSEKNM_VAR_POWER_ON_INIT

/* NeuLib MemClass and ptrClass. */
#define NEULIB_CODE
#define NEULIB_CALL_OUT_CODE
#define NEULIB_CODE_FAST
#define NEULIB_CODE_SLOW
#define NEULIB_CONST
#define NEULIB_CALIB
#define NEULIB_CONFIG_DATA
#define NEULIB_APPL_DATA
#define NEULIB_APPL_CONST
#define NEULIB_VAR_NO_INIT
#define NEULIB_VAR_CLEARED
#define NEULIB_VAR_POWER_ON_CLEARED
#define NEULIB_VAR_INIT
#define NEULIB_VAR_POWER_ON_INIT

/* MemAcc MemClass and ptrClass. */
#define MEMACC_CODE
#define MEMACC_CALL_OUT_CODE
#define MEMACC_CODE_FAST
#define MEMACC_CODE_SLOW
#define MEMACC_CONST
#define MEMACC_CALIB
#define MEMACC_CONFIG_DATA
#define MEMACC_APPL_DATA
#define MEMACC_APPL_CONST
#define MEMACC_VAR_NO_INIT
#define MEMACC_VAR_CLEARED
#define MEMACC_VAR_POWER_ON_CLEARED
#define MEMACC_VAR_INIT
#define MEMACC_VAR_POWER_ON_INIT

/* Custmor MemClass and ptrClass. */
#define EEP_CODE_DATA 
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
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* COMPILTER_CFG_H_ */
