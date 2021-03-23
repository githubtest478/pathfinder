#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if(n == 0) {
        return 0;
    }
    int compe;

    for(size_t i = 0; i < n; ++i) {
        compe = *((char*) s1 + i) - *((char*) s2 + i);

        if(compe == 0){
            continue;
        }
        else {
            return *((char*) s1 + i) - *((char*) s2 + i);
        }
    }
    return compe;
}

