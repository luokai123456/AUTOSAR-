 
/*
********************************************************************************
*
*  File name: AngOfstCal_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef AngOfstCal_START_SEC_CALIB_BOOLEAN
#undef AngOfstCal_START_SEC_CALIB_BOOLEAN
#define ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef AngOfstCal_STOP_SEC_CALIB_BOOLEAN
#undef AngOfstCal_STOP_SEC_CALIB_BOOLEAN
#define ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef AngOfstCal_START_SEC_CALIB_8
#undef AngOfstCal_START_SEC_CALIB_8
#define ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef AngOfstCal_STOP_SEC_CALIB_8
#undef AngOfstCal_STOP_SEC_CALIB_8
#define ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef AngOfstCal_START_SEC_CALIB_16
#undef AngOfstCal_START_SEC_CALIB_16
#define ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef AngOfstCal_STOP_SEC_CALIB_16
#undef AngOfstCal_STOP_SEC_CALIB_16
#define ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef AngOfstCal_START_SEC_CALIB_32
#undef AngOfstCal_START_SEC_CALIB_32
#define ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef AngOfstCal_STOP_SEC_CALIB_32
#undef AngOfstCal_STOP_SEC_CALIB_32
#define ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef AngOfstCal_START_SEC_CALIB_UNSPECIFIED
#undef AngOfstCal_START_SEC_CALIB_UNSPECIFIED
#define ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef AngOfstCal_STOP_SEC_CALIB_UNSPECIFIED
#undef AngOfstCal_STOP_SEC_CALIB_UNSPECIFIED
#define ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef AngOfstCal_START_SEC_VAR_BOOLEAN
#undef AngOfstCal_START_SEC_VAR_BOOLEAN
#define ANGOFSTCAL_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef AngOfstCal_STOP_SEC_VAR_BOOLEAN
#undef AngOfstCal_STOP_SEC_VAR_BOOLEAN
#define ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef AngOfstCal_START_SEC_VAR_8
#undef AngOfstCal_START_SEC_VAR_8
#define ANGOFSTCAL_START_SEC_VAR_NO_INIT_8
#endif
#ifdef AngOfstCal_STOP_SEC_VAR_8
#undef AngOfstCal_STOP_SEC_VAR_8
#define ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef AngOfstCal_START_SEC_VAR_16
#undef AngOfstCal_START_SEC_VAR_16
#define ANGOFSTCAL_START_SEC_VAR_NO_INIT_16
#endif
#ifdef AngOfstCal_STOP_SEC_VAR_16
#undef AngOfstCal_STOP_SEC_VAR_16
#define ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef AngOfstCal_START_SEC_VAR_32
#undef AngOfstCal_START_SEC_VAR_32
#define ANGOFSTCAL_START_SEC_VAR_NO_INIT_32
#endif
#ifdef AngOfstCal_STOP_SEC_VAR_32
#undef AngOfstCal_STOP_SEC_VAR_32
#define ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef AngOfstCal_START_SEC_VAR_UNSPECIFIED
#undef AngOfstCal_START_SEC_VAR_UNSPECIFIED
#define ANGOFSTCAL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef AngOfstCal_STOP_SEC_VAR_UNSPECIFIED
#undef AngOfstCal_STOP_SEC_VAR_UNSPECIFIED
#define ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef AngOfstCal_START_SEC_CODE
#undef AngOfstCal_START_SEC_CODE
#define ANGOFSTCAL_START_SEC_CODE
#endif
#ifdef AngOfstCal_STOP_SEC_CODE
#undef AngOfstCal_STOP_SEC_CODE
#define ANGOFSTCAL_STOP_SEC_CODE
#endif

#ifdef AngOfstCal_START_SEC_CODE_fc_AngOfstCal
#undef AngOfstCal_START_SEC_CODE_fc_AngOfstCal
#define ANGOFSTCAL_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef AngOfstCal_STOP_SEC_CODE_fc_AngOfstCal
#undef AngOfstCal_STOP_SEC_CODE_fc_AngOfstCal
#define ANGOFSTCAL_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef AngOfstCal_START_SEC_CODE_AngOfstCal_Init
#undef AngOfstCal_START_SEC_CODE_AngOfstCal_Init
#define ANGOFSTCAL_START_SEC_CODE
#endif
#ifdef AngOfstCal_STOP_SEC_CODE_AngOfstCal_Init
#undef AngOfstCal_STOP_SEC_CODE_AngOfstCal_Init
#define ANGOFSTCAL_STOP_SEC_CODE
#endif

/*** ASW End ***/


#ifdef ANGOFSTCAL_START_SEC_CODE
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef ANGOFSTCAL_START_SEC_CODE
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CODE
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CODE
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CODE_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef ANGOFSTCAL_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CODE_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_8
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_16
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_32
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef ANGOFSTCAL_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CONST_BOOLEAN
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGOFSTCAL_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CONST_BOOLEAN
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CONST_8
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGOFSTCAL_START_SEC_CONST_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CONST_8
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CONST_16
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGOFSTCAL_START_SEC_CONST_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CONST_16
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CONST_32
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef ANGOFSTCAL_START_SEC_CONST_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CONST_32
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_CONST_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef ANGOFSTCAL_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_CONST_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGOFSTCAL_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_NO_INIT_8
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGOFSTCAL_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_8
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_NO_INIT_16
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGOFSTCAL_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_16
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_NO_INIT_32
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGOFSTCAL_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_32
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef ANGOFSTCAL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_INIT_BOOLEAN
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGOFSTCAL_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_INIT_8
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGOFSTCAL_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_INIT_8
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_INIT_16
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGOFSTCAL_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_INIT_16
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_INIT_32
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGOFSTCAL_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_INIT_32
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef ANGOFSTCAL_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_8
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_16
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_32
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif
#ifdef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef ANGOFSTCAL_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

#ifdef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef ANGOFSTCAL_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef ANGOFSTCAL_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_ANGOFSTCAL
#endif

 
 
 
