 
/*
********************************************************************************
*
*  File name: AngEmDev_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef AngEmDev_START_SEC_CALIB_BOOLEAN
#undef AngEmDev_START_SEC_CALIB_BOOLEAN
#define ANGEMDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef AngEmDev_STOP_SEC_CALIB_BOOLEAN
#undef AngEmDev_STOP_SEC_CALIB_BOOLEAN
#define ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef AngEmDev_START_SEC_CALIB_8
#undef AngEmDev_START_SEC_CALIB_8
#define ANGEMDEV_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef AngEmDev_STOP_SEC_CALIB_8
#undef AngEmDev_STOP_SEC_CALIB_8
#define ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef AngEmDev_START_SEC_CALIB_16
#undef AngEmDev_START_SEC_CALIB_16
#define ANGEMDEV_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef AngEmDev_STOP_SEC_CALIB_16
#undef AngEmDev_STOP_SEC_CALIB_16
#define ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef AngEmDev_START_SEC_CALIB_32
#undef AngEmDev_START_SEC_CALIB_32
#define ANGEMDEV_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef AngEmDev_STOP_SEC_CALIB_32
#undef AngEmDev_STOP_SEC_CALIB_32
#define ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef AngEmDev_START_SEC_CALIB_UNSPECIFIED
#undef AngEmDev_START_SEC_CALIB_UNSPECIFIED
#define ANGEMDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef AngEmDev_STOP_SEC_CALIB_UNSPECIFIED
#undef AngEmDev_STOP_SEC_CALIB_UNSPECIFIED
#define ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef AngEmDev_START_SEC_VAR_BOOLEAN
#undef AngEmDev_START_SEC_VAR_BOOLEAN
#define ANGEMDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef AngEmDev_STOP_SEC_VAR_BOOLEAN
#undef AngEmDev_STOP_SEC_VAR_BOOLEAN
#define ANGEMDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef AngEmDev_START_SEC_VAR_8
#undef AngEmDev_START_SEC_VAR_8
#define ANGEMDEV_START_SEC_VAR_NO_INIT_8
#endif
#ifdef AngEmDev_STOP_SEC_VAR_8
#undef AngEmDev_STOP_SEC_VAR_8
#define ANGEMDEV_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef AngEmDev_START_SEC_VAR_16
#undef AngEmDev_START_SEC_VAR_16
#define ANGEMDEV_START_SEC_VAR_NO_INIT_16
#endif
#ifdef AngEmDev_STOP_SEC_VAR_16
#undef AngEmDev_STOP_SEC_VAR_16
#define ANGEMDEV_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef AngEmDev_START_SEC_VAR_32
#undef AngEmDev_START_SEC_VAR_32
#define ANGEMDEV_START_SEC_VAR_NO_INIT_32
#endif
#ifdef AngEmDev_STOP_SEC_VAR_32
#undef AngEmDev_STOP_SEC_VAR_32
#define ANGEMDEV_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef AngEmDev_START_SEC_VAR_UNSPECIFIED
#undef AngEmDev_START_SEC_VAR_UNSPECIFIED
#define ANGEMDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef AngEmDev_STOP_SEC_VAR_UNSPECIFIED
#undef AngEmDev_STOP_SEC_VAR_UNSPECIFIED
#define ANGEMDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef AngEmDev_START_SEC_CODE
#undef AngEmDev_START_SEC_CODE
#define ANGEMDEV_START_SEC_CODE
#endif
#ifdef AngEmDev_STOP_SEC_CODE
#undef AngEmDev_STOP_SEC_CODE
#define ANGEMDEV_STOP_SEC_CODE
#endif

#ifdef AngEmDev_START_SEC_CODE_fc_AngEmDev
#undef AngEmDev_START_SEC_CODE_fc_AngEmDev
#define ANGEMDEV_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef AngEmDev_STOP_SEC_CODE_fc_AngEmDev
#undef AngEmDev_STOP_SEC_CODE_fc_AngEmDev
#define ANGEMDEV_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef AngEmDev_START_SEC_CODE_AngEmDev_Init
#undef AngEmDev_START_SEC_CODE_AngEmDev_Init
#define ANGEMDEV_START_SEC_CODE
#endif
#ifdef AngEmDev_STOP_SEC_CODE_AngEmDev_Init
#undef AngEmDev_STOP_SEC_CODE_AngEmDev_Init
#define ANGEMDEV_STOP_SEC_CODE
#endif

/*** ASW End ***/




#ifdef ANGEMDEV_START_SEC_CODE
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef ANGEMDEV_START_SEC_CODE
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CODE
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CODE
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CODE_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef ANGEMDEV_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CODE_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_8
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_16
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_32
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGEMDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CONST_BOOLEAN
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGEMDEV_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CONST_BOOLEAN
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CONST_8
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGEMDEV_START_SEC_CONST_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CONST_8
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CONST_16
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGEMDEV_START_SEC_CONST_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CONST_16
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CONST_32
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGEMDEV_START_SEC_CONST_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CONST_32
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_CONST_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef ANGEMDEV_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_CONST_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGEMDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_NO_INIT_8
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGEMDEV_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_NO_INIT_8
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_NO_INIT_16
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGEMDEV_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_NO_INIT_16
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_NO_INIT_32
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGEMDEV_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_NO_INIT_32
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGEMDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_INIT_BOOLEAN
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGEMDEV_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_INIT_8
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGEMDEV_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_INIT_8
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_INIT_16
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGEMDEV_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_INIT_16
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_INIT_32
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGEMDEV_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_INIT_32
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGEMDEV_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_8
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_16
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_32
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ANGEMDEV
#endif
#ifdef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef ANGEMDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGEMDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

#ifdef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef ANGEMDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGEMDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGEMDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGEMDEV
#endif

 
 
 
