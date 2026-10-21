/*
********************************************************************************
*
* File name: Dcm.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Tanlx/2018.12.10
* Change: Add Autosar
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: Tanlx/2019.05.10
* Change: Modify the prefix of the function and global variable.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date : Liuziyang/2019.11.21
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.3
* Author/Date : Songqingwei/2019.12.23
* Change: Add "PduIdType Dcm_RxPduId" to "Dcm_PduRxTransportInfoType_st" struct.
* Cause: Features require.
********************************************************************************
* Version: 1.4
* Author/Date : Songqingwei/2020.02.28
* Change: Modify the macros about the 27 service.
* Cause: Adapted to 27 services.
********************************************************************************
* Version: 3.0
* Author/Date : Songqingwei/2020.03.27
* Change: Add service struct and Dcm module software version.
* Cause: Clear QAC warning and update to V3.0.
********************************************************************************
* Version: 3.1
* Author/Date : Songqingwei/2020.05.15
* Change: Modify the coding specification.
* Cause: Optimize
********************************************************************************
* Version: 3.2
* Author/Date : Songqingwei/2020.05.29
* Change: Change the macro "DCM_BIG_ENDIAN" from STD_ON to STD_OFF.
* Cause: Adapt small terminal chip.
********************************************************************************
* Version: 3.3
* Author/Date : Songqingwei/2020.05.31
* Change: Use the macro "CPU_BYTE_ORDER" to adapt the chip.
* Cause: Adapt small terminal chip.
********************************************************************************
* Version: 3.4
* Author/Date: ZhuChunying/2020.09.16
* Change: Add function of MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: ZhuChunying/2020.09.18
* Change: Modify the function name according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: ZhuChunying/2020.12.7
* Change: Add #include "Nm.h".
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: SongQW/2020.12.22
* Change: Add macro "DCM_31_WRITTIMEOUT" to control timeout about the 31 service.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: SongQW/2021.04.26
* Change: Add the macro "(STD_ON == DCM_SERVICE_10_ENABLED)".
* Cause: Bugfix
********************************************************************************
* Version: 3.9
* Author/Date: SongQW/2021.06.30
* Change: 1.Add the macro "DCM_E_INTERFACE_TIMEOUT".
*         2.Add the macro switch of module separation.
*         3.Add the macro "DCM_E_FINISHED", "DCM_COMM_SUPPORT",
*           "DCM_COMM_SUPPORT" and "DCM_DEM_SUPPORT".
*         4.Add structure variable and functions for service 02, 07, 09, 0A.
*         5.Add element of "Dcm_NumberOfFilteredRecords", "Dcm_SubFuncIter"
*           and "Dcm_DTCSnapShrtNum" for "Dcm_19_RepeaterProxyContextType_st".
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: SongQW/2021.7.7
* Change: Add the declaration of variables "Dcm_DownloadTotalLength"
*         and "Dcm_37_Requested".
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: SongQW/2021.07.27
* Change: Delete the "Dcm_DTCSnapShrtNum" in Dcm_19_RepeaterProxyContextType_st
*          structure.
* Cause: Bugfix
********************************************************************************
* Version: 3.12
* Author/Date: SongQW/2021.08.20
* Change: 1.Modify the definition type of variables "Dcm_2A_SchdIdx",
*           "Dcm_2A_SchdTable" and "Dcm_2A_DidList".
*         2.Add the return value of the function "Dcm_2C_ReadDDDidDataLength" and
*         "Dcm_2C_ReadDDDidData".
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: SongQW/2021.08.20
* Change: 1.Add declaration of the function "Dcm_GetDidUsed" for service 0x2C,
*           getting the DID is uesd or not.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date: SongQW/2021.08.27
* Change: Add the definition of the "Dcm_CommunicationModeType" in [SWS_Dcm_00981].
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: SongQW/2021.10.18
* Change: Add the 0x86 service.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: ZhuCY/2021.10.20
* Change: Modify component version information.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: ZhuCY/2021.10.21
* Change: Modify component version information.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: ZhuCY/2021.10.27
* Change: Modify header file name.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: ZhuCY/2021.10.29
* Change: Modify component version information.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: SongQW/2021.11.10
* Change: Modify the service 0x27 about the attempt counter stored to the NvM.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date: SongQW/2021.11.15
* Change: 1.Delete the macros "DCM_COMM_SUPPORT" and "DCM_DEM_SUPPORT" beacuse
*           of the error caused by the compilation sequence.
*         2.Add 0x3D service.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: SongQW/2021.11.18
* Change: 1.Update the minor version for adding the 0x3D service.
*         2.Update the patch version for bugfix about the 0x19 02 subfunction.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: ZhuCY/2021.12.07
* Change: Update the patch version for bugfix about the 0x27 service.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: Songqw/2022.02.15
* Change: Add the 0x19 service with 0x14 sub-function.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: SongQW/2021.12.17
* Change: Add the 0x29 service.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: SongQW/2022.03.02
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: SongQW/2022.03.14
* Change: 1.The Csm callback is inconsistent the definition of the 0x29 service.
*         2.Update the patch version.
* Cause: Bugfix
********************************************************************************
* Version: 3.28
* Author/Date: SongQW/2022.03.23
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: SongQW/2022.05.01
* Change: Add macros "DCM_CHECK_SECURITY_ON" and "DCM_CHECK_SECURITY_OFF" beacuse
*           of the 27 service for start or stop security check.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: SongQW/2022.05.13
* Change: Modify macros "DCM_2E_WRITTIMEOUT" beacuse of the 0x2E service for
*         time out.
* Cause: Bugfix
********************************************************************************
* Version: 3.31
* Author/Date: SongQW/2022.05.18
* Change: PID $02 indicates the DTC that caused the freeze frame data to be
*         stored. If freeze frame data is not stored in the ECU, the system
*         shall report $00 00 as the DTC. Any data reported when the stored
*         DTC is $00 00 may not be valid.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date: SongQW/2022.06.06
* Change: Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.33
* Author/Date: ChenQJ/2022.06.17
* Change: Fix Tasking IDE compile warning. Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.34
* Author/Date: ChenQJ/2022.07.04
* Change: Fix service 0x14 treat DCM_E_PENDING as NRC. Update patch version.
* Cause: Bugfix
********************************************************************************
* Version: 3.35
* Author/Date: ChenQJ/2022.07.04
* Change: Service 0x27 can not handle sub-function with suppress bit correctly.
* Cause: Bugfix
********************************************************************************
* Version: 3.36
* Author/Date: ChenQJ/2022.07.07
* Change: 1.Setting P2*Server_max to 100s will cause data overflow.
*         2.Remove redundant Dcm_10_ChgSession() caller.
* Cause: Bugfix
********************************************************************************
* Version: 3.37
* Author/Date: ChenQJ/2022.07.08
* Change: No need to include memmap.h file.
* Cause: Bugfix
********************************************************************************
* Version: 3.38
* Author/Date: ChenQJ/2022.07.14
* Change: SesCtrlType returned by Dcm_GetSesCtrlType() should be session control
*         type value.
* Cause: Bugfix
********************************************************************************
* Version: 3.39
* Author/Date: ChenQJ/2022.07.18
* Change: The domain name of Dcm_LastSeed is different with its definition.
* Cause: Bugfix
********************************************************************************
* Version: 3.40
* Author/Date: ChenQJ/2022.08.01
* Change: Remove the redundant code of Dcm 0x29.
* Cause: Bugfix
********************************************************************************
* Version: 3.41
* Author/Date: ChenQJ/2022.08.02
* Change: In service 0x27, NRC 0x7E should be handled before NRC 0x24.
* Cause: Bugfix
********************************************************************************
* Version: 3.42
* Author/Date: SongQW/2022.08.31
* Change: Add Dcm_Callback.h head file inclusion and update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.43
* Author/Date: ChenQJ/2022.09.02
* Change: 1.Fix compile warning.
*         2.Add service 0x11 response to ecu reset function.
*         3.When ErrorCode is NULL_PTR, it still be assigned in
*           Dcm_WriteMemory().
*         4.Remove redundant judgment.
* Cause: Bugfix
********************************************************************************
* Version: 3.44
* Author/Date: ChenQJ/2022.09.02
* Change: Add service 0x10 mode-switch function.
* Cause: Update
********************************************************************************
* Version: 3.45
* Author/Date: ChenQJ/2022.09.05
* Change: Send NRC 0x22 if check rule function of each service return
*         DCM_E_NOT_OK.
* Cause: Bugfix
********************************************************************************
* Version: 3.46
* Author/Date: ChenQJ/2022.09.20
* Change: Add 0x35 service and modify related service including 0x36 and 0x37.
* Cause: Update
********************************************************************************
* Version: 3.47
* Author/Date: ChenQJ/2022.10.28
* Change: Fix compile error when service 10 is enabled and service 28 is not
*         enabled.
* Cause: Bugfix
********************************************************************************
* Version: 3.48
* Author/Date: ChenQJ/2022.10.31
* Change: 1.Fix compile warning.
*         2.Define NTFRSLT_OK if CanTp is missing.
* Cause: Bugfix
********************************************************************************
* Version: 3.49
* Author/Date: ChenQJ/2022.11.26
* Change: Include "Rte_Dcm.h" in Dcm.h.
* Cause: Bugfix
********************************************************************************
* Version: 3.50
* Author/Date: ChenQJ/2022.11.30
* Change: DataFormatId only support 0x00U in service 0x34.
* Cause: Bugfix
********************************************************************************
* Version: 3.51
* Author/Date: LiZL/2022.12.5
* Change: Add Dcm_2A_Scheduler_st member variable Dcm_OpStatus, modifying the
*         version number.
* Cause: Update
********************************************************************************
* Version: 3.52
* Author/Date: ChenQJ/2022.12.07
* Change: Optimize service 22 2A 2E, use function return value to judge
*         DCM_E_PENDING as AUTOSAR describe.
* Cause: Optimization
********************************************************************************
* Version: 3.53
* Author/Date: WuHW/2022.12.09
* Change: update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.54
* Author/Date: ChenQJ/2022.12.14
* Change: Fix compile warning.
* Cause: Bugfix
********************************************************************************
* Version: 3.55
* Author/Date: ChenQJ/2022.12.31
* Change: Update minor and patch version.
* Cause: Update
********************************************************************************
* Version: 3.56
* Author/Date: WuHW/2023.02.09
* Change: 1.Add the macro about the Dcm sevice 0x38.
          2.Add member about the 0x38 to the
          Dcm_RepeaterProxyContextPoolType_st.
          3.Add Function declaration about the Dcm sevice 0x38.
* Cause: Update
********************************************************************************
* Version: 3.57
* Author/Date: ChenQJ/2023.01.16
* Change: Update patch version.
* Cause: Update
********************************************************************************
* Version: 3.58
* Author/Date: WuHW/2023.03.01
* Change: 1.Update patch version.
*         2.Change the type of the member subFuncIndex in
*         the Dcm_38_RepeaterProxyContextType_st.
* Cause: Update
********************************************************************************
* Version: 3.59
* Author/Date: WuHW/2023.03.18
* Change: Update patch version.
* Cause: Update
********************************************************************************
* Version: 3.60
* Author/Date: WuHW/2023.03.31
* Change: Add variate to support for USE_DATA_SYNCH_FNC/USE_DATA_ASYNCH_FNC/
*         USE_DATA_ASYNCH_FNC_ERROR in the config of 0x22/0x2E/0x2A service.
* Cause: Update
********************************************************************************
* Version: 3.61
* Author/Date: WuHW/2023.04.07
* Change: To add function declaration that the subfunction 0x17/0x18/0x19 of
*         0x19 service.
* Cause: Update
********************************************************************************
* Version: 3.62
* Author/Date: WuHW/2023.04.21
* Change: Update minor and patch version.
* Cause: Update
********************************************************************************
* Version: 3.63
* Author/Date: WuHW/2023.05.06
* Change: 1.Add macro DCM_28_CHECKTIMEOUT/DCM_10_CHECKTIMEOUT/
*           DCM_11_CHECKTIMEOUT for check function.
*         2.Add the variable sfIter to the struct
*           Dcm_11_RepeaterProxyContextType_st.
* Cause: Update
********************************************************************************
* Version: 3.64
* Author/Date: WuHW/2023.05.25
* Change: 1.Change the conditional compilation about the reference of Nm.h,which
*           according to CCOREDBUG-1899.
*         2.Add a member to the struct Dcm_14_RepeaterProxyContextType_st and
*           the macro DCM_MSDTC_LEN for the 0x14 service,which according to
*           CCOREDBUG-3114.
* Cause: Bugfix
********************************************************************************
* Version: 3.65
* Author/Date: WuHW/2023.05.26
* Change: Modify version to 3.7.0.0.
* Cause: Update
********************************************************************************
* Version: 3.66
* Author/Date: ChenQJ/2023.06.17
* Change: Provide sequence number to Dcm_36_RoutineFunctionForDcm38 function.
* Cause: Update
********************************************************************************
* Version: 3.67
* Author/Date: ChenQJ/2023.06.19
* Change: 1.Support ServiceRequestNotification port operation.
*         2.Modify 28 02/03 incorrect marco value.
* Cause: Update
********************************************************************************
* Version: 3.68
* Author/Date: ChenQJ/2023.06.20
* Change: Fix NRC incorrect when reading a DID with no security clearance by
*         service 0x22.
* Cause: Bugfix
********************************************************************************
* Version: 3.69
* Author/Date: ChenQJ/2023.06.26
* Change: Optimize service 29 01/02/03 for APCE authentication, do not support
*         role and white list now.
* Cause: Optimization
********************************************************************************
* Version: 3.70
* Author/Date: ChenQJ/2023.06.28
* Change: Fix service 0x02 set pid list incorrect.
* Cause: Bugfix
********************************************************************************
* Version: 3.71
* Author/Date: ChenQJ/2023.06.29
* Change: 1.If a DID relate block is configured with NvMWriteBlockOnce and a
*           second block write via service 0x2E occurs, it should return NRC 0x72.
*         2.The data type of security level delay timer is incorrect, it should
*           be uint32.
*         3.Support 29 05/06/07 for ACR authentication.
*         4.Modify 29 01/02/03/06/07 remaining length checking issue to prevent
*           pointer out of bounds.
* Cause: Bugfix
********************************************************************************
* Version: 3.72
* Author/Date: ChenQJ/2023.06.30
* Change: 1.Stop all the control in progress of service 0x2F on a session
*           transition to default session(either from default session or from
*           non-default session).
*         2.Fix compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.73
* Author/Date: ChenQJ/2023.07.04
* Change: Fix QAC warning.
* Cause: Bugfix
********************************************************************************
* Version: 3.74
* Author/Date: LiuY/2023.07.31
* Change: Add UDS general version defination.
* Cause: Update
********************************************************************************
* Version: 3.75
* Author/Date: ChenQJ/2023.08.02
* Change: Update software version to 3.8.0.3.
* Cause: Update
********************************************************************************
* Version: 3.76
* Author/Date: LiuY/2023.08.14
* Change: 1.Add control DTC setting(0x85) mode defination.
*         2.Fix compile warning.
* Cause: Update
********************************************************************************
* Version: 3.77
* Author/Date: LiuY/2023.08.24
* Change: Update software version to 3.8.0.6.
* Cause: Update
********************************************************************************
* Version: 3.78
* Author/Date: LiuY/2023.09.15
* Change: Support multiple service tables.
* Cause: Update
********************************************************************************
* Version: 3.79
* Author/Date: WuXJ/2023.10.27
* Change: Update software version to 3.9.0.8.
* Cause: Update
********************************************************************************
* Version: 3.80
* Author/Date: WuXJ/2023.11.28
* Change: Update software version to 3.9.0.9.
* Cause: Update
********************************************************************************
* Version: 3.81
* Author/Date: WuXJ/2023.12.20
* Change: Update software version to 3.9.0.10.
* Cause: Update
********************************************************************************
* Version: 3.82
* Author/Date: LiuY/2024.1.11
* Change: Update software version to 3.10.0.11.
* Cause: Update
********************************************************************************
* Version: 3.83
* Author/Date: LiuY/2024.1.26
* Change: 1.Add macro DCM_3F_VALUE.
*         2.Update software version to 3.10.0.12.
* Cause: Update
********************************************************************************
* Version: 3.84
* Author/Date: WuXJ/2024.2.4
* Change: 1.Modify the macro "DCM_SID_EXT_SETNEGRESPONSE" to
*           "DCM_SID_PROCESSREQUESTDOWNLOAD".
*         2.Delete the declaration "Dcm_WriteMemory" and "Dcm_37_Requested".
* Cause: Update
********************************************************************************
* Version: 3.85
* Author/Date: WuXJ/2024.2.19
* Change: Delete the header files "Dcm_Callback.h".
* Cause: Update
********************************************************************************
* Version: 3.86
* Author/Date: WuXJ/2024.3.5
* Change: Update software version to 3.10.0.13.
* Cause: Update
********************************************************************************
* Version: 3.87
* Author/Date: WuXJ/2024.3.12
* Change: Add macro DCM_UDS_ON_LIN.
* Cause: Update
********************************************************************************
* Version: 3.88
* Author/Date: WuXJ/2024.3.21
* Change: Add member Dcm_RespBufferLenVal to the struct 
*         Dcm_37_RepeaterProxyContextType_st.
* Cause: Update
********************************************************************************
* Version: 3.89
* Author/Date: LiuY/2024.5.10
* Change: 1.Update software version to 3.11.0.14.
*         2.Add macro DCM_EVENT_RCRRP_SEND.
* Cause: Update
********************************************************************************
* Version: 3.90
* Author/Date: WuXJ/2024.5.22
* Change: Add the 0x19 service with 0x05 sub-function.
* Cause: Update
********************************************************************************
* Version: 3.91
* Author/Date: LiuY/2024.7.16
* Change: 1.Modify the callback notifications from Csm/KeyM upon finishing an
*           asynchronous processing.
*         2.Add macro DCM_29_AUT_WHITELIST_MAXSIZE and DCM_29_SIDLEN
*           for 0x29 service.
*         3.Update software version to 3.11.0.15.
* Cause: Update
********************************************************************************
* Version: 3.92
* Author/Date: WuXJ/2024.8.7
* Change: 1.Fix Dcm memmap issue.
*         2.Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.93
* Author/Date: WuXJ/2024.8.9
* Change: Remove time constraints for some services.
* Cause: Bugfix
********************************************************************************
* Version: 3.94
* Author/Date: LiuY/2024.8.10
* Change: Add members in Dcm_DslInfoPoolType_st for transmit buffer.
* Cause: Update
********************************************************************************
* Version: 3.95
* Author/Date: WuXJ/2024.9.2
* Change: Update software version to 3.11.0.16.
* Cause: Update
********************************************************************************
* Version: 3.96
* Author/Date: WuXJ/2024.9.2
* Change: Add the 0x19 service with 0x42 sub-function.
* Cause: Update
********************************************************************************
* Version: 3.97
* Author/Date: LiuY/2024.9.19
* Change: Update software version to 3.11.0.17.
* Cause: Update
********************************************************************************
* Version: 3.98
* Author/Date: WuXJ/2024.9.19
* Change: Update software version to 3.11.0.18.
* Cause: Update
********************************************************************************
* Version: 3.99
* Author/Date: LiuY/2024.10.23
* Change: Update software version to 3.12.0.19.
* Cause: Update
********************************************************************************
* Version: 3.100
* Author/Date: WuXJ/2024.10.23
* Change: Add the 0x19 service with 0x07/0x08/0x09/0x0C sub-function.
* Cause: Update
********************************************************************************
* Version: 3.101
* Author/Date: WuXJ/2024.10.24
* Change: 1.Add the 0x19 service with 0x12/0x13/0x55 sub-function.
*         2.Add the 0x05 and 0 x06 obd services.
* Cause: Update
********************************************************************************
* Version: 3.102
* Author/Date: WuXJ/2024.10.30
* Change: 1.Add the 0x87 services.
*         2.Update software version to 3.12.0.20.
* Cause: Update
********************************************************************************
* Version: 3.103
* Author/Date: WuXJ/2024.11.07
* Change: Add the macro DCM_DEM_OBD_SUPPORT.
* Cause: Bugfix
********************************************************************************
* Version: 3.104
* Author/Date: LiuY/2024.12.05
* Change: Update software version to 3.12.0.21.
* Cause: Update
********************************************************************************
* Version: 3.105
* Author/Date: WuXJ/2024.12.05
* Change: Delete the macros DCM_TESTID_ZERO and DCM_AVAILTESTID.
* Cause: Update
********************************************************************************
* Version: 3.106
* Author/Date: WuXJ/2025.02.10
* Change: Update software version to 3.13.0.22.
* Cause: Update
********************************************************************************
* Version: 3.107
* Author/Date: WuXJ/2025.03.03
* Change: 1.Update software version to 3.13.0.23.
*         2.Add the macro of 0x3E80.
* Cause: Update
********************************************************************************
* Version: 3.108
* Author/Date: WuXJ/2025.03.26
* Change: 1.Fix the QAC warning and add the QAC deviation suppression comment.
*         2.Update software version to 3.13.0.24.
* Cause: Optimization
********************************************************************************
* Version: 3.109
* Author/Date: WuXJ/2025.04.07
* Change: Update software version to 3.13.0.25.
* Cause: Update
********************************************************************************
* Version: 3.110
* Author/Date: WuXJ/2025.04.29
* Change: Update software version to 3.14.0.26.
* Cause: Update
********************************************************************************
* Version: 3.111
* Author/Date: WuXJ/2025.05.19
* Change: Update software version to 3.14.0.27.
* Cause: Update
********************************************************************************
* Version: 3.112
* Author/Date: WuXJ/2025.06.05
* Change: Update software version to 3.14.0.28.
* Cause: Update
********************************************************************************
* Version: 3.113
* Author/Date: WuXJ/2025.06.05
* Change: Fix Polyspace warnings and add analysis results.
* Cause: Bugfix
********************************************************************************
* Version: 3.114
* Author/Date: WuXJ/2025.06.10
* Change: Modify the suppressed positive response of 0x27.
* Cause: Bugfix
********************************************************************************
* Version: 3.115
* Author/Date: WuXJ/2025.06.18
* Change: 1.Update software version to 3.14.0.29.
*         2.Adjust the position of DCM_29_SID.
* Cause: Bugfix
********************************************************************************
* Version: 3.116
* Author/Date: WuXJ/2025.06.23
* Change: Update software version to 3.14.0.30.
* Cause: Update
********************************************************************************
* Version: 3.117
* Author/Date: WuXJ/2025.08.04
* Change: Update software version to 3.15.0.31.
* Cause: Update
********************************************************************************
* Version: 3.118
* Author/Date: WuXJ/2025.08.14
* Change: Update software version to 3.15.0.32.
* Cause: Update
********************************************************************************
*/
#ifndef DCM_H_
#define DCM_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Dcm_Cfg.h"
#include "Dcm_Lcfg.h"
#include "ComM.h"
#include "ComStack_Types.h"
#include "Dcm_Types.h"
#include "Com.h"
#include "Rte_Dcm.h"

#if ( STD_ON == DCM_SERVICE_28_ENABLED )
#include "Nm.h"
#endif

#if ( STD_ON == DCM_SERVICE_29_ENABLED )
#include "Csm.h"
#include "KeyM.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_DEFAULT_BLOCKID             (0x04U)   /* DCM Default Nvm Block ID. */

/* Module identification and version. */
#define DCM_MODULE_ID                   (53U)
#define DCM_VENDOR_ID                   (119U)

/* Component Version Information. */
#define DCM_SW_MAJOR_VERSION            (3U)
#define DCM_SW_MINOR_VERSION            (15U)
#define DCM_SW_PATCH_VERSION            (0U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SW_REVISION_VERSION         (32U)

/* AUTOSAR Version. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AR_RELEASE_MAJOR_VERSION    (4U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AR_RELEASE_MINOR_VERSION    (2U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AR_RELEASE_REVISION_VERSION (2U)

#define DCM_INSTANCE_ID_DET             (0x00U) /* Instance ID. */

#define DCM_E_OK                         E_OK
#define DCM_E_NOT_OK                     E_NOT_OK
#ifndef NTFRSLT_OK
#define NTFRSLT_OK                      DCM_E_OK
#endif

/*Dsl comm state*/
#define DSL_COMM_E_OK                   (0U)
#define DSL_COMM_E_NOT_OK               (1U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DSL_COMM_E_NO_COMM              (2U)

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#define DCM_BIG_ENDIAN                  STD_OFF  /* little endian */
#else
#define DCM_BIG_ENDIAN                  STD_ON   /* big endian */
#endif

/* Dcm tx type,include linear and page. */
#define DSL_RES_TYPE_FINAL_LINEAR       (0x10U)
#define DSL_RES_TYPE_FINAL_PAGED        (0x20U)
#define DSL_RES_TYPE_FINAL              (DSL_RES_TYPE_FINAL_LINEAR | DSL_RES_TYPE_FINAL_PAGED)

/* Dcm tx state machine. */
#define DCM_PDU_TX_STATE_FREE           (0x00U)
#define DCM_PDU_TX_STATE_INIT           (0x01U)
#define DCM_PDU_TX_STATE_PROCESSING     (0x02U)
#define DCM_PDU_TX_STATE_DO_SEND        (0x03U)
#define DCM_PDU_TX_STATE_ON_TX          (0x04U)

/* Dcm rx state machine. */
#define DCM_CONTEXT_STATE_FREE              (0x01U)
#define DCM_CONTEXT_STATE_RX_STARTED        (0x02U)
#define DCM_CONTEXT_STATE_RX_ENDED          (0x03U)
#define DCM_CONTEXT_STATE_PROCESS_STARTED   (0x04U)
#define DCM_CONTEXT_STATE_PROCESS_ENDED     (0x05U)
#define DCM_CONTEXT_STATE_TX_STARTED        (0x06U)

#define DSL_RES_TYPE_NONE                   (0x00U)
#define DSL_RES_TYPE_RCRRP_AUT              (0x01U)
#define DSL_RES_TYPE_RCRRP_FINISHED         (0x02U)

/* Event id. */
#define DCM_EVENT_SEND_LINEAR_RES       (0x01U)
#define DCM_EVENT_SEND_PAGED_RES        (0x02U)
#define DCM_EVENT_NEW_REQ               (0x04U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_EVENT_TX_END                (0x08U)
#define DCM_EVENT_STATE_TASK_PROXY      (0x10U)
#define DCM_EVENT_RCRRP_CONFIRM         (0x20U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_EVENT_PB_UPDATE_PAGE        (0x40U)
#define DCM_EVENT_TESTER_TIMEOUT        (0x80U)
#define DCM_EVENT_IGNORE_RESPONSE       (0x100U)
#define DCM_EVENT_PERIODIC_TRANSMIT     (0x200U)
#define DCM_EVENT_RCRRP_SEND            (0x400U)

#define DCM_EVENT_ROE_TRANSMIT          (0x01U)
#define DCM_EVENT_ROE_TRANSMIT_DONE     (0x02U)
#define DCM_EVENT_ROE_NVM               (0x04U)

#define DCM_EVENT_SECURITY_GETSTATUS     (0x01U)
#define DCM_EVENT_SECURITY_REQUEST       (0x02U)

#define DCM_SESSION_STATE_GRP_IDX       (0U)    /* Session index. */
#define DCM_SECACCESS_STATE_GRP_IDX     (1U)    /* Security index. */

#define DCM_CHECK_SECURITY_ON           (1U)
#define DCM_CHECK_SECURITY_OFF          (0U)

/* polyspace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_Dcm_11.4" */
#define DCM_ZERO                        (0U)
#define DCM_ONE                         (1U)
#define DCM_TWO                         (2U)
#define DCM_THREE                       (3U)
#define DCM_FOUR                        (4U)
#define DCM_FIVE                        (5U)
#define DCM_SIX                         (6U)
#define DCM_SEVEN                       (7U)
#define DCM_EIGHT                       (8U)
#define DCM_3F_VALUE                    (0x3FU)
#define DCM_FF_VALUE                    (0xFFU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_FE_VALUE                    (0xFEU)
#define DCM_FFFF_VALUE                  (0xFFFFU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_INVALIDVAL_U16BIT           (0xFFFFU)
#define DCM_FFFFFF_VALUE                (0xFFFFFFU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_FFFFFFFF_VALUE              (0xFFFFFFFFU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_00_VALUE                    (0x00U)
#define DCM_UUDT_MSG_LENGTH             (8U)
#define DCM_UPLIMIT_ADDR                (0xFFFFFFFFU)

/* Used for data offset. */
#define DCM_OFFSET_ZERO                 (0U)
#define DCM_OFFSET_ONE                  (1U)
#define DCM_OFFSET_TWO                  (2U)
#define DCM_OFFSET_THREE                (3U)
#define DCM_OFFSET_FOUR                 (4U)
#define DCM_OFFSET_FIVE                 (5U)
#define DCM_OFFSET_SIX                  (6U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_OFFSET_SEVEN                (7U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_OFFSET_EIGHT                (8U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_OFFSET_NINE                 (9U)

/* Used for data length. */
#define DCM_DATALEN_ZERO                (0U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_DATALEN_ONE                 (1U)
#define DCM_DATALEN_FOUR                (4U)

/* Used for initialization. */
#define DCM_INIT_ZERO                   (0U)
#define DCM_INIT_ONE                    (1U)

/* Used for configuring the number of PID. */
#define DCM_PIDNUM_ZERO                 (0U)

/* Used to check record numbers. */
#define DCM_RECNUM_ZERO                 (0U)

/* Used to record the number of DTCs. */
#define DCM_DTCNUM_ZERO                 (0U)

/* Used to DTC severity mask */
#define DCM_SEVERITYMASK_ZERO          (0U)

/* Used to DTC status mask */
#define DCM_STATUSMASK_ZERO             (0U)

/* Used for circular indexing. */
#define DCM_INDEX_ZERO                  (0U)
#define DCM_INDEX_ONE                   (1U)

/* Used to obtain the remainder. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_REMAINDER_ZERO              (0U)

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_OBDMID_ZERO                 (0U)

/* Used to distinguish availability obdMid */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AVAILOBDMID                 (32U)

#define DCM_MEMORYSIZE_OFFSET           (4U)
#define DCM_ADDRANDLENGTH_MASK          (0x0FU)

#define DCM_INVALID_CHNID               (0xFFU)

#define DCM_SECURITY_MASK               (0x01U)

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_RAND_SEED_PARM0             (0x00AAU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_RAND_SEED_PARM1             (0x0FF0U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_RAND_SEED_PARM2             (0xFF00U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_RAND_SEED_PARM3             (0x0055U)

#define DCM_NO_SEC_LEVEL                (0U)

#define DCM_P2TIME_FACTOR               (10U)

#define DCM_NUM_TASKS                   (5U)    /* Dcm task number. */

/* Dsd and Dsl event type. */
#define DCM_TASK_ID_DSL_LL_STATE        (0U)
#define DCM_TASK_ID_DSD_LL_STATE        (1U)
#define DCM_TASK_ID_PERIODIC_TX         (2U)
#define DCM_TASK_ID_ROE                 (3U)
#define DCM_TASK_ID_SECURITY            (4U)

#define DCM_TASK_EVENT_ALLMASK          (0xFFFFU)

#define DCM_SUPPRESS_POS                (0x80U)

#define DCM_NRC_POS                     (0x7FU)

#define DCM_RCRRPTX_LEN                 (0x03U)
#define DCM_NEGTX_LEN                   (0x03U)

#define DCM_CURRENTSTATE_LEN            (0x02U)
#define DCM_RESPONSE_OFFSET             (0x40U)

#define DCM_CONFIRM_NEG                 (0x2U)
#define DCM_CONFIRM_TX_FAIL             (0x01U)

/* Dsl state machine. */
#define DCM_EVENT_DO_SEND               (0x01U)
#define DCM_EVENT_DO_RETRY_TX_ALLOC_UDS (0x02U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_EVENT_DO_RETRY_TX_ALLOC_OBD (0x04U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_EVENT_PPRH_DO_SEND          (0x08U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_EVENT_REV_DATA              (0x10U)

/* Session flag. */
#define DCM_NO_PEND_SESCHG_IDX          (0xFFU)

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

/* Current state,include session and security. */
#define DCM_NUM_STATE_GROUPS            (2U)

#define DCM_INHIBIT_POS                 (0x80U)

/* Buffer used flag. */
#define DCM_BUFFER_USED                 (1U)
#define DCM_BUFFER_IDLE                 (0U)

#define DCM_DSL_INIT_PRIORITY           (0xFFU)

/* Dcm return type. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_TI_PREPARE_LIMITS         (2U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_TI_PREPARE_INCONSTENT     (3U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_SESSION_NOT_ALLOWED       (4U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_PROTOCOL_NOT_ALLOWED      (5U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_ROE_NOT_ACCEPTED          (6U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_PERIODICID_NOT_ACCEPTED   (7U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_REQUEST_NOT_ACCEPTED      (8U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_REQUEST_ENV_NOK           (9U)
#define DCM_E_PENDING                   (10U)
#define DCM_E_COMPARE_KEY_FAILED        (11U)
#define DCM_E_FORCE_RCRRP               (12U)
#define DCM_E_FINISHED                  (13U)

/* Det error id. */
#define DCM_E_NO_ERROR                  (0x00U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_INTERFACE_TIMEOUT         (0x01U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_INTERFACE_RETURN_VALUE    (0x02U)
#define DCM_E_INTERFACE_BUFFER_OVERFLOW (0x03U)
#define DCM_E_UNINIT                    (0x05U)
#define DCM_E_PARAM                     (0x06U)
#define DCM_E_PARAM_POINTER             (0x07U)
#define DCM_E_INIT_FAILED               (0x08U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_SET_PROG_CONDITIONS_FAIL  (0x09U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_ILLEGAL_STATE             (0x40U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_INVALID_CONFIG            (0x41U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_E_CRITICAL_ERROR            (0x42U)

/* Service id. */
#define DCM_SID_STARTOFRECEPTION                        (0x00U)
#define DCM_SID_INIT                                    (0x01U)
#define DCM_SID_COPYRXDATA                              (0x02U)
#define DCM_SID_TPRXINDICATION                          (0x03U)
#define DCM_SID_COPYTXDATA                              (0x04U)
#define DCM_SID_TPTXCONFIRMATION                        (0x05U)
#define DCM_SID_GETSESCTRLTYPE                          (0x06U)
#define DCM_SID_GETVIN                                  (0x07U)
#define DCM_SID_GETSECLEVEL                             (0x0DU)
#define DCM_SID_GETACTIVEPROTOCOL                       (0x0FU)
#define DCM_SID_COMMENTERNOCOMMODE                      (0x21U)
#define DCM_SID_COMMENTERSILENTCOMMODE                  (0x22U)
#define DCM_SID_COMMENTERFULLCOMMODE                    (0x23U)
#define DCM_SID_GETVERSIONINFO                          (0x24U)
#define DCM_SID_MAINFUNCTION                            (0x25U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_RESET2DEFAULTSESSION                    (0x2AU)
#define DCM_SID_DEMTRIGGERONDTCSTATUS                   (0x2BU)
#define DCM_SID_TRIGGERONEVENT                          (0x2DU)
#define DCM_SID_PROCESSREQUESTDOWNLOAD                  (0x30U)
#define DCM_SID_PROCESSREQUESTUPLOAD                    (0x31U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_EXT_DIAGSVC_PROCESSOR                   (0x32U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_SVCPORT_DATASVCS_OP_READDATA_SYNC       (0x34U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_SVCPORT_DATASVCS_OP_READDATA_ASYNC      (0x3BU)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_SVCPORT_DATASVCS_OP_ISAVAILABLEDIDRANGE (0x3FU)
#define DCM_SID_SVCPORT_DATASVCS_OP_READDIDRANGE        (0x40U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define DCM_SID_SVCPORT_DATASVCS_OP_WRITEDIDRANGE       (0x41U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_GETSEED                                 (0x44U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_GETSEED_ACCESSDATA_RECORD               (0x45U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_COMPARE_KEY                             (0x47U)
#define DCM_SID_DID_AVAILABLE                           (0x53U)
#define DCM_SID_SETACTIVEDIAGNOSTIC                     (0x56U)
#define DCM_SID_GETSECURITYATTEMPTCOUNTER               (0x59U)
#define DCM_SID_SETSECURITYATTEMPTCOUNTER               (0x5AU)
#define DCM_SID_READDIDRANGEDATALENGTH                  (0x5EU)
#define DCM_SID_CLEARDTCCHECKFNC                        (0x5FU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_SVCPORT_DATASVCS_OP_READVID             (0x60U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_TXCONFIRMATION                          (0xA1U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_TRIGGERTRANSMIT                         (0xA2U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_PROVIDERECOVERYSTATES                   (0xA3U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_ONREQUESTDETECTION                      (0xA4U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_GETRECOVERYSTATES                       (0xA5U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_GETTESTERSOURCEADDRESS                  (0xA6U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_GETSECLEVELFIXEDBYTES                   (0xA7U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_PROCESSVIRTUALREQUEST                   (0xA8U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_SETSECLEVEL                             (0xA9U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_SVCPORT_DATASVCS_OP_READPAGEDDID        (0xAAU)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_GETREQUESTKIND                          (0xABU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_VSGSETSINGLE                            (0xACU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_VSGISACTIVE                             (0xADU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_VSGSETMULTIPLE                          (0xAEU)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_SID_VSGISACTIVEANY                          (0xAFU)

/* Dummy function. */
#ifndef DCM_DUMMY_STATEMENT
/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt"  polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_DUMMY_STATEMENT(v) (v)=(v)
#endif

#define DCM_MSGADDINFO_NONE_TYPE                        (0x00U)
/* For func, NRC 11,12,31,7e,7f is not supported. */
#define DCM_MSGADDINFO_REQ_TYPE                         (0x01U)
/* Positiver response in not supported, whether it is phy or func. */
#define DCM_MSGADDINFO_SUPP_POS_RES                     (0x02U)

/* Used for checking session and security. */
#define DCM_STATE_LVL_SID                               (0U)
#define DCM_STATE_LVL_PARAM                             (1U)
#define DCM_STATE_LVL_SUBFUNC                           (2U)

#define DCM_TIMER_ID_S3                                 (0U)/* Session timeout. */
#define DCM_TIMER_ID_P2                                 (1U)/* Pending timeout. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_TIMER_ID_SA                                 (2U)/* 27 sendkey timeout. */
#define DCM_TIMER_ID_ROE                                (3U)/* 86 ROE timeout. */

/* Timer manager num,include session timout, rccrp timer and security locking time. */
#define DCM_NUM_TIMERS_CONST                            (4U)

#define DCM_DTC_LEN                                     (0x3U)
#define DCM_MSDTC_LEN                                   (0x4U)

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dcm_GetHiByte(data)                             ((uint8)(((uint16)(data))>>8U))
/* polyspace +1 MISRA-C3:12.4 [Justified:Unset] "NSCA_Polyspace_Dcm_12.4"  polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [JUstified:Unset] "NSCA_Polyspace_Dcm_UINT_CONSTANT_OVFL" */
#define Dcm_GetLoByte(data)                             ((uint8)(data))

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dcm_GetHiHiByte(data)                           ((uint8)(((uint32)(data))>>24U))
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dcm_GetHiLoByte(data)                           ((uint8)(((uint32)(data))>>16U))
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dcm_GetLoHiByte(data)                           ((uint8)(((uint32)(data))>>8U))
/* polyspace +1 MISRA-C3:12.4 [Justified:Unset] "NSCA_Polyspace_Dcm_12.4"  polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  Polyspace +1 DEFECT:UINT_CONSTANT_OVFL [JUstified:Unset] "NSCA_Polyspace_Dcm_UINT_CONSTANT_OVFL" */
#define Dcm_GetLoLoByte(data)                           ((uint8)(data))

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define Dcm_Make16Bit(hiByte,loByte)                    ((uint16)((((uint32)(hiByte))<<8U)| ((uint32)(loByte))))

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro"  Polyspace +1 MISRA-C3:2.1 [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
#define Dcm_Make32Bit(hiHiByte,hiLoByte,loHiByte,loLoByte)  ((uint32)((((uint32)(hiHiByte))<<24U)| \
                                                            (((uint32)(hiLoByte))<<16U)| \
                                                            (((uint32)(loHiByte))<<8U) | \
                                                            ((uint32)(loLoByte))))

/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_GET_STATE_MASK(stateIter)                    ((uint32)0x01U<<(stateIter))
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef"  polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_GET_PROTOCOL_MASK(iProt)                     ((uint32)0x01U<<((iProt) - 1U))

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

/* Active protocol. */
#ifndef DCM_OBD_ON_CAN
#define DCM_OBD_ON_CAN                                  (0U)
#endif

#ifndef DCM_OBD_ON_FLEXRAY
#define DCM_OBD_ON_FLEXRAY                              (1U)
#endif

#ifndef DCM_OBD_ON_IP
#define DCM_OBD_ON_IP                                   (2U)
#endif

#ifndef DCM_UDS_ON_CAN
#define DCM_UDS_ON_CAN                                  (3U)
#endif

#ifndef DCM_UDS_ON_FLEXRAY
#define DCM_UDS_ON_FLEXRAY                              (4U)
#endif

#ifndef DCM_UDS_ON_IP
#define DCM_UDS_ON_IP                                   (5U)
#endif

#ifndef DCM_UDS_ON_LIN
#define DCM_UDS_ON_LIN                                  (13U)
#endif

#ifndef DCM_NO_ACTIVE_PROTOCOL
#define DCM_NO_ACTIVE_PROTOCOL (12U)
#endif

/* Dcm_DidSupportedType. */
#ifndef DCM_DID_SUPPORTED
#define DCM_DID_SUPPORTED                               (0x00U)
#endif
#ifndef DCM_DID_NOT_SUPPORTED
#define DCM_DID_NOT_SUPPORTED                           (0x01U)
#endif

/* Initial state. */
#define DCM_INITSTATE_UNINIT                            (0x00U)
#define DCM_INITSTATE_INIT                              (0x01U)

/* Comm active. */
#define DCM_NET_COMM_ACTIVE                             TRUE
#define DCM_NET_COMM_NOT_ACTIVE                         FALSE

/* Specifies the result of the callout for the memory access. */
/* Memory access was successful. */
#define DCM_MEMMGR_OP_RSLT_OK                           ((Dcm_MemMgrOpResultType)0x00U)
/* Memory access is not yet finished. */
#define DCM_MEMMGR_OP_RSLT_PENDING                      ((Dcm_MemMgrOpResultType)0x01U)
/* Memory access was not successful. */
#define DCM_MEMMGR_OP_RSLT_FAILED                       ((Dcm_MemMgrOpResultType)0x02U)
/* Memory access is not yet finished, the response pending transmission starts immediately. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_MEMMGR_OP_RSLT_FORCE_RCRRP                  ((Dcm_MemMgrOpResultType)0x03U)

/* Specifies the result of the Dcm_ReadMemory callout. */
/* Read of the memory was successful. */
#define DCM_READ_OK                                     DCM_MEMMGR_OP_RSLT_OK
/* Read of the memory is not yet finished. */
#define DCM_READ_PENDING                                DCM_MEMMGR_OP_RSLT_PENDING
/* Read of the memory was not successful. */
#define DCM_READ_FAILED                                 DCM_MEMMGR_OP_RSLT_FAILED
/* Read of the memory is not yet finished, the response pending transmission starts immediately. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_READ_FORCE_RCRRP                            DCM_MEMMGR_OP_RSLT_FORCE_RCRRP

/* Specifies the result of the Dcm_WriteMemory callout. */
/* Write to the memory was successful. */
#define DCM_WRITE_OK                                    DCM_MEMMGR_OP_RSLT_OK
/* Write to the memory is not yet finished. */
#define DCM_WRITE_PENDING                               DCM_MEMMGR_OP_RSLT_PENDING
/* Write to the memory was not successful. */
#define DCM_WRITE_FAILED                                DCM_MEMMGR_OP_RSLT_FAILED
/* Write to the memory is not yet finished, the response pending transmission starts immediately. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_WRITE_FORCE_RCRRP                           DCM_MEMMGR_OP_RSLT_FORCE_RCRRP

/* AuthenticationReturnParameter definitions */
/* Request was successful. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_REQUESTACCEPTED                  (0x00U)
/* Request was not successful. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_GENERALREJECT                    (0x01U)
/* Indicates the provided authentication configuration as Authentication
with PKI Certificate Exchange (APCE). */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AUTHCONFIGAPCE                   (0x02U)
/* Indicates the provided authentication configuration as Authentication
with Challenge-Response (ACR) and asymmetric cryptography. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AUTHCONFIGACRWITHASYCRY          (0x03U)
/* Indicates the provided authentication configuration as Authentication
with Challenge-Response (ACR) and symmetric cryptography. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_AUTHCONFIGACRWITHSYCRY           (0x04U)
/* DeAuthentication was successful, server is protected again. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_DEAUTH_SUCCESS                   (0x10U)
/* Certificate could be verified in first step, second step is pending. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_CERTVERIFYOWNSHIP                (0x11U)
/* Proof of Ownership could be verified, Authentication is complete. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_OWNSHIPAUTHCOMPLETE              (0x12U)
/* Certificate could be verified. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_CERTVERIFIED                     (0x13U)

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define Dcm_Config_Ptr                                  NULL_PTR

#if ( (DCM_SERVICE_01_ENABLED == STD_ON) || (DCM_SERVICE_09_ENABLED == STD_ON) || \
      (DCM_SERVICE_02_ENABLED == STD_ON) || (DCM_SERVICE_05_ENABLED == STD_ON) || \
      (DCM_SERVICE_06_ENABLED == STD_ON))
#define DCM_09_NUMOFDATAITER                            (0x01U)
#define DCM_MAX_OBD_DATALEN                             (0x06U)
#endif

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
#define DCM_OBD_DTC_ELEM                                 (0x02U)
#define DCM_OBD_DTC_LENGTH                               (0x02U)
#endif

#define DCM_3E_SID                                      (0x3EU)
#define DCM_3E_SUB80                                    (0x80U)
#define DCM_3E_SERVICELEN                               (0x02U)
#define DCM_STATE_TESTPRESENT_FALSE                     (0x00U)
#define DCM_STATE_TESTPRESENT_TRUE                      (0x01U)

#if ( DCM_SERVICE_22_ENABLED == STD_ON )
#define DCM_22_PROCESS_INIT_DID                         (0U)
#define DCM_22_PROCESS_READ_DID                         (1U)
#endif

#if ( DCM_SERVICE_27_ENABLED == STD_ON )
#define DCM_SEEDTRYTIME                                 (4U)
#define DCM_SEEDINVALID0                                (0x0U)
#define DCM_SEEDINVALIDF                                (0xFFU)
#define DCM_27_SEED_RECORD_LENGTH                       (8U)

#define DCM_27_DEFAULT_SEED                             (0x5AU)


#endif

#if ( (STD_ON == DCM_SERVICE_10_ENABLED) || (STD_ON == DCM_SERVICE_28_ENABLED) )
#define DCM_COMM_NORMALMSG                              (0x01U)
#define DCM_COMM_NMMSG                                  (0x02U)

#define DCM_COMM_ENABLE_RX_AND_TX                       (0x00U)
#define DCM_COMM_ENABLE_RX_AND_DISABLE_TX               (0x01U)
#define DCM_COMM_DISABLE_RX_AND_ENABLE_TX               (0x02U)
#define DCM_COMM_DISABLE_RX_AND_TX                      (0x03U)

#define DCM_COMM_ENABLE_RX_AND_TX_SUPPRESSPOS           (0x80U)
#define DCM_COMM_ENABLE_RX_AND_DISABLE_TX_SUPPRESSPOS   (0x81U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define DCM_COMM_DISABLE_RX_AND_ENABLE_TX_SUPPRESSPOS   (0x82U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define DCM_COMM_DISABLE_RX_AND_TX_SUPPRESSPOS          (0x83U)

#define DCM_COMM_SIGNAL_ENABLE_RX_AND_TX                (0xFFU)
#define DCM_COMM_SIGNAL_ENABLE_RX_AND_DISABLE_TX        (0xAAU)
#define DCM_COMM_SIGNAL_DISABLE_RX_AND_ENABLE_TX        (0x55U)
#define DCM_COMM_SIGNAL_DISABLE_RX_AND_TX               (0x00U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */

#define DCM_COMM_SIGNAL_NUM                             COM_PDUGRP_VECTOR_SIZE
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_COMM_SIGNAL_NUMPERCHANNEL                   (4U)
#endif

#if ( STD_ON == DCM_SERVICE_85_ENABLED )
#define DCM_COMM_ENABLE_DTC                             (0x01U)
#define DCM_COMM_DISALBE                                (0x02U)

#define DCM_COMM_ENABLE_DTC_SUPPRESSPOS                 (0x81U)
#define DCM_COMM_DISALBE_SUPPRESSPOS                    (0x82U)

#define DCM_RTE_MODE_ENABLEDTCSETTING                   (0x00U)
#define DCM_RTE_MODE_DISABLEDTCSETTING                  (0x01U)
#endif

#if ( STD_ON == DCM_SERVICE_23_ENABLED )
#define DCM_23_COPYSTEPLEN                              (256U)
#endif

#if ( STD_ON == DCM_SERVICE_34_ENABLED )
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_34_DATAFMTID                                (0x00U)
#endif

#if ( STD_ON == DCM_SERVICE_36_ENABLED )
#define DCM_36_MAXSEQNUM                                (0xFFU)
#endif

#if ( STD_ON == DCM_SERVICE_2A_ENABLED )
#define DCM_2A_TRANSMODE_SENDATSLOWRATE     (0x01U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_2A_TRANSMODE_SENDATMEDIUMRATE   (0x02U)
#define DCM_2A_TRANSMODE_SENDATFASTRATE     (0x03U)
#define DCM_2A_TRANSMODE_STOPSENDING        (0x04U)

#define DCM_2A_STOPSENDING                              (0x00U)
#define DCM_2A_STARTSENDING                             (0x01U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_2A_PROCESS_INIT_DID                         (0U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_2A_PROCESS_READ_DID                         (1U)
#endif

#if ( (STD_ON == DCM_SERVICE_2A_ENABLED) || (STD_ON == DCM_SERVICE_2C_ENABLED) )
#define DCM_PDID_HIGHBYTE                                (0xF2U)
#endif

#if ( STD_ON == DCM_SERVICE_2C_ENABLED )
#define DCM_2C_DDDID_BYDID                              (0x01U)
#define DCM_2C_DDDID_BYMEM                              (0x02U)
#define DCM_2C_DDDID_CLEAR                              (0x03U)
#define DCM_2C_SUB01_MINLENGTH                         (0x07U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_2C_SUB02_MINLENGTH                         (0x06U)
#endif

#if ( STD_ON == DCM_SERVICE_86_ENABLED )
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_86_GETEVENTTYPE(eventType)                 (uint8)(eventType & 0x3FU)
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_86_GETSTORAGESTATE(eventType)              (uint8)((eventType >> 6U) & 0x01U)
#define DCM_86_SUB00_STOPRESPONSEONEVENT               (0x00U)
#define DCM_86_SUB01_ONDTCCHANGE                       (0x01U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_86_SUB02_ONTIMERINTERRUPT                  (0x02U)
#define DCM_86_SUB03_ONCHANGEOFDATAIDENTIFIER          (0x03U)
#define DCM_86_SUB04_REPORTACTIVEDEVENTS               (0x04U)
#define DCM_86_SUB05_STARTRESPONSEONEVENT              (0x05U)
#define DCM_86_SUB06_CLEATRESPONSEONEVENT              (0x06U)
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_86_SUB07_ONCOMPARISONOFVALUES              (0x07U)

#define DCM_86_SUBFUNC_MASK                            (0x0FU)
#define DCM_86_SUBFUNC_INVALID                         (0x30U)
#define DCM_86_SUBFUNC_SUPPOS_OFFSET                   (0x07U)

/* [SWS_Dcm_00871] */
#define DCM_86_STATE_STOP                              (0x00U)
#define DCM_86_STATE_START                             (0x01U)
#define DCM_86_STATE_CLEAR                             (0x02U)

#define DCM_8601_SERVICETORESPONDTORECORD              (0x190EU)
#define DCM_8603_REQSID                                (0x22U)

#define DCM_ONDTCSTATUSCHANGE_EVENTTYPE                (0x01U)
#define DCM_ONCHANGEDID_EVENTTYPE                      (0x03U)

/* The number of saved events in the NvM. */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_86_INVALID_EVENTTYPE                       (0xFFU)
#define DCM_86_MOST_RECENT_CONFIMDTC_MASK              (0x08U)

/* Roe send states */
#define DCM_86_TX_STATE_IDLE                           (0x00U)
#define DCM_86_TX_STATE_SENDING                        (0x01U)
#define DCM_86_TX_STATE_WAIT_TIMEOUT                   (0x02U)

#define DCM_DSL_PROTOCOL_TYPE1                         (0x01U)
#define DCM_DSL_PROTOCOL_TYPE2                         (0x02U)
#endif

#define DCM_29_SID                                     (0x29U)

#if ( STD_ON == DCM_SERVICE_29_ENABLED )
#define DCM_29_INVALID_AUTHCONNID                      (0xFFFFU)
#define DCM_29_AUT_WHITELIST_MAXSIZE                   (0xFFU)
#define DCM_SUPPORT_COCO                               (0x00U)

#define DCM_29_MAXELEMTLEN                             (0x04U)
#define DCM_29_WHITELISTSERVICE                        (0x00U)
#define DCM_29_WHITELISTDID                            (0x01U)
#define DCM_29_WHITELISTRID                            (0x02U)

#define DCM_29_SERVICELEN                              (0x04U)
#define DCM_29_DIDLEN                                  (0x03U)
#define DCM_29_RIDLEN                                  (0x03U)

#define DCM_29_SID11                                   (0x11U)
#define DCM_29_SID22                                   (0x22U)
#define DCM_29_SID2E                                   (0x2EU)
#define DCM_29_SID31                                   (0x31U)
#define DCM_29_SID85                                   (0x85U)
#define DCM_29_SID10                                   (0x10U)
#define DCM_29_SID27                                   (0x27U)
#define DCM_29_SID28                                   (0x28U)
#define DCM_29_SID3E                                   (0x3EU)
#define DCM_29_SID19                                   (0x19U)
#define DCM_29_SID2F                                   (0x2FU)

#define DCM_29_SIDLEN                                  (0x01U)
#define DCM_29_SID11LEN                                (0x02U)
#define DCM_29_SID22LEN                                (0x03U)
#define DCM_29_SID2ELEN                                (0x03U)
#define DCM_29_SID31LEN                                (0x04U)
#define DCM_29_SID85LEN                                (0x02U)
#define DCM_29_SID10LEN                                (0x02U)
#define DCM_29_SID27LEN                                (0x02U)
#define DCM_29_SID28LEN                                (0x02U)
#define DCM_29_SID3ELEN                                (0x02U)
#define DCM_29_SID19LEN                                (0x02U)
#define DCM_29_SID2FLEN                                (0x03U)

#define DCM_29_DIDLISTMASK                             (~0x07U)
#define DCM_29_RIDLISTMASK                             (~0x07U)
#define DCM_29_RIDSTARTMASK                            (0x01U)
#define DCM_29_RIDSTOPMASK                             (0x02U)
#define DCM_29_RIDRESULTMASK                           (0x04U)
#define DCM_29_DID22MASK                               (0x01U)
#define DCM_29_DID2EMASK                               (0x02U)
#define DCM_29_DID2FMASK                               (0x04U)

#define DCM_SUPPORT_SUBFUNC                            (11U)

#define DCM_29_DEAUTH                                  (0x00U)
#define DCM_29_AUTH_SUCCESS                            (0x01U)

#define DCM_29_ALGORITHM_INDICATOR_LENGTH              (16U)
#define DCM_29_AUT_MAXSIZE                             (0xFFU)
#endif

#if ( STD_ON == DCM_SERVICE_3D_ENABLED )
#define DCM_3D_COPYSTEPLEN                              (256U)
#endif

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
#define DCM_11_SID                                      (0x11U)
#define DCM_BEFORE_RESET                                (0x00U)
#define DCM_AFTER_RESET                                 (0x01U)
#endif

#if (STD_ON == DCM_SERVICE_38_ENABLED)

#define DCM_38_SUB_REPLACEFILE                         (3U)
#define DCM_38_SUB_RESUMEFILE                          (6U)

#define DCM_38_SUB_LENTH                               (1U)
#define DCM_38_FILEPATHNAMELENTH_LENTH                 (2U)
#define DCM_38_DATAFORMATID_LENTH                      (1U)
#define DCM_38_FILESIZEPARALENTH_LENTH                 (1U)
#define DCM_38_FILEPOSITION_LENTH                      (8U)
#define DCM_38_MD5VALUE_LENTH                          (16U)
#define DCM_38_MAXNUMOFBLOCK_LENTH                     (4U)
#define DCM_38_MAXNUMOFBLOCK_LENTH_LEN                 (1U)
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( STD_ON == DCM_SERVICE_28_ENABLED )
#define DCM_28_CHECKTIMEOUT                              (6000U)
#endif

#if ( STD_ON == DCM_SERVICE_10_ENABLED )
#define DCM_10_CHECKTIMEOUT                              (6000U)
#endif

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
#define DCM_11_CHECKTIMEOUT                              (6000U)
#endif

#if ( (DCM_SPT_ADDRESSANDLENGTH_FORMAT & DCM_ADDRANDLENGTH_MASK) == DCM_FOUR )
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_GETADDRVALUE(srcData)   Dcm_Make32Bit((srcData)[DCM_ZERO], (srcData)[DCM_ONE],(srcData)[DCM_TWO], (srcData)[DCM_THREE])
#elif ( (DCM_SPT_ADDRESSANDLENGTH_FORMAT & DCM_ADDRANDLENGTH_MASK) == DCM_THREE)
#define DCM_GETADDRVALUE(srcData)   Dcm_Make32Bit(DCM_ZERO, srcData[DCM_ZERO], srcData[DCM_ONE], srcData[DCM_TWO])
#elif ( (DCM_SPT_ADDRESSANDLENGTH_FORMAT & DCM_ADDRANDLENGTH_MASK) == DCM_TWO )
#define DCM_GETADDRVALUE(srcData)   Dcm_Make16Bit(srcData[DCM_ZERO], srcData[DCM_ONE])
#elif ( (DCM_SPT_ADDRESSANDLENGTH_FORMAT & DCM_ADDRANDLENGTH_MASK) == DCM_ONE )
#define DCM_GETADDRVALUE(srcData)   srcData[DCM_ZERO]
#endif

#if ( ((DCM_SPT_ADDRESSANDLENGTH_FORMAT >> DCM_MEMORYSIZE_OFFSET) & DCM_ADDRANDLENGTH_MASK) == DCM_FOUR )
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define DCM_GETLENGTHVALUE(srcData)   Dcm_Make32Bit((srcData)[DCM_ZERO], (srcData)[DCM_ONE],(srcData)[DCM_TWO], (srcData)[DCM_THREE])
#elif ( ((DCM_SPT_ADDRESSANDLENGTH_FORMAT >> DCM_MEMORYSIZE_OFFSET) & DCM_ADDRANDLENGTH_MASK) == DCM_THREE)
#define DCM_GETLENGTHVALUE(srcData)   Dcm_Make32Bit(DCM_ZERO, srcData[DCM_ZERO], srcData[DCM_ONE], srcData[DCM_TWO])
#elif ( ((DCM_SPT_ADDRESSANDLENGTH_FORMAT >> DCM_MEMORYSIZE_OFFSET) & DCM_ADDRANDLENGTH_MASK) == DCM_TWO )
#define DCM_GETLENGTHVALUE(srcData)   Dcm_Make16Bit(srcData[DCM_ZERO], srcData[DCM_ONE])
#elif ( ((DCM_SPT_ADDRESSANDLENGTH_FORMAT >> DCM_MEMORYSIZE_OFFSET) & DCM_ADDRANDLENGTH_MASK) == DCM_ONE )
#define DCM_GETLENGTHVALUE(srcData)   srcData[DCM_ZERO]
#endif

#ifndef DCM_ENABLE_RX_TX_NORM
#define DCM_ENABLE_RX_TX_NORM (0U)
#endif

#ifndef DCM_ENABLE_RX_DISABLE_TX_NORM
#define DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
#endif

#ifndef DCM_DISABLE_RX_ENABLE_TX_NORM
#define DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
#endif

#ifndef DCM_DISABLE_RX_TX_NORMAL
#define DCM_DISABLE_RX_TX_NORMAL (3U)
#endif

#ifndef DCM_ENABLE_RX_TX_NM
#define DCM_ENABLE_RX_TX_NM (4U)
#endif

#ifndef DCM_ENABLE_RX_DISABLE_TX_NM
#define DCM_ENABLE_RX_DISABLE_TX_NM (5U)
#endif

#ifndef DCM_DISABLE_RX_ENABLE_TX_NM
#define DCM_DISABLE_RX_ENABLE_TX_NM (6U)
#endif

#ifndef DCM_DISABLE_RX_TX_NM
#define DCM_DISABLE_RX_TX_NM (7U)
#endif

#ifndef DCM_ENABLE_RX_TX_NORM_NM
#define DCM_ENABLE_RX_TX_NORM_NM (8U)
#endif

#ifndef DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
#endif

#ifndef DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
#endif

#ifndef DCM_DISABLE_RX_TX_NORM_NM
#define DCM_DISABLE_RX_TX_NORM_NM (11U)
#endif

/*UDS Version*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_ISO14229_2006 (1U)
#define DCM_ISO14229_2013 (2U)
#define DCM_ISO14229_2020 (3U)
/*
********************************************************************************
*    Global Types
********************************************************************************
*/
#if ( STD_ON == DCM_SERVICE_31_ENABLED )
enum
{
    Dcm_31_START = 0x01U,
    Dcm_31_STOP,
    Dcm_31_RESULT,
    Dcm_31_START_SUPPRESSPOS = 0x81U,
    Dcm_31_STOP_SUPPRESSPOS,
    Dcm_31_RESULT_SUPPRESSPOS,
};
#endif

#if ( STD_ON == DCM_SERVICE_2F_ENABLED )
enum
{
    RETURNCONTROLTOECU = 0x00,
    RESETTODEFAULT,
    FREEZECURRENTSTATE,
    SHORTTERMADJUSTMENT,
    RETURNCONTROLTOECU_SUPPRESSPOS = 0x80,
    RESETTODEFAULT_SUPPRESSPOS,
    FREEZECURRENTSTATE_SUPPRESSPOS,
    SHORTTERMADJUSTMENT_SUPPRESSPOS,
};
#endif

enum
{
    DCM_PHYSICAL = 1U,
    DCM_FUNCTIONAL,
    DCM_TA_ORTHER
};

#if ( DCM_SERVICE_19_ENABLED == STD_ON )
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define DCM_1902_DTCLEN   4U
#define DCM_1905_PID      (0xF4U)  /* SWS_Dcm_00388:The Dcm shall compose the DidId by adding 0xF400 to the Pid */
#define DCM_FUNGROUPID    (0x33U)  /* SWS_Dcm_01128:FunctionalGroupIdentifier is fixed to 0x33 in the 1942 service */
#define DCM_FORMATID_02   (0x02U)  /* DEM_DTC_TRANSLATION_SAEJ1939_73 */
#define DCM_FORMATID_04   (0x04U)  /* DEM_DTC_TRANSLATION_J2012DA_FORMAT_04 */
#endif

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
typedef struct
{
    uint8 Dcm_PidNum;
    uint8 Dcm_TypeInfo;/* Which is belong to Pid or supported Pid. */
} Dcm_01_RepeaterProxyContextType_st;

typedef enum
{
    DCM_NO_PID = 0U,
    DCM_PIDSET,
    DCM_SUPPORT_PIDSET
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Service01Type_e;
#endif /* (DCM_SERVICE_01_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
typedef struct
{
    uint8 Dcm_PidNum;
    uint8 Dcm_TypeInfo;/* Which is belong to Pid or supported Pid. */
} Dcm_02_RepeaterProxyContextType_st;

#endif /* (DCM_SERVICE_02_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_03_ENABLED )
typedef struct
{
    uint16 Dcm_DTCCode;
} Dcm_03_RepeaterProxyContextType_st;

#endif /* (DCM_SERVICE_03_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_07_ENABLED )
typedef struct
{
    uint16 Dcm_DTCCode;
} Dcm_07_RepeaterProxyContextType_st;
#endif /* (DCM_SERVICE_07_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
typedef struct
{
    uint8 Dcm_PidNum;
    uint8 Dcm_TypeInfo;/* Which is belong to Pid or supported Pid. */
} Dcm_09_RepeaterProxyContextType_st;

typedef enum
{
    DCM_09_NO_PID = 0U,
    DCM_09_PIDSET,
    DCM_09_SUPPORT_PIDSET
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Service09Type_e;
#endif /* (DCM_SERVICE_09_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_0A_ENABLED )
typedef struct
{
    uint16 Dcm_DTCCode;
} Dcm_0A_RepeaterProxyContextType_st;

#endif /* (DCM_SERVICE_0A_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_10_ENABLED )
typedef struct
{
    uint8 Dcm_ServiceNum;
} Dcm_10_RepeaterProxyContextType_st;
#endif /* (DCM_SERVICE_10_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
typedef struct
{
    uint32 sfIter;
    uint8 Dcm_ResetLevel;
} Dcm_11_RepeaterProxyContextType_st;
typedef enum
{
    DCM_11_CHK_IDLE = 0U,
    DCM_11_RSTNVMFLAG,
    DCM_11_SENDPOSRESP,
    DCM_11_CHK_FINISH,
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_11_ChkNvmStatType_en;
#endif /* (DCM_SERVICE_11_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_14_ENABLED )
typedef struct
{
    uint32 Dcm_DtcGroup;
    uint8 Dcm_MemSelection;
} Dcm_14_RepeaterProxyContextType_st;
#endif /* (DCM_SERVICE_14_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_22_ENABLED )
typedef struct
{
    uint8 Dcm_Progress;
    uint8 Dcm_DidCount;
    uint8 Dcm_CurDid;
    uint8* Dcm_ResData;
} Dcm_22_RepeaterProxyContextType_st;
#endif /* (DCM_SERVICE_22_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_2E_ENABLED )
typedef struct
{
    uint16    Dcm_CurDidHandle;
} Dcm_2E_RepeaterProxyContextType_st;
#endif /* (DCM_SERVICE_2E_ENABLED == STD_ON) */

#if ( STD_ON == DCM_SERVICE_27_ENABLED )
typedef struct
{
    uint8 Dcm_SecLevIdxOnGotSeed;
    boolean Dcm_MayExecuteSendKey;  /* Already received get seed request. */
} Dcm_g27_StateType_st;

typedef struct
{
    boolean Dcm_IsGetSeedRequest;   /* Wait for compare key flag .*/
} Dcm_27_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_27_ENABLED */

#if ( STD_ON == DCM_SERVICE_28_ENABLED )
typedef struct
{
    uint8 Dcm_Subfunc;
    uint8 Dcm_Comtype;
} Dcm_28_RepeaterProxyContextType_st;

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef void (*Dcm_CanIf_PduModeType_Channel_p)(uint8 PduMod);
#endif /* STD_ON == DCM_SERVICE_28_ENABLED */

#if ( STD_ON == DCM_SERVICE_85_ENABLED )
typedef struct
{
    uint8 Dcm_Subfunc;
} Dcm_85_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_85_ENABLED */

#if ( STD_ON == DCM_SERVICE_19_ENABLED )
typedef struct
{
    boolean Dcm_NeedsRecordUpdateDisabling;
    uint8 Dcm_Mask;
    uint8 Dcm_MemSelection;
    uint8 *Dcm_ResData;
    uint16 Dcm_AvailLen;
    uint16 Dcm_NumberOfFilteredRecords;
    uint32 Dcm_DtcNum;
    uint32 Dcm_SubFuncIter;
    uint8 Dcm_RecordNum;  /* DTCStoredDataRecordNumber */
} Dcm_19_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_19_ENABLED */

#if ( STD_ON == DCM_SERVICE_3E_ENABLED )
typedef struct
{
    uint8 Dcm_Subfunc;
} Dcm_3E_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_3E_ENABLED */

#if ( STD_ON == DCM_SERVICE_2F_ENABLED )
typedef struct
{
    uint32 sesIter;
    uint16 reqDataLength;
    uint8 Dcm_Subfunc;
} Dcm_2F_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_2F_ENABLED */

#if ( STD_ON == DCM_SERVICE_31_ENABLED )
typedef struct
{
    uint8 Dcm_Subfunc;
    uint32 Dcm_CurDidHandle;
}Dcm_31_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_31_ENABLED */

#if ( STD_ON == DCM_SERVICE_36_ENABLED )
typedef struct
{
    uint16* Dcm_ReqBufferLen;
    uint8* Dcm_ReqBuffer;
    uint8* Dcm_RespBuffer;
    uint16* Dcm_RespBufferLen;
    uint32 Dcm_MemoryAddress;
    uint32 Dcm_MemorySize;
} Dcm_36_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_36_ENABLED */

#if ( STD_ON == DCM_SERVICE_37_ENABLED )
typedef struct
{
    uint8* Dcm_RespBuffer;  /* Buffer data */
    uint16* Dcm_RespBufferLen;  /* Buffer length pointer */
    uint32 Dcm_RespBufferLenVal;  /* Buffer length value */
    uint32 Dcm_MemorySize;  /* Memory size */
} Dcm_37_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_37_ENABLED */

#if ( STD_ON == DCM_SERVICE_23_ENABLED )
typedef struct
{
    uint16 Dcm_MemoryIndx;
    uint32 Dcm_MemoryAddress;
    uint32 Dcm_MemorySize;
    uint32 Dcm_CpyLen;
} Dcm_23_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_23_ENABLED */

#if ( STD_ON == DCM_SERVICE_2A_ENABLED )
typedef struct
{
    uint16 Dcm_Did;
    uint8 Dcm_State;
    uint16 Dcm_Rate;
    uint16 Dcm_Timer;
    uint16 Dcm_DidLength;
    uint16 Dcm_DidHandle;
    Dcm_OpStatusType Dcm_OpStatus;
}Dcm_2A_Scheduler_st;

typedef struct
{
    uint8 Dcm_DidNum;
    uint8 Dcm_CurTransMod;
} Dcm_2A_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_2A_ENABLED */

#if (STD_ON == DCM_SERVICE_86_ENABLED)
typedef struct
{
    PduIdType RxPduId;
    PduIdType TxPduId;
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_86_DslDynInfo_st;

typedef struct
{
    uint8 Dcm_EventMask; /* EventType = onDTCStatusChange */
    uint16 Dcm_DidValue; /* EventType = onChangeOfDataIdentifier */
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_86_DslSendInfo_st;

typedef struct
{
    uint8 Dcm_StorageState;
} Dcm_86_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */

#if ( STD_OFF == DCM_SERVICE_NONE_ENABLED )
typedef struct
{
    uint8 Dcm_None;
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_00_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_NONE_ENABLED */

#if ( STD_ON == DCM_SERVICE_3D_ENABLED )
typedef struct
{
    uint16 Dcm_MemoryIndx;
    uint32 Dcm_MemoryAddress;
    uint32 Dcm_MemorySize;
    uint32 Dcm_CpyLen;
} Dcm_3D_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_3D_ENABLED */

#if ( STD_ON == DCM_SERVICE_29_ENABLED )
typedef struct
{
    uint16 Dcm_LengthOfChallenge;
    uint16 Dcm_lengthOfCert;
    uint8* Dcm_certPtr;
    uint8* resLenPtr;
    uint8* resRPPtr;
    uint8* Dcm_ChallengePtr;
    uint32 resLen;
    uint8 curSubSID;
    uint8 algorithmIndicator[DCM_29_ALGORITHM_INDICATOR_LENGTH];
} Dcm_29_RepeaterProxyContextType_st;

/* Store the parameter of authentication. */
typedef struct
{
    uint8 Dcm_VerifyCertFinish;        /* Indicate KeyM certificate verify state of asynchronous call. */
    uint8 Dcm_VerifyCertResult;        /* Indicate KeyM certificate verify result. */
    uint8 Dcm_VerifyCsmFinish;         /* Indicate Csm job state of asynchronous call. */
    uint8 Dcm_VerifyCsmResult;         /* Indicate Csm job result. */
    uint8 Dcm_AuthenticationSequence;  /* Authentication sequence of each connection. */
    uint8 Dcm_AuthState;               /* Authentication state(auth or deauth) of each connection. */
} Dcm_29_AuthParaType;
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if ( STD_ON == DCM_SERVICE_38_ENABLED )
typedef struct
{
    uint32 subFuncIndex;
    uint8 Dcm_Subfunc;
    uint8 dataFormatIdentifier;
}Dcm_38_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_38_ENABLED */

#if ( STD_ON == DCM_SERVICE_87_ENABLED )
typedef struct
{
    uint8 baudRateVaild;
    uint32 subFuncIdx;
}Dcm_87_RepeaterProxyContextType_st;
#endif /* STD_ON == DCM_SERVICE_87_ENABLED */

#if ( STD_OFF == DCM_SERVICE_NONE_ENABLED )
typedef struct
{

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
    Dcm_01_RepeaterProxyContextType_st Dcm_01_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
    Dcm_02_RepeaterProxyContextType_st Dcm_02_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_03_ENABLED )
    Dcm_03_RepeaterProxyContextType_st Dcm_03_ProxyContext;
#endif  /* STD_ON == DCM_SERVICE_03_ENABLED */

#if ( STD_ON == DCM_SERVICE_07_ENABLED )
    Dcm_07_RepeaterProxyContextType_st Dcm_07_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_07_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
    Dcm_09_RepeaterProxyContextType_st Dcm_09_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if ( STD_ON == DCM_SERVICE_0A_ENABLED )
    Dcm_0A_RepeaterProxyContextType_st Dcm_0A_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_0A_ENABLED */

#if ( STD_ON == DCM_SERVICE_10_ENABLED )
    Dcm_10_RepeaterProxyContextType_st Dcm_10_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_10_ENABLED */

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
    Dcm_11_RepeaterProxyContextType_st Dcm_11_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */

#if ( STD_ON == DCM_SERVICE_14_ENABLED )
    Dcm_14_RepeaterProxyContextType_st Dcm_14_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_14_ENABLED */

#if ( STD_ON == DCM_SERVICE_22_ENABLED )
    Dcm_22_RepeaterProxyContextType_st Dcm_22_ProxyContext;
#endif

#if ( STD_ON == DCM_SERVICE_2E_ENABLED )
    Dcm_2E_RepeaterProxyContextType_st Dcm_2E_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_2E_ENABLED */

#if ( STD_ON == DCM_SERVICE_27_ENABLED )
    Dcm_27_RepeaterProxyContextType_st Dcm_27_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_27_ENABLED */

#if ( STD_ON == DCM_SERVICE_28_ENABLED )
    Dcm_28_RepeaterProxyContextType_st Dcm_28_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_28_ENABLED */

#if ( STD_ON == DCM_SERVICE_85_ENABLED )
    Dcm_85_RepeaterProxyContextType_st Dcm_85_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_85_ENABLED */

#if ( STD_ON == DCM_SERVICE_19_ENABLED )
    Dcm_19_RepeaterProxyContextType_st Dcm_19_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_19_ENABLED */

#if ( STD_ON == DCM_SERVICE_3E_ENABLED )
    Dcm_3E_RepeaterProxyContextType_st Dcm_3E_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_3E_ENABLED */

#if ( STD_ON == DCM_SERVICE_2F_ENABLED )
    Dcm_2F_RepeaterProxyContextType_st Dcm_2F_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_2F_ENABLED */

#if ( STD_ON == DCM_SERVICE_31_ENABLED )
    Dcm_31_RepeaterProxyContextType_st Dcm_31_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_31_ENABLED */

#if ( STD_ON == DCM_SERVICE_34_ENABLED )
    Dcm_34_RepeaterProxyContextType_st Dcm_34_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_34_ENABLED */

#if ( STD_ON == DCM_SERVICE_36_ENABLED )
    Dcm_36_RepeaterProxyContextType_st Dcm_36_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_36_ENABLED */

#if ( STD_ON == DCM_SERVICE_37_ENABLED )
    Dcm_37_RepeaterProxyContextType_st Dcm_37_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_37_ENABLED */

#if ( STD_ON == DCM_SERVICE_23_ENABLED )
    Dcm_23_RepeaterProxyContextType_st Dcm_23_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_23_ENABLED */

#if ( STD_ON == DCM_SERVICE_2A_ENABLED )
    Dcm_2A_RepeaterProxyContextType_st Dcm_2A_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_2A_ENABLED */

#if ( STD_ON == DCM_SERVICE_86_ENABLED )
    Dcm_86_RepeaterProxyContextType_st Dcm_86_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_86_ENABLED */

#if ( STD_ON == DCM_SERVICE_87_ENABLED )
    Dcm_87_RepeaterProxyContextType_st Dcm_87_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_87_ENABLED */

#if ( STD_ON == DCM_SERVICE_3D_ENABLED )
    Dcm_3D_RepeaterProxyContextType_st Dcm_3D_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_3D_ENABLED */

#if ( STD_ON == DCM_SERVICE_29_ENABLED )
    Dcm_29_RepeaterProxyContextType_st Dcm_29_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if ( STD_ON == DCM_SERVICE_35_ENABLED )
    Dcm_35_RepeaterProxyContextType_st Dcm_35_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_35_ENABLED */

#if ( STD_ON == DCM_SERVICE_38_ENABLED )
    Dcm_38_RepeaterProxyContextType_st Dcm_38_ProxyContext;
#endif /* STD_ON == DCM_SERVICE_38_ENABLED */
}Dcm_RepeaterProxyContextPoolType_st;
#endif  /* STD_ON == DCM_SERVICE_NONE_ENABLED */

typedef void (*Dcm_TimerTimeoutCallBackType_p) (void);

typedef uint8 (*Dcm_RepeaterProxyFuncType_p)(void);

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef void (*Dcm_SetWLSubFunc_p)
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) elmtPrt,
    uint8 controlPara,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) errCodePtr
);

typedef struct
{
    PduInfoType  Dcm_pduInfo;
    uint8        Dcm_state;
} Dcm_PduTransportInfoType_st;


typedef struct
{
    Dcm_PduTransportInfoType_st Dcm_Base;
    uint16                      Dcm_TotalRequestLength;
    uint16                      Dcm_BuffPos;
    PduIdType Dcm_RxPduId;
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_PduRxTransportInfoType_st;

typedef struct
{
    Dcm_PduTransportInfoType_st Dcm_Base;
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_PduTxTransportInfoType_st;

typedef struct
{
    uint8 *Dcm_DataPtrRx;
    uint8 *Dcm_DataPtrTx;
    uint8 Dcm_AddrType;
    uint8 Dcm_ResType;
    uint8 Dcm_RcrRpState;
    uint8 Dcm_ContextState;
    uint8 Dcm_ServiceIndex;
    uint8 Dcm_PendingSessChgIdx;
    uint8 Dcm_ConcurrentTesterPresentState;
    uint16 Dcm_DataLengthRx;
    uint16 Dcm_DataLengthTx;
    uint16 Dcm_MaxBufferLength;
} Dcm_DslInfoPoolType_st;

typedef struct
{
    uint8 Dcm_CommState;  /* Dcm ComM state. */
} Dcm_StateMachineType_st;

typedef struct
{
    uint8 *Dcm_ReqData;
    uint8 *Dcm_ResData;
    uint16 Dcm_ReqDataLen;
    uint16 Dcm_ResDataLen;
    uint16 Dcm_ResMaxDataLen;
    uint8 Dcm_MsgAddInfo;
} Dcm_MsgContextType_st;

typedef uint8 Dcm_MemMgrOpResultType;
typedef Dcm_MemMgrOpResultType Dcm_ReturnReadMemoryType;
typedef Dcm_MemMgrOpResultType Dcm_ReturnWriteMemoryType;
typedef uint8 Dcm_InitStateType;
typedef boolean Dcm_NetActiveDiagnosticType;
typedef uint8 Dcm_EcuStartModeType;

typedef struct
{
    uint8 Dcm_Sid;
    uint8 Dcm_SubFuncLen;
    /* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Dcm_SubFuncInfo_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define DCM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"
extern VAR(Dcm_TimerSettingType_st, DCM_VAR_INIT) Dcm_DslTimerSettings;
extern VAR(Dcm_DslInfoPoolType_st, DCM_VAR_INIT) Dcm_DslInfoPool;
extern VAR(uint8, DCM_VAR_INIT) Dcm_DslBufferRcrRpTx[DCM_RCRRPTX_LEN];
extern VAR(uint16, DCM_VAR_INIT) Dcm_EvMgrEventRegisters[DCM_NUM_TASKS];
extern VAR(uint16, DCM_VAR_INIT)Dcm_PeriodicEvMgrEventRegisters[DCM_NUM_TASKS];
extern VAR(uint8, DCM_VAR_INIT) Dcm_EvMgrNumActiveTasks;
extern VAR(uint8, DCM_VAR_INIT) Dcm_PeriodiceEvMgrNumActiveTasks;
extern VAR(Dcm_StateMachineType_st, DCM_VAR_INIT) Dcm_ComMState;
extern VAR(uint8, DCM_VAR_INIT) Dcm_CurrentStateInfo[DCM_CURRENTSTATE_LEN];
extern VAR(uint8, DCM_VAR_INIT) Dcm_DsdErrorRegister;
extern VAR(Dcm_MsgContextType_st, DCM_VAR_INIT) Dcm_DsdMsgContext;
extern VAR(uint8, DCM_VAR_INIT) Dcm_ActiveTimerCounter;
extern VAR(Dcm_RepeaterProxyFuncType_p, DCM_VAR_INIT) Dcm_RepeatedProxyCallBack;
extern VAR(uint8, DCM_VAR_INIT) Dcm_SuppressBitFlag;

extern VAR(uint32, DCM_VAR_INIT) Dcm_TimerEngine[DCM_NUM_TIMERS_CONST];
extern VAR(uint8, DCM_VAR_INIT) Dcm_BufferUsedByAppL;
extern VAR(uint8, DCM_VAR_INIT) Dcm_Dslprotocolpriority;
extern VAR(Dcm_ProtocolType, DCM_VAR_INIT) Dcm_ActiveProtocol;
extern VAR(Dcm_InitStateType, DCM_VAR_INIT) Dcm_InitState;
extern VAR(Dcm_NetActiveDiagnosticType, DCM_VAR_INIT) Dcm_ActiveDiagnostic;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RespPendding_Counter;
extern VAR(uint8, DCM_VAR_INIT) Dcm_ReadBlockDone;
extern VAR(uint8, DCM_VAR_INIT) Dcm_DtcSettingStatus;
extern VAR(Dcm_TimerTimeoutCallBackType_p, DCM_VAR_INIT) Dcm_TimerManagerInfo[DCM_NUM_TIMERS_CONST];
// baoenfei ClearDTC
extern VAR(uint8, DCM_VAR_INIT) Dcm_SwcClearAllDtcReq;
// baoenfei 0x31 RCtrl
extern VAR(boolean, DCM_VAR_INIT) Dcm_RoutineReq_03E0;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RoutineResult_03E0;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RoutineFailResult_03E0;
extern VAR(boolean, DCM_VAR_INIT) Dcm_RoutineReq_03E1;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RoutineResult_03E1;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RoutineFailResult_03E1;
extern VAR(boolean, DCM_VAR_INIT) Dcm_RoutineReq_03E4;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RoutineResult_03E4;
extern VAR(uint8, DCM_VAR_INIT) Dcm_RoutineFailResult_03E4;

#if ( DCM_SERVICE_27_ENABLED == STD_ON )
extern VAR(uint8, DCM_VAR_INIT) Dcm_27_ActiveTimerCounter;
extern VAR(uint8, DCM_VAR_INIT) Dcm_SendKeyFlag[DCM_27_LEVEL_NUM + 1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_RequestSeedFlag[DCM_27_LEVEL_NUM + 1U];
extern VAR(uint8, DCM_VAR_INIT) Dcm_Default_Seed;
extern VAR(uint8, DCM_VAR_INIT) Dcm_ReadSecurity;
extern VAR(uint16, DCM_VAR_INIT) Dcm_27WriteTimeout;  /* Write NvM timeout. */
extern VAR(uint8, DCM_VAR_INIT) Dcm_LastSeed[DCM_27_LEVEL_NUM + 1U][DCM_27_MAX_SEED_LENGTH + 1U];
extern VAR(Dcm_g27_StateType_st, DCM_VAR_INIT) Dcm_SeedKeyProxyParam;
#endif /* DCM_SERVICE_27_ENABLED == STD_ON */

#if ( DCM_SERVICE_23_ENABLED == STD_ON )
extern VAR(uint16, DCM_VAR_INIT) Dcm_23WriteTimeout;  /* 23 routine control timeout. */
#endif /* DCM_SERVICE_23_ENABLED == STD_ON */

#if ( DCM_SERVICE_2E_ENABLED == STD_ON )
extern VAR(uint16, DCM_VAR_INIT) Dcm_2EWriteTimeout;
#endif /* DCM_SERVICE_2E_ENABLED == STD_ON */

#if ( DCM_SERVICE_31_ENABLED == STD_ON )
extern VAR(uint16, DCM_VAR_INIT) Dcm_31ResLength;  /* 31 routine control response length. */
extern VAR(uint16, DCM_VAR_INIT) Dcm_31WriteTimeout;  /* 31 routine control timeout. */
#endif /* DCM_SERVICE_31_ENABLED == STD_ON */

#if ( DCM_SERVICE_34_ENABLED == STD_ON )
extern VAR(uint16, DCM_VAR_INIT) Dcm_34WriteTimeout;  /* 34 routine control timeout. */
#endif /* DCM_SERVICE_34_ENABLED == STD_ON */

#if ( DCM_SERVICE_36_ENABLED == STD_ON )
extern VAR(uint8, DCM_VAR_INIT) Dcm_36_LastSeqNum;
extern VAR(uint16, DCM_VAR_INIT) Dcm_36WriteTimeout;  /* 36 routine control timeout. */
#endif /* DCM_SERVICE_36_ENABLED == STD_ON */

#if ( DCM_SERVICE_37_ENABLED == STD_ON )
extern VAR(uint16, DCM_VAR_INIT) Dcm_37WriteTimeout;  /* 37 routine control timeout. */
#endif /* DCM_SERVICE_37_ENABLED == STD_ON */

#if ( ( DCM_SERVICE_34_ENABLED == STD_ON ) || ( DCM_SERVICE_35_ENABLED == STD_ON ) || ( DCM_SERVICE_36_ENABLED == STD_ON )\
    || ( DCM_SERVICE_37_ENABLED == STD_ON ) )
extern VAR(uint32, DCM_VAR_INIT) Dcm_DownloadTotalLength;
extern VAR(uint8, DCM_VAR_INIT) Dcm_34_Requested;
extern VAR(uint8, DCM_VAR_INIT) Dcm_35_Requested;
extern VAR(uint8, DCM_VAR_INIT) Dcm_36_Requested;
#endif

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
extern VAR(uint8, DCM_VAR_INIT) Dcm_01_PidList[DCM_MAX_OBD_DATALEN];
#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
/* Polyspace +1 MISRA-C3:8.6 [Justified:Unset] "NSCA_Polyspace_Dcm_8.6" */
extern VAR(uint8, DCM_VAR_INIT) Dcm_02_PidList[DCM_MAX_OBD_DATALEN];
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
extern VAR(uint8, DCM_VAR_INIT) Dcm_09_PidList[DCM_MAX_OBD_DATALEN];
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if ( STD_ON == DCM_SERVICE_31_ENABLED )
extern VAR(uint8, DCM_VAR_INIT) Dcm_31_ActiveList[DCM_31_SUBID_NUM];
#endif /* STD_ON == DCM_SERVICE_31_ENABLED */

#if ( STD_ON == DCM_SERVICE_2A_ENABLED )
extern VAR(uint16, DCM_VAR_INIT) Dcm_2A_SchdIdx;
extern VAR(Dcm_2A_Scheduler_st, DCM_VAR_INIT) Dcm_2A_SchdTable[DCM_2A_SCHEDULER_SIZE];
extern VAR(uint8, DCM_VAR_INIT) Dcm_2A_DidList[DCM_2A_SCHEDULER_SIZE];
#endif /* STD_ON == DCM_SERVICE_2A_ENABLED */

#define DCM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"

#if ( STD_OFF == DCM_SERVICE_NONE_ENABLED )
extern VAR(Dcm_RepeaterProxyContextPoolType_st, DCM_VAR_NO_INIT) Dcm_RepeatedProxyContexts;
#endif

#define DCM_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"
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
#define DCM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"

extern FUNC(void, DCM_CODE) Dcm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_APPL_DATA) versioninfo);
extern FUNC(void, DCM_CODE) Dcm_OnChgStateSession(uint8 stateGroupIdx, uint8 newStateIdx);
extern FUNC(void, DCM_CODE) Dcm_DspInitDummyService(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_DspPostDummyService(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_OnTimeoutResponsePending(void);
extern FUNC(void, DCM_CODE) Dcm_TmrMgrStartTimer(uint8 timerId, uint32 ticks);
extern FUNC(void, DCM_CODE) Dcm_TmrMgrResetTimer(uint8 timerId, uint32 ticks);
extern FUNC(void, DCM_CODE) Dcm_SetNegResponse(uint8 errorCode);
extern FUNC(void, DCM_CODE) Dcm_TmrMgrInit(void);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityAttemptCounter
(
    uint8 secLvlIdx,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType opStatus,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) attemptCounter
);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetSecurityAttemptCounter
(
    uint8 secLvlIdx,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType opStatus,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    uint8 attemptCounter
);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_TxConfirmation(PduIdType txPduId);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_HandleSuppressBitFunc(uint8 subFunc);
extern FUNC(Dcm_ReturnReadMemoryType, DCM_CODE) Dcm_ReadMemory
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) MemoryData,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

extern FUNC(Dcm_EcuStartModeType, DCM_CODE) Dcm_GetProgConditions(P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions);
extern FUNC(Std_ReturnType, DCM_CODE) Xxx_GetScalingInformation
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ScalingInfo,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

#if ( (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED)|| (STD_ON == DCM_SERVICE_2C_ENABLED) )
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(uint32, DCM_CODE) Dcm_FindDid(uint16 did);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(uint8, DCM_CODE) Dcm_SetDidBuffer(uint16 did, Dcm_OpStatusType opStatus, uint16 length, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) srcData);
extern FUNC(uint8, DCM_CODE) Dcm_GetDidUsed(uint32 didIndex);
#endif /* (STD_ON == DCM_SERVICE_22_ENABLED) || (STD_ON == DCM_SERVICE_2E_ENABLED) || (STD_ON == DCM_SERVICE_2A_ENABLED)|| (STD_ON == DCM_SERVICE_2C_ENABLED) */

#if ( STD_ON == DCM_SERVICE_01_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_01_Init(void);
extern FUNC(void, DCM_CODE) Dcm_01_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_01_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_01_ENABLED */

#if ( STD_ON == DCM_SERVICE_02_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_02_Init(void);
extern FUNC(void, DCM_CODE) Dcm_02_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_02_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_02_ENABLED */

#if ( STD_ON == DCM_SERVICE_03_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_03_Init(void);
extern FUNC(void, DCM_CODE) Dcm_03_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_03_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_03_ENABLED */

#if ( STD_ON == DCM_SERVICE_04_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_04_Init(void);
extern FUNC(void, DCM_CODE) Dcm_04_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_04_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_04_ENABLED */

#if ( STD_ON == DCM_SERVICE_05_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_05_Init(void);
extern FUNC(void, DCM_CODE) Dcm_05_Process(void);
extern FUNC(void, DCM_CODE) Dcm_05_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_05_ENABLED */

#if ( STD_ON == DCM_SERVICE_06_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_06_Init(void);
extern FUNC(void, DCM_CODE) Dcm_06_Process(void);
extern FUNC(void, DCM_CODE) Dcm_06_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_06_ENABLED */

#if ( STD_ON == DCM_SERVICE_07_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_07_Init(void);
extern FUNC(void, DCM_CODE) Dcm_07_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_07_PostProcess(uint8 status);
#endif

#if ( STD_ON == DCM_SERVICE_09_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_09_Init(void);
extern FUNC(void, DCM_CODE) Dcm_09_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_09_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_09_ENABLED */

#if ( STD_ON == DCM_SERVICE_0A_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_0A_Init(void);
extern FUNC(void, DCM_CODE) Dcm_0A_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_0A_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_0A_ENABLED */

#if ( STD_ON == DCM_SERVICE_10_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_10_Init(void);
extern FUNC(void, DCM_CODE) Dcm_10_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_10_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_10_ENABLED */

#if ( STD_ON == DCM_SERVICE_11_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_11_Process(void);
extern FUNC(void, DCM_CODE) Dcm_11_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_11_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_11_ENABLED */

#if ( STD_ON == DCM_SERVICE_14_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_14_Process(void);
extern FUNC(void, DCM_CODE) Dcm_14_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_14_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_14_ENABLED */

#if ( STD_ON == DCM_SERVICE_19_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_19_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_19_PostProcess(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_19_Init(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1901_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1902_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1903_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1904_Process(void);
#if( DCM_DEM_OBD_SUPPORT == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_Dsp_1905_Process(void);
#endif  /* DCM_DEM_OBD_SUPPORT == STD_ON */
extern FUNC(void, DCM_CODE) Dcm_Dsp_1906_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1907_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1908_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1909_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1912_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1913_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1917_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1918_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1919_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_190A_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_190C_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_190E_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_1914_Process(void);
#if( DCM_DEM_OBD_SUPPORT == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_Dsp_1942_Process(void);
#endif  /* DCM_DEM_OBD_SUPPORT == STD_ON */
extern FUNC(void, DCM_CODE) Dcm_Dsp_1955_Process(void);
#endif /* STD_ON == DCM_SERVICE_19_ENABLED */

#if ( STD_ON == DCM_SERVICE_22_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_22_Process(void);
extern FUNC(void, DCM_CODE) Dcm_22_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_22_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_22_ENABLED */

#if ( STD_ON == DCM_SERVICE_27_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_27_Process(void);
extern FUNC(void, DCM_CODE) Dcm_27_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_27_PostProcess(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_DspSecurityTimer(uint8 secLvlIdx);
extern FUNC(uint8, DCM_CODE) Dcm_GetSeed(uint8 secLvlIdx, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) securitySeed);
#endif /* STD_ON == DCM_SERVICE_27_ENABLED */

#if ( STD_ON == DCM_SERVICE_28_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_28_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_28_PostProcess(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_28_Init(void);
#endif /* STD_ON == DCM_SERVICE_28_ENABLED */

#if ( STD_ON == DCM_SERVICE_2E_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_2E_Process(void);
extern FUNC(void, DCM_CODE) Dcm_2E_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_2E_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_2E_ENABLED */

#if ( STD_ON == DCM_SERVICE_2F_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_2F_Process(void);
extern FUNC(void, DCM_CODE) Dcm_2F_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_2F_PostProcess(uint8 status);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(uint32, DCM_CODE) Dcm_FindInputOutputDid(uint16 did);
#endif /* STD_ON == DCM_SERVICE_2F_ENABLED */

#if ( STD_ON == DCM_SERVICE_31_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_31_Process(void);
extern FUNC(void, DCM_CODE) Dcm_31_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_31_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_31_ENABLED */

#if ( STD_ON == DCM_SERVICE_3E_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_3E_Process(void);
extern FUNC(void, DCM_CODE) Dcm_3E_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_3E_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_3E_ENABLED */

#if ( STD_ON == DCM_SERVICE_85_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_85_Process(void);
extern FUNC(void, DCM_CODE) Dcm_85_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_85_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_85_ENABLED */

#if ( STD_ON == DCM_SERVICE_87_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_87_Process(void);
extern FUNC(void, DCM_CODE) Dcm_87_Init(void);
extern FUNC(void, DCM_CODE) Dcm_87_PostProcess(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_Dsp_8701_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_8702_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_8703_Process(void);
#endif /* STD_ON == DCM_SERVICE_87_ENABLED */

#if (STD_ON == DCM_SERVICE_83_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_83_Process(void);
extern FUNC(void, DCM_CODE) Dcm_83_Init(void);
extern FUNC(void, DCM_CODE) Dcm_83_PostProcess(uint8 Status);
#endif

#if (STD_ON == DCM_SERVICE_34_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_34_Process(void);
extern FUNC(void, DCM_CODE) Dcm_34_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_34_PostProcess(uint8 status);
#endif

#if (STD_ON == DCM_SERVICE_36_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_36_Process(void);
extern FUNC(void, DCM_CODE) Dcm_36_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_36_PostProcess(uint8 status);
#endif

#if (STD_ON == DCM_SERVICE_37_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_37_Process(void);
extern FUNC(void, DCM_CODE) Dcm_37_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_37_PostProcess(uint8 status);
#endif

#if ( DCM_SERVICE_23_ENABLED == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_23_Process(void);
extern FUNC(void, DCM_CODE) Dcm_23_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_23_PostProcess(uint8 status);
#endif /* DCM_SERVICE_23_ENABLED == STD_ON */

#if ( DCM_SERVICE_2A_ENABLED == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_2A_Process(void);
extern FUNC(void, DCM_CODE) Dcm_2A_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_2A_PostProcess(uint8 status);
#endif /* DCM_SERVICE_2A_ENABLED == STD_ON */

#if ( DCM_SERVICE_2C_ENABLED == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_2C_Process(void);
extern FUNC(void, DCM_CODE) Dcm_2C_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_2C_PostProcess(uint8 status);
extern FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_2C_ReadDDDidDataLength(uint32 didIdx, P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) dataLength);
extern FUNC(Dcm_NegativeResponseCodeType, DCM_CODE) Dcm_2C_ReadDDDidData(uint32 didIdx, P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) destdata);
#endif /* DCM_SERVICE_2C_ENABLED == STD_ON */

#if ( DCM_SERVICE_86_ENABLED == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_86_Process(void);
extern FUNC(void, DCM_CODE) Dcm_86_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_86_PostProcess(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_DspRoeEventTimer(void);
#endif /* DCM_SERVICE_86_ENABLED == STD_ON */

#if ( DCM_SERVICE_3D_ENABLED == STD_ON )
extern FUNC(void, DCM_CODE) Dcm_3D_Process(void);
extern FUNC(void, DCM_CODE) Dcm_3D_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_3D_PostProcess(uint8 status);
#endif /* DCM_SERVICE_3D_ENABLED == STD_ON */

#if ( STD_ON == DCM_SERVICE_29_ENABLED )
extern FUNC(void, DCM_CODE) Dcm_29_Process(void);
extern FUNC(void, DCM_CODE) Dcm_29_PostProcess(uint8 status);
extern FUNC(void, DCM_CODE) Dcm_29_Init(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2900_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2901_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2902_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2903_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2908_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2904_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2905_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2906_Process(void);
extern FUNC(void, DCM_CODE) Dcm_Dsp_2907_Process(void);
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_KeyMAsyncCertificateVerifyFinished
(
    KeyM_CertificateIdType CertID,
    KeyM_CertificateStatusType Result
);
extern FUNC(void, DCM_CODE) Dcm_CsmAsyncJobFinished
(
    uint32 jobId,
    Csm_ResultType result
);
#endif /* STD_ON == DCM_SERVICE_29_ENABLED */

#if (STD_ON == DCM_SERVICE_35_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_35_Process(void);
extern FUNC(void, DCM_CODE) Dcm_35_Init(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_35_PostProcess(uint8 status);
#endif /* STD_ON == DCM_SERVICE_35_ENABLED */

#if (STD_ON == DCM_SERVICE_38_ENABLED)
extern FUNC(void, DCM_CODE) Dcm_38_Init(void);
extern FUNC(void, DCM_CODE) Dcm_38_Process(void);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_Dcm_Dir4.5" */
extern FUNC(void, DCM_CODE) Dcm_38_PostProcess(uint8 status);
#endif/* STD_ON == DCM_SERVICE_38_ENABLED */

#define DCM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "Dcm_MemMap.h"

#endif  /* DCM_H_ */
