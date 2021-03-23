#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if(arr == NULL || delim == NULL) {
        return;
    }
    int count = 0;

    while(arr[count] != NULL) {
        if(count != 0) {
            mx_printstr(delim);
        }
        mx_printstr(arr[count]);
        ++count;
    }
    mx_printstr("\n");
}
