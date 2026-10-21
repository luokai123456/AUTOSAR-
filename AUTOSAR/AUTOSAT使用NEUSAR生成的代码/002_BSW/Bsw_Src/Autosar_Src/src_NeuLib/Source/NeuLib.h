/*
********************************************************************************
*
* File name: NeuLib.h
*
* Copyright 2023-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: ZhangDX/2023.08.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: ChenQJ/2023.08.01
* Change: Update version to 3.8.0.1.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: KangJH/2024.08.07
* Change: 1.Add NeuLib_memcpy32 function declaration.
*         2.Update version to 3.11.0.2.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: TianG/2024.10.12
* Change: 1.Add a memory-map label to function.
*         2.Modify copyright.
*         3.Update version to 3.11.0.3.
*         4.Modify FUNC_P2VAR error.
* Cause: Bugfix
********************************************************************************
* Version: 3.4
* Author/Date: KangJH/2025.02.08
* Change: 1.Fix compile warning.
*         2.Update software version to 3.13.0.04.
* Cause: Optimization
********************************************************************************
* Version: 3.5
* Author/Date: KangJH/2025.03.26
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: KangJH/2025.05.22
* Change: 1.Fix the polyspace warning and add the polyspace deviation suppression
*         comment.
*         2.Update software version to 3.14.0.05.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: KangJH/2025.06.17
* Change: Update software version to 3.14.0.06.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: KangJH/2025.06.23
* Change: 1.Add the polyspace deviation suppression comment.
*         2.Update software version to 3.14.0.07.
* Cause: Update
********************************************************************************

*/
#ifndef NEULIB_H_
#define NEULIB_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "NeuLib_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* AUTOSAR Version. */
#define NEULIB_AR_RELEASE_MAJOR_VERSION         (4U)
#define NEULIB_AR_RELEASE_MINOR_VERSION         (4U)
#define NEULIB_AR_RELEASE_REVISION_VERSION      (0U)

/* Vendor and module identification */
#define NEULIB_VENDOR_ID                        (119U)
#define NEULIB_MODULE_ID                        (170U)

/* Component version information (decimal version of ALM implementation package) */
#define NEULIB_SW_MAJOR_VERSION                 (3U)
#define NEULIB_SW_MINOR_VERSION                 (14U)
#define NEULIB_SW_PATCH_VERSION                 (0U)
#define NEULIB_SW_REVISION_VERSION              (7U)

/* API service IDs */
#define NEULIB_SID_MEM_SET                      (0x00U)    /*!< Service ID: NeuLib_MemClr(), NeuLib_memset(). */
#define NEULIB_SID_MEM_COPY                     (0x01U)    /*!< Service ID: NeuLib_memcpy().                  */
#define NEULIB_SID_MEM_CMP                      (0x04U)    /*!< Service ID: NeuLib_memcmp().                  */
#define NEULIB_SID_MEM_MOVE                     (0x05U)    /*!< Service ID: NeuLib_memmove().                 */
#define NEULIB_SID_STR_LEN                      (0x06U)    /*!< Service ID: NeuLib_strlen().                  */
#define NEULIB_SID_STR_NCMP                     (0x07U)    /*!< Service ID: NeuLib_strncmp().                 */

/* Error codes */
#define NEULIB_E_NO_ERROR                       (0x00U)    /*!< Used to check if no error occurred.                             */
#define NEULIB_E_PARAM_POINTER                  (0x01U)    /*!< Error code: API used with invalid pointer parameter (NULL_PTR). */
#define NEULIB_E_PARAM_SIZE                     (0x02U)    /*!< Error code: NeuLib_MemCpy_s() used with invalid dst size.       */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

#if (NEULIB_DEV_ERROR_DETECT == STD_ON)
/* Det_ReportError calls the mapping. */
#define NEULIB_DET_REPORT_ERROR(_api, _errorId)                                             \
        do                                                                                  \
        {                                                                                   \
            (void)Det_ReportError(NEULIB_MODULE_ID, NEULIB_VENDOR_ID, (_api), (_errorId));  \
        } while (0U)

/* Development Error Tracer */
#define NeuLib_CheckDetReturnVoid(_assertion, _api, _errId)     \
    do                                                          \
    {                                                           \
        if (!(_assertion))                                      \
        {                                                       \
            NEULIB_DET_REPORT_ERROR((_api), (_errId));          \
            return;                                             \
        }                                                       \
    } while (0U)

#define NeuLib_CheckDetReturnValue(_assertion, _api, _errId, _ret)  \
    do                                                              \
    {                                                               \
        if (!(_assertion))                                          \
        {                                                           \
            NEULIB_DET_REPORT_ERROR((_api), (_errId));              \
            return (_ret);                                          \
        }                                                           \
    } while (0U)
#else   /* (NEULIB_DEV_ERROR_DETECT == STD_ON) */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NEULIB_DET_REPORT_ERROR(_api, _errorId)
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NeuLib_CheckDetReturnVoid(_assertion, _api, _errId)
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NeuLib_CheckDetReturnValue(_assertion, _api, _errId, _ret)
#endif  /* (NEULIB_DEV_ERROR_DETECT == STD_ON) */

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define NeuLib_memclr(_dst, _cnt)           NeuLib_memset((_dst), 0u, (_cnt))

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"
FUNC(void, NEULIB_CODE) NeuLib_memcpy(
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    CONST(uint32, NEULIB_CONST) size
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(void, NEULIB_CODE) NeuLib_memcpy32(
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    CONST(uint32, NEULIB_CONST) size
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(void, NEULIB_CODE) NeuLib_memset(
    volatile P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr,
    uint8 value,
    CONST(uint32, NEULIB_CONST) len
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(boolean, NEULIB_CODE) NeuLib_memcmp(
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) dstPtr,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr,
    uint32 count
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC_P2VAR(void, NEULIB_APPL_DATA, NEULIB_CODE) NeuLib_memmove(
    P2VAR(void, AUTOMATIC, NEULIB_APPL_DATA) dstPtr ,
    P2CONST(void, AUTOMATIC, NEULIB_APPL_CONST) srcPtr ,
    uint32 count
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(uint32, NEULIB_CODE) NeuLib_strlen(
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(sint8, NEULIB_CODE) NeuLib_strcmp(
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str1,
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str2
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
FUNC(sint8, NEULIB_CODE) NeuLib_strncmp(
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str1,
    P2CONST(char, AUTOMATIC, NEULIB_APPL_CONST) str2,
    uint32 cnt
);  /* PRQA S 0777 */ /* NSCA_QAC_Common_IdentifierLength */
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define NEULIB_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "NeuLib_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif  /* #ifndef NEULIB_H_ */
