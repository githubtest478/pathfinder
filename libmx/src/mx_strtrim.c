#include "libmx.h"

//void mx_strdel(char **str);

//int mx_strlen(const char *s);
//char *mx_strnew(const int size);
//char *mx_strncpy(char *dst, const char *src, int len);
//bool mx_isspace(char c);
//int mx_strncmp (const char *s1, const char *s2, int n);

char *mx_strtrim(const char *str) {
    if(str == NULL) {
        return NULL;
    }
    int point = 0;
    int count1 = 0;
    int count2 = mx_strlen(str) - 1;
    
    while(str[point] && mx_isspace(str[point])) {
        ++point;
    }
    count1 = point;
    while(str[count2] && mx_isspace(str[count2])) {
        --count2;
    }
    if((count2 - count1 + 1) < 0) {
        char *new_str = mx_strnew(0); 
        return new_str;
    }
    char *new_str = mx_strnew(count2 - count1 + 1); 

    new_str = mx_strncpy(new_str, &str[count1], count2 - count1 + 1);
    return new_str;
}
