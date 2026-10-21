/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx I2C lower level driver h file
* HISTORY     : Initial version.
* @file     iic_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 0779,1534,3472,1535,3630,0654,4116,4558,4304,3432,1753,1752 EOF*/
#ifndef IIC_LLD_H
#define IIC_LLD_H

#ifdef __cplusplus
extern "C"{
#endif
#include "derivative.h"
#include "status.h"
#include "common.h"
#include "CDD_I2c_Cfg.h"

#if (CDD_I2C_DMA_USED == STD_ON)
#include "eDma.h"
#endif

#ifdef RESOURCE_SUPPORT_I2C

#define CDD_I2C_CFG_C_VENDOR_ID                     176
#define CDD_I2C_CFG_C_AR_REL_MAJOR_VER              4
#define CDD_I2C_CFG_C_AR_REL_MINOR_VER              4
#define CDD_I2C_CFG_C_AR_REL_REV_VER                0
#define CDD_I2C_CFG_C_SW_MAJOR_VER                  3
#define CDD_I2C_CFG_C_SW_MINOR_VER                  0
#define CDD_I2C_CFG_C_SW_PATCH_VER                  0

#if (MCAL_VENDOR_ID != CDD_I2C_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CDD_I2C_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CDD_I2C_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CDD_I2C_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CDD_I2C_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CDD_I2C_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CDD_I2C_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CDD_I2C_CFG_C_SW_PATCH_VER "
#endif

typedef struct {
    volatile VAR(uint8, AUTOMATIC) IBAD;                               /** < I2C Bus Address Register, offset: 0x0 */
    volatile VAR(uint8, AUTOMATIC) IBFD;                               /** < I2C Bus Frequency Divider Register, offset: 0x1 */
    volatile VAR(uint8, AUTOMATIC) IBCR;                               /** < I2C Bus Control Register, offset: 0x2 */
    volatile VAR(uint8, AUTOMATIC) IBSR;                               /** < I2C Bus Status Register, offset: 0x3 */
    volatile VAR(uint8, AUTOMATIC) IBDR;                               /** < I2C Bus Data I/O Register, offset: 0x4 */
    volatile VAR(uint8, AUTOMATIC) IBIC;                               /** < I2C Bus Interrupt Config Register, offset: 0x5 */
} I2C_Type, *I2C_MemMapPtr;

#define I2C_0_BASE                               ((uint32_t)0xFFE68000UL)

#define I2C_0_0                                  ((I2C_Type *)I2C_0_BASE)

#define I2C_1_BASE                               ((uint32_t)0xFBE68000UL)

#define I2C_1_1                                    ((I2C_Type *)I2C_1_BASE)

#define I2C_BASE_ADDRS                           { I2C_0_BASE, I2C_1_BASE}

#define I2C_BASE_PTRS                            { I2C_0_0, I2C_1_1}

#define I2C_INSTANCE_COUNT                       2

#if (CDD_I2C_DMA_USED == STD_ON)
#define I2C_DMA_INSTANCE                    (0U)
#ifdef RESOURCE_SUPPORT_I2C1
#define I2C_DMA_REQ                         {{DMAMUX9_I2C_0_TX, DMAMUX9_I2C_0_RX}, \
                                            {DMAMUX6_I2C_1_TX, DMAMUX6_I2C_1_RX}}
#else
#define I2C_DMA_REQ                         {{DMAMUX9_I2C_0_TX, DMAMUX9_I2C_0_RX}, \
                                            {DMAMUX3_I2C_0_TX, DMAMUX3_I2C_0_RX}}
#endif
#endif

#define I2C_IRQS                            {440u, 442u}

#define I2C_CLOCKS                          {I2C0_CLK, I2C1_CLK}

#define MAX_I2C_SCL_DIVIDERS                    71U

#define I2C_SCL_DIVIDER                     {{0x0, 20U}, {0x1, 22U}, {0x2, 24U}, {0x3, 26U}, {0x4, 28U}, {0x5, 30U}, {0x9, 32U}, {0x6, 34U}, {0x0A, 36U}, {0x7, 40U}, \
                                            {0x0C, 44U}, {0x0D, 48U}, {0x43, 52U}, {0x0E, 56U}, {0x45, 60U}, {0x12, 64U}, {0x0F, 68U}, {0x13, 72U}, {0x14, 80U}, {0x15, 88U}, \
                                            {0x19, 96U}, {0x16, 104U}, {0x1A, 112U}, {0x85, 120U}, {0x17, 128U}, {0x4F, 136U}, {0x1C, 144U}, {0x1D, 160U}, {0x55, 176U}, \
                                            {0x1E, 192U}, {0x56, 208U}, {0x22, 224U}, {0x1F, 240U}, {0x23, 256U}, {0x8F, 272U}, {0x24, 288U}, {0x25, 320U}, {0x95, 352U}, \
                                            {0x26, 384U}, {0x96, 416U}, {0x2A, 448U}, {0x27, 480U}, {0x2B, 512U}, {0x2C, 576U}, {0x2D, 640U}, {0x2E, 768U}, {0x32, 896U}, \
                                            {0x2F, 960U}, {0x33, 1024U}, {0x34, 1152U}, {0x35, 1280U}, {0x36, 1536U}, {0x3A, 1792U}, {0x37, 1920U}, {0x3B, 2048U}, {0x3C, 2304U}, \
                                            {0x3D, 2560U}, {0x3E, 3072U}, {0x7A, 3584U}, {0x3F, 3840U}, {0x7B, 4096U}, {0x7C, 4608U}, {0x7D, 5120U}, {0x7E, 6144U}, {0xBA, 7168U}, \
                                            {0x7F, 7680U}, {0xBB, 8192U}, {0xBC, 9216U}, {0xBD, 10240U}, {0xBE, 12288U}, {0xBF, 15360U}}

#define I2C_BAUDRATE_100K                        0x29//0x26//0x65
#define I2C_BAUDRATE_200K                        0x5D

#define CDD_I2C_CORE_NUM                    MCAL_CORE_NUM

#define I2C_FREEBUS_CLK_EDGES 18
#define I2C_FREEBUS_IDLE_TICKS 200
typedef enum
{
    I2C_SLAVE_RX_FULL_EVENT = 0x00U,
    I2C_SLAVE_TX_EMPTY_EVENT = 0x01U,
    I2C_SLAVE_TX_REQ_EVENT = 0x02U,
    I2C_SLAVE_RX_REQ_EVENT = 0x03U,
    I2C_SLAVE_STOP_EVENT = 0X04U,
}i2cSlaveEventType;

typedef enum
{
    I2C_SLAVE =  0,             /*!< The I2C module is in slave mode >*/
    I2C_MASTER = 1,             /*!< The I2C module is in master mode >*/
}i2c_module_type;
typedef enum
{
    I2C_MASTER_END_TRANSFER_EVENT                     = 0x4U,
}i2cMasterEventType;

typedef void (*i2c_slave_callback_t)(i2cSlaveEventType event, void *userData);

typedef void (*i2c_master_callback_t)(i2cMasterEventType event, void *userData);

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

typedef enum
{
    I2C_USING_DMA         = 0,
    I2C_USING_INTERRUPTS  = 1,
}  i2cTransferType;

typedef struct
{
    VAR(uint8, AUTOMATIC)                                       instance;
    VAR(uint32, AUTOMATIC)                                      i2cClock;
    VAR(uint8, AUTOMATIC)                                       slaveAddress;
    VAR(uint32, AUTOMATIC)                                      baudRate;
    VAR(boolean, AUTOMATIC)                                     slaveListening;
    VAR(i2c_slave_callback_t, AUTOMATIC)                        slaveCallback;
    P2VAR(void, AUTOMATIC, I2C_APPL_DATA)                       callbackParam;
    VAR(uint8, AUTOMATIC)                                       I2cPortPin;
    VAR(uint8, AUTOMATIC)                                       I2cPortPinMode;
} i2cSlaveConfigType;

typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    VAR(status_t, AUTOMATIC)                                    status;                   /* The I2C slave status */
    volatile VAR(boolean, AUTOMATIC)                            isTransferInProgress;     /* Slave is busy because of an ongoing transfer */
    VAR(uint32, AUTOMATIC)                                      txSize;                   /* Size of the TX buffer */
    VAR(uint32, AUTOMATIC)                                      rxSize;                   /* Size of the RX buffer */
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST)                   txBuff;                   /* Pointer to Tx Buffer */
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA)                      rxBuff;                   /* Pointer to Rx Buffer */
    VAR(uint8, AUTOMATIC)                                       slaveAddress;             /* Slave address */
    VAR(boolean, AUTOMATIC)                                     slaveListening;           /* Slave mode (always listening or on demand only) */
    VAR(boolean, AUTOMATIC)                                     txUnderrunWarning;        /* Possible slave tx underrun */
    VAR(boolean, AUTOMATIC)                                     dataAck;                  /* Data acknowledge enable or disable*/
    VAR(boolean, AUTOMATIC)                                     blocking;                 /* Specifies if the current transfer is blocking */
    volatile VAR(uint8, AUTOMATIC)                              nonblockingflag;
    VAR(i2c_slave_callback_t, AUTOMATIC)                        slaveCallback;            /* Slave callback function */
    P2VAR(void, AUTOMATIC, I2C_APPL_DATA)                       callbackParam;            /* Parameter for the slave callback function */
    VAR(uint32, AUTOMATIC)                                      i2cClock;
    VAR(uint8, AUTOMATIC)                                       I2cPortPin; 
    VAR(uint8, AUTOMATIC)                                       I2cPortPinMode;
/*! @endcond */
} i2cSlaveStateType;

typedef struct
{
    VAR(uint8, AUTOMATIC)                                       instance;
    VAR(uint32, AUTOMATIC)                                      i2cClock;
    VAR(uint8, AUTOMATIC)                                       slaveAddress;             /*!< Slave address, 7-bit */
    VAR(uint32, AUTOMATIC)                                      baudRate;                 /*!< The baud rate in hertz to use with current slave device */
    VAR(i2cTransferType, AUTOMATIC)                             transferType;             /*!< Type of I2C transfer */
#if (CDD_I2C_DMA_USED == STD_ON)
    VAR(uint8, AUTOMATIC)                                       dmaChannel;               /*!< Channel number for DMA channel. If DMA mode isn't used this field will be ignored */
#endif
    VAR(i2c_master_callback_t, AUTOMATIC)                       masterCallback;           /*!< Master callback function. Note that this function will be
                                                                                        called from the interrupt service routine at the end of a transfer,
                                                                                        so its execution time should be as small as possible. It can be
                                                                                        NULL if you want to check manually the status of the transfer. */
    P2VAR(void, AUTOMATIC, I2C_APPL_DATA)                       callbackParam;            /*!< Parameter for the master callback function */
    VAR(uint8, AUTOMATIC)                                       I2cPortPin; 
    VAR(uint8, AUTOMATIC)                                       I2cPortPinMode;
} i2cMasterConfigType;

typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */

    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA)                      rxBuff;                   /* Pointer to receive data buffer */
    VAR(uint32, AUTOMATIC)                                      rxSize;                   /* Size of receive data buffer */
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST)                   txBuff;                   /* Pointer to transmit data buffer */
    VAR(uint32, AUTOMATIC)                                      txSize;                   /* Size of transmit data buffer */
    volatile VAR(status_t, AUTOMATIC)                           status;                   /* Status of last driver operation */
    VAR(uint8, AUTOMATIC)                                       slaveAddress;             /* Slave address */
    volatile VAR(boolean, AUTOMATIC)                            i2cIdle;                  /* Idle/busy state of the driver */
    VAR(boolean, AUTOMATIC)                                     sendStop;                 /* Specifies if STOP condition must be generated after current transfer */
    VAR(boolean, AUTOMATIC)                                     blocking;                 /* Specifies if the current transfer is blocking */
    VAR(i2cTransferType, AUTOMATIC)                             transferType;             /* Type of I2C transfer */
#if (CDD_I2C_DMA_USED == STD_ON)
    VAR(uint8, AUTOMATIC)                                       dmaChannel;               /* Channel number for DMA rx channel */
#endif
    VAR(boolean, AUTOMATIC)                                     sendData;                 /* Master is in transmitting or receive mode*/
    VAR(boolean, AUTOMATIC)                                     stopGenerated;            /* Specifies if stop was generated for the previous transfer */
    volatile VAR(uint8, AUTOMATIC)                              nonblockingflag;
    VAR(i2c_master_callback_t, AUTOMATIC)                       masterCallback;           /* Master callback function */
    P2VAR(void, AUTOMATIC, I2C_APPL_DATA)                       callbackParam;            /* Parameter for the master callback function */
    VAR(uint32, AUTOMATIC)                                      i2cClock;
    VAR(uint8, AUTOMATIC)                                       I2cPortPin; 
    VAR(uint8, AUTOMATIC)                                       I2cPortPinMode; 
/*! @endcond */
} i2cMasterStateType;

/*******************************************************************************
 * API
 ******************************************************************************/
#if (CDD_I2C_MASTER_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_Master_Init \
( \
    P2CONST(i2cMasterConfigType, AUTOMATIC, I2C_APPL_CONST) userConfigPtr \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Transmit \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8 ,AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize, \
    VAR(boolean, AUTOMATIC) sendStop \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Transmit_WaitDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8 ,AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize, \
    VAR(boolean, AUTOMATIC) sendStop, \
    VAR(uint32, AUTOMATIC) timeout \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_AbortTransmit(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Receive \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize, \
    VAR(boolean, AUTOMATIC) sendStop \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE)I2C_LLD_Master_FreeBus(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE)I2C_LLD_Slave_FreeBus(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Receive_WaitDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize, \
    VAR(boolean, AUTOMATIC) sendStop, \
    VAR(uint32, AUTOMATIC) timeout \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Deinit(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_GetStatus(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_SetBaudRate \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) baudRate \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_SetBaudRate \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) baudRate \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(uint32, I2C_CODE) I2C_LLD_Master_GetBaudRate(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_SLAVE_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_Slave_Init \
( \
    P2CONST(i2cSlaveConfigType, AUTOMATIC, I2C_APPL_CONST) userConfigPtr \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Transmit \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Transmit_WaitDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize, \
    VAR(uint32, AUTOMATIC) timeout \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Receive \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Receive_WaitDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize, \
    VAR(uint32, AUTOMATIC) timeout \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_AbortTransmit(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_InstallRxBuffer \
( \
    VAR(uint8, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_InstallTxBuffer \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_GetStatus(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Deinit(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

extern void I2C_callback_test(void);
/** I2C - Register Layout Typedef */
/*! @brief I2C module types
 * Implements : i2c_module_type_Class
 */

/*******************************************************************************
 * Interrupt handler signature for I2C module
 ******************************************************************************/
extern void I2C_LLD_ModuleIRQHandler(VAR(uint8, AUTOMATIC) instance);

#if (CDD_I2C_PRECOMPILE_SUPPORT == STD_OFF)

    #if (CDD_I2C_MASTER_CONTROLLER_COUNT > 0)
CDD_I2C_PB_MASTER_CONFIG_DECLARATION
    #endif

    #if (CDD_I2C_SLAVE_CONTROLLER_COUNT > 0)
CDD_I2C_PB_SLAVE_CONFIG_DECLARATION
    #endif

#else

    #if (CDD_I2C_MASTER_CONTROLLER_COUNT > 0)
extern CONST(i2cMasterConfigType, I2C_CONST) I2C_Master_Config[CDD_I2C_MASTER_CONTROLLER_COUNT];
    #endif

    #if (CDD_I2C_SLAVE_CONTROLLER_COUNT > 0)
extern CONST(i2cSlaveConfigType, I2C_CONST) I2C_Slave_Config[CDD_I2C_SLAVE_CONTROLLER_COUNT];
    #endif

#endif

#endif /* RESOURCE_SUPPORT_I2C */

#ifdef __cplusplus
}
#endif

#endif
