/*** create info ***********************
*@ Author : duqian 
*@ date :2025-12-02
*@ Description :PWM-GTM configuration
/*** modify info *********************** 
*@ version :0.0
*@ Modifier : duqian 
*@ date :2025-12-02
*@ Modification Description :
初始版本
****************************************/
#include "IoHwAbs_PWM_Cfg.h"
#include "Pwm_LLDriver.h"
#include "CCFC3012PT.h"
 
/**
 * 变量名称: Pwm_valChannelConfig_STR
 * 描述: PWM输出通道参数配置
 */
const Pwm_IndexConfig_TDSTR  Pwm_valChannelConfig_STR[IOHWABS_PWM_PwmOutChannMax] =
{
    /* numPwmType    	numGtmType		numPwmChannel  		    	numPwmChannelCfgId*/
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON1,				PwmChannel_MCU_PWMOUT_CON1			},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON2,				PwmChannel_MCU_PWMOUT_CON2			},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON3,				PwmChannel_MCU_PWMOUT_CON3			},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON4,				PwmChannel_MCU_PWMOUT_CON4			},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON5,				PwmChannel_MCU_PWMOUT_CON5			},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON6,				PwmChannel_MCU_PWMOUT_CON6			},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_PWMOUT_CON10,			   PwmChannel_MCU_PWMOUT_CON10		},
    {IoHwAbs_GTM_PWM,		IoHwAbs_TOM_GTM,		IoHwAbs_PWM_MCU_VrefPhase_OCP_N,			PwmChannel_MCU_VrefPhase_OCP_N	},
    {IoHwAbs_GTM_PWM,       IoHwAbs_TOM_GTM,        IoHwAbs_PWM_MCU_VrefPhase_OCP_P,        PwmChannel_MCU_VrefPhase_OCP_P},
    {IoHwAbs_GTM_PWM,       IoHwAbs_TOM_GTM,        IoHwAbs_PWM_MCU_Vref_VDC,                PwmChannel_MCU_Vref_VDC},
    {IoHwAbs_GTM_PWM,       IoHwAbs_TOM_GTM,        IoHwAbs_PWM_MCU_PWMOUT_CON7,             PwmChannel_MCU_PWMOUT_CON7},
    {IoHwAbs_GTM_PWM,       IoHwAbs_TOM_GTM,        IoHwAbs_PWM_MCU_PWMOUT_CON11,            PwmChannel_MCU_PWMOUT_CON11},
};

void IoHwAbs_TOM_TrigAdc_Func(void)
{
    GTM4_TOM1.CH[7].CTRL.R = 0x1000000;
    GTM4_TOM1.CH[7].SR0.R = 1997;
    GTM4_TOM1.CH[7].SR1.R = 999;


    GTM4_TOM1.TGC0_GLB_CTRL.B.UPEN_CTRL7 = 2; 
    GTM4_TOM1.TGC0_ENDIS_CTRL.B.ENDIS_CTRL7 = 2;       /* 通道7: 使能通道 */
    GTM4_TOM1.TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = 2;       /* 通道7: 使能通道输出 */

    /* Final Activation */
    GTM4.GLS[1].CMU.CLK[0].CTRL.B.CLK_CNT = 0;
    GTM4_TOM1.TGC0_ACT_TB.B.TB_TRIG = 1u;                           /* Trigger timer base */
    GTM4_TOM1.TGC0_GLB_CTRL.B.HOST_TRIG = 1;                       /* Trigger TOM0 update */

}