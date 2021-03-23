#include "pathfinder.h"

void mx_print(int *dist, int src, t_struct *my_struct, int V) {    
    for(int i = src + 1; i < V; ++i) {
        t_print *print = (t_print*)malloc(sizeof(t_print));

        print->position = 0;
        mx_add_to_t_print(print, i);
        mx_find_path_recursively(dist, i, dist[i], my_struct, print);
        free(print);
    }
}

void mx_find_path_recursively(int *dist, int point, int price, t_struct *my_struct, t_print *print) {
    if(price == 0) {
        mx_print_final(dist, my_struct, print);
        return;
    }
    for(int i = 0; i < my_struct->islands_count; ++i) {
        int position_now = print->position;
        if(price - my_struct->arr[point][i] == dist[i] && my_struct->arr[point][i] != 0) {
            mx_add_to_t_print(print, i);
            mx_find_path_recursively(dist, i, dist[i], my_struct, print);
            print->position = position_now;
        }
    }
}

void mx_print_final(int *dist, t_struct *my_struct, t_print *print) {
    mx_printstr(PRINT1);

    mx_printstr("Path: ");
    mx_printstr(my_struct->islands[print->arr[print->position - 1]]);
    mx_printstr(" -> ");
    mx_printstr(my_struct->islands[print->arr[0]]);
    mx_printchar('\n');

    mx_printstr("Route: ");
    for(int i = print->position - 1; i >= 0; --i) {
        mx_printstr(my_struct->islands[print->arr[i]]);
        if(i - 1 != -1) {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');

    mx_printstr("Distance: ");
    if(print->position == 2) {
        char *num = mx_itoa(dist[print->arr[0]]);
        mx_printstr(num);
        free(num);
        num = NULL;
        mx_printchar('\n');
    }
    else {
        for(int i = print->position - 2; i >= 0; --i) {
            char *num = mx_itoa(dist[print->arr[i]] - dist[print->arr[i + 1]]);
            mx_printstr(num);
            free(num);
            num = NULL;
            if(i - 1 != -1) {
                mx_printstr(" + ");
            }
        }
        mx_printstr(" = ");
        char *num = mx_itoa(dist[print->arr[0]]);
        mx_printstr(num);
        free(num);
        num = NULL;
        mx_printchar('\n');
    }
    mx_printstr(PRINT1);
}




void mx_add_to_t_print(t_print *print, int node_num) {
    print->arr[print->position] = node_num;
    print->position += 1;
}



