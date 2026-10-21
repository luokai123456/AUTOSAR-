/*** create info ***********************
*@ Author : liufengyuan 
*@ date :2025-12-04
*@ Description :BSW bootloader functions H file
/*** modify info *********************** 
*@ version :0.0
*@ Modifier :  
*@ date :2025-12-04
*@ Modification Description :
初始版本
****************************************/
#ifndef __BSW_BOOTLOADER_H_
#define __BSW_BOOTLOADER_H_

#include "typedefs.h"

#define PBL_JUMP_MAGIC_WORD     0x50424C4A
#define SBL_JUMP_MAGIC_WORD     0x53424C4A

extern void BootLoader_MainFunction_10ms(void);

#endif /* __BSW_BOOTLOADER_H_ */
