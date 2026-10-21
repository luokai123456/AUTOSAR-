/**
****************************************************************************************
 * @FilePath: saf_bist.h
 * @Author: CCORE
 * @Date: 2024-03-20
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: BIST Head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_BIST_H
#define SAF_BIST_H


#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_cpu.h"
#include "SafetyCoreTst_Cfg.h"
/**
****************************************************************************************
 * @brief: Macros
****************************************************************************************
*/
#define SAF_BIST_CREATE_DCF_RECORD(user_falshAddr, user_data, user_cs, user_addr, user_parity) \
{ \
    .flashAddr = user_falshAddr, \
    .dcfObj.data = user_data, \
    .dcfObj.addr.B.cs = user_cs, \
    .dcfObj.addr.B.addr = user_addr, \
    .dcfObj.addr.B.parity = user_parity \
}

#define SAF_STCU2_BIST_CR                       ((volatile uint32_t*)0xFFF44000UL)
#define SAF_STCU2_BIST_SKC                      ((volatile uint32_t*)0xFFF44004UL)
#define SAF_STCU2_BIST_PDR                      ((volatile uint32_t*)0xFFF44008UL)
#define SAF_STCU2_BIST_PLL_CFG                  ((volatile uint32_t*)0xFFF4400CUL)
#define SAF_STCU2_BIST_WDG                      ((volatile uint32_t*)0xFFF44010UL)
#define SAF_STCU2_BIST_LBRM                     ((volatile uint32_t*)0xFFF44018UL)
#define SAF_STCU2_BIST_LBDRC                    ((volatile uint32_t*)0xFFF4401CUL)
#define SAF_BIST_CR_MASK                        ((uint32_t)0x01030103)
#define SAF_BIST_PDR_MASK                       ((uint32_t)0x007F007F)
#define SAF_BIST_PLL_MASK                       ((uint32_t)0x00000007)
#define SAF_BIST_WDG_MASK                       ((uint32_t)0xFFFFFFFF)
#define SAF_BIST_LBRM_MASK                      ((uint32_t)0x000003FF)
#define SAF_BIST_LBDRC_MASK                     ((uint32_t)0x000003FF)

#define SAF_STCU2_BIST_STS (*(volatile STCU2_Bist_STS_tag*)0xFFF44014UL)

#define SAF_DCF_RECORD_END_OF_DCF_LIST_VALID    1U
#define SAF_DCF_RECORD_END_OF_DCF_LIST_INVALID  0U
#define SAF_DCF_RECORD_DATA_FIELD_SHIFT         32U
#define SAF_DCF_RECORD_BYTE_SIZE                8U
#define SAF_DCF_RECORD_INDEX_SHIFT              3U
#define SAF_DCF_RECORD_ADDRESS_ALIGNMENT        0x7U
#define SAF_DCF_RECORD_ADDRESS_ALIGNMENT_VALUE  0x0U
#define SAF_DCF_RECORD_ERASED_VALUE             0xFFFFFFFFFFFFFFFFULL
#define SAF_DCF_WORD_MASK                       0xFFFFFFFFU
#define SAF_DCF_HALF_WORD_MASK                  0xFFFFU
#define SAF_DCF_NUM                             22U
#define SAF_DCF_VALID_INDEX                     9U

#define SAF_OFFLINE_LBIST_NOT_NEED_CHECK        0U
#define SAF_OFFLINE_LBIST_NEED_CHECK            1U
#define SAF_OFFLINE_LBIST_CHECK_INDEX_LIMIT     12U

#define SAF_OFFLINE_MBIST_NOT_NEED_CHECK        0U
#define SAF_OFFLINE_MBIST_NEED_CHECK            1U
#define SAF_OFFLINE_MBIST_CHECK_INDEX_LIMIT     4U
#define SAF_OFFLINE_MBIST_CFG_SHIFT             16U

#define SAF_ONLINE_LBIST_MAX_COUNT              (0x03U)
#define SAF_ONLINE_MBIST_MAX_COUNT              (0x06U)

#define SAF_BIST_RET_SUCCESS                    0U
#define SAF_BIST_RET_ERROR                      1U

#define SAF_BIST_CHECK_PASS_RESULT              0U
#define SAF_BIST_CHECK_FAIL_RESULT              1U
/**
****************************************************************************************
 * @brief: Structures
****************************************************************************************
*/
/*!
 * @brief DCF information structure.
 */
typedef union
{
    uint32_t R;
    struct
    {
        uint32_t cs :15;
        uint32_t addr :15;
        uint32_t parity :1;
        uint32_t stop :1;
    } B;
} saf_dcf_record_addr_t;

/*!
 * @brief STCU2 Configuration Register.
 */
typedef struct STCU2_STS_Bit/*PRQA S 1536*/
{
    vuint32_t  :13;
    vuint32_t  STCU_RF:1;      
    vuint32_t  STCU_UF:1;         
    vuint32_t  STCU_LMBIST_USR_ERR:1;
    vuint32_t  :5;
    vuint32_t  MBSW_F :1; 
    vuint32_t  MBSW_D:1;                 
    vuint32_t  LBSW_F:1;                  
    vuint32_t  LBSW_D:1;
    vuint32_t  PLL_LOCK_F:1;
    vuint32_t  MB_F:1;
    vuint32_t  MB_WDTO:1;
    vuint32_t  MB_D:1;
    vuint32_t  LB_F:1;
    vuint32_t  LB_WDTO:1;
    vuint32_t  LB_D:1;
} STCU2_STS_Bit;

/*!
 * @brief DCF data and information structure.
 */
typedef struct
{
    /* dcf data */
    uint32_t data;
    /* dcf information structure */
    saf_dcf_record_addr_t addr;
} saf_dcf_record_t;

/*!
 * @brief BIST DCF object structure.
 */
typedef struct
{
    /* flash address */
    uint32_t flashAddr;
    /* dcf data structure */
    saf_dcf_record_t dcfObj;
} saf_bist_dcf_object_t;/*PRQA S 1535*/


/*!
 * @brief off-line BIST configuration structure.
 */
typedef struct
{
    uint32_t startAddr;
    uint32_t endAddr;
    uint32_t dcfCount;
    uint32_t lbistCfg;
    uint32_t mbistCfg;
} saf_bist_offline_config_t;

/*!
 * @brief on-line BIST configuration structure.
 */
typedef struct
{
    uint8_t lbistCount;
    uint8_t mbistCount;
    uint8_t lbistPartition[SAF_ONLINE_LBIST_MAX_COUNT];
    uint8_t mbistPartition[SAF_ONLINE_MBIST_MAX_COUNT];
} saf_bist_online_config_t;

/*!
 * @brief BIST check result structure.
 */
typedef struct
{
    /* status of the selected LBIST */
    uint32_t offLineLbistCheckResult;
    /* End status of the selected LBIST */
    uint32_t offLineLbistCheckEnd;
    /* status of the selected MBIST */
    uint32_t offLineMbistCheckResult;
    /* End status of the selected MBIST */
    uint32_t offLineMbistCheckEnd;
    /* status of the online LBIST */
    uint32_t onLineLbistCheckResult[SAF_ONLINE_LBIST_MAX_COUNT];
    /* status of the online MBIST */
    uint32_t onLineMbistCheckResult[SAF_ONLINE_MBIST_MAX_COUNT];
} saf_bist_check_result_t;

typedef struct
{
    const char * funcName;
    int (*func)(void);
} bist_test_callback_t;

/**
****************************************************************************************
 * @brief: Unions
****************************************************************************************
*/
/*!
 * @brief STCU2 Union.
 */
typedef union{
   vuint32_t R;            
   STCU2_STS_Bit B;        
 }STCU2_Bist_STS_tag;

/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/
FS_STATUS SAF_BIST_GetDcfValue(const saf_dcf_record_addr_t dcfAddr, uint32_t *pRecordData);
FS_STATUS SAF_BIST_SetDcfValue(uint32_t DcfFlashAddr, saf_dcf_record_t Record);
FS_STATUS SAF_BIST_DcfCmpValue(uint32_t DcfStartAddr);
FS_STATUS SAF_BIST_GetOfflinebistConfig(saf_bist_offline_config_t *pOfflineCfg);
FS_STATUS SAF_BIST_KeyPairCheck(void);
FS_STATUS SAF_BIST_OfflineCheck(saf_bist_check_result_t *pBistCheckResult);
#ifdef SAF_BIST_ONLINE_BIST_SUPPORTED
FS_STATUS SAF_BIST_OnlineInit(const uint8_t lbistPartition[], const uint8_t lbistCount, const uint8_t mbistPartition[], const uint8_t mbistCount);
FS_STATUS SAF_BIST_OnlineCheck(saf_bist_check_result_t *pBistCheckResult);
#endif

#ifdef __cplusplus
}
#endif

#endif
