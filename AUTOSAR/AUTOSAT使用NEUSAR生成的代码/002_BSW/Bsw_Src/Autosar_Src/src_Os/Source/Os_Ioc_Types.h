/*
********************************************************************************
*
*  File name: Os_Ioc_Types.h
*
*  Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: HanCL/2021.11.25
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: LiG/2023.1.28
* Change: Add IOC type to full type.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: LiG/2024.1.5
* Change: Added IocCallback functional related structures.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: LiG/2024.4.10
* Change: Modifying static code check issues.
* Cause: Optimization
********************************************************************************
*/
#ifndef OS_IOC_TYPES_H_
#define OS_IOC_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Os_Types_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define IOC_INIT                     (0)    /* The ioc initial zero value. */
#define IOC_INIT_U                   (0U)   /* The ioc initial zero value. */
#define IOC_E_OK                     (0U)   /* No error. */
#define IOC_E_NOK                    (1U)   /* The ioc parameter error or permission error. */
#define IOC_E_LOST_DATA              (64U)  /* The ioc buffer is overflow, receive successful. */
#define IOC_E_LIMIT                  (130U) /* The ioc buffer is overflow. */
#define IOC_E_NO_DATA                (131U) /* The ioc buffer is empty. send unsuccessful. */
#define IOC_STATE_OK                 (0U)   /* The ioc lost flag. */
#define IOC_STATE_LOST               (1U)
/* The IOC data type. */
#define IOC_DATATYPE_BL              (0U)
#define IOC_DATATYPE_U8              (1U)
#define IOC_DATATYPE_U16             (2U)
#define IOC_DATATYPE_U32             (3U)
#define IOC_DATATYPE_U64             (4U)
#define IOC_DATATYPE_S8              (5U)
#define IOC_DATATYPE_S16             (6U)
#define IOC_DATATYPE_S32             (7U)
#define IOC_DATATYPE_S64             (8U)
#define IOC_DATATYPE_FL              (9U)
#define IOC_DATATYPE_DB              (10U)
#define IOC_DATATYPE_PTR             (11U)
/* The IOC lock type. */
#define IOC_LOCKTYPE_NONE            (0U)
#define IOC_LOCKTYPE_INT             (1U)
#define IOC_LOCKTYPE_INT_SPINLOCK    (2U)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef void (*ReceiverPullCB)(void);
typedef void (*IocQueueInit)(void);

typedef struct
{
    /* The state of the IOC. */
    uint8 iocState;
}Os_IocDynType;

typedef struct
{
    uint8 dataType;
    uint32 dataSize;
    /*The buffer address for storing IOC data. */
    void* buffer;
}Os_IocDataType;

typedef struct
{
    /* The core id. */
    CoreIdType coreId;
    /* The callback function. */
    ReceiverPullCB callBack;
} Os_IocRxCBType;

typedef struct
{
    /* Reference to applications which access this object. */
    uint32 accessingApps;
    /* The callback function. */
    Os_IocRxCBType IocRxCB;
} Os_IocTxCfgType;

typedef struct
{
    /* Reference to applications which access this object. */
    uint32 accessingApps;
} Os_IocRxCfgType;

typedef struct
{
    /* The IOC data type. */
    const Os_IocDataType* dataType;
    /* The IOC data type counter. */
    uint8 dataTypeCnt;
    /* The IOC lock type. */
    uint8 lockType;
    /* The spinlock id. */
    SpinlockIdType spinlockId;
    /* The internal queue size. */
    uint32 bufferLength;
    /* The sender configuration. */
    const Os_IocTxCfgType* iocTxCfg;
    /* The sender counter. */
    uint32 senderCnt;
    /* The receiver configuration. */
    const Os_IocRxCfgType* iocRxCfg;
    /* The running data of the IOC. */
    Os_IocDynType* iocDyn;
    /* The IOC queue queue initialization function. */
    IocQueueInit func;
} Os_IocCfgType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* OS_IOC_TYPES_H_ */
