#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if(str == NULL || sub == NULL) {
        return -1;
    }
    if(mx_strlen(sub) == 0) {
        return 0;
    }
    int i = 0, count = 0;

    while(str[i]) {
        if(str[i] == sub[0]) {
           if(mx_strncmp(sub, &str[i], mx_strlen(sub)) == 0) {
               ++count;
           }
        }
        ++i;
    }
    return count;
}

