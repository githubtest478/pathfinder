#include "pathfinder.h"

void mx_print_error(int err_num, char *file_name) {
    if(err_num > 0) {
        char s[2] = { err_num + 48, '\0'};
        mx_print_error_str(ERROR_LINE1);
        mx_print_error_str(s);
        mx_print_error_str(ERROR_LINE2);
        exit(1);
    }
    switch (err_num) {
        case -1:
            mx_print_error_str(ERROR_INVALID_ARGC);
            exit(1);
            break;
        
        case -2:
            mx_print_error_str(ERROR_FILE_NOT_EXIST1);
            mx_print_error_str(file_name);
            mx_print_error_str(ERROR_FILE_NOT_EXIST2);
            exit(1);
            break;

        case -3:
            mx_print_error_str(ERROR_FILE_EMPTY1);
            mx_print_error_str(file_name);
            mx_print_error_str(ERROR_FILE_EMPTY2);
            exit(1);
            break;

        case -4:
            mx_print_error_str(ERROR_SECOND);
            exit(1);
            break;  

        case -5:
            mx_print_error_str(ERROR_IS_COUNT);
            exit(1);
            break;  

        case -6:
            mx_print_error_str(ERROR_DUPLICATE);
            exit(1);
            break;

        case -7:
            mx_print_error_str(ERROR_INT);
            exit(1);
            break;    

        default:
            break;
    }

}

void mx_print_error_str(const char *s) {
    write(2, s, mx_strlen(s));
}



