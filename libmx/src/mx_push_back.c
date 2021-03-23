#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if(list == NULL) {
        return;
    }

    t_list *new_node = mx_create_node(data);  

    if(*list == NULL) {
        *list = new_node;
        return;
    } 
    else {
        t_list *p_list = *list;
        while(p_list -> next != NULL) {
            p_list = p_list -> next;
        }
        p_list -> next = new_node;
    }
}
