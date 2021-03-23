#include "libmx.h"

void mx_swap_int(int *s1, int *s2);

int mx_quicksort(int *arr, int left, int right) {
    if (!arr)
        return -1;
    if (left >= right)
        return 0;

    int pivot = right;
    int swap = 0;
    int i = left;  
    int j = right - 1;

    while(i != j){
      while(arr[i] <= arr[pivot] && i != j) {
        i++;
      }
      while(arr[j] > arr[pivot] && i != j) {
        j--;
      }
      if(i != j) {
          ++swap;
          mx_swap_int(&arr[i], &arr[j]);
      }
    }
    if(swap == 0 && i == j && i == right - 1) {
        swap += mx_quicksort(arr, left, i);
    }
    if(i == j) {
        if(pivot != j && arr[j] > arr[pivot]  ) {
          ++swap;
          mx_swap_int(&arr[j], &arr[pivot]);
        }
        swap += mx_quicksort(arr, left, i - 1);
        swap += mx_quicksort(arr, i + 1, right);
    }
    return swap;
}

void mx_swap_int(int *s1, int *s2) {
    int one = *s1;
    
    *s1 = *s2;
    *s2 = one; 
}  
