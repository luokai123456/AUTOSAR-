 
/*
********************************************************************************
*
*  File name: HvIntlck_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef HvIntlck_START_SEC_CALIB_BOOLEAN
#undef HvIntlck_START_SEC_CALIB_BOOLEAN
#define HVINTLCK_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef HvIntlck_STOP_SEC_CALIB_BOOLEAN
#undef HvIntlck_STOP_SEC_CALIB_BOOLEAN
#define HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef HvIntlck_START_SEC_CALIB_8
#undef HvIntlck_START_SEC_CALIB_8
#define HVINTLCK_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef HvIntlck_STOP_SEC_CALIB_8
#undef HvIntlck_STOP_SEC_CALIB_8
#define HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef HvIntlck_START_SEC_CALIB_16
#undef HvIntlck_START_SEC_CALIB_16
#define HVINTLCK_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef HvIntlck_STOP_SEC_CALIB_16
#undef HvIntlck_STOP_SEC_CALIB_16
#define HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef HvIntlck_START_SEC_CALIB_32
#undef HvIntlck_START_SEC_CALIB_32
#define HVINTLCK_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef HvIntlck_STOP_SEC_CALIB_32
#undef HvIntlck_STOP_SEC_CALIB_32
#define HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef HvIntlck_START_SEC_CALIB_UNSPECIFIED
#undef HvIntlck_START_SEC_CALIB_UNSPECIFIED
#define HVINTLCK_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef HvIntlck_STOP_SEC_CALIB_UNSPECIFIED
#undef HvIntlck_STOP_SEC_CALIB_UNSPECIFIED
#define HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef HvIntlck_START_SEC_VAR_BOOLEAN
#undef HvIntlck_START_SEC_VAR_BOOLEAN
#define HVINTLCK_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef HvIntlck_STOP_SEC_VAR_BOOLEAN
#undef HvIntlck_STOP_SEC_VAR_BOOLEAN
#define HVINTLCK_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef HvIntlck_START_SEC_VAR_8
#undef HvIntlck_START_SEC_VAR_8
#define HVINTLCK_START_SEC_VAR_NO_INIT_8
#endif
#ifdef HvIntlck_STOP_SEC_VAR_8
#undef HvIntlck_STOP_SEC_VAR_8
#define HVINTLCK_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef HvIntlck_START_SEC_VAR_16
#undef HvIntlck_START_SEC_VAR_16
#define HVINTLCK_START_SEC_VAR_NO_INIT_16
#endif
#ifdef HvIntlck_STOP_SEC_VAR_16
#undef HvIntlck_STOP_SEC_VAR_16
#define HVINTLCK_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef HvIntlck_START_SEC_VAR_32
#undef HvIntlck_START_SEC_VAR_32
#define HVINTLCK_START_SEC_VAR_NO_INIT_32
#endif
#ifdef HvIntlck_STOP_SEC_VAR_32
#undef HvIntlck_STOP_SEC_VAR_32
#define HVINTLCK_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef HvIntlck_START_SEC_VAR_UNSPECIFIED
#undef HvIntlck_START_SEC_VAR_UNSPECIFIED
#define HVINTLCK_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef HvIntlck_STOP_SEC_VAR_UNSPECIFIED
#undef HvIntlck_STOP_SEC_VAR_UNSPECIFIED
#define HVINTLCK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef HvIntlck_START_SEC_CODE
#undef HvIntlck_START_SEC_CODE
#define HVINTLCK_START_SEC_CODE
#endif
#ifdef HvIntlck_STOP_SEC_CODE
#undef HvIntlck_STOP_SEC_CODE
#define HVINTLCK_STOP_SEC_CODE
#endif

#ifdef HvIntlck_START_SEC_CODE_fc_HVIntlck
#undef HvIntlck_START_SEC_CODE_fc_HVIntlck
#define HVINTLCK_START_SEC_CODE
#endif
#ifdef HvIntlck_STOP_SEC_CODE_fc_HVIntlck
#undef HvIntlck_STOP_SEC_CODE_fc_HVIntlck
#define HVINTLCK_STOP_SEC_CODE
#endif

#ifdef HvIntlck_START_SEC_CODE_HvIntlck_Init
#undef HvIntlck_START_SEC_CODE_HvIntlck_Init
#define HVINTLCK_START_SEC_CODE
#endif
#ifdef HvIntlck_STOP_SEC_CODE_HvIntlck_Init
#undef HvIntlck_STOP_SEC_CODE_HvIntlck_Init
#define HVINTLCK_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef HVINTLCK_START_SEC_CODE
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef HVINTLCK_START_SEC_CODE
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CODE
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CODE
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINTLCK_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CALIBRATION_ONLINE_8
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINTLCK_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CALIBRATION_ONLINE_16
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINTLCK_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CALIBRATION_ONLINE_32
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINTLCK_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINTLCK_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CONST_BOOLEAN
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINTLCK_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CONST_BOOLEAN
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CONST_8
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINTLCK_START_SEC_CONST_8
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CONST_8
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CONST_16
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINTLCK_START_SEC_CONST_16
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CONST_16
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CONST_32
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINTLCK_START_SEC_CONST_32
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CONST_32
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_CONST_UNSPECIFIED
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef HVINTLCK_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_CONST_UNSPECIFIED
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINTLCK_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_NO_INIT_8
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINTLCK_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_NO_INIT_8
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_NO_INIT_16
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINTLCK_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_NO_INIT_16
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_NO_INIT_32
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINTLCK_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_NO_INIT_32
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINTLCK_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_INIT_BOOLEAN
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINTLCK_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_INIT_8
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINTLCK_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_INIT_8
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_INIT_16
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINTLCK_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_INIT_16
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_INIT_32
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINTLCK_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_INIT_32
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINTLCK_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_8
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_16
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_32
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_HVINTLCK
#endif
#ifdef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef HVINTLCK_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINTLCK_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

#ifdef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef HVINTLCK_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINTLCK_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINTLCK_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINTLCK
#endif

 
 
 
