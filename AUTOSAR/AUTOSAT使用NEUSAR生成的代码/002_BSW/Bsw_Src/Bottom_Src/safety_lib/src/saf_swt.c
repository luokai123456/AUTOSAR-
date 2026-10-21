/**
****************************************************************************************
 * @FilePath: saf_swt.c
 * @Author: CCORE
 * @Date: 2024-03-01
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety swt C File
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

#include "intc_lld.h"/*PRQA S 0380*/
#include "saf_swt.h"
#include "SafetyPeriphTst_Cfg.h"
#include "Saf_MemMap.h"
/*PRQA S 0315,0686,0704,1258,1259,1881,2052,2880,2844,3119,3200,3218,3344,3432,4304,4322,4342,4404,4559 EOF*/
/**
****************************************************************************************
 * @brief: Local Variables
****************************************************************************************
*/
SAF_SWT_SEC_VAR_INIT
static uint32_t s_swtFixServiceDataList[2] = SAF_SWT_FIXED_SERVICE_DATA_LIST;
SAF_SWT_SEC_VAR_INIT
static SWT_tag_Type * s_swtBase[SAF_SWT_INSTANCE_COUNT] = SWT_BASE_ARRAY;
SAF_SWT_SEC_VAR_INIT
static saf_swt_path_test_result_t s_swtPathCheckTest =
{
    .PathTestCheckPassed = {false},
};
SAF_SWT_SEC_VAR_INIT
static SWT_ModeConfig_Type s_swtFastModeConfig =
{
    .SWT_MAPConfig=    (uint8)                   0xFF,
    .SWT_ServiceMode=  (SWT_ServiceMode_Type)    Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)     SWT_SystemReset,
    .SWT_WindowMode=   (SWT_Status_Type)         SWT_Disable,
    .SWT_InterruptMode=(SWT_InterMode)           SWT_RESET_SECOND,
    .SWT_StopMode=     (SWT_StopMode_Type)       SWT_CONTINUE,
    .SWT_DebugMode=    (SWT_DebugMode_Type)      SWT_FreezeOFF,
    .SWT_Lock_Mode=    (SWT_Lock_Type)           SWT_Softlock,
    .SWT_InitialSK=    (uint16)                  0,
    .SWT_Timeout=      (uint32)                  0x00000100,
    .SWT_WindowValue=  (uint32)                  0x00000000,
    .Wdg_InternalClock=(uint32)                  16000,
    .Wdg_TriggerAddr=  (uint32)                  0U
};
SAF_SWT_SEC_VAR_INIT
static SWT_ModeConfig_Type s_swtFastModeConfig_7=
{
    .SWT_MAPConfig=    (uint8)                   0xFF,
    .SWT_ServiceMode=  (SWT_ServiceMode_Type)    Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)     SWT_SystemReset,
    .SWT_WindowMode=   (SWT_Status_Type)         SWT_Disable,
    .SWT_InterruptMode=(SWT_InterMode)           SWT_RESET_SECOND,
    .SWT_StopMode=     (SWT_StopMode_Type)       SWT_CONTINUE,
    .SWT_DebugMode=    (SWT_DebugMode_Type)      SWT_FreezeOFF,
    .SWT_Lock_Mode=    (SWT_Lock_Type)           SWT_Softlock,
    .SWT_InitialSK=    (uint16)                  0u,
    .SWT_Timeout=      (uint32)                  0x00000100u,
    .SWT_WindowValue=  (uint32)                  0x00000000u,
    .Wdg_InternalClock=(uint32)                  32u,
	.Wdg_TriggerAddr = (uint32)                  0u
};

SAF_SWT_SEC_VAR_INIT
static SWT_Module_Config_Type WdgConfigSetType[SAF_SWT_INSTANCE_COUNT] =
{
    {
        .SWT_ModuleID = SWT0,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT1,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT2,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT3,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT4,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT5,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT6,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig},
        .SWT_Callback = NULL_PTR
    },
    {
        .SWT_ModuleID = SWT7_AO,
        .SWT_DefaultRunMode = WDGIF_FAST_MODE,
        .SWT_Config = { NULL_PTR, NULL_PTR, &s_swtFastModeConfig_7},
        .SWT_Callback = NULL_PTR
    }
};
SAF_SWT_SEC_VAR_INIT
static saf_swt_config_type SwtConfigSet =
{
    &WdgConfigSetType
};

/**
****************************************************************************************
 * @brief: Local Function Prototypes
****************************************************************************************
*/
static void SAF_SWT_AccessFixedServiceWdg(SWT_ModuleID_Type SWT_ModuleID);
static FS_STATUS SAF_SWT_AccessUnLock(SWT_ModuleID_Type SWT_ModuleID);
static FS_STATUS SAF_SWT_AccessSetInitialServiceKey(SWT_ModuleID_Type SWT_ModuleID, uint16_t intitialvalue);
static FS_STATUS SAF_SWT_AccessSetTimeoutValue(SWT_ModuleID_Type SWT_ModuleID, uint32_t value);
static FS_STATUS SAF_SWT_AccessSetWindowMode(SWT_ModuleID_Type SWT_ModuleID, SWT_Status_Type windowmode, uint32_t value);
static FS_STATUS SAF_SWT_AccessSetResetOnInvalid(SWT_ModuleID_Type SWT_ModuleID, SWT_RIA_Type mode);
static FS_STATUS SAF_SWT_AccessSetServiceMode(SWT_ModuleID_Type SWT_ModuleID, SWT_ServiceMode_Type mode);
static FS_STATUS SAF_SWT_AccessSetInterruptState(SWT_ModuleID_Type SWT_ModuleID, SWT_InterMode InterruptState);
static FS_STATUS SAF_SWT_AccessSetDebugFreeze(SWT_ModuleID_Type SWT_ModuleID, SWT_DebugMode_Type SWT_DebugMod);
static FS_STATUS SAF_SWT_AccessClearInterruptFlag(SWT_ModuleID_Type SWT_ModuleID);
static FS_STATUS SAF_SWT_AccessModuleDisable(SWT_ModuleID_Type SWT_ModuleID);
static void SAF_SWT_AccessDeInit (SWT_ModuleID_Type SWT_ModuleID);
static FS_STATUS SAF_SWT_AccessGetFreq( const uint8_t swtInst, uint32_t *pFreq);
static FS_STATUS SAF_SWT_AccessSetSwtLock(SWT_ModuleID_Type SWT_ModuleID, SWT_Lock_Type locktype);


/*******************************************************************************
 * Local Functions
 ******************************************************************************/

/**
****************************************************************************************
* @brief[SW_82] This function is used to fix the service watchdog.
* @param[in] SWT_ModuleID: Swt peripheral instance number.
* @return void.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static void SAF_SWT_AccessFixedServiceWdg(SWT_ModuleID_Type SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];

    base->SR.R = s_swtFixServiceDataList[0];
    base->SR.R = s_swtFixServiceDataList[1];
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to unlock swt register.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: UnLock success.
            FS_STATUS_ERROR: UnLock failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessUnLock(SWT_ModuleID_Type SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Write unlock sequence*/
    base->SR.R = SWT_UNLOCK_KEY_1;
    base->SR.R = SWT_UNLOCK_KEY_2;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->CR.B.SLK, SAF_SWT_REG_DISABLE, CMPVALUE_UNSIGNED_INT_MASK);/* polyspace RTE:NIV */

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set initial key when random sequence
                 feed dog.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] intitialvalue: Intitial key.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set initial key success.
            FS_STATUS_ERROR: Set initial key failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetInitialServiceKey(SWT_ModuleID_Type SWT_ModuleID, uint16_t intitialvalue)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set initial key*/
    base->SK.R = intitialvalue;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->SK.R, intitialvalue, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set module timeout value.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] value: Timeout value.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set module timeout value success.
            FS_STATUS_ERROR: Set module timeout value failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetTimeoutValue(SWT_ModuleID_Type SWT_ModuleID, uint32_t value)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set module timeout value*/
    base->TO.R = value;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->TO.R, value, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set module window mode and
                 window value.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] windowmode: Swt window mode.
 * @param[in] value: Window value.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set window mode success.
            FS_STATUS_ERROR: Set window mode failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetWindowMode(SWT_ModuleID_Type SWT_ModuleID, SWT_Status_Type windowmode, uint32_t value)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set window mode*/
    base->CR.B.WND = (uint8_t)windowmode;
    /*Set window value*/
    base->WN.R = value;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->WN.R, value, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set module reset or bus error on
                 invalid access.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] mode: Reset or bus error.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set module reset or bus error success.
            FS_STATUS_ERROR: Set module reset or bus error failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetResetOnInvalid(SWT_ModuleID_Type SWT_ModuleID, SWT_RIA_Type mode)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set module reset or bus error on invalid access*/
    base->CR.B.RIA = (uint8_t)mode;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->CR.B.RIA, (uint32_t)mode, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set module service mode.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] mode: Service mode.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set service key success.
            FS_STATUS_ERROR: Set service key failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetServiceMode(SWT_ModuleID_Type SWT_ModuleID, SWT_ServiceMode_Type mode)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set service key*/
    base->CR.B.SMD = (uint8_t)mode;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->CR.B.SMD, (uint32_t)mode, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set swt interrupt then reset or
                 reset immediately when timeout.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] InterruptState: Interrupt state.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set swt interrupt state success.
            FS_STATUS_ERROR: Set swt interrupt state failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetInterruptState(SWT_ModuleID_Type SWT_ModuleID, SWT_InterMode InterruptState)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set SWT interrupt state*/
    base->CR.B.ITR = (uint8_t)InterruptState;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->CR.B.ITR, (uint32_t)InterruptState, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to set module freeze mode.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @param[in] SWT_DebugMod: Freeze mode.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Set freeze mode success.
            FS_STATUS_ERROR: Set freeze mode failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetDebugFreeze(SWT_ModuleID_Type SWT_ModuleID, SWT_DebugMode_Type SWT_DebugMod)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Set freeze mode*/
    base->CR.B.FRZ = (uint8_t)SWT_DebugMod;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->CR.B.FRZ, (uint32_t)SWT_DebugMod, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to clear swt interrupt flag.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Clear swt interrupt flag success.
            FS_STATUS_ERROR: Clear swt interrupt flag failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessClearInterruptFlag(SWT_ModuleID_Type SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Clear SWT interrupt flag*/
    base->IR.R = SAF_SWT_CLEAR_IR_MASK;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->IR.R, SAF_SWT_IR_MASK, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
 * @brief[SW_82] This function is used to disable swt module.
 * @param[in] SWT_ModuleID: Swt peripheral instance number.
 * @return FS_STATUS
            FS_STATUS_SUCCESS: Disable swt module success.
            FS_STATUS_ERROR: Disable swt module failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessModuleDisable(SWT_ModuleID_Type SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_tag_Type * base = s_swtBase[(uint8_t)SWT_ModuleID];
    /*Disable SWT module */
    base->CR.B.WEN = SAF_SWT_REG_DISABLE;
    /*Check whether the operation is successful*/
    status = SAF_ReadBackCompare(base->CR.B.WEN, SAF_SWT_REG_DISABLE, CMPVALUE_UNSIGNED_INT_MASK);

    return status;
}

/**
****************************************************************************************
* @brief[SW_82] This function is used to de-initialize swt module.
* @param[in] SWT_ModuleID: Swt peripheral instance number.
* @return void.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static void SAF_SWT_AccessDeInit (SWT_ModuleID_Type SWT_ModuleID)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);
    /*Disable module clock*/
    (void)SAF_SWT_AccessModuleDisable(SWT_ModuleID);
    /*Clear interrupt flag*/
    (void)SAF_SWT_AccessClearInterruptFlag(SWT_ModuleID);
    /*Disable freeze mode*/
    (void)SAF_SWT_AccessSetDebugFreeze(SWT_ModuleID, SWT_FreezeOFF);
    /*Set reset immediately when timeout*/
    (void)SAF_SWT_AccessSetInterruptState(SWT_ModuleID, SWT_RESET_FIRST);
    /*Set service mode*/
    (void)SAF_SWT_AccessSetServiceMode(SWT_ModuleID, Fixed_Serv_Seq);
    /*Set bus error on invalid access*/
    (void)SAF_SWT_AccessSetResetOnInvalid(SWT_ModuleID, SWT_BusError);
    /*Disable window mode and clear window value*/
    (void)SAF_SWT_AccessSetWindowMode(SWT_ModuleID, SWT_Disable, 0u);
    /*Clear timeout value*/
    (void)SAF_SWT_AccessSetTimeoutValue(SWT_ModuleID, 0u);
    /*Clear initial key value*/
    (void)SAF_SWT_AccessSetInitialServiceKey(SWT_ModuleID, 0u);
}

/**
****************************************************************************************
* @brief[SW_82] This function is used to get the swt clock frequency.
* @param[in] swtInst: Swt instance.
* @param[in] pFreq: Clock frequency.
* @return status
            FS_STATUS_SUCCESS: Get clock frequency success.
            FS_STATUS_ERROR: Get clock frequency failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessGetFreq( const uint8_t swtInst, uint32_t *pFreq)
{
    FS_STATUS status = FS_STATUS_SUCCESS;
    saf_clock_names_t swtClk;

    if (SAF_SWT_INSTANCE_COUNT <= swtInst)
    {
        status = FS_STATUS_ERROR;
    }
    else if (SWT7_AO == swtInst)
    {
    	*pFreq = SAF_FEATURE_SIRCOSC0_FREQ / SAF_SIRC_DEFAULT_DIV;
    }
    else
    {
        swtClk = SAF_IRCOSC_CLK;

        if(FS_STATUS_SUCCESS != (FS_STATUS)SAF_CLOCK_GetModuleClockFreq(swtClk, pFreq))/*PRQA S 4322*/
        {
            status = FS_STATUS_ERROR;
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_044] This function is used to Lock swt registers.
* @param[in] SWT_ModuleID: Swt peripheral instance number.
* @param[in] locktype: Lock type.
* @return status
            FS_STATUS_SUCCESS: Config lock success.
            FS_STATUS_ERROR: Config lock failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
static FS_STATUS SAF_SWT_AccessSetSwtLock(SWT_ModuleID_Type SWT_ModuleID, SWT_Lock_Type locktype)
{
    /*Check Module ID*/
    DEV_ASSERT((uint8_t)SWT_ModuleID < (uint8_t)SWT_INSTANCE_NUM);

    FS_STATUS status = FS_STATUS_ERROR;

    SWT_tag_Type * base = s_swtBase[SWT_ModuleID];
    /* Unlocks SWT instance */
    (void)SAF_SWT_AccessUnLock(SWT_ModuleID);

    if (SWT_Hardlock == locktype)
    {
        /*Hardware lock*/
        base->CR.B.HLK = SAF_SWT_REG_ENABLE;
        /*Check whether the operation is successful*/
        status = SAF_ReadBackCompare(base->CR.B.HLK, SAF_SWT_REG_ENABLE, CMPVALUE_UNSIGNED_INT_MASK);
    }

    return status;
}

/**
****************************************************************************************
 * @brief: Global Functions
****************************************************************************************
*/
/**
****************************************************************************************
* @brief[SW_044] This function is used to check the swt module is available or not.
* @param[in] swtInst: Swt instance.
* @return ret
            true: SWT available.
            false: SWT unavailable.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
bool SAF_SWT_IsInstanceAvailable(SWT_ModuleID_Type swtInst)
{
    DEV_ASSERT(swtInst < SWT_INSTANCE_NUM);

    bool ret = false;

	#define CASE_CHECK_RESOURCE(x) \
		case x: \
			ret = true; \
			break;

    switch(swtInst)
    {
        #ifdef RESOURCE_SUPPORT_SWT0
        CASE_CHECK_RESOURCE(SWT0);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT1
        CASE_CHECK_RESOURCE(SWT1);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT2
        CASE_CHECK_RESOURCE(SWT2);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT3
        CASE_CHECK_RESOURCE(SWT3);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT4
        CASE_CHECK_RESOURCE(SWT4);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT5
        CASE_CHECK_RESOURCE(SWT5);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT6
        CASE_CHECK_RESOURCE(SWT6);
        #endif

        #ifdef RESOURCE_SUPPORT_SWT7_AO
        CASE_CHECK_RESOURCE(SWT7_AO);
        #endif

        default:
            ret = false;
            break;
    }

    #undef CASE_CHECK_RESOURCE

    return ret;
}



/**
****************************************************************************************
* @brief[SW_046] This function is used to detect if the swt is enabled.
* @param[in] swtInst: Swt instance.
* @return ret
            true: Swt enabled.
            false: Swt disable.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
bool SAF_SWT_SwtIsEnabled(const uint8_t swtInst)
{
    DEV_ASSERT(swtInst < SWT_INSTANCE_NUM);
    bool ret = true;
    if(false == SAF_SWT_IsInstanceAvailable((SWT_ModuleID_Type)swtInst))
    {
    	ret = false;
    }
    else
    {
        ret = (bool)(s_swtBase[swtInst]->CR.B.WEN) ? true : false;/* polyspace RTE:NIV */
    }
    return ret;
}

/**
****************************************************************************************
* @brief[SW_044] This function is used to check the swt module hard lock..
* @param[in] swtInst: Swt instance.
* @return ret
            true: Hardlock enabled.
            false: Hardlock disable.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
bool SAF_SWT_CheckHardlock(const uint8_t swtInst)
{
    DEV_ASSERT(swtInst < SWT_INSTANCE_NUM);

    bool ret = true;

    ret = (bool)(s_swtBase[swtInst]->CR.B.HLK) ? true : false;/* polyspace RTE:OBAI *//* polyspace RTE:NIV */

    return ret;
}

/**
****************************************************************************************
* @brief[SW_82] This function will be used for the path checking test of swt.
* @return status
            FS_STATUS_SUCCESS: Path test success.
            FS_STATUS_ERROR: Path test failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
FS_STATUS SAF_SWT_PathTest(void)
{
    saf_swt_path_test_result_t *pResult = &s_swtPathCheckTest;

    FS_STATUS status = FS_STATUS_SUCCESS;

    SWT_Module_Config_Type *pSwtConfig = NULL_PTR;
    uint32_t IntcFlag[SAF_SWT_INSTANCE_COUNT];
    uint8_t ConfigIndex = 0;
    SWT_ModuleID_Type swtInst = SWT0;

    for (ConfigIndex = 0; ConfigIndex < SAF_SWT_INSTANCE_COUNT; ConfigIndex++)
    {
        pSwtConfig = &(*SwtConfigSet.pUsedSwtConfig)[ConfigIndex];
        swtInst = pSwtConfig->SWT_ModuleID;/* polyspace RTE:IDP */
        pResult->PathTestCheckPassed[swtInst] = true;/* polyspace RTE:OBAI */

        if (false == SAF_SWT_IsInstanceAvailable(swtInst))
        {
        	continue;
        }

        if (false == SAF_SWT_SwtIsEnabled((uint8_t)swtInst))
        {
            if(FS_STATUS_SUCCESS == (FS_STATUS)SWT_LLD_Init(pSwtConfig))
            {
            	saf_delay(400);
            	if (SWT7_AO == swtInst)
            	{
            		saf_delay(200000);
            	}
                IntcFlag[swtInst] = (uint32_t)SWT_LLD_GetInterruptFlag(swtInst);
                if(SAF_SWT_INTERRUPT_FLAG != IntcFlag[swtInst])
                {
                    pResult->PathTestCheckPassed[swtInst] = false;
                    status = FS_STATUS_ERROR;
                }
                if(FS_STATUS_SUCCESS != SAF_SWT_Deinit((uint8_t)swtInst))
                {
                    pResult->PathTestCheckPassed[swtInst] = false;
                    status = FS_STATUS_ERROR;
                }
                else if(FS_STATUS_SUCCESS != SAF_SWT_AccessClearInterruptFlag(swtInst))
                {
                    pResult->PathTestCheckPassed[swtInst] = false;
                    status = FS_STATUS_ERROR;
                }
                else
                {
                    SAF_SWT_AccessFixedServiceWdg(swtInst);
                }
            }
            else
            {
                pResult->PathTestCheckPassed[swtInst] = false;
                status = FS_STATUS_ERROR;
            }
        }
        else
        {
            pResult->PathTestCheckPassed[swtInst] = false;
            status = FS_STATUS_ERROR;
        }
    }

     return status;
}

/**
****************************************************************************************
* @brief[SW_82] This function will be used to de-initialize the swt module configuration.
* @param[in] swtInst: Swt instance.
* @return status
            FS_STATUS_SUCCESS: De-initialize success.
            FS_STATUS_ERROR: De-initialize failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
FS_STATUS SAF_SWT_Deinit(const uint8_t swtInst)
{
    FS_STATUS status = FS_STATUS_ERROR;

    DEV_ASSERT(swtInst < SAF_SWT_INSTANCE_COUNT);

    if(true == SAF_SWT_SwtIsEnabled(swtInst))
    {
        status = SAF_SWT_AccessUnLock((SWT_ModuleID_Type)swtInst);

        if (status == FS_STATUS_SUCCESS)
        {
            /*Reset module*/
            SAF_SWT_AccessDeInit((SWT_ModuleID_Type)swtInst);
        }
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_82] This function is used to get the swt test results.
* @param[out] pTestResult: Swt path test result.
* @return status
            FS_STATUS_SUCCESS: Get results success.
            FS_STATUS_ERROR: Get results failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
FS_STATUS SAF_SWT_PathTestResult(saf_swt_path_test_result_t *pTestResult)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (NULL != pTestResult)
    {
        (void)memcpy(pTestResult, &s_swtPathCheckTest, sizeof(s_swtPathCheckTest));
        status = FS_STATUS_SUCCESS;
    }

    return status;
}

/**
****************************************************************************************
* @brief[SW_045] This function is be used to check if the monitor period is available.
* @param[in] swtInst: Swt instance.
* @param[in] fttiPeriodUs: Ftti period.
* @return ret
            true: Monitor period is smaller than ftti.
            false: Monitor period is longer than ftti.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
bool SAF_SWT_MonitorPeriodIsAvailable(const uint8_t swtInst, const uint32_t fttiPeriodUs)
{
    bool ret = true;
    uint32_t frequency = 0u;
    uint32_t realTicks = 0u;
    uint32_t expectedTicks = 0u;
    const SWT_tag_Type *pBase = NULL;

    if ((swtInst >= SAF_SWT_INSTANCE_COUNT) || (FS_STATUS_SUCCESS != SAF_SWT_AccessGetFreq(swtInst, &frequency)))
    {
        ret = false;
    }
    else
    {
        expectedTicks = (uint32_t)(((uint64_t)frequency * fttiPeriodUs) / 1000000U);

        pBase = s_swtBase[swtInst];
        realTicks = pBase->TO.R;/* polyspace RTE:NIV */

        if (expectedTicks < realTicks)
        {
            ret = false;
        }
    }

    return ret;
}

/**
****************************************************************************************
* @brief[SW_044] This function enables the swt module hard lock..
* @param[in] swtInst: Swt instance.
* @return status
            FS_STATUS_SUCCESS: Enable hardlock success.
            FS_STATUS_ERROR: Enable hardlock failed.
****************************************************************************************
*/
SAF_SWT_SEC_CODE
FS_STATUS SAF_SWT_EnableHardlock(const uint8_t swtInst)
{
    FS_STATUS status = FS_STATUS_ERROR;

    if (swtInst < SAF_SWT_INSTANCE_COUNT)
    {
        status = SAF_SWT_AccessSetSwtLock((SWT_ModuleID_Type)swtInst, SWT_Hardlock);
    }

    return status;
}

#ifdef __cplusplus
}
#endif
