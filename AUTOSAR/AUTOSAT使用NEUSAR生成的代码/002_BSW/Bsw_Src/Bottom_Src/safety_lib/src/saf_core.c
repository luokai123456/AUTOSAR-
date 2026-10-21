/**
****************************************************************************************
 * @FilePath: saf_core.c
 * @Author: CCORE
 * @Date: 2024-02-28
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion: CORE Source File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_core.h"/*PRQA S 0380*/
#include "saf_fccu.h"
#include "mcu_lld.h"
#include "rgm_lld.h"
#include "saf_ccfc30xx.h"
#include "saf_userservice_callback.h"
#include "Saf_MemMap.h"

/*PRQA S 0753 EOF*/
/*PRQA S 1843,1881,1843,1258 EOF*/
/*PRQA S 2844,2984 EOF*/
/*PRQA S 3218,3398,3604,3635,3200,3344 EOF*/
/*PRQA S 4115,4116,4304,4404,4558,4559 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/

/**
****************************************************************************************
 * @brief: Global Variable
****************************************************************************************
*/
extern const saf_core_reset_config_t CoreResetCfg;
extern const call_config_t s_coreDestructiveResetCallSet;
extern const call_config_t s_coreFunctionResetCallSet;

/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_CORE_SEC_VAR_INIT
static bool s_resetDetectInitialized = (bool)false;
SAF_CORE_SEC_VAR_NO_INIT
static saf_core_reset_mgr_t s_resetReasonCountInfo;
SAF_CORE_SEC_CONFIG_DATA
static const saf_core_reset_detect_t s_resetDetectObjList[SAF_RESET_COUNT] = SAF_RESET_REASON_DETECT_OBJ_LIST;

SAF_CORE_SEC_VAR_INIT
static MC_ME_Type *s_pMcmeBasePtr[MC_ME_INSTANCE_COUNT] = SAF_MC_ME_BASE_PTRS;
SAF_CORE_SEC_VAR_INIT
static RGM_Type *s_pRgmBasePtr[MC_RGM_INSTANCE_COUNT] = RGM_BASE_PTRS;

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/
static bool SAF_CORE_AccessGetResetFlag(const SAF_RESET_REASON_TYPE type);
static FS_STATUS SAF_CORE_AccessCleanRegResetFlag(void);
static void SAF_CORE_AccessSetDretAndFretReg(void);

/**
****************************************************************************************
 * @brief: Local Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [] This function is used to get reset flag.
* @param[in] rgmInst rgm instance ID
* @param[in] type reset reason type
* @return status:
            true:  access flag successfully
            false: access flag failure
****************************************************************************************
*/
SAF_CORE_SEC_CODE
static bool SAF_CORE_AccessGetResetFlag(const SAF_RESET_REASON_TYPE type)
{
	RGM_Type *pBase = s_pRgmBasePtr[SAF_RGM_INSTANCE];
    bool ret = (bool)false;
    uint32_t rgmMask[RGM_DEST_MASK_COUNT] = RGM_DEST_MASK;

    if (SAF_RESET_DEST_COUNT > (uint8_t)type)
    {
        ret = (SAF_CORE_RESET_DIS_FLAG != (pBase->DES.R & rgmMask[type])) ? (bool)true: (bool)false;
    }
    else
    {
        ret = (SAF_CORE_RESET_DIS_FLAG != (pBase->FES.R & rgmMask[type])) ? (bool)true: (bool)false;/* polyspace RTE:OBAI */
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function is used to clean the register reset flag.
* @param[in] rgmInst rgm instance ID
* @return status:
            FS_STATUS_SUCCESS  clean register successfully
            FS_STATUS_ERROR   clean register failure 
****************************************************************************************
*/
SAF_CORE_SEC_CODE
static FS_STATUS SAF_CORE_AccessCleanRegResetFlag(void)
{
	RGM_Type *pBase = s_pRgmBasePtr[SAF_RGM_INSTANCE];
    uint32_t value = SAF_CORE_RESET_DIS_FLAG;
    FS_STATUS status=FS_STATUS_ERROR;

    value |= RGM_VOR_FUNC_MASK;
    value |= RGM_TSR_FUNC_MASK;
    value |= RGM_HSM_FUNC_MASK;
    value |= RGM_JTAG_FUNC_MASK;
    #if defined(CCFC3008PC) | defined(CCFC3008PCSN)
    value |= RGM_SWT_AO_FUNC_MASK;
    #endif
    value |= RGM_FCCU_SOFT_FUNC_MASK;
    value |= RGM_FCCU_HARD_FUNC_MASK;
    value |= RGM_ST_DONE_FUNC_MASK;
    value |= RGM_ESR0_FUNC_MASK;
    value |= RGM_ESR1_FUNC_MASK;
    pBase->FES.R = value;
    READ_AFTER_WRITE_ASSERT(pBase->FES.R , SAF_CORE_RESET_DIS_FLAG);

    value = SAF_CORE_RESET_DIS_FLAG;
    value |= RGM_VOR_DEST_MASK;
    value |= RGM_TSR_DEST_MASK;
    value |= RGM_HSM_DEST_MASK;
    value |= RGM_SSCM_DEST_MASK;
    value |= RGM_JTAG_DEST_MASK;
    value |= RGM_FIF_DEST_MASK;
    #if defined(CCFC3008PC) | defined(CCFC3008PCSN)
    value |= RGM_SWT_AO_DEST_MASK;
    #endif
    value |= RGM_EDR_DEST_MASK;
    value |= RGM_SUF_DEST_MASK;
    value |= RGM_FFRR_DEST_MASK;
    value |= RGM_SOFT_DEST_MASK;
    value |= RGM_PORST_DEST_MASK;
    value |= RGM_POR_DEST_MASK;
    pBase->DES.R = value;
    READ_AFTER_WRITE_ASSERT(pBase->DES.R , SAF_CORE_RESET_DIS_FLAG);

    if((pBase->DES.R == SAF_CORE_RESET_DIS_FLAG) && (pBase->FES.R == SAF_CORE_RESET_DIS_FLAG))
    {
    	status=FS_STATUS_SUCCESS;
    }
    return status;
}

/**
****************************************************************************************
* @brief: [] This function is used to set the DRET and FRET register value.
* @return void
****************************************************************************************
*/
static void SAF_CORE_AccessSetDretAndFretReg(void)
{
    if(SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_POR) || SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_PORST))
    {
        SAF_CORE_SetRgmDretReg(CoreResetCfg.DesThreshold);
    }

    if(SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_EDR) || SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_POR) || SAF_CORE_CheckerResetFlag(SAF_RESET_DEST_PORST))
    {
        SAF_CORE_SetRgmFretReg(CoreResetCfg.FuncThreshold);
    }
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief: [] This function is used to set the DRET register value
* @param[in] value register set value.
* @return void
****************************************************************************************
*/
SAF_CORE_SEC_CODE
void SAF_CORE_SetRgmDretReg(const uint8_t value)
{
    RGM_LLD_SetDRET((bool)true,value);
}

/**
****************************************************************************************
* @brief: [] This function is used to set the FRET register value.
* @param[in] value register set value.
* @return void
****************************************************************************************
*/
SAF_CORE_SEC_CODE
void SAF_CORE_SetRgmFretReg(const uint8_t value)
{
    RGM_LLD_SetFRET((bool)true,value);
}

/**
****************************************************************************************
* @brief: [] This function is used to set a safe mode request if the destructive reset 
*            is disabled.
* @param[in] name destructive reset type.
* @param[in] mode alternate request type
* @return status:
             FS_STATUS_SUCCESS Set register successfully.
             FS_STATUS_ERROR   Set register failure.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
FS_STATUS SAF_CORE_DesSafeModeRequest(destrutive_reset_name_t name, alternate_request_t mode)
{
    FS_STATUS ret = FS_STATUS_SUCCESS;

    if(STATUS_SUCCESS != RGM_LLD_SetDEAR(name, mode))
    {
        ret = FS_STATUS_ERROR;
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function is used to set a safe mode request if the functional reset 
*            is disabled.
* @param[in] name functional reset type.
* @param[in] mode alternate request type
* @return status:
             FS_STATUS_SUCCESS Set register successfully.
             FS_STATUS_ERROR   Set register failure. 
****************************************************************************************
*/
SAF_CORE_SEC_CODE
FS_STATUS SAF_CORE_FuncSafeModeRequest(functional_reset_name_t name,alternate_request_t mode)
{
    FS_STATUS ret = FS_STATUS_SUCCESS;

    if(STATUS_SUCCESS != RGM_LLD_SetFEAR(name, mode))
    {
        ret = FS_STATUS_ERROR;
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function is used to obtain the value of the MC_RGM_DEAR register.
* @param[in] name: destrutive reset type.
* @return boolean
             true: The value of the register is 1.
             false: The value of the register is 0.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_GetRgmDearReg(destrutive_reset_name_t name)
{
    boolean reg = false;
    RGM_Type *pBase = s_pRgmBasePtr[SAF_RGM_INSTANCE];

    if(name == DEST_PORST)
    {
    	reg = (boolean)(pBase->DEAR.B.AR_PORST);
    }

    return reg;
}

/**
****************************************************************************************
* @brief: [] This function is used to obtain the value of the MC_RGM_FEAR register.
* @param[in] name: functional reset type.
* @return boolean
             true: The value of the register is 1.
             false: The value of the register is 0.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_GetRgmFearReg(functional_reset_name_t name)
{
    boolean reg = false;
    RGM_Type *pBase = s_pRgmBasePtr[SAF_RGM_INSTANCE];

    if(name == Func_VOR)
    {
        reg = (boolean)(pBase->FEAR.B.AR_VOR_FUNC);
    }
    else if(name == Func_TSR)
    {
		reg = (boolean)(pBase->FEAR.B.AR_TSR_FUNC);
    }
    else if(name == Func_ESR1)
    {
		reg = (boolean)(pBase->FEAR.B.AR_ESR1);
    }
    else
    {
        /* do nothing */
    }

    return reg;
}

/**
****************************************************************************************
* @brief: [] This function is used to clean the register reset flag.
* @param[in] void
* @return status:
            FS_STATUS_SUCCESS  clean register successfully.
            FS_STATUS_ERROR   clean register failure.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
FS_STATUS SAF_CORE_CleanRegResetFlag(void)
{
	FS_STATUS sts = FS_STATUS_SUCCESS;

	sts = SAF_CORE_AccessCleanRegResetFlag();

	return sts;
}

/**
****************************************************************************************
* @brief: [] This function is used to get the reset flag.
* @param[in] type reset reason type
* @return status:
             true:  access flag successfully.
             false: access flag failure.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_GetResetFlag(const SAF_RESET_REASON_TYPE type)
{
    bool ret = (bool)true;

    ret = SAF_CORE_AccessGetResetFlag(type);

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function detects if the current core is safety core.
* @param[in] void
* @return status:
                true:  the core is safety core.
                false: the core is not safety core.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_IsSafetyCore(void)
{
    bool ret = (bool)true;

    if(SAF_CORE_ID_Z7_0 != SAF_MCU_LLD_Get_Core_Id())
    {
        ret = (bool)false;
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function detects if the checker core is enabled.
* @param[in] void
* @return status:
                true:  the checker core is enabled.
                false: the checker core is disabled.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_CheckerCoreIsEnabled(void)
{
    bool ret = (bool)false;

    MC_ME_Type *pBase = s_pMcmeBasePtr[SAF_MCME_INSTANCE];

    ret = (bool)(SAF_CORE_CHECKER_CORE_DIS_FLAG != (pBase->CS.R & MC_ME_CS_S_COREC_MASK));

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function is used to check reset flag.
* @param[in] resetType: Reset source.
* @return ret
            true: The current source is reset.
            false: The current source is not reset.
****************************************************************************************
*/
bool SAF_CORE_CheckerResetFlag(const SAF_RESET_REASON_TYPE resetType)
{
    bool ret;

    if(false == s_resetDetectInitialized)
    {
        ret = false;
    }
    else
    {
        ret = s_resetReasonCountInfo.curSysResetStaus[resetType];
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function detects if the current reset is destructive reset.
* @param[in] void
* @return status:
                true:  the current reset is destructive reset.
                false: the current reset is not destructive reset.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_IsDestructiveReset(void)
{
	bool ret;
    uint8 i;

    if(false == s_resetDetectInitialized)
    {
        ret = false;
    }
    else
    {
        for(i = 0; i < SAF_RESET_DEST_COUNT; i++)
        {
            ret = SAF_CORE_CheckerResetFlag(s_resetDetectObjList[i].type);
            if(true == ret)
            {
                break;
            }
        }
    }

    return ret;
}

/**
****************************************************************************************
* @brief: [] This function detects if the current reset is function reset.
* @param[in] void
* @return status:
             true:  the current reset is function reset.
             false: the current reset is not function reset.
****************************************************************************************
*/
SAF_CORE_SEC_CODE
bool SAF_CORE_IsFunctionReset(void)
{
    bool ret= false;
    uint8 i;

    if(false == s_resetDetectInitialized)
    {
        ret = false;
    }
    else
    {
        for(i = SAF_RESET_DEST_COUNT; i < (SAF_RESET_FUNC_COUNT + SAF_RESET_DEST_COUNT); i++)
        {
            ret = SAF_CORE_CheckerResetFlag(s_resetDetectObjList[i].type);
            if(true == ret)
            {
                break;
            }
        }

    }

    return  ret;
}

/**
****************************************************************************************
* @brief: [] This function is used to set SSCM PAERAE bit.
* @param[in] void
* @return void                 
****************************************************************************************
*/
SAF_CORE_SEC_CODE
void SAF_CORE_SSCM_PAERAESet(void)
{
    SSCM.ERROR.R = PAE_ENABLE;
}


/**
****************************************************************************************
* @brief: [] This function detects is used to initialize reset reason detection function.
* @param[in] void
* @return status
            FS_STATUS_SUCCESS: The detection function is initialized successfully. 
            FS_STATUS_ERROR:   Failed to initialize the detection function. 
****************************************************************************************
*/
SAF_CORE_SEC_CODE
FS_STATUS SAF_CORE_ResetDetectInit(void)
{
    saf_core_reset_mgr_t *pResetMgr = &s_resetReasonCountInfo;
    uint8_t i;
    FS_STATUS status = FS_STATUS_ERROR;/*PRQA S 2982*/

    s_resetDetectInitialized = (bool)true;

    for(i = 0; i < SAF_RESET_COUNT; i++)/*PRQA S 1880*/
    {
        pResetMgr->curSysResetStaus[i] = s_resetDetectObjList[i].func(s_resetDetectObjList[i].type) ? (bool)true : (bool)false;
    }

    SAF_CORE_AccessSetDretAndFretReg();
    if(SAF_CORE_IsDestructiveReset())
    {
        if (s_coreDestructiveResetCallSet.callback != NULL)
	    {
   		    s_coreDestructiveResetCallSet.callback(s_coreDestructiveResetCallSet.callbackParam);
		}
    }

    if(SAF_CORE_IsFunctionReset())
    {
        if (s_coreFunctionResetCallSet.callback != NULL)
	    {
   		    s_coreFunctionResetCallSet.callback(s_coreFunctionResetCallSet.callbackParam);
		}
    }

#if  SAF_RGM_SUPPORTED
    status=SAF_CORE_CleanRegResetFlag();
#endif
    return status;
}

#ifdef __cplusplus
}
#endif
