/**
****************************************************************************************
 * @FilePath: saf_regprot.h
 * @Author: CCORE
 * @Date: 2024-02-12
 * @Copyright: 2024 CCORE CO.,LTD. All Rights Reserved.
 * @Descripttion:Safety Regprot head File
 * @MCAL Version: 3.0.1
 * @Safety Version: 3.0.0
****************************************************************************************
*/
#ifndef SAF_REGPROT_H
#define SAF_REGPROT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
****************************************************************************************
 * @brief: Include Files
****************************************************************************************
*/
#include "saf_common.h"
#include "typedefs.h"
#include "SafetyRegprotTst_Cfg.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


#define REGPROT_MODE_8BIT      	0
#define REGPROT_MODE_16BIT      1
#define REGPROT_MODE_32BIT      2

#define REGPROT_LOCK_DISABLE	0
#define REGPROT_LOCK_ENABLE		1

#define REGPROT_SLBR_LOCK_8BIT_VALUE   0x88U
#define REGPROT_SLBR_LOCK_16BIT_VALUE  0xCCU
#define REGPROT_SLBR_LOCK_32BIT_VALUE  0xFFU

#define REGPROT_SLBR_OFFSET_8BIT_MASK  0x3U
#define REGPROT_SLBR_OFFSET_16BIT_MASK 0x2U

#define REGPROT_SOFT_LOCK_BIT_OFFSET 0x2U

#define REGPROT_AREA4_SIZE             0x600U
/*!
 * @brief The REG prot module test result structure.
 *
 * This is the test result of regprot moduletest.
 * Implements : saf_regprot_test_result_t
 */
typedef struct
{
	FS_STATUS RegProtResult;
} saf_regprot_test_result_t;

/*!
* @brief The REG Prot module Test information structure.
*
* This is the config information of regprot test.
* Implements : saf_RegprotTestInfoType
*/
typedef struct
{
    const char * Name;	//register name
    uint32_t Base;		//register base addr
    uint16_t Offset;	//register addr offset
    uint16_t Mode;		//register protect mode
} saf_RegprotTestInfoType;

/*!
* @brief The REG Prot module Test information structure.
*
* This is the config information of regprot test.
* Implements : saf_RegprotConfigType
*/
typedef struct
{
    const saf_RegprotTestInfoType * RP_Test_Info;
    uint16_t Size; //instance register list size
} saf_RegprotConfigType;


/*!
* @brief The REG Prot module Test information structure.
*
* This is the config information of regprot test.
* Implements : saf_RegprotConfigType
*/
typedef struct
{                               //--OFFSET----SIZE----DESC.--
  union                         //   0000    6  K    Area #1
  {
    vuint8_t MR8[0x1800];           // 8-bit access mode
    vuint16_t MR16[0x0C00];         //16-bit access mode
    vuint32_t MR32[0x0600];         //32-bit access mode
  }A1;
  vuint8_t Res1[0x0800];        //   1800    2  K    Area #2
/* */
  union
  {                             //   2000    6  K    Area #3
    vuint8_t MMR8[0x1800];          // 8-bit access mode
    vuint16_t MMR16[0x0C00];        //16-bit access mode
    vuint32_t MMR32[0x0600];        //32-bit access mode
  }A3;
  vuint8_t SLBR[0x0600];        //   3800    1.5K    Area #4
/* */
  vuint8_t Res2[0x200-4];       //   3E00    448     Area #5
  struct
  {                             //   3F00      4     Area #5
    vuint32_t HLB:1;
    vuint32_t :7;
    vuint32_t UAA:1;
    vuint32_t :23;
  }GCR;
}RP;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif


extern const saf_RegprotConfigType RP_REG_LIST[SAF_RP_INSTANCE_COUNT];
/*!
 * This function is used to execute regprot test.
 *
 */
FS_STATUS SAF_RegProt_RegprotTest(SAF_REG_PROT_INSTANCE instanceIndex);

/*!
 * This function is used to lock regprot.
 *
 */
void SAF_RegProt_LockReg(uint8_t instanceIndex, uint16_t regIndex);

/*!
 * This function is used to unlock regprot.
 *
 */
void SAF_RegProt_UnlockReg(uint8_t instanceIndex, uint16_t regIndex);

/*!
 * This function is used to set register lock.
 *
 */



/*!
 * This function is used to get register lock.
 *
 */
uint8_t SAF_RP_GetLock(RP * rp, int offset);

#if defined (__cplusplus)
}
#endif

#endif/* SAF_REGPROT_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
