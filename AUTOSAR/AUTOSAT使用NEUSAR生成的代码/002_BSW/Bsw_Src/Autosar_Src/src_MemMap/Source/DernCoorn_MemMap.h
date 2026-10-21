 
/*
********************************************************************************
*
*  File name: DernCoorn_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef DernCoorn_START_SEC_CALIB_BOOLEAN
#undef DernCoorn_START_SEC_CALIB_BOOLEAN
#define DERNCOORN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef DernCoorn_STOP_SEC_CALIB_BOOLEAN
#undef DernCoorn_STOP_SEC_CALIB_BOOLEAN
#define DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef DernCoorn_START_SEC_CALIB_8
#undef DernCoorn_START_SEC_CALIB_8
#define DERNCOORN_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef DernCoorn_STOP_SEC_CALIB_8
#undef DernCoorn_STOP_SEC_CALIB_8
#define DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef DernCoorn_START_SEC_CALIB_16
#undef DernCoorn_START_SEC_CALIB_16
#define DERNCOORN_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef DernCoorn_STOP_SEC_CALIB_16
#undef DernCoorn_STOP_SEC_CALIB_16
#define DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef DernCoorn_START_SEC_CALIB_32
#undef DernCoorn_START_SEC_CALIB_32
#define DERNCOORN_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef DernCoorn_STOP_SEC_CALIB_32
#undef DernCoorn_STOP_SEC_CALIB_32
#define DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef DernCoorn_START_SEC_CALIB_UNSPECIFIED
#undef DernCoorn_START_SEC_CALIB_UNSPECIFIED
#define DERNCOORN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef DernCoorn_STOP_SEC_CALIB_UNSPECIFIED
#undef DernCoorn_STOP_SEC_CALIB_UNSPECIFIED
#define DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef DernCoorn_START_SEC_VAR_BOOLEAN
#undef DernCoorn_START_SEC_VAR_BOOLEAN
#define DERNCOORN_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef DernCoorn_STOP_SEC_VAR_BOOLEAN
#undef DernCoorn_STOP_SEC_VAR_BOOLEAN
#define DERNCOORN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef DernCoorn_START_SEC_VAR_8
#undef DernCoorn_START_SEC_VAR_8
#define DERNCOORN_START_SEC_VAR_NO_INIT_8
#endif
#ifdef DernCoorn_STOP_SEC_VAR_8
#undef DernCoorn_STOP_SEC_VAR_8
#define DERNCOORN_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef DernCoorn_START_SEC_VAR_16
#undef DernCoorn_START_SEC_VAR_16
#define DERNCOORN_START_SEC_VAR_NO_INIT_16
#endif
#ifdef DernCoorn_STOP_SEC_VAR_16
#undef DernCoorn_STOP_SEC_VAR_16
#define DERNCOORN_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef DernCoorn_START_SEC_VAR_32
#undef DernCoorn_START_SEC_VAR_32
#define DERNCOORN_START_SEC_VAR_NO_INIT_32
#endif
#ifdef DernCoorn_STOP_SEC_VAR_32
#undef DernCoorn_STOP_SEC_VAR_32
#define DERNCOORN_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef DernCoorn_START_SEC_VAR_UNSPECIFIED
#undef DernCoorn_START_SEC_VAR_UNSPECIFIED
#define DERNCOORN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef DernCoorn_STOP_SEC_VAR_UNSPECIFIED
#undef DernCoorn_STOP_SEC_VAR_UNSPECIFIED
#define DERNCOORN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef DernCoorn_START_SEC_CODE
#undef DernCoorn_START_SEC_CODE
#define DERNCOORN_START_SEC_CODE
#endif
#ifdef DernCoorn_STOP_SEC_CODE
#undef DernCoorn_STOP_SEC_CODE
#define DERNCOORN_STOP_SEC_CODE
#endif

#ifdef DernCoorn_START_SEC_CODE_fc_DernCoorn
#undef DernCoorn_START_SEC_CODE_fc_DernCoorn
#define DERNCOORN_START_SEC_CODE
#endif
#ifdef DernCoorn_STOP_SEC_CODE_fc_DernCoorn
#undef DernCoorn_STOP_SEC_CODE_fc_DernCoorn
#define DERNCOORN_STOP_SEC_CODE
#endif

#ifdef DernCoorn_START_SEC_CODE_DernCoorn_Init
#undef DernCoorn_START_SEC_CODE_DernCoorn_Init
#define DERNCOORN_START_SEC_CODE
#endif
#ifdef DernCoorn_STOP_SEC_CODE_DernCoorn_Init
#undef DernCoorn_STOP_SEC_CODE_DernCoorn_Init
#define DERNCOORN_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef DERNCOORN_START_SEC_CODE
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef DERNCOORN_START_SEC_CODE
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CODE
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CODE
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNCOORN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CALIBRATION_ONLINE_8
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNCOORN_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CALIBRATION_ONLINE_16
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNCOORN_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CALIBRATION_ONLINE_32
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNCOORN_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef DERNCOORN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CONST_BOOLEAN
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNCOORN_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CONST_BOOLEAN
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CONST_8
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNCOORN_START_SEC_CONST_8
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CONST_8
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CONST_16
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNCOORN_START_SEC_CONST_16
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CONST_16
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CONST_32
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef DERNCOORN_START_SEC_CONST_32
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CONST_32
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_CONST_UNSPECIFIED
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef DERNCOORN_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_CONST_UNSPECIFIED
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNCOORN_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_NO_INIT_8
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNCOORN_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_NO_INIT_8
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_NO_INIT_16
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNCOORN_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_NO_INIT_16
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_NO_INIT_32
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNCOORN_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_NO_INIT_32
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef DERNCOORN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_INIT_BOOLEAN
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNCOORN_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_INIT_8
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNCOORN_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_INIT_8
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_INIT_16
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNCOORN_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_INIT_16
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_INIT_32
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNCOORN_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_INIT_32
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef DERNCOORN_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_8
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_16
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_32
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_DERNCOORN
#endif
#ifdef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef DERNCOORN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef DERNCOORN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

#ifdef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef DERNCOORN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef DERNCOORN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef DERNCOORN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_DERNCOORN
#endif

 
 
 
