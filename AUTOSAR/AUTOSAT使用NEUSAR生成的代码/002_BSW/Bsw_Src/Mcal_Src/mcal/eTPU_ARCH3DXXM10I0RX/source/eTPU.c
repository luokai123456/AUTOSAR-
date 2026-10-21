/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : ETPU
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    eTPU.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eTPU MCAL driver.
*
*   @addtogroup eTPU
*   @{
*/
/* PRQA S 2052, 1526, 1594, 1599, 1756 EOF */
/* PRQA S 0491, 1281, 3332, 3218, 3334, 2004, 2053,2844,0310,1006,4399,4499,4391 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "eTPU.h" /* PRQA S 0380 */
#if (defined(RESOURCE_SUPPORT_ETPU))
#if ((SPWM_DEV_ERROR_DETECT == STD_ON) || (EBPPA_DEV_ERROR_DETECT == STD_ON)||(ETPU_DEV_ERROR_DETECT == STD_ON))
#include "Det.h"
#endif
#include "sPwm.h"
#include "EBPPA.h"
#include "SchM_eTPU.h"


#define ETPU_C_VENDOR_ID_PLUGIN             176
#define ETPU_C_AR_REL_MAJOR_VER				4
#define ETPU_C_AR_REL_MINOR_VER			    4
#define ETPU_C_AR_REL_REV_VER   		    0
#define ETPU_C_SW_MAJOR_VER                 3
#define ETPU_C_SW_MINOR_VER                 0
#define ETPU_C_SW_PATCH_VER                 0

#if (ETPU_VENDOR_ID_OUTPUT != ETPU_C_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : ETPU_C_VENDOR_ID_PLUGIN "
#endif
#if (ETPU_AR_REL_MAJOR_VER_OUTPUT != ETPU_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_C_AR_REL_MAJOR_VER "
#endif
#if (ETPU_AR_REL_MINOR_VER_OUTPUT != ETPU_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_C_AR_REL_MINOR_VER "
#endif
#if (ETPU_AR_REL_REVISION_VER_OUTPUT != ETPU_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETPU_C_AR_REL_REV_VER "
#endif
#if (ETPU_SW_MAJOR_VERSION_OUTPUT != ETPU_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETPU_C_SW_MAJOR_VER "
#endif
#if (ETPU_SW_MINOR_VERSION_OUTPUT != ETPU_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETPU_C_SW_MINOR_VER "
#endif
#if (ETPU_SW_PATCH_VERSION_OUTPUT != ETPU_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETPU_C_SW_PATCH_VER "
#endif

#define ETPU_START_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"
static VAR(eTPU_StatusType, ETPU_VAR) eTPU_gStatus = ETPU_UNINIT;
#define ETPU_STOP_SEC_VAR_SHARED_INIT
#include "eTPU_MemMap.h"

#if (ETPU_DEV_ERROR_DETECT == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static FUNC(Std_ReturnType, ETPU_CODE) eTPU_InitVerify \
( \
    P2CONST(eTPU_Total_ConfigType, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr
)
{
	VAR(Std_ReturnType, AUTOMATIC) u8eTPU_ret = E_NOT_OK;
#if (ETPU_PRECOMPILE_SUPPORT == STD_OFF)
    if (NULL_PTR == ConfigPtr)
#else
    if (NULL_PTR != ConfigPtr)
#endif
    {
        (void)Det_ReportError((uint16)ETPU_MODULE_ID_OUTPUT, (uint8)0U, ETPU_INIT_ID, (uint8)ETPU_E_PARAM_POINTER);
    }
    else
    {
        u8eTPU_ret = E_OK;
    }
	return u8eTPU_ret;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif // ETPU_DEV_ERROR_DETECT

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static FUNC(void, ETPU_CODE) eTPU_Init_func(P2CONST(eTPU_Total_ConfigType, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr)
{
    VAR(uint8, AUTOMATIC) count = 0U;
    VAR(uint8, AUTOMATIC) etpu_itc_cnt = 0U;
    static const uint32_t etpu_global[] = {0x000000FFU, 0x00000000U};
    static P2CONST(eTPU_ConfigType, ETPU_CONST, ETPU_APPL_CONST) eTPU_ConfigPtr = NULL_PTR;
    static const uint32_t etpu_code_buff[] = 
    {
        /*0x000*/ 0x40914096, 0x40914096, 0xC0A00080, 0x42DE42DE,
        /*0x010*/ 0x42DE40B4, 0x42DE40A8, 0x42DE40B4, 0x42DE40A8,
        /*0x020*/ 0x40BE42DE, 0x40BE42DE, 0x40BE42DE, 0x40BE42DE,
        /*0x030*/ 0x40BE40B4, 0x40BE40A8, 0x40BE40B4, 0x40BE40A8,
        /*0x040*/ 0x42DE42DE, 0x42DE42DE, 0x42DE42DE, 0x42DE00CE,
        /*0x050*/ 0x00CB00C2, 0x40D040F1, 0x40D040F1, 0x40D040F1,
        /*0x060*/ 0x40D040F1, 0x40D040F1, 0x40D040F1, 0x40D040F1,
        /*0x070*/ 0x42DE42DE, 0x42DE42DE, 0x40D040F1, 0x40D040F1,
        /*0x080*/ 0x42DE42DE, 0x42DE42DE, 0x00FD00FF, 0x00F940F7,
        /*0x090*/ 0x40F50101, 0x01250125, 0x416C416E, 0x416C416E,
        /*0x0A0*/ 0x416C416E, 0x416C416E, 0x41284145, 0x41284145,
        /*0x0B0*/ 0x01250125, 0x01250125, 0x01250125, 0x01250125,
        /*0x0C0*/ 0x41C341C3, 0x41C341C3, 0x017E0170, 0x01A201A2,
        /*0x0D0*/ 0x81C141B2, 0x42DE418A, 0x81C141B2, 0x42DE418A,
        /*0x0E0*/ 0x41BD81C1, 0x419B42DE, 0x41BD81C1, 0x419B42DE,
        /*0x0F0*/ 0x41BD41B2, 0x419B418A, 0x41BD41B2, 0x419B418A,
        /*0x100*/ 0x42DE42DE, 0x42DE42DE, 0xC1C442DE, 0x42DE42DE,
        /*0x110*/ 0x42DE42DE, 0x42DE42DE, 0x42DE42DE, 0x42DE42DE,
        /*0x120*/ 0xC1E4C201, 0xC1DDC201, 0xC1E4C201, 0xC1DDC201,
        /*0x130*/ 0xC1E4C201, 0xC1DDC201, 0xC1E4C201, 0xC1DDC201,
        /*0x140*/ 0x429A429A, 0x429A429A, 0x42DE42DE, 0x42DE42DE,
        /*0x150*/ 0x42DE42DE, 0x42A142A1, 0x42A142A1, 0x42A142A1,
        /*0x160*/ 0x42DE42DE, 0x42DE42DE, 0x42A142A1, 0x42A142A1,
        /*0x170*/ 0x42DE42DE, 0x42DE42DE, 0x42A142A1, 0x42DE42DE,
        /*0x180*/ 0x42A342A3, 0x42A342A3, 0x42DE42DE, 0x42DE42DE,
        /*0x190*/ 0x42DE42DE, 0x42AD42AD, 0x42CB42AD, 0x42AD42CB,
        /*0x1A0*/ 0x42DE42DE, 0x42DE42DE, 0x42CB42AD, 0x42AD42CB,
        /*0x1B0*/ 0x42DC42C9, 0x42C942DC, 0x42AD42AD, 0x42C942C9,
        /*0x1C0*/ 0x03B003B0, 0x03B003B0, 0x42F942F7, 0x03B003B0,
        /*0x1D0*/ 0xC37AC37A, 0xC37AC37A, 0xC37AC37A, 0xC37AC37A,
        /*0x1E0*/ 0x4306433C, 0x43234355, 0x4306433C, 0x43234355,
        /*0x1F0*/ 0x43724376, 0x43744378, 0x43724376, 0x43744378,
        /*0x200*/ 0x580337E5, 0x0C0D2EBE, 0x0C02ABA2, 0xF3B810E7,
        /*0x210*/ 0xCFFFF980, 0x4FF00FFF, 0x000C2439, 0x1F7E3FFF,
        /*0x220*/ 0xBFF37B85, 0xF3F011C7, 0xFB3F0EFB, 0x4F58FDFE,
        /*0x230*/ 0xF7F01587, 0x0FFFFFFE, 0x4F38FBFE, 0xF7F01707,
        /*0x240*/ 0x0FFFFF7E, 0xBFEFFB84, 0xBF787B85, 0xBFE80B80,
        /*0x250*/ 0xF7F01327, 0x7C193FDF, 0xBFEFFB84, 0xBF787B85,
        /*0x260*/ 0x7FF83FDF, 0x000BF019, 0xF0D013A7, 0xF3D813E7,
        /*0x270*/ 0x41FFFFFF, 0xF3D013E7, 0x41FFFFFF, 0x42FFFFFF,
        /*0x280*/ 0xBFEFFB84, 0xBF787B85, 0xCFEFF980, 0xF51014A7,
        /*0x290*/ 0x7FF83FDF, 0xBFEFFB82, 0xF7F01328, 0xBFFFFF81,
        /*0x2A0*/ 0xFFF83EF9, 0x0FF2ABDA, 0xCFFF7980, 0x1F1E2FFF,
        /*0x2B0*/ 0x000BF019, 0xF0D01607, 0xF7F01627, 0x4AFFFFFF,
        /*0x2C0*/ 0x49FFFFFF, 0xBFFE7B84, 0x7F7E7E7F, 0xAFFFFB85,
        /*0x2D0*/ 0xFFF83EF9, 0x0FF2ABDA, 0xCFFF7980, 0x1F1E2FFF,
        /*0x2E0*/ 0x000BF019, 0xF0D01787, 0xF7F01627, 0x49FFFFFF,
        /*0x2F0*/ 0xF7F01627, 0x4AFFFFFF, 0xCFE9FA85, 0x7FF83F9F,
        /*0x300*/ 0x0C02ABA2, 0xC7FFF980, 0x0FFFFE7E, 0x4FF00FFF,
        /*0x310*/ 0xF5781927, 0x5B7FFFF9, 0xF5381927, 0x593FFFFF,
        /*0x320*/ 0x5A5FFFFF, 0x4FE9F6BF, 0xD73FFA01, 0x0FFFFE7E,
        /*0x330*/ 0xF7F01887, 0x4FF33FFF, 0xF7F01867, 0x0FFFFEFE,
        /*0x340*/ 0xBDFB4F81, 0xBFEFFB80, 0x1C1BFEFF, 0xF4B01AC7,
        /*0x350*/ 0x000E7419, 0xF7D01C0B, 0xCFFF3A82, 0xF3B01BA7,
        /*0x360*/ 0xFFFF7EF9, 0xFFF05E47, 0xCFEFF885, 0xFFF05E47,
        /*0x370*/ 0xCFEFF886, 0xF3D01C07, 0xFF7FFEFB, 0x47EFF6BF,
        /*0x380*/ 0xF2501E07, 0xBFEFFF81, 0xBFEFFB80, 0x1C1BFEFF,
        /*0x390*/ 0xF4B01CE7, 0x00037419, 0xF7D01E0B, 0xCFFF3A82,
        /*0x3A0*/ 0xF3B01DC7, 0xFFFF7EF9, 0xFFF05E47, 0xCFEFF885,
        /*0x3B0*/ 0xFFF05E47, 0xCFEFF886, 0xF3D01E07, 0xFF7FFEFB,
        /*0x3C0*/ 0x47EFF6BF, 0xBFEFFB84, 0x00082419, 0xF7F01A07,
        /*0x3D0*/ 0x000E3419, 0xF7F02027, 0x4F3FFFFF, 0xF7F02027,
        /*0x3E0*/ 0x4F5FFFFF, 0xCFEFF981, 0x0D02AB82, 0xCFFFF981,
        /*0x3F0*/ 0x47F8FFFF, 0xF7F01F27, 0x7FFFFDFE, 0xF7F01F27,
        /*0x400*/ 0x7FFFFBFE, 0x4FF8FFE5, 0xCFEFF981, 0xF6D020E7,
        /*0x410*/ 0x4FF33FFF, 0xF7F02127, 0x000D3419, 0x4FF00FFF,
        /*0x420*/ 0x000C3419, 0x7FFFFFDF, 0xF5302227, 0x7FFFFFDF,
        /*0x430*/ 0xF55021E7, 0xBFEFFF83, 0xF7C02202, 0xBFEFFB82,
        /*0x440*/ 0x00083419, 0xCFFFF902, 0xBFEFFF80, 0x1FEFFBDF,
        /*0x450*/ 0xB7F87A85, 0xF0902307, 0xF7F02327, 0x4F3FFFFF,
        /*0x460*/ 0x4F5FFFFF, 0x1F133FFF, 0x001B7419, 0xBFF84B84,
        /*0x470*/ 0x1FEFFBDF, 0xB7F87A85, 0xF0902427, 0xF7F02447,
        /*0x480*/ 0x49FFFFFF, 0x4AFFFFFF, 0x1F132FFF, 0xFB390EFB,
        /*0x490*/ 0x500FF7FF, 0xCFEFF981, 0xF6982027, 0x47FFF7FF,
        /*0x4A0*/ 0xBFEFFB84, 0x00187419, 0xF39025EC, 0x1C1BFEFF,
        /*0x4B0*/ 0xF0902787, 0xF7E02788, 0xBFFFFB84, 0xF3D02647,
        /*0x4C0*/ 0x0802FBAA, 0xF0D026E7, 0x1C1BFEFF, 0xF0902787,
        /*0x4D0*/ 0xFFF97EFB, 0xF7F02A67, 0xBFFE7B82, 0x1C1BFEFF,
        /*0x4E0*/ 0xF0902787, 0xBEE2AB80, 0xBFFFFB84, 0xCFFFF980,
        /*0x4F0*/ 0xBFEFFF84, 0x1FEFFBDF, 0xB7F87A85, 0xF0902847,
        /*0x500*/ 0xF7F02867, 0x49FFFFFF, 0x4AFFFFFF, 0x1F132FFF,
        /*0x510*/ 0xF7F93EFB, 0xBFEFFB84, 0x00187419, 0xF390298C,
        /*0x520*/ 0x1C1BFEFF, 0xF0902C67, 0xF7E02C68, 0xBFFFFB84,
        /*0x530*/ 0xF3D029E7, 0x0802FBAA, 0xF0D02BC7, 0x1C1BFEFF,
        /*0x540*/ 0xF0902C67, 0x0C037E1E, 0xDFFFDA82, 0xCFEFF982,
        /*0x550*/ 0x0802FBAA, 0xF0D02B67, 0xCFEF3981, 0xFFFF7EF9,
        /*0x560*/ 0x4FFFF7FF, 0x0EF2ABFA, 0xCFFFF981, 0xCFEFF982,
        /*0x570*/ 0x0002A439, 0xC7FFF982, 0x1C1BFEFF, 0xF0902C67,
        /*0x580*/ 0xBEE2AB80, 0xBFFFFB84, 0xCFFFF980, 0xBFEFFF84,
        /*0x590*/ 0x1FEFFBDF, 0xB7F87A85, 0xF0902D27, 0xF7F02D47,
        /*0x5A0*/ 0x4F3FFFFF, 0x4F5FFFFF, 0x1F1E3FFF, 0xF7F8CEFB,
        /*0x5B0*/ 0xF7F02507, 0x1FF5FFED, 0xF7F028A7, 0x1FF5FFED,
        /*0x5C0*/ 0x4FF8FDFE, 0xCFEBFE82, 0xFFE9FAD9, 0xBFE80B80,
        /*0x5D0*/ 0xBF192B8A, 0xBFEFFF81, 0x1F7E3FFF, 0xBFF34F89,
        /*0x5E0*/ 0xFFF05E47, 0xDB2F0884, 0xFFF05E47, 0xCFEFF885,
        /*0x5F0*/ 0xF7F03027, 0xBFFE7B86, 0x4FF8FDFE, 0xCBFAF901,
        /*0x600*/ 0x0FFFFEFE, 0xF3B03087, 0x580006A5, 0x4FF33FFF,
        /*0x610*/ 0x495FFFFF, 0xBFEFFF81, 0x000BF019, 0xF0D03127,
        /*0x620*/ 0x4AFFFFFF, 0x0FFFFFFF, 0xCFE8FA8A, 0x1F1E2FFF,
        /*0x630*/ 0x49FFFFFF, 0x000BF019, 0xF0D03207, 0x4AFFFFFF,
        /*0x640*/ 0xBFFE7B86, 0x7F7E4E7F, 0xBFFFFF89, 0xBFEFFF80,
        /*0x650*/ 0xBFFFFF8A, 0xFFF05E47, 0xCFEFF884, 0xFFF05E47,
        /*0x660*/ 0xCFEFF885, 0xFFFF3EF9, 0xF7FF7EF9, 0xBFEFFB89,
        /*0x670*/ 0x00083419, 0xF3F03427, 0xFFF9CEFB, 0xFFFF3EF9,
        /*0x680*/ 0xFFFF7EF9, 0x0FFFFFFF, 0xCFEFF981, 0x0002A019,
        /*0x690*/ 0xF0D035A7, 0xBDEFAF87, 0xCFFFF981, 0x1FEFFBDF,
        /*0x6A0*/ 0xBFEFFF83, 0xBF682F81, 0xBF7E3F8B, 0xF7F03627,
        /*0x6B0*/ 0xFB3F0EFB, 0xBFEFFF87, 0x1FEFFBDF, 0xBFEFFF83,
        /*0x6C0*/ 0xBF787B86, 0x47FFF7FF, 0xF31835A7, 0xBFEFFB86,
        /*0x6D0*/ 0xBFE82B8B, 0xFFF83EFB, 0x49FFFFFF, 0x0008F019,
        /*0x6E0*/ 0xF0D03747, 0x4AFFFFFF, 0xBF1E4F89, 0xBFEFFF81,
        /*0x6F0*/ 0xAFFFFF8B, 0xF31835A7, 0xBFEFFB89, 0x00083419,
        /*0x700*/ 0xF7F9CEFB, 0xF3105BC7, 0xF7D035A7, 0x0FFFFFFF,
        /*0x710*/ 0xF3983907, 0x4FE006AD, 0xF7F03947, 0x000C4419,
        /*0x720*/ 0x4FE336AD, 0x000D4419, 0xF7703A67, 0xBFFFFF8A,
        /*0x730*/ 0x5AFFFFFF, 0xF3F83A27, 0x0FFFFFFE, 0xF7F03B27,
        /*0x740*/ 0x0C02ABA2, 0xF7F03B27, 0x0C02ABC2, 0x59FFFFFF,
        /*0x750*/ 0xF3F83B07, 0x0FFFFF7E, 0xF7F03B27, 0x0FF2ABD2,
        /*0x760*/ 0x0FF2ABB2, 0xDF38F982, 0xBFFFFB00, 0x000FA439,
        /*0x770*/ 0xC7FFF983, 0x59FFFFFF, 0xF3F83C47, 0x0FFFFF7E,
        /*0x780*/ 0xF7F03D47, 0x0FF2ABD2, 0xF7F03D47, 0x0FF2ABB2,
        /*0x790*/ 0x5AFFFFFF, 0xF3F83D27, 0x0FFFFFFE, 0xF7F03D47,
        /*0x7A0*/ 0x0C02ABA2, 0x0C02ABC2, 0xCFFFF982, 0xCFEFF983,
        /*0x7B0*/ 0xF5103F87, 0xCFEFF982, 0x0C020BBA, 0xF3F03E47,
        /*0x7C0*/ 0x000F3411, 0x000F3431, 0x3F330FB1, 0x000F7459,
        /*0x7D0*/ 0x3F123FD2, 0x14033F86, 0x3B330FB1, 0xF0D83F47,
        /*0x7E0*/ 0xF7F03F67, 0x000FA439, 0x03FFA479, 0xCFFFF980,
        /*0x7F0*/ 0xF21840A7, 0xBFEFFB82, 0xB7E80B8B, 0xF7F040A7,
        /*0x800*/ 0x1F382FFF, 0xF21840A7, 0xBFEFFB8B, 0xBFE80B82,
        /*0x810*/ 0x1F192FFF, 0xBFFE4F8B, 0xCFEFF880, 0x3FF20874,
        /*0x820*/ 0xBF387B80, 0x3FF20874, 0xBFEFFB8C, 0xBF387B8C,
        /*0x830*/ 0xCFEFF984, 0xF55042C7, 0xBFEFFB80, 0xBFE80B84,
        /*0x840*/ 0x1C19FEFF, 0xF0D842A7, 0xBFEFFB85, 0x1C19FEFF,
        /*0x850*/ 0xF0D042C7, 0xFFFF3EF9, 0xCFEFF982, 0x0812FBEA,
        /*0x860*/ 0xF0D84367, 0x0002A019, 0xF0D05007, 0xCFEFF984,
        /*0x870*/ 0xF5104467, 0xBFEFFB80, 0x2FF80FF3, 0xBFEFFF83,
        /*0x880*/ 0x1C3BFEFF, 0xF4D04467, 0xBFFFFB00, 0xBFEFFB8A,
        /*0x890*/ 0x1C1E0FFF, 0xB7F97B82, 0xBFFE7B8A, 0xCFEFF983,
        /*0x8A0*/ 0xF5104607, 0xBFEFFB82, 0xBFE80B86, 0x1C19FEFF,
        /*0x8B0*/ 0xF0904FA7, 0x000FA459, 0xF7F04FA7, 0xCFFFF983,
        /*0x8C0*/ 0xF5504A67, 0xBFEFFB82, 0xBFE80B88, 0x1C19FEFF,
        /*0x8D0*/ 0xF09049A7, 0x001FA419, 0xCFFFF983, 0xCFEFF980,
        /*0x8E0*/ 0xF6D04767, 0xF7F04787, 0x03FFA419, 0x001FA419,
        /*0x8F0*/ 0xCFF9F980, 0xB3F97B82, 0xCFEFF982, 0xF5904867,
        /*0x900*/ 0x59FFFFFF, 0xF7F048A7, 0x0FFFFF7E, 0x5AFFFFFF,
        /*0x910*/ 0x0FFFFFFE, 0xF3F84927, 0x00091409, 0xF7F04947,
        /*0x920*/ 0x1DF94FE7, 0x1EF94FE7, 0x58FFFFFF, 0xF7F04FA7,
        /*0x930*/ 0x7FFA4FF5, 0xBFEFFB87, 0x1C38FEFF, 0xF0904FA7,
        /*0x940*/ 0x002FA439, 0xF7F05307, 0xCFFFF983, 0xF5904FA7,
        /*0x950*/ 0xBFEFFB82, 0xBFE80B89, 0x1C38FEFF, 0xF0904F67,
        /*0x960*/ 0x004FA459, 0xCFFFF983, 0xCFEFF980, 0xF6D04BC7,
        /*0x970*/ 0xF7F04BE7, 0x03FFA479, 0x000FA439, 0xCFF8F980,
        /*0x980*/ 0xB7F97B82, 0xCFEFF982, 0xF5904CC7, 0x5AFFFFFF,
        /*0x990*/ 0xF7F04D07, 0x0FFFFFFE, 0x59FFFFFF, 0x0FFFFF7E,
        /*0x9A0*/ 0xCFEFF880, 0x3FF20874, 0xBF387B80, 0x3FF20874,
        /*0x9B0*/ 0xBFC91B8C, 0xF3F84E27, 0xBF387B8C, 0xF7F04E47,
        /*0x9C0*/ 0x1DF94FE7, 0x1EF94FE7, 0xCFEFF982, 0xF5904EE7,
        /*0x9D0*/ 0x59FFFFFF, 0xF7F04F27, 0x0FFFFF7E, 0x5AFFFFFF,
        /*0x9E0*/ 0x0FFFFFFE, 0x4FFFFFED, 0x000A4411, 0xBFEFFB82,
        /*0x9F0*/ 0xB3F87B82, 0xCFEFF983, 0xF7F05047, 0x0C22AB82,
        /*0xA00*/ 0xCFEFF983, 0x0F92ABF2, 0xCFFFF983, 0xCFEFF984,
        /*0xA10*/ 0xF5985307, 0xCFEFF983, 0xF5185307, 0x4FFFFFE9,
        /*0xA20*/ 0xBFEFFB82, 0x1F1E3FFF, 0xBFE80B8E, 0x2F19FFE8,
        /*0xA30*/ 0xF3585187, 0x10070F8E, 0xF2F852C7, 0x1F333FFF,
        /*0xA40*/ 0xBFEFFB82, 0xBFE80B8D, 0x2F19FFE8, 0xF3585267,
        /*0xA50*/ 0x10070F8E, 0x1F3E2FFF, 0xF7F05327, 0x7FFFFF5F,
        /*0xA60*/ 0x4FFFFFED, 0x47EFF6BF, 0xF39053A7, 0xF7F05407,
        /*0xA70*/ 0x5BE0F6A5, 0xF3F85407, 0x5AE0F6A5, 0x59FFFFFF,
        /*0xA80*/ 0xF73FFEFB, 0xDFF7FA01, 0xAFFFFB00, 0xF3F85527,
        /*0xA90*/ 0x5BE0F6A5, 0xF7705587, 0x0FFFFE7E, 0xF7F05587,
        /*0xAA0*/ 0xCFFFF901, 0xF7785587, 0x0FFFFEFE, 0xCFFFF901,
        /*0xAB0*/ 0xD73FFA01, 0x7FEFFFFF, 0xCFEFF983, 0xF5D85627,
        /*0xAC0*/ 0x0FF91FE7, 0xF39056E7, 0xF61056C7, 0xCFEFF980,
        /*0xAD0*/ 0x3FF27874, 0xF7D056E8, 0xBFFFFB00, 0xCFEFF980,
        /*0xAE0*/ 0xF6D05767, 0xF7F05787, 0x1EFB4FFF, 0x000B4439,
        /*0xAF0*/ 0xBFFFFF81, 0xCFFFF981, 0xCFEFF983, 0xF5905847,
        /*0xB00*/ 0x0FD2ABF2, 0xCFFFF983, 0xF5105887, 0x53FFFFFF,
        /*0xB10*/ 0xF3D858E7, 0xF7F05907, 0x59FFFFFF, 0x5AFFFFFF,
        /*0xB20*/ 0x47EFF6BF, 0xF7F055C7, 0x4FFFF7FF, 0xDFE7F981,
        /*0xB30*/ 0x0002A019, 0xF0D85B67, 0xCFEFF983, 0xF5D85B47,
        /*0xB40*/ 0xCFEFF981, 0x00020419, 0xCFEFF980, 0x00021419,
        /*0xB50*/ 0x1C59AEFF, 0xF0D85B67, 0xCFEFF980, 0xF6D05B27,
        /*0xB60*/ 0xAEFB4F81, 0xADFB4F81, 0x00091401, 0x0FFFFFFF,
        /*0xB70*/ 0xF7F059C7, 0x4FFFF7FF, 0xF3305C27, 0x00091409,
        /*0xB80*/ 0x0C0A1FA2, 0xF2905C67, 0x0C0A1FC2, 0xF2D05CA7,
        /*0xB90*/ 0x0C1A1F82, 0xF2105CE7, 0x0C2A1F82, 0xF2505D27,
        /*0xBA0*/ 0x0C4A1F82, 0xF4105D67, 0x0C8A1F82, 0xE3905DA7,
        /*0xBB0*/ 0x0D0A1F82, 0xE3D05DE7, 0x0E0A1F82, 0x9FFA4F00,
        /*0xBC0*/ 0xFFFFBEF9, 0x47EFF6BF, 0x00021411, 0x00071411,
        /*0xBD0*/ 0x00011411, 0xFFFFCEF9, 0x00001411, 0xF7F05F67,
        /*0xBE0*/ 0x4FF00FFF, 0xF7F05F67, 0x4FF33FFF, 0x48E9F6B9,
        /*0xBF0*/ 0xFF38FEFB, 0x5B7FFFFF, 0x7FE94FE7, 0xF4106027,
        /*0xC00*/ 0x0FFFFEFE, 0xF3B06087, 0x0FFFFF7E, 0x0FFFFFFE,
        /*0xC10*/ 0xCFFFF900, 0xC7FFF901, 0x7FE94FE7, 0x0002A019,
        /*0xC20*/ 0xF0F062C7, 0x1C1E1FFF, 0xBFFE7B80, 0x0C0FAEBE,
        /*0xC30*/ 0xF4386287, 0xCFFFF980, 0x0C0E1E1E, 0xFFF07007,
        /*0xC40*/ 0x1C531FFF, 0xBFF37B80, 0x000FA439, 0xCFFFF981,
        /*0xC50*/ 0xBFEFFF83, 0x6F782E7F, 0xFFD07007, 0xFFF07347,
        /*0xC60*/ 0x000E7419, 0xF4386407, 0x0FFFFEFE, 0xFFE07008,
        /*0xC70*/ 0x1C131FFF, 0xBFF37B80, 0x0C0FAE3E, 0xCFFFF981,
        /*0xC80*/ 0xBFEFFB80, 0xBFEFFF83, 0x6F782E7F, 0x7FE94FE7,
        /*0xC90*/ 0x0002A019, 0xF0F065C7, 0x1C1E1FFF, 0xF4386767,
        /*0xCA0*/ 0x0FFFFEFE, 0x0C037E1E, 0xBDFFAB80, 0xCFFFF980,
        /*0xCB0*/ 0xBFEFFF83, 0x6F782E7F, 0xFFD07007, 0xBFFE7B80,
        /*0xCC0*/ 0x0C0FAEBE, 0xF4386707, 0xCFFFF981, 0x0FFFFE7E,
        /*0xCD0*/ 0xFFF07007, 0x1C131FFF, 0xFFF07347, 0x00037419,
        /*0xCE0*/ 0xBFEFFB80, 0xBFEFFF83, 0x7F782E7F, 0x0FFFFFFF,
        /*0xCF0*/ 0x7FE94FE7, 0x0002A019, 0xF0F068E7, 0x1C1E1FFF,
        /*0xD00*/ 0xF4306A87, 0x0FFFFE7E, 0x0C037E9E, 0xBDFFAB80,
        /*0xD10*/ 0xCFFFF980, 0xBFEFFF83, 0x6F782E7F, 0xFFD07007,
        /*0xD20*/ 0xBFFE7B80, 0x0C0FAE3E, 0xF4306A27, 0xCFFFF981,
        /*0xD30*/ 0x0FFFFEFE, 0xFFF07007, 0x1C131FFF, 0xFFF07347,
        /*0xD40*/ 0x00037419, 0xBFEFFB80, 0xBFEFFF83, 0x7F782E7F,
        /*0xD50*/ 0x0FFFFFFF, 0x7FE94FE7, 0x0002A019, 0xF0F06CA7,
        /*0xD60*/ 0x1C1E1FFF, 0xBFFE7B80, 0x0C0FAE3E, 0xF4306C67,
        /*0xD70*/ 0xCFFFF980, 0x0C0E1E9E, 0xFFF07007, 0x1C531FFF,
        /*0xD80*/ 0xBFF37B80, 0x000FA439, 0xCFFFF981, 0xBFEFFF83,
        /*0xD90*/ 0x6F782E7F, 0xFFD07007, 0xFFF07347, 0x000E7419,
        /*0xDA0*/ 0xF4306DE7, 0x0FFFFE7E, 0xFFE07008, 0x1C131FFF,
        /*0xDB0*/ 0xBFF37B80, 0x0C0FAEBE, 0xCFFFF981, 0xBFEFFB80,
        /*0xDC0*/ 0xBFEFFF83, 0x6F782E7F, 0xF29060C7, 0xF7D06F47,
        /*0xDD0*/ 0xF2906467, 0xF7D06F47, 0xF2906787, 0xF7D06F47,
        /*0xDE0*/ 0xF2906AA7, 0xF7D06F47, 0xBFEFFF83, 0xFFF07007,
        /*0xDF0*/ 0x000B1419, 0xBFC5FF83, 0xBFFE7B80, 0x6F7E2E7F,
        /*0xE00*/ 0xBFEFFB85, 0xBF587A85, 0xF0907167, 0xCFEFF985,
        /*0xE10*/ 0x0002A439, 0xCFFFF985, 0x0002A019, 0xF0D07167,
        /*0xE20*/ 0xCFEFF982, 0x0E02AB82, 0xCFFFF982, 0xCFEFF981,
        /*0xE30*/ 0x0802FBAA, 0xF0D07327, 0xBFEFFB84, 0xBF587A84,
        /*0xE40*/ 0xF0907327, 0xCFEFF984, 0x0002A439, 0xCFFFF984,
        /*0xE50*/ 0x0002A019, 0xF0D07327, 0xCFEFF982, 0x0D02AB82,
        /*0xE60*/ 0xCFFFF982, 0xFFDFCEF9, 0xBFFFFB80, 0xCFFFF901,
        /*0xE70*/ 0xBFEFFB82, 0xBDE80F81, 0xBFF97B82, 0x1C79FEFF,
        /*0xE80*/ 0xF49875E7, 0xCFEF3884, 0xCFFF7886, 0xCFEFF885,
        /*0xE90*/ 0xCFFFF887, 0xCFEFF982, 0xCFFFF983, 0xBFFFFB02,
        /*0xEA0*/ 0x000FA419, 0x00000400, 0xCFFFF884, 0x000FA419,
        /*0xEB0*/ 0x00000400, 0xCFFFF885, 0xCFFFF902, 0xFFDFCEF9,
        /*0xEC0*/ 0xCFEFF001, 0xF7F07787, 0x0C42AB82, 0xCFEFF001,
        /*0xED0*/ 0xF7F07787, 0x0E02AB82, 0xCFEFF001, 0xF7F07787,
        /*0xEE0*/ 0x0D02AB82, 0xCFEFF001, 0xF7F07787, 0x0C82AB82,
        /*0xEF0*/ 0xF33077E7, 0x00097409, 0x0E01CB82, 0xF2507827,
        /*0xF00*/ 0x0D01CB82, 0xF2107867, 0x0C81CB82, 0xF2D078A7,
        /*0xF10*/ 0x0C41CB82, 0xF29078E7, 0x0C21CB82, 0xF4107927,
        /*0xF20*/ 0x0C01CBA2, 0xF7107967, 0x0E00DB82, 0xE3D079A7,
        /*0xF30*/ 0x0D00DB82, 0xE39079E7, 0x0C80DB82, 0x4FEFF6BF,
        /*0xF40*/ 0xC7FFF001,
    };

    for(etpu_itc_cnt = 0U; etpu_itc_cnt < (uint8)ETPU_CONFIG_INSTANCE_MAX; etpu_itc_cnt++)
    {
    	switch (etpu_itc_cnt)
    	{
    		case (uint8)ETPU_CONFIG_INSTANCE_A_B:
    			eTPUInstance[etpu_itc_cnt].eTPU = (eTPU_Type *)0xFFDC0000U;
    			eTPUInstance[etpu_itc_cnt].code_start = 0xFFDD0000U;
    			eTPUInstance[etpu_itc_cnt].data_ram_start = 0xFFDC8000U;
    			eTPUInstance[etpu_itc_cnt].data_ram_end = 0xFFDCBFFFU;
    			eTPUInstance[etpu_itc_cnt].data_ram_ext = 0xFFDCC000U;
    			eTPUInstance[etpu_itc_cnt].free_param = (uint32 *)0;
    			eTPUInstance[etpu_itc_cnt].double_engle = 1;
    			break;
    		case (uint8)ETPU_CONFIG_INSTANCE_C:
    			eTPUInstance[etpu_itc_cnt].eTPU = (eTPU_Type *)0xFBF80000U;
    			eTPUInstance[etpu_itc_cnt].code_start = 0xFBF90000U;
    			eTPUInstance[etpu_itc_cnt].data_ram_start = 0xFBF88000U;
    			eTPUInstance[etpu_itc_cnt].data_ram_end = 0xFBF8BFFFU;
    			eTPUInstance[etpu_itc_cnt].data_ram_ext = 0xFBF8C000U;
    			eTPUInstance[etpu_itc_cnt].free_param = (uint32 *)0;
    			eTPUInstance[etpu_itc_cnt].double_engle = 0;
    			break;
    		default:
    			/*do nothing*/
    			break;
    	}
    }

    #if ( ETPU_PRECOMPILE_SUPPORT == STD_ON )
        (void)ConfigPtr;
        eTPU_ConfigPtr = etpuConfig;
    #else 
        eTPU_ConfigPtr = ConfigPtr->etpuConfigPtr;
    #endif

    for (count = 0U; count < ETPU_INSTANCE_NUM; count++)
    {
    #if ( ETPU_INSTANCE_A_B_SUPPORT == STD_ON )
    	if( eTPU_ConfigPtr[count].etpuInstanceId == ETPU_CONFIG_INSTANCE_A_B )
    	{
    		if( ETPU_LLD_Init (ETPU_INSTANCE_A_B,
    			&eTPU_ConfigPtr[count].etpuConfigParameter,
    		    (uint32 const *) etpu_code_buff,
    		    sizeof (etpu_code_buff),
    		    (uint32 const *) etpu_global,
    		    sizeof (etpu_global)) != STATUS_SUCCESS )
            {
    	#if (ETPU_DEV_ERROR_DETECT == STD_ON)
    			(void)Det_ReportError((uint16)ETPU_MODULE_ID_OUTPUT, (uint8)ETPU_INSTANCE, 0, ETPU_E_PARAM_DATA);
    	#endif
            }
#if (ETPU_STARTTIMER_API == STD_OFF)
            ETPU_LLD_TimerStart(ETPU_INSTANCE_A_B);
#endif
        }
    #endif
    #if ( ETPU_INSTANCE_C_SUPPORT == STD_ON )
        if( eTPU_ConfigPtr[count].etpuInstanceId == ETPU_CONFIG_INSTANCE_C )
        {
        	if( ETPU_LLD_Init (ETPU_INSTANCE_C,
        		&eTPU_ConfigPtr[count].etpuConfigParameter,
        	    (uint32 const *) etpu_code_buff,
        	    sizeof (etpu_code_buff),
        	    (uint32 const *) etpu_global,
        	    sizeof (etpu_global)) != STATUS_SUCCESS )
        	{
        #if (ETPU_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)ETPU_MODULE_ID_OUTPUT, (uint8)ETPU_INSTANCE, 0, ETPU_E_PARAM_DATA);
        #endif
            }
#if (ETPU_STARTTIMER_API == STD_OFF)
            ETPU_LLD_TimerStart(ETPU_INSTANCE_C);
#endif
        }
    #endif
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static FUNC(void, ETPU_CODE) Ebppa_Init_func(P2CONST(eTPU_Total_ConfigType, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr)
{
    extern P2CONST(ebppa_config_t, EBPPA_CONST, EBPPA_APPL_CONST) ebppa_gConfigPtr[EBPPA_CORE_NUM];
#if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
    extern volatile VAR(uint8, EBPPA_VAR) sEbppa_u8Hw2LogicChannelMap[EBPPA_CORE_NUM][EBPPA_INSTANCE_NUM];
#endif

#if (EBPPA_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType,  AUTOMATIC) u8EBPPA_VerifyRetVal = E_NOT_OK;
#endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
    VAR(uint32, EBPPA_VAR)u32Loop = 0U;
    P2CONST(ebppa_channel_config_t, EBPPA_CONST, EBPPA_APPL_CONST) ChannelConfigPtr;
#if (EBPPA_MULTI_CORE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) u32CurrentCoreId = (uint32)EBPPA_GetCoreID();/* GetCoreID */
    VAR(uint8,  AUTOMATIC) u8CoreIdMask;
    VAR(uint16, AUTOMATIC) nInstance;
#endif /* (EBPPA_MULTI_CORE_SUPPORT == STD_ON) */

#if ( ETPU_PRECOMPILE_SUPPORT == STD_ON )
    (void)ConfigPtr;
    #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        u8EBPPA_VerifyRetVal = EBPPA_Init_Verify(&ebppa_Config);
    #endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
		ebppa_gConfigPtr[GetCoreID()] = &ebppa_Config;
#else 
    #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        u8EBPPA_VerifyRetVal = EBPPA_Init_Verify(ConfigPtr->ebppaConfigPtr);
    #endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
        ebppa_gConfigPtr[GetCoreID()] = ConfigPtr->ebppaConfigPtr;
#endif // ETPU_PRECOMPILE_SUPPORT
    #if (EBPPA_DEV_ERROR_DETECT == STD_ON)
        if((Std_ReturnType)E_OK == u8EBPPA_VerifyRetVal)
    #endif/*EBPPA_DEV_ERROR_DETECT == STD_ON*/
        {
    
            for(u32Loop = 0; u32Loop < ebppa_gConfigPtr[GetCoreID()]->channelTotal; u32Loop++)
            {
            #if(EBPPA_MULTI_CORE_SUPPORT == STD_ON)
                nInstance = ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u32Loop].EbppaChannelId;
                u8CoreIdMask = (uint8)(u32CurrentCoreId & (uint32)ebppa_gConfigPtr[GetCoreID()]->ebppa_CoreMap[nInstance].nCoreId);
                if(u8CoreIdMask != (uint8)0)
                {
                	if (sEbppa_u8Hw2LogicChannelMap[GetCoreID()][nInstance] == EBPPA_CHN_UNUSED)
                	{
                		sEbppa_u8Hw2LogicChannelMap[GetCoreID()][nInstance] = EBPPA_CHN_USED;
            #endif/* (EBPPA_MULTI_CORE_SUPPORT == STD_ON) */
                        ChannelConfigPtr = &ebppa_gConfigPtr[GetCoreID()]->ebppa_ChannelConfigPtr[u32Loop];
                        (void)ETPU_LLD_EBPPA_Init(ChannelConfigPtr->etpuGroup, ChannelConfigPtr->channel,
                                                    ChannelConfigPtr->priority, ChannelConfigPtr->timebase,
                        					        ChannelConfigPtr->mode, ChannelConfigPtr->max_count,
                                                    ChannelConfigPtr->sample_time);
    #if (EBPPA_MULTI_CORE_SUPPORT == STD_ON)
                    }
                }
    #endif /* (EBPPA_MULTI_CORE_SUPPORT == STD_ON) */
            }
		}
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif // EBPPA_INSTANCE_NUM

#if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
static FUNC(void, ETPU_CODE) Spwm_Init_func(P2CONST(eTPU_Total_ConfigType, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr)
{
    extern	P2CONST(spwm_config_t, SPWM_CONST, SPWM_APPL_CONST) sPWm_ConfigPtr[SPWM_CORE_NUM];
    extern  volatile VAR(uint8, ETPU_VAR) s_sPwm_ChannelInitState[SPWM_MASTER_NUM];
    VAR(uint8, AUTOMATIC) spwm_count = 0U;
    VAR(uint8, AUTOMATIC) index = 0U;
    VAR(uint32, AUTOMATIC) baseaddr = 0;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreId = 0U;
    VAR(uint32, AUTOMATIC) u32Spwm_CoreIdN = 0U;
    VAR(uint8, AUTOMATIC) u8_eTpuindex_temp = 0U;

    u32Spwm_CoreIdN = Spwm_GetCoreID(); /*spwm get coreid*/
    u32Spwm_CoreId = (1U << u32Spwm_CoreIdN);
    // sPWm_ConfigPtr = &sPwm_Config;
#if ( ETPU_PRECOMPILE_SUPPORT == STD_ON )
    (void)ConfigPtr;
	sPWm_ConfigPtr[u32Spwm_CoreIdN] = &sPwm_Config;
	if (NULL_PTR == sPWm_ConfigPtr)
#else 
	sPWm_ConfigPtr[u32Spwm_CoreIdN] = ConfigPtr->spwmConfigPtr;
	if (NULL_PTR == ConfigPtr->spwmConfigPtr)
#endif
    {
#if SPWM_DEV_ERROR_DETECT
        (void)Det_ReportError((uint16)CDD_SPWM_MODULE_ID, (uint8)0U, CDD_SPWM_SID_INIT, (uint8)CDD_SPWM_E_PARAM_POINTER);
#endif
    }
    else
    {
        SchM_Enter_eTPU_EXCLUSIVE_AREA_04();
        for(index = 0U; index < (uint8)SPWM_MASTER_NUM; index++)
        {
            u8_eTpuindex_temp++;
            if(0 != (u32Spwm_CoreId & sPWm_ConfigPtr[u32Spwm_CoreIdN]->mastercore_map[index].sPwm_CoreId))
            {
                if(0 == s_sPwm_ChannelInitState[index])
                {
                    s_sPwm_ChannelInitState[index] = 1;
                    (void)ETPU_LLD_SPWM_Init_Master(sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].etpuGroup,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].channel,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].freq,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].duty,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].timebase,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].timebase_freq,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].reference_mode,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].reference_ptr,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].INT_DMA_on_falling_edge,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].link1,
                									sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].link2);

                    baseaddr = ((uint32)eTPUInstance[sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].etpuGroup].data_ram_ext + \
                    ((uint32)(eTPUInstance[sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].etpuGroup].eTPU->CHAN[sPWm_ConfigPtr[u32Spwm_CoreIdN]-> \
                    spwm_master_config[index].channel].CR.B.CPBA<<3U)) + ((uint32)ETPU_SPWM_RISING_OFFSET - (uint32)1U));
                    for (spwm_count = 0U; spwm_count < sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].channel_count; spwm_count++)
                    {
                        (void)ETPU_LLD_SPWM_Init_Slave(sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].etpuGroup,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].channel,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].priority,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].freq,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].duty,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].cnl_delay,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].timebase,
                                        sPWm_ConfigPtr[u32Spwm_CoreIdN]->spwm_master_config[index].spwm_channel_config[spwm_count].timebase_freq,
                                        (uint32 *)baseaddr);
                        u8_eTpuindex_temp++;
                    }
                }
            }
        }
        SchM_Exit_eTPU_EXCLUSIVE_AREA_04();
    }
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif // SPWM_MASTER_NUM

#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) eTPU_Init(P2CONST(eTPU_Total_ConfigType, ETPU_CONST, ETPU_APPL_CONST) ConfigPtr)
{
#if (ETPU_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) u8eTPU_ret = E_OK;
    u8eTPU_ret = eTPU_InitVerify(ConfigPtr);
    if (E_OK == u8eTPU_ret)
#endif
    {
        if (eTPU_gStatus == ETPU_UNINIT)
        {
            SchM_Enter_eTPU_EXCLUSIVE_AREA_01();
		    eTPU_gStatus = ETPU_INITIALIZING;
		    SchM_Exit_eTPU_EXCLUSIVE_AREA_01();
            eTPU_Init_func(ConfigPtr);
            SchM_Enter_eTPU_EXCLUSIVE_AREA_02();
            eTPU_gStatus = ETPU_READY;
            SchM_Exit_eTPU_EXCLUSIVE_AREA_02();
        }
        else if (ETPU_INITIALIZING == eTPU_gStatus)
        {
        #if (ETPU_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)ETPU_MODULE_ID_OUTPUT, (uint8)ETPU_INSTANCE, ETPU_E_UNINIT, ETPU_E_TRANSITION);
        #endif
            return;
        }
        if (ETPU_READY == eTPU_gStatus)
        {
        #if ((EBPPA_INSTANCE_NUM != 0U)&&(EBPPA_MODULE_ENABLE !=STD_OFF))
            Ebppa_Init_func(ConfigPtr);
        #endif
        #if ((SPWM_MASTER_NUM != 0U)&&(SPWM_MODULE_ENABLE !=STD_OFF))
            Spwm_Init_func(ConfigPtr);
        #endif
        }
    }
    return;
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"

#if (ETPU_STARTTIMER_API == STD_ON)
#define ETPU_START_SEC_CODE
#include "eTPU_MemMap.h"
FUNC(void, ETPU_CODE) ETPU_TimerStart(void)
{
    SchM_Enter_eTPU_EXCLUSIVE_AREA_09();
#if ( ETPU_INSTANCE_A_B_SUPPORT == STD_ON )  
    ETPU_LLD_TimerStart(ETPU_INSTANCE_A_B);   
#endif
    
#if ( ETPU_INSTANCE_C_SUPPORT == STD_ON )
    ETPU_LLD_TimerStart(ETPU_INSTANCE_C);
#endif
    SchM_Exit_eTPU_EXCLUSIVE_AREA_09();
}
#define ETPU_STOP_SEC_CODE
#include "eTPU_MemMap.h"
#endif

#ifdef __cplusplus
}
#endif
#endif
