 
/*
********************************************************************************
*
*  File name: ComRx_CAN_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef ComRx_CAN_START_SEC_CALIB_BOOLEAN
#undef ComRx_CAN_START_SEC_CALIB_BOOLEAN
#define COMRX_CAN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef ComRx_CAN_STOP_SEC_CALIB_BOOLEAN
#undef ComRx_CAN_STOP_SEC_CALIB_BOOLEAN
#define COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef ComRx_CAN_START_SEC_CALIB_8
#undef ComRx_CAN_START_SEC_CALIB_8
#define COMRX_CAN_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef ComRx_CAN_STOP_SEC_CALIB_8
#undef ComRx_CAN_STOP_SEC_CALIB_8
#define COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef ComRx_CAN_START_SEC_CALIB_16
#undef ComRx_CAN_START_SEC_CALIB_16
#define COMRX_CAN_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef ComRx_CAN_STOP_SEC_CALIB_16
#undef ComRx_CAN_STOP_SEC_CALIB_16
#define COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef ComRx_CAN_START_SEC_CALIB_32
#undef ComRx_CAN_START_SEC_CALIB_32
#define COMRX_CAN_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef ComRx_CAN_STOP_SEC_CALIB_32
#undef ComRx_CAN_STOP_SEC_CALIB_32
#define COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef ComRx_CAN_START_SEC_CALIB_UNSPECIFIED
#undef ComRx_CAN_START_SEC_CALIB_UNSPECIFIED
#define COMRX_CAN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef ComRx_CAN_STOP_SEC_CALIB_UNSPECIFIED
#undef ComRx_CAN_STOP_SEC_CALIB_UNSPECIFIED
#define COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef ComRx_CAN_START_SEC_VAR_BOOLEAN
#undef ComRx_CAN_START_SEC_VAR_BOOLEAN
#define COMRX_CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef ComRx_CAN_STOP_SEC_VAR_BOOLEAN
#undef ComRx_CAN_STOP_SEC_VAR_BOOLEAN
#define COMRX_CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef ComRx_CAN_START_SEC_VAR_8
#undef ComRx_CAN_START_SEC_VAR_8
#define COMRX_CAN_START_SEC_VAR_NO_INIT_8
#endif
#ifdef ComRx_CAN_STOP_SEC_VAR_8
#undef ComRx_CAN_STOP_SEC_VAR_8
#define COMRX_CAN_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef ComRx_CAN_START_SEC_VAR_16
#undef ComRx_CAN_START_SEC_VAR_16
#define COMRX_CAN_START_SEC_VAR_NO_INIT_16
#endif
#ifdef ComRx_CAN_STOP_SEC_VAR_16
#undef ComRx_CAN_STOP_SEC_VAR_16
#define COMRX_CAN_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef ComRx_CAN_START_SEC_VAR_32
#undef ComRx_CAN_START_SEC_VAR_32
#define COMRX_CAN_START_SEC_VAR_NO_INIT_32
#endif
#ifdef ComRx_CAN_STOP_SEC_VAR_32
#undef ComRx_CAN_STOP_SEC_VAR_32
#define COMRX_CAN_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef ComRx_CAN_START_SEC_VAR_UNSPECIFIED
#undef ComRx_CAN_START_SEC_VAR_UNSPECIFIED
#define COMRX_CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef ComRx_CAN_STOP_SEC_VAR_UNSPECIFIED
#undef ComRx_CAN_STOP_SEC_VAR_UNSPECIFIED
#define COMRX_CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ComRx_CAN_START_SEC_CODE
#undef ComRx_CAN_START_SEC_CODE
#define COMRX_CAN_START_SEC_CODE
#endif
#ifdef ComRx_CAN_STOP_SEC_CODE
#undef ComRx_CAN_STOP_SEC_CODE
#define COMRX_CAN_STOP_SEC_CODE
#endif

#ifdef ComRx_CAN_START_SEC_CODE_fc_ComRx_CAN_1
#undef ComRx_CAN_START_SEC_CODE_fc_ComRx_CAN_1
#define COMRX_CAN_START_SEC_CODE
#endif
#ifdef ComRx_CAN_STOP_SEC_CODE_fc_ComRx_CAN_1
#undef ComRx_CAN_STOP_SEC_CODE_fc_ComRx_CAN_1
#define COMRX_CAN_STOP_SEC_CODE
#endif

#ifdef ComRx_CAN_START_SEC_CODE_ComRx_CAN_1_Init
#undef ComRx_CAN_START_SEC_CODE_ComRx_CAN_1_Init
#define COMRX_CAN_START_SEC_CODE
#endif
#ifdef ComRx_CAN_STOP_SEC_CODE_ComRx_CAN_1_Init
#undef ComRx_CAN_STOP_SEC_CODE_ComRx_CAN_1_Init
#define COMRX_CAN_STOP_SEC_CODE
#endif

#ifdef ComRx_CAN_START_SEC_CODE_fc_ComRx10ms
#undef ComRx_CAN_START_SEC_CODE_fc_ComRx10ms
#define COMRX_CAN_START_SEC_CODE
#endif
#ifdef ComRx_CAN_STOP_SEC_CODE_fc_ComRx10ms
#undef ComRx_CAN_STOP_SEC_CODE_fc_ComRx10ms
#define COMRX_CAN_STOP_SEC_CODE
#endif

/*** ASW End ***/

#ifdef COMRX_CAN_START_SEC_CODE
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef COMRX_CAN_START_SEC_CODE
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CODE
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CODE
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_8
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_16
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_32
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef COMRX_CAN_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CONST_BOOLEAN
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMRX_CAN_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CONST_BOOLEAN
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CONST_8
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMRX_CAN_START_SEC_CONST_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CONST_8
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CONST_16
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMRX_CAN_START_SEC_CONST_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CONST_16
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CONST_32
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef COMRX_CAN_START_SEC_CONST_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CONST_32
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_CONST_UNSPECIFIED
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef COMRX_CAN_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_CONST_UNSPECIFIED
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMRX_CAN_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_NO_INIT_8
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMRX_CAN_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_NO_INIT_8
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_NO_INIT_16
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMRX_CAN_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_NO_INIT_16
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_NO_INIT_32
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMRX_CAN_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_NO_INIT_32
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef COMRX_CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_INIT_BOOLEAN
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMRX_CAN_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_INIT_8
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMRX_CAN_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_INIT_8
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_INIT_16
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMRX_CAN_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_INIT_16
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_INIT_32
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMRX_CAN_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_INIT_32
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef COMRX_CAN_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_8
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_16
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_32
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_COMRX_CAN
#endif
#ifdef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef COMRX_CAN_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef COMRX_CAN_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

#ifdef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef COMRX_CAN_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef COMRX_CAN_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef COMRX_CAN_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_COMRX_CAN
#endif

 
 
 
