 
/*
********************************************************************************
*
*  File name: DernSys_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef DernSys_START_SEC_CALIB_BOOLEAN
#undef DernSys_START_SEC_CALIB_BOOLEAN
#define DERNSYS_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef DernSys_STOP_SEC_CALIB_BOOLEAN
#undef DernSys_STOP_SEC_CALIB_BOOLEAN
#define DERNSYS_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef DernSys_START_SEC_CALIB_8
#undef DernSys_START_SEC_CALIB_8
#define DERNSYS_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef DernSys_STOP_SEC_CALIB_8
#undef DernSys_STOP_SEC_CALIB_8
#define DERNSYS_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef DernSys_START_SEC_CALIB_16
#undef DernSys_START_SEC_CALIB_16
#define DERNSYS_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef DernSys_STOP_SEC_CALIB_16
#undef DernSys_STOP_SEC_CALIB_16
#define DERNSYS_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef DernSys_START_SEC_CALIB_32
#undef DernSys_START_SEC_CALIB_32
#define DERNSYS_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef DernSys_STOP_SEC_CALIB_32
#undef DernSys_STOP_SEC_CALIB_32
#define DERNSYS_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef DernSys_START_SEC_CALIB_UNSPECIFIED
#undef DernSys_START_SEC_CALIB_UNSPECIFIED
#define DERNSYS_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef DernSys_STOP_SEC_CALIB_UNSPECIFIED
#undef DernSys_STOP_SEC_CALIB_UNSPECIFIED
#define DERNSYS_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef DernSys_START_SEC_VAR_BOOLEAN
#undef DernSys_START_SEC_VAR_BOOLEAN
#define DERNSYS_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef DernSys_STOP_SEC_VAR_BOOLEAN
#undef DernSys_STOP_SEC_VAR_BOOLEAN
#define DERNSYS_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef DernSys_START_SEC_VAR_8
#undef DernSys_START_SEC_VAR_8
#define DERNSYS_START_SEC_VAR_NO_INIT_8
#endif
#ifdef DernSys_STOP_SEC_VAR_8
#undef DernSys_STOP_SEC_VAR_8
#define DERNSYS_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef DernSys_START_SEC_VAR_16
#undef DernSys_START_SEC_VAR_16
#define DERNSYS_START_SEC_VAR_NO_INIT_16
#endif
#ifdef DernSys_STOP_SEC_VAR_16
#undef DernSys_STOP_SEC_VAR_16
#define DERNSYS_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef DernSys_START_SEC_VAR_32
#undef DernSys_START_SEC_VAR_32
#define DERNSYS_START_SEC_VAR_NO_INIT_32
#endif
#ifdef DernSys_STOP_SEC_VAR_32
#undef DernSys_STOP_SEC_VAR_32
#define DERNSYS_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef DernSys_START_SEC_VAR_UNSPECIFIED
#undef DernSys_START_SEC_VAR_UNSPECIFIED
#define DERNSYS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef DernSys_STOP_SEC_VAR_UNSPECIFIED
#undef DernSys_STOP_SEC_VAR_UNSPECIFIED
#define DERNSYS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef DernSys_START_SEC_CODE
#undef DernSys_START_SEC_CODE
#define DERNSYS_START_SEC_CODE
#endif
#ifdef DernSys_STOP_SEC_CODE
#undef DernSys_STOP_SEC_CODE
#define DERNSYS_STOP_SEC_CODE
#endif

#ifdef DernSys_START_SEC_CODE_fc_DernSys
#undef DernSys_START_SEC_CODE_fc_DernSys
#define DERNSYS_START_SEC_CODE
#endif
#ifdef DernSys_STOP_SEC_CODE_fc_DernSys
#undef DernSys_STOP_SEC_CODE_fc_DernSys
#define DERNSYS_STOP_SEC_CODE
#endif

#ifdef DernSys_START_SEC_CODE_DernSys_Init
#undef DernSys_START_SEC_CODE_DernSys_Init
#define DERNSYS_START_SEC_CODE
#endif
#ifdef DernSys_STOP_SEC_CODE_DernSys_Init
#undef DernSys_STOP_SEC_CODE_DernSys_Init
#define DERNSYS_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef DERNSYS_START_SEC_CODE
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DERNSYS_START_SEC_CODE
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CODE
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CODE
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNSYS_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CALIBRATION_ONLINE_8
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNSYS_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CALIBRATION_ONLINE_16
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNSYS_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CALIBRATION_ONLINE_32
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNSYS_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNSYS_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CONST_BOOLEAN
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNSYS_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CONST_BOOLEAN
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CONST_8
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNSYS_START_SEC_CONST_8
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CONST_8
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CONST_16
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNSYS_START_SEC_CONST_16
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CONST_16
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CONST_32
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNSYS_START_SEC_CONST_32
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CONST_32
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_CONST_UNSPECIFIED
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DERNSYS_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_CONST_UNSPECIFIED
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNSYS_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_NO_INIT_8
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNSYS_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_NO_INIT_8
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_NO_INIT_16
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNSYS_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_NO_INIT_16
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_NO_INIT_32
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNSYS_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_NO_INIT_32
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNSYS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_INIT_BOOLEAN
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNSYS_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_INIT_8
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNSYS_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_INIT_8
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_INIT_16
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNSYS_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_INIT_16
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_INIT_32
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNSYS_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_INIT_32
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNSYS_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNSYS
#endif
#ifdef DERNSYS_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DERNSYS_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNSYS_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

#ifdef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DERNSYS_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNSYS_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNSYS_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNSYS
#endif

 
 
 
