#include "pathfinder.h"



int main(int argc, char **argv) {
    if(argc != 2) {
        mx_print_error(-1, NULL);
        exit(1);
    }    
    t_struct *my_struct = (t_struct*)malloc(sizeof(t_struct)); 

    mx_first_open(argv[1], my_struct);
    mx_second_open(argv[1], my_struct);
    mx_make_and_calculate_matriks(my_struct);
    //free struct
    mx_free_struct(my_struct);
    free(my_struct);
    //
}
















void mx_free_struct(t_struct *my_struct) {
    mx_del_strarr(&my_struct->islands);
    for(int i = 0; i < my_struct->islands_count; ++i) {
        free(my_struct->arr[i]);
        my_struct->arr[i] = NULL;
    }
    free(my_struct->arr);
    my_struct->arr = NULL;
}

void mx_second_open(char *file_name, t_struct *my_struct) {
    int fd = mx_open_file(file_name);
 
    for(int i = 0; i < my_struct->str_count; ++i) {
        char *str = mx_read_onestr_from_fd(fd);

        if(i == 0) {
            free(str);
            continue;
        }
        mx_valid_check_add_str(str, i + 1, my_struct);
        free(str);
    }
    close(fd);
    mx_check_INT_MAX(my_struct);
}

void mx_valid_check_add_str(char *str, int str_number, t_struct *my_struct) {
    mx_validation_str(str, str_number);
    mx_check_for_duplicate(str, str_number, my_struct);
}


char *mx_read_onestr_from_fd(int fd) {
    char buff[300];
    int i = 0;

    while(read(fd, &buff[i], 1) > 0 && buff[i] != '\n') {
        ++i;   
    }
    char *new_str = mx_strnew(i);

    new_str = mx_strncpy(new_str, buff, i);
    return new_str;
}

void mx_first_open(char *file_name, t_struct *my_struct) {
    int fd = mx_open_file(file_name), i = 0, str_count = 0;
    int island_count = -1;
    char buff[40] = { '\0'}; 
   
    while(read(fd, &buff[i], 1) != 0) {  
        if(buff[i] == '\n') {
            if(str_count == 0) {
                buff[i] = '\0';
                island_count = mx_atoi(buff);
            }
            ++str_count, i = 0;
        }
        ++i;
    }
    close(fd);
    if(buff[0] == '\0') {
        mx_print_error(-3, file_name);
    }
    mx_struct_struct(my_struct, island_count);
    my_struct->str_count = str_count;
}



int mx_atoi(char *str) {
    int i = 0, c = 1, result = 0;
    while(str[i]) {
        ++i;
    }
    --i;
    for(int y = i; y >= 0; --y) {
        if(str[y] >= 48 && str[y] <= 57) {
            result += (str[y] - 48) * c;
            c *= 10;
        }
        else {
            mx_print_error(-4, NULL);
        }
    }
    return result;
}

int mx_open_file(char *str) {
    int fd = open(str, O_RDONLY);

    if(fd == -1) {
        mx_print_error(-2, str);
        exit(1);
    }
    return fd;
}

bool mx_isalpha(int c) {
    if ((c > 64 
        && c < 91)
        || (c > 96 
        && c < 123)) {
        return 1;
    }
    else {
        return 0;
    }  
}

bool mx_isdigit(int c) {
    if(c > 47
       && c < 58 ) {
        return 1;
    }
    else {
        return 0;
    } 
}

