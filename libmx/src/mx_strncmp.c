#include "libmx.h"

int mx_strncmp (const char *s1, const char *s2, int n) {
    int count = 0;

    while (s1[count] 
           && count < n) {
        if (s1[count] == s2[count]) {
            count++;
        }
        else {
            if (s1[count] > s2[count]) {
                return s1[count] - s2[count];
            }
            else {
                return s1[count] - s2[count];
            }
            break;
        }
    }
    return 0;
}

