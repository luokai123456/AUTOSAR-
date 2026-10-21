/*
************************************************************************************************************************
*
* File name: Rte_NvM_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date : WangJP/2021.11.11
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 3.1
* Author/Date : LiDY/2023.03.08
* Change: Add Variable about NvM.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_NVM_TYPE_H_
#define RTE_NVM_TYPE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
/* Identification of a NVRAM block via a unique block identifier. */
#ifndef Rte_TypeDef_NvM_BlockIdType
#define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;
#endif

/* The type NvM_RequestResultType is an asynchronous request result, which will
be returned by the API service NvM_GetErrorStatus*/
#ifndef Rte_TypeDef_NvM_RequestResultType
#define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;
#endif

/* Configuration data structure of the NvM module. */
#ifndef Rte_TypeDef_NvM_ConfigType
#define Rte_TypeDef_NvM_ConfigType
typedef struct
{
    uint8 reserve;
} NvM_ConfigType;
#endif


/* The last asynchronous request has been finished successfully. */
#define NVM_REQ_OK                      (0x00U)
/* The last asynchronous read/write/control request has been finished unsuccessfully. */
#define NVM_REQ_NOT_OK                  (0x01U)
/* An asynchronous request is currently being processed */
#define NVM_REQ_PENDING                 (0x02U)
/* The result of the last asynchronous request NvM_ReadBlock or NvM_ReadAll is a data integrity failure. */
#define NVM_REQ_INTEGRITY_FAILED        (0x03U)
/* The referenced block was skipped during execution of NvM_ReadAll or NvM_WriteAll */
#define NVM_REQ_BLOCK_SKIPPED           (0x04U)
/* The referenced NV block is invalidated. */
#define NVM_REQ_NV_INVALIDATED          (0x05U)
/* The multi block request NvM_WriteAll was canceled */
#define NVM_REQ_CANCELED                (0x06U)
/* The required redundancy of the referenced NV block is lost */
#define NVM_REQ_REDUNDANCY_FAILED       (0x07U)
/* The referenced NV block had the default values copied to the RAM image. */
#define NVM_REQ_RESTORED_FROM_ROM       (0x08U)
/*
************************************************************************************************************************
*    Global Variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Constants
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Functions
************************************************************************************************************************
*/

#endif /* RTE_H_ */

