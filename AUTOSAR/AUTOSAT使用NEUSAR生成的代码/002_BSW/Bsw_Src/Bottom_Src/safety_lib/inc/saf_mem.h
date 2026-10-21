/**
****************************************************************************************
 * @FilePath: saf_mem.h
 * @Author: CCORE
 * @Date: 2024-01-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety memory head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_MEM_H
#define SAF_MEM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
#define SAF_MEM_ERROR_INFO_NUM                               (16U)

/* Define ram ECC test intc flag */
#define SAFETY_INTC_INITIAL                                  (1U)
#define SAFETY_INTC_NO_INITIAL                               (0U)
/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  The memory type.
*/
typedef enum
{
    SAF_MEM_SRAM  = 0,
    SAF_MEM_PRAM  = 1,/*PRQA S 0722*/
    SAF_MEM_FLASH = 2,/*PRQA S 0722*/
	SAF_MEM_ITCM  = 3,/*PRQA S 0722*/
} SAF_MEM_TYPE;

/**
* @brief  The memory error type.
*/
typedef enum
{
    SAF_MEM_CE_BIT_ERR,
    SAF_MEM_UCE_BIT_ERR,
	SAF_MEM_NONE_BIT_ERR
} SAF_MEM_ERR_TYPE;

/**
* @brief  The detected memory error information.
*/
typedef struct
{
    /* Memory error type array. */
    SAF_MEM_ERR_TYPE errType[SAF_MEM_ERROR_INFO_NUM];
    /* Memory type array. */
    SAF_MEM_TYPE errMemType[SAF_MEM_ERROR_INFO_NUM];
    /* Memory error address array. */
    uint32_t errAddr[SAF_MEM_ERROR_INFO_NUM];
    /* Memory error count. */
    uint32_t errCount;
} saf_mem_err_detect_info_t;

/**
* @brief  The cleaned memory error information.
*/
typedef struct
{
    SAF_MEM_ERR_TYPE errType;
    uint32_t errAddr;
} saf_mem_err_clean_info_t;/*PRQA S 1535*/

/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

void SAF_MEM_ErrorReportInit(const SAF_MEM_TYPE memType);

FS_STATUS SAF_MEM_GetEccErrorResult(const SAF_MEM_TYPE memErrType, const uint32_t addr, SAF_MEM_ERR_TYPE *pMemErrType);

void SAF_MEM_CleanAllErr(const SAF_MEM_TYPE memType);

FS_STATUS SAF_MEM_DetectAllErr(const SAF_MEM_TYPE memType, saf_mem_err_detect_info_t *pMemInfo);

#if defined (__cplusplus)
}
#endif

#endif

