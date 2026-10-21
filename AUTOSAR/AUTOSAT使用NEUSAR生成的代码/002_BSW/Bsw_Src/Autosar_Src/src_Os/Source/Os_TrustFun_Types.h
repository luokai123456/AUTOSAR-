/*
********************************************************************************
*
*  File name: Os_TrustFun_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: YaoXJ/2021.02.16
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.2.15
* Change: Modified for QAC.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_TRUSTFUN_TYPES_H_
#define OS_TRUSTFUN_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types_Cfg.h"
#include "Os_Types.h"
#include "Os_MemProtection_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Type of user provided trusted functions. */
typedef P2FUNC(void, OS_CODE, Os_TrustFunCbkType)
(
    TrustedFunctionIndexType funcId,
    TrustedFunctionParameterRefType funcParam
);

/* Configuration information of a TrustedFunction. */
struct Os_TrustedFunctionCfg
{
    /* Owner application. */
    ApplicationType ownerAppId;
    /* Current memory protection settings. */
    const Os_MpCfgType* appMpCfg;
    /* User call back function. */
    Os_TrustFunCbkType TFCallBack;
};

typedef struct Os_TrustedFunctionCfg Os_TrustedFunctionCfgType;

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

#endif /* OS_TRUSTFUN_TYPES_H_ */
