/*
************************************************************************************************************************
*
* File name: Rte_SecOC_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2020.05.09
* Change: New created
* Cause: New
************************************************************************************************************************
* Version: 3.0
* Author/Date : FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_SECOC_TYPE_H_
#define RTE_SECOC_TYPE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "ComStack_Types.h"

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
/* [SWS_SecOC_00149] */
#ifndef Rte_TypeDef_SecOC_VerificationResultType
#define Rte_TypeDef_SecOC_VerificationResultType
typedef enum
{
    SECOC_VERIFICATIONSUCCESS = 0x00U,
    SECOC_VERIFICATIONFAILURE = 0x01U,
    SECOC_FRESHNESSFAILURE = 0x02U,
    SECOC_AUTHENTICATIONBUILDFAILURE = 0x03U,
    SECOC_NO_VERIFICATION = 0x04U,
    SECOC_VERIFICATIONFAILURE_OVERWRITTEN = 0x05U
} SecOC_VerificationResultType;
#endif    /* [SWS_SecOC_00149] */

#ifndef Rte_TypeDef_SecOC_OverrideStatusType
#define Rte_TypeDef_SecOC_OverrideStatusType
typedef enum
{
    SECOC_OVERRIDE_DROP_UNTIL_NOTICE = 0x00U,
    SECOC_OVERRIDE_DROP_UNTIL_LIMIT = 0x01U,
    SECOC_OVERRIDE_CANCEL = 0x02U,
    SECOC_OVERRIDE_PASS_UNTIL_NOTICE = 0x40U,
    SECOC_OVERRIDE_SKIP_UNTIL_LIMIT = 0x41U,
    SECOC_OVERRIDE_PASS_UNTIL_LIMIT = 0x42U
} SecOC_OverrideStatusType;
#endif

/* [SWS_SecOC_00160] */
#ifndef Rte_TypeDef_SecOC_VerificationStatusType
#define Rte_TypeDef_SecOC_VerificationStatusType
typedef struct
{
    uint16 freshnessValueID;
    SecOC_VerificationResultType verificationStatus;
    uint16 secOCDataId;
}SecOC_VerificationStatusType;
#endif

typedef enum
{
    SECOC_OFF,
    SECOC_ON
}SecOC_ModeType;

/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
#ifndef Rte_TypeDef_SecOC_FreshnessArrayType
#define Rte_TypeDef_SecOC_FreshnessArrayType
typedef uint8* SecOC_FreshnessArrayType;
#endif
/*
************************************************************************************************************************
*    Global Variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Constants
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Functions
************************************************************************************************************************
*/
#endif  /* RTE_SECOC_TYPE_H_ */

