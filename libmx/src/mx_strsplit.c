#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if(s == NULL) {
        return NULL;
    } 
    int index = 0;
    int i = mx_count_words(s, c);
    char **arr_str = (char**)malloc((i + 1) * sizeof(char*));
    int in = 0;

    while(*(s + in)) {
        if(*(s + in) == c) {
            while(*(s + in) == c && *(s + in)) {
                ++in;
            }
            continue;
        }
        if(*(s + in) && *(s + in) != c) {
            int local = 0;
            while(*(s + in) != c && *(s + in)) {
                ++in, ++local;
            }
            *(arr_str + index) = mx_strnew(local);
            *(arr_str + index) = mx_strncpy(*(arr_str + index), &s[in - local], local);
            index++;
        }   
    }
    arr_str[index] = NULL;
    return arr_str;
}

