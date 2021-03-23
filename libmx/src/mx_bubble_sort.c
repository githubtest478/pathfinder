#include "libmx.h"

int mx_bubble_sort(int *arr, int size) {
    int count = 0;

    for(int y = 0; y < size; ++y) {
        for (int i = 0; i < size - y - 1; i++)
        {
            if(arr[i] > arr[i + 1]) {
                int a = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = a;
                ++count;
            }
        }
    }
    return count;
}
