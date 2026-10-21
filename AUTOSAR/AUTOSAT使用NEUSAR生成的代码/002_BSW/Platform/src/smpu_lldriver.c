/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx system mpu low level drivers code
* HISTORY     : Initial version
* @file     smpu_lldriver.c
* @version  3.0.0
* @date     2023 - 06 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 2844,0492,0491,2901 EOF*/
#ifdef MPU_ENABLE

#include "smpu_lldriver.h" /* PRQA S 0380 */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Table of base addresses for SMPU instances. */
#if (RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT == 4U)
static SMPU_Type * const smpuBase[RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT] = { SMPU0_PTR, SMPU1_PTR, SMPU2_PTR, SMPU3_PTR };
#elif (RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT == 2U)
static SMPU_Type * const smpuBase[RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT] = { SMPU0_PTR, SMPU1_PTR };
#else
    #error "SMPU instance error!"
#endif
/*******************************************************************************
 * Code
 *******************************************************************************/

/*
 * @brief Unlocks the region descriptor.
 *
 * @param[in] base The SMPU peripheral base address.
 * @param[in] regionNum The region number.
 * @return operation status
 */
static status_t SMPU_UnlockRegion(SMPU_Type * const base,
                           uint8_t regionNum)
{
    status_t ret = STATUS_SUCCESS;

    /* unlock region */
    base->RGD[regionNum].WORD3.B.RO = SMPU_UNLOCK; /* polyspace RTE:OBAI */

    /* check region is unlocked or not */
    if (base->RGD[regionNum].WORD3.B.RO != SMPU_UNLOCK)
    {
        ret = STATUS_ERROR;
    }

    return ret;
}

/*
 * @brief Sets access permission for master in region descriptor.
 *
 * @param[in] base The SMPU peripheral base address.
 * @param[in] regionNum The region number.
 * @param[in] masterNum The master number.
 * @param[in] masterAccRight The pointer to master access right structure.
 */
static void SMPU_SetMasterAccessRight(SMPU_Type * const base,
                               uint8_t regionNum,
                               const smpu_master_acc_right_t * const masterAccRight)
{
    uint32_t accRight;
    uint32_t accMask;
    uint32_t accShift;
    uint32_t temp;

    accShift = 2U * (uint32_t)(masterAccRight->masterNum);
    accMask  = (uint32_t)(0xC0000000u >> accShift); /* polyspace RTE:SHF */
    accRight = (((uint32_t)(((uint32_t)(masterAccRight->accRight)) << 30u))&0xC0000000u) >> accShift; /* PRQA S 2985 */

    /* set access right */
    temp = base->RGD[regionNum].WORD2.R; /* polyspace RTE:NIV */
    temp = (temp & ~accMask) | accRight;
    base->RGD[regionNum].WORD2.R = temp;
}

/*
 * @brief initializes system memory protection unit
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionCnt The number of regions configured.
 * @param[in] smpuConfig The pointer to user configuration structure, see #smpu_config_t.
 * @return operation status
 */
status_t SMPU_LLD_Init(uint32_t instance,
                       uint8_t regionCnt,
                       const smpu_config_t * smpuConfig)
{
    SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;
    uint8_t regionNum = 0U;

    /* check instance, smpuConfig */
    if ((instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT) || (smpuConfig == NULL))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionCnt */
    if (regionCnt > (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* de-init all region descriptor */
    ret = SMPU_LLD_Deinit(instance);

    if (ret == STATUS_SUCCESS)
    {
        for (regionNum = 0U; regionNum < regionCnt; regionNum++)
        {
            /* set region config */
            ret = SMPU_LLD_SetRegionConfig(instance, regionNum, &smpuConfig[regionNum]);

            if (ret != STATUS_SUCCESS)
            {
                break;
            }
        }

        if (ret == STATUS_SUCCESS)
        {
            /* enable the SMPU module */
            base->CESR0.B.GVLD = 1U;
        }
    }

    return ret;
}

/*
 * @brief De-initializes system memory protection unit
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @return operation status
 */
status_t SMPU_LLD_Deinit(uint32_t instance)
{
    SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;
    uint8_t regionNum = 0U;
    uint8_t masterNum = 0U;
    uint8_t maxRegionNum = 0U;

    /* check instance */
    if (instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    maxRegionNum = (base->CESR1.B.NRGD * 4U);

    /* disable the entire SMPU module */
    base->CESR0.B.GVLD = 0U;

    for (masterNum = 0U; masterNum < SMPU_ERR_COUNT; masterNum++)
    {
        /* clear master error flag */
        base->CESR0.B.MERR = (1UL << (RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX - masterNum));/* polyspace RTE:SHF */
    }

    /* de-init all region descriptors */
    for (regionNum = 0U; regionNum < maxRegionNum; regionNum++)
    {
        /* unlock region descriptors */
        ret = SMPU_UnlockRegion(base, regionNum);

        /* unlock successful */
        if (ret == STATUS_SUCCESS)
        {
            /* reset the WORD3 region */
            base->RGD[regionNum].WORD3.R = 0U;
            /* reset the WORD2 region */
            base->RGD[regionNum].WORD2.R = 0U;
            /* reset the WORD1 region */
            base->RGD[regionNum].WORD1.R = 0U;
            /* reset the WORD0 region */
            base->RGD[regionNum].WORD0.R = 0U;
        }
        else
        {
            break;
        }
    }

    return ret;
}

/*
 * @brief config the region descriptor.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] smpuConfig The pointer to region configuration structure, see #smpu_config_t.
 * @return operation status
 */
status_t SMPU_LLD_SetRegionConfig(uint32_t instance, /* PRQA S 1505 */
                                  uint8_t regionNum,
                                  const smpu_config_t * smpuConfig)
{
    SMPU_Type * base = NULL;
    uint8_t masterIdx = 0U;
    status_t ret = STATUS_SUCCESS;

    /* check instance, smpuConfig */
    if ((instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT) || (smpuConfig == NULL))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* check startAddr, endAddr */
    if (smpuConfig->startAddr > smpuConfig->endAddr )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* check masterAccRight */
    if (smpuConfig->masterAccRight == NULL)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionNum */
    if (regionNum >= (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* unlock region descriptor */
    ret = SMPU_UnlockRegion(base, regionNum);

    /* unlock region descriptor */
    if (ret == STATUS_SUCCESS)
    {
        /* set access right for masters */
        for (masterIdx = 0U; masterIdx < RESOURCE_SUPPORT_SMPU_MASTER_NUM_COUNT; masterIdx++)
        {
            if (smpuConfig->masterAccRight[masterIdx].masterNum <= RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX) /* polyspace RTE:IDP */
            {
                SMPU_SetMasterAccessRight(base,
                                          regionNum,
                                          &smpuConfig->masterAccRight[masterIdx]);
            }
            else
            {
                ret = STATUS_ERROR;
                break;
            }
        }

        if (ret == STATUS_SUCCESS)
        {
            /* write start address */
            base->RGD[regionNum].WORD0.R = smpuConfig->startAddr;

            /* write end address */
            base->RGD[regionNum].WORD1.R = smpuConfig->endAddr;

            /* set cache inhibit */
            base->RGD[regionNum].WORD3.B.CI = smpuConfig->cacheInhibitEnable;

            /* enable the region valid bit */
            base->RGD[regionNum].WORD3.B.VLD = 1U;

            /* set region lock config */
            base->RGD[regionNum].WORD3.B.RO = smpuConfig->lockConfig;
        }
    }

    return ret;
}

/*
 * @brief config the region start and end address.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] startAddr The region start address.
 * @param[in] endAddr The region end address.
 * @return operation status
 */
status_t SMPU_LLD_SetRegionAddr(uint32_t instance, /* PRQA S 1503 */
                                uint8_t regionNum,
                                uint32_t startAddr,
                                uint32_t endAddr)
{
    SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;

    /* check instance, startAddr, endAddr */
    if ((instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT) || (startAddr >  endAddr))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionNum */
    if (regionNum >= (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* unlock region descriptor */
    ret = SMPU_UnlockRegion(base, regionNum);

    /* check region unlock status */
    if (ret == STATUS_SUCCESS)
    {
        /* write start address */
        base->RGD[regionNum].WORD0.R = startAddr;

        /* write end address */
        base->RGD[regionNum].WORD1.R = endAddr;

        /* re-enable the region valid bit */
        base->RGD[regionNum].WORD3.B.VLD = 1U;
    }

    return ret;
}

/*
 * @brief enable/disable region descriptor.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] enable Valid state: 1 (enable region) or 0 (disable region)
 * @return operation status
 */
status_t SMPU_LLD_EnableRegion(uint32_t instance,
                               uint8_t regionNum,
                               uint8_t enable)
{
    SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;

    /* check instance */
    if ((instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT) || (enable > 1U))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionNum */
    if (regionNum >= (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* unlock region descriptor */
    ret = SMPU_UnlockRegion(base, regionNum);

    /* check region unlock status */
    if (ret == STATUS_SUCCESS)
    {
        /* enable/disable region */
        base->RGD[regionNum].WORD3.B.VLD = enable;
    }

    return ret;
}

/*
 * @brief config access permission of master in the region.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] masterAccRight Pointer to master access right structure, see #smpu_master_acc_right_t.
 * @return operation status
 */
status_t SMPU_LLD_SetMasterAccessRights(uint32_t instance, /* PRQA S 1503 */
                                        uint8_t regionNum,
                                        const smpu_master_acc_right_t * masterAccRight)
{
    SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;

    /* check instance, masterAccRight */
    if ((instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT) || (masterAccRight == NULL))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionNum */
    if (regionNum >= (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* unlock region */
    ret = SMPU_UnlockRegion(base, regionNum);
    if (ret == STATUS_SUCCESS)
    {
        if (masterAccRight->masterNum <= RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX)
        {
            /* set master access right */
            SMPU_SetMasterAccessRight(base, regionNum, masterAccRight);

            /* re-enable region valid */
            base->RGD[regionNum].WORD3.B.VLD = 1U;
        }
        else
        {
            ret = STATUS_ERROR;
        }
    }

    return ret;
}

/*
 * @brief set the region lock configuration.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] lockConfig: SMPU_UNLOCK or SMPU_LOCK
 * @return operation status
 */
status_t SMPU_LLD_SetRegionLockConfig(uint32_t instance, /* PRQA S 1503 */
                                      uint8_t regionNum,
                                      uint8_t lockConfig)
{
    SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;

    /* check instance */
    if (instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionNum */
    if (regionNum >= (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    /* unlock region  */
    ret = SMPU_UnlockRegion(base, regionNum);
    if (ret == STATUS_SUCCESS)
    {
        /* set region lock config */
        base->RGD[regionNum].WORD3.B.RO = lockConfig;
    }

    return ret;
}

/*
 * @brief report the region lock status.
 *
 * @param[in] instance The SMPU peripheral instance number
 * @param[in] regionNum The region number.
 * @param[out] return region lock status.
 * @return operation status
 */
status_t SMPU_LLD_GetRegionLockInfo(uint32_t instance, /* PRQA S 1503 */
                                    uint8_t regionNum,
                                    uint8_t * lockConfig)
{
    const SMPU_Type * base = NULL;
    status_t ret = STATUS_SUCCESS;

    /* check instance */
    if (instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT)
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check regionNum */
    if (regionNum >= (base->CESR1.B.NRGD * 4U) )
    {
        ret = STATUS_ERROR;
        return ret;
    }

    *lockConfig = base->RGD[regionNum].WORD3.B.RO; /* polyspace RTE:OBAI */

    return ret;
}

/*
 * @brief Checks and gets the access error detail information
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] masterNum The error master channel number.
 * @param[out] errInfo The pointer to access error info structure.
 * @return operation status
 */
status_t SMPU_LLD_GetDetailErrorInfo(uint32_t instance,
                                 uint8_t masterNum,
                                 smpu_acc_err_t * errInfo)
{
    status_t ret = STATUS_SUCCESS;
    SMPU_Type * base = NULL;

    /* check instance, masterNum, errInfo */
    if ((instance >= RESOURCE_SUPPORT_SMPU_INSTANCE_COUNT) || (masterNum >= SMPU_ERR_COUNT) || (errInfo == NULL))
    {
        ret = STATUS_ERROR;
        return ret;
    }

    base = smpuBase[instance];

    /* check error status */
    if ((base->CESR0.B.MERR & (1UL << (RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX - masterNum))) != 0U)/* polyspace RTE:SHF */
    {
        /* report error master number */
        errInfo->master = (uint8_t)(base->ERROR_REG[masterNum].EDR.B.EMN);

        /* report error attribute */
        errInfo->attributes = (uint8_t)(base->ERROR_REG[masterNum].EDR.B.EATTR);

        /* report error access type */
        errInfo->accType = (uint8_t)(base->ERROR_REG[masterNum].EDR.B.ERW);

        /* report Error Access Control Detail */
        errInfo->accCtr = (uint32_t)(base->ERROR_REG[masterNum].EDR.B.EACD);

        /* report error address */
        errInfo->addr = base->ERROR_REG[masterNum].EAR.R;

        /* report master error overrun status */
        errInfo->overrun = (((base->CESR1.B.MEOVR
                                & (1UL << (RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX - masterNum)))
                                != 0U) ? 1U : 0U);

        /* clear error flag */
        base->CESR0.B.MERR = (1UL << (RESOURCE_SUPPORT_SMPU_BUS_MASTER_NUM_MAX - masterNum));
    }
    else
    {
        ret = STATUS_ERROR;
    }

    return ret;
}

#endif /* MPU_ENABLE */
/*******************************************************************************
 * EOF
 *******************************************************************************/
