/*
************************************************************************************************************************
*
* File name: Rte_Compiler_Cfg.h
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
#ifndef RTE_COMPILER_CFG_H_
#define RTE_COMPILER_CFG_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_CODE
************************************************************************************************************************
*/

/* used for code */
#define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
#define RTE_VAR_NOINIT

/* used for global or static variables that are initialized with zero by the startup code of the compiler or in Rte_InitMemory */
#define RTE_VAR_ZERO_INIT

/* used for global or static variables that are initialized by the startup code of the compiler or in Rte_InitMemory */
#define RTE_VAR_INIT

/* used for global or static constants */
#define RTE_CONST

/* used for references on application data (variables or constants) */
#define RTE_APPL_DATA

/* used for references on application variables */
#define RTE_APPL_VAR

/* used for references on application functions */
#define RTE_APPL_CODE

/* non cacheable memory variant */
#define RTE_VAR_NOINIT_NOCACHE

/* non cacheable memory variant */
#define RTE_VAR_ZERO_INIT_NOCACHE

/* non cacheable memory variant */
#define RTE_VAR_INIT_NOCACHE

#define RTE_CONST_DEFAULT_RTE_CDATA_GROUP

#define RTE_CONST_DEFAULT_RTE_CALPRM_GROUP

#define RTE_VAR_DEFAULT_RTE_PIM_GROUP

/* used for E2EPW global or static constants */
#define E2EPW_CONST

#define E2EPW_APPL_CONST

/* used for E2EPW global or static variables that are initialized by the 
   startup code of the compiler or in Rte_InitMemory */
#define E2EPW_VAR_INIT

/* used for E2EPW code */
#define E2EPW_CODE

/* used for E2EPW references on application data (variables or constants) */
#define E2EPW_APPL_DATA

/*
************************************************************************************************************************
*    RTE_BSWM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_BSWM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_BSWM_APPL_DATA

/* used for references on application functions */
#define RTE_BSWM_APPL_CODE

/* used for references on application constants */
#define RTE_BSWM_APPL_CONST

/* used for SWC specific code */
#define BswM_CODE

/* used for global or static SWC specific constants */
#define BswM_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define BswM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define BswM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define BswM_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_COMM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_COMM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_COMM_APPL_DATA

/* used for references on application functions */
#define RTE_COMM_APPL_CODE

/* used for references on application constants */
#define RTE_COMM_APPL_CONST

/* used for SWC specific code */
#define ComM_CODE

/* used for global or static SWC specific constants */
#define ComM_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define ComM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define ComM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define ComM_VAR_ZERO_INIT


/*
************************************************************************************************************************
*    RTE_DCM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_DCM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DCM_APPL_DATA

/* used for references on application functions */
#define RTE_DCM_APPL_CODE

/* used for references on application constants */
#define RTE_DCM_APPL_CONST

/* used for SWC specific code */
#define Dcm_CODE

/* used for global or static SWC specific constants */
#define Dcm_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define Dcm_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define Dcm_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define Dcm_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_DEM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_DEM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DEM_APPL_DATA

/* used for references on application functions */
#define RTE_DEM_APPL_CODE

/* used for references on application constants */
#define RTE_DEM_APPL_CONST

/* used for SWC specific code */
#define Dem_CODE

/* used for global or static SWC specific constants */
#define Dem_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define Dem_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define Dem_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define Dem_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_ECUM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_ECUM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_ECUM_APPL_DATA

/* used for references on application functions */
#define RTE_ECUM_APPL_CODE

/* used for references on application constants */
#define RTE_ECUM_APPL_CONST

/* used for SWC specific code */
#define EcuM_CODE

/* used for global or static SWC specific constants */
#define EcuM_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define EcuM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define EcuM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define EcuM_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_FIM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_FIM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_FIM_APPL_DATA

/* used for references on application functions */
#define RTE_FIM_APPL_CODE

/* used for references on application constants */
#define RTE_FIM_APPL_CONST

/* used for SWC specific code */
#define FiM_CODE

/* used for global or static SWC specific constants */
#define FiM_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define FiM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define FiM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define FiM_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_NVM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_NVM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_NVM_APPL_DATA

/* used for references on application functions */
#define RTE_NVM_APPL_CODE

/* used for references on application constants */
#define RTE_NVM_APPL_CONST

/* used for SWC specific code */
#define NvM_CODE

/* used for global or static SWC specific constants */
#define NvM_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define NvM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define NvM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define NvM_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_WDGM_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_WDGM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_WDGM_APPL_DATA

/* used for references on application functions */
#define RTE_WDGM_APPL_CODE

/* used for references on application constants */
#define RTE_WDGM_APPL_CONST

/* used for SWC specific code */
#define WdgM_CODE

/* used for global or static SWC specific constants */
#define WdgM_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define WdgM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define WdgM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define WdgM_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_IoHwAb_APPL
************************************************************************************************************************
*/

/* used for references on application variables */
#define RTE_IoHwAb_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_IoHwAb_APPL_DATA

/* used for references on application functions */
#define RTE_IoHwAb_APPL_CODE

/* used for references on application constants */
#define RTE_IoHwAb_APPL_CONST

/* used for SWC specific code */
#define IoHwAb_CODE

/* used for global or static SWC specific constants */
#define IoHwAb_CONST

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define IoHwAb_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define IoHwAb_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define IoHwAb_VAR_ZERO_INIT

/*
************************************************************************************************************************
*    RTE_SWC_APPL
************************************************************************************************************************
*/
 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ActvDampg_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_ActvDampg_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_ActvDampg_APPL_DATA

/* used for references on application functions */
#define RTE_ActvDampg_APPL_CODE

/* used for references on application constants */
#define RTE_ActvDampg_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvDampg_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define ActvDampg_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvDampg_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define ActvDampg_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ActvDampg_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define ActvDampg_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define ActvDampg_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define ActvDampg_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AngEmDev_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_AngEmDev_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_AngEmDev_APPL_DATA

/* used for references on application functions */
#define RTE_AngEmDev_APPL_CODE

/* used for references on application constants */
#define RTE_AngEmDev_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngEmDev_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define AngEmDev_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngEmDev_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define AngEmDev_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngEmDev_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define AngEmDev_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define AngEmDev_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define AngEmDev_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AngOfstCal_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_AngOfstCal_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_AngOfstCal_APPL_DATA

/* used for references on application functions */
#define RTE_AngOfstCal_APPL_CODE

/* used for references on application constants */
#define RTE_AngOfstCal_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngOfstCal_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define AngOfstCal_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngOfstCal_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define AngOfstCal_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngOfstCal_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define AngOfstCal_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define AngOfstCal_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define AngOfstCal_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AngSwDecod_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_AngSwDecod_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_AngSwDecod_APPL_DATA

/* used for references on application functions */
#define RTE_AngSwDecod_APPL_CODE

/* used for references on application constants */
#define RTE_AngSwDecod_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngSwDecod_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define AngSwDecod_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngSwDecod_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define AngSwDecod_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AngSwDecod_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define AngSwDecod_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define AngSwDecod_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define AngSwDecod_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_AntiRollBack_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_AntiRollBack_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_AntiRollBack_APPL_DATA

/* used for references on application functions */
#define RTE_AntiRollBack_APPL_CODE

/* used for references on application constants */
#define RTE_AntiRollBack_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AntiRollBack_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define AntiRollBack_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AntiRollBack_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define AntiRollBack_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: AntiRollBack_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define AntiRollBack_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define AntiRollBack_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define AntiRollBack_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BIfRx_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_BIfRx_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_BIfRx_APPL_DATA

/* used for references on application functions */
#define RTE_BIfRx_APPL_CODE

/* used for references on application constants */
#define RTE_BIfRx_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BIfRx_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define BIfRx_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BIfRx_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define BIfRx_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BIfRx_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define BIfRx_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define BIfRx_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define BIfRx_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BIfTx_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_BIfTx_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_BIfTx_APPL_DATA

/* used for references on application functions */
#define RTE_BIfTx_APPL_CODE

/* used for references on application constants */
#define RTE_BIfTx_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BIfTx_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define BIfTx_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BIfTx_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define BIfTx_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BIfTx_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define BIfTx_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define BIfTx_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define BIfTx_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BSW_NM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_BSW_NM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_BSW_NM_APPL_DATA

/* used for references on application functions */
#define RTE_BSW_NM_APPL_CODE

/* used for references on application constants */
#define RTE_BSW_NM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BSW_NM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define BSW_NM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BSW_NM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define BSW_NM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BSW_NM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define BSW_NM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define BSW_NM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define BSW_NM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ComRx_CAN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_ComRx_CAN_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_ComRx_CAN_APPL_DATA

/* used for references on application functions */
#define RTE_ComRx_CAN_APPL_CODE

/* used for references on application constants */
#define RTE_ComRx_CAN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComRx_CAN_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define ComRx_CAN_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComRx_CAN_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define ComRx_CAN_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComRx_CAN_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define ComRx_CAN_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define ComRx_CAN_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define ComRx_CAN_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ComTx_CAN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_ComTx_CAN_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_ComTx_CAN_APPL_DATA

/* used for references on application functions */
#define RTE_ComTx_CAN_APPL_CODE

/* used for references on application constants */
#define RTE_ComTx_CAN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComTx_CAN_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define ComTx_CAN_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComTx_CAN_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define ComTx_CAN_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComTx_CAN_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define ComTx_CAN_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define ComTx_CAN_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define ComTx_CAN_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_Dchrg_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_Dchrg_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_Dchrg_APPL_DATA

/* used for references on application functions */
#define RTE_Dchrg_APPL_CODE

/* used for references on application constants */
#define RTE_Dchrg_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dchrg_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define Dchrg_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dchrg_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define Dchrg_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dchrg_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define Dchrg_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define Dchrg_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define Dchrg_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DernCoorn_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_DernCoorn_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DernCoorn_APPL_DATA

/* used for references on application functions */
#define RTE_DernCoorn_APPL_CODE

/* used for references on application constants */
#define RTE_DernCoorn_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernCoorn_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define DernCoorn_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernCoorn_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define DernCoorn_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernCoorn_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define DernCoorn_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define DernCoorn_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define DernCoorn_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DernEm_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_DernEm_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DernEm_APPL_DATA

/* used for references on application functions */
#define RTE_DernEm_APPL_CODE

/* used for references on application constants */
#define RTE_DernEm_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernEm_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define DernEm_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernEm_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define DernEm_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernEm_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define DernEm_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define DernEm_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define DernEm_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DernInv_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_DernInv_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DernInv_APPL_DATA

/* used for references on application functions */
#define RTE_DernInv_APPL_CODE

/* used for references on application constants */
#define RTE_DernInv_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernInv_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define DernInv_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernInv_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define DernInv_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernInv_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define DernInv_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define DernInv_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define DernInv_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DernSys_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_DernSys_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DernSys_APPL_DATA

/* used for references on application functions */
#define RTE_DernSys_APPL_CODE

/* used for references on application constants */
#define RTE_DernSys_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernSys_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define DernSys_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernSys_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define DernSys_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DernSys_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define DernSys_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define DernSys_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define DernSys_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_Diag_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_Diag_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_Diag_APPL_DATA

/* used for references on application functions */
#define RTE_Diag_APPL_CODE

/* used for references on application constants */
#define RTE_Diag_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Diag_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define Diag_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Diag_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define Diag_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Diag_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define Diag_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define Diag_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define Diag_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DynFrq_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_DynFrq_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_DynFrq_APPL_DATA

/* used for references on application functions */
#define RTE_DynFrq_APPL_CODE

/* used for references on application constants */
#define RTE_DynFrq_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DynFrq_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define DynFrq_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DynFrq_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define DynFrq_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DynFrq_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define DynFrq_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define DynFrq_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define DynFrq_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EVPT_XCUInterFace_Map_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_EVPT_XCUInterFace_Map_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_EVPT_XCUInterFace_Map_APPL_DATA

/* used for references on application functions */
#define RTE_EVPT_XCUInterFace_Map_APPL_CODE

/* used for references on application constants */
#define RTE_EVPT_XCUInterFace_Map_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EVPT_XCUInterFace_Map_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define EVPT_XCUInterFace_Map_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EVPT_XCUInterFace_Map_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define EVPT_XCUInterFace_Map_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EVPT_XCUInterFace_Map_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define EVPT_XCUInterFace_Map_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define EVPT_XCUInterFace_Map_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define EVPT_XCUInterFace_Map_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EdrvStMac_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_EdrvStMac_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_EdrvStMac_APPL_DATA

/* used for references on application functions */
#define RTE_EdrvStMac_APPL_CODE

/* used for references on application constants */
#define RTE_EdrvStMac_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EdrvStMac_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define EdrvStMac_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EdrvStMac_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define EdrvStMac_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EdrvStMac_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define EdrvStMac_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define EdrvStMac_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define EdrvStMac_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EmPwr_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_EmPwr_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_EmPwr_APPL_DATA

/* used for references on application functions */
#define RTE_EmPwr_APPL_CODE

/* used for references on application constants */
#define RTE_EmPwr_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EmPwr_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define EmPwr_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EmPwr_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define EmPwr_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EmPwr_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define EmPwr_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define EmPwr_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define EmPwr_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_EmTq_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_EmTq_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_EmTq_APPL_DATA

/* used for references on application functions */
#define RTE_EmTq_APPL_CODE

/* used for references on application constants */
#define RTE_EmTq_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EmTq_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define EmTq_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EmTq_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define EmTq_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EmTq_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define EmTq_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define EmTq_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define EmTq_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ExtTqDes_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_ExtTqDes_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_ExtTqDes_APPL_DATA

/* used for references on application functions */
#define RTE_ExtTqDes_APPL_CODE

/* used for references on application constants */
#define RTE_ExtTqDes_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ExtTqDes_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define ExtTqDes_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ExtTqDes_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define ExtTqDes_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ExtTqDes_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define ExtTqDes_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define ExtTqDes_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define ExtTqDes_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HrmcInj_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_HrmcInj_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_HrmcInj_APPL_DATA

/* used for references on application functions */
#define RTE_HrmcInj_APPL_CODE

/* used for references on application constants */
#define RTE_HrmcInj_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HrmcInj_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define HrmcInj_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HrmcInj_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define HrmcInj_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HrmcInj_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define HrmcInj_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define HrmcInj_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define HrmcInj_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HvIntlck_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_HvIntlck_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_HvIntlck_APPL_DATA

/* used for references on application functions */
#define RTE_HvIntlck_APPL_CODE

/* used for references on application constants */
#define RTE_HvIntlck_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HvIntlck_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define HvIntlck_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HvIntlck_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define HvIntlck_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HvIntlck_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define HvIntlck_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define HvIntlck_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define HvIntlck_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_HvInvDev_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_HvInvDev_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_HvInvDev_APPL_DATA

/* used for references on application functions */
#define RTE_HvInvDev_APPL_CODE

/* used for references on application constants */
#define RTE_HvInvDev_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HvInvDev_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define HvInvDev_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HvInvDev_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define HvInvDev_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: HvInvDev_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define HvInvDev_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define HvInvDev_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define HvInvDev_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IdqAct_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_IdqAct_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_IdqAct_APPL_DATA

/* used for references on application functions */
#define RTE_IdqAct_APPL_CODE

/* used for references on application constants */
#define RTE_IdqAct_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqAct_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define IdqAct_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqAct_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define IdqAct_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqAct_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define IdqAct_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define IdqAct_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define IdqAct_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IdqCtrl_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_IdqCtrl_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_IdqCtrl_APPL_DATA

/* used for references on application functions */
#define RTE_IdqCtrl_APPL_CODE

/* used for references on application constants */
#define RTE_IdqCtrl_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqCtrl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define IdqCtrl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqCtrl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define IdqCtrl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqCtrl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define IdqCtrl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define IdqCtrl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define IdqCtrl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_IdqDes_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_IdqDes_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_IdqDes_APPL_DATA

/* used for references on application functions */
#define RTE_IdqDes_APPL_CODE

/* used for references on application constants */
#define RTE_IdqDes_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqDes_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define IdqDes_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqDes_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define IdqDes_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: IdqDes_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define IdqDes_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define IdqDes_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define IdqDes_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MCU_DID_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_MCU_DID_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_MCU_DID_APPL_DATA

/* used for references on application functions */
#define RTE_MCU_DID_APPL_CODE

/* used for references on application constants */
#define RTE_MCU_DID_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_DID_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define MCU_DID_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_DID_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define MCU_DID_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_DID_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define MCU_DID_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define MCU_DID_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define MCU_DID_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MCU_UDS_Interface_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_MCU_UDS_Interface_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_MCU_UDS_Interface_APPL_DATA

/* used for references on application functions */
#define RTE_MCU_UDS_Interface_APPL_CODE

/* used for references on application constants */
#define RTE_MCU_UDS_Interface_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_UDS_Interface_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define MCU_UDS_Interface_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_UDS_Interface_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define MCU_UDS_Interface_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_UDS_Interface_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define MCU_UDS_Interface_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define MCU_UDS_Interface_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define MCU_UDS_Interface_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MCU_fc_BIfRx_IN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_MCU_fc_BIfRx_IN_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_MCU_fc_BIfRx_IN_APPL_DATA

/* used for references on application functions */
#define RTE_MCU_fc_BIfRx_IN_APPL_CODE

/* used for references on application constants */
#define RTE_MCU_fc_BIfRx_IN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_fc_BIfRx_IN_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define MCU_fc_BIfRx_IN_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_fc_BIfRx_IN_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define MCU_fc_BIfRx_IN_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_fc_BIfRx_IN_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define MCU_fc_BIfRx_IN_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define MCU_fc_BIfRx_IN_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define MCU_fc_BIfRx_IN_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_MCU_fc_BIfRx_OUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_MCU_fc_BIfRx_OUT_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_MCU_fc_BIfRx_OUT_APPL_DATA

/* used for references on application functions */
#define RTE_MCU_fc_BIfRx_OUT_APPL_CODE

/* used for references on application constants */
#define RTE_MCU_fc_BIfRx_OUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_fc_BIfRx_OUT_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define MCU_fc_BIfRx_OUT_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_fc_BIfRx_OUT_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define MCU_fc_BIfRx_OUT_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: MCU_fc_BIfRx_OUT_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define MCU_fc_BIfRx_OUT_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define MCU_fc_BIfRx_OUT_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define MCU_fc_BIfRx_OUT_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_BswAswRte_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_BswAswRte_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_BswAswRte_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_BswAswRte_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_BswAswRte_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_BswAswRte_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_BswAswRte_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_BswAswRte_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_BswAswRte_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_BswAswRte_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_BswAswRte_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_BswAswRte_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_BswAswRte_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_DID_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_DID_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_DID_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_DID_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_DID_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_DID_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_DID_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_DID_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_DID_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_DID_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_DID_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_DID_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_DID_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_HWI_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_HWI_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_HWI_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_HWI_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_HWI_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWI_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_HWI_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWI_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_HWI_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWI_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_HWI_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_HWI_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_HWI_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_HWI_Serve_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_HWI_Serve_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_HWI_Serve_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_HWI_Serve_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_HWI_Serve_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWI_Serve_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_HWI_Serve_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWI_Serve_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_HWI_Serve_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWI_Serve_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_HWI_Serve_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_HWI_Serve_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_HWI_Serve_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_HWO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_HWO_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_HWO_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_HWO_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_HWO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWO_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_HWO_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWO_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_HWO_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWO_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_HWO_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_HWO_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_HWO_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_HWO_Serve_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_HWO_Serve_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_HWO_Serve_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_HWO_Serve_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_HWO_Serve_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWO_Serve_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_HWO_Serve_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWO_Serve_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_HWO_Serve_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_HWO_Serve_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_HWO_Serve_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_HWO_Serve_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_HWO_Serve_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PMS_RollingCounter_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PMS_RollingCounter_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PMS_RollingCounter_APPL_DATA

/* used for references on application functions */
#define RTE_PMS_RollingCounter_APPL_CODE

/* used for references on application constants */
#define RTE_PMS_RollingCounter_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_RollingCounter_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PMS_RollingCounter_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_RollingCounter_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PMS_RollingCounter_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PMS_RollingCounter_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PMS_RollingCounter_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PMS_RollingCounter_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PMS_RollingCounter_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_PhaCurrDev_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_PhaCurrDev_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_PhaCurrDev_APPL_DATA

/* used for references on application functions */
#define RTE_PhaCurrDev_APPL_CODE

/* used for references on application constants */
#define RTE_PhaCurrDev_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaCurrDev_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define PhaCurrDev_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaCurrDev_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define PhaCurrDev_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: PhaCurrDev_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define PhaCurrDev_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define PhaCurrDev_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define PhaCurrDev_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TempDev_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_TempDev_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_TempDev_APPL_DATA

/* used for references on application functions */
#define RTE_TempDev_APPL_CODE

/* used for references on application constants */
#define RTE_TempDev_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TempDev_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define TempDev_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TempDev_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define TempDev_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TempDev_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define TempDev_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define TempDev_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define TempDev_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_TqDemCoorn_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_TqDemCoorn_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_TqDemCoorn_APPL_DATA

/* used for references on application functions */
#define RTE_TqDemCoorn_APPL_CODE

/* used for references on application constants */
#define RTE_TqDemCoorn_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TqDemCoorn_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define TqDemCoorn_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TqDemCoorn_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define TqDemCoorn_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: TqDemCoorn_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define TqDemCoorn_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define TqDemCoorn_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define TqDemCoorn_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VoltModlnGen_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_VoltModlnGen_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_VoltModlnGen_APPL_DATA

/* used for references on application functions */
#define RTE_VoltModlnGen_APPL_CODE

/* used for references on application constants */
#define RTE_VoltModlnGen_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VoltModlnGen_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define VoltModlnGen_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VoltModlnGen_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define VoltModlnGen_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VoltModlnGen_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define VoltModlnGen_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define VoltModlnGen_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define VoltModlnGen_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VoltModlnlnp_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_VoltModlnlnp_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_VoltModlnlnp_APPL_DATA

/* used for references on application functions */
#define RTE_VoltModlnlnp_APPL_CODE

/* used for references on application constants */
#define RTE_VoltModlnlnp_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VoltModlnlnp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define VoltModlnlnp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VoltModlnlnp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define VoltModlnlnp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: VoltModlnlnp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define VoltModlnlnp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define VoltModlnlnp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define VoltModlnlnp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_ATAU_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_ATAU_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_ATAU_APPL_DATA

/* used for references on application functions */
#define RTE_swc_ATAU_APPL_CODE

/* used for references on application constants */
#define RTE_swc_ATAU_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_ATAU_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_ATAU_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_ATAU_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_ATAU_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_ATAU_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_ATAU_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_ATAU_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_ATAU_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_AUXC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_AUXC_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_AUXC_APPL_DATA

/* used for references on application functions */
#define RTE_swc_AUXC_APPL_CODE

/* used for references on application constants */
#define RTE_swc_AUXC_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_AUXC_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_AUXC_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_AUXC_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_AUXC_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_AUXC_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_AUXC_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_AUXC_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_AUXC_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatBalnCtl_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatBalnCtl_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatBalnCtl_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatBalnCtl_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatBalnCtl_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatBalnCtl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatBalnCtl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatBalnCtl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatBalnCtl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatBalnCtl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatBalnCtl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatBalnCtl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatBalnCtl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatChCtl_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatChCtl_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatChCtl_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatChCtl_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatChCtl_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatChCtl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatChCtl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatChCtl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatChCtl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatChCtl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatChCtl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatChCtl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatChCtl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatCoreFct_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatCoreFct_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatCoreFct_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatCoreFct_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatCoreFct_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatCoreFct_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatCoreFct_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatCoreFct_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatCoreFct_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatCoreFct_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatCoreFct_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatCoreFct_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatCoreFct_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatProtnIU_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatProtnIU_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatProtnIU_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatProtnIU_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatProtnIU_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatProtnIU_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatProtnIU_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatProtnIU_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatProtnIU_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatProtnIU_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatProtnIU_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatProtnIU_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatProtnIU_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatProtnPack_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatProtnPack_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatProtnPack_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatProtnPack_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatProtnPack_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatProtnPack_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatProtnPack_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatProtnPack_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatProtnPack_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatProtnPack_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatProtnPack_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatProtnPack_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatProtnPack_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatThermHndlgMngt_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatThermHndlgMngt_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatThermHndlgMngt_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatThermHndlgMngt_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatThermHndlgMngt_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatThermHndlgMngt_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatThermHndlgMngt_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatThermHndlgMngt_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatThermHndlgMngt_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatThermHndlgMngt_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatThermHndlgMngt_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatThermHndlgMngt_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatThermHndlgMngt_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BatWntyLogtcData_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BatWntyLogtcData_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BatWntyLogtcData_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BatWntyLogtcData_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BatWntyLogtcData_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatWntyLogtcData_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BatWntyLogtcData_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatWntyLogtcData_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BatWntyLogtcData_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BatWntyLogtcData_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BatWntyLogtcData_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BatWntyLogtcData_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BatWntyLogtcData_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_BcuStTranCtl_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_BcuStTranCtl_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_BcuStTranCtl_APPL_DATA

/* used for references on application functions */
#define RTE_swc_BcuStTranCtl_APPL_CODE

/* used for references on application constants */
#define RTE_swc_BcuStTranCtl_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BcuStTranCtl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_BcuStTranCtl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BcuStTranCtl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_BcuStTranCtl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_BcuStTranCtl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_BcuStTranCtl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_BcuStTranCtl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_BcuStTranCtl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_CIL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_CIL_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_CIL_APPL_DATA

/* used for references on application functions */
#define RTE_swc_CIL_APPL_CODE

/* used for references on application constants */
#define RTE_swc_CIL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_CIL_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_CIL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_CIL_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_CIL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_CIL_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_CIL_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_CIL_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_CIL_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_COL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_COL_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_COL_APPL_DATA

/* used for references on application functions */
#define RTE_swc_COL_APPL_CODE

/* used for references on application constants */
#define RTE_swc_COL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_COL_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_COL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_COL_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_COL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_COL_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_COL_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_COL_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_COL_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_CtctrTranCtl_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_CtctrTranCtl_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_CtctrTranCtl_APPL_DATA

/* used for references on application functions */
#define RTE_swc_CtctrTranCtl_APPL_CODE

/* used for references on application constants */
#define RTE_swc_CtctrTranCtl_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_CtctrTranCtl_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_CtctrTranCtl_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_CtctrTranCtl_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_CtctrTranCtl_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_CtctrTranCtl_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_CtctrTranCtl_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_CtctrTranCtl_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_CtctrTranCtl_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_DIAG_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_DIAG_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_DIAG_APPL_DATA

/* used for references on application functions */
#define RTE_swc_DIAG_APPL_CODE

/* used for references on application constants */
#define RTE_swc_DIAG_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_DIAG_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_DIAG_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_DIAG_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_DIAG_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_DIAG_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_DIAG_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_DIAG_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_DIAG_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_DiagcEveHndlg_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_DiagcEveHndlg_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_DiagcEveHndlg_APPL_DATA

/* used for references on application functions */
#define RTE_swc_DiagcEveHndlg_APPL_CODE

/* used for references on application constants */
#define RTE_swc_DiagcEveHndlg_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_DiagcEveHndlg_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_DiagcEveHndlg_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_DiagcEveHndlg_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_DiagcEveHndlg_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_DiagcEveHndlg_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_DiagcEveHndlg_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_DiagcEveHndlg_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_DiagcEveHndlg_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_EGYM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_EGYM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_EGYM_APPL_DATA

/* used for references on application functions */
#define RTE_swc_EGYM_APPL_CODE

/* used for references on application constants */
#define RTE_swc_EGYM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_EGYM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_EGYM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_EGYM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_EGYM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_EGYM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_EGYM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_EGYM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_EGYM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_EltlLnkHzrdProtnNet_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_EltlLnkHzrdProtnNet_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_EltlLnkHzrdProtnNet_APPL_DATA

/* used for references on application functions */
#define RTE_swc_EltlLnkHzrdProtnNet_APPL_CODE

/* used for references on application constants */
#define RTE_swc_EltlLnkHzrdProtnNet_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_EltlLnkHzrdProtnNet_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_EltlLnkHzrdProtnNet_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_EltlLnkHzrdProtnNet_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_EltlLnkHzrdProtnNet_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_EltlLnkHzrdProtnNet_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_EltlLnkHzrdProtnNet_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_EltlLnkHzrdProtnNet_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_EltlLnkHzrdProtnNet_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_GetInputInterface_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_GetInputInterface_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_GetInputInterface_APPL_DATA

/* used for references on application functions */
#define RTE_swc_GetInputInterface_APPL_CODE

/* used for references on application constants */
#define RTE_swc_GetInputInterface_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_GetInputInterface_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_GetInputInterface_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_GetInputInterface_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_GetInputInterface_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_GetInputInterface_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_GetInputInterface_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_GetInputInterface_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_GetInputInterface_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_HMIF_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_HMIF_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_HMIF_APPL_DATA

/* used for references on application functions */
#define RTE_swc_HMIF_APPL_CODE

/* used for references on application constants */
#define RTE_swc_HMIF_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_HMIF_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_HMIF_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_HMIF_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_HMIF_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_HMIF_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_HMIF_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_HMIF_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_HMIF_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_HVSM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_HVSM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_HVSM_APPL_DATA

/* used for references on application functions */
#define RTE_swc_HVSM_APPL_CODE

/* used for references on application constants */
#define RTE_swc_HVSM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_HVSM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_HVSM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_HVSM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_HVSM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_HVSM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_HVSM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_HVSM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_HVSM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_MEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_MEST_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_MEST_APPL_DATA

/* used for references on application functions */
#define RTE_swc_MEST_APPL_CODE

/* used for references on application constants */
#define RTE_swc_MEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_MEST_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_MEST_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_MEST_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_MEST_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_MEST_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_MEST_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_MEST_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_MEST_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_OGVL_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_OGVL_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_OGVL_APPL_DATA

/* used for references on application functions */
#define RTE_swc_OGVL_APPL_CODE

/* used for references on application constants */
#define RTE_swc_OGVL_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_OGVL_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_OGVL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_OGVL_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_OGVL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_OGVL_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_OGVL_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_OGVL_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_OGVL_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_RMLK_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_RMLK_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_RMLK_APPL_DATA

/* used for references on application functions */
#define RTE_swc_RMLK_APPL_CODE

/* used for references on application constants */
#define RTE_swc_RMLK_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_RMLK_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_RMLK_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_RMLK_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_RMLK_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_RMLK_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_RMLK_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_RMLK_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_RMLK_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_SCAP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_SCAP_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_SCAP_APPL_DATA

/* used for references on application functions */
#define RTE_swc_SCAP_APPL_CODE

/* used for references on application constants */
#define RTE_swc_SCAP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SCAP_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_SCAP_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SCAP_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_SCAP_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SCAP_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_SCAP_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_SCAP_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_SCAP_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_SCOO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_SCOO_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_SCOO_APPL_DATA

/* used for references on application functions */
#define RTE_swc_SCOO_APPL_CODE

/* used for references on application constants */
#define RTE_swc_SCOO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SCOO_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_SCOO_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SCOO_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_SCOO_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SCOO_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_SCOO_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_SCOO_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_SCOO_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_SetInputInterface_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_SetInputInterface_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_SetInputInterface_APPL_DATA

/* used for references on application functions */
#define RTE_swc_SetInputInterface_APPL_CODE

/* used for references on application constants */
#define RTE_swc_SetInputInterface_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetInputInterface_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_SetInputInterface_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetInputInterface_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_SetInputInterface_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetInputInterface_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_SetInputInterface_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_SetInputInterface_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_SetInputInterface_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_SetOutputInterface_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_SetOutputInterface_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_SetOutputInterface_APPL_DATA

/* used for references on application functions */
#define RTE_swc_SetOutputInterface_APPL_CODE

/* used for references on application constants */
#define RTE_swc_SetOutputInterface_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetOutputInterface_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_SetOutputInterface_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetOutputInterface_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_SetOutputInterface_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetOutputInterface_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_SetOutputInterface_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_SetOutputInterface_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_SetOutputInterface_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_SetSendCANMsg_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_SetSendCANMsg_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_SetSendCANMsg_APPL_DATA

/* used for references on application functions */
#define RTE_swc_SetSendCANMsg_APPL_CODE

/* used for references on application constants */
#define RTE_swc_SetSendCANMsg_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetSendCANMsg_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_SetSendCANMsg_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetSendCANMsg_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_SetSendCANMsg_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_SetSendCANMsg_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_SetSendCANMsg_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_SetSendCANMsg_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_SetSendCANMsg_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_TCOO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_TCOO_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_TCOO_APPL_DATA

/* used for references on application functions */
#define RTE_swc_TCOO_APPL_CODE

/* used for references on application constants */
#define RTE_swc_TCOO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_TCOO_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_TCOO_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_TCOO_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_TCOO_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_TCOO_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_TCOO_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_TCOO_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_TCOO_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_THSM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_THSM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_THSM_APPL_DATA

/* used for references on application functions */
#define RTE_swc_THSM_APPL_CODE

/* used for references on application constants */
#define RTE_swc_THSM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_THSM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_THSM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_THSM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_THSM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_THSM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_THSM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_THSM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_THSM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_VCIP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_VCIP_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_VCIP_APPL_DATA

/* used for references on application functions */
#define RTE_swc_VCIP_APPL_CODE

/* used for references on application constants */
#define RTE_swc_VCIP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VCIP_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_VCIP_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VCIP_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_VCIP_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VCIP_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_VCIP_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_VCIP_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_VCIP_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_VCOP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_VCOP_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_VCOP_APPL_DATA

/* used for references on application functions */
#define RTE_swc_VCOP_APPL_CODE

/* used for references on application constants */
#define RTE_swc_VCOP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VCOP_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_VCOP_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VCOP_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_VCOP_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VCOP_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_VCOP_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_VCOP_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_VCOP_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_swc_VOMM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
#define RTE_swc_VOMM_APPL_VAR

/* used for references on application data (constants or variables) */
#define RTE_swc_VOMM_APPL_DATA

/* used for references on application functions */
#define RTE_swc_VOMM_APPL_CODE

/* used for references on application constants */
#define RTE_swc_VOMM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VOMM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
#define swc_VOMM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VOMM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
#define swc_VOMM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: swc_VOMM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
#define swc_VOMM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
#define swc_VOMM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
#define swc_VOMM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#endif /* RTE_COMPILER_CFG_H_ */

