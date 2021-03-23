#include "libmx.h"

int mx_sqrt(int x) {
    int count = 1;

    if (x == 1) {
        return 1;
    }
    for (int i = count; i <= x/2; i++) {
        if (i * i == x) {
            return i;
        }
    }    
    return 0;
}

