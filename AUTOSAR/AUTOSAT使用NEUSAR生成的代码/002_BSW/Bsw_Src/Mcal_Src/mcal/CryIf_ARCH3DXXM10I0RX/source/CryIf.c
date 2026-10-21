/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CryIf
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    CryIf.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CryIf MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

#include "CryIf_Cbk.h"

CRYIF_START_SEC_CODE
void CryIf_CallbackNotification(const Crypto_JobType* job, Std_ReturnType result)
{
    (void)job;
    (void)result;
}
CRYIF_STOP_SEC_CODE

/** @} */
