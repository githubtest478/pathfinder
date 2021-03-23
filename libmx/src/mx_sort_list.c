#include "libmx.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    if(list == NULL) {
        return list;
    }
    t_list *first = list;
    t_list *second = list -> next;
    bool is_true = false;

    while (second != NULL) {
        is_true =  cmp(first -> data, second -> data);
        if(is_true) {
            void *temporary = first -> data;
            
            first -> data = second -> data;
            second -> data = temporary; 
            first = list;
            second = list -> next;
            is_true = false;
        }
        else
        {
            first = first -> next;
            second = second -> next;
        }        
    }
    return list;
}
