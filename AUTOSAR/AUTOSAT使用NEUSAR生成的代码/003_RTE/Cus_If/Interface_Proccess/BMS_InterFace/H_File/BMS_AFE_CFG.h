#ifndef _BMS_AFE_CFG_H
#define _BMS_AFE_CFG_H


#define BAT_VERSION                 BAT_65KWH                     //电池型号 BAT_51KWH：51KWH电池  BAT_65KWH：65KWH电池
#define AFE_NUM                     6U                            //需要支持的AFE芯片个数
#define ONE_AFE_TEMP_NUM            6U                            //单个AFE芯片采集的单体温度个数
#define ONE_AFE_VOL_NUM             18U                           //单个AFE芯片采集的单体电压个数
#define RUN_AFE_TEMP_NUM            4U                            //单个AFE芯片实际运行的单体温度个数
#define AFE_TOTAL_TEMP_NUM          (AFE_NUM * ONE_AFE_TEMP_NUM)  //AFE芯片采集温度的总个数
#define AFE_TOTAL_VOL_NUM           (AFE_NUM * ONE_AFE_VOL_NUM)   //AFE芯片采集电压的总个数


#endif /* _BMS_AFE_CFG_H */