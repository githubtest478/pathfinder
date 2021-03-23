#include "libmx.h"

void mx_del_strarr(char ***arr) {
    int count = 0;

    while(*(*arr + count) != NULL) {
        free(*(*arr + count));
        *(*arr + count) = NULL;
        ++count; 
    }
    free(*(*arr + count));
    *(*arr + count) = NULL;
    free(*arr);
    *arr = NULL;
}
