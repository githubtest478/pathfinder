#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if(nbr == 0) {
        char *string = mx_strnew(1);
        string[0] = 48;
        return string;
    }
    int leng = find_length_arr_for_nbr(nbr);
    char *string = mx_strnew(leng);
    
    while (nbr != 0)
    {
        if(nbr % 16 <= 9) {
            string[leng - 1] = nbr % 16 + 48;
        }
        else {
            string[leng - 1] = nbr % 16 + 87;
        }
        nbr /= 16;
        --leng;
    }
    return string;
}

int find_length_arr_for_nbr(unsigned long nbr_copy) {
    int count = 1;

    while (nbr_copy >= 16) {
        ++count;
        nbr_copy /= 16;
    }
    return count;
}

