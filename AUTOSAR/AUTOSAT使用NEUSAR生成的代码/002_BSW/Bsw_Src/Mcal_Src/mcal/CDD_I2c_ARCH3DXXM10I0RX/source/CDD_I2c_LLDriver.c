/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : I2C
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/
/**
*   @file    CDD_I2c_LLDriver.c
*   @version
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of I2c MCAL driver.
*
*   @addtogroup I2c
*   @{
*/
/* PRQA S 1503,1505,3469,4404,0380,3673,3119,3432,2985,2844,0491,0498,0488,1258,1259,2834,0492,0313,2934,0751,2913 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "CDD_I2c_LLDriver.h"
#include "Port_Cfg.h"
#include "Dio.h"
#include "Port.h"
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

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define I2C_LLD_DUMMY_BYTE    (0xFFU)

#if (CDD_I2C_DMA_USED == STD_ON)
typedef enum {
    I2C_TX_REQ = 0, /*!< The driver will perform an I2C transmit transfer */
    I2C_RX_REQ = 1, /*!< The driver will perform an I2C receive transfer */
} i2c_transfer_direction_t;

typedef struct {
    /*! @cond DRIVER_INTERNAL_USE_ONLY */
    VAR(uint8, AUTOMATIC)                           dmaChannel;             /* Number of DMA channel */
    VAR(eDMATransferType, AUTOMATIC)                dmaTransferType;        /* DMA type transfer */
    VAR(uint32, AUTOMATIC)                          i2cDataRegAddr;         /* I2C data register address */
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA)          bufferTransfer;         /* Buffer used for transfer */
    VAR(uint32, AUTOMATIC)                          transferSize;           /* Buffer data size */
    VAR(i2c_transfer_direction_t, AUTOMATIC)        transferDirection;      /* DMA transfer direction: receive or transmit */
/*! @endcond */
} i2c_dma_transfer_params_t;
#endif

#define CDD_I2C_START_SEC_CONFIG_DATA
#include "CDD_I2c_MemMap.h"
static CONSTP2VAR(I2C_Type, AUTOMATIC, I2C_APPL_CONST) i2c_Global_BaseAddr[I2C_INSTANCE_COUNT] = I2C_BASE_PTRS;
#define CDD_I2C_STOP_SEC_CONFIG_DATA
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_VAR_SHARED_NO_INIT
#include "CDD_I2c_MemMap.h"
static VAR(i2cMasterStateType, AUTOMATIC) i2c_Global_MasterState[I2C_INSTANCE_COUNT];
#define CDD_I2C_STOP_SEC_VAR_SHARED_NO_INIT
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_VAR_SHARED_NO_INIT
#include "CDD_I2c_MemMap.h"
static VAR(i2cSlaveStateType, AUTOMATIC) i2c_Global_SlaveState[I2C_INSTANCE_COUNT];
#define CDD_I2C_STOP_SEC_VAR_SHARED_NO_INIT
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_DMA_USED == STD_ON)
#define CDD_I2C_START_SEC_CONFIG_DATA
#include "CDD_I2c_MemMap.h"
static CONST(eDMARequestSourceType, I2C_CONST) i2c_Global_DMASrc[I2C_INSTANCE_COUNT][2U] = I2C_DMA_REQ;/*PRQA S 3218*/
#define CDD_I2C_STOP_SEC_CONFIG_DATA
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CONFIG_DATA
#include "CDD_I2c_MemMap.h"
static CONST(uint32, I2C_CONST) i2c_Global_Dividers[MAX_I2C_SCL_DIVIDERS][2] = I2C_SCL_DIVIDER;
#define CDD_I2C_STOP_SEC_CONFIG_DATA
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_DMA_USED == STD_ON)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE) I2C_LLD_Master_StartDma(VAR(uint32, AUTOMATIC) instance);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(status_t, I2C_CODE) I2C_LLD_Master_WaitTransferDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) timeout \
);
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

/************************************************************************
 *    Functional declarations
 ************************************************************************/
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_ModuleEnable \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_MDIS_MASK));
    regValue |= I2C_IBCR_MDIS(!enable);/* PRQA S 4558, 4304, 4116 */
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_BusIRQEnable \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_IBIE_MASK));
    regValue |= I2C_IBCR_IBIE(enable);
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_ModuleModSelect
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(i2c_module_type, AUTOMATIC) moduleType
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_MSSL_MASK));
    regValue |= I2C_IBCR_MSSL(moduleType);
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_ModuleModSelect(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBCR_MSSL_MASK) >> I2C_IBCR_MSSL_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_ModuleTransmitMode \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_TXRX_MASK));
    regValue |= I2C_IBCR_TXRX(enable);
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_ModuleTransmitMode(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBCR_TXRX_MASK) >> I2C_IBCR_TXRX_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_DataAcknowledge \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_NOACK_MASK));
    regValue |= I2C_IBCR_NOACK(!enable); /*PRQA S 4558,4304,4825,4116*/
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_DMA_USED == STD_ON)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_DMAEnable \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_DMAEN_MASK));
    regValue |= I2C_IBCR_DMAEN(enable);
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_RepeatStart \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBCR; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBCR_RSTA_MASK));
    regValue |= I2C_IBCR_RSTA(enable);
    baseAddr->IBCR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_AddressAsSlave(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBSR_IAAS_MASK) >> I2C_IBSR_IAAS_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_BusBusyEvent(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBSR_IBB_MASK) >> I2C_IBSR_IBB_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_MasterArbitrationLostEvent(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBSR_IBAL_MASK) >> I2C_IBSR_IBAL_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Clear_MasterArbitrationLostFlag(P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr)
{
    VAR(boolean, AUTOMATIC) enable = TRUE;
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue &= (uint8)((uint8)(~(I2C_IBSR_IBAL_MASK)) & ((uint8)(~(I2C_IBSR_IBIF_MASK))));/*PRQA S 2905*/
    regValue |= I2C_IBSR_IBAL(enable);
    baseAddr->IBSR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_SlaveTransmitMode(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBSR_SRW_MASK) >> I2C_IBSR_SRW_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_ReceivedACK(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBSR_RXAK_MASK) >> I2C_IBSR_RXAK_SHIFT;/*PRQA S 2985*/
    return !(regValue);/*PRQA S 4558,4116*/
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Clear_BusInterruptFlag \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBSR; /* polyspace RTE:NIV */
#if (!defined(NO_ARBITRATION_LOST_DETECTION_FEATURE))
    regValue &= (uint8)((uint8)(~(I2C_IBSR_IBIF_MASK)) & ((uint8)(~(I2C_IBSR_IBAL_MASK))));/*PRQA S 2905*/
#else
    regValue &= (uint8)(~(I2C_IBSR_IBIF_MASK));
#endif
    regValue |= I2C_IBSR_IBIF(enable);
    baseAddr->IBSR = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_DataIBDR(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = baseAddr->IBDR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBDR_DATA_MASK) >> I2C_IBDR_DATA_SHIFT;/*PRQA S 2985*/
    return (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(uint8, I2C_CODE) I2C_Get_TCF(P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr)
{
    VAR(uint8, AUTOMATIC) regValue = baseAddr->IBSR; /* polyspace RTE:NIV */
    regValue = (regValue & I2C_IBSR_TCF_MASK) >> I2C_IBSR_TCF_SHIFT;
    return regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_DataIBDR \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(uint8, AUTOMATIC) data \
)
{
    baseAddr->IBDR = (uint8) data;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
/*IBIC Interrupt config register*/
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_BusIdleIRQ \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(boolean, AUTOMATIC) enable \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBIC; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBIC_BIIE_MASK));
    regValue |= I2C_IBIC_BIIE(enable);/*PRQA S 2985*/
    baseAddr->IBIC = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_SLAVE_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_Set_SlaveAddress \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    VAR(uint8, AUTOMATIC) data \
)
{
    VAR(uint8, AUTOMATIC) regValue = (uint8) baseAddr->IBAD; /* polyspace RTE:NIV */
    regValue &= (uint8) (~(I2C_IBAD_ADR_MASK));
    regValue |= I2C_IBAD_ADR(data);/*PRQA S 2985*/
    baseAddr->IBAD = (uint8) regValue;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
CDD_I2C_INLINE FUNC(void, I2C_CODE) I2C_ResetModuleState(P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr)
{
    /* Reset the I2C Bus Control Register values */
    baseAddr->IBCR = 0x80;

    /* Reset the I2C Bus Interrupt Configuration Register */
    baseAddr->IBIC = 0x00;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(status_t, I2C_CODE) I2C_LLD_Master_SendAddr(VAR(uint32, AUTOMATIC) instance)
{
    VAR(uint8, AUTOMATIC) address;
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];
    master = &i2c_Global_MasterState[instance];

    /* Select master mode , generating a START signal */
    I2C_Set_ModuleModSelect(baseAddr, I2C_MASTER);

    /* Select transmit mode for master */
    I2C_Set_ModuleTransmitMode(baseAddr, TRUE);

    /* Transmit address */
    address = (uint8)(((uint8)((master->slaveAddress << 1U)) + (uint8) (!master->sendData)));/*PRQA S 4304,4116,4558*/  /* polyspace RTE:IDP */
    I2C_Set_DataIBDR(baseAddr, address);

    /* In case master want to receive one byte set NACK */
    if((master->sendData == 0U) && (master->rxSize == 1U))
    {
        /* Send NACK */
        I2C_Set_DataAcknowledge(baseAddr, FALSE);
    }

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_GenerateStop(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];
    master = &i2c_Global_MasterState[instance];

    if (I2C_Get_ModuleModSelect(baseAddr) == TRUE)
    {
        I2C_Set_ModuleModSelect(baseAddr, I2C_SLAVE);
        master->stopGenerated = TRUE; /* polyspace RTE:IDP */
    }

}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_InstallRxBuffer \
( \
    VAR(uint8, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize \
)
{
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(rxBuff != NULL_PTR);
    DEV_ASSERT(rxSize > 0U);

    slave = &i2c_Global_SlaveState[instance]; /* polyspace RTE:OBAI */

    slave->rxBuff = rxBuff; /* polyspace RTE:IDP */
    slave->rxSize = rxSize;

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_InstallTxBuffer \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize \
)
{
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(txBuff != NULL_PTR);
    DEV_ASSERT(txSize > 0U);

    slave = &i2c_Global_SlaveState[instance]; /* polyspace RTE:OBAI */

    slave->txBuff = txBuff; /* polyspace RTE:IDP */
    slave->txSize = txSize;

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Transmit \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8 ,AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize, \
    VAR(boolean, AUTOMATIC) sendStop \
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(txBuff != NULL_PTR);
    DEV_ASSERT(txSize > 0U);

    baseAddr = i2c_Global_BaseAddr[instance];
    master = &i2c_Global_MasterState[instance];

    /* Check if driver is busy */
    if(master->i2cIdle == 0U) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    if((master->stopGenerated) == TRUE)
    {
        /* Check if bus is busy */
        if(I2C_Get_BusBusyEvent(baseAddr) == TRUE)
        {
            return STATUS_I2C_BUS_BUSY;
        }
    }

    /* Copy parameters to drive state structure */
    master->txBuff = txBuff;
    master->txSize = txSize;
    master->i2cIdle = FALSE;
    master->status = STATUS_BUSY;
    master->sendData = TRUE;
    master->sendStop = sendStop;

    /* Clear I-Bus Interrupt */
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    /* Activate interrupts for DMA transfer*/
    I2C_Set_BusIRQEnable(baseAddr, TRUE);

    /* Activate interrupts for bus idle */
    I2C_Set_BusIdleIRQ(baseAddr, TRUE);

#if (CDD_I2C_DMA_USED == STD_ON)
    if (master->transferType == I2C_USING_DMA)
    {
        /* Start DMA transfer */
        I2C_LLD_Master_StartDma(instance);
    }
    else
#endif
    {
        (void)I2C_LLD_Master_SendAddr(instance);
    }

    return STATUS_SUCCESS;
}
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
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(rxBuff != NULL_PTR);
    DEV_ASSERT(rxSize > 0U);

    baseAddr = i2c_Global_BaseAddr[instance];
    master = &i2c_Global_MasterState[instance];

    /* Check if driver is busy */
    if(master->i2cIdle == 0U) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    if((master->stopGenerated) == TRUE)
    {
        /* Check if bus is busy */
        if(I2C_Get_BusBusyEvent(baseAddr) == TRUE)
        {
            return STATUS_I2C_BUS_BUSY;
        }
    }

    /* Copy parameters to driver state structure */
    master->rxSize = rxSize;
    master->i2cIdle = FALSE;
    master->rxBuff = rxBuff;
    master->status = STATUS_BUSY;
    master->sendData = FALSE;
    master->sendStop = sendStop;

    /* Clear I-Bus Interrupt */
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    /* Acknowledge enabled */
    I2C_Set_DataAcknowledge(baseAddr, TRUE);

    /* Enable interrupts */
    I2C_Set_BusIRQEnable(baseAddr, TRUE);

    /* Activate interrupts for bus idle*/
    I2C_Set_BusIdleIRQ(baseAddr, TRUE);

#if (CDD_I2C_DMA_USED == STD_ON)
    if (master->transferType == I2C_USING_DMA)
    {
        /* Start DMA transfer */
        I2C_LLD_Master_StartDma(instance);
    }
    else
#endif
    {
        (void)I2C_LLD_Master_SendAddr(instance);
    }

    return STATUS_SUCCESS;
}
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
)
{
    VAR(status_t, AUTOMATIC) retVal = STATUS_SUCCESS;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(txBuff != NULL_PTR);
    DEV_ASSERT(txSize > 0U);

    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master = &i2c_Global_MasterState[instance]; /* polyspace RTE:OBAI */

    /* Check if driver is busy */
    if(master->i2cIdle == 0U) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    /* mark transfer as blocking */
    master->blocking = TRUE;

    /* Dummy wait to ensure the semaphore is 0, no need to check result */
    master->nonblockingflag = FALSE;

    retVal = I2C_LLD_Master_Transmit(instance, txBuff, txSize, sendStop);

    if (retVal != STATUS_SUCCESS)
    {
        master->blocking = FALSE;
        return retVal;
    }

    /* Wait for transfer to end */
    return I2C_LLD_Master_WaitTransferDone(instance, timeout);
}
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
)
{
    VAR(status_t, AUTOMATIC) retVal = STATUS_SUCCESS;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(rxBuff != NULL_PTR);
    DEV_ASSERT(rxSize > 0U);

    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master = &i2c_Global_MasterState[instance]; /* polyspace RTE:OBAI */

    /* Check if driver is busy */
    if(master->i2cIdle == 0U) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    /* mark transfer as blocking */
    master->blocking = TRUE;

    /* Dummy wait to ensure the semaphore is 0, no need to check result */
    master->nonblockingflag = FALSE;

    retVal = I2C_LLD_Master_Receive(instance, rxBuff, rxSize, sendStop);
    if (retVal != STATUS_SUCCESS)
    {
        master->blocking = FALSE;
        return retVal;
    }

    /* Wait for transfer to end */
    return I2C_LLD_Master_WaitTransferDone(instance, timeout);
}
static FUNC(void, I2C_CODE)I2C_LLD_Master_TransmitSingleData \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master \
)
{
    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(baseAddr != NULL_PTR);
    DEV_ASSERT(master != NULL_PTR);
    (void)instance;
    if (master->txSize > 0U)
    {
        I2C_Set_DataIBDR(baseAddr, master->txBuff[0U]); /* polyspace RTE:IDP,NIV */

        master->txBuff++;
        master->txSize--;
    }
    else
    {
        master->status = STATUS_SUCCESS;
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_StopTransfer \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master \
)
{
    DEV_ASSERT(master != NULL_PTR);
    DEV_ASSERT(baseAddr != NULL_PTR);

    /* Disable all events */
    I2C_Set_BusIRQEnable(baseAddr, FALSE);
    I2C_Set_BusIdleIRQ(baseAddr, FALSE);

    master->txBuff = NULL_PTR; /* polyspace RTE:IDP */
    master->txSize = 0;
    master->rxBuff = NULL_PTR;
    master->rxSize = 0;
    master->i2cIdle = TRUE;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(status_t, I2C_CODE) I2C_LLD_Master_WaitTransferDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) timeout \
)
{
    VAR(status_t, AUTOMATIC) runState = STATUS_SUCCESS;
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;
    VAR(uint32, AUTOMATIC) tovalue = 0u;

    baseAddr = i2c_Global_BaseAddr[instance];
    master = &i2c_Global_MasterState[instance];

    tovalue = timeout;
    /* Wait for transfer to be completed by the IRQ */
    while (master->nonblockingflag == FALSE) /* polyspace RTE:IDP */
    {
        tovalue -= 1U;
        if((tovalue == 0u) || (tovalue > timeout))
        {
            runState = STATUS_TIMEOUT;
            break;
        }
    }

	/*special handle*/
    if((master->stopGenerated) == TRUE)
    {
            while (I2C_Get_BusBusyEvent(baseAddr) == TRUE)
            {
                    tovalue -= 1U;
                    if((tovalue == 0u) || (tovalue > timeout))
                    {
                            runState = STATUS_TIMEOUT;
                break;
                    }
            }
    }
    /****************/

    if (runState == STATUS_TIMEOUT)
    {
#if (CDD_I2C_DMA_USED == STD_ON)
        if(master->transferType == I2C_USING_DMA)
        {
            (void)EDMA_LLD_SetChannelRequest(master->dmaChannel);
            I2C_Set_DMAEnable(baseAddr, FALSE);
        }
        master->sendStop = TRUE;
#endif

        /* In case of timeout, abort will be done at byte boundary */
        if((I2C_Get_ModuleTransmitMode(baseAddr)) == TRUE)
        {
            master->txSize = 0U;
        }
        else
        {
            master->rxSize = 1U;
        }

        tovalue = timeout;
        /* Wait for interrupt to occur */
        while (master->nonblockingflag == FALSE)
        {
            tovalue -= 1U;
            if((tovalue == 0u) || (tovalue > timeout))
            {
                break;
            }
        }

        master->status = STATUS_TIMEOUT;

    }

    /* Blocking transfer is over */
    master->blocking = FALSE;
    return master->status;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_ReceiveSingleData \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr, \
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master \
)
{
    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(baseAddr != NULL_PTR);
    DEV_ASSERT(master != NULL_PTR);
    (void)instance;
    if (master->rxSize > 0U)
    {
        /* Receive data from slave and store it */
        master->rxBuff[0U] = I2C_Get_DataIBDR(baseAddr); /* polyspace RTE:IDP */

        master->rxBuff++;
        master->rxSize--;
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_StopTransfer \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave \
)
{
    DEV_ASSERT(slave != NULL_PTR);
    DEV_ASSERT(baseAddr != NULL_PTR);

    /* Deactivate events */
    I2C_Set_BusIRQEnable(baseAddr, FALSE);

    /* Disable I2C slave */
    I2C_Set_ModuleEnable(baseAddr, FALSE);

    slave->isTransferInProgress = FALSE;
    slave->rxBuff = NULL_PTR;
    slave->rxSize = 0U;
    slave->txBuff = NULL_PTR;
    slave->txSize = 0U;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static status_t I2C_LLD_Slave_WaitTransferDone \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) timeout \
)
{
    VAR(status_t, AUTOMATIC) runState = STATUS_SUCCESS;
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;
    VAR(uint32, AUTOMATIC) tovalue = 0u;

    baseAddr = i2c_Global_BaseAddr[instance];
    slave = &i2c_Global_SlaveState[instance];

    tovalue = timeout;
    /* Wait for transfer to be completed by the IRQ */
    while (slave->nonblockingflag == FALSE) /* polyspace RTE:IDP */
    {
        tovalue -= 1U;
        if((tovalue == 0u) || (tovalue > timeout))
        {
            runState = STATUS_TIMEOUT;
            break;
        }
    }

    if (runState == STATUS_TIMEOUT)
    {
        I2C_LLD_Slave_StopTransfer(baseAddr, slave);
        slave->status = STATUS_TIMEOUT;
    }

    /* Blocking transfer is over */
    slave->blocking = FALSE;
    return slave->status;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Receive \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(uint8, AUTOMATIC, I2C_APPL_DATA) rxBuff, \
    VAR(uint32, AUTOMATIC) rxSize \
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(rxBuff != NULL_PTR);
    DEV_ASSERT(rxSize > 0U);

    baseAddr = i2c_Global_BaseAddr[instance];
    slave = &i2c_Global_SlaveState[instance];

    /* Use this function only if the slave is not listening */
    DEV_ASSERT(slave->slaveListening == FALSE);

    /* Check if driver is busy */
    if((slave->isTransferInProgress) == TRUE) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    slave->rxBuff = rxBuff;
    slave->rxSize = rxSize;
    slave->status = STATUS_BUSY;

    slave->isTransferInProgress = TRUE;

    /* Clear I-Bus Interrupt */
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    /* Enable I2C Module*/
    I2C_Set_ModuleEnable(baseAddr, TRUE);

    /* Slave Mode */
    I2C_Set_ModuleModSelect(baseAddr, I2C_SLAVE);

    /*  Enable/Disable Acknowledge */
    I2C_Set_DataAcknowledge(baseAddr, slave->dataAck);

    /* Clear bus interrupt flag*/
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    /* Interrupt enabled*/
    I2C_Set_BusIRQEnable(baseAddr, TRUE);

    /* Enable bus idle interrupts */
    I2C_Set_BusIdleIRQ(baseAddr, TRUE);

    return STATUS_SUCCESS;
}
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
)
{
    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(rxBuff != NULL_PTR);
    DEV_ASSERT(rxSize > 0U);

    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave = &i2c_Global_SlaveState[instance]; /* polyspace RTE:OBAI */

    /* Check if driver is busy */
    if((slave->isTransferInProgress) == TRUE) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    /* mark transfer as blocking */
    slave->blocking = TRUE;

    /* Dummy wait to ensure the semaphore is 0, no need to check result */
    slave->nonblockingflag = FALSE;

    (void)I2C_LLD_Slave_Receive(instance, rxBuff, rxSize);

    /* Wait for transfer to end */
    return I2C_LLD_Slave_WaitTransferDone(instance, timeout);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Transmit \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(uint8, AUTOMATIC, I2C_APPL_CONST) txBuff, \
    VAR(uint32, AUTOMATIC) txSize \
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(txBuff != NULL_PTR);
    DEV_ASSERT(txSize > 0U);

    baseAddr = i2c_Global_BaseAddr[instance];
    slave = &i2c_Global_SlaveState[instance];

    /* If the slave is in listening mode the user should not use this function or the blocking counterpart. */
    DEV_ASSERT(slave->slaveListening == FALSE);

    /* Check if slave is busy */
    if((slave->isTransferInProgress) == TRUE) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    slave->txBuff = txBuff;
    slave->txSize = txSize;
    slave->status = STATUS_BUSY;

    /* Clear I-Bus Interrupt */
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    /* Interrupts enabled*/
    I2C_Set_BusIRQEnable(baseAddr, TRUE);

    /* Enable I2C Module*/
    I2C_Set_ModuleEnable(baseAddr, TRUE);

    /* Enable bus idle interrupts */
    I2C_Set_BusIdleIRQ(baseAddr, TRUE);

    /* Clear bus interrupt flag*/
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    slave->isTransferInProgress = TRUE;

    return STATUS_SUCCESS;
}
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
)
{
    VAR(status_t, AUTOMATIC) retVal = STATUS_SUCCESS;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(txBuff != NULL_PTR);
    DEV_ASSERT(txSize > 0U);

    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave = &i2c_Global_SlaveState[instance]; /* polyspace RTE:OBAI */

    /* Check if driver is busy */
    if((slave->isTransferInProgress) == TRUE) /* polyspace RTE:IDP */
    {
        return STATUS_BUSY;
    }

    /* mark transfer as blocking */
    slave->blocking = TRUE;

    /* Dummy wait to ensure the semaphore is 0, no need to check result */
    slave->nonblockingflag = FALSE;

    retVal = I2C_LLD_Slave_Transmit(instance, txBuff, txSize);
    if (retVal != STATUS_SUCCESS)
    {
        return retVal;
    }

    /* Wait for transfer to end */
    return I2C_LLD_Slave_WaitTransferDone(instance, timeout);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_StopEvent \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave, \
    VAR(status_t, AUTOMATIC) moduleStatus \
)
{
    DEV_ASSERT(baseAddr != NULL_PTR);
    DEV_ASSERT(slave != NULL_PTR);

    if (slave->slaveListening == 0U)
    {
        I2C_LLD_Slave_StopTransfer(baseAddr, slave);

        /* Signal transfer end for blocking transfers */
        if (slave->blocking == TRUE)
        {
            slave->nonblockingflag = TRUE;
        }
    }

    slave->status = moduleStatus;

    if (slave->slaveCallback != NULL_PTR) {
        slave->slaveCallback(I2C_SLAVE_STOP_EVENT, slave->callbackParam); /* polyspace RTE:COR */
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_TransmitSingleData \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave \
)
{
    DEV_ASSERT(baseAddr != NULL_PTR);
    DEV_ASSERT(slave != NULL_PTR);

    slave->status = STATUS_BUSY; /* polyspace RTE:IDP */

    if (slave->txSize == 0U)
    {
        /* Out of data, call callback to allow user to provide a new buffer */
        if (slave->slaveCallback != NULL_PTR)
        {
            slave->slaveCallback(I2C_SLAVE_TX_EMPTY_EVENT, slave->callbackParam); /* polyspace RTE:COR */
        }
    }

    if (slave->txSize > 0U)
    {
        /* Send data to master*/
        I2C_Set_DataIBDR(baseAddr, slave->txBuff[0U]); /* polyspace RTE:IDP,NIV */

        slave->txBuff++;
        slave->txSize--;
    }
    else
    {
        /* Slave end transfer */
        I2C_LLD_Slave_StopEvent(baseAddr, slave, STATUS_I2C_TX_UNDERRUN);

        /* Transmit dummy byte */
        I2C_Set_DataIBDR(baseAddr, I2C_LLD_DUMMY_BYTE);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_ReceiveSingleData \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave \
)
{
    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);
    DEV_ASSERT(baseAddr != NULL_PTR);
    DEV_ASSERT(slave != NULL_PTR);
    (void)instance;
    slave->status = STATUS_BUSY; /* polyspace RTE:IDP */

    if (slave->rxSize == 0U)
    {
        if (slave->slaveCallback != NULL_PTR)
        {
            slave->slaveCallback(I2C_SLAVE_RX_FULL_EVENT, slave->callbackParam); /* polyspace RTE:COR */
        }
    }

    if (slave->rxSize > 0U)
    {
        /* Read data from IBDR and store it */
        slave->rxBuff[0U] = I2C_Get_DataIBDR(baseAddr); /* polyspace RTE:IDP */
        slave->rxBuff++;
        slave->rxSize--;
    }
    else
    {
        /* Slave end transfer */
        I2C_LLD_Slave_StopEvent(baseAddr, slave, STATUS_I2C_RX_OVERRUN);

        /* Dummy read from IBDR */
        (void) I2C_Get_DataIBDR(baseAddr);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_AddrMatch \
( \
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr, \
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave \
)
{
    DEV_ASSERT(baseAddr != NULL_PTR);

    /* Check if slave is transmitting or receiving - check SRW bit */
    if ((I2C_Get_SlaveTransmitMode(baseAddr)) == TRUE)
    {
        /* Set TX Mode, Write data to IBCR to clear the IAAS bit! */
        I2C_Set_ModuleTransmitMode(baseAddr, TRUE);

        /* Request from master to transmit data */
        if ((slave->slaveCallback != NULL_PTR) && (slave->slaveListening == 1U)) /* polyspace RTE:IDP */
        {
            slave->slaveCallback(I2C_SLAVE_TX_REQ_EVENT, slave->callbackParam); /* polyspace RTE:COR */
        }

        I2C_LLD_Slave_TransmitSingleData(baseAddr, slave);
    }
    else
    {
        /* Request from master to receive data */
        if ((slave->slaveCallback != NULL_PTR) && (slave->slaveListening == 1U)) /* polyspace RTE:IDP */
        {
            slave->slaveCallback(I2C_SLAVE_RX_REQ_EVENT, slave->callbackParam); /* polyspace RTE:COR */
        }

        /* Set RX Mode */
        I2C_Set_ModuleTransmitMode(baseAddr, FALSE);

        /* Dummy reading */
        (void) I2C_Get_DataIBDR(baseAddr);
    }
    slave->status = STATUS_BUSY;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_DMA_USED == STD_ON)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_DMATransmitDone \
( \
    P2VAR(void, AUTOMATIC, I2C_APPL_DATA) parameter,
    VAR(eDMAChnStatusType, AUTOMATIC) status)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    VAR(uint32, AUTOMATIC) instance = (uint32) parameter;/*PRQA S 0326*/

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */

    master = &i2c_Global_MasterState[instance];

    if(status != EDMA_CHN_STATUS_NORMAL)
    {
        /* Generate stop signal */
        I2C_LLD_Master_GenerateStop((uint8)instance);

        I2C_LLD_Master_StopTransfer(baseAddr, master);

        /* Signal transfer end for blocking transfers */
        if (master->blocking == TRUE)
        {
            master->nonblockingflag = TRUE;
        }

        if (master->masterCallback != NULL_PTR)
        {
            master->masterCallback(I2C_MASTER_END_TRANSFER_EVENT, master->callbackParam); /* polyspace RTE:COR */
        }
    }
    else
    {
        if ((master->sendData) == TRUE) /* polyspace RTE:IDP */
        {
            master->txBuff += master->txSize - 1U;
            master->txSize = 1;
        }
        else
        {
            master->rxBuff += master->rxSize - 2U;
            master->rxSize = 2;
        }
    }

    if(status != EDMA_CHN_STATUS_NORMAL)
    {
        master->status = STATUS_ERROR;
    }
    else
    {
        master->status = STATUS_SUCCESS;
    }

    /* set I2C DMA disable */
    I2C_Set_DMAEnable(baseAddr, FALSE);

    /* Exiting DMA mode, slow reaction */
    /* Send/receive the next byte of data in case CPU interrupt is not triggered */
    if ((I2C_Get_TCF(baseAddr) == 1U) && (status == EDMA_CHN_STATUS_NORMAL))
    {
        if(master->sendData == TRUE)
        {
            /* Send the next byte of data */
            I2C_LLD_Master_TransmitSingleData(instance, baseAddr, master);
        }
        else
        {
            /* Receive the next byte of data */
            I2C_LLD_Master_ReceiveSingleData(instance, baseAddr, master);
        }
    }

}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#if (CDD_I2C_DMA_USED == STD_ON)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_ConfigDma \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(i2c_dma_transfer_params_t, AUTOMATIC, I2C_APPL_CONST) dmaTransParams)
{
    if (dmaTransParams->transferDirection == I2C_TX_REQ)
    {
        (void)EDMA_LLD_SetChannelSourceConfig(dmaTransParams->dmaChannel,  (uint32)i2c_Global_DMASrc[instance][I2C_TX_REQ], FALSE);
        (void)EDMA_LLD_SetMultiTransferConfig(dmaTransParams->dmaChannel, dmaTransParams->dmaTransferType, (uint32)dmaTransParams->bufferTransfer,
                                                (uint32)dmaTransParams->i2cDataRegAddr, EDMA_TRANSFER_SIZE_1B, (uint32)1U,
                                                (uint32)dmaTransParams->transferSize, FALSE);
    }
    else
    {
        (void)EDMA_LLD_SetChannelSourceConfig(dmaTransParams->dmaChannel,  (uint32)i2c_Global_DMASrc[instance][I2C_RX_REQ], FALSE);
        (void)EDMA_LLD_SetMultiTransferConfig(dmaTransParams->dmaChannel, dmaTransParams->dmaTransferType, (uint32)dmaTransParams->i2cDataRegAddr,
                                                (uint32)dmaTransParams->bufferTransfer, EDMA_TRANSFER_SIZE_1B, (uint32)1U,
                                                (uint32)dmaTransParams->transferSize, FALSE);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#if (CDD_I2C_DMA_USED == STD_ON)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE) I2C_LLD_Master_StartDma(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr = i2c_Global_BaseAddr[instance];
    P2CONST(i2cMasterStateType, AUTOMATIC, I2C_APPL_CONST) master = &i2c_Global_MasterState[instance];
    VAR(i2c_dma_transfer_params_t, AUTOMATIC) dmaTransParams;

    dmaTransParams.dmaChannel = master->dmaChannel; /* polyspace RTE:IDP */

    if ((master->sendData) == TRUE)
    {
        dmaTransParams.dmaTransferType = EDMA_TRANSFER_TYPE_MEMTOPERIPH;
        dmaTransParams.i2cDataRegAddr = (uint32) (&(baseAddr->IBDR));
        dmaTransParams.bufferTransfer = (uint8 *)(master->txBuff);/*PRQA S 0311*/
        dmaTransParams.transferDirection = I2C_TX_REQ;
        dmaTransParams.transferSize = master->txSize - 1U; /* In transmitting mode the DMA is not transferring the last byte of data */
    }
    else
    {
        dmaTransParams.dmaTransferType = EDMA_TRANSFER_TYPE_PERIPHTOMEM;
        dmaTransParams.i2cDataRegAddr = (uint32) (&(baseAddr->IBDR));
        dmaTransParams.bufferTransfer = (uint8 *)(master->rxBuff);
        dmaTransParams.transferDirection = I2C_RX_REQ;
        dmaTransParams.transferSize = master->rxSize - 2U; /* In receiving mode the DMA is not transferring the last two bytes */
    }

    (void) I2C_LLD_Master_ConfigDma(instance, &dmaTransParams);

    /* Disable DMA requests for channel when transfer is done */
    EDMA_LLD_SetChnDisReqOnTrfComp(dmaTransParams.dmaChannel, TRUE);

    /* Call callback function when all the bytes were transfered. */
    (void) EDMA_LLD_SetUpCallback(dmaTransParams.dmaChannel,(eDMACallbackType)(&I2C_LLD_Master_DMATransmitDone), (void*)(instance));/*PRQA S 0326*/

    /* Start channel */
    (void) EDMA_LLD_SetChannelRequest(dmaTransParams.dmaChannel);

    if (master->sendData == TRUE)
    {
        if(master->txSize != 1U)
        {
            /* Enable master DMA transmit */
            I2C_Set_DMAEnable(baseAddr, TRUE);
        }
    }

    (void)I2C_LLD_Master_SendAddr(instance);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_GetStatus(VAR(uint32, AUTOMATIC) instance)
{
    P2CONST(i2cMasterStateType, AUTOMATIC, I2C_APPL_CONST) master;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    master = &i2c_Global_MasterState[instance]; /* polyspace RTE:OBAI */

    return master->status; /* polyspace RTE:IDP */
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_GetStatus(VAR(uint32, AUTOMATIC) instance)
{
    P2CONST(i2cSlaveStateType, AUTOMATIC, I2C_APPL_CONST) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    slave = &i2c_Global_SlaveState[instance]; /* polyspace RTE:OBAI */

    return slave->status; /* polyspace RTE:IDP */
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_Deinit(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */

    cc_memset((uint8 *)&i2c_Global_MasterState[instance], 0U, sizeof(i2c_Global_MasterState));

    baseAddr->IBFD = 0U;

    /* Disable master */
    I2C_Set_ModuleEnable(baseAddr, FALSE);

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Deinit(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */

    cc_memset((uint8 *)&i2c_Global_SlaveState[instance], 0U, sizeof(i2c_Global_SlaveState));

    baseAddr->IBFD = 0U;

    /* Disable I2C slave */
    I2C_Set_ModuleEnable(baseAddr, FALSE);

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_AbortTransmit(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */
    master = &i2c_Global_MasterState[instance];

    /* Check if driver is busy */
    if(master->i2cIdle == TRUE) /* polyspace RTE:IDP */
    {
        return STATUS_SUCCESS;
    }

    /* End transfer: force stop generation */
    master->status = STATUS_I2C_ABORTED;

    I2C_LLD_Master_GenerateStop(instance);

    I2C_LLD_Master_StopTransfer(baseAddr, master);

    /* Software reset of the I2C module for stop generation */
    I2C_Set_ModuleEnable(baseAddr, FALSE);
    I2C_Set_ModuleEnable(baseAddr, TRUE);

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_AbortTransmit(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */
    slave = &i2c_Global_SlaveState[instance];

    /* Check if slave is busy */
    if(slave->isTransferInProgress == 0U) /* polyspace RTE:IDP */
    {
        return STATUS_SUCCESS;
    }

    if (slave->slaveListening == 0U)
    {
        I2C_LLD_Slave_StopTransfer(baseAddr, slave);

        /* Deactivate events */
        I2C_Set_BusIRQEnable(baseAddr, FALSE);
        I2C_Set_BusIdleIRQ(baseAddr, FALSE);

        slave->status = STATUS_I2C_ABORTED;
    }

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_CalculateDivider \
( \
    VAR(uint32, AUTOMATIC) divider, \
    P2VAR(uint32, AUTOMATIC, I2C_APPL_DATA) valReg)
{
    VAR(uint32, AUTOMATIC) difMin;
    VAR(uint32, AUTOMATIC) difMax;
    VAR(uint32, AUTOMATIC) u32I2c_Index;

    /* Find in table the value which match the divider */
    for (u32I2c_Index = 0; u32I2c_Index < (MAX_I2C_SCL_DIVIDERS - 2U); u32I2c_Index++)
    {
        if ((divider >= i2c_Global_Dividers[u32I2c_Index][1U]) && (divider < i2c_Global_Dividers[u32I2c_Index + 1U][1U]))
        {
            /* Check which value is closer to measured divider */
            difMin = (uint32) (divider - i2c_Global_Dividers[u32I2c_Index][1U]);
            difMax = (uint32) (i2c_Global_Dividers[u32I2c_Index + 1U][1U] - divider);

            if (difMin > difMax)
            {
                /* Divider is closer to the right value */
                *valReg = i2c_Global_Dividers[u32I2c_Index + 1U][0U];
            }
            else
            {
                /* Divider is closer to the left value */
                *valReg = i2c_Global_Dividers[u32I2c_Index][0U];
            }

            break;
        }
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Master_SetBaudRate \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) baudRate \
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    VAR(uint32, AUTOMATIC) divider;
    VAR(uint32, AUTOMATIC) valReg;
    VAR(uint32, AUTOMATIC) inputClock;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];
    master = &i2c_Global_MasterState[instance];
    inputClock = master->i2cClock; /* polyspace RTE:IDP */

    DEV_ASSERT(inputClock > 0U);
    DEV_ASSERT(baudRate > 0U);

    /* Calculate divider needed for the requested baudRate */
    divider = (uint32)((inputClock + (baudRate >> 1))/baudRate); /* polyspace RTE:ZDV */
    valReg = 1U;

    /* Divider takes the smallest value from the table if the calculated value is smaller than all dividers found in table */
    if (divider < i2c_Global_Dividers[0U][1U])
    {
        valReg = i2c_Global_Dividers[0U][0U];
    }
    else if (divider >= i2c_Global_Dividers[MAX_I2C_SCL_DIVIDERS - 1U][1U])
    {
        /* Divider takes biggest value from the table if the calculated value is bigger than all the dividers found in table */
        valReg = i2c_Global_Dividers[MAX_I2C_SCL_DIVIDERS - 1U][0U];
    }
    else
    {
        I2C_LLD_Master_CalculateDivider(divider, &valReg);
    }

    baseAddr->IBFD = (uint8)valReg;

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(status_t, I2C_CODE) I2C_LLD_Slave_SetBaudRate \
( \
    VAR(uint32, AUTOMATIC) instance, \
    VAR(uint32, AUTOMATIC) baudRate \
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    VAR(uint32, AUTOMATIC) divider;
    VAR(uint32, AUTOMATIC) valReg;
    VAR(uint32, AUTOMATIC) inputClock;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */
    slave = &i2c_Global_SlaveState[instance];
    inputClock = slave->i2cClock; /* polyspace RTE:IDP */

    DEV_ASSERT(inputClock > 0U);
    DEV_ASSERT(baudRate > 0U);

    /* Calculate divider needed for the requested baudRate */
    divider = (uint32)((inputClock + (baudRate >> 1))/baudRate); /* polyspace RTE:ZDV */
    valReg = 1U;

    /* Divider takes the smallest value from the table if the calculated value is smaller than all dividers found in table */
    if (divider < i2c_Global_Dividers[0U][1U])
    {
        valReg = i2c_Global_Dividers[0U][0U];
    }
    else if (divider >= i2c_Global_Dividers[MAX_I2C_SCL_DIVIDERS - 1U][1U])
    {
        /* Divider takes biggest value from the table if the calculated value is bigger than all the dividers found in table */
        valReg = i2c_Global_Dividers[MAX_I2C_SCL_DIVIDERS - 1U][0U];
    }
    else
    {
        I2C_LLD_Master_CalculateDivider(divider, &valReg);
    }

    baseAddr->IBFD = (uint8)valReg;

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(uint32, I2C_CODE) I2C_LLD_Master_GetBaudRate(VAR(uint32, AUTOMATIC) instance)
{
    P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr;
    VAR(uint8, AUTOMATIC) regDivider;
    VAR(uint32, AUTOMATIC) divider;
    VAR(uint32, AUTOMATIC) baudRate;
    VAR(uint32, AUTOMATIC) u32I2c_Index;
    VAR(uint32, AUTOMATIC) inputClock;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */
    master = &i2c_Global_MasterState[instance];
    inputClock = master->i2cClock; /* polyspace RTE:IDP */

    DEV_ASSERT(inputClock > 0U);

    regDivider = baseAddr->IBFD; /* polyspace RTE:NIV */
    divider = 1U;

    /* Check in the I2C dividers table the divider associated with the value of IBFD register */
    for(u32I2c_Index=0; u32I2c_Index<MAX_I2C_SCL_DIVIDERS; u32I2c_Index++)
    {
        if(i2c_Global_Dividers[u32I2c_Index][0U] == (uint32)regDivider)
        {
            divider = i2c_Global_Dividers[u32I2c_Index][1U];

            break;
        }
    }

    baudRate = (uint32)(inputClock/divider);

    return baudRate;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE)I2C_LLD_Master_FreeBus(VAR(uint32, AUTOMATIC) instance)
{
	VAR(uint8, AUTOMATIC) Loop;
	VAR(uint16, AUTOMATIC) ticks;
	P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;
	master = &i2c_Global_MasterState[instance];

	Port_SetPinMode(master->I2cPortPin,PORT_GPIO_MODE);

	for(Loop =0u;Loop<(uint8)I2C_FREEBUS_CLK_EDGES;Loop++)
	{
		(void)Dio_FlipChannel(master->I2cPortPin);
		for(ticks=0u;ticks<(uint8)I2C_FREEBUS_IDLE_TICKS;ticks++)
		{
			(void)0U;
		}
	}

	Port_SetPinMode(master->I2cPortPin,master->I2cPortPinMode);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE)I2C_LLD_Slave_FreeBus(VAR(uint32, AUTOMATIC) instance)
{
	VAR(uint8, AUTOMATIC) Loop;
	VAR(uint16, AUTOMATIC) ticks;
	P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;
	slave = &i2c_Global_SlaveState[instance];

	Port_SetPinMode(slave->I2cPortPin,PORT_GPIO_MODE);

	for(Loop =0u;Loop<(uint8)I2C_FREEBUS_CLK_EDGES;Loop++)
	{
		(void)Dio_FlipChannel(slave->I2cPortPin);
		for(ticks=0u;ticks<(uint8)I2C_FREEBUS_IDLE_TICKS;ticks++)
		{
			(void)0U;
		}
	}

	Port_SetPinMode(slave->I2cPortPin,slave->I2cPortPinMode);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_ArbitrationLostHandler(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* If the module is slave */
    master = &i2c_Global_MasterState[instance];
    I2C_LLD_Master_FreeBus(instance);

    /* Clear the master arbitration lost flag */
    I2C_Clear_MasterArbitrationLostFlag(baseAddr);

    master->status = STATUS_I2C_ARBITRATION_LOST; /* polyspace RTE:IDP */

    /* End transfer */
    I2C_LLD_Master_StopTransfer(baseAddr, master);

    master->stopGenerated = TRUE;

    if (master->masterCallback != NULL_PTR)
    {
        master->masterCallback(I2C_MASTER_END_TRANSFER_EVENT, master->callbackParam); /* polyspace RTE:COR */
    }

    /* Signal transfer end for blocking transfers */
    if (master->blocking == TRUE) {
        master->nonblockingflag = TRUE;
    }

#if (CDD_I2C_DMA_USED == STD_ON)
    if(master->transferType == I2C_USING_DMA)
    {
        I2C_Set_DMAEnable(baseAddr, FALSE);
    }
#endif
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_BusBusyEventHandler(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* If the module is slave */
    master = &i2c_Global_MasterState[instance];

    /* Report success if no error was recorded */
    if (master->status == STATUS_BUSY) /* polyspace RTE:IDP */
    {
        master->status = STATUS_SUCCESS;
    }

    I2C_LLD_Master_StopTransfer(baseAddr, master);

    if (master->masterCallback != NULL_PTR)
    {
        master->masterCallback(I2C_MASTER_END_TRANSFER_EVENT, master->callbackParam); /* polyspace RTE:COR */
    }

    /* Signal transfer end for blocking transfers */
    if (master->blocking == TRUE) {
        master->nonblockingflag = TRUE;
    }

}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_TransmitEvent(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* If the module is slave */
    slave = &i2c_Global_SlaveState[instance];

    /* Check the acknowledge from master */
    if (I2C_Get_ReceivedACK(baseAddr) == TRUE)
    {
        /* Transmit next byte to master */
        I2C_LLD_Slave_TransmitSingleData(baseAddr, slave);
    }
    else
    {
        /* Switch to RX mode and dummy read */
        I2C_Set_ModuleTransmitMode(baseAddr, FALSE);
        (void) I2C_Get_DataIBDR(baseAddr);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_CheckSwitchHandler(VAR(uint8, AUTOMATIC) instance)
{

    P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr;
    baseAddr = i2c_Global_BaseAddr[instance];

    if(I2C_Get_MasterArbitrationLostEvent(baseAddr) == TRUE)
    {
        I2C_LLD_Master_ArbitrationLostHandler(instance);
    }
    if (I2C_Get_BusBusyEvent(baseAddr) == 0U)
    {
        I2C_LLD_Master_BusBusyEventHandler(instance);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_ArbitrationLostHandler(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* If the module is slave */
    slave = &i2c_Global_SlaveState[instance];
    I2C_LLD_Slave_FreeBus(instance);
    /* Clear the arbitration lost flag */
    I2C_Clear_MasterArbitrationLostFlag(baseAddr);

    /* Check address as slave flag */
    if (I2C_Get_AddressAsSlave(baseAddr) == TRUE)
    {
        /* It was an address transfer */
        I2C_LLD_Slave_AddrMatch(baseAddr, slave);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_TransferHandler(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    baseAddr = i2c_Global_BaseAddr[instance];
    slave = &i2c_Global_SlaveState[instance];

    /* Module is transmitting or receiving */
    if (I2C_Get_ModuleTransmitMode(baseAddr) == TRUE)
    {
        I2C_LLD_Slave_TransmitEvent(instance);
    }
    else
    {
        if(I2C_Get_TCF(baseAddr) == TRUE)
        {
            /* Read data from IBDR and store it */
            I2C_LLD_Slave_ReceiveSingleData(instance, baseAddr, slave);
        }
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_TransferEvents(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* If the module is slave */
    slave = &i2c_Global_SlaveState[instance];

    /* Check if slave is addressed as slave */
    if (I2C_Get_AddressAsSlave(baseAddr) == TRUE)
    {
        /* It was an address transfer */
        I2C_LLD_Slave_AddrMatch(baseAddr, slave);
    }
    else if(I2C_Get_BusBusyEvent(baseAddr) == 0U)
    {
        /* Report success if no error was recorded */
        if(slave->status == STATUS_BUSY) /* polyspace RTE:IDP */
        {
            I2C_LLD_Slave_StopEvent(baseAddr, slave, STATUS_SUCCESS);
        }
    }
    else
    {
        I2C_LLD_Slave_TransferHandler(instance);
    }

}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Slave_IRQHandler(VAR(uint8, AUTOMATIC) instance)
{
    P2CONST(i2cMasterStateType, AUTOMATIC, I2C_APPL_CONST) master;
    P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* If the module is slave */
    master = &i2c_Global_MasterState[instance];

    if (master->i2cClock != 0U)
    {
        /* Master arbitration lost event */
        I2C_LLD_Slave_CheckSwitchHandler(instance);
    }
    else
    {
        /* Check arbitration lost event */
        if (I2C_Get_MasterArbitrationLostEvent(baseAddr) == TRUE)
        {
            I2C_LLD_Slave_ArbitrationLostHandler(instance);
        }
        else
        {
            /* No arbitration lost event */
            I2C_LLD_Slave_TransferEvents(instance);
        }
    }

    /* Cast to void to avoid compiler warnings */
    (void) baseAddr;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_MasterLastByteTransmitted(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];

    master = &i2c_Global_MasterState[instance];

    if (master->sendStop == TRUE) /* polyspace RTE:IDP */
    {
        /* Generate stop signal */
        I2C_LLD_Master_GenerateStop(instance);
    }
    else
    {
        /* Generate repeated start */
        I2C_Set_RepeatStart(baseAddr, TRUE);
        master->stopGenerated = FALSE;
        master->i2cIdle = TRUE;
    }

    /* No more data in buffer, end transmission */
    I2C_LLD_Master_StopTransfer(baseAddr, master);

    if (master->masterCallback != NULL_PTR) {
        master->masterCallback(I2C_MASTER_END_TRANSFER_EVENT, master->callbackParam); /* polyspace RTE:COR */
    }

    master->status = STATUS_SUCCESS;

    /* Signal transfer end for blocking transfers */
    if (master->blocking == TRUE)
    {
        master->nonblockingflag = TRUE;
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_ReceiveAck(VAR(uint32, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];

    master = &i2c_Global_MasterState[instance];

    /* End of address cycle? */
    if (master->sendData == TRUE) /* polyspace RTE:IDP */
    {
        /* Send the next byte of data */
        I2C_LLD_Master_TransmitSingleData(instance, baseAddr, master);
    }
    else
    {
        /* If is the end of address cycle and master is in RX mode */
        I2C_Set_ModuleTransmitMode(baseAddr, FALSE);

        /* Dummy read from IBDR */
        (void) I2C_Get_DataIBDR(baseAddr);

#if (CDD_I2C_DMA_USED == STD_ON)
        if (master->transferType == I2C_USING_DMA)
        {
        	if(master->rxSize > 2U)
        	{
                I2C_Set_DMAEnable(baseAddr, TRUE);
        	}
        }
#endif
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_GenerateStopEvent(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];

    master = &i2c_Global_MasterState[instance];

    /* Generate Stop Signal */
    I2C_LLD_Master_GenerateStop(instance);

    master->status = STATUS_I2C_RECEIVED_NACK; /* polyspace RTE:IDP */

     /* Master End Transfer */
    I2C_LLD_Master_StopTransfer(baseAddr, master);

    if (master->masterCallback != NULL_PTR)
    {
        master->masterCallback(I2C_MASTER_END_TRANSFER_EVENT, master->callbackParam); /* polyspace RTE:COR */
    }

    /* Signal transfer end for blocking transfers */
    if (master->blocking == TRUE)
    {
        master->nonblockingflag = TRUE;
    }

#if (CDD_I2C_DMA_USED == STD_ON)
    if(master->transferType == I2C_USING_DMA)
    {
        I2C_Set_DMAEnable(baseAddr, FALSE);
    }
#endif
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_TransmitHandler(VAR(uint8, AUTOMATIC) instance)
{
    P2CONST(i2cMasterStateType, AUTOMATIC, I2C_APPL_CONST) master;
    P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr;

    baseAddr = i2c_Global_BaseAddr[instance];

    /* Master Mode */

    master = &i2c_Global_MasterState[instance];

    if(I2C_Get_TCF(baseAddr) == TRUE)
    {
       /* Last byte transmitted ? */
        if ((master->txSize == 0U)&&(master->sendData == 1U)) /* polyspace RTE:IDP */
        {
            I2C_LLD_MasterLastByteTransmitted(instance);
        }
        else
        {
            /* Receive acknowledge */
            if (I2C_Get_ReceivedACK(baseAddr) == TRUE)
            {
                I2C_LLD_Master_ReceiveAck(instance);
            }
            else
            {
                I2C_LLD_Master_GenerateStopEvent(instance);
            }
        }
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_Master_ReceiveHandler(VAR(uint8, AUTOMATIC) instance)
{
    /* Master is in receive mode */

    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    baseAddr = i2c_Global_BaseAddr[instance];

    master = &i2c_Global_MasterState[instance];

    /* If last byte to be read */
    if (master->rxSize == 1U) /* polyspace RTE:IDP */
    {
        if (master->sendStop == TRUE)
        {
            /* Generate Stop Signal */
            I2C_LLD_Master_GenerateStop(instance);
        }
        else
        {
            /* Generate repeated start */
            I2C_Set_RepeatStart(baseAddr, TRUE);
            master->stopGenerated = FALSE;
            master->i2cIdle = TRUE;

            /* Signal transfer end for blocking transfers */
            if (master->blocking == TRUE)
            {
                master->nonblockingflag = TRUE;
            }

            master->status = STATUS_SUCCESS;
        }
    }
    else
    {
        /* If second last byte to be read */
        if (master->rxSize == 2U)
        {
            /* Set noAck = 1 */
            I2C_Set_DataAcknowledge(baseAddr, FALSE);
        }
    }
    /* Read data from IBDR and store */
    I2C_LLD_Master_ReceiveSingleData(instance, baseAddr, master);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE)I2C_LLD_MasterIRQHandler(VAR(uint8, AUTOMATIC) instance)
{
    P2CONST(I2C_Type, AUTOMATIC, I2C_APPL_CONST) baseAddr;
    baseAddr = i2c_Global_BaseAddr[instance];

    /* Check the mode - receive or transmit */
    if (I2C_Get_ModuleTransmitMode(baseAddr) == TRUE)
    {
        I2C_LLD_Master_TransmitHandler(instance);
    }
    else
    {
        I2C_LLD_Master_ReceiveHandler(instance);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_LLD_ModuleIRQHandler(VAR(uint8, AUTOMATIC) instance)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    baseAddr = i2c_Global_BaseAddr[instance];

    /* Clear I-Bus Interrupt */
    I2C_Clear_BusInterruptFlag(baseAddr, TRUE);

    /* Check if is master or slave module */
    if (I2C_Get_ModuleModSelect((const I2C_Type *)baseAddr) == FALSE)
    {
        I2C_LLD_Slave_IRQHandler(instance);
    }
    else
    {
        I2C_LLD_MasterIRQHandler(instance);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"

#if (CDD_I2C_MASTER_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(void, I2C_CODE) I2C_LLD_Master_Init \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(i2cMasterConfigType, AUTOMATIC, I2C_APPL_CONST) userConfigPtr
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cMasterStateType, AUTOMATIC, I2C_APPL_DATA) master;

    DEV_ASSERT(userConfigPtr != NULL_PTR);
    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */
    master = &i2c_Global_MasterState[instance];

    /*  Initialize driver status structure */
    master->rxBuff = NULL_PTR;
    master->rxSize = 0U;
    master->txBuff = NULL_PTR;
    master->txSize = 0U;
    master->status = STATUS_SUCCESS;
    master->i2cIdle = TRUE;
    master->slaveAddress = userConfigPtr->slaveAddress;
    master->transferType = userConfigPtr->transferType;
    master->stopGenerated = TRUE;

    /* Initialize callback and callback parameter*/
    master->masterCallback = userConfigPtr->masterCallback;
    master->callbackParam = userConfigPtr->callbackParam;
    master->I2cPortPin = userConfigPtr->I2cPortPin;
    master->I2cPortPinMode = userConfigPtr->I2cPortPinMode;
    /*  Store DMA channel number used in transfer */

#if (CDD_I2C_DMA_USED == STD_ON)
    master->dmaChannel = userConfigPtr->dmaChannel;
#endif
    master->blocking = FALSE;
    master->nonblockingflag = FALSE;
    master->i2cClock = userConfigPtr->i2cClock;

    /* Initial state */
    I2C_ResetModuleState(baseAddr);

    /* Set baud rate */
    (void)I2C_LLD_Master_SetBaudRate(instance, userConfigPtr->baudRate);

    /* Enable I2C Module*/
    I2C_Set_ModuleEnable(baseAddr, TRUE);
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#if (CDD_I2C_SLAVE_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
static FUNC(status_t, I2C_CODE) I2C_LLD_Slave_Init \
( \
    VAR(uint32, AUTOMATIC) instance, \
    P2CONST(i2cSlaveConfigType, AUTOMATIC, I2C_APPL_CONST) userConfigPtr
)
{
    P2VAR(I2C_Type, AUTOMATIC, I2C_APPL_DATA) baseAddr;
    P2VAR(i2cSlaveStateType, AUTOMATIC, I2C_APPL_DATA) slave;

    DEV_ASSERT(userConfigPtr != NULL_PTR);
    DEV_ASSERT((uint8)instance < (uint8)I2C_INSTANCE_COUNT);

    baseAddr = i2c_Global_BaseAddr[instance]; /* polyspace RTE:OBAI */
    slave = &i2c_Global_SlaveState[instance];

    /*  Initialize driver status structure */
    slave->status = STATUS_SUCCESS;
    slave->slaveListening = userConfigPtr->slaveListening;
    slave->slaveCallback = userConfigPtr->slaveCallback;
    slave->callbackParam = userConfigPtr->callbackParam;
    slave->txBuff = NULL_PTR;
    slave->rxBuff = NULL_PTR;
    slave->txSize = 0U;
    slave->rxSize = 0U;
    slave->slaveAddress = userConfigPtr->slaveAddress;
    slave->dataAck = TRUE;
    slave->isTransferInProgress = FALSE;
    slave->blocking = FALSE;
    slave->nonblockingflag = FALSE;
    slave->i2cClock = userConfigPtr->i2cClock;
    slave->I2cPortPin = userConfigPtr->I2cPortPin;
    slave->I2cPortPinMode = userConfigPtr->I2cPortPinMode;
    /* Initial state */
    I2C_ResetModuleState(baseAddr);

    /* Initialize the semaphore */
    /* Set baud rate */
    (void)I2C_LLD_Slave_SetBaudRate(instance, userConfigPtr->baudRate);

    /* Set Slave Address*/
    I2C_Set_SlaveAddress(baseAddr, slave->slaveAddress);

    if (slave->slaveListening == TRUE)
    {
        /* Interrupts enabled*/
        I2C_Set_BusIRQEnable(baseAddr, TRUE);

        /* Enable I2C Module*/
        I2C_Set_ModuleEnable(baseAddr, TRUE);

        /* Slave Mode */
        I2C_Set_ModuleModSelect(baseAddr, I2C_SLAVE);

        /* Enable Bus idle interrupt */
        I2C_Set_BusIdleIRQ(baseAddr, TRUE);

        /* Enable/Disable Acknowledge */
        I2C_Set_DataAcknowledge(baseAddr, TRUE);

        /* Clear bus interrupt flag*/
        I2C_Clear_BusInterruptFlag(baseAddr, TRUE);
    }

    return STATUS_SUCCESS;
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#if (CDD_I2C_MASTER_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_Master_Init \
( \
    P2CONST(i2cMasterConfigType, AUTOMATIC, I2C_APPL_CONST) userConfigPtr \
)
{
    VAR(uint8, AUTOMATIC) u8I2c_tempIdx = 0U;
    for (u8I2c_tempIdx = 0U; u8I2c_tempIdx < CDD_I2C_MASTER_CONTROLLER_COUNT; u8I2c_tempIdx++)
    {
        I2C_LLD_Master_Init(userConfigPtr[u8I2c_tempIdx].instance, &userConfigPtr[u8I2c_tempIdx]);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#if (CDD_I2C_SLAVE_CONTROLLER_COUNT > 0)
#define CDD_I2C_START_SEC_CODE
#include "CDD_I2c_MemMap.h"
FUNC(void, I2C_CODE) I2C_Slave_Init \
( \
    P2CONST(i2cSlaveConfigType, AUTOMATIC, I2C_APPL_CONST) userConfigPtr \
)
{
    VAR(uint8, AUTOMATIC) u8I2c_tempIdx = 0U;
    for (u8I2c_tempIdx = 0U; u8I2c_tempIdx < CDD_I2C_SLAVE_CONTROLLER_COUNT; u8I2c_tempIdx++)
    {
        I2C_LLD_Slave_Init(userConfigPtr[u8I2c_tempIdx].instance, &userConfigPtr[u8I2c_tempIdx]);
    }
}
#define CDD_I2C_STOP_SEC_CODE
#include "CDD_I2c_MemMap.h"
#endif

#endif /* RESOURCE_SUPPORT_I2C */

#ifdef __cplusplus
}
#endif
