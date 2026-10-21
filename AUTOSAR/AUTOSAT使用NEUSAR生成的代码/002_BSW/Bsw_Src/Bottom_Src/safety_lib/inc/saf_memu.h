/**
****************************************************************************************
 * @FilePath: saf_memu.h
 * @Author: CCORE
 * @Date: 2024-01-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Memu head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_MEMU_H
#define SAF_MEMU_H

#ifdef __cplusplus
extern "C"{
#endif
/*PRQA S 0722 EOF*/

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "saf_mem.h"
#include "derivative.h"

#if SAF_MEMU_SUPPORTED

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
typedef  struct MEMU_tag                           MEMU_Type;

/* Array initializer of MEMU peripheral base addresses */
#define SAF_MEMU_BASE_ADDRS                          ((uint32_t)&MEMU)
/* Peripheral MEMU base address */
#define SAF_MEMU_BASE                                ((MEMU_Type *)SAF_MEMU_BASE_ADDRS)
/* Array initializer of MEMU peripheral base pointers */
#define SAF_MEMU_BASE_PTRS                           {SAF_MEMU_BASE}

#define SAF_MEMU_SRAM_CE_CHAN_COUNT                  MEMU_SYS_RAM_CERR_COUNT
#define SAF_MEMU_PRAM_CE_CHAN_COUNT                  MEMU_PERIPH_RAM_CERR_COUNT
#define SAF_MEMU_FLASH_CE_CHAN_COUNT                 MEMU_FLASH_CERR_COUNT

/* F_CE. */
#define SAF_MEMU_FLASH_CORRECTABLE_ERROR_DETECT         1U
#define SAF_MEMU_FLASH_CORRECTABLE_ERROR_NOT_DETECT     0U
/* F_CE clear. */
#define SAF_MEMU_FLASH_CORRECTABLE_ERROR_CLEAR          1U

/* F_UCE. */
#define SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_DETECT       1U
#define SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_NOT_DETECT   0U
/* F_UCE clear. */
#define SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_CLEAR        1U

/* SR_CE. */
#define SAF_MEMU_SRAM_CORRECTABLE_ERROR_DETECT          1U
#define SAF_MEMU_SRAM_CORRECTABLE_ERROR_NOT_DETECT      0U
/* SR_CE. */
#define SAF_MEMU_SRAM_CORRECTABLE_ERROR_CLEAR           1U

/* SR_UCE. */
#define SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_DETECT        1U
#define SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_NOT_DETECT    0U
/* SR_UCE clear. */
#define SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_CLEAR         1U

/* PR_CE. */
#define SAF_MEMU_PRAM_CORRECTABLE_ERROR_DETECT          1U
#define SAF_MEMU_PRAM_CORRECTABLE_ERROR_NOT_DETECT      0U
/* PR_CE clear. */
#define SAF_MEMU_PRAM_CORRECTABLE_ERROR_CLEAR           1U

/* PR_UCE. */
#define SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_DETECT        1U
#define SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_NOT_DETECT    0U
/* PR_UCE clear. */
#define SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_CLEAR         1U

/* MEMU_FLASH_CERR_STSn. */
#define SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_VALID      1U
#define SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID    0U
/* MEMU_FLASH_UNCERR_STS. */
#define SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_VALID    1U
#define SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID  0U

/* MEMU_SYS_RAM_CERR_STSn. */
#define SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_VALID       1U
#define SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID     0U
/* MEMU_SYS_RAM_UNCERR_STS. */
#define SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_VALID     1U
#define SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID   0U

/* MEMU_PERIPH_RAM_CERR_STSn. */
#define SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_VALID       1U
#define SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID     0U
/* MEMU_PERIPH_RAM_UNCERR_STS. */
#define SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_VALID     1U
#define SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID   0U

/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  The memory error source type.
*/
typedef enum
{
    /* Memory error source : SRAM*/
    SAF_MEMU_EEROR_SOURCE_IS_SRAM = 0,
    /* Memory error source : PRAM*/
    SAF_MEMU_ERROR_SOURCE_IS_PRAM,
    /* Memory error source : FLASH*/
    SAF_MEMU_ERROR_SOURCE_IS_FLASH,
    /* Memory error source : invalid*/
    SAF_MEMU_ERROR_SOURCE_IS_INVALID,
} SAF_MEMU_ERROR_SOURCE_TYPE;

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

FS_STATUS SAF_MEMU_GetMemErrAndClean(const SAF_MEM_TYPE memType, const uint32_t addr, SAF_MEM_ERR_TYPE *pMemErrType);

void SAF_MEMU_ErrorReportInit(void);

FS_STATUS SAF_MEMU_DetectAllErr(const SAF_MEM_TYPE memType, saf_mem_err_detect_info_t *pMemInfo);

void SAF_MEMU_CleanAllErr(const SAF_MEM_TYPE memType);

#endif

#if defined (__cplusplus)
}
#endif

#endif
