#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    for(int i = (int)n - 1; i > -1; --i) {
        if(*((char*)s + i) == c) {
            return (char*)s + i;
        }
    }
    return NULL;
}
