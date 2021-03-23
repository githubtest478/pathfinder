#include "libmx.h"

//   int mx_strlen(const char *s);
//   char *mx_strnew(const int size);

char *mx_strdup(const char *s1) {
    int leng = mx_strlen(s1);
    char *new_str = mx_strnew(leng);

    if(new_str == NULL) {
        return NULL;
    }
    for (int i = 0; i < leng; i++)
    {
        new_str[i] = s1[i];
    }
    return new_str;
}

