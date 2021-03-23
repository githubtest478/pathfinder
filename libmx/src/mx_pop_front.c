#include "libmx.h"

void mx_pop_front(t_list **list) {
    if(list == NULL) {
        return;
    }
    if(*list == NULL) {
        return;
    }
    t_list *first = *list;
 
    *list = (*list) -> next;

    free(first);
    first = NULL;
}

