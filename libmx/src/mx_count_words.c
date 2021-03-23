#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if(str == NULL) {
        return -1;
    }
    int count = 0;

    while(*str) {
        if(*str == c) {
            while(*str == c && *str) {
                ++str;
            }
            continue;
        }
        if(*str != c) {
            ++count;
            while(*str != c && *str) {
                ++str;
            }
        }
    }
    return count;
}

