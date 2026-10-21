/**
****************************************************************************************
 * @FilePath: SafetyCrcTst_Cfg.h
 * @Author: CCORE
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety test Crc configuration head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAFETYCRCTST_CFG_H
#define SAFETYCRCTST_CFG_H

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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                


/* Total number of startup tests */
#define CRC_TOTAL_READBACK_TESTS   ((uint8_t)29U)

#define SAF_CRC_SWITCH_OFF 0
#define SAF_CRC_SWITCH_ON 1

/* 1. xbar Switch */
#define SAF_CRC_XbarRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 2. pit Switch*/
#define SAF_CRC_PitRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 3. cmu Switch*/
#define SAF_CRC_CmuRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 4. pBridge Switch*/
#define SAF_CRC_PbridgeRegReadback_SWITCH      SAF_CRC_SWITCH_ON

/* 5. emios Switch*/
#define SAF_CRC_EmiosRegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 6. etpu Switch*/
#define SAF_CRC_EtpuRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 7. eqadc Switch*/
#define SAF_CRC_EqadcRegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 8. sdadc Switch*/
#define SAF_CRC_SdadcRegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 9. pmc Switch*/
#define SAF_CRC_PmcRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 10. siul2 Switch*/
#define SAF_CRC_Siul2RegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 11. MC_RGM Switch*/
#define SAF_CRC_RgmRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 12. INTC Switch*/
#define SAF_CRC_IntcRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 13. RAM Switch*/
#define SAF_CRC_RamRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 14. Flash Switch*/
#define SAF_CRC_FlashRegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 15. Can Switch*/
#define SAF_CRC_CanRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 16. Dma Switch*/
#define SAF_CRC_DmaRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 17. Dspi Switch*/
#define SAF_CRC_DspiRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 18. Emac Switch*/
#define SAF_CRC_EmacRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 19. Flexray Switch*/
#define SAF_CRC_FlexrayRegReadback_SWITCH      SAF_CRC_SWITCH_OFF

/* 20. I2c Switch*/
#define SAF_CRC_I2cRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 21. Linflex Switch*/
#define SAF_CRC_LinflexRegReadback_SWITCH      SAF_CRC_SWITCH_ON

/* 22. Mccgm Switch*/
#define SAF_CRC_MccgmRegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 23. Mcme Switch*/
#define SAF_CRC_McmeRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 24. Psi5 Switch*/
#define SAF_CRC_Psi5RegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 25. Sent Switch*/
#define SAF_CRC_SentRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 26. Smpu Switch*/
#define SAF_CRC_SmpuRegReadback_SWITCH         SAF_CRC_SWITCH_ON

/* 27. Stm Switch*/
#define SAF_CRC_StmRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 28. Canfd Switch*/
#define SAF_CRC_CanfdRegReadback_SWITCH        SAF_CRC_SWITCH_OFF

/* 29. Ssi Switch*/
#define SAF_CRC_SsiRegReadback_SWITCH          SAF_CRC_SWITCH_OFF

/* 30. Csent Switch*/
#define SAF_CRC_CsentRegReadback_SWITCH        SAF_CRC_SWITCH_ON

/* 31. I2s Switch*/
#define SAF_CRC_I2sRegReadback_SWITCH          SAF_CRC_SWITCH_ON

/* 32. I2sslv Switch*/
#define SAF_CRC_I2sslvRegReadback_SWITCH       SAF_CRC_SWITCH_ON

#ifdef __cplusplus
}
#endif

#endif
