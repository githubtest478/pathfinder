#include "libmx.h"

// int mx_strlen(const char *s)

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int start_s1 = mx_strlen(s1);
    int i = 0;

    while (s2[i]){     
        s1[start_s1] = s2[i];
        ++i;
        ++start_s1;
    }
    s1[start_s1] = '\0';
    return s1;
}
