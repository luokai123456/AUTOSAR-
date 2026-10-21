/*
********************************************************************************
*                                                                                                                                         
* File name: ComM_Cfg.h                                                                                                  
*                                                                                                                                         
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.                                                
*                                                                                                                                         
********************************************************************************
*                                                                                                                                        
* History                                                                                                                             
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : TanLixiang/2018.07.14
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : TanLixiang/2019.05.05
* Change: Modify
* Cause: Modify file structure.
********************************************************************************
* Version: 3.0
* Author/Date : jiafeng/2020.07.02
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date : jiafeng/2020.07.02
* Change: Add macro COMM_DCM_MODE_INDICATION.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : jiafeng/2020.09.01
* Change: Add include Rte_ComM_Type.h, delete include Rte_Type.h for compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: TianL/2024.8.5
* Change: Modify copyright.
* Cause: Update
********************************************************************************
*/
#ifndef COMM_CFG_H_
#define COMM_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Rte_ComM_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define COMM_ECUGROUPCLASSIFICATION                                         (3U)
#define COMM_GLOBALNVMBLOCKDESCRIPTOR                                       (0U)
#define COMM_PNCPREPARESLEEPTIMER                                           (0U)
#define COMM_TMINFULLCOMMODEDURATION                                        (5U)
#define COMM_BUSNM_EXIST_FULL_VARIANT                                       (STD_ON)
#define COMM_BUSNM_EXSIT_ENABLED                                            (STD_ON)
#define COMM_BUSTYPE_CAN_ENABLED                                            (STD_ON)
#define COMM_BUSTYPE_ETH_ENABLED                                            (STD_OFF)
#define COMM_BUSTYPE_FR_ENABLED                                             (STD_OFF)
#define COMM_BUSTYPE_LIN_ENABLED                                            (STD_ON)
#define COMM_DCM_MODE_INDICATION                                            (STD_ON)
#define COMM_DCM_REQUEST_ENABLED                                            (STD_ON)
#define COMM_DEVERRORDETECT                                                 (STD_ON)
#define COMM_DIRECTUSERMAPPING                                              (STD_OFF)
#define COMM_MODELIMITATION                                                 (STD_ON)
#define COMM_NMPASSIVEMODEENABLED                                           (STD_OFF)
#define COMM_PNCACTIVECOORD                                                 (STD_OFF)
#define COMM_PNCGATEWAYENABLED                                              (STD_OFF)
#define COMM_PNCSUPPORT                                                     (STD_OFF)
#define COMM_RESETAFTERFORCINGNOCOMM                                        (STD_OFF)
#define COMM_SYNCHRONOUSWAKEUP                                              (STD_OFF)
#define COMM_VERSIONINFOAPI                                                 (STD_ON)
#define COMM_WAKEUPINHIBITIONENABLED                                        (STD_ON)
#define COMM_PNCPASSIVEGWSUPPORT                                            (STD_OFF)
#define COMM_BSWMENABLED                                                    (STD_ON)

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
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* COMM_CFG_H_ */

