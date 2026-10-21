/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx system mpu low level drivers h file
* HISTORY     : Initial version
* @file     smpu_lldriver.h
* @version  3.0.0
* @date     2023 - 06 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0883 EOF */
#ifdef MPU_ENABLE

#ifndef SMPU_LLDRIVER_H_
#define SMPU_LLDRIVER_H_


#include "derivative.h"
#include "status.h"


/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*
 * SMPU lock config
 */
#define SMPU_UNLOCK            (0U)
#define SMPU_LOCK              (1U) /* PRQA S 1534 */

/*
 * Type of error access
 */
#define SMPU_ERR_TYPE_READ       (0U)
#define SMPU_ERR_TYPE_WRITE      (1U)

/*
 * Attribute of error access attribute
 */
#define SMPU_INST_ACCESS_IN_USER_MODE         (0U) /* PRQA S 1534 */
#define SMPU_DATA_ACCESS_IN_USER_MODE         (1U) /* PRQA S 1534 */
#define SMPU_INST_ACCESS_IN_SUPERVISOR_MODE   (2U) /* PRQA S 1534 */
#define SMPU_DATA_ACCESS_IN_SUPERVISOR_MODE   (3U)

/*
 * Access rights
 */
#define SMPU_NONE    (0U)             // All accesses are not allowed
#define SMPU_W       (1U)             // Only Write allowed
#define SMPU_R       (2U)             // Only Read allowed
#define SMPU_RW      (SMPU_R|SMPU_W)  // Both Read and Write allowed

/*
 * Error access info
 */
typedef struct /* PRQA S 3630 */
{
    volatile uint8_t                overrun;
    volatile uint8_t                master;
    volatile uint8_t                attributes;
    volatile uint8_t                accType;
    volatile uint32_t               accCtr;
    volatile uint32_t               addr;
} smpu_acc_err_t;

/*
 * Structure of master access rights
 */
typedef struct /* PRQA S 3630 */
{
    uint8_t masterNum;
    uint8_t accRight;
} smpu_master_acc_right_t;

/*
 * SMPU region configuration
 */
typedef struct /* PRQA S 3630 */
{
    uint32_t                            startAddr;
    uint32_t                            endAddr;
    const smpu_master_acc_right_t       *masterAccRight;
    uint8_t                             cacheInhibitEnable;
    uint8_t                             lockConfig;
} smpu_config_t;


/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

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
                       const smpu_config_t * smpuConfig);

/*
 * @brief De-initializes system memory protection unit
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @return operation status
 */
status_t SMPU_LLD_Deinit(uint32_t instance);

/*
 * @brief config the region descriptor.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] smpuConfig The pointer to region configuration structure, see #smpu_config_t.
 * @return operation status
 */
status_t SMPU_LLD_SetRegionConfig(uint32_t instance,
                                  uint8_t regionNum,
                                  const smpu_config_t * smpuConfig);

/*
 * @brief config the region start and end address.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] startAddr The region start address.
 * @param[in] endAddr The region end address.
 * @return operation status
 */
status_t SMPU_LLD_SetRegionAddr(uint32_t instance,
                                uint8_t regionNum,
                                uint32_t startAddr,
                                uint32_t endAddr);

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
                               uint8_t enable);

/*
 * @brief config access permission of master in the region.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] masterAccRight Pointer to master access right structure, see #smpu_master_acc_right_t.
 * @return operation status
 */
status_t SMPU_LLD_SetMasterAccessRights(uint32_t instance,
                                        uint8_t regionNum,
                                        const smpu_master_acc_right_t * masterAccRight);

/*
 * @brief set the region lock configuration.
 *
 * @param[in] instance The SMPU peripheral instance number.
 * @param[in] regionNum The region number.
 * @param[in] lockConfig: SMPU_UNLOCK or SMPU_LOCK
 * @return operation status
 */
status_t SMPU_LLD_SetRegionLockConfig(uint32_t instance,
                                      uint8_t regionNum,
                                      uint8_t lockConfig);

/*
 * @brief report the region lock status.
 *
 * @param[in] instance The SMPU peripheral instance number
 * @param[in] regionNum The region number.
 * @param[out] return region lock status.
 * @return operation status
 */
status_t SMPU_LLD_GetRegionLockInfo(uint32_t instance,
                                    uint8_t regionNum,
                                    uint8_t * lockConfig);

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
                                 smpu_acc_err_t * errInfo);

/*! @} */

#if defined(__cplusplus)
}
#endif


#endif /* SMPU_LLDRIVER_H_ */

#endif /* MPU_ENABLE */
/*******************************************************************************
 * EOF
 *******************************************************************************/
