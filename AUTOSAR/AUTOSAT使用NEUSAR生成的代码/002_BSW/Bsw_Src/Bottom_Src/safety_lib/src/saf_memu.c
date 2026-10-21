/**
****************************************************************************************
 * @FilePath: saf_memu.c
 * @Author: CCORE
 * @Date: 2024-01-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Memu C File
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
#include "saf_memu.h"/*PRQA S 0380*/
#include "saf_mem.h"
#include "Saf_MemMap.h"
/*PRQA S 1881,2844,3344,3400,3401,3397,4304,4404,4559 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_MEMU_SEC_VAR_INIT
MEMU_Type *s_pMemuRegList[SAF_MEMU_INSTANCE_COUNT] = SAF_MEMU_BASE_PTRS;/*PRQA S 3408*/


/**
****************************************************************************************
 * @brief: Local Function
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  This function is used to detect if the single bit error is valid.
* @param[in]    memuInst    memu instance.
* @param[in]    type        error reporting memory area.
* @param[in]    chanId      memu channel id(reporting table entries).
* @return       bool
*               true        single bit error is valid
*               false       single bit error is not valid
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static bool SAF_MEMU_AccessCEErrAddrIsValid(const uint8_t memuInst, const SAF_MEM_TYPE type, const uint8_t chanId)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];
    bool ret = false;
    
    if (SAF_MEM_SRAM == type)
    {
        ret = (SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->SYS_RAM_CERR[chanId].STS.B.VLD)) ? true : false;/* polyspace RTE:NIV */
    }
    else if (SAF_MEM_PRAM == type)
    {
        ret = (SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->PERIPH_RAM_CERR[chanId].STS.B.VLD)) ? true : false;/* polyspace RTE:NIV */
    }
    else if (SAF_MEM_FLASH == type)
    {
        ret = (SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->FLASH_CERR[chanId].STS.B.VLD)) ? true : false;/* polyspace RTE:NIV */
    }
    else
    {
        /* Do nothing for satisfy the misra 2012. */
    }
    
    return ret;
}

/**
****************************************************************************************
* @brief:  This function is used to detect if the multiple bit error is valid.
* @param[in]    memuInst    memu instance.
* @param[in]    type        error reporting memory area.
* @return       bool
*               true        multiple bit error is valid
*               false       multiple bit error is not valid
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static bool SAF_MEMU_AccessUCEErrAddrIsValid(const uint8_t memuInst, const SAF_MEM_TYPE type)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];
    bool ret = false;
    
    if (SAF_MEM_SRAM == type)
    {
        ret = (SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->SYS_RAM_UNCERR_STS.B.VLD)) ? true : false;/* polyspace RTE:NIV */
    }
    else if (SAF_MEM_PRAM == type)
    {
        ret = (SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->PERIPH_RAM_UNCERR_STS.B.VLD)) ? true : false;/* polyspace RTE:NIV */
    }
    else if (SAF_MEM_FLASH == type)
    {
        ret = (SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->FLASH_UNCERR_STS.B.VLD)) ? true : false;/* polyspace RTE:NIV */
    }
    else
    {
        /* Do nothing for satisfy the misra 2012. */
    }

    return ret;
}


/**
****************************************************************************************
* @brief:  This function is used to get the single bit error address.
* @param[in]    memuInst    memu instance.
* @param[in]    type        error reporting memory area.
* @param[in]    chanId      memu channel id(reporting table entries).
* @return       uint32_t    single bit error address
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static uint32_t SAF_MEMU_AccessGetMemCEErrAddr(const uint8_t memuInst, const SAF_MEM_TYPE type, const uint8_t chanId)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];
    uint32_t addr = 0;
    
    if (SAF_MEM_SRAM == type)
    {
        addr = pBase->SYS_RAM_CERR[chanId].ADDR.B.ERR_ADD; /* polyspace RTE:NIV */
    }
    else if (SAF_MEM_PRAM == type)
    {
        addr = pBase->PERIPH_RAM_CERR[chanId].ADDR.B.ERR_ADD; /* polyspace RTE:NIV */
    }
    else if (SAF_MEM_FLASH == type)
    {
        addr = pBase->FLASH_CERR[chanId].ADDR.B.ERR_ADD; /* polyspace RTE:NIV */
    }
    else
    {
        /* do nothing for satisfy the misra 2012*/
    }
    
    return addr;
}


/**
****************************************************************************************
* @brief:  This function is used to get the multiple bit error address.
* @param[in]    memuInst    memu instance.
* @param[in]    type        error reporting memory area.
* @return       uint32_t    multiple bit error address
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static uint32_t SAF_MEMU_AccessGetMemUCEErrAddr(const uint8_t memuInst, const SAF_MEM_TYPE type)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];
    uint32_t addr = 0;
    
    if (type == SAF_MEM_SRAM)
    {
        addr = pBase->SYS_RAM_UNCERR_ADDR.B.ERR_ADD; /* polyspace RTE:NIV */
    }
    else if (type == SAF_MEM_PRAM)
    {
        addr = pBase->PERIPH_RAM_UNCERR_ADDR.B.ERR_ADD; /* polyspace RTE:NIV */
    }
    else if (type == SAF_MEM_FLASH)
    {
        addr = pBase->FLASH_UNCERR_ADDR.B.ERR_ADD; /* polyspace RTE:NIV */
    }
    else
    {
        /* do nothing for satisfy the misra 2012*/
    }
    
    return addr;
}


/**
****************************************************************************************
* @brief This function is used to detect FLASH error by address.
* @param[in] memuInst :Memu instance.
* @param[in] addr :Target address.
* @return SAF_MEM_ERR_TYPE
*         SAF_MEM_CE_BIT_ERR :Memory error type, correctable error.
*         SAF_MEM_UCE_BIT_ERR :Memory error type, uncorrectable error.
*         SAF_MEM_NONE_BIT_ERR :Memory error type, none.
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static SAF_MEM_ERR_TYPE SAF_MEMU_AccessFlashErrDetectByAddr(const uint8_t memuInst, const uint32_t addr)
{
    SAF_MEM_ERR_TYPE errType = SAF_MEM_NONE_BIT_ERR;
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->FLASH_UNCERR_STS.B.VLD) && pBase->FLASH_UNCERR_ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
    {
        errType = SAF_MEM_UCE_BIT_ERR;
    }
    else
    {
        for (uint8_t chanID = 0; chanID < SAF_MEMU_FLASH_CE_CHAN_COUNT; chanID++)
        {
            if (SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->FLASH_CERR[chanID].STS.B.VLD))/* polyspace RTE:NIV */
            {
                if (pBase->FLASH_CERR[chanID].ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
                {
                    errType = SAF_MEM_CE_BIT_ERR;
                    break;
                }
            }
        }
    }

    return errType;
}


/**
****************************************************************************************
* @brief:  This function is used to clean flash error.
* @param[in]    memuInst    memu instance.
* @param[in]    chanID      memu channel id(reporting table entries).
* @param[in]    errType     ecc error type.
* @return       void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessFlashErrClean(const uint8_t memuInst, const uint8_t chanID, const SAF_MEM_ERR_TYPE errType)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEM_CE_BIT_ERR == errType)
    {
        pBase->FLASH_CERR[chanID].STS.B.VLD = SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.F_CE = SAF_MEMU_FLASH_CORRECTABLE_ERROR_CLEAR;
    }
    else if (SAF_MEM_UCE_BIT_ERR == errType)
    {
        pBase->FLASH_UNCERR_STS.B.VLD = SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.F_UCE = SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_CLEAR;
    }
    else
    {
        /* Do nothing for satisfy the misra 2012. */
    }
}

/**
****************************************************************************************
* @brief This function is used to clean FLASH error by address.
* @param[in] memuInst :Memu instance.
* @param[in] addr :Target address.
* @return void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessFlashErrCleanByAddr(const uint8_t memuInst, const uint32_t addr)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->FLASH_UNCERR_STS.B.VLD) && pBase->FLASH_UNCERR_ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
    {
        pBase->FLASH_UNCERR_STS.B.VLD = SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.F_UCE = SAF_MEMU_FLASH_UNCORRECTABLE_ERROR_CLEAR;
    }
    else
    {
        for (uint8_t chanID = 0; chanID < SAF_MEMU_FLASH_CE_CHAN_COUNT; chanID++)
        {
            if (SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->FLASH_CERR[chanID].STS.B.VLD))/* polyspace RTE:NIV */
            {
                if (pBase->FLASH_CERR[chanID].ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
                {
                    pBase->FLASH_CERR[chanID].STS.B.VLD = SAF_MEMU_FLASH_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
                    pBase->ERR_FLAG.B.F_CE = SAF_MEMU_FLASH_CORRECTABLE_ERROR_CLEAR;
                }
            }
        }
    }
}


/**
****************************************************************************************
* @brief This function is used to detect SRAM error by address.
* @param[in] memuInst :Memu instance.
* @param[in] addr :Target address.
* @return SAF_MEM_ERR_TYPE
*         SAF_MEM_CE_BIT_ERR :Memory error type, correctable error.
*         SAF_MEM_UCE_BIT_ERR :Memory error type, uncorrectable error.
*         SAF_MEM_NONE_BIT_ERR :Memory error type, none.
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static SAF_MEM_ERR_TYPE SAF_MEMU_AccessSramErrDetectByAddr(const uint8_t memuInst, const uint32_t addr)
{
    SAF_MEM_ERR_TYPE errType = SAF_MEM_NONE_BIT_ERR;
    MEMU_Type *pBase = s_pMemuRegList[memuInst];
    
    if (SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->SYS_RAM_UNCERR_STS.B.VLD) && pBase->SYS_RAM_UNCERR_ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
    {
        errType = SAF_MEM_UCE_BIT_ERR;
    }
    else
    {
        for (uint8_t chanID = 0; chanID < SAF_MEMU_SRAM_CE_CHAN_COUNT; chanID++)
        {
            if (SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->SYS_RAM_CERR[chanID].STS.B.VLD))/* polyspace RTE:NIV */
            {
                if (pBase->SYS_RAM_CERR[chanID].ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
                {
                    errType = SAF_MEM_CE_BIT_ERR;
                    break;
                }
            }
        }
    }

    return errType;
}


/**
****************************************************************************************
* @brief:  This function is used to clean SRAM error.
* @param[in]    memuInst    memu instance.
* @param[in]    chanID      memu channel id(reporting table entries).
* @param[in]    errType     ecc error type.
* @return       void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessSramErrClean(const uint8_t memuInst, const uint8_t chanID, const SAF_MEM_ERR_TYPE errType)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEM_CE_BIT_ERR == errType)
    {
        pBase->SYS_RAM_CERR[chanID].STS.B.VLD = SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.SR_CE = SAF_MEMU_SRAM_CORRECTABLE_ERROR_CLEAR;
    }
    else if (SAF_MEM_UCE_BIT_ERR == errType)
    {
        pBase->SYS_RAM_UNCERR_STS.B.VLD = SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.SR_UCE = SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_CLEAR;
    }
    else
    {
        /* Do nothing for satisfy the misra 2012. */
    }
}

/**
****************************************************************************************
* @brief This function is used to clean SRAM error by address.
* @param[in] memuInst :Memu instance.
* @param[in] addr :Target address.
* @return void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessSramErrCleanByAddr(const uint8_t memuInst, const uint32_t addr)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->SYS_RAM_UNCERR_STS.B.VLD) && pBase->SYS_RAM_UNCERR_ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
    {
        pBase->SYS_RAM_UNCERR_STS.B.VLD = SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.SR_UCE = SAF_MEMU_SRAM_UNCORRECTABLE_ERROR_CLEAR;
    }
    else
    {
        for (uint8_t chanID = 0; chanID < SAF_MEMU_SRAM_CE_CHAN_COUNT; chanID++)
        {
            if (SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->SYS_RAM_CERR[chanID].STS.B.VLD))/* polyspace RTE:NIV */
            {
                if (pBase->SYS_RAM_CERR[chanID].ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
                {
                    pBase->SYS_RAM_CERR[chanID].STS.B.VLD = SAF_MEMU_SRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
                    pBase->ERR_FLAG.B.SR_CE = SAF_MEMU_SRAM_CORRECTABLE_ERROR_CLEAR;
                }
            }
        }
    }
}

/**
****************************************************************************************
* @brief:  This function is used to detect PRAM error and compare expect address.
* @param[in]    memuInst    memu instance.
* @param[in]    chanID      memu channel id(reporting table entries).
* @param[in]    errType     ecc error type.
* @param[in]    addr        compared expect address.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     detect and compare success
*               FS_STATUS_ERROR       detect and compare failed
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static SAF_MEM_ERR_TYPE SAF_MEMU_AccessPramErrDetectByAddr(const uint8_t memuInst, const uint32_t addr)
{
    SAF_MEM_ERR_TYPE errType = SAF_MEM_NONE_BIT_ERR;
    MEMU_Type *pBase = s_pMemuRegList[memuInst];
    
    if (SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->PERIPH_RAM_UNCERR_STS.B.VLD) && pBase->PERIPH_RAM_UNCERR_ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
    {
        errType = SAF_MEM_UCE_BIT_ERR;
    }
    else
    {
        for (uint8_t chanID = 0; chanID < SAF_MEMU_PRAM_CE_CHAN_COUNT; chanID++)
        {
            if (SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->PERIPH_RAM_CERR[chanID].STS.B.VLD))/* polyspace RTE:NIV */
            {
                if (pBase->PERIPH_RAM_CERR[chanID].ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
                {
                    errType = SAF_MEM_CE_BIT_ERR;
                    break;
                }
            }
        }
    }

    return errType;
}


/**
****************************************************************************************
* @brief:  This function is used to clean PRAM error.
* @param[in]    memuInst    memu instance.
* @param[in]    chanID      memu channel id(reporting table entries).
* @param[in]    errType     ecc error type.
* @return       void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessPramErrClean(const uint8_t memuInst, const uint8_t chanID, const SAF_MEM_ERR_TYPE errType)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEM_CE_BIT_ERR == errType)
    {
        pBase->PERIPH_RAM_CERR[chanID].STS.B.VLD = SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.PR_CE = SAF_MEMU_PRAM_CORRECTABLE_ERROR_CLEAR;
    }
    else if (SAF_MEM_UCE_BIT_ERR == errType)
    {
        pBase->PERIPH_RAM_UNCERR_STS.B.VLD = SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.PR_UCE = SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_CLEAR;
    }
    else
    {
        /* Do nothing for satisfy the misra 2012. */
    }
}

/**
****************************************************************************************
* @brief This function is used to clean PRAM error by address.
* @param[in] memuInst :Memu instance.
* @param[in] addr :Target address.
* @return void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessPramErrCleanByAddr(const uint8_t memuInst, const uint32_t addr)
{
    MEMU_Type *pBase = s_pMemuRegList[memuInst];

    if (SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->PERIPH_RAM_UNCERR_STS.B.VLD) && pBase->PERIPH_RAM_UNCERR_ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
    {
        pBase->PERIPH_RAM_UNCERR_STS.B.VLD = SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
        pBase->ERR_FLAG.B.PR_UCE = SAF_MEMU_PRAM_UNCORRECTABLE_ERROR_CLEAR;
    }
    else
    {
        for (uint8_t chanID = 0; chanID < SAF_MEMU_PRAM_CE_CHAN_COUNT; chanID++)
        {
            if (SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID != (pBase->PERIPH_RAM_CERR[chanID].STS.B.VLD))/* polyspace RTE:NIV */
            {
                if (pBase->PERIPH_RAM_CERR[chanID].ADDR.B.ERR_ADD == addr)/* polyspace RTE:NIV */
                {
                    pBase->PERIPH_RAM_CERR[chanID].STS.B.VLD = SAF_MEMU_PRAM_CORRECTABLE_ERROR_REPORTING_TABLE_ENTRY_INVALID;
                    pBase->ERR_FLAG.B.PR_CE = SAF_MEMU_PRAM_CORRECTABLE_ERROR_CLEAR;
                }
            }
        }
    }
}

/**
****************************************************************************************
* @brief This function is used to detect all FLASH ECC error.
* @param[in] memuInst :Memu instance.
* @param[in] pMemInfo :Error message buffer.
* @return void.
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessDetectFlashAllErr(const uint8_t memuInst, saf_mem_err_detect_info_t *pMemInfo)
{
    if (true == SAF_MEMU_AccessUCEErrAddrIsValid(memuInst, SAF_MEM_FLASH))
    {
        if (pMemInfo->errCount < SAF_MEM_ERROR_INFO_NUM)
        {
            pMemInfo->errMemType[pMemInfo->errCount] = SAF_MEM_FLASH;
            pMemInfo->errType[pMemInfo->errCount] = SAF_MEM_UCE_BIT_ERR;
            pMemInfo->errAddr[pMemInfo->errCount] = SAF_MEMU_AccessGetMemUCEErrAddr(memuInst, SAF_MEM_FLASH);
            pMemInfo->errCount++;
        }
    }

    for (uint8_t chanID = 0; chanID < SAF_MEMU_FLASH_CE_CHAN_COUNT; chanID++)
    {
        if (true == SAF_MEMU_AccessCEErrAddrIsValid(memuInst, SAF_MEM_FLASH, chanID))
        {
            if (pMemInfo->errCount < SAF_MEM_ERROR_INFO_NUM)
            {
                pMemInfo->errMemType[pMemInfo->errCount] = SAF_MEM_FLASH;
                pMemInfo->errType[pMemInfo->errCount] = SAF_MEM_CE_BIT_ERR;
                pMemInfo->errAddr[pMemInfo->errCount] = SAF_MEMU_AccessGetMemCEErrAddr(memuInst, SAF_MEM_FLASH, chanID);
                pMemInfo->errCount++;
            }
        }
    }
}

/**
****************************************************************************************
* @brief This function is used to detect all SRAM ECC error.
* @param[in] memuInst :Memu instance.
* @param[in] pMemInfo :Error message buffer.
* @return void.
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessDetectSramAllErr(const uint8_t memuInst, saf_mem_err_detect_info_t *pMemInfo)
{
    if (true == SAF_MEMU_AccessUCEErrAddrIsValid(memuInst, SAF_MEM_SRAM))
    {
        if (pMemInfo->errCount < SAF_MEM_ERROR_INFO_NUM)
        {
            pMemInfo->errMemType[pMemInfo->errCount] = SAF_MEM_SRAM;
            pMemInfo->errType[pMemInfo->errCount] = SAF_MEM_UCE_BIT_ERR;
            pMemInfo->errAddr[pMemInfo->errCount] = SAF_MEMU_AccessGetMemUCEErrAddr(memuInst, SAF_MEM_SRAM);
            pMemInfo->errCount++;
        }
    }

    for (uint8_t chanID = 0; chanID < SAF_MEMU_SRAM_CE_CHAN_COUNT; chanID++)
    {
        if (true == SAF_MEMU_AccessCEErrAddrIsValid(memuInst, SAF_MEM_SRAM, chanID))
        {
            if (pMemInfo->errCount < SAF_MEM_ERROR_INFO_NUM)
            {
                pMemInfo->errMemType[pMemInfo->errCount] = SAF_MEM_SRAM;
                pMemInfo->errType[pMemInfo->errCount] = SAF_MEM_CE_BIT_ERR;
                pMemInfo->errAddr[pMemInfo->errCount] = SAF_MEMU_AccessGetMemCEErrAddr(memuInst, SAF_MEM_SRAM, chanID);
                pMemInfo->errCount++;
            }
        }
    }
}

/**
****************************************************************************************
* @brief This function is used to detect all PRAM ECC error.
* @param[in] memuInst :Memu instance.
* @param[in] pMemInfo :Error message buffer.
* @return void.
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
static void SAF_MEMU_AccessDetectPramAllErr(const uint8_t memuInst, saf_mem_err_detect_info_t *pMemInfo)
{
    if (true == SAF_MEMU_AccessUCEErrAddrIsValid(memuInst, SAF_MEM_PRAM))
    {
        if (pMemInfo->errCount < SAF_MEM_ERROR_INFO_NUM)
        {
            pMemInfo->errMemType[pMemInfo->errCount] = SAF_MEM_PRAM;
            pMemInfo->errType[pMemInfo->errCount] = SAF_MEM_UCE_BIT_ERR;
            pMemInfo->errAddr[pMemInfo->errCount] = SAF_MEMU_AccessGetMemUCEErrAddr(memuInst, SAF_MEM_PRAM);
            pMemInfo->errCount++;
        }
    }

    for (uint8_t chanID = 0; chanID < SAF_MEMU_PRAM_CE_CHAN_COUNT; chanID++)
    {
        if (true == SAF_MEMU_AccessCEErrAddrIsValid(memuInst, SAF_MEM_PRAM, chanID))
        {
            if (pMemInfo->errCount < SAF_MEM_ERROR_INFO_NUM)
            {
                pMemInfo->errMemType[pMemInfo->errCount] = SAF_MEM_PRAM;
                pMemInfo->errType[pMemInfo->errCount] = SAF_MEM_CE_BIT_ERR;
                pMemInfo->errAddr[pMemInfo->errCount] = SAF_MEMU_AccessGetMemCEErrAddr(memuInst, SAF_MEM_PRAM, chanID);
                pMemInfo->errCount++;
            }
        }
    }
}

/**
****************************************************************************************
 * @brief: Global Function
****************************************************************************************
*/

/**
****************************************************************************************
* @brief:  This function is used to initialize memory error report.
* @return  void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
void SAF_MEMU_ErrorReportInit(void)
{
    uint8_t instance, chanID;
    
    for (instance = 0; instance < SAF_MEMU_INSTANCE_COUNT; instance++)/*PRQA S 2877*/
    {
        /* clean SRAM */
        for (chanID = 0; chanID < SAF_MEMU_SRAM_CE_CHAN_COUNT; chanID++)
        {
            SAF_MEMU_AccessSramErrClean(instance, chanID, SAF_MEM_CE_BIT_ERR);
        }
        SAF_MEMU_AccessSramErrClean(instance, 0, SAF_MEM_UCE_BIT_ERR);
        
        /* clean PRAM */
        for (chanID = 0; chanID < SAF_MEMU_PRAM_CE_CHAN_COUNT; chanID++)
        {
            SAF_MEMU_AccessPramErrClean(instance, chanID, SAF_MEM_CE_BIT_ERR);
        }
        SAF_MEMU_AccessPramErrClean(instance, 0, SAF_MEM_UCE_BIT_ERR);
        
        /* clean FLASH */
        for (chanID = 0; chanID < SAF_MEMU_FLASH_CE_CHAN_COUNT; chanID++)
        {
            SAF_MEMU_AccessFlashErrClean(instance, chanID, SAF_MEM_CE_BIT_ERR);
        }
        SAF_MEMU_AccessFlashErrClean(instance, chanID, SAF_MEM_UCE_BIT_ERR);
    }
}


/**
****************************************************************************************
* @brief:  This function is used to get and clean memory error report.
* @param[in]    memType         error reporting memory area..
* @param[in]    addr            compared expect address.
* @param[in]    pMemErrType     ecc error type.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     get and clean success
*               FS_STATUS_ERROR       get and clean failed
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
FS_STATUS SAF_MEMU_GetMemErrAndClean(const SAF_MEM_TYPE memType, const uint32_t addr, SAF_MEM_ERR_TYPE *pMemErrType)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t instance = 0;

    if (NULL != pMemErrType)
    {
        *pMemErrType = SAF_MEM_NONE_BIT_ERR;

        for (instance = 0; instance < SAF_MEMU_INSTANCE_COUNT; instance++)/*PRQA S 2877*/
        {
            if (SAF_MEM_FLASH == memType)
            {
                *pMemErrType = SAF_MEMU_AccessFlashErrDetectByAddr(instance, addr);
                SAF_MEMU_AccessFlashErrCleanByAddr(instance, addr);
            }
            else if (SAF_MEM_SRAM == memType)
            {
                *pMemErrType = SAF_MEMU_AccessSramErrDetectByAddr(instance, addr);
                SAF_MEMU_AccessSramErrCleanByAddr(instance, addr);
            }
            else if (SAF_MEM_PRAM == memType)
            {
                *pMemErrType = SAF_MEMU_AccessPramErrDetectByAddr(instance, addr);
                SAF_MEMU_AccessPramErrCleanByAddr(instance, addr);
            }
            else
            {
                status = FS_STATUS_ERROR;
                break;
            }
        }
    }
    else
    {
        status = FS_STATUS_ERROR;
    }

    return status;
}


/**
****************************************************************************************
* @brief:  This function is used to detect all memory error.
* @param[in]    memType         error reporting memory area..
* @param[in]    pMemInfo        error message buffer.
* @return       FS_STATUS
*               FS_STATUS_SUCCESS     detect success
*               FS_STATUS_ERROR       detect failed
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
FS_STATUS SAF_MEMU_DetectAllErr(const SAF_MEM_TYPE memType, saf_mem_err_detect_info_t *pMemInfo)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    uint8_t instance = 0;

    if (NULL != pMemInfo)
    {
        memset(pMemInfo, 0, sizeof(saf_mem_err_detect_info_t));/*PRQA S 0315,3200*/
        for (instance = 0; instance < SAF_MEMU_INSTANCE_COUNT; instance++)/*PRQA S 2877*/
        {
            if (SAF_MEM_FLASH == memType)
            {
                SAF_MEMU_AccessDetectFlashAllErr(instance, pMemInfo);
            }
            else if (SAF_MEM_SRAM == memType)
            {
                SAF_MEMU_AccessDetectSramAllErr(instance, pMemInfo);
            }
            else if (SAF_MEM_PRAM == memType)
            {
                SAF_MEMU_AccessDetectPramAllErr(instance, pMemInfo);
            }
            else
            {
                status = FS_STATUS_ERROR;
                break;
            }
        }
    }
    
    return status;
}


/**
****************************************************************************************
* @brief:  This function is used to clean all memory error.
* @param[in]    memType         error reporting memory area..
* @return       void
****************************************************************************************
*/
SAF_MEMU_SEC_CODE
void SAF_MEMU_CleanAllErr(const SAF_MEM_TYPE memType)
{
    uint8_t chanID, instance;

    for (instance = 0; instance < SAF_MEMU_INSTANCE_COUNT; instance++)/*PRQA S 2877*/
    {
        if (memType == SAF_MEM_SRAM)
        {
            for (chanID = 0; chanID < SAF_MEMU_SRAM_CE_CHAN_COUNT; chanID++)
            {
                SAF_MEMU_AccessSramErrClean(instance, chanID, SAF_MEM_CE_BIT_ERR);
            }
            SAF_MEMU_AccessSramErrClean(instance, 0, SAF_MEM_UCE_BIT_ERR);
        }
        else if (memType == SAF_MEM_PRAM)
        {
            for (chanID = 0; chanID < SAF_MEMU_PRAM_CE_CHAN_COUNT; chanID++)
            {
                SAF_MEMU_AccessPramErrClean(instance, chanID, SAF_MEM_CE_BIT_ERR);
            }
            SAF_MEMU_AccessPramErrClean(instance, 0, SAF_MEM_UCE_BIT_ERR);
        }
        else if (memType == SAF_MEM_FLASH)
        {
            for (chanID = 0; chanID < SAF_MEMU_FLASH_CE_CHAN_COUNT; chanID++)
            {
                SAF_MEMU_AccessFlashErrClean(instance, chanID, SAF_MEM_CE_BIT_ERR);
            }
            SAF_MEMU_AccessFlashErrClean(instance, 0, SAF_MEM_UCE_BIT_ERR);
        }
        else
        {
            /* do nothing for satisfy the misra 2012*/
        }
    }
}

#ifdef __cplusplus
}
#endif

