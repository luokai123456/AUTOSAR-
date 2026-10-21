/*
************************************************************************************************************************
*
* File name: Rte_Dcm_Type.h
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

/*
************************************************************************************************************************
*    double include preventio and include files
************************************************************************************************************************
*/
#ifndef _RTE_DCM_TYPE_H
#define _RTE_DCM_TYPE_H

/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
#ifndef Rte_TypeDef_Dcm_38_ServiceInfoType_Req
#define Rte_TypeDef_Dcm_38_ServiceInfoType_Req
typedef struct{
    uint64 fileSizeUnCompressed;
    uint64 fileSizeCompressed;
    uint8 *filePathAndName;
    uint16 filePathAndNameLength;
    uint8 modeOfOperation;
    uint8 dataFormatIdentifier;
    uint8 fileSizeParameterLength;
}Dcm_38_ServiceInfoType_Req;
#endif

#ifndef Rte_TypeDef_Dcm_38_ServiceInfoType_Res
#define Rte_TypeDef_Dcm_38_ServiceInfoType_Res
typedef struct{
    uint8 md5Value[16];
    uint8 filePosition[8];
}Dcm_38_ServiceInfoType_Res;
#endif

#ifndef Rte_TypeDef_Dcm_OpStatusType
#define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;
#endif

#ifndef Rte_TypeDef_Dcm_ProtocolType
#define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;
#endif

#ifndef Rte_TypeDef_Dcm_SecLevelType
#define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;
#endif

#ifndef Rte_TypeDef_Dcm_SesCtrlType
#define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;
#endif

/* Dcm_OpStatusType */
#ifndef DCM_INITIAL
#define DCM_INITIAL                                     (0U)
#endif

#ifndef DCM_PENDING
#define DCM_PENDING                                     (1U)
#endif

#ifndef DCM_CANCEL
#define DCM_CANCEL                                      (2U)
#endif

#ifndef DCM_FORCE_RCRRP_OK
#define DCM_FORCE_RCRRP_OK                              (3U)
#endif

#ifndef Rte_TypeDef_Dcm_NegativeResponseCodeType
#define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;
#endif

/* Dcm_NegativeResponseCodeType. */
#ifndef DCM_POS_RESP
#define DCM_POS_RESP                                (0x00U)
#endif

#ifndef DCM_E_GENERALREJECT
#define DCM_E_GENERALREJECT                         (0x10U)
#endif

#ifndef DCM_E_SERVICENOTSUPPORTED
#define DCM_E_SERVICENOTSUPPORTED                   (0x11U)
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTED
#define DCM_E_SUBFUNCTIONNOTSUPPORTED               (0x12U)
#endif

#ifndef DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (0x13U)
#endif

#ifndef DCM_E_RESPONSETOOLONG
#define DCM_E_RESPONSETOOLONG                       (0x14U)
#endif

#ifndef DCM_E_BUSYREPEATREQUEST
#define DCM_E_BUSYREPEATREQUEST                     (0x21U)
#endif

#ifndef DCM_E_CONDITIONSNOTCORRECT
#define DCM_E_CONDITIONSNOTCORRECT                  (0x22U)
#endif

#ifndef DCM_E_REQUESTSEQUENCEERROR
#define DCM_E_REQUESTSEQUENCEERROR                  (0x24U)
#endif

#ifndef DCM_E_NORESPONSEFROMSUBNETCOMPONENT
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT         (0x25U)
#endif

#ifndef DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (0x26U)
#endif

#ifndef DCM_E_REQUESTOUTOFRANGE
#define DCM_E_REQUESTOUTOFRANGE                     (0x31U)
#endif

#ifndef DCM_E_SECURITYACCESSDENIED
#define DCM_E_SECURITYACCESSDENIED                  (0x33U)
#endif

#ifndef DCM_E_AUTHENTICATIONREQUIRED
#define DCM_E_AUTHENTICATIONREQUIRED                (0x34U)
#endif

#ifndef DCM_E_INVALIDKEY
#define DCM_E_INVALIDKEY                            (0x35U)
#endif

#ifndef DCM_E_EXCEEDNUMBEROFATTEMPTS
#define DCM_E_EXCEEDNUMBEROFATTEMPTS                (0x36U)
#endif

#ifndef DCM_E_REQUIREDTIMEDELAYNOTEXPIRED
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED           (0x37U)
#endif

#ifndef DCM_E_UPLOADDOWNLOADNOTACCEPTED
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED              (0x70U)
#endif

#ifndef DCM_E_TRANSFERDATASUSPENDED
#define DCM_E_TRANSFERDATASUSPENDED                  (0x71U)
#endif

#ifndef DCM_E_GENERALPROGRAMMINGFAILURE
#define DCM_E_GENERALPROGRAMMINGFAILURE              (0x72U)
#endif

#ifndef DCM_E_WRONGBLOCKSEQUENCECOUNTER
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER              (0x73U)
#endif

#ifndef DCM_E_REQUESTCORRECTLYRECEIVED_RESPONSEPENDING
#define DCM_E_REQUESTCORRECTLYRECEIVED_RESPONSEPENDING (0x78U)
#endif

#ifndef DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION   (0x7EU)
#endif

#ifndef DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION    (0x7FU)
#endif

#ifndef DCM_E_RPMTOOHIGH
#define DCM_E_RPMTOOHIGH                            (0x81U)
#endif

#ifndef DCM_E_RPMTOOLOW
#define DCM_E_RPMTOOLOW                             (0x82U)
#endif

#ifndef DCM_E_ENGINEISRUNNING
#define DCM_E_ENGINEISRUNNING                       (0x83U)
#endif

#ifndef DCM_E_ENGINEISNOTRUNNING
#define DCM_E_ENGINEISNOTRUNNING                    (0x84U)
#endif

#ifndef DCM_E_ENGINERUNTIMETOOLOW
#define DCM_E_ENGINERUNTIMETOOLOW                   (0x85U)
#endif

#ifndef DCM_E_TEMPERATURETOOHIGH
#define DCM_E_TEMPERATURETOOHIGH                    (0x86U)
#endif

#ifndef DCM_E_TEMPERATURETOOLOW
#define DCM_E_TEMPERATURETOOLOW                     (0x87U)
#endif

#ifndef DCM_E_VEHICLESPEEDTOOHIGH
#define DCM_E_VEHICLESPEEDTOOHIGH                   (0x88U)
#endif

#ifndef DCM_E_VEHICLESPEEDTOOLOW
#define DCM_E_VEHICLESPEEDTOOLOW                    (0x89U)
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOHIGH
#define DCM_E_THROTTLE_PEDALTOOHIGH                 (0x8AU)
#endif

#ifndef DCM_E_THROTTLE_PEDALTOOLOW
#define DCM_E_THROTTLE_PEDALTOOLOW                  (0x8BU)
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINNEUTRAL
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL         (0x8CU)
#endif

#ifndef DCM_E_TRANSMISSIONRANGENOTINGEAR
#define DCM_E_TRANSMISSIONRANGENOTINGEAR            (0x8DU)
#endif

#ifndef DCM_E_BRAKESWITCH_NOTCLOSED
#define DCM_E_BRAKESWITCH_NOTCLOSED                 (0x8FU)
#endif

#ifndef DCM_E_SHIFTERLEVERNOTINPARK
#define DCM_E_SHIFTERLEVERNOTINPARK                 (0x90U)
#endif

#ifndef DCM_E_TORQUECONVERTERCLUTCHLOCKED
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED           (0x91U)
#endif

#ifndef DCM_E_VOLTAGETOOHIGH
#define DCM_E_VOLTAGETOOHIGH                        (0x92U)
#endif

#ifndef DCM_E_VOLTAGETOOLOW
#define DCM_E_VOLTAGETOOLOW                         (0x93U)
#endif

#ifndef DCM_E_VMSCNC_0
#define DCM_E_VMSCNC_0                              (0xF0U)
#endif

#ifndef DCM_E_VMSCNC_1
#define DCM_E_VMSCNC_1                              (0xF1U)
#endif

#ifndef DCM_E_VMSCNC_2
#define DCM_E_VMSCNC_2                              (0xF2U)
#endif

#ifndef DCM_E_VMSCNC_3
#define DCM_E_VMSCNC_3                              (0xF3U)
#endif

#ifndef DCM_E_VMSCNC_4
#define DCM_E_VMSCNC_4                              (0xF4U)
#endif

#ifndef DCM_E_VMSCNC_5
#define DCM_E_VMSCNC_5                              (0xF5U)
#endif

#ifndef DCM_E_VMSCNC_6
#define DCM_E_VMSCNC_6                              (0xF6U)
#endif

#ifndef DCM_E_VMSCNC_7
#define DCM_E_VMSCNC_7                              (0xF7U)
#endif

#ifndef DCM_E_VMSCNC_8
#define DCM_E_VMSCNC_8                              (0xF8U)
#endif

#ifndef DCM_E_VMSCNC_9
#define DCM_E_VMSCNC_9                              (0xF9U)
#endif

#ifndef DCM_E_VMSCNC_A
#define DCM_E_VMSCNC_A                              (0xFAU)
#endif

#ifndef DCM_E_VMSCNC_B
#define DCM_E_VMSCNC_B                              (0xFBU)
#endif

#ifndef DCM_E_VMSCNC_C
#define DCM_E_VMSCNC_C                              (0xFCU)
#endif

#ifndef DCM_E_VMSCNC_D
#define DCM_E_VMSCNC_D                              (0xFDU)
#endif

#ifndef DCM_E_VMSCNC_E
#define DCM_E_VMSCNC_E                              (0xFEU)
#endif

#ifndef Rte_TypeDef_Dcm_DidSupportedType
#define Rte_TypeDef_Dcm_DidSupportedType
typedef uint8 Dcm_DidSupportedType;
#endif

/* Dcm_DidSupportedType. */
#ifndef DCM_DID_SUPPORTED
#define DCM_DID_SUPPORTED                               (0x00U)
#endif

#ifndef DCM_DID_NOT_SUPPORTED
#define DCM_DID_NOT_SUPPORTED                           (0x01U)
#endif

#ifndef Rte_TypeDef_Dcm_ConfirmationStatusType
#define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;
#endif

#ifndef DCM_RES_POS_OK
#define DCM_RES_POS_OK                  (0x00U)
#endif

#ifndef DCM_RES_POS_NOT_OK
#define DCM_RES_POS_NOT_OK              (0x01U)
#endif

#ifndef DCM_RES_NEG_OK
#define DCM_RES_NEG_OK                  (0x02U)
#endif

#ifndef DCM_RES_NEG_NOT_OK
#define DCM_RES_NEG_NOT_OK              (0x03U)
#endif

/* Active protocol. */
#ifndef DCM_OBD_ON_CAN
#define DCM_OBD_ON_CAN                                  (0x00U)
#endif

#ifndef DCM_OBD_ON_FLEXRAY
#define DCM_OBD_ON_FLEXRAY                              (0x01U)
#endif

#ifndef DCM_OBD_ON_IP
#define DCM_OBD_ON_IP                                   (0x02U)
#endif

#ifndef DCM_UDS_ON_CAN
#define DCM_UDS_ON_CAN                                  (0x03U)
#endif

#ifndef DCM_UDS_ON_FLEXRAY
#define DCM_UDS_ON_FLEXRAY                              (0x04U)
#endif

#ifndef DCM_UDS_ON_IP
#define DCM_UDS_ON_IP                                   (0x05U)
#endif

#ifndef DCM_ROE_ON_CAN
#define DCM_ROE_ON_CAN                                  (0x06U)
#endif

#ifndef DCM_ROE_ON_FLEXRAY
#define DCM_ROE_ON_FLEXRAY                              (0x07U)
#endif

#ifndef DCM_ROE_ON_IP
#define DCM_ROE_ON_IP                                   (0x08U)
#endif

#ifndef DCM_PERIODICTRANS_ON_CAN
#define DCM_PERIODICTRANS_ON_CAN                        (0x09U)
#endif

#ifndef DCM_PERIODICTRANS_ON_FLEXRAY
#define DCM_PERIODICTRANS_ON_FLEXRAY                    (0x0AU)
#endif

#ifndef DCM_PERIODICTRANS_ON_IP
#define DCM_PERIODICTRANS_ON_IP                         (0x0BU)
#endif

#ifndef DCM_NO_ACTIVE_PROTOCOL
#define DCM_NO_ACTIVE_PROTOCOL                          (0x0CU)
#endif

#ifndef DCM_UDS_ON_LIN
#define DCM_UDS_ON_LIN                                  (0x0DU)
#endif

#ifndef DCM_SUPPLIER_1
#define DCM_SUPPLIER_1                                  (0xF0U)
#endif

#ifndef DCM_SUPPLIER_2
#define DCM_SUPPLIER_2                                  (0xF1U)
#endif

#ifndef DCM_SUPPLIER_3
#define DCM_SUPPLIER_3                                  (0xF2U)
#endif

#ifndef DCM_SUPPLIER_4
#define DCM_SUPPLIER_4                                  (0xF3U)
#endif

#ifndef DCM_SUPPLIER_5
#define DCM_SUPPLIER_5                                  (0xF4U)
#endif

#ifndef DCM_SUPPLIER_6
#define DCM_SUPPLIER_6                                  (0xF5U)
#endif

#ifndef DCM_SUPPLIER_7
#define DCM_SUPPLIER_7                                  (0xF6U)
#endif

#ifndef DCM_SUPPLIER_8
#define DCM_SUPPLIER_8                                  (0xF7U)
#endif

#ifndef DCM_SUPPLIER_9
#define DCM_SUPPLIER_9                                  (0xF8U)
#endif

#ifndef DCM_SUPPLIER_10
#define DCM_SUPPLIER_10                                 (0xF9U)
#endif

#ifndef DCM_SUPPLIER_11
#define DCM_SUPPLIER_11                                 (0xFAU)
#endif

#ifndef DCM_SUPPLIER_12
#define DCM_SUPPLIER_12                                 (0xFBU)
#endif

#ifndef DCM_SUPPLIER_13
#define DCM_SUPPLIER_13                                 (0xFCU)
#endif

#ifndef DCM_SUPPLIER_14
#define DCM_SUPPLIER_14                                 (0xFDU)
#endif

#ifndef DCM_SUPPLIER_15
#define DCM_SUPPLIER_15                                 (0xFEU)
#endif

#ifndef DCM_SEC_LEV_LOCKED
#define DCM_SEC_LEV_LOCKED              (0x00U)
#endif

# ifndef DCM_DEFAULT_SESSION
# define DCM_DEFAULT_SESSION (1U)
# endif

# ifndef DCM_PROGRAMMING_SESSION
# define DCM_PROGRAMMING_SESSION (2U)
# endif

# ifndef DCM_EXTENDED_DIAGNOSTIC_SESSION
# define DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
# endif

# ifndef DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION
# define DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION (4U)
# endif

#ifndef Rte_TypeDef_DcmEcuReset
#define Rte_TypeDef_DcmEcuReset
typedef enum
{
    DCM_NONE,
    DCM_HARD,
    DCM_KEYONOFF,
    DCM_SOFT,
    DCM_JUMPTOBOOTLOADER,
    DCM_JUMPTOSYSSUPPLIERBOOTLOADER,
    DCM_EXECUTE,
} DcmEcuReset;
#endif

/*
************************************************************************************************************************
*    Range, Invalidation, Enumeration and Bit Field Definitions
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Definitions for Mode Management
************************************************************************************************************************
*/

#endif
