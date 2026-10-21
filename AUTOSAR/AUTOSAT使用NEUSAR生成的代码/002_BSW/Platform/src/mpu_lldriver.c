/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx core mpu low level drivers code
* HISTORY     : Initial version
* @file     cmpu_lld.c
* @version  1.0
* @date     2023 - 06 - 09
* @brief    Initial version.
*
*****************************************************************************/
#ifdef MPU_ENABLE

#include "mpu_lldriver.h" /* PRQA S 0380 */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Special register MAS0 value */
static uint32_t mas0 = 0UL;
/* Special register MAS1 value */
static uint32_t mas1 = 0UL;
/* Special register MAS2 value */
static uint32_t mas2 = 0UL;
/* Special register MAS3 value */
static uint32_t mas3 = 0UL;
/* Special register CSR0 value */
static uint32_t csr0 = 0UL;

/*******************************************************************************
 * Code
 *******************************************************************************/

/*
 * @brief Checks to see if the region ID is valid for selected region
 * type and configures the bit fields accordingly.
 *
 * @param[in] regId Entry number of the region
 * @param[in] regType Region type of the entry
 * @param[out] reg Pointer to where the reg value will be stored
 * @return operation status
 */
static status_t CMPU_ConfigRegion(uint8_t regId,
                                  uint8_t regType,
                                  uint32_t *reg)
{
    status_t ret = STATUS_SUCCESS;
    uint32_t region = 0x0U;

    /* Check regId and regType */
    if (regType == CMPU_DATA_REGION)
    {
        /* Data Region */
        if (regId < 12U)
        {
            region = CMPU_MAS0_INST(0UL) | CMPU_MAS0_SHD(0UL);
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }
    else if (regType == CMPU_SHARED_DATA_REGION)
    {
        /* Shared Data Region */
        if (regId < 6U)
        {
            region = CMPU_MAS0_INST(0UL) | CMPU_MAS0_SHD(1UL);
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }
    else if (regType == CMPU_EXEC_REGION)
    {
        /* Instruction Region */
        if (regId < 6U)
        {
            region = CMPU_MAS0_INST(1UL) | CMPU_MAS0_SHD(0UL);
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }
    else if (regType == CMPU_SHARED_EXEC_REGION)
    {
        /* Shared Instruction Region */
        if (regId < 6U)
        {
            region = CMPU_MAS0_INST(1UL) | CMPU_MAS0_SHD(1UL);
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }
    else
    {
        ret = STATUS_ERROR;
    }

    /* Set reg value */
    if (ret == STATUS_SUCCESS)
    {
        (*reg) |= region | CMPU_MAS0_ESEL(regId); /* PRQA S 2985 */
    }

    return ret;
}

/*
 * @brief Configures the entry ID to the MPU Assist Register 0 and reads
 * from the MPU the configuration into the MPU Assist Registers.
 *
 * @param[in] entryCfg Pointer to the configuration structure of an entry
 * @return operation status
 */
static status_t CMPU_ConfigEntry(const cmpu_entry_cfg_t *entryCfg) /* PRQA S 3006 */
{
    status_t ret = STATUS_SUCCESS;

    /* Initialize MAS values */
    mas0 = 0x00000030UL | CMPU_MAS0_SEL(0x2UL);
    mas1 = 0x00000000UL;
    mas2 = 0x00000000UL;
    mas3 = 0x00000000UL;

    /* Configure invalidation, read-only, debug behavior. */
    mas0 |= CMPU_MAS0_VALID(1UL)
            | CMPU_MAS0_IPROT(entryCfg->iprot)
            | CMPU_MAS0_RO(entryCfg->readOnly)
            | CMPU_MAS0_DEBUG(entryCfg->debug);

    /* Configure the entry as a data or instruction region */
    ret = CMPU_ConfigRegion(entryCfg->regId, entryCfg->regType, &mas0);

    if (ret == STATUS_SUCCESS)
    {
        /* Check addrMask range */
        if (entryCfg->addrMask < 6U)
        {
            mas0 |= CMPU_MAS0_UAMSK(entryCfg->addrMask); /* PRQA S 2985 */
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }

    if (ret == STATUS_SUCCESS)
    {
        /* Configure access rights, cache inhibit and guard behavior. */
        mas0 |= CMPU_MAS0_UW((uint32_t)entryCfg->uRight >> 2U)
              | CMPU_MAS0_UXR(entryCfg->uRight)
              | CMPU_MAS0_SW((uint32_t)entryCfg->sRight >> 2U)
              | CMPU_MAS0_SXR(entryCfg->sRight)
              | CMPU_MAS0_IOVR(entryCfg->cacheInhibitOverride)
              | CMPU_MAS0_GOVR(entryCfg->guardOverride)
              | CMPU_MAS0_I(entryCfg->cacheInhibit)
              | CMPU_MAS0_G(entryCfg->guard);

        /* Configure region TID and TIDMSK bits. */
        mas1 = CMPU_MAS1_TID(entryCfg->tid)          /* PRQA S 2985 */
              | CMPU_MAS1_TIDMSK(entryCfg->tidMask); /* PRQA S 2985 */

        /* Write MPU entry to MPU Assist Registers */
        MTSPR(SPR_MAS0, mas0); /* PRQA S 1006 */
        MTSPR(SPR_MAS1, mas1); /* PRQA S 1006 */
        MTSPR(SPR_MAS2, entryCfg->endAddr); /* PRQA S 1006 */
        MTSPR(SPR_MAS3, entryCfg->startAddr); /* PRQA S 1006 */

        /* Configure MPU entry using the MAS registers*/
        CMPUWE(); /* PRQA S 1006 */
        CMPUSYNC(); /* PRQA S 1006 */
    }

    return ret;
}

/*
 * @brief Configures the Core MPU module and enables the MPU
 *
 * @param[in] mpuCfg Pointer to the configuration structure of the MPU module
 * @return operation status
 */
static status_t CMPU_ConfigModule(const cmpu_module_cfg_t *mpuCfg) /* PRQA S 3006 */
{
    status_t ret = STATUS_SUCCESS;

    /* Initialize CSR0 value */
    csr0 = 0x00000000UL;

    /* Check Bypass and Debug */
    if ((mpuCfg->uBypass > (uint8_t)CMPU_BYPASS_ALL)
        || (mpuCfg->sBypass > (uint8_t)CMPU_BYPASS_ALL)
        || (mpuCfg->debugOpt > (uint8_t)CMPU_DEBUG_ALL))
    {
        ret = STATUS_ERROR;
    }
    else
    {
        /* Configure Control and Status Register value */
        csr0 = CMPU_CSR_BYPS(mpuCfg->sBypass)  /* PRQA S 2985 */
              | CMPU_CSR_BYPU(mpuCfg->uBypass) /* PRQA S 2985 */
              | CMPU_CSR_DEN(mpuCfg->debugOpt) /* PRQA S 2985 */
              | CMPU_CSR_TIDCTL(mpuCfg->tidCtrl)
              | CMPU_CSR_MPUEN(1UL);

        /* Write the config to the CSR register */
        MTSPR(SPR_MPU0CSR0, csr0); /* PRQA S 1006 */
        CMPUSYNC(); /* PRQA S 1006 */
    }
    return ret;
}


/*
 * @brief This function initializes the Core MPU and configures the
 * region entries. It enables the MPU module.
 *
 * @param[in] mpuConfig Pointer to the MPU module configuration structure
 * @param[in] entriesConfig Array containing all entries configuration structures
 * @param[in] entriesCount Number of entries in the array
 * @return operation status
 */
status_t CMPU_LLD_Init(const cmpu_module_cfg_t *mpuConfig,
                        const cmpu_entry_cfg_t *entriesConfig,
                        const uint8_t entriesCount)
{
    status_t ret = STATUS_SUCCESS;
    uint32_t regionSize = 0U;
    uint8_t index = 0U;

    /* check mpuConfig, entriesConfig, entriesCount */
    if ((mpuConfig == NULL) || (entriesConfig == NULL) || (entriesCount >= 25U))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* Check that MPU module is not already enabled */
    if ((((uint32_t)MFSPR(SPR_MPU0CSR0)) & CMPU_CSR_MPUEN_MASK) == 1U) /* PRQA S 1006 */
    {
        ret = STATUS_ERROR;
    }

    /* Configure all regions */
    for (index = 0U; (index < entriesCount) && (ret == STATUS_SUCCESS); index++)
    {
        /* Check startAddr and endAddr is valid or not */
        if (entriesConfig[index].startAddr > entriesConfig[index].endAddr) /* PRQA S 0492 */
        {
            ret = STATUS_ERROR;
        }

        if (ret == STATUS_SUCCESS)
        {
            /* Check size of the region */
            regionSize = entriesConfig[index].endAddr - entriesConfig[index].startAddr; /* PRQA S 0492 */
            if (regionSize == 0U)
            {
                continue;
            }
            else if (regionSize < CMPU_MIN_REGION_SIZE)
            {
                ret = STATUS_ERROR;
            }
            else
            {
                ret = CMPU_ConfigEntry(&(entriesConfig[index])); /* PRQA S 0492 */
            }
        }
    }

    /* Configure and enable CMPU */
    if (ret == STATUS_SUCCESS)
    {
        ret = CMPU_ConfigModule(mpuConfig);
    }

    return ret;
}

/*
 * @brief This function de-initializes the core MPU and invalidates all
 * entries that are not protected.
 */
void CMPU_LLD_DeInit(void) /* PRQA S 3006 */
{
    /* Set Invalidate bit to start the hardware invalidation process */
    MTSPR(SPR_MPU0CSR0, CMPU_CSR_MPUFI(1U)); /* PRQA S 1006 */

    /* Wait the invalidation process to be finished */
    csr0 = (uint32_t)MFSPR(SPR_MPU0CSR0); /* PRQA S 1006 */
    while (csr0 != 0UL)
    {
        csr0 = (uint32_t)MFSPR(SPR_MPU0CSR0); /* PRQA S 1006 */
    }
}

/*
 * @brief This function invalidates all entries that are not protected.
 *
 */
void CMPU_LLD_Invalidate(void) /* PRQA S 3006 */
{
    csr0 = (uint32_t)MFSPR(SPR_MPU0CSR0); /* PRQA S 1006 */
    csr0 |= CMPU_CSR_MPUFI(1UL);
    /* Set Invalidate bit to start the hardware invalidation process */
    MTSPR(SPR_MPU0CSR0, csr0); /* PRQA S 1006 */

    CMPUSYNC(); /* PRQA S 1006 */

    /* Wait the invalidation process to be finished */
    csr0 = (uint32_t)MFSPR(SPR_MPU0CSR0); /* PRQA S 1006 */
    while ((csr0 & (~(CMPU_CSR_MPUFI(1UL)))) == 0U)
    {
        csr0 = (uint32_t)MFSPR(SPR_MPU0CSR0); /* PRQA S 1006 */
    }
}

/*
 * @brief This function reads the requested entry from the MPU and
 * returns the configuration as a structure.
 *
 * @param[in] regId Entry number of the region
 * @param[in] regType Region type of the entry
 * @param[out] entryConfig Pointer to where the selected entry config will be stored
 * @return operation status
 */
status_t CMPU_LLD_GetEntryConfig(const uint8_t regId, /* PRQA S 3006 */
                                    const uint8_t regType,
                                    cmpu_entry_cfg_t *entryConfig)
{
    status_t ret = STATUS_SUCCESS;

    /* check entryConfig */
    if (entryConfig == NULL)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* Initialize MAS values */
    mas0 = 0x00000030UL | CMPU_MAS0_SEL(0x2UL);
    mas1 = 0x00000000UL;
    mas2 = 0x00000000UL;
    mas3 = 0x00000000UL;

    /* Check if region ID is valid and get mas0 */
    ret = CMPU_ConfigRegion(regId, regType, &mas0);

    if (ret == STATUS_SUCCESS)
    {
        /* Read CMPU entry into MPU Assist registers */
        MTSPR(SPR_MAS0, mas0); /* PRQA S 1006 */
        CMPURE(); /* PRQA S 1006 */
        CMPUSYNC(); /* PRQA S 1006 */

        /* Read configuration for selected entry */
        mas0 = (uint32_t)MFSPR(SPR_MAS0); /* PRQA S 1006 */
        mas1 = (uint32_t)MFSPR(SPR_MAS1); /* PRQA S 1006 */
        mas2 = (uint32_t)MFSPR(SPR_MAS2); /* PRQA S 1006 */
        mas3 = (uint32_t)MFSPR(SPR_MAS3); /* PRQA S 1006 */

        /* Check if this entry is valid or not. */
        if (CMPU_MAS0_VALID_GET(mas0) == 0UL)
        {
            ret = STATUS_ERROR;
        }
    }
    if (ret == STATUS_SUCCESS)
    {
        /* Get Config from the MPU Assist Registers */
        entryConfig->iprot                = (uint8_t)CMPU_MAS0_IPROT_GET(mas0);
        entryConfig->readOnly             = (uint8_t)CMPU_MAS0_RO_GET(mas0);
        entryConfig->debug                = (uint8_t)CMPU_MAS0_DEBUG_GET(mas0);
        entryConfig->regId                = (uint8_t)CMPU_MAS0_ESEL_GET(mas0);
        entryConfig->addrMask             = (uint8_t)CMPU_MAS0_UAMSK_GET(mas0);
        entryConfig->cacheInhibitOverride = (uint8_t)CMPU_MAS0_IOVR_GET(mas0);
        entryConfig->guardOverride        = (uint8_t)CMPU_MAS0_GOVR_GET(mas0);
        entryConfig->cacheInhibit         = (uint8_t)CMPU_MAS0_I_GET(mas0);
        entryConfig->guard                = (uint8_t)CMPU_MAS0_G_GET(mas0);
        entryConfig->tid                  = (uint8_t)CMPU_MAS1_TID_GET(mas1);
        entryConfig->tidMask              = (uint8_t)CMPU_MAS1_TIDMSK_GET(mas1); /* PRQA S 2985 */
        entryConfig->uRight = (uint8_t)((CMPU_MAS0_UW_GET(mas0) << 2U) | CMPU_MAS0_UXR_GET(mas0));
        entryConfig->sRight = (uint8_t)((CMPU_MAS0_SW_GET(mas0) << 2U) | CMPU_MAS0_SXR_GET(mas0));
        /* Get region type */
        if (CMPU_MAS0_SHD_GET(mas0) == 1UL)
        {
            if (CMPU_MAS0_INST_GET(mas0) == 1UL)
            {
                entryConfig->regType = CMPU_SHARED_EXEC_REGION;
            }
            else
            {
                entryConfig->regType = CMPU_SHARED_DATA_REGION;
            }
        }
        else
        {
            if (CMPU_MAS0_INST_GET(mas0) == 1UL)
            {
                entryConfig->regType = CMPU_EXEC_REGION;
            }
            else
            {
                entryConfig->regType = CMPU_DATA_REGION;
            }
        }
        /* Get startAddr and endAddr */
        entryConfig->endAddr = mas2;
        entryConfig->startAddr = mas3;
    }

    return ret;
}

/*
 * @brief This function reads the current configuration of the MPU module
 *
 * @param[out] mpuCfg Pointer to the MPU module structure to store config
 * @return operation status
 */
status_t CMPU_LLD_GetModuleConfig(cmpu_module_cfg_t *mpuCfg)
{
    status_t ret = STATUS_SUCCESS;

    /* check mpuCfg */
    if (mpuCfg == NULL)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* Initialize CSR0 value */
    csr0 = 0x00000000UL;

    /* Read the CSR0 from the SPR register */
    csr0 = (uint32_t)MFSPR(SPR_MPU0CSR0); /* PRQA S 1006 */

    /* Get config from the CSR0 */
    mpuCfg->sBypass  = (uint8_t)CMPU_CSR_BYPS_GET(csr0);
    mpuCfg->uBypass  = (uint8_t)CMPU_CSR_BYPU_GET(csr0);
    mpuCfg->debugOpt = (uint8_t)CMPU_CSR_DEN_GET(csr0);
    mpuCfg->tidCtrl  = (uint8_t)CMPU_CSR_TIDCTL_GET(csr0);

    return ret;
}

/*
 * @brief This function set entry into MPU
 *
 * @param[in] entryConfig Pointer to the entry configuration structure
 * @return operation status
 */
status_t CMPU_LLD_SetEntry(const cmpu_entry_cfg_t *entryConfig)
{
    status_t ret = STATUS_SUCCESS;

    /* Check entryConfig */
    if (entryConfig == NULL)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* Check address range */
    if ((entryConfig->endAddr - entryConfig->startAddr) < CMPU_MIN_REGION_SIZE)
    {
        ret = STATUS_ERROR;
    }
    else
    {
        /* Config entry */
        ret = CMPU_ConfigEntry(entryConfig);
    }

    return ret;
}

#endif /* MPU_ENABLE */
/*******************************************************************************
 * EOF
 *******************************************************************************/
