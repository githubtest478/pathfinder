#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int i = 0;
    int pow = 0;

    while (hex[i])
    {
        ++i;
    }
    i--;

    while(i >= 0) {
        if (hex[i] >= 48 && hex[i] <= 57)
        {
            int num = hex[i] - '0';
            result += num * mx_pow_for_hex_to_nbr(16 ,pow);
            --i;
            ++pow;
            continue;
        }
        char a = hex[i];

        if(hex[i] >= 97 && hex[i] <= 102) {
            a = hex[i] - 32; 
        }
        a -= '7';

        int num = a;

        result += num * mx_pow_for_hex_to_nbr(16 ,pow);
        --i;
        ++pow;
    }
    return (unsigned long)result;
}

unsigned long mx_pow_for_hex_to_nbr(int n, unsigned int pow) {
    if(pow == 0) {
        return 1;
    }
    unsigned long result = n;

    while (--pow > 0)
    {
        result *= n;
    }
    return result;
}

