/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx flash low level drivers h file
* HISTORY     : Initial version
* @file     flash_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/

#ifndef FLASH_LLD_H_
#define FLASH_LLD_H_

#include "derivative.h"
#include "status.h"
// #include "libSwap.h"
#include "common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 * @brief User Configure for Flash Module
 */

/* Load Flash Access Code to SRAM */
#define FLS_AC_LOAD
/* The max size of write that are allowed. */
#define FLS_PROGRAMABLE_SIZE        (0x80U)
/* The number of word to check in each cycle. */
#define NUM_WORD_FOR_BLANK_CHECK    (0x90)
/* The number of word to verify in each cycle. */
#define NUM_WORD_FOR_PGM_VERIFY     (0x80)
/* The number of word to calculate sum in each cycle. */
#define NUM_WORD_FOR_CHECK_SUM      (0x120)

/*
 * Flash program size in byte
 */
#define FLS_WORD_SIZE               (4U)
#define FLS_DWORD_SIZE              (8U)
#define FLS_PAGE_SIZE               (32U)  /* PRQA S 1534 */
#define FLS_QPAGE_SIZE              (128U) /* PRQA S 1534 */


/*******************************************************************************
 * Enumerations.
 ******************************************************************************/
/*
 *
 * Define for select special flash block to operate.
 *
 */
#define         FLS_BLK_LOW             (0x00U)   /* low flash block */
#define         FLS_BLK_MID             (0x01U)   /* mid flash block */
#define         FLS_BLK_HIGH            (0x02U)   /* high flash block */

#ifndef RESOURCE_SUPPORT_PFI
    #define     FLS_BLK_FIRST_256K      (0x03U)   /* first of 256K flash block */
    #define     FLS_BLK_SECOND_256K     (0x04U)   /* second of 256K flash block */
#else
    #ifdef RESOURCE_SUPPORT_PFI0
        #define FLS_BLK_LARGE0_256K     (0x03U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
        #define FLS_BLK_LARGE1_256K     (0x04U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
        #define FLS_BLK_LARGE2_256K     (0x05U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
        #define FLS_BLK_LARGE3_256K     (0x06U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
        #define FLS_BLK_LARGE4_256K     (0x07U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
        #define FLS_BLK_LARGE5_256K     (0x08U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI5
#endif // RESOURCE_SUPPORT_PFI

/*
 * Define for select flash space to erase.
 */
#define FLS_ERS_MAIN_SPACE      (0x00U)   /* erase flash main space */

/*
 * Define for flash status of flash operate.
 */
#define FLS_OK                  (0x00U)   /* Flash operate successful status  */

#define FLS_PGM_WRITE           (0x10U)   /* Program sequence in inter_lock write stage. */
#define FLS_ERS_WRITE           (0x11U)   /* Erase sequence in inter_lock write stage. */
#define FLS_ERS_SUS_PGM_WRITE   (0x12U)   /* Erase-suspend program sequence in inter_lock write stage. */

#define FLS_NO_SUS              (0x20U)   /* There is no program/erase operate for suspend */
#define FLS_PGM_SUS             (0x21U)   /* Program operate is in suspend state */
#define FLS_ERS_SUS             (0x22U)   /* Erase operate is in suspend state */
#define FLS_ERS_SUS_PGM_SUS     (0x23U)   /* Erase-suspended program operate is in suspend state */

#define FLS_RES_NOTHING         (0x30U)   /* There is no suspended program/erase operate */
#define FLS_RES_PGM             (0x31U)   /* Program operate is resumed */
#define FLS_RES_ERS             (0x32U)   /* Erase operate is resumed */
#define FLS_RES_ERS_PGM         (0x33U)   /* Erase-suspended program operate is resumed */

/*
 * Define for select PFlash port.
 */
enum {
    FLS_PORT1,     /* port1 */
    FLS_PORT2,     /* port2 */

#ifdef RESOURCE_SUPPORT_PFI0
    FLS_PORT3,     /* port3  */
    FLS_PORT4,     /* port4  */
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    FLS_PORT5,     /* port5  */
    FLS_PORT6,     /* port6  */
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    FLS_PORT7,     /* port7  */
    FLS_PORT8,     /* port8  */
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    FLS_PORT9,     /* port9  */
    FLS_PORT10,    /* port10 */
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    FLS_PORT11,    /* port11 */
    FLS_PORT12,    /* port12 */
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    FLS_PORT13,    /* port13 */
    FLS_PORT14,    /* port14 */
#endif // RESOURCE_SUPPORT_PFI5

    FLS_PORT_MAX
};

/*
 * Define flash operate mode (sync or async).
 */
#define FLS_OP_SYNC             (0x00U)   /* flash sync operate(erase or program)  */
#define FLS_OP_ASYNC            (0x01U)   /* flash async operate(erase or program) */

/*******************************************************************************
* Function prototype
*******************************************************************************/

/*
 * Function pointer of access code.
 */
#ifdef FLS_AC_LOAD
    #ifndef RESOURCE_SUPPORT_PFI
        typedef void (* fls_acload_t)(void);
    #else
        typedef void (* fls_acload_t)(volatile struct C55FMC_tag *fmc);
    #endif // RESOURCE_SUPPORT_PFI
#endif // FLS_AC_LOAD

/*
 * Define the structure for select special flash block.
 */
typedef struct /* PRQA S 3630 */
{
        uint32_t lowBlkSel;               /* Select bits for low block */
        uint32_t midBlkSel;               /* Select bits for mid block */
        uint32_t highBlkSel;              /* Select bits for high block */

#ifndef RESOURCE_SUPPORT_PFI
        uint32_t first256KBlkSel;         /* Select bits for first of 256K block */
        uint32_t second256KBlkSel;        /* Select bits for second of 256K block */
#else
        uint32_t large0BlkSel;            /* Select bits for large0 block */
        uint32_t large1BlkSel;            /* Select bits for large1 block */
        uint32_t large2BlkSel;            /* Select bits for large2 block */
        uint32_t large3BlkSel;            /* Select bits for large3 block */
        uint32_t large4BlkSel;            /* Select bits for large4 block */
        uint32_t large5BlkSel;            /* Select bits for large5 block */
#endif // RESOURCE_SUPPORT_PFI
} fls_blk_sel_t;

/*
 * Define the structure for store the context of data of flash operate.
 */
typedef struct /* PRQA S 3630 */
{
    uint32_t dest;                   /* Destination address for flash operate */
    uint32_t src;                    /* Source address for flash operate */
    uint32_t size;                   /* Size of the flash operate */
    uint32_t mode;                   /* Operate mode type(FLS_OP_SYNC or FLS_OP_ASYNC) */
} fls_ctx_data_t;

/* Flash Swap Status */
extern uint8_t g_swapStatus;
extern uint8_t g_flashSize;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*
 * @brief Check the program operation
 *
 * This function will check the status of ongoing program operation.
 *
 * @param[in] pCtxData: Storing context variables.
 * @param[out] opRet: Return the status of flash.
 * @return Operation status
 */
status_t FLASH_LLD_CheckProgramStatus(fls_ctx_data_t * pCtxData,
                                      uint8_t * opRet);

/*
 * @brief Check the erase operation
 *
 * This function will check the status of ongoing erase operation.
 *
 * @param[out] opRet: Return the state of flash.
 * @return Operation status
 */
status_t FLASH_LLD_CheckEraseStatus(uint8_t * opRet);

/*
 * @brief Initializes the FLASH module
 *
 * This function will initialize flash module.
 *
 * @param[in] lockBlk: Indicating the lock status of flash module.
 * @return Operation status
 */
status_t FLASH_LLD_Init(const uint8_t * lockBlk);

/*
 * @brief Get flash block lock status
 *
 * This function will get the lock status for selected flash block.
 *
 * @param[in] lockedBlkSel: Select the special flash block.
 * @param[out] lockedBlkStatus: Return lock status of selected flash block.
 * @return Operation status
 */
status_t FLASH_LLD_GetLock(uint8_t lockedBlkSel,
                           uint32_t * lockedBlkStatus);

/*
 * @brief Set flash block lock status
 *
 * This function will set the lock status for selected flash block.
 *
 * @param[in] lockedBlkSel: Select the special flash block.
 * @param[in] lockedBlkStatus: The lock status will set to the selected flash block.
 * @return Operation status
 */
status_t FLASH_LLD_SetLock(uint8_t lockedBlkSel,
                           uint32_t lockedBlkStatus);

/*
 * @brief Erase the selected flash block
 *
 * This function is to do erase operation for selected flash block.
 *
 * @param[in] eraseSpace: Select flash main space.
 * @param[in] blkSel: Select the special flash block for erasing.
 * @param[in] mode: means the operate mode of erase.
              FLS_OP_SYNC: means sync erase operate.
              FLS_OP_ASYNC: means async erase operate.
 * @return Operation status
 */
status_t FLASH_LLD_Erase(uint8_t eraseSpace,
                         fls_blk_sel_t * blkSel,
                         uint32_t mode);

/*
 * @brief Blank check for the previous erase operation
 *
 * This function is to do blank check for the previous erase operation.
 *
 * @param[in] dest: Destination address to be checked.(4 bytes aligned)
 * @param[in] size: Size of the flash region to check.(4 bytes aligned)
 * @param[in] checkWordSize: The number of word need check in each cycle.
 * @param[out] pFailAddr: Return the first error address of blank check.
 * @return Operation status
 */
status_t FLASH_LLD_BlankCheck(uint32_t dest,
                              uint32_t size,
                              uint32_t checkWordSize,
                              uint32_t * pFailAddr);

/*
 * @brief Program operation for flash
 *
 * This function is to do program operation for flash.
 *
 * @param[in] pCtxData: Storing context variables.
 * @return Operation status
 */
status_t FLASH_LLD_Program(fls_ctx_data_t * pCtxData);

/*
 * @brief Verify the previous program operation
 *
 * This function is to verify the previous program operation.
 *
 * @param[in] dest: Destination address for verify.(4 bytes aligned)
 * @param[in] size: Size of the flash region to verify.(4 bytes aligned)
 * @param[in] src: Source buffer address for verify.(4 bytes aligned)
 * @param[in] checkWordSize: The number of word need to verify in each cycle.
 * @param[out] pFailAddr: Return the first failing address in flash.
 * @return Operation status
 */
status_t FLASH_LLD_ProgramVerify(uint32_t dest,
                                 uint32_t size,
                                 uint32_t src,
                                 uint32_t checkWordSize,
                                 uint32_t * pFailAddr);

/*
 * @brief Perform a sum over the specified flash
 *
 * This function perform a sum(32 bit) over the specified flash without carry.
 *
 * @param[in] dest: Destination address to the specified flash memory.(4 bytes aligned)
 * @param[in] size: Size in bytes of the flash region to check sum.(4 bytes aligned)
 * @param[in] checkWordSize: The number of word need to calculate sum in each cycle.
 * @param[out] pSum: Return the sum value.
 * @return Operation status
 */
status_t FLASH_LLD_CheckSum(uint32_t dest,
                            uint32_t size,
                            uint32_t checkWordSize,
                            uint32_t * pSum);

/*
 * @brief Abort the flash program/erase operation
 *
 * This function will abort a flash program or erase operation.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Abort(void);

/*
 * @brief Suspend a flash operation
 *
 * This function will suspend a flash operation which is in progress.
 *
 * @param[out] susStatus: Return suspend state after call this function.
 * @return Operation status
 */
status_t FLASH_LLD_Suspend(uint8_t * susStatus);

/*
 * @brief Resume the suspended flash operation
 *
 * This function will resume the suspended flash operation.
 *
 * @param[out] resStatus: Return resume state after call this function.
 * @return Operation status
 */
status_t FLASH_LLD_Resume(uint8_t * resStatus);

/*
 * @brief Get the over-program protection status
 *
 * This function will return the over-program protection status.
 *
 * @param[in] flsBlk: Select the special flash block to get over-program protection status.
 * @param[out] protStatus: Return bit map for over-program protection status.
 * @return Operation status
 */
status_t FLASH_LLD_GetOverPgmProtStatus(uint8_t flsBlk,
                                        uint32_t * protStatus);

/*
 * @brief Enable flash command complete interrupt.
 *
 * This function will enable flash command complete interrupt.
 */
void FLASH_LLD_EnableCmdCompleteInterupt(void);

/*
 * @brief Disable flash command complete interrupt.
 *
 * This function will disable flash command complete interrupt.
 *
 */
void FLASH_LLD_DisableCmdCompleteInterupt(void);

/*
 * @brief Flash command complete interrupt handle function.
 *
 * The interrupt handle function for flash command complete interrupt.
 *
 */
    void FLASH_Cmd_Done_ISR(void);

#ifdef RESOURCE_SUPPORT_PFI0
    void FLASH_PFI0_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    void FLASH_PFI1_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    void FLASH_PFI2_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    void FLASH_PFI3_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    void FLASH_PFI4_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    void FLASH_PFI5_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI5

/*
 * @brief Disable flash cache
 *
 * This function used to disable flash cache.
 *
 * @param[in] port: Select flash port to disable cache.
 * @param[out] originValue: Return the original value of PFCR.
 * @return Operation status
 */
status_t FLASH_LLD_DisableCache(uint8_t port, uint32_t *originValue);

/*
 * @brief Restore flash cache
 *
 * This function will restore configuration register.
 *
 * @param[in] port: Select flash port to restore.
 * @param[in] originValue: The original value of PFCR.
 * @return Operation status
 */
status_t FLASH_LLD_RestoreCache(uint8_t port, uint32_t originValue);

/*
 * @brief Enable Flash Calibration Region Descriptor
 *
 * This function will Enable flash calibration region descriptor.
 *
 * @param[in] cdrIndex: The Index of Calibration Remap Descriptor.
 * @param[in] remapConfig: The config of Calibration Region Descriptor.
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Config_Enable(uint32_t cdrIndex, flash_remap_config_t *remapConfig);

/*
 * @brief Disable Flash Calibration Region Descriptor
 *
 * This function will disable flash calibration region descriptor.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Config_Disable(uint32_t cdrIndex);

/*
 * @brief Enable Flash Global Calibration remap
 *
 * This function will enable flash global calibration remap.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Golbal_Enable(void);

/*
 * @brief Disable Flash Global Calibration remap
 *
 * This function will disable flash global calibration remap.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Golbal_Disable(void);

#if defined(__cplusplus)
}
#endif



#endif /* FLASH_LLD_H_ */
