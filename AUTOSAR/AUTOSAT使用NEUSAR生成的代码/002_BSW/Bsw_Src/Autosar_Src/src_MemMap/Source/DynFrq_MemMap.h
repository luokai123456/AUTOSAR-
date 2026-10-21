 
/*
********************************************************************************
*
*  File name: DynFrq_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef DynFrq_START_SEC_CALIB_BOOLEAN
#undef DynFrq_START_SEC_CALIB_BOOLEAN
#define DYNFRQ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef DynFrq_STOP_SEC_CALIB_BOOLEAN
#undef DynFrq_STOP_SEC_CALIB_BOOLEAN
#define DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef DynFrq_START_SEC_CALIB_8
#undef DynFrq_START_SEC_CALIB_8
#define DYNFRQ_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef DynFrq_STOP_SEC_CALIB_8
#undef DynFrq_STOP_SEC_CALIB_8
#define DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef DynFrq_START_SEC_CALIB_16
#undef DynFrq_START_SEC_CALIB_16
#define DYNFRQ_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef DynFrq_STOP_SEC_CALIB_16
#undef DynFrq_STOP_SEC_CALIB_16
#define DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef DynFrq_START_SEC_CALIB_32
#undef DynFrq_START_SEC_CALIB_32
#define DYNFRQ_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef DynFrq_STOP_SEC_CALIB_32
#undef DynFrq_STOP_SEC_CALIB_32
#define DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef DynFrq_START_SEC_CALIB_UNSPECIFIED
#undef DynFrq_START_SEC_CALIB_UNSPECIFIED
#define DYNFRQ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef DynFrq_STOP_SEC_CALIB_UNSPECIFIED
#undef DynFrq_STOP_SEC_CALIB_UNSPECIFIED
#define DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef DynFrq_START_SEC_VAR_BOOLEAN
#undef DynFrq_START_SEC_VAR_BOOLEAN
#define DYNFRQ_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef DynFrq_STOP_SEC_VAR_BOOLEAN
#undef DynFrq_STOP_SEC_VAR_BOOLEAN
#define DYNFRQ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef DynFrq_START_SEC_VAR_8
#undef DynFrq_START_SEC_VAR_8
#define DYNFRQ_START_SEC_VAR_NO_INIT_8
#endif
#ifdef DynFrq_STOP_SEC_VAR_8
#undef DynFrq_STOP_SEC_VAR_8
#define DYNFRQ_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef DynFrq_START_SEC_VAR_16
#undef DynFrq_START_SEC_VAR_16
#define DYNFRQ_START_SEC_VAR_NO_INIT_16
#endif
#ifdef DynFrq_STOP_SEC_VAR_16
#undef DynFrq_STOP_SEC_VAR_16
#define DYNFRQ_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef DynFrq_START_SEC_VAR_32
#undef DynFrq_START_SEC_VAR_32
#define DYNFRQ_START_SEC_VAR_NO_INIT_32
#endif
#ifdef DynFrq_STOP_SEC_VAR_32
#undef DynFrq_STOP_SEC_VAR_32
#define DYNFRQ_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef DynFrq_START_SEC_VAR_UNSPECIFIED
#undef DynFrq_START_SEC_VAR_UNSPECIFIED
#define DYNFRQ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef DynFrq_STOP_SEC_VAR_UNSPECIFIED
#undef DynFrq_STOP_SEC_VAR_UNSPECIFIED
#define DYNFRQ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef DynFrq_START_SEC_CODE
#undef DynFrq_START_SEC_CODE
#define DYNFRQ_START_SEC_CODE
#endif
#ifdef DynFrq_STOP_SEC_CODE
#undef DynFrq_STOP_SEC_CODE
#define DYNFRQ_STOP_SEC_CODE
#endif

#ifdef DynFrq_START_SEC_CODE_fc_DynFrq
#undef DynFrq_START_SEC_CODE_fc_DynFrq
#define DYNFRQ_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef DynFrq_STOP_SEC_CODE_fc_DynFrq
#undef DynFrq_STOP_SEC_CODE_fc_DynFrq
#define DYNFRQ_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef DynFrq_START_SEC_CODE_DynFrq_Init
#undef DynFrq_START_SEC_CODE_DynFrq_Init
#define DYNFRQ_START_SEC_CODE
#endif
#ifdef DynFrq_STOP_SEC_CODE_DynFrq_Init
#undef DynFrq_STOP_SEC_CODE_DynFrq_Init
#define DYNFRQ_STOP_SEC_CODE
#endif

/*** ASW End ***/

#ifdef DYNFRQ_START_SEC_CODE
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DYNFRQ_START_SEC_CODE
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CODE
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CODE
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CODE_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef DYNFRQ_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CODE_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DYNFRQ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CALIBRATION_ONLINE_8
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DYNFRQ_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CALIBRATION_ONLINE_16
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DYNFRQ_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CALIBRATION_ONLINE_32
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DYNFRQ_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DYNFRQ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CONST_BOOLEAN
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DYNFRQ_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CONST_BOOLEAN
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CONST_8
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DYNFRQ_START_SEC_CONST_8
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CONST_8
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CONST_16
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DYNFRQ_START_SEC_CONST_16
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CONST_16
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CONST_32
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DYNFRQ_START_SEC_CONST_32
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CONST_32
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_CONST_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DYNFRQ_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_CONST_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DYNFRQ_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_NO_INIT_8
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DYNFRQ_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_NO_INIT_8
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_NO_INIT_16
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DYNFRQ_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_NO_INIT_16
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_NO_INIT_32
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DYNFRQ_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_NO_INIT_32
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DYNFRQ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_INIT_BOOLEAN
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DYNFRQ_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_INIT_8
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DYNFRQ_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_INIT_8
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_INIT_16
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DYNFRQ_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_INIT_16
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_INIT_32
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DYNFRQ_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_INIT_32
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DYNFRQ_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DYNFRQ
#endif
#ifdef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DYNFRQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DYNFRQ_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

#ifdef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DYNFRQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DYNFRQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DYNFRQ_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DYNFRQ
#endif

 
 
 
