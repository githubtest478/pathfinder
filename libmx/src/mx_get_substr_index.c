#include "libmx.h"

//int mx_strlen(const char *s);
//int mx_strncmp (const char *s1, const char *s2, int n);


int mx_get_substr_index(const char *str, const char *sub) {
    if(str == NULL || sub == NULL) {
        return -2;
    }
    //int result = 0;
    int lend_sub = mx_strlen(sub);
    int index = 0;

    while(*str) {
        if(*str == sub[0]) {
            if(!mx_strncmp(str, sub, lend_sub)) {
                return index;
            }
        }
        ++index;
        ++str;
    }
    return -1;
}
