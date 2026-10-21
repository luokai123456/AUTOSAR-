#ifndef SECUAUTH_INTERFACE_H
#define SECUAUTH_INTERFACE_H


#include "Std_Types.h"


typedef enum
{
    SECU_SYM_AES128_CBC,
    SECU_SYM_AES128_ECB,
    SECU_SYM_SM4_CBC,
    SECU_SYM_SM4_ECB
} Secu_SymAlgorithmType;

typedef enum
{
    SECU_ASYM_ECC256_SHA256     = 0U,   /* ECC256 + SHA256 */
    SECU_ASYM_RSA3072_SHA256    = 1U,   /* RSA3072 + SHA256 */
    SECU_ASYM_RSA4096_SHA512    = 2U,   /* RSA4096 + SHA512 */
    SECU_ASYM_SM2_SM3           = 3U,   /* SM2 + SM3 */
    SECU_ASYM_ED25519_SHA256    = 4U,   /* ED25519 + SHA256 */
    SECU_ASYM_ECDSA384_SHA512   = 5U    /* ECDSA384 + SHA512 */
} Secu_AsymAlgorithmType;

typedef enum
{
    SECU_DIR_ENCRYPT = 0U,
    SECU_DIR_DECRYPT = 1U,
    SECU_DIR_SIGN    = 2U,
    SECU_DIR_VERIFY  = 3U
} Secu_DirectionType;

typedef enum
{
    SECU_OPERATIONMODE_START = 0x01U,
    SECU_OPERATIONMODE_UPDATE = 0x02U,
    SECU_OPERATIONMODE_FINISH = 0x04U,
    SECU_OPERATIONMODE_SINGLECALL = 0x07U
} Secu_OperationModeType;

typedef enum
{
    SECU_E_VER_OK = 0x00U,
    SECU_E_VER_NOT_OK = 0x01U
} Secu_VerifyResultType;

typedef enum
{
    SECU_ALGOFAM_SHA2_256 = 0x03U,
    SECU_ALGOFAM_SHA2_512 = 0x05U,
    SECU_ALGOFAM_SM3 = 0x29U,
} Secu_AlgorithmFamilyType;

typedef enum
{
    SECU_KE_CIPHER_KEY = 1U, /* 对称/非对称密钥 */
    SECU_KE_CIPHER_IV  = 5U, /* IV */
} Secu_KeyElementIdType;


typedef struct
{
	uint8*                          pKey[3];
	uint16                          u16KeyLength[3];
} Secu_AsymKeyImportType;


/**
 * @brief 导入密钥
 * 
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] keyElementId 密钥类型
 * @param[in] keyPtr 密钥内容
 * @param[in] keyLength 密钥长度
 * @return Std_ReturnType 
 */
extern Std_ReturnType Secu_KeyElementSet
(
    uint32 cryptoKeyId,
    Secu_KeyElementIdType keyElementId,
    const uint8 *keyPtr,
    uint32 keyLength
);


/**
 * @brief AES-CMAC生成
 *
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] eOptMode 操作模式
 * @param[in] pInput 输入数据指针
 * @param[in] inputLen 输入数据长度
 * @param[out] pOutput 输出CMAC结果缓冲区
 * @param[in,out] pOutputLen 输入时指向输出缓冲区大小，输出时指向实际CMAC长度
 * @return Std_ReturnType
 */
extern Std_ReturnType SecuAuth_Calculate_AesCmacGenerate
(
    uint32 cryptoKeyId,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLen,
	uint8 *pOutput,
    uint32 *pOutputLen
);

/**
 * @brief AES-CMAC验证
 *
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] eOptMode 操作模式
 * @param[in] pInput 输入数据指针
 * @param[in] inputLen 输入数据长度
 * @param[in] pCmac 参考CMAC值指针
 * @param[in,out] pCmacLen CMAC长度指针
 * @param[out] pVerifyStatus 验证结果状态指针
 * @return Std_ReturnType
 */
extern Std_ReturnType SecuAuth_Calculate_AesCmacVerify
(
    uint32 cryptoKeyId,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLen,
	const uint8 *pCmac,
	uint32 *pCmacLen,
	uint32 *pVerifyStatus
);

/**
 * @brief 对称加密算法计算
 *
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] algorithm 对称算法类型
 * @param[in] direction 操作方向(加密/解密)
 * @param[in] eOptMode 操作模式
 * @param[in] pInput 输入数据指针
 * @param[in] inputLength 输入数据长度
 * @param[out] pOutput 输出数据缓冲区
 * @return Std_ReturnType
 */
extern Std_ReturnType SecuAuth_Calculate_SymmetricAlgorithm
(
    uint32 cryptoKeyId,
    Secu_SymAlgorithmType algorithm,
    Secu_DirectionType direction,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLength, 
	uint8 *pOutput
);

/**
 * @brief 对称AEAD加密(GCM模式)
 *
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] plaintextPtr 明文数据指针
 * @param[in] plaintextLength 明文数据长度
 * @param[in] associatedDataPtr 附加认证数据(AAD)指针
 * @param[in] associatedDataLength 附加认证数据长度
 * @param[out] ciphertextPtr 密文输出缓冲区
 * @param[in,out] ciphertextLengthPtr 密文长度指针
 * @param[out] tagPtr 认证标签输出缓冲区
 * @param[in,out] tagLengthPtr 标签长度指针
 * @return Std_ReturnType
 */
Std_ReturnType SecuAuth_Calculate_SymmetricAEADEncrypt
(
    uint32 cryptoKeyId,
    const uint8 *plaintextPtr,
    uint32 plaintextLength,
    const uint8 *associatedDataPtr,
    uint32 associatedDataLength,
    uint8 *ciphertextPtr,
    uint32 *ciphertextLengthPtr,
    uint8 *tagPtr,
    uint32 *tagLengthPtr
);

/**
 * @brief 对称AEAD解密(GCM模式)
 *
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] ciphertextPtr 密文数据指针
 * @param[in] ciphertextLength 密文数据长度
 * @param[in] associatedDataPtr 附加认证数据(AAD)指针
 * @param[in] associatedDataLength 附加认证数据长度
 * @param[in] tagPtr 认证标签指针
 * @param[in] tagLength 认证标签长度
 * @param[out] plaintextPtr 明文输出缓冲区
 * @param[in,out] plaintextLengthPtr 明文长度指针
 * @param[out] verifyPtr 验证结果指针
 * @return Std_ReturnType
 */
Std_ReturnType SecuAuth_Calculate_SymmetricAEADDecrypt
(
    uint32 cryptoKeyId,
    const uint8 *ciphertextPtr,
    uint32 ciphertextLength,
    const uint8 *associatedDataPtr,
    uint32 associatedDataLength,
    const uint8 *tagPtr,
    uint32 tagLength,
    uint8 *plaintextPtr,
    uint32 *plaintextLengthPtr,
    Secu_VerifyResultType *verifyPtr
);

/**
 * @brief 哈希计算
 *
 * @param[in] hashAlgorithm 哈希算法类型
 * @param[in] eOptMode 操作模式
 * @param[in] pInput 输入数据指针
 * @param[in] inputLength 输入数据长度
 * @param[out] pOutput 哈希结果输出缓冲区
 * @param[in,out] outputLengthPtr 输出长度指针
 * @return Std_ReturnType
 */
extern Std_ReturnType SecuAuth_Calculate_HashAlgorithm
(
    Secu_AlgorithmFamilyType hashAlgorithm,
	Secu_OperationModeType eOptMode,
    const uint8 *pInput,
    uint32 inputLength, 
	uint8 *pOutput,
    uint32 *outputLengthPtr
);

/**
 * @brief 随机数生成
 *
 * @param[out] outputPtr 随机数输出缓冲区
 * @param[in] outputLength 需要生成的随机数长度
 * @return Std_ReturnType
 */
extern Std_ReturnType SecuAuth_RandomGenerate
(
	uint8 *outputPtr,
    uint32 outputLength   
);

/**
 * @brief 非对称签名验证
 *
 * @param[in] cryptoKeyId 密钥ID
 * @param[in] algorithm 签名算法类型
 * @param[in] inputPtr 输入数据指针(待验证数据)
 * @param[in] inputLength 输入数据长度
 * @param[in] inputHashed 输入数据是否已哈希(TRUE=已哈希,FALSE=原始数据)
 * @param[in] signaturePtr 签名数据指针
 * @param[in] signatureLength 签名数据长度
 * @param[out] verifyPtr 验证结果指针
 * @return Std_ReturnType
 */
extern Std_ReturnType SecuAuth_Calculate_SignatureVerify
(
   uint32 cryptoKeyId,
   Secu_AsymAlgorithmType algorithm,
   const uint8 *inputPtr,  
   uint32 inputLength,
   boolean inputHashed,
   const uint8 *signaturePtr,
   uint32 signatureLength,
   Secu_VerifyResultType *verifyPtr
);


#endif  /*SECUAUTH_INTERFACE_H */
