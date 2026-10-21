 
/*
********************************************************************************
*
*  File name: EmTq_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef EmTq_START_SEC_CALIB_BOOLEAN
#undef EmTq_START_SEC_CALIB_BOOLEAN
#define EMTQ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef EmTq_STOP_SEC_CALIB_BOOLEAN
#undef EmTq_STOP_SEC_CALIB_BOOLEAN
#define EMTQ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef EmTq_START_SEC_CALIB_8
#undef EmTq_START_SEC_CALIB_8
#define EMTQ_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef EmTq_STOP_SEC_CALIB_8
#undef EmTq_STOP_SEC_CALIB_8
#define EMTQ_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef EmTq_START_SEC_CALIB_16
#undef EmTq_START_SEC_CALIB_16
#define EMTQ_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef EmTq_STOP_SEC_CALIB_16
#undef EmTq_STOP_SEC_CALIB_16
#define EMTQ_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef EmTq_START_SEC_CALIB_32
#undef EmTq_START_SEC_CALIB_32
#define EMTQ_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef EmTq_STOP_SEC_CALIB_32
#undef EmTq_STOP_SEC_CALIB_32
#define EMTQ_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef EmTq_START_SEC_CALIB_UNSPECIFIED
#undef EmTq_START_SEC_CALIB_UNSPECIFIED
#define EMTQ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef EmTq_STOP_SEC_CALIB_UNSPECIFIED
#undef EmTq_STOP_SEC_CALIB_UNSPECIFIED
#define EMTQ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef EmTq_START_SEC_VAR_BOOLEAN
#undef EmTq_START_SEC_VAR_BOOLEAN
#define EMTQ_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef EmTq_STOP_SEC_VAR_BOOLEAN
#undef EmTq_STOP_SEC_VAR_BOOLEAN
#define EMTQ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef EmTq_START_SEC_VAR_8
#undef EmTq_START_SEC_VAR_8
#define EMTQ_START_SEC_VAR_NO_INIT_8
#endif
#ifdef EmTq_STOP_SEC_VAR_8
#undef EmTq_STOP_SEC_VAR_8
#define EMTQ_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef EmTq_START_SEC_VAR_16
#undef EmTq_START_SEC_VAR_16
#define EMTQ_START_SEC_VAR_NO_INIT_16
#endif
#ifdef EmTq_STOP_SEC_VAR_16
#undef EmTq_STOP_SEC_VAR_16
#define EMTQ_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef EmTq_START_SEC_VAR_32
#undef EmTq_START_SEC_VAR_32
#define EMTQ_START_SEC_VAR_NO_INIT_32
#endif
#ifdef EmTq_STOP_SEC_VAR_32
#undef EmTq_STOP_SEC_VAR_32
#define EMTQ_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef EmTq_START_SEC_VAR_UNSPECIFIED
#undef EmTq_START_SEC_VAR_UNSPECIFIED
#define EMTQ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef EmTq_STOP_SEC_VAR_UNSPECIFIED
#undef EmTq_STOP_SEC_VAR_UNSPECIFIED
#define EMTQ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef EmTq_START_SEC_CODE
#undef EmTq_START_SEC_CODE
#define EMTQ_START_SEC_CODE
#endif
#ifdef EmTq_STOP_SEC_CODE
#undef EmTq_STOP_SEC_CODE
#define EMTQ_STOP_SEC_CODE
#endif

#ifdef EmTq_START_SEC_CODE_fc_EmTq
#undef EmTq_START_SEC_CODE_fc_EmTq
#define EMTQ_START_SEC_CODE
#endif
#ifdef EmTq_STOP_SEC_CODE_fc_EmTq
#undef EmTq_STOP_SEC_CODE_fc_EmTq
#define EMTQ_STOP_SEC_CODE
#endif

#ifdef EmTq_START_SEC_CODE_EmTq_Init
#undef EmTq_START_SEC_CODE_EmTq_Init
#define EMTQ_START_SEC_CODE
#endif
#ifdef EmTq_STOP_SEC_CODE_EmTq_Init
#undef EmTq_STOP_SEC_CODE_EmTq_Init
#define EMTQ_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef EMTQ_START_SEC_CODE
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef EMTQ_START_SEC_CODE
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CODE
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CODE
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMTQ_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CALIBRATION_ONLINE_8
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMTQ_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CALIBRATION_ONLINE_16
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMTQ_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CALIBRATION_ONLINE_32
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMTQ_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EMTQ_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CONST_BOOLEAN
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMTQ_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CONST_BOOLEAN
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CONST_8
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMTQ_START_SEC_CONST_8
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CONST_8
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CONST_16
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMTQ_START_SEC_CONST_16
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CONST_16
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CONST_32
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EMTQ_START_SEC_CONST_32
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CONST_32
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_CONST_UNSPECIFIED
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef EMTQ_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_CONST_UNSPECIFIED
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMTQ_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_NO_INIT_8
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMTQ_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_NO_INIT_8
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_NO_INIT_16
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMTQ_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_NO_INIT_16
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_NO_INIT_32
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMTQ_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_NO_INIT_32
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EMTQ_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_INIT_BOOLEAN
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMTQ_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_INIT_8
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMTQ_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_INIT_8
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_INIT_16
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMTQ_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_INIT_16
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_INIT_32
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMTQ_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_INIT_32
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EMTQ_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_INIT_8
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_INIT_16
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_INIT_32
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EMTQ
#endif
#ifdef EMTQ_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef EMTQ_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EMTQ_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

#ifdef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef EMTQ_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EMTQ_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EMTQ_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EMTQ
#endif

 
 
 
