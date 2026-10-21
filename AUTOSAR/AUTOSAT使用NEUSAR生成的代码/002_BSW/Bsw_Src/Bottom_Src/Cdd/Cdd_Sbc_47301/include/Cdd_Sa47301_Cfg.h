#ifndef _CDD_SA47301_CFG_H_
#define _CDD_SA47301_CFG_H_


#ifdef __cplusplus
extern "C" {
#endif

#define EB_AR_RELEASE_MAJOR_VERSION     4
#define EB_AR_RELEASE_MINOR_VERSION     4
#define EB_AR_RELEASE_REVISION_VERSION  0
#define EB_SW_MAJOR_VERSION             1
#define EB_SW_MINOR_VERSION             0
#define EB_SW_PATCH_VERSION             0

#define STD_ON                                    1
#define STD_OFF                                   0


#define SA_FEED_WWDG_TIME    3//(((EVPT_CDD_SA_WINWDGTMIN_CW_50WD + 1) * 50) + (((EVPT_CDD_SA_WINWDGTMARGIN_OW_50WD + 1) * 50) / 2 ) / 10)                   

#define SA_FEED_FWDG_TIME    3//((((EVPT_CDD_SA_FUNWDGHBTIMEPERIOD_600WD + 1) * 50) / 10 ) - 1)                 

#define SA47301_WWDG_ENABLE    (STD_ON)

#define SA47301_FWDG_ENABLE    (STD_ON)

#define EVPT_CDD_SPI_CHANNEL_SBC_SA47301_CH    SpiChannel_SBC_Sa47301

#define EVPT_CDD_SPI_SEQUENCE_SBC_SA47301_SEQ    SpiSequence_SBC_SA47301

#define SA_REG_DEVCFG0_CTRL    (STD_ON)

#define SA_REG_DEVCFG1_CTRL    (STD_ON)

#define SA_REG_DEVCFG2_CTRL    (STD_ON)

#define SA_REG_DEVCTRL_CTRL    (STD_ON)


#define SA_REG_SYSPCFG0_CTRL    (STD_ON)

#define SA_REG_SYSPCFG1_CTRL    (STD_ON)

#define SA_REG_WDCFG0_CTRL    (STD_ON)

#define SA_REG_WDCFG1_CTRL    (STD_ON)

#define SA_REG_FWDCFG_CTRL    (STD_ON)

#define SA_REG_WWDCFG0_CTRL    (STD_ON)

#define SA_REG_WWDCFG1_CTRL    (STD_ON)

#define SA_REG_WKTIMCFG0_CTRL    (STD_ON)

#define SA_REG_WKTIMCFG1_CTRL    (STD_ON)

#define SA_REG_WKTIMCFG2_CTRL    (STD_ON)

#define SA_REG_ABIST_CTRL0_CTRL    (STD_OFF)

#define SA_REG_ABIST_CTRL1_CTRL    (STD_OFF)

#define SA_REG_ABIST_SELECT0_CTRL    (STD_OFF)

#define SA_REG_ABIST_SELECT1_CTRL    (STD_OFF)

#define SA_REG_ABIST_SELECT2_CTRL    (STD_OFF)

#define SA_REG_BCK_FREQ_CHANGE_CTRL    (STD_OFF)

#define SA_REG_BCK_FREQ_SPREAD_CTRL    (STD_OFF)

#define SA_REG_BCK_MAIN_CTRL_CTRL    (STD_ON)

#define SA_REG_FCR_CTRL    (STD_ON)

#define SA_REG_MCUSUP_CTRL    (STD_ON)

// extern Cdd_Sa47301ConfigType_TDSTR Cdd_Sa47301_Config;


#ifdef __cplusplus
}
#endif

#endif /* _CDD_SA47301_CFG_H_ */