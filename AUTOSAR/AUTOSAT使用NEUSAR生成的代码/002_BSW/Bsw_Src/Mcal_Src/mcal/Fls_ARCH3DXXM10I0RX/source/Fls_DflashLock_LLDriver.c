/*
 * Fls_DfashLock_LLDriver.c
 *
 *  Created on: 2025/11/17
 *      Author: zjjin
 */
/* PRQA S 380,4424,1006,4342,1881,3200,3344  EOF */
#include "sema42_lld.h"
#include "Fls_DflashLock_LLDriver.h"
#include "mcal.h"
#include "SchM_Fls.h"

#define FLS_START_SEC_VAR_SHARED_INIT
#include "Fls_MemMap.h"
volatile uint8_t Flash_Lock=0;
#define FLS_STOP_SEC_VAR_SHARED_INIT
#include "Fls_MemMap.h"

/* SEMA42 - Peripheral instance pMcu_Base addresses */
/** Peripheral SEMA42 pMcu_Base address */
#define FLS_SEMA42_BASE                              (0xFC03C000UL)

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
static FUNC(lock_status_t, FLS_CODE) SchM_Hsm_Try(void)
{
    VAR(lock_status_t, AUTOMATIC) status = S_BUSY;
    VAR(uint32_t, AUTOMATIC) u32TimeOut = TIMEMAX;
    VAR(uint8_t, AUTOMATIC) u8CoreID = (uint8_t)GetCoreID();
    SchM_Enter_Fls_EXCLUSIVE_AREA_16();

    do
    {
        if (STATUS_SUCCESS == SEMA42_LockGate((SEMA42_Type *)FLS_SEMA42_BASE, (GATE_NUM)RTE_HSM_SEMA42_GATE_ID, u8CoreID))
        {
            if (STATUS_SUCCESS == SEMA42_CheckLock((SEMA42_Type *)FLS_SEMA42_BASE, (GATE_NUM)RTE_HSM_SEMA42_GATE_ID, u8CoreID, 3U))
            {
                status = S_OK;
            }
        }
        else
        {
            u32TimeOut--;
            if (u32TimeOut == 0U)
            {
                status = S_TIMEOUT;
                SchM_Exit_Fls_EXCLUSIVE_AREA_16();
                break;
            }
        }
    }while(status != S_OK);

    return status;

}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
static FUNC(void, FLS_CODE) SchM_Hsm_Exit(void)
{
    VAR(uint8_t, AUTOMATIC) u8CoreID = (uint8_t)GetCoreID();
    (void)SEMA42_UnlockGate((SEMA42_Type *)FLS_SEMA42_BASE,(GATE_NUM)RTE_HSM_SEMA42_GATE_ID, u8CoreID);
    
    SchM_Exit_Fls_EXCLUSIVE_AREA_16();
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(lock_status_t, FLS_CODE) Host_Flash_TryLock(LOCK_TYPE master)
{
    VAR(lock_status_t, AUTOMATIC) status = S_BUSY;
    status = SchM_Hsm_Try();
    if(status == S_OK)
    {
         if (UNLOCK == Flash_Lock)
        {
            Flash_Lock = master;
            status = S_OK;
        }else
        {
            status = S_BUSY;
        }
        SchM_Hsm_Exit();
     }
     else
     {
         status = S_TIMEOUT;
     }
     return status;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(lock_status_t, FLS_CODE) Host_Flash_UnLock(LOCK_TYPE master)
{
    VAR(lock_status_t, AUTOMATIC) status = S_ERROR;
    status = SchM_Hsm_Try();
    if(status == S_OK)
    {
        if (master == Flash_Lock)
        {
            Flash_Lock = UNLOCK;
            status = S_OK;
        }else
        {
            status = S_ERROR;
        }
        SchM_Hsm_Exit();
    }
    else
    {
        status = S_TIMEOUT;
    }
    return status;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Host_Flash_LockInit(void)
{
    SEMA42_LLD_Init(SEMA42_0);
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(lock_status_t, FLS_CODE) Host_Flash_Request(void)
{
    VAR(lock_status_t, AUTOMATIC) status = S_ERROR;
    VAR(uint32_t, AUTOMATIC) flag = INIT;
    status = SchM_Hsm_Try();
    if(status == S_OK)
    {
        if (UNLOCK == Flash_Lock)
        {
            Flash_Lock = LOCK_HOST_FLS;
            flag = QUICK;
            status = S_OK;
        }
        else     //LOCK_HSM==Flash_lock
        {
            Flash_Lock = LOCK_HOST_FLS;
            status = S_OK;
        }
        SchM_Hsm_Exit();
    }
    else
    {
        status = S_TIMEOUT;
    }

    if(flag == QUICK)
    {
        Host_Flash_Request_Done();
    }

    return status;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(lock_status_t, FLS_CODE) Host_Flash_Request_Done(void)
{
    VAR(lock_status_t, AUTOMATIC) status = S_ERROR;
    status = Host_Flash_UnLock(LOCK_HOST_FLS);
    {
        if(status)
        {
            /* do nothing */
        }
    }
    return status;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(uint8_t, FLS_CODE) Host_Flash_ReadLock(void)
{
    return Flash_Lock;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

