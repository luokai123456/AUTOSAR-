/*** create info ***************************************************************
*@ File name: Nvm_Interface.h
*@ Author : liufengyuan 
*@ date :2025-04-27
*@ Description : 描述本文件实现功能
**** modify info ***************************************************************
*@ version :0.0
*@ Modifier : liufengyuan 
*@ date :2025-04-27
*@ Modification Description : 初始版本
********************************************************************************/
#ifndef BOTTOMLIB_INC_NVM_INTERFACE_H_
#define BOTTOMLIB_INC_NVM_INTERFACE_H_

#include "Std_Types.h"
#include "MemIf_Types.h"


/**
 * WARNING:
 * - This function reads data directly from the corresponding RAM block.
 * - The size of the read array is equal to the size of the target block; please ensure that the passed-in buffer pointer points to a buffer with a size greater than or equal to that of the block.
 * - This function is of blocking type. It will read back data immediately upon completion of execution, and it is not recommended to be used in scheduling.
 * 
 * Return Value Description:
 * - This function validates error states and returns the corresponding status code.
 * - It returns whether the read operation is successful or not.
 * @param Nvm_BlockId Block ID of the data block to be read (valid range: 50-58)
 * @param Nvm_DstPtr Pointer to the destination buffer
 * @return Std_ReturnType Status code of the read operation
 */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
    uint16 BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);
/**
 * WARNING:
 * - Regardless of whether the write operation succeeds or not, the incoming data content will be pre-stored in the RAM corresponding to the target block to be written.
 * - The validity of the length of the content pointed to by the incoming pointer will not be verified.
 * - Regardless of the length of the incoming data content, data with a length equal to the size of the block will be stored.
 * - CRC check will be performed during repeated writes to avoid unnecessary Flash wear.
 * 
 * Return Value Description:
 * - This function validates error states and returns the corresponding status code.
 * - It returns whether the write procedure is executed without exceptions.
 * 
 * @param Nvm_BlockId Block ID of the data block to be written (valid range: 50-58)
 * @param Nvm_DstPtr Pointer to the source data buffer
 * @return Std_ReturnType Status code of the write operation
 */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
    uint16 BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_CONST) NvM_SrcPtr
);

/* Service to read the block dependent error/status information. */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
    uint16 BlockId,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
);
extern FUNC(MemIf_StatusType, FEE_CODE) Fee_GetStatus(void);

#endif /* BOTTOMLIB_INC_NVM_INTERFACE_H_ */
