#include "libmx.h"

static char *mx_strchr(const char *s, int c);
//int mx_strlen(const char *s);
//int mx_strncmp (const char *s1, const char *s2, int n);

char *mx_strstr(const char *haystack, const char *needle) {
    if (mx_strlen(needle) == 0) {
        return (char *)haystack;
    }    
    else {
        while (mx_strchr(haystack, *needle)) {            
            if (mx_strncmp(haystack, needle, mx_strlen(needle)) == 0) {
                return (char *)haystack;
            } 
            haystack++;
        }
        return (char *)haystack ;
    }
}

static char *mx_strchr(const char *s, int c) {
    int count = 0;

    while (s[count]) {
        if (s[count] == c) {
            return (char *) &s[count];
        }
        count++;
    }
    return NULL;
}

