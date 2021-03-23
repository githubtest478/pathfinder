#include "libmx.h"

// int mx_strlen(const char *s);
// char *mx_strnew(const int size);
// int mx_strncmp (const char *s1, const char *s2, int n);


char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(!sub || !replace || !str) {
        return NULL;
    }

    int i = 0, i1 = 0, leng = mx_strlen(str), leng1 = mx_strlen(sub);
    char *new_str = mx_strnew(leng);

    while(str[i]) {
        if(mx_strncmp(sub, &str[i], leng1) == 0) {
            int y = 0;
            while(replace[y]) {
                new_str[i1] = replace[y];
                ++y, ++i1;
            }
            i += leng1;
        }
        else {
            new_str[i1] = str[i];
            ++i1, ++i;
        }
    }
    new_str[i1] = '\0';
    return new_str;
}

