#include "Std_Types.h"
#include "Task_App_Core3.h"

#define RTE_CORE

#include "Rte_AngEmDev.h"
#include "Rte_AngOfstCal.h"
#include "Rte_AngSwDecod.h"
#include "Rte_BIfRx.h"
#include "Rte_BIfTx.h"
#include "Rte_Diag.h"
#include "Rte_DynFrq.h"
#include "Rte_EdrvStMac.h"
#include "Rte_HrmcInj.h"
#include "Rte_HvInvDev.h"
#include "Rte_IdqAct.h"
#include "Rte_IdqCtrl.h"
#include "Rte_MCU_fc_BIfRx_IN.h"
#include "Rte_MCU_fc_BIfRx_OUT.h"
#include "Rte_PhaCurrDev.h"
#include "Rte_VoltModlnGen.h"
#include "Rte_VoltModlnlnp.h"
#include "Interface_Test_IO.h"
#ifdef LOADTEST
#include "CCFC3012PT.h"
#include "Gpt_Stm_LLDriver.h"
uint8 time_BIfRx,time_HvInvDev,time_PhaCurrDev,time_AngEmDev,time_AngSwDecod,time_AngOfstCal,time_IdqAct,time_HrmcInj,time_IdqCtrl,time_VoltModlnInp,time_Diag,time_EdrvStMac,time_VoltModlnGen,time_DynFrq,time_BIfTx = 0;
#endif

FUNC(void, RTE_CODE) Core3_Runnable_Task_Init(void)
{

}

FUNC(void, RTE_CODE) Core3_Runnable_App_100us(void)
{
    Core3_Runnable_App_Rte_100us();
}

FUNC(void, RTE_CODE) Core3_Runnable_App_1ms(void)
{
    #ifdef VCU_Test_Code_YXP
    Test_SetIO_Status_LS11(0);
    #endif
}

inline FUNC(void, RTE_CODE) Core3_Runnable_App_Rte_100us(void)
{
    uint32 start,end = 0;
    MCU_fc_BIfRx_IN_100us();

    *(&Rte_Task_100us_Core3_QM.Rte_RB.Rte_BIfRx_fc_BIfRx.Rte_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V.value) = Rte_MCU_fc_BIfRx_IN_BSW_f32_uDCActSmp_V_BSW_f32_uDCActSmp_V;
    #ifdef LOADTEST
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_BIfRx();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_BIfRx = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_HvInvDev();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_HvInvDev = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_PhaCurrDev();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_PhaCurrDev = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_AngEmDev();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_AngEmDev = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_AngSwDecod();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_AngSwDecod = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_AngOfstCal();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_AngOfstCal = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_IdqAct();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_IdqAct = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_HrmcInj();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_HrmcInj = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_IdqCtrl();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_IdqCtrl = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_VoltModlnInp();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_VoltModlnInp = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_Diag();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_Diag = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_EdrvStMac();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_EdrvStMac = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_VoltModlnGen();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_VoltModlnGen = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_DynFrq();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_DynFrq = end - start;
    start = Gpt_Stm_LLD_GetCounter(STM0);
    #endif
    fc_BIfTx();
    #ifdef LOADTEST
    end = Gpt_Stm_LLD_GetCounter(STM0);
    time_BIfTx = end - start;
    #endif
    MCU_fc_BIfRx_OUT_100us();

}