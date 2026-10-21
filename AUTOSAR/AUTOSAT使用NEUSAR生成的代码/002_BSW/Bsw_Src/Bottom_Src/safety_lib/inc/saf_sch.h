/**
****************************************************************************************
 * @FilePath: saf_sch.h
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Schedule Header File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_SCH_H
#define SAF_SCH_H

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "SafetyTestHnd_Cfg.h"
#include "saf_common.h"

/**
****************************************************************************************
 * @brief: Type Define
****************************************************************************************
*/
typedef FS_STATUS (* saf_safety_test_func)(void);/*PRQA S 1336*/

/**
****************************************************************************************
 * @brief: Structs
****************************************************************************************
*/
/**
* @brief  Prestartup test object struct type.
*/
typedef struct
{
	/**
    * @brief Prestartup test function pointer
    */
	saf_safety_test_func test_func;
} saf_sch_prestartup_object_t;

/**
* @brief  Startup test object struct type.
*/
typedef struct
{
	/**
    * @brief Startup test function pointer
    */
	saf_safety_test_func test_func;
} saf_sch_startup_object_t;

/**
* @brief  Runtime test object struct type.
*/
typedef struct
{
	/**
    * @brief Runtime test function pointer
    */
	saf_safety_test_func test_func;
} saf_sch_runtime_object_t;

/**
* @brief   Prestartup test result struct type.
*/
typedef struct
{
	/**
	* @brief   Prestartup test error status.
	*/
	FS_STATUS ErrStatus[SAFETYTESTHND_TOTAL_PRESTARTUP_TESTS];
} saf_sch_prestartup_err_t;

/**
* @brief   Startup1 test result struct type.
*/
typedef struct
{
	/**
	* @brief   Startup1 test error status.
	*/
	FS_STATUS ErrStatus[SAFETYTESTHND_TOTAL_STARTUP_TESTS];
} saf_sch_startup_err_t;

/**
* @brief   Runtime test result struct type.
*/
typedef struct
{
	/**
	* @brief   Runtime test error status.
	*/
	FS_STATUS ErrStatus[SAFETYTESTHND_TOTAL_RUNTIME_TESTS];
} saf_sch_runtime_err_t;

/**
* @brief   Safey test result struct type.
*/
typedef struct
{
	/**
	* @brief   Prestartup test error status.
	*/
	FS_STATUS prestartupTestErrStatus[SAFETYTESTHND_TOTAL_PRESTARTUP_TESTS];
	/**
	* @brief   Startup test error status.
	*/
	FS_STATUS startupTestErrStatus[SAFETYTESTHND_TOTAL_STARTUP_TESTS];
	/**
	* @brief   Runtime test error status.
	*/
	FS_STATUS runtimeTestErrStatus[SAFETYTESTHND_TOTAL_RUNTIME_TESTS];
} saf_sch_err_container_type_t;

/**
* @brief  Prestartup test struct type.
*/
typedef struct
{
	/**
	* @brief  Prestartup test has benn initalized or not.
	*/
	bool prestartupTestInitialized;
	/**
	* @brief  Prestartup test hander list pointer.
	*/
	saf_sch_prestartup_object_t *pPrestartupTestHandlerList[SAFETYTESTHND_TOTAL_PRESTARTUP_TESTS];
	/**
	* @brief  Prestartup test result pointer.
	*/
	saf_sch_prestartup_err_t *pPrestartupTestErrStatus;
} saf_sch_prestartup_t;

/**
* @brief  Startup test struct type.
*/
typedef struct
{
	/**
	* @brief  Startup test has benn initalized or not.
	*/
	bool startupTestInitialized;
	/**
	* @brief  Startup test hander list pointer.
	*/
	saf_sch_startup_object_t *pStartupTestHandlerList[SAFETYTESTHND_TOTAL_STARTUP_TESTS];
	/**
	* @brief  Startup test result pointer.
	*/
	saf_sch_startup_err_t *pstartupTestErrStatus;
} saf_sch_startup_t;

/**
* @brief  Runtime test struct type.
*/
typedef struct
{
	/**
	* @brief  Runtime test has benn initalized or not.
	*/
	saf_sch_runtime_object_t *pRuntimeTestHandlerList[SAFETYTESTHND_TOTAL_RUNTIME_TESTS];
	/**
	* @brief  Runtime test result pointer.
	*/
	saf_sch_runtime_err_t *pruntimeTestErrStatus;
} saf_sch_runtime_t;


/**
****************************************************************************************
 * @brief: Function prototypes
****************************************************************************************
*/

#if defined (__cplusplus)
extern "C" {
#endif
FS_STATUS SAF_SCH_PrestartupErrReportResult(saf_sch_prestartup_err_t *TestResult);

FS_STATUS SAF_SCH_StartupErrReportResult(saf_sch_startup_err_t *TestResult);

FS_STATUS SAF_SCH_RuntimeErrReportResult(saf_sch_runtime_err_t *TestResult);

void SAF_SCH_PrestartupTest(void);

void SAF_SCH_StartupTest(void);

void SAF_SCH_RuntimeTest(void);


#if defined (__cplusplus)
}
#endif

#endif/* FS_MANAGER_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
