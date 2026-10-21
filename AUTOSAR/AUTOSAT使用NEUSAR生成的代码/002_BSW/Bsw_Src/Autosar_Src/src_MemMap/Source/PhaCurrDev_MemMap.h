 
/*
********************************************************************************
*
*  File name: PhaCurrDev_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/


/*** ASW Start ***/

#ifdef PhaCurrDev_START_SEC_CALIB_BOOLEAN
#undef PhaCurrDev_START_SEC_CALIB_BOOLEAN
#define PHACURRDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef PhaCurrDev_STOP_SEC_CALIB_BOOLEAN
#undef PhaCurrDev_STOP_SEC_CALIB_BOOLEAN
#define PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef PhaCurrDev_START_SEC_CALIB_8
#undef PhaCurrDev_START_SEC_CALIB_8
#define PHACURRDEV_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef PhaCurrDev_STOP_SEC_CALIB_8
#undef PhaCurrDev_STOP_SEC_CALIB_8
#define PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef PhaCurrDev_START_SEC_CALIB_16
#undef PhaCurrDev_START_SEC_CALIB_16
#define PHACURRDEV_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef PhaCurrDev_STOP_SEC_CALIB_16
#undef PhaCurrDev_STOP_SEC_CALIB_16
#define PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef PhaCurrDev_START_SEC_CALIB_32
#undef PhaCurrDev_START_SEC_CALIB_32
#define PHACURRDEV_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef PhaCurrDev_STOP_SEC_CALIB_32
#undef PhaCurrDev_STOP_SEC_CALIB_32
#define PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef PhaCurrDev_START_SEC_CALIB_UNSPECIFIED
#undef PhaCurrDev_START_SEC_CALIB_UNSPECIFIED
#define PHACURRDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef PhaCurrDev_STOP_SEC_CALIB_UNSPECIFIED
#undef PhaCurrDev_STOP_SEC_CALIB_UNSPECIFIED
#define PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef PhaCurrDev_START_SEC_VAR_BOOLEAN
#undef PhaCurrDev_START_SEC_VAR_BOOLEAN
#define PHACURRDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef PhaCurrDev_STOP_SEC_VAR_BOOLEAN
#undef PhaCurrDev_STOP_SEC_VAR_BOOLEAN
#define PHACURRDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef PhaCurrDev_START_SEC_VAR_8
#undef PhaCurrDev_START_SEC_VAR_8
#define PHACURRDEV_START_SEC_VAR_NO_INIT_8
#endif
#ifdef PhaCurrDev_STOP_SEC_VAR_8
#undef PhaCurrDev_STOP_SEC_VAR_8
#define PHACURRDEV_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef PhaCurrDev_START_SEC_VAR_16
#undef PhaCurrDev_START_SEC_VAR_16
#define PHACURRDEV_START_SEC_VAR_NO_INIT_16
#endif
#ifdef PhaCurrDev_STOP_SEC_VAR_16
#undef PhaCurrDev_STOP_SEC_VAR_16
#define PHACURRDEV_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef PhaCurrDev_START_SEC_VAR_32
#undef PhaCurrDev_START_SEC_VAR_32
#define PHACURRDEV_START_SEC_VAR_NO_INIT_32
#endif
#ifdef PhaCurrDev_STOP_SEC_VAR_32
#undef PhaCurrDev_STOP_SEC_VAR_32
#define PHACURRDEV_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef PhaCurrDev_START_SEC_VAR_UNSPECIFIED
#undef PhaCurrDev_START_SEC_VAR_UNSPECIFIED
#define PHACURRDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef PhaCurrDev_STOP_SEC_VAR_UNSPECIFIED
#undef PhaCurrDev_STOP_SEC_VAR_UNSPECIFIED
#define PHACURRDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef PhaCurrDev_START_SEC_CODE
#undef PhaCurrDev_START_SEC_CODE
#define PHACURRDEV_START_SEC_CODE
#endif
#ifdef PhaCurrDev_STOP_SEC_CODE
#undef PhaCurrDev_STOP_SEC_CODE
#define PHACURRDEV_STOP_SEC_CODE
#endif

#ifdef PhaCurrDev_START_SEC_CODE_fc_PhaCurrDev
#undef PhaCurrDev_START_SEC_CODE_fc_PhaCurrDev
#define PHACURRDEV_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef PhaCurrDev_STOP_SEC_CODE_fc_PhaCurrDev
#undef PhaCurrDev_STOP_SEC_CODE_fc_PhaCurrDev
#define PHACURRDEV_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef PhaCurrDev_START_SEC_CODE_PhaCurrDev_Init
#undef PhaCurrDev_START_SEC_CODE_PhaCurrDev_Init
#define PHACURRDEV_START_SEC_CODE
#endif
#ifdef PhaCurrDev_STOP_SEC_CODE_PhaCurrDev_Init
#undef PhaCurrDev_STOP_SEC_CODE_PhaCurrDev_Init
#define PHACURRDEV_STOP_SEC_CODE
#endif

/*** ASW End ***/

#ifdef PHACURRDEV_START_SEC_CODE
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef PHACURRDEV_START_SEC_CODE
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CODE
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CODE
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CODE_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef PHACURRDEV_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CODE_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_8
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_16
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_32
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef PHACURRDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CONST_BOOLEAN
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef PHACURRDEV_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CONST_BOOLEAN
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CONST_8
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef PHACURRDEV_START_SEC_CONST_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CONST_8
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CONST_16
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef PHACURRDEV_START_SEC_CONST_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CONST_16
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CONST_32
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef PHACURRDEV_START_SEC_CONST_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CONST_32
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_CONST_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef PHACURRDEV_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_CONST_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef PHACURRDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_NO_INIT_8
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef PHACURRDEV_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_NO_INIT_8
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_NO_INIT_16
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef PHACURRDEV_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_NO_INIT_16
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_NO_INIT_32
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef PHACURRDEV_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_NO_INIT_32
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef PHACURRDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_INIT_BOOLEAN
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef PHACURRDEV_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_INIT_8
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef PHACURRDEV_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_INIT_8
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_INIT_16
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef PHACURRDEV_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_INIT_16
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_INIT_32
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef PHACURRDEV_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_INIT_32
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef PHACURRDEV_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_8
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_16
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_32
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_PHACURRDEV
#endif
#ifdef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef PHACURRDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef PHACURRDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

#ifdef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef PHACURRDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef PHACURRDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef PHACURRDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_PHACURRDEV
#endif

 
 
 
