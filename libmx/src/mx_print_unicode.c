#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    if(c < 128) {
        write(1, &c, 1);
    }
    else if(c < 2048) {
        unsigned char unicode[2] = { c >> 6 | 192, (c & 63) | 128};

        write(1, unicode, 2);
    }
    else if(c < 65536) {
        unsigned char unicode[3] = { ((c >> 12) & 63) | 224, ((c >> 6) & 63) | 128, (c & 63) | 128};
        
        write(1, unicode, 3);
    }
    else {
        unsigned char unicode[4] = {((c >> 18) & 63) | 240 , ((c >> 12) & 63) | 128, ((c >> 6) & 63) | 128, (c & 63) | 128};

        write(1, unicode, 4);
    }
}

