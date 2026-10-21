/*
********************************************************************************
*
* File name: Dcm_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Tanlx/20190513
* Change: Autosar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Liuziyang/2019.11.21
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.2
* Author/Date : SongQW/2020.12.22
* Change: Add macro "DCM_RESPPENDINGNUMBERLIMIT" to control the number of NRC78.
* Cause: Optimization.
********************************************************************************
*/
#ifndef DCM_CFG_H_
#define DCM_CFG_H_

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
//baoenfei OFF->ON
#define DCM_SERVICE_01_ENABLED (STD_ON)
#define DCM_SERVICE_02_ENABLED (STD_OFF)
#define DCM_SERVICE_03_ENABLED (STD_OFF)
#define DCM_SERVICE_04_ENABLED (STD_OFF)
#define DCM_SERVICE_05_ENABLED (STD_OFF)
#define DCM_SERVICE_06_ENABLED (STD_OFF)
#define DCM_SERVICE_07_ENABLED (STD_OFF)
//baoenfei OFF->ON
#define DCM_SERVICE_09_ENABLED (STD_ON)
#define DCM_SERVICE_0A_ENABLED (STD_OFF)
#define DCM_SERVICE_10_ENABLED (STD_ON)
#define DCM_SERVICE_11_ENABLED (STD_ON)
#define DCM_SERVICE_22_ENABLED (STD_ON)
#define DCM_SERVICE_2E_ENABLED (STD_ON)
#define DCM_SERVICE_27_ENABLED (STD_ON)
#define DCM_SERVICE_3E_ENABLED (STD_ON)
#define DCM_SERVICE_28_ENABLED (STD_ON)
#define DCM_SERVICE_85_ENABLED (STD_ON)
#define DCM_SERVICE_2F_ENABLED (STD_OFF)
#define DCM_SERVICE_14_ENABLED (STD_ON)
#define DCM_SERVICE_31_ENABLED (STD_ON)
#define DCM_SERVICE_19_ENABLED (STD_ON)
#define DCM_SERVICE_34_ENABLED (STD_OFF)
#define DCM_SERVICE_35_ENABLED (STD_OFF)
#define DCM_SERVICE_36_ENABLED (STD_OFF)
#define DCM_SERVICE_37_ENABLED (STD_OFF)
#define DCM_SERVICE_23_ENABLED (STD_OFF)
#define DCM_SERVICE_29_ENABLED (STD_OFF)
#define DCM_SERVICE_38_ENABLED (STD_OFF)
#define DCM_SERVICE_NONE_ENABLED (STD_OFF)
#define DCM_DEV_ERROR_DETECT (STD_ON)
#define DCM_REQUESTMANUFACTURERNOTIFICATION_ENABLED (STD_ON)
#define DCM_REQUESTSUPPLIERNOTIFICATION_ENABLED (STD_ON)
#define DCM_DSLTXBUFFERCLEAR_ENABLE (STD_OFF)
#define DCM_PDURTXCONFIRMATION_DISABLE (STD_OFF)
#define DCM_CLEARDTCMEMORYSELECTION (DCM_MEMORYSELECTION_DISABLE)
#define DCM_SERVICE_83_ENABLED (STD_OFF)
#define DCM_RESPPENDINGNUMBERLIMIT (STD_OFF)
#define DCM_SERVICE_2C_ENABLED (STD_OFF)
#define DCM_SERVICE_2A_ENABLED (STD_OFF)
#define DCM_SERVICE_86_ENABLED (STD_OFF)
#define DCM_SERVICE_3D_ENABLED (STD_OFF)
#define DCM_SERVICE_87_ENABLED (STD_OFF)
#define DCM_DEM_OBD_SUPPORT (STD_OFF)
#if ( (DCM_SERVICE_2C_ENABLED == STD_ON) || (DCM_SERVICE_2A_ENABLED == STD_ON) )
#define DCM_DSPDDDIDCHECKPERSOURCEDID (STD_OFF)
#endif
#define DCM_UDS_GENERAL_VERSION (DCM_ISO14229_2020)
#define DCM_MULTI_SERVICETABLE_ENABLE (STD_ON)
#define DCM_NVM_CLASS1_SUPPORT (STD_OFF)
#if ( DCM_SERVICE_27_ENABLED == STD_ON )
#define DCM_27_CONTINUEREQUESTSAMESEED (STD_ON)
#endif/* DCM_SERVICE_27_ENABLED == STD_ON */

#define DCM_COMM_SUPPORT (STD_ON)

#if ( (DCM_SERVICE_02_ENABLED == STD_ON) || (DCM_SERVICE_03_ENABLED == STD_ON) \
   || (DCM_SERVICE_04_ENABLED == STD_ON) || (DCM_SERVICE_07_ENABLED == STD_ON) \
   || (DCM_SERVICE_0A_ENABLED == STD_ON) || (DCM_SERVICE_14_ENABLED == STD_ON) \
   || (DCM_SERVICE_19_ENABLED == STD_ON) )
#define DCM_DEM_SUPPORT  (STD_ON)
#endif

#define DCM_CANTP_SUPPORT (STD_ON)

#if ( DCM_SERVICE_09_ENABLED == STD_ON )
#define DCM_09_NUMOFDATAITER                            (0x01U)
#endif

#define DCM_COMCONTROLBYBSWM (STD_OFF)

#if (DCM_SERVICE_86_ENABLED == STD_ON)

/* Service 0x86 needs a timer. */
#define DCM_86_INTERMESSAGETIME_ENABLED (STD_OFF)

#endif

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
#endif

#if ( STD_ON == DCM_SERVICE_31_ENABLED )
#define DCM_SUPPRESSBIT_31 (STD_OFF)
#endif
#define DCM_RETURNCONTROLTOECU_PENDING (STD_OFF)

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

#endif /* DCM_CFG_H_ */

