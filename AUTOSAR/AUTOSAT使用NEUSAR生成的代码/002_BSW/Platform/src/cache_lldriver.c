/**
****************************************************************************************
 * @FilePath: saf_cache.c
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Cache C File
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif

/*PRQA S 1006,3006,0380 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "cache_lldriver.h"
#include "Mcal.h"
/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
#ifdef DCACHE_ENABLE
/**
****************************************************************************************
* @brief:  This function shall be used to detects if the DCACHE is enabled.
* @return      boolean
*              true       DCACHE is enabled
*              false      DCACHE is disabled
****************************************************************************************
*/
static boolean CACHE_LLD_AccessDcacheIsEnabled(void)
{
    CORE_L1CSR0_tag l1csr0Register;

    l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
    
    return (l1csr0Register.B.DCE == CACHE_LLD_DCACHE_ENABLE) ? TRUE : FALSE;
}

/**
****************************************************************************************
* @brief:  This function is used to invalidate DCACHE and it needs to be cache-inhibited.
* @return       void
****************************************************************************************
*/
static void CACHE_LLD_AccessInvalidateDcache(void)
{
    static CORE_L1CSR0_tag s_l1csr0Register = {0UL};

    s_l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
    s_l1csr0Register.B.DCINV = 1U;
    MTSPR(CORE_L1CSR0_SPR_ID, s_l1csr0Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to wait completing invalidate DCACHE and it needs
*          to be cache-inhibited.
* @return       void
****************************************************************************************
*/
static void CACHE_LLD_AccessWaitInvalidateDcacheDone(void)
{
    static CORE_L1CSR0_tag s_l1csr0Register = {0UL};
    static uint32_t s_timeout = CACHE_LLD_INVALIDATE_COUNT;

    /* Cache invalidation operations require approximately 66 cycles to complete. */
    do
    {
        s_l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
        if (s_l1csr0Register.B.DCINV == 0U)
        {
            break;
        }
    } while ((--s_timeout) > 0U);
    s_timeout = CACHE_LLD_INVALIDATE_COUNT;
}

/**
****************************************************************************************
* @brief:  This function is used to invalidate DCACHE and wait it completing.
* @return      void
****************************************************************************************
*/
void CACHE_LLD_InvalidateDcache(void)
{
	static CORE_L1CSR0_tag s_l1csr0Register = {0UL};
	CACHE_LLD_AccessInvalidateDcache();
	CACHE_LLD_AccessWaitInvalidateDcacheDone();
    s_l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
    (void)s_l1csr0Register;
}

/**
****************************************************************************************
* @brief:  This function is used to enable DCACHE.
* @return       void
****************************************************************************************
*/
void CACHE_LLD_AccessEnableDcache(void)
{
    CORE_L1CSR0_tag l1csr0Register;
    l1csr0Register.R = 0UL;

    l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
    /* Enable cache */
    l1csr0Register.B.DCE = 1U;
    l1csr0Register.B.DCECE = 1U;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(CORE_L1CSR0_SPR_ID, l1csr0Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to disable DCACHE.
* @return       void
****************************************************************************************
*/
void CACHE_LLD_AccessDisableDcache(void)
{
    CORE_L1CSR0_tag l1csr0Register;
    l1csr0Register.R = 0UL;

    l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
    /* Disable cache */
    l1csr0Register.B.DCE = 0U;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(CORE_L1CSR0_SPR_ID, l1csr0Register.R);
    PPCASM("se_isync");
}
#endif

#ifdef ICACHE_ENABLE
/**
****************************************************************************************
* @brief:  This function detects if ICACHE is enabled.
* @return      boolean
*              true       ICACHE is enabled
*              false      ICACHE is disabled
****************************************************************************************
*/
static boolean CACHE_LLD_AccessIcacheIsEnabled(void)
{
    CORE_L1CSR1_tag l1csr1Register;

    l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
    
    return (l1csr1Register.B.ICE == CACHE_LLD_ICACHE_ENABLE) ? TRUE : FALSE;
}

/**
****************************************************************************************
* @brief:  This function is used to invalidate ICACHE and it needs to be cache-inhibited.
* @return      void
****************************************************************************************
*/
static void CACHE_LLD_AccessInvalidateIcache(void)
{
    static CORE_L1CSR1_tag s_l1csr1Register = {0UL};

    s_l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
    s_l1csr1Register.B.ICINV = 1U;
    MTSPR(CORE_L1CSR1_SPR_ID, s_l1csr1Register.R);
    PPCASM("se_isync");
}

/**
****************************************************************************************
* @brief:  This function is used to wait completing invalidate ICACHE
*          and it needs to be cache-inhibited.
* @return      void
****************************************************************************************
*/
static void CACHE_LLD_AccessWaitInvalidateIcacheDone(void)
{
    static CORE_L1CSR1_tag s_l1csr1Register = {0UL};
    static uint32_t s_timeout = CACHE_LLD_INVALIDATE_COUNT;

    /* Cache invalidation operations require approximately 134 cycles to
       complete. */
    do
    {
        s_l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
        if (s_l1csr1Register.B.ICINV == 0x00u)
        {
            break;
        }
    } while ((--s_timeout) > 0U);
}

/**
****************************************************************************************
* @brief:  This function is used to invalidate ICACHE and wait it completing.
* @return      void
****************************************************************************************
*/
void CACHE_LLD_InvalidateIcache(void)
{
    static CORE_L1CSR1_tag s_l1csr1Register = {0UL};
    CACHE_LLD_AccessInvalidateIcache();
    CACHE_LLD_AccessWaitInvalidateIcacheDone();
    s_l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
    (void)s_l1csr1Register;
}


/**
****************************************************************************************
* @brief:  This function is used to enable ICACHE.
* @return      void
****************************************************************************************
*/
void CACHE_LLD_AccessEnableIcache(void)
{
    CORE_L1CSR1_tag l1csr1Register;
    l1csr1Register.R = 0UL;

    l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
    /* Enable cache */
    if (l1csr1Register.B.ICE == 0x0U)
    {
        l1csr1Register.B.ICE = 1U;
        l1csr1Register.B.ICECE = 1U;
        PPCASM("se_isync");
        PPCASM("msync");
        MTSPR(CORE_L1CSR1_SPR_ID, l1csr1Register.R);
        PPCASM("se_isync");
    }   
}

/**
****************************************************************************************
* @brief:  This function is used to disable ICACHE.
* @return      void
****************************************************************************************
*/
void CACHE_LLD_AccessDisableIcache(void)
{
    CORE_L1CSR1_tag l1csr1Register;
    l1csr1Register.R = 0UL;
    
    l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
    /* Disable cache */
    l1csr1Register.B.ICE = 0U;
    PPCASM("se_isync");
    PPCASM("msync");
    MTSPR(CORE_L1CSR1_SPR_ID, l1csr1Register.R);
    PPCASM("se_isync");
}

#endif

/*******************************************************************************
 * Global Functions
 ******************************************************************************/


/**
****************************************************************************************
* @brief:  This function is used to enable CACHE.
* @return       status_t
*               STATUS_SUCCESS     enable CACHE succeed
*               STATUS_ERROR       enable CACHE failed
****************************************************************************************
*/
status_t CACHE_LLD_Enable(const CACHE_LLD_TYPE cacheType)
{
    status_t status = STATUS_SUCCESS;

    if (CACHE_LLD_TYPE_DCACHE == cacheType)
    {
#ifdef DCACHE_ENABLE
        if (CACHE_LLD_AccessDcacheIsEnabled() == FALSE)
        {
            /* Invalidate cache before cache is enabled. */
            CACHE_LLD_AccessInvalidateDcache();
            CACHE_LLD_AccessWaitInvalidateDcacheDone();
            CACHE_LLD_AccessEnableDcache();
        }
#endif
    }
    else if (CACHE_LLD_TYPE_ICACHE == cacheType)
    {
#ifdef ICACHE_ENABLE
        if (CACHE_LLD_AccessIcacheIsEnabled() == FALSE)
        {
            /* Invalidate cache before cache is enabled. */
            CACHE_LLD_AccessInvalidateIcache();
            CACHE_LLD_AccessWaitInvalidateIcacheDone();
            CACHE_LLD_AccessEnableIcache();
        }
#endif
    }
    else
    {
        status = STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to disable CACHE.
* @return       status_t
*               STATUS_SUCCESS     disable CACHE succeed
*               STATUS_ERROR       disable CACHE failed
****************************************************************************************
*/
status_t CACHE_LLD_Disable(const CACHE_LLD_TYPE cacheType)
{
    status_t status = STATUS_SUCCESS;

    if (CACHE_LLD_TYPE_DCACHE == cacheType)
    {
#ifdef DCACHE_ENABLE
        CACHE_LLD_AccessDisableDcache();
#endif
    }
    else if (CACHE_LLD_TYPE_ICACHE == cacheType)
    {
#ifdef ICACHE_ENABLE
        CACHE_LLD_AccessDisableIcache();
#endif
    }
    else
    {
        status = STATUS_ERROR;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to store CACHE status.
* @param[out]   pCacheEnableFlag   CACHE status.
* @return       status_t
*               STATUS_SUCCESS     store CACHE status succeed
*               STATUS_ERROR       store CACHE status failed
****************************************************************************************
*/
status_t CACHE_LLD_Store(const CACHE_LLD_TYPE cacheType, uint32_t *pCacheEnableFlag)
{
    status_t status = STATUS_ERROR;

    if(pCacheEnableFlag != NULL)
    {
        if (CACHE_LLD_TYPE_DCACHE == cacheType)
        {
            *pCacheEnableFlag = CACHE_LLD_DCACHE_ENABLE & MFSPR(CORE_L1CSR0_SPR_ID);
        }
        else if (CACHE_LLD_TYPE_ICACHE == cacheType)
        {
            *pCacheEnableFlag = CACHE_LLD_ICACHE_ENABLE & MFSPR(CORE_L1CSR1_SPR_ID);
        }
        else
        {
            /* do nothing */
        }
        
        status = STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief:  This function is used to restore CACHE status.
* @param[in]    cacheEnableFlag   CACHE status.
* @return       status_t
*               STATUS_SUCCESS     restore CACHE status succeed
*               STATUS_ERROR       restore CACHE status failed
****************************************************************************************
*/
status_t CACHE_LLD_Restore(const CACHE_LLD_TYPE cacheType, const uint32_t cacheEnableFlag)
{
    status_t status = STATUS_SUCCESS;
#ifdef DCACHE_ENABLE
    CORE_L1CSR0_tag l1csr0Register;
#endif
#ifdef ICACHE_ENABLE
    CORE_L1CSR1_tag l1csr1Register;
#endif   
    
    if (CACHE_LLD_TYPE_DCACHE == cacheType)
    {
#ifdef DCACHE_ENABLE
        if ((cacheEnableFlag & CACHE_LLD_DCACHE_ENABLE) != 0U)
        {
        	(void)CACHE_LLD_Enable(CACHE_LLD_TYPE_DCACHE);
        }
        else
        {
        	(void)CACHE_LLD_Disable(CACHE_LLD_TYPE_DCACHE);
        }
        
        /* Read back */
        l1csr0Register.R = MFSPR(CORE_L1CSR0_SPR_ID);
        if ((l1csr0Register.R & CACHE_LLD_DCACHE_ENABLE) != (cacheEnableFlag & CACHE_LLD_DCACHE_ENABLE))
        {
            status = STATUS_ERROR;
        }
#endif
    }
    else if (CACHE_LLD_TYPE_ICACHE == cacheType)
    {
#ifdef ICACHE_ENABLE
        if ((cacheEnableFlag & CACHE_LLD_ICACHE_ENABLE) != 0U)
        {
            (void)CACHE_LLD_Enable(CACHE_LLD_TYPE_ICACHE);
        }
        else
        {
        	(void)CACHE_LLD_Disable(CACHE_LLD_TYPE_ICACHE);
        }

        /* Read back */
        l1csr1Register.R = MFSPR(CORE_L1CSR1_SPR_ID);
        if ((l1csr1Register.R & CACHE_LLD_ICACHE_ENABLE) != (cacheEnableFlag & CACHE_LLD_ICACHE_ENABLE))
        {
            status = STATUS_ERROR;
        }
#endif
    }
    else
    {
        status = STATUS_ERROR;
    }

    return status;
}




#ifdef __cplusplus
}
#endif


