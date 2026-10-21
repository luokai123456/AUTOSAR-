/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Crypto
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Crypto_LLDriver.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

/*
 * QAC violations
 *
 * @ID:rcma-4.0.0-1534 Rule:M3CM Rule-2.5
 * The macro '%1s' is declared but not used within this project.
 *
 * @ID:rcma-4.0.0-1535 Rule:M3CM Rule-2.3
 * The typedef '%1s' is declared but not used within this project.
 */

/* PRQA S 1534, 1535, 0602, 1536, 1506 EOF */

#ifndef CRYPTO_LLDRIVER_H
#define CRYPTO_LLDRIVER_H

#include "status.h"
#include "common.h"
#include "derivative.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "Csm.h"
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* brief Macro used for checking 'HSM enabled' bit in SSCM */
#define HSM_ENABLED               	(SSCM.UOPS.B.HSE != 0U)

/* brief Macro used for checking security firmware start address */
#define HSM_VALID_START_ADDR      	(SSCM.HSA.B.HADR != 0U)

/* brief Macro used for checking buffer address */
#define HSM_BUFF_ADDR_CHECK_MASK  	0x03U

/*! @brief Macro used for checking buffer length */
#define HSM_BUFF_LEN_CHECK_MASK  	0x0FU

/*! @brief Macro used for checking version buffer length */
#define HSM_FM_VER_LEN            	0x40U

/*! @brief Security error codes offset in status.h */
#define HSM_ERC_OFFSET            	0x400U

#define HSM_STATUS_MASK           	(0x1UL << 0)
#define HSM_STATUS_BUSY           	(0x1UL)
#define HSM_STATUS_READY          	(0x0UL)

#define SUSPEND_O	0x12345678
#define SUSPEND_REG	((*(volatile uint32_t*)0xfc0c0008))

#define SUPPORT_NEW_CACHE_API	0

/*! @brief Macro used for unused command parameters */
#define HSE_OPERATION_TIMEOUT     	((uint32_t)0xDFFFFFUL)
/*==================================================================================================
*                                     HSM Service Command
==================================================================================================*/
typedef uint32_t hsmSrvCmd_t;
#define HSM_SRV_CMD_NONE                            	((hsmSrvCmd_t)0x00000000)

#define HSM_SRV_CMD_GET_ATTR                        	((hsmSrvCmd_t)0x00010001)
#define HSM_SRV_CMD_SET_ATTR                        	((hsmSrvCmd_t)0x00010002)
#define HSM_SRV_CMD_DEV_AUTH_REQ                    	((hsmSrvCmd_t)0x00010003)
#define HSM_SRV_CMD_DEV_AUTH_RESP                   	((hsmSrvCmd_t)0x00010004)
#define HSM_SRV_CMD_DEV_AUTH_RST						((hsmSrvCmd_t)0x00010005)
#define HSM_SRV_CMD_CONFIG_SECURE_BOOT              	((hsmSrvCmd_t)0x00010006)
#define HSM_SRV_CMD_IGNORE_SECURE_BOOT              	((hsmSrvCmd_t)0x00010007)
#if (defined(CCFC3007PT) || defined(CCFC3008PT))
#define HSM_SRV_CMD_INSTALL_SMR_ENTRY					((hsmSrvCmd_t)0x00010008)
#define HSM_SRV_CMD_RAMWAIT	                        	((hsmSrvCmd_t)0x00010009)
#else
#define HSM_SRV_CMD_INSTALL_SMR_ENTRY					((hsmSrvCmd_t)0x00010009)
#define HSM_SRV_CMD_RAMWAIT	                        	((hsmSrvCmd_t)0x00010008)
#endif
#define HSM_SRV_CMD_CONFIG_SECURE_BOOT_SWP              ((hsmSrvCmd_t)0x000100A1)
#define HSM_SRV_CMD_SET_CLK_DIV                     	((hsmSrvCmd_t)0x000100AA)

#define HSM_SRV_CMD_GET_TRNG_NUMBER                 	((hsmSrvCmd_t)0x00020001)
#define HSM_SRV_CMD_GET_PRNG_NUMBER                 	((hsmSrvCmd_t)0x00020002)

#define HSM_SRV_CMD_ERASE_KEY                       	((hsmSrvCmd_t)0x00030001)
#define HSM_SRV_CMD_IMPORT_KEY                       	((hsmSrvCmd_t)0x00030002)
#define HSM_SRV_CMD_EXPORT_KEY                        	((hsmSrvCmd_t)0x00030003)
#define HSM_SRV_CMD_GET_KEY_INFO                      	((hsmSrvCmd_t)0x00030004)
#define HSM_SRV_CMD_KEY_DERIVE                          ((hsmSrvCmd_t)0x00030005)
#define HSM_SRV_CMD_KEY_GENERATE                        ((hsmSrvCmd_t)0x00030006)
#define HSM_SRV_CMD_GET_KEY_HASH                        ((hsmSrvCmd_t)0x00030007)

#define HSM_SRV_CMD_HASH                               	((hsmSrvCmd_t)0x00040001)
#define HSM_SRV_CMD_MAC                                	((hsmSrvCmd_t)0x00040002)
#define HSM_SRV_CMD_SYM_CIPHER                         	((hsmSrvCmd_t)0x00040003)
#define HSM_SRV_CMD_AEAD                               	((hsmSrvCmd_t)0x00040004)
#define HSM_SRV_CMD_SIGN                               	((hsmSrvCmd_t)0x00040005)
#define HSM_SRV_CMD_RSA_CIPHER                         	((hsmSrvCmd_t)0x00040006)
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_SRV_CMD_SM2_CIPHER                         	((hsmSrvCmd_t)0x00040007)
#endif
#define HSM_SRV_CMD_WRITE_USER_DATA                     ((hsmSrvCmd_t)0x00050001)
#define HSM_SRV_CMD_READ_USER_DATA                      ((hsmSrvCmd_t)0x00050002)

#define HSM_SRV_CMD_FW_UPDATA_INIT                     ((hsmSrvCmd_t)0x00070001)
#define HSM_SRV_CMD_FW_UPDATE_PROCESS                  ((hsmSrvCmd_t)0x00070002)
#define HSM_SRV_CMD_FW_UPDATE_FINAL                    ((hsmSrvCmd_t)0x00070003)

typedef uint8_t hsmOperationMode_t;
#define HSM_OPERATION_MODE_SINGLE_CALL                 	((hsmOperationMode_t)0x0U)
#define HSM_OPERATION_MODE_START                       	((hsmOperationMode_t)0x1U)
#define HSM_OPERATION_MODE_UPDATE                      	((hsmOperationMode_t)0x2U)
#define HSM_OPERATION_MODE_FINISH                      	((hsmOperationMode_t)0x3U)

typedef uint8_t hsmHashAlgo_t;
#define HSM_HASH_ALGO_NOT_SET         					((hsmHashAlgo_t)0x00U)
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_HASH_ALGO_SM3               				((hsmHashAlgo_t)0x01U)
#endif
#define HSM_HASH_ALGO_SHA0             			 		((hsmHashAlgo_t)0x02U)
#define HSM_HASH_ALGO_MD5               				((hsmHashAlgo_t)0x03U)
#define HSM_HASH_ALGO_SHA1              				((hsmHashAlgo_t)0x04U)
#define HSM_HASH_ALGO_SHA2_224          				((hsmHashAlgo_t)0x05U)
#define HSM_HASH_ALGO_SHA2_256          				((hsmHashAlgo_t)0x06U)
#define HSM_HASH_ALGO_SHA2_384          				((hsmHashAlgo_t)0x07U)
#define HSM_HASH_ALGO_SHA2_512          				((hsmHashAlgo_t)0x08U)
#define HSM_HASH_ALGO_SHA3_224          				((hsmHashAlgo_t)0x09U)
#define HSM_HASH_ALGO_SHA3_256          				((hsmHashAlgo_t)0x0AU)
#define HSM_HASH_ALGO_SHA3_384          				((hsmHashAlgo_t)0x0BU)
#define HSM_HASH_ALGO_SHA3_512          				((hsmHashAlgo_t)0x0CU)
#define HSM_HASH_ALGO_RIPEMD160         				((hsmHashAlgo_t)0x0DU)

/** @brief    Symmetric Cipher Algorithms .*/
typedef uint8_t hsmCipherAlgo_t;
#define HSM_CIPHER_ALGO_NULL         					((hsmCipherAlgo_t)0x00U)     /**< @brief NULL cipher */
#define HSM_CIPHER_ALGO_AES          					((hsmCipherAlgo_t)0x01U)     /**< @brief AES cipher */
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_CIPHER_ALGO_SM4          					((hsmCipherAlgo_t)0x02)      /**< @brief SM4 cipher */
#endif
/** @brief    Symmetric Cipher Block Modes */
typedef uint8_t hsmCipherBlockMode_t;
#define HSM_CIPHER_BLOCK_MODE_NULL   					((hsmCipherBlockMode_t)0U)   /**< @brief NULL cipher */
#define HSM_CIPHER_BLOCK_MODE_CTR    					((hsmCipherBlockMode_t)1U)   /**< @brief CTR mode (SYM) */
#define HSM_CIPHER_BLOCK_MODE_CBC    					((hsmCipherBlockMode_t)2U)   /**< @brief CBC mode (SYM) */
#define HSM_CIPHER_BLOCK_MODE_ECB    					((hsmCipherBlockMode_t)3U)   /**< @brief ECB mode (SYM) */
#define HSM_CIPHER_BLOCK_MODE_CFB    					((hsmCipherBlockMode_t)4U)   /**< @brief CFB mode (SYM) */
#define HSM_CIPHER_BLOCK_MODE_OFB    					((hsmCipherBlockMode_t)5U)   /**< @brief OFB mode (SYM) */

/** @brief    Symmetric CFB/OFB Stream bits */
typedef uint8_t hsmCipherStreambits_t;
#define HSM_CIPHER_STREAM_BITS_NULL          			((hsmCipherStreambits_t)0U)
#define HSM_CIPHER_STREAM_1_BITS             			((hsmCipherStreambits_t)1U)
#define HSM_CIPHER_STREAM_8_BITS             			((hsmCipherStreambits_t)2U)
#define HSM_CIPHER_STREAM_16_BITS            			((hsmCipherStreambits_t)3U)
#define HSM_CIPHER_STREAM_32_BITS            			((hsmCipherStreambits_t)4U)
#define HSM_CIPHER_STREAM_64_BITS            			((hsmCipherStreambits_t)5U)
#define HSM_CIPHER_STREAM_128_BITS           			((hsmCipherStreambits_t)6U)

/** @brief   HSM cipher direction: encryption/decryption */
typedef uint8_t hsmCipherDir_t;
#define HSM_CIPHER_DIR_ENCRYPT        					((hsmCipherDir_t)0U)         /**< @brief Decrypt */
#define HSM_CIPHER_DIR_DECRYPT        					((hsmCipherDir_t)1U)         /**< @brief Encrypt */

/** @brief   HSM Authenticated cipher/encryption mode (only AES supported). */
typedef uint8_t hsmAuthCipherMode_t;
#define HSM_AUTH_CIPHER_MODE_CCM     					((hsmAuthCipherMode_t)0x11U)  /**< @brief CCM mode */
#define HSM_AUTH_CIPHER_MODE_GCM     					((hsmAuthCipherMode_t)0x12U)  /**< @brief GCM mode */

/** @brief   authentication direction: generate/verify.*/
typedef uint8_t hsmAuthDir_t;
#define HSM_AUTH_DIR_VERIFY          					((hsmAuthDir_t)0U)            /**< @brief Verify authentication tag */
#define HSM_AUTH_DIR_GENERATE        				    ((hsmAuthDir_t)1U)            /**< @brief Generate authentication tag */

/** @brief  MAC algorithm.*/
typedef uint8_t hsmMacAlgo_t;
#define HSM_MAC_ALGO_CMAC               				((hsmMacAlgo_t)0x00U)         /**< @brief CMAC (AES)*/
#define HSM_MAC_ALGO_GMAC               				((hsmMacAlgo_t)0x01U)         /**< @brief GMAC (AES)*/
#define HSM_MAC_ALGO_HMAC               				((hsmMacAlgo_t)0x02U)         /**< @brief HMAC */

/** @brief   RSA algorithm types.*/
typedef uint8_t hsmRsaAlgo_t;
#define HSM_RSA_ALGO_NO_PADDING        					((hsmRsaAlgo_t)0x00U)        /**< @brief The input will be treated as an unsigned integer and perform a modular exponentiation of the input  */
#define HSM_RSA_ALGO_RSAES_OAEP        					((hsmRsaAlgo_t)0x01U)        /**< @brief RSAES OAEP cipher */
#define HSM_RSA_ALGO_RSAES_PKCS1_V15   					((hsmRsaAlgo_t)0x02U)        /**< @brief ECDSA RSAES_PKCS1_V15 cipher */
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
typedef uint8_t hsmSm2Algo_t;
#define HSM_SM2_ALGO_CIPHER            					((hsmSm2Algo_t)0x00U)
#define HSM_SM2_ALGO_SIGN              					((hsmSm2Algo_t)0x01U)
#endif
typedef uint8_t hsmSignSchemeEnum_t;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_SIGN_SM2				  					((hsmSignSchemeEnum_t)0x0U) /**< @brief SM2 signature scheme */
#endif
#define HSM_SIGN_ECDSA                					((hsmSignSchemeEnum_t)0x1U) /**< @brief ECDSA signature scheme */
#define HSM_SIGN_RSASSA_PKCS1_V15     					((hsmSignSchemeEnum_t)0x2U) /**< @brief RSASSA_PKCS1_V15 signature scheme */
#define HSM_SIGN_RSASSA_PSS           					((hsmSignSchemeEnum_t)0x3U) /**< @brief RSASSA_PSS signature scheme */

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
/* add Ed25519*/
#define HSM_SIGN_ED_25519          	 			        ((hsmSignSchemeEnum_t)0x4U) /**< @brief ED_25519 signature scheme */
#endif

typedef uint8_t hsmAuthAlgo_t;
#define HSM_AUTH_ALGO_CMAC            					((hsmAuthAlgo_t)0x00U)  /**< @brief CMAC (AES)*/
#define HSM_AUTH_ALGO_GMAC            					((hsmAuthAlgo_t)0x01U)  /**< @brief GMAC (AES)*/
#define HSM_AUTH_ALGO_HMAC            					((hsmAuthAlgo_t)0x02U)  /**< @brief HMAC */
#define HSM_AUTH_ALGO_SM2				  				((hsmAuthAlgo_t)0x03U) 	/**< @brief SM2   */
#define HSM_AUTH_ALGO_ECDSA                				((hsmAuthAlgo_t)0x04U) 	/**< @brief ECDSA   */
#define HSM_AUTH_ALGO_RSASSA_PKCS1V15     				((hsmAuthAlgo_t)0x05U) 	/**< @brief RSASSA_PKCS1V15   */
#define HSM_AUTH_ALGO_RSASSA_PSS          	 			((hsmAuthAlgo_t)0x06U) 	/**< @brief RSASSA_PSS */

/** @brief    HSM Key Type */
typedef uint16_t hsmKeyType_t;
#define HSM_KEY_TYPE_SHE                                (hsmKeyType_t)0x1U /* @brief Symmetric AES128 key used with SHE specification commands.
                                        It can be used with any AES block ciphering mode and AES MACs (same as any AES128 key). */
#define HSM_KEY_TYPE_AES                                (hsmKeyType_t)0x2U
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_KEY_TYPE_SM4                                (hsmKeyType_t)0x3U
#endif
#define HSM_KEY_TYPE_HMAC								(hsmKeyType_t)0x4U
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_KEY_TYPE_SM2_PUB                            (hsmKeyType_t)0x5U
#define HSM_KEY_TYPE_SM2_PRIV                           (hsmKeyType_t)0x6U
#define HSM_KEY_TYPE_SM2_PAIR                           (hsmKeyType_t)0x7U
#endif
#define HSM_KEY_TYPE_RSA_PUB                            (hsmKeyType_t)0x8U
#define HSM_KEY_TYPE_RSA_PRIV                           (hsmKeyType_t)0x9U
#define HSM_KEY_TYPE_RSA_PAIR                           (hsmKeyType_t)0xAU
#define HSM_KEY_TYPE_ECC_PUB                            (hsmKeyType_t)0xBU
#define HSM_KEY_TYPE_ECC_PRIV                           (hsmKeyType_t)0xCU
#define HSM_KEY_TYPE_ECC_PAIR                           (hsmKeyType_t)0xDU
#define HSM_KEY_TYPE_PASSWD								(hsmKeyType_t)0xEU

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
/*add ED25519*/
#define HSM_KEY_TYPE_ED_25519_PUB                       (hsmKeyType_t)0xFU
#define HSM_KEY_TYPE_ED_25519_PRIV                      (hsmKeyType_t)0x10U
#endif

#define HSM_KEY_TYPE_NOT_SET                            (hsmKeyType_t)0xFFU

/** @brief    HSM Key Flags */
typedef uint16_t hsmKeyFlags_t;
#define HSM_KEY_FLAG_USAGE_ENCRYPT                      (hsmKeyFlags_t)(1U << 0)
#define HSM_KEY_FLAG_USAGE_DECRYPT                      (hsmKeyFlags_t)(1U << 1)
#define HSM_KEY_FLAG_USAGE_SIGN                         (hsmKeyFlags_t)(1U << 2)
#define HSM_KEY_FLAG_USAGE_VERIFY                       (hsmKeyFlags_t)(1U << 3)
#define HSM_KEY_FLAG_USAGE_DERIVE                       (hsmKeyFlags_t)(1U << 4)
#define HSM_KEY_FLAG_USAGE_AUTH                         (hsmKeyFlags_t)(1U << 5)
#define HSM_KEY_FLAG_ACCESS_WRITE_PROT                  (hsmKeyFlags_t)(1U << 6)
#define HSM_KEY_FLAG_ACCESS_EXPORTABLE                  (hsmKeyFlags_t)(1U << 7)
#define HSM_KEY_FLAG_USAGE_UNLOCK_JTAG					(hsmKeyFlags_t)(1U << 10)

/** @brief    HSM Key Bits */
typedef uint16_t hsmKeyBits_t;
#define HSM_KEY_BITS_ZERO           					(hsmKeyBits_t)0U
#define HSM_KEY_BITS_128            					(hsmKeyBits_t)128U
#define HSM_KEY_BITS_192            					(hsmKeyBits_t)192U
#define HSM_KEY_BITS_256            					(hsmKeyBits_t)256U
#define HSM_KEY_BITS_384            					(hsmKeyBits_t)384U
#define HSM_KEY_BITS_512            					(hsmKeyBits_t)512U
#define HSM_KEY_BITS_1024           					(hsmKeyBits_t)1024U
#define HSM_KEY_BITS_2048           					(hsmKeyBits_t)2048U
#ifndef CCFC3008PC
#define HSM_KEY_BITS_3072           					(hsmKeyBits_t)3072U
#define HSM_KEY_BITS_4096           					(hsmKeyBits_t)4096U
#endif
/** @brief The ECC curve IDs*/
typedef uint8_t hsmEccCurveId_t;
#define HSM_EC_CURVE_NONE								((hsmEccCurveId_t)0U)
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_EC_CURVE_SM2				  				((hsmEccCurveId_t)1U)
#endif
#define HSM_EC_SEC_SECP256R1              				((hsmEccCurveId_t)2U)

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define HSM_EC_SEC_SECP384R1              				((hsmEccCurveId_t)3U)
#endif

/** @brief Host address size */
#define HOST_ADDR                    					uint32_t

typedef uint32_t hsmKeyHandle_t;

typedef uint8_t hsmKeyGroupIdx_t;
#define HSM_KEY_GROUP_SYM       						((hsmKeyGroupIdx_t)0U)
#define HSM_KEY_GROUP_ASYM      						((hsmKeyGroupIdx_t)1U)


/** @brief    Options to erase keys.
 *  @details  The erase key options are used only if the provided key handle is set to #HSE_INVALID_KEY_HANDLE. */
typedef uint8_t hsmEraseKeyOptions_t;
#define HSM_ERASE_NOT_USED          					(0U)  /**< @brief Erase key options not used. */
#define HSM_ERASE_ALL_RAM_KEYS      					(1U)  /**< @brief Erase all nvm sym keys. */
#define HSM_ERASE_ALL_NVM_SYM_KEYS  					(2U)  /**< @brief Erase all nvm sym keys if keyFLags not set writeprotect. */
#define HSM_ERASE_ALL_NVM_ASYM_KEYS 					(3U)  /**< @brief Erase all nvm asym keys if keyFLags not set writeprotect. */
#define HSM_ERASE_ALL_NVM_KEYS_IGNORE_WRITE_PROT      	(4U)  /**< @brief */
#define HSM_ERASE_ALL_NVM_SYM_KEYS_IGNORE_WRITE_PROT    (5U)  /**< @brief */
#define HSM_ERASE_ALL_NVM_ASYM_KEYS_IGNORE_WRITE_PROT   (6U)  /**< @brief */

typedef uint8_t hsmDevAuthOption_t;
#define HSM_DEV_AUTH_KEY_MGMT            				((hsmDevAuthOption_t)(1U << 0U))
#define HSM_DEV_AUTH_USERDATA_MGMT       				((hsmDevAuthOption_t)(1U << 1U))
#define HSM_DEV_AUTH_FW_UPDATE			 				((hsmDevAuthOption_t)(1U << 2U))
#define HSM_DEV_AUTH_FLASH_OPERATION			 		((hsmDevAuthOption_t)(1U << 3U))
#define HSM_DEV_AUTH_SECURE_BOOT			 			((hsmDevAuthOption_t)(1U << 4U))
#define HSM_DEV_AUTH_ALL                 				(HSM_DEV_AUTH_SECURE_BOOT | HSM_DEV_AUTH_KEY_MGMT | HSM_DEV_AUTH_USERDATA_MGMT | HSM_DEV_AUTH_FW_UPDATE | HSM_DEV_AUTH_FLASH_OPERATION)

/** @brief Challenge length: Length of the challenge (in bytes) returned by a successful authorization request. */
#define HSM_DEVAUTH_CHALLENGE_LENGTH    				(32U)

/** @brief   HSM key catalog type */
typedef uint8_t hsmKeyCatalogId_t;
#define HSM_KEY_CATALOG_ID_NVM        					((hsmKeyCatalogId_t)0U)    /**< @brief NVM key catalog */
#define HSM_KEY_CATALOG_ID_RAM        					((hsmKeyCatalogId_t)1U)    /**< @brief RAM key catalog */

typedef uint8_t hsmKeySlotIdx_t;

/** @brief All keys used in cryptographic operations are referenced by a unique key handle. */
#define GET_KEY_HANDLE(catalogId, groupIdx, slotIdx) \
                      ((((hsmKeyHandle_t)((hsmKeyCatalogId_t)(catalogId))) << 16U) | \
                       (((hsmKeyHandle_t)((hsmKeyGroupIdx_t)(groupIdx))) << 8U) | \
                       (((hsmKeyHandle_t)((hsmKeyCatalogId_t)(slotIdx)))))

#define GET_CATALOG_ID(keyHandle)     					((hsmKeyCatalogId_t)((keyHandle) >> 16U)) /**< @brief Get key catalog Id. */
#define GET_GROUP_IDX(keyHandle)      					((hsmKeyGroupIdx_t)((keyHandle) >> 8U))
#define GET_SLOT_IDX(keyHandle)       					((hsmKeySlotIdx_t)(keyHandle))            /**< @brief Get key slot index. */

#define HSM_INVALID_KEY_HANDLE        					((hsmKeyHandle_t)0xFFFFFFFFUL)   /**< @brief HSM invalid key . */
#define HSM_INVALID_SLOT_IDX          					((hsmKeySlotIdx_t)0xFFU)         /**< @brief HSM invalid key slot index. */

/** @brief HSM Key Generate Type. */
typedef uint8_t hsmKeyGenScheme_t;
#define HSM_KEY_GEN_SYM_RANDOM_KEY     				 	((hsmKeyGenScheme_t)1U) /**< @brief Generate a random symmetric key (e.g AES, SM4). */
#define HSM_KEY_GEN_RSA_KEY_PAIR                     	((hsmKeyGenScheme_t)2U) /**< @brief Generate a RSA key pair. */
#define HSM_KEY_GEN_ECC_KEY_PAIR                     	((hsmKeyGenScheme_t)3U) /**< @brief Generate a ECC key pair. */
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define HSM_KEY_GEN_SM2_KEY_PAIR                     	((hsmKeyGenScheme_t)4U) /**< @brief Generate a SM2 key pair. */
#endif
#define HSM_KEY_GEN_JTAG_PASSWD						    ((hsmKeyGenScheme_t)5U) /**< @brief Generate Jtag password */

typedef uint16_t hsmAttrId_t;
#define HSM_ATTR_ID_FW_VERSION           				((hsmAttrId_t)1U)
#define HSM_ATTR_ID_SECURE_BOOT_STATUS   				((hsmAttrId_t)2U)
#define HSM_ATTR_ID_FLASH_LOCK             				((hsmAttrId_t)3U)
#define HSM_ATTR_ID_DATA_VERSION             			((hsmAttrId_t)4U)
#define HSM_ATTR_ID_BOOT_TYPE			              	((hsmAttrId_t)8U)
#define HSM_ATTR_ID_SMR_ENTRY							((hsmAttrId_t)9U)
#define HSM_ATTR_ID_SECBOOT_ALL							((hsmAttrId_t)0xAU)
#define HSM_ATTR_ID_STACK_REMAIN						((hsmAttrId_t)0xBU)
#define HSM_ATTR_ID_GET_COUNTER							((hsmAttrId_t)0xCU)
#define HSM_ATTR_ID_SET_PARAM             				((hsmAttrId_t)0xDU)

#define HSM_SECURE_BOOT_ENTRY_VALID_FLAG    			0x87654321UL

typedef uint8_t hsmSecureBootType_t;
#define HSM_SECURE_BOOT_TYPE_NONE                       ((hsmSecureBootType_t)0xFFU)
#define HSM_SECURE_BOOT_TYPE_FAST                       ((hsmSecureBootType_t)0x00U)
#define HSM_SECURE_BOOT_TYPE_STRICT                     ((hsmSecureBootType_t)0x01U)

typedef uint8_t hsmSecureBootFailOp_t;
#define HSM_SECURE_BOOT_ONFAIL_DEGRADE					((hsmSecureBootFailOp_t)0x00U)
#define HSM_SECURE_BOOT_ONFAIL_RESET                    ((hsmSecureBootFailOp_t)0x01U)
#define HSM_SECURE_BOOT_ONFAIL_LOOP                     ((hsmSecureBootFailOp_t)0x02U)

typedef uint8_t hsmSecureBootStatus_t;
#define HSM_SECURE_BOOT_NONE                            ((hsmSecureBootStatus_t)0x33U)
#define HSM_SECURE_BOOT_OK                              ((hsmSecureBootStatus_t)0x11U)
#define HSM_SECURE_BOOT_FAIL                            ((hsmSecureBootStatus_t)0x22U)
#define HSM_SECURE_BOOT_NOT_START                       ((hsmSecureBootStatus_t)0x00U)

#define HSM_SECURE_BOOT_MAX_CODE_SEG					(8)

struct _verify_code_segment
{
    uint32_t address;
    uint32_t length;
} ;

typedef struct _verifyCodeSegments
{
	struct _verify_code_segment seg[HSM_SECURE_BOOT_MAX_CODE_SEG];
}verifyCodeSegments;

typedef struct
{
    uint8_t*         authTag0;
    uint16_t         authTag0Len;
} hostSecureBootTag_t;

typedef struct
{
	hostSecureBootTag_t sign[HSM_SECURE_BOOT_MAX_CODE_SEG];
} codeSigns;

typedef struct
{
    uint8_t          authTag0[512];
} hostSecureBootTag0_t;

typedef struct
{
	hostSecureBootTag0_t sign[HSM_SECURE_BOOT_MAX_CODE_SEG];
} codeSigns0;

/* @brief HSM key info structure. */
typedef struct
{
    hsmKeyType_t  keyType;

    hsmKeyFlags_t keyFlags;

    /** @brief The length of key in bits.
     * - For RSA, bit length of modulus n
     * - For SM2, the bit length of the base point order.
     * - Any other key, the bit length of the key. */
    hsmKeyBits_t  keyBitLen;

    uint16_t reversed0;

    /** @brief
     *         The key counter for SHE keys follows the SHE specification (e.g. key counter is 28bits;
     *         for SHE RAM keys, the key counter is forced to zero). */
    uint32_t      keyCounter;

    union
    {
        hsmEccCurveId_t   eccCurveId;
    } special;
    uint8_t reversed1[3];
} hsmKeyInfo_t;

typedef struct
{
    /** @brief   INPUT: Specifies the HSM attribute ID.*/
    hsmAttrId_t   attrId;
    uint8_t       reserved[2];
    /** @brief   INPUT: Specifies the attribute length (in bytes). The size of the memory location
     *                   must be equal to the length of attribute structure */
    union{
    	uint32_t      attrLen;
    	uint32_t      attrOffset;
    };
    /** @brief   INPUT: The address of the attribute. */
    HOST_ADDR     pAttr;
} hsmSetAttrSrv_t;

/** @brief Get HSE attribute service. */
typedef struct
{
    /** @brief   INPUT: Specifies the HSE attribute ID.*/
    hsmAttrId_t   attrId;
    uint8_t       reserved[2];
    /** @brief   INPUT: Specifies the attribute length (in bytes).The size of the memory location
     *                  must be bigger than or equal to the length of attribute structure */
    uint32_t      attrLen;
    /** @brief   OUTPUT: The address where the attribute will be stored. */
    HOST_ADDR     pAttr;
} hsmGetAttrSrv_t;

/** @brief Get Random Number Service.
 *  @details  Includes parameters needed for get ranndom number. */
typedef struct
{
    /** @brief   INPUT:  The length of the generated random number in bytes. Must be a multiple of word(4B) length. */
    uint32_t                randomNumLength;

    /** @brief   OUTPUT:  The address where the random number will be stored. */
    HOST_ADDR               pRandomNum;
} hsmGetRandomNumSrv_t;

/** @brief HSM symmetric cipher scheme.
 *  @details Includes parameters needed for a symmetric cipher.
 */
typedef struct
{
    /** @brief   INPUT: Select an symmetric cipher. */
    hsmCipherAlgo_t         cipherAlgo;
    /** @brief   INPUT: Specifies the cipher block mode. */
    hsmCipherBlockMode_t    cipherBlockMode;

    hsmCipherStreambits_t   cipherStreamBits;

    uint8_t                 reserved;
    /** @brief   INPUT: Initialization Vector length(at least 16 bytes). */
    uint32_t                ivLength;
    /** @brief   INPUT: Initialization Vector/Nonce. */
    HOST_ADDR               pIV;
} hsmSymCipherScheme_t;

/** @brief  No scheme (or parameters) are defined. */
typedef uint32_t hsmNoScheme_t;

/** @brief RSA key generate scheme.
 *  @details It generates a RSA key pair.
 *           Note that the public modulus can be exported to HOST via this service or using the export key service. */
typedef struct
{
    /** @brief   INPUT: The length of public exponent "e". Should not be more than 16 bytes */
    uint32_t             publicExponentLength;
    /** @brief   INPUT: The public exponent "e". */
    HOST_ADDR            pPublicExponent;
    /** @brief   OUTPUT: The  public modulus n. It can be NULL (the modulus is not provided using this service).
     *                   The size of this memory area must be at least the byte length of the public modulus. */
    HOST_ADDR            pModulus;
} hsmKeyGenRsaScheme_t;

/** @brief   ECC Key Generate scheme.
 *  @details It generates a ECC key pair.
 *           @note
 *           - the curve ID is specified by the keyInfo.specific.eccCurveId parameter.
 *           - Note that the public key can be exported to HOST via this service or using the export key service.*/
typedef struct
{
    /** @brief   OUTPUT: Where to store the public key. If the public key is not needed at this point, pass a NULL pointer. <br>
     *                   The x and y coordinate of the public key will be passed concatenated one after another, as big-endian
     *                   strings. The size of the buffer must be double the byte length of the prime n. */
    HOST_ADDR            pPubKey;
} hsmKeyGenEccScheme_t;

/** @brief   SM2 Key Generate scheme.
 *  @details It generates a SM2 key pair. */
typedef struct
{
    /** @brief   OUTPUT: Where to store the public key. If the public key is not needed at this point, pass a NULL pointer. <br>
     *                   The x and y coordinate of the public key will be passed concatenated one after another, as big-endian
     *                   strings. The size of the buffer must be double the byte length of the prime n. */
    HOST_ADDR            pPubKey;
} hsmKeyGenSm2Scheme_t;

/**@brief    JTAG Password Generate scheme */
typedef struct
{
	uint32_t			 derivativeLen;

	/** @brief 	 INPUT: fix length 32 byte derivateive */
	HOST_ADDR			 derivative;

	/** @brief 	 OUTPUT: fix length 32 byte passwd */
	HOST_ADDR            pPasswd;
} hsmKeyGenJtagPasswdScheme_t;

typedef struct
{
    /** @brief   INPUT: The Hash algorithm for RSA OAEP padding. */
    hsmHashAlgo_t   hashAlgo;
    uint8_t         reserved[3];
    /** @brief   INPUT: Optional OAEP label length (it can be 0). Must be less than 128. */
    uint32_t        labelLength;
    /** @brief   INPUT: Optional OAEP label (it can be NULL if label length is 0). Must be less than 128 bytes long. */
    HOST_ADDR       pLabel;
} hsmRsaOAEPScheme_t;

typedef struct
{
    /** @brief   INPUT: The Hash algorithm for RSA PKCS1V15 padding. */
    hsmHashAlgo_t   hashAlgo;
    uint8_t         reserved[3];
} hsmRsaPkcs1v15Scheme_t;

/**
* @brief          RSA cipher scheme.
* @details        Performs the RSA encryption/decryption).
*/
typedef struct
{
    /** @brief   INPUT: RSA algorithm. */
    hsmRsaAlgo_t             rsaAlgo;
    uint8_t                  reserved[3];
    /** @brief   INPUT: Scheme for selected RSA algorithm. */
    union
    {
        hsmRsaOAEPScheme_t      rsaOeap;
        hsmNoScheme_t           rsaPkcs1v15;
    }sch;
} hsmRsaCipherScheme_t;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
typedef struct
{
    hsmSm2Algo_t    sm2Algo;

    /** @brief   INPUT: RSA or SM2 algorithm. */
    uint32_t reversed[3];
} hsmSm2CipherScheme_t;
#endif
/** @brief HSE Cipher scheme.
 *  @details Includes parameters needed for symmetric cipher/RSA encryption and decryption.
 */
typedef union
{
    /** @brief   INPUT: Symmetric cipher scheme. */
    hsmSymCipherScheme_t      symCipher;
    /** @brief   INPUT: RSA cipher scheme. */
    hsmRsaCipherScheme_t      rsaCipher;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
    /** @brief   INPUT: SM2 cipher scheme. */
    hsmSm2CipherScheme_t      sm2Cipher;
#endif
} hsmCipherScheme_t;

/** @brief ECDSA signature scheme.
 *  @details  Includes parameters needed for ECDSA signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: The hash algorithm used to hash the input before applying the ECDSA operation.
     *           Must not be #HSE_HASH_ALGO_NULL. */
    hsmHashAlgo_t   hashAlgo;

    uint8_t         reserved[3];
} hsmEcdsaScheme_t;

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
/** @brief Ed25519 signature scheme.
 *  @details  Includes parameters needed for Ed25519 signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: The hash algorithm used to hash the input before applying the Ed25519 operation.
     *           Must not be #HSE_HASH_ALGO_NULL. */
    hsmHashAlgo_t   hashAlgo;

    uint8_t         reserved[3];
} hsmEd25519Scheme_t;
#endif

/** @brief RSASSA_PSS signature scheme.
 *  @details  Includes parameters needed for RSASSA_PSS signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: The hash algorithm used to hash the input before applying the RSA operation.
     *           Must not be #HSE_HASH_ALGO_NULL. */
    hsmHashAlgo_t   hashAlgo;

    uint8_t         reserved[3];

    /** @brief   INPUT: The length of the salt in bytes. It must fulfill one of the following conditions:
     *                    - 0 <= saltLength <= 62 if the key length is 128 bytes and SHA-512 is used as hash algorithm;
     *                    - 0 <= saltLength <= hashLength otherwise, where hashLength denotes the output length of the chosen hash algorithm.

     */
    uint32_t        saltLength;
} hsmRsaPssSignScheme_t;


/** @brief The HSE signature scheme.
 *  @details  Includes parameters needed for signature generate/verify. */
typedef struct
{
    /** @brief   INPUT: Signature scheme.*/
    hsmSignSchemeEnum_t        signSch;
    uint8_t                    reserved[3];
    /** @brief   INPUT: Additional information for selected Signature scheme. */
    union
    {
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
        /** @brief   INPUT: SM2 signature scheme. */
    	hsmNoScheme_t   	   sm2;
#endif
        /** @brief   INPUT: ECDSA signature scheme. */
        hsmEcdsaScheme_t       ecdsa;
        /** @brief   INPUT: RSA PSS signature scheme. */
        hsmRsaPssSignScheme_t  rsaPss;
        /** @brief   INPUT: RSASSA_PKCS1_V15 signature scheme. */
        hsmRsaPkcs1v15Scheme_t rsaPkcs1v15;
#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
        /** @brief   INPUT: Ed25519 signature scheme. */
        hsmEd25519Scheme_t    ed25519;
#endif
    }sch;
} hsmSignScheme_t;

typedef struct
{
    /** @brief   INPUT: Specifies the slot where to add or updated a key.
     *                  Note that the keyHandle identifies the key catalog, key group index and key slot index */
    hsmKeyHandle_t      targetKeyHandle;
    /** @brief   INPUT: Specifies usage flags, restriction access, key length in bits, etc for the key (see hseKeyInfo_t).
     *                  @note
     *                        - Only keys that are not write protected can be updated with this service.
     *                        - NVM keys are secured against replay attacks by including a counter value stored within HSE.
     *                          The anti-replay attack counter included in the key info header should be greater than
     *                          the counter of the HSE key that will be updated (in case of key update).
     *                          This mean that keyInfo MUST be included in the signed key container (when the Life Cycle is IN_FIELD).
     *                        - For RAM keys the key counter is ignored (keyInfo may not be in the key container). */
    HOST_ADDR           pKeyInfo;
    /** @brief   INPUT: Pointer to key values.
     *           A asymmetric private key should always be imported together with the public key.
     *           - pKey[0]:
     *              - RSA public modulus n (big-endian).
     *              - ECC depends on the key format
     *                  - Weierstrass curve keys:
     *                      - raw format: X || Y, in big endian; keyLen[0] must be 2 * #HSE_BYTES_TO_BITS(keyBitLength)
     *                      - uncompressed format: 0x04 || X || Y, in big endian; keyLen[0] must be 1 + 2 * #HSE_BYTES_TO_BITS(keyBitLength)
     *                      - compressed format: 0x02 / x03 || X,  in big endian; keyLen[0] must be 1 + #HSE_BYTES_TO_BITS(keyBitLength)
     *                  - Twisted Edwards curve keys:
     *                      - raw format: point Y with the sign bit of X, in big endian; keyLen[0] must be #HSE_BYTES_TO_BITS(keyBitLength)
     *                  - Montgomery curve keys:
     *                      - raw format: the X coordinate, in big endian; keyLen[0] must be #HSE_BYTES_TO_BITS(keyBitLength)
     *              - Classic DH prime modulus p
     *           - pKey[1]:
     *              - RSA public exponent e (big-endian).
     *              - Classic DH public key
     *           - pKey[2]:
     *              - RSA private exponent d (big-endian).
     *              - ECC/ED25519 private scalar (big-endian).
     *              - The symmetric key (e.g AES, HMAC).
     *              - Classic DH private key
     */
    HOST_ADDR       pKey[3];
    /** @brief   INPUT: The length in bytes for the above key values in the same order. <br>
     *                  Note that keyInfo.keyBitLen specifies the key length in bits.*/
    uint16_t        keyLen[3];
    uint8_t         reserved[2];
    /** @brief   INPUT: Cipher parameters are used only if the cipherKeyHandle is not #HSE_INVALID_KEY_HANDLE.
     *                  @note
     *                  - For AES-block cipher, if the keyBitLen is not multiple of AES block size (128bits), the key value have to be padded with zeros.
     *                  - For RSAES NO PADDING, the keyBitLen of the imported key must be less than or equal to #HSE_BITS_TO_BYTES(cipherKey_keyBitLen), and the key is considered a big-endian integer.
     *                  - For RSAES-PKCS1-v1_5, the keyBitLen of the imported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) -11 bytes.
     *                  - For RSAES-OAEP, the keyBitLen of the imported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) - 2 * hashLen - 2 bytes.
    */
    struct
    {
        /** @brief   INPUT: Decryption key handle.
         *                  The cipherKeyHandle can only be a provisioning key (#HSE_KF_USAGE_KEY_PROVISION and #HSE_KF_USAGE_DECRYPT flags are set). <br>
         *                  Note that the key handle identifies the cipher scheme below.
         *                  In case of symmetric cipher scheme and authenticated encryption scheme(AEAD) the differentiation is made using the first byte of cipherScheme.
         *                  Must be set to #HSE_INVALID_KEY_HANDLE if not used. */
        hsmKeyHandle_t    cipherKeyHandle;
        /** @brief Symmetric, asymmetric  and AEAD cipher scheme.
                   @note
                   - Only the private keys are encrypted. */
        hsmCipherScheme_t cipherScheme;
    }cipher;
} hsmImportKeySrv_t;

typedef struct
{
    /** @brief   INPUT: The key handle to be exported.  <br>
     *                  Note that the keyHandle identifies the key catalog, key group index and key slot index */
    hsmKeyHandle_t      targetKeyHandle;
    /** @brief   OUTPUT: Export the key information (see hseKeyInfo_t).
     *                   @note
     *                   - For symmetric keys exported in an authenticated key container, key information MUST be part of the key container;
     *                   - For symmetric keys exported authenticated with AEAD, key information MUST be part of AAD (see hseAeadScheme_t);
     *                   - For public keys this parameter is optional. It can be NULL. */
    HOST_ADDR           pKeyInfo;
    /** @brief   OUTPUT: Addresses where to fill to key values.
     *           - pKey[0]:
     *              - RSA public modulus n.
     *              - ECC depends on the key format
     *                  - Weierstrass curve keys:
     *                      - raw format: X || Y, in big endian; the HSE will output 2 * #HSE_BYTES_TO_BITS(keyBitLength) bytes
     *                      - uncompressed format: 0x04 || X || Y, in big endian; the HSE will output 1 + 2 * #HSE_BYTES_TO_BITS(keyBitLength) bytes
     *                      - compressed format: 0x02 / x03 || X,  in big endian; the HSE will output 1 + #HSE_BYTES_TO_BITS(keyBitLength) bytes
     *                  - Twisted Edwards curve keys:
     *                      - raw format: point Y with the sign bit of X, in big endian; the HSE will output #HSE_BYTES_TO_BITS(keyBitLength) bytes
     *                  - Montgomery curve keys:
     *                      - raw format: the X coordinate, in big endian; the HSE will output #HSE_BYTES_TO_BITS(keyBitLength) bytes
     *              - Classic DH prime modulus p
     *           - pKey[1]:
     *              - RSA public exponent e.
     *              - Classic DH public key
     *           - pKey[2]:
     *              - The symmetric key (e.g AES, HMAC).
     *              - Classic DH private key
     */
    HOST_ADDR          pKey[3];
    /** @brief   INPUT/OUTPUT: Addressed of uint16_t values of the length (in bytes) for the above buffers (INPUT).
     *                         As output, it provides the lengths of the encrypted or unencrypted (only for public) keys. <br>
     *                         Note that the length in bits of the key is specified by hseKeyInfo_t.
     */
    HOST_ADDR          pKeyLen[3];

    /** @brief   INPUT: Cipher parameters.
     *                  @note
     *                  - Only the private keys are encrypted and the encrypted value length is specified by the corresponding private key length (in bytes).
     *                  - For AES-block cipher, if the keyBitLen of the exported is not multiple of AES block size (128bits), the key value will be padded with zeros.
     *                  - For RSAES NO PADDING, the keyBitLen of the exported key must be less than or equal to #HSE_BITS_TO_BYTES(cipherKey_keyBitLen), and the key is considered a big-endian integer.
     *                  - For RSAES-PKCS1-v1_5, the keyBitLen of the exported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) -11 bytes.
     *                  - For RSAES-OAEP, the keyBitLen of the exported key shall not be greater than #HSE_BITS_TO_BYTES(cipherKey_keyBitLen) - 2 * hashLen - 2 bytes.
     * */
    struct
    {
        /** @brief   INPUT: Encryption key handle.
         *                  The cipherKeyHandle can only be a provisioning key (#HSE_KF_USAGE_KEY_PROVISION and #HSE_KF_USAGE_ENCRYPT flags are set). <br>
         *                  Note that the key handle will identifies the cipher scheme below.
         *                  Must be set to #HSE_INVALID_KEY_HANDLE if not used. */
        hsmKeyHandle_t    cipherKeyHandle;
        /** @brief Symmetric, asymmetric  and AEAD cipher scheme.
                   @note
                   - Only the private keys are encrypted.*/
        hsmCipherScheme_t cipherScheme;
    }cipher;
} hsmExportKeySrv_t;

typedef struct
{
    /** @brief   INPUT: The key handle. */
    hsmKeyHandle_t   keyHandle;
    /** @brief   OUTPUT: Address where to store hseKeyInfo_t (Specifies usage flags, restriction access, key bit length etc ). */
    HOST_ADDR        pKeyInfo;
} hsmGetKeyInfoSrv_t;

typedef struct
{
    /** @brief   INPUT: The key handle. */
    hsmKeyHandle_t   keyHandle;
    /** @brief   OUTPUT: The address of the output buffer where the resulting hash will be stored. */
    HOST_ADDR          pHash;
} hseGetKeyHash_t;

typedef struct
{
    /** @brief   INPUT: The key handle. */
    hsmKeyHandle_t        keyHandle;
    /** @brief   INPUT: The Erase key options */
    hsmEraseKeyOptions_t  eraseKeyOptions;
    uint8_t               reserved[3];
} hsmEraseKeySrv_t;

typedef struct
{
    /** @brief   INPUT: The target key handle (where to store the new key). */
    hsmKeyHandle_t      targetKeyHandle;
    /** @brief   INPUT:  Specifies usage flags, restriction access, key bit length etc for the key.
     *                   @note
     *                   - For random symmetric key, the key length in bits should be specified by keyBitLen.
     *                   - For RSA, keyBitLen specifies the bit length of the public modulus which shall be generated.
     *                   - For ECC, the keyInfo should specify the ECC curve ID and the length of the base point order.
     **/
    hsmKeyInfo_t        keyInfo;
    /** @brief   INPUT: Specifies the key generation type (e.g random sym key, rsa key pair, ecc key pair */
    hsmKeyGenScheme_t   keyGenScheme;
    uint8_t             reserved[3];
    /** @brief   INPUT: The selected scheme parameters. */
    union
    {
        /** @brief   INPUT: No scheme (parameter) is used for random symmetric key. */
        hsmNoScheme_t               symKey;
        /** @brief   INPUT: The scheme used to generate a RSA key pair. */
        hsmKeyGenRsaScheme_t        rsaKey;
        /** @brief   INPUT: The scheme used to generate a ECC key pair. */
        hsmKeyGenEccScheme_t	    eccKey;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
        /** @brief   INPUT: The scheme used to generate a SM2 key pair. */
        hsmKeyGenEccScheme_t	    sm2Key;
#endif
        /** @brief   INPUT: The scheme used to generate a Jtag key. */
        hsmKeyGenJtagPasswdScheme_t jtagKey;
    }sch;
} hsmKeyGenerateSrv_t;

/* @brief HASH service. */
typedef struct
{
    hsmOperationMode_t optMode;

    /** @brief   INPUT: Specifies the hash algorithm */
    hsmHashAlgo_t      hashAlgo;

    uint8_t            reversed[2];

    /** @brief   INPUT: Length of the input message. Can be any value(except zero). */
    uint32_t           inputLength;

    /** @brief   INPUT: Address of the input message. */
    HOST_ADDR          pInput;

    HOST_ADDR          pHashLength;

    /** @brief   OUTPUT: The address of the output buffer where the resulting hash will be stored. */
    HOST_ADDR          pHash;
} hsmHashSrv_t;

/** @brief CMAC scheme.
 *  @details  Includes parameters needed for CMAC tag generation/verification. */
typedef struct
{
    /** @brief   INPUT: Select a cipher algorithm for CMAC. */
    hsmCipherAlgo_t    cipherAlgo;
    uint8_t            reserved[3];
} hsmCmacScheme_t;


/** @brief HMAC scheme.
 *  @details  Includes parameters needed for HMAC tag generation/verification. */
typedef struct
{
    /** @brief   INPUT: Specifies the hash algorithm for HMAC. SHA3 and Miyaguchi-Preneel are not supported for HMAC */
    hsmHashAlgo_t      hashAlgo;
    uint8_t            reserved[3];
} hsmHmacScheme_t;

/** @brief GMAC scheme (AES only).
 *  @details  Includes parameters needed for GMAC tag generation/verification. */
typedef struct
{
    /** @brief   INPUT: Initialization Vector length. Zero is not allowed. */
    uint32_t           ivLength;

    /** @brief   INPUT: Initialization Vector/Nonce. */
    HOST_ADDR          pIV;
} hsmGmacScheme_t;

/** @brief HSE MAC scheme.
 *  @details Includes parameters needed for MAC computation.
 */
typedef struct
{
    /** @brief   INPUT: Select an MAC algorithm. */
    hsmMacAlgo_t      macAlgo;
    uint8_t           reserved[3];
    /** @brief   INPUT: The scheme (or parameters) for the selected mac algorithm. */
    union
    {
        /** @brief   INPUT: CMAC scheme (AES). */
        hsmCmacScheme_t        cmac;
        /** @brief   INPUT: HMAC scheme. */
        hsmHmacScheme_t        hmac;
        /** @brief   INPUT: GMAC scheme. Supports only AES. */
        hsmGmacScheme_t        gmac;
    }sch;
} hsmMacScheme_t;

typedef struct
{
    hsmOperationMode_t optMode;

    /** @brief   INPUT: Specifies the direction: generate/verify. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmAuthDir_t    authDir;

    uint8_t         resversed[2];

    /** @brief   INPUT: Specifies the MAC scheme. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmMacScheme_t  macScheme;

    /** @brief   INPUT: The key to be used for the operation.
     *           STREAMING USAGE: Used in START.*/
    hsmKeyHandle_t  keyHandle;

    /** @brief   INPUT: Length of the input message. Can be zero. <br>
     *           STREAMING USAGE: Used in all steps.
     *            - START: Must be a multiple of block length (for HMAC-hash or AES), or zero. Cannot be zero for HMAC.
     *            - UPDATE: Must be a multiple of block length (for HMAC-hash or AES). Cannot be zero.
     *                  Refrain from issuing the service request, instead of passing zero.
     *            - FINISH: Can be any value (For CMAC & XCBC-MAC, zero length is invalid).
     *
     *           Algorithm block lengths (for STREAMING USAGE):
     *            - CMAC, GMAC, XCBC-MAC: 16
     *            - HMAC, depends on underlying hash:
     *                - SHA1, SHA2_224, SHA2_256: 64
     *                - SHA2_512_224, SHA2_512_256, SHA2_384, SHA2_512: 128
     *                - SHA3: not supported for HMAC
     *                - Miyaguchi-Preneel: not supported for HMAC */
    uint32_t        inputLength;

    /** @brief   INPUT: The input message.
     *           @note The input message for GMAC is the AAD (as specified by AEAD-GCM).
     *
     *           STREAMING USAGE: Used in all steps, but ignored when #inputLength is zero */
    HOST_ADDR       pInput;

    /** @brief   INPUT/OUTPUT: Holds the address to a memory location (an uint32_t variable) in which the tag length in bytes is stored.
     *                         - GENERATE:
     *                           - On calling service (input), this parameter shall contain the size of the buffer provided by #pTag.
     *                           - For GMAC, valid tag lengths are 8, 12, 13, 14, 15 and 16. Tag-lengths greater than 16 will be truncated to 16.
     *                           - For HMAC, valid tag lengths are [8, hash-length]. Tag-lengths greater than hash-length will be truncated to hash-length.
     *                           - For CMAC & XCBC-MAC, valid tag lengths are [8, cipher-block-length]. Tag-lengths greater than cipher-block-length will be
     *                             truncated to cipher-block-length.
     *                           - When the request has finished (output), the actual length of the returned value shall be stored.
     *                         - VERIFY:
     *                           - On calling service (input), this parameter shall contain the tag-length to be verified.
     *                           - For GMAC, valid tag lengths are 8, 12, 13, 14, 15 and 16.
     *                           - For HMAC, valid tag lengths are [8, hash-length].
     *                           - For CMAC & XCBC-MAC, valid tag lengths are [8, cipher block-length].
     *
     *           STREAMING USAGE: Used in FINISH. */
    HOST_ADDR     pTagLength;

    /** @brief   OUTPUT/INPUT: The output tag for "generate"; the input tag for "verify". <br>
     *           STREAMING USAGE: Used in FINISH.*/
    HOST_ADDR     pTag;
    HOST_ADDR	  pVerifyResult;
} hsmMacSrv_t;

typedef struct
{
    /** @brief   INPUT: Specifies the access mode: ONE-PASS, START, UPDATE, FINISH. <br>
     *           STREAMING USAGE: Used in all steps.*/
    hsmOperationMode_t optMode;

    /** @brief   INPUT: Specifies the cipher algorithm . <br>
     *           STREAMING USAGE: Used in START.*/
    hsmCipherAlgo_t  cipherAlgo;

    /** @brief   INPUT: Specifies the cipher mode. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmCipherBlockMode_t  cipherBlockMode;

    hsmCipherStreambits_t   cipherStramBits;

    /** @brief   INPUT: Specifies the cipher direction: encryption/decryption. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmCipherDir_t   cipherDir;

    uint8_t         reversed[3];

    /** @brief   INPUT: The key to be used for the operation. <br>
     *           STREAMING USAGE: Used in START step. */
    hsmKeyHandle_t   keyHandle;

    /** @brief   INPUT: Initialization Vector/Nonce. Ignored for NULL & ECB cipher block modes. <br>
     *                  IV length is 16 bytes. (AES cipher block size). <br>
     *           STREAMING USAGE: Used in START.*/
    HOST_ADDR        pIV;

    /** @brief   INPUT: The plaintext and ciphertext length. For ECB, CBC & CFB cipher block modes*/
    uint32_t         inputLength;

    /** @brief   INPUT: The plaintext for encryption or the ciphertext for decryption. <br>
     *           STREAMING USAGE: Used in START, UPDATE and FINISH. Ignored in START if #inputLength is zero. */
    HOST_ADDR        pInput;

    /** @brief   OUTPUT: The plaintext for decryption or ciphertext for encryption. <br>
     *           STREAMING USAGE: Used in START, UPDATE and FINISH. Ignored in START if #inputLength is zero. */
    HOST_ADDR        pOutput;
} hsmSymCipherSrv_t;

typedef struct
{
    /** @brief   INPUT: Specifies the option mode: ONE-PASS, START, UPDATE, FINISH. <br>
     *           STREAMING USAGE: Used in all steps. */
	hsmOperationMode_t     optMode;

    /** @brief   INPUT: Specifies the authenticated cipher mode. <br>
     *           STREAMING USAGE: Used in all steps. */
    hsmAuthCipherMode_t authCipherMode;

    /** @brief   INPUT: Specifies the cipher direction: encryption/decryption. <br>
     *           STREAMING USAGE: Used in all steps. */
    hsmCipherDir_t      cipherDir;

    uint8_t 		    reversed;

    /** @brief   INPUT: The key to be used for the operation. <br>
     *           STREAMING USAGE: Used in START step. */
    hsmKeyHandle_t      keyHandle;

    /** @brief   INPUT: The length of the IV/Nonce (in bytes).
     *                  - CCM valid IV sizes 7, 8, 9, 10, 11, 12, 13 bytes
     *                  - GCM: 1<= ivLength <= 2^32-1. Recommended 12 bytes or greater.
     *
     *           STREAMING USAGE: Used in START. */
    uint32_t            ivLength;

    /** @brief   INPUT: Initialization Vector/Nonce. <br>
     *           STREAMING USAGE: Used in START. */
    HOST_ADDR           pIV;

    /** @brief   INPUT: The length of AAD Header data (in bytes). Can be zero.
     *                  - CCM: Restricted to lengths less than or equal to (2^16 - 2^8) bytes.
     *
     *           STREAMING USAGE: Used in START. Any AAD is ignored in UPDATE or FINISH, and must be passed to the HSE in START. */
    uint32_t            aadLength;

    /** @brief   INPUT: The AAD Header data. Ignored if aadLength is zero. <br>
     *           STREAMING USAGE: Used in START. Any AAD is ignored in UPDATE or FINISH, and must be passed to the HSE in START. */
    HOST_ADDR           pAad;

    /** @brief   INPUT: The length of the plaintext and ciphertext (in bytes).
     *                  Can be zero (compute/verify the tag without input message). <br>
     *           STREAMING USAGE:
     *            - START:  The input length is ignored.
     *            - UPDATE: Must be a multiple of block length. Cannot be zero. Refrain from issuing the service request
     *                      instead of passing zero.
     *            - FINISH: All lengths are allowed. */
    uint32_t            inputLength;

    /** @brief   INPUT: The plaintext for "authenticated encryption" or
     *                  the ciphertext for "authenticated decryption". <br>
     *           STREAMING USAGE: Used in UPDATE and FINISH step. Ignored for START step or if inputLength is zero. */
    HOST_ADDR           pInput;

    /** @brief   INPUT: The length of tag (in bytes).
     *                  - CCM valid Tag sizes 4, 6, 8, 10, 12, 14, 16 bytes
     *                  - GCM valid Tag sizes 4, 8, 12, 13, 14, 15, 16 bytes
     *           STREAMING USAGE: Used in FINISH step. */
    uint32_t            tagLength;

    /** @brief   OUTPUT/INPUT: The output tag for "authenticated encryption" or
     *                         the input tag for "authenticated decryption". <br>
     *           STREAMING USAGE: Used in FINISH step. */
    HOST_ADDR           pTag;

    /** @brief   OUTPUT: The ciphertext for "authenticated encryption" or
     *                   the plaintext for "authenticated decryption". <br>
     *           STREAMING USAGE: Used in UPDATE and FINISH step. */
    HOST_ADDR           pOutput;
} hsmAeadSrv_t;

typedef struct
{
    /** @brief   INPUT: Specifies the access mode: ONE-PASS, START, UPDATE, FINISH. <br>
     *           STREAMING USAGE: Used in all steps.*/
	hsmOperationMode_t     optMode;


    /** @brief   INPUT: Specifies the direction: generate/verify. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmAuthDir_t    authDir;

    /** @brief   INPUT: Specifies that the input is already hashed with the algorithm in specified in the sign scheme.
     *                  Not valid for any signing scheme that does not perform prehashing (i.e. PureEDDSA)
     *           @note The hashing algorithm must still be provided as it is included in the signature for various schemes (e.g. RSA)
     *           STREAMING USAGE: Not supported in streaming mode.*/
    boolean         bInputIsHashed;

    uint8_t			reversed;

    /** @brief   INPUT: Scheme for selected Signature algo. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmSignScheme_t signScheme;

    /** @brief   INPUT: The key to be used for the operation. <br>
     *           STREAMING USAGE: Used in START.*/
    hsmKeyHandle_t  keyHandle;

    /** @brief   INPUT: The length of the message.
     *                  For RSA schemes, this must be the length of the original (not pre-hashed) input. <br>
     *           STREAMING USAGE: Used in all steps.
     *            - START: Must be a multiple of block length of the hash, or zero.
     *            - UPDATE: Must be a multiple of block length of the hash. Cannot be zero. Refrain from issuing the service request, instead of passing zero.
     *            - FINISH: Can be any value.
     *
     *           Algorithm block lengths:
     *            - SHA1, SHA2_224, SHA2_256: 64
     *            - SHA2_512_224, SHA2_512_256, SHA2_384, SHA2_512: 128
     *            - SHA3-224: 144
     *            - SHA3-256: 136
     *            - SHA3-384: 104
     *            - SHA3-512: 72
     *            - SHA3: If the targeted platform does NOT have #HSE_SPT_HW_SHA3 defined, there is no limitation (input can be any size)
     *           @note EDDSA does not support streaming */
    uint32_t        inputLength;

    /** @brief   INPUT: The address of the message to be signed/verify.
     *                  For RSA schemes, this is the actual (not pre-hashed) input. <br>
     *           STREAMING USAGE: Used in all steps.*/
    HOST_ADDR       pInput;

    /** @brief   INPUT/OUTPUT: An array of two addresses of two uint32_t values containing signature lengths. It is input/output for "generate" and input for "verify".
     *                         On calling "generate" service, these parameter shall contain the size of the signature buffers provided by the application.
                               When the request has finished, the actual lengths of the signature components. <br>
     *           STREAMING USAGE: Used in FINISH. */
    HOST_ADDR       pSignatureLength[2];

    /** @brief   OUTPUT: Where the signature components must be stored.  It is output for "generate" and input for "verify".
     *                   - RSA has a single signature component, at index 0, and the size of buffer must be at least the byteLength(public modulus n)
     *                   - ECDSA and EDDSA signature format as (r,s), with r at index 0, and s at index 1.
     *                     The buffer size for each component must be at least the length of the used curve in bytes (e.g. 32 bytes for a 256 bit curve).<br>
     *           STREAMING USAGE: Used in FINISH. */
    HOST_ADDR       pSignature[2];
    HOST_ADDR		pVerifyResault;
} hsmSignSrv_t;

typedef struct
{
    /** @brief   INPUT: The RSA cipher scheme. */
    hsmRsaCipherScheme_t    rsaScheme;
    /** @brief   INPUT: Specifies the cipher direction: encryption/decryption.*/
    hsmCipherDir_t          cipherDir;
    uint8_t                 reserved[3];
    /** @brief   INPUT: The key to be used for the operation. */
    hsmKeyHandle_t          keyHandle;
    /** @brief   INPUT: The input length (plaintext or ciphertext):
     *                 - The length of the ciphertext should be #HSE_BITS_TO_BYTES(keyBitLen) .
     *                 - The length of the plaintext (in bytes):
     *                      - For RSAES NO PADDING, the Input Length must be less than or equal to #HSE_BITS_TO_BYTES(keyBitLen), and
     *                        #pInput is considered a big-endian integer.
     *                      - For RSAES-PKCS1-v1_5, the Input Length shall not be greater than #HSE_BITS_TO_BYTES(keyBitLen) -11 bytes.
     *                      - For RSAES-OAEP, Input Length shall not be greater than #HSE_BITS_TO_BYTES(keyBitLen) - 2 * hashLen - 2 bytes. */
    uint32_t                inputLength;
    /** @brief   INPUT: The plaintext for encryption or the ciphertext for decryption. */
    HOST_ADDR               pInput;
    /** @brief   INPUT/OUTPUT: Holds the address to a location (an uint32_t variable) in which the output length in bytes is stored.  <br>
                               On calling this service, this parameter shall contain the size of the buffer
                               provided by the application.
                               When the request has finished, the actual length of the returned value shall be stored.*/
    HOST_ADDR               pOutputLength;
    /** @brief   OUTPUT: The address of the Output. The plaintext for decryption or ciphertext for encryption.
     *                   The size of output must be at least the #HSE_BITS_TO_BYTES(keyBitLen) */
    HOST_ADDR               pOutput;
} hsmRsaCipherSrv_t;

typedef struct
{
    /** @brief   INPUT: Specifies the cipher direction: encryption/decryption.*/
    hsmCipherDir_t          cipherDir;
    uint8_t                 reserved[3];
    /** @brief   INPUT: The key to be used for the operation. */
    hsmKeyHandle_t          keyHandle;
    /** @brief   INPUT: The input length (plaintext or ciphertext) */
    uint32_t                inputLength;
    /** @brief   INPUT: The plaintext for encryption or the ciphertext for decryption. */
    HOST_ADDR               pInput;
    /** @brief   INPUT/OUTPUT: Holds the address to a location (an uint32_t variable) in which the output length in bytes is stored.  <br>
                               On calling this service, this parameter shall contain the size of the buffer
                               provided by the application.
                               When the request has finished, the actual length of the returned value shall be stored.*/
    HOST_ADDR               pOutputLength;
    /** @brief   OUTPUT: The address of the Output. The plaintext for decryption or ciphertext for encryption.
     *                   The size of output must be at least the #HSE_BITS_TO_BYTES(keyBitLen) */
    HOST_ADDR               pOutput;
} hsmSm2CipherSrv_t;

/* @brief  User Data Read/Write  service. */
typedef struct
{
    /** @brief   INPUT: The offset of read/write address. */
    uint32_t        offset;

    /** @brief   INPUT: The length of read/write. */
    uint32_t        length;

    /** @brief   INPUT/OUT: The point of read/write data. */
    HOST_ADDR       pData;

    /** @brief   INPUT: the key used for encrypto the data which to be saved in flash. if keyHandle is None, then save the plain data*/
    hsmKeyHandle_t 		keyHandle;
} hsmUsrDataRWSrv_t;

/** @brief HSE authentication scheme.
 *  @details Includes parameters needed for authentication.
 */
typedef union
{
    /** @brief   INPUT: MAC scheme. */
    hsmMacScheme_t    macScheme;
} hsmAuthScheme_t;

typedef struct
{
    /** @brief   INPUT: Authorization option: Key management/NVM configuration/Both. */
    hsmDevAuthOption_t  devAuthOption;
    uint8_t             reserved[3];

    hsmKeyHandle_t      keyHandle;

    hsmAuthScheme_t     authScheme;
    /** @brief   OUTPUT: The output challenge that needs to be signed by the HOST.
     *                   In case SHE MASTER_ECU_KEY is used, the returned challenge is HSE_SYS_AUTH_CHALLENGE_LENGTH - 1 byte long and
     *                   is formed from 16 random bytes concatenated with SHE UID: (RANDOM(16 bytes) || SHE_UID(15 bytes)). <br>
     *                   Otherwise, for any other key type, the challenge size is HSE_SYS_AUTH_CHALLENGE_LENGTH bytes.*/
    HOST_ADDR           pChallenge;
} hsmDevAuthReqSrv_t;

typedef struct
{
    /** @brief   INPUT: Authorization option: Key management/NVM configuration/Both. */
    hsmDevAuthOption_t  devAuthOption;
    uint8_t             reserved[3];
} hsmDevAuthRstSrv_t;


typedef struct {
	uint32_t validFlag;
	uint32_t XOSC_Frequency_Flag;
	uint32_t XOSC_CTL_Value;
	uint32_t IRCOSC_CTL_Value;
	uint32_t PLLDIG_PLL0DV_Value;
	uint32_t PLLDIG_PLL1DV_Value;
	uint32_t PLLDIG_PLL1FM_Value;
	uint32_t PLLDIG_PLL1FD_Value;

	uint32_t MC_CGM_SC_DC0_Value;
	uint32_t MC_CGM_SC_DC1_Value;
	uint32_t MC_CGM_SC_DC2_Value;
	uint32_t MC_CGM_SC_DC3_Value;
	uint32_t MC_CGM_SC_DC4_Value;

	uint32_t MC_CGM_AC0_SC_Value;
	uint32_t MC_CGM_AC0_DC0_Value;
	uint32_t MC_CGM_AC0_DC1_Value;
	uint32_t MC_CGM_AC0_DC2_Value;
	uint32_t MC_CGM_AC0_DC3_Value;
	uint32_t MC_CGM_AC0_DC4_Value;

	uint32_t MC_CGM_AC1_SC_Value;
	uint32_t MC_CGM_AC1_DC0_Value;

	uint32_t MC_CGM_AC2_DC0_Value;
	uint32_t MC_CGM_AC2_DC1_Value;

	uint32_t MC_CGM_AC3_SC_Value;
	uint32_t MC_CGM_AC4_SC_Value;

	uint32_t MC_CGM_AC5_DC0_Value;
	uint32_t MC_CGM_AC5_DC1_Value;
	uint32_t MC_CGM_AC5_DC2_Value;
	uint32_t MC_CGM_AC5_CDC0_Value;
	uint32_t MC_CGM_AC5_CDC1_Value;
	uint32_t MC_CGM_AC5_CDC2_Value;
	uint32_t MC_CGM_AC5_CDC10_Value;
	uint32_t MC_CGM_AC5_CDC11_Value;
	uint32_t MC_CGM_AC5_CDC12_Value;
	uint32_t MC_CGM_AC5_CDC13_Value;
	uint32_t MC_CGM_AC5_CDC20_Value;
	uint32_t MC_CGM_AC5_CDC21_Value;
	uint32_t MC_CGM_AC5_CDC22_Value;
	uint32_t MC_CGM_AC5_CDC23_Value;

	uint32_t MC_CGM_AC6_SC_Value;
	uint32_t MC_CGM_AC6_DC0_Value;
	uint32_t MC_CGM_AC7_SC_Value;
	uint32_t MC_CGM_AC7_DC0_Value;
	uint32_t MC_CGM_AC8_SC_Value;
	uint32_t MC_CGM_AC8_DC0_Value;
	uint32_t MC_CGM_AC9_SC_Value;
	uint32_t MC_CGM_AC9_DC0_Value;
	uint32_t MC_CGM_AC10_SC_Value;
	uint32_t MC_CGM_AC10_DC0_Value;

	uint32_t HSM_DIV_Value;

#if (defined(CCFC3007PT))
	uint32_t MC_CGM_AC11_SC_Value;
	uint32_t MC_CGM_AC11_DC0_Value;
	uint32_t MC_CGM_AC12_SC_Value;
	uint32_t MC_CGM_AC12_DC0_Value;
	uint32_t MC_CGM_AC12_DC1_Value;
	uint32_t MC_CGM_AC12_DC2_Value;
#endif

} xoscClkCofigData_t;

typedef struct
{
    hsmSecureBootType_t 	bootType;

    hsmKeyHandle_t      	authkeyHandle;

    hsmSecureBootFailOp_t 	operationOnFail;
    HOST_ADDR				xoscConfig;
    HOST_ADDR           	pVerifySegs;
    HOST_ADDR           	pSign;
    uint32_t				signlen;

    boolean					bootZ4_2;
    boolean					bootZ7_0;
    boolean					bootZ7_1;

} hsmSecureBootConfigSrv_t;

typedef struct
{
    hsmSecureBootType_t bootType;

    hsmKeyHandle_t      authkeyHandle;

    hsmSecureBootFailOp_t 	operationOnFail;

    HOST_ADDR			xoscConfig;
    HOST_ADDR           verifySegs;
    HOST_ADDR           SwpverifySegs;
    HOST_ADDR           pSign;
    HOST_ADDR           Swpsigns;
    uint32_t			signlen;

    boolean				bootZ4_2;
    boolean				bootZ7_0;
    boolean				bootZ7_1;

} hsmSecureBootConfigSwpSrv_t;

/**
 * @brief           HSE SYS Authorization Response service.
 * @details         Provides the signature for the requested challenge (using hseSysAuthorizationReqSrv_t service).
 * @note
 *      - In case SHE MASTER_ECU key is used, the HSE will return the HSE_SRV_RSP_VERIFY_FAILED status
 *        as the equivalent of ERC_NO_DEBUGGING status as specified by the SHE spec (returned when the tag over the challenge is not correct).
 */
typedef struct
{
    /** @brief   INPUT: Byte length(s) of the authentication tag(s).
     *                   @note
     *                   - For RSA signature and CMAC only authLen[0] is used.
     *                   - Both lengths are used for (R,S) (ECC).
     *                   - The MAC tag size must be minimum 16 bytes.
     *                   - RSA signature size must be #HSE_BYTES_TO_BITS(keyBitLength) */
    uint16_t          authLen[2];
    /** @brief   INPUT: Address(es) to authentication tag.
     *                   @note
     *                   - For RSA signature and CMAC only pAuth[0] is used.
     *                   - Both pointers are used for (R,S) (ECC).
     *                   - If SHE MASTER_ECU_KEY is used, the CMAC must be computed over the challenge (31 bytes) using a derived key (as per SHE specification). */
    HOST_ADDR         pAuth[2];

    HOST_ADDR         pCalcBuf;
} hsmDevAuthRespSrv_t;

/* @brief Firmware update service */
typedef struct
{
    /** @brief  INPUT:   */
    uint32_t        fwLength;

    uint32_t        fwOffset;

    /** @brief  INPUT:   */
    HOST_ADDR       pInFwData;
} hsmFirmwareUpdateSrv_t;

/* @brief Firmware update final */
typedef struct
{
	/** @brief  INPUT:  */
	uint32_t		fwLength;

	/** @brief  INPUT:  */
	HOST_ADDR		pVerifyKey;

	/** @brief  INPUT:  */
	HOST_ADDR		pVerifyMac;
} hsmFirmwareFinalSrv_t;

/* @brief Firmware update final */
typedef struct
{
	/** @brief  INPUT:  */
	HOST_ADDR		pVerifyKeyHandle;

	/** @brief  INPUT:  */
	uint32_t		fwLength;

	/** @brief  INPUT:  */
	HOST_ADDR		pVerifyMac;

#if 1
	uint32_t		dverValid;

	HOST_ADDR		dverAddr;

	uint32_t		codeValid;

	/** @brief  INPUT:  */
	HOST_ADDR		dyCodeAddr;

	/** @brief  INPUT:  */
	HOST_ADDR		stCodeAddr;

	uint32_t		codeLength;
#endif
} hsmFirmwareFinalSrvNew_t;

typedef struct
{
	hsmKeyHandle_t	mainkey;
	HOST_ADDR   salt;
	uint32_t	saltlen;
}hsmKdfSheScheme_t;
/* @brief HSM Key Derive Service. */
typedef struct
{
	uint32_t	kdfType;
	union
	{
		hsmKdfSheScheme_t	shekdf;
	};

    /** @brief   OUTPUR: The derive key. */
    hsmKeyHandle_t   	pDeriveKey;
    HOST_ADDR           pDeriveKeyInfo;
} hsmKeyDeriveSrv_t;

/** @brief Get UID Service. */
typedef struct
{
    /** @brief   OUTPUT: The address where the uid will be stored. */
    HOST_ADDR               pUID;
} hsmGetUIDSrv_t;

/** @brief SHE load key service.
 *  @details Load a SHE key into the HSE according to the SHE memory update protocol.
 *  @note The SHE keys can be used for any supported AES operations (e.g. AES with all block modes, AEAD etc.)
 *  given the proper flags are set. */
typedef struct
{
    /** @brief   INPUT: Pointer to M1M2M3 */
    HOST_ADDR   pM1M2M3;
    /** @brief   OUTPUT: Pointer to M4 */
    HOST_ADDR   pM4;
    /** @brief   OUTPUT: Pointer to M5 */
    HOST_ADDR   pM5;
} hsmLoadKeySrv_t;

/** @brief SHE load plain key service.
 *  @details Load a SHE RAM key from plain text */
typedef struct
{
    /** @brief   INPUT: Pointer to the plain key */
    HOST_ADDR   pKey;
} hsmLoadPlainKeySrv_t;

/* @brief HSM Load User Key Service. */
typedef struct
{
    /** @brief   INPUT: The key handle. */
	uint8_t 		keyID;

    uint8_t        reversed[3];

    /** @brief   OUTPUT: The address of key info. */
    HOST_ADDR      pkeyInfo;

    /** @brief   OUTPUT: The address of key length. */
    HOST_ADDR      pKeyLength;

    /** @brief   OUTPUT: The address of key. */
    HOST_ADDR      pKey;
} hsmExportRAMKeySrv_t;

/* @brief HSM Key Derive Service. */
typedef struct
{
    /** @brief   INPUT: The input key. */
    HOST_ADDR   pKey;

    /** @brief   INPUT: The iter count. */
    uint32_t    pIterCount;

    /** @brief   INPUT: The salt param. */
    HOST_ADDR   pSalt;

    /** @brief   OUTPUR: The derive key. */
    HOST_ADDR   pDeriveKey;
} hsmSheKeyDeriveSrv_t;


typedef struct
{
    HOST_ADDR           bootType;
    HOST_ADDR           bootCore;
} hsmPreSecureBootChecksrv_t;

typedef struct
{
	hsmAuthAlgo_t		authAlgo;
	uint8_t				reserved[3];

    union
    {
        /** @brief   INPUT: CMAC scheme (AES). */
        hsmCmacScheme_t        cmac;
        /** @brief   INPUT: HMAC scheme. */
        hsmHmacScheme_t        hmac;
        /** @brief   INPUT: GMAC scheme. Supports only AES. */
        hsmGmacScheme_t        gmac;
        /** @brief   INPUT: SM2 signature scheme. */
    	hsmNoScheme_t   	   sm2;
        /** @brief   INPUT: ECDSA signature scheme. */
        hsmEcdsaScheme_t       ecdsa;
        /** @brief   INPUT: RSA PSS signature scheme. */
        hsmRsaPssSignScheme_t  rsaPss;
        /** @brief   INPUT: RSASSA_PKCS1_V15 signature scheme. */
        hsmRsaPkcs1v15Scheme_t rsaPkcs1v15;
    }sch;
} hsmSmrAuthScheme_t;

typedef struct
{
	HOST_ADDR	pAuthTag[2];
	uint32_t	authTagLen[2];
} hsmSmrAuthTag_t;

typedef struct
{
	uint32_t			smrAddr;
	uint32_t			smrSize;
	hsmKeyHandle_t 		authKeyHandle;
	hsmSmrAuthScheme_t 	authScheme;
	hsmSmrAuthTag_t		authTag;
} hsmSmrEntry_t;

typedef struct
{
	uint8_t					bootCore;
	hsmSecureBootType_t 	bootType;
	hsmSecureBootFailOp_t 	bootFailOp;
	HOST_ADDR				pXoscConfig;
	uint32_t 				smrCnt;
	HOST_ADDR				pSmrEntry;
} hsmSmrEntryInstallSrv_t;

typedef struct
{
    /** @brief   INPUT: The iter count. */
	volatile uint32_t * checkaddr;
	uint32_t	timeout;
} hsmRamWaitSrv_t;

/** @brief Service Command Type */
typedef struct
{
    hsmSrvCmd_t srvCmd;

    union
    {
        hsmSetAttrSrv_t         	setAttr;
        hsmGetAttrSrv_t         	getAttr;
        hsmGetRandomNumSrv_t    	getRandom;
        hsmDevAuthReqSrv_t     	 	devAuthReq;
        hsmDevAuthRespSrv_t     	devAuthResp;
        hsmDevAuthRstSrv_t			devAuthRst;
        hsmSecureBootConfigSrv_t	configSecureBoot;
        hsmSecureBootConfigSwpSrv_t    configSecureBootSWP;
        hsmSmrEntryInstallSrv_t		installlSmrEntry;
        hsmGetKeyInfoSrv_t      	getKeyInfo;
        hsmKeyGenerateSrv_t			keyGen;
        hsmImportKeySrv_t       	importKey;
        hsmExportKeySrv_t       	exportKey;
        hsmEraseKeySrv_t        	eraseKey;
        hseGetKeyHash_t             getKeyHash;
        hsmHashSrv_t            	hash;
        hsmMacSrv_t             	mac;
        hsmAeadSrv_t				aead;
        hsmSignSrv_t				sign;
        hsmSymCipherSrv_t       	symCipher;
        hsmRsaCipherSrv_t       	rsaCipher;
#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
        hsmSm2CipherSrv_t       	sm2Cipher;
#endif
        hsmUsrDataRWSrv_t			userDataRW;
        hsmFirmwareUpdateSrv_t		fwUpdate;
        hsmFirmwareFinalSrv_t		fwFinal;
        hsmFirmwareFinalSrvNew_t	fwFinalNew;

        hsmKeyDeriveSrv_t			keyDerive;

		hsmGetUIDSrv_t				getUID;
		hsmLoadKeySrv_t				sheloadKey;
		hsmLoadPlainKeySrv_t		sheloadPlainKey;
		hsmExportRAMKeySrv_t		sheExportKey;
		hsmSheKeyDeriveSrv_t		sheDeriveKey;

		hsmPreSecureBootChecksrv_t	PreBootCheck;
	    hsmRamWaitSrv_t				ramWait;
    } srvReq;
} hsmSrvDescriptor_t;

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Init(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) HSM_LLD_ConfigInterrupt
(
	VAR(boolean, AUTOMATIC) enable
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetClkDiv
(
	VAR(uint32, AUTOMATIC) divider
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetAttr_Async
(
		VAR(uint16, AUTOMATIC) attrid,
		VAR(uint8, AUTOMATIC) attrval,
		VAR(uint32, AUTOMATIC) attrlen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetAttr
(
		VAR(uint16, AUTOMATIC) attrid,
		VAR(uint8, AUTOMATIC) attrval,
		VAR(uint32, AUTOMATIC) attrlen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVer,
	VAR(uint32, AUTOMATIC) verLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetParam
(
	P2VAR(volatile uint8, AUTOMATIC, CRYPTO_APPL_DATA) pParam,
	VAR(uint32, AUTOMATIC) ParamOffset
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetCounter
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCounter,
	VAR(uint32, AUTOMATIC) counterLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetStack
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVer,
	VAR(uint32, AUTOMATIC) verLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetAttr
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVal,
	VAR(uint32, AUTOMATIC) Len,
	VAR(hsmAttrId_t, AUTOMATIC) AttrID
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetDataVersion
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pVer,
	VAR(uint32, AUTOMATIC) verLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetBootType
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pType,
	VAR(uint32, AUTOMATIC) typeLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetSmrEntry
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry,
	VAR(uint32, AUTOMATIC) SmrEntryLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_DevAuthReq
(
	VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmAuthScheme_t, AUTOMATIC, CRYPTO_APPL_DATA) pAuthScheme,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pChallenge
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_DevAuthResp
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth0,
	VAR(uint32, AUTOMATIC) auth0Len,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAuth1,
	VAR(uint32, AUTOMATIC) auth1Len
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_DevAuthRst
(
	VAR(hsmDevAuthOption_t, AUTOMATIC) devAuthOption
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ConfigSecureBoot
(
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmKeyHandle_t, AUTOMATIC) authKeyHandle,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pCodeSegs,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSign,
	VAR(uint32, AUTOMATIC) segcnt,
	VAR(boolean, AUTOMATIC) bootZ4_2,
	VAR(boolean, AUTOMATIC) bootZ7_0,
	VAR(boolean, AUTOMATIC) bootZ7_1
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ConfigSecureBoot_SWP
(
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmKeyHandle_t, AUTOMATIC) authKeyHandle,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pCodeSegs,
	P2VAR(verifyCodeSegments, AUTOMATIC, CRYPTO_APPL_DATA) pSwpCodeSegs,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSign,
	P2VAR(codeSigns0, AUTOMATIC, CRYPTO_APPL_DATA) pSwpSign,
	VAR(uint32, AUTOMATIC) segcnt,
	VAR(boolean, AUTOMATIC) bootZ4_2,
	VAR(boolean, AUTOMATIC) bootZ7_0,
	VAR(boolean, AUTOMATIC) bootZ7_1
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_InstallSmrEntry
(

	VAR(uint8, AUTOMATIC) bootCore,
	VAR(hsmSecureBootType_t, AUTOMATIC) bootType,
	VAR(hsmSecureBootFailOp_t, AUTOMATIC) op,
	P2VAR(xoscClkCofigData_t, AUTOMATIC, CRYPTO_APPL_DATA) xoscConfigData,
	VAR(uint32, AUTOMATIC) smrCnt,
	P2VAR(hsmSmrEntry_t, AUTOMATIC, CRYPTO_APPL_DATA) pSmrEntry
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetSecureBootStatus
(
	P2VAR(hsmSecureBootStatus_t, AUTOMATIC, CRYPTO_APPL_DATA) secureBootStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_SetIgnoreSecureBootOnce(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GenerateTrngNum
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pRandom,
	VAR(uint32, AUTOMATIC) randomLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GeneratePrngNum
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pRandom,
	VAR(uint32, AUTOMATIC) randomLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EraseKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmEraseKeyOptions_t, AUTOMATIC) eraseKeyOptions
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetKeyInfo
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetKeyHash
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKeyHash
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GenerateSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GenerateJtagPasswd
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pDerivative,
	VAR(uint32, AUTOMATIC) derivativeLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pJtagPasswd
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_GetJtagPasswd
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pJtagPasswd,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pJtagPasswdLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSymKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateExponent
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainRsaKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateExponent
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainEccKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainED25519Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainED25519Key_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportPlainSm2Key_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC)  keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey,
	VAR(uint16, AUTOMATIC) encryptedKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSymKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyByteLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey,
	VAR(uint16, AUTOMATIC) encryptedKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	VAR(uint16, AUTOMATIC) encryptedPrivateExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateExponent
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedRsaKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	VAR(uint16, AUTOMATIC) publicExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	VAR(uint16, AUTOMATIC) encryptedPrivateExponentLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateExponent
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC) encryptedPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedEccKey_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(hsmEccCurveId_t, AUTOMATIC) eccCurveId,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC) encryptedPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC)  encryptedPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ImportEncryptedSm2Key_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	VAR(hsmKeyType_t, AUTOMATIC) keyType,
	VAR(hsmKeyFlags_t, AUTOMATIC) keyFlags,
	VAR(uint16, AUTOMATIC) keyBitLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pPublicKey,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pEncryptedPrivateKey,
	VAR(uint16, AUTOMATIC)  encryptedPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pKeyByteLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pModulusLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponentLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) *pPrivateExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateExponentLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA)pPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportPlainSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedSymKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptedKeyLen,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedRsaKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pModulus,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pModulusLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicExponentLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateExponent,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateExponentLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedEccKey
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ExportEncryptedSm2Key
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmKeyHandle_t, AUTOMATIC) cipherKeyHandle,
	VAR(hsmCipherScheme_t, AUTOMATIC) cipherScheme,
	P2VAR(hsmKeyInfo_t, AUTOMATIC, CRYPTO_APPL_DATA) pKeyInfo,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pPublicKeyLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKey,
	P2VAR(uint16, AUTOMATIC, CRYPTO_APPL_DATA) pEncryptPrivateKeyLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Hash
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Hash_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacGenerate
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacGenerate_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacVerify
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pHmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pHmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_HmacVerify_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pHmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pHmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacGenerate
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacGenerate_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacVerify
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pCmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesCmacVerify_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCmac,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pCmaLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesEncrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesEncrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesDecrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesDecrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA)  pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadEncrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadDecrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadEncrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_AesAeadDecrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmAuthCipherMode_t, AUTOMATIC) authCipherMode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIv,
	VAR(uint32, AUTOMATIC) ivLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pAad,
	VAR(uint32, AUTOMATIC) aadLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(hsmKeyHandle_t, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pTag,
	VAR(uint32, AUTOMATIC) tagLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Encrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Encrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Decrypt
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm4Decrypt_Async
(
	VAR(Crypto_OperationModeType, AUTOMATIC) eOptMode,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmCipherBlockMode_t, AUTOMATIC) cipherBlockMode,
	VAR(hsmCipherStreambits_t, AUTOMATIC) cipherStreamBits,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pIV,
	VAR(uint32, AUTOMATIC) inputLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Encrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Encrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Decrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15Decrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddEncrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddDecrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddEncrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaNoPaddDecrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPEncrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPDecrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPEncrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaOAEPDecrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15GenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssGenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssVerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssGenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPssVerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	VAR(uint32, AUTOMATIC) saltLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15GenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15VerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RsaPkcs1V15VerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignature,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if (defined(RESOURCE_SUPPORT_CRYPTO_EB1) || defined(RESOURCE_SUPPORT_CRYPTO_EB4))
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Encrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Encrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Decrypt
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2Decrypt_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pOutput,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pOutputLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2GenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2GenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2VerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_Sm2VerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaGenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaGenerateSignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaVerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_EcdsaVerifySignature_Async
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#if defined(RESOURCE_SUPPORT_CRYPTO_EB4)
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ED25519VerifySignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureR,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRLen,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pVerifyStatus
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ED25519GenerateSignature
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(hsmHashAlgo_t, AUTOMATIC) hashAlgo,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pInput,
	VAR(uint32, AUTOMATIC) inputLen,
	VAR(boolean, AUTOMATIC) isInputHashed,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRs,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureRsLen,
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureS,
	P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) pSignatureSLen
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#endif

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_WriteUseData
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pData,
	VAR(uint32, AUTOMATIC) length,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_ReadUseData
(
	P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pData,
	VAR(uint32, AUTOMATIC) length,
	VAR(uint32, AUTOMATIC) offset,
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) HSM_LLD_IRQHandler
(
	VAR(uint32, AUTOMATIC) coreId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateInit(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateInit_Async(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateProcess
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateProcess_Async
(
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pFwImage,
	VAR(uint32, AUTOMATIC) fwLength,
	VAR(uint32, AUTOMATIC) fwOffset
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal	/* PRQA S 1753 */
(
	VAR(uint32, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) key,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal_New
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal2
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) dVer,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) stDycode,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) runDycode,
	VAR(uint32, AUTOMATIC) codeLength
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal_Async
(
	VAR(uint32, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) key,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_FWUpdateFinal_Async_New
(
	VAR(hsmKeyHandle_t, AUTOMATIC) keyHandle,
	VAR(uint32_t, AUTOMATIC) fwLength,
	P2CONST(uint8, AUTOMATIC, CRYPTO_APPL_DATA) mac
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_CheckServiceResponce(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_CheckServiceResponce(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RamWait_S0
(
		P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr,
		VAR(uint32_t, AUTOMATIC) ram_timeout
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RamWait_S1
(
		P2VAR(volatile uint32_t, AUTOMATIC, CRYPTO_APPL_DATA) checkaddr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(status_t, CRYPTO_CODE) HSM_LLD_RamWait_S1_Err(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif /* CRYPTO_LLDRIVER_H */

/** @} */

