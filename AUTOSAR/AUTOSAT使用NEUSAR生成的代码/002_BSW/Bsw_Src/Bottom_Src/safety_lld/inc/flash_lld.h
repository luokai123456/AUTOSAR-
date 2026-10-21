/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007PT
* DESCRIPTION : CCFC3007PT flash low level drivers h file
* HISTORY     : Initial version
* @file     flash_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
* @MCAL 	Version: 3.0.1
* @Safety 	Version: 3.0.0
*
*****************************************************************************/

#ifndef SAF_FLASH_LLD_H_
#define SAF_FLASH_LLD_H_

#include "derivative.h"
#include "status.h"
#include "common.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*
 * @brief User Configure for Flash Module
 */

/* Load Flash Access Code to SRAM */
#define SAF_FLS_AC_LOAD
/* The max size of write that are allowed. */
#define SAF_FLS_PROGRAMABLE_SIZE        (0x80U)
/* The number of word to check in each cycle. */
#define SAF_NUM_WORD_FOR_BLANK_CHECK    (0x90)
/* The number of word to verify in each cycle. */
#define SAF_NUM_WORD_FOR_PGM_VERIFY     (0x80)
/* The number of word to calculate sum in each cycle. */
#define SAF_NUM_WORD_FOR_CHECK_SUM      (0x120)

/* PFIx Max Block Number */
#define FLS_PFIX_MAX_BLOCK (12U)
#define FLS_SEL_MASK_LARGE_256K  (0xFFFFFFFFU >> (32U - FLS_PFIX_MAX_BLOCK))
/*
 * Flash program size in byte
 */
#define SAF_FLS_WORD_SIZE               (4U)
#define SAF_FLS_DWORD_SIZE              (8U)
#define SAF_FLS_PAGE_SIZE               (32U)  /* PRQA S 1534 */
#define SAF_FLS_QPAGE_SIZE              (128U) /* PRQA S 1534 */


/*******************************************************************************
 * Enumerations.
 ******************************************************************************/
/*
 *
 * Define for select special flash block to operate.
 *
 */
#define         SAF_FLS_BLK_LOW             (0x00U)   /* low flash block */
#define         SAF_FLS_BLK_MID             (0x01U)   /* mid flash block */
#define         SAF_FLS_BLK_HIGH            (0x02U)   /* high flash block */

#ifndef RESOURCE_SUPPORT_PFI
    #define     SAF_FLS_BLK_FIRST_256K      (0x03U)   /* first of 256K flash block */
    #define     SAF_FLS_BLK_SECOND_256K     (0x04U)   /* second of 256K flash block */
#else
    #ifdef RESOURCE_SUPPORT_PFI0
        #define SAF_FLS_BLK_LARGE0_256K     (0x03U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
        #define SAF_FLS_BLK_LARGE1_256K     (0x04U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
        #define SAF_FLS_BLK_LARGE2_256K     (0x05U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
        #define SAF_FLS_BLK_LARGE3_256K     (0x06U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
        #define SAF_FLS_BLK_LARGE4_256K     (0x07U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
        #define SAF_FLS_BLK_LARGE5_256K     (0x08U)   /* large0 of 256k flash block */
    #endif // RESOURCE_SUPPORT_PFI5
#endif // RESOURCE_SUPPORT_PFI

/*
 * Define for select flash space to erase.
 */
#define SAF_FLS_ERS_MAIN_SPACE      (0x00U)   /* erase flash main space */

/*
 * Define for flash status of flash operate.
 */
#define SAF_FLS_OK                  (0x00U)   /* Flash operate successful status  */

#define SAF_FLS_PGM_WRITE           (0x10U)   /* Program sequence in inter_lock write stage. */
#define SAF_FLS_ERS_WRITE           (0x11U)   /* Erase sequence in inter_lock write stage. */
#define SAF_FLS_ERS_SUS_PGM_WRITE   (0x12U)   /* Erase-suspend program sequence in inter_lock write stage. */

#define SAF_FLS_NO_SUS              (0x20U)   /* There is no program/erase operate for suspend */
#define SAF_FLS_PGM_SUS             (0x21U)   /* Program operate is in suspend state */
#define SAF_FLS_ERS_SUS             (0x22U)   /* Erase operate is in suspend state */
#define SAF_FLS_ERS_SUS_PGM_SUS     (0x23U)   /* Erase-suspended program operate is in suspend state */

#define SAF_FLS_RES_NOTHING         (0x30U)   /* There is no suspended program/erase operate */
#define SAF_FLS_RES_PGM             (0x31U)   /* Program operate is resumed */
#define SAF_FLS_RES_ERS             (0x32U)   /* Erase operate is resumed */
#define SAF_FLS_RES_ERS_PGM         (0x33U)   /* Erase-suspended program operate is resumed */

#define     SAF_FLS_FMC_BASE            ((uint32_t)0xFFFE0000U)
#define     SAF_FLS_T40FMC0_BASE        ((uint32_t)0xFFFE8000U)
#define     SAF_FLS_T40FMC1_BASE        ((uint32_t)0xFFFE8800U)
#define     SAF_FLS_T40FMC2_BASE        ((uint32_t)0xFFFE9000U)
#define     SAF_FLS_T40FMC3_BASE        ((uint32_t)0xFFFE9800U)
#define     SAF_FLS_T40FMC4_BASE        ((uint32_t)0xFFFEA000U)
#define     SAF_FLS_T40FMC5_BASE        ((uint32_t)0xFFFEA800U)
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
#define SAF_FLS_OP_SYNC             (0x00U)   /* flash sync operate(erase or program)  */
#define SAF_FLS_OP_ASYNC            (0x01U)   /* flash async operate(erase or program) */

typedef struct
{
    uint32_t block;
    volatile struct C55FMC_tag *controller;
} saf_flash_block_map_t;/* PRQA S 1535 */

typedef struct
{
    volatile struct C55FMC_tag *controller;
    volatile struct C55FMC_tag *mapped_controller;
} saf_flash_controller_map_t;/* PRQA S 1535 */

typedef struct
{
    uint32_t port;
    uint32_t mapped_port;
} saf_flash_port_map_t;/* PRQA S 1535 */
#ifdef CCFC3012PT
static const saf_flash_block_map_t saf_flashBlockMap0[FLS_BLOCK_ALL] = {
    /* Low Block */
    {0,  &FLS_FMC},
    {1,  &FLS_FMC},
    {2,  &FLS_FMC},
    {3,  &FLS_FMC},
    {4,  &FLS_FMC},
    {5,  &FLS_FMC},
    {6,  &FLS_FMC},
    {7,  &FLS_FMC},
    {8,  &FLS_FMC},
    {9,  &FLS_FMC},
    {10, &FLS_FMC},
    {11, &FLS_FMC},

    /* Mid Block */
    {12, &FLS_FMC},
    {13, &FLS_FMC},

    /* High Block */
    {14, &FLS_FMC},
    {15, &FLS_FMC},
    {16, &FLS_FMC},
    {17, &FLS_FMC},
    {18, &FLS_FMC},
    {19, &FLS_FMC},
    {20, &FLS_FMC},
    {21, &FLS_FMC},
    {22, &FLS_FMC},
    {23, &FLS_FMC},
    {24, &FLS_FMC},
    {25, &FLS_FMC},
    {26, &FLS_FMC},
    {27, &FLS_FMC},
    {28, &FLS_FMC},
    {29, &FLS_FMC},

    /* 256K Block */
    {30, &FLS_T40FMC0},
    {31, &FLS_T40FMC0},
    {32, &FLS_T40FMC0},
    {33, &FLS_T40FMC0},
    {34, &FLS_T40FMC0},
    {35, &FLS_T40FMC0},
    {36, &FLS_T40FMC0},
    {37, &FLS_T40FMC0},
    {38, &FLS_T40FMC0},
    {39, &FLS_T40FMC0},
    {40, &FLS_T40FMC0},
    {41, &FLS_T40FMC0},
    {42, &FLS_T40FMC1},
    {43, &FLS_T40FMC1},
    {44, &FLS_T40FMC1},
    {45, &FLS_T40FMC1},
    {46, &FLS_T40FMC1},
    {47, &FLS_T40FMC1},
    {48, &FLS_T40FMC1},
    {49, &FLS_T40FMC1},
    {50, &FLS_T40FMC1},
    {51, &FLS_T40FMC1},
    {52, &FLS_T40FMC1},
    {53, &FLS_T40FMC1},
    {54, &FLS_T40FMC2},
    {55, &FLS_T40FMC2},
    {56, &FLS_T40FMC2},
    {57, &FLS_T40FMC2},
    {58, &FLS_T40FMC2},
    {59, &FLS_T40FMC2},
    {60, &FLS_T40FMC2},
    {61, &FLS_T40FMC2},
    {62, &FLS_T40FMC2},
    {63, &FLS_T40FMC2},
    {64, &FLS_T40FMC2},
    {65, &FLS_T40FMC2},
    {66, &FLS_T40FMC3},
    {67, &FLS_T40FMC3},
    {68, &FLS_T40FMC3},
    {69, &FLS_T40FMC3},
    {70, &FLS_T40FMC3},
    {71, &FLS_T40FMC3},
    {72, &FLS_T40FMC3},
    {73, &FLS_T40FMC3},
    {74, &FLS_T40FMC3},
    {75, &FLS_T40FMC3},
    {76, &FLS_T40FMC3},
    {77, &FLS_T40FMC3},
    {78, &FLS_T40FMC4},
    {79, &FLS_T40FMC4},
    {80, &FLS_T40FMC4},
    {81, &FLS_T40FMC4},
    {82, &FLS_T40FMC4},
    {83, &FLS_T40FMC4},
    {84, &FLS_T40FMC4},
    {85, &FLS_T40FMC4},
    {86, &FLS_T40FMC4},
    {87, &FLS_T40FMC4},
    {88, &FLS_T40FMC4},
    {89, &FLS_T40FMC4},
    {90, &FLS_T40FMC5},
    {91, &FLS_T40FMC5},
    {92, &FLS_T40FMC5},
    {93, &FLS_T40FMC5},
    {94, &FLS_T40FMC5},
    {95, &FLS_T40FMC5},
};

static const saf_flash_block_map_t saf_flashBlockMap1[FLS_BLOCK_ALL] = {
    /* Low Block */
    {0,  &FLS_FMC},
    {1,  &FLS_FMC},
    {2,  &FLS_FMC},
    {3,  &FLS_FMC},
    {4,  &FLS_FMC},
    {5,  &FLS_FMC},
    {6,  &FLS_FMC},
    {7,  &FLS_FMC},
    {8,  &FLS_FMC},
    {9,  &FLS_FMC},
    {10, &FLS_FMC},
    {11, &FLS_FMC},

    /* Mid Block */
    {12, &FLS_FMC},
    {13, &FLS_FMC},

    /* High Block */
    {14, &FLS_FMC},
    {15, &FLS_FMC},
    {16, &FLS_FMC},
    {17, &FLS_FMC},
    {18, &FLS_FMC},
    {19, &FLS_FMC},
    {20, &FLS_FMC},
    {21, &FLS_FMC},
    {22, &FLS_FMC},
    {23, &FLS_FMC},
    {24, &FLS_FMC},
    {25, &FLS_FMC},
    {26, &FLS_FMC},
    {27, &FLS_FMC},
    {28, &FLS_FMC},
    {29, &FLS_FMC},

    /* 256K Block */
    {30, &FLS_T40FMC3},
    {31, &FLS_T40FMC3},
    {32, &FLS_T40FMC3},
    {33, &FLS_T40FMC3},
    {34, &FLS_T40FMC3},
    {35, &FLS_T40FMC3},
    {36, &FLS_T40FMC3},
    {37, &FLS_T40FMC3},
    {38, &FLS_T40FMC3},
    {39, &FLS_T40FMC3},
    {40, &FLS_T40FMC3},
    {41, &FLS_T40FMC3},
    {42, &FLS_T40FMC4},
    {43, &FLS_T40FMC4},
    {44, &FLS_T40FMC4},
    {45, &FLS_T40FMC4},
    {46, &FLS_T40FMC4},
    {47, &FLS_T40FMC4},
    {48, &FLS_T40FMC4},
    {49, &FLS_T40FMC4},
    {50, &FLS_T40FMC4},
    {51, &FLS_T40FMC4},
    {52, &FLS_T40FMC4},
    {53, &FLS_T40FMC4},
    {54, &FLS_T40FMC5},
    {55, &FLS_T40FMC5},
    {56, &FLS_T40FMC5},
    {57, &FLS_T40FMC5},
    {58, &FLS_T40FMC5},
    {59, &FLS_T40FMC5},
    {60, &FLS_T40FMC5},
    {61, &FLS_T40FMC5},
    {62, &FLS_T40FMC5},
    {63, &FLS_T40FMC5},
    {64, &FLS_T40FMC5},
    {65, &FLS_T40FMC5},
    {66, &FLS_T40FMC0},
    {67, &FLS_T40FMC0},
    {68, &FLS_T40FMC0},
    {69, &FLS_T40FMC0},
    {70, &FLS_T40FMC0},
    {71, &FLS_T40FMC0},
    {72, &FLS_T40FMC0},
    {73, &FLS_T40FMC0},
    {74, &FLS_T40FMC0},
    {75, &FLS_T40FMC0},
    {76, &FLS_T40FMC0},
    {77, &FLS_T40FMC0},
    {78, &FLS_T40FMC1},
    {79, &FLS_T40FMC1},
    {80, &FLS_T40FMC1},
    {81, &FLS_T40FMC1},
    {82, &FLS_T40FMC1},
    {83, &FLS_T40FMC1},
    {84, &FLS_T40FMC1},
    {85, &FLS_T40FMC1},
    {86, &FLS_T40FMC1},
    {87, &FLS_T40FMC1},
    {88, &FLS_T40FMC1},
    {89, &FLS_T40FMC1},
    {90, &FLS_T40FMC2},
    {91, &FLS_T40FMC2},
    {92, &FLS_T40FMC2},
    {93, &FLS_T40FMC2},
    {94, &FLS_T40FMC2},
    {95, &FLS_T40FMC2},
};

static const saf_flash_controller_map_t saf_flashControllerMap0[FLS_CONTROLLER_NUM] = {
    {&FLS_FMC,     &FLS_FMC},
    {&FLS_T40FMC0, &FLS_T40FMC0},
    {&FLS_T40FMC1, &FLS_T40FMC1},
    {&FLS_T40FMC2, &FLS_T40FMC2},
    {&FLS_T40FMC3, &FLS_T40FMC3},
    {&FLS_T40FMC4, &FLS_T40FMC4},
    {&FLS_T40FMC5, &FLS_T40FMC5},
};

static const saf_flash_controller_map_t saf_flashControllerMap1[FLS_CONTROLLER_NUM] = {
    {&FLS_FMC,     &FLS_FMC},
    {&FLS_T40FMC0, &FLS_T40FMC3},
    {&FLS_T40FMC1, &FLS_T40FMC4},
    {&FLS_T40FMC2, &FLS_T40FMC5},
    {&FLS_T40FMC3, &FLS_T40FMC0},
    {&FLS_T40FMC4, &FLS_T40FMC1},
    {&FLS_T40FMC5, &FLS_T40FMC2},
};

static const saf_flash_port_map_t flashPortMap0[FLS_CONTROLLER_NUM * 2] = {
    {0,  0},  // {FLS_PORT1,  FLS_PORT1},
    {1,  1},  // {FLS_PORT2,  FLS_PORT2},
    {2,  2},  // {FLS_PORT3,  FLS_PORT3},
    {3,  3},  // {FLS_PORT4,  FLS_PORT4},
    {4,  4},  // {FLS_PORT5,  FLS_PORT5},
    {5,  5},  // {FLS_PORT6,  FLS_PORT6},
    {6,  6},  // {FLS_PORT7,  FLS_PORT7},
    {7,  7},  // {FLS_PORT8,  FLS_PORT8},
    {8,  8},  // {FLS_PORT9,  FLS_PORT9},
    {9,  9},  // {FLS_PORT10, FLS_PORT10},
    {10, 10}, // {FLS_PORT11, FLS_PORT11},
    {11, 11}, // {FLS_PORT12, FLS_PORT12},
    {12, 12}, // {FLS_PORT13, FLS_PORT13},
    {13, 13}, // {FLS_PORT14, FLS_PORT14},
};

static const saf_flash_port_map_t flashPortMap1[FLS_CONTROLLER_NUM * 2] = {
    {0,  0},  // {FLS_PORT1,  FLS_PORT1},
    {1,  1},  // {FLS_PORT2,  FLS_PORT2},
    {2,  8},  // {FLS_PORT3,  FLS_PORT9},
    {3,  9},  // {FLS_PORT4,  FLS_PORT10},
    {4,  10}, // {FLS_PORT5,  FLS_PORT11},
    {5,  11}, // {FLS_PORT6,  FLS_PORT12},
    {6,  12}, // {FLS_PORT7,  FLS_PORT13},
    {7,  13}, // {FLS_PORT8,  FLS_PORT14},
    {8,  2},  // {FLS_PORT9,  FLS_PORT3},
    {9,  3},  // {FLS_PORT10, FLS_PORT4},
    {10, 4},  // {FLS_PORT11, FLS_PORT5},
    {11, 5},  // {FLS_PORT12, FLS_PORT6},
    {12, 6},  // {FLS_PORT13, FLS_PORT7},
    {13, 7},  // {FLS_PORT14, FLS_PORT8},
};
#endif
/*******************************************************************************
* Function prototype
*******************************************************************************/

/*
 * Function pointer of access code.
 */
#ifdef SAF_FLS_AC_LOAD
    #ifndef RESOURCE_SUPPORT_PFI
        typedef void (* saf_fls_acload_t)(void);
    #else
        typedef void (* saf_fls_acload_t)(volatile struct C55FMC_tag *fmc);
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
    #ifdef RESOURCE_SUPPORT_PFI0
        uint32_t large0BlkSel;            /* Select bits for large0 block */
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
        uint32_t large1BlkSel;            /* Select bits for large1 block */
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
        uint32_t large2BlkSel;            /* Select bits for large2 block */
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
        uint32_t large3BlkSel;            /* Select bits for large3 block */
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
        uint32_t large4BlkSel;            /* Select bits for large4 block */
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
        uint32_t large5BlkSel;            /* Select bits for large5 block */
    #endif // RESOURCE_SUPPORT_PFI5
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
    uint32_t mode;                   /* Operate mode type(SAF_FLS_OP_SYNC or SAF_FLS_OP_ASYNC) */
} fls_ctx_data_t;

/* Flash Swap Status */
extern uint8_t saf_g_swapStatus;

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
status_t SAF_FLASH_LLD_CheckProgramStatus(fls_ctx_data_t * pCtxData,
                                      uint8_t * opRet);

/*
 * @brief Check the erase operation
 *
 * This function will check the status of ongoing erase operation.
 *
 * @param[out] opRet: Return the state of flash.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_CheckEraseStatus(uint8_t * opRet);

/*
 * @brief Initializes the FLASH module
 *
 * This function will initialize flash module.
 *
 * @param[in] lockBlk: Indicating the lock status of flash module.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Init(const uint8_t * lockBlk);

void SAF_FLASH_LLD_SafOperationInit(void);

/*
 * @brief Get flash block lock status
 *
 * This function will get the lock status for selected flash block.
 *
 * @param[in] lockedBlkSel: Select the special flash block.
 * @param[out] lockedBlkStatus: Return lock status of selected flash block.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_GetLock(uint8_t lockedBlkSel,
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
status_t SAF_FLASH_LLD_SetLock(uint8_t lockedBlkSel,
                           uint32_t lockedBlkStatus);

/*
 * @brief Erase the selected flash block
 *
 * This function is to do erase operation for selected flash block.
 *
 * @param[in] eraseSpace: Select flash main space.
 * @param[in] blkSel: Select the special flash block for erasing.
 * @param[in] mode: means the operate mode of erase.
              SAF_FLS_OP_SYNC: means sync erase operate.
              SAF_FLS_OP_ASYNC: means async erase operate.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Erase(uint8_t eraseSpace,
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
status_t SAF_FLASH_LLD_BlankCheckSaf(uint32_t dest,
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
status_t SAF_FLASH_LLD_Program(fls_ctx_data_t * pCtxData);

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
status_t SAF_FLASH_LLD_ProgramVerifySaf(uint32_t dest,
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
status_t SAF_FLASH_LLD_CheckSum(uint32_t dest,
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
status_t SAF_FLASH_LLD_Abort(void);

/*
 * @brief Suspend a flash operation
 *
 * This function will suspend a flash operation which is in progress.
 *
 * @param[out] susStatus: Return suspend state after call this function.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Suspend(uint8_t * susStatus);

/*
 * @brief Resume the suspended flash operation
 *
 * This function will resume the suspended flash operation.
 *
 * @param[out] resStatus: Return resume state after call this function.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Resume(uint8_t * resStatus);

/*
 * @brief Get the over-program protection status
 *
 * This function will return the over-program protection status.
 *
 * @param[in] flsBlk: Select the special flash block to get over-program protection status.
 * @param[out] protStatus: Return bit map for over-program protection status.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_GetOverPgmProtStatus(uint8_t flsBlk,
                                        uint32_t * protStatus);

/*
 * @brief Enable flash command complete interrupt.
 *
 * This function will enable flash command complete interrupt.
 */
void SAF_FLASH_LLD_EnableCmdCompleteInterupt(void);

/*
 * @brief Disable flash command complete interrupt.
 *
 * This function will disable flash command complete interrupt.
 *
 */
void SAF_FLASH_LLD_DisableCmdCompleteInterupt(void);

/*
 * @brief Flash command complete interrupt handle function.
 *
 * The interrupt handle function for flash command complete interrupt.
 *
 */
void SAF_FLASH_Cmd_Done_ISR(void);
#ifdef RESOURCE_SUPPORT_PFI0
    void SAF_FLASH_PFI0_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI0

#ifdef RESOURCE_SUPPORT_PFI1
    void SAF_FLASH_PFI1_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI1

#ifdef RESOURCE_SUPPORT_PFI2
    void SAF_FLASH_PFI2_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI2

#ifdef RESOURCE_SUPPORT_PFI3
    void SAF_FLASH_PFI3_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI3

#ifdef RESOURCE_SUPPORT_PFI4
    void SAF_FLASH_PFI4_Cmd_Done_ISR(void);
#endif // RESOURCE_SUPPORT_PFI4

#ifdef RESOURCE_SUPPORT_PFI5
    void SAF_FLASH_PFI5_Cmd_Done_ISR(void);
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
status_t SAF_FLASH_LLD_DisableCache(uint8_t port, uint32_t *originValue);

/*
 * @brief Restore flash cache
 *
 * This function will restore configuration register.
 *
 * @param[in] port: Select flash port to restore.
 * @param[in] originValue: The original value of PFCR.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_RestoreCache(uint8_t port, uint32_t originValue);

/*
 * @brief Enable Flash Calibration Region Descriptor
 *
 * This function will Enable flash calibration region descriptor.
 *
 * @param[in] cdrIndex: The Index of Calibration Remap Descriptor.
 * @param[in] remapConfig: The config of Calibration Region Descriptor.
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Overlay_Config_Enable(uint32_t cdrIndex, flash_remap_config_t *remapConfig);

/*
 * @brief Disable Flash Calibration Region Descriptor
 *
 * This function will disable flash calibration region descriptor.
 *
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Overlay_Config_Disable(uint32_t cdrIndex);

/*
 * @brief Enable Flash Global Calibration remap
 *
 * This function will enable flash global calibration remap.
 *
 * @return Operation status
 */
status_t SAF_FLASH_LLD_Overlay_Golbal_Enable(void);

/*
 * @brief Disable Flash Global Calibration remap
 *
 * This function will disable flash global calibration remap.
 *
 * @return Operation status
 */
 status_t SAF_FLASH_LLD_Overlay_Golbal_Disable(void);
 
#if 0 // Legacy Overlay symbols are provided by Safety/flash_lld.c.
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
 * @brief Enable Flash Global Calibration remap
 *
 * This function will enable flash global calibration remap.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Golbal_Enable(void);

/*
 * @brief Disable Flash Calibration Region Descriptor
 *
 * This function will disable flash calibration region descriptor.
 *
 * @return Operation status
 */
status_t FLASH_LLD_Overlay_Config_Disable(uint32_t cdrIndex);

/*
 * @brief Disable Flash Global Calibration remap
 *
 * This function will disable flash global calibration remap.
 *
 * @return Operation status
 */
 status_t FLASH_LLD_Overlay_Golbal_Disable(void);
#endif

#if defined(__cplusplus)
}
#endif



#endif /* SAF_FLASH_LLD_H_ */
