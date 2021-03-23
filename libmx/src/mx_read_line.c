#include "libmx.h"

static char *for_test1_copy(char *old_str, char *buf, int index);

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if(fd < 0) {
        return -2;
    }
    int i = 0;
    char buf[buf_size / buf_size], buf_big[10000] = { '\0' };

    while(read(fd, buf, 1) > 0) {
        if(buf[0] == delim) {
            break;
        }
        if(i == 9999) {
            *lineptr = for_test1_copy(*lineptr, buf_big, i);
            i = 0;
            continue;
        }
        buf_big[i] = buf[0];
        i++;
    }
    if(buf_big[0] == '\0') {
        return -1;
    }
    *lineptr = for_test1_copy(*lineptr, buf_big, i);
    return mx_strlen(*lineptr);
}

static char *for_test1_copy(char *old_str, char *buf, int index) {
    char *new_str = mx_strnew(mx_strlen(old_str) + index);
    int i = 0;

    while(i < mx_strlen(old_str)) {
        new_str[i] = old_str[i];
        ++i;
    }
    for(int j = 0; j < index; ++j) {
        new_str[i] = buf[j];
        ++i;
    }
    free(old_str);
    old_str = NULL;
    return new_str;
}
