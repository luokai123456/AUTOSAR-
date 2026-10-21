/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    eTPU_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eTPU MCAL driver.
*
*   @addtogroup eTPU
*   @{
*/
/* PRQA S 3432 EOF */
/* PRQA S 2844, 0488, 0751, 4397, 498, 489, 2053 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "eTPU_LLDrivers.h" /* PRQA S 0380 */
#if (defined(RESOURCE_SUPPORT_ETPU))

#define ETPU_LLD_WRA_C_VENDOR_ID                     176
#define ETPU_LLD_WRA_C_AR_REL_MAJOR_VER              4
#define ETPU_LLD_WRA_C_AR_REL_MINOR_VER              4
#define ETPU_LLD_WRA_C_AR_REL_REV_VER                0
#define ETPU_LLD_WRA_C_SW_MAJOR_VER                  3
#define ETPU_LLD_WRA_C_SW_MINOR_VER                  0
#define ETPU_LLD_WRA_C_SW_PATCH_VER                  0

#if (ETPU_VENDOR_ID_OUTPUT != ETPU_LLD_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_VENDOR_ID "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != ETPU_LLD_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != ETPU_LLD_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != ETPU_LLD_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != ETPU_LLD_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != ETPU_LLD_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != ETPU_LLD_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETPU_LLD_WRA_C_SW_PATCH_VER "
#endif

#define ETPU_START_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"
etpu_instance_t eTPUInstance[2] =
{
	/* ETPU A && ETPU B */
	{(eTPU_Type *)0xFFDC0000U, 0xFFDD0000U, 0xFFDC8000U, 0xFFDCBFFFU, 0xFFDCC000U, (uint32 *)0, 1},
	/* ETPU C */
	{(eTPU_Type *)0xFBF80000U, 0xFBF90000U, 0xFBF88000U, 0xFBF8BFFFU, 0xFBF8C000U, (uint32 *)0, 0},
};
#define ETPU_STOP_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static uint8 *ETPU_LLD_MemCopy_32(uint32 *dest,
                            uint32 const *source,
                            uint32 size);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static FUNC(void, ETPU_CODE) ETPU_LLD_MemSet_32 \
( \
    P2VAR( uint32, AUTOMATIC, ETPU_APPL_DATA ) start, \
    VAR( uint32, AUTOMATIC ) value, \
    VAR( uint32, AUTOMATIC ) size
);
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief This function initializes the eTPU module.
 *
 * This function does not configure the pins, only the eTPU.
 *
 * @param[in] p_etpu_config : This is the structure used to initialize the eTPU
 * @param[in] *code : This is a pointer to an image of the eTPU code.
 * @param[in] code_size : This is the size of the eTPU code in bytes.
 * @param[in] *globals : This is a pointer to the global eTPU data that needs to be initialized.
 * @param[in] globals_size : This is the size of the global data in bytes.
 * @return
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(status_t, ETPU_CODE)ETPU_LLD_Init \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    P2CONST(etpu_global_param_t, AUTOMATIC, ETPU_APPL_CONST) p_etpu_config, \
    P2CONST(uint32, AUTOMATIC, ETPU_APPL_CONST) code, \
    VAR(uint32, AUTOMATIC) code_size, \
    P2CONST(uint32, AUTOMATIC, ETPU_APPL_CONST) globals, \
    VAR(uint32, AUTOMATIC) globals_size
)
{
    status_t ret = STATUS_SUCCESS;
    uint32 *code_end;
    sint32 unused_code_ram;
    sint8 x;

    if(etpuGroup >= 2U)
    {
        return STATUS_ERROR;
    }

    unused_code_ram = (((sint32)eTPUInstance[etpuGroup].eTPU->MCR.B.SCMSIZE + 1 ) * 2048) - (sint32)code_size;/* polyspace RTE:NIV,IDP */
    if(unused_code_ram < 0)
    {
        ret = STATUS_ETPU_WRONG_CODE_SIZE;
    }

    /* 1. Load microcode */
    /* In order for the MISC function to work with code that is small than
    * the code memory any unused locations must be set to zero. */
    if (ret == STATUS_SUCCESS)
    {
        eTPUInstance[etpuGroup].eTPU->ECR_A.B.MDIS = 1;    /* stop eTPU_A */
        eTPUInstance[etpuGroup].eTPU->ECR_B.B.MDIS = 1;    /* stop eTPU_B *//* polyspace RTE:IDP */
        eTPUInstance[etpuGroup].eTPU->MCR.B.VIS = 1;       /* enable CPU writes to eTPU code memory *//* polyspace RTE:IDP */

        x = 0;
        while(x < 5)
        {
            if(eTPUInstance[etpuGroup].eTPU->MCR.B.VIS == 1U)/* polyspace RTE:NIV,IDP */
            {
                break;
            }
            x++;
        }
        if(x > 4)
        {
            ret = STATUS_TIMEOUT;
        }
    }

    if (ret == STATUS_SUCCESS)
    {
        /* Copy microcode */
        (void)ETPU_LLD_MemCopy_32((uint32 *)(eTPUInstance[etpuGroup].code_start), code, code_size);    /*PRQA S 0310,3305,0563 */

        code_end = (uint32*)(eTPUInstance[etpuGroup].code_start + code_size);
        /* Clear rest of program memory */
        ETPU_LLD_MemSet_32(code_end, 0, (uint32)unused_code_ram);

        eTPUInstance[etpuGroup].eTPU->MCR.B.VIS = 0;    /* disable CPU writes to eTPU code memory */

        /* Configure MISC */
        eTPUInstance[etpuGroup].eTPU->MISCCMPR.R = p_etpu_config->misc; /*write MISC value before enabled in MCR *//* polyspace RTE:IDP */
        eTPUInstance[etpuGroup].eTPU->MCR.R = p_etpu_config->mcr;/* polyspace RTE:IDP */

        /* Configure Engine 1 */
        eTPUInstance[etpuGroup].eTPU->ECR_A.R = p_etpu_config->ecr_a;/* polyspace RTE:IDP */
        if(eTPUInstance[etpuGroup].eTPU->ECR_A.B.MDIS == 0U)/* polyspace RTE:NIV,IDP */
        {
            eTPUInstance[etpuGroup].eTPU->TBCR_A.R = p_etpu_config->tbcr_a;
            eTPUInstance[etpuGroup].eTPU->REDCR_A.R = p_etpu_config->stacr_a;/* polyspace RTE:IDP */
        }

        /* Configure Engine 2 */
        /* Not all parts have a second eTPU engine, if yes, these write are ignored. */
        eTPUInstance[etpuGroup].eTPU->ECR_B.R = p_etpu_config->ecr_b;/* polyspace RTE:IDP */
        if(eTPUInstance[etpuGroup].eTPU->ECR_B.B.MDIS == 0U)/* polyspace RTE:NIV,IDP */
        {
            eTPUInstance[etpuGroup].eTPU->TBCR_B.R = p_etpu_config->tbcr_b;
            eTPUInstance[etpuGroup].eTPU->REDCR_B.R = p_etpu_config->stacr_b;/* polyspace RTE:IDP */
        }

        /* 3. Copy initial global values to parameter RAM. */
        (void)ETPU_LLD_MemCopy_32((uint32 *)eTPUInstance[etpuGroup].data_ram_start, (uint32 const *)globals, globals_size);    /*PRQA S 0310,3305,0563 */
        eTPUInstance[etpuGroup].free_param = (uint32*)(eTPUInstance[etpuGroup].data_ram_start + globals_size);
        eTPUInstance[etpuGroup].free_param = (uint32*)((((uint32)eTPUInstance[etpuGroup].free_param + 7U) >> 3U) << 3U); /* round up to 8s */
    }
#if (defined(CCFC3007PT))
#if (ETPU_STARTTIMER_API == STD_OFF)
        ETPU_LLD_TimerStart(etpuGroup); /*start timebases*/
#endif
#endif/* defined(CCFC3007PT) */
    return ret;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_TimerStart
****************************************************************************//*!
* @brief   This function starts the timebases.
*
* @note    This functions synchronously starts the timebases of all timer
*          modules on a device.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_TimerStart \
( \
    VAR(uint8, AUTOMATIC) etpuGroup
)
{
    eTPUInstance[etpuGroup].eTPU->MCR.B.GTBE = 1;/* polyspace RTE:IDP */
    eTPUInstance[etpuGroup].eTPU->MCR.B.VIS = 0;/* polyspace RTE:IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_Malloc_32
****************************************************************************//*!
* @brief   This function allocates DATA RAM (parameter RAM) for a channel.
*
* @param   num_bytes - this is the number of bytes that is required to
*          allocate in DATA RAM.
*
* @return  A pointer to allocated DATA RAM. If the requested amount of memory
*          is larger than the available amount of memory then 0 is returned.
*
* @warning This function is non-reentrant and uses the @ref fs_free_param global.
*          The granularity of eTPU DATA RAM allocation for channel parameters
*          is 8 bytes. The requested size is enlarged to a multiple of 8 bytes.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint32 *ETPU_LLD_Malloc_32(uint8 etpuGroup,
                          uint16 num_bytes)
{
    uint32 *pba;
    uint32 param = 0U;

    if(etpuGroup >= 2U)
    {
        return NULL_PTR;
    }

    pba = eTPUInstance[etpuGroup].free_param;
    eTPUInstance[etpuGroup].free_param += (((num_bytes + 7U) >> 3U) << 1U);
    param = (uint32)eTPUInstance[etpuGroup].free_param;

    if(param > eTPUInstance[etpuGroup].data_ram_end)
    {
        return NULL_PTR;
    }
    else
    {
        return (pba);
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint32 *ETPU_LLD_Malloc2(uint8 etpuGroup,
                           uint8 channel,
                          uint16 num_bytes)
{
    uint32 *pba;
    uint32 param = 0U;

    if(etpuGroup >= 2U)
    {
        return NULL_PTR;
    }

    if(eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA == 0U )  /*PRQA S 1863 *//* polyspace RTE:NIV,IDP,OBAI*/
    {
        pba = eTPUInstance[etpuGroup].free_param;
        eTPUInstance[etpuGroup].free_param += (((num_bytes+7U)>>3U)<<1U);        /*PRQA S 1860 */
        param = (uint32)eTPUInstance[etpuGroup].free_param;

        if(param > eTPUInstance[etpuGroup].data_ram_end)
        {
            return (NULL_PTR);
        }
        else
        {
            return (pba);
        }
    }
    else
    {
        return (ETPU_LLD_GetDataRam(etpuGroup, channel));
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_MemCopy_32
****************************************************************************//*!
* @brief   This function is similar to the standard C memset() function
*          however it sets 32-bit words rather than bytes.
*
* @param   *dest - The pointer to the destination location
* @param   *source - The pointer to the source location
* @param   size - The size of the data to copy in bytes
*
* @return  A pointer to the end of the copied data.
*
* @warning The *dest and *source pointers should be aligned to a 32-bit
*          address. If they are not it may cause memory exceptions. Moving
*          data to the eTPU code memory that is not 32-bit aligned is
*          undefined. The size should be a multiple of 4. If it is not
*          it is rounded down.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static uint8 *ETPU_LLD_MemCopy_32(uint32 *dest,
                            uint32 const *source,
                            uint32 size)
{
    uint8 *p = (uint8 *)dest;
    uint8 const *q = (uint8 const *)source;
    uint32 size_l = size;

    while(size_l != 0U)
    {
        *p = *q;/* polyspace RTE:IDP */
        p++;
        q++;
        size_l--;
    }

    return p;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_MemSet_32
****************************************************************************//*!
* @brief   This function is similar to the standard C memcpy() function
*          however it copies 32-bit words rather than bytes.
*
* @param   *start - The pointer to the start location
* @param   *value - The value to write to memory
* @param   size - The size of the data to set in bytes
*
* @warning The *start pointers should be aligned to a 32-bit address.
*          If it is not it may cause memory exceptions. Writing
*          data to the eTPU code memory that is not 32-bit aligned is
*          undefined. The size should be a multiple of 4. If it is not
*          it is rounded down.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static FUNC(void, ETPU_CODE) ETPU_LLD_MemSet_32 \
( \
    P2VAR( uint32, AUTOMATIC, ETPU_APPL_DATA ) start, \
    VAR( uint32, AUTOMATIC ) value, \
    VAR( uint32, AUTOMATIC ) size
)
{
    uint32 *p = start;
    uint32 size_l = size;

    size_l = size_l >> 2U;

    while(size_l != 0U)
    {
        *p = value;/* polyspace RTE:IDP */
        p++;
        size_l--;
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentRead24
****************************************************************************//*!
* @brief   This function coherently reads two 24-bit variables from the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 24-bit variable to be read
* @param   offset2 - The offset to the second 24-bit variable to be read
* @param   *value1 - A pointer to where the first variable value will be stored
* @param   *value2 - A pointer to where the second variable value will be stored
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentRead24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value1, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value2
)
{
    uint32 addr1, addr2, ctbase1, ctbase2;
    uint32 addr_b;
    uint32 err_code = 0;

    if(etpuGroup >= 2U)
    {
        err_code = ETPU_ERROR_VALUE;
        return err_code;
    }

    /* check there is a DATA RAM space for the temporally buffer */
    if (((uint32)eTPUInstance[etpuGroup].free_param + 8U) > eTPUInstance[etpuGroup].data_ram_end)
    {
        err_code = ETPU_ERROR_MALLOC;
    }
    else
    {
        /* SDM-relative word addresses of parameters (4 byte granularity) */
        addr1 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + (offset1 - 1U)) >> 2;/* polyspace RTE:OBAI,NIV,IDP */
        addr2 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + (offset2 - 1U)) >> 2;
        ctbase1 = addr1 >> 7;
        ctbase2 = addr2 >> 7;

        if(ctbase1 != ctbase2)
        {
            err_code = ETPU_ERROR_ADDRESS;
        }
        else
        {
            /* SDM-relative doubleword address of buffer (8 byte granularity) */
            addr_b = ((uint32)eTPUInstance[etpuGroup].free_param - eTPUInstance[etpuGroup].data_ram_start) >> 3;

            eTPUInstance[etpuGroup].eTPU->CDCR.R = ((uint32)1UL << 31U) + (ctbase1 << 26U) + (addr_b << 16U) \
                            + ((addr1 & 0x7FU) << 8U) + (addr2 & 0x7FU);

            /* now host receives wait states untill the transfer is done */

            /* read values from temporary buffer */
            *value1 = ((uint32)(*( eTPUInstance[etpuGroup].free_param))<<8U)>>8U;/* polyspace RTE:NIV,IDP */
            *value2 = ((*(eTPUInstance[etpuGroup].free_param + 1))<<8)>>8;/* polyspace RTE:NIV,IDP */
        }
    }

    return (err_code);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentRead32
****************************************************************************//*!
* @brief   This function coherently reads two 32-bit variables from the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 32-bit variable to be read
* @param   offset2 - The offset to the second 32-bit variable to be read
* @param   *value1 - A pointer to where the first variable value will be stored
* @param   *value2 - A pointer to where the second variable value will be stored
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentRead32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value1, \
    P2VAR(uint32, AUTOMATIC, ETPU_APPL_DATA) value2
)
{
    uint32 addr1, addr2, ctbase1, ctbase2;
    uint32 addr_b;
    uint32 err_code = 0;

    if(etpuGroup >= 2U)
    {
        return ETPU_ERROR_VALUE;
    }

    /* check there is a DATA RAM space for the temporally buffer */
    if (((uint32)eTPUInstance[etpuGroup].free_param + 8U) > eTPUInstance[etpuGroup].data_ram_end)
    {
        err_code = ETPU_ERROR_MALLOC;
    }
    else
    {
        /* SDM-relative word addresses of parameters (4 byte granularity) */
        addr1 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + offset1) >> 2;/* polyspace RTE:OBAI,NIV,IDP */
        addr2 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + offset2) >> 2;
        ctbase1 = addr1 >> 7;
        ctbase2 = addr2 >> 7;

        if(ctbase1 != ctbase2)
        {
            err_code = ETPU_ERROR_ADDRESS;
        }
        else
        {
            /* SDM-relative doubleword address of buffer (8 byte granularity) */
            addr_b = ((uint32)eTPUInstance[etpuGroup].free_param - eTPUInstance[etpuGroup].data_ram_start) >> 3;

            eTPUInstance[etpuGroup].eTPU->CDCR.R = ((uint32)1UL << 31U) + (ctbase1 << 26U) + (addr_b << 16U) + ((uint32)1UL << 15U) \
                            + ((addr1 & 0x7FU) << 8U) + (addr2 & 0x7FU);

            /* now host receives wait states untill the transfer is done */

            /* read values from temporary buffer */
            *value1 = *(eTPUInstance[etpuGroup].free_param);/* polyspace RTE:NIV,IDP */
            *value2 = *(eTPUInstance[etpuGroup].free_param + 1);/* polyspace RTE:NIV,IDP */
        }
    }

    return (err_code);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentWrite24
****************************************************************************//*!
* @brief   This function coherently writes two 24-bit variables into the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 24-bit variable to be written
* @param   offset2 - The offset to the second 24-bit variable to be written
* @param   value1 - The first variable value
* @param   value2 - The second variable value
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentWrite24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    VAR(sint32, AUTOMATIC) value1, \
    VAR(sint32, AUTOMATIC) value2
)
{
    uint32 addr1, addr2, ctbase1, ctbase2;
    uint32 addr_b;
    uint32 err_code = 0;

    if(etpuGroup >= 2U)
    {
        return ETPU_ERROR_VALUE;
    }

    /* check there is a DATA RAM space for the temporally buffer */
    if (((uint32)eTPUInstance[etpuGroup].free_param + 8U) > eTPUInstance[etpuGroup].data_ram_end)
    {
        err_code = ETPU_ERROR_MALLOC;
    }
    else
    {
        /* write values to the temporary buffer */
        *(eTPUInstance[etpuGroup].free_param) = (uint32)value1;/* polyspace RTE:IDP */
        *(eTPUInstance[etpuGroup].free_param + 1) = (uint32)value2;/* polyspace RTE:IDP */

        /* SDM-relative word addresses of parameters (4 byte granularity) */
        addr1 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + (offset1 - 1U)) >> 2;/* polyspace RTE:OBAI,NIV,IDP */
        addr2 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + (offset2 - 1U)) >> 2;
        ctbase1 = addr1 >> 7;
        ctbase2 = addr2 >> 7;

        if(ctbase1 != ctbase2)
        {
            err_code = ETPU_ERROR_ADDRESS;
        }
        else
        {
            /* SDM-relative doubleword address of buffer (8 byte granularity) */
            addr_b = ((uint32)eTPUInstance[etpuGroup].free_param - eTPUInstance[etpuGroup].data_ram_start) >> 3;

            eTPUInstance[etpuGroup].eTPU->CDCR.R = ((uint32)1UL << 31U) + (ctbase1 << 26U) + (addr_b << 16U) + (1U << 7U) \
                            + ((addr1 & 0x7FU) << 8U) + (addr2 & 0x7FU);

            /* now host receives wait states untill the transfer is done */
        }
    }

    return (err_code);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_CoherentWrite32
****************************************************************************//*!
* @brief   This function coherently writes two 32-bit variables into the eTPU
*          DATA RAM, using the Coherent Dual-Parameter Controller (CDC).
*
* @param   channel - The eTPU channel number
* @param   offset1 - The offset to the first 32-bit variable to be written
* @param   offset2 - The offset to the second 32-bit variable to be written
* @param   value1 - The first variable value
* @param   value2 - The second variable value
*
* @return  Zero or an error code. Error codes that can be returned are:
*          - @ref ETPU_ERROR_MALLOC - When there is not enough available
*            memory for the temporally buffer in eTPU DATA RAM
*          - @ref ETPU_ERROR_ADDRESS - When the variable offsets do not allow
*            the CDC operation.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_CoherentWrite32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset1, \
    VAR(uint32, AUTOMATIC) offset2, \
    VAR(sint32, AUTOMATIC) value1, \
    VAR(sint32, AUTOMATIC) value2
)
{
    uint32 addr1, addr2, ctbase1, ctbase2;
    uint32 addr_b;
    uint32 err_code = 0;

    if(etpuGroup >= 2U)
    {
        return ETPU_ERROR_VALUE;
    }

    /* check there is a DATA RAM space for the temporally buffer */
    if (((uint32)eTPUInstance[etpuGroup].free_param + 8U) > eTPUInstance[etpuGroup].data_ram_end)
    {
        err_code = ETPU_ERROR_MALLOC;
    }
    else
    {
        /* write values to the temporary buffer */
        *(eTPUInstance[etpuGroup].free_param) = (uint32)value1;/* polyspace RTE:IDP */
        *(eTPUInstance[etpuGroup].free_param + 1) = (uint32)value2;/* polyspace RTE:IDP */

        /* SDM-relative word addresses of parameters (4 byte granularity) */
        addr1 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + offset1) >> 2;/* polyspace RTE:OBAI,NIV,IDP */
        addr2 = (((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3) + offset2) >> 2;
        ctbase1 = addr1 >> 7;
        ctbase2 = addr2 >> 7;

        if(ctbase1 != ctbase2)
        {
            err_code = ETPU_ERROR_ADDRESS;
        }
        else
        {
            /* SDM-relative doubleword address of buffer (8 byte granularity) */
            addr_b = ((uint32)eTPUInstance[etpuGroup].free_param - eTPUInstance[etpuGroup].data_ram_start) >> 3;

            eTPUInstance[etpuGroup].eTPU->CDCR.R = ((uint32)1UL << 31U) + (ctbase1 << 26U) + (addr_b << 16U) + ((uint32)1UL << 15U) + (1UL << 7U) \
                            + ((addr1 & 0x7FU) << 8U) + (addr2 & 0x7FU);

            /* now host receives wait states untill the transfer is done */

        }
    }
    
    return (err_code);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_interrupt_enable
****************************************************************************//*!
* @brief   This function enables an eTPU channel to generate interrupts.
*
* @param   channel - The eTPU channel number
*
* @warning This enables the eTPU to send interrupts to an interrupt
*          controller. Additional configuration may be required for
*          the CPU to receive the interrupts.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Interrupt_Enable(uint8 etpuGroup,uint8 channel)
{
	eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CIE = TRUE;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_interrupt_disable
****************************************************************************//*!
* @brief   This function disables an eTPU channel from generating interrupts.
*
* @param   channel - The eTPU channel number
*
* @warning When interrupts are disabled the eTPU interrupt status bits are
*          still set and can be used to poll the interrupt status.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Interrupt_Disable(uint8 etpuGroup,uint8 channel)
{
	eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CIE = FALSE;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_dma_enable
****************************************************************************//*!
* @brief   This function enables an eTPU channel to request DMA service.
*
* @param   channel - The eTPU channel number
*
* @warning In a given device not all of the DMA requests may be connected
*          to DMA channels.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Dma_Enable(uint8 etpuGroup,uint8 channel)
{
	eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.DTRE = TRUE;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_dma_disable
****************************************************************************//*!
* @brief   This function disables an eTPU channel from generating DMA requests.
*
* @param   channel - The eTPU channel number
*
* @warning When DMA requests are disabled the eTPU DMA request status bits are
*          still set and can be used to poll the DMA request status.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Dma_Disable(uint8 etpuGroup,uint8 channel)
{
	eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.DTRE = FALSE;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_interrupt_flag
****************************************************************************//*!
* @brief   This function returns the current value of the Channel Interrupt
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_interrupt_flag(uint8 etpuGroup,uint8 channel)
{
  return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.CIS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_interrupt_flag
****************************************************************************//*!
* @brief   This function clears the channel interrupt flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_Clear_Chan_Interrupt_Flag(uint8 etpuGroup,uint8 channel)
{
  if(channel < 32U)
  {
	  eTPUInstance[etpuGroup].eTPU->CISR_A.R =(uint32)1UL<<channel;/* polyspace RTE:OBAI,IDP */
  }
  else
  {
	  if((channel-64U) <32U)
	  {
		  eTPUInstance[etpuGroup].eTPU->CISR_B.R = (uint32)1UL << (channel-64U );/* polyspace RTE:OBAI,IDP */
	  }
  }

}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_interrupt_oveflow_flag
****************************************************************************//*!
* @brief   This function returns the current value of the Channel Interrupt
*          Overflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIOS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_interrupt_overflow_flag(uint8 etpuGroup,uint8 channel)
{
  return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.CIOS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_interrupt_overflow_flag
****************************************************************************//*!
* @brief   This function clears the channel interrupt oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void fs_etpu_clear_chan_interrupt_overflow_flag(uint8 etpuGroup,uint8 channel)
{
  if(channel < 32U )
  {
	  eTPUInstance[etpuGroup].eTPU->CIOSR_A.R = (uint32)1UL<<channel;/* polyspace RTE:OBAI,IDP */
  }
  else
  {
	  if((channel-64U) <32U)
	  {
		  eTPUInstance[etpuGroup].eTPU->CIOSR_B.R = (uint32)1UL<<(channel - 64U );/* polyspace RTE:OBAI,IDP */
	  }
  }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_dma_flag
****************************************************************************//*!
* @brief   This function returns the current value of the Data Transfer Request
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTRS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_dma_flag(uint8 etpuGroup,uint8 channel)
{
  return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.DTRS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_dma_flag
****************************************************************************//*!
* @brief   This function clears the channel data transfer request flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void fs_etpu_clear_chan_dma_flag(uint8 etpuGroup,uint8 channel)
{
  if(channel < 32U )
  {
	  eTPUInstance[etpuGroup].eTPU->CDTRSR_A.R = (uint32)1UL<<channel;/* polyspace RTE:OBAI,IDP */
  }
  else
  {
	  if((channel-64U) <32U)
	  {
		  eTPUInstance[etpuGroup].eTPU->CDTRSR_B.R =(uint32) 1UL<<(channel-64U);/* polyspace RTE:OBAI,IDP */
	  }
  }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_get_chan_dma_oveflow_flag
****************************************************************************//*!
* @brief   This function returns the current value of the Data Transfer Request
*          Oveflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTROS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 fs_etpu_get_chan_dma_overflow_flag(uint8 etpuGroup,uint8 channel)
{
    return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.DTROS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: fs_etpu_clear_chan_dma_oveflow_flag
****************************************************************************//*!
* @brief   This function clears the channel data transfer request oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void fs_etpu_clear_chan_dma_overflow_flag(uint8 etpuGroup,uint8 channel)
{
  if(channel < 32U)
  {
	  eTPUInstance[etpuGroup].eTPU->CDTROSR_A.R = (uint32)1UL<<channel;/* polyspace RTE:OBAI,IDP */
  }
  else
  {
	  if((channel-64U) <32U)
	  {
		  eTPUInstance[etpuGroup].eTPU->CDTROSR_B.R = (uint32)1UL<<(channel-64U);/* polyspace RTE:OBAI,IDP */
	  }
  }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


/*-----------------------Channel Configuration Register CR-----------------------------*/

/*
 * @brief   This function enables an eTPU channel to generate interrupts.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelInterruptEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CIE = 1U;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function disables an eTPU channel from generating interrupts.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelInterruptDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CIE = 0U;/* polyspace RTE:IDP,OBAI */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function enables an eTPU channel to request DMA service.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMAEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.DTRE = 1U;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function disables an eTPU channel from generating DMA requests.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMADisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.DTRE = 0U;/* polyspace RTE:IDP,OBAI */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function enables or changes the priority of an eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 * @param[in]   priority - The priority to be assigned to the channel.
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) priority
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPR = priority;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function disables an eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPR = ETPU_PRIORITY_DISABLE;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function disables an eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameterBaseAddress \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    return eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function enables or disables the channel "output disable"
 *          feature for each engine A channel according to the given mask and
 *          polarity.
 * @param[in]   mask - The "output disable" enable mask.
 * @param[in]   polarity - The "output disable" polarity mask.
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetOutputDisableMask_A \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask, \
    VAR(uint32, AUTOMATIC) polarity
)
{
    uint8 i;
    uint32 mask_l = mask;
    uint32 polarity_l = polarity;

    for(i=0U; i<32U; i++)
    {
        eTPUInstance[etpuGroup].eTPU->CHAN[i].CR.B.ODIS = mask_l & 0x00000001U;/* polyspace RTE:OBAI,IDP */
        eTPUInstance[etpuGroup].eTPU->CHAN[i].CR.B.OPOL = polarity_l & 0x00000001U;/* polyspace RTE:IDP */
        mask_l >>= 1;
        polarity_l >>= 1;
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetOutputDisableMask_B
****************************************************************************//*!
* @brief   This function enables or disables the channel "output disable"
*          feature for each engine B channel according to the given mask and
*          polarity.
*
* @param   mask - The "output disable" enable mask. A value of:
*          - 0x00000001 enables the "output disable" feature on channel 64 only,
*          - 0x80000000 enables the "output disable" feature on channel 95 only
* @param   polarity - The "output disable" polarity mask. A value of:
*          - 0x00000001 sets the high polarity of disabled output on channel 64
*            and low polarity of disabled output on all other channels
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetOutputDisableMask_B \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask, \
    VAR(uint32, AUTOMATIC) polarity
)
{
    uint8 i;
    uint32 mask_l = mask;
    uint32 polarity_l = polarity;

    for(i = 64U; i < 96U; i++)
    {
        eTPUInstance[etpuGroup].eTPU->CHAN[i].CR.B.ODIS = mask_l & 0x00000001U;/* polyspace RTE:OBAI,IDP */
        eTPUInstance[etpuGroup].eTPU->CHAN[i].CR.B.OPOL = polarity_l & 0x00000001U;/* polyspace RTE:IDP */
        mask_l >>= 1U;
        polarity_l >>= 1U;
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*-----------------------Channel Status Control Register SCR-----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetInterruptFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Channel Interrupt
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetInterruptFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.CIS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetInterruptOverflowFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Channel Interrupt
*          Overflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of CIOS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetInterruptOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.CIOS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelDMAFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Data Transfer Request
*          Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTRS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetChannelDMAFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.DTRS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetDMAOverflowFlag
****************************************************************************//*!
* @brief   This function returns the current value of the Data Transfer Request
*          Oveflow Status bit of the specified eTPU channel.
*
* @param   channel - The eTPU channel number
*
* @return  Value of DTROS bit of the specified channel SCR register.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetDMAOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.DTROS);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*-----------------------Channel Host Service Request Register HSR-----------------------------*/

/*
 * @brief   This function sets the Host Service Request (HSR) register of the
 *          specified eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 * @param[in]   hsr - The HSR value to send to the channel
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetHSR \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint8, AUTOMATIC) hsr
)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = hsr;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*
 * @brief   This function returns the current value of the Host Service Request
 *          (HSR) register of the specified eTPU channel.
 * @param[in]   etpuGroup - The eTPU instance index
 * @param[in]   channel - The eTPU channel number
 * @return  The value of HSR register
 */
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetHSR \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    return((uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R);/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*-----------------------Interruput Enable Register GCR_CIER-----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetInterruptMask_A
****************************************************************************//*!
* @brief   This function enables or disables channel interrupt for each engine A
*          channel according to the given mask.
*
* @param   mask - The interrupt enable mask. A value of:
*          - 0x00000001 enables interrupt on channel 0 only,
*          - 0x80000000 enables interrupt on channel 31 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetInterruptMask_A \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
)
{
    eTPUInstance[etpuGroup].eTPU->CIER_A.R = mask;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetInterruptMask_B
****************************************************************************//*!
* @brief   This function enables or disables channel interrupt for each engine B
*          channel according to the given mask.
*
* @param   mask - The interrupt enable mask. A value of:
*          - 0x00000001 enables interrupt on channel 64 only,
*          - 0x80000000 enables interrupt on channel 95 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetInterruptMask_B \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
)
{
    eTPUInstance[etpuGroup].eTPU->CIER_B.R = mask;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelIntMaskEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CIER_A.R |= 1UL<<channel;/* polyspace RTE:NIV,IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        eTPUInstance[etpuGroup].eTPU->CIER_B.R |= 1UL<<(channel-64U);/* polyspace RTE:NIV,IDP,OBAI */
  	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelIntMaskDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CIER_A.R &= ~(1UL<<channel);/* polyspace RTE:NIV,IDP,OBAI */
    }
    else
    {
		  if((channel-64U) <32U)
		  {
			eTPUInstance[etpuGroup].eTPU->CIER_B.R &= ~(1UL<<(channel-64U));/* polyspace RTE:NIV,IDP,OBAI */
		  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 ETPU_LLD_GetChannelIntMaskStatus(uint8 etpuGroup,
                                                uint8 channel)
{
    uint8 status = (uint8)0U;
    uint32 mask = 0;

    if(channel < 32U)
    {
        mask = eTPUInstance[etpuGroup].eTPU->CIER_A.R & (1UL<<channel);/* polyspace RTE:NIV,IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        mask = eTPUInstance[etpuGroup].eTPU->CIER_B.R & (1UL<<(channel-64U));/* polyspace RTE:NIV,IDP,OBAI */
  	  }
    }

    if (mask != 0U)
    {
        status = (uint8)1U;
    }
    else
    {
        status = (uint8)0U;
    }

    return status;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
/*-----------------------Channel Host Service Request Register HSR-----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetDMAMask_A
****************************************************************************//*!
* @brief   This function enables or disables channel DMA request for each engine
*          A channel according to the given mask.
*
* @param   mask - The DMA enable mask. A value of:
*          - 0x00000001 enables DMA requests on channel 0 only,
*          - 0x80000000 enables DMA requests on channel 31 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetDMAMask_A \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
)
{
    eTPUInstance[etpuGroup].eTPU->CDTRER_A.R = mask;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetDMAMask_B
****************************************************************************//*!
* @brief   This function enables or disables channel DMA request for each engine
*          B channel according to the given mask.
*
* @param   mask - The DMA enable mask. A value of:
*          - 0x00000001 enables DMA requests on channel 64 only,
*          - 0x80000000 enables DMA requests on channel 95 only
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetDMAMask_B \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) mask
)
{
    eTPUInstance[etpuGroup].eTPU->CDTRER_B.R = mask;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMAMaskEnable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CDTRER_A.R |= 1UL<<channel;/* polyspace RTE:NIV,IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        eTPUInstance[etpuGroup].eTPU->CDTRER_B.R |= 1UL<<(channel-64U);/* polyspace RTE:NIV,IDP,OBAI */
  	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ChannelDMAMaskDisable \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CDTRER_A.R &= ~(1UL<<channel);/* polyspace RTE:NIV,IDP,OBAI */
    }
    else
    {
    	  if((channel-64U) <32U)
    	  {
    		  eTPUInstance[etpuGroup].eTPU->CDTRER_B.R &= ~(1UL<<(channel-64U));/* polyspace RTE:NIV,IDP,OBAI */
    	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 ETPU_LLD_GetChannelDMAMaskStatus(uint8 etpuGroup,
                                             uint8 channel)
{
    uint8 status = (uint8)0U;
    uint32 mask = 0;

    if(channel < 32U)
    {
        mask = eTPUInstance[etpuGroup].eTPU->CDTRER_A.R & (1UL<<channel);/* polyspace RTE:OBAI,NIV,IDP */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        mask = eTPUInstance[etpuGroup].eTPU->CDTRER_B.R & (1UL<<(channel-64U));/* polyspace RTE:OBAI,NIV,IDP */
  	  }
    }

    if (mask != 0U)
    {
        status = (uint8)1U;
    }
    else
    {
        status = (uint8)0U;
    }

    return status;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelInterruptFlag
****************************************************************************//*!
* @brief   This function clears the channel interrupt flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelInterruptFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CISR_A.R = 1UL<<channel;/* polyspace RTE:IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        eTPUInstance[etpuGroup].eTPU->CISR_B.R = 1UL<<(channel-64U);/* polyspace RTE:IDP,OBAI */
  	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelInterruptOverflowFlag
****************************************************************************//*!
* @brief   This function clears the channel interrupt oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelInterruptOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CIOSR_A.R = 1UL<<channel;/* polyspace RTE:IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        eTPUInstance[etpuGroup].eTPU->CIOSR_B.R = 1UL<<(channel-64U);/* polyspace RTE:IDP,OBAI */
  	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*----------------------- interrupt flag clear function -----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelDMAFlag
****************************************************************************//*!
* @brief   This function clears the channel data transfer request flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelDMAFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CDTRSR_A.R = 1UL<<channel;/* polyspace RTE:IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        eTPUInstance[etpuGroup].eTPU->CDTRSR_B.R = 1UL<<(channel-64U);/* polyspace RTE:IDP,OBAI */
  	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_ClearChannelDMAOverflowFlag
****************************************************************************//*!
* @brief   This function clears the channel data transfer request oveflow flag.
*
* @param   channel - The eTPU channel number
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_ClearChannelDMAOverflowFlag \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel
)
{
    if(channel < 32U)
    {
        eTPUInstance[etpuGroup].eTPU->CDTROSR_A.R = 1UL<<channel;/* polyspace RTE:IDP,OBAI */
    }
    else
    {
  	  if((channel-64U) <32U)
  	  {
        eTPUInstance[etpuGroup].eTPU->CDTROSR_B.R = 1UL<<(channel-64U);/* polyspace RTE:IDP,OBAI */
  	  }
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 ETPU_LLD_GetChannelInputStatus(uint8 etpuGroup,uint8 channel)
{
    return (uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.IPS;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 ETPU_LLD_GetChannelOutputStatus(uint8 etpuGroup,uint8 channel)
{
    return (uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.OPS;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
void ETPU_LLD_SetChannelFunctionMode(uint8 etpuGroup,uint8 channel,uint8 fm)
{
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.FM0 = (uint32)fm % 1U;/* polyspace RTE:OBAI,IDP */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.FM1 = (uint32)fm % 2U;/* polyspace RTE:IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
uint8 ETPU_LLD_GetChannelFunctionMode(uint8 etpuGroup,uint8 channel)
{
    uint8 fm1;
    uint8 fm0;

    fm0 = (uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.FM0;/* polyspace RTE:OBAI,NIV,IDP */
    fm1 = (uint8)eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.B.FM1;/* polyspace RTE:NIV */

    return (uint8)((fm1<<1)|fm0);
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


/*----------------------- data ram parameter -----------------------------*/

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetDataRam
****************************************************************************//*!
* @brief   This function returns a pointer to the start of the data RAM for
*            the specified channel.
*
* @param   channel - The eTPU channel number
*
* @return  A pointer to the start of the eTPU DATA RAM allocated for the channel
*
* @warning This function does no error checking. If the channel has not been
*          initialized then an undefined value will be returned (normally 0).
******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
  uint32 *ETPU_LLD_GetDataRam(uint8 etpuGroup,
                                            uint8 channel)
{
    return((uint32*)(eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA << 3U)));     /*PRQA S 0310,3305 *//* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter32
****************************************************************************//*!
* @brief   This function writes to a 32-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
)
{
    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + offset) = value;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter32
****************************************************************************//*!
* @brief   This function reads a 32-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 32-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetGlobalParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + offset));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter24
****************************************************************************//*!
* @brief   This function writes to a 24-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
)
{
    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + (offset-1U)) = value;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter24
****************************************************************************//*!
* @brief   This function reads an unsigned 24-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The unsigned 24-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetGlobalParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset 
)
{
    return(0x00FFFFFFU & (*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + (offset-1U))));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter16
****************************************************************************//*!
* @brief   This function writes to a 16-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint16, AUTOMATIC) value
)
{
    *(uint16 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + offset) = value;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter16
****************************************************************************//*!
* @brief   This function reads a 16-bit global variable.
*
* @param   offset - The byte offset to the variable. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 16-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint16, ETPU_CODE) ETPU_LLD_GetGlobalParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint16 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + offset));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetGlobalParameter8
****************************************************************************//*!
* @brief   This function writes to an 8-bit global variable.
*
* @param   offset - The byte offset to the variable. This value is normally
*          provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetGlobalParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint8, AUTOMATIC) value
)
{
    *(uint8 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + offset) = value;/* polyspace RTE:OBAI,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetGlobalParameter8
****************************************************************************//*!
* @brief   This function reads an 8-bit global variable.
*
* @param   offset - The byte offset to the variable. This value is normally
*          provided by the eTPU compiler.
*
* @return  The 8-bit value of the variable.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetGlobalParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint8 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + offset));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter32
****************************************************************************//*!
* @brief   This function sets a 32-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
)
{
    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + offset) = value;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter32
****************************************************************************//*!
* @brief   This function reads a 32-bit parameter from an eTPU channel..
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 32-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 32-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter32 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + offset));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter24
****************************************************************************//*!
* @brief   This function sets a 24-bit parameter for an eTPU channel.
*
* @note    This function uses the sign extended location of the data memory
*          to write only 24 bits to the data memory. This 24 bit write is
*          an atomic operation and does not effect the upper 8 bits of the
*          32 bit value associated with the 24 bits
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
)
{
    *(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + (offset-1U)) = value;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter24
****************************************************************************//*!
* @brief   This function reads a unsigned 24-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 24-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The unsigned 24-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(0x00FFFFFFU & (*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + (offset-1U))));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24Address \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset 
)
{
    uint32 *u32pAddress = &eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + (offset-1U);/* polyspace RTE:OBAI,NIV,IDP */
    return (uint32)u32pAddress;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"


#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24S \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3U) + (offset-1U)));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter24S \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint32, AUTOMATIC) value
)
{
    (*(uint32 *)((uint32)eTPUInstance[etpuGroup].data_ram_ext + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3U) + (offset-1U))) = value & 0x00FFFFFFU;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint32, ETPU_CODE) ETPU_LLD_GetChannelParameter24SAddress \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
)
{
    VAR(uint32, AUTOMATIC) u32pAddress = eTPUInstance[etpuGroup].data_ram_ext + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3U) + (offset-1U);/* polyspace RTE:OBAI,NIV,IDP */
    return (uint32)u32pAddress;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter16
****************************************************************************//*!
* @brief   This function sets a 16-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint16, AUTOMATIC) value
)
{
    *(uint16 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + offset) = value;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter16
****************************************************************************//*!
* @brief   This function reads a 16-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This must be a 16-bit
*          aligned value. This value is normally provided by the eTPU compiler.
*
* @return  The 16-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint16, ETPU_CODE) ETPU_LLD_GetChannelParameter16 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint16 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + offset));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_GetChannelParameter8
****************************************************************************//*!
* @brief   This function reads an 8-bit parameter from an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This value is normally
*          provided by the eTPU compiler.
*
* @return  The 8-bit value of the parameter.
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(uint8, ETPU_CODE) ETPU_LLD_GetChannelParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset
)
{
    return(*(uint8 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + offset));/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

/*******************************************************************************
* FUNCTION: ETPU_LLD_SetChannelParameter8
****************************************************************************//*!
* @brief   This function sets an 8-bit parameter for an eTPU channel.
*
* @param   channel - The eTPU channel number
* @param   offset - The byte offset to the parameter. This value is normally
*          provided by the eTPU compiler.
* @param   value - The value to write to the parameter
*******************************************************************************/
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_LLD_SetChannelParameter8 \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) offset, \
    VAR(uint8, AUTOMATIC) value
)
{
    *(uint8 *)((uint32)eTPUInstance[etpuGroup].data_ram_start + ((uint32)eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA<<3) + offset) = value;/* polyspace RTE:OBAI,NIV,IDP */
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif
