/*
********************************************************************************
*
* File name: CanTp_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Tanlx/2019.05.01
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Tanlx/2019.10.12
* Change: Modify MIRSA-C code.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date : Liuziyang/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 3.0
* Author/Date : Songqingwei/2020.05.15
* Change: Modify the coding specification.
* Cause: Optimize
********************************************************************************
* Version: 3.1
* Author/Date : YanCL/2024.7.3
* Change: Update copyright information.
* Cause: Update
********************************************************************************
*/
#ifndef CANTP_CFG_H_
#define CANTP_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/

#include "UDS_IF.h"//User UDS IF

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define CANTP_COMMUNICATION_USER_RULE_SUPPORT   (STD_OFF)    //UDS报文自定义发送规则是否支持，手动添加配置项
#define CANTP_CANFD_SUPPORT               (STD_ON)
#define CANTP_GENERAL_VERSION             (CANTP_ISO15765_2_2004)
#define CANTP_TX_CF_STMIN_TIMECORRECTION_ENABLE (STD_ON)
#define CANTP_STMIN_ZERO_CF_IN_TXCONFIRM  (STD_OFF)
#define CANTP_TRANSMIT_WITHOUTDATA        (STD_OFF)
#define CANTP_DEV_ERROR_DETECT            (STD_ON)
#define CANTP_ENABLE_CHANGE_PARAM         (STD_ON)
#define CANTP_ENABLE_READ_PARAM           (STD_ON)
#define CANTP_VERSION_INFO_API            (STD_ON)

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

#endif /* CANTP_CFG_H_ */

