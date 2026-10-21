/*** create info ***********************
 *@ filename : IoHwAbs_GTM.c
 *@ Author   : wangke
 *@ date     : 2026-08-14
 *@ Description : 
    * GTM The functional interface of the abstraction layer GTM
/*** modify info ***********************
 *@ version  : 0.0
 *@ Modifier : wangke
 *@ date     : 2026-08-14
 *@ Modification Description :
 * 初始版本
 ****************************************/

 /********************* Include Files *************************/
#include "CCFC3012PT.h"
#include "gtm410_reg.h"
#include "Icu_Cfg.h"
#include "Icu.h"





/********************* Global Varibles *************************/








/********************* Functions *************************/
void Gtm_FCCU_OUTConfig(void)
{
    Icu_StartSignalMeasurement(IcuChannel_FCCU_EOUT);
    GTM4.GLS[3].CMU.CLK[0].CTRL.B.CLK_CNT  = 0U;      
    GTM4.GLS[3].CMU.CLK_EN.B.EN_CLK0       = 2U;      

    /* ATOM3_CH0: SOMP, CMU_CLK0, up-count, active-high, 20 kHz/50%. */
    GTM4_ATOM3.CH[0].SOMP.B.MODE            = 2U;
    GTM4_ATOM3.CH[0].SOMP.B.CLK_SRC         = 0U;
    GTM4_ATOM3.CH[0].SOMP.B.UDMODE          = 0U;
    GTM4_ATOM3.CH[0].SOMP.B.RST_CCU0        = 0U;
    GTM4_ATOM3.CH[0].SOMP.B.SL              = 1U;
    GTM4_ATOM3.CH[0].SOMP.B.ARU_EN          = 0U;
    GTM4_ATOM3.CH[0].SOMP.B.OSM             = 0U;
    GTM4_ATOM3.CH[0].CTRL_SR.B.CLK_SRC_SR   = 0U;
    GTM4_ATOM3.CH[0].CTRL_SR.B.SL_SR        = 1U;
    GTM4_ATOM3.CH[0].CN0.B.CN0              = 0U;
    GTM4_ATOM3.CH[0].SR0.B.SR0              = 2500U;
    GTM4_ATOM3.CH[0].SR1.B.SR1              = 1250U;
    GTM4_ATOM3.CH[0].CM0.B.CM0              = 2500U;
    GTM4_ATOM3.CH[0].CM1.B.CM1              = 1250U;

    /* Enable shadow update, channel and output, then apply synchronously. */
    GTM4_ATOM3.AGC.GLB_CTRL.B.UPEN_CTRL0    = 2U;
    GTM4_ATOM3.AGC.ENDIS_CTRL.B.ENDIS_CTRL0 = 2U;
    GTM4_ATOM3.AGC.OUTEN_CTRL.B.OUTEN_CTRL0 = 2U;
    GTM4_ATOM3.AGC.GLB_CTRL.B.HOST_TRIG     = 1U;

    GTM4.GLS[0].TOUTSEL[18].B.SEL0 = 9U;    /* ATOM3_CH0_N */
}

void Fccu_Trig_PWM_TO_SBC_ERROR_PIN(void)
{
    /*20K 50% Duty*/
	GTM4_ATOM3.CH[0].CTRL.B.UDMODE 			= 0x00;
    GTM4_ATOM3.CH[0].SR0.B.SR0              = 10000;
    GTM4_ATOM3.CH[0].SR1.B.SR1              = 5000;
    GTM4_ATOM3.CH[0].CM0.B.CM0              = 10000;
    GTM4_ATOM3.CH[0].CM1.B.CM1              = 5000;
}

#define FCCU_DTM_SHUTOFF_SEL   (0U) 

void Cdd_Motor_DTMInit_FUNC(void)
{

//  GTM4.GLS[3].DTMAUXINSEL.B.ASEL3                 = 1;
    GTM4.GLS[3].CDTM.DTM[4].CTRL.B.CLK_SEL          = 1;
    GTM4.GLS[3].CDTM.DTM[4].CTRL.B.DTM_SEL          = 0;
    GTM4.GLS[3].CDTM.DTM[4].CTRL.B.UPD_MODE         = 3;
    GTM4.GLS[3].CDTM.DTM[4].CTRL.B.SR_UPD_EN        = 0;

    GTM4.GLS[3].CDTM.DTM[4].PS_CTRL.B.PSU_IN_SEL    = 0;
    GTM4.GLS[3].CDTM.DTM[4].PS_CTRL.B.TIM_SEL       = 1;
    /*The trigger level of the wave seal*/
    GTM4.GLS[3].CDTM.DTM[4].PS_CTRL.B.IN_POL        = 1;

    /*Enable the dead function*/
    GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2.B.DT0_0        = 1;
    GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2.B.DT1_0        = 1;

    /*The level state after wave sealing*/
    GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2_SR.B.DT0_0_SR  = 1;
    GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2_SR.B.DT1_0_SR  = 1;
    GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2_SR.B.OC0_0_SR  = 1;//ATOM3_0
    GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2_SR.B.OC1_0_SR  = 1;//ATOM3_0_N
    
    GTM4.GLS[3].CDTM.DTM[4].CTRL.B.SHUT_OFF_RST     = 1;

}
















/********************* End of File*************************/