 
/*
************************************************************************************************************************
*
* File name: Rte_swc_DiagcEveHndlg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_SWC_DIAGCEVEHNDLG_H_
#define RTE_SWC_DIAGCEVEHNDLG_H_

#include "Rte_swc_DiagcEveHndlg_Type.h"
#include "Rte_DataHandleType.h"

#ifndef RTE_CORE                                     
#ifdef RTE_APPLICATION_HEADER_FILE                   
# error Multiple application header files included.  
#endif                                               
#define RTE_APPLICATION_HEADER_FILE                  
#ifndef RTE_PTR2ARRAYBASETYPE_PASSING                
#define RTE_PTR2ARRAYBASETYPE_PASSING                
#endif                                               
#endif                                               
                   
#ifdef __cplusplus
extern "C"         
{                  
#endif            

/*
************************************************************************************************************************
*    Buffers for Mode Management
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Mode_<p>_<m>
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    declaration of application error code
************************************************************************************************************************
*/

#ifndef RTE_E_DataServices_DspData_0x0500_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0500_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0501_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0501_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0502_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0502_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0503_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0503_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0504_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0504_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0505_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0505_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0507_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0507_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x050A_0_NOT_OK
#define RTE_E_DataServices_DspData_0x050A_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0522_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0522_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0523_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0523_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0524_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0524_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0525_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0525_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0526_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0526_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0527_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0527_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0528_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0528_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0529_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0529_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x052A_0_NOT_OK
#define RTE_E_DataServices_DspData_0x052A_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x052B_0_NOT_OK
#define RTE_E_DataServices_DspData_0x052B_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x052C_0_NOT_OK
#define RTE_E_DataServices_DspData_0x052C_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x052D_0_NOT_OK
#define RTE_E_DataServices_DspData_0x052D_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x052E_0_NOT_OK
#define RTE_E_DataServices_DspData_0x052E_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0530_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0530_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0531_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0531_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0532_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0532_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0533_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0533_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0534_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0534_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0535_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0535_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0536_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0536_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0537_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0537_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0538_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0538_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0539_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0539_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x053A_0_NOT_OK
#define RTE_E_DataServices_DspData_0x053A_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x053B_0_NOT_OK
#define RTE_E_DataServices_DspData_0x053B_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x053C_0_NOT_OK
#define RTE_E_DataServices_DspData_0x053C_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x053D_0_NOT_OK
#define RTE_E_DataServices_DspData_0x053D_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x053E_0_NOT_OK
#define RTE_E_DataServices_DspData_0x053E_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0542_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0542_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0543_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0543_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0544_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0544_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0545_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0545_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0547_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0547_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0552_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0552_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x055A_0_NOT_OK
#define RTE_E_DataServices_DspData_0x055A_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x055C_0_NOT_OK
#define RTE_E_DataServices_DspData_0x055C_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x055D_0_NOT_OK
#define RTE_E_DataServices_DspData_0x055D_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0585_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0585_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0586_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0586_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0587_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0587_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0588_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0588_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0589_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0589_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x058A_0_NOT_OK
#define RTE_E_DataServices_DspData_0x058A_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x058B_0_NOT_OK
#define RTE_E_DataServices_DspData_0x058B_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x058C_0_NOT_OK
#define RTE_E_DataServices_DspData_0x058C_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x058D_0_NOT_OK
#define RTE_E_DataServices_DspData_0x058D_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x058E_0_NOT_OK
#define RTE_E_DataServices_DspData_0x058E_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x058F_0_NOT_OK
#define RTE_E_DataServices_DspData_0x058F_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0590_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0590_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0591_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0591_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0592_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0592_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0593_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0593_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0594_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0594_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0595_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0595_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0596_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0596_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0597_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0597_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0598_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0598_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x0599_0_NOT_OK
#define RTE_E_DataServices_DspData_0x0599_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x059A_0_NOT_OK
#define RTE_E_DataServices_DspData_0x059A_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x059B_0_NOT_OK
#define RTE_E_DataServices_DspData_0x059B_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x059C_0_NOT_OK
#define RTE_E_DataServices_DspData_0x059C_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x059D_0_NOT_OK
#define RTE_E_DataServices_DspData_0x059D_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x059E_0_NOT_OK
#define RTE_E_DataServices_DspData_0x059E_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x059F_0_NOT_OK
#define RTE_E_DataServices_DspData_0x059F_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A1_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A1_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A2_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A2_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A3_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A3_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A4_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A4_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A5_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A5_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A6_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A6_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A7_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A7_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A8_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A8_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05A9_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05A9_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05AA_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05AA_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05AB_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05AB_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05AC_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05AC_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05AD_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05AD_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05AE_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05AE_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05AF_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05AF_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B0_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B0_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B1_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B1_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B2_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B2_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B3_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B3_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B4_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B4_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B5_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B5_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B6_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B6_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B7_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B7_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B8_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B8_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05B9_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05B9_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05BA_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05BA_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05BB_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05BB_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05BC_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05BC_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05BD_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05BD_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05BE_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05BE_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05BF_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05BF_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C0_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C0_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C1_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C1_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C2_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C2_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C3_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C3_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C4_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C4_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C5_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C5_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C6_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C6_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C7_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C7_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C8_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C8_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05C9_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05C9_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05CA_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05CA_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05CB_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05CB_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05CC_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05CC_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05CD_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05CD_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05CE_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05CE_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05CF_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05CF_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05D0_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05D0_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05D1_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05D1_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05D2_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05D2_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05D3_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05D3_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0x05D4_0_NOT_OK
#define RTE_E_DataServices_DspData_0x05D4_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xCF00_0_NOT_OK
#define RTE_E_DataServices_DspData_0xCF00_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xCF05_0_NOT_OK
#define RTE_E_DataServices_DspData_0xCF05_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xCF06_0_NOT_OK
#define RTE_E_DataServices_DspData_0xCF06_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xCF07_0_NOT_OK
#define RTE_E_DataServices_DspData_0xCF07_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xCF09_0_NOT_OK
#define RTE_E_DataServices_DspData_0xCF09_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDD00_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDD00_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF00_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF00_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF01_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF01_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF02_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF02_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF03_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF03_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF04_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF04_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF05_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF05_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF06_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF06_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF07_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF07_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xDF09_0_NOT_OK
#define RTE_E_DataServices_DspData_0xDF09_0_NOT_OK (1U)
#endif

#ifndef RTE_E_DataServices_DspData_0xF1A5_0_NOT_OK
#define RTE_E_DataServices_DspData_0xF1A5_0_NOT_OK (1U)
#endif

#ifndef RTE_E_FunctionInhibition_NOT_OK
#define RTE_E_FunctionInhibition_NOT_OK (1U)
#endif

#ifndef RTE_E_Ram_Service_NOT_OK
#define RTE_E_Ram_Service_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x03E2_NOT_OK
#define RTE_E_RoutineServices_0x03E2_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x05F2_NOT_OK
#define RTE_E_RoutineServices_0x05F2_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x05F3_NOT_OK
#define RTE_E_RoutineServices_0x05F3_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x05F4_NOT_OK
#define RTE_E_RoutineServices_0x05F4_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x05F5_NOT_OK
#define RTE_E_RoutineServices_0x05F5_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x05F6_NOT_OK
#define RTE_E_RoutineServices_0x05F6_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x4000_NOT_OK
#define RTE_E_RoutineServices_0x4000_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x400F_NOT_OK
#define RTE_E_RoutineServices_0x400F_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x4F02_NOT_OK
#define RTE_E_RoutineServices_0x4F02_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x4F03_NOT_OK
#define RTE_E_RoutineServices_0x4F03_NOT_OK (1U)
#endif

#ifndef RTE_E_RoutineServices_0x4F04_NOT_OK
#define RTE_E_RoutineServices_0x4F04_NOT_OK (1U)
#endif


/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrType_DEH_BatMfctrType;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_BatMfctrr_DEH_BatMfctrr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CBatNom_DEH_CBatNom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ChgLvlErr_DEH_ChgLvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DayBatMfctr_DEH_DayBatMfctr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_DischgLvlErr_DEH_DischgLvlErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd4_DEH_ErrCfmd4;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd6_DEH_ErrCfmd6;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErrSb_DEH_LvlErrSb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ModBalCtl_DEH_ModBalCtl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_MonthBatMfctr_DEH_MonthBatMfctr;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrPackSerl_DEH_NrPackSerl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin1_DEH_NrVin1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin10_DEH_NrVin10;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin11_DEH_NrVin11;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin12_DEH_NrVin12;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin13_DEH_NrVin13;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin14_DEH_NrVin14;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin15_DEH_NrVin15;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin16_DEH_NrVin16;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin17_DEH_NrVin17;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin2_DEH_NrVin2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin3_DEH_NrVin3;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin4_DEH_NrVin4;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin5_DEH_NrVin5;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin6_DEH_NrVin6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin7_DEH_NrVin7;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin8_DEH_NrVin8;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_NrVin9_DEH_NrVin9;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_PackCode_DEH_PackCode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqBalCtl_DEH_ReqBalCtl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyCh_DEH_ReqRlyCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyNeg_DEH_ReqRlyNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPos_DEH_ReqRlyPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqRlyPrech_DEH_ReqRlyPrech;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StFltLampIndcn_DEH_StFltLampIndcn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StIslnMeasReq_DEH_StIslnMeasReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StSocCal_DEH_StSocCal;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_TiChFullOff_DEH_TiChFullOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_UBatNom_DEH_UBatNom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValCodDiag_DEH_ValCodDiag;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ValPackSoc_DEH_ValPackSoc;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_YearBatMfctr_DEH_YearBatMfctr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcChInh_DEH_bAcvAcChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvChInh_DEH_bAcvChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcChInh_DEH_bAcvDcChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvDchaInh_DEH_bAcvDchaInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvHeatInh_DEH_bAcvHeatInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPowupInh_DEH_bAcvPowupInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvRecupInh_DEH_bAcvRecupInh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatChTot_NVM_CBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatDchaTot_NVM_CBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChIIntglFls_NVM_ChIIntglFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_ChgDeltAh_NVM_ChgDeltAh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCh_NVM_CtrCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_CtrDcha_NVM_CtrDcha;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DeltAh_NVM_DeltAh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatChTot_NVM_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatDchaTot_NVM_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_FullChgSOH_NVM_FullChgSOH;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatChMax_NVM_IBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IBatDchaMax_NVM_IBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_IIntglFls_NVM_IIntglFls;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatChMax_NVM_PBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_PBatDchaMax_NVM_PBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls;
extern VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMax_NVM_SocBatMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocBatMin_NVM_SocBatMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocCnsAct_NVM_SocCnsAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocPackScld_NVM_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SocUOcIni_NVM_SocUOcIni;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCalFls_NVM_SohCalFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohCycFls_NVM_SohCycFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohPackFls_NVM_SohPackFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohRDeltaFls_NVM_SohRDeltaFls;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls;
extern VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_StAryFls_NVM_StAryFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TPackFls_NVM_TPackFls;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatAgi_NVM_TiBatAgi;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffFls_NVM_TiBatOffFls;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMax_NVM_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UCellMin_NVM_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_UPrechAccumd_NVM_UPrechAccumd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls;
extern VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_ErrInfo_BCC_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StCh_BCC_StCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_UObcLimn_BCC_UObcLimn;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChIIntglNv_BCF_ChIIntglNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_DeltAhNv_BCF_DeltAhNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_ErrInfo_BCF_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_FullChgSOHNv_BCF_FullChgSOHNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLimMap_BCF_IChLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLimMap_BCF_IDchaLimMap;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IIntglNv_BCF_IIntglNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocCnsActNv_BCF_SocCnsActNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocLimMin_BCF_SocLimMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPackScld_BCF_SocPackScld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocUOcIniNv_BCF_SocUOcIniNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCalNv_BCF_SohCalNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohCycNv_BCF_SohCycNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPack_BCF_SohPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohPackNv_BCF_SohPackNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv;
extern VAR(rt_Array_Float_144, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_StAryFlsNv_BCF_StAryFlsNv;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv;
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiBatOffNv_BCF_TiBatOffNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_TiChFullOff_BCF_TiChFullOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_BMSStopChgReason_BMS_BMSStopChgReason;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMS_CCUStopChgReason_BMS_CCUStopChgReason;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_ErrInfo_BPP_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ErrInfo_BSTC_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatChTotNv_BWLD_CBatChTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrCh_BWLD_CtrCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrChNv_BWLD_CtrChNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDcha_BWLD_CtrDcha;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrDchaNv_BWLD_CtrDchaNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTot_BWLD_EBatChTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatChTotNv_BWLD_EBatChTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTot_BWLD_EBatDchaTot;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMax_BWLD_IBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMax_BWLD_IBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMax_BWLD_PBatChMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMax_BWLD_PBatDchaMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMax_BWLD_SocBatMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMin_BWLD_SocBatMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_SocBatMinNv_BWLD_SocBatMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgi_BWLD_TiBatAgi;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMax_BWLD_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMaxNv_BWLD_UCellMaxNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMin_BWLD_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatWntyLogtcData_BWLD_UCellMinNv_BWLD_UCellMinNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayTelbox_CIL_DayTelbox;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_ErrInfoBSW_CIL_ErrInfoBSW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourTelbox_CIL_HourTelbox;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_MilgTot_CIL_MilgTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuTelbox_CIL_MinuTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthTelbox_CIL_MonthTelbox;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_PowerMode_CIL_PowerMode;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SWVerVeh_CIL_SWVerVeh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecTelbox_CIL_SecTelbox;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointNeg_CIL_TAcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TAcChPointPos_CIL_TAcChPointPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBd_CIL_TBd;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointNeg_CIL_TDcChPointNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TDcChPointPos_CIL_TDcChPointPos;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdul_CIL_TMdul;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearTelbox_CIL_YearTelbox;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bAcvRstDiag_CIL_bAcvRstDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldIslnR_CIL_bVldIslnR;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ErrInfo_CTC_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_IDriftZero_CTC_IDriftZero;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyHeat_CTC_ReqRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyNeg_CTC_ReqRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPos_CTC_ReqRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyPrech_CTC_ReqRlyPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyCh_CTC_StRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyNeg_CTC_StRlyNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPrech_CTC_StRlyPrech;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_ChMode_EVCSH_ChMode;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_IChrgrSp_EVCSH_IChrgrSp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_UChrgrSp_EVCSH_UChrgrSp;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_DCChargeProcess_BMSH_DCChargeProcess;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_COL_BMSH_StsMode_BMSH_StsMode;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
extern VAR(Rte_ts_App1_Task1_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task1_UDS_Core2_QM;
extern VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
extern VAR(Rte_ts_App1_Task0_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task0_UDS_Core2_QM;
extern VAR(Rte_ts_App1_Task2_UDS_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task2_UDS_Core2_QM;
extern VAR(Rte_ts_App1_Task_1000ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_1000ms_Core2_QM;
extern VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for inter-runnable variables
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrErrCfmdNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStopDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrFctInhDeacStrtDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagNeg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_CtrRlyReqDiagPrech;
extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd4;
extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd5;
extern VAR(UInt32, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ErrCfmd6;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_LvlErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyNeg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_ReqRlyPrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_StsIninNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_DEH_bAcvBdNew;
extern VAR(UInt8, RTE_VAR_INIT) Rte_Irv_swc_DiagcEveHndlg_NVM_CtrErrCfmd;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    RTE Helper-Functions prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_NVM_Write_100ms_DEH_CtrErrCfmdNv(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF02_22_RE_DEH_CtrErrCfmdNv(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_CtrFctInhDeacStopDiag(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_CtrFctInhDeacStrtDiag(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagCh(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagNeg(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagPos(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagPrech(void);
FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd1(void);
FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd2(void);
FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd3(void);
FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd4(void);
FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd5(void);
FUNC(UInt32, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd6(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0537_22_RE_DEH_LvlErr(void);
FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyCh(void);
FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyNeg(void);
FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyPos(void);
FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyPrech(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_StsIninNv(void);
FUNC(Boolean, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_bAcvBdNew(void);
FUNC(UInt8, RTE_CODE) Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_NVM_CtrErrCfmd(void);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_CtrErrCfmdNv(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services_DEH_CtrFctInhDeacStopDiag(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services_DEH_CtrFctInhDeacStrtDiag(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services_DEH_CtrRlyReqDiagCh(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services_DEH_CtrRlyReqDiagNeg(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services_DEH_CtrRlyReqDiagPos(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services_DEH_CtrRlyReqDiagPrech(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd1(UInt32 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd2(UInt32 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd3(UInt32 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd4(UInt32 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd5(UInt32 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd6(UInt32 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_10ms_DEH_LvlErr(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services_DEH_ReqRlyCh(Boolean data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services_DEH_ReqRlyNeg(Boolean data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services_DEH_ReqRlyPos(Boolean data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services_DEH_ReqRlyPrech(Boolean data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_DEH_StsIninNv(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_DEH_StsIninNv(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_DEH_bAcvBdNew(Boolean data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_DEH_bAcvBdNew(Boolean data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_NVM_CtrErrCfmd(UInt8 data);
FUNC(void, RTE_CODE) Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_NVM_CtrErrCfmd(UInt8 data);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Rte_Switch_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IRead_<r>_<p>_<d>
*    Rte_IStatus_<r>_<p>_<d>
*    Rte_IWrite_<r>_<p>_<d>
*    Rte_IWriteRef_<r>_<p>_<d>
*    Rte_IInvalidate_<r>_<p>_<d>
************************************************************************************************************************
*/
#define Rte_IRead_NVM_Write_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv() \
  (&((*RteIRead_NVM_Write_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv())[0]))

#define RteIRead_NVM_Write_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0594_22_RE_BBC_bAcvBaln_BBC_bAcvBaln() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0594_22_RE.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value)

#define Rte_IRead_SetEventStatus_10ms_BCC_ErrInfo_BCC_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BCC_ErrInfo_BCC_ErrInfo.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0545_22_RE_BCC_IObcLimn_BCC_IObcLimn() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0545_22_RE.Rte_BCC_IObcLimn_BCC_IObcLimn.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0542_22_RE_BCC_StCh_BCC_StCh() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0542_22_RE.Rte_BCC_StCh_BCC_StCh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0544_22_RE_BCC_UObcLimn_BCC_UObcLimn() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0544_22_RE.Rte_BCC_UObcLimn_BCC_UObcLimn.value)

#define Rte_IRead_NVM_Write_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv() \
  (&((*RteIRead_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv())[0]))

#define RteIRead_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv() \
  (&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B1_22_RE.Rte_BCF_CMdulAgiFacFlsNv_BCF_CMdulAgiFacFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_ChIIntglNv_BCF_ChIIntglNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_ChIIntglNv_BCF_ChIIntglNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_ChgDeltAhNv_BCF_ChgDeltAhNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_DeltAhNv_BCF_DeltAhNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_DeltAhNv_BCF_DeltAhNv.value)

#define Rte_IRead_SetEventStatus_10ms_BCF_ErrInfo_BCF_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BCF_ErrInfo_BCF_ErrInfo.value)

#define Rte_IRead_NVM_Write_100ms_BCF_FullChgSOHNv_BCF_FullChgSOHNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_FullChgSOHNv_BCF_FullChgSOHNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0504_22_RE_BCF_IChLim_BCF_IChLim() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE.Rte_BCF_IChLim_BCF_IChLim.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x055C_22_RE_BCF_IChLim_BCF_IChLim() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055C_22_RE.Rte_BCF_IChLim_BCF_IChLim.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0502_22_RE_BCF_IChLimMap_BCF_IChLimMap() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE.Rte_BCF_IChLimMap_BCF_IChLimMap.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0503_22_RE_BCF_IDchaLim_BCF_IDchaLim() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE.Rte_BCF_IDchaLim_BCF_IDchaLim.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x055A_22_RE_BCF_IDchaLim_BCF_IDchaLim() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055A_22_RE.Rte_BCF_IDchaLim_BCF_IDchaLim.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0501_22_RE_BCF_IDchaLimMap_BCF_IDchaLimMap() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE.Rte_BCF_IDchaLimMap_BCF_IDchaLimMap.value)

#define Rte_IRead_NVM_Write_100ms_BCF_IIntglNv_BCF_IIntglNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_IIntglNv_BCF_IIntglNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv() \
  (&((*RteIRead_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv())[0]))

#define RteIRead_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv() \
  (&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B0_22_RE.Rte_BCF_RMdulAgiFacFlsNv_BCF_RMdulAgiFacFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SOHCalFulChgFlgNv_BCF_SOHCalFulChgFlgNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SOHCalOCVFlgNv_BCF_SOHCalOCVFlgNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SocCnsActNv_BCF_SocCnsActNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocCnsActNv_BCF_SocCnsActNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x055D_22_RE_BCF_SocLimMin_BCF_SocLimMin() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x055D_22_RE.Rte_BCF_SocLimMin_BCF_SocLimMin.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A1_22_RE_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A1_22_RE.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0524_22_RE_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0524_22_RE.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x052E_22_RE_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052E_22_RE.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDF09_22_RE_BCF_SocPackScld_BCF_SocPackScld() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF09_22_RE.Rte_BCF_SocPackScld_BCF_SocPackScld.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SocUOcIniNv_BCF_SocUOcIniNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SocUOcIniNv_BCF_SocUOcIniNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SohCalNv_BCF_SohCalNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohCalNv_BCF_SohCalNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SohCycNv_BCF_SohCycNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohCycNv_BCF_SohCycNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0525_22_RE_BCF_SohPack_BCF_SohPack() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0525_22_RE.Rte_BCF_SohPack_BCF_SohPack.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SohPackNv_BCF_SohPackNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohPackNv_BCF_SohPackNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohRDeltaFlsNv_BCF_SohRDeltaFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_SohSocDeltaFlsNv_BCF_SohSocDeltaFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_StAryFlsNv_BCF_StAryFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE_BCF_StAryFlsNv_BCF_StAryFlsNv() \
  (&((*RteIRead_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE_BCF_StAryFlsNv_BCF_StAryFlsNv())[0]))

#define RteIRead_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE_BCF_StAryFlsNv_BCF_StAryFlsNv() \
  (&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B2_22_RE.Rte_BCF_StAryFlsNv_BCF_StAryFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiBatOffForMdulCFlsNv_BCF_TiBatOffForMdulCFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiBatOffForMdulRFlsNv_BCF_TiBatOffForMdulRFlsNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_TiBatOffNv_BCF_TiBatOffNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiBatOffNv_BCF_TiBatOffNv.value)

#define Rte_IRead_NVM_Write_100ms_BCF_TiChFullOff_BCF_TiChFullOff() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_TiChFullOff_BCF_TiChFullOff.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0522_22_RE_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0522_22_RE.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0592_22_RE_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0592_22_RE.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xCF00_22_RE_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF00_22_RE.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05CC_22_RE_BCF_UCellAvg_BCF_UCellAvg() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CC_22_RE.Rte_BCF_UCellAvg_BCF_UCellAvg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0593_22_RE_BCF_UMdul_BCF_UMdul() \
  (&((*RteIRead_SWC_TestDCM_DataServices_DspData_0x0593_22_RE_BCF_UMdul_BCF_UMdul())[0]))

#define RteIRead_SWC_TestDCM_DataServices_DspData_0x0593_22_RE_BCF_UMdul_BCF_UMdul() \
  (&Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0593_22_RE.Rte_BCF_UMdul_BCF_UMdul.value)

#define Rte_IRead_NVM_Write_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv() \
  (&((*RteIRead_NVM_Write_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv())[0]))

#define RteIRead_NVM_Write_100ms_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BCF_bErrMdulSocInvldFlsNv_BCF_bErrMdulSocInvldFlsNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0547_22_RE_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0547_22_RE.Rte_BCTE_TiBatChByMinuTot_BCTE_TiBatChByMinuTot.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0507_22_RE_BMC_UCell_BMC_UCell() \
  (&((*RteIRead_SWC_TestDCM_DataServices_DspData_0x0507_22_RE_BMC_UCell_BMC_UCell())[0]))

#define RteIRead_SWC_TestDCM_DataServices_DspData_0x0507_22_RE_BMC_UCell_BMC_UCell() \
  (&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0507_22_RE.Rte_BMC_UCell_BMC_UCell.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059C_22_RE_BMSH_DCChargeProcess_BMSH_DCChargeProcess() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059C_22_RE.Rte_BMSH_DCChargeProcess_BMSH_DCChargeProcess.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0505_22_RE_BMSH_StsMode_BMSH_StsMode() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0505_22_RE.Rte_BMSH_StsMode_BMSH_StsMode.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059D_22_RE_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_BMSStopChgErrReason_BMS_BMSStopChgErrReason.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059D_22_RE_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_BMSStopChgFltReason_BMS_BMSStopChgFltReason.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059D_22_RE_BMS_BMSStopChgReason_BMS_BMSStopChgReason() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_BMSStopChgReason_BMS_BMSStopChgReason.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059D_22_RE_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_CCUStopChgErrReason_BMS_CCUStopChgErrReason.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059D_22_RE_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_CCUStopChgFltReason_BMS_CCUStopChgFltReason.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059D_22_RE_BMS_CCUStopChgReason_BMS_CCUStopChgReason() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059D_22_RE.Rte_BMS_CCUStopChgReason_BMS_CCUStopChgReason.value)

#define Rte_IRead_SetEventStatus_10ms_BPIU_ErrInfo_BPIU_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0527_22_RE_BPIU_IdCellUMax_BPIU_IdCellUMax() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0527_22_RE.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0529_22_RE_BPIU_IdCellUMin_BPIU_IdCellUMin() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0529_22_RE.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0526_22_RE_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0526_22_RE.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0528_22_RE_BPIU_UCellMin_BPIU_UCellMin() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0528_22_RE.Rte_BPIU_UCellMin_BPIU_UCellMin.value)

#define Rte_IRead_SetEventStatus_10ms_BPP_ErrInfo_BPP_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BPP_ErrInfo_BPP_ErrInfo.value)

#define Rte_IRead_NVM_Write_100ms_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv.value)

#define Rte_IRead_SetEventStatus_10ms_BSTC_ErrInfo_BSTC_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BSTC_ErrInfo_BSTC_ErrInfo.value)

#define Rte_IRead_NVM_Write_100ms_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv.value)

#define Rte_IRead_NVM_Write_100ms_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv.value)

#define Rte_IRead_NVM_Write_100ms_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv.value)

#define Rte_IRead_NVM_Write_100ms_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv.value)

#define Rte_IRead_DEH_1000ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_DEH_10ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x053A_22_RE_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053A_22_RE.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xCF09_22_RE_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF09_22_RE.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_DEH_10ms_BSTC_StBcuInt_BSTC_StBcuInt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value)

#define Rte_IRead_NVM_Write_100ms_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv.value)

#define Rte_IRead_SetEventStatus_10ms_BTHM_ErrInfo_BTHM_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x052B_22_RE_BTHM_IdCellTMax_BTHM_IdCellTMax() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052B_22_RE.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x052D_22_RE_BTHM_IdCellTMin_BTHM_IdCellTMin() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052D_22_RE.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x052A_22_RE_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052A_22_RE.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xCF06_22_RE_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF06_22_RE.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x052C_22_RE_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x052C_22_RE.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xCF07_22_RE_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF07_22_RE.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_NVM_Write_100ms_BTHM_TPack_BTHM_TPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BTHM_TPack_BTHM_TPack.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0530_22_RE_BTHM_TPack_BTHM_TPack() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0530_22_RE.Rte_BTHM_TPack_BTHM_TPack.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_CBatChTotNv_BWLD_CBatChTotNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CBatChTotNv_BWLD_CBatChTotNv.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CBatDchaTotNv_BWLD_CBatDchaTotNv.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CBatRecoveryTotNv_BWLD_CBatRecoveryTotNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0588_22_RE_BWLD_CtrCh_BWLD_CtrCh() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0588_22_RE.Rte_BWLD_CtrCh_BWLD_CtrCh.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_CtrChNv_BWLD_CtrChNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CtrChNv_BWLD_CtrChNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0589_22_RE_BWLD_CtrDcha_BWLD_CtrDcha() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0589_22_RE.Rte_BWLD_CtrDcha_BWLD_CtrDcha.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_CtrDchaNv_BWLD_CtrDchaNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_CtrDchaNv_BWLD_CtrDchaNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x058A_22_RE_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058A_22_RE.Rte_BWLD_CtrV2GDchaMax_BWLD_CtrV2GDchaMax.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x053E_22_RE_BWLD_EBatChTot_BWLD_EBatChTot() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053E_22_RE.Rte_BWLD_EBatChTot_BWLD_EBatChTot.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_EBatChTotNv_BWLD_EBatChTotNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_EBatChTotNv_BWLD_EBatChTotNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x053D_22_RE_BWLD_EBatDchaTot_BWLD_EBatDchaTot() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053D_22_RE.Rte_BWLD_EBatDchaTot_BWLD_EBatDchaTot.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_EBatDchaTotNv_BWLD_EBatDchaTotNv.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_EBatRecoveryTotNv_BWLD_EBatRecoveryTotNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A4_22_RE_BWLD_IBatChMax_BWLD_IBatChMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A4_22_RE.Rte_BWLD_IBatChMax_BWLD_IBatChMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_IBatChMaxNv_BWLD_IBatChMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A5_22_RE_BWLD_IBatDchaMax_BWLD_IBatDchaMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A5_22_RE.Rte_BWLD_IBatDchaMax_BWLD_IBatDchaMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_IBatDchaMaxNv_BWLD_IBatDchaMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A2_22_RE_BWLD_PBatChMax_BWLD_PBatChMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A2_22_RE.Rte_BWLD_PBatChMax_BWLD_PBatChMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_PBatChMaxNv_BWLD_PBatChMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A3_22_RE_BWLD_PBatDchaMax_BWLD_PBatDchaMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A3_22_RE.Rte_BWLD_PBatDchaMax_BWLD_PBatDchaMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_PBatDchaMaxNv_BWLD_PBatDchaMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05AB_22_RE_BWLD_SocBatMax_BWLD_SocBatMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AB_22_RE.Rte_BWLD_SocBatMax_BWLD_SocBatMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_SocBatMaxNv_BWLD_SocBatMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05AA_22_RE_BWLD_SocBatMin_BWLD_SocBatMin() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AA_22_RE.Rte_BWLD_SocBatMin_BWLD_SocBatMin.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_SocBatMinNv_BWLD_SocBatMinNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_SocBatMinNv_BWLD_SocBatMinNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05AF_22_RE_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AF_22_RE.Rte_BWLD_TMdulSnsrMax_BWLD_TMdulSnsrMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_TMdulSnsrMaxNv_BWLD_TMdulSnsrMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05AE_22_RE_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AE_22_RE.Rte_BWLD_TMdulSnsrMin_BWLD_TMdulSnsrMin.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_TMdulSnsrMinNv_BWLD_TMdulSnsrMinNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0591_22_RE_BWLD_TiBatAgi_BWLD_TiBatAgi() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0591_22_RE.Rte_BWLD_TiBatAgi_BWLD_TiBatAgi.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_TiBatAgiNv_BWLD_TiBatAgiNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A9_22_RE_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A9_22_RE.Rte_BWLD_UBatCtctrClsdMax_BWLD_UBatCtctrClsdMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrClsdMaxNv_BWLD_UBatCtctrClsdMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A8_22_RE_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A8_22_RE.Rte_BWLD_UBatCtctrClsdMin_BWLD_UBatCtctrClsdMin.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrClsdMinNv_BWLD_UBatCtctrClsdMinNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A7_22_RE_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A7_22_RE.Rte_BWLD_UBatCtctrOpenMax_BWLD_UBatCtctrOpenMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrOpenMaxNv_BWLD_UBatCtctrOpenMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05A6_22_RE_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05A6_22_RE.Rte_BWLD_UBatCtctrOpenMin_BWLD_UBatCtctrOpenMin.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UBatCtctrOpenMinNv_BWLD_UBatCtctrOpenMinNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05AD_22_RE_BWLD_UCellMax_BWLD_UCellMax() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AD_22_RE.Rte_BWLD_UCellMax_BWLD_UCellMax.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_UCellMaxNv_BWLD_UCellMaxNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UCellMaxNv_BWLD_UCellMaxNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05AC_22_RE_BWLD_UCellMin_BWLD_UCellMin() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05AC_22_RE.Rte_BWLD_UCellMin_BWLD_UCellMin.value)

#define Rte_IRead_NVM_Write_100ms_BWLD_UCellMinNv_BWLD_UCellMinNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_BWLD_UCellMinNv_BWLD_UCellMinNv.value)

#define Rte_IRead_DEH_10ms_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_BMSH_FaultResetReq_CIL_BMSH_FaultResetReq.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE_CIL_DayTelbox_CIL_DayTelbox() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_DayTelbox_CIL_DayTelbox.value)

#define Rte_IRead_SetEventStatus_10ms_CIL_ErrInfoBSW_CIL_ErrInfoBSW() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_CIL_ErrInfoBSW_CIL_ErrInfoBSW.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE_CIL_HourTelbox_CIL_HourTelbox() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_HourTelbox_CIL_HourTelbox.value)

#define Rte_IRead_DEH_1000ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0523_22_RE_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0523_22_RE.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xCF05_22_RE_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xCF05_22_RE.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDF03_22_RE_CIL_MilgTot_CIL_MilgTot() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF03_22_RE.Rte_CIL_MilgTot_CIL_MilgTot.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDF04_22_RE_CIL_MilgTot_CIL_MilgTot() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF04_22_RE.Rte_CIL_MilgTot_CIL_MilgTot.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE_CIL_MinuTelbox_CIL_MinuTelbox() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_MinuTelbox_CIL_MinuTelbox.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE_CIL_MonthTelbox_CIL_MonthTelbox() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_MonthTelbox_CIL_MonthTelbox.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDF06_22_RE_CIL_PowerMode_CIL_PowerMode() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF06_22_RE.Rte_CIL_PowerMode_CIL_PowerMode.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05CA_22_RE_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CA_22_RE.Rte_CIL_RDcChrgrPlg_CIL_RDcChrgrPlg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE_CIL_SWVerVeh_CIL_SWVerVeh() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE.Rte_CIL_SWVerVeh_CIL_SWVerVeh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE_CIL_SecTelbox_CIL_SecTelbox() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_SecTelbox_CIL_SecTelbox.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDF01_22_RE_CIL_SpdVeh_CIL_SpdVeh() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF01_22_RE.Rte_CIL_SpdVeh_CIL_SpdVeh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B8_22_RE_CIL_StBatHvReq_CIL_StBatHvReq() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B8_22_RE.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05BA_22_RE_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BA_22_RE.Rte_CIL_StCellTSamplgExcpn_CIL_StCellTSamplgExcpn.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05BC_22_RE_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BC_22_RE.Rte_CIL_StCellUSamplgExcpn_CIL_StCellUSamplgExcpn.value)

#define Rte_IRead_DEH_10ms_CIL_StPtIndcr_CIL_StPtIndcr() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0534_22_RE_CIL_TAcChPointNeg_CIL_TAcChPointNeg() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0534_22_RE.Rte_CIL_TAcChPointNeg_CIL_TAcChPointNeg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0533_22_RE_CIL_TAcChPointPos_CIL_TAcChPointPos() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0533_22_RE.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05CD_22_RE_CIL_TAcChPointPos_CIL_TAcChPointPos() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CD_22_RE.Rte_CIL_TAcChPointPos_CIL_TAcChPointPos.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0596_22_RE_CIL_TBd_CIL_TBd() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0596_22_RE.Rte_CIL_TBd_CIL_TBd.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05D1_22_RE_CIL_TBd_CIL_TBd() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D1_22_RE.Rte_CIL_TBd_CIL_TBd.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0535_22_RE_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0535_22_RE.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0536_22_RE_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0536_22_RE.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0532_22_RE_CIL_TDcChPointNeg_CIL_TDcChPointNeg() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0532_22_RE.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059E_22_RE_CIL_TDcChPointNeg_CIL_TDcChPointNeg() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE.Rte_CIL_TDcChPointNeg_CIL_TDcChPointNeg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0531_22_RE_CIL_TDcChPointPos_CIL_TDcChPointPos() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0531_22_RE.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059E_22_RE_CIL_TDcChPointPos_CIL_TDcChPointPos() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059E_22_RE.Rte_CIL_TDcChPointPos_CIL_TDcChPointPos.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x050A_22_RE_CIL_TMdul_CIL_TMdul() \
  (&((*RteIRead_SWC_TestDCM_DataServices_DspData_0x050A_22_RE_CIL_TMdul_CIL_TMdul())[0]))

#define RteIRead_SWC_TestDCM_DataServices_DspData_0x050A_22_RE_CIL_TMdul_CIL_TMdul() \
  (&Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x050A_22_RE.Rte_CIL_TMdul_CIL_TMdul.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C5_22_RE_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C5_22_RE.Rte_CIL_UChPoleHiSideDrv_CIL_UChPoleHiSideDrv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C8_22_RE_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C8_22_RE.Rte_CIL_UHeatPoleHiSideDrv_CIL_UHeatPoleHiSideDrv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0599_22_RE_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0599_22_RE.Rte_CIL_UMainNegPoleAftRly_CIL_UMainNegPoleAftRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C6_22_RE_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C6_22_RE.Rte_CIL_UMainNegPoleHiSideDrv_CIL_UMainNegPoleHiSideDrv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0598_22_RE_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0598_22_RE.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05CE_22_RE_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CE_22_RE.Rte_CIL_UMainPosPoleAftRly_CIL_UMainPosPoleAftRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0501_22_RE_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0501_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0502_22_RE_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0502_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0503_22_RE_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0503_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0504_22_RE_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0504_22_RE.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C7_22_RE_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C7_22_RE.Rte_CIL_UMainPosPoleHiSideDrv_CIL_UMainPosPoleHiSideDrv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059B_22_RE_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059B_22_RE.Rte_CIL_UPoleAftRlyCh_CIL_UPoleAftRlyCh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059A_22_RE_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059A_22_RE.Rte_CIL_UPoleAftRlyHeat_CIL_UPoleAftRlyHeat.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C4_22_RE_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C4_22_RE.Rte_CIL_URlyPrechHiSideDrv_CIL_URlyPrechHiSideDrv.value)

#define Rte_IRead_DEH_10ms_CIL_UTrml30_CIL_UTrml30() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_UTrml30_CIL_UTrml30.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0500_22_RE_CIL_UTrml30_CIL_UTrml30() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0500_22_RE.Rte_CIL_UTrml30_CIL_UTrml30.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDF00_22_RE_CIL_UTrml30_CIL_UTrml30() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF00_22_RE.Rte_CIL_UTrml30_CIL_UTrml30.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE_CIL_YearTelbox_CIL_YearTelbox() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDD00_22_RE.Rte_CIL_YearTelbox_CIL_YearTelbox.value)

#define Rte_IRead_DEH_10ms_CIL_bAcvRstDiag_CIL_bAcvRstDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value)

#define Rte_IRead_GetEventStatus_10ms_CIL_bAcvRstDiag_CIL_bAcvRstDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_CIL_bAcvRstDiag_CIL_bAcvRstDiag.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05BE_22_RE_CIL_bVldBatIHv_CIL_bVldBatIHv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BE_22_RE.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B9_22_RE_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B9_22_RE.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05BB_22_RE_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BB_22_RE.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05BF_22_RE_CIL_bVldIslnR_CIL_bVldIslnR() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BF_22_RE.Rte_CIL_bVldIslnR_CIL_bVldIslnR.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C3_22_RE_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C3_22_RE.Rte_CIL_bVldUMainNegPoleAftRly_CIL_bVldUMainNegPoleAftRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C2_22_RE_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C2_22_RE.Rte_CIL_bVldUMainPosPoleAftRly_CIL_bVldUMainPosPoleAftRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05BD_22_RE_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05BD_22_RE.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C0_22_RE_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C0_22_RE.Rte_CIL_bVldUPoleAftRlyCh_CIL_bVldUPoleAftRlyCh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C1_22_RE_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C1_22_RE.Rte_CIL_bVldUPoleAftRlyHeat_CIL_bVldUPoleAftRlyHeat.value)

#define Rte_IRead_NVM_Write_100ms_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x058F_22_RE_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058F_22_RE.Rte_CTC_CtrCtctrAgiChNv_CTC_CtrCtctrAgiChNv.value)

#define Rte_IRead_NVM_Write_100ms_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0590_22_RE_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0590_22_RE.Rte_CTC_CtrCtctrAgiHeatNv_CTC_CtrCtctrAgiHeatNv.value)

#define Rte_IRead_NVM_Write_100ms_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x058D_22_RE_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058D_22_RE.Rte_CTC_CtrCtctrAgiNegNv_CTC_CtrCtctrAgiNegNv.value)

#define Rte_IRead_NVM_Write_100ms_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x058C_22_RE_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058C_22_RE.Rte_CTC_CtrCtctrAgiPosNv_CTC_CtrCtctrAgiPosNv.value)

#define Rte_IRead_NVM_Write_100ms_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x058E_22_RE_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058E_22_RE.Rte_CTC_CtrCtctrAgiPrechNv_CTC_CtrCtctrAgiPrechNv.value)

#define Rte_IRead_SetEventStatus_10ms_CTC_ErrInfo_CTC_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_CTC_ErrInfo_CTC_ErrInfo.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0597_22_RE_CTC_IDriftZero_CTC_IDriftZero() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0597_22_RE.Rte_CTC_IDriftZero_CTC_IDriftZero.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B3_22_RE_CTC_ReqRlyCh_CTC_ReqRlyCh() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B3_22_RE.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B7_22_RE_CTC_ReqRlyHeat_CTC_ReqRlyHeat() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B7_22_RE.Rte_CTC_ReqRlyHeat_CTC_ReqRlyHeat.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B4_22_RE_CTC_ReqRlyNeg_CTC_ReqRlyNeg() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B4_22_RE.Rte_CTC_ReqRlyNeg_CTC_ReqRlyNeg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B5_22_RE_CTC_ReqRlyPos_CTC_ReqRlyPos() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B5_22_RE.Rte_CTC_ReqRlyPos_CTC_ReqRlyPos.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05B6_22_RE_CTC_ReqRlyPrech_CTC_ReqRlyPrech() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05B6_22_RE.Rte_CTC_ReqRlyPrech_CTC_ReqRlyPrech.value)

#define Rte_IRead_DEH_10ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_DEH_10ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05CF_22_RE_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CF_22_RE.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_DEH_1000ms_CTC_StRlyCh_CTC_StRlyCh() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyCh_CTC_StRlyCh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0586_22_RE_CTC_StRlyCh_CTC_StRlyCh() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0586_22_RE.Rte_CTC_StRlyCh_CTC_StRlyCh.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05D0_22_RE_CTC_StRlyCh_CTC_StRlyCh() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05D0_22_RE.Rte_CTC_StRlyCh_CTC_StRlyCh.value)

#define Rte_IRead_DEH_1000ms_CTC_StRlyHeat_CTC_StRlyHeat() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0539_22_RE_CTC_StRlyHeat_CTC_StRlyHeat() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0539_22_RE.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value)

#define Rte_IRead_DEH_1000ms_CTC_StRlyNeg_CTC_StRlyNeg() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0538_22_RE_CTC_StRlyNeg_CTC_StRlyNeg() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0538_22_RE.Rte_CTC_StRlyNeg_CTC_StRlyNeg.value)

#define Rte_IRead_DEH_1000ms_CTC_StRlyPos_CTC_StRlyPos() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0585_22_RE_CTC_StRlyPos_CTC_StRlyPos() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0585_22_RE.Rte_CTC_StRlyPos_CTC_StRlyPos.value)

#define Rte_IRead_DEH_1000ms_CTC_StRlyPrech_CTC_StRlyPrech() \
  (Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0587_22_RE_CTC_StRlyPrech_CTC_StRlyPrech() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0587_22_RE.Rte_CTC_StRlyPrech_CTC_StRlyPrech.value)

#define Rte_IRead_NVM_Write_100ms_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_CTC_UPrechAccumdNv_CTC_UPrechAccumdNv.value)

#define Rte_IWrite_DEH_1000ms_DEH_BatMfctrType_DEH_BatMfctrType(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_BatMfctrType_DEH_BatMfctrType.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_BatMfctrType_DEH_BatMfctrType() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_BatMfctrType_DEH_BatMfctrType.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_BatMfctrr_DEH_BatMfctrr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_BatMfctrr_DEH_BatMfctrr.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_BatMfctrr_DEH_BatMfctrr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_BatMfctrr_DEH_BatMfctrr.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_CBatNom_DEH_CBatNom(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_CBatNom_DEH_CBatNom.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_CBatNom_DEH_CBatNom() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_CBatNom_DEH_CBatNom.value \
)

#define Rte_IWrite_DEH_10ms_DEH_ChgLvlErr_DEH_ChgLvlErr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_ChgLvlErr_DEH_ChgLvlErr.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_ChgLvlErr_DEH_ChgLvlErr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_ChgLvlErr_DEH_ChgLvlErr.value \
)

#define Rte_IWrite_RoutineServices_0x05F3_Start_Services_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F3_Start_Services_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag.value \
)

#define Rte_IWrite_RoutineServices_0x05F4_Start_Services_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start_Services.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F4_Start_Services_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start_Services.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_CtrErrCfmdNv_DEH_CtrErrCfmdNv.value \
)

#define Rte_IWrite_RoutineServices_0x05F6_Stop_Services_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services.Rte_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F6_Stop_Services_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services.Rte_DEH_CtrFctInhDeacStopDiag_DEH_CtrFctInhDeacStopDiag.value \
)

#define Rte_IWrite_RoutineServices_0x05F6_Start_Services_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services.Rte_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F6_Start_Services_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services.Rte_DEH_CtrFctInhDeacStrtDiag_DEH_CtrFctInhDeacStrtDiag.value \
)

#define Rte_IWrite_RoutineServices_0x03E2_Stop_Services_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Services.Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x03E2_Stop_Services_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Services.Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag.value \
)

#define Rte_IWrite_RoutineServices_0x03E2_Start_Services_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Services.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x03E2_Start_Services_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Services.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value \
)

#define Rte_IWrite_RoutineServices_0x400F_Start_Services_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services.Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x400F_Start_Services_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services.Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag.value \
)

#define Rte_IWrite_RoutineServices_0x05F5_Start_Services_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services.Rte_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F5_Start_Services_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services.Rte_DEH_CtrPackSocSetDiag_DEH_CtrPackSocSetDiag.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_CtrRlyReqDiag_DEH_CtrRlyReqDiag.value \
)

#define Rte_IWrite_RoutineServices_0x05F2_Start_Services_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start_Services.Rte_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F2_Start_Services_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start_Services.Rte_DEH_CtrRlyWlddErrRstDiag_DEH_CtrRlyWlddErrRstDiag.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_DayBatMfctr_DEH_DayBatMfctr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_DayBatMfctr_DEH_DayBatMfctr.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_DayBatMfctr_DEH_DayBatMfctr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_DayBatMfctr_DEH_DayBatMfctr.value \
)

#define Rte_IWrite_DEH_10ms_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_DelayDataUpldEnb_DEH_DelayDataUpldEnb.value \
)

#define Rte_IWrite_DEH_10ms_DEH_DischgLvlErr_DEH_DischgLvlErr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_DischgLvlErr_DEH_DischgLvlErr.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_DischgLvlErr_DEH_DischgLvlErr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_DischgLvlErr_DEH_DischgLvlErr.value \
)

#define Rte_IWrite_DEH_10ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrCfmd1_DEH_ErrCfmd1(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrCfmd2_DEH_ErrCfmd2(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrCfmd3_DEH_ErrCfmd3(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrCfmd4_DEH_ErrCfmd4(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrCfmd4_DEH_ErrCfmd4() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd4_DEH_ErrCfmd4.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrCfmd5_DEH_ErrCfmd5(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrCfmd5_DEH_ErrCfmd5() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrCfmd6_DEH_ErrCfmd6(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd6_DEH_ErrCfmd6.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrCfmd6_DEH_ErrCfmd6() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrCfmd6_DEH_ErrCfmd6.value \
)

#define Rte_IWrite_GetEventStatus_10ms_DEH_ErrHisCfmd_DEH_ErrHisCfmd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value = (data) \
)

#define Rte_IWriteRef_GetEventStatus_10ms_DEH_ErrHisCfmd_DEH_ErrHisCfmd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_GetEventStatus_10ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_ErrRlyCtlDiag_DEH_ErrRlyCtlDiag.value \
)

#define Rte_IWrite_RoutineServices_0x05F3_Start_Services_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F3_Start_Services_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl.value \
)

#define Rte_IWrite_DEH_10ms_DEH_LvlErr_DEH_LvlErr(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_LvlErr_DEH_LvlErr.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_LvlErr_DEH_LvlErr() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_LvlErr_DEH_LvlErr.value \
)

#define Rte_IWrite_DEH_10ms_DEH_LvlErrSb_DEH_LvlErrSb(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_LvlErrSb_DEH_LvlErrSb.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_LvlErrSb_DEH_LvlErrSb() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_LvlErrSb_DEH_LvlErrSb.value \
)

#define Rte_IWrite_RoutineServices_0x05F3_Start_Services_DEH_ModBalCtl_DEH_ModBalCtl(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_ModBalCtl_DEH_ModBalCtl.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F3_Start_Services_DEH_ModBalCtl_DEH_ModBalCtl() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_ModBalCtl_DEH_ModBalCtl.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_MonthBatMfctr_DEH_MonthBatMfctr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_MonthBatMfctr_DEH_MonthBatMfctr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_MonthBatMfctr_DEH_MonthBatMfctr.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrPackSerl_DEH_NrPackSerl(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrPackSerl_DEH_NrPackSerl.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrPackSerl_DEH_NrPackSerl() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrPackSerl_DEH_NrPackSerl.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin1_DEH_NrVin1(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin1_DEH_NrVin1.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin1_DEH_NrVin1() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin1_DEH_NrVin1.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin10_DEH_NrVin10(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin10_DEH_NrVin10.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin10_DEH_NrVin10() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin10_DEH_NrVin10.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin11_DEH_NrVin11(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin11_DEH_NrVin11.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin11_DEH_NrVin11() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin11_DEH_NrVin11.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin12_DEH_NrVin12(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin12_DEH_NrVin12.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin12_DEH_NrVin12() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin12_DEH_NrVin12.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin13_DEH_NrVin13(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin13_DEH_NrVin13.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin13_DEH_NrVin13() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin13_DEH_NrVin13.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin14_DEH_NrVin14(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin14_DEH_NrVin14.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin14_DEH_NrVin14() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin14_DEH_NrVin14.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin15_DEH_NrVin15(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin15_DEH_NrVin15.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin15_DEH_NrVin15() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin15_DEH_NrVin15.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin16_DEH_NrVin16(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin16_DEH_NrVin16.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin16_DEH_NrVin16() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin16_DEH_NrVin16.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin17_DEH_NrVin17(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin17_DEH_NrVin17.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin17_DEH_NrVin17() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin17_DEH_NrVin17.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin2_DEH_NrVin2(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin2_DEH_NrVin2.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin2_DEH_NrVin2() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin2_DEH_NrVin2.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin3_DEH_NrVin3(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin3_DEH_NrVin3.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin3_DEH_NrVin3() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin3_DEH_NrVin3.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin4_DEH_NrVin4(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin4_DEH_NrVin4.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin4_DEH_NrVin4() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin4_DEH_NrVin4.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin5_DEH_NrVin5(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin5_DEH_NrVin5.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin5_DEH_NrVin5() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin5_DEH_NrVin5.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin6_DEH_NrVin6(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin6_DEH_NrVin6.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin6_DEH_NrVin6() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin6_DEH_NrVin6.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin7_DEH_NrVin7(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin7_DEH_NrVin7.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin7_DEH_NrVin7() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin7_DEH_NrVin7.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin8_DEH_NrVin8(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin8_DEH_NrVin8.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin8_DEH_NrVin8() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin8_DEH_NrVin8.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_NrVin9_DEH_NrVin9(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin9_DEH_NrVin9.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_NrVin9_DEH_NrVin9() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_NrVin9_DEH_NrVin9.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_PackCode_DEH_PackCode(data) \
  RteIWrite_DEH_1000ms_DEH_PackCode_DEH_PackCode(data)

#define RteIWrite_DEH_1000ms_DEH_PackCode_DEH_PackCode(data) \
( \
  Rte_MemCpy(Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_PackCode_DEH_PackCode.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_PackCode_DEH_PackCode() \
  (&((*RteIWriteRef_DEH_1000ms_DEH_PackCode_DEH_PackCode())[0]))

#define RteIWriteRef_DEH_1000ms_DEH_PackCode_DEH_PackCode() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_PackCode_DEH_PackCode.value \
)

#define Rte_IWrite_RoutineServices_0x05F3_Start_Services_DEH_ReqBalCtl_DEH_ReqBalCtl(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_ReqBalCtl_DEH_ReqBalCtl.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F3_Start_Services_DEH_ReqBalCtl_DEH_ReqBalCtl() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start_Services.Rte_DEH_ReqBalCtl_DEH_ReqBalCtl.value \
)

#define Rte_IWrite_RoutineServices_0x4000_Start_Services_DEH_ReqRlyCh_DEH_ReqRlyCh(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services.Rte_DEH_ReqRlyCh_DEH_ReqRlyCh.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x4000_Start_Services_DEH_ReqRlyCh_DEH_ReqRlyCh() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services.Rte_DEH_ReqRlyCh_DEH_ReqRlyCh.value \
)

#define Rte_IWrite_RoutineServices_0x4F03_Start_Services_DEH_ReqRlyNeg_DEH_ReqRlyNeg(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services.Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x4F03_Start_Services_DEH_ReqRlyNeg_DEH_ReqRlyNeg() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services.Rte_DEH_ReqRlyNeg_DEH_ReqRlyNeg.value \
)

#define Rte_IWrite_RoutineServices_0x4F02_Start_Services_DEH_ReqRlyPos_DEH_ReqRlyPos(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services.Rte_DEH_ReqRlyPos_DEH_ReqRlyPos.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x4F02_Start_Services_DEH_ReqRlyPos_DEH_ReqRlyPos() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services.Rte_DEH_ReqRlyPos_DEH_ReqRlyPos.value \
)

#define Rte_IWrite_RoutineServices_0x4F04_Start_Services_DEH_ReqRlyPrech_DEH_ReqRlyPrech(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services.Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x4F04_Start_Services_DEH_ReqRlyPrech_DEH_ReqRlyPrech() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services.Rte_DEH_ReqRlyPrech_DEH_ReqRlyPrech.value \
)

#define Rte_IWrite_DEH_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value \
)

#define Rte_IWrite_DEH_10ms_DEH_StFltLampIndcn_DEH_StFltLampIndcn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_StFltLampIndcn_DEH_StFltLampIndcn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value \
)

#define Rte_IWrite_DEH_Init_DEH_StFltLampIndcn_DEH_StFltLampIndcn(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_DEH_StFltLampIndcn_DEH_StFltLampIndcn() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_StFltLampIndcn_DEH_StFltLampIndcn.value \
)

#define Rte_IWrite_RoutineServices_0x400F_Start_Services_DEH_StIslnMeasReq_DEH_StIslnMeasReq(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services.Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x400F_Start_Services_DEH_StIslnMeasReq_DEH_StIslnMeasReq() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Services.Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq.value \
)

#define Rte_IWrite_RoutineServices_0x05F5_Start_Services_DEH_StSocCal_DEH_StSocCal(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services.Rte_DEH_StSocCal_DEH_StSocCal.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F5_Start_Services_DEH_StSocCal_DEH_StSocCal() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services.Rte_DEH_StSocCal_DEH_StSocCal.value \
)

#define Rte_IWrite_NVM_Read_10ms_DEH_StsIninNv_DEH_StsIninNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_DEH_StsIninNv_DEH_StsIninNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value \
)

#define Rte_IWrite_DEH_Init_DEH_StsIninNv_DEH_StsIninNv(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_StsIninNv_DEH_StsIninNv.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_DEH_StsIninNv_DEH_StsIninNv() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_StsIninNv_DEH_StsIninNv.value \
)

#define Rte_IWrite_NVM_Read_10ms_DEH_TiChFullOff_DEH_TiChFullOff(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_DEH_TiChFullOff_DEH_TiChFullOff() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value \
)

#define Rte_IWrite_DEH_Init_DEH_TiChFullOff_DEH_TiChFullOff(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_DEH_TiChFullOff_DEH_TiChFullOff() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_TiChFullOff_DEH_TiChFullOff.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_UBatNom_DEH_UBatNom(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_UBatNom_DEH_UBatNom.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_UBatNom_DEH_UBatNom() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_UBatNom_DEH_UBatNom.value \
)

#define Rte_IWrite_DEH_10ms_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_VCU_ChgFaultReq_DEH_VCU_ChgFaultReq.value \
)

#define Rte_IWrite_DEH_10ms_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_VCU_DischgFaultReq_DEH_VCU_DischgFaultReq.value \
)

#define Rte_IWrite_DEH_10ms_DEH_ValCodDiag_DEH_ValCodDiag(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_ValCodDiag_DEH_ValCodDiag() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value \
)

#define Rte_IWrite_DEH_Init_DEH_ValCodDiag_DEH_ValCodDiag(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_DEH_ValCodDiag_DEH_ValCodDiag() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_ValCodDiag_DEH_ValCodDiag.value \
)

#define Rte_IWrite_RoutineServices_0x05F5_Start_Services_DEH_ValPackSoc_DEH_ValPackSoc(data) \
( \
  Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services.Rte_DEH_ValPackSoc_DEH_ValPackSoc.value = (data) \
)

#define Rte_IWriteRef_RoutineServices_0x05F5_Start_Services_DEH_ValPackSoc_DEH_ValPackSoc() \
( \
  &Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start_Services.Rte_DEH_ValPackSoc_DEH_ValPackSoc.value \
)

#define Rte_IWrite_DEH_1000ms_DEH_YearBatMfctr_DEH_YearBatMfctr(data) \
( \
  Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_YearBatMfctr_DEH_YearBatMfctr.value = (data) \
)

#define Rte_IWriteRef_DEH_1000ms_DEH_YearBatMfctr_DEH_YearBatMfctr() \
( \
  &Rte_App1_Task_1000ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_1000ms.Rte_DEH_YearBatMfctr_DEH_YearBatMfctr.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvAcChInh_DEH_bAcvAcChInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvAcChInh_DEH_bAcvAcChInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvAcChInh_DEH_bAcvAcChInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvAcPwrChInh_DEH_bAcvAcPwrChInh.value \
)

#define Rte_IWrite_NVM_Read_10ms_DEH_bAcvBdNew_DEH_bAcvBdNew(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_DEH_bAcvBdNew_DEH_bAcvBdNew() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value \
)

#define Rte_IWrite_DEH_Init_DEH_bAcvBdNew_DEH_bAcvBdNew(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_DEH_bAcvBdNew_DEH_bAcvBdNew() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvChInh_DEH_bAcvChInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvChInh_DEH_bAcvChInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvChInh_DEH_bAcvChInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvDcChInh_DEH_bAcvDcChInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvDcChInh_DEH_bAcvDcChInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDcChInh_DEH_bAcvDcChInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDcPwrChInh_DEH_bAcvDcPwrChInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvDchaInh_DEH_bAcvDchaInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvDchaInh_DEH_bAcvDchaInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvDchaInh_DEH_bAcvDchaInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvHeatInh_DEH_bAcvHeatInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvHeatInh_DEH_bAcvHeatInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb1_DEH_bAcvLvlErrSb1.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb2_DEH_bAcvLvlErrSb2.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvLvlErrSb3_DEH_bAcvLvlErrSb3.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPowupInh_DEH_bAcvPowupInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPowupInh_DEH_bAcvPowupInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPowupInh_DEH_bAcvPowupInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrChLim1_DEH_bAcvPwrChLim1.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrChLim2_DEH_bAcvPwrChLim2.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrDchaLim1_DEH_bAcvPwrDchaLim1.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrDchaLim2_DEH_bAcvPwrDchaLim2.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrRecupLim1_DEH_bAcvPwrRecupLim1.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrRecupLim2_DEH_bAcvPwrRecupLim2.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvPwrdNorm_DEH_bAcvPwrdNorm.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvRecupInh_DEH_bAcvRecupInh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvRecupInh_DEH_bAcvRecupInh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvRecupInh_DEH_bAcvRecupInh.value \
)

#define Rte_IWrite_DEH_10ms_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm.value = (data) \
)

#define Rte_IWriteRef_DEH_10ms_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_10ms.Rte_DEH_bAcvSleepNorm_DEH_bAcvSleepNorm.value \
)

#define Rte_IRead_SetEventStatus_10ms_ELHPN_ErrInfo_ELHPN_ErrInfo() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SetEventStatus_10ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x053C_22_RE_ELHPN_RIslnNeg_ELHPN_RIslnNeg() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053C_22_RE.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value)

#define Rte_IRead_NVM_Write_100ms_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x053B_22_RE_ELHPN_RIslnPos_ELHPN_RIslnPos() \
  (Rte_App1_Task0_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x053B_22_RE.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value)

#define Rte_IRead_NVM_Write_100ms_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Write_100ms.Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x058B_22_RE_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x058B_22_RE.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x0595_22_RE_ELHPN_StIsln_ELHPN_StIsln() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0595_22_RE.Rte_ELHPN_StIsln_ELHPN_StIsln.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05CB_22_RE_EVCSH_ChMode_EVCSH_ChMode() \
  (Rte_App1_Task2_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05CB_22_RE.Rte_EVCSH_ChMode_EVCSH_ChMode.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x059F_22_RE_EVCSH_IChrgrSp_EVCSH_IChrgrSp() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x059F_22_RE.Rte_EVCSH_IChrgrSp_EVCSH_IChrgrSp.value)

#define Rte_IRead_SWC_TestDCM_DataServices_DspData_0x05C9_22_RE_EVCSH_UChrgrSp_EVCSH_UChrgrSp() \
  (Rte_App1_Task1_UDS_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x05C9_22_RE.Rte_EVCSH_UChrgrSp_EVCSH_UChrgrSp.value)

#define Rte_IWrite_NVM_Read_10ms_NVM_CBatChTot_NVM_CBatChTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatChTot_NVM_CBatChTot.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CBatChTot_NVM_CBatChTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatChTot_NVM_CBatChTot.value \
)

#define Rte_IWrite_DEH_Init_NVM_CBatChTot_NVM_CBatChTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatChTot_NVM_CBatChTot.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CBatChTot_NVM_CBatChTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatChTot_NVM_CBatChTot.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CBatDchaTot_NVM_CBatDchaTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CBatDchaTot_NVM_CBatDchaTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value \
)

#define Rte_IWrite_DEH_Init_NVM_CBatDchaTot_NVM_CBatDchaTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CBatDchaTot_NVM_CBatDchaTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatDchaTot_NVM_CBatDchaTot.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value \
)

#define Rte_IWrite_DEH_Init_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CBatRecoveryTot_NVM_CBatRecoveryTot.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls(data) \
  RteIWrite_DEH_Init_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls(data)

#define RteIWrite_DEH_Init_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CMdulAgiFacFls_NVM_CMdulAgiFacFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_ChIIntglFls_NVM_ChIIntglFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_ChIIntglFls_NVM_ChIIntglFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_ChIIntglFls_NVM_ChIIntglFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_ChIIntglFls_NVM_ChIIntglFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_ChIIntglFls_NVM_ChIIntglFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_ChgDeltAh_NVM_ChgDeltAh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_ChgDeltAh_NVM_ChgDeltAh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value \
)

#define Rte_IWrite_DEH_Init_NVM_ChgDeltAh_NVM_ChgDeltAh(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_ChgDeltAh_NVM_ChgDeltAh() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_ChgDeltAh_NVM_ChgDeltAh.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrCh_NVM_CtrCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCh_NVM_CtrCh.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrCh_NVM_CtrCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCh_NVM_CtrCh.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrCh_NVM_CtrCh(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCh_NVM_CtrCh.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrCh_NVM_CtrCh() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCh_NVM_CtrCh.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiCh_NVM_CtrCtctrAgiCh.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiHeat_NVM_CtrCtctrAgiHeat.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiNeg_NVM_CtrCtctrAgiNeg.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiPos_NVM_CtrCtctrAgiPos.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrCtctrAgiPrech_NVM_CtrCtctrAgiPrech.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_CtrDcha_NVM_CtrDcha(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrDcha_NVM_CtrDcha.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_CtrDcha_NVM_CtrDcha() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_CtrDcha_NVM_CtrDcha.value \
)

#define Rte_IWrite_DEH_Init_NVM_CtrDcha_NVM_CtrDcha(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrDcha_NVM_CtrDcha.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_CtrDcha_NVM_CtrDcha() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_CtrDcha_NVM_CtrDcha.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_DayRtcLst_NVM_DayRtcLst(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_DayRtcLst_NVM_DayRtcLst() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value \
)

#define Rte_IWrite_DEH_Init_NVM_DayRtcLst_NVM_DayRtcLst(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_DayRtcLst_NVM_DayRtcLst() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_DeltAh_NVM_DeltAh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_DeltAh_NVM_DeltAh.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_DeltAh_NVM_DeltAh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_DeltAh_NVM_DeltAh.value \
)

#define Rte_IWrite_DEH_Init_NVM_DeltAh_NVM_DeltAh(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_DeltAh_NVM_DeltAh.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_DeltAh_NVM_DeltAh() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_DeltAh_NVM_DeltAh.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_EBatChTot_NVM_EBatChTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_EBatChTot_NVM_EBatChTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatChTot_NVM_EBatChTot.value \
)

#define Rte_IWrite_DEH_Init_NVM_EBatChTot_NVM_EBatChTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatChTot_NVM_EBatChTot.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_EBatChTot_NVM_EBatChTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatChTot_NVM_EBatChTot.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_EBatDchaTot_NVM_EBatDchaTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_EBatDchaTot_NVM_EBatDchaTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value \
)

#define Rte_IWrite_DEH_Init_NVM_EBatDchaTot_NVM_EBatDchaTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_EBatDchaTot_NVM_EBatDchaTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatDchaTot_NVM_EBatDchaTot.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value \
)

#define Rte_IWrite_DEH_Init_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_EBatRecoveryTot_NVM_EBatRecoveryTot.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_FullChgSOH_NVM_FullChgSOH(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_FullChgSOH_NVM_FullChgSOH() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value \
)

#define Rte_IWrite_DEH_Init_NVM_FullChgSOH_NVM_FullChgSOH(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_FullChgSOH_NVM_FullChgSOH() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_FullChgSOH_NVM_FullChgSOH.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_HourRtcLst_NVM_HourRtcLst(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_HourRtcLst_NVM_HourRtcLst() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value \
)

#define Rte_IWrite_DEH_Init_NVM_HourRtcLst_NVM_HourRtcLst(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_HourRtcLst_NVM_HourRtcLst() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_IBatChMax_NVM_IBatChMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IBatChMax_NVM_IBatChMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_IBatChMax_NVM_IBatChMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IBatChMax_NVM_IBatChMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_IBatChMax_NVM_IBatChMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IBatChMax_NVM_IBatChMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_IBatChMax_NVM_IBatChMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IBatChMax_NVM_IBatChMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_IBatDchaMax_NVM_IBatDchaMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_IBatDchaMax_NVM_IBatDchaMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_IBatDchaMax_NVM_IBatDchaMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_IBatDchaMax_NVM_IBatDchaMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IBatDchaMax_NVM_IBatDchaMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_IIntglFls_NVM_IIntglFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IIntglFls_NVM_IIntglFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_IIntglFls_NVM_IIntglFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_IIntglFls_NVM_IIntglFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_IIntglFls_NVM_IIntglFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IIntglFls_NVM_IIntglFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_IIntglFls_NVM_IIntglFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_IIntglFls_NVM_IIntglFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_MinuRtcLst_NVM_MinuRtcLst(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_MinuRtcLst_NVM_MinuRtcLst() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value \
)

#define Rte_IWrite_DEH_Init_NVM_MinuRtcLst_NVM_MinuRtcLst(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_MinuRtcLst_NVM_MinuRtcLst() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_MonthRtcLst_NVM_MonthRtcLst(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_MonthRtcLst_NVM_MonthRtcLst() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value \
)

#define Rte_IWrite_DEH_Init_NVM_MonthRtcLst_NVM_MonthRtcLst(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_MonthRtcLst_NVM_MonthRtcLst() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_PBatChMax_NVM_PBatChMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_PBatChMax_NVM_PBatChMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_PBatChMax_NVM_PBatChMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_PBatChMax_NVM_PBatChMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_PBatChMax_NVM_PBatChMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_PBatChMax_NVM_PBatChMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_PBatChMax_NVM_PBatChMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_PBatChMax_NVM_PBatChMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_PBatDchaMax_NVM_PBatDchaMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_PBatDchaMax_NVM_PBatDchaMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_PBatDchaMax_NVM_PBatDchaMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_PBatDchaMax_NVM_PBatDchaMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_PBatDchaMax_NVM_PBatDchaMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_RIslnNeg_NVM_RIslnNeg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_RIslnNeg_NVM_RIslnNeg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value \
)

#define Rte_IWrite_DEH_Init_NVM_RIslnNeg_NVM_RIslnNeg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_RIslnNeg_NVM_RIslnNeg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_RIslnPos_NVM_RIslnPos(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RIslnPos_NVM_RIslnPos.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_RIslnPos_NVM_RIslnPos() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RIslnPos_NVM_RIslnPos.value \
)

#define Rte_IWrite_DEH_Init_NVM_RIslnPos_NVM_RIslnPos(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RIslnPos_NVM_RIslnPos.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_RIslnPos_NVM_RIslnPos() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RIslnPos_NVM_RIslnPos.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls(data) \
  RteIWrite_DEH_Init_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls(data)

#define RteIWrite_DEH_Init_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RMdulAgiFacFls_NVM_RMdulAgiFacFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln(data) \
  RteIWrite_NVM_Read_10ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln(data)

#define RteIWrite_NVM_Read_10ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value, data, sizeof(rt_Array_UInt8_255)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value \
)

#define Rte_IWrite_DEH_Init_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln(data) \
  RteIWrite_DEH_Init_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln(data)

#define RteIWrite_DEH_Init_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value, data, sizeof(rt_Array_UInt8_255)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln() \
  (&((*RteIWriteRef_DEH_Init_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln())[0]))

#define RteIWriteRef_DEH_Init_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value \
)

#define Rte_IWrite_DEH_Init_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SOHCalFulChgFlg_NVM_SOHCalFulChgFlg.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value \
)

#define Rte_IWrite_DEH_Init_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SOHCalOCVFlg_NVM_SOHCalOCVFlg.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SecRtcLst_NVM_SecRtcLst(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SecRtcLst_NVM_SecRtcLst() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value \
)

#define Rte_IWrite_DEH_Init_NVM_SecRtcLst_NVM_SecRtcLst(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SecRtcLst_NVM_SecRtcLst() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SocBatMax_NVM_SocBatMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocBatMax_NVM_SocBatMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SocBatMax_NVM_SocBatMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocBatMax_NVM_SocBatMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_SocBatMax_NVM_SocBatMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocBatMax_NVM_SocBatMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SocBatMax_NVM_SocBatMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocBatMax_NVM_SocBatMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SocBatMin_NVM_SocBatMin(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocBatMin_NVM_SocBatMin.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SocBatMin_NVM_SocBatMin() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocBatMin_NVM_SocBatMin.value \
)

#define Rte_IWrite_DEH_Init_NVM_SocBatMin_NVM_SocBatMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocBatMin_NVM_SocBatMin.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SocBatMin_NVM_SocBatMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocBatMin_NVM_SocBatMin.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SocCnsAct_NVM_SocCnsAct(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SocCnsAct_NVM_SocCnsAct() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value \
)

#define Rte_IWrite_DEH_Init_NVM_SocCnsAct_NVM_SocCnsAct(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SocCnsAct_NVM_SocCnsAct() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocCnsAct_NVM_SocCnsAct.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SocPackScld_NVM_SocPackScld(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocPackScld_NVM_SocPackScld.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SocPackScld_NVM_SocPackScld() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocPackScld_NVM_SocPackScld.value \
)

#define Rte_IWrite_DEH_Init_NVM_SocPackScld_NVM_SocPackScld(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocPackScld_NVM_SocPackScld.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SocPackScld_NVM_SocPackScld() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocPackScld_NVM_SocPackScld.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SocUOcIni_NVM_SocUOcIni(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SocUOcIni_NVM_SocUOcIni() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value \
)

#define Rte_IWrite_DEH_Init_NVM_SocUOcIni_NVM_SocUOcIni(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SocUOcIni_NVM_SocUOcIni() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SocUOcIni_NVM_SocUOcIni.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SohCalFls_NVM_SohCalFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohCalFls_NVM_SohCalFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SohCalFls_NVM_SohCalFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohCalFls_NVM_SohCalFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_SohCalFls_NVM_SohCalFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohCalFls_NVM_SohCalFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SohCalFls_NVM_SohCalFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohCalFls_NVM_SohCalFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SohCycFls_NVM_SohCycFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohCycFls_NVM_SohCycFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SohCycFls_NVM_SohCycFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohCycFls_NVM_SohCycFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_SohCycFls_NVM_SohCycFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohCycFls_NVM_SohCycFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SohCycFls_NVM_SohCycFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohCycFls_NVM_SohCycFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SohPackFls_NVM_SohPackFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohPackFls_NVM_SohPackFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SohPackFls_NVM_SohPackFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohPackFls_NVM_SohPackFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_SohPackFls_NVM_SohPackFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohPackFls_NVM_SohPackFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SohPackFls_NVM_SohPackFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohPackFls_NVM_SohPackFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_SohRDeltaFls_NVM_SohRDeltaFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_SohRDeltaFls_NVM_SohRDeltaFls(data) \
  RteIWrite_DEH_Init_NVM_SohRDeltaFls_NVM_SohRDeltaFls(data)

#define RteIWrite_DEH_Init_NVM_SohRDeltaFls_NVM_SohRDeltaFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SohRDeltaFls_NVM_SohRDeltaFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_SohRDeltaFls_NVM_SohRDeltaFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_SohRDeltaFls_NVM_SohRDeltaFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohRDeltaFls_NVM_SohRDeltaFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls(data) \
  RteIWrite_DEH_Init_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls(data)

#define RteIWrite_DEH_Init_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_SohSocDeltaFls_NVM_SohSocDeltaFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_StAryFls_NVM_StAryFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_StAryFls_NVM_StAryFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_StAryFls_NVM_StAryFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_StAryFls_NVM_StAryFls.value, data, sizeof(rt_Array_Float_144)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_StAryFls_NVM_StAryFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_StAryFls_NVM_StAryFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_StAryFls_NVM_StAryFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_StAryFls_NVM_StAryFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_StAryFls_NVM_StAryFls(data) \
  RteIWrite_DEH_Init_NVM_StAryFls_NVM_StAryFls(data)

#define RteIWrite_DEH_Init_NVM_StAryFls_NVM_StAryFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_StAryFls_NVM_StAryFls.value, data, sizeof(rt_Array_Float_144)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_StAryFls_NVM_StAryFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_StAryFls_NVM_StAryFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_StAryFls_NVM_StAryFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_StAryFls_NVM_StAryFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TMdulSnsrMax_NVM_TMdulSnsrMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value \
)

#define Rte_IWrite_DEH_Init_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TMdulSnsrMin_NVM_TMdulSnsrMin.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TPackFls_NVM_TPackFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TPackFls_NVM_TPackFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TPackFls_NVM_TPackFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TPackFls_NVM_TPackFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_TPackFls_NVM_TPackFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TPackFls_NVM_TPackFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TPackFls_NVM_TPackFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TPackFls_NVM_TPackFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TiBatAgi_NVM_TiBatAgi(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TiBatAgi_NVM_TiBatAgi() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value \
)

#define Rte_IWrite_DEH_Init_NVM_TiBatAgi_NVM_TiBatAgi(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TiBatAgi_NVM_TiBatAgi() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatAgi_NVM_TiBatAgi.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TiBatOffFls_NVM_TiBatOffFls(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TiBatOffFls_NVM_TiBatOffFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_TiBatOffFls_NVM_TiBatOffFls(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TiBatOffFls_NVM_TiBatOffFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffFls_NVM_TiBatOffFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls(data) \
  RteIWrite_DEH_Init_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls(data)

#define RteIWrite_DEH_Init_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffForMdulCFls_NVM_TiBatOffForMdulCFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls(data) \
  RteIWrite_DEH_Init_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls(data)

#define RteIWrite_DEH_Init_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_TiBatOffForMdulRFls_NVM_TiBatOffForMdulRFls.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrClsdMax_NVM_UBatCtctrClsdMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value \
)

#define Rte_IWrite_DEH_Init_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrClsdMin_NVM_UBatCtctrClsdMin.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrOpenMax_NVM_UBatCtctrOpenMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value \
)

#define Rte_IWrite_DEH_Init_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UBatCtctrOpenMin_NVM_UBatCtctrOpenMin.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UCellMax_NVM_UCellMax(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UCellMax_NVM_UCellMax.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UCellMax_NVM_UCellMax() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UCellMax_NVM_UCellMax.value \
)

#define Rte_IWrite_DEH_Init_NVM_UCellMax_NVM_UCellMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UCellMax_NVM_UCellMax.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UCellMax_NVM_UCellMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UCellMax_NVM_UCellMax.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UCellMin_NVM_UCellMin(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UCellMin_NVM_UCellMin.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UCellMin_NVM_UCellMin() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UCellMin_NVM_UCellMin.value \
)

#define Rte_IWrite_DEH_Init_NVM_UCellMin_NVM_UCellMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UCellMin_NVM_UCellMin.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UCellMin_NVM_UCellMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UCellMin_NVM_UCellMin.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_UPrechAccumd_NVM_UPrechAccumd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_UPrechAccumd_NVM_UPrechAccumd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value \
)

#define Rte_IWrite_DEH_Init_NVM_UPrechAccumd_NVM_UPrechAccumd(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_UPrechAccumd_NVM_UPrechAccumd() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_UPrechAccumd_NVM_UPrechAccumd.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_YearRtcLst_NVM_YearRtcLst(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value = (data) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_YearRtcLst_NVM_YearRtcLst() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value \
)

#define Rte_IWrite_DEH_Init_NVM_YearRtcLst_NVM_YearRtcLst(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value = (data) \
)

#define Rte_IWriteRef_DEH_Init_NVM_YearRtcLst_NVM_YearRtcLst() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value \
)

#define Rte_IWrite_NVM_Read_10ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls(data) \
  RteIWrite_NVM_Read_10ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls(data)

#define RteIWrite_NVM_Read_10ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_NVM_Read_10ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls() \
  (&((*RteIWriteRef_NVM_Read_10ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls())[0]))

#define RteIWriteRef_NVM_Read_10ms_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_DiagcEveHndlg_NVM_Read_10ms.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value \
)

#define Rte_IWrite_DEH_Init_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls(data) \
  RteIWrite_DEH_Init_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls(data)

#define RteIWrite_DEH_Init_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_DEH_Init_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls() \
  (&((*RteIWriteRef_DEH_Init_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls())[0]))

#define RteIWriteRef_DEH_Init_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_DiagcEveHndlg_DEH_Init.Rte_NVM_bErrMdulSocInvldFls_NVM_bErrMdulSocInvldFls.value \
)

/*
************************************************************************************************************************
*    Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Trigger_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_GetInputInterface_CODE) DiagcEvent_GetEvent(VAR(UInt16, RTE_swc_GetInputInterface_APPL_DATA) DTC_ID, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) EventStatusByte);
FUNC(void, swc_GetInputInterface_CODE) DiagcEvent_SetEvent(VAR(UInt16, RTE_swc_GetInputInterface_APPL_DATA) ID, VAR(UInt8_T, RTE_swc_GetInputInterface_APPL_DATA) EventStatus);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID1_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID10_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID11_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID12_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID13_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID14_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID15_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID16_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID17_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID18_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID19_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID2_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID20_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID21_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID22_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID23_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID24_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID25_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID26_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID27_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID28_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID29_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID3_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID30_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID4_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID5_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID6_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID7_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID8_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_GetInputInterface_CODE) Func_FiMFID9_GetFunctionPermission(P2VAR(Boolean_T, AUTOMATIC, RTE_swc_GetInputInterface_APPL_DATA) Permission);
FUNC(Std_ReturnType, swc_SetOutputInterface_CODE) Ram_Service_ReadStatus(VAR(UInt32_T, RTE_swc_SetOutputInterface_APPL_DATA) BlockId, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_SetOutputInterface_APPL_DATA) blockstatus);
FUNC(Std_ReturnType, swc_SetOutputInterface_CODE) Ram_Service_Write(VAR(UInt32_T, RTE_swc_SetOutputInterface_APPL_DATA) block_Id, VAR(UInt8_T, RTE_swc_SetOutputInterface_APPL_DATA) write);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_DiagcEvent_GetEvent Rte_Call_swc_DiagcEveHndlg_DiagcEvent_GetEvent
#define Rte_Call_swc_DiagcEveHndlg_DiagcEvent_GetEvent(arg1, arg2) (DiagcEvent_GetEvent(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_DiagcEvent_SetEvent Rte_Call_swc_DiagcEveHndlg_DiagcEvent_SetEvent
#define Rte_Call_swc_DiagcEveHndlg_DiagcEvent_SetEvent(arg1, arg2) (DiagcEvent_SetEvent(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#define Rte_Call_Func_FiMFID1_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID1_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID1_GetFunctionPermission Func_FiMFID1_GetFunctionPermission
#define Rte_Call_Func_FiMFID10_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID10_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID10_GetFunctionPermission Func_FiMFID10_GetFunctionPermission
#define Rte_Call_Func_FiMFID11_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID11_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID11_GetFunctionPermission Func_FiMFID11_GetFunctionPermission
#define Rte_Call_Func_FiMFID12_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID12_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID12_GetFunctionPermission Func_FiMFID12_GetFunctionPermission
#define Rte_Call_Func_FiMFID13_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID13_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID13_GetFunctionPermission Func_FiMFID13_GetFunctionPermission
#define Rte_Call_Func_FiMFID14_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID14_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID14_GetFunctionPermission Func_FiMFID14_GetFunctionPermission
#define Rte_Call_Func_FiMFID15_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID15_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID15_GetFunctionPermission Func_FiMFID15_GetFunctionPermission
#define Rte_Call_Func_FiMFID16_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID16_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID16_GetFunctionPermission Func_FiMFID16_GetFunctionPermission
#define Rte_Call_Func_FiMFID17_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID17_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID17_GetFunctionPermission Func_FiMFID17_GetFunctionPermission
#define Rte_Call_Func_FiMFID18_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID18_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID18_GetFunctionPermission Func_FiMFID18_GetFunctionPermission
#define Rte_Call_Func_FiMFID19_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID19_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID19_GetFunctionPermission Func_FiMFID19_GetFunctionPermission
#define Rte_Call_Func_FiMFID2_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID2_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID2_GetFunctionPermission Func_FiMFID2_GetFunctionPermission
#define Rte_Call_Func_FiMFID20_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID20_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID20_GetFunctionPermission Func_FiMFID20_GetFunctionPermission
#define Rte_Call_Func_FiMFID21_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID21_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID21_GetFunctionPermission Func_FiMFID21_GetFunctionPermission
#define Rte_Call_Func_FiMFID22_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID22_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID22_GetFunctionPermission Func_FiMFID22_GetFunctionPermission
#define Rte_Call_Func_FiMFID23_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID23_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID23_GetFunctionPermission Func_FiMFID23_GetFunctionPermission
#define Rte_Call_Func_FiMFID24_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID24_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID24_GetFunctionPermission Func_FiMFID24_GetFunctionPermission
#define Rte_Call_Func_FiMFID25_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID25_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID25_GetFunctionPermission Func_FiMFID25_GetFunctionPermission
#define Rte_Call_Func_FiMFID26_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID26_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID26_GetFunctionPermission Func_FiMFID26_GetFunctionPermission
#define Rte_Call_Func_FiMFID27_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID27_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID27_GetFunctionPermission Func_FiMFID27_GetFunctionPermission
#define Rte_Call_Func_FiMFID28_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID28_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID28_GetFunctionPermission Func_FiMFID28_GetFunctionPermission
#define Rte_Call_Func_FiMFID29_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID29_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID29_GetFunctionPermission Func_FiMFID29_GetFunctionPermission
#define Rte_Call_Func_FiMFID3_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID3_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID3_GetFunctionPermission Func_FiMFID3_GetFunctionPermission
#define Rte_Call_Func_FiMFID30_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID30_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID30_GetFunctionPermission Func_FiMFID30_GetFunctionPermission
#define Rte_Call_Func_FiMFID4_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID4_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID4_GetFunctionPermission Func_FiMFID4_GetFunctionPermission
#define Rte_Call_Func_FiMFID5_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID5_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID5_GetFunctionPermission Func_FiMFID5_GetFunctionPermission
#define Rte_Call_Func_FiMFID6_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID6_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID6_GetFunctionPermission Func_FiMFID6_GetFunctionPermission
#define Rte_Call_Func_FiMFID7_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID7_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID7_GetFunctionPermission Func_FiMFID7_GetFunctionPermission
#define Rte_Call_Func_FiMFID8_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID8_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID8_GetFunctionPermission Func_FiMFID8_GetFunctionPermission
#define Rte_Call_Func_FiMFID9_GetFunctionPermission Rte_Call_swc_DiagcEveHndlg_Func_FiMFID9_GetFunctionPermission
#define Rte_Call_swc_DiagcEveHndlg_Func_FiMFID9_GetFunctionPermission Func_FiMFID9_GetFunctionPermission
#define Rte_Call_Ram_Service_ReadStatus Rte_Call_swc_DiagcEveHndlg_Ram_Service_ReadStatus
#define Rte_Call_swc_DiagcEveHndlg_Ram_Service_ReadStatus Ram_Service_ReadStatus
#define Rte_Call_Ram_Service_Write Rte_Call_swc_DiagcEveHndlg_Ram_Service_Write
#define Rte_Call_swc_DiagcEveHndlg_Ram_Service_Write Ram_Service_Write
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IrvRead_<p>_<d> and Rte_IrvWrite_<p>_<d> Inter-runnable variables
************************************************************************************************************************
*/
#define Rte_IrvIRead_NVM_Write_100ms_DEH_CtrErrCfmdNv Rte_IrvRead_swc_DiagcEveHndlg_NVM_Write_100ms_DEH_CtrErrCfmdNv
#define Rte_IrvIRead_SWC_TestDCM_DataServices_DspData_0xDF02_22_RE_DEH_CtrErrCfmdNv Rte_IrvRead_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0xDF02_22_RE_DEH_CtrErrCfmdNv
#define Rte_IrvIRead_DEH_10ms_DEH_CtrFctInhDeacStopDiag Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_CtrFctInhDeacStopDiag
#define Rte_IrvIRead_DEH_10ms_DEH_CtrFctInhDeacStrtDiag Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_CtrFctInhDeacStrtDiag
#define Rte_IrvIRead_DEH_1000ms_DEH_CtrRlyReqDiagCh Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagCh
#define Rte_IrvIRead_DEH_1000ms_DEH_CtrRlyReqDiagNeg Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagNeg
#define Rte_IrvIRead_DEH_1000ms_DEH_CtrRlyReqDiagPos Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagPos
#define Rte_IrvIRead_DEH_1000ms_DEH_CtrRlyReqDiagPrech Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_CtrRlyReqDiagPrech
#define Rte_IrvIRead_DEH_10ms_DEH_ErrCfmd1 Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd1
#define Rte_IrvIRead_DEH_10ms_DEH_ErrCfmd2 Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd2
#define Rte_IrvIRead_DEH_10ms_DEH_ErrCfmd3 Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd3
#define Rte_IrvIRead_DEH_10ms_DEH_ErrCfmd4 Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd4
#define Rte_IrvIRead_DEH_10ms_DEH_ErrCfmd5 Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd5
#define Rte_IrvIRead_DEH_10ms_DEH_ErrCfmd6 Rte_IrvRead_swc_DiagcEveHndlg_DEH_10ms_DEH_ErrCfmd6
#define Rte_IrvIRead_SWC_TestDCM_DataServices_DspData_0x0537_22_RE_DEH_LvlErr Rte_IrvRead_swc_DiagcEveHndlg_SWC_TestDCM_DataServices_DspData_0x0537_22_RE_DEH_LvlErr
#define Rte_IrvIRead_DEH_1000ms_DEH_ReqRlyCh Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyCh
#define Rte_IrvIRead_DEH_1000ms_DEH_ReqRlyNeg Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyNeg
#define Rte_IrvIRead_DEH_1000ms_DEH_ReqRlyPos Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyPos
#define Rte_IrvIRead_DEH_1000ms_DEH_ReqRlyPrech Rte_IrvRead_swc_DiagcEveHndlg_DEH_1000ms_DEH_ReqRlyPrech
#define Rte_IrvIRead_GetEventStatus_10ms_DEH_StsIninNv Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_StsIninNv
#define Rte_IrvIRead_GetEventStatus_10ms_DEH_bAcvBdNew Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_bAcvBdNew
#define Rte_IrvIRead_GetEventStatus_10ms_NVM_CtrErrCfmd Rte_IrvRead_swc_DiagcEveHndlg_GetEventStatus_10ms_NVM_CtrErrCfmd

#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_CtrErrCfmdNv Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_CtrErrCfmdNv
#define Rte_IrvIWrite_RoutineServices_0x05F6_Stop_Services_DEH_CtrFctInhDeacStopDiag Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop_Services_DEH_CtrFctInhDeacStopDiag
#define Rte_IrvIWrite_RoutineServices_0x05F6_Start_Services_DEH_CtrFctInhDeacStrtDiag Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start_Services_DEH_CtrFctInhDeacStrtDiag
#define Rte_IrvIWrite_RoutineServices_0x4000_Start_Services_DEH_CtrRlyReqDiagCh Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services_DEH_CtrRlyReqDiagCh
#define Rte_IrvIWrite_RoutineServices_0x4F03_Start_Services_DEH_CtrRlyReqDiagNeg Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services_DEH_CtrRlyReqDiagNeg
#define Rte_IrvIWrite_RoutineServices_0x4F02_Start_Services_DEH_CtrRlyReqDiagPos Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services_DEH_CtrRlyReqDiagPos
#define Rte_IrvIWrite_RoutineServices_0x4F04_Start_Services_DEH_CtrRlyReqDiagPrech Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services_DEH_CtrRlyReqDiagPrech
#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_ErrCfmd1 Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd1
#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_ErrCfmd2 Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd2
#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_ErrCfmd3 Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd3
#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_ErrCfmd4 Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd4
#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_ErrCfmd5 Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd5
#define Rte_IrvIWrite_GetEventStatus_10ms_DEH_ErrCfmd6 Rte_IrvWrite_swc_DiagcEveHndlg_GetEventStatus_10ms_DEH_ErrCfmd6
#define Rte_IrvIWrite_DEH_10ms_DEH_LvlErr Rte_IrvWrite_swc_DiagcEveHndlg_DEH_10ms_DEH_LvlErr
#define Rte_IrvIWrite_RoutineServices_0x4000_Start_Services_DEH_ReqRlyCh Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Services_DEH_ReqRlyCh
#define Rte_IrvIWrite_RoutineServices_0x4F03_Start_Services_DEH_ReqRlyNeg Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Services_DEH_ReqRlyNeg
#define Rte_IrvIWrite_RoutineServices_0x4F02_Start_Services_DEH_ReqRlyPos Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Services_DEH_ReqRlyPos
#define Rte_IrvIWrite_RoutineServices_0x4F04_Start_Services_DEH_ReqRlyPrech Rte_IrvWrite_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Services_DEH_ReqRlyPrech
#define Rte_IrvIWrite_DEH_Init_DEH_StsIninNv Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_DEH_StsIninNv
#define Rte_IrvIWrite_NVM_Read_10ms_DEH_StsIninNv Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_DEH_StsIninNv
#define Rte_IrvIWrite_DEH_Init_DEH_bAcvBdNew Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_DEH_bAcvBdNew
#define Rte_IrvIWrite_NVM_Read_10ms_DEH_bAcvBdNew Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_DEH_bAcvBdNew
#define Rte_IrvIWrite_DEH_Init_NVM_CtrErrCfmd Rte_IrvWrite_swc_DiagcEveHndlg_DEH_Init_NVM_CtrErrCfmd
#define Rte_IrvIWrite_NVM_Read_10ms_NVM_CtrErrCfmd Rte_IrvWrite_swc_DiagcEveHndlg_NVM_Read_10ms_NVM_CtrErrCfmd

/*
************************************************************************************************************************
*    extern declaration of calibration parameters buffers
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_CData (SW-C local calibration parameters) and Rte_Prm (Calibration component calibration parameters)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of Buffers for Memory Block
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(rt_Array_UInt8_4, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D5_Ram;
extern VAR(rt_Array_UInt8_4, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D6_Ram;
extern VAR(rt_Array_UInt8_3, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D7_Ram;
extern VAR(rt_Array_UInt8_2, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D8_Ram;
extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05D9_Ram;
extern VAR(UInt8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05DA_Ram;
extern VAR(rt_Array_UInt8_24, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_05DB_Ram;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App1;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App2;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App3;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App4;
extern VAR(rt_Array_UInt8_256, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_App5;
extern VAR(rt_Array_UInt8_17, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_swc_DiagcEveHndlg_NvRam_F190_Ram;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Rte_Pim (Per-Instance Memory)
************************************************************************************************************************
*/
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_05D5_Ram() (&(Rte_swc_DiagcEveHndlg_NvRam_05D5_Ram[0]))
#else
#define Rte_Pim_NvRam_05D5_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05D5_Ram)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_05D6_Ram() (&(Rte_swc_DiagcEveHndlg_NvRam_05D6_Ram[0]))
#else
#define Rte_Pim_NvRam_05D6_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05D6_Ram)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_05D7_Ram() (&(Rte_swc_DiagcEveHndlg_NvRam_05D7_Ram[0]))
#else
#define Rte_Pim_NvRam_05D7_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05D7_Ram)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_05D8_Ram() (&(Rte_swc_DiagcEveHndlg_NvRam_05D8_Ram[0]))
#else
#define Rte_Pim_NvRam_05D8_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05D8_Ram)
#endif
#define Rte_Pim_NvRam_05D9_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05D9_Ram)
#define Rte_Pim_NvRam_05DA_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05DA_Ram)
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_05DB_Ram() (&(Rte_swc_DiagcEveHndlg_NvRam_05DB_Ram[0]))
#else
#define Rte_Pim_NvRam_05DB_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_05DB_Ram)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_App1() (&(Rte_swc_DiagcEveHndlg_NvRam_App1[0]))
#else
#define Rte_Pim_NvRam_App1() (&Rte_swc_DiagcEveHndlg_NvRam_App1)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_App2() (&(Rte_swc_DiagcEveHndlg_NvRam_App2[0]))
#else
#define Rte_Pim_NvRam_App2() (&Rte_swc_DiagcEveHndlg_NvRam_App2)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_App3() (&(Rte_swc_DiagcEveHndlg_NvRam_App3[0]))
#else
#define Rte_Pim_NvRam_App3() (&Rte_swc_DiagcEveHndlg_NvRam_App3)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_App4() (&(Rte_swc_DiagcEveHndlg_NvRam_App4[0]))
#else
#define Rte_Pim_NvRam_App4() (&Rte_swc_DiagcEveHndlg_NvRam_App4)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_App5() (&(Rte_swc_DiagcEveHndlg_NvRam_App5[0]))
#else
#define Rte_Pim_NvRam_App5() (&Rte_swc_DiagcEveHndlg_NvRam_App5)
#endif
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
#define Rte_Pim_NvRam_F190_Ram() (&(Rte_swc_DiagcEveHndlg_NvRam_F190_Ram[0]))
#else
#define Rte_Pim_NvRam_F190_Ram() (&Rte_swc_DiagcEveHndlg_NvRam_F190_Ram)
#endif
/*
************************************************************************************************************************
*    Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_DiagcEveHndlg_CODE) DEH_1000ms(void);
FUNC(void, swc_DiagcEveHndlg_CODE) DEH_10ms(void);
FUNC(void, swc_DiagcEveHndlg_CODE) DEH_Init(void);
FUNC(void, swc_DiagcEveHndlg_CODE) GetEventStatus_10ms(void);
FUNC(void, swc_DiagcEveHndlg_CODE) NVM_Read_10ms(void);
FUNC(void, swc_DiagcEveHndlg_CODE) NVM_Write_100ms(void);
FUNC(void, swc_DiagcEveHndlg_CODE) SetEventStatus_10ms(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#if 0 //UDS不使用
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x03E2_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x03E2_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x03E2_Stop Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x03E2_Stop_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F2_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start RoutineServices_0x05F2_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F2_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F3_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start RoutineServices_0x05F3_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F3_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F4_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start RoutineServices_0x05F4_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F4_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F5_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start RoutineServices_0x05F5_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F5_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F6_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start RoutineServices_0x05F6_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F6_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F6_Stop Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop RoutineServices_0x05F6_Stop_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F6_Stop_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4000_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4000_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x400F_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x400F_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F02_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F02_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F03_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F03_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F04_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F04_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0500_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0500_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0500_0_ReadData SWC_TestDCM_DataServices_DspData_0x0500_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0500_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0501_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0501_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0502_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0502_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0503_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0503_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0504_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0504_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0505_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0505_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0507_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0507_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x050A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x050A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0522_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0522_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0522_0_ReadData SWC_TestDCM_DataServices_DspData_0x0522_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0522_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0523_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0523_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0523_0_ReadData SWC_TestDCM_DataServices_DspData_0x0523_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0523_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0524_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0524_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0524_0_ReadData SWC_TestDCM_DataServices_DspData_0x0524_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0524_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0525_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0525_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0526_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0526_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0527_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0527_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0528_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0528_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0529_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0529_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052A_0_ReadData SWC_TestDCM_DataServices_DspData_0x052A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052C_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052C_0_ReadData SWC_TestDCM_DataServices_DspData_0x052C_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0530_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0530_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0531_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0531_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0532_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0532_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0533_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0533_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0534_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0534_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0535_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0535_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0536_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0536_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0537_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0537_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0538_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0538_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0539_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0539_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053A_0_ReadData SWC_TestDCM_DataServices_DspData_0x053A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0542_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0542_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0543_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0543_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0544_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0544_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0545_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0545_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0547_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0547_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0552_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0552_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0585_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0585_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0586_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0586_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0587_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0587_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0588_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0588_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0589_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0589_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058F_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0590_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0590_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0591_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0591_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0592_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0592_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0593_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0593_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0594_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0594_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0595_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0595_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0596_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0596_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0597_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0597_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0598_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0598_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0599_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0599_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059F_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF05_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF05_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF06_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF07_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF07_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF09_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF09_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF09_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF09_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF09_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDD00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDD00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF01_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF01_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF02_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF02_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF03_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF03_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF04_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF04_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF05_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF05_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF05_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF05_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF05_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF06_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF07_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF07_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF07_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF07_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF07_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF09_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF09_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xF1A5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xF1A5_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xF1A5_0_ReadData SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#else
#define Rte_Call_RoutineServices_0x03E2_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start RoutineServices_0x03E2_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x03E2_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x03E2_Stop Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop RoutineServices_0x03E2_Stop_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x03E2_Stop_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F2_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F2_Start RoutineServices_0x05F2_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F2_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F3_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F3_Start RoutineServices_0x05F3_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F3_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F4_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F4_Start RoutineServices_0x05F4_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F4_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F5_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F5_Start RoutineServices_0x05F5_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F5_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F6_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Start RoutineServices_0x05F6_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F6_Start_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x05F6_Stop Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x05F6_Stop RoutineServices_0x05F6_Stop_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x05F6_Stop_Services(P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4000_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start RoutineServices_0x4000_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4000_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x400F_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start RoutineServices_0x400F_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x400F_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F02_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start RoutineServices_0x4F02_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F02_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F03_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start RoutineServices_0x4F03_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F03_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_RoutineServices_0x4F04_Start Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start
#define Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start RoutineServices_0x4F04_Start_Services
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) RoutineServices_0x4F04_Start_Services(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0500_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0500_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0500_0_ReadData SWC_TestDCM_DataServices_DspData_0x0500_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0500_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0501_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData SWC_TestDCM_DataServices_DspData_0x0501_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0501_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0502_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData SWC_TestDCM_DataServices_DspData_0x0502_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0502_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0503_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData SWC_TestDCM_DataServices_DspData_0x0503_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0503_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0504_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData SWC_TestDCM_DataServices_DspData_0x0504_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0504_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0505_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData SWC_TestDCM_DataServices_DspData_0x0505_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0505_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0507_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData SWC_TestDCM_DataServices_DspData_0x0507_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0507_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x050A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData SWC_TestDCM_DataServices_DspData_0x050A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x050A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0522_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0522_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0522_0_ReadData SWC_TestDCM_DataServices_DspData_0x0522_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0522_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0523_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0523_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0523_0_ReadData SWC_TestDCM_DataServices_DspData_0x0523_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0523_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0524_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0524_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0524_0_ReadData SWC_TestDCM_DataServices_DspData_0x0524_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0524_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0525_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData SWC_TestDCM_DataServices_DspData_0x0525_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0525_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0526_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData SWC_TestDCM_DataServices_DspData_0x0526_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0526_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0527_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData SWC_TestDCM_DataServices_DspData_0x0527_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0527_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0528_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData SWC_TestDCM_DataServices_DspData_0x0528_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0528_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0529_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData SWC_TestDCM_DataServices_DspData_0x0529_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0529_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052A_0_ReadData SWC_TestDCM_DataServices_DspData_0x052A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData SWC_TestDCM_DataServices_DspData_0x052B_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052C_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052C_0_ReadData SWC_TestDCM_DataServices_DspData_0x052C_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData SWC_TestDCM_DataServices_DspData_0x052D_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x052E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData SWC_TestDCM_DataServices_DspData_0x052E_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x052E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0530_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData SWC_TestDCM_DataServices_DspData_0x0530_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0530_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0531_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData SWC_TestDCM_DataServices_DspData_0x0531_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0531_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0532_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData SWC_TestDCM_DataServices_DspData_0x0532_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0532_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0533_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData SWC_TestDCM_DataServices_DspData_0x0533_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0533_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0534_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData SWC_TestDCM_DataServices_DspData_0x0534_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0534_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0535_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData SWC_TestDCM_DataServices_DspData_0x0535_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0535_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0536_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData SWC_TestDCM_DataServices_DspData_0x0536_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0536_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0537_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData SWC_TestDCM_DataServices_DspData_0x0537_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0537_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0538_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData SWC_TestDCM_DataServices_DspData_0x0538_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0538_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0539_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData SWC_TestDCM_DataServices_DspData_0x0539_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0539_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053A_0_ReadData SWC_TestDCM_DataServices_DspData_0x053A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData SWC_TestDCM_DataServices_DspData_0x053B_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData SWC_TestDCM_DataServices_DspData_0x053C_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData SWC_TestDCM_DataServices_DspData_0x053D_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x053E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData SWC_TestDCM_DataServices_DspData_0x053E_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x053E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0542_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData SWC_TestDCM_DataServices_DspData_0x0542_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0542_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0543_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData SWC_TestDCM_DataServices_DspData_0x0543_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0543_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0544_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData SWC_TestDCM_DataServices_DspData_0x0544_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0544_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0545_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData SWC_TestDCM_DataServices_DspData_0x0545_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0545_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0547_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData SWC_TestDCM_DataServices_DspData_0x0547_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0547_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0552_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData SWC_TestDCM_DataServices_DspData_0x0552_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0552_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData SWC_TestDCM_DataServices_DspData_0x055A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData SWC_TestDCM_DataServices_DspData_0x055C_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x055D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData SWC_TestDCM_DataServices_DspData_0x055D_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x055D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0585_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData SWC_TestDCM_DataServices_DspData_0x0585_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0585_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0586_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData SWC_TestDCM_DataServices_DspData_0x0586_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0586_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0587_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData SWC_TestDCM_DataServices_DspData_0x0587_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0587_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0588_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData SWC_TestDCM_DataServices_DspData_0x0588_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0588_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0589_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData SWC_TestDCM_DataServices_DspData_0x0589_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0589_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData SWC_TestDCM_DataServices_DspData_0x058A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData SWC_TestDCM_DataServices_DspData_0x058B_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData SWC_TestDCM_DataServices_DspData_0x058C_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData SWC_TestDCM_DataServices_DspData_0x058D_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData SWC_TestDCM_DataServices_DspData_0x058E_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x058F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData SWC_TestDCM_DataServices_DspData_0x058F_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x058F_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0590_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData SWC_TestDCM_DataServices_DspData_0x0590_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0590_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0591_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData SWC_TestDCM_DataServices_DspData_0x0591_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0591_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0592_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData SWC_TestDCM_DataServices_DspData_0x0592_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0592_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0593_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData SWC_TestDCM_DataServices_DspData_0x0593_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0593_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0594_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData SWC_TestDCM_DataServices_DspData_0x0594_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0594_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0595_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData SWC_TestDCM_DataServices_DspData_0x0595_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0595_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0596_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData SWC_TestDCM_DataServices_DspData_0x0596_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0596_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0597_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData SWC_TestDCM_DataServices_DspData_0x0597_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0597_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0598_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData SWC_TestDCM_DataServices_DspData_0x0598_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0598_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x0599_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData SWC_TestDCM_DataServices_DspData_0x0599_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x0599_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059A_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData SWC_TestDCM_DataServices_DspData_0x059A_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059A_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059B_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData SWC_TestDCM_DataServices_DspData_0x059B_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059B_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059C_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData SWC_TestDCM_DataServices_DspData_0x059C_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059C_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059D_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData SWC_TestDCM_DataServices_DspData_0x059D_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059D_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059E_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData SWC_TestDCM_DataServices_DspData_0x059E_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059E_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x059F_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData SWC_TestDCM_DataServices_DspData_0x059F_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x059F_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A1_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A2_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A3_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A4_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A5_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A6_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A7_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A8_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05A9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData SWC_TestDCM_DataServices_DspData_0x05A9_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05A9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AA_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AB_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AC_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AD_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AE_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05AF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData SWC_TestDCM_DataServices_DspData_0x05AF_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05AF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B0_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B1_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B2_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B3_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B4_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B5_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B6_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B7_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B8_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05B9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData SWC_TestDCM_DataServices_DspData_0x05B9_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05B9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BA_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BB_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BC_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BD_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BE_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05BF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData SWC_TestDCM_DataServices_DspData_0x05BF_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05BF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C0_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C1_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C2_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C3_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C4_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C5_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C6_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C6_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C6_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C7_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C7_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C7_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C8_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C8_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C8_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05C9_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData SWC_TestDCM_DataServices_DspData_0x05C9_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05C9_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CA_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CA_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CA_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CB_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CB_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CB_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CC_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CC_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CC_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CD_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CD_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CD_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CE_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CE_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CE_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05CF_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData SWC_TestDCM_DataServices_DspData_0x05CF_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05CF_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D0_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D0_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D0_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D1_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D1_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D1_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D2_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D2_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D2_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D3_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D3_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D3_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0x05D4_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData SWC_TestDCM_DataServices_DspData_0x05D4_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0x05D4_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF00_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF05_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF05_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF05_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF06_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF06_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF07_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF07_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF07_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xCF09_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF09_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF09_0_ReadData SWC_TestDCM_DataServices_DspData_0xCF09_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xCF09_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDD00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData SWC_TestDCM_DataServices_DspData_0xDD00_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDD00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF00_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF00_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF00_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF01_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF01_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF01_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF02_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF02_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF02_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF03_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF03_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF03_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF04_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF04_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF04_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF05_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF05_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF05_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF05_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF05_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF06_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF06_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF06_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF07_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF07_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF07_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF07_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF07_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xDF09_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData SWC_TestDCM_DataServices_DspData_0xDF09_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xDF09_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#define Rte_Call_DataServices_DspData_0xF1A5_0_ReadData Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xF1A5_0_ReadData
#define Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xF1A5_0_ReadData SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE
FUNC(Std_ReturnType, swc_DiagcEveHndlg_CODE) SWC_TestDCM_DataServices_DspData_0xF1A5_22_RE(VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode);
#endif
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_SWC_DIAGCEVEHNDLG_H_ */
 
 
 
