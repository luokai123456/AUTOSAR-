 
/*
********************************************************************************
*
*  File name: TqDemCoorn_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef TqDemCoorn_START_SEC_CALIB_BOOLEAN
#undef TqDemCoorn_START_SEC_CALIB_BOOLEAN
#define TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef TqDemCoorn_STOP_SEC_CALIB_BOOLEAN
#undef TqDemCoorn_STOP_SEC_CALIB_BOOLEAN
#define TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef TqDemCoorn_START_SEC_CALIB_8
#undef TqDemCoorn_START_SEC_CALIB_8
#define TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef TqDemCoorn_STOP_SEC_CALIB_8
#undef TqDemCoorn_STOP_SEC_CALIB_8
#define TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef TqDemCoorn_START_SEC_CALIB_16
#undef TqDemCoorn_START_SEC_CALIB_16
#define TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef TqDemCoorn_STOP_SEC_CALIB_16
#undef TqDemCoorn_STOP_SEC_CALIB_16
#define TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef TqDemCoorn_START_SEC_CALIB_32
#undef TqDemCoorn_START_SEC_CALIB_32
#define TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef TqDemCoorn_STOP_SEC_CALIB_32
#undef TqDemCoorn_STOP_SEC_CALIB_32
#define TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef TqDemCoorn_START_SEC_CALIB_UNSPECIFIED
#undef TqDemCoorn_START_SEC_CALIB_UNSPECIFIED
#define TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef TqDemCoorn_STOP_SEC_CALIB_UNSPECIFIED
#undef TqDemCoorn_STOP_SEC_CALIB_UNSPECIFIED
#define TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef TqDemCoorn_START_SEC_VAR_BOOLEAN
#undef TqDemCoorn_START_SEC_VAR_BOOLEAN
#define TQDEMCOORN_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef TqDemCoorn_STOP_SEC_VAR_BOOLEAN
#undef TqDemCoorn_STOP_SEC_VAR_BOOLEAN
#define TQDEMCOORN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef TqDemCoorn_START_SEC_VAR_8
#undef TqDemCoorn_START_SEC_VAR_8
#define TQDEMCOORN_START_SEC_VAR_NO_INIT_8
#endif
#ifdef TqDemCoorn_STOP_SEC_VAR_8
#undef TqDemCoorn_STOP_SEC_VAR_8
#define TQDEMCOORN_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef TqDemCoorn_START_SEC_VAR_16
#undef TqDemCoorn_START_SEC_VAR_16
#define TQDEMCOORN_START_SEC_VAR_NO_INIT_16
#endif
#ifdef TqDemCoorn_STOP_SEC_VAR_16
#undef TqDemCoorn_STOP_SEC_VAR_16
#define TQDEMCOORN_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef TqDemCoorn_START_SEC_VAR_32
#undef TqDemCoorn_START_SEC_VAR_32
#define TQDEMCOORN_START_SEC_VAR_NO_INIT_32
#endif
#ifdef TqDemCoorn_STOP_SEC_VAR_32
#undef TqDemCoorn_STOP_SEC_VAR_32
#define TQDEMCOORN_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef TqDemCoorn_START_SEC_VAR_UNSPECIFIED
#undef TqDemCoorn_START_SEC_VAR_UNSPECIFIED
#define TQDEMCOORN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef TqDemCoorn_STOP_SEC_VAR_UNSPECIFIED
#undef TqDemCoorn_STOP_SEC_VAR_UNSPECIFIED
#define TQDEMCOORN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef TqDemCoorn_START_SEC_CODE
#undef TqDemCoorn_START_SEC_CODE
#define TQDEMCOORN_START_SEC_CODE
#endif
#ifdef TqDemCoorn_STOP_SEC_CODE
#undef TqDemCoorn_STOP_SEC_CODE
#define TQDEMCOORN_STOP_SEC_CODE
#endif

#ifdef TqDemCoorn_START_SEC_CODE_fc_TqDemCoorn
#undef TqDemCoorn_START_SEC_CODE_fc_TqDemCoorn
#define TQDEMCOORN_START_SEC_CODE
#endif
#ifdef TqDemCoorn_STOP_SEC_CODE_fc_TqDemCoorn
#undef TqDemCoorn_STOP_SEC_CODE_fc_TqDemCoorn
#define TQDEMCOORN_STOP_SEC_CODE
#endif

#ifdef TqDemCoorn_START_SEC_CODE_TqDemCoorn_Init
#undef TqDemCoorn_START_SEC_CODE_TqDemCoorn_Init
#define TQDEMCOORN_START_SEC_CODE
#endif
#ifdef TqDemCoorn_STOP_SEC_CODE_TqDemCoorn_Init
#undef TqDemCoorn_STOP_SEC_CODE_TqDemCoorn_Init
#define TQDEMCOORN_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef TQDEMCOORN_START_SEC_CODE
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef TQDEMCOORN_START_SEC_CODE
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CODE
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CODE
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_8
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_16
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_32
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TQDEMCOORN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CONST_BOOLEAN
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TQDEMCOORN_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CONST_BOOLEAN
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CONST_8
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TQDEMCOORN_START_SEC_CONST_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CONST_8
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CONST_16
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TQDEMCOORN_START_SEC_CONST_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CONST_16
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CONST_32
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TQDEMCOORN_START_SEC_CONST_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CONST_32
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_CONST_UNSPECIFIED
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef TQDEMCOORN_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_CONST_UNSPECIFIED
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TQDEMCOORN_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_NO_INIT_8
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TQDEMCOORN_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_8
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_NO_INIT_16
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TQDEMCOORN_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_16
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_NO_INIT_32
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TQDEMCOORN_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_32
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TQDEMCOORN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_INIT_BOOLEAN
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TQDEMCOORN_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_INIT_8
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TQDEMCOORN_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_INIT_8
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_INIT_16
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TQDEMCOORN_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_INIT_16
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_INIT_32
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TQDEMCOORN_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_INIT_32
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TQDEMCOORN_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_8
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_16
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_32
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_TQDEMCOORN
#endif
#ifdef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TQDEMCOORN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

#ifdef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef TQDEMCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TQDEMCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TQDEMCOORN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TQDEMCOORN
#endif

 
 
 
