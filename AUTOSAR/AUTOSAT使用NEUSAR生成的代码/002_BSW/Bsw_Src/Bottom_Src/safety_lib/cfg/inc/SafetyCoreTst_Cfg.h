/**
****************************************************************************************
 * @FilePath: SafetyCoreTst_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Core configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAFETYCORETST_CFG_H
#define SAFETYCORETST_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/ 

/**
****************************************************************************************
* @brief: Macros
****************************************************************************************
*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
#define SAF_DCF_RECORD_COUNT            (22U)

#define SAF_DCF_RECORD_LIST             {408232926338088960UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,0UL,5783775738754760832UL,14638485710114390148UL,14525868781395247240UL,5783775738754760852UL,14638485710114390168UL,14525868781395247260UL,15275833400553373700UL,3170910668862259204UL,4393752068120UL,524296UL,72057589743484944UL,704301622624268UL,72058697845047296UL}
                                                                                   
#define SAF_DCF_START_ADDR              (4195072)

#define SAF_ONLINE_MBIST_COUNT          (0U)

#define SAF_ONLINE_LBIST_COUNT          (0U)

#define SAF_ONLINE_MBIST_LIST            {0xFFU}

#define SAF_ONLINE_LBIST_LIST            {0xFFU}

#define SAF_OFFLINEBIST_FAIL_RESET        (STD_OFF)
/* Pmc fccu event enable config. */
#define SAF_PMC_FCCU_EVENT_ENABLE       (true)

                                                                                                                                                                                                                                                                                                                                
/* Modify the pmc_hvd high voltage threshold of PMC */
#define PMC_HVD_TRIM                    (0x4U)
/* Modify the pmc_lvd low voltage threshold of PMC */
#define PMC_LVD_TRIM                    (0xcU)

/* Modify the avdd_hvd high voltage threshold of PMC */
#define AVDD_HVD_TRIM                   (0x4U)
/* Modify the avdd_lvd low voltage threshold of PMC */
#define AVDD_LVD_TRIM                   (0xcU)

/* Modify the main_io_hvd high voltage threshold of PMC */
#define MAIN_IO_HVD_TRIM                (0x4U)
/* Modify the main_io_lvd low voltage threshold of PMC */
#define MAIN_IO_LVD_TRIM                (0xcU)

/* Modify the osc_hvd high voltage threshold of PMC */
#define OSC_HVD_TRIM                    (0x4U)
/* Modify the osc_lvd low voltage threshold of PMC */
#define OSC_LVD_TRIM                    (0xcU)

/* Modify the fla_hvd high voltage threshold of PMC */
#define FLA_HVD_TRIM                    (0x4U)
/* Modify the fla_lvd low voltage threshold of PMC */
#define FLA_LVD_TRIM                    (0xcU)

/* Modify the vddc_hvd high voltage threshold of PMC */
#define VDDC_HVD_TRIM                   (0x4U)
/* Modify the vddc_lvd low voltage threshold of PMC */
#define VDDC_LVD_TRIM                   (0x0U)

/* Modify the flex_io_hvd high voltage threshold of PMC */
#define FLEX_IO_HVD_TRIM                (0x4U)
/* Modify the flex_io_lvd low voltage threshold of PMC */
#define FLEX_IO_LVD_TRIM                (0xcU)

/* Modify the sdavdd_hvd high voltage threshold of PMC */
#define SDAVDD_HVD_TRIM                 (0x4U)
/* Modify the sdavdd_lvd low voltage threshold of PMC */
#define SDAVDD_LVD_TRIM                 (0xcU)

/* Modify the io_5v_hvd high voltage threshold of PMC */
#define IO_5V_HVD_TRIM                  (0x4U)
/* Modify the io_5v_lvd low voltage threshold of PMC */
#define IO_5V_LVD_TRIM                  (0xcU)

/* Modify the vddc_c_hvd high voltage threshold of PMC */
#define VDDC_C_HVD_TRIM                 (0x4U)
/* Modify the vddc_c_lvd low voltage threshold of PMC */
#define VDDC_C_LVD_TRIM                 (0x0U)


#ifdef __cplusplus
}
#endif

#endif
