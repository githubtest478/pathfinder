#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char box[len];
    
    for(size_t i = 0; i < len; ++i) {
        box[i] = *((char*)src + i);
    }
    for(size_t i = 0; i < len; ++i) {
        if(*(char*)dst + i) {
            *((char*)dst + i) = box[i];
        }
        else {
            return dst;
        }
    }
    return dst;
}
