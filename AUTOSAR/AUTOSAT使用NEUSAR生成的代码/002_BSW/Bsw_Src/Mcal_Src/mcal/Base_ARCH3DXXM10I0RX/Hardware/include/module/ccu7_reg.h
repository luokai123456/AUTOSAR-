#ifndef CCU7_REG_H_
#define CCU7_REG_H_

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

/* =========================================================================================================================== */
/* ================                                           CCU7                                            ================ */
/* =========================================================================================================================== */

/**
  * @brief CCU7 (CCU7)
  */

struct CCU7_Type                                /*!< (@ 0x40008000) CCU7 Structure                                             */
{

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000000) Clock Control Register                                     */

    struct
    {
      uint32_t            : 30;
      __IM  uint32_t DISS       : 1;            /*!< [1..1] Module Disable Status Bit - DISS                                   */
      __IOM uint32_t DISR       : 1;            /*!< [0..0] Module Disable Request Bit - DISR                                  */
    } bit;
  } CLC;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000004) Module Configuration Register                              */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t WREN       : 1;            /*!< [15..15] Write Enable - WREN                                              */
      uint32_t            : 8;
      __IOM uint32_t T16        : 1;            /*!< [6..6] T16 Available - T16                                                */
      __IOM uint32_t T15        : 1;            /*!< [5..5] T15 Available - T15                                                */
      __IOM uint32_t T14        : 1;            /*!< [4..4] T14 Available -T14                                                 */
      uint32_t            : 1;
      __IOM uint32_t MCM        : 1;            /*!< [2..2] Multi-Channel Mode Available - MCM                                 */
      __IOM uint32_t T12        : 1;            /*!< [0..0] T12 Available - T12                                                */
      __IOM uint32_t T13        : 1;            /*!< [1..1] T13 Available - T13                                                */
    } bit;
  } MCFG;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000008) Module Identification Register                             */

    struct
    {
      uint32_t            : 16;
      __IM  uint32_t MODNUM     : 8;            /*!< [15..8] Module Number Value - MODNUM                                      */
      __IM  uint32_t MODREV     : 8;            /*!< [7..0] Module Revision Number - MODREV                                    */

    } bit;
  } ID;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000000C) Port Input Select Register 0                               */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t IST12HR    : 2;            /*!< [15..14] Input Select for T12HR                                           */
      __IOM uint32_t ISPOS2     : 2;            /*!< [13..12] Input Select for CCPOS2                                          */
      __IOM uint32_t ISPOS1     : 2;            /*!< [11..10] Input Select for CCPOS1                                          */
      __IOM uint32_t ISPOS0     : 2;            /*!< [9..8] Input Select for CCPOS0                                            */
      __IOM uint32_t ISTRP      : 2;            /*!< [7..6] Input Select for CTRAP                                             */
      __IOM uint32_t ISCC72     : 2;            /*!< [5..4] Input Select for CC72                                              */
      __IOM uint32_t ISCC71     : 2;            /*!< [3..2] Input Select for CC71                                              */
      __IOM uint32_t ISCC70     : 2;            /*!< [1..0] Input Select for CC70                                              */
    } bit;
  } PISEL0;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000010) Port Input Select Register 2                               */

    struct
    {
      uint32_t            : 24;
      __IOM uint32_t T13EXT     : 1;            /*!< [7..7] Extension for T13HR Inputs                                         */
      __IOM uint32_t T12EXT     : 1;            /*!< [6..6] Extension for T12HR Inputs                                         */
      __IOM uint32_t ISCNT13    : 2;            /*!< [5..4] Input Select for T13 Counting Input                                */
      __IOM uint32_t ISCNT12    : 2;            /*!< [3..2] Input Select for T12 Counting Input                                */
      __IOM uint32_t IST13HR    : 2;            /*!< [1..0] Input Select for T13HR                                             */
    } bit;
  } PISEL2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000014) Port Input Select Register 24                              */

    struct
    {
      uint32_t            : 27;
      __IOM uint32_t T1xEXT     : 1;            /*!< [4..4] Extension for T1xHR Inputs                                         */
      __IOM uint32_t ISCNT1x    : 2;            /*!< [3..2] Input Select for T1x Counting Input                                */
      __IOM uint32_t IST1xHR    : 2;            /*!< [1..0] Input Select for T1xHR                                             */
    } bit;
  } PISEL24;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000018) Port Input Select Register 25                              */

    struct
    {
      uint32_t            : 27;
      __IOM uint32_t T1xEXT     : 1;            /*!< [4..4] Extension for T1xHR Inputs                                         */
      __IOM uint32_t ISCNT1x    : 2;            /*!< [3..2] Input Select for T1x Counting Input                                */
      __IOM uint32_t IST1xHR    : 2;            /*!< [1..0] Input Select for T1xHR                                             */
    } bit;
  } PISEL25;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000001C) Port Input Select Register 26                              */

    struct
    {
      uint32_t            : 27;
      __IOM uint32_t T1xEXT     : 1;            /*!< [4..4] Extension for T1xHR Inputs                                         */
      __IOM uint32_t ISCNT1x    : 2;            /*!< [3..2] Input Select for T1x Counting Input                                */
      __IOM uint32_t IST1xHR    : 2;            /*!< [1..0] Input Select for T1xHR                                             */
    } bit;
  } PISEL26;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000020) Kernel State Control Sensitivity Register                  */

    struct
    {
      uint32_t            : 25;
      __IOM uint32_t SB6        : 1;            /*!< [0..0] Sensitivity Block x SBx (x=0,1,2,...)                              */
      __IOM uint32_t SB5        : 1;            /*!< [1..1] Sensitivity Block x SBx (x=0,1,2,...)                              */
      __IOM uint32_t SB4        : 1;            /*!< [2..2] Sensitivity Block x SBx (x=0,1,2,...)                              */
      __IOM uint32_t SB3        : 1;            /*!< [3..3] Sensitivity Block x SBx (x=0,1,2,...)                              */
      __IOM uint32_t SB2        : 1;            /*!< [4..4] Sensitivity Block x SBx (x=0,1,2,...)                              */
      __IOM uint32_t SB1        : 1;            /*!< [5..5] Sensitivity Block x SBx (x=0,1,2,...)                              */
      __IOM uint32_t SB0        : 1;            /*!< [6..6] Sensitivity Block x SBx (x=0,1,2,...)                              */
    } bit;
  } KSCSR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000024) Timer T12 Counter Register                                 */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t T12CV      : 16;           /*!< [15..0] Timer T12 Counter Value                                           */
    } bit;
  } T12;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000028) Timer T12 Period Register                                  */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t T12PV      : 16;           /*!< [15..0] T12 Period Value                                                  */
    } bit;
  } T12PR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000002C) Dead-Time Control Register for Timer T12 Low               */

    struct
    {
      uint32_t            : 21;
      __IM  uint32_t DTR2       : 1;            /*!< [8..8] Dead-Time Run Indication Bit 0                                     */
      __IM  uint32_t DTR1       : 1;            /*!< [9..9] Dead-Time Run Indication Bit 1                                     */
      __IM  uint32_t DTR0       : 1;            /*!< [10..10] Dead-Time Run Indication Bit 2                                   */
      uint32_t            : 5;
      __IOM uint32_t DTE2       : 1;            /*!< [0..0] Dead-Time Enable Bit 0                                             */
      __IOM uint32_t DTE1       : 1;            /*!< [1..1] Dead-Time Enable Bit 1                                             */
      __IOM uint32_t DTE0       : 1;            /*!< [2..2] Dead-Time Enable Bit 2                                             */
    } bit;
  } T12DTC;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000030) Dead-Time value Register CC70                              */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t DTM_FALL   : 8;            /*!< [15..8] Dead-Time fall                                                    */
      __IOM uint32_t DTM_RISE   : 8;            /*!< [7..0] Dead-Time rise                                                     */
    } bit;
  } T12DT0_VAL;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000034) Dead-Time value Register CC71                              */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t DTM_FALL   : 8;            /*!< [15..8] Dead-Time fall                                                    */
      __IOM uint32_t DTM_RISE   : 8;            /*!< [7..0] Dead-Time rise                                                     */
    } bit;
  } T12DT1_VAL;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000038) Dead-Time value Register CC72                              */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t DTM_FALL   : 8;            /*!< [15..8] Dead-Time fall                                                    */
      __IOM uint32_t DTM_RISE   : 8;            /*!< [7..0] Dead-Time rise                                                     */
    } bit;
  } T12DT2_VAL;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000003C) Dead-Time Input Selection Register (Demo in Windows)       */

    struct
    {

      uint32_t            : 22;
      __IOM uint32_t DTINSEL2   : 2;            /*!< [1..0] Deadtime Input selection 0                                         */
      uint32_t            : 2;
      __IOM uint32_t DTINSEL1   : 2;            /*!< [5..4] Deadtime Input selection 1                                         */
      uint32_t            : 2;
      __IOM uint32_t DTINSEL0   : 2;            /*!< [9..8] Deadtime Input selection 2                                         */
    } bit;
  } T12DTINSEL;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000040) Capture/Compare Register for Channel CC70                  */

    struct
    {
      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Capture/Compare Value - CCV                                       */
    } bit;
  } CC70R;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000044) Capture/Compare Register for Channel CC71                  */

    struct
    {
      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Capture/Compare Value - CCV                                       */
    } bit;
  } CC71R;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000048) Capture/Compare Register for Channel CC72                  */

    struct
    {
      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Capture/Compare Value - CCV                                       */
    } bit;
  } CC72R;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000004C) Capture/Compare Shadow Reg. for Channel CC70               */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel x Capture/Compare Value
                                                 - CCS                                                                     */
    } bit;
  } CC70SR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000050) Capture/Compare Shadow Reg. for Channel CC71               */

    struct
    {
      uint32_t            : 16;
       __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel x Capture/Compare Value
                                                     - CCS                                                                     */
    } bit;
  } CC71SR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000054) Capture/Compare Shadow Reg. for Channel CC72               */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel x Capture/Compare Value
                                                     - CCS                                                                     */
    } bit;
  } CC72SR;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000058) Compare Register for Channel C70B                          */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CV         : 16;           /*!< [15..0] Compare Value - CV                                                */
    } bit;
  } CC70BR;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x0000005C) Compare Register for Channel C71B                          */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CV         : 16;           /*!< [15..0] Compare Value - CV                                                */
    } bit;
  } CC71BR;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000060) Compare Register for Channel C72B                          */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CV         : 16;           /*!< [15..0] Compare Value - CV                                                */
    } bit;
  } CC72BR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000064) Compare Shadow Reg. for Channel C70BSR                     */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CS         : 16;           /*!< [15..0] Shadow Register for Channel x Compare Value - CS                  */
    } bit;
  } CC70BSR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000068) Compare Shadow Reg. for Channel C71BSR                     */

    struct
    {

      uint32_t            : 16;
       __IOM uint32_t CS         : 16;           /*!< [15..0] Shadow Register for Channel x Compare Value - CS                  */
    } bit;
  } CC71BSR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000006C) Compare Shadow Reg. for Channel C72BSR                     */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CS         : 16;           /*!< [15..0] Shadow Register for Channel x Compare Value - CS                  */
    } bit;
  } CC72BSR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000070) Timer T13 Counter Register                                 */

    struct
    {

      uint32_t            : 16;
       __IOM uint32_t T1xCV      : 16;           /*!< [15..0] Timer T1x Counter Value                                           */
    } bit;
  } T13R;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000074) Timer T14 Counter Register                                 */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xCV      : 16;           /*!< [15..0] Timer T1x Counter Value                                           */
    } bit;
  } T14R;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000078) Timer T15 Counter Register                                 */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xCV      : 16;           /*!< [15..0] Timer T1x Counter Value                                           */
    } bit;
  } T15R;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000007C) Timer T16 Counter Register                                 */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xCV      : 16;           /*!< [15..0] Timer T1x Counter Value                                           */
    } bit;
  } T16R;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000080) Timer T13 Period Register                                  */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xPV      : 16;           /*!< [15..0] T1x Period Value                                                  */
    } bit;
  } T13PR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000084) Timer T14 Period Register                                  */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xPV      : 16;           /*!< [15..0] T1x Period Value                                                  */
    } bit;
  } T14PR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000088) Timer T15 Period Register                                  */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xPV      : 16;           /*!< [15..0] T1x Period Value                                                  */
    } bit;
  } T15PR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000008C) Timer T16 Period Register                                  */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t T1xPV      : 16;           /*!< [15..0] T1x Period Value                                                  */
    } bit;
  } T16PR;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000090) Compare Register for Channel C73                           */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Channel C7x Compare Value - CCV                                   */
    } bit;
  } C73R;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000094) Compare Register for Channel C74                           */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Channel C7x Compare Value - CCV                                   */
    } bit;
  } C74R;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000098) Compare Register for Channel C75                           */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Channel C7x Compare Value - CCV                                   */
    } bit;
  } C75R;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x0000009C) Compare Register for Channel C76                           */

    struct
    {

      uint32_t            : 16;
      __IM  uint32_t CCV        : 16;           /*!< [15..0] Channel C7x Compare Value - CCV                                   */
    } bit;
  } C76R;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000A0) Compare Shadow Reg. for Channel CC73                       */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel CC73 Compare Value                    */
    } bit;
  } C73SR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000A4) Compare Shadow Reg. for Channel CC74                       */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel CC74 Compare Value                    */
    } bit;
  } C74SR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000A8) Compare Shadow Reg. for Channel CC75                       */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel CC75 Compare Value                    */
    } bit;
  } C75SR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000AC) Compare Shadow Reg. for Channel CC76                       */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t CCS        : 16;           /*!< [15..0] Shadow Register for Channel CC76 Compare Value                    */
    } bit;
  } C76SR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000B0) Compare State Register                                     */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t T13IM      : 1;            /*!< [15..15] T13 Inverted Modulation                                          */
      __IOM uint32_t COUT73PS   : 1;            /*!< [14..14] Passive State Select for Compare Outputs                         */
       __IOM uint32_t COUT72PS   : 1;            /*!< [13..13] Passive State Select for Compare Outputs                         */
      __IOM uint32_t CC72PS     : 1;            /*!< [12..12] Passive State Select for Compare Outputs                         */
      __IOM uint32_t COUT71PS   : 1;            /*!< [11..11] Passive State Select for Compare Outputs                         */
      __IOM uint32_t CC71PS     : 1;            /*!< [10..10] Passive State Select for Compare Outputs                         */
     __IOM uint32_t COUT70PS   : 1;            /*!< [9..9] Passive State Select for Compare Outputs                           */
      __IOM uint32_t CC70PS     : 1;            /*!< [8..8] Passive State Select for Compare Outputs                           */
      uint32_t            : 1;
       __IM  uint32_t CC73ST     : 1;            /*!< [6..6] Compare State Bits                                                 */
      __IM  uint32_t CCPOS2     : 1;            /*!< [5..5] Sampled Hall Pattern Bit 2                                         */
      __IM  uint32_t CCPOS1     : 1;            /*!< [4..4] Sampled Hall Pattern Bit 1                                         */
      __IM  uint32_t CCPOS0     : 1;            /*!< [3..3] Sampled Hall Pattern Bit 0                                         */
      __IM  uint32_t CC72ST     : 1;            /*!< [2..2] Capture/Compare State Bits                                         */
      __IM  uint32_t CC71ST     : 1;            /*!< [1..1] Capture/Compare State Bits                                         */
    __IM  uint32_t CC70ST     : 1;            /*!< [0..0] Capture/Compare State Bits                                         */
    } bit;
  } CMPSTAT;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x000000B4) Compare State Register 2                                   */

    struct
    {
      uint32_t            : 21;
       __IM  uint32_t CC72ST     : 1;            /*!< [10..10] Capture/Compare State Bits                                       */
      __IM  uint32_t CC71ST     : 1;            /*!< [9..9] Capture/Compare State Bits                                         */
      __IM  uint32_t CC70ST     : 1;            /*!< [8..8] Capture/Compare State Bits                                         */
      uint32_t            : 1;
      __IM  uint32_t C76ST      : 1;            /*!< [6..6] Compare State Bits                                                 */
      __IM  uint32_t C75ST      : 1;            /*!< [5..5] Compare State Bits                                                 */
      __IM  uint32_t C74ST      : 1;            /*!< [4..4] Compare State Bits                                                 */
      uint32_t            : 1;
       __IM  uint32_t C72BST     : 1;            /*!< [2..2] Compare State Bits B                                               */
      __IM  uint32_t C71BST     : 1;            /*!< [1..1] Compare State Bits B                                               */
      __IM  uint32_t C70BST     : 1;            /*!< [0..0] Compare State Bits B                                               */
    } bit;
  } CMPSTAT_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000B8) Compare State Modification Register                        */

    struct
    {
      uint32_t            : 17;
      __OM  uint32_t MCC73R     : 1;            /*!< [14..14] Capture/Compare Status Modification Bits (Reset)                 */
      __OM  uint32_t MCC72BR    : 1;            /*!< [13..13] Compare B Status Modification Bit 2(Reset)                       */
      __OM  uint32_t MCC71BR    : 1;            /*!< [12..12] Compare B Status Modification Bit 1(Reset)                       */
       __OM  uint32_t MCC70BR    : 1;            /*!< [11..11] Compare B Status Modification Bit 0(Reset)                       */
      __OM  uint32_t MCC72R     : 1;            /*!< [10..10] Capture/Compare Status Modification Bit 2(Reset)                 */
      __OM  uint32_t MCC71R     : 1;            /*!< [9..9] Capture/Compare Status Modification Bit 1(Reset)                   */
       __OM  uint32_t MCC70R     : 1;            /*!< [8..8] Capture/Compare Status Modification Bit 0(Reset)                   */
      uint32_t            : 1;
      __OM  uint32_t MCC73S     : 1;            /*!< [6..6] Capture/Compare Status Modification Bits (Set)                     */
      __OM  uint32_t MCC72BS    : 1;            /*!< [5..5] Compare B Status Modification Bit 2 (Set)                          */
      __OM  uint32_t MCC71BS    : 1;            /*!< [4..4] Compare B Status Modification Bit 1 (Set)                          */
      __OM  uint32_t MCC70BS    : 1;            /*!< [3..3] Compare B Status Modification Bit 0 (Set)                          */
      __OM  uint32_t MCC72S     : 1;            /*!< [2..2] Capture/Compare Status Modification Bit 2 (Set)                    */
      __OM  uint32_t MCC71S     : 1;            /*!< [1..1] Capture/Compare Status Modification Bit 1 (Set)                    */
     __OM  uint32_t MCC70S     : 1;            /*!< [0..0] Capture/Compare Status Modification Bit 0 (Set)                    */
    } bit;
  } CMPMODIF;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000BC) Compare State Modification Register 2                      */

    struct
    {
      uint32_t            : 17;
       __IOM uint32_t C72BINV    : 1;            /*!< [14..14] Output channel C72BST Inversion Enable                           */
       __IOM uint32_t C71BINV    : 1;            /*!< [13..13] Output channel C71BST Inversion Enable                           */
      __IOM uint32_t C70BINV    : 1;            /*!< [12..12] Output channel C70BST Inversion Enable                           */
      uint32_t            : 1;
       __OM  uint32_t MC76R      : 1;            /*!< [10..10] Compare Status Modification Bit 6(Reset)                         */
       __OM  uint32_t MC75R      : 1;            /*!< [9..9] Compare Status Modification Bit 5(Reset)                           */
      __OM  uint32_t MC74R      : 1;            /*!< [8..8] Compare Status Modification Bit 4(Reset)                           */
      uint32_t            : 1;
      __IOM uint32_t CC72INV    : 1;            /*!< [6..6] Output channel CC72ST Inversion Enable                             */
      __IOM uint32_t CC71INV    : 1;            /*!< [5..5] Output channel CC71ST Inversion Enable                             */
      __IOM uint32_t CC70INV    : 1;            /*!< [4..4] Output channel CC70ST Inversion Enable                             */
      uint32_t            : 1;
      __OM  uint32_t MC76S      : 1;            /*!< [2..2] Compare Status Modification Bit 6 (Set)                            */
      __OM  uint32_t MC75S      : 1;            /*!< [1..1] Compare Status Modification Bit 5 (Set)                            */
      __OM  uint32_t MC74S      : 1;            /*!< [0..0] Compare Status Modification Bit 4 (Set)                            */
    } bit;
  } CMPMODIF_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000C0) T12 Capture/Compare Mode Select Register                   */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t DBYP       : 1;            /*!< [15..15] Delay Bypass                                                     */
      __IOM uint32_t HSYNC      : 3;            /*!< [14..12] Hall Synchronization                                             */
      __IOM uint32_t MSEL72     : 4;            /*!< [11..8] Capture/Compare Mode Selection MSEL7x (x=0,1,2)                   */
      __IOM uint32_t MSEL71     : 4;            /*!< [7..4] Capture/Compare Mode Selection MSEL7x (x=0,1,2)                    */
      __IOM uint32_t MSEL70     : 4;            /*!< [3..0] Capture/Compare Mode Selection MSEL7x (x=0,1,2)                    */
    } bit;
  } T12MSEL;




  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000C4) Timer Control Register 0                                   */

    struct
    {
      uint32_t            : 18;
       __IM  uint32_t STE13      : 1;            /*!< [13..13] Timer T13 Shadow Transfer Enable                                 */
      __IM  uint32_t T13R       : 1;            /*!< [12..12] Timer T13 Run Bit                                                */
      __IOM uint32_t T13PRE     : 1;            /*!< [11..11] Timer T13 Prescaler Bit                                          */
      uint32_t            : 3;
      __IOM uint32_t CTM        : 1;            /*!< [7..7] T12 Operating Mode                                                 */
      __IM  uint32_t CDIR       : 1;            /*!< [6..6] Count Direction of Timer T12                                       */
      __IM  uint32_t STE12      : 1;            /*!< [5..5] Timer T12 Shadow Transfer Enable                                   */
      __IM  uint32_t T12R       : 1;            /*!< [4..4] Timer T12 Run Bit                                                  */
      __IOM uint32_t T12PRE     : 1;            /*!< [3..3] Timer T12 Prescaler Bit                                            */
      uint32_t            : 3;
    } bit;
  } TCTR0;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000C8) Timer Control Register 1                                   */

    struct
    {
      uint32_t            : 16;
      __IM  uint32_t STE13      : 1;            /*!< [15..15] Timer T13 Shadow Transfer Enable                                 */
      __IM  uint32_t STE12      : 1;            /*!< [14..14] Timer T12 Shadow Transfer Enable                                 */
      __IM  uint32_t STE16      : 1;            /*!< [13..13] Timer T16 Shadow Transfer Enable                                 */
      __IM  uint32_t T16R       : 1;            /*!< [12..12] Timer T16 Run Bit                                                */
      uint32_t            : 2;
      __IM  uint32_t STE15      : 1;            /*!< [9..9] Timer T15 Shadow Transfer Enable                                   */
      __IM  uint32_t T15R       : 1;            /*!< [8..8] Timer T15 Run Bit                                                  */
      uint32_t            : 2;
       __IM  uint32_t STE14      : 1;            /*!< [5..5] Timer T14 Shadow Transfer Enable                                   */
      __IM  uint32_t T14R       : 1;            /*!< [4..4] Timer T14 Run Bit                                                  */
      __IOM uint32_t T1xPRE     : 1;            /*!< [3..3] Timer T14 / 15 /16 Prescaler Bit                                   */
      uint32_t            : 3;

    } bit;
  } TCTR1;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000CC) Timer Control Register 2                                   */

    struct
    {
      uint32_t            : 20;
      __IOM uint32_t T13RSEL    : 2;            /*!< [11..10] Timer T13 External Run Selection                                 */
      __IOM uint32_t T12RSEL    : 2;            /*!< [9..8] Timer T12 External Run Selection                                   */
      uint32_t            : 1;
      __IOM uint32_t T13TED     : 2;            /*!< [6..5] Timer T13 Trigger Event Direction                                  */
      __IOM uint32_t T13TEC     : 3;            /*!< [4..2] T13 Trigger Event Control                                          */
      __IOM uint32_t T13SSC     : 1;            /*!< [1..1] Timer T13 Single Shot Control                                      */
      __IOM uint32_t T12SSC     : 1;            /*!< [0..0] Timer T12 Single Shot Control                                      */
    } bit;
  } TCTR2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000D0) Timer Control Register 24                                  */

    struct
    {
      uint32_t            : 22;
      __IOM uint32_t T1xRSEL    : 2;            /*!< [9..8] Timer T1x External Run Selection                                   */
      uint32_t            : 2;
      __IOM uint32_t T1xTED     : 2;            /*!< [5..4] Timer T1x Trigger Event Direction                                  */
      __IOM uint32_t T1xTEC     : 3;            /*!< [3..1] T1x Trigger Event Control                                          */
      __IOM uint32_t T1xSSC     : 1;            /*!< [0..0] Timer T1x Single Shot Control                                      */

    } bit;
  } TCTR24;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000D4) Timer Control Register 25                                  */

    struct
    {
      uint32_t            : 22;

      __IOM uint32_t T1xRSEL    : 2;            /*!< [9..8] Timer T1x External Run Selection                                   */
      uint32_t            : 2;
       __IOM uint32_t T1xTED     : 2;            /*!< [5..4] Timer T1x Trigger Event Direction                                  */
       __IOM uint32_t T1xTEC     : 3;            /*!< [3..1] T1x Trigger Event Control                                          */
      __IOM uint32_t T1xSSC     : 1;            /*!< [0..0] Timer T1x Single Shot Control                                      */

    } bit;
  } TCTR25;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000D8) Timer Control Register 26                                  */

    struct
    {
      uint32_t            : 22;
      __IOM uint32_t T1xRSEL    : 2;            /*!< [9..8] Timer T1x External Run Selection                                   */
      uint32_t            : 2;
      __IOM uint32_t T1xTED     : 2;            /*!< [5..4] Timer T1x Trigger Event Direction                                  */
      __IOM uint32_t T1xTEC     : 3;            /*!< [3..1] T1x Trigger Event Control                                          */
      __IOM uint32_t T1xSSC     : 1;            /*!< [0..0] Timer T1x Single Shot Control                                      */

    } bit;
  } TCTR26;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000DC) Timer Control Register 4                                   */

    struct
    {
      uint32_t            : 16;
     __OM  uint32_t T13STD     : 1;            /*!< [15..15] Timer T13 Shadow Transfer Disable                                */
     __OM  uint32_t T13STR     : 1;            /*!< [14..14] Timer T13 Shadow Transfer Request                                */
     __OM  uint32_t T13CNT     : 1;            /*!< [13..13] Timer T13 Count Event                                            */
     uint32_t            : 2;
     __OM  uint32_t T13RES     : 1;            /*!< [10..10] Timer T13 Reset                                                  */
     __OM  uint32_t T13RS      : 1;            /*!< [9..9] Timer T13 Run Set                                                  */
     __OM  uint32_t T13RR      : 1;            /*!< [8..8] Timer T13 Run Reset                                                */
     __OM  uint32_t T12STD     : 1;            /*!< [7..7] Timer T12 Shadow Transfer Disable                                  */
     __OM  uint32_t T12STR     : 1;            /*!< [6..6] Timer T12 Shadow Transfer Request                                  */
     __OM  uint32_t T12CNT     : 1;            /*!< [5..5] Timer T12 Count Event                                              */
     uint32_t            : 1;
     __OM  uint32_t DTRES      : 1;            /*!< [3..3] Dead-Time Counter Reset                                            */
     __OM  uint32_t T12RES     : 1;            /*!< [2..2] Timer T12 Reset                                                    */
     __OM  uint32_t T12RS      : 1;            /*!< [1..1] Timer T12 Run Set                                                  */
     __OM  uint32_t T12RR      : 1;            /*!< [0..0] Timer T12 Run Reset                                                */
    } bit;
  } TCTR4;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000E0) Timer Control Register 44                                  */

    struct
    {
      uint32_t            : 25;
     __OM  uint32_t T1xSTD     : 1;            /*!< [6..6] Timer T1x Shadow Transfer Disable                                  */
     __OM  uint32_t T1xSTR     : 1;            /*!< [5..5] Timer T1x Shadow Transfer Request                                  */
     __OM  uint32_t T1xCNT     : 1;            /*!< [4..4] Timer T1x Count Event                                              */
     uint32_t            : 1;
     __OM  uint32_t T1xRES     : 1;            /*!< [2..2] Timer T1x Reset                                                    */
      __OM  uint32_t T1xRS      : 1;            /*!< [1..1] Timer T1x Run Set                                                  */
      __OM  uint32_t T1xRR      : 1;            /*!< [0..0] Timer T1x Run Reset                                                */
    } bit;
  } TCTR44;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000E4) Timer Control Register 45                                  */

    struct
    {
      uint32_t            : 25;
      __OM  uint32_t T1xSTD     : 1;            /*!< [6..6] Timer T1x Shadow Transfer Disable                                  */
     __OM  uint32_t T1xSTR     : 1;            /*!< [5..5] Timer T1x Shadow Transfer Request                                  */
     __OM  uint32_t T1xCNT     : 1;            /*!< [4..4] Timer T1x Count Event                                              */
     uint32_t            : 1;
     __OM  uint32_t T1xRES     : 1;            /*!< [2..2] Timer T1x Reset                                                    */
     __OM  uint32_t T1xRS      : 1;            /*!< [1..1] Timer T1x Run Set                                                  */
     __OM  uint32_t T1xRR      : 1;            /*!< [0..0] Timer T1x Run Reset                                                */
    } bit;
  } TCTR45;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000E8) Timer Control Register 46                                  */

    struct
    {
      uint32_t            : 25;

      __OM  uint32_t T1xSTD     : 1;            /*!< [6..6] Timer T1x Shadow Transfer Disable                                  */
      __OM  uint32_t T1xSTR     : 1;            /*!< [5..5] Timer T1x Shadow Transfer Request                                  */
      __OM  uint32_t T1xCNT     : 1;            /*!< [4..4] Timer T1x Count Event                                              */
      uint32_t            : 1;
      __OM  uint32_t T1xRES     : 1;            /*!< [2..2] Timer T1x Reset                                                    */
      __OM  uint32_t T1xRS      : 1;            /*!< [1..1] Timer T1x Run Set                                                  */
      __OM  uint32_t T1xRR      : 1;            /*!< [0..0] Timer T1x Run Reset                                                */
    } bit;
  } TCTR46;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000EC) Modulation Control Register                                */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t ECT13O     : 1;            /*!< [15..15] Enable Compare Timer T13 Output                                  */
      uint32_t            : 1;
      __IOM uint32_t T13MODEN_COUT72 : 1;       /*!< [13..13] T13 Modulation Enable                                            */
      __IOM uint32_t T13MODEN_CC72 : 1;         /*!< [12..12] T13 Modulation Enable                                            */
      __IOM uint32_t T13MODEN_COUT71 : 1;       /*!< [11..11] T13 Modulation Enable                                            */
      __IOM uint32_t T13MODEN_CC71 : 1;         /*!< [10..10] T13 Modulation Enable                                            */
      __IOM uint32_t T13MODEN_COUT70 : 1;       /*!< [9..9] T13 Modulation Enable                                              */
      __IOM uint32_t T13MODEN_CC70 : 1;         /*!< [8..8] T13 Modulation Enable                                              */
      __IOM uint32_t MCMEN      : 1;            /*!< [7..7] Multi-Channel Mode Enable                                          */
      uint32_t            : 1;
      __IOM uint32_t T12MODEN_COUT72 : 1;       /*!< [5..5] T12 Modulation Enable                                              */
      __IOM uint32_t T12MODEN_CC72 : 1;         /*!< [4..4] T12 Modulation Enable                                              */
      __IOM uint32_t T12MODEN_COUT71 : 1;       /*!< [3..3] T12 Modulation Enable                                              */
      __IOM uint32_t T12MODEN_CC71 : 1;         /*!< [2..2] T12 Modulation Enable                                              */
      __IOM uint32_t T12MODEN_COUT70 : 1;       /*!< [1..1] T12 Modulation Enable                                              */
      __IOM uint32_t T12MODEN_CC70 : 1;         /*!< [0..0] T12 Modulation Enable                                              */
    } bit;
  } MODCTR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000F0) Trap Control Register                                      */

    struct
    {
      uint32_t            : 16;

      __IOM uint32_t TRPPEN     : 1;            /*!< [15..15] Trap Pin Enable - TRPPEN                                         */
      __IOM uint32_t TRPEN13    : 1;            /*!< [14..14] Trap Enable Control for Timer T13                                */
      __IOM uint32_t TRPEN      : 6;            /*!< [13..8] Trap Enable Control                                               */
      uint32_t            : 5;
      __IOM uint32_t TRPM2      : 1;
      __IOM uint32_t TRPM1      : 1;            /*!< [1..1] Trap Mode Control Bit 1 - TRPM1                                    */
      __IOM uint32_t TRPM0      : 1;            /*!< [0..0] Trap Mode Control Bit 0 - TRPM0                                    */
    } bit;
  } TRPCTR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000F4) Passive State Level Register                               */

    struct
    {
      uint32_t            : 24;
       __IOM uint32_t PSL73      : 1;            /*!< [7..7] Passive State Level of Output COUT73                               */
      uint32_t            : 1;
      __IOM uint32_t PSL_COUT72 : 1;            /*!< [5..5] Compare Outputs Passive State Level                                */
      __IOM uint32_t PSL_CC72   : 1;            /*!< [4..4] Compare Outputs Passive State Level                                */
      __IOM uint32_t PSL_COUT71 : 1;            /*!< [3..3] Compare Outputs Passive State Level                                */
      __IOM uint32_t PSL_CC71   : 1;            /*!< [2..2] Compare Outputs Passive State Level                                */
      __IOM uint32_t PSL_COUT70 : 1;            /*!< [1..1] Compare Outputs Passive State Level                                */
      __IOM uint32_t PSL_CC70   : 1;            /*!< [0..0] Compare Outputs Passive State Level                                */
    } bit;
  } PSLR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x000000F8) Multi-Channel Mode Output Shadow Register                  */

    struct
    {
      uint32_t            : 16;
      __OM  uint32_t STRHP      : 1;            /*!< [15..15] Shadow Transfer Request for the Hall Pattern - STRHP             */
      uint32_t            : 1;
      __IOM uint32_t CURHS      : 3;            /*!< [13..11] Current Hall Pattern Shadow                                      */
      __IOM uint32_t EXPHS      : 3;            /*!< [10..8] Expected Hall Pattern Shadow                                      */
      __OM  uint32_t STRMCM     : 1;            /*!< [7..7] Shadow Transfer Request for MCMPS - STRMCM                         */
      uint32_t            : 1;
      __IOM uint32_t MCMPS      : 6;            /*!< [5..0] Multi-Channel PWM Pattern Shadow                                   */

    } bit;
  } MCMOUTS;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x000000FC) Multi-Channel Mode Output Register                         */

    struct
    {
      uint32_t            : 18;

      __IM  uint32_t CURH       : 3;            /*!< [13..11] Current Hall Pattern - CURH                                      */
      __IM  uint32_t EXPH       : 3;            /*!< [10..8] Expected Hall Pattern - EXPH                                      */
      uint32_t            : 1;
      __IM  uint32_t R          : 1;            /*!< [6..6] Reminder Flag                                                      */
     __IM  uint32_t MCMP       : 6;            /*!< [5..0] Multi-Channel PWM Pattern                                          */
    } bit;
  } MCMOUT;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000100) Multi-Channel Mode Control Register                        */

    struct
    {
      uint32_t            : 21;
      __IOM uint32_t STE13U     : 1;            /*!< [10..10] Shadow Transfer Enable for T13 Upcounting                        */
      __IOM uint32_t STE12D     : 1;            /*!< [9..9] Shadow Transfer Enable for T12 Downcounting                        */
      __IOM uint32_t STE12U     : 1;            /*!< [8..8] Shadow Transfer Enable for T12 Upcounting                          */
      uint32_t            : 2;
      __IOM uint32_t SWSYN      : 2;            /*!< [5..4] Switching Synchronization                                          */
      uint32_t            : 1;
      __IOM uint32_t SWSEL      : 3;            /*!< [2..0] Switching Selection                                                */
    } bit;
  } MCMCTR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000104) Input Monitoring Register                                  */

    struct
    {

      uint32_t            : 22;

      __IOM uint32_t T13HRI     : 1;            /*!< [9..9] Event indication for input signal T13HR - T13HRI                   */
      __IOM uint32_t T12HRI     : 1;            /*!< [8..8] Event indication for input signal T12HR - T12HRI                   */
      __IOM uint32_t CTRAPI     : 1;            /*!< [7..7] Event indication for input signal CTRAP - CTRAPI                   */
      __IOM uint32_t CC72INI    : 1;            /*!< [6..6] Event indication for input signal CC72IN - CC72INI                 */
      __IOM uint32_t CC71INI    : 1;            /*!< [5..5] Event indication for input signal CC71IN - CC71INI                 */
      __IOM uint32_t CC70INI    : 1;            /*!< [4..4] Event indication for input signal CC70IN - CC70INI                 */
             __IOM uint32_t CCPOS2I    : 1;            /*!< [3..3] Event indication for input signal CCPOS2 - CCPOS2I                 */
      __IOM uint32_t CCPOS1I    : 1;            /*!< [2..2] Event indication for input signal CCPOS1 - CCPOS1I                 */
      __IOM uint32_t CCPOS0I    : 1;            /*!< [1..1] Event indication for input signal CCPOS0 - CCPOS0I                 */
      __IOM uint32_t LBE        : 1;            /*!< [0..0] Lost Bit Event - LBE                                               */
    } bit;
  } IMON;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000108) Lost Indicator Register                                    */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t INPLBE     : 2;            /*!< [15..14] Interrupt Node Pointer for lost bit event - INPLBE               */
      __IOM uint32_t LBEEN      : 1;            /*!< [13..13] Interrupt Enable for Lost Bit Event - LBEEN                      */
      uint32_t            : 3;
      __IOM uint32_t T13HREN    : 1;            /*!< [9..9] Lost Indicator Enable for input signal T13HR - T13HREN             */
      __IOM uint32_t T12HREN    : 1;            /*!< [8..8] Lost Indicator Enable for input signal T12HR - T12HREN             */
      __IOM uint32_t CTRAPEN    : 1;            /*!< [7..7] Lost Indicator Enable for input signal CTRAP - CTRAPEN             */

      __IOM uint32_t CC72INEN   : 1;            /*!< [6..6] Lost Indicator Enable for input signal CC72IN - CC72INEN           */
      __IOM uint32_t CC71INEN   : 1;            /*!< [5..5] Lost Indicator Enable for input signal CC71IN - CC71INEN           */
      __IOM uint32_t CC70INEN   : 1;            /*!< [4..4] Lost Indicator Enable for input signal CC70IN - CC70INEN           */
      __IOM uint32_t CCPOS2EN   : 1;            /*!< [3..3] Lost Indicator Enable for input signal CCPOS2 - CCPOS2EN           */
      __IOM uint32_t CCPOS1EN   : 1;            /*!< [2..2] Lost Indicator Enable for input signal CCPOS1 - CCPOS1EN           */
      __IOM uint32_t CCPOS0EN   : 1;            /*!< [1..1] Lost Indicator Enable for input signal CCPOS0 - CCPOS0EN           */
             uint32_t            : 1;

    } bit;
  } LI;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x0000010C) Capture/Compare Interrupt Status Register 1                */

    struct
    {
      uint32_t            : 16;
      __IM  uint32_t STR        : 1;            /*!< [15..15] Multi-Channel Mode Shadow Transfer Request                       */
      __IM  uint32_t IDLE       : 1;            /*!< [14..14] IDLE State                                                       */
      __IM  uint32_t WHE        : 1;            /*!< [13..13] Wrong Hall Event                                                 */
      __IM  uint32_t CHE        : 1;            /*!< [12..12] Correct Hall Event                                               */
      __IM  uint32_t TRPS       : 1;            /*!< [11..11] Trap State                                                       */
      __IM  uint32_t TRPF       : 1;            /*!< [10..10] Trap Flag                                                        */
      __IM  uint32_t T13PM      : 1;            /*!< [9..9] Timer T13 Period-Match Flag                                        */
      __IM  uint32_t T13CM      : 1;            /*!< [8..8] Timer T13 Compare-Match Flag                                       */
      __IM  uint32_t T12PM      : 1;            /*!< [7..7] Timer T12 Period-Match Flag                                        */
      __IM  uint32_t T12OM      : 1;            /*!< [6..6] Timer T12 One-Match Flag                                           */
      __IM  uint32_t ICC72F     : 1;            /*!< [5..5] Capture, Compare-Match Falling Edge Flag                           */
      __IM  uint32_t ICC72R     : 1;            /*!< [4..4] Capture, Compare-Match Rising Edge Flag                            */
      __IM  uint32_t ICC71F     : 1;            /*!< [3..3] Capture, Compare-Match Falling Edge Flag                           */
      __IM  uint32_t ICC71R     : 1;            /*!< [2..2] Capture, Compare-Match Rising Edge Flag                            */
      __IM  uint32_t ICC70F     : 1;            /*!< [1..1] Capture, Compare-Match Falling Edge Flag                           */
      __IM  uint32_t ICC70R     : 1;            /*!< [0..0] Capture, Compare-Match Rising Edge Flag                            */

    } bit;
  } IS;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000110) Capture/Compare Interrupt Status Set Register
                                                                    1                                                          */

    struct
    {
      uint32_t            : 16;
      __OM  uint32_t SSTR       : 1;            /*!< [15..15] Set STR Flag                                                     */
      __OM  uint32_t SIDLE      : 1;            /*!< [14..14] Set IDLE Flag                                                    */
      __OM  uint32_t SWHE       : 1;            /*!< [13..13] Set Wrong Hall Event Flag                                        */
      __OM  uint32_t SCHE       : 1;            /*!< [12..12] Set Correct Hall Event Flag                                      */
      __OM  uint32_t SWHC       : 1;            /*!< [11..11] Software Hall Compare                                            */
      __OM  uint32_t STRPF      : 1;            /*!< [10..10] Set Trap Flag                                                    */
      __OM  uint32_t ST13PM     : 1;            /*!< [9..9] Set Timer T13 Period-Match Flag                                    */
      __OM  uint32_t ST13CM     : 1;            /*!< [8..8] Set Timer T13 Compare-Match Flag                                   */
      __OM  uint32_t ST12PM     : 1;            /*!< [7..7] Set Timer T12 Period-Match Flag                                    */
      __OM  uint32_t ST12OM     : 1;            /*!< [6..6] Set Timer T12 One-Match Flag                                       */
      __OM  uint32_t SCC72F     : 1;            /*!< [5..5] Set Capture, Compare-Match Falling Edge Flag                       */
      __OM  uint32_t SCC72R     : 1;            /*!< [4..4] Set Capture, Compare-Match Rising Edge Flag                        */
      __OM  uint32_t SCC71F     : 1;            /*!< [3..3] Set Capture, Compare-Match Falling Edge Flag                       */
      __OM  uint32_t SCC71R     : 1;            /*!< [2..2] Set Capture, Compare-Match Rising Edge Flag                        */
      __OM  uint32_t SCC70F     : 1;            /*!< [1..1] Set Capture, Compare-Match Falling Edge Flag                       */
      __OM  uint32_t SCC70R     : 1;            /*!< [0..0] Set Capture, Compare-Match Rising Edge Flag                        */

    } bit;
  } ISS;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000114) Capture/Compare Interrupt Status Reset Register
                                                                    1                                                          */

    struct
    {
      uint32_t            : 16;
       __OM  uint32_t RSTR       : 1;            /*!< [15..15] Reset STR Flag                                                   */
      __OM  uint32_t RIDLE      : 1;            /*!< [14..14] Reset IDLE Flag                                                  */
      __OM  uint32_t RWHE       : 1;            /*!< [13..13] Reset Wrong Hall Event Flag                                      */
      __OM  uint32_t RCHE       : 1;            /*!< [12..12] Reset Correct Hall Event Flag                                    */
      uint32_t            : 1;
      __OM  uint32_t RTRPF      : 1;            /*!< [10..10] Reset Trap Flag                                                  */
      __OM  uint32_t RT13PM     : 1;            /*!< [9..9] Reset Timer T13 Period-Match Flag                                  */
      __OM  uint32_t RT13CM     : 1;            /*!< [8..8] Reset Timer T13 Compare-Match Flag                                 */
      __OM  uint32_t RT12PM     : 1;            /*!< [7..7] Reset Timer T12 Period-Match Flag                                  */
      __OM  uint32_t RT12OM     : 1;            /*!< [6..6] Reset Timer T12 One-Match Flag                                     */
      __OM  uint32_t RCC72F     : 1;            /*!< [5..5] Reset Capture, Compare-Match Falling Edge Flag                     */
      __OM  uint32_t RCC72R     : 1;            /*!< [4..4] Reset Capture, Compare-Match Rising Edge Flag                      */
      __OM  uint32_t RCC71F     : 1;            /*!< [3..3] Reset Capture, Compare-Match Falling Edge Flag                     */
      __OM  uint32_t RCC71R     : 1;            /*!< [2..2] Reset Capture, Compare-Match Rising Edge Flag                      */
      __OM  uint32_t RCC70F     : 1;            /*!< [1..1] Reset Capture, Compare-Match Falling Edge Flag                     */
      __OM  uint32_t RCC70R     : 1;            /*!< [0..0] Reset Capture, Compare-Match Rising Edge Flag                      */

    } bit;
  } ISR;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000118) Capture/Compare Interrupt Node Pointer Register
                                                                    1                                                          */

    struct
    {
         uint32_t            : 18;
      __IOM uint32_t INPT13     : 2;            /*!< [13..12] Interrupt Node Pointer for Timer T13 Interrupts                  */
      __IOM uint32_t INPT12     : 2;            /*!< [11..10] Interrupt Node Pointer for Timer T12 Interrupts                  */
      __IOM uint32_t INPERR     : 2;            /*!< [9..8] Interrupt Node Pointer for Error Interrupts                        */
      __IOM uint32_t INPCHE     : 2;            /*!< [7..6] Interrupt Node Pointer for the CHE Interrupt                       */
      __IOM uint32_t INPCC72    : 2;            /*!< [5..4] Interrupt Node Pointer for Channel 2 Interrupts                    */
      __IOM uint32_t INPCC71    : 2;            /*!< [3..2] Interrupt Node Pointer for Channel 1 Interrupts                    */
      __IOM uint32_t INPCC70    : 2;            /*!< [1..0] Interrupt Node Pointer for Channel 0 Interrupts                    */
    } bit;
  } INP;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000011C) Capture/Compare Interrupt Enable Register 1                */

    struct
    {

      uint32_t            : 16;

      __IOM uint32_t ENSTR      : 1;            /*!< [15..15] Enable Multi-Channel Mode Shadow Transfer Interrupt              */
      __IOM uint32_t ENIDLE     : 1;            /*!< [14..14] Enable Idle                                                      */
      __IOM uint32_t ENWHE      : 1;            /*!< [13..13] Enable Interrupt for Wrong Hall Event                            */
      __IOM uint32_t ENCHE      : 1;            /*!< [12..12] Enable Interrupt for Correct Hall Event                          */
      uint32_t            : 1;
      __IOM uint32_t ENTRPF     : 1;            /*!< [10..10] Enable Interrupt for Trap Flag                                   */
      __IOM uint32_t ENT13PM    : 1;            /*!< [9..9] Enable Interrupt for T13 Period-Match                              */
      __IOM uint32_t ENT13CM    : 1;            /*!< [8..8] Enable Interrupt for T13 Compare-Match                             */
      __IOM uint32_t ENT12PM    : 1;            /*!< [7..7] Enable Interrupt for T12 Period-Match                              */
      __IOM uint32_t ENT12OM    : 1;            /*!< [6..6] Enable Interrupt for T12 One-Match                                 */

      __IOM uint32_t ENCC72F    : 1;            /*!< [5..5] Capture, Compare-Match Falling Edge Interrupt Enable for Channel 2*/

      __IOM uint32_t ENCC72R    : 1;            /*!< [4..4] Capture, Compare-Match Rising Edge Interrupt Enable for Channel 2*/

      __IOM uint32_t ENCC71F    : 1;            /*!< [3..3] Capture, Compare-Match Falling Edge Interrupt Enable for Channel 1*/

      __IOM uint32_t ENCC71R    : 1;            /*!< [2..2] Capture, Compare-Match Rising Edge Interrupt Enable for Channel 1*/

      __IOM uint32_t ENCC70F    : 1;            /*!< [1..1] Capture, Compare-Match Falling Edge Interrupt Enable for Channel 0*/
      __IOM uint32_t ENCC70R    : 1;            /*!< [0..0] Capture, Compare-Match Rising Edge Interrupt Enable for Channel 0*/

    } bit;
  } IEN;

  union
  {
    __IM  uint32_t reg;                         /*!< (@ 0x00000120) Capture/Compare Interrupt Status Register 2                */

    struct
    {
      uint32_t            : 18;
      __IM  uint32_t T16PM      : 1;            /*!< [13..13] Timer T16 Period-Match Flag                                      */
      __IM  uint32_t T16CM      : 1;            /*!< [12..12] Timer T16 Compare-Match Flag                                     */
      __IM  uint32_t T15PM      : 1;            /*!< [11..11] Timer T15 Period-Match Flag                                      */
      __IM  uint32_t T15CM      : 1;            /*!< [10..10] Timer T15 Compare-Match Flag                                     */
      __IM  uint32_t T14PM      : 1;            /*!< [9..9] Timer T14 Period-Match Flag                                        */
      __IM  uint32_t T14CM      : 1;            /*!< [8..8] Timer T14 Compare-Match Flag                                       */
      uint32_t            : 2;
      __IM  uint32_t ICC72BF    : 1;            /*!< [5..5] Capture, Compare-Match Falling Edge Flag                           */
      __IM  uint32_t ICC72BR    : 1;            /*!< [4..4] Capture, Compare-Match Rising Edge Flag                            */
      __IM  uint32_t ICC71BF    : 1;            /*!< [3..3] Capture, Compare-Match Falling Edge Flag                           */
      __IM  uint32_t ICC71BR    : 1;            /*!< [2..2] Capture, Compare-Match Rising Edge Flag                            */
      __IM  uint32_t ICC70BF    : 1;            /*!< [1..1] Capture, Compare-Match Falling Edge Flag                           */
      __IM  uint32_t ICC70BR    : 1;            /*!< [0..0] Capture, Compare-Match Rising Edge Flag                            */

    } bit;
  } IS_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000124) Capture/Compare Interrupt Status Set Register
                                                                    2                                                          */

    struct
    {
      uint32_t            : 18;
      __OM  uint32_t ST16PM     : 1;            /*!< [13..13] Set Timer T16 Period-Match Flag                                  */
      __OM  uint32_t ST16CM     : 1;            /*!< [12..12] Set Timer T16 Compare-Match Flag                                 */
      __OM  uint32_t ST15PM     : 1;            /*!< [11..11] Set Timer T15 Period-Match Flag                                  */
      __OM  uint32_t ST15CM     : 1;            /*!< [10..10] Set Timer T15 Compare-Match Flag                                 */
      __OM  uint32_t ST14PM     : 1;            /*!< [9..9] Set Timer T14 Period-Match Flag                                    */
      __OM  uint32_t ST14CM     : 1;            /*!< [8..8] Set Timer T14 Compare-Match Flag                                   */
      uint32_t            : 2;
      __OM  uint32_t SCC72BF    : 1;            /*!< [5..5] Set Capture, Compare-Match Falling Edge Flag                       */
      __OM  uint32_t SCC72BR    : 1;            /*!< [4..4] Set Capture, Compare-Match Rising Edge Flag                        */
      __OM  uint32_t SCC71BF    : 1;            /*!< [3..3] Set Capture, Compare-Match Falling Edge Flag                       */
      __OM  uint32_t SCC71BR    : 1;            /*!< [2..2] Set Capture, Compare-Match Rising Edge Flag                        */
      __OM  uint32_t SCC70BF    : 1;            /*!< [1..1] Set Capture, Compare-Match Falling Edge Flag                       */
      __OM  uint32_t SCC70BR    : 1;            /*!< [0..0] Set Capture, Compare-Match Rising Edge Flag                        */

    } bit;
  } ISS_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000128) Capture/Compare Interrupt Status Reset Register
                                                                    2                                                          */

    struct
    {
        uint32_t            : 18;
      __OM  uint32_t RT16PM     : 1;            /*!< [13..13] Reset Timer T16 Period-Match Flag                                */
      __OM  uint32_t RT16CM     : 1;            /*!< [12..12] Reset Timer T16 Compare-Match Flag                               */
      __OM  uint32_t RT15PM     : 1;            /*!< [11..11] Reset Timer T15 Period-Match Flag                                */
      __OM  uint32_t RT15CM     : 1;            /*!< [10..10] Reset Timer T15 Compare-Match Flag                               */
      __OM  uint32_t RT14PM     : 1;            /*!< [9..9] Reset Timer T14 Period-Match Flag                                  */
      __OM  uint32_t RT14CM     : 1;            /*!< [8..8] Reset Timer T14 Compare-Match Flag                                 */
      uint32_t            : 2;
      __OM  uint32_t RCC72BF    : 1;            /*!< [5..5] Reset Capture, Compare-Match Falling Edge Flag                     */
      __OM  uint32_t RCC72BR    : 1;            /*!< [4..4] Reset Capture, Compare-Match Rising Edge Flag                      */
      __OM  uint32_t RCC71BF    : 1;            /*!< [3..3] Reset Capture, Compare-Match Falling Edge Flag                     */
      __OM  uint32_t RCC71BR    : 1;            /*!< [2..2] Reset Capture, Compare-Match Rising Edge Flag                      */
      __OM  uint32_t RCC70BF    : 1;            /*!< [1..1] Reset Capture, Compare-Match Falling Edge Flag                     */
    __OM  uint32_t RCC70BR    : 1;            /*!< [0..0] Reset Capture, Compare-Match Rising Edge Flag                      */

    } bit;
  } ISR_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000012C) Capture/Compare Interrupt Node Pointer Register
                                                                    2                                                          */

    struct
    {
      uint32_t            : 18;
      __IOM uint32_t INPT16     : 2;            /*!< [13..12] Interrupt Node Pointer for Timer T16 Interrupts                  */
      __IOM uint32_t INPT15     : 2;            /*!< [11..10] Interrupt Node Pointer for Timer T15 Interrupts                  */
      __IOM uint32_t INPT14     : 2;            /*!< [9..8] Interrupt Node Pointer for Timer T14 Interrupts                    */
      uint32_t            : 2;
      __IOM uint32_t INPCC72B   : 2;            /*!< [5..4] Interrupt Node Pointer for Channel 2 Interrupts                    */
      __IOM uint32_t INPCC71B   : 2;            /*!< [3..2] Interrupt Node Pointer for Channel 1 Interrupts                    */
      __IOM uint32_t INPCC70B   : 2;            /*!< [1..0] Interrupt Node Pointer for Channel 0 Interrupts                    */

    } bit;
  } INP_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000130) Capture/Compare Interrupt Enable Register 2                */

    struct
    {
      uint32_t            : 18;
      __IOM uint32_t ENT16PM    : 1;            /*!< [13..13] Enable Interrupt for T16 Period-Match                            */
      __IOM uint32_t ENT16CM    : 1;            /*!< [12..12] Enable Interrupt for T16 Compare-Match                           */
      __IOM uint32_t ENT15PM    : 1;            /*!< [11..11] Enable Interrupt for T15 Period-Match                            */
      __IOM uint32_t ENT15CM    : 1;            /*!< [10..10] Enable Interrupt for T15 Compare-Match                           */
      __IOM uint32_t ENT14PM    : 1;            /*!< [9..9] Enable Interrupt for T14 Period-Match                              */
      __IOM uint32_t ENT14CM    : 1;            /*!< [8..8] Enable Interrupt for T14 Compare-Match                             */
      uint32_t            : 2;

      __IOM uint32_t ENCC72BF   : 1;            /*!< [5..5] Capture, Compare-Match Falling Edge Interrupt Enable  for Channel 2 */

      __IOM uint32_t ENCC72BR   : 1;            /*!< [4..4] Capture, Compare-Match Rising Edge Interrupt Enable for Channel 2 */

      __IOM uint32_t ENCC71BF   : 1;            /*!< [3..3] Capture, Compare-Match Falling Edge Interrupt Enable for Channel 1 */

      __IOM uint32_t ENCC71BR   : 1;            /*!< [2..2] Capture, Compare-Match Rising Edge Interrupt Enable for  Channel 1 */

      __IOM uint32_t ENCC70BF   : 1;            /*!< [1..1] Capture, Compare-Match Falling Edge Interrupt Enable for Channel 0 */
      __IOM uint32_t ENCC70BR   : 1;            /*!< [0..0] Capture, Compare-Match Rising Edge Interrupt Enable for Channel 0 */

    } bit;
  } IEN_2;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000134) OCDS Control and Status Register                           */

    struct
    {
      uint32_t            : 2;
      __IM  uint32_t SUSSTA     : 1;            /*!< [29..29] Suspend State - SUSSTA                                           */
      __OM  uint32_t SUS_P      : 1;            /*!< [28..28] SUS Write Protection - SUS_P                                     */
      __IOM uint32_t SUS        : 4;            /*!< [27..24] OCDS Suspend Control - SUS                                       */
      uint32_t            : 24;

    } bit;
  } OCS;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000138) Fractional Divider0                                        */

    struct
    {
      uint32_t            : 16;
      __IOM uint32_t PQ         : 16;           /*!< [15..0] PQ                                                                */
    } bit;
  } T_FDIV0;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x0000013C) Fractional Divider1                                        */

    struct
    {

      uint32_t            : 16;
      __IOM uint32_t PQ         : 16;           /*!< [15..0] PQ                                                                */
    } bit;
  } T_FDIV1;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000140) Timer Clock Selection                                      */

    struct
    {
      uint32_t            : 18;
      __IOM uint32_t FDIV1_SEL  : 1;            /*!< [13..13] FDIV1 Mode Selection                                             */
      __IOM uint32_t FDIV0_SEL  : 1;            /*!< [12..12] FDIV0 Mode Selection                                             */
      __IOM uint32_t DT_CLK_SEL : 2;            /*!< [11..10] Clock Selector for dead time control                             */
      __IOM uint32_t T16_CLK_SEL : 2;           /*!< [9..8] Clock selector for Timer 16                                        */
      __IOM uint32_t T15_CLK_SEL : 2;           /*!< [7..6] Clock selector for Timer 15                                        */
      __IOM uint32_t T14_CLK_SEL : 2;           /*!< [5..4] Clock selector for Timer 14                                        */
      __IOM uint32_t T13_CLK_SEL : 2;           /*!< [3..2] Clock selector for Timer 13                                        */
      __IOM uint32_t T12_CLK_SEL : 2;           /*!< [1..0] Clock selector for Timer 12                                        */

    } bit;
  } T_CLK_CTRL;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000144) Timer Control Register 3                                   */

    struct
    {
        uint32_t            : 19;
      __OM  uint32_t T16STD     : 1;            /*!< [12..12] Timer T16 Shadow Transfer Disable                                */
      __OM  uint32_t T15STD     : 1;            /*!< [11..11] Timer T15 Shadow Transfer Disable                                */
      __OM  uint32_t T14STD     : 1;            /*!< [10..10] Timer T14 Shadow Transfer Disable                                */
      __OM  uint32_t T13STD     : 1;            /*!< [9..9] Timer T13 Shadow Transfer Disable                                  */
      __OM  uint32_t T12STD     : 1;            /*!< [8..8] Timer T12 Shadow Transfer Disable                                  */
      uint32_t            : 3;
      __OM  uint32_t T16STR     : 1;            /*!< [4..4] Timer T16 Shadow Transfer Request                                  */
      __OM  uint32_t T15STR     : 1;            /*!< [3..3] Timer T15 Shadow Transfer Request                                  */
      __OM  uint32_t T14STR     : 1;            /*!< [2..2] Timer T14 Shadow Transfer Request                                  */
      __OM  uint32_t T13STR     : 1;            /*!< [1..1] Timer T13 Shadow Transfer Request                                  */
    __OM  uint32_t T12STR     : 1;            /*!< [0..0] Timer T12 Shadow Transfer Request                                  */

    } bit;
  } TCTR3;

  union
  {
    __IOM uint32_t reg;                         /*!< (@ 0x00000148) Interupt gating Register                                   */

    struct
    {
      uint32_t            : 18;
      __IOM uint32_t GT3        : 2;            /*!< [13..12] Gating SR3                                                       */
      uint32_t            : 2;
      __IOM uint32_t GT2        : 2;            /*!< [9..8] Gating SR2                                                         */
      uint32_t            : 2;
      __IOM uint32_t GT1        : 2;            /*!< [5..4] Gating SR1                                                         */
      uint32_t            : 2;
      __IOM uint32_t GT0        : 2;            /*!< [1..0] Gating SR0                                                         */

    } bit;
  } IGT;
};

/* =========================================================================================================================== */
/* ================                                           CCU7                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  CMPSTAT  ======================================================== */
#define CCU7_CMPSTAT_CCPOS0_Pos           (3UL)                     /*!< CCPOS0 (Bit 3)                                        */
#define CCU7_CMPSTAT_CCPOS0_Msk           (0x8UL)                   /*!< CCPOS0 (Bitfield-Mask: 0x01)                          */
#define CCU7_CMPSTAT_CCPOS1_Pos           (4UL)                     /*!< CCPOS1 (Bit 4)                                        */
#define CCU7_CMPSTAT_CCPOS1_Msk           (0x10UL)                  /*!< CCPOS1 (Bitfield-Mask: 0x01)                          */
#define CCU7_CMPSTAT_CCPOS2_Pos           (5UL)                     /*!< CCPOS2 (Bit 5)                                        */
#define CCU7_CMPSTAT_CCPOS2_Msk           (0x20UL)                  /*!< CCPOS2 (Bitfield-Mask: 0x01)                          */
/* ==========================================================  INP  ========================================================== */
#define CCU7_INP_INPCC70_Pos              (0UL)                     /*!< INPCC70 (Bit 0)                                       */
#define CCU7_INP_INPCC70_Msk              (0x3UL)                   /*!< INPCC70 (Bitfield-Mask: 0x03)                         */
#define CCU7_INP_INPCC71_Pos              (2UL)                     /*!< INPCC71 (Bit 2)                                       */
#define CCU7_INP_INPCC71_Msk              (0xcUL)                   /*!< INPCC71 (Bitfield-Mask: 0x03)                         */
#define CCU7_INP_INPCC72_Pos              (4UL)                     /*!< INPCC72 (Bit 4)                                       */
#define CCU7_INP_INPCC72_Msk              (0x30UL)                  /*!< INPCC72 (Bitfield-Mask: 0x03)                         */
#define CCU7_INP_INPCHE_Pos               (6UL)                     /*!< INPCHE (Bit 6)                                        */
#define CCU7_INP_INPCHE_Msk               (0xc0UL)                  /*!< INPCHE (Bitfield-Mask: 0x03)                          */
#define CCU7_INP_INPERR_Pos               (8UL)                     /*!< INPERR (Bit 8)                                        */
#define CCU7_INP_INPERR_Msk               (0x300UL)                 /*!< INPERR (Bitfield-Mask: 0x03)                          */
#define CCU7_INP_INPT12_Pos               (10UL)                    /*!< INPT12 (Bit 10)                                       */
#define CCU7_INP_INPT12_Msk               (0xc00UL)                 /*!< INPT12 (Bitfield-Mask: 0x03)                          */
#define CCU7_INP_INPT13_Pos               (12UL)                    /*!< INPT13 (Bit 12)                                       */
#define CCU7_INP_INPT13_Msk               (0x3000UL)                /*!< INPT13 (Bitfield-Mask: 0x03)                          */
/* =========================================================  INP_2  ========================================================= */
#define CCU7_INP_2_INPCC70B_Pos           (0UL)                     /*!< INPCC70B (Bit 0)                                      */
#define CCU7_INP_2_INPCC70B_Msk           (0x3UL)                   /*!< INPCC70B (Bitfield-Mask: 0x03)                        */
#define CCU7_INP_2_INPCC71B_Pos           (2UL)                     /*!< INPCC71B (Bit 2)                                      */
#define CCU7_INP_2_INPCC71B_Msk           (0xcUL)                   /*!< INPCC71B (Bitfield-Mask: 0x03)                        */
#define CCU7_INP_2_INPCC72B_Pos           (4UL)                     /*!< INPCC72B (Bit 4)                                      */
#define CCU7_INP_2_INPCC72B_Msk           (0x30UL)                  /*!< INPCC72B (Bitfield-Mask: 0x03)                        */
#define CCU7_INP_2_INPT14_Pos             (8UL)                     /*!< INPT14 (Bit 8)                                        */
#define CCU7_INP_2_INPT14_Msk             (0x300UL)                 /*!< INPT14 (Bitfield-Mask: 0x03)                          */
#define CCU7_INP_2_INPT15_Pos             (10UL)                    /*!< INPT15 (Bit 10)                                       */
#define CCU7_INP_2_INPT15_Msk             (0xc00UL)                 /*!< INPT15 (Bitfield-Mask: 0x03)                          */
#define CCU7_INP_2_INPT16_Pos             (12UL)                    /*!< INPT16 (Bit 12)                                       */
#define CCU7_INP_2_INPT16_Msk             (0x3000UL)                /*!< INPT16 (Bitfield-Mask: 0x03)                          */
/* ==========================================================  LI  =========================================================== */
#define CCU7_LI_INPLBE_Pos                (14UL)                    /*!< INPLBE (Bit 14)                                       */
#define CCU7_LI_INPLBE_Msk                (0xc000UL)                /*!< INPLBE (Bitfield-Mask: 0x03)                          */

#endif /* CCU7_REG_H_ */
