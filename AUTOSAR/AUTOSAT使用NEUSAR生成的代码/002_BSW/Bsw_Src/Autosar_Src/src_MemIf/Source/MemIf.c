/*
********************************************************************************
*
* File name: MemIf.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2018.11.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: WangJipeng/2018.11.14
* Change: MemIf_GetVersionInfo add null pointer decide.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date: WangJipeng/2019.01.05
* Change: Add configuration items,Optimize the internal implementation of each
*         function.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: TongQian/2019.05.05
* Change: Increase the function of error detection to detect development errors.
* Cause: Add function
********************************************************************************
* Version: 1.4
* Author/Date: TongQian/2019.05.06
* Change: Perfecting the Function of MemIf_GetStatus Function.
* Cause: Optimization
********************************************************************************
* Version: 1.5
* Author/Date: TongQian/2019.05.08
* Change: Adjust the code format.
* Cause: Optimization
********************************************************************************
* Version: 1.6
* Author/Date: TongQian/2019.05.10
* Change: Remove null pointer judgment.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date: Liuziyang/2020.03.27
* Change: Optimize MemIf_ChkDeviceIndex logic.
* Cause: Optimization and update.
********************************************************************************
* Version: 3.1
* Author/Date: Hanbaiyu/2020.09.29
* Change: 1. Change the code style to AUTOSAR format.
*         2. Add definition of paragraph.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: HanBY/2020.11.04
* Change: Deleting memrory maps for variable or function declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: HanBY/2020.11.09
* Change: Add the precompile of Det.h.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: HanBY/2020.12.07
* Change: Modify code format.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: HanBY/2021.10.27
* Change: Delete the header MemIf_MemMap.h.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: LiK/2022.8.12
* Change: MemIf_Det_ErrorReport API add macro switch.
* Cause: Bugfix
********************************************************************************
* Version: 3.7
* Author/Date: LiDY/2023.3.19
* Change: Modify MemIf_SetMode/MemIf_GetStatus how to get the device id.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: WangLX/2023.10.30
* Change: Move MemIf_ChkDeviceIndex to MEMIF_DEV_ERROR_DETECT macro middle.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: WangLX/2024.04.25
* Change: Add a memory-map label to function and variable declarations.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: WangLX/2024.08.08
* Change: Change copyright information.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: ZhangXL/2025.03.31
* Change: 1. Fix QAC and Polyspace warnings and add analysis results.
*         2. Modify the DET detection method to always check the input
*            parameters of the function, even if DET is disabled.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: Chixp/2025.06.05
* Change: Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: Chixp/2025.06.23
* Change: Update the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "MemIf.h"

#if( MEMIF_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
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
#define MEMIF_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
static FUNC(void, MEMIF_CODE) MemIf_Det_ErrorReport(uint8 ApiId, uint8 ErrorId);
#endif

static FUNC(Std_ReturnType, MEMIF_CODE) MemIf_IsBitSet(uint8 Mask, MemIf_StatusType Status);

#define MEMIF_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
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
#define MEMIF_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
/*
********************************************************************************
* Function Name: MemIf_Det_ErrorReport
*
* Explanation: Function to report Error to Det.
*
* param: ApiId: Unique Api ID of MemIf manager service.
*         ErrorId: Det Error ID of MemIf manager.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_MemIf_Dir4.5" */
static FUNC(void, MEMIF_CODE) MemIf_Det_ErrorReport(uint8 ApiId, uint8 ErrorId)
{
    /* Report Error to Det. */
    (void)Det_ReportError(MEMIF_MODULE_ID, MEMIF_INSTANCE_ID, ApiId, ErrorId);
}
#endif

/*
********************************************************************************
* Function Name: MemIf_IsBitSet
*
* Explanation: Returns whether the state of the underlying Abstract module or
*               device driver is set.
*
* param: Mask: Store the state of the underlying Abstract module or device
*               driver.
*         Status: The state of the underlying Abstract module or device driver.
*
* retval: E_OK: The state of the underlying Abstract module or device driver
*               has been set.
*         E_NOT_OK: The state of the underlying Abstract module or device driver
*                   is not set.
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_MemIf_Dir4.5" */
static FUNC(Std_ReturnType, MEMIF_CODE) MemIf_IsBitSet(uint8 Mask, MemIf_StatusType Status)
{
    Std_ReturnType RtrnValu = E_NOT_OK;

    /* Determines the state. */
    if( (Mask & (uint8)(STORE_EACH_STATUS << (uint8)Status)) > DETERMINE_STATE_VALUE )
    {
        RtrnValu = E_OK;
    }

    return RtrnValu;
}

/*
********************************************************************************
* Function Name: MemIf_SetMode
*
* Explanation: Invokes the "SetMode" functions of all underlying memory
*              abstraction modules.(Synchronous)
*
* param: Mode: Denotes the operation mode of the underlying abstraction modules
*               and device drivers.
*
* retval: void
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_MemIf_Dir4.5" */
FUNC(void, MEMIF_CODE) MemIf_SetMode(MemIf_ModeType Mode)
{

#if( MEMIF_FEE_ENABLE == STD_ON )
    MemIf_API_Table[MEMIF_DEVEICE_FEE].SetMode(Mode);
#endif

#if( MEMIF_EA_ENABLE == STD_ON )
    MemIf_API_Table[MEMIF_DEVEICE_EA].SetMode(Mode);/* Set new mode to all devices. */
#endif
}

/*
********************************************************************************
* Function Name: MemIf_Read
*
* Explanation: Invokes the "Read" function of the underlying memory abstraction
*              module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Selection of memory abstraction modules.
*         BlockNumber: Number of logical block, also denoting start address of
*                      that block in EEPROM.
*         BlockOffset: Address offset inside the block.
*         *DataBufferPtr: Pointer to data buffer.
*         Length: Number of bytes to read.
*
* retval: E_OK: The underlying memory abstraction module accepts the requested task.
*         E_NOT_OK: The underlying memory abstraction module does not accept the
*                   requested tasks.
********************************************************************************
*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read
(
    uint8 DeviceIndex,
    uint16 BlockNumber,
    uint16 BlockOffset,
    /* polyspace +1 MISRA-C3:8.13 [Justified:Unset] "NSCA_Polyspace_Common_Rule8.13" */
    P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_MemIf_Dir4.5" */
    uint16 Length
)
{
    Std_ReturnType RtrnValu = E_NOT_OK;
    /* Check DeviceIndex within a reasonable range. */
    if( MEMIF_NUMBER_OF_DEVICES <= DeviceIndex )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_READ, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* Invokes the "Read" function. */
        RtrnValu = MemIf_API_Table[DeviceIndex].Read(BlockNumber, BlockOffset, DataBufferPtr, Length);
    }

    return RtrnValu;
}

/*
********************************************************************************
* Function Name: MemIf_Write
*
* Explanation: Invokes the "Write" function of the underlying memory abstraction
*              module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Module index.
*         BlockNumber: Number of logical block, also denoting start address of
*                      that block in flash memory.
*         *DataBufferPtr: Pointer to data buffer.
*
* retval: E_OK: The underlying memory abstraction module accepts the requested task.
*         E_NOT_OK: The underlying memory abstraction module does not accept the
*                   requested tasks.
********************************************************************************
*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write
(
    uint8 DeviceIndex,
    uint16 BlockNumber,
    P2CONST(uint8, AUTOMATIC, MEMIF_APPL_CONST) DataBufferPtr
)
{
    uint8 RtrnValu = E_NOT_OK;
    /* Check DeviceIndex within a reasonable range. */
    if( MEMIF_NUMBER_OF_DEVICES <= DeviceIndex )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_WRITE, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* Invokes the "Write" function. */
        RtrnValu = MemIf_API_Table[DeviceIndex].Write(BlockNumber, DataBufferPtr);
    }

    return RtrnValu;
}

/*
********************************************************************************
* Function Name: MemIf_Cancel
*
* Explanation: Invokes the "Cancel" function of the underlying memory abstraction
*              module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Module index.
*
* retval: void
********************************************************************************
*/
FUNC(void, MEMIF_CODE) MemIf_Cancel(uint8 DeviceIndex)
{
    /* Check DeviceIndex within a reasonable range. */
    if( MEMIF_NUMBER_OF_DEVICES <= DeviceIndex )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_CANCEL, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* Invokes the "Cancel" function. */
        MemIf_API_Table[DeviceIndex].Cancel();
    }
}

/*
********************************************************************************
* Function Name: MemIf_GetStatus
*
* Explanation: Invokes the "GetStatus" function of the underlying memory abstraction
*              module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Module index.
*
* retval: MEMIF_UNINIT: The underlying memory abstraction module has not been
*                        initialized.
*          MEMIF_IDLE: The underlying memory abstraction module is currently idle.
*          MEMIF_BUSY: The underlying memory abstraction module is currently busy.
*          MEMIF_BUSY_INTERNAL: The underlying memory abstraction module is busy
*                               with internal management operations.
********************************************************************************
*/
FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus(uint8 DeviceIndex)
{
    MemIf_StatusType RtrnValu = MEMIF_UNINIT;
    uint8 MemIf_StatusMask = MEMIF_MASK_INITIAL_VALUE;

    /* Check DeviceIndex within a reasonable range. */
    if( (MEMIF_NUMBER_OF_DEVICES <= DeviceIndex) && (MEMIF_BROADCAST_ID != DeviceIndex) )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_GET_STATUS, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* The function  is called with the DeviceIndex denoting a broadcast to all configured devices. */
        if( MEMIF_BROADCAST_ID == DeviceIndex )
        {
            /* Get status of all configured devices. */
#if( MEMIF_EA_ENABLE == STD_ON )
            /* Store each status to status mask. */
            MemIf_StatusMask |= (uint8)((uint8)STORE_EACH_STATUS << (uint8) MemIf_API_Table[MEMIF_DEVEICE_EA].GetStatus());
#endif

#if( MEMIF_FEE_ENABLE == STD_ON )
            /* Store each status to status mask. */
            MemIf_StatusMask |= (uint8)((uint8)STORE_EACH_STATUS << (uint8) MemIf_API_Table[MEMIF_DEVEICE_FEE].GetStatus());
#endif
            /* Check if UNINIT-bit is set. */
            if( E_OK == MemIf_IsBitSet(MemIf_StatusMask, MEMIF_UNINIT) )
            {
                RtrnValu = MEMIF_UNINIT;
            }
            /* Check if BUSY-bit is set. */
            else if( E_OK == MemIf_IsBitSet(MemIf_StatusMask, MEMIF_BUSY) )
            {
                RtrnValu = MEMIF_BUSY;
            }
            /* Check if BUSY_INTERNAL-bit is set. */
            else if( E_OK == MemIf_IsBitSet(MemIf_StatusMask, MEMIF_BUSY_INTERNAL) )
            {
                RtrnValu = MEMIF_BUSY_INTERNAL;
            }
            else
            {
                /* All MemHwA modules are MEMIF_IDLE. */
                RtrnValu = MEMIF_IDLE;
            }
        }
        else
        {
            RtrnValu = MemIf_API_Table[DeviceIndex].GetStatus();    /* Invokes the "GetStatus" function. */
        }
    }

    return RtrnValu;
}

/*
********************************************************************************
* Function Name: MemIf_GetJobResult
*
* Explanation: Invokes the "GetJobResult" function of the underlying memory
*              abstraction module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Module index.
*
* retval: MEMIF_JOB_OK: The last job has been finished successfully.
*          MEMIF_JOB_PENDING: The last job is waiting for execution or currently
*                             being executed.
*          MEMIF_JOB_CANCELED: The last job has been canceled(which means it failed).
*          MEMIF_JOB_FAILED: The last job has not been finished successfully (it failed).
*          MEMIF_BLOCK_INCONSISTENT: The requested block is inconsistent, it may
*                                    contain corrupted data.
*          MEMIF_BLOCK_INVALID: The requested block has been invalidated, the
*                               requested read operation can not beperformed.
********************************************************************************
*/
FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult(uint8 DeviceIndex)
{
    MemIf_JobResultType RtrnValu = MEMIF_JOB_FAILED;
    /* Check DeviceIndex within a reasonable range. */
    if( MEMIF_NUMBER_OF_DEVICES <= DeviceIndex )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_GET_JOB_RESULT, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* Invokes the "GetJobResult" function. */
        RtrnValu = MemIf_API_Table[DeviceIndex].GetJobResult();
    }

    return RtrnValu;
}

/*
********************************************************************************
* Function Name: MemIf_InvalidateBlock
*
* Explanation: Invokes the "InvalidateBlock" function of the underlying memory
*              abstraction module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Module index.
*         BlockNumber: Number of logical block, also denoting start address of
*                      that block in flash memory.
*
* retval: E_OK: The requested job has been accepted by the underlying memory
*                abstraction module.
*          E_NOT_OK: Only if DET is enabled: The requested job has not been
*                    accepted by the underlying memory abstraction module.
********************************************************************************
*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock
(
    uint8 DeviceIndex,
    uint16 BlockNumber
)
{
    uint8 RtrnValu = E_NOT_OK;

    /* Check DeviceIndex within a reasonable range. */
    if( MEMIF_NUMBER_OF_DEVICES <= DeviceIndex )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_INVALIDATE_BLOCK, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* Invokes the "InvalidateBlock" function. */
        RtrnValu = MemIf_API_Table[DeviceIndex].InvalidateBlock(BlockNumber);
    }



    return RtrnValu;
}

/*
********************************************************************************
* Function Name: MemIf_EraseImmediateBlock
*
* Explanation: Invokes the "EraseImmediateBlock" function of the underlying memory
*              abstraction module selected by the parameter DeviceIndex.(Synchronous)
*
* param: DeviceIndex: Module index.
*         BlockNumber: Number of logical block, also denoting start address of
*                      that block in flash memory.
*
* retval: E_OK: The requested job has been accepted by the underlying memory
*                abstraction module.
*          E_NOT_OK: only if DET is enabled: The requested job has not been
*                    accepted by theunderlying memory abstraction module.
********************************************************************************
*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock
(
    uint8 DeviceIndex,
    uint16 BlockNumber
)
{
    uint8 RtrnValu = E_NOT_OK;

    /* Check DeviceIndex within a reasonable range. */
    if( MEMIF_NUMBER_OF_DEVICES <= DeviceIndex )
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_ERASE_IMMEDIATE_BLOCK, MEMIF_E_PARAM_DEVICE);
#endif

    }
    else
    {
        /* Invokes the "EraseImmediateBlock" function. */
        RtrnValu = MemIf_API_Table[DeviceIndex].EraseImmediateBlock(BlockNumber);
    }

    return RtrnValu;
}

#if (MEMIF_VERSION_INFO_API == STD_ON)
/*
********************************************************************************
* Function Name: MemIf_GetVersionInfo
*
* Explanation: Returns version information.(Synchronous)
*
* param: VersionInfoPtr:Pointer to standard version information structure.
*
* retval: void
********************************************************************************
*/
FUNC(void, MEMIF_CODE) MemIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MEMIF_APPL_DATA) VersionInfoPtr
)
{
    /* Check parameter is null pointer. */
    if( NULL_PTR == VersionInfoPtr )
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {

#if ( MEMIF_DEV_ERROR_DETECT == STD_ON )
        /* Report ErrorId to Det. */
        MemIf_Det_ErrorReport(MEMIF_GET_VERSION_INFO, MEMIF_E_PARAM_POINTER);
#endif

    }
    else
    {
        /* MemIf Version. */
        /* Polyspace +1 MISRA-C3:D4.14 [Justified:Unset] " NSCA_Polyspace_MemIf_Dir4.14 " polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_MemIf_TAINTED_PTR" */
        VersionInfoPtr->vendorID = MEMIF_VENDOR_ID;
        VersionInfoPtr->moduleID = MEMIF_MODULE_ID;
        VersionInfoPtr->sw_major_version = MEMIF_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = MEMIF_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = MEMIF_SW_PATCH_VERSION;
    }
}
#endif

#define MEMIF_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "MemIf_MemMap.h" /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
