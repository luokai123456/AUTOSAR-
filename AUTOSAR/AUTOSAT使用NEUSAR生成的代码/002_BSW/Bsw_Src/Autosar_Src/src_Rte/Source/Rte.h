/*
************************************************************************************************************************
*
* File name: Rte.h
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
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_H_
#define RTE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Std_Types.h"
#include "Platform_Types.h"

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
/* RTE Version */
#define RTE_VENDOR_ID                             (119U)
#define RTE_MODULE_ID                             (130U)
#define RTE_SW_MAJOR_VERSION                      (3U)
#define RTE_SW_MINOR_VERSION                      (13U)
#define RTE_SW_PATCH_VERSION                      (0U)
#define RTE_SW_REVISION_VERSION                   (2U)

/* AUTOSAR Version. */
#define RTE_AR_RELEASE_MAJOR_VERSION              (4U)
#define RTE_AR_RELEASE_MINOR_VERSION              (2U)
#define RTE_AR_RELEASE_REVISION_VERSION           (2U)

#if !defined (TYPEDEF) && defined (AUTOMATIC)
#define TYPEDEF AUTOMATIC
#endif

#if !defined (FUNC_P2CONST)
#define FUNC_P2CONST(rettype, ptrclass, memclass) FUNC(P2CONST(rettype, AUTOMATIC, ptrclass), memclass)
#endif

/* Common errors macro definition. */
#define RTE_E_OK                                  (0U)
#define RTE_E_INVALID                             (1U)

/* Overlayed errors macro definition. */
#define RTE_E_LOST_DATA                           (64U)
#define RTE_E_MAX_AGE_EXCEEDED                    (64U)

/* Immediate infrastructure errors macro definition. */
#define RTE_E_COM_STOPPED                         (128U)
#define RTE_E_TIMEOUT                             (129U)
#define RTE_E_LIMIT                               (130U)
#define RTE_E_NO_DATA                             (131U)
#define RTE_E_TRANSMIT_ACK                        (132U)
#define RTE_E_NEVER_RECEIVED                      (133U)
#define RTE_E_UNCONNECTED                         (134U)
#define RTE_E_IN_EXCLUSIVE_AREA                   (135U)
#define RTE_E_SEG_FAULT                           (136U)
#define RTE_E_OUT_OF_RANGE                        (137U)
#define RTE_E_SERIALIZATION_ERROR                 (138U)
#define RTE_E_HARD_TRANSFORMER_ERROR              (138U)
#define RTE_E_SERIALIZATION_LIMIT                 (139U)
#define RTE_E_TRANSFORMER_LIMIT                   (139U)
#define RTE_E_SOFT_TRANSFORMER_ERROR              (140U)
#define RTE_E_COM_BUSY                            (141U)

/* Common SchM errors macro definition. */
#define SCHM_E_OK                                 (0U)
#define SCHM_E_TIMEOUT                            (129U)
#define SCHM_E_LIMIT                              (130U)
#define SCHM_E_NO_DATA                            (131U)
#define SCHM_E_TRANSMIT_ACK                       (132U)
#define SCHM_E_IN_EXCLUSIVE_AREA                  (135U)

#define Rte_HasOverlayedError(status)             (((status) & 64U) != 0)
#define Rte_IsInfrastructureError(status)         (((status) & 128U) != 0)
#define Rte_IsHardTransformerError                Rte_IsInfrastructureError
#define Rte_ApplicationError(status)              ((status) & 63U)

/* Macros for reporting Det Errors. */
#define Rte_CheckDetErrorReturnVoid( CONDITION, API_ID, ERROR_CODE )            { if(!(CONDITION)) { (void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)); return; } }
#define Rte_CheckDetErrorReturnValue( CONDITION, API_ID, ERROR_CODE, RET_VAL )  { if(!(CONDITION)) { (void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)); return (RET_VAL); } }
#define Rte_CheckDetErrorContinue( CONDITION, API_ID, ERROR_CODE )              { if(!(CONDITION)) { (void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)); } }
#define Rte_CallDetReportError( API_ID, ERROR_CODE )                            ((void)Det_ReportError( RTE_MODULE_ID, 0, (API_ID), (ERROR_CODE)))

/* Service IDs of Rte APIs macro definition. */
#define SCHM_INIT_SERVICE_ID                      (0x00U)
#define SCHM_DEINIT_SERVICE_ID                    (0x01U)
#define SCHM_ENTER_SERVICE_ID                     (0x03U)
#define SCHM_EXIT_SERVICE_ID                      (0x04U)
#define RTE_SEND_SERVICE_ID                       (0x13U)
#define RTE_WRITE_SERVICE_ID                      (0x14U)
#define RTE_SWITCH_SERVICE_ID                     (0x15U)
#define RTE_INVALIDATE_SERVICE_ID                 (0x16U)
#define RTE_FEEDBACK_SERVICE_ID                   (0x17U)
#define RTE_SWITCHACK_SERVICE_ID                  (0x18U)
#define RTE_READ_SERVICE_ID                       (0x19U)
#define RTE_DREAD_SERVICE_ID                      (0x1AU)
#define RTE_RECEIVE_SERVICE_ID                    (0x1BU)
#define RTE_CALL_SERVICE_ID                       (0x1CU)
#define RTE_RESULT_SERVICE_ID                     (0x1DU)
#define RTE_CDATA_SERVICE_ID                      (0x1FU)
#define RTE_PRM_SERVICE_ID                        (0x20U)
#define RTE_IRVREAD_SERVICE_ID                    (0x28U)
#define RTE_IRVWRITE_SERVICE_ID                   (0x29U)
#define RTE_ENTER_SERVICE_ID                      (0x2AU)
#define RTE_EXIT_SERVICE_ID                       (0x2BU)
#define RTE_MODE_SERVICE_ID                       (0x2CU)
#define RTE_TRIGGER_SERVICE_ID                    (0x2DU)
#define RTE_ISUPDATED_SERVICE_ID                  (0x30U)
#define RTE_START_SERVICE_ID                      (0x70U)
#define RTE_STOP_SERVICE_ID                       (0x71U)
#define RTE_PARTITIONTERMINATED_SERVICE_ID        (0x72U)
#define RTE_PARTITIONRESTARTING_SERVICE_ID        (0x73U)
#define RTE_RESTARTPARTITION_SERVICE_ID           (0x74U)
#define RTE_INIT_SERVICE_ID                       (0x75U)
#define RTE_STARTTIMING_SERVICE_ID                (0x76U)
#define RTE_COMCBKTACK_SN_SERVICE_ID              (0x90U)
#define RTE_COMCBKTERR_SN_SERVICE_ID              (0x91U)
#define RTE_COMCBKINV_SN_SERVICE_ID               (0x92U)
#define RTE_COMCBKRXTOUT_SN_SERVICE_ID            (0x93U)
#define RTE_COMCBKTXTOUT_SN_SERVICE_ID            (0x94U)
#define RTE_COMCBK_SG_SERVICE_ID                  (0x95U)
#define RTE_COMCBKTACK_SG_SERVICE_ID              (0x96U)
#define RTE_COMCBKTERR_SG_SERVICE_ID              (0x97U)
#define RTE_COMCBKINV_SG_SERVICE_ID               (0x98U)
#define RTE_COMCBKRXTOUT_SG_SERVICE_ID            (0x99U)
#define RTE_COMCBKTXTOUT_SG_SERVICE_ID            (0x9AU)
#define RTE_SETMIRROR_SERVICE_ID                  (0x9BU)
#define RTE_GETMIRROR_SERVICE_ID                  (0x9CU)
#define RTE_NVMNOTIFYJOBFINISHED_SERVICE_ID       (0x9DU)
#define RTE_NVMNOTIFYINITBLOCK_SERVICE_ID         (0x9EU)
#define RTE_COMCBK_SN_SERVICE_ID                  (0x9FU)
#define RTE_LDCOMCBKRXINDICATION_SERVICE_ID       (0xA0U)
#define RTE_LDCOMCBKSTARTOFRECEPTION_SERVICE_ID   (0xA1U)
#define RTE_LDCOMCBKCOPYRXDATA_SERVICE_ID         (0xA2U)
#define RTE_LDCOMCBKTPRXINDICATION_SERVICE_ID     (0xA3U)
#define RTE_LDCOMCBKCOPYTXDATA_SERVICE_ID         (0xA4U)
#define RTE_LDCOMCBKTPTXCONFIRMATION_SERVICE_ID   (0xA5U)
#define RTE_LDCOMCBKTRIGGERTRANSMIT_SERVICE_ID    (0xA6U)
#define RTE_LDCOMCBKTXCONFIRMATION_SERVICE_ID     (0xA7U)
#define RTE_TASK_SERVICE_ID                       (0xF0U)
#define RTE_INCDISABLEFLAGS_SERVICE_ID            (0xF1U)
#define RTE_DECDISABLEFLAGS_SERVICE_ID            (0xF2U)

/*  Det Error Values macro definition. */
#define RTE_E_DET_ILLEGAL_SIGNAL_ID               (0x01U)
#define RTE_E_DET_ILLEGAL_VARIANT_CRITERION_VALUE (0x02U)
#define RTE_E_DET_ILLEGAL_NESTED_EXCLUSIVE_AREA   (0x05U)
#define RTE_E_DET_UNINIT                          (0x07U)
#define RTE_E_DET_MODEARGUMENT                    (0x20U)
#define RTE_E_DET_TRIGGERDISABLECOUNTER           (0x21U)
#define RTE_E_DET_TRANSITIONSTATE                 (0x22U)
#define RTE_E_DET_BLOCKSIZECHECK                  (0x23U)
#define RTE_E_DET_MULTICORE_STARTUP               (0x24U)
#define RTE_E_DET_MODESTATE                       (0x25U)
#define RTE_E_DET_GETVERSIONINFO                  (0x26U)

#define RTE_SOMEIPXF_HEADER_LENGTH                (8U)
#define RTE_E2EXF_HEADER_LENGTH                   (4U)
#define RTE_E2EXF_HEADER_LENGTH_P01               (2U)
#define RTE_E2EXF_HEADER_LENGTH_P02               (2U)
#define RTE_E2EXF_HEADER_LENGTH_P04               (12U)
#define RTE_E2EXF_HEADER_LENGTH_P05               (3U)
#define RTE_E2EXF_HEADER_LENGTH_P06               (5U)
#define RTE_ENCODING_BOM_LENGTH                   (4U)

/* Multi Core Sync Switch Macro Definition.*/
#define RTE_MULTI_CORE_SYNC_ENABLE                (STD_ON)
/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
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
#if(STD_ON == RTE_MULTI_CORE_SYNC_ENABLE)
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
extern FUNC(void, RTE_CODE) Rte_WaitMasterCoreStart(void);
extern FUNC(void, RTE_CODE) Rte_WaitMultiCoreSyncStart(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif

#endif /* RTE_H_ */

