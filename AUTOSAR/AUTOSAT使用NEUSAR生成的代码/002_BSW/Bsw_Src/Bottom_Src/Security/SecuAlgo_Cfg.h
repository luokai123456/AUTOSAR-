#ifndef SECURITY_SECUALGO_CFG_H
#define SECURITY_SECUALGO_CFG_H

#include "Std_Types.h"

/* RAM key used temporarily while performing HSM device authentication. */
#define SECU_KEY_ID_AUTH_RAM                     (20U)

/* NVM symmetric keys allocated by the C3012PT security implementation. */
#define SECU_KEY_ID_KEY_INJECT                   (0U)
#define SECU_KEY_ID_SECURE_ACCESS_L1             (1U)
#define SECU_KEY_ID_SECURE_STORE                 (21U)
#define SECU_KEY_ID_SECOC_1                      (28U)
#define SECU_KEY_ID_SECOC_2                      (29U)
#define SECU_KEY_ID_SECOC_3                      (30U)
#define SECU_KEY_ID_SECOC_4                      (31U)
#define SECU_KEY_ID_SECOC_5                      (32U)
#define SECU_KEY_ID_SECOC_6                      (33U)
#define SECU_KEY_ID_SYMMETRIC_RESERVED_1         (34U)
#define SECU_KEY_ID_SYMMETRIC_RESERVED_2         (35U)
#define SECU_KEY_ID_SYMMETRIC_RESERVED_3         (36U)
#define SECU_KEY_ID_SYMMETRIC_RESERVED_4         (37U)
#define SECU_KEY_ID_SECURE_BOOT_1                (38U)
#define SECU_KEY_ID_SECURE_BOOT_2                (39U)
#define SECU_KEY_ID_SECURE_BOOT_3                (40U)
#define SECU_KEY_ID_SYMMETRIC_RESERVED_5         (44U)
#define SECU_KEY_ID_USER_DATA                    (45U)
#define SECU_KEY_ID_SECURE_ACCESS_L2             (46U)
#define SECU_KEY_ID_SECURE_ACCESS_L3             (47U)

/* NVM asymmetric keys allocated by the C3012PT security implementation. */
#define SECU_KEY_ID_SECURE_BOOT_EVPT             (41U)
#define SECU_KEY_ID_SECURE_FLASH_USER_APP        (42U)
#define SECU_KEY_ID_SECURE_FLASH_USER_BOOT       (43U)
#define SECU_KEY_ID_AUTH_CA_EVPT                 (48U)
#define SECU_KEY_ID_AUTH_ECU_EVPT                (49U)
#define SECU_KEY_ID_AUTH_CA_USER                 (50U)
#define SECU_KEY_ID_AUTH_ECU_USER                (51U)
#define SECU_KEY_ID_ASYMMETRIC_RESERVED_1        (52U)
#define SECU_KEY_ID_ASYMMETRIC_RESERVED_2        (53U)
#define SECU_KEY_ID_ASYMMETRIC_RESERVED_3        (54U)

#define SECU_AUTH_KEY_HANDLE                     (0U)
#define SECU_AUTH_KEY_LENGTH                     (16U)

extern const uint8 HSM_Internal_KEY_AUTH[SECU_AUTH_KEY_LENGTH];

#endif  /* SECURITY_SECUALGO_CFG_H */
