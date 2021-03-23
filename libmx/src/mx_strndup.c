#include "libmx.h"

// int mx_strlen(const char *s);
// char *mx_strnew(const int size);

char *mx_strndup(const char *s1, size_t n) {
    size_t length = mx_strlen(s1);
    if(n < length) {
        length = n;
    }
    char *new_str = mx_strnew(length);
    
    if(new_str == NULL) {
        return NULL;
    }
    mx_strncpy(new_str, s1, length);
    return new_str;
}
