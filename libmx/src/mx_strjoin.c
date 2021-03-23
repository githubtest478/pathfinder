#include "libmx.h"

//int mx_strlen(const char *s);
//char *mx_strnew(const int size);
//char *mx_strcat(char *restrict s1, const char *restrict s2);

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL)
    {
        if (s1 == NULL && s2 == NULL)
        {
            return NULL;     
        }   
        int leng = s1 == NULL ? mx_strlen(s2) : mx_strlen(s1);
        char *s3 = mx_strnew(leng);

        s1 == NULL ? mx_strcat(s3, s2) : mx_strcat(s3, s1);
        return s3;
    }
    int leng = mx_strlen(s1) + mx_strlen(s2);
    char *s3 = mx_strnew(leng);

    mx_strcat(s3, s1);
    mx_strcat(s3, s2);
    return s3;
 }

