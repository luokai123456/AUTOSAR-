/* PRQA S 0602 EOF */
#ifndef _HSM_REG_H_
#define _HSM_REG_H_

struct HSM_tag
{
    vuint32_t HSM_FLAG;
    vuint32_t HOST_IE_ENABLE;
    vuint32_t HOST_FLAG;
    vuint32_t HSM_IE_ENABLE;
    vuint32_t HSM_STATUS;
    vuint32_t HOST_STATUS;
    vuint32_t ALG_PARAM[11];
} ;
#endif
