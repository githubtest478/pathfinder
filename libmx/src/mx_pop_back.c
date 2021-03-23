#include "libmx.h"

void mx_pop_back(t_list **list) {
    if(list == NULL || *list == NULL) {
        return;
    }
    if((*list) -> next == NULL) {
        free(*list);
        *list = NULL;
    }
    else {
        t_list *pre_last;
        t_list *p_list = *list;

        while(p_list -> next != NULL) {
            pre_last = p_list;
            p_list = p_list -> next;
        }
        pre_last -> next = NULL;
        free(p_list);
        p_list = NULL;
    }
}

