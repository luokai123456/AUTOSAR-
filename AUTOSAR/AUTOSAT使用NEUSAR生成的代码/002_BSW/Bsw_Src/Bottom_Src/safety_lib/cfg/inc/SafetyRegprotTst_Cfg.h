/**
****************************************************************************************
 * @FilePath: SafetyRegprotTst_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Regprot test configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/

#ifndef SAFETYREGPROTTST_CFG_H
#define SAFETYREGPROTTST_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/**
****************************************************************************************
* Register protect instance enum
****************************************************************************************
*/
typedef enum
{	
    SAF_RP_SIUL2,
    SAF_RP_CMU,
    SAF_RP_PMC_DIG,
    SAF_RP_PLL_DIG,
    SAF_RP_OSC_DIG,
    SAF_RP_MEMU,
    SAF_RP_MC_ME,
    SAF_RP_MC_CGM,
    SAF_RP_MC_RGM,
    SAF_RP_SSCM,
    SAF_RP_IMA,
	SAF_RP_INSTANCE_COUNT,
} SAF_REG_PROT_INSTANCE;/*PRQA S 1535 EOF*/

#ifdef __cplusplus
}
#endif



#endif  
