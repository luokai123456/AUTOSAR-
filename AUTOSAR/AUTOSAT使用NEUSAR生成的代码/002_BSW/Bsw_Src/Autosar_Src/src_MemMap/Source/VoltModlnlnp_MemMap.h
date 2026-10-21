 
/*
********************************************************************************
*
*  File name: VoltModlnlnp_MemMap.h
*
*  Copyright 2021-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*/

/*** ASW Start ***/

#ifdef VoltModlnlnp_START_SEC_CALIB_BOOLEAN
#undef VoltModlnlnp_START_SEC_CALIB_BOOLEAN
#define VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif
#ifdef VoltModlnlnp_STOP_SEC_CALIB_BOOLEAN
#undef VoltModlnlnp_STOP_SEC_CALIB_BOOLEAN
#define VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#endif

#ifdef VoltModlnlnp_START_SEC_CALIB_8
#undef VoltModlnlnp_START_SEC_CALIB_8
#define VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_8
#endif
#ifdef VoltModlnlnp_STOP_SEC_CALIB_8
#undef VoltModlnlnp_STOP_SEC_CALIB_8
#define VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_8
#endif

#ifdef VoltModlnlnp_START_SEC_CALIB_16
#undef VoltModlnlnp_START_SEC_CALIB_16
#define VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_16
#endif
#ifdef VoltModlnlnp_STOP_SEC_CALIB_16
#undef VoltModlnlnp_STOP_SEC_CALIB_16
#define VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_16
#endif

#ifdef VoltModlnlnp_START_SEC_CALIB_32
#undef VoltModlnlnp_START_SEC_CALIB_32
#define VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_32
#endif
#ifdef VoltModlnlnp_STOP_SEC_CALIB_32
#undef VoltModlnlnp_STOP_SEC_CALIB_32
#define VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_32
#endif

#ifdef VoltModlnlnp_START_SEC_CALIB_UNSPECIFIED
#undef VoltModlnlnp_START_SEC_CALIB_UNSPECIFIED
#define VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif
#ifdef VoltModlnlnp_STOP_SEC_CALIB_UNSPECIFIED
#undef VoltModlnlnp_STOP_SEC_CALIB_UNSPECIFIED
#define VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#endif

#ifdef VoltModlnlnp_START_SEC_VAR_BOOLEAN
#undef VoltModlnlnp_START_SEC_VAR_BOOLEAN
#define VOLTMODLNLNP_START_SEC_VAR_NO_INIT_BOOLEAN
#endif
#ifdef VoltModlnlnp_STOP_SEC_VAR_BOOLEAN
#undef VoltModlnlnp_STOP_SEC_VAR_BOOLEAN
#define VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_BOOLEAN
#endif

#ifdef VoltModlnlnp_START_SEC_VAR_8
#undef VoltModlnlnp_START_SEC_VAR_8
#define VOLTMODLNLNP_START_SEC_VAR_NO_INIT_8
#endif
#ifdef VoltModlnlnp_STOP_SEC_VAR_8
#undef VoltModlnlnp_STOP_SEC_VAR_8
#define VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_8
#endif

#ifdef VoltModlnlnp_START_SEC_VAR_16
#undef VoltModlnlnp_START_SEC_VAR_16
#define VOLTMODLNLNP_START_SEC_VAR_NO_INIT_16
#endif
#ifdef VoltModlnlnp_STOP_SEC_VAR_16
#undef VoltModlnlnp_STOP_SEC_VAR_16
#define VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_16
#endif

#ifdef VoltModlnlnp_START_SEC_VAR_32
#undef VoltModlnlnp_START_SEC_VAR_32
#define VOLTMODLNLNP_START_SEC_VAR_NO_INIT_32
#endif
#ifdef VoltModlnlnp_STOP_SEC_VAR_32
#undef VoltModlnlnp_STOP_SEC_VAR_32
#define VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_32
#endif

#ifdef VoltModlnlnp_START_SEC_VAR_UNSPECIFIED
#undef VoltModlnlnp_START_SEC_VAR_UNSPECIFIED
#define VOLTMODLNLNP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef VoltModlnlnp_STOP_SEC_VAR_UNSPECIFIED
#undef VoltModlnlnp_STOP_SEC_VAR_UNSPECIFIED
#define VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef VoltModlnlnp_START_SEC_CODE
#undef VoltModlnlnp_START_SEC_CODE
#define VOLTMODLNLNP_START_SEC_CODE
#endif
#ifdef VoltModlnlnp_STOP_SEC_CODE
#undef VoltModlnlnp_STOP_SEC_CODE
#define VOLTMODLNLNP_STOP_SEC_CODE
#endif

#ifdef VoltModlnlnp_START_SEC_CODE_fc_VoltModlnInp
#undef VoltModlnlnp_START_SEC_CODE_fc_VoltModlnInp
#define VOLTMODLNLNP_START_SEC_CODE_UNSPECIFIED
#endif
#ifdef VoltModlnlnp_STOP_SEC_CODE_fc_VoltModlnInp
#undef VoltModlnlnp_STOP_SEC_CODE_fc_VoltModlnInp
#define VOLTMODLNLNP_STOP_SEC_CODE_UNSPECIFIED
#endif

#ifdef VoltModlnlnp_START_SEC_CODE_VoltModlnlnp_Init
#undef VoltModlnlnp_START_SEC_CODE_VoltModlnlnp_Init
#define VOLTMODLNLNP_START_SEC_CODE
#endif
#ifdef VoltModlnlnp_STOP_SEC_CODE_VoltModlnlnp_Init
#undef VoltModlnlnp_STOP_SEC_CODE_VoltModlnlnp_Init
#define VOLTMODLNLNP_STOP_SEC_CODE
#endif

/*** ASW End ***/



#ifdef VOLTMODLNLNP_START_SEC_CODE
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".asw_flash_safety_qm"
#undef VOLTMODLNLNP_START_SEC_CODE
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CODE
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CODE
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CODE_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section text=".foc_code"
#undef VOLTMODLNLNP_START_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CODE_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section text=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CODE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_8
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_8
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_16
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_16
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_32
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_32
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".XCP_CAL"
#undef VOLTMODLNLNP_START_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CALIBRATION_ONLINE_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CONST_BOOLEAN
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".foc_data"
#undef VOLTMODLNLNP_START_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CONST_BOOLEAN
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CONST_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CONST_8
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".foc_data"
#undef VOLTMODLNLNP_START_SEC_CONST_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CONST_8
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CONST_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CONST_16
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".foc_data"
#undef VOLTMODLNLNP_START_SEC_CONST_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CONST_16
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CONST_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CONST_32
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section rodata=".foc_data"
#undef VOLTMODLNLNP_START_SEC_CONST_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CONST_32
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CONST_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_CONST_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  rodata=".foc_data"
#undef VOLTMODLNLNP_START_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_CONST_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section rodata=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_CONST_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_BOOLEAN
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_BOOLEAN
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_8
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_8
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_16
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_16
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_32
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_32
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".foc_bss"
#undef VOLTMODLNLNP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_INIT_BOOLEAN
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNLNP_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_INIT_8
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNLNP_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_INIT_8
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_INIT_16
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNLNP_START_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_INIT_16
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_INIT_32
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNLNP_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_INIT_32
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".foc_data"
#undef VOLTMODLNLNP_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_8
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_16
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_32
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  bss=".bss_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section bss=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_8
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_8
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_8
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_16
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_16
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_16
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_32
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_32
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_32
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif
#ifdef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifdef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error A MemMap section is already open.
#endif
#define VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs startdata
#pragma ghs section  data=".data_share"
#undef VOLTMODLNLNP_START_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

#ifdef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#ifndef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#error No MemMap section is currently opened.
#endif
#undef VOLTMODLNLNP_MEMMAP_SECTION_OPEN
#pragma ghs section data=default
#pragma ghs enddata
#undef VOLTMODLNLNP_STOP_SEC_GLOBAL_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR_VOLTMODLNLNP
#endif

 
 
 
