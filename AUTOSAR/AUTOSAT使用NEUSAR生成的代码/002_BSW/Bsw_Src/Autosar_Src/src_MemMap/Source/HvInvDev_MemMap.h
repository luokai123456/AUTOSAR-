 
/*
********************************************************************************
*
*  File name: HvInvDev_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef HvInvDev_START_SEC_CALIB_BOOLEAN
#undef HvInvDev_START_SEC_CALIB_BOOLEAN
#define HVINVDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef HvInvDev_STOP_SEC_CALIB_BOOLEAN
#undef HvInvDev_STOP_SEC_CALIB_BOOLEAN
#define HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef HvInvDev_START_SEC_CALIB_8
#undef HvInvDev_START_SEC_CALIB_8
#define HVINVDEV_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef HvInvDev_STOP_SEC_CALIB_8
#undef HvInvDev_STOP_SEC_CALIB_8
#define HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef HvInvDev_START_SEC_CALIB_16
#undef HvInvDev_START_SEC_CALIB_16
#define HVINVDEV_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef HvInvDev_STOP_SEC_CALIB_16
#undef HvInvDev_STOP_SEC_CALIB_16
#define HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef HvInvDev_START_SEC_CALIB_32
#undef HvInvDev_START_SEC_CALIB_32
#define HVINVDEV_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef HvInvDev_STOP_SEC_CALIB_32
#undef HvInvDev_STOP_SEC_CALIB_32
#define HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef HvInvDev_START_SEC_CALIB_UNSPECIFIED
#undef HvInvDev_START_SEC_CALIB_UNSPECIFIED
#define HVINVDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef HvInvDev_STOP_SEC_CALIB_UNSPECIFIED
#undef HvInvDev_STOP_SEC_CALIB_UNSPECIFIED
#define HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef HvInvDev_START_SEC_VAR_BOOLEAN
#undef HvInvDev_START_SEC_VAR_BOOLEAN
#define HVINVDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef HvInvDev_STOP_SEC_VAR_BOOLEAN
#undef HvInvDev_STOP_SEC_VAR_BOOLEAN
#define HVINVDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef HvInvDev_START_SEC_VAR_8
#undef HvInvDev_START_SEC_VAR_8
#define HVINVDEV_START_SEC_VAR_NO_INIT_8
#endif
#ifdef HvInvDev_STOP_SEC_VAR_8
#undef HvInvDev_STOP_SEC_VAR_8
#define HVINVDEV_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef HvInvDev_START_SEC_VAR_16
#undef HvInvDev_START_SEC_VAR_16
#define HVINVDEV_START_SEC_VAR_NO_INIT_16
#endif
#ifdef HvInvDev_STOP_SEC_VAR_16
#undef HvInvDev_STOP_SEC_VAR_16
#define HVINVDEV_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef HvInvDev_START_SEC_VAR_32
#undef HvInvDev_START_SEC_VAR_32
#define HVINVDEV_START_SEC_VAR_NO_INIT_32
#endif
#ifdef HvInvDev_STOP_SEC_VAR_32
#undef HvInvDev_STOP_SEC_VAR_32
#define HVINVDEV_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef HvInvDev_START_SEC_VAR_UNSPECIFIED
#undef HvInvDev_START_SEC_VAR_UNSPECIFIED
#define HVINVDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef HvInvDev_STOP_SEC_VAR_UNSPECIFIED
#undef HvInvDev_STOP_SEC_VAR_UNSPECIFIED
#define HVINVDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef HvInvDev_START_SEC_CODE
#undef HvInvDev_START_SEC_CODE
#define HVINVDEV_START_SEC_CODE
#endif
#ifdef HvInvDev_STOP_SEC_CODE
#undef HvInvDev_STOP_SEC_CODE
#define HVINVDEV_STOP_SEC_CODE
#endif

#ifdef HvInvDev_START_SEC_CODE_fc_HvInvDev
#undef HvInvDev_START_SEC_CODE_fc_HvInvDev
#define HVINVDEV_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef HvInvDev_STOP_SEC_CODE_fc_HvInvDev
#undef HvInvDev_STOP_SEC_CODE_fc_HvInvDev
#define HVINVDEV_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef HvInvDev_START_SEC_CODE_HvInvDev_Init
#undef HvInvDev_START_SEC_CODE_HvInvDev_Init
#define HVINVDEV_START_SEC_CODE
#endif
#ifdef HvInvDev_STOP_SEC_CODE_HvInvDev_Init
#undef HvInvDev_STOP_SEC_CODE_HvInvDev_Init
#define HVINVDEV_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef HVINVDEV_START_SEC_CODE
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef HVINVDEV_START_SEC_CODE
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CODE
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CODE
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CODE_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef HVINVDEV_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CODE_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINVDEV_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CALIBRATION_ONLINE_8
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINVDEV_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CALIBRATION_ONLINE_16
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINVDEV_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CALIBRATION_ONLINE_32
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINVDEV_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef HVINVDEV_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CONST_BOOLEAN
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINVDEV_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CONST_BOOLEAN
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CONST_8
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINVDEV_START_SEC_CONST_8
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CONST_8
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CONST_16
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINVDEV_START_SEC_CONST_16
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CONST_16
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CONST_32
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef HVINVDEV_START_SEC_CONST_32
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CONST_32
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_CONST_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef HVINVDEV_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_CONST_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINVDEV_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_NO_INIT_8
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINVDEV_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_NO_INIT_8
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_NO_INIT_16
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINVDEV_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_NO_INIT_16
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_NO_INIT_32
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINVDEV_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_NO_INIT_32
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef HVINVDEV_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_INIT_BOOLEAN
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINVDEV_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_INIT_8
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINVDEV_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_INIT_8
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_INIT_16
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINVDEV_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_INIT_16
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_INIT_32
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINVDEV_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_INIT_32
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef HVINVDEV_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_8
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_16
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_32
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_HVINVDEV
#endif
#ifdef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef HVINVDEV_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef HVINVDEV_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

#ifdef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef HVINVDEV_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef HVINVDEV_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef HVINVDEV_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_HVINVDEV
#endif

 
 
 
