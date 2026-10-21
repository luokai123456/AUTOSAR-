/*
********************************************************************************
*
*  File name:   Xcp.c
*
*  Copyright    Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Sunpengfei/2018.07.10
* Change: New created
* Cause: New
********************************************************************************
* Version: 2.0
* Author/Date: fangtao/2020.01.17
* Change: Modify part of the code
* 1. Remove the number of devil in the code.
* 2. Modify local variables and structures that have no meaning.
* 3. If there is a goto statement, remove it.
* 4. function can only have one exit. (Misra-c)
* 5. Add comments as appropriate and use English.
* Cause: Update
********************************************************************************
* Version: 2.1
* Author/Date: fangtao/2020.02.25
* Change: Modify part of the code
* Cause: Update
********************************************************************************
* Version: 2.2
* Author/Date: fangtao/2020.03.12
* Change: Modify code based on configuration.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: zhangyong/2020.03.27
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: zhangyong/2020.05.29
* Change: Delete index = XCP_FIVE;
* Cause: Update to V3.1
********************************************************************************
* Version: 3.2
* Author/Date: fangtao/2020.08.11
* Change:
* 1. Configuration items available.
* 2. Implement block transfer function.
* 3. Add time stamp function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.3
* Author/Date: fangtao/2020.08.21
* Change:
* 1. Remove continue from the code.
* 2. Add Det function.
* Cause: Bugfix.
********************************************************************************
* Version: 3.4
* Author/Date: fangtao/2020.09.15
* Change: Modify the function name according to the AUTOSAR specification, add
*         MemMap.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: fangtao/2020.10.12
* Change: Change Xcp_Main to Xcp_MainFunction.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: FangT/2021.03.03
* Change: Add checksum and Multi pudid functions.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: FangT/2021.06.30
* Change: Modify code specifications.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: FangT/2021.07.14
* Change: Add header file SchM_Xcp.h.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: FangT/2021.07.19
* Change: Modify ApplXcpGetTimestamp local parameters.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date : FangT/2021.08.18
* Change: Modify the code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date : FangT/2021.08.31
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date : FangT/2021.09.01
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date : FangT/2021.10.20
* Change: Modify the ether reply question.
* Cause: Optimization
********************************************************************************
* Version: 3.14
* Author/Date : FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date : FangT/2021.11.1
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date : FangT/2021.11.3
* Change: 1.Modify the timestamp acquisition problem.
*         2.Add relative Odt identification function.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date : FangT/2021.11.23
* Change:Resolve eth count errors.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date : FangT/2021.12.6
* Change: 1.Timestamp judgment condition plus priority brackets.
*         2.Modify the default page.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date : FangT/2021.12.13
* Change: 1.Modify the address offset mode and request the DAQ information again
*         after the page is switched. The address is incorrect.
*         2.Reinitialize the work page when disconnected.
*         3.Xcp_Init_cal_page change to Xcp_InitCalPage.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date : FangT/2021.12.17
* Change: 1.Add type conversion when pointer data is used.
*         2.Modify the length of the single-pointer RAM buffer to be configurable.
* Cause: Optimization
********************************************************************************
* Version: 3.20
* Author/Date : FangT/2021.12.23
* Change: Single-pointer calibration, the address will not be
*         incremented when the read/write range is exceeded.
* Cause: Optimization
********************************************************************************
* Version: 3.21
* Author/Date : FangT/2022.03.01
* Change: 1.ODT data transmission is not connected.
*         2.Alloc Odt Modify the error judgment order.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date : FangT/2022.03.16
* Change: 1.Modify the byte order of the Ethernet sending data header
*         2.Change the send length to uint32 type.
*         3.Modify code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date : ShiRong/2022.06.21
* Change: Clear compile warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date : ShiRong/2022.09.16
* Change: Add XcpOnCANFD function.
* Cause: Update
*******************************************************************************
* Version: 3.25
* Author/Date : ShiRong/2022.10.12
* Change: 1.Modifying the Comment Mode.
* Cause: Update
*******************************************************************************
* Version: 3.26
* Author/Date : ShiRong/2022.11.3
* Change: 1.Modifying the  four bite time stamp .
* Cause: Update
*******************************************************************************
* Version: 3.27
* Author/Date : ShiRong/2022.11.28
* Change: 1.Modify the bug with mismatched parentheses .
*         2.Add XCP_DAQMEMSIZE Configuration Item
* Cause: Update
*******************************************************************************
* Version: 3.28
* Author/Date : ShiRong/2022.12.22
* Change: The modified ethereal measurement cannot exceed 255.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date : ShiRong/2023.02.09
* Change: 1.Add STIM function.
*         2.Add structure calibration method.
*         3.Add the observation method of collecting while sending.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date : ShiRong/2023.02.13
* Change: 1.Delete redundant comments.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date : ShiRong/2023.02.13
* Change: 1.Remove compilation warnings.
* Cause: Update
********************************************************************************
* Version: 3.32
* Author/Date : ShiRong/2023.03.09
* Change: 1.Modify the data processing of STIM function.
* Cause: Bugfix
********************************************************************************
* Version: 3.33
* Author/Date : ShiRong/2023.03.13
* Change: 1.Remove warning.
* Cause: Optimization
********************************************************************************
* Version: 3.34
* Author/Date : ShiRong/2023.03.21
* Change: 1.Modify the data type for the STIM function to calculate the queue size.
*         2.Modify some logic of the STIM function.
*         3.Enable XCP_ ODT_ ENTRY_ SIZE_ Functions of STIM macros.
* Cause: Bugfix.
********************************************************************************
* Version: 3.35
* Author/Date : ShiRong/2023.04.16
* Change: Add security algorithm functionality.
* Cause: Update.
********************************************************************************
* Version: 3.36
* Author/Date : ShiRong/2023.05.06
* Change: 1.Add Block Transfer Mode.
*         2.Remove excess code.
* Cause: Update.
********************************************************************************
* Version: 3.37
* Author/Date : ShiRong/2023.05.12
* Change: 1.Add storage RAM scaling to NVM functionality.
* Cause: Update.
********************************************************************************
* Version: 3.38
* Author/Date : ShiRong/2023.05.16
* Change: The issue of modifying the polyspace.
* Cause: Optimization.
********************************************************************************
* Version: 3.39
* Author/Date : ShiRong/2023.05.19
* Change: 1.Add error replies related to security algorithms.
*         2.Fix timestamp adaptation byte alignment issues with STIM functionality.
* Cause: Bugfix.
********************************************************************************
* Version: 3.40
* Author/Date : ShiRong/2023.05.23
* Change: Modifying NVM Configuration Reference Issues.
* Cause: Bugfix.
********************************************************************************
* Version: 3.41
* Author/Date : ShiRong/2023.05.31
* Change: The issue of missing address retrieval in modifying STIM timestamp code writing.
* Cause: BugFix.
********************************************************************************
* Version: 3.42
* Author/Date : ShiRong/2023.06.25
* Change: Modifying single pointer calibration byte alignment issues.
* Cause: BugFix.
********************************************************************************
* Version: 3.43
* Author/Date : ShiRong/2023.08.01
* Change: 1.Add verification algorithms for XCP_ADD11 and XCP_CRC32.
*         2.Add flash writing function.
*         3.Add overlay calibration function.
* Cause: Update.
********************************************************************************
* Version: 3.44
* Author/Date : ShiRong/2023.08.02
* Change: Add sending confirmation timeout judgment function.
* Cause: Update.
********************************************************************************
* Version: 3.45
* Author/Date : ShiRong/2023.08.04
* Change: Modify compilation issues caused by validation enabled configuration items.
* Cause: Update.
********************************************************************************
* Version: 3.46
* Author/Date : ShiRong/2023.08.16
* Change: Modifying Compilation Warning Issues.
* Cause: Update.
********************************************************************************
* Version: 3.47
* Author/Date : ShiRong/2023.08.17
* Change: 1.Modifying compilation issues when seed is enabled.
*         2.The sending confirmation time affects the block transmission function.
* Cause: Update.
********************************************************************************
* Version: 3.48
* Author/Date : ShiRong/2023.08.28
* Change: 1.The sending confirmation time affects the block transmission function.
* Cause: BugFix.
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Xcp.h"
#include "Os.h"
#include "SchM_Xcp.h"
#include "status.h"  //manual_code_zsh
#include "flash_lld.h"  //manual_code_zsh
//#include "overlay.h" //manual_code_whz
#include "Xcp_Swc.h"
#include "CCFC3011PT.h"

#if( XCP_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

#if( RTECALIBRATIONSUPPORT != RTE_MMU_METHOD )
#include "Rte.h"
#include "Rte_Type.h"
#endif

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
#include "Calibration.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
#define XCP_START_SEC_VAR_INIT
#include "Xcp_MemMap.h"

static VAR(uint8, XCP_VAR_INIT) Xcp_StationId[XCP_STATIONIDLENGTH] = XCP_STATIONIDSTRING;
static VAR(uint8, XCP_VAR_INIT) Xcp_Pending = XCP_ZERO;
static VAR(uint8, XCP_VAR_INIT) Xcp_CalPage = XCP_ONE;
static VAR(uint8, XCP_VAR_INIT) Xcp_WorkingPage = XCP_ZERO;
#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
static VAR(uint8, XCP_VAR_INIT) Xcp_ReadBlockDone = FALSE;
#endif
#if( XCP_ENABLE_SEED_KEY == STD_ON )
static VAR(uint16, XCP_VAR_INIT) Xcp_SafeLen = XCP_ZERO;
static VAR(uint16, XCP_VAR_INIT) Xcp_SafeAddLen = XCP_ZERO;
static VAR(boolean, XCP_VAR_INIT) Xcp_SafeSeedFlag = FALSE;
static VAR(boolean, XCP_VAR_INIT) Xcp_SafeFlag = FALSE;
#endif

#if( XCP_ONETHERNET_ENABLE == STD_ON )
static VAR(uint16, XCP_VAR_INIT) Xcp_EthCtrTx = XCP_ZERO;
#if( STD_ON == XCP_ENABLE_SEND_QUEUE )
static VAR(uint8, XCP_VAR_INIT) Xcp_FirstDaqFlag = XCP_ZERO;
#endif
static VAR(uint8,XCP_VAR_INIT) Xcp_EthResData[XCP_MAX_CTO + XCP_FOUR] = {XCP_ZERO};
#endif
/* Single pointer calibration data */
#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
/* The data needs to be generated in the calibration RAM area */
static VAR(uint8, XCP_VAR_INIT) Xcp_CalibGroupParaRamBuf[SINGCALRAM_SIZE] = {0U};
static P2VAR(uint8, XCP_VAR_INIT, XCP_APPL_DATA) Xcp_CalibGroupPtCnt = &Xcp_CalibGroupParaRamBuf[0];
#endif

#define XCP_STOP_SEC_VAR_INIT
#include "Xcp_MemMap.h"

#define XCP_START_SEC_VAR_NO_INIT
#include "Xcp_MemMap.h"

static VAR(XCP_Data_st, XCP_VAR_NO_INIT) Xcp_Data;

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
static VAR(Xcp_Addr_st, XCP_VAR_NO_INIT) Xcp_Addr;
#endif

#if( XCP_ENABLE_SEED_KEY == STD_ON )
static VAR(uint8, XCP_VAR_NO_INIT) Xcp_Resource;
#endif

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
static VAR(Xcp_VectList_st, XCP_VAR_NO_INIT) Xcp_VectList;
static VAR(Xcp_DownloadCopy_t, XCP_VAR_NO_INIT) Xcp_DownLoadCopyState;
static VAR(uint32, XCP_VAR_NO_INIT) Xcp_CalRamInfoMem[XCP_FIVE];
#endif

#define XCP_STOP_SEC_VAR_NO_INIT
#include "Xcp_MemMap.h"

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
static FUNC_P2VAR(uint8, XCP_CODE, XCP_APPL_DATA) Xcp_GetPointer
(
    uint8 extAddr,uint32 addr
);
static FUNC(uint8, XCP_CODE) Xcp_WriteMta
(
    uint8 size,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)data
);
static FUNC(uint8, XCP_CODE) Xcp_ReadMta
(
    uint8 size,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)data
);
#if defined (XCP_ENABLE_SEND_EVENT) && ( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
static FUNC(void, XCP_CODE) Xcp_SendEv(void);
#endif

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
static FUNC(void, XCP_CODE) Xcp_QueueInit(void);

#if (MULTIPDUIDSUPPORT == STD_ON )
static FUNC(uint8, XCP_CODE) Xcp_SendDtoFromQueue(uint8 eventid);
#else
static FUNC(uint8, XCP_CODE) Xcp_SendDtoFromQueue(void);
#endif

#endif

#ifdef XCP_ENABLE_DAQ
static FUNC(void, XCP_CODE) Xcp_FreeDaq(void);
static FUNC(uint8, XCP_CODE) Xcp_AllocMemory(void);
static FUNC(uint8, XCP_CODE) Xcp_AllocDaq(uint8 daqCount);
static FUNC(uint8, XCP_CODE) Xcp_AllocOdt(uint8 daq, uint8 odtCount);
static FUNC(uint8, XCP_CODE) Xcp_AllocOdtEntry
(
    uint8 daq, uint8 odt, uint8 odtEntryCount
);
static FUNC(void, XCP_CODE) Xcp_StartDaq(uint8 daq);
static FUNC(void, XCP_CODE) Xcp_StartAllSelectedDaq(void);
static FUNC(void, XCP_CODE) Xcp_StopDaq(uint8 daq);
static FUNC(void, XCP_CODE) Xcp_StopAllSelectedDaq(void);
static FUNC(void, XCP_CODE) Xcp_StopAllDaq(void);
#endif

#ifdef XCP_ENABLE_STIM
static FUNC(uint8, XCP_CODE) Xcp_AllocStimQueueMemory(void);
#endif

static FUNC(void, XCP_CODE) Xcp_CC_Sync(void);

#ifdef XCP_ENABLE_COMM_MODE_INFO
static FUNC(void, XCP_CODE) Xcp_CC_GetCommModeInfo(void);
#endif

static FUNC(void, XCP_CODE) Xcp_CC_Disconnect(void);
static FUNC(void, XCP_CODE) Xcp_CC_GetID
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_GetStatus(void);

#if( XCP_ENABLE_SEED_KEY == STD_ON )
static FUNC(void, XCP_CODE) Xcp_CC_GetSeed
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_UnLock
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif

#ifdef XCP_ENABLE_CALIBRATION_PAGE
static FUNC(void, XCP_CODE) Xcp_CC_SetCalpage
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_GetCalPage
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_GetPagProcessorInfo(void);
#endif

static FUNC(void, XCP_CODE) Xcp_CC_GetSegmentInfo
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_GetPageInfo
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);

#ifdef XCP_ENABLE_PAGE_COPY
static FUNC(void, XCP_CODE) Xcp_CC_CopyCalPage
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif

static FUNC(void, XCP_CODE) Xcp_CC_SetMta
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_Download
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
static FUNC(void, XCP_CODE) Xcp_CC_DownloadNext
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif
static FUNC(void, XCP_CODE) Xcp_CC_DownloadMax
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_UpLoad
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_ShortUplod
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);

#if( STD_ON == XCP_ENABLE_CHECKSUM )
static FUNC(void, XCP_CODE) Xcp_CC_BuildCheckum
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif

#ifdef XCP_ENABLE_DAQ
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqProcessorInfo(void);
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqResolutionInfo(void);
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqEventInfo
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_FreeDaq(void);
static FUNC(void, XCP_CODE) Xcp_CC_AllocDaq
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_AllocOdt
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_AllocOdtEntry
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqListMode
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_SetDaqListMode
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_SetDaqPtr
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_WriteDaq
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_StartStopDaqList
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_StartStopSynch
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqClock(void);
#endif

#if ( STD_ON == XCP_FLASH_PROGRAMING_ENABLE )
static FUNC(void, XCP_CODE) Xcp_CC_Program_Start(void);
static FUNC(void, XCP_CODE) Xcp_CC_Program_Clear
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
static FUNC(void, XCP_CODE) Xcp_CC_Program
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
static FUNC(void, XCP_CODE) Xcp_CC_Program_Next
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif
static FUNC(void, XCP_CODE) Xcp_CC_Program_Max
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif
#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
static FUNC(void, XCP_CODE) Xcp_CC_Set_Request
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
);
#endif

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD && STD_ON == XCP_ENABLE_CHECKSUM )
static FUNC(void, XCP_CODE) Xcp_SinglePtrChecksum(uint32 checksumSize);
#endif
#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
static FUNC(Std_ReturnType, XCP_CODE) Xcp_ModifyEntry(
    uint32 CalibAddress,
    uint16 CalibLength,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)CalibGroupData
);
static FUNC(Std_ReturnType, XCP_CODE) Xcp_CalibParaRead(
    uint32 CalibAddress,
    uint16 CalibLength,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)CalibGroupData
);
#endif

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD && STD_ON == XCP_ENABLE_CHECKSUM )
static FUNC(void, XCP_CODE) Xcp_AddressRelocationChecksum(uint32 checksumSize);
#endif
#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD || RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
static FUNC(void, XCP_CODE) Xcp_MemCpy32(uint32 source, uint32 target, uint32 Size);
#endif
#ifdef XCP_ENABLE_PAGE_COPY
static FUNC(uint8, XCP_CODE) ApplXcpCopyCalPage
(
    uint8 srcSeg, uint8 srcPage, uint8 dstSeg, uint8 dstPage
);
static FUNC(void, XCP_CODE) Xcp_CopyMemCpy
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)dest,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)src,
    uint16 num
);
#endif

static FUNC(void, XCP_CODE) Xcp_InitCalPage(void);

#if( MULTIPDUIDSUPPORT == STD_ON )
static FUNC(void, XCP_CODE) Xcp_Send
(
    uint8 pduid,
    uint32 avcLen,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)avcpMsg
);
#else
static FUNC(void, XCP_CODE) Xcp_Send
(
    uint32 avcLen,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)avcpMsg
);
#endif

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD && STD_ON == XCP_ENABLE_CHECKSUM )
static FUNC(void, XCP_CODE) Xcp_StructurePtChecksum
(
    uint32 ChecksumSize
);
#endif
#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
static FUNC(void, XCP_CODE) Xcp_CalVectReset
(
    P2VAR(Xcp_VectList_st, AUTOMATIC, XCP_APPL_DATA) VectPtr
);

static FUNC(uint16, XCP_CODE) Xcp_CalVectSearch
(
    P2VAR(Xcp_VectList_st, AUTOMATIC, XCP_APPL_DATA) VectPtr,
    uint32 AddrReq
);

static FUNC(uint8, XCP_CODE) Xcp_CalDownLoadHandle
(
    uint16 Size,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) Data
);

static FUNC(uint8, XCP_CODE) Xcp_CalUpLoadHandle
(
    uint8 Size,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Data
);

static FUNC(void, XCP_CODE) Xcp_CalMemInit(void);

static FUNC(void, XCP_CODE) Xcp_ReqCopy
(
    uint32 SrcAddr,
    uint32 DesAddr,
    uint32 Size
);
#endif

#ifdef XCP_ENABLE_CALIBRATION_PAGE
static FUNC(uint8, XCP_CODE) ApplXcpSetCalPage
(
    uint8 segment, uint8 page, uint8 mode
);
static FUNC(uint8, XCP_CODE) ApplXcpGetCalPage(uint8 avcSegment, uint8 avcMode);
#endif

static FUNC(Xcp_TimestampType, XCP_CODE) ApplXcpGetTimestamp(void);

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
static FUNC(uint8, XCP_CODE) Xcp_ActionForBlock
(
    uint8 mode
);
#endif
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define XCP_START_SEC_VAR_INIT
#include "Xcp_MemMap.h"

VAR(uint8, XCP_VAR_INIT) CanXcpGetStatus = TRUE;
VAR(uint8, XCP_VAR_INIT) XcpCommandTimeCounter = XCP_ZERO;

#define XCP_STOP_SEC_VAR_INIT
#include "Xcp_MemMap.h"
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h"

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )

/*
********************************************************************************
* Function Name: Xcp_CalVectRegister
*
* Explanation: Register the calibration partition.
*
* param: Pptr: The address of the partition start address.
*        Size: The amount of data in the calibration partition, in bytes.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_CalVectRegister
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_CONST) *Pptr,
    uint16 Size
)
{
    uint16 idx;
    Xcp_VectList_st *vectListptr;
    Xcp_RamList_st *ramPtr;

    vectListptr = &Xcp_VectList;
    ramPtr = Xcp_Data.XcpRamPtr;

    idx = (vectListptr->vect_cnt)++;
    vectListptr->vect_info[idx].CalVecAddr = (uint32)Pptr;
    vectListptr->vect_info[idx].CalVecWpAddr = (uint32)*Pptr;
    vectListptr->vect_info[idx].CalVecRpAddr = (uint32)*Pptr;
    vectListptr->vect_info[idx].CalVecLen = (uint32)Size;

    ramPtr->RamCfg[ramPtr->RamNum].RamCurAddr += (uint32)sizeof(Xcp_VectInfo_st);
}

/*
********************************************************************************
* Function Name: Xcp_CalVectReset
*
* Explanation: Reset the calibration partition.
*
* param: Vect_ptr: The partition start address.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_CalVectReset
(
    P2VAR(Xcp_VectList_st, AUTOMATIC, XCP_APPL_DATA) VectPtr
)
{
    uint16 vectidx;
    uint32 *CalVecAddr;
    Xcp_RamList_st *ramPtr;

    ramPtr = Xcp_Data.XcpRamPtr;

    for( vectidx = XCP_ZERO; vectidx < VectPtr->vect_cnt; vectidx++ )
    {
        CalVecAddr = (uint32*)(VectPtr->vect_info[vectidx].CalVecAddr);
        *CalVecAddr = VectPtr->vect_info[vectidx].CalVecRpAddr;
        VectPtr->vect_info[vectidx].CalVecWpAddr = VectPtr->vect_info[vectidx].CalVecRpAddr;
    }

    ramPtr->RamCfg[ramPtr->RamNum].RamCurAddr = (uint32)&(VectPtr->vect_info[vectidx]);
}

/*
********************************************************************************
* Function Name: Xcp_CalVectSearch
*
* Explanation: Find the partition index of the calibration address.
*
* param: VectPtr: The partition start address.
*        AddrReq: The calibration address.
*
* retval: vectIdx: The partition index.
********************************************************************************
*/
FUNC(uint16, XCP_CODE) Xcp_CalVectSearch
(
    P2VAR(Xcp_VectList_st, AUTOMATIC, XCP_APPL_DATA) VectPtr,
    uint32 AddrReq
)
{
    uint16 vectIdx;

    for( vectIdx = XCP_ZERO; vectIdx < VectPtr->vect_cnt; vectIdx++ )
    {
        if( (AddrReq >= VectPtr->vect_info[vectIdx].CalVecRpAddr) &&
			(AddrReq < (VectPtr->vect_info[vectIdx].CalVecRpAddr + VectPtr->vect_info[vectIdx].CalVecLen)) )
        {
            break;
        }
    }

    return vectIdx;
}

/*
********************************************************************************
* Function Name: Xcp_CalDownLoadHandle
*
* Explanation: Perform data calibration.
*
* param: Size: Data calibration size.
*        Data: Data calibration start address.
*
* retval: retVal: Calibration operation result.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) Xcp_CalDownLoadHandle
(
    uint16 Size,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) Data
)
{
    uint8 retVal = E_NOT_OK;
    uint16 vectIdx;
    uint32 addr;
    uint32 *CalVecAddr;
    uint32 downsize;

    Xcp_RamList_st *ramPtr;
    Xcp_VectList_st *vectPtr;
    addr = (uint32)Xcp_Data.Mta;

    ramPtr = Xcp_Data.XcpRamPtr;
    vectPtr = &Xcp_VectList;

    vectIdx = Xcp_CalVectSearch(vectPtr, addr);
    if( vectIdx < vectPtr->vect_cnt )
    {
        if( vectPtr->vect_info[vectIdx].CalVecWpAddr == vectPtr->vect_info[vectIdx].CalVecRpAddr )
        {
            /* The first time to calibrate the partition, data copy is required. */
            Xcp_ReqCopy(vectPtr->vect_info[vectIdx].CalVecRpAddr,
                        ramPtr->RamCfg[ramPtr->RamNum].RamCurAddr,
                        vectPtr->vect_info[vectIdx].CalVecLen);
            vectPtr->vect_info[vectIdx].CalVecWpAddr = ramPtr->RamCfg[ramPtr->RamNum].RamCurAddr;
            CalVecAddr = (uint32*)(vectPtr->vect_info[vectIdx].CalVecAddr);
            *CalVecAddr = ramPtr->RamCfg[ramPtr->RamNum].RamCurAddr;
            ramPtr->RamCfg[ramPtr->RamNum].RamCurAddr += vectPtr->vect_info[vectIdx].CalVecLen;
            if( ramPtr->RamCfg[ramPtr->RamNum].RamLen < vectPtr->vect_info[vectIdx].CalVecLen )
            {
                retVal = XCP_CMD_OUT_OF_RANGE;
            }
            else
            {
                ramPtr->RamCfg[ramPtr->RamNum].RamLen -= vectPtr->vect_info[vectIdx].CalVecLen;
                Xcp_DownLoadCopyState.DownSize = Size;
                Xcp_DownLoadCopyState.DownData = Data;
                Xcp_Pending = XCP_ONE;
                retVal = XCP_CMD_PENDING;
            }

        }
        else
        {
            /* WP is already in RAM, excute write action */
            addr = vectPtr->vect_info[vectIdx].CalVecWpAddr + (addr - vectPtr->vect_info[vectIdx].CalVecRpAddr);
            downsize = Size;
            while( downsize > XCP_ZERO )
            {
                XCP_WRITE_BYTE_2_ADDR((uint8 *)addr, *Data);
                addr++;
                Data++;
                downsize--;
            }
            retVal = E_OK;
        }

    }
#if( XCPBLOCK_SIZE > XCP_ZERO )
    else
    {
        retVal = E_NOT_OK;
    }
#endif

    return retVal;
}

/*
********************************************************************************
* Function Name: Xcp_CalUpLoadHandle
*
* Explanation: Perform data upload.
*
* param: Size: Data upload size.
*        Data: Data upload start address.
*
* retval: retVal: Upload operation result.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) Xcp_CalUpLoadHandle
(
    uint8 Size,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) Data
)
{
    uint8 retVal = E_NOT_OK;
    uint16 vectIdx;
    uint32 addr;

    Xcp_VectList_st *vectPtr;
    addr = (uint32)Xcp_Data.Mta;

    vectPtr = &Xcp_VectList;

    vectIdx = Xcp_CalVectSearch(vectPtr, addr);
    if( vectIdx < vectPtr->vect_cnt )
    {
        addr = vectPtr->vect_info[vectIdx].CalVecWpAddr + (addr - vectPtr->vect_info[vectIdx].CalVecRpAddr);

        while( Size > XCP_ZERO )
        {
            *(Data) = XCP_READ_BYTE_FROM_ADDR((uint8 *)addr);
            addr++;
            Data++;
            Size--;
        }
        retVal = E_OK;
    }
    return retVal;
}

/*
********************************************************************************
* Function Name: Xcp_CalMemInit
*
* Explanation: Calibration partition initialization.
*
* param: None.
*
* retval: retVal: Upload operation result.
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_CalMemInit(void)
{
    uint8 ramIdx = XCP_ZERO;
    Xcp_RamList_st *ptr;

    Xcp_Data.XcpRamPtr = (Xcp_RamList_st *)(&Xcp_CalRamInfoMem[XCP_ZERO]);
    ptr = Xcp_Data.XcpRamPtr;

    /* calibration ram info init */
    ptr->RamCnt = XCP_ONE;
    ptr->RamNum = XCP_ZERO;

    ptr->RamCfg = (Xcp_Ram_st *)((uint8 *)(ptr) + sizeof(*(ptr)));
    ptr->RamCfg[ramIdx].RamStaAddr = Xcp_Addr_Stru[XCP_ZERO].addr_wp;
    ptr->RamCfg[ramIdx].RamCurAddr = Xcp_Addr_Stru[XCP_ZERO].addr_wp;

    for( ramIdx = XCP_ZERO; ramIdx < XCP_RAM_CNT; ramIdx++ )
    {
        ptr->RamCfg[XCP_ZERO].RamLen += Xcp_Addr_Stru[ramIdx].len;
    }

    Xcp_VectList.vect_cnt = XCP_ZERO;
    Xcp_VectList.vect_info = (Xcp_VectInfo_st *)(ptr->RamCfg[XCP_ZERO].RamCurAddr);

}

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD && STD_ON == XCP_ENABLE_CHECKSUM )
/*
********************************************************************************
* Function Name: Xcp_StructurePtChecksum
*
* Explanation: Check data size.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_StructurePtChecksum(uint32 ChecksumSize)
{
    uint16 vectIdx = XCP_ZERO;
    uint32 addr = (uint32)Xcp_Data.Mta;
    uint32 calVecLen = XCP_ZERO;
    Xcp_VectList_st *vectPtr = &Xcp_VectList;
    uint8* addrOfs = NULL_PTR;

    if( XCP_ONE == Xcp_Data.PageInd )  /* Working Page */
    {
        while( ChecksumSize > XCP_ZERO )
        {
            vectIdx = Xcp_CalVectSearch(vectPtr, addr);
#if( (XCP_ADD12 == XCP_CHECKSUM_TYPE) || (XCP_ADD11 == XCP_CHECKSUM_TYPE) )
            if( vectIdx < vectPtr->vect_cnt )		/* In the calibration area. */
            {
                addrOfs = (uint8*)vectPtr->vect_info[vectIdx].CalVecWpAddr;
                calVecLen = vectPtr->vect_info[vectIdx].CalVecLen;

                if( vectPtr->vect_info[vectIdx].CalVecRpAddr == vectPtr->vect_info[vectIdx].CalVecWpAddr )
                {
                    while( calVecLen > XCP_ZERO )
                    {
                        Xcp_Data.CheckSum += (tXcpChecksumSumType)XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta);
                        Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
                        ChecksumSize -= (uint8)sizeof(tXcpChecksumAddType);
                        calVecLen -= (uint8)sizeof(tXcpChecksumAddType);
                    }
                }
                else
                {
                    while( calVecLen > XCP_ZERO )
                    {
                        Xcp_Data.CheckSum += (tXcpChecksumSumType)XCP_READ_CHECKSUMVALUE_FROM_ADDR(addrOfs);
                        Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
                        ChecksumSize -= (uint8)sizeof(tXcpChecksumAddType);
                        calVecLen -= (uint8)sizeof(tXcpChecksumAddType);
                        addrOfs += (uint8)sizeof(tXcpChecksumAddType);
                    }
                }
            }
            else
            {
                Xcp_Data.CheckSum += (tXcpChecksumSumType)XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta);
                Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
                ChecksumSize -= (uint8)sizeof(tXcpChecksumAddType);
            }
            addr = (uint32)Xcp_Data.Mta;
#else
            if( vectIdx < vectPtr->vect_cnt )		/* In the calibration area. */
            {
                addrOfs = (uint8*)vectPtr->vect_info[vectIdx].CalVecWpAddr;
                calVecLen = vectPtr->vect_info[vectIdx].CalVecLen;

                if( vectPtr->vect_info[vectIdx].CalVecRpAddr == vectPtr->vect_info[vectIdx].CalVecWpAddr )
                {
                    if( TRUE == Xcp_Data.Crc32Flag )
                    {

                        Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, calVecLen, (uint32)XCP_ZERO, TRUE);
                        Xcp_Data.Crc32Flag = FALSE;
                    }
                    else
                    {
                        Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, calVecLen, (uint32)Xcp_Data.CheckSum, FALSE);
                    }
                }
                else
                {
                    if( TRUE == Xcp_Data.Crc32Flag )
                    {

                        Xcp_Data.CheckSum = Crc_CalculateCRC32(addrOfs, calVecLen, (uint32)XCP_ZERO, TRUE);
                        Xcp_Data.Crc32Flag = FALSE;
                    }
                    else
                    {
                        Xcp_Data.CheckSum = Crc_CalculateCRC32(addrOfs, calVecLen, (uint32)Xcp_Data.CheckSum, FALSE);
                    }
                }
                Xcp_Data.Mta += (uint8)calVecLen;
                ChecksumSize -= (uint8)calVecLen;
            }
            else
            {
                if( TRUE == Xcp_Data.Crc32Flag )
                {
                    Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, XCP_ONE, (uint32)XCP_ZERO, TRUE);
                    Xcp_Data.Crc32Flag = FALSE;
                    Xcp_Data.Mta += (uint8)XCP_ONE;
                    ChecksumSize -= (uint8)XCP_ONE;
                }
                else
                {
                    Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, XCP_ONE, (uint32)Xcp_Data.CheckSum, FALSE);
                    Xcp_Data.Mta += (uint8)XCP_ONE;
                    ChecksumSize -= (uint8)XCP_ONE;
                }
            }
            addr = (uint32)Xcp_Data.Mta;
#endif
        }
    }
    else
    {
#if( (XCP_ADD12 == XCP_CHECKSUM_TYPE) || (XCP_ADD11 == XCP_CHECKSUM_TYPE) )
        while( ChecksumSize > XCP_ZERO )
        {
            Xcp_Data.CheckSum += (tXcpChecksumSumType)XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta);
            Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
            ChecksumSize -= (uint8)sizeof(tXcpChecksumAddType);
        }
#else
        if( TRUE == Xcp_Data.Crc32Flag )
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, ChecksumSize, (uint32)XCP_ZERO, TRUE);
            Xcp_Data.Crc32Flag = FALSE;
            Xcp_Data.Mta += (uint8)ChecksumSize;
        }
        else
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, ChecksumSize, (uint32)Xcp_Data.CheckSum, FALSE);
            Xcp_Data.Mta += (uint8)ChecksumSize;
        }
#endif
    }
}
#endif
/*
********************************************************************************
* Function Name: Xcp_ReqCopy
*
* Explanation: Request data copy before calibration.
*
* param: SrcAddr: Source data address.
*        DesAddr: Copy destination.
*        Size: Data copy size.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_ReqCopy
(
    uint32 SrcAddr,
    uint32 DesAddr,
    uint32 Size
)
{

    /* First request, setting the copy size */
    Xcp_DownLoadCopyState.CopyAddrDest = DesAddr;
    Xcp_DownLoadCopyState.CopyAddrSrc = SrcAddr;
    Xcp_DownLoadCopyState.CopyLen = Size;
    Xcp_DownLoadCopyState.CopyReqState = XCP_ONE;

}

#endif

#if( STD_ON == XCP_VERSION_INFO_API )
/*
********************************************************************************
* Function Name: XCP_GetVersionInfo
*
* Explanation: Returns the version information of this module.
*
* param: VersionInfoPtr:Pointer to standard version information structure.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, XCP_APPL_DATA) VersionInfoPtr
)
{
    uint8 errType = XCP_E_NO_ERROR;
    if( NULL_PTR != VersionInfoPtr )
    {
        VersionInfoPtr->vendorID = XCP_VENDOR_ID;
        VersionInfoPtr->moduleID = XCP_MODULE_ID;
        VersionInfoPtr->sw_major_version = XCP_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = XCP_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = XCP_SW_PATCH_VERSION;
    }
    else
    {
        errType = XCP_E_PARAM_POINTER;
    }

    Xcp_Det_ErrorReport(XCP_SID_GET_VERSIONINFO, errType);

}
#endif /* ( STD_ON == XCP_VERSION_INFO_API ) */

/*
********************************************************************************
* Function Name: Xcp_MainFunction
*
* Explanation: XCP main function.Transfer to the command processing function
*              or EventChannel according to the received message.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_MainFunction(void)
{
#if( RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
    uint8 addrIndex;
#endif

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
    uint8 retValue = E_OK;
    retValue = Xcp_ActionForBlock(ACTION_READ);
    if( E_OK == retValue )
    {
#endif/* XCP_ENABLE_NVM_SAVE_DATA == STD_ON */

#if( XCP_ONETHERNET_ENABLE == STD_ON )
        EthXcp_MainFunction();
#endif

#if( XCP_ONCAN_ENABLE == STD_ON )
        CanXcp_MainFunction();
#endif

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
        if( XCP_ZERO < Xcp_Addr.len )
        {
            if( XCP_512 < Xcp_Addr.len )
            {
                Xcp_Addr.len -= XCP_512;
                Xcp_MemCpy32(Xcp_Addr.addr_rp, Xcp_Addr.addr_wp, XCP_512);
                Xcp_Addr.addr_rp += XCP_512;
                Xcp_Addr.addr_wp += XCP_512;
            }
            else
            {
                Xcp_MemCpy32(Xcp_Addr.addr_rp, Xcp_Addr.addr_wp, Xcp_Addr.len);
                Xcp_Addr.addr_rp += Xcp_Addr.len;
                Xcp_Addr.addr_wp += Xcp_Addr.len;
                Xcp_Addr.len = XCP_ZERO;
            }
        }
#endif

#if( RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
        for( addrIndex = XCP_ZERO; addrIndex < XCP_OVERLAY_CNT; addrIndex++ )
        {
            if( Xcp_Addr_Temp[addrIndex].len > XCP_ZERO )
            {
                if( Xcp_Addr_Temp[addrIndex].len > XCP_512 )
                {
                    Xcp_Addr_Temp[addrIndex].len -= XCP_512;
                    Xcp_MemCpy32(Xcp_Addr_Temp[addrIndex].addr_rp, Xcp_Addr_Temp[addrIndex].addr_wp, XCP_512);
                    Xcp_Addr_Temp[addrIndex].addr_rp += XCP_512;
                    Xcp_Addr_Temp[addrIndex].addr_wp += XCP_512;
                }
                else
                {
                    Xcp_MemCpy32(Xcp_Addr_Temp[addrIndex].addr_rp, Xcp_Addr_Temp[addrIndex].addr_wp, Xcp_Addr_Temp[addrIndex].len);
                    Xcp_Addr_Temp[addrIndex].addr_rp += Xcp_Addr_Temp[addrIndex].len;
                    Xcp_Addr_Temp[addrIndex].addr_wp += Xcp_Addr_Temp[addrIndex].len;
                    Xcp_Addr_Temp[addrIndex].len = XCP_ZERO;
                }
            }
        }
#endif

        (void)Xcp_Background();

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
        if( Xcp_Data.storeFlag == SS_STORE_CAL_REQ )
        {
            retValue = Xcp_ActionForBlock(ACTION_WRITE);
            if ( E_OK == retValue )
            {
                CRM_EV_ID = PID_EV;
                CRM_EV_CODE = EV_STORE_CAL;
                Xcp_Data.EvLen = XCP_TWO;
                Xcp_Data.storeFlag = XCP_ZERO;
                Xcp_SendEv();
            }
            else
            {

            }
        }
    }/* XCP_ENABLE_NVM_SAVE_DATA == STD_ON */
#endif

}

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
/*
********************************************************************************
* Function Name: Xcp_ActionForBlock
*
* Explanation: Xcp_ActionForBlock.
*              Calibration block for reading or writing all RAM.
*
* param: mode:ACTION_READ:Indicates the use of read.
*             ACTION_WRITE:Indicates the use of write.
*
*
* retval: E_OK:Indicates completion of reading or writing.
*         E_NOT_OK:Indicates whether to read or write without complete.
*
********************************************************************************
*/
static FUNC(uint8, DCM_CODE) Xcp_ActionForBlock
(
    uint8 mode
)
{
    uint8 retVal;
    uint8 errorStatus = E_OK;
    uint16 blockIndex = XCP_BLOCK_NUM;
    static uint8 actionDoneFlag[XCP_BLOCK_NUM + XCP_ONE] = {FALSE};

    if( (SS_STORE_CAL_REQ == Xcp_Data.storeFlag) && (ACTION_WRITE == mode) )
    {
        retVal = E_NOT_OK;
    }
    else
    {
        if( (uint8)TRUE == Xcp_ReadBlockDone )
        {
            retVal = E_OK;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }

    if( E_NOT_OK == retVal )
    {
        /* Action block id data. */
        for( blockIndex = XCP_ZERO; blockIndex != XCP_BLOCK_NUM; blockIndex++ )
        {
            /* No data in not needed to option, set invalid block id. */
            if( XCP_FFFF == Xcp_NvmBlockId[blockIndex].BlockId )
            {
                actionDoneFlag[blockIndex] = TRUE;
                Xcp_NvmBlockId[blockIndex].ReadResp = E_OK;
                Xcp_NvmBlockId[blockIndex].RequestResp = E_OK;
            }
            /* If data buffer is null, set option done. */
            else if( NULL_PTR == Xcp_NvmBlockId[blockIndex].DataPtr )
            {
                actionDoneFlag[blockIndex] = TRUE;
                Xcp_NvmBlockId[blockIndex].ReadResp = E_OK;
                Xcp_NvmBlockId[blockIndex].RequestResp = E_OK;
            }
            else
            {
                if( (uint8)E_NOT_OK == Xcp_NvmBlockId[blockIndex].RequestResp )
                {
                    if( (SS_STORE_CAL_REQ == Xcp_Data.storeFlag) && (ACTION_WRITE == mode) )
                    {
                        /* Write nvm block data. */
                        retVal = NvM_WriteBlock(Xcp_NvmBlockId[blockIndex].BlockId,
                                                Xcp_NvmBlockId[blockIndex].DataPtr);
                    }
                    else
                    {   /* Read nvm block data. */
                        retVal = NvM_ReadBlock(Xcp_NvmBlockId[blockIndex].BlockId,
                                                Xcp_NvmBlockId[blockIndex].DataPtr);
                    }
                    if( (uint8)E_OK == retVal )
                    {
                        Xcp_NvmBlockId[blockIndex].RequestResp = E_OK;
                        Xcp_NvmBlockId[blockIndex].ReadResp = E_NOT_OK;
                    }
                }
                else if( (uint8)E_NOT_OK == Xcp_NvmBlockId[blockIndex].ReadResp )
                {
                    /* Get the nvm error status. */
                    (void)NvM_GetErrorStatus(Xcp_NvmBlockId[blockIndex].BlockId, &errorStatus);

                    if( (uint8)E_NOT_OK == errorStatus )
                    {
                         /* Nothing to be done.The return value remains false */
                    }
                    else if( NVM_REQ_PENDING == errorStatus )
                    {
                        /* Nothing to be done.The return value remains false */
                    }
                    else
                    {
                        actionDoneFlag[blockIndex] = TRUE;
                        Xcp_NvmBlockId[blockIndex].ReadResp = E_OK;
                    }
                }
                else
                {
                }
            }
        }

        /* Determine if all blocks have completed the operation*/
        for( blockIndex = XCP_ZERO; blockIndex != XCP_BLOCK_NUM ; blockIndex++ )
        {
            if( (uint8)FALSE == actionDoneFlag[blockIndex] )
            {
                break;
            }
        }

        if( XCP_BLOCK_NUM  == blockIndex )
        {
            /* Recovery status */
            for( blockIndex = XCP_ZERO; blockIndex != XCP_BLOCK_NUM; blockIndex++ )
            {
                Xcp_NvmBlockId[blockIndex].RequestResp = E_NOT_OK;
                Xcp_NvmBlockId[blockIndex].ReadResp = E_NOT_OK;
                actionDoneFlag[blockIndex] = FALSE;
            }
            if( SS_STORE_CAL_REQ != Xcp_Data.storeFlag )
            {
                Xcp_ReadBlockDone = TRUE;
            }
            retVal = E_OK;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    return retVal;
}
#endif/* XCP_ENABLE_NVM_SAVE_DATA == STD_ON */

/*
********************************************************************************
* Function Name: XCP_GetPointer
*
* Explanation: Get the address of the data to be measured or calibrated.
*
* param: extAddr: Address extension.
*        addr: Address of DAQ element.
*
* retval: Storage address.
********************************************************************************
*/
static FUNC_P2VAR(uint8, XCP_CODE, XCP_APPL_DATA) Xcp_GetPointer
(
    uint8 extAddr, uint32 addr
)
{
    uint8* retValue = NULL_PTR;
    XCP_DUMMY_STATEMENT(extAddr);

    retValue = (uint8*)addr; /* Add error handling later */

    return retValue;
}

/*
********************************************************************************
* Function Name: XCP_MemSet
*
* Explanation: Initialize n bytes starting from address p with b.
*
* param: destAddr : Pointer to start address.
*        num : Number of data bytes.
*        byte : Data byte to initialize with.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_MemSet
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)destAddr,
    uint16 num,
    uint8 byte
)
{
    for( ; num > XCP_ZERO; num-- )
    {
        *destAddr = byte;
        destAddr++;
    }
}

/*
********************************************************************************
* Function Name: Xcp_MemCpy8
*
* Explanation: Copy n bytes from src to dest.
*              A maximum of 255 Bytes can be copied at once.
*
* param: dest : pointer to destination address.
*        src : pointer to source address.
*        num : number of data bytes to copy.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_MemCpy8
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) dest,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) src,
    uint32 num
)
{
    for( ; num > XCP_ZERO; num-- )
    {
        XCP_WRITE_BYTE_2_ADDR(dest, *src);
        dest++;
        src++;
    }
}

/*
********************************************************************************
* Function Name: XCP_WriteMta
*
* Explanation: Write n bytes.
*              Copying of size bytes from data to Xcp_Data.Mta.
*
* param: size : Size of copies of data.
*        data : Copied data.
*
* retval: E_OK: XCP_WriteMta success.
*         Any other: XCP_WriteMta not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_WriteMta
(
    uint8 size,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST) data
)
{
    uint8 retValue = E_NOT_OK;

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD || RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    uint8 acRet;
#endif

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
    acRet = Xcp_ModifyEntry((uint32)Xcp_Data.Mta, (uint16)size, (uint8*)data);
    if( E_OK == acRet )
    {
        Xcp_Data.Mta += size;
        retValue = (uint8)XCP_CMD_OK;
    }
    else
    {
        retValue = (uint8)XCP_CMD_DENIED;
    }
#elif( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    acRet = Xcp_CalDownLoadHandle(size, (uint8*)data);

    if( E_OK == acRet )
    {
        Xcp_Data.Mta += size;
        retValue = (uint8)XCP_CMD_OK;
    }
    else if( XCP_CMD_PENDING == acRet )
    {
        retValue = XCP_CMD_PENDING;
    }
    else
    {
        retValue = (uint8)XCP_CMD_DENIED;
    }

#else

    while( size > XCP_ZERO )
    {
#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
        if( ((uint32)Xcp_Data.Mta >= CALFLASH_ADDR) &&
            ((uint32)Xcp_Data.Mta < (CALFLASH_ADDR + CALRAM_SIZE)) )
        {
            XCP_WRITE_BYTE_2_ADDR(Xcp_Data.Mta + XcpCalOffset, *data);
        }
        else
        {
            XCP_WRITE_BYTE_2_ADDR(Xcp_Data.Mta, *data);
        }
#else
        XCP_WRITE_BYTE_2_ADDR(Xcp_Data.Mta, *data);
#endif

        Xcp_Data.Mta++;
        data++;
        size--;
    }
    retValue = (uint8)XCP_CMD_OK;
#endif

    return retValue;
}

/*
********************************************************************************
* Function Name: XCP_ReadMta
*
* Explanation: Read n bytes.
*              Copying of size bytes from Xcp_Data.Mta to data.
*
* param: size : Size of copies of data.
*        data : Copied data.
*
* retval: E_OK: XCP_WriteMta success.
*         Any other: XCP_WriteMta not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_ReadMta
(
    uint8 size,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)data
)
{
    uint8 retValue = E_NOT_OK;

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD || RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    uint8 acRet;
#endif

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )

    acRet = Xcp_CalibParaRead((uint32)Xcp_Data.Mta, (uint16)size, (uint8*)data);
    if( E_OK == acRet )
    {
        Xcp_Data.Mta += size;
        retValue = (uint8)XCP_CMD_OK;
    }
    else if( E_NOT_OK == acRet )
    {
        if( NULL_PTR == Xcp_Data.Mta )
        {
            retValue = (uint8)XCP_CMD_OK;
        }
        /* Standard RAM memory read access */
        else
        {
            while( size > XCP_ZERO )
            {
                *(data) = XCP_READ_BYTE_FROM_ADDR(Xcp_Data.Mta);
                data++;
                Xcp_Data.Mta++;
                size--;
            }
            retValue = (uint8)XCP_CMD_OK;
        }
    }
    else
    {
        /* Do noting. */
    }
#elif( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    acRet = Xcp_CalUpLoadHandle(size, data);

    if( E_OK == acRet )
    {
        Xcp_Data.Mta += size;
        retValue = (uint8)XCP_CMD_OK;
    }
    else
    {
        if( NULL_PTR == Xcp_Data.Mta )
        {
            retValue = (uint8)XCP_CMD_ERROR;
        }
        else
        {
            while( size > XCP_ZERO )
            {
                *(data) = XCP_READ_BYTE_FROM_ADDR(Xcp_Data.Mta);
                data++;
                Xcp_Data.Mta++;
                size--;
            }
            retValue = (uint8)XCP_CMD_OK;
        }
    }

#else
    /*Determine if there is data in Xcp_Data.Mta*/
    if( NULL_PTR == Xcp_Data.Mta )
    {
        retValue = XCP_CMD_OK;
    }
    /* Standard RAM memory read access */
    else
    {
        while( size > XCP_ZERO )
        {

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
            if( ((uint32)Xcp_Data.Mta >= CALFLASH_ADDR) &&
                ((uint32)Xcp_Data.Mta < (CALFLASH_ADDR + CALRAM_SIZE)) )
            {
                *(data) = XCP_READ_BYTE_FROM_ADDR(Xcp_Data.Mta + XcpCalOffset);
            }
            else
            {
                *(data) = XCP_READ_BYTE_FROM_ADDR(Xcp_Data.Mta);
            }
#else
            *(data) = XCP_READ_BYTE_FROM_ADDR(Xcp_Data.Mta);
#endif

            data++;
            Xcp_Data.Mta++;
            size--;
        }
        retValue = XCP_CMD_OK;
    }
#endif

    return retValue;
}

/*
********************************************************************************
* Function Name: XCP_MemClr
*
* Explanation: Initialize n bytes starting from address p 0.
*
* param: straddr : Pointer to start address.
*        num : Number of data bytes.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_MemClr
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)straddr,
    uint16 num
)
{
    Xcp_MemSet(straddr, num, (uint8)XCP_ZERO);
}

/*
********************************************************************************
* Function Name: XCP_Send
*
* Explanation: XCP send a message.
*
* param: avcLen: length of send data.
*       avcpMsg: the data send.
*
* retval: 0 : if the key is not valid.
********************************************************************************
*/
#if (MULTIPDUIDSUPPORT == STD_ON )
FUNC(void, XCP_CODE) Xcp_Send
(
    uint8 pduid, uint32 avcLen,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)avcpMsg
)
{
    CanXcp_Send(pduid, avcLen, avcpMsg);
}
#else
FUNC(void, XCP_CODE) Xcp_Send
(
    uint32 avcLen,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)avcpMsg
)
{
#if ( STD_ON == XCP_ONCAN_ENABLE )
        CanXcp_Send(avcLen, avcpMsg);
#endif

#if ( STD_ON == XCP_ONETHERNET_ENABLE )
        /* Fill the Ethernet data frame header */
#if( CPU_BYTE_ORDER == LOW_BYTE_FIRST )
        Xcp_EthResData[XCP_ONE] = (uint8)( (avcLen & 0x0000FF00U) >> XCP_EIGHT );
        Xcp_EthResData[XCP_ZERO] = (uint8)( avcLen & 0x000000FFU );
        Xcp_EthResData[XCP_THREE] = (uint8)( (Xcp_EthCtrTx & 0xFF00U) >> XCP_EIGHT );
        Xcp_EthResData[XCP_TWO] = (uint8)( Xcp_EthCtrTx & 0x00FF );
#else
        Xcp_EthResData[XCP_ZERO] = (uint8)( (avcLen & 0x0000FF00U) >> XCP_EIGHT );
        Xcp_EthResData[XCP_ONE] = (uint8)( avcLen & 0x000000FFU );
        Xcp_EthResData[XCP_TWO] = (uint8)( (Xcp_EthCtrTx & 0xFF00U) >> XCP_EIGHT );
        Xcp_EthResData[XCP_THREE] = (uint8)( Xcp_EthCtrTx & 0x00FF );
#endif
        Xcp_EthCtrTx++;
        Xcp_MemCpy8(&Xcp_EthResData[XCP_FOUR],avcpMsg,avcLen);
        EthXcp_Send((avcLen + XCP_FOUR), &Xcp_EthResData[XCP_ZERO]);
#endif

}
#endif

#if defined (XCP_ENABLE_SEND_EVENT) && ( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
/*
********************************************************************************
* Function Name: XCP_SendEv
*
* Explanation: Send a EV or SERV message, if no other message is pending.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_SendEv(void)
{
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    if( XCP_ZERO != (Xcp_Data.SendStatus & (uint8)XCP_SEND_PENDING) )
    {
        if( XCP_ZERO != (Xcp_Data.SendStatus & (uint8)XCP_EVT_REQUEST) )
        {
            Xcp_Data.SessionStatus |= (uint8)SS_ERROR;
        }
        Xcp_Data.SendStatus |= (uint8)XCP_EVT_REQUEST;
    }
    else
    {
        Xcp_Data.SendStatus |= (uint8)XCP_EVT_PENDING;
        Xcp_Send(Xcp_Data.EvLen, Xcp_Data.Ev.bytes);
        Xcp_Data.EvLen = XCP_ZERO;
    }
#else
    Xcp_Send(Xcp_Data.EvLen, Xcp_Data.Ev.bytes);
    Xcp_Data.EvLen = XCP_ZERO;
#endif

}
#endif /* XCP_ENABLE_SEND_EVENT */

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )

#if ( MULTIPDUIDSUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: XCP_SendDtoFromQueue
*
* Explanation: Send a DTO from the queue.
*
* param: None
*
* retval: E_OK: XCP_SendDtoFromQueue success.
*         Any other: XCP_SendDtoFromQueue not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_SendDtoFromQueue(uint8 eventid)
{
    uint8 retValue = E_NOT_OK;
    uint8 daq = Xcp_Data.Daq.EventDaq[eventid];

    /* A pending flag indicates that XCP_Send() is in progress */
    if( (XCP_ZERO == (Xcp_Data.SendStatus[eventid] & (uint8)XCP_SEND_PENDING)) &&
        (XCP_ZERO != Xcp_Data.QueueLen[daq]) )
    {
        Xcp_Data.SendStatus[eventid] |= (uint8)XCP_DTO_PENDING;
        /* Send Dto */
        Xcp_SendDto(eventid, &Xcp_Data.pQueue[daq][Xcp_Data.QueueRp[daq]]);
        Xcp_Data.QueueRp[daq]++;
        if( Xcp_Data.QueueRp[daq] >= Xcp_Data.QueueSize[daq] )
        {
            Xcp_Data.QueueRp[daq] = XCP_ZERO;
        }
        Xcp_Data.QueueLen[daq]--;
        retValue = E_OK;
    }
    return retValue;
}
#else
static FUNC(uint8, XCP_CODE) Xcp_SendDtoFromQueue(void)
{
    uint8 retValue = E_NOT_OK;

#if( XCP_ONETHERNET_ENABLE == STD_ON )
    Xcp_Eth_Dto_st Eth_Data = {{XCP_ZERO}, XCP_ZERO};
    uint8 * dtoi = &Eth_Data.bytes[XCP_ZERO];
    if( XCP_ZERO == Xcp_FirstDaqFlag )
    {
        Xcp_FirstDaqFlag++;
        Xcp_Data.SendStatus &= (uint8)(~XCP_CRM_PENDING) & XCP_FF;
    }
#endif
    /* A pending flag indicates that XCP_Send() is in progress */
    if( (XCP_ZERO == (Xcp_Data.SendStatus & (uint8)XCP_SEND_PENDING)) &&
        (XCP_ZERO != Xcp_Data.QueueLen) )
    {

#if (STD_ON == XCP_ONCAN_ENABLE)
        Xcp_Data.SendStatus |= (uint8)XCP_DTO_PENDING;
        /* Send Dto */
        Xcp_SendDto( & Xcp_Data.pQueue[Xcp_Data.QueueRp]);
        Xcp_Data.QueueRp++;
        if( Xcp_Data.QueueRp >= Xcp_Data.QueueSize )
        {
            Xcp_Data.QueueRp = XCP_ZERO;
        }
        Xcp_Data.QueueLen--;
#endif

#if ( STD_ON == XCP_ONETHERNET_ENABLE )

#if( CPU_BYTE_ORDER == LOW_BYTE_FIRST )
        (*(uint8*)(dtoi + XCP_ONE)) = (uint8)( (Xcp_Data.pQueue[Xcp_Data.QueueRp].length & 0x0000FF00U) >> XCP_EIGHT );
        (*(uint8*)(dtoi + XCP_ZERO)) = (uint8)( Xcp_Data.pQueue[Xcp_Data.QueueRp].length & 0x000000FFU );
        (*(uint8*)(dtoi + XCP_THREE)) = (uint8)( (Xcp_EthCtrTx & 0xFF00U) >> XCP_EIGHT );
        (*(uint8*)(dtoi + XCP_TWO)) = (uint8)( Xcp_EthCtrTx & 0x00FF );
#else
        (*(uint8*)(dtoi + XCP_ZERO)) = (uint8)( (Xcp_Data.pQueue[Xcp_Data.QueueRp].length & 0x0000FF00U) >> XCP_EIGHT );
        (*(uint8*)(dtoi + XCP_ONE)) = (uint8)( Xcp_Data.pQueue[Xcp_Data.QueueRp].length & 0x000000FFU );
        (*(uint8*)(dtoi + XCP_TWO)) = (uint8)( (Xcp_EthCtrTx & 0xFF00U) >> XCP_EIGHT );
        (*(uint8*)(dtoi + XCP_THREE)) = (uint8)( Xcp_EthCtrTx & 0x00FF );
#endif
        Xcp_EthCtrTx++;
        dtoi = &dtoi[XCP_FOUR];
        Xcp_MemCpy8(dtoi,
                    &Xcp_Data.pQueue[Xcp_Data.QueueRp].bytes[XCP_ZERO],
                    Xcp_Data.pQueue[Xcp_Data.QueueRp].length);
        Eth_Data.length += (Xcp_Data.pQueue[Xcp_Data.QueueRp].length + XCP_FOUR);
        Xcp_Data.QueueRp++;

        if( Xcp_Data.QueueRp >= Xcp_Data.QueueSize )
        {
            Xcp_Data.QueueRp = XCP_ZERO;
        }
        Xcp_Data.QueueLen--;
        Xcp_Data.SendStatus |= (uint8)XCP_DTO_PENDING;
        Xcp_SendEthDaq(&Eth_Data);

#endif

        retValue = E_OK;
    }
    return retValue;
}
#endif

/*
********************************************************************************
* Function Name: XCP_QueueInit
*
* Explanation: XCP transmission queue initialization.
*
* param: None
*
* retval: None
********************************************************************************
*/
#if ( MULTIPDUIDSUPPORT == STD_ON )
static FUNC(void, XCP_CODE) Xcp_QueueInit(void)
{
    uint8 index;

    for( index = XCP_ZERO; index < XCP_EVENT_CHANNEL_NUM ; index++ )
    {
        Xcp_Data.QueueLen[index] = XCP_ZERO;
        Xcp_Data.QueueRp[index] = XCP_ZERO;
    }

}
#else
static FUNC(void, XCP_CODE) Xcp_QueueInit(void)
{
    Xcp_Data.QueueLen = XCP_ZERO;
    Xcp_Data.QueueRp = XCP_ZERO;
}
#endif

#endif /* XCP_ENABLE_SEND_QUEUE */

#ifdef XCP_ENABLE_DAQ
/*
********************************************************************************
* Function Name: XCP_FreeDaq
*
* Explanation: Free all dynamic DAQ lists.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_FreeDaq(void)
{
    Xcp_Data.SessionStatus &= (uint8)(~SS_DAQ) & XCP_FF;

    Xcp_Data.Daq.DaqCount = XCP_ZERO;
    Xcp_Data.Daq.OdtCount = XCP_ZERO;
    Xcp_Data.Daq.OdtEntryCount = XCP_ZERO;

    Xcp_Data.pOdt = (Xcp_Odt_st*)XCP_ZERO;
    Xcp_Data.pOdtEntryAddr = (void *)XCP_ZERO;
    Xcp_Data.pOdtEntrySize = (void *)XCP_ZERO;

    /* clear daq data 2048 byte */
    Xcp_MemClr((uint8*)&Xcp_Data.Daq.u.b[XCP_ZERO], (uint16)XCP_DAQMEMSIZE);
    Xcp_MemSet( (uint8*) & Xcp_Data.Daq.EventDaq[XCP_ZERO],
        (uint16)sizeof(Xcp_Data.Daq.EventDaq), (uint8)XCP_FF);

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    Xcp_QueueInit();
#endif

}

/*
********************************************************************************
* Function Name: XCP_AllocMemory
*
* Explanation: Allocate Memory for daq,odt,odtEntries and Queue
*              according to DaqCount, OdtCount and OdtEntryCount.
*
* param: None
*
* retval: E_OK: XCP_AllocMemory success.
*         Any other: XCP_AllocMemory not success.
********************************************************************************
*/
#if( MULTIPDUIDSUPPORT == STD_ON )
static FUNC(uint8, XCP_CODE) Xcp_AllocMemory(void)
{
    uint8 retValue = E_OK;
    uint8 odtIndex;
    /*size:xcp_daq size   ,queuesize:queue size*/
    uint16 size = XCP_ZERO;
    uint16 queuesize = XCP_ZERO;
    /* Check memory overflow */
    /* 6 bytes sizeof(Xcp_DaqList_st) */
    /* 4 bytes sizeof(Xcp_Odt_st) */
    /* 5 bytes sizeof(uint8 *) + sizeof(uint8) */
    size = (uint16)((Xcp_Data.Daq.DaqCount * (uint8)sizeof(Xcp_DaqList_st)) +
            (Xcp_Data.Daq.OdtCount * (uint16)sizeof(Xcp_Odt_st)) +
            (Xcp_Data.Daq.OdtEntryCount * ((uint8)sizeof(uint8*) + (uint8)sizeof(uint8))));
    size += XCP_THREE; /* Worst case 3 bytes needed for alignment */
    if( (uint16)XCP_DAQMEMSIZE <= size)
    {
        retValue = (uint8)CRC_MEMORY_OVERFLOW;
    }
    else
    {
        /* Force WORD alignment for ODTs */
        /* Allign to dwords */
        Xcp_Data.pOdt = (Xcp_Odt_st*)((((uint32)(&Xcp_Data.Daq.u.DaqList[Xcp_Data.Daq.DaqCount]))+
                        (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
        /* Force DWORD alignment for ODT entries */
        Xcp_Data.pOdtEntryAddr = (uint8**) ((((uint32)&Xcp_Data.pOdt[Xcp_Data.Daq.OdtCount])+
                                 (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
        Xcp_Data.pOdtEntrySize = (uint8*)&Xcp_Data.pOdtEntryAddr[Xcp_Data.Daq.OdtEntryCount];

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
        /* Force WORD alignment for the queue */
        /* Allign to dwords */

        for( odtIndex = XCP_ZERO; odtIndex < XCP_EVENT_CHANNEL_NUM; odtIndex++ )
        {
            if( XCP_ZERO == odtIndex )
            {
                Xcp_Data.pQueue[odtIndex] = (Xcp_Dto_st*)((((uint32)(&Xcp_Data.pOdtEntrySize[Xcp_Data.Daq.OdtEntryCount]))+
                                            (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
            }
            else
            {
                Xcp_Data.pQueue[odtIndex] = (Xcp_Dto_st*)((((uint32)Xcp_Data.pQueue[odtIndex - XCP_ONE])+
                                            (DaqListOdtCount(odtIndex-XCP_ONE) + XCP_ZERO)*
                                            sizeof(Xcp_Dto_st) + (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
            }
            size += ((uint16)(DaqListOdtCount(odtIndex) * sizeof(Xcp_Dto_st)) + (uint16)XCP_THREE);

            queuesize = DaqListOdtCount(odtIndex);
            if( XCP_128 <= queuesize)
            {
                /* Maximum possible size because of the modulo operation in XcpQueueWrite */
                Xcp_Data.QueueSize[odtIndex] = XCP_127;
            }
            else
            {
                Xcp_Data.QueueSize[odtIndex] = (uint8)queuesize;
            }
            /* At least one queue entry per odt */

        }
        if( (uint16)XCP_DAQMEMSIZE <= size )
        {
            retValue = (uint8)CRC_MEMORY_OVERFLOW;
        }
#endif  /* XCP_ENABLE_SEND_QUEUE */

    }
    return retValue;
}

#else
static FUNC(uint8, XCP_CODE) Xcp_AllocMemory(void)
{
    uint8 retValue = E_OK;
    /*size:xcp_daq size   ,queuesize:queue size*/
    uint16 size = XCP_ZERO;

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    uint16 queuesize = XCP_ZERO;
#endif  /* XCP_ENABLE_SEND_QUEUE */

    /* Check memory overflow */
    /* 6 bytes sizeof(Xcp_DaqList_st) */
    /* 4 bytes sizeof(Xcp_Odt_st) */
    /* 5 bytes sizeof(uint8 *) + sizeof(uint8) */
    size = (uint16)((Xcp_Data.Daq.DaqCount * (uint8)sizeof(Xcp_DaqList_st)) +
            (Xcp_Data.Daq.OdtCount * (uint16)sizeof(Xcp_Odt_st)) +
            (Xcp_Data.Daq.OdtEntryCount * ((uint8)sizeof(uint8*) + (uint8)sizeof(uint8))));
    size += XCP_THREE; /* Worst case 3 bytes needed for alignment */
    if( (uint16)XCP_DAQMEMSIZE <= size )
    {
        retValue = (uint8)CRC_MEMORY_OVERFLOW;
    }
    else
    {
        /* Force WORD alignment for ODTs */
        /* Allign to dwords */
        Xcp_Data.pOdt = (Xcp_Odt_st*)((((uint32)(&Xcp_Data.Daq.u.DaqList[Xcp_Data.Daq.DaqCount]))+
                        (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
        /* Force DWORD alignment for ODT entries */
        Xcp_Data.pOdtEntryAddr = (uint8**) ((((uint32)&Xcp_Data.pOdt[Xcp_Data.Daq.OdtCount])+
                                 (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
        Xcp_Data.pOdtEntrySize = (uint8*)&Xcp_Data.pOdtEntryAddr[Xcp_Data.Daq.OdtEntryCount];

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
        /* Force WORD alignment for the queue */
        /* Allign to dwords */
        Xcp_Data.pQueue = (Xcp_Dto_st*)((((uint32)(&Xcp_Data.pOdtEntrySize[Xcp_Data.Daq.OdtEntryCount]))+
                          (uint32)XCP_THREE) & (uint32)0xFFFFFFFCU);
        queuesize = ((uint16)XCP_DAQMEMSIZE - size) / sizeof(Xcp_Dto_st);
        if( XCP_128 <= queuesize)
        {
            /* Maximum possible size because of the modulo operation in XcpQueueWrite */
            Xcp_Data.QueueSize = XCP_127;
        }
        else
        {
            Xcp_Data.QueueSize = (uint8)queuesize;
        }
        /* At least one queue entry per odt */
        if( Xcp_Data.QueueSize < Xcp_Data.Daq.OdtCount )
        {
            retValue = (uint8)CRC_MEMORY_OVERFLOW;
        }
#endif  /* XCP_ENABLE_SEND_QUEUE */

    }
    return retValue;
}

#endif


/*
********************************************************************************
* Function Name: Xcp_AllocStimQueueMemory
*
* Explanation: Allocate Stim Date Receive queue.
*
* retval: E_OK: Alloc success.
*         E_NOT_OK: Alloc not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_AllocStimQueueMemory(void)
{
    uint8 retValue = E_OK;
    uint16 QueueSizeStim;

    Xcp_Data.pQueueStim = (Xcp_Stim_Dto_st*)Xcp_Data.Daq.StimDateBuffer;
    QueueSizeStim = XCP_DAQMEMSIZE_STIM / sizeof(Xcp_Stim_Dto_st);
    if( XCP_128 <= QueueSizeStim)
    {
        /* Maximum possible size because of the modulo operation in XcpQueueWrite */
        Xcp_Data.QueueSizeStim = XCP_127;
    }
    else
    {
        Xcp_Data.QueueSizeStim = (uint8)QueueSizeStim;
    }
    /* At least one queue entry per odt */
    if( Xcp_Data.QueueSizeStim < Xcp_Data.Daq.OdtCount )
    {
        retValue = (uint8)CRC_MEMORY_OVERFLOW;
    }

    return retValue;
}

/*
********************************************************************************
* Function Name: Xcp_AllocDaq
*
* Explanation: Allocate DAQ list.
*
* param: daqCount: Number of daqs in DAQ list.
*
* retval: E_OK: XCP_AllocDaq success.
*         E_NOT_OK: XCP_AllocDaq not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_AllocDaq(uint8 daqCount)
{
    uint8 retValue = E_NOT_OK;

    if( (XCP_ZERO != Xcp_Data.Daq.OdtCount ) || (XCP_ZERO != Xcp_Data.Daq.OdtEntryCount) )
    {
        retValue = (uint8)CRC_SEQUENCE;
    }
    else
    {
        if( (XCP_DAQ_COUNT + XCP_MIN_DAQ) < daqCount )
        {
            retValue = CRC_OUT_OF_RANGE;
        }
        else
        {
            Xcp_Data.Daq.DaqCount = daqCount;
            retValue = Xcp_AllocMemory();
        }
    }

    return retValue;
}

/*
********************************************************************************
* Function Name: Xcp_AllocOdt
*
* Explanation: Allocate all ODTs in a DAQ list.
*
* param: daqCount: Number of odt in DAQ.
*
* retval: E_OK: XCP_AllocOdt success.
*         Any other: XCP_AllocOdt not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_AllocOdt(uint8 daq, uint8 odtCount)
{
    uint8 retValue = E_NOT_OK;

    if( daq >= Xcp_Data.Daq.DaqCount )
    {
        retValue = (uint8)CRC_OUT_OF_RANGE;
    }
    else
    {
        if( XCP_ODT_COUNT < odtCount )
        {
            retValue = CRC_OUT_OF_RANGE;
        }
        else
        {
            Xcp_Data.Daq.u.DaqList[daq].firstOdt = Xcp_Data.Daq.OdtCount;
            Xcp_Data.Daq.OdtCount += odtCount;
            Xcp_Data.Daq.u.DaqList[daq].lastOdt = (uint8)(Xcp_Data.Daq.OdtCount - XCP_ONE);
            retValue = Xcp_AllocMemory();
        }
    }

    return retValue;
}

/*
********************************************************************************
* Function Name: Xcp_AllocOdtEntry
*
* Explanation: Allocate all OdtEntry in a ODT.
*
* param: daq :Currently initialized DAQ.
*        odt :ODT in current DAQ.
*        odtEntryCount :Number of ODT entries in ODT.
*
* retval: E_OK: XCP_AllocOdtEntry success.
*         Any other: XCP_AllocOdtEntry not success.
********************************************************************************
*/
static FUNC(uint8, XCP_CODE) Xcp_AllocOdtEntry(uint8 daq, uint8 odt, uint8 odtEntryCount)
{
    uint8 retValue = E_NOT_OK;
    uint8 xcpFirstOdt = XCP_ZERO;

    if( (XCP_ZERO== Xcp_Data.Daq.DaqCount) || (XCP_ZERO == Xcp_Data.Daq.OdtCount) )
    {
        retValue = (uint8)CRC_SEQUENCE;
    }
    else
    {
        /* Absolute ODT entry count count must fit in a WORD */
        if( Xcp_Data.Daq.OdtEntryCount > (XCP_FFFF - odtEntryCount) )
        {
            retValue = (uint8)CRC_MEMORY_OVERFLOW;
        }
        else
        {
            if( XCP_ODT_ENTRYS_COUNT < odtEntryCount )
            {
                retValue = CRC_OUT_OF_RANGE;
            }
            else
            {
                xcpFirstOdt = Xcp_Data.Daq.u.DaqList[daq].firstOdt;
                Xcp_Data.pOdt[xcpFirstOdt + odt].firstOdtEntry = Xcp_Data.Daq.OdtEntryCount;
                Xcp_Data.Daq.OdtEntryCount += (uint16)odtEntryCount;
                Xcp_Data.pOdt[xcpFirstOdt + odt].lastOdtEntry = (uint16)(Xcp_Data.Daq.OdtEntryCount - XCP_ONE);
                retValue = Xcp_AllocMemory();
            }
        }
    }

    return retValue;
}

/*
********************************************************************************
* Function Name: Xcp_StartDaq
*
* Explanation: Start the transfer of the specified DAQ list.
*
* param: daq: The Daq list you want to start.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_StartDaq(uint8 daq)
{
    /* Initialize the DAQ list */
    DaqListFlags(daq) |= (uint8)DAQ_FLAG_RUNNING;

#if ( XCP_PRESCALER_SUPPORTED == STD_ON )
    DaqListCycle(daq) = XCP_ONE;
#endif

    Xcp_Data.SessionStatus |= (uint8)SS_DAQ;
}

/*
********************************************************************************
* Function Name: Xcp_StartAllSelectedDaq
*
* Explanation: Start all selected DAQs.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_StartAllSelectedDaq(void)
{
    uint8 daq = XCP_ZERO;

    /* Start all selected DAQs */
    for( daq = XCP_ZERO; daq < Xcp_Data.Daq.DaqCount; daq++ )
    {
        if( (DaqListFlags(daq) & (uint8)DAQ_FLAG_SELECTED) != XCP_ZERO )
        {
            Xcp_StartDaq(daq);
            DaqListFlags(daq) &= (uint8)(~DAQ_FLAG_SELECTED) & XCP_00FF;
        }
    }
}

/*
********************************************************************************
* Function Name: Xcp_StopDaq
*
* Explanation: Stop DAQ.
*
* param: daq: The Daq list you want to stop.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_StopDaq(uint8 daq)
{
    uint8 acIndex_i = XCP_ZERO;
    uint8 reValue = XCP_ZERO;
    DaqListFlags(daq) &= (uint8)(DAQ_FLAG_DIRECTION|DAQ_FLAG_TIMESTAMP|DAQ_FLAG_NO_PID);

    /* Check if all DAQ lists are stopped */
    for( acIndex_i = XCP_ZERO; acIndex_i < Xcp_Data.Daq.DaqCount; acIndex_i++ )
    {
        if( XCP_ZERO != (DaqListFlags(acIndex_i) & (uint8)DAQ_FLAG_RUNNING)  )
        {
            reValue = XCP_ONE;
        }
    }
    if( XCP_ZERO == reValue )
    {
        Xcp_Data.SessionStatus &= (uint8)(~SS_DAQ) & XCP_00FF;

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
        Xcp_QueueInit();
#endif

    }
}

/*
********************************************************************************
* Function Name: Xcp_StopAllSelectedDaq
*
* Explanation: Stop all selected DAQs.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_StopAllSelectedDaq(void)
{
    uint8 daq;

    for( daq = XCP_ZERO; daq < Xcp_Data.Daq.DaqCount; daq++ )
    {
        if( XCP_ZERO != (DaqListFlags(daq) & (uint8)DAQ_FLAG_SELECTED)  )
        {
            Xcp_StopDaq(daq);
            DaqListFlags(daq) &= (uint8)(~DAQ_FLAG_SELECTED) & XCP_00FF;
        }
    }
}

/*
********************************************************************************
* Function Name: Xcp_StopAllDaq
*
* Explanation: Stop all DAQs.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_StopAllDaq(void)
{
    uint8 daq;

    for( daq = XCP_ZERO; daq < Xcp_Data.Daq.DaqCount; daq++ )
    {
        DaqListFlags(daq) &= (uint8)(DAQ_FLAG_DIRECTION|DAQ_FLAG_TIMESTAMP|DAQ_FLAG_NO_PID);
    }
    Xcp_Data.SessionStatus &= (uint8)(~SS_DAQ) & XCP_00FF;

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    Xcp_QueueInit();
#endif

    Xcp_FreeDaq();
}
#endif /* XCP_ENABLE_DAQ */

/*
********************************************************************************
* Function Name: XCP_RecordError
*
* Explanation: xcp command handles error jumps.
*
* param: err: Return Codes
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_RecordError(uint8 err)
{
    Xcp_Data.CrmLen = XCP_TWO;
    CRM_CMD = (uint8)PID_ERR;
    CRM_ERR = (uint8)err;
}

/*
********************************************************************************
* Function Name: Xcp_CC_Sync
*
* Explanation: Execute command CC_Sync.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Sync(void)
{
     /* Always return a negative response with the error code ERR_CMD_SYNCH. */
    Xcp_Data.CrmLen = CRM_SYNCH_LEN;
    CRM_CMD    = PID_ERR;           /* CRM[0] */
    CRM_ERR    = CRC_CMD_SYNCH;     /* CRM[1] */
}

#ifdef XCP_ENABLE_COMM_MODE_INFO
/*
********************************************************************************
* Function Name: Xcp_CC_GetCommModeInfo
*
* Explanation: Execute command CC_GetCommModeInfo.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetCommModeInfo(void)
{
    Xcp_Data.CrmLen = CRM_GET_COMM_MODE_INFO_LEN;

#if( STD_ON == XCP_BLOCK_DOWNLOAD )
    CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL = CMO_MASTER_BLOCK_MODE;      /* CRM[2] */
    CRM_GET_COMM_MODE_INFO_MAX_BS = XCPBLOCK_SIZE;             /* CRM[4] */
    CRM_GET_COMM_MODE_INFO_MIN_ST = XCPBLOCK_MIN_ST;             /* CRM[5] */
#else
    CRM_GET_COMM_MODE_INFO_COMM_OPTIONAL = XCP_ZERO;      /* CRM[2] */
    CRM_GET_COMM_MODE_INFO_MAX_BS = XCP_ZERO;             /* CRM[4] */
    CRM_GET_COMM_MODE_INFO_MIN_ST = XCP_ZERO;             /* CRM[5] */
#endif

    CRM_GET_COMM_MODE_INFO_QUEUE_SIZE = XCP_ZERO;         /* CRM[6] */
    CRM_GET_COMM_MODE_INFO_DRIVER_VERSION = (uint8)(((CP_XCP_VERSION & 0x0F00U) >> XCP_FOUR)
                                                    |(CP_XCP_VERSION & 0x000FU)); /* CRM[7] */
}
#endif

/*
********************************************************************************
* Function Name: Xcp_InitCalPage
*
* Explanation: xcp init calibration page.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_InitCalPage(void)
{

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
    XcpCalOffset = XCP_ZERO;
#endif
    Xcp_Data.PageInd = XCP_ZERO;

}

/*
********************************************************************************
* Function Name: Xcp_CC_Disconnect
*
* Explanation: Execute command CC_disconnect.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Disconnect(void)
{
    Xcp_Data.CrmLen = CRM_DISCONNECT_LEN;
    Xcp_Disconnect();
    /*xcp init calibration page*/
    Xcp_InitCalPage();
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetID
*
* Explanation: Execute command CC_GetID.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetID
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    Xcp_Data.CrmLen = CRM_GET_ID_LEN;
    CRM_GET_ID_MODE = XCP_ZERO;
    CRM_GET_ID_LENGTH = XCP_ZERO;
    /* Which types are supported by the slave device is implementation specific */
    if( CRO_GET_ID_TYPE == IDT_ASAM_NAME )    /* Type = ASAM MC2 , only support this style */
    {
        CRM_GET_ID_LENGTH = (uint32)XCP_STATIONIDLENGTH;
        XCPSETMTA(Xcp_GetPointer(XCP_FF, (uint32)( & Xcp_StationId[XCP_ZERO])), XCP_FF);
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetStatus
*
* Explanation: Execute command CC_GetStatus.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetStatus(void)
{
    Xcp_Data.CrmLen = CRM_GET_STATUS_LEN;
    CRM_GET_STATUS_STATUS = Xcp_Data.SessionStatus;      /* CRM[1] */

#if( XCP_ENABLE_SEED_KEY == STD_ON )
        /* Return current resource protection status. If a bit is one,
           the associated resource is locked. */
        CRM_GET_STATUS_PROTECTION = Xcp_Data.ProtectionStatus;
#else
        CRM_GET_STATUS_PROTECTION = XCP_ZERO;             /* CRM[2] */
#endif

    /* Session configuration ID not available. */
    CRM_GET_STATUS_CONFIG_ID = XCP_ZERO;               /* CRM[4] CRM[5] */
}

#if( XCP_ENABLE_SEED_KEY == STD_ON )
/*
********************************************************************************
* Function Name: Xcp_CC_GetSeed
*
* Explanation: Execute command CC_GetSeed.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetSeed
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint16 maxLen = XCP_MAX_CTO - XCP_TWO;
    Xcp_Resource = CRO_GET_SEED_RESOURCE;

    if( RM_CAL_PAG == Xcp_Resource ||
        RM_DAQ == Xcp_Resource ||
        RM_STIM == Xcp_Resource ||
        RM_PGM == Xcp_Resource )
    {
        if( CRO_GET_SEED_MODE == XCP_ONE )
        {
            /* Determine if the order of instructions is correct */
            if( TRUE == Xcp_SafeSeedFlag )
            {
                Xcp_SafeLen -= maxLen;
                if( Xcp_SafeLen > maxLen )
                {
                    Xcp_MemCpy8((uint8*)CRM_GET_SEED_DATA,(uint8*)&Xcp_Resource_Array[Xcp_SafeAddLen], (uint32)maxLen);
                    Xcp_Data.CrmLen = XCP_MAX_CTO;
                    Xcp_SafeAddLen += maxLen;
                }
                else
                {
                    Xcp_MemCpy8((uint8*)CRM_GET_SEED_DATA,(uint8*)&Xcp_Resource_Array[Xcp_SafeAddLen], (uint32)Xcp_SafeLen);
                    Xcp_Data.CrmLen = (Xcp_SafeLen + XCP_TWO);
                    Xcp_SafeLen = XCP_ZERO;
                    Xcp_SafeSeedFlag = FALSE;
                }
                CRM_GET_SEED_LENGTH = Xcp_SafeLen;
            }
            else
            {
                /* Command 1 not sent after command 0 */
                Xcp_RecordError(CRC_SEQUENCE);
                /* Recovery status */
                Xcp_SafeSeedFlag = FALSE;
                Xcp_SafeFlag = FALSE;
                Xcp_SafeAddLen = XCP_ZERO;
                Xcp_SafeLen = XCP_ZERO;
            }
        }
        else
        {
            if( (Xcp_Data.ProtectionStatus & CRO_GET_SEED_RESOURCE) != XCP_ZERO )   /* locked */
            {
                /* Determine whether the previous seed acquisition was completed */
                if( XCP_ZERO == Xcp_SafeLen )
                {
                    (void)XcpGetSeed();
                    Xcp_SafeSeedFlag = TRUE;
                    Xcp_SafeFlag = TRUE;
                    Xcp_SafeAddLen = XCP_ZERO;
                    Xcp_SafeLen = XCP_SAFELEN;
                    CRM_GET_SEED_LENGTH = XCP_SAFELEN;
                    if( XCP_SAFELEN <= maxLen )
                    {
                        Xcp_MemCpy8((uint8*)CRM_GET_SEED_DATA,(uint8*)Xcp_Resource_Array, (uint32)XCP_SAFELEN);
                        Xcp_Data.CrmLen = CRM_GET_SEED_LEN;
                    }
                    else
                    {
                        Xcp_MemCpy8((uint8*)CRM_GET_SEED_DATA,(uint8*)Xcp_Resource_Array, (uint32)maxLen);
                        Xcp_Data.CrmLen = XCP_MAX_CTO;
                        Xcp_SafeAddLen += maxLen;
                    }
                }
                else
                {
                    /* Seed acquisition not completed, proceed to obtain new seeds */
                    Xcp_RecordError(CRC_OUT_OF_RANGE);
                    /* Recovery status */
                    Xcp_SafeSeedFlag = FALSE;
                    Xcp_SafeFlag = FALSE;
                    Xcp_SafeAddLen = XCP_ZERO;
                    Xcp_SafeLen = XCP_ZERO;
                }
            }
            else    /* Unlocked */
            {
                /* return 0 if the resource is unprotected. */
            }
        }
    }
    else
    {   /* Request ID error */
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_UnLock
*
* Explanation: Execute command CC_UnLock.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_UnLock
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    boolean unlockFlag = FALSE;
    uint8 maxLen = XCP_MAX_CTO - XCP_TWO;
    uint8 reVal = E_NOT_OK;

    if( (TRUE == Xcp_SafeFlag) && (XCP_ZERO == Xcp_SafeLen) )
    {
        if( CRO_UNLOCK_LENGTH > maxLen )
        {
            reVal = XcpUnlock(CRO_UNLOCK_KEY, maxLen);
        }
        else
        {
            reVal = XcpUnlock(CRO_UNLOCK_KEY, CRO_UNLOCK_LENGTH);
            unlockFlag = TRUE;
            Xcp_SafeFlag = FALSE;
        }
        if( E_NOT_OK == reVal )
        {
            /* Key wrong ! */
            /* Send ERR_ACCESS_LOCKED and go to disconnected state. */
            Xcp_Disconnect();
            Xcp_RecordError(CRC_ACCESS_LOCKED);
            Xcp_SafeFlag = FALSE;
        }
        else if( FALSE == unlockFlag )
        {
            CRM_UNLOCK_PROTECTION = Xcp_Data.ProtectionStatus;
            Xcp_Data.CrmLen = CRM_UNLOCK_LEN;
        }
        else
        {
            /* unlock (reset) the appropriate resource protection mask bit. */
            Xcp_Data.ProtectionStatus &= (uint8)~Xcp_Resource;
            /* .and return the current resource protection status. */
            CRM_UNLOCK_PROTECTION = Xcp_Data.ProtectionStatus;
            Xcp_Data.CrmLen = CRM_UNLOCK_LEN;
        }
    }
    else
    {
        Xcp_RecordError(CRC_SEQUENCE);
        /* Recovery status */
        Xcp_SafeSeedFlag = FALSE;
        Xcp_SafeFlag = FALSE;
        Xcp_SafeAddLen = XCP_ZERO;
        Xcp_SafeLen = XCP_ZERO;
    }
}
#endif /* defined (XCP_ENABLE_SEED_KEY) */

#ifdef XCP_ENABLE_CALIBRATION_PAGE
/*
********************************************************************************
* Function Name: ApplXcpSetCalPage
*
* Explanation: Set calibration page.
*
* param: segment: calibration segment.
*        page: calibration page.
*        mode: calibration mode.
*
* retval: uint8: Always return 0.
********************************************************************************
*/
volatile uint8 Overlay_Status = 0;
FUNC(uint8, XCP_CODE) ApplXcpSetCalPage(uint8 segment, uint8 page, uint8 mode)
{
    /* Reserved */
    XCP_DUMMY_STATEMENT(segment);
    XCP_DUMMY_STATEMENT(page);
    XCP_DUMMY_STATEMENT(mode);

    //manual_code_whz start
    status_t ret = STATUS_SUCCESS;
    if(1 == page)
    {
        flash_remap_config_t remapConfig;
        uint32_t flashMirrAddr = CALFLASH_ADDR;
        uint32_t sramAddr = CALRAM_ADDR;

        remapConfig.flsLogicAddr = flashMirrAddr;
        remapConfig.ramPhyAddr = sramAddr;
        remapConfig.remapSize = XCP_valCALRAM_REMAPSIZE_MP;
        ret = FLASH_LLD_Overlay_Config_Enable(0U, &remapConfig);
        if (STATUS_SUCCESS != ret)
        {
            return ret;
        }

        ret = FLASH_LLD_Overlay_Golbal_Enable();
        if (STATUS_SUCCESS != ret)
        {
            return ret;
        }
        Overlay_Status = 1;
    }
    else
    {
        ret = FLASH_LLD_Overlay_Config_Disable(0U);
        if (STATUS_SUCCESS != ret)
        {
            return ret;
        }

        ret = FLASH_LLD_Overlay_Golbal_Disable();
        if (STATUS_SUCCESS != ret)
        {
            return ret;
        }
        Overlay_Status = 2;

    }
    //manual_code_whz end

    return XCP_ZERO;
}

/*
********************************************************************************
* Function Name: ApplXcpGetCalPage
*
* Explanation: Get calibration page.
*
* param: avcSegment: calibration segment.
*        avcMode: calibration mode.
*
* retval: uint8: calibration page.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) ApplXcpGetCalPage(uint8 avcSegment, uint8 avcMode)
{
    uint8 returnValue = XCP_ZERO;
    XCP_DUMMY_STATEMENT(avcSegment);

    if( (avcMode & (CAL_ECU | CAL_XCP)) == CAL_ECU )
    {
        returnValue = Xcp_CalPage;
    }
    else if( (avcMode & (CAL_ECU | CAL_XCP)) == CAL_XCP )
    {
        returnValue = Xcp_WorkingPage;
    }
    else
    {
        returnValue = Xcp_WorkingPage;
    }
    return returnValue;
}
#endif

#ifdef XCP_ENABLE_CALIBRATION_PAGE
/*
********************************************************************************
* Function Name: Xcp_CC_SetCalpage
*
* Explanation: Execute command CC_SetCalpage.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_SetCalpage
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
#if( RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
    uint8 ret = XCP_E_NOT_OK;
#endif
    /* Judge whether the segment and page is out of range */
    if( CRO_SET_CAL_PAGE_SEGMENT < XCP_TWO)
    {
        if(CRO_SET_CAL_PAGE_PAGE < XCP_TWO)
        {
            Xcp_Data.PageInd = CRO_SET_CAL_PAGE_PAGE;

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
            if( XCP_ONE == Xcp_Data.PageInd )
            {
                XcpCalOffset = CALRAM_ADDR - CALFLASH_ADDR;
            }
            else
            {
                XcpCalOffset = XCP_ZERO;
            }
#endif

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
            if( XCP_ZERO == Xcp_Data.PageInd )
            {
                Xcp_CalVectReset(&Xcp_VectList);
            }
#endif
            /* sets the access mode for a calibration data segment */
            (void)ApplXcpSetCalPage(CRO_SET_CAL_PAGE_SEGMENT, CRO_SET_CAL_PAGE_PAGE, CRO_SET_CAL_PAGE_MODE);
#if( RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
            ret = XcpOverlayMapping(CRO_SET_CAL_PAGE_SEGMENT, CRO_SET_CAL_PAGE_PAGE, CRO_SET_CAL_PAGE_MODE);
            if( XCP_E_NOT_OK == ret )
            {
                Xcp_RecordError(CRC_PAGE_MODE_NOT_VALID);
            }
#endif
        }
        else
        {
            Xcp_RecordError(CRC_PAGE_NOT_VALID);
        }
    }
    else
    {
        Xcp_RecordError(CRC_SEGMENT_NOT_VALID);
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetCalPage
*
* Explanation: Execute command CC_GetCalPage.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetCalPage
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    Xcp_Data.CrmLen = CRM_GET_CAL_PAGE_LEN;
    /* CRM[3] */
    CRM_GET_CAL_PAGE_PAGE = ApplXcpGetCalPage(
                                CRO_GET_CAL_PAGE_SEGMENT,
                                CRO_GET_CAL_PAGE_MODE);
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetPagProcessorInfo
*
* Explanation: Execute command CC_GetPagProcessorInfo.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetPagProcessorInfo(void)
{
    Xcp_Data.CrmLen = CRM_GET_PAG_PROCESSOR_INFO_LEN;

    CRM_GET_PAG_PROCESSOR_INFO_MAX_SEGMENT = (uint8)XCP_MAXSEGMENT; /* CRM[1] */

#ifdef XCP_ENABLE_PAGE_FREEZE /* CRM[2] */
    CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES  = XCP_ONE;    /* FREEZE_SUPPORTED = 1 */
#else
    CRM_GET_PAG_PROCESSOR_INFO_PROPERTIES  = XCP_ZERO;    /* FREEZE_SUPPORTED = 0 */
#endif

}
#endif /* defined (XCP_ENABLE_CALIBRATION_PAGE) */

/*
********************************************************************************
* Function Name: Xcp_CC_GetSegmentInfo
*
* Explanation: Execute command CC_GetSegmentInfo.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetSegmentInfo
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    if( CRO_GET_SEGMENT_INFO_NUMBER >= (uint8)XCP_MAXSEGMENT )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
            Xcp_Data.CrmLen = CRM_GET_SEGMENT_INFO_LEN;
        /* Get standard info for a segment.
        SEGMENT_INFO and MAPPING_INDEX are don't care
        */
        if( CRO_GET_SEGMENT_INFO_MODE == XCP_ONE )
        {
            CRM_GET_SEGMENT_INFO_MAX_PAGES         = XCP_TWO;  /* CRM[1] */
            CRM_GET_SEGMENT_INFO_ADDRESS_EXTENSION = XCP_ZERO; /* CRM[2] */
            CRM_GET_SEGMENT_INFO_MAX_MAPPING       = XCP_ZERO; /* CRM[3] */
            CRM_GET_SEGMENT_INFO_COMPRESSION       = XCP_ZERO; /* CRM[4] */
            CRM_GET_SEGMENT_INFO_ENCRYPTION        = XCP_ZERO; /* CRM[5] */
        }
        /* Get basic address info for a segment:
        SEGMENT_INFO contains address range information and
        MAPPING_INDEX is don't care
        Get address mapping for a segment:
        SEGMENT_INFO contains address range information and
        MAPPING_INDEX indicates the range MAPPING_INFO belongs to
        */
        if( (CRO_GET_SEGMENT_INFO_MODE == XCP_ZERO) || (CRO_GET_SEGMENT_INFO_MODE == XCP_TWO) )
        {
        /*  mode = 0
            If SEGMENT_INFO = 0 , this command returns the
            address of this SEGMENT in BASIC_INFO.
            If SEGMENT_INFO = 1 , this command returns the
            length of this SEGMENT in BASIC_INFO.

            mode = 2
            If SEGMENT_INFO = 0 , this command returns the source
            address for this MAPPING_INDEX in MAPPING_INFO.
            If SEGMENT_INFO = 1 , this command returns the
            destination address for this MAPPING_INDEX in MAPPING_INFO.
            If SEGMENT_INFO = 2 , this command returns the
            length for this MAPPING_INDEX in MAPPING_INFO.
        */
            CRM_GET_SEGMENT_INFO_MAPPING_INFO = XCP_ZERO;
        }
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetPageInfo
*
* Explanation: Execute command CC_GetPageInfo.
*
* param: pCmd: Accept instructions and parameters.
*        err: error code.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetPageInfo
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    /* Determine if segments and pages to view are out of range */
    if( (CRO_GET_PAGE_INFO_SEGMENT_NUMBER > ((uint8)(XCP_MAXSEGMENT - XCP_ONE) & XCP_FF)) ||
    (CRO_GET_PAGE_INFO_PAGE_NUMBER > ((uint8)(XCP_MAXPAGES - XCP_ONE) & XCP_FF)) )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        Xcp_Data.CrmLen = CRM_GET_PAGE_INFO_LEN;
        CRM_GET_PAGE_INFO_PROPERTIES = XCP_ZERO;  /* CRM[1] */
        /* A subsequent return value should be added */
    }
}

#ifdef XCP_ENABLE_PAGE_COPY
/*
********************************************************************************
* Function Name: Xcp_CC_CopyCalPage
*
* Explanation: Execute command CC_CopyCalPage.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_CopyCalPage
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd,
)
{
    uint8 err = XCP_ZERO;
    Xcp_Data.CrmLen = CRM_COPY_CAL_PAGE_LEN;
    /* copy one calibration page to another */
    err = ApplXcpCopyCalPage( CRO_COPY_CAL_PAGE_SRC_SEGMENT,
                              CRO_COPY_CAL_PAGE_SRC_PAGE,
                              CRO_COPY_CAL_PAGE_DEST_SEGMENT,
                              CRO_COPY_CAL_PAGE_DEST_PAGE);
    if( (uint8)XCP_CMD_PENDING == err )
    {
        /* Reserved */
    }
    else
    {
        CHECK_ERROR(err);
    }
}
#endif

/*
********************************************************************************
* Function Name: Xcp_CC_SetMta
*
* Explanation: Execute command CC_SetMta.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_SetMta
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    /* Initialize a pointer (CRO_SET_MTA_ADDR + CRO_SET_MTA_EXT) */
    XCPSETMTA(Xcp_GetPointer(CRO_SET_MTA_EXT, CRO_SET_MTA_ADDR), CRO_SET_MTA_EXT);
}

/*
********************************************************************************
* Function Name: Xcp_CC_Download
*
* Explanation: Execute command CC_Download.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Download
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 size = XCP_ZERO;
    uint8 err = XCP_CMD_DENIED;

    CheckResourceProtection(RM_CAL_PAG)
    /*check whether there are enough resources available in order to cover the complete download request*/
    size = CRO_DOWNLOAD_SIZE;
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
    Xcp_Data.NextDownloadSize = CRO_DOWNLOAD_SIZE;
#endif
    if( CRO_DOWNLOAD_MAX_SIZE < size )
    {
        size = CRO_DOWNLOAD_MAX_SIZE;
        CanXcpGetStatus = TRUE;
    }
    err = Xcp_WriteMta(size, CRO_DOWNLOAD_DATA);

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    if( (uint8)XCP_CMD_PENDING == err )
    {
        /* When the download is successful, set the wait bit and reduce the download volume  */
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
        Xcp_Data.NextDownloadSize -= size;
#endif
        Xcp_Pending = XCP_ONE;  /* Send pending */
    }
#elif( RTECALIBRATIONSUPPORT != RTE_MMU_METHOD )
    if( (uint8)XCP_CMD_DENIED == err )
    {
        Xcp_RecordError(CRC_WRITE_PROTECTED);
    }
#else
    XCP_DUMMY_STATEMENT(err);
#endif
    /* When the download is successful, set the wait bit and reduce the download volume  */
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
    Xcp_Data.NextDownloadSize -= size;
    if( Xcp_Data.NextDownloadSize > XCP_ZERO )
    {
        Xcp_Pending = XCP_ONE;  /* Send pending */
    }
#endif
}

#if( STD_ON == XCP_BLOCK_DOWNLOAD )
/*
********************************************************************************
* Function Name: Xcp_CC_DownloadNext
*
* Explanation: Execute command CC_Download.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_DownloadNext
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 size = XCP_ZERO;
    uint8 err = XCP_CMD_DENIED;

    CheckResourceProtection(RM_CAL_PAG)
    /*check whether there are enough resources available in order to cover the complete download request*/
    size = CRO_DOWNLOAD_NEXT_SIZE;
    if( CRO_DOWNLOAD_NEXT_SIZE != Xcp_Data.NextDownloadSize )
    {
        Xcp_RecordError(CRC_SEQUENCE);
    }
    else
    {
        /* Copying of size bytes from CRO_DOWNLOAD_DATA to Xcp_Data.Mta */
        if( CRO_DOWNLOAD_NEXT_MAX_SIZE < size )
        {
            err = Xcp_WriteMta(CRO_DOWNLOAD_NEXT_MAX_SIZE, CRO_DOWNLOAD_DATA);
            Xcp_Data.NextDownloadSize -= CRO_DOWNLOAD_NEXT_MAX_SIZE;
            CanXcpGetStatus = TRUE;
        }
        else
        {
            err = Xcp_WriteMta(size, CRO_DOWNLOAD_NEXT_DATA);
            Xcp_Data.NextDownloadSize = XCP_ZERO;
            /* When using block transfer, resetting the pending bit is performed here */
            Xcp_Pending = XCP_ZERO;
        }
#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
        if( (uint8)XCP_CMD_PENDING == err )
        {
            /* pending */
        }
#elif( RTECALIBRATIONSUPPORT != RTE_MMU_METHOD )
        if( (uint8)XCP_CMD_DENIED == err )
        {
            Xcp_RecordError(CRC_WRITE_PROTECTED);
        }
        else
        {
            /* do nothing */
        }
#else
    XCP_DUMMY_STATEMENT(err);
#endif
    }
}
#endif

/*
********************************************************************************
* Function Name: Xcp_CC_DownloadMax
*
* Explanation: Execute command CC_DownloadMax.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_DownloadMax
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 err = XCP_ZERO;
    CheckResourceProtection( RM_CAL_PAG )
     /* Copying of CRO_DOWNLOAD_MAX_MAX_SIZE bytes from
     CRO_DOWNLOAD_MAX_DATA to Xcp_Data.Mta */

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
    err = Xcp_WriteMta(CRO_DOWNLOAD_MAX_MAX_SIZE, CRO_DOWNLOAD_MAX_DATA);
    if( XCP_CMD_SYNTAX == err )
    {
        Xcp_RecordError(CRC_CMD_SYNTAX);
    }
#else
    (void)Xcp_WriteMta(CRO_DOWNLOAD_MAX_MAX_SIZE, CRO_DOWNLOAD_MAX_DATA);
    XCP_DUMMY_STATEMENT(err);
#endif
    

}

/*
********************************************************************************
* Function Name: Xcp_CC_UpLoad
*
* Explanation: Execute command CC_UpLoad.
*
* param: pCmd: Accept instructions and parameters.
*        err: Error code.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_UpLoad
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 size = CRO_UPLOAD_SIZE;

#if( STD_ON == XCP_BLOCK_UPLOAD )
    /* #20 If the number of requested bytes to be uploaded exceeds max CTO-1:
     * Store missing number of bytes to be uploaded and copy maximum valid
     number of bytes from MTA. */
    if( (uint8)CRM_UPLOAD_MAX_SIZE < size )
    {
        Xcp_Data.NextDataBlockSize = size - (uint8)CRM_UPLOAD_MAX_SIZE;
        size = (uint8)CRM_UPLOAD_MAX_SIZE;
        (void)Xcp_ReadMta(size, CRM_UPLOAD_DATA);
        Xcp_Data.CrmLen = (uint8)((CRM_UPLOAD_LEN + size) & 0xFFu);
        Xcp_Data.SessionStatus |= (uint8)SS_BLOCK_UPLOAD; 
    }
    else
#else
    if( CRM_UPLOAD_MAX_SIZE < size)
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
#endif

    {
        /* Transfer data from Mta to CRM[] */
        (void)Xcp_ReadMta(size, CRM_UPLOAD_DATA);
        Xcp_Data.CrmLen = (uint8)((CRM_UPLOAD_LEN + size) & XCP_FF);

    }
}
/*
********************************************************************************
* Function Name: Xcp_CC_ShortUplod
*
* Explanation: Execute command CC_ShortUplod.
*
* param: pCmd: Accept instructions and parameters.
*        err: Error code.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_ShortUplod
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    if( CRO_SHORT_UPLOAD_SIZE > (uint8)CRM_SHORT_UPLOAD_MAX_SIZE )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        /*Get calibration address to Xcp_Data.Mta */
        XCPSETMTA(Xcp_GetPointer(CRO_SHORT_UPLOAD_EXT, CRO_SHORT_UPLOAD_ADDR), CRO_SHORT_UPLOAD_EXT);
        /* The content in Xcp_Data.Mta is copied to Xcp_Data.Crm.bytes [x] for sending to the master */
        (void)Xcp_ReadMta(CRO_SHORT_UPLOAD_SIZE, CRM_SHORT_UPLOAD_DATA);
        Xcp_Data.CrmLen = (uint8)((CRM_SHORT_UPLOAD_LEN + CRO_SHORT_UPLOAD_SIZE) & XCP_FF);
    }
}

#if( STD_ON == XCP_ENABLE_CHECKSUM )
/*
********************************************************************************
* Function Name: Xcp_CC_BuildCheckum
*
* Explanation: Execute command CC_BuildCheckum.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_BuildCheckum
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
#if( XCP_ADD12 == XCP_CHECKSUM_TYPE || XCP_ADD11 == XCP_CHECKSUM_TYPE )
    uint8 err = XCP_ZERO;
#endif
    uint32 check_size = XCP_ZERO;
    /* Initialization of checksum calculation. */
    Xcp_Data.CheckSum = (tXcpChecksumSumType)XCP_ZERO;
    check_size = CRO_BUILD_CHECKSUM_SIZE;

    /* The blocksize is limited to WORD length. */
    /* If the blocksize exceeds the allowed maximum transmit negative response. */
#if( XCP_ADD12 == XCP_CHECKSUM_TYPE )
    if( (check_size & (uint32)XCP_FFFF0000) != (uint32)XCP_ZERO )
    {
        CRM_BUILD_CHECKSUM_RESULT = XCP_FFFF;    /* Range, max. 64K-1 */
        err = CRC_OUT_OF_RANGE;
        Xcp_Data.CrmLen = CRM_BUILD_CHECKSUM_LEN;
        /* Response length is arbitrary */
        CRM_CMD = (uint8)PID_ERR;
        CRM_ERR = (uint8)err;
    }
    else
    {
        Xcp_Data.CheckSumSize = (uint16)check_size;
    }
#elif( XCP_ADD11 == XCP_CHECKSUM_TYPE )
    if( (check_size & (uint32)XCP_FFFF0000) != (uint32)XCP_ZERO )
    {
        CRM_BUILD_CHECKSUM_RESULT = XCP_FF;
        err = CRC_OUT_OF_RANGE;
        Xcp_Data.CrmLen = CRM_BUILD_CHECKSUM_LEN;

        /* Response length is arbitrary */
        CRM_CMD = (uint8)PID_ERR;
        CRM_ERR = (uint8)err;
    }
    else
    {
        Xcp_Data.CheckSumSize = (uint16)check_size;
    }
#else
    Xcp_Data.CheckSumSize = check_size;
    Xcp_Data.Crc32Flag = TRUE;
#endif

    return;    /* Checksum calculation will be performed by XcpBackground() */
}
#endif

/*
********************************************************************************
* Function Name: ApplXcpGetTimestamp
*
* Explanation: Get time stamp.
*
* param: None
*
* retval: Xcp_TimestampType: The value of time stamp.
********************************************************************************
*/
FUNC(Xcp_TimestampType, XCP_CODE) ApplXcpGetTimestamp(void)
{
    Xcp_TimestampType xcpTimestamp = XCP_ZERO; /* XCP timestamp */
    TickType counterTick = XCP_ZERO;
    GetCounterValue((CounterType)XCP_COUNTER_REF, &counterTick);
    xcpTimestamp = (Xcp_TimestampType)(counterTick);

    return xcpTimestamp;
}

#ifdef XCP_ENABLE_DAQ
/*
********************************************************************************
* Function Name: Xcp_CC_GetDaqProcessorInfo
*
* Explanation: Execute command CC_GetDaqProcessorInfo.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqProcessorInfo(void)
{
    Xcp_Data.CrmLen = CRM_GET_DAQ_PROCESSOR_INFO_LEN;

    CRM_GET_DAQ_PROCESSOR_INFO_PROPERTIES = (uint8)( XCPDAQCONFIGTYPE

#if( XCP_PRESCALER_SUPPORTED == STD_ON )
        | DAQ_PROPERTY_PRESCALER
#endif

#if( XCP_TIMESTAMP_TYPE != XCPTS_NO_TIME_STAMP )
        | DAQ_PROPERTY_TIMESTAMP
#endif
#if defined (XCP_ENABLE_DAQ_OVERRUN_INDICATION)    /* DAQ_PROPERTY_OVERLOAD_INDICATION */
        | (uint8)DAQ_OVERLOAD_INDICATION_PID);     /* CRM[1] */
#endif

    CRM_GET_DAQ_PROCESSOR_INFO_MAX_DAQ = Xcp_Data.Daq.DaqCount;    /* CRM[2] CRM[3] */

#ifdef XCP_MAX_EVENT
    CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT = XCP_MAX_EVENT;          /* CRM[4] CRM[5] */
#else
    CRM_GET_DAQ_PROCESSOR_INFO_MAX_EVENT = XCP_ZERO;
#endif

    CRM_GET_DAQ_PROCESSOR_INFO_MIN_DAQ = XCP_MIN_DAQ;              /* CRM[6] */
    /* DTO identification field type: Absolute ODT number */
#if( XCP_IDENTIFICATION_FIELD_TYPE == ID_TYPE_ABSOLUTE )
    CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE = (uint8)DAQ_HDR_PID;   /* CRM[7] */
#else                                                               /* CRM[7] */
    CRM_GET_DAQ_PROCESSOR_INFO_DAQ_KEY_BYTE = (uint8)DAQ_HDR_ODT_DAQB;
#endif

}

/*
********************************************************************************
* Function Name: Xcp_CC_GetDaqResolutionInfo
*
* Explanation: Execute command CC_GetDaqResolutionInfo.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqResolutionInfo(void)
{
    Xcp_Data.CrmLen = CRM_GET_DAQ_RESOLUTION_INFO_LEN;

    CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_DAQ = XCP_ONE;                      /* CRM[1] */
    CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_DAQ  = (uint8)XCP_ODT_ENTRY_SIZE_DAQ;  /* CRM[2] */
    CRM_GET_DAQ_RESOLUTION_INFO_GRANULARITY_STIM = XCP_ONE;                     /* CRM[3] */
    CRM_GET_DAQ_RESOLUTION_INFO_MAX_SIZE_STIM = (uint8)XCP_ODT_ENTRY_SIZE_STIM;  /* CRM[4] */

#if( XCP_TIMESTAMP_TYPE > XCP_ZERO )
    CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE = (uint8)XCP_TIMESTAMP_TYPE|XCP_TIMESTAMP_UNIT;
    /*Missing a configuration item  TIMESTAMP_FIXED */
#else
    CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_MODE = XCP_ZERO;
#endif

    CRM_GET_DAQ_RESOLUTION_INFO_TIMESTAMP_TICKS = XCP_TIMESTAMP_TICKS;    /* BCD coded */
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetDaqEventInfo
*
* Explanation: Execute command CC_GetDaqEventInfo.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqEventInfo
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 event = (uint8)CRO_GET_DAQ_EVENT_INFO_EVENT;

    if( (uint8)XCP_MAX_EVENT <= event )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        Xcp_Data.CrmLen = CRM_GET_DAQ_EVENT_INFO_LEN;
        CRM_GET_DAQ_EVENT_INFO_PROPERTIES = Xcp_EventChannel[event].XcpEventChannelType;
        CRM_GET_DAQ_EVENT_INFO_MAX_DAQ_LIST = Xcp_EventChannel[event].XcpEventChannelMaxDaqList;
        CRM_GET_DAQ_EVENT_INFO_NAME_LENGTH = XcpEventNameLength[event];
        CRM_GET_DAQ_EVENT_INFO_TIME_CYCLE = Xcp_EventChannel[event].XcpEventChannelTimeCycle;
        CRM_GET_DAQ_EVENT_INFO_TIME_UNIT = Xcp_EventChannel[event].XcpEventChannelTimeUnit >> XCP_FOUR;
        /*0U Event channel prioritization is not supported. */
        CRM_GET_DAQ_EVENT_INFO_PRIORITY = Xcp_EventChannel[event].XcpEventChannelPriority;
        XCPSETMTA( Xcp_GetPointer(XCP_FF, (uint32)(XcpEventName[event])), XCP_FF);
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_FreeDaq
*
* Explanation: Execute command CC_FreeDaq.
*
* param: None
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_FreeDaq(void)
{
    CheckResourceProtection(RM_DAQ);
    Xcp_FreeDaq();
}

/*
********************************************************************************
* Function Name: Xcp_CC_AllocDaq
*
* Explanation: Execute command CC_AllocDaq.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_AllocDaq
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 err = XCP_ZERO;
    uint8 count = (uint8)CRO_ALLOC_DAQ_COUNT;
    CHECK_ERROR(Xcp_AllocDaq(count));
}

/*
********************************************************************************
* Function Name: Xcp_CC_AllocOdt
*
* Explanation: Execute command CC_AllocOdt.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_AllocOdt
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 err = XCP_ZERO;
    /* Obtain the DAQ number that needs to be modified */
    uint8 daq = (uint8)CRO_ALLOC_ODT_DAQ;
    uint8 count = CRO_ALLOC_ODT_COUNT;

    if( (XCP_ZERO == Xcp_Data.Daq.DaqCount) || (XCP_ZERO != Xcp_Data.Daq.OdtEntryCount) )
    {
        Xcp_RecordError(CRC_SEQUENCE);
    }
    else
    {
        CHECK_ERROR(Xcp_AllocOdt(daq, count));
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_AllocOdtEntry
*
* Explanation: Execute command CC_AllocOdtEntry.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_AllocOdtEntry
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 err = XCP_ZERO;
    uint8 daq = (uint8)CRO_ALLOC_ODT_ENTRY_DAQ;
    uint8 odt = CRO_ALLOC_ODT_ENTRY_ODT;
    uint8 count = CRO_ALLOC_ODT_ENTRY_COUNT;

    if( (daq >= Xcp_Data.Daq.DaqCount) || (odt >= (uint8)DaqListOdtCount(daq)) )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        CHECK_ERROR(Xcp_AllocOdtEntry(daq, odt, count));
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetDaqListMode
*
* Explanation: Execute command CC_GetDaqListMode.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqListMode
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 daq = (uint8)CRO_GET_DAQ_LIST_MODE_DAQ;

    if( daq >= Xcp_Data.Daq.DaqCount )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        Xcp_Data.CrmLen = CRM_GET_DAQ_LIST_MODE_LEN;
        CRM_GET_DAQ_LIST_MODE_MODE = DaqListFlags(daq);    /* CRM[1] */
#ifdef XCP_MAX_EVENT
        /* Lookup in EventDaq[] / DaqListEventChannel(daq) */
        CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL = XCP_ZERO;
#else
        CRM_GET_DAQ_LIST_MODE_EVENTCHANNEL = DaqListEventChannel(daq);
#endif

#if( XCP_PRESCALER_SUPPORTED == STD_ON )
        CRM_GET_DAQ_LIST_MODE_PRESCALER = DaqListPrescaler(daq);    /* CRM[6] */
#else
        CRM_GET_DAQ_LIST_MODE_PRESCALER = XCP_ONE;
#endif
        /* DAQ-list prioritization is not supported. */
        CRM_GET_DAQ_LIST_MODE_PRIORITY = XCP_ZERO;
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_SetDaqListMode
*
* Explanation: Execute command CC_SetDaqListMode.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_SetDaqListMode
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 daq = (uint8)CRO_SET_DAQ_LIST_MODE_DAQ;
    uint8 xcpPrescaler = CRO_SET_DAQ_LIST_MODE_PRESCALER;
    uint8 event = (uint8)(CRO_SET_DAQ_LIST_MODE_EVENTCHANNEL & 0xFFu);

    if( (daq >= Xcp_Data.Daq.DaqCount) || ((uint8)XCP_MAX_EVENT <= event) )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }

#if( XCP_TIMESTAMP_TYPE == XCP_ZERO )
    if( (CRO_SET_DAQ_LIST_MODE_MODE & XCP_DAQ_LIST_TIMESTAMP) > XCP_ZERO )
    {
        Xcp_RecordError(CRC_CMD_SYNTAX);
    }
#endif

    if( CRO_SET_DAQ_LIST_MODE_PRIORITY != XCP_ZERO )    /* Priorization is not supported */
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }

#if( XCP_PRESCALER_SUPPORTED == STD_OFF )
    if( xcpPrescaler != XCP_ONE )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
#endif

    if( PID_ERR != CRM_CMD )
    {

#if( XCP_PRESCALER_SUPPORTED == STD_ON )
        if( XCP_ZERO == xcpPrescaler )
        {
            xcpPrescaler = XCP_ONE;
        }
        DaqListPrescaler(daq) = xcpPrescaler;
#endif

#if defined (XCP_MAX_EVENT) && ! defined (XCP_ENABLE_MULDAQ_EVENT)
        Xcp_Data.Daq.EventDaq[event] = daq;
#else
        DaqListEventChannel(daq) = event;
#endif

        DaqListFlags(daq) = CRO_SET_DAQ_LIST_MODE_MODE;
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_SetDaqPtr
*
* Explanation: Execute command CC_SetDaqPtr.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_SetDaqPtr
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 daq = (uint8) (CRO_SET_DAQ_PTR_DAQ & XCP_FF);
    /* ODT_NUMBER [0,1,..MAX_ODT(DAQ list)-1]  relative ODT number  */
    uint8 odt = CRO_SET_DAQ_PTR_ODT;
    uint8 idx = CRO_SET_DAQ_PTR_IDX;   /* ODT_ENTRY_NUMBER */
    uint8 odt0 = (uint8)(DaqListFirstOdt(daq) + odt);     /* Absolute odt number */

    /* Determine if DAQ, ODT, ODT entry is out of range */
    if( (daq >= Xcp_Data.Daq.DaqCount) || (odt >= (uint8)DaqListOdtCount(daq)) ||
        (idx >= (uint8)DaqListOdtEntryCount(odt0)) )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        Xcp_Data.CrmLen = CRM_SET_DAQ_PTR_LEN;
        Xcp_Data.DaqListPtr = DaqListOdtFirstEntry(odt0) + idx;
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_WriteDaq
*
* Explanation: Execute command CC_WriteDaq.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_WriteDaq
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    CheckResourceProtection( RM_DAQ )
    /* Determine if DAQ, ODT, ODT entry is out of range */
    if( ((uint8)CRO_WRITE_DAQ_SIZE == (uint8)XCP_ZERO) ||
        (CRO_WRITE_DAQ_SIZE > (uint8)XCP_MAX_ODT_ENTRY_SIZE) )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        Xcp_Data.CrmLen = CRM_WRITE_DAQ_LEN;
        OdtEntrySize(Xcp_Data.DaqListPtr) = CRO_WRITE_DAQ_SIZE;
        OdtEntryAddr(Xcp_Data.DaqListPtr) = (uint8*)Xcp_GetPointer(
                                                        CRO_WRITE_DAQ_EXT,
                                                        CRO_WRITE_DAQ_ADDR);
        Xcp_Data.DaqListPtr++; /* Autoincrement */
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_StartStopDaqList
*
* Explanation: Execute command CC_StartStopDaqList.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_StartStopDaqList
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 daq = (uint8)(CRO_START_STOP_DAQ & XCP_FF); /* DAQ_LIST_NUMBER */

    CheckResourceProtection(RM_DAQ)
    if( daq >= Xcp_Data.Daq.DaqCount )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
        Xcp_SendCrm();
    }
    /* 1 = start   2 = select */
    else
    {
        if( (CRO_START_STOP_MODE == XCP_ONE) || (CRO_START_STOP_MODE == XCP_TWO) )
        {
            DaqListFlags(daq) |= (uint8)DAQ_FLAG_SELECTED;
            if( CRO_START_STOP_MODE == XCP_ONE )
            {
                Xcp_StartDaq(daq);
            }
            Xcp_Data.CrmLen = CRM_START_STOP_LEN;

            /* FIRST_PID is the absolute ODT number in the DTO Packet
            of the first ODT transferred by this DAQ list. */
            CRM_START_STOP_FIRST_PID = DaqListFirstPid(daq);
        }
        else
        {
            Xcp_StopDaq(daq);
        }
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_StartStopSynch
*
* Explanation: Execute command CC_StartStopSynch.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_StartStopSynch
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    CheckResourceProtection(RM_DAQ)

    if( CRO_START_STOP_MODE == XCP_TWO ) /* stop selected */
    {
        Xcp_StopAllSelectedDaq();
    }
    else
    {
        if( CRO_START_STOP_MODE == XCP_ONE ) /* start selected */
        {
            Xcp_StartAllSelectedDaq();
        }
        else if( CRO_START_STOP_MODE == XCP_ZERO )
        {
            /* CRO_START_STOP_MODE==0 : stop all */
            Xcp_StopAllDaq();
        }
        else
        {
            /* Do nothing. */
        }
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_GetDaqClock
*
* Explanation: Execute command CC_GetDaqClock.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_GetDaqClock(void)
{
    Xcp_Data.CrmLen = CRM_GET_DAQ_CLOCK_LEN;
    CRM_GET_DAQ_CLOCK_TIME = (uint32)ApplXcpGetTimestamp();
}
#endif /* defined ( XCP_ENABLE_DAQ ) */

#if ( STD_ON == XCP_FLASH_PROGRAMING_ENABLE )
/*
********************************************************************************
* Function Name: Xcp_CC_Program_Start
*
* Explanation: Execute command Xcp_CC_Program_Start.
*
* param: None.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Program_Start(void)
{
    CheckResourceProtection(RM_PGM)
    CRM_PROGRAM_COMM_MODE_PGM = XCP_ZERO;
    CRM_PROGRAM_MAX_CTO_PGM = XCP_MAX_CTO;
#if( STD_ON == XCP_BLOCK_UPLOAD )
    CRM_PROGRAM_COMM_MODE_PGM |= PI_PGM_BLOCK_UPLOAD;
#endif
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
    CRM_PROGRAM_COMM_MODE_PGM |= PI_PGM_BLOCK_DOWNLOAD;
    CRM_PROGRAM_MAX_BS_PGM = XCPBLOCK_SIZE;
    CRM_PROGRAM_MIN_ST_PGM = XCPBLOCK_MIN_ST;
#else
    CRM_PROGRAM_MAX_BS_PGM = XCP_ZERO;
    CRM_PROGRAM_MIN_ST_PGM = XCP_ZERO;
#endif
    CRM_PROGRAM_QUEUE_SIZE_PGM = XCP_ZERO;
    Xcp_Data.CrmLen = CRM_PROGRAM_START_LEN;
}

/*
********************************************************************************
* Function Name: Xcp_CC_Program_Clear
*
* Explanation: Execute command Xcp_CC_Program_Clear.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Program_Clear
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 ret = XCP_E_NOT_OK;
    /* absolute access mode is active */
    if( CRO_PROGRAM_CLEAR_MODE == XCP_ZERO )
    {
        ret = XcpAppl_FlashClear((uint32)Xcp_Data.Mta, CRO_PROGRAM_CLEAR_SIZE);
        if( ret != XCP_E_OK )
        {
            Xcp_RecordError(CRC_OUT_OF_RANGE);
        }
        else
        {
            ;
        }
    }
    else
    {   /* not support  */
        Xcp_RecordError(CRC_CMD_SYNTAX);
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_Program
*
* Explanation: Execute command Xcp_CC_Program.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Program
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 ret = XCP_E_NOT_OK;

    if( CRO_PROGRAM_SIZE > CRO_PROGRAM_MAX_SIZE )
    {
        ret = XcpAppl_FlashProgram((uint32)Xcp_Data.Mta, (uint8*)CRO_PROGRAM_DATA, CRO_PROGRAM_MAX_SIZE);
        if( ret != XCP_E_OK )
        {
            Xcp_RecordError(CRC_OUT_OF_RANGE);
        }
        else
        {
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
            Xcp_Data.NextDownloadSize = (CRO_PROGRAM_SIZE - CRO_PROGRAM_MAX_SIZE);
            Xcp_Pending = XCP_ONE;
            CanXcpGetStatus = TRUE;
            Xcp_Data.Mta += CRO_PROGRAM_MAX_SIZE;
#endif
        }
    }
    else
    {
        ret = XcpAppl_FlashProgram((uint32)Xcp_Data.Mta, (uint8*)CRO_PROGRAM_DATA, CRO_PROGRAM_SIZE);
        if( ret != XCP_E_OK )
        {
            Xcp_RecordError(CRC_OUT_OF_RANGE);
        }
        else
        {
            Xcp_Data.Mta += CRO_PROGRAM_SIZE;
        }
    }
}

#if( STD_ON == XCP_BLOCK_DOWNLOAD )
/*
********************************************************************************
* Function Name: Xcp_CC_Program_Next
*
* Explanation: Execute command Xcp_CC_Program_Next.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Program_Next
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 ret = XCP_E_NOT_OK;

    if( CRO_PROGRAM_NEXT_SIZE == Xcp_Data.NextDownloadSize )
    {
        if ( CRO_PROGRAM_NEXT_SIZE > CRO_PROGRAM_NEXT_MAX_SIZE )
        {
            ret = XcpAppl_FlashProgram((uint32) Xcp_Data.Mta,(uint8*)CRO_PROGRAM_NEXT_DATA,CRO_PROGRAM_NEXT_MAX_SIZE);
            if( ret != XCP_E_OK )
            {
                Xcp_RecordError(CRC_OUT_OF_RANGE);
            }
            else
            {
                Xcp_Data.NextDownloadSize = (CRO_PROGRAM_NEXT_SIZE - CRO_PROGRAM_NEXT_MAX_SIZE);
                Xcp_Data.Mta += CRO_PROGRAM_NEXT_MAX_SIZE;
            }
            CanXcpGetStatus = TRUE;
        }
        else
        {
            ret = XcpAppl_FlashProgram((uint32) Xcp_Data.Mta,(uint8*)CRO_PROGRAM_NEXT_DATA, CRO_PROGRAM_NEXT_SIZE);
            if( ret != XCP_E_OK )
            {
                Xcp_RecordError(CRC_OUT_OF_RANGE);
            }
            else
            {
                Xcp_Data.NextDownloadSize = XCP_ZERO;
                Xcp_Pending = XCP_ZERO;
                Xcp_Data.Mta += CRO_PROGRAM_NEXT_SIZE;
            }
        }
    }
    else
    {
        Xcp_RecordError(CRC_SEQUENCE);
        CRM_PROGRAM_NEXT_SIZE_EXPECTED_DATA = Xcp_Data.NextDownloadSize;
    }
}
#endif
/*
********************************************************************************
* Function Name: Xcp_CC_Program_Max
*
* Explanation: Execute command Xcp_CC_Program_Max.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Program_Max
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    uint8 ret = XCP_E_NOT_OK;

    ret = XcpAppl_FlashProgram((uint32)Xcp_Data.Mta, (uint8*)CRO_PROGRAM_MAX_DATA, CRO_PROGRAM_MAX_MAX_SIZE);
    if( ret != XCP_E_OK )
    {
        Xcp_RecordError(CRC_OUT_OF_RANGE);
    }
    else
    {
        Xcp_Data.Mta += CRO_PROGRAM_MAX_MAX_SIZE;
    }
}

/*
********************************************************************************
* Function Name: Xcp_CC_Program_Reset
*
* Explanation: Execute command CC_StartStopSynch.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Program_Reset
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    Xcp_Disconnect();
    /* May not return */
    XcpAppl_Reset();
}
#endif

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
/*
********************************************************************************
* Function Name: Xcp_CC_Set_Request
*
* Explanation: Execute command CC_StartStopSynch.
*
* param: pCmd: Accept instructions and parameters.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CC_Set_Request
(
    P2CONST(Xcp_Cto_st, AUTOMATIC, XCP_APPL_CONST)pCmd
)
{
    Xcp_Data.storeFlag = CRO_SET_REQUEST_MODE;
    Xcp_Data.sessionId = CRO_SET_REQUEST_CONFIG_ID;
    if( (CRO_SET_REQUEST_MODE & SS_STORE_DAQ_REQ) == SS_STORE_DAQ_REQ )
    {
        Xcp_Data.storeFlag = (CRO_SET_REQUEST_MODE & SS_STORE_DAQ_REQ);
        Xcp_Data.SessionStatus |= (uint8)SS_RESUME;
    }
    else if( (CRO_SET_REQUEST_MODE&SS_STORE_CAL_REQ) == SS_STORE_CAL_REQ )
    {
        Xcp_Data.storeFlag = (CRO_SET_REQUEST_MODE & SS_STORE_CAL_REQ);
    }
    else
    {
        ;
    }
}
#endif

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD || RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
/*
********************************************************************************
* Function Name: Xcp_MemCpy32
*
* Explanation: 32-bit data copy
*
* param: source: Source address.
*        target: Destination address.
*        Size: Data copy length (unit byte).
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_MemCpy32(uint32 source, uint32 target, uint32 Size)
{
    uint32 index;
    uint32 *src;
    uint32 *des;

    src = (uint32 *)source;
    des = (uint32 *)target;

    for( index = XCP_ZERO; index < (Size/XCP_FOUR); index++)
    {
        *des = *src;
        des++;
        src++;
    }
}
#endif

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD && STD_ON == XCP_ENABLE_CHECKSUM )
/*
********************************************************************************
* Function Name: Xcp_AddressRelocationChecksum
*
* Explanation: Address relocation is used to check sum.
*
* param: checksumSize: Number of checksums.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_AddressRelocationChecksum(uint32 checksumSize)
{
    if( Xcp_Data.PageInd == XCP_ONE )  /* Working Page */
    {
#if ( XCP_ADD12 == XCP_CHECKSUM_TYPE || XCP_ADD11 == XCP_CHECKSUM_TYPE )
        while( checksumSize )
        {
            /* Checksum calculation method: XCP_ADD_xx */
            Xcp_Data.CheckSum += (tXcpChecksumSumType)(XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta + XcpCalOffset));
            Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
            checksumSize -= (uint8)sizeof(tXcpChecksumAddType);
        }
#else
        if( TRUE == Xcp_Data.Crc32Flag )
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32((Xcp_Data.Mta + XcpCalOffset), checksumSize, (uint32)XCP_ZERO, TRUE);
            Xcp_Data.Crc32Flag = FALSE;
            Xcp_Data.Mta += checksumSize;
        }
        else
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32((Xcp_Data.Mta + XcpCalOffset), checksumSize, (uint32)Xcp_Data.CheckSum, FALSE);
            Xcp_Data.Mta += checksumSize;
        }
#endif
    }
    else  /* Reference Page */
    {
#if( XCP_ADD12 == XCP_CHECKSUM_TYPE || XCP_ADD11 == XCP_CHECKSUM_TYPE )
        while( checksumSize )
        {
            /* Checksum calculation method: XCP_ADD_xx */
            Xcp_Data.CheckSum += (tXcpChecksumSumType)(XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta));
            Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
            checksumSize -= (uint8)sizeof(tXcpChecksumAddType);
        }
#else
        if( TRUE == Xcp_Data.Crc32Flag )
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, checksumSize, (uint32)XCP_ZERO, TRUE);
            Xcp_Data.Crc32Flag = FALSE;
            Xcp_Data.Mta += checksumSize;
        }
        else
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, checksumSize, (uint32)Xcp_Data.CheckSum, FALSE);
            Xcp_Data.Mta += checksumSize;
        }
#endif
    }
}
#endif

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD && STD_ON == XCP_ENABLE_CHECKSUM )
/*
********************************************************************************
* Function Name: Xcp_SinglePtrChecksum
*
* Explanation: Implementation of checksum with single pointer.
*
* param: checksumSize: Number of checksums.
*
* retval: None
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_SinglePtrChecksum(uint32 checksumSize)
{
    uint32 alCalibGroupNum;
    uint32 length = XCP_ZERO;
    uint8 *checksumAddr = NULL_PTR;

    if( XCP_ONE == Xcp_Data.PageInd )  /* Working Page */
    {
        while( checksumSize )
        {
            /* Checksum calculation method: XCP_ADD_12 */
            for( alCalibGroupNum = XCP_ZERO; alCalibGroupNum < RTE_CALIBGROUPNUM; alCalibGroupNum++ )
            {
                /* Find CalibGroup Num */
                if( (Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress <= (uint32)Xcp_Data.Mta)&&
                    ((Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress +
                      Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength) > (uint32)Xcp_Data.Mta) )
                {
                    break;
                }
                else
                {
                    /* do nothing */
                }
            }
            if( (alCalibGroupNum < RTE_CALIBGROUPNUM) &&
                (Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress !=
                *(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf)) )
            {
                length = Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength;
                checksumAddr = (uint8*)(*(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf));
#if( (XCP_ADD12 == XCP_CHECKSUM_TYPE) || (XCP_ADD11 == XCP_CHECKSUM_TYPE) )
                while(length)
                {
                    Xcp_Data.CheckSum += (tXcpChecksumSumType)(XCP_READ_CHECKSUMVALUE_FROM_ADDR(checksumAddr));
                    checksumAddr++;
                    length--;
                }
#else
                if( TRUE == Xcp_Data.Crc32Flag )
                {
                    Xcp_Data.CheckSum = Crc_CalculateCRC32(checksumAddr, length, (uint32)XCP_ZERO, TRUE);
                    Xcp_Data.Crc32Flag = FALSE;

                }
                else
                {
                    Xcp_Data.CheckSum = Crc_CalculateCRC32(checksumAddr, length, (uint32)Xcp_Data.CheckSum, FALSE);
                }
#endif

                Xcp_Data.Mta += Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength;
                checksumSize -= Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength;
            }
            else
            {
#if( XCP_ADD12 == XCP_CHECKSUM_TYPE || XCP_ADD11 == XCP_CHECKSUM_TYPE )
                Xcp_Data.CheckSum += (tXcpChecksumSumType)(XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta));
                Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
                checksumSize -= (uint8)sizeof(tXcpChecksumAddType);
#else
                if( TRUE == Xcp_Data.Crc32Flag )
                {
                    Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, (uint32)XCP_ONE, (uint32)XCP_ZERO, TRUE);
                    Xcp_Data.Crc32Flag = FALSE;
                }
                else
                {
                    Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, (uint32)XCP_ONE, (uint32)Xcp_Data.CheckSum, FALSE);
                }
                Xcp_Data.Mta += (uint8)XCP_ONE;
                checksumSize -= (uint8)XCP_ONE;
#endif
            }
        }
    }
    else  /* Reference Page */
    {

#if( XCP_ADD12 == XCP_CHECKSUM_TYPE || XCP_ADD11 == XCP_CHECKSUM_TYPE )
        while( checksumSize )
        {
            /* Checksum calculation method: XCP_ADD_xx */
            Xcp_Data.CheckSum += (tXcpChecksumSumType)(XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta));
            Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
            checksumSize -= (uint8)sizeof(tXcpChecksumAddType);
        }
#else
        if( TRUE == Xcp_Data.Crc32Flag )
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, checksumSize, (uint32)XCP_ZERO, TRUE);
            Xcp_Data.Crc32Flag = FALSE;
            Xcp_Data.Mta += checksumSize;
        }
        else
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, checksumSize, (uint32)Xcp_Data.CheckSum, FALSE);
            Xcp_Data.Mta += checksumSize;
        }
#endif

    }
}
#endif

#if( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
/*
********************************************************************************
* Function Name: XCP_ModifyEntry
*
* Explanation: Address conversion with single pointer.
*
* param: CalibAddress: Calibration address.
*        CalibLength: Calibration data length.
*        CalibGroupData: Calibration data value.
*
* retval: E_OK: Address conversion complete.
*         E_NOT_OK: The calibration RAM area is full or
*                   the calibration address is out of range.
********************************************************************************
*/
FUNC(Std_ReturnType, XCP_CODE) Xcp_ModifyEntry
(
    uint32 CalibAddress,
    uint16 CalibLength,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)CalibGroupData
)
{
    uint8 returnValue = E_NOT_OK;
    uint32 alCalibGroupNum;
    uint32 alIndex;

    for( alCalibGroupNum = XCP_ZERO; alCalibGroupNum < RTE_CALIBGROUPNUM; alCalibGroupNum++ )
    {
        /* Find CalibGroup Num */
        if( (Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress <= CalibAddress)&&
            ((Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress +
              Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength) > CalibAddress) )
        {

            if( (Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress +
                 Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength) >= (CalibAddress+CalibLength) )
            {
                returnValue = E_OK;
                break;
            }
            else
            {
                /* A2L Error */
                returnValue = E_NOT_OK;
            }
        }
    }
    if( E_OK == returnValue)
    {
        if( RTE_CALIBGROUPNUM <= alCalibGroupNum )
        {
            /* A2L Error */
            returnValue = E_NOT_OK;
        }
        /* check the group Calibration completed or not. */
        else
        {
             if( (RTE_CALIBGROUP_PARABUF_ADDREND >= (*(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf)))&&
            (RTE_CALIBGROUP_PARABUF_ADDRSTART <= (*(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf))) )
            {
                /* Not First calibration */
                for( alIndex = XCP_ZERO; alIndex<CalibLength; alIndex++ )
                {
                    ((uint8*)((*(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf))+
                    (CalibAddress - Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress)))[alIndex] =
                     CalibGroupData[alIndex];
                }
            }
            else /* First calibration */
            {
                /* Supports 2-byte alignment */
                if( (XCP_ZERO == Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength % XCP_TWO) &&
                   (XCP_ZERO != ((uint32)Xcp_CalibGroupPtCnt & XCP_ONE)) )
                {
                    Xcp_CalibGroupPtCnt = Xcp_CalibGroupPtCnt + XCP_ONE;
                }
                /* the CalibGroup_RAMBuf overflow or not  */
                if( RTE_CALIBGROUP_PARABUF_ADDREND <
                    ((uint32)Xcp_CalibGroupPtCnt + Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength) )
                {
                    /* RAM overflow Error */
                    returnValue = E_NOT_OK;
                }
                else
                {
                /* Fill a RAM buffer with the Init calibration parameter values */
                    for( alIndex = XCP_ZERO; alIndex < Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength; alIndex++)
                    {
                        Xcp_CalibGroupPtCnt[alIndex] =
                        ((uint8*)Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress)[alIndex];
                    }

                    /* Fill a RAM buffer with the modify calibration parameter values */
                    for( alIndex = XCP_ZERO; alIndex < CalibLength; alIndex++ )
                    {
                        ((uint8*)(((uint32)Xcp_CalibGroupPtCnt) +
                        (CalibAddress - Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress)))[alIndex] =
                         CalibGroupData[alIndex];
                    }
                    /* Modify Entry */
                    *(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf) = (uint32)Xcp_CalibGroupPtCnt;
                    /* change the Xcp_CalibGroupPtCnt to the next */
                    Xcp_CalibGroupPtCnt = (uint8*)((uint32)Xcp_CalibGroupPtCnt +
                                          Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength);
                }
            }
        }
    }

    return returnValue;
}

/*
********************************************************************************
* Function Name: XCP_CalibParaRead
*
* Explanation: Reading calibration data with single pointer.
*
* param: CalibAddress: Calibration address.
*        CalibLength: Calibration data length.
*        CalibGroupData: Calibration data value.
*
* retval: E_OK: Check value read completed.
*         E_NOT_OK: The calibration address is out of range.
********************************************************************************
*/
FUNC(Std_ReturnType, XCP_CODE) Xcp_CalibParaRead(
    uint32 CalibAddress,
    uint16 CalibLength,
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)CalibGroupData
)
{
    uint8 returnValue = E_OK;
    uint32 alCalibGroupNum;
    uint32 alIndex;

    for( alCalibGroupNum = XCP_ZERO; alCalibGroupNum < RTE_CALIBGROUPNUM; alCalibGroupNum++)
    {
        /* Find CalibGroup Num */
        if( (Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress <= CalibAddress) &&
            ((Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress +
            Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength) > CalibAddress) )
        {
            if( (Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress +
                 Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupLength) >= (CalibAddress+CalibLength) )
            {
                break;
            }
            else
            {
                /* A2L Error */
                returnValue = E_NOT_OK;
            }
        }
    }
    if( E_OK == returnValue )
    {
        if( RTE_CALIBGROUPNUM <= alCalibGroupNum )
        {
            /* Not Calib */
            returnValue = E_NOT_OK;
        }
        else
        {
            /* read calibration para value */
            for( alIndex = XCP_ZERO; alIndex < CalibLength ; alIndex++)
            {
                CalibGroupData[alIndex] = ((uint8*)((*(Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupPtBuf))+
                                          (CalibAddress-Rte_CalibGroupCfg[alCalibGroupNum].Rte_CalibGroupHAddress)))[alIndex];
            }
        }
    }

    return returnValue;
}
#endif

/*
********************************************************************************
* Function Name: ApplXcpCopyCalPage
*
* Explanation: Copy calibration page.
*
* param: srcSeg: source segment.
*        srcPage: source page.
*        dstSeg: destination segment.
*        dstPage: destination page.
*
* retval: uint8: calibration page.
********************************************************************************
*/
#ifdef XCP_ENABLE_PAGE_COPY
FUNC(uint8, XCP_CODE) ApplXcpCopyCalPage
(
    uint8 srcSeg, uint8 srcPage, uint8 dstSeg, uint8 dstPage
)
{
    uint16 awSize;
    uint8 returnValue = XCP_ZERO;

    if( (XCPTS_NO_TIME_STAMP !=srcSeg) || (XCP_ZERO != dstSeg) )
    {
        returnValue = CRC_SEGMENT_NOT_VALID; /* Segments are not supported */
    }
    else if( dstPage == srcPage )
    {
        returnValue = CRC_PAGE_NOT_VALID; /* Can not copy on itself */
    }
    else if( XCP_ZERO == dstPage )
    {
        returnValue = CRC_ACCESS_DENIED; /* Can not copy to FLASH page */
    }
    else
    {
        awSize = CALRAM_SIZE;
        if( CALPAGE_RAM == Xcp_WorkingPage )
        {
            ApplXcpSetCalPage(XCP_ZERO, CALPAGE_FLASH, CAL_ECU);
            Xcp_CopyMemCpy((void*)CALRAM_ADDR, (void*)CALFLASH_ADDR, awSize);
            ApplXcpSetCalPage(XCP_ZERO, CALPAGE_RAM, CAL_ECU);
        }
        else
        {
            Xcp_CopyMemCpy((void*)CALRAM_ADDR, (void*)CALFLASH_ADDR, awSize);
        }
    }
    return returnValue;
}

/*
********************************************************************************
* Function Name: Xcp_CopyMemCpy
*
* Explanation: Copy n bytes from src to dest.
*
* param: dest : pointer to destination address.
*        src : pointer to source address.
*        n : number of data bytes to copy.
*
* retval: uint8: calibration page.
********************************************************************************
*/
static FUNC(void, XCP_CODE) Xcp_CopyMemCpy
(
    P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA)dest,
    P2CONST(uint8, AUTOMATIC, XCP_APPL_CONST)src,
    uint16 num
)
{
    for( ; num > XCP_ZERO; num-- )
    {
        XCP_WRITE_BYTE_2_ADDR(dest, *src);
        dest++;
        src++;
    }
}
#endif

/*
********************************************************************************
* Function Name: XCP_Init
*
* Explanation: Initialization of the XCP Protocol Layer.
*              Application specific initialization.
*              ( e.g. Vector XCP on CAN Transport Layer )
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_Init(void)
{
#if( MULTIPDUIDSUPPORT == STD_ON || (RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD) || (RTECALIBRATIONSUPPORT == OVERLAY_METHOD) )
    uint8 index;
#endif
    /*xcp init calibration page*/
    Xcp_InitCalPage();
    /* Initialize all XCP variables to zero */
    Xcp_MemClr((uint8*) & Xcp_Data, (uint16)sizeof(Xcp_Data));
    /* Initialize the session status */
    Xcp_Data.SessionStatus = (uint8)XCP_ZERO;
    Xcp_Data.storeFlag = XCP_ZERO;
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
    Xcp_Data.NextDownloadSize = XCP_ZERO;
#endif
#if( STD_ON == XCP_BLOCK_UPLOAD )
    Xcp_Data.NextDataBlockSize = XCP_ZERO;
#endif

#if( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
    Xcp_Addr.addr_wp = CALRAM_ADDR;
    Xcp_Addr.addr_rp = CALFLASH_ADDR;
    Xcp_Addr.len = CALRAM_SIZE;
#endif
#if( RTECALIBRATIONSUPPORT == OVERLAY_METHOD )
    for( index = XCP_ZERO; index < XCP_OVERLAY_CNT; index++ )
    {
        Xcp_Addr_Temp[index].len = Xcp_Overlay_Addr[index].len;
        Xcp_Addr_Temp[index].addr_rp = Xcp_Overlay_Addr[index].addr_rp;
        Xcp_Addr_Temp[index].addr_wp = Xcp_Overlay_Addr[index].addr_wp;
    }
#endif
#ifdef XCP_ENABLE_STIM_QUEUE
    Xcp_AllocStimQueueMemory();
    Xcp_Data.QueueLenStim = XCP_ZERO;
    Xcp_Data.QueueRpStim = XCP_ZERO;
#endif

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    /* Initialize the transmit queue */
#if( MULTIPDUIDSUPPORT == STD_ON )
    for(index = XCP_ZERO; index < XCP_TXPDU_LIST; index ++)
    {
        Xcp_Data.SendStatus[index] = (uint8)XCP_ZERO;
    }
#else
    Xcp_Data.SendStatus = (uint8)XCP_ZERO;
#endif

#endif

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    Xcp_CalMemInit();

    for(index = XCP_ZERO; index < XCP_REGISTER_NUM; index++ )
    {
        Xcp_RegisterFunList[index].FctPtrOfRegister();
    }
#endif

}

/*
********************************************************************************
* Function Name: Xcp_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: ApiId: Unique Api ID of ComM manager service.
*         ErrorId: Det Error ID of ComM manager.
*
* retval: None
********************************************************************************
*/
extern FUNC(void, XCP_CODE) Xcp_Det_ErrorReport(uint8  ApiId, uint8  ErrorId)
{

#if( XCP_DEV_ERROR_DETECT == STD_ON )
    if( XCP_E_NO_ERROR != ErrorId )    /* Error detected. */
    {
         /* Report Error to Det. */
        (void)Det_ReportError(XCP_MODULE_ID, XCP_INSTANCE_ID, ApiId, ErrorId);
    }
#else
    XCP_DUMMY_STATEMENT(ApiId);
    XCP_DUMMY_STATEMENT(ErrorId);
#endif

}

/*
********************************************************************************
* Function Name: XCP_InterruptDisable
*
* Explanation: xcp interrupt disable.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_InterruptDisable(void)
{
    SchM_Enter_Xcp_XCP_EXCLUSIVE_AREA_0();
}

/*
********************************************************************************
* Function Name: XCP_InterruptEnable
*
* Explanation: xcp interrupt enable.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_InterruptEnable(void)
{
    SchM_Exit_Xcp_XCP_EXCLUSIVE_AREA_0();
}

/*
********************************************************************************
* Function Name: XCP_SendCallBack
*
* Explanation: Notifies the XCP Protocol Layer about the successful.
*              transmission of a XCP packet.
*
* param: None
*
* retval: E_OK: XCP_SendCallBack success.
*         Any other: XCP_SendCallBack not success.
********************************************************************************
*/
#if ( MULTIPDUIDSUPPORT == STD_ON )
FUNC(uint8, XCP_CODE) Xcp_SendCallBack(uint8 eventid)
{
    uint8 retValue = E_NOT_OK;
    uint8 index;
#if( STD_ON == XCP_BLOCK_UPLOAD )
    uint8 nextCmd[XCP_EIGHT] = {XCP_ZERO}; /* Used to call upload again */
#endif

#if defined (XCP_ENABLE_DAQ)
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    /* Clear all pending flags */
    /* A pending flag indicates that XCP_Send() is in progress */
    for( index = XCP_ZERO; index < XCP_TXPDU_LIST; index++ )
    {
        Xcp_Data.SendStatus[index] &= (uint8)(~XCP_SEND_PENDING) & XCP_FF;
    }

    /* Now check if there is another transmit request */
    if( (Xcp_Data.SendStatus[eventid] & (uint8)XCP_CRM_REQUEST) != XCP_ZERO )
    {
        /* Send a RES or ERR (CRM) message */
        Xcp_Data.SendStatus[eventid] &= (uint8)(~XCP_CRM_REQUEST) & XCP_FF;
        Xcp_SendCrm();
        retValue = E_OK;
    }

#if defined (XCP_ENABLE_SEND_EVENT) && ( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
    else if( (Xcp_Data.SendStatus & (uint8)XCP_EVT_REQUEST) != XCP_ZERO )
    {
        /* Send a EV or SERV message */
        Xcp_Data.SendStatus &= (uint8)(~XCP_EVT_REQUEST) & XCP_FF;
        Xcp_SendEv();
        retValue = E_OK;
    }
#endif

    else
    {
        if( ((Xcp_Data.SessionStatus & (uint8)SS_DAQ) != XCP_ZERO) && (eventid < XCP_EVENT_CHANNEL_NUM) )
        {
            /* Send a DAQ message from the queue or from the buffer */
            if( E_OK == Xcp_SendDtoFromQueue(eventid) )
            {
                retValue = E_OK;
            }
        }
    }
#endif /* defined (XCP_ENABLE_DAQ) && defined (XCP_ENABLE_SEND_QUEUE) */
#endif

#if( STD_ON == XCP_BLOCK_UPLOAD )
    /* #80 Otherwise, if pending upload data exist: */
    if( (Xcp_Data.SessionStatus & SS_BLOCK_UPLOAD) != XCP_ZERO )
    {
        nextCmd[XCP_ZERO] = (uint8)CC_UPLOAD;
        nextCmd[XCP_ONE] = (uint8)Xcp_Data.NextDataBlockSize;
        /* #90 Reset PENDING flag, execute upload command and send the frame. */
        Xcp_Data.SessionStatus &= (uint16)((~SS_BLOCK_UPLOAD) & 0xFFFFU);
        Xcp_Command( ( const uint32* )nextCmd );
    }
#endif

    return retValue;
}

#else
FUNC(uint8, XCP_CODE) Xcp_SendCallBack(void)
{
#if( STD_ON == XCP_BLOCK_UPLOAD )
    uint8 nextCmd[XCP_EIGHT] = {XCP_ZERO}; /* Used to call upload again */
#endif
    uint8 retValue = E_NOT_OK;

#if defined (XCP_ENABLE_DAQ)
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    /* Clear all pending flags */
    /* A pending flag indicates that XCP_Send() is in progress */
    Xcp_Data.SendStatus &= (uint8)(~XCP_SEND_PENDING) & XCP_FF;
    /* Now check if there is another transmit request */
    if( (Xcp_Data.SendStatus & (uint8)XCP_CRM_REQUEST) != XCP_ZERO )
    {
        /* Send a RES or ERR (CRM) message */
        Xcp_Data.SendStatus &= (uint8)(~XCP_CRM_REQUEST) & XCP_FF;
        Xcp_SendCrm();
        retValue = E_OK;
    }
#if defined (XCP_ENABLE_SEND_EVENT) && ( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
    else if( (Xcp_Data.SendStatus & (uint8)XCP_EVT_REQUEST) != XCP_ZERO )
    {
        /* Send a EV or SERV message */
        Xcp_Data.SendStatus &= (uint8)(~XCP_EVT_REQUEST) & XCP_FF;
        Xcp_SendEv();
        retValue = E_OK;
    }
#endif

    else
    {
        if( (Xcp_Data.SessionStatus & (uint8)SS_DAQ) != XCP_ZERO )
        {
            /* Send a DAQ message from the queue or from the buffer */
            if( E_OK == Xcp_SendDtoFromQueue() )
            {
                retValue = E_OK;
            }
        }
    }
#endif /* defined (XCP_ENABLE_DAQ) && defined (XCP_ENABLE_SEND_QUEUE) */
#endif

#if( STD_ON == XCP_BLOCK_UPLOAD )
    /* #80 Otherwise, if pending upload data exist: */
    if( (Xcp_Data.SessionStatus & SS_BLOCK_UPLOAD) != XCP_ZERO )
    {
        CanXcpGetStatus = FALSE;
        nextCmd[XCP_ZERO] = (uint8)CC_UPLOAD;
        nextCmd[XCP_ONE] = (uint8)Xcp_Data.NextDataBlockSize;
        /* #90 Reset PENDING flag, execute upload command and send the frame. */
        Xcp_Data.SessionStatus &= (uint16)((~SS_BLOCK_UPLOAD) & 0xFFFFU);
        Xcp_Command( ( const uint32* )nextCmd );
    }
    else
    {
        CanXcpGetStatus = TRUE;
    }
#endif

    return retValue;
}
#endif
/*
********************************************************************************
* Function Name: XCP_Background
*
* Explanation: perform background calculation of checksum.
*
* param: None
*
* retval: E_OK: XCP_Background success.
*         Any other: XCP_Background not success.
********************************************************************************
*/
FUNC(uint8, XCP_CODE) Xcp_Background(void)
{
    uint8 retValue = E_OK;
#if( STD_ON == XCP_ENABLE_CHECKSUM )
    uint16 checksumSize;     /*checksumsize: Xcp_Data.CheckSumSize*/
#endif

#if( STD_ON == XCP_ENABLE_CHECKSUM )
    /* Checksum calculation in progress */
    if( (Xcp_Data.CheckSumSize) != (tXcpChecksumSumType)XCP_ZERO )
    {

        if( Xcp_Data.CheckSumSize <= (XCP_CHECKSUMBLOCKSIZE - XCP_ONE) )
        {
            checksumSize = Xcp_Data.CheckSumSize;
            Xcp_Data.CheckSumSize = XCP_ZERO;
        }
        else
        {
            checksumSize = (uint16)XCP_CHECKSUMBLOCKSIZE;
            Xcp_Data.CheckSumSize -= XCP_CHECKSUMBLOCKSIZE;
        }
        /* Single pointer checksum */
#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
        Xcp_StructurePtChecksum(checksumSize);
#elif( RTECALIBRATIONSUPPORT == RTE_SINGLE_PT_METHOD )
        Xcp_SinglePtrChecksum(checksumSize);
#elif( RTECALIBRATIONSUPPORT == RTE_INITRAM_METHOD )
        Xcp_AddressRelocationChecksum(checksumSize);
#else
#if( (XCP_ADD12 == XCP_CHECKSUM_TYPE) || (XCP_ADD11 == XCP_CHECKSUM_TYPE) )
        while( checksumSize )
        {
            /* Checksum calculation method: XCP_ADD_xx */
            Xcp_Data.CheckSum += (tXcpChecksumSumType)(XCP_READ_CHECKSUMVALUE_FROM_ADDR(Xcp_Data.Mta));
            Xcp_Data.Mta += (uint8)sizeof(tXcpChecksumAddType);
            checksumSize -= (uint8)sizeof(tXcpChecksumAddType);
        }
#else
        if( TRUE == Xcp_Data.Crc32Flag )
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, (uint32)checksumSize, (uint32)XCP_ZERO, TRUE);
            Xcp_Data.Crc32Flag = FALSE;
            Xcp_Data.Mta += checksumSize;
        }
        else
        {
            Xcp_Data.CheckSum = Crc_CalculateCRC32(Xcp_Data.Mta, (uint32)checksumSize, (uint32)Xcp_Data.CheckSum, FALSE);
            Xcp_Data.Mta += checksumSize;
        }
#endif
#endif
        /* Checksum calculation finished ? */
        if( XCP_ZERO != (Xcp_Data.CheckSumSize) )
        {
            retValue = E_NOT_OK;     /* Still pending */
        }
        else
        {
#if( XCP_ADD12 == XCP_CHECKSUM_TYPE )
            CRM_BUILD_CHECKSUM_TYPE = XCP_CHECKSUM_TYPE_ADD12;
#elif( XCP_ADD11 == XCP_CHECKSUM_TYPE )
            CRM_BUILD_CHECKSUM_TYPE = XCP_CHECKSUM_TYPE_ADD11;
#elif( XCP_CRC32== XCP_CHECKSUM_TYPE )
            CRM_BUILD_CHECKSUM_TYPE = XCP_CHECKSUM_TYPE_CRC32;
#endif
            CRM_BUILD_CHECKSUM_RESULT = Xcp_Data.CheckSum;
            Xcp_Data.CrmLen = CRM_BUILD_CHECKSUM_LEN;
            Xcp_Pending = XCP_ZERO;
            Xcp_SendCrm();
            retValue = E_OK;
        }
    }  /* Xcp_Data.CheckSumSize */
#endif /* STD_ON == XCP_ENABLE_CHECKSUM */

#if( RTECALIBRATIONSUPPORT == XCP_STRUCTUREPT_METHOD )
    if( XCP_ONE == Xcp_DownLoadCopyState.CopyReqState )
    {
        if( Xcp_DownLoadCopyState.CopyLen > XCP_512 )
        {
            Xcp_MemCpy8((uint8*)Xcp_DownLoadCopyState.CopyAddrDest,
                        (const uint8*)Xcp_DownLoadCopyState.CopyAddrSrc,
                        XCP_512);
            Xcp_DownLoadCopyState.CopyLen -= XCP_512;
        }
        else
        {
            Xcp_MemCpy8((uint8*)Xcp_DownLoadCopyState.CopyAddrDest,
                        (const uint8*)Xcp_DownLoadCopyState.CopyAddrSrc,
                        Xcp_DownLoadCopyState.CopyLen);
            Xcp_DownLoadCopyState.CopyReqState = XCP_ZERO;
            retValue = Xcp_CalDownLoadHandle(Xcp_DownLoadCopyState.DownSize, Xcp_DownLoadCopyState.DownData);
            if( E_OK == retValue )
            {
                Xcp_Data.Mta += Xcp_DownLoadCopyState.DownSize;
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
                if( Xcp_Data.NextDownloadSize == XCP_ZERO )
                {
#endif
                    CRM_CMD = XCP_FF;
                    Xcp_Data.CrmLen = XCP_ONE;
                    Xcp_Pending = XCP_ZERO;
                    Xcp_SendCrm();
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
                }
#endif
            }
        }
    }
#endif
    return retValue;
}

/*
********************************************************************************
* Function Name: XCP_Disconnect
*
* Explanation: If the XCP slave is connected to a XCP master a call of this
*              function discontinues the connection
*              (transition to disconnected state).If the XCP
*              slave is not connected this function performs no action.
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_Disconnect(void)
{
    Xcp_Data.SessionStatus &= (uint8)(~SS_CONNECTED) & XCP_FF;

#ifdef XCP_ENABLE_DAQ
    Xcp_StopAllDaq();
#endif

#if( XCP_ENABLE_SEED_KEY == STD_ON )
     /* Lock all resources */
    Xcp_Data.ProtectionStatus = (uint8)RM_CAL_PAG|RM_DAQ|RM_PGM|RM_STIM;
#endif

}

/*
********************************************************************************
* Function Name: Xcp_SendCrm
*
* Explanation: Transmission of a command response packet (RES),
*               or error packet (ERR) if no other packet is pending.
* param: None
*
* retval: None
********************************************************************************
*/
#if ( MULTIPDUIDSUPPORT == STD_ON )
FUNC(void, XCP_CODE) Xcp_SendCrm(void)
{

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    /* Judge Send Occupation */
    if( (Xcp_Data.SendStatus[XCP_EVENT_CHANNEL_NUM] & (uint8)XCP_SEND_PENDING) != XCP_ZERO )
    {
        if( (Xcp_Data.SendStatus[XCP_EVENT_CHANNEL_NUM] & (uint8)XCP_CRM_REQUEST) != XCP_ZERO )
        {
            Xcp_Data.SessionStatus |= (uint8)SS_ERROR;
        }
        /* Mark command reply request */
        Xcp_Data.SendStatus[XCP_EVENT_CHANNEL_NUM] |= (uint8)XCP_CRM_REQUEST;
    }
    else
    {
        Xcp_Data.SendStatus[XCP_EVENT_CHANNEL_NUM] |= (uint8)XCP_CRM_PENDING;
        Xcp_Send(XCP_EVENT_CHANNEL_NUM, Xcp_Data.CrmLen, & Xcp_Data.Crm.bytes[XCP_ZERO]);
    }
#else
    Xcp_Send(XCP_EVENT_CHANNEL_NUM, Xcp_Data.CrmLen, & Xcp_Data.Crm.bytes[XCP_ZERO]);
#endif

}

#else
FUNC(void, XCP_CODE) Xcp_SendCrm(void)
{

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
    /* Judge Send Occupation */
    if( (Xcp_Data.SendStatus & (uint8)XCP_SEND_PENDING) != XCP_ZERO )
    {
        if( (Xcp_Data.SendStatus & (uint8)XCP_CRM_REQUEST) != XCP_ZERO )
        {
            Xcp_Data.SessionStatus |= (uint8)SS_ERROR;
        }
        /* Mark command reply request */
        Xcp_Data.SendStatus |= (uint8)XCP_CRM_REQUEST;
    }
    else
    {
        Xcp_Data.SendStatus |= (uint8)XCP_CRM_PENDING;
        Xcp_Send(Xcp_Data.CrmLen, & Xcp_Data.Crm.bytes[XCP_ZERO]);
    }
#else
    Xcp_Send(Xcp_Data.CrmLen, & Xcp_Data.Crm.bytes[XCP_ZERO]);
#endif

}
#endif

#ifdef XCP_ENABLE_DAQ
/*
********************************************************************************
* Function Name: XCP_SendDto
*
* Explanation: Send a DTO.
*
* param: astpDto : pointer to XCP packet type definition
*
* retval: None
********************************************************************************
*/
#if ( MULTIPDUIDSUPPORT == STD_ON )
FUNC(void, XCP_CODE) Xcp_SendDto(uint8 eventid, P2VAR(Xcp_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto)
{
    Xcp_Send(eventid, astpDto->length, &astpDto->bytes[XCP_ZERO]);
}
#else
FUNC(void, XCP_CODE) Xcp_SendDto(P2VAR(Xcp_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto)
{
    Xcp_Send(astpDto->length, &astpDto->bytes[XCP_ZERO]);
}

/*
********************************************************************************
* Function Name: Xcp_SendEthDaq
*
* Explanation: Send a EthDAQ.
*
* param: astpDto : pointer to XCP packet type definition.
*
* retval: None
********************************************************************************
*/
#if( XCP_ONETHERNET_ENABLE == STD_ON )
void Xcp_SendEthDaq(Xcp_Eth_Dto_st *astpDto)
{
    EthXcp_Send(astpDto->length, &astpDto->bytes[XCP_ZERO]);
}
#endif

#endif /* MULTIPDUIDSUPPORT == STD_ON */

#endif /* XCP_ENABLE_DAQ */


/*
********************************************************************************
* Function Name: Xcp_SendDtoMode
*
* Explanation: Select the sending method of dto.
*
* param: astpDto : pointer to XCP packet type definition.
*
* retval: None
********************************************************************************
*/
#if ( XCP_ENABLE_SEND_QUEUE == STD_OFF )
FUNC(void, XCP_CODE) Xcp_SendDtoMode(P2VAR(Xcp_Dto_st, AUTOMATIC, XCP_APPL_DATA)astpDto)
{

#if ( STD_ON == XCP_ONETHERNET_ENABLE )
    Xcp_Eth_Dto_st Eth_Data = {{XCP_ZERO}, XCP_ZERO};
    uint8 * dtoi = &Eth_Data.bytes[XCP_ZERO];
#endif

#if (STD_ON == XCP_ONCAN_ENABLE)
    Xcp_SendDto(astpDto);
#endif

#if ( STD_ON == XCP_ONETHERNET_ENABLE )
    (*(uint8*)(dtoi + XCP_ZERO)) = (uint8)((astpDto->length) & XCP_00FF);
    (*(uint8*)(dtoi + XCP_ONE)) = (uint8)((astpDto->length >> XCP_EIGHT) & XCP_00FF);
    (*(uint8*)(dtoi + XCP_TWO)) = (uint8)((Xcp_EthCtrTx) & XCP_00FF);
    (*(uint8*)(dtoi + XCP_THREE)) = (uint8)((Xcp_EthCtrTx >> XCP_EIGHT) & XCP_00FF);
    Xcp_EthCtrTx++;
    dtoi = &dtoi[XCP_FOUR];
    Xcp_MemCpy8(dtoi, &astpDto->bytes[XCP_ZERO], astpDto->length);
    Eth_Data.length += (astpDto->length + XCP_FOUR);
    Xcp_SendEthDaq(&Eth_Data);
#endif
}

#endif /* no define XCP_ENABLE_SEND_QUEUE */
/*
********************************************************************************
* Function Name: XCP_Event
*
* Explanation: Handling of data acquisition or stimulation event channel.
*
* param: avcEvent : event channel number to process.
*
* retval: None
********************************************************************************
*/
#if( MULTIPDUIDSUPPORT == STD_ON )
FUNC(uint8, XCP_CODE) Xcp_Event(uint8 avcEvent)
{
    uint8* dtoi = NULL_PTR;        /*dto[i]*/
    uint8  status = XCP_ZERO;      /*return value*/
    uint8  entrySize = XCP_ZERO;   /*OdtEntrySize*/
    uint8  daq = XCP_ZERO;
    uint8  odt = XCP_ZERO;
    uint8  index = XCP_ZERO;       /*Dto data start location*/
    Std_ReturnType retValue = E_NOT_OK;
    uint16 firstEntry = XCP_ZERO;
    uint16 lastEntry = XCP_ZERO;
    Xcp_TimestampType xcpTimeStamp; /*DAQ timestamp*/
    Xcp_Dto_st *dtop = NULL_PTR;   /*dto pointer*/

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
#else
    static Xcp_Dto_st dto;
#endif

    status = (uint8)XCP_ZERO;
    /* Daq did not startup, return; */
    if( (Xcp_Data.SessionStatus & (uint8)SS_DAQ) == XCP_ZERO )
    {
        retValue = (uint8)XCP_EVENT_NOP;
    }
    else
    {
         /* Event send */
#if defined (XCP_MAX_EVENT) && ! defined (XCP_ENABLE_MULDAQ_EVENT)
        if( (uint8)XCP_MAX_EVENT <= avcEvent )
        {
            retValue = (uint8)XCP_EVENT_NOP;
        }
        else
        {
            daq = Xcp_Data.Daq.EventDaq[avcEvent];
            /* DAQ is less than daqcount and belongs to the channel */
            if( ((daq < Xcp_Data.Daq.DaqCount) &&
                ((DaqListFlags(daq) & (uint8)DAQ_FLAG_RUNNING) != XCP_ZERO)) )
            {

#else
        for( daq = XCP_ZERO; daq < Xcp_Data.Daq.DaqCount; daq++ )
        {
            if( (DaqListFlags(daq)& (uint8)DAQ_FLAG_RUNNING) != XCP_ZERO ) /* Is DAQ started?  */
            {
                if( DaqListEventChannel(daq) == avcEvent ) /* Judge whether DAQ belongs to the channel */
                {
#endif
                /* pre send */
#if (XCP_PRESCALER_SUPPORTED == STD_ON)
                DaqListCycle(daq)--;
                if( DaqListCycle(daq) == (uint8)XCP_ZERO )
                {
                    DaqListCycle(daq) = DaqListPrescaler(daq);
#endif
                    /* Data Stimulation (STIM) */
                    for( odt = DaqListFirstOdt(daq); odt <= DaqListLastOdt(daq); odt++ )
                    {
                        status |= (uint8)XCP_EVENT_DAQ;
                        Xcp_InterruptDisable();    /* The following code is not reentrant */

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
                         /* Check if there is space in the queue for this ODT */
                        if( Xcp_Data.QueueLen[daq] >= Xcp_Data.QueueSize[daq] )
                        {
                            status |= (uint8)XCP_EVENT_DAQ_OVERRUN;    /* Queue overflow */
                            DaqListFlags(daq) |= (uint8)DAQ_FLAG_OVERRUN;
                        }
                        else
                        {
                            /* Xcp_Data.QueueLen >= Xcp_Data.QueueSize */
                            /*Positioning the dtop to a valid location on the queue*/
                            dtop = &Xcp_Data.pQueue[daq][(Xcp_Data.QueueRp[daq] +\
                                    Xcp_Data.QueueLen[daq]) % Xcp_Data.QueueSize[daq]];
                            Xcp_Data.QueueLen[daq]++;
#else
                            dtop = &dto;
#endif
                    /* Is ODT absolute or relative? This procedure is absolute */
#if ( ID_TYPE_ABSOLUTE == XCP_IDENTIFICATION_FIELD_TYPE )
                             /* PID */
                            dtop->bytes[XCP_ZERO] = odt;
                            index = XCP_ONE;
#else
                           /* ODT,DAQ */
                            dtop->bytes[XCP_ZERO] = odt - DaqListFirstOdt(daq); /* Relative odt number */
                            dtop->bytes[XCP_ONE] = daq;
                            index = XCP_TWO;
#endif

#if( XCP_TIMESTAMP_TYPE > XCP_ZERO )
                        /* If it is the first ODT and timestamp mode is enabled,
                            acquire timestamp and insert in response frame. */
                            if( (DaqListFirstOdt(daq) == odt) &&
                                ((DaqListFlags(daq) & DAQ_FLAG_TIMESTAMP) != XCP_ZERO) )
                            {
                                /* Acquire timestamp */
                                xcpTimeStamp = ApplXcpGetTimestamp();
                              /* Add a timestamp to the ODT according to the length of the timestamp */
                                if( XCP_TIMESTAMP_TYPE == XCPTS_ONE_BYTE )
                                {
                                    dtop->bytes[index] = xcpTimeStamp;
                                }
                                else if( XCP_TIMESTAMP_TYPE == XCPTS_TWO_BYTE )
                                {
                                    dtop->bytes[index] = (uint8)((xcpTimeStamp) & 0xFF);
                                    dtop->bytes[index + XCP_ONE] = (uint8)(((xcpTimeStamp) >> XCP_EIGHT) & 0xFF);
                                }
                                else
                                {
                                    dtop->bytes[index] = (uint8)((xcpTimeStamp) & 0xFF);
                                    dtop->bytes[index + XCP_ONE] = (uint8)(((xcpTimeStamp) >> XCP_EIGHT) & 0xFF);
                                    dtop->bytes[index + XCP_TWO] = (uint8)(((xcpTimeStamp) >> XCP_16) & 0xFF);
                                    dtop->bytes[index + XCP_THREE] = (uint8)(((xcpTimeStamp) >> XCP_24) & 0xFF);
                                }
                                index += sizeof(Xcp_TimestampType);
                            }
#endif /* XCP_TIMESTAMP_TYPE > XCP_ZERO */

        /* Use BIT7 of PID or ODT to indicate overruns */
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )

#ifdef XCP_ENABLE_DAQ_OVERRUN_INDICATION
                            if( (DaqListFlags(daq) & (uint8)DAQ_FLAG_OVERRUN) != XCP_ZERO )
                            {
                                dtop->bytes[XCP_ZERO] |= (uint8)XCP_0X80;
                                DaqListFlags(daq) &= (uint8)(~DAQ_FLAG_OVERRUN & XCP_FF);
                            }
#endif /* defined (XCP_ENABLE_DAQ_OVERRUN_INDICATION) */

#endif /* defined (XCP_ENABLE_SEND_QUEUE) */
                    /* Sample data sampling data cycle the entire ODT table reads the corresponding data
                    into dtop - > b [] according to the odtentryaddr in each odtentry*/
                    /* This is the inner loop, optimize here */
                            firstEntry = DaqListOdtFirstEntry(odt);
                            dtoi = (uint8*)&dtop->bytes[index];
                            if( OdtEntrySize(firstEntry) == XCP_ZERO )
                            {
                               /* goto next_odt */
                                dtop->length = (uint8)(dtoi-(&dtop->bytes[XCP_ZERO]));
                            }
                            else
                            {
                                lastEntry = DaqListOdtLastEntry(odt);
                                entrySize = XCP_ZERO;
                                while( firstEntry <= lastEntry )
                                {
                                     entrySize += OdtEntrySize(firstEntry);
                                     firstEntry++;
                                }
                                if( XCP_MAX_DTO < (entrySize + index) )/*Determine if it is out of range*/
                                {
                                     break;
                                }
                                firstEntry = DaqListOdtFirstEntry(odt);
                                while( firstEntry <= lastEntry )
                                {
                                    entrySize = OdtEntrySize(firstEntry);
                                    if( XCP_ZERO == entrySize )
                                    {
                                        break;
                                    }
                                    if( NULL_PTR == OdtEntryAddr(firstEntry) )
                                    {
                                        /* Suppress warning for MISRA rule 101 (pointer arithmetic) */
                                        dtoi = &dtoi[entrySize];
                                    }
                                    else
                                    {
                                        /* Copy data from ODT to SEND_QUEUE */
                                        Xcp_MemCpy8((uint8*)dtoi, OdtEntryAddr(firstEntry), entrySize);
                                        /* Suppress warning for MISRA rule 101 (pointer arithmetic) */
                                        dtoi= &dtoi[entrySize];
                                    }
                                    firstEntry++;
                                }
                                dtop->length = (uint8)(dtoi-(&dtop->bytes[XCP_ZERO]));
                            /*XCP_ASSERT(dtop->l<=XCP_MAX_DTO);*/
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
#else
                                Xcp_SendDto(&dto);
#endif

                            } /* OdtEntrySize(firstEntry) == XCP_ZERO */
                        } /* Xcp_Data.QueueLen >= Xcp_Data.QueueSize */
                        Xcp_InterruptEnable();
                    } /* odt */
                    retValue = status;

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
                    (void)Xcp_SendDtoFromQueue(avcEvent);
#endif

#if (XCP_PRESCALER_SUPPORTED == STD_ON)
                }
#endif

#ifdef XCP_ENABLE_MULDAQ_EVENT
                        }
                    }
#endif

            } /* daq */
        }
    }
    return retValue;
}

#else
FUNC(uint8, XCP_CODE) Xcp_Event(uint8 avcEvent)
{
    uint8 daq = XCP_ZERO;
    uint8 status = XCP_ZERO;      /*return value*/
    Std_ReturnType retValue = E_NOT_OK;

    status = (uint8)XCP_ZERO;
    /* Daq did not startup, return; */
    if( (Xcp_Data.SessionStatus & (uint8)SS_DAQ) == XCP_ZERO )
    {
        retValue = (uint8)XCP_EVENT_NOP;
    }
    else
    {
                /* Event send */
#if defined (XCP_MAX_EVENT) && ! defined (XCP_ENABLE_MULDAQ_EVENT)
        if( (uint8)XCP_MAX_EVENT <= avcEvent )
        {
            retValue = (uint8)XCP_EVENT_NOP;
        }
        else
        {
            daq = Xcp_Data.Daq.EventDaq[avcEvent];
            /* DAQ is less than daqcount and belongs to the channel */
            if( ((daq < Xcp_Data.Daq.DaqCount) &&
                ((DaqListFlags(daq) & (uint8)DAQ_FLAG_RUNNING) != XCP_ZERO)) )
            {

#else
        for( daq = XCP_ZERO; daq < Xcp_Data.Daq.DaqCount; daq++ )
            {
                if( (DaqListFlags(daq)& (uint8)DAQ_FLAG_RUNNING) != XCP_ZERO ) /* Is DAQ started?  */
                {
                    if( DaqListEventChannel(daq) == avcEvent ) /* Judge whether DAQ belongs to the channel */
                    {
#endif
                        if( (DaqListFlags(daq) & (uint8)DAQ_FLAG_DIRECTION) != XCP_ZERO )
                        {
                            status = Xcp_StimEvent(daq);
                        }
                        else
                        {
                            status = Xcp_DaqEvent(daq);
                        }
                        retValue = status;

#ifdef XCP_ENABLE_MULDAQ_EVENT
                    }
                }
            } /* daq */
#else
            }
        }
#endif
    }

    return retValue;
}
#endif

/*
********************************************************************************
* Function Name: Xcp_StimEvent
*
* Explanation: xcp stim active process.
*
* param: daq :  the daq belong to chanel.
*
* retval: None
********************************************************************************
*/
FUNC(uint8, XCP_CODE) Xcp_StimEvent(uint8 daq)
{
    uint8 nowQueue = XCP_ZERO;     /* curruent queue */
    uint8 odt = XCP_ZERO;
    uint8 indexFromRp = XCP_ZERO;
    uint8 indexFromZero = XCP_ZERO;
    uint8 indexStop = XCP_ZERO;
    uint16 firstEntry = XCP_ZERO;
    uint16 lastEntry = XCP_ZERO;
    uint8  entrySize = XCP_ZERO;
    uint8* dataP = NULL_PTR;
    uint8 status = XCP_ZERO;
    Std_ReturnType retValue = E_NOT_OK;

    /* pre send */
#if (XCP_PRESCALER_SUPPORTED == STD_ON)
    DaqListCycle(daq)--;
    if( (uint8)XCP_ZERO == DaqListCycle(daq) )
    {
        DaqListCycle(daq) = DaqListPrescaler(daq);
#endif
        Xcp_InterruptDisable();
        if( Xcp_Data.QueueLenStim >= Xcp_Data.QueueSizeStim )
        {
            status |= (uint8)XCP_EVENT_STIM_OVERRUN;    /* Queue overflow */
            DaqListFlags(daq) |= (uint8)DAQ_FLAG_OVERRUN;
        }
        else
        {
            status |= (uint8)XCP_EVENT_STIM;
            indexFromRp = XCP_ZERO;
            while( indexFromRp < Xcp_Data.QueueLenStim )
            {
                nowQueue = Xcp_Data.QueueRpStim + indexFromRp;
                if( nowQueue > Xcp_Data.QueueSizeStim )
                {
                    nowQueue = nowQueue - Xcp_Data.QueueSizeStim - XCP_ONE;
                }

                if( XcpStimOdt(nowQueue) >= DaqListFirstOdt(daq) &&
                    XcpStimOdt(nowQueue) <= DaqListLastOdt(daq) )
                {
                    odt = XcpStimOdt(nowQueue);
                    dataP = XcpStimData(nowQueue);
                    firstEntry = DaqListOdtFirstEntry(odt);
                    lastEntry = DaqListOdtLastEntry(odt);
                    while( firstEntry <= lastEntry )
                    {
                        entrySize = OdtEntrySize(firstEntry);
                        if( NULL_PTR == OdtEntryAddr(firstEntry) )
                        {
                            /* Suppress warning for MISRA rule 101 (pointer arithmetic) */
                            dataP = &dataP[entrySize];
                        }
                        else
                        {
                            /* Copy data from RECEIVE_QUEUE to ODT */
                            Xcp_MemCpy8((uint8*)OdtEntryAddr(firstEntry), dataP, entrySize);
                            dataP = &dataP[entrySize];
                        }
                        firstEntry++;
                    }

                    if( Xcp_Data.QueueRpStim + Xcp_Data.QueueLenStim < Xcp_Data.QueueSizeStim )
                    {
                        for( ; nowQueue < Xcp_Data.QueueSizeStim - XCP_ONE; nowQueue++ )
                        {
                            Xcp_MemCpy8((uint8*)(&Xcp_Data.pQueueStim[nowQueue]),
                                        (uint8*)(&Xcp_Data.pQueueStim[nowQueue + XCP_ONE]),
                                        sizeof(Xcp_Stim_Dto_st));
                        }
                    }
                    else
                    {
                        for( ; nowQueue < Xcp_Data.QueueSizeStim - XCP_ONE; nowQueue++ )
                        {
                            Xcp_MemCpy8((uint8*)(&Xcp_Data.pQueueStim[nowQueue]),
                                        (uint8*)(&Xcp_Data.pQueueStim[nowQueue + XCP_ONE]),
                                        sizeof(Xcp_Stim_Dto_st));
                        }

                        indexStop = Xcp_Data.QueueLenStim - (Xcp_Data.QueueSizeStim - Xcp_Data.QueueRpStim);
                        if( XCP_ZERO == indexStop )
                        {
                            Xcp_MemCpy8((uint8*)(&Xcp_Data.pQueueStim[Xcp_Data.QueueSizeStim - XCP_ONE]),
                                            (uint8*)(&Xcp_Data.pQueueStim[XCP_ZERO]),
                                            sizeof(Xcp_Stim_Dto_st));

                            for( indexFromZero =  XCP_ONE; indexFromZero < indexStop; indexFromZero++ )
                            {
                                Xcp_MemCpy8((uint8*)(&Xcp_Data.pQueueStim[indexFromZero]),
                                            (uint8*)(&Xcp_Data.pQueueStim[indexFromZero+1]),
                                            sizeof(Xcp_Stim_Dto_st));
                            }
                        }
                        else
                        {
                            Xcp_RecordError(CRC_MEMORY_OVERFLOW);
                            Xcp_SendCrm();
                        }
                    }
                    Xcp_Data.QueueLenStim--;
                }
                else
                {
                    indexFromRp++;
                }
            }
        }
        Xcp_InterruptEnable();
        retValue = status;

#if (XCP_PRESCALER_SUPPORTED == STD_ON)
    }
#endif
    return retValue;
}

/*
********************************************************************************
* Function Name: Xcp_DaqEvent
*
* Explanation: xcp daq active process.
*
* param: daq :  the daq belong to chanel.
*
* retval: None
********************************************************************************
*/
FUNC(uint8, XCP_CODE) Xcp_DaqEvent(uint8 daq)
{
    uint8* dtoi = NULL_PTR;        /*dto[i]*/
    uint8  status = XCP_ZERO;      /*return value*/
    uint8  entrySize = XCP_ZERO;   /*OdtEntrySize*/
    uint8  odt = XCP_ZERO;
    uint8  index = XCP_ZERO;       /*Dto data start location*/
    Std_ReturnType retValue = E_NOT_OK;
    Xcp_Dto_st *dtop = NULL_PTR;   /*dto pointer*/
    uint16 firstEntry = XCP_ZERO;
    uint16 lastEntry = XCP_ZERO;

#if( XCP_TIMESTAMP_TYPE > XCP_ZERO )
    Xcp_TimestampType xcpTimeStamp; /*DAQ timestamp*/
#endif

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
#else
    static Xcp_Dto_st dto;
#endif

    status = (uint8)XCP_ZERO;

    /* pre send */
#if (XCP_PRESCALER_SUPPORTED == STD_ON)
    DaqListCycle(daq)--;
    if( DaqListCycle(daq) == (uint8)XCP_ZERO )
    {
        DaqListCycle(daq) = DaqListPrescaler(daq);
#endif
        /* Data Stimulation (STIM) */
        for( odt = DaqListFirstOdt(daq); odt <= DaqListLastOdt(daq); odt++ )
        {
            status |= (uint8)XCP_EVENT_DAQ;
            Xcp_InterruptDisable();    /* The following code is not reentrant */
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
            /* Check if there is space in the queue for this ODT */
            if( Xcp_Data.QueueLen >= Xcp_Data.QueueSize )
            {
                status |= (uint8)XCP_EVENT_DAQ_OVERRUN;    /* Queue overflow */
                DaqListFlags(daq) |= (uint8)DAQ_FLAG_OVERRUN;
            }
            else
            {
                /* Xcp_Data.QueueLen >= Xcp_Data.QueueSize */
                /*Positioning the dtop to a valid location on the queue*/
                dtop = &Xcp_Data.pQueue[(Xcp_Data.QueueRp + Xcp_Data.QueueLen) % Xcp_Data.QueueSize];
                Xcp_Data.QueueLen++;
#else
                dtop = &dto;
#endif
                /* Is ODT absolute or relative? This procedure is absolute */
#if ( ID_TYPE_ABSOLUTE == XCP_IDENTIFICATION_FIELD_TYPE )
                /* PID */
                dtop->bytes[XCP_ZERO] = odt;
                index = XCP_ONE;
#else
                /* ODT,DAQ */
                dtop->bytes[XCP_ZERO] = odt - DaqListFirstOdt(daq); /* Relative odt number */
                dtop->bytes[XCP_ONE] = daq;
                index = XCP_TWO;
#endif

#if( XCP_TIMESTAMP_TYPE > XCP_ZERO )
                /* If it is the first ODT and timestamp mode is enabled,
                acquire timestamp and insert in response frame. */
                if( (DaqListFirstOdt(daq) == odt) &&
                    ((DaqListFlags(daq) & DAQ_FLAG_TIMESTAMP) != XCP_ZERO) )
                {
                    /* Acquire timestamp */
                    xcpTimeStamp = ApplXcpGetTimestamp();
                    /* Add a timestamp to the ODT according to the length of the timestamp */
                    if( XCP_TIMESTAMP_TYPE == XCPTS_ONE_BYTE )
                    {
                        dtop->bytes[index] = xcpTimeStamp;
                    }
                    else if( XCP_TIMESTAMP_TYPE == XCPTS_TWO_BYTE )
                    {
                        dtop->bytes[index] = (uint8)((xcpTimeStamp) & 0xFF);
                        dtop->bytes[index + XCP_ONE] = (uint8)(((xcpTimeStamp) >> XCP_EIGHT) & 0xFF);
                    }
                    else
                    {
                        dtop->bytes[index] = (uint8)((xcpTimeStamp) & 0xFF);
                        dtop->bytes[index + XCP_ONE] = (uint8)(((xcpTimeStamp) >> XCP_EIGHT) & 0xFF);
                        dtop->bytes[index + XCP_TWO] = (uint8)(((xcpTimeStamp) >> XCP_16) & 0xFF);
                        dtop->bytes[index + XCP_THREE] = (uint8)(((xcpTimeStamp) >> XCP_24) & 0xFF);
                    }
                    index += sizeof(Xcp_TimestampType);
                }
#endif /* XCP_TIMESTAMP_TYPE > XCP_ZERO */

/* Use BIT7 of PID or ODT to indicate overruns */
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )

#ifdef XCP_ENABLE_DAQ_OVERRUN_INDICATION
                if( (DaqListFlags(daq) & (uint8)DAQ_FLAG_OVERRUN) != XCP_ZERO )
                {
                    dtop->bytes[XCP_ZERO] |= (uint8)XCP_0X80;
                    DaqListFlags(daq) &= (uint8)(~DAQ_FLAG_OVERRUN & XCP_FF);
                }
#endif /* defined (XCP_ENABLE_DAQ_OVERRUN_INDICATION) */

#endif /* defined (XCP_ENABLE_SEND_QUEUE) */
                /* Sample data sampling data cycle the entire ODT table reads the corresponding data
                into dtop - > b [] according to the odtentryaddr in each odtentry*/
                /* This is the inner loop, optimize here */
                firstEntry = DaqListOdtFirstEntry(odt);
                dtoi = (uint8*)&dtop->bytes[index];
                if( OdtEntrySize(firstEntry) == XCP_ZERO )
                {
                    /* goto next_odt */
                    dtop->length = (uint8)(dtoi-(&dtop->bytes[XCP_ZERO]));
                }
                else
                {
                    lastEntry = DaqListOdtLastEntry(odt);
                    entrySize = XCP_ZERO;
                    while( firstEntry <= lastEntry )
                    {
                        entrySize += OdtEntrySize(firstEntry);
                        firstEntry++;
                    }
                    if( XCP_MAX_DTO < (entrySize + index) )     /* Determine if it is out of range. */
                    {
                        break;
                    }
                    firstEntry = DaqListOdtFirstEntry(odt);
                    while( firstEntry <= lastEntry )
                    {
                        entrySize = OdtEntrySize(firstEntry);
                        if( NULL_PTR == OdtEntryAddr(firstEntry) )
                        {
                            /* Suppress warning for MISRA rule 101 (pointer arithmetic) */
                            dtoi = &dtoi[entrySize];
                        }
                        else
                        {
                            /* Copy data from ODT to SEND_QUEUE */
                            Xcp_MemCpy8((uint8*)dtoi, OdtEntryAddr(firstEntry), entrySize);
                            /* Suppress warning for MISRA rule 101 (pointer arithmetic) */
                            dtoi= &dtoi[entrySize];
                        }
                        firstEntry++;
                    }
                    dtop->length = (uint16)(dtoi-(&dtop->bytes[XCP_ZERO]));
                    /*XCP_ASSERT(dtop->l<=XCP_MAX_DTO);*/
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
#else
                    Xcp_SendDtoMode(&dto);
#endif

                } /*OdtEntrySize(firstEntry) == XCP_ZERO*/
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )     
            } /*Xcp_Data.QueueLen >= Xcp_Data.QueueSize*/
#endif

            Xcp_InterruptEnable();
        }/* odt */

        retValue = status;

#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
        (void)Xcp_SendDtoFromQueue();
#endif

#if (XCP_PRESCALER_SUPPORTED == STD_ON)
    }
#endif


    return retValue;

}

/*
********************************************************************************
* Function Name: XCP_Command
*
* Explanation: xcp command process.
*
* param: avlpCommand: data of received CTO message.
*
* retval: None
********************************************************************************
*/
FUNC(void, XCP_CODE) Xcp_Command
(
    P2VAR(const uint32, AUTOMATIC, XCP_APPL_DATA) avlpCommand
)
{
#if( MULTIPDUIDSUPPORT == STD_ON )
    uint8 index;
#endif

    const Xcp_Cto_st* pCmd = (const Xcp_Cto_st*) avlpCommand;

    if( CRO_CMD == CC_CONNECT ) /* CONNECT */
    {
        /* Prepare the default response */
        CRM_CMD = PID_RES;       /* No Error */
        Xcp_Data.CrmLen = XCP_ONE;        /* Length = 1 */
        /* Reset DAQ */
        /* Do not reset DAQ if in resume mode */
#ifdef XCP_ENABLE_DAQ
        if( (Xcp_Data.SessionStatus & (uint8)SS_RESUME) == XCP_ZERO )
        {
            Xcp_FreeDaq();
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )

#if ( MULTIPDUIDSUPPORT == STD_ON )
            for(index = XCP_ZERO; index < XCP_TXPDU_LIST; index++)
            {
                Xcp_Data.SendStatus[index] = XCP_ZERO; /* Clear all transmission flags */
            }
#else
            Xcp_Data.SendStatus = XCP_ZERO; /* Clear all transmission flags */
#endif

#endif
        }
#endif /* defined (XCP_ENABLE_DAQ) */

#if( XCP_ENABLE_SEED_KEY == STD_ON )
        /* Lock all resources. */
        Xcp_Data.ProtectionStatus = (uint8)RM_CAL_PAG|RM_DAQ|RM_PGM|RM_STIM;
#endif
        /* Reset Session Status */
        Xcp_Data.SessionStatus = SS_CONNECTED;
        Xcp_Data.CrmLen = CRM_CONNECT_LEN;

#ifdef XCP_ENABLE_CALIBRATION_PAGE
        CRM_CONNECT_RESOURCE |= RM_CAL_PAG;  /* CRM[1] */
#else
        CRM_CONNECT_RESOURCE = XCP_ZERO;
#endif

#ifdef XCP_ENABLE_DAQ
        CRM_CONNECT_RESOURCE |= (uint8)RM_DAQ_STIM;  /* Data Acquisition */
#endif

#if (STD_ON == XCP_FLASH_PROGRAMING_ENABLE)
        CRM_CONNECT_RESOURCE |= (uint8)RM_PGM;
#endif

#ifdef XCP_ENABLE_COMM_MODE_INFO
        CRM_CONNECT_COMM_BASIC |= (uint8)CMB_OPTIONAL;
#endif

        CRM_CONNECT_COMM_BASIC = (uint8)CMB_ADDRESS_GRANULARITY_BYTE;   /* CRM[2] */
#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        CRM_CONNECT_COMM_BASIC |= (uint8)PI_INTEL;
#else
        CRM_CONNECT_COMM_BASIC |= (uint8)PI_MOTOROLA;
#endif
#if( STD_ON == XCP_BLOCK_UPLOAD )
        CRM_CONNECT_COMM_BASIC |= (uint8)CMB_SLAVE_BLOCK_MODE;
#endif
        CRM_CONNECT_MAX_CTO_SIZE = XCP_MAX_CTO;                                                   /* CRM[3] */
        CRM_CONNECT_MAX_DTO_SIZE = XCP_MAX_DTO;                                                   /* CRM[4] */
        CRM_CONNECT_PROTOCOL_VERSION =  (uint8)( (uint16)XCP_VERSION >> XCP_EIGHT);                  /* CRM[6] */
        CRM_CONNECT_TRANSPORT_VERSION = (uint8)( (uint16)XCP_TRANSPORT_LAYER_VERSION >> XCP_EIGHT);  /* CRM[7] */
        Xcp_SendCrm();
    }

    /* CRO_CMD == CC_CONNECT */
    /* Handle other commands only if connected */
    else /* CC_CONNECT */
    {
        if( (Xcp_Data.SessionStatus & (uint8)SS_CONNECTED) != XCP_ZERO )
        {
            /* Ignore commands if the previous command sequence has not been completed */
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )

#if( MULTIPDUIDSUPPORT == STD_ON )
            if( (Xcp_Data.SendStatus[XCP_EVENT_CHANNEL_NUM] & (uint8)(XCP_CRM_PENDING|XCP_CRM_REQUEST)) != XCP_ZERO )
            {
                Xcp_Data.SessionStatus |= (uint8)SS_ERROR;
                /* No response */
            }
#else
            if( (Xcp_Data.SendStatus & (uint8)(XCP_CRM_PENDING|XCP_CRM_REQUEST)) != XCP_ZERO )
            {
                Xcp_Data.SessionStatus |= (uint8)SS_ERROR;
                /* No response */
            }
#endif
            else
            {
#else
#endif   /* XCP_ENABLE_SEND_QUEUE ==  STD_OFF*/
                /* Prepare the default response */
                CRM_CMD = XCP_FF;
                Xcp_Data.CrmLen = XCP_ONE;
                switch( CRO_CMD )
                {
                    case CC_SYNC:
                    {
                        /* Always return a negative response with the error code ERR_CMD_SYNCH. */
                        Xcp_CC_Sync();
                    }
                    break;

#ifdef XCP_ENABLE_COMM_MODE_INFO
                    case CC_GET_COMM_MODE_INFO:
                    {
                        Xcp_CC_GetCommModeInfo();
                    }
                    break;
#endif /* XCP_ENABLE_COMM_MODE_INFO */

                    case CC_DISCONNECT:
                    {
                        Xcp_CC_Disconnect();
                    }
                    break;
                    case CC_GET_ID:
                    {
                        Xcp_CC_GetID(pCmd);
                    }
                    break;
                    case CC_GET_STATUS:
                    {
                        Xcp_CC_GetStatus();
                    }
                    break;

#if( XCP_ENABLE_SEED_KEY == STD_ON )
                    case CC_GET_SEED:
                    {
                        /* Check whether the first part or a remaining part of the seed is requested. */
                        Xcp_CC_GetSeed(pCmd);
                    }
                    break;
                    case CC_UNLOCK:
                    {
                        Xcp_CC_UnLock(pCmd);
                    }
                    break;
#endif  /* XCP_ENABLE_SEED_KEY */

#ifdef XCP_ENABLE_CALIBRATION_PAGE
                    case CC_SET_CAL_PAGE:
                    {
                        Xcp_CC_SetCalpage(pCmd);
                    }
                    break;
                    case CC_GET_CAL_PAGE:
                    {
                        Xcp_CC_GetCalPage(pCmd);
                    }
                    break;
                    /* Paging Information optional */
                    case CC_GET_PAG_PROCESSOR_INFO:
                    {
                        Xcp_CC_GetPagProcessorInfo();
                    }
                    break;
#endif /* XCP_ENABLE_CALIBRATION_PAGE */

                    case CC_GET_SEGMENT_INFO:
                    {
                        Xcp_CC_GetSegmentInfo(pCmd);
                    }
                    break;
                    case CC_GET_PAGE_INFO:
                    {
                        Xcp_CC_GetPageInfo(pCmd);
                    }
                    break;
       /* Paging freeze mode support */
#ifdef XCP_ENABLE_PAGE_FREEZE
                    case CC_SET_SEGMENT_MODE:
                    {
                    }
                    break;
                    case CC_GET_SEGMENT_MODE:
                    {
                    }
                    break;
#endif /* XCP_ENABLE_PAGE_FREEZE */

       /* Copy cal page support */
#ifdef XCP_ENABLE_PAGE_COPY
                    case CC_COPY_CAL_PAGE:
                    {
                        Xcp_CC_CopyCalPage(pCmd);
                    }
                    break;
#endif
                    case CC_SET_MTA:
                    {

                        if(Xcp_GetPointer(CRO_SET_MTA_EXT, CRO_SET_MTA_ADDR) == 0x00000000)
                        {
                            CRM_CMD = (uint8)PID_ERR;
                            CRM_ERR = (uint8)CRC_MEMORY_OVERFLOW;
                        }
                        else
                        {
                        	Xcp_CC_SetMta(pCmd);
                        }
                    }
                    break;
                    case CC_DOWNLOAD:
                    {
                        Xcp_CC_Download(pCmd);
                    }
                    break;
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
                    case CC_DOWNLOAD_NEXT:
                    {
                        Xcp_CC_DownloadNext(pCmd);
                    }
                    break;
#endif
                    case CC_DOWNLOAD_MAX:
                    {
                        Xcp_CC_DownloadMax(pCmd);
                    }
                    break;
                    case CC_UPLOAD:
                    {
                        Xcp_CC_UpLoad(pCmd);
                    }
                    break;
                    case CC_SHORT_UPLOAD:
                    {
                        Xcp_CC_ShortUplod(pCmd);
                    }
                    break;

#if( STD_ON == XCP_ENABLE_CHECKSUM )
                    case CC_BUILD_CHECKSUM:
                    {
                        Xcp_CC_BuildCheckum(pCmd);
                        if( CRM_CMD != PID_ERR)
                        {
                            Xcp_Pending = XCP_ONE;
                        }
                    }
                    break;
#endif /* XCP_ENABLE_CHECKSUM */

#ifdef XCP_ENABLE_DAQ
                    case CC_GET_DAQ_PROCESSOR_INFO:
                    {
                        Xcp_CC_GetDaqProcessorInfo();
                    }
                    break;
                    case CC_GET_DAQ_RESOLUTION_INFO:
                    {
                        Xcp_CC_GetDaqResolutionInfo();
                    }
                    break;
                    case CC_GET_DAQ_EVENT_INFO:
                    {
                        Xcp_CC_GetDaqEventInfo(pCmd);
                    }
                    break;
                    case CC_FREE_DAQ:
                    {
                        Xcp_CC_FreeDaq();
                    }
                    break;
                    case CC_ALLOC_DAQ:
                    {
                        Xcp_CC_AllocDaq(pCmd);
                    }
                    break;
                    case CC_ALLOC_ODT:
                    {
                        Xcp_CC_AllocOdt(pCmd);
                    }
                    break;
                    case CC_ALLOC_ODT_ENTRY:
                    {
                        Xcp_CC_AllocOdtEntry(pCmd);
                    }
                    break;
                    case CC_GET_DAQ_LIST_MODE:
                    {
                        Xcp_CC_GetDaqListMode(pCmd);
                    }
                    break;
                    case CC_SET_DAQ_LIST_MODE:
                    {
                        Xcp_CC_SetDaqListMode(pCmd);
                    }
                    break;
                    case CC_SET_DAQ_PTR:
                    {
                        Xcp_CC_SetDaqPtr(pCmd);
                    }
                    break;
                    case CC_WRITE_DAQ: /* Write DAQ entry */
                    {
                        if(Xcp_GetPointer(CRO_WRITE_DAQ_EXT, CRO_WRITE_DAQ_ADDR) == 0x00000000)
                        {
                            CRM_CMD = (uint8)PID_ERR;
                            CRM_ERR = (uint8)CRC_OUT_OF_RANGE;
                        }
                        else if((Xcp_GetPointer(CRO_WRITE_DAQ_EXT, CRO_WRITE_DAQ_ADDR) < XCP_OBS_LIMIT_MINADDR_MP)||(Xcp_GetPointer(CRO_WRITE_DAQ_EXT, CRO_WRITE_DAQ_ADDR) > XCP_OBS_LIMIT_MAXADDR_MP))
                        {
                            CRM_ERR = (uint8)CRC_OUT_OF_RANGE;
                        }
                        else
                        {
                        	Xcp_CC_WriteDaq(pCmd);
                        }
                    }
                    break;
                    case CC_START_STOP_DAQ_LIST:
                    {
                        Xcp_CC_StartStopDaqList(pCmd);
                    }
                    break;
                    case CC_START_STOP_SYNCH:
                    {
                        Xcp_CC_StartStopSynch(pCmd);
                    }
                    break;
                    case CC_GET_DAQ_CLOCK:
                    {
                        Xcp_CC_GetDaqClock();
                    }
                    break;
#endif /* XCP_ENABLE_DAQ */
#if (STD_ON == XCP_FLASH_PROGRAMING_ENABLE)

                    case CC_PROGRAM_START:
                    {
                        Xcp_CC_Program_Start();
                    }
                    break;

                    case CC_PROGRAM_CLEAR:
                    {
                        Xcp_CC_Program_Clear(pCmd);
                    }
                    break;

                    case CC_PROGRAM:
                    {
                        Xcp_CC_Program(pCmd);
                    }
                    break;
#if( STD_ON == XCP_BLOCK_DOWNLOAD )
                    case CC_PROGRAM_NEXT:
                    {
                        Xcp_CC_Program_Next(pCmd);
                    }
                    break;
#endif
                    case CC_PROGRAM_MAX:
                    {
                        Xcp_CC_Program_Max(pCmd);
                    }
                    break;

                    case CC_PROGRAM_RESET:
                    {
                        Xcp_CC_Program_Reset(pCmd);
                    }
                    break;
#endif /* STD_ON == XCP_FLASH_PROGRAMING_ENABLE */

#if( XCP_ENABLE_NVM_SAVE_DATA == STD_ON )
                    case CC_SET_REQUEST:
                    {
                        Xcp_CC_Set_Request(pCmd);
                    }
                    break;
#endif /* XCP_ENABLE_NVM_SAVE_DATA */

#ifdef XCP_ENABLE_USER_COMMAND
                    case CC_USER_CMD:
                    {
                    }
                    break;
#endif /* XCP_ENABLE_USER_COMMAND */

                    default: /* unknown */
                    {
                        Xcp_RecordError(CRC_CMD_UNKNOWN);
                    }
                } /* switch */
                if( Xcp_Pending == XCP_ZERO )
                {
                    Xcp_SendCrm();
                }
#if ( XCP_ENABLE_SEND_QUEUE == STD_ON )
            }
#endif
        }
        /* Not connected */
        else
        {
            /* Do nothing */
        }
    } /* CC_CONNECT */
}

FUNC(void, XCP_CODE) Xcp_StimDate
(
    P2VAR(const uint8, AUTOMATIC, XCP_APPL_DATA) stimDate,
    uint32 dateLen
)
{
    uint8 indexDaq;
    Xcp_Stim_Dto_st* dtoStimp;
    uint8* Xcp_Stim_Date = (uint8*) stimDate;
    uint8 firstOdtFlag = FALSE;
    if( (*Xcp_Stim_Date) <= PID_STIM_END )
    {
        CRM_CMD = XCP_FF;
        Xcp_Data.CrmLen = XCP_ONE;
        if( Xcp_Data.QueueLenStim >= Xcp_Data.QueueSizeStim )
        {
            Xcp_RecordError(CRC_MEMORY_OVERFLOW);
            Xcp_SendCrm();
        }
        else
        {
            dtoStimp = &Xcp_Data.pQueueStim[(Xcp_Data.QueueRpStim+Xcp_Data.QueueLenStim) % Xcp_Data.QueueSizeStim];
            Xcp_Data.QueueLenStim++;
#if( ID_TYPE_ABSOLUTE == XCP_IDENTIFICATION_FIELD_TYPE )
            dtoStimp->xcpStimOdt = *Xcp_Stim_Date;
            Xcp_Stim_Date = Xcp_Stim_Date + XCP_ONE;
#else
            /* ODT,DAQ */
            dtoStimp->xcpStimDaq = *(Xcp_Stim_Date + XCP_ONE);
            dtoStimp->xcpStimOdt = *Xcp_Stim_Date + DaqListFirstOdt(dtoStimp->xcpStimDaq);
            Xcp_Stim_Date = Xcp_Stim_Date + XCP_TWO;
#endif
            for( indexDaq = XCP_ZERO; indexDaq < Xcp_Data.Daq.DaqCount; indexDaq++ )
            {
                if( dtoStimp->xcpStimOdt == DaqListFirstOdt(indexDaq) )
                {
                    firstOdtFlag = TRUE;
                    break;
                }
            }

            if( TRUE == firstOdtFlag )
            {
#if( XCP_TIMESTAMP_TYPE > XCP_ZERO )
                if( XCPTS_ONE_BYTE == XCP_TIMESTAMP_TYPE )
                {
                    Xcp_MemCpy8((uint8*)&dtoStimp->xcpStimTimeStamp, Xcp_Stim_Date, XCP_ONE);
                    Xcp_Stim_Date++;
                }
                else if( XCPTS_TWO_BYTE == XCP_TIMESTAMP_TYPE )
                {
                    Xcp_MemCpy8((uint8*)&dtoStimp->xcpStimTimeStamp, Xcp_Stim_Date, XCP_TWO);
                    Xcp_Stim_Date = (uint8*)Xcp_Stim_Date + XCP_TWO;
                }
                else
                {
                    Xcp_MemCpy8((uint8*)&dtoStimp->xcpStimTimeStamp, Xcp_Stim_Date, XCP_FOUR);
                    Xcp_Stim_Date = (uint8*)Xcp_Stim_Date + XCP_FOUR;
                }
    #endif /* XCP_TIMESTAMP_TYPE > XCP_ZERO */
                    Xcp_MemCpy8((uint8*)dtoStimp->bytes, Xcp_Stim_Date,
                    dateLen - XCP_TIMESTAMP_TYPE - XCP_IDENTIFICATION_FIELD_TYPE);
            }
            else
            {
                Xcp_MemCpy8((uint8*)dtoStimp->bytes, Xcp_Stim_Date,
                dateLen - XCP_IDENTIFICATION_FIELD_TYPE);
            }
        }

    }
}



#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h"
