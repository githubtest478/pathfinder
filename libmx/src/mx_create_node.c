#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *my_struct;
    my_struct = (t_list *)malloc(sizeof(t_list));
    my_struct -> data = data;
    my_struct -> next = NULL;
    return my_struct;
}

