#include "libmx.h"


//int mx_strcmp(const char *s1, const char *s2);


int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) { 
        int mid;

        if(left + right == 1) {
            mid = 1;
        } 
        else {
            mid = (left + right) / 2;
        }
        int search = mx_strcmp(arr[mid], s);
        
        if(search == 0) {
            (*count)++;
            return mid;            
        }
        if (search > 0) {
            right = mid - 1;  
            (*count)++;
        }
        else {
            left = mid + 1;            
            (*count)++;
        }
    }
    *count = 0;
    return -1;
}

