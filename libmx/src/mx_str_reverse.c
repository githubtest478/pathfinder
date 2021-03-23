#include "libmx.h"

//int mx_strlen(const char *s);
//void mx_swap_char(char *s1, char *s2);

void mx_str_reverse(char *s) {
    if(!s) {
        return;
    }
    int leng = mx_strlen(s);

    for(int i = 0; i < leng / 2; ++i) {
        mx_swap_char(&s[i], &s[leng - 1 - i]);
    }
}
