/**
****************************************************************************************
 * @FilePath: saf_cache.h
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Cache head File
****************************************************************************************
*/
#ifndef CACHE_LLD_H
#define CACHE_LLD_H

#ifdef __cplusplus
extern "C"{
#endif

/*PRQA S 1536 EOF*/
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "derivative.h"
#include "status.h"

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
#define CORE_L1CSR0_SPR_ID                               (1010)
#define CORE_L1CSR1_SPR_ID                               (1011)
#define CORE_L1FINV0_SPR_ID                              (1016)
#define CORE_L1FINV1_SPR_ID                              (959)
#define CORE_DCACHE_WAY_COUNT                            (2U)
#define CORE_DCACHE_SET_COUNT                            (64U)
#define CORE_ICACHE_WAY_COUNT                            (2U)
#define CORE_ICACHE_SET_COUNT                            (64U)

#define CACHE_LLD_INVALIDATE_COUNT                           (1000UL)
#define CACHE_LLD_ICACHE_ENABLE                              (0x1U)
#define CACHE_LLD_DCACHE_ENABLE                              (0x1U)


/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/**
* @brief  CACHE type.
*/
typedef enum
{
    CACHE_LLD_TYPE_DCACHE = 0U,
    CACHE_LLD_TYPE_ICACHE = 1U,
    CACHE_LLD_TYPE_COUNT = 2U
} CACHE_LLD_TYPE;

typedef union CORE_L1CSR0_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t WID:2;
        vuint32_t :2;
        vuint32_t WDD:2;
        vuint32_t :6;
        vuint32_t DCWA:1;
        vuint32_t :2;
        vuint32_t DCECE:1;
        vuint32_t DCEI:1;
        vuint32_t DCLOC:2;
        vuint32_t :6;
        vuint32_t DCEA:2;
        vuint32_t DCLOINV:1;
        vuint32_t :1;
        vuint32_t DCABT:1;
        vuint32_t DCINV:1;
        vuint32_t DCE:1;
    }B;
} CORE_L1CSR0_tag;

typedef union CORE_L1CSR1_union_tag
{
    vuint32_t R;
    struct
    {
        vuint32_t :15;
        vuint32_t ICECE:1;
        vuint32_t ICEI:1;
        vuint32_t ICLOC:2;
        vuint32_t :6;
        vuint32_t ICEA:2;
        vuint32_t ICLOINV:1;
        vuint32_t :1;
        vuint32_t ICABT:1;
        vuint32_t ICINV:1;
        vuint32_t ICE:1;
    }B;
} CORE_L1CSR1_tag;


/**
****************************************************************************************
 * @brief: Function Prototypes
****************************************************************************************
*/

status_t CACHE_LLD_Disable(const CACHE_LLD_TYPE cacheType);

status_t CACHE_LLD_Enable(const CACHE_LLD_TYPE cacheType);

status_t CACHE_LLD_Store(const CACHE_LLD_TYPE cacheType, uint32_t *pCacheEnableFlag);

status_t CACHE_LLD_Restore(const CACHE_LLD_TYPE cacheType, const uint32_t cacheEnableFlag);


void CACHE_LLD_InvalidateDcache(void);
void CACHE_LLD_InvalidateIcache(void);
void CACHE_LLD_AccessEnableDcache(void);
void CACHE_LLD_AccessEnableIcache(void);
void CACHE_LLD_AccessDisableDcache(void);
void CACHE_LLD_AccessDisableIcache(void);


#ifdef __cplusplus
}
#endif

#endif
