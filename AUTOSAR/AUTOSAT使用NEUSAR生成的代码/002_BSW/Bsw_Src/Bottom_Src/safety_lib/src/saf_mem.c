/**
****************************************************************************************
 * @FilePath: saf_mem.c
 * @Author: CCORE
 * @Date: 2024-01-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety memory C File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_mem.h"
#include "saf_cpu.h"/*PRQA S 0380*/
#include "saf_memu.h"
#include "intc_lld.h"
#include "Saf_MemMap.h"

/**
****************************************************************************************
 * @brief: Variables
****************************************************************************************
*/
extern const uint32_t IntcIsrVectorTable[];/*PRQA S 3684*/
extern void VTABLE(void);
/*******************************************************************************
 * Global Functions
 ******************************************************************************/
/**
****************************************************************************************
* @brief:  This function is used to initialize memory error report.
* @param[in]    memErrType  memory error area.
* @return       void
****************************************************************************************
*/
SAF_MEM_SEC_CODE
void SAF_MEM_ErrorReportInit(const SAF_MEM_TYPE memType)
{
#if SAF_MEMU_SUPPORTED
    (void)memType;/*PRQA S 3119*/
    SAF_MEMU_ErrorReportInit();
#endif

}

/**
****************************************************************************************
* @brief:  This function is used to get the result of memory ECC error.
* @param[in]    memErrType   memory error area.
* @param[in]    addr         expected error address.
* @param[in]    pMemErrType  memory error type.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get the result of memory ECC error succeed
*               FS_STATUS_ERROR       get the result of memory ECC error failed
****************************************************************************************
*/
SAF_MEM_SEC_CODE
FS_STATUS SAF_MEM_GetEccErrorResult(const SAF_MEM_TYPE memErrType, const uint32_t addr, SAF_MEM_ERR_TYPE *pMemErrType)
{ 
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pMemErrType)
    {  
#if SAF_MEMU_SUPPORTED
       status = SAF_MEMU_GetMemErrAndClean(memErrType, addr, pMemErrType);
#endif
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to detect all memory error.
* @param[in]    memType      memory error area.
* @param[out]   pMemInfo     memory error information buffer.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     detect succeed
*               FS_STATUS_ERROR       detect failed
****************************************************************************************
*/
SAF_MEM_SEC_CODE
FS_STATUS SAF_MEM_DetectAllErr(const SAF_MEM_TYPE memType, saf_mem_err_detect_info_t *pMemInfo)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (pMemInfo != NULL)
    {
        memset(pMemInfo, 0, sizeof(saf_mem_err_detect_info_t));/*PRQA S 0315,3200*/
#if SAF_MEMU_SUPPORTED
        status = SAF_MEMU_DetectAllErr(memType, pMemInfo);
#endif
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to clean all memory error.
* @param[in]    memType      memory error area.
* @return       void
****************************************************************************************
*/
SAF_MEM_SEC_CODE
void SAF_MEM_CleanAllErr(const SAF_MEM_TYPE memType)
{

#if SAF_MEMU_SUPPORTED
        SAF_MEMU_CleanAllErr(memType);
#endif

}



#ifdef __cplusplus
}
#endif
