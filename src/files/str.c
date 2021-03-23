#include "pathfinder.h"


void mx_check_for_duplicate(char *str, int str_number, t_struct *my_struct) {
    char island1[50] = { '\0'}, island2[50] = { '\0'};
    int i = 0, y = 0, num = 0;

    while(mx_isalpha(str[i])) {
        island1[i] = str[i];
        ++i;
    }
    ++i;
    while(mx_isalpha(str[i])) {
        island2[y] = str[i];
        ++i, ++y;
    }
    num = mx_atoi(&str[++i]);
    if(!mx_strcmp(island1, island2)) { //проверка на один и тот же остров
        mx_print_error(str_number, NULL);
    }
    mx_add_islands(island1, island2, num, my_struct);
}

void mx_validation_str(char *str, int str_number) {
    if(!mx_isalpha(*str)) {
        mx_print_error(str_number, NULL);
    }
    int i = 0; 

    while(mx_isalpha(str[i])) {
        ++i;
    }
    if(str[i++] != '-') {
        mx_print_error(str_number, NULL);
    }
    if(!mx_isalpha(str[i])) {
        mx_print_error(str_number, NULL);
    }
    while(mx_isalpha(str[i])) {
        ++i;
    }
    if(str[i++] != ',') {
        mx_print_error(str_number, NULL);
    }
    if(!mx_isdigit(str[i])) {
        mx_print_error(str_number, NULL);
    }
    while(mx_isdigit(str[i])) {
        ++i;
    }
    if(str[i] == '\0') {
        return;
    }
    mx_print_error(str_number, NULL);
}
