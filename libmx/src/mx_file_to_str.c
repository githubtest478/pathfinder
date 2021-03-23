#include "libmx.h"

char *mx_file_to_str(const char *file) {
    const int fd = open(file, O_RDONLY);
    int bytes = 0, str_len = 0;
    char buff[1];

    if(fd <= 0) {
        return NULL;
    }
    while((bytes = read(fd, buff, 1)) > 0) {
        ++str_len;
    }
    if(bytes == -1 || str_len == 0) {
        return NULL;
    }
    close(fd);
    char *new_str = mx_strnew(str_len);
    const int fd1 = open(file, O_RDONLY);
    bytes = 0, str_len = 0;

    if(fd1 == -1) {
        return NULL;
    }
    while((bytes = read(fd1, buff, 1)) > 0) {
        new_str[str_len] = buff[0];
        ++str_len;
    }
    if(bytes == -1) {
        return NULL;
    }
    close(fd1);
    return new_str;
}

