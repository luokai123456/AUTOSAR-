 
/*
********************************************************************************
*
*  File name: ExtTqDes_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef ExtTqDes_START_SEC_CALIB_BOOLEAN
#undef ExtTqDes_START_SEC_CALIB_BOOLEAN
#define EXTTQDES_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef ExtTqDes_STOP_SEC_CALIB_BOOLEAN
#undef ExtTqDes_STOP_SEC_CALIB_BOOLEAN
#define EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef ExtTqDes_START_SEC_CALIB_8
#undef ExtTqDes_START_SEC_CALIB_8
#define EXTTQDES_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef ExtTqDes_STOP_SEC_CALIB_8
#undef ExtTqDes_STOP_SEC_CALIB_8
#define EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef ExtTqDes_START_SEC_CALIB_16
#undef ExtTqDes_START_SEC_CALIB_16
#define EXTTQDES_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef ExtTqDes_STOP_SEC_CALIB_16
#undef ExtTqDes_STOP_SEC_CALIB_16
#define EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef ExtTqDes_START_SEC_CALIB_32
#undef ExtTqDes_START_SEC_CALIB_32
#define EXTTQDES_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef ExtTqDes_STOP_SEC_CALIB_32
#undef ExtTqDes_STOP_SEC_CALIB_32
#define EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef ExtTqDes_START_SEC_CALIB_UNSPECIFIED
#undef ExtTqDes_START_SEC_CALIB_UNSPECIFIED
#define EXTTQDES_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef ExtTqDes_STOP_SEC_CALIB_UNSPECIFIED
#undef ExtTqDes_STOP_SEC_CALIB_UNSPECIFIED
#define EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef ExtTqDes_START_SEC_VAR_BOOLEAN
#undef ExtTqDes_START_SEC_VAR_BOOLEAN
#define EXTTQDES_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef ExtTqDes_STOP_SEC_VAR_BOOLEAN
#undef ExtTqDes_STOP_SEC_VAR_BOOLEAN
#define EXTTQDES_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef ExtTqDes_START_SEC_VAR_8
#undef ExtTqDes_START_SEC_VAR_8
#define EXTTQDES_START_SEC_VAR_NO_INIT_8
#endif
#ifdef ExtTqDes_STOP_SEC_VAR_8
#undef ExtTqDes_STOP_SEC_VAR_8
#define EXTTQDES_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef ExtTqDes_START_SEC_VAR_16
#undef ExtTqDes_START_SEC_VAR_16
#define EXTTQDES_START_SEC_VAR_NO_INIT_16
#endif
#ifdef ExtTqDes_STOP_SEC_VAR_16
#undef ExtTqDes_STOP_SEC_VAR_16
#define EXTTQDES_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef ExtTqDes_START_SEC_VAR_32
#undef ExtTqDes_START_SEC_VAR_32
#define EXTTQDES_START_SEC_VAR_NO_INIT_32
#endif
#ifdef ExtTqDes_STOP_SEC_VAR_32
#undef ExtTqDes_STOP_SEC_VAR_32
#define EXTTQDES_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef ExtTqDes_START_SEC_VAR_UNSPECIFIED
#undef ExtTqDes_START_SEC_VAR_UNSPECIFIED
#define EXTTQDES_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef ExtTqDes_STOP_SEC_VAR_UNSPECIFIED
#undef ExtTqDes_STOP_SEC_VAR_UNSPECIFIED
#define EXTTQDES_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef ExtTqDes_START_SEC_CODE
#undef ExtTqDes_START_SEC_CODE
#define EXTTQDES_START_SEC_CODE
#endif
#ifdef ExtTqDes_STOP_SEC_CODE
#undef ExtTqDes_STOP_SEC_CODE
#define EXTTQDES_STOP_SEC_CODE
#endif

#ifdef ExtTqDes_START_SEC_CODE_fc_ExtTqDes
#undef ExtTqDes_START_SEC_CODE_fc_ExtTqDes
#define EXTTQDES_START_SEC_CODE
#endif
#ifdef ExtTqDes_STOP_SEC_CODE_fc_ExtTqDes
#undef ExtTqDes_STOP_SEC_CODE_fc_ExtTqDes
#define EXTTQDES_STOP_SEC_CODE
#endif

#ifdef ExtTqDes_START_SEC_CODE_ExtTqDes_Init
#undef ExtTqDes_START_SEC_CODE_ExtTqDes_Init
#define EXTTQDES_START_SEC_CODE
#endif
#ifdef ExtTqDes_STOP_SEC_CODE_ExtTqDes_Init
#undef ExtTqDes_STOP_SEC_CODE_ExtTqDes_Init
#define EXTTQDES_STOP_SEC_CODE
#endif

/*** ASW End ***/

#ifdef EXTTQDES_START_SEC_CODE
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef EXTTQDES_START_SEC_CODE
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CODE
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CODE
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EXTTQDES_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CALIBRATION_ONLINE_8
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EXTTQDES_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CALIBRATION_ONLINE_16
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EXTTQDES_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CALIBRATION_ONLINE_32
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EXTTQDES_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef EXTTQDES_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CONST_BOOLEAN
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EXTTQDES_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CONST_BOOLEAN
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CONST_8
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EXTTQDES_START_SEC_CONST_8
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CONST_8
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CONST_16
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EXTTQDES_START_SEC_CONST_16
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CONST_16
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CONST_32
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".rodata"
#undef EXTTQDES_START_SEC_CONST_32
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CONST_32
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_CONST_UNSPECIFIED
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".rodata"
#undef EXTTQDES_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_CONST_UNSPECIFIED
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EXTTQDES_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_NO_INIT_8
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EXTTQDES_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_NO_INIT_8
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_NO_INIT_16
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EXTTQDES_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_NO_INIT_16
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_NO_INIT_32
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EXTTQDES_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_NO_INIT_32
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef EXTTQDES_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_INIT_BOOLEAN
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EXTTQDES_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_INIT_8
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EXTTQDES_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_INIT_8
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_INIT_16
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EXTTQDES_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_INIT_16
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_INIT_32
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EXTTQDES_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_INIT_32
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef EXTTQDES_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_8
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_16
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_32
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_EXTTQDES
#endif
#ifdef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef EXTTQDES_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef EXTTQDES_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

#ifdef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef EXTTQDES_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef EXTTQDES_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef EXTTQDES_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_EXTTQDES
#endif

 
 
 
