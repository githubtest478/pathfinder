#include "libmx.h"

char *mx_itoa(int number) {
    int leng = numbers_digits(number);
    char *new_str;
    int stop = -1;
    long int box = number;

    if(box == 0) {
        new_str = mx_strnew(1);
        new_str[0] = '0';
        return new_str;
    }
    if(box < 0) {
        ++leng;
        new_str = mx_strnew(leng);
        new_str[0] = '-';
        stop = 0;
        box *= -1;
    }
    else {
        new_str = mx_strnew(leng);
    }
    --leng;
    while (leng != stop)
    {
        new_str[leng] = box % 10 + 48;
        box /= 10;
        --leng;
    }
    return new_str;
}

int numbers_digits(int num) {
    int counter = 0;

    while (num != 0)
    {
        num /= 10;
        ++counter;
    }
    return counter;
}

