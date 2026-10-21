/* PRQA S 0602 EOF */
#ifndef _LIB_SWAP_H_
#define _LIB_SWAP_H_

#define LIBSWAP_VER_STR_MAX_LENGTH (16)

/*
 * @brief Get Flash Size
 *
 * This function is to Get Flash Swap status.
 *
 * @return 1U: get flash size fail.
 *         3U:  flash size is 3MB.
 *         4U:  flash size is 4MB.
 *         6U:  flash size is 6MB.
 *         8U:  flash size is 8MB.
 *         10U: flash size is 10MB.
 *         12U: flash size is 12MB.
 *         18U: flash size is 16.5MB.
 */
unsigned char FLASH_Get_Size(void);

/*
 * @brief Swap to Flash A partition
 *
 * This function is to Swap Flash A partition.
 *
 * @return 0U: Swap success.
 *         1U: Swap fail.
 */
unsigned char FLASH_Swap_A(void);

/*
 * @brief Swap to Flash B partition
 *
 * This function is to Swap Flash B partition.
 *
 * @return 0U: Swap success.
 *         1U: Swap fail.
 */ 
unsigned char FLASH_Swap_B(void);

/*
 * @brief Get Flash Swap status
 *
 * This function is to Get Flash Swap status.
 *
 * @return 0U: is A partition.
 *         1U: is B partition.
 */
unsigned char FLASH_Get_Swap_Status(void);

/*
 * @brief Erase Swap block
 *
 * This function is to Erase Swap block.
 *
 * @return 0U: Success.
 *         1U: Fail.
 */
unsigned char FLASH_Erase_Swap_Block_Async(void);

/*
 * @brief Waiting for Erase Swap block
 *
 * This function is used to wait for the erase state.
 *
 * @return 0U: Success.
 *         1U: Fail.
 *         2U: In Progress
 */
unsigned char FLASH_Erase_Swap_Block_Wait(void);

/*
 * @brief Swap to Flash A partition
 *
 * This function is to Swap Flash A partition.
 *
 * @return 0U: Swap success.
 *         1U: Swap fail.
 */
unsigned char FLASH_Swap_A_Async(void);

/*
 * @brief Swap to Flash B partition
 *
 * This function is to Swap Flash B partition.
 *
 * @return 0U: Swap success.
 *         1U: Swap fail.
 */ 
unsigned char FLASH_Swap_B_Async(void);

/*
 * @brief Get libSwap version
 *
 * This function is to get libSwap version.
 *
 * @return 0U: Get success.
 *         1U: Get fail.
 */ 
unsigned char FLASH_Get_LibSwap_Version(unsigned char *version);

#endif // _LIB_SWAP_H_
