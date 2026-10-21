#ifndef IMA_REG_H_
#define IMA_REG_H_

/* ============================================================================
   =============================== Module: IMA ================================
   ============================================================================ */

typedef union IMA_CTRL_union_tag {     /* Control Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t READ:1;
  } B;
} IMA_CTRL_tag;

typedef union IMA_ENABLE_union_tag {   /* Enable Access Register */
  vuint32_t R;
  struct {
    vuint32_t  :31;
    vuint32_t EN:1;
  } B;
} IMA_ENABLE_tag;

typedef union IMA_STATUS_union_tag {   /* Status Register */
  vuint32_t R;
  struct {
    vuint32_t  :23;
    vuint32_t WRITE_LOCK:1;
    vuint32_t  :7;
    vuint32_t READ_LOCK:1;
  } B;
} IMA_STATUS_tag;

typedef union IMA_SLCT_union_tag {     /* RAM Select Register */
  vuint32_t R;
  struct {
    vuint32_t  :3;
    vuint32_t ROW_SLCT:13;
    vuint32_t  :10;
    vuint32_t ARRAY_SLCT:6;
  } B;
} IMA_SLCT_tag;

typedef union IMA_WRITE_UNLOCK_union_tag { /* Write Unlock Register */
  vuint32_t R;
  struct {
    vuint32_t WRITE_KEY:32;
  } B;
} IMA_WRITE_UNLOCK_tag;

typedef union IMA_READ_UNLOCK_union_tag { /* Read Unlock Register */
  vuint32_t R;
  struct {
    vuint32_t READ_KEY:32;
  } B;
} IMA_READ_UNLOCK_tag;

typedef union IMA_WRITE_DATA_4_union_tag { /* RAM Write Data Register 4 */
  vuint32_t R;
  struct {
    vuint32_t WRITE_4:32;
  } B;
} IMA_WRITE_DATA_4_tag;

typedef union IMA_WRITE_DATA_3_union_tag { /* RAM Write Data Register 3 */
  vuint32_t R;
  struct {
    vuint32_t WRITE_3:32;
  } B;
} IMA_WRITE_DATA_3_tag;

typedef union IMA_WRITE_DATA_2_union_tag { /* RAM Write Data Register 2 */
  vuint32_t R;
  struct {
    vuint32_t WRITE_2:32;
  } B;
} IMA_WRITE_DATA_2_tag;

typedef union IMA_WRITE_DATA_1_union_tag { /* RAM Write Data Register 1 */
  vuint32_t R;
  struct {
    vuint32_t WRITE_1:32;
  } B;
} IMA_WRITE_DATA_1_tag;

typedef union IMA_WRITE_DATA_0_union_tag { /* RAM Write Data Register 0 */
  vuint32_t R;
  struct {
    vuint32_t WRITE_0:32;
  } B;
} IMA_WRITE_DATA_0_tag;

typedef union IMA_READ_DATA_4_union_tag { /* RAM Read Data Register 4 */
  vuint32_t R;
  struct {
    vuint32_t READ_4:32;
  } B;
} IMA_READ_DATA_4_tag;

typedef union IMA_READ_DATA_3_union_tag { /* RAM Read Data Register 3 */
  vuint32_t R;
  struct {
    vuint32_t READ_3:32;
  } B;
} IMA_READ_DATA_3_tag;

typedef union IMA_READ_DATA_2_union_tag { /* RAM Read Data Register 2 */
  vuint32_t R;
  struct {
    vuint32_t READ_2:32;
  } B;
} IMA_READ_DATA_2_tag;

typedef union IMA_READ_DATA_1_union_tag { /* RAM Read Data Register 1 */
  vuint32_t R;
  struct {
    vuint32_t READ_1:32;
  } B;
} IMA_READ_DATA_1_tag;

typedef union IMA_READ_DATA_0_union_tag { /* RAM Read Data Register 0 */
  vuint32_t R;
  struct {
    vuint32_t READ_0:32;
  } B;
} IMA_READ_DATA_0_tag;

struct IMA_tag {
  IMA_CTRL_tag CTRL;                   /* Control Register */
  IMA_ENABLE_tag ENABLE_R;               /* Enable Access Register */
  IMA_STATUS_tag STATUS;               /* Status Register */
  IMA_SLCT_tag SLCT;                   /* RAM Select Register */
  IMA_WRITE_UNLOCK_tag WRITE_UNLOCK;   /* Write Unlock Register */
  IMA_READ_UNLOCK_tag READ_UNLOCK;     /* Read Unlock Register */
  uint8_t IMA_reserved0[20];
  IMA_WRITE_DATA_4_tag WRITE_DATA_4;   /* RAM Write Data Register 4 */
  IMA_WRITE_DATA_3_tag WRITE_DATA_3;   /* RAM Write Data Register 3 */
  IMA_WRITE_DATA_2_tag WRITE_DATA_2;   /* RAM Write Data Register 2 */
  IMA_WRITE_DATA_1_tag WRITE_DATA_1;   /* RAM Write Data Register 1 */
  IMA_WRITE_DATA_0_tag WRITE_DATA_0;   /* RAM Write Data Register 0 */
  uint8_t IMA_reserved1[12];
  IMA_READ_DATA_4_tag READ_DATA_4;     /* RAM Read Data Register 4 */
  IMA_READ_DATA_3_tag READ_DATA_3;     /* RAM Read Data Register 3 */
  IMA_READ_DATA_2_tag READ_DATA_2;     /* RAM Read Data Register 2 */
  IMA_READ_DATA_1_tag READ_DATA_1;     /* RAM Read Data Register 1 */
  IMA_READ_DATA_0_tag READ_DATA_0;     /* RAM Read Data Register 0 */
};

#endif
