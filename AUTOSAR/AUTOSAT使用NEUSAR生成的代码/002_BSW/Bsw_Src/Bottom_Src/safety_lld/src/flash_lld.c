/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx flash low level drivers code
* HISTORY     : Initial version
* @file     flash_lld.c
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#include "../inc/flash_lld.h" /* PRQA S 0380 */
#include "intc_lld.h"
#include "Saf_MemMap.h"
/* PRQA S 1862,1863,2753,2985,2919,3119,3408,4534 EOF */
/* Flash Swap Status */
SAF_FLASH_SEC_VAR_INIT
uint8_t saf_g_swapStatus = 0U;

/* Flash EHV value */
SAF_FLASH_SEC_VAR_INIT
uint8_t saf_g_flashSize = 1U; /* PRQA S 1533 */

/* Flash EHV value */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_VAR_INIT
    static uint8_t Saf_FLS_EHV_Val = 0U;
#else
	SAF_FLASH_SEC_VAR_INIT
    static uint8_t Saf_FLS_EHV_Val_All[FLS_CONTROLLER_NUM] = {0U};
#endif // RESOURCE_SUPPORT_PFI

#ifdef SAF_FLS_AC_LOAD
    /* Function pointer of access code */
	SAF_FLASH_SEC_VAR_NO_INIT
    static saf_fls_acload_t Saf_FLS_AcCodePtr;

    #if defined(START_FROM_FLASH)
        #ifdef FLS_AC_LOAD
        /* SRAM buffer for access code */
		SAF_FLASH_SEC_VAR_INIT
        static uint32_t Saf_FLS_AcCodeArea[128] = {0U}; /* PRQA S 3218 */
        #endif
    #endif // START_FROM_FLASH
#endif // FLS_AC_LOAD

#ifdef RESOURCE_SUPPORT_PFI
    /* The controller currently in operation */
	SAF_FLASH_SEC_VAR_NO_INIT
    static fls_blk_sel_t Saf_FLS_OpBlk;

	SAF_FLASH_SEC_VAR_INIT
    static volatile struct C55FMC_tag *saf_FLS_OpPFMC = NULL;
	SAF_FLASH_SEC_VAR_INIT
    static volatile struct C55FMC_tag *FLS_OpEFMC[FLS_CONTROLLER_NUM] = {NULL};
	SAF_FLASH_SEC_CONFIG_DATA
    static volatile struct C55FMC_tag * const flashControllerList[FLS_CONTROLLER_NUM] = {
        &FLS_FMC,

    #ifdef RESOURCE_SUPPORT_PFI0
        &FLS_T40FMC0,
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
        &FLS_T40FMC1,
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
        &FLS_T40FMC2,
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
        &FLS_T40FMC3,
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
        &FLS_T40FMC4,
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
        &FLS_T40FMC5,
    #endif // RESOURCE_SUPPORT_PFI5
    };
#endif // RESOURCE_SUPPORT_PFI

/*******************************************************************************
 * Code
 ******************************************************************************/
#ifdef SAF_FLS_AC_LOAD
    #ifndef RESOURCE_SUPPORT_PFI
    	SAF_FLASH_SEC_CODE
        static void SAF_FLS_AccessCode(void) {
            /* Set MCR EHV bit, start operation */
            FLS_FMC.MCR.B.EHV = 1U;

            /* Wait MCR DONE bit is set */
            while (FLS_FMC.MCR.B.DONE == 0x0U)
            {
            }
        }
    #else
    	SAF_FLASH_SEC_CODE
        static void SAF_FLS_AccessCode(volatile struct C55FMC_tag *fmc) {
            /* Set MCR EHV bit, start operation */
            fmc->MCR.B.EHV = 1U;/* polyspace RTE:IDP */

            /* Wait MCR DONE bit is set */
            while (fmc->MCR.B.DONE == 0x0U)/* polyspace RTE:NIV */
            {
            }
        }
    #endif // RESOURCE_SUPPORT_PFI
#endif // FLS_AC_LOAD

/*
 * @brief Get the controller Saf_FLS_EHV_Val
 *
 * This function will return the Saf_FLS_EHV_Val depend on controller
 *
 * @param[in] fmc The controller.
 * @param[in] fmc The controller.
 * @return Operation status
 */
#ifdef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_Get_FLS_EHV_Val(volatile struct C55FMC_tag *fmc, uint8_t **ehv_val) {
        uint32_t i = 0U;
        status_t ret = STATUS_ERROR;

        for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
            if (fmc == flashControllerList[i]) {
                ret = STATUS_SUCCESS;
                *ehv_val = Saf_FLS_EHV_Val_All + i;

                break;
            }
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Get the inter_write address
 *
 * This function will return the inter_write address depend on selected block
 *
 * @param[in] blkSel The selected flash block info.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
static uint32_t SAF_FLS_LLD_GetInterWriteAddr(const fls_blk_sel_t * blkSel)
{
    uint8_t i = 0U;
    uint8_t offset = 0U;
    uint32_t addr = 0U;

    if (blkSel->lowBlkSel > 0U)
    {
        offset = FLS_LOW_OFFSET;
        for (i = 0U; i < FLS_LOW_BLOCK; i++)
        {
            if (((blkSel->lowBlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart; /* PRQA S 2985 */
                break;
            }
        }
    }
    else if (blkSel->midBlkSel > 0U)
    {
        offset = FLS_MID_OFFSET; /* PRQA S 2983 */
        for (i = 0U; i < FLS_MID_BLOCK; i++) /* PRQA S 2994, 2996 */
        {
            if (((blkSel->midBlkSel & (1UL << i)) >> i) == 1UL) /* PRQA S 2880 */
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
    else if (blkSel->highBlkSel > 0U)
    {
        #if defined(CCFC3008PC)
        #else
        offset = FLS_HIGH_OFFSET;
        for (i = 0U; i < FLS_HIGH_BLOCK; i++)
        {
            if (((blkSel->highBlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
        #endif
    }
#ifndef RESOURCE_SUPPORT_PFI
    else if (blkSel->first256KBlkSel > 0U)
    {
        offset = FLS_256K_FIRST_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_FIRST; i++)
        {
            if (((blkSel->first256KBlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#if (FLS_256K_BLOCK_SECOND != 0U)
    else if (blkSel->second256KBlkSel > 0U)
    {
        offset = FLS_256K_SECOND_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_SECOND; i++)
        {
            if (((blkSel->second256KBlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
    #endif // FLS_256K_BLOCK_SECOND
#else
#ifdef RESOURCE_SUPPORT_PFI0
    else if (blkSel->large0BlkSel > 0U)
    {
        offset = FLS_256K_LARGE0_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_LARGE0; i++)
        {
            if (((blkSel->large0BlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    else if (blkSel->large1BlkSel > 0U)
    {
        offset = FLS_256K_LARGE1_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_LARGE1; i++)
        {
            if (((blkSel->large1BlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    else if (blkSel->large2BlkSel > 0U)
    {
        offset = FLS_256K_LARGE2_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_LARGE2; i++)
        {
            if (((blkSel->large2BlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    else if (blkSel->large3BlkSel > 0U)
    {
        offset = FLS_256K_LARGE3_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_LARGE3; i++)
        {
            if (((blkSel->large3BlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    else if (blkSel->large4BlkSel > 0U)
    {
        offset = FLS_256K_LARGE4_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_LARGE4; i++)
        {
            if (((blkSel->large4BlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    else if (blkSel->large5BlkSel > 0U)
    {
        offset = FLS_256K_LARGE5_OFFSET;
        for (i = 0U; i < FLS_256K_BLOCK_LARGE5; i++)
        {
            if (((blkSel->large5BlkSel & (1UL << i)) >> i) == 1UL)
            {
                addr = flashInfo[i + offset].addrStart;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI5
#endif // RESOURCE_SUPPORT_PFI
    else
    {
    }

    return addr;
}


/*
 * @brief Check the status of flash erase operate
 *
 * This function will check the status of ongoing high voltage in erase
 *
 * @param[out] pStatus The status of flash erase after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_CheckErsExec(uint8_t * pStatus)
    {
        status_t ret = STATUS_SUCCESS;
        *pStatus = SAF_FLS_OK;

        /* Check EGOOD (PEG) */
        if (FLS_FMC.MCR.B.PEG != 0U)
        {
            /* Clear EHV if it is high */
            if ( (FLS_FMC.MCR.B.EHV != 0U) || (Saf_FLS_EHV_Val == 1U) )
            {
                /* Clear EHV */
                FLS_FMC.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val = 0U;
            }
            else
            {
                *pStatus = SAF_FLS_ERS_WRITE;
            }
        }
        else
        {
            /* EGOOD (PEG) is low */
            ret = STATUS_ERROR;

            /* Clear EHV if it is high */
            if ( (FLS_FMC.MCR.B.EHV != 0U) || (Saf_FLS_EHV_Val == 1U) )
            {
                /* Clear EHV */
                FLS_FMC.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val = 0U;
            }
        }

        if (*pStatus != SAF_FLS_ERS_WRITE)
        {
            /* Clear ERS */
            FLS_FMC.MCR.B.ERS = 0U;

            /* Disable Cache */
            PFLASH.PFCR1.B.P0_BFEN = 0U;
            PFLASH.PFCR2.B.P1_BFEN = 0U;
            /* Enable Cache */
            PFLASH.PFCR1.B.P0_BFEN = 1U;
            PFLASH.PFCR2.B.P1_BFEN = 1U;
        }

        return ret;
    }
#else
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_CheckErsExec(uint8_t * pStatus, volatile struct C55FMC_tag * fmc)
    {
        status_t ret;
        uint8_t *fls_ehv_val;

        SAF_FLS_LLD_Get_FLS_EHV_Val(fmc, &fls_ehv_val);

        ret = STATUS_SUCCESS;
        *pStatus = SAF_FLS_OK;

        /* Check EGOOD (PEG) */
        if (fmc->MCR.B.PEG != 0U)/* polyspace RTE:NIV */
        {
            /* Clear EHV if it is high */
            if ( (fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U) )/* polyspace RTE:NIV *//* polyspace RTE:NIP */
            {
                /* Clear EHV */
                fmc->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;/* polyspace RTE:NIP */
            }
            else
            {
                *pStatus = SAF_FLS_ERS_WRITE;
            }
        }
        else
        {
            /* EGOOD (PEG) is low */
            ret = STATUS_ERROR;

            /* Clear EHV if it is high */
            if ( (fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U) )/* polyspace RTE:NIV *//* polyspace RTE:NIP */
            {
                /* Clear EHV */
                fmc->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;/* polyspace RTE:NIP */
            }
        }

        if (*pStatus != SAF_FLS_ERS_WRITE)
        {
            /* Clear ERS */
            fmc->MCR.B.ERS = 0U;
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Check the status of flash program operate
 *
 * This function will check the status of ongoing high voltage in program
 *
 * @param[in] pCtxData Storing context variables.
 * @param[out] pStatus The status of flash program after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_CheckPgmExec(fls_ctx_data_t * pCtxData,
                                                uint8_t * pStatus)
    {
        status_t ret = STATUS_SUCCESS;
        *pStatus = SAF_FLS_OK;

        /* check PEG */
        if (FLS_FMC.MCR.B.PEG != 0U) /* PEG is high */
        {
            /* Clear EHV if it is high */
            if ((FLS_FMC.MCR.B.EHV != 0U) || (Saf_FLS_EHV_Val == 1U))
            {
                /* Clear EHV */
                FLS_FMC.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val = 0U;
                /* If there is remaining data needs to be programmed */
                if ((pCtxData->size) != 0x0U)
                {
                    /* Call FLASH_LLD_Program to continue the operation */
                    ret = SAF_FLASH_LLD_Program(pCtxData);

                    if (ret == STATUS_SUCCESS)
                    {
                        ret = STATUS_FLASH_INPROGRESS;
                    }
                }
                else /* pCtxData->size == 0 */
                {
                    /* Program finished successfully, clear PGM */
                    FLS_FMC.MCR.B.PGM = 0U;

                    /* Disable Cache */
                    PFLASH.PFCR1.B.P0_BFEN = 0U;
                    PFLASH.PFCR2.B.P1_BFEN = 0U;
                    /* Enable Cache */
                    PFLASH.PFCR1.B.P0_BFEN = 1U;
                    PFLASH.PFCR2.B.P1_BFEN = 1U;
                }
            }
            else /* EHV == 0 */
            {
                if (FLS_FMC.MCR.B.ERS != 0U)
                {
                    *pStatus = SAF_FLS_ERS_SUS_PGM_WRITE;
                }
                else
                {
                    *pStatus = SAF_FLS_PGM_WRITE;
                }
            }
        }
        else /* PEG is low */
        {
            if ((FLS_FMC.MCR.B.EHV != 0U) || (Saf_FLS_EHV_Val == 1U))
            {
                /* Clear EHV */
                FLS_FMC.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val = 0U;
            }
            else /* EHV == 0 */
            {
                /* PEG is invalid at this stage */
                if (FLS_FMC.MCR.B.ERS != 0U)
                {
                    *pStatus = SAF_FLS_ERS_SUS_PGM_WRITE;
                }
                else
                {
                    *pStatus = SAF_FLS_PGM_WRITE;
                }
            }
            /* Program finished unsuccessfully, clear PGM */
            FLS_FMC.MCR.B.PGM = 0U;
            ret = STATUS_ERROR;

            /* Disable Cache */
            PFLASH.PFCR1.B.P0_BFEN = 0U;
            PFLASH.PFCR2.B.P1_BFEN = 0U;
            /* Enable Cache */
            PFLASH.PFCR1.B.P0_BFEN = 1U;
            PFLASH.PFCR2.B.P1_BFEN = 1U;
        }

        return ret;
    }
#else
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_CheckPgmExec(fls_ctx_data_t * pCtxData,
                                                uint8_t * pStatus)
    {
        status_t ret;
        uint8_t *fls_ehv_val;

        SAF_FLS_LLD_Get_FLS_EHV_Val(saf_FLS_OpPFMC, &fls_ehv_val);

        ret = STATUS_SUCCESS;
        *pStatus = SAF_FLS_OK;

        /* check PEG */
        if (saf_FLS_OpPFMC->MCR.B.PEG != 0U) /* polyspace RTE:NIV *//* PEG is high */
        {
            /* Clear EHV if it is high */
            if ((saf_FLS_OpPFMC->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U))/* polyspace RTE:NIV *//* polyspace RTE:NIP */
            {
                /* Clear EHV */
                saf_FLS_OpPFMC->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;/* polyspace RTE:NIP */
                /* If there is remaining data needs to be programmed */
                if ((pCtxData->size) != 0x0U)
                {
                    /* Call FLASH_LLD_Program to continue the operation */
                    ret = SAF_FLASH_LLD_Program(pCtxData);

                    if (ret == STATUS_SUCCESS)
                    {
                        ret = STATUS_FLASH_INPROGRESS;
                    }
                }
                else /* pCtxData->size == 0 */
                {
                    /* Program finished successfully, clear PGM */
                    saf_FLS_OpPFMC->MCR.B.PGM = 0U;
                }
            }
            else /* EHV == 0 */
            {
                if (saf_FLS_OpPFMC->MCR.B.ERS != 0U)/* polyspace RTE:NIV */
                {
                    *pStatus = SAF_FLS_ERS_SUS_PGM_WRITE;
                }
                else
                {
                    *pStatus = SAF_FLS_PGM_WRITE;
                }
            }
        }
        else /* PEG is low */
        {
            if ((saf_FLS_OpPFMC->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U))/* polyspace RTE:NIV *//* polyspace RTE:NIP */
            {
                /* Clear EHV */
                saf_FLS_OpPFMC->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;/* polyspace RTE:NIP */
            }
            else /* EHV == 0 */
            {
                /* PEG is invalid at this stage */
                if (saf_FLS_OpPFMC->MCR.B.ERS != 0U)/* polyspace RTE:NIV */
                {
                    *pStatus = SAF_FLS_ERS_SUS_PGM_WRITE;
                }
                else
                {
                    *pStatus = SAF_FLS_PGM_WRITE;
                }
            }
            /* Program finished unsuccessfully, clear PGM */
            saf_FLS_OpPFMC->MCR.B.PGM = 0U;
            ret = STATUS_ERROR;
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Execute program operation
 *
 * This function will do program operation
 *
 * @param[in] pCtxData Storing context variables.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_PgmExec(fls_ctx_data_t * pCtxData)
    {
        status_t ret = STATUS_SUCCESS;
        uint32_t srcIndex;
        uint32_t temp;

        if (0U != pCtxData->size)
        {
            /* Set MCR_PGM to start program operation */
            FLS_FMC.MCR.B.PGM = 1U;

            if (FLS_FMC.MCR.B.PGM == 0U)
            {
                ret = STATUS_FLASH_ERROR_ENABLE;
            }
            else
            {
                /* Disable Cache */
                PFLASH.PFCR1.B.P0_BFEN = 0U;
                PFLASH.PFCR2.B.P1_BFEN = 0U;

                /* Compute the buffer size used in the program cycle and calculate number of word for interlock write */
                if (pCtxData->size > SAF_FLS_PROGRAMABLE_SIZE)
                {
                    temp = SAF_FLS_PROGRAMABLE_SIZE / SAF_FLS_WORD_SIZE;
                }
                else
                {
                    temp = pCtxData->size / SAF_FLS_WORD_SIZE;
                }

                /* Program data */
                for (srcIndex = 0U; srcIndex < temp; srcIndex++)
                {
                    /* Programming write */
                    *(volatile uint32_t *)(pCtxData->dest) = *(volatile uint32_t *)(pCtxData->src);/* polyspace RTE:NIV,IDP */
                    /* Update dest, size, source index */
                    pCtxData->dest += SAF_FLS_WORD_SIZE;
                    pCtxData->src += SAF_FLS_WORD_SIZE;
                    pCtxData->size -= SAF_FLS_WORD_SIZE;

                    /* Is it time to do page programming?  */
                    if (0U == (pCtxData->dest % SAF_FLS_PROGRAMABLE_SIZE))
                    {
                        break;
                    }
                }

                /* Set MCR_EHV bit */
                if (SAF_FLS_OP_SYNC == pCtxData->mode)
                {
                    INTC_LLD_Set_Global_Disable();
                    Saf_FLS_AcCodePtr();
                    INTC_LLD_Set_Global_Enable();
                }
                else
                {
                    FLS_FMC.MCR.B.EHV = 1U;
                }
            }
        }
        else
        {
        }

        return ret;
    }
#else
	SAF_FLASH_SEC_CODE
    static status_t SAF_FLS_LLD_PgmExec(fls_ctx_data_t * pCtxData, volatile struct C55FMC_tag *fmc)
    {
        status_t ret = STATUS_SUCCESS;
        uint32_t srcIndex;
        uint32_t temp;

        if (0U != pCtxData->size)
        {
            /* Set MCR_PGM to start program operation */
            fmc->MCR.B.PGM = 1U;

            if (fmc->MCR.B.PGM == 0U)
            {
                ret = STATUS_FLASH_ERROR_ENABLE;
            }
            else
            {
                /* Compute the buffer size used in the program cycle and calculate number of word for interlock write */
                if (pCtxData->size > SAF_FLS_PROGRAMABLE_SIZE)
                {
                    temp = SAF_FLS_PROGRAMABLE_SIZE / SAF_FLS_WORD_SIZE;
                }
                else
                {
                    temp = pCtxData->size / SAF_FLS_WORD_SIZE;
                }

                /* Program data */
                for (srcIndex = 0U; srcIndex < temp; srcIndex++)
                {
                    /* Programming write */
                    *(volatile uint32_t *)(pCtxData->dest) = *(volatile uint32_t *)(pCtxData->src);/* polyspace RTE:NIV,IDP */
                    /* Update dest, size, source index */
                    pCtxData->dest += SAF_FLS_WORD_SIZE;
                    pCtxData->src += SAF_FLS_WORD_SIZE;
                    pCtxData->size -= SAF_FLS_WORD_SIZE;

                    /* Is it time to do page programming?  */
                    if (0U == (pCtxData->dest % SAF_FLS_PROGRAMABLE_SIZE))
                    {
                        break;
                    }
                }

                /* Set MCR_EHV bit */
                if (SAF_FLS_OP_SYNC == pCtxData->mode)
                {
                    INTC_LLD_Set_Global_Disable();
                    Saf_FLS_AcCodePtr(fmc);
                    INTC_LLD_Set_Global_Enable();
                }
                else
                {
                    fmc->MCR.B.EHV = 1U;
                }
            }
        }
        else
        {
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Execute suspend operation
 *
 * This function will suspend the program, erase activities
 *
 * @param[out] susStatus The status of suspend after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    static void SAF_FLS_LLD_SusExec(uint8_t * susStatus)
    {
        uint16_t susDelay = 0U;
        uint32_t i = 450U;

        if (FLS_FMC.MCR.B.EHV == 0U)
        {
            if (FLS_FMC.MCR.B.PGM != 0U)
            {
                *susStatus = SAF_FLS_PGM_WRITE;

                if (FLS_FMC.MCR.B.ERS != 0U)
                {
                    *susStatus = SAF_FLS_ERS_SUS_PGM_WRITE;
                }
            }
            else
            {
                *susStatus = SAF_FLS_ERS_WRITE;
            }
            /* Wait MCR DONE bit is set */
            while ((FLS_FMC.MCR.B.DONE == 0x0U) && (i > 0U))
            {
                i--;
            }
        }
        else
        {
            if (FLS_FMC.MCR.B.PGM != 0x0U)
            {
                /* Set MCR_PSUS bit */
                FLS_FMC.MCR.B.PSUS = 1U;
                for (susDelay = 0U; susDelay < 160U; susDelay++)
                {}
            }
            else
            {
                /* Set MCR-ESUS bit */
                FLS_FMC.MCR.B.ESUS = 1U;
                for (susDelay = 0U; susDelay < 320U; susDelay++)
                {}
            }
        }
    }
#else
	SAF_FLASH_SEC_CODE
    static void SAF_FLS_LLD_SusExec(uint8_t * susStatus, volatile struct C55FMC_tag *fmc)
    {
        uint16_t susDelay = 0U;
        uint32_t i = 450U;

        if (fmc->MCR.B.EHV == 0U)
        {
            if (fmc->MCR.B.PGM != 0U)
            {
                *susStatus = SAF_FLS_PGM_WRITE;

                if (fmc->MCR.B.ERS != 0U)
                {
                    *susStatus = SAF_FLS_ERS_SUS_PGM_WRITE;
                }
            }
            else
            {
                *susStatus = SAF_FLS_ERS_WRITE;
            }
            /* Wait MCR DONE bit is set */
            while ((fmc->MCR.B.DONE == 0x0U) && (i > 0U))
            {
                i--;
            }
        }
        else
        {
            if (fmc->MCR.B.PGM != 0x0U)
            {
                /* Set MCR_PSUS bit */
                fmc->MCR.B.PSUS = 1U;
                for (susDelay = 0U; susDelay < 160U; susDelay++)
                {}
            }
            else
            {
                /* Set MCR-ESUS bit */
                fmc->MCR.B.ESUS = 1U;
                for (susDelay = 0U; susDelay < 320U; susDelay++)
                {}
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Config Flash Calibration Region Descriptor
 *
 * This function will config flash calibration region descriptor.
 *
 * @param[in] cdrIndex: The Index of Calibration Remap Descriptor.
 * @param[in] remapConfig: The config of Calibration Region Descriptor.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
static status_t SAF_FLS_LLD_OverlayConfig(uint32_t cdrIndex, flash_remap_config_t const *remapConfig)
{
    status_t ret = STATUS_SUCCESS;

    /* check flash region count */
    if (cdrIndex < PFLASH_PFCRD_COUNT)
    {
        /* set the Logical Start Address, ensure the most 4-bit LSB are 0*/
        PFLASH.PFCRD[cdrIndex].Word0.R = remapConfig->flsLogicAddr&0xFFFFFFF0U;

        /* set the Physical Start Address, ensure the most 4-bit LSB are 0*/
        PFLASH.PFCRD[cdrIndex].Word1.R = remapConfig->ramPhyAddr&0xFFFFFFF0U;

        /* enable Crossbar master and configure the region size*/
        PFLASH.PFCRD[cdrIndex].Word2.R = 0xFFFF0000U|(uint32_t)(remapConfig->remapSize);

        /* enable the corresponding Calibration Remap Descriptor */
        PFLASH.PFCRDE.R |= ((uint32_t)(1UL<<(31U-cdrIndex)))&0xFFFFFFFFU; /* PRQA S 2985 */
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}

#ifdef RESOURCE_SUPPORT_PFI
/*
 * @brief Get Flash Block Offset
 *
 * This function will get flash block offset.
 *
 * @param[in]  blkSel: The Selector of Block.
 * @param[out] offset: The Offset of Selected Block.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
static status_t SAF_FLS_LLD_GetBlockOffset(uint8_t blkSel, uint32_t *offset) {
    status_t ret = STATUS_SUCCESS;

    switch (blkSel) {
        case SAF_FLS_BLK_LOW:
            *offset = FLS_LOW_OFFSET;
            break;

        case SAF_FLS_BLK_MID:
            *offset = FLS_MID_OFFSET;
            break;

        case SAF_FLS_BLK_HIGH:
            *offset = FLS_HIGH_OFFSET;
            break;

    #ifdef RESOURCE_SUPPORT_PFI0
        case SAF_FLS_BLK_LARGE0_256K:
            *offset = FLS_256K_LARGE0_OFFSET;
            break;
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
        case SAF_FLS_BLK_LARGE1_256K:
            *offset = FLS_256K_LARGE1_OFFSET;
            break;
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
        case SAF_FLS_BLK_LARGE2_256K:
            *offset = FLS_256K_LARGE2_OFFSET;
            break;
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
        case SAF_FLS_BLK_LARGE3_256K:
            *offset = FLS_256K_LARGE3_OFFSET;
            break;
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
        case SAF_FLS_BLK_LARGE4_256K:
            *offset = FLS_256K_LARGE4_OFFSET;
            break;
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
        case SAF_FLS_BLK_LARGE5_256K:
            *offset = FLS_256K_LARGE5_OFFSET;
            break;
    #endif // RESOURCE_SUPPORT_PFI5

        default:
            ret = STATUS_ERROR;
            break;
    }

    return ret;
}

/*
 * @brief Get Flash Block Controller
 *
 * This function will get flash block controller.
 *
 * @param[in]  blk: The Index of Block.
 * @param[out] controller: The Controller of Selected Block.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
static status_t SAF_FLS_LLD_GetBlockController(uint32_t blk, volatile struct C55FMC_tag **controller) {
    status_t ret = STATUS_SUCCESS;
    const saf_flash_block_map_t *block_map = NULL;

    if (blk >= FLS_BLOCK_ALL) {
        return STATUS_ERROR;
    }

    if (saf_g_swapStatus == 0U) {
        block_map = saf_flashBlockMap0;
    } else {
        block_map = saf_flashBlockMap1;
    }

    *controller = block_map[blk].controller;

    return ret;
}

/*
 * @brief Get Mapped Controller
 *
 * This function will get mapped controller.
 *
 * @param[in]  controller: The Target Controller.
 * @param[out] mapped_controller: The Mapped Controller.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
static status_t SAF_FLS_LLD_GetMappedController(volatile struct C55FMC_tag *controller, volatile struct C55FMC_tag **mapped_controller) {
    uint32_t i = 0U;
    status_t ret = STATUS_ERROR;
    const saf_flash_controller_map_t *controller_map = NULL;

    if (saf_g_swapStatus == 0U) {
        controller_map = saf_flashControllerMap0;
    } else {
        controller_map = saf_flashControllerMap1;
    }

    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        if (controller_map[i].controller == controller) {
            ret = STATUS_SUCCESS;
            *mapped_controller = controller_map[i].mapped_controller;

            break;
        }
    }

    return ret;
}

/*
 * @brief Get Mapped Port
 *
 * This function will get mapped port.
 *
 * @param[in]  port: The Target Port.
 * @param[out] mapped_port: The Mapped Port.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
static status_t SAF_FLS_LLD_GetMappedPort(uint32_t port, uint32_t *mapped_port) {
    uint32_t i = 0U;
    status_t ret = STATUS_SUCCESS;
    const saf_flash_port_map_t *port_map = NULL;

    if (port >= FLS_PORT_MAX) {
        ret = STATUS_ERROR;
        return ret;
    }

    if (saf_g_swapStatus == 0U) {
        port_map = flashPortMap0;
    } else {
        port_map = flashPortMap1;
    }

    *mapped_port = port_map[i].mapped_port;

    return ret;
}
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Check the program operation
 *
 * This function will check the status of ongoing program operation.
 *
 * @param[in] pCtxData: Storing context variables.
 * @param[out] opRet: Return the status of flash.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    status_t SAF_FLASH_LLD_CheckProgramStatus(fls_ctx_data_t * pCtxData,
                                        uint8_t * opRet)
    {
        status_t ret = STATUS_SUCCESS;

        if ( (pCtxData == NULL) || (opRet == NULL))
        {
            ret = STATUS_ERROR;
            return ret;
        }

        *opRet = SAF_FLS_OK;

        /* There must be a program operation */
        if (FLS_FMC.MCR.B.PGM != 0U)
        {
            /* If DONE bit goes high */
            if (FLS_FMC.MCR.B.DONE != 0U)
            {
                /* If the operation is suspended */
                if (FLS_FMC.MCR.B.PSUS != 0U)
                {
                    /* Check if the suspended program is PGM_SUS or ERS_SUS_PGM_SUS */
                    if (FLS_FMC.MCR.B.ERS != 0U)
                    {
                        *opRet = SAF_FLS_ERS_SUS_PGM_SUS;
                    }
                    else
                    {
                        *opRet = SAF_FLS_PGM_SUS;
                    }
                }
                else
                {
                    ret = SAF_FLS_LLD_CheckPgmExec(pCtxData, opRet);
                }
            }
            else
            {
                /* DONE bit is still low means the operation is in-progress */
                ret = STATUS_FLASH_INPROGRESS;
            }
        }

        return ret;
    }
#else
	SAF_FLASH_SEC_CODE
    status_t SAF_FLASH_LLD_CheckProgramStatus(fls_ctx_data_t * pCtxData,
                                        uint8_t * opRet)
    {
        status_t ret = STATUS_SUCCESS;

        if ( (pCtxData == NULL) || (opRet == NULL))
        {
            ret = STATUS_ERROR;
            return ret;
        }

        *opRet = SAF_FLS_OK;

        /* There must be a program operation */
        if ((saf_FLS_OpPFMC != NULL) && (saf_FLS_OpPFMC->MCR.B.PGM != 0U))/* polyspace RTE:NIV */
        {
            /* If DONE bit goes high */
            if (saf_FLS_OpPFMC->MCR.B.DONE != 0U)/* polyspace RTE:NIV */
            {
                /* If the operation is suspended */
                if (saf_FLS_OpPFMC->MCR.B.PSUS != 0U)/* polyspace RTE:NIV */
                {
                    /* Check if the suspended program is PGM_SUS or ERS_SUS_PGM_SUS */
                    if (saf_FLS_OpPFMC->MCR.B.ERS != 0U)/* polyspace RTE:NIV */
                    {
                        *opRet = SAF_FLS_ERS_SUS_PGM_SUS;
                    }
                    else
                    {
                        *opRet = SAF_FLS_PGM_SUS;
                    }
                }
                else
                {
                    ret = SAF_FLS_LLD_CheckPgmExec(pCtxData, opRet);
                }
            }
            else
            {
                /* DONE bit is still low means the operation is in-progress */
                ret = STATUS_FLASH_INPROGRESS;
            }
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Check the erase operation
 *
 * This function will check the status of ongoing erase operation.
 *
 * @param[out] opRet: Return the state of flash.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_CheckEraseStatus(uint8_t * opRet)
{
    status_t ret = STATUS_SUCCESS;

#ifdef RESOURCE_SUPPORT_PFI
    uint32_t i = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if (opRet == NULL)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    *opRet = SAF_FLS_OK;

#ifndef RESOURCE_SUPPORT_PFI
    /* There must be an erase operation */
    if (FLS_FMC.MCR.B.ERS != 0U)
    {
        /* If DONE bit goes high */
        if (FLS_FMC.MCR.B.DONE != 0U)
        {
            /* If the operation is suspended */
            if (FLS_FMC.MCR.B.ESUS != 0U)
            {
                *opRet = SAF_FLS_ERS_SUS;
            }
            else
            {
                ret = SAF_FLS_LLD_CheckErsExec(opRet);
            }
        }
        else
        {
            /* DONE bit is still low means the operation is in-progress */
            ret = STATUS_FLASH_INPROGRESS;
        }
    }
#else
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[i];

        if (fmc == NULL) {
            continue;
        }

        /* There must be an erase operation */
        if (fmc->MCR.B.ERS != 0U) {/* polyspace RTE:NIV,IDP */
            /* If DONE bit goes high */
            if (fmc->MCR.B.DONE != 0U) {/* polyspace RTE:NIV */
                /* If the operation is suspended */
                if (fmc->MCR.B.ESUS != 0U) {/* polyspace RTE:NIV */
                    *opRet = SAF_FLS_ERS_SUS;
                } else {
                    ret = SAF_FLS_LLD_CheckErsExec(opRet, fmc);

                    if (ret != STATUS_SUCCESS) {
                        break;
                    }
                }
            } else {
                /* DONE bit is still low means the operation is in-progress */
                ret = STATUS_FLASH_INPROGRESS;
                break;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    return ret;
}

/*
 * @brief Initializes the FLASH module
 *
 * This function will initialize flash module.
 *
 * @param[in] lockBlk: Indicating the lock status of flash module.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Init(const uint8_t * lockBlk)
{
    status_t ret = STATUS_SUCCESS;
    uint32_t i = 0;

#ifndef RESOURCE_SUPPORT_PFI
    uint32_t lockValue = 0U;
    uint32_t lock2 = 0U;
#endif // RESOURCE_SUPPORT_PFI

    /* unLock Flash Block*/
    FLS_FMC.LOCK0.B.LOWLOCK = 0U;
    FLS_FMC.LOCK0.B.MIDLOCK = 0U;

    #if defined(CCFC3008PCSN)
    FLS_FMC.LOCK1.B.LOWLOCK = 0U;
    #else
    FLS_FMC.LOCK1.B.HIGHLOCK = 0U;
    #endif // CCFC3008PCSN

#ifndef RESOURCE_SUPPORT_PFI
    #if defined(CCFC3008PC) || defined(CCFC3008PCSN)
    *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;/* polyspace RTE:IDP */
    *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;/* polyspace RTE:IDP */
    *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;/* polyspace RTE:IDP */
    *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;/* polyspace RTE:IDP */

    FLS_FMC.LOCK1.B.MTLOCK = 0xFFFFU; // for the info block, setting the bit to 1 is unlocking
    #endif // CCFC3008PC

    FLS_FMC.LOCK2.B.A256KLOCK = 0U;
    FLS_FMC.LOCK3.B.A256KLOCK = 0U;

    #if defined(CCFC3008PCSN)
    FLS_FMC.LOCK4.B.MIDLOCK = 0U;
    #endif // CCFC3008PCSN

    /* lock Flash Block*/
    for (i = 0; i < FLS_BLOCK_ALL; i++)
    {
        if (1U == lockBlk[i]) /* PRQA S 0492 */
        {
            if (0U == flashInfo[i].lockSelReg)
            {
                FLS_FMC.LOCK0.R |= (1UL << flashInfo[i].lockSelBit);
            }
            else if (1U == flashInfo[i].lockSelReg)
            {
            #if defined(CCFC3008PC)
                *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;
                *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;
                *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;
                *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;
                FLS_FMC.LOCK1.R &= (~(1UL << flashInfo[i].lockSelBit));
            #elif defined(CCFC3008PCSN)
                if (flashInfo[i].lockSelBit < FLS_LOCK_OFFSET_MIT)
                {
                    FLS_FMC.LOCK1.R |= (1UL << flashInfo[i].lockSelBit);
                }
                else
                {
                    *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;/* polyspace RTE:IDP */
                    *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;/* polyspace RTE:IDP */
                    *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;/* polyspace RTE:IDP */
                    *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;/* polyspace RTE:IDP */
                    FLS_FMC.LOCK1.R &= (~(1UL << flashInfo[i].lockSelBit));
                }
            #else
                FLS_FMC.LOCK1.R |= (1UL << flashInfo[i].lockSelBit);
            #endif // CCFC3008PC || CCFC3008PCSN
            }
            else if (2U == flashInfo[i].lockSelReg)
            {
                lockValue |= (1UL << flashInfo[i].lockSelBit);
            }
            else if (3U == flashInfo[i].lockSelReg)
            {
                FLS_FMC.LOCK3.R |= (1UL << flashInfo[i].lockSelBit);
            }
            #if defined(CCFC3008PCSN)
            else if (4U == flashInfo[i].lockSelReg)
            {
                FLS_FMC.LOCK4.R |= (1UL << flashInfo[i].lockSelBit);
            }
            #endif // CCFC3008PCSN
            else
            {
                /* No operation */
            }
        }
    }

    #if defined(CCFC3008PT)
        /* If Swapped to B partition */
        if (1U == g_swapStatus)
        {
            lock2 = (((lockValue >> 8U) & 0x000000FFU) | ((lockValue << 8U) & 0x0000FF00U));
        }
        else
        {
            lock2 = lockValue & FLS_LOCK_MASK_FIR256K;
        }
    #else
        lock2 = lockValue & FLS_LOCK_MASK_FIR256K;
    #endif // CCFC3008PT

    FLS_FMC.LOCK2.R = lock2;
#else
    saf_FLS_OpPFMC = NULL;
    cc_memset((uint8_t *)(&FLS_OpEFMC), NULL, sizeof(FLS_OpEFMC));

    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        if (flashControllerList[i] != &FLS_FMC) {
            flashControllerList[i]->LOCK2.B.A256KLOCK = 0U;
        }
    }

    /* lock Flash Block*/
    for (i = 0U; i < FLS_BLOCK_ALL; i++)
    {
        if (0U == lockBlk[i]) {
            continue;
        }

        if (i < FLS_HIGH_OFFSET + FLS_HIGH_BLOCK) { // C55FMC
            if (0U == flashInfo[i].lockSelReg) {
                FLS_FMC.LOCK0.R |= (1UL << flashInfo[i].lockSelBit);
            } else if (1U == flashInfo[i].lockSelReg) {
                FLS_FMC.LOCK1.R |= (1UL << flashInfo[i].lockSelBit);
            } else {
                // No operation
            }
        } else {                          // T40FMC
            volatile struct C55FMC_tag *controller = NULL;

            SAF_FLS_LLD_GetBlockController(i, &controller);
            controller->LOCK2.R |= (1UL << flashInfo[i].lockSelBit);/* polyspace RTE:NIV */
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    /* Clear error bits */
#ifndef RESOURCE_SUPPORT_PFI
    FLS_FMC.MCR.B.EER = 1U;
    FLS_FMC.MCR.B.RWE = 1U;
    FLS_FMC.MCR.B.SBC = 1U;
    FLS_FMC.MCR.B.RVE = 1U;
    FLS_FMC.MCR.B.RRE = 1U;
    FLS_FMC.MCR.B.AEE = 1U;
    FLS_FMC.MCR.B.EEE = 1U;
#else
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        flashControllerList[i]->MCR.B.EER = 1U;
        flashControllerList[i]->MCR.B.RWE = 1U;
        flashControllerList[i]->MCR.B.SBC = 1U;
        flashControllerList[i]->MCR.B.RVE = 1U;
        flashControllerList[i]->MCR.B.RRE = 1U;
        flashControllerList[i]->MCR.B.AEE = 1U;
        flashControllerList[i]->MCR.B.EEE = 1U;
    }
#endif // RESOURCE_SUPPORT_PFI

#ifdef FLS_AC_LOAD
    #if defined(START_FROM_FLASH)
        /* Copy Flash Access Code to SRAM */
        uint32_t * RomPtr = (uint32_t *)&SAF_FLS_AccessCode; /* PRQA S 0307,3678 */
        uint32_t * RomEndPtr = RomPtr + (sizeof(Saf_FLS_AcCodeArea)/4U); /* PRQA S 3678 */
        uint32_t * RamPtr = (uint32_t *)Saf_FLS_AcCodeArea;

        for (; (uint32_t)RomPtr < (uint32_t)RomEndPtr; RomPtr++)
        {
            *RamPtr = *RomPtr;
            RamPtr++;
        }

        Saf_FLS_AcCodePtr = (saf_fls_acload_t)&Saf_FLS_AcCodeArea; /* PRQA S 0307 */
    #else
        /* If Flash Access Code in SRAM */
        Saf_FLS_AcCodePtr = (saf_fls_acload_t)&Saf_AccessCode;
    #endif // START_FROM_FLASH
#endif // FLS_AC_LOAD

    /* Flash interrupt Initialize */
#ifndef RESOURCE_SUPPORT_PFI
    ret = INTC_LLD_Set_IRQ_Priority(FLASH_MCR_DONE_IRQn, INTR_PRI_1);
    if (ret != STATUS_SUCCESS)
    {
        return ret;
    }

    ret = INTC_LLD_Set_IRQ_Handle(FLASH_MCR_DONE_IRQn, &SAF_FLASH_Cmd_Done_ISR);
    if (ret != STATUS_SUCCESS)
    {
        return ret;
    }

    ret = INTC_LLD_Set_IRQ_Enable(FLASH_MCR_DONE_IRQn);
    if (ret != STATUS_SUCCESS)
    {
        return ret;
    }
#else
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        IntrId intr_id;
        IntrHandle intr_handle = NULL;

        switch ((uint32_t)(flashControllerList[i])) {
            case SAF_FLS_FMC_BASE: {
                intr_id = FLASH_MCR_DONE_IRQn;
                intr_handle = SAF_FLASH_Cmd_Done_ISR;

                break;
            }

        #ifdef RESOURCE_SUPPORT_PFI0
            case SAF_FLS_T40FMC0_BASE: {
                intr_id = CFLASH_PFI0_FGF_PECI_IRQn;
                intr_handle = SAF_FLASH_PFI0_Cmd_Done_ISR;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI0

        #ifdef RESOURCE_SUPPORT_PFI1
            case SAF_FLS_T40FMC1_BASE: {
                intr_id = CFLASH_PFI1_FGF_PECI_IRQn;
                intr_handle = SAF_FLASH_PFI1_Cmd_Done_ISR;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI1

        #ifdef RESOURCE_SUPPORT_PFI2
            case SAF_FLS_T40FMC2_BASE: {
                intr_id = CFLASH_PFI2_FGF_PECI_IRQn;
                intr_handle = SAF_FLASH_PFI2_Cmd_Done_ISR;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI2

        #ifdef RESOURCE_SUPPORT_PFI3
            case SAF_FLS_T40FMC3_BASE: {
                intr_id = CFLASH_PFI3_FGF_PECI_IRQn;
                intr_handle = SAF_FLASH_PFI3_Cmd_Done_ISR;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI3

        #ifdef RESOURCE_SUPPORT_PFI4
            case SAF_FLS_T40FMC4_BASE: {
                intr_id = CFLASH_PFI4_FGF_PECI_IRQn;
                intr_handle = SAF_FLASH_PFI4_Cmd_Done_ISR;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI4

        #ifdef RESOURCE_SUPPORT_PFI5
            case SAF_FLS_T40FMC5_BASE: {
                intr_id = CFLASH_PFI5_FGF_PECI_IRQn;
                intr_handle = SAF_FLASH_PFI5_Cmd_Done_ISR;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI5

            default: {
                break;
            }
        }

        if (intr_handle != NULL) {
            ret = INTC_LLD_Set_IRQ_Priority(intr_id, INTR_PRI_1);
            if (ret != STATUS_SUCCESS)
            {
                return ret;
            }

            ret = INTC_LLD_Set_IRQ_Handle(intr_id, intr_handle);
            if (ret != STATUS_SUCCESS)
            {
                return ret;
            }

            ret = INTC_LLD_Set_IRQ_Enable(intr_id);
            if (ret != STATUS_SUCCESS)
            {
                return ret;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    return ret;
}

SAF_FLASH_SEC_CODE
void SAF_FLASH_LLD_SafOperationInit(void)
{
    Saf_FLS_AcCodePtr = (saf_fls_acload_t)&SAF_FLS_AccessCode;
}

/*
 * @brief Get flash block lock status
 *
 * This function will get the lock status for selected flash block.
 *
 * @param[in] lockedBlkSel: Select the special flash block.
 * @param[out] lockedBlkStatus: Return lock status of selected flash block.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_GetLock(uint8_t lockedBlkSel,
                           uint32_t * lockedBlkStatus)
{
    status_t ret = STATUS_SUCCESS;

#ifndef RESOURCE_SUPPORT_PFI
    uint32_t lockValue = 0U;

    /* Determine which address space is selected */
    switch (lockedBlkSel)
    {
        case SAF_FLS_BLK_LOW:
        #if defined(CCFC3008PC)
        {
            uint32_t temp;

            temp = (FLS_FMC.LOCK0.B.LOWLOCK & (FLS_LOCK_MASK_LOW | (3U << 8U)));
            *lockedBlkStatus = ((temp & 0x1EU) >> 1U) | ((temp & 0x3C0) >> 2U);
            break;
        }
        #elif defined(CCFC3008PCSN)
            *lockedBlkStatus = ((FLS_FMC.LOCK0.B.LOWLOCK & FLS_LOCK_MASK_LOW0) | \
                               ((FLS_FMC.LOCK1.B.LOWLOCK & FLS_LOCK_MASK_LOW1) << FLS_LOCK_OFFSET_LOW));
            break;
        #else
            *lockedBlkStatus = (FLS_FMC.LOCK0.B.LOWLOCK & FLS_LOCK_MASK_LOW);
            break;
        #endif // CCFC3008PC || CCFC3008PCSN
        case SAF_FLS_BLK_MID:
        #if defined(CCFC3008PC)
            *lockedBlkStatus = ((~((uint32_t)(FLS_FMC.LOCK1.R) >> FLS_LOCK_OFFSET_MID)) & FLS_LOCK_MASK_MID);
        #elif defined(CCFC3008PCSN)
            *lockedBlkStatus = ((uint32_t)(FLS_FMC.LOCK4.B.MIDLOCK) & FLS_LOCK_MASK_MID);
        #else
            *lockedBlkStatus = (((uint32_t)(FLS_FMC.LOCK0.B.MIDLOCK) >> FLS_LOCK_OFFSET_MID) & FLS_LOCK_MASK_MID);
        #endif // CCFC3008PC || CCFC3008PCSN
            break;
        case SAF_FLS_BLK_HIGH:
		#ifndef CCFC3008PC
        #if defined(CCFC3008PCSN)
            *lockedBlkStatus = ((FLS_FMC.LOCK0.B.MIDLOCK & FLS_LOCK_MASK_HIGH0) | \
                               (((~(uint32_t)(FLS_FMC.LOCK1.B.MTLOCK)) & FLS_LOCK_MASK_HIGH1) << FLS_LOCK_OFFSET_HIGH));
        #else
            *lockedBlkStatus = (FLS_FMC.LOCK1.B.HIGHLOCK & FLS_LOCK_MASK_HIGH);
        #endif // CCFC3008PCSN
		#endif // CCFC3008PC
            break;
        case SAF_FLS_BLK_FIRST_256K:
            lockValue = (FLS_FMC.LOCK2.B.A256KLOCK & FLS_LOCK_MASK_FIR256K);
        #if defined(CCFC3008PT)
            /* If Swapped to B partition */
            if (1U == g_swapStatus)
            {
                *lockedBlkStatus = (((lockValue >> 8U) & 0x000000FFU) | ((lockValue << 8U) & 0x0000FF00U));
            }
            else
            {
                *lockedBlkStatus = lockValue;
            }
        #else
            *lockedBlkStatus = lockValue;
        #endif // CCFC3008PT
            break;
        case SAF_FLS_BLK_SECOND_256K:
            *lockedBlkStatus = (FLS_FMC.LOCK3.R & FLS_LOCK_MASK_SEC256K); /* PRQA S 0499 */
            break;
        default:
            ret = STATUS_ERROR;
            break;
    }
#else
    /* Determine which address space is selected */
    switch (lockedBlkSel)
    {
        case SAF_FLS_BLK_LOW:
            *lockedBlkStatus = (FLS_FMC.LOCK0.B.LOWLOCK & FLS_LOCK_MASK_LOW);
            break;
        case SAF_FLS_BLK_MID:
            *lockedBlkStatus = (((uint32_t)(FLS_FMC.LOCK0.B.MIDLOCK) >> FLS_LOCK_OFFSET_MID) & FLS_LOCK_MASK_MID);
            break;
        case SAF_FLS_BLK_HIGH:
            *lockedBlkStatus = (FLS_FMC.LOCK1.B.HIGHLOCK & FLS_LOCK_MASK_HIGH);
            break;

        default: {
            uint32_t blk_offset;
            ret = SAF_FLS_LLD_GetBlockOffset(lockedBlkSel, &blk_offset);

            if (ret == STATUS_SUCCESS) {
                volatile struct C55FMC_tag *controller = NULL;

                SAF_FLS_LLD_GetBlockController(blk_offset, &controller);
                *lockedBlkStatus = (controller->LOCK2.B.A256KLOCK & FLS_SEL_MASK_LARGE_256K);/* polyspace RTE:NIV */
            }

            break;
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    return ret;
}

/*
 * @brief Set flash block lock status
 *
 * This function will set the lock status for selected flash block.
 *
 * @param[in] lockedBlkSel: Select the special flash block.
 * @param[in] lockedBlkStatus: The lock status will set to the selected flash block.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_SetLock(uint8_t lockedBlkSel,
                           uint32_t lockedBlkStatus)
{
    status_t ret = STATUS_SUCCESS;
    uint32_t value = 0x0U;                   /* value of block lock */

    /* Check which address space need to set lock, then:
     * 1. Clear block lock field.
     * 2. Set block lock field.
     * 3. Check block lock field.
     * */
#ifndef RESOURCE_SUPPORT_PFI
    switch (lockedBlkSel)
    {
        case SAF_FLS_BLK_LOW:
        #if defined(CCFC3008PC)
        {
            uint32_t temp1, temp2;

            value = lockedBlkStatus & FLS_LOCK_MASK_LOW;

            FLS_FMC.LOCK0.B.LOWLOCK = 0U;
            FLS_FMC.LOCK0.B.LOWLOCK = ((value & 0xFU) << 1U) | ((value & 0xF0U) << 2U);

            temp1 = (FLS_FMC.LOCK0.B.LOWLOCK & (FLS_LOCK_MASK_LOW | (3U << 8U)));
            temp2 = ((temp1 & 0x1EU) >> 1U) | ((temp1 & 0x3C0) >> 2U);

            if (temp2 != value)
            {
                ret = STATUS_ERROR;
            }
            break;
        }
        #elif defined(CCFC3008PCSN)
        {
            uint32_t temp1, temp2;

            value = lockedBlkStatus & FLS_LOCK_MASK_LOW;

            temp1 = value & FLS_LOCK_MASK_LOW0;
            temp2 = (value >> FLS_LOCK_OFFSET_LOW) & FLS_LOCK_MASK_LOW1;

            FLS_FMC.LOCK0.B.LOWLOCK = 0U;
            FLS_FMC.LOCK0.B.LOWLOCK = temp1;

            FLS_FMC.LOCK1.B.LOWLOCK = 0U;
            FLS_FMC.LOCK1.B.LOWLOCK = temp2;

            if (((FLS_FMC.LOCK0.B.LOWLOCK & FLS_LOCK_MASK_LOW0) != temp1) || \
                ((FLS_FMC.LOCK1.B.LOWLOCK & FLS_LOCK_MASK_LOW1) != temp2))
            {
                ret = STATUS_ERROR;
            }
            break;
        }
        #else
            value = lockedBlkStatus & FLS_LOCK_MASK_LOW;
            FLS_FMC.LOCK0.B.LOWLOCK = 0U;
            FLS_FMC.LOCK0.B.LOWLOCK = value;
            if ((FLS_FMC.LOCK0.B.LOWLOCK & FLS_LOCK_MASK_LOW) != value)
            {
                ret = STATUS_ERROR;
            }
            break;
        #endif // CCFC3008PC || CCFC3008PCSN
        case SAF_FLS_BLK_MID:
        #if defined(CCFC3008PC)
            *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;
            *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;
            *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;
            *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;

            value = ((~lockedBlkStatus) & FLS_LOCK_MASK_MID); /* PRQA S 2984, 2790 */
            FLS_FMC.LOCK1.B.MTLOCK = 0U;
            FLS_FMC.LOCK1.R |= (value << FLS_LOCK_OFFSET_MID);
            if ((FLS_FMC.LOCK1.R & (FLS_LOCK_MASK_MID << FLS_LOCK_OFFSET_MID)) != (value << FLS_LOCK_OFFSET_MID)) /* PRQA S 2790 */
            {
                ret = STATUS_ERROR;
            }
        #elif defined(CCFC3008PCSN)
            value = value & FLS_LOCK_MASK_MID;
            FLS_FMC.LOCK4.B.MIDLOCK = 0U;
            FLS_FMC.LOCK4.B.MIDLOCK = value;
            if ((FLS_FMC.LOCK4.B.MIDLOCK & FLS_LOCK_MASK_MID) != value)
            {
                ret = STATUS_ERROR;
            }
        #else
            value = (lockedBlkStatus & FLS_LOCK_MASK_MID) << FLS_LOCK_OFFSET_MID; /* PRQA S 2984, 2790 */
            FLS_FMC.LOCK0.B.MIDLOCK = 0U;
            FLS_FMC.LOCK0.B.MIDLOCK = value;
            if ((FLS_FMC.LOCK0.B.MIDLOCK & (FLS_LOCK_MASK_MID << FLS_LOCK_OFFSET_MID)) != value) /* PRQA S 2790 */
            {
                ret = STATUS_ERROR;
            }
        #endif // CCFC3008PC || CCFC3008PCSN
            break;
        case SAF_FLS_BLK_HIGH:
		#ifndef CCFC3008PC
        #if defined(CCFC3008PCSN)
            value = lockedBlkStatus & FLS_LOCK_MASK_HIGH;
            FLS_FMC.LOCK0.B.MIDLOCK = 0U;
            FLS_FMC.LOCK0.B.MIDLOCK = value & FLS_LOCK_MASK_HIGH0;
            *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;/* polyspace RTE:IDP */
            *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;/* polyspace RTE:IDP */
            *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;/* polyspace RTE:IDP */
            *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;/* polyspace RTE:IDP */
            FLS_FMC.LOCK1.B.MTLOCK = 0U;
            FLS_FMC.LOCK1.B.MTLOCK = ~((value >> FLS_LOCK_OFFSET_HIGH) & FLS_LOCK_MASK_HIGH1);
            if (((FLS_FMC.LOCK0.B.MIDLOCK & FLS_LOCK_MASK_HIGH0) != (value & FLS_LOCK_MASK_HIGH0)) || \
                ((FLS_FMC.LOCK1.B.MTLOCK  & FLS_LOCK_MASK_HIGH1) != (~((value >> FLS_LOCK_OFFSET_HIGH) & FLS_LOCK_MASK_HIGH1))))
            {
                ret = STATUS_ERROR;
            }
        #else
            value = lockedBlkStatus & FLS_LOCK_MASK_HIGH;
            FLS_FMC.LOCK1.B.HIGHLOCK = 0U;
            FLS_FMC.LOCK1.B.HIGHLOCK = value;
            if ((FLS_FMC.LOCK1.B.HIGHLOCK & FLS_LOCK_MASK_HIGH) != value)
            {
                ret = STATUS_ERROR;
            }
        #endif // CCFC3008PCSN
		#endif // CCFC3008PC
            break;
        case SAF_FLS_BLK_FIRST_256K:
        #if defined(CCFC3008PT)
            /* If Swapped to B partition */
            if (1U == saf_g_swapStatus)
            {
                value = (((lockedBlkStatus >> 8U) & 0x000000FFU) | ((lockedBlkStatus << 8U) & 0x0000FF00U));
            }
            else
            {
                value = lockedBlkStatus & FLS_LOCK_MASK_FIR256K;/* PRQA S 2985 */
            }
        #else
            value = lockedBlkStatus & FLS_LOCK_MASK_FIR256K; /* PRQA S 2985 */
        #endif // CCFC3008PT
            FLS_FMC.LOCK2.B.A256KLOCK = 0U;
            FLS_FMC.LOCK2.B.A256KLOCK = value;
            if ((FLS_FMC.LOCK2.B.A256KLOCK & FLS_LOCK_MASK_FIR256K) != value)
            {
                ret = STATUS_ERROR;
            }
            break;
        case SAF_FLS_BLK_SECOND_256K:
            value = lockedBlkStatus & FLS_LOCK_MASK_SEC256K; /* PRQA S 2984, 499 */
            FLS_FMC.LOCK3.B.A256KLOCK = 0U;
            FLS_FMC.LOCK3.B.A256KLOCK = value;
            if ((FLS_FMC.LOCK3.R & FLS_LOCK_MASK_SEC256K) != value) /* PRQA S 499 */
            {
                ret = STATUS_ERROR;
            }
            break;
        default:
            ret = STATUS_ERROR;
            break;
    }
#else
    switch (lockedBlkSel)
    {
        case SAF_FLS_BLK_LOW:
            value = lockedBlkStatus & FLS_LOCK_MASK_LOW;
            FLS_FMC.LOCK0.B.LOWLOCK = 0U;
            FLS_FMC.LOCK0.B.LOWLOCK = value;
            if ((FLS_FMC.LOCK0.B.LOWLOCK & FLS_LOCK_MASK_LOW) != value)
            {
                ret = STATUS_ERROR;
            }
            break;
        case SAF_FLS_BLK_MID:
            value = (lockedBlkStatus & FLS_LOCK_MASK_MID) << FLS_LOCK_OFFSET_MID; /* PRQA S 2984, 2790 */
            FLS_FMC.LOCK0.B.MIDLOCK = 0U;
            FLS_FMC.LOCK0.B.MIDLOCK = value;
            if ((FLS_FMC.LOCK0.B.MIDLOCK & (FLS_LOCK_MASK_MID << FLS_LOCK_OFFSET_MID)) != value) /* PRQA S 2790 */
            {
                ret = STATUS_ERROR;
            }
            break;
        case SAF_FLS_BLK_HIGH:
            value = lockedBlkStatus & FLS_LOCK_MASK_HIGH;
            FLS_FMC.LOCK1.B.HIGHLOCK = 0U;
            FLS_FMC.LOCK1.B.HIGHLOCK = value;
            if ((FLS_FMC.LOCK1.B.HIGHLOCK & FLS_LOCK_MASK_HIGH) != value)
            {
                ret = STATUS_ERROR;
            }
            break;

        default: {
            uint32_t blk_offset;
            ret = SAF_FLS_LLD_GetBlockOffset(lockedBlkSel, &blk_offset);

            if (ret == STATUS_SUCCESS) {
                volatile struct C55FMC_tag *controller = NULL;
                SAF_FLS_LLD_GetBlockController(blk_offset, &controller);

                value = lockedBlkStatus & FLS_SEL_MASK_LARGE_256K;
                controller->LOCK2.B.A256KLOCK = 0U;
                controller->LOCK2.B.A256KLOCK = value;
                if ((controller->LOCK2.B.A256KLOCK & FLS_SEL_MASK_LARGE_256K) != value)
                {
                    ret = STATUS_ERROR;
                }
            }

            break;
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    return ret;
}

/*
 * @brief Erase the selected flash block
 *
 * This function is to do erase operation for selected flash block.
 *
 * @param[in] eraseSpace: Select flash main space.
 * @param[in] blkSel: Select the special flash block for erasing.
 * @param[in] mode: means the operate mode of erase.
              SAF_FLS_OP_SYNC: means sync erase operate.
              SAF_FLS_OP_ASYNC: means async erase operate.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Erase(uint8_t eraseSpace,
                         fls_blk_sel_t * blkSel,
                         uint32_t mode)
{
    status_t ret = STATUS_SUCCESS;

    fls_blk_sel_t blkSelTmp;
    uint32_t interlockWriteAddress = 0U;

#ifdef RESOURCE_SUPPORT_PFI
    uint32_t i = 0U, j = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if (blkSel == NULL)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* Check for validity of erase option */
    if (eraseSpace != SAF_FLS_ERS_MAIN_SPACE)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    blkSel->lowBlkSel &= FLS_SEL_MASK_LOW;
    blkSel->midBlkSel &= FLS_SEL_MASK_MID;
#ifndef CCFC3008PC
    blkSel->highBlkSel &= FLS_SEL_MASK_HIGH;
#endif // CCFC3008PC

#ifndef RESOURCE_SUPPORT_PFI
    blkSel->first256KBlkSel &= FLS_SEL_MASK_FIR256K; /* PRQA S 2985 */
    blkSel->second256KBlkSel &= FLS_SEL_MASK_SEC256K;

    blkSelTmp = *blkSel;
    interlockWriteAddress = SAF_FLS_LLD_GetInterWriteAddr(&blkSelTmp);

    if (0U == interlockWriteAddress)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    if ((blkSel->lowBlkSel > 0U) || (blkSel->midBlkSel > 0U) || (blkSel->highBlkSel > 0U) || (blkSel->first256KBlkSel > 0U) || (blkSel->second256KBlkSel > 0U)) {
        if ((FLS_FMC.MCR.B.PGM != 0U) || ((FLS_FMC.MCR.B.ERS != 0U) && ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_FMC.MCR.B.ESUS != 0U)))) {
            ret = STATUS_BUSY;
            return ret;
        }

        /* Set MCR_ERS to start erase operation */
        FLS_FMC.MCR.B.ERS = 1U;

        if (FLS_FMC.MCR.B.ERS == 0U)
        {
            ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
            /* Set the block selection registers */
#if defined(CCFC3008PC)
            uint32_t temp = 0U;
#endif
            FLS_FMC.SEL0.R = 0U;
            FLS_FMC.SEL1.R = 0U;
            FLS_FMC.SEL2.R = 0U;
            FLS_FMC.SEL3.R = 0U;
        #if defined(CCFC3008PCSN)
            FLS_FMC.SEL4.R = 0U;
        #endif // CCFC3008PCSN

        #if defined(CCFC3008PC)
            FLS_FMC.SEL0.B.LOWSEL = ((blkSel->lowBlkSel & 0xFU) << 1U) | ((blkSel->lowBlkSel & 0xF0U) << 2U);
        #elif defined(CCFC3008PCSN)
            FLS_FMC.SEL0.B.LOWSEL = blkSel->lowBlkSel & FLS_SEL_MASK_LOW0;
            FLS_FMC.SEL1.B.LOWSEL = (blkSel->lowBlkSel >> FLS_LOCK_OFFSET_LOW) & FLS_LOCK_MASK_LOW1;
        #else
            FLS_FMC.SEL0.B.LOWSEL = blkSel->lowBlkSel;
        #endif // CCFC3008PC || CCFC3008PCSN

        #if defined(CCFC3008PC)
            *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;
            *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;
            *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;
            *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;

            temp = blkSel->midBlkSel << FLS_LOCK_OFFSET_MID;
            FLS_FMC.SEL1.R = temp;
        #elif defined(CCFC3008PCSN)
            FLS_FMC.SEL4.B.MIDSEL = blkSel->midBlkSel & FLS_SEL_MASK_MID;
        #else
            FLS_FMC.SEL0.B.MIDSEL = blkSel->midBlkSel << FLS_LOCK_OFFSET_MID;
        #endif // CCFC3008PC || CCFC3008PCSN

        #ifndef CCFC3008PC
        #if defined(CCFC3008PCSN)
            FLS_FMC.SEL0.B.MIDSEL = blkSel->highBlkSel & FLS_SEL_MASK_HIGH0;
            *((volatile uint8_t *)(&C55FMC) + 0x1FC) = 0x20;/* polyspace RTE:IDP */
            *((volatile uint8_t *)(&C55FMC) + 0x1FD) = 0x22;/* polyspace RTE:IDP */
            *((volatile uint8_t *)(&C55FMC) + 0x1FE) = 0x08;/* polyspace RTE:IDP */
            *((volatile uint8_t *)(&C55FMC) + 0x1FF) = 0x01;/* polyspace RTE:IDP */
            FLS_FMC.SEL1.B.MTSEL = (blkSel->highBlkSel >> FLS_LOCK_OFFSET_HIGH) & FLS_LOCK_MASK_HIGH1;
        #else
            FLS_FMC.SEL1.R = blkSel->highBlkSel;
        #endif // CCFC3008PCSN
        #endif // CCFC3008PC

        #if defined(CCFC3008PT)
            if (1U == g_swapStatus)
            {
                FLS_FMC.SEL2.R = (((blkSel->first256KBlkSel >> 8U) & 0x000000FFU) | ((blkSel->first256KBlkSel << 8U) & 0x0000FF00U)); /* PRQA S 2985 */
            }
            else
            {
                FLS_FMC.SEL2.R = blkSel->first256KBlkSel;
            }
        #else
            FLS_FMC.SEL2.R = blkSel->first256KBlkSel;
        #endif // CCFC3008PT

            FLS_FMC.SEL3.R = blkSel->second256KBlkSel;

            /* Interlock write */
            *((volatile uint32_t*)interlockWriteAddress) = 0xFFFFFFFFU;/* polyspace RTE:IDP */
            /* Write a 1 to MCR_EHV */
            if (SAF_FLS_OP_SYNC == mode)
            {
                INTC_LLD_Set_Global_Disable();
                Saf_FLS_AcCodePtr();
                INTC_LLD_Set_Global_Enable();
            }
            else
            {
                FLS_FMC.MCR.B.EHV = 1U;
            }
            /* Not wait until MCR_DONE is set */
        }
    }
#else
#ifdef RESOURCE_SUPPORT_PFI0
    blkSel->large0BlkSel &= FLS_SEL_MASK_LARGE_256K;
#endif // RESOURCE_SUPPORT_PFI0
#ifdef RESOURCE_SUPPORT_PFI1
    blkSel->large1BlkSel &= FLS_SEL_MASK_LARGE_256K;
#endif // RESOURCE_SUPPORT_PFI1
#ifdef RESOURCE_SUPPORT_PFI2
    blkSel->large2BlkSel &= FLS_SEL_MASK_LARGE_256K;
#endif // RESOURCE_SUPPORT_PFI2
#ifdef RESOURCE_SUPPORT_PFI3
    blkSel->large3BlkSel &= FLS_SEL_MASK_LARGE_256K;
#endif // RESOURCE_SUPPORT_PFI3
#ifdef RESOURCE_SUPPORT_PFI4
    blkSel->large4BlkSel &= FLS_SEL_MASK_LARGE_256K;
#endif // RESOURCE_SUPPORT_PFI4
#ifdef RESOURCE_SUPPORT_PFI5
    blkSel->large5BlkSel &= FLS_SEL_MASK_LARGE_256K;
#endif // RESOURCE_SUPPORT_PFI5

    blkSelTmp = *blkSel;

    /* Get the controller that needs to be operated on */
    Saf_FLS_OpBlk = *blkSel;
    (void)Saf_FLS_OpBlk;
    cc_memset((uint8_t *)(&FLS_OpEFMC), NULL, sizeof(FLS_OpEFMC));

    if ((blkSel->lowBlkSel > 0U) || (blkSel->midBlkSel > 0U) || (blkSel->highBlkSel > 0U)) {
        FLS_OpEFMC[0] = &FLS_FMC;
    }

#ifdef RESOURCE_SUPPORT_PFI0
    if (blkSel->large0BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;

        SAF_FLS_LLD_GetMappedController(&FLS_T40FMC0, &controller);
        FLS_OpEFMC[SAF_FLS_BLK_LARGE0_256K - SAF_FLS_BLK_HIGH] = controller;
    }
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    if (blkSel->large1BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;

        SAF_FLS_LLD_GetMappedController(&FLS_T40FMC1, &controller);
        FLS_OpEFMC[SAF_FLS_BLK_LARGE1_256K - SAF_FLS_BLK_HIGH] = controller;
    }
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    if (blkSel->large2BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;

        SAF_FLS_LLD_GetMappedController(&FLS_T40FMC2, &controller);
        FLS_OpEFMC[SAF_FLS_BLK_LARGE2_256K - SAF_FLS_BLK_HIGH] = controller;
    }
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    if (blkSel->large3BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;

        SAF_FLS_LLD_GetMappedController(&FLS_T40FMC3, &controller);
        FLS_OpEFMC[SAF_FLS_BLK_LARGE3_256K - SAF_FLS_BLK_HIGH] = controller;
    }
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    if (blkSel->large4BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;

        SAF_FLS_LLD_GetMappedController(&FLS_T40FMC4, &controller);
        FLS_OpEFMC[SAF_FLS_BLK_LARGE4_256K - SAF_FLS_BLK_HIGH] = controller;
    }
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    if (blkSel->large5BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;

        SAF_FLS_LLD_GetMappedController(&FLS_T40FMC5, &controller);
        FLS_OpEFMC[SAF_FLS_BLK_LARGE5_256K - SAF_FLS_BLK_HIGH] = controller;
    }
#endif // RESOURCE_SUPPORT_PFI5

    /* Check parameters */
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[i];

        if (fmc == NULL) {
            continue;
        }

        /* Check busy */
        if ((fmc->MCR.B.PGM != 0U) || ((fmc->MCR.B.ERS != 0U) && ((fmc->MCR.B.EHV != 0U) || (fmc->MCR.B.ESUS != 0U)))) {/* polyspace RTE:NIV,IDP */
            ret = STATUS_BUSY;
            return ret;
        }
    }

    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[i];

        if (fmc == NULL) {
            continue;
        }

        /* Set MCR_ERS to start erase operation */
        fmc->MCR.B.ERS = 1U;/* polyspace RTE:IDP */

        if (fmc->MCR.B.ERS == 0U) {
            for (j = 0U; j < i; j++) {
                fmc = FLS_OpEFMC[j];

                if (fmc != NULL) {
                    fmc->MCR.B.ERS = 0U;/* polyspace RTE:IDP */
                }
            }

            ret = STATUS_FLASH_ERROR_ENABLE;
            return ret;
        }
    }

    /* Execute erase */
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[i];
        volatile struct C55FMC_tag *recovered_fmc = NULL;

        if (fmc == NULL) {
            continue;
        }

        interlockWriteAddress = SAF_FLS_LLD_GetInterWriteAddr(&blkSelTmp);

        SAF_FLS_LLD_GetMappedController(fmc, &recovered_fmc);

        if (fmc == &FLS_FMC) {
            blkSelTmp.lowBlkSel = 0;
            blkSelTmp.midBlkSel = 0;
            blkSelTmp.highBlkSel = 0;

            /* Set the block selection registers */
            FLS_FMC.SEL0.B.LOWSEL = blkSel->lowBlkSel;
            FLS_FMC.SEL0.B.MIDSEL = blkSel->midBlkSel << FLS_LOCK_OFFSET_MID;
            FLS_FMC.SEL1.B.HIGHSEL = blkSel->highBlkSel;
        }

    #ifdef RESOURCE_SUPPORT_PFI0
        else if (recovered_fmc == &FLS_T40FMC0) {
            blkSelTmp.large0BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = blkSel->large0BlkSel;/* polyspace RTE:IDP */
        }
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
        else if (recovered_fmc == &FLS_T40FMC1) {
            blkSelTmp.large1BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = blkSel->large1BlkSel;/* polyspace RTE:IDP */
        }
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
        else if (recovered_fmc == &FLS_T40FMC2) {
            blkSelTmp.large2BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = blkSel->large2BlkSel;/* polyspace RTE:IDP */
        }
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
        else if (recovered_fmc == &FLS_T40FMC3) {
            blkSelTmp.large3BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = blkSel->large3BlkSel;/* polyspace RTE:IDP */
        }
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
        else if (recovered_fmc == &FLS_T40FMC4) {
            blkSelTmp.large4BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = blkSel->large4BlkSel;/* polyspace RTE:IDP */
        }
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
        else if (recovered_fmc == &FLS_T40FMC5) {
            blkSelTmp.large5BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = blkSel->large5BlkSel;/* polyspace RTE:IDP */
        }
    #endif // RESOURCE_SUPPORT_PFI5

        else {
        }

        /* Interlock write */
        *((volatile uint32_t *)interlockWriteAddress) = 0xFFFFFFFFU;/* polyspace RTE:IDP */

        /* Write a 1 to MCR_EHV */
        if (SAF_FLS_OP_SYNC == mode) {
            INTC_LLD_Set_Global_Disable();
            Saf_FLS_AcCodePtr(fmc);/* polyspace RTE:COR */
            INTC_LLD_Set_Global_Enable();
        } else {
            fmc->MCR.B.EHV = 1U;/* polyspace RTE:IDP */
        }

        /* Not wait until MCR_DONE is set */
    }
#endif // RESOURCE_SUPPORT_PFI

    return ret;
}

/*
 * @brief Blank check for the previous erase operation
 *
 * This function is to do blank check for the previous erase operation.
 *
 * @param[in] dest: Destination address to be checked.(4 bytes aligned)
 * @param[in] size: Size of the flash region to check.(4 bytes aligned)
 * @param[in] checkWordSize: The number of word need check in each cycle.
 * @param[out] pFailAddr: Return the first error address of blank check.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_BlankCheckSaf(uint32_t dest,
                              uint32_t size,
                              uint32_t checkWordSize,
                              uint32_t * pFailAddr)
{
    status_t ret = STATUS_SUCCESS;
    uint32_t destIndex = 0U;
    uint32_t temp = 0U;
    uint32_t destTmp = dest;
    uint32_t sizeTmp = size;

    if (((destTmp | sizeTmp) % SAF_FLS_WORD_SIZE) != 0U)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    while ((sizeTmp > 0U) && (STATUS_SUCCESS == ret))
    {
        /* Number of words needs to be checked for blank */
        temp = sizeTmp / SAF_FLS_WORD_SIZE;

        /* In each blank check cycle, we take up to a certain words */
        if (temp >= checkWordSize)
        {
            temp = checkWordSize;
        }

        /* Word by word blank check */
        for (destIndex = 0U; destIndex < temp; destIndex++)
        {
            if ((*(volatile uint32_t *)destTmp) != 0xFFFFFFFFU) /* polyspace RTE:NIV,IDP */
            {
                ret = STATUS_ERROR;
                *pFailAddr = destTmp;
                break;
            }
            destTmp += SAF_FLS_WORD_SIZE;
            sizeTmp -= SAF_FLS_WORD_SIZE;
        }
    }

    return ret;
}


/*
 * @brief Program operation for flash
 *
 * This function is to do program operation for flash.
 *
 * @param[in] pCtxData: Storing context variables.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Program(fls_ctx_data_t * pCtxData)
{
    status_t ret = STATUS_SUCCESS;

#ifdef RESOURCE_SUPPORT_PFI
    uint32_t i = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if ( (pCtxData == NULL) || ((pCtxData->dest % SAF_FLS_DWORD_SIZE) != 0U) || ((pCtxData->size % SAF_FLS_DWORD_SIZE) != 0U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

#ifndef RESOURCE_SUPPORT_PFI
    if (((FLS_FMC.MCR.B.PGM != 0U) && ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_FMC.MCR.B.PSUS != 0U))) ||
         ((FLS_FMC.MCR.B.ERS != 0U) && (FLS_FMC.MCR.B.ESUS == 0U)))
    {
        /*
         * Return busy: program in progress, program in suspended, erase in progress
         * */
        ret = STATUS_BUSY;
    }
    else
    {
        /*
         * Do program: no program and erase, erase_suspend and EHV is low
         * */
        ret = SAF_FLS_LLD_PgmExec(pCtxData);
    }
#else
    /* Obtain the controller corresponding to the target address */
    for (i = 0; i < FLS_BLOCK_ALL; i++) {
        uint32_t addr_start = flashInfo[i].addrStart;
        uint32_t addr_end   = flashInfo[i].addrEnd;

        if ((addr_start <= pCtxData->dest) && (pCtxData->dest <= addr_end)) {
            volatile struct C55FMC_tag *fmc = NULL;

            SAF_FLS_LLD_GetBlockController(i, &fmc);

            if (((fmc->MCR.B.PGM != 0U) && ((fmc->MCR.B.EHV != 0U) || (fmc->MCR.B.PSUS != 0U))) || ((fmc->MCR.B.ERS != 0U) && (fmc->MCR.B.ESUS == 0U)))/* polyspace RTE:NIV */
            {
                /*
                * Return busy: program in progress, program in suspended, erase in progress
                * */
                ret = STATUS_BUSY;
            }
            else
            {
                /*
                * Do program: no program and erase, erase_suspend and EHV is low
                * */
                if ((saf_FLS_OpPFMC != NULL) && (saf_FLS_OpPFMC != fmc)) {
                    saf_FLS_OpPFMC->MCR.B.PGM = 0U;
                }

                saf_FLS_OpPFMC = fmc;
                ret = SAF_FLS_LLD_PgmExec(pCtxData, fmc);
            }

            break;
        }
    }

    if (i == FLS_BLOCK_ALL) {
        ret = STATUS_ERROR;
    }
#endif // RESOURCE_SUPPORT_PFI

    return ret;
}

/*
 * @brief Verify the previous program operation
 *
 * This function is to verify the previous program operation.
 *
 * @param[in] dest: Destination address for verify.(4 bytes aligned)
 * @param[in] size: Size of the flash region to verify.(4 bytes aligned)
 * @param[in] src: Source buffer address for verify.(4 bytes aligned)
 * @param[in] checkWordSize: The number of word need to verify in each cycle.
 * @param[out] pFailAddr: Return the first failing address in flash.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_ProgramVerifySaf(uint32_t dest,
                                 uint32_t size,
                                 uint32_t src,
                                 uint32_t checkWordSize,
                                 uint32_t * pFailAddr)
{
    status_t ret = STATUS_SUCCESS;
    uint32_t destIndex = 0U;
    uint32_t temp = 0U;
    uint32_t valDest = 0U;
    uint32_t destTmp = dest;
    uint32_t sizeTmp = size;
    uint32_t srcTmp = src;

    if ( ((destTmp | sizeTmp | src) % SAF_FLS_WORD_SIZE) != 0U )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    while ((sizeTmp > 0U) && (STATUS_SUCCESS == ret))
    {
        /* Number of words needs to be verified */
        temp = sizeTmp / SAF_FLS_WORD_SIZE;

        /* In each verify cycle, we take up to a certain words */
        if (temp >= checkWordSize)
        {
            temp = checkWordSize;
        }

        /* Word by word verify */
        for (destIndex = 0U; destIndex < temp; destIndex++)
        {
            valDest = *(volatile uint32_t *)destTmp; /* polyspace RTE:NIV,IDP */
            if (valDest != *(volatile uint32_t *)srcTmp) /* polyspace RTE:NIV,IDP */
            {
                ret = STATUS_ERROR;
                *pFailAddr = destTmp;
                break;
            }

            destTmp += SAF_FLS_WORD_SIZE;
            srcTmp += SAF_FLS_WORD_SIZE;
            sizeTmp -= SAF_FLS_WORD_SIZE;
        }
    }

    return ret;
}

/*
 * @brief Perform a sum over the specified flash
 *
 * This function perform a sum(32 bit) over the specified flash without carry.
 *
 * @param[in] dest: Destination address to the specified flash memory.(4 bytes aligned)
 * @param[in] size: Size in bytes of the flash region to check sum.(4 bytes aligned)
 * @param[in] checkWordSize: The number of word need to calculate sum in each cycle.
 * @param[out] pSum: Return the sum value.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_CheckSum(uint32_t dest,
                            uint32_t size,
                            uint32_t checkWordSize,
                            uint32_t *pSum)
{
    uint32_t destIndex = 0U;
    uint32_t temp = 0U;
    uint32_t destTmp = dest;
    uint32_t sizeTmp = size;

    if ( ((destTmp | sizeTmp) % SAF_FLS_WORD_SIZE) != 0U )
    {
        return STATUS_ERROR;
    }

    /* Initialize the sum variable */
    *pSum = 0U;

    while (sizeTmp != 0U)
    {
        /* Number of words needs to be checked sum */
        temp = sizeTmp / SAF_FLS_WORD_SIZE;

        /* In each check sum cycle, we take up to a certain words */
        if (temp >= checkWordSize)
        {
            temp = checkWordSize;
        }

        /* Word by word checksum */
        for (destIndex = 0U; destIndex < temp; destIndex++)
        {
            *pSum += *(volatile uint32_t *)destTmp; /* polyspace RTE:NIV,IDP */
            destTmp += SAF_FLS_WORD_SIZE;
            sizeTmp -= SAF_FLS_WORD_SIZE;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * @brief Abort the flash program/erase operation
 *
 * This function will abort a flash program or erase operation.
 *
 * @return Operation status
 */
#ifdef CCFC3012PT
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Abort(void)
{
    volatile uint32_t clearFlag = 0x0U;
    uint32_t count = 450U;

#ifndef RESOURCE_SUPPORT_PFI
    volatile uint32_t u32Fls_erase = 0x0U;

    u32Fls_erase = FLS_FMC.MCR.B.ERS;

    if (FLS_FMC.MCR.B.ESUS != 0U)
    {
        if (FLS_FMC.MCR.B.PSUS != 0U)
        {
            clearFlag = 0x3U;
        }
        else
        {
            clearFlag = 0x2U;
        }
    }
    else
    {
        if (FLS_FMC.MCR.B.PSUS != 0U)
        {
            clearFlag = 0x1U;
        }
    }

    if ((clearFlag & 0x1U) != 0x0U)  /* Program-suspended Erase-suspended or Program-suspended only */
    {
        /* Wait MCR DONE bit is set to program-suspended operation accomplish */
        while ((FLS_FMC.MCR.B.DONE == 0U) && (count > 0U))
        {
            count--;
        }
        /* Set MCR_EHV bit then clear MCR_PSUS to resume program operation */
        FLS_FMC.MCR.B.EHV = 1U;
        FLS_FMC.MCR.B.PSUS = 0U;
    }

    if ((clearFlag & 0x2U) != 0x0U)
    {
        /* Clear EHV to abort program operation and then clear MCR_PGM */
        FLS_FMC.MCR.B.EHV = 0U;
        /* Wait MCR DONE bit is set */
        while ((FLS_FMC.MCR.B.DONE == 0U) && (count > 0U))
        {
            count--;
        }
        FLS_FMC.MCR.B.PGM = 0U;
        /* Set MCR_EHV bit then clear MCR_PSUS to resume erase operation */
        FLS_FMC.MCR.B.EHV = 1U;
        FLS_FMC.MCR.B.ESUS = 0U;
    }

    /* Clear EHV bit to abort flash operation */
    FLS_FMC.MCR.B.EHV = 0U;
    /* Wait MCR DONE bit is set */
    while ((FLS_FMC.MCR.B.DONE == 0U) && (count > 0U))
    {
        count--;
    }

    /* Clear PGM, ERS bit */
    FLS_FMC.MCR.B.PGM = 0U;
    FLS_FMC.MCR.B.ERS = 0U;

    /* Disable Cache */
    PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFLASH.PFCR2.B.P1_BFEN = 0U;
    /* Enable Cache */
    PFLASH.PFCR1.B.P0_BFEN = 1U;
    PFLASH.PFCR2.B.P1_BFEN = 1U;

    /* Make the erased flash space in DCache invalid */
    if (u32Fls_erase != 0x0U)
    {
        SAF_FLS_SDK_LLD_DCacheInvalid();
    }
#else
    uint32_t i = 0U;
    volatile uint32_t u32Fls_erase = 0x0U;

    for (i = 0; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag * const fmc = flashControllerList[i];

        count = 450U;
        clearFlag = 0x0U;

        u32Fls_erase |= fmc->MCR.B.ERS;

        if (fmc->MCR.B.ESUS != 0U)
        {
            if (fmc->MCR.B.PSUS != 0U)
            {
                clearFlag = 0x3U;
            }
            else
            {
                clearFlag = 0x2U;
            }
        }
        else
        {
            if (fmc->MCR.B.PSUS != 0U)
            {
                clearFlag = 0x1U;
            }
        }

        if ((clearFlag & 0x1U) != 0x0U)  /* Program-suspended Erase-suspended or Program-suspended only */
        {
            /* Wait MCR DONE bit is set to program-suspended operation accomplish */
            while ((fmc->MCR.B.DONE == 0U) && (count > 0U))
            {
                count--;
            }
            /* Set MCR_EHV bit then clear MCR_PSUS to resume program operation */
            fmc->MCR.B.EHV = 1U;
            fmc->MCR.B.PSUS = 0U;
        }

        if ((clearFlag & 0x2U) != 0x0U)
        {
            /* Clear EHV to abort program operation and then clear MCR_PGM */
            fmc->MCR.B.EHV = 0U;
            /* Wait MCR DONE bit is set */
            while ((fmc->MCR.B.DONE == 0U) && (count > 0U))
            {
                count--;
            }
            fmc->MCR.B.PGM = 0U;
            /* Set MCR_EHV bit then clear MCR_PSUS to resume erase operation */
            fmc->MCR.B.EHV = 1U;
            fmc->MCR.B.ESUS = 0U;
        }

        /* Clear EHV bit to abort flash operation */
        fmc->MCR.B.EHV = 0U;
        /* Wait MCR DONE bit is set */
        while ((fmc->MCR.B.DONE == 0U) && (count > 0U))
        {
            count--;
        }

        /* Clear PGM, ERS bit */
        fmc->MCR.B.PGM = 0U;
        fmc->MCR.B.ERS = 0U;
    }
#endif // RESOURCE_SUPPORT_PFI

    return STATUS_SUCCESS;
}
#endif
/*
 * @brief Suspend a flash operation
 *
 * This function will suspend a flash operation which is in progress.
 *
 * @param[out] susStatus: Return suspend state after call this function.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Suspend(uint8_t * susStatus)
{
    uint32_t count = 450U;

#ifdef RESOURCE_SUPPORT_PFI
    uint32_t i = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if ( susStatus == NULL)
    {
        return STATUS_ERROR;
    }

    *susStatus = SAF_FLS_NO_SUS;

#ifndef RESOURCE_SUPPORT_PFI
    /* No program/erase sequence */
    if ((FLS_FMC.MCR.B.PGM == 0U) && (FLS_FMC.MCR.B.ERS == 0U))
    {
        /* Nothing to do */
    }
    else
    {
        if (((FLS_FMC.MCR.B.PGM != 0U) && (FLS_FMC.MCR.B.PSUS == 0U)) ||
             ((FLS_FMC.MCR.B.ERS != 0U) && (FLS_FMC.MCR.B.ESUS == 0U)))
        {
            SAF_FLS_LLD_SusExec(susStatus);
        }

        /* Check the high voltage is cleared or not */
        if ((FLS_FMC.MCR.B.EHV != 0U) || (Saf_FLS_EHV_Val == 1U))
        {
            if (FLS_FMC.MCR.B.PSUS != 0U)
            {
                *susStatus = SAF_FLS_PGM_SUS;

                if (FLS_FMC.MCR.B.ESUS != 0U)
                {
                    *susStatus = SAF_FLS_ERS_SUS_PGM_SUS;
                }
            }
            else
            {
                *susStatus = SAF_FLS_ERS_SUS;
            }

            /* Wait MCR DONE bit is set */
            while ((FLS_FMC.MCR.B.DONE == 0U) && (count > 0U))
            {
                count--;
            }

            /* Set MCR_EHV to 0 */
            FLS_FMC.MCR.B.EHV = 0U;
            Saf_FLS_EHV_Val = 0U;
        }
    }
#else
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag * const fmc = flashControllerList[i];

        /* No program/erase sequence */
        if ((fmc->MCR.B.PGM == 0U) && (fmc->MCR.B.ERS == 0U)) {
            /* Nothing to do */
        } else {
            uint8_t *fls_ehv_val;

            if (((fmc->MCR.B.PGM != 0U) && (fmc->MCR.B.PSUS == 0U)) ||
                ((fmc->MCR.B.ERS != 0U) && (fmc->MCR.B.ESUS == 0U))) {
                SAF_FLS_LLD_SusExec(susStatus, fmc);
            }

            SAF_FLS_LLD_Get_FLS_EHV_Val(fmc, &fls_ehv_val);

            /* Check the high voltage is cleared or not */
            if ((fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U)) /* polyspace RTE:NIV,NIP */
	    {
                if (fmc->MCR.B.PSUS != 0U) {/* polyspace RTE:NIV *//* polyspace RTE:NIP */
                    *susStatus = SAF_FLS_PGM_SUS;

                    if (fmc->MCR.B.ESUS != 0U) {/* polyspace RTE:NIV */
                        *susStatus = SAF_FLS_ERS_SUS_PGM_SUS;
                    }
                } else {
                    *susStatus = SAF_FLS_ERS_SUS;
                }

                /* Wait MCR DONE bit is set */
                while ((fmc->MCR.B.DONE == 0U) && (count > 0U)) {/* polyspace RTE:NIV */
                    count--;
                }

                /* Set MCR_EHV to 0 */
                fmc->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;/* polyspace RTE:NIP */
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    return STATUS_SUCCESS;
}

/*
 * @brief Resume the suspended flash operation
 *
 * This function will resume the suspended flash operation.
 *
 * @param[out] resStatus: Return resume state after call this function.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Resume(uint8_t * resStatus)
{
    uint32_t bitMask = 0U;                       /* PSUS or ESUS bit to be cleared */
    uint32_t count = 0U;                         /* the loop count for the wait loop */

#ifdef RESOURCE_SUPPORT_PFI
    uint32_t i = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if ( resStatus == NULL)
    {
        return STATUS_ERROR;
    }

    *resStatus = SAF_FLS_RES_NOTHING;

    /* Resume the operation according to the interface selection */
    count = 15U;

#ifndef RESOURCE_SUPPORT_PFI
    /* Program in suspend state or entering suspend state */
    if (FLS_FMC.MCR.B.PSUS != 0U)
    {
        *resStatus = SAF_FLS_RES_PGM;
        bitMask = 0x1U;

        if (FLS_FMC.MCR.B.ESUS != 0U)
        {
            /* Erase-suspended program is suspended */
            *resStatus = SAF_FLS_RES_ERS_PGM;
        }
    }
    else
    {
        /* Erase in suspend state or entering suspend state */
        if ((FLS_FMC.MCR.B.ESUS != 0U) && (FLS_FMC.MCR.B.PGM == 0U))
        {
            *resStatus = SAF_FLS_RES_ERS;
            bitMask = 0x2U;
        }
        else
        {
            /* No suspended operation */
        }
    }

    if (*resStatus != SAF_FLS_RES_NOTHING)
    {
        /* Set MCR_EHV bit */
        FLS_FMC.MCR.B.EHV = 1U;

        /* Clear the MCR_PSUS bit */
        if (bitMask == 0x1U)
        {
            FLS_FMC.MCR.B.PSUS = 0U;
        }

        /* Clear the MCR_ESUS bit */
        if (bitMask == 0x2U)
        {
            FLS_FMC.MCR.B.ESUS = 0U;
        }

        /* Wait the MCR_DONE bit goes low */
        while ((FLS_FMC.MCR.B.DONE != 0U) && (count > 0U))
        {
            count--;
        }
    }
#else
    for (i = 0U; i < FLS_CONTROLLER_NUM; i++) {
        volatile struct C55FMC_tag * const fmc = flashControllerList[i];

        /* Program in suspend state or entering suspend state */
        if (fmc->MCR.B.PSUS != 0U) {
            *resStatus = SAF_FLS_RES_PGM;
            bitMask = 0x1U;

            if (fmc->MCR.B.ESUS != 0U) {
                /* Erase-suspended program is suspended */
                *resStatus = SAF_FLS_RES_ERS_PGM;
            }
        } else {
            /* Erase in suspend state or entering suspend state */
            if ((fmc->MCR.B.ESUS != 0U) && (fmc->MCR.B.PGM == 0U)) {
                *resStatus = SAF_FLS_RES_ERS;
                bitMask = 0x2U;
            } else {
                /* No suspended operation */
            }
        }

        if (*resStatus != SAF_FLS_RES_NOTHING) {
            /* Set MCR_EHV bit */
            fmc->MCR.B.EHV = 1U;

            /* Clear the MCR_PSUS bit */
            if (bitMask == 0x1U) {
                fmc->MCR.B.PSUS = 0U;
            }

            /* Clear the MCR_ESUS bit */
            if (bitMask == 0x2U) {
                fmc->MCR.B.ESUS = 0U;
            }

            /* Wait the MCR_DONE bit goes low */
            while ((fmc->MCR.B.DONE != 0U) && (count > 0U)) {
                count--;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI

    return STATUS_SUCCESS;
}


/*
 * @brief Get the over-program protection status
 *
 * This function will return the over-program protection status.
 *
 * @param[in] flsBlk: Select the special flash block to get over-program protection status.
 * @param[out] protStatus: Return bit map for over-program protection status.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_GetOverPgmProtStatus(uint8_t flsBlk,
                                        uint32_t * protStatus)
{
    status_t ret = STATUS_SUCCESS;

    /* Determine which address space is selected */
    switch (flsBlk)
    {
        case SAF_FLS_BLK_LOW:
        #if defined(CCFC3008PC)
        {
            uint32_t temp;

            temp = (FLS_FMC.OPP0.B.LOWOPP & (FLS_SEL_MASK_LOW | (3U << 8U)));
            *protStatus = ((temp & 0x1EU) >> 1U) | ((temp & 0x3C0) >> 2U);
            break;
        }
        #else
            *protStatus = (FLS_FMC.OPP0.B.LOWOPP & FLS_SEL_MASK_LOW);
            break;
        #endif // CCFC3008PC
        case SAF_FLS_BLK_MID:
        #if defined(CCFC3008PC) || defined(CCFC3008PCSN)
            *protStatus = (((uint32_t)(FLS_FMC.OPP1.R) >> FLS_LOCK_OFFSET_MID) & FLS_SEL_MASK_MID);/* PRQA S 2790 */
        #else
            *protStatus = (((uint32_t)(FLS_FMC.OPP0.B.MIDOPP) >> FLS_LOCK_OFFSET_MID) & FLS_SEL_MASK_MID);/* PRQA S 2790 */
        #endif // CCFC3008PC || CCFC3008PCSN
            break;
        case SAF_FLS_BLK_HIGH:
		#ifndef CCFC3008PC
        #if defined(CCFC3008PCSN)
            /* MIT Info Block always turns on Over-Program Protection */
            *protStatus = (FLS_FMC.OPP3.B.MIDOPP | (0x7F << FLS_LOCK_OFFSET_HIGH));
        #else
            *protStatus = (FLS_FMC.OPP1.B.HIGHOPP & FLS_SEL_MASK_HIGH);
        #endif // CCFC3008PCSN
		#endif // CCFC3008PC
            break;
#ifndef RESOURCE_SUPPORT_PFI
        case SAF_FLS_BLK_FIRST_256K:
            *protStatus = (FLS_FMC.OPP2.B.A256KOPP & FLS_SEL_MASK_FIR256K);
            break;
        case SAF_FLS_BLK_SECOND_256K:
            *protStatus = (FLS_FMC.OPP3.R & FLS_SEL_MASK_SEC256K);
            break;
        default:
            ret = STATUS_ERROR;
            break;
#else
        default: {
            uint32_t blk_offset;
            ret = SAF_FLS_LLD_GetBlockOffset(flsBlk, &blk_offset);

            if (ret == STATUS_SUCCESS) {
                volatile struct C55FMC_tag *controller = NULL;

                SAF_FLS_LLD_GetBlockController(blk_offset, &controller);
                *protStatus = (controller->OPP2.B.A256KOPP & FLS_SEL_MASK_LARGE_256K);/* polyspace RTE:NIV */
            }

            break;
        }
#endif // RESOURCE_SUPPORT_PFI
    }

    return ret;
}

/*
 * @brief Enable flash command complete interrupt.
 *
 * This function will enable flash command complete interrupt.
 */
SAF_FLASH_SEC_CODE
void SAF_FLASH_LLD_EnableCmdCompleteInterupt(void)
{
    /* Enable the command complete interrupt */
    FLS_FMC.MCR.B.PECIE = 1U;

#ifdef RESOURCE_SUPPORT_PFI0
    FLS_T40FMC0.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    FLS_T40FMC1.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    FLS_T40FMC2.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    FLS_T40FMC3.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    FLS_T40FMC4.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    FLS_T40FMC5.MCR.B.PECIE = 1U;
#endif // RESOURCE_SUPPORT_PFI5
}

/*
 * @brief Disable flash command complete interrupt.
 *
 * This function will disable flash command complete interrupt.
 *
 */
SAF_FLASH_SEC_CODE
void SAF_FLASH_LLD_DisableCmdCompleteInterupt(void)
{
    /* Disable the command complete interrupt */
    FLS_FMC.MCR.B.PECIE = 0U;

#ifdef RESOURCE_SUPPORT_PFI0
    FLS_T40FMC0.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    FLS_T40FMC1.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    FLS_T40FMC2.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    FLS_T40FMC3.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    FLS_T40FMC4.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    FLS_T40FMC5.MCR.B.PECIE = 0U;
#endif // RESOURCE_SUPPORT_PFI5
}

/*
 * @brief Flash command complete interrupt handle function.
 *
 * The interrupt handle function for flash command complete interrupt.
 *
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    void SAF_FLASH_Cmd_Done_ISR(void)
    {
        FLS_FMC.MCR.B.PECIE = 0U;
        if (FLS_FMC.MCR.B.EHV != 0U)
        {
            FLS_FMC.MCR.B.EHV = 0U;
            Saf_FLS_EHV_Val = 1U;
        }
        else
        {
            Saf_FLS_EHV_Val = 0U;
        }
    }
#else
	SAF_FLASH_SEC_CODE
    void SAF_FLASH_Cmd_Done_ISR(void)
    {
        FLS_FMC.MCR.B.PECIE = 0U;
        if (FLS_FMC.MCR.B.EHV != 0U)
        {
            FLS_FMC.MCR.B.EHV = 0U;
            Saf_FLS_EHV_Val_All[0] = 1U;
        }
        else
        {
            Saf_FLS_EHV_Val_All[0] = 0U;
        }
    }

    #ifdef RESOURCE_SUPPORT_PFI0
		SAF_FLASH_SEC_CODE
        void SAF_FLASH_PFI0_Cmd_Done_ISR(void) {
            FLS_T40FMC0.MCR.B.PECIE = 0U;
            if (FLS_T40FMC0.MCR.B.EHV != 0U)
            {
                FLS_T40FMC0.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE0_256K - SAF_FLS_BLK_HIGH] = 1U;
            }
            else
            {
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE0_256K - SAF_FLS_BLK_HIGH] = 0U;
            }
        }
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
		SAF_FLASH_SEC_CODE
        void SAF_FLASH_PFI1_Cmd_Done_ISR(void) {
            FLS_T40FMC1.MCR.B.PECIE = 0U;
            if (FLS_T40FMC1.MCR.B.EHV != 0U)
            {
                FLS_T40FMC1.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE1_256K - SAF_FLS_BLK_HIGH] = 1U;
            }
            else
            {
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE1_256K - SAF_FLS_BLK_HIGH] = 0U;
            }
        }
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
		SAF_FLASH_SEC_CODE
        void SAF_FLASH_PFI2_Cmd_Done_ISR(void) {
            FLS_T40FMC2.MCR.B.PECIE = 0U;
            if (FLS_T40FMC2.MCR.B.EHV != 0U)
            {
                FLS_T40FMC2.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE2_256K - SAF_FLS_BLK_HIGH] = 1U;
            }
            else
            {
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE2_256K - SAF_FLS_BLK_HIGH] = 0U;
            }
        }
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
		SAF_FLASH_SEC_CODE
        void SAF_FLASH_PFI3_Cmd_Done_ISR(void) {
            FLS_T40FMC3.MCR.B.PECIE = 0U;
            if (FLS_T40FMC3.MCR.B.EHV != 0U)
            {
                FLS_T40FMC3.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE3_256K - SAF_FLS_BLK_HIGH] = 1U;
            }
            else
            {
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE3_256K - SAF_FLS_BLK_HIGH] = 0U;
            }
        }
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
		SAF_FLASH_SEC_CODE
        void SAF_FLASH_PFI4_Cmd_Done_ISR(void) {
            FLS_T40FMC4.MCR.B.PECIE = 0U;
            if (FLS_T40FMC4.MCR.B.EHV != 0U)
            {
                FLS_T40FMC4.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE4_256K - SAF_FLS_BLK_HIGH] = 1U;
            }
            else
            {
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE4_256K - SAF_FLS_BLK_HIGH] = 0U;
            }
        }
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
		SAF_FLASH_SEC_CODE
        void SAF_FLASH_PFI5_Cmd_Done_ISR(void) {
            FLS_T40FMC5.MCR.B.PECIE = 0U;
            if (FLS_T40FMC5.MCR.B.EHV != 0U)
            {
                FLS_T40FMC5.MCR.B.EHV = 0U;
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE5_256K - SAF_FLS_BLK_HIGH] = 1U;
            }
            else
            {
                Saf_FLS_EHV_Val_All[SAF_FLS_BLK_LARGE5_256K - SAF_FLS_BLK_HIGH] = 0U;
            }
        }
    #endif // RESOURCE_SUPPORT_PFI5
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Disable flash cache
 *
 * This function used to disable flash cache.
 *
 * @param[in] port: Select flash port to disable cache.
 * @param[out] originValue: Return the original value of PFCR.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    status_t SAF_FLASH_LLD_DisableCache(uint8_t port, uint32_t *originValue)
    {
        status_t ret = STATUS_SUCCESS;

        if (port > FLS_PORT2)
        {
            ret = STATUS_ERROR;
            return ret;
        }

        if (FLS_PORT1 == port)
        {
            /* Read the values of the register of flash configuration */
            *originValue = PFLASH.PFCR1.R;

            /* Disable Caches */
            PFLASH.PFCR1.B.P0_BFEN = 0U;
        }
        else
        {
            /* Read the values of the register of flash configuration */
            *originValue = PFLASH.PFCR2.R;

            /* Disable Caches */
            PFLASH.PFCR2.B.P1_BFEN = 0U;
        }

        return ret;
    }
#else
	SAF_FLASH_SEC_CODE
    status_t SAF_FLASH_LLD_DisableCache(uint8_t port, uint32_t *originValue) {
        uint32_t mapped_port;
        status_t ret = STATUS_SUCCESS;

        if (port >= FLS_PORT_MAX) {
            ret = STATUS_ERROR;
            return ret;
        }

        ret = SAF_FLS_LLD_GetMappedPort((uint32_t)port, &mapped_port);

        if (ret != STATUS_SUCCESS) {
            return ret;
        }

        port = (uint8_t)mapped_port;

        switch (port) {
            case FLS_PORT1: {
                /* Read the values of the register of flash configuration */
                *originValue = PFLASH.PFCR1.R;

                /* Disable Caches */
                PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT2: {
                /* Read the values of the register of flash configuration */
                *originValue = PFLASH.PFCR2.R;

                /* Disable Caches */
                PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }

        #ifdef RESOURCE_SUPPORT_PFI0
            case FLS_PORT3: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI0_PFLASH.PFCR1.R;

                /* Disable Caches */
                PFI0_PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT4: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI0_PFLASH.PFCR2.R;

                /* Disable Caches */
                PFI0_PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI0

        #ifdef RESOURCE_SUPPORT_PFI1
            case FLS_PORT5: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI1_PFLASH.PFCR1.R;

                /* Disable Caches */
                PFI1_PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT6: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI1_PFLASH.PFCR2.R;

                /* Disable Caches */
                PFI1_PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI1

        #ifdef RESOURCE_SUPPORT_PFI2
            case FLS_PORT7: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI2_PFLASH.PFCR1.R;

                /* Disable Caches */
                PFI2_PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT8: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI2_PFLASH.PFCR2.R;

                /* Disable Caches */
                PFI2_PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI2

        #ifdef RESOURCE_SUPPORT_PFI3
            case FLS_PORT9: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI3_PFLASH.PFCR1.R;

                /* Disable Caches */
                PFI3_PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT10: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI3_PFLASH.PFCR2.R;

                /* Disable Caches */
                PFI3_PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI3

        #ifdef RESOURCE_SUPPORT_PFI4
            case FLS_PORT11: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI4_PFLASH.PFCR1.R;

                /* Disable Caches */
                PFI4_PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT12: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI4_PFLASH.PFCR2.R;

                /* Disable Caches */
                PFI4_PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI4

        #ifdef RESOURCE_SUPPORT_PFI5
            case FLS_PORT13: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI5_PFLASH.PFCR1.R;

                /* Disable Caches */
                PFI5_PFLASH.PFCR1.B.P0_BFEN = 0U;

                break;
            }

            case FLS_PORT14: {
                /* Read the values of the register of flash configuration */
                *originValue = PFI5_PFLASH.PFCR2.R;

                /* Disable Caches */
                PFI5_PFLASH.PFCR2.B.P1_BFEN = 0U;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI5
        
            default:
                break;
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Restore flash cache
 *
 * This function will restore configuration register.
 *
 * @param[in] port: Select flash port to restore.
 * @param[in] originValue: The original value of PFCR.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
	SAF_FLASH_SEC_CODE
    status_t SAF_FLASH_LLD_RestoreCache(uint8_t port, uint32_t originValue)
    {
        status_t ret = STATUS_SUCCESS;

        if (port > FLS_PORT2)
        {
            ret = STATUS_ERROR;
            return ret;
        }

        if (FLS_PORT1 == port)
        {
            /* Restore configuration register of flash configuration */
            PFLASH.PFCR1.R = originValue;
        }
        else
        {
            /* Restore configuration register of flash configuration */
            PFLASH.PFCR2.R = originValue;
        }

        return ret;
    }
#else
	SAF_FLASH_SEC_CODE
    status_t SAF_FLASH_LLD_RestoreCache(uint8_t port, uint32_t originValue) {
        uint32_t mapped_port;
        status_t ret = STATUS_SUCCESS;

        if (port >= FLS_PORT_MAX) {
            ret = STATUS_ERROR;
            return ret;
        }

        ret = SAF_FLS_LLD_GetMappedPort((uint32_t)port, &mapped_port);

        if (ret != STATUS_SUCCESS) {
            return ret;
        }

        port = (uint8_t)mapped_port;

        switch (port) {
            case FLS_PORT1: {
                /* Restore configuration register of flash configuration */
                PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT2: {
                /* Restore configuration register of flash configuration */
                PFLASH.PFCR2.R = originValue;

                break;
            }

        #ifdef RESOURCE_SUPPORT_PFI0
            case FLS_PORT3: {
                /* Restore configuration register of flash configuration */
                PFI0_PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT4: {
                /* Restore configuration register of flash configuration */
                PFI0_PFLASH.PFCR2.R = originValue;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI0

        #ifdef RESOURCE_SUPPORT_PFI1
            case FLS_PORT5: {
                /* Restore configuration register of flash configuration */
                PFI1_PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT6: {
                /* Restore configuration register of flash configuration */
                PFI1_PFLASH.PFCR2.R = originValue;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI1

        #ifdef RESOURCE_SUPPORT_PFI2
            case FLS_PORT7: {
                /* Restore configuration register of flash configuration */
                PFI2_PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT8: {
                /* Restore configuration register of flash configuration */
                PFI2_PFLASH.PFCR2.R = originValue;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI2

        #ifdef RESOURCE_SUPPORT_PFI3
            case FLS_PORT9: {
                /* Restore configuration register of flash configuration */
                PFI3_PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT10: {
                /* Restore configuration register of flash configuration */
                PFI3_PFLASH.PFCR2.R = originValue;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI3

        #ifdef RESOURCE_SUPPORT_PFI4
            case FLS_PORT11: {
                /* Restore configuration register of flash configuration */
                PFI4_PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT12: {
                /* Restore configuration register of flash configuration */
                PFI4_PFLASH.PFCR2.R = originValue;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI4

        #ifdef RESOURCE_SUPPORT_PFI5
            case FLS_PORT13: {
                /* Restore configuration register of flash configuration */
                PFI5_PFLASH.PFCR1.R = originValue;

                break;
            }

            case FLS_PORT14: {
                /* Restore configuration register of flash configuration */
                PFI5_PFLASH.PFCR2.R = originValue;

                break;
            }
        #endif // RESOURCE_SUPPORT_PFI5

            default:
                break;
        }

        return ret;
    }
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Enable Flash Calibration Region Descriptor
 *
 * This function will Enable flash calibration region descriptor.
 *
 * @param[in] cdrIndex: The Index of Calibration Remap Descriptor.
 * @param[in] remapConfig: The config of Calibration Region Descriptor.
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Overlay_Config_Enable(uint32_t cdrIndex, flash_remap_config_t *remapConfig) /* PRQA S 3673 */
{
    status_t ret = STATUS_SUCCESS;

#if PFLASH_Safe_Calibration
    /* check flash region count */
    if (cdrIndex >= PFLASH_PFCRD_SAFE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    ret = SAF_FLS_LLD_OverlayConfig(cdrIndex, remapConfig);
    ret = SAF_FLS_LLD_OverlayConfig((cdrIndex+PFLASH_PFCRD_SAFE_COUNT), remapConfig);
#else
    /* check flash region count */
    if (cdrIndex >= PFLASH_PFCRD_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    ret = SAF_FLS_LLD_OverlayConfig(cdrIndex, remapConfig);
#endif

    return ret;
}

/*
 * @brief Disable Flash Calibration Region Descriptor
 *
 * This function will disable flash calibration region descriptor.
 *
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Overlay_Config_Disable(uint32_t cdrIndex)
{
    status_t ret = STATUS_SUCCESS;

    /* check flash region count */
#if PFLASH_Safe_Calibration
    if (cdrIndex >= PFLASH_PFCRD_SAFE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }
    /* disable the corresponding Calibration Remap Descriptor */
    PFLASH.PFCRDE.R &= (~(uint32_t)(1UL<<(31U-cdrIndex)))&0xFFFFFFFFU; /* PRQA S 2985 */
    PFLASH.PFCRDE.R &= (~(uint32_t)(1UL<<(31U-(cdrIndex+PFLASH_PFCRD_SAFE_COUNT))))&0xFFFFFFFFU; /* PRQA S 2985 */
#else
    if (cdrIndex >= PFLASH_PFCRD_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }
    /* disable the corresponding Calibration Remap Descriptor */
    PFLASH.PFCRDE.R &= (~(uint32_t)(1UL<<(31U-cdrIndex)))&0xFFFFFFFFU; /* PRQA S 2985 */
#endif

    return STATUS_SUCCESS;
}

/*
 * @brief Enable Flash Global Calibration remap
 *
 * This function will enable flash global calibration remap.
 *
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Overlay_Golbal_Enable(void)
{
    /* enable the global Calibration remap */
#if PFLASH_Safe_Calibration
    PFLASH.PFCRCR.B.SAFE_CAL = 1U;
#else
    PFLASH.PFCRCR.B.SAFE_CAL = 0U;
#endif

    PFLASH.PFCRCR.B.GRMEN = 1U;

    return STATUS_SUCCESS;
}

/*
 * @brief Disable Flash Global Calibration remap
 *
 * This function will disable flash global calibration remap.
 *
 * @return Operation status
 */
SAF_FLASH_SEC_CODE
status_t SAF_FLASH_LLD_Overlay_Golbal_Disable(void)
{
    /* disable the global Calibration remap */
    PFLASH.PFCRCR.B.GRMEN = 0U;

    return STATUS_SUCCESS;
}

/*
 * @brief Config Flash Calibration Region Descriptor
 *
 * This function will config flash calibration region descriptor.
 *
 * @param[in] cdrIndex: The Index of Calibration Remap Descriptor.
 * @param[in] remapConfig: The config of Calibration Region Descriptor.
 * @return Operation status
 */
static status_t FLS_LLD_OverlayConfig(uint32_t cdrIndex, flash_remap_config_t const *remapConfig)
{
    status_t ret = STATUS_SUCCESS;

    /* check flash region count */
    if (cdrIndex < PFLASH_PFCRD_COUNT)
    {
        /* set the Logical Start Address, ensure the most 4-bit LSB are 0*/
        PFLASH.PFCRD[cdrIndex].Word0.R = remapConfig->flsLogicAddr&0xFFFFFFF0U;

        /* set the Physical Start Address, ensure the most 4-bit LSB are 0*/
        PFLASH.PFCRD[cdrIndex].Word1.R = remapConfig->ramPhyAddr&0xFFFFFFF0U;

        /* enable Crossbar master and configure the region size*/
        PFLASH.PFCRD[cdrIndex].Word2.R = 0xFFFF0000U|(uint32_t)(remapConfig->remapSize);

        /* enable the corresponding Calibration Remap Descriptor */
        PFLASH.PFCRDE.R |= ((uint32_t)(1UL<<(31U-cdrIndex)))&0xFFFFFFFFU; /* PRQA S 2985 */
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}

#if 0 // Legacy Overlay symbols are provided by Safety/flash_lld.c.
/*
 * @brief Enable Flash Calibration Region Descriptor
 *
 * This function will Enable flash calibration region descriptor.
 *
 * @param[in] cdrIndex: The Index of Calibration Remap Descriptor.
 * @param[in] remapConfig: The config of Calibration Region Descriptor.
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Config_Enable(uint32_t cdrIndex, flash_remap_config_t *remapConfig) /* PRQA S 3673, 1503  */
{
    status_t ret = STATUS_SUCCESS;

#if PFLASH_Safe_Calibration
    /* check flash region count */
    if (cdrIndex >= PFLASH_PFCRD_SAFE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    ret = FLS_LLD_OverlayConfig(cdrIndex, remapConfig);
    ret = FLS_LLD_OverlayConfig((cdrIndex+PFLASH_PFCRD_SAFE_COUNT), remapConfig);
#else
    /* check flash region count */
    if (cdrIndex >= PFLASH_PFCRD_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    ret = FLS_LLD_OverlayConfig(cdrIndex, remapConfig);
#endif

    return ret;
}

/*
 * @brief Enable Flash Global Calibration remap
 *
 * This function will enable flash global calibration remap.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Golbal_Enable(void) /* PRQA S 1503  */
{
    /* enable the global Calibration remap */
#if PFLASH_Safe_Calibration
    PFLASH.PFCRCR.B.SAFE_CAL = 1U;
#else
    PFLASH.PFCRCR.B.SAFE_CAL = 0U;
#endif

    PFLASH.PFCRCR.B.GRMEN = 1U;

    return STATUS_SUCCESS;
}

/*
 * @brief Disable Flash Calibration Region Descriptor
 *
 * This function will disable flash calibration region descriptor.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Config_Disable(uint32_t cdrIndex) /* PRQA S 1503  */
{
    status_t ret = STATUS_SUCCESS;

    /* check flash region count */
#if PFLASH_Safe_Calibration
    if (cdrIndex >= PFLASH_PFCRD_SAFE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }
    /* disable the corresponding Calibration Remap Descriptor */
    PFLASH.PFCRDE.R &= (~(uint32_t)(1UL<<(31U-cdrIndex)))&0xFFFFFFFFU; /* PRQA S 2985 */
    PFLASH.PFCRDE.R &= (~(uint32_t)(1UL<<(31U-(cdrIndex+PFLASH_PFCRD_SAFE_COUNT))))&0xFFFFFFFFU; /* PRQA S 2985 */
#else
    if (cdrIndex >= PFLASH_PFCRD_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }
    /* disable the corresponding Calibration Remap Descriptor */
    PFLASH.PFCRDE.R &= (~(uint32_t)(1UL<<(31U-cdrIndex)))&0xFFFFFFFFU; /* PRQA S 2985 */
#endif

    return STATUS_SUCCESS;
}

/*
 * @brief Disable Flash Global Calibration remap
 *
 * This function will disable flash global calibration remap.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Golbal_Disable(void) /* PRQA S 1503  */
{
    /* disable the global Calibration remap */
    PFLASH.PFCRCR.B.GRMEN = 0U;

    return STATUS_SUCCESS;
}
#endif

