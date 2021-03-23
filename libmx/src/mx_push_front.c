#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    if(list == NULL) {
        return;
    }
    
    t_list *my_list = mx_create_node(data); 
    my_list -> next = *list;    
    *list = my_list;
}
