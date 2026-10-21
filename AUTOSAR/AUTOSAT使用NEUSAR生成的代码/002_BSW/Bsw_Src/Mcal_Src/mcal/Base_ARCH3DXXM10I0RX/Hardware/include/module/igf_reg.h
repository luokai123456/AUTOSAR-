#ifndef IGF_REG_H_
#define IGF_REG_H_

/* ============================================================================
   =============================== Module: IGF ===============================
   ============================================================================ */

typedef union IGF_CTRL_union_tag {
   vuint32_t R;
   struct {
 	  vuint8_t  :3;
     vuint8_t CTR_FE0:1;
 	  vuint8_t MODE_FE0:1;
     vuint8_t CTR_RE0:1;
     vuint8_t MODE_RE0:1;
     vuint8_t FLT_EN0:1;
 	  vuint8_t  :3;
     vuint8_t CTR_FE1:1;
 	  vuint8_t MODE_FE1:1;
     vuint8_t CTR_RE1:1;
     vuint8_t MODE_RE1:1;
     vuint8_t FLT_EN1:1;
 	  vuint8_t  :3;
     vuint8_t CTR_FE2:1;
 	  vuint8_t MODE_FE2:1;
     vuint8_t CTR_RE2:1;
     vuint8_t MODE_RE2:1;
     vuint8_t FLT_EN2:1;
 	  vuint8_t  :3;
     vuint8_t CTR_FE3:1;
 	  vuint8_t MODE_FE3:1;
     vuint8_t CTR_RE3:1;
     vuint8_t MODE_RE3:1;
     vuint8_t FLT_EN3:1;

   } B;
 } IGF_CTRL_tag;

 typedef union IGF_FCNT_union_tag {
   vuint32_t R;
   struct {
     vuint32_t  :8;
     vuint32_t FLT_FE_CNT:24;
   } B;
 } IGF_FCNT_tag;

 typedef union IGF_RCNT_union_tag {
 	  vuint32_t R;
 	  struct {
 	    vuint32_t  :8;
 	    vuint32_t FLT_RE_CNT:24;
 	  } B;
 } IGF_RCNT_tag;

 typedef union IGF_DIV_union_tag {
   vuint32_t R;
   struct {
     vuint32_t DIV:32;
   } B;
 } IGF_DIV_tag;

 struct IGF_tag {
	IGF_RCNT_tag IGF_RCNT[76];
 	IGF_FCNT_tag IGF_FCNT[76];
 	IGF_CTRL_tag IGF_CTRL[19];
 	IGF_DIV_tag  IGF_DIV[76];
 };

#endif
