#include "libmx.h"

char *mx_strnew(const int size) {
    if (size < 0)
    {
        return NULL;
    }
    char *ptr_char = (char*) malloc(size + 1);
    
    if(ptr_char == NULL) {
        return NULL;
    }
    for (int i = 0; i < size + 1; i++)
    {
        ptr_char[i] = '\0';
    }
    return ptr_char;
}

