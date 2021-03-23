#include "pathfinder.h"

void mx_struct_struct(t_struct *my_struct, int island_count) {
    my_struct->islands_count = island_count;
    my_struct->islands_now = 0;
    //memory for (char*) ptr
    my_struct->islands = (char**)malloc((island_count + 1) * sizeof(char*));
    my_struct->islands[island_count] = NULL;
    
    my_struct->arr = (int**)malloc(island_count * sizeof(int*));
    for(int i = 0; i < island_count; ++i) {
        my_struct->arr[i] = (int*)calloc(island_count, sizeof(int));
    }
}

void mx_add_islands(char *island1, char *island2, int distance, t_struct *my_struct) {
    int x = -1, y = -1;

    for(int i = 0; i < my_struct->islands_now; ++i) {
        if(!mx_strcmp(my_struct->islands[i], island1)) {
            x = i;
        }
        if(!mx_strcmp(my_struct->islands[i], island2)) {
            y = i;
        }
    }
    if(x != -1 && y != -1) {
        if(my_struct->arr[x][y] != 0) {
            mx_print_error(-6, NULL);
        }
        else {
            my_struct->arr[x][y] = distance;
            my_struct->arr[y][x] = distance;
        }
    }
    else {
        if(x == -1) {
            mx_add_island(island1, my_struct);
            x = my_struct->islands_now;
            my_struct->islands_now += 1;
        }
        if(y == -1) {
            mx_add_island(island2, my_struct);
            y = my_struct->islands_now;
            my_struct->islands_now += 1;
        }
        my_struct->arr[x][y] = distance;
        my_struct->arr[y][x] = distance;
    }
}

void mx_add_island(char *island, t_struct *my_struct) {
    int len = mx_strlen(island);
    
    if(my_struct->islands_now == my_struct->islands_count) {
        mx_print_error(-5, NULL);
    }
    my_struct->islands[my_struct->islands_now] = (char*)malloc(len * sizeof(char));
    mx_strcpy(my_struct->islands[my_struct->islands_now], island);
}

void mx_check_INT_MAX(t_struct *my_struct) {
    int is_count = my_struct->islands_count;
    uint my_struct_dist_sum = 0;

    for(int x = 0; x < is_count; ++x) {
        for(int y = 0; y < is_count; ++y) {
            my_struct_dist_sum += my_struct->arr[x][y];
        }
    }
    if(my_struct_dist_sum > INT_MAX) {
        mx_print_error(-7, NULL);
    }
}




