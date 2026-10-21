#include "SecuCommon.h"


boolean Secu_Memcmp(uint8 *dst, uint8 *src, uint32 count) {
    uint32 i;
    boolean ret = TRUE;

    if( (dst != NULL_PTR) && (src != NULL_PTR) && (count != 0UL) ) {
        for (i = 0UL; i < count; i++) {
            if ((uint32)dst[i] != (uint32)src[i]) {
                ret = FALSE;
                break;
            } else {
                // Do nothing
            }
        }
    } else {
        ret = FALSE;
    }

    return ret;
}


void Secu_Memset(uint8 *dst, uint8 value, uint32 count) {
    uint32 i;

    if( (dst != NULL_PTR) && (count != 0UL) ) {
        for( i = 0UL; i < count; i++ ) {
            dst[i] = value;
        }
    } else {
        // Do nothing
    }
}
