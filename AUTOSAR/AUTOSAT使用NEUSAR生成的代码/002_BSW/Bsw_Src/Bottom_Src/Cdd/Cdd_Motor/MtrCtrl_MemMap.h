#define MMAP_ERROR


/*************************
*******Code in ITCM*******
*************************/
#if defined(MTRCTRL_START_SEC_CODE_DEFAULT)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text =".foc_code" 
    #undef MTRCTRL_START_SEC_CODE_DEFAULT
    #undef MMAP_ERROR
/* MTRCTRL_START_SEC_CODE_DEFAULT */


#elif defined(MTRCTRL_STOP_SEC_CODE_DEFAULT)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section
    #undef MTRCTRL_STOP_SEC_CODE_DEFAULT
    #undef MMAP_ERROR
/* MTRCTRL_STOP_SEC_CODE_DEFAULT */


/*************************
*******Data in DTCM*******
*************************/
#elif defined(MTRCTRL_START_SEC_VAR_INIT_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data =".foc_data"
    #undef MTRCTRL_START_SEC_VAR_INIT_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_START_SEC_VAR_INIT_UNSPECIFIED */

#elif defined(MTRCTRL_STOP_SEC_VAR_INIT_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section
    #undef MTRCTRL_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_STOP_SEC_VAR_INIT_UNSPECIFIED */




/*************************
*******Bss in DTCM********
*************************/
#elif defined(MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section bss =".foc_bss" 
    #undef MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED */


#elif defined(MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section
    #undef MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED */

/*************************
*******Calibration in DTCM*****
*************************/
#elif defined(MTRCTRL_START_SEC_CALIB_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section data=".foc_data"//XCP_CAL
    #undef MTRCTRL_START_SEC_CALIB_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_START_SEC_CALIB_UNSPECIFIED */


#elif defined(MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section
    #undef MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED */

/*************************
*******Rodata in DTCM*****
*************************/
#elif defined(MTRCTRL_START_SEC_CONST_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section rodata=".foc_rodata"
    #undef MTRCTRL_START_SEC_CONST_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_START_SEC_CONST_UNSPECIFIED */


#elif defined(MTRCTRL_STOP_SEC_CONST_UNSPECIFIED)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section
    #undef MTRCTRL_STOP_SEC_CONST_UNSPECIFIED
    #undef MMAP_ERROR
/* MTRCTRL_STOP_SEC_CONST_UNSPECIFIED */


/*************************
*******Code in FLASH******
*************************/

#elif defined(MTRCTRL_START_SEC_CODE_FLS_DEFAULT)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section text=".foc_code_fls"
    #undef MTRCTRL_START_SEC_CODE_FLS_DEFAULT
    #undef MMAP_ERROR
/* MTRCTRL_START_SEC_CODE_FLS_DEFAULT */


#elif defined(MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT)
    #ifndef MMAP_ERROR
        error "No open memmap"
    #endif
    #pragma ghs section
    #undef MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT
    #undef MMAP_ERROR
/* MTRCTRL_STOP_SEC_CODE_FLS_DEFAULT */
#endif

#ifdef MMAP_ERROR
#error "MotorCtrl MemMap Error"
#undef MMAP_ERROR
#endif

