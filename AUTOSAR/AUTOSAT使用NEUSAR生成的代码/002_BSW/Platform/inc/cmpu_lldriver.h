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
* @file     cmpu_lldriver.h
* @version  3.0.0
* @date     2023 - 06 - 01
* @brief    Initial version.
*
*****************************************************************************/
/* PRQA S 0883 EOF */
#ifdef MPU_ENABLE

#ifndef LLD_INC_CMPU_LLD_H_
#define LLD_INC_CMPU_LLD_H_

#include "typedefs.h"
#include "compiler_api.h"
#include "derivative.h"
#include "status.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 * CMPU instructions
 */

/* CMPU read entry
 * Note: When CMPURE is invoked, data is read from the MPU into the MAS registers. */
#define CMPURE()    PPCASM("mpure")
/* CMPU write entry
 * Note: When CMPUWE is invoked, data is written to the MPU from the MAS registers. */
#define CMPUWE()    PPCASM("mpuwe")
/* CMPU synchronize */
#define CMPUSYNC()  PPCASM("mpusync")

/* No bypass acceptable */
#define CMPU_BYPASS_NONE  (0x0U)
/* Instruction protection can be bypassed */
#define CMPU_BYPASS_EXEC  (0x1U)
/* Write data protection can be bypassed */
#define CMPU_BYPASS_WRITE (0x2U)
/* Read data protection can be bypassed */
#define CMPU_BYPASS_READ  (0x4U)
/* No debug event can be generated */
#define CMPU_DEBUG_NONE   (0x0U)
/* Instruction access can generate debug events */
#define CMPU_DEBUG_EXEC   (0x1U)
/* Write data access can generate debug events */
#define CMPU_DEBUG_WRITE  (0x2U)
/* Read data access can generate debug events */
#define CMPU_DEBUG_READ   (0x4U)
/* Define for all access value */
#define CMPU_BYPASS_ALL (CMPU_BYPASS_EXEC | CMPU_BYPASS_READ | CMPU_BYPASS_WRITE)
#define CMPU_DEBUG_ALL  (CMPU_DEBUG_EXEC | CMPU_DEBUG_READ | CMPU_DEBUG_WRITE)

/*
 * CMPU access rights options
 */
#define CMPU_NONE    (0x0U)          // All accesses are not allowed
#define CMPU_R       (0x1U)          // Instruct or (Data read) is allowed
#define CMPU_W       (0x4U)          // Data write is allowed
#define CMPU_RW      (CMPU_R|CMPU_W) // Instruct or (Data read and write) is allowed

/*
 * CMPU region types options
 */
#define CMPU_DATA_REGION         (0x1U) // Region is used for data
#define CMPU_EXEC_REGION         (0x2U) // Region is used for instruction
#define CMPU_SHARED_DATA_REGION  (0x3U) // Shared region is used for data
#define CMPU_SHARED_EXEC_REGION  (0x4U) // Shared region is used for instruction

/*
 * CMPU entry configuration structure
 */
typedef struct /* PRQA S 3630 */
{
    uint8_t                     iprot;                // Invalidation protection
    uint8_t                     readOnly;             // Read-Only attribute for entry
    uint8_t                     debug;                // Debug event generation behaviour
    uint8_t                     regType;              // Region type
    uint8_t                     regId;                // Region ID
    uint8_t                     addrMask;             // Masking of upper address bits
    uint8_t                     uRight;               // User region access rights
    uint8_t                     sRight;               // Supervisor region access rights
    uint8_t                     cacheInhibitOverride; // Override for cache-inhibit attribute
    uint8_t                     guardOverride;        // Override for guard attribute
    uint8_t                     cacheInhibit;         // Cache Inhibit attribute for entry
    uint8_t                     guard;                // Guard attribute for data regions
    uint8_t                     tid;                  // Region ID bits
    uint8_t                     tidMask;              // Masking support of TID bits
    uint32_t                    startAddr;            // Lower bound of memory region
    uint32_t                    endAddr;              // Upper bound of memory region
} cmpu_entry_cfg_t;

/*
 * CMPU configuration structure
 */
typedef struct /* PRQA S 3630 */
{
    uint8_t     sBypass;   // Bypass options for supervisor mode
    uint8_t     uBypass;   // Bypass options for user mode
    uint8_t     debugOpt;  // Debug event generation behaviour
    uint8_t     tidCtrl;   // TID usage control
} cmpu_module_cfg_t;


/*******************************************************************************
 * API
 *******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif


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
                        const uint8_t entriesCount);

/*
 * @brief This function de-initializes the core MPU and invalidates all
 * entries that are not protected.
 */
void CMPU_LLD_DeInit(void);

/*
 * @brief This function invalidates all entries that are not protected.
 *
 */
void CMPU_LLD_Invalidate(void);

/*
 * @brief This function reads the requested entry from the MPU and
 * returns the configuration as a structure.
 *
 * @param[in] regId Entry number of the region
 * @param[in] regType Region type of the entry
 * @param[out] entryConfig Pointer to where the selected entry config will be stored
 * @return operation status
 */
status_t CMPU_LLD_GetEntryConfig(const uint8_t regId,
                                    const uint8_t regType,
                                    cmpu_entry_cfg_t *entryConfig);

/*
 * @brief This function reads the current configuration of the MPU module
 *
 * @param[out] mpuCfg Pointer to the MPU module structure to store config
 * @return operation status
 */
status_t CMPU_LLD_GetModuleConfig(cmpu_module_cfg_t *mpuCfg);

/*
 * @brief This function set entry into MPU
 *
 * @param[in] entryConfig Pointer to the entry configuration structure
 * @return operation status
 */
status_t CMPU_LLD_SetEntry(const cmpu_entry_cfg_t *entryConfig);


#if defined(__cplusplus)
}
#endif


#endif /* LLD_INC_CMPU_LLD_H_ */


#endif /* MPU_ENABLE */
/*******************************************************************************
 * EOF
 *******************************************************************************/
