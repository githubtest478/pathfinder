#include "libmx.h"

//bool mx_isspace(char c);
//int mx_strlen(const char *s);
//char *mx_strnew(const int size);
//char *mx_strncpy(char *dst, const char *src, int len);
//char *mx_strtrim(const char *str)

//void mx_strdel(char **str);

char *mx_del_extra_spaces(const char *str) {
    if(str == NULL) {
        return NULL;
    }
    char *new_str = mx_strtrim(str);
    int count = 0, count1 = 0, leng = 0;

    while(new_str[count]) {
        if(mx_isspace(new_str[count])) {
            new_str[count1] = ' ';
            ++count1;
        }
        else {
            new_str[count1] = new_str[count];
            ++count1;
            ++count;
            continue;
        }
        while(new_str[count] && mx_isspace(new_str[count])) {
            count++;
        }
    }
    new_str[count1] = '\0';
    leng = mx_strlen(new_str);

    char * ret_str = mx_strnew(leng);

    ret_str = mx_strncpy(ret_str, new_str, leng + 1);
    mx_strdel(&new_str); 
    return ret_str;
}

