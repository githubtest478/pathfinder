#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    if(pow == 0) {
        return 1;
    }
    double result = n;

    while (--pow > 0)
    {
        result *= n;
    }
    return result;
}
