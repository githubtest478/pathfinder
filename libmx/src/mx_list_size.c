#include "libmx.h"

int mx_list_size(t_list *list) {
    if(list == NULL) {
        return 0;
    }
    int count = 0;
    
    t_list *check_list = list;
    
    while(check_list -> next != NULL) {
        check_list = check_list -> next;
        count++;
    }
    count++;
    
    return count;
}
