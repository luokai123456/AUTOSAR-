 
/*
********************************************************************************
*
*  File name: IdqAct_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef IdqAct_START_SEC_CALIB_BOOLEAN
#undef IdqAct_START_SEC_CALIB_BOOLEAN
#define IDQACT_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef IdqAct_STOP_SEC_CALIB_BOOLEAN
#undef IdqAct_STOP_SEC_CALIB_BOOLEAN
#define IDQACT_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef IdqAct_START_SEC_CALIB_8
#undef IdqAct_START_SEC_CALIB_8
#define IDQACT_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef IdqAct_STOP_SEC_CALIB_8
#undef IdqAct_STOP_SEC_CALIB_8
#define IDQACT_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef IdqAct_START_SEC_CALIB_16
#undef IdqAct_START_SEC_CALIB_16
#define IDQACT_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef IdqAct_STOP_SEC_CALIB_16
#undef IdqAct_STOP_SEC_CALIB_16
#define IDQACT_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef IdqAct_START_SEC_CALIB_32
#undef IdqAct_START_SEC_CALIB_32
#define IDQACT_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef IdqAct_STOP_SEC_CALIB_32
#undef IdqAct_STOP_SEC_CALIB_32
#define IDQACT_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef IdqAct_START_SEC_CALIB_UNSPECIFIED
#undef IdqAct_START_SEC_CALIB_UNSPECIFIED
#define IDQACT_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef IdqAct_STOP_SEC_CALIB_UNSPECIFIED
#undef IdqAct_STOP_SEC_CALIB_UNSPECIFIED
#define IDQACT_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef IdqAct_START_SEC_VAR_BOOLEAN
#undef IdqAct_START_SEC_VAR_BOOLEAN
#define IDQACT_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef IdqAct_STOP_SEC_VAR_BOOLEAN
#undef IdqAct_STOP_SEC_VAR_BOOLEAN
#define IDQACT_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef IdqAct_START_SEC_VAR_8
#undef IdqAct_START_SEC_VAR_8
#define IDQACT_START_SEC_VAR_NO_INIT_8
#endif
#ifdef IdqAct_STOP_SEC_VAR_8
#undef IdqAct_STOP_SEC_VAR_8
#define IDQACT_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef IdqAct_START_SEC_VAR_16
#undef IdqAct_START_SEC_VAR_16
#define IDQACT_START_SEC_VAR_NO_INIT_16
#endif
#ifdef IdqAct_STOP_SEC_VAR_16
#undef IdqAct_STOP_SEC_VAR_16
#define IDQACT_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef IdqAct_START_SEC_VAR_32
#undef IdqAct_START_SEC_VAR_32
#define IDQACT_START_SEC_VAR_NO_INIT_32
#endif
#ifdef IdqAct_STOP_SEC_VAR_32
#undef IdqAct_STOP_SEC_VAR_32
#define IDQACT_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef IdqAct_START_SEC_VAR_UNSPECIFIED
#undef IdqAct_START_SEC_VAR_UNSPECIFIED
#define IDQACT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef IdqAct_STOP_SEC_VAR_UNSPECIFIED
#undef IdqAct_STOP_SEC_VAR_UNSPECIFIED
#define IDQACT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef IdqAct_START_SEC_CODE
#undef IdqAct_START_SEC_CODE
#define IDQACT_START_SEC_CODE
#endif
#ifdef IdqAct_STOP_SEC_CODE
#undef IdqAct_STOP_SEC_CODE
#define IDQACT_STOP_SEC_CODE
#endif

#ifdef IdqAct_START_SEC_CODE_fc_IdqAct
#undef IdqAct_START_SEC_CODE_fc_IdqAct
#define IDQACT_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef IdqAct_STOP_SEC_CODE_fc_IdqAct
#undef IdqAct_STOP_SEC_CODE_fc_IdqAct
#define IDQACT_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef IdqAct_START_SEC_CODE_IdqAct_Init
#undef IdqAct_START_SEC_CODE_IdqAct_Init
#define IDQACT_START_SEC_CODE
#endif
#ifdef IdqAct_STOP_SEC_CODE_IdqAct_Init
#undef IdqAct_STOP_SEC_CODE_IdqAct_Init
#define IDQACT_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef IDQACT_START_SEC_CODE
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef IDQACT_START_SEC_CODE
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CODE
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CODE
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CODE_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef IDQACT_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CODE_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQACT_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CALIBRATION_ONLINE_8
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQACT_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CALIBRATION_ONLINE_16
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQACT_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CALIBRATION_ONLINE_32
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQACT_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef IDQACT_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CONST_BOOLEAN
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQACT_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CONST_BOOLEAN
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CONST_8
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQACT_START_SEC_CONST_8
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CONST_8
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CONST_16
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQACT_START_SEC_CONST_16
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CONST_16
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CONST_32
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef IDQACT_START_SEC_CONST_32
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CONST_32
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_CONST_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef IDQACT_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_CONST_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQACT_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_NO_INIT_8
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQACT_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_NO_INIT_8
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_NO_INIT_16
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQACT_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_NO_INIT_16
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_NO_INIT_32
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQACT_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_NO_INIT_32
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef IDQACT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_INIT_BOOLEAN
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQACT_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_INIT_8
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQACT_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_INIT_8
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_INIT_16
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQACT_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_INIT_16
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_INIT_32
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQACT_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_INIT_32
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef IDQACT_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_INIT_8
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_INIT_16
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_INIT_32
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_IDQACT
#endif
#ifdef IDQACT_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef IDQACT_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef IDQACT_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

#ifdef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef IDQACT_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef IDQACT_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef IDQACT_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_IDQACT
#endif

 
 
 
