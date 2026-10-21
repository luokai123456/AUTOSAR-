 
/*
********************************************************************************
*
*  File name: TempDev_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef TempDev_START_SEC_CALIB_BOOLEAN
#undef TempDev_START_SEC_CALIB_BOOLEAN
#define TEMPDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef TempDev_STOP_SEC_CALIB_BOOLEAN
#undef TempDev_STOP_SEC_CALIB_BOOLEAN
#define TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef TempDev_START_SEC_CALIB_8
#undef TempDev_START_SEC_CALIB_8
#define TEMPDEV_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef TempDev_STOP_SEC_CALIB_8
#undef TempDev_STOP_SEC_CALIB_8
#define TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef TempDev_START_SEC_CALIB_16
#undef TempDev_START_SEC_CALIB_16
#define TEMPDEV_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef TempDev_STOP_SEC_CALIB_16
#undef TempDev_STOP_SEC_CALIB_16
#define TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef TempDev_START_SEC_CALIB_32
#undef TempDev_START_SEC_CALIB_32
#define TEMPDEV_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef TempDev_STOP_SEC_CALIB_32
#undef TempDev_STOP_SEC_CALIB_32
#define TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef TempDev_START_SEC_CALIB_UNSPECIFIED
#undef TempDev_START_SEC_CALIB_UNSPECIFIED
#define TEMPDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef TempDev_STOP_SEC_CALIB_UNSPECIFIED
#undef TempDev_STOP_SEC_CALIB_UNSPECIFIED
#define TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef TempDev_START_SEC_VAR_BOOLEAN
#undef TempDev_START_SEC_VAR_BOOLEAN
#define TEMPDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef TempDev_STOP_SEC_VAR_BOOLEAN
#undef TempDev_STOP_SEC_VAR_BOOLEAN
#define TEMPDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef TempDev_START_SEC_VAR_8
#undef TempDev_START_SEC_VAR_8
#define TEMPDEV_START_SEC_VAR_NO_INIT_8
#endif
#ifdef TempDev_STOP_SEC_VAR_8
#undef TempDev_STOP_SEC_VAR_8
#define TEMPDEV_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef TempDev_START_SEC_VAR_16
#undef TempDev_START_SEC_VAR_16
#define TEMPDEV_START_SEC_VAR_NO_INIT_16
#endif
#ifdef TempDev_STOP_SEC_VAR_16
#undef TempDev_STOP_SEC_VAR_16
#define TEMPDEV_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef TempDev_START_SEC_VAR_32
#undef TempDev_START_SEC_VAR_32
#define TEMPDEV_START_SEC_VAR_NO_INIT_32
#endif
#ifdef TempDev_STOP_SEC_VAR_32
#undef TempDev_STOP_SEC_VAR_32
#define TEMPDEV_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef TempDev_START_SEC_VAR_UNSPECIFIED
#undef TempDev_START_SEC_VAR_UNSPECIFIED
#define TEMPDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef TempDev_STOP_SEC_VAR_UNSPECIFIED
#undef TempDev_STOP_SEC_VAR_UNSPECIFIED
#define TEMPDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef TempDev_START_SEC_CODE
#undef TempDev_START_SEC_CODE
#define TEMPDEV_START_SEC_CODE
#endif
#ifdef TempDev_STOP_SEC_CODE
#undef TempDev_STOP_SEC_CODE
#define TEMPDEV_STOP_SEC_CODE
#endif

#ifdef TempDev_START_SEC_CODE_fc_TempDev
#undef TempDev_START_SEC_CODE_fc_TempDev
#define TEMPDEV_START_SEC_CODE
#endif
#ifdef TempDev_STOP_SEC_CODE_fc_TempDev
#undef TempDev_STOP_SEC_CODE_fc_TempDev
#define TEMPDEV_STOP_SEC_CODE
#endif

#ifdef TempDev_START_SEC_CODE_TempDev_Init
#undef TempDev_START_SEC_CODE_TempDev_Init
#define TEMPDEV_START_SEC_CODE
#endif
#ifdef TempDev_STOP_SEC_CODE_TempDev_Init
#undef TempDev_STOP_SEC_CODE_TempDev_Init
#define TEMPDEV_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef TEMPDEV_START_SEC_CODE
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef TEMPDEV_START_SEC_CODE
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CODE
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CODE
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TEMPDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CALIBRATION_ONLINE_8
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TEMPDEV_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CALIBRATION_ONLINE_16
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TEMPDEV_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CALIBRATION_ONLINE_32
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TEMPDEV_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef TEMPDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CONST_BOOLEAN
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TEMPDEV_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CONST_BOOLEAN
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CONST_8
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TEMPDEV_START_SEC_CONST_8
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CONST_8
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CONST_16
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TEMPDEV_START_SEC_CONST_16
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CONST_16
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CONST_32
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef TEMPDEV_START_SEC_CONST_32
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CONST_32
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_CONST_UNSPECIFIED
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef TEMPDEV_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_CONST_UNSPECIFIED
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TEMPDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_NO_INIT_8
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TEMPDEV_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_NO_INIT_8
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_NO_INIT_16
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TEMPDEV_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_NO_INIT_16
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_NO_INIT_32
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TEMPDEV_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_NO_INIT_32
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef TEMPDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_INIT_BOOLEAN
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TEMPDEV_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_INIT_8
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TEMPDEV_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_INIT_8
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_INIT_16
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TEMPDEV_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_INIT_16
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_INIT_32
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TEMPDEV_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_INIT_32
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef TEMPDEV_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_8
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_16
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_32
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_TEMPDEV
#endif
#ifdef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef TEMPDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef TEMPDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

#ifdef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef TEMPDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef TEMPDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef TEMPDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_TEMPDEV
#endif

 
 
 
