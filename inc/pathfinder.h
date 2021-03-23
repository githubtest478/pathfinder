#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>
#ifdef __linux__
    #include <malloc.h>
    #define malloc_size malloc_usable_size
#else
    #include <malloc/malloc.h>
#endif
#include "libmx.h"

#define ERROR_INVALID_ARGC "usage: ./pathfinder [filename]\n"  //-1

#define ERROR_FILE_NOT_EXIST1 "error: file " 
#define ERROR_FILE_NOT_EXIST2 " does not exist\n" //-2

#define ERROR_FILE_EMPTY1 "error: file " 
#define ERROR_FILE_EMPTY2 " is empty\n"  //-3

#define ERROR_SECOND "error: line 1 is not valid\n" //-4

#define ERROR_LINE1 "error: line "
#define ERROR_LINE2 " is not valid\n" // any positive int

#define ERROR_IS_COUNT "error: invalid number of islands\n"    //-5
#define ERROR_DUPLICATE "error: duplicate bridges\n"           //-6
#define ERROR_INT "error: sum of bridges lengths is too big\n" //-7

#define PRINT1 "========================================\n"

typedef unsigned int uint;

typedef struct s_struct {
    char **islands;
    int **arr;
    
    int islands_count;
    int islands_now;
    int str_count;

}              t_struct;

typedef struct s_print {
    int arr[20];
    int position;
}              t_print;



//----path
bool mx_isalpha(int c);
int mx_atoi(char *str);
bool mx_isdigit(int c);
int mx_open_file(char *str);
char *mx_read_onestr_from_fd(int fd);
void mx_first_open(char *file_name, t_struct *my_struct);
void mx_second_open(char *file_name, t_struct *my_struct);
void mx_free_struct(t_struct *my_struct);

    //STR_V_C_A
void mx_valid_check_add_str(char *str, int str_number, t_struct *my_struct);
void mx_validation_str(char *str, int str_number);
void mx_check_for_duplicate(char *str, int str_number, t_struct *my_struct);

  ///struct
void mx_struct_struct(t_struct *my_struct, int island_count);
void mx_add_islands(char *island1, char *islaland2, int distance, t_struct *my_struct);
void mx_add_island(char *island, t_struct *my_struct);
void mx_check_INT_MAX(t_struct *my_struct);

  ///ERROR
void mx_print_error(int err_num, char *file_name);
void mx_print_error_str(const char *s);


  ///MATH
void mx_make_and_calculate_matriks(t_struct *my_struct);
void mx_make_and_calculate(t_struct *my_struct, int start_index);
void mx_math_test(int src, int V, t_struct *my_struct);
int mx_min_distance(int *dist, bool *sptSet, int V);

  ///PRINT
void mx_print(int *dist, int src, t_struct *my_struct, int V);
void mx_add_to_t_print(t_print *print, int node_num);
void mx_print_final(int *dist, t_struct *my_struct, t_print *print);
void mx_find_path_recursively(int *dist, int point, int price, t_struct *my_struct, t_print *print);






//libmx
// int mx_strlen(const char *s);
// char *mx_strnew(const int size);
// void mx_printstr(const char *s);
// char *mx_strncpy(char *dst, const char *src, int len);
// void mx_printchar(char c);
// int mx_strcmp(const char *s1, const char *s2);
// char *mx_strcpy(char *dst, const char *src);
// void mx_del_strarr(char ***arr);
// char *mx_itoa(int number);
// int numbers_digits(int num);

#endif
